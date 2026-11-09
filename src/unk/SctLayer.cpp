#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_alloc__9BedMemoryii(...) asm("alloc__9BedMemoryii");
extern "C" int X_free__9BedMemoryPv(...) asm("free__9BedMemoryPv");
extern "C" int X_func_0017C3F0(...) asm("func_0017C3F0");
extern "C" int X_func_0017C58C(...) asm("func_0017C58C");
extern "C" int X_func_0017C60C(...) asm("func_0017C60C");
extern "C" int X_func_0017C754(...) asm("func_0017C754");
extern "C" int X_func_0017C7B0(...) asm("func_0017C7B0");
extern "C" int X_func_0017E464(...) asm("func_0017E464");
extern "C" int X_func_0017E4D0(...) asm("func_0017E4D0");
extern "C" int X_memcpy(...) asm("memcpy");
extern int D_006E9800;

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017B7CC);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017B918);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017BA54);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017BB50);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C0F0);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C14C);

extern "C" int func_0017C1F4(int arg0, int arg1, int arg2)
{
    int temp_a1;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int var_s1;
    int var_s0;

    if (arg2 != 0) {
        temp_v0 = X_func_0017C3F0(arg1);
        temp_v0_2 = X_alloc__9BedMemoryii((int)&D_006E9800, temp_v0, -1);
        X_memcpy(temp_v0_2, arg1, temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0x4)) = temp_v0_2;
        (*(int *)(int *)((char *)(arg0) + 0x0)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x0)) | 2);
    } else {
        (*(int *)(int *)((char *)(arg0) + 0x4)) = arg1;
    }
    var_s1 = 0;
    var_s0 = arg0 + 8;
    do {
        temp_a1 = (*(int *)(int *)((char *)(arg0) + 0x4));
        temp_v0_3 = var_s1 * 4;
        var_s1 += 1;
        temp_v0_4 = (*(int *)(int *)((char *)((temp_a1 + temp_v0_3)) + 0x4));
        if (temp_v0_4 != 0) {
            X_func_0017C60C(var_s0, temp_a1 + temp_v0_4, 0);
        }
        var_s0 += 0x18;
    } while (var_s1 < 4);
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C2C0);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C340);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C3F0);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C45C);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C4F4);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C58C);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", SctLayer__vfunc_01);

INCLUDE_RODATA("asm/nonmatchings/unk/SctLayer", D_002F3060);

INCLUDE_RODATA("asm/nonmatchings/unk/SctLayer", D_002F3070);
