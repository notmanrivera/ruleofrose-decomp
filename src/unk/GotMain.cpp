#include "include_asm.h"
#include "emy/emy.h"

struct GotVtblEntry {
    short m_delta;
    short m_pad;
    int m_fn;
};

struct GotStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[0xA];
    signed char *m_table;
};

struct GotObjStatView {
    unsigned char m_pad00[0x3EC];
    int m_partsFlags;                   // +0x3EC
};

struct GotMain : EmyMain {
    unsigned char m_pad204[0x60];       // +0x204..+0x263
    signed char m_unk264;               // +0x264
    signed char m_unk265;               // +0x265
    unsigned char m_pad266[2];          // +0x266..+0x267
    int m_unk268;                       // +0x268
    int m_unk26C;                       // +0x26C
};
STATIC_ASSERT(sizeof(GotMain) == 0x270, GotMain_size);

struct GotOutParts : EmyOut {
};

struct GotOutTest : EmyOut {
};

extern int vtbl_GotMain asm("_vt$7GotMain");

extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_EmyMain__vfunc_01(EmyMain *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00165794(GotMain *) asm("func_00165794");
extern "C" int X_func_00165A68(GotMain *) asm("func_00165A68");
extern "C" int X_func_00165AA8(GotMain *) asm("func_00165AA8");
extern "C" int X_func_00165D38(GotMain *) asm("func_00165D38");
extern "C" int X_func_00165D7C(GotMain *) asm("func_00165D7C");
extern "C" int X_func_00166004(GotMain *) asm("func_00166004");
extern "C" int X_func_00166048(GotMain *) asm("func_00166048");
extern "C" int X_func_00166108(GotMain *) asm("func_00166108");
extern "C" int X_func_00166128(GotMain *) asm("func_00166128");
extern "C" int X_func_00166178(GotMain *) asm("func_00166178");
extern "C" int X_func_00166198(GotMain *) asm("func_00166198");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_001685C0(EmyOut *, int, int) asm("func_001685C0");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_001696FC(void *, int) asm("func_001696FC");
extern "C" int X_func_001CBEDC(void *, int) asm("func_001CBEDC");
extern "C" int X_func_001DA228(void *, int, void *) asm("func_001DA228");

extern int D_007812C0;

static inline int GotCheckBlocked(GotMain *self, int idx)
{
    int next = X_func_001696FC(self->m_brain, idx);
    if (next == 0xB && self->m_unk268 == 0) {
        return 1;
    }
    if (next == 0xC && self->m_unk26C == 0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_001583D4);

extern "C" void GotMain__vfunc_01(GotMain *self, int flags)
{
    self->m_vtbl = &vtbl_GotMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return Xv___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotMain__vfunc_04);

extern "C" void GotMain__vfunc_05(GotMain *self)
{
    int flags;
    int next;
    int res;

    self->m_stateChanged = 0;
    flags = self->m_flags30;
    if (flags & 2) {
        self->m_curState = 4;
        ((EmyBrainView *)self->m_brain)->m_state = 4;
        self->m_stateChanged = 1;
        self->m_flags30 = 0;
    } else {
        next = self->m_nextState;
        if (next != -1) {
            self->m_flags30 = 0;
            res = X_func_0016968C(self->m_brain, next);
            self->m_unk264 = 0;
            self->m_unk265 = 0;
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

extern "C" void GotMain__vfunc_06(GotMain *self)
{
    EmyOut *curOut;
    GotVtblEntry *vt;

    if (self->m_stateChanged != 0) {
        curOut = self->m_curOut;
        vt = (GotVtblEntry *)((char *)curOut->m_vtbl + 0x20);
        ((void (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
        vt = (GotVtblEntry *)((char *)self->m_vtbl + 0x10);
        ((void (*)(void *))vt->m_fn)((char *)self + vt->m_delta);
    }
    curOut = self->m_curOut;
    vt = (GotVtblEntry *)((char *)curOut->m_vtbl + 0x18);
    self->m_nextState = ((int (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
}

extern "C" int GotMain__vfunc_02(GotMain *self)
{
    int v;
    EmyOut *obj;
    GotVtblEntry *vt;
    register GotStateTable *tbl PS2_REG("$3");
    int count;
    register signed char *base PS2_REG("$7");
    register int v2 PS2_REG("$2");
    int i;
    int *dst;

    v = self->m_curState;
    if (v != 0) {
        if (v >= 0) {
            if (v < 0x10) {
                obj = ((EmyOut **)self->m_unk48)[v];
                self->m_curOut = obj;
                vt = (GotVtblEntry *)((char *)obj->m_vtbl + 0x10);
                ((void (*)(void *))vt->m_fn)((char *)obj + vt->m_delta);
            }
        }
    }
    i = 0;
    tbl = (GotStateTable *)self->m_unkE8;
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

extern "C" int func_00158EA0(void)
{
    return X_func_00165734();
}

extern "C" int func_00158EB4(GotMain *self)
{
    if (GotCheckBlocked(self, 1) == 0) {
        return X_func_00165794(self);
    }
    return 0;
}

// D_002F0D08..D_002F0D18: the end of unk/FshMain's .rodata now (config/splits_manual.tsv)

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_00158F2C);

extern "C" int func_0015908C(GotMain *self)
{
    if (GotCheckBlocked(self, 7) == 0) {
        return X_func_00165A68(self);
    }
    return 0;
}

extern "C" int func_00159104(GotMain *self)
{
    if (GotCheckBlocked(self, 8) == 0) {
        return X_func_00165AA8(self);
    }
    return 0;
}

extern "C" int func_0015917C(GotMain *self)
{
    if (GotCheckBlocked(self, 9) == 0) {
        return X_func_00165D38(self);
    }
    return 0;
}

extern "C" int func_001591F4(GotMain *self)
{
    if (GotCheckBlocked(self, 0xA) == 0) {
        return X_func_00165D7C(self);
    }
    return 0;
}

extern "C" int func_0015926C(GotMain *self)
{
    if (GotCheckBlocked(self, 0xB) == 0) {
        return X_func_00166004(self);
    }
    return 0;
}

extern "C" int func_001592F0(GotMain *self)
{
    if (GotCheckBlocked(self, 0xC) == 0) {
        return X_func_00166048(self);
    }
    return 0;
}

extern "C" int func_00159368(GotMain *self)
{
    if (GotCheckBlocked(self, 0xD) == 0) {
        return X_func_00166128(self);
    }
    return 0;
}

extern "C" int func_001593E0(GotMain *self)
{
    if (GotCheckBlocked(self, 0xE) == 0) {
        return X_func_00166108(self);
    }
    return 0;
}

extern "C" int func_00159458(GotMain *self)
{
    if (GotCheckBlocked(self, 0xF) == 0) {
        return X_func_00166178(self);
    }
    return 0;
}

extern "C" int func_001594D0(GotMain *self)
{
    if (GotCheckBlocked(self, 0x10) != 0) {
        return 0;
    }
    int f = ((GotObjStatView *)self->m_objStat)->m_partsFlags;
    if (f & 8) {
        if (f & 0x10) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_00159560(GotMain *self)
{
    if (GotCheckBlocked(self, 0x11) != 0) {
        return 0;
    }
    int f = ((GotObjStatView *)self->m_objStat)->m_partsFlags;
    if (f & 2) {
        if (f & 4) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_001595F0(GotMain *self)
{
    if (GotCheckBlocked(self, 0x12) != 0) {
        return 0;
    }
    return ((GotObjStatView *)self->m_objStat)->m_partsFlags & 1;
}

extern "C" int func_00159668(GotMain *self)
{
    if (GotCheckBlocked(self, 0x13) != 0) {
        return 0;
    }
    int f = ((GotObjStatView *)self->m_objStat)->m_partsFlags;
    if (!(f & 2)) {
        if (!(f & 4)) {
            return 0;
        }
    }
    return 1;
}

extern "C" int func_001596F8(GotMain *self)
{
    if (GotCheckBlocked(self, 0x14) != 0) {
        return 0;
    }
    int f = ((GotObjStatView *)self->m_objStat)->m_partsFlags;
    if (!(f & 8)) {
        if (!(f & 0x10)) {
            return 0;
        }
    }
    return 1;
}

extern "C" int func_00159788(GotMain *self)
{
    if (GotCheckBlocked(self, 0x15) == 0) {
        return X_func_00166198(self);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_00159800);

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", func_00159AF8);

#ifdef NON_MATCHING
extern "C" void GotOutParts__vfunc_02(GotOutParts *self)
{
    GotObjStatView *stat = (GotObjStatView *)self->m_unk08;
    int anim;

    if ((stat->m_partsFlags & 8) != 0 && (stat->m_partsFlags & 0x10) != 0) {
        anim = 0xA;
    } else if ((stat->m_partsFlags & 8) != 0 || (stat->m_partsFlags & 0x10) != 0) {
        anim = 1;
    } else {
        int val;
        X_func_001DA228(stat, 0x67, &val);
        anim = (X_func_001CBEDC(&D_007812C0, val) == 0xA2E) ? 0x4F : 0x14;
    }
    X_func_001685C0(self, anim, 0);
    self->m_unk04 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotOutParts__vfunc_02);
#endif

extern "C" int GotOutParts__vfunc_03(void)
{
    return -1;
}

extern "C" void GotOutParts__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void GotOutTest__vfunc_02(GotOutTest *self)
{
    self->m_unk04 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/GotMain", GotOutTest__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/GotMain", D_002F0D68);
INCLUDE_RODATA("asm/nonmatchings/unk/GotMain", D_002F0D78);
INCLUDE_RODATA("asm/nonmatchings/unk/GotMain", D_002F0D88);
