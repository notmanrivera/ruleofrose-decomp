#include "include_asm.h"

#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))

extern "C" int X_func_001E6734(...) asm("func_001E6734");
extern int D_007812C0;

extern "C" void func_001F8FB8(void) {
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA48);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F8FC0);

extern "C" void TskSnd__vfunc_04(int arg0)
{
    short idx;
    long ent;
    int fp;
    short base;
    int off;
    int p;

    idx = M2C_FIELD(arg0, short *, 0x26);
    if (idx >= 0) {
        p = *(int *) (arg0 + M2C_FIELD(arg0, short *, 0x28));
        p += idx * 8;
        ent = *((long *) p - 1);
        fp = (int) (ent >> 32);
    } else {
        fp = M2C_FIELD(arg0, int *, 0x28);
    }
    base = M2C_FIELD(arg0, short *, 0x24);
    off = (idx >= 0) ? (short) ent + base : base;
    ((void (*)(int)) fp)(arg0 + off);
}

extern "C" void TskSnd__vfunc_05(int arg0)
{
    int temp_a2;
    int off = 0x18E00;

    if (M2C_FIELD(arg0, int *, 0x34) == 2) {
        temp_a2 = M2C_FIELD(arg0, int *, 0x84);
        X_func_001E6734((int)&D_007812C0 + off, 0xD, temp_a2, temp_a2, 0, -1);
    }
}

extern "C" float func_001F9294(int arg0)
{
    float var_f0;
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x38);
    var_f0 = 0.0f;
    if (temp_v0 > 0) {
        var_f0 = (float) M2C_FIELD(arg0, int *, 0x3C) / (float) temp_v0;
    }
    return var_f0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F92C8);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F93D8);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F9484);

extern "C" int func_001F9550(int arg0, int arg1, int arg2)
{
    int off = 0x18E00;

    X_func_001E6734((int)&D_007812C0 + off, 0xD, arg1, arg2, 0, -1);
    return M2C_FIELD(arg0, int *, 0x3C) > M2C_FIELD(arg0, int *, 0x38);
}

extern "C" int func_001F95A8(int arg0, int arg1, int arg2)
{
    int off = 0x18E00;

    X_func_001E6734((int)&D_007812C0 + off, 0xE, arg1, arg2, 0, -1);
    return M2C_FIELD(arg0, int *, 0x3C) > M2C_FIELD(arg0, int *, 0x38);
}

extern "C" int func_001F9600(int arg0, int arg1, int arg2)
{
    int off = 0x18E00;

    X_func_001E6734((int)&D_007812C0 + off, 0xF, arg1, arg2, 0, -1);
    return M2C_FIELD(arg0, int *, 0x3C) > M2C_FIELD(arg0, int *, 0x38);
}

extern "C" int func_001F9658(int arg0, int *arg1, int *arg2)
{
    *arg1 = M2C_FIELD(arg0, int *, 0x84);
    *arg2 = M2C_FIELD(arg0, int *, 0x88);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F9670);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F96C0);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F974C);

extern "C" int func_001F97C0()
{
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F97C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA70);
