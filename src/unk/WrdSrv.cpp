#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C754);

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

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E9D0);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EA44);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EA84);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EB3C);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EBAC);

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

