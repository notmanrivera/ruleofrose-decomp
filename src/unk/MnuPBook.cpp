#include "include_asm.h"
#include "unk/mnuBase.h"
#include "bed/bedpfh.h"
#include "bed/bedpad.h"

// still used by func_00193A1C and func_00194148 (their typed versions do not match yet)
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
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
struct MnuTexCtx {
    int m_unk00;
    int m_unk04;
    int m_unk08;
};
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

extern "C" void func_0019397C(MnuBase *arg0, char *arg1, int arg2, int arg3)
{
    MnuResSlot *p;
    int i;
    int count;

    count = arg0->m_resUsed;
    if (count == arg0->m_resNum) {
        return;
    }
    p = arg0->m_resSlots;
    for (i = 0; i < count; i++) {
        if ((p->m_type & 0xF) == (arg2 & 0xF)) {
            if (p->m_slotIdx == arg3) {
                return;
            }
        }
        p++;
    }
    X_strcpy_pv(p->m_name, arg1);
    p->m_type = arg2;
    p->m_slotIdx = arg3;
    arg0->m_resUsed = arg0->m_resUsed + 1;
}

extern "C" int X_func_0022B518(...) asm("func_0022B518");
extern "C" float Xfi_func_0022E958(int) asm("func_0022E958");
extern "C" int Xii_clear__6BedPfh(int) asm("clear__6BedPfh");
extern "C" int Xii_func_00194588(int) asm("func_00194588");
extern "C" int Xiii_func_00193E20_queue(MnuBase *, int) asm("func_00193E20");
extern "C" int Xiii_func_001BE564(void *, int) asm("func_001BE564");
extern "C" int Xiii_getIndex__C6BedPfhPCc(int, int) asm("getIndex__C6BedPfhPCc");
extern "C" int Xiii_setTop__6BedPfhPv(int, int) asm("setTop__6BedPfhPv");
extern "C" int Xiiii_func_001BE524__10FileReaderP11FileReadReqi(void *, void *, int) asm("func_001BE524__10FileReaderP11FileReadReqi");
extern "C" int Xiiii_memmove_queue(void *, void *, int) asm("memmove");
extern "C" int Xiiiiii_loadTM2__10DogTexInfoPCcPvii(int, const char *, int, int, int) asm("loadTM2__10DogTexInfoPCcPvii");
extern "C" char *Xpi_func_00194588(int) asm("func_00194588");
#ifdef NON_MATCHING
extern "C" void func_00193A1C(int arg0)
{
    int first, second;
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
        if (Xiii_func_001BE564((void *)(arg0 + 0x68), 1) == 0) {
            if (M2C_FIELD(arg0, int *, 4) & 8) {
                Xiii_func_00193E20_queue((MnuBase *)arg0, 0);
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
                    first = (int)temp_v0_2 + temp_s0;
                    second = first + temp_s1;
                    M2C_FIELD(temp_s2, int *, 4) = (int)temp_v0_2;
                    M2C_FIELD(temp_s2, int *, 8) = first;
                    M2C_FIELD(temp_s2, int *, 0xC) = second;
                    M2C_FIELD(temp_s2, int *, 0x10) = (int) (second + temp_s1);
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
                    M2C_FIELD(temp_s0_2, int *, 8) = Xiiiiii_loadTM2__10DogTexInfoPCcPvii((int) M2C_FIELD(arg0, int *, 0xC), (const char *)(temp_s4 + 0x10), M2C_FIELD(temp_s4, int *, 0), 0, -1);
                    M2C_FIELD(temp_s0_2, int *, 0) = (int) M2C_FIELD(temp_s4, int *, 0);
                    M2C_FIELD(temp_s0_2, int *, 4) = (int) M2C_FIELD(temp_s4, int *, 4);
                    break;
                }
            }
            M2C_FIELD(temp_s4, int *, 0) = 0;
            Xiii_func_00193E20_queue((MnuBase *)arg0, 0);
            temp_a0_4 = M2C_FIELD(arg0, int *, 0x18);
            Xiiii_memmove_queue((void *)temp_a0_4, (void *)(temp_a0_4 + 0x30), (M2C_FIELD(arg0, int *, 0x20) * 0x30) - 0x30);
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
                Xiiii_func_001BE524__10FileReaderP11FileReadReqi((void *) temp_a0_5, (void *) temp_a1, 0);
                M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 4);
                goto loop_1;
            }
            Xiiii_func_001BE524__10FileReaderP11FileReadReqi((void *) temp_a0_5, (void *) temp_a1, 1);
            M2C_FIELD(arg0, int *, 4) = (int) (M2C_FIELD(arg0, int *, 4) | 4);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193A1C);
#endif

extern "C" int Xiii_func_00193E20(MnuBase *, int) asm("func_00193E20");
extern "C" int Xiiii_memmove(void *, void *, int) asm("memmove");
extern "C" void func_00193D1C(MnuBase *arg0, int arg1, int arg2)
{
    register MnuResSlot *p PS2_REG("$3");
    register int count PS2_REG("$4");
    int i;

    count = arg0->m_resUsed;
    if (count <= 0) {
        return;
    }
    p = arg0->m_resSlots;
    arg1 &= 0xF;
    i = 1;
    if ((p->m_type & 0xF) == arg1) {
        if (p->m_slotIdx == arg2) {
            arg0->m_flags |= 8;
            return;
        }
    }
    goto test;
    do {
        if ((p->m_type & 0xF) == arg1) {
            if (p->m_slotIdx == arg2) {
                Xiii_func_00193E20(arg0, i);
                p = &arg0->m_resSlots[i];
                Xiiii_memmove(p, p + 1, (arg0->m_resUsed - i) * 0x30 - 0x30);
                arg0->m_resUsed = arg0->m_resUsed - 1;
                return;
            }
        }
        i++;
    test:
        bool more = i < count;
        p++;
        if (!more) break;
    } while (true);
}

extern "C" void func_00193DFC(MnuBase *arg0)
{
    if (arg0->m_resUsed > 0) {
        arg0->m_resUsed = 1;
        arg0->m_flags = arg0->m_flags | 8;
    }
}


extern "C" void func_00193E20(MnuBase *arg0, int arg1)
{
    MnuResSlot *temp_s0;
    int temp_v0;

    temp_s0 = &arg0->m_resSlots[arg1];
    temp_v0 = temp_s0->m_unk00;
    if (temp_v0 != 0) {
        Xii_func_00194688(temp_v0);
        temp_s0->m_unk00 = 0;
    }
    temp_s0->m_unk04 = 0;
    temp_s0->m_name[0] = 0;
    temp_s0->m_type = 0;
    temp_s0->m_slotIdx = -1;
}

extern "C" int func_00193E7C(MnuBase *arg0, int arg1, int *arg2)
{
    if (arg0->m_readBuf == 0) {
        return 0;
    }
    if (arg0->m_flags & 4) {
        return 0;
    }

    BedPfh pfh;
    pfh.setTop(arg0->m_readBuf);
    int idx = pfh.getIndex((const char *)arg1);
    int size = pfh.getFileSize(idx);
    int result = X_func_00194588(size);
    arg0->m_reqSeekWhence = 0;
    arg0->m_reqSeekOff = pfh.getFileOffset(idx);
    arg0->m_reqSize = size;
    arg0->m_reqBuf = (void *)result;
    Xiii_func_001BE524__10FileReaderP11FileReadReqi((int)arg0->m_fileReader, (int)arg0->m_fileReq, 0);
    if (arg2 != 0) {
        *arg2 = size;
    }
    return result;
}

extern "C" void func_00193F74(int arg0, int arg1)
{
    if (arg1 != 0) {
        X_func_00194688(arg1);
    }
}


extern "C" void func_00193F98(MnuBase *arg0, int arg1)
{
    MnuModelSlot *temp_s0;
    char *temp_v0;

    temp_s0 = (MnuModelSlot *)((arg1 << 5) + (int)arg0->m_models);
    temp_v0 = temp_s0->m_data;
    if (temp_v0 != 0) {
        Xiii_func_00193F74((int)arg0, (int)temp_v0);
        Xii_func_00194688(temp_s0->m_unk04);
        Xiiii_memset((int)temp_s0, 0, 0x20);
    }
}

extern "C" void func_00193FEC(MnuBase *arg0, int arg1, int arg2)
{
    register int temp_a1 PS2_REG("$5");
    register int temp_a2 PS2_REG("$6");
    MnuAnimSlot *temp_s3;
    MnuModelSlot *temp_s1;
    int temp_v0;
    int temp_a0;
    int var_s2;

    var_s2 = 0;
    temp_a1 = arg1 << 5;
    temp_a2 = arg2 << 4;
    temp_s3 = (MnuAnimSlot *)((char *)arg0->m_animSlots + temp_a2);
    temp_s1 = (MnuModelSlot *)((char *)arg0->m_models + temp_a1);
    temp_v0 = X_func_0022B6F8(temp_s3->m_unk00, temp_a1, temp_a2);
    *(short *)temp_s1->m_unk10 = temp_v0;
    if (temp_v0 > 0) {
        do {
            short *out;
            temp_a0 = X_func_0022B3D8(temp_s1->m_data,
                                      X_func_0022B730(temp_s3->m_unk00, var_s2 & 0xFFFF));
            out = (short *)(var_s2 * 2 + temp_s1->m_unk10 + 2);
            var_s2++;
            if (temp_a0 >= 0) {
                out[0] = temp_a0;
            } else {
                out[0] = -1;
            }
        } while (var_s2 < temp_v0);
    }
}

extern "C" int func_001940A4(MnuBase *arg0, int arg1, int arg2)
{
    MnuResSlot *p;
    int i;
    int cap;
    int limit;

    cap = arg0->m_unk98;
    limit = arg2 + 1;
    if (cap < limit) {
        limit = cap;
    }
    for (; arg1 < limit; arg1++) {
        if (arg0->m_models[arg1].m_data != 0) {
            continue;
        }
        i = 0;
        p = arg0->m_resSlots;
        for (; i < arg0->m_resUsed; i++) {
            if ((p->m_type & 0xF) == 1) {
                if (p->m_slotIdx == arg1) {
                    break;
                }
            }
            p++;
        }
        if (i == arg0->m_resUsed) {
            return arg1;
        }
    }
    return -1;
}

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

extern "C" void func_00194280(MnuBase *arg0, int arg1)
{
    MnuAnimSlot *temp_s0;
    int temp_v0;

    temp_s0 = (MnuAnimSlot *)((arg1 * 0x10) + (int)arg0->m_animSlots);
    temp_v0 = temp_s0->m_unk00;
    if (temp_v0 != 0) {
        Xiii_func_00193F74((int)arg0, temp_v0);
        Xiiii_memset((int)temp_s0, 0, 0x10);
    }
}

extern "C" int func_001942CC(MnuBase *arg0, int arg1, int arg2)
{
    MnuResSlot *p;
    int i;
    int cap;
    int limit;

    cap = arg0->m_unkA0;
    limit = arg2 + 1;
    if (cap < limit) {
        limit = cap;
    }
    for (; arg1 < limit; arg1++) {
        if (arg0->m_animSlots[arg1].m_unk00 != 0) {
            continue;
        }
        i = 0;
        p = arg0->m_resSlots;
        for (; i < arg0->m_resUsed; i++) {
            if ((p->m_type & 0xF) == 2) {
                if (p->m_slotIdx == arg1) {
                    break;
                }
            }
            p++;
        }
        if (i == arg0->m_resUsed) {
            return arg1;
        }
    }
    return -1;
}

extern "C" void func_00194370(MnuBase *arg0, int arg1)
{
    MnuTexSlot *temp_s0;

    if (X_func_001943D8() != 0) {
        temp_s0 = &arg0->m_texSlots[arg1];
        X_releaseTex__10DogTexInfoi(arg0->m_unk0C, temp_s0->m_texId);
        X_func_00193F74(arg0, temp_s0->m_unk00);
        temp_s0->m_unk00 = 0;
        temp_s0->m_unk04 = 0;
        temp_s0->m_texId = -1;
    }
}


extern "C" int func_001943D8(MnuBase *arg0, int arg1)
{
    int var_a0;
    MnuTexSlot *temp_v1;

    temp_v1 = &arg0->m_texSlots[arg1];
    var_a0 = 0;
    if (temp_v1->m_unk00 != 0) {
        var_a0 = ~temp_v1->m_texId != 0;
    }
    return var_a0;
}


extern "C" int func_00194404(MnuBase *arg0, int arg1, int arg2)
{
    register MnuBase *self PS2_REG("$17");
    register int limit PS2_REG("$18");
    register int i PS2_REG("$5");
    register int count PS2_REG("$6");
    MnuResSlot *p;
    int idx;

    idx = arg1;
    self = arg0;
    limit = arg2 + 1;
    if (self->m_texSlotNum < limit) {
        limit = self->m_texSlotNum;
    }
    while (idx < limit) {
        if (Xiii_func_001943D8((int)self, idx) == 0) {
            count = self->m_resUsed;
            i = 0;
            p = self->m_resSlots;
            while (i < count) {
                if ((p->m_type & 0xF) == 4) {
                    if (p->m_slotIdx == idx) {
                        break;
                    }
                }
                i++;
                p++;
            }
            if (i == self->m_resUsed) {
                return idx;
            }
        }
        idx++;
    }
    return -1;
}

struct PBookHeapEnt {
    char *top;
    unsigned int size;
    int flags;
    int unk;
};

extern "C" void func_001944D0()
{
    int temp_v0;

    temp_v0 = X_alloc__9BedMemoryii((int)&D_006E9800, 0x100800, -1);
    D_0029BFB4 = temp_v0;
    X_memset(temp_v0, 0, 0x100800);
    ((PBookHeapEnt *)D_0029BFB4)->top = (char *)(D_0029BFB4 + 0x800);
    ((PBookHeapEnt *)D_0029BFB4)->size = 0x100000;
    ((PBookHeapEnt *)D_0029BFB4)->flags = 1;
}


extern "C" void func_00194548()
{
    if (D_0029BFB4 != 0) {
        X_free__9BedMemoryPv((int)&D_006E9800, D_0029BFB4);
        D_0029BFB4 = 0;
    }
}

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
extern "C" void func_00194688(char *arg0)
{
    int i;
    int v;
    PBookHeapEnt *p;

    i = 0;
    p = (PBookHeapEnt *)D_0029BFB4;
    v = *(volatile int *)&p->flags;
    while ((v & 3) != 3 || p->top != arg0) {
        i += 1;
        if (i >= 0x80)
            return;
        p++;
        v = p->flags;
    }
    p->flags = v & -3;
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

extern "C" void func_001947A4(MnuMap *arg0)
{
    register MnuMap *self PS2_REG("$16") = arg0;
    register char *p PS2_REG("$17") = (char *)self->m_msgWin;
    int i = 1;
    Xii_func_00192AC0_ctor((int)self);
    *(int **)((char *)self + 0x10C) = &vtbl_MnuMap_ctor;
    do {
        Xii_func_0018330C_ctor((int)p);
        p += 0x3BC;
        i -= 1;
    } while (i != -1);
    self->m_type = 4;
    __builtin_memcpy(((PBookMnuMapName *)self)->m_name, "data/mnurpk/mnumap.rpk", 0x17);
    asm volatile("" ::: "memory");
    self->m_unk144 = i;
    self->m_unk148 = i;
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

extern "C" void MnuMap__vfunc_02(MnuMap *arg0, int arg1)
{
    X_func_00192BA4((int)arg0, arg1, 0x1B, 0, 0, 0x1A);
    arg0->m_state = 0;
    arg0->vfunc10();
    X_func_001949BC((int)arg0);
}

extern "C" void MnuMap__vfunc_03(MnuMap *arg0)
{
    int temp_v0;

    temp_v0 = arg0->m_unk144;
    if (temp_v0 != -1) {
        X_func_001348B0(arg0->m_scene, temp_v0);
        arg0->m_unk144 = -1;
    }
    X_func_00193868(arg0);
    X_func_00187464(arg0->m_msgWin);
    X_mnuBase__vfunc_03(arg0);
}


// NON_MATCHING: 296/383 differ, 33 relocs differ (size 0x5FC, game 0x5E8), 163 edits
#ifdef NON_MATCHING
struct MapAreaInfo {
    int m_unk00[4];
    int m_name;
    int m_unk14;
    int m_hasFloor;
    int m_unk1C;
    float m_offX;
    float m_offY;
    float m_offZ;
};
struct MapObjEnt {
    int m_unk00;
    int m_kind;
    int m_pad[6];
};
struct MapVec4 {
    union {
        u_long128 q;
        struct {
            float x;
            float y;
            float z;
            float w;
        };
    };
};
extern "C" int MapInitArea(int) asm("func_001C6C28");
extern "C" MapAreaInfo *MapInitInfo(int, int) asm("func_0017EA44");
extern "C" int MapInitRoom(int) asm("func_001C6C38");
extern "C" int MapInitFloor(int) asm("func_001DBD90");
extern "C" int MapInitObjects(int, int, void *) asm("func_001DBDF0");
extern "C" void MapInitConvert(MnuMap *, void *) asm("func_00196878");
extern "C" void MapInitSize(MnuMap *, void *) asm("func_001959EC");
extern "C" void MapInitClamp(MnuMap *, void *) asm("func_0019586C");
extern "C" int MapInitAlloc(int, int, int, int, int) asm("func_00134730");
extern "C" int MapInitText(int, int, int) asm("func_0013555C");
extern "C" void MapInitHeight(int, unsigned int, int *) asm("func_00134E18");
extern "C" void MapInitDraw(int, int, int, int, int, int) asm("func_00135234__8MagSceneiiiii");
extern "C" void MapInitUpdate(MnuMap *) asm("func_00195A34");
extern MnuMapEntry MapInitEntries[] asm("D_0029BFB8");
struct MapInitMessage { char text[14]; };
static inline void MapInitPlayer(int game, u_long128 *dst) { *dst = *(u_long128 *)((char *)game + 0x22020); }
static inline void MapInitTarget(int game, u_long128 *dst) { *dst = *(u_long128 *)((char *)game + 0x22040); }
static inline void MapInitRotation(int game, u_long128 *dst) { *dst = *(u_long128 *)((char *)game + 0x22030); }
static inline int MapInitEmpty(int scene, int x, int y, int mode, int res, MapInitMessage *text, int *height) { *text = *(MapInitMessage *)"N O     M A P"; *height = 0; return MapInitAlloc(scene, x, y, mode, res); }
extern "C" void func_001949BC(MnuMap *self)
{
    struct { MapObjEnt list[0x80]; MapVec4 vector; int height; } stack;
    int game = (int)&D_007812C0;
    int mapObj = PBookMapObject(game);
    MapAreaInfo *info = MapInitInfo((int)&D_00298EE0, MapInitArea(game));
    self->m_unk124 = self->m_unk128 = 0.0f;
    int one = 1;
    self->m_unk12C = one;
    self->m_unk130 = one;
    self->m_flags |= 2;
    self->m_unk134 = -1;
    self->m_unk138 = 0;
    self->m_unk13C = 0;
    self->m_unk140 = 0;
    int room = MapInitRoom(game);
    int floor = MapInitFloor(mapObj);
    self->m_unk8C8 = MapInitEntries;
    int selected = info->m_hasFloor != 0 ? floor : 0;
    if (MapInitEntries[0].m_room != -1) {
        if (MapInitEntries[0].m_room != room || MapInitEntries[0].m_floor != selected) {
scan_next:
            self->m_unk8C8++;
            MnuMapEntry *current = self->m_unk8C8;
            int id = current->m_room;
            if (id != -1) {
                if (id != room) goto scan_next;
                if (current->m_floor != selected) goto scan_next;
            }
        }
    }
    self->m_unk110 = self->m_unk8C8;
    if (self->m_unk8C8->m_room == -1) {
        self->m_flags |= 0x01000000;
    }
    MnuMapEntry *entry = self->m_unk110;
    self->m_unk118 = 0x200;
    self->m_unk114 = entry->m_tileCount << 7;
    int count = MapInitObjects(mapObj, entry->m_floor, stack.list);
    self->m_unk8DC = self->m_unk8CC = self->m_unk8D0 = self->m_unk8D8 = -100000.0f;
    if (!(self->m_flags & 0x01000000)) {
        MapObjEnt *object = stack.list;
        for (int i = 0; i < count; ++i, ++object) {
                int kind = object->m_kind;
                if (kind == 1) {
                    MapInitPlayer((int)&D_007812C0, &stack.vector.q);
                    MapInitConvert(self, &stack.vector);
                    self->m_unk8CC = stack.vector.x;
                    self->m_unk8D0 = stack.vector.z;
                } else if (kind == 2) {
                    MapInitTarget((int)&D_007812C0, &stack.vector.q);
                    MapInitConvert(self, &stack.vector);
                    self->m_unk8D8 = stack.vector.x;
                    self->m_unk8DC = stack.vector.z;
                }
        }
        MapInitRotation((int)&D_007812C0, &stack.vector.q);
        float angle = stack.vector.y + 3.1415923f;
        self->m_unk8D4 = angle;
        if (angle < -3.1415923f) {
            do { angle += 6.2831845f; } while (angle < -3.1415923f);
            self->m_unk8D4 = angle;
        }
        angle = self->m_unk8D4;
        if (angle >= 3.1415923f) {
            float next;
            do { next = angle - 6.2831845f; angle = next; } while (next >= 3.1415923f);
            self->m_unk8D4 = next;
        }
    }
    float *position = &self->m_unk11C;
    MapInitSize(self, position);
    *position = self->m_unk8CC - *position * 0.5f;
    self->m_unk120 = self->m_unk8D0 - self->m_unk120 * 0.5f;
    MapInitClamp(self, position);
    if (!(self->m_flags & 0x01000000)) {
        stack.height = 0;
        int handle = MapInitAlloc(self->m_scene, 0x100, 0x20, 0, -1);
        self->m_unk144 = handle;
        int width = MapInitText(self->m_scene, handle, info->m_name);
        MapInitHeight(self->m_scene, (unsigned int)self->m_unk144, &stack.height);
        Xiiuiii_func_00134A00(self->m_scene, (unsigned int)self->m_unk144, (0x200 - width) / 2, 0x188 - stack.height, 0x7FFF);
        Xiiuii_func_00134AB8(self->m_scene, (unsigned int)self->m_unk144, 0x100, 0x20);
        Xiiuiiii_func_00134CD0(self->m_scene, (unsigned int)self->m_unk144, 0, 0, 0x100, 0x20);
        Xiiui_func_00135494(self->m_scene, (unsigned int)self->m_unk144, 1);
        Xiiui_func_00135418(self->m_scene, (unsigned int)self->m_unk144, 0);
        Xiiu_func_00135594(self->m_scene, (unsigned int)self->m_unk144);
        Xiiui_func_001351B0(self->m_scene, (unsigned int)self->m_unk144, 1);
        MapInitDraw(self->m_scene, self->m_unk144, 0, 0, info->m_name, 0);
        if (self->m_flags & 0x01000000) goto no_map;
    } else {
no_map:
        int handle = MapInitEmpty(self->m_scene, 0x100, 0x20, 0, -1, (MapInitMessage *)stack.list, &stack.height);
        self->m_unk144 = handle;
        int width = MapInitText(self->m_scene, handle, (int)stack.list);
        MapInitHeight(self->m_scene, (unsigned int)self->m_unk144, &stack.height);
        Xiiuiii_func_00134A00(self->m_scene, (unsigned int)self->m_unk144, (0x200 - width) / 2, 0xF0 - stack.height / 2, 0x7FFF);
        Xiiuii_func_00134AB8(self->m_scene, (unsigned int)self->m_unk144, 0x100, 0x20);
        Xiiuiiii_func_00134CD0(self->m_scene, (unsigned int)self->m_unk144, 0, 0, 0x100, 0x20);
        Xiiui_func_00135494(self->m_scene, (unsigned int)self->m_unk144, 1);
        Xiiui_func_00135418(self->m_scene, (unsigned int)self->m_unk144, 0);
        Xiiu_func_00135594(self->m_scene, (unsigned int)self->m_unk144);
        Xiiui_func_001351B0(self->m_scene, (unsigned int)self->m_unk144, 1);
        MapInitDraw(self->m_scene, self->m_unk144, 0, 0, (int)stack.list, 0);
    }
    Xiiiii_func_0019397C((int)self, (int)"map01_tcc.tm2", 4, 0);
    Xiiiii_func_0019397C((int)self, (int)"map_bg_tcc.tm2", 4, 1);
    MapInitUpdate(self);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001949BC);
#endif

extern "C" void func_00194FA4(MnuMap *arg0) throw()
{
    Xiiff_func_00192E94((int)arg0, 256.0f, 1.57079616189003f);
    Xii_func_0019381C((int)arg0);
}

extern "C" int Map05_Xii_func_00131550(int) asm("func_00131550");
extern "C" int Map05_Xii_func_0018741C(void *) asm("func_0018741C");
extern "C" int Map05_Xii_func_00192F3C(MnuMap *) asm("func_00192F3C");
extern "C" int Map05_Xii_func_00193A1C(MnuMap *) asm("func_00193A1C");
extern "C" int Map05_Xii_func_00193DFC(MnuMap *) asm("func_00193DFC");
extern "C" int Map05_Xii_func_00194FA4(MnuMap *) throw() asm("func_00194FA4");
extern "C" int Map05_Xii_func_00195A34(MnuMap *) asm("func_00195A34");
extern "C" int Map05_Xii_func_00196760(MnuMap *) asm("func_00196760");
extern "C" int Map05_Xiii_func_0017F8FC(int, int) asm("func_0017F8FC");
extern "C" int Map05_Xiii_func_00194370(MnuMap *, int) asm("func_00194370");
extern "C" int Map05_Xiii_func_001943D8(MnuMap *, int) asm("func_001943D8");
extern "C" int Map05_Xiii_func_00195430(MnuMap *, int) asm("func_00195430");
extern "C" int Map05_Xiii_func_0019586C(MnuMap *, float *) asm("func_0019586C");
extern "C" int Map05_Xiii_func_00195B78(MnuMap *, int) asm("func_00195B78");
extern "C" int Map05_Xiiiii_func_00131184(int, int, int, int) asm("func_00131184");
extern "C" int Map05_Xiiiii_func_001311BC(int, int, int, int) asm("func_001311BC");
extern "C" int Map05_Xiiui_func_001351B0(int, unsigned int, int) asm("func_001351B0");
static inline bool Map05Ready(int object) { return Map05_Xii_func_00131550(object) >= 5; }
extern "C" int MnuMap__vfunc_05(MnuMap *arg0, int arg1)
{
    float baseX;
    float baseY;
    int temp_a0;
    register int temp_v0 PS2_REG("$2");
    register int temp_v1 PS2_REG("$3");
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_6;
    int temp_v1_7;
    int var_a0;
    int var_s1;
    int var_s2;
    unsigned int temp_v1_2;
    unsigned int temp_v1_5;
    unsigned int var_v0_2;
    int transitionDir;
    MnuMapEntry *var_v0_3;

    temp_v1 = arg0->m_unk12C;
    temp_a0 = arg0->m_unk130;
    var_s2 = 0;
    if (temp_v1 < temp_a0) {
        temp_v0 = temp_v1 + 1;
        asm("" : "+r"(temp_v0));
        arg0->m_unk12C = temp_v0;
        if (temp_v0 == temp_a0) {
            arg0->m_flags = arg0->m_flags & 0xFFF9FFFD;
        }
    }
    temp_v1_2 = (unsigned int)arg0->m_unk134;
    if (temp_v1_2 < 0x12U) {
        arg0->m_unk134 = (int)(temp_v1_2 + 1);
    }
    temp_v1_3 = arg0->m_unk13C;
    if (temp_v1_3 != 0) {
        var_a0 = 0xF;
        temp_v1_4 = arg0->m_unk138 + temp_v1_3;
        arg0->m_unk138 = temp_v1_4;
        if (temp_v1_4 < 0x10) {
            var_a0 = (temp_v1_4 < 0) ? 0 : temp_v1_4;
        }
        arg0->m_unk138 = var_a0;
        if ((unsigned int)(var_a0 - 1) >= 0xEU) {
            arg0->m_unk13C = 0;
        }
    }
    Map05_Xii_func_00193A1C(arg0);
    temp_v1_5 = (unsigned int)arg0->m_state;
    arg0->m_unk10 = (int)temp_v1_5;
    switch (temp_v1_5) {
    case 0:
        if (Map05Ready(arg0->m_scene)) {
            arg0->m_state = 1;
        }
        break;
    case 1:
        if (Map05_Xiii_func_001943D8(arg0, 1) != 0) {
            if (Map05_Xiii_func_001943D8(arg0, 0) != 0) {
                Map05_Xii_func_00194FA4(arg0);
                Map05_Xiiiii_func_00131184(arg0->m_scene, 0xF, 7, 0);
                arg0->m_unk134 = 0;
                Map05_Xiii_func_0017F8FC((int)&D_007B2580, 5);
                arg0->m_state = 2;
                break;
            }
        } else {
            break;
        }
        break;
    case 2:
        if (Map05Ready(arg0->m_scene)) {
            if (arg0->m_unk134 >= 0x12) {
                if (arg0->m_resUsed == 0) {
                    transitionDir = 1;
                    var_v0_2 = 3;
                    goto block_48;
                }
                break;
            }
        }
        break;
    case 3:
        if (arg0->m_unk13C == 0) {
            Map05_Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk144, 0);
            Map05_Xii_func_0018741C(arg0->m_msgWin);
            Map05_Xiii_func_00195B78(arg0, 1);
            int flags = arg0->m_flags & ~2;
            arg0->m_state = 4;
            arg0->m_flags = flags;
        }
        break;
    case 4:
        if (Map05_Xiii_func_00195430(arg0, arg1) == 0) {
            Map05_Xiiiii_func_001311BC(arg0->m_scene, 0xF, 7, 0);
            Map05_Xiii_func_0017F8FC((int)&D_007B2580, 2);
            Map05_Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk144, 1);
            Map05_Xiii_func_00195B78(arg0, 0);
            arg0->m_state = 5;
        }
        break;
    case 5:
        if (Map05Ready(arg0->m_scene)) {
            arg0->m_state = 0xA;
        }
        break;
    case 6:
        Map05_Xii_func_00193DFC(arg0);
        Map05_Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk144, 1);
        arg0->m_unk13C = -1;
        arg0->m_state = 7;
        break;
    case 7:
        if (arg0->m_unk138 == 0) {
            if (arg0->m_resUsed == 0) {
                temp_v1_6 = arg0->m_flags;
                if (temp_v1_6 & 0x200000) {
                    baseX = arg0->m_unk8CC;
                    baseY = arg0->m_unk8D0;
                    register float *position PS2_REG("$5") = &arg0->m_unk11C;
                    if (!(temp_v1_6 & 0x10000)) {
                        *position = baseX - 384.0f;
                        arg0->m_unk120 = baseY - 256.0f;
                    } else {
                        *position = baseX - 192.0f;
                        arg0->m_unk120 = baseY - 128.0f;
                    }
                    Map05_Xiii_func_0019586C(arg0, position);
                } else {
                    var_s1 = 0;
                    if (arg0->m_unk110->m_tileCount > 0) {
                        do {
                            Map05_Xiii_func_00194370(arg0, var_s1 + 2);
                            var_s1 += 1;
                        } while (var_s1 < arg0->m_unk110->m_tileCount);
                    }
                    temp_v1_7 = arg0->m_flags;
                    if (temp_v1_7 & 0x80000) {
                        var_v0_3 = arg0->m_unk110 + 1;
                    } else if (temp_v1_7 & 0x100000) {
                        var_v0_3 = arg0->m_unk110 - 1;
                    } else {
                        goto page_unchanged;
                    }
                    arg0->m_unk110 = var_v0_3;
page_unchanged:;
                }
                Map05_Xii_func_00195A34(arg0);
                arg0->m_state = 8;
                break;
            }
        }
        break;
    case 8:
        if (arg0->m_resUsed == 0) {
            transitionDir = 1;
            var_v0_2 = 9;
block_48:
            arg0->m_unk13C = transitionDir;
            arg0->m_state = (int)var_v0_2;
        }
        break;
    case 9:
        if (arg0->m_unk138 == 0xF) {
            arg0->m_flags = arg0->m_flags & 0xFFC7FFFD;
            if (Map05_Xii_func_00196760(arg0) != 0) {
                Map05_Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk144, 0);
            }
            arg0->m_state = 4;
            break;
        }
        break;
    case 10:
        var_s2 = 1;
        Map05_Xii_func_00192F3C(arg0);
        arg0->vfunc03();
        break;
    }
    return var_s2;
}

// NON_MATCHING: 204/261 differ, 14 relocs differ (size 0x414, game 0x43C), 110 edits
#ifdef NON_MATCHING
extern "C" float Xfi_getLeftY__C6BedPad(int) asm("getLeftY__C6BedPad");
extern "C" int Xii_func_00195A34(MnuMap *) asm("func_00195A34");
extern "C" int Xii_func_00196760(MnuMap *) asm("func_00196760");
extern "C" int Xiii_func_0019586C(MnuMap *, void *) asm("func_0019586C");
extern MnuMapEntry D_0029BFB8[];
extern "C" void PBookMoveSoundC(int, int) asm("func_0017F8FC");
static inline void PBookMoveSound(int sound, int code) { PBookMoveSoundC(sound, code); }
extern "C" int func_00195430(MnuMap *arg0, BedPad *arg1)
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
    MnuMapEntry *temp_a0;
    MnuMapEntry *temp_v0;

    Xii_func_001874AC((int)arg0->m_msgWin);
    temp_a1 = arg0->m_flags;
    if (!(temp_a1 & 2)) {
        temp_v1 = arg1->m_trigger;
        if (PBookButton(temp_v1, 13) || PBookButton(temp_v1, 0)) {
            arg0->m_flags = temp_a1 | 2;
            return 0;
        }
        if (PBookButton(temp_v1, 11)) {
            temp_v0 = arg0->m_unk110;
            if (temp_v0[0].m_room != temp_v0[1].m_room || (temp_a1 & 0x01000000)) goto fail;
            var_v0 = 0x80002;
            goto turn;
        }
        if (PBookButton(temp_v1, 10)) {
            temp_a0 = arg0->m_unk110;
            if ((unsigned int)D_0029BFB8 >= (unsigned int)temp_a0 || temp_a0[0].m_room != temp_a0[-1].m_room || (temp_a1 & 0x01000000)) goto fail;
            var_v0 = 0x100002;
turn:
        arg0->m_state = 6;
        arg0->m_flags = temp_a1 | var_v0;
        PBookMoveSound((int)&D_007B2580, 4);
        goto update;
        } else {
            if ((temp_v1 >> 15) != 0) {
                if (temp_a1 & 0x01000000) goto fail;
                temp_f2 = arg0->m_unk11C;
                temp_f3 = arg0->m_unk120;
                temp_v0_2 = (temp_a1 | 0x20002) ^ 0x10000;
                arg0->m_unk130 = 0x12;
                arg0->m_unk12C = 0;
                arg0->m_flags = temp_v0_2;
                arg0->m_unk124 = temp_f2;
                arg0->m_unk128 = temp_f3;
                if (!(temp_v0_2 & 0x10000)) {
                    var_f0 = -192.0f;
                    var_f1 = -128.0f;
                } else {
                    var_f0 = 192.0f;
                    var_f1 = 128.0f;
                }
                arg0->m_unk11C = temp_f2 + var_f0;
                arg0->m_unk120 = temp_f3 + var_f1;
                Xiii_func_0019586C(arg0, &arg0->m_unk11C);
                goto confirm;
            } else if (PBookButton(temp_v1, 12)) {
                if (!Xii_func_00196760(arg0)) goto fail;
                temp_a0_2 = arg0->m_flags;
                if (temp_a0_2 & 0x01000000) goto fail;
                arg0->m_state = 6;
                arg0->m_flags = temp_a0_2 | 0x200002;
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
                stack.sp0 = Xfi_getLeftX__C6BedPad((int)arg1) * 16.0f;
                temp_f0 = Xfi_getLeftY__C6BedPad((int)arg1) * 16.0f;
                stack.sp4 = temp_f0;
                if ((stack.sp0 == 0.0f) && (temp_f0 == 0.0f)) {
                    temp_a0_3 = arg1->m_press;
                    temp_v0_3 = temp_a0_3 & 0xFFFF;
                    var_v0_2 = PBookButton(temp_v0_3, 5);
                    if (PBookButton(temp_v0_3, 7)) {
                        var_v0_2 -= 1;
                    }
                    temp_v1_2 = temp_a0_3 & 0xFFFF;
                    stack.sp0 = (float)var_v0_2 * 16.0f;
                    temp_v1_3 = PBookButton(temp_v1_2, 6);
                    if (PBookButton(temp_v1_2, 4)) {
                        var_f1_2 = 16.0f;
                        var_f0_2 = (float)(temp_v1_3 - 1);
                    } else {
                        var_f1_2 = (float)temp_v1_3;
                        var_f0_2 = 16.0f;
                    }
                    stack.sp4 = var_f1_2 * var_f0_2;
                }
                stack.sp0 += arg0->m_unk11C;
                stack.sp4 += arg0->m_unk120;
                Xiii_func_0019586C(arg0, &stack);
                temp_f2_2 = stack.sp0 - arg0->m_unk11C;
                if (temp_f2_2 >= 0.5f) {
                    arg0->m_unk11C = stack.sp0;
                    var_s2 = 0;
                    arg0->m_flags = arg0->m_flags | 0x400000;
                } else if (temp_f2_2 <= -0.5f) {
                    arg0->m_unk11C = stack.sp0;
                    var_s2 = 0;
                    arg0->m_flags = arg0->m_flags & 0xFFBFFFFF;
                }
                temp_f2_3 = stack.sp4 - arg0->m_unk120;
                if (temp_f2_3 >= 0.5f) {
                    arg0->m_unk120 = stack.sp4;
                    var_s2 = 0;
                    arg0->m_flags = arg0->m_flags | 0x800000;
                } else if (temp_f2_3 <= -0.5f) {
                    arg0->m_unk120 = stack.sp4;
                    var_s2 = 0;
                    arg0->m_flags = arg0->m_flags & 0xFF7FFFFF;
                }
                if (var_s2 == 0) {
                    arg0->m_unk140 = (arg0->m_unk140 + 1) % 12;
                } else {
                    arg0->m_unk140 = 0;
                }
    }
update:
    Xii_func_00195A34(arg0);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195430);
#endif

extern "C" void func_0019586C(MnuMap *arg0, float *arg1)
{
    float sp[2];
    float target;
    float ratio;
    float d;

    Xiii_func_001959EC((int)arg0, (int)sp);

    target = (float)arg0->m_unk114;
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

    target = (float)arg0->m_unk118;
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

extern "C" int func_00195958(MnuMap *arg0, float fparg0, float fparg1)
{
    float sp[2];
    int var_v0;

    Xiii_func_001959EC((int)arg0, (int)sp);
    var_v0 = 0;
    if (!(fparg0 < 0.0f) && !(((float)arg0->m_unk114 - sp[0]) < fparg0) && !(fparg1 < 0.0f) && !(((float)arg0->m_unk118 - sp[1]) < fparg1)) {
        var_v0 = 1;
    }
    return var_v0;
}

extern "C" void func_001959EC(MnuMap *arg0, float *arg1)
{
    float var_f0;
    float var_f1;

    if (!(arg0->m_flags & 0x10000)) {
        var_f1 = 768.0f;
        var_f0 = 512.0f;
    } else {
        var_f1 = 384.0f;
        var_f0 = 256.0f;
    }
    arg1[1] = var_f0;
    arg1[0] = var_f1;
}

// NON_MATCHING: 24/81 differ, 4 relocs differ, 9 edits
#ifdef NON_MATCHING
extern "C" float func_00196790(MnuMap *arg0);
extern "C" int X_func_00279C98(...) asm("func_00279C98");
extern "C" int func_00195A34(MnuMap *arg0)
{
    float t;
    float v;
    int count;
    int limit;
    int i;
    char sp[0x20];

    t = func_00196790(arg0);
    v = arg0->m_unk124 + (arg0->m_unk11C - arg0->m_unk124) * t;
    count = (int)v / 0x80;
    limit = count - 3;
    i = 0;
    while (i < limit) {
        func_00194370(arg0, i + 2);
        i++;
    }
    limit = count + 6;
    i = count + 9;
    while (i < arg0->m_unk110->m_tileCount) {
        func_00194370(arg0, i + 2);
        i++;
    }
    i = 0;
    if (count > 0) {
        i = count - 2;
    }
    while (i < limit + 2 && i < arg0->m_unk110->m_tileCount) {
        if (Xiii_func_001943D8((int)arg0, i + 2) == 0) {
            X_func_00279C98(sp, "%s_%02d.tm2\0\0\0\0", arg0->m_unk110->m_texPrefix, i + 1);
            Xiiiii_func_0019397C((int)arg0, (int)sp, 4, i + 2);
        }
        i++;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195A34);
#endif

extern "C" void func_00195B78(MnuMap *arg0, int arg1)
{
    int temp_a1;
    int temp_s0;

    if (arg1 != 0) {
        Xiiiii_func_001C5168((int)&D_007812C0, 7, 0x10, 0x198);
        Xiiii_func_001C51E0((int)&D_007812C0, 7, 0);
        Xiiiii_func_001C5094((int)&D_007812C0, 7, 1, 0);
        Xiiiii_func_001C5168((int)&D_007812C0, 6, 0x88, 0x198);
        Xiiii_func_001C51E0((int)&D_007812C0, 6, 0);
        Xiiiii_func_001C5094((int)&D_007812C0, 6, 1, 0);
        Xiiiii_func_001C5168((int)&D_007812C0, 0xC, 0xFC, 0x198);
        Xiiii_func_001C51E0((int)&D_007812C0, 0xC, 0);
        Xiiiii_func_001C5094((int)&D_007812C0, 0xC, 1, 0);
        Xiiiii_func_001C5168((int)&D_007812C0, 0xA, 0x118, 0x198);
        Xiiii_func_001C51E0((int)&D_007812C0, 0xA, 0);
        Xiiiii_func_001C5094((int)&D_007812C0, 0xA, 1, 0);
        Xiiiii_func_001C5168((int)&D_007812C0, 9, 0x184, 0x198);
        Xiiii_func_001C51E0((int)&D_007812C0, 9, 0);
        Xiiiii_func_001C5094((int)&D_007812C0, 9, 1, 0);
        Xiiiii_func_001C5168((int)&D_007812C0, 4, 0x1A8, 0x198);
        Xiiii_func_001C51E0((int)&D_007812C0, 4, 0);
        Xiiiii_func_001C5094((int)&D_007812C0, 4, 1, 0);
        if (arg0->m_unk148 == -1) {
            arg0->m_unk148 = Xiiiiii_func_00134730(arg0->m_scene, 0x200, 0x20, 0, -1);
        }
        int ctrl = (int)arg0->m_msgWin;
        Xiiuiii_func_00134A00(arg0->m_scene, (unsigned int)arg0->m_unk148, 0, 0x19A, 0x7FFF);
        Xiiuii_func_00134AB8(arg0->m_scene, (unsigned int)arg0->m_unk148, 0x200, 0x20);
        Xiiuiiii_func_00134CD0(arg0->m_scene, (unsigned int)arg0->m_unk148, 0, 0, 0x200, 0x20);
        Xiiui_func_00135494(arg0->m_scene, (unsigned int)arg0->m_unk148, 1);
        Xiiui_func_00135418(arg0->m_scene, (unsigned int)arg0->m_unk148, 0);
        Xiiu_func_00135594(arg0->m_scene, (unsigned int)arg0->m_unk148);
        Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk148, 0);
        temp_s0 = arg0->m_unk148;
        int texture = Xiu_func_001832E8(0x18U);
        return Xiiiii_func_001874F4(ctrl, temp_s0, texture, 0);
    }
    Xiiiii_func_001C5094((int)&D_007812C0, 7, 0, 0);
    Xiiiii_func_001C5094((int)&D_007812C0, 6, 0, 0);
    Xiiiii_func_001C5094((int)&D_007812C0, 0xC, 0, 0);
    Xiiiii_func_001C5094((int)&D_007812C0, 0xA, 0, 0);
    Xiiiii_func_001C5094((int)&D_007812C0, 9, 0, 0);
    Xiiiii_func_001C5094((int)&D_007812C0, 4, 0, 0);
    Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk148, 1);
    temp_a1 = arg0->m_unk148;
    if (temp_a1 != -1) {
        Xiiu_func_001348B0(arg0->m_scene, (unsigned int)temp_a1);
        arg0->m_unk148 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuMap__vfunc_06);

extern "C" int func_00196760(MnuMap *arg0)
{
    int var_a2;
    MnuMapEntry *temp_a0;
    MnuMapEntry *temp_a1;

    temp_a0 = arg0->m_unk8C8;
    temp_a1 = arg0->m_unk110;
    var_a2 = 0;
    if (temp_a0->m_room == temp_a1->m_room) {
        var_a2 = temp_a0->m_floor == temp_a1->m_floor;
    }
    return var_a2;
}

extern "C" float func_00196790(MnuMap *arg0)
{
    return (-Xff_cosf(((((float)arg0->m_unk12C * 180.0f) / (float)arg0->m_unk130) * 3.141592562198639f) / 180.0f) * 0.5f) + 0.5f;
}

extern "C" float func_00196804(MnuMap *arg0)
{
    return (-Xff_cosf(((((float)arg0->m_unk12C * 180.0f) / (float)arg0->m_unk130) * 3.141592562198639f) / 180.0f) * 0.5f) + 0.5f;
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F7DC0);

struct PBookRoomOff {
    int m_pad[8];
    float m_offX;
    float m_offY;
    float m_offZ;
};

extern "C" void func_00196878(int arg0, float *arg1)
{
    PBookMapTable table = D_002F7DC0;
    int mapObj = PBookMapObject((int)&D_007812C0);
    int map = Xii_func_001C6C38((int)&D_007812C0);
    int mode = Xii_func_001DBD90(mapObj);
    int id = Xii_func_001C6C28((int)&D_007812C0);
    PBookRoomOff *obj = (PBookRoomOff *)Xiii_func_0017EA44((int)&D_00298EE0, id);
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
        arg1[0] = row->v[2] * -(arg1[0] + obj->m_offX) / row->v[0] + row->v[4];
        arg1[2] = row->v[3] * (arg1[2] + obj->m_offZ) / row->v[1] + row->v[5];
    }
}

struct PBookMsg6A9C {
    unsigned char m_data[0x3BC];
    PBookMsg6A9C() asm("func_0018330C");
};
inline void *operator new(unsigned int, void *p) { return p; }
MnuPBook::MnuPBook()
{
    int i = 1;
    register PBookMsg6A9C *p PS2_REG("$18") = (PBookMsg6A9C *)m_msgWin;
    do { new (p) PBookMsg6A9C; p++; } while (--i != -1);
    m_unk134 = i;
    m_msgId = i;
    m_unk114 = i;
    m_unk118 = i;
    m_unk11C = -1;
    m_unk120 = i;
    m_type = 7;
    m_textBuf = 0;
    m_info = 0;
    m_pages = 0;
}

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

extern "C" void MnuPBook__vfunc_03(MnuPBook *arg0)
{
    char *temp_v0;
    MnuBookPage *temp_a0;
    int temp_v0_2;
    int temp_a1;

    temp_v0 = arg0->m_textBuf;
    if (temp_v0 != 0) {
        X_func_00194688_v1((int)temp_v0);
        arg0->m_textBuf = 0;
    }
    temp_a0 = arg0->m_pages;
    if (temp_a0 != 0) {
        X_func_00194688_v1((int)temp_a0);
        arg0->m_pages = 0;
    }
    arg0->m_pageNum = 0;
    X_func_00193868_v1((int)arg0);
    temp_v0_2 = arg0->m_unk134;
    if (temp_v0_2 != -1) {
        X_func_001348B0_v1(arg0->m_scene, temp_v0_2);
        arg0->m_unk134 = -1;
    }
    temp_a1 = arg0->m_msgId;
    if (temp_a1 != -1) {
        X_func_001348B0_v1(arg0->m_scene, temp_a1);
        arg0->m_msgId = -1;
    }
    X_func_00187464_v1((int)arg0->m_msgWin);
    arg0->m_info = 0;
    arg0->m_unk114 = -1;
    arg0->m_unk118 = -1;
    arg0->m_unk11C = -1;
    arg0->m_unk120 = -1;
    X_mnuBase__vfunc_03_v1((int)arg0);
}

extern "C" int func_00196E54(MnuPBook *arg0, int arg1)
{
    for (arg0->m_info = (MnuPBookInfo *)&D_0029C0F8; arg0->m_info->m_unk00 != -1; arg0->m_info++) {
        if (arg0->m_info->m_unk00 == arg1) {
            break;
        }
    }
    if (arg0->m_info->m_unk00 == -1) {
        return 0;
    }
    arg0->m_unk114 = arg1;
    return 1;
}

extern "C" void func_00196EA4(MnuPBook *arg0)
{
    arg0->m_flags = arg0->m_flags | 2;
    Xiiiii_func_0019397C((int)arg0, (int)"ehonbg", 4, 1);
    Xiiiii_func_0019397C((int)arg0, (int)"ehontex01_tcc", 4, 0);
}

// NON_MATCHING: 23/204 differ, 28 edits
#ifdef NON_MATCHING
extern "C" int X_func_00279C98_init(...) asm("func_00279C98");
extern "C" MnuBookPage *Xii_func_00194588_init(int) asm("func_00194588");
extern char D_002F80D0[];
extern char D_002F80E0[];
extern "C" void func_00196EFC(MnuPBook *arg0)
{
    register MnuPBook *self PS2_REG("$16");
    self = arg0;
    struct { char pad0[32]; } stack;
    MnuBookPage *var_a2;
    int temp_a0;
    int temp_a3_2;
    int temp_v0_2;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int var_s1;
    register int var_s2 PS2_REG("$18");
    int var_s3;
    MnuPBookInfo *temp_v0;

    temp_a0 = (self->m_info->m_pageCount + 1) / 2;
    self->m_pageNum = temp_a0;
    self->m_pages = Xii_func_00194588_init(temp_a0 << 5);
    temp_v1 = self->m_curPage;
    if (temp_v1 >= 0) {
        var_s3 = (int)(temp_v1 + ((unsigned int)temp_v1 >> 0x1F)) >> 1;
    } else {
        var_s3 = -1;
    }
    var_a2 = self->m_pages;
    for (var_s1 = 0; var_s1 <= var_s3; var_s1++, var_a2++) {
        var_a2->m_flags = 3;
        var_a2->m_rightTex = -1;
        var_a2->m_leftTex = -1;
        var_a2->m_animIdx = var_s1 * 2 + 1;
        var_a2->m_frame = 0;
    }
    for (; var_s1 < self->m_pageNum; var_s1++, var_a2++) {
        var_a2->m_flags = 3;
        var_a2->m_rightTex = -1;
        var_a2->m_leftTex = -1;
        var_a2->m_animIdx = var_s1 * 2;
        var_a2->m_frame = 0;
    }
    temp_v0 = self->m_info;
    self->m_unk120 = temp_v0->m_pageCount - 1;
    temp_v1_2 = temp_v0->m_flags0C;
    if (temp_v1_2 & 2) {
        if (self->m_unk11C > 0) {
            var_s1 = 0;
            var_a2 = self->m_pages;
            if (self->m_pageNum > 0) {
                do {
                    temp_v0_2 = (var_s1 >= 0) ? (var_s1 * 2) : -1;
                    temp_v1_3 = temp_v0_2 + 1;
                    if (temp_v0_2 >= self->m_unk11C) {
                        var_a2->m_flags |= 4;
                    }
                    if (temp_v1_3 >= self->m_unk11C) {
                        var_a2->m_flags |= 8;
                    }
                    var_s1 += 1;
                    var_a2++;
                } while (var_s1 < self->m_pageNum);
            }
            self->m_unk120 = self->m_unk11C;
        }
    } else if (temp_v1_2 & 1) {
        if (self->m_unk11C == 0) {
            var_a2 = &self->m_pages[7];
            var_a2->m_flags |= 0x30;
        } else {
            self->m_unk120 = self->m_unk11C;
        }
    }
    if ((self->m_curPage + 1) >= self->m_unk120) {
        self->m_flags = self->m_flags | 0x40000;
    }
    var_s1 = 0;
    Xiiiii_func_0019397C((int)self, (int)"pb_pagedmy00_tcc\0\0\0\0", 0x14, 0x20);
    Xiiiii_func_0019397C((int)self, (int)"pb_pagedmy01_tcc\0\0\0\0", 0x14, 0x21);
    if (self->m_pageNum > 0) {
        do {
            X_func_00279C98_init((int)&stack, (int)"%s%d_base.i3s", self->m_info->m_prefix, var_s1);
            Xiiiii_func_0019397C((int)self, (int)&stack, 0x11, var_s1++);
        } while (var_s1 < self->m_pageNum);
    }
    var_s1 = 0;
    if (var_s3 >= 0) {
        var_s2 = 1;
        do {
            X_func_00279C98_init((int)&stack, (int)D_002F80D0, self->m_info->m_prefix, var_s1);
            temp_a3_2 = var_s2;
            var_s2 += 2;
            Xiiiii_func_0019397C((int)self, (int)&stack, 0x12, temp_a3_2);
            Xiiiii_func_0019844C((int)self, var_s1++, 0, 1);
        } while (var_s3 >= var_s1);
    }
    for (; var_s1 < self->m_pageNum; var_s1++) {
        X_func_00279C98_init((int)&stack, (int)D_002F80E0, self->m_info->m_prefix, var_s1);
        Xiiiii_func_0019397C((int)self, (int)&stack, 0x12, var_s1 * 2);
        Xiiiii_func_0019844C((int)self, var_s1, 1, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196EFC);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_0019722C);

extern "C" void func_001973FC(MnuPBook *arg0)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v1;
    int var_s0;
    int var_s1;
    int temp_s1;
    char *temp_v1_6;

    temp_v1 = arg0->m_curPage;
    if (temp_v1 >= 0) {
        var_s1 = (int)(temp_v1 + ((unsigned int)temp_v1 >> 0x1F)) >> 1;
    } else {
        var_s1 = -1;
    }
    for (var_s0 = 0; var_s0 <= var_s1; var_s0++) {
        Xiiiii_func_0019844C((int)arg0, var_s0, 1, 0);
    }
    for (; var_s0 < arg0->m_pageNum; var_s0++) {
        Xiiiii_func_0019844C((int)arg0, var_s0, 0, 1);
    }
    for (var_s0 = 0; var_s0 <= var_s1; var_s0++) {
        MnuAnimSlot *row = (MnuAnimSlot *)((var_s0 << 5) + (int)arg0->m_animSlots);
        row->m_len *= 2;
    }
    for (; var_s0 < arg0->m_pageNum; var_s0++) {
        MnuAnimSlot *row = (MnuAnimSlot *)((var_s0 << 5) + (int)arg0->m_animSlots + 0x10);
        row->m_len *= 2;
    }
    temp_v1_6 = arg0->m_textBuf;
    temp_s1 = (int)arg0->m_msgWin;
    *(PBookPageLabel *)temp_v1_6 = *(PBookPageLabel *)&D_002F80F0;
    Xii_func_0018741C(temp_s1);
    temp_v0 = Xiiiiii_func_00134730(arg0->m_scene, 0x200, 0x100, 0, -1);
    arg0->m_msgId = temp_v0;
    Xiiuiii_func_00134A00(arg0->m_scene, (unsigned int)temp_v0, 0, 0x20, 0x7FFF);
    Xiiuiiii_func_00134CD0(arg0->m_scene, (unsigned int)arg0->m_msgId, 0, 0, 0x200, 0x100);
    Xiiui_func_00135494(arg0->m_scene, (unsigned int)arg0->m_msgId, 1);
    Xiiui_func_00135418(arg0->m_scene, (unsigned int)arg0->m_msgId, 0);
    Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_msgId, 0);
    Xiiu_func_00135594(arg0->m_scene, (unsigned int)arg0->m_msgId);
    Xiiu_func_001985B0((int)arg0, (unsigned int)arg0->m_curPage);
    Xiiiii_func_001C5168((int)&D_007812C0, 4, 0xDC, 0x198);
    Xiiii_func_001C51E0((int)&D_007812C0, 4, 0);
    Xiiiii_func_001C5094((int)&D_007812C0, 4, 0, 0);
    Xii_func_0018741C(temp_s1);
    temp_v0_2 = Xiiiiii_func_00134730(arg0->m_scene, 0x40, 0x20, 0, -1);
    arg0->m_unk134 = temp_v0_2;
    Xiiuiii_func_00134A00(arg0->m_scene, (unsigned int)temp_v0_2, 0xF6, 0x19A, 0x7FFF);
    Xiiuiiii_func_00134CD0(arg0->m_scene, (unsigned int)arg0->m_unk134, 0, 0, 0x40, 0x20);
    Xiiui_func_00135494(arg0->m_scene, (unsigned int)arg0->m_unk134, 1);
    Xiiui_func_00135418(arg0->m_scene, (unsigned int)arg0->m_unk134, 0);
    Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk134, 1);
    Xiiu_func_00135594(arg0->m_scene, (unsigned int)arg0->m_unk134);
    int texture = Xiu_func_001832E8(0x1AU);
    Xiiiii_func_001874F4(temp_s1, arg0->m_unk134, texture, 0);
}

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80D0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80E0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80F0);

struct PBookSaveData {
    int m_pad00[0x11];
    int m_unk44;
    int m_pad48[0x53];
    int m_page;
};
struct PBookSysWork {
    unsigned char m_pad[0xDC1C];
    PBookSaveData *m_save1;
    unsigned int *m_save2;
};
extern "C" int PBookStateFormat(...) asm("func_00279C98");
extern "C" int Xii_func_00131550(int) asm("func_00131550");
extern "C" int Xii_func_00192F3C(MnuPBook *) asm("func_00192F3C");
extern "C" int Xii_func_00193A1C(MnuPBook *) asm("func_00193A1C");
extern "C" int Xii_func_00196EFC(MnuPBook *) asm("func_00196EFC");
extern "C" int Xii_func_0019722C(MnuPBook *) throw() asm("func_0019722C");
extern "C" int Xii_func_001973FC(MnuPBook *) asm("func_001973FC");
extern "C" int Xii_func_00197D28(MnuPBook *) asm("func_00197D28");
extern "C" int Xii_func_001D44E4(int) asm("func_001D44E4");
extern "C" int Xiii_func_00197A74(MnuPBook *, int) asm("func_00197A74");
extern "C" int Xiiiii_func_00131184(int, int, int, int) asm("func_00131184");
extern "C" int Xiiiii_func_001311BC(int, int, int, int) asm("func_001311BC");
extern "C" int Xiiiii_func_001D83D0(int, int, int, int) asm("func_001D83D0");
extern PBookSysWork D_007A4440;
static inline bool PBookStateReady(int object) { return Xii_func_00131550(object) >= 5; }
extern int D_007812C0, D_007B2580;
static inline PBookSaveData *PBookStateObject1(PBookSysWork *game) { return game->m_save1; }
static inline unsigned int *PBookStateObject2(PBookSysWork *game) { return game->m_save2; }
static inline void PBookStateSetPage(PBookSaveData *object, int value) { object->m_page = value; }
static inline void PBookStateClear(unsigned int *address, int mask) { *address &= ~mask; }
static inline void PBookStateSet(unsigned int *address, int mask) { *address |= mask; }
static inline void PBookStateBitClear(unsigned int *array, unsigned int bit) { array[bit >> 5] &= ~(1U << (bit & 31)); }
extern "C" int MnuPBook__vfunc_05(MnuPBook *arg0, int arg1)
{
    int temp_a0;
    int temp_v1_2;
    int var_s2;
    unsigned int temp_v0_3;
    unsigned int temp_v1;

    var_s2 = 0;
    Xii_func_00193A1C(arg0);
    Xii_func_00197D28(arg0);
    temp_v1 = (unsigned int)arg0->m_state;
    arg0->m_unk10 = (int)temp_v1;
    switch (temp_v1) {
    case 0:
        if (!(arg0->m_flags & 0x20000) && (PBookStateReady(arg0->m_scene))) {
            arg0->m_flags = arg0->m_flags | 0x20000;
        }
        temp_v1_2 = arg0->m_flags;
        if (!(temp_v1_2 & 0x10000) && (arg0->m_resUsed == 0)) {
            arg0->m_flags = temp_v1_2 | 0x10000;
            arg0->vfunc11();
            PBookStateFormat(arg0->m_rpkPath, (int)"data/mnurpk/mnupbook/%s.rpk", arg0->m_info->m_prefix);
            arg0->vfunc10();
            Xii_func_00196EFC(arg0);
            arg0->m_flags = arg0->m_flags | 0x20000;
        }
        if ((arg0->m_flags & 0x30000) == 0x30000) {
            arg0->m_state = 1;
        }
        break;
    case 1:
        if (arg0->m_resUsed == 0) {
            Xii_func_0019722C(arg0);
            Xiiiii_func_00131184(arg0->m_scene, 0xF, 7, 0);
            int flags = arg0->m_flags;
            arg0->m_state = 2;
            arg0->m_flags = flags & 0xFFFCFFFF;
        }
        break;
    case 2:
        if (!(arg0->m_flags & 0x20000)) {
            if (PBookStateReady(arg0->m_scene)) {
                arg0->m_flags = arg0->m_flags | 0x20000;
            }
        }
        if (!(arg0->m_flags & 0x10000) && (arg0->m_resUsed == 0)) {
            Xii_func_001973FC(arg0);
            arg0->m_flags = arg0->m_flags | 0x10000;
        }
        temp_a0 = arg0->m_flags;
        if ((temp_a0 & 0x30000) == 0x30000) {
            arg0->m_state = 3;
            arg0->m_flags = temp_a0 & ~2;
        }
        break;
    case 3:
        if (Xiii_func_00197A74(arg0, arg1) == 0) {
            Xiiiii_func_001311BC(arg0->m_scene, 0xF, 7, 0);
            Xiii_func_0017F8FC((int)&D_007B2580, 2);
            Xiiiii_func_001C5094((int)&D_007812C0, 4, 0, 0);
            Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk134, 1);
            arg0->m_state = 4;
        }
        break;
    case 4:
        if (PBookStateReady(arg0->m_scene)) {
            arg0->m_state = 5;
        }
        break;
    case 5: {
        PBookStateObject1(&D_007A4440)->m_unk44 = Xiiiii_func_001D83D0((int)&D_007812C0, 1, arg0->m_unk114, 2);
        int page = arg0->m_unk118;
        PBookStateSetPage(PBookStateObject1(&D_007A4440), page);
        PBookStateClear(PBookStateObject2(&D_007A4440) + 1, 0x04000000);
        if (Xii_func_001D44E4((int)&D_007812C0) != 0) {
            PBookStateSet(PBookStateObject2(&D_007A4440) + 1, 0x02000000);
        }
        temp_v0_3 = Xiiiii_func_001D83D0((int)&D_007812C0, 1, arg0->m_unk114, 6);
        PBookStateBitClear(PBookStateObject2(&D_007A4440), temp_v0_3);
        var_s2 = 1;
        Xii_func_00192F3C(arg0);
        arg0->vfunc03();
        break;
    }
    }
    return var_s2;
}

extern "C" int func_00197A74(MnuPBook *arg0, BedPad *arg1)
{
    int temp_v0;
    int temp_v1;
    int temp_v1_3;
    int var_a1;
    int var_a1_2;
    unsigned int temp_v1_2;

    if (arg0->m_flags & 0x40000) {
        Xiiiii_func_001C5094((int)&D_007812C0, 4, 1, 0);
        Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_unk134, 0);
    }
    temp_v0 = arg0->m_unk124;
    if (temp_v0 > 0) {
        temp_v0--;
        arg0->m_unk124 = temp_v0;
        if (temp_v0 == 0) {
            arg0->m_flags = arg0->m_flags & 0xFFE7FFFD;
            Xiiu_func_001985B0((int)arg0, (unsigned int)arg0->m_curPage);
            if ((arg0->m_curPage + 1) >= arg0->m_unk120) {
                arg0->m_flags = arg0->m_flags | 0x40000;
            }
        }
    }
    Xii_func_001874AC((int)arg0->m_msgWin);
    temp_v1 = arg0->m_flags;
    if (!(temp_v1 & 2)) {
        if (PBookButton(arg1->m_trigger, 13) && (temp_v1 & 0x40000)) {
            Xiiui_func_001351B0(arg0->m_scene, (unsigned int)arg0->m_msgId, 1);
            arg0->m_flags = arg0->m_flags | 2;
            return 0;
        }
        if (arg0->m_unk124 == 0) {
            if ((((arg1->m_press >> 5) & 1 & 0xFFFF) || Xfi_getLeftX__C6BedPad((int)arg1) >= 0.75f) && Xiii_func_00198318((int)arg0, 1)) {
                temp_v1_3 = arg0->m_curPage + 2;
                arg0->m_curPage = temp_v1_3;
                if (temp_v1_3 >= 0) {
                    var_a1_2 = temp_v1_3 / 2;
                } else {
                    var_a1_2 = -1;
                }
                Xiiii_func_00197F18((int)arg0, var_a1_2, 1);
                arg0->m_flags |= 0x100002;
                Xiii_func_0017F8FC((int)&D_007B2580, 8);
                Xiiu_func_001985B0((int)arg0, -0x63U);
            } else if ((((arg1->m_press >> 7) & 1 & 0xFFFF) || Xfi_getLeftX__C6BedPad((int)arg1) <= -0.75f) && Xiii_func_00198318((int)arg0, 0)) {
                temp_v1_2 = (unsigned int)arg0->m_curPage;
                if ((int)temp_v1_2 >= 0) {
                    var_a1 = (int)temp_v1_2 / 2;
                } else {
                    var_a1 = -1;
                }
                Xiiii_func_00197F18((int)arg0, var_a1, 0);
                arg0->m_curPage -= 2;
                arg0->m_flags |= 0x80002;
                Xiii_func_0017F8FC((int)&D_007B2580, 8);
                Xiiu_func_001985B0((int)arg0, -0x63U);
            }
        }
        if (!(arg0->m_flags & 2)) {
            goto done;
        }
    }
block_30:
    arg0->m_unk8B8 = (int)(((unsigned int)arg0->m_unk8B8 + 1) % 300U);
done:
    return 1;
}

extern "C" void func_00197D28(MnuPBook *arg0)
{
    register MnuPBook *self PS2_REG("$17");
    register MnuBookPage *p PS2_REG("$16");
    register int i PS2_REG("$18");
    int temp_v0;

    self = arg0;
    temp_v0 = self->m_pageNum;
    if (temp_v0 != 0) {
        p = self->m_pages;
        i = 0;
        if (temp_v0 > 0) {
            do {
                if (p->m_frame < ((MnuAnimSlot *)((int)self->m_animSlots + (p->m_animIdx << 4)))->m_len) {
                    p->m_frame++;
                }
                i += 1;
                p++;
            } while (i < self->m_pageNum);
        }
        i = 0;
        p = self->m_pages;
        if (self->m_pageNum > 0) {
            do {
                if (p->m_flags & 1) {
                    if (p->m_leftTex != -1) {
                        if (Xiii_func_001943D8((int)self, p->m_leftTex) != 0) {
                            Xiiiii_func_00197E68((int)self, i, p->m_leftTex, 0);
                            p->m_flags = p->m_flags & ~1;
                        }
                    }
                }
                if (p->m_flags & 2) {
                    if (p->m_rightTex != -1) {
                        if (Xiii_func_001943D8((int)self, p->m_rightTex) != 0) {
                            Xiiiii_func_00197E68((int)self, i, p->m_rightTex, 1);
                            p->m_flags = p->m_flags & ~2;
                        }
                    }
                }
                i += 1;
                p++;
            } while (i < self->m_pageNum);
        }
    }
}

extern "C" void func_00197E68(MnuPBook *arg0, int arg1, int arg2, int arg3)
{
    PBookHdr **p = Xp_func_0022AED8(arg0->m_models[arg1].m_data + 0x10, arg3 != 0);
    PBookItem *item = *Xp_func_0022AAD0(p, 0);
    MnuTexSlot *base = arg0->m_texSlots;
    if (arg2 == -1) {
        item->unk1C = (arg3 ? (base + 0x21) : (base + 0x20))->m_texId;
    } else {
        item->unk1C = (base + arg2)->m_texId;
    }
    (*p)->unk08++;
}

extern "C" void func_00197F18(MnuPBook *arg0, int arg1, int arg2)
{
    int t;
    int v;
    MnuBookPage *base;

    base = &arg0->m_pages[arg1];
    v = arg1 * 2;
    t = v;
    if (arg2 != 0)
        t = v + 1;
    base->m_frame = 0;
    base->m_animIdx = t;
    Xiiii_func_00193FEC((int)arg0, arg1, t);
    arg0->m_unk124 = 0xA;
}

// NON_MATCHING: 19/200 differ, 1 reloc differs, 11 edits
#ifdef NON_MATCHING
extern "C" int X_func_0021B550(...) asm("func_0021B550");
extern "C" int X_func_00237340(...) asm("func_00237340");
extern "C" int X_func_002378B0(...) asm("func_002378B0");
extern "C" int Xiii_func_00192F68(MnuPBook *, int) asm("func_00192F68");
extern "C" int Xiii_func_001930F8(MnuPBook *, int) asm("func_001930F8");
extern "C" int Xiii_func_00193210(MnuPBook *, int) asm("func_00193210");
extern "C" int Xiiiff_func_00193258(MnuPBook *, float, float, int) asm("func_00193258");
extern "C" int Xiiiiiii_func_0019368C(MnuPBook *, int, int, int, int, int) asm("func_0019368C");
extern const unsigned int D_002F8140[4] __attribute__((aligned(16)));
struct PBookV6Pair { long long a, b; };
extern "C" void MnuPBook__vfunc_06(MnuPBook *arg0, int arg1)
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
    MnuBookPage *var_s1;

    if ((unsigned int)(arg0->m_unk10 - 2) < 3U) {
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
        if ((arg0->m_curPage - 1) >= 0) {
            if (arg0->m_flags & 0x80000) {
                var_s0 = ((unsigned int)arg0->m_unk8B8 >> 1) % 3U;
            } else {
                var_s0 = 0;
            }
            stack.spC = 16.0f;
            temp_f0 = ((float)var_s0 * 16.0f) + 48.0f;
            stack.sp8 = 28.0f;
            stack.sp18 = 0.21875f;
            stack.sp10 = 0.0f;
            stack.sp14 = temp_f0 * 0.0078125f;
            stack.sp1C = (temp_f0 + 16.0f) * 0.0078125f;
            Xiiiff_func_00193258(arg0, 100.0f, 412.0f, (int)&stack);
        }
        if ((arg0->m_curPage + 2) < arg0->m_info->m_pageCount) {
            if (arg0->m_flags & 0x100000) {
                var_s0 = ((unsigned int)arg0->m_unk8B8 >> 1) % 3U;
            } else {
                var_s0 = 0;
            }
            stack.sp10 = 0.0f;
            stack.spC = 16.0f;
            temp_f0_2 = ((float)var_s0 * 16.0f) + stack.sp10;
            stack.sp8 = 28.0f;
            stack.sp18 = 0.21875f;
            stack.sp14 = temp_f0_2 * 0.0078125f;
            stack.sp1C = (temp_f0_2 + 16.0f) * 0.0078125f;
            Xiiiff_func_00193258(arg0, 384.0f, 412.0f, (int)&stack);
        }
        var_s0 = 0;
        arg0->m_unkB0 = X_func_0021B550(arg0->m_unkB0, 0x47, 0x503FD);
        Xiii_func_001930F8(arg0, arg1);
        stack.vec = *(PBookV6Pair *)&D_002F8140;
        X_func_00237340((int)&stack.sp50);
        X_func_002378B0((int)&stack.sp50, (int)&stack.sp50, (int)&stack.vec);
        stack.sp80 = 25.0f;
        stack.sp84 = 8.0f;
        stack.sp88 = 220.0f;
        var_s1 = arg0->m_pages;
        if (arg0->m_pageNum > 0) {
            do {
                temp_a4 = var_s1->m_animIdx;
                temp_a3 = var_s0;
                temp_a5 = var_s1->m_frame;
                var_s1++;
                var_s0 += 1;
                Xiiiiiii_func_0019368C(arg0, arg1, (int)&stack.sp50, temp_a3, temp_a4, temp_a5);
            } while (var_s0 < arg0->m_pageNum);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_06);
#endif

extern "C" int X_func_00223228(int, int) asm("func_00223228");
extern "C" int X_func_00223558(int, int) asm("func_00223558");
extern "C" void MnuPBook__vfunc_07(MnuPBook *arg0, int arg1)
{
    int arr[16];
    int q[6];
    MnuTexSlot *p1;
    MnuTexSlot *p2;
    int v;
    int c;

    p1 = arg0->m_texSlots;
    arr[0] = p1[0].m_texId;
    p1[0].m_unk0C = 0;
    p2 = arg0->m_texSlots;
    arr[1] = p2[1].m_texId;
    c = 1;
    p2[1].m_unk0C = c;
    c = 2;
    q[2] = c;
    q[0] = 0;
    q[1] = (int)arr;
    q[3] = 0;
    q[4] = 0;
    q[5] = 0;
    v = X_func_00223558(arg1, (int)q);
    arg0->m_unkAC = v;
    X_func_00223228(arg1, v);
}

extern const unsigned int D_002F8140[4] __attribute__((aligned(16))) = {
    0xBF860A91, 0x40490FD9, 0, 0
};
