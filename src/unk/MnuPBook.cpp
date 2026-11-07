#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_alloc__9BedMemoryii(...) asm("alloc__9BedMemoryii");
extern "C" int X_free__9BedMemoryPv(...) asm("free__9BedMemoryPv");
extern "C" int X_func_00134730(...) asm("func_00134730");
extern "C" int X_func_001348B0(...) asm("func_001348B0");
extern "C" int X_func_00134A00(...) asm("func_00134A00");
extern "C" int X_func_00134AB8(...) asm("func_00134AB8");
extern "C" int X_func_00134CD0(...) asm("func_00134CD0");
extern "C" int X_func_001351B0(...) asm("func_001351B0");
extern "C" int X_func_00135418(...) asm("func_00135418");
extern "C" int X_func_00135494(...) asm("func_00135494");
extern "C" int X_func_00135594(...) asm("func_00135594");
extern "C" int X_func_001832E8(...) asm("func_001832E8");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001874F4(...) asm("func_001874F4");
extern "C" int X_func_00192E94(...) asm("func_00192E94");
extern "C" int X_func_0019381C(...) asm("func_0019381C");
extern "C" int X_func_00193868(...) asm("func_00193868");
extern "C" int X_func_0019397C(...) asm("func_0019397C");
extern "C" int X_func_00193E20(...) asm("func_00193E20");
extern "C" int X_func_00193F74(...) asm("func_00193F74");
extern "C" int X_func_00193FEC(...) asm("func_00193FEC");
extern "C" int X_func_001940A4(...) asm("func_001940A4");
extern "C" int X_func_001943D8(...) asm("func_001943D8");
extern "C" int X_func_00194588(...) asm("func_00194588");
extern "C" int X_func_00194688(...) asm("func_00194688");
extern "C" int X_func_00197E68(...) asm("func_00197E68");
extern "C" int X_func_001C5094(...) asm("func_001C5094");
extern "C" int X_func_001C5168(...) asm("func_001C5168");
extern "C" int X_func_001C51E0(...) asm("func_001C51E0");
extern "C" int X_func_0021A5B0(...) asm("func_0021A5B0");
extern "C" int X_func_0021A700(...) asm("func_0021A700");
extern "C" int X_func_0022AED8(...) asm("func_0022AED8");
extern "C" int X_func_0022B330(...) asm("func_0022B330");
extern "C" int X_func_0022B350(...) asm("func_0022B350");
extern "C" int X_func_0022B370(...) asm("func_0022B370");
extern "C" int X_func_0022B3D8(...) asm("func_0022B3D8");
extern "C" int X_func_0022B6F8(...) asm("func_0022B6F8");
extern "C" int X_func_0022B730(...) asm("func_0022B730");
extern "C" int X_memcpy(...) asm("memcpy");
extern "C" int X_memmove(...) asm("memmove");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_mnuBase__vfunc_03(...) asm("mnuBase__vfunc_03");
extern "C" int X_releaseTex__10DogTexInfoi(...) asm("releaseTex__10DogTexInfoi");
extern "C" int X_strcpy(...) asm("strcpy");
extern int D_0029BFB4;
extern int D_0029C0F8;
extern int D_006E9800;
extern int D_007812C0;

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_0019397C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193A1C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193D1C);

extern "C" void func_00193DFC(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x20)) > 0) {
        (*(int *)(int *)((char *)(arg0) + 0x20)) = 1;
        (*(int *)(int *)((char *)(arg0) + 0x4)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x4)) | 8);
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193E20);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193E7C);

extern "C" void func_00193F74(int arg0, int arg1)
{
    if (arg1 != 0) {
        X_func_00194688(arg1);
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193F98);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193FEC);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001940A4);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194148);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194280);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001942CC);

extern "C" void func_00194370(int arg0, int arg1)
{
    int temp_s0;

    if (X_func_001943D8() != 0) {
        temp_s0 = (*(int *)(int *)((char *)(arg0) + 0xA4)) + (arg1 * 0x10);
        X_releaseTex__10DogTexInfoi((*(int *)(int *)((char *)(arg0) + 0xC)), (*(int *)(int *)((char *)(temp_s0) + 0x8)));
        X_func_00193F74(arg0, (*(int *)(int *)((char *)(temp_s0) + 0x0)));
        (*(int *)(int *)((char *)(temp_s0) + 0x0)) = 0;
        (*(int *)(int *)((char *)(temp_s0) + 0x4)) = 0;
        (*(int *)(int *)((char *)(temp_s0) + 0x8)) = -1;
    }
}


extern "C" int func_001943D8(int arg0, int arg1)
{
    int var_a0;
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0xA4)) + (arg1 * 0x10);
    var_a0 = 0;
    if ((*(int *)(int *)((char *)(temp_v1) + 0x0)) != 0) {
        var_a0 = ~(*(int *)(int *)((char *)(temp_v1) + 0x8)) != 0;
    }
    return var_a0;
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194404);

extern "C" void func_001944D0()
{
    int temp_v0;

    temp_v0 = X_alloc__9BedMemoryii((int)&D_006E9800, 0x100800, -1);
    D_0029BFB4 = temp_v0;
    X_memset(temp_v0, 0, 0x100800);
    (*(int *)(int *)((char *)(D_0029BFB4) + 0x0)) = D_0029BFB4 + 0x800;
    (*(int *)(int *)((char *)(D_0029BFB4) + 0x4)) = 0x100000;
    (*(int *)(int *)((char *)(D_0029BFB4) + 0x8)) = 1;
}


extern "C" void func_00194548()
{
    if (D_0029BFB4 != 0) {
        X_free__9BedMemoryPv((int)&D_006E9800, D_0029BFB4);
        D_0029BFB4 = 0;
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194588);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194688);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001946E4);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F7D20);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001947A4);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuMap__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuMap__vfunc_02);

extern "C" void MnuMap__vfunc_03(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x144));
    if (temp_v0 != -1) {
        X_func_001348B0((*(int *)(int *)((char *)(arg0) + 0x8)), temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0x144)) = -1;
    }
    X_func_00193868(arg0);
    X_func_00187464(arg0 + 0x150);
    X_mnuBase__vfunc_03(arg0);
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001949BC);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194FA4);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuMap__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195430);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_0019586C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195958);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001959EC);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195A34);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195B78);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuMap__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196760);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196790);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196804);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F7DC0);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196878);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196A9C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_01);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F8048);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196E54);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196EA4);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196EFC);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_0019722C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001973FC);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80D0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80E0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80F0);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00197A74);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00197D28);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00197E68);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00197F18);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_07);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F8140);
