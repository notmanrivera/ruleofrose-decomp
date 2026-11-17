#include "include_asm.h"
extern "C" int Xii___builtin_delete(int) asm("__builtin_delete");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern int _vt$7ObjStat;
extern "C" void Xv_ObjStatDtor(int arg0, int arg1) asm("PLScenePlay__vfunc_06");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" void Xv_ObjStatDtor(int arg0, int arg1) asm("PLScenePlay__vfunc_06");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern int _vt$11PLScenePlay;
// Translated mechanically from m2c drafts: only what matches byte for byte.

extern "C" void func_001F8F70(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$11PLScenePlay;
}

extern "C" void Xv_ObjStatDtor(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x0) = (int)&_vt$11PLScenePlay;
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}
