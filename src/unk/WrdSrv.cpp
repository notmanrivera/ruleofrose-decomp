#include "include_asm.h"
extern "C" int Xiii_free__9BedMemoryPv(int, int) asm("free__9BedMemoryPv");
extern int D_006E9800;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_0017EA44(int, int) asm("func_0017EA44");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_WrdSrv__vfunc_01(...) asm("WrdSrv__vfunc_01");
extern "C" int X_func_0017E3D8(...) asm("func_0017E3D8");
extern "C" int X_func_0017E540(...) asm("func_0017E540");
extern "C" int X_func_0017F038(...) asm("func_0017F038");
extern "C" int X_memcmp(...) asm("memcmp");
extern "C" int X_strcmp(...) asm("strcmp");
extern "C" int X_strlen(...) asm("strlen");
extern int D_00298EE0;

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C60C);

extern "C" void func_0017C754(int arg0)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 0) & 2) {
        temp_v0 = M2C_FIELD(arg0, int *, 4);
        if (temp_v0 != 0) {
            Xiii_free__9BedMemoryPv((int) (int)&D_006E9800, temp_v0);
        }
    }
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C7B0);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C814);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C844);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C8B8);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C994);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CAA8);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CB50);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CC68);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CCE8);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CE74);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CF0C);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017D298);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017D35C);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017D62C);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017D9AC);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017DD5C);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017DED0);

extern "C" void func_0017DFA8(int arg0)
{
    int var_a2;
    int var_a1;

    var_a2 = 0;
    var_a1 = (*(int *)(int *)((char *)(arg0) + 0x8));
    if ((*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x4))) + 0x4)) > 0) {
        do {
            var_a2 += 1;
            (*(int *)(int *)((char *)(var_a1) + 0x5C)) = (int) ((*(int *)(int *)((char *)(var_a1) + 0x5C)) & 0x7FFFFFFF);
            var_a1 += 0x80;
        } while (var_a2 < (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x4))) + 0x4)));
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017DFF0);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E0A8);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E3D8);

extern "C" void func_0017E464(int arg0, int arg1, int arg2)
{
    int temp_v0_2;
    int var_a1;
    int temp_v0;
    int temp_v1;

    temp_v0 = X_func_0017E3D8();
    if (temp_v0 != 0) {
        var_a1 = 0;
        if ((*(int *)(int *)((char *)(temp_v0) + 0x18)) > 0) {
            do {
                temp_v0_2 = var_a1 * 4;
                var_a1 += 1;
                temp_v1 = *(int *)(temp_v0_2 + (*(int *)(int *)((char *)(temp_v0) + 0x14)));
                (*(int *)(int *)((char *)(temp_v1) + 0x8)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x8)) | arg2);
            } while (var_a1 < (*(int *)(int *)((char *)(temp_v0) + 0x18)));
        }
    }
}


extern "C" void func_0017E4D0(int arg0, int arg1, int arg2)
{
    int temp_v0_2;
    int var_a2;
    int temp_v0;
    int temp_v1;

    temp_v0 = X_func_0017E3D8();
    if (temp_v0 != 0) {
        var_a2 = 0;
        if ((*(int *)(int *)((char *)(temp_v0) + 0x18)) > 0) {
            do {
                temp_v0_2 = var_a2 * 4;
                var_a2 += 1;
                temp_v1 = *(int *)(temp_v0_2 + (*(int *)(int *)((char *)(temp_v0) + 0x14)));
                (*(int *)(int *)((char *)(temp_v1) + 0x8)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x8)) & ~arg2);
            } while (var_a2 < (*(int *)(int *)((char *)(temp_v0) + 0x18)));
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E540);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", WrdSrv__vfunc_01);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3080);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3090);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F30A0);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F30C8);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3118);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E5C0);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E798);

extern "C" void func_0017E9D0(int arg0)
{
    int temp_a1;
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x10);
    if (temp_v0 != 0) {
        Xiii_free__9BedMemoryPv((int) (int)&D_006E9800, temp_v0);
        M2C_FIELD(arg0, int *, 0x10) = 0;
    }
    if (M2C_FIELD(arg0, int *, 0) & 2) {
        temp_a1 = M2C_FIELD(arg0, int *, 4);
        if (temp_a1 != 0) {
            Xiii_free__9BedMemoryPv((int) (int)&D_006E9800, temp_a1);
        }
    }
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EA44);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EA84);

extern "C" void func_0017EB3C(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = Xiii_func_0017EA44(arg0, (int) arg2);
        M2C_FIELD(arg1, float *, 0) = (float) (M2C_FIELD(temp_v0, float *, 0x20) + M2C_FIELD(arg3, float *, 0));
        M2C_FIELD(arg1, float *, 4) = (float) (M2C_FIELD(temp_v0, float *, 0x24) + M2C_FIELD(arg3, float *, 4));
        M2C_FIELD(arg1, float *, 8) = (float) (M2C_FIELD(temp_v0, float *, 0x28) + M2C_FIELD(arg3, float *, 8));
    }
}

extern "C" void func_0017EBAC(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = Xiii_func_0017EA44(arg0, (int) arg3);
        M2C_FIELD(arg1, float *, 0) = (float) (M2C_FIELD(arg2, float *, 0) - M2C_FIELD(temp_v0, float *, 0x20));
        M2C_FIELD(arg1, float *, 4) = (float) (M2C_FIELD(arg2, float *, 4) - M2C_FIELD(temp_v0, float *, 0x24));
        M2C_FIELD(arg1, float *, 8) = (float) (M2C_FIELD(arg2, float *, 8) - M2C_FIELD(temp_v0, float *, 0x28));
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EC1C);

extern "C" void func_0017EFF4(int arg0)
{
    int var_a1;
    int var_a2;

    var_a2 = 0;
    var_a1 = (*(int *)(int *)((char *)(arg0) + 0x10));
    if ((*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x4))) + 0xC)) > 0) {
        do {
            var_a2 += 1;
            (*(int *)(var_a1)) &= ~1;
            var_a1 += 0x10;
        } while (var_a2 < (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x4))) + 0xC)));
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017F038);

extern "C" void func_0017F090()
{
    X_func_0017F038(1, 0xFFFF);
}


extern "C" void func_0017F0B0()
{
    X_func_0017F038(0, 0xFFFF);
}

