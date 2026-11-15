#include "include_asm.h"
extern "C" void *X_memset_p(void *, int, unsigned int) asm("memset");
extern "C" int func_0017DED0(void *, int, void *, float);
extern char D_006FBD80[];
extern "C" void X_func_001D83C0_v(void *, int) asm("func_001D83C0");
extern "C" void func_0017C340(void *, void *, void *, int, float, float);
extern "C" float func_0017DD5C(float, void *, int, void *);
extern "C" int Xiiiiii_func_001D81F0(int, int, int, int, int) asm("func_001D81F0");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_alloc__9BedMemoryiPCciii(...) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_func_001D83C0(...) asm("func_001D83C0");
extern "C" int X_memset(...) asm("memset");
extern int D_006E9800;
extern int D_007811B4;

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5610);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D56F4);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D58D8);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5A0C);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5BC8);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5DA0);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5EC4);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D6078);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D68A0);

extern "C" void func_001D7B00(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D7B08);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D7C20);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D7DE4);

extern "C" void func_001D7EB8()
{
    X_func_001D83C0();
}


extern "C" void *func_001D7ED4(void *arg0, int arg1, int arg2)
{
    X_func_001D83C0_v(arg0, arg2);
    char *entry = (char *)&D_007811B4 + arg2 * 0x18;
    char *ptr = 0;
    if (*(int *)(entry + 4) != 0) {
        char *base = *(char **)(entry + 0xC);
        if (base != 0) {
            ptr = base + arg1 * 0x90;
        }
    }
    return ptr;
}

extern "C" int func_001D7F48(void *arg0, void *arg1, int arg2)
{
    int sp[4];
    int off = 0x8542C;
    X_func_001D83C0_v(arg0, arg2);
    func_0017C340(D_006FBD80 + off, arg1, sp, 0, 40.0f, 0.0f);
    return sp[arg2];
}

extern "C" void *func_001D7FB8(void *arg0, void *arg1, int *arg2, int arg3)
{
    X_func_001D83C0_v(arg0, arg3);
    char *entry = (char *)&D_007811B4 + arg3 * 0x18;
    int idx = func_0017DED0(entry, *arg2, arg1, 40.0f);
    if (idx == -1) {
        return 0;
    }
    char *ptr = 0;
    if (*(int *)(entry + 4) != 0) {
        char *base = *(char **)(entry + 0xC);
        if (base != 0) {
            ptr = base + idx * 0x90;
        }
    }
    return ptr;
}

extern "C" void *func_001D8064(void *arg0, void *arg1, void *arg2, int arg3)
{
    void *sp[4];
    int off = 0x8542C;
    X_func_001D83C0_v(arg0, arg3);
    X_memset_p(sp, 0, sizeof(sp));
    sp[arg3] = arg2;
    func_0017C340(D_006FBD80 + off, arg1, sp, arg2 != 0, 200.0f, 0.0f);
    if (sp[arg3] != 0 && (*(int *)((char *)sp[arg3] + 8) & 4) != 0) {
        return 0;
    }
    return sp[arg3];
}

extern "C" void func_001D8114(void) {
}

// NON_MATCHING: 6/24 differ, 6 edits
#ifdef NON_MATCHING
extern "C" void *func_001D811C(int arg0, int arg1, float *arg2, int arg3)
{
    char *entry = (char *)&D_007811B4 + arg3 * 0x18;
    register char *ptr PS2_REG("$4") = 0;
    if (*(int *)(entry + 4) != 0) {
        char *base = *(char **)(entry + 0xC);
        if (base != 0) {
            ptr = base + arg1 * 0x90;
        }
    }
    arg2[0] = *(float *)(ptr + 0x10);
    arg2[1] = *(float *)(ptr + 0x14);
    arg2[2] = *(float *)(ptr + 0x18);
    return ptr;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D811C);
#endif

extern "C" float func_001D817C(int arg0, int *arg1, void *arg2, int arg3)
{
    float ret = 100000.0f;
    if (arg1 != 0) {
        ret = func_0017DD5C(0.0f, (char *)&D_007811B4 + arg3 * 0x18, *arg1, arg2);
    }
    return ret;
}

extern "C" void func_001D81C4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    struct { char pad0[512]; } stack;
    Xiiiiii_func_001D81F0(arg0, arg6, arg1, arg2, (int)&stack);
}

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D81F0);

extern "C" int func_001D831C()
{
    return 0;
}


extern "C" int func_001D8324()
{
    return 0;
}


extern "C" int func_001D832C()
{
    return 0;
}


extern "C" int func_001D8334()
{
    return 0;
}


extern "C" int func_001D833C()
{
    return 0;
}


extern "C" int func_001D8344()
{
    return 0;
}


extern "C" int func_001D834C()
{
    return 0;
}


extern "C" void func_001D8354(void) {
}

extern "C" void func_001D835C(void) {
}

extern "C" int func_001D8364()
{
    return 0;
}


extern "C" int func_001D836C(void *arg0, int arg1)
{
    char *entry = (char *)&D_007811B4 + *(int *)((char *)arg0 + 0x22AB0) * 0x18;
    char *ptr = 0;
    if (*(int *)(entry + 4) != 0) {
        char *base = *(char **)(entry + 0xC);
        if (base != 0) {
            ptr = base + arg1 * 0x90;
        }
    }
    return *(int *)(ptr + 8);
}

extern "C" void func_001D83C0(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x22AB0)) = arg1;
}


INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D83D0);

extern "C" int func_001D84A8()
{
    return 1;
}


extern "C" int func_001D84B0()
{
    return 0;
}


extern "C" int func_001D84B8()
{
    return 0;
}


extern "C" int func_001D84C0()
{
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1F0);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC3D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC3E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC3F8);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D84C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC418);
