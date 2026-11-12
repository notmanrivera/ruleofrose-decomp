#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EAA38);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EAB54);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EAC38);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EACB8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMoveTypeGen__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EAF00);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMovePointPath__vfunc_04);

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


INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EC834);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ECDD4);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ECEBC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001ECF3C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMoveSectaFindPath__vfunc_04);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMoveAdj__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EE4A8);

extern "C" void TskRotAdj__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0) = (int)&_vt$9TskRotAdj;
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void TskRotAdj__vfunc_05(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskRotAdj__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EE7F0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EE954);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EEAEC);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EF888);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001EF9CC);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F0288);

extern "C" void func_001F0358(int arg0, int arg1, int arg2, int arg3)
{
    float temp_f1;

    temp_f1 = (float) arg3;
    M2C_FIELD(arg0, float *, 0x30) = (float) (-M2C_FIELD(arg2, float *, 0) / temp_f1);
    M2C_FIELD(arg0, int *, 0x34) = 0;
    M2C_FIELD(arg0, float *, 0x38) = (float) (-M2C_FIELD(arg2, float *, 8) / temp_f1);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskAvoidMove__vfunc_04);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F0E90);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F0F9C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F10A4);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F11A0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F1298);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F13A8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F14CC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F1670);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDED0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDED8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEE8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEF0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDEF8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FDF08);

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

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE220);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE228);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE230);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE238);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE240);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE248);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE250);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE258);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE260);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE268);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE270);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE278);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F27E0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2920);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2A84);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2BCC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F2D38);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F3C44);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F42C4);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F438C);

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


INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F4918);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE5E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE5E8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F4A24);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMsgMan__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMsgMan__vfunc_05);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMsgMan__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", TskMsgMan__vfunc_04);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F5350);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F5410);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F5558);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE698);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE6A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMsgMan", D_002FE6B8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMsgMan", func_001F5680);
