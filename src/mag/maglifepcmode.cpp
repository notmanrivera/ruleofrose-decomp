#include "include_asm.h"
#include "mag/maglifepc.h"
#include "mag/magscene.h"
extern "C" int func_0011CE50(MagLifePC *);
extern "C" int func_0011AF04(MagLifePC *);

extern "C" void X_func_001026B0(int, int, int) asm("func_001026B0");
extern "C" float X_func_0010DA18__8DogActor(DogActor *) asm("func_0010DA18__8DogActor");
extern "C" int Xii_func_0011A054(MagLifePC *) asm("func_0011A054");
extern "C" void Xiiis_func_0011A320(MagLifePC *, int, short) asm("func_0011A320");
extern "C" void X_func_0011AF30(MagLifePC *, int, int) asm("func_0011AF30");
extern "C" float X_func_0011B128(MagLifePC *) asm("func_0011B128");
extern "C" void X_func_0011BDC0(MagLifePC *) asm("func_0011BDC0");
extern "C" void X_func_0011BE00(MagLifePC *) asm("func_0011BE00");
extern "C" int Xiiiui_func_0011C1E8(MagLifePC *, int, unsigned int, int) asm("func_0011C1E8");
extern "C" void X_func_0011D06C(MagLifePC *) asm("func_0011D06C");
extern "C" void X_func_0011DF7C(MagLifePC *) asm("func_0011DF7C");
extern "C" void X_func_0011DFD0(MagLifePC *) asm("func_0011DFD0");
extern "C" void X_func_0011EE00(MagLifePC *, int) asm("func_0011EE00");
extern "C" void X_func_0011FF10(MagLifePC *, const BedPad *) asm("func_0011FF10");
extern "C" void X_func_001207A8(...) asm("func_001207A8");
extern "C" void X_func_00120DEC(...) asm("func_00120DEC");
extern "C" void X_func_0012B788(void *, unsigned int) asm("func_0012B788");
extern "C" int X_func_0012C31C(MagLifePC *, int) asm("func_0012C31C");
extern "C" void X_ror_assert(const char *, int, const char *) asm("ror_assert");
extern const char D_002EAD28[];
extern const char D_002EAD60[];

extern "C" void func_00120788(MagLifePCMode *arg0, MagLifePC *arg1, int arg2)
{
    X_func_0011EE00(arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", func_001207A8);

extern "C" void live__13MagLifePCModeR9MagLifePC(MagLifePCMode *arg0, MagLifePC *arg1)
{
    X_func_001207A8();
    if (Xii_func_0011A054(arg1) != 0) {
        Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeNullR9MagLifePC);

extern "C" void live__17MagLifePCModeNullR9MagLifePC(MagLifePCModeNull *arg0, MagLifePC *arg1)
{
    if (arg1->m_actor != 0) {
        Xiiiui_func_0011C1E8(arg1, 1, 0, 0);
    }
}

// NON_MATCHING: 17/30 differ, 4 relocs differ (size 0x78, game 0x74), 3 edits
#ifdef NON_MATCHING
extern "C" void func_0011DFF8(MagLifePC *, int);
extern const int D_002EAD00[];
extern const int D_002EAD10[];
extern "C" void init__17MagLifePCModeWaitR9MagLifePC(MagLifePCModeWait *arg0, MagLifePC *arg1)
{
    int var_a1;
    int a1 = arg1->m_unkEC;
    int v1 = arg1->m_unkE4;
    if (a1 == 2) {
        if (v1 < 3) {
            a1 = v1;
        }
        var_a1 = D_002EAD00[a1];
    } else {
        var_a1 = D_002EAD10[v1];
    }
    Xiiis_func_0011A320(arg1, var_a1, -1);
    func_0011DFF8(arg1, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeWaitR9MagLifePC);
#endif

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", func_00120A54);

extern "C" void live__17MagLifePCModeWaitR9MagLifePC(MagLifePCModeWait *arg0, MagLifePC *arg1)
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

extern "C" void MagLifePCModeRun2D__vfunc_01(MagLifePCModeRun2D *arg0, MagLifePC *arg1)
{
    if (arg1->m_unkEC == 0) {
        return Xiiis_func_0011A320(arg1, 0x2F, -1);
    }
    Xiiis_func_0011A320(arg1, 0x31, -1);
}

extern "C" void func_001211AC()
{
    X_func_00120DEC();
}

extern "C" void MagLifePCModeRun2D__vfunc_02(MagLifePCModeRun2D *arg0, MagLifePC *arg1)
{
    X_func_0011BDC0(arg1);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeRun2D__vfunc_03);

extern "C" void MagLifePCModeTurn__vfunc_01(MagLifePCModeTurn *arg0, MagLifePC *arg1)
{
    if (arg1->m_unkEC == 0) {
        Xiiis_func_0011A320(arg1, 0x32, -1);
    } else if (arg1->m_unkEC == 1) {
        Xiiis_func_0011A320(arg1, 0x34, -1);
    } else if (arg1->m_unkEC == 2) {
        Xiiis_func_0011A320(arg1, 0x36, -1);
    }
    arg0->m_unk04 = X_func_0011B128(arg1);
}

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

extern "C" float func_00121604(float fparg0)
{
    if ((fparg0 <= -1.5707963f) || (fparg0 > 1.5707963f)) {
        return 0.0f;
    }
    if ((fparg0 <= 0.05f) && (fparg0 >= -0.05f)) {
        return 0.0f;
    }
    if (fparg0 < 0.0f) {
        return -0.1f;
    }
    return 0.1f;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__22MagLifePCModeAtkWait2DR9MagLifePC);

extern "C" int pad__22MagLifePCModeAtkWait2DR9MagLifePCRC6BedPad(MagLifePCModeAtkWait2D *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    if (arg1->m_actor->func_0010D9EC() < 0.0f) {
        X_func_001207A8(arg0, arg1);
        return 0;
    }
    if (arg1->m_unkDC == 0) {
        Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
        return 2;
    }
    if (arg1->m_unk104 > 0.0f) {
        Xiiiui_func_0011C1E8(arg1, 6, 0, 0);
        return 2;
    }
    X_func_001207A8(arg0, arg1);
    return 0;
}

extern "C" void MagLifePCModeAtkMove2D__vfunc_01(MagLifePCModeAtkMove2D *arg0, MagLifePC *arg1)
{
    X_func_0011DF7C(arg1);
    arg1->m_unkF4 = -1;
}

extern "C" void func_00121888(void) {
}

extern "C" void MagLifePCModeAtkMove2D__vfunc_02(void) {
}

extern "C" int MagLifePCModeAtkMove2D__vfunc_03(MagLifePCModeAtkMove2D *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    if (arg1->m_unkDC == 0) {
        Xiiiui_func_0011C1E8(arg1, 1, 0, 0);
        return 2;
    }
    if (!(arg1->m_unk104 > 0.0f)) {
        Xiiiui_func_0011C1E8(arg1, 5, 0, 0);
        return 2;
    }
    X_func_0011FF10(arg1, arg2);
    return 0;
}

extern "C" void MagLifePCModeAttacking__vfunc_01(MagLifePCModeAttacking *arg0, MagLifePC *arg1)
{
    arg0->m_unk04 = 0;
    arg0->m_unk08 = 0;
    arg0->m_unk0C = X_func_0012C31C(arg1, 0);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeAttacking__vfunc_02);

static inline int attackingCross_121C64(unsigned int buttons)
{
    return (buttons >> BEDPAD_BIT_CROSS) & 1;
}
extern "C" int MagLifePCModeAttacking__vfunc_03(MagLifePCModeAttacking *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    if (attackingCross_121C64(arg2->m_trigger)) {
        if ((unsigned short)((arg2->m_press >> BEDPAD_BIT_R1) & 1)) {
            if (X_func_0010DA18__8DogActor(arg1->m_actor) >= 0.7f) {
                arg0->m_unk08 = 1;
            }
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__19MagLifePCModeDamageR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__19MagLifePCModeDamageR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeItemR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__17MagLifePCModeItemR9MagLifePC);

extern "C" void init__18MagLifePCModeDogGoR9MagLifePC(MagLifePCModeDogGo *arg0, MagLifePC *arg1)
{
    int v = func_0011AF04(arg1);
    int mot = 0xF;
    if (arg1->m_unk54 == 3) {
        mot = 0x7E;
    } else if (v != 0) {
        mot = 0x12;
    } else if (arg1->m_unkE4 == 2) {
        mot = 0x15;
    }
    Xiiis_func_0011A320(arg1, mot, -1);
    X_func_0011AF30(arg1, 0xF, 1);
    arg1->m_unk08 = 1;
}

extern "C" void live__18MagLifePCModeDogGoR9MagLifePC(MagLifePCModeDogGo *arg0, MagLifePC *arg1)
{
    int s1 = arg1->m_unk08;
    int v1 = Xii_func_0011A054(arg1);
    if (s1 == 1) {
        if (v1 != 0) {
            X_func_0011AF30(arg1, 0xF, 2);
            Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
        }
    } else if (s1 == 2) {
        if (v1 != 0) {
            Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__20MagLifePCModeDogComeR9MagLifePC);

extern "C" void live__20MagLifePCModeDogComeR9MagLifePC(MagLifePCModeDogCome *arg0, MagLifePC *arg1)
{
    if (((unsigned int) (arg1->m_unk08 - 1) < 2U) && (Xii_func_0011A054(arg1) != 0)) {
        X_func_0011AF30(arg1, 0x10, 2);
        Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
    }
}

extern "C" void init__20MagLifePCModeDogStayR9MagLifePC(MagLifePCModeDogStay *arg0, MagLifePC *arg1)
{
    X_func_0011AF30(arg1, 0x11, 3);
    int v = func_0011AF04(arg1);
    int mot = 0x11;
    if (arg1->m_unk54 == 3) {
        mot = 0x80;
    } else if (v != 0) {
        mot = 0x14;
    } else if (arg1->m_unkE4 == 2) {
        mot = 0x17;
    }
    Xiiis_func_0011A320(arg1, mot, -1);
    arg1->m_unk08 = 1;
}

extern "C" void live__20MagLifePCModeDogStayR9MagLifePC(MagLifePCModeDogStay *arg0, MagLifePC *arg1)
{
    int s1 = arg1->m_unk08;
    int v1 = Xii_func_0011A054(arg1);
    if (s1 == 1) {
        if (v1 != 0) {
            Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
        }
    } else if (s1 == 2) {
        if (v1 != 0) {
            Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
        }
    }
}

extern "C" void init__17MagLifePCModeHoldR9MagLifePC(MagLifePCModeHold *arg0, MagLifePC *arg1)
{
    arg1->m_unkEC = 0;
    arg1->m_unkE0 = 0;
    X_func_0011DFD0(arg1);
    Xiiis_func_0011A320(arg1, 0xA, -1);
    arg1->m_unk08 = 0;
}

extern "C" int pad__17MagLifePCModeHoldR9MagLifePCRC6BedPad(MagLifePCModeHold *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    int temp_s2;
    int temp_v1;

    temp_s2 = arg1->m_unk08;
    temp_v1 = Xii_func_0011A054(arg1);
    if (arg2->m_dirCount >= 0x10) {
        Xiiiui_func_0011C1E8(arg1, 0xC, 0U, 0);
        return 2;
    }
    if (temp_s2 == 0) {
        if (!(arg1->m_unk104 > 0.0f)) {
            Xiiis_func_0011A320(arg1, 0xA, -1);
            goto block_8;
        }
        Xiiis_func_0011A320(arg1, 0xC, -1);
        arg1->m_unk08 = 1;
        return 1;
    }
    if (temp_v1 != 0) {
        Xiiis_func_0011A320(arg1, 0xA, -1);
        arg1->m_unk08 = 0;
    }
block_8:
    return 1;
}

extern "C" void init__23MagLifePCModeHoldAttackR9MagLifePC(MagLifePCModeHoldAttack *arg0, MagLifePC *arg1)
{
    Xiiis_func_0011A320(arg1, 0xD, -1);
    X_func_001026B0(0x2E, 0, 0);
}

extern "C" void init__19MagLifePCModeUnholdR9MagLifePC(MagLifePCModeUnhold *arg0, MagLifePC *arg1)
{
    Xiiis_func_0011A320(arg1, 0xE, -1);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeRideR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__17MagLifePCModeRideR9MagLifePC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", pad__17MagLifePCModeRideR9MagLifePCRC6BedPad);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", func_00122C9C);

extern "C" void init__18MagLifePCModeRopedR9MagLifePC(MagLifePCModeRoped *arg0, MagLifePC *arg1)
{
    int var_s0 = 0;
    switch (arg1->m_unk54) {
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
    Xiiis_func_0011A320(arg1, var_s0, -1);
}

extern "C" void live__18MagLifePCModeRopedR9MagLifePC(MagLifePCModeRoped *arg0, MagLifePC *arg1)
{
    X_func_0011BE00(arg1);
    X_func_001207A8(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", pad__18MagLifePCModeRopedR9MagLifePCRC6BedPad);

extern "C" void init__19MagLifePCModeReloadR9MagLifePC(MagLifePCModeReload *arg0, MagLifePC *arg1)
{
    X_func_0011DFD0(arg1);
    Xiiis_func_0011A320(arg1, 4, -1);
    X_func_0011D06C(arg1);
}

extern "C" void live__19MagLifePCModeReloadR9MagLifePC(MagLifePCModeReload *arg0, MagLifePC *arg1)
{
    if (Xii_func_0011A054(arg1) != 0) {
        int id = func_0011CE50(arg1);
        if ((unsigned int)id < MAG_MAX_ACTOR) {
            DogActor *actor = arg1->m_scene->getActor(id);
            actor->func_0010B1B0(actor->func_0010AA5C("wait2"), 1, 0.016666694f, -1, -1);
        }
        Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
    }
}

extern "C" void init__16MagLifePCModeHugR9MagLifePC(MagLifePCModeHug *arg0, MagLifePC *arg1)
{
    arg1->m_unk08 = 0;
    Xiiis_func_0011A320(arg1, 5, -1);
    arg1->m_unkEC = 0;
    arg1->m_unkE0 = 0;
    X_func_0012B788((char *)arg1->m_scene + 0x2BD20, 0U);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__16MagLifePCModeHugR9MagLifePC);
