#include "include_asm.h"
#include "emy/emy.h"

struct BdlPos {
    unsigned long long xy;
    int z;
};

struct BdlOutAtk : public EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
};

struct BdlOutWin : public EmyOut {
    float m_unk38;                      // +0x38
};

struct BdlDeadEffParam {
    int m_kind;                         // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    unsigned long long m_posXY;         // +0x10
    int m_posZ;                         // +0x18
    float m_unk1C;                      // +0x1C
    float m_unk20;                      // +0x20
    float m_unk24;                      // +0x24
    float m_unk28;                      // +0x28
    int m_unk2C;                        // +0x2C
    unsigned char m_pad30[0x50];        // +0x30..+0x7F
};

extern int D_006FBD80;
extern int D_007812C0;
extern int D_007B2580;

extern "C" void X_func_00165570(EmyMain *) asm("func_00165570");
extern "C" void X_func_00166AD0_v(...) asm("func_00166AD0");
extern "C" void X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" void X_func_00167230(EmyOut *, int, float) asm("func_00167230");
extern "C" int X_func_001679B4(EmyOut *, int, int, float, float) asm("func_001679B4");
extern "C" void X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" void X_func_001687BC(EmyOut *, int, int) asm("func_001687BC");
extern "C" int X_func_001694CC(EmyOut *, int) asm("func_001694CC");
extern "C" void X_func_00176CC8(void *, BdlDeadEffParam *) asm("func_00176CC8");
extern "C" int X_func_00180EEC(int, int, int) asm("func_00180EEC");
extern "C" void X_func_001D10D0(void *, int, int) asm("func_001D10D0");
extern "C" void X_func_001D1410(void *, int, int) asm("func_001D1410");
extern "C" void X_func_001DA228(void *, int, void *) asm("func_001DA228");
extern "C" void X_func_00202F10(void *) asm("func_00202F10");

extern "C" void BdlOutAtk__vfunc_02(BdlOutAtk *self)
{
    unsigned short val;
    X_func_00166DA4(self, 0x64);
    self->m_unk38 = 0;
    X_func_001DA228((void *)self->m_unk08, 0x68, &val);
    int v = val;
    self->m_unk3C = v;
    if (v == 1) {
        self->m_unk04 = 1;
    } else {
        X_func_00167230(self, 0, 0.7853981405496597f);
        self->m_unk04 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/BdlOutAtk", BdlOutAtk__vfunc_03);

extern "C" void BdlOutAtk__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" void BdlOutWin__vfunc_02(BdlOutWin *self)
{
    X_func_001680A0(self, 0x15, 0x100);
    int snd = X_func_001694CC(self, 0xD);
    self->m_unk2C = snd;
    X_func_00180EEC((int)&D_007B2580, snd, 1);
    self->m_unk04 = 1;
}

extern "C" int BdlOutWin__vfunc_03(BdlOutWin *self)
{
    if ((self->m_unk04 == 0) && (X_func_001679B4(self, self->m_unk14, 1, self->m_unk38, 0.7853981405496597f) != 0)) {
        X_func_00202F10(self->m_owner->m_unk1F0);
        self->m_unk04 = 1;
    }
    return -1;
}

extern "C" void BdlOutWin__vfunc_04()
{
    X_func_00166AD0_v();
}

#ifdef NON_MATCHING
extern "C" void BdlOutDead__vfunc_02(EmyOut *self)
{
    BdlPos pos;
    X_func_001DA228((void *)self->m_unk08, 5, &pos);
    BdlDeadEffParam param;
    param.m_posZ = pos.z;
    param.m_kind = 3;
    param.m_posXY = pos.xy;
    param.m_unk20 = -1.0f;
    param.m_unk28 = 100.0f;
    param.m_unk2C = 0x5A;
    param.m_unk1C = 0.0f;
    param.m_unk24 = 0.0f;
    param.m_unk08 = 0;
    register char *sc PS2_REG("$4") = (char *)&D_006FBD80;
    X_func_00176CC8(sc + 0x837E0, &param);
    self->m_owner->m_unk0C = 0;
    X_func_001D1410(&D_007812C0, self->m_unk00, 0x40);
    X_func_001D10D0(&D_007812C0, self->m_unk00, 0x10000000);
    X_func_001D10D0(&D_007812C0, self->m_unk00, 0x400);
    X_func_00165570(self->m_owner);
    ((EmyObjStatView *)self->m_unk08)->m_flags |= 0x400;
    ((EmyObjStatView *)self->m_unk08)->m_flags |= 0x2000;
    X_func_001687BC(self, 0x24, 0x100);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/BdlOutAtk", BdlOutDead__vfunc_02);
#endif

extern "C" int BdlOutDead__vfunc_03()
{
    return -1;
}

extern "C" void BdlOutDead__vfunc_04()
{
    X_func_00166AD0_v();
}

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6A8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6B0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6B8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6C0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6C8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6D0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6D8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6E0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6E8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6F0);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF6F8);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF700);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF708);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF710);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF718);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF720);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF730);

INCLUDE_RODATA("asm/nonmatchings/unk/BdlOutAtk", D_002EF740);
