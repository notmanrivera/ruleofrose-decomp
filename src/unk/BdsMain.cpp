#include "include_asm.h"
extern "C" int Xii_func_00202F10(int) asm("func_00202F10");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int Xiiii_func_00180EEC(int, int, int) asm("func_00180EEC");
extern "C" int Xiiiiff_func_001679B4(int, int, int, float, float) asm("func_001679B4");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" int Xiii_func_001694CC(int, int) asm("func_001694CC");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_0014A21C(...) asm("func_0014A21C");
extern "C" int X_func_0014A230(...) asm("func_0014A230");
extern "C" int X_func_0014A240(...) asm("func_0014A240");
extern "C" int X_func_0014A268(...) asm("func_0014A268");
extern "C" int X_func_0014A78C(...) asm("func_0014A78C");
extern "C" int X_func_0014A814(...) asm("func_0014A814");
extern "C" int X_func_00165734(...) asm("func_00165734");
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

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", func_00149D18);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsMain__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsMain__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsMain__vfunc_02);

extern "C" int func_0014A21C()
{
    return X_func_00165734();
}


INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", func_0014A230);

extern "C" int func_0014A240()
{
    return X_func_00118FEC__9MagSystem((int)&D_006E9840) == 4;
}


INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", func_0014A268);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutWalk__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutWalk__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", func_0014A450);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", func_0014A700);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", func_0014A78C);

extern "C" void BdsOutWalk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void func_0014A814(int arg0, int arg1)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x4)) != arg1) {
        (*(int *)(int *)((char *)(arg0) + 0x4)) = arg1;
        (*(int *)(int *)((char *)(arg0) + 0x38)) = 0;
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutStared__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutStared__vfunc_03);

extern "C" void BdsOutStared__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", func_0014A9E8);

extern "C" void BdsOutSearch__vfunc_02(int arg0)
{
    Xiii_func_00166DA4(arg0, 0x64);
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
}

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutSearch__vfunc_03);

extern "C" void BdsOutSearch__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void BdsOutAtk__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, int *, 0x40) = 0;
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    Xiii_func_00166DA4(arg0, 0x64);
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 75.0f);
    M2C_FIELD(arg0, int *, 0x38) = 0;
    Xiii_func_001694CC(arg0, 0xB);
}

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutAtk__vfunc_03);

extern "C" void BdsOutAtk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void BdsOutWin__vfunc_02(int arg0)
{
    int temp_v0;

    Xiiii_func_001680A0(arg0, 0x15, 0x100);
    temp_v0 = Xiii_func_001694CC(arg0, 0xD);
    M2C_FIELD(arg0, int *, 0x2C) = temp_v0;
    Xiiii_func_00180EEC((int) (int)&D_007B2580, temp_v0, 1);
    M2C_FIELD(arg0, int *, 4) = 1;
}

extern "C" int BdsOutWin__vfunc_03(int arg0)
{
    if ((M2C_FIELD(arg0, int *, 4) == 0) && (Xiiiiff_func_001679B4(arg0, M2C_FIELD(arg0, int *, 0x14), 1, M2C_FIELD(arg0, float *, 0x38), 0.7853981405496597f) != 0)) {
        Xii_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
        M2C_FIELD(arg0, int *, 4) = 1;
    }
    return -1;
}

extern "C" void BdsOutWin__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutDead__vfunc_02);

extern "C" int BdsOutDead__vfunc_03()
{
    return -1;
}


extern "C" void BdsOutDead__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF568);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF578);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF588);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF598);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF5A8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF5B0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF5B8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF5C0);
