#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xff_cosf(float) asm("cosf");
extern "C" float Xff_sinf(float) asm("sinf");
extern "C" int Xiii_func_0010AA5C__8DogActorPCc(int, int) asm("func_0010AA5C__8DogActorPCc");
extern "C" int Xiiiiiff_func_001F5E48(int, int, int, int, float, float) asm("func_001F5E48");
extern "C" int Xiiu_func_001CBE38(int, unsigned int) asm("func_001CBE38");
extern int D_006FE6A0;
extern int D_007812C0;
extern "C" int X_memset(...) asm("memset");
extern int D_002D8F68;
extern int D_002D8F70;
// Translated mechanically from m2c drafts: only what matches byte for byte.

extern "C" void func_001F59AC(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F59B4);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F5BDC);

extern "C" int func_001F5D90(int arg0, int arg1, int arg2, int arg3, float fparg0, float fparg1)
{
    int temp_v0;
    int temp_v0_2;

    temp_v0 = Xiiu_func_001CBE38((int)&D_007812C0, (unsigned int) arg0);
    if (temp_v0 != -1) {
        temp_v0_2 = Xiii_func_0010AA5C__8DogActorPCc((int) ((int)&D_006FE6A0 + (temp_v0 * 0x4D0)), arg1);
        Xiiiiiff_func_001F5E48(arg0, (temp_v0_2 >= 0) ? temp_v0_2 : 0, arg2, arg3, fparg0, fparg1);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F5E48);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F603C);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F616C);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F61EC);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F627C);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6308);

extern "C" void func_001F6570(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6578);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6694);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F67A0);

extern "C" int func_001F6878(unsigned int arg0)
{
    return ((arg0 >> 0x17) & 0x1F) == 2;
}

extern "C" void func_001F688C()
{
    X_memset((int)&D_002D8F70, 0, 0x20);
    D_002D8F68 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F68BC);

extern "C" void func_001F6B28(int arg0, float fparg0, float fparg1)
{
    M2C_FIELD(arg0, float *, 0) = (float) (M2C_FIELD(arg0, float *, 0) + (Xff_sinf(fparg0) * fparg1));
    M2C_FIELD(arg0, float *, 8) = (float) (M2C_FIELD(arg0, float *, 8) + (Xff_cosf(fparg0) * fparg1));
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6B8C);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6BD0);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6C14);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6C54);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6C64);

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", DisplayMessage__vfunc_01);
