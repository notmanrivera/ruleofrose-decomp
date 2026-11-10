#include "ror.h"
#include "include_asm.h"
struct m2c_v10C_28_i { char pad[268]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual int call(); };
struct m2c_v10C_30_i { char pad[268]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int call(); };
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_func_00139010(...) asm("func_00139010");
extern "C" int X_func_0013CA10(...) asm("func_0013CA10");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern const char D_002ECE90[];
extern const char D_002ECEB8[];
extern "C" void MnuMap__vfunc_02(char *theMenu);
extern "C" void MnuMap__vfunc_05(char *theMenu);
extern "C" void MnuMap__vfunc_06(char *theMenu);
extern "C" void func_0019A650(char *theMenu);
extern "C" void func_0019A740(char *theMenu);
extern "C" void func_0019A754(char *theMenu);
extern "C" void func_001A134C(char *theMenu);
extern "C" void func_001A1414(char *theMenu);
extern "C" void func_001A1428(char *theMenu);
extern "C" void func_001A5AF4(char *theMenu);
extern "C" void func_001A5CC4(char *theMenu);
extern "C" void func_001A5CD8(char *theMenu);
extern "C" void func_001A91F4(char *theMenu);
extern "C" void func_001A92A0(char *theMenu);
extern "C" void func_001A972C(char *theMenu);
extern "C" void func_001AB598(char *theMenu);
extern "C" void func_001AB66C(char *theMenu);
extern "C" void func_001AB680(char *theMenu);
extern "C" void func_001ADFB0(char *theMenu);
extern "C" void func_001AE02C(char *theMenu);
extern "C" void func_001AE040(char *theMenu);
extern "C" void func_001AE520(char *theMenu);
extern "C" void func_001AE600(char *theMenu);
extern "C" void func_001AE614(char *theMenu);
extern "C" void func_001AEACC(char *theMenu);
extern "C" void func_001AED08(char *theMenu);
extern "C" void func_001B099C(char *theMenu);
extern "C" void func_001BDC00(char *theMenu);
extern "C" void func_001BDE58(char *theMenu);
extern "C" void func_001BDFE0(char *theMenu);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenu", D_002ECE90);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenu", func_0012CF3C);

extern "C" void MagLifeMenuSelLang__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x1078) = *(int *)(self + 0x30);
    func_001BDC00(menu);
}


extern "C" void MagLifeMenuSelLang__vfunc_12(char *self)
{
    return func_001BDE58(self + 0x40);
}


extern "C" void MagLifeMenuSelLang__vfunc_06(char *self)
{
    func_001BDFE0(self + 0x40);
}


extern "C" void MagLifeMenuItem__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x1B60) = *(int *)(self + 0x30);
    func_001AEACC(menu);
}


extern "C" void MagLifeMenuItem__vfunc_12(char *self)
{
    return func_001B099C(self + 0x40);
}


extern "C" void MagLifeMenuItem__vfunc_06(char *self)
{
    func_001AED08(self + 0x40);
}


extern "C" void MagLifeMenuMap__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x8) = *(int *)(self + 0x30);
    MnuMap__vfunc_02(menu);
}


extern "C" void MagLifeMenuMap__vfunc_12(char *self)
{
    return MnuMap__vfunc_05(self + 0x40);
}


extern "C" void MagLifeMenuMap__vfunc_06(char *self)
{
    MnuMap__vfunc_06(self + 0x40);
}


extern "C" void MagLifeMenuStock__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x110C) = *(int *)(self + 0x30);
    func_0019A650(menu);
}


extern "C" void MagLifeMenuStock__vfunc_12(char *self)
{
    return func_0019A740(self + 0x40);
}


extern "C" void MagLifeMenuStock__vfunc_06(char *self)
{
    func_0019A754(self + 0x40);
}


extern "C" void MagLifeMenuSave__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x2730) = *(int *)(self + 0x30);
    func_001A5AF4(menu);
}


extern "C" void MagLifeMenuSave__vfunc_12(char *self)
{
    func_001A5CC4(self + 0x40);
}


extern "C" void MagLifeMenuSave__vfunc_06(char *self)
{
    func_001A5CD8(self + 0x40);
}


extern "C" void MagLifeMenuLoad__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x2730) = *(int *)(self + 0x30);
    func_001A5AF4(menu);
}


extern "C" void MagLifeMenuLoad__vfunc_12(char *self)
{
    func_001A5CC4(self + 0x40);
}


extern "C" void MagLifeMenuLoad__vfunc_06(char *self)
{
    func_001A5CD8(self + 0x40);
}


extern "C" void MagLifeMenuOpt__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x10C8) = *(int *)(self + 0x30);
    func_001AB598(menu);
}


extern "C" void MagLifeMenuOpt__vfunc_12(char *self)
{
    return func_001AB66C(self + 0x40);
}


extern "C" void MagLifeMenuOpt__vfunc_06(char *self)
{
    func_001AB680(self + 0x40);
}


extern "C" void MagLifeMenuMovie__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x968) = *(int *)(self + 0x30);
    func_001ADFB0(menu);
}


extern "C" void MagLifeMenuMovie__vfunc_12(char *self)
{
    return func_001AE02C(self + 0x40);
}


extern "C" void MagLifeMenuMovie__vfunc_06(char *self)
{
    func_001AE040(self + 0x40);
}


extern "C" void MagLifeMenuTitle__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x56F0) = *(int *)(self + 0x30);
    func_001A91F4(menu);
}


extern "C" void MagLifeMenuTitle__vfunc_12(char *self)
{
    return func_001A92A0(self + 0x40);
}


extern "C" void MagLifeMenuTitle__vfunc_06(char *self)
{
    func_001A972C(self + 0x40);
}


extern "C" void MagLifeMenuMcd__vfunc_09(char *self)
{
    func_001A134C(self + 0x40);
}


extern "C" void MagLifeMenuMcd__vfunc_12(char *self)
{
    return func_001A1414(self + 0x40);
}


extern "C" void MagLifeMenuMcd__vfunc_06(char *self)
{
    func_001A1428(self + 0x40);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifemenu", func_0012D398);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenu", MagLifeMenuPBook__vfunc_09);

extern "C" void MagLifeMenuPBook__vfunc_12(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x40);
    ((m2c_v10C_28_i *)(temp_v1))->call();
}

extern "C" void MagLifeMenuPBook__vfunc_06(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x40);
    ((m2c_v10C_30_i *)(temp_v1))->call();
}

extern "C" void MagLifeMenuNow__vfunc_09(char *self)
{
    char *menu = self + 0x40;
    *(int *)(menu + 0x90C) = *(int *)(self + 0x30);
    func_001AE520(menu);
}


extern "C" void MagLifeMenuNow__vfunc_12(char *self)
{
    return func_001AE600(self + 0x40);
}


extern "C" void MagLifeMenuNow__vfunc_06(char *self)
{
    func_001AE614(self + 0x40);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifemenu", func_0012D58C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenu", MagLifeMenuBoard3D__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenu", MagLifeMenuBoard3D__vfunc_09);

extern "C" void MagLifeMenuBoard3D__vfunc_10(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x50)) >= 0) {
        if ((*(int *)(int *)((char *)(arg0) + 0x30)) == 0) {
            X_ror_assert(D_002ECE90, 0x300, D_002ECEB8);
        }
        X_func_00139010((*(int *)(int *)((char *)(arg0) + 0x30)), (*(int *)(int *)((char *)(arg0) + 0x50)));
        X_func_0013CA10((*(int *)(int *)((char *)(arg0) + 0x30)));
        (*(int *)(int *)((char *)(arg0) + 0x50)) = -1;
    }
}


extern "C" int MagLifeMenuBoard3D__vfunc_11(int arg0)
{
    return (unsigned int) ~(*(int *)(int *)((char *)(arg0) + 0x50)) >> 0x1F;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifemenu", MagLifeMenuBoard3D__vfunc_12);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenu", D_002ECEB8);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenu", MagLifeMenuBoard3D__vfunc_06);
