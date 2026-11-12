#include "include_asm.h"
struct D007812C0Type {
    char pad[0x22214];
    int m_22214;
};
extern D007812C0Type D_007812C0;
extern "C" int Xiii_func_001D3AC8(int, int) asm("func_001D3AC8");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiiiiii_func_0018D7EC(int, int, int, int, int, int) asm("func_0018D7EC");
extern int D_00299990;
extern int D_002999B0;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_clear__6BedPfh(...) asm("clear__6BedPfh");
extern "C" int X_func_0018BEF8(...) asm("func_0018BEF8");
extern "C" int X_func_0018C448(...) asm("func_0018C448");
extern "C" int X_func_0018C4D8(...) asm("func_0018C4D8");
extern "C" int X_func_0018C54C(...) asm("func_0018C54C");
extern "C" int X_func_0018C910(...) asm("func_0018C910");
extern "C" int X_func_0018C990(...) asm("func_0018C990");
extern "C" int X_func_0018C9D8(...) asm("func_0018C9D8");
extern "C" int X_func_0018CA58(...) asm("func_0018CA58");
extern "C" int X_func_0018D08C(...) asm("func_0018D08C");
extern "C" int X_func_0018D1E8(...) asm("func_0018D1E8");
extern "C" int X_func_0018D640(...) asm("func_0018D640");
extern "C" int X_func_0018D7EC(...) asm("func_0018D7EC");
extern "C" int X_func_0018DAFC(...) asm("func_0018DAFC");
extern "C" int X_func_0018DF20(...) asm("func_0018DF20");
extern "C" int X_func_0018E05C(...) asm("func_0018E05C");
extern "C" int X_func_0018EF40(...) asm("func_0018EF40");
extern "C" int X_func_0018EFF0(...) asm("func_0018EFF0");
extern "C" int X_func_0018F024(...) asm("func_0018F024");
extern "C" int X_func_0018F060(...) asm("func_0018F060");
extern "C" int X_func_0018F60C(...) asm("func_0018F60C");
extern "C" int X_func_0018F734(...) asm("func_0018F734");
extern "C" int X_func_0018F824(...) asm("func_0018F824");
extern "C" int X_func_001905A0(...) asm("func_001905A0");
extern "C" int X_func_001905A8(...) asm("func_001905A8");
extern "C" int X_func_001BFFCC(...) asm("func_001BFFCC");
extern "C" int X_func_001C0254(...) asm("func_001C0254");
extern "C" int X_func_002232F0(...) asm("func_002232F0");
extern "C" int X_heapFree__FPv(...) asm("heapFree__FPv");
extern int D_007A34D4;

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018BD94);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018BEF8);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C068);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C130);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C190);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C2E4);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C448);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C4D8);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C54C);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C5A8);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C630);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C6C4);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C738);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C794);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C814);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C910);

extern "C" int func_0018C990(int arg0, char *arg1)
{
    int n = 0;

    if (arg1 == 0) {
        return 0;
    }
    if ((M2C_FIELD(arg1, int *, 0) & 0xFF000000) == 0) {
        do {
            arg1 += 0x1C;
            n += 1;
        } while ((M2C_FIELD(arg1, int *, 0) & 0xFF000000) == 0);
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018C9D8);

extern "C" int func_0018CA58(int arg0, char *arg1)
{
    int n = 0;

    if (arg1 == 0) {
        return 0;
    }
    if (M2C_FIELD(arg1, int *, 0) >= 0) {
        do {
            arg1 += 0x20;
            n += 1;
        } while (M2C_FIELD(arg1, int *, 0) >= 0);
    }
    return n;
}

extern "C" float func_0018CA98(int arg0, int arg1, float fparg0)
{
    float t = (float) arg1;

    t = (t * t + t) * 0.5f;
    return fparg0 / t;
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CAC8);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CC54);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CD88);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CEEC);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018CFF0);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018D08C);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018D1E8);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018D640);

extern "C" int func_0018D7C8(int arg0, int arg1)
{
    char *p = (char *)M2C_FIELD(arg0, int *, 0x4AC);

    p += arg1 * 0x154;
    return M2C_FIELD(p, int *, 0x14);
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018D7EC);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018DAFC);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018DF20);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018DFDC);

extern "C" int func_0018E028(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int var_v0;

    var_v0 = 1;
    if ((arg3 < 0) || (arg4 < 0)) {
        var_v0 = 0;
    }
    if ((arg1 >= 0x2801) || (arg2 >= 0x1E01)) {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018E05C);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018EA9C);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018EB30);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018EBA4);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018EC58);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018ED44);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018EF40);

extern "C" void func_0018EFF0(int arg0, int arg1)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x4D0));
    if (temp_v0 != 0) {
        X_func_002232F0(temp_v0, (*(int *)(int *)((char *)(arg0) + 0x4D8)));
    }
}


extern "C" void func_0018F024()
{
    if (~D_007812C0.m_22214 != 0) {
        Xiii_func_001D3AC8((int)&D_007812C0, 1);
    }
}

extern "C" void func_0018F060()
{
    if (~D_007812C0.m_22214 == 0) {
        Xiii_func_001D3AC8((int)&D_007812C0, 0);
    }
}

extern "C" void func_0018F09C(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x4C8)) = (int) (~D_007A34D4 == 0);
}


extern "C" int func_0018F0B4(int arg0)
{
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x4C8));
    switch (temp_v1) {                              
    case 0:
        return X_func_0018F060();
    case 1:
        return X_func_0018F024();
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018F0EC);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018F1F4);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018F2E8);

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018F338);

extern "C" void func_0018F3E0(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = arg1 * 0x154;
    (*(int *)(int *)((char *)((temp_v1 + (*(int *)(int *)((char *)(arg0) + 0x4AC)))) + 0xC)) = 0;
    (*(int *)(int *)((char *)((temp_v1 + (*(int *)(int *)((char *)(arg0) + 0x4AC)))) + 0x8)) = 0;
    (*(int *)(int *)((char *)((temp_v1 + (*(int *)(int *)((char *)(arg0) + 0x4AC)))) + 0x10)) = 0;
}


extern "C" void func_0018F41C(int arg0, int arg1, int arg2)
{
    int temp_v0;

    Xiiiiiii_func_0018D7EC(arg0, arg1, 3, arg2, (int)&D_002999B0, (int)&D_00299990);
    temp_v0 = arg1 * 0x154;
    M2C_FIELD((temp_v0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) = 4;
    M2C_FIELD((temp_v0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x100) = arg2;
}

extern "C" void func_0018F4A0(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int temp_v0;

    Xiiiiiii_func_0018D7EC(arg0, arg1, 3, arg2, (int) arg3, (int) arg4);
    temp_v0 = arg1 * 0x154;
    M2C_FIELD((temp_v0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) = 4;
    M2C_FIELD((temp_v0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x100) = arg2;
}

extern "C" void func_0018F520(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    int temp_s0;

    temp_s0 = arg1 * 0x154;
    if (M2C_FIELD((temp_s0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) != 0) {
        Xiiiiiii_func_0018D7EC(arg0, arg1, 3, arg2, (int) arg3, (int) arg4);
        M2C_FIELD((temp_s0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x10) = 4;
        M2C_FIELD((temp_s0 + M2C_FIELD(arg0, int *, 0x4AC)), int *, 0x100) = arg2;
    }
}

extern "C" void func_0018F5B0(int arg0)
{
    X_clear__6BedPfh(arg0 + 0x41C);
    X_func_0018F60C(arg0);
    (*(int *)(int *)((char *)(arg0) + 0x418)) = 0;
}


extern "C" void func_0018F5E4(void *self, int theFlags)
{
    if (theFlags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/0018BD94", func_0018F60C);
