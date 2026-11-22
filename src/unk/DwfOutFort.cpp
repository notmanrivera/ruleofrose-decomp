#include "include_asm.h"
#include "emy/emy.h"

struct EmyMainVtbl3 {
    unsigned char m_pad[0x200];
    virtual void v1();
    virtual void v2();
    virtual int getType();
};

struct DwfOutFort : public EmyOut {
    int m_unk38;                        // +0x38: dwarf variant (0..2)
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    int m_unk44;                        // +0x44
    int m_unk48;                        // +0x48
};

struct DwfOutIrritate : public EmyOut {
    int m_unk38;                        // +0x38: dwarf variant (0..2)
    int m_unk3C;                        // +0x3C
};

extern float D_002F1148[];
extern int D_006FE6A0;
extern int D_007812C0;
extern void *D_007A3350;
extern unsigned short D_007A34CC;

extern "C" float X_func_0010A650__8DogActor(void *) asm("func_0010A650__8DogActor");
extern "C" void X_func_00166AD0(EmyOut *) asm("func_00166AD0");
extern "C" void X_func_00166AD0_v(...) asm("func_00166AD0");
extern "C" void X_func_00167230(EmyOut *, int, float) asm("func_00167230");
extern "C" float X_func_00167E38(EmyOut *) asm("func_00167E38");
extern "C" void X_func_001687BC(EmyOut *, int, int) asm("func_001687BC");
extern "C" void X_func_0016913C(EmyOut *) asm("func_0016913C");
extern "C" void X_func_001694CC(EmyOut *, int) asm("func_001694CC");
extern "C" int X_func_00169BAC(int, int, int, float, float) asm("func_00169BAC");
extern "C" int X_func_001CBE38(void *, int) asm("func_001CBE38");
extern "C" float X_sinf(float) asm("sinf");
extern "C" float X_cosf(float) asm("cosf");

#ifdef NON_MATCHING
extern "C" void DwfOutFort__vfunc_02(DwfOutFort *self)
{
    int type = ((EmyMainVtbl3 *)self->m_owner)->getType();
    if (type == 1) {
        self->m_unk38 = 1;
    } else if (type == 0) {
        self->m_unk38 = 0;
    } else if (type == 2) {
        self->m_unk38 = 2;
    }
    self->m_unk48 = 0;
    self->m_unk10 = 0;
    self->m_unk14 = D_007A3350 ? *(int *)((char *)D_007A3350 + 0x100) : 0;
    self->m_unk40 = !((double)X_func_00167E38(self) < 1.5707963267948966);
    X_func_00167230(self, 0, 0.39269906282424927f);
    self->m_unk04 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfOutFort", DwfOutFort__vfunc_02);
INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F10C0);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutFort", DwfOutFort__vfunc_03);

extern "C" void DwfOutFort__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" int func_00161AAC(DwfOutFort *self)
{
    if (X_func_00169BAC(1, self->m_unk14, self->m_unk08, D_002F1148[self->m_unk38] + 20.0f, 0.39269906282424927f) != 0) {
        X_func_001694CC(self, 0xB);
        X_func_001687BC(self, 0x48, 0);
        self->m_unk3C = 0;
        X_func_0016913C(self);
        *(int *)((char *)self->m_owner->m_unk1F8 + 4) = 0;
        return 1;
    }
    return 0;
}

#ifdef NON_MATCHING
extern "C" void DwfOutIrritate__vfunc_02(DwfOutIrritate *self)
{
    int type = ((EmyMainVtbl3 *)self->m_owner)->getType();
    if (type == 1) {
        self->m_unk38 = 1;
    } else if (type == 0) {
        self->m_unk38 = 0;
    } else if (type == 2) {
        self->m_unk38 = 2;
    }
    X_func_00167230(self, 0, 0.3141592741012573f);
    self->m_unk04 = 0;
    self->m_unk3C = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfOutFort", DwfOutIrritate__vfunc_02);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutFort", DwfOutIrritate__vfunc_03);

extern "C" void DwfOutIrritate__vfunc_04()
{
    X_func_00166AD0_v();
}

extern "C" float func_00161DA8(void)
{
    float base;
    switch (D_007A34CC) {
    case 0xA00:
        base = 50.0f;
        break;
    case 0xA36:
    case 0xA37:
    case 0xA38:
    case 0xA3D:
        base = 110.0f;
        break;
    case 0xA39:
    case 0xA3A:
    case 0xA3C:
        base = 130.0f;
        break;
    case 0xA3B:
        base = 170.0f;
        break;
    case 0xB59:
        base = 170.0f;
        break;
    case 0xA3E:
    case 0xA3F:
    default:
        base = 50.0f;
        break;
    }
    return base + 10.0f;
}

#ifdef NON_MATCHING
extern "C" void func_00161E74(EmyOut *self, float *pos, float f1, float f2)
{
    int actorIdx = X_func_001CBE38(&D_007812C0, self->m_unk00);
    float ang = X_func_0010A650__8DogActor((char *)&D_006FE6A0 + actorIdx * 0x4D0);
    float s = X_sinf(ang);
    float c = X_cosf(ang);
    pos[0] += f1 * s + f2 * c;
    pos[2] += f1 * c - f2 * s;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfOutFort", func_00161E74);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutFort", func_00161F28);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutFort", DwfOutDead__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F1130);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F1138);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F1148);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F1158);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F1160);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F1170);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F1180);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F1190);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F11A8);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F11B8);

INCLUDE_ASM("asm/nonmatchings/unk/DwfOutFort", DwfOutDead__vfunc_03);

extern "C" void DwfOutDead__vfunc_04(EmyOut *self)
{
    ((EmyObjStatView *)self->m_unk08)->m_flags &= ~0x400;
    X_func_00166AD0(self);
}

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F11E8);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfOutFort", D_002F11F8);
