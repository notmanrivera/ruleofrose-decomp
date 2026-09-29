// bed/bedpad.h: one controller port (scePad2 socket).
//
// Class name from the MagLife*::pad(MagLifePC &, const BedPad &) overrides;
// member names from the assert strings (m_socket>=0, thePortNo); the rest
// of the 0x90 bytes (MagSystem keeps two, at +0x40) is still unknown.
#ifndef BED_BEDPAD_H
#define BED_BEDPAD_H

#include "ror.h"

class BedPad {
public:
    unsigned char m_unk00[0x20];    // +0x00
    int m_socket;                   // +0x20
    int m_portNo;                   // +0x24
    unsigned char m_unk28[0x68];    // +0x28

    ~BedPad();
    void vibrate(int small, int big);
    void open(int thePortNo);
    int close();
};

#endif
