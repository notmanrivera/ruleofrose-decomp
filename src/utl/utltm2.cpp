// utl/utltm2.cpp: TIM2 ("TM2") images in memory: finds a picture and tints
// its pixels or its palette (grey value times a colour; DogTexInfo passes
// the colour). Matching decompilation. The asserts sit on lines 125, 147-149,
// 270, 292 and 336 (#line places them). Names are ours except theN, h and
// Pictures (assert string) and theR, theG, theB (inline tint function).
// Still partial (three pixel loops in asm, see below): .bss is in asm because the 0xF0 bytes after the three
// tint factors are used by no decompiled code; the __FILE__ string stays an
// INCLUDE_RODATA (ASSERT_FILE) with it.

#define ASSERT_FILE D_002E76B0
#include "ror.h"
#include "utl/utltm2.h"
#include "include_asm.h"

extern const char D_002E76B0[];     // "utl/utltm2.cpp"
INCLUDE_RODATA("asm/nonmatchings/utl/utltm2", D_002E76B0);

extern int D_00308488;      // tint factors (16.16): red,
extern int D_0030848C;      // green
extern int D_00308490;      // and blue

extern "C" {
void func_00104EF8(unsigned short *thePixels, int theNum) ASM_NOTHROW;
void func_001050E0(unsigned char *thePixels, int theNum) ASM_NOTHROW;
void func_0010528C(unsigned char *thePixels, int theNum) ASM_NOTHROW;
void func_001050B0(Tm2Picture *thePic);
void func_00105254(Tm2Picture *thePic);
void func_00105400(Tm2Picture *thePic);
void func_00105434(Tm2Picture *thePic);
void func_001054E8(Tm2Picture *thePic);
}

// 0x00104E1C: the offset after the last picture, i.e. the file's size.
extern "C" int func_00104E1C(Tm2Header *h)
{
    int off;
    if (h->FormatID == 0) off = 0x10; else off = 0x80;
    int n = h->Pictures;
    for (int i = 0; i < n; i++) {
        off += *(int *)((char *)h + off);
    }
    return off;
}

// 0x00104E5C
extern "C" int func_00104E5C(Tm2Header *h)
{
    return h->FormatID;
}

// 0x00104E64: picture theN of the file, or 0 when theN is negative.
extern "C" Tm2Picture *func_00104E64(Tm2Header *h, int theN)
{
    int off;
    if (h->FormatID == 0) off = 0x10; else off = 0x80;
#line 125
    ASSERT(theN < h->Pictures);
    char *p = 0;
    if (theN >= 0) {
        int i = theN + 1;
        do {
            p = (char *)h + off;
            i--;
            off += *(int *)p;
        } while (i != 0);
    }
    return (Tm2Picture *)p;
}

// The grey value of a pixel (77, 150, 29 over 256) times each tint factor.
static inline void tint(int &theR, int &theG, int &theB)
{
    int grey = theR * 77 + theG * 150 + theB * 29;
    theR = (D_00308488 * grey) >> 16;
    theG = (D_0030848C * grey) >> 16;
    theB = (D_00308490 * grey) >> 16;
#line 147
    ASSERT(theR >= 0 && theR < 256);
    ASSERT(theG >= 0 && theG < 256);
    ASSERT(theB >= 0 && theB < 256);
}

INCLUDE_RODATA("asm/nonmatchings/utl/utltm2", D_002E76D8);
INCLUDE_RODATA("asm/nonmatchings/utl/utltm2", D_002E76F0);
INCLUDE_RODATA("asm/nonmatchings/utl/utltm2", D_002E7708);

#ifdef NON_MATCHING
// NON_MATCHING (this and the two pixel loops below): the game schedules the
// pixel loads between the stores of the inline tint function's locals,
// as if their addresses had escaped; ours hoists all three loads.
// 0x00104EF8: 16 bit pixels (5-5-5).
extern "C" void func_00104EF8(unsigned short *thePixels, int theNum)
{
    for (int i = 0; i < theNum; i++) {
        unsigned short px = *thePixels;
        int r5 = px & 0x1F;
        int g5 = (px >> 5) & 0x1F;
        int b5 = (px >> 10) & 0x1F;
        int r = r5 * 8 + (r5 >> 2);
        int g = g5 * 8 + (g5 >> 2);
        int b = b5 * 8 + (b5 >> 2);
        tint(r, g, b);
        *thePixels = (r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10);
        thePixels++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utltm2", func_00104EF8);
#endif

// 0x001050B0
extern "C" void func_001050B0(Tm2Picture *thePic)
{
    func_00104EF8((unsigned short *)((char *)thePic + thePic->HeaderSize), thePic->ImageSize / 2);
}

#ifdef NON_MATCHING
// 0x001050E0: 24 bit pixels (R, G, B).
extern "C" void func_001050E0(unsigned char *thePixels, int theNum)
{
    for (int i = 0; i < theNum; i++) {
        int r = thePixels[0];
        int g = thePixels[1];
        int b = thePixels[2];
        tint(r, g, b);
        thePixels[0] = r;
        thePixels[1] = g;
        thePixels[2] = b;
        thePixels += 3;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utltm2", func_001050E0);
#endif

// 0x00105254
extern "C" void func_00105254(Tm2Picture *thePic)
{
    int bytes = 3;
    func_001050E0((unsigned char *)thePic + thePic->HeaderSize, thePic->ImageSize / bytes);
}

#ifdef NON_MATCHING
// 0x0010528C: 32 bit pixels (R, G, B, A).
extern "C" void func_0010528C(unsigned char *thePixels, int theNum)
{
    for (int i = 0; i < theNum; i++) {
        int r = thePixels[0];
        int g = thePixels[1];
        int b = thePixels[2];
        tint(r, g, b);
        thePixels[0] = r;
        thePixels[1] = g;
        thePixels[2] = b;
        thePixels += 4;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utltm2", func_0010528C);
#endif

// 0x00105400
extern "C" void func_00105400(Tm2Picture *thePic)
{
    func_0010528C((unsigned char *)thePic + thePic->HeaderSize, thePic->ImageSize / 4);
}

// 0x00105434: the palette of a 4 bit picture.
extern "C" void func_00105434(Tm2Picture *thePic)
{
    unsigned char *clut = (unsigned char *)thePic + thePic->HeaderSize + thePic->ImageSize;
    switch (thePic->ClutType & 0x3F) {
    case 1:
        return func_00104EF8((unsigned short *)clut, thePic->ClutColors);
    case 2:
        return func_001050E0(clut, thePic->ClutColors);
    case 3:
        return func_0010528C(clut, thePic->ClutColors);
    default:
#line 270
        ASSERT(0);
    }
}

// 0x001054E8: the palette of an 8 bit picture.
extern "C" void func_001054E8(Tm2Picture *thePic)
{
    unsigned char *clut = (unsigned char *)thePic + thePic->HeaderSize + thePic->ImageSize;
    switch (thePic->ClutType & 0x3F) {
    case 1:
        return func_00104EF8((unsigned short *)clut, thePic->ClutColors);
    case 2:
        return func_001050E0(clut, thePic->ClutColors);
    case 3:
        return func_0010528C(clut, thePic->ClutColors);
    default:
#line 292
        ASSERT(0);
    }
}

// 0x0010559C: tints the file's first picture (and its palette).
extern "C" void func_0010559C(Tm2Header *h, int theR, int theG, int theB)
{
    D_00308488 = theR;
    D_0030848C = theG;
    D_00308490 = theB;
    Tm2Picture *p = func_00104E64(h, 0);
    switch (p->ImageType) {
    case 1:
        return func_001050B0(p);
    case 2:
        return func_00105254(p);
    case 3:
        return func_00105400(p);
    case 4:
        return func_00105434(p);
    case 5:
        return func_001054E8(p);
    default:
#line 336
        ASSERT(0);
    }
}
