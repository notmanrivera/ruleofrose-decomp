#include "include_asm.h"
struct m2c_block12 { int w[3]; };
struct m2c_block16 { int w[4]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfi_func_0010DA4C__8DogActor(int) asm("func_0010DA4C__8DogActor");
extern "C" int Xiii_func_00172934(int, int) asm("func_00172934");
extern "C" int Xiiiff_func_0010BCC8__8DogActoriff(int, int, float, float) asm("func_0010BCC8__8DogActoriff");
extern "C" int Xiiii_func_00170158(int, int, int) asm("func_00170158");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_Eff0__vfunc_02(...) asm("Eff0__vfunc_02");
extern "C" int X_func_0016FF18(...) asm("func_0016FF18");
extern "C" int X_func_00170624(...) asm("func_00170624");
extern "C" int X_func_00172934(...) asm("func_00172934");
extern int D_00298E08;
extern int D_00298E14;

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_001702E4);

extern "C" void func_001703C0(int arg0)
{
    float temp_f0;
    int temp_s0;
    int temp_v0;

    temp_s0 = M2C_FIELD(arg0, int *, 4);
    temp_f0 = Xfi_func_0010DA4C__8DogActor(temp_s0);
    if (temp_f0 >= 0.0f) {
        temp_v0 = Xiiiff_func_0010BCC8__8DogActoriff(temp_s0, -1, temp_f0, temp_f0 + 1.0f);
        if (temp_v0 & 0x10000000) {
            Xiiii_func_00170158(arg0, 0, (int) (int) "Bip01 L Toe0");
        }
        if (temp_v0 & 0x20000000) {
            Xiiii_func_00170158(arg0, 1, (int) (int) "Bip01 R Toe0");
        }
        if (temp_v0 & 0x04000000) {
            Xiiii_func_00170158(arg0, 2, (int) (int) "Bip01 L Finger0");
        }
        if (temp_v0 & 0x08000000) {
            Xiiii_func_00170158(arg0, 3, (int) (int) "Bip01 R Finger0");
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffDust2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffDust2__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_00170624);

extern "C" int EffDust2Prim__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        *(m2c_block12 *)((char *)(arg0) + 0x30) = *(m2c_block12 *)((char *)(arg1) + 0x10);
        var_v0 = 1;
        M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
        M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
        *(m2c_block16 *)((char *)(arg0) + 0x50) = *(m2c_block16 *)((char *)(arg1) + 0x20);
        M2C_FIELD(arg0, int *, 0x60) = 0;
    }
    return var_v0;
}

extern "C" int EffDust2Prim__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x60) + 1;
    M2C_FIELD(arg0, int *, 0x60) = temp_v0;
    M2C_FIELD(arg0, float *, 0x34) = (float) (M2C_FIELD(arg0, float *, 0x34) + -0.024999998975545168f);
    return temp_v0 < 0x96;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffDust2Prim__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", updateZDepth__12EffDust2Prim);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFire1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFire1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFire1__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", updateZDepth__8EffFire1);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", liveActivateExec__8EffFire1);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFire1Ex__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2390);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23A0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23B8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23C8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23F0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2400);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", updateZDepth__10EffFire1Ex);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFire2__vfunc_02);

extern "C" int EffFire2__vfunc_05(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x24)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x24)) + 1);
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFire2__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", updateZDepth__8EffFire2);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog1__vfunc_02);

extern "C" int EffFog1__vfunc_05(int arg0)
{
    int temp_hi;

    temp_hi = (int) (M2C_FIELD(arg0, int *, 0x68) + 1) % 540;
    M2C_FIELD(arg0, int *, 0x68) = temp_hi;
    if (temp_hi == 0) {
        M2C_FIELD(arg0, long *, 0x30) = (long) M2C_FIELD(arg0, long *, 0x40);
        M2C_FIELD(arg0, long *, 0x38) = (long) M2C_FIELD(arg0, long *, 0x48);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog1__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", updateZDepth__7EffFog1);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2Prim__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2Prim__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2Prim__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", updateZDepth__11EffFog2Prim);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_00172678);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2438);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2448);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2458);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2470);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F24A0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F24E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2520);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2560);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2580);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F25C0);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_001726B4);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_001727EC);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_00172934);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", _$_7EffFog3);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog3__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog3__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog3Dark__vfunc_02);

extern "C" int EffFog3WeakUp__vfunc_02()
{
    return X_Eff0__vfunc_02() != 0;
}


extern "C" int EffFog3WeakUp__vfunc_05()
{
    if ((*(int *)&D_00298E14) & 1) {
        (*(int *)&D_00298E14) &= ~1;
        Xiii_func_00172934(0, 0x5A);
    }
    return 0;
}
