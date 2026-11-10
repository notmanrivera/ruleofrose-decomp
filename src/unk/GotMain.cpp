#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_0016968C(int, int) asm("func_0016968C");
extern "C" int X_func_00165794(...) asm("func_00165794");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D38(...) asm("func_00165D38");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" int X_func_00166048(...) asm("func_00166048");
extern "C" int X_func_00166108(...) asm("func_00166108");
extern "C" int X_func_00166128(...) asm("func_00166128");
extern "C" int X_func_00166178(...) asm("func_00166178");
extern "C" int X_func_00166198(...) asm("func_00166198");
extern "C" int X_func_001696FC(...) asm("func_001696FC");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00158EB4(...) asm("func_00158EB4");
extern "C" int X_func_00158F2C(...) asm("func_00158F2C");
extern "C" int X_func_0015908C(...) asm("func_0015908C");
extern "C" int X_func_00159104(...) asm("func_00159104");
extern "C" int X_func_0015917C(...) asm("func_0015917C");
extern "C" int X_func_001591F4(...) asm("func_001591F4");
extern "C" int X_func_0015926C(...) asm("func_0015926C");
extern "C" int X_func_001592F0(...) asm("func_001592F0");
extern "C" int X_func_00159368(...) asm("func_00159368");
extern "C" int X_func_001593E0(...) asm("func_001593E0");
extern "C" int X_func_00159458(...) asm("func_00159458");
extern "C" int X_func_001594D0(...) asm("func_001594D0");
extern "C" int X_func_00159560(...) asm("func_00159560");
extern "C" int X_func_001595F0(...) asm("func_001595F0");
extern "C" int X_func_00159668(...) asm("func_00159668");
extern "C" int X_func_001596F8(...) asm("func_001596F8");
extern "C" int X_func_00159788(...) asm("func_00159788");
extern "C" int X_func_00159800(...) asm("func_00159800");
extern "C" int X_func_00159AF8(...) asm("func_00159AF8");
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
extern "C" int X_func_001685C0(...) asm("func_001685C0");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_001696FC(...) asm("func_001696FC");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern int D_007812C0;
extern int D_007A3208;

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_001583D4);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotMain__vfunc_04);

extern "C" void GotMain__vfunc_05(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v0_2;

    M2C_FIELD(arg0, int *, 0x40) = 0;
    temp_a0 = M2C_FIELD(arg0, int *, 0x30);
    if (temp_a0 & 2) {
        M2C_FIELD(arg0, int *, 0x3C) = 4;
        M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = 4;
        M2C_FIELD(arg0, int *, 0x40) = 1;
        M2C_FIELD(arg0, int *, 0x30) = 0;
    } else {
        temp_v0 = M2C_FIELD(arg0, int *, 0x24);
        if (temp_v0 != -1) {
            M2C_FIELD(arg0, int *, 0x30) = 0;
            temp_v0_2 = Xiii_func_0016968C(M2C_FIELD(arg0, int *, 0x1C), temp_v0);
            M2C_FIELD(arg0, signed char *, 0x264) = 0;
            M2C_FIELD(arg0, signed char *, 0x265) = 0;
            if (temp_v0_2 != 0) {
                M2C_FIELD(arg0, int *, 0x3C) = temp_v0_2;
                M2C_FIELD(arg0, int *, 0x40) = 1;
            } else {
                M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = (int) M2C_FIELD(arg0, int *, 0x3C);
            }
        } else if (temp_a0 & 1) {
            M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = (int) M2C_FIELD(arg0, int *, 0x3C);
            M2C_FIELD(arg0, int *, 0x40) = 1;
        }
    }
    M2C_FIELD(arg0, int *, 0x30) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotMain__vfunc_02);

extern "C" int func_00158EA0()
{
    return X_func_00165734();
}


extern "C" int func_00158EB4(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 1);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165794(arg0);
    }
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/unk/GotMain", D_002F0D08);

INCLUDE_RODATA("asm/nonmatchings/unk/GotMain", D_002F0D18);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_00158F2C);

extern "C" int func_0015908C(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 7);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165A68(arg0);
    }
    return 0;
}


extern "C" int func_00159104(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 8);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165AA8(arg0);
    }
    return 0;
}


extern "C" int func_0015917C(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 9);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165D38(arg0);
    }
    return 0;
}


extern "C" int func_001591F4(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xA);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165D7C(arg0);
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_0015926C);

extern "C" int func_001592F0(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xC);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166048(arg0);
    }
    return 0;
}


extern "C" int func_00159368(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xD);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166128(arg0);
    }
    return 0;
}


extern "C" int func_001593E0(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xE);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166108(arg0);
    }
    return 0;
}


extern "C" int func_00159458(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xF);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166178(arg0);
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_001594D0);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_00159560);

extern "C" int func_001595F0(int arg0)
{
    int var_a0;
    int temp_v0;
    int var_v0;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0x12);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a0 = 1;
    else var_a0 = 0;
    if (var_a0 != 0) return 0;
    {
        return (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x20))) + 0x3EC)) & 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_00159668);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_001596F8);

extern "C" int func_00159788(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0x15);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166198(arg0);
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_00159800);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_00159AF8);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotOutParts__vfunc_02);

extern "C" int GotOutParts__vfunc_03()
{
    return -1;
}


extern "C" void GotOutParts__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void GotOutTest__vfunc_02(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x4)) = 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotOutTest__vfunc_03);
