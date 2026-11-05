#include "ror.h"
#include "include_asm.h"
extern const char D_002ED258[];
extern const char D_002ED268[];
#undef ASSERT_FILE
#define ASSERT_FILE D_002ED218
extern const char D_002ED218[];
extern const char D_002ED278[];
extern const char D_002ED230[];
extern const char D_002ED200[];
#include "utl/filereader.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"
#include "dog/dogtexinfo.h"
#include "sdk/string.h"
extern BedMemory D_006E9800;
struct MagFader {
    int m_mode;                     // +0x00
    int m_unk04;                    // +0x04
    unsigned char m_unk08[0x28];
    int m_time;                     // +0x30
    int m_count;                    // +0x34
    int m_unk38;
    unsigned char m_unk3C[4];
    int m_tex;                      // +0x40
};
struct MagFadeReq {
    int m_unk00;
    int m_mode;
    int m_count;
};

INCLUDE_ASM("asm/nonmatchings/mag/maglifefadekey", func_0012F008);

extern "C" void func_0012F048(MagFader *self, int theMode, int theCount)
{
    self->m_count = theCount;
    self->m_unk04 = -1;
    self->m_mode = theMode;
    self->m_time = 0;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_0012F060(MagFader *self, MagFadeReq *theReq)
{
    self->m_unk04 = -1;
    self->m_mode = theReq->m_mode;
    self->m_time = 0;
    self->m_count = theReq->m_count;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifefadekey", func_0012F060);
#endif


extern "C" void func_0012F080(MagFader *self)
{
    self->m_mode = 4;
    self->m_unk04 = -1;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifefadekey", MagLifeFader__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED148);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED158);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED170);

INCLUDE_ASM("asm/nonmatchings/mag/maglifefadekey", MagLifeFader__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/mag/maglifefadekey", func_0012F298);

extern "C" int func_0012F2F0(MagFader *self, DogTexInfo *theTexInfo, int theN)
{
    char tmp[0x840];
    memset(tmp, 0, sizeof(tmp));
    FileReader reader;
    FileReadReq req;
    req.m_name = D_002ED200;
    req.m_size = 0x800;
    req.m_buf = (void *)((int)tmp / 0x40 * 0x40 + 0x40);
    reader.func_001BE524(&req, 0);
    BedPfh pfh_head(req.m_buf);
#line 77
    ASSERT_S(pfh_head.getFileOffset(0) == (2048), D_002ED230);
    int filelen = pfh_head.getFileSize(theN);
#line 81
    ASSERT_S(filelen > 0, D_002ED258);
    int size = (filelen + 0x7FF) / 0x800 * 0x800;
#line 86
    void *p = D_006E9800.alloc(size, ASSERT_FILE, 86, 0, 1);
    ASSERT_S(p != __null, D_002ED268);
    req.m_offset = pfh_head.getFileOffset(theN);
    req.m_size = size;
    req.m_buf = p;
    req.m_unk20 = 1;
    req.m_unk14 = 0;
    reader.func_001BE524(&req, 0);
    self->m_tex = theTexInfo->loadTM2(D_002ED278, p, 1, -1);
    D_006E9800.free(p);
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED1D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED200);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED218);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED230);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED258);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED268);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifefadekey", D_002ED278);

extern "C" int func_0012F518(MagFader *self, DogTexInfo *theTexInfo, const char *theName)
{
#line 110
    ASSERT(theName);
    char tmp[0x840];
    memset(tmp, 0, sizeof(tmp));
    FileReader reader;
    FileReadReq req;
    req.m_name = D_002ED200;
    req.m_size = 0x800;
    req.m_buf = (void *)((int)tmp / 0x40 * 0x40 + 0x40);
    reader.func_001BE524(&req, 0);
    BedPfh pfh_head(req.m_buf);
#line 132
    ASSERT_S(pfh_head.getFileOffset(0) == (2048), D_002ED230);
    int fileno = pfh_head.getIndex(theName);
#line 135
    ASSERT(fileno >= 0);
    int filelen = pfh_head.getFileSize(fileno);
#line 139
    ASSERT_S(filelen > 0, D_002ED258);
    int size = (filelen + 0x7FF) / 0x800 * 0x800;
#line 144
    void *p = D_006E9800.alloc(size, ASSERT_FILE, 144, 0, 1);
    ASSERT_S(p != __null, D_002ED268);
    req.m_offset = pfh_head.getFileOffset(fileno);
    req.m_size = size;
    req.m_buf = p;
    req.m_unk20 = 1;
    req.m_unk14 = 0;
    reader.func_001BE524(&req, 0);
    self->m_tex = theTexInfo->loadTM2(D_002ED278, p, 1, -1);
    D_006E9800.free(p);
    return 0;
}


extern "C" void func_0012F790(MagFader *self, DogTexInfo *theTexInfo)
{
#line 168
    ASSERT(theTexInfo);
    if (self->m_tex >= 0) {
        theTexInfo->releaseTex(self->m_tex);
        self->m_tex = -1;
    }
}

