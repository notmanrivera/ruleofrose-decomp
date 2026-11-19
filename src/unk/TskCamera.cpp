#include "include_asm.h"

extern "C" int Xiii_func_00218470(int, int, int) asm("func_00218470");
extern "C" int Xiii_getInfo__9BedMemoryP13BedMemoryInfoi(int, int, int) asm("getInfo__9BedMemoryP13BedMemoryInfoi");
extern int D_006E9800;

extern "C" int func_001FBBA4()
{
    int info[4];

    Xiii_getInfo__9BedMemoryP13BedMemoryInfoi((int)&D_006E9800, (int)info, 0);
    return info[0];
}

extern "C" void func_001FBBD0()
{
    static const char msg[0x30] = "free mem   max/total/size   = %d/%d \n";
    int info[4];

    Xiii_getInfo__9BedMemoryP13BedMemoryInfoi((int)&D_006E9800, (int)info, 0);
    Xiii_func_00218470((int)msg, info[0], info[1]);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FBC0C);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FBC6C);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FBD2C);

extern "C" void TskCamera__vfunc_03(void) {
}

extern "C" void TskCamera__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", TskCamera__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FC210);

extern "C" int func_001FC46C()
{
    return 0;
}

extern "C" int func_001FC474()
{
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFD0);
