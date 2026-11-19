#include "include_asm.h"
#include "sdk/math.h"
struct EffCameraAnim1_v2 { unsigned char m_pad0[0x24]; int m_unk24; int m_unk28; int m_unk2C; int m_unk30; float m_unk34; float m_unk38; float m_unk3C; float m_unk40; float m_unk44; float m_unk48; float m_unk4C; };
extern "C" int X_v2_func_0013D5AC(int, int) asm("func_0013D5AC__8MagScenePi");
extern "C" int X_v2_func_0016F80C(int, int) asm("func_0016F80C");
extern "C" int X_v2_func_0013CAF0(int, int, int, int) asm("func_0013CAF0__8MagSceneii");
struct Vec4_fda0 { float x, y, z, w; } __attribute__((aligned(8)));
struct Mat4_fda0 { Vec4_fda0 x, y, z, w; };
extern "C" void *X_memset(void *, int, unsigned int) asm("memset");
extern "C" void X_func_00237560(float *, float *, float *) asm("func_00237560");
extern "C" void X_func_00237390(float *, float *, float) asm("func_00237390");
extern "C" int X_func_0022B3D8(void *, int) asm("func_0022B3D8");
extern "C" int X_func_0022B6F8(void *) asm("func_0022B6F8");
extern "C" int X_func_0022B730(void *, int) asm("func_0022B730");
extern "C" short *X_alloc(void *, int, int) asm("alloc__9BedMemoryii");
extern int D_006E9800;
extern "C" int Xii_strlen(int) asm("strlen");
extern "C" int Xpi_func_0022AEC0(void *) asm("func_0022AEC0");
extern "C" void *Xpi_func_0022AED8(void *, int) asm("func_0022AED8");
extern "C" const char *Xpi_func_0022AF08(void *, int) asm("func_0022AF08");
extern "C" const char *X_strstr(const char *, const char *) asm("strstr");
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

// NON_MATCHING: 47/50 differ, 1 reloc differs (size 0xC8, game 0xC0), 24 edits
#ifdef NON_MATCHING
struct EffBreath2Prim_v5 { unsigned char m_pad0[0x30]; float m_unk30[4]; float m_unk40[4]; unsigned char m_pad50[0x4]; float m_unk54; float m_unk58; };
extern "C" void X_func_002373D8(float *, float *, float *) asm("func_002373D8");
extern "C" int EffBreath2Prim__vfunc_05(EffBreath2Prim_v5 *arg0)
{
    X_func_002373D8(arg0->m_unk30, arg0->m_unk30, arg0->m_unk40);
    if (arg0->m_unk30[1] > 0.0f) {
        return 0;
    }
    float temp_f0 = arg0->m_unk58;
    float temp_f0_2 = 1.0f - (temp_f0 * 0.024999998975545168f);
    float var_f2 = 1.0f;
    if (!(temp_f0_2 > 1.0f)) {
        var_f2 = temp_f0_2;
    }
    float vx = arg0->m_unk40[0] * var_f2;
    float vz = arg0->m_unk40[2] * var_f2;
    float vy = arg0->m_unk40[1] + temp_f0 * 0.5f;
    float s = arg0->m_unk54 + 2.5f;
    arg0->m_unk40[0] = vx;
    arg0->m_unk40[2] = vz;
    arg0->m_unk40[1] = vy;
    arg0->m_unk54 = s;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffBreath2Prim__vfunc_05);
#endif

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

extern "C" int EffCameraAnim1__vfunc_02(EffCameraAnim1_v2 *arg0, int arg1)
{
    int temp_s0;
    int temp_s3;

    if (!Xiii_Eff0__vfunc_02((int) arg0, arg1)) {
        return 0;
    }
    temp_s3 = M2C_FIELD(arg1, int *, 0x10);
    if (M2C_FIELD(temp_s3, int *, 0) != 1) {
        return 0;
    }
    temp_s0 = (*(int *)&D_00298E08) + 0x2AB70;
    arg0->m_unk30 = X_v2_func_0013D5AC((int) (*(int *)&D_00298E08), 0);
    arg0->m_unk34 = M2C_FIELD(temp_s0, float *, 0x40);
    arg0->m_unk38 = M2C_FIELD(temp_s0, float *, 0x44);
    arg0->m_unk3C = M2C_FIELD(temp_s0, float *, 0x48);
    arg0->m_unk40 = M2C_FIELD(temp_s0, float *, 0x50);
    arg0->m_unk44 = M2C_FIELD(temp_s0, float *, 0x54);
    arg0->m_unk48 = M2C_FIELD(temp_s0, float *, 0x58);
    arg0->m_unk4C = M2C_FIELD(temp_s0, float *, 0x140);
    arg0->m_unk24 = 0;
    arg0->m_unk28 = M2C_FIELD(temp_s3, int *, 4);
    arg0->m_unk2C = temp_s3 + 0x10;
    X_v2_func_0013CAF0((int) (*(int *)&D_00298E08), 0, 0, 0);
    X_v2_func_0016F80C((int) arg0, arg0->m_unk2C);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", func_0016F80C);

// NON_MATCHING: 10/52 differ, 7 edits
#ifdef NON_MATCHING
extern "C" int Xiifff_setRot__9DogEntityfff(int, float, float, float) asm("setRot__9DogEntityfff");
extern "C" int Xiii_func_0016F80C(int, int) asm("func_0016F80C");
extern "C" int Xiiiii_func_0013CAF0__8MagSceneii(int, int, int, int) asm("func_0013CAF0__8MagSceneii");
struct Cam_v5 { unsigned char m_pad0[0x40]; float m_unk40; float m_unk44; float m_unk48; unsigned char m_pad4C[0x44]; int m_unk90; unsigned char m_pad94[0xAC]; float m_unk140; void setPos(float x, float y, float z) { m_unk40 = x; m_unk44 = y; m_unk48 = z; } };
extern "C" int EffCameraAnim1__vfunc_05(int arg0)
{
    int temp_v0;
    Cam_v5 *temp_s0;
    int temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, int *, 0x24) + 1;
    M2C_FIELD(arg0, int *, 0x24) = temp_v0;
    if (temp_v0 < M2C_FIELD(arg0, int *, 0x28)) {
        temp_v0_2 = M2C_FIELD(arg0, int *, 0x2C) + 0x1C;
        M2C_FIELD(arg0, int *, 0x2C) = temp_v0_2;
        Xiii_func_0016F80C((int) arg0, temp_v0_2);
        return 1;
    }
    temp_s0 = (Cam_v5 *)((*(int *)&D_00298E08) + 0x2AB70);
    M2C_FIELD(temp_s0, int *, 0x90) = 1;
    temp_s0->setPos(M2C_FIELD(arg0, float *, 0x34), M2C_FIELD(arg0, float *, 0x38), M2C_FIELD(arg0, float *, 0x3C));
    Xiifff_setRot__9DogEntityfff((int) temp_s0, M2C_FIELD(arg0, float *, 0x40), M2C_FIELD(arg0, float *, 0x44), M2C_FIELD(arg0, float *, 0x48));
    temp_s0->m_unk140 = M2C_FIELD(arg0, float *, 0x4C);
    Xiiiii_func_0013CAF0__8MagSceneii((int) (*(int *)&D_00298E08), M2C_FIELD(arg0, int *, 0x30), 0, 0);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffBreath2Prim", EffCameraAnim1__vfunc_05);
#endif

extern "C" int func_0016FB70(int arg0, int arg1)
{
    int temp_a1;
    int temp_s1;
    int var_a2;
    int var_a3;
    int var_a0;

    temp_s1 = Xii_strlen((int) arg0);
    var_a3 = 0;
    temp_a1 = Xii_strlen(arg1);
    if (temp_s1 > 0) {
loop_1:
        var_a2 = 0;
        if (temp_a1 > 0) {
            var_a0 = arg0 + var_a3;
            if ((*(signed char *)(var_a0)) == (*(signed char *)(arg1))) {
loop_3:
                var_a2 += 1;
                var_a0 += 1;
                if (var_a2 < temp_a1) {
                    if ((*(signed char *)(var_a0)) == ((signed char *)(arg1))[var_a2]) {
                        goto loop_3;
                    }
                }
            }
        }
        if (var_a2 == temp_a1) {
            return var_a3;
        }
        var_a3 += 1;
        if (var_a3 < temp_s1) {
            goto loop_1;
        }
    }
    return -1;
}

extern "C" float func_0016FC20(const float *v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

extern "C" void func_0016FC74(float *arg0)
{
    float *temp_s1 = arg0 + 8;
    float f20 = func_0016FC20(arg0);
    float f21 = func_0016FC20(temp_s1);
    arg0[9] = 0.0f;
    if (func_0016FC20(temp_s1) <= 1.1754945e-38f) {
        temp_s1[0] = 0.0f;
        arg0[10] = 1.0f;
    } else {
        Xvpp_func_002375D8(temp_s1, temp_s1);
    }
    arg0[4] = 0.0f;
    arg0[5] = 1.0f;
    arg0[6] = 0.0f;
    X_func_00237560(arg0, arg0 + 4, temp_s1);
    X_func_00237390(arg0, arg0, f20);
    X_func_00237390(temp_s1, temp_s1, f21);
}

extern "C" void func_0016FD4C(int arg0, float fparg0)
{
    float mat[16];
    Xvp_func_00237340(mat);
    Xvppf_func_00237848(mat, mat, fparg0);
    Xviip_func_002377D0(arg0, arg0, mat);
}

extern "C" void func_0016FDA0(Mat4_fda0 *arg0, const Vec4_fda0 *arg1)
{
    float stack[4];
    float temp_f1;

    X_memset(stack, 0, 0x10);
    temp_f1 = arg1->y;
    if (temp_f1 > 0.9999990016222f) {
        stack[2] = -1.0f;
    } else if (temp_f1 < -0.9999990016222f) {
        stack[2] = 1.0f;
    } else {
        stack[1] = 1.0f;
    }
    X_func_00237560(&arg0->x.x, stack, (float *)&arg1->x);
    X_func_00237560(&arg0->y.x, (float *)&arg1->x, &arg0->x.x);
    arg0->z = *arg1;
    arg0->w.x = arg0->w.y = arg0->w.z = 0.0f;
    arg0->w.w = 1.0f;
}

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

extern "C" short *func_0016FFEC(void *arg0, void *arg1)
{
    short *temp_v0;
    short *var_s0;
    int temp_v0_2;
    int temp_v0_3;
    int var_s3;

    var_s3 = 0;
    temp_v0_2 = X_func_0022B6F8(arg1);
    temp_v0 = X_alloc(&D_006E9800, (temp_v0_2 * 2) + 2, -1);
    *temp_v0 = temp_v0_2;
    if (temp_v0_2 > 0) {
        var_s0 = temp_v0 + 1;
        do {
            int temp_a1 = var_s3 & 0xFFFF;
            var_s3 += 1;
            temp_v0_3 = X_func_0022B3D8(arg0, X_func_0022B730(arg1, temp_a1));
            if (temp_v0_3 >= 0) {
                *var_s0 = temp_v0_3;
            } else {
                *var_s0 = -1;
            }
            var_s0 += 1;
        } while (var_s3 < temp_v0_2);
    }
    return temp_v0;
}

extern "C" void *func_001700B0(void *arg0, const char *arg1, int *arg2)
{
    int n = Xpi_func_0022AEC0(arg0);
    for (int i = 0; i < n; i++) {
        if (X_strstr(Xpi_func_0022AF08(arg0, i), arg1)) {
            if (arg2) {
                *arg2 = i;
            }
            return Xpi_func_0022AED8(arg0, i);
        }
    }
    return 0;
}

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
