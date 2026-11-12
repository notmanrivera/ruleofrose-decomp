#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_0017FB5C(int) asm("func_0017FB5C");
extern "C" int Xiii_func_0017FB00(int, int) asm("func_0017FB00");
extern "C" int Xiii_func_0017FBA4(int, int) asm("func_0017FBA4");
extern "C" int Xiii_func_00180A90(int, int) asm("func_00180A90");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0017F3B8(...) asm("func_0017F3B8");
extern "C" int X_func_0017F514(...) asm("func_0017F514");
extern "C" int X_func_0017F530(...) asm("func_0017F530");
extern "C" int X_func_0017F584(...) asm("func_0017F584");
extern "C" int X_func_0017F6B8(...) asm("func_0017F6B8");
extern "C" int X_func_0017FAC4(...) asm("func_0017FAC4");
extern "C" int X_func_0017FB00(...) asm("func_0017FB00");
extern "C" int X_func_0017FB5C(...) asm("func_0017FB5C");
extern "C" int X_func_0017FBA4(...) asm("func_0017FBA4");
extern "C" int X_func_0017FC74(...) asm("func_0017FC74");
extern "C" int X_func_0017FD58(...) asm("func_0017FD58");
extern "C" int X_func_00180230(...) asm("func_00180230");
extern "C" int X_func_00180A90(...) asm("func_00180A90");
extern "C" int X_func_00180F44(...) asm("func_00180F44");
extern "C" int X_func_0018120C(...) asm("func_0018120C");
extern "C" int X_func_00181494(...) asm("func_00181494");
extern "C" int X_func_00237D80(...) asm("func_00237D80");
extern "C" int X_func_00237DB0(...) asm("func_00237DB0");
extern "C" int X_func_00237EB0(...) asm("func_00237EB0");
extern "C" int X_func_0023C0F8(...) asm("func_0023C0F8");
extern "C" int X_func_00241AC8(...) asm("func_00241AC8");
extern "C" int X_memset(...) asm("memset");
extern int D_006689BF;
extern int D_006A8DBF;
extern int D_007B40C0;

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F0D0);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F13C);

extern "C" void func_0017F164(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 1;
    (*(int *)(int *)((char *)(arg0) + 0x1AF8)) = 0;
    X_func_00237D80();
}


INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F188);

extern "C" void func_0017F200(int arg0)
{
    if ((*(int *)(arg0)) == 1) {
        X_func_0017F6B8();
        X_func_0018120C((int)&D_007B40C0);
        X_func_00237EB0();
        X_func_00181494((int)&D_007B40C0);
        X_func_0017F3B8(arg0);
    }
}


INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F264);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F308);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F3B8);

extern "C" void func_0017F514(int arg0, int arg1)
{
    M2C_FIELD(arg1, int *, 0) = -1;
    M2C_FIELD(arg1, int *, 4) = -1;
    M2C_FIELD(arg1, int *, 8) = -1;
    M2C_FIELD(arg1, int *, 0xC) = -1;
    M2C_FIELD(arg1, int *, 0x10) = -1;
}

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F530);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F584);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F5E8);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F6B8);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F7AC);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F81C);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F878);

extern "C" int func_0017F8E4(int arg0)
{
    return Xiii_func_00180A90((int) arg0, M2C_FIELD(arg0, int *, 0x1AF4));
}

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F8FC);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F9AC);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FA5C);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FA90);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FAC4);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FB00);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FB5C);

extern "C" void func_0017FBA4(int arg0, int arg1)
{
    if (arg1 != 0) {
        X_func_0017F514();
    }
}


extern "C" int func_0017FBC4(int arg0, int arg1)
{
    int temp_v0;
    int temp_v0_2;

    temp_v0 = Xii_func_0017FB5C((int) arg0);
    if (temp_v0 != 0) {
        Xiii_func_0017FB00((int) arg0, temp_v0);
        if (arg1 == 0) {
            M2C_FIELD(temp_v0, int *, 0x40) = (int) ((int) (int)&D_006689BF & ~0x3F);
        } else {
            M2C_FIELD(temp_v0, int *, 0x40) = (int) ((int) (int)&D_006A8DBF & ~0x3F);
        }
        temp_v0_2 = M2C_FIELD(temp_v0, int *, 0x40);
        if (temp_v0_2 == 0) {
            Xiii_func_0017FBA4((int) arg0, temp_v0);
            return 0;
        }
        Xiiii_memset((int) temp_v0_2, 0, 0x40000);
        
        return temp_v0;
    }
    return temp_v0;
}

extern "C" void func_0017FC74()
{
    X_func_0017FBA4();
}


INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FC90);

extern "C" int func_0017FD1C(int arg0, int arg1)
{
    return X_func_0017FD58(arg0, arg1, 1, -1, 0);
}

extern "C" int func_0017FD3C(int arg0, int arg1, int arg2)
{
    return X_func_0017FD58(arg0, arg1, arg2, -1, 0);
}

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FD58);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FF58);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0018000C);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_00180078);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_001800D0);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_00180108);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_00180168);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_001801C8);

INCLUDE_RODATA("asm/nonmatchings/snd/sndman", D_002F3148);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_00180230);
