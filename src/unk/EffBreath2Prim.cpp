#include "include_asm.h"
#include "sdk/math.h"
struct EffVec4 { float x, y, z, w; };
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
extern "C" void Xvpff_func_00237360(float *, float *, float) asm("func_00237360");
extern "C" void Xviii_func_002373D8(int, float *, int) asm("func_002373D8");
extern "C" void Xviii_func_00237408(float *, int, int) asm("func_00237408");
extern "C" void Xvpp_func_002375D8(float *, float *) asm("func_002375D8");
extern "C" void Xvp_func_00237340(float *) asm("func_00237340");
extern "C" void Xvppf_func_00237848(float *, float *, float) asm("func_00237848");
extern "C" void Xviip_func_002377D0(int, int, float *) asm("func_002377D0");
struct EffBreath2Ground {
    unsigned short m_unk0;
    unsigned char m_pad2[0x9E];
    int m_unkA0;
    int m_unkA4;
};
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern int D_00298E08;
struct m2c_v94_10_i { char pad[148]; virtual void v1(); virtual int call(); };
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_func_00237408(...) asm("func_00237408");
extern "C" int X_func_00237580(...) asm("func_00237580");
// Translated mechanically from m2c drafts: only what matches byte for byte.

extern "C" int EffBreath2__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    M2C_FIELD(arg0, int *, 0x24) = M2C_FIELD(arg1, int *, 0x10);
    M2C_FIELD(arg0, int *, 0x28) = M2C_FIELD(arg1, int *, 0x14);
    M2C_FIELD(arg0, int *, 0x4C) = M2C_FIELD(arg1, int *, 0x34);
    M2C_FIELD(arg0, float *, 0x2C) = M2C_FIELD(arg1, float *, 0x18);
    M2C_FIELD(arg0, float *, 0x30) = M2C_FIELD(arg1, float *, 0x1C);
    M2C_FIELD(arg0, float *, 0x34) = M2C_FIELD(arg1, float *, 0x20);
    *(EffVec4 *)((char *)arg0 + 0x38) = *(EffVec4 *)((char *)arg1 + 0x24);
    int rnd = Xi_func_0016AD94();
    M2C_FIELD(arg0, int *, 0x48) = 0;
    M2C_FIELD(arg0, int *, 0x50) = rnd;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Prim__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Prim__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Prim__vfunc_08);

extern "C" void updateZDepth__14EffBreath2Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Ground__vfunc_02);

extern "C" int EffBreath2Ground__vfunc_05(EffBreath2Ground *arg0)
{
    if (++arg0->m_unkA0 >= arg0->m_unkA4) {
        return 0;
    }
    if (arg0->m_unk0 & 2) {
        int v = arg0->m_unkA4 - 0xF;
        if (arg0->m_unkA0 < v) {
            arg0->m_unkA0 = v;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Ground__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016F55C);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffCameraAnim1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016F80C);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffCameraAnim1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FB70);

extern "C" float func_0016FC20(const float *v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FC74);

extern "C" void func_0016FD4C(int arg0, float fparg0)
{
    float mat[16];
    Xvp_func_00237340(mat);
    Xvppf_func_00237848(mat, mat, fparg0);
    Xviip_func_002377D0(arg0, arg0, mat);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FDA0);

extern "C" float func_0016FE88(float fparg0)
{
    while (fparg0 < -3.1415923f) {
        fparg0 += 6.2831847f;
    }
    while (fparg0 > 3.1415923f) {
        fparg0 -= 6.2831847f;
    }
    return fparg0;
}

extern "C" void func_0016FF18(int arg0, int arg1)
{
    struct { char pad0[16]; } stack;
    int temp_v0;

    ((m2c_v94_10_i *)(arg0))->call();
    X_func_00237408((int)&stack, arg1, arg0 + 0x30);
    X_func_00237580(arg0 + 0x20, (int)&stack);
}

extern "C" void func_0016FF78(int arg0, int arg1, int arg2, float fparg0)
{
    float v[4];
    Xviii_func_00237408(v, arg2, arg1);
    Xvpp_func_002375D8(v, v);
    Xvpff_func_00237360(v, v, fparg0);
    Xviii_func_002373D8(arg0, v, arg1);
}

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016FFEC);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_001700B0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F2278);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F2288);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F2298);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22A8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22D0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F22F8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffBreath2Prim", D_002F2310);

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_00170158);
