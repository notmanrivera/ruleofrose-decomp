// Sony libgraph (SDK 3.0), reconstructed: only what the game's code uses.
// Function names come from tools/sce_symbols.py; the GS register layouts
// follow the GS manual (the SDK's field names), the rest is ours.
#ifndef SDK_LIBGRAPH_H
#define SDK_LIBGRAPH_H

// GS registers. EE `long` is 64 bits, so every register is one u_long.
typedef struct {
    unsigned long EN1:1;
    unsigned long EN2:1;
    unsigned long CRTMD:3;
    unsigned long MMOD:1;
    unsigned long AMOD:1;
    unsigned long SLBG:1;
    unsigned long ALP:8;
    unsigned long p0:48;
} tGS_PMODE;

typedef struct {
    unsigned long INT:1;
    unsigned long FFMD:1;
    unsigned long DPMS:2;
    unsigned long p0:60;
} tGS_SMODE2;

typedef struct {
    unsigned long FBP:9;
    unsigned long FBW:6;
    unsigned long PSM:5;
    unsigned long p0:12;
    unsigned long DBX:11;
    unsigned long DBY:11;
    unsigned long p1:10;
} tGS_DISPFB2;

typedef struct {
    unsigned long DX:12;
    unsigned long DY:11;
    unsigned long MAGH:4;
    unsigned long MAGV:2;
    unsigned long p0:3;
    unsigned long DW:12;
    unsigned long DH:11;
    unsigned long p1:9;
} tGS_DISPLAY2;

typedef struct {
    unsigned long R:8;
    unsigned long G:8;
    unsigned long B:8;
    unsigned long p0:40;
} tGS_BGCOLOR;

typedef struct {
    unsigned long FBP:9;
    unsigned long p0:7;
    unsigned long FBW:6;
    unsigned long p1:2;
    unsigned long PSM:6;
    unsigned long p2:2;
    unsigned long FBMSK:32;
} sceGsFrame;

typedef struct {
    unsigned long ZBP:9;
    unsigned long p0:15;
    unsigned long PSM:4;
    unsigned long p1:4;
    unsigned long ZMSK:1;
    unsigned long p2:31;
} sceGsZbuf;

typedef struct {
    unsigned long R:8;
    unsigned long G:8;
    unsigned long B:8;
    unsigned long A:8;
    float Q;
} sceGsRgbaq;

typedef struct {
    unsigned long NLOOP:15;
    unsigned long EOP:1;
    unsigned long pad16:16;
    unsigned long id:14;
    unsigned long PRE:1;
    unsigned long PRIM:11;
    unsigned long FLG:2;
    unsigned long NREG:4;
    unsigned long REGS0:4;
    unsigned long REGS1:4;
    unsigned long REGS2:4;
    unsigned long REGS3:4;
    unsigned long REGS4:4;
    unsigned long REGS5:4;
    unsigned long REGS6:4;
    unsigned long REGS7:4;
    unsigned long REGS8:4;
    unsigned long REGS9:4;
    unsigned long REGS10:4;
    unsigned long REGS11:4;
    unsigned long REGS12:4;
    unsigned long REGS13:4;
    unsigned long REGS14:4;
    unsigned long REGS15:4;
} sceGifTag __attribute__((aligned(16)));

typedef struct {
    tGS_PMODE pmode;
    tGS_SMODE2 smode2;
    tGS_DISPFB2 dispfb;
    tGS_DISPLAY2 display;
    tGS_BGCOLOR bgcolor;
} sceGsDispEnv;                     // 0x28

typedef struct {
    sceGsFrame frame1;
    unsigned long frame1addr;
    sceGsZbuf zbuf1;
    long zbuf1addr;
    unsigned long xyoffset1;
    long xyoffset1addr;
    unsigned long scissor1;
    long scissor1addr;
    unsigned long prmodecont;
    long prmodecontaddr;
    unsigned long colclamp;
    long colclampaddr;
    unsigned long dthe;
    long dtheaddr;
    unsigned long test1;
    long test1addr;
} sceGsDrawEnv1;                    // 0x80

typedef struct {
    unsigned long testa;
    long testaaddr;
    unsigned long prim;
    long primaddr;
    sceGsRgbaq rgbaq;
    long rgbaqaddr;
    unsigned long xyz2a;
    long xyz2aaddr;
    unsigned long xyz2b;
    long xyz2baddr;
    unsigned long testb;
    long testbaddr;
} sceGsClear;                       // 0x60

typedef struct {
    sceGsDispEnv disp[2];           // +0x000
    sceGifTag giftag0;              // +0x050
    sceGsDrawEnv1 draw0;            // +0x060
    sceGsClear clear0;              // +0x0E0
    sceGifTag giftag1;              // +0x140
    sceGsDrawEnv1 draw1;            // +0x150
    sceGsClear clear1;              // +0x1D0
} sceGsDBuff;                       // 0x230

// The packet sceGsSetDefStoreImage builds (0x70 bytes).
typedef struct {
    unsigned char m_unk[0x70];
} sceGsStoreImage __attribute__((aligned(16)));

// Arguments of sceGsResetGraph / sceGsSetDefDBuff.
#define SCE_GS_NOINTERLACE 0
#define SCE_GS_INTERLACE 1
#define SCE_GS_FIELD 0
#define SCE_GS_FRAME 1
#define SCE_GS_NTSC 2
#define SCE_GS_PSMCT32 0
#define SCE_GS_PSMZ16S 0x3A
#define SCE_GS_ZGEQUAL 2

// GS privileged registers.
#define GS_PMODE ((volatile unsigned long *)0x12000000)

extern "C" {

void sceGsResetGraph(short mode, short inter, short omode, short ffmode);
void sceGsResetPath(void);
void sceGsSetDefDBuff(sceGsDBuff *dp, short psm, short w, short h, short ztest, short zpsm,
                      short clear);
int sceGsSwapDBuff(sceGsDBuff *db, int id);
int sceGsSyncPath(int mode, unsigned short timeout);
int sceGsSyncVCallback(int (*func)(int));
int sceGsSetDefStoreImage(sceGsStoreImage *sp, short sbp, short sbw, short spsm, short x,
                          short y, short w, short h);
int sceGsExecStoreImage(sceGsStoreImage *sp, void *dstaddr);

}

#endif
