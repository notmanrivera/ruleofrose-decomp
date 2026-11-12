#include "include_asm.h"
extern "C" int Xii___builtin_delete(int) asm("__builtin_delete");
extern "C" int Xii___builtin_vec_delete(int) asm("__builtin_vec_delete");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern int D_002D9950;
extern int D_007B4790;
extern int D_007B4D20;
extern int D_007B4D30;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_002155A8(...) asm("func_002155A8");
extern "C" int X_memset(...) asm("memset");
extern int D_002D90F8;
extern int D_007B4640;
extern int D_007B4650;
extern int D_007B4680;
extern int D_007B4700;
extern int D_007B477C;
extern int D_007B4780;
extern int D_007B47A0;
extern int D_007B47B0;
extern int D_007B47C0;
extern int D_007B47D0;
extern int D_007B4810;
extern int D_007B4840;
extern int D_007B4DB0;
extern int D_007B4DD0;

extern "C" void func_0020ED9C(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020EDA4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020EEA8);

extern "C" void func_0020EFA4(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020EFAC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F0C8);

extern "C" int func_0020F140(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0xDC24) & 0x100) {
        return M2C_FIELD(arg0, int *, 0xDC58);
    }
    return M2C_FIELD((*(int *)&D_007B4640), int *, 0x38);
}

extern "C" int func_0020F174(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0xDC24) & 0x100) {
        return M2C_FIELD(arg0, int *, 0xDC34);
    }
    return M2C_FIELD((*(int *)&D_007B4640), int *, 0x14);
}

extern "C" void func_0020F1A8(int arg0)
{
    X_memset((*(int *)(int *)((char *)(arg0) + 0xDC1C)), 0, 0x800);
    X_memset((*(int *)(int *)((char *)(arg0) + 0xDC20)) + 4, 0, 0x7FC);
}


INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F1FC);

extern "C" void func_0020F37C(int arg0)
{
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;

    temp_s0 = M2C_FIELD(arg0, int *, 0x10);
    if (temp_s0 != 0) {
        temp_a0 = M2C_FIELD(temp_s0, int *, 0x1C0);
        if (temp_a0 != 0) {
            Xii___builtin_vec_delete(temp_a0);
        }
        Xii___builtin_delete(temp_s0);
    }
    temp_s0_2 = M2C_FIELD(arg0, int *, 0x14);
    if (temp_s0_2 != 0) {
        temp_a0_2 = M2C_FIELD(temp_s0_2, int *, 0x1C0);
        if (temp_a0_2 != 0) {
            Xii___builtin_vec_delete(temp_a0_2);
        }
        Xii___builtin_delete(temp_s0_2);
    }
    temp_s0_3 = M2C_FIELD(arg0, int *, 0x18);
    if (temp_s0_3 != 0) {
        temp_a0_3 = M2C_FIELD(temp_s0_3, int *, 0x1C0);
        if (temp_a0_3 != 0) {
            Xii___builtin_vec_delete(temp_a0_3);
        }
        Xii___builtin_delete(temp_s0_3);
    }
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F428);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F4FC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F788);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F98C);

extern "C" void func_0020FF34(void) {
}

extern "C" void func_0020FF3C(int arg0, int arg1, int arg2)
{
    if (arg1 == 0) {
        ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0];
        return;
    }
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] + ((int *)&D_007B4700)[arg1];
}

extern "C" void func_0020FF8C(int arg0, int arg1, int arg2)
{
    if (arg1 == 0) {
        ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0];
        return;
    }
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] + ((int *)&D_007B4700)[arg1];
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020FFDC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210024);

extern "C" void func_0021006C(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] & ((int *)&D_007B4700)[arg1];
}

extern "C" void func_002100A0(unsigned int arg0, unsigned int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg1] = ((int *)&D_007B4700)[arg0] & arg2;
}

extern "C" void func_002100C8(int arg0, int arg1)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = ((int *)&D_007B4700)[arg0];
    temp_v1 = ((int *)&D_007B4700)[arg1];
    (*(int *)&D_007B47A0) = temp_v0 / temp_v1;
    (*(int *)&D_007B4790) = temp_v0 % temp_v1;
}

extern "C" void func_00210110(int arg0, int arg1)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = ((int *)&D_007B4700)[arg0];
    temp_v1 = ((int *)&D_007B4700)[arg1];
    (*(int *)&D_007B47A0) = temp_v0 / temp_v1;
    (*(int *)&D_007B4790) = temp_v0 % temp_v1;
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210158);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002101B4);

extern "C" void func_00210210(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ~(((int *)&D_007B4700)[arg0] | ((int *)&D_007B4700)[arg1]);
}

extern "C" void func_00210244(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] | ((int *)&D_007B4700)[arg1];
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210278);

extern "C" void func_002102A0(int arg0, int arg1, int arg2, int arg3)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg1] << arg3;
}

extern "C" void func_002102C8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg1] << ((int *)&D_007B4700)[arg0];
}

extern "C" void func_002102FC(int arg0, int arg1, int arg2, int arg3)
{
    ((int *)&D_007B4700)[arg2] = (int) ((int *)&D_007B4700)[arg1] >> arg3;
}

extern "C" void func_00210324(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = (int) ((int *)&D_007B4700)[arg1] >> ((int *)&D_007B4700)[arg0];
}

extern "C" void func_00210358(int arg0, int arg1, int arg2, int arg3)
{
    ((int *)&D_007B4700)[arg2] = (int) ((unsigned int) ((int *)&D_007B4700)[arg1] >> arg3);
}

extern "C" void func_00210380(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = (int) ((unsigned int) ((int *)&D_007B4700)[arg1] >> ((int *)&D_007B4700)[arg0]);
}

extern "C" void func_002103B4(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] - ((int *)&D_007B4700)[arg1];
}

extern "C" void func_002103E8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] - ((int *)&D_007B4700)[arg1];
}

extern "C" void func_0021041C(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] ^ ((int *)&D_007B4700)[arg1];
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210450);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210478);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002104EC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210534);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210578);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002105C0);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002105FC);

extern "C" void func_002106A0(unsigned int arg0, int arg1, unsigned int arg2)
{
    if (((int *)&D_007B4700)[arg0] > 0) {
        (*(int *)&D_007B47C0) = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;
    }
}

extern "C" void func_002106F4(unsigned int arg0, int arg1, unsigned int arg2)
{
    if (((int *)&D_007B4700)[arg0] <= 0) {
        (*(int *)&D_007B47C0) = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210748);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002107AC);

extern "C" void func_0021082C(int arg0, int arg1, int arg2, int arg3)
{
    D_007B47C0 = ((arg3 & 0x03FFFFFF) * 4) | (D_007B4780 & 0xF8000000) | 0x80000000;
}


INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210864);

extern "C" void func_002108B8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8168;
    (*(int *)&D_007B47C0) = ((int *)&D_007B4700)[arg0] | 0x80000000;
}

extern "C" void func_00210908(int arg0)
{
    (*(int *)&D_007B47C0) = ((int *)&D_007B4700)[arg0] | 0x80000000;
}

extern "C" void func_0021092C(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + ((int) (arg2 << 0x10) >> 0xE));
}

extern "C" void func_00210960(unsigned int arg0, unsigned int arg1, short arg2)
{
    int temp_v1;

    temp_v1 = ((int *)&D_007B4700)[arg0];
    ((int *)&D_007B4700)[arg1] = (*(int *)(temp_v1 + arg2) << 8) | (temp_v1 & 0xFF);
}

extern "C" void func_002109A0(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + arg2);
}

extern "C" void func_002109D4(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + ((int) (arg2 << 0x10) >> 0xE));
}

extern "C" void func_00210A08(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + arg2);
}

extern "C" void func_00210A3C(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + arg2);
}

extern "C" void func_00210A70(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + arg2);
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210AA4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210AD8);

extern "C" void func_00210B0C(unsigned int arg0, unsigned int arg1, short arg2)
{
    int temp_a0;

    temp_a0 = ((int *)&D_007B4700)[arg0] + arg2;
    (*(int *)(temp_a0)) = ((unsigned int) ((int *)&D_007B4700)[arg1] >> 8) | ((*(int *)(temp_a0)) & 0xFF000000);
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210B54);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210BA4);

extern "C" void func_00210BD8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = (*(int *)&D_007B4790);
}

extern "C" void func_00210BF8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = (*(int *)&D_007B47A0);
}

extern "C" void func_00210C18(int arg0, int arg1, int arg2)
{
    (*(int *)&D_007B4790) = ((int *)&D_007B4700)[arg2];
}

extern "C" void func_00210C34(int arg0, int arg1, int arg2)
{
    (*(int *)&D_007B47A0) = ((int *)&D_007B4700)[arg2];
}

extern "C" void func_00210C50(void) {
}

extern "C" void func_00210C58(void) {
}

extern "C" void func_00210C60(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210C68);

extern "C" void func_00210CA0(void) {
}

extern "C" void func_00210CA8(void) {
}

extern "C" void func_00210CB0(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210CB8);

extern "C" void func_00210CEC(void) {
}

extern "C" void func_00210CF4(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210CFC);

extern "C" void func_00210D34(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210D3C);

extern "C" void func_00210EBC(void) {
}

extern "C" void func_00210EC4(void) {
}

extern "C" void func_00210ECC(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg0] + ((float *)&D_007B4680)[arg1];
}

extern "C" void func_00210F00(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg0] - ((float *)&D_007B4680)[arg1];
}

extern "C" void func_00210F34(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg0] * ((float *)&D_007B4680)[arg1];
}

extern "C" void func_00210F68(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg0] / ((float *)&D_007B4680)[arg1];
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210FA4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210FE4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211024);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211064);

extern "C" void func_002110E4(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg1];
}

extern "C" void func_00211108(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = -((float *)&D_007B4680)[arg1];
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211130);

extern "C" void func_00211158(void) {
}

extern "C" void func_00211160(void) {
}

extern "C" void func_00211168()
{
    D_007B4840 = 0;
}


extern "C" void func_00211174(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0021117C);

extern "C" void func_002111BC(void) {
}

extern "C" void func_002111C4(void) {
}

extern "C" void func_002111CC(void) {
}

extern "C" void func_002111D4(void) {
}

extern "C" void func_002111DC(void) {
}

extern "C" void func_002111E4()
{
    D_007B4840 = 0;
}


extern "C" void func_002111F0(void) {
}

extern "C" void func_002111F8(void) {
}

extern "C" void func_00211200(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211208);

extern "C" void func_00211248(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211250);

extern "C" void func_00211290(void) {
}

extern "C" void func_00211298(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002112A0);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002112D8);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211318);

extern "C" void func_002113A4(int arg0, int arg1)
{
    (*(unsigned int *)&D_007B47B0) = (arg1 + (*(int *)&D_007B47D0)) - M2C_FIELD((((*(int *)((int)&D_007B4DD0)) * 4) + arg0), int *, 0xDC08);
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002113DC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211830);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211BE4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211E84);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002120AC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212330);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212598);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002127F4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212920);

INCLUDE_RODATA("asm/nonmatchings/unk/0020ED9C", D_00301710);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002129B8);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212A5C);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212D08);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212E64);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212FBC);

extern "C" void func_00213448(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213450);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213ADC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213B28);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213B7C);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213BFC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213C6C);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213D00);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213D90);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213E78);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213F48);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002142C0);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214310);

extern "C" void func_002144C4(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002144CC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214664);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002147E0);

extern "C" int func_002149A8()
{
    int temp_v0;
    int temp_v0_2;
    int temp_s1;

    temp_s1 = (*(int *)&D_007B4D20) + ((*(int *)&D_002D9950) << 0xB);
    ((int *)&D_007B4D30)[(*(int *)&D_002D9950)] = 1;
    Xiiii_memset(temp_s1, 0, 0x800);
    temp_v0 = (*(int *)&D_002D9950) + 1;
    (*(int *)&D_002D9950) = temp_v0;
    if (temp_v0 >= 0x20) {
        (*(int *)&D_002D9950) = 0;
    }
    if (((int *)&D_007B4D30)[(*(int *)&D_002D9950)] != 0) {
        do {
            temp_v0_2 = (*(int *)&D_002D9950) + 1;
            (*(int *)&D_002D9950) = temp_v0_2;
            if (temp_v0_2 >= 0x20) {
                (*(int *)&D_002D9950) = 0;
            }
        } while (((int *)&D_007B4D30)[(*(int *)&D_002D9950)] != 0);
    }
    return (int) temp_s1;
}

extern "C" void func_00214A94(int arg0)
{
    unsigned int temp_a0;

    temp_a0 = (unsigned int) (arg0 - (*(int *)&D_007B4D20)) >> 0xB;
    (*(int *)&D_002D9950) = (int) temp_a0;
    ((int *)&D_007B4D30)[temp_a0] = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214AC4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214BCC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214C24);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214E98);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002150B0);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002152B8);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00215430);

extern "C" void func_002155A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002155A8);

extern "C" void func_002155D4()
{
    X_func_002155A8(1, 0xFFFF);
}

