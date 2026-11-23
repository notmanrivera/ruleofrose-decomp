// unk/EffFire1.h: EffDust2, EffDust2Prim, EffFire1, EffFire1Ex, EffFire2,
// EffFog1, EffFog2, EffFog2Prim, EffFog3 (all inherit Eff0 from unk/Eff0.h).
#ifndef UNK_EFFFIRE1_H
#define UNK_EFFFIRE1_H

#include "unk/Eff0.h"

struct EffDust2Arg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_unk1C;                      // +0x1C
    EffVec3 m_vel;                      // +0x20..+0x2B
    float m_unk2C;                      // +0x2C
    EffVec4 m_color;                    // +0x30..+0x3F
    float m_unk40;                      // +0x40
}; // size 0x44

struct EffDust2 : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec3 m_pos;                      // +0x30..+0x3B
    float m_posW;                       // +0x3C
    float m_unk40;                      // +0x40
    unsigned char m_pad44[0xC];         // +0x44..+0x4F
    EffVec3 m_vel;                      // +0x50..+0x5B
    float m_velW;                       // +0x5C
    float m_unk60;                      // +0x60
    unsigned char m_pad64[0xC];         // +0x64..+0x6F
    EffVec4 m_color;                    // +0x70..+0x7F
    float m_unk80;                      // +0x80
    short m_unk84;                      // +0x84
    short m_pad86;                      // +0x86
    int m_prims[12];                    // +0x88..+0xB7
}; // size 0xB8

struct EffDust2PrimArg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_size;                       // +0x1C
    EffVec4 m_color;                    // +0x20..+0x2F
}; // size 0x30

struct EffDust2Prim : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec3 m_pos;                      // +0x30..+0x3B
    float m_posW;                       // +0x3C
    float m_size;                       // +0x40
    unsigned char m_pad44[0xC];         // +0x44..+0x4F
    EffVec4 m_color;                    // +0x50..+0x5F
    int m_age;                          // +0x60
}; // size 0x64

struct EffFire1Arg : public Eff0Arg {
    float m_x;                          // +0x10
    float m_y;                          // +0x14
    float m_z;                          // +0x18
    EffVec4 m_color;                    // +0x1C..+0x2B
    float m_scale;                      // +0x2C
}; // size 0x30

struct EffFire1 : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec4A8 m_pos;                    // +0x30..+0x3F
    EffVec4 m_color;                    // +0x40..+0x4F
    unsigned int m_tick;                // +0x50
    float m_intensity;                  // +0x54
    float m_scale;                      // +0x58
    int m_fade;                         // +0x5C
}; // size 0x60

struct EffFire1ExArg : public Eff0Arg {
    void *m_actor;                      // +0x10
    char m_nodeName[0x20];              // +0x14..+0x33
    EffVec4 m_color;                    // +0x34..+0x43
}; // size 0x44

struct EffFire1Ex : public EffFire1 {
    void *m_actor;                      // +0x60
    char m_nodeName[0x20];              // +0x64..+0x83
}; // size 0x84

struct EffFire2Arg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_rotX;                       // +0x1C
    float m_rotY;                       // +0x20
    float m_rotZ;                       // +0x24
    float m_scale;                      // +0x28
    float m_alpha;                      // +0x2C
}; // size 0x30

struct EffFire2 : public Eff0 {
    unsigned int m_tick;                // +0x24
    float m_alpha;                      // +0x28
    unsigned char m_pad2C[0x4];         // +0x2C..+0x2F
    EffMat4 m_mat;                      // +0x30..+0x6F (row 3 at +0x60 = pos)
}; // size 0x70

struct EffFog1Arg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_sizeX;                      // +0x1C
    float m_sizeY;                      // +0x20
    float m_unk24;                      // +0x24
    float m_unk28;                      // +0x28
    int m_centerY;                      // +0x2C
}; // size 0x30

struct EffFog1 : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec4A8 m_pos;                    // +0x30..+0x3F
    EffVec4A8 m_basePos;                // +0x40..+0x4F
    float m_sizeX;                      // +0x50
    float m_sizeY;                      // +0x54
    float m_unk58;                      // +0x58
    float m_unk5C;                      // +0x5C
    float m_unk60;                      // +0x60
    float m_unk64;                      // +0x64
    int m_tick;                         // +0x68
}; // size 0x6C

struct EffFog2Arg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_angle;                      // +0x1C
    float m_radius;                     // +0x20
    float m_scale;                      // +0x24
    EffVec4 m_color;                    // +0x28..+0x37
}; // size 0x38

struct EffFog2 : public Eff0 {
    int m_tick;                         // +0x24
    EffVec3 m_pos;                      // +0x28..+0x33
    float m_angle;                      // +0x34
    float m_radius;                     // +0x38
    float m_scale;                      // +0x3C
    EffVec4 m_color;                    // +0x40..+0x4F
}; // size 0x50

struct EffFog2Prim : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec4 m_pos;                      // +0x30..+0x3F
}; // size 0x40

struct EffFog3 : public Eff0 {
    unsigned int m_tick;                // +0x24
    unsigned int m_interval;            // +0x28
}; // size 0x2C

typedef char EffDust2_size_check[sizeof(EffDust2) == 0xB8 ? 1 : -1];
typedef char EffDust2Prim_size_check[sizeof(EffDust2Prim) == 0x64 ? 1 : -1];
typedef char EffFire1_size_check[sizeof(EffFire1) == 0x60 ? 1 : -1];
typedef char EffFire1Ex_size_check[sizeof(EffFire1Ex) == 0x88 ? 1 : -1];
typedef char EffFire2_size_check[sizeof(EffFire2) == 0x70 ? 1 : -1];
typedef char EffFog1_size_check[sizeof(EffFog1) == 0x70 ? 1 : -1];
typedef char EffFog2_size_check[sizeof(EffFog2) == 0x50 ? 1 : -1];
typedef char EffFog3_size_check[sizeof(EffFog3) == 0x2C ? 1 : -1];

#endif
