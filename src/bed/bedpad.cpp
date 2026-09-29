// bed/bedpad.cpp: controller ports (BedPad).
//
// Matching decompilation of all four functions. Still partial: .bss is in
// asm because its last 4 bytes (0x308480) are used by no code, so nothing
// says which file owns them; while the file is partial the __FILE__ string
// stays an INCLUDE_RODATA (ASSERT_FILE) too. The ASSERTs must stay on lines
// 86, 88 and 133 (0x56, 0x58, 0x85). Method names are ours.

#define ASSERT_FILE D_002E56C8
#include "bed/bedpad.h"
#include "include_asm.h"
#include "sdk/libpad2.h"
#include "sdk/libvib.h"

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
