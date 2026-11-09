#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00166108(...) asm("func_00166108");
extern "C" int X_func_00166198(...) asm("func_00166198");
extern "C" int X_func_0016968C(...) asm("func_0016968C");

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_00150B24);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_02);

extern "C" int func_00151218()
{
    return X_func_00166108();
}


INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_0015122C);

extern "C" int func_0015130C()
{
    return 0;
}


extern "C" int func_00151314()
{
    return X_func_00166198();
}


INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_00151328);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_001513EC);

extern "C" int func_00151424(int arg0)
{
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x244)) + 1;
    (*(int *)(int *)((char *)(arg0) + 0x244)) = temp_v1;
    return (*(int *)(int *)((char *)(arg0) + 0x240)) < temp_v1;
}


extern "C" void func_0015143C(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x240)) = arg1;
    (*(int *)(int *)((char *)(arg0) + 0x244)) = 0;
}


extern "C" int func_00151448(int arg0)
{
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x248)) - 1;
    (*(int *)(int *)((char *)(arg0) + 0x248)) = temp_v1;
    return (unsigned int) ~temp_v1 >> 0x1F;
}


INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_07);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EF9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EF9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EFA00);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EFA08);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_00151508);
