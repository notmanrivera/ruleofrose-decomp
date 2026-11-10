#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_FlushCache(...) asm("FlushCache");
extern "C" int X_SetDebugHandler(...) asm("SetDebugHandler");
extern "C" int X_alloc__9BedMemoryiPCciii(...) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_free__9BedMemoryPv(...) asm("free__9BedMemoryPv");
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
extern "C" int X_func_00204E98(...) asm("func_00204E98");
extern "C" int X_func_00205078(...) asm("func_00205078");
extern "C" int X_func_002050E8(...) asm("func_002050E8");
extern "C" int X_func_0020F140(...) asm("func_0020F140");
extern "C" int X_func_0020F1A8(...) asm("func_0020F1A8");
extern "C" int X_func_002113A4(...) asm("func_002113A4");
extern "C" int X_func_0025A9D0(...) asm("func_0025A9D0");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_rand(...) asm("rand");
extern "C" int X_sceDmaSend(...) asm("sceDmaSend");
extern "C" int X_sceGsExecLoadImage(...) asm("sceGsExecLoadImage");
extern "C" int X_sceGsSetDefLoadImage(...) asm("sceGsSetDefLoadImage");
extern "C" int X_sceGsSwapDBuff(...) asm("sceGsSwapDBuff");
extern "C" int X_sceGsSyncPath(...) asm("sceGsSyncPath");
extern "C" int X_sceGsSyncV(...) asm("sceGsSyncV");
extern const char D_002FF8D0[];
extern int D_002D90A8;
extern int D_002D90E8;
extern int D_006E9800;
extern int D_00725410;
extern int D_007812C0;
extern int D_007A4440;
extern int D_007B2140;
extern int D_007B2294;

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00204BF8);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00204CA4);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00204D38);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00204E68);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00204E98);

extern "C" void func_00205078(int arg0)
{
    int temp_s0;

    temp_s0 = arg0 + 0x230;
    X_sceGsSetDefLoadImage(temp_s0, 0x1A40, 4, 0x13, 0, 0, 0x100, 0x100);
    X_FlushCache(0);
    X_sceGsExecLoadImage(temp_s0, M2C_FIELD(arg0, int *, 0x290));
    X_sceGsSyncPath(0, 0);
}

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002050E8);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002051CC);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002052AC);

extern "C" void func_00205394(int arg0)
{
    int temp_a1;
    int temp_v0;

    X_func_002050E8();
    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x290));
    if (temp_v0 != 0) {
        X_free__9BedMemoryPv((int)&D_006E9800, temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0x290)) = 0;
    }
    temp_a1 = (*(int *)(int *)((char *)(arg0) + 0x294));
    if (temp_a1 != 0) {
        X_free__9BedMemoryPv((int)&D_006E9800, temp_a1);
        (*(int *)(int *)((char *)(arg0) + 0x294)) = 0;
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


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020544C);

extern "C" int func_00205564()
{
    return 0xCCCCCCCD;
}


INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_002FF8C0);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_002FF8D0);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_002FF8F0);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_002FF900);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00205570);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002058F0);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00205928);

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


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00206614);

extern "C" int func_00206638()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00206640);

extern "C" int func_00206944()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020694C);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002076CC);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00207AE8);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_00300598);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_003005A0);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_003005A8);

INCLUDE_RODATA("asm/nonmatchings/system/sysnowloading", D_003005B0);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020810C);

extern "C" int func_00208394()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020839C);

extern "C" int func_00208508()
{
    return 0;
}


extern "C" int func_00208510()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00208518);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00208640);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00208B10);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00208B98);

extern "C" int func_00208DB4()
{
    return 0;
}


extern "C" int func_00208DBC()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00208DC4);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00208E24);

extern "C" int func_00209090()
{
    return 0;
}


extern "C" int func_00209098()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002090A0);

extern "C" int func_002090D8()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002090E0);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00209270);

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


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00209528);

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


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002098E0);

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


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_002099BC);

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


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_00209D4C);

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020A368);

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

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020A7D0);

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


INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020B3C0);

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

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020C4C8);

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

INCLUDE_ASM("asm/nonmatchings/system/sysnowloading", func_0020D428);
