#include "include_asm.h"
#include "spr/sprtexture.h"
#include "mag/magsystem.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"
#include "dog/dogtexinfo.h"
#include "sdk/string.h"
extern "C" {
int func_0018BCC0(MnuRpk *, int);
void func_0018BD94(MnuRpk *);
int func_0018C068(MnuRpk *);
int func_0018C130(MnuRpk *);
int func_0018C190(MnuRpk *, const void *);
void func_0018D7EC(MnuRpk *, int, int, int, const void *, const void *);
void func_0018F1F4(MnuRpk *, int, int, int, int, int, const void *, const void *);
void func_0018F41C(MnuRpk *);
int func_001916C4(S2dMes *);
int func_001916F8(S2dMes *);
int func_00191718(S2dMes *);
int func_0019183C(S2dMes *);
}
void heapFree(void *);
extern "C" {
int func_00190B60(S2dCineSco *arg0);
int func_00190B70(S2dCineSco *arg0, DogTexInfo *arg1);
void func_00190BBC(S2dCineSco *arg0);
int func_00190BFC(S2dCineSco *arg0);
int func_00190C44(S2dCineSco *arg0);
int func_00190C68(S2dCineSco *arg0);
int func_00190C84(S2dCineSco *arg0);
void func_00190D20(S2dCineSco *arg0);
int func_00190D70(S2dCineSco *arg0);
int func_00190D90(S2dCineSco *arg0, int arg1);
int func_00190E98(S2dCineSco *arg0, int arg1);
int func_00191054(S2dBg *arg0);
int func_00191068(S2dBg *arg0, DogTexInfo *arg1);
void func_00191098(S2dBg *arg0);
int func_001910D0(S2dBg *arg0);
int func_00191124(S2dBg *arg0);
int func_00191158(S2dBg *arg0);
int func_00191174(S2dBg *arg0);
void func_00191248(S2dBg *arg0);
int func_00191258(S2dBg *arg0);
int func_00191278(S2dBg *arg0);
int func_001912A0(S2dBg *arg0);
int func_001913C4(S2dBg *arg0, int arg1, const char *arg2);
void func_0019143C(S2dBg *arg0, int arg1, int arg2);
void func_00191478(S2dBg *arg0);
int func_00191588(S2dMes *arg0, DogTexInfo *arg1);
void func_001915F8(S2dMes *arg0);
int func_00191638(S2dMes *arg0);
void func_00191640(S2dMes *arg0);
}
extern int D_00299D20;
extern int D_00299FE0;
extern int D_00299B70;
extern int D_00299B80;
extern char D_0029A180[];
extern MnuRpkEntry D_00299C60[];
extern int D_002999D8;
extern int D_00299B90;
extern int D_00299990;
extern int D_002999B0;
extern const char D_002F7A18[];
extern MnuRpkEntry D_0029A340[];
extern BedMemory D_006E9800;


extern "C" int func_0018F6DC(SprTexture *self, int id)
{
    int n = self->m_indices[id];
    if (n < 0) n = -1;
    return n;
}

extern "C" int func_0018F6F8(SprTexture *self, int id)
{
    int idx = func_0018F6DC(self, id);
    if (idx < 0) return -1;
    return self->m_texIds[idx];
}

extern "C" tag_I3dTexInfo_s *func_0018F734(SprTexture *self, int id)
{
    return self->m_unk30C[id];
}


extern "C" void func_0018F744(SprTexture *self, MnuRpkEntry *entries, const char *packName)
{
    self->m_packName = packName;
    self->m_entries = entries;
    if (entries != 0) {
        entries[0].m_data = 0;
        if (self->m_entries[0].m_id >= 0) {
            int i = 0;
            do {
                i++;
                self->m_entries[i].m_data = 0;
            } while (self->m_entries[i].m_id >= 0);
        }
    }
    if (self->m_packName == 0) {
        self->m_pfh = 0;
        func_001905A0(self, 5);
    } else {
        switch (self->m_loadMode) {
        case 0: func_001905A0(self, 3); break;
        case 1: func_001905A0(self, 1); break;
        }
    }
    self->m_unk124 = 0;
}

extern "C" void func_0018F808(SprTexture *self, MnuRpkEntry *entries, const char *packName, int mode)
{
    self->m_loadMode = mode;
    func_0018F744(self, entries, packName);
}

// NON_MATCHING: 99/103 differ, 4 relocs differ (size 0x19C, game 0x1A8), 57 edits
#ifdef NON_MATCHING
extern "C" void func_0018F824(SprTexture *self)
{
    for (int i = 0; i < self->m_count; i++) {
        int *id = &self->m_texIds[i];
        if (*id > 0) {
            self->m_texInfo->releaseTex(*id);
            *id = 0;
        }
    }
    if (self->m_entries != 0) {
        int i = 0;
        do {
            MnuRpkEntry *entry = &self->m_entries[i];
            if (entry->m_data != 0) {
                int flags = entry->m_flags;
                if (flags & 8) {
                    heapFree(entry->m_data);
                } else {
                    if (!(flags & 4)) heapFree(entry->m_data);
                    else entry->m_flags = flags & ~4;
                    self->m_entries[i].m_flags &= ~8;
                }
                self->m_entries[i].m_data = 0;
            }
        } while (self->m_entries[i++].m_id >= 0);
    }
    for (int i = 0; i < 60; i++) self->m_indices[i] = -1;
    for (int i = 0; i < 60; i++) self->m_unk30C[i] = 0;
    if (self->m_data != 0) {
        heapFree(self->m_data);
        self->m_data = 0;
    }
    self->m_unk124 = 0;
    self->m_count = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018F824);
#endif

// NON_MATCHING: 1/58 differ, 1 edits
#ifdef NON_MATCHING
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_heapFree__FPv(int) asm("heapFree__FPv");
extern "C" int func_0018F9CC(SprTexture *self, int id)
{
    unsigned int i = 0;
    MnuRpkEntry *entry;
    if (self->m_entries[i].m_id < 0) goto fail;
    while (id != self->m_entries[i].m_id) {
        i++;
        if (self->m_entries[i].m_id < 0) goto fail;
    }
    entry = self->m_entries + i;
    if (entry->m_id < 0) {
fail:
        return 0;
    }
    if (entry->m_data != 0) {
        int flags = entry->m_flags;
        if (flags & 8) {
            heapFree(entry->m_data);
        } else if (!(flags & 4)) {
            heapFree(entry->m_data);
        }
        self->m_entries[i].m_data = 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018F9CC);
#endif

extern "C" int func_0018FAB4(SprTexture *self, int id)
{
    int i = 0;
    if (self->m_indices[id] < 0) return 0;
    if (self->m_texIds[self->m_indices[id]] <= 0) return 0;
    while (self->m_entries[i].m_id >= 0 && id != self->m_entries[i].m_id) i++;
    if (self->m_entries[i].m_id < 0) return 0;
    self->m_texInfo->releaseTex(self->m_texIds[self->m_indices[id]]);
    self->m_texIds[self->m_indices[id]] = 0;
    self->m_unk30C[id] = 0;
    return 1;
}

// NON_MATCHING: 166/172 differ, 7 relocs differ (size 0x2B0, game 0x2DC), 38 edits
#ifdef NON_MATCHING
extern "C" int func_0018FBB0(SprTexture *self, int id)
{
    if (self->m_indices[id] < 0 || self->m_texIds[self->m_indices[id]] != 0) return 0;
    int i = 0;
    while (self->m_entries[i].m_id >= 0 && id != self->m_entries[i].m_id) i++;
    if (self->m_entries[i].m_id < 0) return 0;
    if (self->m_entries[i].m_data == 0) {
        if (self->m_pfh == 0) return 0;
        int n = self->m_pfh->getIndex(self->m_entries[i].m_name);
        if (n < 0) return 0;
        self->m_entries[i].m_unk0C = self->m_pfh->getFileSize(n);
        if (self->m_entries[i].m_unk0C < 0) return 0;
        self->m_entries[i].m_data = self->m_pfh->getFileTop(n);
        if (self->m_entries[i].m_data == 0) return 0;
        self->m_entries[i].m_flags &= ~8;
        if (func_001908D0(self, (const RtcmHeader *)self->m_entries[i].m_data) == 1) {
            self->m_entries[i].m_data = func_00190904(self, (const RtcmHeader *)self->m_entries[i].m_data);
            if (self->m_entries[i].m_data == 0) return 0;
            self->m_entries[i].m_flags |= 8;
        }
    }
    self->m_texIds[self->m_indices[id]] = self->m_texInfo->loadTM2(
        self->m_entries[i].m_texName, self->m_entries[i].m_data, 0, 1);
    int *texId = &self->m_texIds[self->m_indices[id]];
    if (*texId <= 0) {
        *texId = 0;
        return 0;
    }
    self->m_unk30C[id] = self->m_texInfo->getTexInfo(*texId);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018FBB0);
#endif

extern "C" int func_0018FE8C(SprTexture *self, const char *name)
{
    if (self->m_pfh == 0) return -1;
    return self->m_pfh->getIndex(name);
}

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F79E0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F79F0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F79F8);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7A18);

// NON_MATCHING: 399/429 differ, 35 relocs differ (size 0x6B4, game 0x6E4), 114 edits
#ifdef NON_MATCHING
extern "C" int func_001BE768(const char *);
extern "C" int func_0018FEBC(SprTexture *self)
{
    int result = 0;
    switch (self->m_state) {
    case 0:
        result = -1;
        break;
    case 1:
    case 3:
        if (self->m_data == 0) {
            self->m_pfh = 0;
            const bool fixedSize = self->m_state == 1;
            self->m_unk0C = fixedSize ? 0x1000 : func_001BE768(self->m_packName);
            self->m_data = D_006E9800.alloc(self->m_unk0C, D_002F7A18,
                fixedSize ? 0x1A9 : 0x1D2, 0, 2);
            if (self->m_data == 0) {
                func_001905A0(self, 0);
            } else {
                func_001905B0(self, self->m_packName, self->m_data, self->m_unk0C, 0);
                func_001905A0(self, 4);
            }
        } else func_001905A0(self, 5);
        break;
    case 2:
    case 4:
        result = func_00190618(self);
        if (result > 0) {
            func_001905A0(self, 5);
            self->m_pfh = &self->m_pack;
            self->m_pfh->setTop(self->m_data);
        } else if (result < 0) func_001905A0(self, 0);
        result = 0;
        break;
    case 5:
    {
        if (self->m_count >= 60) func_001905A0(self, 0);
        MnuRpkEntry *entry = &self->m_entries[self->m_unk124];
        if (entry->m_id < 0 || entry->m_name[0] == 0) func_001905A0(self, 10);
        else if (entry->m_id < 60) func_001905A0(self, 6);
        else func_001905A0(self, 0);
        break;
    }
    case 6:
    {
        if (self->m_entries[self->m_unk124].m_data != 0) {
            heapFree(self->m_entries[self->m_unk124].m_data);
            self->m_entries[self->m_unk124].m_data = 0;
        }
        int n = func_0018FE8C(self, self->m_entries[self->m_unk124].m_name);
        if (n < 0) {
            self->m_entries[self->m_unk124].m_unk0C = func_001BE768(self->m_entries[self->m_unk124].m_name);
            int size = self->m_entries[self->m_unk124].m_unk0C;
            if (size < 0) { func_001905A0(self, 0); break; }
            self->m_entries[self->m_unk124].m_data = D_006E9800.alloc(size, D_002F7A18, 0x21E, 0, 2);
            MnuRpkEntry *entry = &self->m_entries[self->m_unk124];
            if (entry->m_data == 0) { func_001905A0(self, 0); break; }
            func_001905B0(self, entry->m_name, entry->m_data, entry->m_unk0C, 0);
            self->m_entries[self->m_unk124].m_flags &= ~4;
            func_001905A0(self, 7);
            // The first poll happens immediately after starting the read.
            int read = func_00190618(self);
            if (read > 0) func_001905A0(self, 8);
            else if (read < 0) func_001905A0(self, 0);
        } else {
            self->m_entries[self->m_unk124].m_unk0C = self->m_pfh->getFileSize(n);
            MnuRpkEntry *entry = &self->m_entries[self->m_unk124];
            if (entry->m_unk0C < 0) { func_001905A0(self, 0); break; }
            if (self->m_loadMode == 0) {
                entry->m_data = self->m_pfh->getFileTop(n);
                if (self->m_entries[self->m_unk124].m_data == 0) { func_001905A0(self, 0); break; }
                self->m_entries[self->m_unk124].m_flags |= 4;
                func_001905A0(self, 8);
            } else {
                entry->m_data = D_006E9800.alloc(entry->m_unk0C, D_002F7A18, 0x242, 0, 2);
                int offset = self->m_pfh->getFileOffset(n);
                entry = &self->m_entries[self->m_unk124];
                func_001905B0(self, self->m_packName, entry->m_data, entry->m_unk0C, offset);
                self->m_entries[self->m_unk124].m_flags &= ~4;
                func_001905A0(self, 7);
            }
        }
        break;
    }
    case 7:
    {
        int read = func_00190618(self);
        if (read > 0) func_001905A0(self, 8);
        else if (read < 0) func_001905A0(self, 0);
        break;
    }
    case 8:
    {
        MnuRpkEntry *entry = &self->m_entries[self->m_unk124];
        if ((entry->m_flags & 1) && func_001908D0(self, (const RtcmHeader *)entry->m_data) == 1) {
            void *data = func_00190904(self, (const RtcmHeader *)self->m_entries[self->m_unk124].m_data);
            if (!(self->m_entries[self->m_unk124].m_flags & 4)) heapFree(self->m_entries[self->m_unk124].m_data);
            self->m_entries[self->m_unk124].m_data = data;
        }
        self->m_indices[self->m_entries[self->m_unk124].m_id] = self->m_count;
        entry = &self->m_entries[self->m_unk124];
        if (entry->m_flags & 1) func_0018FBB0(self, entry->m_id);
        else if (self->m_loadMode == 0) entry->m_data = 0;
        func_001905A0(self, 9);
        // fall through
    }
    case 9:
        self->m_unk124++;
        self->m_count++;
        func_001905A0(self, 5);
        break;
    case 10:
        result = 1;
        if (self->m_unk418 != 0) self->m_texInfo->func_0011756C(self->m_unk418);
        break;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_0018FEBC);
#endif

extern "C" void func_001905A0(SprTexture *self, int state)
{
    self->m_state = state;
}


extern "C" void func_001905A8(SprTexture *self, int state)
{
    self->m_readState = state;
}


extern "C" int func_001905B0(SprTexture *self, const char *name, void *arg2, unsigned int arg3, int arg4)
{
    strcpy(self->m_filename, name);
    self->m_unk110 = arg2;
    self->m_unk114 = arg3;
    self->m_unk118 = arg4;
    func_001905A8(self, 1);
    return 0;
}

// NON_MATCHING: 86/153 differ, 14 relocs differ (size 0x264, game 0x26C), 38 edits
#ifdef NON_MATCHING
#include "unk/001BE2CC.h"
extern "C" int func_001BE338(FileReader *, const char *);
extern "C" int func_001BE36C(FileReader *, int, void *, unsigned int);
extern "C" int func_001BE3C4(FileReader *, int);
extern "C" int func_001BE444(FileReader *, int, int, int);
extern "C" int func_001BE4C8(FileReader *, int *, int *);
extern "C" int rxGsVSync(int);
extern "C" void func_0017F200(void *);
extern int D_007B2580;
extern "C" int func_00190618(SprTexture *self)
{
    int result = 0;
    switch (self->m_readState) {
    case 0:
        result = -1;
        break;
    case 1:
        self->m_reader = new FileReader;
        func_001905A8(self, 2);
        break;
    case 2:
        if (func_001BE4C8(self->m_reader, self->m_unk404, &self->m_readResult)) func_001905A8(self, 3);
        break;
    case 3:
        if ((int)self->m_unk114 < 0 || func_001BE338(self->m_reader, self->m_filename)) {
            result = -1;
            func_001905A8(self, 0);
        } else func_001905A8(self, 4);
        break;
    case 4:
        if (func_001BE4C8(self->m_reader, self->m_unk404, &self->m_readResult)) {
            int fd = self->m_readResult;
            result = fd < 0 ? fd : 0;
            func_001905A8(self, self->m_unk118 != 0 ? 5 : 7);
        }
        break;
    case 5:
        func_001BE444(self->m_reader, self->m_readResult, self->m_unk118, 0);
        func_001905A8(self, 6);
        break;
    case 6:
        rxGsVSync(1);
        func_0017F200(&D_007B2580);
        if (func_001BE4C8(self->m_reader, self->m_unk404, &self->m_unk404[1])) func_001905A8(self, 7);
        break;
    case 7:
        func_001BE36C(self->m_reader, self->m_readResult, (void *)self->m_unk110, self->m_unk114);
        func_001905A8(self, 8);
        break;
    case 8:
        rxGsVSync(1);
        func_0017F200(&D_007B2580);
        if (func_001BE4C8(self->m_reader, self->m_unk404, &self->m_unk404[1])) func_001905A8(self, 9);
        break;
    case 9:
        func_001BE3C4(self->m_reader, self->m_readResult);
        func_001905A8(self, 10);
        break;
    case 10:
        if (func_001BE4C8(self->m_reader, self->m_unk404, &self->m_unk404[1])) func_001905A8(self, 11);
        break;
    case 11:
        result = 1;
        delete self->m_reader;
        break;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/spr/sprtexture", func_00190618);
#endif

extern "C" int func_00190884(SprTexture *arg0, const unsigned char *arg1, const unsigned char *arg2)
{
    while (*arg1 != 0) {
        if (*arg1 != *arg2) {
            return -1;
        }
        arg1++;
        arg2++;
    }
    return *arg1 != *arg2;
}

extern "C" int func_001908D0(SprTexture *arg0, const RtcmHeader *arg1)
{
    static const char sMagic[16] = "RTCM";
    unsigned int var_v0;

    var_v0 = 0;
    if (arg1 != 0) {
        var_v0 = (unsigned int) ~func_00190884(arg0, (const unsigned char *)sMagic, arg1->m_magic) >> 0x1F;
    }
    return var_v0;
}

extern "C" void *func_00190904(SprTexture *arg0, const RtcmHeader *arg1)
{
    const unsigned char *src = (const unsigned char *)(arg1 + 1);
    unsigned int pos = 0;
    short unitSize;
    unsigned int dataSize;
    unsigned char *buf;
    unsigned char *dst;

    if (func_001908D0(arg0, arg1) == 0) {
        return 0;
    }

    unitSize = arg1->m_unitSize;
    dataSize = arg1->m_fileSize - 0x20;
    buf = (unsigned char *)D_006E9800.alloc(arg1->m_outputSize + unitSize, D_002F7A18, 0x42B, 0, 2);
    if (buf == 0) {
        return 0;
    }

    dst = buf;
    while (pos < dataSize) {
        unsigned char cmd = *src++;
        unsigned int count = *src++ << 16;
        unsigned int j;

        count |= *src++ << 8;
        count |= *src++;
        pos += 4;

        switch (cmd) {
        case 0:
            for (j = 0; j < count; j++) {
                memcpy(dst, src, unitSize);
                dst += unitSize;
            }
            src += unitSize;
            pos += unitSize;
            break;
        case 1:
            for (j = 0; j < count; j++) {
                memcpy(dst, src, unitSize);
                dst += unitSize;
                src += unitSize;
                pos += unitSize;
            }
            break;
        default:
            return 0;
        }
    }
    return buf;
}

S2dCineSco::S2dCineSco()
{
    func_00190B60(this);
}

S2dCineSco::~S2dCineSco()
{
    func_00190C68(this);
    if (m_open == 1) {
        func_00190BBC(this);
    }
}

extern "C" int func_00190B60(S2dCineSco *arg0)
{
    arg0->m_active = 0;
    arg0->m_open = 0;
    return 0;
}

extern "C" int func_00190B70(S2dCineSco *arg0, DogTexInfo *arg1)
{
    func_0018BCC0(&arg0->m_rpk, 3);
    ((SprTexture *)arg0->m_rpk.m_loader)->m_texInfo = arg1;
    func_00190C44(arg0);
    arg0->m_open = 1;
    return 1;
}

extern "C" void func_00190BBC(S2dCineSco *arg0)
{
    if (arg0->m_open != 0) {
        func_0018C130(&arg0->m_rpk);
        func_00190C68(arg0);
        arg0->m_open = 0;
    }
}


extern "C" int func_00190BFC(S2dCineSco *arg0)
{
    return arg0->m_open;
}


void S2dCineSco::live()
{
    func_00190C84(this);
}


void S2dCineSco::render(tag_I3dRenderStage_s *arg1)
{
    if (arg1) {
        MnuRpk *rpk = &this->m_rpk;
        rpk->m_renderCtx = (int)arg1;
        func_0018BD94(rpk);
    }
}

extern "C" int func_00190C44(S2dCineSco *arg0)
{
    if (arg0->m_active == 1) {
        return -1;
    }
    arg0->m_active = 1;
    arg0->m_state = 0;
    return 0;
}

extern "C" int func_00190C68(S2dCineSco *arg0)
{
    if (arg0->m_active == 0) {
        return -1;
    }
    arg0->m_active = 0;
    return 0;
}

extern "C" int func_00190C84(S2dCineSco *arg0)
{
    int var_s0 = 0;
    unsigned int temp_v1;

    if (arg0->m_active == 0) {
        return -1;
    }
    temp_v1 = arg0->m_state;
    switch (temp_v1) {
    case 0:
        arg0->m_state = 3U;
    case 3:
        arg0->m_state = 4U;
        func_00190D20(arg0);
        break;
    case 4:
        func_00190D70(arg0);
        break;
    case 6:
        arg0->m_state = 7U;
    case 1:
    case 2:
    case 5:
    case 7:
    default:
        arg0->m_state = 0U;
        var_s0 = 1;
        break;
    }
    return var_s0;
}

extern "C" void func_00190D20(S2dCineSco *arg0)
{
    MnuRpk *temp_s0;

    temp_s0 = &arg0->m_rpk;
    arg0->m_system = MagSystem::m_current_system;
    temp_s0->m_tbl = &D_002999D8;
    func_0018C190(temp_s0, &D_00299B90);
    temp_s0->m_unk04 = 1;
}

extern "C" int func_00190D70(S2dCineSco *arg0)
{
    func_0018C068(&arg0->m_rpk);
    return 0;
}


extern "C" int func_00190D90(S2dCineSco *arg0, int arg1)
{
    if (arg1 == 0) {
        MnuRpk *sub = &arg0->m_rpk;
        sub->m_sprTbl[1].m_rgba[0] = 0;
        sub->m_sprTbl[1].m_rgba[1] = 0;
        sub->m_sprTbl[1].m_rgba[2] = 0;
        sub->m_sprTbl[1].m_rgba[3] = 0x80;
        sub->m_sprTbl[2].m_rgba[0] = 0;
        sub->m_sprTbl[2].m_rgba[1] = 0;
        sub->m_sprTbl[2].m_rgba[2] = 0;
        sub->m_sprTbl[2].m_rgba[3] = 0x80;
    } else {
        MnuRpk *sub = &arg0->m_rpk;
        func_0018D7EC(sub, 1, 1, arg1, &D_00299B70, &D_00299B80);
        func_0018D7EC(sub, 2, 1, arg1, &D_00299B70, &D_00299B80);
    }
    MnuRpk *sub2 = &arg0->m_rpk;
    sub2->m_sprTbl[1].m_vis0C = 1;
    sub2->m_sprTbl[2].m_vis0C = 1;
    sub2->m_sprTbl[1].m_vis10 = 1;
    sub2->m_sprTbl[2].m_vis10 = 1;
    return 0;
}

extern "C" int func_00190E98(S2dCineSco *arg0, int arg1)
{
    MnuRpk *temp_s2;

    temp_s2 = &arg0->m_rpk;
    if (arg1 == 0) {
        temp_s2->m_sprTbl[1].m_vis0C = 0;
        temp_s2->m_sprTbl[2].m_vis0C = 0;
        temp_s2->m_sprTbl[1].m_vis10 = 0;
        temp_s2->m_sprTbl[2].m_vis10 = 0;
    } else {
        func_0018D7EC(temp_s2, 1, 2, arg1, &D_00299B70, &D_00299B80);
        func_0018D7EC(temp_s2, 2, 2, arg1, &D_00299B70, &D_00299B80);
        int v = 4;
        temp_s2->m_sprTbl[1].m_vis10 = v;
        temp_s2->m_sprTbl[1].m_unk100 = arg1;
        temp_s2->m_sprTbl[2].m_vis10 = v;
        temp_s2->m_sprTbl[2].m_unk100 = arg1;
    }
    return 0;
}

S2dBg::S2dBg()
{
    func_00191054(this);
}

S2dBg::~S2dBg()
{
    func_00191158(this);
    if (m_open == 1) {
        func_00191098(this);
    }
}

extern "C" int func_00191054(S2dBg *arg0)
{
    arg0->m_active = 0;
    arg0->m_open = 0;
    arg0->m_loadState = 0;
    return 0;
}

extern "C" int func_00191068(S2dBg *arg0, DogTexInfo *arg1)
{
    arg0->m_texInfo = arg1;
    func_00191124(arg0);
    arg0->m_open = 1;
    return 1;
}

extern "C" void func_00191098(S2dBg *arg0)
{
    if (arg0->m_open != 0) {
        func_00191158(arg0);
        arg0->m_open = 0;
    }
}


extern "C" int func_001910D0(S2dBg *arg0)
{
    return arg0->m_open;
}


void S2dBg::live()
{
    this->m_unk04 = (int) (this->m_unk04 + 1);
    func_00191174(this);
}

void S2dBg::render(tag_I3dRenderStage_s *arg1)
{
    if (arg1) {
        MnuRpk *rpk = &this->m_rpk;
        rpk->m_renderCtx = (int)arg1;
        func_0018BD94(rpk);
    }
}

extern "C" int func_00191124(S2dBg *arg0)
{
    if (arg0->m_active == 1) {
        return -1;
    }
    arg0->m_active = 1;
    arg0->m_unk3C = 0;
    arg0->m_unk40 = 0;
    arg0->m_unk44 = 2;
    arg0->m_state = 0;
    return 0;
}

extern "C" int func_00191158(S2dBg *arg0)
{
    if (arg0->m_active == 0) {
        return -1;
    }
    arg0->m_active = 0;
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7AC0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7AD0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7AF0);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B00);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B10);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B20);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B30);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B40);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B50);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7B60);

extern "C" int func_00191174(S2dBg *arg0)
{
    int temp_v0;
    int var_s1 = 0;
    unsigned int temp_v1;

    if (arg0->m_active == 0) {
        return -1;
    }
    temp_v1 = arg0->m_state;
    switch (temp_v1) {
    case 0:
        arg0->m_state = 3U;
    case 3:
        arg0->m_state = 4U;
        func_00191248(arg0);
        break;
    case 4:
        if (arg0->m_unk3C == 0) {
            temp_v0 = func_00191278(arg0);
            switch (temp_v0) {
            case 0:
                break;
            case 1:
                arg0->m_state = 6U;
                break;
            }
        }
        func_00191258(arg0);
        break;
    case 6:
        arg0->m_state = 7U;
    case 1:
    case 2:
    case 5:
    case 7:
    default:
        arg0->m_state = 0U;
        var_s1 = 1;
        arg0->m_unk40 = 0;
        break;
    }
    return var_s1;
}




extern "C" void func_00191248(S2dBg *arg0)
{
    arg0->m_system = MagSystem::m_current_system;
}

extern "C" int func_00191258(S2dBg *arg0)
{
    func_001912A0(arg0);
    return 0;
}


extern "C" int func_00191278(S2dBg *arg0)
{
    int v = arg0->m_unk40;

    if (v != 3) {
        if (v < 4) {
            if (v == 0) {
                arg0->m_unk40 = 3;
            }
        }
    }
    return 0;
}

extern "C" int func_001912A0(S2dBg *arg0)
{
    int i;
    unsigned int temp_v1;
    MnuRpk *temp_s1;

    temp_v1 = arg0->m_loadState;
    switch (temp_v1) {
    case 0:
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            D_00299C60[i].m_id = -1;
        }
        arg0->m_loadState = 2U;
        break;
    case 2:
        break;
    case 3:
    {
        func_0018BCC0(&arg0->m_rpk, 7);
        DogTexInfo *val = arg0->m_texInfo;
        SprTexture *sub = (SprTexture *)arg0->m_rpk.m_loader;
        sub->m_texInfo = val;
        func_0018F808(sub, D_00299C60, "data/mnurpk/s2dgen.rpk", 1);
        arg0->m_loadState = 4U;
        break;
    }
    case 4:
        temp_s1 = &arg0->m_rpk;
        if (func_0018FEBC((SprTexture *)arg0->m_rpk.m_loader) != 0) {
            temp_s1->m_tbl = &D_00299D20;
            func_0018C190(temp_s1, &D_00299FE0);
            temp_s1->m_unk04 = 1;
            arg0->m_loadState = 5U;
        }
        break;
    case 5:
    case 6:
        break;
    case 7:
        arg0->m_loadState = 8U;
    case 8:
        func_0018C130(&arg0->m_rpk);
        arg0->m_loadState = 0U;
        break;
    default:
        break;
    }
    func_0018C068(&arg0->m_rpk);
    return 0;
}

extern "C" int func_001913C4(S2dBg *arg0, int arg1, const char *arg2)
{
    if (arg1 >= 7) {
        return -1;
    }
    char *dst = D_0029A180 + arg1 * 0x40;
    *dst = 0;
    strcpy(dst, arg2);
    D_00299C60[arg1].m_id = arg1;
    D_00299C60[arg1 + 1].m_id = -1;
    return 0;
}

extern "C" void func_0019143C(S2dBg *arg0, int arg1, int arg2)
{
    func_0018F1F4(&arg0->m_rpk, arg1, 1, arg2, 0, -1, &D_002999B0, &D_00299990);
}

extern "C" void func_00191478(S2dBg *arg0)
{
    func_0018F41C(&arg0->m_rpk);
}


S2dMes::S2dMes()
{
    m_active = 0;
    func_0019183C(this);
    m_open = 0;
}

S2dMes::~S2dMes()
{
    func_001916F8(this);
    if (m_open == 1) {
        func_001915F8(this);
    }
}

extern "C" int func_00191588(S2dMes *arg0, DogTexInfo *arg1)
{
    func_0018BCC0(&arg0->m_rpk, 0x10);
    ((SprTexture *)arg0->m_rpk.m_loader)->m_texInfo = arg1;
    arg0->m_rpk.m_unk00 = 1;
    func_001916C4(arg0);
    func_00191640(arg0);
    arg0->m_open = 1;
    return 1;
}


extern "C" void func_001915F8(S2dMes *arg0)
{
    if (arg0->m_open != 0) {
        func_0018C130(&arg0->m_rpk);
        func_001916F8(arg0);
        arg0->m_open = 0;
    }
}


extern "C" int func_00191638(S2dMes *arg0)
{
    return arg0->m_open;
}


INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7BD8);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7BE8);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C00);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C10);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C20);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C30);

INCLUDE_RODATA("asm/nonmatchings/spr/sprtexture", D_002F7C40);

extern "C" void func_00191640(S2dMes *arg0)
{
    SprTexture *temp_s0;

    temp_s0 = (SprTexture *)arg0->m_rpk.m_loader;
    func_0018F744(temp_s0, D_0029A340, "data/mnurpk/s2dman.rpk");
    do {

    } while (func_0018FEBC(temp_s0) == 0);
}

void S2dMes::live()
{
    func_00191718(this);
}


void S2dMes::render(tag_I3dRenderStage_s *arg1)
{
    if (arg1) {
        MnuRpk *rpk = &this->m_rpk;
        rpk->m_renderCtx = (int)arg1;
        func_0018BD94(rpk);
    }
}
