#include "include_asm.h"
struct m2c_v200_10_i { char pad[512]; virtual void v1(); virtual int call(); };
struct m2c_v34_18_i { char pad[52]; virtual void v1(); virtual void v2(); virtual int call(); };
struct m2c_v34_20_i { char pad[52]; virtual void v1(); virtual void v2(); virtual void v3(); virtual int call(); };
struct m2c_v200_18_i { char pad[512]; virtual void v1(); virtual void v2(); virtual int call(); };
extern "C" int Xii_func_001682B0(int) asm("func_001682B0");
extern "C" int Xii_func_00168844(int) asm("func_00168844");
extern "C" int Xii_func_00165794(int) asm("func_00165794");
extern "C" int Xii_func_00165AA8(int) asm("func_00165AA8");
extern "C" int Xii_func_00165D7C(int) asm("func_00165D7C");
extern "C" int Xii_func_00166048(int) asm("func_00166048");
extern "C" int Xii_func_00166108(int) asm("func_00166108");
extern "C" int Xii_func_00166178(int) asm("func_00166178");
extern "C" int Xiii_func_001696FC(int, int) asm("func_001696FC");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0015CE88(...) asm("func_0015CE88");
extern "C" int X_func_0015CF30(...) asm("func_0015CF30");
extern "C" int X_func_0015D08C(...) asm("func_0015D08C");
extern "C" int X_func_0015D134(...) asm("func_0015D134");
extern "C" int X_func_0015D1DC(...) asm("func_0015D1DC");
extern "C" int X_func_0015D284(...) asm("func_0015D284");
extern "C" int X_func_0015D32C(...) asm("func_0015D32C");
extern "C" int X_func_0015D3E0(...) asm("func_0015D3E0");
extern "C" int X_func_0015D488(...) asm("func_0015D488");
extern "C" int X_func_0015D530(...) asm("func_0015D530");
extern "C" int X_func_0015D5D8(...) asm("func_0015D5D8");
extern "C" int X_func_0015D680(...) asm("func_0015D680");
extern "C" int X_func_0015D738(...) asm("func_0015D738");
extern "C" int X_func_0015D7F0(...) asm("func_0015D7F0");
extern "C" int X_func_0015D890(...) asm("func_0015D890");
extern "C" int X_func_0015D948(...) asm("func_0015D948");
extern "C" int X_func_0015DA00(...) asm("func_0015DA00");
extern "C" int X_func_0015DAA8(...) asm("func_0015DAA8");
extern "C" int X_func_0015DD74(...) asm("func_0015DD74");
extern "C" int X_func_0015F37C(...) asm("func_0015F37C");
extern "C" int X_func_0015F8AC(...) asm("func_0015F8AC");
extern "C" int X_func_0015FF54(...) asm("func_0015FF54");
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00165794(...) asm("func_00165794");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D38(...) asm("func_00165D38");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" int X_func_00166004(...) asm("func_00166004");
extern "C" int X_func_00166048(...) asm("func_00166048");
extern "C" int X_func_00166108(...) asm("func_00166108");
extern "C" int X_func_00166128(...) asm("func_00166128");
extern "C" int X_func_00166178(...) asm("func_00166178");
extern "C" int X_func_00166198(...) asm("func_00166198");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_001687BC(...) asm("func_001687BC");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_001696FC(...) asm("func_001696FC");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001D23F8(...) asm("func_001D23F8");
extern int D_007812C0;
extern int D_007A3208;
extern int D_007B2294;

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015C304);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfMain__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfMain__vfunc_05);

extern "C" void DwfMain__vfunc_06(int arg0)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    if (M2C_FIELD(arg0, int *, 0x40) != 0) {
        ((m2c_v34_20_i *)(M2C_FIELD(arg0, int *, 0x44)))->call();
        ((m2c_v200_10_i *)(arg0))->call();
    }
    M2C_FIELD(arg0, int *, 0x24) = ((m2c_v34_18_i *)(M2C_FIELD(arg0, int *, 0x44)))->call();
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfMain__vfunc_02);

extern "C" int func_0015CE74()
{
    return X_func_00165734();
}


extern "C" int func_0015CE88(int arg0)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = Xiii_func_001696FC(M2C_FIELD(arg0, int *, 0x1C), 1);
    if (temp_v0 == 0xB && M2C_FIELD(arg0, int *, 0x26C) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && M2C_FIELD(arg0, int *, 0x270) == 0) var_a0 = 1;
    else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x3EC);
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else var_a0 = 0;
    if (var_a0) return 0;
    return Xii_func_00165794((int) arg0);
}

// D_002F0DD8: the end of unk/PigMain's .rodata now (config/splits_manual.tsv)

// D_002F0DE8: the end of unk/PigMain's .rodata now (config/splits_manual.tsv)

// D_002F0DF8: the end of unk/PigMain's .rodata now (config/splits_manual.tsv)

// D_002F0E08: the end of unk/PigMain's .rodata now (config/splits_manual.tsv)

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015CF30);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D08C);

extern "C" int func_0015D134(int arg0)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = Xiii_func_001696FC(M2C_FIELD(arg0, int *, 0x1C), 8);
    if (temp_v0 == 0xB && M2C_FIELD(arg0, int *, 0x26C) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && M2C_FIELD(arg0, int *, 0x270) == 0) var_a0 = 1;
    else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x3EC);
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else var_a0 = 0;
    if (var_a0) return 0;
    return Xii_func_00165AA8((int) arg0);
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D1DC);

extern "C" int func_0015D284(int arg0)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = Xiii_func_001696FC(M2C_FIELD(arg0, int *, 0x1C), 0xA);
    if (temp_v0 == 0xB && M2C_FIELD(arg0, int *, 0x26C) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && M2C_FIELD(arg0, int *, 0x270) == 0) var_a0 = 1;
    else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x3EC);
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else var_a0 = 0;
    if (var_a0) return 0;
    return Xii_func_00165D7C((int) arg0);
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D32C);

extern "C" int func_0015D3E0(int arg0)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = Xiii_func_001696FC(M2C_FIELD(arg0, int *, 0x1C), 0xC);
    if (temp_v0 == 0xB && M2C_FIELD(arg0, int *, 0x26C) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && M2C_FIELD(arg0, int *, 0x270) == 0) var_a0 = 1;
    else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x3EC);
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else var_a0 = 0;
    if (var_a0) return 0;
    return Xii_func_00166048(arg0);
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D488);

extern "C" int func_0015D530(int arg0)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = Xiii_func_001696FC(M2C_FIELD(arg0, int *, 0x1C), 0xE);
    if (temp_v0 == 0xB && M2C_FIELD(arg0, int *, 0x26C) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && M2C_FIELD(arg0, int *, 0x270) == 0) var_a0 = 1;
    else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x3EC);
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else var_a0 = 0;
    if (var_a0) return 0;
    return Xii_func_00166108(arg0);
}

extern "C" int func_0015D5D8(int arg0)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = Xiii_func_001696FC(M2C_FIELD(arg0, int *, 0x1C), 0xF);
    if (temp_v0 == 0xB && M2C_FIELD(arg0, int *, 0x26C) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && M2C_FIELD(arg0, int *, 0x270) == 0) var_a0 = 1;
    else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x3EC);
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else var_a0 = 0;
    if (var_a0) return 0;
    return Xii_func_00166178(arg0);
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D680);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D738);

extern "C" int func_0015D7F0(int arg0)
{
    int temp_v0;
    int temp_v1;
    int var_a0;
    int var_v0;

    temp_v0 = Xiii_func_001696FC(M2C_FIELD(arg0, int *, 0x1C), 0x12);
    if (temp_v0 == 0xB && M2C_FIELD(arg0, int *, 0x26C) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && M2C_FIELD(arg0, int *, 0x270) == 0) var_a0 = 1;
    else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x3EC);
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else var_a0 = 0;
    var_v0 = 0;
    if (var_a0 == 0) {
        var_v0 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x3EC) & 1;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D890);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D948);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015DA00);

// NON_MATCHING: 158/159 differ, 10 relocs differ (size 0x27C, game 0x2CC), 103 edits
#ifdef NON_MATCHING
extern "C" int X___builtin_vec_delete(...) asm("__builtin_vec_delete");
extern "C" int X___builtin_vec_new(...) asm("__builtin_vec_new");
extern "C" int X_func_001637CC(...) asm("func_001637CC");
extern "C" int X_func_0016976C(...) asm("func_0016976C");
extern "C" int X_func_001D1720(...) asm("func_001D1720");
extern "C" int X_func_001D35AC(int, int, int, int, int, int, float) asm("func_001D35AC");
extern "C" int X_func_001D890C(...) asm("func_001D890C");
extern "C" int X_func_001DB71C(...) asm("func_001DB71C");
extern int D_007B2140;
extern "C" int func_0015DAA8(int arg0)
{
    struct { float sp0; char pad4[4]; float sp8; char padC[4]; float sp10; char pad14[4]; float sp18; char pad1C[4]; float sp20; char pad24[4]; float sp28; char pad2C[4]; int sp30; int sp34; char pad38[4]; int sp3C; int sp40; int sp44; char pad48[4]; int sp4C; int sp50; char pad54[28]; int sp70; char pad74[60]; int spB0; char padB4[12]; int spC0; char padC4[12]; int spD0; char padD4[12]; int spE0; } stack;
    int temp_a2;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_a0;
    float temp_f3;
    float var_f2;
    float var_f2_2;
    float var_f4;
    int temp_a2_2;
    int temp_s0;
    int var_a1;
    int var_s6;

    stack.sp3C = 0;
    M2C_FIELD((int)&stack.sp30, int *, 0) = (int)&stack.sp30;
    stack.sp34 = (int)&stack.sp30;
    stack.sp4C = 0;
    stack.sp40 = (int)&stack.sp40;
    stack.sp44 = (int)&stack.sp40;
    stack.sp50 = 0;
    temp_a2 = X___builtin_vec_new(0x300);
    stack.sp50 = 0x40;
    stack.sp70 = temp_a2;
    var_a0 = temp_a2;
    var_a1 = 0;
    do {
        M2C_FIELD(var_a0, int *, 0) = var_a0 - 0xC;
        temp_v1 = var_a0 + 0xC;
        var_a1 += 1;
        M2C_FIELD(var_a0, int *, 4) = temp_v1;
        var_a0 = temp_v1;
    } while (var_a1 < M2C_FIELD((int)&stack.sp30, int *, 0x20));
    temp_v0 = (int)&stack.sp30 + 0x10;
    M2C_FIELD(temp_v0, int *, 4) = temp_v0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD((int)&stack.sp30, int *, 0x10) = temp_v0;
    M2C_FIELD((int)&stack.sp30, int *, 4) = temp_a2;
    var_s6 = 0;
    M2C_FIELD((int)&stack.sp30, int *, 0xC) = (int) M2C_FIELD((int)&stack.sp30, int *, 0x20);
    (*(int *)(temp_a2)) = (int)&stack.sp30;
    temp_a2_2 = M2C_FIELD((int)&stack.sp30, int *, 0xC);
    temp_v1_2 = (M2C_FIELD((int)&stack.sp30, int *, 4) + (temp_a2_2 * 0xC)) - 0xC;
    M2C_FIELD((int)&stack.sp30, int *, 0) = temp_v1_2;
    M2C_FIELD(temp_v1_2, int *, 4) = (int)&stack.sp30;
    stack.spB0 = 0;
    stack.spC0 = 0;
    X_func_001D890C(arg0, (int)&stack, temp_a2_2);
    X_func_001D35AC((int)&D_007812C0, (int)&stack, (int)&stack.sp30, 5, 0x800000, 0x04000000, 700.0f);
    stack.sp10 = 700.0f;
    stack.sp18 = 700.0f;
    stack.spD0 = stack.sp44;
    stack.spB0 = stack.sp44;
    stack.spD0 = (int)&stack.sp40;
    stack.spC0 = (int)&stack.sp40;
    if (stack.spB0 != stack.spC0) {
        do {
            temp_s0 = M2C_FIELD(M2C_FIELD(stack.spB0, int *, 8), int *, 0x100);
            if ((temp_s0 != 0) && (X_func_001D1720((int)&D_007812C0, temp_s0, 1) == 0)) {
                if (X_func_001637CC((int)&D_007B2140, temp_s0) == 0) {
                    X_func_001DB71C(M2C_FIELD(stack.spB0, int *, 8), (int)&stack.sp20);
                    var_f4 = stack.sp10;
                    var_f2 = stack.sp20 - stack.sp0;
                    temp_f3 = stack.sp28 - stack.sp8;
                    stack.sp20 = var_f2;
                    stack.sp28 = temp_f3;
                    if (var_f4 < 0.0f) {
                        var_f4 = -var_f4;
                    }
                    if (var_f2 < 0.0f) {
                        var_f2 = -var_f2;
                    }
                    if (temp_f3 < 0.0f) {
                        var_f2_2 = var_f2 - temp_f3;
                    } else {
                        var_f2_2 = var_f2 + temp_f3;
                    }
                    if (!(stack.sp18 < 0.0f)) {
                        if (var_f2_2 < (var_f4 + stack.sp18)) {
                            goto block_22;
                        }
                    } else if (!(var_f2_2 < (var_f4 - stack.sp18))) {

                    } else {
block_22:
                        if (X_func_0016976C((int)&stack, (int)&stack.sp20) != 0) {
                            var_s6 = temp_s0;
                            stack.sp10 = stack.sp20;
                            stack.sp18 = stack.sp28;
                        }
                    }
                }
            }
            stack.spE0 = stack.spB0;
            stack.spB0 = M2C_FIELD(stack.spB0, int *, 4);
            stack.spD0 = stack.spE0;
        } while (stack.spB0 != stack.spC0);
    }
    if (stack.sp70 != 0) {
        X___builtin_vec_delete(stack.sp70);
    }
    return var_s6;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015DAA8);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015DD74);

extern "C" void DwfOutDisappear__vfunc_02(int arg0)
{
    X_func_001D23F8((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 1);
    X_func_001687BC(arg0, 0x1D, 0x100);
    (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0xC)) = 0;
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x40);
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x10000000);
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    (*(int *)(int *)((char *)(arg0) + 0x4)) = 0;
}


extern "C" void DwfOutDisappear__vfunc_04(int arg0)
{
    X_func_001D23F8((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0);
    (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0xC)) = 1;
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x40);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x10000000);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    X_func_00166AD0(arg0);
}


extern "C" void DwfOutAppear__vfunc_02(int arg0)
{
    int temp_v1;

    (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0xC)) = 0;
    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x8));
    (*(int *)(int *)((char *)(temp_v1) + 0x120)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x120)) | 0x400);
    (*(int *)(int *)((char *)(arg0) + 0x4)) = 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutAppear__vfunc_03);

extern "C" void DwfOutWait__vfunc_02(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0xC);
    if (((m2c_v200_18_i *)(temp_v1))->call() == 2) {
        Xii_func_00168844(arg0);
    } else {
        Xii_func_001682B0(arg0);
    }
    M2C_FIELD(arg0, int *, 4) = 0;
}

extern "C" int DwfOutWait__vfunc_03()
{
    return -1;
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutWalk__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0E58);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0E68);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0E80);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0E90);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutWalk__vfunc_03);

extern "C" void DwfOutWalk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void func_0015EAA8(int arg0, int arg1)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x4)) != arg1) {
        (*(int *)(int *)((char *)(arg0) + 0x4)) = arg1;
        (*(int *)(int *)((char *)(arg0) + 0x3C)) = 0;
    }
}


extern "C" void DwfOutSerch__vfunc_02(int arg0)
{
    Xiii_func_00166DA4(arg0, 0x64);
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutSerch__vfunc_03);

extern "C" void DwfOutSerch__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutPickup__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0EC0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0ED0);

// NON_MATCHING: 176/203 differ, 26 relocs differ (size 0x32C, game 0x348), 93 edits
#ifdef NON_MATCHING
extern "C" int P_func_0015DAA8(...) asm("func_0015DAA8");
extern "C" int P_func_00166F50(char *, int, float) asm("func_00166F50");
extern "C" int P_func_001687BC(...) asm("func_001687BC");
extern "C" int P_func_00169810(...) asm("func_00169810");
extern "C" int P_func_001CBEDC(...) asm("func_001CBEDC");
extern "C" bool P_func_001D19A8(int *, int) asm("func_001D19A8");
extern "C" int P_func_001D2BA8(...) asm("func_001D2BA8");
extern "C" int P_func_001DA228(...) asm("func_001DA228");
extern "C" int P_func_001DA740(...) asm("func_001DA740");
extern "C" int P_func_001DB520(...) asm("func_001DB520");
extern "C" int P_func_00202F10(...) asm("func_00202F10");
extern int D_002F0F10[];
extern int D_002F0F20[];
extern "C" int DwfOutPickup__vfunc_03(char *arg0) {
    struct { short id; short pad2; int id4; char pad8[8]; float vec[4]; int id20; } stack;
    int temp_a0_2;
    int temp_s1;
    bool temp_v0;
    int temp_v0_2;
    bool temp_v0_3;
    bool temp_v0_4;
    bool temp_v0_5;
    int temp_v1_2;
    int var_a1;
    int var_s3;
    int var_v0;
    int var_v0_2;
    int var_v1;
    unsigned int temp_v1;
    unsigned int var_v0_3;
    char *temp_a0;

    temp_v1 = M2C_FIELD(arg0, unsigned int *, 4);
    var_s3 = -1;
    switch (temp_v1) {
    case 0:
        temp_v0 = P_func_001D19A8(&D_007812C0, M2C_FIELD(arg0, int *, 0));
        if (temp_v0 != 0) {
            M2C_FIELD(M2C_FIELD(arg0, char **, 0xC), int *, 0x2C) = 1;
            if (temp_v0 != 0) {
            case 1:
                P_func_001DA228(M2C_FIELD(arg0, char **, 8), 0x67, &stack.id4);
                temp_a0 = M2C_FIELD(arg0, char **, 8);
                if (stack.id4 == 0) {
                    var_v1 = M2C_FIELD(temp_a0, int *, 0x3EC);
                    var_v0_2 = var_v1 & 8;
                    if (!(var_v1 & 2) && (var_v0_2 = var_v1 & 8, (((var_v1 & 1) != 0) == 0)) && ((var_v0_2 == 0) || (var_v0_2 = var_v1 & 8, ((var_v1 & 0x10) == 0)))) {
                        temp_v0_2 = P_func_0015DAA8(temp_a0);
                        M2C_FIELD(arg0, int *, 0x3C) = temp_v0_2;
                        if (temp_v0_2 != 0) {
                            P_func_00166F50(arg0, temp_v0_2, 20.0f);
                            M2C_FIELD(arg0, unsigned int *, 4) = 2U;
                        } else {
                            goto block_12;
                        }
                    } else {
                        goto block_13;
                    }
                } else {
block_12:
                    var_v1 = M2C_FIELD(M2C_FIELD(arg0, char **, 8), int *, 0x3EC);
                    var_v0_2 = var_v1 & 8;
block_13:
                    if ((var_v0_2 == 0) || (var_a1 = 0xA, ((var_v1 & 0x10) == 0))) {
                        temp_v1_2 = M2C_FIELD(M2C_FIELD(arg0, char **, 8), int *, 0x3EC);
                        if (temp_v1_2 & 8) {
                            var_a1 = 1;
                        } else if (!(temp_v1_2 & 0x10)) {
                            var_a1 = 0x14;
                            if (M2C_FIELD(arg0, int *, 0x38) == 2) {
                                P_func_001DA228(M2C_FIELD(arg0, char **, 8), 0x67, &stack.id20);
                                var_a1 = 0x4F;
                                if ((P_func_001CBEDC(&D_007812C0, stack.id20) ^ 0xA2E) != 0) {
                                    var_a1 = 0x14;
                                }
                            }
                        } else {
                            var_a1 = 1;
                        }
                    }
                    P_func_001687BC(arg0, var_a1, 0);
                    M2C_FIELD(arg0, unsigned int *, 4) = 6U;
                }
            }
        }
    default:
block_43:
        var_v0 = var_s3;
        break;
    case 2:
        var_v0 = -1;
        if (M2C_FIELD(arg0, int *, 0x24) != 0) {
            P_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, char **, 0xC), int *, 0x1F0));
            if (M2C_FIELD(arg0, int *, 0x24) == 1) {
                P_func_001687BC(arg0, 0x19, 0);
                M2C_FIELD(arg0, unsigned int *, 4) = 3U;
            } else {
block_42:
                var_s3 = D_002F0F10[M2C_FIELD(arg0, int *, 0x38)];
            }
            goto block_43;
        }
        break;
    case 3:
        temp_v0_3 = P_func_001D19A8(&D_007812C0, M2C_FIELD(arg0, int *, 0));
        if (temp_v0_3 != 0) {
            M2C_FIELD(M2C_FIELD(arg0, char **, 0xC), int *, 0x2C) = 1;
            if (temp_v0_3 != 0) {
                if (P_func_00169810(M2C_FIELD(arg0, int *, 0), M2C_FIELD(arg0, int *, 0x3C)) == 0) {
                    var_v0_3 = 6;
                } else {
                    stack.id = P_func_001CBEDC(&D_007812C0, M2C_FIELD(arg0, int *, 0x3C));
                    P_func_001DA740(M2C_FIELD(arg0, char **, 8), 0x66, &stack.id);
                    P_func_001DA740(M2C_FIELD(arg0, char **, 8), 0x67, arg0 + 0x3C);
                    var_v0_3 = 4;
                }
                M2C_FIELD(arg0, unsigned int *, 4) = var_v0_3;
                P_func_001687BC(arg0, 0x1A, 0);
            }
        }
        goto block_43;
    case 4:
        temp_s1 = P_func_001D2BA8(&D_007812C0, M2C_FIELD(arg0, int *, 0x3C));
        temp_a0_2 = temp_s1;
        stack.vec[0] = 0.0f;
        stack.vec[3] = 0.0f;
        stack.vec[2] = 0.0f;
        stack.vec[1] = 0.0f;
        P_func_001DB520(temp_a0_2, 5, &stack.vec[0]);
        P_func_001DB520(temp_s1, 6, &stack.vec[0]);
        M2C_FIELD(arg0, unsigned int *, 4) = 5U;
        goto block_43;
    case 5:
        temp_v0_4 = P_func_001D19A8(&D_007812C0, M2C_FIELD(arg0, int *, 0));
        if (temp_v0_4 != 0) {
            M2C_FIELD(M2C_FIELD(arg0, char **, 0xC), int *, 0x2C) = 1;
            if (temp_v0_4 != 0) {
                var_s3 = D_002F0F20[M2C_FIELD(arg0, int *, 0x38)];
            }
        }
        goto block_43;
    case 6:
        temp_v0_5 = P_func_001D19A8(&D_007812C0, M2C_FIELD(arg0, int *, 0));
        if (temp_v0_5 != 0) {
            M2C_FIELD(M2C_FIELD(arg0, char **, 0xC), int *, 0x2C) = 1;
            if (temp_v0_5 != 0) {
                goto block_42;
            }
        }
        goto block_43;
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutPickup__vfunc_03);
#endif

extern "C" void DwfOutPickup__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void DwfOutAtkNear__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutAtkNear__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutAtkNear__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015F37C);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015F744);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0F00);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0F10);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0F20);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015F8AC);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015FEE8);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015FF54);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FA0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FA8);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FB0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FC0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FD0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FE0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FF0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1000);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1010);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1020);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1030);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1040);
