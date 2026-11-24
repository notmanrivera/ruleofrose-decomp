// unk/EffLight2.h: EffFoot1, EffFoot1Prim, EffFoot2, EffFoot2Prim, EffGeneric1,
// EffLight1, EffLight2, EffLight3, and EffFindItem1 (all derive from Eff0).
//
// Evidence:
// - Vtables _vt$11EffGeneric1, _vt$9EffLight3 stored at +0x20 after Eff0 ctor
//   (func_0016A914), and _$_11EffGeneric1 calls _$_4Eff0 + BedMemory::free.
// - Mangled names: updateZDepth__12EffFoot1Prim, _$_11EffGeneric1,
//   renderPreMain__11EffGeneric1PQ24Eff011RENDERPARAM, liveActivateExec__9EffLight1,
//   render__9EffLight2PQ24Eff011RENDERPARAM, liveActivateExec__9EffLight2,
//   _$_9EffLight3, render__12EffFindItem1PQ24Eff011RENDERPARAM,
//   updateZDepth__12EffFindItem1.
#ifndef UNK_EFFLIGHT2_H
#define UNK_EFFLIGHT2_H

#include "unk/Eff0.h"

struct EffFoot1CheckArg {
    unsigned int m_flags;               // +0x00
    void *m_actor;                      // +0x04
    float m_cx;                         // +0x08
    float m_cy;                         // +0x0C
    float m_cz;                         // +0x10
    float m_r1;                         // +0x14
    float m_hy;                         // +0x18
    float m_unk1C;                      // +0x1C
    float m_r2;                         // +0x20
    float m_pts[4][3];                  // +0x24
    unsigned char m_pad54[0x0C];        // +0x54
};

struct EffFoot1SpawnParam {
    int m_kind;                         // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    float m_pos[3];                     // +0x10
    int m_unk1C;                        // +0x1C
    int m_unk20;                        // +0x20
    float m_unk24;                      // +0x24
    float m_unk28;                      // +0x28
    unsigned char m_pad2C[0x54];        // +0x2C
};

struct EffFoot1Arg {
    unsigned char m_pad00[0x10];        // +0x00
    float m_p0[3];                      // +0x10
    float m_p1[3];                      // +0x1C
    int m_unk28;                        // +0x28
    int m_unk2C;                        // +0x2C
    float m_unk30;                      // +0x30
    float m_unk34;                      // +0x34
};

struct EffFoot1 : public Eff0 {
    float m_center[3];                  // +0x24
    float m_size[3];                    // +0x30
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    float m_unk44;                      // +0x44
    float m_unk48;                      // +0x48
};

struct EffFoot1PrimArg {
    unsigned char m_pad00[0x10];        // +0x00
    float m_x, m_y, m_z;                // +0x10
    int m_unk1C;                        // +0x1C
    int m_unk20;                        // +0x20
    float m_unk24;                      // +0x24
    float m_unk28;                      // +0x28
};

struct EffFoot1Prim : public Eff0 {
    unsigned char m_pad24[0x0C];        // +0x24
    EffVec4 m_pos;                      // +0x30
    int m_unk40;                        // +0x40
    int m_mode;                         // +0x44
    int m_frame;                        // +0x48
    float m_unk4C;                      // +0x4C
    float m_unk50;                      // +0x50
};

struct EffFoot2State {
    int m_unk00;                        // +0x00
    int m_unk04;                        // +0x04
    float m_unk08;                      // +0x08
};

struct EffFoot2PrimArg : public Eff0Arg {        // +0x00
    int m_unk10;                        // +0x10
    EffVec3 m_pos;                      // +0x14
    float m_unk20;                      // +0x20
    float m_unk24;                      // +0x24
    unsigned char m_unk28[0x58];        // +0x28: common 0x80-byte spawn packet
};

struct EffFoot2Prim : public Eff0 {
    int m_unk24;                        // +0x24
    unsigned char m_pad28[0x08];        // +0x28
    EffVec3 m_pos;                      // +0x30
    float m_w;                          // +0x3C
    float m_unk40;                      // +0x40
    float m_unk44;                      // +0x44
    int m_frame;                        // +0x48
};

struct EffGenericKey {
    unsigned short m_frame;             // +0x00
    unsigned short m_flags;             // +0x02
    float m_value;                      // +0x04
}; // size 0x08

struct EffGenericTrack {
    int m_unk00;                        // +0x00
    unsigned short m_numKeys;           // +0x04
    unsigned short m_mask;              // +0x06
    EffGenericKey m_keys[1];            // +0x08
};

struct EffGenericChunk {
    unsigned short m_type;              // +0x00
    unsigned short m_size;              // +0x02
    float m_tag[8];                     // +0x04
    float m_du;                         // +0x24
    float m_dv;                         // +0x28
    float m_u;                          // +0x2C
    float m_v;                          // +0x30
};

struct EffGenericData {
    unsigned short m_flags;             // +0x00
    unsigned short m_chunkCount;        // +0x02
    unsigned char m_pad04[0x0C];        // +0x04
};

struct EffUvKey {
    unsigned short m_frame;             // +0x00
    unsigned short m_pad02;             // +0x02
    float m_u;                          // +0x04
    float m_v;                          // +0x08
    int m_unk0C;                        // +0x0C
}; // size 0x10

struct EffUvTrack {
    unsigned char m_pad00[0x04];        // +0x00
    float m_tag[8];                     // +0x04
    unsigned short m_numKeys;           // +0x24
    unsigned short m_pad26;             // +0x26
    EffUvKey m_keys[1];                 // +0x28
};

struct EffGeneric1 : public Eff0 {
    EffGeneric1() asm("func_00173DF8");
    char *m_buf24;                      // +0x24
    int m_unk28;                        // +0x28
    void *m_buf2C;                      // +0x2C
    void *m_unk30;                      // +0x30
    void *m_unk34;                      // +0x34
    void *m_buf38;                      // +0x38
    EffVec4 *m_uvList;                  // +0x3C
    EffGenericData *m_data;             // +0x40
    unsigned short m_curFrame;          // +0x44
    unsigned short m_maxFrame;          // +0x46
};

struct EffLight1Arg {
    unsigned char m_pad00[0x10];        // +0x00
    EffVec3 m_pos;                      // +0x10
    EffVec2 m_size;                     // +0x1C
    EffVec4 m_color;                    // +0x24
    float m_unk34;                      // +0x34
    int m_flag;                         // +0x38
};

struct EffLight1 : public Eff0 {
    unsigned char m_pad24[0x0C];        // +0x24
    EffVec3 m_pos;                      // +0x30
    float m_w;                          // +0x3C
    EffVec2 m_size;                     // +0x40
    unsigned char m_pad48[0x08];        // +0x48
    EffVec4 m_color;                    // +0x50
    float m_unk60;                      // +0x60
    int m_frame;                        // +0x64
    int m_fade;                         // +0x68
};

struct EffLight2Arg {
    unsigned char m_pad00[0x10];        // +0x00
    EffVec3 m_pos;                      // +0x10
    float m_unk1C;                      // +0x1C
    float m_unk20;                      // +0x20
    EffVec4 m_color;                    // +0x24
    int m_unk34;                        // +0x34
    float m_unk38;                      // +0x38
    float m_unk3C;                      // +0x3C
    int m_flag;                         // +0x40
};

struct EffLight2 : public Eff0 {
    unsigned char m_pad24[0x0C];        // +0x24
    EffVec3 m_pos;                      // +0x30
    float m_w;                          // +0x3C
    float m_unk40;                      // +0x40
    float m_unk44;                      // +0x44
    float m_unk48;                      // +0x48
    float m_unk4C;                      // +0x4C
    EffVec4 m_color;                    // +0x50
    float m_alpha;                      // +0x60
    float m_unk64;                      // +0x64
    float m_unk68;                      // +0x68
    float m_dist;                       // +0x6C
    int m_unk70;                        // +0x70
    int m_frame;                        // +0x74
    int m_fade;                         // +0x78
};

struct EffLight3 : public Eff0 {
    int m_entries[6][16][2];            // +0x24..0x323 ([i][j][0]=idx, [i][j][1]=handle)
    unsigned char m_pad324[0x0C];       // +0x324..0x32F
    float m_ambColor[3];                // +0x330..0x33B
    unsigned char m_pad33C[0x04];       // +0x33C..0x33F
    float m_f340[4];                    // +0x340..0x34F
    float m_f350[4];                    // +0x350..0x35F
    float m_f360;                       // +0x360
    unsigned char m_f364;               // +0x364
    unsigned char m_f365;               // +0x365
    unsigned char m_pad366[0x2A];       // +0x366..0x38F
    int m_unk390;                       // +0x390
};

struct EffFindItem1Arg {
    unsigned char m_pad00[0x10];        // +0x00
    float m_x, m_y, m_z;                // +0x10
    float m_zBias;                      // +0x1C
};

struct EffFindItem1 : public Eff0 {
    unsigned char m_pad24[0x0C];        // +0x24
    EffVec4 m_pos;                      // +0x30
    float m_zBias;                      // +0x40
    unsigned char m_phase;              // +0x44
};

#endif
