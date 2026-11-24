#include "include_asm.h"
#include "ror.h"
#include "sdk/string.h"
#include "dog/dogtexinfo.h"
extern "C" int strncmp(const char *, const char *, size_t);
extern "C" void func_00237830(void *, void *, float);
struct MagSceneFocusTexName {
    unsigned short m_data[0x0F];
};
extern const MagSceneFocusTexName D_002EEB10;
extern const char D_002EEB40[];
extern const char D_002EEB58[];
struct MagSceneFocusGif {
    unsigned long long m_tag0;
    unsigned long long m_tag1;
    unsigned long long m_prim;
    unsigned long long m_nop;
    unsigned long long m_v0;
    unsigned long long m_v1;
    unsigned long long m_v2;
    unsigned long long m_v3;
};
extern "C" MagSceneFocusGif *func_0021B4D0(void *, int, int, int);
struct MagSceneFocusObj {
    unsigned char m_pad00[0x508];
    float (*m_unk508)[4][4];
    float *m_unk50C;
    int m_unk510;
    unsigned char m_pad514[0xC];
};
struct MagSceneFocusLerp {
    float m_unk00;
    float m_unk04;
    int m_unk08;
    int m_unk0C;
};
struct MagSceneFocus {
    unsigned char m_pad00[0x29520];
    DogTexInfo m_tex_info;
    MagSceneFocusObj m_unk29540[4];
    unsigned char m_pad2A9C0[0x853BC - 0x2A9C0];
    int m_unk853BC;
    int m_unk853C0;
    int m_unk853C4;
    float m_unk853C8;
    float m_unk853CC;
    float m_unk853D0;
    int m_unk853D4;
    int m_unk853D8;
    int m_unk853DC;
    int m_unk853E0;
    int m_unk853E4;
    unsigned char m_pad853E8[0x14];
    MagSceneFocusLerp m_unk853FC;
    MagSceneFocusLerp m_unk8540C;
    MagSceneFocusLerp m_unk8541C;
};
extern "C" void func_00140B20(MagSceneFocus *, int);
extern "C" int Xiiii_memset(int, int, int) asm("memset");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfii_func_00140D40(int, int) asm("func_00140D40");
extern "C" int Xii_func_0014186C(int) asm("func_0014186C");
extern "C" int strcmp(const char *, const char *);
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140390);

extern "C" void func_0014062C(MagSceneFocus *arg0)
{
    MagSceneFocusObj *obj = arg0->m_unk29540;
    for (int i = 0; i < 4; i++, obj++) {
        for (int j = 0; j < obj->m_unk510; j++) {
            func_00237830(&obj->m_unk508[j], &obj->m_unk508[j], obj->m_unk50C[j]);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_001406B8);

// NON_MATCHING: 55/59 differ, 1 reloc differs (size 0xEC, game 0xF4), 60 edits
#ifdef NON_MATCHING
extern "C" MagSceneFocusGif *func_00140990(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9)
{
    MagSceneFocusGif *q = func_0021B4D0(arg0, 4, 0x10, 0);
    q->m_prim = ((long long)arg1 << 6) | 0x116;
    q->m_v0 = (long long)arg2 | ((long long)arg3 << 16);
    q->m_v2 = (long long)arg4 | ((long long)arg5 << 16);
    q->m_v1 = (long long)arg6 | ((long long)arg7 << 16);
    q->m_v3 = (long long)arg8 | ((long long)arg9 << 16);
    q->m_tag1 = 0x5353F0ULL;
    q->m_tag0 = 0x6400000000008001ULL;
    return q + 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140990);
#endif

extern "C" void func_00140A84(int arg0)
{
    Xiiii_memset(arg0 + 0x853BC, 0, 0x70);
    M2C_FIELD(arg0, int *, 0x853C0) = -1;
    M2C_FIELD(arg0, float *, 0x853C8) = 1.0f;
    M2C_FIELD(arg0, float *, 0x853CC) = 300.0f;
    M2C_FIELD(arg0, float *, 0x853D0) = 600.0f;
    M2C_FIELD(arg0, int *, 0x853D4) = 0;
    M2C_FIELD(arg0, int *, 0x853DC) = 0;
}

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEB10);

extern "C" void func_00140B20(MagSceneFocus *arg0, int arg1) {
    int tex = arg0->m_unk853C0;
    if (arg1 == 0) {
        if (tex != -1) {
            arg0->m_tex_info.releaseTex(tex);
            arg0->m_unk853C0 = -1;
        }
        arg0->m_unk853BC = 0;
        arg0->m_unk853D4 = 0;
        arg0->m_unk853DC = 0;
        return;
    }
    if (tex == -1) {
        MagSceneFocusTexName buf = D_002EEB10;
        int idx = arg0->m_tex_info.func_00116B5C(&buf, "efffocus");
        arg0->m_unk853C0 = idx;
        if (idx == tex) {
            ror_assert(D_002EEB40, 0x89, D_002EEB58);
        }
    }
    arg0->m_unk853BC = arg1;
}

extern "C" void func_00140C68(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0x85408) > 0) {
        M2C_FIELD(arg0, float *, 0x853C8) = Xfii_func_00140D40((int) arg0, arg0 + 0x853FC);
    }
    if (M2C_FIELD(arg0, int *, 0x85418) > 0) {
        M2C_FIELD(arg0, float *, 0x853CC) = Xfii_func_00140D40((int) arg0, arg0 + 0x8540C);
    }
    if (M2C_FIELD(arg0, int *, 0x85428) > 0) {
        M2C_FIELD(arg0, float *, 0x853D0) = Xfii_func_00140D40((int) arg0, arg0 + 0x8541C);
    }
    if (M2C_FIELD(arg0, int *, 0x853D4) != 0) {
        Xii_func_0014186C(arg0);
    }
}

extern "C" float func_00140D40(void *arg0, MagSceneFocusLerp *arg1)
{
    int count = arg1->m_unk08 + 1;
    int max = arg1->m_unk0C;
    float start = arg1->m_unk00;
    arg1->m_unk08 = count;
    float res = start + ((arg1->m_unk04 - start) * (float)count) / (float)max;
    if (count >= max) {
        arg1->m_unk0C = 0;
    }
    return res;
}

// NON_MATCHING: 4/51 differ, 6 edits
#ifdef NON_MATCHING
extern "C" float func_00140E60(int, int, int, float, float);
extern "C" void func_00140D94(MagSceneFocus *arg0, int arg1, int arg2, float fparg0, float fparg1)
{
    switch (arg1) {
    case 1:
        arg0->m_unk853CC = func_00140E60((int)arg0, (int)&arg0->m_unk8540C, arg2,
                                         (fparg0 < 0.0f) ? arg0->m_unk853CC : fparg0, fparg1);
        break;
    case 2:
        arg0->m_unk853D0 = func_00140E60((int)arg0, (int)&arg0->m_unk8541C, arg2,
                                         (fparg0 < 0.0f) ? arg0->m_unk853D0 : fparg0, fparg1);
        break;
    default:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140D94);
#endif

extern "C" float func_00140E60(int arg0, int arg1, int arg2, float fparg0, float fparg1)
{
    if (arg2 == 0) {
        M2C_FIELD(arg1, int *, 0xC) = 0;
        return fparg1;
    }
    M2C_FIELD(arg1, int *, 0xC) = arg2;
    M2C_FIELD(arg1, float *, 4) = fparg1;
    M2C_FIELD(arg1, int *, 8) = 0;
    M2C_FIELD(arg1, float *, 0) = fparg0;
    return fparg0;
}

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140E88);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00140FDC);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEB40);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEB58);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00141184);

extern "C" int func_0014159C(const char *arg0, const char *arg1)
{
    int len = strlen(arg1);
    int n = strlen(arg0) - len;
    for (int i = 0; i <= n; i++) {
        if (strncmp(arg0 + i, arg1, len) == 0) {
            return i;
        }
    }
    return -1;
}

extern "C" int func_00141634(const char *arg0, const char *arg1, char *arg2)
{
    int out = 0;
    int i = 0;
    int count = 0;
    int len0 = strlen(arg0);
    int len1 = strlen(arg1);
    register int start PS2_REG("$5") = 0; // pin global-alloc register to match game's $a1/$a2/$a0 split

    if (len0 > 0) {
        do {
            register int j PS2_REG("$6");
            for (j = 0; j < len1; j++) {
                if (arg0[i] == arg1[j]) {
                    break;
                }
            }
            if (j != len1) {
                int n = i - start;
                if (n > 0) {
                    memcpy(&arg2[out], &arg0[start], n);
                    out += n;
                    arg2[out++] = 0;
                    count++;
                }
                start = i + 1;
            }
            i++;
        } while (i < len0);
    }

    int n = i - start;
    if (n > 0) {
        memcpy(&arg2[out], &arg0[start], n);
        out += n;
        arg2[out] = 0;
        count++;
    }
    return count;
}

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEB90);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEBA0);

// NON_MATCHING: fn matches; D_002EEBD0 needs .align 3 in config/rodata_align_manual.tsv
#ifdef NON_MATCHING
extern "C" int func_00141770(const char *arg0)
{
    if (strcmp(arg0, "far1far2") == 0) {
        return 3;
    }
    if (strcmp(arg0, "far1") == 0) {
        return 1;
    }
    return (strcmp(arg0, "far2") == 0) ? 2 : 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_00141770);
#endif

extern "C" void func_001417E4(MagSceneFocus *arg0, int arg1, int arg2)
{
    if (arg1 != 0) {
        func_00140B20(arg0, 3);
        arg0->m_unk853D4 = arg1;
        arg0->m_unk853D8 = arg2;
        arg0->m_unk853DC = 0;
        arg0->m_unk853E0 = -1;
        arg0->m_unk853E4 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_0014186C);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenefocus", D_002EEBD0);

INCLUDE_ASM("asm/nonmatchings/mag/magscenefocus", func_001419D8);
