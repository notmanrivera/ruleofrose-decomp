#include "include_asm.h"
#include "unk/NorMain.h"

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

extern "C" void NorMain__vfunc_01(NorMain *self, int flags)
{
    self->m_vtbl = &vtbl_NorMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_04);

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

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_02);

extern "C" int func_00151218()
{
    return X_func_00166108();
}

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_0015122C);

extern "C" int func_0015130C()
{
    return 0;
}

extern "C" int func_00151314()
{
    return X_func_00166198();
}

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", func_00151328);

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

INCLUDE_ASM("asm/nonmatchings/unk/NorMain", NorMain__vfunc_07);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EF9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EF9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EFA00);

INCLUDE_RODATA("asm/nonmatchings/unk/NorMain", D_002EFA08);

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
