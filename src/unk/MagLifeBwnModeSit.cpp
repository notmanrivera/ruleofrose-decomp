#include "include_asm.h"
#include "target.h"
extern "C" void X_func_0011A888(int) asm("func_0011A888");
extern "C" void X_func_0011A144(int, void *) asm("func_0011A144");
extern "C" char vtbl_MagLifeBwn[] asm("_vt$10MagLifeBwn");
extern "C" char vtbl_MagLifeBwnModeNull[] asm("_vt$18MagLifeBwnModeNull");
extern "C" char vtbl_MagLifeBwnModeOne[] asm("_vt$17MagLifeBwnModeOne");
extern "C" char vtbl_MagLifeBwnModeWait[] asm("_vt$18MagLifeBwnModeWait");
extern "C" char vtbl_MagLifeBwnModeSit[] asm("_vt$17MagLifeBwnModeSit");
extern "C" char vtbl_MagLifeBwnModeFuse[] asm("_vt$18MagLifeBwnModeFuse");
extern "C" char vtbl_MagLifeBwnModeMove[] asm("_vt$18MagLifeBwnModeMove");
extern "C" char vtbl_MagLifeBwnModePath[] asm("_vt$18MagLifeBwnModePath");
extern "C" char vtbl_MagLifeBwnModeTurn[] asm("_vt$18MagLifeBwnModeTurn");
extern "C" char vtbl_MagLifeBwnModeWall[] asm("_vt$18MagLifeBwnModeWall");
extern "C" char vtbl_MagLifeBwnModeRotate[] asm("_vt$20MagLifeBwnModeRotate");
extern char D_00297418[];
struct BwnVec4 {
    float x, y, z, w;
};
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

extern "C" void func_00125AA4(int arg0)
{
    X_func_0011A888(arg0);
    M2C_FIELD(arg0, void **, 0x14) = vtbl_MagLifeBwn;
#ifdef TARGET_PS2
    *(u_long128 *)((char *)arg0 + 0x80) = 0;
#else
    static const u_long128 zero128 = {{0, 0, 0, 0}};
    *(u_long128 *)((char *)arg0 + 0x80) = zero128;
#endif
    BwnVec4 *v0 = (BwnVec4 *)((char *)arg0 + 0x90);
    v0->x = v0->y = v0->z = 0.0f;
    v0->w = 1.0f;
    BwnVec4 *arr = (BwnVec4 *)((char *)arg0 + 0xA0);
    int i = 0x7E;
    do {
        i--;
        arr->x = arr->y = arr->z = 0.0f;
        arr->w = 1.0f;
        arr++;
    } while (i != -1);
    M2C_FIELD(arg0, int *, 0xCDC) = -1;
    M2C_FIELD(arg0, float *, 0xCE0) = 0.0f;
    M2C_FIELD(arg0, void **, 0xCF0) = vtbl_MagLifeBwnModeNull;
    M2C_FIELD(arg0, void **, 0xCF4) = vtbl_MagLifeBwnModeOne;
    M2C_FIELD(arg0, void **, 0xCF8) = vtbl_MagLifeBwnModeWait;
    M2C_FIELD(arg0, void **, 0xD04) = vtbl_MagLifeBwnModeSit;
    M2C_FIELD(arg0, void **, 0xD08) = vtbl_MagLifeBwnModeFuse;
    M2C_FIELD(arg0, void **, 0xD0C) = vtbl_MagLifeBwnModeMove;
    M2C_FIELD(arg0, void **, 0xD18) = vtbl_MagLifeBwnModePath;
    M2C_FIELD(arg0, void **, 0xD28) = vtbl_MagLifeBwnModeTurn;
    M2C_FIELD(arg0, void **, 0xD2C) = vtbl_MagLifeBwnModeWall;
    M2C_FIELD(arg0, void **, 0xD30) = vtbl_MagLifeBwnModeRotate;
    M2C_FIELD(arg0, int *, 0xCB8) = 0;
    M2C_FIELD(arg0, int *, 0xCBC) = 0;
    M2C_FIELD(arg0, int *, 0xCD0) = 0;
    M2C_FIELD(arg0, int *, 0xCD8) = 0;
    M2C_FIELD(arg0, int *, 0xCE4) = 0;
    M2C_FIELD(arg0, int *, 0xCEC) = 0;
    return X_func_0011A144(arg0, D_00297418);
}

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

extern "C" void init__18MagLifeBwnModeFuseR10MagLifeBwn(int arg0, int arg1)
{
    if ((unsigned int) (M2C_FIELD(arg1, int *, 0x70) - 2) < 2U) {
        return Xiiiii_func_001233F4((int) arg1, 2, 0, 0);
    }
    Xiii_func_00125A20((int) arg1, 0);
    Xii_func_00124E18((int) arg1);
    Xiiis_func_0011A320((int) arg1, (M2C_FIELD(arg1, int *, 0x30) == 3) ? 0x10 : 0xC, -1);
}

extern "C" int term__18MagLifeBwnModeFuseR10MagLifeBwni(int arg0, int arg1, int arg2)
{
    int var_v0;

    if (arg2 == 0) {
        if (M2C_FIELD(arg1, int *, 0x80) == 3) {
            return 1;
        }
        if (Xii_func_0011A028((int) arg1) == 0xD) {
            Xiiis_func_0011A320((int) arg1, 0xE, -1);
            return 0;
        }
        return 1;
    }
    Xii_func_00123BB8((int) arg1);
    var_v0 = Xii_func_0011A054((int) arg1) != 0;
    return var_v0;
}

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
