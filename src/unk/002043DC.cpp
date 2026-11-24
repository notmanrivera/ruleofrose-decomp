#include "include_asm.h"
#include "sdk/eekernel.h"
#include "sdk/libgraph.h"
#include "game/gamsnd.h"
#define T0_MODE ((volatile unsigned int *)0x10000010)
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
extern int D_006E9840;
extern int D_007812C0;
extern GamTaskMan D_007A3D80;
extern int D_007A4440;
extern int D_007B2140;
extern int D_007B2580;
extern int D_007B45C0;

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_002043DC);

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", main);

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_002046D4);

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
