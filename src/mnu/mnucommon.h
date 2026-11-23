// mnu/mnucommon.h: Shared menu UI helper components embedded across mnu/* and unk/Mnu*:
//   MnuRpkEntry (0x018): RPK table entry
//   MnuSprElem  (0x154): Sprite/text element in MnuRpk::m_sprTbl
//   MnuRpk      (0x8EC): RPK/sprite manager (ctor func_0018BB8C, dtor func_0018BC18)
//   MnuMsgWin   (0x3BC): Message window (ctor func_0018330C, dtor func_00183B24)
//   MnuSub104   (0x104): Selection sub-menu (ctor func_001A066C, dtor func_001A0684,
//                        implemented in mnu/mnuselect.cpp and mnu/mnudlg.cpp)
#ifndef MNU_MNUCOMMON_H
#define MNU_MNUCOMMON_H

struct MnuRpkEntry {
    int m_id;                           // +0x00
    const char *m_name;                 // +0x04
    unsigned char m_pad08[0x10];        // +0x08..0x17
}; // size 0x18

struct MnuSprElem {
    int m_unk00;                        // +0x000
    int m_unk04;                        // +0x004
    int m_unk08;                        // +0x008
    int m_vis0C;                        // +0x00C
    int m_vis10;                        // +0x010
    int m_unk14;                        // +0x014
    int m_rgba[4];                      // +0x018..0x027
    unsigned char m_pad28[0x50];        // +0x028..0x077
    int m_pos[4];                       // +0x078..0x087
    unsigned char m_pad88[0x48];        // +0x088..0x0CF
    int m_unkD0;                        // +0x0D0
    int m_unkD4;                        // +0x0D4
    int m_iconId;                       // +0x0D8
    unsigned char m_padDC[0x68];        // +0x0DC..0x143
    int m_unk144;                       // +0x144
    int m_unk148;                       // +0x148
    char *m_text;                       // +0x14C
    void *m_color;                      // +0x150
}; // size 0x154

struct MnuRpk {
    int m_unk00;                        // +0x000
    int m_unk04;                        // +0x004
    unsigned char m_loader[0x414];      // +0x008 (passed to func_0018F744 / func_0018FEBC)
    int m_param;                        // +0x41C
    unsigned char m_pad420[0x8C];       // +0x420..0x4AB
    MnuSprElem *m_sprTbl;               // +0x4AC
    void *m_tbl;                        // +0x4B0
    unsigned char m_pad4B4[0x1C];       // +0x4B4..0x4CF
    int m_renderCtx;                    // +0x4D0
    unsigned char m_pad4D4[0x414];      // +0x4D4..0x8E7
    int m_unk8E8;                       // +0x8E8

    MnuRpk() asm("func_0018BB8C");
    ~MnuRpk() asm("func_0018BC18");

    inline void setUnk04(int v) { m_unk04 = v; }
    inline void setUnk8E8(int v) { m_unk8E8 = v; }
    inline void setTbl(void *p) { m_tbl = p; }
    inline void setRenderCtx(int v) { m_renderCtx = v; }
    inline void setSpr08(int idx, int v) { m_sprTbl[idx].m_unk08 = v; }
    inline void setSprVis0C(int idx, int v) { m_sprTbl[idx].m_vis0C = v; }
    inline void setSprVis10(int idx, int v) { m_sprTbl[idx].m_vis10 = v; }
    inline void setText(int idx, char *str) {
        m_sprTbl[idx].m_unk144 = 0x20;
        m_sprTbl[idx].m_unk148 = 0;
        m_sprTbl[idx].m_text = str;
    }
}; // size 0x8EC

struct MnuMsgWin {
    unsigned char m_data[0x3BC];

    MnuMsgWin() asm("func_0018330C");
    ~MnuMsgWin() asm("func_00183B24");
}; // size 0x3BC

struct MnuSub104Base {
    int m_open;                         // +0x000
}; // size 0x004

// Selection sub-menu (ctor func_001A066C, dtor func_001A0684, size 0x104)
struct MnuSub104 : public MnuSub104Base {
    int m_cursor[7];                    // +0x004..0x01F (rel +0x00)
    int m_max[3];                       // +0x020..0x02B (rel +0x1C)
    int m_pad2C[4];                     // +0x02C..0x03B
    int m_step;                         // +0x03C
    int m_mode;                         // +0x040
    int m_subStep;                      // +0x044
    int m_pad48[3];                     // +0x048..0x053
    int m_unk54;                        // +0x054
    int m_unk58;                        // +0x058
    int m_unk5C;                        // +0x05C
    int m_unk60;                        // +0x060
    int m_result;                       // +0x064
    int m_unk68;                        // +0x068
    int m_unk6C;                        // +0x06C
    int m_active;                       // +0x070
    unsigned char m_pad74[0x10];        // +0x074..0x083
    void *m_lines[32];                  // +0x084..0x103 (rel +0x80)
}; // size 0x104

typedef char MnuRpkEntry_size_check[sizeof(MnuRpkEntry) == 0x18 ? 1 : -1];
typedef char MnuSprElem_size_check[sizeof(MnuSprElem) == 0x154 ? 1 : -1];
typedef char MnuRpk_size_check[sizeof(MnuRpk) == 0x8EC ? 1 : -1];
typedef char MnuMsgWin_size_check[sizeof(MnuMsgWin) == 0x3BC ? 1 : -1];
typedef char MnuSub104_size_check[sizeof(MnuSub104) == 0x104 ? 1 : -1];

#endif
