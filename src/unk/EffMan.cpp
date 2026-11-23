#include "include_asm.h"
#include "unk/Eff0.h"
struct EffNameTable_177F54 {
    const char *names[54];
};
extern "C" const EffNameTable_177F54 D_002F2CD0;
extern "C" unsigned int X_177F54_strlen(const char *) asm("strlen");
extern "C" void *X_177F54_memcpy(void *, const void *, unsigned int) asm("memcpy");
struct EffMan_176AFC {
    void *field_0;
    void *ptrs[0x110];
    int field_444;
    int field_448;
    int list[0x110];
    int field_88C[256];
    int field_C8C;
    char pad_C90[0x1294 - 0xC90];
    int field_1294;
    int field_1298;
};
extern "C" int X_176AFC_16AC84() asm("func_0016AC84");
extern "C" void X_176AFC_1780C0(EffMan_176AFC *) asm("func_001780C0");
extern "C" void *X_176AFC_memset(void *, int, unsigned int) asm("memset");
extern "C" int X_176AFC_17820C(EffMan_176AFC *, int, const char *, void *) asm("func_0017820C");
struct EffObj_177C00 {
    char pad[0x10];
    float field_10;
};
struct EffMan_177C00 {
    int field_0;
    EffObj_177C00 *ptrs[0x110];
    int field_444;
    int field_448;
    int list[0x110];
};
extern "C" void *X_177C00_memmove(void *, const void *, unsigned int) asm("memmove");
struct EffObj_17772C {
    char pad[32];
    virtual int vfunc_08(int);
    virtual void vfunc_10();
    virtual void vfunc_18();
    virtual int vfunc_20();
};
struct EffMan_17772C {
    int field_0;
    EffObj_17772C *ptrs[0x110];
    int field_444;
    int field_448;
};
extern "C" void X_17772C_756C(EffMan_17772C *, int) asm("func_0017756C");
extern "C" int X_177D20_21A158(...) asm("func_0021A158");
extern "C" int X_177D20_21F7E0(...) asm("func_0021F7E0");
extern "C" int X_177D20_223240(...) asm("func_00223240");
extern "C" int X_177D20_223250(...) asm("func_00223250");
extern "C" int X_177D20_223260(...) asm("func_00223260");
extern "C" int X_177D20_226C58(...) asm("func_00226C58");
extern "C" int X_177D20_getViewMatrix(int) asm("getViewMatrix__9DogCamera");
extern "C" int X_177D20_apply(int, int, int, float, int) asm("apply__C12DogLightPoolPvifi");
struct EffObj_1779B8 {
    char pad[0x10];
    float field_10;
};
struct EffMan_1779B8 {
    int field_0;
    EffObj_1779B8 *ptrs[0x110];
    int field_444;
    int field_448;
    int list[0x110];
};
extern "C" int X_1779B8_7A8C(EffMan_1779B8 *) asm("func_00177A8C");
extern "C" void X_1779B8_7C00(EffMan_1779B8 *, int) asm("func_00177C00");
struct EffObj_17756C {
    unsigned short flags;
    char pad[30];
    virtual int call(int);
};
struct EffMan_17756C {
    int field_0;
    EffObj_17756C *ptrs[0x110];
    int field_444;
    int field_448;
    char pad_44C[0x1294 - 0x44C];
    int field_1294;
    int field_1298;
};
extern "C" void X_17756C_7E24(EffMan_17756C *, int) asm("func_00177E24");
struct EffObj_17762C {
    char pad[32];
    virtual int call(int);
};
struct EffMan_17762C {
    int field_0;
    EffObj_17762C *ptrs[0x110];
    int field_444;
    int field_448;
    char pad_44C[0xC8C - 0x44C];
    int field_C8C;
    char pad_C90[0x1294 - 0xC90];
    int field_1294;
    int field_1298;
};
extern "C" int X_17762C_8894(EffMan_17762C *, int) asm("func_00178894");
struct EffMan_1774E0 {
    int field_0;
    void *ptrs[0x110];
    int field_444;
    int field_448;
};
extern "C" int X_1774E0_76C4(EffMan_1774E0 *) asm("func_001776C4");
extern "C" int X_1774E0_7E9C(EffMan_1774E0 *) asm("func_00177E9C");
extern "C" void X_1774E0_7EF8(EffMan_1774E0 *, int) asm("func_00177EF8");
struct EffManEntry_178148 {
    int active;
    char name[0x5C];
};
struct EffMan_178148 {
    char pad[0xC94];
    EffManEntry_178148 entries[16];
};
extern "C" unsigned int X_178148_strlen(const char *) asm("strlen");
extern "C" int X_178148_memcmp(const void *, const void *, unsigned int) asm("memcmp");
struct FileReadReq_1780C0 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    const char *m_name;
    int m_offset;
    int m_unk14;
    void *m_buf;
    int m_size;
    int m_unk20;
};
struct EffMan_1780C0 {
    char pad0[0xC90];
    void *m_buf;
    char pad1[0x129C - 0xC94];
    int m_reader[2]; // 0x129C..0x12A4
    FileReadReq_1780C0 m_req; // 0x12A4
};
extern "C" void X_1780C0_FileReadReq(FileReadReq_1780C0 *) asm("__11FileReadReq");
extern "C" void *X_1780C0_alloc(void *, int, int) asm("alloc__9BedMemoryii");
extern "C" int X_1780C0_read(int *, FileReadReq_1780C0 *, int) asm("func_001BE524__10FileReaderP11FileReadReqi");
struct EffMan_177E24 {
    char pad[0x88C];
    int arr[256];
    int count;
};
extern "C" void *X_177E24_memmove(void *, const void *, unsigned int) asm("memmove");
struct EffMan_1776C4 {
    int field_0;
    void *ptrs[0x110];
    int field_444;
};
struct EffItem_177EF8 {
    int field_0;
    int field_4;
};
struct EffMan_177EF8 {
    int field_0;
    EffItem_177EF8 *ptrs[0x110];
    int field_444;
    int field_448;
};
struct EffMan_177E9C {
    char pad[0x88C];
    int arr[256];
    int count;
};
extern "C" void *X_177E9C_memmove(void *, const void *, unsigned int) asm("memmove");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_func_00176C50(void *) asm("func_00176C50");
extern "C" void X_dtor_10FileReader(void *, int) asm("_$_10FileReader");
struct EffManEntry_1781D0 {
    char pad0[4];
    int field_4;
    char pad8[0x58];
};
struct EffMan_1781D0 {
    char pad[0xC90];
    EffManEntry_1781D0 entries[16];
};
struct EffMan_177E04 {
    char pad[0x88C];
    int arr[256];
    int count;
};
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X___10FileReader(...) asm("__10FileReader");
extern "C" int X___11FileReadReq(...) asm("__11FileReadReq");
extern "C" int X_alloc__9BedMemoryii(...) asm("alloc__9BedMemoryii");
extern "C" int X_apply__C12DogLightPoolPvifi(...) asm("apply__C12DogLightPoolPvifi");
extern "C" int X_free__9BedMemoryPv(...) asm("free__9BedMemoryPv");
extern "C" int X_func_0016AC84(...) asm("func_0016AC84");
extern "C" int X_func_0017762C(...) asm("func_0017762C");
extern "C" int X_func_001776C4(...) asm("func_001776C4");
extern "C" int X_func_00177A8C(...) asm("func_00177A8C");
extern "C" int X_func_00177C00(...) asm("func_00177C00");
extern "C" int X_func_00177E9C(...) asm("func_00177E9C");
extern "C" int X_func_00177EF8(...) asm("func_00177EF8");
extern "C" int X_func_001780C0(...) asm("func_001780C0");
extern "C" int X_func_0017820C(...) asm("func_0017820C");
extern "C" int X_func_00178894(...) asm("func_00178894");
extern "C" int X_func_001BE524__10FileReaderP11FileReadReqi(...) asm("func_001BE524__10FileReaderP11FileReadReqi");
extern "C" int X_func_0021A158(...) asm("func_0021A158");
extern "C" int X_func_0021F7E0(...) asm("func_0021F7E0");
extern "C" int X_func_00223240(...) asm("func_00223240");
extern "C" int X_func_00223250(...) asm("func_00223250");
extern "C" int X_func_00223260(...) asm("func_00223260");
extern "C" int X_func_00226C58(...) asm("func_00226C58");
extern "C" int X_getViewMatrix__9DogCamera(...) asm("getViewMatrix__9DogCamera");
extern "C" int X_memcmp(...) asm("memcmp");
extern "C" int X_memmove(...) asm("memmove");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_render__4Eff0PQ24Eff011RENDERPARAM(...) asm("render__4Eff0PQ24Eff011RENDERPARAM");
extern "C" int X_strlen(...) asm("strlen");
extern int D_00298E08;
extern int D_00298E0C;
extern int D_006E9800;


extern "C" void func_00176A34(void) {
}

extern "C" int func_00176A3C(int arg0)
{
    X___10FileReader(arg0 + 0x129C);
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x444)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x448)) = 0;
    X_memset(arg0 + 4, 0, 0x440);
    X_memset(arg0 + 0x44C, 0, 0x440);
    (*(int *)(int *)((char *)(arg0) + 0xC90)) = 0;
    return X_memset(arg0 + 0xC94, 0, 0x600);
}


extern "C" void func_00176AA0(char *arg0, int arg1)
{
    X_func_00176C50(arg0);
    X_dtor_10FileReader(arg0 + 0x129C, 2);
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

extern "C" int func_00176AFC(EffMan_176AFC *self, int arg1, void *arg2)
{
    self->field_0 = arg2;
    self->field_444 = 0;
    self->field_448 = 0;
    X_176AFC_memset(self->ptrs, 0, 0x440);
    for (int i = 0; i < 0x110; i++) {
        self->list[i] = i;
    }
    self->field_1294 = -1;
    self->field_1298 = -1;
    self->field_C8C = 0;
    D_00298E08 = (int)self->field_0;
    D_00298E0C = arg1;
    X_176AFC_16AC84();
    X_176AFC_1780C0(self);
    X_176AFC_17820C(self, 1, 0, (void *)1);
    X_176AFC_17820C(self, 2, 0, (void *)1);
    X_176AFC_17820C(self, 3, 0, (void *)1);
    X_176AFC_17820C(self, 4, 0, (void *)1);
    X_176AFC_17820C(self, 0x32, 0, (void *)1);
    X_176AFC_17820C(self, 0x1F, 0, (void *)1);
    X_176AFC_17820C(self, 0x26, 0, (void *)1);
    X_176AFC_17820C(self, 0x27, 0, (void *)1);
    X_176AFC_17820C(self, 0x1A, 0, (void *)1);
    return 1;
}

extern "C" void func_00176C50(int arg0)
{
    int temp_v0;

    X_func_0017762C();
    X_func_00178894(arg0, 1);
    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0xC90));
    if (temp_v0 != 0) {
        X_free__9BedMemoryPv((int)&D_006E9800, temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0xC90)) = 0;
    }
    (*(int *)(int *)((char *)(arg0) + 0x12BC)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x12C4)) = 1;
    X_func_001BE524__10FileReaderP11FileReadReqi(arg0 + 0x129C, arg0 + 0x12A4, 0);
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    D_00298E08 = 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00176CC8);

extern "C" int func_001774E0(EffMan_1774E0 *self, void *arg1)
{
    int idx = X_1774E0_76C4(self);
    if (idx == -1) {
        idx = X_1774E0_7E9C(self);
        if (idx == -1) {
            return -1;
        }
        X_1774E0_7EF8(self, idx);
    }
    self->ptrs[idx] = arg1;
    self->field_448++;
    return idx;
}

extern "C" void func_0017756C(EffMan_17756C *self, int arg1)
{
    if (self->ptrs[arg1] != 0) {
        if (arg1 == self->field_1294) {
            self->field_1294 = -1;
        } else if (arg1 == self->field_1298) {
            self->field_1298 = -1;
        }
        unsigned int flags = self->ptrs[arg1]->flags;
        if ((flags >> 4) & 1) {
            X_17756C_7E24(self, arg1);
        }
        if (self->ptrs[arg1] != 0) {
            self->ptrs[arg1]->call(3);
        }
        self->ptrs[arg1] = 0;
        self->field_448--;
    }
}

extern "C" void func_0017762C(EffMan_17762C *self)
{
    for (int i = 0; i < 0x110; i++) {
        if (self->ptrs[i] != 0) {
            self->ptrs[i]->call(3);
            self->ptrs[i] = 0;
        }
    }
    self->field_448 = 0;
    self->field_1294 = -1;
    self->field_1298 = -1;
    self->field_C8C = 0;
    X_17762C_8894(self, 0);
}

extern "C" int func_001776C4(EffMan_1776C4 *self)
{
    int idx = self->field_444;
    for (int i = 0; i < 0x100; i++) {
        if (self->ptrs[idx] == 0) {
            self->field_444 = (idx + 1) % 0x100;
            return idx;
        }
        idx = (idx + 1) % 0x100;
    }
    return -1;
}

extern "C" void func_0017772C(EffMan_17772C *self)
{
    int i;
    EffObj_17772C **p = &self->ptrs[0x100];
    for (i = 0x100; i < 0x110; i++, p++) {
        if (*p != 0) {
            if ((*p)->vfunc_20() == 0) {
                if (self->ptrs[i] != 0) {
                    self->ptrs[i]->vfunc_08(3);
                }
                self->ptrs[i] = 0;
            }
        }
    }
    if (self->field_448 != 0) {
        p = self->ptrs;
        for (i = 0; i < 0x100; i++, p++) {
            if (*p != 0) {
                if ((*p)->vfunc_20() == 0) {
                    X_17772C_756C(self, i);
                }
            }
        }
    }
}

// NON_MATCHING: 5/98 differ, 9 edits (ori/daddu order at 21B550 calls and addu operand order in loop 2)
#ifdef NON_MATCHING
struct EffObj_177830 {
    char pad[32];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_30(int *);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void vfunc_60();
};
struct EffMan_177830 {
    int field_0;
    EffObj_177830 *ptrs[0x110];
    int field_444;
    int field_448;
    int list[0x110];
};
extern "C" int X_177830_21B550(int, int, int) asm("func_0021B550");
extern "C" int X_177830_223378(int) asm("func_00223378");
extern "C" void X_177830_223398(int, int) asm("func_00223398");
extern "C" void X_177830_16ADD8() asm("func_0016ADD8");
extern "C" int X_177830_79B8(EffMan_177830 *) asm("func_001779B8");
extern "C" int X_177830_7D20(EffMan_177830 *, int, float) asm("func_00177D20");
extern "C" void func_00177830(EffMan_177830 *self, int arg1)
{
    int sp[2];
    if (self->field_448 != 0) {
        int i;
        EffObj_177830 **ptrs = self->ptrs;
        EffObj_177830 **p = ptrs;
        sp[0] = X_177830_7D20(self, arg1, 850.0f);
        X_177830_223398(sp[0], X_177830_21B550(X_177830_21B550(X_177830_223378(sp[0]), 8, 0), 0x47, 0x5000D));
        sp[1] = X_177830_7D20(self, arg1, 855.0f);
        X_177830_223398(sp[1], X_177830_21B550(X_177830_21B550(X_177830_223378(sp[1]), 8, 0), 0x47, 0x3000D));
        for (i = 0; i < 0x110; i++, p++) {
            if (*p != 0) {
                (*p)->vfunc_60();
            }
        }
        int n = X_177830_79B8(self);
        X_177830_16ADD8();
        for (i = 0; i < n; i++) {
            ptrs[self->list[i]]->vfunc_30(sp);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00177830);
#endif

extern "C" int func_001779B8(EffMan_1779B8 *self)
{
    int n = X_1779B8_7A8C(self);
    EffObj_1779B8 *prev = self->ptrs[self->list[0]];
    for (int i = 1; i < n; i++) {
        EffObj_1779B8 *cur = self->ptrs[self->list[i]];
        if (prev->field_10 < cur->field_10) {
            X_1779B8_7C00(self, i);
            prev = self->ptrs[self->list[i]];
        } else {
            prev = cur;
        }
    }
    return n;
}

// NON_MATCHING: 1/93 differ, 1 edits (addu $a0, $s2, $a0 vs addu $a0, $a0, $s2)
#ifdef NON_MATCHING
struct EffMan_177A8C {
    int field_0;
    void *ptrs[0x110];
    int field_444;
    int field_448;
    int list[0x110];
};
extern "C" void *X_177A8C_memcpy(void *, const void *, unsigned int) asm("memcpy");
extern "C" void *X_177A8C_memmove(void *, const void *, unsigned int) asm("memmove");
extern "C" int func_00177A8C(EffMan_177A8C *self)
{
    int tmp[0x110];
    int i;
    for (i = 0; i < 0x110; i++) {
        if (self->ptrs[self->list[i]] == 0) {
            int j;
            for (j = i + 1; j < 0x110; j++) {
                if (self->ptrs[self->list[j]] != 0) {
                    break;
                }
            }
            if (j == 0x110) {
                break;
            }
            int count = j - i;
            if (count == 1) {
                tmp[0] = self->list[i];
                X_177A8C_memmove(&self->list[i], &self->list[j], (0x110 - j) * 4);
                self->list[0x110 - 1] = tmp[0];
            } else {
                X_177A8C_memcpy(tmp, &self->list[i], count * 4);
                X_177A8C_memmove(&self->list[i], &self->list[j], (0x110 - j) * 4);
                X_177A8C_memcpy(&self->list[0x110 - count], tmp, count * 4);
            }
        }
    }
    return i;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00177A8C);
#endif

extern "C" void func_00177C00(EffMan_177C00 *self, int arg1)
{
    int lo = 0;
    int hi = arg1 - 1;
    int idx;
    EffObj_177C00 *target = self->ptrs[self->list[arg1]];
    while (hi - lo > 0) {
        idx = lo + (hi - lo + 1) / 2;
        EffObj_177C00 *obj = self->ptrs[self->list[idx]];
        if (target->field_10 < obj->field_10) {
            lo = idx + 1;
        } else if (obj->field_10 < target->field_10) {
            hi = idx - 1;
        } else {
            break;
        }
    }
    if (target->field_10 < self->ptrs[self->list[lo]]->field_10) {
        lo++;
    }
    idx = self->list[arg1];
    X_177C00_memmove(&self->list[lo + 1], &self->list[lo], (arg1 - lo) * 4);
    self->list[lo] = idx;
}

extern "C" int func_00177D20(int arg0, int arg1)
{
    int temp_s2;
    int temp_a0;
    int temp_v0;

    temp_s2 = X_177D20_21F7E0(arg1);
    X_177D20_223240(temp_s2, X_177D20_apply((int)((*(int *)(arg0)) + 0x2050), arg1, 0, 1.0f, 0));
    temp_v0 = (*(int *)(arg0));
    if (M2C_FIELD(temp_v0, int *, 0x2AA84) != 0) {
        X_177D20_223250(temp_s2, X_177D20_21A158(arg1, temp_v0 + 0x2AAE0));
    }
    temp_a0 = (*(int *)(arg0));
    int p = temp_a0 + 0x2AA10;
    X_177D20_223260(temp_s2, X_177D20_226C58(arg1, p, X_177D20_getViewMatrix(temp_a0 + 0x2AB70)));
    return temp_s2;
}

extern "C" void func_00177E04(EffMan_177E04 *self, int arg1)
{
    self->arr[self->count++] = arg1;
}

extern "C" void func_00177E24(EffMan_177E24 *self, int arg1)
{
    for (int i = 0; i < self->count; i++) {
        if (self->arr[i] == arg1) {
            X_177E24_memmove(&self->arr[i], &self->arr[i + 1], (self->count - i - 1) * 4);
            self->count--;
            return;
        }
    }
}

extern "C" int func_00177E9C(EffMan_177E9C *self)
{
    if (self->count == 0) {
        return -1;
    }
    int first = self->arr[0];
    X_177E9C_memmove(&self->arr[0], &self->arr[1], (self->count - 1) * 4);
    self->count--;
    return first;
}

extern "C" void func_00177EF8(EffMan_177EF8 *self, int arg1)
{
    for (int i = 0x100; i < 0x110; i++) {
        if (self->ptrs[i] == 0) {
            self->ptrs[i] = self->ptrs[arg1];
            self->ptrs[arg1] = 0;
            self->ptrs[i]->field_4 = 0;
            self->field_448--;
            return;
        }
    }
}

extern "C" void func_00177F54(int arg0, char *arg1, const char *arg2)
{
    EffNameTable_177F54 table = D_002F2CD0;
    const char *s = table.names[arg0];
    int len = X_177F54_strlen(s);
    X_177F54_memcpy(arg1, s, len);
    if (arg2 != 0) {
        int len2 = X_177F54_strlen(arg2);
        X_177F54_memcpy(arg1 + len, arg2, len2);
        len += len2;
    }
    arg1[len] = 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2B90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2B98);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BA8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BB8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BD8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BE8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BF8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C00);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C08);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C10);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C18);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C20);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C28);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C30);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C38);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C40);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C48);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C50);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C58);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C60);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C68);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C88);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C98);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CA0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CA8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CB0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CC0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CD0);

extern "C" void func_001780C0(EffMan_1780C0 *self)
{
    self->m_buf = X_1780C0_alloc(&D_006E9800, 0x800, -1);
    X_1780C0_FileReadReq(&self->m_req);
    self->m_req.m_name = "data/eff/eff.bin";
    self->m_req.m_size = 0x800;
    self->m_req.m_buf = self->m_buf;
    self->m_req.m_unk14 = 0;
    self->m_req.m_offset = 0;
    self->m_req.m_unk20 = 0;
    X_1780C0_read(self->m_reader, &self->m_req, 0);
    self->m_req.m_buf = 0;
}

extern "C" int func_00178148(EffMan_178148 *self, int arg1, const char *arg2)
{
    EffManEntry_178148 *p = self->entries;
    for (int i = 0; i < 16; i++, p++) {
        if (p->active != 0 &&
            X_178148_memcmp(p->name, arg2, X_178148_strlen(p->name)) == 0) {
            return i;
        }
    }
    return -1;
}

extern "C" int func_001781D0(EffMan_1781D0 *self)
{
    for (int i = 0; i < 16; i++) {
        if (self->entries[i].field_4 == 0) {
            return i;
        }
    }
    return -1;
}

// NON_MATCHING: 30/50 differ, 2 relocs differ (size 0xC8, game 0xC0), 5 edits
#ifdef NON_MATCHING
struct EffLoadInfo_17820C {
    EffManEntry_178148 *entry; // 0x00
    int arg1;                  // 0x04
    char name[0x20];           // 0x08
    void *arg3;                // 0x28
    int pad_2C;                // 0x2C
};
extern "C" void X_17820C_7F54(int, char *, const char *) asm("func_00177F54");
extern "C" int X_17820C_8148(EffMan_178148 *, int, const char *) asm("func_00178148");
extern "C" int X_17820C_81D0(EffMan_178148 *) asm("func_001781D0");
extern "C" int X_17820C_82CC(EffMan_178148 *, EffLoadInfo_17820C *) asm("func_001782CC");
extern "C" int func_0017820C(EffMan_178148 *self, int arg1, const char *arg2, void *arg3)
{
    EffLoadInfo_17820C info;
    X_17820C_7F54(arg1, info.name, arg2);
    if (info.name[0] == 0) {
        return -1;
    }
    int res = X_17820C_8148(self, arg1, info.name);
    if (res != -1) {
        return res;
    }
    int idx = X_17820C_81D0(self);
    info.arg1 = arg1;
    info.arg3 = arg3;
    info.entry = &self->entries[idx];
    return X_17820C_82CC(self, &info) ? idx : -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_0017820C);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_001782CC);
