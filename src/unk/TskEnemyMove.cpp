#include "include_asm.h"
extern "C" float ctor700_Xf_func_001D4A3C(int, int, int) asm("func_001D4A3C");
extern "C" float ctor700_Xf_func_001D4AEC(int, int, int) asm("func_001D4AEC");
extern "C" int ctor700_X_func_0010423C(int, int) asm("func_0010423C");
extern "C" int ctor700_X_func_00163DB8(int, int) asm("func_00163DB8");
extern "C" int ctor700_X_func_001D2B8C(int, int) asm("func_001D2B8C");
extern float D_002FF260[];
extern float D_002FF270[];
extern int D_002FF280[];
extern "C" float X_FDDB8_10A650(void *) asm("func_0010A650__8DogActor");
extern "C" int X_FDDB8_1D5A0C(void *, float *, int, int, int, void *) asm("func_001D5A0C");
extern "C" int X_FDDB8_1D890C(int, float *) asm("func_001D890C");
extern "C" int X_FDDB8_1D7F48(int, float *, int) asm("func_001D7F48");
extern float D_002FF230[];
extern float D_002FF240[];
extern int D_002FF250[];
struct DogActor_1FF494 {
    unsigned char pad0[0x50];
    float rot[4];
    void getRot(float *out) {
        out[0] = rot[0];
        out[1] = rot[1];
        out[2] = rot[2];
    }
};
extern "C" int Xiiiif_func_001F5410(int, int, int, float) asm("func_001F5410");
extern "C" int Xiuiiiiui_func_001FAC60(unsigned int, int, int, int, int, unsigned int, int) asm("func_001FAC60");
extern int D_006FE6A0;
struct DogActor_1FF664 {
    unsigned char pad0[0x50];
    float rot[4];
    void getRot(float *out) {
        out[0] = rot[0];
        out[1] = rot[1];
        out[2] = rot[2];
    }
};
extern "C" void X_FFFC0_163EE4(int, int, int) asm("func_00163EE4");
extern "C" int X_2FE4_1640E8(void *) asm("func_001640E8");
extern "C" int X_2FE4_180CA8(void *, int) asm("func_00180CA8");
extern "C" int X_2FE4_10423C(int, int) asm("func_0010423C");
extern "C" int X_2FE4_16A8A4(int, int) asm("func_0016A8A4");
extern "C" int X_2FE4_169A98(void *, void *, float) asm("func_00169A98");
extern "C" void X_2FE4_1640AC(void *, int, int) asm("func_001640AC");
extern int D_002FF5C0[];
extern int D_002FF600[];
extern "C" int Xiii_func_0010423C(int, int) asm("func_0010423C");
extern "C" int X_2234_1D5A0C(void *, float *, int, int, int, void *) asm("func_001D5A0C");
extern "C" void X_2234_16A594(unsigned int, void *) asm("func_0016A594");
extern "C" float X_2234_atan2f(float, float) asm("func_0026CB00");
extern "C" float X_2234_10A650(void *) asm("func_0010A650__8DogActor");
extern "C" int X_2234_10B1B0(void *, int, int, float, int, int) asm("func_0010B1B0__8DogActoriifii");
extern "C" float cosf(float);
extern "C" float Xf_func_0010A650__8DogActor(void *) asm("func_0010A650__8DogActor");
extern "C" float sinf(float);
extern "C" int Xiiif_func_00202900(void *, float *, float) asm("func_00202900");
extern "C" int Xiiiii_func_00202E20(void *, float *, float *, int) asm("func_00202E20");
extern "C" int Xii_func_001FBB04(int) asm("func_001FBB04");
extern "C" int Xiiiiiif_func_001F5BDC(int, int, int, int, int, float, float) asm("func_001F5BDC");
extern "C" int Xiiu_func_001D19A8(int, unsigned int) asm("func_001D19A8");
extern "C" int X_2E20_1D5A0C(void *, float *, int, int, int, void *) asm("func_001D5A0C");
extern "C" void X_2E20_17C340(void *, float *, void *, int, float, float) asm("func_0017C340");
extern char D_006FBD80[];
struct S_00202E20_sub {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10[4];
};
struct S_00202E20 {
    char pad00[0x8];
    struct S_00202E20_sub sub;
};
extern "C" int X_v4_200988(void *, void *) asm("func_00200988");
extern "C" void X_v4_200D18(void *, void *) asm("func_00200D18");
extern "C" void X_v4_202FE4(void *, void *) asm("func_00202FE4");
extern "C" void X_v4_16A594(unsigned int, void *) asm("func_0016A594");
extern float D_006E97D8[];
extern "C" int X_2874_DogActor(void *, int, int, float, int, int) asm("func_0010B1B0__8DogActoriifii");
struct S_00202874 {
    char pad00[0x28];
    void *f28;      // 0x28
    int f2C;        // 0x2C
    char pad30[0x1C];
    float f4C;      // 0x4C
    char pad50[0x0C];
    int f5C;        // 0x5C
    char pad60[0x10];
    int f70;        // 0x70
    char pad74[0xA0C];
    int fA80;       // 0xA80
};
struct v94_1FF25C { char pad[148]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void call(void *, int); };
extern "C" void X_2F60_180EA8(void *, int) asm("func_00180EA8");
extern "C" void X_2F10_180EA8(void *, int) asm("func_00180EA8");
extern "C" void X_2F10_1640AC(void *, int, int) asm("func_001640AC");
struct S_002006B0 {
    int *vt;
    int f04;
    char pad08[0x20];
    int f28;
    char pad2c[0xA98];
    int fAC4;
};
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_vt_12TskEnemyMove asm("_vt$12TskEnemyMove");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_00163EE4(...) asm("func_00163EE4");
extern "C" int X_func_001640AC(...) asm("func_001640AC");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001F5410(...) asm("func_001F5410");
extern "C" int X_func_001F5BDC(...) asm("func_001F5BDC");
extern "C" int X_func_001FAC60(...) asm("func_001FAC60");
extern "C" int X_func_001FBB04(...) asm("func_001FBB04");
extern const char D_002FF2F0[];
extern const char D_002FF2F8[];
extern int D_007812C0;
extern int D_007B2140;
extern int D_007B2580;

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FD424);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FD6BC);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FD9BC);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF040);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF058);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF068);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF078);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF0A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF0A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF0B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF0C8);

extern "C" int func_001FDDB8(int arg0)
{
    float pos0[4];
    float pos1[4];
    float baseYaw = X_FDDB8_10A650((char *)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0x14) * 0x4D0);
    X_FDDB8_1D890C(M2C_FIELD(arg0, int *, 0x18), pos0);
    for (int i = 0; i < 3; i++) {
        float yaw = baseYaw - D_002FF230[i];
        if (yaw < -3.14159265358979323846) {
            yaw += 2.0 * 3.14159265358979323846;
        }
        if (yaw > 3.14159265358979323846) {
            yaw -= 2.0 * 3.14159265358979323846;
        }
        float dist = D_002FF240[i];
        pos1[0] = pos0[0] + sinf(yaw) * dist;
        pos1[2] = pos0[2] + cosf(yaw) * dist;
        pos1[1] = 0.0f;
        if (X_FDDB8_1D7F48((int)&D_007812C0, pos1, 0) != 0 &&
            X_FDDB8_1D5A0C(&D_007812C0, pos1, M2C_FIELD(arg0, int *, 0x10), 0, 0, 0) == 0) {
            return D_002FF250[i];
        }
    }
    M2C_FIELD(arg0, int *, 0xC) |= 8;
    return M2C_FIELD(arg0, int *, 0x20);
}

extern "C" int func_001FDF8C(int arg0)
{
    float pos0[4];
    float pos1[4];
    float baseYaw = X_FDDB8_10A650((char *)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0x14) * 0x4D0);
    X_FDDB8_1D890C(M2C_FIELD(arg0, int *, 0x18), pos0);
    for (int i = 0; i < 3; i++) {
        float yaw = baseYaw - D_002FF260[i];
        if (yaw < -3.14159265358979323846) {
            yaw += 2.0 * 3.14159265358979323846;
        }
        if (yaw > 3.14159265358979323846) {
            yaw -= 2.0 * 3.14159265358979323846;
        }
        float dist = D_002FF270[i];
        pos1[0] = pos0[0] + sinf(yaw) * dist;
        pos1[2] = pos0[2] + cosf(yaw) * dist;
        pos1[1] = 0.0f;
        if (X_FDDB8_1D7F48((int)&D_007812C0, pos1, 0) != 0 &&
            X_FDDB8_1D5A0C(&D_007812C0, pos1, M2C_FIELD(arg0, int *, 0x10), 0, 0, 0) == 0) {
            return D_002FF280[i];
        }
    }
    M2C_FIELD(arg0, int *, 0xC) |= 8;
    return M2C_FIELD(arg0, int *, 0x20);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FE160);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FE87C);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF110);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FEB38);

extern "C" void func_001FF25C(void *arg0)
{
    struct {
        float m[4][4];
    } stack;
    v94_1FF25C *temp_v1;

    temp_v1 = M2C_FIELD(arg0, v94_1FF25C **, 0x50);
    temp_v1->call(&stack, M2C_FIELD(arg0, int *, 0x54));
    M2C_FIELD(arg0, float *, 0x58) = stack.m[3][0];
    M2C_FIELD(arg0, float *, 0x5C) = stack.m[3][1];
    M2C_FIELD(arg0, float *, 0x60) = stack.m[3][2];
    M2C_FIELD(arg0, float *, 0x64) = stack.m[3][3];
    M2C_FIELD(arg0, float *, 0x68) = stack.m[2][0];
    M2C_FIELD(arg0, float *, 0x6C) = stack.m[2][1];
    M2C_FIELD(arg0, float *, 0x70) = stack.m[2][2];
    M2C_FIELD(arg0, float *, 0x74) = stack.m[2][3];
}

extern "C" int func_001FF2E0(int arg0)
{
    if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
        if (Xii_func_001FBB04(arg0) != 0) {
            return 1;
        }
        goto block_6;
    }
    if (M2C_FIELD(arg0, int *, 0xC) & 4) {
block_6:
        switch (M2C_FIELD(arg0, int *, 0x20)) {
        case 0:
        case 20:
        case 10000:
        case 10020:
            M2C_FIELD(arg0, int *, 0x24) = 0x20;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 10:
        case 30:
        case 10010:
        case 10030:
            M2C_FIELD(arg0, int *, 0x24) = 0x1D;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 60:
        case 10060:
            M2C_FIELD(arg0, int *, 0x24) = 0x1F;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 70:
        case 10070:
            M2C_FIELD(arg0, int *, 0x24) = 0x1C;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        }
        M2C_FIELD(arg0, int *, 0x20)++;
        Xiiiiiif_func_001F5BDC(M2C_FIELD(arg0, unsigned int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 1.0f / 60.0f, 32769.0f);
        M2C_FIELD(arg0, int *, 0xC) &= ~4;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF190);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", jtbl_002FF1B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", jtbl_002FF1F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF230);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF240);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF250);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF260);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF270);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF280);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF290);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF2A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF2A4);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF2A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF2AC);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF2B0);

extern "C" int func_001FF494(int arg0)
{
    switch (M2C_FIELD(arg0, int *, 0x20)) {
    case 0: {
        float rot[3];
        int a0 = M2C_FIELD(arg0, int *, 0x10);
        int a1 = M2C_FIELD(arg0, int *, 0x24);
        ((struct DogActor_1FF494 *)((char *)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0x14) * 0x4D0))->getRot(rot);
        Xiiiiiif_func_001F5BDC(a0, a1, -1, 0, 0, 1.0f / 60.0f, rot[1]);
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = 1;
        break;
    }
    case 1:
        if (M2C_FIELD(arg0, int *, 0x1C) >= M2C_FIELD(arg0, int *, 0x44)) {
            M2C_FIELD(arg0, int *, 0x20) = 2;
        }
        break;
    case 2:
        if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) == 0) {
            if (M2C_FIELD(arg0, int *, 0x1C) <= M2C_FIELD(arg0, int *, 0x48)) {
                const char *s = "b_fg_l";
                if (s != 0) {
                    if (Xiiiif_func_001F5410(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x34), (int)s, M2C_FIELD(arg0, float *, 0x40)) != 0 ||
                        Xiiiif_func_001F5410(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x34), (int)"b_fg_r", M2C_FIELD(arg0, float *, 0x40)) != 0) {
                        Xiuiiiiui_func_001FAC60(0xBU, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), M2C_FIELD(arg0, unsigned int *, 0x34), 0);
                        M2C_FIELD(arg0, int *, 0x20) = 4;
                    }
                }
            }
        } else {
            M2C_FIELD(arg0, int *, 0x20) = 4;
        }
        break;
    case 3:
        if (M2C_FIELD(arg0, int *, 0x1C) == 0x1E) {
            return 1;
        }
        break;
    case 4:
        if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
            return 1;
        }
        break;
    case 0x3E7:
        return 1;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

extern "C" int func_001FF664(int arg0)
{
    switch (M2C_FIELD(arg0, int *, 0x20)) {
    case 0: {
        float rot[3];
        int a0 = M2C_FIELD(arg0, int *, 0x10);
        int a1 = M2C_FIELD(arg0, int *, 0x24);
        ((struct DogActor_1FF664 *)((char *)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0x14) * 0x4D0))->getRot(rot);
        Xiiiiiif_func_001F5BDC(a0, a1, -1, 0, 0, 1.0f / 60.0f, rot[1]);
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = 1;
        break;
    }
    case 1:
        if (M2C_FIELD(arg0, int *, 0x1C) >= M2C_FIELD(arg0, int *, 0x44)) {
            M2C_FIELD(arg0, int *, 0x20) = 2;
        }
        break;
    case 2:
        if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) == 0) {
            if (M2C_FIELD(arg0, int *, 0x1C) <= M2C_FIELD(arg0, int *, 0x48)) {
                if (Xiiiif_func_001F5410(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x34), (int)D_002FF2F0, M2C_FIELD(arg0, float *, 0x40)) != 0 ||
                    Xiiiif_func_001F5410(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x34), (int)D_002FF2F8, M2C_FIELD(arg0, float *, 0x40)) != 0) {
                    Xiuiiiiui_func_001FAC60(0xBU, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), M2C_FIELD(arg0, unsigned int *, 0x34), 0);
                }
            }
        } else {
            M2C_FIELD(arg0, int *, 0x20) = 4;
        }
        break;
    case 3:
        if (M2C_FIELD(arg0, int *, 0x1C) == 0x1E) {
            return 1;
        }
        break;
    case 4:
        if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
            return 1;
        }
        break;
    case 0x3E7:
        return 1;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

extern "C" int func_001FF830(int arg0)
{
    switch (M2C_FIELD(arg0, int *, 0x20)) {
    case 0: {
        float rot[3];
        int a0 = M2C_FIELD(arg0, int *, 0x10);
        int a1 = M2C_FIELD(arg0, int *, 0x24);
        ((struct DogActor_1FF664 *)((char *)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0x14) * 0x4D0))->getRot(rot);
        Xiiiiiif_func_001F5BDC(a0, a1, -1, 0, 0, 1.0f / 60.0f, rot[1]);
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = 1;
        break;
    }
    case 1:
        if (M2C_FIELD(arg0, int *, 0x1C) >= M2C_FIELD(arg0, int *, 0x44)) {
            M2C_FIELD(arg0, int *, 0x20) = 2;
        }
        break;
    case 2:
        if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) == 0) {
            if (M2C_FIELD(arg0, int *, 0x1C) <= M2C_FIELD(arg0, int *, 0x48)) {
                if (Xiiiif_func_001F5410(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x34), (int)D_002FF2F0, M2C_FIELD(arg0, float *, 0x40)) != 0 ||
                    Xiiiif_func_001F5410(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x34), (int)D_002FF2F8, M2C_FIELD(arg0, float *, 0x40)) != 0) {
                    Xiuiiiiui_func_001FAC60(0xBU, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), M2C_FIELD(arg0, unsigned int *, 0x34), 0);
                }
            }
        } else {
            M2C_FIELD(arg0, int *, 0x20) = 4;
        }
        break;
    case 3:
        if (M2C_FIELD(arg0, int *, 0x1C) == 0x1E) {
            return 1;
        }
        break;
    case 4:
        if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
            return 1;
        }
        break;
    case 0x3E7:
        return 1;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

extern "C" int func_001FF9FC(int arg0)
{
    if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
        if (Xii_func_001FBB04(arg0) != 0) {
            return 1;
        }
        goto block_6;
    }
    if (M2C_FIELD(arg0, int *, 0xC) & 4) {
block_6:
        switch (M2C_FIELD(arg0, int *, 0x20)) {
        case 0:
            M2C_FIELD(arg0, int *, 0x24) = 8;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 10:
            M2C_FIELD(arg0, int *, 0x24) = 7;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 20:
        case 10000:
        case 10020:
            M2C_FIELD(arg0, int *, 0x24) = 0xF;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 30:
        case 10010:
        case 10030:
            M2C_FIELD(arg0, int *, 0x24) = 0xE;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 40:
        case 10040:
            M2C_FIELD(arg0, int *, 0x24) = 0x10;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 50:
        case 10050:
            M2C_FIELD(arg0, int *, 0x24) = 0x11;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        }
        M2C_FIELD(arg0, int *, 0x20)++;
        Xiiiiiif_func_001F5BDC(M2C_FIELD(arg0, unsigned int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 1.0f / 60.0f, 32769.0f);
        M2C_FIELD(arg0, int *, 0xC) &= ~4;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

extern "C" int func_001FFBC0(int arg0)
{
    if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
        if (Xii_func_001FBB04(arg0) != 0) {
            return 1;
        }
        goto block_6;
    }
    if (M2C_FIELD(arg0, int *, 0xC) & 4) {
block_6:
        switch (M2C_FIELD(arg0, int *, 0x20)) {
        case 0:
        case 10:
            M2C_FIELD(arg0, int *, 0x24) = 0x19;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 20:
            M2C_FIELD(arg0, int *, 0x24) = 0x1C;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 30:
            M2C_FIELD(arg0, int *, 0x24) = 0x1F;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        }
        M2C_FIELD(arg0, int *, 0x20)++;
        Xiiiiiif_func_001F5BDC(M2C_FIELD(arg0, unsigned int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 1.0f / 60.0f, 32769.0f);
        M2C_FIELD(arg0, int *, 0xC) &= ~4;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FFCE0);

extern "C" int func_001FFFC0(int arg0)
{
    if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
        if (Xii_func_001FBB04(arg0) != 0) {
            X_FFFC0_163EE4((int)&D_007B2140, M2C_FIELD(arg0, unsigned int *, 0x10), Xiii_func_0010423C(8, 0x10));
            return 1;
        }
        goto block_6;
    }
    if (M2C_FIELD(arg0, int *, 0xC) & 4) {
block_6:
        switch (M2C_FIELD(arg0, int *, 0x20)) {
        case 0:
        case 10:
            M2C_FIELD(arg0, int *, 0x24) = 0x13;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 20:
            M2C_FIELD(arg0, int *, 0x24) = 0x12;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 30:
            M2C_FIELD(arg0, int *, 0x24) = 0xF;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 10000:
        case 10010:
        case 10020:
        case 10030:
            M2C_FIELD(arg0, int *, 0x24) = 0x31;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        }
        M2C_FIELD(arg0, int *, 0x20)++;
        Xiiiiiif_func_001F5BDC(M2C_FIELD(arg0, unsigned int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 1.0f / 60.0f, 32769.0f);
        M2C_FIELD(arg0, int *, 0xC) &= ~4;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

extern "C" int func_0020014C(int arg0)
{
    if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
        if (Xii_func_001FBB04(arg0) != 0) {
            return 1;
        }
        goto block_6;
    }
    if (M2C_FIELD(arg0, int *, 0xC) & 4) {
block_6:
        switch (M2C_FIELD(arg0, int *, 0x20)) {
        case 0:
        case 10:
            M2C_FIELD(arg0, int *, 0x24) = 0x13;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 20:
        case 10000:
        case 10020:
            M2C_FIELD(arg0, int *, 0x24) = 0x12;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 30:
        case 10010:
        case 10030:
            M2C_FIELD(arg0, int *, 0x24) = 0x11;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 70:
            M2C_FIELD(arg0, int *, 0x24) = 0x15;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        }
        M2C_FIELD(arg0, int *, 0x20)++;
        Xiiiiiif_func_001F5BDC(M2C_FIELD(arg0, unsigned int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 1.0f / 60.0f, 32769.0f);
        M2C_FIELD(arg0, int *, 0xC) &= ~4;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

extern "C" int func_002002CC(int arg0)
{
    if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
        if (Xii_func_001FBB04(arg0) != 0) {
            return 1;
        }
        goto block_6;
    }
    if (M2C_FIELD(arg0, int *, 0xC) & 4) {
block_6:
        switch (M2C_FIELD(arg0, int *, 0x20)) {
        case 0:
            M2C_FIELD(arg0, int *, 0x24) = 0xE;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 10:
            M2C_FIELD(arg0, int *, 0x24) = 0xD;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 20:
            M2C_FIELD(arg0, int *, 0x24) = 0x15;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 10000:
        case 10020:
            M2C_FIELD(arg0, int *, 0x24) = 0x15;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 30:
        case 10010:
        case 10030:
            M2C_FIELD(arg0, int *, 0x24) = 0x16;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        }
        M2C_FIELD(arg0, int *, 0x20)++;
        Xiiiiiif_func_001F5BDC(M2C_FIELD(arg0, unsigned int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 1.0f / 60.0f, 32769.0f);
        M2C_FIELD(arg0, int *, 0xC) &= ~4;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

extern "C" int func_00200444(int arg0)
{
    if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
        if (Xii_func_001FBB04(arg0) != 0) {
            return 1;
        }
        goto block_6;
    }
    if (M2C_FIELD(arg0, int *, 0xC) & 4) {
block_6:
        switch (M2C_FIELD(arg0, int *, 0x20)) {
        case 0:
        case 10:
            M2C_FIELD(arg0, int *, 0x24) = 0x19;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 20:
            M2C_FIELD(arg0, int *, 0x24) = 0x1E;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 30:
            M2C_FIELD(arg0, int *, 0x24) = 0x1F;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 10000:
        case 10020:
            M2C_FIELD(arg0, int *, 0x24) = 0x1A;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        case 10010:
        case 10030:
            M2C_FIELD(arg0, int *, 0x24) = 0x1B;
            M2C_FIELD(arg0, int *, 0xC) |= 8;
            break;
        }
        M2C_FIELD(arg0, int *, 0x20)++;
        Xiiiiiif_func_001F5BDC(M2C_FIELD(arg0, unsigned int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 1.0f / 60.0f, 32769.0f);
        M2C_FIELD(arg0, int *, 0xC) &= ~4;
    }
    M2C_FIELD(arg0, int *, 0x1C)++;
    return 0;
}

extern "C" int func_002005B8(int arg0)
{
    if (Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x10)) != 0) {
        if (Xii_func_001FBB04(arg0) != 0) {
            return 1;
        }
        goto block_4;
    }
    if (M2C_FIELD(arg0, int *, 0xC) & 4) {
block_4:
        M2C_FIELD(arg0, int *, 0x24) = 0x19;
        M2C_FIELD(arg0, int *, 0xC) = M2C_FIELD(arg0, int *, 0xC) | 8;
        Xiiiiiif_func_001F5BDC((int) M2C_FIELD(arg0, unsigned int *, 0x10), 0x19, 1, 0, 0, 1.0f / 60.0f, 32769.0f);
        M2C_FIELD(arg0, int *, 0xC) = M2C_FIELD(arg0, int *, 0xC) & ~4;
    }
    M2C_FIELD(arg0, int *, 0x1C) = M2C_FIELD(arg0, int *, 0x1C) + 1;
    return 0;
}

extern "C" void TskEnemyMove__vfunc_03(void) {
}

extern "C" void TskEnemyMove__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0xAB8));
    if (temp_v0 >= 0) {
        X_func_00180EA8((int)&D_007B2580, temp_v0);
    }
}


extern "C" void func_002006B0(struct S_002006B0 *arg0)
{
    arg0->vt = &X_vt_12TskEnemyMove;
    arg0->f04 = 0;
    arg0->f28 = 0;
    arg0->fAC4 = 0;
}

extern "C" void TskEnemyMove__vfunc_06(void *arg0, int arg1)
{
    M2C_FIELD(arg0, int **, 0) = &X_vt_12TskEnemyMove;
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

extern "C" void func_00200700(int arg0, int arg1)
{
    float var_f2;
    int temp_v0_2;
    int temp_a1;
    int temp_a1_2;
    int temp_v0;

    M2C_FIELD(arg0, int *, 4) = 1;
    M2C_FIELD(arg0, int *, 0xAC4) = 0;
    temp_a1 = M2C_FIELD(arg1, int *, 0);
    M2C_FIELD(arg0, int *, 8) = temp_a1;
    temp_v0 = M2C_FIELD(ctor700_X_func_001D2B8C((int)&D_007812C0, temp_a1), int *, 0x108);
    M2C_FIELD(arg0, int *, 0x2C) = 0;
    M2C_FIELD(arg0, int *, 0xC) = temp_v0;
    M2C_FIELD(arg0, int *, 0x28) = (int) ((int)&D_006FE6A0 + (temp_v0 * 0x4D0));
    temp_v0_2 = M2C_FIELD(arg1, int *, 4);
    M2C_FIELD(arg0, int *, 0x30) = temp_v0_2;
    (*(int *)(temp_v0_2)) = 0;
    M2C_FIELD(arg0, int *, 0x34) = 1;
    M2C_FIELD(arg0, int *, 0x38) = (int) M2C_FIELD(arg1, int *, 0x28);
    M2C_FIELD(arg0, float *, 0x3C) = (float) M2C_FIELD(arg1, float *, 0x2C);
    M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x30);
    M2C_FIELD(arg0, float *, 0x44) = (float) M2C_FIELD(arg1, float *, 0x34);
    M2C_FIELD(arg0, float *, 0x48) = (float) M2C_FIELD(arg1, float *, 0x38);
    M2C_FIELD(arg0, int *, 0x10) = (int) M2C_FIELD(arg1, int *, 8);
    M2C_FIELD(arg0, float *, 0x4C) = (float) (M2C_FIELD(arg1, float *, 0xC) * 0.016666694078594446f);
    M2C_FIELD(arg0, float *, 0x54) = (float) (M2C_FIELD(arg1, float *, 0x10) * M2C_FIELD(arg1, float *, 0xC));
    M2C_FIELD(arg0, float *, 0x58) = (float) (M2C_FIELD(arg1, float *, 0x14) * M2C_FIELD(arg1, float *, 0xC));
    M2C_FIELD(arg0, float *, 0xA90) = (float) M2C_FIELD(arg1, float *, 0x18);
    M2C_FIELD(arg0, float *, 0xA94) = (float) M2C_FIELD(arg1, float *, 0x1C);
    M2C_FIELD(arg0, float *, 0x50) = (float) M2C_FIELD(arg1, float *, 0x10);
    M2C_FIELD(arg0, int *, 0x60) = 0x40;
    M2C_FIELD(arg0, int *, 0x5C) = 0;
    M2C_FIELD(arg0, int *, 0x64) = (int) (M2C_FIELD(arg1, int *, 0x20) + 3);
    M2C_FIELD(arg0, int *, 0x68) = 0;
    M2C_FIELD(arg0, int *, 0x6C) = 0;
    M2C_FIELD(arg0, int *, 0x70) = (int) M2C_FIELD(arg1, int *, 0x24);
    M2C_FIELD(arg0, int *, 0x74) = 0;
    M2C_FIELD(arg0, float *, 0xA84) = (float) M2C_FIELD(arg1, float *, 0x3C);
    M2C_FIELD(arg0, float *, 0xA88) = ctor700_Xf_func_001D4AEC((int)&D_007812C0, M2C_FIELD(arg0, int *, 8), 0);
    temp_a1_2 = M2C_FIELD(arg0, int *, 0x38);
    if (temp_a1_2 != 0) {
        var_f2 = ctor700_Xf_func_001D4A3C((int)&D_007812C0, temp_a1_2, 0);
    } else {
        var_f2 = 0.0f;
    }
    M2C_FIELD(arg0, float *, 0xA8C) = var_f2;
    M2C_FIELD(arg0, float *, 0xA8C) = (float) (var_f2 + (M2C_FIELD(arg0, float *, 0xA88) + M2C_FIELD(arg1, float *, 0x5C)));
    M2C_FIELD(arg0, int *, 0x14) = ctor700_X_func_00163DB8((int)&D_007B2140, M2C_FIELD(arg0, int *, 8));
    M2C_FIELD(arg0, int *, 0xA98) = (int) M2C_FIELD(arg1, int *, 0x44);
    M2C_FIELD(arg0, int *, 0xAA0) = (int) M2C_FIELD(arg1, int *, 0x48);
    M2C_FIELD(arg0, int *, 0xAA8) = (int) M2C_FIELD(arg1, int *, 0x4C);
    M2C_FIELD(arg0, int *, 0xAB0) = (int) M2C_FIELD(arg1, int *, 0x50);
    M2C_FIELD(arg0, float *, 0xAB4) = (float) M2C_FIELD(arg1, float *, 0x58);
    M2C_FIELD(arg0, int *, 0xABC) = ctor700_X_func_0010423C(0xF, 0x1E);
    M2C_FIELD(arg0, int *, 0xAB8) = -1;
    M2C_FIELD(arg0, int *, 0xAC0) = (int) M2C_FIELD(arg1, int *, 0x54);
}

extern "C" int TskEnemyMove__vfunc_04(void *arg0)
{
    struct { float v[4]; } stack;
    void *temp_v1;

    if (M2C_FIELD(arg0, int *, 0xAC4) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, int *, 4) == 0) {
        return 0;
    }
    temp_v1 = M2C_FIELD(arg0, void **, 0x28);
    D_006E97D8[0] = M2C_FIELD(temp_v1, float *, 0x40);
    D_006E97D8[1] = M2C_FIELD(temp_v1, float *, 0x44);
    D_006E97D8[2] = M2C_FIELD(temp_v1, float *, 0x48);
    X_v4_16A594(M2C_FIELD(arg0, unsigned int *, 8), &stack);
    if (X_v4_200988(arg0, &stack) != 0) {
        X_v4_200D18(arg0, &stack);
    }
    X_v4_202FE4(arg0, &stack);
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF2F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF2F8);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00200988);

extern "C" int func_00200BC4(int arg0)
{
    int r = 0;

    if (M2C_FIELD(arg0, int *, 0x2C) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, int *, 0x34) != 0) {
        M2C_FIELD(arg0, int *, 0x34) = 0;
        r = 1;
    } else {
        if (M2C_FIELD(arg0, int *, 0xA98) != 0 && M2C_FIELD(arg0, int *, 0x74) == 0) {
            if (--M2C_FIELD(arg0, int *, 0xA9C) < 0) {
                int v = M2C_FIELD(arg0, int *, 0xA98);
                M2C_FIELD(arg0, int *, 0xA9C) = Xiii_func_0010423C(v * 80, v * 120) / 100;
                r = 4;
            }
        }
        if (M2C_FIELD(arg0, int *, 0xAB0) != 0) {
            if (--M2C_FIELD(arg0, int *, 0xAAC) < 0) {
                int v = M2C_FIELD(arg0, int *, 0xAA8);
                M2C_FIELD(arg0, int *, 0xAAC) = Xiii_func_0010423C(v * 80, v * 120) / 100;
                r = 3;
            }
        }
        if (M2C_FIELD(arg0, int *, 0xAA0) != 0) {
            if (--M2C_FIELD(arg0, int *, 0xAA4) < 0) {
                int v = M2C_FIELD(arg0, int *, 0xAA0);
                M2C_FIELD(arg0, int *, 0xAA4) = Xiii_func_0010423C(v * 80, v * 120) / 100;
                r = 2;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00200D18);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00201164);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00201524);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_002019D0);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00201D58);

// NON_MATCHING: 6/101 differ, 4 edits
#ifdef NON_MATCHING
extern "C" float Xfi_func_0010A650__8DogActor(void *) asm("func_0010A650__8DogActor");
extern "C" int func_00201FA4(void *arg0, float *arg1)
{
    float v1[4];
    float v2[4];
    float yaw;
    float dist = 70.0f;

    yaw = Xfi_func_0010A650__8DogActor(M2C_FIELD(arg0, void **, 0x28));
    v1[1] = v2[1] = arg1[1];
    v1[0] = arg1[0] + sinf(yaw) * dist;
    v1[2] = arg1[2] + cosf(yaw) * dist;
    v2[0] = D_006E97D8[0] + sinf(yaw) * dist;
    v2[2] = D_006E97D8[2] + cosf(yaw) * dist;
    if (Xiiiii_func_00202E20(arg0, v1, v2, M2C_FIELD(arg0, int *, 0x38)) != 0) {
        Xiiif_func_00202900(arg0, arg1, yaw);
        return 1;
    }
    dist = 30.0f;
    v1[0] = arg1[0] + sinf(yaw) * dist;
    v1[2] = arg1[2] + cosf(yaw) * dist;
    v2[0] = D_006E97D8[0] + sinf(yaw) * dist;
    v2[2] = D_006E97D8[2] + cosf(yaw) * dist;
    if (Xiiiii_func_00202E20(arg0, v1, v2, M2C_FIELD(arg0, int *, 0x38)) != 0) {
        Xiiif_func_00202900(arg0, arg1, yaw);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00201FA4);
#endif

extern "C" int func_00202138(void *arg0, float *arg1)
{
    float v1[4];
    float v2[4];
    float yaw;
    int var_v0;

    v1[1] = v2[1] = arg1[1];
    yaw = Xf_func_0010A650__8DogActor(M2C_FIELD(arg0, void **, 0x28));
    v1[0] = arg1[0] + sinf(yaw) * M2C_FIELD(arg0, float *, 0x50);
    v1[2] = arg1[2] + cosf(yaw) * M2C_FIELD(arg0, float *, 0x50);
    v2[0] = D_006E97D8[0] + sinf(yaw) * M2C_FIELD(arg0, float *, 0x50);
    v2[2] = D_006E97D8[2] + cosf(yaw) * M2C_FIELD(arg0, float *, 0x50);
    var_v0 = Xiiiii_func_00202E20(arg0, v1, v2, M2C_FIELD(arg0, int *, 0x38));
    if (var_v0 != 0) {
        Xiiif_func_00202900(arg0, arg1, yaw);
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF338);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF340);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF348);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF350);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF358);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF360);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF368);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF370);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF378);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF380);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF388);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF390);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF398);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF3F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF400);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF408);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF410);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF418);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF420);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF428);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF430);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF438);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF440);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF448);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF450);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF458);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF460);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF468);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF470);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF478);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF480);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF488);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF490);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF498);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF4A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF4A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF4B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF4B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF4C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF4C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF4D0);

extern "C" int func_00202234(void *arg0, float *arg1)
{
    float pos[4];
    int info[8];
    float yaw;
    int mot;

    if (X_2234_1D5A0C(&D_007812C0, arg1, M2C_FIELD(arg0, int *, 0x8), 0, 0, info) != 0) {
        X_2234_16A594(info[4], pos);
        yaw = X_2234_atan2f(pos[0] - arg1[0], pos[2] - arg1[2]) - X_2234_10A650(M2C_FIELD(arg0, void **, 0x28));
        if (yaw < -3.14159265358979323846) {
            yaw += 2.0 * 3.14159265358979323846;
        }
        if (yaw > 3.14159265358979323846) {
            yaw -= 2.0 * 3.14159265358979323846;
        }
        mot = (yaw > 0.0f) ? 0x10 : 0x11;
        X_2234_10B1B0(M2C_FIELD(arg0, void **, 0x28), mot, 0, M2C_FIELD(arg0, float *, 0x4C), -1, -1);
        M2C_FIELD(arg0, int *, 0x5C) = mot;
        M2C_FIELD(arg0, int *, 0x2C) = 1;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00202380);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00202638);

extern "C" void func_00202874(struct S_00202874 *arg0, float fparg0)
{
    int temp_s1;
    int f70 = arg0->f70;
    int f5C = arg0->f5C;

    if (fparg0 > 0.0f) {
        temp_s1 = (f70 != 0) ? 0xF : 9;
        arg0->fA80 = 0;
    } else {
        temp_s1 = (f70 != 0) ? 0xE : 8;
        arg0->fA80 = 1;
    }
    if (f5C != temp_s1) {
        X_2874_DogActor(arg0->f28, temp_s1, 1, arg0->f4C, -1, -1);
        arg0->f5C = temp_s1;
    }
    arg0->f2C = 2;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00202900);

extern "C" int func_00202E20(struct S_00202E20 *arg0, float *arg1, float *arg2, int arg3)
{
    int off = 0x8542C;

    X_2E20_17C340(D_006FBD80 + off, arg2, arg0->sub.f10, 0, 40.0f, 0.0f);
    if (arg0->sub.f10[arg0->sub.f0C] == 0) {
        return 1;
    }
    return X_2E20_1D5A0C(&D_007812C0, arg1, arg0->sub.f00, arg3, 0, 0) != 0;
}

extern "C" void TskEnemyMove__vfunc_02(int arg0, int arg1)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x28);
        if (arg1 != 0) {
            if (temp_v0 != 0) {
                M2C_FIELD(temp_v0, float *, 0x1E8) = 9.999999583953922e-08f;
            }
        } else if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, float *, 0x1E8) = (float) M2C_FIELD(arg0, float *, 0x4C);
        }
    }
}

extern "C" void func_00202F10(void *arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    X_2F10_180EA8(&D_007B2580, M2C_FIELD(arg0, int *, 0xAB8));
    M2C_FIELD(arg0, int *, 0xAB8) = -1;
    X_2F10_1640AC(&D_007B2140, M2C_FIELD(arg0, int *, 8), 0);
}

extern "C" void func_00202F60(void *arg0)
{
    void *temp_a0;

    M2C_FIELD(arg0, int *, 0xAC4) = 1;
    X_2F60_180EA8(&D_007B2580, M2C_FIELD(arg0, int *, 0xAB8));
    if (M2C_FIELD(arg0, int *, 4) == 0) {
        return;
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x28);
    if (temp_a0 != 0) {
        M2C_FIELD(temp_a0, float *, 0x1E8) = 9.999999583953922e-08f;
    }
}

extern "C" void func_00202FBC(int arg0)
{
    int temp_v0;

    M2C_FIELD(arg0, int *, 0xAC4) = 0;
    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x28);
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, float *, 0x1E8) = (float) M2C_FIELD(arg0, float *, 0x4C);
        }
    }
}

extern "C" void func_00202FE4(void *arg0, float *arg1)
{
    if (M2C_FIELD(arg0, int *, 0xAB8) >= 0) {
        int r = X_2FE4_180CA8(&D_007B2580, M2C_FIELD(arg0, int *, 0xAB8));
        if (r != -1) {
            return;
        }
        M2C_FIELD(arg0, int *, 0xAB8) = r;
        X_2FE4_1640AC(&D_007B2140, M2C_FIELD(arg0, int *, 8), 0);
    }
    if (--M2C_FIELD(arg0, int *, 0xABC) > 0) {
        return;
    }
    if (X_2FE4_169A98(arg1, (char *)arg0 + 0x78, 60.0f) != 0) {
        return;
    }
    M2C_FIELD(arg0, int *, 0xABC) = X_2FE4_10423C(0x1E, 0x50);
    if (X_2FE4_1640E8(&D_007B2140) >= 4) {
        return;
    }
    switch (M2C_FIELD(arg0, int *, 0xAC0)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        M2C_FIELD(arg0, int *, 0xAB8) = X_2FE4_16A8A4(M2C_FIELD(arg0, int *, 8), 0xC);
        break;
    case 6:
        M2C_FIELD(arg0, int *, 0xAB8) = X_2FE4_16A8A4(M2C_FIELD(arg0, int *, 8), D_002FF5C0[X_2FE4_10423C(0, 0xF)]);
        break;
    case 10:
        M2C_FIELD(arg0, int *, 0xAB8) = X_2FE4_16A8A4(M2C_FIELD(arg0, int *, 8), D_002FF600[X_2FE4_10423C(0, 3)]);
        break;
    }
    X_2FE4_1640AC(&D_007B2140, M2C_FIELD(arg0, int *, 8), 1);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF4F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF500);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF508);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF510);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF518);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF520);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF528);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF530);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF538);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF540);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF548);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF550);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF558);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF560);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF568);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF570);

INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_0020313C);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF5B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF5C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF600);
