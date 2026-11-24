#ifndef TASK_TSK_SCENE_H
#define TASK_TSK_SCENE_H

#include "task/cmnitask.h"

struct SceneVoice {
    int m_unk00;                // +0x00
    int m_unk04;                // +0x04
    int m_unk08;                // +0x08
};

struct ScenePlayCmd {
    int m_unk00;                // +0x00
    int m_unk04;                // +0x04
    unsigned char m_pad08[0x40];
};

struct ScenePlaySingle {
    ScenePlayCmd *m_unk00;      // +0x00
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
    ScenePlaySingle *m_unk04[11];       // +0x04
    int m_unk30;                        // +0x30
    int m_unk34;                        // +0x34
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_camera_eff_id;                // +0x40
    int m_unk44;                        // +0x44
    unsigned char m_pad48[0x40];
    int m_unk88;                        // +0x88
    unsigned char m_pad8C[0x40];
    unsigned int m_imd_load_chr_id[16]; // +0xCC
    int m_imd_load_chr_num;             // +0x10C
    char m_unk110[0x20];                // +0x110
    unsigned char m_pad130[0x80];
    unsigned char m_displayMessage[0x90]; // +0x1B0
    unsigned char m_seManager[0x308];     // +0x240
    unsigned char m_voiceManager[0x40];   // +0x548
};

#endif
