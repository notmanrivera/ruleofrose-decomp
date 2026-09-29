// bed/bedpad.cpp: controller ports (BedPad): scePad2 socket, per-frame
// read (buttons, auto-repeat, sticks), vibration. Every function matches.
// Still partial: .bss is in asm because its last 4 bytes (0x308480) are
// used by no code, so nothing says which file owns them; while the file is
// partial the __FILE__ string stays an INCLUDE_RODATA (ASSERT_FILE) too.
// The ASSERTs must stay on lines 86, 88 and 133 (0x56, 0x58, 0x85). Method
// names are ours.

#define ASSERT_FILE D_002E56C8
#include "bed/bedpad.h"
#include "include_asm.h"
#include "sdk/libpad2.h"
#include "sdk/libvib.h"
#include "sdk/math.h"

extern const char D_002E56C8[];

// scePad2 DMA buffers, one per port; 64-byte aligned (see the assert).
extern unsigned char D_00308280[2][0x100];
#define zDmaBuf D_00308280

// 0x00101AEC
BedPad::~BedPad()
{
    if (m_portNo >= 0) {
        close();
        m_portNo = -1;
    }
}

// 0x00101B50: small motor on/off (bit 0) and big motor level (bits 1-8);
// a negative argument leaves that motor out.
void BedPad::vibrate(int small, int big)
{
    int profile;
    int data;
    int size = 1;
    if (small >= 0) {
        profile = 1;
        data = small & 1;
        if (big >= 0) {
            profile = 3;
            data |= (big & 0xFF) << 1;
            size = 2;
        }
    } else if (big >= 0) {
        profile = 2;
        data = big & 0xFF;
    }
    sceVibSetActParam(m_socket, 1, (unsigned char *)&profile, size, (unsigned char *)&data);
}

INCLUDE_RODATA("asm/nonmatchings/bed/bedpad", D_002E56C8);





























// 0x00101BCC
void BedPad::open(int thePortNo)
{
    ASSERT(thePortNo >= 0 && thePortNo < 2);

    ASSERT((((int)zDmaBuf)&0x3F) == 0);
    m_portNo = thePortNo;
    scePad2SocketParam param;
    param.option = 2;
    param.port = thePortNo != 0;
    param.slot = 0;
    param.number = 0;
    param.name[0] = 0;
    m_socket = scePad2CreateSocket(&param, zDmaBuf[thePortNo]);
}
































// 0x00101C7C
int BedPad::close()
{
    ASSERT(m_socket>=0);
    int socket = m_socket;
    m_socket = -1;
    return scePad2DeleteSocket(socket);
}

// 0x00101CCC: read the pad once per frame. Returns 0, with everything
// neutral, while the pad is missing or not ready.
int BedPad::update()
{
    if (m_socket < 0 || scePad2GetState(m_socket) != 1) {
        m_old = m_press = m_trigger = 0;
        m_stick[0] = m_stick[1] = m_stick[2] = m_stick[3] = 0x80;
        m_mag = m_change = m_x = m_y = 0.0f;
        return 0;
    }
    scePad2Read(m_socket, this);
    m_old = m_press;
    m_press = ~m_rawButton;
    m_trigger = m_press & ~m_old;
    m_stick[0] = m_rawStick[0];
    m_stick[1] = m_rawStick[1];
    m_stick[2] = m_rawStick[2];
    m_stick[3] = m_rawStick[3];
    m_frame++;
    m_repeat = 0;
    if (m_press == 0) {
        m_hold = 0;
    } else {
        m_hold++;
        if (m_trigger == 0 && m_repeatDelay != 0 && m_repeatInterval != 0) {
            if (m_hold >= m_repeatDelay && (m_hold - m_repeatDelay) % m_repeatInterval == 0) {
                m_repeat = m_press | m_trigger;
            }
        } else if (m_trigger != 0) {
            m_repeat |= m_trigger;
        }
    }
    updateStick();
    m_change = calcChange();
    if (m_change >= 0.001f) {
        m_lastX = m_x;
        m_lastY = m_y;
        m_lastMag = m_mag;
    }
    return 1;
}

// The stick getters: byte 0..255 (centre 0x80) as -1..1, 0 inside the
// dead zone. Each is written out: a shared helper, even inline, reads the
// byte once and does not match.

// 0x00101E64
float BedPad::getRightX() const
{
    if (m_stick[0] < 0x60) {
        return (m_stick[0] - 96.0f) / 96.0f;
    }
    if (m_stick[0] > 0xA0) {
        return (m_stick[0] - 160.0f) / 95.0f;
    }
    return 0.0f;
}

// 0x00101EEC
float BedPad::getRightY() const
{
    if (m_stick[1] < 0x60) {
        return (m_stick[1] - 96.0f) / 96.0f;
    }
    if (m_stick[1] > 0xA0) {
        return (m_stick[1] - 160.0f) / 95.0f;
    }
    return 0.0f;
}

// 0x00101F74
float BedPad::getLeftX() const
{
    if (m_stick[2] < 0x60) {
        return (m_stick[2] - 96.0f) / 96.0f;
    }
    if (m_stick[2] > 0xA0) {
        return (m_stick[2] - 160.0f) / 95.0f;
    }
    return 0.0f;
}

// 0x00101FFC
float BedPad::getLeftY() const
{
    if (m_stick[3] < 0x60) {
        return (m_stick[3] - 96.0f) / 96.0f;
    }
    if (m_stick[3] > 0xA0) {
        return (m_stick[3] - 160.0f) / 95.0f;
    }
    return 0.0f;
}

// 0x00102084
float BedPad::getStick(float *x, float *y) const
{
    *x = m_x;
    *y = m_y;
    return m_mag;
}

// 0x0010209C
float BedPad::getChange() const
{
    return m_change;
}

// 0x001020A4: how much the stick moved since m_last*: the change of
// direction (0 same, 1 opposite) plus 0.1 per 0.001 of length.
float BedPad::calcChange() const
{
    float x, y;
    if (m_mag == 0.0f) {
        x = 0.0f;
        y = 0.0f;
        if (m_lastMag == 0.0f) {
            return 0.0f;
        }
    } else {
        x = m_x / m_mag;
        y = m_y / m_mag;
    }
    float lastX, lastY;
    if (m_lastMag == 0.0f) {
        lastX = 0.0f;
        lastY = 0.0f;
    } else {
        lastX = m_lastX / m_lastMag;
        lastY = m_lastY / m_lastMag;
    }
    float dot = lastX * x + lastY * y;
    float d = m_mag - m_lastMag;
    if (d < 0.0f) {
        d = -d;
    }
    d = d * 100.0f * 0.001f;
    return (1.0f - dot) * 0.5f + d;
}

// 0x00102188: the left stick (or the d-pad, which wins) as m_x/m_y, as
// d-pad bits with auto-repeat, and as m_dir.
void BedPad::updateStick()
{
    int dpad = 0;
    if ((m_press >> BEDPAD_BIT_UP) & 1) {
        m_y = -1.0f;
        dpad = BEDPAD_UP;
    } else if ((m_press >> BEDPAD_BIT_DOWN) & 1) {
        m_y = 1.0f;
        dpad = BEDPAD_DOWN;
    } else {
        m_y = getLeftY();
        if (m_y < -0.7f) {
            dpad = BEDPAD_UP;
        } else if (m_y > 0.7f) {
            dpad = BEDPAD_DOWN;
        }
    }
    if ((m_press >> BEDPAD_BIT_LEFT) & 1) {
        m_x = -1.0f;
        dpad |= BEDPAD_LEFT;
    } else if ((m_press >> BEDPAD_BIT_RIGHT) & 1) {
        m_x = 1.0f;
        dpad |= BEDPAD_RIGHT;
    } else {
        m_x = getLeftX();
        if (m_x < -0.7f) {
            dpad |= BEDPAD_LEFT;
        } else if (m_x > 0.7f) {
            dpad |= BEDPAD_RIGHT;
        }
    }
    m_dpadRepeat = 0;
    m_dpadTrigger = ~m_dpad & dpad;
    m_dpad = dpad;
    if (dpad == 0) {
        m_dpadHold = 0;
    } else {
        m_dpadHold++;
        if (m_dpadTrigger == 0 && m_repeatDelay != 0 && m_repeatInterval != 0) {
            if (m_dpadHold >= m_repeatDelay && (m_dpadHold - m_repeatDelay) % m_repeatInterval == 0) {
                m_dpadRepeat = dpad;
            }
        } else if (m_dpadTrigger != 0) {
            m_dpadRepeat |= m_dpadTrigger;
        }
    }
    m_mag = sqrtf(m_x * m_x + m_y * m_y);
    int dir = 0;
    if (!(m_mag < 0.5f)) {
        if (m_y > 0.1f) {
            dir = BEDPAD_DIR_DOWN;
        } else if (m_y < -0.1f) {
            dir = BEDPAD_DIR_UP;
        }
        if (m_x > 0.1f) {
            dir |= BEDPAD_DIR_RIGHT;
        } else if (m_x < -0.1f) {
            dir |= BEDPAD_DIR_LEFT;
        }
    }
    if (dir == m_dir && m_frame - m_dirFrame >= 16) {
        m_dirCount = 0;
    }
    int last = m_dirFrame;
    if (m_dir != dir) {
        m_dir = dir;
        m_dirFrame = m_frame;
        if (m_frame - last < 15) {
            m_dirCount++;
        } else {
            m_dirCount = 0;
        }
    }
}
