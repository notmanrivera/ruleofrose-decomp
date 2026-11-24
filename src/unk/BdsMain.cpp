#include "include_asm.h"
#include "emy/emy.h"
extern "C" void *__builtin_new(unsigned int);
extern "C" void func_00166A1C(EmyOut *, int, void *, EmyMain *);
extern int _vt$10BdsOutWalk;
extern int _vt$12BdsOutSearch;
extern int _vt$9BdsOutAtk;
extern int _vt$9BdsOutWin;
extern int _vt$12BdsOutStared;
extern int _vt$10BdsOutDead;

struct BdsVtblEntry {
    short m_delta;
    short m_pad;
    int m_fn;
};

struct BdsStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[0xA];
    signed char *m_table;
};

struct BdsActorPtr {
    unsigned char m_pad00[0x100];
    void *m_objStat100;
};

struct BdsDogSlot {
    unsigned char m_pad00[0x4D0];
};
STATIC_ASSERT(sizeof(BdsDogSlot) == 0x4D0, BdsDogSlot_size);

struct BdsMagSystem {
    unsigned char m_pad00[0x14E60];
    BdsDogSlot m_actors[1];
};

struct BdsMain : EmyMain {
    unsigned char m_unk204;             // +0x204
    unsigned char m_unk205;             // +0x205
    unsigned char m_pad206[2];          // +0x206..+0x207
    int m_unk208;                       // +0x208
    int m_unk20C;                       // +0x20C
    int m_unk210;                       // +0x210
    int m_unk214;                       // +0x214
    int m_unk218;                       // +0x218
    int m_unk21C;                       // +0x21C
};
STATIC_ASSERT(sizeof(BdsMain) == 0x220, BdsMain_size);

struct BdsOutWalk : EmyOut {
    int m_unk38;                        // +0x38
};
STATIC_ASSERT(sizeof(BdsOutWalk) == 0x3C, BdsOutWalk_size);

struct BdsOutStared : EmyOut {
    unsigned short m_unk38;             // +0x38
    unsigned short m_pad3A;             // +0x3A
};
STATIC_ASSERT(sizeof(BdsOutStared) == 0x3C, BdsOutStared_size);

struct BdsOutSearch : EmyOut {
};

struct BdsOutAtk : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
};
STATIC_ASSERT(sizeof(BdsOutAtk) == 0x44, BdsOutAtk_size);

struct BdsOutWin : EmyOut {
    float m_unk38;                      // +0x38
};
STATIC_ASSERT(sizeof(BdsOutWin) == 0x3C, BdsOutWin_size);

extern int vtbl_BdsMain asm("_vt$7BdsMain");
extern BdsMagSystem *g_magSystem asm("_9MagSystem$m_current_system");

extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_EmyMain__vfunc_01(EmyMain *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" float X_func_0010A650(void *) asm("func_0010A650__8DogActor");
extern "C" int X_func_00118FEC(void *) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_00144244(void) asm("func_00144244");
extern "C" int X_func_0014A21C(BdsMain *) asm("func_0014A21C");
extern "C" int X_func_0014A230(BdsMain *) asm("func_0014A230");
extern "C" int X_func_0014A240(BdsMain *) asm("func_0014A240");
extern "C" int X_func_0014A268(BdsMain *) asm("func_0014A268");
extern "C" void func_0014A450(BdsOutWalk *, float *);
extern "C" void func_0014A700(BdsOutWalk *, int);
extern "C" void func_0014A78C(BdsOutWalk *, int);
extern "C" void func_0014A814(BdsOutWalk *, int);
extern "C" int func_0014A9E8(BdsOutStared *, float *, float);
extern "C" void func_001670DC(BdsOutWalk *, float *, float);
extern "C" float func_00169A14(float *);
extern "C" int func_001D19A8(void *, unsigned int);
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166B74(EmyOut *, void *) asm("func_00166B74");
extern "C" int X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" int X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" int X_func_001679B4(EmyOut *, int, int, float, float) asm("func_001679B4");
extern "C" int X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" int X_func_001693EC(EmyOut *, int, int, int) asm("func_001693EC");
extern "C" int X_func_0016947C(EmyOut *) asm("func_0016947C");
extern "C" int X_func_001694CC(EmyOut *, int) asm("func_001694CC");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_00169BAC(float, float, int, void *, void *) asm("func_00169BAC");
extern "C" int X_func_0016A7AC(void *) asm("func_0016A7AC");
extern "C" int X_func_00180EEC(void *, int, int) asm("func_00180EEC");
extern "C" int X_func_001DA228(void *, int, void *) asm("func_001DA228");
extern "C" int X_func_001F13A8(int, int, int, int, float, float, float) asm("func_001F13A8");
extern "C" int X_func_001F603C(int, int, int, int, float, float, int) asm("func_001F603C");
extern "C" int X_func_00202F10(void *) asm("func_00202F10");
extern "C" float X_func_0026CB00(float, float) asm("func_0026CB00");

extern int D_006E9840;
extern int D_007812C0;
extern BdsActorPtr *D_007A3350;
extern int D_007B2580;

extern "C" void func_00149D18(BdsMain *self)
{
    register int c20 PS2_REG("$3") = 0x20;
    register int one PS2_REG("$2") = 1;
    register int three PS2_REG("$5") = 3;
    EmyOut *out;

    ((int *)self->m_padEC)[7] = c20;
    ((int *)self->m_padEC)[2] = three;
    ((int *)self->m_padEC)[3] = three;
    ((int *)self->m_padEC)[4] = three;
    ((int *)self->m_padEC)[5] = three;
    self->m_unk204 = 0;
    self->m_unk205 = 0;
    ((int *)self->m_padEC)[0] = one;
    ((int *)self->m_padEC)[1] = one;
    ((int *)self->m_padEC)[8] = one;
    ((int *)self->m_padEC)[9] = one;
    self->m_stateFlags[5] = one;
    self->m_stateFlags[3] = one;
    self->m_stateFlags[2] = one;
    self->m_stateFlags[6] = 0;
    self->m_stateFlags[4] = 0;
    self->m_stateFlags[1] = 0;

    out = (EmyOut *)__builtin_new(0x4C);
    func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &_vt$10BdsOutWalk;
    self->m_unk48[1] = out;

    out = (EmyOut *)__builtin_new(0x38);
    func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &_vt$12BdsOutSearch;
    self->m_unk48[2] = out;

    out = (EmyOut *)__builtin_new(0x44);
    func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &_vt$9BdsOutAtk;
    self->m_unk48[3] = out;

    out = (EmyOut *)__builtin_new(0x3C);
    func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &_vt$9BdsOutWin;
    self->m_unk48[4] = out;

    out = (EmyOut *)__builtin_new(0x3C);
    func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &_vt$12BdsOutStared;
    self->m_unk48[5] = out;

    out = (EmyOut *)__builtin_new(0x38);
    func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &_vt$10BdsOutDead;
    self->m_unk48[6] = out;
}

extern "C" void BdsMain__vfunc_01(BdsMain *self, int flags)
{
    self->m_vtbl = &vtbl_BdsMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return Xv___builtin_delete(self);
    }
}

extern "C" void BdsMain__vfunc_04(BdsMain *self)
{
    if (self->m_unk28 && self->m_unk2C && self->m_nextState == -1) {
        if (self->m_unk208) {
            if (!X_func_0014A21C(self)) {
                if (self->m_unk205) {
                    self->m_nextState = 0;
                    self->m_unk205 = 0;
                }
                return;
            }
            self->m_unk205 = 1;
        }
        if (self->m_unk20C && X_func_0014A230(self)) {
            self->m_nextState = 1;
        } else if (self->m_unk210 && (self->m_flags30 & 1)) {
            self->m_nextState = 2;
        } else {
            int result = X_func_0014A268(self);
            if (self->m_unk204) {
                if (!result) {
                    self->m_unk204 = 0;
                    if (self->m_unk218) {
                        self->m_nextState = 4;
                        return;
                    }
                }
            } else if (result) {
                self->m_unk204 = 1;
                if (self->m_unk214) {
                    self->m_nextState = 3;
                    return;
                }
                goto fallback;
            }
fallback:
            if (self->m_unk21C && X_func_0014A240(self)) {
                self->m_nextState = 5;
            } else {
                return;
            }
        }
    }
}

extern "C" void BdsMain__vfunc_05(BdsMain *self)
{
    self->m_stateChanged = 0;
    int flags = self->m_flags30;
    if (flags & 2) {
        int next = 6;
        EmyBrainView *brain = (EmyBrainView *)self->m_brain;
        self->m_curState = next;
        brain->m_state = next;
        self->m_stateChanged = 1;
    } else if (self->m_nextState != -1) {
        int next = X_func_0016968C(self->m_brain, self->m_nextState);
        self->m_unk205 = 0;
        self->m_unk204 = 0;
        if (next != 0) {
            self->m_curState = next;
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

extern "C" void BdsMain__vfunc_06(BdsMain *self)
{
    EmyOut *curOut;
    BdsVtblEntry *vt;

    if (self->m_stateChanged != 0) {
        curOut = self->m_curOut;
        vt = (BdsVtblEntry *)((char *)curOut->m_vtbl + 0x20);
        ((void (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
        vt = (BdsVtblEntry *)((char *)self->m_vtbl + 0x10);
        ((void (*)(void *))vt->m_fn)((char *)self + vt->m_delta);
    }
    curOut = self->m_curOut;
    vt = (BdsVtblEntry *)((char *)curOut->m_vtbl + 0x18);
    self->m_nextState = ((int (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
}

static inline bool BdsStateBelowLimit(int state) { return state < 7; }
static inline void BdsWriteFlag(char *slot, int value) { *(int *)(slot + 0x200) = value; }
static inline void BdsWriteStateFlag(int self, int index, int value) { char *slot = (char *)((index * 4) + self); BdsWriteFlag(slot, value); }

extern "C" int BdsMain__vfunc_02(BdsMain *self)
{
    int cur;
    EmyOut *obj;
    BdsVtblEntry *vt;
    BdsStateTable *tbl;
    unsigned char count;
    register signed char *base PS2_REG("$7");

    cur = self->m_curState;
    if (BdsStateBelowLimit(cur) && (cur > 0)) {
        obj = ((EmyOut **)self->m_unk48)[cur];
        self->m_curOut = obj;
        vt = (BdsVtblEntry *)((char *)obj->m_vtbl + 0x10);
        ((void (*)(void *))vt->m_fn)((char *)obj + vt->m_delta);
    }
    tbl = (BdsStateTable *)self->m_unkE8;
    count = tbl->m_count;
    base = tbl->m_table;
    base += self->m_curState * count;
    for (int i = 0; i < count; ++i) {
        if (base[i] != 0) {
            BdsWriteStateFlag((int)((char *)self + 8), i, 1);
        } else {
            BdsWriteStateFlag((int)((char *)self + 8), i, 0);
        }
    }
    return 0;
}

extern "C" int func_0014A21C(void)
{
    return X_func_00165734();
}

extern "C" int func_0014A230(void)
{
    volatile int unused[12];
    (void)unused;
    return 0;
}

extern "C" int func_0014A240(void)
{
    return X_func_00118FEC(&D_006E9840) == 4;
}

extern "C" int func_0014A268(BdsMain *self)
{
    float dist = 0.0f;
    void *obj;

    X_func_001DA228(self->m_objStat, 0x5F, &dist);
    obj = (D_007A3350 != 0) ? D_007A3350->m_objStat100 : 0;
    return X_func_00169BAC(dist, 3.1415926218032837f, 1, obj, self->m_objStat);
}

extern "C" void BdsOutWalk__vfunc_02(BdsOutWalk *self)
{
    func_0014A78C(self, 1);
    self->m_unk04 = 0;
}

static inline int checkHitWalk(BdsOutWalk *self)
{
    int r = func_001D19A8(&D_007812C0, self->m_unk00);
    if (r) {
        self->m_owner->m_unk2C = 1;
    }
    return r;
}

extern "C" int BdsOutWalk__vfunc_03(BdsOutWalk *self)
{
    float vec[4];
    int step = self->m_unk04;
    self->m_unk38++;

    switch (step) {
    case 0: {
        int r = X_func_0010423C(1, 0x64);
        if (r < 0x51) {
            func_0014A450(self, vec);
            if (func_00169A14(vec) >= 100.0f) {
                func_001670DC(self, vec, 0.0f);
                func_0014A814(self, 1);
                break;
            }
        }
        func_0014A700(self, r);
        break;
    }
    case 1:
        if (self->m_unk24 != 0) {
            X_func_00202F10(self->m_owner->m_unk1F0);
            func_0014A814(self, 0);
        }
        break;
    case 2:
        if (self->m_unk38 >= 0x1E) {
            func_0014A814(self, 0);
        }
        break;
    case 3:
        if (checkHitWalk(self) != 0) {
            func_0014A814(self, 0);
        }
        break;
    }
    return -1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF568);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF578);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF588);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF598);

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", func_0014A450);

extern "C" void func_0014A700(BdsOutWalk *self, int arg1)
{
    if (arg1 < 0x56) {
        int r = X_func_0010423C(1, 0x64);
        func_0014A78C(self, (r < 0x1F) ? 1 : ((r < 0x3D) ? 0x1C : 0x1D));
        return func_0014A814(self, 2);
    }
    X_func_001680A0(self, 0x14, 0);
    func_0014A814(self, 3);
}

extern "C" void func_0014A78C(BdsOutWalk *self, int anim)
{
    float v;

    v = self->m_owner->m_unk1C4;
    if (v != 0.0f) {
        v = v * 0.016666666f;
    } else {
        v = 0.016666666f;
    }
    X_func_001F603C(self->m_unk00, anim, -1, 0x100, v, 32769.0f, 1);
}

extern "C" void BdsOutWalk__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void func_0014A814(BdsOutWalk *self, int state)
{
    if (self->m_unk04 != state) {
        self->m_unk04 = state;
        self->m_unk38 = 0;
    }
}

extern "C" void BdsOutStared__vfunc_02(BdsOutStared *self)
{
    BdsVtblEntry *vt;

    self->m_unk04 = 0;
    vt = (BdsVtblEntry *)((char *)self->m_vtbl + 0x18);
    ((int (*)(void *))vt->m_fn)((char *)self + vt->m_delta);
}

extern "C" int BdsOutStared__vfunc_03(BdsOutStared *self)
{
    float ang;

    switch (self->m_unk04) {
        case 0:
            if (func_0014A9E8(self, &ang, 0.52359876f) == 0) {
                X_func_001F13A8(self->m_unk00, (ang >= 0.0f) ? 9 : 8, 0, 1, ang, 1.5f, 32769.0f);
                self->m_unk04 = 1;
            } else {
                X_func_001680A0(self, 0x17, 0x100);
                self->m_unk04 = 2;
            }
            break;
        case 1:
            if (X_func_00144244() == 0) {
                return 6;
            }
            if (self->m_unk24 != 0) {
                X_func_001680A0(self, 0x17, 0x100);
                self->m_unk04 = 2;
            }
            break;
        case 2:
            if (X_func_00144244() != 0) {
                return -1;
            }
            self->m_unk38 = 0;
            self->m_unk04 = 3;
            break;
        case 3:
            X_func_001693EC(self, 8, 0x18, 9);
            if (X_func_00144244() == 0) {
                self->m_unk04 = 0;
                break;
            }
            if (++self->m_unk38 >= 0x3C) {
                X_func_0016947C(self);
                return 6;
            }
            break;
    }
    return -1;
}

extern "C" void BdsOutStared__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" int func_0014A9E8(BdsOutStared *self, float *outAngle, float limit)
{
    float posA[4];
    float posB[4];
    float yaw;
    float ang;
    float half;

    X_func_00166B74(self, posA);
    X_func_0016A7AC(posB);
    yaw = X_func_0010A650(&g_magSystem->m_actors[((EmyObjStatView *)self->m_unk08)->m_actorId]);
    ang = X_func_0026CB00(posB[0] - posA[0], posB[2] - posA[2]) - yaw;
    if (ang < -3.14159265358979323846) {
        ang += 6.28318530717958647692;
    }
    if (ang > 3.14159265358979323846) {
        ang -= 6.28318530717958647692;
    }
    if (outAngle != 0) {
        *outAngle = ang;
    }
    half = limit * 0.5f;
    {
        int ret = 0;
        if (-half <= ang && ang <= half) {
            ret = 1;
        }
        return ret;
    }
}

extern "C" void BdsOutSearch__vfunc_02(BdsOutSearch *self)
{
    X_func_00166DA4(self, 0x64);
    X_func_00166F50(self, self->m_unk14, 10.0f);
}

extern "C" int BdsOutSearch__vfunc_03(BdsOutSearch *self)
{
    int next;
    int result = X_func_001679B4(self, self->m_unk14, 0, 200.0f, 3.1415926218032837f);
    switch (result) {
        case 0:
            next = -1;
            break;
        case 1:
            next = 6;
            X_func_00202F10(self->m_owner->m_unk1F0);
            break;
        case 2:
            next = 4;
            X_func_00202F10(self->m_owner->m_unk1F0);
            break;
        default:
            next = 7;
            X_func_00202F10(self->m_owner->m_unk1F0);
            break;
    }
    return next;
}

extern "C" void BdsOutSearch__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void BdsOutAtk__vfunc_02(BdsOutAtk *self)
{
    self->m_unk40 = 0;
    self->m_unk3C = 0;
    X_func_00166DA4(self, 0x64);
    self->m_unk04 = 0;
    X_func_00166F50(self, self->m_unk14, 75.0f);
    self->m_unk38 = 0;
    X_func_001694CC(self, 0xB);
}

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutAtk__vfunc_03);

extern "C" void BdsOutAtk__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void BdsOutWin__vfunc_02(BdsOutWin *self)
{
    int id;

    X_func_001680A0(self, 0x15, 0x100);
    id = X_func_001694CC(self, 0xD);
    self->m_unk2C = id;
    X_func_00180EEC(&D_007B2580, id, 1);
    self->m_unk04 = 1;
}

extern "C" int BdsOutWin__vfunc_03(BdsOutWin *self)
{
    if ((self->m_unk04 == 0) && (X_func_001679B4(self, self->m_unk14, 1, self->m_unk38, 0.7853981405496597f) != 0)) {
        X_func_00202F10(self->m_owner->m_unk1F0);
        self->m_unk04 = 1;
    }
    return -1;
}

extern "C" void BdsOutWin__vfunc_04(void)
{
    X_func_00166AD0();
}

INCLUDE_ASM("asm/nonmatchings/unk/BdsMain", BdsOutDead__vfunc_02);

extern "C" int BdsOutDead__vfunc_03(void)
{
    return -1;
}

extern "C" void BdsOutDead__vfunc_04(void)
{
    X_func_00166AD0();
}

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF5C8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF5D8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF5E8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF5F8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdsMain", D_002EF608);
