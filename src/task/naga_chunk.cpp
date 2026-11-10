#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern int _vt$11PLScenePlay;
// Translated mechanically from m2c drafts: only what matches byte for byte.

extern "C" void func_001F8F70(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$11PLScenePlay;
}

INCLUDE_ASM("asm/nonmatchings/task/naga_chunk", PLScenePlay__vfunc_06);
