#include "include_asm.h"
extern int _vt$12TskEnemyTurn;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern int D_007B2580;

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyTurn", func_0020313C);

extern "C" void TskEnemyTurn__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x3C));
    if (temp_v0 >= 0) {
        X_func_00180EA8((int)&D_007B2580, temp_v0);
    }
}


extern "C" void TskEnemyTurn__vfunc_03(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x3C));
    if (temp_v0 >= 0) {
        X_func_00180EA8((int)&D_007B2580, temp_v0);
    }
}


extern "C" void func_002034C0(int arg0)
{
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$12TskEnemyTurn;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyTurn", TskEnemyTurn__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyTurn", func_0020350C);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyTurn", TskEnemyTurn__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyTurn", func_00203684);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyTurn", func_00203828);

extern "C" void TskEnemyTurn__vfunc_02(int arg0, int arg1)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x10);
        if (arg1 != 0) {
            if (temp_v0 != 0) {
                M2C_FIELD(temp_v0, float *, 0x1E8) = 9.999999583953922e-08f;
            }
        } else if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, float *, 0x1E8) = (float) M2C_FIELD(arg0, float *, 0x1C);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF5B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF5C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF600);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF620);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF628);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF630);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF638);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF640);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF648);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF650);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyTurn", D_002FF658);
