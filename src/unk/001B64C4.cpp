#include "ror.h"
#include "include_asm.h"
#include "game/gamtrg.h"
#include "game/gamman.h"
#include "unk/001B64C4.h"
#include "unk/0020ED9C.h"
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

// NON_MATCHING: 10/323 differ, 0 relocs differ (size 0x50C, game 0x50C)
#ifdef NON_MATCHING
extern char c64Heap[] asm("D_006E9840");
extern "C" int c64_func_001C9198(GamMan *,C64Item) asm("func_001C9198");
extern "C" int c64_func_0018F0EC(MnuRpk *,int,int,int) asm("func_0018F0EC");
extern "C" int c64_func_0017F8FC(int,int) asm("func_0017F8FC");
extern "C" int c64_func_0013511C(int,int,int,int,int) asm("func_0013511C");
extern "C" int c64_func_001351B0(int,int,int) asm("func_001351B0");
extern "C" int c64_func_00135088(int,int,int,int,int) asm("func_00135088");
extern "C" int c64_func_001C5094(int,int,int,int) asm("func_001C5094");
extern "C" int c64_func_001C51E0(int,int,int) asm("func_001C51E0");
extern "C" int c64_func_001B070C(MnuItemView *,int,int) asm("func_001B070C");
extern "C" int c64_func_001C8214(int,int) asm("func_001C8214");
extern "C" int c64_func_001AF5E0(MnuItemView *) ASM_NOTHROW asm("func_001AF5E0");
extern "C" int c64_func_0018F41C(MnuRpk *,int,int) asm("func_0018F41C");
extern "C" int c64_func_0018C4D8(MnuRpk *,int,int) asm("func_0018C4D8");
extern "C" int func_001B64C4(MnuItemView *arg0_in, const BedPad *arg1) {
    register MnuItemView *arg0 PS2_REG("$17") = arg0_in;
    register int *choice PS2_REG("$16");
    int temp_a1_2;
    int temp_s2;
    int temp_s2_3;
    int var_s3;
    unsigned short temp_a1;
    unsigned int temp_v1;
    MnuRpk *temp_s0;
    register int temp_s0_2 PS2_REG("$16");
    MnuRpk *temp_s0_3;
    MnuRpk *temp_s0_4;
    register MnuRpk *temp_s0_5 PS2_REG("$16");
    register MnuItemView *temp_s2_2 PS2_REG("$18");
    register int *indexPtr PS2_REG("$16");

    temp_v1 = arg0->m_subState;
    var_s3 = 0;
    switch (temp_v1) {
    case 0:
        arg0->m_choice0 = 1;
        /* fallthrough */
    case 1:
        temp_s0 = &arg0->m_rpk0;
        arg0->m_subState = 6U;
        var_s3 = 2;
        c64_func_0018F0EC(temp_s0, 0x26, 1, -1);
        c64_func_0018F0EC(temp_s0, 0x27, 1, -1);
        c64_func_0018F0EC(temp_s0, 0x28, 1, -1);
        c64_func_0018F0EC(temp_s0, 0x29, 1, -1);
        arg0->m_choice0 = 1;
        break;
    case 6:
        if ((arg1->m_dpadRepeat & 0x10) && ((choice = &arg0->m_choice0, *choice) == 1)) {
            var_s3 = 1;
            c64_func_0017F8FC((int)&D_007B2580, 1);
            *choice = 0;
        }
        if ((arg1->m_dpadRepeat & 0x40) && ((choice = &arg0->m_choice0, *choice) == 0)) {
            var_s3 |= 2;
            c64_func_0017F8FC((int)&D_007B2580, 1);
            *choice = 1;
        }
        temp_a1 = arg1->m_trigger;
        if ((temp_a1 >> 14) & 1) {
            switch (arg0->m_choice0) {
            case 0: var_s3 |= 4; break;
            case 1: var_s3 |= 8; break;
            }
        }
        if ((temp_a1 >> 13) & 1) {
            var_s3 |= 8;
            arg0->m_choice0 = 1;
        }
        if (var_s3 & 4) {
            temp_s2 = arg0->m_unk2470;
            arg0->m_unk248C = 1;
            if (temp_s2 == 1) {
                if (arg0->m_unk246C == 0) {
                    temp_s0_2 = (int)&c64Heap;
                    temp_s0_2 += 0x12540;
                    c64_func_0013511C(temp_s0_2, arg0->m_texHandle, 0, 0, 0x80);
                    c64_func_001351B0(temp_s0_2, arg0->m_texHandle, 0);
                    c64_func_00135088(temp_s0_2, arg0->m_texHandle, 0xF, 0, 0x80);
                    c64_func_001C5094((int)&D_007812C0, 8, 1, 0);
                    c64_func_001C5094((int)&D_007812C0, 4, 1, 0);
                    c64_func_001C51E0((int)&D_007812C0, 8, 0xF);
                    c64_func_001C51E0((int)&D_007812C0, 4, 0xF);
                    arg0->m_unk246C = temp_s2;
                }
            }
            c64_func_0017F8FC((int)&D_007B2580, 4);
            arg0->m_subState = 7U;
        }
        if (var_s3 & 8) {
            c64_func_0017F8FC((int)&D_007B2580, 3);
            goto block_35;
        }
        break;
    case 7:
        arg0->m_subState = 8U;
        break;
    case 8:
        arg0->m_subState = 9U;
        break;
    case 9:
        arg0->m_subState = 0xAU;
        break;
    case 10:
        indexPtr = (int *)((char *)arg0 + 8);
        temp_s2_2 = (MnuItemView *)((char *)arg0 + 4);
        temp_a1_2 = *indexPtr;
        if (((unsigned short *)((C64Item **)&temp_s2_2->m_item12)[temp_a1_2])[4] != 0xA00) {
            if (c64_func_001B070C(arg0, temp_a1_2, 0x01000000) != 1) {
                C64Item item = *((C64Item **)&temp_s2_2->m_item12)[*indexPtr];
                c64_func_001C9198(&D_007812C0, item);
            }
            c64_func_001C8214((int)&D_007812C0, *indexPtr);
        }
        c64_func_001AF5E0(arg0);
block_35:
        arg0->m_subState = 0xCU;
        break;
    case 12:
        temp_s0_3 = &arg0->m_rpk0;
        c64_func_0018F41C(temp_s0_3, 0x26, 6);
        c64_func_0018F41C(temp_s0_3, 0x27, 6);
        c64_func_0018F41C(temp_s0_3, 0x28, 6);
        c64_func_0018F41C(temp_s0_3, 0x29, 6);
        c64_func_0018F41C(temp_s0_3, 0x2A, 6);
        c64_func_0018F41C(temp_s0_3, 0x2B, 6);
        {
            int st = arg0->m_state;
            temp_s2_3 = arg0->m_choice0;
            arg0->m_state = arg0->m_prevState[st];
        }
        if (temp_s2_3 == 1) {
            arg0->m_subState = 6U;
            c64_func_0018C4D8(temp_s0_3, 0x20, 3);
            temp_s0_3->m_sprTbl[0x20].m_vis0C = temp_s2_3;
        }
        break;
    }
    if (var_s3 != 0) {
        temp_s0_4 = &arg0->m_rpk0;
        if (var_s3 & 1) {
            c64_func_0018F0EC(temp_s0_4, 0x2A, 1, -1);
            c64_func_0018F0EC(temp_s0_4, 0x2B, 0, -1);
            temp_s0_4->m_sprTbl[0x2A].m_rgba[0] = 0x80;
            temp_s0_4->m_sprTbl[0x2A].m_rgba[1] = 0x80;
            temp_s0_4->m_sprTbl[0x2A].m_rgba[2] = 0x80;
            temp_s0_4->m_sprTbl[0x2A].m_rgba[3] = 0x80;
            temp_s0_4->m_sprTbl[0x2B].m_rgba[0] = 0x80;
            temp_s0_4->m_sprTbl[0x2B].m_rgba[1] = 0x80;
            temp_s0_4->m_sprTbl[0x2B].m_rgba[2] = 0x80;
            temp_s0_4->m_sprTbl[0x2B].m_rgba[3] = 0x28;
        }
        if (var_s3 & 2) {
            temp_s0_5 = &arg0->m_rpk0;
            c64_func_0018F0EC(temp_s0_5, 0x2A, 0, -1);
            c64_func_0018F0EC(temp_s0_5, 0x2B, 1, -1);
            temp_s0_5->m_sprTbl[0x2A].m_rgba[0] = 0x80;
            temp_s0_5->m_sprTbl[0x2A].m_rgba[1] = 0x80;
            temp_s0_5->m_sprTbl[0x2A].m_rgba[2] = 0x80;
            temp_s0_5->m_sprTbl[0x2A].m_rgba[3] = 0x28;
            temp_s0_5->m_sprTbl[0x2B].m_rgba[0] = 0x80;
            temp_s0_5->m_sprTbl[0x2B].m_rgba[1] = 0x80;
            temp_s0_5->m_sprTbl[0x2B].m_rgba[2] = 0x80;
            temp_s0_5->m_sprTbl[0x2B].m_rgba[3] = 0x80;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001B64C4);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001B69D0);

// NON_MATCHING: 308/317 differ, 55 relocs differ (size 0x4F4, game 0x544), 167 edits
#ifdef NON_MATCHING
extern char boardName[] asm("D_002B8878");
extern char boardPack[] asm("D_002B8598");
extern char boardTable[] asm("D_002B8810");
extern char boardItems[] asm("D_002B8740");
extern int *D_007B2060;
extern "C" int ba3_func_001CF7D0(...) asm("func_001CF7D0");
extern "C" int ba3_func_001AEE8C(...) asm("func_001AEE8C");
extern "C" int ba3_func_0018BCC0(...) asm("func_0018BCC0");
extern "C" int ba3_func_001DC48C(...) asm("func_001DC48C");
extern "C" int ba3_func_001B1B34(...) asm("func_001B1B34");
extern "C" int ba3_strcpy(...) asm("strcpy");
extern "C" int ba3_func_001AD7D4(...) asm("func_001AD7D4");
extern "C" int ba3_strlen(...) asm("strlen");
extern "C" int ba3_func_0018F808(...) asm("func_0018F808");
extern "C" int ba3_func_001CF95C(...) asm("func_001CF95C");
extern "C" int ba3_func_001311BC(...) asm("func_001311BC");
extern "C" int ba3_func_0013511C(...) asm("func_0013511C");
extern "C" int ba3_func_001C5240(...) asm("func_001C5240");
extern "C" int ba3_func_0018FEBC(...) asm("func_0018FEBC");
extern "C" int ba3_func_00131184(...) asm("func_00131184");
extern "C" int ba3_func_001C5094(...) asm("func_001C5094");
extern "C" int ba3_func_001C5168(...) asm("func_001C5168");
extern "C" int ba3_func_001C51E0(...) asm("func_001C51E0");
extern "C" int ba3_func_0018C190(...) asm("func_0018C190");
extern "C" int ba3_func_001CF854(...) asm("func_001CF854");
extern "C" int ba3_func_0018C068(...) asm("func_0018C068");
extern "C" int ba3_func_00135088(...) asm("func_00135088");
extern "C" int ba3_func_0018C130(...) asm("func_0018C130");
extern "C" int func_001BA3A0(MnuItemView *arg0, const BedPad *arg1) {
    int sp0;
    int sp4;
    int params[8];
    int temp_s0_2;
    int temp_v1_3;
    unsigned short temp_a1;
    unsigned int temp_v1;
    int temp_s1;
    unsigned char *temp_s5;
    int temp_s0;
    int temp_s0_3;
    MnuRpk *temp_s2;
    MnuRpk *temp_s2_2;
    MnuRpk *temp_v1_2;
    MnuRpk *temp_v1_4;

    params[0] = 0x20;
    params[1] = 0x140;
    params[2] = 0x8001;
    params[3] = 0x1C0;
    params[4] = 0x50;
    sp0 = 0;
    params[5] = 0;
    params[6] = 0;
    params[7] = 0;
    ba3_func_001CF7D0((int)&D_007812C0, (int)&params[0]);
    temp_v1 = arg0->m_subState;
    switch (temp_v1) {
    case 0:
        temp_s5 = &arg0->m_rpk2.m_loader[0];
        ba3_func_001AEE8C(arg0);
        ba3_func_0018BCC0(&arg0->m_rpk2, 3);
        temp_v1_2 = &arg0->m_rpk0;
        arg0->m_rpk2.m_param = arg0->m_unk23E0;
        temp_v1_2->m_sprTbl[0x6F].m_vis10 = 4;
        temp_v1_2->m_sprTbl[0x70].m_vis10 = 4;
        temp_v1_2->m_sprTbl[0x71].m_vis10 = 4;
        ba3_func_001DC48C((int)&D_007812C0 + 0x22220, ba3_func_001B1B34(arg0, arg0->m_curSlot) & 0xFFFF, 0x42, (int)&sp0);
        if (sp0 == 0) {
            sp0 = 0x40000;
        }
        ba3_strcpy((int)boardName, ba3_func_001AD7D4(sp0));
        ba3_strcpy(ba3_strlen((int)boardName) + (int)boardName, ".tm2");
        ba3_func_0018F808(temp_s5, (int)boardPack, "data/mnurpk/mnuboard.rpk", 1);
        arg0->m_subState = 1U;
        temp_s0 = (int)&D_006E9840 + 0x12540;
        ba3_func_001CF95C((int)&D_007812C0);
        ba3_func_001311BC((int) temp_s0, 0xA, 7, 0);
        ba3_func_0013511C((int) temp_s0, arg0->m_texHandle, 0xA, 0, 0x80);
        ba3_func_001C5240((int)&D_007812C0, 8, 10);
        ba3_func_001C5240((int)&D_007812C0, 4, 10);
        break;
    case 1:
        temp_s2 = &arg0->m_rpk2;
        if (ba3_func_0018FEBC(&arg0->m_rpk2.m_loader[0]) != 0) {
            ba3_func_00131184((int) ((int)&D_006E9840 + 0x12540), 0xA, 7, 0);
            ba3_func_001C5094((int) (int)&D_007812C0, 2, 1, 3);
            ba3_func_001C5168((int) (int)&D_007812C0, 2, 0x100, 0x180);
            ba3_func_001C51E0((int) (int)&D_007812C0, 2, 0xA);
            arg0->m_subState = 2U;
            temp_s2->m_tbl = (void *)boardTable;
            ba3_func_0018C190(temp_s2, (int)boardItems);
            temp_s2->m_unk04 = 1;
            temp_s2->m_sprTbl[0].m_vis10 = 2;
        }
        break;
    case 2:
        arg0->m_subState = 3U;
        temp_s1 = (int)&D_007812C0 + 0x22220;
        ba3_func_00131184(arg0->m_unk1B5C + 0x12540, *(int *)(D_007B205C + 0x164), 7, 0);
        temp_s0_2 = ba3_func_001B1B34(arg0, arg0->m_curSlot) & 0xFFFF;
        ba3_func_001DC48C(temp_s1, temp_s0_2, 0x42, (int)&sp0);
        ba3_func_001DC48C(temp_s1, temp_s0_2, 0x25, (int)&sp4);
        ba3_func_001CF854((int)&D_007812C0, sp4, 0, 0xB4);
        break;
    case 3:
        temp_a1 = arg1->m_trigger;
        if (((temp_a1 >> 0xD) & 1 & 0xFFFF) || ((temp_a1 >> 0xE) & 1 & 0xFFFF)) {
            arg0->m_subState = 0xCU;
            arg0->m_rpk2.m_sprTbl[0].m_vis10 = 4;
            ba3_func_001311BC((int) ((int)&D_006E9840 + 0x12540), 0xA, 7, 0);
            ba3_func_001C5240((int)&D_007812C0, 2, 10);
            ba3_func_001CF95C((int)&D_007812C0);
            arg0->m_fadeTimer = 0xA;
        }
        ba3_func_0018C068(&arg0->m_rpk2);
        break;
    case 12:
        temp_s2_2 = &arg0->m_rpk2;
        temp_v1_3 = arg0->m_fadeTimer;
        arg0->m_fadeTimer = temp_v1_3 - 1;
        if (temp_v1_3 <= 0) {
            temp_s0_3 = (int)&D_006E9840 + 0x12540;
            ba3_func_001C5094((int) (int)&D_007812C0, 2, 0, 0);
            ba3_func_00131184((int) temp_s0_3, 0xA, 7, 0);
            ba3_func_00135088((int) temp_s0_3, arg0->m_texHandle, 0xA, 0, 0x80);
            if (!(D_007B2060[1] & 0x10000000) || (arg0->m_unk246C == 1)) {
                ba3_func_001C5094((int) (int)&D_007812C0, 8, 1, 0);
                ba3_func_001C5094((int) (int)&D_007812C0, 4, 1, 0);
            }
            ba3_func_001C51E0((int) (int)&D_007812C0, 8, 0xA);
            ba3_func_001C51E0((int) (int)&D_007812C0, 4, 0xA);
            ba3_func_0018C130(temp_s2_2);
            temp_v1_4 = &arg0->m_rpk0;
            temp_v1_4->m_sprTbl[0x6F].m_vis10 = 1;
            temp_v1_4->m_sprTbl[0x70].m_vis10 = 1;
            temp_v1_4->m_sprTbl[0x71].m_vis10 = 1;
            arg0->m_subState = 1U;
            arg0->m_state = arg0->m_prevState[arg0->m_state];
        } else {
            ba3_func_0018C068(temp_s2_2);
        }
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BA3A0);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BA8E4);

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BAFF4);

// NON_MATCHING: 220/226 differ, 29 relocs differ (size 0x388, game 0x3C4), 86 edits
#ifdef NON_MATCHING
extern "C" void b12_func_0017F8FC(int,int) asm("func_0017F8FC");
extern "C" void b12_func_0018F1F4(MnuRpk *,int,int,int,int,int,int,int) asm("func_0018F1F4");
extern "C" void b12_func_0018F41C(MnuRpk *,int,int) asm("func_0018F41C");
extern "C" void b12_func_0018F4A0(MnuRpk *,int,int,int,int) asm("func_0018F4A0");
extern "C" void b12_func_001A06D4(MnuSub104 *) asm("func_001A06D4");
extern "C" void b12_func_001A06E8(MnuSub104 *) asm("func_001A06E8");
extern "C" void b12_func_001A074C(MnuSub104 *) asm("func_001A074C");
extern "C" void b12_func_001A09B8(MnuSub104 *,unsigned char *,int,int) asm("func_001A09B8");
extern "C" int b12_func_001A0BA0(MnuSub104 *) asm("func_001A0BA0");
extern "C" void b12_func_001A0BB8(MnuSub104 *) asm("func_001A0BB8");
extern "C" void b12_func_001BAFF4(MnuItemView *) asm("func_001BAFF4");
extern "C" int b12_func_001D83D0(int,int,int,int) asm("func_001D83D0");
extern int D_00299950;
extern int D_00299970;
extern int D_002B6D70;
extern int D_002B6D90;
extern ScrMan D_007A4440;
extern "C" int func_001BB12C(MnuItemView *arg0, int arg1)
{
    int var_a1_3;
    int temp_s3;
    int temp_v0;
    int temp_v0_2;
    unsigned int temp_v1;
    int var_a1;
    int var_a2;
    int var_a3;
    int var_s4;
    int var_v0;
    int var_v1;
    MnuRpk *temp_s0;
    MnuSub104 *temp_s0_2;
    MnuSub104 *temp_s0_3;
    MnuRpk *temp_s1;
    MnuSub104 *temp_s2;
    MnuSprElem *var_v0_2;

    var_a1 = arg1;
    temp_s3 = var_a1;
    temp_v1 = arg0->m_subState;
    var_s4 = 0;
    switch (temp_v1) {
    case 0:
            arg0->m_subState = 1;
            arg0->m_selRes = -1;
            temp_s2 = &arg0->m_select;
            b12_func_001A06E8(temp_s2);
            b12_func_001BAFF4(arg0);
            var_a3 = 0;
            var_a2 = 0;
            if (arg0->m_selItems[0] != -1) {
                int *p = &arg0->m_selItems[0];
                do {
                    p++;
                    var_a3 |= 1 << var_a2;
                    var_a2 += 1;
                } while (*p != -1);
            }
            temp_s2->m_unk58 = 0x64;
            temp_s2->m_unk54 = 0x82;
            temp_s2->m_unk5C = 0x7FF8;
            temp_s0 = &arg0->m_rpk0;
            b12_func_001A09B8(temp_s2, arg0->m_selLines, var_a3 | 0x40000, var_a3);
            temp_s0->m_sprTbl[0x73].m_pos[0] = 0;
            temp_s0->m_sprTbl[0x73].m_pos[1] = 0;
            temp_s0->m_sprTbl[0x73].m_pos[2] = 0;
            temp_s0->m_sprTbl[0x73].m_pos[3] = 0;
            b12_func_0018F1F4(temp_s0, 0x73, 1, 0xA, 0, -1, (int)&D_00299950, (int)&D_00299970);
            b12_func_0018F1F4(temp_s0, 0x74, 1, 0xA, 0, -1, (int)&D_002B6D70, (int)&D_002B6D90);
            b12_func_0018F1F4(temp_s0, 0x75, 1, 0xA, 1, -1, (int)&D_002B6D70, (int)&D_002B6D90);
            b12_func_0018F1F4(temp_s0, 0x76, 1, 0xA, 2, -1, (int)&D_002B6D70, (int)&D_002B6D90);
            b12_func_0018F1F4(temp_s0, 0x77, 1, 0xA, 3, -1, (int)&D_002B6D70, (int)&D_002B6D90);
            var_v1 = 2;
            temp_s0->m_sprTbl[0x10].m_vis10 = 2;
            temp_s0->m_sprTbl[0x0F].m_vis10 = 2;
            var_v0_2 = temp_s0->m_sprTbl;
            goto block_21;
        case 6:
            temp_s0_2 = &arg0->m_select;
            b12_func_001A06D4(temp_s0_2);
            temp_v0 = b12_func_001A0BA0(temp_s0_2);
            arg0->m_selRes = temp_v0;
            if (temp_v0 >= 0) {
                var_a1_3 = 4;
                goto block_16;
            }
            var_v0 = 0;
            if (temp_v0 == -3) {
                var_a1_3 = 2;
block_16:
                b12_func_0017F8FC((int)&D_007B2580, var_a1_3);
                arg0->m_subState = 0xC;
                goto block_22;
            }
            
            return var_s4;
        case 12:
            temp_v0_2 = arg0->m_selRes;
            if (temp_v0_2 >= 0) {
                var_s4 = 1;
                var_a1 = 3;
                ((int *)D_007A4440.m_varBufA)[0x11] = b12_func_001D83D0((int)&D_007812C0, 0x63, arg0->m_selItems[temp_v0_2], 2);
                ((int *)D_007A4440.m_varBufA)[0x15] = 3;
                ((int *)D_007A4440.m_varBufA)[0x16] = 1;
            } else {
                arg0->m_subState = 1;
                arg0->m_state = arg0->m_prevState[arg0->m_state];
            }
            temp_s0_3 = &arg0->m_select;
            temp_s1 = &arg0->m_rpk0;
            b12_func_001A0BB8(temp_s0_3);
            b12_func_001A06D4(temp_s0_3);
            b12_func_001A074C(temp_s0_3);
            b12_func_0018F4A0(temp_s1, 0x73, 6, (int)&D_00299950, (int)&D_00299970);
            b12_func_0018F41C(temp_s1, 0x74, 6);
            b12_func_0018F41C(temp_s1, 0x75, 6);
            b12_func_0018F41C(temp_s1, 0x76, 6);
            b12_func_0018F41C(temp_s1, 0x77, 6);
            var_v1 = 1;
            temp_s1->m_sprTbl[0x10].m_vis10 = 1;
            temp_s1->m_sprTbl[0x0F].m_vis10 = 1;
            var_v0_2 = temp_s1->m_sprTbl;
block_21:
            var_v0_2[0x52].m_vis10 = var_v1;
            goto block_22;
    case 1:
        arg0->m_subState = 6;
        break;
    default:
        break;
    }
block_22:
    return var_s4;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BB12C);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BB4F0);

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BBCFC);

// NON_MATCHING: 232/238 differ, 25 relocs differ (size 0x3B8, game 0x3F0), 102 edits
#ifdef NON_MATCHING
extern "C" void c370_func_0017F8FC(int,int) asm("func_0017F8FC");
extern "C" void c370_func_0018F0EC(MnuRpk *,int,int,int) asm("func_0018F0EC");
extern "C" void c370_func_0018F41C(MnuRpk *,int,int) asm("func_0018F41C");
extern "C" int c370_func_001B1B34(MnuItemView *,int) asm("func_001B1B34");
extern "C" int func_001BC370(MnuItemView *arg0, const BedPad *arg1)
{
    int temp_v1_2;
    int var_s3;
    int var_s4;
    unsigned short temp_a1;
    unsigned int temp_v1;
    unsigned int var_v0;
    MnuRpk *temp_s0;
    MnuRpk *temp_s0_2;
    MnuRpk *temp_s0_3;
    MnuRpk *temp_s0_4;

    var_s3 = 0;
    temp_v1 = arg0->m_subState;
    var_s4 = 0;
    switch (temp_v1) {
    case 0:
        arg0->m_choice1 = 0;
        
    case 1:
        temp_s0 = &arg0->m_rpk0;
        arg0->m_subState = 6U;
        var_s3 = 1;
        c370_func_0018F0EC(temp_s0, 0x26, 1, -1);
        c370_func_0018F0EC(temp_s0, 0x27, 1, -1);
        c370_func_0018F0EC(temp_s0, 0x28, 1, -1);
        c370_func_0018F0EC(temp_s0, 0x29, 1, -1);
        arg0->m_choice1 = 0;
        break;
    case 6:
        if ((arg1->m_dpadRepeat & 0x10) && (arg0->m_choice1 == 1)) {
            var_s3 = 1;
            c370_func_0017F8FC((int)&D_007B2580, 1);
            arg0->m_choice1 = 0;
        }
        if ((arg1->m_dpadRepeat & 0x40) && (arg0->m_choice1 == 0)) {
            var_s3 |= 2;
            c370_func_0017F8FC((int)&D_007B2580, 1);
            arg0->m_choice1 = 1;
        }
        temp_a1 = arg1->m_trigger;
        var_v0 = temp_a1 >> 0xD;
        if ((temp_a1 >> 0xE) & 1 & 0xFFFF) {
            temp_v1_2 = arg0->m_choice1;
            if (temp_v1_2 != 0) {
                var_v0 = temp_a1 >> 0xD;
                if (temp_v1_2 != 1) {

                } else {
                    var_s3 |= 8;
                    goto block_16;
                }
            } else {
                var_s3 |= 4;
block_16:
                var_v0 = temp_a1 >> 0xD;
            }
        }
        if (var_v0 & 1 & 0xFFFF) {
            var_s3 |= 8;
            arg0->m_choice1 = 1;
        }
        if (var_s3 & 4) {
            c370_func_0017F8FC((int)&D_007B2580, 4);
            arg0->m_subState = 7U;
        }
        if (var_s3 & 8) {
            c370_func_0017F8FC((int)&D_007B2580, 3);
        case 10:
            arg0->m_subState = 0xCU;
        }
        break;
    case 7:
        arg0->m_subState = 8U;
        break;
    case 8:
        arg0->m_subState = 9U;
        break;
    case 9:
        arg0->m_subState = 0xAU;
        break;
    case 12:
        temp_s0_2 = &arg0->m_rpk0;
        c370_func_0018F41C(temp_s0_2, 0x26, 6);
        c370_func_0018F41C(temp_s0_2, 0x27, 6);
        c370_func_0018F41C(temp_s0_2, 0x28, 6);
        c370_func_0018F41C(temp_s0_2, 0x29, 6);
        c370_func_0018F41C(temp_s0_2, 0x2A, 6);
        c370_func_0018F41C(temp_s0_2, 0x2B, 6);
        if (arg0->m_choice1 != 1) {
            var_s4 = 1;
            ((int *)D_007A4440.m_varBufA)[0x11] = c370_func_001B1B34(arg0, arg0->m_curSlot);
            ((int *)D_007A4440.m_varBufA)[0x15] = 3;
            ((int *)D_007A4440.m_varBufA)[0x16] = 1;
        } else {
            arg0->m_subState = 1U;
            arg0->m_state = arg0->m_prevState[arg0->m_state];
        }
        break;
    }
    if (var_s3 != 0) {
        temp_s0_3 = &arg0->m_rpk0;
        if (var_s3 & 1) {
            c370_func_0018F0EC(temp_s0_3, 0x2A, 1, -1);
            c370_func_0018F0EC(temp_s0_3, 0x2B, 0, -1);
            temp_s0_3->m_sprTbl[0x2A].m_rgba[0] = 0x80;
            temp_s0_3->m_sprTbl[0x2A].m_rgba[1] = 0x80;
            temp_s0_3->m_sprTbl[0x2A].m_rgba[2] = 0x80;
            temp_s0_3->m_sprTbl[0x2A].m_rgba[3] = 0x80;
            temp_s0_3->m_sprTbl[0x2B].m_rgba[0] = 0x80;
            temp_s0_3->m_sprTbl[0x2B].m_rgba[1] = 0x80;
            temp_s0_3->m_sprTbl[0x2B].m_rgba[2] = 0x80;
            temp_s0_3->m_sprTbl[0x2B].m_rgba[3] = 0x28;
        }
        temp_s0_4 = &arg0->m_rpk0;
        if (var_s3 & 2) {
            c370_func_0018F0EC(temp_s0_4, 0x2A, 0, -1);
            c370_func_0018F0EC(temp_s0_4, 0x2B, 1, -1);
            temp_s0_4->m_sprTbl[0x2A].m_rgba[0] = 0x80;
            temp_s0_4->m_sprTbl[0x2A].m_rgba[1] = 0x80;
            temp_s0_4->m_sprTbl[0x2A].m_rgba[2] = 0x80;
            temp_s0_4->m_sprTbl[0x2A].m_rgba[3] = 0x28;
            temp_s0_4->m_sprTbl[0x2B].m_rgba[0] = 0x80;
            temp_s0_4->m_sprTbl[0x2B].m_rgba[1] = 0x80;
            temp_s0_4->m_sprTbl[0x2B].m_rgba[2] = 0x80;
            temp_s0_4->m_sprTbl[0x2B].m_rgba[3] = 0x80;
        }
    }
    return var_s4;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BC370);
#endif

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

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BC790);

static inline int BC8F8_game(char *p) { return (int)(p + 0x22220); }
extern "C" int X_func_0018C4D8(...) asm("func_0018C4D8");
extern "C" int X_func_0018EBA4(...) asm("func_0018EBA4");
extern "C" int X_func_0018EC58(...) asm("func_0018EC58");
extern "C" int X_func_001B1B34(MnuItemView *,int) ASM_NOTHROW asm("func_001B1B34");
extern "C" int X_func_001DC48C(...) asm("func_001DC48C");
extern int D_002B8848;
extern int D_002B8850;
extern int D_002B8920;
extern "C" void func_001BC8F8(MnuItemView *arg0, int arg1, int arg2)
{
    struct { char *sp0; } stack;
    char *temp_s2;
    char *temp_s3;
    int temp_s0;
    int temp_s1_2;
    int var_a2;
    int temp_s1;
    MnuRpk *temp_s4;

    temp_s4 = &arg0->m_rpk0;
    var_a2 = 0xA00;
    temp_s4->m_sprTbl[0x5C].m_color = &D_002B8850;
    temp_s4->m_sprTbl[0x5D].m_color = &D_002B8850;
    temp_s4->m_sprTbl[0x5E].m_color = &D_002B8850;
    temp_s4->m_sprTbl[0x5F].m_color = &D_002B8850;
    if (arg1 >= 0) {
        if (arg1 < 12) var_a2=X_func_001B1B34(arg0,arg1);
        else if (arg1==12) var_a2=arg0->m_item12;
        else if (arg1==13) var_a2=arg0->m_item13;
        if (var_a2 != 0xA00) {
            temp_s0 = var_a2 & 0xFFFF;
            temp_s1 = BC8F8_game((char *)&D_007812C0);
            X_func_001DC48C(temp_s1, temp_s0, 0xB, (int)&stack);
            if (stack.sp0 == 0) {
                stack.sp0 = (*(char **)&D_002B8848);
            }
            X_func_0018EC58(temp_s4, stack.sp0);
            X_func_001DC48C(temp_s1, temp_s0, 0xC, (int)&stack);
            if (stack.sp0 == 0) {
                stack.sp0 = (*(char **)&D_002B8848);
            }
            X_func_0018EC58(temp_s4, stack.sp0);
            char *value = stack.sp0;
            temp_s4->m_sprTbl[0x5C].m_unk144 = 0;
            temp_s4->m_sprTbl[0x5C].m_unk148 = 0;
            temp_s4->m_sprTbl[0x5C].m_text = value;
            X_func_0018C4D8(temp_s4, 0x5C, 0);
            temp_s4->m_sprTbl[0x5C].m_vis0C = 1;
            X_func_001DC48C(temp_s1, temp_s0, 0x25, (int)&stack);
            if (stack.sp0 == 0) {
                stack.sp0 = (*(char **)&D_002B8848);
            }
            temp_s1_2 = arg2 * 3;
            X_func_0018EBA4(temp_s4, stack.sp0, (int)&D_002B8920, temp_s1_2);
            temp_s4->m_sprTbl[0x5D].m_unk144 = 0;
            temp_s2 = (char *)&D_002B8920 + 0x40;
            temp_s3 = (char *)&D_002B8920 + 0x80;
            temp_s4->m_sprTbl[0x5D].m_unk148 = 0;
            temp_s4->m_sprTbl[0x5D].m_text = (char *)&D_002B8920;
            X_func_0018C4D8(temp_s4, 0x5D, 0);
            temp_s4->m_sprTbl[0x5D].m_vis0C = 1;
            X_func_0018EBA4(temp_s4, stack.sp0, temp_s2, temp_s1_2 + 1);
            temp_s4->m_sprTbl[0x5E].m_unk144 = 0;
            temp_s4->m_sprTbl[0x5E].m_unk148 = 0;
            temp_s4->m_sprTbl[0x5E].m_text = temp_s2;
            X_func_0018C4D8(temp_s4, 0x5E, 0);
            temp_s4->m_sprTbl[0x5E].m_vis0C = 1;
            X_func_0018EBA4(temp_s4, stack.sp0, temp_s3, temp_s1_2 + 2);
            temp_s4->m_sprTbl[0x5F].m_unk144 = 0;
            temp_s4->m_sprTbl[0x5F].m_unk148 = 0;
            temp_s4->m_sprTbl[0x5F].m_text = temp_s3;
            X_func_0018C4D8(temp_s4, 0x5F, 0);
            temp_s4->m_sprTbl[0x5F].m_vis0C = 1;
        }
    }
}

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

// NON_MATCHING: 208/253 differ, 16 relocs differ (size 0x3F4, game 0x420), 52 edits
#ifdef NON_MATCHING
extern "C" int cc08_func_0018C4D8(MnuRpk *,int,int) asm("func_0018C4D8");
extern "C" int cc08_func_0018EC58(MnuRpk *,char *) asm("func_0018EC58");
extern "C" int cc08_func_001B1B34(MnuItemView *,int) asm("func_001B1B34");
extern "C" char *cc08_func_001BCB84(MnuItemView *,int) asm("func_001BCB84");
extern "C" int cc08_func_001DC48C(int,int,int,int) asm("func_001DC48C");
extern int D_002B8860;
extern char *cc08Fallback asm("D_002B8848");
extern "C" void func_001BCC08(MnuItemView *arg0, int arg1, int arg2)
{
    struct { short sp0; } stack;
    char *var_s1;
    char *var_s1_2;
    char *var_s1_3;
    int var_s6;
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    int temp_s4;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int var_a0;
    MnuRpk *temp_s0;
    MnuRpk *temp_s0_2;
    MnuRpk *temp_s0_3;

    var_a0 = 0xA00;
    if ((arg2 == 0) || (var_s6 = 1, (arg2 != 1))) {
        var_s6 = 0;
    }
    temp_s0 = &arg0->m_rpk0;
    temp_s0->m_sprTbl[0x6F].m_color = &D_002B8860;
    temp_s0->m_sprTbl[0x70].m_color = &D_002B8860;
    temp_s0->m_sprTbl[0x71].m_color = &D_002B8860;
    if ((arg0->m_unk2418 != 0) && (arg1 >= 0)) {
        if (arg1 < 12) var_a0=cc08_func_001B1B34(arg0,arg1);
        else if (arg1==12) var_a0=arg0->m_item12;
        else if (arg1==13) var_a0=arg0->m_item13;
        if (var_a0 != 0xA00) {
            temp_s4 = var_a0 & 0xFFFF;
            cc08_func_001DC48C((int)&D_007812C0 + 0x22220, temp_s4, 0x10, (int)&stack);
            if (stack.sp0 != 0xA00) {
                var_s1 = cc08_func_001BCB84(arg0, stack.sp0);
                if (var_s1 == 0) {
                    var_s1 = cc08Fallback;
                }
                temp_a0 = cc08_func_0018EC58(temp_s0, var_s1);
                temp_v1 = temp_a0 < 0x79;
                temp_s0->m_sprTbl[0x6F].m_unkD0 = 0xA00;
                if (temp_v1 == 0) {
                    temp_s0->m_sprTbl[0x6F].m_unkD0 = (int)((120.0f / (float)temp_a0) * 160.0f) * 16;
                }
                temp_s0->m_sprTbl[0x6F].m_unk144 = 0;
                temp_s0->m_sprTbl[0x6F].m_unk148 = 0;
                temp_s0->m_sprTbl[0x6F].m_text = var_s1;
                cc08_func_0018C4D8(temp_s0, 0x6F, var_s6);
                temp_s0->m_sprTbl[0x6F].m_vis0C = 1;
            }
            cc08_func_001DC48C((int)&D_007812C0 + 0x22220, temp_s4, 0x11, (int)&stack);
            if (stack.sp0 != 0xA00) {
                var_s1_2 = cc08_func_001BCB84(arg0, stack.sp0);
                temp_s0_2 = &arg0->m_rpk0;
                if (var_s1_2 == 0) {
                    var_s1_2 = cc08Fallback;
                }
                temp_a0_2 = cc08_func_0018EC58(temp_s0_2, var_s1_2);
                temp_v1_2 = temp_a0_2 < 0x79;
                temp_s0_2->m_sprTbl[0x70].m_unkD0 = 0xA00;
                if (temp_v1_2 == 0) {
                    temp_s0_2->m_sprTbl[0x70].m_unkD0 = (int)((120.0f / (float)temp_a0_2) * 160.0f) * 16;
                }
                temp_s0_2->m_sprTbl[0x70].m_unk144 = 0;
                temp_s0_2->m_sprTbl[0x70].m_unk148 = 0;
                temp_s0_2->m_sprTbl[0x70].m_text = var_s1_2;
                cc08_func_0018C4D8(temp_s0_2, 0x70, var_s6);
                temp_s0_2->m_sprTbl[0x70].m_vis0C = 1;
            }
            cc08_func_001DC48C((int)&D_007812C0 + 0x22220, temp_s4, 0x12, (int)&stack);
            if (stack.sp0 != 0xA00) {
                var_s1_3 = cc08_func_001BCB84(arg0, stack.sp0);
                temp_s0_3 = &arg0->m_rpk0;
                if (var_s1_3 == 0) {
                    var_s1_3 = cc08Fallback;
                }
                temp_a0_3 = cc08_func_0018EC58(temp_s0_3, var_s1_3);
                temp_v1_3 = temp_a0_3 < 0x79;
                temp_s0_3->m_sprTbl[0x71].m_unkD0 = 0xA00;
                if (temp_v1_3 == 0) {
                    temp_s0_3->m_sprTbl[0x71].m_unkD0 = (int)((120.0f / (float)temp_a0_3) * 160.0f) * 16;
                }
                temp_s0_3->m_sprTbl[0x71].m_unk144 = 0;
                temp_s0_3->m_sprTbl[0x71].m_unk148 = 0;
                temp_s0_3->m_sprTbl[0x71].m_text = var_s1_3;
                cc08_func_0018C4D8(temp_s0_3, 0x71, var_s6);
                temp_s0_3->m_sprTbl[0x71].m_vis0C = 1;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BCC08);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BD028);

INCLUDE_RODATA("asm/nonmatchings/unk/001B64C4", D_002FB188);

INCLUDE_RODATA("asm/nonmatchings/unk/001B64C4", D_002FB190);

extern "C" int func_001BE414(int);

class FileReader {
public:
    int unk0;
    int unk4;
    ~FileReader();
};
