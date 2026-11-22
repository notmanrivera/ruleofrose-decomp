// system/sysnowloading.h: SysNowLoading (the loading screen renderer,
// 0x204D38..0x2053F3) and the debug exception handler installer
// (0x204BF8..0x204D37).
//
// Evidence:
// - "system/sysnowloading.cpp" (D_002FF8D0) passed to BedMemory::alloc in
//   func_002050E8 (line 0xF6) and func_002052AC (lines 0x130, 0x131).
// - "cdrom0:\\DATA\\CMNTEX\\LOADING.BIN" (D_002FF8A0) loaded by func_00204D38.
// - Layout of SysNowLoading comes from func_00204D38..func_00205394:
//   sceGsDBuff at +0x000 (0x230 bytes), sceGsLoadImage at +0x230 (0x60 bytes),
//   m_texBuf at +0x290, m_dmaBuf at +0x294, m_dmaChan at +0x298, m_frame at +0x29C.
#ifndef SYSTEM_SYSNOWLOADING_H
#define SYSTEM_SYSNOWLOADING_H

#include "sdk/eekernel.h"
#include "sdk/libdma.h"
#include "sdk/libgraph.h"
#include "sdk/sifdev.h"

// The packet sceGsSetDefLoadImage builds (0x60 bytes, 16-byte aligned).
typedef struct {
    unsigned char m_unk[0x60];
} sceGsLoadImage __attribute__((aligned(16)));

// EE timer 0 mode register (T0_MODE).
#define T0_MODE ((volatile unsigned int *)0x10000010)

// DMA/GIF 128-bit packet element (ours).
struct SysNowLoadQuad {
    unsigned int m_w[4];
} __attribute__((aligned(16)));

struct SysNowLoadReg {
    unsigned long m_val;
    unsigned long m_addr;
} __attribute__((aligned(16)));

// sizeof 0x2A0.
struct SysNowLoading {
    sceGsDBuff m_dbuff;             // +0x000 (0x230)
    sceGsLoadImage m_loadImage;     // +0x230 (0x60)
    void *m_texBuf;                 // +0x290: 0x100000-byte LOADING.BIN buffer
    void *m_dmaBuf;                 // +0x294: 0x4000-byte GIF/DMA packet buffer
    sceDmaChan *m_dmaChan;          // +0x298: sceDmaGetChan(2) (GIF)
    int m_frame;                    // +0x29C: frame counter
};

extern "C" {

void *SetDebugHandler(int cause, void *handler);
int sceRead(int fd, void *buf, int nbyte);
int sceGsSetDefLoadImage(sceGsLoadImage *lp, short dbp, short dbw, short dpsm,
                         short x, short y, short w, short h);
int sceGsExecLoadImage(sceGsLoadImage *lp, void *srcaddr);
int sceGsSyncV(int mode);

}

#endif
