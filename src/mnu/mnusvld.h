// mnu/mnusvld.h: MnuDlg (0x1A4BD8..0x1A59B7, split across mnudlg/mnusvld)
// and MnuSvld (0x1A59B8..0x1A90EC, memory-card save/load menu, sizeof 0x2780).
//
// Evidence:
// - MnuSvld embeds MnuMcd (+0x0000, ctor func_001A1244, dtor func_001A12A8,
//   size 0x1400), MnuRpk (+0x1474, ctor func_0018BB8C, dtor func_0018BC18,
//   size 0x8EC), and MnuMsgWin[2] (+0x1D68, ctor func_0018330C, dtor func_00183B24).
// - 12 save slot metadata entries of stride 0x2C at +0x2508..+0x2717.
// - Source filename string D_002F91E8 ("mnu/mnusvld.cpp") used in BedMemory::alloc
//   and assertion checks in func_001A5AF4, func_001A6764, func_001A67D8.
#ifndef MNU_MNUSVLD_H
#define MNU_MNUSVLD_H

#include "mnu/mnudlg.h"

struct MnuDlgBase {
    int m_open;                         // +0x000
}; // size 0x004

struct MnuDlg : public MnuDlgBase {
    int m_cursor[7];                    // +0x004..0x01F (rel +0x000)
    int m_max[3];                       // +0x020..0x02B (titleCount, bodyCount, max2)
    int m_pad2C[4];                     // +0x02C..0x03B
    int m_step;                         // +0x03C
    int m_mode;                         // +0x040
    int m_subStep;                      // +0x044
    int m_pad48[3];                     // +0x048..0x053
    unsigned char m_msgWin[2 * 0x3BC];  // +0x054..0x7CB
    int m_sys;                          // +0x7CC
    int m_winId;                        // +0x7D0
    int m_result;                       // +0x7D4
    int m_active;                       // +0x7D8
    int m_arg3;                         // +0x7DC
    int m_arg4;                         // +0x7E0
    int m_arg5;                         // +0x7E4
    int m_arg6;                         // +0x7E8
    int m_pad7EC[2];                    // +0x7EC..0x7F3
    char *m_titleLines[16];             // +0x7F4..0x833 (rel +0x7F0)
    char *m_bodyLines[16];              // +0x834..0x873 (rel +0x830)
}; // size 0x874

struct MnuSvldSlot {
    int m_status;                       // +0x00 (-1 empty, 0 valid, 1 corrupted)
    int m_clearFlg;                     // +0x04
    int m_chapter;                      // +0x08
    int m_hours;                        // +0x0C
    int m_minutes;                      // +0x10
    int m_year;                         // +0x14
    int m_month;                        // +0x18
    int m_day;                          // +0x1C
    int m_hour;                         // +0x20
    int m_min;                          // +0x24
    int m_sec;                          // +0x28
}; // size 0x2C

struct MnuSvldBase1 {
    MnuMcd m_mcd;                       // +0x0000..0x13FF
    int m_open;                         // +0x1400
    int m_cursor[9];                    // +0x1404..0x1427
    int m_unk1428;                      // +0x1428
    int m_slotMax;                      // +0x142C (12)
    int m_visMax;                       // +0x1430 (5)
    int m_pad1434[5];                   // +0x1434..0x1447
    int m_gridMax;                      // +0x1448 (36)
    int m_step;                         // +0x144C
    int m_mode;                         // +0x1450
    int m_subStep;                      // +0x1454
    int m_pad1458[6];                   // +0x1458..0x146F
    int m_unk1470;                      // +0x1470
    MnuRpk m_rpk;                       // +0x1474..0x1D5F
    int m_sys;                          // +0x1D60
    int m_renderCtx;                    // +0x1D64
    inline ~MnuSvldBase1() {}
}; // size 0x1D68

struct MnuSvldBase2 {
    MnuMsgWin m_msgWin[2];              // +0x0000..0x0777 (at +0x1D68 in MnuSvld)
    inline ~MnuSvldBase2() {}
}; // size 0x778

struct MnuSvld : public MnuSvldBase1, public MnuSvldBase2 {
    int m_mcdRes;                       // +0x24E0
    int m_unk24E4;                      // +0x24E4
    int m_isLoad;                       // +0x24E8
    int m_unk24EC;                      // +0x24EC
    int m_unk24F0;                      // +0x24F0
    int m_unk24F4;                      // +0x24F4
    int m_unk24F8;                      // +0x24F8
    int m_unk24FC;                      // +0x24FC
    int m_unk2500;                      // +0x2500
    int m_unk2504;                      // +0x2504
    MnuSvldSlot m_slots[12];            // +0x2508..0x2717
    unsigned char m_pad2718[0x1C];      // +0x2718..0x2733
    int m_active;                       // +0x2734
    int m_pad2738[2];                   // +0x2738..0x273F
    void *m_saveBuf;                    // +0x2740
    int m_winId;                        // +0x2744
    int m_winShown;                     // +0x2748
    int m_doneFlag;                     // +0x274C
    int m_unk2750;                      // +0x2750
    int m_result;                       // +0x2754
    unsigned char m_pad2758[0x28];      // +0x2758..0x277F

    MnuSvld() asm("func_001A59B8");
    ~MnuSvld() asm("func_001A5A34");

    inline int getResult() { return m_result; }
}; // size 0x2780

typedef char MnuSvld_size_check[sizeof(MnuSvld) == 0x2780 ? 1 : -1];

#endif
