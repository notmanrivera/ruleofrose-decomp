#include "include_asm.h"
struct TskVec4;
extern "C" float sqrtf(float);
extern "C" int X_func_001F59B4_ee7f0(unsigned int, int, int, int, int, float, float) asm("func_001F59B4");
extern "C" float Xf_func_001333E4_ee7f0(int, int, int) asm("func_001333E4");
extern "C" int X_func_00118E6C__9MagSystemiffR9DogVectorPfP9DogVector(
    void *, int, float, float, TskVec4 *, float *, TskVec4 *) asm("func_00118E6C__9MagSystemiffR9DogVectorPfP9DogVector");
extern "C" int Xiii_func_00143D7C(int, float *, int) asm("func_00143D7C");
extern int D_006FE6A0;
extern "C" int Xiiu_func_001CBE38(void *, unsigned int) asm("func_001CBE38");
extern "C" int X_func_001311F4_loc(int, int *) asm("func_001311F4");
extern "C" int Xiiiii_func_001311BC_loc(int, int, int, int) asm("func_001311BC");
struct DogVtblEntry {
    short delta;
    short unk2;
    void (*fn)(void *, float *, int);
};
extern "C" int Xipu_func_001CBDB8(void *, unsigned int) asm("func_001CBDB8");
extern "C" void X_ror_assert(const char *, int, const char *) asm("ror_assert");
extern "C" int Xiii_func_0022B3D8(int, int) asm("func_0022B3D8");
extern const char D_002FE698[];
extern const char D_002FE6A8[];
extern const char D_002FE6B8[];
extern "C" int Xiiu_func_001D2BA8(int, unsigned int) asm("func_001D2BA8");
extern int D_002FDFB0;
extern "C" float Xfi_func_001E9CB4(int) asm("func_001E9CB4");
extern "C" int Xiiff_func_001F0F9C(int, float, float) asm("func_001F0F9C");
extern "C" int Xiifff_func_001F11A0(int, float, float, float) asm("func_001F11A0");
extern "C" int Xiii_func_001D8964(int, int) asm("func_001D8964");
struct DogActorStub {
    char pad0[0x40];
    float unk40[3];
    char pad4C[4];
    float unk50[3];
    char pad5C[0x4D0 - 0x5C];
};
struct DogManStub {
    char pad0[0x2920];
    struct DogActorStub actors[1];
};
static inline struct DogActorStub *getDogActor(void *base, int idx)
{
    return (struct DogActorStub *)(((char *)base + idx * 0x4D0) + 0x2920);
}
struct TskMovePointPathObj {
    char pad0[4];
    int m_unk04;
    int m_unk08;
    char pad0C[0x14];
    int m_unk20;
    char pad24[0xC];
    int m_unk30;
    char pad34[0xC];
    float m_unk40[4];
    char pad50[0x10];
    float m_unk60[4];
    int (TskMovePointPathObj::*m_func)();
    char pad78[0x8];
    float m_unk80;
};
extern "C" int Xiii_func_001D8ADC_mpp(int, int) asm("func_001D8ADC");
extern "C" void Xv_func_001EC834_mpp(TskMovePointPathObj *) asm("func_001EC834");
extern "C" void Xv_func_001F59B4_mpp(int, int, int, int, int, float, float) asm("func_001F59B4");
extern "C" int X_func_001E71FC(int, int, int, int, int, int, int, int, int) asm("func_001E71FC");
extern "C" int Xii___builtin_new(int) asm("__builtin_new");
extern "C" int Xiii_func_001E7724(int, int) asm("func_001E7724");
extern "C" int Xiii_func_001E7D7C_2(int, int) asm("func_001E7D7C");
extern "C" int Xfunc_001F0434(int, unsigned int, int, int, float, float, float, int, int) asm("func_001F0434");
extern "C" void Xv_func_001CFE78(int, unsigned int, int) asm("func_001CFE78");
extern "C" int Xiu_func_001EE7F0(unsigned int, unsigned short, int, float, float, int, float) asm("func_001EE7F0");
extern "C" void Xv_setActorRot__9MagSystemiPCf(int, int, int) asm("setActorRot__9MagSystemiPCf");
extern "C" void Xv_func_001E6734(int, int, int, int, int, int) asm("func_001E6734");
extern "C" void Xv_func_0017F5E8(int, int) asm("func_0017F5E8");
extern "C" void Xv_strncpy(char *, const char *, int) asm("strncpy");
extern "C" void Xv_func_00191E58(int, int, int) asm("func_00191E58");
extern "C" void Xv_func_00192834(int, char *) asm("func_00192834");
extern "C" void Xv_func_001F0E90(unsigned int, float, int) asm("func_001F0E90");
extern "C" int Xiff_func_001F6B8C(float, float) asm("func_001F6B8C");
extern "C" void Xv_func_001F1298(int, float, int, float) asm("func_001F1298");
struct GamHitInfo {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    GamHitInfo() { unk10 = 0; }
};
extern "C" void Xvp_func_001D890C(int, int) asm("func_001D890C");
extern "C" int Xiii_func_001D8B5C(int, int) asm("func_001D8B5C");
extern "C" void Xvp_func_001D89C4(int, int) asm("func_001D89C4");
extern "C" float Xff_cosf(float) asm("cosf");
extern "C" float Xff_sinf(float) asm("sinf");
extern "C" float Xfpff_func_002180E4(float *, float, float) asm("func_002180E4");
struct TskMoveSectaFindPathObj {
    char pad0[0x20C];
    int m_unk20C;
    char pad210[0x8];
    int m_unk218;
    int m_unk21C;
    char pad220[0x70];
    int *m_unk290;
    char pad294[0x24];
    int (TskMoveSectaFindPathObj::*m_func)();
};
extern "C" int X_func_001ED1D0(TskMoveSectaFindPathObj *) asm("func_001ED1D0");
struct TskVec4 {
    float f[4];
} __attribute__((aligned(16)));
struct TskHitCheck {
    void *m_origin_pos;
    int m_rotate;
    float m_angle;
    void *m_target_pos;
    float m_scale;
};
extern "C" void Xv_func_001D05F4(void *, unsigned int, TskVec4 *) asm("func_001D05F4");
extern "C" void Xv_func_001D06B8(void *, unsigned int, TskVec4 *) asm("func_001D06B8");
extern "C" float Xf_func_001D4A3C(void *, unsigned int, int) asm("func_001D4A3C");
extern "C" int Xi_func_0010456C(TskHitCheck *) asm("func_0010456C");
extern "C" float Xfi_func_001EA5EC(int) asm("func_001EA5EC");
extern "C" int Xiif_func_001EAFB0(int, float) asm("func_001EAFB0");
extern "C" int Xiu_func_001F61EC(unsigned int) asm("func_001F61EC");
extern "C" void Xv_TskMsgMan__vfunc_05(int) asm("TskMsgMan__vfunc_05");
extern "C" void Xvii_func_00183B24(int, int) asm("func_00183B24");
extern int _vt$9TskMsgMan;
struct TskAvoidMoveObj {
    char pad0[0xC];
    unsigned int m_unk0C;
    char pad10[0x6C];
    int (TskAvoidMoveObj::*m_func)();
};
struct TskMoveTypeGenObj {
    char pad0[0x60];
    int m_unk60;
    char pad64[0x18];
    void (TskMoveTypeGenObj::*m_func)();
};
extern "C" void Xv_func_001EAF00(void *) asm("func_001EAF00");
extern "C" void Xv_func_0025B878(...) asm("func_0025B878");
extern "C" void Xvii_func_001D8B9C(int, int) asm("func_001D8B9C");
extern "C" int Xii_func_00187464(int) asm("func_00187464");
extern "C" int Xiiu_func_001348B0(int, unsigned int) asm("func_001348B0");
extern "C" int Xiiu_func_00135594(int, unsigned int) asm("func_00135594");
extern "C" int Xiiui_func_001351B0(int, unsigned int, int) asm("func_001351B0");
extern int D_002FE590;
extern "C" int Xi_rand() asm("rand");
struct MagGameFlags2 {
    int m_unk00;
    int m_flags;
};
extern MagGameFlags2 *D_007B2060;
extern "C" int Xii_func_00192920(int) asm("func_00192920");
extern "C" int Xii_func_001CF95C(int) asm("func_001CF95C");
extern int _9MagSystem$m_v_rate;
extern int _vt$8TskMovie;
extern "C" void TskMovie__vfunc_05();
extern "C" int Xii_func_001A06D4(int, int) asm("func_001A06D4");
extern "C" int Xii_func_001A0BA0(int) asm("func_001A0BA0");
extern int D_007B205C;
extern int _9MagSystem$m_current_system;
extern "C" int Xiiu_func_001D19A8(int, unsigned int) asm("func_001D19A8");
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern int _vt$10TskSysFunc;
extern int _vt$9TskRotAdj;
extern int _vt$16TskMoveTypeRound;
extern int _vt$14TskMoveTypeGen;
extern int _vt$12TskMoveSecta;
extern int _vt$20TskMoveSectaFindPath;
extern int _vt$16TskMovePointPath;
extern int _vt$13TskMovePhysic;
extern int _vt$10TskMoveAdj;
extern int _vt$12TskFrameFunc;
extern int _vt$9TskChrRot;
extern int _vt$12TskAvoidMove;
extern "C" void Xv___builtin_delete(int) asm("__builtin_delete");
extern int _vt$9TskAttach;
struct m2c_block8 { int w[2]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiiu_func_001D2B8C(int, unsigned int) asm("func_001D2B8C");
extern int D_002FE588;
extern int D_002FE5E0;
extern int D_002FE5E8;
extern int _vt$11TskSeqEvent;
extern int _vt$15TskGenFrameFunc;
extern "C" float Xfi_func_0010A650__8DogActor(int) asm("func_0010A650__8DogActor");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001C5D08(int, int) asm("func_001C5D08");
extern "C" int Xiii_func_001CB57C(int, int) asm("func_001CB57C");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiiiii_getActorNodeMatrix__9MagSystemiP19tag_I3dMatrixF4x4_sPCc(int, int, int, int) asm("getActorNodeMatrix__9MagSystemiP19tag_I3dMatrixF4x4_sPCc");
extern "C" int Xiiiiiii_func_0013F980__8MagSceneiiiPfi(int, int, int, int, int, int) asm("func_0013F980__8MagSceneiiiPfi");
extern "C" int Xiiiiiii_func_001CD044(int, int, int, int, int, int) asm("func_001CD044");
extern "C" int Xiiu_func_001D046C(int, unsigned int) asm("func_001D046C");
extern "C" int Xiiui_func_00213D00(int, unsigned int, int) asm("func_00213D00");
extern "C" int Xiiuiii_func_00211BE4(int, unsigned int, int, int, int) asm("func_00211BE4");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00131184(...) asm("func_00131184");
extern "C" int X_func_001348B0(...) asm("func_001348B0");
extern "C" int X_func_001351B0(...) asm("func_001351B0");
extern "C" int X_func_00135594(...) asm("func_00135594");
extern "C" int X_func_0017F8FC(...) asm("func_0017F8FC");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001913C4(...) asm("func_001913C4");
extern "C" int X_func_0019143C(...) asm("func_0019143C");
extern "C" int X_func_00191478(...) asm("func_00191478");
extern "C" int X_func_00191F44(...) asm("func_00191F44");
extern "C" int X_func_00191F98(...) asm("func_00191F98");
extern "C" int X_func_001A0684(...) asm("func_001A0684");
extern "C" int X_func_001A074C(...) asm("func_001A074C");
extern "C" int X_func_001C5D08(...) asm("func_001C5D08");
extern "C" int X_func_001C65E8(...) asm("func_001C65E8");
extern "C" int X_func_001C6A40(...) asm("func_001C6A40");
extern "C" int X_func_001CD044(...) asm("func_001CD044");
extern "C" int X_func_001CF9D4(...) asm("func_001CF9D4");
extern "C" int X_func_001CFA5C(...) asm("func_001CFA5C");
extern "C" int X_func_001D046C(...) asm("func_001D046C");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001E7724(...) asm("func_001E7724");
extern "C" int X_func_001E7D7C(...) asm("func_001E7D7C");
extern "C" int X_func_001EA5EC(...) asm("func_001EA5EC");
extern "C" int X_func_001EAFB0(...) asm("func_001EAFB0");
extern "C" int X_func_001F61EC(...) asm("func_001F61EC");
extern "C" int X_func_00211BE4(...) asm("func_00211BE4");
extern "C" int X_func_00213D00(...) asm("func_00213D00");
extern "C" int X_rand(...) asm("rand");
extern int D_006E9840;
extern int D_006FBD80;
extern int D_0073E91C;
extern int D_007812C0;
extern int D_007A3D80;
extern int D_007A4440;
extern int D_007B2580;

extern "C" int func_001E9A34()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001E9A3C);

extern "C" void TskMoveTypeGen__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$14TskMoveTypeGen;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveTypeGen__vfunc_05(void) {
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDA88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDA98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDAC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDAC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDAD0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001E9CB4);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EA5EC);

extern "C" int func_001EAA38(int arg0)
{
    if (Xiii_func_001E7D7C_2((int)&D_007A3D80, M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x3D8)) != 0 ||
        M2C_FIELD(arg0, int *, 0x60) == 1) {
        Xiii_func_001D8964(M2C_FIELD(arg0, int *, 4), arg0 + 0x40);
        M2C_FIELD(arg0, int *, 0x60) = 2;
        return 0;
    }
    M2C_FIELD(arg0, int *, 0x84) = 0;
    {
        struct DogActorStub *d = getDogActor(&D_006FBD80, M2C_FIELD(arg0, int *, 0xC));
        float *p30 = (float *)(arg0 + 0x30);
        p30[0] = d->unk40[0];
        p30[1] = d->unk40[1];
        p30[2] = d->unk40[2];
    }
    {
        struct DogActorStub *d = getDogActor(&D_006FBD80, M2C_FIELD(arg0, int *, 0xC));
        float *p40 = (float *)(arg0 + 0x40);
        p40[0] = d->unk50[0];
        p40[1] = d->unk50[1];
        p40[2] = d->unk50[2];
    }
    M2C_FIELD(arg0, float *, 0x44) = Xfi_func_0010A650__8DogActor((int)getDogActor(&D_006FBD80, M2C_FIELD(arg0, int *, 0xC)));
    float f = Xfi_func_001E9CB4(arg0);
    if (M2C_FIELD(arg0, int *, 0x1C) < 8) {
        Xiiff_func_001F0F9C(M2C_FIELD(arg0, int *, 8), f, M2C_FIELD(arg0, float *, 0x78));
    } else {
        Xiifff_func_001F11A0(M2C_FIELD(arg0, int *, 8), M2C_FIELD(arg0, float *, 0x44), f, M2C_FIELD(arg0, float *, 0x78));
    }
    return 0;
}

// NON_MATCHING: 33/55 differ, 5 relocs differ (size 0xDC, game 0xE4), 16 edits
#ifdef NON_MATCHING
extern "C" int X_func_00260110(const char *, ...) asm("func_00260110");
extern "C" int Xii_func_001EAF00(int) asm("func_001EAF00");
extern "C" int Xiii_func_001D8ADC(int, int) asm("func_001D8ADC");
extern "C" int Xiiuii_func_001D544C(int, unsigned int, int, int) asm("func_001D544C");
extern const char D_002FDBF0[];
extern "C" int func_001EAB54(int arg0)
{
    int out[8];
    int temp_s1;

    temp_s1 = arg0 + 0x30;
    if ((M2C_FIELD(arg0, int *, 0xA8) & 1) != 0) {
        if (X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x3D8)) != 0) {
            return 0;
        }
    }
    if (Xiiuii_func_001D544C((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 8), (int)out, 0) != 0) {
        *(u_long128 *)temp_s1 = *(u_long128 *)(arg0 + 0x90);
        X_func_00260110(D_002FDBF0, out[4]);
        return 0;
    }
    Xv_func_0025B878(temp_s1, temp_s1, arg0 + 0x50);
    if (Xiii_func_001D8ADC(M2C_FIELD(arg0, int *, 4), temp_s1) != 0) {
        M2C_FIELD(arg0, int *, 0x60)--;
        *(u_long128 *)(arg0 + 0x90) = *(u_long128 *)temp_s1;
        return 0;
    }
    return Xii_func_001EAF00(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EAB54);
#endif

// NON_MATCHING: 4/32 differ, 4 edits
#ifdef NON_MATCHING
extern "C" int X_func_0025B878(...) asm("func_0025B878");
extern "C" int Xiii_func_001D8B9C(int, int) asm("func_001D8B9C");
extern "C" int Xiii_func_001E7D7C(int, int) asm("func_001E7D7C");
extern "C" int func_001EAC38(int arg0)
{
    int temp_s1;

    int ret;

    temp_s1 = arg0 + 0x30;
    if ((M2C_FIELD(arg0, int *, 0xA8) & 1) != 0 && Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x3D8)) != 0) {
        ret = 0;
    } else {
        X_func_0025B878(temp_s1, temp_s1, arg0 + 0x50);
        Xiii_func_001D8B9C(M2C_FIELD(arg0, int *, 4), temp_s1);
        M2C_FIELD(arg0, int *, 0x60)--;
        ret = 0;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EAC38);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EACB8);

extern "C" void TskMoveTypeGen__vfunc_04(TskMoveTypeGenObj *arg0)
{
    if (arg0->m_unk60 > 0) {
        (arg0->*(arg0->m_func))();
    } else {
        return Xv_func_001EAF00(arg0);
    }
}

extern "C" int func_001EAF00(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x1C);
    if (temp_v1 < 3) {
        goto fail;
    }
    if (temp_v1 >= 5) {
        if (temp_v1 >= 0xD) {
            goto fail;
        }
        if (temp_v1 < 0xB) {
            goto fail;
        }
    }
    if ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0xC) >= 0x201U) {
        M2C_FIELD(arg0, unsigned int *, 0xC) = (unsigned int) M2C_FIELD(M2C_FIELD(arg0, int *, 4), unsigned int *, 0x108);
    }
    Xiif_func_001EAFB0(arg0, Xfi_func_001EA5EC(arg0));
    temp_v0 = M2C_FIELD(arg0, int *, 0x68);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, int *, 0x60) = temp_v0;
    }
    if (M2C_FIELD(arg0, int *, 0x60) == 0) {
        M2C_FIELD(arg0, int *, 0x50) = 0;
        M2C_FIELD(arg0, int *, 0x54) = 0;
        M2C_FIELD(arg0, int *, 0x58) = 0;
    }
    return 0;

fail:
    Xiu_func_001F61EC(M2C_FIELD(arg0, unsigned int *, 8));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EAFB0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EB63C);

extern "C" void TskMoveTypeRound__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$16TskMoveTypeRound;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveTypeRound__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMoveTypeRound__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EBB80);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EBDE8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EC0E4);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB48);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB50);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB58);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB78);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDB98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBB8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBD0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBD8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBE8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDBF0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC48);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC50);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC58);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC78);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDC98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCB8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCD0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCD8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCE8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCF0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDCF8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD48);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD50);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD58);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD78);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EC344);

extern "C" void TskMovePointPath__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$16TskMovePointPath;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMovePointPath__vfunc_05(void) {
}

extern "C" int TskMovePointPath__vfunc_04(TskMovePointPathObj *arg0)
{
    if (arg0->m_unk20 > 0) {
        if (arg0->m_unk30 < 4) {
            Xv_func_0025B878(arg0->m_unk40, arg0->m_unk40, arg0->m_unk60);
        } else {
            Xvp_func_001D890C(arg0->m_unk04, (int)arg0->m_unk40);
        }
        if (Xiii_func_001D8ADC_mpp(arg0->m_unk04, (int)arg0->m_unk40) != 0) {
            arg0->m_unk20--;
        }
        return 0;
    }
    if ((arg0->*(arg0->m_func))() != 0) {
        Xv_func_001F59B4_mpp(arg0->m_unk08, 1, -1, 0x100, 0, arg0->m_unk80, 32769.0f);
        return 1;
    }
    Xv_func_001EC834_mpp(arg0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EC6E8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EC72C);

extern "C" int func_001EC774(int arg0)
{
    int old = M2C_FIELD(arg0, int *, 0x1C)++;

    if (old < M2C_FIELD(arg0, int *, 0x18)) {
        M2C_FIELD(arg0, int *, 0x10) = (int) (M2C_FIELD(arg0, int *, 0xC) + ((Xi_rand() % (int) M2C_FIELD(arg0, int *, 0x18)) * 8));
        return 0;
    }
    return 1;
}

extern "C" int func_001EC7E8(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x10)) = (int) ((*(int *)(int *)((char *)(arg0) + 0xC)) + ((X_rand() % (int) (*(int *)(int *)((char *)(arg0) + 0x18))) * 8));
    return 0;
}


extern "C" void func_001EC834(int arg0)
{
    float dist;
    float angle;
    float *p;
    int pos = arg0 + 0x40;

    Xv_func_001D05F4(&D_007812C0, M2C_FIELD(arg0, unsigned int *, 8), (TskVec4 *)pos);
    p = M2C_FIELD(arg0, float **, 0x10);
    angle = Xfpff_func_002180E4(&dist, p[0] - *(float *)pos, p[1] - M2C_FIELD(arg0, float *, 0x48));
    if (M2C_FIELD(arg0, int *, 0x30) < 4) {
        float s = Xff_sinf(angle);
        M2C_FIELD(arg0, int *, 0x64) = 0;
        M2C_FIELD(arg0, float *, 0x60) = s * M2C_FIELD(arg0, float *, 0x2C);
        float c = Xff_cosf(angle) * M2C_FIELD(arg0, float *, 0x2C);
        int steps = (int)(dist / M2C_FIELD(arg0, float *, 0x2C));
        M2C_FIELD(arg0, float *, 0x54) = angle;
        M2C_FIELD(arg0, float *, 0x68) = c;
        M2C_FIELD(arg0, int *, 0x20) = steps;
        Xv_func_001CFE78((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 8), arg0 + 0x50);
    } else {
        M2C_FIELD(arg0, int *, 0x20) = Xiu_func_001EE7F0(
            M2C_FIELD(arg0, unsigned int *, 8),
            M2C_FIELD(arg0, unsigned short *, 0x14),
            arg0 + 0x78,
            angle,
            dist,
            M2C_FIELD(arg0, int *, 0x7C),
            M2C_FIELD(arg0, float *, 0x80));
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EC940);

extern "C" void TskMoveSectaFindPath__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$20TskMoveSectaFindPath;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveSectaFindPath__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ECBE0);

// NON_MATCHING: 2/58 differ, 1 reloc differs, 4 edits
#ifdef NON_MATCHING
extern "C" int X_func_00260110(const char *fmt, ...) asm("func_00260110");
extern "C" int Xiii_func_001D8ADC(int a, int b) asm("func_001D8ADC");
extern "C" int Xiiuii_func_001D544C(int a, unsigned int b, int c, int d) asm("func_001D544C");
extern "C" int func_001ECDD4(int arg0)
{
    extern const char D_002FDBF0[];
    int out[8];
    int temp_s1;

    temp_s1 = arg0 + 0x250;
    if ((M2C_FIELD(arg0, int *, 0x2A8) & 1) != 0) {
        if (X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x3D8)) != 0) {
            return 0;
        }
    }
    if (Xiiuii_func_001D544C((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 8), (int)out, 0) != 0) {
        u_long128 *p1 = (u_long128 *)(arg0 + 0x280);
        asm volatile("" : "+r"(p1));
        register u_long128 tmp1 asm("$6") = *p1;
        asm volatile("" : "+r"(tmp1));
        *(u_long128 *)temp_s1 = tmp1;
        X_func_00260110(D_002FDBF0, out[4]);
        return 0;
    }
    Xv_func_0025B878(temp_s1, temp_s1, arg0 + 0x270);
    if (Xiii_func_001D8ADC(M2C_FIELD(arg0, int *, 4), temp_s1) != 0) {
        register u_long128 *p2 asm("$3") = (u_long128 *)(arg0 + 0x280);
        asm volatile("" : "+r"(p2));
        M2C_FIELD(arg0, int *, 0x21C)--;
        register u_long128 tmp2 asm("$6") = *(u_long128 *)temp_s1;
        asm volatile("" : "+r"(tmp2));
        *p2 = tmp2;
        asm volatile("" ::: "memory");
        return 0;
    }
    X_func_001ED1D0((TskMoveSectaFindPathObj *)arg0);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ECDD4);
#endif

extern "C" int func_001ECEBC(int arg0)
{
    int temp_s1;

    temp_s1 = arg0 + 0x250;
    if ((M2C_FIELD(arg0, int *, 0x2A8) & 1) != 0) {
        if (X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x3D8)) != 0) {
            return 0;
        }
    }
    Xv_func_0025B878(temp_s1, temp_s1, arg0 + 0x270);
    Xvii_func_001D8B9C(M2C_FIELD(arg0, int *, 4), temp_s1);
    M2C_FIELD(arg0, int *, 0x21C) = M2C_FIELD(arg0, int *, 0x21C) - 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ECF3C);

extern "C" int TskMoveSectaFindPath__vfunc_04(TskMoveSectaFindPathObj *arg0)
{
    if (arg0->m_unk21C > 0) {
        return (arg0->*(arg0->m_func))();
    }
    if (arg0->m_unk218++ >= arg0->m_unk20C - 1) {
        if (arg0->m_unk290 != 0) {
            *arg0->m_unk290 |= 2;
        }
        return 1;
    }
    X_func_001ED1D0(arg0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ED1D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDB8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDD0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDD8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDE8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDF0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDDF8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE48);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE50);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDE58);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ED998);

extern "C" void TskMoveSecta__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$12TskMoveSecta;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveSecta__vfunc_05(int arg0)
{
    if (X_func_001E7D7C((int)&D_007A3D80, *(int *)(*(int *)(int *)((char *)(arg0) + 0x10))) != 0) {
        X_func_001E7724((int)&D_007A3D80, *(int *)(*(int *)(int *)((char *)(arg0) + 0x10)));
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMoveSecta__vfunc_04);

extern "C" u_long128 *func_001EE2FC(int arg0, int arg1, int arg2, int arg3, u_long128 *arg4, int arg5, float fparg0)
{
    register u_long128 *p asm("$2");
    register int vt asm("$2") = (int)&_vt$10TskMoveAdj;

    M2C_FIELD(arg0, int *, 0x20) = arg1;
    M2C_FIELD(arg0, int *, 0) = vt;
    M2C_FIELD(arg0, int *, 0x30) = arg3;
    M2C_FIELD(arg0, int *, 0x28) = arg2 + 0x10;
    M2C_FIELD(arg0, float *, 0x24) = fparg0;
    M2C_FIELD(arg0, int *, 0x34) = arg5;
    p = (u_long128 *)((char *)arg0 + 0x10);
    register u_long128 tmp asm("$6") = *arg4;
    *p = tmp;
    return p;
}

extern "C" void TskMoveAdj__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$10TskMoveAdj;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveAdj__vfunc_05(void) {
}

// NON_MATCHING: 21/79 differ, 1 reloc differs, 10 edits
#ifdef NON_MATCHING
static inline char *getDogBase(void *base, int idx)
{
    return (char *)base + idx * 0x4D0;
}

extern "C" int TskMoveAdj__vfunc_04(int arg0)
{
    float sp[4];
    float *p10 = (float *)(arg0 + 0x10);
    int steps = M2C_FIELD(arg0, int *, 0x30);
    if (steps >= 0) {
        int val = M2C_FIELD(getDogBase(&D_006FBD80, M2C_FIELD(arg0, int *, 0x20)), int *, 0x2AF8);
        M2C_FIELD(arg0, int *, 0x2C) = val;
        float h = M2C_FIELD(M2C_FIELD(arg0, float **, 0x28), float *, 8);
        sp[0] = 0.0f;
        sp[2] = 0.0f;
        sp[1] = h * ((float)steps / (float)val) - 7.5f;
        Xv_func_0025B878(sp, sp, p10);
        struct DogActorStub *d = getDogActor(&D_006FBD80, M2C_FIELD(arg0, int *, 0x20));
        d->unk40[0] = sp[0];
        d->unk40[1] = sp[1];
        d->unk40[2] = sp[2];
        M2C_FIELD(d, int *, 0x90) = 1;
        M2C_FIELD(arg0, int *, 0x30)--;
        return 0;
    }
    Xv_func_0025B878(sp, sp, p10);
    struct DogActorStub *d = getDogActor(&D_006FBD80, M2C_FIELD(arg0, int *, 0x20));
    d->unk40[0] = p10[0];
    d->unk40[1] = p10[1];
    d->unk40[2] = p10[2];
    M2C_FIELD(d, int *, 0x90) = 1;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMoveAdj__vfunc_04);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EE4A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDED0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDED8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEE8);

extern "C" void TskRotAdj__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$9TskRotAdj;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskRotAdj__vfunc_05(void) {
}

extern "C" int TskRotAdj__vfunc_04(int arg0)
{
    float var_f20;

    if (M2C_FIELD(arg0, int *, 0x10)-- >= 0) {
        M2C_FIELD(arg0, float *, 0x24) += M2C_FIELD(arg0, float *, 0xC);
        var_f20 = M2C_FIELD(arg0, float *, 0x24);
        if (var_f20 < -3.14159265358979323846) {
            var_f20 += 2.0 * 3.14159265358979323846;
        }
        if (var_f20 > 3.14159265358979323846) {
            var_f20 -= 2.0 * 3.14159265358979323846;
        }
        M2C_FIELD(arg0, float *, 0x24) = var_f20;
        Xv_setActorRot__9MagSystemiPCf((int)&D_006E9840, M2C_FIELD(arg0, int *, 4), arg0 + 0x20);
        return 0;
    }
    return 1;
}

extern "C" int func_001EE7F0(unsigned int arg0, unsigned short arg1, int *arg2, float f0, float f1, int arg3, float f2)
{
    TskVec4 vec;
    float time;
    float dist;
    float speed;
    float ratio;
    char *sys;

    if (*arg2 == 0) {
        *arg2 = X_func_001F59B4_ee7f0(arg0, arg3, -1, 0x100, 0, f2, f0);
    }
    sys = (char *)&D_006E9840;
    time = Xf_func_001333E4_ee7f0((int)(sys + 0x12540), arg1, arg3);
    X_func_00118E6C__9MagSystemiffR9DogVectorPfP9DogVector(sys, arg1, 0.0f, time * 50.0f, &vec, &f0, 0);
    dist = sqrtf(vec.f[0] * vec.f[0] + vec.f[2] * vec.f[2]);
    speed = dist * (f2 / 0.016666666f);
    if (speed <= 0.0f) {
        ratio = 0.0f;
    } else {
        ratio = f1 / speed;
    }
    return (int)(ratio * time * 25.0f);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EE954);

extern "C" void func_001EEAEC(int arg0, unsigned int arg1)
{
    int kind = (arg1 >> 28) & 3;
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$13TskMovePhysic;
    M2C_FIELD(arg0, unsigned int *, 0xC) = arg1;
    M2C_FIELD(arg0, int *, 0x58) = 0;
    switch (kind) {
    case 1:
        break;
    case 2:
        M2C_FIELD(arg0, int *, 8) = Xiiu_func_001D2BA8((int)&D_007812C0, arg1);
        *(m2c_block8 *)((char *)arg0 + 0x70) = *(m2c_block8 *)&D_002FDFB0;
        M2C_FIELD(arg0, int *, 0x10) = M2C_FIELD(M2C_FIELD(arg0, int *, 8), int *, 0x108);
        break;
    }
    {
        struct DogActorStub *d = getDogActor(&D_006FBD80, M2C_FIELD(arg0, int *, 0x10));
        float *p20 = (float *)(arg0 + 0x20);
        p20[0] = d->unk40[0];
        p20[1] = d->unk40[1];
        p20[2] = d->unk40[2];
    }
    {
        struct DogActorStub *d = getDogActor(&D_006FBD80, M2C_FIELD(arg0, int *, 0x10));
        float *p30 = (float *)(arg0 + 0x30);
        p30[0] = d->unk50[0];
        p30[1] = d->unk50[1];
        p30[2] = d->unk50[2];
    }
    float s = Xff_sinf(M2C_FIELD(arg0, float *, 0x34));
    M2C_FIELD(arg0, float *, 0x44) = 1.0f;
    M2C_FIELD(arg0, float *, 0x40) = s;
    M2C_FIELD(arg0, float *, 0x48) = Xff_cosf(M2C_FIELD(arg0, float *, 0x34));
    M2C_FIELD(arg0, int *, 0x5C) |= 1;
}

extern "C" void TskMovePhysic__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$13TskMovePhysic;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMovePhysic__vfunc_05(void) {
}

extern "C" int func_001EEC44()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EEC4C);

extern "C" float func_001EF0D8(float fparg0)
{
    return (fparg0 * 16.0f) - (fparg0 * 29.3999981880188f * fparg0);
}

extern "C" float func_001EF100(float fparg0)
{
    return 24.0f - (fparg0 * 16.0f);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMovePhysic__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EF184);

extern "C" void TskAvoidMove__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$12TskAvoidMove;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskAvoidMove__vfunc_05(int arg0)
{
    int temp_a0;

    if (Xiiu_func_001D046C((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0xC)) != 0) {
        temp_a0 = M2C_FIELD(arg0, int *, 4);
        if (temp_a0 != 0) {
            M2C_FIELD(temp_a0, int *, 0x120) = (int) (M2C_FIELD(temp_a0, int *, 0x120) & ~0x4000);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EF498);

// NON_MATCHING: 78/82 differ, 8 relocs differ (size 0x148, game 0x144), 44 edits
#ifdef NON_MATCHING
extern "C" int Xiiiiii_func_001D5A0C(void *, void *, unsigned int, int, int, void *) asm("func_001D5A0C");
extern "C" void Xviii_func_0025B878(void *, void *, void *) asm("func_0025B878");
extern "C" int Xiuii_func_001F5558(unsigned int, int, int) asm("func_001F5558");
extern const char D_002FDFE0[];
extern "C" int func_001EF888(int arg0)
{
    u_long128 sp0;
    u_long128 sp10;
    struct {
        int a[4];
        int sp30;
    } sp20;
    int temp_s3;
    u_long128 *p10;

    temp_s3 = arg0 + 0x20;
    sp20.sp30 = 0;
    Xvp_func_001D890C(M2C_FIELD(arg0, int *, 4), temp_s3);
    p10 = &sp10;
    if (Xiuii_func_001F5558(M2C_FIELD(arg0, unsigned int *, 0xC), (int)p10, (int)D_002FDFE0) == 0) {
        *p10 = M2C_FIELD(arg0, u_long128 *, 0x20);
    }
    Xviii_func_0025B878(&sp0, p10, (void *)(arg0 + 0x30));
    if (Xiiiiii_func_001D5A0C(&D_007812C0, &sp0, M2C_FIELD(arg0, unsigned int *, 0xC), 0, 0, &sp20) == 0) {
        return 1;
    }
    Xviii_func_0025B878(&sp0, (void *)temp_s3, (void *)(arg0 + 0x30));
    Xvp_func_001D89C4(M2C_FIELD(arg0, int *, 4), (int)&sp0);
    M2C_FIELD(arg0, int *, 0x64) = 0;
    if (M2C_FIELD(arg0, int *, 0x60)++ > M2C_FIELD(arg0, int *, 0x50)) {
        if (Xiiiiii_func_001D5A0C(&D_007812C0, &sp0, M2C_FIELD(arg0, unsigned int *, 0xC), 0, 0, &sp20) == 0) {
            return 1;
        }
    }
    return M2C_FIELD(arg0, int *, 0x70)++ > M2C_FIELD(arg0, int *, 0x68);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EF888);
#endif

extern "C" int func_001EF9CC(int arg0)
{
    TskVec4 pos;
    GamHitInfo info;
    int temp_s0;

    temp_s0 = arg0 + 0x20;
    Xvp_func_001D890C(M2C_FIELD(arg0, int *, 4), temp_s0);
    Xv_func_0025B878(&pos, temp_s0, arg0 + 0x30);
    if (Xiii_func_001D8B5C(M2C_FIELD(arg0, int *, 4), (int)&pos) != 0) {
        Xvp_func_001D89C4(M2C_FIELD(arg0, int *, 4), (int)&pos);
        if (M2C_FIELD(arg0, int *, 0x64)++ >= 9) {
            return 1;
        }
    } else {
        M2C_FIELD(arg0, int *, 0x64) = 0;
    }
    if (M2C_FIELD(arg0, int *, 0x70)++ > M2C_FIELD(arg0, int *, 0x68)) {
        M2C_FIELD(arg0, float *, 0x30) *= 1.25f;
        M2C_FIELD(arg0, float *, 0x38) *= 1.25f;
        M2C_FIELD(arg0, int *, 0x70) = 0;
    }
    return 0;
}

extern "C" int func_001EFAA8()
{
    return 1;
}


extern "C" int func_001EFAB0()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EFAB8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EFEB8);

extern "C" void func_001F0288(int arg0, int arg1, float *arg2, float *arg3, int arg4)
{
    float dist;
    float ang;
    float spd;

    M2C_FIELD(arg0, int *, 0x64) = 0;
    ang = Xfpff_func_002180E4(&dist, arg3[0] - arg2[0], arg3[2] - arg2[2]);
    spd = (dist * 1.5f) / (float) arg4;
    if (spd > (1.0f / 30.0f)) {
        spd = 1.0f / 30.0f;
    }
    float s = Xff_sinf(ang);
    M2C_FIELD(arg0, int *, 0x34) = 0;
    M2C_FIELD(arg0, float *, 0x30) = s * spd;
    float c = Xff_cosf(ang);
    M2C_FIELD(arg0, int *, 0x60) = 0;
    M2C_FIELD(arg0, int *, 0x50) = arg4;
    M2C_FIELD(arg0, float *, 0x38) = c * spd;
}

extern "C" void func_001F0358(int arg0, int arg1, int arg2, int arg3)
{
    float temp_f1;

    temp_f1 = (float) arg3;
    M2C_FIELD(arg0, float *, 0x30) = (float) (-M2C_FIELD(arg2, float *, 0) / temp_f1);
    M2C_FIELD(arg0, int *, 0x34) = 0;
    M2C_FIELD(arg0, float *, 0x38) = (float) (-M2C_FIELD(arg2, float *, 8) / temp_f1);
}

extern "C" int TskAvoidMove__vfunc_04(TskAvoidMoveObj *arg0)
{
    if (Xiiu_func_001D046C((int)&D_007812C0, arg0->m_unk0C) == 0) {
        return 1;
    }
    return (arg0->*(arg0->m_func))();
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F0434);

extern "C" void TskChrRot__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$9TskChrRot;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskChrRot__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskChrRot__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F090C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F0B50);

extern "C" int func_001F0E14(int arg0)
{
    float temp_f1;
    int var_v0;

    temp_f1 = Xfi_func_0010A650__8DogActor(M2C_FIELD(arg0, int *, 0x50)) - M2C_FIELD(arg0, float *, 0x30);
    var_v0 = 0;
    if (temp_f1 < 0.0f) {
        if (!(temp_f1 >= -0.09999999590218067f)) {

        } else {
            goto block_4;
        }
    } else if (temp_f1 <= 0.09999999590218067f) {
block_4:
        var_v0 = 1;
    }
    return var_v0;
}

extern "C" void func_001F0E90(unsigned int arg0, int arg1, float fparg0)
{
    int *slot;
    int temp_v0_2;

    slot = (int *)(Xiiu_func_001D2B8C((int)&D_007812C0, arg0) + 0x3D8);
    if (Xiii_func_001E7D7C_2((int)&D_007A3D80, *slot) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, *slot);
        *slot = -1;
    }
    if (fparg0 != 0.0f) {
        temp_v0_2 = Xii___builtin_new(0x80);
        Xfunc_001F0434(temp_v0_2, arg0, arg1, -1, fparg0, 32769.0f, 1.0f, 1, 1);
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_2, 0, (int)slot, 0x11);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF58);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDFB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDFB8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDFD8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDFE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDFF0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDFF8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE000);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE008);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE010);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE018);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE020);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE028);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE030);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE038);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE040);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE048);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE050);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE058);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE060);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE068);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE070);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE078);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE080);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE088);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE090);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE098);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE0F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE100);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE108);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE110);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE130);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE140);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE148);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE150);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE158);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE160);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE168);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE170);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE178);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE180);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE188);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE190);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE198);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE1F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE200);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE208);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE210);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE218);

extern "C" void func_001F0F9C(unsigned int arg0, float fparg0, float fparg1)
{
    TskVec4 rot;
    float diff;

    Xv_func_001D06B8(&D_007812C0, arg0, &rot);
    if (rot.f[1] != fparg0) {
        diff = fparg0 - rot.f[1];
        if (diff < -3.14159265358979323846) {
            diff += 2.0 * 3.14159265358979323846;
        }
        if (diff > 3.14159265358979323846) {
            diff -= 2.0 * 3.14159265358979323846;
        }
        Xv_func_001F0E90(arg0, diff, Xiff_func_001F6B8C(diff, fparg1));
    }
}

extern "C" void func_001F10A4(unsigned int arg0, int arg1, float fparg0)
{
    TskVec4 rot;
    float diff;

    Xv_func_001D06B8(&D_007812C0, arg0, &rot);
    if (rot.f[1] != fparg0) {
        diff = fparg0 - rot.f[1];
        if (diff < -3.14159265358979323846) {
            diff += 2.0 * 3.14159265358979323846;
        }
        if (diff > 3.14159265358979323846) {
            diff -= 2.0 * 3.14159265358979323846;
        }
        Xv_func_001F0E90(arg0, diff, arg1);
    }
}

extern "C" void func_001F11A0(int arg0, float fparg0, float fparg1, float fparg2)
{
    float diff;

    if (fparg0 != fparg1) {
        diff = fparg1 - fparg0;
        if (diff < -3.14159265358979323846) {
            diff += 2.0 * 3.14159265358979323846;
        }
        if (diff > 3.14159265358979323846) {
            diff -= 2.0 * 3.14159265358979323846;
        }
        Xv_func_001F1298(arg0, diff, Xiff_func_001F6B8C(diff, fparg2), fparg0);
    }
}

extern "C" void func_001F1298(unsigned int arg0, int arg1, float fparg0, float fparg1)
{
    int *slot;
    int temp_v0_2;

    slot = (int *)(Xiiu_func_001D2B8C((int)&D_007812C0, arg0) + 0x3D8);
    if (Xiii_func_001E7D7C_2((int)&D_007A3D80, *slot) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, *slot);
        *slot = -1;
    }
    if (fparg0 != 0.0f) {
        temp_v0_2 = Xii___builtin_new(0x80);
        Xfunc_001F0434(temp_v0_2, arg0, arg1, -1, fparg0, fparg1, 1.0f, 1, 1);
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_2, 0, (int)slot, 0x11);
    }
}

extern "C" void func_001F13A8(unsigned int arg0, int arg1, int arg2, float fparg0, float fparg1, float fparg2)
{
    int *slot;
    int temp_v0_2;

    slot = (int *)(Xiiu_func_001D2B8C((int)&D_007812C0, arg0) + 0x3D8);
    if (Xiii_func_001E7D7C_2((int)&D_007A3D80, *slot) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, *slot);
        *slot = -1;
    }
    if (fparg0 != 0.0f) {
        temp_v0_2 = Xii___builtin_new(0x80);
        Xfunc_001F0434(temp_v0_2, arg0, 0, arg1, fparg0, fparg2, fparg1, arg2, 1);
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_2, 0, (int)slot, 0x11);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F14CC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F1670);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE280);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE288);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE290);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE298);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2E0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F184C);

extern "C" void TskFrameFunc__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$12TskFrameFunc;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskFrameFunc__vfunc_05(int arg0)
{
    int temp_v0;
    int temp_v0_2;

    if ((*(int *)(int *)((char *)(arg0) + 0x4)) == 8) {
        temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x18));
        if (temp_v0 != 0) {
            X_func_001A074C(temp_v0);
            temp_v0_2 = (*(int *)(int *)((char *)(arg0) + 0x18));
            if (temp_v0_2 != 0) {
                X_func_001A0684(temp_v0_2, 3);
            }
            (*(int *)(int *)((char *)(arg0) + 0x18)) = 0;
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskFrameFunc__vfunc_04);

// NON_MATCHING: 4/80 differ, 6 edits
#ifdef NON_MATCHING
extern "C" int X_func_001311F4(int, int *) asm("func_001311F4");
extern "C" int Xiiiii_func_001311BC(int, int, int, int) asm("func_001311BC");
extern "C" int func_001F27E0(int arg0)
{
    int arr[8];
    int state = M2C_FIELD(arg0, int *, 0x10);
    switch (state) {
    case 0:
    {
        int t = M2C_FIELD(arg0, int *, 0x20) / 2;
        int off = 0x12540;
        M2C_FIELD(arg0, int *, 0x14) = t;
        Xiiiii_func_001311BC((int)&D_006E9840 + off, t, 7, 0);
        M2C_FIELD(arg0, int *, 0x10)++;
        break;
    }
    case 1:
        if (--M2C_FIELD(arg0, int *, 0x14) != -1) {
            return 0;
        } else {
            int off = 0x12540;
            int p = (int)&D_006E9840 + off;
            X_func_00131184(p, 0, 7, 0);
            int t = M2C_FIELD(arg0, int *, 0x20) / 2;
            arr[0] = state;
            arr[1] = 2;
            M2C_FIELD(arg0, int *, 0x14) = t;
            arr[2] = t;
            X_func_001311F4(p, arr);
            M2C_FIELD(arg0, int *, 0x10) = 0x63;
        }
        break;
    case 0x63:
        return --M2C_FIELD(arg0, int *, 0x14) == -1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F27E0);
#endif

// NON_MATCHING: 4/89 differ, 2 edits
#ifdef NON_MATCHING
extern "C" int X_func_001311F4_2920(int, int *) asm("func_001311F4");
extern "C" int X_func_00131184_2920(int, int, int, int) asm("func_00131184");
extern "C" int func_001F2920(int arg0)
{
    int arr[8];
    switch (M2C_FIELD(arg0, int *, 0x10)) {
    case 0:
    {
        arr[2] = M2C_FIELD(arg0, int *, 0x20) / 4;
        arr[0] = 1;
        arr[1] = 6;
        int off = 0x12540;
        int p = (int)&D_006E9840 + off;
        X_func_001311F4_2920(p, arr);
        M2C_FIELD(arg0, int *, 0x10)++;
        M2C_FIELD(arg0, int *, 0x14) = M2C_FIELD(arg0, int *, 0x20) / 2;
        break;
    }
    case 1:
        if (M2C_FIELD(arg0, int *, 0x14)-- > 0) {
            return 0;
        } else {
            int off = 0x12540;
            int p = (int)&D_006E9840 + off;
            M2C_FIELD(arg0, int *, 0x14) = M2C_FIELD(arg0, int *, 0x20) / 2;
            arr[0] = 1;
            arr[1] = 0;
            arr[2] = 0;
            X_func_001311F4_2920(p, arr);
            X_func_00131184_2920(p, M2C_FIELD(arg0, int *, 0x14), 7, 0);
            M2C_FIELD(arg0, int *, 0x10) = 0x63;
        }
        break;
    case 0x63:
        return M2C_FIELD(arg0, int *, 0x14)-- <= 0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2920);
#endif

extern "C" int func_001F2A84(int arg0)
{
    int arr[8];
    switch (M2C_FIELD(arg0, int *, 0x10)) {
    case 0:
    {
        int t = M2C_FIELD(arg0, int *, 0x20) / 2;
        int off = 0x12540;
        M2C_FIELD(arg0, int *, 0x14) = t;
        Xiiiii_func_001311BC_loc((int)&D_006E9840 + off, t, 7, 0);
        M2C_FIELD(arg0, int *, 0x10)++;
        break;
    }
    case 1:
        if (M2C_FIELD(arg0, int *, 0x14)-- > 0) {
            return 0;
        } else {
            int off = 0x12540;
            int p = (int)&D_006E9840 + off;
            X_func_00131184(p, 0, 7, 0);
            int t = M2C_FIELD(arg0, int *, 0x20) / 2;
            arr[0] = 2;
            arr[1] = 2;
            M2C_FIELD(arg0, int *, 0x14) = t;
            arr[2] = t;
            X_func_001311F4_loc(p, arr);
            M2C_FIELD(arg0, int *, 0x10) = 0x63;
        }
        break;
    case 0x63:
        return M2C_FIELD(arg0, int *, 0x14)-- <= 0;
    }
    return 0;
}

// NON_MATCHING: 12/91 differ, 10 edits
#ifdef NON_MATCHING
extern "C" int X_func_001311F4_2bcc(int, int *) asm("func_001311F4");
extern "C" int X_func_00131184_2bcc(int, int, int, int) asm("func_00131184");
extern "C" int func_001F2BCC(int arg0)
{
    int arr[8];
    switch (M2C_FIELD(arg0, int *, 0x10)) {
    case 0:
    {
        int t = M2C_FIELD(arg0, int *, 0x20) / 4;
        int off = 0x12540;
        arr[0] = 2;
        arr[2] = t;
        arr[1] = 6;
        X_func_001311F4_2bcc((int)&D_006E9840 + off, arr);
        M2C_FIELD(arg0, int *, 0x10)++;
        M2C_FIELD(arg0, int *, 0x14) = M2C_FIELD(arg0, int *, 0x20) / 2;
        break;
    }
    case 1:
        if (M2C_FIELD(arg0, int *, 0x14)-- > 0) {
            return 0;
        } else {
            int off = 0x12540;
            int p = (int)&D_006E9840 + off;
            M2C_FIELD(arg0, int *, 0x14) = M2C_FIELD(arg0, int *, 0x20) / 2;
            arr[0] = 2;
            arr[1] = 0;
            arr[2] = 0;
            X_func_001311F4_2bcc(p, arr);
            X_func_00131184_2bcc(p, M2C_FIELD(arg0, int *, 0x14), 7, 0);
            M2C_FIELD(arg0, int *, 0x10) = 0x63;
        }
        break;
    case 0x63:
        return M2C_FIELD(arg0, int *, 0x14)-- <= 0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2BCC);
#endif

// NON_MATCHING: 42/110 differ, 6 relocs differ (size 0x1B8, game 0x18C), 22 edits
#ifdef NON_MATCHING
extern "C" void X_func_00131184_2d38(int, int, int, int) asm("func_00131184");
extern "C" void X_func_001CFA5C_2d38(void *, int, int, int, int, int) asm("func_001CFA5C");
extern "C" int X_func_001CF9D4_2d38(void *) asm("func_001CF9D4");
extern "C" void X_func_001C65E8_2d38(void *, int) asm("func_001C65E8");
extern "C" void X_func_001C6A40_2d38(void *, int) asm("func_001C6A40");
extern "C" int func_001F2D38(int arg0)
{
    switch (M2C_FIELD(arg0, int *, 0x10)) {
    case 0x64:
    {
        int off = 0x12540;
        X_func_00131184_2d38((int)&D_006E9840 + off, 0xA, 7, 0);
        X_func_001CFA5C_2d38(&D_007812C0, 0xD, -1, -1, -1, -1);
        int ret = X_func_001CF9D4_2d38(&D_007812C0);
        if (ret == 0) {
            return ret;
        }
        M2C_FIELD(arg0, int *, 0x10)++;
        break;
    }
    case 0x66:
        X_func_001C65E8_2d38(&D_007812C0, 0x100000);
        X_func_001C6A40_2d38(&D_007812C0, 0x8000);
        return 1;
    case 0xC8:
    {
        int off = 0x12540;
        X_func_00131184_2d38((int)&D_006E9840 + off, 0xA, 7, 0);
        X_func_001CFA5C_2d38(&D_007812C0, 0xE, -1, -1, -1, -1);
        int ret = X_func_001CF9D4_2d38(&D_007812C0);
        if (ret == 0) {
            return ret;
        }
        M2C_FIELD(arg0, int *, 0x10)++;
        break;
    }
    case 0x65:
    case 0xC9:
        if (X_func_001CF9D4_2d38(&D_007812C0) == 0) {
            M2C_FIELD(arg0, int *, 0x10)++;
        }
        break;
    case 0xCA:
        X_func_001C65E8_2d38(&D_007812C0, 0x100000);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2D38);
#endif

extern "C" int func_001F2EC4(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0x10) == 0x64) {
        return Xiiu_func_001D19A8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x20)) != 0;
    }
    M2C_FIELD(arg0, int *, 0x14) = M2C_FIELD(arg0, int *, 0x14) + 1;
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE3F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE400);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE408);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE410);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE418);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", jtbl_002FE420);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE480);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE488);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE490);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE498);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE4F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE500);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE508);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE510);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE518);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE520);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2F0C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F34C8);

extern "C" int func_001F370C(int arg0)
{
    if (Xii_func_001A06D4(M2C_FIELD(arg0, int *, 0x18),
                          (int)_9MagSystem$m_current_system + 0x40) != 0) {
        M2C_FIELD(D_007B205C, int *, 0xB4) = Xii_func_001A0BA0(M2C_FIELD(arg0, int *, 0x18));
        return 1;
    }
    return 0;
}

extern "C" int func_001F3760()
{
    Xiii_func_001C5D08((int)&D_007812C0, 1);
    return 1;
}

extern "C" int func_001F3788()
{
    char *base = (char *)&D_007812C0;

    M2C_FIELD(base, int *, 0x21F4C) = M2C_FIELD(base, int *, 0x21F4C) & ~0x100;
    return 1;
}

extern "C" int func_001F37B8()
{
    char *base = (char *)&D_007812C0;

    if (M2C_FIELD(base, int *, 0x21F48) & 4) {
        M2C_FIELD(base, int *, 0x21F4C) &= ~0x800;
    }
    M2C_FIELD(base, int *, 0x21F4C) &= ~0x400000;
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE548);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE550);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE558);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE560);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F3824);

extern "C" int func_001F3B3C()
{
    struct { char pad0[16]; } stack;
    Xiiii_memset((int)&stack, 0, 0x10);
    Xiii_func_001CB57C((int)&D_007812C0, (int)&stack);
    return 1;
}

extern "C" int func_001F3B74(int arg0)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x10);
    switch (temp_v1) {                              
    case 0:
        Xiiuiii_func_00211BE4((int)&D_007A4440, M2C_FIELD(arg0, unsigned int *, 0x20), M2C_FIELD(arg0, int *, 0x24), 0, 0);
        M2C_FIELD(arg0, int *, 0x10) = (int) (M2C_FIELD(arg0, int *, 0x10) + 1);
block_6:
        return 0;
    case 1:
        if (Xiiui_func_00213D00((int)&D_007A4440, M2C_FIELD(arg0, unsigned int *, 0x20), 0) == 0) {
            Xiiiiiii_func_001CD044((int)&D_007812C0, 2, M2C_FIELD(arg0, int *, 0x28), 0, -1, M2C_FIELD(arg0, int *, 0x2C));
            M2C_FIELD((int)&D_007812C0, int *, 0x222E0) = 0;
            M2C_FIELD((int)&D_007812C0, int *, 0x222DC) = 0;
            return 1;
        }
        goto block_6;
    default:
        return 0;
    }
}

extern "C" int func_001F3C44(int arg0)
{
    float stack[8];
    int temp_v1;
    int temp_a0;
    float temp_f0;
    float temp_f1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x14);
    temp_a0 = M2C_FIELD(arg0, int *, 0x60);
    if (temp_v1 < temp_a0) {
        temp_f0 = (float)temp_v1 / (float)temp_a0;
        temp_f1 = 1.0f - temp_f0;
        float f0 = M2C_FIELD(arg0, float *, 0x40) * temp_f0 + M2C_FIELD(arg0, float *, 0x20) * temp_f1;
        float f1 = M2C_FIELD(arg0, float *, 0x44) * temp_f0 + M2C_FIELD(arg0, float *, 0x24) * temp_f1;
        float f2 = M2C_FIELD(arg0, float *, 0x48) * temp_f0 + M2C_FIELD(arg0, float *, 0x28) * temp_f1;
        float f3 = M2C_FIELD(arg0, float *, 0x4C) * temp_f0 + M2C_FIELD(arg0, float *, 0x2C) * temp_f1;
        float f4 = M2C_FIELD(arg0, float *, 0x50) * temp_f0 + M2C_FIELD(arg0, float *, 0x30) * temp_f1;
        float f5 = M2C_FIELD(arg0, float *, 0x54) * temp_f0 + M2C_FIELD(arg0, float *, 0x34) * temp_f1;
        float f6 = M2C_FIELD(arg0, float *, 0x58) * temp_f0 + M2C_FIELD(arg0, float *, 0x38) * temp_f1;
        float f7 = M2C_FIELD(arg0, float *, 0x5C) * temp_f0 + M2C_FIELD(arg0, float *, 0x3C) * temp_f1;
        stack[0] = f0;
        stack[1] = f1;
        stack[2] = f2;
        stack[3] = f3;
        stack[4] = f4;
        stack[5] = f5;
        stack[6] = f6;
        stack[7] = f7;
        int off = 0x12540;
        Xiii_func_00143D7C((int)&D_006E9840 + off, stack, 0);
        M2C_FIELD(arg0, int *, 0x14)++;
        return 0;
    }
    return 1;
}

extern "C" int func_001F3D90()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F3D98);

extern "C" void func_001F4088(int arg0, int arg1, int arg2)
{
    M2C_FIELD(arg0, int *, 0x10) = arg2;
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$15TskGenFrameFunc;
    if (arg1 == 1) {
        *(m2c_block8 *)((char *)(arg0) + 0x8) = *(m2c_block8 *)((char *)(&D_002FE588) + 0x0);
    }
}

extern "C" void TskGenFrameFunc__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$15TskGenFrameFunc;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskGenFrameFunc__vfunc_04);

extern "C" int func_001F415C(int arg0)
{
    X_func_0017F8FC((int)&D_007B2580, (*(int *)(int *)((char *)(arg0) + 0x10)));
    return 1;
}


extern "C" void func_001F4184(int arg0, int arg1, int arg2, int arg3)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$10TskSysFunc;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 4) = arg1;
    if (arg1 >= 2) {
        return;
    }
    if (arg1 < 0) {
        return;
    }
    M2C_FIELD(arg0, int *, 0x18) = arg3;
    M2C_FIELD(arg0, int *, 0x10) = 0x64;
    M2C_FIELD(arg0, int *, 0x1C) = 0x1E;
    M2C_FIELD(arg0, int *, 0x20) = 0xF;
    M2C_FIELD(arg0, int *, 0x24) = 0x1B;
    *(m2c_block8 *)((char *)(arg0) + 0x8) = *(m2c_block8 *)((char *)(&D_002FE590) + 0x0);
}

extern "C" void TskSysFunc__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$10TskSysFunc;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskSysFunc__vfunc_05(int arg0)
{
    int temp_a0 = M2C_FIELD(arg0, int *, 4);

    if (temp_a0 == 1) {
        char *base = (char *)&D_006FBD80;
        char *p = base + 0x42BB0;

        if (M2C_FIELD(p, int *, 0x944) == temp_a0) {
            M2C_FIELD(p, int *, 0x94C) = 0;
            M2C_FIELD(p, int *, 0x944) = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskSysFunc__vfunc_04);

// NON_MATCHING: 36/51 differ, 1 reloc differs (size 0xCC, game 0xC8), 8 edits
#ifdef NON_MATCHING
extern "C" int func_001F42C4(int arg0)
{
    switch (M2C_FIELD(arg0, int *, 0x10)) {
    case 0x64:
        {
            char *base = (char *)&D_006FBD80;
            char *p = base + 0x42BB0;
            M2C_FIELD(p, volatile int *, 0x93C) = M2C_FIELD(arg0, int *, 0x18);
            if (M2C_FIELD(p, volatile int *, 0x944) == 0) {
                M2C_FIELD(p, volatile int *, 0x94C) = M2C_FIELD(arg0, int *, 0x1C);
                M2C_FIELD(p, volatile int *, 0x944) = 1;
            }
            M2C_FIELD(arg0, int *, 0x10) = 0x65;
            M2C_FIELD(arg0, int *, 0x14) = M2C_FIELD(arg0, int *, 0x24);
        }
        break;
    case 0x65:
        if (M2C_FIELD(arg0, int *, 0x14)-- <= 0) {
            int val = M2C_FIELD(arg0, int *, 0x20);
            char *base = (char *)&D_006FBD80;
            char *p = base + 0x42BB0;
            if (M2C_FIELD(p, volatile int *, 0x944) == 1) {
                M2C_FIELD(p, volatile int *, 0x94C) = val;
                M2C_FIELD(p, volatile int *, 0x944) = 0;
            }
            return 1;
        }
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F42C4);
#endif

extern "C" void func_001F438C(int arg0, const char *arg1)
{
    int off = 0x18E00;
    int v = 1;
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$8TskMovie;
    Xv_func_001E6734((int)&D_007812C0 + off, 0x1D, 1, 0x40, 0, -1);
    Xv_func_0017F5E8((int)&D_007B2580, 8);
    M2C_FIELD(arg0, int *, 4) = 0;
    char *s = (char *)arg0 + 0x10;
    Xv_strncpy(s, arg1, 0x40);
    char *base = (char *)&D_006FBD80;
    Xv_func_00191E58((int)(base + 0x42BB0), 3, 0x1E);
    M2C_FIELD(arg0, int *, 8) = 0x64;
    int *p = &D_007B2060->m_flags;
    *p |= 0x08000000;
    Xv_func_00192834((int)(base + 0x84AA8), s);
    _9MagSystem$m_v_rate = v;
}

extern "C" void TskMovie__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$8TskMovie;
    TskMovie__vfunc_05();
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMovie__vfunc_05()
{
    int *p = &D_007B2060->m_flags;

    *p &= 0xF7FFFFFF;
    Xii_func_001CF95C((int)&D_007812C0);
    char *base = (char *)&D_006FBD80;
    Xii_func_00192920((int)(base + 0x84AA8));
    int v = 2;
    _9MagSystem$m_v_rate = v;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE588);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE590);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMovie__vfunc_04);

extern "C" void func_001F47F0(int arg0, int arg1, int arg2, int arg3)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$11TskSeqEvent;
    M2C_FIELD(arg0, int *, 0xC) = arg2;
    if (arg2 == 0) {
        M2C_FIELD(arg0, int *, 0x3C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = (int) M2C_FIELD(arg3, int *, 0);
        M2C_FIELD(arg0, float *, 0x48) = (float) M2C_FIELD(arg3, float *, 4);
        M2C_FIELD(arg0, int *, 0x1C) = Xiiu_func_001D2B8C((int) (int)&D_007812C0, (unsigned int) arg1);
        if (!(M2C_FIELD(arg0, float *, 0x48) <= 1.0f)) {
            *(m2c_block8 *)((char *)(arg0) + 0x4) = *(m2c_block8 *)((char *)(&D_002FE5E8) + 0x0);
            return;
        }
    }
    *(m2c_block8 *)((char *)(arg0) + 0x4) = *(m2c_block8 *)((char *)(&D_002FE5E0) + 0x0);
}

extern "C" void TskSeqEvent__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskSeqEvent__vfunc_04);

extern "C" int func_001F4910()
{
    return 1;
}


// NON_MATCHING: 29/67 differ, 29 edits
#ifdef NON_MATCHING
struct __attribute__((aligned(8))) TskSeq48 {
    int unk0;
    int unk4;
    long long unk8;
    float unk10;
    int unk14;
    long long unk18;
    long long unk20;
    long long unk28;
};
static inline void setSeq48(int ptr, struct TskSeq48 val)
{
    *(struct TskSeq48 *)(ptr + 0x150) = val;
}
extern "C" int func_001F4918(int arg0)
{
    int *p3C = (int *)(arg0 + 0x3C);
    int prev = (*p3C)++;
    if (prev < M2C_FIELD(arg0, int *, 0x20)) {
        if (Xiiu_func_001D046C((int)&D_007812C0, M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), unsigned int *, 0x100)) != 0) {
            float ratio = (float)*p3C / (float)M2C_FIELD(arg0, int *, 0x20);
            M2C_FIELD(arg0, float *, 0x4C) = ratio;
            struct TskSeq48 s;
            s.unk0 = 2;
            s.unk4 = 4;
            s.unk10 = M2C_FIELD(arg0, float *, 0x48) * ratio;
            setSeq48(M2C_FIELD(arg0, int *, 0x1C), s);
            return 0;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F4918);
#endif

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE5E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE5E8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F4A24);

extern "C" void TskMsgMan__vfunc_06(int arg0, int arg1)
{
    int temp_s0;
    int temp_s1;

    (*(int *)(arg0)) = (int)&_vt$9TskMsgMan;
    Xv_TskMsgMan__vfunc_05(arg0);
    temp_s1 = arg0 + 0x224;
    if (temp_s1 != 0) {
        temp_s0 = temp_s1 + 0x778;
        while (temp_s1 != temp_s0) {
            temp_s0 -= 0x3BC;
            Xvii_func_00183B24(temp_s0, 2);
        }
    }
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMsgMan__vfunc_05(int arg0)
{
    char *base = (char *)&D_006E9840;

    Xii_func_00187464(arg0 + 0x224);
    char *scene = base + 0x12540;
    Xiiui_func_001351B0((int) scene, M2C_FIELD(arg0, unsigned int *, 0x214), 1);
    Xiiu_func_00135594((int) scene, M2C_FIELD(arg0, unsigned int *, 0x214));
    Xiiu_func_001348B0((int) scene, M2C_FIELD(arg0, unsigned int *, 0x214));
    M2C_FIELD(arg0, int *, 0x204) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMsgMan__vfunc_02);

// NON_MATCHING: 38/86 differ, 3 relocs differ (size 0x158, game 0x15C), 15 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_001874AC(int) asm("func_001874AC");
extern "C" int Xiii_func_001875C0(int, int) asm("func_001875C0");
extern "C" int Xiii_func_0018761C(int, int) asm("func_0018761C");
static inline unsigned int padTrigU_04(int p) { return *(unsigned short *)((char *)p + 0x7A); }
extern "C" int TskMsgMan__vfunc_04(int arg0)
{
    int var_s1 = 0;
    int off = 0x97A40;
    int *pad = (int *)((char *)&D_006E9840 + off);
    switch (M2C_FIELD(arg0, unsigned int *, 0x204)) {
    case 0:
        break;
    case 1:
    {
        int tmp = M2C_FIELD(arg0, int *, 0x21C);
        M2C_FIELD(arg0, int *, 0x21C) = tmp + 1;
        var_s1 = M2C_FIELD(arg0, int *, 0x210) < tmp;
        break;
    }
    case 2:
        if (Xiii_func_001875C0(arg0 + 0x224, M2C_FIELD(arg0, int *, 0x214)) == 0) {
            int ok = (((padTrigU_04(*pad) >> 0xE) & 1) && (M2C_FIELD(arg0, int *, 0x21C) >= 0xB));
            var_s1 = ok;
        }
        M2C_FIELD(arg0, int *, 0x21C)++;
        break;
    case 3:
        if (Xiii_func_001875C0(arg0 + 0x224, M2C_FIELD(arg0, int *, 0x214)) == 0) {
            int ok = ((M2C_FIELD(arg0, int *, 0x21C) >= 0xB) && ((padTrigU_04(*pad) >> 0xE) & 1));
            var_s1 = ok;
        }
        if (var_s1 == 0) {
            var_s1 = M2C_FIELD(arg0, int *, 0x210) < M2C_FIELD(arg0, int *, 0x21C);
        }
        M2C_FIELD(arg0, int *, 0x21C)++;
        break;
    case 4:
        var_s1 = Xiii_func_001875C0(arg0 + 0x224, M2C_FIELD(arg0, int *, 0x214)) == 0;
        M2C_FIELD(arg0, int *, 0x21C)++;
        break;
    }
    if (var_s1 != 0) {
        Xiii_func_0018761C(arg0 + 0x224, M2C_FIELD(arg0, int *, 0x214));
        return 1;
    }
    Xii_func_001874AC(arg0 + 0x224);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMsgMan__vfunc_04);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F50B8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F5244);

extern "C" void TskAttach__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$9TskAttach;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskAttach__vfunc_05(void) {
}

extern "C" int TskAttach__vfunc_04(int arg0)
{
    struct { char pad0[48]; int sp30; } stack;

    Xiiiii_getActorNodeMatrix__9MagSystemiP19tag_I3dMatrixF4x4_sPCc((int) (int)&D_006E9840, M2C_FIELD(arg0, int *, 8), (int) (int)&stack, M2C_FIELD(arg0, int *, 0xC));
    Xiiiiiii_func_0013F980__8MagSceneiiiPfi((int) ((int)&D_006E9840 + 0x12540), 2, M2C_FIELD(arg0, int *, 0x10), 0, (int) (int)&stack.sp30, 0);
    return 0;
}

extern "C" int func_001F5350(unsigned int arg0, unsigned int arg1, float fparg0)
{
    TskHitCheck hit;
    TskVec4 pos1;
    TskVec4 pos0;
    TskVec4 rot0;

    Xv_func_001D05F4(&D_007812C0, arg1, &pos1);
    Xv_func_001D06B8(&D_007812C0, arg0, &rot0);
    Xv_func_001D05F4(&D_007812C0, arg0, &pos0);
    pos1.f[3] = Xf_func_001D4A3C(&D_007812C0, arg1, 0);
    pos0.f[3] = fparg0;
    hit.m_origin_pos = &pos0;
    hit.m_rotate = 0;
    hit.m_angle = fparg0;
    hit.m_target_pos = &pos1;
    return Xi_func_0010456C(&hit) != 0;
}

extern "C" int func_001F5410(unsigned int arg0, unsigned int arg1, int arg2, float fparg0)
{
    TskVec4 pos0;
    TskVec4 pos1;
    TskHitCheck hit;
    char *actor = (char *)&D_006FE6A0 + Xiiu_func_001CBE38(&D_007812C0, arg0) * 0x4D0;

    if (M2C_FIELD(actor, int *, 0x11C) == 0) {
        X_ror_assert(D_002FE698, 0x131, D_002FE6A8);
    }
    if (arg2 == 0) {
        X_ror_assert(D_002FE698, 0x131, D_002FE6B8);
    }
    int idx = Xiii_func_0022B3D8(M2C_FIELD(actor, int *, 0x11C), arg2);
    pos0.f[0] = pos0.f[1] = pos0.f[2] = 0.0f;
    pos0.f[3] = 1.0f;
    struct DogVtblEntry *vt = (struct DogVtblEntry *)((char *)M2C_FIELD(actor, char **, 0x94) + 0x90);
    vt->fn((void *)(actor + vt->delta), pos0.f, idx);
    Xv_func_001D05F4(&D_007812C0, arg1, &pos1);
    pos1.f[3] = 50.0f;
    pos0.f[3] = fparg0;
    hit.m_origin_pos = &pos0;
    hit.m_rotate = 0;
    hit.m_angle = 0.0f;
    hit.m_target_pos = &pos1;
    hit.m_scale = 0.0f;
    return Xi_func_0010456C(&hit) != 0;
}

extern "C" int func_001F5558(unsigned int arg0, float *arg1, int arg2)
{
    int actor = Xipu_func_001CBDB8(&D_007812C0, arg0);
    if (actor == 0) {
        return 0;
    }
    if (M2C_FIELD(&D_007812C0, int *, 0x21F4C) & 0x3000) {
        return 0;
    }
    if (M2C_FIELD(actor, int *, 0x11C) == 0) {
        X_ror_assert(D_002FE698, 0x131, D_002FE6A8);
    }
    if (arg2 == 0) {
        X_ror_assert(D_002FE698, 0x131, D_002FE6B8);
    }
    int idx = Xiii_func_0022B3D8(M2C_FIELD(actor, int *, 0x11C), arg2);
    if (idx < 0) {
        return 0;
    }
    float vec[4];
    vec[0] = vec[1] = vec[2] = 0.0f;
    vec[3] = 1.0f;
    struct DogVtblEntry *vt = (struct DogVtblEntry *)((char *)M2C_FIELD(actor, char **, 0x94) + 0x90);
    vt->fn((void *)(actor + vt->delta), vec, idx);
    arg1[0] = vec[0];
    arg1[1] = vec[1];
    arg1[2] = vec[2];
    arg1[3] = vec[3];
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE698);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE6A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE6B8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F5680);
