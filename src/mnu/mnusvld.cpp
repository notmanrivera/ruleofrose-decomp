#include "include_asm.h"
extern "C" int Xii_func_001A6BF8(int) asm("func_001A6BF8");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_0018C190(int, int) asm("func_0018C190");
extern "C" int Xiiii_func_0018C4D8(int, int, int) asm("func_0018C4D8");
extern int D_002A45C0;
extern int D_002A64E0;
extern int _9MagSystem$m_current_system;
extern "C" int Xiiii_func_001A4E34(int, int, int) asm("func_001A4E34");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_alloc__9BedMemoryiPCciii(...) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_func_00118980__9MagSystemiiiiii(...) asm("func_00118980__9MagSystemiiiiii");
extern "C" int X_func_001189BC__9MagSystemiiiii(...) asm("func_001189BC__9MagSystemiiiii");
extern "C" int X_func_00131550(...) asm("func_00131550");
extern "C" int X_func_00134730(...) asm("func_00134730");
extern "C" int X_func_001348B0(...) asm("func_001348B0");
extern "C" int X_func_00134CD0(...) asm("func_00134CD0");
extern "C" int X_func_00135088(...) asm("func_00135088");
extern "C" int X_func_0013511C(...) asm("func_0013511C");
extern "C" int X_func_001351B0(...) asm("func_001351B0");
extern "C" int X_func_00135418(...) asm("func_00135418");
extern "C" int X_func_00135494(...) asm("func_00135494");
extern "C" int X_func_00135594(...) asm("func_00135594");
extern "C" int X_func_0018330C(...) asm("func_0018330C");
extern "C" int X_func_0018741C(...) asm("func_0018741C");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001874AC(...) asm("func_001874AC");
extern "C" int X_func_001874F4(...) asm("func_001874F4");
extern "C" int X_func_0018BB8C(...) asm("func_0018BB8C");
extern "C" int X_func_0018BCC0(...) asm("func_0018BCC0");
extern "C" int X_func_0018BD94(...) asm("func_0018BD94");
extern "C" int X_func_0018C068(...) asm("func_0018C068");
extern "C" int X_func_0018C130(...) asm("func_0018C130");
extern "C" int X_func_0018C2E4(...) asm("func_0018C2E4");
extern "C" int X_func_0018F744(...) asm("func_0018F744");
extern "C" int X_func_0018FEBC(...) asm("func_0018FEBC");
extern "C" int X_func_001A1244(...) asm("func_001A1244");
extern "C" int X_func_001A1514(...) asm("func_001A1514");
extern "C" int X_func_001A4E34(...) asm("func_001A4E34");
extern "C" int X_func_001A5C80(...) asm("func_001A5C80");
extern "C" int X_func_001A5D04(...) asm("func_001A5D04");
extern "C" int X_func_001A5D74(...) asm("func_001A5D74");
extern "C" int X_func_001A5ED0(...) asm("func_001A5ED0");
extern "C" int X_func_001A65F0(...) asm("func_001A65F0");
extern "C" int X_func_001A6BF8(...) asm("func_001A6BF8");
extern "C" int X_func_001C5094(...) asm("func_001C5094");
extern "C" int X_func_001C51E0(...) asm("func_001C51E0");
extern "C" int X_func_001C5240(...) asm("func_001C5240");
extern "C" int X_func_001D6078(...) asm("func_001D6078");
extern "C" int X_func_001D68A0(...) asm("func_001D68A0");
extern "C" int X_func_002155F4(...) asm("func_002155F4");
extern "C" int X_heapFree__FPv(...) asm("heapFree__FPv");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_strlen(...) asm("strlen");
extern const char D_002F91E8[];
extern const char D_002F91F8[];
extern int D_002A4530;
extern int D_006E9800;
extern int D_006E9840;
extern int D_007812C0;
extern int D_007B2060;

// func_001A4E88 .. func_001A4FF0 were game/mnudlg's: config/splits_manual.tsv
extern "C" int Xiiiii_func_001A4DB8(int, int, int, int) asm("func_001A4DB8");
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A4E88);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A4F60);

extern "C" void func_001A4FF0(int arg0)
{
    Xiiiii_func_001A4DB8((int) arg0, arg0 + 0x7F4, 0x10, 0x100);
    Xiiiii_func_001A4DB8((int) arg0, arg0 + 0x834, 0x10, 0x100);
}

extern "C" void func_001A5034(int arg0)
{
    Xiiii_func_001A4E34(arg0, arg0 + 0x7F4, 0x10);
    Xiiii_func_001A4E34(arg0, arg0 + 0x834, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5070);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5368);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5540);

extern "C" void func_001A5558(int arg0)
{
    if (((*(int *)(int *)((char *)(arg0) + 0x0)) != 0) && ((*(int *)(int *)((char *)(arg0) + 0x7D8)) == 1)) {
        (*(int *)(int *)((char *)(arg0) + 0x44)) = 4;
    }
}


extern "C" int func_001A557C()
{
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9118);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9120);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5584);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A59B8);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5A34);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9130);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9140);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9150);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9160);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9170);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9180);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9190);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91B0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91C0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91D0);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5AF4);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5BF4);

extern "C" int func_001A5C78(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x2734));
}


INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91E8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91F8);

extern "C" void func_001A5C80(int arg0)
{
    int temp_s0;

    temp_s0 = arg0 + 0x147C;
    X_func_0018F744(temp_s0, (int)&D_002A4530, "data/mnurpk/mnusvld.rpk");
    do {

    } while (X_func_0018FEBC(temp_s0) == 0);
}


extern "C" int func_001A5CC4()
{
    return X_func_001A5ED0();
}


extern "C" void func_001A5CD8(int arg0, int arg1)
{
    int temp_v0;

    temp_v0 = arg0 + 0x1474;
    (*(int *)(int *)((char *)(arg0) + 0x1D64)) = arg1;
    if (arg1 != 0) {
        (*(int *)(int *)((char *)(temp_v0) + 0x4D0)) = arg1;
        X_func_0018BD94(temp_v0);
    }
}


INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5D04);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5D74);

extern "C" int func_001A5D90()
{
    return 0;
}


extern "C" int func_001A5D98()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5DA0);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5ED0);

extern "C" int func_001A65F0(int arg0)
{
    int var_a0;
    int var_v1;
    int temp_v0;

    var_a0 = 0x1400;
    var_v1 = 8;
    do {
        temp_v0 = arg0 + var_a0;
        var_a0 += 4;
        var_v1 -= 1;
        M2C_FIELD(temp_v0, int *, 4) = 0;
    } while (var_v1 >= 0);
    Xii_func_001A6BF8(arg0);
    M2C_FIELD(arg0, int *, 0x142C) = 0xC;
    M2C_FIELD(arg0, int *, 0x1430) = 5;
    M2C_FIELD(arg0, int *, 0x1448) = 0x24;
    M2C_FIELD(arg0, int *, 0x24F0) = 0;
    return 0;
}

extern "C" void func_001A665C(int arg0)
{
    int temp_v0;
    int temp_s1;

    temp_s1 = arg0 + 0x1474;
    M2C_FIELD(arg0, int *, 0x1D60) = (int) (*(int *)&_9MagSystem$m_current_system);
    M2C_FIELD(temp_s1, int *, 0x4B0) = (int)&D_002A45C0;
    Xiii_func_0018C190(temp_s1, (int)&D_002A64E0);
    temp_v0 = M2C_FIELD(arg0, int *, 0x24E8);
    if (temp_v0 != 0) {
        if (temp_v0 == 1) {
            Xiiii_func_0018C4D8(temp_s1, 0x3E, 1);
        }
    } else {
        Xiiii_func_0018C4D8(temp_s1, 0x3E, 3);
    }
    M2C_FIELD(temp_s1, int *, 4) = 1;
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A66F0);

extern "C" int func_001A6764(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x2740)) == 0) {
        X_func_002155F4(D_002F91E8, 0x2C4, D_002F91F8);
    }
    X_memset((*(int *)(int *)((char *)(arg0) + 0x2740)), 0, 0x3000);
    X_func_001D6078((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x2740)));
    X_func_001A1514(arg0, (*(int *)(int *)((char *)(arg0) + 0x2740)));
    return (*(int *)(int *)((char *)(arg0) + 0x2740));
}


extern "C" int func_001A67D8(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x2740)) == 0) {
        X_func_002155F4(D_002F91E8, 0x2D7, D_002F91F8);
    }
    X_func_001D68A0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x2740)));
    return 1;
}

// ---- 0x1A6830-0x1A90EC: once unk/001A6830, the same file as the code above
// (config/splits_manual.tsv); its declarations as they were there:
extern "C" void Xvp_func_001AEBC8(void *) asm("func_001AEBC8");
struct SprAE9F4 {
    unsigned char m_unk[0x8EC];
    ~SprAE9F4() asm("func_0018BC18");
};
struct Sub1B64_AE9F4 {
    unsigned char m_unk[0x104];
    ~Sub1B64_AE9F4() asm("func_001A0684");
};
struct MsgAE9F4 {
    unsigned char m_unk[0x3BC];
    ~MsgAE9F4() asm("func_00183B24");
};
struct Base1_AE9F4 {
    unsigned char m_pad00[0x98];
    SprAE9F4 m_spr0;
    SprAE9F4 m_spr1;
    SprAE9F4 m_spr2;
    unsigned char m_pad1B5C[8];
    Sub1B64_AE9F4 m_1B64;
    inline ~Base1_AE9F4() {}
};
struct Base2_AE9F4 {
    MsgAE9F4 m_msg[2];
    inline ~Base2_AE9F4() {}
};
struct ObjAE9F4 : public Base1_AE9F4, public Base2_AE9F4 {
    unsigned char m_pad23E0[0xA0];
    int m_2480;
    ~ObjAE9F4() asm("func_001AE9F4");
};
extern "C" int Xvp_snprintf(void *, int, const char *, ...) asm("snprintf");
extern "C" char *Xvp_strcpy(char *, const char *) asm("strcpy");
extern "C" unsigned int Xvp_strlen(const char *) asm("strlen");
extern int D_002F9428;
extern int D_002F9430;
static inline unsigned int padTrigU_F40(int p) { return *(unsigned short *)((char *)p + 0x7A); }
struct EntAEC50 {
    int unk0;
    const char *unk4;
    char pad[0x10];
};
extern EntAEC50 X_D_002ACA20_AEC50[] asm("D_002ACA20");
extern "C" void Xvp_func_0018F744(void *, void *, const char *) asm("func_0018F744");
extern "C" int Xvp_func_0018FEBC(void *) asm("func_0018FEBC");
extern "C" void Xvp_func_001AB5E4(void *) asm("func_001AB5E4");
extern "C" void Xvp_func_001AB6F4(void *) asm("func_001AB6F4");
struct MsgAB4E0 {
    unsigned char m_unk[0x3BC];
    ~MsgAB4E0() asm("func_00183B24");
};
struct SprAB4E0 {
    unsigned char m_unk[0x8FC];
    ~SprAB4E0() asm("func_0018BC18");
};
struct PadAB4E0 {
    unsigned char m_pad[0x58];
};
struct BaseAB4E0 {
    MsgAB4E0 m_msg[2];
    inline ~BaseAB4E0() {}
};
struct ObjAB4E0 : public PadAB4E0, public BaseAB4E0 {
    SprAB4E0 m_spr;
    int m_10CC;
    ~ObjAB4E0() asm("func_001AB4E0");
};
extern "C" void Xvp_func_0018BC18(void *, int) asm("func_0018BC18");
extern "C" void Xvp_func_001AD870(void *) asm("func_001AD870");
extern "C" void Xvp_func_001AD940(void *) asm("func_001AD940");
struct MsgAD72C {
    unsigned char m_unk[0x3BC];
    ~MsgAD72C() asm("func_00183B24");
};
struct ObjAD72C {
    MsgAD72C m_msg[2];
    unsigned char m_pad778[0x93C];
    int m_10B4;
    ~ObjAD72C() asm("func_001AD72C");
};
extern int D_007A3210;
extern int D_007A4440;
static inline int *sysFlags_F130()
{
    char *p = (char *)&D_007A4440;
    return *(int **)(p + 0xDC20);
}
extern "C" void Xv___builtin_delete_9150(void *) asm("__builtin_delete");
extern "C" int X_func_0018BC18(...) asm("func_0018BC18");
extern "C" int X_func_001A0684(...) asm("func_001A0684");
extern "C" int X_func_001A12A8(...) asm("func_001A12A8");
extern "C" int X_func_001A5A34(...) asm("func_001A5A34");
extern "C" int X_func_001A9258(...) asm("func_001A9258");
extern "C" int X_func_001AB4E0(...) asm("func_001AB4E0");
extern "C" int X_func_0018C190_1(int, int) asm("func_0018C190");
extern int D_002A8848;
extern int D_002AAD70;
struct SubABA98 {
    int unk0;
    int unk4;
    char pad8[0x4B0 - 8];
    int vtbl;
};
struct ObjABA98 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char pad20[0x7D0 - 0x20];
    SubABA98 sub;
    char padC84[0x10BC - (0x7D0 + sizeof(SubABA98))];
    int sys;
};
struct EntEF9C {
    int unk0;
    char pad[0x18 - 4];
};
extern EntEF9C X_D_002ACA20_EF9C[] asm("D_002ACA20");
struct EntEF14 {
    int unk0;
    char pad[0x18 - 4];
};
extern EntEF14 X_D_002ACA20_EF14[] asm("D_002ACA20");
struct EntEE8C {
    int unk0;
    char pad[0x18 - 4];
};
extern EntEE8C X_D_002ACA20[] asm("D_002ACA20");
extern "C" int X_func_00279C98_68E0(char *, const char *, ...) asm("func_00279C98");
struct Ent68E0 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    char pad[0x2C - 0x14];
};
struct Sub68E0 {
    char pad[0x2500];
    Ent68E0 arr[12];
};
struct Obj68E0 {
    char pad[8];
    Sub68E0 sub;
};
extern "C" int X_func_00279C98_1(char *, const char *, ...) asm("func_00279C98");
struct Ent6858 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    char pad[0x2C - 0x14];
};
struct Sub6858 {
    char pad[0x2500];
    Ent6858 arr[12];
};
struct Obj6858 {
    char pad[8];
    Sub6858 sub;
};
extern "C" int X_func_001AF024(...) asm("func_001AF024");
extern "C" int X_func_001AF3F0(...) asm("func_001AF3F0");
extern "C" int X_func_001DC48C(...) asm("func_001DC48C");
extern "C" void Xv_func_001AE574(int) asm("func_001AE574");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xii_func_0018BC18(int, int) asm("func_0018BC18");
extern "C" void Xv_func_001ADFE4(int) asm("func_001ADFE4");
extern "C" int Xiiii_func_001A6C90(int, int, int) asm("func_001A6C90");
extern "C" int Xii_func_0018741C(int) asm("func_0018741C");
extern "C" int Xiii_func_001AF44C(int, int) asm("func_001AF44C");
extern "C" int Xii_func_0018330C(int) asm("func_0018330C");
extern "C" int Xii_func_0018BB8C(int) asm("func_0018BB8C");
extern "C" int Xii_func_001A066C(int) asm("func_001A066C");
extern "C" int Xii_func_001AEB7C(int) asm("func_001AEB7C");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_001A97F4(int) asm("func_001A97F4");
extern "C" int Xiii_func_0018BCC0(int, int) asm("func_0018BCC0");
extern "C" int Xiii_func_0018C190(int, int) asm("func_0018C190");
extern int D_002A7858;
extern int D_002A80C0;
extern int D_002ABB08;
extern int D_002ABCE8;
extern int D_002AC7B8;
extern int D_002AC980;
extern int D_006FE04C;
extern int _9MagSystem$m_current_system;
extern "C" int Xii_func_0018FEBC(int) asm("func_0018FEBC");
extern "C" int Xiiii_func_0018F744(int, int, int) asm("func_0018F744");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00118980__9MagSystemiiiiii(...) asm("func_00118980__9MagSystemiiiiii");
extern "C" int X_func_00131184(...) asm("func_00131184");
extern "C" int X_func_001311BC(...) asm("func_001311BC");
extern "C" int X_func_00131550(...) asm("func_00131550");
extern "C" int X_func_00134730(...) asm("func_00134730");
extern "C" int X_func_001348B0(...) asm("func_001348B0");
extern "C" int X_func_00135088(...) asm("func_00135088");
extern "C" int X_func_0013511C(...) asm("func_0013511C");
extern "C" int X_func_001351B0(...) asm("func_001351B0");
extern "C" int X_func_00135594(...) asm("func_00135594");
extern "C" int X_func_0017F264(...) asm("func_0017F264");
extern "C" int X_func_0017F308(...) asm("func_0017F308");
extern "C" int X_func_0017F5E8(...) asm("func_0017F5E8");
extern "C" int X_func_0017F8FC(...) asm("func_0017F8FC");
extern "C" int X_func_001832E8(...) asm("func_001832E8");
extern "C" int X_func_0018330C(...) asm("func_0018330C");
extern "C" int X_func_0018741C(...) asm("func_0018741C");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001874AC(...) asm("func_001874AC");
extern "C" int X_func_001874F4(...) asm("func_001874F4");
extern "C" int X_func_0018BB8C(...) asm("func_0018BB8C");
extern "C" int X_func_0018BCC0(...) asm("func_0018BCC0");
extern "C" int X_func_0018BD94(...) asm("func_0018BD94");
extern "C" int X_func_0018C068(...) asm("func_0018C068");
extern "C" int X_func_0018C130(...) asm("func_0018C130");
extern "C" int X_func_0018C2E4(...) asm("func_0018C2E4");
extern "C" int X_func_0018C4D8(...) asm("func_0018C4D8");
extern "C" int X_func_0018C6C4(...) asm("func_0018C6C4");
extern "C" int X_func_0018D7EC(...) asm("func_0018D7EC");
extern "C" int X_func_0018F060(...) asm("func_0018F060");
extern "C" int X_func_0018F09C(...) asm("func_0018F09C");
extern "C" int X_func_0018F0B4(...) asm("func_0018F0B4");
extern "C" int X_func_0018F1F4(...) asm("func_0018F1F4");
extern "C" int X_func_0018F41C(...) asm("func_0018F41C");
extern "C" int X_func_0018F744(...) asm("func_0018F744");
extern "C" int X_func_0018F808(...) asm("func_0018F808");
extern "C" int X_func_0018F9CC(...) asm("func_0018F9CC");
extern "C" int X_func_0018FAB4(...) asm("func_0018FAB4");
extern "C" int X_func_0018FBB0(...) asm("func_0018FBB0");
extern "C" int X_func_0018FEBC(...) asm("func_0018FEBC");
extern "C" int X_func_001A066C(...) asm("func_001A066C");
extern "C" int X_func_001A1244(...) asm("func_001A1244");
extern "C" int X_func_001A1658(...) asm("func_001A1658");
extern "C" int X_func_001A1C8C(...) asm("func_001A1C8C");
extern "C" int X_func_001A59B8(...) asm("func_001A59B8");
extern "C" int X_func_001A5AF4(...) asm("func_001A5AF4");
extern "C" int X_func_001A5BF4(...) asm("func_001A5BF4");
extern "C" int X_func_001A5CC4(...) asm("func_001A5CC4");
extern "C" int X_func_001A5CD8(...) asm("func_001A5CD8");
extern "C" int X_func_001A5DA0(...) asm("func_001A5DA0");
extern "C" int X_func_001A6BF8(...) asm("func_001A6BF8");
extern "C" int X_func_001A6C90(...) asm("func_001A6C90");
extern "C" int X_func_001A6FE8(...) asm("func_001A6FE8");
extern "C" int X_func_001A7088(...) asm("func_001A7088");
extern "C" int X_func_001A7498(...) asm("func_001A7498");
extern "C" int X_func_001A90DC(...) asm("func_001A90DC");
extern "C" int X_func_001A90E4(...) asm("func_001A90E4");
extern "C" int X_func_001A9828(...) asm("func_001A9828");
extern "C" int X_func_001A9844(...) asm("func_001A9844");
extern "C" int X_func_001AB474(...) asm("func_001AB474");
extern "C" int X_func_001AB598(...) asm("func_001AB598");
extern "C" int X_func_001AB5E4(...) asm("func_001AB5E4");
extern "C" int X_func_001AB66C(...) asm("func_001AB66C");
extern "C" int X_func_001AB680(...) asm("func_001AB680");
extern "C" int X_func_001AB6AC(...) asm("func_001AB6AC");
extern "C" int X_func_001AB6F4(...) asm("func_001AB6F4");
extern "C" int X_func_001AB720(...) asm("func_001AB720");
extern "C" int X_func_001ABA44(...) asm("func_001ABA44");
extern "C" int X_func_001ABA98(...) asm("func_001ABA98");
extern "C" int X_func_001ABB24(...) asm("func_001ABB24");
extern "C" int X_func_001AC5B0(...) asm("func_001AC5B0");
extern "C" int X_func_001AD7D4(...) asm("func_001AD7D4");
extern "C" int X_func_001AD90C(...) asm("func_001AD90C");
extern "C" int X_func_001AD940(...) asm("func_001AD940");
extern "C" int X_func_001AD96C(...) asm("func_001AD96C");
extern "C" int X_func_001ADBD8(...) asm("func_001ADBD8");
extern "C" int X_func_001ADC0C(...) asm("func_001ADC0C");
extern "C" int X_func_001ADC6C(...) asm("func_001ADC6C");
extern "C" int X_func_001ADCD8(...) asm("func_001ADCD8");
extern "C" int X_func_001ADDD0(...) asm("func_001ADDD0");
extern "C" int X_func_001AE024(...) asm("func_001AE024");
extern "C" int X_func_001AE188(...) asm("func_001AE188");
extern "C" int X_func_001AE1BC(...) asm("func_001AE1BC");
extern "C" int X_func_001AE1E8(...) asm("func_001AE1E8");
extern "C" int X_func_001AE2D8(...) asm("func_001AE2D8");
extern "C" int X_func_001AE318(...) asm("func_001AE318");
extern "C" int X_func_001AE328(...) asm("func_001AE328");
extern "C" int X_func_001AE330(...) asm("func_001AE330");
extern "C" int X_func_001AE5BC(...) asm("func_001AE5BC");
extern "C" int X_func_001AE640(...) asm("func_001AE640");
extern "C" int X_func_001AE674(...) asm("func_001AE674");
extern "C" int X_func_001AE6A0(...) asm("func_001AE6A0");
extern "C" int X_func_001AE7F0(...) asm("func_001AE7F0");
extern "C" int X_func_001AE7F8(...) asm("func_001AE7F8");
extern "C" int X_func_001AE848(...) asm("func_001AE848");
extern "C" int X_func_001AE868(...) asm("func_001AE868");
extern "C" int X_func_001AEB7C(...) asm("func_001AEB7C");
extern "C" int X_func_001AEC50(...) asm("func_001AEC50");
extern "C" int X_func_001AED5C(...) asm("func_001AED5C");
extern "C" int X_func_001AEE50(...) asm("func_001AEE50");
extern "C" int X_func_001AF21C(...) asm("func_001AF21C");
extern "C" int X_func_001AF44C(...) asm("func_001AF44C");
extern "C" int X_func_001AF5E0(...) asm("func_001AF5E0");
extern "C" int X_func_001B1CD4(...) asm("func_001B1CD4");
extern "C" int X_func_001B2F64(...) asm("func_001B2F64");
extern "C" int X_func_001B3534(...) asm("func_001B3534");
extern "C" int X_func_001B3E20(...) asm("func_001B3E20");
extern "C" int X_func_001B3E28(...) asm("func_001B3E28");
extern "C" int X_func_001B4488(...) asm("func_001B4488");
extern "C" int X_func_001B5C20(...) asm("func_001B5C20");
extern "C" int X_func_001B64C4(...) asm("func_001B64C4");
extern "C" int X_func_001BA3A0(...) asm("func_001BA3A0");
extern "C" int X_func_001BA8E4(...) asm("func_001BA8E4");
extern "C" int X_func_001BB12C(...) asm("func_001BB12C");
extern "C" int X_func_001BB4F0(...) asm("func_001BB4F0");
extern "C" int X_func_001BBCFC(...) asm("func_001BBCFC");
extern "C" int X_func_001BC370(...) asm("func_001BC370");
extern "C" int X_func_001C5094(...) asm("func_001C5094");
extern "C" int X_func_001C5168(...) asm("func_001C5168");
extern "C" int X_func_001C51E0(...) asm("func_001C51E0");
extern "C" int X_func_001C5240(...) asm("func_001C5240");
extern "C" int X_func_001C8214(...) asm("func_001C8214");
extern "C" int X_func_001DD00C(...) asm("func_001DD00C");
extern "C" int X_func_00279C98(...) asm("func_00279C98");
extern "C" int X_setDisplay448__9MagSystem(...) asm("setDisplay448__9MagSystem");
extern "C" int X_strcpy(...) asm("strcpy");
extern "C" int X_strlen(...) asm("strlen");
extern const char D_002F9248[];
extern const char D_002F9268[];
extern const char D_002F9278[];
extern int D_002A7798;
extern int D_002A87E8;
extern int D_002ABAD8;
extern int D_002ABDB8;
extern int D_002AC4E0;
extern int D_002AC788;
extern int D_002ACA20;
extern int D_002B5F38;
extern int D_002B60C0;
extern int D_006E9840;
extern int D_007812AC;
extern int D_007812C0;
extern int D_007A34CC;
extern int D_007A34CE;
extern int D_007B205C;
extern int D_007B2060;
extern int D_007B2580;

extern "C" int func_001A6830(int arg0, int arg1)
{
    return (unsigned int) ~(*(int *)(int *)((char *)(((arg1 * 0x2C) + arg0)) + 0x2508)) >> 0x1F;
}


extern "C" void func_001A6858(Obj6858 *arg0, int arg1, char *arg2)
{
    X_func_00279C98_1(
        arg2, D_002F9248, D_002F9268, D_002F9278,
        arg1,
        arg0->sub.arr[arg1].f0,
        arg0->sub.arr[arg1].f4,
        arg0->sub.arr[arg1].f8,
        arg0->sub.arr[arg1].fC,
        arg0->sub.arr[arg1].f10
    );
}

extern "C" void func_001A68E0(Obj68E0 *arg0, int arg1, char *arg2)
{
    X_func_00279C98_68E0(
        arg2, D_002F9248, D_002F9268, D_002F9278,
        arg1,
        arg0->sub.arr[arg1].f0,
        arg0->sub.arr[arg1].f4,
        arg0->sub.arr[arg1].f8,
        arg0->sub.arr[arg1].fC,
        arg0->sub.arr[arg1].f10
    );
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A6968);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9248);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9268);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9278);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A6AB8);

extern "C" void func_001A6BF8(int arg0)
{
    int temp_a0;
    int temp_a1;
    int temp_a2;
    int temp_a3;
    int temp_t0;
    int temp_t1;
    int temp_v1;
    int var_t8;
    int var_t9;

    var_t8 = 0;
    var_t9 = 0xB;
    do {
        temp_v1 = var_t8 + 0x2500;
        temp_t0 = var_t8 + 0x2510;
        temp_t1 = var_t8 + 0x2520;
        var_t8 += 0x2C;
        temp_a1 = arg0 + 8;
        temp_a2 = arg0 + 0xC;
        temp_a3 = arg0 + 0x10;
        temp_a0 = arg0 + 0x14;
        var_t9 -= 1;
        *(int *)(temp_a1 + temp_v1) = -1;
        *(int *)(temp_a2 + temp_v1) = -1;
        *(int *)(temp_a3 + temp_v1) = -1;
        *(int *)(temp_a0 + temp_v1) = -1;
        *(int *)(temp_a1 + temp_t0) = -1;
        *(int *)(temp_a2 + temp_t0) = -1;
        *(int *)(temp_a3 + temp_t0) = -1;
        *(int *)(temp_a0 + temp_t0) = -1;
        *(int *)(temp_a1 + temp_t1) = -1;
        *(int *)(temp_a2 + temp_t1) = -1;
        *(int *)(temp_a3 + temp_t1) = -1;
    } while (var_t9 >= 0);
}


INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92A8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92B0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92B8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92C0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92C8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92D0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92D8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92E0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92E8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92F0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92F8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9300);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9318);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9330);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9340);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9350);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9360);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9370);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9380);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9390);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93B0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93C0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93D0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93E0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93F0);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A6C90);

extern "C" void func_001A6FE8(int arg0)
{
    int i;

    for (i = 0; i < M2C_FIELD(arg0, int *, 0x142C); i++) {
        Xiiii_func_001A6C90(arg0, i, i);
    }
}

extern "C" int func_001A7040(unsigned char arg0)
{
    unsigned int temp_v0;

    temp_v0 = arg0 & 0xFF;
    return ((temp_v0 >> 4) * 0xA) + (temp_v0 & 0xF);
}

extern "C" int func_001A7060(int arg0)
{
    return ((arg0 / 10) * 0x10) + (arg0 % 10);
}


INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A7088);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A7418);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A7498);

extern "C" void *func_001A7B90(void *arg0, const unsigned char *arg1)
{
    char buf[64];
    int count = 0;

    while (arg1[0] == 0x81 && arg1[1] == 0x40) {
        arg1 += 2;
        count++;
    }
    buf[0] = '\0';
    for (int i = 0; i < count; i++) {
        const char *s = (const char *)&D_002F9428;
        Xvp_strcpy(buf + Xvp_strlen(buf), s);
    }
    Xvp_snprintf(arg0, 0x40, (const char *)&D_002F9430, buf, arg1, 0);
    return arg0;
}

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9428);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9430);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9440);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A7C54);

extern "C" int func_001A7F40(int arg0, int arg1)
{
    int temp_v1;
    int var_s2;

    temp_v1 = M2C_FIELD(arg0, int *, 0x1454);
    var_s2 = 0;
    switch (temp_v1) {                              
    case 13:
        break;
    case 0:
        M2C_FIELD(arg0, int *, 0x1404) = 0;
        M2C_FIELD(arg0, int *, 0x1454) = 0xD;
        X_func_001A6BF8();
        X_func_001A6FE8(arg0);
        break;
    case 17:
        M2C_FIELD(arg0, int *, 0x1454) = 0;
        break;
    case 1:
        M2C_FIELD(arg0, int *, 0x1454) = 0xD;
        break;
    }
    if ((padTrigU_F40(arg1) >> 0xD) & 1) {
        var_s2 = 2;
        X_func_0017F8FC((int)&D_007B2580, 2);
    }
    return var_s2;
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8000);

// NON_MATCHING: 85/125 differ, 8 relocs differ (size 0x1F4, game 0x1EC), 17 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_001A6FE8(int) asm("func_001A6FE8");
extern "C" int Xii_func_001A7088(int) asm("func_001A7088");
extern "C" int Xiii_func_001A1658(int, int) asm("func_001A1658");
extern "C" int Xiii_func_001A5DA0(int, int) asm("func_001A5DA0");
extern "C" int Xiiiu_func_001A7498(int, int, unsigned int) asm("func_001A7498");
extern "C" int func_001A8730(int arg0)
{
    int temp_s1;
    int var_s1;
    int var_s2;
    unsigned int temp_v1;
    unsigned int var_v0;
    int temp_s0;
    int temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, unsigned int *, 0x1454);
    var_s2 = 0;
    switch (temp_v1) {                              
    case 0:                                         
        temp_v1_2 = arg0 + 0x1474;
        M2C_FIELD(arg0, unsigned int *, 0x1454) = 1U;
        M2C_FIELD(M2C_FIELD(temp_v1_2, int *, 0x4AC), int *, 0x4FC0) = 0;
        M2C_FIELD(M2C_FIELD(temp_v1_2, int *, 0x4AC), int *, 0x5114) = 0;
        Xiiiu_func_001A7498(arg0, 0xC, 3U);
        Xiii_func_001A5DA0(arg0, 0);
        
    case 1:                                         
        temp_s1 = M2C_FIELD(arg0, int *, 0x24E8);
        switch (temp_s1) {                          
        case 1:                                     
            if (Xiii_func_001A1658(arg0, 2) == temp_s1) {
                var_v0 = 2;
block_25:
                M2C_FIELD(arg0, unsigned int *, 0x1454) = var_v0;
            }
        default:                                    
            break;
        case 0:                                     
            if (Xiii_func_001A1658(arg0, 3) == 1) {
                var_v0 = 2;
                goto block_25;
            }
            break;
        }
        break;
    case 2:                                         
        var_s1 = 0;
        if (M2C_FIELD(arg0, int *, 0x24) == 4) {
            var_s1 = M2C_FIELD(arg0, int *, 0x1390);
        }
        M2C_FIELD(arg0, int *, 0x24E0) = var_s1;
        switch (var_s1) {                           
        case 0:                                     
            Xii_func_001A6BF8(arg0);
            Xii_func_001A6FE8(arg0);
            break;
        case 1:                                     
            if (M2C_FIELD(arg0, int *, 0x2754) != var_s1) {
                Xiii_func_001A5DA0(arg0, 1);
            }
            M2C_FIELD(arg0, int *, 0x274C) = var_s1;
            Xii_func_001A7088(arg0);
            Xii_func_001A6FE8(arg0);
            M2C_FIELD(arg0, int *, 0x1450) = 0;
            M2C_FIELD(arg0, unsigned int *, 0x1454) = 0U;
            break;
        case 2:                                     
            M2C_FIELD(arg0, unsigned int *, 0x1454) = 0U;
            M2C_FIELD(arg0, int *, 0x144C) = 6;
            break;
        }
        break;
    case 13: break;
    case 17:                                        
        var_s2 = 1;
        Xiiiu_func_001A7498(arg0, 0xC, 4U);
        M2C_FIELD(arg0, int *, 0x1450) = 0;
        var_v0 = 0xD;
        goto block_25;
    }
    var_s1 = M2C_FIELD(arg0, int *, 0x13BC);
    temp_s0 = arg0 + 0x1474;
    if (var_s1 == 1) {
        Xiiii_func_0018C4D8(temp_s0, 0x45, 0);
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB0) = var_s1;
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB4) = var_s1;
    } else {
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB0) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB4) = 0;
    }
    return var_s2;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8730);
#endif

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A891C);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8B7C);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8D44);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8E84);

extern "C" int func_001A90DC()
{
    return 0;
}


extern "C" int func_001A90E4()
{
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F95D8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F95E8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F95F8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9608);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9618);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9628);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9638);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9648);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9658);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9668);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9678);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9688);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9698);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96A8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96B8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96C8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96D8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96E8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96F8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9708);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9718);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9728);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9738);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9748);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9758);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9768);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9778);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9788);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9798);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97A8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97B8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97C8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97D8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97E8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97F8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9808);
