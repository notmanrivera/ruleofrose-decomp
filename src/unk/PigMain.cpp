#include "include_asm.h"
#include "emy/emy.h"

struct PigVtblEntry {
    short m_delta;
    short m_pad;
    int m_fn;
};

struct PigStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[0xA];
    signed char *m_table;
};

struct PigObjStatView {
    unsigned char m_pad00[0x3EC];
    int m_partsFlags;                   // +0x3EC
};

struct PigMain : EmyMain {
    unsigned char m_pad204[0x60];       // +0x204..+0x263
    signed char m_unk264;               // +0x264
    signed char m_unk265;               // +0x265
    signed char m_unk266;               // +0x266
    unsigned char m_pad267;             // +0x267
    int m_unk268;                       // +0x268
    int m_unk26C;                       // +0x26C
};
STATIC_ASSERT(sizeof(PigMain) == 0x270, PigMain_size);

struct PigOutParts : EmyOut {
};

struct PigOutTackle : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
};
STATIC_ASSERT(sizeof(PigOutTackle) == 0x40, PigOutTackle_size);

struct PigOutTest : EmyOut {
};

extern int vtbl_PigMain asm("_vt$7PigMain");

extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_EmyMain__vfunc_01(EmyMain *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00165794(PigMain *) asm("func_00165794");
extern "C" int X_func_00165A68(PigMain *) asm("func_00165A68");
extern "C" int X_func_00165AA8(PigMain *) asm("func_00165AA8");
extern "C" int X_func_00165D38(PigMain *) asm("func_00165D38");
extern "C" int X_func_00165D7C(PigMain *) asm("func_00165D7C");
extern "C" int X_func_00166004(PigMain *) asm("func_00166004");
extern "C" int X_func_00166048(PigMain *) asm("func_00166048");
extern "C" int X_func_00166108(PigMain *) asm("func_00166108");
extern "C" int X_func_00166128(PigMain *) asm("func_00166128");
extern "C" int X_func_00166178(PigMain *) asm("func_00166178");
extern "C" int X_func_00166198(PigMain *) asm("func_00166198");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166EB4(EmyOut *, int) asm("func_00166EB4");
extern "C" int X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_001696FC(void *, int) asm("func_001696FC");

static inline int PigCheckBlocked(PigMain *self, int idx)
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

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015A17C);

extern "C" void PigMain__vfunc_01(PigMain *self, int flags)
{
    self->m_vtbl = &vtbl_PigMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return Xv___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigMain__vfunc_04);

extern "C" void PigMain__vfunc_05(PigMain *self)
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
            self->m_unk265 = 0;
            self->m_unk264 = 0;
            self->m_unk266 = 0;
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

extern "C" void PigMain__vfunc_06(PigMain *self)
{
    EmyOut *curOut;
    PigVtblEntry *vt;

    if (self->m_stateChanged != 0) {
        curOut = self->m_curOut;
        vt = (PigVtblEntry *)((char *)curOut->m_vtbl + 0x20);
        ((void (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
        vt = (PigVtblEntry *)((char *)self->m_vtbl + 0x10);
        ((void (*)(void *))vt->m_fn)((char *)self + vt->m_delta);
    }
    curOut = self->m_curOut;
    vt = (PigVtblEntry *)((char *)curOut->m_vtbl + 0x18);
    self->m_nextState = ((int (*)(void *))vt->m_fn)((char *)curOut + vt->m_delta);
}

extern "C" int PigMain__vfunc_02(PigMain *self)
{
    int v;
    EmyOut *obj;
    PigVtblEntry *vt;
    register PigStateTable *tbl PS2_REG("$3");
    int count;
    register signed char *base PS2_REG("$7");
    register int v2 PS2_REG("$2");
    int i;
    int *dst;

    v = self->m_curState;
    if (v != 0) {
        if (v >= 0) {
            if (v < 0x11) {
                obj = ((EmyOut **)self->m_unk48)[v];
                self->m_curOut = obj;
                vt = (PigVtblEntry *)((char *)obj->m_vtbl + 0x10);
                ((void (*)(void *))vt->m_fn)((char *)obj + vt->m_delta);
            }
        }
    }
    i = 0;
    tbl = (PigStateTable *)self->m_unkE8;
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

extern "C" int func_0015AC8C(void)
{
    return X_func_00165734();
}

extern "C" int func_0015ACA0(PigMain *self)
{
    if (PigCheckBlocked(self, 1) == 0) {
        return X_func_00165794(self);
    }
    return 0;
}

// D_002F0D68..D_002F0D88: the end of unk/GotMain's .rodata now (config/splits_manual.tsv)

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015AD18);

extern "C" int func_0015AE78(PigMain *self)
{
    if (PigCheckBlocked(self, 7) == 0) {
        return X_func_00165A68(self);
    }
    return 0;
}

extern "C" int func_0015AEF0(PigMain *self)
{
    if (PigCheckBlocked(self, 8) == 0) {
        return X_func_00165AA8(self);
    }
    return 0;
}

extern "C" int func_0015AF68(PigMain *self)
{
    if (PigCheckBlocked(self, 9) == 0) {
        return X_func_00165D38(self);
    }
    return 0;
}

extern "C" int func_0015AFE0(PigMain *self)
{
    if (PigCheckBlocked(self, 0xA) == 0) {
        return X_func_00165D7C(self);
    }
    return 0;
}

extern "C" int func_0015B058(PigMain *self)
{
    if (PigCheckBlocked(self, 0xB) == 0) {
        return X_func_00166004(self);
    }
    return 0;
}

extern "C" int func_0015B0DC(PigMain *self)
{
    if (PigCheckBlocked(self, 0xC) == 0) {
        return X_func_00166048(self);
    }
    return 0;
}

extern "C" int func_0015B154(PigMain *self)
{
    if (PigCheckBlocked(self, 0xD) == 0) {
        return X_func_00166128(self);
    }
    return 0;
}

extern "C" int func_0015B1CC(PigMain *self)
{
    if (PigCheckBlocked(self, 0xE) == 0) {
        return X_func_00166108(self);
    }
    return 0;
}

extern "C" int func_0015B244(PigMain *self)
{
    if (PigCheckBlocked(self, 0xF) == 0) {
        return X_func_00166178(self);
    }
    return 0;
}

extern "C" int func_0015B2BC(PigMain *self)
{
    if (PigCheckBlocked(self, 0x10) != 0) {
        return 0;
    }
    int f = ((PigObjStatView *)self->m_objStat)->m_partsFlags;
    if (f & 8) {
        if (f & 0x10) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_0015B34C(PigMain *self)
{
    if (PigCheckBlocked(self, 0x11) != 0) {
        return 0;
    }
    int f = ((PigObjStatView *)self->m_objStat)->m_partsFlags;
    if (f & 2) {
        if (f & 4) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_0015B3DC(PigMain *self)
{
    if (PigCheckBlocked(self, 0x12) != 0) {
        return 0;
    }
    return ((PigObjStatView *)self->m_objStat)->m_partsFlags & 1;
}

extern "C" int func_0015B454(PigMain *self)
{
    if (PigCheckBlocked(self, 0x13) != 0) {
        return 0;
    }
    int f = ((PigObjStatView *)self->m_objStat)->m_partsFlags;
    if (!(f & 2)) {
        if (!(f & 4)) {
            return 0;
        }
    }
    return 1;
}

extern "C" int func_0015B4E4(PigMain *self)
{
    if (PigCheckBlocked(self, 0x14) != 0) {
        return 0;
    }
    int f = ((PigObjStatView *)self->m_objStat)->m_partsFlags;
    if (!(f & 8)) {
        if (!(f & 0x10)) {
            return 0;
        }
    }
    return 1;
}

extern "C" int func_0015B574(PigMain *self)
{
    if (PigCheckBlocked(self, 0x15) == 0) {
        return X_func_00166198(self);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B5EC);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", func_0015B8B8);

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigOutParts__vfunc_02);

extern "C" int PigOutParts__vfunc_03(void)
{
    return -1;
}

extern "C" void PigOutParts__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void PigOutTackle__vfunc_02(PigOutTackle *self)
{
    X_func_00166EB4(self, 0x64);
    self->m_unk38 = 0;
    self->m_unk3C = 0;
    X_func_00166F50(self, self->m_unk14, 300.0f);
    self->m_unk04 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigOutTackle__vfunc_03);

extern "C" void PigOutTackle__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void PigOutTest__vfunc_02(PigOutTest *self)
{
    self->m_unk04 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/PigMain", PigOutTest__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/PigMain", D_002F0DD8);
INCLUDE_RODATA("asm/nonmatchings/unk/PigMain", D_002F0DE8);
INCLUDE_RODATA("asm/nonmatchings/unk/PigMain", D_002F0DF8);
INCLUDE_RODATA("asm/nonmatchings/unk/PigMain", D_002F0E08);
