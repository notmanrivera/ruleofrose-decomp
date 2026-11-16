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

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001B64C4);

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001B69D0);

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BA3A0);

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BA8E4);

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BAFF4);

// NON_MATCHING: 220/226 differ, 29 relocs differ (size 0x388, game 0x3C4), 86 edits
#ifdef NON_MATCHING
extern "C" void b12_func_0017F8FC(int,int) asm("func_0017F8FC");
extern "C" void b12_func_0018F1F4(int,int,int,int,int,int,int,int) asm("func_0018F1F4");
extern "C" void b12_func_0018F41C(int,int,int) asm("func_0018F41C");
extern "C" void b12_func_0018F4A0(int,int,int,int,int) asm("func_0018F4A0");
extern "C" void b12_func_001A06D4(int) asm("func_001A06D4");
extern "C" void b12_func_001A06E8(int) asm("func_001A06E8");
extern "C" void b12_func_001A074C(int) asm("func_001A074C");
extern "C" void b12_func_001A09B8(int,int,int,int) asm("func_001A09B8");
extern "C" int b12_func_001A0BA0(int) asm("func_001A0BA0");
extern "C" void b12_func_001A0BB8(int) asm("func_001A0BB8");
extern "C" void b12_func_001BAFF4(int) asm("func_001BAFF4");
extern "C" int b12_func_001D83D0(int,int,int,int) asm("func_001D83D0");
extern int D_00299950;
extern int D_00299970;
extern int D_002B6D70;
extern int D_002B6D90;
extern int D_007A4440;
extern "C" int func_001BB12C(int arg0, int arg1)
{
    int var_a1_3;
    int temp_s3;
    int temp_v0;
    int temp_v0_2;
    int temp_v1;
    int var_a1;
    int var_a1_2;
    int var_a2;
    int var_a3;
    int var_s4;
    int var_v0;
    int var_v1;
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s1;
    int temp_s2;
    int var_v0_2;

    var_a1 = arg1;
    temp_s3 = var_a1;
    temp_v1 = M2C_FIELD(arg0, int *, 0x5C);
    var_s4 = 0;
    switch (temp_v1) {
    case 0:
            M2C_FIELD(arg0, int *, 0x5C) = 1;
            M2C_FIELD(arg0, int *, 0x20) = -1;
            temp_s2 = arg0 + 0x1B64;
            b12_func_001A06E8(temp_s2);
            b12_func_001BAFF4(arg0);
            var_a3 = 0;
            var_a2 = 0;
            if (M2C_FIELD(arg0, int *, 0x26A4) != -1) {
                var_a1_2 = 0x26A0;
                do {
                    var_a1_2 += 4;
                    var_a3 |= 1 << var_a2;
                    var_a2 += 1;
                } while (M2C_FIELD((arg0 + var_a1_2), int *, 4) != -1);
            }
            M2C_FIELD(temp_s2, int *, 0x58) = 0x64;
            M2C_FIELD(temp_s2, int *, 0x54) = 0x82;
            M2C_FIELD(temp_s2, int *, 0x5C) = 0x7FF8;
            temp_s0 = arg0 + 0x98;
            b12_func_001A09B8(temp_s2, arg0 + 0x24A4, var_a3 | 0x40000, var_a3);
            M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x98D4) = 0;
            M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x98D8) = 0;
            M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x98DC) = 0;
            M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x98E0) = 0;
            b12_func_0018F1F4(temp_s0, 0x73, 1, 0xA, 0, -1, (int)&D_00299950, (int)&D_00299970);
            b12_func_0018F1F4(temp_s0, 0x74, 1, 0xA, 0, -1, (int)&D_002B6D70, (int)&D_002B6D90);
            b12_func_0018F1F4(temp_s0, 0x75, 1, 0xA, 1, -1, (int)&D_002B6D70, (int)&D_002B6D90);
            b12_func_0018F1F4(temp_s0, 0x76, 1, 0xA, 2, -1, (int)&D_002B6D70, (int)&D_002B6D90);
            b12_func_0018F1F4(temp_s0, 0x77, 1, 0xA, 3, -1, (int)&D_002B6D70, (int)&D_002B6D90);
            var_v1 = 2;
            M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x154C) = 2;
            M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x13F8) = 2;
            var_v0_2 = M2C_FIELD(temp_s0, int *, 0x4AC);
            goto block_21;
        case 6:
            temp_s0_2 = arg0 + 0x1B64;
            b12_func_001A06D4(temp_s0_2);
            temp_v0 = b12_func_001A0BA0(temp_s0_2);
            M2C_FIELD(arg0, int *, 0x20) = temp_v0;
            if (temp_v0 >= 0) {
                var_a1_3 = 4;
                goto block_16;
            }
            var_v0 = 0;
            if (temp_v0 == -3) {
                var_a1_3 = 2;
block_16:
                b12_func_0017F8FC((int)&D_007B2580, var_a1_3);
                M2C_FIELD(arg0, int *, 0x5C) = 0xC;
                goto block_22;
            }
            
            return var_s4;
        case 12:
            temp_v0_2 = M2C_FIELD(arg0, int *, 0x20);
            if (temp_v0_2 >= 0) {
                var_s4 = 1;
                var_a1 = 3;
                M2C_FIELD(M2C_FIELD((int)&D_007A4440, int *, 0xDC1C), unsigned int *, 0x44) = b12_func_001D83D0((int)&D_007812C0, 0x63, M2C_FIELD(((temp_v0_2 * 4) + (arg0 + 4)), int *, 0x26A0), 2);
                M2C_FIELD(M2C_FIELD((int)&D_007A4440, int *, 0xDC1C), int *, 0x54) = 3;
                M2C_FIELD(M2C_FIELD((int)&D_007A4440, int *, 0xDC1C), int *, 0x58) = 1;
            } else {
                M2C_FIELD(arg0, int *, 0x5C) = 1;
                M2C_FIELD(arg0, int *, 0x58) = (int) M2C_FIELD(((M2C_FIELD(arg0, int *, 0x58) * 4) + arg0), int *, 0x60);
            }
            temp_s0_3 = arg0 + 0x1B64;
            temp_s1 = arg0 + 0x98;
            b12_func_001A0BB8(temp_s0_3);
            b12_func_001A06D4(temp_s0_3);
            b12_func_001A074C(temp_s0_3);
            b12_func_0018F4A0(temp_s1, 0x73, 6, (int)&D_00299950, (int)&D_00299970);
            b12_func_0018F41C(temp_s1, 0x74, 6);
            b12_func_0018F41C(temp_s1, 0x75, 6);
            b12_func_0018F41C(temp_s1, 0x76, 6);
            b12_func_0018F41C(temp_s1, 0x77, 6);
            var_v1 = 1;
            M2C_FIELD(M2C_FIELD(temp_s1, int *, 0x4AC), int *, 0x154C) = 1;
            M2C_FIELD(M2C_FIELD(temp_s1, int *, 0x4AC), int *, 0x13F8) = 1;
            var_v0_2 = M2C_FIELD(temp_s1, int *, 0x4AC);
block_21:
            M2C_FIELD(var_v0_2, int *, 0x6CF4) = var_v1;
            goto block_22;
    case 1:
        M2C_FIELD(arg0, int *, 0x5C) = 6;
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

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BC370);

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

// NON_MATCHING: 117/160 differ, 17 relocs differ (size 0x280, game 0x28C), 13 edits
#ifdef NON_MATCHING
extern "C" int X_func_0018C4D8(...) asm("func_0018C4D8");
extern "C" int X_func_0018EBA4(...) asm("func_0018EBA4");
extern "C" int X_func_0018EC58(...) asm("func_0018EC58");
extern "C" int X_func_001B1B34(int,int) asm("func_001B1B34");
extern "C" int X_func_001DC48C(...) asm("func_001DC48C");
extern int D_002B8848;
extern int D_002B8850;
extern int D_002B8920;
extern "C" void func_001BC8F8(int arg0, int arg1, int arg2)
{
    struct { int sp0; } stack;
    int temp_s2;
    int temp_s3;
    int temp_s0;
    int temp_s1_2;
    int var_a2;
    int temp_s1;
    int temp_s4;

    temp_s4 = arg0 + 0x98;
    var_a2 = 0xA00;
    M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7B80) = (int)&D_002B8850;
    M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7CD4) = (int)&D_002B8850;
    M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7E28) = (int)&D_002B8850;
    M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7F7C) = (int)&D_002B8850;
    if (arg1 >= 0) {
        if (arg1 < 12) var_a2=X_func_001B1B34(arg0,arg1);
        else if (arg1==12) var_a2=M2C_FIELD(arg0,int *,0x2430);
        else if (arg1==13) var_a2=M2C_FIELD(arg0,int *,0x242C);
        if (var_a2 != 0xA00) {
            temp_s0 = var_a2 & 0xFFFF;
            temp_s1 = (int)&D_007812C0 + 0x22220;
            X_func_001DC48C(temp_s1, temp_s0, 0xB, (int)&stack);
            if (stack.sp0 == 0) {
                stack.sp0 = (*(int *)&D_002B8848);
            }
            X_func_0018EC58(temp_s4, stack.sp0);
            X_func_001DC48C(temp_s1, temp_s0, 0xC, (int)&stack);
            if (stack.sp0 == 0) {
                stack.sp0 = (*(int *)&D_002B8848);
            }
            X_func_0018EC58(temp_s4, stack.sp0);
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7B74) = 0;
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7B78) = 0;
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7B7C) = stack.sp0;
            X_func_0018C4D8(temp_s4, 0x5C, 0);
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7A3C) = 1;
            X_func_001DC48C(temp_s1, temp_s0, 0x25, (int)&stack);
            if (stack.sp0 == 0) {
                stack.sp0 = (*(int *)&D_002B8848);
            }
            temp_s1_2 = arg2 * 3;
            X_func_0018EBA4(temp_s4, stack.sp0, (int)&D_002B8920, temp_s1_2);
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7CC8) = 0;
            temp_s2 = (int)&D_002B8920 + 0x40;
            temp_s3 = (int)&D_002B8920 + 0x80;
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7CCC) = 0;
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7CD0) = (int)&D_002B8920;
            X_func_0018C4D8(temp_s4, 0x5D, 0);
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7B90) = 1;
            X_func_0018EBA4(temp_s4, stack.sp0, temp_s2, temp_s1_2 + 1);
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7E1C) = 0;
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7E20) = 0;
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7E24) = temp_s2;
            X_func_0018C4D8(temp_s4, 0x5E, 0);
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7CE4) = 1;
            X_func_0018EBA4(temp_s4, stack.sp0, temp_s3, temp_s1_2 + 2);
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7F70) = 0;
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7F74) = 0;
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7F78) = temp_s3;
            X_func_0018C4D8(temp_s4, 0x5F, 0);
            M2C_FIELD(M2C_FIELD(temp_s4, int *, 0x4AC), int *, 0x7E38) = 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BC8F8);
#endif

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

INCLUDE_ASM("asm/nonmatchings/unk/001B64C4", func_001BCC08);

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
