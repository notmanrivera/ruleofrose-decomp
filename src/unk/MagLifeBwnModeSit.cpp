#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00119B60(...) asm("func_00119B60");
extern "C" int X_func_0011A028(...) asm("func_0011A028");
extern "C" int X_func_0011A054(...) asm("func_0011A054");
extern "C" int X_func_0011A320(...) asm("func_0011A320");
extern "C" int X_func_001233F4(...) asm("func_001233F4");
extern "C" int X_func_00123BB8(...) asm("func_00123BB8");
extern "C" int X_func_00124D7C(...) asm("func_00124D7C");
extern "C" int X_func_00124E18(...) asm("func_00124E18");
extern "C" int X_func_00125A20(...) asm("func_00125A20");

extern "C" void func_00125A20(int arg0, int arg1)
{
    if ((*(int *)(int *)((char *)(arg0) + 0xCD4)) != arg1) {
        (*(int *)(int *)((char *)(arg0) + 0xCD4)) = arg1;
        (*(int *)(int *)((char *)(arg0) + 0xCD8)) = 1;
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", func_00125A3C);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", func_00125A90);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", func_00125AA4);

extern "C" int live__14MagLifeBwnModeR10MagLifeBwn(int arg0, int arg1)
{
    X_func_00123BB8(arg1);
    if (X_func_0011A054(arg1) != 0) {
        X_func_001233F4(arg1, 0, 0, 0);
    }
    return 0;
}


extern "C" void init__18MagLifeBwnModeNullR10MagLifeBwn(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", init__18MagLifeBwnModeWaitR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", init__17MagLifeBwnModeSitR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", term__17MagLifeBwnModeSitR10MagLifeBwni);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", init__18MagLifeBwnModeFuseR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", term__18MagLifeBwnModeFuseR10MagLifeBwni);

INCLUDE_RODATA("asm/nonmatchings/unk/MagLifeBwnModeSit", D_002EBBF8);

INCLUDE_RODATA("asm/nonmatchings/unk/MagLifeBwnModeSit", D_002EBC08);

INCLUDE_RODATA("asm/nonmatchings/unk/MagLifeBwnModeSit", D_002EBC20);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", init__18MagLifeBwnModeMoveR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", live__18MagLifeBwnModeMoveR10MagLifeBwn);
