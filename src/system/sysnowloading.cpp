#include "include_asm.h"
#include "sysnowloading.h"
#include "game/gamman.h"
#include "sdk/stdlib.h"
#include "sdk/string.h"
extern "C" int loadingA7_func_001C6CCC(...) asm("func_001C6CCC");
extern "C" int loadingA7_func_001C6FE0(...) asm("func_001C6FE0");
extern "C" int loadingA7_func_001C7DA8(...) asm("func_001C7DA8");
extern "C" int loadingA7_func_001C98C0(...) asm("func_001C98C0");
extern "C" int loadingA7_func_001CAA14(...) asm("func_001CAA14");
extern "C" int loadingA7_func_001CABD4(...) asm("func_001CABD4");
extern "C" int loadingA7_func_001CC044(...) asm("func_001CC044");
extern "C" int loadingA7_func_001CC970(...) asm("func_001CC970");
extern "C" int loadingA7_func_001CEA44(...) asm("func_001CEA44");
extern "C" int loadingA7_func_001D1C80(...) asm("func_001D1C80");
extern "C" int loadingA7_func_001D2D00(...) asm("func_001D2D00");
extern "C" int loadingA7_func_001D2D7C(...) asm("func_001D2D7C");
extern "C" int loadingA7_func_001DB520(...) asm("func_001DB520");
extern "C" int loadingA7_func_001DBA3C(...) asm("func_001DBA3C");
extern "C" int loadingA7_func_001DC48C(...) asm("func_001DC48C");
extern "C" float Xf_func_0010FBD4__9DogCamera(...) asm("func_0010FBD4__9DogCamera");
extern "C" void loadingSetCamera(int, float) asm("func_0010FC08__9DogCameraf");
extern "C" void loadingSetTime(int, float) asm("func_0013D240");
extern "C" int X_func_001C5FFC(...) asm("func_001C5FFC");
extern "C" int X_func_001C621C(...) asm("func_001C621C");
extern "C" int X_func_001C7210(...) asm("func_001C7210");
extern "C" int X_func_001CBE38(...) asm("func_001CBE38");
extern "C" int loadingRemoveTask(...) asm("func_001E7724");
extern "C" int X_func_001FBC0C(...) asm("func_001FBC0C");
extern "C" int X_normalizeRot__9DogEntity(...) asm("normalizeRot__9DogEntity");
extern "C" int X_func_001C53E0(...) asm("func_001C53E0");
extern "C" int X_func_001C65E8(...) asm("func_001C65E8");
extern "C" int X_func_001C6A40(...) asm("func_001C6A40");
extern "C" int X_func_001C6F08(...) asm("func_001C6F08");
extern "C" int X_func_001CB24C(...) asm("func_001CB24C");
extern "C" int X_func_001CB384(...) asm("func_001CB384");
extern "C" int X_func_001CB424(...) asm("func_001CB424");
extern int D_007A3208;
extern int D_007A320C;
extern int D_007A3210;
extern int D_007A3350;
extern int D_007A3354;
extern int D_007B205C;
extern int D_007B2060;
extern "C" int X_func_00131184(...) asm("func_00131184");
extern "C" int X_func_001311BC(...) asm("func_001311BC");
extern "C" int X_func_00131550(...) asm("func_00131550");
extern "C" int X_func_00131608(...) asm("func_00131608");
extern "C" int X_func_00190D90(...) asm("func_00190D90");
extern "C" int X_func_00190E98(...) asm("func_00190E98");
extern "C" void loadingSetValue(int, int) asm("func_001D3A38");
extern int D_006E9840;
extern int D_006FBD80;
extern "C" int X_func_001CC044(...) asm("func_001CC044");
extern "C" int X_func_001CC250(...) asm("func_001CC250");
extern "C" int X_func_001DC48C(...) asm("func_001DC48C");
extern "C" int X_func_002120AC(...) asm("func_002120AC");
extern "C" int X_func_00212920(...) asm("func_00212920");
extern "C" int X_func_002129B8(...) asm("func_002129B8");
extern "C" int X_func_00212A5C(...) asm("func_00212A5C");
extern "C" int X_func_00212D08(...) asm("func_00212D08");
extern "C" int X_func_00212E64(...) asm("func_00212E64");
extern int D_002D9900;
extern "C" int X___builtin_new(...) asm("__builtin_new");
extern "C" int X_func_001CF6BC(...) asm("func_001CF6BC");
extern "C" int X_func_001CF854(...) asm("func_001CF854");
extern "C" int X_func_001CFA5C(...) asm("func_001CFA5C");
extern "C" int X_func_001E71FC(...) asm("func_001E71FC");
extern "C" int X_func_001E7D7C(...) asm("func_001E7D7C");
extern "C" int X_func_001F184C(...) asm("func_001F184C");
extern int D_007A3580;
extern int D_007A3898;
extern int D_007A3D80;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" void *X_alloc__9BedMemoryiPCciii(void *, int, const char *, int, int, int) asm("alloc__9BedMemoryiPCciii");
extern "C" void X_free__9BedMemoryPv(void *, void *) asm("free__9BedMemoryPv");
extern "C" void X_func_00117F80__9MagSystemiiiiiii(...) asm("func_00117F80__9MagSystemiiiiiii");
extern "C" void X_func_0013F980__8MagSceneiiiPfi(void *, int, int, int, float *, int) asm("func_0013F980__8MagSceneiiiPfi");
extern "C" int X_func_00144AE0(...) asm("func_00144AE0");
extern "C" int X_func_001C541C(...) asm("func_001C541C");
extern "C" int X_func_001D2724(...) asm("func_001D2724");
extern const float D_002FF8F0[4];
extern const float D_002FF900[4];
extern int D_007A3294;
extern "C" int X_func_00162AFC(...) asm("func_00162AFC");
extern "C" int X_func_0016366C(...) asm("func_0016366C");
extern "C" int X_func_00163B20(...) asm("func_00163B20");
extern "C" int X_func_00163B48(...) asm("func_00163B48");
extern "C" int X_func_00163B80(...) asm("func_00163B80");
extern "C" int X_func_00163BB8(...) asm("func_00163BB8");
extern "C" int X_func_00164078(...) asm("func_00164078");
extern "C" int X_func_001C143C(...) asm("func_001C143C");
extern "C" int X_func_001C4F70(...) asm("func_001C4F70");
extern "C" int X_func_001C5A5C(...) asm("func_001C5A5C");
extern "C" int X_func_001CB01C(...) asm("func_001CB01C");
extern "C" int X_func_001CCC30(...) asm("func_001CCC30");
extern "C" int X_func_001CF7D0(...) asm("func_001CF7D0");
extern "C" int X_func_001CF95C(...) asm("func_001CF95C");
extern "C" int rand(void);
extern "C" void func_00204A00();
extern "C" int X_func_0020F140(...) asm("func_0020F140");
extern "C" int X_func_0020F1A8(...) asm("func_0020F1A8");
extern "C" int X_func_002113A4(...) asm("func_002113A4");
extern "C" int X_func_0025A9D0(sceGsDrawEnv1 *, int, int, int) asm("func_0025A9D0");
extern const char D_002FF8D0[];
extern const unsigned int D_002FF8C0[4];
extern void *D_002D90A8[];
extern int D_002D90E8;
extern int D_006E9800;
extern int D_00725410;
extern GamMan D_007812C0;
extern int D_007A4440;
extern int D_007B2140;
extern int D_007B2294;

extern "C" void func_00204BF8()
{
    int i;

    if (D_002D90E8 != 0) {
        return;
    }
    D_002D90E8 = 1;
    for (i = 1; i < 8; i++) {
        D_002D90A8[i] = SetDebugHandler(i, (void *)func_00204A00);
    }
    for (i = 10; i < 14; i++) {
        D_002D90A8[i] = SetDebugHandler(i, (void *)func_00204A00);
    }
}

extern "C" void func_00204CA4()
{
    int i;

    if (D_002D90E8 == 0) {
        return;
    }
    D_002D90E8 = 0;
    for (i = 1; i < 8; i++) {
        SetDebugHandler(i, D_002D90A8[i]);
    }
    for (i = 10; i < 14; i++) {
        SetDebugHandler(i, D_002D90A8[i]);
    }
}

struct SysNowLoadTex64K {
    unsigned long m_d[0x2000];
};

extern "C" void func_00204D38(SysNowLoading *self)
{
    char path[32] = "cdrom0:\\DATA\\CMNTEX\\LOADING.BIN";
    sceGsLoadImage img;
    int fd;
    register unsigned char *tex PS2_REG("$16");

    fd = sceOpen(path, 1);
    sceRead(fd, self->m_texBuf, 0x20000);
    sceClose(fd);

    *(SysNowLoadTex64K *)self->m_texBuf = *(SysNowLoadTex64K *)self->m_texBuf;

    tex = (unsigned char *)self->m_texBuf;
    sceGsSetDefLoadImage(&img, 0x1F40, 1, 0, 0, 0, 16, 16);
    tex += 0x10000;
    FlushCache(0);
    sceGsExecLoadImage(&img, tex);
    sceGsSyncPath(0, 0);
}

extern "C" void func_00204E68(SysNowLoading *self, unsigned int *dst, float u, float v)
{
    dst[0] = *(unsigned int *)&u;
    dst[1] = *(unsigned int *)&v;
    dst[2] = 0x3F800000;
    dst[3] = 0;
}

extern "C" void func_00204E98(SysNowLoading *self, int idx);
// NON_MATCHING: 86/121 differ, 2 relocs differ (size 0x1E4, game 0x1E0), 66 edits
#ifdef NON_MATCHING
#ifdef TARGET_PS2
static inline void zeroQuad(void *p) { *(u_long128 *)p = 0; }
#else
static inline void zeroQuad(void *p) { u_long128 z = {{0, 0, 0, 0}}; *(u_long128 *)p = z; }
#endif

static inline void setDmaTag(void *p, unsigned int tag)
{
    zeroQuad(p);
    *(unsigned int *)p = tag;
}

static inline void setGifAD(void *p, unsigned long addr, unsigned long val)
{
    unsigned long *q = (unsigned long *)p;
    q[1] = addr;
    q[0] = val;
}

static inline void setXYZ2(void *p, unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int *q = (unsigned int *)p;
    q[0] = x;
    q[1] = y;
    q[2] = z;
    q[3] = 0;
}

extern "C" void func_00204E98(SysNowLoading *self, int idx)
{
    SysNowLoadQuad col = *(const SysNowLoadQuad *)D_002FF8C0;
    SysNowLoadQuad *p = (SysNowLoadQuad *)self->m_dmaBuf;

    setDmaTag(p + 0, 0x1000000D);
    setGifAD(p + 1, 0xE, 0x1000000000000005ULL);
    setGifAD(p + 2, 0x3F, 0);
    setGifAD(p + 4, 0x6, 0x2003E80E21311A40ULL);
    setGifAD(p + 5, 0x14, 0x60);
    setGifAD(p + 6, 0x8, 0x5);
    setGifAD(p + 7, 0x412412, 0x600B400000008001ULL);

    func_00204E68(self, p[8].m_w, 0.0f, (float)idx * 0.25f);
    *(u_long128 *)&p[9] = *(u_long128 *)&col;
    setXYZ2(p + 10, 0x8200, 0x8980, 0x10);

    func_00204E68(self, p[11].m_w, 1.0f, (float)(idx + 1) * 0.25f);
    *(u_long128 *)&p[12] = *(u_long128 *)&col;
    setXYZ2(p + 13, 0x8E00, 0x8C80, 0x10);

    setDmaTag(p + 14, 0x70000000);
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00204E98);
#endif

extern "C" void func_00205078(SysNowLoading *self)
{
    sceGsLoadImage *img = &self->m_loadImage;

    sceGsSetDefLoadImage(img, 0x1A40, 4, 0x13, 0, 0, 0x100, 0x100);
    FlushCache(0);
    sceGsExecLoadImage(img, self->m_texBuf);
    sceGsSyncPath(0, 0);
}

extern "C" void func_002050E8(SysNowLoading *self)
{
    void *buf;
    unsigned int i;

    buf = X_alloc__9BedMemoryiPCciii(&D_006E9800, 0x100000, D_002FF8D0, 0xF6, 0, 2);
    memset(buf, 0, 0x100000);
    for (i = 0; i < 16; i++) {
        sceGsSetDefLoadImage(&self->m_loadImage, (short)(i << 10), 4, 0, 0, 0, 0x100, 0x100);
        FlushCache(0);
        sceGsExecLoadImage(&self->m_loadImage, buf);
        sceGsSyncPath(0, 0);
    }
    X_free__9BedMemoryPv(&D_006E9800, buf);
}

extern "C" void func_002051CC(SysNowLoading *self)
{
    int odd;

    func_00205078(self);
    odd = (sceGsSyncV(0) == 0);
    X_func_0025A9D0((self->m_frame & 1) ? &self->m_dbuff.draw1 : &self->m_dbuff.draw0,
                    0x800, 0x800, odd);
    FlushCache(0);
    sceGsSwapDBuff(&self->m_dbuff, self->m_frame & 1);
    sceGsSyncPath(0, 0);
    FlushCache(0);
    sceDmaSend(self->m_dmaChan, self->m_dmaBuf);
    self->m_frame++;
    sceGsSyncPath(0, 0);
    if ((self->m_frame % 8) == 0) {
        func_00204E98(self, (self->m_frame / 8) % 4);
    }
}

extern "C" void func_002052AC(SysNowLoading *self)
{
    self->m_texBuf = X_alloc__9BedMemoryiPCciii(&D_006E9800, 0x100000, D_002FF8D0, 0x130, 0, 2);
    self->m_dmaBuf = X_alloc__9BedMemoryiPCciii(&D_006E9800, 0x4000, D_002FF8D0, 0x131, 0, 2);
    self->m_dmaChan = sceDmaGetChan(2);
    sceGsSetDefDBuff(&self->m_dbuff, 0, 0x200, 0x1C0, 2, 0x3A, 1);
    *(unsigned long *)&self->m_dbuff.clear0.rgbaq = 0x3F80000000000000ULL;
    *(unsigned long *)&self->m_dbuff.clear1.rgbaq = 0x3F80000000000000ULL;
    func_00204E98(self, 0);
    func_002050E8(self);
    func_00204D38(self);
    *T0_MODE = 0x83;
}

extern "C" void func_00205394(SysNowLoading *self)
{
    void *texBuf;
    void *dmaBuf;

    func_002050E8(self);
    texBuf = self->m_texBuf;
    if (texBuf != 0) {
        X_free__9BedMemoryPv(&D_006E9800, texBuf);
        self->m_texBuf = 0;
    }
    dmaBuf = self->m_dmaBuf;
    if (dmaBuf != 0) {
        X_free__9BedMemoryPv(&D_006E9800, dmaBuf);
        self->m_dmaBuf = 0;
    }
}


extern "C" int func_002053F4()
{
    X_func_002113A4((int)&D_007A4440);
    return 0xCCCCCCCE;
}


extern "C" int func_0020541C()
{
    X_func_0020F1A8((int)&D_007A4440);
    X_func_001C143C((int)&D_007812C0);
    return 0;
}


struct SysNowLoadVec4 {
    float m_v[4];
};

extern "C" int func_0020544C()
{
    char *scene = (char *)&D_006FBD80;
    float c0[4];
    float c1[4];

    *(int *)(scene + 0x22B4) = 0;
    memcpy(c0, D_002FF8F0, sizeof(c0));
    memcpy(c1, D_002FF900, sizeof(c1));
    X_func_00117F80__9MagSystemiiiiiii((int)&D_006E9840, 1, 1, 1, 1, 1, 1, 0);
    X_func_0013F980__8MagSceneiiiPfi(scene, 0, 0, 2, c0, 0);
    X_func_0013F980__8MagSceneiiiPfi(scene, 1, 0, 1, c1, 0);
    X_func_0013F980__8MagSceneiiiPfi(scene, 1, 0, 2, c0, 0);
    X_func_001D2724((int)&D_007812C0, 1, 0);
    return 0;
}

extern "C" int func_00205564()
{
    return 0xCCCCCCCD;
}


INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_002FF8C0);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_002FF8D0);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_002FF8F0);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_002FF900);

// NON_MATCHING: 139/224 differ, 37 relocs differ, 41 edits
#ifdef NON_MATCHING
extern int loadingTask asm("D_007A3574");
extern "C" int X_func_0010A834__8DogActor(...) asm("func_0010A834__8DogActor");
extern "C" int X_func_001330F4(...) asm("func_001330F4");
extern "C" int X_func_0013F444(...) asm("func_0013F444");
extern "C" int X_func_001CB1C0(...) asm("func_001CB1C0");
extern "C" int X_func_001CF9D4(...) asm("func_001CF9D4");
extern "C" int X_func_001D046C(...) asm("func_001D046C");
extern "C" int X_func_001D1A48(...) asm("func_001D1A48");
extern "C" int X_func_001D1C80(...) asm("func_001D1C80");
extern "C" int X_func_001D2B8C(...) asm("func_001D2B8C");
extern "C" int X_func_00211318(...) asm("func_00211318");
extern "C" int X_func_00213D00(...) asm("func_00213D00");
extern "C" int X_func_00213E78(...) asm("func_00213E78");
extern int D_006FE6A0;
extern int D_00781280;
extern int D_007A353C;
extern int D_007A3564;
extern int D_007A356C;
extern int D_007A3578;
extern int D_007A357C;
extern "C" int func_00205570(unsigned int arg0, unsigned int arg1, int arg2)
{
    struct { int sp0; } stack;
    int base;
    register int base4 PS2_REG("$4");
    int id;
    int pad;
    int temp_a0;
    int temp_v1;
    int var_v0;
    int var_v0_2;
    int var_v0_3;

    switch (arg0) {
    case 0:
        var_v0 = 0;
        if (arg1 != 0) {
            return (X_func_00211318((int)&D_007A4440, arg1) == 0) ? 0 : 0xCCCCCCCC;
        }
        return var_v0;
    case 1:
        return (X_func_001CB1C0((int)&D_007812C0) == 0) ? 0 : 0xCCCCCCCC;
    case 2:
        base = (int)&D_007812C0;
        var_v0 = X_func_001D046C(base, arg1);
        if (var_v0 != 0) {
            id = X_func_001CBE38(base, arg1);
            base4 = (int)&D_006E9840;
            return ((X_func_001330F4(base4 + 0x12540, id) ^ arg2) != 0) ? 0 : 0xCCCCCCCC;
        }
        
        return var_v0;
    case 3:
        X_func_001D1C80((int)&D_007812C0, arg1, (int) 0x19, (int)&stack);
        return (X_func_001E7D7C((int)&D_007A3D80, stack.sp0) == 0) ? 0 : 0xCCCCCCCC;
    case 4:
        return (X_func_00213D00((int)&D_007A4440, arg1, 0) == 0) ? 0 : 0xCCCCCCCC;
    case 5:
        base = (int)&D_007812C0;
        var_v0 = X_func_001D046C(base, arg1);
        if (var_v0 != 0) {
            return (~M2C_FIELD(X_func_001D2B8C(base, arg1), int *, 0x3E0) == 0) ? 0 : 0xCCCCCCCC;
        }
        
        return var_v0;
    case 6:
        if (X_func_00211318((int)&D_007A4440, 0x11U) == 0) {
            return (X_func_001D1A48((int)&D_007812C0) == 0) ? 0 : 0xCCCCCCCC;
        }
        return 0xCCCCCCCC;
    case 7:
        return (X_func_001CF9D4((int)&D_007812C0) == 0) ? 0 : 0xCCCCCCCC;
    case 8:
        return (X_func_001E7D7C((int)&D_007A3D80, (*(int *)&D_007A356C)) == 0) ? 0 : 0xCCCCCCCC;
    case 9:
        pad = D_00781280;
        if (arg1 < 0x11U) {
            temp_a0 = 1 << arg1;
            return (((M2C_FIELD(pad, unsigned short *, 0x78) & temp_a0) ^ temp_a0) == 0) ? 0 : 0xCCCCCCCC;
        }
        temp_v1 = 1 << (arg1 - 0x10);
        return (((M2C_FIELD(pad, unsigned short *, 0x7A) & temp_v1) ^ temp_v1) == 0) ? 0 : 0xCCCCCCCC;
    case 10:
        return (X_func_001E7D7C((int)&D_007A3D80, (*(int *)&D_007A3564)) == 0) ? 0 : 0xCCCCCCCC;
    case 11:
        return (X_func_001E7D7C((int)&D_007A3D80, (*(int *)&loadingTask)) == 0) ? 0 : 0xCCCCCCCC;
    case 12:
        base = (int)&D_007812C0;
        var_v0 = X_func_001D046C(base, arg1);
        if (var_v0 != 0) {
            return (~M2C_FIELD(X_func_001D2B8C(base, arg1), int *, 0x3D8) == 0) ? 0 : 0xCCCCCCCC;
        }
        
        return var_v0;
    case 13:
        return (X_func_001E7D7C((int)&D_007A3D80, (*(int *)&D_007A3578)) == 0) ? 0 : 0xCCCCCCCC;
    case 14:
        return (X_func_001E7D7C((int)&D_007A3D80, (*(int *)&D_007A357C)) == 0) ? 0 : 0xCCCCCCCC;
    case 15:
        base4 = (int)&D_006E9840;
        return (X_func_0013F444(base4 + 0x12540, (*(int *)((int)&D_007A353C))) == 0) ? 0 : 0xCCCCCCCC;
    case 16:
        return (X_func_00213E78((int)&D_007A4440, arg1) == 0) ? 0 : 0xCCCCCCCC;
    case 17:
        base = (int)&D_007812C0;
        var_v0 = X_func_001D046C(base, arg1);
        if (var_v0 != 0) {
            return (X_func_0010A834__8DogActor((int)&D_006FE6A0 + (X_func_001CBE38(base, arg1) * 0x4D0)) == 0) ? 0 : 0xCCCCCCCC;
        }
        
        return var_v0;
    case 18:
        return (M2C_FIELD((*(int *)&D_007B2060), int *, 4) & 0x40000000) ? 0 : 0xCCCCCCCC;
    default:
        var_v0 = 0;
        
        return var_v0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00205570);
#endif

extern "C" unsigned int func_002058F0(int arg0, unsigned int arg1)
{
    unsigned int mod = (arg1 != 0) ? arg1 : 1;
    return (unsigned int)rand() % mod;
}

extern "C" int func_00205928(int arg0, int arg1, int arg2)
{
    int temp_v0;
    int base;
    int var_a0;
    int var_v1;

    switch (arg0) {
    case 1:
        var_a0 = 0;
        var_v1 = arg1;
        while (*(unsigned char *)var_v1++ && var_a0++ < 0x200) {}
        if (var_a0 >= 0x1FE) {
            M2C_FIELD(var_v1, signed char *, 0) = 0;
            M2C_FIELD(var_v1, unsigned char *, 1) = 0;
        }
        X_func_001CF854((int)&D_007812C0, arg1, 0, 0xB4);
        break;
    case 2:
        X_func_001CF854((int)&D_007812C0, arg1, arg2, 0xB4);
        break;
    case 3:
        X_func_001CFA5C((int)&D_007812C0, arg1, -1, -1, -1, -1);
        break;
    case 4:
        (*(int *)((int)&D_007A3898)) = arg1;
        break;
    case 5:
        X_func_001CF854((int)&D_007812C0, arg1, 0, arg2);
        break;
    case 10:
        X_func_001CF6BC((int)&D_007812C0, 1, arg1);
        break;
    case 11:
        X_func_001CF6BC((int)&D_007812C0, 0, arg1);
        break;
    case 20:
        base = (int)&D_007812C0;
        M2C_FIELD(base, int *, 0x21F4C) = (int) (M2C_FIELD(base, int *, 0x21F4C) | 0x80000);
        temp_v0 = X___builtin_new(0x80);
        X_func_001F184C(temp_v0, 0x15, 0, 0);
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0, 0, base + 0x222C0, 0x11);
        break;
    case 21:
        return (X_func_001E7D7C((int)&D_007A3D80, (*(int *)((int)&D_007A3580))) == 0) ? 0 : 0xCCCCCCCC;
    }
    return 0;
}

extern "C" int func_00205B18(int arg0)
{
    if (arg0 == 1) {
        X_func_001CF7D0((int)&D_007812C0);
    }
    return 0;
}


extern "C" int func_00205B44(int arg0)
{
    if (arg0 == 1) {
        X_func_001CF95C((int)&D_007812C0);
    }
    return 0;
}


extern "C" int func_00205B70()
{
    return 0;
}


extern "C" int func_00205B78()
{
    return 0;
}


extern "C" int func_00205B80()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00205B88);

extern "C" int func_0020660C()
{
    return 0;
}


extern "C" int func_00206614(int arg0, int arg1)
{
    switch (arg0) {
    case 0:
        break;
    case 1:
        D_00725410 = (arg1 == 0);
        break;
    }
    return 0;
}

extern "C" int func_00206638()
{
    return 0;
}


extern "C" int func_00206640(unsigned int arg0, int arg1, int arg2)
{
    float var_f12;
    register int base4 PS2_REG("$4");
    register int base11 PS2_REG("$11");
    int *field;
    int temp_v0_4;
    int var_a2;
    register int temp_s0 PS2_REG("$16");
    register int temp_v0 PS2_REG("$2");
    register int temp_v0_2 PS2_REG("$2");
    register int temp_v0_3 PS2_REG("$2");

    switch (arg0) {
    case 0x1:
        temp_v0 = (int)&D_006FBD80;
        temp_v0 += 0x2AB70;
        M2C_FIELD(temp_v0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0);
        M2C_FIELD(temp_v0, float *, 0x44) = (float) M2C_FIELD(arg1, float *, 4);
        M2C_FIELD(temp_v0, float *, 0x48) = (float) M2C_FIELD(arg1, float *, 8);
        M2C_FIELD(temp_v0, int *, 0x90) = 1;
        break;
    case 0x2:
        temp_s0 = (int)&D_006FBD80;
        temp_s0 += 0x2AB70;
        M2C_FIELD(temp_s0, float *, 0x50) = (float) M2C_FIELD(arg1, float *, 0);
        M2C_FIELD(temp_s0, float *, 0x54) = (float) M2C_FIELD(arg1, float *, 4);
        M2C_FIELD(temp_s0, float *, 0x58) = (float) M2C_FIELD(arg1, float *, 8);
        X_normalizeRot__9DogEntity(temp_s0);
        M2C_FIELD(temp_s0, int *, 0x90) = 1;
        break;
    case 0x3:
        temp_v0_2 = (int)&D_006FBD80;
        temp_v0_2 += 0x2AB70;
        M2C_FIELD(arg1, float *, 0) = (float) M2C_FIELD(temp_v0_2, float *, 0x40);
        M2C_FIELD(arg1, float *, 4) = (float) M2C_FIELD(temp_v0_2, float *, 0x44);
        M2C_FIELD(arg1, float *, 8) = (float) M2C_FIELD(temp_v0_2, float *, 0x48);
        break;
    case 0x4:
        temp_v0_3 = (int)&D_006FBD80;
        temp_v0_3 += 0x2AB70;
        M2C_FIELD(arg1, float *, 0) = (float) M2C_FIELD(temp_v0_3, float *, 0x50);
        M2C_FIELD(arg1, float *, 4) = (float) M2C_FIELD(temp_v0_3, float *, 0x54);
        M2C_FIELD(arg1, float *, 8) = (float) M2C_FIELD(temp_v0_3, float *, 0x58);
        break;
    case 0x5:
        base4 = (int)&D_006FBD80;
        loadingSetCamera(base4 + 0x2AB70, M2C_FIELD(arg1, float *, 0));
        break;
    case 0x6:
        base4 = (int)&D_006FBD80;
        M2C_FIELD(arg1, float *, 0) = Xf_func_0010FBD4__9DogCamera(base4 + 0x2AB70);
        break;
    case 0x7:
        if (!((*(int *)&D_007A3208) & 0x20000)) {
            var_f12 = (float)(unsigned int)arg1;
            base4 = (int)&D_006E9840;
            loadingSetTime(base4 + 0x12540, var_f12);
        }
        break;
    case 0x8:
        temp_s0 = (int)&D_007812C0;
        M2C_FIELD(temp_s0, int *, 0x21F70) = X_func_001CBE38(temp_s0, (unsigned int) arg1);
        break;
    case 0xA:
        var_a2 = 0;
        X_func_001C7210((int)&D_007812C0, arg1, var_a2, 0);
        break;
    case 0xB:
        var_a2 = arg2 & 0xFFFF;
        X_func_001C7210((int)&D_007812C0, arg1, var_a2, 0);
        break;
    case 0x14:
        X_func_001C5FFC((int)&D_007812C0);
        break;
    case 0x15:
        X_func_001C621C((int)&D_007812C0);
        break;
    case 0x32:
        temp_v0_4 = X___builtin_new(0xC0);
        X_func_001FBC0C(temp_v0_4, arg2, arg1);
        base11 = (int)&D_007812C0;
        base11 += 0x222B8;
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_4, 0, base11, 0x11);
        break;
    case 0x33:
        temp_v0 = (int)&D_007812C0;
        field = (int *)(temp_v0 + 0x222B8);
        if (X_func_001E7D7C((int)&D_007A3D80, *field) != 0) {
            loadingRemoveTask((int)&D_007A3D80, *field);
            *field = -1;
        }
        break;
    case 0: default: break;
    }
    return 0;
}

extern "C" int func_00206944()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020694C);

// NON_MATCHING: 165/265 differ, 2 relocs differ (size 0x424, game 0x41C), 49 edits
#ifdef NON_MATCHING
extern "C" void loadingGetStick(int, float *, float *) asm("getStick__C6BedPadPfT1");
extern "C" float loadingRightX(int) asm("getRightX__C6BedPad");
extern "C" float loadingRightY(int) asm("getRightY__C6BedPad");
inline unsigned short loadingPadBit(unsigned short value, int bit) { return (value >> bit) & 1; }
extern "C" unsigned int func_002076CC(unsigned int arg0, int arg1, int *arg2)
{
    float x, y;
    unsigned int result;
    unsigned short buttonBits;
    unsigned int fullBits;
    bool condition;
    register unsigned int bits PS2_REG("$3");
    register float f0 PS2_REG("$f0");
    register float f1 PS2_REG("$f1");
    register float f2 PS2_REG("$f2");
    register int base PS2_REG("$2") = (int)&D_006E9840;
    int *padSlot = (int *)(base + 0x97A40);
    loadingGetStick(*padSlot, &x, &y);
    int pad = *padSlot;
    int state = M2C_FIELD(pad, int *, 0x70);
    switch (arg0) {
    case 0: return (M2C_FIELD(pad, unsigned short *, 120) >> 0) & 1;
    case 1: return (M2C_FIELD(pad, unsigned short *, 120) >> 1) & 1;
    case 2: return (M2C_FIELD(pad, unsigned short *, 120) >> 2) & 1;
    case 3: return (M2C_FIELD(pad, unsigned short *, 120) >> 3) & 1;
    case 8: return (M2C_FIELD(pad, unsigned short *, 120) >> 8) & 1;
    case 9: return (M2C_FIELD(pad, unsigned short *, 120) >> 9) & 1;
    case 10: return (M2C_FIELD(pad, unsigned short *, 120) >> 10) & 1;
    case 11: return (M2C_FIELD(pad, unsigned short *, 120) >> 11) & 1;
    case 12: return (M2C_FIELD(pad, unsigned short *, 120) >> 12) & 1;
    case 13: return (M2C_FIELD(pad, unsigned short *, 120) >> 14) & 1;
    case 14: return (M2C_FIELD(pad, unsigned short *, 120) >> 13) & 1;
    case 15: return (M2C_FIELD(pad, unsigned short *, 120) >> 15) & 1;
    case 16: return (M2C_FIELD(pad, unsigned short *, 124) >> 0) & 1;
    case 17: return (M2C_FIELD(pad, unsigned short *, 124) >> 1) & 1;
    case 18: return (M2C_FIELD(pad, unsigned short *, 124) >> 2) & 1;
    case 19: return (M2C_FIELD(pad, unsigned short *, 124) >> 3) & 1;
    case 24: return (M2C_FIELD(pad, unsigned short *, 124) >> 8) & 1;
    case 25: return (M2C_FIELD(pad, unsigned short *, 124) >> 9) & 1;
    case 26: return (M2C_FIELD(pad, unsigned short *, 124) >> 10) & 1;
    case 27: return (M2C_FIELD(pad, unsigned short *, 124) >> 11) & 1;
    case 28: return (M2C_FIELD(pad, unsigned short *, 124) >> 12) & 1;
    case 29: return (M2C_FIELD(pad, unsigned short *, 124) >> 14) & 1;
    case 30: return (M2C_FIELD(pad, unsigned short *, 124) >> 13) & 1;
    case 31: return (M2C_FIELD(pad, unsigned short *, 124) >> 15) & 1;
    case 4: f1 = x; goto negative;
    case 5: condition = y > 0.5f; goto conditionCheck;
    case 6: condition = x > 0.5f; goto conditionCheck;
    case 7: f1 = y;
negative:
        condition = f1 < -0.5f;
conditionCheck:
        result = 1;
        if (condition) return result;
        result = 0;
        break;
    case 20: return (state >> 4) & 1;
    case 21: return (state >> 5) & 1;
    case 22: return (state >> 6) & 1;
    case 23: return (state >> 7) & 1;
    case 64: return (M2C_FIELD(pad, unsigned short *, 0x78) & arg1) == arg1;
    case 65: return (M2C_FIELD(pad, unsigned short *, 0x7A) & arg1) == arg1;
    case 66:
        buttonBits = M2C_FIELD(pad, unsigned short *, 0x78);
        result = 1;
        if (!loadingPadBit(buttonBits, 0)) {
            fullBits = buttonBits;
            result = 1;
            if (!loadingPadBit(fullBits, 1)) {
            result = 1;
            if (!loadingPadBit(fullBits, 2)) {
            result = 1;
            if (!loadingPadBit(fullBits, 3)) {
            result = 1;
            if (!loadingPadBit(fullBits, 4)) {
            result = 1;
            if (!loadingPadBit(fullBits, 5)) {
            result = 1;
            if (!loadingPadBit(fullBits, 6)) {
            result = 1;
            if (!loadingPadBit(fullBits, 7)) {
            result = 1;
            if (!loadingPadBit(fullBits, 8)) {
            result = 1;
            if (!loadingPadBit(fullBits, 9)) {
            result = 1;
            if (!loadingPadBit(fullBits, 10)) {
            result = 1;
            if (!loadingPadBit(fullBits, 11)) {
            result = 1;
            if (!loadingPadBit(fullBits, 12)) {
            result = 1;
            if (!loadingPadBit(fullBits, 14)) {
            result = 1;
            if (!loadingPadBit(fullBits, 13)) {
                bits = fullBits >> 15;
                goto boolean;
            }
            }
            }
            }
            }
            }
            }
            }
            }
            }
            }
            }
            }
            }
        }
        return result;
    case 128:
        if (arg1 == 0) {
            if (arg2) {
                f0 = x;
                f2 = 128.0f;
                f1 = y;
                f0 *= f2;
                f1 *= f2;
                arg2[0] = (int)f0;
                arg2[1] = (int)f1;
            }
        } else {
            arg2[0] = (int)loadingRightX(pad) << 7;
            arg2[1] = (int)loadingRightY(*padSlot) << 7;
        }
        result = 1; if (arg2[0]) return result;
        bits = arg2[1];
boolean:
        result = 0;
        if (bits != 0) { result = 1; }
        break;
    default: result = 0; break;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002076CC);
#endif

// NON_MATCHING: 278/404 differ, 11 relocs differ (size 0x650, game 0x624), 142 edits
#ifdef NON_MATCHING
#include "ror.h"
struct Loading7AVec { float x, y, z, w; } ALIGNED(8);
static inline void loading7A_set(void *dst, const float *src) { float *v = (float *)dst; v[0] = src[0]; v[1] = src[1]; v[2] = src[2]; v[3] = 0; }
extern double D_00300598 ALIGNED(8);
extern double D_003005A0 ALIGNED(8);
extern double D_003005A8 ALIGNED(8);
extern double D_003005B0 ALIGNED(8);
extern "C" { float sinf(float angle); }
extern "C" { float cosf(float angle); }
extern "C" { float sqrtf(float value); }
extern "C" float loading7A_atan(float, float) asm("func_0026CB00");
extern "C" float loading7A_mod(float, float) asm("func_0026CB18");
extern "C" void loading7A_add(Loading7AVec *, Loading7AVec *, Loading7AVec *) asm("func_0025B878");
extern "C" void loading7A_sub(Loading7AVec *, Loading7AVec *, Loading7AVec *) asm("func_0025B890");
extern "C" void loading7A_norm(Loading7AVec *, Loading7AVec *) asm("sceVu0Normalize");
extern "C" float loading7A_dot(Loading7AVec *, Loading7AVec *) asm("sceVu0InnerProduct");
extern "C" void loading7A_cross(Loading7AVec *, Loading7AVec *, Loading7AVec *) asm("sceVu0OuterProduct");
extern "C" void loading7A_scale(Loading7AVec *, Loading7AVec *, float) asm("func_0025C1F0");
extern "C" int loading7A_rand() asm("rand");
extern "C" int func_00207AE8(unsigned int arg0, int arg1, float *param2, float *param3, float *arg4)
{
    struct { int sp0, pad[3]; Loading7AVec v[5]; } stack;
    float angle, a, b, y;
    register float value PS2_REG("$f12");
    register float *arg2 PS2_REG("$17") = param2;
    register float *arg3 PS2_REG("$18") = param3;
    register float *out PS2_REG("$16");
    Loading7AVec *input;
    stack.sp0 = arg1;
    switch (arg0) {
    case 1:
        value = (float)((double)*(float *)&stack.sp0 * D_00300598 / D_003005A0);
        goto sine;
    case 2:
        value = (float)((double)*(float *)&stack.sp0 * D_003005A8 / D_003005B0);
        goto cosine;
    case 3:
        value = *(float *)&stack.sp0;
    sine:
        *arg2 = sinf(value); break;
    case 4:
        value = *(float *)&stack.sp0;
    cosine:
        *arg2 = cosf(value); break;
    case 5:
        value = loading7A_atan(*arg2, *arg3);
        goto scalar;
    case 10: *(float *)stack.sp0 = *arg2 + *arg3; break;
    case 11: *(float *)stack.sp0 = *arg2 - *arg3; break;
    case 12: *(float *)stack.sp0 = *arg2 / *arg3; break;
    case 13: *(float *)stack.sp0 = *arg2 * *arg3; break;
    case 20: *(int *)stack.sp0 = (int)*arg2; break;
    case 21: value = (float)*(int *)arg2; goto scalar;
    case 30: value = sqrtf(*arg2 + *arg3); goto scalar;
    case 50:
        out = (float *)stack.sp0;
        angle = *arg4;
        a = cosf(angle) * arg3[0];
        a = a + sinf(angle) * arg3[2];
        stack.v[0].x = a + arg2[0];
        stack.v[0].y = arg3[1] + arg2[1];
        b = -sinf(angle) * arg3[0];
        b = b + cosf(angle) * arg3[2];
        stack.v[0].z = b + arg2[2];
        out[0] = stack.v[0].x;
        out[1] = stack.v[0].y;
        out[2] = stack.v[0].z;
        break;
    case 51:
        out = (float *)stack.sp0;
        loading7A_set(&stack.v[3], arg2);
        stack.v[2] = stack.v[3];
        loading7A_set(&stack.v[4], arg3);
        stack.v[3] = stack.v[4];
        loading7A_add(&stack.v[1], &stack.v[2], &stack.v[3]);
        out[0] = stack.v[1].x; out[1] = stack.v[1].y; out[2] = stack.v[1].z; out[3] = stack.v[1].w;
        break;
    case 52:
        out = (float *)stack.sp0;
        loading7A_set(&stack.v[2], arg2);
        stack.v[1] = stack.v[2];
        loading7A_set(&stack.v[3], arg3);
        stack.v[2] = stack.v[3];
        loading7A_sub(&stack.v[0], &stack.v[1], &stack.v[2]);
        goto vector;
    case 53:
        out = (float *)stack.sp0;
        input = &stack.v[1];
        loading7A_set(&stack.v[2], arg2);
        stack.v[1] = stack.v[2];
        goto normalize;
    case 54:
        stack.v[1].x = ((float *)stack.sp0)[0]; stack.v[1].y = ((float *)stack.sp0)[1]; stack.v[1].z = ((float *)stack.sp0)[2]; stack.v[1].w = 0;
        stack.v[0] = stack.v[1];
        loading7A_set(&stack.v[2], arg2);
        stack.v[1] = stack.v[2];
        value = loading7A_dot(&stack.v[0], &stack.v[1]);
    scalar:
        *(float *)stack.sp0 = value; break;
    case 55:
        out = (float *)stack.sp0;
        loading7A_set(&stack.v[2], arg2);
        stack.v[1] = stack.v[2];
        loading7A_set(&stack.v[3], arg3);
        stack.v[2] = stack.v[3];
        loading7A_cross(&stack.v[0], &stack.v[1], &stack.v[2]);
        goto vector;
    case 56:
        out = (float *)stack.sp0;
        value = sqrtf(arg2[0]*arg2[0] + arg2[1]*arg2[1] + arg2[2]*arg2[2]);
        *out = value; break;
    case 57:
        out = (float *)stack.sp0;
        loading7A_set(&stack.v[2], arg2);
        stack.v[1] = stack.v[2];
        loading7A_scale(&stack.v[0], &stack.v[1], *arg3);
        goto vector;
    case 58:
        ((float *)stack.sp0)[0] = arg2[0]; ((float *)stack.sp0)[1] = arg2[1]; ((float *)stack.sp0)[2] = arg2[2]; ((float *)stack.sp0)[3] = arg2[3]; break;
    case 59:
        ((float *)stack.sp0)[0] = arg2[0]; ((float *)stack.sp0)[1] = arg3[0]; ((float *)stack.sp0)[2] = *arg4; ((float *)stack.sp0)[3] = 0; break;
    case 60:
        out = (float *)stack.sp0;
        *out = loading7A_mod(*arg2, 6.283185307179586f); break;
    case 61:
        out = (float *)stack.sp0;
        stack.v[1].x = (float)loading7A_rand() - 1073741760.0f;
        stack.v[1].y = (float)loading7A_rand() - 1073741760.0f;
        stack.v[1].z = (float)loading7A_rand() - 1073741760.0f;
        stack.v[1].w = 0;
        stack.v[0] = stack.v[1];
        input = &stack.v[0];
    normalize:
        loading7A_norm(&stack.v[0], input);
    vector:
        out[0] = stack.v[0].x; out[1] = stack.v[0].y; out[2] = stack.v[0].z; out[3] = stack.v[0].w;
        break;
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    default: break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00207AE8);
#endif

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00300598);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_003005A0);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_003005A8);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_003005B0);

extern "C" int func_0020810C(unsigned int arg0, unsigned int arg1, int arg2)
{
    struct { unsigned int sp0; } stack;
    register int base4 PS2_REG("$4");
    register int base3 PS2_REG("$3");
    register int base2 PS2_REG("$2");
    register unsigned int mask4 PS2_REG("$4");
    int temp_v1;
    int temp_v1_2;
    register int var_v0 PS2_REG("$2");
    int var_v1;
    int var_v0_2;

    stack.sp0 = arg1;
    switch (arg0) {
    case 1:
        X_func_001C65E8((int)&D_007812C0, stack.sp0);
        break;
    case 2:
        X_func_001C6A40((int)&D_007812C0, stack.sp0);
        if (stack.sp0 == 0x100000) {
            return 0xCCCCCCCD;
        }
        break;
    case 4:
        X_func_001CB384((int)&D_007812C0, stack.sp0);
        break;
    case 5:
        X_func_001CB424((int)&D_007812C0, stack.sp0);
        break;
    case 3:
    case 6:
        X_func_001CB24C((int)&D_007812C0, stack.sp0);
        break;
    case 7:
        temp_v1 = ((stack.sp0 >> 5) * 4) + (*(int *)&D_007B2060);
        (*(int *)(temp_v1)) |= 1 << (stack.sp0 & 0x1F);
        break;
    case 8:
        temp_v1_2 = ((stack.sp0 >> 5) * 4) + (*(int *)&D_007B2060);
        (*(int *)(temp_v1_2)) &= ~(1 << (stack.sp0 & 0x1F));
        break;
    case 9:
        M2C_FIELD((*(int *)&D_007B205C), unsigned int *, 0x174) = stack.sp0;
        X_func_001C6F08((int)&D_007812C0, 0x1B, (int)&stack);
        break;
    case 10:
        var_v0 = (*(int *)&D_007A3208);
        return (var_v0 & stack.sp0) != 0;
    case 11:
        return (*(int *)&D_007A3210);
    case 12:
        base2 = (int)&D_007812C0;
        mask4 = stack.sp0;
        M2C_FIELD(base2, int *, 0x21F4C) = (int) (M2C_FIELD(base2, int *, 0x21F4C) | mask4);
        break;
    case 13:
        base4 = (int)&D_007812C0;
        M2C_FIELD(base4, int *, 0x21F4C) = (int) (M2C_FIELD(base4, int *, 0x21F4C) & ~stack.sp0);
        break;
    case 14:
        var_v0 = (*(int *)&D_007A320C);
        return (var_v0 & stack.sp0) != 0;
    case 20:
        X_func_001C53E0((int)&D_007812C0, stack.sp0);
        break;
    case 21:
        base3 = (int)&D_007812C0;
        M2C_FIELD(base3, unsigned int *, 0x21FF4) = stack.sp0;
        M2C_FIELD(base3, int *, 0x21FF8) = arg2;
        M2C_FIELD(base3, int *, 0x21F4C) = (int) (M2C_FIELD(base3, int *, 0x21F4C) | 0x10000000);
        break;
    case 30:
        var_v1 = 0;
        var_v0_2 = (*(int *)&D_007A3350);
        goto block_21;
    case 31:
        var_v1 = 0;
        var_v0_2 = (*(int *)((int)&D_007A3354));
block_21:
        if (var_v0_2 != 0) {
            var_v1 = M2C_FIELD(var_v0_2, int *, 0x100);
        }
        return var_v1;
    case 0: default: break;
    }
    return 0;
}

extern "C" int func_00208394()
{
    return 0;
}


extern "C" void X_func_001DD5E8(void *, void *, int, int) asm("func_001DD5E8");
extern "C" void X_func_001DDC80(void *, void *) asm("func_001DDC80");
extern "C" void X_func_001DE4E4(void *, void *) asm("func_001DE4E4");
extern "C" void X_func_001DE6FC(void *, void *) asm("func_001DE6FC");

extern "C" int func_0020839C(unsigned int arg0, float *arg1)
{
    register char *gm PS2_REG("$4");

    switch (arg0) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5: {
        int flg = *(int *)((char *)arg1 + 0x20) | 0x3000000;
        *(int *)((char *)arg1 + 0x20) = flg;
        if (flg & 0x103) {
            if (arg1[0] > arg1[2]) {
                float tmp = arg1[0];
                arg1[0] = arg1[2];
                arg1[2] = tmp;
            }
            if (arg1[1] > arg1[3]) {
                float tmp = arg1[1];
                arg1[1] = arg1[3];
                arg1[3] = tmp;
            }
        }
        switch (arg0) {
        case 1:
            gm = (char *)&D_007812C0;
            X_func_001DD5E8(gm + 0x40, arg1, 0, -1);
            break;
        case 2:
            gm = (char *)&D_007812C0;
            X_func_001DD5E8(gm + 0x40, arg1, 1, -1);
            break;
        case 3:
            gm = (char *)&D_007812C0;
            X_func_001DD5E8(gm + 0x40, arg1, 1, 0);
            break;
        case 4:
            gm = (char *)&D_007812C0;
            X_func_001DD5E8(gm + 0x40, arg1, 1, 1);
            break;
        case 5:
            gm = (char *)&D_007812C0;
            X_func_001DD5E8(gm + 0x40, arg1, 1, 2);
            break;
        }
        break;
    }
    case 10:
        gm = (char *)&D_007812C0;
        X_func_001DE4E4(gm + 0x40, arg1);
        break;
    case 11:
        gm = (char *)&D_007812C0;
        X_func_001DDC80(gm + 0x40, arg1);
        break;
    case 30:
        gm = (char *)&D_007812C0;
        X_func_001DE6FC(gm + 0x40, arg1);
        break;
    case 0:
    default:
        break;
    }
    return 0;
}

extern "C" int func_00208508()
{
    return 0;
}


extern "C" int func_00208510()
{
    return 0;
}


extern "C" int func_00208518(unsigned int arg0, int arg1, int arg2, int arg3, int arg4)
{
    register int base11 PS2_REG("$11");

    switch (arg0) {
    case 1: {
        int params[4];
        int p;
        params[0] = arg1;
        params[1] = arg2;
        params[2] = arg3;
        params[3] = arg4;
        p = X___builtin_new(0x80);
        X_func_001F184C(p, 8, (int)params, 0);
        base11 = (int)&D_007812C0;
        base11 += 0x222AC;
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, p, 0, base11, 0x11);
        break;
    }
    case 2: {
        int params[4];
        int p;
        params[0] = arg1;
        params[1] = arg2;
        params[2] = arg3;
        params[3] = arg4;
        p = X___builtin_new(0x80);
        X_func_001F184C(p, 8, (int)params, 0);
        base11 = (int)&D_007812C0;
        base11 += 0x222A4;
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, p, 0, base11, 0x11);
        break;
    }
    case 0:
    case 3:
    case 4:
    case 5:
    default:
        break;
    }
    return 0;
}

// NON_MATCHING: 240/306 differ, 36 relocs differ (size 0x4C8, game 0x4D0), 44 edits
#ifdef NON_MATCHING
extern "C" int X_func_001C4F38(...) asm("func_001C4F38");
extern "C" int X_func_001CA0D4(...) asm("func_001CA0D4");
extern "C" int X_func_001CA0DC(...) asm("func_001CA0DC");
extern "C" int X_func_001CA72C(...) asm("func_001CA72C");
extern "C" int X_func_001CA8E8(...) asm("func_001CA8E8");
extern "C" int X_func_001CAD88(...) asm("func_001CAD88");
extern "C" void loading8640Set(int, int, int, int, int, int, int, int, float, int, int, int, int) asm("func_001CC560");
extern "C" int X_func_001CD7C0(...) asm("func_001CD7C0");
extern "C" int X_func_001D024C(...) asm("func_001D024C");
extern "C" int X_func_001FBBD0(...) asm("func_001FBBD0");
extern "C" void loading8640Value(int, int, float) asm("func_001D024C");
extern "C" int func_00208640(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5)
{
    unsigned int saved0 = arg0;
    register unsigned int saved1 PS2_REG("$17") = arg1;
    register unsigned int saved5 PS2_REG("$18") = arg5;
    register unsigned int saved2 PS2_REG("$19") = arg2;
    register unsigned int saved3 PS2_REG("$20") = arg3;
    register unsigned int saved4 PS2_REG("$21") = arg4;
    struct { unsigned short sp20; } stack;
    int base;
    int var_a1_2;
    int var_a1_3;
    int var_a3;
    int var_a3_2;
    int var_a3_3;
    int var_a5_3;
    unsigned short var_a1;
    unsigned int temp_v0;
    unsigned int var_a2;
    unsigned int var_a2_2;
    unsigned int var_a2_3;
    unsigned int var_a3_4;
    unsigned int var_a3_5;
    unsigned int var_a4;
    unsigned int var_a4_2;
    unsigned int var_a4_3;
    unsigned int var_a5;
    unsigned int var_a5_2;
    unsigned int var_a6;

    X_func_001FBBD0();
    switch (saved0) {
    case 0x2:
        X_func_001CA0D4((int)&D_007812C0, saved1, 2);
        break;
    case 0x3:
        base = (int)&D_007812C0;
        var_a1 = saved1 & 0xFFFF;
        var_a2 = saved2;
        var_a3 = 0xFFFF;
        var_a4 = 0; var_a5 = -1U; X_func_001CA8E8(base, var_a1, var_a2, var_a3, var_a4, (int)var_a5, 1); break;
    case 0x4:
        base = (int)&D_007812C0;
        saved1 = saved1 & 0xFFFF;
        X_func_001DC48C(base + 0x22220, saved1, (int) 0xF, (int)&stack.sp20);
        if (stack.sp20 != 0xFFFF) {
            var_a1 = stack.sp20;
            var_a2 = saved2;
            var_a3 = saved1;
            var_a4 = 0; var_a5 = -1U; X_func_001CA8E8(base, var_a1, var_a2, var_a3, var_a4, (int)var_a5, 1); break;
        }
        var_a3_2 = saved1;
        var_a4_2 = 0;
        X_func_001CC250(base, -1U, saved2, var_a3_2, var_a4_2, 0); break;
    case 0x5:
        base = (int)&D_007812C0;
        saved1 = saved1 & 0xFFFF;
        X_func_001DC48C(base + 0x22220, saved1, (int) 0xF, (int)&stack.sp20);
        var_a1 = stack.sp20;
        if (stack.sp20 != 0xFFFF) {
            var_a2 = saved2;
            var_a3 = saved1;
            var_a4 = saved3;
            var_a5 = -1U; X_func_001CA8E8(base, var_a1, var_a2, var_a3, var_a4, (int)var_a5, 1); break;
        }
        var_a3_2 = saved1;
        var_a4_2 = saved3;
        var_a3_3 = var_a3_2;
        var_a4_3 = var_a4_2;
        var_a5_2 = 0;
        X_func_001CC250(base, -1U, saved2, var_a3_3, var_a4_3, (int)var_a5_2); break;
    case 0x6:
        base = (int)&D_007812C0;
        saved1 = saved1 & 0xFFFF;
        X_func_001DC48C(base + 0x22220, saved1, (int) 0xF, (int)&stack.sp20);
        if (stack.sp20 != 0xFFFF) {
            var_a1 = stack.sp20;
            var_a2 = saved2;
            var_a3 = saved1;
            var_a4 = saved4;
            var_a5 = saved3;
            X_func_001CA8E8(base, var_a1, var_a2, var_a3, var_a4, (int)var_a5, 1); break;
        }
        var_a3_3 = saved1;
        var_a4_3 = saved4;
        var_a5_2 = saved3;
        X_func_001CC250(base, -1U, saved2, var_a3_3, var_a4_3, (int)var_a5_2); break;
    case 0x7:
        base = (int)&D_007812C0;
        saved1 = saved1 & 0xFFFF;
        X_func_001DC48C(base + 0x22220, saved1, (int) 0xF, (int)&stack.sp20);
        if (saved3 != 0xFFFF) {
            var_a1 = stack.sp20;
            var_a2 = saved2;
            var_a3 = saved1;
            var_a4 = saved5;
            var_a5 = saved4;
            X_func_001CA8E8(base, var_a1, var_a2, var_a3, var_a4, (int)var_a5, 1); break;
        }
        var_a3_3 = saved1;
        var_a4_3 = saved5;
        var_a5_2 = saved4;
        X_func_001CC250(base, -1U, saved2, var_a3_3, var_a4_3, (int) var_a5_2);
        break;
    case 0x8:
        base = (int)&D_007812C0;
        saved1 = saved1 & 0xFFFF;
        X_func_001DC48C(base + 0x22220, saved1, (int) 0xF, (int)&stack.sp20);
        loading8640Set(base, stack.sp20, saved2, M2C_FIELD(saved5, int *, 4), M2C_FIELD(saved5, int *, 8), M2C_FIELD(saved5, int *, 0xC), M2C_FIELD(saved5, int *, 0x10), M2C_FIELD(saved5, int *, 0x14), (float) M2C_FIELD(saved5, int *, 0x1C), M2C_FIELD(saved5, int *, 0x18), saved1, (int) saved4, M2C_FIELD(saved5, int *, 0));
        break;
    case 0x9:
        var_a1_2 = saved1 & 0xFFFF;
        var_a2_2 = saved2;
        var_a6 = saved4;
        var_a3_4 = -1U;
        var_a5_3 = 0xFFFF;
        X_func_001CA72C((int)&D_007812C0, var_a1_2, var_a2_2, var_a3_4, saved3, var_a5_3, var_a6, -1); break;
    case 0xA:
        X_func_001CA0D4((int)&D_007812C0, saved1, 3);
        break;
    case 0xC:
        X_func_001CA0DC((int)&D_007812C0, saved1, saved2, 2);
        break;
    case 0xD:
        X_func_001CA0DC((int)&D_007812C0, saved1, saved2, 3);
        break;
    case 0xE:
        var_a1_3 = saved1 & 0xFFFF;
        var_a2_3 = saved2;
        var_a3_5 = saved3;
        X_func_001CAD88((int)&D_007812C0, var_a1_3, var_a2_3, var_a3_5, 1); break;
    case 0xF:
        var_a1_3 = saved1 & 0xFFFF;
        var_a3_5 = saved2;
        var_a2_3 = 0;
        X_func_001CAD88((int)&D_007812C0, var_a1_3, var_a2_3, var_a3_5, 1);
        break;
    case 0x14:
        X_func_001C4F38((int)&D_007812C0, saved1);
        break;
    case 0x23:
        var_a1_2 = saved5 & 0xFFFF;
        var_a2_2 = saved1;
        var_a5_3 = saved2 & 0xFFFF;
        var_a3_4 = 9;
        var_a6 = 0;
        X_func_001CA72C((int)&D_007812C0, var_a1_2, var_a2_2, var_a3_4, saved3, var_a5_3, var_a6, -1);
        break;
    case 0x24:
        base = (int)&D_007812C0;
        saved1 = saved2 & 0xFFFF;
        X_func_001DC48C(base + 0x22220, saved1, (int) 0xF, (int)&stack.sp20);
        var_a1 = stack.sp20;
        var_a2 = saved3;
        var_a5 = M2C_FIELD((*(int *)&D_007B205C), unsigned int *, 0xB8);
        var_a3 = saved1;
        var_a4 = saved4;
        X_func_001CA8E8(base, var_a1, var_a2, var_a3, var_a4, (int)var_a5, 1); break;
    case 0x32:
        base = (int)&D_007812C0;
        var_a1 = saved1 & 0xFFFF;
        var_a2 = saved2;
        var_a3 = saved3 & 0xFFFF;
        var_a4 = 0;
        var_a5 = -1U;
        X_func_001CA8E8(base, var_a1, var_a2, var_a3, var_a4, (int) var_a5, 1);
        break;
    case 0x64:
        base = (int)&D_007812C0;
        if (X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(base, int *, 0x222BC)) == 0) {
            X_func_001CD7C0(base, saved1);
        }
        break;
    case 0xC8:
        base = (int)&D_007812C0;
        temp_v0 = X_func_001CA72C(base, saved1 & 0xFFFF, saved2, saved1 >> 0xA, 0U, 0xFFFF, saved3, -1);
        M2C_FIELD((*(int *)&D_007B205C), unsigned int *, 0x188) = temp_v0;
        if (saved4 != 0) {
            loading8640Value(base, temp_v0, (*(float *)(saved4)));
        }
        break;
    case 0:
    case 1:
    case 11:
    case 16:
    case 17:
    case 18:
    case 19:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
    case 136:
    case 137:
    case 138:
    case 139:
    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
    case 145:
    case 146:
    case 147:
    case 148:
    case 149:
    case 150:
    case 151:
    case 152:
    case 153:
    case 154:
    case 155:
    case 156:
    case 157:
    case 158:
    case 159:
    case 160:
    case 161:
    case 162:
    case 163:
    case 164:
    case 165:
    case 166:
    case 167:
    case 168:
    case 169:
    case 170:
    case 171:
    case 172:
    case 173:
    case 174:
    case 175:
    case 176:
    case 177:
    case 178:
    case 179:
    case 180:
    case 181:
    case 182:
    case 183:
    case 184:
    case 185:
    case 186:
    case 187:
    case 188:
    case 189:
    case 190:
    case 191:
    case 192:
    case 193:
    case 194:
    case 195:
    case 196:
    case 197:
    case 198:
    case 199:
    case 201:
    case 202:
    case 203:
    case 204:
    default: break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00208640);
#endif

extern "C" int func_00208B10(unsigned int arg0)
{
    switch (arg0) {
    case 0:
        break;
    case 1:
        X_func_001CB01C((int)&D_007812C0, 2);
        break;
    case 2:
        X_func_001CB01C((int)&D_007812C0, 3);
        break;
    case 3:
        X_func_001CCC30((int)&D_007812C0);
        break;
    case 10:
        X_func_001CB01C((int)&D_007812C0, 0);
        break;
    case 20:
        X_func_001C4F70((int)&D_007812C0);
        break;
    case 30:
        break;
    }
    return 0;
}

// NON_MATCHING: 113/133 differ, 11 relocs differ (size 0x214, game 0x21C), 58 edits
#ifdef NON_MATCHING
extern "C" int X_func_001CD044(...) asm("func_001CD044");
extern "C" int func_00208B98(unsigned int arg0, int arg1, int arg2)
{
    struct { unsigned int sp10; int sp14; int sp18; int sp1C; } stack;
    int temp_v0;
    int var_a1;
    int base;
    switch (arg0) {
    case 1:
        base = (int)&D_007812C0;
        if (!(M2C_FIELD(base, int *, 0x21F48) & 0x800) ||
            X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(base, int *, 0x222BC)) == 0) {
            var_a1 = (int)&D_007812C0 + 0x222DC;
            if (M2C_FIELD(var_a1, int *, 4)) {
                stack.sp10 = M2C_FIELD(var_a1, unsigned int *, 0);
                stack.sp14 = M2C_FIELD(var_a1, int *, 4);
                stack.sp18 = arg1;
                stack.sp1C = 0xCCCCCCCC;
                goto create;
            }
            X_func_001CD044((int)&D_007812C0, 2, arg1, 0, -1, 0xCCCCCCCC);
            break;
        }
        return 0xCCCCCCCC;
    case 2:
        base = (int)&D_007812C0;
        if (!(M2C_FIELD(base, int *, 0x21F48) & 0x800) ||
            X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(base, int *, 0x222BC)) == 0) {
            var_a1 = (int)&D_007812C0 + 0x222DC;
            if (M2C_FIELD(var_a1, int *, 4)) {
                stack.sp10 = M2C_FIELD(var_a1, unsigned int *, 0);
                stack.sp14 = M2C_FIELD(var_a1, int *, 4);
                stack.sp18 = arg1;
                stack.sp1C = arg2;
create:
                temp_v0 = X___builtin_new(0x80, var_a1, arg1);
                X_func_001F184C(temp_v0, 0xB, (int)&stack.sp10, 0);
                X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0, 0, 0, 1);
            } else {
                X_func_001CD044((int)&D_007812C0, 2, arg1, 0, -1, arg2);
            }
            break;
        }
        return 0xCCCCCCCC;
    case 10:
        X_func_001CD044((int)&D_007812C0, 1, -1, -1, arg1, 0xCCCCCCCC);
        break;
    case 0: default: break;
    }
    return 0xCCCCCCCA;
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00208B98);
#endif

extern "C" int func_00208DB4()
{
    return 0;
}


extern "C" int func_00208DBC()
{
    return 0;
}


extern "C" int func_00208DC4(int arg0, unsigned char *arg1)
{
    if (arg0 == 10 && (unsigned int)arg1 <= 0x7FFFFFFU) {
        int n = 0;
        while (*arg1++ && n++ < 0x200) {}
        if (n >= 0x1FE) {
            arg1[0] = 0;
            arg1[1] = 0;
        }
    }
    return 0;
}

extern "C" int func_00208E24(unsigned int arg0, int arg1)
{
    struct { int sp10; } stack;
    int var_a1;
    register int data6 PS2_REG("$6");
    register int base2 PS2_REG("$2");
    register int base4 PS2_REG("$4");
    register int base11 PS2_REG("$11");
    float var_f1;
    int temp_v0;
    int temp_v0_2;
    int var_v0;
    int temp_s1;
    int temp_s1_2;

    switch (arg0) {
    case 1:
        base2 = (int)&D_006E9840;
        temp_s1 = base2 + 0x12540;
        temp_v0 = X_func_00131550(temp_s1);
        if ((temp_v0 != 3) && (temp_v0 != 5) && (temp_v0 != 0)) {
            X_func_00131184(temp_s1, arg1, 7, 0);
            return 1;
        }
        break;
    case 2:
        base2 = (int)&D_006E9840;
        temp_s1_2 = base2 + 0x12540;
        temp_v0_2 = X_func_00131550(temp_s1_2);
        if ((temp_v0_2 != 4) && (temp_v0_2 != 6)) {
            X_func_001311BC(temp_s1_2, arg1, 7, 0);
            return 1;
        }
        break;
    case 3:
        base4 = (int)&D_006E9840;
        return X_func_00131608(base4 + 0x12540) - 1;
    case 4:
        base4 = (int)&D_006E9840;
        return (unsigned int) (X_func_00131550(base4 + 0x12540) - 3) < 2U;
    case 5:
        loadingSetValue((int)&D_007812C0, (int)((float)(unsigned int)arg1 * 0.5f));
        break;
    case 6:
        base4 = (int)&D_006FBD80;
        X_func_00190D90(base4 + 0x41930, arg1);
        break;
    case 7:
        base4 = (int)&D_006FBD80;
        X_func_00190E98(base4 + 0x41930, arg1);
        break;
    case 10:
        stack.sp10 = arg1;
        var_v0 = X___builtin_new(0x80);
        var_a1 = 2;
        goto block_21;
    case 11:
        stack.sp10 = arg1;
        var_v0 = X___builtin_new(0x80);
        var_a1 = 3;
        goto block_21;
    case 12:
        stack.sp10 = arg1;
        var_v0 = X___builtin_new(0x80);
        var_a1 = 4;
        goto block_21;
    case 13:
        stack.sp10 = arg1;
        var_v0 = X___builtin_new(0x80);
        var_a1 = 5;
block_21:
        data6 = (int)&stack.sp10;
        X_func_001F184C(var_v0, var_a1, data6, 0);
        base11 = (int)&D_007812C0;
        base11 += 0x222AC;
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, var_v0, 0, base11, 0x11);
        break;
    case 0: default: break;
    }
    return 0;
}

extern "C" int func_00209090()
{
    return 0;
}


extern "C" int func_00209098()
{
    return 0;
}


extern "C" int func_002090A0(int arg0)
{
    switch (arg0) {
    case 0:
        break;
    case 1:
        return X_func_0020F140((int)&D_007A4440);
    }
    return 0;
}

extern "C" int func_002090D8()
{
    return 0;
}


extern "C" int X_func_001C9920(void *, int, int, void *, void *) asm("func_001C9920");

extern "C" int func_002090E0(unsigned int arg0, int arg1, int arg2, int *arg3)
{
    switch (arg0) {
    case 1:
        X_func_001C9920(&D_007812C0, arg1, 0, &arg2, 0);
        break;
    case 2:
        X_func_001C9920(&D_007812C0, arg1, 1, &arg2, 0);
        break;
    case 3:
        return X_func_001C9920(&D_007812C0, arg1, 2, &arg2, 0);
    case 4:
        X_func_001C9920(&D_007812C0, arg1, 4, &arg2, 0);
        break;
    case 5: {
        int ret;
        X_func_001C9920(&D_007812C0, arg1, 5, &ret, 0);
        return ret;
    }
    case 6:
        X_func_001C9920(&D_007812C0, arg1, 9, &arg2, 0);
        break;
    case 10:
        X_func_001C9920(&D_007812C0, arg1, 11, (void *)arg2, 0);
        break;
    case 11: {
        int out[4];
        X_func_001C9920(&D_007812C0, arg1, 12, out, 0);
        *(int *)arg2 = out[0];
        *arg3 = out[1];
        break;
    }
    case 12:
        X_func_001C9920(&D_007812C0, arg1, 13, (void *)arg2, 0);
        break;
    case 13:
        X_func_001C9920(&D_007812C0, arg1, 14, (void *)arg2, 0);
        break;
    case 14:
        X_func_001C9920(&D_007812C0, arg1, 15, (void *)arg2, 0);
        break;
    case 15:
        X_func_001C9920(&D_007812C0, arg1, 16, (void *)arg2, 0);
        break;
    case 99:
        X_func_001C9920(&D_007812C0, arg1, 5, &arg2, arg3);
        break;
    case 0:
    default:
        break;
    }
    return 0;
}

extern "C" int func_00209270(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    if (arg0 == 0x65716473) {
        if (arg1 != 0) {
            D_007812C0.setSysFlg2(0x4000000);
        } else {
            D_007812C0.unsetSysFlg2(0x4000000);
        }
    }
    switch (arg0) {
    case 100:
        X_func_001C541C((int)&D_007812C0);
        return 0;
    case 101:
        return D_007A3294;
    default: {
        int args[6];
        args[0] = arg0;
        args[1] = arg1;
        args[2] = arg2;
        args[3] = arg3;
        args[4] = arg4;
        args[5] = arg5;
        return X_func_00144AE0((int)args);
    }
    }
}

extern "C" int func_00209344()
{
    return 0xCCCCCCCA;
}


extern "C" int func_00209350()
{
    return 0;
}


extern "C" int func_00209358()
{
    return 0;
}


extern "C" int func_00209360()
{
    return 0;
}


extern "C" int func_00209368()
{
    return 0;
}


extern "C" int func_00209370()
{
    return 0;
}


extern "C" int func_00209378()
{
    return 0;
}


extern "C" int func_00209380()
{
    return 0;
}


extern "C" int func_00209388()
{
    return 0;
}


extern "C" int func_00209390()
{
    return 0;
}


extern "C" int func_00209398()
{
    return 0;
}


extern "C" int func_002093A0()
{
    return 0;
}


extern "C" int func_002093A8()
{
    return 0;
}


extern "C" int func_002093B0()
{
    return 0;
}


extern "C" int func_002093B8()
{
    return 0;
}


extern "C" int func_002093C0()
{
    return 0;
}


extern "C" int func_002093C8()
{
    return 0;
}


extern "C" int func_002093D0()
{
    return 0;
}


extern "C" int func_002093D8()
{
    return 0;
}


extern "C" int func_002093E0()
{
    return 0;
}


extern "C" int func_002093E8()
{
    return 0;
}


extern "C" int func_002093F0()
{
    return 0;
}


extern "C" int func_002093F8()
{
    return 0;
}


extern "C" int func_00209400()
{
    return 0;
}


extern "C" int func_00209408()
{
    return 0;
}


extern "C" int func_00209410()
{
    return 0;
}


extern "C" int func_00209418()
{
    return 0;
}


extern "C" int func_00209420()
{
    return 0;
}


extern "C" int func_00209428()
{
    return 0;
}


extern "C" int func_00209430()
{
    return 0;
}


extern "C" int func_00209438()
{
    return 0;
}


extern "C" int func_00209440()
{
    return 0;
}


extern "C" int func_00209448()
{
    return 0;
}


extern "C" int func_00209450()
{
    return 0;
}


extern "C" int func_00209458()
{
    return 0;
}


extern "C" int func_00209460()
{
    return 0;
}


extern "C" int func_00209468()
{
    return 0;
}


extern "C" int func_00209470()
{
    return 0;
}


extern "C" int func_00209478()
{
    return 0;
}


extern "C" int func_00209480()
{
    return 0;
}


extern "C" int func_00209488()
{
    return 0;
}


extern "C" int func_00209490()
{
    return 0;
}


extern "C" int func_00209498()
{
    return 0;
}


extern "C" int func_002094A0()
{
    return 0;
}


extern "C" int func_002094A8()
{
    return 0;
}


extern "C" int func_002094B0()
{
    return 0;
}


extern "C" int func_002094B8()
{
    return 0;
}


extern "C" int func_002094C0()
{
    return 0;
}


extern "C" int func_002094C8()
{
    return 0;
}


extern "C" int func_002094D0()
{
    return 0;
}


extern "C" int func_002094D8()
{
    return 0;
}


extern "C" int func_002094E0()
{
    return 0;
}


extern "C" int func_002094E8()
{
    return 0;
}


extern "C" int func_002094F0()
{
    return 0;
}


extern "C" int func_002094F8()
{
    return 0;
}


extern "C" int func_00209500()
{
    return 0;
}


extern "C" int func_00209508()
{
    return 0;
}


extern "C" int func_00209510()
{
    return 0;
}


extern "C" int func_00209518()
{
    return 0;
}


extern "C" int func_00209520()
{
    return 0;
}


// NON_MATCHING: 23/228 differ, 22 edits
#ifdef NON_MATCHING
extern int loadingActors asm("D_006FE6A0");
extern "C" float Xf_func_0010D9EC__8DogActor(...) asm("func_0010D9EC__8DogActor");
extern "C" float Xf_func_001333E4(...) asm("func_001333E4");
extern "C" int X_func_0010AA5C__8DogActorPCc(...) asm("func_0010AA5C__8DogActorPCc");
extern "C" int loadingActorState(...) asm("func_001330F4");
extern "C" void X_func_00133144(int, int, int, int, int, int, float) asm("func_00133144");
extern "C" void X_func_00133324(int, int, int, int, int, int, float) asm("func_00133324");
extern "C" int loadingActorExists(int, unsigned int) asm("func_001D046C");
extern "C" int X_func_001D0758(...) asm("func_001D0758");
extern "C" int X_func_001F59B4(int, int, int, int, int, float, float) asm("func_001F59B4");
extern "C" int X_func_001F5BDC(int, int, int, int, int, float, float) asm("func_001F5BDC");
extern "C" int X_func_001F5D90(int, int, int, int, float, float) asm("func_001F5D90");
extern "C" int X_func_001F61EC(...) asm("func_001F61EC");
extern "C" int X_func_001F6308(int, int, int, int, int, int, float) asm("func_001F6308");
extern "C" int func_00209528(unsigned int arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5)
{
    struct { float sp0; } stack;
    int base = (int)&D_007812C0;
    register int base4 PS2_REG("$4");
    float var_f0;
    int temp_s1;

    int temp_v0;
    int var_a0;
    int var_a3;
    int var_v0;
    int var_a0_2;

    register int data PS2_REG("$18") = arg2;
    register int mode PS2_REG("$20") = arg3;
    register int weight PS2_REG("$19") = arg4;
    register int flags PS2_REG("$21");
    var_v0 = loadingActorExists(base, arg1);
    if (var_v0 != 0) {
        temp_s1 = X_func_001CBE38(base, arg1);
        flags = (arg5 << 7) & 0x100;
        switch (arg0) {
        case 2:
            X_func_001F61EC(arg1);
            base4 = (int)&D_006E9840;
            base4 += 0x12540;
            X_func_00133144(base4, temp_s1, data, mode, flags, 0, 0.016666695f);
            break;
        case 4:
            if (((arg1 >> 0x1C) & 3) == 1) {
                X_func_001D0758((int)&D_007812C0, arg1, (int)&stack);
                X_func_001F59B4(arg1, data, mode, flags, 0, (*(float *)(weight)), stack.sp0);
            } else {
                goto block_16;
            }
            break;
        case 5:
            X_func_001F6308(temp_s1, 0, mode, flags, arg1, data, (*(float *)(weight)));
            break;
        case 6:
            if (((arg1 >> 0x1C) & 3) == 1) {
                X_func_001D0758((int)&D_007812C0, arg1, (int)&stack);
                X_func_001F59B4(arg1, 0, mode, flags, data, (*(float *)(weight)), stack.sp0);
            } else {
                X_func_001F61EC(arg1);
                base4 = (int)&D_006E9840;
                base4 += 0x12540;
                X_func_00133324(base4, temp_s1, data, mode, flags, arg1, (*(float *)(weight)));
            }
            break;
        case 7:
            X_func_001D0758((int)&D_007812C0, arg1, (int)&stack);
            X_func_001F5D90(arg1, data, mode, flags, (*(float *)(weight)), stack.sp0);
            break;
        case 8:
            temp_v0 = X_func_001CBE38((int)&D_007812C0, arg1);
            var_a0 = 0;
            if (temp_v0 != -1) {
                var_a0 = X_func_0010AA5C__8DogActorPCc((int)&loadingActors + (temp_v0 * 0x4D0), data);
            }
            return var_a0;
        case 9:
            if (((arg1 >> 0x1C) & 3) == 1) {
                X_func_001D0758((int)&D_007812C0, arg1, (int)&stack);
                X_func_001F5BDC(arg1, data, mode, flags, 0, (*(float *)(weight)), stack.sp0);
            } else {
                goto block_16;
            }
            break;
        case 3:
block_16:
            X_func_001F6308(temp_s1, data, mode, flags, arg1, 0, (*(float *)(weight)));
            break;
        case 1:
        case 10:
        case 12:
            X_func_001F61EC(arg1);
            base4 = (int)&D_006E9840;
            base4 += 0x12540;
            X_func_00133144(base4, temp_s1, data, 0, flags, 0, 0.016666695f);
            break;
        case 30:
            base4 = (int)&D_006E9840;
            base4 += 0x12540;
            return loadingActorState(base4, temp_s1);
        case 31:
            var_f0 = Xf_func_0010D9EC__8DogActor((int)&loadingActors + (temp_s1 * 0x4D0));
            (*(float *)(data)) = var_f0;
            break;
        case 32:
            base4 = (int)&D_006E9840;
            base4 += 0x12540;
            var_f0 = Xf_func_001333E4(base4, temp_s1, -1);
            (*(float *)(data)) = var_f0;
            break;
        case 0: default: break;
        }
        return 0;
    } else {
        return var_v0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00209528);
#endif

extern "C" int func_002098B8()
{
    return 0;
}


extern "C" int func_002098C0()
{
    return 0;
}


extern "C" int func_002098C8()
{
    return 0;
}


extern "C" int func_002098D0()
{
    return 0;
}


extern "C" int func_002098D8()
{
    return 0;
}


extern "C" int X_hasActor_001D046C(void *, int) asm("func_001D046C");
extern "C" void *X_getActor_001D2B8C(void *, int) asm("func_001D2B8C");
extern "C" void X_func_001333C0(void *, int, float) asm("func_001333C0");
extern "C" void X_func_001DB1B8(void *, float) asm("func_001DB1B8");

extern "C" int func_002098E0(unsigned int arg0, int arg1, float *arg2)
{
    if (X_hasActor_001D046C(&D_007812C0, arg1) == 0) {
        return 0;
    }
    char *obj = (char *)X_getActor_001D2B8C(&D_007812C0, arg1);
    register char *base4 PS2_REG("$4") = (char *)&D_006E9840;
    char *scene = base4 + 0x12540;
    switch (arg0) {
    case 0:
        break;
    case 1:
        X_func_001333C0(scene, *(int *)(obj + 0x108), *arg2);
        break;
    case 2:
        X_func_001DB1B8(obj, *arg2);
        break;
    }
    return 0;
}

extern "C" int func_002099A4()
{
    return 0;
}


extern "C" int func_002099AC()
{
    return 0;
}


extern "C" int func_002099B4()
{
    return 0;
}


extern "C" int func_002099BC(unsigned int arg0, unsigned int arg1, unsigned int arg2, int arg3)
{
    struct { unsigned short sp0; } stack;
    int var_a6;
    register int base PS2_REG("$4");
    int var_a3_2;
    int var_a3;
    unsigned int var_a1;
    unsigned int var_a2;

    switch (arg0) {
    case 0x1:
        X_func_002120AC((int)&D_007A4440, (int) arg2, arg1, 0, 0, 0, (int)"none");
        break;
    case 0x2:
        var_a1 = arg1;
        var_a2 = arg2;
        var_a3 = 0xFFFF;
        X_func_001CC250((int)&D_007812C0, var_a1, var_a2, var_a3, 0U, 0);
        break;
    case 0x3:
        var_a2 = arg1;
        var_a1 = -1U;
        var_a3 = 0xC00;
        X_func_001CC250((int)&D_007812C0, var_a1, var_a2, var_a3, 0U, 0);
        break;
    case 0x4:
        if (arg1 != 0xFFFF) {
            base = (int)&D_007812C0;
            X_func_001DC48C(base + 0x22220, arg1 & 0xFFFF, (int) 0xF, (int)&stack);
        } else {
            stack.sp0 = -1U;
        }
        X_func_001CC044((int)&D_007812C0, stack.sp0, (int) arg2, arg3, arg1 & 0xFFFF, 0);
        break;
    case 0xB:
        X_func_00212920((int)&D_007A4440, (int) arg2, arg1);
        break;
    case 0xD:
        var_a3_2 = 0;
        X_func_002129B8((int)&D_007A4440, arg1, 0, var_a3_2);
        return 0xCCCCCCCD;
    case 0xE:
        var_a3_2 = 1;
        X_func_002129B8((int)&D_007A4440, arg1, 0, 1);
        return 0xCCCCCCCD;
    case 0xF:
        X_func_00212A5C((int)&D_007A4440, arg1, 0, 1);
        return 0xCCCCCCC9;
    case 0x14:
        var_a1 = arg1;
        var_a2 = arg2;
        var_a3 = arg3 & 0xFFFF;
        X_func_001CC250((int)&D_007812C0, var_a1, var_a2, var_a3, 0U, 0);
        break;
    case 0x15:
        M2C_FIELD((int)&D_002D9900, float *, 0) = (float) M2C_FIELD(arg2, float *, 0);
        M2C_FIELD((int)&D_002D9900, float *, 4) = (float) M2C_FIELD(arg2, float *, 4);
        M2C_FIELD((int)&D_002D9900, float *, 8) = (float) M2C_FIELD(arg2, float *, 8);
        X_func_001CC250((int)&D_007812C0, -1U, arg1, 0x1200, (unsigned int) (int)&D_002D9900, 0);
        break;
    case 0x1E:
        var_a6 = (int) arg3;
        X_func_002120AC((int)&D_007A4440, (int)arg2, arg1, 0, 0, 0, arg3);
        break;
    case 0x1F:
        X_func_00212E64((int)&D_007A4440, arg1);
        break;
    case 0x63:
        X_func_00212D08((int)&D_007A4440, (int) arg2, 0);
        break;
    case 0: default: break;
    }
    return 0;
}

extern "C" int func_00209C0C()
{
    return 0;
}


extern "C" int func_00209C14()
{
    return 0;
}


extern "C" int func_00209C1C()
{
    return 0;
}


extern "C" int func_00209C24()
{
    return 0;
}


extern "C" int func_00209C2C()
{
    return 0;
}


extern "C" int func_00209C34()
{
    return 0;
}


extern "C" int func_00209C3C()
{
    return 0;
}


extern "C" int func_00209C44()
{
    return 0;
}


extern "C" int func_00209C4C()
{
    return 0;
}


extern "C" int func_00209C54()
{
    return 0;
}


extern "C" int func_00209C5C()
{
    return 0;
}


extern "C" int func_00209C64()
{
    return 0;
}


extern "C" int func_00209C6C()
{
    return 0;
}


extern "C" int func_00209C74()
{
    return 0;
}


extern "C" int func_00209C7C()
{
    return 0;
}


extern "C" int func_00209C84()
{
    return 0;
}


extern "C" int func_00209C8C()
{
    return 0;
}


extern "C" int func_00209C94()
{
    return 0;
}


extern "C" int func_00209C9C()
{
    return 0;
}


extern "C" int func_00209CA4()
{
    return 0;
}


extern "C" int func_00209CAC()
{
    return 0;
}


extern "C" int func_00209CB4()
{
    return 0;
}


extern "C" int func_00209CBC()
{
    return 0;
}


extern "C" int func_00209CC4()
{
    return 0;
}


extern "C" int func_00209CCC()
{
    return 0;
}


extern "C" int func_00209CD4()
{
    return 0;
}


extern "C" int func_00209CDC()
{
    return 0;
}


extern "C" int func_00209CE4()
{
    return 0;
}


extern "C" int func_00209CEC()
{
    return 0;
}


extern "C" int func_00209CF4()
{
    return 0;
}


extern "C" int func_00209CFC()
{
    return 0;
}


extern "C" int func_00209D04()
{
    return 0;
}


extern "C" int func_00209D0C()
{
    return 0;
}


extern "C" int func_00209D14()
{
    return 0;
}


extern "C" int func_00209D1C()
{
    return 0;
}


extern "C" int func_00209D24()
{
    return 0;
}


extern "C" int func_00209D2C()
{
    return 0;
}


extern "C" int func_00209D34()
{
    return 0;
}


extern "C" int func_00209D3C()
{
    return 0;
}


extern "C" int func_00209D44()
{
    return 0;
}


// NON_MATCHING: 26/391 differ, 27 edits
#ifdef NON_MATCHING
struct Loading9DData { float x; int mode; float z, width, height, depth, angle, pad; };
extern int loading9DActors asm("D_006FE6A0");
extern "C" int loading9D_func_001CBE38(...) asm("func_001CBE38");
extern "C" void loading9D_func_001CFBE4(...) asm("func_001CFBE4");
extern "C" void loading9D_func_001CFDA4(...) asm("func_001CFDA4");
extern "C" void loading9D_func_001CFE78(...) asm("func_001CFE78");
extern "C" void loading9D_func_001D024C(int, unsigned int, float) asm("func_001D024C");
extern "C" int loading9D_func_001D046C(...) asm("func_001D046C");
extern "C" void loading9D_func_001D080C(...) asm("func_001D080C");
extern "C" void loading9D_func_001D091C(...) asm("func_001D091C");
extern "C" void loading9D_func_001D0C64(...) asm("func_001D0C64");
extern "C" void loading9D_func_001D10D0(...) asm("func_001D10D0");
extern "C" void loading9D_func_001D1410(...) asm("func_001D1410");
extern "C" void loading9D_func_001D1838(...) asm("func_001D1838");
extern "C" void loading9D_func_001D18C4(...) asm("func_001D18C4");
extern "C" void loading9D_func_001D1C80(...) asm("func_001D1C80");
extern "C" void loading9D_func_001D1D5C(...) asm("func_001D1D5C");
extern "C" void loading9D_func_001D1E88(int, unsigned int, float) asm("func_001D1E88");
extern "C" void loading9D_func_001D1F74(...) asm("func_001D1F74");
extern "C" void loading9D_func_001D1FD8(...) asm("func_001D1FD8");
extern "C" void loading9D_func_001D2270(...) asm("func_001D2270");
extern "C" void loading9D_func_001D2334(...) asm("func_001D2334");
extern "C" void loading9D_func_001D2428(...) asm("func_001D2428");
extern "C" void loading9D_func_001D480C(...) asm("func_001D480C");
extern "C" float loading9D_func_001D4A3C(int, unsigned int, int) asm("func_001D4A3C");
extern "C" void loading9D_func_001D5BC8(...) asm("func_001D5BC8");
extern "C" void loading9D_func_001DC070(...) asm("func_001DC070");
extern "C" void loading9D_func_001DCD38(...) asm("func_001DCD38");
extern "C" void loading9D_func_001DCE30(...) asm("func_001DCE30");
extern "C" void loading9D_func_001DD118(...) asm("func_001DD118");
extern "C" void loading9D_func_001DD154(...) asm("func_001DD154");
extern "C" void loading9D_setBillboard__8DogModeli(...) asm("setBillboard__8DogModeli");
extern "C" float cosf(float);
extern "C" float sinf(float);
extern "C" int func_00209D4C(unsigned int arg0, int arg1, int arg2, int arg3, int arg4, unsigned int arg5) {
    struct { int sp0, sp4, pad[2]; Loading9DData data; int pad30[4]; float points[8]; } stack;
    int temp_s0, temp_s0_2, temp_s0_3, temp_s0_4;
    register float temp_f0 PS2_REG("$f0");
    float temp_f0_2;
    register float temp_f10 PS2_REG("$f10");
    register float temp_f1 PS2_REG("$f1");
    float temp_f1_2;
    register float temp_f20 PS2_REG("$f20");
    float temp_f20_2;
    register float temp_f21 PS2_REG("$f21");
    register float temp_f2 PS2_REG("$f2");
    register float temp_f3 PS2_REG("$f3");
    register float temp_f4 PS2_REG("$f4");
    register float temp_f5 PS2_REG("$f5");
    register float temp_f6 PS2_REG("$f6");
    int temp_a1;
    int temp_a1_2;
    int var_v0;
    int temp_a0;
    register int base4 PS2_REG("$4");
    int output;
    float half;
    register float temp_f7 PS2_REG("$f7");
    register float temp_f8 PS2_REG("$f8");
    register float temp_f9 PS2_REG("$f9");

    stack.sp0 = arg1;
    stack.sp4 = arg2;
    var_v0 = loading9D_func_001D046C((int)&D_007812C0, arg5);
    if (var_v0 == 0) return var_v0;
    switch (arg0) {
        case 0x1:
        case 0x6:
            loading9D_func_001CFBE4((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0x2:
            loading9D_func_001CFE78((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0x3:
            loading9D_func_001D1E88((int)&D_007812C0, arg5, *(float *)&stack.sp0);
            break;
        case 0x5:
            loading9D_func_001D024C((int)&D_007812C0, arg5, M2C_FIELD(stack.sp0, float *, 0));
            break;
        case 0xA:
            loading9D_func_001D1D5C((int)&D_007812C0, arg5, stack.sp0, stack.sp4);
            break;
        case 0xB:
            loading9D_func_001D1F74((int)&D_007812C0, arg5, stack.sp0, stack.sp4);
            break;
        case 0xC:
            loading9D_func_001D10D0((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0xD:
            loading9D_func_001D1410((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0xF:
            base4 = (int)&D_007812C0;
            loading9D_func_001DC070(base4 + 0x22220, arg5 & 0xFFFF, stack.sp0, stack.sp4);
            break;
        case 0x10:
            temp_a1 = arg5 & 0xFFFF;
            if (stack.sp0 == 0) {
                base4 = (int)&D_007812C0;
                loading9D_func_001DCD38(base4 + 0x22220, temp_a1, stack.sp4, stack.sp4);
            } else {
                base4 = (int)&D_007812C0;
                loading9D_func_001DD118(base4 + 0x22220, temp_a1, (unsigned short) stack.sp0, stack.sp4);
            }
            break;
        case 0x11:
            temp_a1_2 = arg5 & 0xFFFF;
            if (stack.sp0 == 0) {
                base4 = (int)&D_007812C0;
                loading9D_func_001DCE30(base4 + 0x22220, temp_a1_2, stack.sp4, stack.sp4);
            } else {
                base4 = (int)&D_007812C0;
                loading9D_func_001DD154(base4 + 0x22220, temp_a1_2, (unsigned short) stack.sp0, stack.sp4);
            }
            break;
        case 0x12:
            loading9D_func_001D1838((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0x13:
            loading9D_func_001D18C4((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0x14:
            loading9D_func_001CFDA4((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0x19:
            loading9D_func_001D1FD8((int)&D_007812C0, (unsigned short) stack.sp0, stack.sp4, 1);
            break;
        case 0x1A:
            loading9D_func_001D1FD8((int)&D_007812C0, (unsigned short) stack.sp0, stack.sp4, 0);
            break;
        case 0x1E:
            loading9D_func_001D2270((int)&D_007812C0, arg5, stack.sp0, stack.sp4);
            break;
        case 0x1F:
            loading9D_func_001D2334((int)&D_007812C0, arg5, stack.sp0, stack.sp4);
            break;
        case 0x28:
            temp_a0 = (int)&D_007812C0;
            if (stack.sp0 != 0) {
                loading9D_func_001D10D0(temp_a0, arg5, (int)1);
            } else {
                loading9D_func_001D1410(temp_a0, arg5, (int)1);
            }
            break;
        case 0x29:
            loading9D_func_001D2428((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0x2A:
            loading9D_setBillboard__8DogModeli((int)&loading9DActors + (loading9D_func_001CBE38((int)&D_007812C0, arg5) * 0x4D0), stack.sp0);
            break;
        case 0x32:
            temp_s0 = (int)&D_007812C0;
            loading9D_func_001D1C80(temp_s0, arg5, (void *)0x18, &stack.data.x);
            stack.data.mode = stack.sp0;
            loading9D_func_001D1D5C(temp_s0, arg5, (int)0x18, &stack.data.x);
            break;
        case 0x33:
            temp_s0_2 = (int)&D_007812C0;
            loading9D_func_001D1C80(temp_s0_2, arg5, (void *)0x18, &stack.data.x);
            stack.data.mode = stack.sp0;
            if (stack.sp0 == (int)4) {
                stack.data.height = *(float *)&stack.sp4;
            }
            loading9D_func_001D1D5C(temp_s0_2, arg5, (int)0x18, &stack.data.x);
            break;
        case 0x34:
            temp_s0_3 = (int)&D_007812C0;
            loading9D_func_001D1D5C(temp_s0_3, arg5, (int)0x18, stack.sp0);
            if (M2C_FIELD(stack.sp0, int *, 0) == 1) {
                loading9D_func_001D480C(temp_s0_3, arg5);
            }
            break;
        case 0x35:
            output = stack.sp0;
            stack.data = *(Loading9DData *)stack.sp4;
            temp_s0_4 = (int)&D_007812C0;
            M2C_FIELD(output, int *, 4) = 4;
            M2C_FIELD(output, float *, 0x10) = (stack.data.width + stack.data.height + stack.data.depth) / 3.0f;
            half = 0.5f;
            loading9D_func_001D1D5C(temp_s0_4, arg5, 0x18, output);
            temp_f20 = cosf(stack.data.angle);
            temp_f21 = stack.data.width;
            temp_f0 = sinf(stack.data.angle);
            temp_f21 *= half;
            temp_f1 = stack.data.depth * half;
            temp_f3 = -temp_f0;
            temp_f9 = stack.data.x;
            temp_f8 = stack.data.z;
            temp_f2 = -temp_f21;
            temp_f5 = temp_f0 * temp_f21;
            temp_f4 = -temp_f1;
            temp_f6 = temp_f20 * temp_f1;
            temp_f2 = temp_f20 * temp_f2;
            temp_f1 = temp_f0 * temp_f1;
            temp_f10 = temp_f20 * temp_f4;
            temp_f0 = temp_f0 * temp_f4;
            temp_f3 = temp_f3 * temp_f21;
            temp_f20 = temp_f20 * temp_f21;
            stack.points[4] = temp_f20 + temp_f1 + temp_f9;
            stack.points[5] = temp_f3 + temp_f6 + temp_f8;
            stack.points[0] = temp_f2 + temp_f0 + temp_f9;
            stack.points[1] = temp_f5 + temp_f10 + temp_f8;
            stack.points[2] = temp_f20 + temp_f0 + temp_f9;
            stack.points[3] = temp_f3 + temp_f10 + temp_f8;
            stack.points[6] = temp_f2 + temp_f1 + temp_f9;
            stack.points[7] = temp_f5 + temp_f6 + temp_f8;
            loading9D_func_001D1D5C(temp_s0_4, arg5, (int)0x1003, &stack.points[0]);
            loading9D_func_001CFBE4(temp_s0_4, arg5, &stack.data.x);
            loading9D_func_001D5BC8(temp_s0_4, 0, arg5);
            break;
        case 0x36:
            M2C_FIELD(stack.sp0, float *, 0) = loading9D_func_001D4A3C((int)&D_007812C0, arg5, 0);
            break;
        case 0x37:
            loading9D_func_001D080C((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0x38:
            loading9D_func_001D091C((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0x39:
            loading9D_func_001D0C64((int)&D_007812C0, arg5, stack.sp0);
            break;
        case 0:
        case 4:
        case 7:
        case 8:
        case 9:
        case 14:
        case 21:
        case 22:
        case 23:
        case 24:
        case 27:
        case 28:
        case 29:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        default: break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00209D4C);
#endif

// NON_MATCHING: 146/272 differ, 26 relocs differ (size 0x440, game 0x458), 93 edits
#ifdef NON_MATCHING
extern int A368_actors asm("D_006FE6A0");
extern double D_00301070;
extern double D_00301078;
extern double D_00301080;
extern double D_00301088;
extern "C" int A368_func_001CBE38(...) asm("func_001CBE38");
extern "C" int A368_func_001D046C(...) asm("func_001D046C");
extern "C" int A368_func_001D1720(...) asm("func_001D1720");
extern "C" int A368_func_001D17C8(...) asm("func_001D17C8");
extern "C" int A368_func_001D1A5C(...) asm("func_001D1A5C");
extern "C" int A368_func_001D1BEC(...) asm("func_001D1BEC");
extern "C" int A368_func_001D1C80(...) asm("func_001D1C80");
extern "C" int A368_func_001D217C(...) asm("func_001D217C");
extern "C" int A368_func_001DC48C(...) asm("func_001DC48C");
extern "C" int A368_func_001DD00C(...) asm("func_001DD00C");
extern "C" int A368_func_001DD194(...) asm("func_001DD194");
extern "C" void A368_rotate(int, float, float) asm("func_001F6B28");
extern "C" int A368_func_00213E78(...) asm("func_00213E78");
extern "C" long long fptodp(float);
extern "C" float dptofp(long long);
extern "C" long long dpadd(long long, long long);
extern "C" long long dpsub(long long, long long);
extern "C" int dpcmp(long long, long long);
extern "C" int func_0020A368(unsigned int arg0, int arg1, int arg2, int arg3, int arg4, unsigned int arg5) {
    struct { int sp0, sp4, pad[2]; } stack;
    float vec[4];
    float vec2[4];
    float temp_f0_2;
    float var_f12;
    float var_f13;
    float temp_f0;
    float temp_f1;
    float temp_f1_2;
    float temp_f2;
    float temp_f2_2;
    float var_f20;
    int temp_a1;
    register int base4 PS2_REG("$4");
    double temp_v0_5;
    double temp_v0_6;
    int var_a0;
    int var_v0;
    double temp_s2;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_7;
    int temp_v0_8;

    var_a0 = 0;
    stack.sp0 = arg2;
    stack.sp4 = arg3;
    if ((unsigned int) (arg0 - 0x19) >= 2U) {
        var_v0 = A368_func_001D046C((int)&D_007812C0, arg5);
        if (var_v0 != 0) {
            var_a0 = A368_func_001CBE38((int)&D_007812C0, arg5);
            goto block_3;
        }
        /* Duplicate return node #28. Try simplifying control flow for better match */
        return var_v0;
    }
block_3:
    var_v0 = 0;
    switch (arg0) {
    case 1:
        temp_v0 = (int)&A368_actors + (var_a0 * 0x4D0);
        M2C_FIELD(arg1, float *, 0) = (float) M2C_FIELD(temp_v0, float *, 0x40);
        M2C_FIELD(arg1, float *, 4) = (float) M2C_FIELD(temp_v0, float *, 0x44);
        M2C_FIELD(arg1, float *, 8) = (float) M2C_FIELD(temp_v0, float *, 0x48);
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 23:
    case 24:
    case 27:
    case 28:
    case 29:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
block_27:
    default:
        break;
    case 2:
        temp_v0_2 = (int)&A368_actors + (var_a0 * 0x4D0);
        M2C_FIELD(arg1, float *, 0) = (float) M2C_FIELD(temp_v0_2, float *, 0x50);
        M2C_FIELD(arg1, float *, 4) = (float) M2C_FIELD(temp_v0_2, float *, 0x54);
        M2C_FIELD(arg1, float *, 8) = (float) M2C_FIELD(temp_v0_2, float *, 0x58);
        break;
    case 3:
        temp_v0_3 = (int)&A368_actors + (arg5 * 0x4D0);
        M2C_FIELD(arg1, float *, 0) = (float) M2C_FIELD(temp_v0_3, float *, 0x60);
        M2C_FIELD(arg1, float *, 4) = (float) M2C_FIELD(temp_v0_3, float *, 0x64);
        M2C_FIELD(arg1, float *, 8) = (float) M2C_FIELD(temp_v0_3, float *, 0x68);
        break;
    case 20:
        A368_func_001D1C80((int)&D_007812C0, arg5, arg1, stack.sp0);
        break;
    case 21:
        return A368_func_001D1720((int)&D_007812C0, arg5, arg1);
    case 22:
        return A368_func_001D17C8((int)&D_007812C0, arg5, stack.sp0);
    case 25:
        base4 = (int)&D_007812C0;
        A368_func_001DC48C(base4 + 0x22220, arg5 & 0xFFFF, arg1, stack.sp0);
        break;
    case 26:
        temp_a1 = arg5 & 0xFFFF;
        if (arg1 == 0) {
            base4 = (int)&D_007812C0;
            return A368_func_001DD00C(base4 + 0x22220, temp_a1, stack.sp0, stack.sp0);
        }
        base4 = (int)&D_007812C0;
        return A368_func_001DD194(base4 + 0x22220, temp_a1, (int) arg1 & 0xFFFF, stack.sp0);
    case 30:
        return A368_func_001D217C((int)&D_007812C0, arg5, arg1);
    case 40:
        temp_s2 = D_00301070;
        temp_v0_4 = (int)&A368_actors + (var_a0 * 0x4D0);
        temp_f0 = M2C_FIELD(temp_v0_4, float *, 0x40);
        temp_f1 = M2C_FIELD(temp_v0_4, float *, 0x44);
        temp_f2 = M2C_FIELD(temp_v0_4, float *, 0x48);
        vec[0] = temp_f0;
        vec2[0] = temp_f0;
        vec2[2] = temp_f2;
        vec[1] = temp_f1;
        vec[2] = temp_f2;
        vec2[1] = temp_f1;
        var_f20 = (float)((double)temp_f1 + temp_s2);
        temp_v0_5 = (double)var_f20;
        if (temp_v0_5 < D_00301078) {
            var_f20 = (float)(temp_v0_5 + D_00301080);
        }
        temp_v0_6 = (double)var_f20;
        if (temp_v0_6 > temp_s2) {
            var_f20 = (float)(temp_v0_6 - D_00301088);
        }
        vec2[1] = var_f20;
        A368_rotate((int)&vec[0], var_f20, *(float *)&stack.sp0);
        M2C_FIELD(arg1, float *, 4) = vec[1];
        M2C_FIELD(arg1, float *, 0) = vec[0];
        M2C_FIELD(arg1, float *, 0xC) = 1.0f;
        M2C_FIELD(arg1, float *, 8) = vec[2];
        break;
    case 41:
        temp_v0_7 = (int)&A368_actors + (var_a0 * 0x4D0);
        temp_f1_2 = M2C_FIELD(temp_v0_7, float *, 0x40);
        temp_f0_2 = M2C_FIELD(temp_v0_7, float *, 0x44);
        vec[0] = temp_f1_2;
        var_f12 = temp_f0_2;
        temp_f2_2 = M2C_FIELD(temp_v0_7, float *, 0x48);
        var_f13 = *(float *)&stack.sp0;
        vec2[0] = temp_f1_2;
        vec2[2] = temp_f2_2;
        vec[1] = temp_f0_2;
        vec[2] = temp_f2_2;
        vec2[1] = temp_f0_2;
block_23:
        A368_rotate((int)&vec[0], var_f12, var_f13);
        M2C_FIELD(arg1, float *, 4) = vec[1];
        M2C_FIELD(arg1, float *, 0xC) = 1.0f;
        M2C_FIELD(arg1, float *, 0) = vec[0];
        M2C_FIELD(arg1, float *, 8) = vec[2];
        break;
    case 42:
        temp_v0_8 = (int)&A368_actors + (var_a0 * 0x4D0);
        vec[0] = M2C_FIELD(temp_v0_8, float *, 0x40);
        var_f12 = *(float *)&stack.sp0;
        var_f13 = *(float *)&stack.sp4;
        vec[1] = M2C_FIELD(temp_v0_8, float *, 0x44);
        vec[2] = M2C_FIELD(temp_v0_8, float *, 0x48);
        goto block_23;
    case 43:
        A368_func_001D1A5C((int)&D_007812C0, arg5, arg1, stack.sp0);
        break;
    case 44:
        A368_func_001D1BEC((int)&D_007812C0, arg5, arg1);
        break;
    case 50:
        return A368_func_00213E78((int)&D_007A4440, (unsigned int) arg1);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020A368);
#endif

extern "C" int func_0020A7C0()
{
    return 0;
}


extern "C" int func_0020A7C8()
{
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301070);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301078);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301080);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301088);

extern "C" int func_0020A7D0(unsigned int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    struct { int sp0, sp4, sp8, spC, sp10, sp14; } stack;
    int temp_v0;
    int temp_v0_2;
    int var_v0;
    int temp_v0_3;
    int temp_s0;
    unsigned short tid;
    int base;
    int base20;
    register int p8 PS2_REG("$20");
    register int p14 PS2_REG("$21");
    register int base4 PS2_REG("$4");
    register int value2 PS2_REG("$18") = arg2;
    register int value3 PS2_REG("$19") = arg3;
    register int value5 PS2_REG("$17") = arg5;
    stack.sp0 = arg1;
    stack.sp4 = arg4;
    switch (arg0) {
    case 1:
        loadingA7_func_001DB520(loadingA7_func_001D2D00((int)&D_007812C0, value5), stack.sp0, value2);
        break;
    case 2:
        base = (int)&D_007812C0;
        if (loadingA7_func_001D2D00(base, value2) == 0) {
            loadingA7_func_001CC044(base, -1U, value2, stack.sp4, value3 & 0xFFFF, value5);
            loadingA7_func_001DB520(loadingA7_func_001D2D00(base, value2), (int)0x1000, (int)&stack);
        }
        break;
    case 3:
        base = (int)&D_007812C0;
        var_v0 = 0;
        if (loadingA7_func_001D2D00(base, value2) == 0) {
            loadingA7_func_001CC044(base, -1U, value2, (*(int *)stack.sp4), value3 & 0xFFFF, value5);
            temp_v0 = loadingA7_func_001D2D00(base, value2);
            loadingA7_func_001DB520(temp_v0, (int)0x1000, (int)&stack);
            loadingA7_func_001DB520(temp_v0, (int)0x40, stack.sp4 + 4);
            break;
        }
        /* Duplicate return node #25. Try simplifying control flow for better match */
        return var_v0;
    case 4:
        base = (int)&D_007812C0;
        if ((loadingA7_func_001D2D00(base, value2) == 0) && (loadingA7_func_001C7DA8(base, value2) == 0)) {
            var_v0 = loadingA7_func_001C98C0(base, value3);
            if (var_v0 != 0) {
                p8 = (int)&stack.sp8;
                loadingA7_func_001DC48C(base + 0x22220, (int) (unsigned short) stack.sp0, (int)0xF, p8);
                if ((int) stack.sp8 == 0xFFFF) {
                    stack.sp8 = 0x800;
                }
                loadingA7_func_001CC044(base, -1U, value2, value3, (unsigned short) stack.sp0, value5);
                loadingA7_func_001C6CCC(base, (int)5, (int)&stack.spC);
                if (value3 == stack.spC) {
                    loadingA7_func_001CAA14(base, (unsigned short)stack.sp8, value2, value5);
                    loadingA7_func_001D1C80(base, (unsigned int) value2, (int)3, (int)&stack.sp10);
                }
                temp_v0_2 = loadingA7_func_001D2D00(base, value2);
                loadingA7_func_001DB520(temp_v0_2, (int)0x1000, p8);
                loadingA7_func_001DB520(temp_v0_2, (int)0x40, (int) (int)&stack.sp4);
                break;
            }
        } else {
            break;
        }
        /* Duplicate return node #25. Try simplifying control flow for better match */
        return var_v0;
    case 5:
        base20 = (int)&D_007812C0;
        tid = (unsigned short)stack.sp0;
        p14 = (int)&stack.sp14;
        temp_s0 = base20 + 0x22220;
        stack.sp10 = value2;
        loadingA7_func_001DC48C(temp_s0, tid, (int)0xF, p14);
        loadingA7_func_001DC48C(temp_s0, tid, (int)0xB, (int) (int)&stack.spC);
        temp_v0_3 = loadingA7_func_001C6FE0(base20, 0, 5, value3);
        loadingA7_func_001CC044(base20, -1U, temp_v0_3, stack.sp10, tid, (int) stack.sp4);
        loadingA7_func_001C6CCC(base20, (int)5, (int) (int)&stack.sp10);
        if (value2 == stack.sp10) {
            loadingA7_func_001CABD4(base20, (unsigned short)stack.sp14, stack.spC, temp_v0_3, stack.sp4);
        }
        loadingA7_func_001DB520(loadingA7_func_001D2D00(base20, temp_v0_3), (int)0x1000, p14);
        break;
    case 10:
        loadingA7_func_001CEA44((int)&D_007812C0, 0);
        break;
    case 11:
        loadingA7_func_001CC970((int)&D_007812C0, value2);
        break;
    case 20:
        base4 = (int)&D_007812C0;
        loadingA7_func_001DBA3C(base4 + 0x18C00, 1, value2, stack.sp0);
        break;
    case 21:
        base4 = (int)&D_007812C0;
        loadingA7_func_001DBA3C(base4 + 0x18C00, 0, value2, stack.sp0);
        break;
    case 22:
        base4 = (int)&D_007812C0;
        loadingA7_func_001DBA3C(base4 + 0x18C00, 2, stack.sp0, 0);
        break;
    case 23:
        return loadingA7_func_001D2D7C((int)&D_007812C0, 2, stack.sp0);
    case 0: default: break;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020ABFC);

extern "C" int func_0020B268()
{
    return 0;
}


extern "C" int func_0020B270()
{
    return 0;
}


extern "C" int func_0020B278()
{
    return 0;
}


extern "C" int func_0020B280()
{
    return 0;
}


extern "C" int func_0020B288()
{
    return 0;
}


extern "C" int func_0020B290()
{
    return 0;
}


extern "C" int func_0020B298()
{
    return 0;
}


extern "C" int func_0020B2A0()
{
    return 0;
}


extern "C" int func_0020B2A8()
{
    return 0;
}


extern "C" int func_0020B2B0()
{
    return 0;
}


extern "C" int func_0020B2B8()
{
    return 0;
}


extern "C" int func_0020B2C0()
{
    return 0;
}


extern "C" int func_0020B2C8()
{
    return 0;
}


extern "C" int func_0020B2D0()
{
    return 0;
}


extern "C" int func_0020B2D8()
{
    return 0;
}


extern "C" int func_0020B2E0()
{
    return 0;
}


extern "C" int func_0020B2E8()
{
    return 0;
}


extern "C" int func_0020B2F0()
{
    return 0;
}


extern "C" int func_0020B2F8()
{
    return 0;
}


extern "C" int func_0020B300()
{
    return 0;
}


extern "C" int func_0020B308()
{
    return 0;
}


extern "C" int func_0020B310()
{
    return 0;
}


extern "C" int func_0020B318()
{
    return 0;
}


extern "C" int func_0020B320()
{
    return 0;
}


extern "C" int func_0020B328()
{
    return 0;
}


extern "C" int func_0020B330()
{
    return 0;
}


extern "C" int func_0020B338()
{
    return 0;
}


extern "C" int func_0020B340()
{
    return 0;
}


extern "C" int func_0020B348()
{
    return 0;
}


extern "C" int func_0020B350()
{
    return 0;
}


extern "C" int func_0020B358()
{
    return 0;
}


extern "C" int func_0020B360()
{
    return 0;
}


extern "C" int func_0020B368()
{
    return 0;
}


extern "C" int func_0020B370()
{
    return 0;
}


extern "C" int func_0020B378()
{
    return 0;
}


extern "C" int func_0020B380()
{
    return 0;
}


extern "C" int func_0020B388()
{
    return 0;
}


extern "C" int func_0020B390()
{
    return 0;
}


extern "C" int func_0020B398()
{
    return 0;
}


extern "C" int func_0020B3A0()
{
    return 0;
}


extern "C" int func_0020B3A8()
{
    return 0;
}


extern "C" int func_0020B3B0()
{
    return 0;
}


extern "C" int func_0020B3B8()
{
    return 0;
}


extern "C" void X_func_001F0E90(int, float, int) asm("func_001F0E90");
extern "C" int X_func_001F6B8C(float, float) asm("func_001F6B8C");
extern "C" void X_func_001F0F9C(int, float, float) asm("func_001F0F9C");
extern "C" void X_func_001F10A4(int, float, int) asm("func_001F10A4");
extern "C" float X_func_001CFB48(void *, int, float *) asm("func_001CFB48");

extern "C" int func_0020B3C0(unsigned int arg0, int arg1, float *arg2, float *arg3)
{
    if (X_hasActor_001D046C(&D_007812C0, arg1) == 0) {
        return 0;
    }
    switch (arg0) {
    case 1:
        X_func_001F0E90(arg1, *arg2, 0);
        break;
    case 2: {
        float v = *arg2;
        X_func_001F0E90(arg1, v, X_func_001F6B8C(v, *arg3));
        break;
    }
    case 3:
        X_func_001F0E90(arg1, *arg2, (int)arg3);
        break;
    case 4:
        X_func_001F0F9C(arg1, *arg2, *arg3);
        break;
    case 5:
        X_func_001F10A4(arg1, *arg2, (int)arg3);
        break;
    case 6:
        X_func_001F0F9C(arg1, X_func_001CFB48(&D_007812C0, arg1, arg2), *arg3);
        break;
    case 7:
        X_func_001F10A4(arg1, X_func_001CFB48(&D_007812C0, arg1, arg2), (int)arg3);
        break;
    case 0:
    default:
        break;
    }
    return 0;
}

extern "C" int func_0020B520()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020B528);

extern "C" int func_0020BCC8()
{
    return 0;
}


extern "C" int func_0020BCD0()
{
    return 0;
}


extern "C" int func_0020BCD8()
{
    return 0;
}


extern "C" int func_0020BCE0()
{
    return 0;
}


extern "C" int func_0020BCE8()
{
    return 0;
}


extern "C" int func_0020BCF0()
{
    return 0;
}


extern "C" int func_0020BCF8()
{
    return 0;
}


extern "C" int func_0020BD00()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020BD08);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301178);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301180);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301188);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301190);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00301198);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_003011A0);

extern "C" int func_0020C4C8(unsigned int arg0, int arg1, int arg2)
{
    switch (arg0) {
    case 10:
        X_func_0016366C((int)&D_007B2140, arg1, arg2 != 0);
        break;
    case 20:
        return X_func_00163B20((int)&D_007B2140, arg1);
    case 21:
        X_func_00163B48((int)&D_007B2140, arg1);
        break;
    case 22:
        return X_func_00163B80((int)&D_007B2140, arg1);
    case 23:
        X_func_00163BB8((int)&D_007B2140, arg1);
        break;
    case 24:
        *(int *)((char *)&D_007B2294 + arg1 * 0x3C) = arg2;
        break;
    case 30:
        X_func_00162AFC((int)&D_007B2140, arg1, arg2 != 0);
        break;
    case 40:
        return X_func_00164078((int)&D_007B2140, arg1) != 0;
    case 50:
        X_func_001C5A5C((int)&D_007812C0, arg1 != 0);
        break;
    case 0:
    default:
        break;
    }
    return 0;
}

extern "C" int func_0020C5C4()
{
    return 0;
}


extern "C" int func_0020C5CC()
{
    return 0;
}


extern "C" int func_0020C5D4()
{
    return 0;
}


extern "C" int func_0020C5DC()
{
    return 0;
}


extern "C" int func_0020C5E4()
{
    return 0;
}


extern "C" int func_0020C5EC()
{
    return 0;
}


extern "C" int func_0020C5F4()
{
    return 0;
}


extern "C" int func_0020C5FC()
{
    return 0;
}


extern "C" int func_0020C604()
{
    return 0;
}


extern "C" int func_0020C60C()
{
    return 0;
}


extern "C" int func_0020C614()
{
    return 0;
}


extern "C" int func_0020C61C()
{
    return 0;
}


extern "C" int func_0020C624()
{
    return 0;
}


extern "C" int func_0020C62C()
{
    return 0;
}


extern "C" int func_0020C634()
{
    return 0;
}


extern "C" int func_0020C63C()
{
    return 0;
}


extern "C" int func_0020C644()
{
    return 0;
}


extern "C" int func_0020C64C()
{
    return 0;
}


extern "C" int func_0020C654()
{
    return 0;
}


extern "C" int func_0020C65C()
{
    return 0;
}


extern "C" int func_0020C664()
{
    return 0;
}


extern "C" int func_0020C66C()
{
    return 0;
}


extern "C" int func_0020C674()
{
    return 0;
}


extern "C" int func_0020C67C()
{
    return 0;
}


extern "C" int func_0020C684()
{
    return 0;
}


extern "C" int func_0020C68C()
{
    return 0;
}


extern "C" int func_0020C694()
{
    return 0;
}


extern "C" int func_0020C69C()
{
    return 0;
}


extern "C" int func_0020C6A4()
{
    return 0;
}


extern "C" int func_0020C6AC()
{
    return 0;
}


extern "C" int func_0020C6B4()
{
    return 0;
}


extern "C" int func_0020C6BC()
{
    return 0;
}


extern "C" int func_0020C6C4()
{
    return 0;
}


extern "C" int func_0020C6CC()
{
    return 0;
}


extern "C" int func_0020C6D4()
{
    return 0;
}


extern "C" int func_0020C6DC()
{
    return 0;
}


extern "C" int func_0020C6E4()
{
    return 0;
}


extern "C" int func_0020C6EC()
{
    return 0;
}


extern "C" int func_0020C6F4()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020C6FC);

extern "C" int X_func_0017F5E8(...) asm("func_0017F5E8");
extern "C" int X_func_00182BE8(...) asm("func_00182BE8");
extern "C" int X_func_001E7724(...) asm("func_001E7724");
extern "C" int X_func_001E79C0(...) asm("func_001E79C0");
extern "C" int X_func_001F438C(...) asm("func_001F438C");
extern "C" int loadingSetMode(int, unsigned int) asm("func_00211318");
extern "C" int X_getInfo__9BedMemoryP13BedMemoryInfoi(...) asm("getInfo__9BedMemoryP13BedMemoryInfoi");
extern int D_007A3574;
extern int D_007B2580;
extern "C" int func_0020D428(unsigned int arg0, int arg1)
{
  int info[4];
  int base;
  int *field;
  int *field2;
  int temp_s0;
  int new_var;
  int temp_v0;
  X_getInfo__9BedMemoryP13BedMemoryInfoi((int) (&D_006E9800), (int) info, 0);
  switch (arg0)
  {
    case 1:
      base = (int) (field2 = (int *)&D_007812C0);
      if (X_func_001E7D7C((int) (&D_007A3D80), *((int *) (((char *) base) + 0x222B4))) == 0)
    {
      field = (int *) (base + 0x222B4);
      X_func_0017F5E8((int) (&D_007B2580), 1);
      if (X_func_001E7D7C((int) (&D_007A3D80), *field) == 0)
      {
        temp_v0 = X___builtin_new(0x80);
        X_func_001F438C(temp_v0, arg1);
        new_var = -1;
        X_func_001E71FC((int) (&D_007A3D80), 1, new_var, 1, 0, temp_v0, 0, (int) field, 0x11);
        return 0xCCCCCCCD;
      }
    }
      break;

    case 2:
      base = (int) (&D_007812C0);
      field2 = (int *) (base + 0x222B4);
      if (X_func_001E7D7C((int) (&D_007A3D80), *field2) != 0)
    {
      X_func_001E7724((int) (&D_007A3D80), *field2);
    }
      temp_v0 = loadingSetMode((int) (&D_007A4440), 5U);
      if (temp_v0 == 0)
    {
      return 0;
    }
      return 0xCCCCCCCC;

    case 3:
      return X_func_001E7D7C((int) (&D_007A3D80), *((int *) (&D_007A3574)));

    case 4:
      temp_s0 = *((int *) (&D_007A3574));
      if (X_func_001E7D7C((int) (&D_007A3D80), temp_s0) == 0)
    {
      return ((*((int *) (((char *) X_func_001E79C0((int) (&D_007A3D80), temp_s0)) + 8))) >= 0x65) ? (0) : (0xCCCCCCCC);
    }
      break;

    case 5:
      return X_func_00182BE8();

    case 0:

    case 6:

    case 7:

    case 8:

    case 9:

    case 10:
      break;

  }

  return 0;
}
