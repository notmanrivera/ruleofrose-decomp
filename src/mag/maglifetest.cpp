#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00130A2C(...) asm("func_00130A2C");
extern "C" int X_func_0021B550(...) asm("func_0021B550");

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_001308BC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_00130A2C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_00130C34);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_00130DA4);

extern "C" void func_00130DE0(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x30)) = arg1;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", MagLifeNoise__vfunc_06);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED3C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED3D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED408);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", live__11MagLifeTest);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", MagLifeTest__vfunc_16);
