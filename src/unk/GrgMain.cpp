#include "include_asm.h"
#include "emy/emy.h"
struct GrgOutWalk;
extern const signed char D_002F0410[][3];
extern "C" int func_0015582C(GrgOutWalk *);
extern "C" int func_00155BB4(GrgOutWalk *);

struct GrgVtblEntry {
    short m_delta;
    short m_pad;
    int m_fn;
};

struct GrgStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[0xA];
    signed char *m_table;
};

struct GrgGlobalB {
    unsigned char m_pad00[0x14C];
    int m_unk14C;
    int m_unk150;
    int m_unk154;
};

struct GrgGlobalA {
    unsigned char m_pad00[0xDC1C];
    GrgGlobalB *m_unkDC1C;
};

struct GrgWrdActor {
    unsigned char m_pad00[0x100];
    void *m_objStat100;
};

struct GrgWrdGlobal {
    unsigned char m_pad00[0x22090];
    GrgWrdActor *m_unk22090;
    GrgWrdActor *m_unk22094;
};

struct GrgAreaInfo {
    int m_id;
    int m_unk04[5];
    float m_unk18;
    int m_unk1C;
};

struct GrgMain : EmyMain {
    int m_unk204[0x0C];                 // +0x204..+0x233
    unsigned char m_unk234;             // +0x234
    unsigned char m_unk235;             // +0x235
    signed char m_unk236;               // +0x236
    unsigned char m_unk237;             // +0x237
    int m_unk238;                       // +0x238
    int m_unk23C;                       // +0x23C
    int m_unk240;                       // +0x240
};
STATIC_ASSERT(sizeof(GrgMain) == 0x244, GrgMain_size);

struct GrgOutCatch : EmyOut {
};

struct GrgOutBitten : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
};
STATIC_ASSERT(sizeof(GrgOutBitten) == 0x40, GrgOutBitten_size);

struct GrgOutDisappear : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    int m_unk44;                        // +0x44
    int m_unk48;                        // +0x48
};
STATIC_ASSERT(sizeof(GrgOutDisappear) == 0x4C, GrgOutDisappear_size);

struct GrgOutEvent : EmyOut {
};

struct GrgOutWalk : EmyOut {
    signed char m_unk38;                // +0x38
    signed char m_unk39;                // +0x39
    short m_unk3A;                      // +0x3A
};
STATIC_ASSERT(sizeof(GrgOutWalk) == 0x3C, GrgOutWalk_size);

struct GrgOutTest : EmyOut {
};

extern int vtbl_GrgMain asm("_vt$7GrgMain");

extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_EmyMain__vfunc_01(EmyMain *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" int X_func_00118FEC(void *) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_00154408(GrgMain *) asm("func_00154408");
extern "C" int X_func_00154668(...) asm("func_00154668");
extern "C" int X_func_00154E20(GrgOutDisappear *) asm("func_00154E20");
extern "C" short X_func_0015558C(GrgOutWalk *) asm("func_0015558C");
extern "C" int X_func_00155648(GrgOutWalk *) asm("func_00155648");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" int X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" int X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_00169BAC(float, float, int, void *, void *) asm("func_00169BAC");
extern "C" int X_func_001C6CCC(void *, int, void *) asm("func_001C6CCC");
extern "C" int X_func_001D19A8(void *, int) asm("func_001D19A8");
extern "C" int X_func_001D23F8(void *, int, int) asm("func_001D23F8");
extern "C" int X_func_001D890C(void *, void *) asm("func_001D890C");
extern "C" int X_func_001DA228(void *, int, void *) asm("func_001DA228");

extern int D_006E9840;
extern GrgWrdGlobal D_007812C0;
extern GrgGlobalA D_007A4440;
extern GrgGlobalB *D_007B205C;

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00153E40);

extern "C" void GrgMain__vfunc_01(GrgMain *self, int flags)
{
    self->m_vtbl = &vtbl_GrgMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return Xv___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgMain__vfunc_04);

extern "C" void GrgMain__vfunc_05(GrgMain *self)
{
    int next;
    int res;

    self->m_stateChanged = 0;
    next = self->m_nextState;
    if (next != -1) {
        self->m_flags30 = 0;
        res = X_func_0016968C(self->m_brain, next);
        self->m_unk236 = 0;
        if (res != 0) {
            self->m_curState = res;
            self->m_stateChanged = 1;
            return;
        }
        ((EmyBrainView *)self->m_brain)->m_state = self->m_curState;
    }
}

extern "C" void GrgMain__vfunc_06(GrgMain *self)
{
    int val;
    int pos[4];
    int neg1;
    EmyOut *curOut;
    GrgVtblEntry *vt;

    X_func_001DA228(self->m_objStat, 8, &val);
    D_007A4440.m_unkDC1C->m_unk150 = val;
    X_func_001D890C(self->m_objStat, pos);
    neg1 = -1;
    D_007A4440.m_unkDC1C->m_unk154 = neg1;
    if (self->m_stateChanged != 0) {
        curOut = self->m_curOut;
        vt = (GrgVtblEntry *)((char *)curOut->m_vtbl + 0x20);
        ((void (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
        vt = (GrgVtblEntry *)((char *)self->m_vtbl + 0x10);
        ((void (*)(void *))vt->m_fn)((char *)self + vt->m_delta);
    }
    curOut = self->m_curOut;
    vt = (GrgVtblEntry *)((char *)curOut->m_vtbl + 0x18);
    self->m_nextState = ((int (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
}

extern "C" int GrgMain__vfunc_02(GrgMain *self)
{
    int v;
    EmyOut *obj;
    GrgVtblEntry *vt;
    register GrgStateTable *tbl PS2_REG("$3");
    int count;
    register signed char *base PS2_REG("$7");
    register int v2 PS2_REG("$2");
    int i;
    int *dst;

    v = self->m_curState;
    if (v != 0) {
        if (v >= 0) {
            if (v < 7) {
                obj = ((EmyOut **)self->m_unk48)[v];
                self->m_curOut = obj;
                vt = (GrgVtblEntry *)((char *)obj->m_vtbl + 0x10);
                ((void (*)(void *))vt->m_fn)((char *)obj + vt->m_delta);
            }
        }
    }
    i = 0;
    tbl = (GrgStateTable *)self->m_unkE8;
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

extern "C" int func_00154408(GrgMain *self)
{
    int a;
    int b;

    if (D_007812C0.m_unk22090 == 0) {
        return 0;
    }
    X_func_001C6CCC(&D_007812C0, 5, &a);
    X_func_001DA228(self->m_objStat, 8, &b);
    return a == b;
}

extern "C" int func_00154474(GrgMain *self)
{
    int a;
    int b;

    X_func_001C6CCC(&D_007812C0, 5, &a);
    X_func_001DA228(self->m_objStat, 8, &b);
    return a == b;
}

extern "C" int func_001544C8(void)
{
    return 0;
}

extern "C" int func_001544D0(GrgMain *self)
{
    int a;
    int b;

    if (self->m_unk234 != 0) {
        return 0;
    }
    X_func_001C6CCC(&D_007812C0, 5, &a);
    if (a == 0x81) {
        self->m_unk234 = 1;
        return 1;
    }
    if (self->m_unk237 >= 0x10) {
        X_func_001DA228(self->m_objStat, 8, &b);
        if (b != a) {
            if (X_func_00118FEC(&D_006E9840) != 10) {
                self->m_unk234 = 1;
                return 1;
            }
        }
    }
    return 0;
}

extern "C" int func_00154584(GrgMain *self)
{
    int a;
    int b;
    float dist;
    void *obj;

    if (self->m_unk234 == 0) {
        return 0;
    }
    if (self->m_unk238 == 2 || self->m_unk238 == 3) {
        return 0;
    }
    X_func_001C6CCC(&D_007812C0, 5, &a);
    X_func_001DA228(self->m_objStat, 8, &b);
    if (a == b) {
        if (self->m_unk238 == 1) {
            X_func_001DA228(self->m_objStat, 0x5F, &dist);
            obj = (D_007812C0.m_unk22090 != 0) ? D_007812C0.m_unk22090->m_objStat100 : 0;
            if (X_func_00169BAC(dist, 3.1415926218032837f, 1, obj, self->m_objStat) != 0) {
                self->m_unk234 = 0;
                return 1;
            }
        } else {
            self->m_unk234 = 0;
            return 1;
        }
    }
    return 0;
}

extern "C" int func_00154668(GrgMain *self)
{
    float dist;
    void *obj0;
    void *obj1;
    int r0;
    int r1;

    if (X_func_00154408(self) == 0) {
        return 0;
    }
    X_func_001DA228(self->m_objStat, 0x5F, &dist);
    obj0 = (D_007812C0.m_unk22090 != 0) ? D_007812C0.m_unk22090->m_objStat100 : 0;
    r0 = X_func_00169BAC(dist, 3.1415926218032837f, 1, obj0, self->m_objStat);
    obj1 = (D_007812C0.m_unk22094 != 0) ? D_007812C0.m_unk22094->m_objStat100 : 0;
    r1 = X_func_00169BAC(dist, 3.1415926218032837f, 1, obj1, self->m_objStat);
    return (r0 != 0) | (r1 != 0);
}

extern "C" int func_00154734(void)
{
    return X_func_00154668();
}

extern "C" void func_00154748(GrgMain *self)
{
    EmyObjStatView *stat0;
    EmyObjStatView *stat1;

    stat0 = (EmyObjStatView *)self->m_objStat;
    stat0->m_flags &= 0xEFFFFFFF;
    stat1 = (EmyObjStatView *)self->m_objStat;
    stat1->m_flags &= ~0x80;
    self->m_unk240 = 1;
}

extern "C" void GrgOutCatch__vfunc_02(GrgOutCatch *self)
{
    D_007B205C->m_unk14C = 1;
    X_func_001D23F8(&D_007812C0, self->m_unk00, 0);
    X_func_00166DA4(self, 0x64);
    X_func_00166F50(self, self->m_unk14, 10.0f);
    self->m_unk04 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutCatch__vfunc_03);

extern "C" void GrgOutCatch__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void GrgOutBitten__vfunc_02(GrgOutBitten *self)
{
    int rnd;

    D_007B205C->m_unk14C = 1;
    rnd = X_func_0010423C(0x3C, 0xB4);
    self->m_unk38 = 1;
    self->m_unk3C = rnd;
    X_func_001680A0(self, 0x13, 0x100);
    self->m_unk04 = 0;
}

extern "C" int GrgOutBitten__vfunc_03(GrgOutBitten *self)
{
    int ret = -1;

    switch (self->m_unk04) {
        case 0:
            if (--self->m_unk3C != 0) {
                return -1;
            }
            X_func_001680A0(self, self->m_unk38 == 0 ? 0x16 : 0x14, 0);
            self->m_unk04 = 1;
            break;
        case 1: {
            int res = X_func_001D19A8(&D_007812C0, self->m_unk00);
            if (res != 0) {
                ret = 9;
            }
            if (res != 0) {
                self->m_owner->m_unk2C = 1;
            }
            break;
        }
    }
    return ret;
}

extern "C" void GrgOutBitten__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void GrgOutDisappear__vfunc_02(GrgOutDisappear *self)
{
    int res;

    D_007B205C->m_unk14C = 1;
    X_func_001D23F8(&D_007812C0, self->m_unk00, 1);
    self->m_unk3C = 0;
    X_func_001C6CCC(&D_007812C0, 5, &self->m_unk44);
    self->m_unk48 = 0;
    res = X_func_00154E20(self);
    self->m_unk04 = 0;
    self->m_unk40 = res;
}

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutDisappear__vfunc_03);

// D_002EFBC8..D_002EFC48: the end of unk/NorOutAttack's .rodata now (config/splits_manual.tsv)

extern "C" int func_00154D78(void)
{
    GrgAreaInfo info;

    X_func_001C6CCC(&D_007812C0, 5, &info);
    switch (info.m_id) {
        case 0x88:
            return 3;
        case 0x87:
            return 4;
        case 0x89:
            if (info.m_unk18 < 255.0f) {
                return 5;
            }
            return 6;
        case 0x8A:
            return 7;
        case 0x86:
            return 1;
        case 0x85:
            return 2;
        case 0x8B:
            return 8;
        case 0x84:
            return 0;
        default:
            return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00154E20);

extern "C" void GrgOutDisappear__vfunc_04(GrgOutDisappear *self)
{
    X_func_00166AD0();
    X_func_001D23F8(&D_007812C0, self->m_unk00, 0);
}

extern "C" void GrgOutEvent__vfunc_02(GrgOutEvent *self)
{
    D_007B205C->m_unk14C = 0;
    X_func_001D23F8(&D_007812C0, self->m_unk00, 1);
}

extern "C" int GrgOutEvent__vfunc_03(void)
{
    return -1;
}

extern "C" void GrgOutWalk__vfunc_02(GrgOutWalk *self)
{
    short val;

    D_007B205C->m_unk14C = 1;
    val = X_func_0015558C(self);
    self->m_unk38 = 0;
    self->m_unk3A = val;
    X_func_00155648(self);
    self->m_unk04 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC80);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002EFC98);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0118);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutWalk__vfunc_03);

extern "C" int func_00155498(GrgOutWalk *self)
{
    int r = X_func_0010423C(0, D_002F0410[(unsigned short)self->m_unk3A][2]);
    unsigned short idx = (unsigned short)self->m_unk3A;
    if (r < D_002F0410[idx][0]) {
        if (X_func_00155648(self) != 0) {
            return 0;
        }
        return func_00155BB4(self);
    }
    if (r < D_002F0410[idx][1]) {
        if (func_0015582C(self) != 0) {
            return 1;
        }
        if (X_func_00155648(self) != 0) {
            return 0;
        }
        return func_00155BB4(self);
    }
    return func_00155BB4(self);
}

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0150);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0158);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0160);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0168);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0170);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0178);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0180);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0188);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0190);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0198);

extern "C" short func_0015558C(GrgOutWalk *self)
{
    int id;
    float pos[4];

    X_func_001DA228((void *)self->m_unk08, 8, &id);
    X_func_001D890C((void *)self->m_unk08, pos);
    switch (id) {
        case 0x88:
            return 3;
        case 0x87:
            return 4;
        case 0x89:
            if (pos[2] < 260.0f) {
                return 5;
            }
            return 6;
        case 0x8A:
            return 7;
        case 0x86:
            return 1;
        case 0x85:
            return 2;
        case 0x8B:
            return 8;
        case 0x84:
            return 0;
        default:
            return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_00155648);

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", func_0015582C);

extern "C" int func_00155BB4(GrgOutWalk *self)
{
    self->m_unk39 = X_func_0010423C(2, 6);
    X_func_001680A0(self, 0x28, 0);
    return 4U;
}

extern "C" void GrgOutWalk__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void GrgOutTest__vfunc_02(GrgOutTest *self)
{
    D_007B205C->m_unk14C = 1;
    self->m_unk04 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/GrgMain", GrgOutTest__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F01C0);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F01D0);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0410);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F0430);

INCLUDE_RODATA("asm/nonmatchings/unk/GrgMain", D_002F08B0);
