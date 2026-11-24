#include "include_asm.h"
#include "mag/maglifepc.h"
#include "mag/magscene.h"
extern "C" int func_0012CA28(MagLifePC *arg0);
extern const int D_002EAD98[];
extern "C" int func_0011C64C(MagLifePC *, MagPCItemData *, int, float);
extern "C" int func_0011CBF4(MagLifePC *, int);
extern "C" int func_0011CC14(MagLifePC *, int);
extern "C" int func_0013F210(MagScene *, int, const int *, int);
extern "C" int func_0010423C(int theMin, int theMax);
extern "C" int func_001034B8();
extern "C" float func_0011D720(MagLifePC *);
void vecTurnY(float *, float);
extern "C" void func_00102AB8(DogVector *theOut, int theA);
extern "C" int func_0011BE30(MagLifePC *);
extern const int D_002EAD68[];
extern const int D_002EAD78[];
extern const int D_002EAD88[];
extern "C" int func_0011A028(MagLifePC *);
extern "C" int func_0011CE50(MagLifePC *);
extern "C" int func_0011AF04(MagLifePC *);
extern "C" int func_0011B204(MagLifePC *, float, float);

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

extern "C" void func_00120788(MagLifePCMode *arg0, MagLifePC *arg1, DogVector *arg2, float arg3, float arg4)
{
    X_func_0011EE00(arg1, (int)arg2);
}

extern "C" void func_001207A8(MagLifePCMode *arg0, MagLifePC *arg1)
{
    DogActor *actor = arg1->m_actor;
    DogVector move;
    float rot = 0.0f;
    float turn = rot;
    if (actor->func_0010DB18() < 0) {
        float t = actor->func_0010DA4C();
        if (t >= 0.0f) {
            DogVector abs;
            float dt = func_0011D720(arg1);
            actor->func_00109348(t * 2.0f, (t + dt) * 2.0f, move, &turn, &abs);
            rot = abs.m_y;
        }
    }
    move.m_w = 1.0f;
    vecTurnY(&move.m_x, actor->m_unk50.m_y);
    func_00120788(arg0, arg1, &move, rot, turn);
}

extern "C" void live__13MagLifePCModeR9MagLifePC(MagLifePCMode *arg0, MagLifePC *arg1)
{
    X_func_001207A8();
    if (Xii_func_0011A054(arg1) != 0) {
        Xiiiui_func_0011C1E8(arg1, 0, 0, 0);
    }
}

// NON_MATCHING: 3/44 differ, 1 reloc differs, 3 edits
#ifdef NON_MATCHING
extern "C" void init__17MagLifePCModeNullR9MagLifePC(MagLifePCModeNull *arg0, MagLifePC *arg1)
{
    if (arg1->m_actor != 0) {
        int var_a1 = arg1->m_unkDC;
        unsigned int var_a2;
        if (arg1->m_unk54 == 1 || arg1->m_unk54 == 3) {
            var_a1 = 7;
            var_a2 = 0;
            goto set_mode;
        }
        var_a2 = 0;
        if (arg1->m_mode_hold.m_unk04 != 0) {
            var_a1 = 8;
            goto set_mode;
        }
        var_a2 = 3;
        if (arg1->m_mode_ride.m_unk04 != 0) {
            var_a1 = 9;
            goto set_mode;
        }
        if (var_a1 != 0) {
            var_a1 = 5;
            var_a2 = 0;
            goto set_mode;
        }
        if (arg1->m_last0 == 0xE) {
            var_a1 = 0xE;
            var_a2 = 0x11;
        set_mode:
            Xiiiui_func_0011C1E8(arg1, var_a1, var_a2, 0);
        } else {
            Xiiiui_func_0011C1E8(arg1, 1, 0, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", init__17MagLifePCModeNullR9MagLifePC);
#endif

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

extern "C" void func_00120A54(MagLifePCModeWait *arg0, MagLifePC *arg1)
{
    int cur = arg1->m_unkE4;
    int prev = arg1->m_unkF0;
    if (prev != cur) {
        if (prev == 1 && cur == 0) {
            Xiiis_func_0011A320(arg1, 8, -1);
        } else {
            Xiiis_func_0011A320(arg1, 0, -1);
        }
    }
    if (cur == 0 && (arg1->m_unk130 + 1) % 5400 == 0) {
        unsigned int r = func_0010423C(0, 7);
        if (r < 5U) {
            if (r != 4) {
                Xiiis_func_0011A320(arg1, r + 0x9F, -1);
                return;
            }
            DogVector pos;
            arg1->func_00119F88(&pos);
            if (func_001034B8() == 0x35 && pos.m_x >= 1000.0f) {
                Xiiis_func_0011A320(arg1, 0xA3, -1);
                return;
            }
            Xiiis_func_0011A320(arg1, func_0010423C(0, 3) + 0x9F, -1);
        }
    }
}

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

extern "C" void MagLifePCModeWalk2D__vfunc_01(MagLifePCModeWalk2D *arg0, MagLifePC *arg1)
{
    int e4 = arg1->m_unkE4;
    int ec = arg1->m_unkEC;
    if (e4 >= 3) {
        e4 = 2;
    }
    int r = func_0011BE30(arg1);
    int *last = &arg1->m_last0;
    if (r != 0 || ec == 2 || *last == 4) {
        return Xiiis_func_0011A320(arg1, D_002EAD68[e4], -1);
    }
    if (ec == 0) {
        return Xiiis_func_0011A320(arg1, D_002EAD78[e4], -1);
    }
    Xiiis_func_0011A320(arg1, D_002EAD88[e4], -1);
}

extern "C" void func_00121054(MagLifePCModeWalk2D *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    X_func_00120DEC(arg0, arg1, arg2);
}

extern "C" void MagLifePCModeWalk2D__vfunc_02(void) {
}

extern "C" int MagLifePCModeWalk2D__vfunc_03(MagLifePCModeWalk2D *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    if (arg1->m_unkDC != 0) {
        Xiiiui_func_0011C1E8(arg1, 5, 0U, 0);
        return 2;
    }
    if (arg1->m_unk104 > 0.0f) {
        int r = func_0011B204(arg1, arg1->m_actor->m_unk50.m_y, X_func_0011B128(arg1));
        int e4 = arg1->m_unkE4;
        if (r == 0 && e4 < 2) {
            Xiiiui_func_0011C1E8(arg1, 4, 0U, 0);
            return 2;
        }
        if (arg1->m_unkE0 == 2) {
            Xiiiui_func_0011C1E8(arg1, 3, 0U, 0);
            return 2;
        }
        func_00121054(arg0, arg1, arg2);
        return 1;
    }
    Xiiiui_func_0011C1E8(arg1, 1, 0U, 0);
    return 0;
}

extern "C" void MagLifePCModeRun2D__vfunc_01(MagLifePCModeRun2D *arg0, MagLifePC *arg1)
{
    if (arg1->m_unkEC == 0) {
        return Xiiis_func_0011A320(arg1, 0x2F, -1);
    }
    Xiiis_func_0011A320(arg1, 0x31, -1);
}

extern "C" void func_001211AC(MagLifePCModeRun2D *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    X_func_00120DEC(arg0, arg1, arg2);
}

extern "C" void MagLifePCModeRun2D__vfunc_02(MagLifePCModeRun2D *arg0, MagLifePC *arg1)
{
    X_func_0011BDC0(arg1);
}

// NON_MATCHING: 26/58 differ, 3 relocs differ (size 0xE8, game 0xE4), 14 edits
#ifdef NON_MATCHING
extern "C" int MagLifePCModeRun2D__vfunc_03(MagLifePCModeRun2D *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    if (arg1->m_unkDC != 0) {
        Xiiiui_func_0011C1E8(arg1, 5, 0U, 0);
        return 2;
    }
    if (arg1->m_unk104 > 0.0f) {
        if (func_0011B204(arg1, arg1->m_actor->m_unk50.m_y, X_func_0011B128(arg1)) != 0) {
            if (arg1->m_unkE0 == 1) {
                Xiiiui_func_0011C1E8(arg1, 2, 0U, 0);
                return 2;
            }
            func_001211AC(arg0, arg1, arg2);
            return 1;
        }
        Xiiiui_func_0011C1E8(arg1, 4, 0U, 0);
        return 2;
    }
    Xiiiui_func_0011C1E8(arg1, 1, 0U, 0);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", MagLifePCModeRun2D__vfunc_03);
#endif

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

extern "C" void func_00121348(MagLifePCModeTurn *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    X_func_001207A8(arg0, arg1, arg2);
}

extern "C" void MagLifePCModeTurn__vfunc_02(void) {
}

extern "C" int MagLifePCModeTurn__vfunc_03(MagLifePCModeTurn *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    float diff = X_func_0011B128(arg1) - arg0->m_unk04;
    if (diff < -DOG_PI) {
        diff += DOG_PI2;
    } else if (diff >= DOG_PI) {
        diff -= DOG_PI2;
    }
    float limit = DOG_PI * 0.1f;
    int ok = 0;
    if (-limit <= diff && diff < limit) {
        ok = 1;
    }
    if (Xii_func_0011A054(arg1) != 0 || !ok) {
        int e0 = arg1->m_unkE0;
        if (e0 == 1) {
            Xiiiui_func_0011C1E8(arg1, 2, 0U, 0);
            return 2;
        }
        if (e0 == 2) {
            Xiiiui_func_0011C1E8(arg1, 3, 0U, 0);
            return 2;
        }
        Xiiiui_func_0011C1E8(arg1, 1, 0U, 0);
        return 0;
    }
    func_00121348(arg0, arg1, arg2);
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD68);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD78);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD88);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmode", D_002EAD98);

extern "C" void init__22MagLifePCModeAtkWait2DR9MagLifePC(MagLifePCModeAtkWait2D *arg0, MagLifePC *arg1)
{
    int *last = &arg1->m_last0;
    int hhh = func_0012CA28(arg1);
    if (hhh < 0) {
        arg1->m_target_id = 0;
        hhh = 0;
    }
    if (!(0 <= hhh && hhh < 5)) {
        X_ror_assert(D_002EAD28, 0x34C, "0 <= hhh && hhh < 5");
    }
    int wc = arg1->m_unk21C;
    if (!(0 <= wc && wc < 4)) {
        X_ror_assert(D_002EAD28, 0x34E, "0 <= wc && wc < 4");
    }
    if (arg1->m_unkE4 == 2) {
        wc += 4;
    }
    if (*last == 0xA || *last == 0xF || *last == 0x10 || *last == 0x11 || *last == 6) {
        arg1->func_0011A27C(D_002EAD98[wc * 5 + hhh], -1);
    } else {
        Xiiis_func_0011A320(arg1, D_002EAD98[wc * 5 + hhh], -1);
    }
    X_func_0011DFD0(arg1);
    arg1->m_unk08 = 0;
}

extern "C" float func_00121604(MagLifePCModeAtkWait2D *arg0, float fparg0)
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

// NON_MATCHING: 44/72 differ, 1 reloc differs (size 0x120, game 0x11C), 14 edits
#ifdef NON_MATCHING
extern "C" float func_0011CE5C(MagLifePC *self, DogVector *theOut, int theId, int theFlag);
extern "C" float func_0012BEDC(MagLifePC *arg0, float *theYaw, float *thePitch, const DogVector *thePos);
extern "C" void live__22MagLifePCModeAtkWait2DR9MagLifePC(MagLifePCModeAtkWait2D *arg0, MagLifePC *arg1)
{
    if (arg1->m_unk08 == 0) {
        register int target PS2_REG("$6") = arg1->m_target_id;
        register float turn PS2_REG("$f12");
        if (target == 0) {
            goto block_5;
        }
        {
            DogVector pos;
            float yaw;
            float pitch;
            func_0011CE5C(arg1, &pos, target, 0);
            turn = func_00121604(arg0, func_0012BEDC(arg1, &yaw, &pitch, &pos));
        }
        if (turn == 0.0f) {
        block_5:
            arg1->m_unk08 = 1;
            return;
        }
        arg1->m_actor->addRotY(turn);
        arg1->m_actor->func_0010E7DC(turn);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmode", live__22MagLifePCModeAtkWait2DR9MagLifePC);
#endif

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

extern "C" void live__19MagLifePCModeDamageR9MagLifePC(MagLifePCModeDamage *arg0, MagLifePC *arg1)
{
    X_func_001207A8(arg0, arg1);
    if (Xii_func_0011A054(arg1) != 0) {
        int dc = arg1->m_unkDC;
        if (arg1->m_unk54 == 1 || arg1->m_unk54 == 3) {
            Xiiiui_func_0011C1E8(arg1, 7, 0U, 0);
            return;
        }
        if (arg1->m_mode_hold.m_unk04 != 0) {
            Xiiiui_func_0011C1E8(arg1, 8, 0U, 0);
            return;
        }
        if (arg1->m_mode_ride.m_unk04 != 0) {
            Xiiiui_func_0011C1E8(arg1, 9, 3U, 0);
            return;
        }
        if (dc != 0) {
            Xiiiui_func_0011C1E8(arg1, 5, 0U, 0);
            return;
        }
        Xiiiui_func_0011C1E8(arg1, 1, 0U, 0);
        return;
    } else if (arg1->m_actor != 0 && arg1->m_actor->getMotionNo() < 2) {
        Xiiiui_func_0011C1E8(arg1, 1, 0U, 0);
    }
}

extern "C" void init__17MagLifePCModeItemR9MagLifePC(MagLifePCModeItem *arg0, MagLifePC *arg1)
{
    int oid = arg1->m_unk08;
    if (oid == 0) {
        X_ror_assert(D_002EAD28, 0x5CE, "oid != 0");
    }
    DogVector pos;
    func_00102AB8(&pos, oid);
    DogActor *actor = arg1->m_actor;
    if (actor == 0) {
        X_ror_assert(D_002EAD28, 0x5D4, "actor != __null");
    }
    DogVector actor_pos = actor->m_unk40;
    float dy = -(pos.m_y - actor_pos.m_y);
    int mot;
    if (dy < 50.0f) {
        mot = 0x81;
    } else if (dy < 100.0f) {
        mot = 0x83;
    } else if (dy < 160.0f) {
        mot = 0x85;
    } else {
        mot = 0x87;
    }
    arg1->m_unk0C = mot;
    Xiiis_func_0011A320(arg1, mot, -1);
}

extern "C" void live__17MagLifePCModeItemR9MagLifePC(MagLifePCModeItem *arg0, MagLifePC *arg1)
{
    int end = Xii_func_0011A054(arg1);
    int &mot = arg1->m_unk0C;
    MagScene *scene = arg1->m_scene;
    if (((mot - 0x81) & 1) == 0) {
        if (end != 0) {
            mot = mot + 1;
            Xiiis_func_0011A320(arg1, mot, -1);
            MagPCItemData itemdata[10];
            if (func_0011C64C(arg1, itemdata, 10, 50.0f) > 0) {
                if (func_0011CBF4(arg1, itemdata[0].m_obj_id) != 0) {
                    X_func_001026B0(3, 0, 0);
                    func_0011CC14(arg1, itemdata[0].m_obj_id);
                    int param[16];
                    param[0] = itemdata[0].m_unk14[0];
                    if (param[0] == 0xA64) {
                        func_0013F210(scene, 0x11, param, 1);
                        return;
                    }
                    scene->func_0013F280(0x11, param, 1);
                    return;
                }
                scene->func_0013F280(0x12, 0, 1);
            }
        }
    } else if (end != 0) {
        Xiiiui_func_0011C1E8(arg1, 1, 0U, 0);
    }
}

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

extern "C" void live__17MagLifePCModeRideR9MagLifePC(MagLifePCModeRide *arg0, MagLifePC *arg1)
{
    X_func_001207A8(arg0, arg1);
    int &flag = arg1->m_unk0C;
    if (flag >= 2) {
        if (Xii_func_0011A054(arg1) != 0) {
            Xiiiui_func_0011C1E8(arg1, 0, 0U, 0);
        }
    } else if (flag > 0 && Xii_func_0011A054(arg1) != 0) {
        if (arg0->m_unk08 == 1) {
            Xiiis_func_0011A320(arg1, 0x8A, -1);
        } else if (arg0->m_unk08 == 2) {
            Xiiis_func_0011A320(arg1, 0x91, -1);
        } else if (arg0->m_unk08 == 3) {
            Xiiis_func_0011A320(arg1, 0x98, -1);
        } else if (arg0->m_unk08 == 4) {
            Xiiis_func_0011A320(arg1, 0x9C, -1);
        }
        flag = 0;
    }
}

extern "C" int pad__17MagLifePCModeRideR9MagLifePCRC6BedPad(MagLifePCModeRide *arg0, MagLifePC *arg1, const BedPad *arg2)
{
    int &flag = arg1->m_unk0C;
    if (flag <= 0 && arg1->m_unk104 > 0.0f) {
        int mot = func_0011A028(arg1);
        if ((unsigned int)(mot - 0x8A) < 4U) {
            Xiiis_func_0011A320(arg1, 0x8E, -1);
            flag |= 1;
        } else if ((unsigned int)(mot - 0x91) < 2U) {
            Xiiis_func_0011A320(arg1, 0x93, -1);
            flag |= 1;
        } else if (mot == 0x98) {
            Xiiis_func_0011A320(arg1, 0x99, -1);
            flag |= 1;
        } else if (mot == 0x9C) {
            Xiiis_func_0011A320(arg1, 0x9D, -1);
            flag |= 1;
        }
    }
    return 1;
}

extern "C" void func_00122C9C(MagLifePCModeRide *arg0, MagLifePC *arg1, int arg2)
{
    int &step = arg1->m_unk08;
    int &flag = arg1->m_unk0C;
    if (flag < 2) {
        step = arg2;
        switch (arg2) {
        case 6:
            Xiiis_func_0011A320(arg1, 0x8F, -1);
            flag = 2;
            arg0->m_unk04 = 0;
            return;
        case 9:
            Xiiis_func_0011A320(arg1, 0x94, -1);
            flag = 2;
            arg0->m_unk04 = 0;
            return;
        case 11:
            Xiiis_func_0011A320(arg1, 0x9A, -1);
            flag = 2;
            arg0->m_unk04 = 0;
            return;
        case 13:
            Xiiis_func_0011A320(arg1, 0x9E, -1);
            flag = 2;
            arg0->m_unk04 = 0;
            return;
        default:
            X_ror_assert(D_002EAD28, 0x8B1, D_002EAD60);
            break;
        }
    }
}

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
