#include "include_asm.h"
#include "mag/maglifepc.h"
extern "C" float Xf_vecDistXZ__FPCfT0(...) asm("vecDistXZ__FPCfT0");
extern "C" int X_func_0011D1B0(...) asm("func_0011D1B0");
extern "C" float func_0012BC20(int arg0, int arg1);
extern "C" int Xiiif_func_0011D3D0(int, int, float) asm("func_0011D3D0");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float X_func_0011CE5C(...) asm("func_0011CE5C");
extern "C" int X_func_0012CAA4(...) asm("func_0012CAA4");
extern "C" int Xii_func_0011DFD0(int) asm("func_0011DFD0");
extern "C" int Xiiii_func_001026B0(int, int, int) asm("func_001026B0");
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern "C" int Xiiiiiif_func_0011D7C0(int, int, int, int, int, float) asm("func_0011D7C0");
extern "C" int Xiiiui_func_0011C1E8(int, int, unsigned int, int) asm("func_0011C1E8");
extern "C" int Xiiuui_func_0011D1CC(int, unsigned int, unsigned int, int) asm("func_0011D1CC");
extern "C" int Xiiuuu_func_0012C104(int, unsigned int, unsigned int, unsigned int) asm("func_0012C104");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001026B0(...) asm("func_001026B0");
extern "C" int X_func_00119F88(...) asm("func_00119F88");
extern "C" int X_func_0011C1E8(...) asm("func_0011C1E8");
extern "C" int X_func_0011D1CC(...) asm("func_0011D1CC");
extern "C" int X_func_0011D7C0(...) asm("func_0011D7C0");
extern "C" int X_func_0011DFD0(...) asm("func_0011DFD0");
extern "C" int X_func_0012C104(...) asm("func_0012C104");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern const char D_002EC8B0[];
extern const char D_002ECAD8[];
extern const char D_002ECAF8[];
extern const char D_002ECB18[];

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012B870);

extern "C" void func_0012BA2C(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x70));
    if (temp_v0 != 0) {
        X_func_00119F88(temp_v0);
    }
}


extern "C" int func_0012BA54(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0) == 0xB) {
        if (M2C_FIELD(arg0, int *, 8) == 3) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012BA80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC4B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC4D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC4F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC510);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC530);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC550);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC570);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC590);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC5B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC5D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC5E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC608);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC628);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC648);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC668);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC680);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC708);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC718);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC720);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC730);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC740);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC750);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC760);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC770);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC780);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC790);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC800);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC810);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC820);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC830);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC840);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC850);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC860);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC870);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC880);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC890);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC8A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC8B0);

extern "C" float func_0012BC20(int arg0, int arg1)
{
    float temp_f0;
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x58);
    M2C_FIELD(arg1, float *, 0) = M2C_FIELD(temp_v0, float *, 0x40);
    M2C_FIELD(arg1, float *, 4) = M2C_FIELD(temp_v0, float *, 0x44);
    M2C_FIELD(arg1, float *, 8) = M2C_FIELD(temp_v0, float *, 0x48);
    M2C_FIELD(arg1, float *, 4) += -120.0f;
    if (M2C_FIELD(arg0, int *, 0x58) == 0) {
        X_ror_assert((int) D_002EC8B0, 0xFB, (int) "m_actor");
    }
    return M2C_FIELD(M2C_FIELD(arg0, int *, 0x58), float *, 0x54);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012BC98);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012BEDC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012C014);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC9C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC9D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC9D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC9F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECA58);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012C104);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECAD8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECAF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB38);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB48);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB58);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB68);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB78);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBB0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBD0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBE0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBF0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC20);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC30);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC50);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC70);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC98);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCB8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCC8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCD8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCE8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECD08);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECD18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECD28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECD38);

extern "C" void func_0012C1FC(int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    if ((unsigned int) (arg3 + 1) >= 4U) {
        Xiiii_ror_assert((int) D_002EC8B0, 0x291, (int) "theCombo >= -1 && theCombo < 3");
    }
    if (arg1 >= 4U) {
        Xiiii_ror_assert((int) D_002EC8B0, 0x292, (int) D_002ECAD8);
    }
    if (arg2 >= 5U) {
        Xiiii_ror_assert((int) D_002EC8B0, 0x293, (int) D_002ECAF8);
    }
    M2C_FIELD(arg0, unsigned int *, 0x124) = arg1;
    M2C_FIELD(arg0, unsigned int *, 0x128) = arg2;
    M2C_FIELD(arg0, unsigned int *, 0x12C) = arg3;
    Xiiiiiif_func_0011D7C0(arg0, Xiiuuu_func_0012C104(arg0, arg1, arg2, arg3), 0, 0, -1, 0.01666669361293316f);
    Xii_func_0011DFD0(arg0);
    Xiiii_func_001026B0(Xiiuui_func_0011D1CC((int) arg0, arg2, arg3, 0), 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012C31C);

extern "C" void func_0012C9C0(int arg0, int arg1, int arg2)
{
    if ((M2C_FIELD(arg0, int *, 0x58) != 0) && ((M2C_FIELD(arg0, int *, 0) != 0xE) || (M2C_FIELD(arg0, int *, 8) >= 8))) {
        Xiiiui_func_0011C1E8(arg0, 0xE, (unsigned int) arg1, 1);
        M2C_FIELD(arg0, int *, 0xC) = arg2;
    }
}

// NON_MATCHING: 3 of 31 instructions
#ifdef NON_MATCHING
extern "C" int func_0012CA28(int arg0)
{
    int ret = M2C_FIELD(arg0, int *, 0x1F0);
    if (ret != 0) {
        DogVector vec;
        X_func_0011CE5C(arg0, &vec, ret, 0);
        return X_func_0012CAA4(arg0, &vec, M2C_FIELD(arg0, int *, 0x1F0));
    }
    ret = M2C_FIELD(arg0, int *, 0x1B0);
    return (ret < 0) ? 0 : ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012CA28);
#endif

extern "C" int func_0012CAA4(int arg0, int arg1, int arg2)
{
    DogVector vec;
    func_0012BC20(arg0, (int)&vec);
    float dist = Xf_vecDistXZ__FPCfT0(&vec, arg1);
    if (X_func_0011D1B0(arg0, arg2) == 0 && dist <= 80.0f) {
        return 4;
    }
    return Xiiif_func_0011D3D0(arg0, arg2, dist);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012CB50);
