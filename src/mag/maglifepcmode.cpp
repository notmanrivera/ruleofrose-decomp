#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_func_0011EE00(...) asm("func_0011EE00");
extern "C" int Xii_func_0011A054(int) asm("func_0011A054");
extern "C" int Xiiis_func_0011A320(int, int, short) asm("func_0011A320");
extern "C" int Xiiiui_func_0011C1E8(int, int, unsigned int, int) asm("func_0011C1E8");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001026B0(...) asm("func_001026B0");
extern "C" int X_func_0010AA5C__8DogActorPCc(...) asm("func_0010AA5C__8DogActorPCc");
extern "C" int X_func_0010B1B0__8DogActoriifii(...) asm("func_0010B1B0__8DogActoriifii");
extern "C" int X_func_0011A054(...) asm("func_0011A054");
extern "C" int X_func_0011A27C(...) asm("func_0011A27C");
extern "C" int X_func_0011A320(...) asm("func_0011A320");
extern "C" int X_func_0011AF04(...) asm("func_0011AF04");
extern "C" int X_func_0011AF30(...) asm("func_0011AF30");
extern "C" int X_func_0011B128(...) asm("func_0011B128");
extern "C" int X_func_0011BDC0(...) asm("func_0011BDC0");
extern "C" int X_func_0011BE00(...) asm("func_0011BE00");
extern "C" int X_func_0011C1E8(...) asm("func_0011C1E8");
extern "C" int X_func_0011CE50(...) asm("func_0011CE50");
extern "C" int X_func_0011D06C(...) asm("func_0011D06C");
extern "C" int X_func_0011DF7C(...) asm("func_0011DF7C");
extern "C" int X_func_0011DFD0(...) asm("func_0011DFD0");
extern "C" int X_func_001207A8(...) asm("func_001207A8");
extern "C" int X_func_00120DEC(...) asm("func_00120DEC");
extern "C" int X_func_0012B788(...) asm("func_0012B788");
extern "C" int X_func_0012C31C(...) asm("func_0012C31C");
extern "C" int X_getMainMotionNo__C14DogMotionBlend(...) asm("getMainMotionNo__C14DogMotionBlend");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern "C" int X_vibrate__9MagSystemi(...) asm("vibrate__9MagSystemi");
extern const char D_002EAD28[];
extern const char D_002EAD60[];
extern int D_006E9840;

extern "C" void func_00120788(int arg0, int arg1, int arg2)
{
    X_func_0011EE00(arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", func_001207A8);

extern "C" void live__13MagLifePCModeR9MagLifePC(int arg0, int arg1)
{
    X_func_001207A8();
    if (X_func_0011A054(arg1) != 0) {
        X_func_0011C1E8(arg1, 0, 0, 0);
    }
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeNullR9MagLifePC);

extern "C" void live__17MagLifePCModeNullR9MagLifePC(int arg0, int arg1)
{
    if ((*(int *)(int *)((char *)(arg1) + 0x58)) != 0) {
        X_func_0011C1E8(arg1, 1, 0, 0);
    }
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeWaitR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", func_00120A54);

extern "C" void live__17MagLifePCModeWaitR9MagLifePC(int arg0, int arg1)
{
    X_func_0011BE00(arg1);
    X_func_001207A8(arg0, arg1);
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD28);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", pad__17MagLifePCModeWaitR9MagLifePCRC6BedPad);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", func_00120DEC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeWalk2D__vfunc_01);

extern "C" void func_00121054()
{
    X_func_00120DEC();
}


extern "C" void MagLifePCModeWalk2D__vfunc_02(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeWalk2D__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeRun2D__vfunc_01);

extern "C" void func_001211AC()
{
    X_func_00120DEC();
}


extern "C" void MagLifePCModeRun2D__vfunc_02(int arg0, int arg1)
{
    X_func_0011BDC0(arg1);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeRun2D__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeTurn__vfunc_01);

extern "C" void func_00121348()
{
    X_func_001207A8();
}


extern "C" void MagLifePCModeTurn__vfunc_02(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeTurn__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD68);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD78);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD88);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD98);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__22MagLifePCModeAtkWait2DR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", func_00121604);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__22MagLifePCModeAtkWait2DR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", pad__22MagLifePCModeAtkWait2DR9MagLifePCRC6BedPad);

extern "C" void MagLifePCModeAtkMove2D__vfunc_01(int arg0, int arg1)
{
    X_func_0011DF7C(arg1);
    (*(int *)(int *)((char *)(arg1) + 0xF4)) = -1;
}


extern "C" void func_00121888(void) {
}

extern "C" void MagLifePCModeAtkMove2D__vfunc_02(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeAtkMove2D__vfunc_03);

extern "C" void MagLifePCModeAttacking__vfunc_01(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x4)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x8)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0xC)) = X_func_0012C31C(arg1, 0);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeAttacking__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeAttacking__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__19MagLifePCModeDamageR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__19MagLifePCModeDamageR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeItemR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__17MagLifePCModeItemR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__18MagLifePCModeDogGoR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__18MagLifePCModeDogGoR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__20MagLifePCModeDogComeR9MagLifePC);

extern "C" void live__20MagLifePCModeDogComeR9MagLifePC(int arg0, int arg1)
{
    if (((unsigned int) ((*(int *)(int *)((char *)(arg1) + 0x8)) - 1) < 2U) && (X_func_0011A054(arg1) != 0)) {
        X_func_0011AF30(arg1, 0x10, 2);
        X_func_0011C1E8(arg1, 0, 0, 0);
    }
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__20MagLifePCModeDogStayR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__20MagLifePCModeDogStayR9MagLifePC);

extern "C" void init__17MagLifePCModeHoldR9MagLifePC(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg1) + 0xEC)) = 0;
    (*(int *)(int *)((char *)(arg1) + 0xE0)) = 0;
    X_func_0011DFD0(arg1);
    X_func_0011A320(arg1, 0xA, -1);
    (*(int *)(int *)((char *)(arg1) + 0x8)) = 0;
}


extern "C" int pad__17MagLifePCModeHoldR9MagLifePCRC6BedPad(int arg0, int arg1, int arg2)
{
    int temp_s2;
    int temp_v1;

    temp_s2 = M2C_FIELD(arg1, int *, 8);
    temp_v1 = Xii_func_0011A054((int) arg1);
    if (M2C_FIELD(arg2, int *, 0x64) >= 0x10) {
        Xiiiui_func_0011C1E8((int) arg1, 0xC, 0U, 0);
        return 2;
    }
    if (temp_s2 == 0) {
        if (!(M2C_FIELD(arg1, float *, 0x104) > 0.0f)) {
            Xiiis_func_0011A320((int) arg1, 0xA, -1);
            goto block_8;
        }
        Xiiis_func_0011A320((int) arg1, 0xC, -1);
        M2C_FIELD(arg1, int *, 8) = 1;
        return 1;
    }
    if (temp_v1 != 0) {
        Xiiis_func_0011A320((int) arg1, 0xA, -1);
        M2C_FIELD(arg1, int *, 8) = 0;
    }
block_8:
    return 1;
}

extern "C" void init__23MagLifePCModeHoldAttackR9MagLifePC(int arg0, int arg1)
{
    X_func_0011A320(arg1, 0xD, -1);
    X_func_001026B0(0x2E, 0, 0);
}


extern "C" void init__19MagLifePCModeUnholdR9MagLifePC(int arg0, int arg1)
{
    X_func_0011A320(arg1, 0xE, -1);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeRideR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__17MagLifePCModeRideR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", pad__17MagLifePCModeRideR9MagLifePCRC6BedPad);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", func_00122C9C);

extern "C" void init__18MagLifePCModeRopedR9MagLifePC(int arg0, int arg1)
{
    int temp_v1;
    int var_s0;

    temp_v1 = (*(int *)(int *)((char *)(arg1) + 0x54));
    var_s0 = 0;
    switch (temp_v1) {                              
    case 1:
        var_s0 = 0x74;
        break;
    case 3:
        var_s0 = 0x79;
        break;
    default:
        X_ror_assert(D_002EAD28, 0x8C9, D_002EAD60);
        break;
    }
    X_func_0011A320(arg1, var_s0, -1);
}


extern "C" void live__18MagLifePCModeRopedR9MagLifePC(int arg0, int arg1)
{
    X_func_0011BE00(arg1);
    X_func_001207A8(arg0, arg1);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", pad__18MagLifePCModeRopedR9MagLifePCRC6BedPad);

extern "C" void init__19MagLifePCModeReloadR9MagLifePC(int arg0, int arg1)
{
    X_func_0011DFD0(arg1);
    X_func_0011A320(arg1, 4, -1);
    X_func_0011D06C(arg1);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__19MagLifePCModeReloadR9MagLifePC);

extern "C" void init__16MagLifePCModeHugR9MagLifePC(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg1) + 0x8)) = 0;
    X_func_0011A320(arg1, 5, -1);
    (*(int *)(int *)((char *)(arg1) + 0xEC)) = 0;
    (*(int *)(int *)((char *)(arg1) + 0xE0)) = 0;
    X_func_0012B788((*(int *)(int *)((char *)(arg1) + 0x20)) + 0x2BD20, 0U);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__16MagLifePCModeHugR9MagLifePC);
