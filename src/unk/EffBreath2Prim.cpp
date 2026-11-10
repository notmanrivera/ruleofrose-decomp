#include "include_asm.h"
struct m2c_v94_10_i { char pad[148]; virtual void v1(); virtual int call(); };
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_func_00237408(...) asm("func_00237408");
extern "C" int X_func_00237580(...) asm("func_00237580");
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Prim__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Prim__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Prim__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", updateZDepth__14EffBreath2Prim);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Ground__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Ground__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Ground__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016F55C);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffCameraAnim1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016F80C);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffCameraAnim1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FB70);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FC20);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FC74);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FD4C);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FDA0);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FE88);

extern "C" void func_0016FF18(int arg0, int arg1)
{
    struct { char pad0[16]; } stack;
    int temp_v0;

    ((m2c_v94_10_i *)(arg0))->call();
    X_func_00237408((int)&stack, arg1, arg0 + 0x30);
    X_func_00237580(arg0 + 0x20, (int)&stack);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FF78);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FFEC);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_001700B0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F2278);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F2288);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F2298);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22A8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22D0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22F8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F2310);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_00170158);
