// mag/maglifebwn.h: Brown (the dog) life & controller family:
//   MagLifeControlChara -> MagLifeBwn (size 0xD3C, embeds 10 MagLifeBwnMode* sub-objects at +0xCF0..+0xD3B)
//   MagLife             -> MagLifeBwnCtrl (controller, holds MagLifeBwn *m_bwn at +0x70)
//   MagLifeBwnMode      -> Null, One, Wait, Sit, Fuse, Move, Path, Turn, Wall, Rotate
//   MagLifeBwnCtrlMode  -> Null, Wait, Follow, Stay, Find, FindEnd, Move, MoveEnd,
//                          Rot, RotEnd, Damage, Bark, SitOut, Hug, Wound
//
// Evidence:
// - RTTI hierarchy in notes/class_hierarchy.txt and mag/maglife.h.
// - MagLifeBwn ctor func_00125AA4 in unk/MagLifeBwnModeSit.cpp initializes all 10
//   MagLifeBwnMode* vptrs at +0xCF0..+0xD30.
// - Mode structs keep explicit void *m_vtbl (no C++ virtuals) so embedding them
//   does not emit duplicate RTTI strings into .rodata; MagLifeBwn and MagLifeBwnCtrl
//   declare out-of-line key virtuals (vfunc16 / vfunc09) for the same reason.
#ifndef MAG_MAGLIFEBWN_H
#define MAG_MAGLIFEBWN_H

#include "mag/maglife.h"

struct MagBwnVec4 {
    float x, y, z, w;
}; // size 0x10

struct MagLifeBwnMode {
    void *m_vtbl;                       // +0x00
}; // size 0x04

struct MagLifeBwnModeNull : public MagLifeBwnMode {};   // size 0x04
struct MagLifeBwnModeOne : public MagLifeBwnMode {};    // size 0x04

struct MagLifeBwnModeWait : public MagLifeBwnMode {
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
}; // size 0x0C

struct MagLifeBwnModeSit : public MagLifeBwnMode {};    // size 0x04
struct MagLifeBwnModeFuse : public MagLifeBwnMode {};   // size 0x04

struct MagLifeBwnModeMove : public MagLifeBwnMode {
    int m_motion;                       // +0x04
    int m_state;                        // +0x08
}; // size 0x0C

struct MagLifeBwnModePath : public MagLifeBwnMode {
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
}; // size 0x10

struct MagLifeBwnModeTurn : public MagLifeBwnMode {};   // size 0x04
struct MagLifeBwnModeWall : public MagLifeBwnMode {};   // size 0x04

struct MagLifeBwnModeRotate : public MagLifeBwnMode {
    float m_target_rot;                 // +0x04 (named by assert in func_001264F8)
    float m_diff_rot;                   // +0x08
}; // size 0x0C

class MagLifeBwn : public MagLifeControlChara {
public:
    int m_nextMode[4];                  // +0x080..+0x08F (zeroed as u_long128 in ctor)
    MagBwnVec4 m_targetPos;             // +0x090..+0x09F
    MagBwnVec4 m_pathPoints[0x7F];      // +0x0A0..+0x88F
    unsigned char m_pad890[0x410];      // +0x890..+0xC9F
    int m_unkCA0;                       // +0xCA0
    int m_padCA4[2];                    // +0xCA4..+0xCAB
    int m_unkCAC;                       // +0xCAC
    int m_padCB0[2];                    // +0xCB0..+0xCB7
    int m_unkCB8;                       // +0xCB8
    int m_unkCBC;                       // +0xCBC
    int m_unkCC0;                       // +0xCC0 (mode done flag)
    int m_unkCC4;                       // +0xCC4
    int m_padCC8[2];                    // +0xCC8..+0xCCF
    int m_unkCD0;                       // +0xCD0
    int m_unkCD4;                       // +0xCD4
    int m_unkCD8;                       // +0xCD8 (dirty flag)
    int m_unkCDC;                       // +0xCDC
    float m_unkCE0;                     // +0xCE0
    int m_unkCE4;                       // +0xCE4 (render pause flag)
    int m_unkCE8;                       // +0xCE8 (saved motion no)
    int m_unkCEC;                       // +0xCEC
    MagLifeBwnModeNull m_modeNull;      // +0xCF0
    MagLifeBwnModeOne m_modeOne;        // +0xCF4
    MagLifeBwnModeWait m_modeWait;      // +0xCF8
    MagLifeBwnModeSit m_modeSit;        // +0xD04
    MagLifeBwnModeFuse m_modeFuse;      // +0xD08
    MagLifeBwnModeMove m_modeMove;      // +0xD0C
    MagLifeBwnModePath m_modePath;      // +0xD18
    MagLifeBwnModeTurn m_modeTurn;      // +0xD28
    MagLifeBwnModeWall m_modeWall;      // +0xD2C
    MagLifeBwnModeRotate m_modeRotate;  // +0xD30

    virtual void vfunc16(int theMode, int theA, int theB) asm("MagLifeBwn__vfunc_16");
}; // size 0xD3C

struct MagLifeBwnCtrlMode {
    void *m_vtbl;                       // +0x00
}; // size 0x04

struct MagLifeBwnCtrlModeFollow : public MagLifeBwnCtrlMode {
    int m_unk04;                        // +0x04
}; // size 0x08

struct MagLifeBwnCtrlModeHug : public MagLifeBwnCtrlMode {
    int m_unk04;                        // +0x04
}; // size 0x08

struct MagLifeBwnCtrlModeBark : public MagLifeBwnCtrlMode {
    unsigned char m_pad04[0x20];        // +0x04..+0x23
    int m_unk24;                        // +0x24
    int m_unk28;                        // +0x28
    unsigned char m_pad2C[0x8];         // +0x2C..+0x33
}; // size 0x34

class MagLifeBwnCtrl : public MagLife {
public:
    MagBwnVec4 m_targetPos;             // +0x030..+0x03F
    float m_targetRot;                  // +0x040
    unsigned char m_pad44[0x1C];        // +0x044..+0x05F
    int m_unk60;                        // +0x060
    int m_unk64;                        // +0x064
    int m_unk68;                        // +0x068
    int m_unk6C;                        // +0x06C
    MagLifeBwn *m_bwn;                  // +0x070
    int m_unk74;                        // +0x074
    int m_unk78;                        // +0x078
    int m_unk7C;                        // +0x07C
    int m_unk80;                        // +0x080
    int m_unk84;                        // +0x084
    MagLifeBwnCtrlMode *m_unk88;        // +0x088
    unsigned char m_pad8C[0x64];        // +0x08C..+0x0EF
    MagLifeBwnCtrlModeBark m_modeBark;  // +0x0F0..+0x123
    int m_unk124;                       // +0x124

    virtual void vfunc09() asm("MagLifeBwnCtrl__vfunc_09");
}; // size 0x128

typedef char MagLifeBwn_size_check[sizeof(MagLifeBwn) == 0xD3C ? 1 : -1];
typedef char MagLifeBwnCtrl_size_check[sizeof(MagLifeBwnCtrl) == 0x128 ? 1 : -1];

#endif
