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

extern "C" void X___builtin_delete(void *) asm("__builtin_delete");

extern "C" void func_0017F13C(void *arg0, int arg1)
{
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

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

extern "C" void func_0017F530(int arg0)
{
    int *p = (int *)(arg0 + 0x234);
    int i;
    for (i = 0x2F; i >= 0; i--) {
        X_func_0017F514(arg0, (int)p);
        p = (int *)((char *)p + 0x84);
    }
}

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F584);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F5E8);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F6B8);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F7AC);

extern "C" int X4_func_001E4908(int, int, int, int) asm("func_001E4908");
extern int D_007812C0;

extern "C" int func_0017F81C(int arg0, int arg1)
{
    int v;
    int base = (int)&D_007812C0;
    if (X4_func_001E4908(base + 0x18E00, arg1, (int)&v, 1) == 0) {
        return -1;
    }
    return Xiii_func_00180A90(arg0, *(unsigned short *)(v + 0x20));
}

extern "C" int X4_func_001809D8(int, int, int, int) asm("func_001809D8");
extern "C" int atoi(const char *);

extern "C" void func_0017F878(int arg0, unsigned char *arg1, int arg2)
{
    char buf[3];

    buf[0] = arg1[3];
    buf[1] = arg1[4];
    buf[2] = 0;
    int n = atoi(buf);
    *(int *)(arg0 + 0x1AF4) = n;
    X4_func_001809D8(arg0, n, (int)arg1, arg2);
}

extern "C" int func_0017F8E4(int arg0)
{
    return Xiii_func_00180A90((int) arg0, M2C_FIELD(arg0, int *, 0x1AF4));
}

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F8FC);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017F9AC);

extern "C" int func_0017FA5C(int arg0, int arg1, int arg2)
{
    switch (arg1) {
    case 0:
        return ((((*(unsigned int *)(arg0 + 0x24) >> arg2) & 1) == 0) ? arg2 : -1);
    case 1:
        return -1;
    default:
        return -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FA90);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_0017FAC4);

extern "C" void func_0017FB00(int arg0, int arg1)
{
    *(int *)(arg1 + 0x00) = 1;
    *(int *)(arg1 + 0x0C) = 0;
    *(int *)(arg1 + 0x10) = 5;
    *(int *)(arg1 + 0x14) = -1;
    *(int *)(arg1 + 0x18) = -1;
    *(int *)(arg1 + 0x1C) = -1;
    *(int *)(arg1 + 0x20) = 0;
    *(int *)(arg1 + 0x24) = -1;
    *(int *)(arg1 + 0x28) = 1;
    *(int *)(arg1 + 0x2C) = 0x80;
    *(int *)(arg1 + 0x30) = 0x80;
    *(int *)(arg1 + 0x34) = 0;
    *(int *)(arg1 + 0x38) = 0;
    *(float *)(arg1 + 0x3C) = 1.0f;
    *(int *)(arg1 + 0x40) = 0;
    *(char *)(arg1 + 0x44) = 0;
}

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

extern "C" int func_0018000C(int arg0, int arg1, int arg2)
{
    int *p = (int *)X_func_0017F584(arg0, arg1);
    if (p == 0) {
        return -1;
    }
    if (p[0] != 1) {
        return -1;
    }
    if (arg2 != -0x400) {
        p[13] = arg2;
    }
    int state = p[4];
    if (state != 0) {
        if (state == 2) {
            p[4] = 3;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_00180078);

extern "C" int func_001800D0(int arg0, int arg1)
{
    int *p = (int *)X_func_0017F584(arg0, arg1);
    if (p == 0) {
        return -1;
    }
    if (p[0] == 1) {
        return p[4];
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_00180108);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_00180168);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_001801C8);

INCLUDE_RODATA("asm/nonmatchings/snd/sndman", D_002F3148);

INCLUDE_ASM("asm/nonmatchings/snd/sndman", func_00180230);
