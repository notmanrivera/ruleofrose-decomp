#include "include_asm.h"
#include "task/cmnitask.h"
#include "task/tsk_scene.h"
extern "C" char vtbl_15ScenePlaySingle[] asm("_vt$15ScenePlaySingle");
extern "C" char vtbl_11PLScenePlay[] asm("_vt$11PLScenePlay");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" void ScenePlaySingle__vfunc_01(int arg0, int arg1);
extern "C" void PLScenePlay__vfunc_06(int arg0, int arg1);
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
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

extern "C" void func_001F764C(ScenePlaySingle *self, int arg1, int arg2)
{
    self->m_vtable = vtbl_15ScenePlaySingle;
    self->m_unk04 = 1;
    self->m_unk00 = arg2;
    self->m_unk08 = arg1;
    self->m_unk0C = -1;
    self->m_unk10 = 0;
    self->m_oid = -1;
}

extern "C" void ScenePlaySingle__vfunc_01(int arg0, int arg1)
{
    M2C_FIELD(arg0, void **, 0x9c) = vtbl_15ScenePlaySingle;
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

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

extern "C" void func_001F8028(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x38) = arg1;
    M2C_FIELD(arg0, int *, 0x34) = arg1;
}

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F8034);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE858);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F81A8);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", ScenePlay__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F836C);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F839C);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE898);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE8A0);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE8B0);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE8B8);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F83F4);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F8CEC);

extern "C" void func_001F8F70(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, void **, 0) = vtbl_11PLScenePlay;
}

extern "C" void PLScenePlay__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, void **, 0x0) = vtbl_11PLScenePlay;
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE980);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE998);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE9A8);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE9B8);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE9D0);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE9E0);
