#include "include_asm.h"
#include "ror.h"
#include "unk/TskMsgMan.h"
extern "C" float yawC0(float, float) asm("func_00217F10");
extern "C" int rotGet(int, int) asm("func_001E79C0");
struct Ecbe0Targets { char pad[0x10]; int targets[128]; };
extern "C" void ecbe0Stop(int, int) asm("func_001D8964");
extern "C" void ecbe0Move(int, int, int, int, int, int, float) asm("func_001F6308");
extern "C" void ecbe0Yaw(int, float, float) asm("func_001F0F9C");
struct TskVec4_f1670 {
    float f[4];
} __attribute__((aligned(16)));
extern "C" int X_func_001D2B8C_f1670(int, unsigned int) asm("func_001D2B8C");
extern "C" int X_func_001E7D7C_f1670(int, int) asm("func_001E7D7C");
extern "C" void X_func_001E7724_f1670(int, int) asm("func_001E7724");
extern "C" void X_func_001D06B8_f1670(void *, unsigned int, TskVec4_f1670 *) asm("func_001D06B8");
extern "C" int X___builtin_new_f1670(int) asm("__builtin_new");
extern "C" void X_func_001F0434_f1670(int, unsigned int, int, int, float, float, float, int, int) asm("func_001F0434");
extern "C" int X_func_001E71FC_f1670(int, int, int, int, int, int, int, int *, int) asm("func_001E71FC");
extern "C" void X_func_00191F44_v2(int, int) asm("func_00191F44");
extern "C" void X_func_00191F98_v2(int, int) asm("func_00191F98");
extern "C" void X_func_001351B0_v2(int, unsigned int, int) asm("func_001351B0");
static inline void pause_v2(unsigned int no, char *base)
{
    X_func_001351B0_v2((int)(base + 0x12540), no, 1);
    int s = (int)(base + 0x550F0);
    X_func_00191F44_v2(s, 0);
    X_func_00191F44_v2(s, 2);
    X_func_00191F44_v2(s, 1);
    X_func_00191F44_v2(s, 3);
    X_func_00191F44_v2(s, 5);
    X_func_00191F44_v2(s, 4);
    X_func_00191F44_v2(s, 6);
    X_func_00191F44_v2(s, 7);
    X_func_00191F44_v2(s, 8);
    X_func_00191F44_v2(s, 9);
    X_func_00191F44_v2(s, 0xA);
    X_func_00191F44_v2(s, 0xB);
    X_func_00191F44_v2(s, 0xC);
    X_func_00191F44_v2(s, 0xD);
}
static inline void resume_v2(unsigned int no, char *base)
{
    X_func_001351B0_v2((int)(base + 0x12540), no, 0);
    int s = (int)(base + 0x550F0);
    X_func_00191F98_v2(s, 0);
    X_func_00191F98_v2(s, 2);
    X_func_00191F98_v2(s, 1);
    X_func_00191F98_v2(s, 3);
    X_func_00191F98_v2(s, 5);
    X_func_00191F98_v2(s, 4);
    X_func_00191F98_v2(s, 6);
    X_func_00191F98_v2(s, 7);
    X_func_00191F98_v2(s, 8);
    X_func_00191F98_v2(s, 9);
    X_func_00191F98_v2(s, 0xA);
    X_func_00191F98_v2(s, 0xB);
    X_func_00191F98_v2(s, 0xC);
    X_func_00191F98_v2(s, 0xD);
}
extern "C" float X_func_002180E4_ecf3c(float *, float, float) asm("func_002180E4");
extern "C" void X_func_001F11A0_ecf3c(int, float, float, float) asm("func_001F11A0");
extern "C" int X_func_001E7D7C_ecf3c(int, int) asm("func_001E7D7C");
extern "C" int X_func_001EE7F0_ecf3c(unsigned int, unsigned short, float, float, int *, int, float) asm("func_001EE7F0");
extern "C" float X_func_002180E4_eacb8(float *, float, float) asm("func_002180E4");
extern "C" void X_func_001F11A0_eacb8(int, float, float, float) asm("func_001F11A0");
extern "C" int X_func_001E7D7C_eacb8(int, int) asm("func_001E7D7C");
extern "C" int X_func_001EE7F0_eacb8(unsigned int, unsigned short, float, float, int *, int, float) asm("func_001EE7F0");
struct TskVec4_ee954 {
    float f[4];
};
extern "C" float X_func_001333E4_ee954(int, int, int) asm("func_001333E4");
extern "C" void X_func_001331F4_ee954(int, int, int, int, int, int, float) asm("func_001331F4");
extern "C" int X_func_00118E6C_ee954(void *, int, float, float, TskVec4_ee954 *, float *, TskVec4_ee954 *) asm("func_00118E6C__9MagSystemiffR9DogVectorPfP9DogVector");
extern "C" float X_func_001F6C14_ee954(int, float) asm("func_001F6C14");
extern "C" int X_func_001F59B4_ee954(unsigned int, int, int, int, int, float, float) asm("func_001F59B4");
extern "C" void X_func_0018741C_50b8(int) asm("func_0018741C");
extern "C" int X_func_00187464_50b8(int) asm("func_00187464");
extern "C" void X_func_001874F4_50b8(int, int, int, int) asm("func_001874F4");
extern "C" char *X_strncpy_50b8(char *, const char *, int) asm("strncpy");
extern "C" int X_func_00134730_50b8(int, int, int, int, int) asm("func_00134730");
extern "C" void X_func_00118980__9MagSystemiiiiii(void *, int, int, int, int, int, int) asm("func_00118980__9MagSystemiiiiii");
extern "C" int X_func_001348B0_50b8(int, unsigned int) asm("func_001348B0");
extern "C" int X_func_00135594_50b8(int, unsigned int) asm("func_00135594");
extern "C" int X_func_001351B0_50b8(int, unsigned int, int) asm("func_001351B0");
extern "C" void X_func_00135418_50b8(int, unsigned int, int) asm("func_00135418");
extern "C" void X_func_00135494_50b8(int, unsigned int, int) asm("func_00135494");
extern "C" void X_func_00134CD0_50b8(int, unsigned int, int, int, int, int) asm("func_00134CD0");
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
    char pad5C[0x10];
    float unk6C;
    char pad70[0x20];
    int unk90;
    char *vtbl94;
    char pad98[0x84];
    int unk11C;
    char pad120[0xB8];
    int unk1D8;
    char pad1DC[0x4D0 - 0x1DC];
};
struct DogManStub {
    char pad0[0x2920];
    struct DogActorStub actors[1];
};
static inline struct DogActorStub *getDogActor(void *base, int idx)
{
    return (struct DogActorStub *)(((char *)base + idx * 0x4D0) + 0x2920);
}
extern "C" int Xiii_func_001D8ADC_mpp(int, int) asm("func_001D8ADC");
extern "C" void Xv_func_001EC834_mpp(TskMovePointPath *) asm("func_001EC834");
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
extern "C" int X_func_001ED1D0(TskMoveSectaFindPath *) asm("func_001ED1D0");
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
extern "C" void Xv_TskMsgMan__vfunc_05(TskMsgMan *) asm("TskMsgMan__vfunc_05");
extern "C" void Xvii_func_00183B24(void *, int) asm("func_00183B24");
extern "C" char vtbl_TskMsgMan[] asm("_vt$9TskMsgMan");
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
extern "C" char vtbl_TskMovie[] asm("_vt$8TskMovie");
extern "C" void TskMovie__vfunc_05();
extern "C" int Xii_func_001A06D4(void *, int) asm("func_001A06D4");
extern "C" int Xii_func_001A0BA0(void *) asm("func_001A0BA0");
extern int D_007B205C;
extern int _9MagSystem$m_current_system;
extern "C" int Xiiu_func_001D19A8(void *, unsigned int) asm("func_001D19A8");
// u_long128: include/target.h
extern "C" char vtbl_TskSysFunc[] asm("_vt$10TskSysFunc");
extern "C" char vtbl_TskRotAdj[] asm("_vt$9TskRotAdj");
extern "C" char vtbl_TskMoveTypeRound[] asm("_vt$16TskMoveTypeRound");
extern "C" char vtbl_TskMoveTypeGen[] asm("_vt$14TskMoveTypeGen");
extern "C" char vtbl_TskMoveSecta[] asm("_vt$12TskMoveSecta");
extern "C" char vtbl_TskMoveSectaFindPath[] asm("_vt$20TskMoveSectaFindPath");
extern "C" char vtbl_TskMovePointPath[] asm("_vt$16TskMovePointPath");
extern "C" char vtbl_TskMovePhysic[] asm("_vt$13TskMovePhysic");
extern "C" char vtbl_TskMoveAdj[] asm("_vt$10TskMoveAdj");
extern "C" char vtbl_TskFrameFunc[] asm("_vt$12TskFrameFunc");
extern "C" char vtbl_TskChrRot[] asm("_vt$9TskChrRot");
extern "C" char vtbl_TskAvoidMove[] asm("_vt$12TskAvoidMove");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" char vtbl_TskAttach[] asm("_vt$9TskAttach");
struct m2c_block8 { int w[2]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" ObjStat *Xiiu_func_001D2B8C(void *, unsigned int) asm("func_001D2B8C");
extern int D_002FE588;
extern int D_002FE5E0;
extern int D_002FE5E8;
extern "C" char vtbl_TskSeqEvent[] asm("_vt$11TskSeqEvent");
extern "C" char vtbl_TskGenFrameFunc[] asm("_vt$15TskGenFrameFunc");
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
extern int D_007A3D80;
extern int D_007A4440;
extern int D_007B2580;

// declarations from the code that moved to unk/TskMtnMove:

extern "C" int genGet(int, int, int) asm("func_001DA228");
extern "C" int genFinish(int, float) asm("func_001EAFB0");
extern "C" void func_001E9A3C(TskMoveTypeGen *param0, unsigned int arg1, int param2, int param3, int param4, float fparg0)
{
    register TskMoveTypeGen *arg0 PS2_REG("$20") = param0;
    int arg2 = param2;
    int arg3 = param3;
    int arg4 = param4;
    float *rate = &arg0->m_unk74;
    arg0->m_oid = arg1;
    *(void **)arg0 = vtbl_TskMoveTypeGen;
    ObjStat *actor = Xiiu_func_001D2B8C(&D_007812C0, arg1);
    arg0->m_obj = actor;
    int no = actor->getChrID();
    arg0->m_type = arg2;
    arg0->m_chrID = no;
    arg0->m_unk6C = arg3;
    arg0->m_unkA0 = fparg0;
    arg0->m_unkA4 = arg4;
    arg0->m_unk84 = 0;
    Xiiii_memset((int)&arg0->m_func, 0, 8);
    arg0->m_flg = 0;
    arg0->m_unk68 = 0;
    genGet((int)arg0->m_obj, 0x1100, (int)&arg0->m_unk70);
    genGet((int)arg0->m_obj, 0x1103, (int)rate);
    genGet((int)arg0->m_obj, 0x1101, (int)&arg0->m_unkAC);
    genGet((int)arg0->m_obj, 0x1102, (int)&arg0->m_unkB0);
    genGet((int)arg0->m_obj, 0x1105, (int)&arg0->m_unkB4);
    genGet((int)arg0->m_obj, 0x1104, (int)&arg0->m_unk78);
    float r = *rate * (1.0f/60.0f);
    *rate = r;
    register int threshold PS2_REG("$3") = 5;
    register int flag PS2_REG("$4") = 0;
    if (threshold < arg0->m_type && (!(r > 0.0001f) || !(r < 1.0f))) flag = 1;
    if (flag) arg0->m_unk74 = (1.0f/60.0f);
    if (arg0->m_obj->checkFlg(0x400000)) arg0->m_flg |= 1;
    register float *rot PS2_REG("$5") = arg0->m_rot.f;
    register float *pos PS2_REG("$4") = arg0->m_pos.f;
    DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
    rot[0] = d->unk50[0]; rot[1] = d->unk50[1]; rot[2] = d->unk50[2];
    d = getDogActor(&D_006FBD80, arg0->m_chrID);
    pos[0] = d->unk40[0]; pos[1] = d->unk40[1]; pos[2] = d->unk40[2];
    d = getDogActor(&D_006FBD80, arg0->m_chrID);
    *(int *)rot = 0;
    float yaw = Xfi_func_0010A650__8DogActor((int)d);
    M2C_FIELD(&arg0->m_rot, int *, 8) = 0;
    arg0->m_rot.f[1] = yaw;
    genFinish((int)arg0, Xfi_func_001E9CB4((int)arg0));
}

extern "C" void TskMoveTypeGen__vfunc_06(TskMoveTypeGen *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskMoveTypeGen;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveTypeGen__vfunc_05(void) {
}

// D_002FDA88: the end of unk/TskMtnMove's .rodata now (config/splits_manual.tsv)

// D_002FDA98: the end of unk/TskMtnMove's .rodata now (config/splits_manual.tsv)

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDAC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDAC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDAD0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001E9CB4);

// NON_MATCHING: 219/266 differ, 40 relocs differ (size 0x428, game 0x44C), 92 edits
#ifdef NON_MATCHING
extern "C" int activeA5ec(int, int) asm("func_001E7D7C");
extern "C" int taskA5ec(int, int) asm("func_001E79C0");
extern "C" void posA5ec(int, unsigned int, float *) asm("func_001D05F4");
extern "C" float yawA5ec(float *, float, float) asm("func_002180E4");
extern "C" int moveA5ec(unsigned int, unsigned short, float, float, int *, int, float) asm("func_001EE7F0");
extern "C" void startA5ec(int, int, int, int, int, int, float) asm("func_001F6308");
extern "C" float sinA5ec(float) asm("sinf");
extern "C" float cosA5ec(float) asm("cosf");
struct CopyA5ec { int words[2]; };
extern const CopyA5ec cbA5ec0 asm("D_002FDAC0");
extern const CopyA5ec cbA5ec1 asm("D_002FDAC8");
extern const CopyA5ec cbA5ec2 asm("D_002FDAD0");
extern const double cA5ec_2FDBA8 asm("D_002FDBA8");
extern const double cA5ec_2FDBB0 asm("D_002FDBB0");
extern const double cA5ec_2FDBB8 asm("D_002FDBB8");
extern const double cA5ec_2FDBC0 asm("D_002FDBC0");
extern const double cA5ec_2FDBC8 asm("D_002FDBC8");
extern const double cA5ec_2FDBD0 asm("D_002FDBD0");
extern const double cA5ec_2FDBD8 asm("D_002FDBD8");
extern const double cA5ec_2FDBE0 asm("D_002FDBE0");
extern const double cA5ec_2FDBE8 asm("D_002FDBE8");
extern "C" float func_001EA5EC(int arg0) {
    float distance;
    float *pos = (float *)(arg0 + 0x30);
    float angle = 0.0f;
    u_long128 *saved = (u_long128 *)(arg0 + 0x90);
    register int actors PS2_REG("$21") = (int)&D_006FBD80;
    register int stride PS2_REG("$22") = 0x4D0;
    int taskman = (int)&D_007A3D80;
    int actor = M2C_FIELD(arg0, int *, 0xC) * stride + actors + 0x2920;
    pos[0] = M2C_FIELD(actor, float *, 0x40);
    pos[1] = M2C_FIELD(actor, float *, 0x44);
    pos[2] = M2C_FIELD(actor, float *, 0x48);
    int slot = M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x3DC);
    if (!activeA5ec(taskman, slot)) {
        float *rot = (float *)(arg0 + 0x40);
        actor = M2C_FIELD(arg0, int *, 0xC) * stride + actors + 0x2920;
        rot[0] = M2C_FIELD(actor, float *, 0x50);
        rot[1] = M2C_FIELD(actor, float *, 0x54);
        rot[2] = M2C_FIELD(actor, float *, 0x58);
    } else {
        M2C_FIELD(arg0, float *, 0x44) = M2C_FIELD(taskA5ec(taskman, slot), float *, 0x6C);
    }
    *saved = *(u_long128 *)pos;
    int mode = M2C_FIELD(arg0, int *, 0x1C);
    if (mode >= 3 && (mode < 5 || (mode < 13 && mode >= 11))) {
        unsigned int id = M2C_FIELD(arg0, unsigned int *, 0x6C);
        M2C_FIELD(arg0, unsigned int *, 0x10) = id;
        M2C_FIELD(arg0, float *, 0x14) = M2C_FIELD(arg0, float *, 0xA0);
        posA5ec((int)&D_007812C0, id, (float *)(arg0 + 0x20));
        angle = yawA5ec(&distance, M2C_FIELD(arg0, float *, 0x20) - pos[0], M2C_FIELD(arg0, float *, 0x28) - M2C_FIELD(arg0, float *, 0x38));
        float speed = M2C_FIELD(arg0, float *, 0x14);
        if (speed < 0.0f) angle += cA5ec_2FDBA8;
        if (angle < cA5ec_2FDBB0) angle += cA5ec_2FDBB8;
        if (angle > cA5ec_2FDBC0) angle -= cA5ec_2FDBC8;
        M2C_FIELD(arg0, int *, 0x84) = 0;
        bool specialMode = M2C_FIELD(arg0, int *, 0x1C) >= 8;
        if (specialMode) {
            int count = moveA5ec(M2C_FIELD(arg0, unsigned int *, 8), M2C_FIELD(arg0, unsigned short *, 0xC), 32769.0f, distance, (int *)(arg0 + 0x84), M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, float *, 0x74));
            M2C_FIELD(arg0, int *, 0x60) = count;
            M2C_FIELD(arg0, int *, 0x64) = count / 2;
        } else {
            float zero = 0.0f;
            if (speed == zero) M2C_FIELD(arg0, float *, 0x14) = 1.0f;
            M2C_FIELD(arg0, int *, 0x60) = (int)(distance / M2C_FIELD(arg0, float *, 0x14));
            if (angle < cA5ec_2FDBD0) angle += cA5ec_2FDBD8;
            if (angle > cA5ec_2FDBE0) angle -= cA5ec_2FDBE8;
            float x = sinA5ec(angle);
            M2C_FIELD(arg0, float *, 0x54) = zero;
            M2C_FIELD(arg0, float *, 0x50) = x * M2C_FIELD(arg0, float *, 0x14);
            M2C_FIELD(arg0, float *, 0x58) = cosA5ec(angle) * M2C_FIELD(arg0, float *, 0x14);
            startA5ec(M2C_FIELD(arg0, int *, 0xC), M2C_FIELD(arg0, int *, 0x70), 0, 0x100, M2C_FIELD(arg0, int *, 8), 0, M2C_FIELD(arg0, float *, 0x74));
        }
        int m = M2C_FIELD(arg0, int *, 0x1C);
        if (m == 4 || m == 12) M2C_FIELD(arg0, int *, 0x60) = M2C_FIELD(arg0, int *, 0x68);
    }
    bool specialMode = M2C_FIELD(arg0, int *, 0x1C) >= 8;
    if (specialMode) {
        M2C_FIELD(arg0, CopyA5ec *, 0x7C) = cbA5ec0;
    } else {
        int flags = M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x120);
        if ((flags & 0x40) && !(flags & 0x80)) M2C_FIELD(arg0, CopyA5ec *, 0x7C) = cbA5ec1;
        else M2C_FIELD(arg0, CopyA5ec *, 0x7C) = cbA5ec2;
    }
    return angle;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EA5EC);
#endif

extern "C" int func_001EAA38(TskMoveTypeGen *arg0)
{
    if (Xiii_func_001E7D7C_2((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) != 0 ||
        arg0->m_cnt == 1) {
        Xiii_func_001D8964((int)arg0->m_obj, (int)arg0->m_rot.f);
        arg0->m_cnt = 2;
        return 0;
    }
    arg0->m_unk84 = 0;
    {
        struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
        float *p30 = arg0->m_pos.f;
        p30[0] = d->unk40[0];
        p30[1] = d->unk40[1];
        p30[2] = d->unk40[2];
    }
    {
        struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
        float *p40 = arg0->m_rot.f;
        p40[0] = d->unk50[0];
        p40[1] = d->unk50[1];
        p40[2] = d->unk50[2];
    }
    arg0->m_rot.f[1] = Xfi_func_0010A650__8DogActor((int)getDogActor(&D_006FBD80, arg0->m_chrID));
    float f = Xfi_func_001E9CB4((int)arg0);
    if (arg0->m_type < 8) {
        Xiiff_func_001F0F9C(arg0->m_oid, f, arg0->m_unk78);
    } else {
        Xiifff_func_001F11A0(arg0->m_oid, arg0->m_rot.f[1], f, arg0->m_unk78);
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

extern "C" int func_001EAC38(TskMoveTypeGen *arg0)
{
    TskVec4 *pos = &arg0->m_pos;

    if ((arg0->m_flg & 1) != 0) {
        if (X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) != 0) {
            return 0;
        }
    }
    Xv_func_0025B878(pos, pos, &arg0->m_vel);
    Xvii_func_001D8B9C((int)arg0->m_obj, (int)pos);
    arg0->m_cnt = arg0->m_cnt - 1;
    return 0;
}

extern "C" int func_001EACB8(TskMoveTypeGen *arg0)
{
    float dist;
    float ang;
    int cnt;

    if (arg0->m_flg & 1) {
        if (arg0->m_flg & 2) {
            if (X_func_001E7D7C_eacb8((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) == 0) {
                int a = arg0->m_unk84;
                arg0->m_flg &= ~2;
                M2C_FIELD(a, int *, 4) &= ~1;
            }
        } else if (X_func_001E7D7C_eacb8((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) != 0) {
            int b = arg0->m_unk84;
            arg0->m_flg |= 2;
            M2C_FIELD(b, int *, 4) |= 1;
        }
    }
    if (arg0->m_cnt < arg0->m_halfCnt) {
        {
            struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
            float *p30 = arg0->m_pos.f;
            p30[0] = d->unk40[0];
            p30[1] = d->unk40[1];
            p30[2] = d->unk40[2];
        }
        ang = X_func_002180E4_eacb8(&dist, arg0->m_targetPos.f[0] - arg0->m_pos.f[0], arg0->m_targetPos.f[2] - arg0->m_pos.f[2]);
        arg0->m_cnt = X_func_001EE7F0_eacb8(
            arg0->m_oid,
            (unsigned short)arg0->m_chrID,
            ang,
            dist,
            &arg0->m_unk84,
            arg0->m_unk70,
            arg0->m_unk74);
        {
            struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
            float *p40 = arg0->m_rot.f;
            p40[0] = d->unk50[0];
            p40[1] = d->unk50[1];
            p40[2] = d->unk50[2];
        }
        X_func_001F11A0_eacb8(arg0->m_oid, arg0->m_rot.f[1], ang, 1.0f);
        cnt = arg0->m_cnt;
        if (cnt >= 6) {
            arg0->m_halfCnt = cnt / 2;
        } else {
            arg0->m_halfCnt = 0;
        }
    }
    arg0->m_cnt--;
    return 0;
}

extern "C" void TskMoveTypeGen__vfunc_04(TskMoveTypeGen *arg0)
{
    if (arg0->m_cnt > 0) {
        (arg0->*(arg0->m_func))();
    } else {
        return Xv_func_001EAF00(arg0);
    }
}

extern "C" int func_001EAF00(TskMoveTypeGen *arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v1 = arg0->m_type;
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
    if ((unsigned int)arg0->m_chrID >= 0x201U) {
        arg0->m_chrID = arg0->m_obj->getChrID();
    }
    Xiif_func_001EAFB0((int)arg0, Xfi_func_001EA5EC((int)arg0));
    temp_v0 = arg0->m_unk68;
    if (temp_v0 > 0) {
        arg0->m_cnt = temp_v0;
    }
    if (arg0->m_cnt == 0) {
        M2C_FIELD(&arg0->m_vel, int *, 0) = 0;
        M2C_FIELD(&arg0->m_vel, int *, 4) = 0;
        M2C_FIELD(&arg0->m_vel, int *, 8) = 0;
    }
    return 0;

fail:
    Xiu_func_001F61EC(arg0->m_oid);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EAFB0);

// NON_MATCHING: 157/190 differ, 10 relocs differ (size 0x2F8, game 0x308), 155 edits
#ifdef NON_MATCHING
struct RoundFnB63 { int w[2]; };
extern const RoundFnB63 roundFn0B63 asm("D_002FDCB8");
extern const RoundFnB63 roundFn1B63 asm("D_002FDCC0");
extern const RoundFnB63 roundFn2B63 asm("D_002FDCC8");
extern "C" int roundMoveB63(int, int, int, int, int, int, float) asm("func_001F6308");
extern "C" void func_001EB63C(int arg0, int arg1, int arg2, int arg3, int arg4, float f0, float f1, float f2) {
    M2C_FIELD(arg0, void **, 0) = vtbl_TskMoveTypeRound;
    M2C_FIELD(arg0, int *, 8) = arg1;
    register int man PS2_REG("$21") = (int)&D_006FBD80;
    int obj = X_func_001D2B8C_f1670((int)&D_007812C0, arg1);
    float one = 1.0f;
    M2C_FIELD(arg0, int *, 4) = obj;
    register int stride PS2_REG("$22") = 0x4D0;
    float *pos = (float *)(arg0 + 0x40);
    float *rot = (float *)(arg0 + 0x50);
    int id = M2C_FIELD(obj, int *, 0x108);
    M2C_FIELD(arg0, float *, 0x1C) = f0;
    M2C_FIELD(arg0, int *, 0xC) = id;
    M2C_FIELD(arg0, float *, 0x28) = f1;
    M2C_FIELD(arg0, float *, 0x24) = one;
    M2C_FIELD(arg0, int *, 0x2C) = arg2;
    int actor = id * stride + man;
    actor += 0x2920;
    pos[0] = M2C_FIELD(actor, float *, 0x40);
    pos[1] = M2C_FIELD(actor, float *, 0x44);
    pos[2] = M2C_FIELD(actor, float *, 0x48);
    actor = M2C_FIELD(arg0, int *, 0xC) * stride + man;
    actor += 0x2920;
    rot[0] = M2C_FIELD(actor, float *, 0x50);
    rot[1] = M2C_FIELD(actor, float *, 0x54);
    rot[2] = M2C_FIELD(actor, float *, 0x58);
    int n;
    float *p;
    switch(arg2) {
    case 0:
        M2C_FIELD(arg0, int *, 0x10) = arg3;
        n = Xiiu_func_001CBE38(&D_007812C0, arg3);
        p = (float *)(arg0 + 0x30);
        M2C_FIELD(arg0, int *, 0x14) = n;
        actor = n * stride + man;
        actor += 0x2920;
        p[0] = M2C_FIELD(actor, float *, 0x40);
        p[1] = M2C_FIELD(actor, float *, 0x44);
        p[2] = M2C_FIELD(actor, float *, 0x48);
        M2C_FIELD(arg0, RoundFnB63 *, 0x60) = roundFn0B63;
        goto move;
    case 1:
        M2C_FIELD(arg0, float *, 0x30) = M2C_FIELD(arg3, float *, 0);
        M2C_FIELD(arg0, float *, 0x34) = M2C_FIELD(arg3, float *, 4);
        M2C_FIELD(arg0, float *, 0x38) = M2C_FIELD(arg3, float *, 8);
        M2C_FIELD(arg0, RoundFnB63 *, 0x60) = roundFn1B63;
move:
        roundMoveB63(M2C_FIELD(arg0, int *, 0xC), arg4, 0, 0x100, arg1, 0, f2);
        break;
    case 2:
        M2C_FIELD(arg0, int *, 0x10) = arg3;
        n = Xiiu_func_001CBE38(&D_007812C0, arg3);
        p = (float *)(arg0 + 0x30);
        M2C_FIELD(arg0, int *, 0x14) = n;
        actor = n * stride + man;
        actor += 0x2920;
        p[0] = M2C_FIELD(actor, float *, 0x40);
        p[1] = M2C_FIELD(actor, float *, 0x44);
        p[2] = M2C_FIELD(actor, float *, 0x48);
        M2C_FIELD(arg0, RoundFnB63 *, 0x60) = roundFn2B63;
        goto follow;
    case 3:
        M2C_FIELD(arg0, float *, 0x30) = M2C_FIELD(arg3, float *, 0);
        M2C_FIELD(arg0, float *, 0x34) = M2C_FIELD(arg3, float *, 4);
        M2C_FIELD(arg0, float *, 0x38) = M2C_FIELD(arg3, float *, 8);
        M2C_FIELD(arg0, RoundFnB63 *, 0x60) = roundFn1B63;
follow:
        M2C_FIELD(arg0, int *, 0x68) = X_func_001F59B4_ee954(arg1, arg4, -1, 0x100, 0, f2, 32769.0f);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EB63C);
#endif

extern "C" void TskMoveTypeRound__vfunc_06(TskMoveTypeRound *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskMoveTypeRound;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveTypeRound__vfunc_05(void) {
}

// NON_MATCHING: 96/125 differ, 4 relocs differ (size 0x1F4, game 0x200), 54 edits
#ifdef NON_MATCHING
extern const char roundHitText[] asm("D_002FDBF0");
extern "C" int roundCheck(int, unsigned int, int *, int) asm("func_001D544C");
extern "C" int roundHit(int, int) asm("func_001D8ADC");
extern "C" void roundSet(int, int) asm("func_001D8A8C");
extern "C" void roundPrint(const char *, int) asm("func_00260110");
extern "C" int TskMoveTypeRound__vfunc_04(TskMoveTypeRound *obj)
{
    int out[8];
    int arg0 = (int)obj;
    u_long128 *pos = (u_long128 *)(arg0+0x40);
    (obj->*(obj->m_func))();
    int base = (int)&D_007812C0;
    u_long128 *old = (u_long128 *)(arg0+0x70);
    int ok = roundCheck(base, M2C_FIELD(arg0, unsigned int *, 8), out, 0);
    int actor = M2C_FIELD(arg0, int *, 4);
    int rot = arg0+0x50;
    if (((ok != 0) && (M2C_FIELD(actor, int *, 0x120) & 0x40)) || roundHit(actor, (int)pos) == 0) {
        roundPrint(roundHitText, out[4]);
        if ((M2C_FIELD(arg0, volatile int *, 0x18) ^ 1) & 1) {
            int a = M2C_FIELD(arg0, int *, 4);
            M2C_FIELD(a, int *, 0x120) |= 0x1000;
        }
        M2C_FIELD(arg0, volatile int *, 0x18) |= 1;
        *(u_long128 *)(arg0+0x40) = *old;
        int flags = M2C_FIELD(arg0, volatile int *, 0x18);
        if (!(flags & 2)) {
            M2C_FIELD(arg0, volatile int *, 0x18) = flags | 2;
            int a = M2C_FIELD(arg0, int *, 4);
            M2C_FIELD(arg0, float *, 0x24) = -M2C_FIELD(arg0, float *, 0x24);
            M2C_FIELD(a, int *, 0x120) &= ~0x1000;
        } else {
            unsigned int period = 60;
            if (M2C_FIELD(base, unsigned int *, 0x21F60) % period == 0) {
                M2C_FIELD(arg0, volatile int *, 0x18) = flags & ~2;
            }
        }
    } else {
        *old = *pos;
        int a = M2C_FIELD(arg0, int *, 4);
        M2C_FIELD(a, int *, 0x120) &= ~0x1000;
        if (M2C_FIELD(arg0, volatile int *, 0x18) & 1) {
            int b = M2C_FIELD(arg0, int *, 4);
            M2C_FIELD(b, int *, 0x120) &= ~0x1000;
        }
        M2C_FIELD(arg0, volatile int *, 0x18) &= ~1;
    }
    roundSet(M2C_FIELD(arg0, int *, 4), rot);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMoveTypeRound__vfunc_04);
#endif

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

extern "C" void func_001EBB80(TskMoveTypeRound *arg0) {
    float dist;
    float angle = Xfpff_func_002180E4(&dist, arg0->m_targetPos.f[0] - arg0->m_pos.f[0], arg0->m_targetPos.f[2] - arg0->m_pos.f[2]);
    float x, z;
    if (dist < arg0->m_unk1C - 10.0f) {
        x = Xff_sinf(angle) * arg0->m_unk28;
        z = Xff_cosf(angle) * arg0->m_unk28;
    } else if (arg0->m_unk1C + 10.0f < dist) {
        x = -Xff_sinf(angle) * arg0->m_unk28;
        z = -Xff_cosf(angle) * arg0->m_unk28;
    } else {
        x = z = 0.0f;
    }
    angle = arg0->m_unk24 < 0.0f ? angle + 1.57079632679489661923 : angle - 1.57079632679489661923;
    if(angle < -3.14159265358979323846) angle += 6.28318530717958647692;
    if(angle > 3.14159265358979323846) angle -= 6.28318530717958647692;
    arg0->m_rot.f[1] = angle;
    if (arg0->m_mode == 3) {
        float *pos = arg0->m_pos.f;
        M2C_FIELD(arg0->m_unk68, float *, 0x6C) = angle;
        DogActorStub *actor = (DogActorStub *)((char *)&D_006FE6A0 + arg0->m_chrID * 0x4D0);
        pos[0] = actor->unk40[0];
        pos[1] = actor->unk40[1];
        pos[2] = actor->unk40[2];
        arg0->m_pos.f[0] -= x;
        arg0->m_pos.f[2] -= z;
        return;
    }
    arg0->m_pos.f[0] += Xff_sinf(angle) * arg0->m_unk28;
    arg0->m_pos.f[2] += Xff_cosf(angle) * arg0->m_unk28;
    arg0->m_pos.f[0] += x;
    arg0->m_pos.f[2] += z;
}

// NON_MATCHING: 108/190 differ, 14 relocs differ (size 0x2F8, game 0x2FC), 25 edits
#ifdef NON_MATCHING
extern unsigned int tickBDE8 asm("D_007A3220");
static inline int actorAddrBDE8(int base, int n) { return n * 0x4D0 + base + 0x2920; }
extern "C" void func_001EBDE8(int arg0) {
    register int manBase PS2_REG("$18") = (int)&D_006FBD80;
    volatile float predicted[4];
    float dist;
    float *pos = (float *)(arg0 + 0x30);
    int actor = (int)&D_006FE6A0 + M2C_FIELD(arg0, int *, 0x14) * 0x4D0;
    pos[0] = M2C_FIELD(actor, float *, 0x40);
    pos[1] = M2C_FIELD(actor, float *, 0x44);
    pos[2] = M2C_FIELD(actor, float *, 0x48);
    float angle = Xfpff_func_002180E4(&dist, pos[0] - M2C_FIELD(arg0, float *, 0x40), M2C_FIELD(arg0, float *, 0x38) - M2C_FIELD(arg0, float *, 0x48));
    float x, z;
    float c;
    if (dist < M2C_FIELD(arg0, float *, 0x1C) - 10.0f) {
        x = -Xff_sinf(angle) * M2C_FIELD(arg0, float *, 0x28);
        z = -Xff_cosf(angle) * M2C_FIELD(arg0, float *, 0x28);
    } else if (M2C_FIELD(arg0, float *, 0x1C) + 10.0f < dist) {
        x = Xff_sinf(angle) * M2C_FIELD(arg0, float *, 0x28);
        z = Xff_cosf(angle) * M2C_FIELD(arg0, float *, 0x28);
    } else {
        x = z = 0.0f;
    }
angle_part:
    angle = M2C_FIELD(arg0, float *, 0x24) < 0.0f ? angle + 1.57079632679489661923 : angle - 1.57079632679489661923;
    int addr = M2C_FIELD(arg0, int *, 0xC) * 0x4D0 + manBase;
    addr += 0x2920;
    DogActorStub *other = (DogActorStub *)addr;
    float pz = other->unk40[2] + z;
    float px = other->unk40[0] + x;
    predicted[1] = other->unk40[1];
    predicted[2] = pz;
    predicted[0] = px;
    if(angle < -3.14159265358979323846) angle += 6.28318530717958647692;
    if(angle > 3.14159265358979323846) angle -= 6.28318530717958647692;
    if((x != 0.0f || z != 0.0f) && !(M2C_FIELD(arg0, int *, 0x18) & 4)) {
        angle = yawC0(M2C_FIELD(arg0, float *, 0x30) - px, M2C_FIELD(arg0, float *, 0x38) - pz);
        M2C_FIELD(arg0, int *, 0x18) |= 4;
    } else {
        unsigned int period = 180;
        if((*(unsigned int *)&tickBDE8 % period) == 0) M2C_FIELD(arg0, int *, 0x18) &= ~4;
    }
    M2C_FIELD(arg0, float *, 0x54) = angle;
    M2C_FIELD(M2C_FIELD(arg0, int *, 0x68), float *, 0x6C) = angle;
    float *out = (float *)(arg0 + 0x40);
    addr = M2C_FIELD(arg0, int *, 0xC) * 0x4D0 + manBase;
    addr += 0x2920;
    other = (DogActorStub *)addr;
    out[0] = other->unk40[0];
    out[1] = other->unk40[1];
    out[2] = other->unk40[2];
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EBDE8);
#endif



























INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD28);

extern "C" void func_001EC0E4(TskMoveTypeRound *arg0) {
    float dist;
    float *pos = arg0->m_targetPos.f;
    DogActorStub *actor = (DogActorStub *)((char *)&D_006FE6A0 + arg0->m_targetChrID * 0x4D0);
    pos[0] = actor->unk40[0];
    pos[1] = actor->unk40[1];
    pos[2] = actor->unk40[2];
    float angle = Xfpff_func_002180E4(&dist, pos[0] - arg0->m_pos.f[0], arg0->m_targetPos.f[2] - arg0->m_pos.f[2]);
    float x, z;
    if (dist < arg0->m_unk1C - 10.0f) {
        x = -Xff_sinf(angle) * arg0->m_unk28;
        z = -Xff_cosf(angle) * arg0->m_unk28;
    } else if (arg0->m_unk1C + 10.0f < dist) {
        x = Xff_sinf(angle) * arg0->m_unk28;
        z = Xff_cosf(angle) * arg0->m_unk28;
    } else {
        x = z = 0.0f;
    }
    angle = arg0->m_unk24 < 0.0f ? angle + 1.57079632679489661923 : angle - 1.57079632679489661923;
    if(angle < -3.14159265358979323846) angle += 6.28318530717958647692;
    if(angle > 3.14159265358979323846) angle -= 6.28318530717958647692;
    arg0->m_rot.f[1] = angle;
    arg0->m_pos.f[0] += Xff_sinf(angle) * arg0->m_unk28 + x;
    arg0->m_pos.f[2] += Xff_cosf(angle) * arg0->m_unk28 + z;
    if(x != 0.0f && z != 0.0f) arg0->m_rot.f[1] = yawC0(arg0->m_targetPos.f[0] - arg0->m_pos.f[0], arg0->m_targetPos.f[2] - arg0->m_pos.f[2]);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDD78);

// NON_MATCHING: 3/150 differ, 2 edits
#ifdef NON_MATCHING
struct PathFnCopy { int w[2]; };
extern const PathFnCopy D_002FDD60, D_002FDD68, D_002FDD70, D_002FDD78;
extern "C" void func_001EC344(TskMovePointPath *arg0, int arg1, unsigned int arg2, int arg3, int arg4, void *arg5, float fparg0, float fparg1) {
    int temp_a1;
    unsigned int temp_v1;
    float *p40;
    float *p50;
    ObjStat *temp_v0;
    struct DogActorStub *d;

    *(void **)arg0 = vtbl_TskMovePointPath;
    arg0->m_oid = arg1;
    temp_v0 = Xiiu_func_001D2B8C(&D_007812C0, arg1);
    p40 = arg0->m_pos.f;
    arg0->m_obj = temp_v0;
    p50 = arg0->m_rot.f;
    temp_a1 = temp_v0->getChrID();
    arg0->m_unk30 = arg2;
    arg0->m_unk14 = temp_a1;
    arg0->m_chrID = arg4;
    arg0->m_unk2C = fparg0;
    arg0->m_unk7C = (int)arg5;
    arg0->m_unk18 = arg3;
    arg0->m_unk80 = fparg1;
    d = getDogActor(&D_006FBD80, temp_a1);
    arg0->m_unk1C = 0;
    arg0->m_unk78 = 0;
    p40[0] = d->unk40[0];
    p40[1] = d->unk40[1];
    p40[2] = d->unk40[2];
    d = getDogActor(&D_006FBD80, arg0->m_unk14);
    p50[0] = d->unk50[0];
    p50[1] = d->unk50[1];
    p50[2] = d->unk50[2];
    temp_v1 = (unsigned int)arg0->m_unk30;
    switch (temp_v1) {
    case 0:
    case 4:
        arg0->m_points = (float *)arg0->m_chrID;
        *(PathFnCopy *)&arg0->m_func = D_002FDD60;
        break;
    case 1:
    case 5:
        arg0->m_points = (float *)arg0->m_chrID;
        *(PathFnCopy *)&arg0->m_func = D_002FDD68;
        break;
    case 2:
    case 6:
        arg0->m_points = (float *)(arg0->m_chrID + ((Xi_rand() % arg0->m_unk18) * 8));
        *(PathFnCopy *)&arg0->m_func = D_002FDD70;
        break;
    case 3:
    case 7:
        arg0->m_points = (float *)(arg0->m_chrID + ((Xi_rand() % arg0->m_unk18) * 8));
        *(PathFnCopy *)&arg0->m_func = D_002FDD78;
        break;
    }
    if (arg0->m_unk30 < 4) {
        ecbe0Move(arg0->m_unk14, arg0->m_unk7C, 0, 0x100, arg1, 0, arg0->m_unk80);
    }
    return Xv_func_001EC834_mpp(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EC344);
#endif

extern "C" void TskMovePointPath__vfunc_06(TskMovePointPath *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskMovePointPath;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMovePointPath__vfunc_05(void) {
}

extern "C" int TskMovePointPath__vfunc_04(TskMovePointPath *arg0)
{
    if (arg0->m_unk20 > 0) {
        if (arg0->m_unk30 < 4) {
            Xv_func_0025B878(arg0->m_pos.f, arg0->m_pos.f, arg0->m_vel.f);
        } else {
            Xvp_func_001D890C((int)arg0->m_obj, (int)arg0->m_pos.f);
        }
        if (Xiii_func_001D8ADC_mpp((int)arg0->m_obj, (int)arg0->m_pos.f) != 0) {
            arg0->m_unk20--;
        }
        return 0;
    }
    if ((arg0->*(arg0->m_func))() != 0) {
        Xv_func_001F59B4_mpp(arg0->m_oid, 1, -1, 0x100, 0, arg0->m_unk80, 32769.0f);
        return 1;
    }
    Xv_func_001EC834_mpp(arg0);
    return 0;
}

extern "C" int func_001EC6E8(TskMovePointPath *arg0)
{
    int limit = arg0->m_unk18 - 1;
    if (arg0->m_unk1C++ < limit) {
        arg0->m_points += 2;
        return 0;
    }
    return 1;
}

extern "C" int func_001EC72C(TskMovePointPath *arg0)
{
    int limit = arg0->m_unk18 - 1;
    if (arg0->m_unk1C++ < limit) {
        arg0->m_points += 2;
    } else {
        arg0->m_unk1C = 0;
        arg0->m_points = (float *)arg0->m_chrID;
    }
    return 0;
}

extern "C" int func_001EC774(TskMovePointPath *arg0)
{
    int old = arg0->m_unk1C++;

    if (old < arg0->m_unk18) {
        arg0->m_points = (float *)(arg0->m_chrID + ((Xi_rand() % arg0->m_unk18) * 8));
        return 0;
    }
    return 1;
}

extern "C" int func_001EC7E8(TskMovePointPath *arg0)
{
    arg0->m_points = (float *)(arg0->m_chrID + ((X_rand() % arg0->m_unk18) * 8));
    return 0;
}


extern "C" void func_001EC834(TskMovePointPath *arg0)
{
    float dist;
    float angle;
    float *p;
    TskVec4 *pos = &arg0->m_pos;

    Xv_func_001D05F4(&D_007812C0, arg0->m_oid, pos);
    p = arg0->m_points;
    angle = Xfpff_func_002180E4(&dist, p[0] - pos->f[0], p[1] - arg0->m_pos.f[2]);
    if (arg0->m_unk30 < 4) {
        float s = Xff_sinf(angle);
        M2C_FIELD(&arg0->m_vel, int *, 4) = 0;
        arg0->m_vel.f[0] = s * arg0->m_unk2C;
        float c = Xff_cosf(angle) * arg0->m_unk2C;
        int steps = (int)(dist / arg0->m_unk2C);
        arg0->m_rot.f[1] = angle;
        arg0->m_vel.f[2] = c;
        arg0->m_unk20 = steps;
        Xv_func_001CFE78((int)&D_007812C0, arg0->m_oid, (int)&arg0->m_rot);
    } else {
        arg0->m_unk20 = Xiu_func_001EE7F0(
            arg0->m_oid,
            (unsigned short)arg0->m_unk14,
            (int)&arg0->m_unk78,
            angle,
            dist,
            arg0->m_unk7C,
            arg0->m_unk80);
    }
}

// NON_MATCHING: 38/155 differ, 2 relocs differ (size 0x26C, game 0x264), 23 edits
#ifdef NON_MATCHING
extern "C" int X_func_001D2B8C(...) asm("func_001D2B8C");
extern "C" int X_func_001D7B08(...) asm("func_001D7B08");
extern "C" int X_func_001D81F0(...) asm("func_001D81F0");
extern "C" int X_func_001DA228(...) asm("func_001DA228");
extern "C" int pathInit940(int) asm("func_001ED1D0");
extern "C" int X_func_001F6878(...) asm("func_001F6878");
extern int D_002FDDA0;
extern int D_002FDDA8;
extern int D_002FDDB0;
extern "C" void func_001EC940(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, float fparg0)
{
    float temp_f1;
    int temp_v0_3;
    int temp_v1;
    int temp_a0;
    int temp_v0_2;
    int var_v1;
    int temp_v0;

    M2C_FIELD(arg0, void **, 0) = vtbl_TskMoveSectaFindPath;
    M2C_FIELD(arg0, int *, 8) = arg1;
    temp_v0 = X_func_001D2B8C_f1670((int)&D_007812C0, arg1);
    M2C_FIELD(arg0, int *, 4) = temp_v0;
    M2C_FIELD(arg0, int *, 0xC) = (int) M2C_FIELD(temp_v0, int *, 0x108);
    X_func_001DA228(temp_v0, 0x1100, arg0 + 0x29C);
    X_func_001DA228(M2C_FIELD(arg0, int *, 4), 0x1103, arg0 + 0x2A0);
    X_func_001DA228(M2C_FIELD(arg0, int *, 4), 0x1101, arg0 + 0x2AC);
    X_func_001DA228(M2C_FIELD(arg0, int *, 4), 0x1102, arg0 + 0x2B0);
    X_func_001DA228(M2C_FIELD(arg0, int *, 4), 0x1105, arg0 + 0x2B4);
    X_func_001DA228(M2C_FIELD(arg0, int *, 4), 0x1104, arg0 + 0x2A4);
    temp_v0_2 = X_func_001F6878(M2C_FIELD(arg0, int *, 8));
    if (temp_v0_2 != 0) {
        M2C_FIELD(arg0, int *, 0x224) = X_func_001D7B08((int)&D_007812C0, M2C_FIELD(arg0, int *, 8), temp_v0_2);
    } else {
        temp_v0_3 = M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x114);
        var_v1 = -1;
        if (temp_v0_3 != 0) {
            var_v1 = (*(int *)(temp_v0_3));
        }
        M2C_FIELD(arg0, int *, 0x224) = var_v1;
    }
    M2C_FIELD(arg0, int *, 0x228) = arg2;
    temp_f1 = M2C_FIELD(arg0, float *, 0x2A0) * (1.0f / 60.0f);
    M2C_FIELD(arg0, float *, 0x230) = fparg0;
    M2C_FIELD(arg0, int *, 0x290) = arg3;
    M2C_FIELD(arg0, int *, 0x218) = 0;
    M2C_FIELD(arg0, int *, 0x21C) = 0;
    M2C_FIELD(arg0, int *, 0x298) = arg5;
    M2C_FIELD(arg0, int *, 0x294) = 0;
    M2C_FIELD(arg0, float *, 0x2A0) = temp_f1;
    if ((arg5 > 0) && (!(temp_f1 > 0.0001f) || !(temp_f1 < 1.0f))) {
        M2C_FIELD(arg0, float *, 0x2A0) = (1.0f / 60.0f);
    }
    X_func_001D81F0((int)&D_007812C0, X_func_001F6878(arg1), M2C_FIELD(arg0, int *, 0x224), M2C_FIELD(arg0, int *, 0x228), arg0 + 0x10);
    if (M2C_FIELD(arg0, int *, 0x20C) > 0) {
        pathInit940(arg0);
    } else {
        temp_v1 = M2C_FIELD(arg0, int *, 0x290);
        if (temp_v1 != 0) *(int *)temp_v1 = 4;
    }
    if (M2C_FIELD(arg0, int *, 0x298) > 0) {
        *(m2c_block8 *)((char *)(arg0) + 696) = *(m2c_block8 *)((char *)(&D_002FDDA0) + 0);
        return;
    }
    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0x120);
    bool flag40 = temp_a0 & 0x40;
    bool flag80 = temp_a0 & 0x80;
    if (flag40 && !flag80) {
        *(m2c_block8 *)((char *)(arg0) + 696) = *(m2c_block8 *)((char *)(&D_002FDDA8) + 0);
        return;
    }
    *(m2c_block8 *)((char *)(arg0) + 696) = *(m2c_block8 *)((char *)(&D_002FDDB0) + 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EC940);
#endif

extern "C" void TskMoveSectaFindPath__vfunc_06(TskMoveSectaFindPath *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskMoveSectaFindPath;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveSectaFindPath__vfunc_05(void) {
}

extern "C" int func_001ECBE0(TskMoveSectaFindPath *arg0)
{
    float dist, angle;
    if (X_func_001E7D7C_ecf3c((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) != 0 || (unsigned int)arg0->m_cnt == 1) {
        ecbe0Stop((int)arg0->m_obj, (int)&arg0->m_rot);
        arg0->m_cnt = 2;
    } else {
        arg0->m_unk294 = 0;
        DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
        float *pos = arg0->m_pos.f;
        pos[0] = d->unk40[0]; pos[1] = d->unk40[1]; pos[2] = d->unk40[2];
        M2C_FIELD(&arg0->m_rot, int *, 0) = 0;
        arg0->m_rot.f[1] = Xfi_func_0010A650__8DogActor((int)getDogActor(&D_006FBD80, arg0->m_chrID));
        M2C_FIELD(&arg0->m_rot, int *, 8) = 0;
        register int target PS2_REG("$2") = (int)arg0;
        target += arg0->m_unk218*4;
        target = M2C_FIELD(target, int *, 0x10);
        angle = X_func_002180E4_ecf3c(&dist, M2C_FIELD(target, float *, 0x10) - pos[0], M2C_FIELD(target, float *, 0x18) - arg0->m_pos.f[2]);
        if (arg0->m_unk298 <= 0) {
            float speed0 = arg0->m_unk230.f[0];
            float zero = 0.0f;
            if (speed0 == zero) arg0->m_unk230.f[0] = 1.0f;
            float sn = Xff_sinf(angle) * arg0->m_unk230.f[0];
            arg0->m_vel.f[1] = zero;
            arg0->m_vel.f[0] = sn;
            float cs = Xff_cosf(angle) * arg0->m_unk230.f[0];
            float frames = dist / arg0->m_unk230.f[0];
            arg0->m_vel.f[2] = cs;
            arg0->m_cnt = (int)frames;
            ecbe0Move(arg0->m_chrID, arg0->m_unk29C, 0, 0x100, arg0->m_oid, 0, arg0->m_unk2A0);
        } else {
            arg0->m_cnt = X_func_001EE7F0_ecf3c(arg0->m_oid, (unsigned short)arg0->m_chrID, angle, dist, &arg0->m_unk294, arg0->m_unk29C, arg0->m_unk2A0);
        }
        int actor = arg0->m_oid;
        float speed = arg0->m_unk2A4;
        if (arg0->m_unk298 <= 0) { ecbe0Yaw(actor, angle, speed); return 0; }
        else X_func_001F11A0_ecf3c(actor, arg0->m_rot.f[1], angle, speed);
    }
    return 0;
}

// NON_MATCHING: 39/60 differ, 5 relocs differ (size 0xF0, game 0xE8)
#ifdef NON_MATCHING
extern "C" int X_func_00260110(const char *fmt, ...) asm("func_00260110");
extern "C" int Xiii_func_001D8ADC(int a, int b) asm("func_001D8ADC");
extern "C" int Xiiuii_func_001D544C(int a, unsigned int b, int c, int d) asm("func_001D544C");
extern "C" int func_001ECDD4(TskMoveSectaFindPath *arg0)
{
    extern const char D_002FDBF0[];
    int out[8];
    TskVec4 *pos = &arg0->m_pos;

    if ((arg0->m_unk2A8 & 1) != 0) {
        if (X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) != 0) {
            return 0;
        }
    }
    if (Xiiuii_func_001D544C((int)&D_007812C0, arg0->m_oid, (int)out, 0) != 0) {
        *pos = arg0->m_prevPos;
        X_func_00260110(D_002FDBF0, out[4]);
        return 0;
    }
    Xv_func_0025B878((int)pos, (int)pos, (int)&arg0->m_vel);
    if (Xiii_func_001D8ADC((int)arg0->m_obj, (int)pos) != 0) {
        arg0->m_cnt--;
        arg0->m_prevPos = *pos;
        return 0;
    }
    X_func_001ED1D0(arg0);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ECDD4);
#endif

extern "C" int func_001ECEBC(TskMoveSectaFindPath *arg0)
{
    TskVec4 *pos = &arg0->m_pos;

    if ((arg0->m_unk2A8 & 1) != 0) {
        if (X_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) != 0) {
            return 0;
        }
    }
    Xv_func_0025B878(pos, pos, &arg0->m_vel);
    Xvii_func_001D8B9C((int)arg0->m_obj, (int)pos);
    arg0->m_cnt = arg0->m_cnt - 1;
    return 0;
}

extern "C" int func_001ECF3C(TskMoveSectaFindPath *arg0)
{
    float dist;
    float ang;
    int cnt;

    if (arg0->m_unk2A8 & 1) {
        if (arg0->m_unk2A8 & 2) {
            if (X_func_001E7D7C_ecf3c((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) == 0) {
                int a = arg0->m_unk294;
                arg0->m_unk2A8 &= ~2;
                M2C_FIELD(a, int *, 4) &= ~1;
            }
        } else if (X_func_001E7D7C_ecf3c((int)&D_007A3D80, M2C_FIELD(arg0->m_obj, int *, 0x3D8)) != 0) {
            int b = arg0->m_unk294;
            arg0->m_unk2A8 |= 2;
            M2C_FIELD(b, int *, 4) |= 1;
        }
    }
    if (arg0->m_cnt < arg0->m_halfCnt) {
        {
            struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
            float *p = arg0->m_pos.f;
            p[0] = d->unk40[0];
            p[1] = d->unk40[1];
            p[2] = d->unk40[2];
        }
        ang = X_func_002180E4_ecf3c(&dist, arg0->m_targetPos.f[0] - arg0->m_pos.f[0], arg0->m_targetPos.f[2] - arg0->m_pos.f[2]);
        arg0->m_cnt = X_func_001EE7F0_ecf3c(
            arg0->m_oid,
            (unsigned short)arg0->m_chrID,
            ang,
            dist,
            &arg0->m_unk294,
            arg0->m_unk29C,
            arg0->m_unk2A0);
        {
            struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
            float *p = arg0->m_rot.f;
            p[0] = d->unk50[0];
            p[1] = d->unk50[1];
            p[2] = d->unk50[2];
        }
        X_func_001F11A0_ecf3c(arg0->m_oid, arg0->m_rot.f[1], ang, 1.0f);
        cnt = arg0->m_cnt;
        if (cnt >= 6) {
            arg0->m_halfCnt = cnt / 2;
        } else {
            arg0->m_halfCnt = 0;
        }
    }
    arg0->m_cnt--;
    return 0;
}

extern "C" int TskMoveSectaFindPath__vfunc_04(TskMoveSectaFindPath *arg0)
{
    if (arg0->m_cnt > 0) {
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

// NON_MATCHING: 101/213 differ, 8 relocs differ (size 0x354, game 0x370), 48 edits
#ifdef NON_MATCHING
extern "C" void sectaCreateEd998(int, int, int, int, int, int, int, float, float) asm("func_001EC940");
extern "C" void moveCreateEd998(int, int, int, int, int, float, float) asm("func_001E9A3C");
extern "C" int randEd998() asm("rand");
extern "C" int sectaFindEd998(int, int, int) asm("func_001D7B08");
extern "C" int sectaGetEd998(int) asm("func_001F6878");
extern "C" void func_001ED998(int arg0, int arg1, int arg2, int arg3, int a4, int a5, float fparg0, float fparg1) {
    register int arg4 PS2_REG("$18") = a4;
    register int arg5 PS2_REG("$17") = a5;
    int temp_s0;
    int var_a3;
    int temp_s4;
    int temp_s6;
    int temp_v0_2;
    int var_a2;
    int var_a2_2;
    int temp_v0;
    int temp_v0_3;
    int var_a0;
    int var_a0_2;
    register int var_s0 PS2_REG("$16");
    int var_s0_2;

    temp_s6 = arg2 < 6;
    M2C_FIELD(arg0, int *, 8) = arg1;
    temp_s4 = temp_s6 == 0;
    M2C_FIELD(arg0, void **, 0) = vtbl_TskMoveSecta;
    temp_v0 = X_func_001D2B8C_f1670((int)&D_007812C0, arg1);
    M2C_FIELD(arg0, int *, 4) = temp_v0;
    M2C_FIELD(arg0, int *, 0x3C) = arg3;
    M2C_FIELD(arg0, int *, 0x14) = (int) M2C_FIELD(temp_v0, int *, 0x108);
    M2C_FIELD(arg0, float *, 0x2C) = fparg0;
    M2C_FIELD(arg0, int *, 0x18) = arg4;
    M2C_FIELD(arg0, int *, 0x40) = arg5;
    M2C_FIELD(arg0, float *, 0x44) = fparg1;
    M2C_FIELD(arg0, int *, 0x10) = (int ) (temp_v0 + 0x3E0);
    M2C_FIELD(arg0, int *, 0x38) = arg3;
    M2C_FIELD(arg0, int *, 0x30) = arg2;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    switch (arg2) {
    case 0:
    case 1:
    case 6:
    case 7:
        M2C_FIELD(arg0, int *, 0x1C) = (int ) M2C_FIELD(arg0, int *, 0x18);
        var_s0 = X___builtin_new_f1670(0x2C0);
        var_a2 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x18), int *, 0);
        var_a0 = var_s0;
        var_a3 = arg0 + 0xC;
        sectaCreateEd998(var_a0, M2C_FIELD(arg0, int *, 8), var_a2, var_a3, M2C_FIELD(arg0, int *, 0x40), temp_s4, 0x20, M2C_FIELD(arg0, float *, 0x2C), M2C_FIELD(arg0, float *, 0x44));
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, var_s0, 0, M2C_FIELD(arg0, int *, 0x10), 0x11);
    default:
        break;
    case 2:
    case 3:
    case 8:
    case 9:
        M2C_FIELD(arg0, int *, 0x1C) = (int ) M2C_FIELD(arg0, int *, 0x18);
        var_s0 = X___builtin_new_f1670(0x2C0);
        var_a0 = var_s0;
        var_a2 = *(int *)(((randEd998() % M2C_FIELD(arg0, int *, 0x38)) * 4) + M2C_FIELD(arg0, int *, 0x18));
        var_a3 = arg0 + 0xC;
        sectaCreateEd998(var_a0, M2C_FIELD(arg0, int *, 8), var_a2, var_a3, M2C_FIELD(arg0, int *, 0x40), temp_s4, 0x20, M2C_FIELD(arg0, float *, 0x2C), M2C_FIELD(arg0, float *, 0x44));
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, var_s0, 0, M2C_FIELD(arg0, int *, 0x10), 0x11);
        break;
    case 4:
    case 5:
    case 10:
    case 11:
        temp_s0 = (int)&D_007812C0;
        temp_v0_2 = sectaFindEd998(temp_s0, M2C_FIELD(arg0, int *, 0x18), sectaGetEd998(M2C_FIELD(arg0, int *, 8)));
        if (temp_v0_2 != -1) {
            if (sectaFindEd998(temp_s0, M2C_FIELD(arg0, int *, 8), sectaGetEd998(M2C_FIELD(arg0, int *, 8))) == temp_v0_2) {
                if (temp_s6 != 0) {
                    var_s0_2 = X___builtin_new_f1670(0xC0);
                    moveCreateEd998(var_s0_2, M2C_FIELD(arg0, int *, 8), 3, M2C_FIELD(arg0, int *, 0x18), 0, 1.0f, 0.016666667f);
                } else {
                    var_s0_2 = X___builtin_new_f1670(0xC0);
                    moveCreateEd998(var_s0_2, M2C_FIELD(arg0, int *, 8), 11, M2C_FIELD(arg0, int *, 0x18), 0, 1.0f, 0.016666667f);
                }
                X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, var_s0_2, 0, M2C_FIELD(arg0, int *, 0x10), 0x11);
            } else {
                temp_v0_3 = X___builtin_new_f1670(0x2C0);
                sectaCreateEd998(temp_v0_3, M2C_FIELD(arg0, int *, 8), temp_v0_2, arg0 + 0xC, M2C_FIELD(arg0, int *, 0x40), temp_s4, 0x20, M2C_FIELD(arg0, float *, 0x2C), M2C_FIELD(arg0, float *, 0x44));
                X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_3, 0, M2C_FIELD(arg0, int *, 0x10), 0x11);
            }
        } else {
            M2C_FIELD(arg0, int *, 0xC) = (int) (M2C_FIELD(arg0, int *, 0xC) | 4);
        }
        if ((arg2 == 5) || (arg2 == 0xB)) {
            if (M2C_FIELD(arg0, int *, 0x38) < 0xA) {
                M2C_FIELD(arg0, int *, 0x38) = 0xA;
            }
            M2C_FIELD(arg0, int *, 0xC) = (int) (M2C_FIELD(arg0, int *, 0xC) | 8);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ED998);
#endif

extern "C" void TskMoveSecta__vfunc_06(TskMoveSecta *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskMoveSecta;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveSecta__vfunc_05(TskMoveSecta *arg0)
{
    if (X_func_001E7D7C((int)&D_007A3D80, *(int *)arg0->m_unk10) != 0) {
        X_func_001E7724((int)&D_007A3D80, *(int *)arg0->m_unk10);
    }
}


// NON_MATCHING: 307/318 differ, 32 relocs differ (size 0x4F8, game 0x56C), 189 edits
#ifdef NON_MATCHING
extern "C" void sCreate(int,int,int,int,int,int,int,float,float) asm("func_001EC940");
extern "C" void sMove(int,int,int,int,int,float,float) asm("func_001E9A3C");
extern "C" void sFinish(int,int,int,int,int,float,float) asm("func_001F59B4");
extern "C" int sFind(int,int,int) asm("func_001D7B08");
extern "C" int sGet(int) asm("func_001F6878");
extern "C" int sRand() asm("rand");
extern "C" int TskMoveSecta__vfunc_04(int arg0) {
    float var_f12;
    int temp_v0_3;
    int var_a3;
    int temp_a0;
    int temp_s4;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v0_7;
    int temp_v1;
    int temp_v1_2;
    int var_a2;
    int var_v0;
    int temp_v0_8;
    int var_a0;
    int var_s0;
    int var_s0_2;

    temp_v1 = M2C_FIELD(arg0, int *, 0x30);
    temp_s4 = (temp_v1 < 6) == 0;
    temp_a0 = M2C_FIELD(arg0, int *, 0xC);
    if (temp_a0 != 0) {
        if (temp_a0 & 8) {
            temp_v0 = M2C_FIELD(arg0, int *, 0x3C)--;
            if (temp_v0 <= 0) {
                if (X_func_001E7D7C((int)&D_007A3D80, *(int *)M2C_FIELD(arg0, int *, 0x10)) != 0) {
                    X_func_001E7724((int)&D_007A3D80, *(int *)M2C_FIELD(arg0, int *, 0x10));
                }
                M2C_FIELD(arg0, int *, 0x3C) = (int) M2C_FIELD(arg0, int *, 0x38);
                var_v0 = (M2C_FIELD(arg0, int *, 0xC) & ~8) | 2;
                goto block_43;
            }
            goto block_44;
        }
        if (temp_a0 & 2) {
            M2C_FIELD(arg0, int *, 0xC) = (int) ((temp_a0 & ~2) | 1);
            return 0;
        }
        switch (temp_v1) {
        case 0:
        case 6:
            temp_v0_2 = M2C_FIELD(arg0, int *, 0x3C) - 1;
            M2C_FIELD(arg0, int *, 0x3C) = temp_v0_2;
            if (temp_v0_2 > 0) {
                M2C_FIELD(arg0, int *, 0xC) = 0;
                var_s0 = X___builtin_new_f1670(0x2C0);
                temp_v0_3 = M2C_FIELD(arg0, int *, 0x1C);
                M2C_FIELD(arg0, int *, 0x1C) = (int) (temp_v0_3 + 4);
                var_a0 = var_s0;
                var_a3 = arg0 + 0xC;
                var_a2 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0);
block_21:
                sCreate(var_a0, M2C_FIELD(arg0, int *, 8), var_a2, var_a3, M2C_FIELD(arg0, int *, 0x40), temp_s4, 0x20, M2C_FIELD(arg0, float *, 0x2C), M2C_FIELD(arg0, float *, 0x44));
                X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, var_s0, 0, M2C_FIELD(arg0, int *, 0x10), 0x11);
                goto block_44;
            }
block_17:
            sFinish(M2C_FIELD(arg0, int *, 8), 1, -1, 0x100, 0, M2C_FIELD(arg0, float *, 0x44) * 0.016666666f, 32769.0f);
            return 1;
        case 1:
        case 7:
            temp_v0_4 = M2C_FIELD(arg0, int *, 0x3C) - 1;
            M2C_FIELD(arg0, int *, 0x3C) = temp_v0_4;
            if (temp_v0_4 > 0) {
                M2C_FIELD(arg0, int *, 0x1C) = (int) (M2C_FIELD(arg0, int *, 0x1C) + 4);
            } else {
                M2C_FIELD(arg0, int *, 0x3C) = (int) M2C_FIELD(arg0, int *, 0x38);
                M2C_FIELD(arg0, int *, 0x1C) = (int) M2C_FIELD(arg0, int *, 0x18);
            }
            M2C_FIELD(arg0, int *, 0xC) = 0;
            var_s0 = X___builtin_new_f1670(0x2C0);
            var_a2 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x1C), int *, 0);
            var_a0 = var_s0;
            var_a3 = arg0 + 0xC;
            goto block_21;
        case 2:
        case 8:
            temp_v0_5 = M2C_FIELD(arg0, int *, 0x3C) - 1;
            M2C_FIELD(arg0, int *, 0x3C) = temp_v0_5;
            if (temp_v0_5 <= 0) {
                goto block_17;
            }
block_20:
            M2C_FIELD(arg0, int *, 0xC) = 0;
            var_s0 = X___builtin_new_f1670(0x2C0);
            var_a0 = var_s0;
            var_a3 = arg0 + 0xC;
            var_a2 = *(int *)(((sRand() % (int) M2C_FIELD(arg0, int *, 0x38)) * 4) + M2C_FIELD(arg0, int *, 0x18));
            goto block_21;
        case 3:
        case 9:
            temp_v0_6 = M2C_FIELD(arg0, int *, 0x3C) - 1;
            M2C_FIELD(arg0, int *, 0x3C) = temp_v0_6;
            if (temp_v0_6 <= 0) {
                M2C_FIELD(arg0, int *, 0x3C) = (int) M2C_FIELD(arg0, int *, 0x38);
            }
            goto block_20;
        case 4:
        case 5:
        case 10:
        case 11:
            if (temp_a0 & 4) {
                var_f12 = M2C_FIELD(arg0, float *, 0x44) * 0.016666666f;
                goto block_28;
            }
            temp_v0_7 = sFind((int)&D_007812C0, M2C_FIELD(arg0, int *, 0x18), sGet(M2C_FIELD(arg0, int *, 8)));
            if (temp_v0_7 != -1) {
                if (X_func_001E7D7C((int)&D_007A3D80, *(int *)M2C_FIELD(arg0, int *, 0x10)) != 0) {
                    X_func_001E7724((int)&D_007A3D80, *(int *)M2C_FIELD(arg0, int *, 0x10));
                }
                if (sFind((int)&D_007812C0, M2C_FIELD(arg0, int *, 8), sGet(M2C_FIELD(arg0, int *, 8))) == temp_v0_7) {
                    if (sFind((int)&D_007812C0, M2C_FIELD(arg0, int *, 8), sGet(M2C_FIELD(arg0, int *, 8))) == temp_v0_7) {
                        if (M2C_FIELD(arg0, int *, 0x30) < 6) {
                            var_s0_2 = X___builtin_new_f1670(0xC0);
                            sMove(var_s0_2, M2C_FIELD(arg0, int *, 8), 3, M2C_FIELD(arg0, int *, 0x18), M2C_FIELD(arg0, int *, 0x40), 1.0f, M2C_FIELD(arg0, float *, 0x44));
                        } else {
                            var_s0_2 = X___builtin_new_f1670(0xC0);
                            sMove(var_s0_2, M2C_FIELD(arg0, int *, 8), 0xB, M2C_FIELD(arg0, int *, 0x18), M2C_FIELD(arg0, int *, 0x40), 1.0f, M2C_FIELD(arg0, float *, 0x44));
                        }
                    } else {
                        var_s0_2 = X___builtin_new_f1670(0x2C0);
                        sCreate(var_s0_2, M2C_FIELD(arg0, int *, 8), temp_v0_7, arg0 + 0xC, M2C_FIELD(arg0, int *, 0x40), temp_s4, 0x20, M2C_FIELD(arg0, float *, 0x2C), M2C_FIELD(arg0, float *, 0x44));
                    }
                    X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, var_s0_2, 0, M2C_FIELD(arg0, int *, 0x10), 0x11);
                } else {
                    temp_v0_8 = X___builtin_new_f1670(0x2C0);
                    sCreate(temp_v0_8, M2C_FIELD(arg0, int *, 8), temp_v0_7, arg0 + 0xC, M2C_FIELD(arg0, int *, 0x40), temp_s4, 0x20, M2C_FIELD(arg0, float *, 0x2C), M2C_FIELD(arg0, float *, 0x44));
                    X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_8, 0, M2C_FIELD(arg0, int *, 0x10), 0x11);
                }
                M2C_FIELD(arg0, int *, 0xC) = 0;
            } else {
                var_f12 = M2C_FIELD(arg0, float *, 0x44) * 0.016666666f;
block_28:
                sFinish(M2C_FIELD(arg0, int *, 8), 1, -1, 0x100, 0, var_f12, 32769.0f);
                M2C_FIELD(arg0, int *, 0x3C) = 0x3C;
                M2C_FIELD(arg0, int *, 0x38) = 0x3C;
                M2C_FIELD(arg0, int *, 0xC) = (int) ((M2C_FIELD(arg0, int *, 0xC) & ~4) | 8);
            }
            temp_v1_2 = M2C_FIELD(arg0, int *, 0x30);
            if ((temp_v1_2 == 5) || (temp_v1_2 == 0xB)) {
                var_v0 = M2C_FIELD(arg0, int *, 0xC) | 8;
block_43:
                M2C_FIELD(arg0, int *, 0xC) = var_v0;
            }
            /* Duplicate return node #45. Try simplifying control flow for better match */
            return 0;
        }
    } else {
block_44:
        return 0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMoveSecta__vfunc_04);
#endif

extern "C" u_long128 *func_001EE2FC(TskMoveAdj *arg0, int arg1, int arg2, int arg3, u_long128 *arg4, int arg5, float fparg0)
{
    register u_long128 *p PS2_REG("$2");
    register void *vt PS2_REG("$2") = vtbl_TskMoveAdj;

    arg0->m_unk20 = arg1;
    *(void **)arg0 = vt;
    arg0->m_unk30 = arg3;
    arg0->m_unk28 = (float *)(arg2 + 0x10);
    arg0->m_unk24 = fparg0;
    arg0->m_unk34 = arg5;
    p = (u_long128 *)&arg0->m_pos;
    register u_long128 tmp PS2_REG("$6") = *arg4;
    *p = tmp;
    return p;
}

extern "C" void TskMoveAdj__vfunc_06(TskMoveAdj *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskMoveAdj;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMoveAdj__vfunc_05(void) {
}

static inline char *getDogBase(void *base, int idx)
{
    return (char *)base + idx * 0x4D0;
}

extern "C" int TskMoveAdj__vfunc_04(TskMoveAdj *arg0)
{
    float sp[4];
    float *p10 = arg0->m_pos.f;
    int steps = arg0->m_unk30;
    if (steps >= 0) {
        sp[0] = 0.0f;
        int val = M2C_FIELD(getDogBase(&D_006FBD80, arg0->m_unk20), int *, 0x2AF8);
        arg0->m_unk2C = val;
        float h = arg0->m_unk28[2];
        sp[2] = 0.0f;
        sp[1] = h * ((float)steps / (float)val) - 7.5f;
        Xv_func_0025B878(sp, sp, p10);
        struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_unk20);
        d->unk40[0] = sp[0];
        d->unk40[1] = sp[1];
        d->unk40[2] = sp[2];
        d->unk90 = 1;
        arg0->m_unk30--;
        return 0;
    }
    Xv_func_0025B878(sp, sp, p10);
    int idx = arg0->m_unk20;
    struct DogActorStub *d = getDogActor(&D_006FBD80, idx);
    d->unk40[0] = p10[0];
    d->unk40[1] = p10[1];
    d->unk40[2] = p10[2];
    d->unk90 = 1;
    return 1;
}

extern "C" void func_001EE4A8(TskRotAdj *arg0, int arg1, int arg2, float fparg0)
{
    float var_f20;
    float var_f20_2;
    double temp_v0;
    double temp_v0_3;
    double temp_v0_4;
    double temp_s4;
    double temp_s5;
    float *rot;
    int temp_v0_2;

    var_f20 = fparg0;
    *(void **)arg0 = vtbl_TskRotAdj;
    temp_s5 = -3.14159265358979323846;
    arg0->m_chrID = arg1;
    if ((double)fparg0 < temp_s5) {
        var_f20 = (float)((double)fparg0 + 6.28318530717958647692);
    }
    temp_s4 = 3.14159265358979323846;
    temp_v0 = (double)var_f20;
    if (temp_v0 > temp_s4) {
        var_f20 = (float)(temp_v0 - 6.28318530717958647692);
    }
    arg0->m_unk08 = var_f20;
    rot = arg0->m_rot.f;
    DogActorStub *actor = (DogActorStub *)((char *)&D_006FE6A0 + (arg1 * 0x4D0));
    rot[0] = actor->unk50[0];
    rot[1] = actor->unk50[1];
    rot[2] = actor->unk50[2];
    if (arg2 <= 0) {
        arg0->m_rot.f[1] += fparg0;
        var_f20_2 = arg0->m_rot.f[1];
        temp_v0_3 = (double)var_f20_2;
        if (temp_v0_3 < temp_s5) {
            var_f20_2 = (float)(temp_v0_3 + 6.28318530717958647692);
        }
        temp_v0_4 = (double)var_f20_2;
        if (temp_v0_4 > temp_s4) {
            var_f20_2 = (float)(temp_v0_4 - 6.28318530717958647692);
        }
        arg0->m_rot.f[1] = var_f20_2;
        Xv_setActorRot__9MagSystemiPCf((int)&D_006E9840, arg0->m_chrID, (int)rot);
        arg0->m_unk0C = 0.0f;
        arg0->m_unk10 = 0;
        arg0->m_unk14 = 0;
        return;
    }
    arg0->m_unk14 = arg2;
    arg0->m_unk10 = arg2;
    arg0->m_unk0C = (float)(fparg0 / (float)arg2);
}

extern "C" void TskRotAdj__vfunc_06(TskRotAdj *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskRotAdj;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskRotAdj__vfunc_05(void) {
}

extern "C" int TskRotAdj__vfunc_04(TskRotAdj *arg0)
{
    float var_f20;

    if (arg0->m_unk10-- >= 0) {
        arg0->m_rot.f[1] += arg0->m_unk0C;
        var_f20 = arg0->m_rot.f[1];
        if (var_f20 < -3.14159265358979323846) {
            var_f20 += 2.0 * 3.14159265358979323846;
        }
        if (var_f20 > 3.14159265358979323846) {
            var_f20 -= 2.0 * 3.14159265358979323846;
        }
        arg0->m_rot.f[1] = var_f20;
        Xv_setActorRot__9MagSystemiPCf((int)&D_006E9840, arg0->m_chrID, (int)arg0->m_rot.f);
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

extern "C" void func_001EE954(unsigned int arg0, unsigned short arg1, int *arg2, int arg3, int arg4, float f0, float f1)
{
    TskVec4_ee954 vec;
    int off = 0x12540;
    char *sys = (char *)&D_006E9840;
    int scene = (int)(sys + off);
    float time;
    float dist;
    float ratio;

    time = X_func_001333E4_ee954(scene, arg1, arg3);
    X_func_001331F4_ee954(scene, arg1, arg3, 0, 0x100, 0, 0.016666694f);
    X_func_00118E6C_ee954(sys, arg1, 0.0f, time * 50.0f, &vec, &f0, 0);
    dist = sqrtf(vec.f[0] * vec.f[0] + vec.f[2] * vec.f[2]);
    if (dist <= 0.0f || arg4 == 0) {
        dist = 0.0f;
    } else {
        dist = X_func_001F6C14_ee954(arg4, f1 / dist);
    }
    if (*arg2 == 0) {
        *arg2 = X_func_001F59B4_ee954(arg0, arg3, -1, 0x100, 0, dist, 32769.0f);
    }
}

extern "C" void func_001EEAEC(TskMovePhysic *arg0, unsigned int arg1)
{
    int kind = (arg1 >> 28) & 3;
    *(void **)arg0 = vtbl_TskMovePhysic;
    arg0->m_oid = arg1;
    arg0->m_unk58 = 0;
    switch (kind) {
    case 1:
        break;
    case 2:
        arg0->m_obj = (ObjStat *)Xiiu_func_001D2BA8((int)&D_007812C0, arg1);
        *(m2c_block8 *)&arg0->m_func = *(m2c_block8 *)&D_002FDFB0;
        arg0->m_chrID = arg0->m_obj->getChrID();
        break;
    }
    {
        struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
        float *p20 = arg0->m_pos.f;
        p20[0] = d->unk40[0];
        p20[1] = d->unk40[1];
        p20[2] = d->unk40[2];
    }
    {
        struct DogActorStub *d = getDogActor(&D_006FBD80, arg0->m_chrID);
        float *p30 = arg0->m_vel.f;
        p30[0] = d->unk50[0];
        p30[1] = d->unk50[1];
        p30[2] = d->unk50[2];
    }
    float s = Xff_sinf(arg0->m_vel.f[1]);
    arg0->m_acc.f[1] = 1.0f;
    arg0->m_acc.f[0] = s;
    arg0->m_acc.f[2] = Xff_cosf(arg0->m_vel.f[1]);
    arg0->m_unk5C |= 1;
}

extern "C" void TskMovePhysic__vfunc_06(TskMovePhysic *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskMovePhysic;
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


// NON_MATCHING: 272/281 differ, 20 relocs differ (size 0x464, game 0x48C), 156 edits
#ifdef NON_MATCHING
extern "C" float ee_001EF0D8(int, float) asm("func_001EF0D8");
extern "C" float ee_001EF100(int, float) asm("func_001EF100");
extern "C" float ee_00133454(int, float *, float *, float *, int) asm("func_00133454");
extern "C" void ee_001DB7CC(int, float *) asm("func_001DB7CC");
extern "C" int ee_001F5350(int, unsigned int, float) asm("func_001F5350");
extern "C" void ee_001FAC60(int,int,int,int,int,int,int) asm("func_001FAC60");
extern "C" int ee_001D7F48(void *, float *, int) asm("func_001D7F48");
extern "C" void ee_001D05F4(void *, int, float *) asm("func_001D05F4");
extern "C" void ee_0025B878(float *, float *, float *) asm("func_0025B878");
extern "C" int func_001EEC4C(int arg0) {
    float sp[4] __attribute__((aligned(16)));
    float out[4] __attribute__((aligned(16)));
    float area[28] __attribute__((aligned(16)));
    float pos[4], delta[4];
    float *var_v1;
    int var_a0_2;
    register float *temp_s2 PS2_REG("$18");
    float temp_f0;
    float temp_f0_2;
    float temp_f1;
    float temp_f20;
    float temp_f20_2;
    float temp_f21;
    float temp_f22;
    float temp_f2;
    float var_f20;
    float var_f23;
    int var_a0;
    int var_v0;
    unsigned int var_a1;
    unsigned int var_a1_2;
    register int temp_s6 PS2_REG("$22");
    int temp_v0;

    var_v1 = &area[8];
    var_a0 = 2;
    area[0] = area[1] = area[2] = 0.0f;
    area[4] = 0.0f;
    area[3] = area[7] = 1.0f;
    area[5] = area[6] = 0.0f;
    do {
        var_a0 -= 1;
        M2C_FIELD(var_v1, float *, 0) = M2C_FIELD(var_v1, float *, 4) = M2C_FIELD(var_v1, float *, 8) = 0.0f;
        M2C_FIELD(var_v1, float *, 0xC) = 1.0f;
        var_v1 += 4;
    } while (var_a0 != -1);
    temp_s2 = (float *)(arg0 + 0x20);
    M2C_FIELD(arg0, int *, 0x64) = (int) (M2C_FIELD(arg0, int *, 0x64) + 1);
    ee_001D05F4(&D_007812C0, M2C_FIELD(arg0, int *, 0xC), temp_s2);
    temp_f21 = (float) M2C_FIELD(arg0, int *, 0x64) / 30.0f;
    if (temp_f21 > 0.5f) {
        temp_f20 = ee_001EF0D8(arg0, temp_f21);
        var_f23 = temp_f20 - ee_001EF0D8(arg0, temp_f21 - 0.5f);
    } else {
        var_f23 = ee_001EF0D8(arg0, temp_f21);
    }
    if (temp_f21 > 0.5f) {
        temp_f20_2 = ee_001EF100(arg0, temp_f21);
        var_f20 = temp_f20_2 - ee_001EF100(arg0, temp_f21 - 0.5f);
    } else {
        var_f20 = ee_001EF100(arg0, temp_f21);
    }
    if (var_f20 < 16.0f) {
        var_f20 = M2C_FIELD(arg0, float *, 0x60);
    }
    temp_f22 = -var_f23;
    M2C_FIELD(arg0, float *, 0x60) = var_f20;
    sp[0] = M2C_FIELD(arg0, float *, 0x40) * var_f20;
    sp[1] = M2C_FIELD(arg0, float *, 0x44) * temp_f22;
    sp[2] = M2C_FIELD(arg0, float *, 0x48) * var_f20;
    ee_0025B878(&out[0], temp_s2, sp);
    pos[0] = out[0];
    temp_s6 = (int)&D_006E9840 + 0x12540;
    pos[2] = out[2];
    pos[3] = out[3];
    pos[1] = out[1];
    delta[0] = sp[0];
    delta[3] = sp[3];
    delta[1] = sp[1];
    delta[2] = sp[2];
    temp_f0 = ee_00133454(temp_s6, &area[0], &pos[0], &delta[0], 0);
    if (!(temp_f0 >= 0.0f) || !(temp_f0 <= 1.0f)) {
        M2C_FIELD(arg0, u_long128 *, 0x20) = *(u_long128 *)out;
    } else {
        sp[0] *= temp_f0;
        sp[2] *= temp_f0;
        ee_0025B878(&out[0], temp_s2, sp);
        M2C_FIELD(arg0, u_long128 *, 0x20) = *(u_long128 *)out;
        temp_f1 = -(M2C_FIELD(arg0, float *, 0x40) * 0.25f);
        temp_f2 = -(M2C_FIELD(arg0, float *, 0x48) * 0.25f);
        sp[1] = M2C_FIELD(arg0, float *, 0x44) * temp_f22;
        M2C_FIELD(arg0, float *, 0x40) = temp_f1;
        M2C_FIELD(arg0, float *, 0x48) = temp_f2;
        sp[0] = temp_f1 * var_f20;
        sp[2] = temp_f2 * var_f20;
        ee_0025B878(&out[0], &out[0], sp);
        pos[0] = out[0];
        pos[1] = out[1];
        pos[2] = out[2];
        pos[3] = out[3];
        delta[0] = sp[0];
        delta[3] = sp[3];
        delta[1] = sp[1];
        delta[2] = sp[2];
        temp_f0_2 = ee_00133454(temp_s6, &area[0], &pos[0], &delta[0], 0);
        if ((temp_f0_2 >= 0.0f) && (temp_f0_2 <= 1.0f)) {
            M2C_FIELD(arg0, float *, 0x48) = 0.0f;
            M2C_FIELD(arg0, float *, 0x40) = 0.0f;
        }
    }
    ee_001DB7CC(M2C_FIELD(arg0, int *, 8), temp_s2);
    if (M2C_FIELD(arg0, int *, 0x5C) & 1) {
        var_a1 = 0;
        if (M2C_FIELD(&D_007812C0, int *, 0x22090) != 0) {
            var_a1 = M2C_FIELD(M2C_FIELD(&D_007812C0, int *, 0x22090), unsigned int *, 0x100);
        }
        if (ee_001F5350(M2C_FIELD(arg0, int *, 0xC), var_a1, 100.0f) != 0) {
            var_a0_2 = 4;
            goto block_27;
        }
        var_a1_2 = 0;
        if (M2C_FIELD(&D_007812C0, int *, 0x22094) != 0) {
            var_a1_2 = M2C_FIELD(M2C_FIELD(&D_007812C0, int *, 0x22094), unsigned int *, 0x100);
        }
        var_a0_2 = 3;
        if (ee_001F5350(M2C_FIELD(arg0, int *, 0xC), var_a1_2, 100.0f) != 0) {
block_27:
            ee_001FAC60(var_a0_2, M2C_FIELD(arg0, int *, 0xC), 0, 0, 0x15, 0, 0);
            M2C_FIELD(arg0, int *, 0x5C) = (int) (M2C_FIELD(arg0, int *, 0x5C) & ~1);
        }
    }
    temp_v0 = ee_001D7F48(&D_007812C0, temp_s2, 0);
    var_v0 = 0;
    if (temp_v0 != 0) {
        var_v0 = 1;
        if (!(M2C_FIELD(temp_v0, float *, 0x14) < M2C_FIELD(arg0, float *, 0x24))) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EEC4C);
#endif

extern "C" float func_001EF0D8(float fparg0)
{
    return (fparg0 * 16.0f) - (fparg0 * 29.3999981880188f * fparg0);
}

extern "C" float func_001EF100(float fparg0)
{
    return 24.0f - (fparg0 * 16.0f);
}

extern "C" int TskMovePhysic__vfunc_04(TskMovePhysic *arg0)
{
    return (arg0->*(arg0->m_func))();
}

// NON_MATCHING: 151/163 differ, 19 relocs differ (size 0x28C, game 0x290), 20 edits
#ifdef NON_MATCHING
extern "C" int X_func_001D1720(...) asm("func_001D1720");
extern "C" int X_func_001D890C(...) asm("func_001D890C");
extern "C" int X_func_001EFAB8(...) asm("func_001EFAB8");
extern "C" int X_func_001EFEB8(...) asm("func_001EFEB8");
extern "C" int X_func_001F0288(...) asm("func_001F0288");
extern "C" int X_func_001F5558(...) asm("func_001F5558");
extern const char avoidSpine184[] asm("D_002FDFE0");
extern int D_002FDFD8;
extern int D_002FDFF0;
extern int D_002FDFF8;
extern int D_002FE000;
struct AvoidCopy184 { int w[2]; };
static inline int playerId184(void *man) { int id = 0; int p = *(int *)((char *)man + 0x22090); if(p) id = *(int *)((char *)p + 0x100); return id; }
static inline int flags184(void *man) { return *(int *)((char *)man + 0x21F4C); }
extern "C" void func_001EF184(int arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    int temp_s2;
    int var_v1;
    unsigned int temp_a1;
    int temp_v0;
    int temp_v1;

    M2C_FIELD(arg0, void **, 0) = vtbl_TskAvoidMove;
    M2C_FIELD(arg0, int *, 0x6C) = arg3;
    M2C_FIELD(arg0, int *, 0x68) = arg4;
    M2C_FIELD(arg0, unsigned int *, 0xC) = arg1;
    M2C_FIELD(arg0, int *, 0x58) = 0;
    M2C_FIELD(arg0, int *, 0x70) = 0;
    var_v1 = 0;
    if (M2C_FIELD((int)&D_007812C0, int *, 0x22090) != 0) {
        var_v1 = M2C_FIELD(M2C_FIELD((int)&D_007812C0, int *, 0x22090), int *, 0x100);
    }
    if (arg1 == var_v1) {
        *(AvoidCopy184 *)((char *)(arg0) + 124) = *(AvoidCopy184 *)((char *)(&D_002FDFD8) + 0);
        return;
    }
    if (((arg1 >> 0x1C) & 3) == 1) {
        temp_v0 = X_func_001D2B8C_f1670((int)&D_007812C0, arg1);
        M2C_FIELD(arg0, int *, 4) = temp_v0;
        M2C_FIELD(arg0, int *, 0x14) = (int) M2C_FIELD(temp_v0, int *, 0x108);
    }
    temp_s2 = arg0 + 0x20;
    if (flags184(&D_007812C0) & 0x3000) {
        *(AvoidCopy184 *)((char *)(arg0) + 124) = *(AvoidCopy184 *)((char *)(&D_002FDFD8) + 0);
        return;
    }
    if (X_func_001F5558(M2C_FIELD(arg0, unsigned int *, 0xC), temp_s2, (int) avoidSpine184) == 0) {
        X_func_001D890C(M2C_FIELD(arg0, int *, 4), temp_s2);
    }
    if (arg2 != 0) {
        if ((arg6 != 0) && ((unsigned int) ((((unsigned int) M2C_FIELD(arg2, unsigned int *, 0x10) >> 0x17) & 0x1F) - 1) < 2U)) {
            *(AvoidCopy184 *)((char *)(arg0) + 124) = *(AvoidCopy184 *)((char *)(&D_002FDFD8) + 0);
            return;
        }
        temp_a1 = M2C_FIELD(arg2, unsigned int *, 0x10);
        if ((((temp_a1 >> 0x1C) & 3) == 1) && (X_func_001D1720((int)&D_007812C0, temp_a1, 0x4000) != 0)) {
            *(AvoidCopy184 *)((char *)(arg0) + 124) = *(AvoidCopy184 *)((char *)(&D_002FDFD8) + 0);
            return;
        }
        if (arg6 != 0) {
            *(AvoidCopy184 *)((char *)(arg0) + 124) = *(AvoidCopy184 *)((char *)(&D_002FDFF0) + 0);
            X_func_001EFEB8(arg0, M2C_FIELD(arg2, unsigned int *, 0x10), temp_s2, M2C_FIELD(arg0, int *, 0x6C));
        } else {
            *(AvoidCopy184 *)((char *)(arg0) + 124) = *(AvoidCopy184 *)((char *)(&D_002FDFF8) + 0);
            X_func_001EFAB8(arg0, M2C_FIELD(arg2, unsigned int *, 0x10), temp_s2, M2C_FIELD(arg0, int *, 0x6C));
        }
        goto block_22;
    }
    if (arg5 != 0) {
        *(AvoidCopy184 *)((char *)(arg0) + 124) = *(AvoidCopy184 *)((char *)(&D_002FE000) + 0);
        X_func_001F0288(arg0, M2C_FIELD(arg0, unsigned int *, 0xC), temp_s2, arg5, M2C_FIELD(arg0, int *, 0x6C));
    }
block_22:
    temp_v1 = M2C_FIELD(arg0, int *, 4);
    M2C_FIELD(temp_v1, int *, 0x120) = (int) (M2C_FIELD(temp_v1, int *, 0x120) | 0x4000);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EF184);
#endif

extern "C" void TskAvoidMove__vfunc_06(TskAvoidMove *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskAvoidMove;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskAvoidMove__vfunc_05(TskAvoidMove *arg0)
{
    ObjStat *obj;

    if (Xiiu_func_001D046C((int)&D_007812C0, arg0->m_oid) != 0) {
        obj = arg0->m_obj;
        if (obj != 0) {
            obj->unsetFlg(0x4000);
        }
    }
}

// NON_MATCHING: 197/254 differ, 50 relocs differ (size 0x3F8, game 0x3F0), 96 edits
#ifdef NON_MATCHING
extern "C" void readPosF498(int, float *) asm("func_001D890C");
extern "C" void addVecF498(float *, float *, float *) asm("func_0025B878");
extern "C" int testF498(int, float *) asm("func_001D8B5C");
extern "C" void setPosF498(int, float *) asm("func_001D89C4");
extern "C" int queryF498(int, float *, unsigned int, int, int, void *) asm("func_001D5A0C");
extern "C" float radiusF498(int, unsigned int, int) asm("func_001D4A3C");
extern "C" float sinF498(float) asm("sinf");
extern "C" float cosF498(float) asm("cosf");
struct HitF498 { char pad[16]; int flag; } ALIGNED(16);
extern const double cF498_2FE008 asm("D_002FE008");
extern const double cF498_2FE010 asm("D_002FE010");
extern const double cF498_2FE018 asm("D_002FE018");
extern const double cF498_2FE020 asm("D_002FE020");
extern const double cF498_2FE028 asm("D_002FE028");
extern const double cF498_2FE030 asm("D_002FE030");
extern const double cF498_2FE038 asm("D_002FE038");
extern const double cF498_2FE040 asm("D_002FE040");
extern const double cF498_2FE048 asm("D_002FE048");
extern const double cF498_2FE050 asm("D_002FE050");
extern const double cF498_2FE058 asm("D_002FE058");
extern "C" int func_001EF498(int arg0) {
    float next[4] ALIGNED(16);
    float probeData[4] ALIGNED(16);
    register float *probe PS2_REG("$20") = probeData;
    HitF498 hit;
    register float *pos PS2_REG("$18") = (float *)(arg0 + 0x20);
    register float *offset PS2_REG("$21") = (float *)(arg0 + 0x40);
    hit.flag = 0;
    readPosF498(M2C_FIELD(arg0, int *, 4), pos);
    addVecF498(next, pos, (float *)(arg0 + 0x30));
    addVecF498(probe, pos, offset);
    if (!testF498(M2C_FIELD(arg0, int *, 4), probe)) {
        register int i PS2_REG("$19") = 0;
        float angle = M2C_FIELD(arg0, float *, 0x74) + cF498_2FE008;
        float a, x;
        goto checkFirst;
        do {
            ++i;
            x = sinF498(angle) * M2C_FIELD(arg0, float *, 0x78);
            M2C_FIELD(arg0, int *, 0x44) = 0;
            M2C_FIELD(arg0, float *, 0x40) = x * 1.25f;
            M2C_FIELD(arg0, float *, 0x48) = cosF498(angle) * M2C_FIELD(arg0, float *, 0x78) * 1.25f;
            addVecF498(probe, pos, offset);
            a = angle + cF498_2FE010;
            if (a < cF498_2FE018) a += cF498_2FE020;
            angle = a;
            if (a > cF498_2FE028) angle = a - cF498_2FE030;
checkFirst:
            if (i < 16) {
                if (testF498(M2C_FIELD(arg0, int *, 4), probe)) goto found;
            } else break;
        } while (1);
        i = 0;
        M2C_FIELD(arg0, float *, 0x78) = radiusF498((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0xC), 0);
        while (i < 16 && !testF498(M2C_FIELD(arg0, int *, 4), probe)) {
            ++i;
            x = sinF498(angle) * M2C_FIELD(arg0, float *, 0x78);
            M2C_FIELD(arg0, int *, 0x44) = 0;
            M2C_FIELD(arg0, float *, 0x40) = x * 1.25f;
            M2C_FIELD(arg0, float *, 0x48) = cosF498(angle) * M2C_FIELD(arg0, float *, 0x78) * 1.25f;
            addVecF498(probe, (float *)(arg0 + 0x20), (float *)(arg0 + 0x40));
            a = angle + cF498_2FE038;
            if (a < cF498_2FE040) a += cF498_2FE048;
            angle = a;
            if (a > cF498_2FE050) angle = a - cF498_2FE058;
        }
        M2C_FIELD(arg0, int *, 0x60) = M2C_FIELD(arg0, int *, 0x50) + 1;
found:
        x = sinF498(angle);
        M2C_FIELD(arg0, int *, 0x34) = 0;
        M2C_FIELD(arg0, float *, 0x30) = x * M2C_FIELD(arg0, float *, 0x78);
        M2C_FIELD(arg0, float *, 0x38) = cosF498(angle) * M2C_FIELD(arg0, float *, 0x78);
        if (i >= 16) return 1;
        M2C_FIELD(arg0, float *, 0x74) = angle;
    } else {
        setPosF498(M2C_FIELD(arg0, int *, 4), next);
        if (M2C_FIELD(arg0, int *, 0x50) < M2C_FIELD(arg0, int *, 0x60)++) {
            if (!queryF498((int)&D_007812C0, next, M2C_FIELD(arg0, unsigned int *, 0xC), 0, 0, &hit)) return 1;
        }
    }
    return M2C_FIELD(arg0, int *, 0x68) < M2C_FIELD(arg0, int *, 0x70)++;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EF498);
#endif

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

extern "C" int func_001EF9CC(TskAvoidMove *arg0)
{
    TskVec4 pos;
    GamHitInfo info;
    TskVec4 *p20;

    p20 = &arg0->m_unk20;
    Xvp_func_001D890C((int)arg0->m_obj, (int)p20);
    Xv_func_0025B878(&pos, p20, &arg0->m_unk30);
    if (Xiii_func_001D8B5C((int)arg0->m_obj, (int)&pos) != 0) {
        Xvp_func_001D89C4((int)arg0->m_obj, (int)&pos);
        if (arg0->m_unk64++ >= 9) {
            return 1;
        }
    } else {
        arg0->m_unk64 = 0;
    }
    if (arg0->m_unk70++ > arg0->m_unk68) {
        arg0->m_unk30.f[0] *= 1.25f;
        arg0->m_unk30.f[2] *= 1.25f;
        arg0->m_unk70 = 0;
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


// NON_MATCHING: 96/256 differ, 26 relocs differ, 66 edits
#ifdef NON_MATCHING
extern "C" float radiusFab8(int, unsigned int, int) asm("func_001D4A3C");
extern "C" int spineFab8(unsigned int, float *, const char *) asm("func_001F5558");
extern "C" void posFab8(int, unsigned int, float *) asm("func_001D05F4");
extern "C" float yawFab8(float *, float, float) asm("func_002180E4");
extern "C" int testFab8(int, float *) asm("func_001D8B5C");
extern "C" float sinFab8(float) asm("sinf");
extern "C" float cosFab8(float) asm("cosf");
extern const char spineNameFab8[] asm("D_002FDFE0");
extern const double cFab8_2FE060 asm("D_002FE060");
extern const double cFab8_2FE068 asm("D_002FE068");
extern const double cFab8_2FE070 asm("D_002FE070");
extern const double cFab8_2FE078 asm("D_002FE078");
extern const double cFab8_2FE080 asm("D_002FE080");
extern const double cFab8_2FE088 asm("D_002FE088");
extern const double cFab8_2FE090 asm("D_002FE090");
extern const double cFab8_2FE098 asm("D_002FE098");
extern const double cFab8_2FE0A0 asm("D_002FE0A0");
extern const double cFab8_2FE0A8 asm("D_002FE0A8");
extern const double cFab8_2FE0B0 asm("D_002FE0B0");
extern "C" void func_001EFAB8(int arg0, unsigned int arg1, float *arg2, int arg3) {
    float distance;
    float point[4] ALIGNED(16);
    M2C_FIELD(arg0, unsigned int *, 0x10) = arg1;
    radiusFab8((int)&D_007812C0, arg1, 0);
    radiusFab8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0xC), 0);
    if (!spineFab8(arg1, point, spineNameFab8)) posFab8((int)&D_007812C0, arg1, point);
    float angle = yawFab8(&distance, arg2[0] - point[0], arg2[2] - point[2]);
    float length = distance;
    M2C_FIELD(arg0, float *, 0x74) = angle;
    M2C_FIELD(arg0, float *, 0x78) = length / (float)arg3 * 0.5f;
    float x = sinFab8(angle) * length;
    point[1] = arg2[1];
    point[0] = arg2[0] + x;
    point[2] = arg2[2] + cosFab8(angle) * length;
    if (!testFab8(M2C_FIELD(arg0, int *, 4), point)) {
        int i = 0;
        double next = angle + cFab8_2FE060;
        bool more;
        goto convertFirst;
bodyFirst:
        x = sinFab8(angle) * length;
        point[1] = arg2[1];
        point[0] = arg2[0] + x;
        point[2] = arg2[2] + cosFab8(angle) * length;
        angle += cFab8_2FE068;
        if (angle < cFab8_2FE070) angle += cFab8_2FE078;
        if (angle > cFab8_2FE080) {
            next = angle - cFab8_2FE088;
convertFirst:
            angle = next;
        }
        more = i < 16;
        ++i;
        if (more) {
            if (!testFab8(M2C_FIELD(arg0, int *, 4), point)) goto bodyFirst;
            goto done;
        }
        M2C_FIELD(arg0, float *, 0x78) = radiusFab8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0xC), 0);
        i = 0;
        while (i++ < 16 && !testFab8(M2C_FIELD(arg0, int *, 4), point)) {
            float x = sinFab8(angle) * M2C_FIELD(arg0, float *, 0x78);
            point[1] = arg2[1];
            point[0] = arg2[0] + x;
            point[2] = arg2[2] + cosFab8(angle) * M2C_FIELD(arg0, float *, 0x78);
            angle += cFab8_2FE090;
            if (angle < cFab8_2FE098) angle += cFab8_2FE0A0;
            if (angle > cFab8_2FE0A8) angle -= cFab8_2FE0B0;
        }
    }
done:
    float sx = sinFab8(angle);
    M2C_FIELD(arg0, int *, 0x34) = 0;
    M2C_FIELD(arg0, float *, 0x30) = sx * M2C_FIELD(arg0, float *, 0x78);
    float cz = cosFab8(angle);
    float z = cz * M2C_FIELD(arg0, float *, 0x78);
    M2C_FIELD(arg0, int *, 0x50) = arg3;
    M2C_FIELD(arg0, int *, 0x44) = 0;
    M2C_FIELD(arg0, int *, 0x60) = 0;
    M2C_FIELD(arg0, float *, 0x38) = z;
    M2C_FIELD(arg0, float *, 0x40) = M2C_FIELD(arg0, float *, 0x30) * 1.25f;
    M2C_FIELD(arg0, float *, 0x48) = z * 1.25f;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EFAB8);
#endif

// NON_MATCHING: 169/242 differ, 40 relocs differ (size 0x3C8, game 0x3D0), 89 edits
#ifdef NON_MATCHING
extern "C" float radiusEfeb8(int, unsigned int, int) asm("func_001D4A3C");
extern "C" int spineEfeb8(unsigned int, float *, const char *) asm("func_001F5558");
extern "C" void posEfeb8(int, unsigned int, float *) asm("func_001D05F4");
extern "C" float yawEfeb8(float *, float, float) asm("func_002180E4");
extern "C" int testEfeb8(int, float *) ASM_NOTHROW asm("func_001D8B5C");
extern "C" float sinf(float);
extern "C" float cosf(float);
extern const char spineNameEfeb8[] asm("D_002FDFE0");
extern const double c2FE0B8 asm("D_002FE0B8");
extern const double c2FE0C0 asm("D_002FE0C0");
extern const double c2FE0C8 asm("D_002FE0C8");
extern const double c2FE0D0 asm("D_002FE0D0");
extern const double c2FE0D8 asm("D_002FE0D8");
extern const double c2FE0E0 asm("D_002FE0E0");
extern const double c2FE0E8 asm("D_002FE0E8");
extern const double c2FE0F0 asm("D_002FE0F0");
extern const double c2FE0F8 asm("D_002FE0F8");
extern const double c2FE100 asm("D_002FE100");
extern const double c2FE108 asm("D_002FE108");
extern "C" void func_001EFEB8(int arg0, unsigned int arg1, float *arg2, int arg3) {
    float distance;
    float point[4] ALIGNED(16);
    M2C_FIELD(arg0, unsigned int *, 0x10) = arg1;
    radiusEfeb8((int)&D_007812C0, arg1, 0);
    radiusEfeb8((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0xC), 0);
    if (!spineEfeb8(arg1, point, spineNameEfeb8)) posEfeb8((int)&D_007812C0, arg1, point);
    float angle = yawEfeb8(&distance, arg2[0] - point[0], arg2[2] - point[2]);
    float used = distance;
    float radius = radiusEfeb8((int)&D_007812C0, arg1, 0);
    float x = sinf(angle) * radius;
    point[1] = arg2[1];
    point[0] = arg2[0] + x;
    point[2] = arg2[2] + cosf(angle) * radius;
    if (!testEfeb8(M2C_FIELD(arg0, int *, 4), point)) {
        int i = 0;
        double next = angle + c2FE0B8;
        goto convert;
        while (i++ < 16) {
            if (testEfeb8(M2C_FIELD(arg0, int *, 4), point)) goto done;
            used = distance;
            x = sinf(angle) * used;
            point[1] = arg2[1];
            point[0] = arg2[0] + x;
            point[2] = arg2[2] + cosf(angle) * used;
            angle += c2FE0C0;
            if (angle < c2FE0C8) angle += c2FE0D0;
            if (angle > c2FE0D8) {
                next = angle - c2FE0E0;
convert:
                angle = next;
            }
        }
        used = radius;
        i = 0;
        while (i++ < 16 && !testEfeb8(M2C_FIELD(arg0, int *, 4), point)) {
            float x = sinf(angle) * radius;
            point[1] = arg2[1];
            point[0] = arg2[0] + x;
            point[2] = arg2[2] + cosf(angle) * radius;
            angle += c2FE0E8;
            if (angle < c2FE0F0) angle += c2FE0F8;
            if (angle > c2FE100) angle -= c2FE108;
        }
    }
done:
    M2C_FIELD(arg0, float *, 0x74) = angle;
    M2C_FIELD(arg0, float *, 0x78) = used / (float)arg3;
    float sx = sinf(angle);
    M2C_FIELD(arg0, int *, 0x34) = 0;
    M2C_FIELD(arg0, float *, 0x30) = sx * M2C_FIELD(arg0, float *, 0x78);
    float cz = cosf(angle);
    M2C_FIELD(arg0, int *, 0x50) = arg3;
    M2C_FIELD(arg0, int *, 0x60) = 0;
    M2C_FIELD(arg0, float *, 0x38) = cz * M2C_FIELD(arg0, float *, 0x78);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EFEB8);
#endif

extern "C" void func_001F0288(TskAvoidMove *arg0, int arg1, float *arg2, float *arg3, int arg4)
{
    float dist;
    float ang;
    float spd;

    arg0->m_unk64 = 0;
    ang = Xfpff_func_002180E4(&dist, arg3[0] - arg2[0], arg3[2] - arg2[2]);
    spd = (dist * 1.5f) / (float) arg4;
    if (spd > (1.0f / 30.0f)) {
        spd = 1.0f / 30.0f;
    }
    float s = Xff_sinf(ang);
    M2C_FIELD(&arg0->m_unk30, int *, 4) = 0;
    arg0->m_unk30.f[0] = s * spd;
    float c = Xff_cosf(ang);
    arg0->m_unk60 = 0;
    arg0->m_unk50 = arg4;
    arg0->m_unk30.f[2] = c * spd;
}

extern "C" void func_001F0358(TskAvoidMove *arg0, int arg1, float *arg2, int arg3)
{
    float temp_f1;

    temp_f1 = (float) arg3;
    arg0->m_unk30.f[0] = -arg2[0] / temp_f1;
    M2C_FIELD(&arg0->m_unk30, int *, 4) = 0;
    arg0->m_unk30.f[2] = -arg2[2] / temp_f1;
}

extern "C" int TskAvoidMove__vfunc_04(TskAvoidMove *arg0)
{
    if (Xiiu_func_001D046C((int)&D_007812C0, arg0->m_oid) == 0) {
        return 1;
    }
    return (arg0->*(arg0->m_func))();
}

// NON_MATCHING: 193/267 differ, 42 relocs differ (size 0x42C, game 0x434), 107 edits
#ifdef NON_MATCHING
extern "C" int idF0434(int, unsigned int) asm("func_001CBE38");
extern "C" float yawF0434(int) asm("func_0010A650__8DogActor");
extern "C" void eventF0434(int, int, int *) asm("func_001DA228");
extern "C" int moveF0434(unsigned int, int, int, int, int, float, float) asm("func_001F5BDC");
extern "C" void rotF0434(int, int, float *) asm("setActorRot__9MagSystemiPCf");
struct CopyF0434 { int words[2]; };
extern const CopyF0434 cbF0434a asm("D_002FE130");
extern const CopyF0434 cbF0434b asm("D_002FE140");
extern const double cF0434_2FE148 asm("D_002FE148");
extern const double cF0434_2FE150 asm("D_002FE150");
extern const double cF0434_2FE158 asm("D_002FE158");
extern const double cF0434_2FE160 asm("D_002FE160");
extern const double cF0434_2FE168 asm("D_002FE168");
extern const double cF0434_2FE170 asm("D_002FE170");
extern const double cF0434_2FE178 asm("D_002FE178");
extern const double cF0434_2FE180 asm("D_002FE180");
extern const double cF0434_2FE188 asm("D_002FE188");
extern const double cF0434_2FE190 asm("D_002FE190");
extern const double cF0434_2FE198 asm("D_002FE198");
extern const double cF0434_2FE1A0 asm("D_002FE1A0");
extern const double cF0434_2FE1A8 asm("D_002FE1A8");
extern "C" void func_001F0434(int arg0, unsigned int arg1, int arg2, int arg3, float f0, float f1, float f2, int arg4, int unused) {
    int manager = (int)&D_007812C0;
    int actors = (int)&D_006FBD80;
    float angle = f0;
    M2C_FIELD(arg0, void **, 0) = vtbl_TskChrRot;
    M2C_FIELD(arg0, unsigned int *, 0x20) = arg1;
    M2C_FIELD(arg0, int *, 0x24) = idF0434(manager, arg1);
    unsigned int actorId = M2C_FIELD(arg0, unsigned int *, 0x20);
    if (angle < cF0434_2FE148) angle += cF0434_2FE150;
    register double maxAngle PS2_REG("$23") = cF0434_2FE158;
    if (angle > maxAngle) angle -= cF0434_2FE160;
    M2C_FIELD(arg0, float *, 0x30) = angle;
    M2C_FIELD(arg0, int *, 0x40) = arg4;
    int obj = X_func_001D2B8C_f1670(manager, actorId);
    M2C_FIELD(arg0, int *, 0x44) = arg3;
    M2C_FIELD(arg0, int *, 0x54) = obj;
    M2C_FIELD(arg0, int *, 0x4C) = 0;
    M2C_FIELD(arg0, int *, 0x50) = M2C_FIELD(arg0, int *, 0x24) * 0x4D0 + actors + 0x2920;
    bool special = (M2C_FIELD(obj, int *, 0x120) & 0x80000) != 0;
    double a = M2C_FIELD(arg0, float *, 0x30);
    if (a < cF0434_2FE168 || a > maxAngle) {
        M2C_FIELD(arg0, float *, 0x30) = 0.0f;
        arg2 = 0;
    }
    if (!(f1 >= 32769.0f)) {
        M2C_FIELD(arg0, float *, 0x14) = f1;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 0;
    } else {
        M2C_FIELD(arg0, int *, 0x10) = 0;
        float y = yawF0434(M2C_FIELD(arg0, int *, 0x50));
        M2C_FIELD(arg0, int *, 0x18) = 0;
        M2C_FIELD(arg0, float *, 0x14) = y;
    }
    M2C_FIELD(arg0, int *, 0x1C) = 0;
    if (special) {
        if (f0 < 0.0f) eventF0434(M2C_FIELD(arg0, int *, 0x54), 0x1102, (int *)(arg0 + 0x44));
        else eventF0434(M2C_FIELD(arg0, int *, 0x54), 0x1101, (int *)(arg0 + 0x44));
    }
    int mode = M2C_FIELD(arg0, int *, 0x44);
    float delta = M2C_FIELD(arg0, float *, 0x30);
    if (mode != -1) {
        float yaw = M2C_FIELD(arg0, float *, 0x14);
        float speed = f2 * 0.016666667f;
        angle = yaw + delta;
        M2C_FIELD(arg0, float *, 0x48) = speed;
        if (angle < cF0434_2FE170) angle += cF0434_2FE178;
        if (angle > cF0434_2FE180) angle -= cF0434_2FE188;
        M2C_FIELD(arg0, float *, 0x34) = 0.0f;
        M2C_FIELD(arg0, float *, 0x30) = angle;
        M2C_FIELD(arg0, int *, 0x4C) = moveF0434(arg1, mode, 0, 0x100, 0, speed, yaw);
        M2C_FIELD(arg0, CopyF0434 *, 0x58) = cbF0434a;
        return;
    }
    if (arg2 <= 0) {
        angle = M2C_FIELD(arg0, float *, 0x14) + delta;
        if (angle < cF0434_2FE190) angle += cF0434_2FE198;
        if (angle > cF0434_2FE1A0) angle -= cF0434_2FE1A8;
        M2C_FIELD(arg0, float *, 0x14) = angle;
        rotF0434((int)&D_006E9840, M2C_FIELD(arg0, int *, 0x24), (float *)(arg0 + 0x10));
        M2C_FIELD(arg0, float *, 0x34) = 0.0f;
        M2C_FIELD(arg0, int *, 0x3C) = 0;
        M2C_FIELD(arg0, int *, 0x38) = 0;
    } else {
        M2C_FIELD(arg0, int *, 0x3C) = arg2 - 1;
        M2C_FIELD(arg0, int *, 0x38) = arg2 - 1;
        M2C_FIELD(arg0, float *, 0x34) = delta / (float)arg2;
    }
    M2C_FIELD(arg0, CopyF0434 *, 0x58) = cbF0434b;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F0434);
#endif

extern "C" void TskChrRot__vfunc_06(TskChrRot *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskChrRot;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskChrRot__vfunc_05(void) {
}

extern "C" int TskChrRot__vfunc_04(TskChrRot *arg0)
{
    return (arg0->*(arg0->m_func))();
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













extern "C" int func_001F090C(TskChrRot *arg0) {
    if (arg0->m_unk38-- >= 0) {
        float angle = arg0->m_rot.f[1] + arg0->m_unk34;
        if (angle < -3.14159265358979323846) angle += 6.28318530717958647692;
        if (angle > 3.14159265358979323846) angle -= 6.28318530717958647692;
        arg0->m_rot.f[1] = angle;
        Xv_func_001CFE78((int)&D_007812C0, arg0->m_oid, (int)&arg0->m_rot);
        int *id = (int *)(arg0->m_unk54 + 0x3DC);
        if (X_func_001E7D7C((int)&D_007A3D80, *id)) {
        arg0->m_unk4C = rotGet((int)&D_007A3D80, *id);
        if (arg0->m_rot.f[1] < -3.14159265358979323846 || arg0->m_rot.f[1] > 3.14159265358979323846) {
            float a = arg0->m_rot.f[1];
            if (a < -3.14159265358979323846) a += 6.28318530717958647692;
            if (a > 3.14159265358979323846) a -= 6.28318530717958647692;
            arg0->m_rot.f[1] = a;
            if (a < -3.14159265358979323846 || a > 3.14159265358979323846) arg0->m_rot.f[1] = 0.0f;
        }
        M2C_FIELD(arg0->m_unk4C, float *, 0x6C) = arg0->m_rot.f[1];
        }
        return 0;
    }
    return 1;
}

// NON_MATCHING: 122/176 differ, 24 relocs differ (size 0x2C0, game 0x2C4), 15 edits
#ifdef NON_MATCHING
static inline float wrap0B50(float a) { if(a < -3.14159265358979323846) a += 6.28318530717958647692; if(a > 3.14159265358979323846) a -= 6.28318530717958647692; return a; }
extern "C" int stop0B50(unsigned int, int, int, int, int, float, float) asm("func_001F5BDC");
extern "C" int func_001F0B50(int arg0) {
    float yaw = Xfi_func_0010A650__8DogActor(M2C_FIELD(arg0, int *, 0x50));
    float diff = yaw - M2C_FIELD(arg0, float *, 0x30);
    if(wrap0B50(diff) < 0.0f) {
        if(!(wrap0B50(diff) >= -0.1f)) return 0;
        goto ready;
    }
    if(wrap0B50(diff) <= 0.1f) {
ready:
        if(M2C_FIELD(arg0, int *, 0x40)) stop0B50(M2C_FIELD(arg0, unsigned int *, 0x20), 1, 0, 0, 0, 1.0f / 60.0f, 32769.0f);
        int *slot = (int *)(M2C_FIELD(arg0, int *, 0x54) + 0x3DC);
        if(X_func_001E7D7C_f1670((int)&D_007A3D80, *slot)) {
            X_func_001E7724_f1670((int)&D_007A3D80, *slot);
            *slot = -1;
        }
        M2C_FIELD(arg0, float *, 0x14) = yaw;
        M2C_FIELD(arg0, float *, 0x1C) = 1.0f;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 0;
        Xv_func_001CFE78((int)&D_007812C0, M2C_FIELD(arg0, unsigned int *, 0x20), arg0 + 0x10);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F0B50);
#endif

extern "C" int func_001F0E14(TskChrRot *arg0)
{
    float temp_f1;
    int var_v0;

    temp_f1 = Xfi_func_0010A650__8DogActor(arg0->m_unk50) - arg0->m_unk30;
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

    slot = (int *)((char *)Xiiu_func_001D2B8C(&D_007812C0, arg0) + 0x3D8);
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

    slot = (int *)((char *)Xiiu_func_001D2B8C(&D_007812C0, arg0) + 0x3D8);
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

    slot = (int *)((char *)Xiiu_func_001D2B8C(&D_007812C0, arg0) + 0x3D8);
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

// NON_MATCHING: 5/105 differ, 5 edits
#ifdef NON_MATCHING
extern "C" int X_func_001E71FC_f14cc(int, int, int, int, int, int, int, int *, int) asm("func_001E71FC");
extern "C" int X___builtin_new_f14cc(int) asm("__builtin_new");
extern "C" int X_func_001E7724_f14cc(int, int) asm("func_001E7724");
extern "C" int X_func_001E7D7C_f14cc(int, int) asm("func_001E7D7C");
extern "C" int X_func_001F0434_f14cc(int, unsigned int, int, int, float, float, float, int, int) asm("func_001F0434");
extern "C" int X_func_001D2B8C_f14cc(int, unsigned int) asm("func_001D2B8C");
extern "C" void func_001F14CC(unsigned int arg0, int arg1, int arg2, int arg3, float fparg0, float fparg1, float fparg2)
{
    int *slot = (int *)(X_func_001D2B8C_f14cc((int)&D_007812C0, arg0) + 0x3D8);
    int task;

    if (X_func_001E7D7C_f14cc((int)&D_007A3D80, *slot) != 0) {
        X_func_001E7724_f14cc((int)&D_007A3D80, *slot);
        *slot = -1;
    }
    if (fparg0 != 0.0f) {
        if (fparg0 < 0.0f) {
            task = X___builtin_new_f14cc(0x80);
            X_func_001F0434_f14cc(task, arg0, 0, arg1, fparg0, fparg2, fparg1, arg3, 1);
            X_func_001E71FC_f14cc((int)&D_007A3D80, 1, -1, 1, 0, task, 0, slot, 0x11);
        } else {
            task = X___builtin_new_f14cc(0x80);
            X_func_001F0434_f14cc(task, arg0, 0, arg2, fparg0, fparg2, fparg1, arg3, 1);
            X_func_001E71FC_f14cc((int)&D_007A3D80, 1, -1, 1, 0, task, 0, slot, 0x11);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F14CC);
#endif

extern "C" void func_001F1670(unsigned int arg0, int arg1, int arg2, float fparg0, float fparg1, float fparg2)
{
    TskVec4_f1670 rot;
    int *slot;
    float diff;
    int task;

    slot = (int *)(X_func_001D2B8C_f1670((int)&D_007812C0, arg0) + 0x3D8);
    if (X_func_001E7D7C_f1670((int)&D_007A3D80, *slot) != 0) {
        X_func_001E7724_f1670((int)&D_007A3D80, *slot);
        *slot = -1;
    }
    if (fparg2 >= 32769.0f) {
        X_func_001D06B8_f1670(&D_007812C0, arg0, &rot);
        fparg2 = rot.f[1];
    }
    diff = fparg0 - fparg2;
    if (diff < -3.14159265358979323846) {
        diff += 2.0 * 3.14159265358979323846;
    }
    if (diff > 3.14159265358979323846) {
        diff -= 2.0 * 3.14159265358979323846;
    }
    if (diff != 0.0f) {
        task = X___builtin_new_f1670(0x80);
        X_func_001F0434_f1670(task, arg0, 0, arg1, diff, fparg2, fparg1, arg2, 1);
        X_func_001E71FC_f1670((int)&D_007A3D80, 1, -1, 1, 0, task, 0, slot, 0x11);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE2E0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F184C);

extern "C" void TskFrameFunc__vfunc_06(TskFrameFunc *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskFrameFunc;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskFrameFunc__vfunc_05(TskFrameFunc *arg0)
{
    void *temp_v0;
    void *temp_v0_2;

    if (arg0->m_type == 8) {
        temp_v0 = arg0->m_unk18;
        if (temp_v0 != 0) {
            X_func_001A074C(temp_v0);
            temp_v0_2 = arg0->m_unk18;
            if (temp_v0_2 != 0) {
                X_func_001A0684(temp_v0_2, 3);
            }
            arg0->m_unk18 = 0;
        }
    }
}


extern "C" int TskFrameFunc__vfunc_04(TskFrameFunc *arg0)
{
    return (arg0->*(arg0->m_func))();
}

extern "C" int X_func_001311F4(int, int *) asm("func_001311F4");
extern "C" int Xiiiii_func_001311BC(int, int, int, int) asm("func_001311BC");
extern "C" int func_001F27E0(TskFrameFunc *arg0)
{
    int arr[8];
    int state = arg0->m_step;
    switch (state) {
    case 0:
    {
        int t = arg0->m_param.i[0] / 2;
        int off = 0x12540;
        arg0->m_cnt = t;
        Xiiiii_func_001311BC((int)&D_006E9840 + off, t, 7, 0);
        arg0->m_step++;
        break;
    }
    case 1:
        if (--arg0->m_cnt != -1) {
            return 0;
        } else {
            int off = 0x12540;
            int p = (int)&D_006E9840 + off;
            X_func_00131184(p, 0, 7, 0);
            int t = arg0->m_param.i[0] / 2;
            arr[0] = 1;
            arr[2] = t;
            arr[1] = 2;
            arg0->m_cnt = t;
            X_func_001311F4(p, arr);
            arg0->m_step = 0x63;
        }
        break;
    case 0x63:
        return --arg0->m_cnt == -1;
    }
    return 0;
}

extern "C" void X_func_001311F4_2920(int, int *) asm("func_001311F4");
extern "C" void X_func_00131184_2920(int, int, int, int) asm("func_00131184");
extern "C" int func_001F2920(TskFrameFunc *arg0)
{
    int arr[8];
    switch (arg0->m_step) {
    case 0:
    {
        int t = arg0->m_param.i[0] / 4;
        int off = 0x12540;
        arr[2] = t;
        arr[0] = 1;
        arr[1] = 6;
        int p = (int)&D_006E9840 + off;
        X_func_001311F4_2920(p, arr);
        arg0->m_step++;
        arg0->m_cnt = arg0->m_param.i[0] / 2;
        break;
    }
    case 1:
        if (arg0->m_cnt-- > 0) {
            return 0;
        } else {
            int off = 0x12540;
            int p = (int)&D_006E9840 + off;
            arg0->m_cnt = arg0->m_param.i[0] / 2;
            arr[0] = 1;
            arr[1] = 0;
            arr[2] = 0;
            X_func_001311F4_2920(p, arr);
            X_func_00131184_2920(p, arg0->m_cnt, 7, 0);
            arg0->m_step = 0x63;
        }
        break;
    case 0x63:
        return arg0->m_cnt-- <= 0;
    }
    return 0;
}

extern "C" int func_001F2A84(TskFrameFunc *arg0)
{
    int arr[8];
    switch (arg0->m_step) {
    case 0:
    {
        int t = arg0->m_param.i[0] / 2;
        int off = 0x12540;
        arg0->m_cnt = t;
        Xiiiii_func_001311BC_loc((int)&D_006E9840 + off, t, 7, 0);
        arg0->m_step++;
        break;
    }
    case 1:
        if (arg0->m_cnt-- > 0) {
            return 0;
        } else {
            int off = 0x12540;
            int p = (int)&D_006E9840 + off;
            X_func_00131184(p, 0, 7, 0);
            int t = arg0->m_param.i[0] / 2;
            arr[0] = 2;
            arr[1] = 2;
            arg0->m_cnt = t;
            arr[2] = t;
            X_func_001311F4_loc(p, arr);
            arg0->m_step = 0x63;
        }
        break;
    case 0x63:
        return arg0->m_cnt-- <= 0;
    }
    return 0;
}

// NON_MATCHING: 3/91 differ, 6 edits
#ifdef NON_MATCHING
extern "C" int Xiiiii_func_00131184(int, int, int, int) asm("func_00131184");
extern "C" int X_func_001311F4_2bcc(int, int *) asm("func_001311F4");
extern "C" int X_func_00131184_2bcc(int, int, int, int) asm("func_00131184");
extern "C" int func_001F2BCC(TskFrameFunc *arg0)
{
    int arr[8];
    switch (arg0->m_step) {
    case 0:
    {
        int t = arg0->m_param.i[0] / 4;
        int off = 0x12540;
        arr[0] = 2;
        arr[1] = 6;
        arr[2] = t;
        X_func_001311F4_2bcc((int)&D_006E9840 + off, arr);
        arg0->m_step++;
        arg0->m_cnt = arg0->m_param.i[0] / 2;
        break;
    }
    case 1:
        if (arg0->m_cnt-- > 0) {
            return 0;
        } else {
            int off = 0x12540;
            int p = (int)&D_006E9840 + off;
            arg0->m_cnt = arg0->m_param.i[0] / 2;
            arr[0] = 2;
            arr[1] = 0;
            arr[2] = 0;
            X_func_001311F4_2bcc(p, arr);
            X_func_00131184_2bcc(p, arg0->m_cnt, 7, 0);
            arg0->m_step = 0x63;
        }
        break;
    case 0x63:
        return arg0->m_cnt-- <= 0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2BCC);
#endif

// NON_MATCHING: 12/99 differ, 2 relocs differ (size 0x18C == game 0x18C), 12 edits
#ifdef NON_MATCHING
extern "C" void X_func_00131184_2d38(int, int, int, int) asm("func_00131184");
extern "C" void X_func_001CFA5C_2d38(void *, int, int, int, int, int) asm("func_001CFA5C");
extern "C" int X_func_001CF9D4_2d38(void *) asm("func_001CF9D4");
extern "C" void X_func_001C65E8_2d38(void *, int) asm("func_001C65E8");
extern "C" void X_func_001C6A40_2d38(void *, int) asm("func_001C6A40");
extern "C" int func_001F2D38(TskFrameFunc *arg0)
{
    int off = 0x12540;
    int cmd;
    register void *gm PS2_REG("$16");
    switch (arg0->m_step) {
    case 0x64:
        gm = &D_007812C0;
        X_func_00131184_2d38((int)&D_006E9840 + off, 0xA, 7, 0);
        cmd = 0xD;
    start_ev:
        X_func_001CFA5C_2d38(gm, cmd, -1, -1, -1, -1);
        if (X_func_001CF9D4_2d38(gm) == 0) {
            return 0;
        }
        arg0->m_step++;
        break;
    case 0x66:
        X_func_001C65E8_2d38(&D_007812C0, 0x100000);
        X_func_001C6A40_2d38(&D_007812C0, 0x8000);
        return 1;
    case 0xC8:
        gm = &D_007812C0;
        X_func_00131184_2d38((int)&D_006E9840 + off, 0xA, 7, 0);
        cmd = 0xE;
        goto start_ev;
    case 0x65:
    case 0xC9:
        if (X_func_001CF9D4_2d38(&D_007812C0) == 0) {
            arg0->m_step++;
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

extern "C" int func_001F2EC4(TskFrameFunc *arg0)
{
    if (arg0->m_step == 0x64) {
        return Xiiu_func_001D19A8(&D_007812C0, arg0->m_param.u[0]) != 0;
    }
    arg0->m_cnt = arg0->m_cnt + 1;
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

// NON_MATCHING: 287/352 differ, 48 relocs differ (size 0x580, game 0x5BC), 105 edits
#ifdef NON_MATCHING
extern double D_002FE548, D_002FE550, D_002FE558, D_002FE560;
extern "C" void death001E7544(int,int) asm("func_001E7544");
extern "C" void death0017762C(int) asm("func_0017762C");
extern "C" void death001CB638(int) asm("func_001CB638");
extern "C" void death001C6A40(int,int) asm("func_001C6A40");
extern "C" void death001F5BDC(int,int,int,int,int,float,float) asm("func_001F5BDC");
extern "C" int death001D8B5C(int,float *) asm("func_001D8B5C");
extern "C" void death001F0F9C(int,float,float) asm("func_001F0F9C");
extern "C" int death001E7D7C(int,int) asm("func_001E7D7C");
extern "C" void death001311BC(int,int,int,int) asm("func_001311BC");
extern "C" void death001CD044(int,int,int,int,int,unsigned int) asm("func_001CD044");
extern "C" void death00140B20(int,int) asm("func_00140B20");
extern "C" void death00131184(int,int,int,int) asm("func_00131184");
extern "C" void death001F438C(int,char *) asm("func_001F438C");
extern "C" void death001E71FC(int,int,int,int,int,int,int,int,int) asm("func_001E71FC");
extern "C" int func_001F2F0C(int input) {
    register int arg0 PS2_REG("$18") = input;
    float sp10[4] __attribute__((aligned(16)));
    float sp20[4] __attribute__((aligned(16)));
    float sp30[4] __attribute__((aligned(16)));
    char sp40[64] = "DEATH_J.PSS";
    char sp80[64] = "DEATH_B.PSS";
    int temp_v0;
    int temp_v0_2;
    int var_a0_2;
    int var_a0_3;
    register float var_f22 PS2_REG("$f22");
    int temp_a3;
    int temp_a3_2;
    double angle1, angle2;
    register float var_f21 PS2_REG("$f21");
    int temp_a0;
    int temp_a0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int var_a1;
    register int var_s0 PS2_REG("$16");
    register int var_s2 PS2_REG("$18");
    int var_v0;
    int var_v0_2;
    int temp_s0;
    register int temp_s1 PS2_REG("$17");
    int temp_v0_7;
    int var_a0;
    int sceneOffset = 0x12540;
    int padOffset = 0x837E0;

switch (M2C_FIELD(arg0, int *, 0x10)) {
case 100: var_s0 = 101;
                death001C6A40((int)&D_007812C0, 0x100000);
                M2C_FIELD(arg0, int *, 0x14) = 1;
                var_a0 = (int)&D_006E9840 + sceneOffset;
                var_a1 = 0x78;
                goto block_39;

case 101:
            M2C_FIELD(arg0, int *, 0x14) = 0x77;
            M2C_FIELD(arg0, int *, 0x10) = 0x66;
            temp_s1 = M2C_FIELD((int)&D_007812C0, int *, 0x22090);
            if ((temp_s1 != 0) && (M2C_FIELD(arg0, int *, 0x28) != 0xB)) {
                *(u_long128 *)sp30 = M2C_FIELD((int)&D_007812C0, u_long128 *, 0x22030);
                *(u_long128 *)sp10 = M2C_FIELD((int)&D_007812C0, u_long128 *, 0x22020);
                var_a0_2 = 0;
                if (M2C_FIELD((int)&D_007812C0, int *, 0x22090) != 0) {
                    var_a0_2 = M2C_FIELD(M2C_FIELD((int)&D_007812C0, int *, 0x22090), int *, 0x100);
                }
                death001F5BDC(var_a0_2, 0x2C, 0x1E, 0, 0, 0.016666667f, 32769.0f);
                var_f22 = sp30[1];
                sp20[1] = sp10[1];
                sp20[0] = sp10[0] + (Xff_sinf(var_f22) * 50.0f);
                sp20[2] = sp10[2] + (Xff_cosf(var_f22) * 50.0f);
                var_v0 = 0;
                if (death001D8B5C(temp_s1, sp20) == 0) {
                    sp20[0] = sp10[0] + (Xff_sinf(var_f22) * 140.0f);
                    sp20[2] = sp10[2] + (Xff_cosf(var_f22) * 140.0f);
                    var_v0 = 0;
                    if (death001D8B5C(temp_s1, sp20) == 0) {
                        var_s2 = 0;
loop_22:
                        var_f21 = var_f22 + 0.39269908169872414f;
                        angle1 = (double)var_f21;
                        if (angle1 < D_002FE548) {
                            var_f21 = (float)(angle1 + D_002FE550);
                        }
                        angle2 = (double)var_f21;
                        if (angle2 > D_002FE558) {
                            var_f21 = (float)(angle2 - D_002FE560);
                        }
                        var_f22 = var_f21;
                        sp20[0] = sp10[0] + (Xff_sinf(var_f21) * 50.0f);
                        sp20[2] = sp10[2] + (Xff_cosf(var_f21) * 50.0f);
                        if (death001D8B5C(temp_s1, sp20) != 0) {
                            sp20[0] = sp10[0] + (Xff_sinf(var_f21) * 140.0f);
                            sp20[2] = sp10[2] + (Xff_cosf(var_f21) * 140.0f);
                            if (death001D8B5C(temp_s1, sp20) != 0) {
                                var_a0_3 = 0;
                                if (M2C_FIELD((int)&D_007812C0, int *, 0x22090) != 0) {
                                    var_a0_3 = M2C_FIELD(M2C_FIELD((int)&D_007812C0, int *, 0x22090), int *, 0x100);
                                }
                                death001F0F9C(var_a0_3, var_f21, 1.0f);
                                goto block_43;
                            }
                        }
                        var_s2 += 1;
                        if (var_s2 >= 0xF) {
                            return 0;
                        }
                        goto loop_22;
                    }
                }
                /* Duplicate return node #44. Try simplifying control flow for better match */
                return var_v0;
            }
            goto block_43;

case 102:
                    temp_v0_3 = M2C_FIELD(arg0, int *, 0x14)--;
                    if (temp_v0_3 <= 0) {
                        death001E7544((int)&D_007A3D80, 1);
                        death0017762C((int)&D_006FBD80 + padOffset);
                        death001CB638((int)&D_007812C0);
                        M2C_FIELD(arg0, int *, 0x14) = 0;
                        var_v0_2 = 0x67;
                        goto block_42;
                    }
                    goto block_43;

case 103:
    temp_v0_6 = M2C_FIELD(arg0, int *, 0x14)--;
    if (temp_v0_6 <= 0) {
        M2C_FIELD(arg0, int *, 0x14) = 0x28;
        temp_s0 = (int)&D_006E9840 + sceneOffset;
        death00140B20(temp_s0, 0);
        death00131184(temp_s0, M2C_FIELD(arg0, int *, 0x14), 7, 0);
        temp_v0_7 = X___builtin_new_f1670(0x80);
        death001F438C(temp_v0_7, sp40);
        death001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_7, 0, arg0 + 0x20, 0x11);
        var_v0_2 = 0x68;
block_42:
        M2C_FIELD(arg0, int *, 0x10) = var_v0_2;
    }
goto block_43;
case 104: var_s0 = 105;
var_v0 = 0;
if (death001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x20)) == 0) {
 M2C_FIELD(arg0, int *, 0x14) = 0x3C;
 var_a0 = (int)&D_006E9840 + sceneOffset; var_a1 = 0x3C;
block_39:
 death001311BC(var_a0, var_a1, 7, 0);
 M2C_FIELD(arg0, int *, 0x10) = var_s0;
}
return 0;

case 105:
temp_a0_2 = M2C_FIELD(arg0, int *, 0x14)--;
if (temp_a0_2 > 0) {
 death001CD044((int)&D_007812C0, 1, -1, -1, 0x63, 0xCCCCCCCC);
 var_v0_2 = 0x3E7; goto block_42;
}
return 0;

case 999: return 1;
default: return 0;
}
block_43: return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2F0C);
#endif

// NON_MATCHING: 132/141 differ, 10 relocs differ (size 0x234, game 0x244), 58 edits
#ifdef NON_MATCHING
struct MsgState34 { char pad[0x93C]; int state; };
struct MsgOwner34 { char pad[0x42260]; MsgState34 msg; };
extern MsgOwner34 owner34 asm("D_006FBD80");
extern "C" void msgStart34(MsgState34 *, int, int) asm("func_001913C4");
extern "C" void msgEnd34(MsgState34 *, int, int) asm("func_0019143C");
extern "C" void msgWait34(MsgState34 *, int, int) asm("func_00191478");
static inline int start34(MsgState34 *p) { int r; if(p->state != 0) { r = 0; } else { r = 1; p->state = 1; } return r; }
static inline int next34(MsgState34 *p) { int r; if(p->state != 2) { r = 0; } else { r = 1; p->state = 3; } return r; }
static inline MsgState34 *get34(MsgOwner34 *p) { return &p->msg; }
static inline int check34(MsgState34 *p, int v) { return (p->state ^ v) == 0; }
static inline void finish34(MsgState34 *p) { if(p->state == 5) p->state = 6; }
static inline void finishWait34(MsgState34 *p) { if(p->state == 6) p->state = 7; }
extern "C" int func_001F34C8(int arg0) {
    switch (M2C_FIELD(arg0, int *, 0x10)) {
    case 202: break;
    case 100:
        if(start34(get34(&owner34)) == 1) M2C_FIELD(arg0, int *, 0x10) = 101;
        break;
    case 101:
        if (check34(get34(&owner34), 2)) {
            msgStart34(get34(&owner34), 0, arg0 + 0x20);
            M2C_FIELD(arg0, int *, 0x10) = 102;
        }
        break;
    case 102:
        if(next34(get34(&owner34)) == 1) M2C_FIELD(arg0, int *, 0x10) = 103;
        break;
    case 103:
        if ((D_0073E91C ^ 5) == 0) M2C_FIELD(arg0, int *, 0x10) = 104;
        break;
    case 104:
        finish34(get34(&owner34));
        msgEnd34(get34(&owner34), 0, M2C_FIELD(arg0, int *, 0x44));
        return 1;
    case 200:
        msgWait34(get34(&owner34), 0, M2C_FIELD(arg0, int *, 0x44));
        M2C_FIELD(arg0, int *, 0x10) = 201;
        M2C_FIELD(arg0, int *, 0x14) = M2C_FIELD(arg0, int *, 0x44);
        break;
    case 201:
        if(M2C_FIELD(arg0, int *, 0x14)-- <= 0) {
            finishWait34(get34(&owner34));
            return 1;
        }
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F34C8);
#endif

extern "C" int func_001F370C(TskFrameFunc *arg0)
{
    if (Xii_func_001A06D4(arg0->m_unk18,
                          (int)_9MagSystem$m_current_system + 0x40) != 0) {
        M2C_FIELD(D_007B205C, int *, 0xB4) = Xii_func_001A0BA0(arg0->m_unk18);
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
    D_007812C0.unsetSysFlg2(0x100);
    return 1;
}

extern "C" int func_001F37B8()
{
    if (D_007812C0.chkSysFlg(4)) {
        D_007812C0.unsetSysFlg2(0x800);
    }
    D_007812C0.unsetSysFlg2(0x400000);
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE548);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE550);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE558);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE560);

// NON_MATCHING: 156/162 differ, 27 relocs differ (size 0x288, game 0x318), 146 edits
#ifdef NON_MATCHING
extern "C" int X_func_00118FEC__9MagSystem(...) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_0013F280(...) asm("func_0013F280");
extern "C" int X_func_0013F444(...) asm("func_0013F444");
extern "C" int X_func_00191D20(...) asm("func_00191D20");
extern "C" int X_func_00191D74(...) asm("func_00191D74");
extern "C" int X_func_00191DC8(...) asm("func_00191DC8");
extern "C" int X_func_00191ED0(...) asm("func_00191ED0");
extern "C" int X_func_001C574C(...) asm("func_001C574C");
extern "C" int X_func_001CF95C(...) asm("func_001CF95C");
extern "C" int X_func_001F5BDC(...) asm("func_001F5BDC");
extern "C" int X_memset(...) asm("memset");
extern "C" int func_001F3824(int arg0)
{
    struct { char pad0[64]; } stack;
    int var_v0;
    int var_a1;
    int temp_v1_2;
    unsigned int temp_v1;
    int temp_s0;

    temp_v1 = M2C_FIELD(arg0, unsigned int *, 0x10);
    switch (temp_v1) {
    case 0:
        if (!(M2C_FIELD((int)&D_007812C0, int *, 0x21F4C) & 0x80000)) {
            return 1;
        }
        if ((unsigned int) (X_func_00118FEC__9MagSystem((int)&D_006E9840) - 5) < 3U) {
            M2C_FIELD(arg0, unsigned int *, 0x10) = 1U;
block_24:
        default:
            return 0;
        }
block_9:
        M2C_FIELD((int)&D_007812C0, int *, 0x21F4C) = (int) (M2C_FIELD((int)&D_007812C0, int *, 0x21F4C) & 0xFFF7FFFF & 0xFFFBFFFF);
        return 1;
    case 1:
        if (X_func_001C574C((int)&D_007812C0) == 0) {
            if ((unsigned int) (X_func_00118FEC__9MagSystem((int)&D_006E9840) - 5) >= 3U) {
                goto block_9;
            }
            X_func_001C6A40((int)&D_007812C0, 0x100000);
            var_v0 = 0;
            if (M2C_FIELD((int)&D_007812C0, int *, 0x22090) != 0) {
                var_v0 = M2C_FIELD(M2C_FIELD((int)&D_007812C0, int *, 0x22090), int *, 0x100);
            }
            X_func_001F5BDC(var_v0, 1, 0x1E, 0, 0, 0.016666666138917208f, 32769.0f);
            X_memset((int)&stack, 0, 0x40);
            if (M2C_FIELD((int)&D_007812C0, int *, 0x21F4C) & 0x40000) {
                var_a1 = 0x16;
            } else {
                var_a1 = 0xB;
            }
            M2C_FIELD(arg0, int *, 0x28) = X_func_0013F280((int)&D_006E9840 + 0x12540, var_a1, (int)&stack, 1);
            M2C_FIELD((int)&D_007812C0, int *, 0x21F4C) = (int) (M2C_FIELD((int)&D_007812C0, int *, 0x21F4C) & 0xFFF7FFFF & 0xFFFBFFFF);
            M2C_FIELD(arg0, unsigned int *, 0x10) = 3U;
            M2C_FIELD(arg0, int *, 0x14) = 1;
            goto block_24;
        }
        goto block_24;
    case 2:
        if (X_func_0013F444((int)&D_006E9840 + 0x12540, M2C_FIELD(arg0, int *, 0x28)) != 0) {
            M2C_FIELD(arg0, unsigned int *, 0x10) = 3U;
        }
        goto block_24;
    case 3:
        temp_v1_2 = M2C_FIELD(arg0, int *, 0x14);
        M2C_FIELD(arg0, int *, 0x14) = (int) (temp_v1_2 - 1);
        if (temp_v1_2 > 0) {
            temp_s0 = (int)&D_006FBD80 + 0x42BB0;
            X_func_00191F98(temp_s0, 2);
            X_func_00191ED0(temp_s0, 2);
            X_func_00191D20(temp_s0, 2, 1);
            X_func_00191D74(temp_s0, 2, 1);
            X_func_00191DC8(temp_s0, 2, 2);
        }
        if (X_func_0013F444((int)&D_006E9840 + 0x12540, M2C_FIELD(arg0, int *, 0x28)) == 0) {
            M2C_FIELD(arg0, unsigned int *, 0x10) = 4U;
        }
        
        return 0;
    case 4:
        if (!(M2C_FIELD((int)&D_007812C0, int *, 0x21F4C) & 8)) {
            X_func_001CF95C((int)&D_007812C0);
            X_func_001C65E8((int)&D_007812C0, 0x100000);
            return 1;
        }
        goto block_24;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F3824);
#endif

extern "C" int func_001F3B3C()
{
    struct { char pad0[16]; } stack;
    Xiiii_memset((int)&stack, 0, 0x10);
    Xiii_func_001CB57C((int)&D_007812C0, (int)&stack);
    return 1;
}

extern "C" int func_001F3B74(TskFrameFunc *arg0)
{
    int temp_v1;

    temp_v1 = arg0->m_step;
    switch (temp_v1) {                              
    case 0:
        Xiiuiii_func_00211BE4((int)&D_007A4440, arg0->m_param.u[0], arg0->m_param.i[1], 0, 0);
        arg0->m_step = arg0->m_step + 1;
block_6:
        return 0;
    case 1:
        if (Xiiui_func_00213D00((int)&D_007A4440, arg0->m_param.u[0], 0) == 0) {
            Xiiiiiii_func_001CD044((int)&D_007812C0, 2, arg0->m_param.i[2], 0, -1, arg0->m_param.i[3]);
            D_007812C0.m_jumpAreaAct[1] = 0;
            D_007812C0.m_jumpAreaAct[0] = 0;
            return 1;
        }
        goto block_6;
    default:
        return 0;
    }
}

extern "C" int func_001F3C44(TskFrameFunc *arg0)
{
    float stack[8];
    int temp_v1;
    int temp_a0;
    float temp_f0;
    float temp_f1;

    temp_v1 = arg0->m_cnt;
    temp_a0 = arg0->m_param.i[16];
    if (temp_v1 < temp_a0) {
        temp_f0 = (float)temp_v1 / (float)temp_a0;
        temp_f1 = 1.0f - temp_f0;
        float f0 = arg0->m_param.f[8] * temp_f0 + arg0->m_param.f[0] * temp_f1;
        float f1 = arg0->m_param.f[9] * temp_f0 + arg0->m_param.f[1] * temp_f1;
        float f2 = arg0->m_param.f[10] * temp_f0 + arg0->m_param.f[2] * temp_f1;
        float f3 = arg0->m_param.f[11] * temp_f0 + arg0->m_param.f[3] * temp_f1;
        float f4 = arg0->m_param.f[12] * temp_f0 + arg0->m_param.f[4] * temp_f1;
        float f5 = arg0->m_param.f[13] * temp_f0 + arg0->m_param.f[5] * temp_f1;
        float f6 = arg0->m_param.f[14] * temp_f0 + arg0->m_param.f[6] * temp_f1;
        float f7 = arg0->m_param.f[15] * temp_f0 + arg0->m_param.f[7] * temp_f1;
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
        arg0->m_cnt++;
        return 0;
    }
    return 1;
}

extern "C" int func_001F3D90()
{
    return 1;
}


// NON_MATCHING: 109/188 differ, 15 relocs differ, 29 edits
#ifdef NON_MATCHING
extern "C" void *clear3d(void *, int, unsigned int) asm("memset");
extern "C" int actorEvent3d(int, int, int, int, int) asm("func_001E4EBC");
extern "C" int sceneEvent3d(int, int, int *, int) asm("func_0013F280");
extern "C" int sceneBusy3d(int, int) asm("func_0013F444");
extern "C" int actorBusy3d(int) asm("func_001D1A48");
extern "C" int actorUse3d(int, int, int) asm("func_001C7E40");
extern "C" int fade3d(int, int) asm("func_00190E98");
extern "C" int flags3d(int, int, int, int) asm("func_001357B0");
extern "C" int func_001F3D98(int arg0) {
    int data[16];
    int sceneOff = 0x12540;
    int actorOff = 0x18E00;
    int fadeOff = 0x53E70;
    switch(M2C_FIELD(arg0, int *, 0x10)) {
    case 100:
        clear3d(data, 0, 0x40);
        actorEvent3d((int)&D_007812C0 + actorOff, 17, 0, 0, 0);
        data[0] = M2C_FIELD(arg0, unsigned short *, 0x20);
        data[1] = 1;
        M2C_FIELD(arg0, int *, 0x28) = sceneEvent3d((int)&D_006E9840 + sceneOff, 17, data, 1);
        M2C_FIELD(arg0, int *, 0x10) = 101;
        break;
    case 101:
        if(sceneBusy3d((int)&D_006E9840 + sceneOff, M2C_FIELD(arg0, int *, 0x28)) != 0) return 0;
    case 150:
        actorUse3d((int)&D_007812C0, M2C_FIELD(arg0, unsigned short *, 0x20), 0);
        return 1;
    case 200:
        clear3d(data, 0, 0x40);
        actorEvent3d((int)&D_007812C0 + actorOff, 17, 0, 0, 0);
        data[0] = M2C_FIELD(arg0, unsigned short *, 0x20);
        M2C_FIELD(arg0, int *, 0x28) = sceneEvent3d((int)&D_006E9840 + sceneOff, 19, data, 1);
        M2C_FIELD(arg0, int *, 0x10) = 201;
        break;
    case 201: {
        int base = (int)&D_006E9840;
        int scene = base + sceneOff;
        if(sceneBusy3d(scene, M2C_FIELD(arg0, int *, 0x28)) == 0) {
            fade3d(base + fadeOff, 0);
            char *owner = (char *)&D_007A4440;
            int *flags = (int *)(M2C_FIELD(owner, int *, 0xDC20) + 4);
            *flags |= 0x10000000;
            flags3d(scene, 0x10000, 0, 0x10000000);
            M2C_FIELD(owner, int *, 0xDC24) |= 1;
            M2C_FIELD(arg0, int *, 0x10) = 202;
        }
        break;
    }
    case 202: {
        int r = actorBusy3d((int)&D_007812C0);
        if(r) { M2C_FIELD(arg0, int *, 0x10) = 203; return 0; }
        return r;
    }
    case 203:
        if(!actorBusy3d((int)&D_007812C0)) {
            char *owner = (char *)&D_007A4440;
            M2C_FIELD(owner, int *, 0xDC24) &= ~1;
            actorUse3d((int)&D_007812C0, M2C_FIELD(arg0, unsigned short *, 0x20), 0);
            return 1;
        }
        break;
    case 300:
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F3D98);
#endif

extern "C" void func_001F4088(TskGenFrameFunc *arg0, int arg1, int arg2)
{
    arg0->m_param = arg2;
    *(void **)arg0 = vtbl_TskGenFrameFunc;
    if (arg1 == 1) {
        *(m2c_block8 *)&arg0->m_func = *(m2c_block8 *)&D_002FE588;
    }
}

extern "C" void TskGenFrameFunc__vfunc_06(TskGenFrameFunc *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskGenFrameFunc;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" int TskGenFrameFunc__vfunc_04(TskGenFrameFunc *arg0)
{
    return (arg0->*(arg0->m_func))();
}

extern "C" int func_001F415C(TskGenFrameFunc *arg0)
{
    X_func_0017F8FC((int)&D_007B2580, arg0->m_param);
    return 1;
}


extern "C" void func_001F4184(TskSysFunc *arg0, int arg1, int arg2, int arg3)
{
    *(void **)arg0 = vtbl_TskSysFunc;
    arg0->m_step = 0;
    arg0->m_type = arg1;
    if (arg1 >= 2) {
        return;
    }
    if (arg1 < 0) {
        return;
    }
    arg0->m_unk18 = arg3;
    arg0->m_step = 0x64;
    arg0->m_unk1C = 0x1E;
    arg0->m_unk20 = 0xF;
    arg0->m_unk24 = 0x1B;
    *(m2c_block8 *)&arg0->m_func = *(m2c_block8 *)&D_002FE590;
}

extern "C" void TskSysFunc__vfunc_06(TskSysFunc *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskSysFunc;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskSysFunc__vfunc_05(TskSysFunc *arg0)
{
    int temp_a0 = arg0->m_type;

    if (temp_a0 == 1) {
        char *base = (char *)&D_006FBD80;
        char *p = base + 0x42BB0;

        if (M2C_FIELD(p, int *, 0x944) == temp_a0) {
            M2C_FIELD(p, int *, 0x94C) = 0;
            M2C_FIELD(p, int *, 0x944) = 0;
        }
    }
}

extern "C" int TskSysFunc__vfunc_04(TskSysFunc *arg0)
{
    return (arg0->*(arg0->m_func))();
}

extern "C" int func_001F42C4(TskSysFunc *arg0)
{
    int new_var;
    switch (arg0->m_step) {
    case 0x64: {
        char *base = (char *)&D_006FBD80;
        char *p = base + 0x42BB0;
        *(volatile int *)(p + 0x93C) = arg0->m_unk18;
        new_var = arg0->m_unk1C;
        if (*(volatile int *)(p + 0x944) == 0) {
            *(volatile int *)(p + 0x94C) = new_var;
            *(volatile int *)(p + 0x944) = 1;
        }
        arg0->m_step = 0x65;
        arg0->m_cnt = arg0->m_unk24;
        break;
    }
    case 0x65:
        if (arg0->m_cnt-- <= 0) {
            unsigned int val = arg0->m_unk20;
            char *base = (char *)&D_006FBD80;
            char *p = base + 0x42BB0;
            if (*(volatile int *)(p + 0x944) == 1) {
                *(volatile int *)(p + 0x94C) = val;
                *(volatile int *)(p + 0x944) = 0;
            }
            return 1;
        }
        break;
    }
    new_var = 0;
    return new_var;
}

extern "C" void func_001F438C(TskMovie *arg0, const char *arg1)
{
    int off = 0x18E00;
    int v = 1;
    *(void **)arg0 = vtbl_TskMovie;
    Xv_func_001E6734((int)&D_007812C0 + off, 0x1D, 1, 0x40, 0, -1);
    Xv_func_0017F5E8((int)&D_007B2580, 8);
    arg0->m_unk04 = 0;
    char *s = arg0->m_fileName;
    Xv_strncpy(s, arg1, 0x40);
    char *base = (char *)&D_006FBD80;
    Xv_func_00191E58((int)(base + 0x42BB0), 3, 0x1E);
    arg0->m_step = 0x64;
    int *p = &D_007B2060->m_flags;
    *p |= 0x08000000;
    Xv_func_00192834((int)(base + 0x84AA8), s);
    _9MagSystem$m_v_rate = v;
}

extern "C" void TskMovie__vfunc_06(TskMovie *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskMovie;
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

// NON_MATCHING: 21/169 differ, 4 relocs differ, 15 edits
#ifdef NON_MATCHING
extern "C" int movieReady04(int) asm("func_001928B8");
extern "C" int movieStatus04(int) asm("func_001928D4");
extern "C" int movieEnd04(int) asm("func_00181780");
extern "C" int movieStop04(int) asm("func_00192920");
extern "C" int movieFade04(int, int, int, int) asm("func_00131184");
extern "C" int movieSkip04(int, int, int, int) asm("func_001311BC");
extern int D_0079A0C0;
extern int D_007B40C0;
extern "C" int movieParam04(int, int, int, int, int, int) asm("func_001E6734");
extern "C" int TskMovie__vfunc_04(TskMovie *arg0) {
    int movieOff = 0x84AA8;
    int sceneOff = 0x12540;
    int actorOff = 0x18E00;
    int padOff = 0x97A40;
    switch(arg0->m_step) {
    case 100:
        if(movieReady04((int)&D_006FBD80 + movieOff) == 1) arg0->m_step = 101;
        break;
    case 101:
        if(movieStatus04((int)&D_006FBD80 + movieOff) >= 0) {
            arg0->m_unk0C = 2;
            arg0->m_step = 102;
        }
        break;
    case 102:
        if(arg0->m_unk0C-- <= 0) {
            movieFade04((int)&D_006E9840 + sceneOff, 10, 7, 0);
            arg0->m_step = 103;
        }
        break;
    case 103: {
        int one = 1;
        int *pad = (int *)((char *)&D_006E9840 + padOff);
        if(!(~M2C_FIELD(*pad, unsigned short *, 0x78) & 8)) {
            movieSkip04((int)&D_006E9840 + sceneOff, 0, 7, 0);
            arg0->m_step = 104;
        } else if(movieEnd04((int)&D_007B40C0) == one) {
            arg0->m_step = 104;
        }
        break;
    }
    case 104: {
        char *p = (char *)&D_0079A0C0;
        arg0->m_unk50 = M2C_FIELD(p, int *, 0x1588);
        arg0->m_unk54 = M2C_FIELD(p, int *, 0x158C);
        movieParam04((int)p, 13, 0, 0, 20, -1);
        arg0->m_unk0C = 0;
        arg0->m_step = 105;
        break;
    }
    case 105:
        if(arg0->m_unk0C++ >= 31) {
            int *flags = &D_007B2060->m_flags;
            if(*flags >= 0) movieFade04((int)&D_006E9840 + sceneOff, 30, 7, 0);
            else *flags &= 0x7FFFFFFF;
            int actor = (int)&D_007812C0 + actorOff;
            int rate = 2;
            movieStop04((int)&D_006FBD80 + movieOff);
            _9MagSystem$m_v_rate = rate;
            arg0->m_step = 106;
            movieParam04(actor, 13, arg0->m_unk50, arg0->m_unk54, 10, -1);
            movieParam04(actor, 30, 1, 64, 0, -1);
        }
        break;
    case 106:
        return 1;
    default:
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMovie__vfunc_04);
#endif

extern "C" void func_001F47F0(TskSeqEvent *arg0, int arg1, int arg2, int arg3)
{
    *(void **)arg0 = vtbl_TskSeqEvent;
    arg0->m_type = arg2;
    if (arg2 == 0) {
        arg0->m_frameCnt = 0;
        arg0->m_frameMax = M2C_FIELD(arg3, int *, 0);
        arg0->m_colScaleDist = M2C_FIELD(arg3, float *, 4);
        arg0->m_obj = Xiiu_func_001D2B8C(&D_007812C0, (unsigned int)arg1);
        if (!(arg0->m_colScaleDist <= 1.0f)) {
            *(m2c_block8 *)&arg0->m_func = *(m2c_block8 *)&D_002FE5E8;
            return;
        }
    }
    *(m2c_block8 *)&arg0->m_func = *(m2c_block8 *)&D_002FE5E0;
}

extern "C" void TskSeqEvent__vfunc_05(void) {
}

extern "C" int TskSeqEvent__vfunc_04(TskSeqEvent *arg0)
{
    return (arg0->*(arg0->m_func))();
}

extern "C" int func_001F4910()
{
    return 1;
}


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
extern "C" int func_001F4918(TskSeqEvent *arg0)
{
    int prev = arg0->m_frameCnt++;
    if (prev < arg0->m_frameMax) {
        if (Xiiu_func_001D046C((int)&D_007812C0, arg0->m_obj->getOID()) != 0) {
            float ratio = (float)arg0->m_frameCnt / (float)arg0->m_frameMax;
            arg0->m_unk4C = ratio;
            struct TskSeq48 s;
            s.unk0 = 2;
            s.unk4 = 4;
            s.unk10 = arg0->m_colScaleDist * ratio;
            setSeq48((int)arg0->m_obj, s);
            return 0;
        }
    }
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE5E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE5E8);

// NON_MATCHING: 120/150 differ, 21 relocs differ (size 0x258, game 0x250), 13 edits
#ifdef NON_MATCHING
struct MsgCopy4a { int w[8]; };
extern "C" void ctor4a(int) asm("func_0018330C");
extern "C" void print4a(int, ...) asm("func_00260110");
extern "C" char *strcpy(char *, const char *);
extern "C" int X_strlen(int) asm("strlen");
extern "C" void X_strncpy(int, int, int) asm("strncpy");
extern "C" void func_001F4A24(TskMsgMan *arg0, const char *arg1, int arg2, GamMsgRect *arg3, int arg4, int arg5, int arg6)
{
    int temp_a1;
    TskMsgSub *sub0;
    TskMsgSub *cur;
    int temp_v0_2;
    register int var_s1 PS2_REG("$17");
    char *text;
    register int temp_s0_2 PS2_REG("$16");

    int off = 0x12540;
    var_s1 = 1;
    sub0 = arg0->m_sub;
    cur = sub0;
    *(void **)arg0 = vtbl_TskMsgMan;
    {
        TskMsgSub *p = cur;
        do {
            cur++;
            ctor4a((int)p);
            var_s1 -= 1;
            p = cur;
        } while (var_s1 != -1);
    }
    text = arg0->m_text;
    __builtin_memcpy(text, "#C", 3);
    X_strncpy((int)(arg0->m_text + X_strlen((int)text)), (int)arg1, 0x200);
    arg0->m_rect = *arg3;
    arg0->m_msgPtr = text;
    temp_s0_2 = (int)&D_006E9840 + off;
    arg0->m_mode = arg5;
    arg0->m_cnt = 0;
    temp_v0_2 = X_func_00134730_50b8(temp_s0_2, arg3->m_h, arg3->m_unk10, arg3->m_unk18, -1);
    arg0->m_time = arg6;
    arg0->m_window_no = temp_v0_2;
    arg0->m_cnt = 0;
    arg3->m_w = 0x8001;
    X_func_00118980__9MagSystemiiiiii(&D_006E9840, arg0->m_window_no, arg3->m_x, arg3->m_y, 0x8001, arg3->m_h, arg3->m_unk10);
    X_func_00134CD0_50b8(temp_s0_2, arg0->m_window_no, 0, 0, arg3->m_h, arg3->m_unk10);
    temp_a1 = arg0->m_window_no;
    if (arg4 != 0) {
        X_func_00135494_50b8(temp_s0_2, temp_a1, 1);
        X_func_00135418_50b8(temp_s0_2, arg0->m_window_no, 0);
    } else {
        X_func_00135494_50b8(temp_s0_2, temp_a1, 0);
        X_func_00135418_50b8(temp_s0_2, arg0->m_window_no, 1);
    }
    X_func_00135594_50b8((int)&D_006E9840 + off, arg0->m_window_no);
    X_func_0018741C_50b8((int)sub0);
    X_func_001874F4_50b8((int)sub0, arg0->m_window_no, (int)arg0->m_msgPtr, arg3->m_unk14);
    print4a((int) "TskMsgMan::TskMsgMan \n");
    print4a((int) "m_window_no : %d %s \n", arg0->m_window_no, (int)arg0->m_msgPtr);
    return print4a((int) "======= ======= ======= ======= ======= ======= ======= ======= ======= \n");
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F4A24);
#endif

extern "C" void TskMsgMan__vfunc_06(TskMsgMan *arg0, int arg1)
{
    TskMsgSub *end;
    TskMsgSub *begin;

    *(void **)arg0 = vtbl_TskMsgMan;
    Xv_TskMsgMan__vfunc_05(arg0);
    begin = arg0->m_sub;
    if (begin != 0) {
        end = begin + 2;
        while (begin != end) {
            end--;
            Xvii_func_00183B24(end, 2);
        }
    }
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskMsgMan__vfunc_05(TskMsgMan *arg0)
{
    char *base = (char *)&D_006E9840;

    Xii_func_00187464((int)arg0->m_sub);
    char *scene = base + 0x12540;
    Xiiui_func_001351B0((int)scene, (unsigned int)arg0->m_window_no, 1);
    Xiiu_func_00135594((int)scene, (unsigned int)arg0->m_window_no);
    Xiiu_func_001348B0((int)scene, (unsigned int)arg0->m_window_no);
    arg0->m_mode = 0;
}

extern "C" void TskMsgMan__vfunc_02(TskMsgMan *arg0, int arg1)
{
    unsigned int no = (unsigned int)arg0->m_window_no;
    if (arg1 != 0) {
        pause_v2(no, (char *)&D_006E9840);
        return;
    }
    resume_v2(no, (char *)&D_006E9840);
}

extern "C" int Xii_func_001874AC(int) asm("func_001874AC");
extern "C" int Xiii_func_001875C0(int, int) asm("func_001875C0");
extern "C" int Xiii_func_0018761C(int, int) asm("func_0018761C");
static inline unsigned int padTrigU_04(int p) { return *(unsigned short *)((char *)p + 0x7A); }
extern "C" int TskMsgMan__vfunc_04(TskMsgMan *arg0)
{
    int var_s1 = 0;
    int off = 0x97A40;
    int *pad = (int *)((char *)&D_006E9840 + off);
    switch ((unsigned int)arg0->m_mode) {
    case 0:
        break;
    case 1:
    {
        int tmp = arg0->m_cnt;
        arg0->m_cnt = tmp + 1;
        var_s1 = arg0->m_time < tmp;
        break;
    }
    case 2:
        if (Xiii_func_001875C0((int)arg0->m_sub, arg0->m_window_no) == 0) {
            var_s1 = (((padTrigU_04(*pad) >> 0xE) & 1) && (arg0->m_cnt >= 0xB));
        }
        arg0->m_cnt++;
        break;
    case 3:
        if (Xiii_func_001875C0((int)arg0->m_sub, arg0->m_window_no) == 0) {
            var_s1 = ((arg0->m_cnt >= 0xB) && ((padTrigU_04(*pad) >> 0xE) & 1));
        }
        if (var_s1 == 0) {
            var_s1 = arg0->m_cnt > arg0->m_time;
        }
        arg0->m_cnt++;
        break;
    case 4:
        var_s1 = Xiii_func_001875C0((int)arg0->m_sub, arg0->m_window_no) == 0;
        arg0->m_cnt++;
        break;
    }
    if (var_s1 != 0) {
        Xiii_func_0018761C((int)arg0->m_sub, arg0->m_window_no);
        return 1;
    }
    Xii_func_001874AC((int)arg0->m_sub);
    return 0;
}

extern "C" void func_001F50B8(TskMsgMan *arg0, const char *arg1, int arg2, int arg3, int arg4)
{
    int sub = (int)arg0->m_sub;
    int off = 0x12540;
    int scene;
    unsigned int no;

    X_strncpy_50b8(arg0->m_text, arg1, 0x200);
    arg0->m_msgPtr = arg1;
    arg0->m_unk208 = arg2;
    X_func_00187464_50b8(sub);
    scene = (int)&D_006E9840 + off;
    X_func_001351B0_50b8(scene, (unsigned int)arg0->m_window_no, 1);
    X_func_00135594_50b8(scene, (unsigned int)arg0->m_window_no);
    X_func_001348B0_50b8(scene, (unsigned int)arg0->m_window_no);
    arg0->m_rect.m_w = 0x8001;
    no = X_func_00134730_50b8(scene, arg0->m_rect.m_h, arg0->m_rect.m_unk10, arg0->m_rect.m_unk18, -1);
    arg0->m_window_no = no;
    X_func_00118980__9MagSystemiiiiii(&D_006E9840, no, arg0->m_rect.m_x, arg0->m_rect.m_y, arg0->m_rect.m_w, arg0->m_rect.m_h, arg0->m_rect.m_unk10);
    X_func_00134CD0_50b8(scene, (unsigned int)arg0->m_window_no, 0, 0, arg0->m_rect.m_h, arg0->m_rect.m_unk10);
    if (arg4 != 0) {
        X_func_00135494_50b8(scene, (unsigned int)arg0->m_window_no, 1);
        X_func_00135418_50b8(scene, (unsigned int)arg0->m_window_no, 0);
    } else {
        X_func_00135494_50b8(scene, (unsigned int)arg0->m_window_no, 0);
        X_func_00135418_50b8(scene, (unsigned int)arg0->m_window_no, 1);
    }
    X_func_00135594_50b8((int)&D_006E9840 + off, (unsigned int)arg0->m_window_no);
    X_func_0018741C_50b8(sub);
    X_func_001874F4_50b8(sub, 0, (int)arg0->m_msgPtr, arg0->m_rect.m_unk14);
}

struct TskAttachCtor {
    void *vt;
    unsigned int m_oid;
    int m_chrID;
    const char *m_nodeName;
    int m_attachID;
    TskAttachCtor(unsigned int arg1, int *arg2, const char *arg3) asm("func_001F5244");
};

TskAttachCtor::TskAttachCtor(unsigned int arg1, int *arg2, const char *arg3)
    : m_oid(arg1)
{
    vt = vtbl_TskAttach;
    m_chrID = Xiiu_func_001CBE38(&D_007812C0, arg1);
    m_nodeName = arg3;
    m_attachID = *arg2;
}

extern "C" void TskAttach__vfunc_06(TskAttach *arg0, int arg1)
{
    *(void **)arg0 = vtbl_TskAttach;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskAttach__vfunc_05(void) {
}

extern "C" int TskAttach__vfunc_04(TskAttach *arg0)
{
    struct { char pad0[48]; int sp30; } stack;

    Xiiiii_getActorNodeMatrix__9MagSystemiP19tag_I3dMatrixF4x4_sPCc((int)&D_006E9840, arg0->m_chrID, (int)&stack, (int)arg0->m_nodeName);
    Xiiiiiii_func_0013F980__8MagSceneiiiPfi((int)((int)&D_006E9840 + 0x12540), 2, arg0->m_attachID, 0, (int)&stack.sp30, 0);
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
    DogActorStub *actor = (DogActorStub *)((char *)&D_006FE6A0 + Xiiu_func_001CBE38(&D_007812C0, arg0) * 0x4D0);

    if (actor->unk11C == 0) {
        X_ror_assert(D_002FE698, 0x131, D_002FE6A8);
    }
    if (arg2 == 0) {
        X_ror_assert(D_002FE698, 0x131, D_002FE6B8);
    }
    int idx = Xiii_func_0022B3D8(actor->unk11C, arg2);
    pos0.f[0] = pos0.f[1] = pos0.f[2] = 0.0f;
    pos0.f[3] = 1.0f;
    struct DogVtblEntry *vt = (struct DogVtblEntry *)(actor->vtbl94 + 0x90);
    vt->fn((void *)((char *)actor + vt->delta), pos0.f, idx);
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
    DogActorStub *actor = (DogActorStub *)Xipu_func_001CBDB8(&D_007812C0, arg0);
    if (actor == 0) {
        return 0;
    }
    if (M2C_FIELD(&D_007812C0, int *, 0x21F4C) & 0x3000) {
        return 0;
    }
    if (actor->unk11C == 0) {
        X_ror_assert(D_002FE698, 0x131, D_002FE6A8);
    }
    if (arg2 == 0) {
        X_ror_assert(D_002FE698, 0x131, D_002FE6B8);
    }
    int idx = Xiii_func_0022B3D8(actor->unk11C, arg2);
    if (idx < 0) {
        return 0;
    }
    float vec[4];
    vec[0] = vec[1] = vec[2] = 0.0f;
    vec[3] = 1.0f;
    struct DogVtblEntry *vt = (struct DogVtblEntry *)(actor->vtbl94 + 0x90);
    vt->fn((void *)((char *)actor + vt->delta), vec, idx);
    arg1[0] = vec[0];
    arg1[1] = vec[1];
    arg1[2] = vec[2];
    arg1[3] = vec[3];
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE698);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE6A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE6B8);

// NON_MATCHING: 180/198 differ, 47 relocs differ (size 0x318, game 0x32C), 53 edits
#ifdef NON_MATCHING
extern "C" void X_func_0010EBA0__8DogActorif(int, int, float) asm("func_0010EBA0__8DogActorif");
extern "C" int X_func_0022B3D8(...) asm("func_0022B3D8");
extern "C" int assertF5680(...) asm("ror_assert");
extern "C" int func_001F5680(int arg0, unsigned int arg1) {
    int obj = X_func_001D2B8C_f1670((int)&D_007812C0, arg0);
    int id = M2C_FIELD(obj, int *, 0x108);
    int *flags = (int *)(obj + 0x3EC);
    int node = -1;
    switch (arg1) {
    case 0: {
        if (!bool(*flags & 1)) return 0;
        int name = (int) "Bip01 Neck";
        int actor = (int)&D_006FE6A0 + id * 0x4D0;
        if (!M2C_FIELD(actor, int *, 0x11C)) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6A8);
        if (!name) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6B8);
        node = X_func_0022B3D8(M2C_FIELD(actor, int *, 0x11C), name);
        *flags &= ~1;
        break;
    }
    case 1: {
        if (!(*flags & 2)) return 0;
        int name = (int) "Bip01 R UpperArm";
        int actor = (int)&D_006FE6A0 + id * 0x4D0;
        if (!M2C_FIELD(actor, int *, 0x11C)) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6A8);
        if (!name) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6B8);
        node = X_func_0022B3D8(M2C_FIELD(actor, int *, 0x11C), name);
        *flags &= ~2;
        break;
    }
    case 2: {
        if (!(*flags & 4)) return 0;
        int name = (int) "Bip01 L UpperArm";
        int actor = (int)&D_006FE6A0 + id * 0x4D0;
        if (!M2C_FIELD(actor, int *, 0x11C)) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6A8);
        if (!name) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6B8);
        node = X_func_0022B3D8(M2C_FIELD(actor, int *, 0x11C), name);
        *flags &= ~4;
        break;
    }
    case 3: {
        if (!(*flags & 8)) return 0;
        int name = (int) "Bip01 R Thigh";
        int actor = (int)&D_006FE6A0 + id * 0x4D0;
        if (!M2C_FIELD(actor, int *, 0x11C)) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6A8);
        if (!name) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6B8);
        node = X_func_0022B3D8(M2C_FIELD(actor, int *, 0x11C), name);
        *flags &= ~8;
        break;
    }
    case 4: {
        if (!(*flags & 16)) return 0;
        int name = (int) "Bip01 L Thigh";
        int actor = (int)&D_006FE6A0 + id * 0x4D0;
        if (!M2C_FIELD(actor, int *, 0x11C)) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6A8);
        if (!name) assertF5680((int)D_002FE698, 0x131, (int)D_002FE6B8);
        node = X_func_0022B3D8(M2C_FIELD(actor, int *, 0x11C), name);
        *flags &= ~16;
        break;
    }
    }
    X_func_0010EBA0__8DogActorif((int)&D_006FE6A0 + id * 0x4D0, node, 1.0f);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F5680);
#endif
