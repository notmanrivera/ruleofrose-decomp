#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001A1244(...) asm("func_001A1244");
extern "C" int X_func_001A12A8(...) asm("func_001A12A8");
extern "C" int X_func_00215998(...) asm("func_00215998");
extern "C" int X_func_00260110(...) asm("func_00260110");
extern "C" int X_s(...) asm("s");
extern int D_002D9E80;

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301720);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301730);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301748);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301760);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301778);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301790);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_003017A8);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_003017C0);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_003017D8);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_003017F0);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301808);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_0030180C);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301820);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301838);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301850);

INCLUDE_RODATA("asm/nonmatchings/unk/002155F4", D_00301868);

INCLUDE_ASM("asm/nonmatchings/unk/002155F4", func_002155F4);

extern "C" void func_00215998(int arg0, int arg1)
{
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            X_func_001A1244((int)&D_002D9E80);
        }
        if (arg0 == 0) {
            X_func_001A12A8((int)&D_002D9E80, 2);
        }
    }
}


extern "C" void func_002159F0()
{
    X_func_00215998(1, 0xFFFF);
}


extern "C" void func_00215A10()
{
    X_func_00215998(0, 0xFFFF);
}

