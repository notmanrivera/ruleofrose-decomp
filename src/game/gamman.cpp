#include "include_asm.h"
extern "C" void func_001CCC30(int, int);
extern "C" int func_001C0148(int, int);
extern "C" int func_001C0298(int, int);
extern "C" int func_001C02B8(int, int);
struct __attribute__((aligned(8))) DogVector {
    float m_x;
    float m_y;
    float m_z;
    float m_w;
    DogVector() {}
    DogVector(float x, float y, float z, float w)
    {
        m_x = x;
        m_y = y;
        m_z = z;
        m_w = w;
    }
};
struct PcEffParam {
    int m_kind;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    DogVector m_pos;
    float m_rot[3];
    int m_num;
    int m_pad[20];
};
extern "C" int func_00176CC8(void *, void *);
extern "C" void func_001CBA0C(void *, void *, int);
extern "C" int X_func_0018741C(...) asm("func_0018741C");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001874AC(...) asm("func_001874AC");
extern "C" int X_func_001874F4(...) asm("func_001874F4");
extern "C" int X_func_001875C0(...) asm("func_001875C0");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern int D_002B8C90;
extern "C" void func_001348B0(void *, int) asm("func_001348B0");
extern "C" void func_00135594(void *, int) asm("func_00135594");
extern "C" void *func_001D2B8C();
extern "C" void *func_001D2BA8();
extern "C" void func_00191D20(void *, int, int);
extern "C" void func_00191D74(void *, int, int);
extern "C" int func_001E7D7C(void *, int);
extern "C" int func_0013F444(void *, int);
extern "C" int func_001DC48C(void *, int, int, int *);
extern "C" int func_001DD00C(void *, int, int);
extern int D_002B8870;
extern "C" void func_00191BA8(char *, int, int, int);
extern "C" void func_00191C64(char *, int, int, int);
extern "C" void setActorLight__9MagSystemii(void *, int, int);
extern "C" void ror_assert(const char *, int, const char *);
struct MapModel {
    int val;
    char pad[0x520 - 4];
};
extern MapModel D_007257B8[];
struct Foo {
    char pad[0x1F24C];
    int ids[0x180];
};
extern "C" void func_001CB01C(int, int);
extern "C" void func_001CDF5C(int, int, int);
extern "C" void func_0018BD94(char *);
extern "C" int X4_func_0013F280(int, int, int, int) asm("func_0013F280");
extern "C" int X_func_00243C40(int, int, int) asm("func_00243C40");
extern "C" int X_func_001CBE38(int, int) asm("func_001CBE38");
extern int D_006FE6A0;
extern "C" void X_func_00144500(...) asm("func_00144500");
extern "C" int func_001C0298(int arg0, int arg1);
extern char *D_007B205C;
extern "C" int X_func_00191E58(...) asm("func_00191E58");
extern char D_006FBD80[];
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_func_001BE564(...) asm("func_001BE564");
extern "C" int Xiiiii_func_001BE444(int, int, int, int) asm("func_001BE444");
extern "C" int Xiii_func_001BE3C4(int, int) asm("func_001BE3C4");
extern "C" int Xiiiii_func_001BE36C(int, int, int, int) asm("func_001BE36C");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_FlushCache(...) asm("FlushCache");
extern "C" int X_func_001E71FC(...) asm("func_001E71FC");
extern "C" int X_sceGsExecLoadImage(...) asm("sceGsExecLoadImage");
extern "C" int X_sceGsSetDefLoadImage(...) asm("sceGsSetDefLoadImage");
extern "C" int X_sceGsSyncPath(...) asm("sceGsSyncPath");
extern "C" int Xii___builtin_new(int) asm("__builtin_new");
extern "C" int Xii_func_00144334(int) asm("func_00144334");
extern "C" int Xii_func_0018741C(int) asm("func_0018741C");
extern "C" int Xii_func_00187464(int) asm("func_00187464");
extern "C" int Xii_func_0018FEBC(int) asm("func_0018FEBC");
extern "C" int Xii_func_001BE048(int) asm("func_001BE048");
extern "C" int Xii_func_001D8DC4(int) asm("func_001D8DC4");
extern "C" void Xii_func_001D8FEC(int, int) asm("func_001D8FEC");
extern "C" int Xii_func_001D9F40(int) asm("func_001D9F40");
extern "C" int Xii_func_001D9F84(int) asm("func_001D9F84");
extern "C" int Xii_func_001DA05C(int) asm("func_001DA05C");
extern "C" int Xiii_func_0018BCC0(int, int) asm("func_0018BCC0");
extern "C" int Xiii_func_001CBAFC(int, int) asm("func_001CBAFC");
extern "C" int Xiii_func_001D8964(int, int) asm("func_001D8964");
extern "C" int Xiii_func_001DB774(int, int) asm("func_001DB774");
extern "C" int Xiii_func_001E7724(int, int) asm("func_001E7724");
extern "C" int Xiii_func_001E7D7C(int, int) asm("func_001E7D7C");
extern "C" int Xiiii_func_0011825C__9MagSystemii(int, int, int) asm("func_0011825C__9MagSystemii");
extern "C" int Xiiii_func_0018F744(int, int, int) asm("func_0018F744");
extern "C" int Xiiii_func_001C82F8(int, int, int) asm("func_001C82F8");
extern "C" int Xiiii_func_001C94D8(int, int, int) asm("func_001C94D8");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern "C" int Xiiiii_func_001CB970(int, int, int, int) asm("func_001CB970");
extern "C" int Xiiiiii_func_00134730(int, int, int, int, int) asm("func_00134730");
extern "C" int Xiiiiiiii_func_001F4A24(int, int, int, int, int, int, int) asm("func_001F4A24");
extern "C" int Xiiu_func_001348B0(int, unsigned int) asm("func_001348B0");
extern "C" int Xiiu_func_00135594(int, unsigned int) asm("func_00135594");
extern "C" int Xiiu_func_001D046C(int, unsigned int) asm("func_001D046C");
extern "C" int Xiiu_func_001D2B8C(int, unsigned int) asm("func_001D2B8C");
extern "C" int Xiiu_func_001D2BA8(int, unsigned int) asm("func_001D2BA8");
extern "C" int Xiiui_func_001351B0(int, unsigned int, int) asm("func_001351B0");
extern "C" int Xiiui_func_001D05F4(int, unsigned int, int) asm("func_001D05F4");
extern "C" float func_00217F10(float, float);
extern "C" int Xiiuii_func_00134AB8(int, unsigned int, int, int) asm("func_00134AB8");
extern "C" int Xiiuiii_func_00134A00(int, unsigned int, int, int, int) asm("func_00134A00");
extern const char D_002FB330[];
extern const char D_002FB350[];
extern int D_002B89E0;
extern int D_006FE04C;
extern int D_00727BD0;
extern int D_007812C0;
extern "C" int X_func_00118ED8__9MagSystemiii(...) asm("func_00118ED8__9MagSystemiii");
extern "C" int X_func_00118F30__9MagSystemii(...) asm("func_00118F30__9MagSystemii");
extern "C" int X_func_00163AB8(...) asm("func_00163AB8");
extern "C" int X_func_0017F5E8(...) asm("func_0017F5E8");
extern "C" int X_func_00180B30(...) asm("func_00180B30");
extern "C" int X_func_0018330C(...) asm("func_0018330C");
extern "C" int X_func_0018BB8C(...) asm("func_0018BB8C");
extern "C" int X_func_0018C130(...) asm("func_0018C130");
extern "C" int X_func_0018C190(...) asm("func_0018C190");
extern "C" int X_func_001BE084(...) asm("func_001BE084");
extern "C" int X_func_001BE0C0(...) asm("func_001BE0C0");
extern "C" int X_func_001C02F8(...) asm("func_001C02F8");
extern "C" int X_func_001C0D70(...) asm("func_001C0D70");
extern "C" int X_func_001C2848(...) asm("func_001C2848");
extern "C" int X_func_001C4FA4(...) asm("func_001C4FA4");
extern "C" int X_func_001C96C8(...) asm("func_001C96C8");
extern "C" int X_func_001CB8E4(...) asm("func_001CB8E4");
extern "C" int X_func_001CBEDC(...) asm("func_001CBEDC");
extern "C" int X_func_001CED18(...) asm("func_001CED18");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D2B8C(...) asm("func_001D2B8C");
extern "C" int X_func_001DA228(...) asm("func_001DA228");
extern "C" int X_func_001DA740(...) asm("func_001DA740");
extern "C" int X_func_001DCD38(...) asm("func_001DCD38");
extern "C" int X_func_001E7724(...) asm("func_001E7724");
extern "C" int X_func_001E7D7C(...) asm("func_001E7D7C");
extern "C" int X_func_00243788(...) asm("func_00243788");
extern "C" int X_func_002437F8(...) asm("func_002437F8");
extern "C" int X_func_00243938(...) asm("func_00243938");
extern "C" int X_func_00243CD8(...) asm("func_00243CD8");
extern "C" int X_func_00247EB8(...) asm("func_00247EB8");
extern "C" int X_func_00247F00(...) asm("func_00247F00");
extern "C" int X_func_00247F10(...) asm("func_00247F10");
extern "C" int X_setPlayer__9MagSystemii(...) asm("setPlayer__9MagSystemii");
extern int D_002B8A10;
extern int D_002B8BF0;
extern int D_002B8F50;
extern int D_006E9840;
extern int D_007A3D80;
extern int D_007B2140;
extern int D_007B2580;
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001B64C4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001B69D0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BA3A0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BA8E4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BAFF4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BB12C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BB4F0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BBCFC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BC370);

extern "C" int func_001BC760()
{
    int r = -1;

    if (*(int *)(D_007B205C + 0x54) == 2) {
        r = *(int *)(D_007B205C + 0x44);
        if (r == 0xA00) {
            r = -1;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BC790);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BC8F8);

static inline void *gamSub22220() {
    void *p = (void *)&D_007812C0;
    return (char *)p + 0x22220;
}

extern "C" int func_001BCB84(int unused, unsigned int arg1)
{
    int sp0;
    void *temp_s0 = gamSub22220();
    unsigned short temp_s1 = arg1 & 0xFFFF;
    sp0 = 0;
    if (func_001DD00C(temp_s0, temp_s1, 4) != 0) {
        func_001DC48C(temp_s0, temp_s1, 0xC, &sp0);
    } else {
        sp0 = D_002B8870;
    }
    return sp0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BCC08);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BD028);

extern "C" int func_001BDAE4(int arg0)
{
    int temp_a0;
    int var_s0;
    int var_s2;

    var_s0 = arg0 + 0x14;
    var_s2 = 1;
    do {
        temp_a0 = var_s0;
        var_s0 += 0x3BC;
        X_func_0018330C(temp_a0);
        var_s2 -= 1;
    } while (var_s2 != -1);
    X_func_0018BB8C(arg0 + 0x78C);
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x1080)) = 0;
    return X_func_001BE0C0(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BDB4C);

extern "C" void func_001BDC00(int arg0, int arg1)
{
    (*(int *)&D_006FE04C) = 0;
    Xiii_func_0018BCC0(arg0 + 0x78C, 2);
    M2C_FIELD(arg0, int *, 0xBA8) = arg1;
    Xii_func_001BE048(arg0);
    M2C_FIELD(arg0, int *, 0x1080) = 1;
}

extern "C" void func_001BDC54(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x1080)) != 0) {
        X_func_0018C130(arg0 + 0x78C);
        X_func_001BE084(arg0);
        (*(int *)(int *)((char *)(arg0) + 0x1080)) = 0;
    }
}

extern "C" int func_001BDC94(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x1080));
}

extern "C" void func_001BDC9C(int arg0)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 0x1078) == 0) {
        Xiiii_ror_assert((int) D_002FB330, 0xA0, (int) D_002FB350);
    }
    Xii_func_0018741C(arg0 + 0x14);
    temp_v0 = Xiiiiii_func_00134730(M2C_FIELD(arg0, int *, 0x1078), 0x200, 0x100, 0, -1);
    M2C_FIELD(arg0, int *, 0x1084) = temp_v0;
    Xiiu_func_00135594(M2C_FIELD(arg0, int *, 0x1078), (unsigned int) temp_v0);
    Xiiuiii_func_00134A00((int) M2C_FIELD(arg0, int *, 0x1078), (unsigned int) M2C_FIELD(arg0, int *, 0x1084), 0xDC, 0x78, 0x7FFF);
    Xiiuii_func_00134AB8((int) M2C_FIELD(arg0, int *, 0x1078), (unsigned int) M2C_FIELD(arg0, int *, 0x1084), 0x200, 0x100);
    Xiiui_func_001351B0((int) M2C_FIELD(arg0, int *, 0x1078), (unsigned int) M2C_FIELD(arg0, int *, 0x1084), 0);
}

extern "C" void func_001BDD48(int arg0)
{
    int temp_a1;

    if (M2C_FIELD(arg0, int *, 0x1078) == 0) {
        Xiiii_ror_assert((int) D_002FB330, 0xB5, (int) D_002FB350);
    }
    temp_a1 = M2C_FIELD(arg0, int *, 0x1084);
    if (temp_a1 >= 0) {
        Xiiu_func_00135594(M2C_FIELD(arg0, int *, 0x1078), (unsigned int) temp_a1);
        Xiiu_func_001348B0(M2C_FIELD(arg0, int *, 0x1078), (unsigned int) M2C_FIELD(arg0, int *, 0x1084));
        M2C_FIELD(arg0, int *, 0x1084) = -1;
    }
    Xii_func_00187464(arg0 + 0x14);
}

extern "C" void func_001BDDBC(int arg0)
{
    int temp_s1;

    temp_s1 = arg0 + 0x14;
    if (M2C_FIELD(arg0, int *, 0x1078) == 0) {
        X_ror_assert((int) D_002FB330, 0xCC, (int) D_002FB350);
    }
    if (X_func_001875C0(temp_s1, M2C_FIELD(arg0, int *, 0x1084)) != 0) {
        X_func_00187464(temp_s1);
    }
    X_func_0018741C(temp_s1);
    X_func_001874F4(temp_s1, M2C_FIELD(arg0, int *, 0x1084), ((int *)&D_002B8C90)[M2C_FIELD(arg0, int *, 0x107C)], 0);
    X_func_001874AC(temp_s1);
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB188);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB190);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB1A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB1B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB1C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB1C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB210);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB258);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB2A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB2E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB330);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB350);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BDE58);

extern "C" void func_001BDFE0(char *arg0, int arg1)
{
    if (arg1 != 0) {
        arg0 += 0x78C;
        *(int *)(arg0 + 0x4D0) = arg1;
        func_0018BD94(arg0);
    }
}

extern "C" void func_001BE004(int arg0)
{
    int temp_s0;

    temp_s0 = arg0 + 0x794;
    Xiiii_func_0018F744(temp_s0, (int)&D_002B89E0, (int) "data/mnurpk/mnusllg.rpk");
    do {

    } while (Xii_func_0018FEBC(temp_s0) == 0);
}

extern "C" int func_001BE048(int self)
{
    int *p = (int *)self;

    if (p[0] == 1) {
        return -1;
    }
    p[0] = 1;
    p[3] = 0;
    p[4] = 0;
    func_001BDC9C(self);
    return 0;
}

extern "C" int func_001BE084(int self)
{
    if (*(int *)(self + 0) == 0) {
        return -1;
    }
    func_001BDD48(self);
    *(int *)(self + 0) = 0;
    return 0;
}

extern "C" int func_001BE0C0(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x107C)) = 0;
    return 0;
}

extern "C" void func_001BE0CC(int arg0)
{
    int temp_s0;

    temp_s0 = arg0 + 0x78C;
    (*(int *)(int *)((char *)(temp_s0) + 0x4B0)) = (int)&D_002B8A10;
    X_func_0018C190(temp_s0, (int)&D_002B8BF0);
    (*(int *)(int *)((char *)(temp_s0) + 0x4)) = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BE110);

extern "C" void __10FileReader(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x4)) = -1;
}

extern "C" int func_001BE414(int);

class FileReader {
public:
    int unk0;
    int unk4;
    ~FileReader();
};

FileReader::~FileReader()
{
    if (unk4 >= 0) {
        func_001BE414((int)this);
    }
}

extern "C" int func_001BE338(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x4)) = X_func_00243788(arg1, 0x8001);
    return 0;
}

extern "C" int func_001BE36C(int arg0, int arg1, int arg2, int arg3)
{
    return X_func_00243938(arg1, arg2, arg3);
}

extern "C" int func_001BE38C(int arg0, int arg1, int arg2)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 4);
    if (temp_v1 < 0) {
        return -1;
    }
    return Xiiiii_func_001BE36C((int) arg0, temp_v1, arg1, arg2);
}

extern "C" int func_001BE3C4(int arg0, int arg1)
{
    if (arg1 == (*(int *)(int *)((char *)(arg0) + 0x4))) {
        X_func_002437F8(arg1);
        (*(int *)(int *)((char *)(arg0) + 0x4)) = -1;
        return 1;
    }
    X_func_002437F8(arg1);
    return 2;
}

extern "C" int func_001BE414(int arg0)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 4);
    if (temp_v1 < 0) {
        return -1;
    }
    return Xiii_func_001BE3C4(arg0, temp_v1);
}

extern "C" int func_001BE444(int theA, int theB, int theC, int theD)
{
    int mode = 0;

    switch (theD) {
    case 0:
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    }
    return X_func_00243C40(theB, theC, mode);
}

extern "C" int func_001BE490(int arg0, int arg1, int arg2)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 4);
    if (temp_v1 < 0) {
        return -1;
    }
    return Xiiiii_func_001BE444((int) arg0, temp_v1, arg1, arg2);
}

extern "C" int func_001BE4C8(int arg0, int arg1, int arg2)
{
    int temp_v0;
    int var_v1;

    var_v1 = 0;
    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x4));
    if (temp_v0 >= 0) {
        var_v1 = X_func_00243CD8(temp_v0, 1);
    }
    if (arg2 != 0) {
        (*(int *)(arg2)) = (*(int *)(int *)((char *)(arg0) + 0x4));
    }
    return var_v1 == 0;
}

extern "C" void func_001BE524__10FileReaderP11FileReadReqi(int self, int theReq, int theA)
{
    *(int *)(self) = theReq;
    *(int *)(theReq + 4) = 0;
    return X_func_001BE564(self, theA);
}

extern "C" void func_001BE548(int *theOut, int theA, int theB)
{
    *theOut = theA;
    return X_func_001BE564(theOut, theB);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BE564);

extern "C" void __11FileReadReq(int arg0)
{
    Xiiii_memset(arg0, 0, 0x24);
    (*(int *)(arg0)) = -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BE768);

extern "C" int func_001BE84C(int theA)
{
    int r = X_func_00243788(theA, 1);

    if (r < 0) {
        return 0;
    }
    X_func_002437F8(r);
    return 1;
}

extern "C" int func_001BE880()
{
    return X_func_00247EB8();
}

extern "C" int func_001BE894()
{
    return X_func_00247F00();
}

extern "C" int func_001BE8A8()
{
    return X_func_00247F10();
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BE8BC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BEA18);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BEB70);

extern "C" void func_001BEBC4(void *self, int theFlags)
{
    if (theFlags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BEBEC);

extern "C" int func_001BEDB0()
{
    return 1;
}

extern "C" int func_001BEDB8()
{
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BEDC0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BEE8C);

extern "C" int func_001BEEB4(int self)
{
    void *p = *(void **)(self + 0xC);

    if (p == 0) {
        return 0;
    }
    Xiiii_memset((int)p, *(int *)(self + 0x64), *(int *)(self + 0x1C));
    return 1;
}

extern "C" int func_001BEEEC(int self, int theA)
{
    if (func_001C0298(self, theA) == 1) {
        return *(int *)(self + 0x38) >> 1;
    }
    return *(int *)(self + 0x38);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BEF24);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BF024);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BF8C4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BFE30);

extern "C" void func_001BFF28(char *self, int theA)
{
    *(int *)(self + 0x64) = theA;

    switch (*(int *)(self + 0x18)) {
    case 4:
        break;
    case 8:
        if (*(int *)(self + 0x68) != 0) {
            *(int *)(self + 0x64) = theA | 0x80;
        }
        break;
    }
}

extern "C" void func_001BFF5C(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x68)) = arg1;
}

extern "C" void func_001BFF64(char *self, int theA)
{
    switch (*(int *)(self + 0x18)) {
    case 4:
        *(int *)(self + 0x2C) = theA & 0xF;
        break;
    case 8:
        *(int *)(self + 0x2C) = theA & 0xFF;
        if (*(int *)(self + 0x68) != 0) {
            *(int *)(self + 0x2C) = (theA & 0xFF) | 0x80;
        }
        break;
    }
}

extern "C" int func_001BFFAC(unsigned short *theA, unsigned short *theB)
{
    int a = *theA;
    int b = *theB;

    if (a < b) {
        return -1;
    }
    return b < a;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001BFFCC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C0078);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C0148);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C020C);

extern "C" int func_001C0254(int self, int theA)
{
    int r = *(int *)(self + 0x38);

    if (*(int *)(self + 0x24) != 0 && *(int *)(self + 0x28) != 0 && theA >= 0) {
        r = *(unsigned char *)(*(int *)(self + 0x5C) + ((theA << 1) + 1 & 0xFF));
    }
    return r;
}

extern "C" int func_001C0298(int arg0, int arg1)
{
    if ((unsigned int)(arg1 - 0x20) < 0x60U) {
        return 1;
    }
    return (unsigned int)(arg1 - 0xA0) < 0x40U;
}

extern "C" int func_001C02B8(int arg0, int arg1)
{
    int v = arg1 & 0xFF00;

    if ((unsigned int)(v - 0x8000) < 0x1F01U) {
        return 1;
    }
    return (unsigned int)(v - 0xE000) < 0xA01U;
}

extern "C" int func_001C02E4(int arg0, int arg1)
{
    return (unsigned int) (arg1 - 0x20) < 0xE0U;
}

extern "C" int func_001C02F0()
{
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C02F8);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C03D0);

extern "C" int func_001C047C()
{
    return X_func_001C02F8();
}

extern "C" int func_001C0490(int arg0, const unsigned char *arg1)
{
    int total = 0;
    int c;
    const unsigned char *p = arg1;

    while ((c = *p++) != 0) {
        if (func_001C0298(arg0, c) == 1) {
            goto do_add;
        }
        c <<= 8;
        c |= *p;
        if (func_001C02B8(arg0, c) == 1) {
            p++;
do_add:
            total += func_001C0148(arg0, c);
        }
    }
    return total;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C0534);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C05C0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", GamMan__vfunc_01);

extern "C" void func_001C0D44(int arg0)
{
    X_func_001C4FA4();
    X_func_001C0D70(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C0D70);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C1378);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C143C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C19C4);

extern "C" int func_001C1A6C(void *self, int theIdx)
{
    int *p = *(int **)((char *)self + 0x22200);

    return p[theIdx];
}

extern "C" void func_001C1A88(void) {
}

extern "C" void func_001C1A90(int arg0, int arg1)
{
    struct { char pad0[96]; } stack;
    Xiiii_memset(arg1, 0, 0x100000);
    X_sceGsSetDefLoadImage((int)&stack, 0, 8, 0, 0, -4, 0x200, 0xE4);
    X_FlushCache(0);
    X_sceGsExecLoadImage((int)&stack, arg1);
    X_sceGsSyncPath(0, 0);
    X_sceGsSetDefLoadImage((int)&stack, 0, 8, 0, 0, 0xDC, 0x200, 0xE4);
    X_FlushCache(0);
    X_sceGsExecLoadImage((int)&stack, arg1);
    X_sceGsSyncPath(0, 0);
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB398);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3F0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C1B48);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C1F84);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB418);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB438);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C204C);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB540);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB558);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB560);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB578);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB580);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB598);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB600);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB618);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB620);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB638);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB640);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB658);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB660);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB678);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB680);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB698);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB700);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB718);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB720);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB738);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C2848);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C2F50);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C387C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C3A48);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C3D38);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C4168);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C43F0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C4610);

extern "C" void func_001C46C8(int arg0)
{
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x21FE0);
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, float *, 0x1E8) = 9.999999583953922e-08f;
    }
}

extern "C" void func_001C46F4(void) {
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB898);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8C0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C46FC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C47C4);

extern "C" void func_001C4F30(void) {
}

extern "C" void func_001C4F38(int arg0, int arg1)
{
    X_func_00118ED8__9MagSystemiii((int)&D_006E9840, (*(int *)(int *)((char *)(arg0) + 0x21FDC)), arg1, 1);
}

extern "C" void func_001C4F70(int arg0, int arg1)
{
    X_func_00118F30__9MagSystemii((int)&D_006E9840, (*(int *)(int *)((char *)(arg0) + 0x21FDC)), arg1);
}

extern "C" void func_001C4FA4()
{
    X_func_001CED18();
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C4FC0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C5094);

extern "C" void func_001C5168(int unused, int arg1, int arg2, int arg3)
{
    unsigned int off = 0x42BB0;
    char *p = D_006FBD80 + off;
    func_00191BA8(p, arg1, 0, 0);
    func_00191C64(p, arg1, arg2 << 4, arg3 << 4);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C51E0);

extern "C" void func_001C5240()
{
    char *p = D_006FBD80;

    X_func_00191E58((int)(p + 0x42BB0));
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C526C);

extern "C" void func_001C53D8(void) {
}

extern "C" void func_001C53E0(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x21FF0)) = arg1;
    X_setPlayer__9MagSystemii((int)&D_006E9840, (*(int *)(int *)((char *)(arg0) + 0x21FDC)), arg1);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C541C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C574C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C57A0);

extern "C" int func_001C58B8()
{
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C58C0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C5A5C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C5BF4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C5D08);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C5E1C);

extern "C" void func_001C5F70(char *arg0)
{
    if (*(int *)(arg0 + 0x21F4C) & 0x20) {
        unsigned int off = 0x42BB0;
        char *p = D_006FBD80 + off;
        func_00191D20(p, 2, 0);
        func_00191D74(p, 2, 0);
    }
    *(int *)(arg0 + 0x21F4C) |= 8;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C5FFC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C621C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6470);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C651C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C65E8);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C687C);

extern "C" void func_001C6A04(int arg0)
{
    X_func_00163AB8((int)&D_007B2140, arg0 + 0x22004, arg0 + 0x22008);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6A40);

extern "C" int func_001C6C28(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x21F7C));
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6C38);

extern "C" int func_001C6C98(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x21F64)) + ((unsigned int) (*(int *)(unsigned int *)((char *)(arg0) + 0x21F60)) / 1800U);
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB920);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB930);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6CCC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6F08);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6FE0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C7210);

extern "C" int func_001C7494(char *arg0)
{
    unsigned int no = *(unsigned int *)(arg0 + 0x1D300);
    if (no >= 4) {
        ror_assert("mag/magscene.h", 0x330, "no >= 0 && no < MAX_MAP_MODEL");
    }
    return D_007257B8[no].val;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C7500);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C75BC);

extern "C" void func_001C766C(int arg0)
{
    X_func_0017F5E8((int)&D_007B2580, 8);
    X_func_00180B30((int)&D_007B2580, 0x1F);
    X_func_001C2848(arg0, (*(int *)(int *)((char *)(arg0) + 0x21F50)), 1);
}

extern "C" void func_001C76CC(int arg0)
{
    X_func_0017F5E8((int)&D_007B2580, 8);
    X_func_00180B30((int)&D_007B2580, 0xC);
    X_func_001C2848(arg0, (*(int *)(int *)((char *)(arg0) + 0x21F50)), 0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C772C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C7A4C);

extern "C" void func_001C7D04(int arg0, int arg1)
{
    int found = 0;
    int i = 0;
    int *p = *(int **)((char *)arg0 + 0x1F240);
    int *start = p;

    while (1) {
        int val = *p++;
        if (val != 0) {
            if (val == arg1) {
                found = 1;
            }
        }
        i++;
        if (i >= 0x169 || found != 0) {
            break;
        }
    }

    if (found == 0) {
        p = start;
        i = 0;
        if (*p != 0) {
            do {
                p++;
                i++;
                if (*p == 0) {
                    break;
                }
            } while (i < 0x169);
        }
        *p = arg1;
    }

    func_001CCC30(arg0, arg1);
}

extern "C" int func_001C7DA8(int self, int theValue)
{
    int *p = *(int **)(self + 0x1F240);

    for (int i = 0; i < 0x169; i++) {
        if (*p == theValue) {
            return 1;
        }
        p++;
    }
    return 0;
}

extern "C" void func_001C7DEC(int arg0)
{
    int var_a0;
    int var_v1;

    var_v1 = M2C_FIELD(arg0, int *, 0x1F240);
    var_a0 = 0x168;
    do {
        if (((unsigned int) (*(unsigned int *)(var_v1)) >> 0x1E) != 0) {
            (*(unsigned int *)(var_v1)) = 0;
        }
        var_a0 -= 1;
        var_v1 += 4;
    } while (var_a0 >= 0);
}

extern "C" int func_001C7E28(int arg0, int arg1)
{
    return (int)&D_002B8F50 + ((arg1 & 0xFFFF) << 9);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C7E40);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C812C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8214);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C82F8);

extern "C" void func_001C8414(int arg0, int arg1)
{
    int temp_s1;

    temp_s1 = arg1 & 0xFFFF;
    Xiiii_func_001C82F8((int) arg0, temp_s1, 0);
    Xiiii_func_001C94D8(arg0, temp_s1, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C845C);

extern "C" int func_001C8508(int arg0, unsigned short arg1)
{
    int temp_v0;
    int var_a2;
    int temp_v1;

    var_a2 = 0;
loop_1:
    temp_v0 = var_a2 * 0x10;
    var_a2 += 1;
    temp_v1 = M2C_FIELD(arg0, int *, 0x1A6C0) + temp_v0;
    if (M2C_FIELD(temp_v1, unsigned short *, 8) == (arg1 & 0xFFFF)) {
        return (int) M2C_FIELD(temp_v1, unsigned short *, 0xA);
    }
    if (var_a2 >= 0xC) {
        return 0;
    }
    goto loop_1;
}

extern "C" int func_001C854C(int self)
{
    for (int i = 0; i < 0xC; i++) {
        int base = *(int *)(self + 0x1A6C0);
        if (*(unsigned short *)(base + (i << 4) + 8) == *(unsigned short *)(self + 0x2220C)) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8598);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8604);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C870C);

extern "C" int func_001C898C(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x1D200));
}

extern "C" void func_001C899C(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x1D200);
    if (temp_v0 > 0) {
        temp_v1 = M2C_FIELD(arg0, int *, 0x1D204);
        M2C_FIELD(arg0, int *, 0x1D200) = (int) (temp_v0 - 1);
        if (temp_v1 != 0) {
            M2C_FIELD(temp_v1, unsigned short *, 0xA) = (unsigned short) (M2C_FIELD(temp_v1, unsigned short *, 0xA) + 0xFFFF);
        }
    }
}

extern "C" int func_001C89E4(int arg0)
{
    int var_a2 = 0;
    int var_a1 = 0;

loop_1:
    int temp_v0 = M2C_FIELD(arg0, int *, 0x1A6C0);
    int temp_v1 = var_a1 * 0x10;
    var_a1 += 1;
    int temp_v2 = temp_v0 + temp_v1;
    unsigned short val = M2C_FIELD(temp_v2, unsigned short *, 8);
    int diff = val ^ 0xA00;
    if (diff != 0) {
        var_a2++;
    }
    if (var_a1 < 0xC) {
        goto loop_1;
    }
    return var_a2;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8A28);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8AE8);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8C50);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8CA4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8DC8);

extern "C" int func_001C8E14()
{
    return 0;
}

extern "C" void func_001C8E1C(int arg0, int arg1)
{
    X_func_001DCD38(arg0 + 0x22220, X_func_001CBEDC(), 4);
    X_func_001D10D0(arg0, arg1, 2);
    X_func_001D1410(arg0, arg1, 1);
    if (X_func_001C96C8(arg0, arg1) != 0) {
        X_func_001CB8E4(arg0, arg1, 0x32, 0);
    }
}

extern "C" void func_001C8EAC(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8EB4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8F7C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9198);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9334);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C94D8);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C96C8);

extern "C" void func_001C9784(int self, unsigned short theA)
{
    *(unsigned short *)(self + 0x2220E) = theA;
    if (theA == 0xA00) {
        return X_func_00144500(0);
    }
    X_func_00144500(theA);
}

extern "C" int func_001C97C8(int arg0)
{
    return (M2C_FIELD(arg0, long *, 0x21F48) & (((long) 0x800 << 0x20) | 4)) == 4;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C97F0);

extern "C" void func_001C98B8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C98C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBB78);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBB88);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBB98);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9920);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9C1C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9E20);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9F94);

extern "C" void func_001CA0CC(void) {
}

extern "C" void func_001CA0D4(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CA0DC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CA38C);

extern "C" void func_001CA598(int unused, int arg1, unsigned int arg2)
{
    switch ((arg2 >> 23) & 0x1F) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 5:
        setActorLight__9MagSystemii(&D_006E9840, arg1, 1);
        break;
    case 4:
    case 9:
        setActorLight__9MagSystemii(&D_006E9840, arg1, 0);
        break;
    default:
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CA604);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CA72C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CA8E8);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CAA14);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CABD4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CAD88);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CAF78);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB01C);

template <class T> class GamListLocal2 {
public:
    struct Node {
        Node *m_prev;       // +0x00
        Node *m_next;       // +0x04
        T m_data;           // +0x08
    };

    class iterator {
    public:
        Node *m_node;

        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        T &operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };

    unsigned char m_unk00[0x10];
    Node m_head;            // +0x10

    iterator begin() { return iterator(m_head.m_next); }
    iterator end() { return iterator(&m_head); }
};

extern "C" int func_001CB1C0(char *arg0)
{
    GamListLocal2<int>::iterator it;
    GamListLocal2<int>::iterator last;
    GamListLocal2<int> *list = (GamListLocal2<int> *)(arg0 + 0x1D24C);
    it = list->begin();
    last = list->end();
    while (it != last) {
        if (*it & 1) {
            *it &= ~1;
        }
        ++it;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB24C);

extern "C" int func_001CB384(int arg0, int arg1)
{
    int temp_a1;
    int temp_v0;

    if (arg1 == -1) {
        return Xii_func_00144334(0);
    }
    M2C_FIELD(arg0, int *, 0x21FD0) = arg1;
    temp_v0 = Xiiu_func_001D2B8C((int) arg0, (unsigned int) arg1);
    M2C_FIELD(arg0, int *, 0x22094) = temp_v0;
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, int *, 0x120) = (int) (M2C_FIELD(temp_v0, int *, 0x120) | 0x10000);
        temp_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x22094), int *, 0x108);
        M2C_FIELD(arg0, int *, 0x21FE8) = temp_a1;
        Xiiii_func_0011825C__9MagSystemii((int) (int)&D_006E9840, temp_a1, 0);
    }
}

extern "C" void func_001CB424(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x21FD8)) = arg1;
    (*(int *)(int *)((char *)(arg0) + 0x22098)) = X_func_001D2B8C();
}

extern "C" void func_001CB460(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x22090));
    if (temp_v0 != 0) {
        X_func_001DA228(temp_v0);
    }
}

extern "C" void func_001CB490(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x22094));
    if (temp_v0 != 0) {
        X_func_001DA228(temp_v0);
    }
}

extern "C" void func_001CB4C0(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x22098));
    if (temp_v0 != 0) {
        X_func_001DA228(temp_v0);
    }
}

extern "C" void func_001CB4F0(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x22090));
    if (temp_v0 != 0) {
        X_func_001DA740(temp_v0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB520);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB57C);

extern "C" void func_001CB5D8(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x22094));
    if (temp_v0 != 0) {
        X_func_001DA740(temp_v0);
    }
}

extern "C" void func_001CB608(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x22098));
    if (temp_v0 != 0) {
        X_func_001DA740(temp_v0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB638);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB74C);

extern "C" void func_001CB8E4(int arg0, int arg1, int arg2)
{
    struct { char pad0[16]; } stack;
    if (Xiii_func_001CBAFC(arg0, (int) arg1) == -1) {
        Xiiui_func_001D05F4((int)&D_007812C0, (unsigned int) arg1, (int)&stack);
        if (arg2 == 0x32) {
            Xiiiii_func_001CB970(arg0, arg1, 0x32, (int)&stack);
            return;
        }
        Xiiiii_func_001CB970(arg0, arg1, arg2, (int)&stack);
    }
}

extern "C" void func_001CB970(void *arg0, void *arg1, int arg2, float *arg3)
{
    if (arg2 == 0x32) {
        DogVector pos(arg3[0], arg3[1], arg3[2], 50.0f);
        PcEffParam param;
        param.m_kind = arg2;
        param.m_pos = pos;
        param.m_unk08 = 0;
        unsigned int off = 0x837E0;
        char *p = D_006FBD80 + off;
        func_001CBA0C(arg0, arg1, func_00176CC8(p, &param));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CBA0C);

struct GamPair {
    int key;
    int val;
};

template <class T> class GamListLocal {
public:
    struct Node {
        Node *m_prev;       // +0x00
        Node *m_next;       // +0x04
        T m_data;           // +0x08
    };

    class iterator {
    public:
        Node *m_node;

        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        T &operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };

    unsigned char m_unk00[0x10];
    Node m_head;            // +0x10

    iterator begin() { return iterator(m_head.m_next); }
    iterator end() { return iterator(&m_head); }
};

extern "C" int func_001CBAFC(char *arg0, int arg1)
{
    GamListLocal<GamPair>::iterator it;
    GamListLocal<GamPair>::iterator last;
    GamListLocal<GamPair> *list = (GamListLocal<GamPair> *)(arg0 + 0x20B04);
    it = list->begin();
    last = list->end();
    while (it != last) {
        if ((*it).key == arg1) {
            return (*it).val;
        }
        ++it;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CBB80);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CBD0C);

extern "C" int func_001CBDB8(int theA, int theB)
{
    int r = X_func_001CBE38((int)&D_007812C0, theB);

    if (r == -1) {
        return 0;
    }
    return (int)&D_006FE6A0 + r * 0x4D0;
}

extern "C" void func_001CBDFC(int arg0, int arg1, int arg2)
{
    int var_v1;

    var_v1 = M2C_FIELD(arg2, unsigned char *, 0) * M2C_FIELD(arg2, unsigned char *, 1);
    if (var_v1 & 0xF) {
        var_v1 = (var_v1 & 0xFFF0) + 0x10;
    }
    M2C_FIELD(arg2, int *, 0xC) = (int) (arg2 - var_v1);
    M2C_FIELD(((arg1 * 4) + arg0), int *, 0x222E4) = arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CBE38);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CBEDC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CBF4C);

extern "C" void *func_001CBFB0(int arg0, unsigned int arg1)
{
    int var_a2 = 0;
    int var_a4 = 0;
    unsigned int off = 0x1F24CU;

loop_1:
    int temp_v0 = var_a2 * 4;
    var_a2 += 1;
    int temp_v1 = temp_v0 + arg0;
    int *p = (int *)(temp_v1 + off);
    if (*p == 0) {
        *p = arg1;
        return *(char **)(arg0 + 0x1F248) + var_a4;
    }
    var_a4 += 0x2C0;
    if (var_a2 < 0x180) {
        goto loop_1;
    }
    return 0;
}

extern "C" void func_001CC004(Foo *self, int arg1)
{
    for (int i = 0; i < 0x180; i++) {
        if (self->ids[i] == arg1) {
            self->ids[i] = 0;
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CC044);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CC250);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CC560);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CC7C8);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CC970);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CCC30);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD044);

extern "C" void func_001CD224(int arg0)
{
    func_001CB01C(arg0, 2);
    func_001CDF5C(arg0, 2, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD25C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD404);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD60C);

extern "C" void func_001CD7C0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD7C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF50);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF58);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF60);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF68);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF70);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD954);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CDBF0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CDF5C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CEA44);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CEBF8);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CED18);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CF2E8);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CF518);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CF6BC);

struct Struct32 {
    char data[32];
} __attribute__((packed));

extern "C" void func_001CF7D0(char *arg0, const Struct32 *arg1)
{
    *(Struct32 *)(arg0 + 0x22280) = *arg1;
}

extern "C" void func_001CF854(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x222A0)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x222A0));
        M2C_FIELD(arg0, int *, 0x222A0) = -1;
    }
    temp_v0 = Xii___builtin_new(0x9C0);
    Xiiiiiiii_func_001F4A24(temp_v0, arg1, arg2, arg0 + 0x22280, 1, M2C_FIELD(arg0, int *, 0x225D8), arg3);
    X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0, 0, arg0 + 0x222A0, 0x11);
}

extern "C" void func_001CF95C(int arg0)
{
    if (X_func_001E7D7C((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x222A0))) != 0) {
        X_func_001E7724((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x222A0)));
        (*(int *)(int *)((char *)(arg0) + 0x222A0)) = -1;
    }
    (*(int *)(int *)((char *)(arg0) + 0x225D8)) = 0;
}

extern "C" int func_001CF9D4(char *self)
{
    register char *self_reg asm("$16") = self;
    register int var_s1 asm("$17") = 0;
    int temp_v0;

    if (func_001E7D7C(&D_007A3D80, *(int *)(self_reg + 0x222A0)) == 0) {
        temp_v0 = *(int *)(self_reg + 0x2227C);
        if (temp_v0 != -1) {
            char *p = (char *)&D_006E9840;
            if (func_0013F444(p + 0x12540, temp_v0) != 0) {
                goto block_3;
            }
        }
    } else {
block_3:
        var_s1 = 1;
    }
    return var_s1;
}

extern "C" void func_001CFA5C(int self, int theA)
{
    char *p = (char *)&D_006E9840;

    *(int *)(self + 0x2227C) = X4_func_0013F280((int)(p + 0x12540), theA, 0, 0);
}

extern "C" void func_001CFAA8(char *arg0)
{
    int temp_v0 = *(int *)(arg0 + 0x2227C);
    if (temp_v0 != -1) {
        char *p = (char *)&D_006E9840;
        func_00135594(p + 0x12540, temp_v0);
        func_001348B0(p + 0x12540, *(int *)(arg0 + 0x2227C));
        *(int *)(arg0 + 0x2227C) = -1;
    }
    *(int *)(arg0 + 0x225D8) = 0;
}

extern "C" void func_001CFB38(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x2227C)) = arg1;
}

extern "C" float func_001CFB48(int arg0, unsigned int arg1, unsigned int arg2)
{
    DogVector v1;
    DogVector v2;

    if (Xiiu_func_001D046C(arg0, arg1) == 0 || Xiiu_func_001D046C(arg0, arg2) == 0) {
        return 0.0f;
    }
    Xiiui_func_001D05F4(arg0, arg1, (int)&v1);
    Xiiui_func_001D05F4(arg0, arg2, (int)&v2);
    return func_00217F10(v2.m_x - v1.m_x, v2.m_z - v1.m_z);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CFBE4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CFCA8);

extern "C" void func_001CFDA4(int arg0, unsigned int arg1, int arg2)
{
    register unsigned int v0 asm("$2") = arg1 >> 28;
    register unsigned int a3 asm("$7") = v0 & 3;
    switch (a3) {
    case 1:
        Xii_func_001D8FEC(Xiiu_func_001D2B8C(arg0, arg1), arg2);
        break;
    case 2:
        Xii_func_001D8FEC(Xiiu_func_001D2BA8(arg0, arg1), arg2);
        break;
    }
}

extern "C" int func_001CFE1C(int arg0, unsigned int arg1)
{
    int temp_a2;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {                              
    case 1:
        return Xii_func_001D8DC4(Xiiu_func_001D2B8C(arg0, arg1));
    case 2:
        return Xii_func_001D8DC4(Xiiu_func_001D2BA8(arg0, arg1));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CFE78);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D024C);

extern "C" int func_001D044C(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x1D35C));
}

extern "C" int func_001D045C(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x1D99C));
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D046C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D0530);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D05F4);

extern "C" int func_001D06B8(int arg0, unsigned int arg1, int arg2)
{
    int var_v0;
    int temp_v1;

    var_v0 = Xiiu_func_001D046C(arg0, arg1);
    temp_v1 = (arg1 >> 0x1C) & 3;
    if (var_v0 != 0) {
        switch (temp_v1) {                          
        case 1:
            Xiii_func_001D8964(Xiiu_func_001D2B8C((int) arg0, arg1), (int) arg2);
block_6:
            var_v0 = (int) 1;
            
            return var_v0;
        case 2:
            Xiii_func_001DB774(Xiiu_func_001D2BA8((int) arg0, arg1), arg2);
            goto block_6;
        default:
            return (int) 1;
        }
    } else {
        return var_v0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D0758);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D080C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D091C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D0C64);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D0EFC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D10D0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D1410);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D1720);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D17C8);

extern "C" void func_001D1838(int unused, unsigned int arg1, unsigned int arg2)
{
    register unsigned int v0 asm("$2") = arg1 >> 28;
    register unsigned int a3 asm("$7") = v0 & 3;
    switch (a3) {
    case 1: {
        register char *ret asm("$2") = (char *)func_001D2B8C();
        int mask = arg2 & 0x00FFFFFF;
        register int idx asm("$3") = (arg2 >> 24) << 2;
        idx += (int)ret;
        idx += 0x3EC;
        *(int *)idx |= mask;
        break;
    }
    case 2:
        *(int *)((char *)func_001D2BA8() + 0x120) |= arg2;
        break;
    default:
        break;
    }
}

extern "C" void func_001D18C4(int unused, unsigned int arg1, unsigned int arg2)
{
    register unsigned int v0 asm("$2") = arg1 >> 28;
    register unsigned int a3 asm("$7") = v0 & 3;
    switch (a3) {
    case 1: {
        register char *ret asm("$2") = (char *)func_001D2B8C();
        int mask = arg2 & 0x00FFFFFF;
        register int idx asm("$3") = (arg2 >> 24) << 2;
        idx += (int)ret;
        idx += 0x3EC;
        *(int *)idx &= ~mask;
        break;
    }
    case 2:
        *(int *)((char *)func_001D2BA8() + 0x120) &= ~arg2;
        break;
    default:
        break;
    }
}

extern "C" int func_001D1958(int arg0, unsigned int arg1)
{
    int temp_a2;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {                              
    case 1:
        return Xii_func_001D9F40(Xiiu_func_001D2B8C(arg0, arg1));
    case 2:
        return 0;
    default:
        return 0;
    }
}

extern "C" int func_001D19A8(int arg0, unsigned int arg1)
{
    int temp_a2;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {                              
    case 1:
        return Xii_func_001D9F84(Xiiu_func_001D2B8C(arg0, arg1));
    case 2:
        return 0;
    default:
        return 0;
    }
}

extern "C" int func_001D19F8(int arg0, unsigned int arg1)
{
    int temp_a2;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {                              
    case 1:
        return Xii_func_001DA05C(Xiiu_func_001D2B8C(arg0, arg1));
    case 2:
        return 0;
    default:
        return 0;
    }
}

extern "C" int func_001D1A48()
{
    return ~(*(int *)((int)&D_00727BD0)) != 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFD0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFE0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFE8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFF0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFF8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC000);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC008);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC010);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC018);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC020);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC028);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC030);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC038);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC040);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC048);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC050);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC058);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC060);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC068);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC070);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC078);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D1A5C);
