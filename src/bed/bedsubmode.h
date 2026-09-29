// bed/bedsubmode.h: a small stack of 16-byte "sub mode" states.
//
// Layout from bed/bedsubmode.cpp and its callers in mag/: the current
// state at +0x00, MAX_STACK saved states at +0x10, depth at +0x50.
// Class name from MagLifeBwnCtrlModeSitOut::setNextSubMode(const BedSubMode &);
// member names from the assert strings; method names are ours.
#ifndef BED_BEDSUBMODE_H
#define BED_BEDSUBMODE_H

#include "ror.h"

class BedSubMode {
public:
    enum { MAX_STACK = 4 };

    u_long128 m_cur;                 // +0x00
    u_long128 m_stack[MAX_STACK];    // +0x10
    int m_depth;                     // +0x50

    void push();
    void pop();
    void clear();
};

#endif
