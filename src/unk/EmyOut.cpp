#include "include_asm.h"
extern "C" int Xi_func_001442D4() asm("func_001442D4");
extern "C" int Xii_func_00118FEC__9MagSystem(int) asm("func_00118FEC__9MagSystem");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_00165570(int) asm("func_00165570");
extern "C" int Xii_func_0016A6B4(int) asm("func_0016A6B4");
extern "C" int Xiii_func_00165280(int, int) asm("func_00165280");
extern "C" int Xiiif_func_00169A98(int, int, float) asm("func_00169A98");
extern "C" int Xiiii_func_00104394(int, int, int) asm("func_00104394");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00104394(...) asm("func_00104394");
extern "C" int X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_001442D4(...) asm("func_001442D4");
extern "C" int X_func_001636E4(...) asm("func_001636E4");
extern "C" int X_func_00165570(...) asm("func_00165570");
extern "C" int X_func_001664A4(...) asm("func_001664A4");
extern "C" int X_func_00168478(...) asm("func_00168478");
extern "C" int X_func_00168520(...) asm("func_00168520");
extern "C" int X_func_0016913C(...) asm("func_0016913C");
extern "C" int X_func_001DA130(...) asm("func_001DA130");
extern "C" int X_func_001E5660(...) asm("func_001E5660");
extern "C" int X_func_001E5E58(...) asm("func_001E5E58");
extern "C" int X_func_00202F60(...) asm("func_00202F60");
extern "C" int X_func_00202FBC(...) asm("func_00202FBC");
extern "C" int X_func_002039A4(...) asm("func_002039A4");
extern "C" int X_func_00203A00(...) asm("func_00203A00");
extern "C" int X_memset(...) asm("memset");
extern int D_006E9840;
extern int D_007812C0;
extern int D_007B2140;

extern "C" void func_00165010(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x44));
    if (temp_v0 != 0) {
        X_func_00168478(temp_v0);
    }
}


extern "C" void func_00165038(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x44));
    if (temp_v0 != 0) {
        X_func_00168520(temp_v0);
    }
}


extern "C" void func_00165060(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x44));
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(temp_v0) + 0x1C)) = 0;
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165074);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165280);

extern "C" void func_00165398(int arg0, int arg1, int arg2, int arg3)
{
    Xii_func_00165570((int) arg0);
    M2C_FIELD(arg0, int *, 0x154) = arg1;
    M2C_FIELD(arg0, int *, 0x160) = arg2;
    M2C_FIELD(arg0, int *, 0x164) = 0;
    M2C_FIELD(arg0, int *, 0x168) = 0;
    M2C_FIELD(arg0, int *, 0x16C) = Xiiii_func_00104394(1, arg3, 4);
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165404);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165498);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165570);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165638);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_001656B4);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165710);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165734);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165794);

extern "C" int func_00165A68()
{
    if (!(Xii_func_00118FEC__9MagSystem((int) (int)&D_006E9840) != 1) || !(Xi_func_001442D4() != 0)) return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165AA8);

extern "C" int func_00165D38()
{
    if (!(Xii_func_00118FEC__9MagSystem((int) (int)&D_006E9840) != 2) || !(Xi_func_001442D4() != 1)) return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165D7C);

extern "C" void func_00166004(int arg0)
{
    struct { char pad0[16]; float sp10; } stack;

    Xiii_func_00165280((int) arg0, (int)&stack);
    Xii_func_0016A6B4((int)&stack.sp10);
    Xiiif_func_00169A98((int)&stack, (int)&stack.sp10, 60.0f);
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166048);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166108);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166128);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166178);

extern "C" int func_00166198()
{
    if (!(Xii_func_00118FEC__9MagSystem((int) (int)&D_006E9840) != 4) || !(Xi_func_001442D4() != 2)) return 1;
    return 0;
}

extern "C" void func_001661DC(int arg0, int arg1)
{
    if (((unsigned int) (arg1 - 1) >= 2U) && (arg1 != 4)) {
        if (arg1 == 8) {
            goto block_4;
        }
    } else {
block_4:
        (*(int *)(int *)((char *)(arg0) + 0x14)) = 1;
    }
    (*(int *)(int *)((char *)(arg0) + 0x30)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x30)) | arg1);
}


INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_0016621C);

extern "C" void func_00166364(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x1C8) = arg1;
    M2C_FIELD(arg0, int *, 0x1D4) = 0;
    M2C_FIELD(arg0, short *, 0x1D0) = 0;
    M2C_FIELD(arg0, int *, 0x1CC) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166378);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_0016640C);

extern "C" void func_00166434(int arg0)
{
    short idx;
    long ent;
    int fp;
    short base;
    int off;
    int p;

    idx = M2C_FIELD(arg0, short *, 0x1DE);
    if (idx >= 0) {
        p = *(int *) (arg0 + M2C_FIELD(arg0, short *, 0x1E0));
        p += idx * 8;
        ent = *((long *) p - 1);
        fp = (int) (ent >> 32);
    } else {
        fp = M2C_FIELD(arg0, int *, 0x1E0);
    }
    base = M2C_FIELD(arg0, short *, 0x1DC);
    off = (idx >= 0) ? (short) ent + base : base;
    ((void (*)(int)) fp)(arg0 + off);
}

extern "C" void func_0016649C(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x28)) = arg1;
}


INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_001664A4);

extern "C" void func_00166518(int arg0)
{
    X_func_0016913C((*(int *)(int *)((char *)(arg0) + 0x44)));
}


extern "C" void func_00166534(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x1E4)) - 1;
    (*(int *)(int *)((char *)(arg0) + 0x1E4)) = temp_v0;
    if (temp_v0 <= 0) {
        (*(int *)(int *)((char *)(arg0) + 0x1E4)) = 0;
        temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x20));
        (*(int *)(int *)((char *)(temp_v1) + 0x120)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x120)) & ~0x400);
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166568);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1520);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1528);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1530);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1538);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1540);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1548);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1550);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1558);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1560);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1568);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1570);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1578);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1580);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1588);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1590);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1598);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15A0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15A8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15B0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15B8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15C8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15D0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15D8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15E8);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_001665B8);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_001669A4);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166A0C);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166A1C);

extern int _vt$6EmyOut;
extern "C" int Xii_func_00166AD0(int) asm("func_00166AD0");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_6EmyOut(int, int) asm("_$_6EmyOut");

extern "C" void dtor_6EmyOut(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x34) = (int)&_vt$6EmyOut;
    Xii_func_00166AD0(arg0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16A8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16B8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16C8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16D0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16F0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16F8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1700);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1708);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1710);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1718);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F171C);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1720);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1728);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1730);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1738);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1740);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1748);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1750);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F18B8);
