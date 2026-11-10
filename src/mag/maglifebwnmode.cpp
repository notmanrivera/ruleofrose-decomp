#include "include_asm.h"
extern "C" float Xfi_func_00119FB0(int) asm("func_00119FB0");
extern "C" int Xii_func_00124D7C(int) asm("func_00124D7C");
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern "C" int Xiiis_func_0011A320(int, int, short) asm("func_0011A320");
extern const char D_002EBC70[];
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001264F8(int, int) asm("func_001264F8");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00119B60(...) asm("func_00119B60");
extern "C" int X_func_0011A028(...) asm("func_0011A028");
extern "C" int X_func_0011A03C(...) asm("func_0011A03C");
extern "C" int X_func_0011A054(...) asm("func_0011A054");
extern "C" int X_func_0011A320(...) asm("func_0011A320");
extern "C" int X_func_00123BB8(...) asm("func_00123BB8");
extern "C" int X_func_00124150(...) asm("func_00124150");
extern "C" int X_func_00124D7C(...) asm("func_00124D7C");
extern "C" int X_func_00124E18(...) asm("func_00124E18");
extern "C" int X_func_00125014(...) asm("func_00125014");
extern "C" int X_live__14MagLifeBwnModeR10MagLifeBwn(...) asm("live__14MagLifeBwnModeR10MagLifeBwn");

extern "C" void init__18MagLifeBwnModePathR10MagLifeBwn(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0xC)) = 0;
    X_func_0011A03C(arg1);
    X_func_00125014(arg1);
    X_func_00124D7C(arg1);
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnmode", D_002EBC70);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnmode", live__18MagLifeBwnModePathR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnmode", term__18MagLifeBwnModePathR10MagLifeBwni);

extern "C" void init__18MagLifeBwnModeTurnR10MagLifeBwn(int arg0, int arg1)
{
    X_func_0011A320(arg1, (*(int *)(int *)((char *)(arg1) + 0xC)) + 0x2B, -1);
    X_func_00124D7C(arg1);
}


extern "C" void init__17MagLifeBwnModeOneR10MagLifeBwn(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg1) + 0xCC0)) = 0;
    X_func_0011A320(arg1, 0, -1);
    X_func_0011A320(arg1, (*(int *)(int *)((char *)(arg1) + 0x8)), -1);
    X_func_00124E18(arg1);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnmode", live__17MagLifeBwnModeOneR10MagLifeBwn);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnmode", init__18MagLifeBwnModeWallR10MagLifeBwn);

extern "C" void init__20MagLifeBwnModeRotateR10MagLifeBwn(int arg0, int arg1)
{
    M2C_FIELD(arg0, float *, 4) = (float) M2C_FIELD(arg1, float *, 8);
    Xiii_func_001264F8((int) arg0, (int) arg1);
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnmode", D_002EBCB8);

extern "C" void func_001264F8(int arg0, int arg1)
{
    float temp_f1;
    float var_f1;
    int var_a1;

    temp_f1 = M2C_FIELD(arg0, float *, 4);
    if (!(temp_f1 >= -3.141593039035797f) || !(temp_f1 < 3.141593039035797f)) {
        Xiiii_ror_assert((int) D_002EBC70, 0x278, (int) "(m_target_rot >= -DOG_PI) && (m_target_rot < DOG_PI)");
    }
    M2C_FIELD(arg1, int *, 0xCC0) = 0;
    var_f1 = M2C_FIELD(arg0, float *, 4) - Xfi_func_00119FB0(arg1);
    if (var_f1 < -3.141593039035797f) {
        var_f1 += 6.283186078071594f;
    } else if (var_f1 >= 3.141593039035797f) {
        var_f1 -= 6.283186078071594f;
    }
    var_a1 = 0x39;
    M2C_FIELD(arg0, float *, 8) = var_f1;
    if (!(var_f1 < -1.5707962810993195f)) {
        var_a1 = 0x2C;
        if (!(var_f1 < -0.7853981405496597f)) {
            var_a1 = 0x2B;
            if (!(var_f1 < -0.034906589426100254f)) {
                var_a1 = 0x3A;
                if (!(var_f1 > 1.5707962810993195f)) {
                    var_a1 = 0x2F;
                    if (!(var_f1 > 0.7853981405496597f)) {
                        if (var_f1 > 0.034906589426100254f) {
                            var_a1 = 0x2E;
                            goto block_16;
                        }
                        M2C_FIELD(arg1, int *, 0xCC0) = 1;
                        M2C_FIELD(arg1, int *, 8) = 1;
                        return;
                    }
                }
            }
        }
    }
block_16:
    Xiiis_func_0011A320(arg1, var_a1, -1);
    Xii_func_00124D7C(arg1);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnmode", live__20MagLifeBwnModeRotateR10MagLifeBwn);
