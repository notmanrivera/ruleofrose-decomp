// mnu/mnudlg.h: MnuSub104 (0x1A0950..0x1A1243, sizeof 0x104),
// MnuMcd (0x1A1244..0x1A4BD7, memory card manager, sizeof 0x1400),
// and MnuDlgObj (0x1A4BD8..0x1A4E87, continues in mnu/mnusvld.cpp).
//
// Evidence:
// - Source filename literal "mnu/mnudlg.cpp" in func_001A4DB8 (BedMemory::alloc).
// - MnuMcd embeds a card sub-object at +0x00C0 (ctor func_00187724, dtor
//   func_00187738, size 0xAC0; dir count at +0x90, 0x40-byte entries at +0x1C0)
//   and two MnuMsgWin at +0x0B80..+0x12F7 (ctor func_0018330C, dtor func_00183B24).
// - MnuDlgObj embeds two MnuMsgWin at +0x0054..+0x07CB and calls func_001A4F60
//   / func_001A4D38 from its ctor/dtor (func_001A4BD8 / func_001A4C34).
#ifndef MNU_MNUDLG_H
#define MNU_MNUDLG_H

#include "mnu/mnucommon.h"

struct MnuMcdDirEnt {
    unsigned char m_pad00[0x10];        // +0x00
    int m_size;                         // +0x10 (+0x1D0 in MnuMcdCard)
    unsigned char m_pad14[0x0C];        // +0x14
    char m_name[0x20];                  // +0x20 (+0x1E0 in MnuMcdCard)
}; // size 0x40

struct MnuMcdCard {
    unsigned char m_pad00[0x90];        // +0x000
    int m_dirCount;                     // +0x090 (+0x150 in MnuMcd)
    unsigned char m_pad94[0x12C];       // +0x094..0x1BF
    MnuMcdDirEnt m_dir[36];             // +0x1C0..0xABF

    MnuMcdCard() asm("func_00187724");
    ~MnuMcdCard() asm("func_00187738");

    inline char *getName(int idx) {
        char *ret = 0;
        if (idx < m_dirCount) {
            ret = m_dir[idx].m_name;
        }
        return ret;
    }
    inline int getSize(int idx) {
        int ret = 0;
        if (idx < m_dirCount) {
            ret = m_dir[idx].m_size;
        }
        return ret;
    }
}; // size 0xAC0

struct MnuMcdBase1 {
    int m_open;                         // +0x0000
    int m_active;                       // +0x0004
    int m_cursor[7];                    // +0x0008..0x0023
    int m_step;                         // +0x0024
    int m_mode;                         // +0x0028
    int m_unk2C;                        // +0x002C
    int m_reqCmd;                       // +0x0030
    int m_subStep;                      // +0x0034
    int m_pad38[8];                     // +0x0038..0x0057
    int m_sys;                          // +0x0058
    int m_pad5C[4];                     // +0x005C..0x006B
    int m_unk6C;                        // +0x006C
    int m_unk70;                        // +0x0070
    int m_port;                         // +0x0074
    int m_portState[2];                 // +0x0078..0x007F
    int m_pad80[2];                     // +0x0080..0x0087
    int m_unk88;                        // +0x0088
    int m_unk8C;                        // +0x008C
    int m_reqOp;                        // +0x0090
    unsigned char m_pad94[0x2C];        // +0x0094..0x00BF
    MnuMcdCard m_card;                  // +0x00C0..0x0B7F
    inline ~MnuMcdBase1() {}
}; // size 0x0B80

struct MnuMcdBase2 {
    MnuMsgWin m_msgWin[2];           // +0x0000..0x0777 (at +0x0B80 in MnuMcd)
    inline ~MnuMcdBase2() {}
}; // size 0x0778

struct MnuMcd : public MnuMcdBase1, public MnuMcdBase2 {
    int m_pad12F8[2];                   // +0x12F8..0x12FF
    int m_winId0;                       // +0x1300
    int m_winId1;                       // +0x1304
    int m_saveSize;                     // +0x1308
    int m_saveBuf;                      // +0x130C
    char m_dirName[0x40];               // +0x1310..0x134F
    char m_fileName[0x40];              // +0x1350..0x138F
    int m_result;                       // +0x1390
    int m_pad1394[6];                   // +0x1394..0x13AB
    int m_statusFlags;                  // +0x13AC
    int m_slotState;                    // +0x13B0
    int m_subState;                     // +0x13B4
    int m_unk13B8;                      // +0x13B8
    int m_busy;                         // +0x13BC
    unsigned char m_pad13C0[0x40];      // +0x13C0..0x13FF

    MnuMcd() asm("func_001A1244");
    ~MnuMcd() asm("func_001A12A8");
}; // size 0x1400

struct MnuDlgObjBase1 {
    int m_open;                         // +0x000
    unsigned char m_pad04[0x38];        // +0x004..0x03B
    int m_step;                         // +0x03C
    int m_mode;                         // +0x040
    int m_subStep;                      // +0x044
    int m_pad48[3];                     // +0x048..0x053
    inline ~MnuDlgObjBase1() {}
}; // size 0x054

struct MnuDlgObjBase2 {
    MnuMsgWin m_msgWin[2];           // +0x000..0x777 (at +0x054 in MnuDlgObj)
    inline ~MnuDlgObjBase2() {}
}; // size 0x778

struct MnuDlgObj : public MnuDlgObjBase1, public MnuDlgObjBase2 {
    int m_sys;                          // +0x7CC
    int m_winId;                        // +0x7D0
    int m_result;                       // +0x7D4
    int m_active;                       // +0x7D8
    int m_arg3;                         // +0x7DC
    int m_arg4;                         // +0x7E0
    int m_arg5;                         // +0x7E4
    int m_arg6;                         // +0x7E8
    int m_pad7EC[2];                    // +0x7EC..0x7F3
    char *m_titleLines[16];             // +0x7F4..0x833
    char *m_bodyLines[16];              // +0x834..0x873

    MnuDlgObj() asm("func_001A4BD8");
    ~MnuDlgObj() asm("func_001A4C34");
}; // size 0x874

typedef char MnuMcd_size_check[sizeof(MnuMcd) == 0x1400 ? 1 : -1];
typedef char MnuDlgObj_size_check[sizeof(MnuDlgObj) == 0x874 ? 1 : -1];

#endif
