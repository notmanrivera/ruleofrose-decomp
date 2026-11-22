#include "include_asm.h"
extern "C" int Xiif_func_00119B60(int, int, float) asm("func_00119B60");
extern "C" int Xii_func_00124D7C(int) asm("func_00124D7C");
extern "C" int Xii_func_00124E18(int) asm("func_00124E18");
extern "C" int Xiii_func_00125A20(int, int) asm("func_00125A20");
extern "C" void Xiiiii_func_001233F4(int, int, int, int) asm("func_001233F4");
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


extern "C" void func_00125A3C(int arg0, int arg1)
{
    if ((M2C_FIELD(arg0, float *, 0x90) != M2C_FIELD(arg1, float *, 0)) || (M2C_FIELD(arg0, float *, 0x94) != M2C_FIELD(arg1, float *, 4)) || (M2C_FIELD(arg0, float *, 0x98) != M2C_FIELD(arg1, float *, 8))) {
        M2C_FIELD(arg0, u_long128 *, 0x90) = M2C_FIELD(arg1, u_long128 *, 0);
        M2C_FIELD(arg0, int *, 0xCD8) = 1;
    }
}

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

extern "C" void init__18MagLifeBwnModeWaitR10MagLifeBwn(int arg0, int arg1)
{
    int temp_v0;
    int var_a1;

    temp_v0 = Xiif_func_00119B60(arg1, 0, 0.0f);
    M2C_FIELD(arg1, int *, 0x70) = temp_v0;
    var_a1 = 0x25;
    if (M2C_FIELD(arg1, int *, 0x30) != 9) {
        var_a1 = 0x6A;
        if (temp_v0 != 2) {
            var_a1 = (temp_v0 == 3) ? 0x6C : 2;
        }
    }
    Xiiis_func_0011A320((int) arg1, var_a1, -1);
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    Xii_func_00124D7C((int) arg1);
}

extern "C" void init__17MagLifeBwnModeSitR10MagLifeBwn(int arg0, int arg1)
{
    if ((unsigned int) (M2C_FIELD(arg1, int *, 0x70) - 2) < 2U) {
        return Xiiiii_func_001233F4((int) arg1, 2, 0, 0);
    }
    Xiii_func_00125A20((int) arg1, 0);
    Xii_func_00124E18((int) arg1);
    Xiiis_func_0011A320((int) arg1, (M2C_FIELD(arg1, int *, 0x30) == 4) ? 0xF : 7, -1);
}

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

extern "C" void init__18MagLifeBwnModeMoveR10MagLifeBwn(int arg0, int arg1)
{
    int idx = M2C_FIELD(arg1, int *, 8);
    if (M2C_FIELD(arg1, int *, 0xCB8) >= 3) {
        idx = 1;
    }
    int table[4] = { 0x57, 0x4E, 0x60, 0x45 };
    int motion = table[idx] + M2C_FIELD(arg1, int *, 0xC);
    M2C_FIELD(arg0, int *, 4) = motion;
    Xiiis_func_0011A320((int) arg1, motion, -1);
    Xii_func_00124D7C((int) arg1);
    M2C_FIELD(arg0, int *, 8) = 0;
}

extern "C" int live__18MagLifeBwnModeMoveR10MagLifeBwn(int arg0, int arg1)
{
    int temp_v0;
    int temp_v0_2;
    int var_a1;

    temp_v0 = Xiif_func_00119B60(arg1, 0, 75.0f);
    M2C_FIELD(arg1, int *, 0x70) = temp_v0;
    temp_v0_2 = M2C_FIELD(arg0, int *, 8);
    if (temp_v0_2 < 0x2000) {
        if (temp_v0_2 >= 0x1000) {
            if (temp_v0 == 0) {
                Xiiis_func_0011A320((int) arg1, M2C_FIELD(arg0, int *, 4), -1);
                M2C_FIELD(arg0, int *, 8) = 0;
            }
        } else {
            if (temp_v0 == 3) {
                Xiiis_func_0011A320((int) arg1, 0x6B, -1);
                M2C_FIELD(arg0, int *, 8) = 0x1000;
            } else if (temp_v0 == 2) {
                Xiiis_func_0011A320((int) arg1, 0x69, -1);
                M2C_FIELD(arg0, int *, 8) = 0x1000;
            }
        }
    }
    Xii_func_00123BB8((int) arg1);
    return 1;
}
