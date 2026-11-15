#include "include_asm.h"
struct Sub154_C068 {
    int unk00;
    unsigned char pad04[0x150];
};
struct Obj_C068 {
    unsigned char pad000[4];
    int unk04;
    unsigned char pad008[0x4AC - 8];
    int unk4AC;
    int unk4B0;
    int unk4B4;
};
extern "C" void Xv_func_0018DF20(Obj_C068 *, Sub154_C068 *) asm("func_0018DF20");
struct Arg223558 {
    float unk00;
    void *unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct Sub4D0_EF40 {
    int a[2];
    int b;
    int c[2];
};
struct Obj_EF40 {
    unsigned char pad000[0x130];
    int unk130;
    int unk134;
    unsigned char pad138[0x4D0 - 0x138];
    Sub4D0_EF40 unk4D0;
};
extern "C" int Xii_func_00223558(int, Arg223558 *) asm("func_00223558");
extern "C" void Xii_func_00223228(int, int) asm("func_00223228");
extern "C" int Xif_func_00223298(int, float) asm("func_00223298");
extern "C" void Xv_func_0018D7EC(int, int, int, int, int, int) asm("func_0018D7EC");
extern "C" int Xiiiiii_func_001BEDC0(int, int, int, int, int) asm("func_001BEDC0");
extern "C" int Xiiiiii_func_001BEF24(int, int, int, int, int) asm("func_001BEF24");
extern "C" int Xiii_func_0018C9D8(int, int) asm("func_0018C9D8");
extern "C" int Xiii_func_0018C910(int, int) asm("func_0018C910");
struct Entry28_C5A8 {
    unsigned short unk00;
    unsigned char unk02[0x1A];
};
struct EntryC_C5A8 {
    int unk00;
    int unk04;
    Entry28_C5A8 *unk08;
};
struct Sub154_C5A8 {
    unsigned char pad00[0xF4];
    int unkF4;
    int unkF8;
    unsigned char padFC[0x14];
    int unk110;
    int unk114;
    int unk118;
    unsigned char pad11C[0x1C];
    EntryC_C5A8 *unk138;
    unsigned char pad13C[0x18];
};
struct Obj_C5A8 {
    unsigned char pad000[0x4AC];
    Sub154_C5A8 *unk4AC;
};
extern "C" int Xiii_func_0018CA58(int, int) asm("func_0018CA58");
extern "C" int Xiii_func_0018C990(int, int) asm("func_0018C990");
extern "C" int Xii_func_0018F824(int) asm("func_0018F824");
extern "C" int Xii_heapFree__FPv(int) asm("heapFree__FPv");
extern "C" int Xiii_func_0018D08C(int, int) asm("func_0018D08C");
extern "C" int Xiii_func_0018F734(int, int) asm("func_0018F734");
struct D007812C0Type {
    char pad[0x22214];
    int m_22214;
};
extern D007812C0Type D_007812C0;
extern "C" int Xiii_func_001D3AC8(int, int) asm("func_001D3AC8");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiiiiii_func_0018D7EC(int, int, int, int, int, int) asm("func_0018D7EC");
extern int D_00299990;
extern int D_002999B0;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_clear__6BedPfh(...) asm("clear__6BedPfh");
extern "C" int X_func_0018BEF8(...) asm("func_0018BEF8");
extern "C" int X_func_0018C448(...) asm("func_0018C448");
extern "C" int X_func_0018C4D8(...) asm("func_0018C4D8");
extern "C" int X_func_0018C54C(...) asm("func_0018C54C");
extern "C" int X_func_0018C910(...) asm("func_0018C910");
extern "C" int X_func_0018C990(...) asm("func_0018C990");
extern "C" int X_func_0018C9D8(...) asm("func_0018C9D8");
extern "C" int X_func_0018CA58(...) asm("func_0018CA58");
extern "C" int X_func_0018D08C(...) asm("func_0018D08C");
extern "C" int X_func_0018D1E8(...) asm("func_0018D1E8");
extern "C" int X_func_0018D640(...) asm("func_0018D640");
extern "C" int X_func_0018D7EC(...) asm("func_0018D7EC");
extern "C" int X_func_0018DAFC(...) asm("func_0018DAFC");
extern "C" int X_func_0018DF20(...) asm("func_0018DF20");
extern "C" int X_func_0018E05C(...) asm("func_0018E05C");
extern "C" int X_func_0018EF40(...) asm("func_0018EF40");
extern "C" int X_func_0018EFF0(...) asm("func_0018EFF0");
extern "C" int X_func_0018F024(...) asm("func_0018F024");
extern "C" int X_func_0018F060(...) asm("func_0018F060");
extern "C" int X_func_0018F60C(...) asm("func_0018F60C");
extern "C" int X_func_0018F734(...) asm("func_0018F734");
extern "C" int X_func_0018F824(...) asm("func_0018F824");
extern "C" int X_func_001905A0(...) asm("func_001905A0");
extern "C" int X_func_001905A8(...) asm("func_001905A8");
extern "C" int X_func_001BFFCC(...) asm("func_001BFFCC");
extern "C" int X_func_001C0254(...) asm("func_001C0254");
extern "C" int X_func_002232F0(...) asm("func_002232F0");
extern "C" int X_heapFree__FPv(...) asm("heapFree__FPv");
extern int D_007A34D4;

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018BD94);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018BEF8);

extern "C" int func_0018C068(Obj_C068 *arg0)
{
    int i;

    if (arg0->unk04 == 0) {
        return 0;
    }
    for (i = 0; i < arg0->unk4B4; i++) {
        Sub154_C068 *p = (Sub154_C068 *)(arg0->unk4AC + i * 0x154);
        if (p->unk00 == 0) {
            Xv_func_0018DF20(arg0, p);
        }
    }
    for (i = 0; i < arg0->unk4B4; i++) {
        Sub154_C068 *p = (Sub154_C068 *)(arg0->unk4AC + i * 0x154);
        if (p->unk00 > 0) {
            Xv_func_0018DF20(arg0, p);
        }
    }
    return 0;
}

extern "C" int func_0018C130(int arg0)
{
    int *p;
    int *q;

    if (M2C_FIELD(arg0, int *, 0x4AC) == 0) {
        return -1;
    }
    Xii_func_0018F824(arg0 + 8);
    Xii_heapFree__FPv(M2C_FIELD(arg0, int *, 0x4AC));
    M2C_FIELD(arg0, int *, 0x4AC) = 0;
    p = (int *)(arg0 + 0x4E4);
    q = (int *)(arg0 + 4);
    if (*p != 0) {
        *p = 0;
    }
    *q = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C190);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C2E4);

extern "C" int func_0018C448(int arg0, int arg1, int arg2)
{
    char *p;

    if (M2C_FIELD(arg0, int *, 0x4AC) == 0) {
        return 1;
    }
    if (arg1 >= M2C_FIELD(arg0, int *, 0x4B4)) {
        return 1;
    }
    p = (char *)M2C_FIELD(arg0, int *, 0x4AC) + arg1 * 0x154;
    M2C_FIELD(p, int *, 0x138) = arg2;
    M2C_FIELD(p, int *, 0x110) = 0;
    M2C_FIELD(p, int *, 0x114) = 0;
    M2C_FIELD(p, int *, 0xF4) = *(unsigned short *)M2C_FIELD(arg2, int *, 8);
    M2C_FIELD(p, int *, 0x118) = *(int *)M2C_FIELD(arg2, int *, 8) & 0xFF0000;
    M2C_FIELD(p, int *, 0x134) = Xiii_func_0018C910(arg0, arg2);
    return 0;
}

extern "C" int func_0018C4D8(int arg0, int arg1, int arg2)
{
    char *p = (char *)M2C_FIELD(arg0, int *, 0x4AC);
    int temp_a0;

    p += arg1 * 0x154;
    if (arg2 >= M2C_FIELD(p, int *, 0x134)) {
        return 1;
    }
    M2C_FIELD(p, int *, 0x110) = arg2;
    M2C_FIELD(p, int *, 0x114) = 0;
    temp_a0 = M2C_FIELD(p, int *, 0x138) + arg2 * 0xC;
    M2C_FIELD(p, int *, 0xF4) = *(unsigned short *)M2C_FIELD(temp_a0, int *, 8);
    M2C_FIELD(p, int *, 0x118) = *(int *)M2C_FIELD(temp_a0, int *, 8) & 0xFF0000;
    return 0;
}

extern "C" int func_0018C54C(int arg0, char *arg1, int arg2)
{
    int temp_a0;

    if (arg2 >= M2C_FIELD(arg1, int *, 0x134)) {
        return 1;
    }
    M2C_FIELD(arg1, int *, 0x110) = arg2;
    M2C_FIELD(arg1, int *, 0x114) = 0;
    temp_a0 = M2C_FIELD(arg1, int *, 0x138) + arg2 * 0xC;
    M2C_FIELD(arg1, int *, 0xF4) = *(unsigned short *)M2C_FIELD(temp_a0, int *, 8);
    M2C_FIELD(arg1, int *, 0x118) = *(int *)M2C_FIELD(temp_a0, int *, 8) & 0xFF0000;
    return 0;
}

extern "C" int func_0018C5A8(Obj_C5A8 *arg0, int arg1, int arg2)
{
    Sub154_C5A8 *p = &arg0->unk4AC[arg1];
    EntryC_C5A8 *q = &p->unk138[p->unk110];
    int off = arg2 * 0x1C;

    if (arg2 >= q->unk04) {
        return 1;
    }
    p->unk114 = arg2;
    p->unkF4 = *(unsigned short *)((char *)q->unk08 + off);
    p->unk118 = *(int *)((char *)q->unk08 + off) & 0xFF0000;
    return 0;
}

extern "C" int func_0018C630(int arg0, int arg1, int arg2)
{
    char *p;

    if (M2C_FIELD(arg0, int *, 0x4AC) == 0) {
        return 1;
    }
    if (arg1 >= M2C_FIELD(arg0, int *, 0x4B4)) {
        return 1;
    }
    p = (char *)M2C_FIELD(arg0, int *, 0x4AC) + arg1 * 0x154;
    M2C_FIELD(p, int *, 0x140) = arg2;
    M2C_FIELD(p, int *, 0x104) = 0;
    M2C_FIELD(p, int *, 0x108) = 0;
    M2C_FIELD(p, int *, 0xF8) = M2C_FIELD(M2C_FIELD(arg2, int *, 8), int *, 4);
    M2C_FIELD(p, int *, 0x13C) = Xiii_func_0018C9D8(arg0, arg2);
    Xiii_func_0018D08C(arg0, (int)p);
    return 0;
}

extern "C" int func_0018C6C4(int arg0, int arg1, int arg2)
{
    char *p = (char *)M2C_FIELD(arg0, int *, 0x4AC);
    char *q;

    p += arg1 * 0x154;
    if (arg2 >= M2C_FIELD(p, int *, 0x13C)) {
        return 1;
    }
    M2C_FIELD(p, int *, 0x104) = arg2;
    M2C_FIELD(p, int *, 0x108) = 0;
    q = (char *)M2C_FIELD(p, int *, 0x140);
    q += arg2 * 0xC;
    M2C_FIELD(p, int *, 0xF8) = M2C_FIELD(M2C_FIELD(q, int *, 8), int *, 4);
    Xiii_func_0018D08C(arg0, (int)p);
    return 0;
}

extern "C" int func_0018C738(int arg0, char *arg1, int arg2)
{
    char *p;

    if (arg2 >= M2C_FIELD(arg1, int *, 0x13C)) {
        return 1;
    }
    M2C_FIELD(arg1, int *, 0x104) = arg2;
    M2C_FIELD(arg1, int *, 0x108) = 0;
    p = (char *)M2C_FIELD(arg1, int *, 0x140);
    p += arg2 * 0xC;
    M2C_FIELD(arg1, int *, 0xF8) = M2C_FIELD(M2C_FIELD(p, int *, 8), int *, 4);
    Xiii_func_0018D08C(arg0, (int)arg1);
    return 0;
}

// NON_MATCHING: 1/32 differ, 1 edits
#ifdef NON_MATCHING
extern "C" int func_0018C794(int arg0, int arg1, int arg2)
{
    char *p = (char *)M2C_FIELD(arg0, int *, 0x4AC) + arg1 * 0x154;
    char *q = (char *)M2C_FIELD(p, int *, 0x140) + M2C_FIELD(p, int *, 0x104) * 0xC;

    if (arg2 >= M2C_FIELD(q, int *, 4)) {
        return 1;
    }
    M2C_FIELD(p, int *, 0x108) = arg2;
    M2C_FIELD(p, int *, 0xF8) = *(int *)(arg2 * 0x20 + M2C_FIELD(q, unsigned int *, 8) + 4);
    Xiii_func_0018D08C(arg0, (int)p);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C794);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C814);

extern "C" int func_0018C910(int arg0, char *arg1)
{
    int n = 0;

    if (arg1 == 0) {
        return 0;
    }
    if (*(int *)arg1 != -1) {
        char *p = arg1;
        do {
            if (M2C_FIELD(p, int *, 4) < 0) {
                M2C_FIELD(p, int *, 4) = Xiii_func_0018C990(arg0, M2C_FIELD(p, int *, 8));
            }
            p += 0xC;
            n += 1;
        } while (*(int *)p != -1);
    }
    return n;
}

extern "C" int func_0018C990(int arg0, char *arg1)
{
    int n = 0;

    if (arg1 == 0) {
        return 0;
    }
    if ((M2C_FIELD(arg1, int *, 0) & 0xFF000000) == 0) {
        do {
            arg1 += 0x1C;
            n += 1;
        } while ((M2C_FIELD(arg1, int *, 0) & 0xFF000000) == 0);
    }
    return n;
}

extern "C" int func_0018C9D8(int arg0, char *arg1)
{
    int n = 0;

    if (arg1 == 0) {
        return 0;
    }
    if (*(int *)arg1 != -1) {
        char *p = arg1;
        do {
            if (M2C_FIELD(p, int *, 4) < 0) {
                M2C_FIELD(p, int *, 4) = Xiii_func_0018CA58(arg0, M2C_FIELD(p, int *, 8));
            }
            p += 0xC;
            n += 1;
        } while (*(int *)p != -1);
    }
    return n;
}

extern "C" int func_0018CA58(int arg0, char *arg1)
{
    int n = 0;

    if (arg1 == 0) {
        return 0;
    }
    if (M2C_FIELD(arg1, int *, 0) >= 0) {
        do {
            arg1 += 0x20;
            n += 1;
        } while (M2C_FIELD(arg1, int *, 0) >= 0);
    }
    return n;
}

extern "C" float func_0018CA98(int arg0, int arg1, float fparg0)
{
    float t = (float) arg1;

    t = (t * t + t) * 0.5f;
    return fparg0 / t;
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CAC8);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CC54);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CD88);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CEEC);

extern "C" void func_0018CFF0(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x4AC) + (arg1 * 0x154);
    M2C_FIELD(temp_v1, int *, 8) = 2;
    M2C_FIELD(temp_v1, int *, 0xF8) = arg2;
    M2C_FIELD(temp_v1, float *, 0x7C) = (float) ((int) M2C_FIELD(temp_v1, int *, 0x64) >> 4);
    M2C_FIELD(temp_v1, float *, 0x80) = (float) ((int) M2C_FIELD(temp_v1, int *, 0x68) >> 4);
    M2C_FIELD(temp_v1, float *, 0x84) = (float) ((int) M2C_FIELD(temp_v1, int *, 0x6C) >> 4);
    M2C_FIELD(temp_v1, int *, 0xFC) = arg2;
    M2C_FIELD(temp_v1, float *, 0x94) = (float) M2C_FIELD(arg4, float *, 0);
    M2C_FIELD(temp_v1, float *, 0x98) = (float) M2C_FIELD(arg4, float *, 4);
    M2C_FIELD(temp_v1, float *, 0x9C) = (float) M2C_FIELD(arg4, float *, 8);
    M2C_FIELD(temp_v1, float *, 0x88) = (float) M2C_FIELD(arg3, float *, 0);
    M2C_FIELD(temp_v1, float *, 0x8C) = (float) M2C_FIELD(arg3, float *, 4);
    M2C_FIELD(temp_v1, float *, 0x90) = (float) M2C_FIELD(arg3, float *, 8);
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018D08C);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018D1E8);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018D640);

extern "C" int func_0018D7C8(int arg0, int arg1)
{
    char *p = (char *)M2C_FIELD(arg0, int *, 0x4AC);

    p += arg1 * 0x154;
    return M2C_FIELD(p, int *, 0x14);
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018D7EC);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018DAFC);

extern "C" void func_0018DF20(int arg0, int arg1)
{
    int temp_a1;
    int temp_v0;
    int temp_v0_2;

    if (M2C_FIELD(arg1, int *, 0x10) == 0) {
        return;
    }
    switch (M2C_FIELD(arg1, int *, 0x10)) {
    case 1:
    case 3:
    case 4:
    case 5:
        temp_a1 = M2C_FIELD(arg1, int *, 0x10C);
        if ((temp_a1 != -1) && (M2C_FIELD(arg1, int *, 0x130) != 0) && (Xiii_func_0018F734(arg0 + 8, temp_a1) != 0)) {
            temp_v0 = M2C_FIELD(arg1, int *, 0x120);
            if (temp_v0 <= 0) {
                temp_v0_2 = M2C_FIELD(arg1, int *, 0x11C) + M2C_FIELD(arg1, int *, 0x124);
                M2C_FIELD(arg1, int *, 0x11C) = temp_v0_2;
                M2C_FIELD(arg1, int *, 0x120) = M2C_FIELD(arg1, int *, 0x130);
                if (temp_v0_2 >= M2C_FIELD(arg1, int *, 0x12C)) {
                    M2C_FIELD(arg1, int *, 0x130) = 0;
                    return;
                }
            } else {
                M2C_FIELD(arg1, int *, 0x120) = temp_v0 - 1;
            }
        }
        break;
    }
}

extern "C" int func_0018DFDC(int arg0, int arg1)
{
    char *p = (char *)M2C_FIELD(arg0, int *, 0x4AC);
    int r;

    p += arg1 * 0x154;
    r = Xiii_func_0018F734(arg0 + 8, M2C_FIELD(p, int *, 0x10C));
    if (r == 0) {
        return 0;
    }
    return M2C_FIELD(M2C_FIELD(r, int *, 4), int *, 0x50);
}

extern "C" int func_0018E028(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int var_v0;

    var_v0 = 1;
    if ((arg3 < 0) || (arg4 < 0)) {
        var_v0 = 0;
    }
    if ((arg1 >= 0x2801) || (arg2 >= 0x1E01)) {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018E05C);

extern "C" void func_0018EA9C(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int temp_s3;
    int temp_s0;
    int temp_s1;
    int temp_v0;
    int temp_v0_2;

    temp_s3 = arg0 + 0x440;
    temp_v0 = M2C_FIELD(arg1, int *, 0x150);
    temp_s0 = ((int) M2C_FIELD(arg1, int *, 0xB8) >> 4) + M2C_FIELD(temp_v0, int *, 0);
    temp_s1 = ((int) M2C_FIELD(arg1, int *, 0xBC) >> 4) + M2C_FIELD(temp_v0, int *, 4);
    Xiiiiii_func_001BEDC0(temp_s3, arg2, arg3, arg4, 4);
    temp_v0_2 = M2C_FIELD(arg1, int *, 0x150);
    Xiiiiii_func_001BEF24(temp_s3, temp_s0, temp_s1, M2C_FIELD(temp_v0_2, int *, 8), M2C_FIELD(temp_v0_2, int *, 0xC));
}

extern "C" int func_0018EB30(int arg0, unsigned char *arg1)
{
    unsigned int c;
    unsigned int off;
    int var_a3 = 0;

    if (*arg1 != 0) {
        do {
            c = *arg1++;
            c &= 0xFF;
            off = c - 0x81;
            if (c == 0x23) {
                if (*arg1 == 0x30) {
                    arg1++;
                    var_a3++;
                    continue;
                }
            }
            if (off < 0x1F || (unsigned int)(c - 0xE0) < 0x1D) {
                arg1++;
            }
        } while (*arg1 != 0);
    }
    return var_a3 + 1;
}

extern "C" void func_0018EBA4(int arg0, unsigned char *arg1, unsigned char *arg2, int arg3)
{
    unsigned int c;
    int line = 0;
    int len = 0;

    if (*arg1 != 0) {
        do {
            c = *arg1;
            if (arg3 == line) {
                *arg2 = c;
            }
            c &= 0xFF;
            arg1++;
            if (c == 0x23) {
                if (*arg1 == 0x30) {
                    arg1++;
                    if (arg3 == line) {
                        break;
                    }
                    line++;
                    continue;
                }
            }
            if ((unsigned int)(c - 0x81) < 0x1F || (unsigned int)(c - 0xE0) < 0x1D) {
                if (arg3 == line) {
                    arg2++;
                    len++;
                    *arg2 = *arg1;
                }
                arg1++;
            }
            if (arg3 == line) {
                arg2++;
                len++;
            }
            if (len >= 0x3F) {
                break;
            }
        } while (*arg1 != 0);
    }
    *arg2 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018EC58);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018ED44);

extern "C" int func_0018EF40(Obj_EF40 *arg0, int arg1)
{
    Arg223558 q;
    int v;

    if (arg0->unk4D0.a[arg1] == 0) {
        return 1;
    }
    q.unk00 = 1.0f;
    q.unk04 = &arg0->unk134;
    q.unk08 = arg0->unk130;
    q.unk0C = 0;
    q.unk10 = 0;
    q.unk14 = 0;
    v = Xii_func_00223558(arg0->unk4D0.a[arg1], &q);
    arg0->unk4D0.c[arg1] = v;
    if (v == 0) {
        return 1;
    }
    Xii_func_00223228(arg0->unk4D0.a[arg1], v);
    arg0->unk4D0.b = Xif_func_00223298(arg0->unk4D0.a[arg1], 0.0f);
    return 0;
}

extern "C" void func_0018EFF0(int arg0, int arg1)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x4D0));
    if (temp_v0 != 0) {
        X_func_002232F0(temp_v0, (*(int *)(int *)((char *)(arg0) + 0x4D8)));
    }
}


extern "C" void func_0018F024()
{
    if (~D_007812C0.m_22214 != 0) {
        Xiii_func_001D3AC8((int)&D_007812C0, 1);
    }
}

extern "C" void func_0018F060()
{
    if (~D_007812C0.m_22214 == 0) {
        Xiii_func_001D3AC8((int)&D_007812C0, 0);
    }
}

extern "C" void func_0018F09C(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x4C8)) = (int) (~D_007A34D4 == 0);
}


extern "C" int func_0018F0B4(int arg0)
{
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x4C8));
    switch (temp_v1) {                              
    case 0:
        return X_func_0018F060();
    case 1:
        return X_func_0018F024();
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018F0EC);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018F1F4);

extern "C" void func_0018F2E8(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    M2C_FIELD((arg1 * 0x154 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) = 3;
    M2C_FIELD((arg1 * 0x154 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x100) = arg2;
    X_func_0018D7EC(arg0, arg1, 4, arg3, arg4, arg5);
}

extern "C" void func_0018F338(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int temp_a7;
    int temp_t1;

    temp_a7 = arg1 * 0x154;
    temp_t1 = temp_a7 + M2C_FIELD(arg0, int *, 0x4AC);
    if (M2C_FIELD(temp_t1, int *, 0x10) == 0) {
        M2C_FIELD(temp_t1, int *, 0x10) = 1;
        M2C_FIELD((temp_a7 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0xC) = 1;
        M2C_FIELD((temp_a7 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x18) = 0x80;
        M2C_FIELD((temp_a7 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x1C) = 0x80;
        M2C_FIELD((temp_a7 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x20) = 0x80;
        M2C_FIELD((temp_a7 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x24) = 0;
        return Xv_func_0018D7EC(arg0, arg1, 4, arg2, (int) arg3, (int) arg4);
    }
}

extern "C" void func_0018F3E0(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = arg1 * 0x154;
    (*(int *)(int *)((char *)((temp_v1 + (*(int *)(int *)((char *)(arg0) + 0x4AC)))) + 0xC)) = 0;
    (*(int *)(int *)((char *)((temp_v1 + (*(int *)(int *)((char *)(arg0) + 0x4AC)))) + 0x8)) = 0;
    (*(int *)(int *)((char *)((temp_v1 + (*(int *)(int *)((char *)(arg0) + 0x4AC)))) + 0x10)) = 0;
}


extern "C" void func_0018F41C(int arg0, int arg1, int arg2)
{
    int temp_v0;

    Xiiiiiii_func_0018D7EC(arg0, arg1, 3, arg2, (int)&D_002999B0, (int)&D_00299990);
    temp_v0 = arg1 * 0x154;
    M2C_FIELD((temp_v0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) = 4;
    M2C_FIELD((temp_v0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x100) = arg2;
}

extern "C" void func_0018F4A0(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int temp_v0;

    Xiiiiiii_func_0018D7EC(arg0, arg1, 3, arg2, (int) arg3, (int) arg4);
    temp_v0 = arg1 * 0x154;
    M2C_FIELD((temp_v0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) = 4;
    M2C_FIELD((temp_v0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x100) = arg2;
}

extern "C" void func_0018F520(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int temp_s0;

    temp_s0 = arg1 * 0x154;
    if (M2C_FIELD((temp_s0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) != 0) {
        Xiiiiiii_func_0018D7EC(arg0, arg1, 3, arg2, (int) arg3, (int) arg4);
        M2C_FIELD((temp_s0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) = 4;
        M2C_FIELD((temp_s0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x100) = arg2;
    }
}

extern "C" void func_0018F5B0(int arg0)
{
    X_clear__6BedPfh(arg0 + 0x41C);
    X_func_0018F60C(arg0);
    (*(int *)(int *)((char *)(arg0) + 0x418)) = 0;
}


extern "C" void func_0018F5E4(void *self, int theFlags)
{
    if (theFlags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018F60C);
