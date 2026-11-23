#include "include_asm.h"
#include "unk/MnuDiary.h"
#include <sdk/string.h>
struct DiaryRGB { signed char r,g,b; };
extern "C" int diaryAttach(int,int,int,int) asm("func_001874F4");
extern "C" int Xiii_func_001874F4(int, int) asm("func_001874F4");
extern "C" int Xiii_func_0019A3C0(int, int) asm("func_0019A3C0");
extern "C" int Xiiii_func_001C51E0(int, int, int) asm("func_001C51E0");
extern "C" int Xiiiii_func_001C5094(int, int, int, int) asm("func_001C5094");
extern "C" int Xiiiii_func_001C5168(int, int, int, int) asm("func_001C5168");
extern "C" int Xiiiiii_func_00134730(int, int, int, int, int) asm("func_00134730");
extern "C" int Xiiui_func_001351B0(int, unsigned int, int) asm("func_001351B0");
extern "C" int Xiiui_func_00135418(int, unsigned int, int) asm("func_00135418");
extern "C" int Xiiui_func_00135494(int, unsigned int, int) asm("func_00135494");
extern "C" int Xiiuii_func_00134AB8(int, unsigned int, int, int) asm("func_00134AB8");
extern "C" int Xiiuiii_func_00134A00(int, unsigned int, int, int, int) asm("func_00134A00");
extern "C" int Xiiuiiii_func_00134CD0(int, unsigned int, int, int, int, int) asm("func_00134CD0");
extern "C" int Xiu_func_001832E8(unsigned int) asm("func_001832E8");
struct SysWork_v2 {
    unsigned char unk[0xDC1C];
    int *m_dc1c;
};
extern int D_007812C0_v2 asm("D_007812C0");
extern SysWork_v2 D_007A4440_v2 asm("D_007A4440");
static inline int *sysWork_v2() { return D_007A4440_v2.m_dc1c; }
extern "C" void X_func_00192BA4_v2(void *, int, int, int, int, int) asm("func_00192BA4");
extern "C" int X_func_001D83D0_v2(void *, int, int, int) asm("func_001D83D0");
extern "C" void *X_func_00194588_v2(int) asm("func_00194588");
extern "C" void *X_memset_v2(void *, int, int) asm("memset");
extern "C" void X_func_0019397C_v2(void *, const char *, int, int) asm("func_0019397C");
extern int D_007812C0_BEB0 asm("D_007812C0");
extern "C" int X_func_001C9198_BEB0(void *, GamItem) asm("func_001C9198");
extern "C" void X_func_001C8214_BEB0(void *, int) asm("func_001C8214");
extern "C" void X_func_001C94D8_BEB0(void *, int, int) asm("func_001C94D8");
extern "C" void X_func_001C812C_BEB0(void *, int, GamItem *) asm("func_001C812C");
extern "C" void X_func_0019B020_BEB0(void *, int) asm("func_0019B020");
extern "C" void X_func_0019B384_BEB0(void *, int) asm("func_0019B384");
extern "C" void X_func_0019BD6C_BEB0(void *) asm("func_0019BD6C");
extern "C" {
void *X_memset_85B0(void *, int, int) asm("memset");
int X_strlen_85B0(const char *) asm("strlen");
void *X_memcpy_85B0(void *, const void *, int) asm("memcpy");
char *X_func_001832E8_85B0(int) asm("func_001832E8");
void X_func_001874F4_85B0(void *, int, char *, int) asm("func_001874F4");
}
extern "C" void *X_memset_A3C0(void *, int, unsigned int) asm("memset");
extern "C" void *X_memcpy_A3C0(void *, const void *, unsigned int) asm("memcpy");
extern "C" unsigned int X_strlen_A3C0(const char *) asm("strlen");
extern "C" int X_strcmp_A3C0(const char *, const char *) asm("strcmp");
extern "C" char *X_func_001832E8_A3C0(int) asm("func_001832E8");
extern "C" void X_func_001874F4_A3C0(void *, int, char *, int) asm("func_001874F4");
extern "C" char D_002F8228[];
extern "C" int X_func_00279C98_844C(char *, const char *, int) asm("func_00279C98");
extern "C" int X_func_00194404_844C(void *, int, int) asm("func_00194404");
extern "C" void X_func_0019397C_844C(void *, char *, int, int) asm("func_0019397C");
extern "C" int X_func_00279C98_A290(char *, const char *, int) asm("func_00279C98");
extern "C" int X_func_0019A24C_A290(void *, int) asm("func_0019A24C");
extern "C" int X_func_00194404_A290(void *, int, int) asm("func_00194404");
extern "C" int X_func_0019397C_A290(void *, char *, int, int) asm("func_0019397C");
extern int D_002A42C0;
extern int D_007812C0_DBC8 asm("D_007812C0");
extern "C" void X_func_001DC48C_DBC8(void *, int, int, void *) asm("func_001DC48C");
static inline void *gamSub22220_DBC8() { void *p = &D_007812C0_DBC8; return (char *)p + 0x22220; }
extern "C" void X_func_00194688_v3(void *) asm("func_00194688");
extern "C" void X_func_00193868_v3(void *) asm("func_00193868");
extern "C" void X_func_001348B0_v3(int, int) asm("func_001348B0");
extern "C" void X_func_00187464_v3(void *) asm("func_00187464");
extern "C" void X_mnuBase__vfunc_03_v3(void *) asm("mnuBase__vfunc_03");
extern "C" void X_MnuDiary__vfunc_03_v1(void *) asm("MnuDiary__vfunc_03");
extern "C" void X___builtin_delete_v1(void *) asm("__builtin_delete");
extern "C" void X_func_00183B24_v1(void *, int) asm("func_00183B24");
extern "C" void X_mnuBase__vfunc_01_v1(void *, int) asm("mnuBase__vfunc_01");
extern int vtbl_MnuDiary_v1 asm("_vt$8MnuDiary");
extern "C" int X_func_0019A20C_9A08(void *, int) asm("func_0019A20C");
extern "C" int X_func_001DD00C_DEDC(void *, int, int) asm("func_001DD00C");
extern "C" void X_func_001DC48C_DEDC(void *, int, int, void *) asm("func_001DC48C");
extern int D_007812C0_DEDC asm("D_007812C0");
extern char *D_002A42E0;
extern char D_002F84B8[];
static inline void *gamSub22220_DEDC() { void *p = &D_007812C0_DEDC; return (char *)p + 0x22220; }
extern "C" int Xii_func_00131550(int) asm("func_00131550");
extern "C" int Xii_func_001874AC(int) asm("func_001874AC");
extern "C" int Xii_func_0018C068(int) asm("func_0018C068");
struct MagGameFlags_CEAC {
    int m_unk00;
    int m_flags;
};
extern MagGameFlags_CEAC *D_007B2060_CEAC asm("D_007B2060");
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" void X_func_0019B384_C0E4(void *, int) asm("func_0019B384");
extern "C" int func_0019C048(MnuStock *, int);
extern "C" void func_0019B020(MnuStock *, int);
struct UnkHdr_9AB4 {
    int unk00;
    int unk04;
    unsigned short unk08;
};
struct UnkItem_9AB4 {
    int pad[7];
    int unk1C;
};
extern "C" int X_func_0019A24C_9AB4(void *, int) asm("func_0019A24C");
extern "C" UnkHdr_9AB4 **X_func_0022AED8_9AB4(void *, int) asm("func_0022AED8");
extern "C" UnkItem_9AB4 **func_0022AAD0(UnkHdr_9AB4 **, int);
struct Arg223558_v7 {
    int unk00;
    void *unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
extern "C" int X_func_00223558_v7(int, Arg223558_v7 *) asm("func_00223558");
extern "C" void X_func_00223228_v7(int, int) asm("func_00223228");
extern "C" void Xvp_func_0019A6B8(void *) asm("func_0019A6B8");
extern "C" void Xvp_func_0019A7D8(void *) asm("func_0019A7D8");
struct Msg_9A598 {
    unsigned char m_unk[0x3BC];
    ~Msg_9A598() asm("func_00183B24");
};
struct Spr_9A598 {
    unsigned char m_unk[0xD70];
    ~Spr_9A598() asm("func_0018BC18");
};
struct Pad_9A598 {
    unsigned char m_pad[0x58];
};
struct Base_9A598 {
    Msg_9A598 m_msg[2];
    inline ~Base_9A598() {}
};
struct Obj_9A598 : public Pad_9A598, public Base_9A598 {
    Spr_9A598 m_spr;
    int m_1540;
    ~Obj_9A598() asm("func_0019A598");
};
extern "C" void X_func_001DC48C(void *, int, int, void *) asm("func_001DC48C");
extern "C" int Xii_func_0019A780(int) asm("func_0019A780");
extern "C" int Xiii_func_0018BCC0(int, int) asm("func_0018BCC0");
extern "C" int Xii_func_0018741C(int) asm("func_0018741C");
extern "C" int Xii_func_00187464(int) asm("func_00187464");
extern "C" int Xii_func_0018C130(int) asm("func_0018C130");
extern "C" int Xii_func_0019A7D8(int) asm("func_0019A7D8");
extern "C" int Xiiu_func_001348B0(int, unsigned int) asm("func_001348B0");
extern "C" int Xiiu_func_00135594(int, unsigned int) asm("func_00135594");
extern "C" int Xiii_func_0019C0E4(int, int) asm("func_0019C0E4");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_func_00279C98(...) asm("func_00279C98");
extern "C" int Xii_func_00194588(int) asm("func_00194588");
extern "C" int Xiii_func_0019A290(int, int) asm("func_0019A290");
extern "C" int Xiiiii_func_0019397C(int, int, int, int) asm("func_0019397C");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00131550(...) asm("func_00131550");
extern "C" int X_func_001348B0(...) asm("func_001348B0");
extern "C" int X_func_00135594(...) asm("func_00135594");
extern "C" int X_func_0018330C(...) asm("func_0018330C");
extern "C" int X_func_0018741C(...) asm("func_0018741C");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001874AC(...) asm("func_001874AC");
extern "C" int X_func_0018BB8C(...) asm("func_0018BB8C");
extern "C" int X_func_0018BCC0(...) asm("func_0018BCC0");
extern "C" int X_func_0018BD94(...) asm("func_0018BD94");
extern "C" int X_func_0018C068(...) asm("func_0018C068");
extern "C" int X_func_0018C130(...) asm("func_0018C130");
extern "C" int X_func_0018C6C4(...) asm("func_0018C6C4");
extern "C" int X_func_00192E94(...) asm("func_00192E94");
extern "C" int X_func_0019381C(...) asm("func_0019381C");
extern "C" int X_func_00193868(...) asm("func_00193868");
extern "C" int X_func_00193FEC(...) asm("func_00193FEC");
extern "C" int X_func_00194148(...) asm("func_00194148");
extern "C" int X_func_00194370(...) asm("func_00194370");
extern "C" int X_func_001943D8(...) asm("func_001943D8");
extern "C" int X_func_00194688(...) asm("func_00194688");
extern "C" int X_func_00198420(...) asm("func_00198420");
extern "C" int X_func_00199A08(...) asm("func_00199A08");
extern "C" int X_func_00199AB4(...) asm("func_00199AB4");
extern "C" int X_func_0019A174(...) asm("func_0019A174");
extern "C" int X_func_0019A1D0(...) asm("func_0019A1D0");
extern "C" int X_func_0019A20C(...) asm("func_0019A20C");
extern "C" int X_func_0019A24C(...) asm("func_0019A24C");
extern "C" int X_func_0019A290(...) asm("func_0019A290");
extern "C" int X_func_0019A780(...) asm("func_0019A780");
extern "C" int X_func_0019A7D8(...) asm("func_0019A7D8");
extern "C" int X_func_0019A824(...) asm("func_0019A824");
extern "C" int X_func_0019AE20(...) asm("func_0019AE20");
extern "C" int X_func_0019B384(...) asm("func_0019B384");
extern "C" int X_func_0019C0E4(...) asm("func_0019C0E4");
extern "C" int X_func_0019DBC8(...) asm("func_0019DBC8");
extern "C" int X_func_0019DCBC(...) asm("func_0019DCBC");
extern "C" int X_func_001DD00C(...) asm("func_001DD00C");
extern "C" int X_func_0022AED8(...) asm("func_0022AED8");
extern "C" int X_mnuBase__vfunc_03(...) asm("mnuBase__vfunc_03");
extern MnuDiaryInfo D_0029C368[];
extern int D_002A26B0;
extern int D_002A2D80;
extern int D_006E9840;
extern int D_007B2060;

// NON_MATCHING: 57/62 differ, 2 relocs differ (size 0xF8, game 0x108), 41 edits
#ifdef NON_MATCHING
extern "C" int X_func_00198420_8318(void *, int) asm("func_00198420");
extern "C" int func_00198318(MnuPBook *arg0, int arg1)
{
    int idx;
    if (arg1 != 0) {
        int page = (arg0->m_curPage >= 0) ? (arg0->m_curPage / 2) : -1;
        idx = page + 1;
        if (idx >= arg0->m_pageNum) {
            return 0;
        }
        if (X_func_00198420_8318(arg0, idx) != 0) {
            return 0;
        }
        idx = page + 2;
        if (idx >= arg0->m_pageNum) {
            return 1;
        }
    } else {
        int page = (arg0->m_curPage >= 0) ? (arg0->m_curPage / 2) : -1;
        if (page < 0) {
            return 0;
        }
        if (X_func_00198420_8318(arg0, page) != 0) {
            return 0;
        }
        idx = page - 1;
        if (idx < 0) {
            return 1;
        }
    }
    int flags = arg0->m_pages[idx].m_flags;
    if ((flags & 5) != 1 && (flags & 0xA) != 2) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00198318);
#endif

extern "C" int func_00198420(MnuPBook *arg0, int arg1)
{
    MnuBookPage *p = &arg0->m_pages[arg1];
    return p->m_frame < arg0->m_animSlots[p->m_animIdx].m_len;
}


extern "C" void func_0019844C(MnuPBook *arg0, int arg1, int arg2, int arg3)
{
    char buf[32];
    MnuBookPage *e = &arg0->m_pages[arg1];
    int page = (arg1 >= 0) ? (arg1 * 2) : -1;
    int var_a1 = 2;
    if (arg2 != 0 && e->m_leftTex == -1 && !(e->m_flags & 4)) {
        e->m_leftTex = X_func_00194404_844C(arg0, 2, 0x21);
        if (e->m_flags & 0x10) {
            X_func_00279C98_844C(buf, "pb_pagebrk%02d_tcc", page);
        } else {
            X_func_00279C98_844C(buf, "pb_page%02d_tcc", page);
        }
        X_func_0019397C_844C(arg0, buf, 4, e->m_leftTex);
        var_a1 = e->m_leftTex + 1;
    }
    if (arg3 != 0 && e->m_rightTex == -1 && !(e->m_flags & 8)) {
        e->m_rightTex = X_func_00194404_844C(arg0, var_a1, 0x21);
        if (e->m_flags & 0x20) {
            X_func_00279C98_844C(buf, "pb_pagebrk%02d_tcc", page + 1);
        } else {
            X_func_00279C98_844C(buf, "pb_page%02d_tcc", page + 1);
        }
        X_func_0019397C_844C(arg0, buf, 4, e->m_rightTex);
    }
}

extern "C" void func_001985B0(MnuPBook *arg0, int arg1) {
    int idx = (arg1 >= 0) ? (arg1 / 2) : -1;
    MnuBookPage *e = &arg0->m_pages[idx];
    X_memset_85B0(arg0->m_textBuf, 0, 0x200);
    __builtin_memcpy(arg0->m_textBuf, "#r#L#T#f00#w001#F20", 20);
    if (arg1 >= 0 && !(e->m_flags & 0x28)) {
        char *s1 = X_func_001832E8_85B0(arg0->m_info->m_msgBase + arg1);
        char *dst = arg0->m_textBuf + X_strlen_85B0(arg0->m_textBuf);
        X_memcpy_85B0(dst, s1, X_strlen_85B0(s1));
    }
    arg1++;
    e++;
    if (arg1 >= 0 && !(e->m_flags & 0x14)) {
        char *s2 = X_func_001832E8_85B0(arg0->m_info->m_msgBase + arg1);
        char *dst = arg0->m_textBuf + X_strlen_85B0(arg0->m_textBuf);
        X_memcpy_85B0(dst, s2, X_strlen_85B0(s2));
    }
    X_func_001874F4_85B0(arg0->m_msgWin, arg0->m_msgId, arg0->m_textBuf, 0);
}

MnuDiary::MnuDiary()
{
    int i = 1;
    MnuMsgWin *p = (MnuMsgWin *)m_msgs;
    do { new (p) MnuMsgWin; p++; } while (--i != -1);
    m_unk130 = -1;
    m_msgId = -1;
    m_diaryId = -1;
    m_unk118 = -1;
    m_unk11C = -1;
    m_type = 7;
    m_slots = 0;
    m_textBuf = 0;
    m_info = 0;
    m_texPageMap = 0;
}

extern "C" void MnuDiary__vfunc_01(char *arg0, int arg1)
{
    char *start = arg0 + 0x13C;
    *(void **)(arg0 + 0x10C) = &vtbl_MnuDiary_v1;
    X_MnuDiary__vfunc_03_v1(arg0);
    if (start != 0) {
        char *p = arg0 + 0x8B4;
        if (start != p) {
            do {
                p -= 0x3BC;
                X_func_00183B24_v1(p, 2);
            } while (start != p);
        }
    }
    X_mnuBase__vfunc_01_v1(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete_v1(arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8190);

extern "C" void MnuDiary__vfunc_02(MnuDiary *arg0, int arg1) {
    X_func_00192BA4_v2(arg0, arg1, 0x10, 6, 2, 0x13);
    arg0->m_unk118 = X_func_001D83D0_v2(&D_007812C0_v2, 1, arg0->m_diaryId, 0);
    int v = sysWork_v2()[X_func_001D83D0_v2(&D_007812C0_v2, 1, arg0->m_diaryId, 4)];
    arg0->m_flags |= 0x40000;
    arg0->m_unk11C = v;
    arg0->m_curPage = sysWork_v2()[X_func_001D83D0_v2(&D_007812C0_v2, 1, arg0->m_diaryId, 7)] & ~1;
    arg0->m_texPageMap = (int *)X_func_00194588_v2(0x4C);
    X_memset_v2(arg0->m_texPageMap, -1, 0x4C);
    int pages = (arg0->m_info->m_pageCount / 2) + 1;
    arg0->m_unk8B4 = 0;
    arg0->m_flags |= 2;
    arg0->m_unk120 = 0;
    arg0->m_state = 0;
    arg0->m_paperNum = pages;
    arg0->m_textBuf = (char *)X_func_00194588_v2(0x4C8);
    __builtin_memcpy(arg0->m_rpkPath, "data/mnurpk/mnupbook/mnupbook.rpk", 34);
    arg0->vfunc10();
    X_func_0019397C_v2(arg0, "ehonbg", 4, 1);
    X_func_0019397C_v2(arg0, "ehontex01_tcc", 4, 0);
}

extern "C" void MnuDiary__vfunc_03(MnuDiary *arg0)
{
    if (arg0->m_textBuf != 0) {
        X_func_00194688_v3(arg0->m_textBuf);
        arg0->m_textBuf = 0;
    }
    if (arg0->m_slots != 0) {
        X_func_00194688_v3(arg0->m_slots);
        arg0->m_slots = 0;
    }
    arg0->m_paperNum = 0;
    if (arg0->m_texPageMap != 0) {
        X_func_00194688_v3(arg0->m_texPageMap);
        arg0->m_texPageMap = 0;
    }
    X_func_00193868_v3(arg0);
    if (arg0->m_unk130 != -1) {
        X_func_001348B0_v3(arg0->m_scene, arg0->m_unk130);
        arg0->m_unk130 = -1;
    }
    if (arg0->m_msgId != -1) {
        X_func_001348B0_v3(arg0->m_scene, arg0->m_msgId);
        arg0->m_msgId = -1;
    }
    X_func_00187464_v3(arg0->m_msgs);
    arg0->m_info = 0;
    arg0->m_diaryId = -1;
    arg0->m_unk118 = -1;
    arg0->m_unk11C = -1;
    X_mnuBase__vfunc_03_v3(arg0);
}

extern "C" int func_00198B04(MnuDiary *arg0, int arg1)
{
    for (arg0->m_info = D_0029C368; arg0->m_info->m_id != -1; arg0->m_info++) {
        if (arg0->m_info->m_id == arg1) {
            break;
        }
    }
    if (arg0->m_info->m_id == -1) {
        return 0;
    }
    arg0->m_diaryId = arg1;
    return 1;
}

extern "C" void func_00198B54(MnuDiary *arg0)
{
    char buf[32];
    arg0->m_slots = (MnuBookPage *)X_func_00194588_v2(0xA0);
    MnuBookPage *p = arg0->m_slots;
    int i = 4;
    do {
        i -= 1;
        p->m_flags = 0;
        p->m_rightTex = -1;
        p->m_leftTex = -1;
        p->m_animIdx = -1;
        p->m_frame = 0;
        p++;
    } while (i >= 0);
    X_func_0019397C_v2(arg0, "a_diary", 4, 2);
    X_func_00279C98(buf, "%s_base.i3s", arg0->m_info->m_prefix);
    X_func_0019397C_v2(arg0, buf, 1, 5);
    int paper = (arg0->m_curPage + 1) / 2;
    Xiii_func_0019A290((int)arg0, paper - 1);
    Xiii_func_0019A290((int)arg0, paper);
    X_func_00279C98(buf, "%s01_base.i3s", arg0->m_info->m_prefix);
    X_func_0019397C_v2(arg0, buf, 1, 0);
    X_func_00279C98(buf, "%s01_turn_r.i3s", arg0->m_info->m_prefix);
    X_func_0019397C_v2(arg0, buf, 2, 0);
    X_func_00279C98(buf, "%s01_turn_l.i3s", arg0->m_info->m_prefix);
    X_func_0019397C_v2(arg0, buf, 2, 1);
}

extern "C" void func_00192E94(MnuBase *, float, float);
extern "C" void func_0019381C(MnuBase *);
extern "C" void func_00194148(MnuBase *, int, int);
extern "C" void func_00193FEC(MnuBase *, int, int);
extern "C" int func_0019A1D0(MnuDiary *);
extern "C" void func_00199A08(MnuDiary *, int, int, int);
extern "C" void func_00199AB4(MnuDiary *, int, int);
extern "C" void func_0019A290(MnuDiary *, int);
extern "C" void func_00198CA8(MnuDiary *arg0)
{
    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int temp_s1;
    int temp_s3;
    int doubled;
    int var_s2;
    unsigned int temp_s0;
    MnuAnimSlot *temp_v1_2;
    MnuBookPage *temp_v1_3;
    MnuBookPage *temp_v1_4;
    int var_a1;

    var_s2 = 1;
    func_00192E94(arg0, 512.0f, 0.785398080945015f);
    func_0019381C(arg0);
    do {
        func_00194148(arg0, var_s2, 0);
    } while (++var_s2 < 5);
    var_s2 = 0;
    if (arg0->m_unkA0 >= 1) {
        do {
            arg0->m_animSlots[var_s2].m_len *= 2;
            var_s2 += 1;
        } while (var_s2 < arg0->m_unkA0);
    }
    temp_s0 = arg0->m_curPage + 1;
    temp_s0_2 = temp_s0 + (temp_s0 >> 0x1F);
    temp_s0_3 = temp_s0_2 >> 1;
    var_s2 = func_0019A1D0(arg0);
    temp_v1_3 = &arg0->m_slots[var_s2];
    temp_s1 = temp_s0_3 - 1;
    temp_v1_3->m_animIdx = 1;
    temp_v1_3->m_page = temp_s1;
    temp_v1_3->m_flags |= 3;
    temp_v1_3->m_frame = arg0->m_animSlots[1].m_len;
    func_00193FEC(arg0, var_s2, 1);
    doubled = temp_s1 * 2;
    func_00199A08(arg0, temp_s1, doubled + 1, 0);
    func_00199A08(arg0, temp_s1, doubled + 2, 1);
    var_s2 = func_0019A1D0(arg0);
    temp_v1_4 = &arg0->m_slots[var_s2];
    temp_v1_4->m_page = temp_s0_3;
    temp_v1_4->m_animIdx = 0;
    temp_v1_4->m_flags |= 3;
    temp_v1_4->m_frame = arg0->m_animSlots[0].m_len;
    func_00193FEC(arg0, var_s2, 0);
    temp_s3 = temp_s0_3 * 2;
    func_00199A08(arg0, temp_s0_3, temp_s3 + 1, 0);
    func_00199A08(arg0, temp_s0_3, temp_s3 + 2, 1);
    func_00199AB4(arg0, arg0->m_curPage, 0);
    func_00199AB4(arg0, arg0->m_curPage + 1, 1);
    temp_s0_4 = (arg0->m_curPage + 1) / 2;
    func_0019A290(arg0, temp_s0_4 + 1);
    func_0019A290(arg0, temp_s0_4 - 2);
}

extern "C" void func_00198EB4(MnuDiary *arg0)
{
    int temp_v0_2;
    int temp_v0_3;
    int temp_s2;
    int temp_v0;

    temp_s2 = (int)arg0->m_msgs;
    temp_v0 = (int)arg0->m_textBuf;
    *(DiaryRGB *)temp_v0 = *(DiaryRGB *)&D_002F8228;
    Xii_func_0018741C(temp_s2);
    temp_v0_2 = Xiiiiii_func_00134730(arg0->m_scene, 0x200, 0x100, 0, -1);
    arg0->m_msgId = temp_v0_2;
    Xiiuiii_func_00134A00(arg0->m_scene, (unsigned int) temp_v0_2, 0, 0x20, 0x7FFF);
    Xiiuiiii_func_00134CD0(arg0->m_scene, (unsigned int) arg0->m_msgId, 0, 0, 0x200, 0x100);
    Xiiuii_func_00134AB8(arg0->m_scene, (unsigned int) arg0->m_msgId, 0x200, 0x100);
    Xiiui_func_00135494(arg0->m_scene, (unsigned int) arg0->m_msgId, 1);
    Xiiui_func_00135418(arg0->m_scene, (unsigned int) arg0->m_msgId, 0);
    Xiiui_func_001351B0(arg0->m_scene, (unsigned int) arg0->m_msgId, 0);
    Xiiu_func_00135594(arg0->m_scene, (unsigned int) arg0->m_msgId);
    Xiii_func_0019A3C0((int)arg0, arg0->m_curPage);
    Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 4, 0xDC, 0x198);
    Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 4, 0);
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 0, 0);
    Xii_func_0018741C(temp_s2);
    temp_v0_3 = Xiiiiii_func_00134730(arg0->m_scene, 0x40, 0x20, 0, -1);
    arg0->m_unk130 = temp_v0_3;
    Xiiuiii_func_00134A00(arg0->m_scene, (unsigned int) temp_v0_3, 0xF6, 0x19A, 0x7FFF);
    Xiiuiiii_func_00134CD0(arg0->m_scene, (unsigned int) arg0->m_unk130, 0, 0, 0x40, 0x20);
    Xiiui_func_00135494(arg0->m_scene, (unsigned int) arg0->m_unk130, 1);
    Xiiui_func_00135418(arg0->m_scene, (unsigned int) arg0->m_unk130, 0);
    Xiiui_func_001351B0(arg0->m_scene, (unsigned int) arg0->m_unk130, 1);
    Xiiu_func_00135594(arg0->m_scene, (unsigned int) arg0->m_unk130);
    int texture = Xiu_func_001832E8(0x1AU);
    diaryAttach(temp_s2, arg0->m_unk130, texture, 0);
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8228);

// NON_MATCHING: 44/238 differ, 1 reloc differs (size 0x3B8, game 0x3BC), 33 edits
#ifdef NON_MATCHING

extern int diaryV5Sound asm("D_007B2580");
extern int diaryV5Work asm("D_007A4440");
extern "C" int diaryV5X_func_00279C98(...) asm("func_00279C98");
extern "C" int diaryV5Xii_func_00131550(int) asm("func_00131550");
extern "C" int diaryV5Xii_func_00192F3C(int) asm("func_00192F3C");
extern "C" int diaryV5Xii_func_00193A1C(int) asm("func_00193A1C");
extern "C" int diaryV5Xii_func_00198B54(int) asm("func_00198B54");
extern "C" int diaryV5Xii_func_00198CA8(int) asm("func_00198CA8");
extern "C" int diaryV5Xii_func_00198EB4(int) asm("func_00198EB4");
extern "C" int diaryV5Xii_func_00199714(int) asm("func_00199714");
extern "C" int diaryV5Xii_func_001D44E4(int) asm("func_001D44E4");
extern "C" int diaryV5Xiii_func_0017F8FC(int, int) asm("func_0017F8FC");
extern "C" int diaryV5Xiii_func_0019946C(int, int) asm("func_0019946C");
extern "C" int diaryV5Xiiiii_func_00131184(int, int, int, int) asm("func_00131184");
extern "C" int diaryV5Xiiiii_func_001311BC(int, int, int, int) asm("func_001311BC");
extern "C" int diaryV5Xiiiii_func_001C5094(int, int, int, int) asm("func_001C5094");
extern "C" int diaryV5Xiiiii_func_001D83D0(int, int, int, int) asm("func_001D83D0");
extern "C" int diaryV5Xiiui_func_001351B0(int, unsigned int, int) asm("func_001351B0");
inline bool diaryV5Ready(int p) { return diaryV5Xii_func_00131550(p) >= 5; }
inline int diaryV5SlotA(char *p) { return *(int *)(p+0xDC1C); }
inline int diaryV5SlotB(char *p) { return *(int *)(p+0xDC20); }
inline void diaryV5Clear(int *p, int mask) { *p &= ~mask; }
inline void diaryV5Set(int *p, int mask) { *p |= mask; }
extern "C" int MnuDiary__vfunc_05(MnuDiary *arg0, int arg1)
{
    int temp_a1;
    int temp_a0;
    int temp_v1_2;
    int temp_v1_3;
    int var_s2;
    int var_v0;
    unsigned int temp_v0_3;
    unsigned int temp_v1;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_4;

    var_s2 = 0;
    diaryV5Xii_func_00193A1C((int)arg0);
    diaryV5Xii_func_00199714((int)arg0);
    temp_v1 = (unsigned int)arg0->m_state;
    arg0->m_unk10 = temp_v1;
    switch (temp_v1) {
    case 0:
        if (!(arg0->m_flags & 0x20000) && diaryV5Ready(arg0->m_scene)) {
            arg0->m_flags = (int) (arg0->m_flags | 0x20000);
        }
        temp_v1_2 = arg0->m_flags;
        if (!(temp_v1_2 & 0x10000) && (arg0->m_resUsed == 0)) {
            arg0->m_flags = (int) (temp_v1_2 | 0x10000);
            arg0->vfunc11();
            diaryV5X_func_00279C98(arg0->m_rpkPath, (int) "data/mnurpk/mnupbook/%s.rpk", arg0->m_info->m_prefix);
            arg0->vfunc10();
            diaryV5Xii_func_00198B54((int)arg0);
            arg0->m_flags = (int) (arg0->m_flags | 0x20000);
        }
        var_v0 = 0;
        if ((arg0->m_flags & 0x30000) == 0x30000) {
            arg0->m_state = 1U;
        } else { return 0;
        default:
            break;
        }
        break;
    case 1:
        if (arg0->m_resUsed != 0) return 0;
        if (arg0->m_resUsed == 0) {
            diaryV5Xii_func_00198CA8((int)arg0);
            arg0->m_flags = (int) (arg0->m_flags & 0xFFFCFFFF);
            diaryV5Xiiiii_func_00131184((int) arg0->m_scene, 0xF, 7, 0);
            arg0->m_state = 2U;
            break;
        }
        break;
    case 2:
        if (!(arg0->m_flags & 0x20000) && diaryV5Ready(arg0->m_scene)) {
            arg0->m_flags = (int) (arg0->m_flags | 0x20000);
        }
        temp_v1_3 = arg0->m_flags;
        if (!(temp_v1_3 & 0x10000) && (arg0->m_resUsed == 0)) {
            arg0->m_flags = (int) (temp_v1_3 | 0x10000);
            diaryV5Xii_func_00198EB4((int)arg0);
        }
        temp_a0 = arg0->m_flags;
        var_v0 = 0;
        if ((temp_a0 & 0x30000) == 0x30000) {
            arg0->m_state = 3U;
            arg0->m_flags = (int) (temp_a0 & ~2);
            break;
        }
        break;
    case 3:
        if (diaryV5Xiii_func_0019946C((int)arg0, arg1) == 0) {
            diaryV5Xiiiii_func_001311BC((int) arg0->m_scene, 0xF, 7, 0);
            diaryV5Xiii_func_0017F8FC((int) (int)&diaryV5Sound, 2);
            diaryV5Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 0, 0);
            diaryV5Xiiui_func_001351B0((int) arg0->m_scene, (unsigned int)arg0->m_unk130, 1);
            arg0->m_state = 4U;
        }
        break;
    case 4:
        if (diaryV5Ready(arg0->m_scene)) {
            arg0->m_state = 5U;
        }
        break;
    case 5:
        M2C_FIELD(diaryV5SlotA((char *)&diaryV5Work), int *, 0x44) = diaryV5Xiiiii_func_001D83D0((int) (int)&D_007812C0, 1, arg0->m_diaryId, 2);
        M2C_FIELD(diaryV5SlotA((char *)&diaryV5Work), int *, 0x194) = (int) arg0->m_unk118;
        diaryV5Clear((int *)(diaryV5SlotB((char *)&diaryV5Work)+4), 0x04000000);
        if (diaryV5Xii_func_001D44E4((int)&D_007812C0) != 0) {
            diaryV5Set((int *)(diaryV5SlotB((char *)&diaryV5Work)+4), 0x02000000);
        }
        temp_v0_3 = diaryV5Xiiiii_func_001D83D0((int) (int)&D_007812C0, 1, arg0->m_diaryId, 6);
        temp_a1 = ((temp_v0_3 >> 5) * 4) + diaryV5SlotB((char *)&diaryV5Work);
        var_s2 = 1;
        (*(int *)(temp_a1)) &= ~(1 << (temp_v0_3 & 0x1F));
        diaryV5Xii_func_00192F3C((int)arg0);
        arg0->vfunc03();
        break;
    }
    return var_s2;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_05);
#endif

inline int diaryPressed(unsigned int bits) { return (bits >> 13) & 1; }
inline void diaryTick(unsigned int *counter) { *counter = (*counter + 1) % 300U; }
extern "C" float Xfi_getLeftX__C6BedPad(int) asm("getLeftX__C6BedPad");
extern "C" int Xiii_func_0017F8FC(int, int) asm("func_0017F8FC");
extern "C" int Xiii_func_0019A054(int, int) asm("func_0019A054");
extern "C" int Xiiii_func_00199B3C(int, int, int) asm("func_00199B3C");
extern int D_007B2580;
extern "C" int func_0019946C(MnuDiary *arg0, int arg1)
{
    int temp_v0;
    int temp_v0_3;
    int temp_v1;
    unsigned int temp_a1;

    if (arg0->m_flags & 0x40000) {
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 1, 0);
        Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk130, 0);
    }
    temp_v0 = arg0->m_unk120;

    if (temp_v0 > 0) {
        temp_v0 -= 1;
        arg0->m_unk120 = temp_v0;
        if (temp_v0 == 0) {
            arg0->m_flags = (int) (arg0->m_flags & 0xFFE7FFFD);
            Xiii_func_0019A3C0((int)arg0, arg0->m_curPage);
            if ((arg0->m_curPage + 1) >= arg0->m_unk11C) {
                arg0->m_flags = (int) (arg0->m_flags | 0x40000);
            }
        }
    }
    Xii_func_001874AC((int)arg0->m_msgs);
    temp_v1 = arg0->m_flags;
    if (temp_v1 & 2) goto tick;
    {
        if (diaryPressed(M2C_FIELD(arg1, unsigned short *, 0x7A)) && (temp_v1 & 0x40000)) {
            Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_msgId, 1);
            arg0->m_flags = (int) (arg0->m_flags | 2);
            return 0;
        }
        if (arg0->m_unk120 == 0) {
            if (((((unsigned short) M2C_FIELD(arg1, unsigned short *, 0x78) >> 5) & 1 & 0xFFFF) || (Xfi_getLeftX__C6BedPad((int) arg1) >= 0.75f)) && (Xiii_func_0019A054((int)arg0, 1) != 0)) {
                temp_v0_3 = arg0->m_curPage;
                temp_a1 = temp_v0_3 + 3;
                arg0->m_curPage = (int) (temp_v0_3 + 2);
                Xiiii_func_00199B3C((int)arg0, ((int) (temp_a1 + (temp_a1 >> 0x1F)) >> 1) - 1, 1);
                arg0->m_flags = (int) (arg0->m_flags | 0x100002);
                Xiii_func_0017F8FC((int) (int)&D_007B2580, 8);
                Xiii_func_0019A3C0((int)arg0, -1);
            } else if (((((unsigned short) M2C_FIELD(arg1, unsigned short *, 0x78) >> 7) & 1 & 0xFFFF) || (Xfi_getLeftX__C6BedPad((int) arg1) <= -0.75f)) && (Xiii_func_0019A054((int)arg0, 0) != 0)) {
                Xiiii_func_00199B3C((int)arg0, ((int) (arg0->m_curPage + 1) / 2) - 1, 0);
                arg0->m_curPage = (int) (arg0->m_curPage - 2);
                arg0->m_flags = (int) (arg0->m_flags | 0x80002);
                Xiii_func_0017F8FC((int) (int)&D_007B2580, 8);
                Xiii_func_0019A3C0((int)arg0, -1);
            }
        }

    }
    if (arg0->m_flags & 2) {
tick:
        (*(unsigned int *)&arg0->m_unk8B4) = ((*(unsigned int *)&arg0->m_unk8B4) + 1) % 300U;
    }
    return 1;
}

// NON_MATCHING: 73/189 differ (size 0x2F4, game 0x2F4), 63 edits
#ifdef NON_MATCHING
extern "C" void P714_func_00194370(MnuBase *, int) asm("func_00194370");
extern "C" int func_0019A20C(MnuDiary *, int);
extern "C" int func_0019A24C(MnuDiary *, int);
extern "C" void func_00199AB4(MnuDiary *, int, int);
extern "C" void func_00199714(MnuDiary *self)
{
    MnuBookPage *pg = self->m_slots;
    int n, paper, page, tex, t;
    if (pg != 0) {
    for (n = 4; n >= 0; n--, pg++) {
        bool disabled = !(pg->m_flags & 1);
        if (!disabled) {
            int anim = pg->m_animIdx;
            int frame = pg->m_frame;
            MnuAnimSlot *a = &self->m_animSlots[anim];
            if (frame < a->m_len) {
                pg->m_frame = ++frame;
                t = a->m_len - frame;
                if (t == 0) {
                    if (!(anim & 1)) {
                        func_00199AB4(self, pg->m_page * 2 + 1, 1);
                    } else {
                        func_00199AB4(self, pg->m_page * 2 + 2, 0);
                    }
                } else if (t == 4) {
                    t = func_0019A20C(self, ((anim & 1) ^ 0) != 0 ? pg->m_page - 1 : pg->m_page + 1);
                    if (t != -1) {
                        self->m_slots[t].m_flags &= ~3;
                    }
                } else if (frame == 4) {
                    t = func_0019A20C(self, ((anim & 1) ^ 0) != 0 ? pg->m_page + 1 : pg->m_page - 1);
                    if (t != -1) {
                        self->m_slots[t].m_flags |= 2;
                    }
                }
            }
        }
    }
    n = (self->m_curPage + 1) / 2 - 2;
    while (n >= -1) {
        int prev = n - 1;
        if (func_0019A20C(self, n) == -1) {
            for (n = prev * 2 + 2; n >= 0; n--) {
            t = func_0019A24C(self, n);
            if (t != -1) {
                P714_func_00194370(self, t);
                self->m_texPageMap[t] = -1;
            }
            }
            break;
        }
        n = prev;
    }
    n = (self->m_curPage + 1) / 2 + 1;
    while (n < self->m_paperNum) {
        int next = n + 1;
        if (func_0019A20C(self, n) == -1) {
            for (n = next * 2 + 1; n < self->m_info->m_pageCount; n++) {
            t = func_0019A24C(self, n);
            if (t != -1) {
                P714_func_00194370(self, t);
                self->m_texPageMap[t] = -1;
            }
            }
            break;
        }
        n = next;
    }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00199714);
#endif

extern "C" void func_00199A08(MnuDiary *arg0, int arg1, int arg2, int arg3)
{
    int idx1 = X_func_0019A20C_9A08(arg0, arg1);
    int idx2 = X_func_0019A24C_A290(arg0, arg2);
    UnkHdr_9AB4 **p = X_func_0022AED8_9AB4(arg0->m_models[idx1].m_data + 0x10, arg3 != 0);
    (*func_0022AAD0(p, 0))->unk1C = arg0->m_texSlots[idx2].m_texId;
    (*p)->unk08++;
}

extern "C" void func_00199AB4(MnuDiary *arg0, int arg1, int arg2)
{
    int idx = X_func_0019A24C_A290(arg0, arg1);
    UnkHdr_9AB4 **p = X_func_0022AED8_9AB4(arg0->m_models[5].m_data + 0x10, arg2 != 0);
    (*func_0022AAD0(p, 0))->unk1C = arg0->m_texSlots[idx].m_texId;
    (*p)->unk08++;
}

// NON_MATCHING: 26/86 differ, 26 edits
#ifdef NON_MATCHING
struct Entry_9B3C {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct Sub9C_9B3C {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct Obj_9B3C {
    unsigned char pad00[0x9C];
    Sub9C_9B3C *m_9C;
    unsigned char padA0[0x120 - 0xA0];
    int m_120;
    int m_124;
    Entry_9B3C *m_128;
};
extern "C" int X_func_0019A1D0_9B3C(void *) asm("func_0019A1D0");
extern "C" int X_func_0019A20C_9B3C(void *, int) asm("func_0019A20C");
extern "C" void X_func_0019A290_9B3C(void *, int) asm("func_0019A290");
extern "C" void X_func_00193FEC_9B3C(void *, int, int) asm("func_00193FEC");
extern "C" void X_func_00199AB4_9B3C(void *, int, int) asm("func_00199AB4");
extern "C" void X_func_00199A08_9B3C(void *, int, int, int) asm("func_00199A08");

static inline void call9A08_9B3C(Obj_9B3C *arg0, int page, int page2)
{
    X_func_00199A08_9B3C(arg0, page, page2 + 1, 0);
    X_func_00199A08_9B3C(arg0, page, page2 + 2, 1);
}

extern "C" void func_00199B3C(Obj_9B3C *arg0, int arg1, int arg2)
{
    int cur2 = arg1 * 2;
    int idx = X_func_0019A20C_9B3C(arg0, arg1);
    Entry_9B3C *e = &arg0->m_128[idx];
    e->unk0C = (arg2 != 0);
    e->unk10 = 0;
    X_func_00193FEC_9B3C(arg0, idx, (arg2 != 0));
    call9A08_9B3C(arg0, arg1, cur2);
    arg0->m_120 = 0xA;
    X_func_00199AB4_9B3C(arg0, (arg2 != 0) ? (cur2 + 3) : cur2, arg2);
    X_func_0019A290_9B3C(arg0, (arg2 != 0) ? (arg1 + 2) : (arg1 - 2));

    idx = X_func_0019A1D0_9B3C(arg0);
    int next = (arg2 != 0) ? (arg1 + 1) : (arg1 - 1);
    int zero = arg2 == 0;
    e = &arg0->m_128[idx];
    e->unk14 = next;
    e->unk0C = zero;
    e->unk00 |= 1;
    e->unk10 = arg0->m_9C[zero].unk04;
    X_func_00193FEC_9B3C(arg0, idx, zero);
    call9A08_9B3C(arg0, next, next * 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00199B3C);
#endif

// NON_MATCHING: 180/207 differ, 10 relocs differ (size 0x33C, game 0x338), 26 edits
#ifdef NON_MATCHING

struct DiaryV6Pair { long long a,b; };
extern "C" int X_func_0021B550(...) asm("func_0021B550");
extern "C" int X_func_00237340(...) asm("func_00237340");
extern "C" int X_func_002378B0(...) asm("func_002378B0");
extern "C" int Xiii_func_00192F68(int, int) asm("func_00192F68");
extern "C" int Xiii_func_001930F8(int, int) asm("func_001930F8");
extern "C" int Xiii_func_00193210(int, int) asm("func_00193210");
extern "C" int Xiiiff_func_00193258(int, float, float, int) asm("func_00193258");
extern "C" int Xiiiiiii_func_0019368C(int, int, int, int, int, int) asm("func_0019368C");
extern int D_002F8270;
extern "C" void MnuDiary__vfunc_06(MnuDiary *arg0, int arg1)
{
    struct { float sp0; float sp4; float sp8; float spC; float sp10; float sp14; float sp18; float sp1C; float sp20; float sp24; float sp28; float sp2C; float sp30; char pad34[12]; DiaryV6Pair vec; int sp50; char pad54[44]; float sp80; float sp84; float sp88; } stack;
    float temp_f0;
    float temp_f0_2;
    int var_s1;
    MnuBookPage *var_s0;

    if ((unsigned int) (arg0->m_unk10 - 2) < 3U) {
        Xiii_func_00192F68((int)arg0, arg1);
        Xiii_func_00193210((int)arg0, 1);
        stack.sp0 = 0.0f;
        stack.sp8 = 512.0f;
        stack.spC = 448.0f;
        stack.sp1C = 0.875f;


        stack.sp18 = stack.sp2C = stack.sp28 = stack.sp24 = stack.sp20 = 1.0f;
        Xiiiff_func_00193258((int)arg0, stack.sp4 = stack.sp30 = stack.sp10 = stack.sp14 = stack.sp0, stack.sp0, (int)&stack);
        Xiii_func_00193210((int)arg0, 0);
        if ((arg0->m_curPage - 1) >= 0) {
            if (arg0->m_flags & 0x80000) {
                var_s1 = (unsigned int) ((unsigned int) (unsigned int)arg0->m_unk8B4 >> 1) % 3U;
            } else {
                var_s1 = 0;
            }
            stack.spC = 16.0f;
            temp_f0 = ((float) var_s1 * 16.0f) + 48.0f;
            stack.sp8 = 28.0f;
            stack.sp18 = 0.21875f;
            stack.sp10 = 0.0f;
            stack.sp14 = temp_f0 * 0.0078125f;
            stack.sp1C = (temp_f0 + 16.0f) * 0.0078125f;
            Xiiiff_func_00193258((int)arg0, 100.0f, 412.0f, (int)&stack);
        }
        if ((arg0->m_curPage + 2) < arg0->m_info->m_pageCount) {
            if (arg0->m_flags & 0x100000) {
                var_s1 = (unsigned int) ((unsigned int) (unsigned int)arg0->m_unk8B4 >> 1) % 3U;
            } else {
                var_s1 = 0;
            }
            stack.sp10 = 0.0f;
            stack.spC = 16.0f;
            temp_f0_2 = ((float) var_s1 * 16.0f) + stack.sp10;
            stack.sp8 = 28.0f;
            stack.sp18 = 0.21875f;
            stack.sp14 = temp_f0_2 * 0.0078125f;
            stack.sp1C = (temp_f0_2 + 16.0f) * 0.0078125f;
            Xiiiff_func_00193258((int)arg0, 384.0f, 412.0f, (int)&stack);
        }
        var_s1 = 0;
        arg0->m_unkB0 = X_func_0021B550(arg0->m_unkB0, 0x47, 0x503FD);
        Xiii_func_001930F8((int)arg0, arg1);
        stack.vec = *(DiaryV6Pair *)&D_002F8270;
        X_func_00237340((int)&stack.sp50);
        X_func_002378B0((int)&stack.sp50, (int)&stack.sp50, (int)&stack.vec);
        stack.sp80 = 21.0f;
        stack.sp84 = 8.0f;
        stack.sp88 = 220.0f;
        Xiiiiiii_func_0019368C((int)arg0, arg1, (int)&stack.sp50, 5, -1, 0);
        var_s0 = arg0->m_slots;
        do {
            if (var_s0->m_flags & 2) {
                Xiiiiiii_func_0019368C((int)arg0, arg1, (int)&stack.sp50, var_s1, var_s0->m_animIdx, var_s0->m_frame);
            }
            var_s1 += 1;
            var_s0++;
        } while (var_s1 < 5);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_06);
#endif

extern "C" void MnuDiary__vfunc_07(MnuDiary *arg0, int arg1)
{
    int arr[16];
    Arg223558_v7 q;
    MnuTexSlot *p1;
    MnuTexSlot *p2;
    int v;

    p1 = arg0->m_texSlots;
    arr[0] = p1[0].m_texId;
    p1[0].m_unk0C = 0;
    p2 = arg0->m_texSlots;
    arr[1] = p2[1].m_texId;
    {
        register int one PS2_REG("$6") = 1;
        p2[1].m_unk0C = one;
    }
    {
        register int two PS2_REG("$6") = 2;
        q.unk08 = two;
    }
    q.unk00 = 0;
    q.unk04 = arr;
    q.unk0C = 0;
    q.unk10 = 0;
    q.unk14 = 0;
    v = X_func_00223558_v7(arg1, &q);
    arg0->m_unkAC = v;
    X_func_00223228_v7(arg1, v);
}

// NON_MATCHING: 13/72 differ, 1 reloc differs, 15 edits
#ifdef NON_MATCHING
extern "C" int X_func_0019A1D0_A054(void *) asm("func_0019A1D0");
extern "C" int X_func_0019A174_A054(void *, int) asm("func_0019A174");
extern "C" int X_func_0019A24C_A054(void *, int) asm("func_0019A24C");
extern "C" int X_func_001943D8_A054(void *, int) asm("func_001943D8");
static inline int tail_A054(MnuDiary *arg0, int id)
{
    int i = X_func_0019A24C_A054(arg0, id);
    if (i != -1) {
        if (X_func_001943D8_A054(arg0, i) != 0) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_0019A054(MnuDiary *arg0, int arg1)
{
    int idx;
    int page;

    if (X_func_0019A1D0_A054(arg0) == -1) {
        return 0;
    }
    if (arg1 != 0) {
        idx = (arg0->m_curPage + 1) / 2;
        if (idx >= arg0->m_paperNum) {
            return 0;
        }
        if (X_func_0019A174_A054(arg0, idx) != 0) {
            return 0;
        }
        idx++;
        if (idx >= arg0->m_paperNum) {
            return 1;
        }
        return tail_A054(arg0, idx * 2 + 1);
    } else {
        page = (arg0->m_curPage + 1) / 2;
        idx = page - 1;
        if (idx < 0) {
            return 0;
        }
        if (X_func_0019A174_A054(arg0, idx) != 0) {
            return 0;
        }
        idx = page - 2;
        if (idx < -1) {
            return 1;
        }
        return tail_A054(arg0, idx * 2 + 2);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019A054);
#endif

extern "C" int func_0019A174(MnuDiary *arg0)
{
    int idx = X_func_0019A20C();
    if (idx != -1) {
        MnuBookPage *p = &arg0->m_slots[idx];
        return p->m_frame < arg0->m_animSlots[p->m_animIdx].m_len;
    }
    return 0;
}

extern "C" int func_0019A1D0(MnuDiary *self)
{
    MnuBookPage *p = self->m_slots;
    int i;

    for (i = 0; i < 5; i++) {
        if ((p->m_flags ^ 1) & 1) {
            return i;
        }
        p++;
    }
    return -1;
}

extern "C" int func_0019A20C(MnuDiary *arg0, int arg1)
{
    MnuBookPage *p = arg0->m_slots;
    int i = 0;

    for (;;) {
        if (p->m_flags & 1) {
            if (p->m_page == arg1) {
                return i;
            }
        }
        i += 1;
        if (i < 5) {
            p++;
            continue;
        }
        return -1;
    }
}

extern "C" int func_0019A24C(MnuDiary *arg0, int arg1)
{
    for (int i = 0; i < arg0->m_texSlotNum; i++) {
        if (arg0->m_texPageMap[i] == arg1) {
            return i;
        }
    }
    return -1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8270);

extern "C" void func_0019A290(MnuDiary *arg0, int arg1)
{
    char buf[32];
    int page;
    int idx;

    page = arg0->getPageByPaper(arg1);
    if (page >= 0 && page < arg0->m_info->m_pageCount && X_func_0019A24C_A290(arg0, page) == -1) {
        idx = X_func_00194404_844C(arg0, 3, 0x12);
        arg0->m_texPageMap[idx] = page;
        X_func_00279C98_844C(buf, "dy_page%02d_tcc", page);
        X_func_0019397C_v2(arg0, buf, 4, idx);
    }
    page++;
    if (page >= 0 && page < arg0->m_info->m_pageCount && X_func_0019A24C_A290(arg0, page) == -1) {
        idx = X_func_00194404_844C(arg0, 3, 0x12);
        arg0->m_texPageMap[idx] = page;
        X_func_00279C98_844C(buf, "dy_page%02d_tcc", page);
        X_func_0019397C_v2(arg0, buf, 4, idx);
    }
}

extern "C" void func_0019A3C0(MnuDiary *arg0, int arg1)
{
    memset(arg0->m_textBuf, 0, 0x4C8);
    __builtin_memcpy(arg0->m_textBuf, "#r#L#T#[50#]50#f00#w001#F20", 28);
    if (arg1 >= -1) {
        char *s1 = X_func_001832E8_85B0(arg0->m_info->m_msgBase + arg1 - 1);
        if (s1 != 0 && strcmp(s1, D_002F8228) != 0) {
            strlen(s1);
            char *dst = arg0->m_textBuf + strlen(arg0->m_textBuf);
            memcpy(dst, s1, strlen(s1));
        }
        char *s2 = X_func_001832E8_85B0(arg0->m_info->m_msgBase + arg1);
        if (s2 != 0) {
            strlen(s2);
            char *dst = arg0->m_textBuf + strlen(arg0->m_textBuf);
            memcpy(dst, s2, strlen(s2));
        }
    }
    X_func_001874F4_85B0(arg0->m_msgs, arg0->m_msgId, arg0->m_textBuf, 0);
}

extern "C" void func_0019A52C(int arg0)
{
    int temp_a0;
    int var_s0;
    int var_s2;

    var_s0 = arg0 + 0x58;
    var_s2 = 1;
    do {
        temp_a0 = var_s0;
        var_s0 += 0x3BC;
        X_func_0018330C(temp_a0);
        var_s2 -= 1;
    } while (var_s2 != -1);
    X_func_0018BB8C(arg0 + 0x7D0);
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    X_func_0019AE20(arg0);
    (*(int *)(int *)((char *)(arg0) + 0x1540)) = 0;
}


Obj_9A598::~Obj_9A598() {
    Xvp_func_0019A7D8(this);
    if (m_1540 == 1) {
        Xvp_func_0019A6B8(this);
    }
}

extern "C" void func_0019A650(MnuStock *arg0, int arg1)
{
    int var_s2 = 1;

    if (arg0->m_active == 0) {
        arg0->m_cursor[1] = 0;
        arg0->m_cursor[3] = 0;
        Xiii_func_0018BCC0((int)&arg0->m_rpk, 0x8A);
        arg0->m_rpk.m_param = arg1;
        Xii_func_0019A780((int)arg0);
        arg0->m_active = var_s2;
        arg0->m_flg2B = var_s2;
    }
}

extern "C" void func_0019A6B8(MnuStock *arg0)
{
    int temp_s0;

    if (arg0->m_active != 0) {
        Xii_func_0018C130((int)&arg0->m_rpk);
        temp_s0 = (int)&D_006E9840;
        temp_s0 += 0x12540;
        Xiiu_func_00135594(temp_s0, (unsigned int)arg0->m_unk1580);
        Xiiu_func_001348B0(temp_s0, (unsigned int)arg0->m_unk1580);
        Xii_func_00187464((int)arg0->m_msgs);
        Xii_func_0019A7D8((int)arg0);
        arg0->m_active = 0;
    }
}

extern "C" int func_0019A730(MnuStock *arg0)
{
    return arg0->m_active;
}


extern "C" void func_0019A738(void) {
}

extern "C" int func_0019A740()
{
    return X_func_0019A824();
}


extern "C" void func_0019A754(MnuStock *arg0, int arg1)
{
    MnuRpk *rpk = &arg0->m_rpk;
    arg0->m_renderCtx = arg1;
    if (arg1 != 0) {
        rpk->setRenderCtx(arg1);
        X_func_0018BD94(rpk);
    }
}


extern "C" int func_0019A780(MnuStock *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_unk3C = 0;
    arg0->m_unk54 = 3;
    arg0->m_unk40 = 0;
    arg0->m_unk44 = 0;
    arg0->m_equipIdx = -1;
    arg0->m_findIdx = -1;
    Xii_func_0018741C((int)arg0->m_msgs);
    return 0;
}

extern "C" int func_0019A7D8(MnuStock *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    Xiii_func_0019C0E4((int)arg0, 1);
    arg0->m_open = 0;
    return 0;
}

extern "C" int func_0019A814()
{
    return 0;
}


extern "C" int func_0019A81C()
{
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F82C8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F82E0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F82F0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8300);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8310);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8320);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8330);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8340);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8350);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8360);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8370);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8380);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8390);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F83A0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F83B0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F83C0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F83D0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F83E0);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019A824);

extern "C" int func_0019AE20(MnuStock *self)
{
    int i;
    for (i = 0; i < 7; i++) {
        self->m_cursor[i] = 0;
    }
    self->m_max[0] = 7;
    self->m_max[1] = 8;
    self->m_max[2] = 2;
    self->m_flg1B = 1;
    self->m_flg1A = 1;
    self->m_flg2B = 1;
    self->m_flg2A = 1;
    return 0;
}

struct MagGameFlags_AE78 {
    int m_unk00;
    int m_flags;
};
struct MagGameGlobals_AE78 {
    char m_unk0000[0xDC20];
    MagGameFlags_AE78 *m_flags;
};
extern MagGameGlobals_AE78 D_007A4440;
static inline bool hasFlag_AE78(int mask) {
    return D_007A4440.m_flags->m_flags & mask;
}
extern "C" void func_0019AE78(char *arg0)
{
    bool b1 = hasFlag_AE78(1);
    if (b1 == 1) {
        *(int *)(arg0 + 0x1570) = b1;
        *(int *)(arg0 + 0x1568) = b1;
    } else {
        *(int *)(arg0 + 0x1570) = 0;
        *(int *)(arg0 + 0x1568) = 0;
    }
    int f2 = D_007A4440.m_flags->m_flags & 2;
    if (f2) {
        bool b2 = f2;
        *(int *)(arg0 + 0x156C) = b2;
        *(int *)(arg0 + 0x1564) = b2;
    } else {
        *(int *)(arg0 + 0x156C) = 0;
        *(int *)(arg0 + 0x1564) = 0;
    }
    *(int *)(arg0 + 0x1560) = hasFlag_AE78(4);
}

extern "C" int func_0019AF08(int arg0, int arg1)
{
    switch (arg1) {                                 
    case 0xB3B:
        
    case 0xA00:
        return (int)&D_002A26B0;
    default:
        return (int)&D_002A2D80;
    }
}


extern "C" int func_0019AF34(MnuStock *arg0, int arg1)
{
    struct { unsigned short sp0; } stack;
    int temp_v0;

    (void)arg0;
    if ((arg1 == 0xA00) || (arg1 == 0xB3B)) {
        return 0;
    }
    char *base = (char *)&D_007812C0;
    X_func_001DC48C_DBC8(base + 0x22220, arg1 & 0xFFFF, 0xD, &stack);
    if (stack.sp0 != 0) {
        stack.sp0 += 0xFFFF;
    }
    temp_v0 = (stack.sp0 * 4) + 0x6D;
    return (temp_v0 >= 0x24F) ? 0x6D : temp_v0;
}

// NON_MATCHING: 11/28 differ (size 0x70, game 0x70), 13 edits
#ifdef NON_MATCHING
extern "C" int func_0019AFB0(MnuStock *self, int dir)
{
    if (self->m_stockCount >= 8) {
        switch (dir) {
        case 0:
            if (self->m_cursor[1] != self->m_cursor[3]) {
                return 1;
            }
            break;
        case 1: {
            int n = 7 - self->m_cursor[1];
            if (self->m_cursor[3] + n < self->m_stockCount - 1) {
                return 1;
            }
            break;
        }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019AFB0);
#endif

// NON_MATCHING: 188/194 differ, 17 relocs differ (size 0x308, game 0x364), 156 edits
#ifdef NON_MATCHING

extern char D_002A4300[] __attribute__((aligned(8)));
extern char D_002A42F0[];
extern char D_002F8470[];
extern char D_002999B0[], D_002999A0[];
struct DiaryB020Text { char text[29]; } __attribute__((packed));
struct DiaryB020Item { int m_unq,m_oid; unsigned short m_uid,m_num; int m_unk0c; };
struct DiaryB020Node { DiaryB020Node *prev,*next; int pad[2]; DiaryB020Item data; };
struct DiaryB020Iter { DiaryB020Node *p; DiaryB020Iter(DiaryB020Node *n=0):p(n) {} DiaryB020Iter(const DiaryB020Iter &o):p(o.p) {} DiaryB020Iter operator++(int) { DiaryB020Iter old(*this); p=p->next; return old; } };
extern "C" char *strcpy(char *,const char *);
inline DiaryB020Node *diaryBFirst(char *base) { return *(DiaryB020Node **)(base+0x1A7F4); }
inline DiaryB020Node *diaryBHead(char *base) { return (DiaryB020Node *)(base+0x1A7F0); }
extern "C" int diaryB020_func_0019E43C(int,int,int) asm("func_0019E43C");
extern "C" int diaryB020_func_0019AFB0(int,int) asm("func_0019AFB0");
extern "C" int diaryB020_func_0018F41C(int,int,int) asm("func_0018F41C");
extern "C" int diaryB020_func_0018F1F4(int,int,int,int,int,int,int,int) asm("func_0018F1F4");
inline void diaryBCopyTitle(char *dst,const char *src) { *(int *)(dst+0x28)=*(const int *)(src+8); *(long long *)(dst+0x20)=*(const long long *)src; }
inline void diaryBCopySeparator(char *dst,const char *src) { *(long long *)dst=*(const long long *)src; *(long long *)(dst+8)=*(const long long *)(src+8); dst[16]=src[16]; }
extern "C" void func_0019B020(MnuStock *self,int arg1) {
    int arg0=(int)self;
    DiaryB020Iter it, end;
    it = DiaryB020Iter(diaryBFirst((char *)&D_007812C0));
    end = DiaryB020Iter(diaryBHead((char *)&D_007812C0));
    int var_t2 = 1;
    static const char title[16] __attribute__((aligned(8))) = "Item Change";
    static const char separator[24] __attribute__((aligned(8))) = "----------------";
    diaryBCopyTitle(D_002A4300, title);
    diaryBCopySeparator(D_002A4300, separator);
    *(DiaryB020Text *)(D_002A4300+0xBA) = *(DiaryB020Text *)D_002F8470;
    M2C_FIELD(D_002A42F0, short *,8)=0xA00;
    M2C_FIELD(D_002A42F0,char **,0)=D_002A4300;
    M2C_FIELD(D_002A42F0,int *,4)=0;
    self->m_stockItems[0]=(GamItem *)D_002A42F0;
    DiaryB020Item **out=(DiaryB020Item **)&self->m_stockItems[1];
    while (it.p != end.p) {
        *out=0;
        if (arg1 != 0) {
            if (arg1 >= 0) {
                if (arg1 < 7 && arg1 == M2C_FIELD(it.p->data.m_unq, unsigned short *,0xB8)) { *out++=&it.p->data; ++var_t2; }
            }
        } else { ++var_t2; *out++=&it.p->data; }
        it++;
    }
    int temp_v1,temp_a2_2,temp_a0,temp_a1,temp_v1_2,var_v0;
    char *temp_s0;
    self->m_listCount = var_t2;
    self->m_stockCount = var_t2;
    if (self->m_cursor[1] >= self->m_max[1]) {
        self->m_cursor[1] = 0;
    }
    temp_v1 = self->m_cursor[1];
    if ((self->m_cursor[3] - temp_v1) < 0) {
        self->m_cursor[3] = temp_v1;
    }
    temp_a2_2 = self->m_cursor[1];
    temp_a0 = self->m_max[1];
    temp_a1 = self->m_stockCount;
    if (temp_a0 >= temp_a1) {
        self->m_cursor[3] = temp_a2_2;
        temp_v1_2 = self->m_stockCount;
        if (self->m_cursor[1] >= temp_v1_2) {
            self->m_cursor[1] = (int) (temp_v1_2 - 1);
            var_v0 = self->m_stockCount - 1;
            goto block_19;
        }
    } else if ((((self->m_cursor[3] - temp_a2_2) + temp_a0) - 1) >= temp_a1) {
        var_v0 = temp_a1 + (temp_a2_2 - temp_a0);
block_19:
        self->m_cursor[3] = var_v0;
    }
    temp_s0 = (char *)&self->m_rpk;
    M2C_FIELD(M2C_FIELD((int)temp_s0, char **, 0x4AC), int *, 0x4974) = (int) (diaryB020_func_0019E43C((int) arg0, self->m_cursor[3], self->m_stockCount) * 0x10);
    
    if (diaryB020_func_0019AFB0(arg0, 0) == 0) {
        if (M2C_FIELD(M2C_FIELD((int)temp_s0, char **, 0x4AC), int *, 0x4674) != 0) {
            diaryB020_func_0018F41C((int)temp_s0, 0x35, 0xA);
        }
    } else if ((M2C_FIELD(M2C_FIELD((int)temp_s0, char **, 0x4AC), int *, 0x4674) ^ 1) != 0) {
        diaryB020_func_0018F1F4((int)temp_s0, 0x35, self->m_unk1574, 0xA, 0, -1, (int)&D_002999B0, (int)&D_002999A0);
    }

    if (diaryB020_func_0019AFB0(arg0, 1) == 0) {
        if (M2C_FIELD(M2C_FIELD((int)temp_s0, char **, 0x4AC), int *, 0x47C8) != 0) {
            diaryB020_func_0018F41C((int)temp_s0, 0x36, 0xA);
        }
    } else if ((M2C_FIELD(M2C_FIELD((int)temp_s0, char **, 0x4AC), int *, 0x47C8) ^ 1) != 0) {
        diaryB020_func_0018F1F4((int)temp_s0, 0x36, self->m_unk1574, 0xA, 0, -1, (int)&D_002999B0, (int)&D_002999A0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019B020);
#endif

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8470);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8490);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8498);

// NON_MATCHING: 229/284 differ, 20 relocs differ (size 0x470, game 0x470), 136 edits
#ifdef NON_MATCHING
extern char D_002A4500[][3];
extern char D_002A2DA8[];
extern int D_002A42A8;
extern "C" void B384_func_0018C448(MnuRpk *, int, int) asm("func_0018C448");
extern "C" void B384_func_0018C4D8(MnuRpk *, int, int) asm("func_0018C4D8");
extern "C" int B384_func_001DD00C(void *, int, int) asm("func_001DD00C");
extern "C" int B384_sprintf(char *, const char *, ...) asm("func_00279C98");
extern "C" void func_0019B384(MnuStock *self, int idx)
{
    GamItemHave *have = D_007812C0.getItemHavePtr();
    GamItem *end = have->m_end;
    GamItem *it;
    int i;
    if (idx >= 0) {
        for (it = have->m_begin, i = 0; it != end; it++, i++) {
            if (i == idx) {
                self->m_haveItems[i] = it;
                break;
            }
        }
    } else if (idx == -1) {
        GamItem **dst = self->m_haveItems;
        for (it = have->m_begin; it != end; it++) {
            *dst++ = it;
        }
    }
    for (it = have->m_begin, i = 0; it != end; it++, i++) {
        GamItem *item;
        MnuRpk *rpk;
        int icon, num;
        char *text;
        item = self->m_haveItems[i];
        rpk = &self->m_rpk;
        icon = i + 0x4D;
        num = i + 0x59;
        if (item->m_uid != 0xA00) {
            B384_func_0018C448(rpk, icon, func_0019AF08((int)self, item->m_uid));
            rpk->m_sprTbl[icon].m_iconId = func_0019AF34(self, item->m_uid);
            B384_func_0018C4D8(rpk, icon, 0);
            rpk->m_sprTbl[icon].m_vis0C = 1;
            rpk->m_sprTbl[icon].m_vis10 = 1;
            B384_func_0018C448(rpk, num, (int)D_002A2DA8);
            rpk->m_sprTbl[num].m_iconId = i + 0x61;
            B384_func_0018C4D8(rpk, num, 0);
            rpk->m_sprTbl[num].m_vis0C = 1;
            rpk->m_sprTbl[num].m_vis10 = 1;
            rpk->m_sprTbl[num].m_color = &D_002A42A8;
            rpk->m_sprTbl[num].m_rgba[0] = 0x80;
            rpk->m_sprTbl[num].m_rgba[1] = 0x80;
            rpk->m_sprTbl[num].m_rgba[2] = 0x80;
            rpk->m_sprTbl[num].m_rgba[3] = 0x80;
            if (B384_func_001DD00C(gamSub22220_DEDC(), item->m_uid, 0x20000) != 0) {
                B384_sprintf(text = D_002A4500[i], "%2d", item->m_num);
                rpk->m_sprTbl[num].m_unk144 = 0;
                rpk->m_sprTbl[num].m_unk148 = 0;
                rpk->m_sprTbl[num].m_text = text;
                continue;
            }
            if (item->m_uid != 0xA3E && item->m_uid != 0xA43) {
                rpk->m_sprTbl[num].m_vis0C = 0;
                rpk->m_sprTbl[num].m_vis10 = 0;
                B384_sprintf(text = D_002A4500[i], "  ");
                rpk->m_sprTbl[num].m_unk144 = 0;
                rpk->m_sprTbl[num].m_unk148 = 0;
                rpk->m_sprTbl[num].m_text = text;
            } else {
                B384_sprintf(text = D_002A4500[i], "%2d", item->m_num);
                rpk->m_sprTbl[num].m_unk144 = 0;
                rpk->m_sprTbl[num].m_unk148 = 0;
                rpk->m_sprTbl[num].m_text = text;
            }
        } else {
            B384_func_0018C448(rpk, icon, func_0019AF08((int)self, 0xB3B));
            B384_func_0018C4D8(rpk, icon, 0);
            rpk->m_sprTbl[icon].m_vis0C = 0;
            rpk->m_sprTbl[icon].m_vis10 = 0;
            rpk->m_sprTbl[num].m_vis0C = 0;
            rpk->m_sprTbl[num].m_vis10 = 0;
            B384_sprintf(text = D_002A4500[i], "  ");
            rpk->m_sprTbl[num].m_unk144 = 0;
            rpk->m_sprTbl[num].m_unk148 = 0;
            rpk->m_sprTbl[num].m_text = text;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019B384);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019B7F4);

// NON_MATCHING: 25/80 differ, 1 reloc differs (size 0x140, game 0x144), 8 edits
#ifdef NON_MATCHING
struct Base1_BD6C {
    int m_00;
};
struct Base2_BD6C {
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    inline int getCount() { return m_20; }
};
struct Obj_BD6C : public Base1_BD6C, public Base2_BD6C {
    unsigned char pad30[0x10C4 - 0x30];
    int m_10C4[1];
};
extern "C" void X_func_0019B384_BD6C(void *, int) asm("func_0019B384");
extern "C" void X_func_0019DBC8_BD6C(void *, int, int) asm("func_0019DBC8");
extern "C" void X_func_0019DCBC_BD6C(void *, int, int, int) asm("func_0019DCBC");

extern "C" void func_0019BD6C(Obj_BD6C *arg0)
{
    int a = arg0->m_04;
    int idx = 0;

    if (a == 0) {
        idx = arg0->m_0C;
    } else if (arg0->m_28 >= arg0->m_20) {
        int *p10 = &arg0->m_0C;
        idx = *p10 - a;
        if (idx < 0) {
            *p10 = a;
            idx = 0;
        }
    }

    int i = 0;
    if (arg0->m_20 > 0) {
        do {
            if (i == 0) {
                int *p = &arg0->m_10C4[0];
                idx++;
                X_func_0019DBC8_BD6C(arg0, *p, 0);
                X_func_0019DCBC_BD6C(arg0, *p + 9, 0, 0);
            } else {
                int *p = &arg0->m_10C4[i];
                X_func_0019DBC8_BD6C(arg0, *p, idx);
                X_func_0019DCBC_BD6C(arg0, *p + 9, i, idx++);
            }
            i++;
        } while (i < arg0->getCount());
    }

    X_func_0019B384_BD6C(arg0, -2);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019BD6C);
#endif

extern "C" int func_0019BEB0(MnuStock *arg0, int arg1, int arg2) {
    int ret = 0;
    GamItem *p1110 = arg0->m_stockItems[arg2];
    if (p1110->m_uid == 0xA00) {
        GamItem *p1510 = arg0->m_haveItems[arg1];
        if (p1510->m_uid != 0xA00) {
            X_func_001C9198_BEB0(&D_007812C0, *p1510);
            ret = 1;
            X_func_001C8214_BEB0(&D_007812C0, arg1);
        }
    } else {
        GamItem item = *p1110;
        GamItem *p1510 = arg0->m_haveItems[arg1];
        if (p1510->m_uid != 0xA00) {
            if (p1110->m_uid != p1510->m_uid) {
                X_func_001C9198_BEB0(&D_007812C0, *p1510);
                X_func_001C8214_BEB0(&D_007812C0, arg1);
            }
        }
        ret = 1;
        X_func_001C94D8_BEB0(&D_007812C0, arg0->m_stockItems[arg2]->m_uid, 0);
        X_func_001C812C_BEB0(&D_007812C0, arg1, &item);
    }
    X_func_0019B020_BEB0(arg0, arg0->m_cursor[0]);
    X_func_0019B384_BEB0(arg0, arg0->m_cursor[2]);
    X_func_0019BD6C_BEB0(arg0);
    return ret;
}

extern "C" int func_0019C048(MnuStock *self, int uid)
{
    if (uid == 0xA00) {
        return -1;
    }
    for (int i = 0; i < 12; i++) {
        if (uid == self->m_haveItems[i]->m_uid) {
            return i;
        }
    }
    return -1;
}

extern "C" int func_0019C09C()
{
    char *base = (char *)&D_007812C0;
    __typeof__(base + 0x1A6C0) perm_e7 = 0x1A6C0 + base;
    __typeof__(perm_e7) perm_e5 = base + 0x1A6C0;
    __typeof__(0x1A6C0 + base) perm_e4 = perm_e5;
    __typeof__(0x1A6C0 + base) perm_e3 = perm_e4;
    __typeof__(base + 0x1A6C0) perm_e9 = base + 0x1A6C0;
    __typeof__(0x1A6C0 + base) perm_e10 = 0x1A6C0 + base;
    __typeof__(perm_e10) perm_e6 = perm_e9;
    __typeof__(perm_e6) perm_e2 = perm_e3;
    __typeof__(base + 0x1A6C0) perm_e8 = base + 0x1A6C0;
    __typeof__(perm_e8) perm_e0 = perm_e2;
    register GamItemHave * have PS2_REG("$2") = (GamItemHave *)(perm_e0);
    register int count PS2_REG("$6") = 0;
    __typeof__(have->m_end) perm_t1 = have->m_end;
    GamItem *it = have->m_begin;
    if (it != perm_t1) {
        do {
            if (it->m_uid != 0xA00) {
                count++;
            }
            it++;
        } while (it != perm_t1);
    }
    return count;
}

extern "C" void func_0019C0E4(MnuStock *arg0, int arg1)
{
    if (arg1 != 0) {
        return;
    }
    char *base = (char *)&D_007812C0;
    X_func_0019B384_BEB0(arg0, -1);
    arg0->m_equipIdx = func_0019C048(arg0, *(unsigned short *)(base + 0x2220C));
    arg0->m_findIdx = func_0019C048(arg0, *(unsigned short *)(base + 0x2220E));
    return func_0019B020(arg0, 0);
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019C16C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019C630);

extern "C" int func_0019CEAC(MnuStock *arg0)
{
    Xii_func_0018C068((int)&arg0->m_rpk);
    Xii_func_001874AC((int)arg0->m_msgs);
    bool ok = Xii_func_00131550((int)(arg0->m_magSys + 0x12540)) >= 5;
    if (ok == 1) {
        int *p = &D_007B2060_CEAC->m_flags;
        *p |= 0x40000000;
    }
    if (arg0->m_timer < 0x7FFF) {
        arg0->m_timer++;
        if (arg0->m_timer == 0xA) {
            arg0->m_unk1574 = 5;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019CF48);

extern "C" void func_0019DBC8(MnuStock *arg0, int arg1, int arg2)
{
    char *str = 0;
    MnuRpk *spr = &arg0->m_rpk;
    spr->m_sprTbl[arg1].m_color = &D_002A42C0;
    if (arg2 < arg0->m_listCount) {
        if (arg2 == 0) {
            str = (char *)arg0->m_stockItems[0]->m_unq;
        } else {
            X_func_001DC48C_DBC8(gamSub22220_DBC8(), arg0->m_stockItems[arg2]->m_uid, 0xC, &str);
        }
        spr->setText(arg1, str);
    }
}

// NON_MATCHING: 122/127 differ, 4 relocs differ (size 0x1FC, game 0x220), 99 edits
#ifdef NON_MATCHING
inline int diaryDiv(int n,int d) { return n/d; }
inline int diaryMod(int n,int d) { return n%d; }
extern char D_006E9408[][4];
extern "C" int diaryCount(void *,int,int) asm("func_001DD00C");
extern "C" void func_0019DCBC(MnuStock *self, int spr, int buf, int idx) {
    int temp_hi;
    int temp_hi_2;
    int temp_lo;
    int hundred = 100;
    int ten = 10;
    int temp_lo_2;
    unsigned short num;
    char *s;
    MnuRpk *rpk;

    if (idx >= self->m_listCount) {
        s = D_006E9408[buf];
        s[2] = ' ';
        rpk = &self->m_rpk;
        s[1] = ' ';
        s[0] = ' ';
        s[3] = 0;
        rpk->m_sprTbl[spr].m_unk144 = 0;
        rpk->m_sprTbl[spr].m_unk148 = 0;
        rpk->m_sprTbl[spr].m_text = s;
        return;
    }
    if (idx != 0) {
        GamItem *item = self->m_stockItems[idx];
        num = item->m_num;
        num = (diaryCount(gamSub22220_DEDC(), item->m_uid, 0x20000) == 0) ? 0 : num;
        num = ((int)num >= 100) ? 99 : num;
        temp_hi = diaryMod(num, hundred);
        temp_lo = diaryDiv(num, hundred);
        s = D_006E9408[buf];
        s[0] = 0;
        s[1] = 0;
        s[2] = 0;
        s[3] = 0;
        temp_hi_2 = diaryMod(num, ten);
        temp_lo_2 = diaryDiv(temp_hi, ten);
        s[0] = ' ';
        if (temp_lo_2 == 0) {
            if (temp_lo == 0) {
                D_006E9408[buf][0] = ' ';
                if (temp_hi_2 == 0) {
                    D_006E9408[buf][1] = ' ';
                } else {
                    D_006E9408[buf][1] = temp_hi_2 + '0';
                }
            } else {
                D_006E9408[buf][0] = '0';
            }
        } else {
            s = D_006E9408[buf];
            s[0] = temp_lo_2 + '0';
            s[1] = temp_hi_2 + '0';
        }
        rpk = &self->m_rpk;
        rpk->m_sprTbl[spr].m_unk144 = 0;
        rpk->m_sprTbl[spr].m_unk148 = 0;
        rpk->m_sprTbl[spr].m_text = D_006E9408[buf];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019DCBC);
#endif

extern "C" char *func_0019DEDC(MnuStock *arg0, unsigned short arg1)
{
    char *p = 0;
    void *base = gamSub22220_DBC8();
    (void)arg0;
    if (X_func_001DD00C_DEDC(base, arg1, 4) != 0) {
        X_func_001DC48C_DBC8(base, arg1, 0xC, &p);
    } else {
        p = D_002A42E0;
    }
    if (p == 0) {
        p = D_002F84B8;
    }
    return p;
}

extern "C" void func_0019DF78(char *dst, char *src)
{
    char *start = dst;
    while (*src != 0 && (unsigned int)(dst - start) < 0x100) {
        char c = *src;
        if (c == '#') {
            *dst++ = *src;
            src++;
            if (*src++ == 'n') {
                *dst++ = '0';
            } else {
                *dst++ = *src;
            }
        } else {
            *dst++ = *src;
            src++;
        }
    }
}

// NON_MATCHING: 181/263 differ, 20 relocs differ (size 0x41C, game 0x42C), 105 edits
#ifdef NON_MATCHING

extern char diaryEBlank[] asm("D_002A42D0");
inline char *diaryEUnq(char *p) { return p+0x22220; }
extern "C" int diaryE_func_001DC48C(char *,int,int,void *) asm("func_001DC48C");
extern "C" void * diaryE_memset(void *,int,unsigned int) asm("memset");
extern "C" void diaryE_func_0019DF78(char *,char *) asm("func_0019DF78");
extern "C" void diaryE_func_0018EBA4(int,char *,char *,int) asm("func_0018EBA4");
extern "C" char * diaryE_func_0019DEDC(int,int) asm("func_0019DEDC");
extern "C" void diaryE_func_0018EC58(int,char *) asm("func_0018EC58");
extern "C" void diaryE_func_0018C4D8(char *,int,int) asm("func_0018C4D8");
inline char *diaryESub(char *p) { return p+0x7D0; }
inline unsigned short diaryEId(char *p) { return *(unsigned short *)(p+8); }
extern "C" void func_0019E010(char *arg0, char *arg1) {
    short sp0;
    char *sp4;                                        /* compiler-managed */
    char sp10[256];
    char *temp_s0;
    char *temp_v0_2;
    char *temp_v0_3;
    char *temp_v0_4;
    unsigned short temp_v0;
    char *temp_s5;
    char *temp_s6;
    char *temp_s7;
    char *temp_s4;
    int one;

    temp_s4 = diaryESub(arg0);
    ((MnuRpk *)temp_s4)->m_sprTbl[0x3E].m_color = diaryEBlank;
    ((MnuRpk *)temp_s4)->m_sprTbl[0x3F].m_color = diaryEBlank;
    ((MnuRpk *)temp_s4)->m_sprTbl[0x40].m_color = diaryEBlank;
    ((MnuRpk *)temp_s4)->m_sprTbl[0x42].m_color = diaryEBlank;
    if (arg1 != 0) {
        temp_v0 = diaryEId(arg1);
        if (temp_v0 != 0xA00) {
            diaryE_func_001DC48C(diaryEUnq((char *)&D_007812C0), (int) temp_v0, 0x25, &sp4);
            one = 1;
            diaryE_memset(sp10, 0, 0x100);
            temp_s5 = arg0 + 0xE38;
            temp_s6 = arg0 + 0xEB8;
            temp_s7 = arg0 + 0xF38;
            func_0019DF78(sp10, sp4);
            diaryE_func_0018EBA4((int) temp_s4, (char *) sp10, arg0 + 0xCB8, 0);
            diaryE_func_0018EBA4((int) temp_s4, (char *) sp10, arg0 + 0xD38, 1);
            diaryE_func_0018EBA4((int) temp_s4, (char *) sp10, arg0 + 0xDB8, 2);
            diaryE_func_001DC48C(diaryEUnq((char *)&D_007812C0), (int) diaryEId(arg1), 0x10, &sp0);
            if (((MnuStock *)arg0)->m_flg2B == one) {
                if (sp0 != 0xA00) {
                    temp_v0_2 = func_0019DEDC((MnuStock *)arg0, (unsigned short)sp0);
                    sp4 = temp_v0_2;
                    diaryE_func_0018EBA4((int)temp_s4, temp_v0_2, temp_s5, 0);
                } else {
                    diaryE_func_0018EBA4((int)temp_s4, (char *)" ", temp_s5, 0);
                }
                diaryE_func_001DC48C(diaryEUnq((char *)&D_007812C0), (int) diaryEId(arg1), 17, &sp0);
                if (sp0 != 0xA00) {
                    temp_v0_3 = func_0019DEDC((MnuStock *)arg0, (unsigned short)sp0);
                    sp4 = temp_v0_3;
                    diaryE_func_0018EBA4((int)temp_s4, temp_v0_3, temp_s6, 0);
                } else {
                    diaryE_func_0018EBA4((int)temp_s4, (char *)" ", temp_s6, 0);
                }
                diaryE_func_001DC48C(diaryEUnq((char *)&D_007812C0), (int) diaryEId(arg1), 18, &sp0);
                temp_s0 = diaryESub(arg0);
                if (sp0 != 0xA00) {
                    temp_v0_4 = func_0019DEDC((MnuStock *)arg0, (unsigned short)sp0);
                    sp4 = temp_v0_4;
                    diaryE_func_0018EBA4((int)temp_s0, temp_v0_4, temp_s7, 0);
                } else {
                    diaryE_func_0018EBA4((int)temp_s0, (char *)" ", temp_s7, 0);
                }
            } else {
                temp_s0 = (char *)" ";
                diaryE_func_0018EBA4((int)temp_s4, temp_s0, temp_s5, 0);
                diaryE_func_0018EBA4((int)temp_s4, temp_s0, temp_s6, 0);
                diaryE_func_0018EBA4((int)temp_s4, temp_s0, temp_s7, 0);
            }
            temp_s0 = diaryESub(arg0);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x3E].m_unk144 = 0;
            ((MnuRpk *)temp_s0)->m_sprTbl[0x3E].m_unk148 = 0;
            ((MnuRpk *)temp_s0)->m_sprTbl[0x3E].m_text = (char *) (arg0 + 0xE38);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x3F].m_unk144 = 0;
            ((MnuRpk *)temp_s0)->m_sprTbl[0x3F].m_unk148 = 0;
            ((MnuRpk *)temp_s0)->m_sprTbl[0x3F].m_text = (char *) (arg0 + 0xEB8);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x40].m_unk144 = 0;
            ((MnuRpk *)temp_s0)->m_sprTbl[0x40].m_unk148 = 0;
            ((MnuRpk *)temp_s0)->m_sprTbl[0x40].m_text = (char *) (arg0 + 0xF38);
            diaryE_func_001DC48C(diaryEUnq((char *)&D_007812C0), (int) diaryEId(arg1), 0xC, &sp4);
            diaryE_func_0018EC58((int) temp_s0, (char *) sp4);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x42].m_unk144 = 0;
            ((MnuRpk *)temp_s0)->m_sprTbl[0x42].m_unk148 = 0;
            ((MnuRpk *)temp_s0)->m_sprTbl[0x42].m_text = sp4;
            diaryE_func_0018C4D8(temp_s0, 0x43, 0);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x43].m_vis0C = one;
            diaryE_func_0018C4D8(temp_s0, 0x44, 0);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x44].m_vis0C = one;
            diaryE_func_0018C4D8(temp_s0, 0x45, 0);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x45].m_vis0C = one;
            diaryE_func_0018C4D8(temp_s0, 0x3E, 0);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x3E].m_vis0C = one;
            diaryE_func_0018C4D8(temp_s0, 0x3F, 0);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x3F].m_vis0C = one;
            diaryE_func_0018C4D8(temp_s0, 0x40, 0);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x40].m_vis0C = one;
            diaryE_func_0018C4D8(temp_s0, 0x42, 0);
            ((MnuRpk *)temp_s0)->m_sprTbl[0x42].m_vis0C = one;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019E010);
#endif

extern "C" int func_0019E43C(int arg0, int arg1, int arg2)
{
    int temp_a2;
    int var_v1;

    temp_a2 = arg2 - 1;
    var_v1 = 0x69;
    if (temp_a2 > 0) {
        var_v1 = ((int) (arg1 * 0x89) / temp_a2) + 0x69;
    }
    return var_v1;
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019E474);

extern "C" void func_0019FADC(MnuStock *arg0, int arg1)
{
    switch (arg1) {
    case 0:
        ((MnuStockCursor *)&arg0->m_cursor[2])->snapRowStart();
        break;
    case 1:
        ((MnuStockCursor *)&arg0->m_cursor[2])->snapRowEnd();
        break;
    }
}

extern "C" int func_0019FB88(MnuStock *self, int uid, int arg2)
{
    register int ret PS2_REG("$2") = 0;
    (void)self;
    if (uid != 0xA00) {
        ret = X_func_001DD00C_DEDC(gamSub22220_DBC8(), (unsigned short)uid, arg2);
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019FBC8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84A8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84B8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84C0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84D0);
