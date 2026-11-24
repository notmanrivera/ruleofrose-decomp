#include "include_asm.h"
#include "unk/NorMain.h"
#include "game/gamman.h"
#include "game/gamtrg.h"
extern "C" int func_0010423C(int, int);
extern "C" int func_001442DC(int);
extern "C" int func_00151218(NorMain *);
extern "C" int func_0015122C(NorMain *);
extern "C" int func_0015130C(NorMain *);
extern "C" int func_00151314(NorMain *);
extern "C" int func_00151328(NorMain *);
extern "C" void func_001D10D0(void *, int, int);
extern "C" void func_001D1410(void *, int, int);
extern "C" void func_001DA228(void *, int, void *);
extern "C" int func_00169BAC(float, float, int, int, void *);
extern "C" void func_001CB460(void *, int, unsigned short *);
struct NorStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[10];
    signed char *m_table;
};

struct NorMainVtbl2 {
    unsigned char m_pad[0x200];
    virtual void v1();
    virtual int v2();
};

struct NorOutVtbl3 {
    unsigned char m_pad[0x34];
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct NorOutVtbl4 {
    unsigned char m_pad[0x34];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};

struct NorActorVtbl17 {
    unsigned char m_pad[0x94];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual int getNodePos(void *, int);
};

extern int vtbl_NorMain asm("_vt$7NorMain");
extern int D_006FE6A0;

extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_EmyMain__vfunc_01(EmyMain *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_00166108(...) asm("func_00166108");
extern "C" int X_func_00166198(...) asm("func_00166198");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_0022B3D8(void *, const char *) asm("func_0022B3D8");

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_00150B24);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EF9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EF9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EFA00);

extern "C" void NorMain__vfunc_01(NorMain *self, int flags)
{
    self->m_vtbl = &vtbl_NorMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return X___builtin_delete(self);
    }
}

extern "C" void NorMain__vfunc_04(NorMain *self)
{
    if (self->m_unk28 != 0 && self->m_nextState == -1) {
        if (self->m_unk218 != 0 && func_0015122C(self) != 0) {
            self->m_nextState = 5;
            return;
        }
        if (self->m_unk220 != 0 && func_00151314(self) != 0) {
            self->m_nextState = 7;
        }
        if (self->m_unk21C != 0 && func_0015130C(self) != 0) {
            self->m_nextState = 6;
        }
        if (self->m_unk204[4] != 0 && func_00151218(self) != 0) {
            self->m_nextState = 4;
        }
        if (self->m_unk204[3] != 0 && (self->m_flags30 & 0x11) == 1) {
            self->m_unk238++;
            const int table[6] = { 0, 50, 30, 40, 60, 100 };
            if (func_0010423C(0, 0x63) < table[self->m_unk238]) {
                self->m_unk238 = 0;
                self->m_nextState = 3;
                return;
            }
        }
        if (self->m_unk204[2] != 0 && func_001442DC(self->m_id) != -1) {
            self->m_unk248 = func_0010423C(0x1E, 0x3C);
            self->m_nextState = 2;
        }
        int seen = func_00151328(self);
        if (self->m_unk22C != 0) {
            self->m_unk22C = seen;
            if (self->m_unk22C == 0 && self->m_unk204[1] != 0) {
                self->m_nextState = 1;
            }
        } else {
            self->m_unk22C = seen;
            if (self->m_unk22C != 0 && self->m_unk204[0] != 0) {
                self->m_nextState = 0;
            }
        }
    }
}

extern "C" void NorMain__vfunc_05(NorMain *self)
{
    self->m_stateChanged = 0;
    int flags = self->m_flags30;
    if (flags & 2) {
        self->m_curState = 4;
        ((EmyBrainView *)self->m_brain)->m_state = 4;
        self->m_stateChanged = 1;
        self->m_flags30 = 0;
    } else {
        int next = self->m_nextState;
        if (next != -1) {
            int st = X_func_0016968C(self->m_brain, next);
            self->m_unk22C = 0;
            if (st != 0) {
                self->m_curState = st;
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

extern "C" void NorMain__vfunc_06(NorMain *self)
{
    if (self->m_stateChanged != 0) {
        ((NorOutVtbl4 *)self->m_curOut)->v4();
        ((NorMainVtbl2 *)self)->v2();
    }
    self->m_nextState = ((NorOutVtbl3 *)self->m_curOut)->v3();
}

extern "C" int NorMain__vfunc_02(NorMain *self)
{
    NorStateTable *tbl;
    unsigned char count;
    signed char *base;
    int cur;

    tbl = (NorStateTable *)self->m_unkE8;
    count = tbl->m_count;
    base = tbl->m_table;
    base += self->m_curState * count;
    for (int i = 0; i < count; ++i) {
        if (base[i] != 0) {
            self->m_unk204[i] = 1;
        } else {
            self->m_unk204[i] = 0;
        }
    }
    cur = self->m_curState;
    if (cur != 0) {
        if (cur >= 0) {
            if (cur < 9) {
                EmyOut *obj = self->m_unk48[cur];
                self->m_curOut = obj;
                ((NorOutVtbl3 *)obj)->v2();
            }
        }
    }
    return 0;
}

extern "C" int func_00151218(NorMain *)
{
    return X_func_00166108();
}

extern "C" int func_0015122C(NorMain *self)
{
    unsigned short sp0;
    int ret = 0;

    func_001CB460(&D_007812C0, 0x1B, &sp0);
    if (self->m_unk230 != 0) {
        return 0;
    }
    register int max PS2_REG("$2") = self->m_unk234;
    int half = max >> 1;
    if ((int)sp0 < half || self->m_unk1E8 >= 0xE11 || self->m_unk23C >= 4) {
        ((EmyObjStatView *)self->m_objStat)->m_flags |= 0x400;
        self->m_unk1E4 = 6;
        self->m_unk230 = 1;
        ret = 1;
    }
    if (self->m_unk230 == 0) {
        func_001D10D0(&D_007812C0, self->m_id, 0x800);
    } else {
        func_001D1410(&D_007812C0, self->m_id, 0x800);
    }
    return ret;
}

extern "C" int func_0015130C(NorMain *)
{
    return 0;
}

extern "C" int func_00151314(NorMain *)
{
    return X_func_00166198();
}

extern "C" int func_00151328(NorMain *self)
{
    float dist;
    int oid;
    int r1;
    int r2;

    func_001DA228(self->m_objStat, 0x5F, &dist);
    if (D_007812C0.m_pc != 0) {
        oid = D_007812C0.m_pc->m_oid;
    } else {
        oid = 0;
    }
    r1 = func_00169BAC(dist, 3.1415926f, 1, oid, self->m_objStat);
    if (D_007812C0.m_dog != 0) {
        oid = D_007812C0.m_dog->m_oid;
    } else {
        oid = 0;
    }
    r2 = func_00169BAC(dist, 3.1415926f, 1, oid, self->m_objStat);
    return (r1 != 0) | (r2 != 0);
}

extern "C" int func_001513EC(NorMain *self)
{
    int t = self->m_unk1E8 - 1000;
    if (t < 0) {
        return 0;
    }
    if (t == 0) {
        return 1;
    }
    return (t % 700) < 200;
}

extern "C" int func_00151424(NorMain *self)
{
    int v = self->m_unk244 + 1;
    self->m_unk244 = v;
    return self->m_unk240 < v;
}

extern "C" void func_0015143C(NorMain *self, int val)
{
    self->m_unk240 = val;
    self->m_unk244 = 0;
}

extern "C" int func_00151448(NorMain *self)
{
    int v = self->m_unk248 - 1;
    self->m_unk248 = v;
    return (unsigned int)~v >> 0x1F;
}

// NON_MATCHING: 30/43 differ, 1 reloc differs (size 0xAC, game 0xA8), 10 edits
#ifdef NON_MATCHING
extern "C" int NorMain__vfunc_07(NorMain *self)
{
    unsigned short sp0;
    int flag;

    func_001CB460(&D_007812C0, 0x1B, &sp0);
    flag = (int)sp0 < ((self->m_unk234 * 3) >> 2);
    if (self->m_unk1E8 >= 0xE11) {
        flag = 1;
    }
    func_001DA228(self->m_objStat, 0x1B, &sp0);
    if (sp0 < ((unsigned int)self->m_unk236 >> 1)) {
        flag = 1;
    }
    if (self->m_unk230 != 0 || flag == 0) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_07);
#endif

extern "C" void func_00151508(NorMain *self)
{
    struct { char pad0[64]; } stack;
    int actorId = ((EmyObjStatView *)self->m_objStat)->m_actorId;
    if (actorId >= 0) {
        const char *name = "p_hit";
        char *actor = (char *)&D_006FE6A0 + (actorId * 0x4D0);
        if (*(void **)(actor + 0x11C) == 0) {
            ror_assert("dog/dogmodel.h", 0x131, "m_i3r_root");
        }
        if (name == 0) {
            ror_assert("dog/dogmodel.h", 0x131, "p");
        }
        int idx = X_func_0022B3D8(*(void **)(actor + 0x11C), name);
        if (idx >= 0) {
            ((NorActorVtbl17 *)actor)->getNodePos(&stack, idx);
        }
    }
}
