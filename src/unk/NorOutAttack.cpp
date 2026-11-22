#include "include_asm.h"
#include "emy/emy.h"
#define F20_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int F20_Xii_func_00118FEC__9MagSystem(int) asm("func_00118FEC__9MagSystem");
extern "C" int F20_Xii_func_00119090__9MagSystem(int) asm("func_00119090__9MagSystem");
extern "C" int F20_Xii_func_001517E0(int) asm("func_001517E0");
extern "C" int F20_Xii_func_00202F10(int) asm("func_00202F10");
extern "C" int F20_Xiii_func_0016649C(int, int) asm("func_0016649C");
extern "C" int F20_Xiii_func_001694CC(int, int) asm("func_001694CC");
extern "C" int F20_Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int F20_Xiiu_func_001D19A8(int, unsigned int) asm("func_001D19A8");
extern "C" int F20_Xiiui_func_001D10D0(int, unsigned int, int) asm("func_001D10D0");
extern "C" int F20_Xiiui_func_001D1410(int, unsigned int, int) asm("func_001D1410");
extern "C" int F20_Xiuiiiiui_func_001FAC60(unsigned int, int, int, int, int, unsigned int, int) asm("func_001FAC60");
extern "C" int F20_Xiuiuf_func_0016A1DC(unsigned int, int, unsigned int, float) asm("func_0016A1DC");
inline void f20Inc(int *p) { (*p)++; }
inline void f20Hit(int arg0, unsigned int var_a2) { int temp_v0_4; if (F20_Xiuiuf_func_0016A1DC(F20_FIELD(arg0, unsigned int *, 0), 2, var_a2, 20.0f) != 0) {
                temp_v0_4 = F20_FIELD(arg0, int *, 0xC);
                f20Inc((int *)(temp_v0_4 + 0x23C));
                F20_Xiii_func_001694CC(arg0, 0x50);
                F20_FIELD(arg0, int *, 0x60) = 1;
                F20_Xiuiiiiui_func_001FAC60(0xBU, (int) F20_FIELD(arg0, unsigned int *, 0), 0, 0, 0x21, var_a2, 0);
            } }
extern int f19pc asm("D_007A3350");
extern int f19other asm("D_007A3354");
extern "C" int F19_Xii_func_00118FEC__9MagSystem(int) asm("func_00118FEC__9MagSystem");
extern "C" int F19_Xii_func_00119090__9MagSystem(int) asm("func_00119090__9MagSystem");
extern "C" int F19_Xii_func_00202F10(int) asm("func_00202F10");
extern "C" int F19_Xiii_func_0016649C(int, int) asm("func_0016649C");
extern "C" int F19_Xiii_func_001694CC(int, int) asm("func_001694CC");
extern "C" int F19_Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int F19_Xiiu_func_001D19A8(int, unsigned int) asm("func_001D19A8");
extern "C" int F19_Xiiui_func_001D10D0(int, unsigned int, int) asm("func_001D10D0");
extern "C" int F19_Xiiui_func_001D1410(int, unsigned int, int) asm("func_001D1410");
extern "C" int F19_Xiuiiiiui_func_001FAC60(unsigned int, int, int, int, int, unsigned int, int) asm("func_001FAC60");
extern "C" int F19_Xiuiuf_func_0016A1DC(unsigned int, int, unsigned int, float) asm("func_0016A1DC");
inline unsigned int f19Range(int n, int lo, int hi) { if (n < lo) return 0; if (n > hi) return 0; return 1; }
extern int f19world asm("D_007812C0");
inline int f19Done(int world, int obj) { int r = F19_Xiiu_func_001D19A8(world, *(unsigned int *)obj); if (r) *(int *)(*(int *)(obj + 12) + 44) = 1; return r; }
#define F19_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
inline void f19Hit(int arg0, unsigned int var_a2) { if (F19_Xiuiuf_func_0016A1DC(F19_FIELD(arg0, unsigned int *, 0), 4, var_a2, 55.0f) != 0) {
                    F19_FIELD(arg0, int *, 0x60) = 1;
                    F19_Xiii_func_001694CC(arg0, 0x51);
                    F19_Xiuiiiiui_func_001FAC60(0xBU, (int) F19_FIELD(arg0, unsigned int *, 0), 0, 0, 0x23, var_a2, 0);
                } }
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xi_func_001536CC() asm("func_001536CC");
extern "C" int Xii_func_001517E0(int) asm("func_001517E0");
extern "C" int Xii_func_001519B8(int) asm("func_001519B8");
extern "C" int Xii_func_00151F1C(int) asm("func_00151F1C");
extern "C" int Xii_func_001520CC(int) asm("func_001520CC");
extern "C" int Xii_func_00152544(int) asm("func_00152544");
extern "C" int Xiii_func_0010423C(int, int) asm("func_0010423C");
extern "C" int Xiii_func_0016649C(int, int) asm("func_0016649C");
extern "C" int Xiii_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" int Xiii_func_001694CC(int, int) asm("func_001694CC");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
extern "C" int Xiiif_func_00167230(int, int, float) asm("func_00167230");
extern "C" int Xiiii_func_00104394(int, int, int) asm("func_00104394");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00104394(...) asm("func_00104394");
extern "C" int X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_0013166C(...) asm("func_0013166C");
extern "C" int X_func_001513EC(...) asm("func_001513EC");
extern "C" int X_func_001517E0(...) asm("func_001517E0");
extern "C" int X_func_001519B8(...) asm("func_001519B8");
extern "C" int X_func_00151F1C(...) asm("func_00151F1C");
extern "C" int X_func_001520CC(...) asm("func_001520CC");
extern "C" int X_func_0015246C(...) asm("func_0015246C");
extern "C" int X_func_00152544(...) asm("func_00152544");
extern "C" int X_func_00152F3C(...) asm("func_00152F3C");
extern "C" int X_func_001536CC(...) asm("func_001536CC");
extern "C" int X_func_0016649C(...) asm("func_0016649C");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(...) asm("func_00166DA4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_00167230(...) asm("func_00167230");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_001693EC(...) asm("func_001693EC");
extern "C" int X_func_0016947C(...) asm("func_0016947C");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001FAC60(...) asm("func_001FAC60");
extern int D_006E9840;
extern int D_007812C0;
extern int D_007B205C;

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_001515C4);

extern "C" void NorOutAttack__vfunc_02(int arg0)
{
    Xiii_func_00166DA4(arg0, 0x64);
    M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x150) = 0;
    Xii_func_001517E0(arg0);
}

extern "C" int NorOutAttack__vfunc_03(int arg0)
{
    int temp_v1;
    int var_a1;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x40);
    var_a1 = -1;
    switch (temp_v1) {                              
    case 0:
        var_v0 = Xii_func_001520CC(arg0);
block_11:
        var_a1 = var_v0;
        break;
    case 1:
        var_v0 = Xii_func_00152544(arg0);
        goto block_11;
    case 2:
        var_v0 = Xii_func_001519B8(arg0);
        goto block_11;
    case 3:
        var_v0 = Xii_func_00151F1C(arg0);
        goto block_11;
    }
    return var_a1;
}

extern "C" void NorOutAttack__vfunc_04(int arg0)
{
    X_func_00166AD0();
    (*(int *)(int *)((char *)(D_007B205C) + 0x650)) = 0;
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x04000000);
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x40);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x10000000);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    X_func_0016649C((*(int *)(int *)((char *)(arg0) + 0xC)), 1);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
}


INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_001517E0);

extern "C" void func_0015195C(int arg0)
{
    int temp_v0;

    M2C_FIELD(arg0, int *, 0x3C) = 0;
    M2C_FIELD(arg0, int *, 0x48) = 0;
    M2C_FIELD(arg0, int *, 0x54) = 0;
    M2C_FIELD(arg0, int *, 0x40) = 0;
    temp_v0 = Xiiii_func_00104394(0xA, 0x96, 3);
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0x38) = temp_v0;
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 88.5f);
}

extern "C" int func_001519B8(int arg0)
{
    float var_f1;
    float var_f1_2;
    int temp_a0_2;
    int temp_s2;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    unsigned int var_a0;
    int var_s3;
    int var_v0;
    unsigned int var_v1;
    register unsigned int var_a2 PS2_REG("$6");
    unsigned int var_s0;
    int temp_a0;

    temp_v1 = M2C_FIELD(arg0, int *, 4);
    var_s3 = -1;
    switch (temp_v1) {                              
    case 0:
        if (M2C_FIELD(arg0, int *, 0x24) != 0) {
            F19_Xii_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
            temp_s2 = M2C_FIELD(arg0, int *, 0x24);
            if (temp_s2 == 1) {
            F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x20000000);
            F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x40);
            F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x10000000);
            F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
            F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x04000000);
            F19_Xiii_func_001694CC(arg0, 0x54);
            F19_Xiii_func_001694CC(arg0, 0x62);
            F19_Xiiii_func_001680A0(arg0, 0x2B, 0);
            M2C_FIELD(arg0, int *, 4) = temp_s2;
            } else return 9;
        }
        break;
    case 1:
        temp_v1_2 = M2C_FIELD(arg0, int *, 0x48) + 1;
        M2C_FIELD(arg0, int *, 0x48) = temp_v1_2;
        var_f1 = (float)f19Range(temp_v1_2, 15, 55);
        if (var_f1 != 0.0f) {
            F19_Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 0);
            F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
        } else {
            F19_Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 1);
            F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
        }
        var_f1_2 = (float)f19Range(M2C_FIELD(arg0, int *, 0x48), 20, 50);
        if (var_f1_2 != 0.0f) {
            if ((M2C_FIELD(arg0, int *, 0x60) == 0) && (F19_Xii_func_00118FEC__9MagSystem((int) (int)&D_006E9840) != 9)) {
                var_a2 = 0;
                if (f19pc != 0) {
                    var_a2 = M2C_FIELD(f19pc, unsigned int *, 0x100);
                }
                f19Hit(arg0, var_a2);
            }
            if (M2C_FIELD(arg0, int *, 0x64) == 0) {
                if ((F19_Xii_func_00119090__9MagSystem((int) (int)&D_006E9840) != 0xA) && (F19_Xii_func_00119090__9MagSystem((int) (int)&D_006E9840) != 0xD)) {
                    var_s0 = 0;
                    if (f19other != 0) {
                        var_s0 = M2C_FIELD(f19other, unsigned int *, 0x100);
                    }
                    if (F19_Xiuiuf_func_0016A1DC(M2C_FIELD(arg0, unsigned int *, 0), 4, var_s0, 55.0f) != 0) {
                        M2C_FIELD(arg0, int *, 0x64) = 1;
                        F19_Xiii_func_001694CC(arg0, 0x51);
                        F19_Xiuiiiiui_func_001FAC60(0xBU, (int) M2C_FIELD(arg0, unsigned int *, 0), 0, 0, 0x23, var_s0, 0);
                    }
                }
            }
        }
        if (f19Done((int)&D_007812C0, arg0)) {
                var_s3 = 8;
                F19_Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 1);
                F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
                F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x40);
                F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x10000000);
                F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
                F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x04000000);
        }
        break;
    default:
        break;
    }
    return var_s3;
}

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA50);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA60);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA70);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA98);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFAB8);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFAD8);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00151D4C);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00151F1C);

extern "C" int func_001520CC(int arg0)
{
    float var_f1;
    int temp_v0_2;
    int temp_v1;
    int temp_v1_2;
    int var_v1;
    unsigned int temp_a0_3;
    unsigned int temp_v0;
    unsigned int temp_v0_3;
    register unsigned int var_a2 PS2_REG("$6");
    unsigned int var_s1;
    int temp_a0;
    int temp_a0_2;
    int temp_v0_4;
    int temp_v1_3;

    switch (M2C_FIELD(arg0, int *, 4)) {
    case 0:
            temp_v1_2 = M2C_FIELD(arg0, int *, 0x24);
            if (temp_v1_2 == 2) {
                F20_Xii_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
                return 9;
            }
            if ((temp_v1_2 == 1) || ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x3C) >= (unsigned int) M2C_FIELD(arg0, unsigned int *, 0x38))) {
                F20_Xii_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
                F20_Xiii_func_001694CC(arg0, 0x53);
                F20_Xiii_func_001694CC(arg0, 0x63);
                M2C_FIELD(arg0, int *, 0x64) = 0;
                M2C_FIELD(arg0, int *, 0x60) = 0;
                F20_Xiiii_func_001680A0(arg0, 0x1C, 0);
                M2C_FIELD(arg0, unsigned int *, 0x48) = 0U;
                M2C_FIELD(arg0, int *, 4) = 1;
            }
            
            break;
    case 1:
    temp_a0_2 = M2C_FIELD(arg0, int *, 0xC);
    temp_v0_3 = M2C_FIELD(arg0, unsigned int *, 0x48) + 1;
    M2C_FIELD(arg0, unsigned int *, 0x48) = temp_v0_3;
    if (temp_v0_3 >= 0xFU) {
        F20_Xiii_func_0016649C(temp_a0_2, 0);
        F20_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
    } else {
        F20_Xiii_func_0016649C(temp_a0_2, 1);
        F20_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
    }
    var_f1 = (float)f19Range(M2C_FIELD(arg0, int *, 0x48), 19, 25);
    if (var_f1 != 0.0f) {
        if ((M2C_FIELD(arg0, int *, 0x60) == 0) && (F20_Xii_func_00118FEC__9MagSystem((int) (int)&D_006E9840) != 9)) {
            var_a2 = 0;
            if (f19pc != 0) {
                var_a2 = M2C_FIELD(f19pc, unsigned int *, 0x100);
            }
            f20Hit(arg0, var_a2);
        }
        temp_v1_3 = M2C_FIELD(arg0, int *, 0xC);
        if (((M2C_FIELD(temp_v1_3, int *, 0x218) == 0) || (M2C_FIELD(temp_v1_3, int *, 0x230) != 0)) && (M2C_FIELD(arg0, int *, 0x64) == 0) && (F20_Xii_func_00119090__9MagSystem((int) (int)&D_006E9840) != 0xA) && (F20_Xii_func_00119090__9MagSystem((int) (int)&D_006E9840) != 0xD)) {
            var_s1 = 0;
            if (f19other != 0) {
                var_s1 = M2C_FIELD(f19other, unsigned int *, 0x100);
            }
            if (F20_Xiuiuf_func_0016A1DC(M2C_FIELD(arg0, unsigned int *, 0), 2, var_s1, 20.0f) != 0) {
                F20_Xiii_func_001694CC(arg0, 0x50);
                M2C_FIELD(arg0, int *, 0x64) = 1;
                F20_Xiuiiiiui_func_001FAC60(0xBU, (int) M2C_FIELD(arg0, unsigned int *, 0), 0, 0, 0x21, var_s1, 0);
            }
        }
    }
    if (M2C_FIELD(arg0, unsigned int *, 0x48) == 0x19) {
        M2C_FIELD(arg0, int *, 4) = 3;
    }
    break;
    case 3:
        temp_a0 = M2C_FIELD(arg0, int *, 0xC);
        temp_v0 = M2C_FIELD(arg0, unsigned int *, 0x48) + 1;
        M2C_FIELD(arg0, unsigned int *, 0x48) = temp_v0;
        if (temp_v0 < 0x1EU) {
            F20_Xiii_func_0016649C(temp_a0, 0);
            F20_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
        } else {
            F20_Xiii_func_0016649C(temp_a0, 1);
            F20_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
        }
        if (f19Done((int)&D_007812C0, arg0)) {
                F20_Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 1);
                F20_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
                M2C_FIELD(arg0, unsigned int *, 0x48) = 0U;
                F20_Xii_func_001517E0(arg0);
        }
        break;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_0015246C);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB28);

// NON_MATCHING: 81/126 differ, 18 relocs differ (size 0x1F8, game 0x204), 11 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_001442DC(int) asm("func_001442DC");
extern "C" int Xii_func_00144308(int) asm("func_00144308");
extern "C" int Xii_func_0015195C(int) asm("func_0015195C");
extern "C" int Xii_func_0015246C(int) asm("func_0015246C");
extern "C" int Xii_func_00152748(int) asm("func_00152748");
extern "C" int Xii_func_00152B24(int) asm("func_00152B24");
extern "C" int Xii_func_00152BB4(int) asm("func_00152BB4");
extern "C" int Xii_func_00152C60(int) asm("func_00152C60");
extern "C" int Xii_func_00152CFC(int) asm("func_00152CFC");
extern "C" int Xii_func_00152DA4(int) asm("func_00152DA4");
extern "C" int Xii_func_00152E40(int) asm("func_00152E40");
extern "C" int Xii_func_00152E90(int) asm("func_00152E90");
extern "C" int Xii_func_00202F10(int) asm("func_00202F10");
extern "C" int Xiiif_func_00167D88(int, int, float) asm("func_00167D88");
extern "C" int Xiiiiiff_func_0017C340(int, int, int, int, float, float) asm("func_0017C340");
extern "C" int Xiiui_func_001D10D0(int, unsigned int, int) asm("func_001D10D0");
extern "C" int Xiiui_func_001D1410(int, unsigned int, int) asm("func_001D1410");
extern int D_006FBD80;
extern "C" int func_00152544(int arg0)
{
    struct { char pad0[16]; int sp10; int sp14; char pad18[8]; } stack;
    register int minusOne PS2_REG("$16") = -1;
    int var_v0;
    unsigned int temp_s2;
    unsigned int temp_v1;

    temp_v1 = M2C_FIELD(arg0, unsigned int *, 4);
    if (temp_v1 == 3 || temp_v1 == 8) {
        if (Xii_func_001442DC(M2C_FIELD(arg0, int *, 0)) != minusOne) {
            Xii_func_00144308(1);
            Xii_func_0015246C(arg0);
            return -1;
        }
    }
    switch (M2C_FIELD(arg0, unsigned int *, 4)) {
        case 0:
            if (M2C_FIELD(arg0, unsigned int *, 0x24) != 0) {
                Xii_func_00202F10(M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x1F0));
                temp_s2 = M2C_FIELD(arg0, unsigned int *, 0x24);
                if (temp_s2 != 1) {
                    return 9;
                }
                Xiiif_func_00167D88((int) arg0, (int)&stack, 63.0f);
                Xiiiiiff_func_0017C340((int) ((char *)&D_006FBD80 + 0x8542C), (int) (int)&stack, (int)&stack.sp10, 0, 40.0f, 0.0f);
                if (stack.sp14 == 0) {
                    Xii_func_0015195C(arg0);
                } else {
                    Xiii_func_001694CC(arg0, 0x54);
                    Xiii_func_001694CC(arg0, 0x61);
                    Xiiui_func_001D1410((int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0), 0x40);
                    Xiiui_func_001D10D0((int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0), 0x10000000);
                    Xiiui_func_001D10D0((int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0), 0x04000000);
                    Xiiii_func_001680A0(arg0, 0x21, 0);
                    M2C_FIELD(arg0, int *, 0x48) = 0;
                    M2C_FIELD(arg0, unsigned int *, 4) = temp_s2;
                }
block_24:
                
                return -1;
            }
            
            return -1;
        case 1:
            Xii_func_00152748(arg0);
            goto block_24;
        case 2:
            Xii_func_00152B24(arg0);
            goto block_24;
        case 3:
            Xii_func_00152BB4(arg0);
            goto block_24;
        case 8:
            Xii_func_00152E90(arg0);
            goto block_24;
        case 4:
            Xii_func_00152C60(arg0);
            goto block_24;
        case 5:
            Xii_func_00152CFC(arg0);
            goto block_24;
        case 6:
            Xii_func_00152DA4(arg0);
            goto block_24;
        case 7:
            Xii_func_00152E40(arg0);
            goto block_24;
        }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152544);
#endif

// NON_MATCHING: 205/249 differ, 39 relocs differ (size 0x3E4, game 0x3DC), 51 edits
#ifdef NON_MATCHING
extern "C" int F2748_motion(int, int, int) asm("func_0013166C");
extern "C" int F2748_near(int, int, int, float, float) asm("func_00169BAC");
extern "C" int F2748_actor(int, unsigned int) asm("func_001CBE38");
extern "C" float F2748_yaw(int) asm("func_0010A650__8DogActor");
extern "C" float F2748_angle(int) asm("func_00167E38");
extern "C" void F2748_point(int, float *, float) asm("func_00167D88");
extern "C" int F2748_doneCall(int, unsigned int) asm("func_001D19A8");
inline int F2748_done(int world, int obj) { register int self PS2_REG("$16") = obj; int r = F2748_doneCall(world, *(unsigned int *)self); if (r) *(int *)(*(int *)(self + 12) + 44) = 1; return r; }
extern "C" void func_00152748(int incoming)
{
    register int arg0 PS2_REG("$16") = incoming;
    register int actor PS2_REG("$5") = M2C_FIELD(arg0, int *, 0xC);
    unsigned int frame = M2C_FIELD(arg0, unsigned int *, 0x48) + 1;
    M2C_FIELD(arg0, unsigned int *, 0x48) = frame;
    if (frame >= 11U) {
        Xiii_func_0016649C(actor, 0);
        F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
    } else {
        Xiii_func_0016649C(actor, 1);
        F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
    }
    if (!F2748_done((int)&D_007812C0, arg0)) {
        float active = (float)f19Range(M2C_FIELD(arg0, int *, 0x48), 21, 25);
        if (active != 0.0f && F2748_near(1, M2C_FIELD(arg0, int *, 0x14), M2C_FIELD(arg0, int *, 8), 80.0f, 0.7853981633974483f)) {
            register int base PS2_REG("$2") = (int)&D_006E9840;
            register int offset PS2_REG("$18") = 0x12540;
            int motion = base + offset;
            register int four PS2_REG("$20") = 4;
            if (!(bool)F2748_motion(motion, 22, 0) && !(M2C_FIELD(&D_007812C0, unsigned int *, 0x21F48) & 0x2000) && (M2C_FIELD(&D_007812C0, unsigned int *, 0x21F48) & four)) {
                register int work PS2_REG("$19") = arg0 + 0x68;
                Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 0);
                F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x40);
                F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x10000000);
                F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x04000000);
                M2C_FIELD(arg0, float *, 0x74) = F2748_yaw(F2748_actor((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0)) * 0x4D0 + motion + 0x2920);
                F2748_actor((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x14));
                int side = (double)F2748_angle(arg0) >= 1.57079632679489661923;
                M2C_FIELD(arg0, int *, 0x50) = side;
                M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x24C) = side;
                int sub = M2C_FIELD(arg0, int *, 0xC);
                if (M2C_FIELD(arg0, int *, 0x50) == 0) {
                    M2C_FIELD(sub, int *, 0x150) = 3;
                    double pi = 3.14159265358979323846;
                    F2748_motion(motion, 2, 0);
                    F2748_point(arg0, (float *)work, 60.0f);
                    work = 0x28;
                    float yaw = (float)((double)M2C_FIELD(arg0, float *, 0x74) - pi);
                    if ((double)yaw < (-3.14159265358979323846)) yaw = (float)((double)yaw + 6.28318530717958647692);
                    if ((double)yaw > pi) yaw = (float)((double)yaw - 6.28318530717958647692);
                    M2C_FIELD(arg0, float *, 0x74) = yaw;
                } else {
                    M2C_FIELD(sub, int *, 0x150) = four;
                    F2748_motion(motion, 7, 0);
                    F2748_point(arg0, (float *)work, 60.0f);
                    work = 0x29;
                }
                Xiiii_func_001680A0(arg0, work, 0);
                M2C_FIELD(arg0, int *, 0x54) = 0;
                M2C_FIELD(arg0, unsigned int *, 0x48) = 0;
                M2C_FIELD(arg0, int *, 4) = 2;
            }
        }
    } else {
        F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x04000000);
        F19_Xiiui_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x40);
        F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x10000000);
        F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
        Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 1);
        F19_Xiiui_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
        Xii_func_001517E0(arg0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152748);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152B24);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152BB4);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152C60);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152CFC);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152DA4);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152E40);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152E90);

extern "C" void func_00152F34(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152F3C);

extern "C" void NorOutBitten__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiiii_func_001680A0(arg0, 0x17, 0x100);
    M2C_FIELD(arg0, int *, 0x44) = 0;
    M2C_FIELD(arg0, int *, 0x40) = 0;
}

// NON_MATCHING: 93/178 differ, 13 relocs differ (size 0x2C8, game 0x2D8), 23 edits
#ifdef NON_MATCHING
extern int bittenOther asm("D_007A3354");
extern "C" int Bitten_Xii_func_00118FEC__9MagSystem(int) asm("func_00118FEC__9MagSystem");
extern "C" int Bitten_Xii_func_001442DC(int) asm("func_001442DC");
extern "C" int Bitten_Xii_func_00144308(int) asm("func_00144308");
extern "C" int Bitten_Xii_func_00151448(int) asm("func_00151448");
extern "C" int Bitten_Xii_func_0016947C(int) asm("func_0016947C");
extern "C" int Bitten_Xiii_func_0016649C(int, int) asm("func_0016649C");
extern "C" int Bitten_Xiii_func_001694CC(int, int) asm("func_001694CC");
extern "C" int Bitten_Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int Bitten_Xiiiii_func_001693EC(int, int, int, int) asm("func_001693EC");
extern "C" int Bitten_Xiiu_func_001D19A8(int, unsigned int) asm("func_001D19A8");
extern "C" int Bitten_Xiiui_func_001D10D0(int, unsigned int, int) asm("func_001D10D0");
extern "C" int Bitten_Xiiui_func_001D1410(int, unsigned int, int) asm("func_001D1410");
extern "C" int Bitten_Xiuiiiiui_func_001FAC60(unsigned int, int, int, int, int, unsigned int, int) asm("func_001FAC60");
extern "C" int Bitten_Xiuiuf_func_00169F94(unsigned int, int, unsigned int, float) asm("func_00169F94");
extern int D_007A3350;
extern "C" int NorOutBitten__vfunc_03(int arg0)
{
    float var_f1;
    int temp_a0_2;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    register int var_s2 PS2_REG("$18");
    unsigned int var_v1;
    register unsigned int var_s0 PS2_REG("$16");
    int temp_a0;

    var_s2 = -1;
    if (Bitten_Xii_func_001442DC(M2C_FIELD(arg0, int *, 0)) == var_s2 && M2C_FIELD(arg0, int *, 4) == 0) {
        Bitten_Xii_func_00144308(1);
        return 8;
    }
    {
        switch (M2C_FIELD(arg0, int *, 4)) {        
        case 0:
            Bitten_Xiiiii_func_001693EC(arg0, 0xA, 0x19, 0x52);
            if (Bitten_Xii_func_00151448(M2C_FIELD(arg0, int *, 0xC)) == 0) {
                Bitten_Xii_func_0016947C(arg0);
                Bitten_Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 0);
                Bitten_Xiiui_func_001D10D0((int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0), 0x400);
                Bitten_Xiiii_func_001680A0(arg0, 0x18, 0);
                M2C_FIELD(arg0, int *, 0x3C) = 0;
                M2C_FIELD(arg0, int *, 0x38) = 0;
                Bitten_Xiii_func_001694CC(arg0, 0x56);
                Bitten_Xiii_func_001694CC(arg0, 0x63);
                Bitten_Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 0);
                Bitten_Xiiui_func_001D10D0((int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0), 0x400);
                M2C_FIELD(arg0, int *, 4) = 1;
            }
block_32:
            return var_s2;
        case 1:
            temp_a0 = M2C_FIELD(arg0, int *, 0xC);
            temp_v0 = M2C_FIELD(arg0, int *, 0x3C) + 1;
            M2C_FIELD(arg0, int *, 0x3C) = temp_v0;
            if (temp_v0 < 0x30) {
                Bitten_Xiii_func_0016649C(temp_a0, 0);
                Bitten_Xiiui_func_001D10D0((int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0), 0x400);
            } else {
                Bitten_Xiii_func_0016649C(temp_a0, 1);
                Bitten_Xiiui_func_001D1410((int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0), 0x400);
            }
            temp_a0_2 = M2C_FIELD(arg0, int *, 0x3C);
            var_v1 = 0;
            if (temp_a0_2 >= 0x1D) {
                var_v1 = (temp_a0_2 > 0x2B) == 0;
            }
            if (var_v1 >= 0) {
                var_f1 = (float) var_v1;
            } else {
                var_f1 = 2.0f * (float) var_v1;
            }
            if ((var_f1 != 0.0f) && (M2C_FIELD(arg0, int *, 0x40) == 0) && (Bitten_Xii_func_00118FEC__9MagSystem((int) (int)&D_006E9840) != 9)) {
                var_s0 = 0;
                if ((*(int *)&D_007A3350) != 0) {
                    var_s0 = M2C_FIELD((*(int *)&D_007A3350), unsigned int *, 0x100);
                }
                if (Bitten_Xiuiuf_func_00169F94((unsigned int) M2C_FIELD(arg0, int *, 0), 3, var_s0, 40.0f) != 0) {
                    M2C_FIELD(arg0, int *, 0x40) = 1;
                    Bitten_Xiii_func_001694CC(arg0, 0x51);
                    Bitten_Xiuiiiiui_func_001FAC60(0xBU, (int) M2C_FIELD(arg0, int *, 0), 0, 0, 0x24, var_s0, 0);
                }
            }
            temp_v0_2 = M2C_FIELD(arg0, int *, 0x38) + 1;
            M2C_FIELD(arg0, int *, 0x38) = temp_v0_2;
            if (temp_v0_2 == 0x17) {
                Bitten_Xiuiiiiui_func_001FAC60(0xBU, (int) M2C_FIELD(arg0, int *, 0), 0, 0, 0x25, M2C_FIELD(bittenOther, unsigned int *, 0x100), 0);
                Bitten_Xii_func_00144308(0);
            }
            temp_v0_3 = Bitten_Xiiu_func_001D19A8((int) (int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0));
            if (temp_v0_3 != 0) {
                M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x2C) = 1;
                if (temp_v0_3 != 0) {
                    var_s2 = 8;
                    Bitten_Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 1);
                    Bitten_Xiiui_func_001D1410((int)&D_007812C0, (unsigned int) M2C_FIELD(arg0, int *, 0), 0x400);
                }
            }
            goto block_32;
        default:
            return var_s2;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutBitten__vfunc_03);
#endif

extern "C" void NorOutBitten__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void NorOutWalk__vfunc_02(int arg0)
{
    int temp_v0;

    M2C_FIELD(arg0, short *, 0x3A) = Xi_func_001536CC();
    temp_v0 = Xiii_func_0010423C(0x3E8, 0x7D0);
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0x44) = temp_v0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB68);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB70);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB78);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB80);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB88);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB90);

extern "C" int Walk_func_00166B74(int, float *) asm("func_00166B74");
extern "C" int Walk_func_0010423C(int, int) asm("func_0010423C");
extern "C" float Walk_func_001044B8(float, float) asm("func_001044B8");
extern "C" float Walk_func_001D7DE4(int, int) asm("func_001D7DE4");
extern "C" int Walk_func_0016976C(int, int) asm("func_0016976C");
extern "C" int Walk_func_001670DC(int, float *, float) asm("func_001670DC");
extern "C" int Walk_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int Walk_func_00202F10(int) asm("func_00202F10");
extern "C" int Walk_func_001D19A8(int, unsigned int) asm("func_001D19A8");
extern "C" int Walk_func_001682B0(int) asm("func_001682B0");
extern "C" int NorOutWalk__vfunc_03(int arg0)
{
  struct 
  {
    int flags[3];
    int pad;
    float target[4];
    float origin[4];
  } stack;
  float *var_a1;
  float *var_v1;
  float temp_f0;
  float var_f0;
  int temp_s4;
  int temp_v0;
  int temp_v0_2;
  int temp_v0_4;
  int var_a0;
  register int var_s2 PS2_REG("$18");
  unsigned int temp_a0;
  unsigned int temp_v0_3;
  temp_a0 = *((unsigned int *) (((char *) arg0) + 4));
  *((int *) (((char *) arg0) + 0x44)) = (int) ((*((int *) (((char *) arg0) + 0x44))) - 1);
  switch (temp_a0)
  {
    case 2:

    case 5:

    case 6:

    case 7:

    case 8:
      break;
      walk_success:
    Walk_func_001670DC(arg0, &stack.target[0], 0.0f);

      *((unsigned int *) (((char *) arg0) + 4)) = 1U;
      goto walk_after;

    case 0:
      stack.flags[2] = 0;
      var_s2 = 0;
      stack.flags[1] = 0;
      stack.flags[0] = 0;
      Walk_func_00166B74(arg0, &stack.origin[0]);
      temp_s4 = Walk_func_0010423C(0, 0x59);
      do
    {
      var_a1 = &stack.target[0];
      var_a0 = 3;
      var_v1 = &stack.origin[0];
      do
      {
        temp_f0 = *var_v1;
        var_v1++;
        var_a0 -= 1;
        *var_a1 = temp_f0;
        var_a1++;
      }
      while (var_a0 != (-1));
      if (stack.flags[0] == 0)
      {
        if (temp_s4 >= 0x1E)
        {
          goto block_11;
        }
        stack.target[0] += Walk_func_001044B8(-120.0f, -80.0f);
        stack.target[2] += Walk_func_001044B8(80.0f, 120.0f);
        stack.flags[0] = 1;
      }
      else
      {
        block_11:
        if ((stack.flags[1] == 0) && (temp_s4 < 0x3C))
        {
          stack.target[0] += Walk_func_001044B8(-20.0f, 20.0f);
          stack.target[2] += Walk_func_001044B8(120.0f, 160.0f);
          stack.flags[1] = 1;
        }
        else
        {
          stack.target[0] += Walk_func_001044B8(-20.0f, 20.0f);
          stack.target[2] += Walk_func_001044B8(120.0f, 160.0f);
          stack.flags[2] = 1;
        }

      }
      stack.target[1] += Walk_func_001D7DE4((int) (&D_007812C0), (int) (&stack.origin[0]));
      if (Walk_func_0016976C((int) (&stack.origin[0]), (int) (&stack.target[0])) == 0)
      {
        var_s2 += 1;
      }
      else
      {
        goto walk_success;
      }
    }
    while (var_s2 < 3);
      walk_after:
    if (var_s2 == 3)
    {
      if (((unsigned int) (*((unsigned int *) (((char *) arg0) + 0x40)))) >= 2U)
      {
        Walk_func_0010423C(0, 0x63);
      }
      Walk_func_001680A0(arg0, 0xC, 0);
      *((unsigned int *) (((char *) arg0) + 4)) = 4U;
    }

      break;

    case 1:
      if ((*((int *) (((char *) arg0) + 0x24))) != 0)
    {
      Walk_func_00202F10(*((int *) (((char *) (*((int *) (((char *) arg0) + 0xC)))) + 0x1F0)));
      *((unsigned int *) (((char *) arg0) + 0x40)) = 0U;
      *((unsigned int *) (((char *) arg0) + 4)) = 0U;
    }
      break;

    case 3:
      temp_v0 = (*((int *) (((char *) arg0) + 0x48))) - 1;
      *((int *) (((char *) arg0) + 0x48)) = temp_v0;
      if (temp_v0 < 0)
    {
      *((unsigned int *) (((char *) arg0) + 4)) = 0U;
      *((unsigned int *) (((char *) arg0) + 0x40)) = (unsigned int) ((*((unsigned int *) (((char *) arg0) + 0x40))) + 1);
    }
      break;

    case 4:
      temp_v0_2 = Walk_func_001D19A8((int) (&D_007812C0), *((unsigned int *) (((char *) arg0) + 0)));
      if (temp_v0_2 != 0)
    {
      var_s2 = temp_v0_2 != 0;
      *((int *) (((char *) (*((int *) (((char *) arg0) + 0xC)))) + 0x2C)) = 1;
      if (var_s2)
      {
        temp_v0_3 = (*((unsigned int *) (((char *) arg0) + 0x40))) + 1;
        *((unsigned int *) (((char *) arg0) + 0x40)) = temp_v0_3;
        if ((temp_v0_3 < 3U) && (Walk_func_0010423C(0, 0x63) < 0x32))
        {
          *((unsigned int *) (((char *) arg0) + 4)) = 0U;
        }
        else
        {
          Walk_func_001682B0(arg0);
          temp_v0_4 = Walk_func_0010423C(0x14, 0x32);
          *((int *) (((char *) arg0) + 0x48)) = temp_v0_4;
          *((unsigned int *) (((char *) arg0) + 4)) = 3U;
        }
      }
    }
      break;

  }

  return -1;
}

extern "C" int func_001536CC()
{
    return 0;
}


extern "C" int func_001536D4()
{
    return 0;
}


extern "C" void NorOutWalk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void NorOutDead__vfunc_02(int arg0)
{
    int temp_v1;
    int temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, int *, 8);
    M2C_FIELD(temp_v1, int *, 0x120) = (int) (M2C_FIELD(temp_v1, int *, 0x120) | 0x400);
    temp_v1_2 = M2C_FIELD(arg0, int *, 8);
    M2C_FIELD(temp_v1_2, int *, 0x120) = (int) (M2C_FIELD(temp_v1_2, int *, 0x120) | 0x2000);
    Xiiii_func_001680A0(arg0, 1, 0x100);
}

extern "C" int NorOutDead__vfunc_03()
{
    return -1;
}


extern "C" void NorOutDead__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void NorOutBrownEv__vfunc_02(int arg0)
{
    Xiiii_func_001680A0(arg0, 1, 0);
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD((*(int *)&D_007B205C), int *, 0x64C) = 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutBrownEv__vfunc_03);

extern "C" void NorOutCounter__vfunc_02(int arg0)
{
    M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x150) = 0;
    Xiii_func_001694CC(arg0, 0x56);
    Xiii_func_001694CC(arg0, 0x63);
    Xiiii_func_001680A0(arg0, 0x2A, 0);
    M2C_FIELD(arg0, int *, 0x38) = 0;
    M2C_FIELD(arg0, int *, 0x40) = 0;
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiii_func_00166DA4(arg0, 0x64);
}

// NON_MATCHING: 148/169 differ, 21 relocs differ (size 0x2A4, game 0x2B4), 44 edits
#ifdef NON_MATCHING
struct CounterWorld { char pad[0x22090]; int pc; };
extern CounterWorld counterWorld asm("D_007812C0");
extern int D_007A3354;
extern "C" int Counter_func_0016649C(int, int) asm("func_0016649C");
extern "C" int Counter_func_001D10D0(int, int, int) asm("func_001D10D0");
extern "C" int Counter_func_00118FEC__9MagSystem(int) asm("func_00118FEC__9MagSystem");
extern "C" int Counter_func_00169F94(int, int, int, float) asm("func_00169F94");
extern "C" int Counter_func_001694CC(int, int) asm("func_001694CC");
extern "C" int Counter_func_001FAC60(int, int, int, int, int, int, int) asm("func_001FAC60");
extern "C" int Counter_func_00119090__9MagSystem(int) asm("func_00119090__9MagSystem");
extern "C" int Counter_func_001D19A8(int, int) asm("func_001D19A8");
extern "C" int Counter_func_001D1410(int, int, int) asm("func_001D1410");
inline float counterRange(int n) { unsigned int r = 0; if (n >= 17) r = n <= 38; return r; }
extern "C" int NorOutCounter__vfunc_03(int arg0) {
    float var_f1;
    int temp_a0;
    int temp_v0_2;
    int temp_v1;
    int var_a2;
    register int var_s2 PS2_REG("$18");
    int var_v0;
    int var_v1;
    unsigned int var_s1;
    int temp_v0;
    int temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, int *, 4);
    var_s2 = -1;
    switch (temp_v1) {                              /* irregular */
    case 0:
        M2C_FIELD(arg0, int *, 0x38) = (int) (M2C_FIELD(arg0, int *, 0x38) + 1);
        Counter_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 0);
        Counter_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
        var_f1 = counterRange(M2C_FIELD(arg0, int *, 0x38));
        if (var_f1 != 0.0f) {
            if ((M2C_FIELD(arg0, int *, 0x3C) == 0) && (Counter_func_00118FEC__9MagSystem((int) &D_006E9840) != 9)) {
                var_a2 = 0;
                if (counterWorld.pc != 0) {
                    var_a2 = M2C_FIELD(counterWorld.pc, int *, 0x100);
                }
                if (Counter_func_00169F94(M2C_FIELD(arg0, unsigned int *, 0), 4, (unsigned int) var_a2, 65.0f) != 0) {
                    temp_v0 = M2C_FIELD(arg0, int *, 0xC);
                    int *hits = (int *)(temp_v0 + 0x23C);
                    (*hits)++;
                    Counter_func_001694CC(arg0, 0x50);
                    M2C_FIELD(arg0, int *, 0x3C) = 1;
                    Counter_func_001FAC60(0xBU, (int ) M2C_FIELD(arg0, unsigned int *, 0), 0, 0, 0x24, (unsigned int) var_a2, 0);
                }
            }
            temp_v1_2 = M2C_FIELD(arg0, int *, 0xC);
            if (((M2C_FIELD(temp_v1_2, int *, 0x218) == 0) || (M2C_FIELD(temp_v1_2, int *, 0x230) != 0)) && (M2C_FIELD(arg0, int *, 0x40) == 0) && (Counter_func_00119090__9MagSystem((int) &D_006E9840) != 0xA) && (Counter_func_00119090__9MagSystem((int) &D_006E9840) != 0xD)) {
                var_s1 = 0;
                if (D_007A3354 != 0) {
                    var_s1 = M2C_FIELD(D_007A3354, unsigned int *, 0x100);
                }
                if (Counter_func_00169F94(M2C_FIELD(arg0, unsigned int *, 0), 4, var_s1, 65.0f) != 0) {
                    Counter_func_001694CC(arg0, 0x50);
                    M2C_FIELD(arg0, int *, 0x40) = 1;
                    Counter_func_001FAC60(0xBU, (int ) M2C_FIELD(arg0, unsigned int *, 0), 0, 0, 0x24, var_s1, 0);
                }
            }
        }
        var_v0 = -1;
        if (M2C_FIELD(arg0, int *, 0x38) == 0x26) {
            M2C_FIELD(arg0, int *, 4) = 2;
block_29:
            var_v0 = var_s2;
        }
        return var_v0;
    case 2:
        M2C_FIELD(arg0, int *, 0x38) = (int) (M2C_FIELD(arg0, int *, 0x38) + 1);
        Counter_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 0);
        Counter_func_001D10D0((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
        temp_v0_2 = Counter_func_001D19A8((int) &D_007812C0, M2C_FIELD(arg0, unsigned int *, 0));
        if (temp_v0_2 != 0) {
            M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x2C) = 1;
            if (temp_v0_2 != 0) {
                var_s2 = 8;
                Counter_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 1);
                Counter_func_001D1410((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0), 0x400);
            }
        }
        return var_s2;
    default:
        return -1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutCounter__vfunc_03);
#endif

extern "C" void NorOutCounter__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void NorOutCoax__vfunc_02(int arg0)
{
    Xiiif_func_00167230(arg0, 0, 0.39269906282424927f);
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 0);
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutCoax__vfunc_03);

extern "C" void NorOutTest__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiiii_func_001680A0(arg0, 0x21, 0);
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutTest__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFBC8);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFBD8);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFBE8);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFBF8);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC08);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC18);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC28);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC38);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC48);
