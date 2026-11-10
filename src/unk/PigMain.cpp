#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_00166EB4(int, int) asm("func_00166EB4");
extern "C" int Xiii_func_0016968C(int, int) asm("func_0016968C");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
extern "C" int X_func_00165794(...) asm("func_00165794");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D38(...) asm("func_00165D38");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" int X_func_00166048(...) asm("func_00166048");
extern "C" int X_func_00166108(...) asm("func_00166108");
extern "C" int X_func_00166128(...) asm("func_00166128");
extern "C" int X_func_00166178(...) asm("func_00166178");
extern "C" int X_func_00166198(...) asm("func_00166198");
extern "C" int X_func_001696FC(...) asm("func_001696FC");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_00119090__9MagSystem(...) asm("func_00119090__9MagSystem");
extern "C" int X_func_0015ACA0(...) asm("func_0015ACA0");
extern "C" int X_func_0015AD18(...) asm("func_0015AD18");
extern "C" int X_func_0015AE78(...) asm("func_0015AE78");
extern "C" int X_func_0015AEF0(...) asm("func_0015AEF0");
extern "C" int X_func_0015AF68(...) asm("func_0015AF68");
extern "C" int X_func_0015AFE0(...) asm("func_0015AFE0");
extern "C" int X_func_0015B058(...) asm("func_0015B058");
extern "C" int X_func_0015B0DC(...) asm("func_0015B0DC");
extern "C" int X_func_0015B154(...) asm("func_0015B154");
extern "C" int X_func_0015B1CC(...) asm("func_0015B1CC");
extern "C" int X_func_0015B244(...) asm("func_0015B244");
extern "C" int X_func_0015B2BC(...) asm("func_0015B2BC");
extern "C" int X_func_0015B34C(...) asm("func_0015B34C");
extern "C" int X_func_0015B3DC(...) asm("func_0015B3DC");
extern "C" int X_func_0015B454(...) asm("func_0015B454");
extern "C" int X_func_0015B4E4(...) asm("func_0015B4E4");
extern "C" int X_func_0015B574(...) asm("func_0015B574");
extern "C" int X_func_0015B5EC(...) asm("func_0015B5EC");
extern "C" int X_func_0015B8B8(...) asm("func_0015B8B8");
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00165794(...) asm("func_00165794");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D38(...) asm("func_00165D38");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" int X_func_00166004(...) asm("func_00166004");
extern "C" int X_func_00166048(...) asm("func_00166048");
extern "C" int X_func_00166108(...) asm("func_00166108");
extern "C" int X_func_00166128(...) asm("func_00166128");
extern "C" int X_func_00166178(...) asm("func_00166178");
extern "C" int X_func_00166198(...) asm("func_00166198");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166EB4(...) asm("func_00166EB4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_001696FC(...) asm("func_001696FC");
extern "C" int X_func_00169F94(...) asm("func_00169F94");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001FAC60(...) asm("func_001FAC60");
extern "C" int X_func_00202F10(...) asm("func_00202F10");
extern int D_006E9840;
extern int D_007812C0;
extern int D_007A3208;
extern int D_007A3350;
extern int D_007A3354;

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015A17C);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigMain__vfunc_04);

extern "C" void PigMain__vfunc_05(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v0_2;

    M2C_FIELD(arg0, int *, 0x40) = 0;
    temp_a0 = M2C_FIELD(arg0, int *, 0x30);
    if (temp_a0 & 2) {
        M2C_FIELD(arg0, int *, 0x3C) = 4;
        M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = 4;
        M2C_FIELD(arg0, int *, 0x40) = 1;
        M2C_FIELD(arg0, int *, 0x30) = 0;
    } else {
        temp_v0 = M2C_FIELD(arg0, int *, 0x24);
        if (temp_v0 != -1) {
            M2C_FIELD(arg0, int *, 0x30) = 0;
            temp_v0_2 = Xiii_func_0016968C(M2C_FIELD(arg0, int *, 0x1C), temp_v0);
            M2C_FIELD(arg0, signed char *, 0x265) = 0;
            M2C_FIELD(arg0, signed char *, 0x264) = 0;
            M2C_FIELD(arg0, signed char *, 0x266) = 0;
            if (temp_v0_2 != 0) {
                M2C_FIELD(arg0, int *, 0x3C) = temp_v0_2;
                M2C_FIELD(arg0, int *, 0x40) = 1;
            } else {
                M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = (int) M2C_FIELD(arg0, int *, 0x3C);
            }
        } else if (temp_a0 & 1) {
            M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0xA4) = (int) M2C_FIELD(arg0, int *, 0x3C);
            M2C_FIELD(arg0, int *, 0x40) = 1;
        }
    }
    M2C_FIELD(arg0, int *, 0x30) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigMain__vfunc_02);

extern "C" int func_0015AC8C()
{
    return X_func_00165734();
}


extern "C" int func_0015ACA0(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 1);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165794(arg0);
    }
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/unk/PigMain", D_002F0D68);

INCLUDE_RODATA("asm/nonmatchings/unk/PigMain", D_002F0D78);

INCLUDE_RODATA("asm/nonmatchings/unk/PigMain", D_002F0D88);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015AD18);

extern "C" int func_0015AE78(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 7);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165A68(arg0);
    }
    return 0;
}


extern "C" int func_0015AEF0(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 8);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165AA8(arg0);
    }
    return 0;
}


extern "C" int func_0015AF68(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 9);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165D38(arg0);
    }
    return 0;
}


extern "C" int func_0015AFE0(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xA);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00165D7C(arg0);
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B058);

extern "C" int func_0015B0DC(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xC);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166048(arg0);
    }
    return 0;
}


extern "C" int func_0015B154(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xD);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166128(arg0);
    }
    return 0;
}


extern "C" int func_0015B1CC(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xE);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166108(arg0);
    }
    return 0;
}


extern "C" int func_0015B244(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0xF);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166178(arg0);
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B2BC);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B34C);

extern "C" int func_0015B3DC(int arg0)
{
    int var_a0;
    int temp_v0;
    int var_v0;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0x12);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a0 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a0 = 1;
    else var_a0 = 0;
    if (var_a0 != 0) return 0;
    {
        return (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x20))) + 0x3EC)) & 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B454);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B4E4);

extern "C" int func_0015B574(int arg0)
{
    int temp_v0;
    int var_a1;

    temp_v0 = X_func_001696FC((*(int *)(int *)((char *)(arg0) + 0x1C)), 0x15);
    if (temp_v0 == 0xB && (*(int *)(int *)((char *)(arg0) + 0x268)) == 0) var_a1 = 1;
    else if (temp_v0 == 0xC && (*(int *)(int *)((char *)(arg0) + 0x26C)) == 0) var_a1 = 1;
    else var_a1 = 0;
    if (var_a1 == 0) {
        return X_func_00166198(arg0);
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B5EC);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B8B8);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigOutParts__vfunc_02);

extern "C" int PigOutParts__vfunc_03()
{
    return -1;
}


extern "C" void PigOutParts__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void PigOutTackle__vfunc_02(int arg0)
{
    Xiii_func_00166EB4(arg0, 0x64);
    M2C_FIELD(arg0, int *, 0x38) = 0;
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 300.0f);
    M2C_FIELD(arg0, int *, 4) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigOutTackle__vfunc_03);

extern "C" void PigOutTackle__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void PigOutTest__vfunc_02(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x4)) = 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigOutTest__vfunc_03);
