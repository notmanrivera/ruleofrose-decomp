#include "include_asm.h"
extern "C" {
extern char D_002F2E10[];
extern char D_002F2E28[];
extern char D_002F2E50[];
void ror_assert(const char *file, int line, const char *expr);
void func_00178C54(int arg0, int arg1, short arg2, float fparg0);
void X_freeID__12DogLightPoolii(void *, int, int) asm("freeID__12DogLightPoolii");
}
struct MfLightPoint {
    float m_pos[4];
    float m_color[4];
};
class MfLightPool {
public:
    void *m_light[6];
    int m_num[6];
    MfLightPoint *getPoint(int n) {
        ((n >= 0 && n < m_num[2]) ? (void)0 : ror_assert(D_002F2E10, 0x83, D_002F2E28));
        ((m_light[2]) ? (void)0 : ror_assert(D_002F2E10, 0x83, D_002F2E50));
        return &((MfLightPoint *)m_light[2])[n];
    }
};
extern "C" void X_func_0021A5B0(int, int, int) asm("func_0021A5B0");
extern "C" void X_func_0021A700(int, int) asm("func_0021A700");
extern "C" int X_func_0022B370(int) asm("func_0022B370");
extern "C" int Xiii_func_0016FFEC(int, int) asm("func_0016FFEC");
extern "C" int Xiiii_alloc__9BedMemoryii(int, int, int) asm("alloc__9BedMemoryii");
extern "C" int X_func_0022AEC0(int) asm("func_0022AEC0");
extern "C" int *X_func_0022AED8(int, int) asm("func_0022AED8");
extern "C" int X_func_0022AAD0(int *, int) asm("func_0022AAD0");
extern "C" int X_func_0021AB30(int, int) asm("func_0021AB30");
struct MfVec { int w[4]; } __attribute__((aligned(8)));
extern "C" int Xip_func_0021E488(int, void *) asm("func_0021E488");
extern "C" int func_00178DD8(int, int, int, int);
extern "C" int func_00178E68(int, int, int, int);
extern MfVec D_002F2E70;
struct SteamV4 { float x; float y; int z; int w; } __attribute__((aligned(8)));
extern "C" void Xppp_func_002378B0(void *, void *, void *) asm("func_002378B0");
extern "C" void Xp_func_00237340(void *) asm("func_00237340");
extern "C" void Xpp_func_00237830(void *, void *, float) asm("func_00237830");
extern float D_002F2FB0;
struct m2c_block16 { int w[4]; };
extern "C" int X_func_0021B260(int, int) asm("func_0021B260");
extern "C" int X_func_0021B4F8(int, int) asm("func_0021B4F8");
extern "C" int X_func_0021B5A0(int, int) asm("func_0021B5A0");
extern "C" int X_func_0021E5A0(int, int, int) asm("func_0021E5A0");
extern "C" void X_func_0021E688(int) asm("func_0021E688");
extern "C" int X_func_00223290(int) asm("func_00223290");
extern "C" int Xiiii_func_0017BA54(int, int, int) asm("func_0017BA54");
extern "C" int Xiiii_func_0017BB50(int, int, int) asm("func_0017BB50");
extern "C" int Xiiii_func_0017B7CC(int, int, int) asm("func_0017B7CC");
extern "C" int Xiiii_func_0017B918(int, int, int) asm("func_0017B918");
extern "C" int Xiii_free__9BedMemoryPv(int, int) asm("free__9BedMemoryPv");
extern "C" int Xiii_releaseTex__10DogTexInfoi(int, int) asm("releaseTex__10DogTexInfoi");
struct Unk87B0 {
    int unk00;
    signed char unk04;
    char pad05[0x1F];
    int unk24;
    int unk28;
    int unk2C;
    int unk30[8];
    int unk50;
    int unk54;
    int unk58;
};
extern "C" int X_func_00237360(int, int, float) asm("func_00237360");
extern "C" int X_func_002373D8(int, int, int) asm("func_002373D8");
extern "C" int Xii_func_0017A410(int) asm("func_0017A410");
extern "C" int X_func_0021A760(int, int, int) asm("func_0021A760");
extern "C" int X_func_0022E960(int, int, int, float) asm("func_0022E960");
extern "C" int X_func_0022F7A0(int, int, int) asm("func_0022F7A0");
extern "C" int Xiiiiii_i3dCallLocked__FPvN40(int, int, int, int, int) asm("i3dCallLocked__FPvN40");
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
struct Stack8DD8 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    short unk14;
};
extern "C" void X_func_00178EEC(int, Stack8DD8 *) asm("func_00178EEC");
extern "C" int X_func_0021B550(int, int, int) asm("func_0021B550");
struct Stack8E68 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    short unk14;
};
extern "C" void X_8E68_func_00178EEC(int, Stack8E68 *) asm("func_00178EEC");
extern "C" int X_8E68_func_0021B550(int, int, int) asm("func_0021B550");
extern "C" float Xf_func_0022E958(...) asm("func_0022E958");
extern "C" int Xiiii_func_001787B0(int, int, int) asm("func_001787B0");
struct m2c_block12 { int w[3]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_0016A914(int) asm("func_0016A914");
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern int D_00298E08;
extern int _vt$9EffWater1;
extern int X_vt_10EffReload1 asm("_vt$10EffReload1");
extern int X_vt_9EffWater3 asm("_vt$9EffWater3");
extern int D_006E9800;
extern int D_00298E1C;
extern "C" void X_free__9BedMemoryPv(void *, void *) asm("free__9BedMemoryPv");
extern "C" void X_dtor_4Eff0(void *, int) asm("_$_4Eff0");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_9EffWater1(int, int) asm("_$_9EffWater1");
extern "C" void dtor_10EffReload1(int, int) asm("_$_10EffReload1");
extern "C" void dtor_9EffWater3(int, int) asm("_$_9EffWater3");
// Translated mechanically from m2c drafts: only what matches byte for byte.

extern "C" void func_001787B0(int arg0, int arg1, int arg2)
{
    int *var_s1;
    int temp_s3;
    int var_s2;
    int temp_a1;
    Unk87B0 *temp_s0;

    temp_a1 = arg0 + (arg1 * 0x60);
    temp_s0 = (Unk87B0 *)(temp_a1 + 0xC94);
    if (temp_s0->unk00 == 0) {
        return;
    }
    if (arg2 == 0 && (temp_s0->unk24 & 1)) {
        return;
    }
    var_s1 = temp_s0->unk30;
    var_s2 = 0;
    temp_s3 = (*(int *)(arg0)) + 0x29520;
    temp_s0->unk50 = 0;
    temp_s0->unk54 = 0;
    if (temp_s0->unk58 > 0) {
        do {
            Xiii_releaseTex__10DogTexInfoi(temp_s3, *var_s1++);
            var_s2++;
        } while (var_s2 < temp_s0->unk58);
    }
    temp_s0->unk58 = 0;
    if (temp_s0->unk28 != 0) {
        Xiii_free__9BedMemoryPv((int)&D_006E9800, temp_s0->unk28);
        temp_s0->unk28 = 0;
    }
    temp_s0->unk00 = 0;
    temp_s0->unk04 = 0;
    temp_s0->unk24 = 0;
    temp_s0->unk2C = 0;
}

extern "C" void func_00178894(int arg0, int arg1)
{
    int i;

    for (i = 0; i < 16; i++) {
        Xiiii_func_001787B0(arg0, i, arg1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffMuzzleFlash1__vfunc_02);

extern "C" int EffMuzzleFlash1__vfunc_05(int arg0)
{
    if (M2C_FIELD(arg0, short *, 0x4C) >= 0x100) {
        func_00178C54(arg0, arg0 + 0x40, -0x180, 20.0f);
        MfLightPool *pool = (MfLightPool *)(D_00298E08 + 0x2050);
        MfLightPoint *pt = pool->getPoint(M2C_FIELD(arg0, int *, 0x60));
        float c = (float)M2C_FIELD(arg0, short *, 0x4C) * 150.0f * (1.0f / 32768.0f);
        pt->m_color[3] = 0.0f;
        pt->m_color[0] = pt->m_color[1] = pt->m_color[2] = c;
    } else {
        int id = M2C_FIELD(arg0, int *, 0x60);
        if (id != -1) {
            X_freeID__12DogLightPoolii((void *)(D_00298E08 + 0x2050), 2, id);
            M2C_FIELD(arg0, int *, 0x60) = -1;
        }
    }
    if (M2C_FIELD(arg0, short *, 0x5C) >= 0x100) {
        func_00178C54(arg0, arg0 + 0x50, 0x40, 2.5f);
        M2C_FIELD(arg0, float *, 0x58) -= 2.25f;
        M2C_FIELD(arg0, float *, 0x50) += 0.026179936f;
    }
    if (M2C_FIELD(arg0, short *, 0x5C) >= 0x100 || M2C_FIELD(arg0, short *, 0x4C) >= 0x100) {
        return 1;
    }
    return 0;
}

extern "C" void func_00178C54(int arg0, int arg1, short arg2, float fparg0)
{
    int temp = M2C_FIELD(arg1, unsigned short *, 0xE);

    M2C_FIELD(arg1, unsigned short *, 0xC) = (unsigned short) (M2C_FIELD(arg1, unsigned short *, 0xC) + temp);
    M2C_FIELD(arg1, unsigned short *, 0xE) = (unsigned short) (arg2 + temp);
    M2C_FIELD(arg1, float *, 4) = (float) (M2C_FIELD(arg1, float *, 4) + fparg0);
}

extern "C" void EffMuzzleFlash1__vfunc_08(int arg0, int arg1, int arg2, int arg3)
{
    MfVec v;
    float f20;
    float f0;
    int x;
    int t;

    t = X_func_0021B5A0(arg3, M2C_FIELD(arg1, int *, 8));
    int q = M2C_FIELD(arg1, int *, 8);
    v = D_002F2E70;
    x = Xip_func_0021E488(X_func_0021E5A0(t, q, 1), &v);
    long long lo = M2C_FIELD(arg0, long long *, 0x30);
    long long hi = M2C_FIELD(arg0, long long *, 0x38);
    ((long long *)&v)[0] = lo;
    ((long long *)&v)[1] = hi;
    f20 = Xii_func_0016FF18(D_00298E08 + 0x2AB70, (int)&v);
    ((float *)&v)[1] += M2C_FIELD(arg0, float *, 0x58);
    f0 = Xii_func_0016FF18(D_00298E08 + 0x2AB70, (int)&v);
    if (f20 < f0) {
        x = func_00178DD8(arg0, arg1, arg2, x);
        x = func_00178E68(arg0, arg1, arg2, x);
    } else {
        x = func_00178E68(arg0, arg1, arg2, x);
        x = func_00178DD8(arg0, arg1, arg2, x);
    }
    X_func_0021E688(x);
}

extern "C" int func_00178DD8(int arg0, int arg1, int arg2, int arg3)
{
    Stack8DD8 stack;

    if (M2C_FIELD(arg0, short *, 0x5C) < 0x100) {
        return arg3;
    }
    stack.unk08 = arg2;
    stack.unk04 = (*(int *)&D_00298E08) + 0x2AB70;
    stack.unk0C = X_func_0021B550(arg3, 0x42, 0x44);
    stack.unk00 = arg0 + 0x50;
    stack.unk10 = 1.0f;
    stack.unk14 = 1;
    X_func_00178EEC(arg0, &stack);
    return stack.unk0C;
}

extern "C" int func_00178E68(int arg0, int arg1, int arg2, int arg3)
{
    Stack8E68 stack;

    if (M2C_FIELD(arg0, short *, 0x4C) < 0x100) {
        return arg3;
    }
    stack.unk08 = arg2;
    stack.unk04 = (*(int *)&D_00298E08) + 0x2AB70;
    stack.unk0C = X_8E68_func_0021B550(arg3, 0x42, 0x48);
    stack.unk00 = arg0 + 0x40;
    stack.unk10 = 0;
    stack.unk14 = 0;
    X_8E68_func_00178EEC(arg0, &stack);
    return stack.unk0C;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_00178EEC);

extern "C" void updateZDepth__15EffMuzzleFlash1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_001790E4);

extern "C" void dtor_10EffReload1(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&X_vt_10EffReload1;
    if (M2C_FIELD(arg0, void **, 0x2C) != 0) {
        X_free__9BedMemoryPv(&D_006E9800, M2C_FIELD(arg0, void **, 0x2C));
    }
    if (M2C_FIELD(arg0, void **, 0x38) != 0) {
        X_free__9BedMemoryPv(&D_006E9800, M2C_FIELD(arg0, void **, 0x38));
    }
    X_dtor_4Eff0((void *)arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

extern "C" int EffReload1__vfunc_02(int arg0, int arg1)
{
    struct { float x, y, z; int w; } stack;
    int temp_a0;
    int n;
    int temp_s0;
    int temp_v0;
    int temp_s2;
    int temp_a1;
    int temp_v0_2;
    int temp_v1;

    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    n = M2C_FIELD(arg1, int *, 0x28);
    if (n > 6) {
        n = 6;
    }
    if (n <= 0) {
        M2C_FIELD(arg0, int *, 0x24) = 0;
        return 1;
    }
    temp_s2 = arg0 + 0x40;
    temp_a0 = M2C_FIELD(M2C_FIELD(arg1, int *, 0xC), int *, 0x30);
    temp_v1 = (*(int *)&D_00298E08) + 0x29520;
    M2C_FIELD(arg0, int *, 0x24) = temp_a0;
    temp_a1 = M2C_FIELD(arg1, int *, 0xC);
    M2C_FIELD(arg0, int *, 0x28) = M2C_FIELD(((M2C_FIELD(temp_a1, int *, 0x50) + n) * 4) + temp_a1, int *, 0x2C);
    X_func_0021A5B0(temp_a0, M2C_FIELD(temp_v1, int *, 8), M2C_FIELD(temp_v1, int *, 4));
    M2C_FIELD(arg0, int *, 0x38) = Xiii_func_0016FFEC(M2C_FIELD(arg0, int *, 0x24), M2C_FIELD(arg0, int *, 0x28));
    temp_v0 = X_func_0022B370(M2C_FIELD(arg0, int *, 0x24));
    temp_v0_2 = Xiiii_alloc__9BedMemoryii((int)&D_006E9800, temp_v0 * 0xB0, -1);
    temp_s0 = temp_v0_2 + (temp_v0 * 0x30);
    M2C_FIELD(arg0, int *, 0x2C) = temp_v0_2;
    M2C_FIELD(arg0, int *, 0x30) = temp_s0;
    M2C_FIELD(arg0, int *, 0x34) = temp_s0 + (temp_v0 << 6);
    X_func_0021A700(M2C_FIELD(arg0, int *, 0x24), temp_s0);
    Xp_func_00237340((void *)temp_s2);
    float fx = M2C_FIELD(arg1, float *, 0x1C);
    float fy = M2C_FIELD(arg1, float *, 0x20);
    float fz = M2C_FIELD(arg1, float *, 0x24);
    stack.y = fy;
    stack.x = fx;
    stack.z = fz;
    stack.w = 0;
    Xppp_func_002378B0((void *)temp_s2, (void *)temp_s2, &stack);
    M2C_FIELD(arg0, float *, 0x70) = M2C_FIELD(arg1, float *, 0x10);
    M2C_FIELD(arg0, float *, 0x74) = M2C_FIELD(arg1, float *, 0x14);
    M2C_FIELD(arg0, float *, 0x78) = M2C_FIELD(arg1, float *, 0x18);
    M2C_FIELD(arg0, int *, 0x80) = 0;
    return 1;
}

extern "C" int EffReload1__vfunc_05(int arg0)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 0x24) != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x80) + 1;
        M2C_FIELD(arg0, int *, 0x80) = temp_v0;
        if (((float) temp_v0 / 60.0f) < Xf_func_0022E958(M2C_FIELD(arg0, int *, 0x28))) {
            return 1;
        }
    }
    return 0;
}

extern "C" void renderPreMain__10EffReload1PQ24Eff011RENDERPARAM(int arg0, int arg1)
{
    if (M2C_FIELD(arg0, int *, 0x24) != 0) {
        X_func_0022E960(M2C_FIELD(arg0, int *, 0x28), M2C_FIELD(arg0, int *, 0x2C), 0x111, (float) M2C_FIELD(arg0, int *, 0x80) / 60.0f);
        X_func_0022F7A0(M2C_FIELD(arg0, int *, 0x2C), M2C_FIELD(arg0, int *, 0x30), M2C_FIELD(arg0, int *, 0x38));
        X_func_0021A760(M2C_FIELD(arg0, int *, 0x24), M2C_FIELD(arg0, int *, 0x34), M2C_FIELD(arg0, int *, 0x30));
        Xiiiiii_i3dCallLocked__FPvN40(M2C_FIELD(arg1, int *, 8), M2C_FIELD(arg0, int *, 0x24), M2C_FIELD(arg0, int *, 0x34), arg0 + 0x40, 0);
    }
}

extern "C" int EffSteam1__vfunc_02(int arg0, int arg1)
{
    SteamV4 w;
    SteamV4 v;
    int temp_v0;
    int temp_v0_2;
    int temp_s2;

    temp_s2 = arg0 + 0x30;
    if (Xiii_Eff0__vfunc_02(arg0, arg1) != 0) {
        M2C_FIELD(arg0, float *, 0x70) = M2C_FIELD(arg1, float *, 0x24);
        M2C_FIELD(arg0, float *, 0x74) = M2C_FIELD(arg1, float *, 0x28);
        temp_v0 = M2C_FIELD(arg1, int *, 0x3C);
        M2C_FIELD(arg0, int *, 0x28) = temp_v0;
        int lo = (temp_v0 >= 0) ? temp_v0 : 0;
        temp_v0_2 = temp_v0 + M2C_FIELD(arg1, int *, 0x40);
        M2C_FIELD(arg0, int *, 0x28) = lo;
        M2C_FIELD(arg0, int *, 0x2C) = (temp_v0_2 >= 1) ? temp_v0_2 : 1;
        int rnd = Xi_func_0016AD94();
        float c2 = (float)M2C_FIELD(arg0, int *, 0x2C);
        v.z = 0;
        v.w = 0;
        *(long long *)&w.z = *(long long *)&v.z;
        M2C_FIELD(arg0, int *, 0x24) = (int)((c2 * (float) rnd) / 255.0f);
        float fx = M2C_FIELD(arg1, float *, 0x1C);
        float fy = M2C_FIELD(arg1, float *, 0x20);
        v.x = fx;
        v.y = fy;
        *(long long *)&w.x = *(long long *)&v.x;
        Xp_func_00237340((void *)temp_s2);
        Xppp_func_002378B0((void *)temp_s2, (void *)temp_s2, &w);
        *(m2c_block12 *)((char *)(arg0) + 0x60) = *(m2c_block12 *)((char *)(arg1) + 0x10);
        *(m2c_block16 *)((char *)(arg0) + 0x78) = *(m2c_block16 *)((char *)(arg1) + 0x2C);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1__vfunc_05);

extern "C" int EffSteam1Prim__vfunc_02(int arg0, int arg1)
{
    float temp_f2;
    int temp_v1;

    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    M2C_FIELD(arg0, float *, 0x58) = M2C_FIELD(arg1, float *, 0x20);
    temp_v1 = M2C_FIELD(arg1, int *, 0x10);
    *(m2c_block16 *)((char *)(arg0) + 48) = *(m2c_block16 *)((char *)(temp_v1) + 0);
    M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
    temp_f2 = M2C_FIELD(arg1, float *, 0x24) * 15.0f;
    M2C_FIELD(arg0, float *, 0x40) = M2C_FIELD(arg1, float *, 0x14) * temp_f2;
    M2C_FIELD(arg0, float *, 0x44) = M2C_FIELD(arg1, float *, 0x18) * temp_f2;
    M2C_FIELD(arg0, float *, 0x48) = M2C_FIELD(arg1, float *, 0x1C) * temp_f2;
    M2C_FIELD(arg0, float *, 0x54) = 20.0f;
    M2C_FIELD(arg0, float *, 0x5C) = 0.3999999836087227f;
    M2C_FIELD(arg0, float *, 0x60) = 0.029999999795109034f;
    M2C_FIELD(arg0, int *, 0x4C) = 0;
    M2C_FIELD(arg0, float *, 0x64) = M2C_FIELD(arg1, float *, 0x28);
    *(m2c_block16 *)((char *)(arg0) + 104) = *(m2c_block16 *)((char *)(arg1) + 44);
    return 1;
}

extern "C" int EffSteam1Prim__vfunc_05(int arg0)
{
    float temp_f1;
    int var_v0;
    int temp_a0;
    int temp_s1;

    temp_s1 = arg0 + 0x40;
    var_v0 = 0;
    temp_f1 = M2C_FIELD(arg0, float *, 0x5C) + M2C_FIELD(arg0, float *, 0x60);
    M2C_FIELD(arg0, float *, 0x5C) = temp_f1;
    if (!(temp_f1 <= 0.0f)) {
        if (temp_f1 >= 1.0f) {
            M2C_FIELD(arg0, float *, 0x5C) = 1.0f;
            M2C_FIELD(arg0, float *, 0x60) = (float) (M2C_FIELD(arg0, float *, 0x64) * -0.06999999471008778f);
        }
        X_func_00237360(temp_s1, temp_s1, 0.95f);
        temp_a0 = arg0 + 0x30;
        X_func_002373D8(temp_a0, temp_a0, temp_s1);
        M2C_FIELD(arg0, float *, 0x54) = (float) (M2C_FIELD(arg0, float *, 0x54) + 4.5f);
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1Prim__vfunc_08);

extern "C" void updateZDepth__13EffSteam1Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int EffSteam2__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    *(m2c_block12 *)((char *)(arg0) + 36) = *(m2c_block12 *)((char *)(arg1) + 16);
    M2C_FIELD(arg0, float *, 0x30) = M2C_FIELD(arg1, float *, 0x1C);
    M2C_FIELD(arg0, float *, 0x34) = M2C_FIELD(arg1, float *, 0x20);
    M2C_FIELD(arg0, signed char *, 0x38) = (signed char)((Xi_func_0016AD94() * 0x96) / 255);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam2__vfunc_05);

extern "C" int EffSteam2Prim__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        *(m2c_block12 *)((char *)(arg0) + 48) = *(m2c_block12 *)((char *)(arg1) + 16);
        var_v0 = 1;
        M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
        M2C_FIELD(arg0, float *, 0x44) = (float) M2C_FIELD(arg1, float *, 0x20);
        M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
        M2C_FIELD(arg0, signed char *, 0x48) = 0;
    }
    return var_v0;
}

extern "C" int EffSteam2Prim__vfunc_05(int arg0)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, unsigned char *, 0x48) + 1;
    M2C_FIELD(arg0, unsigned char *, 0x48) = temp_v1;
    if ((unsigned int) (temp_v1 & 0xFF) >= 0x96U) {
        return 0;
    }
    M2C_FIELD(arg0, float *, 0x34) = (float) (M2C_FIELD(arg0, float *, 0x34) + ((M2C_FIELD(arg0, float *, 0x40) * -0.09999999590218067f) / 30.0f));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam2Prim__vfunc_08);

extern "C" void updateZDepth__13EffSteam2Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int EffCloud1__vfunc_02(int arg0, int arg1)
{
    float mat[16];
    int t;

    if (Xiii_Eff0__vfunc_02(arg0, arg1)) {
        *(m2c_block12 *)((char *)(arg0) + 0x40) = *(m2c_block12 *)((char *)(arg1) + 0x10);
        *(m2c_block16 *)((char *)(arg0) + 0x60) = *(m2c_block16 *)((char *)(arg1) + 0x2C);
        M2C_FIELD(arg0, float *, 0x58) = M2C_FIELD(arg1, float *, 0x20);
        Xp_func_00237340(mat);
        float sc = M2C_FIELD(arg1, float *, 0x24);
        float rot = M2C_FIELD(arg1, float *, 0x1C);
        mat[10] = sc;
        Xpp_func_00237830(mat, mat, rot);
        *(m2c_block12 *)((char *)(arg0) + 0x4C) = *(m2c_block12 *)(mat + 8);
        Xii_func_0017A410(arg0);
        M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
        t = (int)(M2C_FIELD(arg1, float *, 0x28) / M2C_FIELD(arg1, float *, 0x24)) + 1;
        M2C_FIELD(arg0, int *, 0x74) = t;
        int e = t + (t % 30);
        M2C_FIELD(arg0, int *, 0x70) = t;
        M2C_FIELD(arg0, float *, 0x10) = D_002F2FB0;
        M2C_FIELD(arg0, int *, 0x78) = e;
        return 1;
    }
    return 0;
}

// NON_MATCHING: 5/73 differ, 5 edits
#ifdef NON_MATCHING
extern "C" void Xpp_func_00237818(void *, void *, float) asm("func_00237818");
extern "C" void func_0017A410(int arg0)
{
    float mat[16];

    Xp_func_00237340(mat);
    mat[12] = (M2C_FIELD(arg0, float *, 0x58) * (float) Xi_func_0016AD94()) / 510.0f;
    Xpp_func_00237818(mat, mat, (((float) Xi_func_0016AD94() * 6.283185124397278f) / 255.0f) - 3.141592562198639f);
    Xpp_func_00237830(mat, mat, (((float) Xi_func_0016AD94() * 6.283185124397278f) / 255.0f) - 3.141592562198639f);
    float x = M2C_FIELD(arg0, float *, 0x40) + mat[12];
    float y = mat[13] + M2C_FIELD(arg0, float *, 0x44);
    float z = M2C_FIELD(arg0, float *, 0x48) + mat[14];
    M2C_FIELD(arg0, float *, 0x30) = x;
    M2C_FIELD(arg0, float *, 0x34) = y;
    M2C_FIELD(arg0, float *, 0x38) = z;
    M2C_FIELD(arg0, int *, 0x5C) = Xi_func_0016AD94();
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_0017A410);
#endif

extern "C" int EffCloud1__vfunc_05(int arg0)
{
    int temp_a1;
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0xC);
    temp_a1 = M2C_FIELD(arg0, int *, 0x70) + 1;
    M2C_FIELD(arg0, int *, 0x70) = temp_a1;
    M2C_FIELD(arg0, int *, 8) = temp_v1;
    switch (temp_v1) {
    case 0:
        if (temp_a1 < M2C_FIELD(arg0, int *, 0x74)) {
            M2C_FIELD(arg0, float *, 0x30) += M2C_FIELD(arg0, float *, 0x4C);
            M2C_FIELD(arg0, float *, 0x34) += M2C_FIELD(arg0, float *, 0x50);
            M2C_FIELD(arg0, float *, 0x38) += M2C_FIELD(arg0, float *, 0x54);
        } else {
            M2C_FIELD(arg0, int *, 0xC) = 0xA;
        }
        break;
    case 10:
        if (temp_a1 >= M2C_FIELD(arg0, int *, 0x78)) {
            Xii_func_0017A410(arg0);
            M2C_FIELD(arg0, int *, 0x70) = 0;
            M2C_FIELD(arg0, int *, 0xC) = 0;
        }
        break;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffCloud1__vfunc_08);

extern "C" void updateZDepth__9EffCloud1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" void func_0017A918(int arg0)
{
    Xii_func_0016A914(arg0);
    M2C_FIELD(arg0, int *, 0x60) = 0;
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$9EffWater1;
}

extern "C" void dtor_9EffWater1(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$9EffWater1;
    if (M2C_FIELD(arg0, void **, 0x60) != 0) {
        X_free__9BedMemoryPv(&D_006E9800, M2C_FIELD(arg0, void **, 0x60));
    }
    X_dtor_4Eff0((void *)arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E10);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E28);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E50);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2E98);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2EB0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2EC0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2ED0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2F10);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2F30);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2F70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FB0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FB8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FD8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FE8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffWater1", D_002F2FF8);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffWater1__vfunc_02);

extern "C" int EffWater1__vfunc_05(int arg0)
{
    int s4;
    int n;
    int i;
    int *p;
    float f;

    s4 = M2C_FIELD(arg0, int *, 0x60) + 0x10;
    n = X_func_0022AEC0(s4);
    float d = M2C_FIELD(arg0, float *, 0x64) / 30.0f;
    f = M2C_FIELD(arg0, float *, 0x70) + d;
    M2C_FIELD(arg0, float *, 0x70) = f;
    if (f >= 1.0f || f <= -1.0f) {
        M2C_FIELD(arg0, float *, 0x70) = f - (float)(int)f;
    }
    M2C_FIELD(arg0, float *, 0x74) += M2C_FIELD(arg0, float *, 0x68) / 30.0f;
    f = M2C_FIELD(arg0, float *, 0x74);
    if (f >= 1.0f || f <= -1.0f) {
        M2C_FIELD(arg0, float *, 0x74) = f - (float)(int)f;
    }
    i = 0;
    if (n > 0) {
        do {
            p = X_func_0022AED8(s4, i++);
            X_func_0021AB30(X_func_0022AAD0(p, 0), arg0 + 0x70);
            M2C_FIELD(*p, unsigned short *, 8) = M2C_FIELD(*p, unsigned short *, 8) + 1;
        } while (i < n);
    }
    return 1;
}

extern "C" void liveActivateExec__9EffWater1(int arg0)
{
    int temp_a2;
    int temp_v0;
    int temp_v0_2;
    unsigned short temp_a1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x80);
    temp_a1 = M2C_FIELD(arg0, unsigned short *, 0);
    temp_v0_2 = temp_v0 - 1;
    temp_a2 = temp_v0 + 1;
    if (temp_a1 & 4) {
        M2C_FIELD(arg0, int *, 0x80) = temp_a2;
        if (temp_a2 >= 5) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    } else {
        M2C_FIELD(arg0, int *, 0x80) = temp_v0_2;
        if (temp_v0_2 <= 0) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", renderPreMain__9EffWater1PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", func_0017AFD8);

extern "C" void dtor_9EffWater3(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&X_vt_9EffWater3;
    if (M2C_FIELD(arg0, void **, 0x24) != 0) {
        X_free__9BedMemoryPv(&D_006E9800, M2C_FIELD(arg0, void **, 0x24));
        M2C_FIELD(arg0, void **, 0x24) = 0;
    }
    D_00298E1C--;
    X_dtor_4Eff0((void *)arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffWater3__vfunc_02);

extern "C" int EffWater3__vfunc_05(int arg0)
{
    int var_s3;
    int var_s0;
    int var_s4;
    int var_s2;

    var_s4 = 0;
    var_s3 = M2C_FIELD(arg0, int *, 0x24);
    if (M2C_FIELD(arg0, int *, 0x28) > 0) {
        do {
            var_s0 = var_s3 + 0x10;
            for (var_s2 = 7; var_s2 >= 0; var_s2--, var_s0 += 0x10) {
                M2C_FIELD(var_s0, float *, 4) += M2C_FIELD(arg0, float *, 0x38);
                if (M2C_FIELD(arg0, float *, 0x30) < M2C_FIELD(var_s0, float *, 4)) {
                    Xiiii_func_0017B7CC(arg0, var_s0, var_s3);
                }
            }
            var_s0 = var_s3 + 0x90;
            for (var_s2 = 3; var_s2 >= 0; var_s2--, var_s0 += 0x10) {
                M2C_FIELD(var_s0, float *, 4) += -0.5f;
                if (M2C_FIELD(var_s0, float *, 4) < -3.0f) {
                    Xiiii_func_0017B918(arg0, var_s0, var_s3);
                }
            }
            var_s4 += 1;
            var_s3 += 0xD0;
        } while (var_s4 < M2C_FIELD(arg0, int *, 0x28));
    }
    return 1;
}

extern "C" void EffWater3__vfunc_08(int arg0, int arg1, int arg2, int arg3)
{
    int temp_s1;
    int var_s2;
    int var_s4;
    int var_s0;

    var_s4 = 0;
    var_s2 = X_func_0021B5A0(X_func_0021B550(arg3, 0x42, 0x44), M2C_FIELD(arg1, int *, 8));
    var_s2 = X_func_0021E5A0(X_func_0021B4F8(var_s2, X_func_0021B260(arg2, 0)), M2C_FIELD(arg1, int *, 8), 1);
    temp_s1 = X_func_00223290(M2C_FIELD(arg1, int *, 8));
    var_s0 = M2C_FIELD(arg0, int *, 0x24);
    if (M2C_FIELD(arg0, int *, 0x28) > 0) {
        do {
            if (Xiiii_func_0017BA54(arg0, var_s0, temp_s1) != 0) {
                var_s2 = Xiiii_func_0017BB50(arg0, var_s2, var_s0);
            }
            var_s0 += 0xD0;
            var_s4 += 1;
        } while (var_s4 < M2C_FIELD(arg0, int *, 0x28));
    }
    return X_func_0021E688(var_s2);
}
