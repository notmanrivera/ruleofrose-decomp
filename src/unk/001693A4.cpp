#include "include_asm.h"
#include "sdk/math.h"
extern "C" int X_func_0025B890(...) asm("func_0025B890");
extern "C" int Xii_func_00169A14(int) asm("func_00169A14");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_00169604(...) asm("func_00169604");
extern "C" int X_func_00180CA8(...) asm("func_00180CA8");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" int X_func_001D7F48(...) asm("func_001D7F48");
extern "C" int X_func_001D81C4(...) asm("func_001D81C4");
extern "C" int X_func_001D859C(...) asm("func_001D859C");
extern "C" int X_func_001D8778(...) asm("func_001D8778");
extern "C" int X_memset(...) asm("memset");
extern int D_007812C0;
extern int D_007B2580;

extern "C" void func_001DA228(void *theObj, int theKind, int *theOut);
extern int D_002F1DF0[];
extern "C" int func_001693A4(int arg0)
{
    unsigned short n;
    func_001DA228((void *)*(int *)(arg0 + 8), 0x5A, (int *)&n);
    if (n >= 6)
        n = 0;
    return D_002F1DF0[n];
}

extern "C" int func_001693EC(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x2C));
    if (temp_v0 < 0) {
        temp_v0_2 = (*(int *)(int *)((char *)(arg0) + 0x30)) - 1;
        (*(int *)(int *)((char *)(arg0) + 0x30)) = temp_v0_2;
        if (temp_v0_2 < 0) {
            (*(int *)(int *)((char *)(arg0) + 0x30)) = X_func_0010423C(arg1, arg2);
            (*(int *)(int *)((char *)(arg0) + 0x2C)) = X_func_001694CC(arg0, arg3);
            return 1;
        }
        goto block_5;
    }
    temp_v0_3 = X_func_00180CA8((int)&D_007B2580, temp_v0);
    if (temp_v0_3 == -1) {
        (*(int *)(int *)((char *)(arg0) + 0x2C)) = temp_v0_3;
    }
block_5:
    return 0;
}


extern "C" void func_0016947C(int arg0)
{
    X_func_00180EA8((int)&D_007B2580, (*(int *)(int *)((char *)(arg0) + 0x2C)));
    (*(int *)(int *)((char *)(arg0) + 0x2C)) = -1;
    (*(int *)(int *)((char *)(arg0) + 0x30)) = X_func_0010423C(8, 0x18);
}


extern "C" void func_001694C4(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x30)) = arg1;
}


INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_001694CC);

extern "C" void func_00169538(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    X_memset(arg0 + 4, 0, 0xA0);
    (*(int *)(int *)((char *)(arg0) + 0xA4)) = arg1;
}


INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016957C);

extern "C" int func_00169604(int arg0, int arg1)
{
    int *p = (int *)(arg0 + arg1 * 4);
    return p[1];
}

extern "C" void func_00169614(int arg0, int arg1, int arg2)
{
    int *p = (int *)(arg0 + arg1 * 4);
    p[1] = arg2;
    (*(int *)(arg0)) += 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169630);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016968C);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_001696FC);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016976C);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1DF0);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169810);

extern "C" float vecLength_00169A14(const float *v) asm("func_00169A14");
extern "C" float vecLength_00169A14(const float *v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

extern "C" void func_00169A68(int arg0, int arg1)
{
    struct { char pad0[16]; } stack;
    X_func_0025B890((int)&stack, arg0, arg1);
    Xii_func_00169A14((int)&stack);
}

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169A98);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169B0C);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169BAC);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169F94);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A1DC);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A424);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A594);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A6B4);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A7AC);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E10);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E20);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E30);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E38);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E48);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E50);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E58);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E60);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E68);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E70);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E78);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E80);
