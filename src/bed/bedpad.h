// bed/bedpad.h: one controller port (scePad2 socket).
//
// Class name from the MagLife*::pad(MagLifePC &, const BedPad &) overrides;
// m_socket and thePortNo from the assert strings. Every other name is ours,
// from what the methods in bed/bedpad.cpp do with each field. MagSystem
// keeps two, at +0x40.
#ifndef BED_BEDPAD_H
#define BED_BEDPAD_H

#include "ror.h"

// Buttons, by bit number, as scePad2Read reports them (inverted: 1 =
// pressed). The code tests them as (m_press >> BEDPAD_BIT_UP) & 1: a mask
// test compiles differently.
enum {
    BEDPAD_BIT_SELECT,
    BEDPAD_BIT_L3,
    BEDPAD_BIT_R3,
    BEDPAD_BIT_START,
    BEDPAD_BIT_UP,
    BEDPAD_BIT_RIGHT,
    BEDPAD_BIT_DOWN,
    BEDPAD_BIT_LEFT,
    BEDPAD_BIT_L2,
    BEDPAD_BIT_R2,
    BEDPAD_BIT_L1,
    BEDPAD_BIT_R1,
    BEDPAD_BIT_TRIANGLE,
    BEDPAD_BIT_CIRCLE,
    BEDPAD_BIT_CROSS,
    BEDPAD_BIT_SQUARE
};

// The same buttons as masks (m_dpad uses them for the d-pad directions).
enum {
    BEDPAD_UP = 1 << BEDPAD_BIT_UP,
    BEDPAD_RIGHT = 1 << BEDPAD_BIT_RIGHT,
    BEDPAD_DOWN = 1 << BEDPAD_BIT_DOWN,
    BEDPAD_LEFT = 1 << BEDPAD_BIT_LEFT
};

// m_dir: where the left stick (or d-pad) points, once past half way.
enum {
    BEDPAD_DIR_DOWN = 1,
    BEDPAD_DIR_UP = 2,
    BEDPAD_DIR_RIGHT = 4,
    BEDPAD_DIR_LEFT = 8
};

class BedPad {
public:
    // What scePad2Read writes.
    unsigned short m_rawButton;     // +0x00: 0 = pressed
    unsigned char m_rawStick[4];    // +0x02: right x, right y, left x, left y
    unsigned char m_unk06[0x1A];    // +0x06
    int m_socket;                   // +0x20
    int m_portNo;                   // +0x24
    unsigned short m_old;           // +0x28: m_press of the previous read
    short m_unk2A;                  // +0x2A
    int m_hold;                     // +0x2C: reads with a button held
    int m_frame;                    // +0x30: successful reads
    int m_repeatDelay;              // +0x34: auto-repeat starts after this many reads
    int m_repeatInterval;           // +0x38: and then every this many
    int m_unk3C;                    // +0x3C
    float m_lastX;                  // +0x40: m_x, m_y, m_mag when the stick
    float m_lastY;                  // +0x44  last moved (see update)
    float m_lastMag;                // +0x48
    float m_x;                      // +0x4C: left stick or d-pad, -1..1
    float m_y;                      // +0x50: down is positive
    float m_mag;                    // +0x54: length of (m_x, m_y)
    float m_change;                 // +0x58: calcChange()
    int m_dirFrame;                 // +0x5C: m_frame when m_dir last changed
    int m_dir;                      // +0x60: BEDPAD_DIR_*
    int m_dirCount;                 // +0x64: quick changes of m_dir in a row
    int m_dpad;                     // +0x68: BEDPAD_UP.. from the d-pad or the stick
    int m_dpadTrigger;              // +0x6C: m_dpad bits new in this read
    int m_dpadRepeat;               // +0x70: m_dpadTrigger plus auto-repeat
    int m_dpadHold;                 // +0x74: reads with m_dpad held
    unsigned short m_press;         // +0x78: buttons down
    unsigned short m_trigger;       // +0x7A: buttons new in this read
    unsigned short m_repeat;        // +0x7C: m_trigger plus auto-repeat
    unsigned char m_stick[4];       // +0x7E: m_rawStick of the last read
    unsigned char m_unk82[0xE];     // +0x82

    // MagSystem's pads (its constructor builds them inline).
    BedPad()
    {
        m_portNo = -1;
        m_socket = -1;
        m_repeatInterval = 0;
        m_repeatDelay = 0;
        m_frame = 0;
    }
    // MagSystem::setPlayer (the name is ours).
    void clearLast() { m_lastY = m_lastX = m_lastMag = 0.0f; }
    ~BedPad();
    void vibrate(int small, int big);
    void open(int thePortNo);
    int close();
    int update();
    float getRightX() const;
    float getRightY() const;
    float getLeftX() const;
    float getLeftY() const;
    float getStick(float *x, float *y) const;
    float getChange() const;
    float calcChange() const;
    void updateStick();
};

#endif
