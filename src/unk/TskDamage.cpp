#include "include_asm.h"
#include "task/cmnitask.h"

struct TskDamageObj {
    unsigned char m_pad00[0x120];
    int m_flg;                          // +0x120
};

class TskDamage : public CmnITask {
public:
    int (TskDamage::*m_func)();         // +0x04 (8 bytes)
    int m_flags;                        // +0x0C
    int m_oid;                          // +0x10
    int m_unk14;                        // +0x14
    TskDamageObj *m_obj;                // +0x18
    int m_unk1C;                        // +0x1C
    int m_damage;                       // +0x20

    virtual int get_task_type() { return 0x12; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskDamage() {}
};

extern "C" char vtbl_9TskDamage[] asm("_vt$9TskDamage");
extern "C" void Xv_func_001F9E58(TskDamage *) asm("func_001F9E58");
extern "C" int Xiii_func_001CB460(int, int, int) asm("func_001CB460");
extern "C" int Xiii_func_001FB624(int, int, int) asm("func_001FB624");
extern "C" int X_func_00163E10(...) asm("func_00163E10");
extern "C" int X_func_00163E48(...) asm("func_00163E48");
extern "C" int X_func_00163E74(...) asm("func_00163E74");
extern "C" int X_func_001DA074(...) asm("func_001DA074");
extern "C" int X_func_001DA07C(...) asm("func_001DA07C");
extern int D_007812C0;
extern int D_007B2140;

extern "C" void func_001F9E38(TskDamage *self)
{
    *(void **)self = vtbl_9TskDamage;
    return Xv_func_001F9E58(self);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB78);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEB98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBB8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBC8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBD0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBD8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBE0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEBE8);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001F9E58);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FA5BC);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FA768);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FA9C4);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FAA70);

extern "C" void TskDamage__vfunc_05(TskDamage *self)
{
    TskDamageObj *temp_v0 = self->m_obj;
    if (temp_v0 != 0) {
        X_func_001DA074(temp_v0);
    }
}

extern "C" int TskDamage__vfunc_04(TskDamage *self)
{
    return (self->*(self->m_func))();
}

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FAC60);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FAE14);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FB084);

extern "C" void func_001FB5D4(int arg0, int arg1)
{
    int info[4];

    Xiii_func_001CB460((int)&D_007812C0, 1, (int)info);
    Xiii_func_001FB624(info[0], arg0, arg1);
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED70);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED78);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED80);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED88);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FED98);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEDA0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEDA8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEDB0);

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FB624);

extern "C" int func_001FBB04(TskDamage *self)
{
    if (self->m_flags & 8) {
        TskDamageObj *temp_v1 = self->m_obj;
        temp_v1->m_flg &= ~0x200;
        int temp_v1_2 = self->m_oid;
        if (self->m_damage < 0x2710) {
            X_func_00163E10((int)&D_007B2140, temp_v1_2, 0);
            X_func_00163E74((int)&D_007B2140, self->m_oid);
            return 1;
        }
        X_func_00163E48((int)&D_007B2140, temp_v1_2);
        X_func_001DA07C(self->m_obj);
        return 1;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEE90);

INCLUDE_RODATA("asm/nonmatchings/unk/TskDamage", D_002FEEA0);
