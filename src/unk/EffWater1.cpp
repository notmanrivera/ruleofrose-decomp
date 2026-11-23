#include "include_asm.h"
#include "unk/EffWater1.h"

extern "C" int X_88EC_func_0013FE64__8MagSceneii(int, int, int) asm("func_0013FE64__8MagSceneii");
extern "C" int X_9C30_func_0016AD94() asm("func_0016AD94");
extern "C" void X_9C30_func_00176CC8(int, void *) asm("func_00176CC8");
extern "C" void X_9C30_func_00237340(void *) asm("func_00237340");
extern "C" void X_9C30_func_00237830(void *, void *, float) asm("func_00237830");

struct Steam2Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float pos[4];
    float unk20;
    char pad24[0x5C];
};

extern "C" {
extern char D_002F2E10[];
extern char D_002F2E28[];
extern char D_002F2E50[];
void ror_assert(const char *file, int line, const char *expr);
void func_00178C54(EffMuzzleFlash1 *arg0, EffMuzzleFlashLayer *arg1, short arg2, float fparg0);
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

struct EffResEntry {
    int unk00;                          // +0x00
    signed char unk04;                  // +0x04
    char pad05[0x1F];                   // +0x05..+0x23
    int unk24;                          // +0x24
    void *unk28;                        // +0x28
    int unk2C;                          // +0x2C
    int unk30[8];                       // +0x30..+0x4F
    int unk50;                          // +0x50
    int unk54;                          // +0x54
    int unk58;                          // +0x58
};

struct DogTexInfoStub {
    int unk00;
    int unk04;
    int unk08;
};

struct EffTexWrap {
    char pad00[0x8];
    unsigned short unk08;
};

struct MfVec { int w[4]; } __attribute__((aligned(8)));
struct SteamV4 { float x; float y; int z; int w; } __attribute__((aligned(8)));
struct m2c_block12 { int w[3]; };
struct m2c_block16 { int w[4]; };

struct Stack8DD8 {
    EffMuzzleFlashLayer *unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    short unk14;
};

struct Stack8E68 {
    EffMuzzleFlashLayer *unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    short unk14;
};

extern "C" void X_func_0021A5B0(int, int, int) asm("func_0021A5B0");
extern "C" void X_func_0021A700(int, int) asm("func_0021A700");
extern "C" int X_func_0022B370(int) asm("func_0022B370");
extern "C" void *Xiii_func_0016FFEC(int, int) asm("func_0016FFEC");
extern "C" void *Xiiii_alloc__9BedMemoryii(void *, int, int) asm("alloc__9BedMemoryii");
extern "C" int X_func_0022AEC0(void *) asm("func_0022AEC0");
extern "C" EffTexWrap **X_func_0022AED8(void *, int) asm("func_0022AED8");
extern "C" int X_func_0022AAD0(void *, int) asm("func_0022AAD0");
extern "C" int X_func_0021AB30(int, void *) asm("func_0021AB30");
extern "C" int Xip_func_0021E488(int, void *) asm("func_0021E488");
extern "C" int func_00178DD8(EffMuzzleFlash1 *, EffRenderParam *, int, int);
extern "C" int func_00178E68(EffMuzzleFlash1 *, EffRenderParam *, int, int);
extern MfVec D_002F2E70;
extern "C" void Xppp_func_002378B0(void *, void *, void *) asm("func_002378B0");
extern "C" void Xp_func_00237340(void *) asm("func_00237340");
extern "C" void Xpp_func_00237830(void *, void *, float) asm("func_00237830");
extern "C" void Xpp_func_00237818(void *, void *, float) asm("func_00237818");
extern float D_002F2FB0;
extern "C" int X_func_0021B260(int, int) asm("func_0021B260");
extern "C" int X_func_0021B4F8(int, int) asm("func_0021B4F8");
extern "C" int X_func_0021B5A0(int, int) asm("func_0021B5A0");
extern "C" int X_func_0021E5A0(int, int, int) asm("func_0021E5A0");
extern "C" void X_func_0021E688(int) asm("func_0021E688");
extern "C" int X_func_00223290(int) asm("func_00223290");
extern "C" int Xiiii_func_0017BA54(EffWater3 *, EffWater3Entry *, int) asm("func_0017BA54");
extern "C" int Xiiii_func_0017BB50(EffWater3 *, int, EffWater3Entry *) asm("func_0017BB50");
extern "C" int Xiiii_func_0017B7CC(EffWater3 *, EffVec4 *, EffWater3Entry *) asm("func_0017B7CC");
extern "C" int Xiiii_func_0017B918(EffWater3 *, EffVec4 *, EffWater3Entry *) asm("func_0017B918");
extern "C" int Xiii_free__9BedMemoryPv(void *, void *) asm("free__9BedMemoryPv");
extern "C" int Xiii_releaseTex__10DogTexInfoi(int, int) asm("releaseTex__10DogTexInfoi");
extern "C" int X_func_00237360(void *, void *, float) asm("func_00237360");
extern "C" int X_func_002373D8(void *, void *, void *) asm("func_002373D8");
extern "C" void Xii_func_0017A410(EffCloud1 *) asm("func_0017A410");
extern "C" int X_func_0021A760(int, int, int) asm("func_0021A760");
extern "C" int X_func_0022E960(int, void *, int, float) asm("func_0022E960");
extern "C" int X_func_0022F7A0(void *, int, void *) asm("func_0022F7A0");
extern "C" int Xiiiiii_i3dCallLocked__FPvN40(int, int, int, void *, int) asm("i3dCallLocked__FPvN40");
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
extern "C" void X_func_00178EEC(EffMuzzleFlash1 *, Stack8DD8 *) asm("func_00178EEC");
extern "C" int X_func_0021B550(int, int, int) asm("func_0021B550");
extern "C" void X_8E68_func_00178EEC(EffMuzzleFlash1 *, Stack8E68 *) asm("func_00178EEC");
extern "C" int X_8E68_func_0021B550(int, int, int) asm("func_0021B550");
extern "C" float Xf_func_0022E958(int) asm("func_0022E958");
extern "C" int Xiiii_func_001787B0(int, int, int) asm("func_001787B0");
extern "C" int Xiii_Eff0__vfunc_02(Eff0 *, Eff0Arg *) asm("Eff0__vfunc_02");
extern "C" int Xii_func_0016A914(Eff0 *) asm("func_0016A914");
extern "C" float Xii_func_0016FF18(int, void *) asm("func_0016FF18");
extern int D_00298E08;
extern "C" char vtbl_9EffWater1[] asm("_vt$9EffWater1");
extern "C" char vtbl_10EffReload1[] asm("_vt$10EffReload1");
extern "C" char vtbl_9EffWater3[] asm("_vt$9EffWater3");
extern int D_006E9800;
extern int D_00298E1C;
extern "C" void X_free__9BedMemoryPv(void *, void *) asm("free__9BedMemoryPv");
extern "C" void X_dtor_4Eff0(Eff0 *, int) asm("_$_4Eff0");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_9EffWater1(EffWater1 *, int) asm("_$_9EffWater1");
extern "C" void dtor_10EffReload1(EffReload1 *, int) asm("_$_10EffReload1");
extern "C" void dtor_9EffWater3(EffWater3 *, int) asm("_$_9EffWater3");

extern "C" void func_001787B0(int arg0, int arg1, int arg2)
{
    int *var_s1;
    int temp_s3;
    int var_s2;
    int temp_a1;
    EffResEntry *temp_s0;

    temp_a1 = arg0 + (arg1 * 0x60);
    temp_s0 = (EffResEntry *)(temp_a1 + 0xC94);
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
        Xiii_free__9BedMemoryPv(&D_006E9800, temp_s0->unk28);
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

extern "C" int EffMuzzleFlash1__vfunc_02(EffMuzzleFlash1 *arg0, EffMuzzleFlash1Arg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    unsigned char rnd = (unsigned int)Xi_func_0016AD94() % 18U;
    *(m2c_block12 *)&arg0->m_pos = *(m2c_block12 *)&arg1->m_pos;
    arg0->m_flash.m_alpha = 0x7F00;
    arg0->m_pos.w = 1.0f;
    arg0->m_flash.m_size = 10.0f;
    arg0->m_flash.m_alphaVel = -0x3200;
    arg0->m_smoke.m_size = 40.0f;
    arg0->m_smoke.m_alpha = 0x6000;
    arg0->m_smoke.m_alphaVel = -0x700;
    *(int *)&arg0->m_flash.m_offsetY = 0;
    *(int *)&arg0->m_smoke.m_offsetY = 0;
    arg0->m_flash.m_angle = ((float)(rnd * 17) * 3.14159265f) / 180.0f;
    arg0->m_smoke.m_angle = ((float)(rnd * 20) * 3.14159265f) / 180.0f;
    int id = X_88EC_func_0013FE64__8MagSceneii(D_00298E08, 2, 3);
    arg0->m_lightId = id;
    MfLightPool *pool = (MfLightPool *)(D_00298E08 + 0x2050);
    MfLightPoint *pt = pool->getPoint(id);
    *(MfVec *)pt->m_pos = *(MfVec *)&arg0->m_pos;
    pt->m_color[0] = pt->m_color[1] = pt->m_color[2] = pt->m_color[3] = 0.0f;
    return 1;
}

extern "C" int EffMuzzleFlash1__vfunc_05(EffMuzzleFlash1 *arg0)
{
    if (arg0->m_flash.m_alpha >= 0x100) {
        func_00178C54(arg0, &arg0->m_flash, -0x180, 20.0f);
        MfLightPool *pool = (MfLightPool *)(D_00298E08 + 0x2050);
        MfLightPoint *pt = pool->getPoint(arg0->m_lightId);
        float c = (float)arg0->m_flash.m_alpha * 150.0f * (1.0f / 32768.0f);
        pt->m_color[3] = 0.0f;
        pt->m_color[0] = pt->m_color[1] = pt->m_color[2] = c;
    } else {
        int id = arg0->m_lightId;
        if (id != -1) {
            X_freeID__12DogLightPoolii((void *)(D_00298E08 + 0x2050), 2, id);
            arg0->m_lightId = -1;
        }
    }
    if (arg0->m_smoke.m_alpha >= 0x100) {
        func_00178C54(arg0, &arg0->m_smoke, 0x40, 2.5f);
        arg0->m_smoke.m_offsetY -= 2.25f;
        arg0->m_smoke.m_angle += 0.026179936f;
    }
    if (arg0->m_smoke.m_alpha >= 0x100 || arg0->m_flash.m_alpha >= 0x100) {
        return 1;
    }
    return 0;
}

extern "C" void func_00178C54(EffMuzzleFlash1 *arg0, EffMuzzleFlashLayer *arg1, short arg2, float fparg0)
{
    int temp = (unsigned short)arg1->m_alphaVel;

    arg1->m_alpha = (short)((unsigned short)arg1->m_alpha + temp);
    arg1->m_alphaVel = (short)(arg2 + temp);
    arg1->m_size = arg1->m_size + fparg0;
}

extern "C" void EffMuzzleFlash1__vfunc_08(EffMuzzleFlash1 *arg0, EffRenderParam *arg1, int arg2, int arg3)
{
    MfVec v;
    float f20;
    float f0;
    int x;
    int t;

    t = X_func_0021B5A0(arg3, arg1->m_unk08);
    int q = arg1->m_unk08;
    v = D_002F2E70;
    x = Xip_func_0021E488(X_func_0021E5A0(t, q, 1), &v);
    long long lo = ((long long *)&arg0->m_pos)[0];
    long long hi = ((long long *)&arg0->m_pos)[1];
    ((long long *)&v)[0] = lo;
    ((long long *)&v)[1] = hi;
    f20 = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &v);
    ((float *)&v)[1] += arg0->m_smoke.m_offsetY;
    f0 = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &v);
    if (f20 < f0) {
        x = func_00178DD8(arg0, arg1, arg2, x);
        x = func_00178E68(arg0, arg1, arg2, x);
    } else {
        x = func_00178E68(arg0, arg1, arg2, x);
        x = func_00178DD8(arg0, arg1, arg2, x);
    }
    X_func_0021E688(x);
}

extern "C" int func_00178DD8(EffMuzzleFlash1 *arg0, EffRenderParam *arg1, int arg2, int arg3)
{
    Stack8DD8 stack;

    if (arg0->m_smoke.m_alpha < 0x100) {
        return arg3;
    }
    stack.unk08 = arg2;
    stack.unk04 = (*(int *)&D_00298E08) + 0x2AB70;
    stack.unk0C = X_func_0021B550(arg3, 0x42, 0x44);
    stack.unk00 = &arg0->m_smoke;
    stack.unk10 = 1.0f;
    stack.unk14 = 1;
    X_func_00178EEC(arg0, &stack);
    return stack.unk0C;
}

extern "C" int func_00178E68(EffMuzzleFlash1 *arg0, EffRenderParam *arg1, int arg2, int arg3)
{
    Stack8E68 stack;

    if (arg0->m_flash.m_alpha < 0x100) {
        return arg3;
    }
    stack.unk08 = arg2;
    stack.unk04 = (*(int *)&D_00298E08) + 0x2AB70;
    stack.unk0C = X_8E68_func_0021B550(arg3, 0x42, 0x48);
    stack.unk00 = &arg0->m_flash;
    stack.unk10 = 0;
    stack.unk14 = 0;
    X_8E68_func_00178EEC(arg0, &stack);
    return stack.unk0C;
}

class MfCam {
public:
    EffMat4 m_mat;
    char pad40[0x54];
    virtual void vfunc0();
    virtual void transform();
};

struct MfArg1 {
    EffMuzzleFlashLayer *unk00;
    MfCam *unk04;
    int unk08;
    int unk0C;
    float unk10;
    short unk14;
};

extern "C" void X_8EEC_func_0016FD4C(void *, float) asm("func_0016FD4C");
extern "C" void X_8EEC_func_00237A40(void *, void *, void *) asm("func_00237A40");
extern "C" int X_8EEC_func_0021B260(int, int) asm("func_0021B260");
extern "C" int X_8EEC_func_0021B4F8(int, int) asm("func_0021B4F8");
extern "C" int X_8EEC_func_0021E428(int, void *) asm("func_0021E428");
extern "C" int X_8EEC_func_0021E690(int, void *, void *) asm("func_0021E690");

extern "C" void func_00178EEC(EffMuzzleFlash1 *arg0, MfArg1 *arg1)
{
    EffMat4 mat;
    MfCam *cam = arg1->unk04;
    int ctx = arg1->unk0C;

    cam->transform();
    mat = cam->m_mat;

    EffMuzzleFlashLayer *p0 = arg1->unk00;
    EffVec4A8 scale = { p0->m_size, p0->m_size, 1.0f, 1.0f };
    EffVec4A8 color = { 1.0f, 1.0f, 1.0f, (float)p0->m_alpha * (1.0f / 32768.0f) };
    X_8EEC_func_0016FD4C(&mat, p0->m_angle);
    X_8EEC_func_00237A40(&mat, &mat, &scale);

    *(EffVec4A8 *)mat.m[3] = arg0->m_pos;
    mat.m[3][0] += mat.m[2][0] * arg1->unk10;
    mat.m[3][1] += mat.m[2][1] * arg1->unk10 + arg1->unk00->m_offsetY;
    mat.m[3][2] += mat.m[2][2] * arg1->unk10;

    arg1->unk0C = X_8EEC_func_0021E690(
        X_8EEC_func_0021E428(
            X_8EEC_func_0021B4F8(ctx, X_8EEC_func_0021B260(arg1->unk08, arg1->unk14)),
            &mat),
        mat.m[3],
        &color);
}

extern "C" void updateZDepth__15EffMuzzleFlash1(EffMuzzleFlash1 *arg0)
{
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &arg0->m_pos);
}

extern "C" void func_001790E4(EffReload1 *);
struct EffReload1Ctor_1790E4 : EffReload1 {
    EffReload1Ctor_1790E4() asm("func_001790E4");
};

EffReload1Ctor_1790E4::EffReload1Ctor_1790E4()
{
    Xii_func_0016A914(this);
    m_vtbl = vtbl_10EffReload1;
    m_buf = 0;
    m_nodeMap = 0;
}

extern "C" void dtor_10EffReload1(EffReload1 *arg0, int arg1)
{
    arg0->m_vtbl = vtbl_10EffReload1;
    if (arg0->m_buf != 0) {
        X_free__9BedMemoryPv(&D_006E9800, arg0->m_buf);
    }
    if (arg0->m_nodeMap != 0) {
        X_free__9BedMemoryPv(&D_006E9800, arg0->m_nodeMap);
    }
    X_dtor_4Eff0(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

extern "C" int EffReload1__vfunc_02(EffReload1 *arg0, EffReload1Arg *arg1)
{
    struct { float x, y, z; int w; } stack;
    int temp_a0;
    int n;
    int temp_s0;
    int temp_v0;
    EffMat4 *temp_s2;
    EffResEntry *res;
    char *temp_v0_2;
    DogTexInfoStub *texInfo;

    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    n = arg1->m_bulletCount;
    if (n > 6) {
        n = 6;
    }
    if (n <= 0) {
        arg0->m_model = 0;
        return 1;
    }
    temp_s2 = &arg0->m_mat;
    temp_a0 = ((EffResEntry *)arg1->m_parent)->unk30[0];
    texInfo = (DogTexInfoStub *)((*(int *)&D_00298E08) + 0x29520);
    arg0->m_model = temp_a0;
    res = (EffResEntry *)arg1->m_parent;
    arg0->m_motion = res->unk30[res->unk50 + n - 1];
    X_func_0021A5B0(temp_a0, texInfo->unk08, texInfo->unk04);
    arg0->m_nodeMap = Xiii_func_0016FFEC(arg0->m_model, arg0->m_motion);
    temp_v0 = X_func_0022B370(arg0->m_model);
    temp_v0_2 = (char *)Xiiii_alloc__9BedMemoryii(&D_006E9800, temp_v0 * 0xB0, -1);
    temp_s0 = (int)(temp_v0_2 + (temp_v0 * 0x30));
    arg0->m_buf = temp_v0_2;
    arg0->m_posture = temp_s0;
    arg0->m_matrix = temp_s0 + (temp_v0 << 6);
    X_func_0021A700(arg0->m_model, temp_s0);
    Xp_func_00237340(temp_s2);
    float fx = arg1->m_rotX;
    float fy = arg1->m_rotY;
    float fz = arg1->m_rotZ;
    stack.y = fy;
    stack.x = fx;
    stack.z = fz;
    stack.w = 0;
    Xppp_func_002378B0(temp_s2, temp_s2, &stack);
    arg0->m_mat.m[3][0] = arg1->m_posX;
    arg0->m_mat.m[3][1] = arg1->m_posY;
    arg0->m_mat.m[3][2] = arg1->m_posZ;
    arg0->m_frame = 0;
    return 1;
}

extern "C" int EffReload1__vfunc_05(EffReload1 *arg0)
{
    int temp_v0;

    if (arg0->m_model != 0) {
        temp_v0 = arg0->m_frame + 1;
        arg0->m_frame = temp_v0;
        if (((float)temp_v0 / 60.0f) < Xf_func_0022E958(arg0->m_motion)) {
            return 1;
        }
    }
    return 0;
}

extern "C" void renderPreMain__10EffReload1PQ24Eff011RENDERPARAM(EffReload1 *arg0, EffRenderParam *arg1)
{
    if (arg0->m_model != 0) {
        X_func_0022E960(arg0->m_motion, arg0->m_buf, 0x111, (float)arg0->m_frame / 60.0f);
        X_func_0022F7A0(arg0->m_buf, arg0->m_posture, arg0->m_nodeMap);
        X_func_0021A760(arg0->m_model, arg0->m_matrix, arg0->m_posture);
        Xiiiiii_i3dCallLocked__FPvN40(arg1->m_unk08, arg0->m_model, arg0->m_matrix, &arg0->m_mat, 0);
    }
}

extern "C" int EffSteam1__vfunc_02(EffSteam1 *arg0, EffSteam1Arg *arg1)
{
    SteamV4 w;
    SteamV4 v;
    int temp_v0;
    int temp_v0_2;
    EffMat4 *temp_s2;

    temp_s2 = &arg0->m_mat;
    if (Xiii_Eff0__vfunc_02(arg0, arg1) != 0) {
        arg0->m_unk70 = arg1->m_unk24;
        arg0->m_unk74 = arg1->m_unk28;
        temp_v0 = arg1->m_minTime;
        arg0->m_minTime = temp_v0;
        int lo = (temp_v0 >= 0) ? temp_v0 : 0;
        temp_v0_2 = temp_v0 + arg1->m_addTime;
        arg0->m_minTime = lo;
        arg0->m_period = (temp_v0_2 >= 1) ? temp_v0_2 : 1;
        int rnd = Xi_func_0016AD94();
        float c2 = (float)arg0->m_period;
        v.z = 0;
        v.w = 0;
        *(long long *)&w.z = *(long long *)&v.z;
        arg0->m_timer24 = (int)((c2 * (float)rnd) / 255.0f);
        float fx = arg1->m_rotX;
        float fy = arg1->m_rotY;
        v.x = fx;
        v.y = fy;
        *(long long *)&w.x = *(long long *)&v.x;
        Xp_func_00237340(temp_s2);
        Xppp_func_002378B0(temp_s2, temp_s2, &w);
        *(m2c_block12 *)arg0->m_mat.m[3] = *(m2c_block12 *)&arg1->m_pos;
        *(m2c_block16 *)&arg0->m_color = *(m2c_block16 *)&arg1->m_color;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1__vfunc_05);

extern "C" int EffSteam1Prim__vfunc_02(EffSteam1Prim *arg0, EffSteam1PrimArg *arg1)
{
    float temp_f2;
    EffVec4 *temp_v1;

    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    arg0->m_scale = arg1->m_scale;
    temp_v1 = arg1->m_posPtr;
    *(m2c_block16 *)&arg0->m_pos = *(m2c_block16 *)temp_v1;
    arg0->m_pos.w = 1.0f;
    temp_f2 = arg1->m_speed * 15.0f;
    arg0->m_vel.x = arg1->m_dirX * temp_f2;
    arg0->m_vel.y = arg1->m_dirY * temp_f2;
    arg0->m_vel.z = arg1->m_dirZ * temp_f2;
    arg0->m_size = 20.0f;
    arg0->m_alpha = 0.3999999836087227f;
    arg0->m_alphaVel = 0.029999999795109034f;
    arg0->m_unk4C = 0;
    arg0->m_fadeSpeed = arg1->m_fadeSpeed;
    *(m2c_block16 *)&arg0->m_color = *(m2c_block16 *)&arg1->m_color;
    return 1;
}

extern "C" int EffSteam1Prim__vfunc_05(EffSteam1Prim *arg0)
{
    float temp_f1;
    int var_v0;
    EffVec4 *temp_a0;
    EffVec3 *temp_s1;

    temp_s1 = &arg0->m_vel;
    var_v0 = 0;
    temp_f1 = arg0->m_alpha + arg0->m_alphaVel;
    arg0->m_alpha = temp_f1;
    if (!(temp_f1 <= 0.0f)) {
        if (temp_f1 >= 1.0f) {
            arg0->m_alpha = 1.0f;
            arg0->m_alphaVel = arg0->m_fadeSpeed * -0.06999999471008778f;
        }
        X_func_00237360(temp_s1, temp_s1, 0.95f);
        temp_a0 = &arg0->m_pos;
        X_func_002373D8(temp_a0, temp_a0, temp_s1);
        arg0->m_size = arg0->m_size + 4.5f;
        var_v0 = 1;
    }
    return var_v0;
}

// NON_MATCHING: 34/113 differ, 1 reloc differs, 30 edits
#ifdef NON_MATCHING
class SteamCam {
public:
    EffMat4 m_mat;
    char pad40[0x54];
    virtual void vfunc0();
    virtual void transform();
};

extern EffVec4A8 D_002F2EB0;
extern EffVec4A8 D_002F2EC0;

extern "C" int X_9998_func_0021B260(int, int) asm("func_0021B260");
extern "C" int X_9998_func_0021B4F8(int, int) asm("func_0021B4F8");
extern "C" int X_9998_func_0021B550(int, int, int) asm("func_0021B550");
extern "C" int X_9998_func_0021B5A0(int, int) asm("func_0021B5A0");
extern "C" int X_9998_func_0021E428(int, void *) asm("func_0021E428");
extern "C" int X_9998_func_0021E488(int, void *) asm("func_0021E488");
extern "C" int X_9998_func_0021E5A0(int, int, int) asm("func_0021E5A0");
extern "C" void X_9998_func_0021E688(int) asm("func_0021E688");
extern "C" int X_9998_func_0021E690(int, void *, void *) asm("func_0021E690");
extern "C" void X_9998_func_00237A40(void *, void *, void *) asm("func_00237A40");
extern "C" void X_9998_func_0016AF20(void *) asm("func_0016AF20");

extern "C" void EffSteam1Prim__vfunc_08(EffSteam1Prim *arg0, EffRenderParam *arg1, int arg2, int arg3)
{
    EffVec4A8 v;
    EffMat4 mat;
    int s0 = X_9998_func_0021B5A0(X_9998_func_0021B550(arg3, 0x42, 0x44), arg1->m_unk08);
    s0 = X_9998_func_0021B4F8(s0, X_9998_func_0021B260(arg2, 0));
    int q = arg1->m_unk08;
    v = D_002F2EB0;
    int s3 = X_9998_func_0021E488(X_9998_func_0021E5A0(s0, q, 1), &v);
    SteamCam *cam = (SteamCam *)(D_00298E08 + 0x2AB70);
    cam->transform();
    mat = cam->m_mat;
    float alpha = arg0->m_color.w * arg0->m_alpha;
    EffVec4A8 color = {
        arg0->m_color.x,
        arg0->m_color.y,
        arg0->m_color.z,
        alpha
    };
    v = D_002F2EC0;
    v.x = v.y = arg0->m_size * arg0->m_scale;
    X_9998_func_00237A40(&mat, &mat, &v);
    X_9998_func_0016AF20(&color);
    X_9998_func_0021E688(X_9998_func_0021E690(X_9998_func_0021E428(s3, &mat), &arg0->m_pos, &color));
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam1Prim__vfunc_08);
#endif

extern "C" void updateZDepth__13EffSteam1Prim(EffSteam1Prim *arg0)
{
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &arg0->m_pos);
}

extern "C" int EffSteam2__vfunc_02(EffSteam2 *arg0, EffSteam2Arg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    *(m2c_block12 *)&arg0->m_pos = *(m2c_block12 *)&arg1->m_pos;
    arg0->m_scale = arg1->m_scale;
    arg0->m_alpha = arg1->m_alpha;
    arg0->m_wait = (unsigned char)((Xi_func_0016AD94() * 0x96) / 255);
    return 1;
}

extern "C" int EffSteam2__vfunc_05(EffSteam2 *arg0)
{
    Steam2Param param;
    float mat[16];
    if (arg0->m_wait == 0) {
        param.unk00 = 0x2C;
        param.unk08 = 0;
        X_9C30_func_00237340(mat);
        mat[12] = (arg0->m_scale * (float)X_9C30_func_0016AD94()) / 510.0f;
        X_9C30_func_00237830(mat, mat, (((float)X_9C30_func_0016AD94() * 6.2831853f) / 255.0f) - 3.14159265f);
        float x = arg0->m_pos.x + mat[12];
        float s = arg0->m_scale;
        float y = arg0->m_pos.y + mat[13] + (-s * 0.5f);
        float z = arg0->m_pos.z + mat[14];
        param.pos[3] = s;
        param.pos[0] = x;
        param.pos[2] = z;
        param.pos[1] = y;
        int rnd = X_9C30_func_0016AD94();
        param.unk20 = arg0->m_alpha * (1.0 - (float)rnd / 510.0f);
        X_9C30_func_00176CC8(D_00298E08 + 0x837E0, &param);
        arg0->m_wait = (X_9C30_func_0016AD94() * 0x1E) / 255 - 0x4C;
    } else {
        arg0->m_wait--;
    }
    return 1;
}

extern "C" int EffSteam2Prim__vfunc_02(EffSteam2Prim *arg0, EffSteam2PrimArg *arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        *(m2c_block12 *)&arg0->m_pos = *(m2c_block12 *)&arg1->m_pos;
        var_v0 = 1;
        arg0->m_posW = 1.0f;
        arg0->m_alpha = arg1->m_alpha;
        arg0->m_scale = arg1->m_scale;
        arg0->m_age = 0;
    }
    return var_v0;
}

extern "C" int EffSteam2Prim__vfunc_05(EffSteam2Prim *arg0)
{
    int temp_v1;

    temp_v1 = arg0->m_age + 1;
    arg0->m_age = temp_v1;
    if ((unsigned int)(temp_v1 & 0xFF) >= 0x96U) {
        return 0;
    }
    arg0->m_pos.y = arg0->m_pos.y + ((arg0->m_scale * -0.09999999590218067f) / 30.0f);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffSteam2Prim__vfunc_08);

extern "C" void updateZDepth__13EffSteam2Prim(EffSteam2Prim *arg0)
{
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &arg0->m_pos);
}

extern "C" int EffCloud1__vfunc_02(EffCloud1 *arg0, EffCloud1Arg *arg1)
{
    float mat[16];
    int t;

    if (Xiii_Eff0__vfunc_02(arg0, arg1)) {
        *(m2c_block12 *)&arg0->m_origin = *(m2c_block12 *)&arg1->m_origin;
        *(m2c_block16 *)&arg0->m_color = *(m2c_block16 *)&arg1->m_color;
        arg0->m_radius = arg1->m_radius;
        Xp_func_00237340(mat);
        float sc = arg1->m_speed;
        float rot = arg1->m_rotY;
        mat[10] = sc;
        Xpp_func_00237830(mat, mat, rot);
        *(m2c_block12 *)&arg0->m_vel = *(m2c_block12 *)(mat + 8);
        Xii_func_0017A410(arg0);
        arg0->m_posW = 1.0f;
        t = (int)(arg1->m_dist / arg1->m_speed) + 1;
        arg0->m_moveDur = t;
        int e = t + (t % 30);
        arg0->m_tick = t;
        arg0->m_zDepth = D_002F2FB0;
        arg0->m_totalDur = e;
        return 1;
    }
    return 0;
}

extern "C" void func_0017A410(EffCloud1 *arg0)
{
    float mat[16];

    Xp_func_00237340(mat);
    mat[12] = (arg0->m_radius * (float)Xi_func_0016AD94()) / 510.0f;
    Xpp_func_00237818(mat, mat, (((float)Xi_func_0016AD94() * 6.283185124397278f) / 255.0f) - 3.141592562198639f);
    Xpp_func_00237830(mat, mat, (((float)Xi_func_0016AD94() * 6.283185124397278f) / 255.0f) - 3.141592562198639f);
    register float x PS2_REG("$f3") = arg0->m_origin.x;
    register float mx PS2_REG("$f0") = mat[12];
    register float my PS2_REG("$f4") = mat[13];
    register float mz PS2_REG("$f2") = mat[14];
    x += mx;
    register float y PS2_REG("$f1") = arg0->m_origin.y;
    register float z PS2_REG("$f0") = arg0->m_origin.z;
    y += my;
    z += mz;
    arg0->m_pos.x = x;
    arg0->m_pos.y = y;
    arg0->m_pos.z = z;
    arg0->m_seed = Xi_func_0016AD94();
}

extern "C" int EffCloud1__vfunc_05(EffCloud1 *arg0)
{
    int temp_a1;
    int temp_v1;

    temp_v1 = arg0->m_unk0C;
    temp_a1 = arg0->m_tick + 1;
    arg0->m_tick = temp_a1;
    arg0->m_unk08 = temp_v1;
    switch (temp_v1) {
    case 0:
        if (temp_a1 < arg0->m_moveDur) {
            arg0->m_pos.x += arg0->m_vel.x;
            arg0->m_pos.y += arg0->m_vel.y;
            arg0->m_pos.z += arg0->m_vel.z;
        } else {
            arg0->m_unk0C = 0xA;
        }
        break;
    case 10:
        if (temp_a1 >= arg0->m_totalDur) {
            Xii_func_0017A410(arg0);
            arg0->m_tick = 0;
            arg0->m_unk0C = 0;
        }
        break;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffCloud1__vfunc_08);

extern "C" void updateZDepth__9EffCloud1(EffCloud1 *arg0)
{
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &arg0->m_pos);
}

extern "C" void func_0017A918(EffWater1 *arg0)
{
    Xii_func_0016A914(arg0);
    arg0->m_modelBuf = 0;
    arg0->m_vtbl = vtbl_9EffWater1;
}

extern "C" void dtor_9EffWater1(EffWater1 *arg0, int arg1)
{
    arg0->m_vtbl = vtbl_9EffWater1;
    if (arg0->m_modelBuf != 0) {
        X_free__9BedMemoryPv(&D_006E9800, arg0->m_modelBuf);
    }
    X_dtor_4Eff0(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
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

extern "C" int EffWater1__vfunc_05(EffWater1 *arg0)
{
    void *s4;
    int n;
    int i;
    EffTexWrap **p;
    float f;

    s4 = (char *)arg0->m_modelBuf + 0x10;
    n = X_func_0022AEC0(s4);
    float d = arg0->m_scrollU / 30.0f;
    f = arg0->m_uvU + d;
    arg0->m_uvU = f;
    if (f >= 1.0f || f <= -1.0f) {
        arg0->m_uvU = f - (float)(int)f;
    }
    arg0->m_uvV += arg0->m_scrollV / 30.0f;
    f = arg0->m_uvV;
    if (f >= 1.0f || f <= -1.0f) {
        arg0->m_uvV = f - (float)(int)f;
    }
    i = 0;
    if (n > 0) {
        do {
            p = X_func_0022AED8(s4, i++);
            X_func_0021AB30(X_func_0022AAD0(p, 0), &arg0->m_uvU);
            (*p)->unk08 = (*p)->unk08 + 1;
        } while (i < n);
    }
    return 1;
}

extern "C" void liveActivateExec__9EffWater1(EffWater1 *arg0)
{
    int temp_a2;
    int temp_v0;
    int temp_v0_2;
    unsigned short temp_a1;

    temp_v0 = arg0->m_fade;
    temp_a1 = arg0->m_flags;
    temp_v0_2 = temp_v0 - 1;
    temp_a2 = temp_v0 + 1;
    if (temp_a1 & 4) {
        arg0->m_fade = temp_a2;
        if (temp_a2 >= 5) {
            arg0->m_flags = (unsigned short)(temp_a1 & 0xFFF7);
        }
    } else {
        arg0->m_fade = temp_v0_2;
        if (temp_v0_2 <= 0) {
            arg0->m_flags = (unsigned short)(temp_a1 & 0xFFF7);
        }
    }
}

// NON_MATCHING: 37/117 differ, 50 edits
#ifdef NON_MATCHING
struct WaterNodeParam {
    char unk00[0x10];
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    char unk24;
    char unk25;
    char pad26[0xA];
} __attribute__((aligned(8)));

struct WaterMat4 {
    EffVec4A8 row[4];
};

extern "C" void *X_AE04_memset(void *, int, int) asm("memset");
extern "C" int X_AE04_func_0022B0D0(void *) asm("func_0022B0D0");
extern "C" int X_AE04_func_0022B0E8(void *, int) asm("func_0022B0E8");
extern "C" int *X_AE04_func_0022AC08(int) asm("func_0022AC08");
extern "C" void X_AE04_func_00237A40(void *, void *, void *) asm("func_00237A40");

extern "C" void renderPreMain__9EffWater1PQ24Eff011RENDERPARAM(EffWater1 *arg0, EffRenderParam *arg1)
{
    if ((arg0->m_flags & 0xC) != 4) {
        WaterNodeParam dst;
        int i = 0;
        {
            WaterNodeParam tmp;
            X_AE04_memset(&tmp, 0, 0x10);
            float c0 = arg0->m_color.x;
            float c1 = arg0->m_color.y;
            float c2 = arg0->m_color.z;
            float c3 = arg0->m_color.w;
            tmp.unk10 = c0;
            tmp.unk14 = c1;
            tmp.unk18 = c2;
            tmp.unk1C = c3;
            tmp.unk20 = 1.0f;
            tmp.unk25 = 1;
            tmp.unk24 = 1;
            dst = tmp;
        }

        void *model = (char *)arg0->m_modelBuf + 0x10;
        int n = X_AE04_func_0022B0D0(model);
        for (; i < n; i++) {
            *X_AE04_func_0022AC08(X_AE04_func_0022B0E8(model, i)) = (int)&dst;
        }

        EffVec4A8 scale;
        {
            float s = arg0->m_scale;
            EffVec4A8 v = { s, s, s, 1.0f };
            scale = v;
        }
        if (arg0->m_flags & 8) {
            scale.x = scale.z = (scale.x * (float)arg0->m_fade) / 5.0f;
        }

        WaterMat4 mat;
        Xp_func_00237340(&mat);
        Xpp_func_00237830(&mat, &mat, arg0->m_rotY);
        X_AE04_func_00237A40(&mat, &mat, &scale);
        mat.row[3] = arg0->m_pos;
        Xiiiiii_i3dCallLocked__FPvN40(arg1->m_unk08, (int)arg0->m_modelBuf, 0, &mat, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", renderPreMain__9EffWater1PQ24Eff011RENDERPARAM);
#endif

extern "C" void func_0017AFD8(EffWater3 *);
struct EffWater3Ctor_17AFD8 : EffWater3 {
    EffWater3Ctor_17AFD8() asm("func_0017AFD8");
};

EffWater3Ctor_17AFD8::EffWater3Ctor_17AFD8()
{
    Xii_func_0016A914(this);
    m_vtbl = vtbl_9EffWater3;
    m_entries = 0;
    m_count = 0;
}

extern "C" void dtor_9EffWater3(EffWater3 *arg0, int arg1)
{
    arg0->m_vtbl = vtbl_9EffWater3;
    if (arg0->m_entries != 0) {
        X_free__9BedMemoryPv(&D_006E9800, arg0->m_entries);
        arg0->m_entries = 0;
    }
    D_00298E1C--;
    X_dtor_4Eff0(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffWater1", EffWater3__vfunc_02);

extern "C" int EffWater3__vfunc_05(EffWater3 *arg0)
{
    EffWater3Entry *var_s3;
    EffVec4 *var_s0;
    int var_s4;
    int var_s2;

    var_s4 = 0;
    var_s3 = arg0->m_entries;
    if (arg0->m_count > 0) {
        do {
            var_s0 = var_s3->m_drops;
            for (var_s2 = 7; var_s2 >= 0; var_s2--, var_s0++) {
                var_s0->y += arg0->m_speedY;
                if (arg0->m_maxY < var_s0->y) {
                    Xiiii_func_0017B7CC(arg0, var_s0, var_s3);
                }
            }
            var_s0 = var_s3->m_ripples;
            for (var_s2 = 3; var_s2 >= 0; var_s2--, var_s0++) {
                var_s0->y += -0.5f;
                if (var_s0->y < -3.0f) {
                    Xiiii_func_0017B918(arg0, var_s0, var_s3);
                }
            }
            var_s4 += 1;
            var_s3 += 1;
        } while (var_s4 < arg0->m_count);
    }
    return 1;
}

extern "C" void EffWater3__vfunc_08(EffWater3 *arg0, EffRenderParam *arg1, int arg2, int arg3)
{
    int temp_s1;
    int var_s2;
    int var_s4;
    EffWater3Entry *var_s0;

    var_s4 = 0;
    var_s2 = X_func_0021B5A0(X_func_0021B550(arg3, 0x42, 0x44), arg1->m_unk08);
    var_s2 = X_func_0021E5A0(X_func_0021B4F8(var_s2, X_func_0021B260(arg2, 0)), arg1->m_unk08, 1);
    temp_s1 = X_func_00223290(arg1->m_unk08);
    var_s0 = arg0->m_entries;
    if (arg0->m_count > 0) {
        do {
            if (Xiiii_func_0017BA54(arg0, var_s0, temp_s1) != 0) {
                var_s2 = Xiiii_func_0017BB50(arg0, var_s2, var_s0);
            }
            var_s0 += 1;
            var_s4 += 1;
        } while (var_s4 < arg0->m_count);
    }
    return X_func_0021E688(var_s2);
}
