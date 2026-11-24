#include "include_asm.h"
#include "game/gamsnd.h"
#include "game/gamman.h"
extern "C" void __9BedMemory(void *);
extern "C" void __9MagSystem(void *);
extern "C" void destroy__9BedMemory(void *);
extern "C" void func_0016265C(void *);
extern "C" void func_0017F0D0(void *);
extern "C" void func_001810F4(void *);
extern "C" void func_001C05C0(void *);
extern "C" void func_001E7094(void *);
extern "C" void func_0020E454(void *);
extern "C" void EmyManager__vfunc_06(void *, int);
extern "C" void GamMan__vfunc_01(void *, int);
extern "C" void _$_9MagSystem(void *, int);
extern "C" void func_0017F13C(void *, int);
extern "C" void func_00181128(void *, int);
extern "C" void func_001E70DC(void *, int);
extern "C" void func_0020E63C(void *, int);
extern int D_006E9800;
extern int D_006E9840;
extern int D_007A3D80;
extern int D_007B2140;
extern int D_007B40C0;
struct TskEnemyTurn {
    void *m_vtable;
    int m_active;
    int m_oid;
    int m_chrID;
    void *m_actor;
    int *m_donePtr;
    int m_targetOid;
    float m_mtnSpeed;
    int m_curMtn;
    int m_turnDir;
    float m_stopAngle;
    float m_targetPos[3];
    int m_unk38;
    int m_sndHandle;
    int m_sndTimer;
    int m_sndType;
    int m_paused;
};
extern "C" int func_00180CA8(void *, int);
extern "C" int func_0010423C(int, int);
extern "C" int func_0016A8A4(int, int);
extern "C" int func_00169A98(const float *, const float *, float);
extern const int D_002FF6A8[];
extern const int D_002FF6E8[];
extern "C" void func_00203DD0(GamTaskBase *);
extern "C" void func_00203F38(GamTaskBase *);
extern "C" int Xii___builtin_delete(int) asm("__builtin_delete");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xii_func_00180EA8(int) asm("func_00180EA8");
extern "C" void X_2F60_180EA8(void *, int) asm("func_00180EA8");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_LoadExecPS2(...) asm("LoadExecPS2");
extern "C" int X_func_0024B3F8(...) asm("rxGsVSync");
extern "C" int X_func_00279C98(...) asm("func_00279C98");
extern "C" int X_sceClose(...) asm("sceClose");
extern "C" int X_sceOpen(...) asm("sceOpen");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001C0D44(...) asm("func_001C0D44");
extern "C" int X_func_001C0D70(...) asm("func_001C0D70");
extern "C" int X_func_0020E664(...) asm("func_0020E664");
extern "C" int X_func_0020E690(...) asm("func_0020E690");
extern int D_007A4440;
extern int D_007B2580;

extern "C" void func_002039A4(void *arg0)
{
    void *temp_a0;

    M2C_FIELD(arg0, int *, 0x48) = 1;
    X_2F60_180EA8(&D_007B2580, M2C_FIELD(arg0, int *, 0x3c));
    if (M2C_FIELD(arg0, int *, 4) == 0) {
        return;
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    if (temp_a0 != 0) {
        M2C_FIELD(temp_a0, float *, 0x1E8) = 9.999999583953922e-08f;
    }
}

extern "C" void func_00203A00(int arg0)
{
    int temp_v0;

    M2C_FIELD(arg0, int *, 0x48) = 0;
    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x10);
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, float *, 0x1E8) = (float) M2C_FIELD(arg0, float *, 0x1C);
        }
    }
}

extern "C" void func_00203A28(TskEnemyTurn *self, const float *pos)
{
    if (self->m_sndHandle >= 0) {
        int h = func_00180CA8(&D_007B2580, self->m_sndHandle);
        if (h != -1) {
            return;
        }
        self->m_sndHandle = h;
    }
    if (--self->m_sndTimer > 0) {
        return;
    }
    if (func_00169A98(pos, self->m_targetPos, 180.0f) != 0) {
        return;
    }
    self->m_sndTimer = func_0010423C(0x1E, 0x50);
    switch (self->m_sndType) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        self->m_sndHandle = func_0016A8A4(self->m_oid, 0xC);
        break;
    case 6:
        self->m_sndHandle = func_0016A8A4(self->m_oid, D_002FF6A8[func_0010423C(0, 0xF)]);
        break;
    case 10:
        self->m_sndHandle = func_0016A8A4(self->m_oid, D_002FF6E8[func_0010423C(0, 3)]);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/002039A4", func_00203B44);

extern "C" void func_00203D94(GamTaskBase *arg0)
{
    return func_00203DD0(arg0);
}


extern "C" void func_00203DA8(void *arg0, int arg1)
{
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void func_00203DD0(GamTaskBase *arg0)
{
    unsigned int t;

    arg0->m_vtable = 0;
    D_007812C0.m_unk22368 = (unsigned int)((float)(D_007812C0.m_vcount * 1000) / 25.0f);
    t = D_007812C0.m_unk22368;
    arg0->m_unk04 = t;
    arg0->m_unk08 = t;
    arg0->m_unk10 = t;
    arg0->m_unk0C = 0;
    arg0->m_unk14 = 0;
    arg0->m_prio = 0;
    arg0->m_unk1C = 0;
    arg0->m_unk20 = 0;
    arg0->m_unk24 = 0;
    arg0->m_unk28 = 0;
}

extern "C" void func_00203EA8(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x0)) == 0) {
        func_00203F38((GamTaskBase *)arg0);
        (*(int *)(int *)((char *)(arg0) + 0x28)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x28)) + ((*(int *)(int *)((char *)(arg0) + 0xC)) - (*(int *)(int *)((char *)(arg0) + 0x14))));
    }
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 1;
}


extern "C" void func_00203EFC(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x0)) != 0) {
        func_00203F38((GamTaskBase *)arg0);
        (*(int *)(int *)((char *)(arg0) + 0x14)) = (int) (*(int *)(int *)((char *)(arg0) + 0xC));
    }
    (*(int *)(int *)((char *)(arg0) + 0x0)) = 0;
}


extern "C" void func_00203F38(GamTaskBase *arg0)
{
    unsigned int cur;
    unsigned int prev;
    unsigned int diff;

    arg0->m_unk08 = arg0->m_unk04;
    D_007812C0.getSysTime();
    cur = D_007812C0.m_unk22368;
    prev = (unsigned int)arg0->m_unk08;
    diff = (cur < prev) ? (prev - cur) : (cur - prev);
    arg0->m_unk04 = cur;
    arg0->m_unk0C += diff;
}

extern "C" void func_00204014(GamTaskBase *arg0)
{
    int temp_a0;

    arg0->m_prio = arg0->m_prio + 1;
    func_00203F38(arg0);
    if (arg0->m_vtable != 0) {
        temp_a0 = arg0->m_unk20;
        arg0->m_unk1C = temp_a0;
        arg0->m_unk20 = arg0->m_unk0C - arg0->m_unk28;
        arg0->m_unk24 = temp_a0;
    }
}

extern "C" void func_0020406C(int arg0, int arg1)
{
    if (((*(int *)(int *)((char *)(arg0) + 0x0)) != 0) && (arg1 >= (unsigned int) (*(int *)(unsigned int *)((char *)(arg0) + 0x24)))) {
        (*(int *)(int *)((char *)(arg0) + 0x24)) = arg1;
    }
}


extern "C" void func_00204090(int arg0)
{
    if ((*(int *)(int *)((char *)(arg0) + 0x0)) != 0) {
        (*(int *)(int *)((char *)(arg0) + 0x24)) = (int) (*(int *)(int *)((char *)(arg0) + 0x20));
    }
}


extern "C" void func_002040AC()
{
    D_007812C0.m_unk22368 = (unsigned int)((float)(D_007812C0.m_vcount * 1000) / 25.0f);
}

extern "C" void func_00204148()
{
    X_func_0020E690((int)&D_007A4440);
    X_func_001C0D70((int)&D_007812C0);
}


extern "C" void func_00204174()
{
    X_func_0020E664((int)&D_007A4440);
    X_func_001C0D44((int)&D_007812C0);
}


INCLUDE_RODATA("asm/nonmatchings/unk/002039A4", D_002FF698);

INCLUDE_RODATA("asm/nonmatchings/unk/002039A4", D_002FF6A8);

INCLUDE_RODATA("asm/nonmatchings/unk/002039A4", D_002FF6E8);

extern "C" void func_002041A0()
{
    struct { char pad0[256]; } stack;
    int temp_v0;

    X_func_00279C98((int)&stack, (int) "host0:main.ee.elf");
    do {
        temp_v0 = X_sceOpen((int)&stack, 1);
    } while (temp_v0 < 0);
    X_sceClose(temp_v0);
    X_func_0024B3F8(0);
    X_LoadExecPS2((int)&stack, 0, 0);
}

extern "C" void func_002041F8(int arg0, int arg1)
{
    if (arg1 == 0xFFFF && arg0 == 1) __9BedMemory(&D_006E9800);
    if (arg1 == 0xFFFF && arg0 == 1) __9MagSystem(&D_006E9840);
    if (arg1 == 0xFFFF && arg0 == 1) func_001C05C0(&D_007812C0);
    if (arg1 == 0xFFFF && arg0 == 1) func_001E7094(&D_007A3D80);
    if (arg1 == 0xFFFF && arg0 == 1) func_0020E454(&D_007A4440);
    if (arg1 == 0xFFFF && arg0 == 1) func_0016265C(&D_007B2140);
    if (arg1 == 0xFFFF && arg0 == 1) func_0017F0D0(&D_007B2580);
    if (arg1 == 0xFFFF && arg0 == 1) func_001810F4(&D_007B40C0);

    if (arg1 == 0xFFFF && arg0 == 0) func_00181128(&D_007B40C0, 2);
    if (arg1 == 0xFFFF && arg0 == 0) func_0017F13C(&D_007B2580, 2);
    if (arg1 == 0xFFFF && arg0 == 0) EmyManager__vfunc_06(&D_007B2140, 2);
    if (arg1 == 0xFFFF && arg0 == 0) func_0020E63C(&D_007A4440, 2);
    if (arg1 == 0xFFFF && arg0 == 0) func_001E70DC(&D_007A3D80, 2);
    if (arg1 == 0xFFFF && arg0 == 0) GamMan__vfunc_01(&D_007812C0, 2);
    if (arg1 == 0xFFFF && arg0 == 0) _$_9MagSystem(&D_006E9840, 2);
    if (arg1 == 0xFFFF && arg0 == 0) destroy__9BedMemory(&D_006E9800);
}

extern "C" void func_0020439C()
{
    func_002041F8(1, 0xFFFF);
}


extern "C" void func_002043BC()
{
    func_002041F8(0, 0xFFFF);
}

