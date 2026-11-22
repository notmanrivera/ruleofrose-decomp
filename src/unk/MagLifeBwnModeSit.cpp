#include "include_asm.h"
extern "C" int Xii_func_0011A028(int) asm("func_0011A028");
extern "C" int Xii_func_0011A054(int) asm("func_0011A054");
extern "C" int Xii_func_00123BB8(int) asm("func_00123BB8");
extern "C" int Xiiis_func_0011A320(int, int, short) asm("func_0011A320");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00119B60(...) asm("func_00119B60");
extern "C" int X_func_0011A028(...) asm("func_0011A028");
extern "C" int X_func_0011A054(...) asm("func_0011A054");
extern "C" int X_func_0011A320(...) asm("func_0011A320");
extern "C" int X_func_001233F4(...) asm("func_001233F4");
extern "C" int X_func_00123BB8(...) asm("func_00123BB8");
extern "C" int X_func_00124D7C(...) asm("func_00124D7C");
extern "C" int X_func_00124E18(...) asm("func_00124E18");
extern "C" int X_func_00125A20(...) asm("func_00125A20");

extern "C" void func_00125A20(int arg0, int arg1)
{
    if ((*(int *)(int *)((char *)(arg0) + 0xCD4)) != arg1) {
        (*(int *)(int *)((char *)(arg0) + 0xCD4)) = arg1;
        (*(int *)(int *)((char *)(arg0) + 0xCD8)) = 1;
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", func_00125A3C);

extern "C" void func_00125A90(int arg0)
{
    M2C_FIELD(arg0, int *, 0xCEC) = 0;
    M2C_FIELD(arg0, int *, 4) = -1;
    M2C_FIELD(arg0, int *, 0) = -1;
}

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", func_00125AA4);

extern "C" int live__14MagLifeBwnModeR10MagLifeBwn(int arg0, int arg1)
{
    X_func_00123BB8(arg1);
    if (X_func_0011A054(arg1) != 0) {
        X_func_001233F4(arg1, 0, 0, 0);
    }
    return 0;
}


extern "C" void init__18MagLifeBwnModeNullR10MagLifeBwn(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", init__18MagLifeBwnModeWaitR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", init__17MagLifeBwnModeSitR10MagLifeBwn);

extern "C" int term__17MagLifeBwnModeSitR10MagLifeBwni(int arg0, int arg1, int arg2)
{
    int var_v0;

    if (arg2 == 0) {
        if (M2C_FIELD(arg1, int *, 0x80) == 4) {
            return 1;
        }
        if (Xii_func_0011A028((int) arg1) == 8) {
            Xiiis_func_0011A320((int) arg1, 9, -1);
            return 0;
        }
        return 1;
    }
    Xii_func_00123BB8((int) arg1);
    var_v0 = Xii_func_0011A054((int) arg1) != 0;
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", init__18MagLifeBwnModeFuseR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", term__18MagLifeBwnModeFuseR10MagLifeBwni);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", init__18MagLifeBwnModeMoveR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/unk/MagLifeBwnModeSit", live__18MagLifeBwnModeMoveR10MagLifeBwn);
