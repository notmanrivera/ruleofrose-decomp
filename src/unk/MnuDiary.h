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

#include "unk/mnuBase.h"
#include "mnu/mnucommon.h"
#include "game/gamman.h"

struct MnuDiaryInfo {
    int m_id;                   // +0x00 (-1 terminates D_0029C368)
    int m_msgBase;              // +0x04
    int m_pageCount;            // +0x08
    char m_prefix[0x24];        // +0x0C
}; // size 0x30

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
    MnuRpk m_rpk;                       // +0x07D0..+0x10BB
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
