// unk/EffBreath2Prim.h: EffBreath2, EffBreath2Prim, EffBreath2Ground, and
// EffCameraAnim1 (all inherit Eff0 from unk/Eff0.h).
#ifndef UNK_EFFBREATH2PRIM_H
#define UNK_EFFBREATH2PRIM_H

#include "unk/Eff0.h"

struct EffBreath2Arg : public Eff0Arg {
    int m_unk10;                        // +0x10
    int m_unk14;                        // +0x14
    float m_unk18;                      // +0x18
    float m_unk1C;                      // +0x1C
    float m_unk20;                      // +0x20
    EffVec4 m_color;                    // +0x24..+0x33
    int m_unk34;                        // +0x34
}; // size 0x38

struct EffBreath2 : public Eff0 {
    int m_unk24;                        // +0x24
    int m_unk28;                        // +0x28
    float m_unk2C;                      // +0x2C
    float m_unk30;                      // +0x30
    float m_unk34;                      // +0x34
    EffVec4 m_color;                    // +0x38..+0x47
    int m_unk48;                        // +0x48
    int m_unk4C;                        // +0x4C
    int m_unk50;                        // +0x50
}; // size 0x54

struct EffBreath2PrimArg : public Eff0Arg {
    EffVec3 m_pos;                      // +0x10..+0x1B
    float m_dirX;                       // +0x1C
    float m_dirY;                       // +0x20
    float m_dirZ;                       // +0x24
    float m_speed;                      // +0x28
    float m_unk2C;                      // +0x2C
    float m_unk30;                      // +0x30
    EffVec4 m_color;                    // +0x34..+0x43
    int m_unk44;                        // +0x44
}; // size 0x48

struct EffBreath2Prim : public Eff0 {
    unsigned char m_pad24[0xC];         // +0x24..+0x2F
    EffVec3 m_pos;                      // +0x30..+0x3B
    float m_posW;                       // +0x3C
    EffVec3 m_vel;                      // +0x40..+0x4B
    int m_unk4C;                        // +0x4C
    float m_unk50;                      // +0x50
    float m_size;                       // +0x54
    float m_unk58;                      // +0x58
    unsigned char m_pad5C[0x4];         // +0x5C..+0x5F
    EffVec4 m_color;                    // +0x60..+0x6F
    int m_unk70;                        // +0x70
}; // size 0x74

struct EffBreath2GroundArg : public Eff0Arg {
    float m_x;                          // +0x10
    float m_y;                          // +0x14
    float m_z;                          // +0x18
    float m_scale;                      // +0x1C
    EffVec4 m_color;                    // +0x20..+0x2F
    int m_life;                         // +0x30
}; // size 0x34

struct EffBreath2Ground : public Eff0 {
    EffVec4 m_parts[4];                 // +0x24..+0x63
    unsigned char m_pad64[0xC];         // +0x64..+0x6F
    float m_x;                          // +0x70
    float m_y;                          // +0x74
    float m_z;                          // +0x78
    float m_w;                          // +0x7C
    float m_scale;                      // +0x80
    unsigned char m_pad84[0xC];         // +0x84..+0x8F
    EffVec4A8 m_color;                  // +0x90..+0x9F
    int m_age;                          // +0xA0
    int m_life;                         // +0xA4
}; // size 0xA8

struct EffCameraAnimData {
    int m_magic;                        // +0x00 (must be 1)
    int m_frameCount;                   // +0x04
    unsigned char m_pad08[0x8];         // +0x08..+0x0F
    unsigned char m_frames[1];          // +0x10 (stride 0x1C)
};

struct EffCameraAnim1Arg : public Eff0Arg {
    EffCameraAnimData *m_data;          // +0x10
}; // size 0x14

struct EffCameraAnim1 : public Eff0 {
    int m_frame;                        // +0x24
    int m_frameCount;                   // +0x28
    int m_curFramePtr;                  // +0x2C
    int m_savedCamId;                   // +0x30
    float m_savedPosX;                  // +0x34
    float m_savedPosY;                  // +0x38
    float m_savedPosZ;                  // +0x3C
    float m_savedRotX;                  // +0x40
    float m_savedRotY;                  // +0x44
    float m_savedRotZ;                  // +0x48
    float m_savedFov;                   // +0x4C
}; // size 0x50

typedef char EffBreath2_size_check[sizeof(EffBreath2) == 0x54 ? 1 : -1];
typedef char EffBreath2Prim_size_check[sizeof(EffBreath2Prim) == 0x74 ? 1 : -1];
typedef char EffBreath2Ground_size_check[sizeof(EffBreath2Ground) == 0xA8 ? 1 : -1];
typedef char EffCameraAnim1_size_check[sizeof(EffCameraAnim1) == 0x50 ? 1 : -1];

#endif
