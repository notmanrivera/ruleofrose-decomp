#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfff_func_001044B8(float, float) asm("func_001044B8");
extern "C" int Xii_func_0014D51C(int) asm("func_0014D51C");
extern "C" int Xii_func_0014D598(int) asm("func_0014D598");
extern "C" int Xiii_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001044B8(...) asm("func_001044B8");
extern "C" int X_func_0014D308(...) asm("func_0014D308");
extern "C" int X_func_0014D320(...) asm("func_0014D320");
extern "C" int X_func_0014D328(...) asm("func_0014D328");
extern "C" int X_func_0014D33C(...) asm("func_0014D33C");
extern "C" int X_func_0014D350(...) asm("func_0014D350");
extern "C" int X_func_0014D384(...) asm("func_0014D384");
extern "C" int X_func_0014D51C(...) asm("func_0014D51C");
extern "C" int X_func_0014D598(...) asm("func_0014D598");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(...) asm("func_00166DA4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_001679B4(...) asm("func_001679B4");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_00169BAC(...) asm("func_00169BAC");
extern int D_006E98FA;
extern int D_007A3350;

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", func_0014CDE4);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtMain__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtMain__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtMain__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", func_0014D308);

extern "C" int func_0014D320()
{
    return 0;
}


extern "C" int func_0014D328()
{
    return X_func_00165A68();
}


extern "C" int func_0014D33C()
{
    return X_func_00165AA8();
}


extern "C" int func_0014D350()
{
    return X_func_00165D7C();
}


extern "C" int func_0014D364()
{
    return 0;
}


extern "C" int func_0014D36C()
{
    return 0;
}


extern "C" int func_0014D374()
{
    return 0;
}


extern "C" int func_0014D37C()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", func_0014D384);

extern "C" void MrtOutYyy__vfunc_02(int arg0)
{
    Xiii_func_00166DA4(arg0, 0x64);
    M2C_FIELD(arg0, int *, 4) = 0;
}

extern "C" int MrtOutYyy__vfunc_03()
{
    return -1;
}


extern "C" void MrtOutYyy__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" int MrtOutSerch__vfunc_02(int arg0)
{
    int temp_a1;

    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x3C);
    switch (temp_a1) {                              
    case 2:
        Xiii_func_00166DA4(arg0, 0);
        return Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
    case 3:
        Xiii_func_00166DA4(arg0, 0x64);
        return Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
    }
}

extern "C" int MrtOutSerch__vfunc_03(int arg0)
{
    int temp_a1;
    int var_a2;
    int var_v0;

    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x3C);
    var_a2 = -1;
    switch (temp_a1) {                              
    case 2:
        var_v0 = Xii_func_0014D51C(arg0);
block_5:
        var_a2 = var_v0;
        break;
    case 3:
        var_v0 = Xii_func_0014D598(arg0);
        goto block_5;
    }
    return var_a2;
}

extern "C" void MrtOutSerch__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", func_0014D51C);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", func_0014D598);

extern "C" void MrtOutAtk__vfunc_02(int arg0)
{
    Xiii_func_00166DA4(arg0, 0x64);
    M2C_FIELD(arg0, int *, 0x38) = 0;
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
    M2C_FIELD(arg0, int *, 4) = 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF720);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF730);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF740);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF750);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF760);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF770);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtOutAtk__vfunc_03);

extern "C" void MrtOutAtk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void MrtOutWin__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, float *, 0x38) = Xfff_func_001044B8(100.0f, 200.0f);
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
    M2C_FIELD(arg0, int *, 4) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtOutWin__vfunc_03);

extern "C" void MrtOutWin__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF798);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7A0);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7A8);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7B0);
