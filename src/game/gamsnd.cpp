#include "include_asm.h"
extern char D_006E9800;
extern char D_002FD770;
extern "C" void *alloc__BedMemory(int, int, const char *, int, int, int) asm("alloc__9BedMemoryiPCciii");
extern "C" void *memset(void *, int, unsigned int);
extern "C" void func_001E107C(int);
extern "C" void func_001E1FA4(int);
extern "C" int atoi(const char *);
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
struct SndElem {
    char m_pad00[0x34];
    int m_unk34;            // +0x34 (node +0x3C)
    char m_pad38[0x20];
};

class SndIt {
public:
    SndNode *m_node;
    SndIt() : m_node(0) {}
    SndIt(SndNode *theNode) : m_node(theNode) {}
    SndIt(const SndIt &theIt) : m_node(theIt.m_node) {}
    SndElem &operator*() const { return *(SndElem *)((char *)m_node + 0x08); }
    SndIt &operator++()
    {
        m_node = m_node->m_next;
        return *this;
    }
    bool operator!=(const SndIt &theIt) const { return m_node != theIt.m_node; }
};

struct SndChain {
    SndNode m_head;         // +0x00
    int m_num;              // +0x60
    void init()
    {
        m_num = 0;
        m_head.m_prev = &m_head;
        m_head.m_next = &m_head;
    }
    SndIt begin() { return SndIt(m_head.m_next); }
    SndIt end() { return SndIt(&m_head); }
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
    char m_pad64[0x0C];
    SndChain m_used;        // +0x70
    char m_padD4[0x0C];
    int m_max;              // +0xE0
    void init(SndNode *theNodes, int theMax)
    {
        m_free.init();
        m_used.init();
        m_max = theMax;
        int i = 0;
        SndNode *p = theNodes;
        for (; i < m_max; i++) {
            p->m_prev = p - 1;
            p->m_next = p + 1;
            p++;
        }
        m_used.init();
        m_free.m_head.m_next = theNodes;
        m_free.m_num = m_max;
        theNodes[0].m_prev = &m_free.m_head;
        m_free.m_head.m_prev = &m_free.m_head.m_next[m_free.m_num - 1];
        m_free.m_head.m_prev->m_next = &m_free.m_head;
    }
    void clear()
    {
        if (m_used.m_num != 0)
            m_free.splice(m_used);
    }
};
extern "C" void __builtin_delete(void *);
extern int _vt$9GamSndMan;
struct Elem28 { int a[10]; };
struct Range { char *m_begin; char *m_end; int m_max; };
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

extern "C" int func_001E0BB0(char *arg0, int arg1)
{
    SndIt it;
    SndIt last;

    it = SndIt(*(SndNode **)(arg0 + 0x18454));
    last = ((SndChain *)(arg0 + 0x18450))->end();
    while (it != last) {
        if ((*it).m_unk34 == arg1)
            return 1;
        ++it;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0C2C);

extern "C" int func_001E0D70(char *arg0, int arg1)
{
    SndIt it;
    SndIt last;

    if (*(int *)(arg0 + 0x190) == 0)
        return 0;
    it = SndIt(*(SndNode **)(arg0 + 0xD4));
    last = ((SndChain *)(arg0 + 0xD0))->end();
    while (it != last) {
        if ((*it).m_unk34 == arg1)
            return 1;
        ++it;
    }
    return 0;
}

extern "C" void func_001E0DF0(char *arg0)
{
    Range *r;

    *(int **)(arg0 + 0x1874) = &_vt$9GamSndMan;
    ((SndQue *)(arg0 + 0x40))->init((SndNode *)(arg0 + 0x140), 0x20);
    r = (Range *)(arg0 + 0xD40);
    r->m_end = (char *)(arg0 + 0xD80);
    r->m_max = 0x30;
    r->m_begin = (char *)(arg0 + 0xD80);
}

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

extern "C" void func_001E0F1C(char *arg0)
{
    func_001E107C((int) arg0);
    func_001E1FA4((int) arg0);
    *(int *)(arg0 + 0x1540) = (int) alloc__BedMemory((int) &D_006E9800, 0xE000, &D_002FD770, 0x51, 0, 1);
    *(int *)(arg0 + 0x1544) = (int) alloc__BedMemory((int) &D_006E9800, 0xC4E0, &D_002FD770, 0x52, 0, 1);
    *(short *)(arg0 + 0x1576) = 0x80;
    *(short *)(arg0 + 0x1578) = 0x80;
    *(short *)(arg0 + 0x157A) = 0x6A4;
    *(short *)(arg0 + 0x157C) = 0x64;
    *(short *)(arg0 + 0x157E) = 0x80;
    *(short *)(arg0 + 0x1580) = 0;
    *(int *)(arg0 + 0x163C) = -1;
    *(int *)(arg0 + 0x170C) = -1;
    *(int *)(arg0 + 0x1710) = -1;
    *(int *)(arg0 + 0x1718) = -1;
    *(int *)(arg0 + 0x1684) = -1;
    *(int *)(arg0 + 0x15AC) = -1;
    *(int *)(arg0 + 0x1630) = 0;
    *(int *)(arg0 + 0x15A0) = 0;
    *(float *)(arg0 + 0x186C) = 0.5F;
    memset(arg0 + 0x1728, -1, 0x104);
}

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

extern "C" void func_001E43E0(int arg0, char *arg1, int *arg2, int *arg3)
{
    char buf[4];

    buf[0] = arg1[2];
    buf[1] = arg1[3];
    buf[2] = 0;
    *arg3 = atoi(buf);
    buf[2] = 0;
    buf[0] = arg1[0];
    buf[1] = arg1[1];
    *arg2 = atoi(buf);
}

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
