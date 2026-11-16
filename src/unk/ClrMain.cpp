#include "include_asm.h"
#include "ror.h"
extern "C" int Xii_func_00202F10(int) asm("func_00202F10");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int Xiiiiff_func_001679B4(int, int, int, float, float) asm("func_001679B4");
extern "C" int Xiiiiff_func_00169BAC(int, int, int, float, float) asm("func_00169BAC");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfff_func_001044B8(float, float) asm("func_001044B8");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001044B8(...) asm("func_001044B8");
extern "C" int X_func_0014E2EC(...) asm("func_0014E2EC");
extern "C" int X_func_0014E300(...) asm("func_0014E300");
extern "C" int X_func_0014E314(...) asm("func_0014E314");
extern "C" int X_func_0014E328(...) asm("func_0014E328");
extern "C" int X_func_0014E33C(...) asm("func_0014E33C");
extern "C" int X_func_0014E350(...) asm("func_0014E350");
extern "C" int X_func_0014E364(...) asm("func_0014E364");
extern "C" int X_func_0014E36C(...) asm("func_0014E36C");
extern "C" int X_func_0014E374(...) asm("func_0014E374");
extern "C" int X_func_0014E37C(...) asm("func_0014E37C");
extern "C" int X_func_0014E384(...) asm("func_0014E384");
extern "C" int X_func_0014E38C(...) asm("func_0014E38C");
extern "C" int X_func_00165A68(...) asm("func_00165A68");
extern "C" int X_func_00165AA8(...) asm("func_00165AA8");
extern "C" int X_func_00165D7C(...) asm("func_00165D7C");
extern "C" int X_func_0016649C(...) asm("func_0016649C");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(...) asm("func_00166DA4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_00169BAC(...) asm("func_00169BAC");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern int D_007812C0;
extern int D_007A3350;
extern int D_007B205C;

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_07);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_01);

// NON_MATCHING: 3/128 differ, 3 edits
#ifdef NON_MATCHING
extern "C" void ClrMain__vfunc_04(int arg0)
{
    int temp_v0;
    int var_v0;
    int temp_v1;

    if ((M2C_FIELD(arg0, int *, 0x28) != 0) && (M2C_FIELD(arg0, int *, 0x2C) != 0) && (M2C_FIELD(arg0, int *, 0x24) == -1)) {
        if ((M2C_FIELD(arg0, int *, 0x23C) != 0) && (X_func_0014E364() != 0)) {
            M2C_FIELD(arg0, int *, 0x24) = 0xD;
        }
        if ((M2C_FIELD(arg0, int *, 0x238) != 0) && (X_func_0014E36C(arg0) != 0)) {
            M2C_FIELD(arg0, int *, 0x24) = 0xC;
        }
        if ((M2C_FIELD(arg0, int *, 0x234) != 0) && (X_func_0014E374(arg0) != 0)) {
            M2C_FIELD(arg0, int *, 0x24) = 0xB;
        }
        if ((M2C_FIELD(arg0, int *, 0x230) != 0) && (X_func_0014E37C(arg0) != 0)) {
            M2C_FIELD(arg0, int *, 0x24) = 0xA;
        }
        if ((M2C_FIELD(arg0, int *, 0x22C) != 0) && (X_func_0014E384(arg0) != 0)) {
            M2C_FIELD(arg0, int *, 0x24) = 9;
        }
        temp_v1 = X_func_0014E38C(arg0);
        temp_v0 = temp_v1 & 0xFF;
        if (M2C_FIELD(arg0, unsigned char *, 0x204) != 0) {
            M2C_FIELD(arg0, unsigned char *, 0x204) = temp_v1;
            if (temp_v0 == 0) {
                
                if (M2C_FIELD(arg0, int *, 0x210) != 0) {
                    M2C_FIELD(arg0, int *, 0x24) = 2;
                }
            } else {
                if ((M2C_FIELD(arg0, int *, 0x214) != 0) && (X_func_0014E2EC(arg0) != 0)) {
                    M2C_FIELD(arg0, int *, 0x24) = 3;
                }
                if ((M2C_FIELD(arg0, int *, 0x218) != 0) && (X_func_0014E300(arg0) != 0)) {
                    M2C_FIELD(arg0, int *, 0x24) = 4;
                }
                if ((M2C_FIELD(arg0, int *, 0x21C) != 0) && (X_func_0014E314(arg0) != 0)) {
                    M2C_FIELD(arg0, int *, 0x24) = 5;
                }
                if ((M2C_FIELD(arg0, int *, 0x220) != 0) && (X_func_0014E328(arg0) != 0)) {
                    M2C_FIELD(arg0, int *, 0x24) = 6;
                }
                if ((M2C_FIELD(arg0, int *, 0x224) != 0) && (X_func_0014E33C(arg0) != 0)) {
                    M2C_FIELD(arg0, int *, 0x24) = 7;
                }
                if (M2C_FIELD(arg0, int *, 0x228) != 0) {
                    
                    if (X_func_0014E350(arg0) != 0) {
                        M2C_FIELD(arg0, int *, 0x24) = 8;
                    }
                }
            }
        } else {
            M2C_FIELD(arg0, unsigned char *, 0x204) = temp_v1;
            if (temp_v0 != 0) {
                if (M2C_FIELD(arg0, int *, 0x208) != 0) {
                    M2C_FIELD(arg0, int *, 0x24) = 0;
                }
                
                if (M2C_FIELD(arg0, int *, 0x20C) != 0) {
block_44:
                    M2C_FIELD(arg0, int *, 0x24) = 1;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_04);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_02);

extern "C" int func_0014E2EC()
{
    return X_func_00165A68();
}


extern "C" int func_0014E300()
{
    return X_func_00165A68();
}


extern "C" int func_0014E314()
{
    return X_func_00165AA8();
}


extern "C" int func_0014E328()
{
    return X_func_00165AA8();
}


extern "C" int func_0014E33C()
{
    return X_func_00165D7C();
}


extern "C" int func_0014E350()
{
    return X_func_00165D7C();
}


extern "C" int func_0014E364()
{
    return 0;
}


extern "C" int func_0014E36C()
{
    return 0;
}


extern "C" int func_0014E374()
{
    return 0;
}


extern "C" int func_0014E37C()
{
    return 0;
}


extern "C" int func_0014E384()
{
    return 0;
}


extern "C" int func_0014E38C(int arg0)
{
    int var_a1;

    var_a1 = 0;
    if ((*(int *)&D_007A3350) != 0) {
        var_a1 = M2C_FIELD((*(int *)&D_007A3350), int *, 0x100);
    }
    return Xiiiiff_func_00169BAC(1, var_a1, M2C_FIELD(arg0, int *, 0x20), 0.0f, 2.356194317340851f);
}

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E3D0);

// NON_MATCHING: 129/143 differ, 8 relocs differ (size 0x23C, game 0x268), 81 edits
#ifdef NON_MATCHING
extern "C" void X_func_001E4EBC(int,int,int,int,int) asm("func_001E4EBC");
extern "C" void X_func_001FAC60(int,int,int,int,int,int,int) asm("func_001FAC60");
extern "C" int Xiiiif_func_0016A424(int, int, int, float) asm("func_0016A424");
struct ClrGlobals { char sound[0x18E00]; char soundObject[0x9290]; int player0; int player1; };
extern ClrGlobals clrGlobals asm("D_007812C0");
extern "C" int func_0014E4D4(int arg0)
{
    struct { int sp0; } stack;
    int temp_s1_2;
    int temp_v1;
    int var_v1;
    int temp_s0;
    int temp_s0_2;
    int temp_s1;
    int temp_v0;
    int temp_v0_2;
    register int var_fp PS2_REG("$30");
    int var_s3;
    int var_s5;
    int var_s6;
    register int var_s7 PS2_REG("$23");

    var_s7 = 0;
    var_fp = 0;
    if (clrGlobals.player0 != 0) {
        var_fp = M2C_FIELD(clrGlobals.player0, int *, 0x100);
    }
    stack.sp0 = 0;
    var_s6 = 0;
    if (clrGlobals.player1 != 0) {
        stack.sp0 = M2C_FIELD(clrGlobals.player1, int *, 0x100);
    }
    var_s5 = arg0 + 0x288;
    var_s3 = 0x270;
    do {
        temp_s1 = arg0 + 4;
        if (*(int *)(temp_s1 + var_s3) != 0) {
            temp_s0 = arg0 + 8;
            var_v1 = temp_s0 + var_s3;
            if (*(int *)(temp_s0 + var_s3) == 1) {
                if (M2C_FIELD((arg0 + var_s3), int *, 0x10) == 0) {
                    if ((var_s6 % 20) == 0) {
                        X_func_001E4EBC((int)&clrGlobals.soundObject, 0x1F010594, 0, 0, 0);
                    }
                } else {
                    X_func_001E4EBC((int)&clrGlobals.soundObject, 0x1F010594, 0, 0, 0);
                }
                var_v1 = temp_s0 + var_s3;
            }
            temp_v0 = (*(int *)(var_v1));
            if (temp_v0 <= 0) {
                temp_v1 = arg0 + 0xC + var_s3;
                temp_v0_2 = (*(int *)(temp_v1));
                if (temp_v0_2 <= 0) {
                    *(int *)(temp_s1 + var_s3) = 0;
                } else {
                    (*(int *)(temp_v1)) = temp_v0_2 - 1;
                }
                temp_s0_2 = arg0 + 4;
                temp_s1_2 = temp_s0_2 + ((var_s6 << 5) + 0x280);
                if (Xiiiif_func_0016A424(var_s5, 1, var_fp, (*(float *)(temp_s1_2))) == 1) {
                    var_s7 = 1;
                    *(int *)(temp_s0_2 + var_s3) = 0;
                }
                if (Xiiiif_func_0016A424(var_s5, 1, stack.sp0, (*(float *)(temp_s1_2))) == 1) {
                    var_s7 = 2;
                    *(int *)(temp_s0_2 + var_s3) = 0;
                }
            } else {
                (*(int *)(var_v1)) = temp_v0 - 1;
            }
        }
        var_s6 += 1;
        var_s5 += 0x20;
        var_s3 += 0x20;
    } while (var_s6 < 0x40);
    if (var_s7 & 1) {
        X_func_001FAC60(0xB, (*(int *)(arg0)), 0, 0, 0x32, var_fp, 0);
    }
    if (var_s7 & 2) {
        X_func_001FAC60(0xB, (*(int *)(arg0)), 0, 0, 0x32, stack.sp0, 0);
    }
    return var_s7;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E4D4);
#endif

extern "C" void ClrOutUp__vfunc_02(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0xAC)) = (int) (*(int *)(int *)((char *)(D_007B205C) + 0x788));
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutUp__vfunc_03);

extern "C" void ClrOutUp__vfunc_04()
{
    X_func_00166AD0();
}


// NON_MATCHING: 146/191 differ, 10 relocs differ (size 0x2FC, game 0x304), 10 edits
#ifdef NON_MATCHING
#define F(o,t) (*(t *)((char *)arg0 + (o)))
extern "C" void clrSetMode(int,int,int) asm("func_001680A0");
extern "C" int clrCheck(int,int) asm("func_001D19A8");
extern "C" void clrGetPos(int,float *) asm("func_001D890C");
extern "C" void clrSetPos(int,float *) asm("func_001D89C4");
extern "C" void clrEffect(int,int,int,int,int,float,float) asm("func_001F627C");
extern "C" void clrSound(int,int,int,int,int) asm("func_001E4EBC");
inline void clrMaybeMode(int obj,int flag) { if(flag) clrSetMode(obj,10,0x100); }
extern "C" int func_0014E850(int arg0, int arg1)
{
    int result = 0;
    X_func_0016649C(F(0xC,int),0);
    X_func_001D10D0((int)&D_007812C0,F(0,int),0x400);
    if(arg1 == 1) F(0x9C,int)=0;
    switch(F(0x9C,int)) {
    case 0:
        F(0x9C,int)=1;
        F(0xA8,int)=0;
        F(0x90,int)=0;
        clrSetMode(arg0,10,0x100);
        F(0x94,float)=0.0f;
    case 1: {
        int check=clrCheck((int)&D_007812C0,F(0,int));
        if(check) {
            M2C_FIELD(F(0xC,int),int *,0x2C)=1;
            clrMaybeMode(arg0,check);
        }
        float *pos=(float *)((char *)arg0+0x40);
        clrGetPos(F(8,int),pos);
        F(0x94,float) += 1.0f;
        if(((int)F(0x94,float)&3)==0)
            clrEffect(F(0xAC,int),2,-1,0,0,0.0166666667f,32769.0f);
        int interval=20;
        if((int)F(0x94,float)%interval==0)
            clrSound((int)&D_007812C0+0x18E00,0x1F010596,0,0,0);
        F(0x44,float) -= 4.0f;
        if(F(0x44,float)<=-347.34599f) {
            pos[0]=-800.0f;
            result=1;
            F(0x44,float)=-347.34599f;
            F(0x48,float)=-800.0f;
            clrSetMode(arg0,1,0x100);
            F(0x9C,int)=2;
            F(0x94,float)=0.0f;
        }
        clrSetPos(F(8,int),pos);
        break;
    }
    case 9999: result=1; break;
    case 2: {
        int interval=3;
        if((int)F(0x94,float)%interval==0)
            clrEffect(F(0xAC,int),2,-1,0,0,0.0166666667f,32769.0f);
        if((int)F(0x94,float)>=121) F(0x9C,int)=3;
        F(0x94,float)+=1.0f;
        break;
    }
    case 3: F(0x9C,int)=9999; break;
    }
    if(F(0xA8,int)==1) {
        X_func_0016649C(F(0xC,int),0);
        X_func_001D10D0((int)&D_007812C0,F(0,int),0x400);
    }
    if(F(0xA8,int)==0) {
        if(M2C_FIELD(F(0xC,int),int *,0x30)&1) F(0xA8,int)=1;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E850);
#endif

extern "C" void ClrOutDeathUp__vfunc_02(int arg0)
{
    int temp_a0;

    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x40);
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x10000000);
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    temp_a0 = (*(int *)(int *)((char *)(arg0) + 0xC));
    if ((*(int *)(int *)((char *)(temp_a0) + 0x260)) == 5) {
        (*(int *)(int *)((char *)(temp_a0) + 0x260)) = 6;
    }
}


// D_002EF7B8: the end of unk/MrtMain's .rodata now (config/splits_manual.tsv)

// D_002EF7C8: the end of unk/MrtMain's .rodata now (config/splits_manual.tsv)

// D_002EF7D8: the end of unk/MrtMain's .rodata now (config/splits_manual.tsv)

// D_002EF7E8: the end of unk/MrtMain's .rodata now (config/splits_manual.tsv)

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutDeathUp__vfunc_03);

extern "C" void ClrOutDeathUp__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014ED10);

extern "C" void ClrOutMove__vfunc_02(int arg0)
{
    X_func_0016649C((*(int *)(int *)((char *)(arg0) + 0xC)), 1);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    X_func_00166DA4(arg0, 0x64);
    (*(int *)(int *)((char *)(arg0) + 0xB0)) = (int) (*(int *)(int *)((char *)(D_007B205C) + 0x788));
}


INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF828);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutMove__vfunc_03);

extern "C" void ClrOutMove__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F23C);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F360);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F72C);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutAtk__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF868);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF870);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF878);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF880);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF888);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF898);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8B0);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutAtk__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8D8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8E0);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8E8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8F0);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014FEBC);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_00150290);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_001506A0);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF950);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF960);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF970);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF978);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF980);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF988);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF990);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF998);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF9A0);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF9A8);

// NON_MATCHING: 125/127 differ, 24 relocs differ (size 0x1FC, game 0x218), 85 edits
#ifdef NON_MATCHING
struct ClrVec { float x,y,z; };
extern "C" float Xfiiifff_func_001D4A3C(int, int, int, float, float, float) asm("func_001D4A3C");
extern "C" int X_func_001CBE38(int, int) asm("func_001CBE38");
extern "C" int X_func_0022B3D8(...) asm("func_0022B3D8");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern "C" int Xiiif_func_00169B0C(int, int, float) asm("func_00169B0C");
extern const char D_002EF950[];
extern const char D_002EF960[];
extern const char D_002EF970[];
extern int D_006FBD80;
struct m2c_v94_88_iii { char pad[148]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual int call(int, int); };
extern "C" int func_00150804(int arg0, int arg1)
{
    struct { char pad0[16]; float sp10; float sp14; float sp18; char pad1C[4]; char sp20[48]; float sp50; float sp54; float sp58; float sp5C; } stack;
    int temp_v0;
    int var_s1;
    float temp_f20;
    int temp_s0;
    int temp_s0_2;
    int temp_v1;
    int temp_v1_2;

    temp_v0 = (int) "Bip01 Spine1";
    temp_s0 = ((X_func_001CBE38((int)&D_007812C0, 0) * 0x4D0) + ((int)&D_006FBD80)) + 0x2920;
    if (M2C_FIELD(temp_s0, int *, 0x11C) == 0) {
        X_ror_assert((int) D_002EF950, 0x131, (int) D_002EF960);
    }
    if (temp_v0 == 0) {
        X_ror_assert((int) D_002EF950, 0x131, (int) D_002EF970);
    }
    ((m2c_v94_88_iii *)(temp_s0))->call((int)&stack.sp20, X_func_0022B3D8(M2C_FIELD(temp_s0, int *, 0x11C), temp_v0));
    temp_f20 = Xfiiifff_func_001D4A3C((int)&D_007812C0, arg1, 0, stack.sp50, stack.sp54, stack.sp58) + 32.0f;
    if (M2C_FIELD(arg0, int *, 0x198) != 0) {
        var_s1 = (int) "nodel_p_arm_r";
    } else {
        var_s1 = (int) "nodel_p_arm_l";
    }
    temp_s0_2 = ((X_func_001CBE38((int)&D_007812C0, M2C_FIELD(arg0, int *, 0)) * 0x4D0) + ((int)&D_006FBD80)) + 0x2920;
    if (M2C_FIELD(temp_s0_2, int *, 0x11C) == 0) {
        X_ror_assert((int) D_002EF950, 0x131, (int) D_002EF960);
    }
    if (var_s1 == 0) {
        X_ror_assert((int) D_002EF950, 0x131, (int) D_002EF970);
    }
    ((m2c_v94_88_iii *)(temp_s0_2))->call((int)&stack.sp20, X_func_0022B3D8(M2C_FIELD(temp_s0_2, int *, 0x11C), var_s1));
    float *position = &stack.sp10;
    position[0] = stack.sp50;
    stack.sp14 = stack.sp54;
    stack.sp18 = stack.sp58;
    return Xiiif_func_00169B0C((int)&stack.sp10, (int)&stack, temp_f20) != 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_00150804);
#endif

extern "C" int func_00150A1C()
{
    return 0;
}


extern "C" void ClrOutAtk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void ClrOutWin__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, float *, 0x38) = Xfff_func_001044B8(100.0f, 200.0f);
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
    M2C_FIELD(arg0, int *, 4) = 0;
}

extern "C" int ClrOutWin__vfunc_03(int arg0)
{
    if ((M2C_FIELD(arg0, int *, 4) == 0) && (Xiiiiff_func_001679B4(arg0, M2C_FIELD(arg0, int *, 0x14), 1, M2C_FIELD(arg0, float *, 0x38), 0.7853981405496597f) != 0)) {
        Xii_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
        Xiiii_func_001680A0(arg0, 0x15, 0x100);
        M2C_FIELD(arg0, int *, 4) = 1;
    }
    return -1;
}

extern "C" void ClrOutWin__vfunc_04()
{
    X_func_00166AD0();
}

