#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001814CC(int, int) asm("func_001814CC");
extern "C" int Xiii_func_0018156C(int, int) asm("func_0018156C");
extern int D_006E9204;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_DIntr(...) asm("DIntr");
extern "C" int X_D_002DBE98(...) asm("D_002DBE98");
extern "C" int X_FlushCache(...) asm("FlushCache");
extern "C" int X_alloc__9BedMemoryiPCciii(...) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_func_0017F584(...) asm("func_0017F584");
extern "C" int X_func_0017F9AC(...) asm("func_0017F9AC");
extern "C" int X_func_0017FA90(...) asm("func_0017FA90");
extern "C" int X_func_0017FB5C(...) asm("func_0017FB5C");
extern "C" int X_func_00180B9C(...) asm("func_00180B9C");
extern "C" int X_func_001814CC(...) asm("func_001814CC");
extern "C" int X_func_0018156C(...) asm("func_0018156C");
extern "C" int X_func_0018173C(...) asm("func_0018173C");
extern "C" int X_func_0018185C(...) asm("func_0018185C");
extern "C" int X_func_001818B4(...) asm("func_001818B4");
extern "C" int X_func_00181920(...) asm("func_00181920");
extern "C" int X_func_00181998(...) asm("func_00181998");
extern "C" int X_func_00181A70(...) asm("func_00181A70");
extern "C" int X_func_00181AB4(...) asm("func_00181AB4");
extern "C" int X_func_00181BF4(...) asm("func_00181BF4");
extern "C" int X_func_00181CE4(...) asm("func_00181CE4");
extern "C" int X_func_00181EF4(...) asm("func_00181EF4");
extern "C" int X_func_0018210C(...) asm("func_0018210C");
extern "C" int X_func_00182148(...) asm("func_00182148");
extern "C" int X_func_00182414(...) asm("func_00182414");
extern "C" int X_func_001824C8(...) asm("func_001824C8");
extern "C" int X_func_0018252C(...) asm("func_0018252C");
extern "C" int X_func_001825E4(...) asm("func_001825E4");
extern "C" int X_func_00182818(...) asm("func_00182818");
extern "C" int X_func_001828C4(...) asm("func_001828C4");
extern "C" int X_func_00182928(...) asm("func_00182928");
extern "C" int X_func_0018294C(...) asm("func_0018294C");
extern "C" int X_func_00182A6C(...) asm("func_00182A6C");
extern "C" int X_func_00182BB4(...) asm("func_00182BB4");
extern "C" int X_func_00182BE8(...) asm("func_00182BE8");
extern "C" int X_func_00182BFC(...) asm("func_00182BFC");
extern "C" int X_func_00182C08(...) asm("func_00182C08");
extern "C" int X_func_00182F3C(...) asm("func_00182F3C");
extern "C" int X_func_00182FC8(...) asm("func_00182FC8");
extern "C" int X_func_00182FDC(...) asm("func_00182FDC");
extern "C" int X_func_00182FEC(...) asm("func_00182FEC");
extern "C" int X_func_001830DC(...) asm("func_001830DC");
extern "C" int X_func_001830F0(...) asm("func_001830F0");
extern "C" int X_func_001830FC(...) asm("func_001830FC");
extern "C" int X_func_0018316C(...) asm("func_0018316C");
extern "C" int X_func_00183194(...) asm("func_00183194");
extern "C" int X_func_001831A8(...) asm("func_001831A8");
extern "C" int X_func_001831C4(...) asm("func_001831C4");
extern "C" int X_func_001831CC(...) asm("func_001831CC");
extern "C" int X_func_001831F8(...) asm("func_001831F8");
extern "C" int X_func_001832A4(...) asm("func_001832A4");
extern "C" int X_func_001832B8(...) asm("func_001832B8");
extern "C" int X_func_001C6CCC(...) asm("func_001C6CCC");
extern "C" int X_func_001C9C1C(...) asm("func_001C9C1C");
extern "C" int X_func_002155F4(...) asm("func_002155F4");
extern "C" int X_func_0023BE68(...) asm("func_0023BE68");
extern "C" int X_func_0023C0F8(...) asm("func_0023C0F8");
extern "C" int X_func_0023C228(...) asm("func_0023C228");
extern "C" int X_func_0023C260(...) asm("func_0023C260");
extern "C" int X_func_0023C328(...) asm("func_0023C328");
extern "C" int X_func_0023C3C0(...) asm("func_0023C3C0");
extern "C" int X_func_0023C510(...) asm("func_0023C510");
extern "C" int X_func_0023CCA8(...) asm("func_0023CCA8");
extern "C" int X_func_0023DCC8(...) asm("func_0023DCC8");
extern "C" int X_func_002437F8(...) asm("func_002437F8");
extern "C" int X_func_00243E60(...) asm("func_00243E60");
extern "C" int X_func_00243ED8(...) asm("func_00243ED8");
extern "C" int X_func_00243F28(...) asm("func_00243F28");
extern "C" int X_func_00243F70(...) asm("func_00243F70");
extern "C" int X_func_00243FB8(...) asm("func_00243FB8");
extern "C" int X_func_00244028(...) asm("func_00244028");
extern "C" int X_func_00249DE0(...) asm("func_00249DE0");
extern "C" int X_func_00249E08(...) asm("func_00249E08");
extern "C" int X_func_0024A508(...) asm("func_0024A508");
extern "C" int X_func_0024A8C8(...) asm("func_0024A8C8");
extern "C" int X_func_0024A958(...) asm("func_0024A958");
extern "C" int X_func_0024AE60(...) asm("func_0024AE60");
extern "C" int X_func_0024F780(...) asm("func_0024F780");
extern "C" int X_func_00253DA0(...) asm("func_00253DA0");
extern "C" int X_func_00267530(...) asm("func_00267530");
extern "C" int X_heapFree__FPv(...) asm("heapFree__FPv");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern "C" int X_sceIpuRestartDMA(...) asm("sceIpuRestartDMA");
extern "C" int X_sceIpuStopDMA(...) asm("sceIpuStopDMA");
extern "C" int X_sceMpegGetPicture(...) asm("sceMpegGetPicture");
extern "C" int X_sceMpegInit(...) asm("sceMpegInit");
extern "C" int X_sceMpegReset(...) asm("sceMpegReset");
extern int D_00298F00;
extern int D_00298F04;
extern int D_00298F08;
extern int D_00298F10;
extern int D_00298F14;
extern int D_00298F18;
extern int D_00298F1C;
extern int D_00298F20;
extern int D_00298F24;
extern int D_00298F28;
extern int D_00298F2C;
extern int D_00298F30;
extern int D_00298F34;
extern int D_00298F38;
extern int D_00298F3C;
extern int D_00298F40;
extern int D_00298F44;
extern int D_00298F48;
extern int D_00298F4C;
extern int D_00298F50;
extern int D_00298F54;
extern int D_00298F58;
extern int D_00298F5C;
extern int D_00298F60;
extern int D_00298F64;
extern int D_00298FC0;
extern int D_00298FD0;
extern int D_00298FD4;
extern int D_00298FD8;
extern int D_00298FDC;
extern int D_00298FE0;
extern int D_002DBE98;
extern int D_002F3228;
extern int D_006E9200;
extern int D_006E9208;
extern int D_006E9248;
extern int D_006E926C;
extern int D_006E9270;
extern int D_006E9274;
extern int D_006E9278;
extern int D_006E927C;
extern int D_006E9280;
extern int D_006E9288;
extern int D_006E928C;
extern int D_006E9290;
extern int D_006E9294;
extern int D_006E9298;
extern int D_006E92AC;
extern int D_006E92B0;
extern int D_006E9800;
extern int D_007812C0;

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001809D8);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180A90);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180B30);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180B9C);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180BE4);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180CA8);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180CE0);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180D94);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180E00);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180E54);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180EA8);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180EEC);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00180F44);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001810F4);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181128);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181150);

extern "C" void func_001811B0(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x0)) == 1) {
        (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
        (*(int *)(int *)((char *)(arg0) + 0x28)) = 0xE00;
    }
}


extern "C" void func_001811D0(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x28)) = 0xE00;
    X_func_0018210C(arg1);
}


extern "C" void func_001811F4(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x38)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x38)) + arg1);
}


extern "C" void func_00181204(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x3C)) = arg1;
}


extern "C" void func_0018120C(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x0)) == 1) {
        if ((*(int *)(int *)((char *)(arg0) + 0x10)) != 0) {
            if ((*(int *)(int *)((char *)(arg0) + 0x14)) < 0) {
                X_func_001830DC(1);
            } else if (X_func_00182BE8() == (*(int *)(int *)((char *)(arg0) + 0x14))) {
                X_func_001830DC(0);
            } else {
                X_func_001830DC(1);
                (*(int *)(int *)((char *)(arg0) + 0x14)) = -1;
            }
        }
        X_func_00182FEC((*(int *)(int *)((char *)(arg0) + 0x20)));
        X_func_00182C08();
    }
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001812A8);

extern "C" void func_00181494(void) {
}

extern "C" void func_0018149C(void) {
}

extern "C" int func_001814A4()
{
    return 0;
}


extern "C" int func_001814AC(int arg0, int arg1, int arg2, int arg3)
{
    M2C_FIELD(arg0, int *, 0x2C) = arg2;
    M2C_FIELD(arg0, int *, 0x30) = arg3;
    return Xiii_func_001814CC(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001814CC);

extern "C" int func_0018154C(int arg0, int arg1, int arg2, int arg3)
{
    M2C_FIELD(arg0, int *, 0x2C) = arg2;
    M2C_FIELD(arg0, int *, 0x30) = arg3;
    return Xiii_func_0018156C(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_0018156C);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181644);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001816B0);

extern "C" int func_00181714(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x10)) == 0;
    (*(int *)(int *)((char *)(arg0) + 0x10)) = temp_v0;
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(arg0) + 0x14)) = -1;
    }
    return (*(int *)(int *)((char *)(arg0) + 0x10));
}


extern "C" int func_00181734()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_0018173C);

extern "C" int func_0018176C()
{
    return X_func_00182BFC();
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181780);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_0018182C);

extern "C" int func_00181848()
{
    return X_func_0023DCC8();
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_0018185C);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001818B4);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181920);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181998);

extern "C" int func_001819F4(int arg0)
{
    int var_v1;
    int temp_a0;

    temp_a0 = (int)&D_006E9288 + (arg0 << 6);
    var_v1 = 0;
    if ((*(int *)(int *)((char *)(temp_a0) + 0x8)) >= 0) {
        var_v1 = ~(*(int *)(int *)((char *)(temp_a0) + 0x4)) != 0;
    }
    return var_v1;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181A24);

extern "C" void func_00181A70(int arg0)
{
    int temp_v0;
    int temp_s0;

    temp_s0 = (int)&D_006E9288 + (arg0 << 6);
    temp_v0 = (*(int *)(int *)((char *)(temp_s0) + 0x14));
    if (temp_v0 != 0) {
        X_func_0018316C(temp_v0);
        (*(int *)(int *)((char *)(temp_s0) + 0x14)) = 0;
    }
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181AB4);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181BF4);

INCLUDE_RODATA("asm/nonmatchings/snd/rxmpeg", D_002F3228);

INCLUDE_RODATA("asm/nonmatchings/snd/rxmpeg", D_002F3230);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181C14);

extern "C" void func_00181CE4()
{
    X_heapFree__FPv(D_00298F40);
    D_00298F40 = 0;
}


extern "C" int func_00181D14()
{
    return ((D_00298F40 + 0x3F) & ~0x3F) + (D_006E9278 * (D_00298F5C * D_00298F58) * 4);
}


extern "C" int func_00181D54(int arg0, int arg1, int arg2)
{
    int temp_s1;
    int temp_s2;
    int var_s3;

    var_s3 = 1;
    temp_s1 = (*(int *)(int *)((char *)(arg1) + 0xC));
    temp_s2 = (*(int *)(int *)((char *)(arg1) + 0x8));
    X_func_0024A8C8();
    if (X_func_001831CC(arg2) < temp_s1) {
        var_s3 = 0;
    } else {
        X_func_001831F8(arg2, temp_s2, temp_s1);
    }
    X_func_0024A958();
    return var_s3;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181DD4);

extern "C" int func_00181EEC()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181EF4);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00181F5C);

extern "C" int func_00182094()
{
    X_func_0024A8C8();
    D_00298F24 = 0;
    X_sceIpuStopDMA((int)&D_006E9248);
    X_func_0024A958();
    return 1;
}


extern "C" int func_001820D0()
{
    X_func_0024A8C8();
    X_sceIpuRestartDMA((int)&D_006E9248);
    D_00298F24 = 1;
    X_func_0024A958();
    return 1;
}


extern "C" void func_0018210C(int arg0)
{
    D_00298FE0 = arg0;
}


extern "C" void func_00182118(int arg0)
{
    D_00298FD0 = arg0;
}


extern "C" int func_00182124()
{
    return D_00298FD0;
}


extern "C" int func_00182130()
{
    return D_00298F64;
}


extern "C" int func_0018213C()
{
    return D_00298FD4;
}


extern "C" void func_00182148(int arg0)
{
    D_00298FD4 = arg0;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00182154);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001822C4);

extern "C" int func_0018240C()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00182414);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_0018247C);

extern "C" void func_001824B4(int arg0, int arg1)
{
    D_00298F58 = arg0;
    D_00298F5C = arg1;
}


extern "C" void func_001824C8()
{
    D_00298F08 = 0;
    X_func_00182414();
    if (D_00298F04 >= 0) {
        X_func_002437F8(D_00298F04);
        D_00298F08 = 0;
        D_00298F04 = -1;
    }
    X_func_00181998(0);
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_0018252C);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001825E4);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00182818);

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_001828C4);

extern "C" void func_00182920(void) {
}

extern "C" void func_00182928()
{
    X_func_001825E4();
    X_func_0018252C();
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_0018294C);

extern "C" int func_00182A60()
{
    return D_00298F54;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00182A6C);

extern "C" void func_00182B7C()
{
    if (D_00298F04 >= 0) {
        D_00298F38 = 1;
        X_func_00243E60(D_00298F04, 0);
    }
}


extern "C" void func_00182BB4()
{
    X_func_0018252C();
    X_func_00182818();
    D_00298F3C = 0;
    D_00298F38 = 0;
}


extern "C" int func_00182BE8()
{
    return ((*(int *)((int)&D_006E9208)) < 0) ? 0 : (*(int *)((int)&D_006E9208));
}

extern "C" int func_00182BFC()
{
    return D_00298F3C;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00182C08);

extern "C" int func_00182EF4()
{
    return D_00298F48;
}


extern "C" int func_00182F00()
{
    int temp_v0;

    temp_v0 = D_006E9274;
    D_006E9274 = 0;
    return temp_v0;
}


extern "C" int func_00182F14()
{
    return D_006E9270 ^ D_00298F4C ^ 1;
}


extern "C" int func_00182F30()
{
    return D_00298F4C;
}


extern "C" void func_00182F3C(int arg0)
{
    D_00298F4C = arg0 != 0;
}


extern "C" int func_00182F4C()
{
    return D_006E9200;
}


extern "C" int func_00182F58()
{
    return (long) (*(int *)&D_006E9204);
}

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00182F64);

extern "C" int func_00182FBC()
{
    return D_00298F50;
}


extern "C" void func_00182FC8(void) {
}

extern "C" int func_00182FD0()
{
    return D_00298F34;
}


extern "C" void func_00182FDC(int arg0)
{
    D_00298F34 = arg0 != 0;
}


INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00182FEC);

extern "C" int func_00183018(int arg0)
{
    int var_v0;

    var_v0 = -1;
    if (arg0 == 0) {
        var_v0 = D_006E9290;
    }
    return var_v0;
}


extern "C" int func_00183030(int arg0)
{
    int var_v0;

    var_v0 = -1;
    if (arg0 == 0) {
        var_v0 = D_006E928C;
    }
    return var_v0;
}


extern "C" int func_00183048(int arg0)
{
    int var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = D_006E92AC;
    }
    return var_v0;
}


extern "C" int func_00183060(int arg0)
{
    int var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = (*(int *)((int)&D_006E92B0));
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/snd/rxmpeg", func_00183078);

extern "C" int func_00183094(int arg0)
{
    int var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = D_006E9294;
    }
    return var_v0;
}


extern "C" int func_001830AC(int arg0)
{
    int var_v0;

    var_v0 = 0;
    if (arg0 == 0) {
        var_v0 = (*(int *)((int)&D_006E9298));
    }
    return var_v0;
}

extern "C" int func_001830C4()
{
    return D_00298F10;
}


extern "C" int func_001830D0()
{
    return D_00298F04;
}


extern "C" int func_001830DC(int arg0)
{
    int temp_v0;

    temp_v0 = D_00298F14;
    D_00298F14 = arg0;
    return temp_v0;
}


extern "C" int func_001830F0()
{
    return D_00298F18;
}


INCLUDE_RODATA("asm/nonmatchings/snd/rxmpeg", D_002F3258);
