// unk/Eff0.h: shared base class Eff0 (size 0x24, vtable at +0x20) and common
// effect vector/matrix/render-param types for the 42 Eff* subclasses.
//
// Evidence:
// - Vtable _vt$4Eff0 (0x002E3250, 12 slots at +0x20): dtor, init (vfunc_02),
//   term (vfunc_03), exec (vfunc_04), liveExec (vfunc_05, pure), render,
//   renderPreMain, renderMain (pure), createPacketEntry, setVisible (vfunc_10),
//   liveActivateExec, updateZDepth.
// - Layout recovered from unk/Eff0.cpp (func_0016A914, _$_4Eff0, vfunc_02..10,
//   render, renderPreMain, createPacketEntry), unk/EffLight2.h, and layouts.py.
// - Kept without C++ virtuals here so subclasses can inherit Eff0 safely while
//   their vtables live in asm/data/vtbl/.
#ifndef UNK_EFF0_H
#define UNK_EFF0_H

struct EffVec2 {
    float x, y;
};

struct EffVec3 {
    float x, y, z;
};

struct EffVec4 {
    float x, y, z, w;
};

struct EffVec4A8 {
    float x, y, z, w;
} __attribute__((aligned(8)));

struct EffMat4 {
    float m[4][4];
} __attribute__((aligned(8)));

struct EffRenderParam {
    int m_unk00;                        // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
};

struct Eff0Arg {
    int m_kind;                         // +0x00
    int m_unk04;                        // +0x04
    int m_delay;                        // +0x08
    void *m_parent;                     // +0x0C
};

struct Eff0 {
    unsigned short m_flags;             // +0x00
    unsigned short m_pad02;             // +0x02
    int m_timer;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    float m_zDepth;                     // +0x10
    void *m_parent;                     // +0x14
    int m_kind;                         // +0x18
    int m_delay;                        // +0x1C
    void *m_vtbl;                       // +0x20
}; // size 0x24

typedef char Eff0_size_check[sizeof(Eff0) == 0x24 ? 1 : -1];

#endif
