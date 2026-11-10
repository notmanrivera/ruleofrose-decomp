#include "include_asm.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xi_func_001536CC() asm("func_001536CC");
extern "C" int Xii_func_001517E0(int) asm("func_001517E0");
extern "C" int Xii_func_001519B8(int) asm("func_001519B8");
extern "C" int Xii_func_00151F1C(int) asm("func_00151F1C");
extern "C" int Xii_func_001520CC(int) asm("func_001520CC");
extern "C" int Xii_func_00152544(int) asm("func_00152544");
extern "C" int Xiii_func_0010423C(int, int) asm("func_0010423C");
extern "C" int Xiii_func_0016649C(int, int) asm("func_0016649C");
extern "C" int Xiii_func_00166DA4(int, int) asm("func_00166DA4");
extern "C" int Xiii_func_001694CC(int, int) asm("func_001694CC");
extern "C" int Xiiif_func_00166F50(int, int, float) asm("func_00166F50");
extern "C" int Xiiif_func_00167230(int, int, float) asm("func_00167230");
extern "C" int Xiiii_func_00104394(int, int, int) asm("func_00104394");
extern "C" int Xiiii_func_001680A0(int, int, int) asm("func_001680A0");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00104394(...) asm("func_00104394");
extern "C" int X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_0013166C(...) asm("func_0013166C");
extern "C" int X_func_001513EC(...) asm("func_001513EC");
extern "C" int X_func_001517E0(...) asm("func_001517E0");
extern "C" int X_func_001519B8(...) asm("func_001519B8");
extern "C" int X_func_00151F1C(...) asm("func_00151F1C");
extern "C" int X_func_001520CC(...) asm("func_001520CC");
extern "C" int X_func_0015246C(...) asm("func_0015246C");
extern "C" int X_func_00152544(...) asm("func_00152544");
extern "C" int X_func_00152F3C(...) asm("func_00152F3C");
extern "C" int X_func_001536CC(...) asm("func_001536CC");
extern "C" int X_func_0016649C(...) asm("func_0016649C");
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166DA4(...) asm("func_00166DA4");
extern "C" int X_func_00166F50(...) asm("func_00166F50");
extern "C" int X_func_00167230(...) asm("func_00167230");
extern "C" int X_func_001680A0(...) asm("func_001680A0");
extern "C" int X_func_001693EC(...) asm("func_001693EC");
extern "C" int X_func_0016947C(...) asm("func_0016947C");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001FAC60(...) asm("func_001FAC60");
extern int D_006E9840;
extern int D_007812C0;
extern int D_007B205C;

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_001515C4);

extern "C" void NorOutAttack__vfunc_02(int arg0)
{
    Xiii_func_00166DA4(arg0, 0x64);
    M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x150) = 0;
    Xii_func_001517E0(arg0);
}

extern "C" int NorOutAttack__vfunc_03(int arg0)
{
    int temp_v1;
    int var_a1;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x40);
    var_a1 = -1;
    switch (temp_v1) {                              
    case 0:
        var_v0 = Xii_func_001520CC(arg0);
block_11:
        var_a1 = var_v0;
        break;
    case 1:
        var_v0 = Xii_func_00152544(arg0);
        goto block_11;
    case 2:
        var_v0 = Xii_func_001519B8(arg0);
        goto block_11;
    case 3:
        var_v0 = Xii_func_00151F1C(arg0);
        goto block_11;
    }
    return var_a1;
}

extern "C" void NorOutAttack__vfunc_04(int arg0)
{
    X_func_00166AD0();
    (*(int *)(int *)((char *)(D_007B205C) + 0x650)) = 0;
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x04000000);
    X_func_001D10D0((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x40);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x10000000);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
    X_func_0016649C((*(int *)(int *)((char *)(arg0) + 0xC)), 1);
    X_func_001D1410((int)&D_007812C0, (*(int *)(int *)((char *)(arg0) + 0x0)), 0x400);
}


INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_001517E0);

extern "C" void func_0015195C(int arg0)
{
    int temp_v0;

    M2C_FIELD(arg0, int *, 0x3C) = 0;
    M2C_FIELD(arg0, int *, 0x48) = 0;
    M2C_FIELD(arg0, int *, 0x54) = 0;
    M2C_FIELD(arg0, int *, 0x40) = 0;
    temp_v0 = Xiiii_func_00104394(0xA, 0x96, 3);
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0x38) = temp_v0;
    Xiiif_func_00166F50(arg0, M2C_FIELD(arg0, int *, 0x14), 88.5f);
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_001519B8);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA50);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA60);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA70);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA98);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFAB8);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFAD8);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00151D4C);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00151F1C);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_001520CC);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_0015246C);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB28);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152544);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152748);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152B24);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152BB4);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152C60);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152CFC);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152DA4);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152E40);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152E90);

extern "C" void func_00152F34(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152F3C);

extern "C" void NorOutBitten__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiiii_func_001680A0(arg0, 0x17, 0x100);
    M2C_FIELD(arg0, int *, 0x44) = 0;
    M2C_FIELD(arg0, int *, 0x40) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutBitten__vfunc_03);

extern "C" void NorOutBitten__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void NorOutWalk__vfunc_02(int arg0)
{
    int temp_v0;

    M2C_FIELD(arg0, short *, 0x3A) = Xi_func_001536CC();
    temp_v0 = Xiii_func_0010423C(0x3E8, 0x7D0);
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0x44) = temp_v0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB68);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB70);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB78);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB80);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB88);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB90);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutWalk__vfunc_03);

extern "C" int func_001536CC()
{
    return 0;
}


extern "C" int func_001536D4()
{
    return 0;
}


extern "C" void NorOutWalk__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void NorOutDead__vfunc_02(int arg0)
{
    int temp_v1;
    int temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, int *, 8);
    M2C_FIELD(temp_v1, int *, 0x120) = (int) (M2C_FIELD(temp_v1, int *, 0x120) | 0x400);
    temp_v1_2 = M2C_FIELD(arg0, int *, 8);
    M2C_FIELD(temp_v1_2, int *, 0x120) = (int) (M2C_FIELD(temp_v1_2, int *, 0x120) | 0x2000);
    Xiiii_func_001680A0(arg0, 1, 0x100);
}

extern "C" int NorOutDead__vfunc_03()
{
    return -1;
}


extern "C" void NorOutDead__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void NorOutBrownEv__vfunc_02(int arg0)
{
    Xiiii_func_001680A0(arg0, 1, 0);
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD((*(int *)&D_007B205C), int *, 0x64C) = 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutBrownEv__vfunc_03);

extern "C" void NorOutCounter__vfunc_02(int arg0)
{
    M2C_FIELD(M2C_FIELD(arg0, int *, 0xC), int *, 0x150) = 0;
    Xiii_func_001694CC(arg0, 0x56);
    Xiii_func_001694CC(arg0, 0x63);
    Xiiii_func_001680A0(arg0, 0x2A, 0);
    M2C_FIELD(arg0, int *, 0x38) = 0;
    M2C_FIELD(arg0, int *, 0x40) = 0;
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiii_func_00166DA4(arg0, 0x64);
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutCounter__vfunc_03);

extern "C" void NorOutCounter__vfunc_04()
{
    X_func_00166AD0();
}


extern "C" void NorOutCoax__vfunc_02(int arg0)
{
    Xiiif_func_00167230(arg0, 0, 0.39269906282424927f);
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiii_func_0016649C(M2C_FIELD(arg0, int *, 0xC), 0);
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutCoax__vfunc_03);

extern "C" void NorOutTest__vfunc_02(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    Xiiii_func_001680A0(arg0, 0x21, 0);
}

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutTest__vfunc_03);
