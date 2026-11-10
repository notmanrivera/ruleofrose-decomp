#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_func_0021B490(...) asm("func_0021B490");
extern "C" int X_func_00223378(...) asm("func_00223378");
extern "C" int X_func_00223398(...) asm("func_00223398");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001173D4__10DogTexInfoPCcT1(...) asm("func_001173D4__10DogTexInfoPCcT1");
extern "C" int X_releaseTex__10DogTexInfoi(...) asm("releaseTex__10DogTexInfoi");

extern "C" void func_00139540(int arg0)
{
    X_releaseTex__10DogTexInfoi(arg0 + 0x29520);
}


extern "C" void func_00139568(int arg0)
{
    X_func_001173D4__10DogTexInfoPCcT1(arg0 + 0x29520);
}


extern "C" void func_00139590(int arg0, int arg1, int arg2)
{
    int temp_v0;

    temp_v0 = X_func_0021B490(X_func_00223378(), 1, 0x10, 0, 0x11000000, 0x50000001);
    M2C_FIELD(temp_v0, long *, 0) = (long) (((long) 0x10000000 << 0x20) | 0x8008);
    M2C_FIELD(temp_v0, long *, 8) = 0xE;
    X_func_00223398(arg0, X_func_0021B490(temp_v0 + 0x10, 8, 0x30, (arg2 & 1) ? (arg1 + 0x150) : (arg1 + 0x60), 0, 0x50000008));
}

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013963C);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_00139664);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_00139920);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EDFB0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EDFC0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EDFD0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EDFE8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE000);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE020);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE040);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_00139B4C);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE0B8);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013A464);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013A57C);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013A924);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013AB30);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013AD24);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013B20C);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE190);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE1A0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE1C0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE1D0);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013B2AC);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013B580);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013B650);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013B870);

extern "C" void func_0013BCB8(void) {
}

INCLUDE_RODATA("asm/nonmatchings/mag/magscenerender", D_002EE258);

INCLUDE_ASM("asm/nonmatchings/mag/magscenerender", func_0013BCC0__8MagSceneP7I3dDrawP10sceGsDBuffi);
