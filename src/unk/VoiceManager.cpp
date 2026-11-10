#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", VoiceManager__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F7444);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7D8);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7E0);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7F0);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE800);
