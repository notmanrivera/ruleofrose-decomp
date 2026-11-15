#include "include_asm.h"
static inline void noop(int *) {}
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

extern "C" void func_001E107C(int arg0)
{
    // Volatile only to keep the game's store order: plain stores let the
    // scheduler move the 4 below the two 0x80s (three instructions off).
    M2C_FIELD(arg0, volatile int *, 0x171C) = 4;
    M2C_FIELD(arg0, volatile int *, 0x1720) = 0x80;
    M2C_FIELD(arg0, volatile int *, 0x1724) = 0x80;
    M2C_FIELD(arg0, volatile int *, 0) = 0;
    Xiiiiiii_func_001E6734(arg0, 0xD, 0x80, 0x80, 0, -1);
    M2C_FIELD(arg0, int *, 0x1598) = 0x80;
    M2C_FIELD(arg0, int *, 0x159C) = 0x80;
    M2C_FIELD(arg0, int *, 0x1590) = 0x80;
    M2C_FIELD(arg0, int *, 0x1594) = 0x80;
    Xiiiiiii_func_001E6734(arg0, 0xE, 0x80, 0x80, 0, -1);
    Xiiiiiii_func_001E6734(arg0, 0xF, 0x80, 0x80, 0, -1);
}

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

// ---- once unk/TskMtnMove's head, the same file as the code above (config/splits_manual.tsv);
// its declarations as they were there:
struct Ent63C0 {
    int unk0;
    int unk4;
    int unk8;
    int unk0C;
    char pad10[0x28 - 0x10];
};
struct Sub63C0 {
    Ent63C0 *arr;
};
struct Obj63C0 {
    char pad0[0xD40];
    Sub63C0 sub;
};
extern "C" int func_00180CA8(int *, int);
extern "C" void func_00180CE0(int *, int, int, int, int, float);
struct VObj7544 {
    virtual int vfunc1();
};
struct Node7544 {
    VObj7544 *obj;
    Node7544 *next;
    int state;
};
struct List7544 {
    Node7544 *head;
};
extern "C" void X7544_func_001E7340(List7544 *, Node7544 *, int) asm("func_001E7340");
struct VObj7340 {
    virtual int vfunc1();
    virtual void vfunc2(int);
};
struct Node7340 {
    VObj7340 *obj;
    Node7340 *next;
    int state;
};
struct Ent4B48 {
    char name[0x1C];
    int id;
    long unk20;
    long unk28;
    long unk30;
};
struct Obj4B48 {
    char pad[0x1544];
    Ent4B48 *list;
};
struct VObj747C {
    virtual int vfunc1();
};
struct Node747C {
    VObj747C *obj;
    Node747C *next;
    int state;
};
struct List747C {
    Node747C *head;
};
extern "C" void X747C_func_001E7340(List747C *, Node747C *, int) asm("func_001E7340");
struct Ent5D1C {
    char pad0[0x14];
    int unk14;
    int unk18;
    char pad1C[0x28 - 0x1C];
};
struct Sub5D1C {
    Ent5D1C *arr;
};
struct Obj5D1C {
    char pad0[0xD40];
    Sub5D1C sub;
};
extern "C" int func_001800D0(int *, int);
extern "C" void func_001801C8(int *, int);
struct Big484C {
    int w[0xC4E0 / 4];
};
struct Obj484C {
    char pad[0x1544];
    Big484C *unk1544;
};
struct Big4790 {
    int w[0xE000 / 4];
};
struct Obj4790 {
    char pad[0x1540];
    Big4790 *unk1540;
};
struct VObj7910 {
    virtual int vfunc1();
};
struct Node7910 {
    VObj7910 *obj;
    Node7910 *next;
    int state;
    int id;
};
struct List7910 {
    Node7910 *head;
};
extern "C" void X7910_func_001E7724(List7910 *, int) asm("func_001E7724");
struct Node785C {
    void *obj;
    Node785C *next;
    int state;
    int id;
};
struct Obj785C {
    Node785C *head;
    char pad4[0x80];
    int arr[0x80];
    int *end;
};
extern "C" void X785C_func_001E7D08(Obj785C *, Node785C *) asm("func_001E7D08");
struct Obj6D54 {
    void *unk0;
    int unk4;
    float unk8;
    void *unkC;
};
extern "C" void func_00237340(void *);
extern "C" void func_00237830(void *, void *, float);
extern "C" void func_002378B0(void *, void *, int);
extern "C" void func_00237408(void *, void *, void *);
extern "C" void func_002375D8(void *, void *);
extern "C" float func_00237580(void *, void *);
struct Ent4A0C {
    char name[0x1C];
    int id;
    char pad[0x38 - 0x20];
};
struct Obj4A0C {
    char pad[0x1540];
    Ent4A0C *list;
};
struct VObj77B4 {
    virtual int vfunc1();
};
struct Node77B4 {
    VObj77B4 *obj;
    Node77B4 *next;
    int state;
};
struct List77B4 {
    Node77B4 *head;
};
extern "C" void X77B4_func_001E7698(List77B4 *, Node77B4 *) asm("func_001E7698");
extern "C" void X77B4_func_001E7D08(List77B4 *, Node77B4 *) asm("func_001E7D08");
struct Node70DC {
    int unk0;
    Node70DC *next;
};
struct Sub70DC {
    int unk0;
    ~Sub70DC() asm("func_00203DA8");
};
struct Obj70DC {
    Node70DC *head0;
    Node70DC *head4;
    char pad8[0x38];
    Sub70DC sub40;
    ~Obj70DC() asm("func_001E70DC");
};
extern "C" void X70DC_func_001E7C7C(Obj70DC *, Node70DC *) asm("func_001E7C7C");
struct Ent4C1C {
    char name[0x1C];
    int id;
    char pad[0x38 - 0x20];
};
struct Obj4C1C {
    char pad[0x1544];
    Ent4C1C *list;
};
extern "C" int X4E20_func_001E4D04(int, int) asm("func_001E4D04");
extern "C" int func_001E50C8(int, int, int, int, float, int, int, int);
struct Ent4970 {
    char name[0x1C];
    int unk1C;
    char pad[0x38 - 0x20];
};
struct Obj4970 {
    char pad[0x1540];
    Ent4970 *list;
};
struct Ent4D18 {
    char pad0[0xC];
    unsigned int unk0C;
    char pad10[0x8];
    int unk18;
    char pad1C[0x28 - 0x1C];
};
struct Obj4D18 {
    char pad0[0xD40];
    Ent4D18 *arr;
};
extern "C" void func_001E649C(Obj4D18 *, unsigned int, int);
struct Obj7724 {
    char pad0[0x84];
    int arr[0x80];
    int *end;
};
extern "C" int func_001E76B8(Obj7724 *);
struct Ent4AB8 {
    char name[0x1C];
    int id;
    char pad[0x38 - 0x20];
};
extern "C" int strcmp(const char *, const char *);
struct Obj7C7C {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct Node7C7C {
    Obj7C7C *obj;
    int pad[4];
    int flags;
};
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void *X_memset(void *, int, unsigned int) asm("memset");
struct TskObj7618 {
    virtual int vfunc1(int);
};
struct TskNode7618 {
    TskObj7618 *obj;
    TskNode7618 *next;
    int state;
};
extern "C" int Xiiii_func_001E4908(int, int, int, int) asm("func_001E4908");
extern "C" int Xii_func_001E4D04(int) asm("func_001E4D04");
extern "C" int Xiiiiii_func_001E4EBC(int, int, int, int, int) asm("func_001E4EBC");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001E7DE8(int, int) asm("func_001E7DE8");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010A834__8DogActor(...) asm("func_0010A834__8DogActor");
extern "C" int X_func_0017F5E8(...) asm("func_0017F5E8");
extern "C" int X_func_001800D0(...) asm("func_001800D0");
extern "C" int X_func_001801C8(...) asm("func_001801C8");
extern "C" int X_func_00180B30(...) asm("func_00180B30");
extern "C" int X_func_00180CA8(...) asm("func_00180CA8");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" int X_func_001E46B8(...) asm("func_001E46B8");
extern "C" int X_func_001E4A0C(...) asm("func_001E4A0C");
extern "C" int X_func_001E4D04(...) asm("func_001E4D04");
extern "C" int X_func_001E4EBC(...) asm("func_001E4EBC");
extern "C" int X_func_001E649C(...) asm("func_001E649C");
extern "C" int X_func_001E7340(...) asm("func_001E7340");
extern "C" int X_func_001E7698(...) asm("func_001E7698");
extern "C" int X_func_001E76B8(...) asm("func_001E76B8");
extern "C" int X_func_001E7D08(...) asm("func_001E7D08");
extern "C" int X_func_001E7DE8(...) asm("func_001E7DE8");
extern "C" int X_func_00203D94(...) asm("func_00203D94");
extern "C" int X_func_0023A080(...) asm("func_0023A080");
extern "C" int X_func_0023A0B8(...) asm("func_0023A0B8");
extern "C" int X_strcmp(...) asm("strcmp");
extern int D_006FE6A0;
extern int D_007B2580;

extern "C" void func_001E46B8(int arg0, int arg1)
{
    X_func_00180B30((int)&D_007B2580);
    (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x1728)) = -1;
}


extern "C" void func_001E4700(int arg0)
{
    X_func_0017F5E8((int)&D_007B2580, 8);
    X_func_001E46B8(arg0, 0);
    X_func_001E46B8(arg0, 0xA);
    X_func_001E46B8(arg0, 0xB);
    X_func_001E46B8(arg0, 0xC);
    X_func_001E46B8(arg0, 0x1F);
    X_func_001E46B8(arg0, 0x20);
    X_func_001E46B8(arg0, 0x21);
    X_func_001E46B8(arg0, 0x40);
}


extern "C" void func_001E4790(Obj4790 *arg0, int arg1, const Big4790 *arg2)
{
    *arg0->unk1540 = *arg2;
}

extern "C" void func_001E484C(Obj484C *arg0, int arg1, const Big484C *arg2)
{
    *arg0->unk1544 = *arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4908);

extern "C" int func_001E4970(Obj4970 *arg0, const char *arg1, Ent4970 **arg2)
{
    Ent4970 *p = arg0->list;
    if (p == 0) {
        return 0;
    }
    int i = 0;
    while (i++ < 0x400 && p->unk1C != 0) {
        if (strcmp(arg1, p->name) == 0) {
            *arg2 = p;
            return 1;
        }
        p++;
    }
    *arg2 = 0;
    return 0;
}

extern "C" int func_001E4A0C(Obj4A0C *arg0, const char *arg1)
{
    Ent4A0C *p = arg0->list;
    if (*arg1 == '.' || *arg1 == '*') {
        arg1++;
    }
    if (p == 0) {
        return 0;
    }
    int i = 0;
    while (i++ < 0x400 && p->id != -1) {
        if (strcmp(arg1, p->name) == 0) {
            return p->id;
        }
        p++;
    }
    return 0;
}

extern "C" int func_001E4AB8(void *arg0, const char *arg1)
{
    Ent4AB8 *p = *(Ent4AB8 **)((char *)arg0 + 0x1544);
    if (p == 0) {
        return 0;
    }
    int i = 0;
    while (i++ < 0x384 && p->id != -1) {
        if (strcmp(arg1, p->name) == 0) {
            return p->id;
        }
        p++;
    }
    return 0;
}

extern "C" int func_001E4B48(Obj4B48 *arg0, int arg1, Ent4B48 *arg2)
{
    int idx = (arg1 % 100000) / 2;
    for (int i = 0; i < 0x384; i++, idx++) {
        if (arg0->list[idx].id == -1 || idx >= 0x385) {
            idx = 0;
        }
        if (arg0->list[idx].id == arg1) {
            arg2->id = arg1;
            arg0->list[idx] = *arg2;
            return 1;
        }
    }
    return 0;
}

extern "C" int func_001E4C1C(Obj4C1C *arg0, int arg1, Ent4C1C **arg2)
{
    int idx = (arg1 % 100000) / 2;
    for (int i = 0; i < 0x384; i++, idx++) {
        if (arg0->list[idx].id == -1 || idx >= 0x385) {
            idx = 0;
        }
        if (arg0->list[idx].id == arg1) {
            *arg2 = &arg0->list[idx];
            return 1;
        }
    }
    *arg2 = 0;
    return 0;
}

extern "C" int func_001E4CBC()
{
    return 0;
}


extern "C" void func_001E4CC4(int arg0, int arg1, int arg2, int arg3)
{
    (*(int *)(int *)((char *)(arg0) + 0x1720)) = arg2;
    (*(int *)(int *)((char *)(arg0) + 0x1724)) = arg3;
    (*(int *)(int *)((char *)(arg0) + 0x171C)) = arg1;
    X_func_0023A080(arg1);
    X_func_0023A0B8((*(int *)(int *)((char *)(arg0) + 0x1720)), (*(int *)(int *)((char *)(arg0) + 0x1724)));
}


extern "C" int func_001E4D04()
{
    return X_func_001E4A0C();
}


extern "C" void func_001E4D18(Obj4D18 *arg0, int arg1)
{
    if (arg1 == 0) {
        return;
    }
    if (arg1 == 1) {
        for (int i = 0; i < 0x30; i++) {
            if (arg1 == 1) {
                Ent4D18 *e = &arg0->arr[i];
                if ((e->unk0C >> 24) != 0xB) {
                    func_001E649C(arg0, e->unk0C, e->unk18);
                }
            }
        }
    }
}

extern "C" int func_001E4DB0(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    temp_v0 = Xii_func_001E4D04((int) arg0);
    if (temp_v0 != 0) {
        return Xiiiiii_func_001E4EBC(arg0, temp_v0, arg2, arg3, 0);
    }
    return -1;
}

extern "C" int func_001E4E20(int arg0, int arg1, int arg2, int arg3, int arg4, float fparg0)
{
    int temp_v0 = X4E20_func_001E4D04(arg0, arg1);
    if (temp_v0 != 0) {
        return func_001E50C8(arg0, temp_v0, arg2, arg3, fparg0, arg4, 0, 0);
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4EBC);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E50C8);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5250);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5428);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5540);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5660);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5B60);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5BE0);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5C40);

extern "C" int func_001E5D1C(Obj5D1C *arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        return 0;
    }
    if (func_001800D0(&D_007B2580, arg2) == -1) {
        return 0;
    }
    Sub5D1C *sub = &arg0->sub;
    int off = arg2 * sizeof(Ent5D1C);
    if (((Ent5D1C *)((char *)sub->arr + off))->unk14 != arg1) {
        return 0;
    }
    func_001801C8(&D_007B2580, arg2);
    ((Ent5D1C *)((char *)sub->arr + off))->unk14 = -1;
    ((Ent5D1C *)((char *)sub->arr + off))->unk18 = -1;
    return 1;
}

extern "C" void func_001E5DE4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    int p[4];

    if (Xiiii_func_001E4908(arg0, arg1, (int)p, 1) != 0) {
        *(short *)(p[0] + 0x2A) = arg2;
        *(short *)(p[0] + 0x2C) = arg3;
        *(short *)(p[0] + 0x2E) = arg4;
        *(short *)(p[0] + 0x30) = arg5;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5E58);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6368);

extern "C" int func_001E63C0(Obj63C0 *arg0, int arg1, int arg2, int arg3, int arg4)
{
    if (arg2 < 0) {
        return 0;
    }
    Sub63C0 *sub = &arg0->sub;
    int off = arg2 * sizeof(Ent63C0);
    if (((Ent63C0 *)((char *)sub->arr + off))->unk0C != arg1) {
        return 0;
    }
    if (func_00180CA8(&D_007B2580, arg2) == -1) {
        return 0;
    }
    ((Ent63C0 *)((char *)sub->arr + off))->unk4 = arg3;
    ((Ent63C0 *)((char *)sub->arr + off))->unk8 = arg4;
    func_00180CE0(&D_007B2580, arg2, arg3, arg4, 0, -1024.0f);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E649C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6570);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6734);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6CAC);

extern "C" float func_001E6D54(Obj6D54 *arg0)
{
    char mat[0x40];
    char vec[0x10];

    func_00237340(mat);
    func_00237830(mat, mat, arg0->unk8);
    func_002378B0(mat, mat, arg0->unk4);
    func_00237408(vec, arg0->unkC, arg0->unk0);
    func_002375D8(vec, vec);
    return ((func_00237580(mat + 0x20, vec) + 1.0f) * 0.5f * 0.7f) + 0.3f;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6E00);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7094);

Obj70DC::~Obj70DC()
{
    Node70DC *p = head4;
    while (p != 0) {
        Node70DC *cur = p;
        p = p->next;
        X70DC_func_001E7C7C(this, cur);
    }
    p = head0;
    while (p != 0) {
        Node70DC *cur = p;
        p = p->next;
        X70DC_func_001E7C7C(this, cur);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7184);

extern "C" void func_001E71F4(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E71FC);

extern "C" void func_001E7340(void *arg0, Node7340 *arg1, int arg2)
{
    int id = arg1->obj->vfunc1();
    if ((id == 0x10 || id == 5 || id == 0x13 || id == 0x14) && arg1->state != arg2) {
        if (arg2 == 1) {
            arg1->obj->vfunc2(1);
        } else if (arg2 == 0) {
            arg1->obj->vfunc2(0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7414);

extern "C" void func_001E747C(List747C *arg0, int *arg1, int arg2)
{
    for (Node747C *node = arg0->head; node != 0; node = node->next) {
        for (int *p = arg1; *p != -1; p++) {
            if (node->obj->vfunc1() == *p && node->state != 2) {
                X747C_func_001E7340(arg0, node, arg2);
                node->state = arg2;
            }
        }
    }
}

extern "C" void func_001E7544(List7544 *arg0, int arg1)
{
    for (Node7544 *node = arg0->head; node != 0; node = node->next) {
        int id = node->obj->vfunc1();
        if ((node->obj == 0 || (id != 1 && id != 0x12 && id != 2 && id != 7 && id != 0xF && id != 0x17 && id != 0x11 && id != 5)) && node->state != 2) {
            X7544_func_001E7340(arg0, node, arg1);
            node->state = arg1;
        }
    }
}

extern "C" void func_001E7618(TskNode7618 **arg0, int arg1)
{
    TskNode7618 *p = *arg0;
    if (p != 0) {
        do {
            int res = p->obj->vfunc1(arg1);
            arg1 = 2;
            if (p->obj == 0 || ((unsigned int)(res - 1) >= 3U && res != 0x11)) {
                p->state = 2;
            }
            p = p->next;
        } while (p != 0);
    }
}

extern "C" void func_001E7698(int arg0, int arg1)
{
    if (arg1 != 0) {
        Xiii_func_001E7DE8((int) arg0, M2C_FIELD(arg1, int *, 0xC));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E76B8);

extern "C" void func_001E7724(Obj7724 *arg0, int arg1)
{
    if (arg1 != -1 && func_001E76B8(arg0) == 0) {
        for (int *p = arg0->arr; p != arg0->end; p++) {
            if (*p == arg1) {
                return;
            }
        }
        *arg0->end = arg1;
        arg0->end++;
    }
}

extern "C" void func_001E77B4(List77B4 *arg0, int arg1)
{
    Node77B4 *p = arg0->head;
    while (p != 0) {
        if (p->state != 2) {
            VObj77B4 *obj = p->obj;
            if (obj != 0 && arg1 == obj->vfunc1()) {
                X77B4_func_001E7D08(arg0, p);
                p->state = 2;
                X77B4_func_001E7698(arg0, p);
            }
        }
        p = p->next;
    }
}

extern "C" void func_001E785C(Obj785C *arg0)
{
    Node785C *node = arg0->head;
    while (node != 0 && arg0->end != arg0->arr) {
        int *p = arg0->arr;
        if (node->state != 2) {
            do {
                if (node->id == *p) {
                    X785C_func_001E7D08(arg0, node);
                    node->state = 2;
                    if (--arg0->end == arg0->arr) {
                        return;
                    }
                }
                p++;
            } while (p < arg0->end);
        }
        node = node->next;
    }
}

extern "C" void func_001E7908(void) {
}

extern "C" void func_001E7910(List7910 *arg0, int *arg1)
{
    Node7910 *node = arg0->head;
    while (node != 0) {
        Node7910 *next = node->next;
        for (int *p = arg1; *p != -1; p++) {
            if (node->obj->vfunc1() == *p) {
                X7910_func_001E7724(arg0, node->id);
            }
        }
        node = next;
    }
}

extern "C" int func_001E79C0(char *arg0, int arg1)
{
    char *n = M2C_FIELD(arg0, char **, 4);

    while (n != 0) {
        if (M2C_FIELD(n, int *, 0xC) == arg1) {
            return M2C_FIELD(n, int *, 0);
        }
        n = M2C_FIELD(n, char **, 4);
    }
    n = M2C_FIELD(arg0, char **, 0);
    while (n != 0) {
        if (M2C_FIELD(n, int *, 0xC) == arg1) {
            return M2C_FIELD(n, int *, 0);
        }
        n = M2C_FIELD(n, char **, 4);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7A20);

extern "C" void func_001E7C7C(void *arg0, Node7C7C *arg1)
{
    X_func_001E7698(arg0, arg1);
    if (arg1->obj != 0) {
        arg1->obj->v5();
        if (arg1->flags & 1) {
            X___builtin_delete(arg1->obj);
            arg1->flags &= ~1;
        }
        arg1->obj = 0;
    }
    X_memset(arg1, 0, 0x40);
    X___builtin_delete(arg1);
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7D08);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7D7C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7DE8);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7E50);

extern "C" int TskTest__vfunc_04()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7ED8);

extern "C" int TskLogger__vfunc_04()
{
    int x;
    noop(&x);
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD900);
INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD910);
INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD920);
