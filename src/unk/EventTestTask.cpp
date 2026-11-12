#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00216828);

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

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301AF8);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00216AD0);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301BF0);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301BF8);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301C00);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301C08);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301C10);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00217260);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00217BEC);

extern "C" void func_00217CAC(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00217CB4);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00217CF0);

INCLUDE_ASM("asm/nonmatchings/unk/EventTestTask", func_00217D2C);

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

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301DC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301DD0);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301DD8);

INCLUDE_RODATA("asm/nonmatchings/unk/EventTestTask", D_00301DE0);

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
