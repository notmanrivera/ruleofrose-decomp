#include "include_asm.h"
#include "emy/emy.h"

struct DwfOutAtkFar : public EmyOut {
    int m_unk38;                        // +0x38
};

struct DwfOutWin : public EmyOut {
    int m_unk38;                        // +0x38
    float m_unk3C;                      // +0x3C
};

struct DwfAtkFarParam {
    int m_target;                       // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    float m_angle;                      // +0x0C
    float m_dist;                       // +0x10
    unsigned char m_pad14[0x1C];        // +0x14..+0x2F
};

extern void *D_007B205C;
extern int D_007B2580;

extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" float X_func_001044B8(float, float) asm("func_001044B8");
extern "C" void X_func_00160D94(DwfOutWin *) asm("func_00160D94");
extern "C" void X_func_00160E44(DwfOutWin *) asm("func_00160E44");
extern "C" void X_func_0016649C(EmyMain *, int) asm("func_0016649C");
extern "C" void X_func_00166AD0_v(...) asm("func_00166AD0");
extern "C" void X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" void X_func_00166EB4(EmyOut *, int) asm("func_00166EB4");
extern "C" void X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" void X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" void X_func_001687BC(EmyOut *, int, int) asm("func_001687BC");
extern "C" int X_func_001694CC(EmyOut *, int) asm("func_001694CC");
extern "C" void X_func_00180EEC(void *, int, int) asm("func_00180EEC");
extern "C" void X_func_001DA228(void *, int, int *) asm("func_001DA228");
extern "C" void X_func_001F9D90(int, DwfAtkFarParam *) asm("func_001F9D90");
extern "C" void X_func_00202F10(void *) asm("func_00202F10");

#ifdef NON_MATCHING
extern "C" void DwfOutAtkFar__vfunc_02(DwfOutAtkFar *self)
{
    int val;
    self->m_unk38 = X_func_0010423C(0x5A, 0x96);
    X_func_00166EB4(self, 0x64);
    X_func_001DA228((void *)self->m_unk08, 0x67, &val);
    int f = *(int *)((char *)self->m_unk08 + 0x3EC);
    int b1 = f & 0x10;
    int b0 = f & 8;
    if (b0 && b1) {
        self->m_unk04 = 3;
    } else if (val != 0) {
        self->m_unk04 = 0;
        X_func_00166F50(self, self->m_unk14, 150.0f);
    } else {
        self->m_unk04 = 3;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutAtkFar__vfunc_02);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutAtkFar__vfunc_03);

extern "C" void DwfOutAtkFar__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" void func_00160998(DwfOutAtkFar *self, int *outState)
{
    int val;
    X_func_001DA228((void *)self->m_unk08, 0x67, &val);
    if (val != 0) {
        DwfAtkFarParam arg;
        self->m_unk04 = 1;
        arg.m_angle = 1.5707963109016418f;
        arg.m_unk08 = 0x15;
        arg.m_dist = 20.0f;
        arg.m_target = self->m_unk14;
        X_func_0016649C(self->m_owner, 0);
        X_func_001F9D90(self->m_unk00, &arg);
        X_func_001694CC(self, 0xB);
    } else {
        *outState = 0x16;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutStared__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutStared__vfunc_03);

extern "C" void DwfOutStared__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" void DwfOutWin__vfunc_02(DwfOutWin *self)
{
    if (*(int *)((char *)D_007B205C + 0x5CC) != 0) {
        X_func_001687BC(self, 0x44, 0);
        X_func_00166EB4(self, 0x64);
        self->m_unk38 = 0;
        return;
    }
    if ((unsigned int)self->m_unk10 >= 2U) {
        X_func_00166DA4(self, 0x64);
    }
    float dist = X_func_001044B8(100.0f, 200.0f);
    self->m_unk3C = dist;
    X_func_00166F50(self, self->m_unk14, dist);
    self->m_unk04 = 0;
}

extern "C" int DwfOutWin__vfunc_03(DwfOutWin *self)
{
    if (*(int *)((char *)D_007B205C + 0x5CC) != 0) {
        X_func_00160E44(self);
    } else {
        X_func_00160D94(self);
    }
    return -1;
}

#ifdef NON_MATCHING
extern "C" void func_00160D94(DwfOutWin *self)
{
    if (self->m_unk04 == 0 && self->m_unk24 != 0) {
        X_func_00202F10(self->m_owner->m_unk1F0);
        int f = *(int *)((char *)self->m_unk08 + 0x3EC);
        int b1 = f & 0x10;
        int b0 = f & 8;
        if (b0 && b1) {
            X_func_001687BC(self, 0xA, 0x100);
        } else {
            X_func_001687BC(self, 0x15, 0x100);
            int snd = X_func_001694CC(self, 0xD);
            self->m_unk2C = snd;
            X_func_00180EEC(&D_007B2580, snd, 1);
        }
        self->m_unk04 = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00160D94);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", func_00160E44);

extern "C" void DwfOutWin__vfunc_04()
{
    X_func_00166AD0_v();
}

#ifdef NON_MATCHING
extern "C" void DwfOutParts__vfunc_02(EmyOut *self)
{
    int f = *(int *)((char *)self->m_unk08 + 0x3EC);
    int b1 = f & 0x10;
    int b0 = f & 8;
    int motion;
    if (b0 && b1) {
        motion = 0xA;
    } else {
        int f2 = *(int *)((char *)self->m_unk08 + 0x3EC);
        int b3 = f2 & 0x10;
        int b2 = f2 & 8;
        if (b2 || b3) {
            motion = 1;
        } else {
            motion = 0x14;
        }
    }
    self->m_unk04 = 0;
    X_func_001687BC(self, motion, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfOutAtkFar", DwfOutParts__vfunc_02);
#endif

extern "C" int DwfOutParts__vfunc_03()
{
    return -1;
}

extern "C" void DwfOutParts__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" void DwfOutTest__vfunc_02(EmyOut *self)
{
    self->m_unk04 = 0;
    X_func_001680A0(self, 6, 0);
}

extern "C" int DwfOutTest__vfunc_03()
{
    return -1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1048);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1058);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1068);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1070);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1080);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F1090);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F10A0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutAtkFar", D_002F10B0);
