// unk/MnuDiary.h: MnuPBook (0x198318..0x19871F), MnuDiary (0x198720..0x19A52B),
// and MnuStock (0x19A52C..0x1A066B, item stock / trash box menu).
//
// Evidence:
// - RTTI strings "8MnuPBook" (D_002F8190) and "8MnuDiary" (D_002F82C8),
//   vtable _vt$8MnuDiary (0x002E4778), and linkonce methods:
//   - MnuDiary::getPaperByPage(int page) -> (page + 1) / 2 - 1
//   - MnuDiary::getPageByPaper(int paper) -> paper * 2 + 1
// - MnuStock ("texstock.tm2" D_002F8300) embeds 2 MnuMsgWin (+0x58),
//   MnuRpk (+0x7D0), and GamItem* tables at +0x1110 and +0x1510.
// - Layouts recovered from the matched and asm functions in unk/MnuDiary.cpp.
#ifndef UNK_MNUDIARY_H
#define UNK_MNUDIARY_H

#include "game/gamman.h"

struct MnuModelSlot {
    char *m_data;               // +0x00
    int m_pad[7];               // +0x04
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

struct MnuDiaryInfo {
    int m_id;                   // +0x00 (-1 terminates D_0029C368)
    int m_msgBase;              // +0x04
    int m_pageCount;            // +0x08
    char m_prefix[0x24];        // +0x0C
}; // size 0x30

struct MnuPBookInfo {
    int m_unk00;                // +0x00
    int m_msgBase;              // +0x04
    int m_pageCount;            // +0x08
};

struct MnuMsgWinCtor {
    unsigned char m_unk[0x3BC];
    MnuMsgWinCtor() asm("func_0018330C");
}; // size 0x3BC

struct MnuBase {
    int m_type;                         // +0x000
    int m_flags;                        // +0x004
    int m_scene;                        // +0x008
    unsigned char m_pad0C[0x08];        // +0x00C
    int m_state;                        // +0x014
    unsigned char m_pad18[0x0C];        // +0x018
    char m_rpkPath[0x40];               // +0x024
    unsigned char m_pad64[0x30];        // +0x064
    MnuModelSlot *m_models;             // +0x094
    int m_unk98;                        // +0x098
    MnuAnimSlot *m_animSlots;           // +0x09C
    int m_unkA0;                        // +0x0A0
    MnuTexSlot *m_texSlots;             // +0x0A4
    int m_texSlotNum;                   // +0x0A8
    int m_unkAC;                        // +0x0AC
    unsigned char m_padB0[0x5C];        // +0x0B0
    virtual void vfunc01();             // +0x10C vtable
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc10();
    MnuBase() asm("func_00192AC0");
}; // size 0x110

struct MnuPBook : public MnuBase {
    MnuPBookInfo *m_info;               // +0x110
    unsigned char m_pad114[0x14];       // +0x114
    int m_curPage;                      // +0x128
    MnuBookPage *m_pages;               // +0x12C
    int m_pageNum;                      // +0x130
    int m_unk134;                       // +0x134
    int m_msgId;                        // +0x138
    char *m_textBuf;                    // +0x13C
    unsigned char m_msgWin[0x3BC];      // +0x140
};

struct MnuDiary : public MnuBase {
    MnuDiaryInfo *m_info;               // +0x110
    int m_diaryId;                      // +0x114
    int m_unk118;                       // +0x118
    int m_unk11C;                       // +0x11C
    int m_unk120;                       // +0x120
    int m_curPage;                      // +0x124
    MnuBookPage *m_slots;               // +0x128 (5 entries)
    int m_paperNum;                     // +0x12C
    int m_unk130;                       // +0x130
    int m_msgId;                        // +0x134
    char *m_textBuf;                    // +0x138 (0x4C8 bytes)
    unsigned char m_msgs[2 * 0x3BC];    // +0x13C..+0x8B3
    int m_unk8B4;                       // +0x8B4
    int *m_texPageMap;                  // +0x8B8 (19 ints)

    void vfunc01();
    MnuDiary() asm("func_00198720");

    int getPaperByPage(int page) { return (page + 1) / 2 - 1; }
    int getPageByPaper(int paper) { return paper * 2 + 1; }
}; // size 0x8BC

struct MnuStockSprElem {
    unsigned char m_unk00[0x144];       // +0x000
    int m_unk144;                       // +0x144
    int m_unk148;                       // +0x148
    char *m_text;                       // +0x14C
    void *m_color;                      // +0x150
}; // size 0x154

struct MnuStockRpk {
    unsigned char m_unk000[0x41C];      // +0x000
    int m_param;                        // +0x41C
    unsigned char m_unk420[0x8C];       // +0x420
    MnuStockSprElem *m_sprTbl;          // +0x4AC
    unsigned char m_unk4B0[0x20];       // +0x4B0
    int m_renderCtx;                    // +0x4D0
    unsigned char m_unk4D4[0x418];      // +0x4D4

    inline void setText(int idx, char *str) {
        m_sprTbl[idx].m_unk144 = 0x20;
        m_sprTbl[idx].m_unk148 = 0;
        m_sprTbl[idx].m_text = str;
    }
}; // size 0x8EC

struct MnuStockCursor {
    int m_pos;
    inline void snapRowStart() {
        int v = m_pos;
        if (v >= 0 && v <= 3) {
            m_pos = 0;
        } else if (v >= 4 && v <= 7) {
            m_pos = 4;
        } else if (v >= 8 && v <= 11) {
            m_pos = 8;
        }
    }
    inline void snapRowEnd() {
        int v = m_pos;
        if (v >= 0 && v <= 3) {
            m_pos = 3;
        } else if (v >= 4 && v <= 7) {
            m_pos = 7;
        } else if (v >= 8 && v <= 11) {
            m_pos = 11;
        }
    }
};

struct MnuStock {
    int m_open;                         // +0x0000
    int m_cursor[7];                    // +0x0004..+0x001F ([0]=+0x04,[1]=+0x08,[2]=+0x0C,[3]=+0x10)
    int m_max[3];                       // +0x0020..+0x002B (7, 8, 2)
    int m_stockCount;                   // +0x002C
    int m_pad30[3];                     // +0x0030
    int m_unk3C;                        // +0x003C
    int m_unk40;                        // +0x0040
    int m_unk44;                        // +0x0044
    int m_pad48[3];                     // +0x0048
    int m_unk54;                        // +0x0054
    unsigned char m_msgs[2 * 0x3BC];    // +0x0058..+0x07CF
    MnuStockRpk m_rpk;                  // +0x07D0..+0x10BB
    char *m_magSys;                     // +0x10BC
    int m_renderCtx;                    // +0x10C0
    unsigned char m_pad10C4[0x4C];      // +0x10C4
    GamItem *m_stockItems[0x100];       // +0x1110..+0x150F
    GamItem *m_haveItems[0xC];          // +0x1510..+0x153F
    int m_active;                       // +0x1540
    int m_listCount;                    // +0x1544
    int m_unk1548;                      // +0x1548
    int m_equipIdx;                     // +0x154C
    int m_findIdx;                      // +0x1550
    int m_pad1554[3];                   // +0x1554
    int m_flg4;                         // +0x1560
    int m_flg2A;                        // +0x1564
    int m_flg1A;                        // +0x1568
    int m_flg2B;                        // +0x156C
    int m_flg1B;                        // +0x1570
    int m_unk1574;                      // +0x1574
    int m_unk1578;                      // +0x1578
    int m_timer;                        // +0x157C
    unsigned int m_unk1580;             // +0x1580
};

#endif
