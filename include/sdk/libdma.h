// Sony libdma (SDK 3.0), reconstructed: only what the game's code uses.
// Function names come from tools/sce_symbols.py; the channel layout is the
// EE's DMA channel registers.
#ifndef SDK_LIBDMA_H
#define SDK_LIBDMA_H

typedef struct {
    unsigned DIR:1;
    unsigned p0:1;
    unsigned MOD:2;
    unsigned ASP:2;
    unsigned TTE:1;
    unsigned TIE:1;
    unsigned STR:1;
    unsigned p1:7;
    unsigned TAG:16;
} tD_CHCR;

// A channel's registers (D1_CHCR at 0x10009000...): CHCR first.
typedef struct {
    tD_CHCR chcr;                   // +0x00
    unsigned int p0[3];
    volatile void *madr;            // +0x10
    unsigned int p1[3];
    volatile unsigned int qwc;      // +0x20
    unsigned int p2[3];
    volatile void *tadr;            // +0x30
    unsigned int p3[3];
} sceDmaChan;

#define SCE_DMA_VIF1 1

extern "C" {

sceDmaChan *sceDmaGetChan(int id);
int sceDmaReset(int mode);
void sceDmaSend(sceDmaChan *d, void *tag);
int sceDmaSync(sceDmaChan *d, int mode, int timeout);

}

#endif
