// unk/mnuBase.h: shared base class MnuBase (RTTI "7mnuBase", size 0x110) and
// book/map menu subclasses MnuPBook (0x8BC) and MnuMap (0x8E0).
//
// Evidence:
// - Vtables _vt$7mnuBase (0x002E4640), _vt$6MnuMap (0x002E46A8),
//   _vt$8MnuPBook (0x002E4710), _vt$8MnuDiary (0x002E4778): 11 virtual slots
//   at +0x10C (vfunc01=dtor, vfunc02=init, vfunc03=term, vfunc04=isInit,
//   vfunc05=exec, vfunc06=draw, vfunc07=setupTex, vfunc08=getType,
//   vfunc09=getFlags, vfunc10=openRpk, vfunc11=closeRpk).
// - Layouts recovered from unk/mnuBase.cpp, unk/MnuPBook.cpp, unk/MnuDiary.cpp,
//   and tools/layouts.py.
#ifndef UNK_MNUBASE_H
#define UNK_MNUBASE_H

struct MnuResSlot {
    int m_unk00;                // +0x00
    int m_unk04;                // +0x04
    int m_type;                 // +0x08
    int m_slotIdx;              // +0x0C
    char m_name[0x20];          // +0x10
}; // size 0x30

struct MnuModelSlot {
    char *m_data;               // +0x00
    int m_unk04;                // +0x04
    int m_unk08;                // +0x08
    int m_unk0C;                // +0x0C
    int m_unk10;                // +0x10
    int m_pad14[3];             // +0x14
}; // size 0x20

struct MnuAnimSlot {
    int m_unk00;                // +0x00
    int m_len;                  // +0x04
    int m_unk08;                // +0x08
    int m_unk0C;                // +0x0C
}; // size 0x10

struct MnuTexSlot {
    int m_unk00;                // +0x00
    int m_unk04;                // +0x04
    int m_texId;                // +0x08
    int m_unk0C;                // +0x0C
}; // size 0x10

struct MnuBookPage {
    int m_flags;                // +0x00
    int m_leftTex;              // +0x04
    int m_rightTex;             // +0x08
    int m_animIdx;              // +0x0C
    int m_frame;                // +0x10
    int m_page;                 // +0x14
    int m_unk18;                // +0x18
    int m_unk1C;                // +0x1C
}; // size 0x20

struct MnuPBookInfo {
    int m_unk00;                // +0x00
    int m_msgBase;              // +0x04
    int m_pageCount;            // +0x08
    int m_flags0C;              // +0x0C
    char m_prefix[0x20];        // +0x10
}; // size 0x30

struct MnuMapEntry {
    int m_room;                 // +0x00
    int m_floor;                // +0x04
    char m_texPrefix[0x10];     // +0x08
    int m_tileCount;            // +0x18
    int m_unk1C;                // +0x1C
}; // size 0x20

struct MnuBase {
    int m_type;                         // +0x000
    int m_flags;                        // +0x004
    int m_scene;                        // +0x008
    int m_unk0C;                        // +0x00C
    int m_unk10;                        // +0x010
    int m_state;                        // +0x014
    MnuResSlot *m_resSlots;             // +0x018
    int m_resNum;                       // +0x01C
    int m_resUsed;                      // +0x020
    char m_rpkPath[0x40];               // +0x024
    void *m_readBuf;                    // +0x064
    unsigned char m_fileReader[0x08];   // +0x068 (FileReader)
    union {
        unsigned char m_fileReq[0x24];  // +0x070 (FileReadReq)
        struct {
            int m_reqFd;                // +0x070
            int m_reqState;             // +0x074
            int m_reqUnk08;             // +0x078
            char *m_reqPath;            // +0x07C
            int m_reqSeekOff;           // +0x080
            int m_reqSeekWhence;        // +0x084
            void *m_reqBuf;             // +0x088
            int m_reqSize;              // +0x08C
            int m_reqCloseFlag;         // +0x090
        };
    };
    MnuModelSlot *m_models;             // +0x094
    int m_unk98;                        // +0x098
    MnuAnimSlot *m_animSlots;           // +0x09C
    int m_unkA0;                        // +0x0A0
    MnuTexSlot *m_texSlots;             // +0x0A4
    int m_texSlotNum;                   // +0x0A8
    int m_unkAC;                        // +0x0AC
    int m_unkB0;                        // +0x0B0
    unsigned char m_padB4[0x0C];        // +0x0B4
    float m_camMat[4][4];               // +0x0C0..+0x0FF
    float m_projW;                      // +0x100
    float m_projH;                      // +0x104
    float m_savedFov;                   // +0x108
    virtual void vfunc01();             // +0x10C vtable (slot 1: dtor)
    virtual void vfunc02();             // slot 2
    virtual void vfunc03();             // slot 3
    virtual void vfunc04();             // slot 4 (isInit)
    virtual void vfunc05();             // slot 5
    virtual void vfunc06();             // slot 6
    virtual void vfunc07(int);          // slot 7 (setupTex)
    virtual void vfunc08();             // slot 8 (getType)
    virtual void vfunc09();             // slot 9 (getFlags)
    virtual void vfunc10();             // slot 10 (openRpk)
    virtual void vfunc11();             // slot 11 (closeRpk)
    MnuBase() asm("func_00192AC0");
}; // size 0x110

struct MnuPBook : public MnuBase {
    MnuPBookInfo *m_info;               // +0x110
    int m_unk114;                       // +0x114
    int m_unk118;                       // +0x118
    int m_unk11C;                       // +0x11C
    int m_unk120;                       // +0x120
    int m_unk124;                       // +0x124
    int m_curPage;                      // +0x128
    MnuBookPage *m_pages;               // +0x12C
    int m_pageNum;                      // +0x130
    int m_unk134;                       // +0x134
    int m_msgId;                        // +0x138
    char *m_textBuf;                    // +0x13C
    unsigned char m_msgWin[2 * 0x3BC];  // +0x140..+0x8B7
    int m_unk8B8;                       // +0x8B8

    void vfunc01();
    MnuPBook() asm("func_00196A9C");
}; // size 0x8BC

struct MnuMap : public MnuBase {
    MnuMapEntry *m_unk110;              // +0x110
    int m_unk114;                       // +0x114
    int m_unk118;                       // +0x118
    float m_unk11C;                     // +0x11C
    float m_unk120;                     // +0x120
    float m_unk124;                     // +0x124
    float m_unk128;                     // +0x128
    int m_unk12C;                       // +0x12C
    int m_unk130;                       // +0x130
    int m_unk134;                       // +0x134
    int m_unk138;                       // +0x138
    int m_unk13C;                       // +0x13C
    int m_unk140;                       // +0x140
    int m_unk144;                       // +0x144
    int m_unk148;                       // +0x148
    int m_unk14C;                       // +0x14C
    unsigned char m_msgWin[2 * 0x3BC];  // +0x150..+0x8C7
    MnuMapEntry *m_unk8C8;              // +0x8C8
    float m_unk8CC;                     // +0x8CC
    float m_unk8D0;                     // +0x8D0
    float m_unk8D4;                     // +0x8D4
    float m_unk8D8;                     // +0x8D8
    float m_unk8DC;                     // +0x8DC

    void vfunc01();
}; // size 0x8E0

typedef char MnuResSlot_size_check[sizeof(MnuResSlot) == 0x30 ? 1 : -1];
typedef char MnuModelSlot_size_check[sizeof(MnuModelSlot) == 0x20 ? 1 : -1];
typedef char MnuAnimSlot_size_check[sizeof(MnuAnimSlot) == 0x10 ? 1 : -1];
typedef char MnuTexSlot_size_check[sizeof(MnuTexSlot) == 0x10 ? 1 : -1];
typedef char MnuBookPage_size_check[sizeof(MnuBookPage) == 0x20 ? 1 : -1];
typedef char MnuPBookInfo_size_check[sizeof(MnuPBookInfo) == 0x30 ? 1 : -1];
typedef char MnuMapEntry_size_check[sizeof(MnuMapEntry) == 0x20 ? 1 : -1];
typedef char MnuBase_size_check[sizeof(MnuBase) == 0x110 ? 1 : -1];
typedef char MnuPBook_size_check[sizeof(MnuPBook) == 0x8BC ? 1 : -1];
typedef char MnuMap_size_check[sizeof(MnuMap) == 0x8E0 ? 1 : -1];

#endif
