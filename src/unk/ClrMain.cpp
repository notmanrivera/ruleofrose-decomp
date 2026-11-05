#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001044B8(...) asm("func_001044B8");
extern "C" int X_func_0014E2EC(...) asm("func_0014E2EC");
extern "C" int X_func_0014E300(...) asm("func_0014E300");
extern "C" int X_func_0014E314(...) asm("func_0014E314");
extern "C" int X_func_0014E328(...) asm("func_0014E328");
extern "C" int X_func_0014E33C(...) asm("func_0014E33C");
extern "C" int X_func_0014E350(...) asm("func_0014E350");
extern "C" int X_func_0014E364(...) asm("func_0014E364");
extern "C" int X_func_0014E36C(...) asm("func_0014E36C");
extern "C" int X_func_0014E374(...) asm("func_0014E374");
extern "C" int X_func_0014E37C(...) asm("func_0014E37C");
extern "C" int X_func_0014E384(...) asm("func_0014E384");
extern "C" int X_func_0014E38C(...) asm("func_0014E38C");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" int X_func_0016649C(...) asm("func_0016649C");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(...) asm("func_00166DA4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_00169BAC(...) asm("func_00169BAC");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern int D_007812C0;
extern int D_007A3350;
extern int D_007B205C;

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_07);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_02);

extern "C" int func_0014E2EC()
{
    return X_func_00165A68();
}


extern "C" int func_0014E300()
{
    return X_func_00165A68();
}


extern "C" int func_0014E314()
{
    return X_func_00165AA8();
}


extern "C" int func_0014E328()
{
    return X_func_00165AA8();
}


extern "C" int func_0014E33C()
{
    return X_func_00165D7C();
}


extern "C" int func_0014E350()
{
    return X_func_00165D7C();
}


extern "C" int func_0014E364()
{
    return 0;
}


extern "C" int func_0014E36C()
{
    return 0;
}


extern "C" int func_0014E374()
{
    return 0;
}


extern "C" int func_0014E37C()
{
    return 0;
}


extern "C" int func_0014E384()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E38C);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E3D0);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E4D4);

extern "C" void ClrOutUp__vfunc_02(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0xAC)) = (int) (*(int *)(int *)((char *)(D_007B205C) + 0x788));
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutUp__vfunc_03);

extern "C" void ClrOutUp__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E850);

extern "C" void ClrOutDeathUp__vfunc_02(int arg0)
{
    int temp_a0;

    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x40);
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x10000000);
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    temp_a0 = (*(int *)(int *)((char *)(arg0) + 0xC));
    if ((*(int *)(int *)((char *)(temp_a0) + 0x260)) == 5) {
        (*(int *)(int *)((char *)(temp_a0) + 0x260)) = 6;
    }
}


INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF7B8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF7C8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF7D8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF7E8);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutDeathUp__vfunc_03);

extern "C" void ClrOutDeathUp__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014ED10);

extern "C" void ClrOutMove__vfunc_02(int arg0)
{
    X_func_0016649C((*(int *)(int *)((char *)(arg0) + 0xC)), 1);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    X_func_00166DA4(arg0, 0x64);
    (*(int *)(int *)((char *)(arg0) + 0xB0)) = (int) (*(int *)(int *)((char *)(D_007B205C) + 0x788));
}


INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF828);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutMove__vfunc_03);

extern "C" void ClrOutMove__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F23C);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F360);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F72C);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutAtk__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF868);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF870);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF878);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF880);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF888);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF898);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8B0);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutAtk__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8D8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8E0);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8E8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8F0);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014FEBC);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_00150290);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_001506A0);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF950);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF960);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF970);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF978);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF980);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF988);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF990);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF998);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF9A0);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF9A8);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_00150804);

extern "C" int func_00150A1C()
{
    return 0;
}


extern "C" void ClrOutAtk__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutWin__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutWin__vfunc_03);

extern "C" void ClrOutWin__vfunc_04()
{
    X_func_00166AD0();
}

