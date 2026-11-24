#include "include_asm.h"

#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))

extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xii_heapFree__FPv(int) asm("heapFree__FPv");
extern "C" int Xii_func_001FCBF8(int) asm("func_001FCBF8");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiiii_strncpy(int, int, int) asm("strncpy");
extern "C" int Xiiiii_func_001FC4F0(int, int, int, int) asm("func_001FC4F0");
extern "C" int Xiiiii_func_001FC600(int, int, int, int) asm("func_001FC600");
extern "C" int X_func_001FC4F0(...) asm("func_001FC4F0");
extern "C" int X_func_001FC5E4(...) asm("func_001FC5E4");
extern "C" int X_func_001FC600(...) asm("func_001FC600");
extern "C" int X_strlen(...) asm("strlen");

extern "C" void func_001FC47C(int arg0)
{
    M2C_FIELD(arg0, int *, 0x400) = 0;
    M2C_FIELD(arg0, int *, 0x50C) = 0;
    M2C_FIELD(arg0, int *, 0x504) = 0;
    M2C_FIELD(arg0, int *, 0x508) = 0;
}

extern "C" void func_001FC490(int arg0, int arg1)
{
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x504);
    if (temp_v0 != 0) {
        Xii_heapFree__FPv(temp_v0);
    }
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/task/naga_chunk", func_001FC4F0);

extern "C" void func_001FC5E4()
{
    X_func_001FC4F0();
}

extern "C" void func_001FC600(int arg0, int arg1, int arg2, int arg3)
{
    struct { char pad0[16]; } stack;
    Xiiii_memset((int)&stack, 0, 8);
    Xiiii_strncpy((int)&stack, (int) arg1, 8);
    Xiiiii_func_001FC4F0(arg0, (int)&stack, arg2, arg3);
}

extern "C" void func_001FC678(int arg0, int arg1, int arg2)
{
    int buf[4];
    int v;

    v = M2C_FIELD(arg0, int *, 0x50C);
    buf[0] = arg2;
    v = (v + 3) & ~3;
    M2C_FIELD(arg0, int *, 0x50C) = v;
    X_func_001FC600(arg0, arg1, (int)buf, 4);
}

extern "C" void func_001FC6B4(int arg0, int arg1, float f0)
{
    int buf[4];
    int v;

    v = M2C_FIELD(arg0, int *, 0x50C);
    M2C_FIELD(buf, float *, 0) = f0;
    v = (v + 3) & ~3;
    M2C_FIELD(arg0, int *, 0x50C) = v;
    X_func_001FC600(arg0, arg1, (int)buf, 4);
}

extern "C" void func_001FC6F0(int arg0, int arg1, int arg2)
{
    X_func_001FC600(arg0, arg1, arg2, X_strlen(arg2) + 1);
}

extern "C" void func_001FC744(int arg0, int arg1, int arg2)
{
    M2C_FIELD(arg0, int *, 0x50C) = (int) ((M2C_FIELD(arg0, int *, 0x50C) + 3) & ~3);
    Xiiiii_func_001FC600(arg0, arg1, M2C_FIELD(arg2, int *, 0x504), M2C_FIELD(arg2, int *, 0x508));
}

extern "C" void func_001FC77C(int arg0, int arg1, int arg2)
{
    int buf[4];
    int v;

    v = M2C_FIELD(arg0, int *, 0x50C);
    buf[0] = arg2;
    v = (v + 3) & ~3;
    M2C_FIELD(arg0, int *, 0x50C) = v;
    X_func_001FC5E4(arg0, arg1, (int)buf, 4);
}

extern "C" void func_001FC7B8(int arg0, int arg1, float f0)
{
    int buf[4];
    int v;

    v = M2C_FIELD(arg0, int *, 0x50C);
    M2C_FIELD(buf, float *, 0) = f0;
    v = (v + 3) & ~3;
    M2C_FIELD(arg0, int *, 0x50C) = v;
    X_func_001FC5E4(arg0, arg1, (int)buf, 4);
}

extern "C" void func_001FC7F4(int arg0, int arg1, int arg2)
{
    X_func_001FC5E4(arg0, arg1, arg2, X_strlen(arg2) + 1);
}

extern "C" void func_001FC848(int arg0, int arg1, int arg2)
{
    M2C_FIELD(arg0, int *, 0x50C) = (int) ((M2C_FIELD(arg0, int *, 0x50C) + 3) & ~3);
    X_func_001FC5E4(arg0, arg1, M2C_FIELD(arg2, int *, 0x504), M2C_FIELD(arg2, int *, 0x508));
}

extern "C" void func_001FC880(int arg0, int arg1)
{
    int temp_a1;

    temp_a1 = arg1 - 1;
    (*(int *)(int *)((char *)(arg0) + 0x50C)) = (int) (((*(int *)(int *)((char *)(arg0) + 0x50C)) + temp_a1) & ~temp_a1);
}

INCLUDE_ASM("asm/nonmatchings/task/naga_chunk", func_001FC89C);

// NON_MATCHING: 29/36 differ, 5 relocs differ (size 0x90, game 0x88), 15 edits
#ifdef NON_MATCHING
extern "C" int X_func_00279C98(...) asm("func_00279C98");
extern "C" int X_sceClose(...) asm("sceClose");
extern "C" int X_sceOpen(...) asm("sceOpen");
extern "C" int X_sceWrite(...) asm("sceWrite");
extern const char D_002FF008[];
extern "C" int func_001FC9E8(int arg0, int arg1)
{
    struct { char pad0[64]; } stack;
    int temp_v0;
    int var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, int *, 0x504) != 0) {
        X_func_00279C98((int)&stack, (int) D_002FF008, arg1);
        temp_v0 = X_sceOpen((int)&stack, 0x602);
        var_v0 = 0;
        if (temp_v0 >= 0) {
            X_sceWrite(temp_v0, M2C_FIELD(arg0, int *, 0x504), (M2C_FIELD(arg0, int *, 0x508) + 0xF) & ~0xF);
            X_sceClose(temp_v0);
            var_v0 = 1;
        }
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/nonmatchings/task/naga_chunk", func_001FC9E8);
#endif

extern "C" void func_001FCA70(int arg0)
{
    M2C_FIELD(arg0, int *, 0) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 4) = 0;
}

extern "C" int func_001FCA84(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = arg1;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 4) = 0;
    return Xii_func_001FCBF8(arg0);
}

extern "C" void func_001FCAAC(int arg0, int arg1)
{
    int temp_a0;

    temp_a0 = M2C_FIELD(arg0, int *, 0);
    if ((temp_a0 != 0) && (M2C_FIELD(arg0, int *, 4) != 0)) {
        Xii_heapFree__FPv(temp_a0);
    }
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/task/naga_chunk", func_001FCB14);

extern "C" void func_001FCBF8(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x8)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0xC)) = -1;
    if (*(int *)(*(int *)(int *)((char *)(arg0) + 0x0)) == 0) {
        (*(int *)(int *)((char *)(arg0) + 0x8)) = 1;
    }
}

INCLUDE_RODATA("asm/nonmatchings/task/naga_chunk", D_002FEFF0);

INCLUDE_RODATA("asm/nonmatchings/task/naga_chunk", D_002FF008);
