#include "ror.h"
#include "include_asm.h"
#include "unk/00166AD0.h"
extern char X844_D_006E9840[] asm("D_006E9840");
extern "C" void X844_DA228(ACHRstat *, int, unsigned int *) asm("func_001DA228");
extern "C" int X844_CBEDC(GamMan *, unsigned int) asm("func_001CBEDC");
extern "C" void X844_33144(int, int, int, int, int, unsigned int, float) asm("func_00133144");
static inline int bigOffset844(char *p) { return (int)(p + 0x12540); }
extern "C" int Xiiiiif_func_001F603C(int, int, int, int, float) asm("func_001F603C");
extern "C" int *Xipp_func_001D7F48(GamMan *, float *, int) asm("func_001D7F48");
extern "C" void Xv_func_001F603C(int, int, int, int, float, float, int) asm("func_001F603C");
extern "C" float Xff_sinf(float) asm("sinf");
extern "C" float Xff_cosf(float) asm("cosf");
extern "C" void Xv_func_00202F10(void *) asm("func_00202F10");
extern "C" int Xiffii_func_00169BAC(int, float, float, int, ACHRstat *) asm("func_00169BAC");
extern "C" void Xv_func_0016A6B4(float *) asm("func_0016A6B4");
extern "C" void Xv_func_0016A7AC(float *) asm("func_0016A7AC");
extern "C" void Xv_func_00166DA4(EmyOutView *, int) asm("func_00166DA4");
extern "C" void Xiiii_func_001685C0(EmyOutView *, int, int) asm("func_001685C0");
extern "C" int Xiiu_func_001D19A8(GamMan *, unsigned int) asm("func_001D19A8");
extern "C" int Xiiii_ffi_func_001F603C(int, int, int, int, float, float, int) asm("func_001F603C");
extern "C" float *func_001D2B8C(GamMan *, unsigned int);
extern "C" void func_001D890C(float *, float *);
extern char D_006FE6A0 [];
extern int cGlobalA asm("D_007A3D80");
extern char cActors[] asm("D_006FBD80");
extern char D_002F19E0[],D_002F19F0[],D_002F1A00[],D_002F1A10[];
extern "C" int cHas(int,int) asm("func_001E7D7C");
extern "C" int cLookup(GamMan *,unsigned int) asm("func_001D046C");
extern "C" int cIndex(GamMan *,unsigned int) asm("func_001CBE38");
extern "C" void cStop(ACHRstat *) asm("func_001DA07C");
extern "C" void cPos(EmyOutView *,float*) asm("func_00166B74");
extern "C" void cSub(float*,float*,float*) asm("func_0025B890");
extern "C" float cAtan(float,float) asm("func_0026CB00");
extern "C" float cYaw(int) asm("func_0010A650__8DogActor");
extern "C" int cBone(int,const char*) asm("func_0022B3D8");
struct cModel { char pad[0x94]; virtual void pad1(); virtual void pad2(); virtual void pad3(); virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7(); virtual void pad8(); virtual void pad9(); virtual void pad10(); virtual void pad11(); virtual void pad12(); virtual void pad13(); virtual void pad14(); virtual void pad15(); virtual void pad16(); virtual void X__vfunc_136(float*,int); float *getBone(float*,const char*); };
inline int cAdd(int p) { return p+0x2920; }
inline int cActor(int n) { return cAdd((int)cActors+n*0x4d0); }
inline float *cGetBone(const char *name,float *mat,cModel *model) {
    if (!(*(int *)((char *)model+0x11c))) ror_assert(D_002F19F0,305,D_002F1A00);
    if (!name) ror_assert(D_002F19F0,305,D_002F1A10);
    model->X__vfunc_136(mat,cBone(*(int *)((char *)model+0x11c),name));
    return mat+12;
}
inline void cCopy(void *d,const float *s) { ((float *)d)[0]=s[0]; ((float *)d)[1]=s[1]; ((float *)d)[2]=s[2]; }
extern "C" int Xii_func_001682B0(EmyOutView *) asm("func_001682B0");
extern "C" int Xii_func_0016834C(EmyOutView *) asm("func_0016834C");
extern "C" int Xii_func_00168844(EmyOutView *) asm("func_00168844");
extern "C" int Xii_func_001442DC(int) asm("func_001442DC");
extern "C" int Xiiii_func_001680A0(EmyOutView *, int, int) asm("func_001680A0");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001442DC(...) asm("func_001442DC");
extern "C" int X_func_00162B14(...) asm("func_00162B14");
extern "C" int X_func_0016649C(...) asm("func_0016649C");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001DA07C(...) asm("func_001DA07C");
extern "C" int X_func_00202F10(...) asm("func_00202F10");
extern int D_007B2140;
extern int D_007B2580;

extern "C" void func_00166AD0(EmyOutView *arg0)
{
    int temp_v0;

    X_func_0016649C(arg0->m_owner, 1);
    X_func_001D1410((int)&D_007812C0, arg0->m_oid, 0x400);
    X_func_00202F10(arg0->m_owner->m_unk1F0);
    arg0->m_owner->m_unk1F8[1] = 0;
    X_func_001DA07C(arg0->m_achr);
    X_func_0016649C(arg0->m_owner, 1);
    arg0->m_owner->m_unk2C = 1;
    arg0->m_owner->m_unk10 = 0;
    temp_v0 = arg0->m_sndHandle;
    if (temp_v0 >= 0) {
        X_func_00180EA8((int)&D_007B2580, temp_v0);
        arg0->m_sndHandle = -1;
    }
}


extern "C" void func_00166B74(EmyOutView *arg0, float *arg1) {
    float sp[4];
    float mat[16];
    float *temp_s3 = func_001D2B8C(&D_007812C0, arg0->m_oid);
    cCopy(arg1, cGetBone(D_002F19E0, mat, (cModel *)(D_006FE6A0 + cIndex(&D_007812C0, arg0->m_oid) * 0x4d0)));
    func_001D890C(temp_s3, sp);
    arg1[1] = sp[1];
}

extern "C" void func_00166C8C(EmyOutView *arg0, float *arg1) {
    float sp[4];
    float mat[16];
    float *temp_s3 = func_001D2B8C(&D_007812C0, arg0->m_targetOid);
    cCopy(arg1, cGetBone(D_002F19E0, mat, (cModel *)(D_006FE6A0 + cIndex(&D_007812C0, arg0->m_targetOid) * 0x4d0)));
    func_001D890C(temp_s3, sp);
    arg1[1] = sp[1];
}

extern "C" int Xffiii_func_00169BAC(float, float, int, int, ACHRstat *) asm("func_00169BAC");
extern "C" int Xiii_func_0010423C(int, int) asm("func_0010423C");
extern "C" void func_00166DA4(EmyOutView *arg0, int arg1)
{
    register EmyOutView *self PS2_REG("$16") = arg0;
    register GamMan *g PS2_REG("$3") = &D_007812C0;
    register int one PS2_REG("$20") = 1;
    ACHRstat *temp_a2 = self->m_achr;
    register int pc PS2_REG("$17") = g->m_pc->m_oid;
    register int rate PS2_REG("$19") = ((*(int *)temp_a2->m_unk3EC) & 1) ? 0x64 : arg1;
    register int dog PS2_REG("$18") = g->m_dog->m_oid;
    if (rate < 0x63) {
        register float f60 PS2_REG("$f21") = 60.0f;
        register float f2pi PS2_REG("$f20") = 6.283185124397278f;
        if (Xffiii_func_00169BAC(f60, f2pi, 0, pc, temp_a2) == 0) {
            if (Xffiii_func_00169BAC(f60, f2pi, 0, dog, self->m_achr) != 0 ||
                Xiii_func_0010423C(0, 0x63) >= rate) {
                self->m_targetKind = one;
                self->m_targetOid = dog;
                return;
            }
        }
    }
    self->m_targetOid = pc;
    self->m_targetKind = 0;
}

extern "C" void func_00166EB4(EmyOutView *arg0, int arg1)
{
    float a[4];
    float b[4];
    float c[4];
    float dx1, dz1, dx2, dz2;

    cPos(arg0, c);
    Xv_func_0016A6B4(a);
    Xv_func_0016A7AC(b);
    dx1 = a[0] - c[0];
    dz1 = a[2] - c[2];
    dx2 = b[0] - c[0];
    dz2 = b[2] - c[2];
    if ((dx1 * dx1 + dz1 * dz1) < (dx2 * dx2 + dz2 * dz2)) {
        arg1 = 0x64;
    }
    Xv_func_00166DA4(arg0, arg1);
}

// NON_MATCHING: 37/99 differ, 1 reloc differs, 42 edits
#ifdef NON_MATCHING
struct Tbl1C90f { float unk0; float unk4; float unk8; int unkC; };
struct Tbl1D80f { float unk0; float unk4; };
struct Ret1669A4f { int a[4]; float f; };
extern int X6F50_1D50[] asm("D_002F1D50");
extern Tbl1D80f X6F50_1D80[] asm("D_002F1D80");
extern Tbl1C90f X6F50_1C90[] asm("D_002F1C90");
extern "C" Ret1669A4f *X6F50_func_001669A4(EmyMainView *) asm("func_001669A4");
extern "C" void X6F50_func_00200700(void *, void *) asm("func_00200700");
extern "C" void func_00166F50(EmyOutView *arg0, int arg1, float fparg0)
{
    unsigned int sp0;
    struct {
        int unk00;
        int unk04;
        int unk08;
        float unk0C;
        float unk10;
        float unk14;
        float unk18;
        float unk1C;
        int unk20;
        int unk24;
        int unk28;
        float unk2C;
        float unk30;
        float unk34;
        float unk38;
        float unk3C;
        int unk40;
        int unk44;
        int unk48;
        int unk4C;
        int unk50;
        int unk54;
        float unk58;
        float unk5C;
    } sp;

    EmyMainView *obj = arg0->m_owner;
    int mode = obj->getType();
    sp.unk24 = 0;
    if (mode == 2) {
        X844_DA228(arg0->m_achr, 0x67, &sp0);
        if (sp0 != 0 && X844_CBEDC(&D_007812C0, sp0) == 0xA2E) {
            sp.unk24 = 1;
        }
    }
    float f18 = X6F50_1D80[mode].unk0;
    float f1c = X6F50_1D80[mode].unk4;
    obj = arg0->m_owner;
    sp.unk00 = arg0->m_oid;
    sp.unk04 = (int)&arg0->m_unk24;
    sp.unk08 = X6F50_1D50[mode];
    sp.unk0C = obj->m_motSpeed;
    sp.unk10 = X6F50_1C90[mode].unk0;
    sp.unk14 = X6F50_1C90[mode].unk4;
    sp.unk18 = f18;
    sp.unk1C = f1c;
    sp.unk3C = X6F50_1C90[mode].unk8;
    sp.unk20 = obj->m_unk06;
    sp.unk28 = arg1;
    sp.unk5C = fparg0;
    Ret1669A4f *ret = X6F50_func_001669A4(obj);
    ACHRstat *stop = arg0->m_achr;
    sp.unk44 = ret->a[0];
    sp.unk48 = ret->a[1];
    sp.unk4C = ret->a[2];
    sp.unk50 = ret->a[3];
    sp.unk58 = ret->f;
    sp.unk54 = mode;
    cStop(stop);
    X6F50_func_00200700(arg0->m_owner->m_unk1F0, &sp);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166F50);
#endif

// NON_MATCHING: 29/85 differ, 2 relocs differ, 27 edits
#ifdef NON_MATCHING
struct Tbl1C90 { float unk0; int unk4; float unk8; int unkC; };
struct Tbl1D80 { float unk0; float unk4; };
struct Ret1669A4 { int a[4]; float f; };
extern int D_002F1D50[];
extern Tbl1D80 D_002F1D80[];
extern Tbl1C90 D_002F1C90[];
extern "C" Ret1669A4 *Xp_func_001669A4(EmyMainView *) asm("func_001669A4");
extern "C" void Xvp_func_00200700(void *, void *) asm("func_00200700");
extern "C" void func_001670DC(EmyOutView *arg0, float *arg1, float fparg0)
{
    struct {
        int unk00;
        int unk04;
        int unk08;
        float unk0C;
        float unk10;
        int unk14;
        float unk18;
        float unk1C;
        int unk20;
        int unk24;
        int unk28;
        float unk2C;
        float unk30;
        float unk34;
        float unk38;
        float unk3C;
        int unk40;
        int unk44;
        int unk48;
        int unk4C;
        int unk50;
        int unk54;
        float unk58;
        float unk5C;
    } sp;

    EmyMainView *obj = arg0->m_owner;
    int mode = obj->getType();
    sp.unk00 = arg0->m_oid;
    sp.unk04 = (int)&arg0->m_unk24;
    sp.unk08 = D_002F1D50[mode];
    obj = arg0->m_owner;
    float d18 = D_002F1D80[mode].unk0;
    float d1c = D_002F1D80[mode].unk4;
    sp.unk0C = obj->m_motSpeed;
    sp.unk10 = D_002F1C90[mode].unk0;
    sp.unk14 = 0;
    sp.unk18 = d18;
    sp.unk1C = d1c;
    sp.unk20 = obj->m_unk06;
    sp.unk5C = fparg0;
    sp.unk2C = arg1[0];
    sp.unk30 = arg1[1];
    sp.unk34 = arg1[2];
    sp.unk3C = D_002F1C90[mode].unk8;
    sp.unk24 = 0;
    sp.unk28 = 0;
    Ret1669A4 *ret = Xp_func_001669A4(obj);
    ACHRstat *stop = arg0->m_achr;
    sp.unk44 = ret->a[0];
    sp.unk48 = ret->a[1];
    sp.unk4C = ret->a[2];
    sp.unk50 = ret->a[3];
    sp.unk54 = mode;
    sp.unk58 = ret->f;
    cStop(stop);
    Xvp_func_00200700(arg0->m_owner->m_unk1F0, &sp);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001670DC);
#endif

// NON_MATCHING: 38/44 differ, 3 relocs differ (size 0xB0, game 0xB8), 14 edits
#ifdef NON_MATCHING
extern "C" void Xvp_func_0020350C(void *, void *) asm("func_0020350C");
extern "C" void func_00167230(EmyOutView *arg0, int arg1, float fparg0)
{
    struct {
        int unk0;
        int unk4;
        int unk8;
        int unkC;
        float unk10;
        float unk14;
    } sp;

    sp.unk8 = (int)&arg0->m_unk28;
    sp.unk0 = arg0->m_oid;
    register GamMan *g PS2_REG("$4") = &D_007812C0;
    register GamMan *g2 PS2_REG("$2") = g;
    EmyMainView *obj = arg0->m_owner;
    sp.unk10 = obj->m_motSpeed;
    ACHRstat *p;
    if (arg1 == 0) {
        p = g->m_pc;
    } else {
        p = g2->m_dog;
    }
    register int id PS2_REG("$4") = 0;
    if (p != 0) {
        id = p->m_oid;
    }
    register int id2 PS2_REG("$2") = id;
    sp.unk4 = id2;
    sp.unk14 = fparg0;
    sp.unkC = obj->getType();
    cStop(arg0->m_achr);
    Xvp_func_0020350C(arg0->m_owner->m_unk1F8, &sp);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167230);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001672E8);

extern "C" int func_0016768C(EmyOutView *arg0, unsigned int arg1)
{
    float pos1[4];
    float pos2[4];
    float mat[16];

    cPos(arg0, pos1);
    cCopy(pos2, cGetBone(D_002F19E0, mat, (cModel *)(D_006FE6A0 + cIndex(&D_007812C0, arg1) * 0x4D0)));
    int *a = Xipp_func_001D7F48(&D_007812C0, pos1, 0);
    int *b = Xipp_func_001D7F48(&D_007812C0, pos2, 0);
    if (a != 0) {
        if (b != 0) {
            if (*a == *b) {
                return 0;
            }
        }
    }
    return 0;
}

inline int flag8(ACHRstat *p) { return (*(int *)p->m_unk3EC) & 8; }
inline int flag16(ACHRstat *p) { return (*(int *)p->m_unk3EC) & 16; }
inline int oneFlag(EmyOutView *a) { return a->m_owner->m_mot[5]; }
inline EmyMainView *objGet(EmyOutView *p) { return p->m_owner; }
inline int bigOffset(char *p) { return (int)(p+0x12540); }
extern int D_002F1DE0[];
extern char D_006E9840[];
extern "C" void qDA228(ACHRstat *,int,unsigned int*) asm("func_001DA228");
extern "C" int qCBEDC(GamMan *,unsigned int) asm("func_001CBEDC");
extern "C" int qCBE38(GamMan *,unsigned int) asm("func_001CBE38");
extern "C" void q33144(int,int,int,int,int,unsigned int,float) asm("func_00133144");
extern "C" int func_001677D0(EmyOutView *arg0, int *arg1, int *arg2) {
    unsigned int sp0, sp4;
    int result;
    register int *out1 PS2_REG("$20") = arg1;
    register int *out2 PS2_REG("$19") = arg2;
    register ACHRstat *flags PS2_REG("$4") = arg0->m_achr;
    if (flag8(flags) && flag16(flags)) {
        EmyMainView *obj = arg0->m_owner;
        result = obj->m_mot[4];
        *out1 = obj->m_mot[13];
        *out2 = arg0->m_owner->m_mot[14];
    } else if (!flag8(flags) && !flag16(flags)) {
        if (arg0->m_owner->getType() == 0 ||
            arg0->m_owner->getType() == 2 ||
            arg0->m_owner->getType() == 1) {
            int n = arg0->m_owner->m_unk06;
            n = n >= 3 ? 0 : n;
            result = D_002F1DE0[n];
            qDA228(arg0->m_achr,0x67,&sp0);
            if ((qCBEDC(&D_007812C0,sp0) ^ 0xa2e) == 0) {
                qDA228(arg0->m_achr,0x67,&sp4);
                int sound = qCBE38(&D_007812C0,sp4);
                q33144(bigOffset(D_006E9840),sound,4,0,0x100,sp4,0.016666694f);
            }
        } else result = arg0->m_owner->m_mot[2];
        *out1 = arg0->m_owner->m_mot[11];
        *out2 = arg0->m_owner->m_mot[12];
    } else {
        result = oneFlag(arg0);
    }
    *out1 = -1;
    *out2 = -1;
    return result;
}

extern "C" int func_001679B4(EmyOutView *arg0, unsigned int arg1, int arg2, float fparg0, float fparg1)
{
    if (!cLookup(&D_007812C0, arg1) || arg0->m_unk24 == 2) {
        Xv_func_00202F10(arg0->m_owner->m_unk1F0);
        return 2;
    }
    if (Xiffii_func_00169BAC(arg2, fparg0, fparg1, arg1, arg0->m_achr) != 0) {
        Xv_func_00202F10(arg0->m_owner->m_unk1F0);
        return 1;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F19E0);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F19F0);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A00);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A10);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A18);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A20);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A28);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A30);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A38);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A40);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A48);
INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A50);

extern "C" int func_00167A64(EmyOutView *arg0,float *arg1,float *arg2) {
    float origin[4], pos[4], mat[16];
    if (!cHas((int)&cGlobalA,arg0->m_achr->m_moveTaskID) ||
        !cLookup(&D_007812C0,arg0->m_targetOid)) {
        cStop(arg0->m_achr);
        return 2;
    }
    cCopy(pos,cGetBone(D_002F19E0,mat,(cModel *)cActor(cIndex(&D_007812C0,arg0->m_targetOid))));
    cPos(arg0,origin);
    cSub(arg1,pos,origin);
    float angle=cAtan(arg1[0],arg1[2]);
    float yaw=cYaw(cActor(cIndex(&D_007812C0,arg0->m_oid)));
    angle=angle-yaw;
    mat[1]=yaw;
    if (angle < -3.14159265358979323846) angle += 6.28318530717958647692;
    if (angle > 3.14159265358979323846) angle -= 6.28318530717958647692;
    *arg2=angle;
    return 0;
}

static inline bool flag1_7CA0(EmyOutView *p) {
    unsigned int flag = (*(unsigned int *)p->m_achr->m_unk3EC) & 1;
    return (unsigned long long)flag != 0;
}
extern "C" int func_00167CA0(EmyOutView *arg0, float *arg1, int arg2, float fparg0, float fparg1, float fparg2)
{
    float x = arg1[0];
    if (x < 0.0f ? (fparg1 <= -x) : (fparg1 <= x)) {
        return 0;
    }
    float z = arg1[2];
    if (z < 0.0f) {
        if (fparg1 <= -z) {
            goto ret0;
        }
    } else {
        if (fparg1 <= z) {
        ret0:
            return 0;
        }
    }
    if (x * x + z * z >= fparg1 * fparg1) {
        return 0;
    }
    if (arg2 == 0) {
        goto ret1;
    }
    if (flag1_7CA0(arg0)) {
    ret1:
        return 1;
    }
    if (fparg0 < 0.0f ? (-fparg0 < fparg2) : (fparg0 < fparg2)) {
        goto ret1;
    }
    return 0;
}

extern "C" void func_00167D88(EmyOutView *arg0, float *arg1, float fparg0)
{
    float rot[4];
    rot[1] = cYaw((int)(D_006FE6A0 + cIndex(&D_007812C0, arg0->m_oid) * 0x4d0));
    func_00166B74(arg0, arg1);
    float x = arg1[0] + Xff_sinf(rot[1]) * fparg0;
    arg1[1] += 0.0f;
    arg1[0] = x;
    arg1[2] += Xff_cosf(rot[1]) * fparg0;
}

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167E38);

extern "C" void func_001680A0(EmyOutView *arg0, int arg1, int arg2)
{
    if (arg2 == 0) {
        arg0->m_owner->m_unk2C = 0;
    }
    float temp_f12 = arg0->m_owner->m_motSpeed;
    float rate;
    if (temp_f12 != 0.0f) {
        rate = temp_f12 * 0.016666666f;
    } else {
        rate = 0.016666666f;
    }
    if (cHas((int)&cGlobalA, arg0->m_achr->m_mtnTaskID) == 0) {
        float angle = cYaw((int)(D_006FE6A0 + cIndex(&D_007812C0, arg0->m_oid) * 0x4D0));
        Xv_func_001F603C(arg0->m_oid, arg1, -1, arg2, rate, angle, 1);
        return;
    }
    Xv_func_001F603C(arg0->m_oid, arg1, -1, arg2, rate, 32769.0f, 1);
}

extern "C" void func_001681C8(EmyOutView *arg0, int arg1, int arg2, float fparg0)
{
    float yaw[4];
    if (arg2 == 0) {
        arg0->m_owner->m_unk2C = 0;
    }
    if (cHas((int)&cGlobalA, arg0->m_achr->m_mtnTaskID) == 0) {
        float angle = cYaw((int)(D_006FE6A0 + cIndex(&D_007812C0, arg0->m_oid) * 0x4D0));
        int handle = arg0->m_oid;
        yaw[1] = angle;
        Xiiii_ffi_func_001F603C(handle, arg1, -1, arg2, fparg0, angle, 1);
    } else {
        Xiiii_ffi_func_001F603C(arg0->m_oid, arg1, -1, arg2, fparg0, 32769.0f, 1);
    }
}

extern "C" void func_001682B0(EmyOutView *arg0)
{
    int temp_v0 = arg0->achrFlags3EC();
    int var_a1;
    if (temp_v0 & 8) {
        if (temp_v0 & 0x10) {
            var_a1 = arg0->m_owner->m_mot[1];
        } else {
            var_a1 = arg0->m_owner->m_mot[0];
        }
    } else {
        var_a1 = arg0->m_owner->m_mot[0];
    }
    float temp_f12 = arg0->m_owner->m_motSpeed;
    float var_f12;
    if (temp_f12 != 0.0f) {
        var_f12 = temp_f12 * 0.016666666f;
    } else {
        var_f12 = 0.016666666f;
    }
    Xiiii_ffi_func_001F603C(arg0->m_oid, var_a1, -1, 0x100, var_f12, 32769.0f, 1);
}

extern "C" void func_0016834C(EmyOutView *arg0)
{
    int temp_v0 = arg0->achrFlags3EC();
    int var_a1;
    if (temp_v0 & 8) {
        if (temp_v0 & 0x10) {
            var_a1 = arg0->m_owner->m_mot[1];
        } else {
            var_a1 = arg0->m_owner->m_mot[0];
        }
    } else {
        var_a1 = arg0->m_owner->m_mot[0];
    }
    float temp_f12 = arg0->m_owner->m_motSpeed;
    float var_f12;
    if (temp_f12 != 0.0f) {
        var_f12 = temp_f12 * 0.016666666f;
    } else {
        var_f12 = 0.016666666f;
    }
    Xiiii_ffi_func_001F603C(arg0->m_oid, var_a1, -1, 0x100, var_f12, 32769.0f, 1);
}

extern "C" void func_001683E8(EmyOutView *arg0)
{
    int temp_v0 = arg0->achrFlags3EC();
    int var_a1;
    if (temp_v0 & 8) {
        if (temp_v0 & 0x10) {
            var_a1 = 0xA;
            goto call;
        }
    }
    var_a1 = 2;
call:
    float temp_f12 = arg0->m_owner->m_motSpeed;
    float var_f12;
    if (temp_f12 != 0.0f) {
        var_f12 = temp_f12 * 0.016666666f;
    } else {
        var_f12 = 0.016666666f;
    }
    Xiiii_ffi_func_001F603C(arg0->m_oid, var_a1, -1, 0, var_f12, 32769.0f, 1);
}

extern "C" void func_00168478(EmyOutView *arg0)
{
    int temp_v0;
    int var_a1;
    ACHRstat *temp_v1;

    if (arg0->m_unk18 == 0) {
        if (!(arg0->m_achr->m_flg & 0x400)) {
            temp_v0 = Xii_func_001442DC(arg0->m_oid);
            var_a1 = 9;
            if ((temp_v0 != 1) && ((temp_v0 >= 2) || (var_a1 = 8, (temp_v0 != 0)))) {
                var_a1 = 0xA;
            }
            Xiiii_func_001680A0(arg0, arg0->m_owner->m_mot[var_a1], 0x100);
            temp_v1 = arg0->m_achr;
            temp_v1->m_flg |= 0x400;
        }
        arg0->m_unk18 = 1;
        arg0->m_unk1C = 1;
    }
}

































INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A78);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A80);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A88);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A90);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1A98);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1AA0);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1AA8);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1AB0);

extern "C" void func_00168520(EmyOutView *arg0)
{
    unsigned int temp_v0_2;
    EmyMainView *temp_v1;

    if (arg0->m_unk1C != 0) {
        arg0->m_unk1C = 0;
        temp_v1 = arg0->m_owner;
        temp_v0_2 = temp_v1->getType();
        switch (temp_v0_2) {
        case 0:
        case 1:
        case 3:
            Xii_func_0016834C(arg0);
            break;
        case 2:
            Xii_func_00168844(arg0);
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            Xii_func_001682B0(arg0);
            break;
        }
    }
    arg0->m_unk18 = 0;
}

extern int D_007A3D80;
extern char D_006FE6A0[];
extern char bGlobal[] asm("D_006E9840");
extern "C" int bE7D7C(int,int) asm("func_001E7D7C");
extern "C" int bCBE38(GamMan *,unsigned int) asm("func_001CBE38");
extern "C" int bCBEDC(GamMan *,unsigned int) asm("func_001CBEDC");
extern "C" float bYaw(int) asm("func_0010A650__8DogActor");
extern "C" void bF603C(int,int,int,int,float,float,int) asm("func_001F603C");
extern "C" void bDA228(ACHRstat *,int,unsigned int*) asm("func_001DA228");
extern "C" void b33144(int,int,int,int,int,unsigned int,float) asm("func_00133144");
inline int bOffset(char *p) { return (int)(p+0x12540); }
inline void bSetYaw(void *out,float v) { ((float *)out)[1] = v; }
extern "C" void func_001685C0(EmyOutView *arg0,int arg1,int arg2) {
    register EmyOutView *self PS2_REG("$16") = arg0;
    int motion = arg1;
    register int flags PS2_REG("$17") = arg2;
    float yaw[4];
    unsigned int sp10,sp14;
    float rate;
    register int mode PS2_REG("$19");
    if (flags == 0) self->m_owner->m_unk2C = 0;
    float v = self->m_owner->m_motSpeed;
    if (v != 0.0f) rate=v*0.016666666f;
    else rate=0.016666666f;
    if (bE7D7C((int)&D_007A3D80,self->m_achr->m_mtnTaskID) == 0) {
        float angle=bYaw((int)D_006FE6A0+bCBE38(&D_007812C0,self->m_oid)*0x4d0);
        int handle=self->m_oid;
        bSetYaw(yaw,angle);
        bF603C(handle,motion,-1,flags,rate,angle,1);
    } else bF603C(self->m_oid,motion,-1,flags,rate,32769.0f,1);
    bDA228(self->m_achr,0x67,&sp10);
    if ((bCBEDC(&D_007812C0,sp10)^0xa2e)==0) {
        switch(motion) {
        case 11: mode=4; break;
        case 10: mode=3; break;
        case 80: mode=12; break;
        case 79: mode=8; break;
        case 76: mode=6; break;
        case 77: mode=7; break;
        case 78: break;
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
        case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35:
        case 36: case 37: case 38: case 39: case 40: case 41: case 42: case 43:
        case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51:
        case 52: case 53: case 54: case 55: case 56: case 57: case 58: case 59:
        case 60: case 61: case 62: case 63: case 64: case 65: case 66: case 67:
        case 68: case 69: case 70: case 71: case 72: case 73: case 74: case 75:
        default:
            mode=2; break;
        }
        bDA228(self->m_achr,0x67,&sp14);
        int id=bCBE38(&D_007812C0,sp14);
        b33144(bOffset(bGlobal),id,mode,0,0x100,sp14,0.016666694f);
    }
}

extern "C" void func_001687BC(EmyOutView *arg0, int arg1, int arg2)
{
    EmyMainView *temp_v1 = arg0->m_owner;
    if (temp_v1->getType() == 2) {
        Xiiii_func_001685C0(arg0, arg1, arg2);
        return;
    }
    Xiiii_func_001680A0(arg0, arg1, arg2);
}

extern "C" void func_00168844(EmyOutView *arg0)
{
    unsigned int sp0, sp4;
    ACHRstat *p8 = arg0->m_achr;
    int flags = *(int *)p8->m_unk3EC;
    int var_s1;
    if (flags & 8) {
        if (flags & 0x10) {
            var_s1 = arg0->m_owner->m_mot[1];
            goto play;
        }
    }
    X844_DA228(p8, 0x67, &sp0);
    if ((X844_CBEDC(&D_007812C0, sp0) ^ 0xA2E) == 0) {
        var_s1 = 0xA;
        X844_DA228(arg0->m_achr, 0x67, &sp4);
        int id = cIndex(&D_007812C0, sp4);
        X844_33144(bigOffset844(X844_D_006E9840), id, 3, 0, 0x100, sp4, 0.016666694f);
    } else {
        var_s1 = arg0->m_owner->m_mot[0];
    }
play:
    float temp_f12 = arg0->m_owner->m_motSpeed;
    float var_f12;
    if (temp_f12 != 0.0f) {
        var_f12 = temp_f12 * 0.016666666f;
    } else {
        var_f12 = 0.016666666f;
    }
    Xiiii_ffi_func_001F603C(arg0->m_oid, var_s1, -1, 0x100, var_f12, 32769.0f, 1);
}

extern "C" void func_0016898C()
{
    X_func_001680A0();
}


extern "C" int func_001689A8(EmyOutView *arg0)
{
    int r = Xiiu_func_001D19A8(&D_007812C0, arg0->m_oid);
    if (r) {
        arg0->m_owner->m_unk2C = 1;
    }
    return r;
}

extern "C" void func_001689E8(EmyOutView *arg0)
{
    int temp_v0_2;
    int *temp_s0;
    EmyMainView *temp_v0;

    temp_v0 = arg0->m_owner;
    temp_s0 = &temp_v0->m_unk1C8;
    temp_v0_2 = temp_v0->m_unk1C8;
    if (temp_v0_2 != 0) {
        temp_s0[1] = 5;
        temp_s0[3] = X_func_00162B14((int)&D_007B2140, temp_v0_2);
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00168A30);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00168EA0);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C10);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C18);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C20);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C28);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C30);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C38);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C40);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C48);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C50);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C58);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C60);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C68);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C70);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C78);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_0016913C);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C88);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1C90);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1D50);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1D80);

INCLUDE_RODATA("asm/nonmatchings/unk/00166AD0", D_002F1DE0);
