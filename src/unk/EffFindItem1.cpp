#include "include_asm.h"
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


INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", EffFindItem1__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", updateZDepth__12EffFindItem1);

extern "C" void func_00176A34(void) {
}

extern "C" int func_00176A3C(int arg0)
{
    X___10FileReader(arg0 + 0x129C);
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x444)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x448)) = 0;
    X_memset(arg0 + 4, 0, 0x440);
    X_memset(arg0 + 0x44C, 0, 0x440);
    (*(int *)(int *)((char *)(arg0) + 0xC90)) = 0;
    return X_memset(arg0 + 0xC94, 0, 0x600);
}


INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00176AA0);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00176AFC);

extern "C" void func_00176C50(int arg0)
{
    int temp_v0;

    X_func_0017762C();
    X_func_00178894(arg0, 1);
    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0xC90));
    if (temp_v0 != 0) {
        X_free__9BedMemoryPv((int)&D_006E9800, temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0xC90)) = 0;
    }
    (*(int *)(int *)((char *)(arg0) + 0x12BC)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x12C4)) = 1;
    X_func_001BE524__10FileReaderP11FileReadReqi(arg0 + 0x129C, arg0 + 0x12A4, 0);
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    D_00298E08 = 0;
}


INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2A18);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2A38);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2A60);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2A70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2A80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2A90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2AA0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2AB0);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00176CC8);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_001774E0);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_0017756C);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_0017762C);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_001776C4);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_0017772C);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177830);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_001779B8);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177A8C);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177C00);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177D20);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177E04);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177E24);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177E9C);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177EF8);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00177F54);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2B90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2B98);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2BA8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2BB8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2BC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2BD8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2BE8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2BF8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C00);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C08);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C10);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C18);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C20);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C28);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C30);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C38);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C40);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C48);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C50);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C58);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C60);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C68);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C88);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2C98);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2CA0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2CA8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2CB0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2CC0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2CC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFindItem1", D_002F2CD0);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_001780C0);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_00178148);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_001781D0);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_0017820C);

INCLUDE_ASM("asm/nonmatchings/unk/EffFindItem1", func_001782CC);
