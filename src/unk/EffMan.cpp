#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00176AFC);

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

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_001774E0);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_0017756C);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_0017762C);

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

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_0017772C);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00177830);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_001779B8);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00177A8C);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00177C00);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00177D20);

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

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00177F54);

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

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_001780C0);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00178148);

extern "C" int func_001781D0(EffMan_1781D0 *self)
{
    for (int i = 0; i < 16; i++) {
        if (self->entries[i].field_4 == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_0017820C);

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_001782CC);
