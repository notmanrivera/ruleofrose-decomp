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

// NON_MATCHING: 102/161 differ, 12 relocs differ (size 0x284, game 0x298), 22 edits
#ifdef NON_MATCHING
extern "C" float d424_Xf_func_0010A650__8DogActor(int) asm("func_0010A650__8DogActor");
extern "C" int d424_X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int d424_X_func_00119090__9MagSystem(...) asm("func_00119090__9MagSystem");
extern "C" int d424_X_func_0016A8A4(...) asm("func_0016A8A4");
extern "C" int d424_X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int d424_X_func_001F5BDC(int,int,int,int,int,float,float) asm("func_001F5BDC");
extern "C" int d424_X_func_001FAC60(...) asm("func_001FAC60");
extern "C" int Xiitif_func_00169F94(int, unsigned short, int, float) asm("func_00169F94");
extern int D_006E9840;
extern "C" int func_001FD424(int arg0)
{
    float var_f1;
    int temp_a1;
    int temp_a1_2;
    int var_s1;
    int var_s2;
    int var_s3;
    int var_v0;
    int var_v1;
    int temp_s1;

    temp_a1 = M2C_FIELD(arg0, int *, 0x20);
    temp_s1 = (int)&D_006FE6A0 + (M2C_FIELD(arg0, int *, 0x14) * 0x4D0);
    switch (temp_a1) {
    case 0:

                d424_X_func_0016A8A4(M2C_FIELD(arg0, int *, 0x10), 0xB);
                d424_X_func_001F5BDC(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 0.016666666666666666f, d424_Xf_func_0010A650__8DogActor(temp_s1));
                M2C_FIELD(arg0, int *, 0x20) = 1;
                M2C_FIELD(arg0, int *, 0x1C) = 0;
                break;
    case 1:

                temp_a1_2 = M2C_FIELD(arg0, int *, 0x1C);
                var_v1 = 0;
                if (temp_a1_2 >= M2C_FIELD(arg0, int *, 0x44)) {
                    var_v1 = (M2C_FIELD(arg0, int *, 0x48) < temp_a1_2) == 0;
                }
                var_f1 = (float)(unsigned int)var_v1;
                if (var_f1 != 0.0f) {
                    var_s3 = 0;
                    var_s1 = 0;
                    if (M2C_FIELD((int)&D_007812C0, int *, 0x22090) != 0) {
                        var_s1 = M2C_FIELD(M2C_FIELD((int)&D_007812C0, int *, 0x22090), int *, 0x100);
                    }
                    if ((d424_X_func_00118FEC__9MagSystem((int)&D_006E9840, temp_a1_2) != 9) && (Xiitif_func_00169F94(M2C_FIELD(arg0, int *, 0x10), 1U, var_s1, M2C_FIELD(arg0, float *, 0x40)) != 0)) {
                        var_s3 = 1;
                        d424_X_func_001FAC60(0xB, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), var_s1, 0);
                    }
                    var_s2 = 0;
                    if (M2C_FIELD((int)&D_007812C0, int *, 0x22094) != 0) {
                        var_s2 = M2C_FIELD(M2C_FIELD((int)&D_007812C0, int *, 0x22094), int *, 0x100);
                    }
                    if ((d424_X_func_00119090__9MagSystem((int)&D_006E9840) != 0xA) && (d424_X_func_00119090__9MagSystem((int)&D_006E9840) != 0xD) && (Xiitif_func_00169F94(M2C_FIELD(arg0, int *, 0x10), 1U, var_s2, M2C_FIELD(arg0, float *, 0x40)) != 0)) {
                        var_s3 = 1;
                        d424_X_func_001FAC60(0xB, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), var_s2, 0);
                    }
                    if (var_s3 != 0) {
                        d424_X_func_0016A8A4(M2C_FIELD(arg0, int *, 0x10), 1);
                    }
                }
                if (M2C_FIELD(arg0, int *, 0x1C) == M2C_FIELD(arg0, int *, 0x48)) {
                    M2C_FIELD(arg0, int *, 0x20) = 3;
                }
                break;
    case 2:
        if (M2C_FIELD(arg0,int *,0x1C) == 30) return 1;
        break;
    case 3:
        if (d424_X_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0,int *,0x10)) != 0) return 1;
        break;
    case 999: return 1;
    }
    M2C_FIELD(arg0,int *,0x1C)++;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FD424);
#endif

// NON_MATCHING: 163/186 differ, 19 relocs differ (size 0x2E8, game 0x300), 108 edits
#ifdef NON_MATCHING
extern int sysD6BC asm("D_006E9840");
extern "C" int X_func_00118FEC__9MagSystem(int) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_00119090__9MagSystem(int) asm("func_00119090__9MagSystem");
extern "C" int X_func_0016A8A4(int, int) asm("func_0016A8A4");
extern "C" int X_func_001D1C80(int, int, int, int) asm("func_001D1C80");
extern "C" int X_func_001DC48C(int, unsigned short, int, int) asm("func_001DC48C");
extern "C" int d6_Xiitif_func_00169F94(int, unsigned short, int, float) asm("func_00169F94");
extern "C" int func_001FD6BC(int arg0)
{
    struct { unsigned short sp0; unsigned short sp2; int sp4; float sp8; } stack;
    float var_f1;
    int temp_a1;
    int temp_a1_2;
    int var_s0;
    int var_s1;
    int var_s3;
    int var_v0;
    int var_v1;
    int temp_s0;
    int temp_s0_2;

    temp_a1 = M2C_FIELD(arg0, int *, 0x20);
    temp_s0 = (int)&D_006FE6A0 + (M2C_FIELD(arg0, int *, 0x14) * 0x4D0);
    if (temp_a1 != 0xA) {
        if (temp_a1 < 0xB) {
            if (temp_a1 == 1) {                      
                temp_a1_2 = M2C_FIELD(arg0, int *, 0x1C);
                var_v1 = 0;
                if (temp_a1_2 >= M2C_FIELD(arg0, int *, 0x44)) {
                    var_v1 = (M2C_FIELD(arg0, int *, 0x48) < temp_a1_2) == 0;
                }
                var_f1 = (float)(unsigned int)var_v1;
                if (var_f1 != 0.0f) {
                    X_func_001D1C80((int)&D_007812C0, M2C_FIELD(arg0, int *, 0x10), 0x66, (int)&stack);
                    temp_s0_2 = (int)&D_007812C0 + 0x22220;
                    X_func_001D1C80((int)&D_007812C0, M2C_FIELD(arg0, int *, 0x10), 0x67, (int)&stack.sp4);
                    var_s3 = 0;
                    X_func_001DC48C(temp_s0_2, stack.sp0, 0x22, (int)&stack.sp2);
                    var_s0 = 0;
                    X_func_001DC48C(temp_s0_2, stack.sp0, 0x30, (int)&stack.sp8);
                    if (M2C_FIELD((int)&D_007812C0, int *, 0x22090) != 0) {
                        var_s0 = M2C_FIELD(M2C_FIELD((int)&D_007812C0, int *, 0x22090), int *, 0x100);
                    }
                    if ((X_func_00118FEC__9MagSystem((int)&sysD6BC) != 9) && (d6_Xiitif_func_00169F94(stack.sp4, stack.sp2, var_s0, stack.sp8) != 0)) {
                        var_s3 = 1;
                        X_func_001FAC60(0xB, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), var_s0, 0);
                    }
                    var_s1 = 0;
                    if (M2C_FIELD((int)&D_007812C0, int *, 0x22094) != 0) {
                        var_s1 = M2C_FIELD(M2C_FIELD((int)&D_007812C0, int *, 0x22094), int *, 0x100);
                    }
                    if ((X_func_00119090__9MagSystem((int)&sysD6BC) != 0xA) && (X_func_00119090__9MagSystem((int)&sysD6BC) != 0xD) && (d6_Xiitif_func_00169F94(stack.sp4, stack.sp2, var_s1, stack.sp8) != 0)) {
                        var_s3 = 1;
                        X_func_001FAC60(0xB, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), var_s1, 0);
                    }
                    if (var_s3 != 0) {
                        X_func_0016A8A4(M2C_FIELD(arg0, int *, 0x10), 3);
                    }
                }
                if (M2C_FIELD(arg0, int *, 0x1C) == M2C_FIELD(arg0, int *, 0x48)) {
                    M2C_FIELD(arg0, int *, 0x20) = 0x14;
                }
            } else if (temp_a1 == 0) {
                X_func_0016A8A4(M2C_FIELD(arg0, int *, 0x10), 0xB);
                Xiiiiiif_func_001F5BDC(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 0.016666667f, Xf_func_0010A650__8DogActor((void *)temp_s0));
                M2C_FIELD(arg0, int *, 0x1C) = 0;
                M2C_FIELD(arg0, int *, 0x20) = (int) (M2C_FIELD(arg0, int *, 0x20) + 1);
            }
            goto block_35;
        }
        if (temp_a1 != 0x14) {
            var_v0 = 1;
            if (temp_a1 != 0x3E7) {
                goto block_35;
            }
        } else {
            var_v0 = 1;
            if (X_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, int *, 0x10)) == 0) {
block_35:
                goto block_36;
            }
        }
        
        return var_v0;
    }
    if (M2C_FIELD(arg0, int *, 0x1C) == 0x1E) {
        return 1;
    }
block_36:
    var_v0 = 0;
    M2C_FIELD(arg0, int *, 0x1C) = (int) (M2C_FIELD(arg0, int *, 0x1C) + 1);
    return var_v0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FD6BC);
#endif

// NON_MATCHING: 235/252 differ, 32 relocs differ (size 0x3F0, game 0x3FC), 31 edits
#ifdef NON_MATCHING
extern int sysD9BC asm("D_006E9840");
extern int queueD9BC asm("D_007A3D80");
extern const char nameD9BC[] asm("D_002FF0A0");
extern const char fileD9BC[] asm("D_002FF0A8");
extern const char rootD9BC[] asm("D_002FF0B8");
extern const char ptrD9BC[] asm("D_002FF0C8");
extern "C" void assertD9BC(const char *, int, const char *) asm("ror_assert");
extern "C" float yawD9BC(void *) asm("func_0010A650__8DogActor");
extern "C" float sqrtf( float );
extern "C" void *memset(void *, int, unsigned int);
struct MotionD9BC { float v[8]; };
struct ModelD9BC { char pad[148]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void call(float *, int); };
extern "C" int d9_idx(void *, int) asm("func_001CBE38");
extern "C" void d9_attach(void *, int, int, int) asm("attachActor__9MagSystemiii");
extern "C" void d9_rot(void *, int, float *) asm("func_001D06B8");
extern "C" int d9_bone(int, const char *) asm("func_0022B3D8");
extern "C" void d9_pos(void *, int, float *) asm("func_001CFBE4");
extern "C" void d9_setrot(void *, int, float *) asm("func_001CFE78");
extern "C" void d9_effect(void *, int, int, int, int, int, float) asm("func_001331F4");
extern "C" void * d9_alloc(unsigned int) asm("__builtin_new");
extern "C" void d9_ctor(void *, int, MotionD9BC *) asm("func_001EEAEC");
extern "C" void d9_queue(void *, int, int, int, int, void *, int, int, int) asm("func_001E71FC");
extern "C" void d9_state(int, int) asm("func_0016A8A4");
extern "C" void d9_start(int, int, int, int, int, float, float) asm("func_001F5BDC");
extern "C" int d9_done(void *, int) asm("func_001D19A8");
extern "C" int func_001FD9BC(void *arg0) {
    float rot[4], pos[4], matrix[16], offset[4];
    MotionD9BC motion, temp;
    int mode = M2C_FIELD(arg0, int *, 0x20);
    char *actor = (char *)((M2C_FIELD(arg0, int *, 0x14) * 0x4D0) + (int)D_006FBD80 + 0x2920);
    switch (mode) {
    case 0: {
        d9_state(M2C_FIELD(arg0, int *, 0x10), 11);
        d9_start(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 0.016666667f, yawD9BC(actor));
        int nextmode = M2C_FIELD(arg0, int *, 0x20) + 1;
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = nextmode;
        break;
    }
    case 1:
        if (M2C_FIELD(arg0, int *, 0x1C) >= M2C_FIELD(arg0, int *, 0x44)) {
            int index = d9_idx(&D_007812C0, M2C_FIELD(arg0, int *, 0x4C));
            d9_attach(&sysD9BC, index, -1, 0);
            d9_rot(&D_007812C0, M2C_FIELD(arg0, int *, 0x10), rot);
            const char *name = nameD9BC;
            char *model = (char *)((M2C_FIELD(arg0, int *, 0x14) * 0x4D0) + (int)D_006FBD80 + 0x2920);
            if (!M2C_FIELD(model, int *, 0x11C)) assertD9BC(fileD9BC, 305, rootD9BC);
            if (!name) assertD9BC(fileD9BC, 305, ptrD9BC);
            int bone = d9_bone(M2C_FIELD(model, int *, 0x11C), name);
            offset[0] = 0.0f; offset[1] = 0.0f; offset[2] = 0.0f;
            ((ModelD9BC *)((char *)((M2C_FIELD(arg0, int *, 0x14) * 0x4D0) + (int)D_006FBD80 + 0x2920)))->call(matrix, bone);
            pos[0] = matrix[12] + offset[0];
            pos[1] = matrix[13] + offset[1];
            pos[2] = matrix[14] + offset[2];
            d9_rot(&D_007812C0, M2C_FIELD(arg0, int *, 0x10), rot);
            d9_pos(&D_007812C0, M2C_FIELD(arg0, int *, 0x4C), pos);
            float x = sinf(rot[1]) * M2C_FIELD(arg0, float *, 0x58);
            float z = cosf(rot[1]) * M2C_FIELD(arg0, float *, 0x58);
            float length = sqrtf(x * x + z * z);
            memset(&temp, 0, 32);
            temp.v[0] = x;
            float y = length * cosf(M2C_FIELD(arg0, float *, 0x54));
            temp.v[2] = z;
            temp.v[4] = 1.0f;
            temp.v[1] = y;
            motion = temp;
            d9_setrot(&D_007812C0, M2C_FIELD(arg0, int *, 0x4C), rot);
            d9_effect(D_006FBD80, index, 1, 0, 0, 0, 0.016666695f);
            void *task = d9_alloc(128);
            d9_ctor(task, M2C_FIELD(arg0, int *, 0x4C), &motion);
            d9_queue(&queueD9BC, 1, -1, 1, 0, task, 0, 0, mode);
            M2C_FIELD(arg0, int *, 0x20) = 20;
        }
        break;
    case 10:
        if (M2C_FIELD(arg0, int *, 0x1C) == 30) return 1;
        break;
    case 20:
        if (d9_done(&D_007812C0, M2C_FIELD(arg0, int *, 0x10))) return 1;
        break;
    case 999:
        return 1;
    }
    M2C_FIELD(arg0, int *, 0x1C) = M2C_FIELD(arg0, int *, 0x1C) + 1;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FD9BC);
#endif

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

// NON_MATCHING: 4/175 differ, 4 edits
#ifdef NON_MATCHING
#define M2C_ULONG(expr, offset) (((e87_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int e87_X___builtin_new(int) asm("__builtin_new");
extern "C" int e87_X_attachActor__9MagSystemiii(...) asm("attachActor__9MagSystemiii");
extern "C" int e87_X_func_00163BE4(...) asm("func_00163BE4");
extern "C" int e87_X_func_001CBE38(...) asm("func_001CBE38");
extern "C" int e87_X_func_001CBEDC(int,int) asm("func_001CBEDC");
extern "C" int e87_X_func_001CFBE4(...) asm("func_001CFBE4");
extern "C" int e87_X_func_001D1410(...) asm("func_001D1410");
extern "C" int e87_X_func_001DA228(...) asm("func_001DA228");
extern "C" int e87_X_func_001DA740(...) asm("func_001DA740");
extern "C" int e87_X_func_001E71FC(...) asm("func_001E71FC");
extern "C" int e87_X_func_001EEAEC(...) asm("func_001EEAEC");
extern "C" int e87_X_func_0022B3D8(...) asm("func_0022B3D8");
extern "C" int e87_X_ror_assert(...) asm("ror_assert");
extern const char D_002FF0A0[];
extern const char D_002FF0A8[];
extern const char D_002FF0B8[];
extern const char D_002FF0C8[];
extern int D_002FF110;
extern int sysE87 asm("D_006E9840");
extern int D_007A3D80;
struct copyE87 { int w[5]; };
struct e87_ulong { long v; } __attribute__((packed));
struct e87_v94 { char pad[148]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual int call(int, int); };
extern "C" void func_001FE87C(int arg0, int arg1, int arg2, unsigned short arg3, int arg4)
{
    struct { int sp10; char pad14[44]; float sp40; float sp44; float sp48; char pad4C[4]; float sp50; float sp54; float sp58; char pad5C[4]; int sp60; short sp64; char pad66[10]; float sp70; float sp74; float sp78; char pad7C[4]; int sp80[5]; } stack;
    int temp_v1_2;
    int temp_v0;
    register int temp_s0 PS2_REG("$16");
    int temp_v0_2;
    int temp_v0_3;
    int temp_v1;
    register int var_s1 PS2_REG("$17");
    register int var_s1_2 PS2_REG("$17");
    int temp_s0_2;
    int temp_v1_3;

    temp_s0 = arg3 & 0xFFFF;
    e87_X_func_001DA228(arg0, 0x67, (int)&stack.sp60);
    if (stack.sp60 != 0) {
        temp_v1 = M2C_FIELD(arg0, int *, 0x3EC);
        var_s1 = 0;
        if (temp_v1 & 8) {
            var_s1 = (unsigned int)(temp_v1 & 0x10) > 0;
        }
        var_s1_2 = var_s1;
        if (arg4 & 0x100) var_s1_2 = 1;
        if ((e87_X_func_00163BE4((int)&D_007B2140, arg1) == 2) && (temp_v0 = e87_X_func_001CBEDC((int)&D_007812C0, stack.sp60), stack.sp64 = temp_v0, (temp_v0 == 0xA2E))) {
            if ((temp_s0 == 0xBC3) || (temp_s0 == 0xBC1)) {
                var_s1_2 = 1;
            }
        }
        if ((temp_s0 == 0xBC3) || (var_s1_2 != 0)) {
            temp_v1_2 = (int) D_002FF0A0;
            temp_s0_2 = (int)&D_006FE6A0 + (arg2 * 0x4D0);
            if (M2C_FIELD(temp_s0_2, int *, 0x11C) == 0) {
                e87_X_ror_assert((int) D_002FF0A8, 0x131, (int) D_002FF0B8);
            }
            if (temp_v1_2 == 0) {
                e87_X_ror_assert((int) D_002FF0A8, 0x131, (int) D_002FF0C8);
            }
            temp_v0_2 = e87_X_func_0022B3D8(M2C_FIELD(temp_s0_2, int *, 0x11C), temp_v1_2);
            stack.sp50 = 0.0f;
            stack.sp54 = 0.0f;
            stack.sp58 = 0.0f;
            ((e87_v94 *)(temp_s0_2))->call((int)&stack.sp10, temp_v0_2);
            stack.sp70 = stack.sp40 + stack.sp50;
            stack.sp74 = stack.sp44 + stack.sp54;
            stack.sp78 = stack.sp48 + stack.sp58;
            e87_X_func_001CFBE4((int)&D_007812C0, stack.sp60, (int)&stack.sp70);
            e87_X_func_001D1410((int)&D_007812C0, stack.sp60, 0x04000000);
            e87_X_attachActor__9MagSystemiii((int)&sysE87, e87_X_func_001CBE38((int)&D_007812C0, stack.sp60), -1, 0);
            *(copyE87 *)stack.sp80 = *(copyE87 *)&D_002FF110;
            temp_v0_3 = e87_X___builtin_new(0x80);
            e87_X_func_001EEAEC(temp_v0_3, stack.sp60, (int)&stack.sp80);
            e87_X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_3, 0, 0, 1);
            stack.sp64 = 0xA00;
            e87_X_func_001DA740(arg0, 0x66, (int)&stack.sp64);
            stack.sp60 = 0;
            e87_X_func_001DA740(arg0, 0x67, (int) (int)&stack.sp60);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FE87C);
#endif

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

// NON_MATCHING: 117/187 differ, 11 relocs differ (size 0x2EC, game 0x2E0), 70 edits
#ifdef NON_MATCHING
extern int sysFce asm("D_006E9840");
extern "C" float fce_Xf_func_0010A650__8DogActor(int) asm("func_0010A650__8DogActor");
extern "C" int fce_X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int fce_X_func_00119090__9MagSystem(...) asm("func_00119090__9MagSystem");
extern "C" int fce_X_func_0016A8A4(...) asm("func_0016A8A4");
extern "C" int fce_X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int fce_X_func_001D1C80(...) asm("func_001D1C80");
extern "C" int fce_X_func_001DC48C(...) asm("func_001DC48C");
extern "C" int fce_X_func_001F5BDC(int,int,int,int,int,float,float) asm("func_001F5BDC");
extern "C" int fce_X_func_001FAC60(...) asm("func_001FAC60");
extern "C" int fce_Xiitif_func_00169F94(int, unsigned short, int, float) asm("func_00169F94");
extern "C" int func_001FFCE0(int input)
{
    struct { unsigned short sp0; unsigned short sp2; int sp4; unsigned short sp8; } stack;
    register int arg0 PS2_REG("$18") = input;
    float var_f1;
    int temp_a1;
    int temp_a1_2;
    register int var_s0 PS2_REG("$16");
    register int var_s1 PS2_REG("$17");
    register int var_s3 PS2_REG("$19");
    int var_v0;
    int var_v1;
    int temp_s0;
    int temp_s0_2;

    temp_a1 = M2C_FIELD(arg0, int *, 0x20);
    temp_s0 = (int)&D_006FE6A0 + (M2C_FIELD(arg0, int *, 0x14) * 0x4D0);
    switch (temp_a1) {
    case 0:
                fce_X_func_0016A8A4(M2C_FIELD(arg0, int *, 0x10), 0x13);
                fce_X_func_001F5BDC(M2C_FIELD(arg0, int *, 0x10), M2C_FIELD(arg0, int *, 0x24), -1, 0, 0, 0.016666666666666666f, fce_Xf_func_0010A650__8DogActor(temp_s0));
                M2C_FIELD(arg0, int *, 0x1C) = 0;
                M2C_FIELD(arg0, int *, 0x20) = (int) (M2C_FIELD(arg0, int *, 0x20) + 1);
        break;
    case 1:
        temp_a1_2 = M2C_FIELD(arg0, int *, 0x1C);
        var_v1 = 0;
        if (temp_a1_2 >= M2C_FIELD(arg0, int *, 0x44)) {
            var_v1 = (unsigned int)(M2C_FIELD(arg0, int *, 0x48) < temp_a1_2) == 0;
        }
        var_f1 = (float)(unsigned int)var_v1;
        if (var_f1 != 0.0f) {
            register int manager PS2_REG("$20") = (int)&D_007812C0;
            register int system PS2_REG("$21") = (int)&sysFce;
            fce_X_func_001D1C80(manager, M2C_FIELD(arg0, int *, 0x10), 0x66, (int)&stack);
            temp_s0_2 = manager + 0x22220;
            fce_X_func_001D1C80(manager, M2C_FIELD(arg0, int *, 0x10), 0x67, (int)&stack.sp4);
            var_s3 = 0;
            fce_X_func_001DC48C(temp_s0_2, stack.sp0, 0x22, (int)&stack.sp2);
            var_s0 = 0;
            fce_X_func_001DC48C(temp_s0_2, stack.sp0, 0x30, (int)&stack.sp8);
            if (M2C_FIELD(manager, int *, 0x22090) != 0) {
                var_s0 = M2C_FIELD(M2C_FIELD(manager, int *, 0x22090), int *, 0x100);
            }
            if ((fce_X_func_00118FEC__9MagSystem(system) != 9) && (fce_Xiitif_func_00169F94(stack.sp4, stack.sp2, var_s0, (float) stack.sp8) != 0)) {
                var_s3 = 1;
                fce_X_func_001FAC60(0xB, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), var_s0, 0);
            }
            var_s1 = 0;
            if (M2C_FIELD(manager, int *, 0x22094) != 0) {
                var_s1 = M2C_FIELD(M2C_FIELD(manager, int *, 0x22094), int *, 0x100);
            }
            if ((fce_X_func_00119090__9MagSystem(system) != 0xA) && (fce_X_func_00119090__9MagSystem(system) != 0xD) && (fce_Xiitif_func_00169F94(stack.sp4, stack.sp2, var_s1, (float) stack.sp8) != 0)) {
                var_s3 = 1;
                fce_X_func_001FAC60(0xB, M2C_FIELD(arg0, int *, 0x10), 0, 0, M2C_FIELD(arg0, int *, 0x3C), var_s1, 0);
            }
            fce_X_func_0016A8A4(M2C_FIELD(arg0, int *, 0x10), (var_s3 == 0) ? 0xF : 0x10);
        }
        if (M2C_FIELD(arg0,int *,0x1C) == M2C_FIELD(arg0,int *,0x48)) M2C_FIELD(arg0,int *,0x20) = 20;
        break;
    case 20:
        if (fce_X_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0,int *,0x10)) != 0) return 1;
        break;
    case 999: return 1;
    }
    M2C_FIELD(arg0,int *,0x1C)++;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_001FFCE0);
#endif

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

// NON_MATCHING: 35/141 differ, 7 relocs differ, 32 edits
#ifdef NON_MATCHING
extern "C" unsigned int e988_00200BC4(int) asm("func_00200BC4");
extern "C" void e988_0017C340(int,float *,float *,int,float,float) asm("func_0017C340");
extern "C" int e988_001D046C(int,int) asm("func_001D046C");
extern "C" void e988_0020313C(int,int,float *) asm("func_0020313C");
extern "C" int e988_0017D298(int,void *) asm("func_0017D298");
extern "C" void e988_0010B1B0(void *,int,int,float,int,int) asm("func_0010B1B0__8DogActoriifii");
extern "C" void e988_002019D0(int) asm("func_002019D0");
extern "C" unsigned int e988_00201D58(int,float *) asm("func_00201D58");
extern "C" int func_00200988(int arg0, float *arg1) {
    struct { int mode; float *start; float *end; void *path; } stack;
    float sp10[4];
    float sp20[4];
    int temp_a1;
    int temp_v0;
    int var_a1;
    unsigned int temp_v0_2;
    unsigned int var_v0;
    int temp_s0;
    int offset = 0x8542C;

    temp_v0_2 = e988_00200BC4(arg0);
    switch (temp_v0_2) {
    case 0: return 1;
    case 1:
    case 2:
        stack.mode = 1;
        e988_0017C340((int)D_006FBD80 + offset, D_006E97D8, sp10, 0, 40.0f, 30.0f);
        temp_a1 = M2C_FIELD(arg0, int *, 0x38);
        stack.start = sp10;
        if (temp_a1 != 0) {
            temp_v0 = e988_001D046C((int)&D_007812C0, temp_a1);
            if (temp_v0 == 0) {
                *M2C_FIELD(arg0, int **, 0x30) = 2;
                M2C_FIELD(arg0, float *, 0x78) = M2C_FIELD(arg0, float *, 0x7C) = M2C_FIELD(arg0, float *, 0x80) = 0.0f;
                return temp_v0;
            }
            e988_0020313C(arg0, M2C_FIELD(arg0, int *, 0x38), (float *)(arg0 + 0x78));
            goto block_9;
        }
        M2C_FIELD(arg0, float *, 0x78) = (float) M2C_FIELD(arg0, float *, 0x3C);
        M2C_FIELD(arg0, float *, 0x7C) = (float) M2C_FIELD(arg0, float *, 0x40);
        M2C_FIELD(arg0, float *, 0x80) = (float) M2C_FIELD(arg0, float *, 0x44);
block_9:
        temp_s0 = (int)D_006FBD80 + offset;
        e988_0017C340(temp_s0, (float *)(arg0 + 0x78), sp20, 0, 40.0f, 80.0f);
        stack.end = sp20;
        stack.path = (void *)(arg0 + 0x88);
        if (e988_0017D298((stack.mode * 0x18) + temp_s0 + 8, &stack) != 0 && M2C_FIELD(arg0, int *, 0x284) > 0) {
            e988_002019D0(arg0);
            var_v0 = e988_00201D58(arg0, arg1);
        } else {
            M2C_FIELD(arg0, int *, 0x68) = 0;
            e988_0010B1B0(M2C_FIELD(arg0, void **, 0x28), (M2C_FIELD(arg0, int *, 0x70) != 0) ? 0xA : 2, 0, M2C_FIELD(arg0, float *, 0x4C), -1, -1);
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, unsigned int *, 0x2C) = 1;
            return 0;
        }
block_20:
        M2C_FIELD(arg0, unsigned int *, 0x2C) = var_v0;
    default:
        return 1;
    case 4:
        M2C_FIELD(arg0, int *, 0x68) = 0;
        var_a1 = (M2C_FIELD(arg0, int *, 0x70) != 0) ? 0xA : 2;
block_19:
        e988_0010B1B0(M2C_FIELD(arg0, void **, 0x28), var_a1, 0, M2C_FIELD(arg0, float *, 0x4C), -1, -1);
        M2C_FIELD(arg0, int *, 0x5C) = 0;
        var_v0 = 1;
        goto block_20;
    case 3:
        var_a1 = M2C_FIELD(arg0, int *, 0xAB0);
        goto block_19;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00200988);
#endif

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

// NON_MATCHING: 243/256 differ, 47 relocs differ (size 0x400, game 0x44C), 125 edits
#ifdef NON_MATCHING
extern "C" float d18_atan(float, float) asm("func_0026CB00");
extern "C" float d18_yaw(void *) asm("func_0010A650__8DogActor");
extern "C" int d18_busy(void *) asm("func_0010A834__8DogActor");
extern "C" int d18_motion(void *) asm("func_0010DB38__8DogActor");
extern "C" void d18_play(void *, int, int, float, int, int) asm("func_0010B1B0__8DogActoriifii");
extern "C" int d18_near(void *, void *, float) asm("func_00169A98");
extern "C" void d18_turn(void *, float) asm("func_00202874");
extern "C" int d18_check(void *, float *) asm("func_00201164");
extern "C" void d18_move(void *, float *) asm("func_00201524");
extern "C" int d18_test(void *, float *) asm("func_00202234");
extern "C" unsigned int d18_next(void *, float *) asm("func_00201D58");
extern "C" void d18_stop(void *) asm("func_00202638");
extern "C" int d18_step(void *, float *) asm("func_00202138");
extern const double d18_2FF338 asm("D_002FF338");
extern const double d18_2FF340 asm("D_002FF340");
extern const double d18_2FF348 asm("D_002FF348");
extern const double d18_2FF350 asm("D_002FF350");
extern const double d18_2FF358 asm("D_002FF358");
extern const double d18_2FF360 asm("D_002FF360");
extern const double d18_2FF368 asm("D_002FF368");
extern const double d18_2FF370 asm("D_002FF370");
extern const double d18_2FF378 asm("D_002FF378");
static inline void d18_getyaw(void *actor, float *out) { *out = d18_yaw(actor); }
static inline void d18_getatan(float *out, float x, float z) { *out = d18_atan(x, z); }
extern "C" void func_00200D18(void *arg0, float *arg1) {
    float yaw, facing;
    switch (M2C_FIELD(arg0, unsigned int *, 0x2C)) {
    case 0:
        if (d18_check(arg0, arg1)) { d18_move(arg0, arg1); return; }
        return;
    case 1:
        if (!d18_busy((char *)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0xC) * 0x4D0)) {
            if (!d18_test(arg0, arg1)) M2C_FIELD(arg0, unsigned int *, 0x2C) = d18_next(arg0, arg1);
        } else d18_stop(arg0);
        break;
    case 2: {
        char *base = (char *)arg0 + 0x18;
        char *point = base + M2C_FIELD(arg0, int *, 0xA7C) * 16;
        d18_getatan(&yaw, M2C_FIELD(point, float *, 0x270) - D_006E97D8[0], M2C_FIELD(point, float *, 0x278) - D_006E97D8[2]);
        d18_getyaw(M2C_FIELD(arg0, void **, 0x28), &facing);
        float angle = yaw - facing;
        int direction = M2C_FIELD(arg0, int *, 0xA80);
        if ((double)angle < d18_2FF338) angle = (float)((double)angle + d18_2FF340);
        if ((double)angle > d18_2FF348) angle = (float)((double)angle - d18_2FF350);
        if (angle > 0.0f) {
            if (direction == 0) goto turning;
            goto reset;
        }
        if (direction != 0) {
turning:
            if (!d18_busy((char *)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0xC) * 0x4D0)) d18_turn(arg0, angle);
            float magnitude = angle;
            if (magnitude < 0.0f) magnitude = -magnitude;
            int index = M2C_FIELD(arg0, int *, 0xA7C);
            if (index >= M2C_FIELD(arg0, int *, 0xA78) - 1) {
                if (magnitude < M2C_FIELD(arg0, float *, 0xA84)) {
                    int *flag = M2C_FIELD(arg0, int **, 0x30);
                    if (d18_near(arg1, (char *)arg0 + 0x78, M2C_FIELD(arg0, float *, 0xA8C))) { *flag = 1; return; }
                    *flag = 0;
                    point = base + M2C_FIELD(arg0, int *, 0xA7C) * 16;
                    goto advance;
                }
            } else if ((double)magnitude < d18_2FF358) {
                point = base + index * 16;
advance:
                d18_getatan(&yaw, M2C_FIELD(point, float *, 0x270) - arg1[0], M2C_FIELD(point, float *, 0x278) - arg1[2]);
                d18_getyaw(M2C_FIELD(arg0, void **, 0x28), &facing);
                float diff = yaw - facing;
                if ((double)diff < d18_2FF360) diff = (float)((double)diff + d18_2FF368);
                if ((double)diff > d18_2FF370) diff = (float)((double)diff - d18_2FF378);
                if (!d18_step(arg0, arg1)) M2C_FIELD(arg0, unsigned int *, 0x2C) = d18_next(arg0, arg1);
            }
        } else {
reset:
            M2C_FIELD(arg0, int *, 0xAA4) = 0;
            M2C_FIELD(arg0, unsigned int *, 0x2C) = 0;
            return;
        }
        break;
    }
    case 3:
        if (!d18_motion(M2C_FIELD(arg0, void **, 0x28))) {
            if (M2C_FIELD(arg0, int *, 0x68)) { M2C_FIELD(arg0, unsigned int *, 0x2C) = 4; return; }
            M2C_FIELD(arg0, unsigned int *, 0x2C) = 0;
            return;
        }
        break;
    case 4:
        if (!d18_busy((char *)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0xC) * 0x4D0)) {
            int motion = 7;
            if (!M2C_FIELD(arg0, int *, 0x74)) motion = M2C_FIELD(arg0, int *, 0x64);
            d18_play(M2C_FIELD(arg0, void **, 0x28), motion, 0x41, M2C_FIELD(arg0, float *, 0x4C), -1, -1);
            M2C_FIELD(arg0, int *, 0x5C) = motion;
            M2C_FIELD(arg0, int *, 0x60) = 0x41;
            M2C_FIELD(arg0, unsigned int *, 0x2C) = 3;
            M2C_FIELD(arg0, int *, 0x68) = 0;
            return;
        }
        d18_stop(arg0);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00200D18);
#endif

// NON_MATCHING: 207/231 differ, 41 relocs differ (size 0x39C, game 0x3C0), 124 edits
#ifdef NON_MATCHING
extern "C" float f1164_atan(float, float) asm("func_0026CB00");
extern "C" int f1164_near(int, int, float) asm("func_00169A98");
extern "C" void f1164_turn(int, float) asm("func_00202874");
extern "C" void f1164_target(int, int, int) asm("func_0020313C");
extern const double d1164_2FF380 asm("D_002FF380");
extern const double d1164_2FF388 asm("D_002FF388");
extern const double d1164_2FF390 asm("D_002FF390");
extern const double d1164_2FF398 asm("D_002FF398");
extern const double d1164_2FF3A0 asm("D_002FF3A0");
extern const double d1164_2FF3A8 asm("D_002FF3A8");
extern const double d1164_2FF3B0 asm("D_002FF3B0");
extern const double d1164_2FF3B8 asm("D_002FF3B8");
extern const double d1164_2FF3C0 asm("D_002FF3C0");
extern const double d1164_2FF3C8 asm("D_002FF3C8");
extern const double d1164_2FF3D0 asm("D_002FF3D0");
extern const double d1164_2FF3D8 asm("D_002FF3D8");
extern "C" float f1164_yaw(void *) asm("func_0010A650__8DogActor");
static inline void yaw1164(void *actor, float *out) { *out = f1164_yaw(actor); }
static inline void atan1164(float *out, float x, float z) { *out = f1164_atan(x, z); }
extern "C" int func_00201164(int arg0, int arg1) {
    float yaw, facing;
    int index = M2C_FIELD(arg0, int *, 0xA7C);
    if (index < M2C_FIELD(arg0, int *, 0xA78) - 1) {
        if (f1164_near(arg1, arg0 + index * 16 + 0x288, 2.0f * M2C_FIELD(arg0, float *, 0xA88)))
            M2C_FIELD(arg0, int *, 0xA7C) = M2C_FIELD(arg0, int *, 0xA7C) + 1;
        if (M2C_FIELD(arg0, int *, 0xA7C) < M2C_FIELD(arg0, int *, 0xA78) - 1) return 1;
    }
    int end = arg0 + 0x78;
    int base = arg0 + 0x18;
    if (f1164_near(arg1, end, M2C_FIELD(arg0, float *, 0xA8C))) {
        int point = base + M2C_FIELD(arg0, int *, 0xA7C) * 16;
        double low = d1164_2FF380;
        atan1164(&yaw, M2C_FIELD(point, float *, 0x270) - M2C_FIELD(arg1, float *, 0),
                        M2C_FIELD(point, float *, 0x278) - M2C_FIELD(arg1, float *, 8));
        yaw1164(M2C_FIELD(arg0, void **, 0x28), &facing);
        float diff = yaw - facing;
        float wrapped = diff;
        if ((double)wrapped < low) wrapped = (float)((double)wrapped + d1164_2FF388);
        double high = d1164_2FF390;
        if ((double)wrapped > high) wrapped = (float)((double)wrapped - d1164_2FF398);
        float value = diff;
        float magnitude;
        if (wrapped < 0.0f) {
            if ((double)value < low) value = (float)((double)value + d1164_2FF3A0);
            if ((double)value <= high) magnitude = -value;
            else magnitude = -(float)((double)value - d1164_2FF3A8);
        } else {
            if ((double)value < low) value = (float)((double)value + d1164_2FF3B0);
            magnitude = value;
            if ((double)value > high) magnitude = (float)((double)value - d1164_2FF3B8);
        }
        if (M2C_FIELD(arg0, float *, 0xA84) < magnitude) {
            float turn = yaw - facing;
            if ((double)turn < d1164_2FF3C0) turn = (float)((double)turn + d1164_2FF3C8);
            if ((double)turn > d1164_2FF3D0) turn = (float)((double)turn - d1164_2FF3D8);
            f1164_turn(arg0, turn);
            return 0;
        }
    }
    int target = M2C_FIELD(arg0, int *, 0x38);
    if (target) {
        f1164_target(arg0, target, end);
        int destbase = arg0 + 0x18;
        M2C_FIELD(destbase + M2C_FIELD(arg0, int *, 0xA7C) * 16, float *, 0x270) = M2C_FIELD(arg0, float *, 0x78);
        M2C_FIELD(destbase + M2C_FIELD(arg0, int *, 0xA7C) * 16, float *, 0x274) = M2C_FIELD(arg0, float *, 0x7C);
        M2C_FIELD(destbase + M2C_FIELD(arg0, int *, 0xA7C) * 16, float *, 0x278) = M2C_FIELD(arg0, float *, 0x80);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00201164);
#endif

// NON_MATCHING: 265/282 differ, 54 relocs differ (size 0x468, game 0x4AC), 130 edits
#ifdef NON_MATCHING
extern "C" float f1524_atan(float, float) asm("func_0026CB00");
extern "C" float f1524_yaw(void *) asm("func_0010A650__8DogActor");
extern "C" float sqrtf(float x);
extern "C" int f1524_test(void *, float *, float, float) asm("func_00201FA4");
extern "C" int f1524_mode(void *, float) asm("func_00202380");
extern "C" void f1524_turn(void *, float) asm("func_00202874");
extern "C" void f1524_move(void *, float *, float) asm("func_00202900");
extern "C" void f1524_pos(int, float *) asm("func_0016A594");
extern "C" int f1524_near(float *, void *, float) asm("func_00169A98");
static inline void f1524_getatan(float *out, float x, float z) { *out = f1524_atan(x, z); }
static inline void f1524_getyaw(void *actor, float *out) { *out = f1524_yaw(actor); }
extern const double f1524_2FF3E0 asm("D_002FF3E0");
extern const double f1524_2FF3E8 asm("D_002FF3E8");
extern const double f1524_2FF3F0 asm("D_002FF3F0");
extern const double f1524_2FF3F8 asm("D_002FF3F8");
extern const double f1524_2FF400 asm("D_002FF400");
extern const double f1524_2FF408 asm("D_002FF408");
extern const double f1524_2FF410 asm("D_002FF410");
extern const double f1524_2FF418 asm("D_002FF418");
extern const double f1524_2FF420 asm("D_002FF420");
extern const double f1524_2FF428 asm("D_002FF428");
extern const double f1524_2FF430 asm("D_002FF430");
extern const double f1524_2FF438 asm("D_002FF438");
extern const double f1524_2FF440 asm("D_002FF440");
extern "C" void func_00201524(void *arg0, float *arg1) {
    float yaw, facing, pos[4];
    char *base = (char *)arg0 + 0x18;
    char *point = base + M2C_FIELD(arg0, int *, 0xA7C) * 16;
    f1524_getatan(&yaw, M2C_FIELD(point, float *, 0x270) - arg1[0], M2C_FIELD(point, float *, 0x278) - arg1[2]);
    f1524_getyaw(M2C_FIELD(arg0, void **, 0x28), &facing);
    float angle = yaw - facing;
    if ((double)angle < f1524_2FF3E0) angle = (float)((double)angle + f1524_2FF3E8);
    if ((double)angle > f1524_2FF3F0) angle = (float)((double)angle - f1524_2FF3F8);
    float magnitude = angle;
    if (angle < 0.0f) magnitude = -angle;
    if (M2C_FIELD(arg0, int *, 0x10) != 0 || !f1524_test(arg0, arg1, angle, magnitude)) {
        float turn;
        if ((double)magnitude <= f1524_2FF400) {
            point = base + M2C_FIELD(arg0, int *, 0xA7C) * 16;
            float z = M2C_FIELD(point, float *, 0x278) - D_006E97D8[2];
            float x = M2C_FIELD(point, float *, 0x270) - D_006E97D8[0];
            float dist = sqrtf(x * x + z * z);
            float limit = M2C_FIELD(arg0, float *, 0xA84);
            turn = magnitude / (dist / M2C_FIELD(arg0, float *, 0x50));
            if (limit < turn) turn = limit;
            if (angle > 0.0f) turn = -turn;
        } else {
            M2C_FIELD(arg0, int *, 0x74) = 0;
            turn = 0.0f;
        }
        switch (f1524_mode(arg0, turn)) {
        case 1: f1524_turn(arg0, angle); break;
        case 2: f1524_move(arg0, arg1, facing); break;
        }
        if (M2C_FIELD(arg0, int *, 0xA7C) == M2C_FIELD(arg0, int *, 0xA78) - 1) {
            f1524_pos(M2C_FIELD(arg0, int *, 8), pos);
            if (f1524_near(arg1, (char *)arg0 + 0x78, M2C_FIELD(arg0, float *, 0xA8C))) {
                point = base + M2C_FIELD(arg0, int *, 0xA7C) * 16;
                double low = f1524_2FF408;
                f1524_getatan(&yaw, M2C_FIELD(point, float *, 0x270) - pos[0], M2C_FIELD(point, float *, 0x278) - pos[2]);
                f1524_getyaw(M2C_FIELD(arg0, void **, 0x28), &facing);
                float diff = yaw - facing;
                float wrapped = diff;
                if ((double)wrapped < low) wrapped = (float)((double)wrapped + f1524_2FF410);
                double high = f1524_2FF418;
                if ((double)wrapped > high) wrapped = (float)((double)wrapped - f1524_2FF420);
                float value = diff;
                float absangle;
                if (wrapped < 0.0f) {
                    if ((double)value < low) value = (float)((double)value + f1524_2FF428);
                    if ((double)value <= high) absangle = -value;
                    else absangle = -(float)((double)value - f1524_2FF430);
                } else {
                    if ((double)value < low) value = (float)((double)value + f1524_2FF438);
                    absangle = value;
                    if ((double)value > high) absangle = (float)((double)value - f1524_2FF440);
                }
                if (absangle < M2C_FIELD(arg0, float *, 0xA84)) {
                    *M2C_FIELD(arg0, int **, 0x30) = 1;
                } else {
                    *M2C_FIELD(arg0, int **, 0x30) = 0;
                }
            } else {
                *M2C_FIELD(arg0, int **, 0x30) = 0;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00201524);
#endif

// NON_MATCHING: 181/215 differ, 40 relocs differ (size 0x35C, game 0x388), 116 edits
#ifdef NON_MATCHING
extern "C" float f19_atan(float, float) asm("func_0026CB00");
extern "C" void f19_trace(void *, float *, void *, int, float, float) asm("func_0017C340");
extern const double D_002FF448;
extern const double D_002FF450;
extern const double D_002FF458;
extern const double D_002FF460;
extern const double D_002FF468;
extern const double D_002FF470;
extern const double D_002FF478;
extern const double D_002FF480;
extern const double D_002FF488;
extern const double D_002FF490;
extern const double D_002FF498;
extern const double D_002FF4A0;
extern const double D_002FF4A8;
struct Vec19 { float x, y, z; };
extern "C" void func_002019D0(void *arg0, void *arg1) {
    float prev[4], next[4];
    int hits[4];
    int count;
#ifdef AVOID_UB
    count = 0;
#endif
    float angle;
    M2C_FIELD(arg0, int *, 0xA7C) = 0;
    int n = M2C_FIELD(arg0, int *, 0x284);
    if (n == 1) {
        float x = M2C_FIELD(arg0, float *, 0x78);
        float y = M2C_FIELD(arg0, float *, 0x7C);
        float z = M2C_FIELD(arg0, float *, 0x80);
        M2C_FIELD(arg0, int *, 0xA78) = n;
        M2C_FIELD(arg0, float *, 0x288) = x;
        M2C_FIELD(arg0, float *, 0x28C) = y;
        M2C_FIELD(arg0, float *, 0x290) = z;
        return;
    } else {
        next[1] = 0;
        int i = 0;
        prev[0] = D_006E97D8[0]; prev[1] = D_006E97D8[1]; prev[2] = D_006E97D8[2];
        if (n - 1 > 0) {
            do {
                int j = i + 1;
                if (j == M2C_FIELD(arg0, int *, 0x284) - 1) {
                    float x = M2C_FIELD(arg0, float *, 0x78); float y = M2C_FIELD(arg0, float *, 0x7C); float z = M2C_FIELD(arg0, float *, 0x80); next[0] = x; next[1] = y; next[2] = z;
                } else {
                    float *p = (float *)((char *)M2C_FIELD((char *)arg0 + i * 4, void **, 0x8C) + 0x10);
                    next[0] = p[0]; next[1] = p[1]; next[2] = p[2];
                }
                float yaw = f19_atan(next[0] - prev[0], next[2] - prev[2]);
                if (i == 0) count = 0;
                else {
                    f19_trace(D_006FBD80 + 0x8542C, (float *)((char *)arg0 + 0x78), hits, 0, 40.0f, 0.0f);
                    if (hits[1]) {
                        float diff = yaw - angle;
                        float wrapped = diff;
                        if ((double)wrapped < D_002FF448) wrapped = (float)((double)wrapped + D_002FF450);
                        if ((double)wrapped > D_002FF458) wrapped = (float)((double)wrapped - D_002FF460);
                        float magnitude;
                        if (wrapped < 0.0f) {
                            float v = diff;
                            if ((double)v < D_002FF468) v = (float)((double)v + D_002FF470);
                            if ((double)v > D_002FF478) magnitude = -(float)((double)v - D_002FF480);
                            else magnitude = -v;
                        } else {
                            float v = diff;
                            if ((double)v < D_002FF488) v = (float)((double)v + D_002FF490);
                            magnitude = v;
                            if ((double)v > D_002FF498) magnitude = (float)((double)v - D_002FF4A0);
                        }
                        if ((double)magnitude < D_002FF4A8) count--;
                    }
                }
                char *dst = (char *)arg0 + 0x18 + count * 16;
                count++;
                M2C_FIELD(dst, float *, 0x270) = next[0]; M2C_FIELD(dst, float *, 0x274) = next[1]; M2C_FIELD(dst, float *, 0x278) = next[2];
                i = j;
                angle = yaw;
                prev[0] = next[0]; prev[1] = next[1]; prev[2] = next[2];
            } while (i < M2C_FIELD(arg0, int *, 0x284) - 1);
        }
        M2C_FIELD(arg0, int *, 0xA78) = count;
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_002019D0);
#endif

// NON_MATCHING: 134/147 differ, 15 relocs differ, 68 edits
#ifdef NON_MATCHING
extern const double D_002FF4B0, D_002FF4B8, D_002FF4C0, D_002FF4C8, D_002FF4D0;
extern "C" float atanD58(float,float) asm("func_0026CB00");
extern "C" float yawD58(void *) asm("func_0010A650__8DogActor");
extern "C" void animD58(void *,int,int,float,int,int) asm("func_0010B1B0__8DogActoriifii");
extern "C" void turnD58(int,float) asm("func_00202874");
extern "C" unsigned int func_00201D58(int input, float *arg1) {
    register int arg0 PS2_REG("$17") = input;
    volatile float yawSlot;
    volatile float sp4;
    int var_a2;
    float temp_f0;
    float temp_f0_2;
    float temp_f1;
    float temp_f2;
    float var_f0;
    float var_f12;
    register float var_f20 PS2_REG("$f20");
    int temp_v0;
    int temp_v0_2;
    register int var_s0 PS2_REG("$16");
    register int var_s2_2 PS2_REG("$18");
    unsigned int var_s2;
    int temp_a0;
    int temp_a1;

    var_s2_2 = 0;
    temp_a0 = arg0 + 0x18;
    temp_a1 = (M2C_FIELD(arg0, int *, 0xA7C) * 0x10) + temp_a0;
    sp4 = atanD58( M2C_FIELD(temp_a1, float *, 0x270) - M2C_FIELD(&D_006E97D8, float *, 0), M2C_FIELD(temp_a1, float *, 0x278) - M2C_FIELD(&D_006E97D8, float *, 8));
    temp_f0 = yawD58(M2C_FIELD(arg0, void **, 0x28));
    yawSlot = temp_f0;
    var_f20 = sp4 - temp_f0;
    double angle1 = var_f20;
    if (angle1 < D_002FF4B0) {
        var_f20 = (float)(angle1 + D_002FF4B8);
    }
    double angle2 = var_f20;
    if (angle2 > D_002FF4C0) {
        var_f20 = (float)(angle2 - D_002FF4C8);
    }
    var_f12 = var_f20;
    if (var_f20 < 0.0f) {
        var_f12 = -var_f20;
    }
    if ((double)var_f12 <= D_002FF4D0) {
        if (M2C_FIELD(arg0, int *, 0xA7C) == (M2C_FIELD(arg0, int *, 0xA78) - 1)) {
            temp_f0_2 = M2C_FIELD(arg0, float *, 0x78) - M2C_FIELD(arg1, float *, 0);
            temp_f2 = M2C_FIELD(arg0, float *, 0xAB4);
            temp_f1 = M2C_FIELD(arg0, float *, 0x80) - M2C_FIELD(arg1, float *, 8);
            if (!(((temp_f0_2 * temp_f0_2) + (temp_f1 * temp_f1)) < (temp_f2 * temp_f2))) {
                var_f0 = M2C_FIELD(arg0, float *, 0x54);
            } else {
                var_f0 = M2C_FIELD(arg0, float *, 0x58);
                var_s2_2 = 1;
            }
            M2C_FIELD(arg0, float *, 0x50) = var_f0;
        }
        M2C_FIELD(arg0, int *, 0x74) = var_s2_2;
        if (M2C_FIELD(arg0, int *, 0x10) == 0) {
            var_a2 = 0x41;
            var_s0 = 0xB;
            if (M2C_FIELD(arg0, int *, 0x70) == 0) {
                goto block_22;
            }
            goto block_24;
        }
        var_a2 = 0x40;
        if (M2C_FIELD(arg0, int *, 0x68) != 0) {
            var_s0 = (var_s2_2 == 0) ? 0xA : 0xB;
            var_s2 = 3;
            M2C_FIELD(arg0, int *, 0x6C) = 1;
            M2C_FIELD(arg0, int *, 0x60) = 0x40;
        } else {
            var_a2 = 0x41;
block_22:
            var_s0 = 7;
            if (var_s2_2 == 0) {
                var_s0 = M2C_FIELD(arg0, int *, 0x64);
            }
block_24:
            var_s2 = 0;
        }
        if (M2C_FIELD(arg0, int *, 0x5C) != var_s0) {
            animD58(M2C_FIELD(arg0, void **, 0x28), var_s0, var_a2, M2C_FIELD(arg0, float *, 0x4C), -1, -1);
            M2C_FIELD(arg0, int *, 0x5C) = var_s0;
        } else {
            var_s2 = 0;
        }
        return var_s2;
    }
    turnD58(arg0, var_f20);
    return 2U;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00201D58);
#endif

extern "C" float Xfi_func_0010A650__8DogActor(void *) asm("func_0010A650__8DogActor");
extern "C" int func_00201FA4(void *arg0, float *arg1)
{
  float v1[4];
  float v2[4];
  float yaw;
  float dist = 70.0f;
  yaw = Xfi_func_0010A650__8DogActor(*((void **) (((char *) arg0) + 0x28)));
  v1[1] = (v2[1] = arg1[1]);
  v1[0] = arg1[0] + (sinf(yaw) * dist);
  v1[2] = arg1[2] + (cosf(yaw) * dist);
  v2[0] = D_006E97D8[0] + (sinf(yaw) * dist);
  v2[2] = D_006E97D8[2] + (cosf(yaw) * dist);
  if (Xiiiii_func_00202E20(arg0, v1, v2, *((int *) (((char *) arg0) + 0x38))) != 0)
  {
    Xiiif_func_00202900(arg0, arg1, yaw);
    return 1;
  }
  dist = 30.0f;
  v1[0] = arg1[0] + (sinf(yaw) * dist);
  v1[2] = arg1[2] + (cosf(yaw) * dist);
  v2[0] = D_006E97D8[0] + (sinf(yaw) * dist);
  v2[2] = D_006E97D8[2] + (cosf(yaw) * dist);
  if (Xiiiii_func_00202E20(arg0, v1, v2, *((int *) (((char *) arg0) + 0x38))) != 0)
  {
    Xiiif_func_00202900(arg0, arg1, yaw);
 do { } while (0);
    return 1;
  }
  return 0;
}

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

// NON_MATCHING: 79/173 differ, 10 relocs differ (size 0x2B4, game 0x2B8), 40 edits
#ifdef NON_MATCHING
extern const double D_002FF4F8, D_002FF500, D_002FF508, D_002FF510;
extern "C" float e2380_yaw(void *) asm("func_0010A650__8DogActor");
extern "C" int e2380_state(void *) asm("func_0010DB18__8DogActor");
extern "C" float e2380_time(void *) asm("func_0010DA4C__8DogActor");
extern "C" void e2380_vec(void *,float,float,float *,float *,float *) asm("func_00109348__8DogActorffR9DogVectorPfP9DogVector");
extern "C" void e2380_turn(float *,float) asm("vecTurnY__FPff");
extern "C" void e2380_ground(int,float *,int *,int,float,float) asm("func_0017C340");
extern "C" int e2380_hit(int,float *,int,int,void *,void *) asm("func_001D5A0C");
extern "C" void e2380_move(void *,float *,float,float) asm("func_0010A090__8DogActorRC9DogVectorff");
extern "C" int func_00202380(int arg0, float inputAngle) {
 register float angle PS2_REG("$f24") = inputAngle;
 float delta[4], rot[4], pos[4], value;
 int ground[4];
 float y;
 float *r = rot;
 float *p = pos;
 delta[0] = delta[1] = delta[2] = 0.0f; delta[3] = 1.0f;
 r[0] = rot[1] = rot[2] = 0.0f; rot[3] = 1.0f;
 p[0] = pos[1] = pos[2] = 0.0f; pos[3] = 1.0f;
 y = 0.0f;
 value = y;
 register float yaw PS2_REG("$f23") = e2380_yaw(M2C_FIELD(arg0,void **,0x28));
 if (e2380_state(M2C_FIELD(arg0,void **,0x28)) < 0) {
  float t = e2380_time(M2C_FIELD(arg0,void **,0x28));
  if (t >= y) {
   void *actor = M2C_FIELD(arg0,void **,0x28);
   e2380_vec(actor, 2.0f * t, 2.0f * (t + M2C_FIELD(actor,float *,0x1E8) / 0.016666694f),delta,&value,r);
   y = rot[1];
  }
  delta[3] = 1.0f;
  e2380_turn(delta,M2C_FIELD(M2C_FIELD(arg0,void **,0x28),float *,0x3C4));
  void *actor = M2C_FIELD(arg0,void **,0x28);
  int off = 0x8542C;
  int world = (int)D_006FBD80 + off;
  p[0] = M2C_FIELD(actor,float *,0x40) + delta[0];
  pos[1] = M2C_FIELD(actor,float *,0x44) + delta[1];
  pos[2] = M2C_FIELD(actor,float *,0x48) + delta[2];
  e2380_ground(world,D_006E97D8,ground,0,40.0f,0.0f);
  if (ground[M2C_FIELD(arg0,int *,0x14)] != 0) {
   e2380_ground(world,p,(int *)(arg0+0x18),0,40.0f,0.0f);
   if (M2C_FIELD(arg0 + M2C_FIELD(arg0,int *,0x14)*4,int *,0x18) == 0) return 1;
  }
  if (e2380_hit((int)&D_007812C0,p,M2C_FIELD(arg0,int *,8),0,0,0) != 0) return 2;
  register float diff PS2_REG("$f20") = yaw - angle;
  if ((double)diff < D_002FF4F8) diff = (float)((double)diff + D_002FF500);
  if ((double)diff > D_002FF508) diff = (float)((double)diff - D_002FF510);
  e2380_move(M2C_FIELD(arg0,void **,0x28),delta,y,diff);
 }
 return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00202380);
#endif

// NON_MATCHING: 30/143 differ, 21 edits
#ifdef NON_MATCHING
extern "C" float e2638_yaw(void *) asm("func_0010A650__8DogActor");
extern "C" int e2638_state(void *) asm("func_0010DB18__8DogActor");
extern "C" float e2638_time(void *) asm("func_0010DA4C__8DogActor");
extern "C" void e2638_vec(void *,float,float,float *,float *,float *) asm("func_00109348__8DogActorffR9DogVectorPfP9DogVector");
extern "C" void e2638_turn(float *,float) asm("vecTurnY__FPff");
extern "C" void e2638_ground(int,float *,int *,int,float,float) asm("func_0017C340");
extern "C" int e2638_hit(int,float *,int,int,void *,void *) asm("func_001D5A0C");
extern "C" void e2638_move(void *,float *,float,float) asm("func_0010A090__8DogActorRC9DogVectorff");
extern "C" int func_00202638(int arg0) {
 float delta[4], rot[4], pos[4], value;
 int hit[8];
 int ground[4];
 float y;
 float *r = rot;
 float *p = pos;
 delta[0] = delta[1] = delta[2] = 0.0f; delta[3] = 1.0f;
 r[0] = rot[1] = rot[2] = 0.0f; rot[3] = 1.0f;
 p[0] = pos[1] = pos[2] = 0.0f; pos[3] = 1.0f;
 y = 0.0f;
 value = y;
 register float yaw PS2_REG("$f23") = e2638_yaw(M2C_FIELD(arg0,void **,0x28));
 if (e2638_state(M2C_FIELD(arg0,void **,0x28)) < 0) {
  float t = e2638_time(M2C_FIELD(arg0,void **,0x28));
  if (t >= y) {
   void *actor = M2C_FIELD(arg0,void **,0x28);
   e2638_vec(actor, 2.0f * t, 2.0f * (t + M2C_FIELD(actor,float *,0x1E8) / 0.016666694f),delta,&value,r);
   y = rot[1];
  }
  delta[3] = 1.0f;
  e2638_turn(delta,M2C_FIELD(M2C_FIELD(arg0,void **,0x28),float *,0x3C4));
  void *actor = M2C_FIELD(arg0,void **,0x28);
  int off = 0x8542C;
  int world = (int)D_006FBD80 + off;
  p[0] = M2C_FIELD(actor,float *,0x40) + delta[0];
  pos[1] = M2C_FIELD(actor,float *,0x44) + delta[1];
  pos[2] = M2C_FIELD(actor,float *,0x48) + delta[2];
  e2638_ground(world,D_006E97D8,ground,0,40.0f,0.0f);
  if (ground[M2C_FIELD(arg0,int *,0x14)] != 0) {
   e2638_ground(world,p,(int *)(arg0+0x18),0,40.0f,0.0f);
   if (M2C_FIELD(arg0 + M2C_FIELD(arg0,int *,0x14)*4,int *,0x18) == 0) return 1;
  }
  if (e2638_hit((int)&D_007812C0,p,M2C_FIELD(arg0,int *,8),0,0,hit) != 0 && (((unsigned int)hit[4] >> 23) & 31) != 2) return 2;
  e2638_move(M2C_FIELD(arg0,void **,0x28),delta,y,yaw);
 }
 return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00202638);
#endif

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

// NON_MATCHING: 261/329 differ, 50 relocs differ (size 0x524, game 0x520), 73 edits
#ifdef NON_MATCHING
extern "C" int f2900_rand(int, int) asm("func_0010423C");
extern "C" int f2900_check(void *, float *, float *, int) asm("func_00202E20");
extern "C" void f2900_play(void *, int, int, float, int, int) asm("func_0010B1B0__8DogActoriifii");
extern const double f2900_2FF518 asm("D_002FF518");
extern const double f2900_2FF520 asm("D_002FF520");
extern const double f2900_2FF528 asm("D_002FF528");
extern const double f2900_2FF530 asm("D_002FF530");
extern const double f2900_2FF538 asm("D_002FF538");
extern const double f2900_2FF540 asm("D_002FF540");
extern const double f2900_2FF548 asm("D_002FF548");
extern const double f2900_2FF550 asm("D_002FF550");
extern const double f2900_2FF558 asm("D_002FF558");
extern const double f2900_2FF560 asm("D_002FF560");
extern const double f2900_2FF568 asm("D_002FF568");
extern const double f2900_2FF570 asm("D_002FF570");
extern "C" void func_00202900(void *arg0, float *arg1, float facing) {
    float start[4], end[4];
    int motion;
    float angle;
    start[1] = end[1] = arg1[1];
    if (f2900_rand(0, 99) < 50) {
        angle = facing - M2C_FIELD(arg0, float *, 0xA94);
        double low = f2900_2FF518;
        if ((double)angle < low) angle = (float)((double)angle + f2900_2FF520);
        double high = f2900_2FF528;
        if ((double)angle > high) angle = (float)((double)angle - f2900_2FF530);
        start[0] = arg1[0] + sinf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        start[2] = arg1[2] + cosf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        end[0] = D_006E97D8[0] + sinf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        end[2] = D_006E97D8[2] + cosf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        int result = f2900_check(arg0, start, end, M2C_FIELD(arg0, int *, 0x38));

        motion = 16;

        if (result) {
            angle = facing + M2C_FIELD(arg0, float *, 0xA94);
        if ((double)angle < low) angle = (float)((double)angle + f2900_2FF538);
        if ((double)angle > high) angle = (float)((double)angle - f2900_2FF540);
        start[0] = arg1[0] + sinf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        start[2] = arg1[2] + cosf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        end[0] = D_006E97D8[0] + sinf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        end[2] = D_006E97D8[2] + cosf(angle) * M2C_FIELD(arg0, float *, 0xA90);
            int result = f2900_check(arg0, start, end, M2C_FIELD(arg0, int *, 0x38));

            motion = 17;

            if (result) goto failed;
        }
    } else {
        angle = facing + M2C_FIELD(arg0, float *, 0xA94);
        double low = f2900_2FF548;
        if ((double)angle < low) angle = (float)((double)angle + f2900_2FF550);
        double high = f2900_2FF558;
        if ((double)angle > high) angle = (float)((double)angle - f2900_2FF560);
        start[0] = arg1[0] + sinf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        start[2] = arg1[2] + cosf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        end[0] = D_006E97D8[0] + sinf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        end[2] = D_006E97D8[2] + cosf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        int result = f2900_check(arg0, start, end, M2C_FIELD(arg0, int *, 0x38));

        motion = 17;

        if (result) {
            angle = facing - M2C_FIELD(arg0, float *, 0xA94);
        if ((double)angle < low) angle = (float)((double)angle + f2900_2FF568);
        if ((double)angle > high) angle = (float)((double)angle - f2900_2FF570);
        start[0] = arg1[0] + sinf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        start[2] = arg1[2] + cosf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        end[0] = D_006E97D8[0] + sinf(angle) * M2C_FIELD(arg0, float *, 0xA90);
        end[2] = D_006E97D8[2] + cosf(angle) * M2C_FIELD(arg0, float *, 0xA90);
            int result = f2900_check(arg0, start, end, M2C_FIELD(arg0, int *, 0x38));

            motion = 16;

            if (result) goto failed;
        }
    }
    f2900_play(M2C_FIELD(arg0, void **, 0x28), motion, 0, M2C_FIELD(arg0, float *, 0x4C), -1, -1);
    M2C_FIELD(arg0, int *, 0x5C) = motion;
    M2C_FIELD(arg0, int *, 0x2C) = 1;
    return;
failed:
    M2C_FIELD(arg0, int *, 0xAA4) = 0;
    M2C_FIELD(arg0, int *, 0x2C) = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_00202900);
#endif

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

// NON_MATCHING: 156/195 differ, 14 relocs differ (size 0x30C, game 0x32C), 103 edits
#ifdef NON_MATCHING
extern int sys313C asm("D_006E9840");
extern char D_002FF578[], D_002FF588[], D_002FF598[], D_002FF5A8[];
extern "C" void ror_assert(const char *, int, const char *);
extern "C" float sqrtf(float);
extern "C" int f313C_bone(int, const char *) asm("func_0022B3D8");
struct Bone313C { char pad[0x94]; virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void call(float *, int); };
extern "C" void f313C_pos(int, float *) asm("func_0016A594");
extern "C" void f313C_start(void *, int, float *) asm("func_001D05F4");
extern "C" int f313C_idx(void *, int) asm("func_001CBE38");
extern "C" int f313C_mode(void *) asm("func_00118FEC__9MagSystem");
extern "C" int f313C_flag(void *) asm("func_00118FDC__9MagSystem");
extern "C" float f313C_yaw(void *) asm("func_0010A650__8DogActor");
extern "C" void f313C_trace(void *, float *, void *, int, float, float) asm("func_0017C340");
static inline void bone313C(void *actor, float *matrix, const char *name) {     if (!(*(int *)((char *)actor + 0x11C))) ror_assert(D_002FF588, 305, D_002FF598);     if (!name) ror_assert(D_002FF588, 305, D_002FF5A8);     ((Bone313C *)actor)->call(matrix, f313C_bone((*(int *)((char *)actor + 0x11C)), name)); }
extern "C" void func_0020313C(void *arg0, int arg1, float *arg2) {
    float pos[4], matrix[16];
    float *target = matrix;
    int *hits = (int *)(matrix + 4);
    float *bone = matrix + 12;
    const char *temp_v0;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f1;
    float temp_f21;
    float var_f20;
    float var_f21;
    float var_f2;
    int temp_v0_2;
    int var_v1;
    void *temp_s0;
    void *temp_v1;

    var_v1 = 0;
    if (M2C_FIELD(&D_007812C0, void **, 0x22090) != 0) {
        var_v1 = M2C_FIELD(M2C_FIELD(&D_007812C0, void **, 0x22090), int *, 0x100);
    }
    if (arg1 != var_v1) {
        f313C_pos(arg1, arg2);
        return;
    }
    f313C_start(&D_007812C0, arg1, arg2);
    temp_v0 = D_002FF578;
    temp_s0 = (char *)&D_006FE6A0 + (f313C_idx(&D_007812C0, arg1) * 0x4D0);
    bone313C(temp_s0, matrix, temp_v0);
    arg2[0] = bone[0]; arg2[2] = bone[2];
    pos[0] = bone[0]; pos[1] = bone[1]; pos[2] = bone[2];
    f313C_pos(M2C_FIELD(arg0, int *, 8), pos);
    var_f2 = pos[2];
    temp_f1 = M2C_FIELD(arg2, float *, 0) - pos[0];
    temp_f0 = M2C_FIELD(arg2, float *, 8) - var_f2;
    var_f2 = sqrtf(temp_f1 * temp_f1 + temp_f0 * temp_f0);
    var_f20 = var_f2 / M2C_FIELD(arg0, float *, 0x50);
    if (var_f20 > 250.0f) {
        var_f20 = 250.0f;
    }
    temp_v0_2 = f313C_mode(&sys313C);
    if (temp_v0_2 != 7) {
        if (temp_v0_2 < 8) {
            if (temp_v0_2 != 6) {
                goto block_22;
            }
            var_f21 = 2.575f;
            if (f313C_flag(&sys313C) == 0) {
                var_f21 = 3.714285714f;
            }
        } else {
            var_f21 = 2.5f;
            if (temp_v0_2 != 8) {
block_22:
                var_f21 = 0.0f;
            }
        }
    } else {
        var_f21 = 2.575f;
        if (f313C_flag(&sys313C) == 0) {
            var_f21 = 6.923076923f;
        }
    }
    temp_f21 = var_f21 * var_f20;
    temp_f0_2 = f313C_yaw(M2C_FIELD(arg0, void **, 0x28));
    temp_f0_3 = sinf(temp_f0_2) * temp_f21;
    target[1] = M2C_FIELD(arg2, float *, 4);
    target[0] = M2C_FIELD(arg2, float *, 0) + temp_f0_3;
    target[2] = M2C_FIELD(arg2, float *, 8) + (cosf(temp_f0_2) * temp_f21);
    f313C_trace(D_006FBD80 + 0x8542C, target, hits, 0, 40.0f, 0.0f);
    if (hits[M2C_FIELD(arg0, int *, 0x14)] != 0) {
        M2C_FIELD(arg2, float *, 0) = target[0];
        M2C_FIELD(arg2, float *, 8) = target[2];
        M2C_FIELD(arg2, float *, 4) = target[1];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskEnemyMove", func_0020313C);
#endif

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF5B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF5C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskEnemyMove", D_002FF600);
