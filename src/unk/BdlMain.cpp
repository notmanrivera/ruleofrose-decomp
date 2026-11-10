#include "include_asm.h"
extern "C" int Xii_func_00202F10(int) asm("func_00202F10");
extern "C" int Xiii_func_001694CC(int, int) asm("func_001694CC");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int Xiiii_func_00180EEC(int, int, int) asm("func_00180EEC");
extern "C" int Xiiiiff_func_001679B4(int, int, int, float, float) asm("func_001679B4");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_0014B8C0(...) asm("func_0014B8C0");
extern "C" int X_func_0014B8D4(...) asm("func_0014B8D4");
extern "C" int X_func_0014B8E8(...) asm("func_0014B8E8");
extern "C" int X_func_0014B910(...) asm("func_0014B910");
extern "C" int X_func_0014BE48(...) asm("func_0014BE48");
extern "C" int X_func_0014BED0(...) asm("func_0014BED0");
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00165794(...) asm("func_00165794");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(...) asm("func_00166DA4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_001679B4(...) asm("func_001679B4");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_00180EEC(...) asm("func_00180EEC");
extern "C" int X_func_00202F10(...) asm("func_00202F10");
extern int D_006E9840;
extern int D_007B2580;

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014B3BC);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlMain__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlMain__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlMain__vfunc_02);

extern "C" int func_0014B8C0()
{
    return X_func_00165734();
}


extern "C" int func_0014B8D4()
{
    return X_func_00165794();
}


extern "C" int func_0014B8E8()
{
    return X_func_00118FEC__9MagSystem((int)&D_006E9840) == 4;
}


INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014B910);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutWalk__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutWalk__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014BAF8);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014BDBC);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014BE48);

extern "C" void BdlOutWalk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void func_0014BED0(int arg0, int arg1)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x4)) != arg1) {
        (*(int *)(int *)((char *)(arg0) + 0x4)) = arg1;
        (*(int *)(int *)((char *)(arg0) + 0x38)) = 0;
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutStared__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutStared__vfunc_03);

extern "C" void BdlOutStared__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014C0A4);

extern "C" void BdlOutSearch__vfunc_02(int arg0)
{
    Xiii_func_00166DA4(arg0, 0x64);
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
}

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutSearch__vfunc_03);

extern "C" void BdlOutSearch__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutAtk__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF5C8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF5D8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF5E8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF5F8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF608);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF618);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF628);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF640);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF650);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF658);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF660);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF668);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF670);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF680);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutAtk__vfunc_03);

extern "C" void BdlOutAtk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void BdlOutWin__vfunc_02(int arg0)
{
    int temp_v0;

    Xiiii_func_001680A0(arg0, 0x15, 0x100);
    temp_v0 = Xiii_func_001694CC(arg0, 0xD);
    M2C_FIELD(arg0, int *, 0x2C) = temp_v0;
    Xiiii_func_00180EEC((int) (int)&D_007B2580, temp_v0, 1);
    M2C_FIELD(arg0, int *, 4) = 1;
}

extern "C" int BdlOutWin__vfunc_03(int arg0)
{
    if ((M2C_FIELD(arg0, int *, 4) == 0) && (Xiiiiff_func_001679B4(arg0, M2C_FIELD(arg0, int *, 0x14), 1, M2C_FIELD(arg0, float *, 0x38), 0.7853981405496597f) != 0)) {
        Xii_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
        M2C_FIELD(arg0, int *, 4) = 1;
    }
    return -1;
}

extern "C" void BdlOutWin__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutDead__vfunc_02);

extern "C" int BdlOutDead__vfunc_03()
{
    return -1;
}


extern "C" void BdlOutDead__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6A8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6B0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6B8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6C0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6C8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6D0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6D8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6E0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6E8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6F0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF6F8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF700);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF708);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF710);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF718);
