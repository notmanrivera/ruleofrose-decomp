#include "include_asm.h"

#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))

extern "C" char vtbl_9TskDamage[] asm("_vt$9TskDamage");
extern "C" void Xv_func_001F9E58(int) asm("func_001F9E58");
extern "C" int Xiii_func_001CB460(int, int, int) asm("func_001CB460");
extern "C" int Xiii_func_001FB624(int, int, int) asm("func_001FB624");
extern "C" int X_func_00163E10(...) asm("func_00163E10");
extern "C" int X_func_00163E48(...) asm("func_00163E48");
extern "C" int X_func_00163E74(...) asm("func_00163E74");
extern "C" int X_func_001DA074(...) asm("func_001DA074");
extern "C" int X_func_001DA07C(...) asm("func_001DA07C");
extern int D_007812C0;
extern int D_007B2140;

extern "C" void func_001F9E38(int arg0)
{
    M2C_FIELD(arg0, void **, 0) = vtbl_9TskDamage;
    return Xv_func_001F9E58(arg0);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB78);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBB8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBD0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBD8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBE8);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001F9E58);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FA5BC);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FA768);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FA9C4);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FAA70);

extern "C" void TskDamage__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x18));
    if (temp_v0 != 0) {
        X_func_001DA074(temp_v0);
    }
}

extern "C" void TskDamage__vfunc_04(int arg0)
{
    short idx;
    long ent;
    int fp;
    short base;
    int off;
    int p;

    idx = M2C_FIELD(arg0, short *, 0x6);
    if (idx >= 0) {
        p = *(int *) (arg0 + M2C_FIELD(arg0, short *, 0x8));
        p += idx * 8;
        ent = *((long *) p - 1);
        fp = (int) (ent >> 32);
    } else {
        fp = M2C_FIELD(arg0, int *, 0x8);
    }
    base = M2C_FIELD(arg0, short *, 0x4);
    off = (idx >= 0) ? (short) ent + base : base;
    ((void (*)(int)) fp)(arg0 + off);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FAC60);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FAE14);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FB084);

extern "C" void func_001FB5D4(int arg0, int arg1)
{
    int info[4];

    Xiii_func_001CB460((int)&D_007812C0, 1, (int)info);
    Xiii_func_001FB624(info[0], arg0, arg1);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED78);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEDA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEDA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEDB0);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FB624);

extern "C" int func_001FBB04(int arg0)
{
    int temp_v1;
    int temp_v1_2;

    if ((*(int *)(int *)((char *)(arg0) + 0xC)) & 8) {
        temp_v1 = (*(int *)(int *)((char *)(arg0) + 0x18));
        (*(int *)(int *)((char *)(temp_v1) + 0x120)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x120)) & ~0x200);
        temp_v1_2 = (*(int *)(int *)((char *)(arg0) + 0x10));
        if ((*(int *)(int *)((char *)(arg0) + 0x20)) < 0x2710) {
            X_func_00163E10((int)&D_007B2140, temp_v1_2, 0);
            X_func_00163E74((int)&D_007B2140, (*(int *)(int *)((char *)(arg0) + 0x10)));
            return 1;
        }
        X_func_00163E48((int)&D_007B2140, temp_v1_2);
        X_func_001DA07C((*(int *)(int *)((char *)(arg0) + 0x18)));
        return 1;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEE90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEEA0);
