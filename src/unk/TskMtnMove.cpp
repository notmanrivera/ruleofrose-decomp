#include "include_asm.h"
extern "C" int Xii_func_001E4D04(int) asm("func_001E4D04");
extern "C" int Xiiiiii_func_001E4EBC(int, int, int, int, int) asm("func_001E4EBC");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001E7DE8(int, int) asm("func_001E7DE8");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010A834__8DogActor(...) asm("func_0010A834__8DogActor");
extern "C" int X_func_0017F5E8(...) asm("func_0017F5E8");
extern "C" int X_func_001800D0(...) asm("func_001800D0");
extern "C" int X_func_001801C8(...) asm("func_001801C8");
extern "C" int X_func_00180B30(...) asm("func_00180B30");
extern "C" int X_func_00180CA8(...) asm("func_00180CA8");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" int X_func_001E46B8(...) asm("func_001E46B8");
extern "C" int X_func_001E4A0C(...) asm("func_001E4A0C");
extern "C" int X_func_001E4D04(...) asm("func_001E4D04");
extern "C" int X_func_001E4EBC(...) asm("func_001E4EBC");
extern "C" int X_func_001E649C(...) asm("func_001E649C");
extern "C" int X_func_001E7340(...) asm("func_001E7340");
extern "C" int X_func_001E7698(...) asm("func_001E7698");
extern "C" int X_func_001E76B8(...) asm("func_001E76B8");
extern "C" int X_func_001E7D08(...) asm("func_001E7D08");
extern "C" int X_func_001E7DE8(...) asm("func_001E7DE8");
extern "C" int X_func_00203D94(...) asm("func_00203D94");
extern "C" int X_func_0023A080(...) asm("func_0023A080");
extern "C" int X_func_0023A0B8(...) asm("func_0023A0B8");
extern "C" int X_strcmp(...) asm("strcmp");
extern int D_006FE6A0;
extern int D_007B2580;

extern "C" void func_001E46B8(int arg0, int arg1)
{
    X_func_00180B30((int)&D_007B2580);
    (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x1728)) = -1;
}


extern "C" void func_001E4700(int arg0)
{
    X_func_0017F5E8((int)&D_007B2580, 8);
    X_func_001E46B8(arg0, 0);
    X_func_001E46B8(arg0, 0xA);
    X_func_001E46B8(arg0, 0xB);
    X_func_001E46B8(arg0, 0xC);
    X_func_001E46B8(arg0, 0x1F);
    X_func_001E46B8(arg0, 0x20);
    X_func_001E46B8(arg0, 0x21);
    X_func_001E46B8(arg0, 0x40);
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4790);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E484C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4908);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4970);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4A0C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4AB8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4B48);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4C1C);

extern "C" int func_001E4CBC()
{
    return 0;
}


extern "C" void func_001E4CC4(int arg0, int arg1, int arg2, int arg3)
{
    (*(int *)(int *)((char *)(arg0) + 0x1720)) = arg2;
    (*(int *)(int *)((char *)(arg0) + 0x1724)) = arg3;
    (*(int *)(int *)((char *)(arg0) + 0x171C)) = arg1;
    X_func_0023A080(arg1);
    X_func_0023A0B8((*(int *)(int *)((char *)(arg0) + 0x1720)), (*(int *)(int *)((char *)(arg0) + 0x1724)));
}


extern "C" int func_001E4D04()
{
    return X_func_001E4A0C();
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4D18);

extern "C" int func_001E4DB0(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    temp_v0 = Xii_func_001E4D04((int) arg0);
    if (temp_v0 != 0) {
        return Xiiiiii_func_001E4EBC(arg0, temp_v0, arg2, arg3, 0);
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4E20);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4EBC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E50C8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5250);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5428);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5540);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5660);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5B60);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5BE0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5C40);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5D1C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5DE4);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5E58);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6368);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E63C0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E649C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6570);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6734);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6CAC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6D54);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6E00);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7094);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E70DC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7184);

extern "C" void func_001E71F4(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E71FC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7340);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7414);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E747C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7544);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7618);

extern "C" void func_001E7698(int arg0, int arg1)
{
    if (arg1 != 0) {
        Xiii_func_001E7DE8((int) arg0, M2C_FIELD(arg1, int *, 0xC));
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E76B8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7724);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E77B4);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E785C);

extern "C" void func_001E7908(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7910);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E79C0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7A20);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7C7C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7D08);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7D7C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7DE8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7E50);

extern "C" int TskTest__vfunc_04()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7ED8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskLogger__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7F28);

extern "C" void TskMtnMove__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskMtnMove__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskMtnMove__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E85D0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E89C0);

extern "C" int func_001E8F88(int arg0)
{
    return X_func_0010A834__8DogActor((int)&D_006FE6A0 + ((*(int *)(int *)((char *)(arg0) + 0xC)) * 0x4D0)) == 0;
}


extern "C" int func_001E8FBC()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E8FC4);

extern "C" void TskMtnMove2__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskMtnMove2__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskMtnMove2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E93EC);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD900);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD910);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD920);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD940);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD948);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD950);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD958);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD960);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD968);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD970);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD978);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD980);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD988);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD990);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD998);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA48);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA50);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA58);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA70);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E9614);
