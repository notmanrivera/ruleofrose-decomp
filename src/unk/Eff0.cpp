#include "include_asm.h"
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern "C" int Xii_func_0016A914(int) asm("func_0016A914");
extern "C" int Xii_func_00173DF8(int) asm("func_00173DF8");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern int _vt$4Eff0;
extern int _vt$14EffBloodSpray1;
extern int _vt$14EffBloodSpray2;
extern int _vt$6EffBg1;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
extern "C" int Xii_func_0016BEDC(int) asm("func_0016BEDC");
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
extern "C" int Xiii_func_0016B50C(int, int) asm("func_0016B50C");
extern "C" int Xiii_func_00174BB0(int, int) asm("func_00174BB0");
extern "C" int Xiii_func_00174BD8(int, int) asm("func_00174BD8");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_Eff0__vfunc_02(...) asm("Eff0__vfunc_02");
extern "C" int X_I3rRoot__CheckIdString(...) asm("I3rRoot__CheckIdString");
extern "C" int X_func_00139568(...) asm("func_00139568");
extern "C" int X_func_0016B50C(...) asm("func_0016B50C");
extern "C" int X_func_0016E92C(...) asm("func_0016E92C");
extern "C" int X_func_0016E9F4(...) asm("func_0016E9F4");
extern "C" int X_func_0016FF18(...) asm("func_0016FF18");
extern "C" int X_func_001700B0(...) asm("func_001700B0");
extern "C" int X_func_00174BB0(...) asm("func_00174BB0");
extern "C" int X_func_00174BD8(...) asm("func_00174BD8");
extern "C" int X_func_0017756C(...) asm("func_0017756C");
extern "C" int X_func_0022AAB8(...) asm("func_0022AAB8");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern "C" int X_strcasecmp(...) asm("strcasecmp");
extern const char D_002F21D0[];
extern int D_00298E08;
extern int D_00308050;
extern int D_008282A0;
extern int D_00828378;

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016A8A4);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016A914);

extern "C" void X_Eff0__vfunc_03(int) asm("Eff0__vfunc_03");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_4Eff0(int, int) asm("_$_4Eff0");

extern "C" void dtor_4Eff0(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$4Eff0;
    X_Eff0__vfunc_03(arg0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

extern "C" int Eff0__vfunc_02(int arg0, int arg1)
{
    int temp_v1;

    (*(int *)(int *)((char *)(arg0) + 0x18)) = (int) (*(int *)(int *)((char *)(arg1) + 0x0));
    (*(int *)(int *)((char *)(arg0) + 0x1C)) = (int) (*(int *)(int *)((char *)(arg1) + 0x8));
    temp_v1 = (*(int *)(int *)((char *)(arg1) + 0xC));
    if (temp_v1 != 0) {
        (*(int *)(int *)((char *)(arg0) + 0x14)) = temp_v1;
        (*(int *)(int *)((char *)(temp_v1) + 0x2C)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x2C)) + 1);
    }
    return 1;
}


extern "C" void Eff0__vfunc_03(int arg0)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x14);
    M2C_FIELD(arg0, short *, 0) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    if (temp_v1 != 0) {
        M2C_FIELD(temp_v1, int *, 0x2C) = (int) (M2C_FIELD(temp_v1, int *, 0x2C) - 1);
    }
}

extern "C" void Eff0__vfunc_10(int arg0, int arg1)
{
    unsigned short temp_v0 = (*(unsigned short *)(arg0));

    (*(unsigned short *)(arg0)) = arg1 != 0 ? (temp_v0 & 0xFFFB) : (temp_v0 | 4);
    (*(unsigned short *)(arg0)) |= 8;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", Eff0__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", render__4Eff0PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", renderPreMain__4Eff0PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", createPacketEntry__4Eff0P20tag_I3dRenderStage_s);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016AC84);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016AD94);

extern "C" void func_0016ADD8()
{
    X_memset((int)&D_008282A0, 0, 0xD8);
}


INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016AE00);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E88);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E90);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E98);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EA0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EA8);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EB0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EB8);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EC0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1ED0);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016AF20);

extern "C" void func_0016AFCC(int arg0)
{
    Xii_func_00173DF8(arg0);
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$6EffBg1;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", _$_6EffBg1);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F38);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F40);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBg1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBg1__vfunc_05);

extern "C" void renderPreMain__6EffBg1PQ24Eff011RENDERPARAM(int arg0, int arg1)
{
    int var_s2;
    unsigned short temp_v1;
    int temp_v0;
    int var_s0;

    var_s2 = 0;
    temp_v0 = M2C_FIELD(arg0, int *, 0x40);
    var_s0 = temp_v0 + 0x10;
    if (M2C_FIELD(temp_v0, unsigned short *, 2) != 0) {
        do {
            temp_v1 = M2C_FIELD(var_s0, unsigned short *, 0);
            switch (temp_v1) {                      
            case 4:
                Xiii_func_00174BB0(arg0, var_s0);
                break;
            case 5:
                Xiii_func_00174BD8((int) arg0, var_s0);
                break;
            case 6:
                Xiii_func_0016B50C((int) arg0, var_s0);
                break;
            }
            var_s2 += 1;
            var_s0 += M2C_FIELD(var_s0, unsigned short *, 2);
        } while (var_s2 < (int) M2C_FIELD(M2C_FIELD(arg0, int *, 0x40), unsigned short *, 2));
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016B50C);

extern "C" int func_0016B62C(int arg0)
{
    Xii_func_0016A914(arg0);
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$14EffBloodSpray1;
    return Xiiii_memset(arg0 + 0x40, 0, 0x240);
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray1__vfunc_08);

extern "C" void updateZDepth__14EffBloodSpray1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int func_0016BE14(int arg0)
{
    Xii_func_0016A914(arg0);
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$14EffBloodSpray2;
    M2C_FIELD(arg0, float *, 0x38) = 1.0f;
    M2C_FIELD(arg0, int *, 0x28) = 0;
    M2C_FIELD(arg0, int *, 0x2C) = 0;
    M2C_FIELD(arg0, int *, 0x30) = 0;
    M2C_FIELD(arg0, int *, 0x34) = 0;
    return Xiiii_memset(arg0 + 0x40, 0, 0x550);
}

extern "C" int EffBloodSpray2__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        M2C_FIELD(arg0, int *, 0x30) = (int) M2C_FIELD(arg1, int *, 0x10);
        M2C_FIELD(arg0, int *, 0x34) = (int) M2C_FIELD(arg1, int *, 0x14);
        M2C_FIELD(arg0, float *, 0x38) = (float) M2C_FIELD(arg1, float *, 0x18);
        M2C_FIELD(arg0, int *, 0x28) = (int) M2C_FIELD(arg1, int *, 0x1C);
        M2C_FIELD(arg0, int *, 0x2C) = Xi_func_0016AD94();
        Xii_func_0016BEDC(arg0);
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016BEDC);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray2__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray2__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", updateZDepth__14EffBloodSpray2);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay1__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016CCB8);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016CEBC);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay2__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016D3E4);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay2__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", _$_13EffBloodStay3);

extern "C" int EffBloodStay3__vfunc_02(int arg0, int arg1)
{
    if (Xiii_Eff0__vfunc_02(arg0, arg1) == 0) {
        return 0;
    }
    Xiiii_memset(arg0 + 0x24, 0, 8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay3__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016D8E8);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay3Prim__vfunc_02);

extern "C" int EffBloodStay3Prim__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x48)) + 1;
    (*(int *)(int *)((char *)(arg0) + 0x48)) = temp_v0;
    return temp_v0 < 0xA5;
}


INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay3Prim__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", updateZDepth__10EffBreath1);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E438);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E65C);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1Space__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F90);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1FA0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1FF0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2000);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2010);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2020);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2068);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2080);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20A0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20B0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20C0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20D0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20E0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20F0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2130);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2170);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2180);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2190);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21A0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21C0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21D0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21E0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21F0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2200);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2210);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2230);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2240);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1Space__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E92C);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E9F4);
