#include "include_asm.h"
#include "task/cmnitask.h"
#include "game/gamsnd.h"
#include "mag/magscene.h"

struct TskDamageObj {
    unsigned char m_pad00[0x120];
    int m_flg;                          // +0x120
    unsigned char m_pad124[0x2BC];      // +0x124..+0x3DF
    int m_unk3E0;                       // +0x3E0
    unsigned char m_pad3E4[8];          // +0x3E4..+0x3EB
    unsigned int m_unk3EC[4];           // +0x3EC
};

struct TskDamageEffParam {
    int m_kind;                         // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    float m_x;                          // +0x10
    float m_y;                          // +0x14
    float m_z;                          // +0x18
    int m_unk1C;                        // +0x1C
    float m_unk20;                      // +0x20
    int m_unk24;                        // +0x24
    float m_unk28;                      // +0x28
    unsigned char m_pad2C[0x54];        // +0x2C..+0x7F
};

static inline void *getEffMan(MagScene *s)
{
    return s->m_unk837E0;
}

class TskDamage : public CmnITask {
public:
    int (TskDamage::*m_func)();         // +0x04 (8 bytes)
    int m_flags;                        // +0x0C
    int m_oid;                          // +0x10
    int m_unk14;                        // +0x14
    TskDamageObj *m_obj;                // +0x18
    int m_unk1C;                        // +0x1C
    int m_damage;                       // +0x20
    unsigned char m_pad24[0x20];        // +0x24..+0x43
    unsigned int m_unk44;               // +0x44
    unsigned short m_unk48;             // +0x48

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
extern "C" int func_00163E10(void *, int, int);
extern "C" int X_func_00163E48(...) asm("func_00163E48");
extern "C" int X_func_00163E74(...) asm("func_00163E74");
extern "C" int X_func_001DA074(...) asm("func_001DA074");
extern "C" int X_func_001DA07C(...) asm("func_001DA07C");
extern int D_007812C0;
extern int D_007B2140;
extern GamTaskMan D_007A3D80;
extern MagScene D_006FBD80;
extern "C" TskDamageObj *func_001D2B8C(void *, unsigned int);
extern "C" void func_001D890C(TskDamageObj *, float *);
extern "C" void func_00176CC8(void *, TskDamageEffParam *);

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

extern "C" void func_001FA5BC(int arg0, void *arg1, int *arg2, int arg3)
{
    TskDamageObj *obj = func_001D2B8C(&D_007812C0, (unsigned int)arg0);
    if (!(obj->m_flg & 0x400)) {
        int *unk3E0 = &obj->m_unk3E0;
        func_00163E10(&D_007B2140, arg0, 1);
        GamTaskMan *taskMan = &D_007A3D80;
        if (func_001E7D7C(taskMan, *unk3E0) != 0) {
            func_001E7724(taskMan, *unk3E0);
            *unk3E0 = -1;
        }
        TskDamage *task = (TskDamage *)::operator new(0x80);
        ((void (*)(TskDamage *, int, void *, int *, int))func_001F9E38)(task, arg0, arg1, arg2, arg3);
        func_001E71FC(taskMan, 1, -1, 1, 0, task, 0, unk3E0, 0x11);
        float pos[4];
        TskDamageEffParam param;
        func_001D890C(obj, pos);
        param.m_kind = 1;
        param.m_x = pos[0];
        param.m_y = pos[1] - 40.0f;
        param.m_z = pos[2];
        param.m_unk20 = -1.0f;
        param.m_unk08 = 0;
        param.m_unk1C = 0;
        param.m_unk24 = 0;
        param.m_unk28 = (arg3 == 2) ? 1.75f : 1.0f;
        func_00176CC8(getEffMan(&D_006FBD80), &param);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FA768);

// NON_MATCHING: 2/43 differ, 2 edits
#ifdef NON_MATCHING
extern "C" void func_001D9F10(void *, int);
extern "C" void func_001DA07C(void *);
extern "C" void func_00212FBC(void *, int);
extern "C" void func_00163624(void *, int, int);
extern "C" void func_001D1D5C(void *, unsigned int, int, void *);
extern int D_007A4440;
extern "C" void func_001FA9C4(TskDamage *self)
{
    self->m_obj->m_flg |= 0x400;
    self->m_obj->m_flg |= 0x2000;
    func_001D9F10(self->m_obj, 0);
    func_001DA07C(self->m_obj);
    func_00212FBC(&D_007A4440, self->m_oid);
    func_00163624(&D_007B2140, self->m_oid, 2);
    int d = self->m_damage;
    self->m_unk48 = 0;
    self->m_flags |= 0x100;
    self->m_damage = d + 10000;
    func_001D1D5C(&D_007812C0, (unsigned int)self->m_oid, 0x1B, &self->m_unk48);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FA9C4);
#endif

// NON_MATCHING: 76/87 differ, 1 reloc differs (size 0x15C, game 0x160), 1 edits
#ifdef NON_MATCHING
extern "C" int func_0010423C(int, int);
extern "C" int func_001FAA70(TskDamage *self)
{
    unsigned int arr[8];
    int count = 0;
    register unsigned int mask PS2_REG("$17") = 0xFFFFFF;
    unsigned int *p = self->m_obj->m_unk3EC;

    if ((p[0] & 1) != 0) {
    } else {
        arr[count++] = 1;
    }
    if (!(p[0] & 2)) {
        arr[count++] = 2;
    }
    if (!(p[0] & 4)) {
        arr[count++] = 4;
    }
    if (!(p[0] & 8)) {
        arr[count++] = 8;
    }
    if (!(p[0] & 0x10)) {
        arr[count++] = 0x10;
    }
    if (count == 0) {
        return 0;
    }
    unsigned int val = arr[func_0010423C(0, count - 1)];
    self->m_unk44 = val;
    self->m_obj->m_unk3EC[val >> 24] |= (val & mask);
    unsigned int f = self->m_obj->m_unk3EC[0];
    if ((f & 7) == 7 || (f & 0x1E) == 0x1E || (f & 0x19) == 0x19) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/TskDamage", func_001FAA70);
#endif

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
            func_00163E10(&D_007B2140, temp_v1_2, 0);
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
