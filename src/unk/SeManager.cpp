#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001CF95C(...) asm("func_001CF95C");
extern "C" int X_strlen(...) asm("strlen");
extern int D_007812C0;

extern "C" void func_001F6CB8(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x88));
    temp_v1 = temp_v0 - 1;
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(arg0) + 0x88)) = temp_v1;
        if (temp_v1 == 0) {
            X_func_001CF95C((int)&D_007812C0);
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/SeManager", func_001F6CEC);

INCLUDE_ASM("asm/nonmatchings/unk/SeManager", func_001F6D20);

extern "C" void func_001F6D84(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x80)) = 0;
}


INCLUDE_RODATA("asm/nonmatchings/unk/SeManager", D_002FE738);

INCLUDE_RODATA("asm/nonmatchings/unk/SeManager", D_002FE748);

INCLUDE_RODATA("asm/nonmatchings/unk/SeManager", D_002FE758);

INCLUDE_RODATA("asm/nonmatchings/unk/SeManager", D_002FE770);

INCLUDE_RODATA("asm/nonmatchings/unk/SeManager", D_002FE780);

INCLUDE_RODATA("asm/nonmatchings/unk/SeManager", D_002FE790);

INCLUDE_RODATA("asm/nonmatchings/unk/SeManager", D_002FE7A0);

INCLUDE_RODATA("asm/nonmatchings/unk/SeManager", D_002FE7B0);

INCLUDE_ASM("asm/nonmatchings/unk/SeManager", func_001F6D8C);

INCLUDE_ASM("asm/nonmatchings/unk/SeManager", func_001F6DFC);

INCLUDE_ASM("asm/nonmatchings/unk/SeManager", func_001F6EDC);

INCLUDE_ASM("asm/nonmatchings/unk/SeManager", SeManager__vfunc_01);
