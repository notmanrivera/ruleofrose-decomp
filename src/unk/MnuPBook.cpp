#include "include_asm.h"
#include "bed/bedpfh.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193A1C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193D1C);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00193FEC);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194148);

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


INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00194404);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001946E4);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195430);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_0019586C);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195A34);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00195B78);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196878);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_03);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00196EFC);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_0019722C);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_001973FC);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80D0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80E0);

INCLUDE_RODATA("asm/nonmatchings/unk/MnuPBook", D_002F80F0);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00197A74);

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", func_00197D28);

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

INCLUDE_ASM("asm/nonmatchings/unk/MnuPBook", MnuPBook__vfunc_06);

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
