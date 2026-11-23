#include "include_asm.h"
#include "task/cmnitask.h"

#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))

extern "C" char vtbl_9TskAttack[] asm("_vt$9TskAttack");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiiii_func_001F98C0(int, int, int) asm("func_001F98C0");

extern "C" int func_001F985C(int arg0, int arg1, int arg2)
{
    M2C_FIELD(arg0, void **, 0) = vtbl_9TskAttack;
    Xiiii_memset(arg0 + 4, 0, 8);
    M2C_FIELD(arg0, int *, 0x10) = arg1;
    return Xiiii_func_001F98C0(arg0, (int) arg1, (int) arg2);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEA90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEA98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEAA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEAA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEAB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEAB8);

INCLUDE_ASM("asm/nonmatchings/unk/TskAttack", func_001F98C0);

extern "C" void TskAttack__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskAttack", TskAttack__vfunc_04);

extern "C" int func_001F9D74(int arg0)
{
    arg0 += 0x38;
    return M2C_FIELD(arg0, int *, 0)-- < 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskAttack", func_001F9D90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEB40);
