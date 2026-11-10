#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_LoadExecPS2(...) asm("LoadExecPS2");
extern "C" int X_func_0024B3F8(...) asm("func_0024B3F8");
extern "C" int X_func_00279C98(...) asm("func_00279C98");
extern "C" int X_sceClose(...) asm("sceClose");
extern "C" int X_sceOpen(...) asm("sceOpen");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00169A98(...) asm("func_00169A98");
extern "C" int X_func_0016A8A4(...) asm("func_0016A8A4");
extern "C" int X_func_00180CA8(...) asm("func_00180CA8");
extern "C" int X_func_001C0D44(...) asm("func_001C0D44");
extern "C" int X_func_001C0D70(...) asm("func_001C0D70");
extern "C" int X_func_00203DD0(...) asm("func_00203DD0");
extern "C" int X_func_00203F38(...) asm("func_00203F38");
extern "C" int X_func_002041F8(...) asm("func_002041F8");
extern "C" int X_func_0020E664(...) asm("func_0020E664");
extern "C" int X_func_0020E690(...) asm("func_0020E690");
extern int D_002FF6A8;
extern int D_002FF6E8;
extern int D_007812C0;
extern int D_007A4440;
extern int D_007B2580;

INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_002039A4);

extern "C" void func_00203A00(int arg0)
{
    int temp_v0;

    M2C_FIELD(arg0, int *, 0x48) = 0;
    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x10);
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, float *, 0x1E8) = (float) M2C_FIELD(arg0, float *, 0x1C);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_00203A28);

INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_00203B44);

extern "C" int func_00203D94()
{
    return X_func_00203DD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_00203DA8);

INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_00203DD0);

extern "C" void func_00203EA8(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x0)) == 0) {
        X_func_00203F38();
        (*(int *)(int *)((char *)(arg0) + 0x28)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x28)) + ((*(int *)(int *)((char *)(arg0) + 0xC)) - (*(int *)(int *)((char *)(arg0) + 0x14))));
    }
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 1;
}


extern "C" void func_00203EFC(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x0)) != 0) {
        X_func_00203F38();
        (*(int *)(int *)((char *)(arg0) + 0x14)) = (int) (*(int *)(int *)((char *)(arg0) + 0xC));
    }
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_00203F38);

INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_00204014);

extern "C" void func_0020406C(int arg0, int arg1)
{
    if (((*(int *)(int *)((char *)(arg0) + 0x0)) != 0) && (arg1 >= (unsigned int) (*(int *)(unsigned int *)((char *)(arg0) + 0x24)))) {
        (*(int *)(int *)((char *)(arg0) + 0x24)) = arg1;
    }
}


extern "C" void func_00204090(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x0)) != 0) {
        (*(int *)(int *)((char *)(arg0) + 0x24)) = (int) (*(int *)(int *)((char *)(arg0) + 0x20));
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_002040AC);

extern "C" void func_00204148()
{
    X_func_0020E690((int)&D_007A4440);
    X_func_001C0D70((int)&D_007812C0);
}


extern "C" void func_00204174()
{
    X_func_0020E664((int)&D_007A4440);
    X_func_001C0D44((int)&D_007812C0);
}


INCLUDE_RODATA("asm/nonmatchings/unk/002039A4", D_002FF698);

INCLUDE_RODATA("asm/nonmatchings/unk/002039A4", D_002FF6A8);

INCLUDE_RODATA("asm/nonmatchings/unk/002039A4", D_002FF6E8);

extern "C" void func_002041A0()
{
    struct { char pad0[256]; } stack;
    int temp_v0;

    X_func_00279C98((int)&stack, (int) "host0:main.ee.elf");
    do {
        temp_v0 = X_sceOpen((int)&stack, 1);
    } while (temp_v0 < 0);
    X_sceClose(temp_v0);
    X_func_0024B3F8(0);
    X_LoadExecPS2((int)&stack, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_002041F8);

extern "C" void func_0020439C()
{
    X_func_002041F8(1, 0xFFFF);
}


extern "C" void func_002043BC()
{
    X_func_002041F8(0, 0xFFFF);
}

