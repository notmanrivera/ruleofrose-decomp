#include "include_asm.h"
#include "task/cmnitask.h"
#include "sdk/math.h"
struct EventEntry64 {
    unsigned char unk00[0x40];
};
struct EventTestTask {
    void *m_vtable;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
};
extern int D_002DB2A4;
extern const unsigned char D_00301AF8[];
extern unsigned char D_007B4E08[];
extern unsigned char D_007B4E28[];
extern EventEntry64 D_007B4EC8[0x28];
extern int D_007B5968[0x28];
extern "C" int Xiiii_strncpy(int, int, int) asm("strncpy");
extern "C" void Xff_func_00218424(float, float) asm("func_00218424");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern int _vt$13EventTestTask;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00217CB4(...) asm("func_00217CB4");
extern "C" int X_func_00217CF0(...) asm("func_00217CF0");
extern "C" int X_func_00217D2C(...) asm("func_00217D2C");
extern "C" int X_func_00217D68(...) asm("func_00217D68");
extern "C" int X_func_00218424(...) asm("func_00218424");
extern int D_003079A9;
extern int D_006E9840;

extern "C" void func_00216828(EventTestTask *self)
{
    int i;

    self->m_vtable = &_vt$13EventTestTask;
    D_002DB2A4 = 0;
    D_007B4E08[0] = D_00301AF8[0];
    D_007B4E28[0] = D_00301AF8[0];
    for (i = 0; i < 0x28; i++) {
        D_007B4EC8[i].unk00[0] = D_00301AF8[0];
        D_007B5968[i] = 0;
    }
    self->m_unk28 = 0;
    self->m_unk24 = 0;
    self->m_unk20 = 0;
    self->m_unk1C = 0;
    self->m_unk04 = 0;
    self->m_unk08 = 0;
    self->m_unk0C = 0;
    self->m_unk10 = 0;
    self->m_unk14 = 0;
    self->m_unk18 = 0;
}

extern "C" void EventTestTask__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$13EventTestTask;
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

extern "C" void EventTestTask__vfunc_03(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", EventTestTask__vfunc_04);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301B00);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00216AD0);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301BF0);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301BF8);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301C00);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301C08);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301C10);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00217260);

extern "C" void func_00217BEC(EventTestTask *self)
{
    float angle = 0.25f * (float)self->m_unk04;

    if (angle < -3.14159265358979323846) {
        angle += 6.28318530717958647692;
    }
    if (angle > 3.14159265358979323846) {
        angle -= 6.28318530717958647692;
    }
    sinf(angle);
}

extern "C" void func_00217CAC(void) {
}

extern "C" int func_00217CB4(int arg0)
{
    char *p = (char *)&D_006E9840;
    int var_a0 = 0;
    unsigned int v;

    p += 0xD0;
    if ((M2C_FIELD(arg0, int *, 0x1c) >= 9) || (v = M2C_FIELD(p, unsigned short *, 0x7A), (v >> 4) & 1)) {
        var_a0 = 1;
    }
    return var_a0;
}

extern "C" int func_00217CF0(int arg0)
{
    char *p = (char *)&D_006E9840;
    int var_a0 = 0;
    unsigned int v;

    p += 0xD0;
    if ((M2C_FIELD(arg0, int *, 0x20) >= 9) || (v = M2C_FIELD(p, unsigned short *, 0x7A), (v >> 6) & 1)) {
        var_a0 = 1;
    }
    return var_a0;
}

extern "C" int func_00217D2C(int arg0)
{
    char *p = (char *)&D_006E9840;
    int var_a0 = 0;
    unsigned int v;

    p += 0xD0;
    if ((M2C_FIELD(arg0, int *, 0x24) >= 9) || (v = M2C_FIELD(p, unsigned short *, 0x7A), (v >> 7) & 1)) {
        var_a0 = 1;
    }
    return var_a0;
}

extern "C" int func_00217D68(int arg0)
{
    char *p = (char *)&D_006E9840;
    int var_a0 = 0;
    unsigned int v;

    p += 0xD0;
    if ((M2C_FIELD(arg0, int *, 0x28) >= 9) || (v = M2C_FIELD(p, unsigned short *, 0x7A), (v >> 5) & 1)) {
        var_a0 = 1;
    }
    return var_a0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00217DA4);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00217F10);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_002180E4);

extern "C" int func_002182C4(int arg0)
{
    struct { char pad0[256]; } stack;
    int temp_s0;
    int var_a0;
    int var_a3;
    int temp_v1;

    var_a0 = arg0;
    temp_s0 = var_a0;
    var_a3 = (int)&stack;
    if ((*(signed char *)(temp_s0)) != 0) {
        do {
            temp_v1 = (unsigned char) (*(signed char *)(var_a0));
            var_a0 += 1;
            if ((unsigned int) (temp_v1 - 0x61) < 0x1AU) {
                (*(unsigned char *)(var_a3)) = temp_v1 - 0x20;
            } else {
                (*(unsigned char *)(var_a3)) = temp_v1;
            }
            var_a3 += 1;
        } while ((*(signed char *)(var_a0)) != 0);
    }
    (*(unsigned char *)(var_a3)) = 0;
    Xiiii_strncpy(temp_s0, (int)&stack, 0x100);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00218338);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_0021838C);

extern "C" void func_002183F8(int arg0, int arg1, int arg2)
{
    int var_a2;
    int var_a0;
    int var_a1;
    unsigned char temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    if (var_a2 > 0) {
        do {
            temp_v0 = (*(unsigned char *)(var_a1));
            var_a1 += 1;
            var_a2 -= 1;
            (*(unsigned char *)(var_a0)) = temp_v0;
            var_a0 += 1;
        } while (var_a2 != 0);
    }
}


extern "C" float func_00218424(float fparg0, float fparg1)
{
    return fparg0 - fparg1 * (float)(int)(fparg0 / fparg1);
}

extern "C" void func_00218450(float f)
{
    return Xff_func_00218424(f, 3.14159265f);
}

extern "C" void func_00218470(int arg0, ...)
{
    __builtin_next_arg(arg0);
}

extern "C" void func_002184B8(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_002184C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301DE8);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E08);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E10);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E18);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E20);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E28);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E30);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E38);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E40);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E48);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E50);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E58);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E60);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E68);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301E70);
