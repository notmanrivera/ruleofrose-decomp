#include "include_asm.h"
struct m2c_v200_10_i { char pad[512]; virtual void v1(); virtual int call(); };
struct m2c_v34_20_i { char pad[52]; virtual void v1(); virtual void v2(); virtual void v3(); virtual int call(); };
struct m2c_v34_18_i { char pad[52]; virtual void v1(); virtual void v2(); virtual int call(); };
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








INCLUDE_ASM("asm/nonmatchings/unk/BdlOutAtk", BdlOutAtk__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/BdlOutAtk", BdlOutAtk__vfunc_03);

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


INCLUDE_ASM("asm/nonmatchings/unk/BdlOutAtk", BdlOutDead__vfunc_02);

extern "C" int BdlOutDead__vfunc_03()
{
    return -1;
}


extern "C" void BdlOutDead__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6A8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6B0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6B8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6C0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6C8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6D0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6D8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6E0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6E8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6F0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6F8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF700);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF708);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF710);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF718);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF720);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF730);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF740);
