#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001D3A38(int, int) asm("func_001D3A38");
extern "C" int Xiiiii_attachActor__9MagSystemiii(int, int, int, int) asm("attachActor__9MagSystemiii");
extern "C" int Xiiu_func_001CBE38(int, unsigned int) asm("func_001CBE38");
extern "C" int Xiiu_func_001D046C(int, unsigned int) asm("func_001D046C");
extern "C" int Xiiu_func_001D2B8C(int, unsigned int) asm("func_001D2B8C");
extern "C" int Xiiu_func_001D2D00(int, unsigned int) asm("func_001D2D00");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_attachActor__9MagSystemiii(...) asm("attachActor__9MagSystemiii");
extern "C" int X_func_00130DE0(...) asm("func_00130DE0");
extern "C" int X_func_0013FB3C(...) asm("func_0013FB3C");
extern "C" int X_func_001CBE38(...) asm("func_001CBE38");
extern "C" int X_func_001D046C(...) asm("func_001D046C");
extern "C" int X_func_001D0EFC(...) asm("func_001D0EFC");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D2B8C(...) asm("func_001D2B8C");
extern "C" int X_func_001D2BA8(...) asm("func_001D2BA8");
extern "C" int X_func_001D2D00(...) asm("func_001D2D00");
extern "C" int X_func_001D3A38(...) asm("func_001D3A38");
extern "C" int X_func_001D4A3C(...) asm("func_001D4A3C");
extern "C" int X_func_001D9F08(...) asm("func_001D9F08");
extern "C" int X_func_001DA228(...) asm("func_001DA228");
extern "C" int X_func_001DA740(...) asm("func_001DA740");
extern "C" int X_func_001DAC8C(...) asm("func_001DAC8C");
extern "C" int X_func_001DB17C(...) asm("func_001DB17C");
extern "C" int X_func_001DB18C(...) asm("func_001DB18C");
extern "C" int X_func_001DB19C(...) asm("func_001DB19C");
extern "C" int X_func_001DB31C(...) asm("func_001DB31C");
extern "C" int X_func_001DB520(...) asm("func_001DB520");
extern int D_006E9840;
extern int D_006FBD80;
extern int D_006FE6A0;
extern int D_00724EA0;
extern int D_007812C0;
extern int D_007B205C;

extern "C" void func_001D1BEC(int arg0, unsigned int arg1, unsigned int arg2)
{
    if (Xiiu_func_001D046C((int) arg0, arg1) != 0) {
        Xiiiii_attachActor__9MagSystemiii((int) (int)&D_006E9840, Xiiu_func_001CBE38((int)&D_007812C0, arg1), -1, 0);
        if (((arg2 >> 0x1C) & 3) == 1) {
            M2C_FIELD(Xiiu_func_001D2B8C(arg0, arg2), int *, 0x254) = -1;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D1C80);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D1D5C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D1E88);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D1F14);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D1F74);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D1FD8);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D217C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2270);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2334);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D23F8);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2428);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2494);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D25E4);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2724);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D27DC);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2A14);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2AAC);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2ADC);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2B10);

extern "C" int func_001D2B8C(int arg0, int arg1)
{
    return (*(int *)(int *)((char *)((((arg1 & 0x1FF) * 4) + arg0)) + 0x21340));
}


extern "C" int func_001D2BA8(int arg0, unsigned int arg1)
{
    int var_v0;

    if ((((arg1 >> 0x17) & 0x1F) != 5) || (var_v0 = Xiiu_func_001D2D00((int) arg0, arg1), (var_v0 == 0))) {
        var_v0 = M2C_FIELD((((arg1 & 0x1FF) * 4) + arg0), int *, 0x21540);
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2C0C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2D00);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2D7C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2E2C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2FF0);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D327C);

extern "C" void func_001D3588(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x21F48)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x21F48)) | 0x40000);
}


INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D35AC);

extern "C" void func_001D3A14()
{
    X_func_001D9F08(X_func_001D2B8C());
}


INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D3A38);

extern "C" void func_001D3AC8(int arg0, int arg1)
{
    int temp_v0;

    if (arg1 != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x22214);
        if (temp_v0 != -1) {
            Xiii_func_001D3A38(arg0, temp_v0);
            M2C_FIELD(arg0, int *, 0x22214) = -1;
        }
    } else {
        M2C_FIELD(arg0, int *, 0x22214) = (int) M2C_FIELD(arg0, int *, 0x22218);
        Xiii_func_001D3A38(arg0, arg1);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0C0);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0E0);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0F0);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D3B44);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D4370);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D44E4);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D4540);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D4730);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D480C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D49D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC130);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D4A3C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D4AEC);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC178);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D4B9C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D50A8);

extern "C" void func_001D5444(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D544C);
