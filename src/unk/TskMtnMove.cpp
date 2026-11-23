#include "include_asm.h"
#include "task/cmnitask.h"

struct TskMtnMoveObj {
    unsigned char m_pad00[0x100];
    int m_oid;                          // +0x100
};

struct TskMtnMoveActor {
    unsigned char m_pad00[0x1E8];
    float m_mtnSpeed;                   // +0x1E8
};

class TskMtnMove : public CmnITask {
public:
    int m_flags;                        // +0x04
    int m_oid;                          // +0x08
    int m_chrID;                        // +0x0C
    int m_unk10;                        // +0x10
    unsigned char m_pad14[0x4C];        // +0x14..+0x5F
    void *m_obj;                        // +0x60
    TskMtnMoveActor *m_actor;           // +0x64
    int m_unk68;                        // +0x68
    float m_unk6C;                      // +0x6C
    unsigned char m_pad70[0x10];        // +0x70..+0x7F
    int (TskMtnMove::*m_func)();        // +0x80 (8 bytes)

    virtual int get_task_type() { return 0; }
    virtual void pause(bool);
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMtnMove() {}
};

class TskMtnMove2 : public CmnITask {
public:
    int m_flags;                        // +0x04
    int m_oid;                          // +0x08
    int m_chrID;                        // +0x0C
    int m_unk10;                        // +0x10
    unsigned char m_pad14[0x3C];        // +0x14..+0x4F
    void *m_obj;                        // +0x50
    TskMtnMoveActor *m_actor;           // +0x54
    int m_unk58;                        // +0x58
    float m_unk5C;                      // +0x5C
    unsigned char m_pad60[0x6C];        // +0x60..+0xCB
    int (TskMtnMove2::*m_func)();       // +0xCC (8 bytes)

    virtual int get_task_type() { return 0; }
    virtual void pause(bool);
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMtnMove2() {}
};

extern "C" int X_func_0010A834__8DogActor(...) asm("func_0010A834__8DogActor");
extern "C" float X_func_00133440(void *, int) asm("func_00133440");
extern "C" void X_func_001DA228(void *, int, float *) asm("func_001DA228");
extern "C" void X_func_001DA740(void *, int, float *) asm("func_001DA740");
extern char D_006E9840[];
extern int D_006FE6A0;
extern TskMtnMoveObj *D_007A3350;

static inline void *getMtnMoveSys(char *base)
{
    return base + 0x12540;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7F28);

extern "C" void TskMtnMove__vfunc_05(void) {
}

extern "C" int TskMtnMove__vfunc_04(TskMtnMove *self)
{
    return (self->*(self->m_func))();
}

extern "C" void TskMtnMove__vfunc_02(TskMtnMove *self, int arg1)
{
    float sp0;
    int oid = 0;

    if (D_007A3350 != 0) {
        oid = D_007A3350->m_oid;
    }
    if (self->m_oid == oid) {
        return;
    }
    if (arg1 != 0) {
        sp0 = X_func_00133440(getMtnMoveSys(D_006E9840), self->m_chrID);
        if (!(self->m_flags & 2)) {
            if (self->m_actor != 0) {
                self->m_actor->m_mtnSpeed = 9.999999583953922e-08f;
            }
            if (self->m_obj != 0) {
                X_func_001DA740(self->m_obj, 0x1201, &sp0);
            }
        }
        self->m_flags |= 2;
    } else {
        sp0 = 0.016666666f;
        if (self->m_flags & 2) {
            if (self->m_obj != 0) {
                X_func_001DA228(self->m_obj, 0x1201, &sp0);
            }
            if ((sp0 < 0.0f) ? (-sp0 < 0.001f) : (sp0 < 0.001f)) {
                sp0 = 0.016666666f;
            }
            if (self->m_actor != 0) {
                self->m_actor->m_mtnSpeed = sp0;
            }
        }
        self->m_flags &= ~2;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E85D0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E89C0);

extern "C" int func_001E8F88(TskMtnMove *self)
{
    return X_func_0010A834__8DogActor((int)&D_006FE6A0 + (self->m_chrID * 0x4D0)) == 0;
}

extern "C" int func_001E8FBC()
{
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E8FC4);

extern "C" void TskMtnMove2__vfunc_05(void) {
}

extern "C" int TskMtnMove2__vfunc_04(TskMtnMove2 *self)
{
    return (self->*(self->m_func))();
}

extern "C" void TskMtnMove2__vfunc_02(TskMtnMove2 *self, int arg1)
{
    float sp0;
    int oid = 0;

    if (D_007A3350 != 0) {
        oid = D_007A3350->m_oid;
    }
    if (self->m_oid == oid) {
        return;
    }
    if (arg1 != 0) {
        sp0 = X_func_00133440(getMtnMoveSys(D_006E9840), self->m_chrID);
        if (!(self->m_flags & 2)) {
            if (self->m_actor != 0) {
                self->m_actor->m_mtnSpeed = 9.999999583953922e-08f;
            }
            if (self->m_obj != 0) {
                X_func_001DA740(self->m_obj, 0x1201, &sp0);
            }
        }
        self->m_flags |= 2;
    } else {
        sp0 = 0.016666666f;
        if (self->m_flags & 2) {
            if (self->m_obj != 0) {
                X_func_001DA228(self->m_obj, 0x1201, &sp0);
            }
            if ((sp0 < 0.0f) ? (-sp0 < 0.001f) : (sp0 < 0.001f)) {
                sp0 = 0.016666666f;
            }
            if (self->m_actor != 0) {
                self->m_actor->m_mtnSpeed = sp0;
            }
        }
        self->m_flags &= ~2;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E93EC);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD940);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD948);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD950);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD958);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD960);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD968);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD970);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD978);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD980);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD988);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD990);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD998);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA48);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA50);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA58);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA70);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E9614);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA88);
INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA98);

extern "C" int func_001E9A34()
{
    return 1;
}
