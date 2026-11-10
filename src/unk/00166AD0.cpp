#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_001442DC(int) asm("func_001442DC");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001442DC(...) asm("func_001442DC");
extern "C" int X_func_00162B14(...) asm("func_00162B14");
extern "C" int X_func_0016649C(...) asm("func_0016649C");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001DA07C(...) asm("func_001DA07C");
extern "C" int X_func_00202F10(...) asm("func_00202F10");
extern int D_007812C0;
extern int D_007B2140;
extern int D_007B2580;

extern "C" void func_00166AD0(int arg0)
{
    int temp_v0;

    X_func_0016649C((*(int *)(int *)((char *)(arg0) + 0xC)), 1);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    X_func_00202F10((*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0x1F0)));
    (*(int *)(int *)((char *)((*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0x1F8))) + 0x4)) = 0;
    X_func_001DA07C((*(int *)(int *)((char *)(arg0) + 0x8)));
    X_func_0016649C((*(int *)(int *)((char *)(arg0) + 0xC)), 1);
    (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0x2C)) = 1;
    (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0x10)) = 0;
    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x2C));
    if (temp_v0 >= 0) {
        X_func_00180EA8((int)&D_007B2580, temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0x2C)) = -1;
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166B74);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166C8C);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166DA4);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166EB4);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166F50);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001670DC);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167230);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001672E8);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_0016768C);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001677D0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001679B4);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167A64);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167CA0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167D88);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167E38);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001680A0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001681C8);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001682B0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_0016834C);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001683E8);

extern "C" void func_00168478(int arg0)
{
    int temp_v0;
    int var_a1;
    int temp_v1;

    if (M2C_FIELD(arg0, int *, 0x18) == 0) {
        if (!(M2C_FIELD(M2C_FIELD(arg0, int *, 8), int *, 0x120) & 0x400)) {
            temp_v0 = Xii_func_001442DC(M2C_FIELD(arg0, int *, 0));
            var_a1 = 9;
            if ((temp_v0 != 1) && ((temp_v0 >= 2) || (var_a1 = 8, (temp_v0 != 0)))) {
                var_a1 = 0xA;
            }
            Xiiii_func_001680A0(arg0, M2C_FIELD(((var_a1 * 4) + M2C_FIELD(arg0, int *, 0xC)), int *, 0xEC), 0x100);
            temp_v1 = M2C_FIELD(arg0, int *, 8);
            M2C_FIELD(temp_v1, int *, 0x120) = (int) (M2C_FIELD(temp_v1, int *, 0x120) | 0x400);
        }
        M2C_FIELD(arg0, int *, 0x18) = 1;
        M2C_FIELD(arg0, int *, 0x1C) = 1;
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F19E0);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F19F0);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A00);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A10);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A18);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A20);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A28);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A30);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A38);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A40);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A48);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A50);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A58);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A60);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A68);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A70);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A78);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A80);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A88);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A90);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A98);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1AA0);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1AA8);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1AB0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00168520);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001685C0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001687BC);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00168844);

extern "C" void func_0016898C()
{
    X_func_001680A0();
}


INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001689A8);

extern "C" void func_001689E8(int arg0)
{
    int temp_v0_2;
    int temp_s0;
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0xC));
    temp_s0 = temp_v0 + 0x1C8;
    temp_v0_2 = (*(int *)(int *)((char *)(temp_v0) + 0x1C8));
    if (temp_v0_2 != 0) {
        (*(int *)(int *)((char *)(temp_s0) + 0x4)) = 5;
        (*(int *)(int *)((char *)(temp_s0) + 0xC)) = X_func_00162B14((int)&D_007B2140, temp_v0_2);
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00168A30);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00168EA0);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C10);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C18);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C20);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C28);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C30);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C38);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C40);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C48);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C50);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C58);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C60);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C68);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C70);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C78);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_0016913C);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C88);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C90);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1D50);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1D80);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1DE0);
