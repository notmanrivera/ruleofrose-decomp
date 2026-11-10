#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiiii_func_001809D8(int, int, int, int) asm("func_001809D8");
extern "C" int Xiiiiiii_func_001E6734(int, int, int, int, int, int) asm("func_001E6734");
extern int D_007B2580;
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0BB0);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0C2C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0D70);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0DF0);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", GamSndMan__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0F1C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E100C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E107C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E111C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E15D0);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1620);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E17B4);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1920);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1FA4);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2178);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2350);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E239C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2704);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2AA0);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2C40);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2DB4);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3138);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E34EC);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3698);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3804);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E386C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3C24);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4120);

extern "C" void func_001E4354(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E435C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E43A4);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E43E0);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4458);

extern "C" void func_001E44B4(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    Xiiiiiii_func_001E6734(arg0, 0x11, 0, 0, 0, -1);
    Xiiiii_func_001809D8((int) (int)&D_007B2580, arg1, arg3, arg4);
    M2C_FIELD(((arg1 * 4) + arg0), int *, 0x1728) = arg2;
}

INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD770);

INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD780);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4540);
