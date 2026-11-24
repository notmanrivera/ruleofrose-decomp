#ifndef UNK_NORMAIN_H
#define UNK_NORMAIN_H

#include "emy/emy.h"

struct NorMain : public EmyMain {
    unsigned char m_pad204[0x14];       // +0x204..+0x217
    int m_unk218;                       // +0x218
    unsigned char m_pad21C[0x10];       // +0x21C..+0x22B
    unsigned char m_unk22C;             // +0x22C
    unsigned char m_pad22D[3];          // +0x22D..+0x22F
    int m_unk230;                       // +0x230
    unsigned short m_unk234;            // +0x234
    unsigned short m_unk236;            // +0x236
    unsigned char m_pad238[4];          // +0x238..+0x23B
    int m_unk23C;                       // +0x23C
    int m_unk240;                       // +0x240
    int m_unk244;                       // +0x244
    int m_unk248;                       // +0x248
    int m_unk24C;                       // +0x24C
    int m_unk250;                       // +0x250
    int m_unk254;                       // +0x254
};
STATIC_ASSERT(sizeof(NorMain) == 0x258, NorMain_size);

#endif // UNK_NORMAIN_H
