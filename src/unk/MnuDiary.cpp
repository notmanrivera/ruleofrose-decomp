#include "include_asm.h"
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
struct Sub110_v2 {
    int unk00;
    int unk04;
    int unk08;
};
struct Obj_v2 {
    unsigned char unk00[0x04];
    int m_04;
    unsigned char unk08[0x0C];
    int m_14;
    unsigned char unk18[0x0C];
    char m_24[0x40];
    unsigned char unk64[0xA8];
    void *m_10C;
    Sub110_v2 *m_110;
    int m_114;
    int m_118;
    int m_11C;
    int m_120;
    int m_124;
    int m_128;
    int m_12C;
    int m_130;
    int m_134;
    void *m_138;
    unsigned char unk13C[0x778];
    int m_8B4;
    void *m_8B8;
};
struct VBase_v2 {
    unsigned char pad[0x10C];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};
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
struct Item_BEB0 {
    int m_unq;
    int m_oid;
    unsigned short m_uid;
    unsigned short m_num;
    int m_unk0C;
};
struct Obj_BEB0 {
    unsigned char unk00[0x04];
    int m_04;
    unsigned char unk08[0x04];
    int m_0C;
    unsigned char unk10[0x1100];
    Item_BEB0 *m_1110[0x100];
    Item_BEB0 *m_1510[0x100];
};
extern int D_007812C0_BEB0 asm("D_007812C0");
extern "C" int X_func_001C9198_BEB0(void *, Item_BEB0) asm("func_001C9198");
extern "C" void X_func_001C8214_BEB0(void *, int) asm("func_001C8214");
extern "C" void X_func_001C94D8_BEB0(void *, int, int) asm("func_001C94D8");
extern "C" void X_func_001C812C_BEB0(void *, int, Item_BEB0 *) asm("func_001C812C");
extern "C" void X_func_0019B020_BEB0(void *, int) asm("func_0019B020");
extern "C" void X_func_0019B384_BEB0(void *, int) asm("func_0019B384");
extern "C" void X_func_0019BD6C_BEB0(void *) asm("func_0019BD6C");
struct Sub110_85B0 {
    int unk00;
    int unk04;
};
struct Entry_85B0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct Obj_85B0 {
    unsigned char pad00[0x110];
    Sub110_85B0 *m_110;
    unsigned char pad114[0x18];
    Entry_85B0 *m_12C;
    unsigned char pad130[0x08];
    int m_138;
    char *m_13C;
    unsigned char m_140[4];
};
extern "C" {
void *X_memset_85B0(void *, int, int) asm("memset");
int X_strlen_85B0(const char *) asm("strlen");
void *X_memcpy_85B0(void *, const void *, int) asm("memcpy");
char *X_func_001832E8_85B0(int) asm("func_001832E8");
void X_func_001874F4_85B0(void *, int, char *, int) asm("func_001874F4");
}
struct Sub110_A3C0 {
    int unk00;
    int unk04;
};
struct Obj_A3C0 {
    unsigned char pad00[0x110];
    Sub110_A3C0 *m_110;
    unsigned char pad114[0x134 - 0x114];
    int m_134;
    char *m_138;
    unsigned char m_13C[4];
};
extern "C" void *X_memset_A3C0(void *, int, unsigned int) asm("memset");
extern "C" void *X_memcpy_A3C0(void *, const void *, unsigned int) asm("memcpy");
extern "C" unsigned int X_strlen_A3C0(const char *) asm("strlen");
extern "C" int X_strcmp_A3C0(const char *, const char *) asm("strcmp");
extern "C" char *X_func_001832E8_A3C0(int) asm("func_001832E8");
extern "C" void X_func_001874F4_A3C0(void *, int, char *, int) asm("func_001874F4");
extern "C" char D_002F8228[];
struct Entry_844C {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct Obj_844C {
    unsigned char pad00[0x12C];
    Entry_844C *m_12C;
};
extern "C" int X_func_00279C98_844C(char *, const char *, int) asm("func_00279C98");
extern "C" int X_func_00194404_844C(void *, int, int) asm("func_00194404");
extern "C" void X_func_0019397C_844C(void *, char *, int, int) asm("func_0019397C");
extern "C" int X_func_00279C98_A290(char *, const char *, int) asm("func_00279C98");
extern "C" int X_func_0019A24C_A290(void *, int) asm("func_0019A24C");
extern "C" int X_func_00194404_A290(void *, int, int) asm("func_00194404");
extern "C" int X_func_0019397C_A290(void *, char *, int, int) asm("func_0019397C");
struct SprElem_DBC8 {
    unsigned char unk00[0x144];
    int unk144;
    int unk148;
    char *unk14C;
    void *unk150;
};
struct Spr_DBC8 {
    unsigned char unk00[0x4AC];
    SprElem_DBC8 *m_4AC;
    inline void set(int idx, char *str) {
        m_4AC[idx].unk144 = 0x20;
        m_4AC[idx].unk148 = 0;
        m_4AC[idx].unk14C = str;
    }
};
struct Item_DBC8 {
    char *unk00;
    int unk04;
    unsigned short unk08;
};
struct Obj_DBC8 {
    unsigned char unk000[0x7D0];
    Spr_DBC8 m_spr;
    unsigned char unkC80[0x1110 - 0xC80];
    Item_DBC8 *m_1110[1];
    unsigned char unk1114[0x1544 - 0x1114];
    int m_1544;
};
extern int D_002A42C0;
extern int D_007812C0_DBC8 asm("D_007812C0");
extern "C" void X_func_001DC48C_DBC8(void *, int, int, void *) asm("func_001DC48C");
static inline void *gamSub22220_DBC8() { void *p = &D_007812C0_DBC8; return (char *)p + 0x22220; }
extern "C" void X_func_00194688_v3(int) asm("func_00194688");
extern "C" void X_func_00193868_v3(void *) asm("func_00193868");
extern "C" void X_func_001348B0_v3(int, int) asm("func_001348B0");
extern "C" void X_func_00187464_v3(void *) asm("func_00187464");
extern "C" void X_mnuBase__vfunc_03_v3(void *) asm("mnuBase__vfunc_03");
extern "C" void X_MnuDiary__vfunc_03_v1(void *) asm("MnuDiary__vfunc_03");
extern "C" void X___builtin_delete_v1(void *) asm("__builtin_delete");
extern "C" void X_func_00183B24_v1(void *, int) asm("func_00183B24");
extern "C" void X_mnuBase__vfunc_01_v1(void *, int) asm("mnuBase__vfunc_01");
extern int vtbl_MnuDiary_v1 asm("_vt$8MnuDiary");
struct Sub_FADC {
    int m_00;
    inline void func0() {
        int v = m_00;
        if (v >= 0 && v <= 3) {
            m_00 = 0;
        } else if (v >= 4 && v <= 7) {
            m_00 = 4;
        } else if (v >= 8 && v <= 11) {
            m_00 = 8;
        }
    }
    inline void func1() {
        int v = m_00;
        if (v >= 0 && v <= 3) {
            m_00 = 3;
        } else if (v >= 4 && v <= 7) {
            m_00 = 7;
        } else if (v >= 8 && v <= 11) {
            m_00 = 11;
        }
    }
};
extern "C" int X_func_0019A20C_9A08(void *, int) asm("func_0019A20C");
struct Elem20_9A08 {
    char *unk00;
    int pad[7];
};
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
struct Base_8720 {
    int m_00;
    unsigned char m_pad04[0x108];
    virtual void vfunc0();
    Base_8720() asm("func_00192AC0");
};
struct Msg_8720 {
    unsigned char m_unk[0x3BC];
    Msg_8720() asm("func_0018330C");
};
inline void *operator new(unsigned int, void *p) { return p; }
struct MnuDiary : public Base_8720 {
    int m_110;
    int m_114;
    int m_118;
    int m_11C;
    int m_120;
    int m_124;
    int m_128;
    int m_12C;
    int m_130;
    int m_134;
    int m_138;
    unsigned char m_msgs[2*0x3BC];
    int m_8B4;
    int m_8B8;
    void vfunc0();
    MnuDiary() asm("func_00198720");
};
extern "C" void X_func_0019B384_C0E4(void *, int) asm("func_0019B384");
extern "C" int func_0019C048(void *, unsigned short);
extern "C" void func_0019B020(void *, int);
struct Elem10_9AB4 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
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
struct SubA4_v7 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
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
extern int D_0029C368;
extern int D_002A26B0;
extern int D_002A2D80;
extern int D_006E9840;
extern int D_007812C0;
extern int D_007B2060;

// NON_MATCHING: 57/62 differ, 2 relocs differ (size 0xF8, game 0x108), 41 edits
#ifdef NON_MATCHING
extern "C" int X_func_00198420_8318(void *, int) asm("func_00198420");
extern "C" int func_00198318(MnuDiary *arg0, int arg1)
{
    int m128 = arg0->m_128;
    int idx;
    if (arg1 != 0) {
        int page = (m128 >= 0) ? (m128 / 2) : -1;
        idx = page + 1;
        if (idx >= arg0->m_130) {
            return 0;
        }
        if (X_func_00198420_8318(arg0, idx) != 0) {
            return 0;
        }
        idx = page + 2;
        if (idx >= arg0->m_130) {
            return 1;
        }
    } else {
        int page = (m128 >= 0) ? (m128 / 2) : -1;
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
    int flags = *(int *)(arg0->m_12C + idx * 0x20);
    if ((flags & 5) != 1 && (flags & 0xA) != 2) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00198318);
#endif

extern "C" int func_00198420(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x12C)) + (arg1 << 5);
    return (*(int *)(int *)((char *)(temp_v1) + 0x10)) < (*(int *)(int *)((char *)((((*(int *)(int *)((char *)(temp_v1) + 0xC)) * 0x10) + (*(int *)(int *)((char *)(arg0) + 0x9C)))) + 0x4));
}


extern "C" void func_0019844C(Obj_844C *arg0, int arg1, int arg2, int arg3)
{
    char buf[32];
    Entry_844C *e = &arg0->m_12C[arg1];
    int page = (arg1 >= 0) ? (arg1 * 2) : -1;
    int var_a1 = 2;
    if (arg2 != 0 && e->unk04 == -1 && !(e->unk00 & 4)) {
        e->unk04 = X_func_00194404_844C(arg0, 2, 0x21);
        if (e->unk00 & 0x10) {
            X_func_00279C98_844C(buf, "pb_pagebrk%02d_tcc", page);
        } else {
            X_func_00279C98_844C(buf, "pb_page%02d_tcc", page);
        }
        X_func_0019397C_844C(arg0, buf, 4, e->unk04);
        var_a1 = e->unk04 + 1;
    }
    if (arg3 != 0 && e->unk08 == -1 && !(e->unk00 & 8)) {
        e->unk08 = X_func_00194404_844C(arg0, var_a1, 0x21);
        if (e->unk00 & 0x20) {
            X_func_00279C98_844C(buf, "pb_pagebrk%02d_tcc", page + 1);
        } else {
            X_func_00279C98_844C(buf, "pb_page%02d_tcc", page + 1);
        }
        X_func_0019397C_844C(arg0, buf, 4, e->unk08);
    }
}

extern "C" void func_001985B0(Obj_85B0 *arg0, int arg1) {
    int idx = (arg1 >= 0) ? (arg1 / 2) : -1;
    Entry_85B0 *e = &arg0->m_12C[idx];
    X_memset_85B0(arg0->m_13C, 0, 0x200);
    __builtin_memcpy(arg0->m_13C, "#r#L#T#f00#w001#F20", 20);
    if (arg1 >= 0 && !(e->unk00 & 0x28)) {
        char *s1 = X_func_001832E8_85B0(arg0->m_110->unk04 + arg1);
        char *dst = arg0->m_13C + X_strlen_85B0(arg0->m_13C);
        X_memcpy_85B0(dst, s1, X_strlen_85B0(s1));
    }
    arg1++;
    e++;
    if (arg1 >= 0 && !(e->unk00 & 0x14)) {
        char *s2 = X_func_001832E8_85B0(arg0->m_110->unk04 + arg1);
        char *dst = arg0->m_13C + X_strlen_85B0(arg0->m_13C);
        X_memcpy_85B0(dst, s2, X_strlen_85B0(s2));
    }
    X_func_001874F4_85B0(arg0->m_140, arg0->m_138, arg0->m_13C, 0);
}

MnuDiary::MnuDiary()
{
    int i = 1;
    Msg_8720 *p = (Msg_8720 *)m_msgs;
    do { new (p) Msg_8720; p++; } while (--i != -1);
    m_130 = -1;
    m_134 = -1;
    m_114 = -1;
    m_118 = -1;
    m_11C = -1;
    m_00 = 7;
    m_128 = 0;
    m_138 = 0;
    m_110 = 0;
    m_8B8 = 0;
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

extern "C" void MnuDiary__vfunc_02(Obj_v2 *arg0, int arg1) {
    X_func_00192BA4_v2(arg0, arg1, 0x10, 6, 2, 0x13);
    arg0->m_118 = X_func_001D83D0_v2(&D_007812C0_v2, 1, arg0->m_114, 0);
    int v = sysWork_v2()[X_func_001D83D0_v2(&D_007812C0_v2, 1, arg0->m_114, 4)];
    arg0->m_04 |= 0x40000;
    arg0->m_11C = v;
    arg0->m_124 = sysWork_v2()[X_func_001D83D0_v2(&D_007812C0_v2, 1, arg0->m_114, 7)] & ~1;
    arg0->m_8B8 = X_func_00194588_v2(0x4C);
    X_memset_v2(arg0->m_8B8, -1, 0x4C);
    int pages = (arg0->m_110->unk08 / 2) + 1;
    arg0->m_8B4 = 0;
    arg0->m_04 |= 2;
    arg0->m_120 = 0;
    arg0->m_14 = 0;
    arg0->m_12C = pages;
    arg0->m_138 = X_func_00194588_v2(0x4C8);
    __builtin_memcpy(arg0->m_24, "data/mnurpk/mnupbook/mnupbook.rpk", 34);
    ((VBase_v2 *)arg0)->v10();
    X_func_0019397C_v2(arg0, "ehonbg", 4, 1);
    X_func_0019397C_v2(arg0, "ehontex01_tcc", 4, 0);
}

extern "C" void MnuDiary__vfunc_03(MnuDiary *arg0)
{
    if (arg0->m_138 != 0) {
        X_func_00194688_v3(arg0->m_138);
        arg0->m_138 = 0;
    }
    if (arg0->m_128 != 0) {
        X_func_00194688_v3(arg0->m_128);
        arg0->m_128 = 0;
    }
    arg0->m_12C = 0;
    if (arg0->m_8B8 != 0) {
        X_func_00194688_v3(arg0->m_8B8);
        arg0->m_8B8 = 0;
    }
    X_func_00193868_v3(arg0);
    if (arg0->m_130 != -1) {
        X_func_001348B0_v3(*(int *)((char *)arg0 + 8), arg0->m_130);
        arg0->m_130 = -1;
    }
    if (arg0->m_134 != -1) {
        X_func_001348B0_v3(*(int *)((char *)arg0 + 8), arg0->m_134);
        arg0->m_134 = -1;
    }
    X_func_00187464_v3(arg0->m_msgs);
    arg0->m_110 = 0;
    arg0->m_114 = -1;
    arg0->m_118 = -1;
    arg0->m_11C = -1;
    X_mnuBase__vfunc_03_v3(arg0);
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00198B04);

extern "C" void func_00198B54(int arg0)
{
    struct { char pad0[32]; } stack;
    int temp_v0;
    int var_v1;
    int temp_s0;
    int var_a0;

    temp_v0 = Xii_func_00194588(0xA0);
    M2C_FIELD(arg0, int *, 0x128) = temp_v0;
    var_v1 = temp_v0;
    var_a0 = 4;
    do {
        var_a0 -= 1;
        M2C_FIELD(var_v1, int *, 0) = 0;
        M2C_FIELD(var_v1, int *, 8) = -1;
        M2C_FIELD(var_v1, int *, 4) = -1;
        M2C_FIELD(var_v1, int *, 0xC) = -1;
        M2C_FIELD(var_v1, int *, 0x10) = 0;
        var_v1 += 0x20;
    } while (var_a0 >= 0);
    Xiiiii_func_0019397C(arg0, (int) (int) "a_diary", 4, 2);
    X_func_00279C98((int)&stack, (int) "%s_base.i3s", M2C_FIELD(arg0, int *, 0x110) + 0xC);
    Xiiiii_func_0019397C(arg0, (int) (int)&stack, 1, 5);
    temp_s0 = (int) (M2C_FIELD(arg0, int *, 0x124) + 1) / 2;
    Xiii_func_0019A290(arg0, temp_s0 - 1);
    Xiii_func_0019A290(arg0, temp_s0);
    X_func_00279C98((int)&stack, (int) "%s01_base.i3s", M2C_FIELD(arg0, int *, 0x110) + 0xC);
    Xiiiii_func_0019397C(arg0, (int) (int)&stack, 1, 0);
    X_func_00279C98((int)&stack, (int) "%s01_turn_r.i3s", M2C_FIELD(arg0, int *, 0x110) + 0xC);
    Xiiiii_func_0019397C(arg0, (int) (int)&stack, 2, 0);
    X_func_00279C98((int)&stack, (int) "%s01_turn_l.i3s", M2C_FIELD(arg0, int *, 0x110) + 0xC);
    Xiiiii_func_0019397C(arg0, (int) (int)&stack, 2, 1);
}

// NON_MATCHING: 80/132 differ, 11 relocs differ (size 0x210, game 0x20C), 14 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_0019381C(int) asm("func_0019381C");
extern "C" int Xii_func_0019A1D0(int) asm("func_0019A1D0");
extern "C" int Xiiff_func_00192E94(int, float, float) asm("func_00192E94");
extern "C" int Xiiii_func_00193FEC(int, int, int) asm("func_00193FEC");
extern "C" int Xiiii_func_00194148(int, int, int) asm("func_00194148");
extern "C" int Xiiii_func_00199AB4(int, int, int) asm("func_00199AB4");
extern "C" int Xiiiii_func_00199A08(int, int, int, int) asm("func_00199A08");
extern "C" void func_00198CA8(int arg0)
{
    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int temp_s1;
    int temp_s3;
    int doubled;
    int temp_v1;
    int var_s2;
    int var_s2_2;
    unsigned int temp_s0;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    int var_a1;

    var_s2 = 1;
    Xiiff_func_00192E94(arg0, 512.0f, 0.785398080945015f);
    Xii_func_0019381C(arg0);
    var_a1 = (int) 1;
    do {
        var_s2 += 1;
        Xiiii_func_00194148(arg0, var_a1, 0);
        var_a1 = (int) var_s2;
    } while (var_s2 < 5);
    var_s2_2 = 0;
    if (M2C_FIELD(arg0, int *, 0xA0) > 0) {
        do {
            temp_v1 = var_s2_2 * 0x10;
            var_s2_2 += 1;
            temp_v1_2 = temp_v1 + M2C_FIELD(arg0, int *, 0x9C);
            M2C_FIELD(temp_v1_2, int *, 4) = (int) (M2C_FIELD(temp_v1_2, int *, 4) * 2);
        } while (var_s2_2 < M2C_FIELD(arg0, int *, 0xA0));
    }
    temp_s0 = M2C_FIELD(arg0, int *, 0x124) + 1;
    temp_s0_2 = temp_s0 + (temp_s0 >> 0x1F);
    var_s2 = Xii_func_0019A1D0(arg0);
    temp_s0_3 = temp_s0_2 >> 1;
    temp_v1_3 = M2C_FIELD(arg0, int *, 0x128) + (var_s2 << 5);
    temp_s1 = temp_s0_3 - 1;
    M2C_FIELD(temp_v1_3, int *, 0xC) = 1;
    M2C_FIELD(temp_v1_3, int *, 0x14) = temp_s1;
    M2C_FIELD(temp_v1_3, int *, 0) = (int) (M2C_FIELD(temp_v1_3, int *, 0) | 3);


    M2C_FIELD(temp_v1_3, int *, 0x10) = (int) M2C_FIELD(M2C_FIELD(arg0, int *, 0x9C), int *, 0x14);
    temp_s3 = temp_s0_3 * 2;
    Xiiii_func_00193FEC(arg0, var_s2, 1);
    doubled = temp_s1 * 2;
    Xiiiii_func_00199A08(arg0, temp_s1, doubled + 1, 0);
    Xiiiii_func_00199A08(arg0, temp_s1, doubled + 2, 1);
    var_s2 = Xii_func_0019A1D0(arg0);
    temp_v1_4 = M2C_FIELD(arg0, int *, 0x128) + (var_s2 << 5);
    M2C_FIELD(temp_v1_4, int *, 0x14) = temp_s0_3;
    M2C_FIELD(temp_v1_4, int *, 0xC) = 0;
    M2C_FIELD(temp_v1_4, int *, 0) = (int) (M2C_FIELD(temp_v1_4, int *, 0) | 3);
    M2C_FIELD(temp_v1_4, int *, 0x10) = (int) M2C_FIELD(M2C_FIELD(arg0, int *, 0x9C), int *, 4);
    Xiiii_func_00193FEC(arg0, var_s2, 0);
    Xiiiii_func_00199A08(arg0, temp_s0_3, temp_s3 + 1, 0);
    Xiiiii_func_00199A08(arg0, temp_s0_3, temp_s3 + 2, 1);
    Xiiii_func_00199AB4(arg0, M2C_FIELD(arg0, int *, 0x124), 0);
    Xiiii_func_00199AB4(arg0, M2C_FIELD(arg0, int *, 0x124) + 1, 1);
    temp_s0_4 = (int) (M2C_FIELD(arg0, int *, 0x124) + 1) / 2;
    Xiii_func_0019A290(arg0, temp_s0_4 + 1);
    Xiii_func_0019A290(arg0, temp_s0_4 - 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00198CA8);
#endif

extern "C" void func_00198EB4(int arg0)
{
    int temp_v0_2;
    int temp_v0_3;
    int temp_s2;
    int temp_v0;

    temp_s2 = arg0 + 0x13C;
    temp_v0 = M2C_FIELD(arg0, int *, 0x138);
    *(DiaryRGB *)temp_v0 = *(DiaryRGB *)&D_002F8228;
    Xii_func_0018741C(temp_s2);
    temp_v0_2 = Xiiiiii_func_00134730(M2C_FIELD(arg0, int *, 8), 0x200, 0x100, 0, -1);
    M2C_FIELD(arg0, int *, 0x134) = temp_v0_2;
    Xiiuiii_func_00134A00((int) M2C_FIELD(arg0, int *, 8), (unsigned int) temp_v0_2, 0, 0x20, 0x7FFF);
    Xiiuiiii_func_00134CD0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 0, 0, 0x200, 0x100);
    Xiiuii_func_00134AB8((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 0x200, 0x100);
    Xiiui_func_00135494((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 1);
    Xiiui_func_00135418((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 0);
    Xiiui_func_001351B0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 0);
    Xiiu_func_00135594(M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134));
    Xiii_func_0019A3C0(arg0, M2C_FIELD(arg0, int *, 0x124));
    Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 4, 0xDC, 0x198);
    Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 4, 0);
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 0, 0);
    Xii_func_0018741C(temp_s2);
    temp_v0_3 = Xiiiiii_func_00134730(M2C_FIELD(arg0, int *, 8), 0x40, 0x20, 0, -1);
    M2C_FIELD(arg0, int *, 0x130) = temp_v0_3;
    Xiiuiii_func_00134A00((int) M2C_FIELD(arg0, int *, 8), (unsigned int) temp_v0_3, 0xF6, 0x19A, 0x7FFF);
    Xiiuiiii_func_00134CD0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x130), 0, 0, 0x40, 0x20);
    Xiiui_func_00135494((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x130), 1);
    Xiiui_func_00135418((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x130), 0);
    Xiiui_func_001351B0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x130), 1);
    Xiiu_func_00135594(M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x130));
    int texture = Xiu_func_001832E8(0x1AU);
    diaryAttach(temp_s2, M2C_FIELD(arg0, int *, 0x130), texture, 0);
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8228);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_05);

// NON_MATCHING: 18/169 differ (size 0x2A4, game 0x2A8), 6 edits
#ifdef NON_MATCHING
inline int diaryPressed(unsigned int bits) { return (bits >> 13) & 1; }
inline void diaryTick(unsigned int *counter) { *counter = (*counter + 1) % 300U; }
extern "C" float Xfi_getLeftX__C6BedPad(int) asm("getLeftX__C6BedPad");
extern "C" int Xiii_func_0017F8FC(int, int) asm("func_0017F8FC");
extern "C" int Xiii_func_0019A054(int, int) asm("func_0019A054");
extern "C" int Xiiii_func_00199B3C(int, int, int) asm("func_00199B3C");
extern int D_007B2580;
extern "C" int func_0019946C(int arg0, int arg1)
{
    int temp_v0;
    int temp_v0_3;
    int temp_v1;
    unsigned int temp_a1;

    if (M2C_FIELD(arg0, int *, 4) & 0x40000) {
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 1, 0);
        Xiiui_func_001351B0(M2C_FIELD(arg0, int *, 8), M2C_FIELD(arg0, unsigned int *, 0x130), 0);
    }
    temp_v0 = M2C_FIELD(arg0, int *, 0x120);

    if (temp_v0 > 0) {
        temp_v0 -= 1;
        M2C_FIELD(arg0, int *, 0x120) = temp_v0;
        if (temp_v0 == 0) {
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) & 0xFFE7FFFD);
            Xiii_func_0019A3C0(arg0, M2C_FIELD(arg0, int *, 0x124));
            if ((M2C_FIELD(arg0, int *, 0x124) + 1) >= M2C_FIELD(arg0, int *, 0x11C)) {
                M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x40000);
            }
        }
    }
    Xii_func_001874AC(arg0 + 0x13C);
    temp_v1 = M2C_FIELD(arg0, int *, 4);
    if (!(temp_v1 & 2)) {
        if (diaryPressed(M2C_FIELD(arg1, unsigned short *, 0x7A)) && (temp_v1 & 0x40000)) {
            Xiiui_func_001351B0(M2C_FIELD(arg0, int *, 8), M2C_FIELD(arg0, unsigned int *, 0x134), 1);
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 2);
            return 0;
        }
        if (M2C_FIELD(arg0, int *, 0x120) == 0) {
            if (((((unsigned short) M2C_FIELD(arg1, unsigned short *, 0x78) >> 5) & 1 & 0xFFFF) || (Xfi_getLeftX__C6BedPad((int) arg1) >= 0.75f)) && (Xiii_func_0019A054(arg0, 1) != 0)) {
                temp_v0_3 = M2C_FIELD(arg0, int *, 0x124);
                temp_a1 = temp_v0_3 + 3;
                M2C_FIELD(arg0, int *, 0x124) = (int) (temp_v0_3 + 2);
                Xiiii_func_00199B3C(arg0, ((int) (temp_a1 + (temp_a1 >> 0x1F)) >> 1) - 1, 1);
                M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x100002);
                Xiii_func_0017F8FC((int) (int)&D_007B2580, 8);
                Xiii_func_0019A3C0(arg0, -1);
            } else if (((((unsigned short) M2C_FIELD(arg1, unsigned short *, 0x78) >> 7) & 1 & 0xFFFF) || (Xfi_getLeftX__C6BedPad((int) arg1) <= -0.75f)) && (Xiii_func_0019A054(arg0, 0) != 0)) {
                Xiiii_func_00199B3C(arg0, ((int) (M2C_FIELD(arg0, int *, 0x124) + 1) / 2) - 1, 0);
                M2C_FIELD(arg0, int *, 0x124) = (int) (M2C_FIELD(arg0, int *, 0x124) - 2);
                M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x80002);
                Xiii_func_0017F8FC((int) (int)&D_007B2580, 8);
                Xiii_func_0019A3C0(arg0, -1);
            }
        }

    }
    if (M2C_FIELD(arg0, int *, 4) & 2) {
        M2C_FIELD(arg0, unsigned int *, 0x8B4) = (M2C_FIELD(arg0, unsigned int *, 0x8B4) + 1) % 300U;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019946C);
#endif

// NON_MATCHING: 178/184 differ, 9 relocs differ (size 0x2E0, game 0x2F4), 136 edits
#ifdef NON_MATCHING
extern "C" int Xiii_func_00194370(int, int) asm("func_00194370");
extern "C" int Xiii_func_0019A20C(int, int) asm("func_0019A20C");
extern "C" int Xiii_func_0019A24C(int, int) asm("func_0019A24C");
extern "C" int diary99714_AB4(int, int, int) asm("func_00199AB4");
extern "C" void func_00199714(int arg0)
{
    int var_v1;
    int temp_a0;
    int temp_a0_2;
    int temp_a1;
    int temp_a1_2;
    int temp_a1_3;
    int temp_a1_4;
    int temp_a1_5;
    int temp_a2;
    int temp_s0;
    int var_a1;
    int var_a1_2;
    int var_a1_3;
    int var_a1_4;
    int var_s2;
    int var_v0;
    int temp_v0;
    int temp_v1;
    int var_s3;

    temp_v0 = M2C_FIELD(arg0, int *, 0x128);
    var_s3 = temp_v0;
    if (temp_v0 != 0) {
        var_s2 = 4;
        do {
            bool disabled = !(M2C_FIELD(var_s3, int *, 0) & 1);
            if (!disabled) {
                temp_a2 = M2C_FIELD(var_s3, int *, 0xC);
                temp_a0 = M2C_FIELD(var_s3, int *, 0x10);
                temp_v1 = M2C_FIELD(arg0, int *, 0x9C) + (temp_a2 * 0x10);
                if (temp_a0 < M2C_FIELD(temp_v1, int *, 4)) {
                    temp_a0_2 = temp_a0 + 1;
                    M2C_FIELD(var_s3, int *, 0x10) = temp_a0_2;
                    temp_s0 = M2C_FIELD(temp_v1, int *, 4) - temp_a0_2;
                    if (temp_s0 == 0) {
                        temp_a1 = M2C_FIELD(var_s3, int *, 0x14);
                        if (!(temp_a2 & 1)) {
                            diary99714_AB4(arg0, (temp_a1 * 2) + 1, 1);
                        } else {
                            diary99714_AB4(arg0, (temp_a1 * 2) + 2, 0);
                        }
                    } else if (temp_s0 == 4) {
                        temp_a1_2 = M2C_FIELD(var_s3, int *, 0x14);
                        temp_s0 = Xiii_func_0019A20C(arg0, (((temp_a2 & 1) ^ 0) != 0) ? (temp_a1_2 - 1) : (temp_a1_2 + 1));
                        if (temp_s0 != -1) {
                            var_v1 = (temp_s0 << 5) + M2C_FIELD(arg0, int *, 0x128);
                            var_v0 = (*(int *)(var_v1)) & ~3;
                            goto block_14;
                        }
                    } else if (temp_a0_2 == 4) {
                        temp_a1_3 = M2C_FIELD(var_s3, int *, 0x14);
                        temp_s0 = Xiii_func_0019A20C(arg0, (((temp_a2 & 1) ^ 0) != 0) ? (temp_a1_3 + 1) : (temp_a1_3 - 1));
                        if (temp_s0 != -1) {
                            var_v1 = (temp_s0 << 5) + M2C_FIELD(arg0, int *, 0x128);
                            var_v0 = (*(int *)(var_v1)) | 2;
block_14:
                            (*(int *)(var_v1)) = var_v0;
                        }
                    }
                }
            }
            var_s2 -= 1;
            var_s3 += 0x20;
        } while (var_s2 >= 0);
        var_s2 = ((int) (M2C_FIELD(arg0, int *, 0x124) + 1) / 2) - 2;
        if (var_s2 >= -1) {
            var_a1 = var_s2;
loop_18:
            temp_a1_4 = var_s2 - 1;
            if (Xiii_func_0019A20C(arg0, var_a1) == -1) {
                var_s2 = (temp_a1_4 * 2) + 2;
                if (var_s2 >= 0) {
                    var_a1_2 = var_s2;
                    do {
                        var_s2 -= 1;
                        temp_s0 = Xiii_func_0019A24C(arg0, var_a1_2);
                        var_s3 = -1;
                        if (temp_s0 != var_s3) {
                            Xiii_func_00194370(arg0, temp_s0);
                            *(int *)((temp_s0 * 4) + M2C_FIELD(arg0, int *, 0x8B8)) = var_s3;
                        }
                        var_a1_2 = var_s2;
                    } while (var_s2 >= 0);
                }
            } else {
                var_s2 = temp_a1_4;
                var_a1 = var_s2;
                if (var_s2 >= -1) {
                    goto loop_18;
                }
            }
        }
        var_s2 = ((int) (M2C_FIELD(arg0, int *, 0x124) + 1) / 2) + 1;
        if (var_s2 < M2C_FIELD(arg0, int *, 0x12C)) {
            var_a1_3 = var_s2;
loop_28:
            temp_a1_5 = var_s2 + 1;
            if (Xiii_func_0019A20C(arg0, var_a1_3) == -1) {
                var_s2 = (temp_a1_5 * 2) + 1;
                if (var_s2 < M2C_FIELD(M2C_FIELD(arg0, int *, 0x110), int *, 8)) {
                    var_a1_4 = var_s2;
                    do {
                        var_s2 += 1;
                        temp_s0 = Xiii_func_0019A24C(arg0, var_a1_4);
                        var_s3 = -1;
                        if (temp_s0 != var_s3) {
                            Xiii_func_00194370(arg0, temp_s0);
                            *(int *)((temp_s0 * 4) + M2C_FIELD(arg0, int *, 0x8B8)) = var_s3;
                        }
                        var_a1_4 = var_s2;
                    } while (var_s2 < M2C_FIELD(M2C_FIELD(arg0, int *, 0x110), int *, 8));
                }
            } else {
                var_s2 = temp_a1_5;
                var_a1_3 = var_s2;
                if (var_s2 >= M2C_FIELD(arg0, int *, 0x12C)) {

                } else {
                    goto loop_28;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00199714);
#endif

extern "C" void func_00199A08(void *arg0, int arg1, int arg2, int arg3)
{
    int idx1 = X_func_0019A20C_9A08(arg0, arg1);
    int idx2 = X_func_0019A24C_9AB4(arg0, arg2);
    UnkHdr_9AB4 **p = X_func_0022AED8_9AB4((*(Elem20_9A08 **)((char *)arg0 + 0x94))[idx1].unk00 + 0x10, arg3 != 0);
    (*func_0022AAD0(p, 0))->unk1C = (*(Elem10_9AB4 **)((char *)arg0 + 0xA4))[idx2].unk08;
    (*p)->unk08++;
}

extern "C" void func_00199AB4(void *arg0, int arg1, int arg2)
{
    int idx = X_func_0019A24C_9AB4(arg0, arg1);
    UnkHdr_9AB4 **p = X_func_0022AED8_9AB4(*(char **)(*(char **)((char *)arg0 + 0x94) + 0xA0) + 0x10, arg2 != 0);
    (*func_0022AAD0(p, 0))->unk1C = (*(Elem10_9AB4 **)((char *)arg0 + 0xA4))[idx].unk08;
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
extern "C" void MnuDiary__vfunc_06(int arg0, int arg1)
{
    struct { float sp0; float sp4; float sp8; float spC; float sp10; float sp14; float sp18; float sp1C; float sp20; float sp24; float sp28; float sp2C; float sp30; char pad34[12]; DiaryV6Pair vec; int sp50; char pad54[44]; float sp80; float sp84; float sp88; } stack;
    float temp_f0;
    float temp_f0_2;
    int var_s1;
    int var_s0;

    if ((unsigned int) (M2C_FIELD(arg0, int *, 0x10) - 2) < 3U) {
        Xiii_func_00192F68(arg0, arg1);
        Xiii_func_00193210(arg0, 1);
        stack.sp0 = 0.0f;
        stack.sp8 = 512.0f;
        stack.spC = 448.0f;
        stack.sp1C = 0.875f;


        stack.sp18 = stack.sp2C = stack.sp28 = stack.sp24 = stack.sp20 = 1.0f;
        Xiiiff_func_00193258(arg0, stack.sp4 = stack.sp30 = stack.sp10 = stack.sp14 = stack.sp0, stack.sp0, (int)&stack);
        Xiii_func_00193210(arg0, 0);
        if ((M2C_FIELD(arg0, int *, 0x124) - 1) >= 0) {
            if (M2C_FIELD(arg0, int *, 4) & 0x80000) {
                var_s1 = (unsigned int) ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x8B4) >> 1) % 3U;
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
            Xiiiff_func_00193258(arg0, 100.0f, 412.0f, (int)&stack);
        }
        if ((M2C_FIELD(arg0, int *, 0x124) + 2) < M2C_FIELD(M2C_FIELD(arg0, int *, 0x110), int *, 8)) {
            if (M2C_FIELD(arg0, int *, 4) & 0x100000) {
                var_s1 = (unsigned int) ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x8B4) >> 1) % 3U;
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
            Xiiiff_func_00193258(arg0, 384.0f, 412.0f, (int)&stack);
        }
        var_s1 = 0;
        M2C_FIELD(arg0, int *, 0xB0) = X_func_0021B550(M2C_FIELD(arg0, int *, 0xB0), 0x47, 0x503FD);
        Xiii_func_001930F8(arg0, arg1);
        stack.vec = *(DiaryV6Pair *)&D_002F8270;
        X_func_00237340((int)&stack.sp50);
        X_func_002378B0((int)&stack.sp50, (int)&stack.sp50, (int)&stack.vec);
        stack.sp80 = 21.0f;
        stack.sp84 = 8.0f;
        stack.sp88 = 220.0f;
        Xiiiiiii_func_0019368C(arg0, arg1, (int)&stack.sp50, 5, -1, 0);
        var_s0 = M2C_FIELD(arg0, int *, 0x128);
        do {
            if (M2C_FIELD(var_s0, int *, 0) & 2) {
                Xiiiiiii_func_0019368C(arg0, arg1, (int)&stack.sp50, var_s1, M2C_FIELD(var_s0, int *, 0xC), M2C_FIELD(var_s0, int *, 0x10));
            }
            var_s1 += 1;
            var_s0 += 0x20;
        } while (var_s1 < 5);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_06);
#endif

extern "C" void MnuDiary__vfunc_07(void *arg0, int arg1)
{
    int arr[16];
    Arg223558_v7 q;
    SubA4_v7 *p1;
    SubA4_v7 *p2;
    int v;

    p1 = *(SubA4_v7 **)((char *)arg0 + 0xA4);
    arr[0] = p1[0].unk08;
    p1[0].unk0C = 0;
    p2 = *(SubA4_v7 **)((char *)arg0 + 0xA4);
    arr[1] = p2[1].unk08;
    {
        register int one PS2_REG("$6") = 1;
        p2[1].unk0C = one;
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
    *(int *)((char *)arg0 + 0xAC) = v;
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
        idx = (arg0->m_124 + 1) / 2;
        if (idx >= arg0->m_12C) {
            return 0;
        }
        if (X_func_0019A174_A054(arg0, idx) != 0) {
            return 0;
        }
        idx++;
        if (idx >= arg0->m_12C) {
            return 1;
        }
        return tail_A054(arg0, idx * 2 + 1);
    } else {
        page = (arg0->m_124 + 1) / 2;
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

extern "C" int func_0019A174(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = X_func_0019A20C();
    if (temp_v0 != -1) {
        temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x128)) + (temp_v0 << 5);
        return (*(int *)(int *)((char *)(temp_v1) + 0x10)) < (*(int *)(int *)((char *)((((*(int *)(int *)((char *)(temp_v1) + 0xC)) * 0x10) + (*(int *)(int *)((char *)(arg0) + 0x9C)))) + 0x4));
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019A1D0);

extern "C" int func_0019A20C(int arg0, int arg1)
{
    int *p = (int *)M2C_FIELD(arg0, int *, 0x128);
    int i = 0;

    for (;;) {
        if (M2C_FIELD(p, int *, 0) & 1) {
            if (M2C_FIELD(p, int *, 0x14) == arg1) {
                return i;
            }
        }
        i += 1;
        if (i < 5) {
            p += 8;
            continue;
        }
        return -1;
    }
}

extern "C" int func_0019A24C(int arg0, int arg1)
{
    for (int i = 0; i < M2C_FIELD(arg0, int *, 0xA8); i++) {
        if (M2C_FIELD(M2C_FIELD(arg0, int *, 0x8B8) + i * 4, int *, 0) == arg1) {
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

    page = arg1 * 2 + 1;
    if (page >= 0 && page < (*(int **)((char *)arg0 + 0x110))[2] && X_func_0019A24C_A290(arg0, page) == -1) {
        idx = X_func_00194404_A290(arg0, 3, 0x12);
        ((int *)arg0->m_8B8)[idx] = page;
        X_func_00279C98_A290(buf, "dy_page%02d_tcc", page);
        X_func_0019397C_A290(arg0, buf, 4, idx);
    }
    page++;
    if (page >= 0 && page < (*(int **)((char *)arg0 + 0x110))[2] && X_func_0019A24C_A290(arg0, page) == -1) {
        idx = X_func_00194404_A290(arg0, 3, 0x12);
        ((int *)arg0->m_8B8)[idx] = page;
        X_func_00279C98_A290(buf, "dy_page%02d_tcc", page);
        X_func_0019397C_A290(arg0, buf, 4, idx);
    }
}

extern "C" void func_0019A3C0(Obj_A3C0 *arg0, int arg1)
{
    X_memset_A3C0(arg0->m_138, 0, 0x4C8);
    __builtin_memcpy(arg0->m_138, "#r#L#T#[50#]50#f00#w001#F20", 28);
    if (arg1 >= -1) {
        char *s1 = X_func_001832E8_A3C0(arg0->m_110->unk04 + arg1 - 1);
        if (s1 != 0 && X_strcmp_A3C0(s1, D_002F8228) != 0) {
            X_strlen_A3C0(s1);
            char *dst = arg0->m_138 + X_strlen_A3C0(arg0->m_138);
            X_memcpy_A3C0(dst, s1, X_strlen_A3C0(s1));
        }
        char *s2 = X_func_001832E8_A3C0(arg0->m_110->unk04 + arg1);
        if (s2 != 0) {
            X_strlen_A3C0(s2);
            char *dst = arg0->m_138 + X_strlen_A3C0(arg0->m_138);
            X_memcpy_A3C0(dst, s2, X_strlen_A3C0(s2));
        }
    }
    X_func_001874F4_A3C0(arg0->m_13C, arg0->m_134, arg0->m_138, 0);
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

extern "C" void func_0019A650(int arg0, int arg1)
{
    int var_s2 = 1;

    if (M2C_FIELD(arg0, int *, 0x1540) == 0) {
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        Xiii_func_0018BCC0(arg0 + 0x7D0, 0x8A);
        M2C_FIELD(arg0, int *, 0xBEC) = arg1;
        Xii_func_0019A780(arg0);
        M2C_FIELD(arg0, int *, 0x1540) = var_s2;
        M2C_FIELD(arg0, int *, 0x156C) = var_s2;
    }
}

extern "C" void func_0019A6B8(int arg0)
{
    int temp_s0;

    if (M2C_FIELD(arg0, int *, 0x1540) != 0) {
        Xii_func_0018C130(arg0 + 0x7D0);
        temp_s0 = (int)&D_006E9840;
        temp_s0 += 0x12540;
        Xiiu_func_00135594(temp_s0, M2C_FIELD(arg0, unsigned int *, 0x1580));
        Xiiu_func_001348B0(temp_s0, M2C_FIELD(arg0, unsigned int *, 0x1580));
        Xii_func_00187464(arg0 + 0x58);
        Xii_func_0019A7D8(arg0);
        M2C_FIELD(arg0, int *, 0x1540) = 0;
    }
}

extern "C" int func_0019A730(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x1540));
}


extern "C" void func_0019A738(void) {
}

extern "C" int func_0019A740()
{
    return X_func_0019A824();
}


extern "C" void func_0019A754(int arg0, int arg1)
{
    int temp_v0;

    temp_v0 = arg0 + 0x7D0;
    (*(int *)(int *)((char *)(arg0) + 0x10C0)) = arg1;
    if (arg1 != 0) {
        (*(int *)(int *)((char *)(temp_v0) + 0x4D0)) = arg1;
        X_func_0018BD94(temp_v0);
    }
}


extern "C" int func_0019A780(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0) == 1) {
        return -1;
    }
    M2C_FIELD(arg0, int *, 0) = 1;
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    M2C_FIELD(arg0, int *, 0x54) = 3;
    M2C_FIELD(arg0, int *, 0x40) = 0;
    M2C_FIELD(arg0, int *, 0x44) = 0;
    M2C_FIELD(arg0, int *, 0x154C) = -1;
    M2C_FIELD(arg0, int *, 0x1550) = -1;
    Xii_func_0018741C(arg0 + 0x58);
    return 0;
}

extern "C" int func_0019A7D8(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0) == 0) {
        return -1;
    }
    Xiii_func_0019C0E4(arg0, 1);
    M2C_FIELD(arg0, int *, 0) = 0;
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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019AE20);

// NON_MATCHING: 4/36 differ, 4 edits
#ifdef NON_MATCHING
struct MagGameFlags_AE78 {
    int m_unk00;
    int m_flags;
};
struct MagGameGlobals_AE78 {
    unsigned char m_unk0000[0xDC20];
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
        *(int *)(arg0 + 0x1568) = 0;
        *(int *)(arg0 + 0x1570) = 0;
    }
    int f2 = D_007A4440.m_flags->m_flags & 2;
    if (f2) {
        bool b2 = f2;
        *(int *)(arg0 + 0x156C) = b2;
        *(int *)(arg0 + 0x1564) = b2;
    } else {
        *(int *)(arg0 + 0x1564) = 0;
        *(int *)(arg0 + 0x156C) = 0;
    }
    *(int *)(arg0 + 0x1560) = hasFlag_AE78(4);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019AE78);
#endif

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


extern "C" int func_0019AF34(int arg0, int arg1)
{
    struct { unsigned short sp0; } stack;
    int temp_v0;

    (void)arg0;
    if ((arg1 == 0xA00) || (arg1 == 0xB3B)) {
        return 0;
    }
    char *base = (char *)&D_007812C0;
    X_func_001DC48C(base + 0x22220, arg1 & 0xFFFF, 0xD, &stack);
    if (stack.sp0 != 0) {
        stack.sp0 += 0xFFFF;
    }
    temp_v0 = (stack.sp0 * 4) + 0x6D;
    return (temp_v0 >= 0x24F) ? 0x6D : temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019AFB0);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019B020);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8470);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8490);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8498);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019B384);

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

extern "C" int func_0019BEB0(Obj_BEB0 *arg0, int arg1, int arg2) {
    int ret = 0;
    Item_BEB0 *p1110 = arg0->m_1110[arg2];
    if (p1110->m_uid == 0xA00) {
        Item_BEB0 *p1510 = arg0->m_1510[arg1];
        if (p1510->m_uid != 0xA00) {
            X_func_001C9198_BEB0(&D_007812C0_BEB0, *p1510);
            ret = 1;
            X_func_001C8214_BEB0(&D_007812C0_BEB0, arg1);
        }
    } else {
        Item_BEB0 item = *p1110;
        Item_BEB0 *p1510 = arg0->m_1510[arg1];
        if (p1510->m_uid != 0xA00) {
            if (p1110->m_uid != p1510->m_uid) {
                X_func_001C9198_BEB0(&D_007812C0_BEB0, *p1510);
                X_func_001C8214_BEB0(&D_007812C0_BEB0, arg1);
            }
        }
        ret = 1;
        X_func_001C94D8_BEB0(&D_007812C0_BEB0, arg0->m_1110[arg2]->m_uid, 0);
        X_func_001C812C_BEB0(&D_007812C0_BEB0, arg1, &item);
    }
    X_func_0019B020_BEB0(arg0, arg0->m_04);
    X_func_0019B384_BEB0(arg0, arg0->m_0C);
    X_func_0019BD6C_BEB0(arg0);
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019C048);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019C09C);

extern "C" void func_0019C0E4(void *arg0, int arg1)
{
    if (arg1 != 0) {
        return;
    }
    char *base = (char *)&D_007812C0;
    X_func_0019B384_C0E4(arg0, -1);
    *(int *)((char *)arg0 + 0x154C) = func_0019C048(arg0, *(unsigned short *)(base + 0x2220C));
    *(int *)((char *)arg0 + 0x1550) = func_0019C048(arg0, *(unsigned short *)(base + 0x2220E));
    return func_0019B020(arg0, 0);
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019C16C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019C630);

extern "C" int func_0019CEAC(int arg0)
{
    Xii_func_0018C068(arg0 + 0x7D0);
    Xii_func_001874AC(arg0 + 0x58);
    bool ok = Xii_func_00131550(M2C_FIELD(arg0, int *, 0x10BC) + 0x12540) >= 5;
    if (ok == 1) {
        int *p = &D_007B2060_CEAC->m_flags;
        *p |= 0x40000000;
    }
    if (M2C_FIELD(arg0, int *, 0x157C) < 0x7FFF) {
        M2C_FIELD(arg0, int *, 0x157C)++;
        if (M2C_FIELD(arg0, int *, 0x157C) == 0xA) {
            M2C_FIELD(arg0, int *, 0x1574) = 5;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019CF48);

extern "C" void func_0019DBC8(Obj_DBC8 *arg0, int arg1, int arg2)
{
    char *str = 0;
    Spr_DBC8 *spr = &arg0->m_spr;
    spr->m_4AC[arg1].unk150 = &D_002A42C0;
    if (arg2 < arg0->m_1544) {
        if (arg2 == 0) {
            str = arg0->m_1110[0]->unk00;
        } else {
            X_func_001DC48C_DBC8(gamSub22220_DBC8(), arg0->m_1110[arg2]->unk08, 0xC, &str);
        }
        spr->set(arg1, str);
    }
}

// NON_MATCHING: 119/124 differ, 4 relocs differ (size 0x1F0, game 0x220), 99 edits
#ifdef NON_MATCHING
inline int diaryDiv(int n,int d) { return n/d; }
inline int diaryMod(int n,int d) { return n%d; }
extern int D_006E9408[];
extern "C" int diaryCount(int,int,int) asm("func_001DD00C");
extern "C" void func_0019DCBC(int arg0, int arg1, int arg2, int arg3) {
    int *temp_a1;
    int *temp_a3;
    int *temp_a5;
    int temp_hi;
    int temp_hi_2;
    int temp_lo;
    int hundred = 100;
    int ten = 10;
    int temp_lo_2;
    int temp_v1;
    int temp_v1_2;
    unsigned short temp_s0;
    unsigned short temp_s0_2;
    unsigned short temp_s0_3;
    int temp_a0;
    int temp_a2;
    void *temp_v0;

    if (arg3 >= M2C_FIELD(arg0, int *, 0x1544)) {
        temp_a3 = &D_006E9408[arg2];
        M2C_FIELD(temp_a3, signed char *, 2) = 0x20;
        temp_a0 = arg0 + 0x7D0;
        M2C_FIELD(temp_a3, signed char *, 1) = 0x20;
        temp_v1 = arg1 * 0x154;
        M2C_FIELD(temp_a3, signed char *, 0) = 0x20;
        M2C_FIELD(temp_a3, signed char *, 3) = 0;
        M2C_FIELD((temp_v1 + M2C_FIELD(temp_a0, int *, 0x4AC)), int *, 0x144) = 0;
        M2C_FIELD((temp_v1 + M2C_FIELD(temp_a0, int *, 0x4AC)), int *, 0x148) = 0;
        M2C_FIELD((temp_v1 + M2C_FIELD(temp_a0, int *, 0x4AC)), int **, 0x14C) = temp_a3;
        return;
    }
    if (arg3 != 0) {
        temp_v0 = M2C_FIELD(((arg3 * 4) + arg0), void **, 0x1110);
        temp_s0 = M2C_FIELD(temp_v0, unsigned short *, 0xA);
        temp_s0_2 = (diaryCount((int)((char *)&D_007812C0) + 0x22220, (int) M2C_FIELD(temp_v0, unsigned short *, 8), 0x20000) == 0) ? 0 : temp_s0;
        temp_s0_3 = ((int) temp_s0_2 >= 0x64) ? 0x63 : temp_s0_2;
        temp_hi = diaryMod(temp_s0_3, hundred);
        temp_lo = diaryDiv(temp_s0_3, hundred);
        temp_a5 = &D_006E9408[arg2];
        M2C_FIELD(temp_a5, signed char *, 0) = 0;
        M2C_FIELD(temp_a5, signed char *, 1) = 0;
        M2C_FIELD(temp_a5, signed char *, 2) = 0;
        M2C_FIELD(temp_a5, signed char *, 3) = 0;
        temp_hi_2 = diaryMod(temp_s0_3, ten);
        temp_lo_2 = diaryDiv(temp_hi, ten);
        M2C_FIELD(temp_a5, signed char *, 0) = 0x20;
        if (temp_lo_2 == 0) {
            if (temp_lo == 0) {
                M2C_FIELD(&D_006E9408[arg2], signed char *, 0) = 0x20;
                if (temp_hi_2 == 0) {
                    M2C_FIELD(&D_006E9408[arg2], signed char *, 1) = 0x20;
                } else {
                    M2C_FIELD(&D_006E9408[arg2], signed char *, 1) = (signed char) (temp_hi_2 + 0x30);
                }
            } else {
                M2C_FIELD(&D_006E9408[arg2], signed char *, 0) = 0x30;
            }
        } else {
            temp_a1 = &D_006E9408[arg2];
            M2C_FIELD(temp_a1, signed char *, 0) = (signed char) (temp_lo_2 + 0x30);
            M2C_FIELD(temp_a1, signed char *, 1) = (signed char) (temp_hi_2 + 0x30);
        }
        temp_a2 = arg0 + 0x7D0;
        temp_v1_2 = arg1 * 0x154;
        M2C_FIELD((temp_v1_2 + M2C_FIELD(temp_a2, int *, 0x4AC)), int *, 0x144) = 0;
        M2C_FIELD((temp_v1_2 + M2C_FIELD(temp_a2, int *, 0x4AC)), int *, 0x148) = 0;
        M2C_FIELD((temp_v1_2 + M2C_FIELD(temp_a2, int *, 0x4AC)), int **, 0x14C) = &D_006E9408[arg2];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019DCBC);
#endif

extern "C" char *func_0019DEDC(int arg0, unsigned short arg1)
{
    char *p = 0;
    void *base = gamSub22220_DEDC();
    (void)arg0;
    if (X_func_001DD00C_DEDC(base, arg1, 4) != 0) {
        X_func_001DC48C_DEDC(base, arg1, 0xC, &p);
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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019E010);

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

extern "C" void func_0019FADC(char *arg0, int arg1)
{
    switch (arg1) {
    case 0:
        ((Sub_FADC *)(arg0 + 0xC))->func0();
        break;
    case 1:
        ((Sub_FADC *)(arg0 + 0xC))->func1();
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019FB88);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019FBC8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84A8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84B8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84C0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84D0);
