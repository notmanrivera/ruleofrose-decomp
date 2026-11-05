#include "ror.h"
#include "include_asm.h"
#include "mag/maglifewindow.h"

#undef ASSERT_FILE
#define ASSERT_FILE D_002ED328
#define FNTMAN D_002ED340

extern const char D_002ED328[];     // "mag/maglifewindow.cpp"
extern const char D_002ED340[];     // "m_fntman"

struct MagFadeKey {
    int m_mode;                     // +0x00
    int m_unk04;                    // +0x04
    int m_unk08;                    // +0x08
    int m_unk0C;                    // +0x0C
    unsigned char m_unk10[0x20];
    int m_time;                     // +0x30
    int m_count;                    // +0x34
    unsigned char m_unk38[0xC];
    float m_ratio0;                 // +0x44
    float m_ratio1;                 // +0x48
    float m_ratio2;                 // +0x4C
};

struct MagFadeReq {
    int m_unk00;
    int m_mode;
    int m_count;
};

extern "C" void func_001C0078(MagFntMan *theMan, int a, int b, int c, int d);
extern "C" void func_001C047C(MagFntMan *theMan, const char *theStr);

// NON_MATCHING: the stores come out in another order.
#ifdef NON_MATCHING
extern "C" void func_0012F7F4(MagFadeKey *self, int theMode, int theCount)
{
    self->m_ratio1 = 1.0f;
    self->m_count = theCount;
    self->m_unk04 = 0;
    self->m_unk08 = theCount;
    self->m_unk0C = 0;
    self->m_time = 0;
    self->m_ratio0 = 1.0f;
    self->m_ratio2 = 1.0f;
    self->m_mode = theMode;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_0012F7F4);
#endif


// NON_MATCHING: the stores come out in another order.
#ifdef NON_MATCHING
extern "C" void func_0012F824(MagFadeKey *self, MagFadeReq *theReq)
{
    self->m_mode = theReq->m_mode;
    self->m_unk0C = 0;
    self->m_unk08 = theReq->m_count;
    self->m_time = 0;
    self->m_count = theReq->m_count;
    self->m_unk04 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_0012F824);
#endif


INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", MagLifeFadeKeyHole__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", MagLifeFadeKeyHole__vfunc_06);

extern "C" void func_0012FC80(MagFadeKey *self, float theMagnify, int theCount)
{
    if (theCount <= 0) {
        self->m_ratio0 = theMagnify;
        self->m_count = 0;
    } else {
        self->m_ratio1 = self->m_ratio0;
        self->m_ratio2 = theMagnify;
        self->m_time = 0;
        self->m_count = theCount;
    }
}


extern "C" void func_0012FCA8(MagLifeWindow *self, int a, int b, int c, int d)
{
#line 43
    ASSERT_S(self->m_fntman, FNTMAN);
    func_001C0078(self->m_fntman, a, b, c, d);
}


extern "C" void func_0012FD30(MagLifeWindow *self, int a)
{
#line 49
    ASSERT_S(self->m_fntman, FNTMAN);
    self->m_fntman->m_unk28 = a != 0;
}


extern "C" void func_0012FD88(MagLifeWindow *self, int a)
{
#line 55
    ASSERT_S(self->m_fntman, FNTMAN);
    self->m_fntman->m_unk30 = a;
}


extern "C" void func_0012FDDC(MagLifeWindow *self, int a)
{
#line 61
    ASSERT_S(self->m_fntman, FNTMAN);
    self->m_fntman->m_unk34 = a;
}


// NON_MATCHING: the stores come out in another order.
#ifdef NON_MATCHING
void MagLifeWindow::func_0012FE30(int theW, int theH)
{
    m_unkBC = 128.0f;
    m_w = theW;
    m_h = theH;
    m_unkAC = -1;
    m_buf_w = 0x200;
    m_unkB4 = 128.0f;
    m_unkB8 = 0.0f;
    m_unkB0 = 0.0f;
    m_buf_h = 0x200;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_0012FE30);
#endif


INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_0012FE68);

INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_0012FEF8);

extern "C" void live__13MagLifeWindow(MagLifeWindow *self)
{
    if (self->m_unk80 > 0) {
        self->m_unk80--;
    }
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", render__13MagLifeWindowP20tag_I3dRenderStage_s);

INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_00130214);

INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_00130230);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifewindow", D_002ED2F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifewindow", D_002ED328);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifewindow", D_002ED340);

INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_00130258);

INCLUDE_ASM("asm/nonmatchings/mag/maglifewindow", func_001305EC);

void MagLifeWindow::func_00130778(MagFntMan *thefontManager)
{
#line 578
    ASSERT(thefontManager);
    m_fntman = thefontManager;
    m_ch_w = thefontManager->m_ch_w;
#line 582
    ASSERT(m_ch_w);
    m_ch_h = thefontManager->m_ch_h;
#line 585
    ASSERT(m_ch_h);
    m_buf_w = thefontManager->m_buf_w;
#line 588
    ASSERT(m_buf_w);
    m_buf_h = thefontManager->m_buf_h;
#line 591
    ASSERT(m_buf_h);
    m_unk8C = m_buf_w;
    m_unk90 = m_buf_h;
    m_unk88 = 0;
    m_unk84 = 0;
}


extern "C" void func_0013086C(MagLifeWindow *self, const char *theStr)
{
#line 608
    ASSERT(theStr);
    return func_001C047C(self->m_fntman, theStr);
}

