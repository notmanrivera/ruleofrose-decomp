#include "include_asm.h"
#include "unk/EffFire1.h"
#include "game/gamtrg.h"
#include "game/gamman.h"
#include "bed/bedpfh.h"

extern "C" int Xiii_func_00170624(EffDust2 *, int) asm("func_00170624");
extern int D_007A3210;

struct Fog3Entry {
    int id;
    float unk04;
    float unk08;
    int unk0C;
    float unk10;
    int r, g, b;
};

struct EffFog3Res {
    char pad00[0x28];
    void *m_pfhTop;                     // +0x28
    char pad2C[0x24];
    int m_cnt0;                         // +0x50
    int m_cnt1;                         // +0x54
    int m_cnt2;                         // +0x58
};

extern Fog3Entry *X_Fog3_D_00298E18 asm("D_00298E18");
extern char X_27EC_D_007B2140[] asm("D_007B2140");
extern "C" int X_27EC_func_00163BE4(void *, int) asm("func_00163BE4");
extern "C" int X_27EC_func_00163B20(void *, int) asm("func_00163B20");
extern "C" int X_1548_func_0021B260(int, int) asm("func_0021B260");
extern "C" int X_1548_func_0021B4F8(int, int) asm("func_0021B4F8");
extern "C" int X_1548_func_0021B550(int, int, int) asm("func_0021B550");
extern "C" int X_1548_func_0021B5A0(int, int) asm("func_0021B5A0");
extern "C" int X_1548_func_0021E428(int, void *) asm("func_0021E428");
extern "C" int X_1548_func_0021E488(int, void *) asm("func_0021E488");
extern "C" int X_1548_func_0021E5A0(int, int, int) asm("func_0021E5A0");
extern "C" void X_1548_func_0021E688(int) asm("func_0021E688");
extern "C" int X_1548_func_0021E690(int, void *, void *) asm("func_0021E690");

struct EffSpawnParam {
    int unk00;
    int unk04;
    int unk08;
    char pad0C[0x74];
};
extern "C" void X_func_00176CC8(void *, void *) asm("func_00176CC8");
extern "C" int Xi_func_001726B4() asm("func_001726B4");
extern "C" int Xi_func_001727EC() asm("func_001727EC");

struct Fire1702E4Sub {
    char pad0[0x40];
    EffVec3 pos;
};
struct Fire1702E4Arg {
    int unk00;
    Fire1702E4Sub *sub;
    float cx, cy, cz;
    float r1, hy, unk1C, r2;
};

static inline EffVec4A8 MakeEffVec4A8(float x, float y, float z, float w)
{
    EffVec4A8 r;
    r.y = y;
    r.z = z;
    r.x = x;
    r.w = w;
    return r;
}

extern "C" void X_Fire2_func_00237340(void *) asm("func_00237340");
extern "C" void X_Fire2_func_002378B0(void *, void *, void *) asm("func_002378B0");
extern "C" void X_Fire2_func_00237A40(void *, void *, void *) asm("func_00237A40");
struct m2c_block12 { int w[3]; };
struct m2c_block16 { int w[4]; };
struct m2c_block32 { int w[8]; };
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
extern "C" float Xff_func_0016FE88(float) asm("func_0016FE88");
extern char D_006FBD80[];
extern "C" float Xii_func_0016FF18(int, void *) asm("func_0016FF18");
extern "C" int Xiii_Eff0__vfunc_02(Eff0 *, Eff0Arg *) asm("Eff0__vfunc_02");
extern "C" float Xfi_func_0010DA4C__8DogActor(void *) asm("func_0010DA4C__8DogActor");
extern "C" int Xiii_func_00172934(int, int) asm("func_00172934");
extern "C" int Xiiiff_func_0010BCC8__8DogActoriff(void *, int, float, float) asm("func_0010BCC8__8DogActoriff");
extern "C" int Xiiii_func_00170158(void *, int, const char *) asm("func_00170158");
extern "C" int X_Eff0__vfunc_02(...) asm("Eff0__vfunc_02");
extern int D_00298E08;
extern int D_00298E14;
extern int D_00298E18;
extern "C" char vtbl_7EffFog3[] asm("_vt$7EffFog3");
extern "C" void X_dtor_4Eff0(Eff0 *, int) asm("_$_4Eff0");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_7EffFog3(EffFog3 *, int) asm("_$_7EffFog3");

extern "C" int func_001702E4(Fire1702E4Arg *arg0)
{
    Fire1702E4Sub *p = arg0->sub;
    float r = arg0->r1 + arg0->r2;
    EffVec3 pos;
    pos.x = p->pos.x;
    pos.y = p->pos.y;
    pos.z = p->pos.z;
    EffVec3 half = { r, arg0->hy, r };
    float cx = arg0->cx;
    if (pos.x < cx - half.x || cx + half.x < pos.x) {
        return 0;
    }
    float cz = arg0->cz;
    if (pos.z < cz - half.z || cz + half.z < pos.z) {
        return 0;
    }
    float cy = arg0->cy;
    if (pos.y < cy - half.y || cy + half.y < pos.y) {
        return 0;
    }
    return 1;
}

extern "C" void func_001703C0(Fire1702E4Arg *arg0)
{
    float temp_f0;
    void *temp_s0;
    int temp_v0;

    temp_s0 = arg0->sub;
    temp_f0 = Xfi_func_0010DA4C__8DogActor(temp_s0);
    if (temp_f0 >= 0.0f) {
        temp_v0 = Xiiiff_func_0010BCC8__8DogActoriff(temp_s0, -1, temp_f0, temp_f0 + 1.0f);
        if (temp_v0 & 0x10000000) {
            Xiiii_func_00170158(arg0, 0, "Bip01 L Toe0");
        }
        if (temp_v0 & 0x20000000) {
            Xiiii_func_00170158(arg0, 1, "Bip01 R Toe0");
        }
        if (temp_v0 & 0x04000000) {
            Xiiii_func_00170158(arg0, 2, "Bip01 L Finger0");
        }
        if (temp_v0 & 0x08000000) {
            Xiiii_func_00170158(arg0, 3, "Bip01 R Finger0");
        }
    }
}

extern "C" int EffDust2__vfunc_02(EffDust2 *arg0, EffDust2Arg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    *(m2c_block12 *)&arg0->m_pos = *(m2c_block12 *)&arg1->m_pos;
    arg0->m_posW = 1.0f;
    arg0->m_unk40 = arg1->m_unk1C;
    *(m2c_block12 *)&arg0->m_vel = *(m2c_block12 *)&arg1->m_vel;
    arg0->m_velW = 1.0f;
    arg0->m_unk60 = arg1->m_unk2C;
    *(m2c_block16 *)&arg0->m_color = *(m2c_block16 *)&arg1->m_color;
    arg0->m_unk80 = arg1->m_unk40;
    arg0->m_unk84 = 0;
    for (int i = 0; i < 12; i++) {
        arg0->m_prims[i] = Xiii_func_00170624(arg0, i * 8);
    }
    return 1;
}

extern "C" int EffDust2__vfunc_05(EffDust2 *self)
{
    for (int i = 0; i < 12; i++) {
        register int entry PS2_REG("$3") = D_00298E08;
        register int index PS2_REG("$2") = self->m_prims[i] * 4;
        entry += index;
        if (*(int *)(entry + 0x837E4) == 0) {
            self->m_prims[i] = Xiii_func_00170624(self, 0);
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_00170624);

extern "C" int EffDust2Prim__vfunc_02(EffDust2Prim *arg0, EffDust2PrimArg *arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        *(m2c_block12 *)&arg0->m_pos = *(m2c_block12 *)&arg1->m_pos;
        var_v0 = 1;
        arg0->m_posW = 1.0f;
        arg0->m_size = arg1->m_size;
        *(m2c_block16 *)&arg0->m_color = *(m2c_block16 *)&arg1->m_color;
        arg0->m_age = 0;
    }
    return var_v0;
}

extern "C" int EffDust2Prim__vfunc_05(EffDust2Prim *arg0)
{
    int temp_v0;

    temp_v0 = arg0->m_age + 1;
    arg0->m_age = temp_v0;
    arg0->m_pos.y = arg0->m_pos.y + -0.024999998975545168f;
    return temp_v0 < 0x96;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffDust2Prim__vfunc_08);

extern "C" void updateZDepth__12EffDust2Prim(EffDust2Prim *arg0)
{
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &arg0->m_pos);
}

extern "C" int EffFire1__vfunc_02(EffFire1 *arg0, EffFire1Arg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    arg0->m_pos.x = arg1->m_x;
    arg0->m_pos.y = arg1->m_y;
    arg0->m_pos.z = arg1->m_z;
    arg0->m_pos.w = 1.0f;
    *(m2c_block16 *)&arg0->m_color = *(m2c_block16 *)&arg1->m_color;
    arg0->m_scale = arg1->m_scale;
    int rnd = Xi_func_0016AD94();
    arg0->m_intensity = 1.0f;
    arg0->m_fade = 0;
    arg0->m_tick = rnd;
    return 1;
}

extern int D_002F23E0;
extern "C" int EffFire1__vfunc_05(EffFire1 *arg0)
{
    unsigned int bits[3];
    float temp_f0;
    register float var_f0 PS2_REG("$f0");
    float var_f2;
    unsigned int temp_hi;

    var_f2 = 0.0f;
    temp_f0 = arg0->m_intensity + -0.25f;
    arg0->m_tick = arg0->m_tick + 1;
    arg0->m_intensity = temp_f0;
    if (!(temp_f0 < 0.0f)) {
        var_f2 = temp_f0;
    }
    arg0->m_intensity = var_f2;
    temp_hi = ((*(volatile unsigned int *)&arg0->m_tick) >> 1) % 96U;
    *(m2c_block12 *)bits = *(m2c_block12 *)&D_002F23E0;
    if (bits[temp_hi >> 5] & (1 << temp_hi)) {
        var_f0 = 1.0f;
        var_f2 += 0.75f;
        arg0->m_intensity = var_f2;
        if (!(var_f2 > 1.0f)) {
            var_f0 = var_f2;
        }
        arg0->m_intensity = var_f0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFire1__vfunc_08);

extern "C" void updateZDepth__8EffFire1(EffFire1 *arg0)
{
    EffVec4A8 v = arg0->m_pos;
    v.y += -1.9999999f;
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &v) - (arg0->m_scale + 10.0f);
}

extern "C" void liveActivateExec__8EffFire1(EffFire1 *arg0)
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

extern "C" int EffFire1Ex__vfunc_02(EffFire1Ex *arg0, EffFire1ExArg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    arg0->m_actor = arg1->m_actor;
    *(m2c_block32 *)arg0->m_nodeName = *(m2c_block32 *)arg1->m_nodeName;
    *(m2c_block16 *)&arg0->m_color = *(m2c_block16 *)&arg1->m_color;
    arg0->m_pos.w = 1.0f;
    arg0->m_tick = 0;
    arg0->m_fade = 0;
    *(int *)&arg0->m_scale = 0;
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2390);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23A0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23B8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23C8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F23F0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2400);

#ifdef TARGET_PS2
 #include "dog/dogactor.h"
#else
struct DogVector {
    float m_x, m_y, m_z, m_w;
    DogVector() { m_x = m_y = m_z = 0.0f; m_w = 1.0f; }
};
struct DogActor {
    int getNodeIndexByName(const char *);
    virtual void vfunc18(DogVector &theOut, int theNode);
};
#endif
extern "C" void X_updateZDepth__8EffFire1(EffFire1 *) asm("updateZDepth__8EffFire1");
extern "C" void updateZDepth__10EffFire1Ex(EffFire1Ex *arg0)
{
    DogVector pos;
    pos.m_z = pos.m_y = pos.m_x = 0.0f;
    pos.m_w = 1.0f;
    DogActor *actor = (DogActor *)arg0->m_actor;
    int node = actor->getNodeIndexByName(arg0->m_nodeName);
    ((DogActor *)arg0->m_actor)->vfunc18(pos, node);
    float x = pos.m_x;
    float y = pos.m_y;
    float z = pos.m_z;
    arg0->m_pos.x = x;
    arg0->m_pos.y = y;
    arg0->m_pos.z = z;
    X_updateZDepth__8EffFire1(arg0);
}

extern "C" int EffFire2__vfunc_02(EffFire2 *arg0, EffFire2Arg *arg1)
{
    int var_v0;

    void *mat = &arg0->m_mat;
    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        EffVec4A8 v = MakeEffVec4A8(arg1->m_rotX, arg1->m_rotY, arg1->m_rotZ, 0.0f);
        X_Fire2_func_00237340(mat);
        X_Fire2_func_002378B0(mat, mat, &v);
        float s = arg1->m_scale;
        v.w = 1.0f;
        v.z = 1.0f;
        v.y = s;
        v.x = s;
        X_Fire2_func_00237A40(mat, mat, &v);
        *(m2c_block12 *)arg0->m_mat.m[3] = *(m2c_block12 *)&arg1->m_pos;
        var_v0 = 1;
        arg0->m_alpha = arg1->m_alpha;
        arg0->m_tick = 0;
    }
    return var_v0;
}

extern "C" int EffFire2__vfunc_05(EffFire2 *arg0)
{
    arg0->m_tick = arg0->m_tick + 1;
    return 1;
}


extern "C" void EffFire2__vfunc_08(EffFire2 *arg0, EffRenderParam *arg1, int arg2, int arg3)
{
    int s0 = X_1548_func_0021B5A0(X_1548_func_0021B550(arg3, 0x42, 0x44), arg1->m_unk08);
    s0 = X_1548_func_0021B4F8(s0, X_1548_func_0021B260(arg2, 0));
    int s1 = X_1548_func_0021E5A0(s0, arg1->m_unk08, 1);
    unsigned int idx = (arg0->m_tick >> 2) & 3;
    unsigned int row = idx / 2;
    unsigned int col = idx - row * 2;
    struct { float u0, v0, u1, v1; } uv;
    uv.v0 = (float)(int)row * 0.5f;
    uv.u0 = (float)(int)col * 0.5f;
    uv.v1 = uv.v0 + 0.5f;
    uv.u1 = uv.u0 + 0.5f;
    int t = X_1548_func_0021E488(s1, &uv);
    struct Color4 {
        float x, y, z, w;
        static inline Color4 make(float x, float y, float z, float w) {
            Color4 r;
            r.x = x;
            r.y = y;
            r.z = z;
            r.w = w;
            return r;
        }
    } __attribute__((aligned(8)));
    Color4 color = Color4::make(1.0f, 1.0f, 1.0f, arg0->m_alpha);
    X_1548_func_0021E688(X_1548_func_0021E690(X_1548_func_0021E428(t, &arg0->m_mat), arg0->m_mat.m[3], &color));
}

extern "C" void updateZDepth__8EffFire2(EffFire2 *arg0)
{
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0->m_mat.m[3]);
}

extern "C" int EffFog1__vfunc_02(EffFog1 *arg0, EffFog1Arg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    arg0->m_sizeX = arg1->m_sizeX;
    arg0->m_sizeY = arg1->m_sizeY;
    arg0->m_unk58 = arg0->m_unk5C = 1.0f;
    *(m2c_block16 *)&arg0->m_pos = *(m2c_block16 *)&arg1->m_pos;
    arg0->m_pos.w = 1.0f;
    if (arg1->m_centerY != 0) {
        arg0->m_pos.y -= arg0->m_sizeY * 0.5f;
    }
    arg0->m_basePos = arg0->m_pos;
    arg0->m_unk60 = arg1->m_unk24;
    arg0->m_unk64 = arg1->m_unk28;
    arg0->m_tick = (Xi_func_0016AD94() * 540) / 255;
    return 1;
}

extern "C" int EffFog1__vfunc_05(EffFog1 *arg0)
{
    int temp_hi;

    temp_hi = (arg0->m_tick + 1) % 540;
    arg0->m_tick = temp_hi;
    if (temp_hi == 0) {
        arg0->m_pos = arg0->m_basePos;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog1__vfunc_08);

extern "C" void updateZDepth__7EffFog1(EffFog1 *arg0)
{
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &arg0->m_pos);
}

extern "C" int EffFog2__vfunc_02(EffFog2 *arg0, EffFog2Arg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    arg0->m_tick = -1;
    *(m2c_block12 *)&arg0->m_pos = *(m2c_block12 *)&arg1->m_pos;
    arg0->m_radius = arg1->m_radius;
    arg0->m_angle = Xff_func_0016FE88(arg1->m_angle);
    arg0->m_scale = arg1->m_scale;
    *(m2c_block16 *)&arg0->m_color = *(m2c_block16 *)&arg1->m_color;
    return 1;
}

// NON_MATCHING: 29/101 differ, 1 reloc differs, 20 edits
#ifdef NON_MATCHING
extern "C" void X_Fog2_func_00237830(void *, void *, float) asm("func_00237830");
struct EffFog2Mat {
    float x, y, z, w;
    float m[12];
};
struct EffFog2Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float x;
    float y;
    float z;
    float angle;
    float scale;
    m2c_block16 unk24;
    char pad34[0x4C];
};
extern "C" int EffFog2__vfunc_05(EffFog2 *arg0)
{
    int t = arg0->m_tick + 1;
    arg0->m_tick = t;
    if ((t % 30) == 0) {
        EffFog2Mat mat;
        float r = (float)((Xi_func_0016AD94() + arg0->m_tick) % 255) / 255.0f - 0.5f;
        X_Fire2_func_00237340(&mat);
        X_Fog2_func_00237830(&mat, &mat, arg0->m_angle);
        float ang = arg0->m_angle + (r * 90.0f * 3.1415926f) / 180.0f;
        float f = arg0->m_radius;
        float mx = mat.x;
        float my = mat.y;
        float mz = mat.z;
        float x = arg0->m_pos.x + mx * f * r;
        float z = arg0->m_pos.z + mz * f * r;
        float y = arg0->m_pos.y + my * f * r;
        EffFog2Param param;
        param.unk00 = 0x19;
        param.unk08 = 0;
        param.x = x;
        param.z = z;
        param.y = y;
        param.angle = Xff_func_0016FE88(ang);
        param.scale = arg0->m_scale;
        param.unk24 = *(m2c_block16 *)&arg0->m_color;
        X_func_00176CC8((void *)(D_00298E08 + 0x837E0), &param);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2__vfunc_05);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2Prim__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2Prim__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog2Prim__vfunc_08);

extern "C" void updateZDepth__11EffFog2Prim(EffFog2Prim *arg0)
{
    arg0->m_zDepth = Xii_func_0016FF18(D_00298E08 + 0x2AB70, &arg0->m_pos);
}

extern "C" void func_00172678()
{
    EffSpawnParam param;
    param.unk00 = 0x1A;
    param.unk08 = 0;
    unsigned int off = 0x837E0;
    X_func_00176CC8(D_006FBD80 + off, &param);
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2438);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2448);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2458);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2470);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F24A0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F24E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2520);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2560);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2580);

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F25C0);

// NON_MATCHING: 26/67 differ, 2 relocs differ, 17 edits
#ifdef NON_MATCHING
extern "C" int func_001726B4()
{
    GamList<ACHRstat *> *list = D_007812C0.getAchrListPtr();
    GamList<ACHRstat *>::iterator last = list->end();
    for (GamList<ACHRstat *>::iterator it = list->begin(); it != last; ++it) {
        int oid = (*it)->getOID();
        if (((unsigned int)oid >> 23 & 0x1F) == 2) {
            switch (X_27EC_func_00163BE4(X_27EC_D_007B2140, oid)) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (X_27EC_func_00163B20(X_27EC_D_007B2140, oid) != 4) {
                    return 1;
                }
                break;
            case 4:
                if (X_27EC_func_00163B20(X_27EC_D_007B2140, oid) != 6) {
                    return 1;
                }
                break;
            case 5:
                if (X_27EC_func_00163B20(X_27EC_D_007B2140, oid) != 6) {
                    return 1;
                }
                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                break;
            default:
                return 1;
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_001726B4);
#endif

extern "C" int func_001727EC()
{
    GamList<ACHRstat *> *list = D_007812C0.getAchrListPtr();
    GamList<ACHRstat *>::iterator last = list->end();
    for (GamList<ACHRstat *>::iterator it = list->begin(); it != last; ++it) {
        int oid = (*it)->getOID();
        if (((unsigned int)oid >> 23 & 0x1F) == 2) {
            switch (X_27EC_func_00163BE4(X_27EC_D_007B2140, oid)) {
            case 0:
                if (X_27EC_func_00163B20(X_27EC_D_007B2140, oid) != 4) {
                    return 0;
                }
                break;
            case 1:
                if (X_27EC_func_00163B20(X_27EC_D_007B2140, oid) != 4) {
                    return 0;
                }
                break;
            case 2:
                if (X_27EC_func_00163B20(X_27EC_D_007B2140, oid) != 4) {
                    return 0;
                }
                break;
            case 3:
                if (X_27EC_func_00163B20(X_27EC_D_007B2140, oid) != 4) {
                    return 0;
                }
                break;
            case 4:
            case 5:
                if (X_27EC_func_00163B20(X_27EC_D_007B2140, oid) != 6) {
                    return 0;
                }
                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                break;
            }
        }
    }
    return 1;
}

// NON_MATCHING: 93/98 differ, 3 relocs differ (size 0x188, game 0x194), 33 edits
#ifdef NON_MATCHING
struct FogParam2934 {
    float r, g, b, a;
    float unk10, unk14, unk18, unk1C;
} __attribute__((aligned(8)));
struct FogHolder2934 {
    char pad[0x2AB00];
    FogParam2934 fog;
};
extern char D_006E9840[];
extern FogHolder2934 X_2934_D_006FBD80 asm("D_006FBD80");
extern "C" void X_2934_func_00143EEC(void *, void *, int) asm("func_00143EEC");

extern "C" void func_00172934(int arg0, int arg1)
{
    FogParam2934 src = X_2934_D_006FBD80.fog;
    Fog3Entry *e = X_Fog3_D_00298E18;
    FogParam2934 dst;
    dst.unk10 = src.unk10 * e->unk04;
    float d = src.unk1C - src.unk14;
    dst.unk14 = src.unk14 + d * e->unk08;
    dst.unk18 = src.unk18 * e->unk04;
    dst.unk1C = src.unk1C * e->unk10;
    dst.r = (float)e->r / 255.0f;
    dst.g = (float)e->g / 255.0f;
    dst.b = (float)e->b / 255.0f;
    dst.a = 0.0f;
    if (arg0 != 0) {
        dst.unk10 -= src.unk10;
        dst.unk14 -= src.unk14;
        dst.unk18 -= src.unk18;
        dst.unk1C -= src.unk1C;
        dst.r -= src.r;
        dst.g -= src.g;
        dst.b -= src.b;
        dst.a -= src.a;
    } else {
        dst.unk10 = src.unk10 - dst.unk10;
        dst.unk14 = src.unk14 - dst.unk14;
        dst.unk18 = src.unk18 - dst.unk18;
        dst.unk1C = src.unk1C - dst.unk1C;
        dst.r = src.r - dst.r;
        dst.g = src.g - dst.g;
        dst.b = src.b - dst.b;
        dst.a = src.a - dst.a;
    }
    unsigned int off2 = 0x12540;
    X_2934_func_00143EEC(D_006E9840 + off2, &dst, arg1);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_00172934);
#endif

extern "C" void dtor_7EffFog3(EffFog3 *arg0, int arg1)
{
    arg0->m_vtbl = vtbl_7EffFog3;
    D_00298E18 = 0;
    X_dtor_4Eff0(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

extern "C" int EffFog3__vfunc_02(EffFog3 *arg0, Eff0Arg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    BedPfh pfh;
    int target = D_007A3210;
    pfh.setTop(((EffFog3Res *)arg0->m_parent)->m_pfhTop);
    EffFog3Res *res = (EffFog3Res *)arg0->m_parent;
    X_Fog3_D_00298E18 = (Fog3Entry *)pfh.getFileTop(res->m_cnt0 + res->m_cnt1 + res->m_cnt2);
    while (X_Fog3_D_00298E18->id != -1 && X_Fog3_D_00298E18->id != target) {
        X_Fog3_D_00298E18++;
    }
    D_00298E14 = 0;
    arg0->m_interval = 0x1E;
    arg0->m_tick = 0;
    if (Xi_func_001726B4()) {
        D_00298E14 |= 1;
        Xiii_func_00172934(1, 0);
    }
    return 1;
}

extern "C" int EffFog3__vfunc_05(EffFog3 *arg0)
{
    EffSpawnParam param;
    unsigned int temp_v0;
    int var_v0;

    temp_v0 = arg0->m_tick + 1;
    arg0->m_tick = temp_v0;
    if ((temp_v0 % arg0->m_interval) == 0) {
        if (D_00298E14 & 1) {
            if (Xi_func_001727EC()) {
                param.unk00 = 0x1C;
                param.unk08 = 0x96;
                X_func_00176CC8((void *)(D_00298E08 + 0x837E0), &param);
                var_v0 = 0xB4;
                goto done;
            }
        } else {
            if (Xi_func_001726B4()) {
                param.unk08 = 0;
                param.unk00 = 0x1B;
                X_func_00176CC8((void *)(D_00298E08 + 0x837E0), &param);
            }
        }
        var_v0 = 0x1E;
    done:
        arg0->m_interval = var_v0;
        arg0->m_tick = 0;
    }
    return 1;
}

extern "C" int EffFog3Dark__vfunc_02(Eff0 *arg0, Eff0Arg *arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    if (!(D_00298E14 & 1)) {
        D_00298E14 |= 1;
        Xiii_func_00172934(1, 0x1E);
    }
    return 1;
}

extern "C" int EffFog3WeakUp__vfunc_02()
{
    return X_Eff0__vfunc_02() != 0;
}


extern "C" int EffFog3WeakUp__vfunc_05()
{
    if ((*(int *)&D_00298E14) & 1) {
        (*(int *)&D_00298E14) &= ~1;
        Xiii_func_00172934(0, 0x5A);
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F2698);
INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F26A8);
INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F26B8);
INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F26C8);
INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F26D8);
INCLUDE_RODATA("asm/nonmatchings/unk/EffFire1", D_002F26E8);
