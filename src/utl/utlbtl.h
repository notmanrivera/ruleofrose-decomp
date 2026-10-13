// utl/utlbtl.h: battle helpers (random numbers, GamMan queries, hit checks).
// Names are ours except theHitCheck and its members (assert strings).
#ifndef UTL_UTLBTL_H
#define UTL_UTLBTL_H

// Line from m_origin_pos to m_target_pos, optionally rotated (assert lines 60-62).
struct UtlHitLine {
    float *m_origin_pos;    // +0x00
    int m_rotate;           // +0x04
    float m_angle;          // +0x08
    float *m_target_pos;    // +0x0C
    float m_scale;          // +0x10
};

// Cone/range test (assert lines 148-153).
struct UtlHitCone {
    int m_unk00;
    int m_type;             // +0x04: 0..3
    int m_range;            // +0x08
    float *m_pos_self;      // +0x0C
    float *m_pos_target;    // +0x10
    float *m_pos_aim;       // +0x14
    float m_size;           // +0x18
    unsigned char m_unk1C[0xC];
};

#endif
