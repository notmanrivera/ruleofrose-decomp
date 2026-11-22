#include "include_asm.h"
#include "emy/emy.h"

struct FshVtblEntry {
    short m_delta;
    short m_pad;
    int m_fn;
};

struct FshStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[0xA];
    signed char *m_table;
};

struct FshActorPtr {
    unsigned char m_pad00[0x100];
    void *m_objStat100;
};

struct FshWrdGlobal {
    unsigned char m_pad00[0x22090];
    FshActorPtr *m_unk22090;
};

struct FshGlobalB {
    int m_unk00[0x33];
    int m_killCounts[1];                // +0xCC
};

struct FshObjStatView {
    unsigned char m_pad00[0x120];
    int m_flags;                        // +0x120
    unsigned char m_pad124[0x18];
    int m_unk13C;                       // +0x13C
    unsigned char m_pad140[0x2AC];
    int m_partsFlags;                   // +0x3EC
};

struct FshMain : EmyMain {
    unsigned char m_pad204[0x54];       // +0x204..+0x257
    signed char m_unk258;               // +0x258
    signed char m_unk259;               // +0x259
    unsigned char m_pad25A[2];          // +0x25A..+0x25B
};
STATIC_ASSERT(sizeof(FshMain) == 0x25C, FshMain_size);

struct FshOutDisappear : EmyOut {
};

struct FshOutAppear : EmyOut {
};

struct FshOutAtk : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    unsigned short m_unk40;             // +0x40
    unsigned short m_unk42;             // +0x42
    unsigned char m_pad44[0x10];        // +0x44..+0x53
    int m_unk54;                        // +0x54
    int m_unk58;                        // +0x58
};
STATIC_ASSERT(sizeof(FshOutAtk) == 0x5C, FshOutAtk_size);

struct FshOutWait : EmyOut {
};

struct FshOutWalk : EmyOut {
    int m_unk38;                        // +0x38
};
STATIC_ASSERT(sizeof(FshOutWalk) == 0x3C, FshOutWalk_size);

struct FshOutSerch : EmyOut {
};

struct FshOutRound : EmyOut {
};

struct FshOutStared : EmyOut {
    unsigned short m_unk38;             // +0x38
    unsigned short m_unk3A;             // +0x3A
    int m_unk3C;                        // +0x3C
};
STATIC_ASSERT(sizeof(FshOutStared) == 0x40, FshOutStared_size);

struct FshOutCollision : EmyOut {
};

struct FshOutWin : EmyOut {
    float m_unk38;                      // +0x38
};
STATIC_ASSERT(sizeof(FshOutWin) == 0x3C, FshOutWin_size);

struct FshOutTest : EmyOut {
};

struct FshOutDead : EmyOut {
    int m_unk38;                        // +0x38
};
STATIC_ASSERT(sizeof(FshOutDead) == 0x3C, FshOutDead_size);

extern int vtbl_FshMain asm("_vt$7FshMain");

extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_EmyMain__vfunc_01(EmyMain *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" float X_func_001044B8(float, float) asm("func_001044B8");
extern "C" int X_func_00118FEC(void *) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_001442A4(void) asm("func_001442A4");
extern "C" int X_func_00157230(FshOutAtk *, int, void *) asm("func_00157230");
extern "C" int X_func_00165280(FshMain *, void *) asm("func_00165280");
extern "C" int X_func_00165398(EmyMain *, int, int, int) asm("func_00165398");
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00165794(...) asm("func_00165794");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D38(...) asm("func_00165D38");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" int X_func_00166004(...) asm("func_00166004");
extern "C" int X_func_00166108(...) asm("func_00166108");
extern "C" int X_func_00166178(...) asm("func_00166178");
extern "C" int X_func_00166198(...) asm("func_00166198");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" int X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" int X_func_00167230(EmyOut *, int, float) asm("func_00167230");
extern "C" int X_func_001679B4(EmyOut *, int, int, float, float) asm("func_001679B4");
extern "C" int X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" int X_func_001682B0(...) asm("func_001682B0");
extern "C" int X_func_001689E8(EmyOut *) asm("func_001689E8");
extern "C" int X_func_001694CC(EmyOut *, int) asm("func_001694CC");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_00169A98(void *, void *, float) asm("func_00169A98");
extern "C" int X_func_0016A6B4(void *) asm("func_0016A6B4");
extern "C" int X_func_00180EEC(void *, int, int) asm("func_00180EEC");
extern "C" int X_func_001D10D0(void *, int, int) asm("func_001D10D0");
extern "C" int X_func_001D1410(void *, int, int) asm("func_001D1410");
extern "C" int X_func_001D19A8(void *, int) asm("func_001D19A8");
extern "C" int X_func_001D23F8(void *, int, int) asm("func_001D23F8");
extern "C" float X_func_001D4A3C(void *, int, int) asm("func_001D4A3C");
extern "C" int X_func_001DA740(void *, int, void *) asm("func_001DA740");
extern "C" int X_func_001FAC60(unsigned int, int, int, int, int, unsigned int, int) asm("func_001FAC60");
extern "C" int X_func_00202F10(void *) asm("func_00202F10");

extern int D_006E9840;
extern FshWrdGlobal D_007812C0;
extern FshActorPtr *D_007A3350;
extern FshActorPtr *D_007A3354;
extern FshGlobalB *D_007B205C;
extern int D_007B2580;
extern const int D_002F0BF8[];
extern const unsigned short D_002F0C78[];

extern "C" void FshMain__vfunc_01(FshMain *self, int flags)
{
    self->m_vtbl = &vtbl_FshMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return Xv___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", FshMain__vfunc_04);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0AF0);

extern "C" void FshMain__vfunc_05(FshMain *self)
{
    int next;
    int flags;
    int res;

    self->m_stateChanged = 0;
    flags = self->m_flags30;
    if (flags & 2) {
        self->m_curState = 4;
        ((EmyBrainView *)self->m_brain)->m_state = 4;
        self->m_stateChanged = 1;
        self->m_flags30 = 0;
    } else if ((next = self->m_nextState) != -1) {
        self->m_flags30 = 0;
        res = X_func_0016968C(self->m_brain, next);
        switch (res) {
            case 0:
            case 1:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                break;
            case 2:
                if (self->m_unk0C != 0) {
                    res = X_func_0016968C(self->m_brain, 0x14);
                }
                break;
        }
        self->m_unk258 = 0;
        self->m_unk259 = 0;
        if (res != 0) {
            self->m_curState = res;
            self->m_stateChanged = 1;
        } else {
            ((EmyBrainView *)self->m_brain)->m_state = self->m_curState;
        }
    } else if (flags & 1) {
        ((EmyBrainView *)self->m_brain)->m_state = self->m_curState;
        self->m_stateChanged = 1;
    }
    self->m_flags30 = 0;
}

extern "C" void FshMain__vfunc_06(FshMain *self)
{
    EmyOut *curOut;
    FshVtblEntry *vt;

    if (self->m_stateChanged != 0) {
        curOut = self->m_curOut;
        vt = (FshVtblEntry *)((char *)curOut->m_vtbl + 0x20);
        ((void (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
        vt = (FshVtblEntry *)((char *)self->m_vtbl + 0x10);
        ((void (*)(void *))vt->m_fn)((char *)self + vt->m_delta);
    }
    curOut = self->m_curOut;
    vt = (FshVtblEntry *)((char *)curOut->m_vtbl + 0x18);
    self->m_nextState = ((int (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
}

extern "C" int FshMain__vfunc_02(FshMain *self)
{
    int v;
    EmyOut *obj;
    FshVtblEntry *vt;
    register FshStateTable *tbl PS2_REG("$3");
    int count;
    register signed char *base PS2_REG("$7");
    register int v2 PS2_REG("$2");
    int i;
    int *dst;

    v = self->m_curState;
    if (v != 0) {
        if (v >= 0) {
            if (v < 0xD) {
                obj = ((EmyOut **)self->m_unk48)[v];
                self->m_curOut = obj;
                vt = (FshVtblEntry *)((char *)obj->m_vtbl + 0x10);
                ((void (*)(void *))vt->m_fn)((char *)obj + vt->m_delta);
            }
        }
    }
    i = 0;
    tbl = (FshStateTable *)self->m_unkE8;
    count = tbl->m_count;
    v2 = self->m_curState;
    base = tbl->m_table + (v2 * count);
    for (; i < count; i++) {
        dst = (int *)((char *)self + 4);
        if (base[i] != 0) {
            *(int *)((char *)(dst + i) + 0x200) = 1;
        } else {
            *(int *)((char *)(dst + i) + 0x200) = 0;
        }
    }
    return 0;
}

extern "C" int func_00156284(void)
{
    return X_func_00165734();
}

extern "C" int func_00156298(void)
{
    return X_func_00165794();
}

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", func_001562AC);

extern "C" int func_0015640C(FshMain *self)
{
    struct {
        char pad0[16];
        float sp10;
    } stack;
    float radius;
    int target;
    FshActorPtr *pc;

    X_func_00165280(self, &stack);
    X_func_0016A6B4(&stack.sp10);
    radius = X_func_001D4A3C(&D_007812C0, self->m_id, 0);
    pc = D_007812C0.m_unk22090;
    target = (pc != 0) ? (int)pc->m_objStat100 : 0;
    return X_func_00169A98(&stack, &stack.sp10, radius + X_func_001D4A3C(&D_007812C0, target, 0) + 10.0f);
}

extern "C" int func_001564C0(void)
{
    return X_func_00165A68();
}

extern "C" int func_001564D4(void)
{
    return X_func_00165AA8();
}

extern "C" int func_001564E8(void)
{
    return X_func_00165D38();
}

extern "C" int func_001564FC(void)
{
    return X_func_00165D7C();
}

extern "C" int func_00156510(void)
{
    return X_func_00166004();
}

extern "C" int func_00156524(void)
{
    return X_func_00166108();
}

extern "C" int func_00156538(void)
{
    return X_func_00166178();
}

extern "C" int func_0015654C(FshMain *self)
{
    int f = ((FshObjStatView *)self->m_objStat)->m_partsFlags;
    if (f & 8) {
        if (f & 0x10) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_00156578(FshMain *self)
{
    int f = ((FshObjStatView *)self->m_objStat)->m_partsFlags;
    if (f & 2) {
        if (f & 4) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_001565A4(FshMain *self)
{
    return ((FshObjStatView *)self->m_objStat)->m_partsFlags & 1;
}

extern "C" int func_001565B4(FshMain *self)
{
    int f = ((FshObjStatView *)self->m_objStat)->m_partsFlags;
    if (!(f & 2)) {
        if (!(f & 4)) {
            return 0;
        }
    }
    return 1;
}

extern "C" int func_001565E0(FshMain *self)
{
    int f = ((FshObjStatView *)self->m_objStat)->m_partsFlags;
    if (!(f & 8)) {
        if (!(f & 0x10)) {
            return 0;
        }
    }
    return 1;
}

extern "C" int func_0015660C(void)
{
    return X_func_00166198();
}

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", func_00156620);

extern "C" void FshOutDisappear__vfunc_02(FshOutDisappear *self)
{
    X_func_001D23F8(&D_007812C0, self->m_unk00, 1);
    X_func_001680A0(self, 0x16, 0x100);
    self->m_owner->m_unk0C = 0;
    X_func_001D1410(&D_007812C0, self->m_unk00, 0x40);
    X_func_001D10D0(&D_007812C0, self->m_unk00, 0x10000000);
    X_func_001D10D0(&D_007812C0, self->m_unk00, 0x400);
    self->m_unk04 = 0;
}

extern "C" void FshOutDisappear__vfunc_04(FshOutDisappear *self)
{
    X_func_001D23F8(&D_007812C0, self->m_unk00, 0);
    self->m_owner->m_unk0C = 1;
    X_func_001D10D0(&D_007812C0, self->m_unk00, 0x40);
    X_func_001D1410(&D_007812C0, self->m_unk00, 0x10000000);
    X_func_001D1410(&D_007812C0, self->m_unk00, 0x400);
    X_func_00166AD0(self);
}

extern "C" void FshOutAppear__vfunc_02(FshOutAppear *self)
{
    FshObjStatView *stat;

    self->m_owner->m_unk0C = 0;
    stat = (FshObjStatView *)self->m_unk08;
    stat->m_flags |= 0x400;
    self->m_unk04 = 0;
}

// NON_MATCHING: 21/48 differ (size 0xC0, game 0xCC), 13 edits. The state-1 path
// in the game keeps a dead second `beqz` on the check result and pre-loads the
// return value into $2, which gcc here folds away.
#ifdef NON_MATCHING
extern "C" int FshOutAppear__vfunc_03(FshOutAppear *self)
{
    int state;
    int ret;
    int res;

    state = self->m_unk04;
    ret = -1;
    switch (state) {
        case 0:
            X_func_001D23F8(&D_007812C0, self->m_unk00, 0);
            X_func_001680A0(self, 0x17, 0);
            self->m_unk04 = 1;
            break;
        case 1:
            res = X_func_001D19A8(&D_007812C0, self->m_unk00);
            if (res != 0) {
                self->m_owner->m_unk2C = state;
                if (res != 0) {
                    ret = 0x13;
                    self->m_owner->m_unk0C = state;
                    ((FshObjStatView *)self->m_unk08)->m_flags &= ~0x400;
                }
            }
            break;
        default:
            return -1;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/FshMain", FshOutAppear__vfunc_03);
#endif

extern "C" void FshOutAtk__vfunc_02(FshOutAtk *self)
{
    int val;
    int entry;

    self->m_unk38 = X_func_0010423C(0x32, 0x50);
    self->m_unk3C = 0;
    val = ((FshObjStatView *)self->m_unk08)->m_unk13C;
    if (val == 0x20 || val == 0x23 || val == 0x1C || val == 0x20 || val == 0x1E || val == 0x2A || val == 0x2B) {
        self->m_unk42 = 1;
        self->m_unk40 = 1;
    } else {
        self->m_unk42 = 0;
        self->m_unk40 = 0;
    }
    entry = D_002F0BF8[self->m_unk40];
    self->m_unk04 = 0;
    X_func_001680A0(self, entry, 0x100);
    self->m_unk54 = 0;
    self->m_unk58 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", FshOutAtk__vfunc_03);

extern "C" void FshOutAtk__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void func_001570FC(FshOutAtk *self)
{
    void *target;
    void *target2;

    if ((X_func_00118FEC(&D_006E9840) != 9) && (self->m_unk54 < 2)) {
        target = 0;
        if (D_007A3350 != 0) {
            target = D_007A3350->m_objStat100;
        }
        target2 = target;
        if (X_func_00157230(self, 0, target2) != 0) {
            self->m_unk54 = self->m_unk54 + 1;
            self->m_unk2C = X_func_001694CC(self, 0);
            X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x17, (unsigned int)target2, 0);
        }
    }
    if ((X_func_001442A4() == 0) && (self->m_unk58 < 2)) {
        target2 = 0;
        if (D_007A3354 != 0) {
            target2 = D_007A3354->m_objStat100;
        }
        if (X_func_00157230(self, 1, target2) != 0) {
            self->m_unk58 = self->m_unk58 + 1;
            self->m_unk2C = X_func_001694CC(self, 0);
            X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x17, (unsigned int)target2, 0);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0B78);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0B88);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0BA0);

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", func_00157230);

extern "C" void FshOutWait__vfunc_02(FshOutWait *self)
{
    X_func_001682B0();
    self->m_unk04 = 0;
}

extern "C" int FshOutWait__vfunc_03(void)
{
    return -1;
}

extern "C" void FshOutWalk__vfunc_02(FshOutWalk *self)
{
    X_func_001682B0();
    X_func_00166DA4(self, 0x64);
    self->m_unk04 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", FshOutWalk__vfunc_03);

extern "C" void FshOutWalk__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void func_001577F8(FshOutWalk *self, int state)
{
    if (self->m_unk04 != state) {
        self->m_unk04 = state;
        self->m_unk38 = 0;
    }
}

extern "C" void FshOutSerch__vfunc_02(FshOutSerch *self)
{
    X_func_00166DA4(self, 0x64);
    X_func_00166F50(self, self->m_unk14, 10.0f);
    X_func_00165398(self->m_owner, 1, 2, 0x5A);
}

extern "C" int FshOutSerch__vfunc_03(FshOutSerch *self)
{
    int ret;
    int res = X_func_001679B4(self, self->m_unk14, 0, 10.0f, 3.1415926218032837f);
    switch (res) {
        case 0:
            ret = -1;
            break;
        case 1:
            ret = 0x13;
            break;
        case 2:
        default:
            ret = 0x14;
            break;
    }
    return ret;
}

extern "C" void FshOutSerch__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void FshOutRound__vfunc_02(FshOutRound *self)
{
    X_func_00165398(self->m_owner, 1, 2, 0x5A);
    X_func_00166DA4(self, 0x64);
    X_func_00166F50(self, self->m_unk14, 10.0f);
}

extern "C" int FshOutRound__vfunc_03(FshOutRound *arg0)
{
    register int res PS2_REG("$2");
    register FshOutRound *self PS2_REG("$17");
    register int ret PS2_REG("$16");
    register int one PS2_REG("$3");

    self = arg0;
    ret = -1;
    res = X_func_001679B4(self, self->m_unk14, 0, 30.0f, 3.141592562198639f);
    if (res != 0) {
        one = 1;
        if (res == one) {
            X_func_00202F10(self->m_owner->m_unk1F0);
            ret = 0x13;
        } else {
            X_func_00202F10(self->m_owner->m_unk1F0);
            ret = 0x14;
        }
    }
    return ret;
}

extern "C" void FshOutRound__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void FshOutStared__vfunc_02(FshOutStared *self)
{
    X_func_00167230(self, 1, 0.39269906282424927f);
    self->m_unk04 = 0;
    self->m_unk38 = 0;
    self->m_unk3C = 0;
    self->m_unk3A = D_002F0C78[X_func_0010423C(0, 2)];
}

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", FshOutStared__vfunc_03);

extern "C" void FshOutStared__vfunc_04(void)
{
    X_func_00166AD0();
}

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", FshOutCollision__vfunc_02);

extern "C" int FshOutCollision__vfunc_03(FshOutCollision *self)
{
    register int r PS2_REG("$4") = X_func_001D19A8(&D_007812C0, self->m_unk00);
    register int ret PS2_REG("$2") = (r != 0) ? 0x13 : -1;
    if (r != 0) {
        self->m_owner->m_unk2C = 1;
    }
    return ret;
}

extern "C" void FshOutWin__vfunc_02(FshOutWin *self)
{
    if ((unsigned int)self->m_unk10 >= 2U) {
        X_func_00166DA4(self, 0x64);
    }
    self->m_unk38 = X_func_001044B8(100.0f, 200.0f);
    X_func_00166F50(self, self->m_unk14, 10.0f);
    self->m_unk04 = 0;
}

extern "C" int FshOutWin__vfunc_03(FshOutWin *self)
{
    int id;

    if ((self->m_unk04 == 0) && (X_func_001679B4(self, self->m_unk14, 1, self->m_unk38, 0.7853981405496597f) != 0)) {
        X_func_001680A0(self, 1, 0x100);
        id = X_func_001694CC(self, 0xD);
        self->m_unk2C = id;
        X_func_00180EEC(&D_007B2580, id, 1);
        self->m_unk04 = 1;
    }
    return -1;
}

extern "C" void FshOutWin__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void FshOutTest__vfunc_02(FshOutTest *self)
{
    self->m_unk04 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0BE8);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0BF8);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C08);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C18);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C28);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C38);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C48);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C58);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C68);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C78);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C80);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C88);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C90);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0C98);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0CA0);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0CA8);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0CB0);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0CB8);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0CC0);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0CC8);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0CE0);

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", FshOutTest__vfunc_03);

extern "C" int FshOutDead__vfunc_03(FshOutDead *self)
{
    int ret = -1;
    int buf[4];

    switch (self->m_unk04) {
        case 0:
            if (--self->m_unk38 == 0) {
                ret = 0x13;
                ((FshObjStatView *)self->m_unk08)->m_flags &= ~0x400;
                buf[0] = self->m_owner->m_unk1D8;
                X_func_001DA740((void *)self->m_unk08, 0x1B, buf);
                self->m_owner->m_unk0C = 1;
                ((FshObjStatView *)self->m_unk08)->m_flags &= ~0x2000;
                X_func_001D10D0(&D_007812C0, self->m_unk00, 0x40);
                X_func_001D1410(&D_007812C0, self->m_unk00, 0x10000000);
                X_func_001D1410(&D_007812C0, self->m_unk00, 0x400);
            }
            break;
        case 1:
            X_func_001689E8(self);
            {
                unsigned int idx = self->m_owner->m_unk04 + 0x33;
                ((int *)D_007B205C)[idx]++;
            }
            self->m_unk04 = 2;
            break;
        case 2:
            break;
    }
    return ret;
}

extern "C" void FshOutDead__vfunc_04(FshOutDead *self)
{
    FshObjStatView *stat = (FshObjStatView *)self->m_unk08;
    stat->m_flags &= ~0x400;
    X_func_00166AD0(self);
}

INCLUDE_ASM("asm/nonmatchings/unk/FshMain", FshOutDead__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0D08);
INCLUDE_RODATA("asm/nonmatchings/unk/FshMain", D_002F0D18);
