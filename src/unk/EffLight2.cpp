#include "include_asm.h"
struct EffVec3_v2 {
    float x, y, z;
};
struct EffFoot2Prim_v2 {
    unsigned short flags;
    char pad2[0x22];
    int f24;
    char pad28[0x8];
    EffVec3_v2 pos;
    float w;
    float f40;
    float f44;
    int f48;
};
struct EffFoot2Arg_v2 {
    char pad0[0x10];
    int f10;
    EffVec3_v2 pos;
    float f20;
    float f24;
};
extern "C" int X_12EffFoot2Prim_Eff0_vfunc02(EffFoot2Prim_v2 *, EffFoot2Arg_v2 *) asm("Eff0__vfunc_02");
struct EffFoot1Prim_v2 {
    char pad0[0x30];
    float x, y, z, w;
    int f40;
    int f44;
    int f48;
    float f4C;
    float f50;
};
struct EffFoot1Arg_v2 {
    char pad0[0x10];
    float x, y, z;
    int f1C;
    int f20;
    float f24;
    float f28;
};
extern "C" int X_12EffFoot1Prim_Eff0_vfunc02(EffFoot1Prim_v2 *, EffFoot1Arg_v2 *) asm("Eff0__vfunc_02");
extern "C" float X_12EffFindItem1_16FF18(int, int) asm("func_0016FF18");
extern "C" int Xiiiff_func_00174C4Cb(int, int, float, float) asm("func_00174C4C");
extern "C" int Xiiii_func_00173618(int, int, int, int) asm("func_00173618");
extern "C" int Xiiii_func_00173628(int, int, int, int) asm("func_00173628");
extern "C" int Xiiii_func_001733CC(int, int, int, int) asm("func_001733CC");
extern "C" int Xi_func_00173610() asm("func_00173610");
extern "C" int Xi_func_00173620() asm("func_00173620");
extern "C" int Xii_func_00173380(int) asm("func_00173380");
extern "C" int Xiiiff_func_00174C4C(int, float *, float, float) asm("func_00174C4C");
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
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern int D_00298E08;

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001730D4);

extern "C" int EffFoot1Prim__vfunc_02(EffFoot1Prim_v2 *self, EffFoot1Arg_v2 *arg1)
{
    if (X_12EffFoot1Prim_Eff0_vfunc02(self, arg1) == 0) {
        return 0;
    }
    self->x = arg1->x;
    self->y = arg1->y;
    self->z = arg1->z;
    self->w = 1.0f;
    self->f40 = arg1->f1C;
    self->f44 = arg1->f20;
    self->f4C = arg1->f24;
    self->f50 = arg1->f28;
    self->f48 = 0;
    return 1;
}

extern "C" int EffFoot1Prim__vfunc_05(int arg0)
{
    switch (M2C_FIELD(arg0, int *, 0x44)) {
    case 0:
        return Xii_func_00173380(arg0);
    case 1:
        return Xi_func_00173610();
    case 2:
        return Xi_func_00173620();
    }
    return 0;
}

extern "C" int EffFoot1Prim__vfunc_08(int arg0, int arg1, int arg2, int arg3)
{
    switch (M2C_FIELD(arg0, int *, 0x44)) {
    case 0:
        return Xiiii_func_001733CC(arg0, arg1, arg2, arg3);
    case 1:
        return Xiiii_func_00173618(arg0, arg1, arg2, arg3);
    case 2:
        return Xiiii_func_00173628(arg0, arg1, arg2, arg3);
    }
    return arg3;
}

extern "C" void updateZDepth__12EffFoot1Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int func_00173380(int arg0)
{
    int temp_v0;
    int var_v1;

    var_v1 = 1;
    temp_v0 = M2C_FIELD(arg0, int *, 0x48) + 1;
    M2C_FIELD(arg0, int *, 0x48) = temp_v0;
    if (!((((float) temp_v0 * -0.049999997951090336f) + 1.0f) > 0.0f)) {
        var_v1 = 0;
    }
    return var_v1;
}

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

// D_002F2698: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26A8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26B8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26C8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26D8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26E8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

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

extern "C" int EffFoot2Prim__vfunc_02(EffFoot2Prim_v2 *self, EffFoot2Arg_v2 *arg1)
{
    if (X_12EffFoot2Prim_Eff0_vfunc02(self, arg1) == 0) {
        return 0;
    }
    self->flags |= 0x10;
    self->f24 = arg1->f10;
    self->pos = arg1->pos;
    self->w = 1.0f;
    self->pos.y += -2.0f;
    self->f40 = arg1->f20;
    self->f44 = arg1->f24;
    self->f48 = 0;
    return 1;
}

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

extern "C" void func_00174A60(int arg0, int arg1, int arg2)
{
    float temp_f0;

    if (!((*(unsigned short *)M2C_FIELD(arg0, int *, 0x40)) & 4)) {
        temp_f0 = Xfii_func_00174D14(arg0, arg1);
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
}

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

extern "C" void func_00174BB0(int arg0, int arg1)
{
    Xiiiff_func_00174C4C(arg0, (float *)(arg1 + 4), M2C_FIELD(arg1, float *, 0x2C), M2C_FIELD(arg1, float *, 0x30));
}

extern "C" void func_00174BD8(int arg0, int arg1)
{
    int var_v1;
    unsigned short temp_v1;
    int var_a2;

    temp_v1 = M2C_FIELD(arg1, unsigned short *, 0x24);
    var_v1 = temp_v1 - 1;
    var_a2 = arg1 + (temp_v1 * 0x10) + 0x18;
    if (var_v1 >= 0) {
        for (;;) {
            if ((unsigned short) M2C_FIELD(arg0, unsigned short *, 0x44) >= (unsigned short) M2C_FIELD(var_a2, unsigned short *, 0)) {
                break;
            }
            var_v1 -= 1;
            if (var_v1 < 0) {
                return;
            }
            var_a2 -= 0x10;
        }
        if (var_v1 >= 0) {
            Xiiiff_func_00174C4Cb(arg0, arg1 + 4, M2C_FIELD(var_a2, float *, 4), M2C_FIELD(var_a2, float *, 8));
        }
    }
}

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

extern "C" void liveActivateExec__9EffLight1(int arg0)
{
    int temp_a2;
    int temp_v0;
    int temp_v0_2;
    unsigned short temp_a1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x68);
    temp_a1 = M2C_FIELD(arg0, unsigned short *, 0);
    temp_v0_2 = temp_v0 - 1;
    temp_a2 = temp_v0 + 1;
    if (temp_a1 & 4) {
        M2C_FIELD(arg0, int *, 0x68) = temp_a2;
        if (temp_a2 >= 5) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    } else {
        M2C_FIELD(arg0, int *, 0x68) = temp_v0_2;
        if (temp_v0_2 <= 0) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight2__vfunc_02);

extern "C" int EffLight2__vfunc_05(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x74)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x74)) + 1);
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", render__9EffLight2PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight2__vfunc_08);

extern "C" void liveActivateExec__9EffLight2(int arg0)
{
    int temp_a2;
    int temp_v0;
    int temp_v0_2;
    unsigned short temp_a1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x78);
    temp_a1 = M2C_FIELD(arg0, unsigned short *, 0);
    temp_v0_2 = temp_v0 - 1;
    temp_a2 = temp_v0 + 1;
    if (temp_a1 & 4) {
        M2C_FIELD(arg0, int *, 0x78) = temp_a2;
        if (temp_a2 >= 5) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    } else {
        M2C_FIELD(arg0, int *, 0x78) = temp_v0_2;
        if (temp_v0_2 <= 0) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    }
}

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

extern "C" int func_001764FC(int arg0, int arg1)
{
    int tbl[4] = { 0x0D, 3, 11, 7 };
    return tbl[arg1];
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_0017653C);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001765E8);

extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X___10FileReader(...) asm("__10FileReader");
extern "C" int X___11FileReadReq(...) asm("__11FileReadReq");
extern "C" int X_alloc__9BedMemoryii(...) asm("alloc__9BedMemoryii");
extern "C" int X_apply__C12DogLightPoolPvifi(...) asm("apply__C12DogLightPoolPvifi");
extern "C" int X_free__9BedMemoryPv(...) asm("free__9BedMemoryPv");
extern "C" int X_func_0016AC84(...) asm("func_0016AC84");
extern "C" int X_func_0017762C(...) asm("func_0017762C");
extern "C" int X_func_001776C4(...) asm("func_001776C4");
extern "C" int X_func_00177A8C(...) asm("func_00177A8C");
extern "C" int X_func_00177C00(...) asm("func_00177C00");
extern "C" int X_func_00177E9C(...) asm("func_00177E9C");
extern "C" int X_func_00177EF8(...) asm("func_00177EF8");
extern "C" int X_func_001780C0(...) asm("func_001780C0");
extern "C" int X_func_0017820C(...) asm("func_0017820C");
extern "C" int X_func_00178894(...) asm("func_00178894");
extern "C" int X_func_001BE524__10FileReaderP11FileReadReqi(...) asm("func_001BE524__10FileReaderP11FileReadReqi");
extern "C" int X_func_0021A158(...) asm("func_0021A158");
extern "C" int X_func_0021F7E0(...) asm("func_0021F7E0");
extern "C" int X_func_00223240(...) asm("func_00223240");
extern "C" int X_func_00223250(...) asm("func_00223250");
extern "C" int X_func_00223260(...) asm("func_00223260");
extern "C" int X_func_00226C58(...) asm("func_00226C58");
extern "C" int X_getViewMatrix__9DogCamera(...) asm("getViewMatrix__9DogCamera");
extern "C" int X_memcmp(...) asm("memcmp");
extern "C" int X_memmove(...) asm("memmove");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_render__4Eff0PQ24Eff011RENDERPARAM(...) asm("render__4Eff0PQ24Eff011RENDERPARAM");
extern "C" int X_strlen(...) asm("strlen");
extern int D_00298E08;
extern int D_00298E0C;
extern int D_006E9800;

extern "C" int EffFindItem1__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        var_v0 = 1;
        M2C_FIELD(arg0, float *, 0x30) = (float) M2C_FIELD(arg1, float *, 0x10);
        M2C_FIELD(arg0, float *, 0x34) = (float) M2C_FIELD(arg1, float *, 0x14);
        M2C_FIELD(arg0, float *, 0x38) = (float) M2C_FIELD(arg1, float *, 0x18);
        M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
        M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
        M2C_FIELD(arg0, signed char *, 0x44) = 0;
    }
    return var_v0;
}

extern "C" int EffFindItem1__vfunc_05(int arg0)
{
    M2C_FIELD(arg0, unsigned char *, 0x44) = (unsigned char) ((int) (M2C_FIELD(arg0, unsigned char *, 0x44) + 1) % 45);
    return 1;
}

extern "C" void render__12EffFindItem1PQ24Eff011RENDERPARAM(int arg0)
{
    if ((unsigned char) (*(int *)(unsigned char *)((char *)(arg0) + 0x44)) < 0xFU) {
        X_render__4Eff0PQ24Eff011RENDERPARAM();
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFindItem1__vfunc_08);

extern "C" void updateZDepth__12EffFindItem1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = X_12EffFindItem1_16FF18(D_00298E08 + 0x2AB70, arg0 + 0x30) - M2C_FIELD(arg0, float *, 0x40);
}



INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A18);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A38);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A60);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2AA0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2AB0);
