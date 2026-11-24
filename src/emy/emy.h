// emy/emy.h: shared base classes for the enemy family (EmyMain, EmyOut,
// EmyManager).
//
// Evidence:
// - RTTI hierarchy (notes/class_hierarchy.txt):
//   * EmyMain [7] -> BdlMain, BdsMain, ClrMain [8], DwfMain, FshMain,
//     GotMain, GrgMain, HfmMain [8], MrtMain, NorMain [8], PigMain.
//   * EmyOut [5] -> ~85 *Out* enemy state classes.
//   * CmnITask [7] -> EmyManager.
// - Layouts confirmed from emy/emy_main.cpp (func_00164118 EmyMain ctor,
//   func_0016265C/func_00162698 EmyManager ctor/reset), unk/EmyOut.cpp
//   (func_00166A1C EmyOut ctor, _$_6EmyOut dtor), unk/NorMain.cpp, and
//   tools/layouts.py.
// - Confirmed R22 open question: offsets +0x00..+0x48 are direct EmyMain
//   fields initialized in func_00164118 (the ACHRstat/ObjStat pointer is
//   stored at EmyMain +0x20, EmyBrain at +0x1C, active EmyOut at +0x44).
#ifndef EMY_EMY_H
#define EMY_EMY_H

#include "ror.h"

struct EmyOut;

// 8-byte g++ 2.96 pointer-to-member-function slot (EmyMain +0x1DC).
struct EmyMemFn {
    short m_delta;                      // +0x00
    short m_index;                      // +0x02 (< 0 for non-virtual)
    int m_pfn;                          // +0x04 (fn ptr or vtable offset)
};

// Minimal view of the brain object pointed to by EmyMain::m_brain (+0x1C).
struct EmyBrainView {
    unsigned char m_pad00[0xA4];        // +0x00..+0xA3
    int m_state;                        // +0xA4
};

// Minimal view of the ACHRstat / ObjStat pointed to by EmyMain::m_objStat (+0x20).
struct EmyObjStatView {
    unsigned char m_pad00[0x108];       // +0x00..+0x107
    int m_actorId;                      // +0x108
    unsigned char m_pad10C[0x14];       // +0x10C..+0x11F
    int m_flags;                        // +0x120
    unsigned short m_unk124;            // +0x124
    unsigned short m_hp;                // +0x126
};

// Base enemy controller (size 0x204, vtable at +0x200).
// Derived *Main classes place their own fields starting at +0x204.
struct EmyMain {
    int m_id;                           // +0x00: enemy id (matched by EmyManager)
    unsigned short m_unk04;             // +0x04
    unsigned char m_unk06;              // +0x06
    unsigned char m_unk07;              // +0x07
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    int m_unk10;                        // +0x10
    int m_unk14;                        // +0x14
    int m_unk18;                        // +0x18
    void *m_brain;                      // +0x1C (EmyBrainView *)
    void *m_objStat;                    // +0x20 (EmyObjStatView * / ACHRstat *)
    int m_nextState;                    // +0x24 (-1 = none)
    int m_unk28;                        // +0x28
    int m_unk2C;                        // +0x2C
    int m_flags30;                      // +0x30
    int m_unk34;                        // +0x34
    int m_unk38;                        // +0x38
    int m_curState;                     // +0x3C
    int m_stateChanged;                 // +0x40
    EmyOut *m_curOut;                   // +0x44
    unsigned char m_unk48[0xA0];        // +0x48..+0xE7
    int m_unkE8;                        // +0xE8
    unsigned char m_padEC[0x3C];        // +0xEC..+0x127
    unsigned char m_stateFlags[0x28];   // +0x128..+0x14F
    int m_unk150;                       // +0x150
    int m_unk154;                       // +0x154..+0x1C3 (0x70 bytes zeroed in ctor)
    int m_unk158;                       // +0x158
    int m_unk15C;                       // +0x15C
    int m_unk160;                       // +0x160
    int m_unk164;                       // +0x164
    int m_unk168;                       // +0x168
    int m_unk16C;                       // +0x16C
    unsigned char m_pad170[0x54];       // +0x170..+0x1C3
    float m_unk1C4;                     // +0x1C4
    int m_unk1C8;                       // +0x1C8
    int m_unk1CC;                       // +0x1CC
    short m_unk1D0;                     // +0x1D0
    short m_pad1D2;                     // +0x1D2
    int m_unk1D4;                       // +0x1D4
    int m_unk1D8;                       // +0x1D8 (low ushort = max HP)
    EmyMemFn m_callback;                // +0x1DC..+0x1E3
    int m_unk1E4;                       // +0x1E4
    int m_unk1E8;                       // +0x1E8
    int m_unk1EC;                       // +0x1EC
    void *m_unk1F0;                     // +0x1F0
    int m_unk1F4;                       // +0x1F4
    void *m_unk1F8;                     // +0x1F8
    int m_unk1FC;                       // +0x1FC
    void *m_vtbl;                       // +0x200 (_vt$7EmyMain / derived)
};
STATIC_ASSERT(sizeof(EmyMain) == 0x204, EmyMain_size);

// Base enemy state/output handler (size 0x38, vtable at +0x34).
struct EmyOut {
    int m_unk00;                        // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    EmyMain *m_owner;                   // +0x0C
    int m_unk10;                        // +0x10
    int m_unk14;                        // +0x14
    int m_unk18;                        // +0x18
    int m_unk1C;                        // +0x1C
    int m_unk20;                        // +0x20
    int m_unk24;                        // +0x24
    int m_unk28;                        // +0x28
    int m_unk2C;                        // +0x2C
    int m_unk30;                        // +0x30
    void *m_vtbl;                       // +0x34 (_vt$6EmyOut / derived)
};
STATIC_ASSERT(sizeof(EmyOut) == 0x38, EmyOut_size);

struct EmyOut3C : public EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
};

// Per-group scheduling entry in EmyManager (+0x148, 8 entries, stride 0x3C).
struct EmyGroup {
    int m_unk00;                        // +0x00 (+0x148 for group 0)
    int m_unk04;                        // +0x04 (+0x14C)
    int m_unk08;                        // +0x08 (+0x150)
    int m_unk0C;                        // +0x0C (+0x154)
    float m_unk10[3];                   // +0x10..+0x1B (+0x158..+0x160)
    float m_unk1C;                      // +0x1C (+0x164)
    float m_unk20;                      // +0x20 (+0x168)
    int m_unk24;                        // +0x24 (+0x16C for group 0)
    int m_unk28;                        // +0x28 (+0x170 for group 0)
    int m_unk2C;                        // +0x2C
    int m_unk30;                        // +0x30 (+0x178 for group 0)
    int m_unk34;                        // +0x34
    int m_unk38;                        // +0x38 (+0x180 for group 0)
};
STATIC_ASSERT(sizeof(EmyGroup) == 0x3C, EmyGroup_size);

// Global enemy manager task (inherits CmnITask, vtable at +0x00).
struct EmyManager {
    void *m_vtbl;                       // +0x00 (_vt$10EmyManager)
    EmyMain *m_emy[0x40];               // +0x04..+0x103
    int m_unk104[0x0C];                 // +0x104..+0x133
    unsigned char m_flag134;            // +0x134
    unsigned char m_flag135;            // +0x135
    unsigned char m_pad136[2];          // +0x136..+0x137
    int m_unk138;                       // +0x138
    int m_unk13C;                       // +0x13C
    int m_unk140;                       // +0x140
    int m_unk144;                       // +0x144
    EmyGroup m_groups[8];               // +0x148..+0x327 (0x1E0 bytes)
    unsigned char m_pad328[8];          // +0x328..+0x32F
    int m_slotVal[0x40];                // +0x330..+0x42F (0x100 bytes)
};
STATIC_ASSERT(sizeof(EmyManager) == 0x430, EmyManager_size);

#endif // EMY_EMY_H
