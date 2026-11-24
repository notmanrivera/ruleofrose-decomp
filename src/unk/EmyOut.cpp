#include "include_asm.h"
#include "emy/emy.h"
#include "dog/dogactor.h"
#include "sdk/string.h"
#include "game/gamman.h"
#include "game/gamtrg.h"
extern "C" int func_001E5E58(void *, int, int, void *);
extern "C" int func_001E5660(void *, int, int, void *);
static inline void *getGamSnd(GamMan *g) { return g->m_snd; }
extern "C" int func_00169BAC(int, int, void *, float, float);
extern "C" void func_001664A4(EmyMain *, int);
extern "C" void func_001DA130(void *, int, int);
extern "C" int func_00104394(int, int, int);
struct EmySlot154 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
};
struct EmyMain154 {
    unsigned char m_pad00[0x154];
    EmySlot154 m_slots[4];
};

struct EmyMainVtbl3 {
    unsigned char m_pad[0x200];
    virtual void v1();
    virtual void v2();
    virtual int getType();
};

struct EmyEntry24 {
    unsigned char m_data[0x18];
};

extern EmyEntry24 D_002F18B8[];
extern int D_006E9840;
extern int D_007A3350;
extern int vtbl_EmyOut asm("_vt$6EmyOut");

extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" int X_func_00104394(int, int, int) asm("func_00104394");
extern "C" int X_func_00118FEC__9MagSystem(void *) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_001442D4() asm("func_001442D4");
extern "C" void func_00165280(EmyMain *, float *);
extern "C" void func_00165570(EmyMain *);
extern "C" void X_func_00166AD0(EmyOut *) asm("func_00166AD0");
extern "C" void X_func_00168478(EmyOut *) asm("func_00168478");
extern "C" void X_func_00168520(EmyOut *) asm("func_00168520");
extern "C" void X_func_0016913C(EmyOut *) asm("func_0016913C");
extern "C" void X_func_00169A98(void *, void *, float) asm("func_00169A98");
extern "C" void X_func_0016A6B4(void *) asm("func_0016A6B4");
extern "C" int X_func_001CBEDC(void *, int) asm("func_001CBEDC");
extern "C" void X_func_001DA130(void *, int, int) asm("func_001DA130");
extern "C" void X_func_001DA228(void *, int, int *) asm("func_001DA228");
extern "C" void X_func_001DA740(void *, int, int *) asm("func_001DA740");
extern "C" void X_func_001DC48C(void *, int, int, unsigned short *) asm("func_001DC48C");
extern "C" void X_func_00202F60(void *) asm("func_00202F60");
extern "C" void X_func_00202FBC(void *) asm("func_00202FBC");
extern "C" void X_func_002039A4(void *) asm("func_002039A4");
extern "C" void X_func_00203A00(void *) asm("func_00203A00");

extern "C" void func_00165010(EmyMain *self)
{
    EmyOut *out = self->m_curOut;
    if (out != 0) {
        X_func_00168478(out);
    }
}

extern "C" void func_00165038(EmyMain *self)
{
    EmyOut *out = self->m_curOut;
    if (out != 0) {
        X_func_00168520(out);
    }
}

extern "C" void func_00165060(EmyMain *self)
{
    EmyOut *out = self->m_curOut;
    if (out != 0) {
        out->m_unk1C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165074);

// NON_MATCHING: fn matches; D_002F1520 needs .align 3 in config/rodata_align_manual.tsv
#ifdef NON_MATCHING
extern DogActor D_006FE6A0[];
extern "C" float *func_001D2B8C(void *, unsigned int);
extern "C" int func_001CBE38(void *, unsigned int);
extern "C" void func_001D890C(float *, float *);

static inline float *getBone_5280(const char *name, float (*mat)[4], DogActor *actor)
{
    actor->vfunc17(mat, actor->getNodeIndexByName(name));
    return mat[3];
}

static inline void copyVec_5280(float *dst, const float *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

extern "C" void func_00165280(EmyMain *arg0, float *arg1)
{
    float sp[4];
    float mat[4][4];
    float *temp_s3 = func_001D2B8C(&D_007812C0, arg0->m_id);
    copyVec_5280(arg1, getBone_5280("Bip01 Spine1", mat, &D_006FE6A0[func_001CBE38(&D_007812C0, arg0->m_id)]));
    func_001D890C(temp_s3, sp);
    arg1[1] = sp[1];
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165280);
#endif

extern "C" void func_00165398(EmyMain *self, int arg1, int arg2, int arg3)
{
    func_00165570(self);
    self->m_unk154 = arg1;
    self->m_unk160 = arg2;
    self->m_unk164 = 0;
    self->m_unk168 = 0;
    self->m_unk16C = X_func_00104394(1, arg3, 4);
}

extern "C" void func_00165404(EmyMain *self, int arg1, int arg2, int arg3)
{
    EmyMain154 *m = (EmyMain154 *)self;
    for (int i = 0; i < 4; i++) {
        if (m->m_slots[i].m_unk00 == 0) {
            m->m_slots[i].m_unk00 = arg1;
            m->m_slots[i].m_unk10 = 0;
            m->m_slots[i].m_unk0C = arg2;
            m->m_slots[i].m_unk14 = 0;
            m->m_slots[i].m_unk18 = func_00104394(1, arg3, 4);
            return;
        }
    }
}

extern "C" void func_00165498(EmyMain *self, int arg1)
{
    EmyMain154 *m = (EmyMain154 *)self;
    for (int i = 0; i < 4; i++) {
        if (m->m_slots[i].m_unk00 == arg1) {
            if (m->m_slots[i].m_unk0C < 3) {
                func_001E5E58(getGamSnd(&D_007812C0), arg1, 8, 0);
            } else {
                func_001E5660(getGamSnd(&D_007812C0), arg1, 8, 0);
            }
            memset(&m->m_slots[i], 0, sizeof(EmySlot154));
        }
    }
}

extern "C" void func_00165570(EmyMain *self)
{
    EmyMain154 *m = (EmyMain154 *)self;
    for (int i = 0; i < 4; i++) {
        int id = m->m_slots[i].m_unk00;
        if (id != 0) {
            if (m->m_slots[i].m_unk0C < 3) {
                func_001E5E58(getGamSnd(&D_007812C0), id, 8, 0);
            } else {
                func_001E5660(getGamSnd(&D_007812C0), id, 8, 0);
            }
            memset(&m->m_slots[i], 0, sizeof(EmySlot154));
        }
    }
}

extern "C" void func_00165638(EmyMain *self, int arg1)
{
    EmyMain154 *m = (EmyMain154 *)self;
    for (int i = 0; i < 4; i++) {
        if (m->m_slots[i].m_unk0C == arg1) {
            memset(&m->m_slots[i], 0, sizeof(EmySlot154));
        }
    }
}

extern "C" int func_001656B4(EmyMain *self)
{
    int r = ((EmyMainVtbl3 *)self)->getType();

    if (r == 3 && self->m_curState == r) {
        return 0;
    }
    return self->m_unk10 == 0;
}

extern "C" int func_00165710(EmyMain *self)
{
    if (self->m_unk10 != 0) {
        return 0;
    }
    return self->m_stateFlags[self->m_curState] != 0;
}

extern "C" int func_00165734(EmyMain *self)
{
    int a;
    int b;

    if (D_007A3350 == 0) {
        return 0;
    }
    X_func_001DA228((void *)D_007A3350, 8, &a);
    X_func_001DA228(self->m_objStat, 8, &b);
    return a == b;
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165794);

extern "C" int func_00165A68()
{
    if (!(X_func_00118FEC__9MagSystem(&D_006E9840) != 1) || !(X_func_001442D4() != 0)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165AA8);

extern "C" int func_00165D38()
{
    if (!(X_func_00118FEC__9MagSystem(&D_006E9840) != 2) || !(X_func_001442D4() != 1)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00165D7C);

extern "C" void func_00166004(EmyMain *self)
{
    struct {
        char pad0[16];
        float sp10;
    } stack;

    func_00165280(self, (float *)&stack);
    X_func_0016A6B4(&stack.sp10);
    X_func_00169A98(&stack, &stack.sp10, 60.0f);
}

extern "C" int func_00166048(EmyMain *self)
{
    int pcOid = D_007812C0.m_pc ? D_007812C0.m_pc->m_oid : 0;
    int r1 = func_00169BAC(0, pcOid, self->m_objStat, 60.0f, 6.2831853f);
    int r2 = func_00169BAC(0, D_007812C0.m_dog->m_oid, self->m_objStat, 60.0f, 6.2831853f);
    return (r1 != 0) | (r2 != 0);
}

extern "C" int func_00166108(EmyMain *self)
{
    float v[4];
    (void)v;

    return ((EmyObjStatView *)self->m_objStat)->m_hp < (unsigned int)((unsigned short)self->m_unk1D8 >> 2);
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_00166128);

extern "C" int func_00166178(EmyMain *self)
{
    float v[4];
    (void)v;

    return ((EmyObjStatView *)self->m_objStat)->m_hp < (unsigned int)((unsigned short)self->m_unk1D8 >> 1);
}

extern "C" int func_00166198()
{
    if (!(X_func_00118FEC__9MagSystem(&D_006E9840) != 4) || !(X_func_001442D4() != 2)) {
        return 1;
    }
    return 0;
}

extern "C" void func_001661DC(EmyMain *self, int flag)
{
    if (((unsigned int)(flag - 1) >= 2U) && (flag != 4)) {
        if (flag == 8) {
            goto set_flag;
        }
    } else {
set_flag:
        self->m_unk14 = 1;
    }
    self->m_flags30 |= flag;
}

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_0016621C);

extern "C" void func_00166364(EmyMain *self, int arg1)
{
    self->m_unk1C8 = arg1;
    self->m_unk1D4 = 0;
    self->m_unk1D0 = 0;
    self->m_unk1CC = 0;
}

extern "C" void func_00166378(EmyMain *self, int arg1)
{
    self->m_unk08 = arg1;
    if (arg1 == 0) {
        func_001DA130(self->m_objStat, arg1, 1);
        func_001664A4(self, 1);
        ((EmyObjStatView *)self->m_objStat)->m_flags |= 0x400;
        ((EmyObjStatView *)self->m_objStat)->m_flags |= 0x2000;
    } else {
        func_001664A4(self, 0);
        ((EmyObjStatView *)self->m_objStat)->m_flags &= ~0x400;
        ((EmyObjStatView *)self->m_objStat)->m_flags &= ~0x2000;
    }
}

extern "C" int func_0016640C(EmyMain *self)
{
    int r;

    X_func_001DA740(self->m_objStat, 0x1B, &r);
    return r;
}

extern "C" void func_00166434(EmyMain *self)
{
    short idx = self->m_callback.m_index;
    long ent;
    int fp;
    if (idx >= 0) {
        int p = *(int *)((char *)self + (short)self->m_callback.m_pfn);
        p += idx * 8;
        ent = *((long *)p - 1);
        fp = (int)(ent >> 32);
    } else {
        fp = self->m_callback.m_pfn;
    }
    short base = self->m_callback.m_delta;
    int off = (idx >= 0) ? (short)ent + base : base;
    ((void (*)(char *))fp)((char *)self + off);
}

extern "C" void func_0016649C(EmyMain *self, int arg1)
{
    self->m_unk28 = arg1;
}

extern "C" void func_001664A4(EmyMain *self, int arg1)
{
    X_func_001DA130(self->m_objStat, arg1, 0);
    if (arg1 == 1) {
        X_func_00202F60(self->m_unk1F0);
        return X_func_002039A4(self->m_unk1F8);
    }
    X_func_00202FBC(self->m_unk1F0);
    X_func_00203A00(self->m_unk1F8);
}

extern "C" void func_00166518(EmyMain *self)
{
    X_func_0016913C(self->m_curOut);
}

extern "C" void func_00166534(EmyMain *self)
{
    int v = self->m_unk1E4 - 1;
    self->m_unk1E4 = v;
    if (v <= 0) {
        self->m_unk1E4 = 0;
        ((EmyObjStatView *)self->m_objStat)->m_flags &= ~0x400;
    }
}

extern "C" int func_00166568(EmyMain *self, int *tbl)
{
    unsigned char idx = self->m_unk06;

    if (idx == 2) {
        int t = X_func_0010423C(0, 0x63) < 0x32;
        idx = !t;
    }
    return tbl[idx];
}

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1520);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1528);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1530);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1538);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1540);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1548);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1550);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1558);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1560);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1568);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1570);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1578);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1580);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1588);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1590);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1598);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15A0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15A8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15B0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15B8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15C8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15D0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15D8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F15E8);

INCLUDE_ASM("asm/nonmatchings/unk/EmyOut", func_001665B8);

extern "C" void *func_001669A4(EmyMain *self)
{
    unsigned short idx;

    X_func_001DC48C((char *)&D_007812C0 + 0x22220, X_func_001CBEDC(&D_007812C0, self->m_id), 0x20, &idx);
    return &D_002F18B8[idx];
}

extern "C" int func_00166A0C(EmyMain *self)
{
    if (self->m_flags30 & 1) {
        return 1;
    }
    return 0;
}

extern "C" int func_00166A1C(EmyOut *self, int arg1, int arg2, EmyMain *owner)
{
    self->m_unk00 = arg1;
    self->m_unk08 = arg2;
    self->m_owner = owner;
    self->m_unk2C = -1;
    self->m_vtbl = &vtbl_EmyOut;
    self->m_unk1C = 0;
    self->m_unk20 = 0;
    self->m_unk30 = X_func_0010423C(8, 0x18);
}

extern "C" void dtor_6EmyOut(EmyOut *self, int flags) asm("_$_6EmyOut");
extern "C" void dtor_6EmyOut(EmyOut *self, int flags)
{
    self->m_vtbl = &vtbl_EmyOut;
    X_func_00166AD0(self);
    if (flags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16A8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16B8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16C8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16D0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16F0);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F16F8);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1700);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1708);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1710);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1718);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F171C);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1720);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1728);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1730);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1738);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1740);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1748);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F1750);

INCLUDE_RODATA("asm/nonmatchings/unk/EmyOut", D_002F18B8);
