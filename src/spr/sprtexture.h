// spr/sprtexture.h: texture-table loading and RTCM decompression.
// Names without symbol evidence are ours. Offsets come from 0x18F6DC..0x190A77.
#ifndef SPR_SPRTEXTURE_H
#define SPR_SPRTEXTURE_H

// This partial translation unit uses the vtables/RTTI kept in asm/inline
// and asm/data/vtbl, including their original interleaved rodata strings.
#ifdef TARGET_PS2
#pragma interface
#endif

#include "ror.h"
#include "mnu/mnucommon.h"
#include "bed/bedpfh.h"
#define MAGLIFE_EXTERNAL_RTTI
#include "mag/maglife.h"
#undef MAGLIFE_EXTERNAL_RTTI

struct tag_I3dTexInfo_s;
class BedPfh;
class DogTexInfo;
class FileReader;

struct SprTexture {
    MnuRpkEntry *m_entries;             // +0x000
    const char *m_packName;             // +0x004
    void *m_data;                       // +0x008
    int m_unk0C;                       // +0x00C
    char m_filename[0x100];             // +0x010
    void *m_unk110;                      // +0x110
    unsigned int m_unk114;              // +0x114
    int m_unk118;                      // +0x118
    int m_state;                       // +0x11C
    int m_readState;                   // +0x120
    int m_unk124;                      // +0x124
    int m_count;                       // +0x128
    int m_texIds[60];                  // +0x12C
    int m_indices[60];                 // +0x21C
    tag_I3dTexInfo_s *m_unk30C[60];                  // +0x30C
    FileReader *m_reader;              // +0x3FC
    int m_unk400;                      // +0x400
    int m_unk404[2];                   // +0x404
    int m_readResult;                  // +0x40C
    int m_unk410;                      // +0x410
    DogTexInfo *m_texInfo;             // +0x414
    void *m_unk418;                    // +0x418
    BedPfh m_pack;                     // +0x41C
    BedPfh *m_pfh;                     // +0x430
    int m_loadMode;                    // +0x434
};

struct RtcmHeader {
    unsigned char m_magic[8];          // +0x00
    int m_outputSize;                  // +0x08
    unsigned int m_fileSize;           // +0x0C
    short m_unitSize;                  // +0x10
    unsigned char m_unk12[0x0E];       // +0x12
};

STATIC_ASSERT(sizeof(SprTexture) == 0x438, SprTexture_size);
STATIC_ASSERT(sizeof(RtcmHeader) == 0x20, RtcmHeader_size);

// These scene objects use MagLife's slots 1..8. The overriding symbols and
// getName names are recorded in symbols/ghidra_symbols.tsv.
class MagSystem;
struct S2dCineSco : public MagLife {
    int m_active;                      // +0x030
    int m_open;                        // +0x034
    unsigned int m_state;              // +0x038
    MnuRpk m_rpk;                      // +0x03C
    MagSystem *m_system;               // +0x928

    S2dCineSco() asm("func_00190A78");
    virtual ~S2dCineSco() asm("S2dCineSco__vfunc_01");
    virtual void live() asm("S2dCineSco__vfunc_02");
    virtual const char *getName() { return 0; }
    virtual void render(tag_I3dRenderStage_s *) asm("S2dCineSco__vfunc_06");
};

struct S2dBg : public MagLife {
    int m_active;                      // +0x030
    int m_open;                        // +0x034
    unsigned int m_state;              // +0x038
    int m_unk3C;                       // +0x03C
    int m_unk40;                       // +0x040
    int m_unk44;                       // +0x044
    MnuRpk m_rpk;                      // +0x048
    MagSystem *m_system;               // +0x934
    DogTexInfo *m_texInfo;              // +0x938
    unsigned int m_loadState;          // +0x93C

    S2dBg() asm("func_00190F6C");
    virtual ~S2dBg() asm("S2dBg__vfunc_01");
    virtual void live() asm("S2dBg__vfunc_02");
    virtual const char *getName() { return 0; }
    virtual void render(tag_I3dRenderStage_s *) asm("S2dBg__vfunc_06");
};

struct S2dMes : public MagLife {
    int m_active;                      // +0x030
    int m_open;                        // +0x034
    unsigned int m_state;              // +0x038
    int m_unk3C;                       // +0x03C
    int m_unk40;                       // +0x040
    int m_unk44;                       // +0x044
    MnuRpk m_rpk;                      // +0x048
    MagSystem *m_system;               // +0x934
    int m_unk938;                      // +0x938
    int m_unk93C;                      // +0x93C
    int m_unk940;                      // +0x940
    int m_unk944;                      // +0x944
    int m_unk948;                      // +0x948
    int m_unk94C;                      // +0x94C

    S2dMes() asm("func_00191494");
    virtual ~S2dMes() asm("S2dMes__vfunc_01");
    virtual void live() asm("S2dMes__vfunc_02");
    virtual void render(tag_I3dRenderStage_s *) asm("S2dMes__vfunc_06");
};

STATIC_ASSERT(sizeof(S2dCineSco) == 0x92C, S2dCineSco_size);
STATIC_ASSERT(sizeof(S2dBg) == 0x940, S2dBg_size);
STATIC_ASSERT(sizeof(S2dMes) == 0x950, S2dMes_size);

extern "C" {
int func_0018F6DC(SprTexture *, int);
int func_0018F6F8(SprTexture *, int);
tag_I3dTexInfo_s *func_0018F734(SprTexture *, int);
void func_0018F744(SprTexture *, MnuRpkEntry *, const char *);
void func_0018F808(SprTexture *, MnuRpkEntry *, const char *, int);
void func_0018F824(SprTexture *);
int func_0018F9CC(SprTexture *, int);
int func_0018FBB0(SprTexture *, int);
int func_00190618(SprTexture *);
int func_0018FAB4(SprTexture *, int);
int func_0018FE8C(SprTexture *, const char *);
int func_0018FEBC(SprTexture *);
void func_001905A0(SprTexture *, int);
void func_001905A8(SprTexture *, int);
int func_001905B0(SprTexture *, const char *, void *, unsigned int, int);
int func_00190884(SprTexture *, const unsigned char *, const unsigned char *);
int func_001908D0(SprTexture *, const RtcmHeader *);
void *func_00190904(SprTexture *, const RtcmHeader *);
}

#endif
