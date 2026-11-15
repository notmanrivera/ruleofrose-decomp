#include "include_asm.h"
struct Vec3 {
    float m_x;
    float m_y;
    float m_z;
};
extern char D_006FBD80;
extern "C" void func_001E3C24(int, Vec3 *);
struct SndChain;
struct SndNode {
    SndNode *m_prev;        // +0x00
    SndNode *m_next;        // +0x04
    char m_data[0x58];      // +0x08
};
struct SndChain {
    SndNode m_head;         // +0x00
    int m_num;              // +0x60
    void splice(SndChain &theOther)
    {
        if (theOther.m_num != 0) {
            m_head.m_prev->m_next = theOther.m_head.m_next;
            SndNode *last = m_head.m_prev;
            last->m_next->m_prev = last;
            SndNode *tail = theOther.m_head.m_prev;
            m_head.m_prev = tail;
            tail->m_next = &m_head;
            m_num += theOther.m_num;
            theOther.m_num = 0;
            theOther.m_head.m_prev = &theOther.m_head;
            theOther.m_head.m_next = &theOther.m_head;
        }
    }
};
struct SndQue {
    SndChain m_free;        // +0x00
    char m_pad00[0x0C];
    SndChain m_used;        // +0x70
    int m_max;              // +0xE0
    void clear()
    {
        if (m_used.m_num != 0)
            m_free.splice(m_used);
    }
};
extern "C" void __builtin_delete(void *);
extern int _vt$9GamSndMan;
struct Elem28 { int a[10]; };
struct Range { char *m_begin; char *m_end; };
extern "C" void func_001E43E0(int, char *, int *, int *);
extern "C" void func_001E44B4(int, int, int, int, int);
extern "C" int func_001E4908(int, int, int *, int) asm("func_001E4908");
extern "C" int func_001E43A4(int, unsigned int, int, unsigned int);
struct m2c_block36 { int w[9]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiiii_func_001809D8(int, int, int, int) asm("func_001809D8");
extern "C" int Xiiiiiii_func_001E6734(int, int, int, int, int, int) asm("func_001E6734");
extern int D_007B2580;
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0BB0);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0C2C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0D70);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0DF0);

extern "C" void GamSndMan__vfunc_01(char *arg0, int arg1)
{
    Range *r;
    Elem28 *p;
    Elem28 *e;

    *(int **)(arg0 + 0x1874) = &_vt$9GamSndMan;
    r = (Range *)(arg0 + 0xD40);
    e = (Elem28 *)r->m_end;
    p = (Elem28 *)r->m_begin;
    while (p != e) {
        p->~Elem28();
        p++;
    }
    if (arg1 & 1) {
        return __builtin_delete(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0F1C);

extern "C" void func_001E100C(int arg0, Vec3 *v)
{
    Vec3 tmp;
    char *base;
    float *src;

    if (*(int *)(arg0 + 0x110) != 0) {
        if (*(int *)(arg0 + 0) == 1) {
            base = &D_006FBD80;
            src = (float *)(base + 0x2AB70);
            tmp.m_x = src[0x10];
            tmp.m_y = src[0x11];
            tmp.m_z = src[0x12];
            func_001E3C24(arg0, &tmp);
        } else {
            func_001E3C24(arg0, v);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E107C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E111C);

extern "C" void func_001E15D0(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x1684) = 0;
    *(m2c_block36 *)((char *)(arg0) + 0x15a0) = *(m2c_block36 *)((char *)(arg1) + 0x0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1620);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E17B4);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1920);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1FA4);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2178);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2350);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E239C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2704);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2AA0);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2C40);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2DB4);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3138);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E34EC);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3698);

extern "C" void func_001E3804(char *arg0)
{
    ((SndQue *)(arg0 + 0x40))->clear();
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E386C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3C24);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4120);

extern "C" void func_001E4354(void) {
}

extern "C" int func_001E435C(int arg0, int arg1)
{
    int *p;
    int r;

    r = func_001E4908(arg0, arg1, (int *) &p, 1);
    if (r != 0) {
        r = func_001E43A4(arg0, *(unsigned short *) ((char *) p + 0x20),
                          *(unsigned short *) ((char *) p + 0x32), 1);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E43A4);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E43E0);

extern "C" void func_001E4458(int arg0, char *arg1, int arg2, int arg3)
{
    int a;
    int b;

    func_001E43E0(arg0, arg1, &a, &b);
    func_001E44B4(arg0, a, b, arg2, arg3);
}

extern "C" void func_001E44B4(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    Xiiiiiii_func_001E6734(arg0, 0x11, 0, 0, 0, -1);
    Xiiiii_func_001809D8((int) (int)&D_007B2580, arg1, arg3, arg4);
    M2C_FIELD(((arg1 * 4) + arg0), int *, 0x1728) = arg2;
}

INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD770);

INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD780);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4540);
