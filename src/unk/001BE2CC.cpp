#include "include_asm.h"
#include "game/gamtrg.h"
#include "game/gamman.h"
#include "unk/001BE2CC.h"
extern int D_002B8DA8[];
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
extern "C" int X_func_0024B3F8(...) asm("rxGsVSync");
extern "C" int X_func_00191D20(...) asm("func_00191D20");
extern "C" int X_func_00191D74(...) asm("func_00191D74");
extern "C" int X_func_00191DC8(...) asm("func_00191DC8");
extern "C" int X_func_00191ED0(...) asm("func_00191ED0");
extern "C" int X_func_00191F98(...) asm("func_00191F98");
extern "C" int func_001C8A28(void *, int, int);
extern "C" int func_001BFFCC(FntCanvas *, int);
extern "C" int func_001C020C(FntCanvas *, int);
extern "C" int func_001C0254(FntCanvas *, int);
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
extern "C" int func_001C0534(FntCanvas *, unsigned int);
extern "C" int func_001BFFAC(unsigned short *, unsigned short *);
extern "C" int Xiiu_func_001D2D00(int, unsigned int) asm("func_001D2D00");
extern "C" int func_001D966C(int);
extern "C" int X_loadModel__9MagSystemii(void *, int, int) asm("loadModel__9MagSystemii");
extern "C" void func_001CCC30(GamMan *, int);
extern "C" int func_001C0148(FntCanvas *, int);
extern "C" int func_001C0298(FntCanvas *, int);
extern "C" int func_001C02B8(FntCanvas *, int);
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
extern "C" int X_func_00243C40(int, int, int) asm("rxFileSeek");
extern "C" int X_func_001CBE38(int, int) asm("func_001CBE38");
extern int D_006FE6A0;
extern "C" void X_func_00144500(...) asm("func_00144500");
extern char *D_007B205C;
extern "C" int X_func_00191E58(...) asm("func_00191E58");
extern char D_006FBD80[];
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_func_001BE564(...) asm("func_001BE564");
extern "C" int Xiiiii_func_001BE444(FileReader *, int, int, int) asm("func_001BE444");
extern "C" int Xiii_func_001BE3C4(FileReader *, int) asm("func_001BE3C4");
extern "C" int Xiiiii_func_001BE36C(FileReader *, int, int, int) asm("func_001BE36C");
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
extern "C" int X_func_002437F8(...) asm("rxFileClose");
extern "C" int X_func_00243938(...) asm("func_00243938");
extern "C" int X_func_00243CD8(...) asm("rxFileSync");
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

extern "C" void __10FileReader(FileReader *arg0)
{
    arg0->m_req = 0;
    arg0->m_fd = -1;
}

extern "C" int func_001BE414(FileReader *);

FileReader::~FileReader()
{
    if (m_fd >= 0) {
        func_001BE414(this);
    }
}

extern "C" int func_001BE338(FileReader *arg0, int arg1)
{
    arg0->m_fd = X_func_00243788(arg1, 0x8001);
    return 0;
}

extern "C" int func_001BE36C(FileReader *arg0, int arg1, int arg2, int arg3)
{
    return X_func_00243938(arg1, arg2, arg3);
}

extern "C" int func_001BE38C(FileReader *arg0, int arg1, int arg2)
{
    int temp_v1;

    temp_v1 = arg0->m_fd;
    if (temp_v1 < 0) {
        return -1;
    }
    return Xiiiii_func_001BE36C(arg0, temp_v1, arg1, arg2);
}

extern "C" int func_001BE3C4(FileReader *arg0, int arg1)
{
    if (arg1 == arg0->m_fd) {
        X_func_002437F8(arg1);
        arg0->m_fd = -1;
        return 1;
    }
    X_func_002437F8(arg1);
    return 2;
}

extern "C" int func_001BE414(FileReader *arg0)
{
    int temp_v1;

    temp_v1 = arg0->m_fd;
    if (temp_v1 < 0) {
        return -1;
    }
    return Xiii_func_001BE3C4(arg0, temp_v1);
}

extern "C" int func_001BE444(FileReader *theA, int theB, int theC, int theD)
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

extern "C" int func_001BE490(FileReader *arg0, int arg1, int arg2)
{
    int temp_v1;

    temp_v1 = arg0->m_fd;
    if (temp_v1 < 0) {
        return -1;
    }
    return Xiiiii_func_001BE444(arg0, temp_v1, arg1, arg2);
}

extern "C" int func_001BE4C8(FileReader *arg0, int arg1, int *arg2)
{
    int temp_v0;
    int var_v1;

    var_v1 = 0;
    temp_v0 = arg0->m_fd;
    if (temp_v0 >= 0) {
        var_v1 = X_func_00243CD8(temp_v0, 1);
    }
    if (arg2 != 0) {
        *arg2 = arg0->m_fd;
    }
    return var_v1 == 0;
}

extern "C" void func_001BE524__10FileReaderP11FileReadReqi(FileReader *self, FileReadReq *theReq, int theA)
{
    self->m_req = theReq;
    theReq->m_state = 0;
    return X_func_001BE564(self, theA);
}

extern "C" void func_001BE548(FileReader *theOut, FileReadReq *theA, int theB)
{
    theOut->m_req = theA;
    return X_func_001BE564(theOut, theB);
}

extern "C" int X_func_002051CC(int) asm("func_002051CC");
extern int D_002D8FFC;
extern "C" int func_001BE564(FileReader *self, int arg1)
{
    while (1) {
        while ((self->m_req->m_state & 1) == 0) {
            FileReadReq *req = self->m_req;
            int state = req->m_state;
            switch (state >> 1) {
            case 0:
                if (req->m_path != 0) {
                    func_001BE338(self, req->m_path);
                    register FileReadReq *r PS2_REG("$3") = self->m_req;
                    r->m_fd = self->m_fd;
                    self->m_req->m_path = 0;
                    goto inc_state;
                }
                req->m_state = state + 2;
                continue;
            case 1:
                if (req->m_seekWhence >= 0) {
                    func_001BE444(self, req->m_fd, req->m_seekOffset, req->m_seekWhence);
                    self->m_req->m_seekWhence = -1;
                    goto inc_state;
                }
                req->m_state = state + 2;
                continue;
            case 2:
                if (req->m_size > 0) {
                    func_001BE36C(self, req->m_fd, req->m_buf, req->m_size);
                    self->m_req->m_size = 0;
                    goto inc_state;
                }
                req->m_state = state + 2;
                continue;
            case 3:
                if (req->m_closeFlag != 0) {
                    func_001BE3C4(self, req->m_fd);
                    self->m_req->m_closeFlag = 0;
                inc_state:
                    self->m_req->m_state++;
                    continue;
                }
                req->m_state = state + 2;
                return 0;
            default:
                return 0;
            }
        }

        if (arg1 == 0) {
            do {
                if (D_002D8FFC != 0) {
                    X_func_002051CC(D_002D8FFC);
                } else {
                    X_func_0024B3F8(1);
                    X_func_0017F200(&D_007B2580);
                }
            } while (func_001BE4C8(self, 0, 0) != 1);
        } else {
            int r = func_001BE4C8(self, 0, 0);
            if (r < 0) {
                return -100;
            }
            if (r == 0) {
                return 1;
            }
        }
        self->m_req->m_state++;
    }
}

extern "C" void __11FileReadReq(FileReadReq *arg0)
{
    Xiiii_memset((int)arg0, 0, 0x24);
    arg0->m_fd = -1;
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

extern "C" int func_001BE8BC(const unsigned char *arg0, int *arg1, int *arg2, int *arg3)
{
    int yearDays = 0;
    int leap = 0;
    int days = 0;
    int i;

    *arg1 = 0;
    *arg2 = 0;
    if ((unsigned char)(arg0[6] - 1) >= 12) {
        return 0;
    }

    unsigned char year = arg0[7];
    if ((year & 3) == 0) {
        leap = 1;
        if ((year % 100U) == 0) {
            leap = ((int)year % 400 == 0);
        }
    }

    for (i = 0; i < 12; i++) {
        yearDays += D_002B8DA8[i];
        if (i == 1) {
            yearDays += leap;
        }
    }

    int yearSec = yearDays * 0x15180;
    *arg3 = yearSec;

    for (i = 0; i < arg0[6] - 1; i++) {
        days += D_002B8DA8[i];
        if (i == 1) {
            days += leap;
        }
    }

    days += arg0[5];
    int sec = (((days * 24 + arg0[3]) * 60 + arg0[2]) * 60) + arg0[1];
    *arg1 = sec;
    *arg2 = yearSec - sec;
    return 1;
}

// NON_MATCHING: 51/83 differ (size 0x14C, game 0x158), 13 edits
#ifdef NON_MATCHING
extern "C" int X_func_001BE8BC(const unsigned char *, int *, int *, int *) asm("func_001BE8BC");
extern "C" int func_001BEA18(const unsigned char *arg0, const unsigned char *arg1, int *arg2, int *arg3)
{
    int a0 = 0;
    int a1 = 0;
    int a2 = 0;
    int b0 = 0;
    int b1 = 0;
    int b2 = 0;

    *arg2 = 0;
    *arg3 = 0;

    int ok = X_func_001BE8BC(arg0, &a0, &a1, &a2);
    if (ok != 1) {
        return 0;
    }
    if (X_func_001BE8BC(arg1, &b0, &b1, &b2) != ok) {
        return 0;
    }

    int y1 = arg1[7];
    int prev;
    if (y1 == 0) {
        prev = 99;
    } else {
        prev = y1 - 1;
    }
    int diff;
    if (arg0[7] == y1) {
        diff = b0 - a0;
    } else if (arg0[7] == prev) {
        diff = a1 + b0;
    } else {
        diff = 0x57E04;
    }

    int h = diff / 3600;
    *arg2 = h;
    if (h >= 100) {
        *arg2 = 99;
        *arg3 = 59;
        return 1;
    }
    *arg3 = diff % 3600;
    *arg3 /= 60;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BEA18);
#endif

extern "C" void func_001BEB70(FntCanvas *arg0)
{
    register int state PS2_REG("$2") = 2;
    register int mode PS2_REG("$3") = 4;
    arg0->m_bpp = mode;
    arg0->m_propStep = state;
    arg0->m_bgColor = 0x80;
    arg0->m_alphaFlag = 1;
    arg0->m_ownBuf = 0;
    arg0->m_buf = 0;
    arg0->m_width = 0;
    arg0->m_height = 0;
    arg0->m_bufSize = 0;
    arg0->m_fgColor = 0;
    arg0->m_cellW = 0;
    arg0->m_cellH = 0;
    arg0->m_glyphCount = 0;
    arg0->m_fnt = 0;
    arg0->m_fixedStep = 0;
    arg0->m_unk00 = 0;
}

extern "C" void func_001BEBC4(void *self, int theFlags)
{
    if (theFlags & 1) {
        return X___builtin_delete(self);
    }
}

// NON_MATCHING: 18/113 differ, 18 edits
#ifdef NON_MATCHING
extern "C" void X_func_001C0078(FntCanvas *, int, int *, int *, int *) asm("func_001C0078");
extern "C" void func_001BEBEC(FntCanvas *arg0, FntDataHdr *arg1)
{
    if (arg1 == 0) {
        return;
    }

    arg0->m_fnt = arg1;
    arg0->m_cellW = arg1->m_cellW;
    arg0->m_cellH = arg1->m_cellH;
    arg0->m_fntBpp = arg1->m_bpp;
    int count = arg1->m_glyphCount;
    arg0->m_glyphCount = count;
    if (arg1->m_flags0B & 2) {
        arg0->m_glyphCount = count - 0x1130;
    }
    FntDataHdr *p = arg0->m_fnt;
    if (p->m_flags0B & 4) {
        arg0->m_glyphCount = arg0->m_glyphCount - 0xDE0;
    }
    arg0->m_codeTbl = 0;
    arg0->m_metricTbl = 0;
    arg0->m_bmpTbl = 0;
    arg0->m_useProp = 0;
    arg0->m_hasMetrics = 0;

    if (p->m_codeTblOff != 0) {
        register long off PS2_REG("$5") = p->m_codeTblOff;
        arg0->m_codeTbl = (int)(off + (int)arg0->m_fnt + 4);
    }
    if (p->m_metricTblOff != 0) {
        register long off PS2_REG("$5") = p->m_metricTblOff;
        arg0->m_metricTbl = (int)(off + (int)arg0->m_fnt + 4);
        arg0->m_useProp = 1;
        arg0->m_hasMetrics = 1;
    }
    if (p->m_bmpTblOff != 0) {
        register long off PS2_REG("$5") = p->m_bmpTblOff;
        arg0->m_bmpTbl = (int)(off + (int)arg0->m_fnt + 4);
    }

    int a = 0;
    int b = 0;
    int c = 0;
    X_func_001C0078(arg0, 'A', &a, &b, &c);
    X_func_001C0078(arg0, 'Z', &a, &b, &c);
    X_func_001C0078(arg0, 'a', &a, &b, &c);
    X_func_001C0078(arg0, 'z', &a, &b, &c);

    int bits = arg0->m_cellW * arg0->m_fntBpp;
    int stride = (bits >> 3) + ((bits & 7) != 0);
    int glyphSize = stride * arg0->m_cellH;
    arg0->m_rowBytes = stride;
    arg0->m_glyphBytes = glyphSize;
    arg0->m_totalBmpSize = glyphSize * count;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BEBEC);
#endif

extern "C" int func_001BEDB0()
{
    return 1;
}

extern "C" int func_001BEDB8()
{
    return 1;
}

// NON_MATCHING: 1/51 differ, 1 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_001BEE8C(FntCanvas *) asm("func_001BEE8C");
extern "C" int func_001BEDC0(FntCanvas *arg0, unsigned char *arg1, int arg2, int arg3, int arg4)
{
    Xii_func_001BEE8C(arg0);
    arg0->m_width = arg2 & 0xFF80;
    if (arg4 == 4) {
        arg0->m_height = arg3 & 0xFF80;
    } else if (arg4 == 8) {
        arg0->m_height = arg3 & 0xFFC0;
    } else {
        return 0;
    }

    int w = arg0->m_width;
    if (w == 0) {
        return 0;
    }
    int h = arg0->m_height;
    if (h == 0) {
        return 0;
    }

    int size = w * h;
    arg0->m_bpp = arg4;
    switch (arg4) {
    case 4:
        size >>= 1;
    case 8:
        break;
    default:
        return 0;
    }
    arg0->m_buf = arg1;
    arg0->m_bufSize = size;
    arg0->m_ownBuf = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BEDC0);
#endif

extern "C" int func_001BEE8C(FntCanvas *arg0)
{
    if (arg0->m_ownBuf == 1) {
        if (arg0->m_buf == 0) {
            return 0;
        }
        arg0->m_ownBuf = 0;
        arg0->m_buf = 0;
    } else {
        if (arg0->m_buf == 0) {
            return 0;
        }
        arg0->m_ownBuf = 0;
        arg0->m_buf = 0;
    }
    return 1;
}

extern "C" int func_001BEEB4(FntCanvas *self)
{
    void *p = self->m_buf;

    if (p == 0) {
        return 0;
    }
    Xiiii_memset((int)p, self->m_bgColor, self->m_bufSize);
    return 1;
}

extern "C" int func_001BEEEC(FntCanvas *self, int theA)
{
    if (func_001C0298(self, theA) == 1) {
        return self->m_cellW >> 1;
    }
    return self->m_cellW;
}

extern "C" int func_001BEF24(FntCanvas *arg0, int arg1, int arg2, int arg3, int arg4)
{
    unsigned char *buf = arg0->m_buf;
    if (buf == 0) {
        return 0;
    }

    int pitch = arg0->m_width;
    int x, y;
    unsigned char *p;
    if (arg0->m_bpp == 4) {
        int c = arg0->m_bgColor & 0xF;
        unsigned char color = c | (c << 4);
        unsigned char *row = buf + (arg1 >> 1) + ((pitch >> 1) * arg2);
        int w = arg3 >> 1;
        for (y = 0; y < arg4; y++) {
            p = row + (arg0->m_width >> 1) * y;
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
            p = row + arg0->m_width * y;
            if (arg3 > 0) {
                x = arg3;
                do {
                    --x;
                    *p++ = (unsigned char)arg0->m_bgColor;
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
extern "C" void func_001BFE30(FntCanvas *arg0, int arg1)
{
    int temp_v1 = arg0->m_height;
    if (arg1 >= temp_v1 || arg1 < -temp_v1) {
        return;
    }

    int abs_arg1;
    if (arg1 >= 0) {
        abs_arg1 = arg1;
    } else {
        abs_arg1 = -arg1;
    }

    int size = arg0->m_width * abs_arg1;
    int fill = 0;
    switch (arg0->m_bpp) {
    case 4:
        size >>= 1;
        fill = (arg0->m_bgColor & 0xF) | ((arg0->m_bgColor & 0xF) << 4);
        break;
    case 8:
        fill = arg0->m_bgColor;
        break;
    }

    unsigned char *buf = arg0->m_buf;
    int total = arg0->m_bufSize;
    if (arg1 < 0) {
        X_memmove(buf, buf + size, total - size);
        X_memset(arg0->m_buf + (arg0->m_bufSize - size), fill, size);
    } else {
        X_memmove(buf + size, buf, total - size);
        X_memset(arg0->m_buf, fill, size);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001BFE30);
#endif

extern "C" void func_001BFF28(FntCanvas *self, int theA)
{
    self->m_bgColor = theA;

    switch (self->m_bpp) {
    case 4:
        break;
    case 8:
        if (self->m_alphaFlag != 0) {
            self->m_bgColor = theA | 0x80;
        }
        break;
    }
}

extern "C" void func_001BFF5C(FntCanvas *arg0, int arg1)
{
    arg0->m_alphaFlag = arg1;
}

extern "C" void func_001BFF64(FntCanvas *self, int theA)
{
    switch (self->m_bpp) {
    case 4:
        self->m_fgColor = theA & 0xF;
        break;
    case 8:
        self->m_fgColor = theA & 0xFF;
        if (self->m_alphaFlag != 0) {
            self->m_fgColor = (theA & 0xFF) | 0x80;
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

extern "C" int func_001BFFCC(FntCanvas *arg0, int arg1)
{
    short key = arg1;

    if (*(int *)&arg0->m_fnt->m_unk08[0] & 0x06000000) {
        if ((unsigned short)arg1 > 0x813F) {
            int ret = func_001C0534(arg0, (unsigned short)arg1);
            if (ret >= 0) {
                ret += arg0->m_glyphCount;
            }
            return ret;
        }
    }

    void *found = bsearch(&key, (void *)arg0->m_codeTbl, arg0->m_glyphCount, 2, (int (*)(const void *, const void *))func_001BFFAC);
    if (found == 0) {
        return -1;
    }
    return ((int)found - arg0->m_codeTbl) / 2;
}

extern "C" void func_001C0078(FntCanvas *arg0, int arg1, int *arg2, int *arg3, int *arg4)
{
    if (arg1 < 0x20) {
        *arg2 = 0;
        *arg3 = 0;
        *arg4 = 0;
        return;
    }

    if (arg0->m_hasMetrics != 0) {
        int temp = func_001BFFCC(arg0, arg1);
        if (temp < 0) {
            *arg2 = 0;
            *arg3 = arg0->m_cellW;
            *arg4 = 0;
            return;
        }

        *arg2 = func_001C020C(arg0, temp);
        *arg3 = func_001C0254(arg0, temp);

        register int var_a0 PS2_REG("$4");
        if (arg0->m_hasMetrics != 0) {
            var_a0 = arg0->m_propStep;
        } else {
            var_a0 = arg0->m_fixedStep;
        }
        *arg4 = var_a0;
        return;
    }

    *arg2 = 0;
    *arg3 = func_001C0148(arg0, arg1);
    *arg4 = 0;
}

extern "C" int func_001C0148(FntCanvas *arg0, int arg1)
{
    register int one PS2_REG("$18") = 1;
    register int var_v0 PS2_REG("$2");
    int flag = 0;

    if (arg0->m_hasMetrics == one) {
        flag = arg0->m_useProp == one;
    }
    if (flag == one) {
        var_v0 = 6;
        if (arg1 != 0x20 && arg1 != 0x8140) {
            return func_001C0254(arg0, func_001BFFCC(arg0, arg1));
        }
    } else if (func_001C0298(arg0, arg1) == one) {
        var_v0 = arg0->m_cellW / 2;
    } else {
        var_v0 = 0;
        if (arg1 >= 0x21) {
            var_v0 = arg0->m_cellW;
        }
    }
    return var_v0;
}

extern "C" int func_001C020C(FntCanvas *arg0, int arg1)
{
    register int one PS2_REG("$3") = 1;
    int flag = 0;

    if (arg0->m_hasMetrics == one) {
        flag = (arg0->m_useProp == one);
    }
    if (flag == one) {
        if (arg1 < 0) {
            return arg0->m_cellW;
        }
        return *(unsigned char *)((arg1 * 2) + arg0->m_metricTbl);
    }
    return 0;
}

extern "C" int func_001C0254(FntCanvas *self, int theA)
{
    int r = self->m_cellW;

    if (self->m_hasMetrics != 0 && self->m_useProp != 0 && theA >= 0) {
        r = *(unsigned char *)(self->m_metricTbl + ((theA << 1) + 1 & 0xFF));
    }
    return r;
}

extern "C" int func_001C0298(FntCanvas *arg0, int arg1)
{
    if ((unsigned int)(arg1 - 0x20) < 0x60U) {
        return 1;
    }
    return (unsigned int)(arg1 - 0xA0) < 0x40U;
}

extern "C" int func_001C02B8(FntCanvas *arg0, int arg1)
{
    int v = arg1 & 0xFF00;

    if ((unsigned int)(v - 0x8000) < 0x1F01U) {
        return 1;
    }
    return (unsigned int)(v - 0xE000) < 0xA01U;
}

extern "C" int func_001C02E4(FntCanvas *arg0, int arg1)
{
    return (unsigned int) (arg1 - 0x20) < 0xE0U;
}

extern "C" int func_001C02F0()
{
    return 0;
}

// NON_MATCHING: 37/53 differ, 1 reloc differs (size 0xD4, game 0xD8), 21 edits
#ifdef NON_MATCHING
extern "C" int func_001C02F8(FntCanvas *arg0, const unsigned char *arg1)
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
            if (arg0->m_hasMetrics != 0) {
                total += arg0->m_propStep;
            } else {
                total += arg0->m_fixedStep;
            }
        }
    }
    return total;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001BE2CC", func_001C02F8);
#endif

extern "C" int func_001C03D0(FntCanvas *arg0, const unsigned char *arg1)
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
            if (arg0->m_hasMetrics != 0) {
                total += arg0->m_propStep;
            } else {
                total += arg0->m_fixedStep;
            }
        }
    }
    return total;
}

extern "C" int func_001C047C()
{
    return X_func_001C02F8();
}

extern "C" int func_001C0490(FntCanvas *arg0, const unsigned char *arg1)
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
extern "C" int func_001C0534(FntCanvas *arg0, unsigned int arg1)
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
