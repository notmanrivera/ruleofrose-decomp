#include "include_asm.h"
#include "emy/emy.h"

struct MrtMain : public EmyMain {
    unsigned char m_unk204;             // +0x204
    unsigned char m_pad205[0x03];       // +0x205..+0x207
    int m_stateActive[12];              // +0x208..+0x237
    unsigned char m_unk238;             // +0x238
};

struct MrtOutAtk : public EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
};

struct MrtOutWin : public EmyOut {
    float m_unk38;                      // +0x38
};

struct MrtMainVtbl2 {
    unsigned char m_pad[0x200];
    virtual void v1();
    virtual int v2();
};

struct MrtOutVtbl3 {
    unsigned char m_pad[0x34];
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct MrtOutVtbl4 {
    unsigned char m_pad[0x34];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};

struct MrtVtblEntry {
    short m_delta;
    short m_index;
    void *m_fn;
};

struct MrtStateTable {
    unsigned char m_unk00;              // +0x00
    unsigned char m_count;              // +0x01
    unsigned char m_pad02[0x0A];        // +0x02..+0x0B
    signed char *m_matrix;              // +0x0C
};

struct MrtPadBits {
    unsigned short m_pad : 12;
    unsigned short m_b12 : 1;
};

extern int vtbl_MrtMain asm("_vt$7MrtMain");
extern int vtbl_MrtOutSerch asm("_vt$11MrtOutSerch");
extern int vtbl_MrtOutAtk asm("_vt$9MrtOutAtk");
extern int vtbl_MrtOutWin asm("_vt$9MrtOutWin");
extern MrtPadBits D_006E98FA;
extern void *D_007A3350;

extern "C" void *X___builtin_new(int) asm("__builtin_new");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_EmyMain__vfunc_01(EmyMain *, int) asm("EmyMain__vfunc_01");
extern "C" float X_func_001044B8(float, float) asm("func_001044B8");
extern "C" int X_func_0014D51C(EmyOut *) asm("func_0014D51C");
extern "C" int X_func_0014D598(EmyOut *) asm("func_0014D598");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" void X_func_00166A1C(EmyOut *, int, void *, EmyMain *) asm("func_00166A1C");
extern "C" void X_func_00166AD0_v(...) asm("func_00166AD0");
extern "C" void X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" int X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" int X_func_001679B4(EmyOut *, int, int, float, float) asm("func_001679B4");
extern "C" void X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_00169BAC(int, int, void *, float, float) asm("func_00169BAC");

extern "C" void func_0014CDE4(MrtMain *self)
{
    *(int *)((char *)self + 0xEC) = 1;
    *(int *)((char *)self + 0xF0) = 1;
    *(int *)((char *)self + 0xF8) = 7;
    *(int *)((char *)self + 0x108) = 7;
    *(int *)((char *)self + 0xF4) = 3;
    self->m_unk204 = 0;

    EmyOut *o1 = (EmyOut *)X___builtin_new(0x3C);
    X_func_00166A1C(o1, self->m_id, self->m_objStat, self);
    o1->m_vtbl = &vtbl_MrtOutSerch;
    *(EmyOut **)((char *)self + 0x50) = o1;

    EmyOut *o2 = (EmyOut *)X___builtin_new(0x3C);
    X_func_00166A1C(o2, self->m_id, self->m_objStat, self);
    o2->m_vtbl = &vtbl_MrtOutSerch;
    *(EmyOut **)((char *)self + 0x54) = o2;

    EmyOut *o3 = (EmyOut *)X___builtin_new(0x50);
    X_func_00166A1C(o3, self->m_id, self->m_objStat, self);
    o3->m_vtbl = &vtbl_MrtOutAtk;
    *(EmyOut **)((char *)self + 0x58) = o3;

    EmyOut *o4 = (EmyOut *)X___builtin_new(0x3C);
    X_func_00166A1C(o4, self->m_id, self->m_objStat, self);
    o4->m_vtbl = &vtbl_MrtOutWin;
    *(EmyOut **)((char *)self + 0x4C) = o4;

    self->m_unk204 = 0;
    self->m_unk238 = 0;
}

extern "C" void MrtMain__vfunc_01(MrtMain *self, int flags)
{
    self->m_vtbl = &vtbl_MrtMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtMain__vfunc_04);

#ifdef NON_MATCHING
extern "C" void MrtMain__vfunc_05(MrtMain *self)
{
    self->m_stateChanged = 0;
    if (self->m_flags30 & 2) {
        self->m_flags30 = 0;
        self->m_stateChanged = 1;
    } else {
        int next = self->m_nextState;
        if (next != -1) {
            self->m_flags30 = 0;
            int st = X_func_0016968C(self->m_brain, next);
            if (st >= 6) {
                st = 0;
            }
            if (st < 0) {
                st = 0;
            }
            if (st != 0) {
                self->m_curState = st;
                self->m_stateChanged = 1;
                self->m_unk204 = 0;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtMain__vfunc_05);
#endif

extern "C" void MrtMain__vfunc_06(MrtMain *self)
{
    if (self->m_stateChanged != 0) {
        ((MrtOutVtbl4 *)self->m_curOut)->v4();
        ((MrtMainVtbl2 *)self)->v2();
    }
    self->m_nextState = ((MrtOutVtbl3 *)self->m_curOut)->v3();
}

extern "C" int MrtMain__vfunc_02(MrtMain *self)
{
    int v = self->m_curState;
    if (v != 0) {
        if (v >= 0) {
            if (v < 5) {
                EmyOut *obj = ((EmyOut **)self->m_unk48)[v];
                self->m_curOut = obj;
                MrtVtblEntry *vt = (MrtVtblEntry *)obj->m_vtbl + 2;
                ((void (*)(char *))vt->m_fn)((char *)obj + vt->m_delta);
            }
        }
    }
    int i = 0;
    register MrtStateTable *e8 PS2_REG("$3") = (MrtStateTable *)self->m_unkE8;
    int count = e8->m_count;
    register int v2 PS2_REG("$2") = self->m_curState;
    register signed char *base PS2_REG("$7") = e8->m_matrix + (v2 * count);
    for (; i < count; i++) {
        int *dst = (int *)((char *)self + 8);
        if (base[i] != 0) {
            *(int *)((char *)(dst + i) + 0x200) = 1;
        } else {
            *(int *)((char *)(dst + i) + 0x200) = 0;
        }
    }
    return 0;
}

// NON_MATCHING: 3/7 differ (size 0x1C, game 0x18), 2 edits
#ifdef NON_MATCHING
extern "C" bool func_0014D308(void)
{
    unsigned long long bit = D_006E98FA.m_b12;
    return bit != 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", func_0014D308);
#endif

extern "C" int func_0014D320()
{
    return 0;
}

extern "C" int func_0014D328()
{
    return X_func_00165A68();
}

extern "C" int func_0014D33C()
{
    return X_func_00165AA8();
}

extern "C" int func_0014D350()
{
    return X_func_00165D7C();
}

extern "C" int func_0014D364()
{
    return 0;
}

extern "C" int func_0014D36C()
{
    return 0;
}

extern "C" int func_0014D374()
{
    return 0;
}

extern "C" int func_0014D37C()
{
    return 0;
}

extern "C" int func_0014D384(MrtMain *self)
{
    int target = 0;
    if (D_007A3350 != 0) {
        target = *(int *)((char *)D_007A3350 + 0x100);
    }
    return X_func_00169BAC(1, target, self->m_objStat, 10.0f, 6.283185124397278f);
}

extern "C" void MrtOutYyy__vfunc_02(EmyOut *self)
{
    X_func_00166DA4(self, 0x64);
    self->m_unk04 = 0;
}

extern "C" int MrtOutYyy__vfunc_03()
{
    return -1;
}

extern "C" void MrtOutYyy__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" int MrtOutSerch__vfunc_02(EmyOut *self)
{
    switch (self->m_owner->m_curState) {
    case 2:
        X_func_00166DA4(self, 0);
        return X_func_00166F50(self, self->m_unk14, 10.0f);
    case 3:
        X_func_00166DA4(self, 0x64);
        return X_func_00166F50(self, self->m_unk14, 10.0f);
    }
}

extern "C" int MrtOutSerch__vfunc_03(EmyOut *self)
{
    int ret = -1;
    switch (self->m_owner->m_curState) {
    case 2:
        ret = X_func_0014D51C(self);
        break;
    case 3:
        ret = X_func_0014D598(self);
        break;
    }
    return ret;
}

extern "C" void MrtOutSerch__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" int func_0014D51C(EmyOut *self)
{
    int ret = -1;
    switch (X_func_001679B4(self, self->m_unk14, 0, 100.0f, 3.1415926218032837f)) {
    case 0:
        break;
    case 1:
        ret = 1;
        break;
    case 2:
        ret = 0;
        break;
    }
    return ret;
}

extern "C" int func_0014D598(EmyOut *self)
{
    int ret = -1;
    switch (X_func_001679B4(self, self->m_unk14, 0, 100.0f, 3.1415926218032837f)) {
    case 0:
        break;
    case 1:
        ret = 1;
        break;
    case 2:
        ret = 0;
        break;
    }
    return ret;
}

extern "C" void MrtOutAtk__vfunc_02(MrtOutAtk *self)
{
    X_func_00166DA4(self, 0x64);
    self->m_unk38 = 0;
    self->m_unk3C = 0;
    X_func_00166F50(self, self->m_unk14, 10.0f);
    self->m_unk04 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF750);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF760);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF770);

INCLUDE_ASM("asm/nonmatchings/unk/MrtMain", MrtOutAtk__vfunc_03);

extern "C" void MrtOutAtk__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" void MrtOutWin__vfunc_02(MrtOutWin *self)
{
    self->m_unk38 = X_func_001044B8(100.0f, 200.0f);
    X_func_00166F50(self, self->m_unk14, 10.0f);
    self->m_unk04 = 0;
}

extern "C" int MrtOutWin__vfunc_03(MrtOutWin *self)
{
    if ((self->m_unk04 == 0) && (X_func_001679B4(self, self->m_unk14, 1, self->m_unk38, 0.7853981405496597f) != 0)) {
        X_func_001680A0(self, 0x15, 0x100);
        self->m_unk04 = 1;
    }
    return -1;
}

extern "C" void MrtOutWin__vfunc_04()
{
    X_func_00166AD0_v();
}

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF798);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7A0);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7A8);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7B0);

INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7B8);
INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7C8);
INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7D8);
INCLUDE_RODATA("asm/nonmatchings/unk/MrtMain", D_002EF7E8);
