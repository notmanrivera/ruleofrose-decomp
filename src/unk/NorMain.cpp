#include "include_asm.h"
struct m2c_v200_10_i { char pad[512]; virtual void v1(); virtual int call(); };
struct m2c_v34_18_i { char pad[52]; virtual void v1(); virtual void v2(); virtual int call(); };
struct m2c_v34_20_i { char pad[52]; virtual void v1(); virtual void v2(); virtual void v3(); virtual int call(); };
struct m2c_v94_88_iii { char pad[148]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual int call(int, int); };
extern "C" int X_func_0022B3D8(...) asm("func_0022B3D8");
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern int D_006FE6A0;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_0016968C(int, int) asm("func_0016968C");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00166108(...) asm("func_00166108");
extern "C" int X_func_00166198(...) asm("func_00166198");
extern "C" int X_func_0016968C(...) asm("func_0016968C");

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_00150B24);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_04);

extern "C" void NorMain__vfunc_05(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v0_2;

    M2C_FIELD(arg0, int *, 0x40) = 0;
    temp_a0 = M2C_FIELD(arg0, int *, 0x30);
    if (temp_a0 & 2) {
        M2C_FIELD(arg0, int *, 0x3C) = 4;
        M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = 4;
        M2C_FIELD(arg0, int *, 0x40) = 1;
        M2C_FIELD(arg0, int *, 0x30) = 0;
    } else {
        temp_v0 = M2C_FIELD(arg0, int *, 0x24);
        if (temp_v0 != -1) {
            temp_v0_2 = Xiii_func_0016968C(M2C_FIELD(arg0, int *, 0x1C), temp_v0);
            M2C_FIELD(arg0, signed char *, 0x22C) = 0;
            if (temp_v0_2 != 0) {
                M2C_FIELD(arg0, int *, 0x3C) = temp_v0_2;
                M2C_FIELD(arg0, int *, 0x40) = 1;
            } else {
                M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = (int) M2C_FIELD(arg0, int *, 0x3C);
            }
        } else if (temp_a0 & 1) {
            M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = (int) M2C_FIELD(arg0, int *, 0x3C);
            M2C_FIELD(arg0, int *, 0x40) = 1;
        }
    }
    M2C_FIELD(arg0, int *, 0x30) = 0;
}

extern "C" void NorMain__vfunc_06(int arg0)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    if (M2C_FIELD(arg0, int *, 0x40) != 0) {
        ((m2c_v34_20_i *)(M2C_FIELD(arg0, int *, 0x44)))->call();
        ((m2c_v200_10_i *)(arg0))->call();
    }
    M2C_FIELD(arg0, int *, 0x24) = ((m2c_v34_18_i *)(M2C_FIELD(arg0, int *, 0x44)))->call();
}

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_02);

extern "C" int func_00151218()
{
    return X_func_00166108();
}


INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_0015122C);

extern "C" int func_0015130C()
{
    return 0;
}


extern "C" int func_00151314()
{
    return X_func_00166198();
}


INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_00151328);

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_001513EC);

extern "C" int func_00151424(int arg0)
{
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x244)) + 1;
    (*(int *)(int *)((char *)(arg0) + 0x244)) = temp_v1;
    return (*(int *)(int *)((char *)(arg0) + 0x240)) < temp_v1;
}


extern "C" void func_0015143C(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x240)) = arg1;
    (*(int *)(int *)((char *)(arg0) + 0x244)) = 0;
}


extern "C" int func_00151448(int arg0)
{
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x248)) - 1;
    (*(int *)(int *)((char *)(arg0) + 0x248)) = temp_v1;
    return (unsigned int) ~temp_v1 >> 0x1F;
}


INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_07);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EF9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EF9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EFA00);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EFA08);

extern "C" void func_00151508(int arg0)
{
    struct { char pad0[64]; } stack;
    int temp_v1;
    int temp_a0;
    int temp_v0;
    int temp_s0;
    int temp_v0_2;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x20), int *, 0x108);
    if (temp_a0 >= 0) {
        temp_v1 = (int) "p_hit";
        temp_s0 = (int)&D_006FE6A0 + (temp_a0 * 0x4D0);
        if (M2C_FIELD(temp_s0, int *, 0x11C) == 0) {
            Xiiii_ror_assert((int) "dog/dogmodel.h", 0x131, (int) "m_i3r_root");
        }
        if (temp_v1 == 0) {
            Xiiii_ror_assert((int) "dog/dogmodel.h", 0x131, (int) "p");
        }
        temp_v0 = X_func_0022B3D8(M2C_FIELD(temp_s0, int *, 0x11C), temp_v1);
        if (temp_v0 >= 0) {
            ((m2c_v94_88_iii *)(temp_s0))->call((int)&stack, temp_v0);
        }
    }
}
