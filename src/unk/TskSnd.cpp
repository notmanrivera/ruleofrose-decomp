#include "include_asm.h"
#include "task/cmnitask.h"

class TskSnd : public CmnITask {
public:
    unsigned char m_pad04[0x20];        // +0x04..+0x23
    int (TskSnd::*m_func)();            // +0x24 (8 bytes)
    unsigned char m_pad2C[0x08];        // +0x2C..+0x33
    int m_mode;                         // +0x34
    int m_maxCnt;                       // +0x38
    int m_cnt;                          // +0x3C
    unsigned char m_pad40[0x44];        // +0x40..+0x83
    int m_val84;                        // +0x84
    int m_val88;                        // +0x88

    virtual int get_task_type() { return 0; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskSnd() {}
};

extern "C" int X_func_001E6734(...) asm("func_001E6734");
extern int D_007812C0;

extern "C" void func_001F8FB8(void) {
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA48);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F8FC0);

extern "C" int TskSnd__vfunc_04(TskSnd *self)
{
    return (self->*(self->m_func))();
}

extern "C" void TskSnd__vfunc_05(TskSnd *self)
{
    int temp_a2;
    int off = 0x18E00;

    if (self->m_mode == 2) {
        temp_a2 = self->m_val84;
        X_func_001E6734((int)&D_007812C0 + off, 0xD, temp_a2, temp_a2, 0, -1);
    }
}

extern "C" float func_001F9294(TskSnd *self)
{
    float var_f0;
    int temp_v0;

    temp_v0 = self->m_maxCnt;
    var_f0 = 0.0f;
    if (temp_v0 > 0) {
        var_f0 = (float) self->m_cnt / (float) temp_v0;
    }
    return var_f0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F92C8);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F93D8);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F9484);

extern "C" int func_001F9550(TskSnd *self, int arg1, int arg2)
{
    int off = 0x18E00;

    X_func_001E6734((int)&D_007812C0 + off, 0xD, arg1, arg2, 0, -1);
    return self->m_cnt > self->m_maxCnt;
}

extern "C" int func_001F95A8(TskSnd *self, int arg1, int arg2)
{
    int off = 0x18E00;

    X_func_001E6734((int)&D_007812C0 + off, 0xE, arg1, arg2, 0, -1);
    return self->m_cnt > self->m_maxCnt;
}

extern "C" int func_001F9600(TskSnd *self, int arg1, int arg2)
{
    int off = 0x18E00;

    X_func_001E6734((int)&D_007812C0 + off, 0xF, arg1, arg2, 0, -1);
    return self->m_cnt > self->m_maxCnt;
}

extern "C" int func_001F9658(TskSnd *self, int *arg1, int *arg2)
{
    *arg1 = self->m_val84;
    *arg2 = self->m_val88;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F9670);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F96C0);

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F974C);

extern "C" int func_001F97C0()
{
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskSnd", func_001F97C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA70);
