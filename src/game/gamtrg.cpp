#include "include_asm.h"
extern "C" int Xiii_func_001D811C(int, int, int, int) asm("func_001D811C");
extern "C" int Xiiif_func_001333C0(int, int, float) asm("func_001333C0");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xiiii_func_001D5BC8(int, int, int) asm("func_001D5BC8");
struct m2c_block8 { int w[2]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern int D_002FC418;
extern int D_002FC420;
extern int D_002FC428;
extern int D_002FC430;
extern int D_002FC438;
extern int D_002FC440;
extern int D_002FC448;
extern int D_002FC450;
extern int D_002FC458;
extern int D_002FC460;
extern int D_002FC468;
extern int D_002FC470;
extern int D_002FC478;
extern int D_002FC480;
extern int D_002FC488;
extern int D_002FC490;
extern int D_002FC498;
extern int D_002FC4A0;
extern int D_002FC4A8;
extern int D_002FC4B0;
extern int D_002FC4B8;
extern int D_002FC4C0;
extern int D_002FC4C8;
extern int D_002FC4D0;
extern int D_002FC4D8;
extern int D_002FC4E0;
extern int D_002FC4E8;
extern int D_002FC4F0;
extern int D_002FC4F8;
extern int D_002FC500;
extern int D_002FC508;
extern int D_002FC510;
extern "C" int Xiii_func_001E7724(int, int) asm("func_001E7724");
extern "C" int Xiii_func_001E7D7C(int, int) asm("func_001E7D7C");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfiiii_func_001D817C(int, int, int, int) asm("func_001D817C");
extern "C" int Xii_func_001C6C28(int) asm("func_001C6C28");
extern "C" int Xii_func_001DA07C(int) asm("func_001DA07C");
extern "C" int Xiii_func_0017EA44(int, int) asm("func_0017EA44");
extern "C" int Xiii_func_001D89C4(int, int) asm("func_001D89C4");
extern "C" int Xiii_func_001D8D28(int, int) asm("func_001D8D28");
extern "C" int Xiiii_setActorRot__9MagSystemiPCf(int, int, int) asm("setActorRot__9MagSystemiPCf");
extern "C" int Xiiiii_func_001D8064(int, int, int, int) asm("func_001D8064");
extern int D_006FE6A0;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001333C0(...) asm("func_001333C0");
extern "C" int X_func_00139010(...) asm("func_00139010");
extern "C" int X_func_0017EA44(...) asm("func_0017EA44");
extern "C" int X_func_001C6C28(...) asm("func_001C6C28");
extern "C" int X_func_001CBB80(...) asm("func_001CBB80");
extern "C" int X_func_001D8064(...) asm("func_001D8064");
extern "C" int X_func_001D966C(...) asm("func_001D966C");
extern "C" int X_func_001DA07C(...) asm("func_001DA07C");
extern "C" int X_func_001E7414(...) asm("func_001E7414");
extern "C" int X_func_001E7724(...) asm("func_001E7724");
extern "C" int X_func_001E7D7C(...) asm("func_001E7D7C");
extern "C" int X_func_001E8F88(...) asm("func_001E8F88");
extern int D_00298EE0;
extern int D_002D8F60;
extern int D_006E9840;
extern int D_007812C0;
extern int D_007A320C;
extern int D_007A3D80;
extern int D_007B2060;

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D859C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D85F8);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8674);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8778);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D87F4);

extern int _vt$7ObjStat;
extern "C" void Xv_ObjStatDtor(int arg0, int arg1) asm("_$_7ObjStat");
extern "C" void Xv_ObjStatDtor(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x258) = (int)&_vt$7ObjStat;
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

extern "C" void func_001D88FC(int arg0)
{
    M2C_FIELD(arg0, int *, 0x114) = 0;
    M2C_FIELD(arg0, int *, 0x110) = 0;
    M2C_FIELD(arg0, int *, 0x10C) = 0;
}

extern "C" void func_001D890C(int arg0, int arg1)
{
    int temp_v1;
    int temp_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    if (temp_v1 == -1) {
        M2C_FIELD(arg1, float *, 0) = M2C_FIELD(arg0, float *, 0x190);
        M2C_FIELD(arg1, float *, 4) = M2C_FIELD(arg0, float *, 0x194);
        M2C_FIELD(arg1, float *, 8) = M2C_FIELD(arg0, float *, 0x198);
        return;
    }
    temp_v0 = (int)&D_006FE6A0 + (temp_v1 * 0x4D0);
    M2C_FIELD(arg1, float *, 0) = M2C_FIELD(temp_v0, float *, 0x40);
    M2C_FIELD(arg1, float *, 4) = M2C_FIELD(temp_v0, float *, 0x44);
    M2C_FIELD(arg1, float *, 8) = M2C_FIELD(temp_v0, float *, 0x48);
}

extern "C" void func_001D8964(int arg0, int arg1)
{
    int temp_v1;
    int temp_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    if (temp_v1 == -1) {
        M2C_FIELD(arg1, float *, 0) = M2C_FIELD(arg0, float *, 0x1A0);
        M2C_FIELD(arg1, float *, 4) = M2C_FIELD(arg0, float *, 0x1A4);
        M2C_FIELD(arg1, float *, 8) = M2C_FIELD(arg0, float *, 0x1A8);
        return;
    }
    temp_v0 = (int)&D_006FE6A0 + (temp_v1 * 0x4D0);
    M2C_FIELD(arg1, float *, 0) = M2C_FIELD(temp_v0, float *, 0x50);
    M2C_FIELD(arg1, float *, 4) = M2C_FIELD(temp_v0, float *, 0x54);
    M2C_FIELD(arg1, float *, 8) = M2C_FIELD(temp_v0, float *, 0x58);
}

extern "C" int func_001D89BC()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D89C4);

extern "C" void func_001D8A8C(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    M2C_FIELD(arg0, float *, 0x1A0) = (float) M2C_FIELD(arg1, float *, 0);
    M2C_FIELD(arg0, float *, 0x1A4) = (float) M2C_FIELD(arg1, float *, 4);
    M2C_FIELD(arg0, float *, 0x1A8) = (float) M2C_FIELD(arg1, float *, 8);
    if (temp_v1 != -1) {
        Xiiii_setActorRot__9MagSystemiPCf((int) (int)&D_006E9840, temp_v1, (int) (arg0 + 0x1A0));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8ADC);

extern "C" int func_001D8B5C(int arg0, int arg1)
{
    return Xiiiii_func_001D8064((int)&D_007812C0, arg1, M2C_FIELD(arg0, int *, 0x114),
                                (((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2) != 0;
}

extern "C" void func_001D8B9C(int arg0, int arg1)
{
    float temp_f0;
    int temp_v0;

    temp_v0 = Xiiiii_func_001D8064((int) (int)&D_007812C0, (int) arg1, M2C_FIELD(arg0, int *, 0x114), (((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2);
    Xiii_func_001D8D28(arg0, temp_v0);
    temp_f0 = Xfiiii_func_001D817C((int) (int)&D_007812C0, (int) temp_v0, (int) arg1, 0);
    if (temp_f0 != 100000.0f) {
        M2C_FIELD(arg1, float *, 4) = temp_f0;
    }
    Xiii_func_001D89C4(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8C50);

extern "C" int func_001D8D28(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x120);
    if (temp_v1 & 0x40) {
        if (!(temp_v1 & 0x10000000)) {
            Xiiii_func_001D5BC8((int)&D_007812C0, arg1, M2C_FIELD(arg0, int *, 0x100));
        }
        M2C_FIELD(arg0, int *, 0x114) = arg1;
        M2C_FIELD(arg0, int *, 0x110) = arg1;
        if (arg1 != 0) {
            M2C_FIELD(arg0, int *, 0x10C) = arg1;
            M2C_FIELD(arg0, float *, 0x1F0) = (float) M2C_FIELD(arg0, float *, 0x190);
            M2C_FIELD(arg0, float *, 0x1F4) = (float) M2C_FIELD(arg0, float *, 0x194);
            M2C_FIELD(arg0, float *, 0x1F8) = (float) M2C_FIELD(arg0, float *, 0x198);
            M2C_FIELD(arg0, float *, 0x1FC) = (float) M2C_FIELD(arg0, float *, 0x19C);
        }
        return 1;
    }
    M2C_FIELD(arg0, int *, 0x114) = arg1;
    M2C_FIELD(arg0, int *, 0x110) = arg1;
    return 0;
}

extern "C" void func_001D8DC4(int arg0)
{
    int temp_v1;
    float temp_f1;
    float temp_f1_2;
    int temp_v0_3;
    int temp_a0;
    int temp_v0;
    int temp_v0_2;

    temp_v1 = arg0 + 0x190;
    temp_a0 = M2C_FIELD(arg0, int *, 0x108);
    if ((temp_a0 != -1) && ((temp_v0 = (int)&D_006FE6A0 + (temp_a0 * 0x4D0), temp_f1 = M2C_FIELD(temp_v0, float *, 0x40), M2C_FIELD(arg0, float *, 0x190) = temp_f1, M2C_FIELD(temp_v1, float *, 4) = (float) M2C_FIELD(temp_v0, float *, 0x44), M2C_FIELD(temp_v1, float *, 8) = (float) M2C_FIELD(temp_v0, float *, 0x48), temp_v0_2 = M2C_FIELD(arg0, int *, 0x114), (temp_v0_2 == 0)) || !(M2C_FIELD(temp_v0_2, float *, 0x1C) <= temp_f1) || !(temp_f1 <= M2C_FIELD(temp_v0_2, float *, 0x24)) || (temp_f1_2 = M2C_FIELD(arg0, float *, 0x198), !(M2C_FIELD(temp_v0_2, float *, 0x20) <= temp_f1_2)) || !(temp_f1_2 <= M2C_FIELD(temp_v0_2, float *, 0x28)))) {
        temp_v0_3 = Xiiiii_func_001D8064((int) (int)&D_007812C0, (int) temp_v1, (int) temp_v0_2, (((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2);
        if (temp_v0_3 != 0) {
            Xiii_func_001D8D28(arg0, (int) temp_v0_3);
        }
    }
}

extern "C" void func_001D8EA8(int arg0)
{
    int temp_v0;

    temp_v0 = Xiiiii_func_001D8064((int) (int)&D_007812C0, (int) (arg0 + 0x190), M2C_FIELD(arg0, int *, 0x114), (((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, int *, 0x110) = 0;
        Xiii_func_001D8D28(arg0, (int) temp_v0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8F04);

extern "C" void func_001D8FEC(int arg0, int arg1)
{
    int buf[4];

    Xiii_func_001D8D28(arg0, Xiii_func_001D811C((int)&D_007812C0, arg1, (int)buf, 0));
    if (M2C_FIELD(arg0, int *, 0x114) != 0) {
        Xiii_func_001D89C4(arg0, (int)buf);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9044);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D932C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D95C4);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D966C);

extern "C" void func_001D96E0(int arg0)
{
    M2C_FIELD(arg0, int *, 0x114) = 0;
    M2C_FIELD(arg0, int *, 0x110) = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D96EC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9830);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9908);

extern "C" void func_001D9B2C(int arg0)
{
    Xiiii_memset(arg0 + 0x280, 0, 0x109);
    *(m2c_block8 *)((char *)(arg0) + 0x288) = *(m2c_block8 *)((char *)(&D_002FC418) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x290) = *(m2c_block8 *)((char *)(&D_002FC420) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x298) = *(m2c_block8 *)((char *)(&D_002FC428) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2a0) = *(m2c_block8 *)((char *)(&D_002FC430) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2a8) = *(m2c_block8 *)((char *)(&D_002FC438) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2b0) = *(m2c_block8 *)((char *)(&D_002FC440) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2b8) = *(m2c_block8 *)((char *)(&D_002FC448) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2c0) = *(m2c_block8 *)((char *)(&D_002FC450) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2d0) = *(m2c_block8 *)((char *)(&D_002FC458) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x340) = *(m2c_block8 *)((char *)(&D_002FC460) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2d8) = *(m2c_block8 *)((char *)(&D_002FC468) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2e0) = *(m2c_block8 *)((char *)(&D_002FC470) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2e8) = *(m2c_block8 *)((char *)(&D_002FC478) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2f0) = *(m2c_block8 *)((char *)(&D_002FC480) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2f8) = *(m2c_block8 *)((char *)(&D_002FC488) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x300) = *(m2c_block8 *)((char *)(&D_002FC490) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x308) = *(m2c_block8 *)((char *)(&D_002FC498) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x310) = *(m2c_block8 *)((char *)(&D_002FC4A0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x318) = *(m2c_block8 *)((char *)(&D_002FC4A8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x320) = *(m2c_block8 *)((char *)(&D_002FC4B0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x328) = *(m2c_block8 *)((char *)(&D_002FC4B8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x330) = *(m2c_block8 *)((char *)(&D_002FC4C0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x338) = *(m2c_block8 *)((char *)(&D_002FC4C8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x348) = *(m2c_block8 *)((char *)(&D_002FC4D0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x350) = *(m2c_block8 *)((char *)(&D_002FC4D8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x358) = *(m2c_block8 *)((char *)(&D_002FC4E0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x360) = *(m2c_block8 *)((char *)(&D_002FC4E8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x368) = *(m2c_block8 *)((char *)(&D_002FC4F0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x370) = *(m2c_block8 *)((char *)(&D_002FC4F8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x378) = *(m2c_block8 *)((char *)(&D_002FC500) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x380) = *(m2c_block8 *)((char *)(&D_002FC508) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x388) = *(m2c_block8 *)((char *)(&D_002FC510) + 0x0);
}

extern "C" void func_001D9E9C(int arg0)
{
    X_func_001D966C();
    if (X_func_001E7D7C((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E8))) != 0) {
        X_func_001E7724((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E8)));
    }
    if (X_func_001E7D7C((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E4))) != 0) {
        X_func_001E7724((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E4)));
    }
}


extern "C" void func_001D9F08(void) {
}

extern "C" void func_001D9F10(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x114) = 0;
    M2C_FIELD(arg0, int *, 0x110) = 0;
    if (arg1 != 0) {
        M2C_FIELD(arg0, int *, 0x10C) = 0;
    }
    Xii_func_001DA07C(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9F40);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9F84);

extern "C" int func_001DA05C(int arg0)
{
    return ~(*(int *)(int *)((char *)(arg0) + 0x3D8)) == 0;
}


extern "C" void func_001DA06C(void) {
}

extern "C" void func_001DA074(void) {
}

extern "C" void func_001DA07C(int arg0)
{
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3DC)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3DC));
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D4)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D4));
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3E0)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3E0));
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D8)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D8));
    }
    M2C_FIELD(arg0, int *, 0x3DC) = -1;
    M2C_FIELD(arg0, int *, 0x3D4) = -1;
    M2C_FIELD(arg0, int *, 0x3E0) = -1;
    M2C_FIELD(arg0, int *, 0x3D8) = -1;
}

extern "C" void func_001DA130(int arg0, int arg1, int arg2)
{
    if (arg2 != 0) {
        X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3DC)), arg1);
    }
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3D4)), arg1);
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E0)), arg1);
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3D8)), arg1);
}


extern "C" void func_001DA1B4(int arg0)
{
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D4)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D4));
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3E0)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3E0));
    }
    M2C_FIELD(arg0, int *, 0x3D4) = -1;
    M2C_FIELD(arg0, int *, 0x3E0) = -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DA228);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DA740);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC418);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC420);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC428);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC430);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC438);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC440);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC448);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC450);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC458);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC460);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC468);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC470);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC478);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC480);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC488);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC490);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC498);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4D0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4F0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC500);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC508);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC510);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DAC8C);

extern "C" int func_001DB17C(int arg0, int arg1)
{
    return (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x1B0));
}


extern "C" void func_001DB18C(int arg0, int arg1, int arg2)
{
    (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x1B0)) = arg2;
}


extern "C" void func_001DB19C(int arg0, int arg1, int arg2)
{
    int off;

    off = arg1 * 4 + 0x1B0;
    M2C_FIELD(arg0 + off, int *, 0) += arg2;
}

extern "C" void func_001DB1B8(int arg0, float fparg0)
{
    int off = 0x12540;

    M2C_FIELD(arg0, float *, 0x418) = fparg0;
    Xiiif_func_001333C0((int)&D_006E9840 + off, M2C_FIELD(arg0, int *, 0x108), fparg0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB1F0);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB31C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB520);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB71C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB774);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB7CC);

extern "C" void func_001DB898(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    M2C_FIELD(arg0, float *, 0x1A0) = (float) M2C_FIELD(arg1, float *, 0);
    M2C_FIELD(arg0, float *, 0x1A4) = (float) M2C_FIELD(arg1, float *, 4);
    M2C_FIELD(arg0, float *, 0x1A8) = (float) M2C_FIELD(arg1, float *, 8);
    if (temp_v1 != -1) {
        Xiiii_setActorRot__9MagSystemiPCf((int) (int)&D_006E9840, temp_v1, (int) (arg0 + 0x1A0));
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC6E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC700);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB8E8);

extern "C" float func_001DB9C4()
{
    float var_f0;
    int temp_v0;

    temp_v0 = Xiii_func_0017EA44((int)&D_00298EE0, Xii_func_001C6C28((int)&D_007812C0));
    var_f0 = 0.0f;
    if (temp_v0 != 0) {
        var_f0 = M2C_FIELD(temp_v0, float *, 0x20);
    }
    return var_f0;
}

extern "C" float func_001DBA00()
{
    float var_f0;
    int temp_v0;

    temp_v0 = Xiii_func_0017EA44((int)&D_00298EE0, Xii_func_001C6C28((int)&D_007812C0));
    var_f0 = 0.0f;
    if (temp_v0 != 0) {
        var_f0 = M2C_FIELD(temp_v0, float *, 0x28);
    }
    return var_f0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBA3C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBB38);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBB74);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBC5C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBCF0);

extern "C" void func_001DBD4C(void) {
}

extern "C" int func_001DBD54(int arg0)
{
    int base = (int)&D_007812C0;

    if ((M2C_FIELD(base + 0x21F4C, int *, 0) & 0x40000) == 0) {
        return M2C_FIELD(arg0, int *, 0x1C0);
    }
    return M2C_FIELD(base + 0x21F58, int *, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBD90);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBDF0);

extern "C" void func_001DBEF0(void) {
}

extern "C" void func_001DBEF8(int arg0, int arg1)
{
    int temp_a2;
    int temp_a1;
    int temp_v1;

    M2C_FIELD(arg0, int *, 0x58) = arg1;
    temp_a1 = arg1 + 0x10;
    temp_v1 = arg1 + 0x40;
    temp_a2 = M2C_FIELD(arg1, int *, 0x10);
    M2C_FIELD(arg0, int *, 0) = temp_v1;
    M2C_FIELD(arg0, int *, 4) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 4) - temp_a2));
    M2C_FIELD(arg0, int *, 8) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 8) - temp_a2));
    M2C_FIELD(arg0, int *, 0xC) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0xC) - temp_a2));
    M2C_FIELD(arg0, int *, 0x10) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x10) - temp_a2));
    M2C_FIELD(arg0, int *, 0x14) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x14) - temp_a2));
    M2C_FIELD(arg0, int *, 0x18) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x18) - temp_a2));
    M2C_FIELD(arg0, int *, 0x1C) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x1C) - temp_a2));
    M2C_FIELD(arg0, int *, 0x20) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x20) - temp_a2));
    M2C_FIELD(arg0, int *, 0x24) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x24) - temp_a2));
}

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC748);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBFA0);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DC070);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DC48C);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD0F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD100);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD110);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD190);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD2A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD320);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD3A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD480);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DCD38);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DCE30);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DCF28);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD00C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD118);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD154);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD194);

extern "C" void func_001DD1D8(void) {
}

extern "C" void func_001DD1E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD1E8);

extern "C" void func_001DD3EC(void *arg0, int arg1)
{
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD414);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD558);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD5E8);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD7BC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDAA8);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDC80);

extern "C" void func_001DDDAC(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x18B5C)) = 0;
}


INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDDBC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDF48);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE104);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE4E4);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE5DC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE6FC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE8AC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEA40);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEAAC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEC14);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DED70);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD640);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD668);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD670);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD678);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD680);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD688);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD690);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD698);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6D0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6F0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD700);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD708);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD710);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD718);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD720);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEE78);
