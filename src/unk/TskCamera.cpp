#include "include_asm.h"
extern "C" int Xiii_func_00218470(int, int, int) asm("func_00218470");
extern "C" int Xiii_getInfo__9BedMemoryP13BedMemoryInfoi(int, int, int) asm("getInfo__9BedMemoryP13BedMemoryInfoi");
extern "C" void Xv_func_001F9E58(int) asm("func_001F9E58");
extern int _vt$9TskDamage;
extern "C" int Xii_func_001FCBF8(int) asm("func_001FCBF8");
extern "C" int Xiiii_func_001F98C0(int, int, int) asm("func_001F98C0");
extern int _vt$9TskAttack;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiiii_strncpy(int, int, int) asm("strncpy");
extern "C" int Xiiiii_func_001FC4F0(int, int, int, int) asm("func_001FC4F0");
extern "C" int Xiiiii_func_001FC600(int, int, int, int) asm("func_001FC600");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_alloc__9BedMemoryiPCciii(...) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_func_00163624(...) asm("func_00163624");
extern "C" int X_func_00163C24(...) asm("func_00163C24");
extern "C" int X_func_00163C50(...) asm("func_00163C50");
extern "C" int X_func_00163E10(...) asm("func_00163E10");
extern "C" int X_func_00163E48(...) asm("func_00163E48");
extern "C" int X_func_00163E74(...) asm("func_00163E74");
extern "C" int X_func_0017FD58(...) asm("func_0017FD58");
extern "C" int X_func_00180078(...) asm("func_00180078");
extern "C" int X_func_001800D0(...) asm("func_001800D0");
extern "C" int X_func_001801C8(...) asm("func_001801C8");
extern "C" int X_func_001D1D5C(...) asm("func_001D1D5C");
extern "C" int X_func_001D9F10(...) asm("func_001D9F10");
extern "C" int X_func_001DA074(...) asm("func_001DA074");
extern "C" int X_func_001DA07C(...) asm("func_001DA07C");
extern "C" int X_func_001E50C8(...) asm("func_001E50C8");
extern "C" int X_func_001E5660(...) asm("func_001E5660");
extern "C" int X_func_001E5C40(...) asm("func_001E5C40");
extern "C" int X_func_001E5E58(...) asm("func_001E5E58");
extern "C" int X_func_001E63C0(...) asm("func_001E63C0");
extern "C" int X_func_001E6734(...) asm("func_001E6734");
extern "C" int X_func_001FC4F0(...) asm("func_001FC4F0");
extern "C" int X_func_001FC5E4(...) asm("func_001FC5E4");
extern "C" int X_func_001FC600(...) asm("func_001FC600");
extern "C" int X_func_001FCBF8(...) asm("func_001FCBF8");
extern "C" int X_func_00212FBC(...) asm("func_00212FBC");
extern "C" int X_heapFree__FPv(...) asm("heapFree__FPv");
extern "C" int X_memcpy(...) asm("memcpy");
extern "C" int X_strlen(...) asm("strlen");
extern const char D_002FEFF0[];
extern int D_006E9800;
extern int D_007812C0;
extern int D_007A4440;
extern int D_007B2140;
extern int D_007B2580;

extern "C" void func_001F8FB8(void) {
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FE980);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FE998);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FE9A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FE9B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FE9D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FE9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA48);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F8FC0);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", TskSnd__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", TskSnd__vfunc_05);

extern "C" float func_001F9294(int arg0)
{
    float var_f0;
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x38);
    var_f0 = 0.0f;
    if (temp_v0 > 0) {
        var_f0 = (float) M2C_FIELD(arg0, int *, 0x3C) / (float) temp_v0;
    }
    return var_f0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F92C8);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F93D8);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F9484);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F9550);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F95A8);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F9600);

extern "C" int func_001F9658(int arg0, int *arg1, int *arg2)
{
    *arg1 = M2C_FIELD(arg0, int *, 0x84);
    *arg2 = M2C_FIELD(arg0, int *, 0x88);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F9670);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F96C0);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F974C);

extern "C" int func_001F97C0()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F97C8);

extern "C" int func_001F985C(int arg0, int arg1, int arg2)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$9TskAttack;
    Xiiii_memset(arg0 + 4, 0, 8);
    M2C_FIELD(arg0, int *, 0x10) = arg1;
    return Xiiii_func_001F98C0(arg0, (int) arg1, (int) arg2);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEA98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEAA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEAA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEAB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEAB8);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F98C0);

extern "C" void TskAttack__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", TskAttack__vfunc_04);

extern "C" int func_001F9D74(int arg0)
{
    arg0 += 0x38;
    return M2C_FIELD(arg0, int *, 0)-- < 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F9D90);

extern "C" void func_001F9E38(int arg0)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$9TskDamage;
    return Xv_func_001F9E58(arg0);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB78);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEB98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBB8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBD0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBD8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEBE8);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001F9E58);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FA5BC);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FA768);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FA9C4);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FAA70);

extern "C" void TskDamage__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x18));
    if (temp_v0 != 0) {
        X_func_001DA074(temp_v0);
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", TskDamage__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FAC60);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FAE14);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FB084);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FB5D4);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FED70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FED78);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FED80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FED88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FED90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FED98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEDA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEDA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEDB0);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FB624);

extern "C" int func_001FBB04(int arg0)
{
    int temp_v1;
    int temp_v1_2;

    if ((*(int *)(int *)((char *)(arg0) + 0xC)) & 8) {
        temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x18));
        (*(int *)(int *)((char *)(temp_v1) + 0x120)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x120)) & ~0x200);
        temp_v1_2 = (*(int *)(int *)((char *)(arg0) + 0x10));
        if ((*(int *)(int *)((char *)(arg0) + 0x20)) < 0x2710) {
            X_func_00163E10((int)&D_007B2140, temp_v1_2, 0);
            X_func_00163E74((int)&D_007B2140, (*(int *)(int *)((char *)(arg0) + 0x10)));
            return 1;
        }
        X_func_00163E48((int)&D_007B2140, temp_v1_2);
        X_func_001DA07C((*(int *)(int *)((char *)(arg0) + 0x18)));
        return 1;
    }
    return 0;
}


extern "C" int func_001FBBA4()
{
    int info[4];

    Xiii_getInfo__9BedMemoryP13BedMemoryInfoi((int)&D_006E9800, (int)info, 0);
    return info[0];
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEE90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEEA0);

extern "C" void func_001FBBD0()
{
    static const char msg[0x30] = "free mem   max/total/size   = %d/%d \n";
    int info[4];

    Xiii_getInfo__9BedMemoryP13BedMemoryInfoi((int)&D_006E9800, (int)info, 0);
    Xiii_func_00218470((int)msg, info[0], info[1]);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FBC0C);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FBC6C);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FBD2C);

extern "C" void TskCamera__vfunc_03(void) {
}

extern "C" void TskCamera__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", TskCamera__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FC210);

extern "C" int func_001FC46C()
{
    return 0;
}


extern "C" int func_001FC474()
{
    return 0;
}


extern "C" void func_001FC47C(int arg0)
{
    M2C_FIELD(arg0, int *, 0x400) = 0;
    M2C_FIELD(arg0, int *, 0x50C) = 0;
    M2C_FIELD(arg0, int *, 0x504) = 0;
    M2C_FIELD(arg0, int *, 0x508) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FC490);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FC4F0);

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


INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FC89C);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FC9E8);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FCAAC);

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FCB14);

extern "C" void func_001FCBF8(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x8)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0xC)) = -1;
    if (*(int *)(*(int *)(int *)((char *)(arg0) + 0x0)) == 0) {
        (*(int *)(int *)((char *)(arg0) + 0x8)) = 1;
    }
}


INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFD0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFF0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FF008);
