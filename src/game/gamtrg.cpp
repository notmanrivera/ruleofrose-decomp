#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", _$_7ObjStat);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D88FC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D890C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8964);

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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8B5C);

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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8D28);

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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8FEC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9044);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D932C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D95C4);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D966C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D96E0);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D96EC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9830);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9908);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9B2C);

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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DA07C);

extern "C" void func_001DA130(int arg0, int arg1, int arg2)
{
    if (arg2 != 0) {
        X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3DC)), arg1);
    }
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3D4)), arg1);
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E0)), arg1);
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3D8)), arg1);
}


INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DA1B4);

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


INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB19C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB1B8);

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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBD54);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBD90);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBDF0);

extern "C" void func_001DBEF0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBEF8);

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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD3EC);

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
