#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00154474(...) asm("func_00154474");
extern "C" int X_func_001544C8(...) asm("func_001544C8");
extern "C" int X_func_001544D0(...) asm("func_001544D0");
extern "C" int X_func_00154584(...) asm("func_00154584");
extern "C" int X_func_00154668(...) asm("func_00154668");
extern "C" int X_func_00154E20(...) asm("func_00154E20");
extern "C" int X_func_0015558C(...) asm("func_0015558C");
extern "C" int X_func_00155648(...) asm("func_00155648");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(...) asm("func_00166DA4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_001C6CCC(...) asm("func_001C6CCC");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001D23F8(...) asm("func_001D23F8");
extern int D_007812C0;
extern int D_007B205C;

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00153E40);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgMain__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgMain__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgMain__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00154408);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00154474);

extern "C" int func_001544C8()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_001544D0);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00154584);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00154668);

extern "C" int func_00154734()
{
    return X_func_00154668();
}


extern "C" void func_00154748(int arg0)
{
    int temp_a1;
    int temp_v1;

    temp_a1 = (*(int *)(int *)((char *)(arg0) + 0x20));
    (*(int *)(int *)((char *)(temp_a1) + 0x120)) = (int) ((*(int *)(int *)((char *)(temp_a1) + 0x120)) & 0xEFFFFFFF);
    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x20));
    (*(int *)(int *)((char *)(temp_v1) + 0x120)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x120)) & ~0x80);
    (*(int *)(int *)((char *)(arg0) + 0x240)) = 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutCatch__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutCatch__vfunc_03);

extern "C" void GrgOutCatch__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutBitten__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutBitten__vfunc_03);

extern "C" void GrgOutBitten__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void GrgOutDisappear__vfunc_02(int arg0)
{
    int temp_v0;

    (*(int *)(int *)((char *)(D_007B205C) + 0x14C)) = 1;
    X_func_001D23F8((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 1);
    (*(int *)(int *)((char *)(arg0) + 0x3C)) = 0;
    X_func_001C6CCC((int)&D_007812C0, 5, arg0 + 0x44);
    (*(int *)(int *)((char *)(arg0) + 0x48)) = 0;
    temp_v0 = X_func_00154E20(arg0);
    (*(int *)(int *)((char *)(arg0) + 0x4)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x40)) = temp_v0;
}


INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutDisappear__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFBC8);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFBD8);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFBE8);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFBF8);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC08);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC18);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC28);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC38);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC48);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00154D78);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00154E20);

extern "C" void GrgOutDisappear__vfunc_04(int arg0)
{
    X_func_00166AD0();
    X_func_001D23F8((int)&D_007812C0, (*(int *)(arg0)), 0);
}


extern "C" void GrgOutEvent__vfunc_02(int arg0)
{
    (*(int *)(int *)((char *)(D_007B205C) + 0x14C)) = 0;
    X_func_001D23F8((int)&D_007812C0, (*(int *)(arg0)), 1);
}


extern "C" int GrgOutEvent__vfunc_03()
{
    return -1;
}


INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutWalk__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC80);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC98);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0118);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutWalk__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00155498);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0150);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0158);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0160);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0168);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0170);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0178);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0180);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0188);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0190);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0198);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_0015558C);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00155648);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_0015582C);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00155BB4);

extern "C" void GrgOutWalk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void GrgOutTest__vfunc_02(int arg0)
{
    (*(int *)(int *)((char *)(D_007B205C) + 0x14C)) = 1;
    (*(int *)(int *)((char *)(arg0) + 0x4)) = 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutTest__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F01C0);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F01D0);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0410);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0430);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F08B0);
