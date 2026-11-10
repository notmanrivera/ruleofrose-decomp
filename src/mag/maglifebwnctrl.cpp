#include "include_asm.h"
extern "C" int Xii_func_00103428(int) asm("func_00103428");
extern "C" int Xii_func_0010344C(int) asm("func_0010344C");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiiii_func_0012A56C(int, int, int, int) asm("func_0012A56C");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00103428(...) asm("func_00103428");
extern "C" int X_func_0010344C(...) asm("func_0010344C");
extern "C" int X_func_00104150(...) asm("func_00104150");
extern "C" int X_func_00119CEC(...) asm("func_00119CEC");
extern "C" int X_func_0011A704(...) asm("func_0011A704");
extern "C" int X_func_001258A4(...) asm("func_001258A4");
extern "C" int X_func_00125980(...) asm("func_00125980");
extern "C" int X_func_001268B4(...) asm("func_001268B4");
extern "C" int X_func_00126928(...) asm("func_00126928");
extern "C" int X_func_00129F50(...) asm("func_00129F50");
extern "C" int X_func_00129F78(...) asm("func_00129F78");
extern "C" int X_func_0012A394(...) asm("func_0012A394");
extern "C" int X_func_0012A56C(...) asm("func_0012A56C");
extern "C" int X_func_0012AB20(...) asm("func_0012AB20");
extern "C" int X_func_0012ADEC(...) asm("func_0012ADEC");
extern "C" int X_func_0012AF70(...) asm("func_0012AF70");
extern "C" int X_func_0012B0D0(...) asm("func_0012B0D0");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern "C" int X_utlFindIsSet__FP7UtlFind(...) asm("utlFindIsSet__FP7UtlFind");
extern "C" int X_utlFindIsTarget__FP7UtlFindi(...) asm("utlFindIsTarget__FP7UtlFindi");
extern "C" int X_utlFindNearest__FP7UtlFindPfi(...) asm("utlFindNearest__FP7UtlFindPfi");
extern "C" int X_utlFindSet__FP7UtlFindii(...) asm("utlFindSet__FP7UtlFindii");
extern const char D_002EBE28[];

extern "C" int func_001267C0(int arg0, int arg1, int arg2)
{
    return X_utlFindIsTarget__FP7UtlFindi(arg2);
}


extern "C" int func_001267D8(int arg0, int arg1, int arg2, int arg3)
{
    return X_utlFindNearest__FP7UtlFindPfi(arg1, arg3);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_001267F4);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_001268B4);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00126928);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeNull__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeNull__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeWait__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeWait__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFollow__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFollow__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00127558);

extern "C" void MagLifeBwnCtrlModeStay__vfunc_01(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg1) + 0x8)) = 0;
    if ((*(int *)(int *)((char *)(arg1) + 0x70)) != 0) {
        (*(int *)(int *)((char *)(arg1) + 0x78)) = 2;
    }
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeStay__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD30);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD48);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD78);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBDA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBDC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBDD8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBDF0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE48);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE60);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFind__vfunc_01);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBEA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBED8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBF10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBF40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBF80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBFC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC000);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC028);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFind__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00128724);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00128854);

extern "C" void MagLifeBwnCtrlModeFindEnd__vfunc_01(int arg0, int arg1)
{
    M2C_FIELD(arg1, int *, 0x78) = 0;
    if (Xii_func_0010344C(M2C_FIELD(arg1, int *, 0x64)) != 0) {
        M2C_FIELD(arg1, int *, 0x7C) = 1;
        Xii_func_00103428(M2C_FIELD(arg1, int *, 0x64));
        M2C_FIELD(arg1, int *, 8) = 0;
        return;
    }
    M2C_FIELD(arg1, int *, 0x7C) = -1;
    Xiiiii_func_0012A56C(arg1, 1, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFindEnd__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeMove__vfunc_01);

extern "C" int MagLifeBwnCtrlModeMove__vfunc_02(int arg0, int arg1)
{
    int temp_a2;

    temp_a2 = (*(int *)(int *)((char *)(arg1) + 0x70));
    if ((*(int *)(int *)((char *)(temp_a2) + 0xCC0)) != 0) {
        return X_func_0012A56C(arg1, 7, 0, 0);
    }
    if ((*(int *)(int *)((char *)(temp_a2) + 0xCAC)) != 0) {
        X_func_0012A56C(arg1, 7, 0, 0);
    }
}


extern "C" void MagLifeBwnCtrlModeMoveEnd__vfunc_01(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg1) + 0x80)) = 1;
    X_func_0012A56C(arg1, 0, 0, 0);
}


extern "C" void MagLifeBwnCtrlModeMoveEnd__vfunc_02(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeRot__vfunc_01);

extern "C" void MagLifeBwnCtrlModeRot__vfunc_02()
{
    X_func_00126928();
}


extern "C" void MagLifeBwnCtrlModeRotEnd__vfunc_01(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg1) + 0x80)) = 1;
    X_func_0012A56C(arg1, 0, 0, 0);
}


extern "C" void MagLifeBwnCtrlModeRotEnd__vfunc_02(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeDamage__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeDamage__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeBark__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00128E6C);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC108);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC118);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC128);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC138);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC148);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC158);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC168);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC178);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC188);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC198);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC208);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC220);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC230);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeBark__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00129F50);

extern "C" void func_00129F78(int arg0, int arg1, int arg2)
{
    (*(int *)(int *)((char *)(arg1) + 0xC)) = arg2;
    (*(int *)(int *)((char *)(arg1) + 0x8)) = 0xC;
}


extern "C" void MagLifeBwnCtrlModeSitOut__vfunc_01(void) {
}

extern "C" void MagLifeBwnCtrlModeSitOut__vfunc_02(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeHug__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeHug__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeWound__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeWound__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC320);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC328);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC330);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC338);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC340);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC348);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC358);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC360);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC370);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC378);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC380);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC388);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC390);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC398);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC3A0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A394);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A56C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrl__vfunc_02);

extern "C" void MagLifeBwnCtrl__vfunc_09(void) {
}

extern "C" void func_0012A6A8(int arg0, int arg1)
{
    Xiiiii_func_0012A56C((int) arg0, 0xA, arg1, 0);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A6CC);

extern "C" int func_0012A6DC(int arg0, int arg1)
{
    if ((*(int *)(arg0)) == 0xB) {
        return X_func_00129F50(arg0 + 0xF0, arg0, arg1, 0xB);
    }
    return -1;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A71C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A758);

extern "C" void func_0012A7CC(int arg0)
{
    if ((unsigned int) (M2C_FIELD(arg0, int *, 0) - 4) < 2U) {
        M2C_FIELD(arg0, int *, 0x78) = 0;
        Xiiiii_func_0012A56C(arg0, 1, 0, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A808);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A89C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A974);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A9EC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012AA70);

extern "C" void func_0012AAC0(int arg0, float fparg0)
{
    M2C_FIELD(arg0, float *, 0x40) = fparg0;
    Xiiiii_func_0012A56C(arg0, 0, 0, 0);
}

extern "C" void func_0012AAE8(int arg0, float fparg0)
{
    M2C_FIELD(arg0, float *, 0x40) = fparg0;
    Xiiiii_func_0012A56C(arg0, 8, 0, 0);
}

extern "C" int func_0012AB10(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x80));
}


extern "C" void func_0012AB18(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012AB20);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012ADEC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012AF70);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B0D0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B19C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B300);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B3D0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B4A0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B5F8);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B65C);

extern "C" void func_0012B788(int arg0, int arg1)
{
    Xiiiii_func_0012A56C(arg0, 0xC, arg1, 1);
    if (arg1 >= 0) {
        M2C_FIELD(arg0, int *, 0x124) = arg1;
    }
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC448);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B7CC);
