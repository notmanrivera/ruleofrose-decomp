// unk/00166AD0.h: EmyOut / EmyMain view structures for unk/00166AD0.cpp.
#ifndef UNK_00166AD0_H
#define UNK_00166AD0_H

#include "target.h"
#include "game/gamtrg.h"
#include "game/gamman.h"

struct EmyMainView {
    int m_id;                           // +0x000
    unsigned short m_unk04;             // +0x004
    unsigned char m_unk06;              // +0x006
    unsigned char m_unk07;              // +0x007
    int m_unk08;                        // +0x008
    int m_unk0C;                        // +0x00C
    int m_unk10;                        // +0x010
    int m_pad14[5];                     // +0x014..+0x027
    int m_unk28;                        // +0x028
    int m_unk2C;                        // +0x02C
    unsigned char m_pad30[0xBC];        // +0x030..+0x0EB
    int m_mot[15];                      // +0x0EC..+0x127
    unsigned char m_pad128[0x9C];       // +0x128..+0x1C3
    float m_motSpeed;                   // +0x1C4
    int m_unk1C8;                       // +0x1C8
    int m_unk1CC;                       // +0x1CC
    int m_unk1D0;                       // +0x1D0
    int m_unk1D4;                       // +0x1D4
    int m_pad1D8[6];                    // +0x1D8..+0x1EF
    void *m_unk1F0;                     // +0x1F0
    int m_unk1F4;                       // +0x1F4
    int *m_unk1F8;                      // +0x1F8
    int m_unk1FC;                       // +0x1FC

    virtual void v1();
    virtual void v2();
    virtual int getType();              // vtable at +0x200, slot 3 (+0x18)

    inline int &flags3EC(ACHRstat *a) { return *(int *)a->m_unk3EC; }
}; // size 0x204

struct EmyOutView {
    unsigned int m_oid;                 // +0x00
    int m_unk04;                        // +0x04
    ACHRstat *m_achr;                   // +0x08
    EmyMainView *m_owner;               // +0x0C
    int m_targetKind;                   // +0x10
    unsigned int m_targetOid;           // +0x14
    int m_unk18;                        // +0x18
    int m_unk1C;                        // +0x1C
    int m_unk20;                        // +0x20
    int m_unk24;                        // +0x24
    int m_unk28;                        // +0x28
    int m_sndHandle;                    // +0x2C
    int m_unk30;                        // +0x30
    void *m_vtbl;                       // +0x34

    inline int achrFlags3EC() const { return *(int *)m_achr->m_unk3EC; }
}; // size 0x38

STATIC_ASSERT(sizeof(EmyMainView) == 0x204, EmyMainView_size);
STATIC_ASSERT(sizeof(EmyOutView) == 0x38, EmyOutView_size);

#endif // UNK_00166AD0_H
