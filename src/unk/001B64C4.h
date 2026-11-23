// unk/001B64C4.h: Item menu sub-screen state layout recovered from
// unk/001B64C4.cpp accesses.
#ifndef UNK_001B64C4_H
#define UNK_001B64C4_H

#include "target.h"
#include "mnu/mnucommon.h"
#include "bed/bedpad.h"

struct C64Item {
    int words[4];
}; // size 0x10

struct MnuItemView {
    int m_unk00;                        // +0x0000
    int m_unk04;                        // +0x0004
    int m_curSlot;                      // +0x0008
    int m_pad0C[2];                     // +0x000C..+0x0013
    int m_choice0;                      // +0x0014
    int m_pad18[2];                     // +0x0018..+0x001F
    int m_selRes;                       // +0x0020
    int m_unk24;                        // +0x0024
    int m_choice1;                      // +0x0028
    unsigned char m_pad2C[0x2C];        // +0x002C..+0x0057
    int m_state;                        // +0x0058
    unsigned int m_subState;            // +0x005C
    int m_prevState[14];                // +0x0060..+0x0097
    MnuRpk m_rpk0;                      // +0x0098..+0x0983
    MnuRpk m_rpk1;                      // +0x0984..+0x126F
    MnuRpk m_rpk2;                      // +0x1270..+0x1B5B
    int m_unk1B5C;                      // +0x1B5C
    int m_unk1B60;                      // +0x1B60
    MnuSub104 m_select;                 // +0x1B64..+0x1C67
    unsigned char m_pad1C68[0x778];     // +0x1C68..+0x23DF
    int m_unk23E0;                      // +0x23E0
    int m_pad23E4[13];                  // +0x23E4..+0x2417
    int m_unk2418;                      // +0x2418
    int m_pad241C[4];                   // +0x241C..+0x242B
    int m_item13;                       // +0x242C
    int m_item12;                       // +0x2430
    C64Item *m_slotPtrs[14];            // +0x2434..+0x246B
    int m_unk246C;                      // +0x246C
    int m_unk2470;                      // +0x2470
    int m_pad2474[6];                   // +0x2474..+0x248B
    int m_unk248C;                      // +0x248C
    int m_pad2490[5];                   // +0x2490..+0x24A3
    unsigned char m_selLines[0x200];    // +0x24A4..+0x26A3
    int m_selItems[23];                 // +0x26A4..+0x26FF
    unsigned int m_texHandle;           // +0x2700
    int m_fadeTimer;                    // +0x2704
}; // size 0x2708

STATIC_ASSERT(sizeof(MnuItemView) == 0x2708, MnuItemView_size);

#endif // UNK_001B64C4_H
