// unk/EffWater1.h: EffMuzzleFlash1, EffReload1, EffSteam1, EffSteam1Prim,
// EffSteam2, EffSteam2Prim, EffCloud1, EffWater1, EffWater3 (all inherit Eff0).
#ifndef UNK_EFFWATER1_H
#define UNK_EFFWATER1_H

#include "unk/Eff0.h"

struct EffMuzzleFlashLayer {
    float m_angle;                      // +0x00
    float m_size;                       // +0x04
    float m_offsetY;                    // +0x08
    short m_alpha;                      // +0x0C
    short m_alphaVel;                   // +0x0E
}; // size 0x10

struct EffMuzzleFlash1Arg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
}; // size 0x1C

struct EffMuzzleFlash1 : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec4A8 m_pos;                    // +0x30..+0x3F
    EffMuzzleFlashLayer m_flash;        // +0x40..+0x4F
    EffMuzzleFlashLayer m_smoke;        // +0x50..+0x5F
    int m_lightId;                      // +0x60
}; // size 0x64 (padded to 0x68 for align 8)

struct EffReload1Arg : public Eff0Arg {
    float m_posX;                       // +0x10
    float m_posY;                       // +0x14
    float m_posZ;                       // +0x18
    float m_rotX;                       // +0x1C
    float m_rotY;                       // +0x20
    float m_rotZ;                       // +0x24
    int m_bulletCount;                  // +0x28
}; // size 0x2C

struct EffReload1 : public Eff0 {
    int m_model;                        // +0x24
    int m_motion;                       // +0x28
    void *m_buf;                        // +0x2C
    int m_posture;                      // +0x30
    int m_matrix;                       // +0x34
    void *m_nodeMap;                    // +0x38
    unsigned char m_pad3C[0x4];         // +0x3C..+0x3F
    EffMat4 m_mat;                      // +0x40..+0x7F (row 3 at +0x70 = pos)
    int m_frame;                        // +0x80
}; // size 0x84 (padded to 0x88 for align 8)

struct EffSteam1Arg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_rotX;                       // +0x1C
    float m_rotY;                       // +0x20
    float m_unk24;                      // +0x24
    float m_unk28;                      // +0x28
    EffVec4 m_color;                    // +0x2C..+0x3B
    int m_minTime;                      // +0x3C
    int m_addTime;                      // +0x40
}; // size 0x44

struct EffSteam1 : public Eff0 {
    int m_timer24;                      // +0x24
    int m_minTime;                      // +0x28
    int m_period;                       // +0x2C
    EffMat4 m_mat;                      // +0x30..+0x6F (row 3 at +0x60 = pos)
    float m_unk70;                      // +0x70
    float m_unk74;                      // +0x74
    EffVec4 m_color;                    // +0x78..+0x87
}; // size 0x88

struct EffSteam1PrimArg : public Eff0Arg {
    EffVec4 *m_posPtr;                  // +0x10
    float m_dirX;                       // +0x14
    float m_dirY;                       // +0x18
    float m_dirZ;                       // +0x1C
    float m_scale;                      // +0x20
    float m_speed;                      // +0x24
    float m_fadeSpeed;                  // +0x28
    EffVec4 m_color;                    // +0x2C..+0x3B
}; // size 0x3C

struct EffSteam1Prim : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec4 m_pos;                      // +0x30..+0x3F
    EffVec3 m_vel;                      // +0x40..+0x4B
    int m_unk4C;                        // +0x4C
    int m_pad50;                        // +0x50
    float m_size;                       // +0x54
    float m_scale;                      // +0x58
    float m_alpha;                      // +0x5C
    float m_alphaVel;                   // +0x60
    float m_fadeSpeed;                  // +0x64
    EffVec4 m_color;                    // +0x68..+0x77
}; // size 0x78

struct EffSteam2Arg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_scale;                      // +0x1C
    float m_alpha;                      // +0x20
}; // size 0x24

struct EffSteam2 : public Eff0 {
    EffVec3 m_pos;                      // +0x24..+0x2F
    float m_scale;                      // +0x30
    float m_alpha;                      // +0x34
    unsigned char m_wait;               // +0x38
    unsigned char m_pad39[0x3];         // +0x39..+0x3B
}; // size 0x3C

struct EffSteam2PrimArg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_scale;                      // +0x1C
    float m_alpha;                      // +0x20
}; // size 0x24

struct EffSteam2Prim : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec3 m_pos;                      // +0x30..+0x3B
    float m_posW;                       // +0x3C
    float m_scale;                      // +0x40
    float m_alpha;                      // +0x44
    unsigned char m_age;                // +0x48
    unsigned char m_pad49[0x3];         // +0x49..+0x4B
}; // size 0x4C

struct EffCloud1Arg : public Eff0Arg {
    EffVec3 m_origin;                   // +0x10..+0x1B
    float m_rotY;                       // +0x1C
    float m_radius;                     // +0x20
    float m_speed;                      // +0x24
    float m_dist;                       // +0x28
    EffVec4 m_color;                    // +0x2C..+0x3B
}; // size 0x3C

struct EffCloud1 : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec3 m_pos;                      // +0x30..+0x3B
    float m_posW;                       // +0x3C
    EffVec3 m_origin;                   // +0x40..+0x4B
    EffVec3 m_vel;                      // +0x4C..+0x57
    float m_radius;                     // +0x58
    int m_seed;                         // +0x5C
    EffVec4 m_color;                    // +0x60..+0x6F
    int m_tick;                         // +0x70
    int m_moveDur;                      // +0x74
    int m_totalDur;                     // +0x78
}; // size 0x7C

struct EffWater1 : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec4A8 m_pos;                    // +0x30..+0x3F
    float m_rotY;                       // +0x40
    float m_scale;                      // +0x44
    unsigned char m_pad48[0x8];         // +0x48..+0x4F
    EffVec4 m_color;                    // +0x50..+0x5F
    void *m_modelBuf;                   // +0x60 (+0x10 = i3r root)
    float m_scrollU;                    // +0x64
    float m_scrollV;                    // +0x68
    unsigned char m_pad6C[0x4];         // +0x6C..+0x6F
    float m_uvU;                        // +0x70
    float m_uvV;                        // +0x74
    float m_unk78;                      // +0x78
    float m_unk7C;                      // +0x7C
    int m_fade;                         // +0x80
}; // size 0x84 (padded to 0x88 for align 8)

struct EffWater3Entry {
    EffVec4 m_header;                   // +0x00..+0x0F
    EffVec4 m_drops[8];                 // +0x10..+0x8F
    EffVec4 m_ripples[4];               // +0x90..+0xCF
}; // size 0xD0

struct EffWater3 : public Eff0 {
    EffWater3Entry *m_entries;          // +0x24
    int m_count;                        // +0x28
    unsigned char m_pad2C[0x4];         // +0x2C..+0x2F
    float m_maxY;                       // +0x30
    unsigned char m_pad34[0x4];         // +0x34..+0x37
    float m_speedY;                     // +0x38
}; // size 0x3C

typedef char EffMuzzleFlash1_size_check[sizeof(EffMuzzleFlash1) == 0x68 ? 1 : -1];
typedef char EffReload1_size_check[sizeof(EffReload1) == 0x88 ? 1 : -1];
typedef char EffSteam1_size_check[sizeof(EffSteam1) == 0x88 ? 1 : -1];
typedef char EffSteam1Prim_size_check[sizeof(EffSteam1Prim) == 0x78 ? 1 : -1];
typedef char EffSteam2_size_check[sizeof(EffSteam2) == 0x3C ? 1 : -1];
typedef char EffSteam2Prim_size_check[sizeof(EffSteam2Prim) == 0x4C ? 1 : -1];
typedef char EffCloud1_size_check[sizeof(EffCloud1) == 0x7C ? 1 : -1];
typedef char EffWater1_size_check[sizeof(EffWater1) == 0x88 ? 1 : -1];
typedef char EffWater3Entry_size_check[sizeof(EffWater3Entry) == 0xD0 ? 1 : -1];
typedef char EffWater3_size_check[sizeof(EffWater3) == 0x3C ? 1 : -1];

#endif
