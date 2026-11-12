#include "include_asm.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern "C" char vtbl_S2dMes[] asm("_vt$6S2dMes");
extern "C" int Xii_func_0019183C(int) asm("func_0019183C");
extern "C" int Xiii_func_001905A8(int, int) asm("func_001905A8");
extern "C" int Xiii_strcpy(int, int) asm("strcpy");
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern "C" char vtbl_S2dBg[] asm("_vt$5S2dBg");
extern "C" int func_00191054(int);
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern "C" char vtbl_S2dCineSco[] asm("_vt$10S2dCineSco");
extern "C" int Xii_func_0018BB8C(int) asm("func_0018BB8C");
extern "C" int func_00190B60(int);
extern "C" int Xiii_func_0018C190(int, int) asm("func_0018C190");
extern int D_002999D8;
extern int D_00299B90;
extern "C" int Xii_func_0018FEBC(int) asm("func_0018FEBC");
extern "C" int Xii_func_00190C44(int) asm("func_00190C44");
extern "C" int Xiii_func_0018BCC0(int, int) asm("func_0018BCC0");
extern "C" int Xiiii_func_00190884(int, int, int) asm("func_00190884");
extern "C" int Xiiiiiiiii_func_0018F1F4(int, int, int, int, int, int, int, int) asm("func_0018F1F4");
extern int D_00299990;
extern int D_002999B0;
extern "C" int Xii_func_00191124(int) asm("func_00191124");
extern "C" int Xii_func_00191174(int) asm("func_00191174");
extern "C" int Xiiii_func_0018F744(int, int, int) asm("func_0018F744");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_alloc__9BedMemoryiPCciii(...) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_func_0018BCC0(...) asm("func_0018BCC0");
extern "C" int X_func_0018BD94(...) asm("func_0018BD94");
extern "C" int X_func_0018C068(...) asm("func_0018C068");
extern "C" int X_func_0018C130(...) asm("func_0018C130");
extern "C" int X_func_0018D7EC(...) asm("func_0018D7EC");
extern "C" int X_func_0018F1F4(...) asm("func_0018F1F4");
extern "C" int X_func_0018F41C(...) asm("func_0018F41C");
extern "C" int X_func_0018F6DC(...) asm("func_0018F6DC");
extern "C" int X_func_0018F744(...) asm("func_0018F744");
extern "C" int X_func_0018FEBC(...) asm("func_0018FEBC");
extern "C" int X_func_001905A0(...) asm("func_001905A0");
extern "C" int X_func_00190884(...) asm("func_00190884");
extern "C" int X_func_001908D0(...) asm("func_001908D0");
extern "C" int X_func_00190C44(...) asm("func_00190C44");
extern "C" int X_func_00190C68(...) asm("func_00190C68");
extern "C" int X_func_00190C84(...) asm("func_00190C84");
extern "C" int X_func_00190D20(...) asm("func_00190D20");
extern "C" int X_func_00190D70(...) asm("func_00190D70");
extern "C" int X_func_00191124(...) asm("func_00191124");
extern "C" int X_func_00191158(...) asm("func_00191158");
extern "C" int X_func_00191174(...) asm("func_00191174");
extern "C" int X_func_00191248(...) asm("func_00191248");
extern "C" int X_func_00191258(...) asm("func_00191258");
extern "C" int X_func_00191278(...) asm("func_00191278");
extern "C" int X_func_001912A0(...) asm("func_001912A0");
extern "C" int X_func_00191640(...) asm("func_00191640");
extern "C" int X_func_001916C4(...) asm("func_001916C4");
extern "C" int X_func_001916F8(...) asm("func_001916F8");
extern "C" int X_func_00191718(...) asm("func_00191718");
extern "C" int X_getIndex__C6BedPfhPCc(...) asm("getIndex__C6BedPfhPCc");
extern "C" int X_heapFree__FPv(...) asm("heapFree__FPv");
extern "C" int X_memcpy(...) asm("memcpy");
extern "C" int X_releaseTex__10DogTexInfoi(...) asm("releaseTex__10DogTexInfoi");
extern const char D_002F7A18[];
extern int D_0029A340;
extern int D_006E9800;
extern "C" int *X_magCurrentSystem asm("_9MagSystem$m_current_system");

extern "C" int func_0018F6DC(int arg0, int arg1)
{
    int temp_v0;

    temp_v0 = M2C_FIELD(((arg1 * 4) + arg0), int *, 0x21C);
    if (temp_v0 < 0)
        temp_v0 = -1;
    return temp_v0;
}

extern "C" int func_0018F6F8(int arg0, int arg1)
{
    int idx = X_func_0018F6DC(arg0, arg1);

    if (idx < 0) {
        return -1;
    }
    return M2C_FIELD((idx * 4) + arg0, int *, 0x12C);
}

extern "C" int func_0018F734(int arg0, int arg1)
{
    return (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x30C));
}


INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018F744);

extern "C" void func_0018F808(int arg0, int arg1, int arg2, int arg3)
{
    M2C_FIELD(arg0, int *, 0x434) = arg3;
    Xiiii_func_0018F744(arg0, arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018F824);

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018F9CC);

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018FAB4);

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018FBB0);

extern "C" int func_0018FE8C(int arg0, int arg1)
{
    if (M2C_FIELD(arg0, int *, 0x430) == 0) {
        return -1;
    }
    return X_getIndex__C6BedPfhPCc(M2C_FIELD(arg0, int *, 0x430), arg1);
}

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F79E0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F79F0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F79F8);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7A18);

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018FEBC);

extern "C" void func_001905A0(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x11C)) = arg1;
}


extern "C" void func_001905A8(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x120)) = arg1;
}


extern "C" int func_001905B0(int arg0, int arg1, int arg2, unsigned int arg3, int arg4)
{
    Xiii_strcpy(arg0 + 0x10, (int) arg1);
    M2C_FIELD(arg0, int *, 0x110) = arg2;
    M2C_FIELD(arg0, unsigned int *, 0x114) = arg3;
    M2C_FIELD(arg0, int *, 0x118) = arg4;
    Xiii_func_001905A8(arg0, 1);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_00190618);

extern "C" int func_00190884(int arg0, const unsigned char *arg1, const unsigned char *arg2)
{
    while (*arg1 != 0) {
        if (*arg1 != *arg2) {
            return -1;
        }
        arg1++;
        arg2++;
    }
    return *arg1 != *arg2;
}

extern "C" int func_001908D0(int arg0, int arg1)
{
    static const char sMagic[16] = "RTCM";
    unsigned int var_v0;

    var_v0 = 0;
    if (arg1 != 0) {
        var_v0 = (unsigned int) ~Xiiii_func_00190884(arg0, (int)sMagic, arg1) >> 0x1F;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_00190904);

extern "C" int func_00190A78(int arg0)
{
    *(void **)(arg0 + 0x14) = vtbl_S2dCineSco;
    *(u_long128 *)arg0 = 0;
    M2C_FIELD(arg0, int *, 0x10) = 1;
    M2C_FIELD(arg0, int *, 4) = -1;
    M2C_FIELD(arg0, int *, 0) = 0;
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0x20) = 0;
    Xii_func_0018BB8C(arg0 + 0x3C);
    return func_00190B60(arg0);
}

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", S2dCineSco__vfunc_01);

extern "C" int func_00190B60(int arg0)
{
    M2C_FIELD(arg0, int *, 0x30) = 0;
    M2C_FIELD(arg0, int *, 0x34) = 0;
    return 0;
}

extern "C" int func_00190B70(int arg0, int arg1)
{
    Xiii_func_0018BCC0(arg0 + 0x3C, 3);
    M2C_FIELD(arg0, int *, 0x458) = arg1;
    Xii_func_00190C44(arg0);
    M2C_FIELD(arg0, int *, 0x34) = 1;
    return 1;
}

extern "C" void func_00190BBC(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x34)) != 0) {
        X_func_0018C130(arg0 + 0x3C);
        X_func_00190C68(arg0);
        (*(int *)(int *)((char *)(arg0) + 0x34)) = 0;
    }
}


extern "C" int func_00190BFC(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x34));
}


extern "C" void S2dCineSco__vfunc_02()
{
    X_func_00190C84();
}


extern "C" void S2dCineSco__vfunc_06(char *arg0, int arg1)
{
    if (arg1) {
        arg0 += 0x3C;
        M2C_FIELD(arg0, int *, 0x4D0) = arg1;
        X_func_0018BD94(arg0);
    }
}

extern "C" int func_00190C44(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0x30) == 1) {
        return -1;
    }
    M2C_FIELD(arg0, int *, 0x30) = 1;
    M2C_FIELD(arg0, int *, 0x38) = 0;
    return 0;
}

extern "C" int func_00190C68(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0x30) == 0) {
        return -1;
    }
    M2C_FIELD(arg0, int *, 0x30) = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_00190C84);

extern "C" void func_00190D20(int arg0)
{
    int temp_s0;

    temp_s0 = arg0 + 0x3C;
    M2C_FIELD(arg0, int *, 0x928) = (int) X_magCurrentSystem;
    M2C_FIELD(temp_s0, int *, 0x4B0) = (int)&D_002999D8;
    Xiii_func_0018C190(temp_s0, (int)&D_00299B90);
    M2C_FIELD(temp_s0, int *, 4) = 1;
}

extern "C" int func_00190D70(int arg0)
{
    X_func_0018C068(arg0 + 0x3C);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_00190D90);

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_00190E98);

extern "C" int func_00190F6C(int arg0)
{
    *(void **)(arg0 + 0x14) = vtbl_S2dBg;
    *(u_long128 *)arg0 = 0;
    M2C_FIELD(arg0, int *, 0x10) = 1;
    M2C_FIELD(arg0, int *, 4) = -1;
    M2C_FIELD(arg0, int *, 0) = 0;
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0x20) = 0;
    Xii_func_0018BB8C(arg0 + 0x48);
    return func_00191054(arg0);
}

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", S2dBg__vfunc_01);

extern "C" int func_00191054(int arg0)
{
    M2C_FIELD(arg0, int *, 0x30) = 0;
    M2C_FIELD(arg0, int *, 0x34) = 0;
    M2C_FIELD(arg0, int *, 0x93C) = 0;
    return 0;
}

extern "C" int func_00191068(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x938) = arg1;
    Xii_func_00191124(arg0);
    M2C_FIELD(arg0, int *, 0x34) = 1;
    return 1;
}

extern "C" void func_00191098(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x34)) != 0) {
        X_func_00191158();
        (*(int *)(int *)((char *)(arg0) + 0x34)) = 0;
    }
}


extern "C" int func_001910D0(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x34));
}


extern "C" void S2dBg__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) + 1);
    Xii_func_00191174(arg0);
}

extern "C" void S2dBg__vfunc_06(char *arg0, int arg1)
{
    if (arg1) {
        arg0 += 0x48;
        M2C_FIELD(arg0, int *, 0x4D0) = arg1;
        X_func_0018BD94(arg0);
    }
}

extern "C" int func_00191124(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0x30) == 1) {
        return -1;
    }
    M2C_FIELD(arg0, int *, 0x30) = 1;
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    M2C_FIELD(arg0, int *, 0x40) = 0;
    M2C_FIELD(arg0, int *, 0x44) = 2;
    M2C_FIELD(arg0, int *, 0x38) = 0;
    return 0;
}

extern "C" int func_00191158(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0x30) == 0) {
        return -1;
    }
    M2C_FIELD(arg0, int *, 0x30) = 0;
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7AC0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7AD0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7AF0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B00);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B10);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B20);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B30);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B40);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B50);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B60);

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_00191174);




extern "C" void func_00191248(int arg0)
{
    (*(int **)(int *)((char *)(arg0) + 0x934)) = X_magCurrentSystem;
}

extern "C" int func_00191258()
{
    X_func_001912A0();
    return 0;
}


extern "C" int func_00191278(int arg0)
{
    int v = M2C_FIELD(arg0, int *, 0x40);

    if (v != 3) {
        if (v < 4) {
            if (v == 0) {
                M2C_FIELD(arg0, int *, 0x40) = 3;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_001912A0);

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_001913C4);

extern "C" void func_0019143C(int arg0, int arg1, int arg2)
{
    Xiiiiiiiii_func_0018F1F4(arg0 + 0x48, arg1, 1, arg2, 0, -1, (int)&D_002999B0, (int)&D_00299990);
}

extern "C" void func_00191478(int arg0)
{
    X_func_0018F41C(arg0 + 0x48);
}


extern "C" void func_00191494(int arg0)
{
    *(void **)(arg0 + 0x14) = vtbl_S2dMes;
    *(u_long128 *)arg0 = 0;
    M2C_FIELD(arg0, int *, 0x10) = 1;
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 4) = -1;
    M2C_FIELD(arg0, int *, 0) = 0;
    M2C_FIELD(arg0, int *, 0x20) = 0;
    Xii_func_0018BB8C(arg0 + 0x48);
    M2C_FIELD(arg0, int *, 0x30) = 0;
    Xii_func_0019183C(arg0);
    M2C_FIELD(arg0, int *, 0x34) = 0;
}

INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", S2dMes__vfunc_01);

extern "C" int func_00191588(int arg0, int arg1)
{
    X_func_0018BCC0(arg0 + 0x48, 0x10);
    (*(int *)(int *)((char *)(arg0) + 0x464)) = arg1;
    (*(int *)(int *)((char *)(arg0) + 0x48)) = 1;
    X_func_001916C4(arg0);
    X_func_00191640(arg0);
    (*(int *)(int *)((char *)(arg0) + 0x34)) = 1;
    return 1;
}


extern "C" void func_001915F8(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x34)) != 0) {
        X_func_0018C130(arg0 + 0x48);
        X_func_001916F8(arg0);
        (*(int *)(int *)((char *)(arg0) + 0x34)) = 0;
    }
}


extern "C" int func_00191638(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x34));
}


INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7BD8);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7BE8);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C00);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C10);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C20);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C30);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C40);

extern "C" void func_00191640(int arg0)
{
    int temp_s0;

    temp_s0 = arg0 + 0x50;
    Xiiii_func_0018F744(temp_s0, (int)&D_0029A340, (int) "data/mnurpk/s2dman.rpk");
    do {

    } while (Xii_func_0018FEBC(temp_s0) == 0);
}

extern "C" void S2dMes__vfunc_02()
{
    X_func_00191718();
}


extern "C" void S2dMes__vfunc_06(char *arg0, int arg1)
{
    if (arg1) {
        arg0 += 0x48;
        M2C_FIELD(arg0, int *, 0x4D0) = arg1;
        X_func_0018BD94(arg0);
    }
}
