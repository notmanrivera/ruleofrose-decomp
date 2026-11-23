#include "include_asm.h"
#include "mag/maglifepc.h"

extern "C" void X_func_0010B328__8DogActoriiPPCc(DogActor *, int, int, const char **) asm("func_0010B328__8DogActoriiPPCc");
extern const char *D_00297160[];
extern const char *D_002971A0[];
extern int D_00297220[];
extern const char *D_00297238[];

extern "C" void func_0011DF7C(MagLifePC *arg0)
{
    int id = D_00297220[arg0->m_unkDC];
    const char **tbl;
    if (arg0->m_unkDC == 4) {
        tbl = D_002971A0;
    } else {
        tbl = D_00297160;
    }
    X_func_0010B328__8DogActoriiPPCc(arg0->m_actor, 0, id, tbl);
}

extern "C" void func_0011DFD0(MagLifePC *arg0)
{
    X_func_0010B328__8DogActoriiPPCc(arg0->m_actor, 0, -1, 0);
}

extern "C" void func_0011DFF8(MagLifePC *arg0, int arg1)
{
    int wep = arg0->m_unk21C;
    if (wep == 3) {
        return X_func_0010B328__8DogActoriiPPCc(arg0->m_actor, 0, 0xA5, D_002971A0);
    }
    if (wep == 0) {
        return X_func_0010B328__8DogActoriiPPCc(arg0->m_actor, 0, -1, D_00297238);
    }
    if (arg1 == 0) {
        return X_func_0010B328__8DogActoriiPPCc(arg0->m_actor, 0, 0x19, D_00297238);
    }
    X_func_0010B328__8DogActoriiPPCc(arg0->m_actor, 0, -1, D_00297238);
}

int MagLifePC::func_0011E080()
{
    switch (m_unkEC) {
    case 1:
        return 6;
    case 2:
        return 7;
    default:
        return 5;
    }
}

extern "C" int func_0011E0AC(MagLifePC *arg0)
{
    int temp_a0 = arg0->m_unk00;
    int var_v1 = 0;
    if (((unsigned int) (temp_a0 - 1) < 0xAU) || (temp_a0 == 0xE)) {
        var_v1 = 1;
    }
    return var_v1;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011E0D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA8D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA8D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA8E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA8E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA8F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA900);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA908);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA910);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA918);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA920);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA928);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA930);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA940);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA950);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA960);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA970);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA980);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA990);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA998);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA9A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA9B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA9B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA9C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA9E8);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011E4C4);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011EA04);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011EE00);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011F0B4);

extern "C" int func_0011F4A0()
{
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EA9F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAA18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAA38);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAA48);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAA58);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011F4A8);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011F884);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011F9F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAB88);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EABA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EABC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EABD8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EABE8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EABF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAC08);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAC18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAC28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAC38);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EAC58);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_0011FF10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcmove", D_002EACC0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_001203A0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_001205DC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcmove", func_00120668);
