#include "include_asm.h"
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
struct Stack8DD8 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    short unk14;
};
extern "C" void X_func_00178EEC(int, Stack8DD8 *) asm("func_00178EEC");
extern "C" int X_func_0021B550(int, int, int) asm("func_0021B550");
struct Stack8E68 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    short unk14;
};
extern "C" void X_8E68_func_00178EEC(int, Stack8E68 *) asm("func_00178EEC");
extern "C" int X_8E68_func_0021B550(int, int, int) asm("func_0021B550");
extern "C" float Xf_func_0022E958(...) asm("func_0022E958");
extern "C" int Xiiii_func_001787B0(int, int, int) asm("func_001787B0");
struct m2c_block12 { int w[3]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_0016A914(int) asm("func_0016A914");
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern int D_00298E08;
extern int _vt$9EffWater1;
extern int X_vt_10EffReload1 asm("_vt$10EffReload1");
extern int D_006E9800;
extern "C" void X_free__9BedMemoryPv(void *, void *) asm("free__9BedMemoryPv");
extern "C" void X_dtor_4Eff0(void *, int) asm("_$_4Eff0");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_9EffWater1(int, int) asm("_$_9EffWater1");
extern "C" void dtor_10EffReload1(int, int) asm("_$_10EffReload1");
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_001787B0);

extern "C" void func_00178894(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 16; i++) {
        Xiiii_func_001787B0(arg0, i, arg1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffMuzzleFlash1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffMuzzleFlash1__vfunc_05);

extern "C" void func_00178C54(int arg0, int arg1, short arg2, float fparg0)
{
    int temp = M2C_FIELD(arg1, unsigned short *, 0xE);

    M2C_FIELD(arg1, unsigned short *, 0xC) = (unsigned short) (M2C_FIELD(arg1, unsigned short *, 0xC) + temp);
    M2C_FIELD(arg1, unsigned short *, 0xE) = (unsigned short) (arg2 + temp);
    M2C_FIELD(arg1, float *, 4) = (float) (M2C_FIELD(arg1, float *, 4) + fparg0);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffMuzzleFlash1__vfunc_08);

extern "C" int func_00178DD8(int arg0, int arg1, int arg2, int arg3)
{
    Stack8DD8 stack;

    if (M2C_FIELD(arg0, short *, 0x5C) < 0x100) {
        return arg3;
    }
    stack.unk08 = arg2;
    stack.unk04 = (*(int *)&D_00298E08) + 0x2AB70;
    stack.unk0C = X_func_0021B550(arg3, 0x42, 0x44);
    stack.unk00 = arg0 + 0x50;
    stack.unk10 = 1.0f;
    stack.unk14 = 1;
    X_func_00178EEC(arg0, &stack);
    return stack.unk0C;
}

extern "C" int func_00178E68(int arg0, int arg1, int arg2, int arg3)
{
    Stack8E68 stack;

    if (M2C_FIELD(arg0, short *, 0x4C) < 0x100) {
        return arg3;
    }
    stack.unk08 = arg2;
    stack.unk04 = (*(int *)&D_00298E08) + 0x2AB70;
    stack.unk0C = X_8E68_func_0021B550(arg3, 0x42, 0x48);
    stack.unk00 = arg0 + 0x40;
    stack.unk10 = 0;
    stack.unk14 = 0;
    X_8E68_func_00178EEC(arg0, &stack);
    return stack.unk0C;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_00178EEC);

extern "C" void updateZDepth__15EffMuzzleFlash1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_001790E4);

extern "C" void dtor_10EffReload1(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&X_vt_10EffReload1;
    if (M2C_FIELD(arg0, void **, 0x2C) != 0) {
        X_free__9BedMemoryPv(&D_006E9800, M2C_FIELD(arg0, void **, 0x2C));
    }
    if (M2C_FIELD(arg0, void **, 0x38) != 0) {
        X_free__9BedMemoryPv(&D_006E9800, M2C_FIELD(arg0, void **, 0x38));
    }
    X_dtor_4Eff0((void *)arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffReload1__vfunc_02);

extern "C" int EffReload1__vfunc_05(int arg0)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 0x24) != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x80) + 1;
        M2C_FIELD(arg0, int *, 0x80) = temp_v0;
        if (((float) temp_v0 / 60.0f) < Xf_func_0022E958(M2C_FIELD(arg0, int *, 0x28))) {
            return 1;
        }
    }
    return 0;
}

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

extern "C" int EffSteam2__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    *(m2c_block12 *)((char *)(arg0) + 36) = *(m2c_block12 *)((char *)(arg1) + 16);
    M2C_FIELD(arg0, float *, 0x30) = M2C_FIELD(arg1, float *, 0x1C);
    M2C_FIELD(arg0, float *, 0x34) = M2C_FIELD(arg1, float *, 0x20);
    M2C_FIELD(arg0, signed char *, 0x38) = (signed char)((Xi_func_0016AD94() * 0x96) / 255);
    return 1;
}

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

extern "C" int EffSteam2Prim__vfunc_05(int arg0)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, unsigned char *, 0x48) + 1;
    M2C_FIELD(arg0, unsigned char *, 0x48) = temp_v1;
    if ((unsigned int) (temp_v1 & 0xFF) >= 0x96U) {
        return 0;
    }
    M2C_FIELD(arg0, float *, 0x34) = (float) (M2C_FIELD(arg0, float *, 0x34) + ((M2C_FIELD(arg0, float *, 0x40) * -0.09999999590218067f) / 30.0f));
    return 1;
}

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

extern "C" void dtor_9EffWater1(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$9EffWater1;
    if (M2C_FIELD(arg0, void **, 0x60) != 0) {
        X_free__9BedMemoryPv(&D_006E9800, M2C_FIELD(arg0, void **, 0x60));
    }
    X_dtor_4Eff0((void *)arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

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
