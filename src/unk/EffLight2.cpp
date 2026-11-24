#include "include_asm.h"
#include "unk/EffLight2.h"

struct EffRetSub {
    unsigned char m_pad0[8];
    unsigned short m_count;
};

struct DogLightAmbient {
    float m_color[4];
} __attribute__((aligned(8)));

struct DogLightPool {
    void *m_light[6];
    int m_num[6];
    DogLightAmbient *getAmbient(int n);
};

extern "C" const char D_002F2700[];
extern "C" const char D_002F2710[];
extern "C" const char D_002F2720[];
extern "C" const char D_002F2730[];
extern "C" const char D_002F28D0[];
extern "C" const char D_002F28E8[];
extern "C" const char D_002F2910[];
extern "C" void ror_assert(const char *file, int line, const char *expr);

inline DogLightAmbient *DogLightPool::getAmbient(int n)
{
    if (!(n >= 0 && n < m_num[0])) ror_assert(D_002F28D0, 0x81, D_002F28E8);
    if (!m_light[0]) ror_assert(D_002F28D0, 0x81, D_002F2910);
    return &((DogLightAmbient *)m_light[0])[n];
}

extern "C" int X_Eff0__vfunc_02(void *, void *) asm("Eff0__vfunc_02");
extern "C" void func_0016A914(Eff0 *);
extern "C" void X__$_4Eff0(void *, int) asm("_$_4Eff0");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_free__9BedMemoryPv(void *, void *) asm("free__9BedMemoryPv");
extern "C" void X_freeID__12DogLightPoolii(void *, int, int) asm("freeID__12DogLightPoolii");
extern "C" int X_I3rRoot__CheckIdString(int) asm("I3rRoot__CheckIdString");
extern "C" int X_func_0013FE64__8MagSceneii(int, int, int) asm("func_0013FE64__8MagSceneii");
extern "C" float X_func_0010DA4C__8DogActor(void *) asm("func_0010DA4C__8DogActor");
extern "C" int X_func_0010BCC8__8DogActoriff(void *, int, float, float) asm("func_0010BCC8__8DogActoriff");
extern "C" float X_func_0016FC20(EffVec4A8 *) asm("func_0016FC20");
extern "C" float X_func_0016FF18(int, void *) asm("func_0016FF18");
extern "C" EffRetSub **X_func_001700B0(char *, float *, int *) asm("func_001700B0");
extern "C" int X_func_001702E4(EffFoot1CheckArg *) asm("func_001702E4");
extern "C" void X_func_001703C0(EffFoot1CheckArg *) asm("func_001703C0");
extern "C" void X_func_001730D4(EffFoot1 *, void *) asm("func_001730D4");
extern "C" int X_func_00173380(EffFoot1Prim *) asm("func_00173380");
extern "C" int X_func_001733CC(EffFoot1Prim *, int, int, int) asm("func_001733CC");
extern "C" int X_func_00173610() asm("func_00173610");
extern "C" int X_func_00173618(EffFoot1Prim *, int, int, int) asm("func_00173618");
extern "C" int X_func_00173620() asm("func_00173620");
extern "C" int X_func_00173628(EffFoot1Prim *, int, int, int) asm("func_00173628");
extern "C" void X_func_00173840(void *, void *, EffFoot2State *) asm("func_00173840");
extern "C" void X_func_00173948(void *, void *, const char *, EffFoot2State *) asm("func_00173948");
extern "C" void X_func_00174C4C(EffGeneric1 *, float *, float, float) asm("func_00174C4C");
extern "C" float X_func_00174D14(EffGeneric1 *, EffGenericTrack *) asm("func_00174D14");
extern "C" void X_func_0017653C(EffLight3 *) asm("func_0017653C");
extern "C" void X_func_001765E8(EffLight3 *, float) asm("func_001765E8");
extern "C" void X_func_00176CC8(int, EffFoot1SpawnParam *) asm("func_00176CC8");
extern "C" int X_func_0022AAB8(EffRetSub **) asm("func_0022AAB8");
extern "C" int X_func_0022AAD0(EffRetSub **, int) asm("func_0022AAD0");
extern "C" void X_func_0021AB30(int, EffVec4 *) asm("func_0021AB30");
extern "C" void X_func_00237408(EffVec4A8 *, EffVec4A8 *, float *) asm("func_00237408");
extern "C" float X_modff(float, float *) asm("modff");
extern "C" void X_render__4Eff0PQ24Eff011RENDERPARAM(...) asm("render__4Eff0PQ24Eff011RENDERPARAM");

extern int D_00298E08;
extern int D_006E9800;
extern EffFoot2State D_00828618;
extern EffFoot2State D_00828648;
extern int vtbl_EffGeneric1 asm("_vt$11EffGeneric1");
extern int vtbl_EffLight3 asm("_vt$9EffLight3");

struct EffEntityView {
    char m_pad0[0x94];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual int isInactive();
};

struct EffActorView : public EffEntityView {
    char m_pad98[0x84];
    int m_i3r_root;
    int hasRoot() {
        if (m_i3r_root != 0 && X_I3rRoot__CheckIdString(m_i3r_root) != 0) {
            ror_assert(D_002F2720, 0xF8, D_002F2730);
        }
        return m_i3r_root != 0;
    }
};

struct EffPcHolder {
    char m_pad[20];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual EffActorView *getActor();
};

struct EffSceneView {
    char m_pad0[0x2920];
    char m_actors[128][0x4D0];
    char m_pad29120[0x5C294];
    int m_curdog;
    EffActorView *getCurDog() {
        if (m_curdog < 0) {
            ror_assert(D_002F2700, 0x2C4, D_002F2710);
        }
        return (EffActorView *)m_actors[m_curdog];
    }
};

class EffCamView {
public:
    EffMat4 m_mat;
    char m_pad40[0x54];
    virtual void vfunc0();
    virtual void transform();
};

class Eff0Render {
public:
    unsigned short m_flags;             // +0x00
    char m_pad02[0x1A];
    int m_unk1C;                        // +0x1C
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(EffRenderParam *);
};

class EffLight2Render : public Eff0Render {
public:
    char m_pad24[0x0C];
    EffVec4A8 m_pos;                    // +0x30
    char m_pad40[0x28];
    float m_unk68;                      // +0x68
    float m_dist;                       // +0x6C
};

extern "C" int EffFoot1__vfunc_02(EffFoot1 *self, EffFoot1Arg *arg1)
{
    if (X_Eff0__vfunc_02(self, arg1) == 0) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (arg1->m_p0[i] <= arg1->m_p1[i]) {
            self->m_center[i] = arg1->m_p0[i];
            self->m_size[i] = arg1->m_p1[i];
        } else {
            self->m_center[i] = arg1->m_p1[i];
            self->m_size[i] = arg1->m_p0[i];
        }
        self->m_size[i] -= self->m_center[i];
        self->m_center[i] += self->m_size[i] * 0.5f;
    }
    self->m_unk3C = arg1->m_unk28;
    self->m_unk40 = arg1->m_unk2C;
    self->m_unk44 = arg1->m_unk30;
    self->m_unk48 = arg1->m_unk34;
    return 1;
}

extern "C" int EffFoot1__vfunc_05(EffFoot1 *self)
{
    EffPcHolder *pc = (EffPcHolder *)(D_00298E08 + 0x2ADC0);
    EffActorView *pcActor = pc->getActor();
    EffActorView *dog = ((EffSceneView *)D_00298E08)->getCurDog();
    if (pcActor != 0) {
        if (pcActor->hasRoot() && pcActor->isInactive() == 0) {
            X_func_001730D4(self, pcActor);
        }
    }
    if (dog->hasRoot() && dog->isInactive() == 0) {
        X_func_001730D4(self, dog);
    }
    return 1;
}

extern "C" void func_001730D4(EffFoot1 *self, void *actor)
{
    EffFoot1CheckArg chk;
    chk.m_actor = actor;
    chk.m_cx = self->m_center[0];
    chk.m_cy = self->m_center[1];
    chk.m_cz = self->m_center[2];
    chk.m_r1 = self->m_size[0];
    chk.m_hy = self->m_size[1];
    chk.m_unk1C = self->m_size[2];
    chk.m_r2 = 100.0f;
    chk.m_flags = 0;
    if (X_func_001702E4(&chk) != 0) {
        EffFoot1SpawnParam param;
        param.m_kind = 0x1E;
        param.m_unk1C = self->m_unk3C;
        param.m_unk20 = self->m_unk40;
        param.m_unk24 = self->m_unk44;
        param.m_unk28 = self->m_unk48;
        param.m_unk08 = 0;
        X_func_001703C0(&chk);
        for (int i = 0; i < 4; i++) {
            if (chk.m_flags & (1 << i)) {
                param.m_pos[0] = chk.m_pts[i][0];
                param.m_pos[1] = chk.m_pts[i][1];
                param.m_pos[2] = chk.m_pts[i][2];
                X_func_00176CC8(D_00298E08 + 0x837E0, &param);
            }
        }
    }
}

extern "C" int EffFoot1Prim__vfunc_02(EffFoot1Prim *self, EffFoot1PrimArg *arg1)
{
    if (X_Eff0__vfunc_02(self, arg1) == 0) {
        return 0;
    }
    self->m_pos.x = arg1->m_x;
    self->m_pos.y = arg1->m_y;
    self->m_pos.z = arg1->m_z;
    self->m_pos.w = 1.0f;
    self->m_unk40 = arg1->m_unk1C;
    self->m_mode = arg1->m_unk20;
    self->m_unk4C = arg1->m_unk24;
    self->m_unk50 = arg1->m_unk28;
    self->m_frame = 0;
    return 1;
}

extern "C" int EffFoot1Prim__vfunc_05(EffFoot1Prim *self)
{
    switch (self->m_mode) {
    case 0:
        return X_func_00173380(self);
    case 1:
        return X_func_00173610();
    case 2:
        return X_func_00173620();
    }
    return 0;
}

extern "C" int EffFoot1Prim__vfunc_08(EffFoot1Prim *self, int arg1, int arg2, int arg3)
{
    switch (self->m_mode) {
    case 0:
        return X_func_001733CC(self, arg1, arg2, arg3);
    case 1:
        return X_func_00173618(self, arg1, arg2, arg3);
    case 2:
        return X_func_00173628(self, arg1, arg2, arg3);
    }
    return arg3;
}

extern "C" void updateZDepth__12EffFoot1Prim(EffFoot1Prim *self)
{
    self->m_zDepth = X_func_0016FF18(D_00298E08 + 0x2AB70, &self->m_pos);
}

extern "C" int func_00173380(EffFoot1Prim *self)
{
    int ret = 1;
    int frame = self->m_frame + 1;
    self->m_frame = frame;
    if (!((((float)frame * -0.049999997951090336f) + 1.0f) > 0.0f)) {
        ret = 0;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001733CC);

extern "C" int func_00173610()
{
    return 0;
}

extern "C" int func_00173618(int arg0, int arg1, int arg2, int arg3)
{
    (void)arg0;
    (void)arg1;
    (void)arg2;
    return arg3;
}

extern "C" int func_00173620()
{
    return 0;
}

extern "C" int func_00173628(int arg0, int arg1, int arg2, int arg3)
{
    (void)arg0;
    (void)arg1;
    (void)arg2;
    return arg3;
}

extern "C" int EffFoot2__vfunc_02(void *self, void *arg1)
{
    if (X_Eff0__vfunc_02(self, arg1) == 0) {
        return 0;
    }
    D_00828648.m_unk00 = 0;
    D_00828648.m_unk04 = 0;
    D_00828648.m_unk08 = 10.0f;
    D_00828618.m_unk00 = 0x10;
    D_00828618.m_unk04 = 0;
    D_00828618.m_unk08 = 10.0f;
    return 1;
}

extern "C" int EffFoot2__vfunc_05(void *self)
{
    if (D_00828648.m_unk04 > 0) {
        EffPcHolder *pc = (EffPcHolder *)(D_00298E08 + 0x2ADC0);
        EffActorView *a = pc->getActor();
        if (a != 0) {
            if (a->hasRoot() && a->isInactive() == 0) {
                X_func_00173840(self, a, &D_00828648);
            }
        }
    }
    if (D_00828618.m_unk04 > 0) {
        EffActorView *dog = ((EffSceneView *)D_00298E08)->getCurDog();
        if (dog->hasRoot() && dog->isInactive() == 0) {
            X_func_00173840(self, dog, &D_00828618);
        }
    }
    return 1;
}

// D_002F2698..D_002F26E8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2700);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2710);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2720);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2730);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2760);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2770);

extern "C" void func_00173840(void *self, void *actor, EffFoot2State *state)
{
    float f = X_func_0010DA4C__8DogActor(actor);
    if (f >= 0.0f) {
        int bits = X_func_0010BCC8__8DogActoriff(actor, -1, f, f + 1.0f);
        if (bits & 0x10000000) {
            X_func_00173948(self, actor, "Bip01 L Toe0", state);
        }
        if (bits & 0x20000000) {
            X_func_00173948(self, actor, "Bip01 R Toe0", state);
        }
        if (bits & 0x04000000) {
            X_func_00173948(self, actor, "Bip01 L Finger0", state);
        }
        if (bits & 0x08000000) {
            X_func_00173948(self, actor, "Bip01 R Finger0", state);
        }
    }
}

// NON_MATCHING: 2/82 differ, 2 edits
#ifdef NON_MATCHING
extern "C" int X_173948_22B3D8(void *, const char *) asm("func_0022B3D8");
extern "C" void X_173948_176CC8(int, void *) asm("func_00176CC8");
struct Vec4_173948 {
    float x, y, z, w;
    Vec4_173948() {
        z = y = x = 0.0f;
        w = 1.0f;
    }
} __attribute__((aligned(16)));
struct EffParam_173948 {
    int kind;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float pos[3];
    float f20;
    float f24;
    char pad28[0x58];
};
class DogEntity_173948 {
public:
    char pad0[0x40];
    float x, y, z;              // 0x40..0x48
    char pad4C[0x8];
    float f54;                  // 0x54
    char pad58[0x3C];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17();
    virtual void v18(Vec4_173948 *, int);
};
class DogModel_173948 : public DogEntity_173948 {
public:
    char pad98[0x84];
    void *m_i3r_root;           // 0x11C
    int getNodeIndexByName(const char *p) {
        if (!m_i3r_root) ror_assert(D_002F2720, 0x131, "m_i3r_root");
        if (!p) ror_assert(D_002F2720, 0x131, "p");
        return X_173948_22B3D8(m_i3r_root, p);
    }
};
extern "C" void func_00173948(void *arg0, DogModel_173948 *arg1, const char *arg2, EffFoot2State *arg3)
{
    (void)arg0;
    EffVec3 pos;
    pos.x = arg1->x;
    pos.y = arg1->y;
    pos.z = arg1->z;
    Vec4_173948 vec;
    arg1->v18(&vec, arg1->getNodeIndexByName(arg2));
    EffParam_173948 param;
    param.kind = 0x20;
    param.unk10 = arg3->m_unk00;
    param.pos[0] = vec.x;
    param.pos[1] = pos.y;
    param.pos[2] = vec.z;
    param.f20 = arg1->f54;
    param.f24 = arg3->m_unk08;
    param.unk08 = 0;
    X_173948_176CC8(D_00298E08 + 0x837E0, &param);
    arg3->m_unk04--;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00173948);
#endif

extern "C" int EffFoot2Prim__vfunc_02(EffFoot2Prim *self, EffFoot2PrimArg *arg1)
{
    if (X_Eff0__vfunc_02(self, arg1) == 0) {
        return 0;
    }
    self->m_flags |= 0x10;
    self->m_unk24 = arg1->m_unk10;
    self->m_pos = arg1->m_pos;
    self->m_w = 1.0f;
    self->m_pos.y += -2.0f;
    self->m_unk40 = arg1->m_unk20;
    self->m_unk44 = arg1->m_unk24;
    self->m_frame = 0;
    return 1;
}

extern "C" int EffFoot2Prim__vfunc_05(EffFoot2Prim *self)
{
    if ((self->m_flags & 2) && (self->m_frame < 0xA5)) {
        self->m_frame = 0xA5;
    }
    int frame = self->m_frame + 1;
    self->m_frame = frame;
    return frame < 0xB4;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot2Prim__vfunc_08);

EffGeneric1::EffGeneric1()
{
    func_0016A914(this);
    m_zDepth = 0.0f;
    m_buf24 = 0;
    m_unk28 = 0;
    m_buf2C = 0;
    m_unk30 = 0;
    m_unk34 = 0;
    m_buf38 = 0;
    m_data = 0;
    m_vtbl = &vtbl_EffGeneric1;
}

extern "C" void EffGeneric1_dtor(EffGeneric1 *self, int flags) asm("_$_11EffGeneric1");
extern "C" void EffGeneric1_dtor(EffGeneric1 *self, int flags)
{
    self->m_vtbl = &vtbl_EffGeneric1;
    if (self->m_buf24 != 0) {
        X_free__9BedMemoryPv(&D_006E9800, self->m_buf24);
        self->m_buf24 = 0;
    }
    if (self->m_buf2C != 0) {
        X_free__9BedMemoryPv(&D_006E9800, self->m_buf2C);
        self->m_buf2C = 0;
        self->m_unk30 = 0;
        self->m_unk34 = 0;
    }
    if (self->m_buf38 != 0) {
        X_free__9BedMemoryPv(&D_006E9800, self->m_buf38);
        self->m_buf38 = 0;
    }
    if (self->m_uvList != 0) {
        X_free__9BedMemoryPv(&D_006E9800, self->m_uvList);
        self->m_uvList = 0;
    }
    if (self->m_data != 0) {
        X_free__9BedMemoryPv(&D_006E9800, self->m_data);
        self->m_data = 0;
    }
    X__$_4Eff0(self, 0);
    if (flags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F27E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F27F0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2800);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2810);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2820);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffGeneric1__vfunc_02);

extern "C" int EffGeneric1__vfunc_05(EffGeneric1 *self)
{
    float ipart;
    self->m_curFrame++;
    if (self->m_curFrame > self->m_maxFrame) {
        self->m_curFrame = self->m_curFrame - self->m_maxFrame - 1;
    }
    char *p = (char *)self->m_data + 0x10;
    for (int i = 0; i < self->m_data->m_chunkCount; i++) {
        EffGenericChunk *c = (EffGenericChunk *)p;
        if (c->m_type == 4) {
            c->m_u += c->m_du / 60.0f;
            c->m_v += c->m_dv / 60.0f;
            c->m_u = X_modff(c->m_u, &ipart);
            c->m_v = X_modff(c->m_v, &ipart);
        }
        p += c->m_size;
    }
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2870);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2880);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", renderPreMain__11EffGeneric1PQ24Eff011RENDERPARAM);

extern "C" void func_001749FC(EffGeneric1 *self, EffGenericTrack *track, float *out)
{
    float v = X_func_00174D14(self, track);
    if (track->m_mask & 1) {
        out[0] = v;
    }
    if (track->m_mask & 2) {
        out[1] = v;
    }
    if (track->m_mask & 4) {
        out[2] = v;
    }
}

extern "C" void func_00174A60(EffGeneric1 *self, EffGenericTrack *track, float *out)
{
    if (!(self->m_data->m_flags & 4)) {
        float v = X_func_00174D14(self, track);
        if (track->m_mask & 1) {
            out[0] = v;
        }
        if (track->m_mask & 2) {
            out[1] = v;
        }
        if (track->m_mask & 4) {
            out[2] = v;
        }
    }
}

extern "C" void func_00174AD8(EffGeneric1 *self, EffGenericTrack *track, float *out)
{
    float v = X_func_00174D14(self, track);
    if (track->m_mask & 1) {
        out[0] = v;
    }
    if (track->m_mask & 2) {
        out[1] = v;
    }
    if (track->m_mask & 4) {
        out[2] = v;
    }
}

extern "C" void func_00174B3C(EffGeneric1 *self, EffGenericTrack *track, float *out)
{
    float v = X_func_00174D14(self, track);
    if (track->m_mask & 1) {
        out[0] = v;
    }
    if (track->m_mask & 2) {
        out[1] = v;
    }
    if (track->m_mask & 4) {
        out[2] = v;
    }
    if (track->m_mask & 8) {
        out[3] = v;
    }
}

extern "C" void func_00174BB0(EffGeneric1 *self, EffGenericChunk *chunk)
{
    X_func_00174C4C(self, chunk->m_tag, chunk->m_u, chunk->m_v);
}

extern "C" void func_00174BD8(EffGeneric1 *self, EffUvTrack *track)
{
    unsigned short num = track->m_numKeys;
    int i = num - 1;
    EffUvKey *k = (EffUvKey *)((char *)track + (num * 0x10) + 0x18);
    if (i >= 0) {
        for (;;) {
            if (self->m_curFrame >= k->m_frame) {
                break;
            }
            i--;
            if (i < 0) {
                return;
            }
            k--;
        }
        if (i >= 0) {
            X_func_00174C4C(self, track->m_tag, k->m_u, k->m_v);
        }
    }
}

extern "C" void func_00174C44(void)
{
}

extern "C" void func_00174C4C(EffGeneric1 *self, float *tag, float u, float v)
{
    int idx;
    EffRetSub **p = X_func_001700B0(self->m_buf24 + 0x10, tag, &idx);
    if (p != 0) {
        EffVec4 *item = &self->m_uvList[idx];
        item->x = u;
        item->y = v;
        int n = X_func_0022AAB8(p);
        for (idx = 0; idx < n; idx++) {
            X_func_0021AB30(X_func_0022AAD0(p, idx), item);
        }
        (*p)->m_count++;
    }
}

#ifdef NON_MATCHING
extern "C" float func_00174D14(EffGeneric1 *self, EffGenericTrack *track)
{
    int i;
    EffGenericKey *p = track->m_keys;
    for (i = 0; i < track->m_numKeys; i++, p++) {
        if (self->m_curFrame < p->m_frame) {
            break;
        }
    }
    if (i > 0) {
        if (i == track->m_numKeys) {
            return (p - 1)->m_value;
        }
        if (((unsigned short)(p->m_flags & 1)) != 0) {
            EffGenericKey *prev = p - 1;
            return prev->m_value + ((p->m_value - prev->m_value) * (float)(self->m_curFrame - prev->m_frame)) / (float)(p->m_frame - prev->m_frame);
        }
        return (p - 1)->m_value;
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00174D14);
#endif

extern "C" int EffLight1__vfunc_02(EffLight1 *self, EffLight1Arg *arg1)
{
    if (X_Eff0__vfunc_02(self, arg1) == 0) {
        return 0;
    }
    self->m_pos = arg1->m_pos;
    self->m_w = 1.0f;
    self->m_size = arg1->m_size;
    self->m_color = arg1->m_color;
    self->m_unk60 = arg1->m_unk34;
    self->m_frame = 0;
    int flags = self->m_flags;
    if (arg1->m_flag) {
        flags |= 0x8000;
    }
    self->m_fade = 0;
    self->m_zDepth = 1.1754945259845955e-38f;
    self->m_flags = flags;
    return 1;
}

extern "C" int EffLight1__vfunc_05(EffLight1 *self)
{
    self->m_frame++;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight1__vfunc_08);

extern "C" void liveActivateExec__9EffLight1(EffLight1 *self)
{
    int fade = self->m_fade;
    unsigned short flags = self->m_flags;
    int dec = fade - 1;
    int inc = fade + 1;
    if (flags & 4) {
        self->m_fade = inc;
        if (inc >= 5) {
            self->m_flags = flags & 0xFFF7;
        }
    } else {
        self->m_fade = dec;
        if (dec <= 0) {
            self->m_flags = flags & 0xFFF7;
        }
    }
}

extern "C" int EffLight2__vfunc_02(EffLight2 *self, EffLight2Arg *arg1)
{
    if (X_Eff0__vfunc_02(self, arg1) == 0) {
        return 0;
    }
    self->m_pos = arg1->m_pos;
    self->m_w = 1.0f;
    self->m_unk40 = arg1->m_unk1C;
    self->m_unk44 = arg1->m_unk20;
    self->m_unk4C = 1.0f;
    self->m_unk48 = 1.0f;
    self->m_color = arg1->m_color;
    self->m_alpha = self->m_color.w;
    unsigned int flags = self->m_flags;
    self->m_unk64 = arg1->m_unk38;
    self->m_unk68 = arg1->m_unk3C;
    self->m_unk70 = arg1->m_unk34;
    if (arg1->m_flag) {
        flags |= 0x8000;
    }
    self->m_zDepth = 1.1754945259845955e-38f;
    self->m_frame = 0;
    self->m_flags = flags;
    self->m_fade = 0;
    return 1;
}

extern "C" int EffLight2__vfunc_05(EffLight2 *self)
{
    self->m_frame++;
    return 1;
}

extern "C" void render__9EffLight2PQ24Eff011RENDERPARAM(EffLight2Render *self, EffRenderParam *arg1)
{
    if ((self->m_unk1C < 0) && ((self->m_flags & 0xC) != 4)) {
        EffCamView *cam = (EffCamView *)(D_00298E08 + 0x2AB70);
        cam->transform();
        EffMat4 mat = cam->m_mat;
        EffVec4A8 vec;
        X_func_00237408(&vec, &self->m_pos, mat.m[3]);
        float dist = X_func_0016FC20(&vec);
        self->m_dist = dist;
        if (!(self->m_unk68 <= dist)) {
            arg1->m_unk08 = arg1->m_unk04;
            self->v6(arg1);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight2__vfunc_08);

extern "C" void liveActivateExec__9EffLight2(EffLight2 *self)
{
    int fade = self->m_fade;
    unsigned short flags = self->m_flags;
    int dec = fade - 1;
    int inc = fade + 1;
    if (flags & 4) {
        self->m_fade = inc;
        if (inc >= 5) {
            self->m_flags = flags & 0xFFF7;
        }
    } else {
        self->m_fade = dec;
        if (dec <= 0) {
            self->m_flags = flags & 0xFFF7;
        }
    }
}

extern "C" void func_0017562C(EffLight3 *);
struct EffLight3Ctor_17562C : EffLight3 {
    EffLight3Ctor_17562C() asm("func_0017562C");
};

EffLight3Ctor_17562C::EffLight3Ctor_17562C()
{
    func_0016A914(this);
    m_vtbl = &vtbl_EffLight3;
    m_unk390 = -1;
}

extern "C" void EffLight3_dtor(EffLight3 *self, int flags) asm("_$_9EffLight3");
extern "C" void EffLight3_dtor(EffLight3 *self, int flags)
{
    self->m_vtbl = &vtbl_EffLight3;
    if (self->m_unk390 != -1) {
        self->m_f365 = self->m_f364 = 1;
        self->m_f360 = self->m_f340[0] = self->m_f340[1] = self->m_f340[2] = self->m_f340[3] = 0.0f;
        self->m_f350[0] = self->m_f350[1] = self->m_f350[2] = self->m_f350[3] = 1.0f;
        X_func_0017653C(self);
        X_func_001765E8(self, 1.0f);
        void *pool = (void *)(D_00298E08 + 0x2050);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; self->m_entries[i][j][1] != -1; j++) {
                X_freeID__12DogLightPoolii(pool, i, self->m_entries[i][j][1]);
            }
        }
    }
    X__$_4Eff0(self, 0);
    if (flags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight3__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight3__vfunc_05);

#ifdef NON_MATCHING
extern "C" void func_00176430(EffLight3 *self, int group)
{
    unsigned int mask = *(unsigned int *)((char *)D_00298E08 + 0x20B0 + group * 4);
    int cnt = 0;
    for (int i = 0; i < 16; i++) {
        if (mask & (1u << i)) {
            int idx = cnt++;
            self->m_entries[group][idx][0] = i;
            self->m_entries[group][idx][1] = X_func_0013FE64__8MagSceneii(D_00298E08, group, 2);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00176430);
#endif

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F28B0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F28C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F28D0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F28E8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2910);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2930);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2958);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2978);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F29A0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F29C0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F29E0);

extern "C" int func_001764FC(int arg0, int arg1)
{
    (void)arg0;
    int tbl[4] = { 0x0D, 3, 11, 7 };
    return tbl[arg1];
}

struct EffSceneObj_17653C {
    char pad0[0x11C];
    char *f11C;
};
extern "C" int X_17653C_sprintf(char *, const char *, ...) asm("func_00279C98");
extern "C" int X_17653C_22B3D8(char *, char *) asm("func_0022B3D8");
extern "C" void *X_17653C_22B0E8(char *, int) asm("func_0022B0E8");
extern "C" void **X_17653C_22AC08(void *) asm("func_0022AC08");
extern "C" void func_0017653C(char *arg0)
{
    char buf[0x20];
    EffSceneObj_17653C *p = (EffSceneObj_17653C *)(D_00298E08 + 0x29550);
    if (p != 0) {
        char *obj = p->f11C;
        if (obj != 0) {
            char *sub = obj + 0x10;
            for (int i = 0; ; i++) {
                X_17653C_sprintf(buf, "light3_%02d", i);
                int idx = X_17653C_22B3D8(obj, buf);
                if (idx < 0) {
                    break;
                }
                *X_17653C_22AC08(X_17653C_22B0E8(sub, idx)) = arg0 + 0x340;
            }
        }
    }
}

extern "C" void func_001765E8(EffLight3 *self, float scale)
{
    DogLightAmbient *amb = ((DogLightPool *)(D_00298E08 + 0x2050))->getAmbient(0);
    amb->m_color[0] = self->m_ambColor[0] * scale;
    amb->m_color[1] = self->m_ambColor[1] * scale;
    amb->m_color[2] = self->m_ambColor[2] * scale;
}

extern "C" int EffFindItem1__vfunc_02(EffFindItem1 *self, EffFindItem1Arg *arg1)
{
    int ret = X_Eff0__vfunc_02(self, arg1);
    if (ret != 0) {
        ret = 1;
        self->m_pos.x = arg1->m_x;
        self->m_pos.y = arg1->m_y;
        self->m_pos.z = arg1->m_z;
        self->m_pos.w = 1.0f;
        self->m_zBias = arg1->m_zBias;
        self->m_phase = 0;
    }
    return ret;
}

extern "C" int EffFindItem1__vfunc_05(EffFindItem1 *self)
{
    self->m_phase = (unsigned char)((int)(self->m_phase + 1) % 45);
    return 1;
}

extern "C" void render__12EffFindItem1PQ24Eff011RENDERPARAM(EffFindItem1 *self)
{
    if (self->m_phase < 0xFU) {
        X_render__4Eff0PQ24Eff011RENDERPARAM();
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFindItem1__vfunc_08);

extern "C" void updateZDepth__12EffFindItem1(EffFindItem1 *self)
{
    self->m_zDepth = X_func_0016FF18(D_00298E08 + 0x2AB70, &self->m_pos) - self->m_zBias;
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A18);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A38);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A60);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2AA0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2AB0);
