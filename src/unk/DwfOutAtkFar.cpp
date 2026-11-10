#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfff_func_001044B8(float, float) asm("func_001044B8");
extern "C" int Xii_func_00166AD0(int) asm("func_00166AD0");
extern "C" int Xiii_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" int Xiii_func_00166EB4(int, int) asm("func_00166EB4");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int Xiiii_func_001687BC(int, int, int) asm("func_001687BC");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00160D94(...) asm("func_00160D94");
extern "C" int X_func_00160E44(...) asm("func_00160E44");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_001687BC(...) asm("func_001687BC");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_00180EEC(...) asm("func_00180EEC");
extern "C" int X_func_00202F10(...) asm("func_00202F10");
extern int D_007B205C;
extern int D_007B2580;

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutAtkFar__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutAtkFar__vfunc_03);

extern "C" void DwfOutAtkFar__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00160998);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutStared__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutStared__vfunc_03);

extern "C" void DwfOutStared__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void DwfOutWin__vfunc_02(int arg0)
{
    float temp_f0;

    if (M2C_FIELD((*(int *)&D_007B205C), int *, 0x5CC) != 0) {
        Xiiii_func_001687BC(arg0, 0x44, 0);
        Xiii_func_00166EB4(arg0, 0x64);
        M2C_FIELD(arg0, int *, 0x38) = 0;
        return;
    }
    if ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x10) >= 2U) {
        Xiii_func_00166DA4(arg0, 0x64);
    }
    temp_f0 = Xfff_func_001044B8(100.0f, 200.0f);
    M2C_FIELD(arg0, float *, 0x3C) = temp_f0;
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), temp_f0);
    M2C_FIELD(arg0, int *, 4) = 0;
}

extern "C" int DwfOutWin__vfunc_03()
{
    if ((*(int *)(int *)((char *)(D_007B205C) + 0x5CC)) != 0) {
        X_func_00160E44();
    } else {
        X_func_00160D94();
    }
    return -1;
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00160D94);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00160E44);

extern "C" void DwfOutWin__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutParts__vfunc_02);

extern "C" int DwfOutParts__vfunc_03()
{
    return -1;
}


extern "C" void DwfOutParts__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void DwfOutTest__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiiii_func_001680A0(arg0, 6, 0);
}

extern "C" int DwfOutTest__vfunc_03()
{
    return -1;
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutFort__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1048);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1058);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1068);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1070);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1080);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1090);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F10A0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F10B0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F10C0);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutFort__vfunc_03);

extern "C" void DwfOutFort__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00161AAC);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutIrritate__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutIrritate__vfunc_03);

extern "C" void DwfOutIrritate__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00161DA8);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00161E74);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00161F28);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutDead__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1130);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1138);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1148);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1158);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1160);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1170);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1180);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1190);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F11A8);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F11B8);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutDead__vfunc_03);

extern "C" void DwfOutDead__vfunc_04(int arg0)
{
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 8);
    M2C_FIELD(temp_a1, int *, 0x120) = (int) (M2C_FIELD(temp_a1, int *, 0x120) & ~0x400);
    Xii_func_00166AD0(arg0);
}

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F11E8);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F11F8);
