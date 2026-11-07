#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00185268(...) asm("func_00185268");
extern "C" int X_func_001853CC(...) asm("func_001853CC");
extern "C" int X_func_00185594(...) asm("func_00185594");
extern "C" int X_func_001856F4(...) asm("func_001856F4");
extern "C" int X_func_00187788(...) asm("func_00187788");
extern "C" int X_func_001879E0(...) asm("func_001879E0");
extern "C" int X_func_00187C30(...) asm("func_00187C30");
extern "C" int X_func_00187E44(...) asm("func_00187E44");
extern "C" int X_func_001880CC(...) asm("func_001880CC");
extern "C" int X_func_001881C0(...) asm("func_001881C0");
extern "C" int X_func_001883C0(...) asm("func_001883C0");
extern "C" int X_func_001885D4(...) asm("func_001885D4");
extern "C" int X_func_001887C0(...) asm("func_001887C0");
extern "C" int X_func_0018894C(...) asm("func_0018894C");
extern "C" int X_func_00188BFC(...) asm("func_00188BFC");
extern "C" int X_func_00188CD4(...) asm("func_00188CD4");
extern "C" int X_func_00188EC0(...) asm("func_00188EC0");
extern "C" int X_func_00189068(...) asm("func_00189068");
extern "C" int X_func_001892B0(...) asm("func_001892B0");
extern "C" int X_func_001894D4(...) asm("func_001894D4");
extern "C" int X_func_00189718(...) asm("func_00189718");
extern "C" int X_func_0018993C(...) asm("func_0018993C");
extern "C" int X_func_00189B7C(...) asm("func_00189B7C");
extern "C" int X_func_00189D94(...) asm("func_00189D94");
extern "C" int X_func_00189F58(...) asm("func_00189F58");
extern "C" int X_func_0018A50C(...) asm("func_0018A50C");
extern "C" int X_func_0018AD0C(...) asm("func_0018AD0C");
extern "C" int X_func_0018ADE0(...) asm("func_0018ADE0");
extern "C" int X_func_0018B12C(...) asm("func_0018B12C");
extern "C" int X_func_0018B2BC(...) asm("func_0018B2BC");
extern "C" int X_func_0018B918(...) asm("func_0018B918");
extern "C" int X_heapFree__FPv(...) asm("heapFree__FPv");
extern "C" int X_sceMcChdir(...) asm("sceMcChdir");
extern "C" int X_sceMcClose(...) asm("sceMcClose");
extern "C" int X_sceMcDelete(...) asm("sceMcDelete");
extern "C" int X_sceMcFlush(...) asm("sceMcFlush");
extern "C" int X_sceMcFormat(...) asm("sceMcFormat");
extern "C" int X_sceMcGetDir(...) asm("sceMcGetDir");
extern "C" int X_sceMcGetEntSpace(...) asm("sceMcGetEntSpace");
extern "C" int X_sceMcGetInfo(...) asm("sceMcGetInfo");
extern "C" int X_sceMcGetSlotMax(...) asm("sceMcGetSlotMax");
extern "C" int X_sceMcMkdir(...) asm("sceMcMkdir");
extern "C" int X_sceMcOpen(...) asm("sceMcOpen");
extern "C" int X_sceMcRead(...) asm("sceMcRead");
extern "C" int X_sceMcRename(...) asm("sceMcRename");
extern "C" int X_sceMcSeek(...) asm("sceMcSeek");
extern "C" int X_sceMcSync(...) asm("sceMcSync");
extern "C" int X_sceMcUnformat(...) asm("sceMcUnformat");
extern "C" int X_sceMcWrite(...) asm("sceMcWrite");
extern "C" int X_strchr(...) asm("strchr");
extern "C" int X_strcmp(...) asm("strcmp");
extern "C" int X_strcpy(...) asm("strcpy");
extern "C" int X_strrchr(...) asm("strrchr");
extern "C" int X_strstr(...) asm("strstr");
extern const char D_002F7898[];
extern const char D_002F78A0[];
extern const char D_002F78C8[];

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001875C0);

extern "C" void func_0018761C(int arg0, int arg1)
{
    int var_s1;
    int var_s0;

    if (arg1 >= 0) {
        var_s0 = arg0;
        var_s1 = 1;
        do {
            if (arg1 == (*(int *)(int *)((char *)(var_s0) + 0x0))) {
                X_func_00185268(var_s0, 0);
                X_func_001853CC(var_s0, 0);
                X_func_00185594(var_s0, 0);
                X_func_001856F4(var_s0, 0);
                (*(int *)(int *)((char *)(var_s0) + 0x0)) = -1;
                (*(int *)(int *)((char *)(var_s0) + 0x4)) = 1;
            }
            var_s1 -= 1;
            var_s0 += 0x3BC;
        } while (var_s1 >= 0);
    }
}


extern "C" void func_001876B0(int arg0, int arg1)
{
    int var_v1;
    int var_a0;

    var_a0 = arg0;
    if (arg1 >= 0) {
        var_v1 = 1;
        do {
            var_v1 -= 1;
            if (arg1 == (*(int *)(int *)((char *)(var_a0) + 0x0))) {
                (*(int *)(int *)((char *)(var_a0) + 0x20)) = (int) ((*(int *)(int *)((char *)(var_a0) + 0x20)) != 1);
            }
            var_a0 += 0x3BC;
        } while (var_v1 >= 0);
    }
}


INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001876E8);

extern "C" int func_00187724()
{
    return X_func_00187788();
}


INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00187738);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F73F0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7410);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7430);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7450);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7460);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7470);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7480);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7490);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74A0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74B0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74C0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74D0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74E0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74F0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7500);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7510);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7520);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7530);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7540);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7558);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7570);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7588);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F75A0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00187788);

extern "C" void func_001879C4()
{
    X_func_00187C30();
}


INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001879E0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00187A28);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7728);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00187B10);

extern "C" void func_00187C30()
{
    X_func_001879E0();
}


INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00187C4C);

extern "C" int func_00187E00(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x64));
}


INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00187E08);

extern "C" void func_00187E3C(void) {
}

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00187E44);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001880CC);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001881C0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001883C0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001885D4);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001887C0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018894C);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00188BFC);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00188CD4);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00188EC0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00189068);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001892B0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001894D4);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00189718);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018993C);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00189B7C);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00189D94);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00189F58);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7800);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7830);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018A17C);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018A3F4);

extern "C" void func_0018A4D4(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x80));
    if (temp_v0 != 0) {
        X_heapFree__FPv(temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0x80)) = 0;
    }
}


INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7868);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7888);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7898);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F78A0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018A50C);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018AD0C);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018ADE0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018B12C);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F78C8);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F78D8);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F78F8);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018B2BC);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018B874);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018B918);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018B9B8);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018BA68);
