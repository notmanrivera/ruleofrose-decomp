#include "include_asm.h"
#define MAGLIFE_EXTERNAL_RTTI
#include "mag/maglife.h"
#include "mag/maglifewindow.h"
#include "bed/bedpad.h"
struct Arg223558 {
    float unk00;
    void *unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct NoiseDrawParam {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
class MagLifeNoise;
extern "C" int func_00223558(void *, Arg223558 *);
extern "C" void func_00223228(void *, int);
extern "C" int func_00223298(void *, float);
extern "C" void func_002232F0(void *, int);
extern "C" int func_0021B260(int, int);
extern "C" int func_0021B4F8(int, int);
extern "C" int func_00130C34(MagLifeNoise *, int, NoiseDrawParam *);
class MagLifeTest : public MagLifeControlChara {
public:
    int m_unk80;                    // +0x80
};
class MagLifeNoise : public MagLife {
public:
    int m_unk30;                    // +0x30
    int m_unk34;                    // +0x34
    MagLifeNoise() asm("func_00130DA4");
    virtual ~MagLifeNoise() {}
    virtual void render(tag_I3dRenderStage_s *theStage);
};
static inline unsigned int padTriggerU(const BedPad *p) { return p->m_trigger; }
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int func_00130A2C(MagLifeNoise *, int, NoiseDrawParam *, int, int, int, int);
extern "C" int func_0021B550(int, int, unsigned long long);

MagLifeWindow::MagLifeWindow()
{
    m_unk80 = 0;
    m_unk84 = 0;
    m_unk88 = 0;
    m_unk8C = 0;
    m_unk90 = 0;
    m_w = 0;
    m_h = 0;
    m_unk9C = 0xFF;
    m_unkA0 = 0xFF;
    m_unkA4 = 0xFF;
    m_unkA8 = 0x80;
    m_unkAC = -1;
    m_unkB0 = 128.0f;
    m_unkB4 = 0.0f;
    m_unkB8 = 0.0f;
    m_unkBC = 128.0f;
    m_font_tex = -1;
    m_fntman = 0;
    m_ch_w = 0;
    m_ch_h = 0;
    m_buf_w = 0;
    m_buf_h = 0;
    m_unkD8 = 0;
    m_unkDC = 0;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_00130A2C);

static inline int clamp0(int n)
{
    if (n < 0) {
        n = 0;
    }
    return n;
}

extern "C" int func_00130C34(MagLifeNoise *self, int prim, NoiseDrawParam *param)
{
    if (param->unk18 == 0) {
        return prim;
    }

    prim = func_0021B550(prim, 8, 0);
    prim = func_0021B550(prim, 1, 0x3F202020);
    prim = func_0021B550(prim, 0x47, 0x31001);

    prim = func_00130A2C(self, prim, param, 0x190, 0x190, clamp0((param->unk18 + 3) / 4), 1);
    prim = func_00130A2C(self, prim, param, 0x258, 0x258, clamp0((param->unk18 + 2) / 4), 0);
    prim = func_00130A2C(self, prim, param, 0x378, 0x378, clamp0((param->unk18 + 1) / 4), 1);
    return func_00130A2C(self, prim, param, 0x3E8, 0x3E8, clamp0(param->unk18 / 4), 0);
}

// NON_MATCHING: 2/15 differ, 4 edits
#ifdef NON_MATCHING
MagLifeNoise::MagLifeNoise() : m_unk30(0)
{
    m_unk34 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_00130DA4);
#endif

extern "C" void func_00130DE0(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x30)) = arg1;
}


// NON_MATCHING: 5/64 differ, 4 edits
#ifdef NON_MATCHING
extern "C" void MagLifeNoise__vfunc_06(MagLifeNoise *self, void *theStage)
{
    if (self->m_unk30 != 0) {
        NoiseDrawParam param;
        Arg223558 q;
        param.unk00 = 0x700;
        param.unk04 = 0x720;
        param.unk10 = 0x200;
        param.unk14 = 0x1C0;
        param.unk18 = self->m_unk30;
        param.unk08 = 0;
        param.unk0C = 0;
        q.unk00 = 1.0f;
        q.unk04 = &self->m_unk34;
        q.unk08 = 1;
        q.unk0C = 0;
        q.unk10 = 0;
        q.unk14 = 0;
        int tex = func_00223558(theStage, &q);
        func_00223228(theStage, tex);
        int ctx = func_00223298(theStage, 895.0f);
        func_002232F0(theStage, func_00130C34(self, func_0021B4F8(ctx, func_0021B260(tex, 0)), &param));
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", MagLifeNoise__vfunc_06);
#endif

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED3C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED3D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED408);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", live__11MagLifeTest);

extern "C" void MagLifeTest__vfunc_16(MagLifeTest *self, BedPad *thePad)
{
    if (self->m_actor != 0 && ((padTriggerU(thePad) >> BEDPAD_BIT_R2) & 1)) {
        self->m_unk80 = 1;
    }
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED478);
