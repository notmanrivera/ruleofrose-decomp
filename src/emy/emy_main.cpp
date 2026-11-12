#include "include_asm.h"
struct m2c_block8 { int w[2]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiiii_func_001DA740(int, int, int) asm("func_001DA740");
extern int D_002F14B0;
extern int _vt$7EmyMain;
extern "C" int Xiii_func_001636A4(int, int) asm("func_001636A4");
extern "C" int Xiii_func_001665B8(int, int) asm("func_001665B8");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiii_memset(int, int, int) asm("memset");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0014582C(...) asm("func_0014582C");
extern "C" int X_func_00154734(...) asm("func_00154734");
extern "C" int X_func_00154748(...) asm("func_00154748");
extern "C" int X_func_0016278C(...) asm("func_0016278C");
extern "C" int X_func_001629C0(...) asm("func_001629C0");
extern "C" int X_func_00162C88(...) asm("func_00162C88");
extern "C" int X_func_001636A4(...) asm("func_001636A4");
extern "C" int X_func_001656B4(...) asm("func_001656B4");
extern "C" int X_func_00165710(...) asm("func_00165710");
extern "C" int X_func_001661DC(...) asm("func_001661DC");
extern "C" int X_func_00166378(...) asm("func_00166378");
extern "C" int X_func_001664A4(...) asm("func_001664A4");
extern "C" int X_func_00166518(...) asm("func_00166518");
extern "C" int X_func_001665B8(...) asm("func_001665B8");
extern "C" int X_func_00166A0C(...) asm("func_00166A0C");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_00202F10(...) asm("func_00202F10");
extern "C" int X_memset(...) asm("memset");

extern "C" void func_00162698(int);
extern int _vt$10EmyManager;
extern "C" void Y_memset(int, int, int) asm("memset");

extern "C" void func_0016265C(int arg0)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$10EmyManager;
    func_00162698(arg0);
    return Y_memset(arg0 + 0x104, 0x64, 0x30);
}

extern "C" void func_00162698(int arg0)
{
    Xiiii_memset(arg0 + 4, 0, 0x100);
    Xiiii_memset(arg0 + 0x330, 0, 0x100);
    M2C_FIELD(arg0, signed char *, 0x134) = 0;
    M2C_FIELD(arg0, signed char *, 0x135) = 0;
    M2C_FIELD(arg0, int *, 0x138) = 0;
    M2C_FIELD(arg0, int *, 0x13C) = 0;
    Xiiii_memset(arg0 + 0x148, 0, 0x1E0);
    M2C_FIELD(arg0, int *, 0x144) = 0;
    M2C_FIELD(arg0, int *, 0x140) = 0;
}

extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void func_00163570(int);
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("EmyManager__vfunc_06");

extern "C" void EmyManager_vfunc06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$10EmyManager;
    func_00163570(arg0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

extern "C" int EmyManager__vfunc_04(int arg0)
{
    X_func_0016278C();
    X_func_001629C0(arg0);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_0016278C);

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_001629C0);

extern "C" void func_00162AFC(int arg0, int arg1, int arg2)
{
    (*(int *)(int *)((char *)(((arg1 * 0x3C) + arg0)) + 0x16C)) = arg2;
}


extern "C" int func_00162B14(int arg0, int arg1)
{
    int *p = (int *)(arg0 + 0x10);
    int *q = (int *)(arg0 + 8);
    int off = arg1 * 0x3C + 0x170;
    p = (int *)((char *)p + off);
    q = (int *)((char *)q + off);
    int old = *p;
    *p = old + 1;
    (*q)--;
    return old;
}

extern "C" void func_00162B50(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(((arg1 * 0x3C) + arg0)) + 0x170)) = 0;
}


INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00162B68);

extern "C" void func_00162C2C(int a0, int a1, unsigned short a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    X_func_00162C88(a0, a1, a2, a3, a4, a5, a6, a7, a8, 1, 0);
}

extern "C" void func_00162C5C(int a0, int a1, unsigned short a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    X_func_00162C88(a0, a1, a2, a3, a4, a5, a6, a7, 0, 0, a8);
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00162C88);

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_001634D4);

struct EmyX { int m_id; char pad[0x33C]; };
struct MgrX { int m_unk0; EmyX *m_emy[0x40]; };

extern "C" void func_00163570(int arg0)
{
    MgrX *m = (MgrX *)arg0;
    int i;
    for (i = 0; i < 0x40; i++) {
        EmyX *e = m->m_emy[i];
        if (e != 0) {
            int *vt = M2C_FIELD(e, int **, 0x200);
            char *entry = (char *)vt + 8;
            short adj = M2C_FIELD(entry, short *, 0);
            int fn = M2C_FIELD(entry, int *, 4);
            ((void (*)(int, int))fn)((int)e + adj, 3);
        }
    }
    func_00162698(arg0);
}

extern "C" void func_001635E0(int arg0)
{
    M2C_FIELD(arg0, signed char *, 0x134) = 0;
    M2C_FIELD(arg0, signed char *, 0x135) = 0;
    M2C_FIELD(arg0, int *, 0x138) = 0;
    M2C_FIELD(arg0, int *, 0x13C) = 0;
    Xiiii_memset(arg0 + 0x148, 0, 0x1E0);
    M2C_FIELD(arg0, int *, 0x144) = 0;
}

extern "C" void func_00163624(int arg0, int arg1, int arg2)
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        X_func_001661DC(temp_v0, arg2);
    }
}


extern "C" void func_0016365C(int arg0, int arg1, int arg2)
{
    (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x104)) = arg2;
}


extern "C" void func_0016366C(int arg0, int arg1, int arg2)
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        X_func_00166378(temp_v0, arg2);
    }
}


extern "C" int func_001636A4(int arg0, int arg1)
{
    MgrX *m = (MgrX *)arg0;
    int i;
    for (i = 0; i < 0x40; i++) {
        EmyX *e = m->m_emy[i];
        if (e != 0 && e->m_id == arg1) {
            return (int)e;
        }
    }
    return 0;
}

extern "C" int func_001636E4(int arg0, int arg1)
{
    if (arg1 == 0) {
        return M2C_FIELD(arg0, unsigned char *, 0x134) != 0;
    }
    return M2C_FIELD(arg0, unsigned char *, 0x135) != 0;
}

extern "C" void func_00163700(int arg0, int arg1, int arg2)
{
    if (arg1 == 0) {
        M2C_FIELD(arg0, int *, 0x138) = arg2;
        M2C_FIELD(arg0, signed char *, 0x134) = 1;
        return;
    }
    M2C_FIELD(arg0, int *, 0x13C) = arg2;
    M2C_FIELD(arg0, signed char *, 0x135) = 1;
}

extern "C" void func_00163720(int arg0, int arg1)
{
    if (arg1 == 0) {
        M2C_FIELD(arg0, signed char *, 0x134) = 0;
        M2C_FIELD(arg0, int *, 0x138) = 0;
    } else {
        M2C_FIELD(arg0, signed char *, 0x135) = 0;
        M2C_FIELD(arg0, int *, 0x13C) = 0;
    }
}

extern "C" int func_0016373C()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    return X_func_001656B4(p);
}

extern "C" int func_00163770()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    return X_func_00165710(p);
}

extern "C" int func_001637A4()
{
    int *p = (int *)X_func_001636A4();
    if (p != 0) {
        return M2C_FIELD(p, int *, 0xC);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_001637CC);

extern float D_002F1360[];

extern "C" float func_001638FC()
{
    int p = X_func_001636A4();
    if (p == 0) {
        goto fail;
    }
    {
        int *vt = M2C_FIELD(p, int **, 0x200);
        char *entry = (char *)vt + 0x18;
        short adj = M2C_FIELD(entry, short *, 0);
        int fn = M2C_FIELD(entry, int *, 4);
        float *tbl = D_002F1360;
        int r = ((int (*)(int))fn)(p + adj);
        return tbl[r];
    }
fail:
    return 0.0f;
}

extern float D_002F1390[];

extern "C" float func_00163958()
{
    int p = X_func_001636A4();
    if (p == 0) {
        goto fail;
    }
    {
        int *vt = M2C_FIELD(p, int **, 0x200);
        char *entry = (char *)vt + 0x18;
        short adj = M2C_FIELD(entry, short *, 0);
        int fn = M2C_FIELD(entry, int *, 4);
        float *tbl = D_002F1390;
        int r = ((int (*)(int))fn)(p + adj);
        return tbl[r];
    }
fail:
    return 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_001639B4);

extern "C" int func_00163A10()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    int v = M2C_FIELD(M2C_FIELD(p, int *, 0x20), int *, 0x120) & 0x200;
    return v != 0;
}

extern "C" void func_00163A44()
{
    int temp_v0;
    int temp_v0_2;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        temp_v0_2 = (*(int *)(int *)((char *)(temp_v0) + 0x20));
        (*(int *)(int *)((char *)(temp_v0_2) + 0x120)) = (int) ((*(int *)(int *)((char *)(temp_v0_2) + 0x120)) & ~0x400);
    }
}


extern "C" int func_00163A78(int arg0)
{
    return (M2C_FIELD(arg0, unsigned char *, 0x134) | M2C_FIELD(arg0, unsigned char *, 0x135)) != 0;
}

extern "C" int func_00163A8C()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    return M2C_FIELD(p, int *, 0x150) != 0;
}

extern "C" void func_00163AB8(int arg0, int *arg1, int *arg2)
{
    *arg1 = M2C_FIELD(arg0, int *, 0x138);
    *arg2 = M2C_FIELD(arg0, int *, 0x13C);
}

extern "C" void func_00163ACC(int arg0, int arg1, int arg2)
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(temp_v0) + 0x10)) = arg2;
    }
}


extern "C" int func_00163AF8()
{
    int *p = (int *)X_func_001636A4();
    if (p != 0) {
        return M2C_FIELD(p, int *, 0x14);
    }
    return 0;
}

extern "C" int func_00163B20()
{
    int *p = (int *)X_func_001636A4();
    if (p != 0) {
        return M2C_FIELD(p, int *, 0x3C);
    }
    return 0;
}

extern "C" int func_00163B48(int arg0, int arg1, int arg2)
{
    int p = X_func_001636A4();
    if (p != 0) {
        M2C_FIELD(p, int *, 0x238) = arg2;
        return 1;
    }
    return 0;
}

extern "C" int func_00163B80()
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        return X_func_00154734(temp_v0);
    }
    return 1;
}


extern "C" void func_00163BB8()
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        X_func_00154748(temp_v0);
    }
}


extern "C" void func_00163BE4()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return;
    }
    int *vt = M2C_FIELD(p, int **, 0x200);
    char *entry = (char *)vt + 0x18;
    short adj = M2C_FIELD(entry, short *, 0);
    int fn = M2C_FIELD(entry, int *, 4);
    ((void (*)(int))fn)(p + adj);
}

extern "C" void func_00163C24()
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(temp_v0) + 0x18)) = 1;
    }
}


extern "C" void func_00163C50()
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(temp_v0) + 0x18)) = 0;
    }
}


INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00163C74);

extern "C" int func_00163D90()
{
    int *p = (int *)X_func_001636A4();
    if (p != 0) {
        return M2C_FIELD(p, int *, 0x1D8);
    }
    return 0;
}

extern int D_002F1470[];

extern "C" int func_00163DB8()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    int *tbl = D_002F1470;
    int *vt = M2C_FIELD(p, int **, 0x200);
    char *entry = (char *)vt + 0x18;
    short adj = M2C_FIELD(entry, short *, 0);
    int fn = M2C_FIELD(entry, int *, 4);
    int r = ((int (*)(int))fn)(p + adj);
    return tbl[r];
}

extern "C" void func_00163E10(int arg0, int arg1, int arg2)
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        X_func_001664A4(temp_v0, arg2);
    }
}


extern "C" void func_00163E48()
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        X_func_00202F10((*(int *)(int *)((char *)(temp_v0) + 0x1F0)));
    }
}


extern "C" void func_00163E74()
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(temp_v0) + 0x1E4)) = 6;
    }
}


extern "C" int func_00163EA0(int arg0, int arg1, int arg2)
{
    int temp_v0;

    temp_v0 = Xiii_func_001636A4(arg0, arg1);
    if (temp_v0 != 0) {
        return Xiii_func_001665B8(temp_v0, arg2);
    }
    return (int) temp_v0;
}

extern "C" void func_00163EE4(int arg0, int arg1, int arg2)
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        X_func_0014582C(temp_v0, arg2);
    }
}


extern "C" int func_00163F1C()
{
    int *p = (int *)X_func_001636A4();
    if (p != 0) {
        return M2C_FIELD(p, int *, 0x238);
    }
    return 0;
}

extern "C" int func_00163F44()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    int *vt = M2C_FIELD(p, int **, 0x200);
    char *entry = (char *)vt + 0x18;
    short adj = M2C_FIELD(entry, short *, 0);
    int fn = M2C_FIELD(entry, int *, 4);
    int r = ((int (*)(int))fn)(p + adj);
    if (r != 0xA) {
        return 0;
    }
    return M2C_FIELD(p, int *, 0x24C);
}

extern "C" int func_00163F9C()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    int *vt = M2C_FIELD(p, int **, 0x200);
    char *entry = (char *)vt + 0x18;
    short adj = M2C_FIELD(entry, short *, 0);
    int fn = M2C_FIELD(entry, int *, 4);
    int r = ((int (*)(int))fn)(p + adj);
    if (r != 6) {
        return 0;
    }
    return M2C_FIELD(p, int *, 0x23C);
}

extern "C" int func_00163FF4()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    int *vt = M2C_FIELD(p, int **, 0x200);
    char *entry = (char *)vt + 0x18;
    short adj = M2C_FIELD(entry, short *, 0);
    int fn = M2C_FIELD(entry, int *, 4);
    int r = ((int (*)(int))fn)(p + adj);
    if (r != 8) {
        return 0;
    }
    return M2C_FIELD(p, int *, 0x248);
}

extern "C" void func_0016404C()
{
    int temp_v0;

    temp_v0 = X_func_001636A4();
    if (temp_v0 != 0) {
        X_func_00166518(temp_v0);
    }
}


extern "C" int func_00164078()
{
    int p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    return X_func_00166A0C(p);
}

extern "C" void func_001640AC(int arg0, int arg1, int arg2)
{
    MgrX *m = (MgrX *)arg0;
    int i;
    for (i = 0; i < 0x40; i++) {
        EmyX *e = m->m_emy[i];
        if (e != 0 && e->m_id == arg1) {
            int *slot = (int *)((i * 4) + (int)m);
            slot[0xCC] = arg2;
        }
    }
}

extern "C" int func_001640E8(int arg0)
{
    int var_a1;
    int var_a2;
    int var_a3;
    int temp_v0;

    var_a2 = 0;
    var_a3 = 0x300;
    var_a1 = 0x3F;
    do {
        temp_v0 = arg0 + var_a3;
        var_a3 += 4;
        var_a1 -= 1;
        if (M2C_FIELD(temp_v0, int *, 0x30) != 0) {
            var_a2++;
        }
    } while (var_a1 >= 0);
    return var_a2;
}

extern "C" int func_00164118(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    M2C_FIELD(arg0, int *, 0) = arg1;
    M2C_FIELD(arg0, int *, 0x200) = (int)&_vt$7EmyMain;
    M2C_FIELD(arg0, int *, 0x24) = -1;
    M2C_FIELD(arg0, int *, 0xE8) = arg5;
    M2C_FIELD(arg0, int *, 8) = 1;
    M2C_FIELD(arg0, int *, 0xC) = 1;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
    M2C_FIELD(arg0, int *, 0x20) = 0;
    M2C_FIELD(arg0, int *, 0x44) = 0;
    M2C_FIELD(arg0, int *, 0x28) = 1;
    M2C_FIELD(arg0, int *, 0x2C) = 1;
    M2C_FIELD(arg0, int *, 0x30) = 0;
    M2C_FIELD(arg0, int *, 0x150) = 0;
    *(m2c_block8 *)((char *)(arg0) + 476) = *(m2c_block8 *)((char *)(&D_002F14B0) + 0);
    M2C_FIELD(arg0, float *, 0x1C4) = 1.0f;
    M2C_FIELD(arg0, signed char *, 6) = 0;
    M2C_FIELD(arg0, int *, 0x1EC) = 0;
    M2C_FIELD(arg0, int *, 0x1F0) = 0;
    M2C_FIELD(arg0, int *, 0x1F8) = 0;
    Xiiii_memset(arg0 + 0x154, 0, 0x70);
    M2C_FIELD(arg0, int *, 0x20) = arg3;
    if (arg6 != 0) {
        Xiiii_func_001DA740((int) arg3, 0x59, arg6);
    }
    return Xiiii_memset(arg0 + 0x48, 0, 0xA0);
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", EmyMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00164364);

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00164508);

extern "C" void EmyMain__vfunc_05(int arg0)
{
    int temp_v0;
    int temp_v0_2;

    (*(int *)(int *)((char *)(arg0) + 0x40)) = 0;
    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x24));
    if (temp_v0 != -1) {
        temp_v0_2 = X_func_0016968C((*(int *)(int *)((char *)(arg0) + 0x1C)), temp_v0);
        if (temp_v0_2 != 0) {
            (*(int *)(int *)((char *)(arg0) + 0x3C)) = temp_v0_2;
            (*(int *)(int *)((char *)(arg0) + 0x40)) = 1;
        }
    }
}


INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1290);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F12A0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F12D0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1300);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1330);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1360);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1390);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F13C0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F13F0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1400);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1410);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1420);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1430);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1440);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1450);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1460);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1470);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F14A0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F14B0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F14B8);
