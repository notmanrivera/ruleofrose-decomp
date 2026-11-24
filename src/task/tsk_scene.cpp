#include "include_asm.h"
#include "task/cmnitask.h"
#include "task/tsk_scene.h"
#include "sdk/string.h"
extern "C" void func_001F6CB8(void *);
extern "C" void func_001F71B8(void *);
extern "C" void ScenePlay__vfunc_05(ScenePlay *);
extern "C" void VoiceManager__vfunc_01(void *, int);
extern "C" void SeManager__vfunc_01(void *, int);
extern "C" void DisplayMessage__vfunc_01(void *, int);
extern "C" void __builtin_delete(void *);
extern "C" void ScenePlay__vfunc_03(ScenePlay *);
extern "C" void func_001F6C64(void *);
extern "C" void func_001F6EDC(void *);
extern "C" void func_001F73D4(void *);
extern void *_vt$9ScenePlay[];
extern "C" int func_00279C98(char *, const char *, ...);
extern "C" char *strncpy(char *, const char *, size_t);
extern "C" char vtbl_15ScenePlaySingle[] asm("_vt$15ScenePlaySingle");
extern "C" char vtbl_11PLScenePlay[] asm("_vt$11PLScenePlay");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" void ScenePlaySingle__vfunc_01(int arg0, int arg1);
extern "C" void PLScenePlay__vfunc_06(int arg0, int arg1);
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001F7644(...) asm("func_001F7644");
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

extern "C" void func_001F7D54(ScenePlay *self, int arg1)
{
    self->m_vtable = _vt$9ScenePlay;
    func_001F6C64(self->m_displayMessage);
    func_001F6EDC(self->m_seManager);
    func_001F73D4(self->m_voiceManager);
    ScenePlay__vfunc_03(self);
    self->m_unk3C = arg1;
    self->m_unk30 = 0;
    self->m_camera_eff_id = -1;
    self->m_imd_load_chr_num = 0;
    self->m_unk44 = 0;
    self->m_unk88 = 0;
}

extern "C" void ScenePlay__vfunc_06(ScenePlay *self, int flags)
{
    self->m_vtable = _vt$9ScenePlay;
    ScenePlay__vfunc_05(self);
    VoiceManager__vfunc_01(self->m_voiceManager, 2);
    SeManager__vfunc_01(self->m_seManager, 2);
    DisplayMessage__vfunc_01(self->m_displayMessage, 2);
    if (flags & 1) {
        return __builtin_delete(self);
    }
}

extern "C" void ScenePlay__vfunc_03(ScenePlay *) {
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

extern "C" int ScenePlay__vfunc_04(ScenePlay *self)
{
    for (int i = 0; i < self->m_unk30; i++) {
        func_001F76B0((int)self->m_unk04[i]);
    }
    if (--self->m_unk34 <= 0) {
        return 1;
    }
    func_001F6CB8(self->m_displayMessage);
    func_001F71B8(self->m_seManager);
    func_001F7610((int)self->m_voiceManager);
    return 0;
}

extern "C" void func_001F836C(ScenePlay *self, const char *str)
{
    strncpy(self->m_unk110, str, 0x1F);
    self->m_unk110[0x1F] = '\0';
}

extern "C" char *func_001F839C(char *dst, const char *src)
{
    char buf[0x20];
    strcpy(buf, src);
    *strstr(buf, ".") = '\0';
    func_00279C98(dst, "%s/%s", buf, buf);
    return dst;
}

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
