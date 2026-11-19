#ifndef UNK_001A6830_H
#define UNK_001A6830_H

// Menu classes implemented in unk/001A6830.cpp (embedded at +0x40 in MagLifeMenu*):
//   MnuTitle (0x1A90EC..0x1AB473) — MagLifeMenuTitle
//   MnuOpt   (0x1AB474..0x1AD6B3) — MagLifeMenuOpt
//   MnuBoard (0x1AD6B4..0x1ADF03) — board viewer
//   MnuMovie (0x1ADF04..0x1AE473) — MagLifeMenuMovie
//   MnuNow   (0x1AE474..0x1AE867) — MagLifeMenuNow
//   MnuItem  (0x1AE868..0x1B64C3) — MagLifeMenuItem

struct MnuRpkEntry {
    int m_id;
    const char *m_name;
    unsigned char m_pad08[0x10];
}; // size 0x18

struct MnuBoardTblEnt {
    int m_key;
    int m_val;
}; // size 0x08

struct MnuItemStockEnt {
    unsigned char m_pad00[0x08];
    unsigned short m_itemId;            // +0x08
    unsigned short m_count;             // +0x0A
    unsigned char m_pad0C[0x04];
}; // size 0x10

// Shared RPK/sprite manager (ctor func_0018BB8C, dtor func_0018BC18, size 0x8EC)
struct MnuRpk {
    int m_unk00;                        // +0x000
    int m_unk04;                        // +0x004
    unsigned char m_loader[0x414];      // +0x008 (passed to func_0018F744 / func_0018FEBC)
    int m_param;                        // +0x41C
    unsigned char m_pad420[0x90];       // +0x420
    void *m_tbl;                        // +0x4B0
    unsigned char m_pad4B4[0x1C];       // +0x4B4
    int m_renderCtx;                    // +0x4D0
    unsigned char m_pad4D4[0x414];      // +0x4D4
    int m_unk8E8;                       // +0x8E8
}; // size 0x8EC

// Shared message window (ctor func_0018330C, dtor func_00183B24, size 0x3BC)
struct MnuMsgWin {
    unsigned char m_data[0x3BC];
}; // size 0x3BC

// Shared sub-object (ctor func_001A066C, dtor func_001A0684, size 0x104)
struct MnuSub104 {
    unsigned char m_data[0x104];
}; // size 0x104

// Embedded MnuMcd (ctor func_001A1244, dtor func_001A12A8, size 0x1400)
struct MnuMcdStub {
    unsigned char m_data[0x1400];
}; // size 0x1400

// Embedded MnuSvld (ctor func_001A59B8, dtor func_001A5A34, size 0x2780)
struct MnuSvldStub {
    unsigned char m_pad00[0x24E8];      // +0x0000
    int m_unk24E8;                      // +0x24E8
    unsigned char m_pad24EC[0x268];     // +0x24EC
    int m_result;                       // +0x2754
    int getResult() { return m_result; }
    unsigned char m_pad2758[0x28];      // +0x2758
}; // size 0x2780

// Option menu (MagLifeMenuOpt + 0x40, size 0x10E8)
struct MnuOpt {
    int m_open;                         // +0x0000
    int m_cursor[8];                    // +0x0004..0x0023
    int m_max[7];                       // +0x0024..0x003F
    int m_unk40;                        // +0x0040
    int m_step0;                        // +0x0044
    int m_mode;                         // +0x0048
    int m_subStep;                      // +0x004C
    int m_unk50;                        // +0x0050
    int m_unk54;                        // +0x0054
    MnuMsgWin m_msgWin[2];              // +0x0058..0x07CF
    MnuRpk m_rpk;                       // +0x07D0..0x10BB
    int m_sys;                          // +0x10BC
    int m_renderCtx;                    // +0x10C0
    int m_unk10C4;                      // +0x10C4
    int m_scene;                        // +0x10C8
    int m_active;                       // +0x10CC
    unsigned char m_pad10D0[0x10];      // +0x10D0
    int m_winId;                        // +0x10E0
    int m_unk10E4;                      // +0x10E4
}; // size 0x10E8

// Title menu (MagLifeMenuTitle + 0x40, size 0x56F8)
struct MnuTitle {
    MnuMcdStub m_mcd;                   // +0x0000..0x13FF
    MnuSvldStub m_svld;                 // +0x1400..0x3B7F
    MnuOpt m_opt;                       // +0x3B80..0x4C67
    MnuSub104 m_sub4C68;                // +0x4C68..0x4D6B
    int m_open;                         // +0x4D6C
    int m_cursor[9];                    // +0x4D70..0x4D93
    int m_max[3];                       // +0x4D94..0x4D9F
    unsigned char m_pad4DA0[0x18];      // +0x4DA0
    int m_unk4DB8;                      // +0x4DB8
    unsigned char m_pad4DBC[0x08];      // +0x4DBC
    int m_step0;                        // +0x4DC4
    int m_mode;                         // +0x4DC8
    int m_subStep;                      // +0x4DCC
    unsigned char m_pad4DD0[0x1C];      // +0x4DD0
    int m_unk4DEC;                      // +0x4DEC
    MnuRpk m_rpk;                       // +0x4DF0..0x56DB
    int m_sys;                          // +0x56DC
    int m_renderCtx;                    // +0x56E0
    int m_param;                        // +0x56E4
    unsigned char m_pad56E8[0x08];      // +0x56E8
    int m_scene;                        // +0x56F0
    int m_active;                       // +0x56F4
}; // size 0x56F8

// Board viewer menu (0x1AD6B4..0x1ADF03)
struct MnuBoard {
    MnuMsgWin m_msgWin[2];              // +0x0000..0x0777
    int m_open;                         // +0x0778
    int m_cursor[2];                    // +0x077C..0x0783
    int m_max0;                         // +0x0784
    int m_unk788;                       // +0x0788
    int m_step0;                        // +0x078C
    int m_mode;                         // +0x0790
    int m_subStep;                      // +0x0794
    unsigned char m_pad798[0x08];       // +0x0798
    int m_unk7A0;                       // +0x07A0
    MnuRpk m_rpk;                       // +0x07A4..0x108F
    int m_sys;                          // +0x1090
    int m_renderCtx;                    // +0x1094
    int m_unk1098;                      // +0x1098
    int m_skipClose;                    // +0x109C
    unsigned char m_pad10A0[0x14];      // +0x10A0
    int m_active;                       // +0x10B4
    int m_unk10B8;                      // +0x10B8
}; // size 0x10BC

// Movie menu (MagLifeMenuMovie + 0x40)
struct MnuMovie {
    int m_open;                         // +0x0000
    int m_cursor[7];                    // +0x0004..0x001F
    int m_max[3];                       // +0x0020..0x002B
    unsigned char m_pad2C[0x10];        // +0x002C
    int m_step0;                        // +0x003C
    int m_mode;                         // +0x0040
    int m_subStep;                      // +0x0044
    unsigned char m_pad48[0x08];        // +0x0048
    int m_unk50;                        // +0x0050
    MnuRpk m_rpk;                       // +0x0054..0x093F
    int m_sys;                          // +0x0940
    unsigned char m_pad944[0x24];       // +0x0944
    int m_scene;                        // +0x0968
    int m_unk96C;                       // +0x096C
    int m_active;                       // +0x0970
}; // size 0x0974

// Now Loading menu (MagLifeMenuNow + 0x40)
struct MnuNow {
    int m_open;                         // +0x0000
    int m_step0;                        // +0x0004
    int m_mode;                         // +0x0008
    int m_subStep;                      // +0x000C
    int m_unk10;                        // +0x0010
    MnuRpk m_rpk;                       // +0x0014..0x08FF
    int m_sys;                          // +0x0900
    int m_renderCtx;                    // +0x0904
    int m_unk908;                       // +0x0908
    int m_scene;                        // +0x090C
    int m_active;                       // +0x0910
}; // size 0x0914

// Item menu (MagLifeMenuItem + 0x40)
struct MnuItem {
    int m_open;                         // +0x0000
    int m_cursor[10];                   // +0x0004..0x002B
    int m_max[3];                       // +0x002C..0x0037
    unsigned char m_pad38[0x60];        // +0x0038
    MnuRpk m_rpk[3];                    // +0x0098..0x1B5B (0x98, 0x984, 0x1270)
    int m_unk1B5C;                      // +0x1B5C
    int m_scene;                        // +0x1B60
    MnuSub104 m_sub1B64;                // +0x1B64..0x1C67
    MnuMsgWin m_msgWin[2];              // +0x1C68..0x23DF
    int m_param;                        // +0x23E0
    unsigned char m_pad23E4[0x28];      // +0x23E4
    int m_canMap;                       // +0x240C
    int m_canOpt;                       // +0x2410
    int m_canDog;                       // +0x2414
    int m_canOpt2;                      // +0x2418
    int m_canDog2;                      // +0x241C
    int m_unk2420;                      // +0x2420
    int m_equipIdx;                     // +0x2424
    int m_weaponIdx;                    // +0x2428
    int m_weaponId;                     // +0x242C
    int m_subItemId;                    // +0x2430
    MnuItemStockEnt *m_slots[12];       // +0x2434..0x2463
    unsigned char m_pad2464[0x1C];      // +0x2464
    int m_active;                       // +0x2480
    unsigned char m_pad2484[0x0C];      // +0x2484
    int m_unk2490;                      // +0x2490
    unsigned char m_pad2494[0x08];      // +0x2494
    int m_unk249C;                      // +0x249C
    int m_unk24A0;                      // +0x24A0
    unsigned char m_pad24A4[0x25C];     // +0x24A4
    int m_winId;                        // +0x2700
}; // size 0x2704

#endif
