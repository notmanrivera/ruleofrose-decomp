#include "ror.h"
#include "include_asm.h"
extern "C" int Xiiiiif_func_001F603C(int, int, int, int, float) asm("func_001F603C");
extern "C" int *Xipp_func_001D7F48(int, float *, int) asm("func_001D7F48");
extern "C" void Xv_func_001F603C(int, int, int, int, float, float, int) asm("func_001F603C");
extern "C" float Xff_sinf(float) asm("sinf");
extern "C" float Xff_cosf(float) asm("cosf");
extern "C" void Xv_func_00202F10(int) asm("func_00202F10");
extern "C" int Xiffii_func_00169BAC(int, float, float, int, int) asm("func_00169BAC");
extern "C" void Xv_func_0016A6B4(float *) asm("func_0016A6B4");
extern "C" void Xv_func_0016A7AC(float *) asm("func_0016A7AC");
extern "C" void Xv_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" void Xiiii_func_001685C0(int, int, int) asm("func_001685C0");
extern "C" int Xiiu_func_001D19A8(int, unsigned int) asm("func_001D19A8");
extern "C" int Xiiii_ffi_func_001F603C(int, int, int, int, float, float, int) asm("func_001F603C");
extern "C" float *func_001D2B8C(int, unsigned int);
extern "C" void func_001D890C(float *, float *);
extern char D_006FE6A0 [];
extern int cGlobalA asm("D_007A3D80");
extern char cActors[] asm("D_006FBD80");
extern char D_002F19E0[],D_002F19F0[],D_002F1A00[],D_002F1A10[];
extern "C" int cHas(int,int) asm("func_001E7D7C");
extern "C" int cLookup(int,unsigned int) asm("func_001D046C");
extern "C" int cIndex(int,unsigned int) asm("func_001CBE38");
extern "C" void cStop(int) asm("func_001DA07C");
extern "C" void cPos(int,float*) asm("func_00166B74");
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
struct m2c_v200_18_i { char pad[512]; virtual void v1(); virtual void v2(); virtual int call(); };
extern "C" int Xii_func_001682B0(int) asm("func_001682B0");
extern "C" int Xii_func_0016834C(int) asm("func_0016834C");
extern "C" int Xii_func_00168844(int) asm("func_00168844");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_001442DC(int) asm("func_001442DC");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
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
extern int D_007812C0;
extern int D_007B2140;
extern int D_007B2580;

extern "C" void func_00166AD0(int arg0)
{
    int temp_v0;

    X_func_0016649C((*(int *)(int *)((char *)(arg0) + 0xC)), 1);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    X_func_00202F10((*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0x1F0)));
    (*(int *)(int *)((char *)((*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0x1F8))) + 0x4)) = 0;
    X_func_001DA07C((*(int *)(int *)((char *)(arg0) + 0x8)));
    X_func_0016649C((*(int *)(int *)((char *)(arg0) + 0xC)), 1);
    (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0x2C)) = 1;
    (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0xC))) + 0x10)) = 0;
    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x2C));
    if (temp_v0 >= 0) {
        X_func_00180EA8((int)&D_007B2580, temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0x2C)) = -1;
    }
}


extern "C" void func_00166B74(unsigned int *arg0, float *arg1) {
    float sp[4];
    float mat[16];
    float *temp_s3 = func_001D2B8C((int)&D_007812C0, *arg0);
    cCopy(arg1, cGetBone(D_002F19E0, mat, (cModel *)(D_006FE6A0 + cIndex((int)&D_007812C0, *arg0) * 0x4d0)));
    func_001D890C(temp_s3, sp);
    arg1[1] = sp[1];
}

extern "C" void func_00166C8C(unsigned int *arg0, float *arg1) {
    float sp[4];
    float mat[16];
    float *temp_s3 = func_001D2B8C((int)&D_007812C0, arg0[5]);
    cCopy(arg1, cGetBone(D_002F19E0, mat, (cModel *)(D_006FE6A0 + cIndex((int)&D_007812C0, arg0[5]) * 0x4d0)));
    func_001D890C(temp_s3, sp);
    arg1[1] = sp[1];
}

// NON_MATCHING: 15/68 differ, 17 edits
#ifdef NON_MATCHING
extern "C" int Xffiii_func_00169BAC(float, float, int, int, int) asm("func_00169BAC");
extern "C" int Xiii_func_0010423C(int, int) asm("func_0010423C");
extern "C" void func_00166DA4(int arg0, int arg1)
{
    register int self PS2_REG("$16") = arg0;
    register int g PS2_REG("$3") = (int)&D_007812C0;
    register int one PS2_REG("$20") = 1;
    int temp_a2 = M2C_FIELD(self, int *, 8);
    register int dog PS2_REG("$18") = M2C_FIELD(M2C_FIELD(g, int *, 0x22094), int *, 0x100);
    register int rate PS2_REG("$19") = (M2C_FIELD(temp_a2, int *, 0x3EC) & 1) ? 0x64 : arg1;
    register int pc PS2_REG("$17") = M2C_FIELD(M2C_FIELD(g, int *, 0x22090), int *, 0x100);
    if (rate < 0x63) {
        register float f60 PS2_REG("$f21") = 60.0f;
        register float f2pi PS2_REG("$f20") = 6.283185124397278f;
        if (Xffiii_func_00169BAC(f60, f2pi, 0, pc, temp_a2) == 0) {
            if (Xffiii_func_00169BAC(f60, f2pi, 0, dog, M2C_FIELD(self, int *, 8)) != 0 ||
                Xiii_func_0010423C(0, 0x63) >= rate) {
                M2C_FIELD(self, int *, 0x14) = dog;
                M2C_FIELD(self, int *, 0x10) = one;
                return;
            }
        }
    }
    M2C_FIELD(self, int *, 0x14) = pc;
    M2C_FIELD(self, int *, 0x10) = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166DA4);
#endif

extern "C" void func_00166EB4(int arg0, int arg1)
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

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166F50);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001670DC);

// NON_MATCHING: 38/44 differ, 3 relocs differ (size 0xB0, game 0xB8), 14 edits
#ifdef NON_MATCHING
extern "C" void Xvp_func_0020350C(int, void *) asm("func_0020350C");
extern "C" void func_00167230(int arg0, int arg1, float fparg0)
{
    struct {
        int unk0;
        int unk4;
        int unk8;
        int unkC;
        float unk10;
        float unk14;
    } sp;

    sp.unk8 = arg0 + 0x28;
    sp.unk0 = M2C_FIELD(arg0, int *, 0);
    int obj = M2C_FIELD(arg0, int *, 0xC);
    sp.unk10 = M2C_FIELD(obj, float *, 0x1C4);
    register int g PS2_REG("$4") = (int)&D_007812C0;
    int p;
    if (arg1 == 0) {
        p = M2C_FIELD(g, int *, 0x22090);
    } else {
        p = M2C_FIELD(g, int *, 0x22094);
    }
    int id = 0;
    if (p != 0) {
        id = M2C_FIELD(p, int *, 0x100);
    }
    sp.unk4 = id;
    sp.unk14 = fparg0;
    sp.unkC = ((m2c_v200_18_i *)obj)->call();
    cStop(M2C_FIELD(arg0, int *, 8));
    Xvp_func_0020350C(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F8), &sp);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167230);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001672E8);

extern "C" int func_0016768C(int arg0, unsigned int arg1)
{
    float pos1[4];
    float pos2[4];
    float mat[16];

    cPos(arg0, pos1);
    cCopy(pos2, cGetBone(D_002F19E0, mat, (cModel *)(D_006FE6A0 + cIndex((int)&D_007812C0, arg1) * 0x4D0)));
    int *a = Xipp_func_001D7F48((int)&D_007812C0, pos1, 0);
    int *b = Xipp_func_001D7F48((int)&D_007812C0, pos2, 0);
    if (a != 0) {
        if (b != 0) {
            if (*a == *b) {
                return 0;
            }
        }
    }
    return 0;
}

// NON_MATCHING: 17/119 differ (size 0x1DC, game 0x1E4), 6 edits
#ifdef NON_MATCHING
inline int flag8(int p) { return (*(int *)((char *)p+0x3ec)) & 8; }
inline int flag16(int p) { return (*(int *)((char *)p+0x3ec)) & 16; }
inline int oneFlag(int a) { return *(int *)((char *)*(int *)((char *)a+12)+0x100); }
inline int objGet(int p) { return *(int *)((char *)p+12); }
inline int bigOffset(char *p) { return (int)(p+0x12540); }
extern int D_002F1DE0[];
extern char D_006E9840[];
extern "C" void qDA228(int,int,unsigned int*) asm("func_001DA228");
extern "C" int qCBEDC(int,unsigned int) asm("func_001CBEDC");
extern "C" int qCBE38(int,unsigned int) asm("func_001CBE38");
extern "C" void q33144(int,int,int,int,int,unsigned int,float) asm("func_00133144");
extern "C" int func_001677D0(int arg0, int *arg1, int *arg2) {
    unsigned int sp0, sp4;
    int result;
    register int *out1 PS2_REG("$20") = arg1;
    register int *out2 PS2_REG("$19") = arg2;
    register int flags PS2_REG("$4") = M2C_FIELD(arg0,int *,8);
    int obj = M2C_FIELD(arg0,int *,12);
    if (flag8(flags) && flag16(flags)) {
        result = M2C_FIELD(obj,int *,0xfc);
        *out1 = M2C_FIELD(obj,int *,0x120);
        *out2 = M2C_FIELD(M2C_FIELD(arg0,int *,12),int *,0x124);
    } else {
        obj = objGet(arg0);
        if (!flag8(flags) && !flag16(flags)) {
            if (((m2c_v200_18_i*)obj)->call() == 0 ||
                ((m2c_v200_18_i*)M2C_FIELD(arg0,int *,12))->call() == 2 ||
                ((m2c_v200_18_i*)M2C_FIELD(arg0,int *,12))->call() == 1) {
                int n = M2C_FIELD(M2C_FIELD(arg0,int *,12),unsigned char *,6);
                n = n >= 3 ? 0 : n;
                result = D_002F1DE0[n];
                qDA228(M2C_FIELD(arg0,int *,8),0x67,&sp0);
                if ((qCBEDC((int)&D_007812C0,sp0) ^ 0xa2e) == 0) {
                    qDA228(M2C_FIELD(arg0,int *,8),0x67,&sp4);
                    int sound = qCBE38((int)&D_007812C0,sp4);
                    q33144(bigOffset(D_006E9840),sound,4,0,0x100,sp4,0.016666694f);
                }
            } else result = M2C_FIELD(M2C_FIELD(arg0,int *,12),int *,0xf4);
            *out1 = M2C_FIELD(M2C_FIELD(arg0,int *,12),int *,0x118);
            *out2 = M2C_FIELD(M2C_FIELD(arg0,int *,12),int *,0x11c);
        } else result = oneFlag(arg0);
    }
    *out1 = -1;
    *out2 = -1;
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001677D0);
#endif

extern "C" int func_001679B4(int arg0, unsigned int arg1, int arg2, float fparg0, float fparg1)
{
    if (!cLookup((int)&D_007812C0, arg1) || M2C_FIELD(arg0, int *, 0x24) == 2) {
        Xv_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
        return 2;
    }
    if (Xiffii_func_00169BAC(arg2, fparg0, fparg1, arg1, M2C_FIELD(arg0, int *, 8)) != 0) {
        Xv_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
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

extern "C" int func_00167A64(int arg0,float *arg1,float *arg2) {
    float origin[4], pos[4], mat[16];
    if (!cHas((int)&cGlobalA,M2C_FIELD(M2C_FIELD(arg0,int *,8),int *,0x3d4)) ||
        !cLookup((int)&D_007812C0,M2C_FIELD(arg0,unsigned int *,0x14))) {
        cStop(M2C_FIELD(arg0,int *,8));
        return 2;
    }
    cCopy(pos,cGetBone(D_002F19E0,mat,(cModel *)cActor(cIndex((int)&D_007812C0,M2C_FIELD(arg0,unsigned int *,0x14)))));
    cPos(arg0,origin);
    cSub(arg1,pos,origin);
    float angle=cAtan(arg1[0],arg1[2]);
    float yaw=cYaw(cActor(cIndex((int)&D_007812C0,M2C_FIELD(arg0,unsigned int *,0))));
    angle=angle-yaw;
    mat[1]=yaw;
    if (angle < -3.14159265358979323846) angle += 6.28318530717958647692;
    if (angle > 3.14159265358979323846) angle -= 6.28318530717958647692;
    *arg2=angle;
    return 0;
}

// NON_MATCHING: 20/57 differ (size 0xE4, game 0xE8), 3 edits
#ifdef NON_MATCHING
static inline bool flag1_7CA0(int p) { return (*(int *)(*(int *)((char *)p + 8) + 0x3EC) & 1); }
extern "C" int func_00167CA0(int arg0, float *arg1, int arg2, float fparg0, float fparg1, float fparg2)
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
#else
INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167CA0);
#endif

extern "C" void func_00167D88(unsigned int *arg0, float *arg1, float fparg0)
{
    float rot[4];
    rot[1] = cYaw((int)(D_006FE6A0 + cIndex((int)&D_007812C0, *arg0) * 0x4d0));
    func_00166B74(arg0, arg1);
    float x = arg1[0] + Xff_sinf(rot[1]) * fparg0;
    arg1[1] += 0.0f;
    arg1[0] = x;
    arg1[2] += Xff_cosf(rot[1]) * fparg0;
}

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167E38);

extern "C" void func_001680A0(int arg0, int arg1, int arg2)
{
    if (arg2 == 0) {
        M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x2C) = 0;
    }
    float temp_f12 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), float *, 0x1C4);
    float rate;
    if (temp_f12 != 0.0f) {
        rate = temp_f12 * 0.016666666f;
    } else {
        rate = 0.016666666f;
    }
    if (cHas((int)&cGlobalA, M2C_FIELD(M2C_FIELD(arg0, int *, 8), int *, 0x3DC)) == 0) {
        float angle = cYaw((int)(D_006FE6A0 + cIndex((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0)) * 0x4D0));
        Xv_func_001F603C(M2C_FIELD(arg0, int *, 0), arg1, -1, arg2, rate, angle, 1);
        return;
    }
    Xv_func_001F603C(M2C_FIELD(arg0, int *, 0), arg1, -1, arg2, rate, 32769.0f, 1);
}

extern "C" void func_001681C8(int arg0, int arg1, int arg2, float fparg0)
{
    float yaw[4];
    if (arg2 == 0) {
        M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x2C) = 0;
    }
    if (cHas((int)&cGlobalA, M2C_FIELD(M2C_FIELD(arg0, int *, 8), int *, 0x3DC)) == 0) {
        float angle = cYaw((int)(D_006FE6A0 + cIndex((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0)) * 0x4D0));
        int handle = M2C_FIELD(arg0, int *, 0);
        yaw[1] = angle;
        Xiiii_ffi_func_001F603C(handle, arg1, -1, arg2, fparg0, angle, 1);
    } else {
        Xiiii_ffi_func_001F603C(M2C_FIELD(arg0, int *, 0), arg1, -1, arg2, fparg0, 32769.0f, 1);
    }
}

extern "C" void func_001682B0(int arg0)
{
    int temp_v0 = M2C_FIELD(M2C_FIELD(arg0, int *, 8), int *, 0x3EC);
    int var_a1;
    if (temp_v0 & 8) {
        if (temp_v0 & 0x10) {
            var_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0xF0);
        } else {
            var_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0xEC);
        }
    } else {
        var_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0xEC);
    }
    float temp_f12 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), float *, 0x1C4);
    float var_f12;
    if (temp_f12 != 0.0f) {
        var_f12 = temp_f12 * 0.016666666f;
    } else {
        var_f12 = 0.016666666f;
    }
    Xiiii_ffi_func_001F603C(M2C_FIELD(arg0, int *, 0), var_a1, -1, 0x100, var_f12, 32769.0f, 1);
}

extern "C" void func_0016834C(int arg0)
{
    int temp_v0 = M2C_FIELD(M2C_FIELD(arg0, int *, 8), int *, 0x3EC);
    int var_a1;
    if (temp_v0 & 8) {
        if (temp_v0 & 0x10) {
            var_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0xF0);
        } else {
            var_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0xEC);
        }
    } else {
        var_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0xEC);
    }
    float temp_f12 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), float *, 0x1C4);
    float var_f12;
    if (temp_f12 != 0.0f) {
        var_f12 = temp_f12 * 0.016666666f;
    } else {
        var_f12 = 0.016666666f;
    }
    Xiiii_ffi_func_001F603C(M2C_FIELD(arg0, int *, 0), var_a1, -1, 0x100, var_f12, 32769.0f, 1);
}

extern "C" void func_001683E8(int arg0)
{
    int temp_v0 = M2C_FIELD(M2C_FIELD(arg0, int *, 8), int *, 0x3EC);
    int var_a1;
    if (temp_v0 & 8) {
        if (temp_v0 & 0x10) {
            var_a1 = 0xA;
            goto call;
        }
    }
    var_a1 = 2;
call:
    float temp_f12 = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), float *, 0x1C4);
    float var_f12;
    if (temp_f12 != 0.0f) {
        var_f12 = temp_f12 * 0.016666666f;
    } else {
        var_f12 = 0.016666666f;
    }
    Xiiii_ffi_func_001F603C(M2C_FIELD(arg0, int *, 0), var_a1, -1, 0, var_f12, 32769.0f, 1);
}

extern "C" void func_00168478(int arg0)
{
    int temp_v0;
    int var_a1;
    int temp_v1;

    if (M2C_FIELD(arg0, int *, 0x18) == 0) {
        if (!(M2C_FIELD(M2C_FIELD(arg0, int *, 8), int *, 0x120) & 0x400)) {
            temp_v0 = Xii_func_001442DC(M2C_FIELD(arg0, int *, 0));
            var_a1 = 9;
            if ((temp_v0 != 1) && ((temp_v0 >= 2) || (var_a1 = 8, (temp_v0 != 0)))) {
                var_a1 = 0xA;
            }
            Xiiii_func_001680A0(arg0, M2C_FIELD(((var_a1 * 4) + M2C_FIELD(arg0, int *, 0xC)), int *, 0xEC), 0x100);
            temp_v1 = M2C_FIELD(arg0, int *, 8);
            M2C_FIELD(temp_v1, int *, 0x120) = (int) (M2C_FIELD(temp_v1, int *, 0x120) | 0x400);
        }
        M2C_FIELD(arg0, int *, 0x18) = 1;
        M2C_FIELD(arg0, int *, 0x1C) = 1;
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

extern "C" void func_00168520(int arg0)
{
    unsigned int temp_v0_2;
    int temp_v0;
    int temp_v1;

    if (M2C_FIELD(arg0, int *, 0x1C) != 0) {
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        temp_v1 = M2C_FIELD(arg0, int *, 0xC);
        temp_v0_2 = ((m2c_v200_18_i *)(temp_v1))->call();
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
    M2C_FIELD(arg0, int *, 0x18) = 0;
}

// NON_MATCHING: 4/127 differ, 4 edits
#ifdef NON_MATCHING
extern int D_007A3D80;
extern char D_006FE6A0[];
extern char bGlobal[] asm("D_006E9840");
extern "C" int bE7D7C(int,int) asm("func_001E7D7C");
extern "C" int bCBE38(int,unsigned int) asm("func_001CBE38");
extern "C" int bCBEDC(int,unsigned int) asm("func_001CBEDC");
extern "C" float bYaw(int) asm("func_0010A650__8DogActor");
extern "C" void bF603C(int,int,int,int,float,float,int) asm("func_001F603C");
extern "C" void bDA228(int,int,unsigned int*) asm("func_001DA228");
extern "C" void b33144(int,int,int,int,int,unsigned int,float) asm("func_00133144");
inline int bOffset(char *p) { return (int)(p+0x12540); }
inline void bSetYaw(void *out,float v) { ((float *)out)[1] = v; }
extern "C" void func_001685C0(int arg0,int arg1,int arg2) {
    register int self PS2_REG("$16") = arg0;
    register int motion PS2_REG("$18") = arg1;
    register int flags PS2_REG("$17") = arg2;
    float yaw[4];
    unsigned int sp10,sp14;
    float rate;
    register int mode PS2_REG("$19");
    if (flags == 0) M2C_FIELD(M2C_FIELD(self,int *,12),int *,0x2c)=0;
    float v = M2C_FIELD(M2C_FIELD(self,int *,12),float *,0x1c4);
    if (v != 0.0f) rate=v*0.016666666f;
    else rate=0.016666666f;
    if (bE7D7C((int)&D_007A3D80,M2C_FIELD(M2C_FIELD(self,int *,8),int *,0x3dc)) == 0) {
        float angle=bYaw((int)D_006FE6A0+bCBE38((int)&D_007812C0,M2C_FIELD(self,int *,0))*0x4d0);
        int handle=M2C_FIELD(self,int *,0);
        bSetYaw(yaw,angle);
        bF603C(handle,motion,-1,flags,rate,angle,1);
    } else bF603C(M2C_FIELD(self,int *,0),motion,-1,flags,rate,32769.0f,1);
    bDA228(M2C_FIELD(self,int *,8),0x67,&sp10);
    if ((bCBEDC((int)&D_007812C0,sp10)^0xa2e)==0) {
        unsigned int select = motion-10;
        if ((unsigned)select >= 71) mode=2; else
        switch(select) {
        case 1: mode=4; break;
        case 0: mode=3; break;
        case 70: mode=12; break;
        case 69: mode=8; break;
        case 66: mode=6; break;
        case 67: mode=7; break;
        case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
case 8:
case 9:
case 10:
case 11:
case 12:
case 13:
case 14:
case 15:
case 16:
case 17:
case 18:
case 19:
case 20:
case 21:
case 22:
case 23:
case 24:
case 25:
case 26:
case 27:
case 28:
case 29:
case 30:
case 31:
case 32:
case 33:
case 34:
case 35:
case 36:
case 37:
case 38:
case 39:
case 40:
case 41:
case 42:
case 43:
case 44:
case 45:
case 46:
case 47:
case 48:
case 49:
case 50:
case 51:
case 52:
case 53:
case 54:
case 55:
case 56:
case 57:
case 58:
case 59:
case 60:
case 61:
case 62:
case 63:
case 64:
case 65:
case 68:
        default: mode=2; break;
        }
        bDA228(M2C_FIELD(self,int *,8),0x67,&sp14);
        int id=bCBE38((int)&D_007812C0,sp14);
        b33144(bOffset(bGlobal),id,mode,0,0x100,sp14,0.016666694f);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001685C0);
#endif

extern "C" void func_001687BC(int arg0, int arg1, int arg2)
{
    int temp_v1 = M2C_FIELD(arg0, int *, 0xC);
    if (((m2c_v200_18_i *)(temp_v1))->call() == 2) {
        Xiiii_func_001685C0(arg0, arg1, arg2);
        return;
    }
    Xiiii_func_001680A0(arg0, arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00168844);

extern "C" void func_0016898C()
{
    X_func_001680A0();
}


extern "C" int func_001689A8(int arg0)
{
    int r = Xiiu_func_001D19A8((int)&D_007812C0, *(unsigned int *)arg0);
    if (r) {
        *(int *)(*(int *)(arg0 + 0xC) + 0x2C) = 1;
    }
    return r;
}

extern "C" void func_001689E8(int arg0)
{
    int temp_v0_2;
    int temp_s0;
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0xC));
    temp_s0 = temp_v0 + 0x1C8;
    temp_v0_2 = (*(int *)(int *)((char *)(temp_v0) + 0x1C8));
    if (temp_v0_2 != 0) {
        (*(int *)(int *)((char *)(temp_s0) + 0x4)) = 5;
        (*(int *)(int *)((char *)(temp_s0) + 0xC)) = X_func_00162B14((int)&D_007B2140, temp_v0_2);
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
