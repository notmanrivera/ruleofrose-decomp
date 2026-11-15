#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00198318);

extern "C" int func_00198420(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x12C)) + (arg1 << 5);
    return (*(int *)(int *)((char *)(temp_v1) + 0x10)) < (*(int *)(int *)((char *)((((*(int *)(int *)((char *)(temp_v1) + 0xC)) * 0x10) + (*(int *)(int *)((char *)(arg0) + 0x9C)))) + 0x4));
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019844C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_001985B0);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_01);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8190);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_03);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00198CA8);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00198EB4);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F8228);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019946C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00199714);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00199A08);

extern "C" void func_00199AB4(void *arg0, int arg1, int arg2)
{
    int idx = X_func_0019A24C_9AB4(arg0, arg1);
    UnkHdr_9AB4 **p = X_func_0022AED8_9AB4(*(char **)(*(char **)((char *)arg0 + 0x94) + 0xA0) + 0x10, arg2 != 0);
    (*func_0022AAD0(p, 0))->unk1C = (*(Elem10_9AB4 **)((char *)arg0 + 0xA4))[idx].unk08;
    (*p)->unk08++;
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_00199B3C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", MnuDiary__vfunc_06);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019A054);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019A290);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019A3C0);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019BD6C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019BEB0);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019DBC8);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019DCBC);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019FADC);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019FB88);

INCLUDE_ASM("asm/nonmatchings/unk/MnuDiary", func_0019FBC8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84A8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84B8);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84C0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuDiary", D_002F84D0);
