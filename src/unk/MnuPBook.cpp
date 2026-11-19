#include "include_asm.h"
#include "bed/bedpfh.h"
extern "C" int Xiii_func_001874F4(int, int) asm("func_001874F4");
extern "C" int Xiiu_func_001348B0(int, unsigned int) asm("func_001348B0");
extern "C" int Xiiuii_func_00134AB8(int, unsigned int, int, int) asm("func_00134AB8");
extern "C" int Xii_func_0018741C(int) asm("func_0018741C");
extern "C" void Xiiiii_func_001874F4(int, int, int, int) asm("func_001874F4");
extern "C" int Xiiii_func_001C51E0(int, int, int) asm("func_001C51E0");
extern "C" int Xiiiii_func_0019844C(int, int, int, int) asm("func_0019844C");
extern "C" int Xiiiii_func_001C5168(int, int, int, int) asm("func_001C5168");
extern "C" int Xiiiiii_func_00134730(int, int, int, int, int) asm("func_00134730");
extern "C" int Xiiu_func_00135594(int, unsigned int) asm("func_00135594");
extern "C" int Xiiui_func_00135418(int, unsigned int, int) asm("func_00135418");
extern "C" int Xiiui_func_00135494(int, unsigned int, int) asm("func_00135494");
extern "C" int Xiiuiii_func_00134A00(int, unsigned int, int, int, int) asm("func_00134A00");
extern "C" int Xiiuiiii_func_00134CD0(int, unsigned int, int, int, int, int) asm("func_00134CD0");
extern "C" int Xiu_func_001832E8(unsigned int) asm("func_001832E8");
extern int D_002F80F0;
struct PBookPageLabel { char text[3]; };
extern "C" float Xfi_getLeftX__C6BedPad(int) asm("getLeftX__C6BedPad");
extern "C" int Xii_func_001874AC(int) asm("func_001874AC");
extern "C" int Xiii_func_0017F8FC(int, int) asm("func_0017F8FC");
extern "C" int Xiii_func_00198318(int, int) asm("func_00198318");
extern "C" int Xiiii_func_00197F18(int, int, int) asm("func_00197F18");
extern "C" int Xiiiii_func_001C5094(int, int, int, int) asm("func_001C5094");
extern "C" void Xiiu_func_001985B0(int, unsigned int) asm("func_001985B0");
extern "C" int Xiiui_func_001351B0(int, unsigned int, int) asm("func_001351B0");
extern int D_007B2580;
static inline int PBookButton(unsigned int buttons, int bit)
{
    return (buttons >> bit) & 1;
}
struct PBookMapCoords { float v[8]; };
struct PBookMapTable { PBookMapCoords row[13]; };
extern PBookMapTable D_002F7DC0;
extern int D_00298EE0;
extern "C" int Xii_func_001C6C38(int) asm("func_001C6C38");
extern "C" int Xii_func_001DBD90(int) asm("func_001DBD90");
extern "C" int Xii_func_001C6C28(int) asm("func_001C6C28");
extern "C" int Xiii_func_0017EA44(int, int) asm("func_0017EA44");
static inline int PBookMapObject(int game)
{
    return game + 0x18C00;
}
extern "C" int Xiiiii_func_00197E68(int, int, int, int) asm("func_00197E68");
extern "C" int Xiii_func_001943D8(int, int) asm("func_001943D8");
extern "C" void X_func_00193868_v1(int) asm("func_00193868");
extern "C" void X_func_001348B0_v1(int, int) asm("func_001348B0");
extern "C" void X_func_00187464_v1(int) asm("func_00187464");
extern "C" void X_func_00194688_v1(int) asm("func_00194688");
extern "C" void X_mnuBase__vfunc_03_v1(int) asm("mnuBase__vfunc_03");
struct __attribute__((aligned(4))) PBookMnuMapName {
    char m_pad[0x24];
    char m_name[0x17];
};
extern "C" int Xii_func_00192AC0_ctor(int) asm("func_00192AC0");
extern "C" int Xii_func_0018330C_ctor(int) asm("func_0018330C");
extern int vtbl_MnuMap_ctor asm("_vt$6MnuMap");
struct PBookHdr {
    int unk00;
    int unk04;
    unsigned short unk08;
};
struct PBookItem {
    int pad[7];
    int unk1C;
};
struct PBookElem10 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct PBookElem20 {
    char *unk00;
    int pad[7];
};
extern "C" PBookHdr **Xp_func_0022AED8(void *, int) asm("func_0022AED8");
extern "C" PBookItem **Xp_func_0022AAD0(PBookHdr **, int) asm("func_0022AAD0");
extern "C" int Xiii_func_001959EC(int, int) asm("func_001959EC");
extern "C" int Xiiii_func_00193FEC(int, int, int) asm("func_00193FEC");
struct m2c_v10C_50_i {
    char pad[268];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};
extern "C" void X_func_00192BA4(int, int, int, int, int, int) asm("func_00192BA4");
extern "C" void X_func_001949BC(int) asm("func_001949BC");
extern "C" float Xff_cosf(float) asm("cosf");
extern "C" int Xii_func_0019381C(int) asm("func_0019381C");
extern "C" int Xiiff_func_00192E94(int, float, float) asm("func_00192E94");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_00194688(int) asm("func_00194688");
extern "C" int Xiii_func_00193F74(int, int) asm("func_00193F74");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiiiii_func_0019397C(int, int, int, int) asm("func_0019397C");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_alloc__9BedMemoryii(...) asm("alloc__9BedMemoryii");
extern "C" int X_free__9BedMemoryPv(...) asm("free__9BedMemoryPv");
extern "C" int X_func_00134730(...) asm("func_00134730");
extern "C" int X_func_001348B0(...) asm("func_001348B0");
extern "C" int X_func_00134A00(...) asm("func_00134A00");
extern "C" int X_func_00134AB8(...) asm("func_00134AB8");
extern "C" int X_func_00134CD0(...) asm("func_00134CD0");
extern "C" int X_func_001351B0(...) asm("func_001351B0");
extern "C" int X_func_00135418(...) asm("func_00135418");
extern "C" int X_func_00135494(...) asm("func_00135494");
extern "C" int X_func_00135594(...) asm("func_00135594");
extern "C" int X_func_001832E8(...) asm("func_001832E8");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001874F4(...) asm("func_001874F4");
extern "C" int X_func_00192E94(...) asm("func_00192E94");
extern "C" int X_func_0019381C(...) asm("func_0019381C");
extern "C" int X_func_00193868(...) asm("func_00193868");
extern "C" int X_func_0019397C(...) asm("func_0019397C");
extern "C" int X_func_00193E20(...) asm("func_00193E20");
extern "C" int X_func_00193F74(...) asm("func_00193F74");
extern "C" int X_func_00193FEC(...) asm("func_00193FEC");
extern "C" int X_func_001940A4(...) asm("func_001940A4");
extern "C" int X_func_001943D8(...) asm("func_001943D8");
extern "C" int X_func_00194588(...) asm("func_00194588");
extern "C" int X_func_00194688(...) asm("func_00194688");
extern "C" int X_func_00197E68(...) asm("func_00197E68");
extern "C" int X_func_001C5094(...) asm("func_001C5094");
extern "C" int X_func_001C5168(...) asm("func_001C5168");
extern "C" int X_func_001C51E0(...) asm("func_001C51E0");
extern "C" int X_func_0021A5B0(...) asm("func_0021A5B0");
extern "C" int X_func_0021A700(...) asm("func_0021A700");
extern "C" int X_func_0022AED8(...) asm("func_0022AED8");
extern "C" int X_func_0022B330(...) asm("func_0022B330");
extern "C" int X_func_0022B350(...) asm("func_0022B350");
extern "C" int X_func_0022B370(...) asm("func_0022B370");
extern "C" int X_func_0022B3D8(...) asm("func_0022B3D8");
extern "C" int X_func_0022B6F8(...) asm("func_0022B6F8");
extern "C" int X_func_0022B730(...) asm("func_0022B730");
extern "C" int X_memcpy(...) asm("memcpy");
extern "C" int X_memmove(...) asm("memmove");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_mnuBase__vfunc_03(...) asm("mnuBase__vfunc_03");
extern "C" int X_releaseTex__10DogTexInfoi(...) asm("releaseTex__10DogTexInfoi");
extern "C" int X_strcpy(...) asm("strcpy");
extern "C" int Xiii_func_001BE524__10FileReaderP11FileReadReqi(int, int, int) asm("func_001BE524__10FileReaderP11FileReadReqi");
extern int D_0029BFB4;
extern int D_0029C0F8;
extern int D_006E9800;
extern int D_007812C0;

extern "C" void X_strcpy_pv(char *dst, char *src) asm("strcpy");

extern "C" void func_0019397C(int arg0, char *arg1, int arg2, int arg3)
{
    char *p;
    int i;
    int count;

    count = *(int *)((char *)arg0 + 0x20);
    if (count == *(int *)((char *)arg0 + 0x1C)) {
        return;
    }
    p = (char *)*(int *)((char *)arg0 + 0x18);
    for (i = 0; i < count; i++) {
        if ((*(int *)(p + 8) & 0xF) == (arg2 & 0xF)) {
            if (*(int *)(p + 0xC) == arg3) {
                return;
            }
        }
        p += 0x30;
    }
    X_strcpy_pv(p + 0x10, arg1);
    *(int *)(p + 8) = arg2;
    *(int *)(p + 0xC) = arg3;
    *(int *)((char *)arg0 + 0x20) = *(int *)((char *)arg0 + 0x20) + 1;
}

// NON_MATCHING: 4/192 differ, 4 edits
#ifdef NON_MATCHING
extern "C" int X_func_0022B518(...) asm("func_0022B518");
extern "C" float Xfi_func_0022E958(int) asm("func_0022E958");
extern "C" int Xii_clear__6BedPfh(int) asm("clear__6BedPfh");
extern "C" int Xii_func_00194588(int) asm("func_00194588");
extern "C" int Xiii_func_00193E20_queue(int, int) asm("func_00193E20");
extern "C" int Xiii_func_001BE564(int, int) asm("func_001BE564");
extern "C" int Xiii_getIndex__C6BedPfhPCc(int, int) asm("getIndex__C6BedPfhPCc");
extern "C" int Xiii_setTop__6BedPfhPv(int, int) asm("setTop__6BedPfhPv");
extern "C" int Xiiii_func_001BE524__10FileReaderP11FileReadReqi(int, int, int) asm("func_001BE524__10FileReaderP11FileReadReqi");
extern "C" int Xiiii_memmove_queue(int, int, int) asm("memmove");
extern "C" int Xiiiiii_loadTM2__10DogTexInfoPCcPvii(int, int, int, int, int) asm("loadTM2__10DogTexInfoPCcPvii");
extern "C" char *Xpi_func_00194588(int) asm("func_00194588");
extern "C" void func_00193A1C(int arg0)
{
    char *temp_v0_2;
    int temp_a0_2;
    int temp_a0_3;
    int temp_s0;
    int temp_s0_4;
    int temp_s1;
    int temp_v0;
    int temp_v1;
    int var_a0;
    int var_v0;
    unsigned int temp_a0;
    int temp_a0_4;
    int temp_a0_5;
    int temp_a1;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s2;
    int temp_s4;
    register int temp_s4_2 PS2_REG("$20");
    int temp_v0_3;

loop_1:
    temp_s4 = M2C_FIELD(arg0, int *, 0x18);
    if (M2C_FIELD(arg0, int *, 4) & 4) {
        if (Xiii_func_001BE564(arg0 + 0x68, 1) == 0) {
            if (M2C_FIELD(arg0, int *, 4) & 8) {
                Xiii_func_00193E20_queue(arg0, 0);
                M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) & ~8);
            } else {
                temp_a0 = M2C_FIELD(temp_s4, int *, 8) & 0xF;
                switch (temp_a0) {
                case 1:
                    temp_a0_2 = M2C_FIELD(temp_s4, int *, 0);
                    temp_s2 = M2C_FIELD(arg0, int *, 0x94) + (M2C_FIELD(temp_s4, int *, 0xC) << 5);
                    M2C_FIELD(temp_s2, int *, 0) = temp_a0_2;
                    X_func_0022B330(temp_a0_2);
                    M2C_FIELD(temp_s2, int *, 0x14) = (int) M2C_FIELD(temp_s4, int *, 4);
                    temp_s1 = X_func_0022B370(M2C_FIELD(temp_s2, int *, 0));
                    temp_s0 = temp_s1 * 0x30;
                    temp_v0 = ((((((temp_s1 * 3) << 2) - temp_s1) << 3) + temp_s1) << 1) + 2;
                    temp_s1 <<= 6;
                    temp_v0_2 = Xpi_func_00194588(temp_v0);
                    temp_s0 = (int)(temp_v0_2 + temp_s0);
                    temp_v1 = temp_s0 + temp_s1;
                    M2C_FIELD(temp_s2, int *, 4) = (int)temp_v0_2;
                    M2C_FIELD(temp_s2, int *, 8) = temp_s0;
                    M2C_FIELD(temp_s2, int *, 0xC) = temp_v1;
                    M2C_FIELD(temp_s2, int *, 0x10) = (int) (temp_v1 + temp_s1);
                    temp_v0_3 = M2C_FIELD(arg0, int *, 0xC);
                    X_func_0021A5B0(M2C_FIELD(temp_s2, int *, 0), M2C_FIELD(temp_v0_3, int *, 8), M2C_FIELD(temp_v0_3, int *, 4));
                    X_func_0021A700(M2C_FIELD(temp_s2, int *, 0), M2C_FIELD(temp_s2, int *, 8));
                    break;
                case 2:
                    temp_a0_3 = M2C_FIELD(temp_s4, int *, 0);
                    temp_s0_3 = M2C_FIELD(arg0, int *, 0x9C) + (M2C_FIELD(temp_s4, int *, 0xC) * 0x10);
                    M2C_FIELD(temp_s0_3, int *, 0) = temp_a0_3;
                    X_func_0022B518(temp_a0_3);
                    M2C_FIELD(temp_s0_3, int *, 4) = (int)(Xfi_func_0022E958(M2C_FIELD(temp_s0_3, int *, 0)) * 30.0f);
                    break;
                case 4:
                    temp_s0_2 = M2C_FIELD(arg0, int *, 0xA4) + (M2C_FIELD(temp_s4, int *, 0xC) * 0x10);
                    M2C_FIELD(temp_s0_2, int *, 8) = Xiiiiii_loadTM2__10DogTexInfoPCcPvii((int) M2C_FIELD(arg0, int *, 0xC), (int) (temp_s4 + 0x10), M2C_FIELD(temp_s4, int *, 0), 0, -1);
                    M2C_FIELD(temp_s0_2, int *, 0) = (int) M2C_FIELD(temp_s4, int *, 0);
                    M2C_FIELD(temp_s0_2, int *, 4) = (int) M2C_FIELD(temp_s4, int *, 4);
                    break;
                }
            }
            M2C_FIELD(temp_s4, int *, 0) = 0;
            Xiii_func_00193E20_queue(arg0, 0);
            temp_a0_4 = M2C_FIELD(arg0, int *, 0x18);
            Xiiii_memmove_queue(temp_a0_4, temp_a0_4 + 0x30, (M2C_FIELD(arg0, int *, 0x20) * 0x30) - 0x30);
            M2C_FIELD(arg0, int *, 0x20) = (int) (M2C_FIELD(arg0, int *, 0x20) - 1);
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) & ~4);
            goto block_19;
        }
    } else {
block_19:
        if (M2C_FIELD(arg0, int *, 0x20) != 0) {
            BedPfh stack;
            temp_s4_2 = M2C_FIELD(arg0, int *, 0x18);
            stack.setTop(M2C_FIELD(arg0, void **, 0x64));
            temp_s0_4 = stack.getIndex((const char *)(temp_s4_2 + 0x10));
            if (stack.m_file_size != 0) {
                var_a0 = stack.m_file_size[temp_s0_4];
            } else {
                var_a0 = -1;
            }
            M2C_FIELD(temp_s4_2, int *, 4) = var_a0;
            M2C_FIELD(temp_s4_2, int *, 0) = Xii_func_00194588(var_a0);
            M2C_FIELD(arg0, int *, 0x84) = 0;
            if (stack.m_file_offset != 0) {
                var_v0 = stack.m_file_offset[temp_s0_4];
            } else {
                var_v0 = -1;
            }
            M2C_FIELD(arg0, int *, 0x80) = var_v0;
            temp_a0_5 = arg0 + 0x68;
            M2C_FIELD(arg0, int *, 0x8C) = (int) M2C_FIELD(temp_s4_2, int *, 4);
            M2C_FIELD(arg0, int *, 0x88) = (int) M2C_FIELD(temp_s4_2, int *, 0);
            temp_a1 = arg0 + 0x70;
            if (M2C_FIELD(temp_s4_2, int *, 8) & 0x10) {
                Xiiii_func_001BE524__10FileReaderP11FileReadReqi((int) temp_a0_5, (int) temp_a1, 0);
                M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 4);
                goto loop_1;
            }
            Xiiii_func_001BE524__10FileReaderP11FileReadReqi((int) temp_a0_5, (int) temp_a1, 1);
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 4);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193A1C);
#endif

// NON_MATCHING: 1/56 differ, 1 edits
#ifdef NON_MATCHING
extern "C" int Xiii_func_00193E20(int, int) asm("func_00193E20");
extern "C" int Xiiii_memmove(int, int, int) asm("memmove");
extern "C" void func_00193D1C(int arg0, int arg1, int arg2)
{
    register int p PS2_REG("$3");
    register int count PS2_REG("$4");
    int i;

    count = M2C_FIELD(arg0, int *, 0x20);
    if (count <= 0) {
        return;
    }
    p = M2C_FIELD(arg0, int *, 0x18);
    arg1 &= 0xF;
    i = 1;
    if ((M2C_FIELD(p, int *, 8) & 0xF) == arg1) {
        if (M2C_FIELD(p, int *, 0xC) == arg2) {
            M2C_FIELD(arg0, int *, 4) |= 8;
            return;
        }
    }
    while (i < count) {
        p += 0x30;
        if ((M2C_FIELD(p, int *, 8) & 0xF) == arg1) {
            if (M2C_FIELD(p, int *, 0xC) == arg2) {
                Xiii_func_00193E20(arg0, i);
                p = M2C_FIELD(arg0, int *, 0x18) + i * 0x30;
                Xiiii_memmove(p, p + 0x30, (M2C_FIELD(arg0, int *, 0x20) - i) * 0x30 - 0x30);
                M2C_FIELD(arg0, int *, 0x20) = M2C_FIELD(arg0, int *, 0x20) - 1;
                return;
            }
        }
        i++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193D1C);
#endif

extern "C" void func_00193DFC(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x20)) > 0) {
        (*(int *)(int *)((char *)(arg0) + 0x20)) = 1;
        (*(int *)(int *)((char *)(arg0) + 0x4)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x4)) | 8);
    }
}


extern "C" void func_00193E20(int arg0, int arg1)
{
    int temp_s0;
    int temp_v0;

    temp_s0 = M2C_FIELD(arg0, int *, 0x18) + (arg1 * 0x30);
    temp_v0 = M2C_FIELD(temp_s0, int *, 0);
    if (temp_v0 != 0) {
        Xii_func_00194688(temp_v0);
        M2C_FIELD(temp_s0, int *, 0) = 0;
    }
    M2C_FIELD(temp_s0, int *, 4) = 0;
    M2C_FIELD(temp_s0, signed char *, 0x10) = 0;
    M2C_FIELD(temp_s0, int *, 8) = 0;
    M2C_FIELD(temp_s0, int *, 0xC) = -1;
}

extern "C" int func_00193E7C(int arg0, int arg1, int arg2)
{
    if (M2C_FIELD(arg0, int *, 0x64) == 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, int *, 4) & 4) {
        return 0;
    }

    BedPfh pfh;
    pfh.setTop(M2C_FIELD(arg0, void **, 0x64));
    int idx = pfh.getIndex((const char *)arg1);
    int size = pfh.getFileSize(idx);
    int result = X_func_00194588(size);
    M2C_FIELD(arg0, int *, 0x84) = 0;
    M2C_FIELD(arg0, int *, 0x80) = pfh.getFileOffset(idx);
    M2C_FIELD(arg0, int *, 0x8C) = size;
    M2C_FIELD(arg0, int *, 0x88) = result;
    Xiii_func_001BE524__10FileReaderP11FileReadReqi(arg0 + 0x68, arg0 + 0x70, 0);
    if (arg2 != 0) {
        (*(int *)arg2) = size;
    }
    return result;
}

extern "C" void func_00193F74(int arg0, int arg1)
{
    if (arg1 != 0) {
        X_func_00194688(arg1);
    }
}


extern "C" void func_00193F98(int arg0, int arg1)
{
    int temp_s0;
    int temp_v0;

    temp_s0 = (arg1 << 5) + M2C_FIELD(arg0, int *, 0x94);
    temp_v0 = M2C_FIELD(temp_s0, int *, 0);
    if (temp_v0 != 0) {
        Xiii_func_00193F74((int) arg0, temp_v0);
        Xii_func_00194688(M2C_FIELD(temp_s0, int *, 4));
        Xiiii_memset(temp_s0, 0, 0x20);
    }
}

extern "C" void func_00193FEC(int arg0, int arg1, int arg2)
{
    register int temp_a1 PS2_REG("$5");
    register int temp_a2 PS2_REG("$6");
    int temp_s3;
    int temp_s1;
    int temp_v0;
    int temp_a0;
    int var_s2;

    var_s2 = 0;
    temp_a1 = arg1 << 5;
    temp_a2 = arg2 << 4;
    temp_s3 = M2C_FIELD(arg0, int *, 0x9C) + temp_a2;
    temp_s1 = M2C_FIELD(arg0, int *, 0x94) + temp_a1;
    temp_v0 = X_func_0022B6F8(*(int *)temp_s3, temp_a1, temp_a2);
    *(short *)M2C_FIELD(temp_s1, int *, 0x10) = temp_v0;
    if (temp_v0 > 0) {
        do {
            short *out;
            temp_a0 = X_func_0022B3D8(*(int *)temp_s1,
                                      X_func_0022B730(*(int *)temp_s3, var_s2 & 0xFFFF));
            out = (short *)(var_s2 * 2 + M2C_FIELD(temp_s1, int *, 0x10) + 2);
            var_s2++;
            if (temp_a0 >= 0) {
                out[0] = temp_a0;
            } else {
                out[0] = -1;
            }
        } while (var_s2 < temp_v0);
    }
}

extern "C" int func_001940A4(int arg0, int arg1, int arg2)
{
    char *p;
    int i;
    int cap;
    int limit;

    cap = *(int *)((char *)arg0 + 0x98);
    limit = arg2 + 1;
    if (cap < limit) {
        limit = cap;
    }
    for (; arg1 < limit; arg1++) {
        if (*(int *)(int *)((arg1 << 5) + *(int *)((char *)arg0 + 0x94)) != 0) {
            continue;
        }
        i = 0;
        p = *(char **)((char *)arg0 + 0x18);
        for (; i < *(int *)((char *)arg0 + 0x20); i++) {
            if ((*(int *)(p + 8) & 0xF) == 1) {
                if (*(int *)(p + 0xC) == arg1) {
                    break;
                }
            }
            p += 0x30;
        }
        if (i == *(int *)((char *)arg0 + 0x20)) {
            return arg1;
        }
    }
    return -1;
}

// NON_MATCHING: 48/76 differ, 7 relocs differ (size 0x130, game 0x138), 28 edits
#ifdef NON_MATCHING
extern "C" int func_00194148(int arg0, int arg1, int arg2)
{
    register int self PS2_REG("$20");
    register int temp_s0 PS2_REG("$16");
    register int temp_s1 PS2_REG("$17");
    register int temp_s2 PS2_REG("$18");
    register int temp_s3 PS2_REG("$19");
    int base;
    int n;
    int p;

    self = arg0;
    temp_s0 = arg1;
    temp_s1 = arg2 << 5;
    if (M2C_FIELD(M2C_FIELD(self, int *, 0x94) + temp_s1, int *, 0) == 0) {
        return 0;
    }
    if (X_func_001940A4(self, temp_s0, temp_s0) != temp_s0) {
        return 0;
    }
    base = M2C_FIELD(self, int *, 0x94);
    temp_s3 = base + temp_s1;
    temp_s2 = base + (temp_s0 << 5);
    X_func_0022B350(M2C_FIELD(temp_s3, int *, 0));
    n = X_func_00194588(M2C_FIELD(temp_s3, int *, 0x14));
    M2C_FIELD(temp_s2, int *, 0) = n;
    X_memcpy(n, M2C_FIELD(temp_s3, int *, 0), M2C_FIELD(temp_s3, int *, 0x14));
    X_func_0022B330(M2C_FIELD(temp_s2, int *, 0));
    M2C_FIELD(temp_s2, int *, 0x14) = M2C_FIELD(temp_s3, int *, 0x14);
    n = X_func_0022B370(M2C_FIELD(temp_s2, int *, 0));
    p = X_func_00194588((n * 89) << 1);
    M2C_FIELD(temp_s2, int *, 4) = p;
    p = p + n * 48;
    M2C_FIELD(temp_s2, int *, 8) = p;
    p = p + n * 64;
    M2C_FIELD(temp_s2, int *, 0xC) = p;
    p = p + n * 64;
    M2C_FIELD(temp_s2, int *, 0x10) = p;
    X_func_0021A5B0(M2C_FIELD(temp_s2, int *, 0), M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 8), M2C_FIELD(M2C_FIELD(self, int *, 0xC), int *, 4));
    X_func_0021A700(M2C_FIELD(temp_s2, int *, 0), M2C_FIELD(temp_s2, int *, 8));
    X_func_0022B330(M2C_FIELD(temp_s3, int *, 0));
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194148);
#endif

extern "C" void func_00194280(int arg0, int arg1)
{
    int temp_s0;
    int temp_v0;

    temp_s0 = (arg1 * 0x10) + M2C_FIELD(arg0, int *, 0x9C);
    temp_v0 = (*(int *)(temp_s0));
    if (temp_v0 != 0) {
        Xiii_func_00193F74((int) arg0, temp_v0);
        Xiiii_memset(temp_s0, 0, 0x10);
    }
}

extern "C" int func_001942CC(int arg0, int arg1, int arg2)
{
    char *p;
    int i;
    int cap;
    int limit;

    cap = *(int *)((char *)arg0 + 0xA0);
    limit = arg2 + 1;
    if (cap < limit) {
        limit = cap;
    }
    for (; arg1 < limit; arg1++) {
        if (*(int *)(int *)((arg1 << 4) + *(int *)((char *)arg0 + 0x9C)) != 0) {
            continue;
        }
        i = 0;
        p = *(char **)((char *)arg0 + 0x18);
        for (; i < *(int *)((char *)arg0 + 0x20); i++) {
            if ((*(int *)(p + 8) & 0xF) == 2) {
                if (*(int *)(p + 0xC) == arg1) {
                    break;
                }
            }
            p += 0x30;
        }
        if (i == *(int *)((char *)arg0 + 0x20)) {
            return arg1;
        }
    }
    return -1;
}

extern "C" void func_00194370(int arg0, int arg1)
{
    int temp_s0;

    if (X_func_001943D8() != 0) {
        temp_s0 = (*(int *)(int *)((char *)(arg0) + 0xA4)) + (arg1 * 0x10);
        X_releaseTex__10DogTexInfoi((*(int *)(int *)((char *)(arg0) + 0xC)), (*(int *)(int *)((char *)(temp_s0) + 0x8)));
        X_func_00193F74(arg0, (*(int *)(int *)((char *)(temp_s0) + 0x0)));
        (*(int *)(int *)((char *)(temp_s0) + 0x0)) = 0;
        (*(int *)(int *)((char *)(temp_s0) + 0x4)) = 0;
        (*(int *)(int *)((char *)(temp_s0) + 0x8)) = -1;
    }
}


extern "C" int func_001943D8(int arg0, int arg1)
{
    int var_a0;
    int temp_v1;

    temp_v1 = (*(int *)(int *)((char *)(arg0) + 0xA4)) + (arg1 * 0x10);
    var_a0 = 0;
    if ((*(int *)(int *)((char *)(temp_v1) + 0x0)) != 0) {
        var_a0 = ~(*(int *)(int *)((char *)(temp_v1) + 0x8)) != 0;
    }
    return var_a0;
}


extern "C" int func_00194404(int arg0, int arg1, int arg2)
{
    register int self PS2_REG("$17");
    register int limit PS2_REG("$18");
    register int i PS2_REG("$5");
    register int count PS2_REG("$6");
    int p;
    int idx;

    idx = arg1;
    self = arg0;
    limit = arg2 + 1;
    if (M2C_FIELD(self, int *, 0xA8) < limit) {
        limit = M2C_FIELD(self, int *, 0xA8);
    }
    while (idx < limit) {
        if (Xiii_func_001943D8(self, idx) == 0) {
            count = M2C_FIELD(self, int *, 0x20);
            i = 0;
            p = M2C_FIELD(self, int *, 0x18);
            while (i < count) {
                if ((M2C_FIELD(p, int *, 8) & 0xF) == 4) {
                    if (M2C_FIELD(p, int *, 0xC) == idx) {
                        break;
                    }
                }
                i++;
                p += 0x30;
            }
            if (i == M2C_FIELD(self, int *, 0x20)) {
                return idx;
            }
        }
        idx++;
    }
    return -1;
}

extern "C" void func_001944D0()
{
    int temp_v0;

    temp_v0 = X_alloc__9BedMemoryii((int)&D_006E9800, 0x100800, -1);
    D_0029BFB4 = temp_v0;
    X_memset(temp_v0, 0, 0x100800);
    (*(int *)(int *)((char *)(D_0029BFB4) + 0x0)) = D_0029BFB4 + 0x800;
    (*(int *)(int *)((char *)(D_0029BFB4) + 0x4)) = 0x100000;
    (*(int *)(int *)((char *)(D_0029BFB4) + 0x8)) = 1;
}


extern "C" void func_00194548()
{
    if (D_0029BFB4 != 0) {
        X_free__9BedMemoryPv((int)&D_006E9800, D_0029BFB4);
        D_0029BFB4 = 0;
    }
}


struct PBookHeapEnt {
    char *top;
    unsigned int size;
    int flags;
    int unk;
};

extern "C" char *func_00194588(unsigned int size)
{
    PBookHeapEnt *p;
    PBookHeapEnt *best;
    unsigned int bestdiff;
    int i;

    size = (size + 0xF) >> 4 << 4;
    p = (PBookHeapEnt *)D_0029BFB4;
    best = 0;
    bestdiff = -1;
    for (i = 0x7F; i >= 0; i--, p++) {
        if ((p->flags & 3) == 1 && p->size >= size && (best == 0 || p->size - size < bestdiff)) {
            bestdiff = p->size - size;
            best = p;
        }
    }
    if (best == 0) {
        return 0;
    }
    if (bestdiff != 0) {
        p = (PBookHeapEnt *)D_0029BFB4;
        i = 0;
        if (((p->flags ^ 1) & 1) == 0) {
            do {
                i++;
                p++;
                if (i >= 0x80) {
                    break;
                }
            } while (((p->flags ^ 1) & 1) == 0);
        }
        if (i == 0x80) {
            return 0;
        }
        p->top = best->top;
        p->flags = 3;
        p->size = size;
        best->top += size;
        best->size -= size;
    } else {
        p = best;
        p->flags |= 2;
    }
    return p->top;
}

// NON_MATCHING: 18/22 differ (size 0x58, game 0x5C), 5 edits
#ifdef NON_MATCHING
extern "C" void func_00194688(int arg0)
{
    int i;
    int v;
    char *p;

    i = 0;
    p = (char *)D_0029BFB4;
    v = *(volatile int *)(p + 8);
    while ((v & 3) != 3 || M2C_FIELD(p, int *, 0) != arg0) {
        i += 1;
        if (i >= 0x80)
            return;
        p += 0x10;
        v = M2C_FIELD(p, int *, 8);
    }
    M2C_FIELD(p, int *, 8) = v & -3;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194688);
#endif

extern "C" void func_001946E4()
{
    PBookHeapEnt *p;
    PBookHeapEnt *q;
    int i;
    int j;

    i = 0;
    p = (PBookHeapEnt *)D_0029BFB4;
    do {
        if ((p->flags & 3) == 1) {
            do {
                j = i + 1;
                q = p + 1;
                while (j < 0x80) {
                    if ((q->flags & 3) == 1) {
                        if ((unsigned int)p->top + p->size == (unsigned int)q->top) {
                            p->size += q->size;
                            q->flags = 0;
                            break;
                        }
                        if ((unsigned int)q->top + q->size == (unsigned int)p->top) {
                            p->top = q->top;
                            p->size += q->size;
                            q->flags = 0;
                            break;
                        }
                    }
                    j++;
                    q++;
                }
            } while (j < 0x80);
        }
        i++;
        p++;
    } while (i < 0x7F);
}

extern "C" void func_001947A4(PBookMnuMapName *arg0)
{
    register PBookMnuMapName *self PS2_REG("$16") = arg0;
    register char *p PS2_REG("$17") = (char *)self + 0x150;
    int i = 1;
    Xii_func_00192AC0_ctor((int)self);
    M2C_FIELD(self, int *, 0x10C) = (int)&vtbl_MnuMap_ctor;
    do {
        Xii_func_0018330C_ctor((int)p);
        p += 0x3BC;
        i -= 1;
    } while (i != -1);
    M2C_FIELD(self, int *, 0) = 4;
    __builtin_memcpy(self->m_name, "data/mnurpk/mnumap.rpk", 0x17);
    asm volatile("" ::: "memory");
    M2C_FIELD(self, int *, 0x144) = i;
    M2C_FIELD(self, int *, 0x148) = i;
}

extern "C" void X_MnuMap__vfunc_03_v1(void *) asm("MnuMap__vfunc_03");
extern "C" void X___builtin_delete_vm(void *) asm("__builtin_delete");
extern "C" void X_func_00183B24_v1(void *, int) asm("func_00183B24");
extern "C" void X_mnuBase__vfunc_01_v1(void *, int) asm("mnuBase__vfunc_01");
extern int vtbl_MnuMap_v1 asm("_vt$6MnuMap");

extern "C" void MnuMap__vfunc_01(char *arg0, int arg1)
{
    char *start = arg0 + 0x150;
    *(void **)(arg0 + 0x10C) = &vtbl_MnuMap_v1;
    X_MnuMap__vfunc_03_v1(arg0);
    if (start != 0) {
        char *p = arg0 + 0x8C8;
        if (start != p) {
            do {
                p -= 0x3BC;
                X_func_00183B24_v1(p, 2);
            } while (start != p);
        }
    }
    X_mnuBase__vfunc_01_v1(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete_vm(arg0);
    }
}

extern "C" void MnuMap__vfunc_02(int arg0, int arg1)
{
    X_func_00192BA4(arg0, arg1, 0x1B, 0, 0, 0x1A);
    M2C_FIELD(arg0, int *, 0x14) = 0;
    ((m2c_v10C_50_i *)arg0)->v10();
    X_func_001949BC(arg0);
}

extern "C" void MnuMap__vfunc_03(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x144));
    if (temp_v0 != -1) {
        X_func_001348B0((*(int *)(int *)((char *)(arg0) + 0x8)), temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0x144)) = -1;
    }
    X_func_00193868(arg0);
    X_func_00187464(arg0 + 0x150);
    X_mnuBase__vfunc_03(arg0);
}


INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001949BC);

extern "C" void func_00194FA4(int arg0)
{
    Xiiff_func_00192E94(arg0, 256.0f, 1.57079616189003f);
    Xii_func_0019381C(arg0);
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuMap__vfunc_05);

// NON_MATCHING: 204/261 differ, 14 relocs differ (size 0x414, game 0x43C), 110 edits
#ifdef NON_MATCHING
extern "C" float Xfi_getLeftY__C6BedPad(int) asm("getLeftY__C6BedPad");
extern "C" int Xii_func_00195A34(int) asm("func_00195A34");
extern "C" int Xii_func_00196760(int) asm("func_00196760");
extern "C" int Xiii_func_0019586C(int, int) asm("func_0019586C");
extern int D_0029BFB8;
extern "C" void PBookMoveSoundC(int, int) asm("func_0017F8FC");
static inline void PBookMoveSound(int sound, int code) { PBookMoveSoundC(sound, code); }
extern "C" int func_00195430(int arg0, int arg1)
{
    struct { float sp0; float sp4; } stack;
    float temp_f0;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f3;
    float var_f0;
    float var_f0_2;
    float var_f1;
    float var_f1_2;
    int temp_a0_2;
    int temp_a1;
    int temp_v0_2;
    int temp_v1_3;
    int var_s2;
    int var_v0;
    int var_v0_2;
    unsigned short temp_a0_3;
    unsigned short temp_v1;
    unsigned int temp_v0_3;
    unsigned int temp_v1_2;
    int temp_a0;
    int temp_v0;

    Xii_func_001874AC(arg0 + 0x150);
    temp_a1 = M2C_FIELD(arg0, int *, 4);
    if (!(temp_a1 & 2)) {
        temp_v1 = M2C_FIELD(arg1, unsigned short *, 0x7A);
        if (PBookButton(temp_v1, 13) || PBookButton(temp_v1, 0)) {
            M2C_FIELD(arg0, int *, 4) = temp_a1 | 2;
            return 0;
        }
        if (PBookButton(temp_v1, 11)) {
            temp_v0 = M2C_FIELD(arg0, int *, 0x110);
            if (M2C_FIELD(temp_v0, int *, 0) != M2C_FIELD(temp_v0, int *, 0x20) || (temp_a1 & 0x01000000)) goto fail;
            var_v0 = 0x80002;
            goto turn;
        }
        if (PBookButton(temp_v1, 10)) {
            temp_a0 = M2C_FIELD(arg0, int *, 0x110);
            if ((unsigned int)&D_0029BFB8 >= (unsigned int)temp_a0 || M2C_FIELD(temp_a0, int *, 0) != M2C_FIELD(temp_a0, int *, -0x20) || (temp_a1 & 0x01000000)) goto fail;
            var_v0 = 0x100002;
turn:
        M2C_FIELD(arg0, int *, 0x14) = 6;
        M2C_FIELD(arg0, int *, 4) = temp_a1 | var_v0;
        PBookMoveSound((int)&D_007B2580, 4);
        goto update;
        } else {
            if ((temp_v1 >> 15) != 0) {
                if (temp_a1 & 0x01000000) goto fail;
                temp_f2 = M2C_FIELD(arg0, float *, 0x11C);
                temp_f3 = M2C_FIELD(arg0, float *, 0x120);
                temp_v0_2 = (temp_a1 | 0x20002) ^ 0x10000;
                M2C_FIELD(arg0, int *, 0x130) = 0x12;
                M2C_FIELD(arg0, int *, 0x12C) = 0;
                M2C_FIELD(arg0, int *, 4) = temp_v0_2;
                M2C_FIELD(arg0, float *, 0x124) = temp_f2;
                M2C_FIELD(arg0, float *, 0x128) = temp_f3;
                if (!(temp_v0_2 & 0x10000)) {
                    var_f0 = -192.0f;
                    var_f1 = -128.0f;
                } else {
                    var_f0 = 192.0f;
                    var_f1 = 128.0f;
                }
                M2C_FIELD(arg0, float *, 0x11C) = (float) (temp_f2 + var_f0);
                M2C_FIELD(arg0, float *, 0x120) = (float) (temp_f3 + var_f1);
                Xiii_func_0019586C(arg0, arg0 + 0x11C);
                goto confirm;
            } else if (PBookButton(temp_v1, 12)) {
                if (!Xii_func_00196760(arg0)) goto fail;
                temp_a0_2 = M2C_FIELD(arg0, int *, 4);
                if (temp_a0_2 & 0x01000000) goto fail;
                M2C_FIELD(arg0, int *, 0x14) = 6;
                M2C_FIELD(arg0, int *, 4) = temp_a0_2 | 0x200002;
confirm:
                PBookMoveSound((int)&D_007B2580, 4);
                goto update;
            }
            goto movement;
            {
fail:
                PBookMoveSound((int)&D_007B2580, 3);
                goto update;
            }
        }
movement:
                var_s2 = 1;
                stack.sp0 = Xfi_getLeftX__C6BedPad((int) arg1) * 16.0f;
                temp_f0 = Xfi_getLeftY__C6BedPad((int) arg1) * 16.0f;
                stack.sp4 = temp_f0;
                if ((stack.sp0 == 0.0f) && (temp_f0 == 0.0f)) {
                    temp_a0_3 = M2C_FIELD(arg1, unsigned short *, 0x78);
                    temp_v0_3 = temp_a0_3 & 0xFFFF;
                    var_v0_2 = PBookButton(temp_v0_3, 5);
                    if (PBookButton(temp_v0_3, 7)) {
                        var_v0_2 -= 1;
                    }
                    temp_v1_2 = temp_a0_3 & 0xFFFF;
                    stack.sp0 = (float) var_v0_2 * 16.0f;
                    temp_v1_3 = PBookButton(temp_v1_2, 6);
                    if (PBookButton(temp_v1_2, 4)) {
                        var_f1_2 = 16.0f;
                        var_f0_2 = (float) (temp_v1_3 - 1);
                    } else {
                        var_f1_2 = (float) temp_v1_3;
                        var_f0_2 = 16.0f;
                    }
                    stack.sp4 = var_f1_2 * var_f0_2;
                }
                stack.sp0 += M2C_FIELD(arg0, float *, 0x11C);
                stack.sp4 += M2C_FIELD(arg0, float *, 0x120);
                Xiii_func_0019586C(arg0, (int)&stack);
                temp_f2_2 = stack.sp0 - M2C_FIELD(arg0, float *, 0x11C);
                if (temp_f2_2 >= 0.5f) {
                    M2C_FIELD(arg0, float *, 0x11C) = stack.sp0;
                    var_s2 = 0;
                    M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x400000);
                } else if (temp_f2_2 <= -0.5f) {
                    M2C_FIELD(arg0, float *, 0x11C) = stack.sp0;
                    var_s2 = 0;
                    M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) & 0xFFBFFFFF);
                }
                temp_f2_3 = stack.sp4 - M2C_FIELD(arg0, float *, 0x120);
                if (temp_f2_3 >= 0.5f) {
                    M2C_FIELD(arg0, float *, 0x120) = stack.sp4;
                    var_s2 = 0;
                    M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x800000);
                } else if (temp_f2_3 <= -0.5f) {
                    M2C_FIELD(arg0, float *, 0x120) = stack.sp4;
                    var_s2 = 0;
                    M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) & 0xFF7FFFFF);
                }
                if (var_s2 == 0) {
                    M2C_FIELD(arg0, int *, 0x140) = (int) ((int) (M2C_FIELD(arg0, int *, 0x140) + 1) % 12);
                } else {
                    M2C_FIELD(arg0, int *, 0x140) = 0;
                }
    }
update:
    Xii_func_00195A34(arg0);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195430);
#endif

extern "C" void func_0019586C(int arg0, float *arg1)
{
    float sp[2];
    float target;
    float ratio;
    float d;

    Xiii_func_001959EC(arg0, (int) sp);

    target = (float) M2C_FIELD(arg0, int *, 0x114);
    ratio = sp[0];
    if (ratio <= target) {
        if (arg1[0] < 0.0f) {
            arg1[0] = 0.0f;
        } else {
            d = target - ratio;
            if (d < arg1[0]) {
                arg1[0] = d;
            }
        }
    } else {
        arg1[0] = target * 0.5f - ratio * 0.5f;
    }

    target = (float) M2C_FIELD(arg0, int *, 0x118);
    ratio = sp[1];
    if (ratio <= target) {
        if (arg1[1] < 0.0f) {
            arg1[1] = 0.0f;
        } else {
            d = target - ratio;
            if (d < arg1[1]) {
                arg1[1] = d;
            }
        }
    } else {
        arg1[1] = target * 0.5f - ratio * 0.5f;
    }
}

extern "C" int func_00195958(int arg0, float fparg0, float fparg1)
{
    float sp[2];
    int var_v0;

    Xiii_func_001959EC(arg0, (int)sp);
    var_v0 = 0;
    if (!(fparg0 < 0.0f) && !(((float) M2C_FIELD(arg0, int *, 0x114) - sp[0]) < fparg0) && !(fparg1 < 0.0f) && !(((float) M2C_FIELD(arg0, int *, 0x118) - sp[1]) < fparg1)) {
        var_v0 = 1;
    }
    return var_v0;
}

extern "C" void func_001959EC(int arg0, int arg1)
{
    float var_f0;
    float var_f1;

    if (!(M2C_FIELD(arg0, int *, 4) & 0x10000)) {
        var_f1 = 768.0f;
        var_f0 = 512.0f;
    } else {
        var_f1 = 384.0f;
        var_f0 = 256.0f;
    }
    M2C_FIELD(arg1, float *, 4) = var_f0;
    M2C_FIELD(arg1, float *, 0) = var_f1;
}

// NON_MATCHING: 24/81 differ, 4 relocs differ, 9 edits
#ifdef NON_MATCHING
extern "C" float func_00196790(int arg0);
extern "C" int X_func_00279C98(...) asm("func_00279C98");
extern "C" int func_00195A34(int arg0)
{
    float t;
    float v;
    int count;
    int limit;
    int i;
    char sp[0x20];

    t = func_00196790(arg0);
    v = M2C_FIELD(arg0, float *, 0x124) + (M2C_FIELD(arg0, float *, 0x11C) - M2C_FIELD(arg0, float *, 0x124)) * t;
    count = (int) v / 0x80;
    limit = count - 3;
    i = 0;
    while (i < limit) {
        func_00194370(arg0, i + 2);
        i++;
    }
    limit = count + 6;
    i = count + 9;
    while (i < M2C_FIELD(M2C_FIELD(arg0, int *, 0x110), int *, 0x18)) {
        func_00194370(arg0, i + 2);
        i++;
    }
    i = (count > 0) ? count - 2 : 0;
    while (i < limit + 2 && i < M2C_FIELD(M2C_FIELD(arg0, int *, 0x110), int *, 0x18)) {
        if (Xiii_func_001943D8(arg0, i + 2) == 0) {
            X_func_00279C98(sp, "%s_%02d.tm2", M2C_FIELD(M2C_FIELD(arg0, int *, 0x110), int *, 8), i + 1);
            Xiiiii_func_0019397C(arg0, (int) sp, 4, i + 2);
        }
        i++;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195A34);
#endif

extern "C" void func_00195B78(int arg0, int arg1)
{
    int temp_a1;
    int temp_s0;

    if (arg1 != 0) {
        Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 7, 0x10, 0x198);
        Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 7, 0);
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 7, 1, 0);
        Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 6, 0x88, 0x198);
        Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 6, 0);
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 6, 1, 0);
        Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 0xC, 0xFC, 0x198);
        Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 0xC, 0);
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 0xC, 1, 0);
        Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 0xA, 0x118, 0x198);
        Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 0xA, 0);
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 0xA, 1, 0);
        Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 9, 0x184, 0x198);
        Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 9, 0);
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 9, 1, 0);
        Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 4, 0x1A8, 0x198);
        Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 4, 0);
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 1, 0);
        if (M2C_FIELD(arg0, int *, 0x148) == -1) {
            M2C_FIELD(arg0, int *, 0x148) = Xiiiiii_func_00134730(M2C_FIELD(arg0, int *, 8), 0x200, 0x20, 0, -1);
        }
        int ctrl = arg0 + 0x150;
        Xiiuiii_func_00134A00((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x148), 0, 0x19A, 0x7FFF);
        Xiiuii_func_00134AB8((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x148), 0x200, 0x20);
        Xiiuiiii_func_00134CD0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x148), 0, 0, 0x200, 0x20);
        Xiiui_func_00135494((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x148), 1);
        Xiiui_func_00135418((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x148), 0);
        Xiiu_func_00135594(M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x148));
        Xiiui_func_001351B0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x148), 0);
        temp_s0 = M2C_FIELD(arg0, int *, 0x148);
        int texture = Xiu_func_001832E8(0x18U);
        return Xiiiii_func_001874F4(ctrl, temp_s0, texture, 0);
    }
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 7, 0, 0);
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 6, 0, 0);
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 0xC, 0, 0);
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 0xA, 0, 0);
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 9, 0, 0);
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 0, 0);
    Xiiui_func_001351B0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x148), 1);
    temp_a1 = M2C_FIELD(arg0, int *, 0x148);
    if (temp_a1 != -1) {
        Xiiu_func_001348B0(M2C_FIELD(arg0, int *, 8), (unsigned int) temp_a1);
        M2C_FIELD(arg0, int *, 0x148) = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuMap__vfunc_06);

extern "C" int func_00196760(int arg0)
{
    int var_a2;
    int temp_a0;
    int temp_a1;

    temp_a0 = M2C_FIELD(arg0, int *, 0x8C8);
    temp_a1 = M2C_FIELD(arg0, int *, 0x110);
    var_a2 = 0;
    if (M2C_FIELD(temp_a0, int *, 0) == M2C_FIELD(temp_a1, int *, 0)) {
        var_a2 = M2C_FIELD(temp_a0, int *, 4) == M2C_FIELD(temp_a1, int *, 4);
    }
    return var_a2;
}

extern "C" float func_00196790(int arg0)
{
    return (-Xff_cosf(((((float) M2C_FIELD(arg0, int *, 0x12C) * 180.0f) / (float) M2C_FIELD(arg0, int *, 0x130)) * 3.141592562198639f) / 180.0f) * 0.5f) + 0.5f;
}

extern "C" float func_00196804(int arg0)
{
    return (-Xff_cosf(((((float) M2C_FIELD(arg0, int *, 0x12C) * 180.0f) / (float) M2C_FIELD(arg0, int *, 0x130)) * 3.141592562198639f) / 180.0f) * 0.5f) + 0.5f;
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F7DC0);

extern "C" void func_00196878(int arg0, float *arg1)
{
    PBookMapTable table = D_002F7DC0;
    int mapObj = PBookMapObject((int)&D_007812C0);
    int map = Xii_func_001C6C38((int)&D_007812C0);
    int mode = Xii_func_001DBD90(mapObj);
    int id = Xii_func_001C6C28((int)&D_007812C0);
    int obj = Xiii_func_0017EA44((int)&D_00298EE0, id);
    if (map != -1) {
        PBookMapCoords *row = &table.row[map];
        if (map == 0 && mode == 3) {
            switch (id) {
            case 0x63: row = &table.row[3]; break;
            case 0x64: row = &table.row[4]; break;
            case 0x65: row = &table.row[5]; break;
            case 0x66: row = &table.row[6]; break;
            case 0x67: row = &table.row[7]; break;
            case 0x68: row = &table.row[8]; break;
            case 0x69: row = &table.row[9]; break;
            case 0x6A: row = &table.row[10]; break;
            case 0x33: row = &table.row[11]; break;
            case 0x32: row = &table.row[12]; break;
            }
        }
        arg1[0] = row->v[2] * -(arg1[0] + M2C_FIELD(obj, float *, 0x20)) / row->v[0] + row->v[4];
        arg1[2] = row->v[3] * (arg1[2] + M2C_FIELD(obj, float *, 0x28)) / row->v[1] + row->v[5];
    }
}

// NON_MATCHING: 6/36 differ, 5 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_0018330C(int) asm("func_0018330C");
extern "C" int Xii_func_00192AC0(int) asm("func_00192AC0");
extern int _vt$8MnuPBook;
extern "C" void func_00196A9C(int arg0)
{
    int i;
    int p;

    p = arg0 + 0x140;
    i = 1;
    Xii_func_00192AC0(arg0);
    M2C_FIELD(arg0, int *, 0x10C) = (int)&_vt$8MnuPBook;
    do {
        Xii_func_0018330C(p);
        p += 0x3BC;
        i -= 1;
    } while (i != -1);
    M2C_FIELD(arg0, int *, 0x120) = i;
    M2C_FIELD(arg0, int *, 0) = 7;
    M2C_FIELD(arg0, int *, 0x134) = i;
    M2C_FIELD(arg0, int *, 0x138) = i;
    M2C_FIELD(arg0, int *, 0x114) = i;
    M2C_FIELD(arg0, int *, 0x118) = i;
    M2C_FIELD(arg0, int *, 0x11C) = -1;
    M2C_FIELD(arg0, int *, 0x12C) = 0;
    M2C_FIELD(arg0, int *, 0x13C) = 0;
    M2C_FIELD(arg0, int *, 0x110) = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196A9C);
#endif

extern "C" void X_MnuPBook__vfunc_03_v1(void *) asm("MnuPBook__vfunc_03");
extern int vtbl_MnuPBook_v1 asm("_vt$8MnuPBook");

extern "C" void MnuPBook__vfunc_01(char *arg0, int arg1)
{
    char *start = arg0 + 0x140;
    *(void **)(arg0 + 0x10C) = &vtbl_MnuPBook_v1;
    X_MnuPBook__vfunc_03_v1(arg0);
    if (start != 0) {
        char *p = arg0 + 0x8B8;
        if (start != p) {
            do {
                p -= 0x3BC;
                X_func_00183B24_v1(p, 2);
            } while (start != p);
        }
    }
    X_mnuBase__vfunc_01_v1(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete_vm(arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F8048);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_02);

extern "C" void MnuPBook__vfunc_03(int arg0)
{
    int temp_v0;
    int temp_a0;
    int temp_a1;

    temp_v0 = *(int *)(arg0 + 0x13C);
    if (temp_v0 != 0) {
        X_func_00194688_v1(temp_v0);
        *(int *)(arg0 + 0x13C) = 0;
    }
    temp_a0 = *(int *)(arg0 + 0x12C);
    if (temp_a0 != 0) {
        X_func_00194688_v1(temp_a0);
        *(int *)(arg0 + 0x12C) = 0;
    }
    *(int *)(arg0 + 0x130) = 0;
    X_func_00193868_v1(arg0);
    temp_v0 = *(int *)(arg0 + 0x134);
    if (temp_v0 != -1) {
        X_func_001348B0_v1(*(int *)(arg0 + 8), temp_v0);
        *(int *)(arg0 + 0x134) = -1;
    }
    temp_a1 = *(int *)(arg0 + 0x138);
    if (temp_a1 != -1) {
        X_func_001348B0_v1(*(int *)(arg0 + 8), temp_a1);
        *(int *)(arg0 + 0x138) = -1;
    }
    X_func_00187464_v1(arg0 + 0x140);
    *(int *)(arg0 + 0x110) = 0;
    *(int *)(arg0 + 0x114) = -1;
    *(int *)(arg0 + 0x118) = -1;
    *(int *)(arg0 + 0x11C) = -1;
    *(int *)(arg0 + 0x120) = -1;
    X_mnuBase__vfunc_03_v1(arg0);
}

// NON_MATCHING: 20/21 differ, 1 reloc differs (size 0x54, game 0x50), 15 edits
#ifdef NON_MATCHING
extern "C" int func_00196E54(int arg0, int arg1)
{
    int *p;
    int v;

    for (p = &D_0029C0F8; ; p += 0x0C) {
        M2C_FIELD(arg0, int **, 0x110) = p;
        v = *p;
        if (v == -1)
            return 0;
        if (v == arg1)
            break;
    }
    if (*(int *)M2C_FIELD(arg0, int **, 0x110) != -1) {
        M2C_FIELD(arg0, int *, 0x114) = arg1;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196E54);
#endif

extern "C" void func_00196EA4(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 2);
    Xiiiii_func_0019397C(arg0, (int) (int) "ehonbg", 4, 1);
    Xiiiii_func_0019397C(arg0, (int) (int) "ehontex01_tcc", 4, 0);
}

// NON_MATCHING: 23/204 differ, 28 edits
#ifdef NON_MATCHING
extern "C" int X_func_00279C98_init(...) asm("func_00279C98");
extern "C" int Xii_func_00194588_init(int) asm("func_00194588");
extern char D_002F80D0[];
extern char D_002F80E0[];
extern "C" void func_00196EFC(int arg0)
{
    register int self PS2_REG("$16");
    self = arg0;
    struct { char pad0[32]; } stack;
    int var_a2;
    int temp_a0;
    int temp_a0_2;
    int temp_a1;
    int temp_a1_2;
    int temp_a3;
    int temp_a3_2;
    int temp_v0_2;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int var_a0;
    int var_s1;
    register int var_s2 PS2_REG("$18");
    int var_s3;
    int temp_v0;

    temp_a0 = (int) (M2C_FIELD(M2C_FIELD(self, int *, 0x110), int *, 8) + 1) / 2;
    M2C_FIELD(self, int *, 0x130) = temp_a0;
    M2C_FIELD(self, int *, 0x12C) = Xii_func_00194588_init(temp_a0 << 5);
    temp_v1 = M2C_FIELD(self, int *, 0x128);
    if (temp_v1 >= 0) {
        var_s3 = (int) (temp_v1 + ((unsigned int) temp_v1 >> 0x1F)) >> 1;
    } else {
        var_s3 = -1;
    }
    var_a2 = M2C_FIELD(self, int *, 0x12C);
    for (var_s1 = 0; var_s1 <= var_s3; var_s1++, var_a2 += 0x20) {
        M2C_FIELD(var_a2, int *, 0) = 3;
        M2C_FIELD(var_a2, int *, 8) = -1;
        M2C_FIELD(var_a2, int *, 4) = -1;
        M2C_FIELD(var_a2, int *, 0xC) = var_s1 * 2 + 1;
        M2C_FIELD(var_a2, int *, 0x10) = 0;
    }
    for (; var_s1 < M2C_FIELD(self, int *, 0x130); var_s1++, var_a2 += 0x20) {
        M2C_FIELD(var_a2, int *, 0) = 3;
        M2C_FIELD(var_a2, int *, 8) = -1;
        M2C_FIELD(var_a2, int *, 4) = -1;
        M2C_FIELD(var_a2, int *, 0xC) = var_s1 * 2;
        M2C_FIELD(var_a2, int *, 0x10) = 0;
    }
    temp_v0 = M2C_FIELD(self, int *, 0x110);
    M2C_FIELD(self, int *, 0x120) = (int) (M2C_FIELD(temp_v0, int *, 8) - 1);
    temp_v1_2 = M2C_FIELD(temp_v0, int *, 0xC);
    if (temp_v1_2 & 2) {
        if (M2C_FIELD(self, int *, 0x11C) > 0) {
            var_s1 = 0;
            var_a2 = M2C_FIELD(self, int *, 0x12C);
            if (M2C_FIELD(self, int *, 0x130) > 0) {
                do {
                    temp_v0_2 = (var_s1 >= 0) ? (var_s1 * 2) : -1;
                    temp_v1_3 = temp_v0_2 + 1;
                    var_s1 += 1;
                    if (temp_v0_2 >= M2C_FIELD(self, int *, 0x11C)) {
                        (*(int *)(var_a2)) |= 4;
                    }
                    if (temp_v1_3 >= M2C_FIELD(self, int *, 0x11C)) {
                        (*(int *)(var_a2)) |= 8;
                    }
                    var_a2 += 0x20;
                } while (var_s1 < M2C_FIELD(self, int *, 0x130));
            }
            M2C_FIELD(self, int *, 0x120) = M2C_FIELD(self, int *, 0x11C);
        }
    } else if (temp_v1_2 & 1) {
        if (M2C_FIELD(self, int *, 0x11C) == 0) {
            var_a2 = M2C_FIELD(self, int *, 0x12C) + 0xE0;
            M2C_FIELD(var_a2, int *, 0) |= 0x30;
        } else {
            M2C_FIELD(self, int *, 0x120) = M2C_FIELD(self, int *, 0x11C);
        }
    }
    if ((M2C_FIELD(self, int *, 0x128) + 1) >= M2C_FIELD(self, int *, 0x120)) {
        M2C_FIELD(self, int *, 4) = (int) (M2C_FIELD(self, int *, 4) | 0x40000);
    }
    var_s1 = 0;
    Xiiiii_func_0019397C(self, (int) (int) "pb_pagedmy00_tcc\0\0\0\0", 0x14, 0x20);
    Xiiiii_func_0019397C(self, (int) (int) "pb_pagedmy01_tcc\0\0\0\0", 0x14, 0x21);
    if (M2C_FIELD(self, int *, 0x130) > 0) {
        do {
            X_func_00279C98_init((int)&stack, (int) "%s%d_base.i3s", M2C_FIELD(self, int *, 0x110) + 0x10, var_s1);
            Xiiiii_func_0019397C(self, (int)&stack, 0x11, var_s1++);
        } while (var_s1 < M2C_FIELD(self, int *, 0x130));
    }
    var_s1 = 0;
    if (var_s3 >= 0) {
        var_s2 = 1;
        do {
            X_func_00279C98_init((int)&stack, (int) D_002F80D0, M2C_FIELD(self, int *, 0x110) + 0x10, var_s1);
            temp_a3_2 = var_s2;
            var_s2 += 2;
            Xiiiii_func_0019397C(self, (int) (int)&stack, 0x12, temp_a3_2);
            Xiiiii_func_0019844C(self, var_s1++, 0, 1);
        } while (var_s3 >= var_s1);
    }
    for (; var_s1 < M2C_FIELD(self, int *, 0x130); var_s1++) {
        X_func_00279C98_init((int)&stack, (int) D_002F80E0, M2C_FIELD(self, int *, 0x110) + 0x10, var_s1);
        Xiiiii_func_0019397C(self, (int) (int)&stack, 0x12, var_s1 * 2);
        Xiiiii_func_0019844C(self, var_s1, 1, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196EFC);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_0019722C);

extern "C" void func_001973FC(int arg0)
{
    int temp_a1;
    int temp_v0;
    int temp_v0_2;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_4;
    int var_a1;
    int var_s0;
    int var_s0_2;
    int var_s1;
    int temp_s1;
    int temp_v1_3;
    int temp_v1_5;
    int temp_v1_6;

    temp_v1 = M2C_FIELD(arg0, int *, 0x128);
    if (temp_v1 >= 0) {
        var_s1 = (int) (temp_v1 + ((unsigned int) temp_v1 >> 0x1F)) >> 1;
    } else {
        var_s1 = -1;
    }
    for (var_s0 = 0; var_s0 <= var_s1; var_s0++) {
        Xiiiii_func_0019844C(arg0, var_s0, 1, 0);
    }
    for (; var_s0 < M2C_FIELD(arg0, int *, 0x130); var_s0++) {
        Xiiiii_func_0019844C(arg0, var_s0, 0, 1);
    }
    for (var_s0 = 0; var_s0 <= var_s1; var_s0++) {
        int row = (var_s0 << 5) + M2C_FIELD(arg0, int *, 0x9C);
        M2C_FIELD(row, int *, 4) *= 2;
    }
    for (; var_s0 < M2C_FIELD(arg0, int *, 0x130); var_s0++) {
        int row = (var_s0 << 5) + M2C_FIELD(arg0, int *, 0x9C) + 0x10;
        M2C_FIELD(row, int *, 4) *= 2;
    }
    temp_v1_6 = M2C_FIELD(arg0, int *, 0x13C);
    temp_s1 = arg0 + 0x140;
    *(PBookPageLabel *)temp_v1_6 = *(PBookPageLabel *)&D_002F80F0;
    Xii_func_0018741C(temp_s1);
    temp_v0 = Xiiiiii_func_00134730(M2C_FIELD(arg0, int *, 8), 0x200, 0x100, 0, -1);
    M2C_FIELD(arg0, int *, 0x138) = temp_v0;
    Xiiuiii_func_00134A00((int) M2C_FIELD(arg0, int *, 8), (unsigned int) temp_v0, 0, 0x20, 0x7FFF);
    Xiiuiiii_func_00134CD0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x138), 0, 0, 0x200, 0x100);
    Xiiui_func_00135494((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x138), 1);
    Xiiui_func_00135418((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x138), 0);
    Xiiui_func_001351B0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x138), 0);
    Xiiu_func_00135594(M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x138));
    Xiiu_func_001985B0(arg0, (unsigned int) M2C_FIELD(arg0, int *, 0x128));
    Xiiiii_func_001C5168((int) (int)&D_007812C0, (int) 4, 0xDC, 0x198);
    Xiiii_func_001C51E0((int) (int)&D_007812C0, (int) 4, 0);
    Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 0, 0);
    Xii_func_0018741C(temp_s1);
    temp_v0_2 = Xiiiiii_func_00134730(M2C_FIELD(arg0, int *, 8), 0x40, 0x20, 0, -1);
    M2C_FIELD(arg0, int *, 0x134) = temp_v0_2;
    Xiiuiii_func_00134A00((int) M2C_FIELD(arg0, int *, 8), (unsigned int) temp_v0_2, 0xF6, 0x19A, 0x7FFF);
    Xiiuiiii_func_00134CD0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 0, 0, 0x40, 0x20);
    Xiiui_func_00135494((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 1);
    Xiiui_func_00135418((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 0);
    Xiiui_func_001351B0((int) M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134), 1);
    Xiiu_func_00135594(M2C_FIELD(arg0, int *, 8), (unsigned int) M2C_FIELD(arg0, int *, 0x134));
    int texture = Xiu_func_001832E8(0x1AU);
    Xiiiii_func_001874F4(temp_s1, M2C_FIELD(arg0, int *, 0x134), texture, 0);
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80D0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80E0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80F0);

// NON_MATCHING: 1/239 differ, 1 edits
#ifdef NON_MATCHING
# define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int PBookStateFormat(...) asm("func_00279C98");
extern "C" int Xii_func_00131550(int) asm("func_00131550");
extern "C" int Xii_func_00192F3C(int) asm("func_00192F3C");
extern "C" int Xii_func_00193A1C(int) asm("func_00193A1C");
extern "C" int Xii_func_00196EFC(int) asm("func_00196EFC");
extern "C" int Xii_func_0019722C(int) asm("func_0019722C");
extern "C" int Xii_func_001973FC(int) asm("func_001973FC");
extern "C" int Xii_func_00197D28(int) asm("func_00197D28");
extern "C" int Xii_func_001D44E4(int) asm("func_001D44E4");
extern "C" int Xiii_func_00197A74(int, int) asm("func_00197A74");
extern "C" int Xiiiii_func_00131184(int, int, int, int) asm("func_00131184");
extern "C" int Xiiiii_func_001311BC(int, int, int, int) asm("func_001311BC");
extern "C" int Xiiiii_func_001D83D0(int, int, int, int) asm("func_001D83D0");
extern int D_007A4440;
struct m2c_v10C_18_i { char pad[268]; virtual void v1(); virtual void v2(); virtual int call(); };
struct PBookStateVTable50 { char pad[268]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual int call(); };
struct m2c_v10C_58_i { char pad[268]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual int call(); };
static inline bool PBookStateReady(int object) { return Xii_func_00131550(object) >= 5; }
extern int D_007812C0, D_007B2580;
static inline int PBookStateObject1(int game) { return M2C_FIELD(game, int *, 0xDC1C); }
static inline int PBookStateObject2(int game) { return M2C_FIELD(game, int *, 0xDC20); }
static inline void PBookStateSetPage(int object, int value) { M2C_FIELD(object, int *, 0x194) = value; }
static inline void PBookStateClear(int address, int mask) { *(int *)address &= ~mask; }
static inline void PBookStateSet(int address, int mask) { *(int *)address |= mask; }
static inline void PBookStateBitClear(int array, unsigned int bit) { ((unsigned int *)array)[bit >> 5] &= ~(1U << (bit & 31)); }
extern "C" int MnuPBook__vfunc_05(int arg0, int arg1)
{
    int temp_a1;
    int temp_a0;
    int temp_v1_2;
    int var_s2;
    int var_v0;
    unsigned int temp_v0_3;
    unsigned int temp_v1;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_4;

    var_s2 = 0;
    Xii_func_00193A1C(arg0);
    Xii_func_00197D28(arg0);
    temp_v1 = M2C_FIELD(arg0, unsigned int *, 0x14);
    M2C_FIELD(arg0, unsigned int *, 0x10) = temp_v1;
    switch (temp_v1) {
    case 0:
        if (!(M2C_FIELD(arg0, int *, 4) & 0x20000) && (PBookStateReady(M2C_FIELD(arg0, int *, 8)))) {
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x20000);
        }
        temp_v1_2 = M2C_FIELD(arg0, int *, 4);
        if (!(temp_v1_2 & 0x10000) && (M2C_FIELD(arg0, int *, 0x20) == 0)) {
            M2C_FIELD(arg0, int *, 4) = (int) (temp_v1_2 | 0x10000);
            ((m2c_v10C_58_i *)(arg0))->call();
            PBookStateFormat(arg0 + 0x24, (int) "data/mnurpk/mnupbook/%s.rpk", M2C_FIELD(arg0, int *, 0x110) + 0x10);
            ((PBookStateVTable50 *)(arg0))->call();
            Xii_func_00196EFC(arg0);
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x20000);
        }
        if ((M2C_FIELD(arg0, int *, 4) & 0x30000) == 0x30000) {
            M2C_FIELD(arg0, unsigned int *, 0x14) = 1U;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, int *, 0x20) == 0) {
            Xii_func_0019722C(arg0);
            Xiiiii_func_00131184((int) M2C_FIELD(arg0, int *, 8), 0xF, 7, 0);
            int flags = M2C_FIELD(arg0, int *, 4);
            M2C_FIELD(arg0, unsigned int *, 0x14) = 2U;
            M2C_FIELD(arg0, int *, 4) = flags & 0xFFFCFFFF;
        }
        break;
    case 2:
        if (!(M2C_FIELD(arg0, int *, 4) & 0x20000)) {
            if (PBookStateReady(M2C_FIELD(arg0, int *, 8))) {
                M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x20000);
            }
        }
        if (!(M2C_FIELD(arg0, int *, 4) & 0x10000) && (M2C_FIELD(arg0, int *, 0x20) == 0)) {
            Xii_func_001973FC(arg0);
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x10000);
        }
        temp_a0 = M2C_FIELD(arg0, int *, 4);
        if ((temp_a0 & 0x30000) == 0x30000) {
            M2C_FIELD(arg0, unsigned int *, 0x14) = 3U;
            M2C_FIELD(arg0, int *, 4) = (int) (temp_a0 & ~2);
        }
        break;
    case 3:
        if (Xiii_func_00197A74(arg0, arg1) == 0) {
            Xiiiii_func_001311BC((int) M2C_FIELD(arg0, int *, 8), 0xF, 7, 0);
            Xiii_func_0017F8FC((int) (int)&D_007B2580, 2);
            Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 0, 0);
            Xiiui_func_001351B0((int) M2C_FIELD(arg0, int *, 8), M2C_FIELD(arg0, unsigned int *, 0x134), 1);
            M2C_FIELD(arg0, unsigned int *, 0x14) = 4U;
        }
        break;
    case 4:
        if (PBookStateReady(M2C_FIELD(arg0, int *, 8))) {
            M2C_FIELD(arg0, unsigned int *, 0x14) = 5U;
        }
        break;
    case 5: {
        M2C_FIELD(PBookStateObject1((int)&D_007A4440), int *, 0x44) = Xiiiii_func_001D83D0((int) (int)&D_007812C0, 1, M2C_FIELD(arg0, int *, 0x114), 2);
        int page = M2C_FIELD(arg0, int *, 0x118);
        PBookStateSetPage(PBookStateObject1((int)&D_007A4440), page);
        PBookStateClear(PBookStateObject2((int)&D_007A4440) + 4, 0x04000000);
        if (Xii_func_001D44E4((int)&D_007812C0) != 0) {
            PBookStateSet(PBookStateObject2((int)&D_007A4440) + 4, 0x02000000);
        }
        temp_v0_3 = Xiiiii_func_001D83D0((int) (int)&D_007812C0, 1, M2C_FIELD(arg0, int *, 0x114), 6);
        PBookStateBitClear(PBookStateObject2((int)&D_007A4440), temp_v0_3);
        var_s2 = 1;
        Xii_func_00192F3C(arg0);
        ((m2c_v10C_18_i *)(arg0))->call();
        break;
    }
    }
    return var_s2;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_05);
#endif

extern "C" int func_00197A74(int arg0, int arg1)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v1;
    int temp_v1_3;
    int var_a1;
    int var_a1_2;
    unsigned int temp_v1_2;

    if (M2C_FIELD(arg0, int *, 4) & 0x40000) {
        Xiiiii_func_001C5094((int) (int)&D_007812C0, (int) 4, 1, 0);
        Xiiui_func_001351B0(M2C_FIELD(arg0, int *, 8), M2C_FIELD(arg0, unsigned int *, 0x134), 0);
    }
    temp_v0 = M2C_FIELD(arg0, int *, 0x124);
    if (temp_v0 > 0) {
        temp_v0--;
        M2C_FIELD(arg0, int *, 0x124) = temp_v0;
        if (temp_v0 == 0) {
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) & 0xFFE7FFFD);
            Xiiu_func_001985B0(arg0, M2C_FIELD(arg0, unsigned int *, 0x128));
            if ((M2C_FIELD(arg0, int *, 0x128) + 1) >= M2C_FIELD(arg0, int *, 0x120)) {
                M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 0x40000);
            }
        }
    }
    Xii_func_001874AC(arg0 + 0x140);
    temp_v1 = M2C_FIELD(arg0, int *, 4);
    if (!(temp_v1 & 2)) {
        if (PBookButton(M2C_FIELD(arg1, unsigned short *, 0x7A), 13) && (temp_v1 & 0x40000)) {
            Xiiui_func_001351B0(M2C_FIELD(arg0, int *, 8), M2C_FIELD(arg0, unsigned int *, 0x138), 1);
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 2);
            return 0;
        }
        if (M2C_FIELD(arg0, int *, 0x124) == 0) {
            if ((((M2C_FIELD(arg1, unsigned short *, 0x78) >> 5) & 1 & 0xFFFF) || Xfi_getLeftX__C6BedPad(arg1) >= 0.75f) && Xiii_func_00198318(arg0, 1)) {
                temp_v1_3 = M2C_FIELD(arg0, unsigned int *, 0x128) + 2;
                M2C_FIELD(arg0, unsigned int *, 0x128) = temp_v1_3;
                if (temp_v1_3 >= 0) {
                    var_a1_2 = temp_v1_3 / 2;
                } else {
                    var_a1_2 = -1;
                }
                Xiiii_func_00197F18(arg0, var_a1_2, 1);
                M2C_FIELD(arg0, int *, 4) |= 0x100002;
                Xiii_func_0017F8FC((int)&D_007B2580, 8);
                Xiiu_func_001985B0(arg0, -0x63U);
            } else if ((((M2C_FIELD(arg1, unsigned short *, 0x78) >> 7) & 1 & 0xFFFF) || Xfi_getLeftX__C6BedPad(arg1) <= -0.75f) && Xiii_func_00198318(arg0, 0)) {
                temp_v1_2 = M2C_FIELD(arg0, unsigned int *, 0x128);
                if ((int)temp_v1_2 >= 0) {
                    var_a1 = (int)temp_v1_2 / 2;
                } else {
                    var_a1 = -1;
                }
                Xiiii_func_00197F18(arg0, var_a1, 0);
                M2C_FIELD(arg0, unsigned int *, 0x128) -= 2;
                M2C_FIELD(arg0, int *, 4) |= 0x80002;
                Xiii_func_0017F8FC((int)&D_007B2580, 8);
                Xiiu_func_001985B0(arg0, -0x63U);
            }
        }
        if (!(M2C_FIELD(arg0, int *, 4) & 2)) {
            goto done;
        }
    }
block_30:
    M2C_FIELD(arg0, unsigned int *, 0x8B8) = (unsigned int) ((unsigned int) (M2C_FIELD(arg0, unsigned int *, 0x8B8) + 1) % 300U);
done:
    return 1;
}

extern "C" void func_00197D28(int arg0)
{
    register int self PS2_REG("$17");
    register int p PS2_REG("$16");
    register int i PS2_REG("$18");
    int temp_v0;

    self = arg0;
    temp_v0 = M2C_FIELD(self, int *, 0x130);
    if (temp_v0 != 0) {
        p = M2C_FIELD(self, int *, 0x12C);
        i = 0;
        if (temp_v0 > 0) {
            do {
                if (M2C_FIELD(p, int *, 0x10) < M2C_FIELD(M2C_FIELD(self, int *, 0x9C) + (M2C_FIELD(p, int *, 0xC) << 4), int *, 4)) {
                    M2C_FIELD(p, int *, 0x10)++;
                }
                i += 1;
                p += 0x20;
            } while (i < M2C_FIELD(self, int *, 0x130));
        }
        i = 0;
        p = M2C_FIELD(self, int *, 0x12C);
        if (M2C_FIELD(self, int *, 0x130) > 0) {
            do {
                if (M2C_FIELD(p, int *, 0) & 1) {
                    if (M2C_FIELD(p, int *, 4) != -1) {
                        if (Xiii_func_001943D8(self, M2C_FIELD(p, int *, 4)) != 0) {
                            Xiiiii_func_00197E68(self, i, M2C_FIELD(p, int *, 4), 0);
                            M2C_FIELD(p, int *, 0) = M2C_FIELD(p, int *, 0) & ~1;
                        }
                    }
                }
                if (M2C_FIELD(p, int *, 0) & 2) {
                    if (M2C_FIELD(p, int *, 8) != -1) {
                        if (Xiii_func_001943D8(self, M2C_FIELD(p, int *, 8)) != 0) {
                            Xiiiii_func_00197E68(self, i, M2C_FIELD(p, int *, 8), 1);
                            M2C_FIELD(p, int *, 0) = M2C_FIELD(p, int *, 0) & ~2;
                        }
                    }
                }
                i += 1;
                p += 0x20;
            } while (i < M2C_FIELD(self, int *, 0x130));
        }
    }
}

extern "C" void func_00197E68(int arg0, int arg1, int arg2, int arg3)
{
    PBookHdr **p = Xp_func_0022AED8((*(PBookElem20 **)((char *)arg0 + 0x94))[arg1].unk00 + 0x10, arg3 != 0);
    PBookItem *item = *Xp_func_0022AAD0(p, 0);
    PBookElem10 *base = (PBookElem10 *)M2C_FIELD(arg0, int *, 0xA4);
    if (arg2 == -1) {
        item->unk1C = (arg3 ? (base + 0x21) : (base + 0x20))->unk08;
    } else {
        item->unk1C = (base + arg2)->unk08;
    }
    (*p)->unk08++;
}

extern "C" void func_00197F18(int arg0, int arg1, int arg2)
{
    int t;
    int v;
    int base;

    base = M2C_FIELD(arg0, int *, 0x12C) + arg1 * 0x20;
    v = arg1 * 2;
    t = v;
    if (arg2 != 0)
        t = v + 1;
    M2C_FIELD(base, int *, 0x10) = 0;
    M2C_FIELD(base, int *, 0xC) = t;
    Xiiii_func_00193FEC(arg0, arg1, t);
    M2C_FIELD(arg0, int *, 0x124) = 0xA;
}

// NON_MATCHING: 19/200 differ, 1 reloc differs, 11 edits
#ifdef NON_MATCHING
extern "C" int X_func_0021B550(...) asm("func_0021B550");
extern "C" int X_func_00237340(...) asm("func_00237340");
extern "C" int X_func_002378B0(...) asm("func_002378B0");
extern "C" int Xiii_func_00192F68(int, int) asm("func_00192F68");
extern "C" int Xiii_func_001930F8(int, int) asm("func_001930F8");
extern "C" int Xiii_func_00193210(int, int) asm("func_00193210");
extern "C" int Xiiiff_func_00193258(int, float, float, int) asm("func_00193258");
extern "C" int Xiiiiiii_func_0019368C(int, int, int, int, int, int) asm("func_0019368C");
extern int D_002F8140;
struct PBookV6Pair { long long a, b; };
extern "C" void MnuPBook__vfunc_06(int arg0, int arg1)
{
    struct { float sp0; float sp4; float sp8; float spC; float sp10; float sp14; float sp18; float sp1C; float sp20; float sp24; float sp28; float sp2C; float sp30; char pad34[12]; PBookV6Pair vec; int sp50; char pad54[44]; float sp80; float sp84; float sp88; } stack;
    register float zero PS2_REG("$f12");
    register float bgHeight PS2_REG("$f2");
    register float uvBottom PS2_REG("$f1");
    register float white PS2_REG("$f0");
    float temp_f0;
    float temp_f0_2;
    int temp_a3;
    int temp_a4;
    int temp_a5;
    int var_s0;
    int var_s1;

    if ((unsigned int) (M2C_FIELD(arg0, int *, 0x10) - 2) < 3U) {
        Xiii_func_00192F68(arg0, arg1);
        Xiii_func_00193210(arg0, 1);
        stack.sp0 = 0.0f;
        stack.sp8 = 512.0f;
        bgHeight = 448.0f;
        uvBottom = 0.875f;
        stack.spC = bgHeight;
        stack.sp1C = uvBottom;
        white = 1.0f;
        stack.sp20 = white;
        zero = stack.sp0;
        stack.sp4 = zero;
        stack.sp30 = zero;
        stack.sp10 = zero;
        stack.sp14 = zero;
        stack.sp18 = white;
        stack.sp2C = white;
        stack.sp28 = white;
        stack.sp24 = white;
        Xiiiff_func_00193258(arg0, zero, zero, (int)&stack);
        Xiii_func_00193210(arg0, 0);
        if ((M2C_FIELD(arg0, int *, 0x128) - 1) >= 0) {
            if (M2C_FIELD(arg0, int *, 4) & 0x80000) {
                var_s0 = (unsigned int) ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x8B8) >> 1) % 3U;
            } else {
                var_s0 = 0;
            }
            stack.spC = 16.0f;
            temp_f0 = ((float) var_s0 * 16.0f) + 48.0f;
            stack.sp8 = 28.0f;
            stack.sp18 = 0.21875f;
            stack.sp10 = 0.0f;
            stack.sp14 = temp_f0 * 0.0078125f;
            stack.sp1C = (temp_f0 + 16.0f) * 0.0078125f;
            Xiiiff_func_00193258(arg0, 100.0f, 412.0f, (int)&stack);
        }
        if ((M2C_FIELD(arg0, int *, 0x128) + 2) < M2C_FIELD(M2C_FIELD(arg0, int *, 0x110), int *, 8)) {
            if (M2C_FIELD(arg0, int *, 4) & 0x100000) {
                var_s0 = (unsigned int) ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x8B8) >> 1) % 3U;
            } else {
                var_s0 = 0;
            }
            stack.sp10 = 0.0f;
            stack.spC = 16.0f;
            temp_f0_2 = ((float) var_s0 * 16.0f) + stack.sp10;
            stack.sp8 = 28.0f;
            stack.sp18 = 0.21875f;
            stack.sp14 = temp_f0_2 * 0.0078125f;
            stack.sp1C = (temp_f0_2 + 16.0f) * 0.0078125f;
            Xiiiff_func_00193258(arg0, 384.0f, 412.0f, (int)&stack);
        }
        var_s0 = 0;
        M2C_FIELD(arg0, int *, 0xB0) = X_func_0021B550(M2C_FIELD(arg0, int *, 0xB0), 0x47, 0x503FD);
        Xiii_func_001930F8(arg0, arg1);
        stack.vec = *(PBookV6Pair *)&D_002F8140;
        X_func_00237340((int)&stack.sp50);
        X_func_002378B0((int)&stack.sp50, (int)&stack.sp50, (int)&stack.vec);
        stack.sp80 = 25.0f;
        stack.sp84 = 8.0f;
        stack.sp88 = 220.0f;
        var_s1 = M2C_FIELD(arg0, int *, 0x12C);
        if (M2C_FIELD(arg0, int *, 0x130) > 0) {
            do {
                temp_a4 = M2C_FIELD(var_s1, int *, 0xC);
                temp_a3 = var_s0;
                temp_a5 = M2C_FIELD(var_s1, int *, 0x10);
                var_s1 += 0x20;
                var_s0 += 1;
                Xiiiiiii_func_0019368C(arg0, arg1, (int)&stack.sp50, temp_a3, temp_a4, temp_a5);
            } while (var_s0 < M2C_FIELD(arg0, int *, 0x130));
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_06);
#endif

// NON_MATCHING: 11/34 differ, 6 edits
#ifdef NON_MATCHING
extern "C" int X_func_00223228(int, int) asm("func_00223228");
extern "C" int X_func_00223558(int, int) asm("func_00223558");
extern "C" void MnuPBook__vfunc_07(int arg0, int arg1)
{
    int arr[16];
    int q[6];
    int p1;
    int p2;
    int v;

    p1 = M2C_FIELD(arg0, int *, 0xA4);
    arr[0] = M2C_FIELD(p1, int *, 8);
    M2C_FIELD(p1, int *, 0xC) = 0;
    p2 = M2C_FIELD(arg0, int *, 0xA4);
    arr[1] = M2C_FIELD(p2, int *, 0x18);
    M2C_FIELD(p2, int *, 0x1C) = 1;
    q[2] = 2;
    q[0] = 0;
    q[1] = (int)arr;
    q[3] = 0;
    q[4] = 0;
    q[5] = 0;
    v = X_func_00223558(arg1, (int)q);
    M2C_FIELD(arg0, int *, 0xAC) = v;
    X_func_00223228(arg1, v);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_07);
#endif

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F8140);
