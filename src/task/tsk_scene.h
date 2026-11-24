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

#endif
