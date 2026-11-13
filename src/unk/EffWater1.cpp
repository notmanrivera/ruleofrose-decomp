#include "include_asm.h"
struct m2c_block12 { int w[3]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_0016A914(int) asm("func_0016A914");
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern int D_00298E08;
extern int _vt$9EffWater1;
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_001787B0);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_00178894);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffMuzzleFlash1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffMuzzleFlash1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_00178C54);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffMuzzleFlash1__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_00178DD8);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_00178E68);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_00178EEC);

extern "C" void updateZDepth__15EffMuzzleFlash1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_001790E4);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", _$_10EffReload1);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffReload1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffReload1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", renderPreMain__10EffReload1PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1Prim__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1Prim__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1Prim__vfunc_08);

extern "C" void updateZDepth__13EffSteam1Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam2__vfunc_05);

extern "C" int EffSteam2Prim__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        *(m2c_block12 *)((char *)(arg0) + 48) = *(m2c_block12 *)((char *)(arg1) + 16);
        var_v0 = 1;
        M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
        M2C_FIELD(arg0, float *, 0x44) = (float) M2C_FIELD(arg1, float *, 0x20);
        M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
        M2C_FIELD(arg0, signed char *, 0x48) = 0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam2Prim__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam2Prim__vfunc_08);

extern "C" void updateZDepth__13EffSteam2Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffCloud1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_0017A410);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffCloud1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffCloud1__vfunc_08);

extern "C" void updateZDepth__9EffCloud1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" void func_0017A918(int arg0)
{
    Xii_func_0016A914(arg0);
    M2C_FIELD(arg0, int *, 0x60) = 0;
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$9EffWater1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", _$_9EffWater1);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E10);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E28);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E50);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E98);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2EB0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2EC0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2ED0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2F10);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2F30);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2F70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FB0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FB8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FD8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FE8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FF8);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffWater1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffWater1__vfunc_05);

extern "C" void liveActivateExec__9EffWater1(int arg0)
{
    int temp_a2;
    int temp_v0;
    int temp_v0_2;
    unsigned short temp_a1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x80);
    temp_a1 = M2C_FIELD(arg0, unsigned short *, 0);
    temp_v0_2 = temp_v0 - 1;
    temp_a2 = temp_v0 + 1;
    if (temp_a1 & 4) {
        M2C_FIELD(arg0, int *, 0x80) = temp_a2;
        if (temp_a2 >= 5) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    } else {
        M2C_FIELD(arg0, int *, 0x80) = temp_v0_2;
        if (temp_v0_2 <= 0) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", renderPreMain__9EffWater1PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_0017AFD8);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", _$_9EffWater3);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffWater3__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffWater3__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffWater3__vfunc_08);
