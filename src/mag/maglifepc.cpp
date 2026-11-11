#include "ror.h"
#include "include_asm.h"
#include "mag/maglifeman.h"
#include "dog/dogactor.h"
class MagPC : public MagLife {
public:
    virtual void vfunc09(int theMode, int theA);
};
#define I(p, off) (*(int *)((char *)(p) + (off)))
#include "bed/bedpad.h"
#include "dog/dogcamera.h"
struct MagPCModeB { virtual void vfunc01(MagPC *thePC); virtual void vfunc02(MagPC *thePC); };
extern "C" void func_0011A738_c(MagPC *self, void *theTable) asm("func_0011A738");
extern "C" void func_0012CB50(MagPC *self);
extern "C" int func_0011E0AC(MagPC *self);
extern "C" void func_00120668(MagPC *self);
extern int D_002E9EF8;
extern "C" void func_0012B4A0(void *theObj, int theA);
extern "C" void func_0012B5F8(void *theObj, int theA);
extern "C" void func_0012B65C(void *theObj, int theA);
extern "C" void func_00102918(int theA, int theB, int theC);
extern "C" void func_001029C4(int theA, int theB, int theC, int theD);
extern const char D_002E9F40[];
struct MagPCModeA { virtual void vfunc01(MagPC *thePC); };
float vecYaw(const float *v);
#define F(p, off) (*(float *)((char *)(p) + (off)))
struct YawPoint { float x, y, z, w; };
extern "C" void func_00119B34_c(MagPC *self) asm("func_00119B34");
extern "C" unsigned int func_0011CE50(MagPC *self);
extern const char D_002E9F28[];
struct ItemVec { float x, y, z, w; ItemVec() { x = y = z = 0.0f; w = 1.0f; } };
struct ItemData { ItemVec m_pos; int m_obj_id; int m_pad[3]; };
extern "C" int func_0011C64C(MagPC *self, ItemData *theData, int theNum, float theRange);
struct Pair64 { long a; long b; };
struct PadBits { unsigned short b0 : 11; unsigned short b11 : 1; };
static inline unsigned short padBit(void *p) { return ((PadBits *)((char *)p + 0x78))->b11; }
class MagPCMode {
public:
    virtual void vfunc01();
    virtual void vfunc02();
    virtual int vfunc03(MagPC *thePC, void *theA);
};
extern int D_00297140;
extern int D_006E9840;
extern "C" int func_0011C464(MagPC *self, int theA);
extern "C" int func_0011C4C0(MagPC *self);
extern "C" int func_0011BE30(MagPC *self);
extern "C" int func_0011AB88(MagPC *self);
extern "C" int func_0011AC24(MagPC *self, BedPad *thePad);
extern "C" int func_0011ACF4(MagPC *self, void *thePad);
extern "C" int func_00131550(void *theScene);
extern "C" void func_0011C1E8(MagPC *self, int theMode, int theA, int theForce);
extern "C" void func_0011A130(MagPC *self);
extern "C" void func_0011C2AC(MagPC *self, int theA);

extern "C" void func_0011AB40(MagPC *self)
{
    func_0011A130(self);
    *(Pair64 *)self = *(Pair64 *)((char *)self + 0x30);
    *(u_long128 *)((char *)self + 0x30) = 0;
    func_0011C2AC(self, 0);
}

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_0011AB88(MagPC *self)
{
    if (I(self, 0x1B4) >= 0) {
        return I(self, 0x1B4);
    }
    if (I(self, 0x54) == 1) {
        return 3;
    }
    if (I(self, 0x54) == 3) {
        return 4;
    }
    float life = (float)func_0011C464(self, I(self, 0x54));
    if (life / (float)func_0011C4C0(self) <= 0.29999999f) {
        return 2;
    }
    return I(self, 0xD0) < 0x12D;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", func_0011AB88);
#endif


extern "C" int func_0011AC24(MagPC *self, BedPad *thePad)
{
    int r = 0;
    float s = thePad->getStick((float *)((char *)self + 0x108), (float *)((char *)self + 0x10C));
    *(float *)((char *)self + 0x114) = thePad->getChange();
    if (*(float *)((char *)self + 0x1F8) <= s) {
        *(float *)((char *)self + 0x104) = s;
        if (s > 0.96999997f && I(self, 0xE4) != 2) {
            r = 2;
            I(self, 0x84) = 0;
            if (I(self, 0xEC) != 2) {
                D_00297140 = D_006E9840;
            }
        } else {
            I(self, 0x84) = 0;
            r = 1;
        }
    } else {
        *(float *)((char *)self + 0x104) = 0.0f;
        I(self, 0x84) = 0;
    }
    return r;
}


extern "C" int func_0011ACF4(MagPC *self, void *thePad)
{
    if (I(self, 0x54) == 2) {
        return 0;
    }
    if (I(self, 0xE4) >= 3) {
        return 0;
    }
    int k = I(self, 0);
    if (k < 7 || (k >= 0xA && k <= 0xB)) {
        if (k == 0xA) {
            return -1;
        }
        int r = 0;
        if (padBit(thePad)) {
            r = I(self, 0x21C) + 1;
        }
        return r;
    }
    return 0;
}

extern "C" void func_0011AD6C(MagPC *self, void *thePad)
{
    I(self, 0xF0) = I(self, 0xE4);
    I(self, 0xE4) = func_0011AB88(self);
    I(self, 0xEC) = I(self, 0xE0);
    I(self, 0xE0) = func_0011AC24(self, (BedPad *)thePad);
    I(self, 0xE8) = I(self, 0xDC);
    I(self, 0xDC) = func_0011ACF4(self, thePad);
    if (I(self, 0xDC) < 0) {
        I(self, 0xDC) = I(self, 0xE8);
    }
}


extern "C" void live__9MagLifePC(MagPC *self)
{
    if (I(self, 0x58) != 0) {
        char *scene = (char *)I(self, 0x20);
        if (I(self, 0x54) == 3) {
            F(scene, 0x22B0) = 0.1f;
        } else if (F(scene, 0x22B0) > 1.0f) {
            F(scene, 0x22B0) = 1.0f;
        } else if (F(scene, 0x22B0) < 1.0f) {
            F(scene, 0x22B0) += 0.05f;
        }
        I(self, 4)++;
        func_0011A738_c(self, &D_002E9EF8);
        if (I(self, 0) == 0xB) {
            func_0012CB50(self);
        } else {
            MagPCModeB *mode = (MagPCModeB *)I(self, 0x134);
            if (mode != 0) {
                mode->vfunc02(self);
            } else {
                func_0011C1E8(self, I(self, 0), 0, 0);
            }
        }
        I(self, 0x130)++;
        if (func_0011E0AC(self) == 0) {
            func_00120668(self);
        }
        I(self, 0xF8) = 0;
    }
}

extern "C" int func_0011AF04(MagPC *self)
{
    return I(self, 0xDC) != 0;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_0011AF10(MagPC *self)
{
    int r = -1;
    if (I(self, 0) == 0x17) {
        r = I(self, 4);
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", func_0011AF10);
#endif


extern "C" void func_0011AF30(MagPC *self, int theType, int theFlag)
{
    switch (theType) {
    case 15:
        if (theFlag & 1) {
            func_00102918(0x26, 0x27, 0x28);
        }
        if (theFlag & 2) {
            func_0012B65C((char *)I(self, 0x20) + 0x2BD20, 0);
        }
        break;
    case 16:
        if (theFlag & 1) {
            func_001029C4(0x25, 0x38, 0x23, 0x24);
        }
        if (theFlag & 2) {
            func_0012B4A0((char *)I(self, 0x20) + 0x2BD20, 0);
        }
        break;
    case 17:
        if (theFlag & 1) {
            func_00102918(0x29, 0x2A, 0x37);
        }
        if (theFlag & 2) {
            func_0012B5F8((char *)I(self, 0x20) + 0x2BD20, 0);
        }
        break;
    default:
        ror_assert(D_002E9F28, 0x416, D_002E9F40);
        break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9660);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9678);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9690);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E96F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9700);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9710);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9720);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9730);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9740);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9750);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9758);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9768);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9778);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9780);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9790);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E97A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E97B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E97C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E97D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E97D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E97E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E97F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9800);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9808);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9818);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9828);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9830);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9840);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9850);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9858);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9868);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9878);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9880);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9890);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9898);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E98A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E98A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E98B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E98C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E98D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E98E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E98F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9900);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9910);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9918);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9928);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9938);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9948);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9958);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9968);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9978);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9988);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9990);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E99A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E99B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E99C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E99D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E99E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E99F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A20);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A30);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A50);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A70);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A88);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9A98);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9AA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9AB8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9AC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9AD0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9AE0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9AF0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B20);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B30);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B50);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B70);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9B90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9BA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9BB0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9BB8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9BC8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9BD8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9BE8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9BF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C08);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C38);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C48);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C58);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C68);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C78);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C88);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9C98);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9CA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9CB0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9CC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9CD0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9CE0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9CF0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9D00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9D10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9D28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9D40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9D58);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9D70);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9D88);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9DA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9DB8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9DD0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9DE8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E20);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E38);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E50);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E70);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9E90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9EA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9EB0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9EC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9ED0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9ED8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9EE0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9EE8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9EF0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9EF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9F28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc", D_002E9F40);

extern "C" void func_0011B07C(MagPC *self)
{
    ItemData itemdata[10];
    if (func_0011C64C(self, itemdata, 10, 50.0f) > 0) {
        if (!(itemdata[0].m_obj_id != 0)) ror_assert(D_002E9F28, 0x429, "itemdata[0].m_obj_id != 0");
        func_0011C1E8(self, 0x13, itemdata[0].m_obj_id, 0);
    }
}

// Eight zero bytes follow this function's string in the game, aligned to 8:
// most likely a constant of a function below that is still asm.
__asm__(".section .rodata\n    .align 3\n    .word 0, 0\n.section .text");

extern "C" float func_0011B128(MagPC *self)
{
    if (F(self, 0x114) > F(self, 0x20C)) {
        YawPoint v;
        v.x = F(self, 0x108);
        v.y = 0.0f;
        v.z = -F(self, 0x10C);
        v.w = 1.0f;
        float yaw = vecYaw(&v.x);
        yaw += ((DogCamera *)(I(self, 0x20) + 0x2AB70))->getYaw();
        float r;
        if (yaw < -DOG_PI) {
            r = yaw + DOG_PI2;
        } else {
            r = yaw;
            if (r >= DOG_PI) {
                r -= DOG_PI2;
            }
        }
        F(self, 0x110) = r;
    }
    return F(self, 0x110);
}

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_0011B204(MagPC *self, float theA, float theB)
{
    int r = 1;
    if (func_0011BE30(self) == 0) {
        float d = theB - theA;
        if (d < -DOG_PI) {
            d += DOG_PI2;
        } else if (d >= DOG_PI) {
            d -= DOG_PI2;
        }
        r = 0;
        if (-2.670354f <= d && d < 2.670354f) {
            r = 1;
        }
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", func_0011B204);
#endif


extern "C" int func_0011B2C4(MagPC *self, void *theA)
{
    MagPCMode *mode = *(MagPCMode **)((char *)self + 0x134);
    if (mode) {
        return mode->vfunc03(self, theA);
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", MagLifePC__vfunc_16);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", message__9MagLifePCiiPv);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", func_0011B964);

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_0011BC64(MagPC *self)
{
#line 1666
    ASSERT_S((unsigned int)I(self, 0xD8) < 4, "m_submode_level >= 0 && m_submode_level < 4");
    ((u_long128 *)((char *)self + 0x90))[I(self, 0xD8)] = *(u_long128 *)self;
    I(self, 0xD8)++;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", func_0011BC64);
#endif


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_0011BCD8(MagPC *self)
{
#line 1674
    ASSERT_S((unsigned int)(I(self, 0xD8) - 1) < 4, "m_submode_level > 0 && m_submode_level <= 4");
    I(self, 0xD8)--;
    *(u_long128 *)self = ((u_long128 *)((char *)self + 0x90))[I(self, 0xD8)];
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", func_0011BCD8);
#endif


extern "C" void setActor__9MagLifePCP8DogActorii(MagPC *self, DogActor *theActor, int theA, int theB)
{
    *(DogActor **)((char *)self + 0x58) = theActor;
    I(self, 0x50) = theA;
    I(self, 0x54) = theB;
    I(self, 0xEC) = -1;
    I(self, 0xE4) = func_0011AB88(self);
    if (func_00131550(*(void **)((char *)self + 0x20)) != 5) {
        I(self, 0x78) = 1;
    } else {
        I(self, 0x78) = 0;
    }
    func_0011C1E8(self, 0, 0, 0);
}


extern "C" void func_0011BDC0(MagPC *self)
{
    if (I(self, 0xD4) < 0) {
        I(self, 0xD4) = 0;
    }
    I(self, 0xD4)++;
    if (I(self, 0xD4) > 10) {
        I(self, 0xD4) = 0;
        int n = I(self, 0xD0) - 10;
        I(self, 0xD0) = n < 0 ? 0 : n;
    }
}


extern "C" void func_0011BE00(MagPC *self)
{
    I(self, 0xD0)++;
    if (I(self, 0xD0) > 1000) {
        I(self, 0xD0) = 1000;
    }
    if (I(self, 0xD0) < 0) {
        I(self, 0xD0) = 0;
    }
}


extern "C" int func_0011BE30(MagPC *self)
{
    DogActor *actor = *(DogActor **)((char *)self + 0x58);
    if (actor) {
        return actor->func_0010DB38();
    }
    return 0;
}


extern "C" void reset4MapJump__9MagLifePC(MagPC *self)
{
    *(u_long128 *)((char *)self + 0x30) = 0;
    func_00119B34_c(self);
    func_0011C1E8(self, 0, 0, 0);
    I(self, 0x188) = 0;
    I(self, 0x198) = 0;
    I(self, 0xE8) = 0;
    I(self, 0xEC) = 0;
    I(self, 0xF0) = 0;
    unsigned int id = func_0011CE50(self);
    if (id < 0x80) {
        DogActor *actor = (DogActor *)(I(self, 0x20) + id * 0x4D0 + 0x2920);
        actor->func_0010B1B0(actor->func_0010AA5C("wait2"), 1, 0.016666694f, -1, -1);
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", func_0011BF0C);

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_0011C1E8(MagPC *self, int theMode, int theA, int theForce)
{
#line 2340
    ASSERT(theMode >= 0);
    if (I(self, 0) == theMode && theMode != 0 && !theForce) {
        return;
    }
    func_0011A130(self);
    self->vfunc09(theMode, theA);
    func_0011C2AC(self, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc", func_0011C1E8);
#endif


extern "C" void func_0011C2AC(MagPC *self, int theA)
{
    *(float *)((char *)self + 0x114) = 9999.0f;
    I(self, 0x130) = 0;
    switch (I(self, 0)) {
    case 0:
        I(self, 0x134) = (int)((char *)self + 0x138);
        break;
    case 1:
        I(self, 0x134) = (int)((char *)self + 0x13C);
        break;
    case 2:
        I(self, 0x134) = (int)((char *)self + 0x140);
        break;
    case 3:
        I(self, 0x134) = (int)((char *)self + 0x144);
        break;
    case 4:
        I(self, 0x134) = (int)((char *)self + 0x148);
        break;
    case 5:
        I(self, 0x134) = (int)((char *)self + 0x150);
        break;
    case 6:
        I(self, 0x134) = (int)((char *)self + 0x154);
        break;
    case 10:
        I(self, 0x134) = (int)((char *)self + 0x158);
        break;
    case 14:
        I(self, 0x134) = (int)((char *)self + 0x168);
        break;
    case 19:
        I(self, 0x134) = (int)((char *)self + 0x174);
        break;
    case 15:
        I(self, 0x134) = (int)((char *)self + 0x178);
        break;
    case 16:
        I(self, 0x134) = (int)((char *)self + 0x17C);
        break;
    case 17:
        I(self, 0x134) = (int)((char *)self + 0x180);
        break;
    case 8:
        I(self, 0x134) = (int)((char *)self + 0x184);
        break;
    case 12:
        I(self, 0x134) = (int)((char *)self + 0x18C);
        break;
    case 13:
        I(self, 0x134) = (int)((char *)self + 0x190);
        break;
    case 9:
        I(self, 0x134) = (int)((char *)self + 0x194);
        break;
    case 7:
        I(self, 0x134) = (int)((char *)self + 0x1A0);
        break;
    case 20:
        I(self, 0x134) = (int)((char *)self + 0x1A4);
        break;
    case 18:
        I(self, 0x134) = (int)((char *)self + 0x1A8);
        break;
    default:
        I(self, 0x134) = 0;
        break;
    }
    if (theA != 0) {
        MagPCModeA *mode = (MagPCModeA *)I(self, 0x134);
        if (mode != 0) {
            mode->vfunc01(self);
        }
    }
}

extern "C" void termWorld__9MagLifePC(MagPC *self)
{
    self->vfunc09(-1, 0);
    I(self, 0x134) = 0;
    I(self, 0xD0) = 1000;
}

