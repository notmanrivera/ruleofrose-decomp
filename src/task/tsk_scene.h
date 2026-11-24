#ifndef TASK_TSK_SCENE_H
#define TASK_TSK_SCENE_H

#include "task/cmnitask.h"

struct ScenePlaySingle {
    int m_unk00;                // +0x00
    int m_unk04;                // +0x04
    int m_unk08;                // +0x08
    int m_unk0C;                // +0x0C
    int m_unk10;                // +0x10
    int m_oid;                  // +0x14
    unsigned char m_pad18[0x84];
    void *m_vtable;             // +0x9C
};

struct ScenePlay {
    void *m_vtable;                     // +0x00
    unsigned char m_pad04[0x2C];
    int m_unk30;                        // +0x30
    int m_unk34;                        // +0x34
    unsigned char m_pad38[0x8];
    int m_camera_eff_id;                // +0x40
    unsigned char m_pad44[0x88];
    unsigned int m_imd_load_chr_id[16]; // +0xCC
    int m_imd_load_chr_num;             // +0x10C
    char m_unk110[0x20];                // +0x110
};

#endif
