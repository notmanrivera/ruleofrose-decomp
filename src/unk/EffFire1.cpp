#include "include_asm.h"
#include "game/gamtrg.h"
#include "game/gamman.h"
#include "bed/bedpfh.h"
extern "C" int Xiii_func_00170624(int, int) asm("func_00170624");
extern int D_007A3210;
struct Fog3Entry {
    int id;
    char pad[0x1C];
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
struct EffFog3Param {
    int unk00;
    int unk04;
    int unk08;
    char pad0C[0x74];
};
extern "C" void X_func_00176CC8(void *, void *) asm("func_00176CC8");
extern "C" int Xi_func_001726B4() asm("func_001726B4");
extern "C" int Xi_func_001727EC() asm("func_001727EC");
struct Fire1702E4Vec3 {
    float x, y, z;
};
struct Fire1702E4Sub {
    char pad0[0x40];
    Fire1702E4Vec3 pos;
};
struct Fire1702E4Arg {
    int unk00;
    Fire1702E4Sub *sub;
    float cx, cy, cz;
    float r1, hy, unk1C, r2;
};
struct Fire2Vec4 {
    float x, y, z, w;
} __attribute__((aligned(8)));
static inline Fire2Vec4 MakeFire2Vec4(float x, float y, float z, float w)
{
    Fire2Vec4 r;
    r.y = y;
    r.z = z;
    r.x = x;
    r.w = w;
    return r;
}
extern "C" void X_Fire2_func_00237340(void *) asm("func_00237340");
extern "C" void X_Fire2_func_002378B0(void *, void *, void *) asm("func_002378B0");
extern "C" void X_Fire2_func_00237A40(void *, void *, void *) asm("func_00237A40");
struct m2c_block32 { int w[8]; };
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
extern "C" float Xff_func_0016FE88(float) asm("func_0016FE88");
struct Fire1Vec4 {
    float x, y, z, w;
} __attribute__((aligned(8)));
struct Eff2678Param {
    int unk00;
    int unk04;
    int unk08;
    char pad0C[0x74];
};
extern "C" void X_2678_func_00176CC8(void *, void *) asm("func_00176CC8");
extern char D_006FBD80[];
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
struct m2c_block12 { int w[3]; };
struct m2c_block16 { int w[4]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfi_func_0010DA4C__8DogActor(int) asm("func_0010DA4C__8DogActor");
extern "C" int Xiii_func_00172934(int, int) asm("func_00172934");
extern "C" int Xiiiff_func_0010BCC8__8DogActoriff(int, int, float, float) asm("func_0010BCC8__8DogActoriff");
extern "C" int Xiiii_func_00170158(int, int, int) asm("func_00170158");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_Eff0__vfunc_02(...) asm("Eff0__vfunc_02");
extern "C" int X_func_0016FF18(...) asm("func_0016FF18");
extern "C" int X_func_00170624(...) asm("func_00170624");
extern "C" int X_func_00172934(...) asm("func_00172934");
extern int D_00298E08;
extern int D_00298E14;
extern int D_00298E18;
extern int X_vt_7EffFog3 asm("_vt$7EffFog3");
extern "C" void X_dtor_4Eff0(void *, int) asm("_$_4Eff0");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_7EffFog3(int, int) asm("_$_7EffFog3");

extern "C" int func_001702E4(Fire1702E4Arg *arg0)
{
    Fire1702E4Sub *p = arg0->sub;
    float r = arg0->r1 + arg0->r2;
    Fire1702E4Vec3 pos;
    pos.x = p->pos.x;
    pos.y = p->pos.y;
    pos.z = p->pos.z;
    Fire1702E4Vec3 half = { r, arg0->hy, r };
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

extern "C" void func_001703C0(int arg0)
{
    float temp_f0;
    int temp_s0;
    int temp_v0;

    temp_s0 = M2C_FIELD(arg0, int *, 4);
    temp_f0 = Xfi_func_0010DA4C__8DogActor(temp_s0);
    if (temp_f0 >= 0.0f) {
        temp_v0 = Xiiiff_func_0010BCC8__8DogActoriff(temp_s0, -1, temp_f0, temp_f0 + 1.0f);
        if (temp_v0 & 0x10000000) {
            Xiiii_func_00170158(arg0, 0, (int) (int) "Bip01 L Toe0");
        }
        if (temp_v0 & 0x20000000) {
            Xiiii_func_00170158(arg0, 1, (int) (int) "Bip01 R Toe0");
        }
        if (temp_v0 & 0x04000000) {
            Xiiii_func_00170158(arg0, 2, (int) (int) "Bip01 L Finger0");
        }
        if (temp_v0 & 0x08000000) {
            Xiiii_func_00170158(arg0, 3, (int) (int) "Bip01 R Finger0");
        }
    }
}

extern "C" int EffDust2__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    *(m2c_block12 *)((char *)(arg0) + 0x30) = *(m2c_block12 *)((char *)(arg1) + 0x10);
    M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
    M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
    *(m2c_block12 *)((char *)(arg0) + 0x50) = *(m2c_block12 *)((char *)(arg1) + 0x20);
    M2C_FIELD(arg0, float *, 0x5C) = 1.0f;
    M2C_FIELD(arg0, float *, 0x60) = (float) M2C_FIELD(arg1, float *, 0x2C);
    *(m2c_block16 *)((char *)(arg0) + 0x70) = *(m2c_block16 *)((char *)(arg1) + 0x30);
    M2C_FIELD(arg0, float *, 0x80) = (float) M2C_FIELD(arg1, float *, 0x40);
    M2C_FIELD(arg0, short *, 0x84) = 0;
    struct Dust2Layout {
        char pad00[0x88];
        int unk88[12];
    };
    Dust2Layout *self = (Dust2Layout *)arg0;
    for (int i = 0; i < 12; i++) {
        self->unk88[i] = X_func_00170624(arg0, i * 8);
    }
    return 1;
}

struct Dust2Struct {
    char pad00[0x88];
    int unk88[12];
};
extern "C" int X_0594_func_00170624(int, int) asm("func_00170624");

extern "C" int EffDust2__vfunc_05(int arg0)
{
    Dust2Struct *self = (Dust2Struct *)arg0;
    for (int i = 0; i < 12; i++) {
        register int entry PS2_REG("$3") = D_00298E08;
        register int index PS2_REG("$2") = self->unk88[i] * 4;
        entry += index;
        if (*(int *)(entry + 0x837E4) == 0) {
            self->unk88[i] = X_0594_func_00170624(arg0, 0);
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", func_00170624);

extern "C" int EffDust2Prim__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        *(m2c_block12 *)((char *)(arg0) + 0x30) = *(m2c_block12 *)((char *)(arg1) + 0x10);
        var_v0 = 1;
        M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
        M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
        *(m2c_block16 *)((char *)(arg0) + 0x50) = *(m2c_block16 *)((char *)(arg1) + 0x20);
        M2C_FIELD(arg0, int *, 0x60) = 0;
    }
    return var_v0;
}

extern "C" int EffDust2Prim__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x60) + 1;
    M2C_FIELD(arg0, int *, 0x60) = temp_v0;
    M2C_FIELD(arg0, float *, 0x34) = (float) (M2C_FIELD(arg0, float *, 0x34) + -0.024999998975545168f);
    return temp_v0 < 0x96;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffDust2Prim__vfunc_08);

extern "C" void updateZDepth__12EffDust2Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int EffFire1__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    M2C_FIELD(arg0, float *, 0x30) = (float) M2C_FIELD(arg1, float *, 0x10);
    M2C_FIELD(arg0, float *, 0x34) = (float) M2C_FIELD(arg1, float *, 0x14);
    M2C_FIELD(arg0, float *, 0x38) = (float) M2C_FIELD(arg1, float *, 0x18);
    M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
    *(m2c_block16 *)((char *)(arg0) + 64) = *(m2c_block16 *)((char *)(arg1) + 28);
    M2C_FIELD(arg0, float *, 0x58) = (float) M2C_FIELD(arg1, float *, 0x2C);
    int rnd = Xi_func_0016AD94();
    M2C_FIELD(arg0, float *, 0x54) = 1.0f;
    M2C_FIELD(arg0, int *, 0x5C) = 0;
    M2C_FIELD(arg0, int *, 0x50) = rnd;
    return 1;
}

extern int D_002F23E0;
extern "C" int EffFire1__vfunc_05(int arg0)
{
    unsigned int bits[3];
    float temp_f0;
    register float var_f0 PS2_REG("$f0");
    float var_f2;
    unsigned int temp_hi;

    var_f2 = 0.0f;
    temp_f0 = M2C_FIELD(arg0, float *, 0x54) + -0.25f;
    M2C_FIELD(arg0, unsigned int *, 0x50) = (unsigned int) (M2C_FIELD(arg0, unsigned int *, 0x50) + 1);
    M2C_FIELD(arg0, float *, 0x54) = temp_f0;
    if (!(temp_f0 < 0.0f)) {
        var_f2 = temp_f0;
    }
    M2C_FIELD(arg0, float *, 0x54) = var_f2;
    temp_hi = (unsigned int) ((unsigned int) M2C_FIELD(arg0, volatile unsigned int *, 0x50) >> 1) % 96U;
    *(m2c_block12 *)bits = *(m2c_block12 *)&D_002F23E0;
    if (bits[temp_hi >> 5] & (1 << temp_hi)) {
        var_f0 = 1.0f;
        var_f2 += 0.75f;
        M2C_FIELD(arg0, float *, 0x54) = var_f2;
        if (!(var_f2 > 1.0f)) {
            var_f0 = var_f2;
        }
        M2C_FIELD(arg0, float *, 0x54) = var_f0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFire1__vfunc_08);

extern "C" void updateZDepth__8EffFire1(int arg0)
{
    Fire1Vec4 v = *(Fire1Vec4 *)((char *)arg0 + 0x30);
    v.y += -1.9999999f;
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, (int)&v) - (M2C_FIELD(arg0, float *, 0x58) + 10.0f);
}

extern "C" void liveActivateExec__8EffFire1(int arg0)
{
    int temp_a2;
    int temp_v0;
    int temp_v0_2;
    unsigned short temp_a1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x5C);
    temp_a1 = M2C_FIELD(arg0, unsigned short *, 0);
    temp_v0_2 = temp_v0 - 1;
    temp_a2 = temp_v0 + 1;
    if (temp_a1 & 4) {
        M2C_FIELD(arg0, int *, 0x5C) = temp_a2;
        if (temp_a2 >= 5) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    } else {
        M2C_FIELD(arg0, int *, 0x5C) = temp_v0_2;
        if (temp_v0_2 <= 0) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    }
}

extern "C" int EffFire1Ex__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    M2C_FIELD(arg0, int *, 0x60) = (int) M2C_FIELD(arg1, int *, 0x10);
    *(m2c_block32 *)((char *)(arg0) + 100) = *(m2c_block32 *)((char *)(arg1) + 20);
    *(m2c_block16 *)((char *)(arg0) + 64) = *(m2c_block16 *)((char *)(arg1) + 52);
    M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
    M2C_FIELD(arg0, int *, 0x50) = 0;
    M2C_FIELD(arg0, int *, 0x5C) = 0;
    M2C_FIELD(arg0, int *, 0x58) = 0;
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
extern "C" void X_updateZDepth__8EffFire1(int) asm("updateZDepth__8EffFire1");
extern "C" void updateZDepth__10EffFire1Ex(int arg0)
{
    DogVector pos;
    pos.m_z = pos.m_y = pos.m_x = 0.0f;
    pos.m_w = 1.0f;
    int node = M2C_FIELD(arg0, DogActor **, 0x60)->getNodeIndexByName((const char *)(arg0 + 0x64));
    M2C_FIELD(arg0, DogActor **, 0x60)->vfunc18(pos, node);
    float x = pos.m_x;
    float y = pos.m_y;
    float z = pos.m_z;
    M2C_FIELD(arg0, float *, 0x30) = x;
    M2C_FIELD(arg0, float *, 0x34) = y;
    M2C_FIELD(arg0, float *, 0x38) = z;
    X_updateZDepth__8EffFire1(arg0);
}

extern "C" int EffFire2__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    void *mat = (void *)(arg0 + 0x30);
    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        Fire2Vec4 v = MakeFire2Vec4(
            M2C_FIELD(arg1, float *, 0x1C),
            M2C_FIELD(arg1, float *, 0x20),
            M2C_FIELD(arg1, float *, 0x24),
            0.0f
        );
        X_Fire2_func_00237340(mat);
        X_Fire2_func_002378B0(mat, mat, &v);
        float s = M2C_FIELD(arg1, float *, 0x28);
        v.w = 1.0f;
        v.z = 1.0f;
        v.y = s;
        v.x = s;
        X_Fire2_func_00237A40(mat, mat, &v);
        *(m2c_block12 *)((char *)(arg0) + 96) = *(m2c_block12 *)((char *)(arg1) + 16);
        var_v0 = 1;
        M2C_FIELD(arg0, float *, 0x28) = (float) M2C_FIELD(arg1, float *, 0x2C);
        M2C_FIELD(arg0, int *, 0x24) = 0;
    }
    return var_v0;
}

extern "C" int EffFire2__vfunc_05(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x24)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x24)) + 1);
    return 1;
}


extern "C" void EffFire2__vfunc_08(int arg0, int arg1, int arg2, int arg3)
{
    int s0 = X_1548_func_0021B5A0(X_1548_func_0021B550(arg3, 0x42, 0x44), M2C_FIELD(arg1, int *, 8));
    s0 = X_1548_func_0021B4F8(s0, X_1548_func_0021B260(arg2, 0));
    int s1 = X_1548_func_0021E5A0(s0, M2C_FIELD(arg1, int *, 8), 1);
    unsigned int idx = ((unsigned int)M2C_FIELD(arg0, unsigned int *, 0x24) >> 2) & 3;
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
    Color4 color = Color4::make(1.0f, 1.0f, 1.0f, M2C_FIELD(arg0, float *, 0x28));
    X_1548_func_0021E688(X_1548_func_0021E690(X_1548_func_0021E428(t, (void *)(arg0 + 0x30)), (void *)(arg0 + 0x60), &color));
}

extern "C" void updateZDepth__8EffFire2(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x60);
}

extern "C" int EffFog1__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    M2C_FIELD(arg0, float *, 0x50) = M2C_FIELD(arg1, float *, 0x1C);
    M2C_FIELD(arg0, float *, 0x54) = M2C_FIELD(arg1, float *, 0x20);
    M2C_FIELD(arg0, float *, 0x58) = M2C_FIELD(arg0, float *, 0x5C) = 1.0f;
    *(m2c_block16 *)((char *)(arg0) + 0x30) = *(m2c_block16 *)((char *)(arg1) + 0x10);
    M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
    if (M2C_FIELD(arg1, int *, 0x2C) != 0) {
        M2C_FIELD(arg0, float *, 0x34) -= M2C_FIELD(arg0, float *, 0x54) * 0.5f;
    }
    *(Fire1Vec4 *)((char *)(arg0) + 0x40) = *(Fire1Vec4 *)((char *)(arg0) + 0x30);
    M2C_FIELD(arg0, float *, 0x60) = M2C_FIELD(arg1, float *, 0x24);
    M2C_FIELD(arg0, float *, 0x64) = M2C_FIELD(arg1, float *, 0x28);
    M2C_FIELD(arg0, int *, 0x68) = (Xi_func_0016AD94() * 540) / 255;
    return 1;
}

extern "C" int EffFog1__vfunc_05(int arg0)
{
    int temp_hi;

    temp_hi = (int) (M2C_FIELD(arg0, int *, 0x68) + 1) % 540;
    M2C_FIELD(arg0, int *, 0x68) = temp_hi;
    if (temp_hi == 0) {
        M2C_FIELD(arg0, long *, 0x30) = (long) M2C_FIELD(arg0, long *, 0x40);
        M2C_FIELD(arg0, long *, 0x38) = (long) M2C_FIELD(arg0, long *, 0x48);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffFire1", EffFog1__vfunc_08);

extern "C" void updateZDepth__7EffFog1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int EffFog2__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    M2C_FIELD(arg0, int *, 0x24) = -1;
    *(m2c_block12 *)((char *)(arg0) + 40) = *(m2c_block12 *)((char *)(arg1) + 16);
    M2C_FIELD(arg0, float *, 0x38) = (float) M2C_FIELD(arg1, float *, 0x20);
    M2C_FIELD(arg0, float *, 0x34) = Xff_func_0016FE88(M2C_FIELD(arg1, float *, 0x1C));
    M2C_FIELD(arg0, float *, 0x3C) = (float) M2C_FIELD(arg1, float *, 0x24);
    *(m2c_block16 *)((char *)(arg0) + 64) = *(m2c_block16 *)((char *)(arg1) + 40);
    return 1;
}

// NON_MATCHING: 29/101 differ, 1 reloc differs, 20 edits
#ifdef NON_MATCHING
extern "C" void X_Fog2_func_00237830(void *, void *, float) asm("func_00237830");
struct EffFog2Mat {
    float x, y, z, w;
    float m[12];
};
struct EffFog2Block16 {
    int w[4];
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
    EffFog2Block16 unk24;
    char pad34[0x4C];
};
extern "C" int EffFog2__vfunc_05(int arg0)
{
    int t = M2C_FIELD(arg0, int *, 0x24) + 1;
    M2C_FIELD(arg0, int *, 0x24) = t;
    if ((t % 30) == 0) {
        EffFog2Mat mat;
        float r = (float)((Xi_func_0016AD94() + M2C_FIELD(arg0, int *, 0x24)) % 255) / 255.0f - 0.5f;
        X_Fire2_func_00237340(&mat);
        X_Fog2_func_00237830(&mat, &mat, M2C_FIELD(arg0, float *, 0x34));
        float ang = M2C_FIELD(arg0, float *, 0x34) + (r * 90.0f * 3.1415926f) / 180.0f;
        float f = M2C_FIELD(arg0, float *, 0x38);
        float mx = mat.x;
        float my = mat.y;
        float mz = mat.z;
        float x = M2C_FIELD(arg0, float *, 0x28) + mx * f * r;
        float z = M2C_FIELD(arg0, float *, 0x30) + mz * f * r;
        float y = M2C_FIELD(arg0, float *, 0x2C) + my * f * r;
        EffFog2Param param;
        param.unk00 = 0x19;
        param.unk08 = 0;
        param.x = x;
        param.z = z;
        param.y = y;
        param.angle = Xff_func_0016FE88(ang);
        param.scale = M2C_FIELD(arg0, float *, 0x3C);
        param.unk24 = *(EffFog2Block16 *)((char *)arg0 + 0x40);
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

extern "C" void updateZDepth__11EffFog2Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" void func_00172678()
{
    Eff2678Param param;
    param.unk00 = 0x1A;
    param.unk08 = 0;
    unsigned int off = 0x837E0;
    X_2678_func_00176CC8(D_006FBD80 + off, &param);
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
 #include "game/gamtrg.h"
 #include "game/gamman.h"
extern char D_007B2140[];
extern "C" int X_26B4_func_00163BE4(void *, int) asm("func_00163BE4");
extern "C" int X_26B4_func_00163B20(void *, int) asm("func_00163B20");
extern "C" int func_001726B4()
{
    GamList<ACHRstat *> *list = D_007812C0.getAchrListPtr();
    GamList<ACHRstat *>::iterator last = list->end();
    for (GamList<ACHRstat *>::iterator it = list->begin(); it != last; ++it) {
        int oid = (*it)->getOID();
        if (((unsigned int)oid >> 23 & 0x1F) == 2) {
            switch (X_26B4_func_00163BE4(D_007B2140, oid)) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (X_26B4_func_00163B20(D_007B2140, oid) != 4) {
                    return 1;
                }
                break;
            case 4:
                if (X_26B4_func_00163B20(D_007B2140, oid) != 6) {
                    return 1;
                }
                break;
            case 5:
                if (X_26B4_func_00163B20(D_007B2140, oid) == 6) {
                    continue;
                }
                return 1;
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
struct FogEntry2934 {
    int id;
    float unk04;
    float unk08;
    int unk0C;
    float unk10;
    int r, g, b;
};
extern char D_006E9840[];
extern FogHolder2934 X_2934_D_006FBD80 asm("D_006FBD80");
extern FogEntry2934 *X_2934_D_00298E18 asm("D_00298E18");
extern "C" void X_2934_func_00143EEC(void *, void *, int) asm("func_00143EEC");

extern "C" void func_00172934(int arg0, int arg1)
{
    FogParam2934 src = X_2934_D_006FBD80.fog;
    FogEntry2934 *e = X_2934_D_00298E18;
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

extern "C" void dtor_7EffFog3(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x20) = (int)&X_vt_7EffFog3;
    D_00298E18 = 0;
    X_dtor_4Eff0((void *)arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

extern "C" int EffFog3__vfunc_02(int arg0, int arg1)
{
    if (!Xiii_Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    BedPfh pfh;
    int target = D_007A3210;
    pfh.setTop(M2C_FIELD(M2C_FIELD(arg0, char **, 0x14), void **, 0x28));
    char *unk14 = M2C_FIELD(arg0, char **, 0x14);
    X_Fog3_D_00298E18 = (Fog3Entry *)pfh.getFileTop(
        M2C_FIELD(unk14, int *, 0x50) + M2C_FIELD(unk14, int *, 0x54) + M2C_FIELD(unk14, int *, 0x58)
    );
    while (X_Fog3_D_00298E18->id != -1 && X_Fog3_D_00298E18->id != target) {
        X_Fog3_D_00298E18++;
    }
    D_00298E14 = 0;
    M2C_FIELD(arg0, int *, 0x28) = 0x1E;
    M2C_FIELD(arg0, int *, 0x24) = 0;
    if (Xi_func_001726B4()) {
        D_00298E14 |= 1;
        Xiii_func_00172934(1, 0);
    }
    return 1;
}

extern "C" int EffFog3__vfunc_05(int arg0)
{
    EffFog3Param param;
    unsigned int temp_v0;
    int var_v0;

    temp_v0 = M2C_FIELD(arg0, unsigned int *, 0x24) + 1;
    M2C_FIELD(arg0, unsigned int *, 0x24) = temp_v0;
    if ((temp_v0 % M2C_FIELD(arg0, unsigned int *, 0x28)) == 0) {
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
        M2C_FIELD(arg0, int *, 0x28) = var_v0;
        M2C_FIELD(arg0, int *, 0x24) = 0;
    }
    return 1;
}

extern "C" int EffFog3Dark__vfunc_02(int arg0, int arg1)
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
