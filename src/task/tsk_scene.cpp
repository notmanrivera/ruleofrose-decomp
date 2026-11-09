#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001F6CB8(...) asm("func_001F6CB8");
extern "C" int X_func_001F71B8(...) asm("func_001F71B8");
extern "C" int X_func_001F7610(...) asm("func_001F7610");
extern "C" int X_func_001F7644(...) asm("func_001F7644");
extern "C" int X_func_001F76B0(...) asm("func_001F76B0");
extern "C" int X_func_001F76E0(...) asm("func_001F76E0");
extern "C" int X_func_001F7788(...) asm("func_001F7788");
extern "C" int X_func_001F7C0C(...) asm("func_001F7C0C");

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F7570);

extern "C" void func_001F7610(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x8));
    temp_v1 = temp_v0 - 1;
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(arg0) + 0x8)) = temp_v1;
        if (temp_v1 == 0) {
            X_func_001F7644(arg0);
        }
    }
}


extern "C" void func_001F7644(void) {
}

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F764C);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", ScenePlaySingle__vfunc_01);

extern "C" int func_001F76B0(int arg0)
{
    X_func_001F76E0();
    X_func_001F7C0C(arg0);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F76E0);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F7788);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F7C0C);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F7D54);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", ScenePlay__vfunc_06);

extern "C" void ScenePlay__vfunc_03(void) {
}

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", ScenePlay__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F7F68);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F8028);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F8034);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE858);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F81A8);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", ScenePlay__vfunc_04);
