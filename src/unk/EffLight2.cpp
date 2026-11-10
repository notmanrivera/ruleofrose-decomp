#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfi_func_0010DA4C__8DogActor(int) asm("func_0010DA4C__8DogActor");
extern "C" float Xfii_func_00174D14(int, int) asm("func_00174D14");
extern "C" int Xiiiff_func_0010BCC8__8DogActoriff(int, int, float, float) asm("func_0010BCC8__8DogActoriff");
extern "C" int Xiiiii_func_00173948(int, int, int, int) asm("func_00173948");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0013FE64__8MagSceneii(...) asm("func_0013FE64__8MagSceneii");
extern "C" int X_func_0016FF18(...) asm("func_0016FF18");
extern "C" int X_func_00173380(...) asm("func_00173380");
extern "C" int X_func_001733CC(...) asm("func_001733CC");
extern "C" int X_func_00173610(...) asm("func_00173610");
extern "C" int X_func_00173618(...) asm("func_00173618");
extern "C" int X_func_00173620(...) asm("func_00173620");
extern "C" int X_func_00173628(...) asm("func_00173628");
extern "C" int X_func_00174C4C(...) asm("func_00174C4C");
extern int D_00298E08;

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001730D4);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1Prim__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1Prim__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1Prim__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", updateZDepth__12EffFoot1Prim);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00173380);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001733CC);

extern "C" int func_00173610()
{
    return 0;
}


extern "C" int func_00173618(int arg0, int arg1, int arg2, int arg3)
{
    return arg3;
}


extern "C" int func_00173620()
{
    return 0;
}


extern "C" int func_00173628(int arg0, int arg1, int arg2, int arg3)
{
    return arg3;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot2__vfunc_05);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2698);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F26A8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F26B8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F26C8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F26D8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F26E8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2700);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2710);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2720);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2730);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2760);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2770);

extern "C" void func_00173840(int arg0, int arg1, int arg2)
{
    float temp_f0;
    int temp_v0;

    temp_f0 = Xfi_func_0010DA4C__8DogActor((int) arg1);
    if (temp_f0 >= 0.0f) {
        temp_v0 = Xiiiff_func_0010BCC8__8DogActoriff((int) arg1, -1, temp_f0, temp_f0 + 1.0f);
        if (temp_v0 & 0x10000000) {
            Xiiiii_func_00173948((int) arg0, arg1, (int) "Bip01 L Toe0", arg2);
        }
        if (temp_v0 & 0x20000000) {
            Xiiiii_func_00173948((int) arg0, arg1, (int) "Bip01 R Toe0", arg2);
        }
        if (temp_v0 & 0x04000000) {
            Xiiiii_func_00173948((int) arg0, arg1, (int) "Bip01 L Finger0", arg2);
        }
        if (temp_v0 & 0x08000000) {
            Xiiiii_func_00173948((int) arg0, arg1, (int) "Bip01 R Finger0", arg2);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00173948);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot2Prim__vfunc_02);

extern "C" int EffFoot2Prim__vfunc_05(int arg0)
{
    int temp_v1;

    if ((M2C_FIELD(arg0, unsigned short *, 0) & 2) && (M2C_FIELD(arg0, int *, 0x48) < 0xA5)) {
        M2C_FIELD(arg0, int *, 0x48) = 0xA5;
    }
    temp_v1 = M2C_FIELD(arg0, int *, 0x48) + 1;
    M2C_FIELD(arg0, int *, 0x48) = temp_v1;
    return temp_v1 < 0xB4;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot2Prim__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00173DF8);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", _$_11EffGeneric1);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F27E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F27F0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2800);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2810);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2820);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffGeneric1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffGeneric1__vfunc_05);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2870);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2880);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", renderPreMain__11EffGeneric1PQ24Eff011RENDERPARAM);

extern "C" void func_001749FC(int arg0, int arg1, int arg2)
{
    float temp_f0;

    temp_f0 = Xfii_func_00174D14((int) arg0, arg1);
    if (M2C_FIELD(arg1, unsigned short *, 6) & 1 & 0xFFFF) {
        M2C_FIELD(arg2, float *, 0) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 2) {
        M2C_FIELD(arg2, float *, 4) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 4) {
        M2C_FIELD(arg2, float *, 8) = temp_f0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00174A60);

extern "C" void func_00174AD8(int arg0, int arg1, int arg2)
{
    float temp_f0;

    temp_f0 = Xfii_func_00174D14((int) arg0, arg1);
    if (M2C_FIELD(arg1, unsigned short *, 6) & 1 & 0xFFFF) {
        M2C_FIELD(arg2, float *, 0) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 2) {
        M2C_FIELD(arg2, float *, 4) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 4) {
        M2C_FIELD(arg2, float *, 8) = temp_f0;
    }
}

extern "C" void func_00174B3C(int arg0, int arg1, int arg2)
{
    float temp_f0;

    temp_f0 = Xfii_func_00174D14((int) arg0, arg1);
    if (M2C_FIELD(arg1, unsigned short *, 6) & 1 & 0xFFFF) {
        M2C_FIELD(arg2, float *, 0) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 2) {
        M2C_FIELD(arg2, float *, 4) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 4) {
        M2C_FIELD(arg2, float *, 8) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 8) {
        M2C_FIELD(arg2, float *, 0xC) = temp_f0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00174BB0);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00174BD8);

extern "C" void func_00174C44(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00174C4C);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00174D14);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight1__vfunc_02);

extern "C" int EffLight1__vfunc_05(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x64)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x64)) + 1);
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight1__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", liveActivateExec__9EffLight1);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight2__vfunc_02);

extern "C" int EffLight2__vfunc_05(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x74)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x74)) + 1);
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", render__9EffLight2PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight2__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", liveActivateExec__9EffLight2);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_0017562C);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", _$_9EffLight3);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight3__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight3__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00176430);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F28B0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F28C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F28D0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F28E8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2910);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2930);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2958);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2978);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F29A0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F29C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F29E0);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001764FC);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_0017653C);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001765E8);
