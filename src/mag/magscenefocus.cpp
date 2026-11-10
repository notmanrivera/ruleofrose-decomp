#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfii_func_00140D40(int, int) asm("func_00140D40");
extern "C" int Xii_func_0014186C(int) asm("func_0014186C");
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140390);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_0014062C);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_001406B8);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140990);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140A84);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEB10);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140B20);

extern "C" void func_00140C68(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0x85408) > 0) {
        M2C_FIELD(arg0, float *, 0x853C8) = Xfii_func_00140D40((int) arg0, arg0 + 0x853FC);
    }
    if (M2C_FIELD(arg0, int *, 0x85418) > 0) {
        M2C_FIELD(arg0, float *, 0x853CC) = Xfii_func_00140D40((int) arg0, arg0 + 0x8540C);
    }
    if (M2C_FIELD(arg0, int *, 0x85428) > 0) {
        M2C_FIELD(arg0, float *, 0x853D0) = Xfii_func_00140D40((int) arg0, arg0 + 0x8541C);
    }
    if (M2C_FIELD(arg0, int *, 0x853D4) != 0) {
        Xii_func_0014186C(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140D40);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140D94);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140E60);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140E88);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140FDC);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEB40);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEB58);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00141184);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_0014159C);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00141634);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEB90);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEBA0);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00141770);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_001417E4);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_0014186C);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEBD0);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_001419D8);
