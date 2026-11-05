#include "ror.h"
#include "include_asm.h"
#include "mag/magscene.h"
#include "mag/maglifewindow.h"
#include "dog/dogtexinfo.h"

#undef ASSERT_FILE
#define ASSERT_FILE D_002ED4A0
#define MAX_WINDOW 4

extern const char D_002ED4A0[];     // "mag/magscene.cpp"
extern const char D_002ED680[];     // "winNo >= 0 && winNo < MAX_WINDOW"
extern const char D_002ED6A8[];     // "theN >= 0 && theN < MAX_WINDOW"

extern "C" void func_00130214(MagLifeWindow *w, int a, int b);
extern "C" void func_00130230(MagLifeWindow *w, int a, int b, int c);
extern "C" void func_0012FCA8(MagLifeWindow *w, int a, int b, int c, int d);
extern "C" void func_0012FD30(MagLifeWindow *w, int a);
extern "C" void func_0012FD88(MagLifeWindow *w, int a);
extern "C" void func_0012FDDC(MagLifeWindow *w, int a);
extern "C" void func_0012FE68(MagLifeWindow *w, int a, int b, int c);
extern "C" void func_0012FEF8(MagLifeWindow *w, int a, int b, int c);
extern "C" void func_001BEBEC(void *thePage, void *theArg);
extern "C" void func_001BFF28(void *thePage, int theA);
extern "C" void func_001BFF5C(void *thePage, int theA);
extern "C" void func_001BFF64(void *thePage, int theA);
extern "C" void func_001C047C(void *thePage, int theA);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013114C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131184);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001311BC);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED478);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED4A0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED4B8);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001311F4);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131550);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131608);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131618);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013164C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013166C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131690);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001316B8__8MagSceneii);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131790__8MagSceneii);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED500);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131840__8MagScene);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131A28__8MagScene);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131B90__8MagSceneP7I3dDraw);

void func_00131F6C(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131F74);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED538);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED570);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED580);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00132048);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013233C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00132430);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013262C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00132744);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00132784);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001327A0);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001327DC__8MagSceneP6BedPadT1);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133090);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001330F4);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133144);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001331F4);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133288);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133324);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001333C0);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001333E4);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133440);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133454);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133658);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013377C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013386C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133A0C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133B80);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133D10);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133E94);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133EFC);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133F68);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134114);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001342BC);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134460);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001344C4);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134624);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134698);

extern "C" int func_00134730(MagScene *self, int theW, int theH, int theA, int theFlag)
{
    int n;
    for (n = 0; n < 4; n++) {
        if (!self->m_window[n]) {
            break;
        }
    }
    if (n >= 4) {
        return -1;
    }
    self->m_window[n] = new MagLifeWindow;
#line 2110
    ASSERT_S(self->m_window[n], "m_window[ n ]");
    self->m_window[n]->func_0012FE30(theW, theH);
    func_001BEBEC(&self->m_unk02744[n], self->m_unk02908);
    self->m_window[n]->func_00130778(&self->m_unk02744[n]);
    self->m_window[n]->m_font_tex = self->m_unk028F4[n];
    self->m_window[n]->m_unk80 = theFlag;
    if (theFlag > 0) {
        BedSubMode *sub = &self->m_sub_mode;
        ((int *)sub)[0] = 2;
        ((int *)sub)[1] = -1;
    }
    self->m_life_man.add(self->m_window[n], 0x800C);
    return n;
}


extern "C" void func_001348B0(MagScene *self, int winNo)
{
#line 2137
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        self->m_life_man.remove(self->m_window[winNo]);
        delete self->m_window[winNo];
        self->m_window[winNo] = 0;
    }
}


// NON_MATCHING: the float registers come out in another order.
#ifdef NON_MATCHING
void MagScene::func_00134944(int theN, int *theParam)
{
#line 2156
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    if (m_window[theN]) {
        DogVector pos((float)theParam[0], (float)theParam[1], (float)theParam[2], 1.0f);
        m_window[theN]->m_pos = pos;
        m_window[theN]->m_h = theParam[4];
        m_window[theN]->m_w = theParam[3];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134944__8MagSceneiPi);
#endif


// NON_MATCHING: the float registers come out in another order.
#ifdef NON_MATCHING
extern "C" void func_00134A00(MagScene *self, int winNo, int theX, int theY, int theZ)
{
#line 2179
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    MagLifeWindow *w = self->m_window[winNo];
    if (w) {
        DogVector pos((float)theX, (float)theY, (float)theZ, 1.0f);
        w->m_pos = pos;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134A00);
#endif


extern "C" void func_00134AB8(MagScene *self, int winNo, int theW, int theH)
{
#line 2194
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    MagLifeWindow *w = self->m_window[winNo];
    if (w) {
        w->m_w = theW;
        w->m_h = theH;
    }
}


extern "C" void func_00134B34(MagScene *self, int winNo, int a, int b)
{
#line 2205
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_00130214(self->m_window[winNo], a, b);
    }
}


extern "C" void func_00134BB8(MagScene *self, int winNo, int a, int b, int c)
{
#line 2215
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_00130230(self->m_window[winNo], a, b, c);
    }
}


extern "C" void func_00134C4C(MagScene *self, int theN, int *theW, int *theH)
{
#line 2225
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    MagLifeWindow *w = self->m_window[theN];
    if (w) {
        *theW = w->m_w;
        *theH = w->m_h;
    }
}


extern "C" void func_00134CD0(MagScene *self, int theN, int theX, int theY, int theW, int theH)
{
#line 2242
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    MagLifeWindow *w = self->m_window[theN];
    if (w) {
        w->m_unk84 = theX;
        w->m_unk88 = theY;
        w->m_unk8C = theW;
        w->m_unk90 = theH;
    }
}


extern "C" void func_00134D6C(MagScene *self, int theN, int *theX, int *theY, int *theW, int *theH)
{
#line 2252
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    MagLifeWindow *w = self->m_window[theN];
    if (w) {
        *theX = w->m_unk84;
        *theY = w->m_unk88;
        *theW = w->m_unk8C;
        *theH = w->m_unk90;
    }
}


extern "C" void func_00134E18(MagScene *self, int theN, int *theOut)
{
#line 2262
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    MagLifeWindow *w = self->m_window[theN];
    if (w) {
        *theOut = w->m_unkCC;
    }
}


extern "C" void func_00134E88(MagScene *self, int winNo, int a, int b, int c, int d)
{
#line 2272
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_0012FCA8(self->m_window[winNo], a, b, c, d);
    }
}


extern "C" void func_00134F2C(MagScene *self, int winNo, int a)
{
#line 2282
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_0012FD30(self->m_window[winNo], a);
    }
}


extern "C" void func_00134FA0(MagScene *self, int winNo, int a)
{
#line 2292
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_0012FD88(self->m_window[winNo], a);
    }
}


extern "C" void func_00135014(MagScene *self, int winNo, int a)
{
#line 2302
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_0012FDDC(self->m_window[winNo], a);
    }
}


extern "C" void func_00135088(MagScene *self, int theN, int a, int b, int c)
{
#line 2318
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    if (self->m_window[theN]) {
        func_0012FE68(self->m_window[theN], a, b, c);
    }
}


extern "C" void func_0013511C(MagScene *self, int theN, int a, int b, int c)
{
#line 2333
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    if (self->m_window[theN]) {
        func_0012FEF8(self->m_window[theN], a, b, c);
    }
}


extern "C" void func_001351B0(MagScene *self, int winNo, int theHide)
{
#line 2349
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        self->m_window[winNo]->setHide(theHide != 0);
    }
}


INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED680);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED6A8);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135234__8MagSceneiiiii);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135364);

extern "C" void func_00135418(MagScene *self, int winNo, int theA)
{
#line 2409
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    func_001BFF28(&self->m_unk02744[winNo], theA);
}


extern "C" void func_00135494(MagScene *self, int winNo, int theA)
{
#line 2417
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    func_001BFF5C(&self->m_unk02744[winNo], theA);
    func_00135418(self, winNo, 0);
}


extern "C" void func_00135520(MagScene *self, int theN, int theA)
{
    func_001BFF64(&self->m_unk02744[theN], theA);
}


extern "C" void func_0013555C(MagScene *self, int theN, int theA)
{
    return func_001C047C(&self->m_unk02744[theN], theA);
}


INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135594);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135628);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013569C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135740);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001357B0);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013580C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135B64);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135B78);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135CAC);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135D58);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135DCC);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135E20);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135F44);
