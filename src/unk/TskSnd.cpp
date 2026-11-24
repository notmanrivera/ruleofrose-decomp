#include "include_asm.h"
#include "task/cmnitask.h"
#include "game/gamman.h"
#include "game/gamsnd.h"
extern GamTaskMan D_007A3D80;
struct Buf40_97C8 {
    char m_data[0x40];
};
extern "C" void func_001F4088(CmnITask *, int, void *, int);
struct SndMan;
extern SndMan D_007B2580;
extern "C" int func_001800D0(SndMan *, int);
extern "C" void func_001801C8(SndMan *, int);
extern "C" int func_0017FD58(SndMan *, char *, int, int, int);
extern "C" void func_00180078(SndMan *, int, int);
static inline GamSndMan *getSnd(GamMan *g) { return (GamSndMan *)g->m_snd; }

class TskSnd : public CmnITask {
public:
    char m_name04[0x20];                // +0x04..+0x23
    int (TskSnd::*m_func)();            // +0x24 (8 bytes)
    int (TskSnd::*m_func2C)(int, int);  // +0x2C (8 bytes)
    int m_mode;                         // +0x34
    int m_maxCnt;                       // +0x38
    int m_cnt;                          // +0x3C
    int m_unk40;                        // +0x40
    unsigned char m_pad44[0x3C];        // +0x44..+0x7F
    int m_unk80;                        // +0x80
    int m_val84;                        // +0x84
    int m_val88;                        // +0x88
    int m_unk8C;                        // +0x8C
    int m_unk90;                        // +0x90
    int m_unk94;                        // +0x94
    float m_unk98;                      // +0x98
    int m_unk9C;                        // +0x9C
    int m_unkA0;                        // +0xA0
    int m_unkA4;                        // +0xA4
    int m_unkA8;                        // +0xA8
    int m_unkAC;                        // +0xAC
    int m_unkB0;                        // +0xB0

    virtual int get_task_type() { return 0; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskSnd() {}
};

extern "C" int X_func_001E6734(...) asm("func_001E6734");

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

extern "C" int func_001F92C8(TskSnd *self)
{
    switch (self->m_unk40) {
    case 0x64: {
        float t = func_001F9294(self);
        float inv = 1.0f - t;
        self->m_cnt++;
        int v1 = (int)((float)self->m_val84 * t + (float)self->m_unkA0 * inv);
        int v2 = (int)((float)self->m_val88 * t + (float)self->m_unkA4 * inv);
        return (self->*(self->m_func2C))(v1, v2);
    }
    case 0x65:
        return 1;
    default:
        return 0;
    }
}

extern "C" int func_001F93D8(TskSnd *self, int arg1, int arg2)
{
    if (arg1 == 0 && arg2 == 0) {
        func_001E5E58(getSnd(&D_007812C0), self->m_unk80, 1, 0);
    }
    if (func_001E63C0(getSnd(&D_007812C0), self->m_unk80, self->m_unk8C, arg1, arg2) != 0 && self->m_cnt <= self->m_maxCnt) {
        return 0;
    }
    return 1;
}

extern "C" int func_001F9484(TskSnd *self, int arg1, int arg2)
{
    if (arg1 == 0 && arg2 == 0) {
        if (self->m_unkA8 != 0) {
            func_001E5660(getSnd(&D_007812C0), self->m_unk80, 0x17, 0);
        } else {
            func_001E5660(getSnd(&D_007812C0), self->m_unk80, 1, 0);
        }
        return 1;
    }
    if (func_001E5C40(getSnd(&D_007812C0), self->m_unk80, self->m_unk8C, arg1, arg2) != 0 && self->m_cnt <= self->m_maxCnt) {
        return 0;
    }
    return 1;
}

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

extern "C" int func_001F9670(TskSnd *self)
{
    func_001E50C8(getSnd(&D_007812C0), self->m_unk80, self->m_val84, self->m_val88, self->m_unk98, self->m_unk90, 0, 0);
    return 1;
}

extern "C" int func_001F96C0(TskSnd *self)
{
    if (func_001800D0(&D_007B2580, self->m_unk8C) != -1) {
        func_001801C8(&D_007B2580, self->m_unk8C);
        return 0;
    }
    func_0017FD58(&D_007B2580, self->m_name04, self->m_unkAC, self->m_unkB0, self->m_unkA8);
    if (self->m_unkA8 != 0) {
        func_00180078(&D_007B2580, self->m_unkB0, 1);
    }
    return 1;
}

extern "C" int func_001F974C(TskSnd *self)
{
    GamSndMessage msg;

    if (self->m_cnt++ >= self->m_maxCnt) {
        msg.m_unk04 = 0;
        msg.m_unk08 = 0;
        msg.m_unk14 = 10;
        func_001E5E58(getSnd(&D_007812C0), self->m_unk80, 0x13, &msg);
        return 1;
    }
    return 0;
}

extern "C" int func_001F97C0()
{
    return 1;
}

extern "C" void func_001F97C8(void *arg0, int arg1)
{
    int prio = D_007A3D80.m_base.m_prio + arg1;
    CmnITask *task = (CmnITask *)new Buf40_97C8;
    func_001F4088(task, 1, arg0, 0);
    func_001E71FC(&D_007A3D80, 1, prio, 1, 0, task, 0, 0, 1);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskSnd", D_002FEA70);
