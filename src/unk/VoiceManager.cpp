#include "include_asm.h"
extern "C" int Xi_func_001F7644() asm("func_001F7644");
extern "C" int Xii___builtin_delete(int) asm("__builtin_delete");
extern int _vt$10EmyManager;
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("VoiceManager__vfunc_01");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("VoiceManager__vfunc_01");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("VoiceManager__vfunc_01");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void func_001F7644(int);
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("VoiceManager__vfunc_01");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern int _vt$12VoiceManager;
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F6F4C);

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F70C8);

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F71B8);

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F723C);

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F728C);

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F7338);

extern "C" void func_001F73D4(int arg0)
{
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = (int)&_vt$12VoiceManager;
}

extern "C" void EmyManager_vfunc06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 12) = (int)&_vt$12VoiceManager;
    func_001F7644(arg0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F7444);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7D8);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7E0);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7F0);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE800);
