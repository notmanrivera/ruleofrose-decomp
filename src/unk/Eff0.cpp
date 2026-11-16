#include "include_asm.h"
#include "dog/doglightpool.h"
struct Obj_Stay1_v5 {
    unsigned short m_00;
    unsigned char pad02[0x06];
    int m_08;
    int m_0C;
    unsigned char pad10[0xA4];
    int m_B4;
    float m_B8;
    int m_BC;
};
struct Scene_AF20 {
    unsigned char unk[0x2050];
    DogLightPool m_light_pool;
};
extern Scene_AF20 *D_00298E08_AF20 asm("D_00298E08");
struct m2c_v20_28_i { char pad[32]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual int call(); };
struct m2c_v20_58_i { char pad[32]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual int call(); };
struct Vec3_E65C {
    float x;
    float y;
    float z;
};
struct Sub50_E65C {
    unsigned char pad[0x40];
    Vec3_E65C pos;
};
struct Obj_E65C {
    unsigned char pad00[0x24];
    float minX;
    float minY;
    float minZ;
    float maxX;
    float maxY;
    float maxZ;
    unsigned char pad3C[0x14];
    Sub50_E65C *sub;
};
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
struct m2c_block12 { int w[3]; };
struct m2c_ulong { long v; } __attribute__((packed));
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern "C" int Xii_func_0016A914(int) asm("func_0016A914");
extern "C" int Xii_func_00173DF8(int) asm("func_00173DF8");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern int _vt$4Eff0;
extern int _vt$14EffBloodSpray1;
extern int _vt$14EffBloodSpray2;
extern int _vt$6EffBg1;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
extern "C" int Xii_func_0016BEDC(int) asm("func_0016BEDC");
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
extern "C" int Xiii_func_0016B50C(int, int) asm("func_0016B50C");
extern "C" int Xiii_func_00174BB0(int, int) asm("func_00174BB0");
extern "C" int Xiii_func_00174BD8(int, int) asm("func_00174BD8");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_Eff0__vfunc_02(...) asm("Eff0__vfunc_02");
extern "C" int X_I3rRoot__CheckIdString(...) asm("I3rRoot__CheckIdString");
extern "C" int X_func_00139568(...) asm("func_00139568");
extern "C" int X_func_0016B50C(...) asm("func_0016B50C");
extern "C" int X_func_0016E92C(...) asm("func_0016E92C");
extern "C" int X_func_0016E9F4(...) asm("func_0016E9F4");
extern "C" int X_func_0016FF18(...) asm("func_0016FF18");
extern "C" int X_func_001700B0(...) asm("func_001700B0");
extern "C" int X_func_00174BB0(...) asm("func_00174BB0");
extern "C" int X_func_00174BD8(...) asm("func_00174BD8");
extern "C" int X_func_0017756C(...) asm("func_0017756C");
extern "C" int X_func_0022AAB8(...) asm("func_0022AAB8");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern "C" int X_strcasecmp(...) asm("strcasecmp");
extern const char D_002F21D0[];
extern int D_00298E08;
extern int D_00308050;
extern int D_008282A0;
extern int D_00828378;

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016A8A4);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016A914);

extern "C" void X_Eff0__vfunc_03(int) asm("Eff0__vfunc_03");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_4Eff0(int, int) asm("_$_4Eff0");

extern "C" void dtor_4Eff0(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$4Eff0;
    X_Eff0__vfunc_03(arg0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

extern "C" int Eff0__vfunc_02(int arg0, int arg1)
{
    int temp_v1;

    (*(int *)(int *)((char *)(arg0) + 0x18)) = (int) (*(int *)(int *)((char *)(arg1) + 0x0));
    (*(int *)(int *)((char *)(arg0) + 0x1C)) = (int) (*(int *)(int *)((char *)(arg1) + 0x8));
    temp_v1 = (*(int *)(int *)((char *)(arg1) + 0xC));
    if (temp_v1 != 0) {
        (*(int *)(int *)((char *)(arg0) + 0x14)) = temp_v1;
        (*(int *)(int *)((char *)(temp_v1) + 0x2C)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x2C)) + 1);
    }
    return 1;
}


extern "C" void Eff0__vfunc_03(int arg0)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x14);
    M2C_FIELD(arg0, short *, 0) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    if (temp_v1 != 0) {
        M2C_FIELD(temp_v1, int *, 0x2C) = (int) (M2C_FIELD(temp_v1, int *, 0x2C) - 1);
    }
}

extern "C" void Eff0__vfunc_10(int arg0, int arg1)
{
    unsigned short temp_v0 = (*(unsigned short *)(arg0));

    (*(unsigned short *)(arg0)) = arg1 != 0 ? (temp_v0 & 0xFFFB) : (temp_v0 | 4);
    (*(unsigned short *)(arg0)) |= 8;
}

extern "C" int Eff0__vfunc_04(int arg0)
{
    int temp_v0;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v1;
    int var_v0;
    int temp_v0_2;
    int temp_v0_5;

    temp_v0 = M2C_FIELD(arg0, int *, 0x1C);
    temp_v1 = temp_v0 - 1;
    if ((temp_v0 < 0) || (M2C_FIELD(arg0, int *, 0x1C) = temp_v1, var_v0 = 1, (temp_v1 < 0))) {
        if (M2C_FIELD(arg0, unsigned short *, 0) & 8) {
            ((m2c_v20_58_i *)(arg0))->call();
        }
        if (M2C_FIELD(arg0, int *, 4) >= 0) {
            if (--M2C_FIELD(arg0, int *, 4) <= 0) {
                M2C_FIELD(arg0, int *, 4) = -1;
                M2C_FIELD(arg0, unsigned short *, 0) |= 2;
            }
        }
        var_v0 = ((m2c_v20_28_i *)(arg0))->call();
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", render__4Eff0PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", renderPreMain__4Eff0PQ24Eff011RENDERPARAM);

// NON_MATCHING: 36/38 differ, 1 reloc differs (size 0x98, game 0xA0), 6 edits
#ifdef NON_MATCHING
struct Arg223558_PE {
    float unk00;
    void *unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct Sub14Hdr_PE {
    unsigned char pad00[0x30];
    int data[8];
    int unk50;
    int unk54;
    int unk58;
};

struct Obj_PE {
    unsigned char pad00[0x14];
    Sub14Hdr_PE *m_14;
};

extern "C" int X_func_00223558_PE(int, Arg223558_PE *) asm("func_00223558");

extern "C" int createPacketEntry__4Eff0P20tag_I3dRenderStage_s(Obj_PE *arg0, int arg1)
{
    int arr[8];
    Arg223558_PE q;
    int ret = 0;
    Sub14Hdr_PE *sub = arg0->m_14;
    if (sub->unk58 != 0) {
        int i = 0;
        int *src = &sub->data[sub->unk50 + sub->unk54];
        if (sub->unk58 > 0) {
            int *dst = arr;
            do {
                *dst++ = *src++;
                i++;
            } while (i < sub->unk58);
        }
        q.unk00 = 1.0f;
        q.unk04 = arr;
        q.unk08 = arg0->m_14->unk58;
        q.unk0C = 0;
        q.unk10 = 0;
        q.unk14 = 0;
        ret = X_func_00223558_PE(arg1, &q);
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", createPacketEntry__4Eff0P20tag_I3dRenderStage_s);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016AC84);

extern "C" int func_0016AD94()
{
    int *p = &D_00308050;
    int old = *p;
    int idx = old + 1;
    int t = (idx < 0) ? (old + 0x100) : idx;
    int d = idx - ((t >> 8) << 8);

    *p = d;
    return ((unsigned char *)&D_00828378)[d];
}

extern "C" void func_0016ADD8()
{
    X_memset((int)&D_008282A0, 0, 0xD8);
}


INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016AE00);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E88);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E90);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E98);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EA0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EA8);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EB0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EB8);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EC0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1ED0);

extern "C" void func_0016AF20(float *arg0)
{
    DogLightAmbient *amb = D_00298E08_AF20->m_light_pool.getAmbient(0);
    arg0[0] *= amb->m_color[0];
    arg0[1] *= amb->m_color[1];
    arg0[2] *= amb->m_color[2];
}

extern "C" void func_0016AFCC(int arg0)
{
    Xii_func_00173DF8(arg0);
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$6EffBg1;
}

extern "C" void X_dtor_11EffGeneric1(int, int) asm("_$_11EffGeneric1");
extern "C" void dtor_6EffBg1(int, int) asm("_$_6EffBg1");

extern "C" void dtor_6EffBg1(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$6EffBg1;
    X_dtor_11EffGeneric1(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F38);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F40);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBg1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBg1__vfunc_05);

extern "C" void renderPreMain__6EffBg1PQ24Eff011RENDERPARAM(int arg0, int arg1)
{
    int var_s2;
    unsigned short temp_v1;
    int temp_v0;
    int var_s0;

    var_s2 = 0;
    temp_v0 = M2C_FIELD(arg0, int *, 0x40);
    var_s0 = temp_v0 + 0x10;
    if (M2C_FIELD(temp_v0, unsigned short *, 2) != 0) {
        do {
            temp_v1 = M2C_FIELD(var_s0, unsigned short *, 0);
            switch (temp_v1) {                      
            case 4:
                Xiii_func_00174BB0(arg0, var_s0);
                break;
            case 5:
                Xiii_func_00174BD8((int) arg0, var_s0);
                break;
            case 6:
                Xiii_func_0016B50C((int) arg0, var_s0);
                break;
            }
            var_s2 += 1;
            var_s0 += M2C_FIELD(var_s0, unsigned short *, 2);
        } while (var_s2 < (int) M2C_FIELD(M2C_FIELD(arg0, int *, 0x40), unsigned short *, 2));
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016B50C);

extern "C" int func_0016B62C(int arg0)
{
    Xii_func_0016A914(arg0);
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$14EffBloodSpray1;
    return Xiiii_memset(arg0 + 0x40, 0, 0x240);
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray1__vfunc_08);

extern "C" void updateZDepth__14EffBloodSpray1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int func_0016BE14(int arg0)
{
    Xii_func_0016A914(arg0);
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$14EffBloodSpray2;
    M2C_FIELD(arg0, float *, 0x38) = 1.0f;
    M2C_FIELD(arg0, int *, 0x28) = 0;
    M2C_FIELD(arg0, int *, 0x2C) = 0;
    M2C_FIELD(arg0, int *, 0x30) = 0;
    M2C_FIELD(arg0, int *, 0x34) = 0;
    return Xiiii_memset(arg0 + 0x40, 0, 0x550);
}

extern "C" int EffBloodSpray2__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        M2C_FIELD(arg0, int *, 0x30) = (int) M2C_FIELD(arg1, int *, 0x10);
        M2C_FIELD(arg0, int *, 0x34) = (int) M2C_FIELD(arg1, int *, 0x14);
        M2C_FIELD(arg0, float *, 0x38) = (float) M2C_FIELD(arg1, float *, 0x18);
        M2C_FIELD(arg0, int *, 0x28) = (int) M2C_FIELD(arg1, int *, 0x1C);
        M2C_FIELD(arg0, int *, 0x2C) = Xi_func_0016AD94();
        Xii_func_0016BEDC(arg0);
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016BEDC);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray2__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray2__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", updateZDepth__14EffBloodSpray2);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay1__vfunc_02);

extern "C" int EffBloodStay1__vfunc_05(Obj_Stay1_v5 *arg0)
{
    int step = ++arg0->m_B4;
    switch (arg0->m_08 = arg0->m_0C) {
    case 0:
        if (step >= 121) {
            arg0->m_0C = 10;
        }
        break;
    case 10:
        if ((arg0->m_BC >= 0 && step >= arg0->m_BC) || (arg0->m_00 & 2)) {
            arg0->m_0C = 20;
        }
        break;
    case 20:
        arg0->m_B8 -= 0.01f;
        if (arg0->m_B8 <= 0.0f) {
            return 0;
        }
        break;
    }
    return 1;
}

// NON_MATCHING: 2/126 differ, 2 edits
#ifdef NON_MATCHING
extern "C" float Stay08_distance(int, int) asm("func_0016FF18");
extern "C" int X_func_0016CCB8(...) asm("func_0016CCB8");
extern "C" int X_func_0021B260(...) asm("func_0021B260");
extern "C" int X_func_0021B4F8(...) asm("func_0021B4F8");
extern "C" int Stay08_write(int,int,unsigned long long) asm("func_0021B550");
extern "C" int X_func_0021B5A0(...) asm("func_0021B5A0");
extern "C" int X_func_0021E488(...) asm("func_0021E488");
extern "C" int Stay08_start(int,int,int) asm("func_0021E5A0");
extern "C" int X_func_0021E688(...) asm("func_0021E688");
extern int D_002F20A0;
extern int D_002F20B0;
extern int D_002F20C0;
struct Stay08Words { int w[4]; };
struct Stay08Pair { long long x,y; };
extern "C" void EffBloodStay1__vfunc_08(int arg0, int arg1, int arg2, int arg3)
{
    struct { Stay08Words words; int sp10; float sp14; float sp18; int sp1C; int sp20; int sp24; char pad28[8]; Stay08Words scales; } stack;
    int var_v0;
    int temp_a0;
    int temp_s0;
    int temp_v0;
    int temp_v0_2;
    int var_s1;
    int var_s4;
    int var_s0;
    int temp_a2;

    var_s4 = 0;
    temp_s0 = Stay08_write(X_func_0021B5A0(arg3, M2C_FIELD(arg1, int *, 8)), 0x42, 0x44);
    temp_a0 = Stay08_write(X_func_0021B4F8(temp_s0, X_func_0021B260(arg2, 0)), 0x47, 0x51001);
    int texture = M2C_FIELD(arg1, int *, 8);
    *(Stay08Pair *)&stack.words = *(Stay08Pair *)&D_002F20A0;
    temp_v0 = X_func_0021E488(Stay08_start(temp_a0, texture, 1), (int)&stack);
    temp_a2 = arg0 + 0x24;
    stack.sp10 = temp_a2;
    stack.sp20 = arg1;
    stack.sp24 = temp_v0;
    float distance = Stay08_distance((*(int *)&D_00298E08) + 0x2AB70, arg0 + 0xA0);
    int count = M2C_FIELD(arg0, int *, 0x64);
    stack.sp14 = distance;
    stack.words = *(Stay08Words *)&D_002F20B0;
    stack.scales = *(Stay08Words *)&D_002F20C0;
    int age;
    if ((count > 0) && ((int) stack.words.w[0] < (age = M2C_FIELD(arg0, int *, 0xB4)))) {
        var_s0 = (int)&stack;
        var_s1 = 0;
loop_3:
        var_v0 = (int)&stack.scales + var_s1;
        var_s1 += 4;
        var_s4 += 1;
        stack.sp18 = M2C_FIELD(arg0, float *, 0xB0) * (*(float *)(var_v0));
        temp_v0_2 = (*(int *)(var_s0));
        var_s0 += 4;
        stack.sp1C = age - temp_v0_2;
        temp_v0 = X_func_0016CCB8(arg0, (int)&stack.sp10);
        int next = stack.sp10 + 0x10;
        count = M2C_FIELD(arg0, int *, 0x64);
        stack.sp24 = temp_v0;
        stack.sp10 = next;
        if (var_s4 < count) {
            age = M2C_FIELD(arg0, int *, 0xB4);
            if ((*(int *)(var_s0)) < age) {
                goto loop_3;
            }
        }
    }
    Stay08_write(X_func_0021E688(stack.sp24), 0x47, 0x5000D);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay1__vfunc_08);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016CCB8);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016CEBC);

// NON_MATCHING: 7/45 differ, 2 edits
#ifdef NON_MATCHING
struct Arg_Stay2 {
    unsigned char pad00[0x10];
    float *m_10;
    int m_14;
    float m_18;
    float m_1C;
};

struct Obj_Stay2 {
    unsigned char pad00[0x4B0];
    float *m_4B0;
    int m_4B4;
    float m_4B8;
    float m_4BC;
    float m_4C0;
    float m_4C4;
    int m_4C8;
    int m_4CC;
    float m_4D0[4];
    float m_4E0[4];
};

extern "C" int X_Eff0__vfunc_02_Stay2(Obj_Stay2 *, Arg_Stay2 *) asm("Eff0__vfunc_02");

extern "C" int EffBloodStay2__vfunc_02(Obj_Stay2 *arg0, Arg_Stay2 *arg1)
{
    if (!X_Eff0__vfunc_02_Stay2(arg0, arg1)) {
        return 0;
    }
    float *v = arg1->m_10;
    float z = 0.0f;
    float one = 1.0f;
    arg0->m_4B0 = v;
    arg0->m_4B4 = arg1->m_14;
    arg0->m_4B8 = arg1->m_18;
    arg0->m_4BC = arg1->m_1C / 31.0f;
    arg0->m_4C4 = z;
    arg0->m_4C0 = z;
    arg0->m_4D0[0] = v[0];
    arg0->m_4D0[1] = v[1];
    float vz = v[2];
    arg0->m_4D0[3] = one;
    arg0->m_4D0[2] = vz;
    arg0->m_4E0[0] = z;
    arg0->m_4C8 = 0;
    arg0->m_4E0[3] = z;
    arg0->m_4E0[2] = z;
    arg0->m_4E0[1] = z;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay2__vfunc_02);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay2__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016D3E4);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay2__vfunc_08);

extern int _vt$13EffBloodStay3;
extern int D_00298E10;
extern "C" void dtor_13EffBloodStay3(int, int) asm("_$_13EffBloodStay3");

extern "C" void dtor_13EffBloodStay3(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$13EffBloodStay3;
    D_00298E10 = -1;
    dtor_4Eff0(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

extern "C" int EffBloodStay3__vfunc_02(int arg0, int arg1)
{
    if (Xiii_Eff0__vfunc_02(arg0, arg1) == 0) {
        return 0;
    }
    Xiiii_memset(arg0 + 0x24, 0, 8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay3__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016D8E8);

extern "C" int EffBloodStay3Prim__vfunc_02(int arg0, int arg1)
{
    int temp_v1;

    if (Xiii_Eff0__vfunc_02(arg0, arg1) == 0) {
        return 0;
    }
    M2C_FIELD(arg0, int *, 0x24) = (int) M2C_FIELD(arg1, int *, 0x10);
    M2C_FIELD(arg0, int *, 0x28) = (int) M2C_FIELD(arg1, int *, 0x14);
    temp_v1 = M2C_FIELD(arg1, int *, 0x18);
    *(m2c_block12 *)((char *)(arg0) + 48) = *(m2c_block12 *)((char *)(temp_v1) + 0);
    M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
    M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
    M2C_FIELD(arg0, float *, 0x44) = (float) M2C_FIELD(arg1, float *, 0x20);
    M2C_FIELD(arg0, int *, 0x48) = 0;
    return 1;
}

extern "C" int EffBloodStay3Prim__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x48)) + 1;
    (*(int *)(int *)((char *)(arg0) + 0x48)) = temp_v0;
    return temp_v0 < 0xA5;
}


INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay3Prim__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1__vfunc_08);

extern "C" void updateZDepth__10EffBreath1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70,
        arg0 + (M2C_FIELD(arg0, int *, 0x180) << 5) + 0x80);
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E438);

extern "C" int func_0016E65C(Obj_E65C *arg0)
{
    float p[3];
    Sub50_E65C *sub = arg0->sub;
    p[0] = sub->pos.x;
    p[1] = sub->pos.y;
    p[2] = sub->pos.z;
    if (arg0->minX <= p[0] && p[0] <= arg0->maxX &&
        arg0->minZ <= p[2] && p[2] <= arg0->maxZ &&
        arg0->minY <= p[1] && p[1] <= arg0->maxY) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1Space__vfunc_02);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F90);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1FA0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1FF0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2000);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2010);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2020);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2068);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2080);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20A0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20B0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20C0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20D0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20E0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20F0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2130);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2170);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2180);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2190);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21A0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21C0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21D0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21E0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21F0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2200);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2210);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2230);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2240);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1Space__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E92C);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E9F4);
