#include "include_asm.h"
#include "sdk/math.h"
extern "C" void X_ror_assert_16A594(const char *, int, const char *) asm("ror_assert");
extern "C" void X_func_001D05F4_16A594(void *, unsigned int, float *) asm("func_001D05F4");
extern "C" int X_func_001CBE38_16A594(void *, unsigned int) throw() asm("func_001CBE38");
extern "C" int X_func_0022B3D8_16A594(void *, const char *) throw() asm("func_0022B3D8");
extern char D_002F1E10[];
extern char D_002F1E20[];
extern char D_002F1E30[];
extern char D_002F1E38[];
struct DogEntityStub_16A594 {
    char pad00[0x94];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void vfunc17(float (*theOut)[4], int theNode);
}; // DogEntityStub_16A594
struct DogActorStub_16A594 : public DogEntityStub_16A594 {
    char pad98[0x11C - 0x98];
    void *m_i3r_root;
    char pad120[0x4D0 - 0x120];
    int getNodeIndexByName(const char *p) {
        if (!m_i3r_root) X_ror_assert_16A594(D_002F1E10, 0x131, D_002F1E20);
        if (!p) X_ror_assert_16A594(D_002F1E10, 0x131, D_002F1E30);
        return X_func_0022B3D8_16A594(m_i3r_root, p);
    } // getNodeIndexByName
}; // DogActorStub_16A594
extern DogActorStub_16A594 D_006FE6A0_16A594[] asm("D_006FE6A0");
extern "C" int *X_func_001D7F48_16976C(void *, int, int) asm("func_001D7F48");
extern "C" int X_func_001D81C4_16976C(void *, int, int, int, int, int, int) asm("func_001D81C4");
extern "C" void X_builtin_delete(void *) asm("__builtin_delete");
extern "C" void Xvi_func_001D859C(void *, int) asm("func_001D859C");
struct S_16957C {
    int m_count;
    void *m_arr[0x28];
    int m_max;
}; // S_16957C
extern "C" int X_func_0025B890(...) asm("func_0025B890");
extern "C" int Xii_func_00169A14(int) asm("func_00169A14");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010423C(...) asm("func_0010423C");
extern "C" int X_func_001694CC(...) asm("func_001694CC");
extern "C" int X_func_00169604(...) asm("func_00169604");
extern "C" int X_func_00180CA8(...) asm("func_00180CA8");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" int X_func_001D7F48(...) asm("func_001D7F48");
extern "C" int X_func_001D81C4(...) asm("func_001D81C4");
extern "C" int X_func_001D859C(...) asm("func_001D859C");
extern "C" void Xiii_func_00166B74(int, int) asm("func_00166B74");
extern "C" int Xiii_func_001665B8(int, int) asm("func_001665B8");
extern "C" int Xiiiiii_func_001E4EBC(int, int, int, int, int) asm("func_001E4EBC");
extern "C" int X_func_001D8778(...) asm("func_001D8778");
extern "C" int X_memset(...) asm("memset");
extern int D_007812C0;
extern int D_007B2580;

extern "C" void func_001DA228(void *theObj, int theKind, int *theOut);
extern int D_002F1DF0[];
extern "C" int func_001693A4(int arg0)
{
    unsigned short n;
    func_001DA228((void *)*(int *)(arg0 + 8), 0x5A, (int *)&n);
    if (n >= 6)
        n = 0;
    return D_002F1DF0[n];
}

extern "C" int func_001693EC(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x2C));
    if (temp_v0 < 0) {
        temp_v0_2 = (*(int *)(int *)((char *)(arg0) + 0x30)) - 1;
        (*(int *)(int *)((char *)(arg0) + 0x30)) = temp_v0_2;
        if (temp_v0_2 < 0) {
            (*(int *)(int *)((char *)(arg0) + 0x30)) = X_func_0010423C(arg1, arg2);
            (*(int *)(int *)((char *)(arg0) + 0x2C)) = X_func_001694CC(arg0, arg3);
            return 1;
        }
        goto block_5;
    }
    temp_v0_3 = X_func_00180CA8((int)&D_007B2580, temp_v0);
    if (temp_v0_3 == -1) {
        (*(int *)(int *)((char *)(arg0) + 0x2C)) = temp_v0_3;
    }
block_5:
    return 0;
}


extern "C" void func_0016947C(int arg0)
{
    X_func_00180EA8((int)&D_007B2580, (*(int *)(int *)((char *)(arg0) + 0x2C)));
    (*(int *)(int *)((char *)(arg0) + 0x2C)) = -1;
    (*(int *)(int *)((char *)(arg0) + 0x30)) = X_func_0010423C(8, 0x18);
}


extern "C" void func_001694C4(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x30)) = arg1;
}


static inline char *getSnd(void *g) { return (char *)g + 0x18E00; }
extern "C" int func_001694CC(int arg0, int arg1)
{
    struct { int w[4]; } stack;
    Xiii_func_00166B74(arg0, (int)&stack);
    int v = *(int *)(arg0 + 0xC);
    stack.w[3] = 0;
    int oid = Xiii_func_001665B8(v, arg1);
    return Xiiiiii_func_001E4EBC((int)getSnd(&D_007812C0), oid, 0, (int)&stack, 0);
}

extern "C" void func_00169538(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
    X_memset(arg0 + 4, 0, 0xA0);
    (*(int *)(int *)((char *)(arg0) + 0xA4)) = arg1;
}


extern "C" void func_0016957C(S_16957C *arg0, int arg1)
{
    for (int i = 0; i < 0x28; i++) {
        if (arg0->m_arr[i] != 0) {
            Xvi_func_001D859C(arg0->m_arr[i], 3);
        }
    }
    if (arg1 & 1) {
        return X_builtin_delete(arg0);
    }
}

extern "C" int func_00169604(int arg0, int arg1)
{
    int *p = (int *)(arg0 + arg1 * 4);
    return p[1];
}

extern "C" void func_00169614(int arg0, int arg1, int arg2)
{
    int *p = (int *)(arg0 + arg1 * 4);
    p[1] = arg2;
    (*(int *)(arg0)) += 1;
}

extern "C" void func_00169630(int arg0, int arg1)
{
    int *p = (int *)(arg0 + 4) + arg1;
    if (*p != 0)
        X_func_001D859C(*p, 3);
    *p = 0;
    (*(int *)(arg0)) -= 1;
}

extern "C" int func_0016968C(int arg0, int arg1)
{
    int r = 0;
    int n = *(int *)(arg0 + 0xA4);

    if (n == 0)
        return r;
    int v = func_00169604(arg0, n);
    if (v == 0) {
        *(int *)(arg0 + 0xA4) = 0;
        return v;
    }
    v = X_func_001D8778(v, arg1);
    if (v != 0)
        *(int *)(arg0 + 0xA4) = v;
    return v;
}

extern "C" int func_001696FC(int arg0, int arg1)
{
    int n = *(int *)(arg0 + 0xA4);
    if (n == 0)
        return 0;
    int v = func_00169604(arg0, n);
    if (v == 0) {
        *(int *)(arg0 + 0xA4) = 0;
        return v;
    }
    return X_func_001D8778(v, arg1);
}

extern "C" int func_0016976C(int arg0, int arg1)
{
    int *p0 = X_func_001D7F48_16976C(&D_007812C0, arg0, 0);
    int *p1 = X_func_001D7F48_16976C(&D_007812C0, arg1, 0);
    if (p1 != 0 && p0 != 0) {
        int a = *p0;
        int b = *p1;
        if (a == b) {
            return 1;
        }
        if (X_func_001D81C4_16976C(&D_007812C0, a, b, 0, 0, 0, 0) != 0) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1DF0);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169810);

extern "C" float vecLength_00169A14(const float *v) asm("func_00169A14");
extern "C" float vecLength_00169A14(const float *v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

extern "C" void func_00169A68(int arg0, int arg1)
{
    struct { char pad0[16]; } stack;
    X_func_0025B890((int)&stack, arg0, arg1);
    Xii_func_00169A14((int)&stack);
}

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169A98);

extern "C" int func_00169B0C(const float *arg0, const float *arg1, float fparg0)
{
    int ret = 0;
    float dx = arg0[0] - arg1[0];
    if (dx < 0.0f) {
        dx = -dx;
    }
    float dy = arg0[1] - arg1[1];
    if (dy < 0.0f) {
        dy = -dy;
    }
    float dz = arg0[2] - arg1[2];
    if (dz < 0.0f) {
        dz = -dz;
    }
    if (dx < fparg0 && dz < fparg0) {
        fparg0 *= fparg0;
        if ((dx * dx + dz * dz) < fparg0 && dy < 100.0f) {
            ret = 1;
        }
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169BAC);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_00169F94);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A1DC);

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A424);

extern "C" void func_0016A594(unsigned int arg0, float *arg1)
{
    int type = (arg0 >> 28) & 3;
    X_func_001D05F4_16A594(&D_007812C0, arg0, arg1);
    if (type == 1) {
        const char *bone = D_002F1E38;
        int idx = X_func_001CBE38_16A594(&D_007812C0, arg0);
        DogActorStub_16A594 *actor = &D_006FE6A0_16A594[idx];
        int node = actor->getNodeIndexByName(bone);
        float pos[4];
        float mat[4][4];
        actor->vfunc17(mat, node);
        pos[0] = mat[3][0];
        pos[1] = mat[3][1];
        pos[2] = mat[3][2];
        arg1[0] = pos[0];
        arg1[2] = pos[2];
    }
}

// NON_MATCHING: 2/62 differ, 2 edits
#ifdef NON_MATCHING
extern "C" void X_ror_assert_1693A4(const char *, int, const char *) asm("ror_assert");
extern "C" int X_func_001CBE38(void *, int) throw() asm("func_001CBE38");
extern "C" int X_func_0022B3D8(void *, const char *) throw() asm("func_0022B3D8");
extern char D_002F1E10[];
extern char D_002F1E20[];
extern char D_002F1E30[];
extern char D_002F1E38[];
struct PcStub_16A6B4 { char pad00[0x100]; int m_oid; };
struct GamManStub_16A6B4 { char pad00[0x22090]; PcStub_16A6B4 *m_pc; };
extern GamManStub_16A6B4 D_007812C0_stub asm("D_007812C0");
struct DogEntityStub_16A6B4 {
    char pad00[0x94];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void vfunc17(float (*theOut)[4], int theNode);
}; // DogEntityStub_16A6B4
struct DogActorStub_16A6B4 : public DogEntityStub_16A6B4 {
    char pad98[0x11C - 0x98];
    void *m_i3r_root;
    char pad120[0x4D0 - 0x120];
    int getNodeIndexByName(const char *p) {
        if (!m_i3r_root) X_ror_assert_1693A4(D_002F1E10, 0x131, D_002F1E20);
        if (!p) X_ror_assert_1693A4(D_002F1E10, 0x131, D_002F1E30);
        return X_func_0022B3D8(m_i3r_root, p);
    } // getNodeIndexByName
}; // DogActorStub_16A6B4
extern DogActorStub_16A6B4 D_006FE6A0_stub[] asm("D_006FE6A0");
extern "C" void func_0016A6B4(float *arg0)
{
    GamManStub_16A6B4 *g = &D_007812C0_stub;
    int oid = 0;
    if (g->m_pc != 0) {
        oid = g->m_pc->m_oid;
    }
    const char *bone = D_002F1E38;
    int idx = X_func_001CBE38(g, oid);
    DogActorStub_16A6B4 *actor = &D_006FE6A0_stub[idx];
    int node = actor->getNodeIndexByName(bone);
    float mat[4][4];
    actor->vfunc17(mat, node);
    arg0[1] = 0.0f;
    arg0[0] = mat[3][0];
    arg0[2] = mat[3][2];
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A6B4);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/001693A4", func_0016A7AC);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E10);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E20);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E30);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E38);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E48);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E50);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E58);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E60);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E68);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E70);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E78);

INCLUDE_RODATA("asm/nonmatchings/unk/001693A4", D_002F1E80);
