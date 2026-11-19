#include "include_asm.h"
extern "C" int Xii_func_0014B8C0(int) asm("func_0014B8C0");
extern "C" int Xii_func_0014B8D4(int) asm("func_0014B8D4");
extern "C" int Xii_func_0014B8E8(int) asm("func_0014B8E8");
extern "C" int Xii_func_0014B910(int) asm("func_0014B910");
extern "C" int Xiii_func_0016968C(int, int) asm("func_0016968C");
extern "C" int Xii_func_0014BE48(int) asm("func_0014BE48");
extern "C" int Xiii_func_0014BE48(int, int) asm("func_0014BE48");
extern "C" int Xii___builtin_delete(int) asm("__builtin_delete");
extern "C" int Xiii_EmyMain__vfunc_01(int, int) asm("EmyMain__vfunc_01");
extern int _vt$7BdlMain;
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xii_EmyMain__vfunc_01(int, int) asm("EmyMain__vfunc_01");
extern int _vt$7HfmMain;
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xii_EmyMain__vfunc_01(int, int) asm("EmyMain__vfunc_01");
extern "C" int Xiiii_ffi_func_001F603C(int, int, int, int, float, float, int) asm("func_001F603C");
struct m2c_v200_10_i { char pad[512]; virtual void v1(); virtual int call(); };
struct m2c_v34_20_i { char pad[52]; virtual void v1(); virtual void v2(); virtual void v3(); virtual int call(); };
struct m2c_v34_18_i { char pad[52]; virtual void v1(); virtual void v2(); virtual int call(); };
extern "C" int Xii_func_00202F10(int) asm("func_00202F10");
extern "C" int Xiii_func_001694CC(int, int) asm("func_001694CC");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
extern "C" int Xiiii_func_00180EEC(int, int, int) asm("func_00180EEC");
extern "C" int Xiiiiff_func_001679B4(int, int, int, float, float) asm("func_001679B4");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_0014B8C0(...) asm("func_0014B8C0");
extern "C" int X_func_0014B8D4(...) asm("func_0014B8D4");
extern "C" int X_func_0014B8E8(...) asm("func_0014B8E8");
extern "C" int X_func_0014B910(...) asm("func_0014B910");
extern "C" int X_func_0014BE48(...) asm("func_0014BE48");
extern "C" int X_func_0014BED0(...) asm("func_0014BED0");
extern "C" int X_func_00165734(...) asm("func_00165734");
extern "C" int X_func_00165794(...) asm("func_00165794");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(...) asm("func_00166DA4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_001679B4(...) asm("func_001679B4");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_0016968C(...) asm("func_0016968C");
extern "C" int X_func_00180EEC(...) asm("func_00180EEC");
extern "C" int X_func_00202F10(...) asm("func_00202F10");
extern int D_006E9840;
extern int D_007B2580;

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014B3BC);

extern "C" void BdlMain__vfunc_01(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x200) = (int)&_vt$7BdlMain;
    Xii_EmyMain__vfunc_01(arg0, 0);
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

extern "C" void BdlMain__vfunc_04(int self)
{
    if (M2C_FIELD(self, int *, 0x28) && M2C_FIELD(self, int *, 0x2C) && M2C_FIELD(self, int *, 0x24) == -1) {
        if (M2C_FIELD(self, int *, 0x208)) {
            if (!Xii_func_0014B8C0(self)) {
                if (M2C_FIELD(self, unsigned char *, 0x205)) {
                    M2C_FIELD(self, int *, 0x24) = 0;
                    M2C_FIELD(self, unsigned char *, 0x205) = 0;
                }
                return;
            }
            M2C_FIELD(self, unsigned char *, 0x205) = 1;
        }
        if (M2C_FIELD(self, int *, 0x20C) && Xii_func_0014B8D4(self)) {
            M2C_FIELD(self, int *, 0x24) = 1;
        } else if (M2C_FIELD(self, int *, 0x210) && (M2C_FIELD(self, int *, 0x30) & 1)) {
            M2C_FIELD(self, int *, 0x24) = 2;
        } else {
            int result = Xii_func_0014B910(self);
            if (M2C_FIELD(self, unsigned char *, 0x204)) {
                if (!result) {
                    M2C_FIELD(self, unsigned char *, 0x204) = 0;
                    if (M2C_FIELD(self, int *, 0x218)) {
                        M2C_FIELD(self, int *, 0x24) = 4;
                        return;
                    }
                }
            } else if (result) {
                M2C_FIELD(self, unsigned char *, 0x204) = 1;
                if (M2C_FIELD(self, int *, 0x214)) {
                    M2C_FIELD(self, int *, 0x24) = 3;
                    return;
                }
                goto fallback;
            }
fallback:
            if (M2C_FIELD(self, int *, 0x21C) && Xii_func_0014B8E8(self)) {
                M2C_FIELD(self, int *, 0x24) = 5;
            } else return;
        }

    }
}

extern "C" void BdlMain__vfunc_05(int self)
{
    M2C_FIELD(self, int *, 0x40) = 0;
    int flags = M2C_FIELD(self, int *, 0x30);
    if (flags & 2) {
        int next = 6;
        int object = M2C_FIELD(self, int *, 0x1C);
        M2C_FIELD(self, int *, 0x3C) = next;
        M2C_FIELD(object, int *, 0xA4) = next;
        M2C_FIELD(self, int *, 0x40) = 1;
    } else if (M2C_FIELD(self, int *, 0x24) != -1) {
        int next = Xiii_func_0016968C(M2C_FIELD(self, int *, 0x1C), M2C_FIELD(self, int *, 0x24));
        M2C_FIELD(self, signed char *, 0x205) = 0;
        M2C_FIELD(self, signed char *, 0x204) = 0;
        if (next != 0) {
            M2C_FIELD(self, int *, 0x3C) = next;
            M2C_FIELD(self, int *, 0x40) = 1;
        } else {
            M2C_FIELD(M2C_FIELD(self, int *, 0x1C), int *, 0xA4) = M2C_FIELD(self, int *, 0x3C);
        }
    } else if (flags & 1) {
        M2C_FIELD(M2C_FIELD(self, int *, 0x1C), int *, 0xA4) = M2C_FIELD(self, int *, 0x3C);
        M2C_FIELD(self, int *, 0x40) = 1;
    }
    M2C_FIELD(self, int *, 0x30) = 0;
}

extern "C" void BdlMain__vfunc_06(int arg0)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    if (M2C_FIELD(arg0, int *, 0x40) != 0) {
        ((m2c_v34_20_i *)(M2C_FIELD(arg0, int *, 0x44)))->call();
        ((m2c_v200_10_i *)(arg0))->call();
    }
    M2C_FIELD(arg0, int *, 0x24) = ((m2c_v34_18_i *)(M2C_FIELD(arg0, int *, 0x44)))->call();
}

// NON_MATCHING: 11/49 differ, 11 edits
#ifdef NON_MATCHING
struct m2c_v34_10_i { char pad[52]; virtual void v1(); virtual int call(); };
static inline bool BdlStateBelowLimit(int state) { return state < 7; }
static inline void BdlWriteFlag(int slot, int value) { *(int *)((char *)slot + 0x200) = value; }
static inline void BdlWriteStateFlag(int self, int index, int value) { int *slot = index + (int *)self; BdlWriteFlag((int)slot, value); }
extern "C" int BdlMain__vfunc_02(int arg0)
{
    int temp_v1;
    int temp_v1_3;
    int var_a5;
    int temp_a3;
    int var_v0;
    unsigned char temp_a2;
    int temp_a0;
    int temp_a0_2;
    int temp_v0;
    int temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, int *, 0x3C);
    if (BdlStateBelowLimit(temp_v1) && (temp_v1 > 0)) {
        temp_a0 = M2C_FIELD(((temp_v1 * 4) + arg0), int *, 0x48);
        M2C_FIELD(arg0, int *, 0x44) = temp_a0;
        ((m2c_v34_10_i *)(temp_a0))->call();
    }
    temp_v1_2 = M2C_FIELD(arg0, int *, 0xE8);
    var_a5 = 0;
    temp_a2 = M2C_FIELD(temp_v1_2, unsigned char *, 1);
    temp_a3 = M2C_FIELD(temp_v1_2, int *, 0xC) + (M2C_FIELD(arg0, int *, 0x3C) * temp_a2);
    for (int i = 0; i < temp_a2; ++i) {
        if (((signed char *)temp_a3)[i] != 0) {
            BdlWriteStateFlag(arg0 + 8, i, 1);
        } else {
            BdlWriteStateFlag(arg0 + 8, i, 0);
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlMain__vfunc_02);
#endif

extern "C" int func_0014B8C0()
{
    return X_func_00165734();
}


extern "C" int func_0014B8D4()
{
    return X_func_00165794();
}


extern "C" int func_0014B8E8()
{
    return X_func_00118FEC__9MagSystem((int)&D_006E9840) == 4;
}


INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014B910);

extern "C" void BdlOutWalk__vfunc_02(int arg0)
{
    Xiii_func_0014BE48(arg0, 0x1);
    M2C_FIELD(arg0, int *, 4) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutWalk__vfunc_03);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014BAF8);

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014BDBC);

extern "C" void func_0014BE48(int arg0, int arg1)
{
    float v;

    v = M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), float *, 0x1C4);
    if (v != 0.0f) {
        v = v * 0.016666666f;
    } else {
        v = 0.016666666f;
    }
    Xiiii_ffi_func_001F603C(M2C_FIELD(arg0, int *, 0), arg1, -1, 0x100, v, 32769.0f, 1);
}

extern "C" void BdlOutWalk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void func_0014BED0(int arg0, int arg1)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x4)) != arg1) {
        (*(int *)(int *)((char *)(arg0) + 0x4)) = arg1;
        (*(int *)(int *)((char *)(arg0) + 0x38)) = 0;
    }
}


extern "C" void BdlOutStared__vfunc_02(int arg0)
{
    int temp_v0;

    M2C_FIELD(arg0, int *, 4) = 0;
    ((m2c_v34_18_i *)(arg0))->call();
}

INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", BdlOutStared__vfunc_03);

extern "C" void BdlOutStared__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_ASM("asm/nonmatchings/unk/BdlMain", func_0014C0A4);

extern "C" void BdlOutSearch__vfunc_02(int arg0)
{
    Xiii_func_00166DA4(arg0, 0x64);
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 10.0f);
}

extern "C" int BdlOutSearch__vfunc_03(int self)
{
    int next;
    int result = Xiiiiff_func_001679B4(self, M2C_FIELD(self, int *, 0x14), 0, 300.0f, 3.141592562198639f);
    switch (result) {
    case 0: next = -1; break;
    case 1: next = 6; Xii_func_00202F10(M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 0x1F0)); break;
    case 2: next = 4; Xii_func_00202F10(M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 0x1F0)); break;
    default: next = 7; Xii_func_00202F10(M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 0x1F0)); break;
    }
    return next;
}

extern "C" void BdlOutSearch__vfunc_04()
{
    X_func_00166AD0();
}


INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF618);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF628);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF640);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF650);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF658);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF660);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF668);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF670);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlMain", D_002EF680);




