#include "include_asm.h"
#include "sdk/eekernel.h"
#include "sdk/libgraph.h"
#include "game/gamsnd.h"
#include "snd/sndman.h"
#include "sdk/string.h"
#include "mag/magsystem.h"
#include "game/gamman.h"
#include "system/sysnowloading.h"
extern "C" int rxGsVSync(int);
extern "C" int sceGsPutDrawEnv(sceGifTag *);
extern "C" void func_00203EA8(GamTaskBase *);
extern "C" void func_00204014(GamTaskBase *);
extern "C" void func_0020F98C(void *);
extern "C" void func_001C526C(void *);
extern "C" void func_001E7A20(GamTaskMan *);
extern "C" void update__9MagSystem(void *);
extern "C" void func_001C53D8(void *);
static inline GamTaskBase *getTaskBase(GamTaskMan *t) { return &t->m_base; }
struct SysNowLoadingCtor : public SysNowLoading {
    SysNowLoadingCtor() {
        m_texBuf = 0;
        m_dmaBuf = 0;
        m_dmaChan = 0;
        m_frame = 0;
    }
};
static inline void setVRate(int r) { MagSystem::m_v_rate = r; }
extern SysNowLoadingCtor *D_002D8FFC;
extern "C" void func_0020499C();
extern "C" void func_0020491C();
extern "C" void func_00204148();
extern "C" void func_002052AC(SysNowLoading *);
extern "C" void func_0013C928(MagScene *);
extern "C" void func_0020E3D8(int, int);
extern "C" void func_001C1B48(GamMan *);
extern "C" void func_001C204C(GamMan *, int);
extern "C" void func_00205394(SysNowLoading *);
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_atoi(...) asm("atoi");
extern "C" int X_func_0017F164(...) asm("func_0017F164");
extern "C" int X_func_002049D4(...) asm("func_002049D4");
extern "C" int X_sceDbcEnd(...) asm("sceDbcEnd");
extern "C" int X_sceDbcInit(...) asm("sceDbcInit");
extern "C" int X_sceMcEnd(...) asm("sceMcEnd");
extern "C" int X_sceMcInit(...) asm("sceMcInit");
extern "C" int X_scePad2End(...) asm("scePad2End");
extern "C" int X_scePad2Init(...) asm("scePad2Init");
extern "C" int X_startSequence__9MagSystemi(...) asm("startSequence__9MagSystemi");
extern "C" int X_strcmp(...) asm("strcmp");
extern "C" int X_term__9MagSystem(...) asm("term__9MagSystem");
extern MagSystem D_006E9840;
extern GamTaskMan D_007A3D80;
extern int D_007A4440;
extern int D_007B2140;
extern SndMan D_007B2580;
extern int D_007B45C0;

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_002043DC);

// NON_MATCHING: 1 reloc differs, 1 edits
#ifdef NON_MATCHING
extern char D_007B45D0[];
extern const char *D_002D9E18;
extern int D_002D8FF8;
void heapInit();
void *heapAlloc(int);
void *heapRealloc(void *, int);
void heapFree(void *);
static inline char *getSndName(SndMan *s) { return (char *)s->m_unk04; }
extern "C" int func_002043DC(int, char **);
extern "C" int snprintf(char *, size_t, const char *, ...);
extern "C" void func_00241B20(const char *);
extern "C" void rxSysSetBootFileName(const char *);
extern "C" int func_0025D7D0();
extern "C" void func_0025D770(int, int);
extern "C" void rxSysInit();
extern "C" void func_0023FF80(void *(*)(int));
extern "C" void func_0023FFB0(void *(*)(int));
extern "C" void func_0023FFE0(void *(*)(void *, int));
extern "C" void func_00240010(void (*)(void *));
extern "C" void rxSysAddExceptionHandler();
extern "C" void func_00243608(int);
extern "C" void func_002046D4(int);
extern "C" void func_00204864();
extern "C" void func_0020483C();
int main(int argc, char **argv)
{
    int mode;
    int handle;

    mode = func_002043DC(argc, argv);
    snprintf(D_007B45D0, 0x40, "0.1.%sn.%s.%s", D_002D9E18, "Jul 27 2006", "22:25:45");
    if (0) {
        snprintf(D_007B45D0, 0x40, "0.1.%s.%s.%s", D_002D9E18, "Jul 27 2006", "22:25:45");
    }
    func_00241B20("IOPRP300.IMG");
    rxSysSetBootFileName("cdrom0:");
    handle = func_0025D7D0();
    D_002D8FF8 = handle;
    func_0025D770(handle, 5);
    rxSysInit();
    heapInit();
    func_0023FF80(heapAlloc);
    func_0023FFB0(heapAlloc);
    func_0023FFE0(heapRealloc);
    func_00240010(heapFree);
    strcpy(getSndName(&D_007B2580), argv[0]);
    rxSysAddExceptionHandler();
    func_00243608(1);
    func_002046D4(mode);
    func_00204864();
    func_0020483C();
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/002043DC", main);
#endif

extern "C" void func_002046D4(int arg0)
{
    func_0020499C();
    func_0020491C();
    func_00204148();
    D_006E9840.func_00117DC8();
    D_002D8FFC = new SysNowLoadingCtor;
    if (D_002D8FFC != 0) {
        func_002052AC(D_002D8FFC);
        D_006E9840.func_00117F80(1, 1, 1, 1, 1, 1, 0);
        func_0013C928(&D_006E9840.m_scene);
        D_006E9840.start();
        func_0020E3D8(D_006E9840.m_unk97A6C, 1);
        func_001C1B48(&D_007812C0);
        if (arg0 != -1) {
            func_001C204C(&D_007812C0, arg0);
        }
        func_00205394(D_002D8FFC);
        SysNowLoadingCtor *p = D_002D8FFC;
        if (p != 0) {
            func_00205394(p);
            delete p;
        }
        D_007812C0.m_cursolInitFlgItem = 1;
        D_007812C0.m_cursolInitFlgStock = 1;
        D_002D8FFC = 0;
        D_006E9840.setDisplay448();
        setVRate(2);
        D_006E9840.setDisplay448();
    }
}

extern "C" void func_0020483C()
{
    X_term__9MagSystem((int)&D_006E9840);
    X_func_002049D4();
}


extern "C" void func_00204864()
{
    func_00203EA8(getTaskBase(&D_007A3D80));
    func_001E71FC(&D_007A3D80, 1, -1, 1, 0, (CmnITask *)&D_007B2140, 0, &D_007B45C0, 0);
    *T0_MODE = 0x83;
    for (;;) {
        *T0_COUNT = 0;
        func_00204014(getTaskBase(&D_007A3D80));
        func_0020F98C(&D_007A4440);
        func_001C526C(&D_007812C0);
        func_001E7A20(&D_007A3D80);
        update__9MagSystem(&D_006E9840);
        func_001C53D8(&D_007812C0);
    }
}

extern "C" void func_0020491C()
{
    sceGsDBuff db;

    sceGsResetGraph(0, 1, 2, 1);
    sceGsSetDefDBuff(&db, 0, 0x280, 0xE0, 2, 0x31, 1);
    FlushCache(0);
    rxGsVSync(0);
    sceGsPutDrawEnv(&db.giftag0);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(&db.giftag1);
    sceGsSyncPath(0, 0);
}

extern "C" void func_0020499C()
{
    X_func_0017F164((int)&D_007B2580);
    X_sceDbcInit();
    X_scePad2Init(0);
    X_sceMcInit();
}


extern "C" void func_002049D4()
{
    X_sceMcEnd();
    X_scePad2End();
    X_sceDbcEnd();
}


INCLUDE_RODATA("asm/nonmatchings/unk/002043DC", D_002FF7A0);

INCLUDE_RODATA("asm/nonmatchings/unk/002043DC", D_002FF7B0);

INCLUDE_RODATA("asm/nonmatchings/unk/002043DC", D_002FF7C0);

INCLUDE_RODATA("asm/nonmatchings/unk/002043DC", D_002FF7D0);

INCLUDE_RODATA("asm/nonmatchings/unk/002043DC", D_002FF7E0);

INCLUDE_RODATA("asm/nonmatchings/unk/002043DC", D_002FF7E8);

INCLUDE_RODATA("asm/nonmatchings/unk/002043DC", D_002FF7F8);

INCLUDE_RODATA("asm/nonmatchings/unk/002043DC", D_002FF808);

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_00204A00);
