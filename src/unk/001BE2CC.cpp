#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BE564);

extern "C" void __11FileReadReq(int arg0)
{
    Xiiii_memset(arg0, 0, 0x24);
    (*(int *)(arg0)) = -1;
}

extern "C" int func_001BE768(const char *theName)
{
    int fd = X_func_00243788(theName, 0x8001);
    if (fd < 0) {
        return fd;
    }

    while (X_func_00243CD8(fd, 1) != 0) {
        X_func_0024B3F8(1);
        X_func_0017F200(&D_007B2580);
    }

    int size = X_func_00243C40(fd, 0, 2);

    while (X_func_00243CD8(fd, 1) != 0) {
        X_func_0024B3F8(1);
        X_func_0017F200(&D_007B2580);
    }

    X_func_002437F8(fd);

    while (X_func_00243CD8(fd, 1) != 0) {
        X_func_0024B3F8(1);
        X_func_0017F200(&D_007B2580);
    }

    return size;
}

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

INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BE8BC);

INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BEA18);

// NON_MATCHING: 2/21 differ, 2 edits
#ifdef NON_MATCHING
extern "C" void func_001BEB70(int arg0)
{
    M2C_FIELD(arg0, int *, 0x34) = 2;
    M2C_FIELD(arg0, int *, 0x18) = 4;
    M2C_FIELD(arg0, int *, 0x64) = 0x80;
    M2C_FIELD(arg0, int *, 0x68) = 1;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
    M2C_FIELD(arg0, int *, 0x2C) = 0;
    M2C_FIELD(arg0, int *, 0x38) = 0;
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    M2C_FIELD(arg0, int *, 0x44) = 0;
    M2C_FIELD(arg0, int *, 0x54) = 0;
    M2C_FIELD(arg0, int *, 0x30) = 0;
    M2C_FIELD(arg0, int *, 0) = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BEB70);
#endif

extern "C" void func_001BEBC4(void *self, int theFlags)
{
    if (theFlags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BEBEC);

extern "C" int func_001BEDB0()
{
    return 1;
}

extern "C" int func_001BEDB8()
{
    return 1;
}

// NON_MATCHING: 2/51 differ, 2 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_001BEE8C(int) asm("func_001BEE8C");
extern "C" int func_001BEDC0(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    Xii_func_001BEE8C(arg0);
    M2C_FIELD(arg0, int *, 0x10) = arg2 & 0xFF80;
    if (arg4 == 4) {
        M2C_FIELD(arg0, int *, 0x14) = arg3 & 0xFF80;
    } else {
        if (arg4 != 8) {
            return 0;
        }
        M2C_FIELD(arg0, int *, 0x14) = arg3 & 0xFFC0;
    }

    int w = M2C_FIELD(arg0, int *, 0x10);
    if (w == 0) {
        return 0;
    }
    int h = M2C_FIELD(arg0, int *, 0x14);
    if (h == 0) {
        return 0;
    }

    int size = w * h;
    M2C_FIELD(arg0, int *, 0x18) = arg4;
    switch (arg4) {
    case 4:
        size >>= 1;
    case 8:
        break;
    default:
        return 0;
    }
    M2C_FIELD(arg0, int *, 0xC) = arg1;
    M2C_FIELD(arg0, int *, 0x1C) = size;
    M2C_FIELD(arg0, int *, 4) = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BEDC0);
#endif

extern "C" int func_001BEE8C(int arg0)
{
    if (M2C_FIELD(arg0, int *, 4) == 1) {
        if (M2C_FIELD(arg0, int *, 0xC) == 0) {
            return 0;
        }
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0;
    } else {
        if (M2C_FIELD(arg0, int *, 0xC) == 0) {
            return 0;
        }
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0;
    }
    return 1;
}

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

extern "C" int func_001BEF24(char *arg0, int arg1, int arg2, int arg3, int arg4)
{
    unsigned char *buf = M2C_FIELD(arg0, unsigned char **, 0xC);
    if (buf == 0) {
        return 0;
    }

    int pitch = M2C_FIELD(arg0, int *, 0x10);
    int x, y;
    unsigned char *p;
    if (M2C_FIELD(arg0, int *, 0x18) == 4) {
        int c = M2C_FIELD(arg0, int *, 0x64) & 0xF;
        unsigned char color = c | (c << 4);
        unsigned char *row = buf + (arg1 >> 1) + ((pitch >> 1) * arg2);
        int w = arg3 >> 1;
        for (y = 0; y < arg4; y++) {
            p = row + (M2C_FIELD(arg0, int *, 0x10) >> 1) * y;
            if (w > 0) {
                x = w;
                do {
                    --x;
                    *p++ = color;
                } while (x != 0);
            }
        }
    } else {
        unsigned char *row = buf + arg1 + (pitch * arg2);
        for (y = 0; y < arg4; y++) {
            p = row + M2C_FIELD(arg0, int *, 0x10) * y;
            if (arg3 > 0) {
                x = arg3;
                do {
                    --x;
                    *p++ = (unsigned char)M2C_FIELD(arg0, int *, 0x64);
                } while (x != 0);
            }
        }
    }

    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BF024);

INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BF8C4);

// NON_MATCHING: 63/64 differ, 4 relocs differ (size 0x100, game 0xF8), 40 edits
#ifdef NON_MATCHING
extern "C" void *X_memmove(void *, const void *, unsigned int) asm("memmove");
extern "C" void *X_memset(void *, int, unsigned int) asm("memset");
extern "C" void func_001BFE30(char *arg0, int arg1)
{
    int temp_v1 = M2C_FIELD(arg0, int *, 0x14);
    if (arg1 >= temp_v1 || arg1 < -temp_v1) {
        return;
    }

    int abs_arg1;
    if (arg1 >= 0) {
        abs_arg1 = arg1;
    } else {
        abs_arg1 = -arg1;
    }

    int size = M2C_FIELD(arg0, int *, 0x10) * abs_arg1;
    int fill = 0;
    switch (M2C_FIELD(arg0, int *, 0x18)) {
    case 4:
        size >>= 1;
        fill = (M2C_FIELD(arg0, int *, 0x64) & 0xF) | ((M2C_FIELD(arg0, int *, 0x64) & 0xF) << 4);
        break;
    case 8:
        fill = M2C_FIELD(arg0, int *, 0x64);
        break;
    }

    char *buf = M2C_FIELD(arg0, char **, 0xC);
    int total = M2C_FIELD(arg0, int *, 0x1C);
    if (arg1 < 0) {
        X_memmove(buf, buf + size, total - size);
        X_memset(M2C_FIELD(arg0, char **, 0xC) + (M2C_FIELD(arg0, int *, 0x1C) - size), fill, size);
    } else {
        X_memmove(buf + size, buf, total - size);
        X_memset(M2C_FIELD(arg0, char **, 0xC), fill, size);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BFE30);
#endif

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

extern "C" int func_001BFFCC(int arg0, int arg1)
{
    short key = arg1;

    if (*(int *)(*(int *)((char *)arg0 + 0x54) + 8) & 0x06000000) {
        if ((unsigned short)arg1 > 0x813F) {
            int ret = func_001C0534(arg0, (unsigned short)arg1);
            if (ret >= 0) {
                ret += *(int *)((char *)arg0 + 0x44);
            }
            return ret;
        }
    }

    void *found = bsearch(&key, *(void **)((char *)arg0 + 0x58), *(int *)((char *)arg0 + 0x44), 2, (int (*)(const void *, const void *))func_001BFFAC);
    if (found == 0) {
        return -1;
    }
    return ((int)found - *(int *)((char *)arg0 + 0x58)) / 2;
}

extern "C" void func_001C0078(int arg0, int arg1, int *arg2, int *arg3, int *arg4)
{
    if (arg1 < 0x20) {
        *arg2 = 0;
        *arg3 = 0;
        *arg4 = 0;
        return;
    }

    if (*(int *)(arg0 + 0x24) != 0) {
        int temp = func_001BFFCC(arg0, arg1);
        if (temp < 0) {
            *arg2 = 0;
            *arg3 = *(int *)(arg0 + 0x38);
            *arg4 = 0;
            return;
        }

        *arg2 = func_001C020C(arg0, temp);
        *arg3 = func_001C0254(arg0, temp);

        register int var_a0 PS2_REG("$4");
        if (*(int *)(arg0 + 0x24) != 0) {
            var_a0 = *(int *)(arg0 + 0x34);
        } else {
            var_a0 = *(int *)(arg0 + 0x30);
        }
        *arg4 = var_a0;
        return;
    }

    *arg2 = 0;
    *arg3 = func_001C0148(arg0, arg1);
    *arg4 = 0;
}

extern "C" int func_001C0148(int arg0, int arg1)
{
    register int one PS2_REG("$18") = 1;
    register int var_v0 PS2_REG("$2");
    int flag = 0;

    if (M2C_FIELD(arg0, int *, 0x24) == one) {
        flag = M2C_FIELD(arg0, int *, 0x28) == one;
    }
    if (flag == one) {
        var_v0 = 6;
        if (arg1 != 0x20 && arg1 != 0x8140) {
            return func_001C0254(arg0, func_001BFFCC(arg0, arg1));
        }
    } else if (func_001C0298(arg0, arg1) == one) {
        var_v0 = M2C_FIELD(arg0, int *, 0x38) / 2;
    } else {
        var_v0 = 0;
        if (arg1 >= 0x21) {
            var_v0 = M2C_FIELD(arg0, int *, 0x38);
        }
    }
    return var_v0;
}

extern "C" int func_001C020C(int arg0, int arg1)
{
    register int one PS2_REG("$3") = 1;
    int flag = 0;

    if (M2C_FIELD(arg0, int *, 0x24) == one) {
        flag = (M2C_FIELD(arg0, int *, 0x28) == one);
    }
    if (flag == one) {
        if (arg1 < 0) {
            return M2C_FIELD(arg0, int *, 0x38);
        }
        return *(unsigned char *)((arg1 * 2) + M2C_FIELD(arg0, int *, 0x5C));
    }
    return 0;
}

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

// NON_MATCHING: 37/53 differ, 1 reloc differs (size 0xD4, game 0xD8), 21 edits
#ifdef NON_MATCHING
extern "C" int func_001C02F8(int arg0, const unsigned char *arg1)
{
    const unsigned char *p = arg1;
    int total = 0;
    int c;

    while ((c = *p++) != 0) {
        int width;
        if (func_001C0298(arg0, c) != 1) {
            c <<= 8;
            c |= *p;
            if (func_001C02B8(arg0, c) == 1) {
                p++;
                width = 0x12;
                if (c != 0x8164) {
                    width = 0xA;
                    if (c != 0x8149) {
                        goto call_148;
                    }
                }
                goto add_total;
            }
        } else {
        call_148:
            width = func_001C0148(arg0, c);
        add_total:
            total += width;
            if (*(int *)((char *)arg0 + 0x24) != 0) {
                total += *(int *)((char *)arg0 + 0x34);
            } else {
                total += *(int *)((char *)arg0 + 0x30);
            }
        }
    }
    return total;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001C02F8);
#endif

extern "C" int func_001C03D0(int arg0, const unsigned char *arg1)
{
    int total = 0;
    int c;
    const unsigned char *p = arg1;

    while ((c = *p++) != 0) {
        if (func_001C02E4(arg0, c) == 1) {
            int width;
            if (c == 0x8164) {
                width = 0x12;
            } else if (c == 0x8149) {
                width = 0xA;
            } else {
                width = func_001C0148(arg0, c);
            }
            total += width;
            if (*(int *)((char *)arg0 + 0x24) != 0) {
                total += *(int *)((char *)arg0 + 0x34);
            } else {
                total += *(int *)((char *)arg0 + 0x30);
            }
        }
    }
    return total;
}

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

// NON_MATCHING: 32/32 differ, 2 relocs differ (size 0x80, game 0x8C), 31 edits
#ifdef NON_MATCHING
struct C0534Entry { unsigned short m_start; unsigned short m_unk02; unsigned short m_num; unsigned short m_unk06; };
extern C0534Entry D_002B8DE8[] asm("D_002B8DE8");
extern "C" int func_001C0534(int arg0, unsigned int arg1)
{
    unsigned int key = arg1 & 0xFFFF;
    int total = 0;

    if (D_002B8DE8[1].m_start != 0) {
        int i = 1;
        do {
            if (key >= D_002B8DE8[i].m_start) {
                unsigned short start = D_002B8DE8[i].m_start;
                if ((int)key < start + D_002B8DE8[i].m_num) {
                    return total + (key - start);
                }
            }
            total = (total + D_002B8DE8[i].m_num) & 0xFFFF;
            i++;
        } while (D_002B8DE8[i].m_start != 0);
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001C0534);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001C05C0);

extern "C" void GamMan__vfunc_01(char *arg0, int arg1)
{
    char *vec = arg0 + 0x1A6C0;
    *(void **)(arg0 + 0x22AB4) = vtbl_GamMan;
    char *finish = *(char **)(vec + 4);
    char *start = *(char **)vec;
    if (start != finish) {
        do {
            start += 0x10;
        } while (start != finish);
    }
    GamSndMan__vfunc_01(arg0 + 0x18E00, 2);
    func_001DD3EC(arg0 + 0x40, 2);
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/001BE2CC", D_002FB398);

INCLUDE_RODATA("asm/nonmatchings/unk/001BE2CC", D_002FB3A0);

INCLUDE_RODATA("asm/nonmatchings/unk/001BE2CC", D_002FB3A8);

INCLUDE_RODATA("asm/nonmatchings/unk/001BE2CC", D_002FB3B0);
