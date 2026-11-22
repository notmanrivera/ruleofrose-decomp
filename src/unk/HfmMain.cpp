#include "include_asm.h"
#include "emy/emy.h"

struct HfmVtblEntry {
    short m_delta;
    short m_pad;
    int m_fn;
};

struct HfmStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[0xA];
    signed char *m_table;
};

struct HfmActorPtr {
    unsigned char m_pad00[0x100];
    int m_objStat100;
};

struct HfmCmdArg {
    int m_unk00;
    int m_arg1;
    int m_arg2;
    int m_arg3;
    int m_arg4;
};

struct HfmGlobalFbdSub {
    unsigned char m_pad00[0x68];
    int m_unk68;                        // +0x68
    unsigned char m_pad6C[0x10];
    int m_unk7C;                        // +0x7C
};

struct HfmMain : EmyMain {
    int m_unk204;                       // +0x204
    int m_unk208;                       // +0x208
    int m_unk20C;                       // +0x20C
    int m_unk210;                       // +0x210
    int m_unk214;                       // +0x214
    int m_unk218;                       // +0x218
    int m_unk21C;                       // +0x21C
    unsigned char m_pad220[8];          // +0x220..+0x227
    unsigned char m_unk228;             // +0x228
    unsigned char m_pad229;             // +0x229
    unsigned char m_unk22A;             // +0x22A
    unsigned char m_pad22B;             // +0x22B
    int m_unk22C;                       // +0x22C
    int m_unk230;                       // +0x230
    int m_unk234;                       // +0x234
    int m_unk238;                       // +0x238
};
STATIC_ASSERT(sizeof(HfmMain) == 0x23C, HfmMain_size);

struct HfmOutWalk : EmyOut {
    int m_unk38;                        // +0x38
};
STATIC_ASSERT(sizeof(HfmOutWalk) == 0x3C, HfmOutWalk_size);

struct HfmOutSlap : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    int m_unk44;                        // +0x44
    int m_unk48;                        // +0x48
};
STATIC_ASSERT(sizeof(HfmOutSlap) == 0x4C, HfmOutSlap_size);

struct HfmOutBreak : EmyOut {
};

struct HfmOutWalk2 : EmyOut {
    int m_unk38;                        // +0x38
};
STATIC_ASSERT(sizeof(HfmOutWalk2) == 0x3C, HfmOutWalk2_size);

struct HfmOutRide : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    int m_unk44;                        // +0x44
    int m_unk48;                        // +0x48
    int m_unk4C;                        // +0x4C
    unsigned char m_pad50[8];           // +0x50..+0x57
    int m_unk58;                        // +0x58
    int m_unk5C;                        // +0x5C
    int m_unk60;                        // +0x60
    int m_unk64;                        // +0x64
    int m_unk68;                        // +0x68
    int m_unk6C;                        // +0x6C
    int m_unk70;                        // +0x70
    int m_unk74;                        // +0x74
    unsigned char m_pad78[0xC];         // +0x78..+0x83
    int m_unk84;                        // +0x84
    unsigned char m_pad88[0xC];         // +0x88..+0x93
    float m_unk94;                      // +0x94
};
STATIC_ASSERT(sizeof(HfmOutRide) == 0x98, HfmOutRide_size);

struct HfmOutDead : EmyOut {
};

struct HfmOutWin : EmyOut {
    float m_unk38;                      // +0x38
};
STATIC_ASSERT(sizeof(HfmOutWin) == 0x3C, HfmOutWin_size);

struct HfmOutBitten : EmyOut {
};

struct HfmOutCounter : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
};
STATIC_ASSERT(sizeof(HfmOutCounter) == 0x44, HfmOutCounter_size);

struct HfmOutTest : EmyOut {
};

extern int vtbl_HfmMain asm("_vt$7HfmMain");

extern int D_002EF418[];
extern int D_006E9840;
extern int D_006FBD80;
extern int D_00727AE4;
extern int D_00727B1C;
extern int D_007812C0;
extern HfmActorPtr *D_007A3350;
extern int D_007B2580;

extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_EmyMain__vfunc_01(EmyMain *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_00103DE4(void) asm("func_00103DE4");
extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" int X_func_00104394(int, int, int) asm("func_00104394");
extern "C" float X_func_001044B8(float, float) asm("func_001044B8");
extern "C" int X_func_00117FC4(void *, unsigned int, int, int, int) asm("func_00117FC4__9MagSystemUiiPfT3");
extern "C" int X_func_00118FEC(void *) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_00119090(void *) asm("func_00119090__9MagSystem");
extern "C" int X_func_0012A7CC(void *) asm("func_0012A7CC");
extern "C" int X_func_00131184(void *, int, int, int) asm("func_00131184");
extern "C" int X_func_001311BC(void *, int, int, int) asm("func_001311BC");
extern "C" int X_func_0013166C(void *, int, int) asm("func_0013166C");
extern "C" void X_func_001357B0(void *, int, int) asm("func_001357B0");
extern "C" int X_func_0013F528(void *, int *, int) asm("func_0013F528__8MagScenePii");
extern "C" int X_func_001442DC(int) asm("func_001442DC");
extern "C" int X_func_00144308(int) asm("func_00144308");
extern "C" int X_func_00145760(HfmMain *) asm("func_00145760");
extern "C" int X_func_00145788(HfmMain *) asm("func_00145788");
extern "C" int func_001457F0(HfmMain *);
extern "C" void X_func_00145A10(HfmOutWalk *, float *) asm("func_00145A10");
extern "C" void func_00145CC8(HfmOutWalk *, int);
extern "C" void func_00145D44(HfmOutWalk *, int);
extern "C" void X_func_00146628(HfmOutWalk2 *, float *) asm("func_00146628");
extern "C" void func_001468E0(HfmOutWalk2 *, int);
extern "C" void func_00146944(HfmOutWalk2 *, int);
extern "C" void func_001469CC(HfmOutWalk2 *, int);
extern "C" void func_00146AE4(HfmOutRide *);
extern "C" void func_00146BF0(HfmOutRide *);
extern "C" void func_00146C8C(HfmOutRide *, float);
extern "C" int X_func_00146D88(HfmOutRide *) asm("func_00146D88");
extern "C" int X_func_001473E4(HfmOutRide *) asm("func_001473E4");
extern "C" void func_00147760(HfmOutRide *);
extern "C" int X_func_00147840(HfmOutRide *) asm("func_00147840");
extern "C" int func_00148450(HfmOutRide *);
extern "C" int func_001484EC(HfmOutRide *);
extern "C" void X_func_00148620(HfmOutRide *) asm("func_00148620");
extern "C" void func_00148A00(HfmOutRide *);
extern "C" void func_00148AF0(HfmOutRide *);
extern "C" void func_00148BD0(HfmOutRide *);
extern "C" void func_00148CB4(HfmOutRide *);
extern "C" int X_func_00165570(EmyMain *) asm("func_00165570");
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00166108(HfmMain *) asm("func_00166108");
extern "C" int X_func_0016649C(EmyMain *, int) asm("func_0016649C");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166B74(EmyOut *, float *) asm("func_00166B74");
extern "C" int X_func_00166C8C(EmyOut *, float *) asm("func_00166C8C");
extern "C" int X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" void X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" void X_func_001670DC(EmyOut *, float *, float) asm("func_001670DC");
extern "C" int X_func_00167D88(EmyOut *, float *, float) asm("func_00167D88");
extern "C" int X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" int X_func_001682B0(EmyOut *) asm("func_001682B0");
extern "C" int X_func_001693EC(EmyOut *, int, int, int) asm("func_001693EC");
extern "C" void X_func_0016947C(EmyOut *) asm("func_0016947C");
extern "C" int X_func_001694CC(EmyOut *, int) asm("func_001694CC");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_00169810(int, int) asm("func_00169810");
extern "C" float X_func_00169A14(float *) asm("func_00169A14");
extern "C" int X_func_00169BAC(float, float, int, int, void *) asm("func_00169BAC");
extern "C" int X_func_00176CC8(void *, void *) asm("func_00176CC8");
extern "C" int X_func_0017C340(void *, float *, void *, int, float, float) asm("func_0017C340");
extern "C" int X_func_00180EA8(void *, int) asm("func_00180EA8");
extern "C" int X_func_001CA8E8(void *, unsigned short, int, unsigned short, int, int, int) asm("func_001CA8E8");
extern "C" int X_func_001CC250(void *, int, int, unsigned short, int, int, int) asm("func_001CC250");
extern "C" int X_func_001D10D0(void *, unsigned int, int) asm("func_001D10D0");
extern "C" int X_func_001D1410(void *, unsigned int, int) asm("func_001D1410");
extern "C" int X_func_001D19A8(void *, int) asm("func_001D19A8");
extern "C" int X_func_001D89C4(void *, float *) asm("func_001D89C4");
extern "C" int X_func_001DA228(void *, int, void *) asm("func_001DA228");
extern "C" int X_func_001DC48C(void *, unsigned short, int, void *) asm("func_001DC48C");
extern "C" int X_func_001F603C(int, int, int, int, float, float, int) asm("func_001F603C");
extern "C" int X_func_001FAC60(unsigned int, int, int, int, int, unsigned int, int) asm("func_001FAC60");
extern "C" int X_func_00202F10(void *) asm("func_00202F10");

static inline int HfmAnimDone(EmyOut *self, void *world)
{
    int ret = X_func_001D19A8(world, self->m_unk00);
    if (ret != 0) {
        self->m_owner->m_unk2C = 1;
    }
    return ret;
}

extern "C" int func_001445D8(void)
{
    switch (X_func_00119090(&D_006E9840)) {
        case 0: return 0x4E554C4C;
        case 1: return 0x57414954;
        case 2: return 0x464F4C57;
        case 3: return 0x53544159;
        case 4: return 0x46494E44;
        case 5: return 0x46444544;
        case 6: return 0x4D4F5645;
        case 7: return 0x4D564544;
        case 8: return 0x524F5441;
        case 9: return 0x52544544;
        case 10: return 0x44414D47;
        case 11: return 0x4241524B;
        case 12: return 0x00485547;
        default: return 0;
    }
}

extern "C" int func_001446B8(HfmCmdArg *arg0)
{
    const int tbl[26] = {
        0x4B4C434B, 0x0001000B,
        0x4256494C, 0x0001000C,
        0x424C4E44, 0x0001000D,
        0x42464D4C, 0x0001000E,
        0x4243504C, 0x0001000F,
        0x53504D30, 0x0001000B,
        0x73706D30, 0x0001000B,
        0x00000000, 0x0001000B,
        0x0001000B, 0x0001000B,
        0x53504D31, 0x0001000C,
        0x73706D31, 0x0001000C,
        0x00000001, 0x0001000C,
        0x0001000C, 0x0001000C,
    };
    unsigned int i;

    if (X_func_00103DE4() == 0) {
        return 0;
    }
    for (i = 0; i < 26; i += 2) {
        if (tbl[i] == arg0->m_arg1) {
            int off = 0x12540;
            X_func_001357B0((char *)&D_006E9840 + off, tbl[i + 1], arg0->m_arg2);
            return 0;
        }
    }
    {
        int off = 0x12540;
        X_func_001357B0((char *)&D_006E9840 + off, 0x1000B, arg0->m_arg2);
    }
    return 0;
}

// NON_MATCHING: 50/64 differ, 6 relocs differ (size 0x100, game 0x104), 28 edits
#ifdef NON_MATCHING
struct DogActor006FE6A0Base {
    char pad[0x94];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int, int);
};
struct DogActor006FE6A0 : DogActor006FE6A0Base {
    char pad2[0x438];
};
extern "C" int X_func_00103E4C(void) asm("func_00103E4C");
extern "C" int X_func_00103E94(void) asm("func_00103E94");
extern "C" int X_func_0010B620(void *, int, const char *, const char **) asm("func_0010B620__8DogActoriPCcPPCc");
extern DogActor006FE6A0 D_006FE6A0[];
extern "C" int func_00144820(HfmCmdArg *arg0)
{
    int temp_v1 = arg0->m_arg1;

    if (temp_v1 == 0x64697370 || temp_v1 == 0x44495350 || temp_v1 == 1) {
        int idx = X_func_00103E4C();
        if (idx >= 0) {
            D_006FE6A0[idx].v8(0, idx);
        }
    } else {
        int idx = X_func_00103E4C();
        if (idx >= 0) {
            D_006FE6A0[idx].v8(1, idx);
        }
        idx = X_func_00103E94();
        if (idx >= 0) {
            X_func_0010B620(&D_006FE6A0[idx], 0, 0, 0);
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00144820);
#endif

extern "C" int func_00144924(HfmCmdArg *arg0)
{
    int off = 0x12540;

    X_func_00131184((char *)&D_006E9840 + off, arg0->m_arg1, 7, 1);
    return 0;
}

extern "C" int func_00144960(HfmCmdArg *arg0)
{
    int off = 0x12540;

    X_func_001311BC((char *)&D_006E9840 + off, arg0->m_arg1, 7, 1);
    return 0;
}

extern "C" int func_0014499C(HfmCmdArg *arg0)
{
    int arr[8];
    int off = 0x12540;
    register int a PS2_REG("$7") = arg0->m_arg2;
    register int b PS2_REG("$3") = arg0->m_arg3;
    int c = arg0->m_arg4;

    arr[0] = a;
    arr[2] = c;
    arr[1] = b;
    arr[3] = 0;
    arr[4] = 0;
    arr[5] = 0;
    X_func_0013F528((char *)&D_006E9840 + off, arr, arg0->m_arg1);
    return 0;
}

extern "C" int func_001449FC(HfmCmdArg *arg0)
{
    X_func_00117FC4(&D_006E9840, (unsigned int)arg0->m_arg1, arg0->m_arg2, arg0->m_arg3, arg0->m_arg4);
    return 0;
}

extern "C" int func_00144A34(void)
{
    return D_00727B1C;
}

extern "C" int func_00144A40(void)
{
    int off = 0x2BD20;
    HfmGlobalFbdSub *p = (HfmGlobalFbdSub *)((char *)&D_006FBD80 + off);
    int v;

    v = 0;
    if (p->m_unk7C != 0) {
        v = p->m_unk68;
    }
    return v;
}

extern "C" int func_00144A6C(void)
{
    return D_00727AE4;
}

extern "C" int func_00144A78(void)
{
    int off = 0x2BD20;

    X_func_0012A7CC((char *)&D_006FBD80 + off);
    return 0;
}

extern "C" int func_00144AA8(void)
{
    int off = 0x12540;

    X_func_0013166C((char *)&D_006E9840 + off, 0x14, 0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00144AE0);

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00145020);

extern "C" void HfmMain__vfunc_01(HfmMain *self, int flags)
{
    self->m_vtbl = &vtbl_HfmMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return Xv___builtin_delete(self);
    }
}

extern "C" void func_001452FC(HfmMain *self)
{
    struct {
        unsigned short sp0;
        unsigned short sp2;
        int sp4;
    } stack;

    X_func_001DA228(self->m_objStat, 0x67, &stack.sp4);
    if (stack.sp4 != 0) {
        char *base;
        X_func_001DA228(self->m_objStat, 0x66, &stack.sp0);
        base = (char *)&D_007812C0;
        X_func_001DC48C(base + 0x22220, stack.sp0, 0xF, &stack.sp2);
        if (stack.sp2 != 0xFFFF) {
            X_func_001CA8E8(base, stack.sp2, stack.sp4, stack.sp0, 0, -1, 1);
        } else {
            X_func_001CC250(base, -1, stack.sp4, stack.sp0, 0, 0, 1);
        }
        X_func_00169810(self->m_id, stack.sp4);
    }
}

extern "C" void HfmMain__vfunc_04(HfmMain *self)
{
    int next;
    int seen;

    if ((self->m_unk28 != 0) && (next = self->m_nextState, (next == -1))) {
        if ((self->m_unk208 != 0) && (X_func_001442DC(self->m_id) != next)) {
            self->m_nextState = 1;
            self->m_unk234 = X_func_0010423C(0x3C, 0x78);
            return;
        }
        if ((self->m_unk20C != 0) && ((self->m_flags30 & 0x11) == 1)) {
            self->m_unk22A = self->m_unk22A + 1;
            const int tbl[6] = { 0, 10, 30, 50, 70, 100 };
            if (X_func_0010423C(0, 0x63) < tbl[self->m_unk22A]) {
                self->m_unk22A = 0;
                self->m_nextState = 2;
                return;
            }
        }
        if (self->m_unk2C != 0) {
            seen = X_func_00145788(self);
            if (self->m_unk228 != 0) {
                if (seen == 0) {
                    self->m_unk228 = 0;
                    if (self->m_unk214 != 0) {
                        self->m_nextState = 4;
                        return;
                    }
                }
            } else if (seen != 0) {
                self->m_unk228 = 1;
                if (self->m_unk210 != 0) {
                    self->m_nextState = 3;
                    return;
                }
            }
            if ((self->m_unk218 != 0) && (X_func_00166108(self) != 0)) {
                self->m_nextState = 5;
            } else if ((self->m_unk21C != 0) && (X_func_00145760(self) != 0)) {
                self->m_nextState = 6;
            }
        }
    }
}

extern "C" void HfmMain__vfunc_05(HfmMain *self)
{
    int flags;
    int next;
    int res;

    self->m_stateChanged = 0;
    flags = self->m_flags30;
    if (flags & 2) {
        self->m_curState = 7;
        ((EmyBrainView *)self->m_brain)->m_state = 7;
        self->m_stateChanged = 1;
    } else {
        next = self->m_nextState;
        if (next != -1) {
            res = X_func_0016968C(self->m_brain, next);
            self->m_unk228 = 0;
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
    }
    self->m_flags30 = 0;
}

extern "C" void HfmMain__vfunc_06(HfmMain *self)
{
    EmyOut *curOut;
    HfmVtblEntry *vt;

    if (self->m_stateChanged != 0) {
        curOut = self->m_curOut;
        vt = (HfmVtblEntry *)((char *)curOut->m_vtbl + 0x20);
        ((void (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
        vt = (HfmVtblEntry *)((char *)self->m_vtbl + 0x10);
        ((void (*)(void *))vt->m_fn)((char *)self + vt->m_delta);
    }
    curOut = self->m_curOut;
    vt = (HfmVtblEntry *)((char *)curOut->m_vtbl + 0x18);
    self->m_nextState = ((int (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
}

static inline bool HfmStateBelowLimit(int state) { return state < 0xA; }
static inline void HfmWriteFlag(char *slot, int value) { *(int *)(slot + 0x200) = value; }
static inline void HfmWriteStateFlag(int self, int index, int value) { char *slot = (char *)((index * 4) + self); HfmWriteFlag(slot, value); }

extern "C" int HfmMain__vfunc_02(HfmMain *self)
{
    int cur;
    EmyOut *obj;
    HfmVtblEntry *vt;
    HfmStateTable *tbl;
    unsigned char count;
    register signed char *base PS2_REG("$7");

    cur = self->m_curState;
    if (HfmStateBelowLimit(cur) && (cur > 0)) {
        obj = ((EmyOut **)self->m_unk48)[cur];
        self->m_curOut = obj;
        vt = (HfmVtblEntry *)((char *)obj->m_vtbl + 0x10);
        ((void (*)(void *))vt->m_fn)((char *)obj + vt->m_delta);
    }
    tbl = (HfmStateTable *)self->m_unkE8;
    count = tbl->m_count;
    base = tbl->m_table;
    base += self->m_curState * count;
    for (int i = 0; i < count; ++i) {
        if (base[i] != 0) {
            HfmWriteStateFlag((int)((char *)self + 4), i, 1);
        } else {
            HfmWriteStateFlag((int)((char *)self + 4), i, 0);
        }
    }
    return 0;
}

extern "C" int func_00145744(void)
{
    return X_func_00165734();
}

extern "C" int func_00145758(void)
{
    return 0;
}

extern "C" int func_00145760(void)
{
    return X_func_00118FEC(&D_006E9840) == 4;
}

extern "C" void func_00145788(HfmMain *self)
{
    float f;
    int v;

    X_func_001DA228(self->m_objStat, 0x5F, &f);
    v = 0;
    if (D_007A3350 != 0) {
        v = D_007A3350->m_objStat100;
    }
    X_func_00169BAC(f, 3.14159265f, 1, v, self->m_objStat);
}

extern "C" int HfmMain__vfunc_07(void)
{
    return 1;
}

extern "C" int func_001457F0(HfmMain *self)
{
    int v = self->m_unk230 + 1;
    self->m_unk230 = v;
    return self->m_unk22C < v;
}

extern "C" void func_00145808(HfmMain *self, int val)
{
    self->m_unk22C = val;
    self->m_unk230 = 0;
}

extern "C" int func_00145814(HfmMain *self)
{
    int v = self->m_unk234 - 1;
    self->m_unk234 = v;
    return (unsigned int)~v >> 0x1F;
}

extern "C" void func_0014582C(HfmMain *self, int delta)
{
    int v = self->m_unk234 - delta;
    self->m_unk234 = (v < 0) ? 0 : v;
}

extern "C" void HfmOutWalk__vfunc_02(HfmOutWalk *self)
{
    X_func_00166DA4(self, 0x64);
    X_func_001680A0(self, 0xC, 0);
    self->m_unk04 = 0;
    func_00145D44(self, 3);
    self->m_owner->m_unk150 = 0;
}

extern "C" int HfmOutWalk__vfunc_03(HfmOutWalk *self)
{
    float sp[4];
    int step;
    int state;
    int r;
    int v;

    state = self->m_unk04;
    step = self->m_unk38 + 1;
    self->m_unk38 = step;
    switch (state) {
        case 0:
            r = X_func_0010423C(1, 0x5F);
            if (r < 0x51) {
                X_func_00145A10(self, sp);
                v = 0;
                if (D_007A3350 != 0) {
                    v = D_007A3350->m_objStat100;
                }
                if (X_func_00169BAC(114.9999924f, 6.283185124397278f, 0, v, (void *)self->m_unk08) == 0) {
                    X_func_001670DC(self, sp, 0.0f);
                    func_00145D44(self, 1);
                    break;
                }
            }
            func_00145CC8(self, r);
            break;
        case 1:
            if (self->m_unk24 != 0) {
                X_func_00202F10(self->m_owner->m_unk1F0);
                func_00145D44(self, 0);
            }
            break;
        case 2:
            if (step >= 0x1E) {
                func_00145D44(self, 0);
            }
            break;
        case 3:
            if (HfmAnimDone(self, &D_007812C0) != 0) {
                func_00145D44(self, 0);
            }
            break;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00145A10);

extern "C" void func_00145CC8(HfmOutWalk *self, int arg1)
{
    if (arg1 < 0x5B) {
        X_func_001682B0(self);
        return func_00145D44(self, 2);
    }
    X_func_001680A0(self, 0xC, 0);
    func_00145D44(self, 3);
}

extern "C" void HfmOutWalk__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void func_00145D44(HfmOutWalk *self, int state)
{
    if (self->m_unk04 != state) {
        self->m_unk04 = state;
        self->m_unk38 = 0;
    }
}

extern "C" void HfmOutSlap__vfunc_02(HfmOutSlap *self)
{
    self->m_unk44 = 0x2D;
    self->m_unk38 = 0;
    self->m_unk3C = 0;
    self->m_unk40 = 0;
    self->m_unk48 = 0;
    X_func_00166DA4(self, 0x64);
    X_func_00166F50(self, self->m_unk14, 10.0f);
    self->m_owner->m_unk150 = 0;
    self->m_unk04 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", HfmOutSlap__vfunc_03);

extern "C" void HfmOutSlap__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void HfmOutBreak__vfunc_02(HfmOutBreak *self)
{
    X_func_00166DA4(self, 0x64);
    self->m_unk04 = 0;
    X_func_0016649C(self->m_owner, 0);
    self->m_owner->m_unk150 = 0;
}

extern "C" int HfmOutBreak__vfunc_03(HfmOutBreak *self)
{
    int state = self->m_unk04;

    switch (state) {
        case 0:
            X_func_001680A0(self, 0x30, 0);
            X_func_001694CC(self, 0x2A);
            self->m_unk04 = 1;
            break;
        case 1:
            if (HfmAnimDone(self, &D_007812C0) != 0) {
                X_func_0016649C(self->m_owner, 1);
                return 7;
            }
            break;
    }
    return -1;
}

extern "C" void HfmOutBreak__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void HfmOutWalk2__vfunc_02(HfmOutWalk2 *self)
{
    X_func_00166DA4(self, 0x64);
    X_func_001680A0(self, 0xC, 0);
    self->m_unk04 = 0;
    func_001469CC(self, 3);
    self->m_owner->m_unk150 = 0;
}

extern "C" int HfmOutWalk2__vfunc_03(HfmOutWalk2 *self)
{
    float sp[4];
    int step;
    int state;
    int r;

    state = self->m_unk04;
    step = self->m_unk38 + 1;
    self->m_unk38 = step;
    switch (state) {
        case 0:
            r = X_func_0010423C(1, 0x5F);
            if (r < 0x51) {
                X_func_00146628(self, sp);
                if (X_func_00169A14(sp) >= 114.9999924f) {
                    X_func_001670DC(self, sp, 0.0f);
                    func_001469CC(self, 1);
                    break;
                }
            }
            func_001468E0(self, r);
            break;
        case 1:
            if (self->m_unk24 != 0) {
                X_func_00202F10(self->m_owner->m_unk1F0);
                func_001469CC(self, 0);
            }
            break;
        case 2:
            if (step >= 0x1E) {
                func_001469CC(self, 0);
            }
            break;
        case 3:
            if (HfmAnimDone(self, &D_007812C0) != 0) {
                func_001469CC(self, 0);
            }
            break;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00146628);

extern "C" void func_001468E0(HfmOutWalk2 *self, int arg1)
{
    if (arg1 < 0x5B) {
        func_00146944(self, 1);
        return func_001469CC(self, 2);
    }
    X_func_001680A0(self, 0xC, 0);
    func_001469CC(self, 3);
}

extern "C" void func_00146944(HfmOutWalk2 *self, int anim)
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

extern "C" void HfmOutWalk2__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void func_001469CC(HfmOutWalk2 *self, int state)
{
    if (self->m_unk04 != state) {
        self->m_unk04 = state;
        self->m_unk38 = 0;
    }
}

extern "C" void HfmOutRide__vfunc_02(HfmOutRide *self)
{
    X_func_00166DA4(self, 0x64);
    self->m_owner->m_unk150 = 0;
    func_00146AE4(self);
}

extern "C" int HfmOutRide__vfunc_03(HfmOutRide *self)
{
    int mode;
    int ret;
    int res;

    mode = self->m_unk40;
    ret = -1;
    switch (mode) {
        case 0:
            res = X_func_00146D88(self);
block_11:
            ret = res;
            break;
        case 1:
            res = X_func_001473E4(self);
            goto block_11;
        case 2:
            res = X_func_00147840(self);
            goto block_11;
        case 3:
            res = func_001484EC(self);
            goto block_11;
    }
    return ret;
}

extern "C" void HfmOutRide__vfunc_04(HfmOutRide *self)
{
    X_func_00166AD0();
    ((HfmMain *)self->m_owner)->m_unk238 = 0;
}

extern "C" void func_00146AE4(HfmOutRide *self)
{
    int off = 0x12540;
    int r;
    int t0;
    int t1;
    int timer;

    self->m_unk3C = 0;
    self->m_unk48 = 0;
    self->m_unk58 = 0;
    self->m_unk5C = X_func_0010423C(0x3C, 0x5A);
    r = X_func_0010423C(0, 0x63);
    if (X_func_0013166C((char *)&D_006E9840 + off, 0x16, 0) != 0) {
        t0 = 0xA;
        t1 = 0x4B;
    } else {
        t0 = 0x14;
        t1 = 0x23;
    }
    if (r < t0) {
        self->m_unk40 = 0;
        timer = X_func_00104394(0xA, 0x96, 3);
        self->m_unk04 = 0;
        self->m_unk38 = timer;
    } else if (r < t1) {
        self->m_unk40 = 1;
        timer = X_func_00104394(0xA, 0x50, 3);
        self->m_unk04 = 0;
        self->m_unk38 = timer;
    } else if (r < 0x55) {
        self->m_unk04 = 0;
        self->m_unk40 = 2;
    } else {
        self->m_unk04 = 0;
        self->m_unk40 = 3;
    }
    X_func_0010423C(0, 0x63);
    X_func_00166F50(self, self->m_unk14, 114.9999924f);
}

extern "C" void func_00146BF0(HfmOutRide *self)
{
    int timer;

    self->m_unk3C = 0;
    self->m_unk48 = 0;
    self->m_unk58 = 0;
    self->m_unk5C = X_func_0010423C(0x3C, 0x5A);
    if (X_func_0010423C(0, 0x63) < 0x4B) {
        self->m_unk40 = 0;
        timer = X_func_00104394(0xA, 0x96, 3);
        self->m_unk04 = 0;
        self->m_unk38 = timer;
    } else {
        self->m_unk40 = 1;
        timer = X_func_00104394(0xA, 0x50, 3);
        self->m_unk04 = 0;
        self->m_unk38 = timer;
    }
    X_func_00166F50(self, self->m_unk14, 114.9999924f);
}

extern "C" void func_00146C8C(HfmOutRide *self, float dist)
{
    struct {
        float vec[4];
        int sp10;
        int sp14;
    } stack;
    char *base;
    char *s1;

    X_func_00166B74(self, stack.vec);
    stack.vec[3] = self->m_unk94;
    X_func_00167D88(self, stack.vec, dist);
    base = (char *)&D_006E9840;
    s1 = base + 0x12540;
    if (X_func_0013166C(s1, 0x15, (int)stack.vec) == 0) {
        X_func_00167D88(self, stack.vec, 30.0f);
        if (X_func_0013166C(s1, 0x15, (int)stack.vec) == 0) {
            X_func_00166C8C(self, stack.vec);
            X_func_0017C340(base + 0x9796C, stack.vec, &stack.sp10, 0, 40.0f, 0.0f);
            if (stack.sp14 != 0) {
                X_func_001D89C4((void *)self->m_unk08, stack.vec);
            }
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF318);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF328);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF338);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF348);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF358);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF368);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF378);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF388);

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00146D88);

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_001473E4);

extern "C" void func_00147760(HfmOutRide *self)
{
    int off = 0x12540;

    X_func_0016947C(self);
    self->m_owner->m_unk150 = 0;
    if (self->m_unk60 == 0) {
        X_func_0013166C((char *)&D_006E9840 + off, 6, 0);
    } else {
        X_func_0013166C((char *)&D_006E9840 + off, 9, 0);
    }
    X_func_001680A0(self, 0x2F, 0);
    ((HfmMain *)self->m_owner)->m_unk238 = 1;
    X_func_001694CC(self, 0x39);
    X_func_0016649C(self->m_owner, 1);
    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
    self->m_unk48 = 0;
    self->m_unk04 = 7;
    {
        EmyMain *owner = self->m_owner;
        self->m_unk84 = 0;
        X_func_0016649C(owner, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00147840);

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00147A28);

extern "C" void func_00147E04(HfmOutRide *self)
{
    if (HfmAnimDone(self, &D_007812C0) == 0) {
        func_00146C8C(self, -3.0f);
        return;
    }
    func_00146C8C(self, -3.0f);
    X_func_001680A0(self, (self->m_unk60 == 0) ? 0x24 : 0x25, 0x100);
    func_00148450(self);
}

extern "C" void func_00147E94(HfmOutRide *self)
{
    if (HfmAnimDone(self, &D_007812C0) != 0) {
        X_func_001680A0(self, (self->m_unk60 == 0) ? 0x24 : 0x25, 0x100);
        func_00148450(self);
    }
}

extern "C" void func_00147F00(HfmOutRide *self)
{
    int sysState;
    int timer;
    int anim;

    X_func_001693EC(self, 5, 0xF, 0x25);
    sysState = X_func_00118FEC(&D_006E9840);
    if (sysState != 9) {
        func_00146C8C(self, -3.0f);
        timer = self->m_unk68 - 1;
        self->m_unk68 = timer;
        self->m_unk64 = self->m_unk64 - 1;
        if (timer <= 0) {
            self->m_unk70 = X_func_0010423C(1, 3);
            if (X_func_0010423C(0, 0x63) < 0x32) {
                self->m_unk74 = 1;
                self->m_unk4C = 0xC;
                anim = 0x28;
            } else {
                self->m_unk74 = 0;
                self->m_unk4C = 0xC;
                anim = 0x26;
            }
            X_func_001680A0(self, anim, 0);
            X_func_0016947C(self);
            X_func_001694CC(self, D_002EF418[X_func_0010423C(0, 4)]);
            X_func_001694CC(self, 0x38);
            self->m_unk04 = 5;
            return;
        }
        if (sysState == 3) {
            X_func_0016947C(self);
            X_func_001680A0(self, (self->m_unk60 == 0) ? 0x21 : 0x22, 0x100);
            self->m_unk04 = 9;
        }
    }
}

extern "C" void func_00148060(HfmOutRide *self)
{
    int frame;
    int left;

    frame = self->m_unk48 + 1;
    self->m_unk48 = frame;
    if (frame == self->m_unk4C) {
        X_func_001694CC(self, 0x10);
        X_func_001FAC60(0xB, self->m_unk00, 0, 0, 0x2B, (unsigned int)self->m_unk14, 0);
        self->m_unk48 = 0;
        left = self->m_unk70 - 1;
        self->m_unk70 = left;
        if (left == 0) {
            self->m_unk04 = 3;
        } else {
            self->m_unk04 = 6;
        }
    }
}

extern "C" void func_001480E0(HfmOutRide *self)
{
    int anim;
    int nextState;

    if (HfmAnimDone(self, &D_007812C0) != 0) {
        if (X_func_00118FEC(&D_006E9840) == 3) {
            X_func_001680A0(self, (self->m_unk60 == 0) ? 0x21 : 0x22, 0x100);
            nextState = 9;
        } else {
            if (self->m_unk74 == 0) {
                anim = 0x28;
                self->m_unk74 = 1;
                self->m_unk4C = 0xC;
            } else {
                self->m_unk74 = 0;
                self->m_unk4C = 0xC;
                anim = 0x26;
            }
            X_func_001680A0(self, anim, 0);
            X_func_0016947C(self);
            X_func_001694CC(self, 0x38);
            nextState = 5;
        }
        self->m_unk04 = nextState;
    }
}

extern "C" void func_001481B8(HfmOutRide *self)
{
    int frame;

    frame = self->m_unk48 + 1;
    self->m_unk48 = frame;
    if ((frame >= 0x29) && (self->m_unk84 == 0)) {
        X_func_001694CC(self, 0x37);
        self->m_unk84 = 1;
    }
    if (HfmAnimDone(self, &D_007812C0) != 0) {
        ((HfmMain *)self->m_owner)->m_unk238 = 0;
        X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
        func_00146AE4(self);
    }
}

extern "C" void func_0014827C(HfmOutRide *self)
{
    int frame;

    frame = self->m_unk48 + 1;
    self->m_unk48 = frame;
    if ((frame >= 0x29) && (self->m_unk84 == 0)) {
        X_func_001694CC(self, 0x37);
        self->m_unk84 = 1;
    }
    if (HfmAnimDone(self, &D_007812C0) != 0) {
        ((HfmMain *)self->m_owner)->m_unk238 = 0;
        func_00146AE4(self);
    }
}

extern "C" void func_00148304(HfmOutRide *self)
{
    if (X_func_00118FEC(&D_006E9840) == 3) {
        if (func_001457F0((HfmMain *)self->m_owner) != 0) {
            return func_00147760(self);
        }
    } else {
        X_func_001680A0(self, (self->m_unk60 == 0) ? 0x24 : 0x25, 0x100);
        func_00148450(self);
    }
}

extern "C" void func_0014837C(HfmOutRide *self)
{
    self->m_unk6C = self->m_unk6C - 1;
    X_func_001693EC(self, 1, 0xA, 0x13);
    if (X_func_00118FEC(&D_006E9840) == 3) {
        if (func_001457F0((HfmMain *)self->m_owner) != 0) {
            X_func_0016947C(self);
            return func_00147760(self);
        }
    } else if (self->m_unk6C <= 0) {
        X_func_0016947C(self);
        X_func_001FAC60(0xB, self->m_unk00, 0, 0, 0x2B, (unsigned int)self->m_unk14, 0);
        X_func_001680A0(self, (self->m_unk60 == 0) ? 0x24 : 0x25, 0x100);
        func_00148450(self);
    }
}

extern "C" int func_00148450(HfmOutRide *self)
{
    int r;

    if (X_func_0010423C(0, 0x63) < 0x1E) {
        self->m_unk04 = 0xA;
        self->m_unk6C = X_func_0010423C(0x14, 0x28);
        return X_func_001680A0(self, 0x23, 0x100);
    }
    self->m_unk04 = 4;
    r = X_func_0010423C(0, 0x63);
    if (r < 0x27) {
        self->m_unk68 = 0x14;
    } else if (r < 0x4F) {
        self->m_unk68 = 0x2D;
    } else {
        self->m_unk68 = 0x4B;
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF3F0);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF3F8);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF400);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF408);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF410);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF418);

extern "C" int func_001484EC(HfmOutRide *self)
{
    struct {
        float vec[4];
        int sp10;
        int sp14;
    } stack;
    int off = 0x8542C;

    switch (self->m_unk04) {
        case 0:
            if (self->m_unk24 != 0) {
                X_func_00202F10(self->m_owner->m_unk1F0);
                if (self->m_unk24 == 2) {
                    return 8;
                }
                X_func_00167D88(self, stack.vec, 98.0f);
                X_func_0017C340((char *)&D_006FBD80 + off, stack.vec, &stack.sp10, 0, 40.0f, 0.0f);
                if (stack.sp14 == 0) {
                    func_00146BF0(self);
                } else {
                    self->m_unk48 = 0;
                    X_func_001680A0(self, 0x18, 0);
                    X_func_001694CC(self, 0x13);
                    self->m_unk04 = 1;
                }
            }
            break;
        case 1:
            X_func_00148620(self);
            break;
        case 2:
            func_00148AF0(self);
            break;
        case 3:
            func_00148BD0(self);
            break;
        case 4:
            func_00148CB4(self);
            break;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", func_00148620);

extern "C" void func_00148A00(HfmOutRide *self)
{
    int off = 0x12540;

    self->m_owner->m_unk150 = 0;
    if (self->m_unk60 == 0) {
        X_func_0013166C((char *)&D_006E9840 + off, 0xB, 0);
    } else {
        X_func_0013166C((char *)&D_006E9840 + off, 0xD, 0);
    }
    X_func_001680A0(self, 0x19, 0);
    X_func_001694CC(self, 0x37);
    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
    X_func_0016649C(self->m_owner, 1);
    self->m_unk48 = 0;
    self->m_unk84 = 0;
    self->m_unk04 = 4;
}

extern "C" void func_00148AF0(HfmOutRide *self)
{
    int sysState;
    int timer;

    if (X_func_001442DC(self->m_unk00) != -1) {
        X_func_00144308(1);
        return func_00148A00(self);
    }
    func_00146C8C(self, 15.0f);
    sysState = X_func_00118FEC(&D_006E9840);
    if (sysState != 9) {
        timer = self->m_unk68 - 1;
        self->m_unk68 = timer;
        if (timer <= 0) {
            self->m_unk48 = 0;
            X_func_001680A0(self, 0x35, 0);
            X_func_001694CC(self, 0x13);
            self->m_unk04 = 3;
            return;
        }
        if (sysState == 3) {
            self->m_unk58 = 0;
            if (func_001457F0((HfmMain *)self->m_owner) != 0) {
                func_00148A00(self);
            }
        }
    }
}

extern "C" void func_00148BD0(HfmOutRide *self)
{
    int frame;

    frame = self->m_unk48 + 1;
    self->m_unk48 = frame;
    if (frame == 0x12) {
        X_func_00180EA8(&D_007B2580, self->m_unk2C);
        X_func_001694CC(self, 0x10);
        if (self->m_unk60 == 0) {
            X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x29, (unsigned int)self->m_unk14, 0);
        } else {
            X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x2A, (unsigned int)self->m_unk14, 0);
        }
        self->m_unk68 = X_func_0010423C(0x14, 0x28);
    }
    if (HfmAnimDone(self, &D_007812C0) != 0) {
        X_func_001680A0(self, 0x1A, 0x100);
        self->m_unk48 = 0;
        self->m_unk04 = 2;
    }
}

extern "C" void func_00148CB4(HfmOutRide *self)
{
    int frame = self->m_unk48 + 1;
    self->m_unk48 = frame;
    if ((frame > 0) && (self->m_unk84 == 0)) {
        X_func_001694CC(self, 0x37);
        self->m_unk84 = 1;
    }
    if (HfmAnimDone(self, &D_007812C0) != 0) {
        func_00146AE4(self);
    }
}

// NON_MATCHING: 2/70 differ (addiu $a1,$sp,0x10 vs addiu $v1,$zero,3 scheduling), 2 edits
#ifdef NON_MATCHING
struct HfmVec4 {
    long long xy;
    int z;
    int w;
};
struct HfmEffParam {
    int m_kind;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    HfmVec4 m_pos;
    float m_rot[3];
    int m_num;
    int m_pad[20];
};
extern "C" void HfmOutDead__vfunc_02(HfmOutDead *self)
{
    HfmVec4 vec;
    HfmEffParam param;
    int off = 0x837E0;

    X_func_001DA228((void *)self->m_unk08, 5, &vec);
    {
        float f1 = -1.0f;
        register int z PS2_REG("$6") = vec.z;
        register long long xy PS2_REG("$7") = vec.xy;
        float f0 = 100.0f;
        register int kind PS2_REG("$3") = 3;

        param.m_pos.z = z;
        param.m_kind = kind;
        param.m_pos.xy = xy;
        param.m_rot[0] = f1;
        param.m_rot[2] = f0;
    }
    param.m_num = 0x5A;
    param.m_pos.w = 0;
    param.m_rot[1] = 0.0f;
    param.m_unk08 = 0;
    X_func_00176CC8((char *)&D_006FBD80 + off, &param);
    self->m_owner->m_unk0C = 0;
    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
    X_func_001680A0(self, 0x31, 0x100);
    X_func_00165570(self->m_owner);
    self->m_owner->m_unk150 = 0;
    ((EmyObjStatView *)self->m_unk08)->m_flags |= 0x400;
    ((EmyObjStatView *)self->m_unk08)->m_flags |= 0x2000;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", HfmOutDead__vfunc_02);
#endif

extern "C" int HfmOutDead__vfunc_03(void)
{
    return -1;
}

extern "C" void HfmOutDead__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void HfmOutWin__vfunc_02(HfmOutWin *self)
{
    self->m_unk38 = X_func_001044B8(114.99999237060547f, 172.49998474121094f);
    X_func_00166DA4(self, 0x64);
    X_func_00166F50(self, self->m_unk14, self->m_unk38);
    self->m_unk04 = 0;
    self->m_owner->m_unk150 = 0;
}

extern "C" int HfmOutWin__vfunc_03(HfmOutWin *self)
{
    if ((self->m_unk04 == 0) && (self->m_unk24 != 0)) {
        X_func_00202F10(self->m_owner->m_unk1F0);
        X_func_001680A0(self, 0x16, 0x100);
        self->m_unk04 = 1;
    }
    return -1;
}

extern "C" void HfmOutWin__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void HfmOutBitten__vfunc_02(HfmOutBitten *self)
{
    self->m_unk04 = 0;
    X_func_001680A0(self, 0xD, 0x100);
}

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", HfmOutBitten__vfunc_03);

extern "C" void HfmOutBitten__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void HfmOutCounter__vfunc_02(HfmOutCounter *self)
{
    self->m_owner->m_unk150 = 0;
    X_func_001680A0(self, 0x34, 0);
    X_func_001694CC(self, 0x13);
    self->m_unk38 = 0;
    self->m_unk04 = 0;
    X_func_0016649C(self->m_owner, 0);
    self->m_unk40 = 0;
    self->m_unk3C = 0;
    X_func_00166DA4(self, 0x64);
}

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", HfmOutCounter__vfunc_03);

extern "C" void HfmOutCounter__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void HfmOutTest__vfunc_02(HfmOutTest *self)
{
    self->m_unk04 = 0;
    X_func_001680A0(self, 0x10, 0);
    self->m_owner->m_unk150 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF448);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF450);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF458);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF460);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF468);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF470);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF480);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF490);

INCLUDE_RODATA("asm/nonmatchings/unk/HfmMain", D_002EF4A0);

INCLUDE_ASM("asm/nonmatchings/unk/HfmMain", HfmOutTest__vfunc_03);
