#include "ror.h"
#include "include_asm.h"
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


INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166B74);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166C8C);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166DA4);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166EB4);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00166F50);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001670DC);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167230);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001672E8);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_0016768C);

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

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001679B4);

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

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167CA0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167D88);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00167E38);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001680A0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001681C8);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001682B0);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_0016834C);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001683E8);

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

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001687BC);

INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_00168844);

extern "C" void func_0016898C()
{
    X_func_001680A0();
}


INCLUDE_ASM("asm/nonmatchings/unk/00166AD0", func_001689A8);

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
