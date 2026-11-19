#include "include_asm.h"
struct EffVec3_175170 { float x, y, z; };
struct EffVec4_175170 { float x, y, z, w; };
struct EffLight2_175170 {
    unsigned short flags;       // 0x00
    char pad2[0xE];
    float f10;                  // 0x10
    char pad14[0x1C];
    EffVec3_175170 f30;         // 0x30
    float f3C;                  // 0x3C
    float f40;                  // 0x40
    float f44;                  // 0x44
    float f48;                  // 0x48
    float f4C;                  // 0x4C
    EffVec4_175170 f50;         // 0x50
    float f60;                  // 0x60
    float f64;                  // 0x64
    float f68;                  // 0x68
    int f6C;                    // 0x6C
    int f70;                    // 0x70
    int f74;                    // 0x74
    int f78;                    // 0x78
};
struct EffLight2Arg_175170 {
    char pad0[0x10];
    EffVec3_175170 f10;         // 0x10
    float f1C;                  // 0x1C
    float f20;                  // 0x20
    EffVec4_175170 f24;         // 0x24
    int f34;                    // 0x34
    float f38;                  // 0x38
    float f3C;                  // 0x3C
    int f40;                    // 0x40
};
extern "C" int X_EffLight2_Eff0_vfunc02(EffLight2_175170 *, EffLight2Arg_175170 *) asm("Eff0__vfunc_02");
struct EffItem3C_174C4C {
    float x, y, z, w;
};
struct EffObj_174C4C {
    char pad0[0x24];
    char *f24;
    char pad28[0x14];
    EffItem3C_174C4C *f3C;
};
struct EffRetSub_174C4C {
    char pad0[8];
    unsigned short f8;
};
extern "C" EffRetSub_174C4C **X_174C4C_1700B0(char *, float *, int *) asm("func_001700B0");
extern "C" int X_174C4C_22AAB8(EffRetSub_174C4C **) asm("func_0022AAB8");
extern "C" int X_174C4C_22AAD0(EffRetSub_174C4C **, int) asm("func_0022AAD0");
extern "C" void X_174C4C_21AB30(int, EffItem3C_174C4C *) asm("func_0021AB30");
extern "C" const char D_002F28D0[];
extern "C" const char D_002F28E8[];
extern "C" const char D_002F2910[];
extern "C" void ror_assert(const char *file, int line, const char *expr);
struct DogLightAmbient_1765E8 {
    float m_color[4];
} __attribute__((aligned(8)));
struct DogLightPool_1765E8 {
    void *m_light[6];
    int m_num[6];
    DogLightAmbient_1765E8 *getAmbient(int n) {
        if (!(n >= 0 && n < m_num[0])) ror_assert(D_002F28D0, 0x81, D_002F28E8);
        if (!m_light[0]) ror_assert(D_002F28D0, 0x81, D_002F2910);
        return &((DogLightAmbient_1765E8 *)m_light[0])[n];
    }
};
struct EffFindItem1_1765E8 {
    char pad[0x330];
    float m_color[3];
};
struct EffVec3_v2 {
    float x, y, z;
};
struct EffFoot2Prim_v2 {
    unsigned short flags;
    char pad2[0x22];
    int f24;
    char pad28[0x8];
    EffVec3_v2 pos;
    float w;
    float f40;
    float f44;
    int f48;
};
struct EffFoot2Arg_v2 {
    char pad0[0x10];
    int f10;
    EffVec3_v2 pos;
    float f20;
    float f24;
};
extern "C" int X_12EffFoot2Prim_Eff0_vfunc02(EffFoot2Prim_v2 *, EffFoot2Arg_v2 *) asm("Eff0__vfunc_02");
struct EffFoot1Prim_v2 {
    char pad0[0x30];
    float x, y, z, w;
    int f40;
    int f44;
    int f48;
    float f4C;
    float f50;
};
struct EffFoot1Arg_v2 {
    char pad0[0x10];
    float x, y, z;
    int f1C;
    int f20;
    float f24;
    float f28;
};
extern "C" int X_12EffFoot1Prim_Eff0_vfunc02(EffFoot1Prim_v2 *, EffFoot1Arg_v2 *) asm("Eff0__vfunc_02");
extern "C" float X_12EffFindItem1_16FF18(int, int) asm("func_0016FF18");
extern "C" int Xiiiff_func_00174C4Cb(int, int, float, float) asm("func_00174C4C");
extern "C" int Xiiii_func_00173618(int, int, int, int) asm("func_00173618");
extern "C" int Xiiii_func_00173628(int, int, int, int) asm("func_00173628");
extern "C" int Xiiii_func_001733CC(int, int, int, int) asm("func_001733CC");
extern "C" int Xi_func_00173610() asm("func_00173610");
extern "C" int Xi_func_00173620() asm("func_00173620");
extern "C" int Xii_func_00173380(int) asm("func_00173380");
extern "C" int Xiiiff_func_00174C4C(int, float *, float, float) asm("func_00174C4C");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfi_func_0010DA4C__8DogActor(int) asm("func_0010DA4C__8DogActor");
extern "C" float Xfii_func_00174D14(int, int) asm("func_00174D14");
extern "C" int Xiiiff_func_0010BCC8__8DogActoriff(int, int, float, float) asm("func_0010BCC8__8DogActoriff");
extern "C" int Xiiiii_func_00173948(int, int, int, int) asm("func_00173948");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0013FE64__8MagSceneii(...) asm("func_0013FE64__8MagSceneii");
extern "C" int X_func_0016FF18(...) asm("func_0016FF18");
extern "C" int X_func_00173380(...) asm("func_00173380");
extern "C" int X_func_001733CC(...) asm("func_001733CC");
extern "C" int X_func_00173610(...) asm("func_00173610");
extern "C" int X_func_00173618(...) asm("func_00173618");
extern "C" int X_func_00173620(...) asm("func_00173620");
extern "C" int X_func_00173628(...) asm("func_00173628");
extern "C" int X_func_00174C4C(...) asm("func_00174C4C");
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern int D_00298E08;

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot1__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001730D4);

extern "C" int EffFoot1Prim__vfunc_02(EffFoot1Prim_v2 *self, EffFoot1Arg_v2 *arg1)
{
    if (X_12EffFoot1Prim_Eff0_vfunc02(self, arg1) == 0) {
        return 0;
    }
    self->x = arg1->x;
    self->y = arg1->y;
    self->z = arg1->z;
    self->w = 1.0f;
    self->f40 = arg1->f1C;
    self->f44 = arg1->f20;
    self->f4C = arg1->f24;
    self->f50 = arg1->f28;
    self->f48 = 0;
    return 1;
}

extern "C" int EffFoot1Prim__vfunc_05(int arg0)
{
    switch (M2C_FIELD(arg0, int *, 0x44)) {
    case 0:
        return Xii_func_00173380(arg0);
    case 1:
        return Xi_func_00173610();
    case 2:
        return Xi_func_00173620();
    }
    return 0;
}

extern "C" int EffFoot1Prim__vfunc_08(int arg0, int arg1, int arg2, int arg3)
{
    switch (M2C_FIELD(arg0, int *, 0x44)) {
    case 0:
        return Xiiii_func_001733CC(arg0, arg1, arg2, arg3);
    case 1:
        return Xiiii_func_00173618(arg0, arg1, arg2, arg3);
    case 2:
        return Xiiii_func_00173628(arg0, arg1, arg2, arg3);
    }
    return arg3;
}

extern "C" void updateZDepth__12EffFoot1Prim(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int func_00173380(int arg0)
{
    int temp_v0;
    int var_v1;

    var_v1 = 1;
    temp_v0 = M2C_FIELD(arg0, int *, 0x48) + 1;
    M2C_FIELD(arg0, int *, 0x48) = temp_v0;
    if (!((((float) temp_v0 * -0.049999997951090336f) + 1.0f) > 0.0f)) {
        var_v1 = 0;
    }
    return var_v1;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_001733CC);

extern "C" int func_00173610()
{
    return 0;
}


extern "C" int func_00173618(int arg0, int arg1, int arg2, int arg3)
{
    return arg3;
}


extern "C" int func_00173620()
{
    return 0;
}


extern "C" int func_00173628(int arg0, int arg1, int arg2, int arg3)
{
    return arg3;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot2__vfunc_05);

// D_002F2698: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26A8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26B8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26C8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26D8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

// D_002F26E8: the end of unk/EffFire1's .rodata now (config/splits_manual.tsv)

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2700);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2710);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2720);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2730);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2760);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2770);

extern "C" void func_00173840(int arg0, int arg1, int arg2)
{
    float temp_f0;
    int temp_v0;

    temp_f0 = Xfi_func_0010DA4C__8DogActor((int) arg1);
    if (temp_f0 >= 0.0f) {
        temp_v0 = Xiiiff_func_0010BCC8__8DogActoriff((int) arg1, -1, temp_f0, temp_f0 + 1.0f);
        if (temp_v0 & 0x10000000) {
            Xiiiii_func_00173948((int) arg0, arg1, (int) "Bip01 L Toe0", arg2);
        }
        if (temp_v0 & 0x20000000) {
            Xiiiii_func_00173948((int) arg0, arg1, (int) "Bip01 R Toe0", arg2);
        }
        if (temp_v0 & 0x04000000) {
            Xiiiii_func_00173948((int) arg0, arg1, (int) "Bip01 L Finger0", arg2);
        }
        if (temp_v0 & 0x08000000) {
            Xiiiii_func_00173948((int) arg0, arg1, (int) "Bip01 R Finger0", arg2);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00173948);

extern "C" int EffFoot2Prim__vfunc_02(EffFoot2Prim_v2 *self, EffFoot2Arg_v2 *arg1)
{
    if (X_12EffFoot2Prim_Eff0_vfunc02(self, arg1) == 0) {
        return 0;
    }
    self->flags |= 0x10;
    self->f24 = arg1->f10;
    self->pos = arg1->pos;
    self->w = 1.0f;
    self->pos.y += -2.0f;
    self->f40 = arg1->f20;
    self->f44 = arg1->f24;
    self->f48 = 0;
    return 1;
}

extern "C" int EffFoot2Prim__vfunc_05(int arg0)
{
    int temp_v1;

    if ((M2C_FIELD(arg0, unsigned short *, 0) & 2) && (M2C_FIELD(arg0, int *, 0x48) < 0xA5)) {
        M2C_FIELD(arg0, int *, 0x48) = 0xA5;
    }
    temp_v1 = M2C_FIELD(arg0, int *, 0x48) + 1;
    M2C_FIELD(arg0, int *, 0x48) = temp_v1;
    return temp_v1 < 0xB4;
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFoot2Prim__vfunc_08);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00173DF8);

extern int _vt$11EffGeneric1;
extern int D_006E9800;
extern "C" void X_dtor11_free(void *, void *) asm("free__9BedMemoryPv");
extern "C" void X_dtor11_Eff0(void *, int) asm("_$_4Eff0");
extern "C" void X_dtor11_delete(void *) asm("__builtin_delete");
struct EffGeneric1_dtor {
    char pad0[0x20];
    void *vtable;
    void *f24;
    int f28;
    void *f2C;
    int f30;
    int f34;
    void *f38;
    void *f3C;
    void *f40;
};
extern "C" void dtor_11EffGeneric1(EffGeneric1_dtor *self, int arg1) asm("_$_11EffGeneric1");
extern "C" void dtor_11EffGeneric1(EffGeneric1_dtor *self, int arg1)
{
    self->vtable = &_vt$11EffGeneric1;
    if (self->f24 != 0) {
        X_dtor11_free(&D_006E9800, self->f24);
        self->f24 = 0;
    }
    if (self->f2C != 0) {
        X_dtor11_free(&D_006E9800, self->f2C);
        self->f2C = 0;
        self->f30 = 0;
        self->f34 = 0;
    }
    if (self->f38 != 0) {
        X_dtor11_free(&D_006E9800, self->f38);
        self->f38 = 0;
    }
    if (self->f3C != 0) {
        X_dtor11_free(&D_006E9800, self->f3C);
        self->f3C = 0;
    }
    if (self->f40 != 0) {
        X_dtor11_free(&D_006E9800, self->f40);
        self->f40 = 0;
    }
    X_dtor11_Eff0(self, 0);
    if (arg1 & 1) {
        return X_dtor11_delete(self);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F27E0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F27F0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2800);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2810);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2820);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffGeneric1__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffGeneric1__vfunc_05);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2870);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2880);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", renderPreMain__11EffGeneric1PQ24Eff011RENDERPARAM);

extern "C" void func_001749FC(int arg0, int arg1, int arg2)
{
    float temp_f0;

    temp_f0 = Xfii_func_00174D14((int) arg0, arg1);
    if (M2C_FIELD(arg1, unsigned short *, 6) & 1 & 0xFFFF) {
        M2C_FIELD(arg2, float *, 0) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 2) {
        M2C_FIELD(arg2, float *, 4) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 4) {
        M2C_FIELD(arg2, float *, 8) = temp_f0;
    }
}

extern "C" void func_00174A60(int arg0, int arg1, int arg2)
{
    float temp_f0;

    if (!((*(unsigned short *)M2C_FIELD(arg0, int *, 0x40)) & 4)) {
        temp_f0 = Xfii_func_00174D14(arg0, arg1);
        if (M2C_FIELD(arg1, unsigned short *, 6) & 1 & 0xFFFF) {
            M2C_FIELD(arg2, float *, 0) = temp_f0;
        }
        if (M2C_FIELD(arg1, unsigned short *, 6) & 2) {
            M2C_FIELD(arg2, float *, 4) = temp_f0;
        }
        if (M2C_FIELD(arg1, unsigned short *, 6) & 4) {
            M2C_FIELD(arg2, float *, 8) = temp_f0;
        }
    }
}

extern "C" void func_00174AD8(int arg0, int arg1, int arg2)
{
    float temp_f0;

    temp_f0 = Xfii_func_00174D14((int) arg0, arg1);
    if (M2C_FIELD(arg1, unsigned short *, 6) & 1 & 0xFFFF) {
        M2C_FIELD(arg2, float *, 0) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 2) {
        M2C_FIELD(arg2, float *, 4) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 4) {
        M2C_FIELD(arg2, float *, 8) = temp_f0;
    }
}

extern "C" void func_00174B3C(int arg0, int arg1, int arg2)
{
    float temp_f0;

    temp_f0 = Xfii_func_00174D14((int) arg0, arg1);
    if (M2C_FIELD(arg1, unsigned short *, 6) & 1 & 0xFFFF) {
        M2C_FIELD(arg2, float *, 0) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 2) {
        M2C_FIELD(arg2, float *, 4) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 4) {
        M2C_FIELD(arg2, float *, 8) = temp_f0;
    }
    if (M2C_FIELD(arg1, unsigned short *, 6) & 8) {
        M2C_FIELD(arg2, float *, 0xC) = temp_f0;
    }
}

extern "C" void func_00174BB0(int arg0, int arg1)
{
    Xiiiff_func_00174C4C(arg0, (float *)(arg1 + 4), M2C_FIELD(arg1, float *, 0x2C), M2C_FIELD(arg1, float *, 0x30));
}

extern "C" void func_00174BD8(int arg0, int arg1)
{
    int var_v1;
    unsigned short temp_v1;
    int var_a2;

    temp_v1 = M2C_FIELD(arg1, unsigned short *, 0x24);
    var_v1 = temp_v1 - 1;
    var_a2 = arg1 + (temp_v1 * 0x10) + 0x18;
    if (var_v1 >= 0) {
        for (;;) {
            if ((unsigned short) M2C_FIELD(arg0, unsigned short *, 0x44) >= (unsigned short) M2C_FIELD(var_a2, unsigned short *, 0)) {
                break;
            }
            var_v1 -= 1;
            if (var_v1 < 0) {
                return;
            }
            var_a2 -= 0x10;
        }
        if (var_v1 >= 0) {
            Xiiiff_func_00174C4Cb(arg0, arg1 + 4, M2C_FIELD(var_a2, float *, 4), M2C_FIELD(var_a2, float *, 8));
        }
    }
}

extern "C" void func_00174C44(void) {
}

extern "C" void func_00174C4C(EffObj_174C4C *arg0, float *arg1, float fp0, float fp1)
{
    int idx;
    EffRetSub_174C4C **p = X_174C4C_1700B0(arg0->f24 + 0x10, arg1, &idx);
    if (p != 0) {
        EffItem3C_174C4C *item = &arg0->f3C[idx];
        item->x = fp0;
        item->y = fp1;
        int n = X_174C4C_22AAB8(p);
        for (idx = 0; idx < n; idx++) {
            X_174C4C_21AB30(X_174C4C_22AAD0(p, idx), item);
        }
        (*p)->f8++;
    }
}

// NON_MATCHING: 30/47 differ (size 0xBC, game 0xC4), 19 edits
#ifdef NON_MATCHING
struct EffKey_174D14 {
    unsigned short frame;
    unsigned short flags;
    float value;
};
struct EffTrack_174D14 {
    char pad0[4];
    unsigned short numKeys;
    unsigned short flags;
    EffKey_174D14 keys[1];
};
struct EffObj_174D14 {
    char pad0[0x44];
    unsigned short curFrame;
};
extern "C" float func_00174D14(EffObj_174D14 *obj, EffTrack_174D14 *track)
{
    int i;
    EffKey_174D14 *p = track->keys;
    for (i = 0; i < track->numKeys; i++, p++) {
        if (obj->curFrame < p->frame) {
            break;
        }
    }
    if (i > 0) {
        if (i != track->numKeys) {
            goto check_flags;
        }
    ret_prev:
        return (p - 1)->value;
    check_flags:
        if (!(p->flags & 1)) {
            goto ret_prev;
        }
        EffKey_174D14 *prev = p - 1;
        unsigned short f0 = prev->frame;
        float v0 = prev->value;
        return v0 + (p->value - v0) * (float)(obj->curFrame - f0) / (float)(p->frame - f0);
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_00174D14);
#endif

// NON_MATCHING: 13/50 differ (size 0xC8, game 0xC4), 7 edits (xori $v1, $v1, 0x0 before movn)
#ifdef NON_MATCHING
struct EffVec2_174DD8 { float x, y; };
struct EffVec3_174DD8 { float x, y, z; };
struct EffVec4_174DD8 { float x, y, z, w; };
struct EffLight1_v2 {
    unsigned short flags;       // 0x00
    char pad2[0xE];
    float f10;                  // 0x10
    char pad14[0x1C];
    EffVec3_174DD8 f30;         // 0x30
    float f3C;                  // 0x3C
    EffVec2_174DD8 f40;         // 0x40
    char pad48[0x8];
    EffVec4_174DD8 f50;         // 0x50
    float f60;                  // 0x60
    int f64;                    // 0x64
    int f68;                    // 0x68
};
struct EffLight1Arg_v2 {
    char pad0[0x10];
    EffVec3_174DD8 f10;         // 0x10
    EffVec2_174DD8 f1C;         // 0x1C
    EffVec4_174DD8 f24;         // 0x24
    float f34;                  // 0x34
    int f38;                    // 0x38
};
extern "C" int X_EffLight1_Eff0_vfunc02(EffLight1_v2 *, EffLight1Arg_v2 *) asm("Eff0__vfunc_02");
extern "C" int EffLight1__vfunc_02(EffLight1_v2 *self, EffLight1Arg_v2 *arg1)
{
    if (X_EffLight1_Eff0_vfunc02(self, arg1) == 0) {
        return 0;
    }
    self->f30 = arg1->f10;
    self->f3C = 1.0f;
    self->f40 = arg1->f1C;
    self->f50 = arg1->f24;
    self->f60 = arg1->f34;
    self->f64 = 0;
    unsigned short flags = self->flags;
    if (arg1->f38) {
        flags |= 0x8000;
    }
    self->f68 = 0;
    self->f10 = 1.1754945259845955e-38f;
    self->flags = flags;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight1__vfunc_02);
#endif

extern "C" int EffLight1__vfunc_05(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x64)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x64)) + 1);
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight1__vfunc_08);

extern "C" void liveActivateExec__9EffLight1(int arg0)
{
    int temp_a2;
    int temp_v0;
    int temp_v0_2;
    unsigned short temp_a1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x68);
    temp_a1 = M2C_FIELD(arg0, unsigned short *, 0);
    temp_v0_2 = temp_v0 - 1;
    temp_a2 = temp_v0 + 1;
    if (temp_a1 & 4) {
        M2C_FIELD(arg0, int *, 0x68) = temp_a2;
        if (temp_a2 >= 5) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    } else {
        M2C_FIELD(arg0, int *, 0x68) = temp_v0_2;
        if (temp_v0_2 <= 0) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    }
}

extern "C" int EffLight2__vfunc_02(EffLight2_175170 *self, EffLight2Arg_175170 *arg1)
{
    if (X_EffLight2_Eff0_vfunc02(self, arg1) == 0) {
        return 0;
    }
    self->f30 = arg1->f10;
    self->f3C = 1.0f;
    self->f40 = arg1->f1C;
    self->f44 = arg1->f20;
    self->f4C = 1.0f;
    self->f48 = 1.0f;
    self->f50 = arg1->f24;
    int flags = self->flags;
    self->f60 = self->f50.w;
    self->f64 = arg1->f38;
    self->f68 = arg1->f3C;
    self->f70 = arg1->f34;
    if (arg1->f40) {
        flags |= 0x8000;
    }
    self->f10 = 1.1754945259845955e-38f;
    self->f74 = 0;
    self->flags = flags;
    self->f78 = 0;
    return 1;
}

extern "C" int EffLight2__vfunc_05(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x74)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x74)) + 1);
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", render__9EffLight2PQ24Eff011RENDERPARAM);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight2__vfunc_08);

extern "C" void liveActivateExec__9EffLight2(int arg0)
{
    int temp_a2;
    int temp_v0;
    int temp_v0_2;
    unsigned short temp_a1;

    temp_v0 = M2C_FIELD(arg0, int *, 0x78);
    temp_a1 = M2C_FIELD(arg0, unsigned short *, 0);
    temp_v0_2 = temp_v0 - 1;
    temp_a2 = temp_v0 + 1;
    if (temp_a1 & 4) {
        M2C_FIELD(arg0, int *, 0x78) = temp_a2;
        if (temp_a2 >= 5) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    } else {
        M2C_FIELD(arg0, int *, 0x78) = temp_v0_2;
        if (temp_v0_2 <= 0) {
            M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short) (temp_a1 & 0xFFF7);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_0017562C);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", _$_9EffLight3);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight3__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffLight3__vfunc_05);

// NON_MATCHING: 47/49 differ, 2 relocs differ (size 0xC4, game 0xCC), 35 edits
#ifdef NON_MATCHING
struct Entry_176430 {
    int a;
    int b;
}; // Entry_176430
struct Obj_176430 {
    char pad[0x24];
    Entry_176430 entries[6][16];
}; // Obj_176430
struct Scene_176430 {
    char pad[0x20B0];
    unsigned int bits[4];
}; // Scene_176430
extern "C" int Xiiii_func_0013FE64__8MagSceneii(int, int, int) asm("func_0013FE64__8MagSceneii");
extern "C" void func_00176430(Obj_176430 *arg0, int arg1)
{
    int count = 0;
    unsigned int bits = ((Scene_176430 *)D_00298E08)->bits[arg1];
    for (int i = 0; i < 16; i++) {
        if (bits & (1 << i)) {
            arg0->entries[arg1][count].a = i;
            arg0->entries[arg1][count].b = Xiiii_func_0013FE64__8MagSceneii(D_00298E08, arg1, 2);
            count++;
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
    int tbl[4] = { 0x0D, 3, 11, 7 };
    return tbl[arg1];
}

// NON_MATCHING: function matches (0xac); blocked on D_002F2A18 .align 3 in config/rodata_align_manual.tsv
#ifdef NON_MATCHING
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
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", func_0017653C);
#endif

extern "C" void func_001765E8(EffFindItem1_1765E8 *self, float scale)
{
    DogLightAmbient_1765E8 *amb = ((DogLightPool_1765E8 *)(D_00298E08 + 0x2050))->getAmbient(0);
    amb->m_color[0] = self->m_color[0] * scale;
    amb->m_color[1] = self->m_color[1] * scale;
    amb->m_color[2] = self->m_color[2] * scale;
}

extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X___10FileReader(...) asm("__10FileReader");
extern "C" int X___11FileReadReq(...) asm("__11FileReadReq");
extern "C" int X_alloc__9BedMemoryii(...) asm("alloc__9BedMemoryii");
extern "C" int X_apply__C12DogLightPoolPvifi(...) asm("apply__C12DogLightPoolPvifi");
extern "C" int X_free__9BedMemoryPv(...) asm("free__9BedMemoryPv");
extern "C" int X_func_0016AC84(...) asm("func_0016AC84");
extern "C" int X_func_0017762C(...) asm("func_0017762C");
extern "C" int X_func_001776C4(...) asm("func_001776C4");
extern "C" int X_func_00177A8C(...) asm("func_00177A8C");
extern "C" int X_func_00177C00(...) asm("func_00177C00");
extern "C" int X_func_00177E9C(...) asm("func_00177E9C");
extern "C" int X_func_00177EF8(...) asm("func_00177EF8");
extern "C" int X_func_001780C0(...) asm("func_001780C0");
extern "C" int X_func_0017820C(...) asm("func_0017820C");
extern "C" int X_func_00178894(...) asm("func_00178894");
extern "C" int X_func_001BE524__10FileReaderP11FileReadReqi(...) asm("func_001BE524__10FileReaderP11FileReadReqi");
extern "C" int X_func_0021A158(...) asm("func_0021A158");
extern "C" int X_func_0021F7E0(...) asm("func_0021F7E0");
extern "C" int X_func_00223240(...) asm("func_00223240");
extern "C" int X_func_00223250(...) asm("func_00223250");
extern "C" int X_func_00223260(...) asm("func_00223260");
extern "C" int X_func_00226C58(...) asm("func_00226C58");
extern "C" int X_getViewMatrix__9DogCamera(...) asm("getViewMatrix__9DogCamera");
extern "C" int X_memcmp(...) asm("memcmp");
extern "C" int X_memmove(...) asm("memmove");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_render__4Eff0PQ24Eff011RENDERPARAM(...) asm("render__4Eff0PQ24Eff011RENDERPARAM");
extern "C" int X_strlen(...) asm("strlen");
extern int D_00298E08;
extern int D_00298E0C;
extern int D_006E9800;

extern "C" int EffFindItem1__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        var_v0 = 1;
        M2C_FIELD(arg0, float *, 0x30) = (float) M2C_FIELD(arg1, float *, 0x10);
        M2C_FIELD(arg0, float *, 0x34) = (float) M2C_FIELD(arg1, float *, 0x14);
        M2C_FIELD(arg0, float *, 0x38) = (float) M2C_FIELD(arg1, float *, 0x18);
        M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
        M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
        M2C_FIELD(arg0, signed char *, 0x44) = 0;
    }
    return var_v0;
}

extern "C" int EffFindItem1__vfunc_05(int arg0)
{
    M2C_FIELD(arg0, unsigned char *, 0x44) = (unsigned char) ((int) (M2C_FIELD(arg0, unsigned char *, 0x44) + 1) % 45);
    return 1;
}

extern "C" void render__12EffFindItem1PQ24Eff011RENDERPARAM(int arg0)
{
    if ((unsigned char) (*(int *)(unsigned char *)((char *)(arg0) + 0x44)) < 0xFU) {
        X_render__4Eff0PQ24Eff011RENDERPARAM();
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/EffLight2", EffFindItem1__vfunc_08);

extern "C" void updateZDepth__12EffFindItem1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = X_12EffFindItem1_16FF18(D_00298E08 + 0x2AB70, arg0 + 0x30) - M2C_FIELD(arg0, float *, 0x40);
}



INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A18);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A38);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A60);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2A90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2AA0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffLight2", D_002F2AB0);
