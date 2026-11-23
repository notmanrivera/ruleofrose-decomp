// unk/EffMan.h: EffMan (effect manager, size >= 0x12C8), managing up to 0x110 Eff0
// instances (0x00..0xFF regular, 0x100..0x10F persistent/overflow), z-sort list,
// recycle queue, and 16 loaded effect resource entries ("data/eff/eff.bin").
#ifndef UNK_EFFMAN_H
#define UNK_EFFMAN_H

#include "unk/Eff0.h"

struct EffManEntry {
    int m_active;                       // +0x00
    char m_name[0x5C];                  // +0x04..+0x5F
}; // size 0x60

struct EffFileReadReq {
    int m_unk00;                        // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    const char *m_name;                 // +0x0C
    int m_offset;                       // +0x10
    int m_unk14;                        // +0x14
    void *m_buf;                        // +0x18 (+0x12BC in EffMan)
    int m_size;                         // +0x1C
    int m_unk20;                        // +0x20 (+0x12C4 in EffMan)
}; // size 0x24

struct EffMan {
    void *m_scene;                      // +0x0000
    Eff0 *m_ptrs[0x110];                // +0x0004..+0x0443
    int m_nextIdx;                      // +0x0444
    int m_activeCount;                  // +0x0448
    int m_sortList[0x110];              // +0x044C..+0x088B
    int m_queue[0x100];                 // +0x088C..+0x0C8B
    int m_queueCount;                   // +0x0C8C
    void *m_effBinBuf;                  // +0x0C90
    EffManEntry m_entries[16];          // +0x0C94..+0x1293
    int m_unk1294;                      // +0x1294
    int m_unk1298;                      // +0x1298
    int m_reader[2];                    // +0x129C..+0x12A3
    EffFileReadReq m_req;               // +0x12A4..+0x12C7
}; // size 0x12C8

typedef char EffManEntry_size_check[sizeof(EffManEntry) == 0x60 ? 1 : -1];
typedef char EffFileReadReq_size_check[sizeof(EffFileReadReq) == 0x24 ? 1 : -1];
typedef char EffMan_size_check[sizeof(EffMan) == 0x12C8 ? 1 : -1];

#endif
