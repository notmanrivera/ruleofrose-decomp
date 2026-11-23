#include "include_asm.h"
#include "task/cmnitask.h"

class TskAttack : public CmnITask {
public:
    int (TskAttack::*m_func)();         // +0x04 (8 bytes)
    int m_unk0C;                        // +0x0C
    int m_oid;                          // +0x10
    unsigned char m_pad14[0x24];        // +0x14
    int m_timer;                        // +0x38
    unsigned char m_pad3C[0x44];        // +0x3C

    virtual int get_task_type() { return 0x11; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskAttack() {}
}; // size 0x80

extern "C" char vtbl_9TskAttack[] asm("_vt$9TskAttack");
extern "C" void *X_memset(void *, int, int) asm("memset");
extern "C" void *X___builtin_new(int) asm("__builtin_new");
extern "C" void *X_func_001D2B8C(void *, int) asm("func_001D2B8C");
extern "C" void X_func_001DA07C(void *) asm("func_001DA07C");
extern "C" int X_func_001E71FC(int, int, int, int, int, int, int, int, int) asm("func_001E71FC");
extern "C" int X_func_001F985C(TskAttack *, int, int) asm("func_001F985C");
extern "C" int X_func_001F98C0(TskAttack *, int, int) asm("func_001F98C0");
extern int D_007812C0;
extern int D_007A3D80;

extern "C" int func_001F985C(TskAttack *self, int arg1, int arg2)
{
    *(void **)self = vtbl_9TskAttack;
    X_memset(&self->m_func, 0, 8);
    self->m_oid = arg1;
    return X_func_001F98C0(self, arg1, arg2);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEA90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEA98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEAA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEAA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEAB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEAB8);

INCLUDE_ASM("asm/nonmatchings/unk/TskAttack", func_001F98C0);

extern "C" void TskAttack__vfunc_05(void)
{
}

extern "C" int TskAttack__vfunc_04(TskAttack *self)
{
    if (self->m_func == 0 || self->m_oid == -1) {
        return 0;
    }
    return (self->*(self->m_func))();
}

extern "C" int func_001F9D74(TskAttack *self)
{
    return self->m_timer-- < 1;
}

extern "C" void func_001F9D90(int arg0, int arg1)
{
    char *obj = (char *)X_func_001D2B8C(&D_007812C0, arg0);
    X_func_001DA07C(obj);
    obj += 0x3E0;
    TskAttack *tsk = (TskAttack *)X___builtin_new(sizeof(TskAttack));
    X_func_001F985C(tsk, arg0, arg1);
    X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, (int)tsk, 0, (int)obj, 0x11);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskAttack", D_002FEB40);
