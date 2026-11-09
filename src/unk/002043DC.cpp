#include "include_asm.h"
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_atoi(...) asm("atoi");
extern "C" int X_func_0017F164(...) asm("func_0017F164");
extern "C" int X_func_001C526C(...) asm("func_001C526C");
extern "C" int X_func_001C53D8(...) asm("func_001C53D8");
extern "C" int X_func_001E71FC(...) asm("func_001E71FC");
extern "C" int X_func_001E7A20(...) asm("func_001E7A20");
extern "C" int X_func_00203EA8(...) asm("func_00203EA8");
extern "C" int X_func_00204014(...) asm("func_00204014");
extern "C" int X_func_002049D4(...) asm("func_002049D4");
extern "C" int X_func_0020F98C(...) asm("func_0020F98C");
extern "C" int X_sceDbcEnd(...) asm("sceDbcEnd");
extern "C" int X_sceDbcInit(...) asm("sceDbcInit");
extern "C" int X_sceMcEnd(...) asm("sceMcEnd");
extern "C" int X_sceMcInit(...) asm("sceMcInit");
extern "C" int X_scePad2End(...) asm("scePad2End");
extern "C" int X_scePad2Init(...) asm("scePad2Init");
extern "C" int X_startSequence__9MagSystemi(...) asm("startSequence__9MagSystemi");
extern "C" int X_strcmp(...) asm("strcmp");
extern "C" int X_term__9MagSystem(...) asm("term__9MagSystem");
extern "C" int X_update__9MagSystem(...) asm("update__9MagSystem");
extern int D_006E9840;
extern int D_007812C0;
extern int D_007A3D80;
extern int D_007A4440;
extern int D_007B2580;

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_002043DC);

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_002045A8);

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_002046D4);

extern "C" void func_0020483C()
{
    X_term__9MagSystem((int)&D_006E9840);
    X_func_002049D4();
}


INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_00204864);

INCLUDE_ASM("asm/nonmatchings/unk/002043DC", func_0020491C);

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
