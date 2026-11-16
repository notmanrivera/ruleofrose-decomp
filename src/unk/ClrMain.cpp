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

// NON_MATCHING: 154/226 differ, 22 relocs differ (size 0x388, game 0x384), 60 edits
#ifdef NON_MATCHING
extern "C" float Xf_func_001044B8(float, float) asm("func_001044B8");
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_0014F23C(...) asm("func_0014F23C");
extern "C" int X_func_0014F360(...) asm("func_0014F360");
extern "C" int X_func_0014F72C(...) asm("func_0014F72C");
extern "C" int X_func_00166C8C(...) asm("func_00166C8C");
extern "C" int X_func_001693EC(...) asm("func_001693EC");
extern "C" int X_func_0016947C(...) asm("func_0016947C");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" void ClrMoveGetPos(int,int) asm("func_001D890C");
extern "C" int X_func_001D89C4(...) asm("func_001D89C4");
extern "C" int X_func_001D8A8C(...) asm("func_001D8A8C");
extern int D_002EF898;
extern int D_002EF8B0;
extern int D_007B2580;
struct ClrMoveGlobals { char pad[0x22090]; int player; };
extern ClrMoveGlobals clrMoveGlobals asm("D_007812C0");
extern "C" int ClrOutMove__vfunc_03(int arg0)
{
    register int self PS2_REG("$17") = arg0;
    struct { float sp0, sp4, sp8, spC; } stack;
    register int temp_s0 PS2_REG("$16");
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float var_f1;
    int temp_v0;
    register int var_s4 PS2_REG("$20");
    register int rotation PS2_REG("$19");
    register int globals PS2_REG("$18");
    unsigned int temp_v1;
    int temp_a0;

    temp_a0 = M2C_FIELD(self, int *, 0xC);
    temp_v1 = M2C_FIELD(temp_a0, unsigned int *, 0x260);
    var_s4 = -1;
    switch (temp_v1) {
    case 0:
        temp_s0 = self + 0x40;
        X_func_0016649C(temp_a0, 1);
        globals = (int)&D_007812C0;
        X_func_001D1410(globals, M2C_FIELD(self, int *, 0), 0x400);
        M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 0x248) = 1;
        rotation = self + 0x70;
        if (X_func_0010423C(0, 0x64) < 0x32) {
            ClrMoveGetPos(M2C_FIELD(self, int *, 8), temp_s0);
            (*(float *)temp_s0) = Xf_func_001044B8(-340.0f, 340.0f);
            M2C_FIELD(self, float *, 0x48) = Xf_func_001044B8(-340.0f, 340.0f);
        } else {
            X_func_00166C8C(self, (int)&stack);
            ClrMoveGetPos(((ClrMoveGlobals *)globals)->player, (int)&stack);
            ClrMoveGetPos(M2C_FIELD(self, int *, 8), temp_s0);
            (*(float *)temp_s0) = (float) (stack.sp0 + Xf_func_001044B8(-60.0f, 60.0f));
            M2C_FIELD(self, float *, 0x48) = (float) (stack.sp8 + Xf_func_001044B8(-60.0f, 60.0f));
            temp_f0 = (*(float *)temp_s0);
            if (temp_f0 < -340.0f) {
                (*(float *)temp_s0) = -340.0f;
            } else if (temp_f0 > 340.0f) {
                (*(float *)temp_s0) = 340.0f;
            }
            temp_f0_2 = M2C_FIELD(self, float *, 0x48);
            var_f1 = -340.0f;
            if ((temp_f0_2 < -340.0f) || (var_f1 = 340.0f, (temp_f0_2 > 340.0f))) {
                M2C_FIELD(self, float *, 0x48) = var_f1;
            }
        }
        X_func_001D89C4(M2C_FIELD(self, int *, 8), self + 0x40);
        M2C_FIELD(self, int *, 0x74) = 0;
        X_func_001D8A8C(M2C_FIELD(self, int *, 8), rotation);
        X_func_0014F23C(self, 1);
        M2C_FIELD(self, int *, 0xA8) = X_func_0010423C(0x3C, 0x96);
        M2C_FIELD(M2C_FIELD(self, int *, 0xC), unsigned int *, 0x260) = 1U;
    default:
block_27:

        break;
    case 1:
        temp_v0 = M2C_FIELD(self, int *, 0xA8) - 1;
        M2C_FIELD(self, int *, 0xA8) = temp_v0;
        if (temp_v0 == 0xA) {
            X_func_0016947C(self);
            M2C_FIELD(self, int *, 0xAC) = X_func_001694CC(self, ((int *)&D_002EF8B0)[X_func_0010423C(0, 3)]);
        } else if (temp_v0 >= 0xB) {
            X_func_001693EC(self, 4, 0x14, ((int *)&D_002EF898)[X_func_0010423C(0, 5)]);
        }

        if (M2C_FIELD(self, int *, 0xA8) < 0) {
            M2C_FIELD(M2C_FIELD(self, int *, 0xC), unsigned int *, 0x260) = 2U;
            M2C_FIELD(self, float *, 0x94) = 10.0f;
            X_func_0014F72C(self);
            break;
        }
        break;
    case 2:
        temp_f0_3 = M2C_FIELD(self, float *, 0x94) - 1.0f;
        M2C_FIELD(self, float *, 0x94) = temp_f0_3;
        if (temp_f0_3 < 0.0f) {
            M2C_FIELD(self, float *, 0x94) = 0.0f;
            M2C_FIELD(temp_a0, unsigned int *, 0x260) = 3U;
            M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 0x264) = 1;
        }
        break;
    case 3:
        X_func_0014F360(self, 1);
        M2C_FIELD(M2C_FIELD(self, int *, 0xC), unsigned int *, 0x260) = 4U;
        break;
    case 4:

        if (X_func_0014F360(self, 0) == 1) {
            M2C_FIELD(M2C_FIELD(self, int *, 0xC), unsigned int *, 0x260) = 5U;
            break;
        }
        break;
    case 5:
        var_s4 = 0xD;
        X_func_00180EA8((int)&D_007B2580, M2C_FIELD(self, int *, 0xAC));
        break;
    case 8:
        var_s4 = 0xD;
        M2C_FIELD(temp_a0, unsigned int *, 0x260) = 5U;
        break;
    }
    return var_s4;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutMove__vfunc_03);
#endif

extern "C" void ClrOutMove__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F23C);

// NON_MATCHING: 233/240 differ, 18 relocs differ (size 0x3C0, game 0x3CC), 49 edits
#ifdef NON_MATCHING
#define CMF(o,t) M2C_FIELD(arg0,t *,o)
extern "C" void ClrRiseGetPos(int,int) asm("func_001D890C");
extern "C" void ClrRiseSetPos(int,int) asm("func_001D89C4");
extern "C" void ClrRiseEffect(int,int,int,int,int,float,float) asm("func_001F627C");
extern "C" void ClrRiseSound(int,int,int,int,int) asm("func_001E4EBC");
extern "C" int ClrRiseCheck(int,int) asm("func_001D19A8");
extern "C" int ClrRiseNear(int,int,float) asm("func_001F5350");
extern "C" void ClrRiseHit(int,int,int,int,int,int,int) asm("func_001FAC60");
extern "C" void ClrRiseMode(int,int,int) asm("func_001680A0");
extern int D_007A3354;
struct ClrRiseGlobals { char pad[0x22090]; int player;
 int playerID() { int id=0; if(player) id=*(int *)((char *)player+0x100); return id; }
 void sound(int id) { ClrRiseSound((int)this+0x18E00,id,0,0,0); }
};
extern ClrRiseGlobals clrRiseGlobals asm("D_007812C0");
extern "C" int func_0014F360(int arg0, int arg1)
{
    register int result PS2_REG("$19")=0;
    int one=1;
    if(arg1==one) CMF(0x9C,int)=0;
    switch(CMF(0x9C,int)) {
    case 0: {
        CMF(0x90,int)=0;
        CMF(0x9C,int)=one;
        int actor=CMF(0xC,int);
        switch(M2C_FIELD(actor,int *,0x264)) {
        case 0: CMF(0x98,float)=0.0f; break;
        case 1: CMF(0x98,float)=-52.6529855f; break;
        case 2: CMF(0x98,float)=-97.345981f; break;
        }
        M2C_FIELD(actor,int *,0x268)=4;
        ClrRiseGetPos(CMF(8,int),arg0+0x50);
        CMF(0x94,float)=0.0f;
        CMF(0xA0,int)=0;
        CMF(0xA4,int)=0;
        ClrRiseEffect(CMF(0xB0,int),2,-1,0,0,0.0166666667f,32769.0f);
        break;
    }
    case 1: {
        int pos=arg0+0x40;
        ClrRiseGetPos(CMF(8,int),pos);
        float time=CMF(0x94,float);
        float velocity=time*0.8f;
        CMF(0x94,float)=time+1.0f;
        float squared=velocity*velocity;
        CMF(0x44,float)=CMF(0x54,float)+squared+time+1.0f;
        int interval=3;
        if((int)CMF(0x94,float)%interval==0)
            ClrRiseEffect(CMF(0xB0,int),2,-1,0,0,0.0166666667f,32769.0f);
        interval=10;
        if((int)CMF(0x94,float)%interval==0)
            clrRiseGlobals.sound(0x1F010597);
        float height=CMF(0x98,float);
        if(height<=CMF(0x44,float)) {
            CMF(0x44,float)=height;
            ClrRiseMode(arg0,9,0);
            CMF(0x9C,int)=2;
            CMF(0x94,float)=0.0f;
        }
        ClrRiseSetPos(CMF(8,int),pos);
        if(CMF(0xA0,int)==0) {
            int player=clrRiseGlobals.playerID();
            if(ClrRiseNear(CMF(0,int),player,60.0f)) {
                ClrRiseHit(11,CMF(0,int),0,0,0x31,player,0);
                CMF(0xA0,int)=1;
                clrRiseGlobals.sound(0x1F0105AC);
            }
        }
        if(CMF(0xA4,int)==0) {
            int player=0;
            if(D_007A3354) player=M2C_FIELD(D_007A3354,int *,0x100);
            if(ClrRiseNear(CMF(0,int),player,60.0f)) {
                ClrRiseHit(11,CMF(0,int),0,0,0x31,player,0);
                CMF(0xA4,int)=1;
            }
        }
        break;
    }
    case 2: {
        int check=ClrRiseCheck((int)&D_007812C0,CMF(0,int));
        if(check) {
            M2C_FIELD(CMF(0xC,int),int *,0x2C)=one;
            if(check) {
                CMF(0xA0,int)=0;
                CMF(0x9C,int)=9999;
                result=1;
                ClrRiseMode(arg0,1,0x100);
            }
        }
        break;
    }
    case 9999: result=1; break;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F360);
#endif

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

// NON_MATCHING: 232/242 differ, 26 relocs differ (size 0x3C8, game 0x3D4), 123 edits
#ifdef NON_MATCHING
extern "C" int ClrAttackRandom(int,int) asm("func_0010423C");
extern "C" int X_func_001506A0(...) asm("func_001506A0");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" void ClrAttackSound(int,int,int,int,int) asm("func_001E4EBC");
extern "C" void ClrAttackCamera(int,void *) asm("func_001F9D90");
extern "C" int func_0014FEBC(int arg0, int arg1)
{
    register int globals PS2_REG("$16") = (int)&D_007812C0;
    register int self PS2_REG("$18") = arg0;
    struct { int target; int pad4; int camera; char padC[12]; int motion; int frames; int mode; int flags; float distance; int pad2C; } stack;
    int temp_a1;
    int temp_a4;
    int temp_a5;
    int temp_a5_2;
    int temp_v0;
    int temp_v0_2;
    int temp_v1;
    register int var_s1 PS2_REG("$17");
    unsigned int var_v1;

    M2C_FIELD(self, int *, 0x194) = 0;
    M2C_FIELD(self, int *, 0x190) = 0;
    temp_v1 = M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 0x24C);
    var_s1 = 0x5A;
    if (temp_v1 < 2) {
        var_s1 = 0x46;
        if (temp_v1 == 0) {
            if (arg1 != 0) {
                goto block_10;
            }
            var_s1 = 0x28;
            goto block_6;
        }
    }
block_6:
    if (ClrAttackRandom(0, 0x63) < var_s1) {
    X_func_0016649C(M2C_FIELD(self, int *, 0xC), 0);
    X_func_001D10D0(globals, M2C_FIELD(self, int *, 0), 0x400);
    M2C_FIELD(self, int *, 0x184) = -1;
    return 0xD;
    }
block_10:
        temp_v0 = ClrAttackRandom(0, 0x63);
        temp_a1 = M2C_FIELD(self, int *, 0x184);
        var_s1 = 0x14;
        if (temp_v0 >= 0x28) {
            var_s1 = (temp_v0 >= 0x50) ? 0x13 : 0x12;
        }
        if (temp_a1 >= 0) {
            var_s1 = ((temp_a1 ^ 0x14) != 0) ? 0x14 : var_s1;
        }
        if (M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 0x14) != 0) {
            var_v1 = var_s1 - 3;
            if (ClrAttackRandom(0, 0x63) < 0x50) {
                temp_v0_2 = X_func_001506A0(self);
                var_s1 = ((temp_v0_2 ^ 2) == 0) ? 4 : (((temp_v0_2 ^ 1) == 0) ? 3 : var_s1);
                goto block_17;
            }
        } else {
block_17:
            var_v1 = var_s1 - 3;
        }
        M2C_FIELD(self, int *, 0x180) = var_s1;
        switch (var_v1) {
        case 15:
            temp_a5 = M2C_FIELD(self, int *, 0x14);
            stack.target = temp_a5;
            stack.camera = 0x2F;
            stack.motion = 0x12;
            stack.frames = 0xF;
            stack.mode = 1;
            stack.flags = 5;
            stack.distance = 25.0f;
            ClrAttackCamera(M2C_FIELD(self,int *,0),&stack);
            M2C_FIELD(self, int *, 0x178) = 0xA;
            M2C_FIELD(self, int *, 4) = 2;
            M2C_FIELD(self, int *, 0x17C) = 0x78;
            X_func_0016649C(M2C_FIELD(self, int *, 0xC), 0);
block_24:
            X_func_001D10D0(globals, M2C_FIELD(self, int *, 0), 0x400);
            break;
        case 16:
            temp_a5_2 = M2C_FIELD(self, int *, 0x14);
            stack.target = temp_a5_2;
            stack.camera = 0x30;
            stack.motion = 0x13;
            stack.frames = 0xF;
            stack.mode = 1;
            stack.flags = 5;
            stack.distance = 25.0f;
            ClrAttackCamera(M2C_FIELD(self,int *,0),&stack);
            M2C_FIELD(self, int *, 0x178) = 0xA;
            M2C_FIELD(self, int *, 4) = 2;
            M2C_FIELD(self, int *, 0x17C) = 0x12C;
            X_func_0016649C(M2C_FIELD(self, int *, 0xC), 0);
            goto block_24;
        case 17:
            X_func_0016649C(M2C_FIELD(self, int *, 0xC), 1);
            X_func_001D1410(globals, M2C_FIELD(self, int *, 0), 0x400);
            temp_a4 = M2C_FIELD(self, int *, 0x14);
            stack.target = temp_a4;
            stack.camera = 0x2E;
            stack.motion = 0x14;
            stack.frames = 0xA;
            stack.mode = 1;
            stack.flags = 5;
            stack.distance = 80.0f;
            ClrAttackCamera(M2C_FIELD(self,int *,0),&stack);
            ClrAttackSound(globals + 0x18E00, 0x1F0105AC, 0, 0, 0);
            M2C_FIELD(self, int *, 0x178) = 0;
            M2C_FIELD(self, int *, 4) = 1;
            break;
        case 1:
            M2C_FIELD(self, int *, 0x198) = 0;
            M2C_FIELD(self, int *, 4) = 5;
            X_func_001680A0(self, var_s1, 0);
            M2C_FIELD(self, float *, 0x188) = 0.09519977308809757f;
            X_func_001D1410(globals, M2C_FIELD(self, int *, 0), 0x40);
            X_func_001D10D0(globals, M2C_FIELD(self, int *, 0), 0x10000000);
            goto block_24;
        case 0:
            M2C_FIELD(self, int *, 4) = 5;
            M2C_FIELD(self, int *, 0x198) = 1;
            X_func_001680A0(self, var_s1, 0);
            M2C_FIELD(self, float *, 0x188) = -0.09519977308809757f;
            X_func_001D1410(globals, M2C_FIELD(self, int *, 0), 0x40);
            X_func_001D10D0(globals, M2C_FIELD(self, int *, 0), 0x10000000);
            X_func_001D10D0(globals, M2C_FIELD(self, int *, 0), 0x400);
            break;
        }
        X_func_0016649C(M2C_FIELD(self, int *, 0xC), 1);
        X_func_001D1410(globals, M2C_FIELD(self, int *, 0), 0x400);
        M2C_FIELD(self, int *, 0x184) = (int) M2C_FIELD(self, int *, 0x180);
        return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014FEBC);
#endif

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

