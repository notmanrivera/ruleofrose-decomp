#include "include_asm.h"
#include "mnu/mnucommon.h"
#include "game/gamtrg.h"
#include "game/gamman.h"
extern "C" void X_func_001C6A40(GamMan *, int) asm("func_001C6A40");
extern "C" int X_func_001F184C(...) asm("func_001F184C");
extern "C" void func_001D5DA0(GamMan *, int);
extern "C" void func_001D3588(GamMan *);
extern "C" void func_0017756C(void *, int);
extern "C" int X_func_001D2BA8(...) asm("func_001D2BA8");
extern "C" int X_func_00191E04(...) asm("func_00191E04");
struct Item1A6C0 {
    int unk0;
    int unk4;
    unsigned short unk8;
    unsigned short unkA;
    int unkC;
    Item1A6C0(void *sub, unsigned short id);
};
extern "C" void func_001C7A4C(GamMan *, unsigned short);
extern "C" void func_001C9784(GamMan *, unsigned short);
extern "C" int func_001DBFA0(void *, unsigned short);
inline Item1A6C0::Item1A6C0(void *sub, unsigned short id)
{
    unk0 = func_001DBFA0(sub, id);
    unk8 = id;
}
extern "C" int X_func_0017F200(...) asm("func_0017F200");
extern "C" int X_func_0024B3F8(...) asm("func_0024B3F8");
extern "C" int X_func_00191D20(...) asm("func_00191D20");
extern "C" int X_func_00191D74(...) asm("func_00191D74");
extern "C" int X_func_00191DC8(...) asm("func_00191DC8");
extern "C" int X_func_00191ED0(...) asm("func_00191ED0");
extern "C" int X_func_00191F98(...) asm("func_00191F98");
extern "C" int func_001C8A28(void *, int, int);
extern "C" int func_001BFFCC(int, int);
extern "C" int func_001C020C(int, int);
extern "C" int func_001C0254(int, int);
extern "C" int func_001BE084(int);
extern "C" void func_001BDC54(int);
extern "C" void func_0018BC18(char *, int);
extern "C" void func_00183B24(char *, int);
extern "C" void X_del(void *) asm("__builtin_delete");
extern "C" void func_0017762C(void *);
struct ListNode {
    ListNode *prev;
    ListNode *next;
    char pad[8];
    int count;
};
extern "C" int func_00143D7C(char *, char *, int);
extern "C" int func_001C6FE0(GamMan *, int, int, int);
extern "C" void func_001CC250(GamMan *, int, int, int, int, int);
extern "C" int func_001CFBE4(int, unsigned int, int);
extern "C" int func_0017EA44(void *, int);
extern "C" int func_001DB8E8(char *, int, int);
extern "C" int func_00279C98(void *, const char *, ...);
extern "C" void X_func_001CF7D0(char *, const void *) asm("func_001CF7D0");
extern "C" void X_func_001CF854(char *, void *, int, int) asm("func_001CF854");
extern int D_00298EE0;
extern int D_006E9640;
struct Header1F84 {
    int data[8];
};
struct Entry1F84 {
    int data[12];
};
struct DstEntry1F84 {
    Entry1F84 entry;
    int pad[8];
};
extern "C" int func_001D2AAC(int, unsigned int);
extern "C" int func_001D2ADC(int, unsigned int);
extern "C" int func_001D2B10(int, unsigned int);
extern "C" int func_001D890C(int, int);
extern "C" int Xiii_func_001DB71C(int, int) asm("func_001DB71C");
extern "C" int func_001D89C4(int, int);
extern "C" int func_001DB7CC(int, int);
extern "C" int X_func_001D84B0(...) asm("func_001D84B0");
extern "C" void func_001331F4(void *, int, int, int, int, int, float);
extern "C" char vtbl_GamMan[] asm("_vt$6GamMan");
extern "C" void GamSndMan__vfunc_01(void *, int);
extern "C" void func_001DD3EC(void *, int);
extern "C" float func_0010A650__8DogActor(void *);
extern "C" int X_func_001C772C(...) asm("func_001C772C");
extern "C" int X_func_001E4540(...) asm("func_001E4540");
extern "C" void *bsearch(const void *, const void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern "C" int func_001C0534(int, unsigned int);
extern "C" int func_001BFFAC(unsigned short *, unsigned short *);
extern "C" int Xiiu_func_001D2D00(int, unsigned int) asm("func_001D2D00");
extern "C" int func_001D966C(int);
extern "C" int X_loadModel__9MagSystemii(void *, int, int) asm("loadModel__9MagSystemii");
extern "C" void func_001CCC30(GamMan *, int);
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
extern "C" void func_001CBA0C(GamMan *, void *, int);
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
extern "C" void func_001CB01C(GamMan *, int);
extern "C" void func_001CDF5C(GamMan *, int, int);
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

static inline void *gamSub22220() {
    void *p = (void *)&D_007812C0;
    return (char *)p + 0x22220;
}

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

extern "C" void func_001BDB4C(char *self, int flags)
{
    func_001BE084((int)self);

    if (*(int *)(self + 0x1080) != 0) {
        func_001BDC54((int)self);
    }

    char *p = self + 0x78C;
    char *start = self + 0x14;

    register int two PS2_REG("$5") = 2;
    func_0018BC18(p, two);

    if (start != 0) {
        if (start != p) {
            do {
                p -= 0x3BC;
                func_00183B24(p, 2);
            } while (start != p);
        }
    }

    if (flags & 1) {
        X_del(self);
        return;
    }
}

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

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB1A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB1B0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB1C0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB1C8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB210);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB258);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB2A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB2E8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB330);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnuSelectLanguage", D_002FB350);

INCLUDE_ASM("asm/nonmatchings/mnu/mnuSelectLanguage", func_001BDE58);

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

INCLUDE_ASM("asm/nonmatchings/mnu/mnuSelectLanguage", func_001BE110);

extern "C" int func_001BE414(int);

class FileReader {
public:
    int unk0;
    int unk4;
    ~FileReader();
};
