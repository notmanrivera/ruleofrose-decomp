#include "ror.h"
#include "include_asm.h"
#include "utl/filereader.h"
struct Vec2DB4 { float m_x,m_y,m_z; }; // vec2DB4
extern "C" float sqrtf(float); // decl2DB4
extern "C" int scene2DB4(void *) asm("func_001C6C28"); // decl2DB4
extern "C" void *find2DB4(void *, int) asm("func_0017EA44"); // decl2DB4
extern "C" int lookup2DB4(void *, unsigned int, void **) asm("func_001E4C1C"); // decl2DB4
extern "C" int check2DB4(void *, unsigned int, int, void *) asm("func_001E5660"); // decl2DB4
extern "C" int play2DB4(void *, unsigned int, int, Vec2DB4 *, int, int) asm("func_001E5250"); // decl2DB4
extern char world2DB4[] asm("D_007812C0"); // decl2DB4
extern char bank2DB4[] asm("D_00298EE0"); // decl2DB4
struct ALIGNED(16) Item2DB4 { // decl2DB4
    char unused[0x10];
    Vec2DB4 position; // decl2DB4
    int pad1C; // decl2DB4 // decl2DB4
    unsigned int id; // decl2DB4
    int handle; // decl2DB4
    unsigned int flags; // decl2DB4
    int zero; // decl2DB4
    int scene; // decl2DB4
    void *data; // decl2DB4
    float distance; // decl2DB4
    int a,b; // decl2DB4
    char tail[12]; // decl2DB4
}; // item2DB4 // decl2DB4
struct Node2DB4 { Node2DB4 *prev,*next; Item2DB4 data; }; // node2DB4 // decl2DB4
class Iter2DB4 { public: // decl2DB4
    Node2DB4 *node; // decl2DB4
    Iter2DB4() : node(0) {} // decl2DB4
    Iter2DB4(Node2DB4 *n) : node(n) {} // decl2DB4
    Iter2DB4(const Iter2DB4 &n) : node(n.node) {} // decl2DB4
    Item2DB4 &operator*() const { return node->data; } // decl2DB4
    Iter2DB4 &operator++() { node = node->next; return *this; } // decl2DB4
    bool operator!=(const Iter2DB4 &n) const { return node != n.node; } // decl2DB4
}; // iter2DB4 // decl2DB4
struct Chain2DB4 { // decl2DB4
    Node2DB4 head; // decl2DB4
    int count; // decl2DB4
    void insert(Node2DB4 *target, Node2DB4 *n) { // decl2DB4
        Node2DB4 *p = target->prev; // decl2DB4
        n->prev = p; // decl2DB4
        p->next = n; // decl2DB4
        n->next = target; // decl2DB4
        target->prev = n; // decl2DB4
        ++count; // decl2DB4
    } // decl2DB4
    void push(Node2DB4 *n) { // decl2DB4
        if (count == 0) { head.next = n; n->prev = &head; } // decl2DB4
        else { head.prev->next = n; n->prev = head.prev; } // decl2DB4
        n->next = &head; // decl2DB4
        head.prev = n; // decl2DB4
        ++count; // decl2DB4
    } // decl2DB4
}; // chain2DB4 // decl2DB4
struct Que2DB4 { // decl2DB4
    Chain2DB4 free, used; // decl2DB4
    Iter2DB4 begin() { return Iter2DB4(used.head.next); } // decl2DB4
    Iter2DB4 end() { return Iter2DB4(&used.head); } // decl2DB4
    Iter2DB4 insert(Iter2DB4 where, const Item2DB4 &item) { // decl2DB4
        Node2DB4 *n = free.head.prev; // decl2DB4
        Node2DB4 *previous = n->prev; // decl2DB4
        free.head.prev = previous; // decl2DB4
        previous->next = &free.head; // decl2DB4
        --free.count; // decl2DB4
        n->data = item; // decl2DB4
        used.insert(where.node, n); // decl2DB4
        return where; // decl2DB4
    } // decl2DB4
    void push(const Item2DB4 &item) { // decl2DB4
        Node2DB4 *n = free.head.prev; // decl2DB4
        Node2DB4 *previous = n->prev; // decl2DB4
        free.head.prev = previous; // decl2DB4
        previous->next = &free.head; // decl2DB4
        --free.count; // decl2DB4
        n->data = item; // decl2DB4
        used.push(n); // decl2DB4
    } // decl2DB4
}; // que2DB4 // decl2DB4
struct Obj2DB4 { char pad[0x40]; Que2DB4 queue; }; // obj2DB4 // decl2DB4
struct Vec5250 { // 5250
    float x, y, z, w; // 5250
}; // 5250
struct Ent5250 { // 5250
    int unk00; // 5250
    int unk04; // 5250
    int unk08; // 5250
    char pad0C[8]; // 5250
    int unk14; // 5250
    int unk18; // 5250
    char pad1C[0xC]; // 5250
}; // 5250
struct Sub5250 { // 5250
    Ent5250 *arr; // 5250
}; // 5250
struct Obj5250 { // 5250
    int unk0; // 5250
    char pad4[0xD40 - 4]; // 5250
    Sub5250 sub; // 5250
}; // 5250
extern "C" { // 5250
extern int X_5250_D_007B2580 asm("D_007B2580"); // 5250
int X_5250_snprintf(char *, unsigned int, const char *, ...) asm("snprintf"); // 5250
int X_5250_func_001E4C1C(Obj5250 *, int, void **) asm("func_001E4C1C"); // 5250
void X_5250_func_001E6E00(int, Vec5250 *, void *, int *, int *, float) asm("func_001E6E00"); // 5250
int X_5250_func_0017FD58(int *, char *, int, int, int) asm("func_0017FD58"); // 5250
void X_5250_func_00180078(int *, int, int) asm("func_00180078"); // 5250
void X_5250_func_0017FF58(int *, float, int, int, int, int) asm("func_0017FF58"); // 5250
} // 5250
struct Ent6570 { // 6570
    unsigned int flags; // 6570
    char pad4[0x10]; // 6570
    int unk14; // 6570
    int unk18; // 6570
    char pad1C[0x28 - 0x1C]; // 6570
    Ent6570() { unk14 = -1; unk18 = -1; } // 6570
    bool isFree() const { return (flags & 1) == 0; } // 6570
}; // Ent6570
struct Sub6570 { // 6570
    Ent6570 *arr; // 6570
}; // Sub6570
struct Obj6570 { // 6570
    char pad0[0xD40]; // 6570
    Sub6570 sub; // 6570
}; // Obj6570
struct Msg50C8 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float unk18;
    char pad1C[0x40 - 0x1C];
};
struct Elem28_50C8 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    char pad1C[0x28 - 0x1C];
};
struct Range50C8 {
    char *m_begin;
    char *m_end;
    int m_max;
};
struct TskMan50C8 {
    char pad00[0x58];
    int m_prio;
};
struct SysFlg50C8 {
    unsigned int m_sysFlg;
    bool chkSysFlg(unsigned int theFlg) const { return (m_sysFlg & theFlg) != 0; }
};
extern TskMan50C8 X_50C8_D_007A3D80 asm("D_007A3D80");
extern SysFlg50C8 X_50C8_D_007A320C asm("D_007A320C");
extern int X_50C8_D_007B2580 asm("D_007B2580");
extern "C" void *X_50C8_builtin_new(unsigned int) asm("__builtin_new");
extern "C" void X_50C8_func_001F8FC0(void *, unsigned int, Msg50C8 *) asm("func_001F8FC0");
extern "C" int X_50C8_func_001E71FC(void *, int, int, int, int, void *, int, int, int) asm("func_001E71FC");
extern "C" int X_50C8_func_0017F8FC(void *, int) asm("func_0017F8FC");
extern "C" void X_50C8_func_00180CE0(void *, int, int, int, float, int) asm("func_00180CE0");
extern "C" void *X_4540_alloc__BedMemory(int, int, const char *, int, int, int) asm("alloc__9BedMemoryiPCciii");
extern "C" void X_4540_heapFree(void *) asm("heapFree__FPv");
extern "C" char *X_4540_strcpy(char *, const char *) asm("strcpy");
extern "C" int X_4540_snprintf(char *, int, const char *, ...) asm("snprintf");
extern "C" void X_4540_func_001E43E0(int, char *, int *, int *) asm("func_001E43E0");
extern "C" void X_4540_func_001E44B4(int, int, int, void *, int) asm("func_001E44B4");
extern "C" int X_4540_func_001E6734(int, int, int, int, int, int) asm("func_001E6734");
struct SndMsg17B4 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    char pad18[0x40 - 0x18];
};
struct Ent15A0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    char pad10[0x24 - 0x10];
};
struct Ent1654 {
    int unk00;
    int unk04;
    int unk08;
};
struct Ent1680 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct Obj17B4 {
    char pad0000[0x15A0];
    Ent15A0 arr15A0[5];     // +0x15A0
    Ent1654 arr1654[3];     // +0x1654
    char pad1678[0x1680 - 0x1678];
    Ent1680 arr1680[8];     // +0x1680 (arr1680[0].unk04 is +0x1684)
    int unk1700;
    int unk1704;
    int unk1708;            // +0x1708
    char pad170C[0x1870 - 0x170C];
    int unk1870;            // +0x1870
};
extern "C" void X_17B4_func_001E111C(Obj17B4 *, int) asm("func_001E111C");
extern "C" int X_17B4_func_001E5660(Obj17B4 *, int, int, SndMsg17B4 *) asm("func_001E5660");
extern "C" int X_17B4_func_001E5E58(Obj17B4 *, int, int, SndMsg17B4 *) asm("func_001E5E58");
extern "C" void X_17B4_func_001E4120(Obj17B4 *) asm("func_001E4120");
struct VObj71FC {
    virtual int v1();
    virtual void v2();
    virtual void v3();
};
struct Node71FC {
    VObj71FC *obj;      // +0x00
    Node71FC *next;     // +0x04
    int state;          // +0x08
    int id;             // +0x0C
    int *unk10;         // +0x10
    void *unk14;        // +0x14
    void *unk18;        // +0x18
    int unk1C;          // +0x1C
    int unk20;          // +0x20
    int unk24;          // +0x24
    int unk28;          // +0x28
    int unk2C;          // +0x2C
    int unk30;          // +0x30
    int prio;           // +0x34
    char pad38[0x40 - 0x38];
};
struct Obj71FC {
    Node71FC *head0;    // +0x00
    Node71FC *head4;    // +0x04
    int nextId;         // +0x08
    char pad0C[0x58 - 0x0C];
    int unk58;          // +0x58
};
extern "C" void *X_71FC___builtin_new(unsigned int) asm("__builtin_new");
extern "C" void X_71FC_func_001E7E50(Obj71FC *, int) asm("func_001E7E50");
extern "C" void X_71FC_func_001E7184(Obj71FC *, Node71FC *) asm("func_001E7184");
struct Ent5540 {
    char pad00[0x2A];
    short unk2A;
    short unk2C;
    short unk2E;
    short unk30;
    char pad32[0x38 - 0x32];
};
struct Obj5540 {
    char pad00[0x1550];
    Ent5540 unk1550;
};
extern "C" int X_5540_func_001E4C1C(Obj5540 *, int, Ent5540 **) asm("func_001E4C1C");
extern "C" int X_5540_func_001E4B48(Obj5540 *, int, Ent5540 *) asm("func_001E4B48");
struct Ent5428 {
    int unk00;
    int unk04;
    int unk08;
    char pad0C[0x14 - 0x0C];
    int unk14;
    int unk18;
    char pad1C[0x28 - 0x1C];
};
struct Sub5428 {
    Ent5428 *arr;
};
struct Obj5428 {
    char pad0[0xD40];
    Sub5428 sub;
};
extern int X_5428_D_007B2580 asm("D_007B2580");
extern "C" void X_5428_func_00180078(int *, int, int) asm("func_00180078");
extern "C" void X_5428_func_0017FF58(int *, int, int, int, int, float) asm("func_0017FF58");
extern "C" int X_5428_func_001E5250(Obj5428 *, int, int, int, int, int) asm("func_001E5250");
struct Ent5C40 {
    int unk00;
    int unk04;
    int unk08;
    char pad0C[0x14 - 0x0C];
    int unk14;
    char pad18[0x28 - 0x18];
};
struct Sub5C40 {
    Ent5C40 *arr;
};
struct Obj5C40 {
    char pad0[0xD40];
    Sub5C40 sub;
};
extern int X_5C40_D_007B2580 asm("D_007B2580");
extern "C" int X_5C40_func_001800D0(int *, int) asm("func_001800D0");
extern "C" void X_5C40_func_0017FF58(int *, int, int, int, int, float) asm("func_0017FF58");
struct Ent6CAC {
    unsigned int flags;
    char pad4[0x10];
    int unk14;
    int unk18;
    char pad1C[0x28 - 0x1C];
    bool isFree() const { return (flags & 1) == 0; }
};
struct Sub6CAC {
    Ent6CAC *arr;
};
struct Obj6CAC {
    char pad0[0xD40];
    Sub6CAC sub;
};
extern int X_6CAC_D_007B2580 asm("D_007B2580");
extern "C" int X_6CAC_func_001800D0(int *, int) asm("func_001800D0");
struct Ent5B60 {
    char pad0[0x14];
    int unk14;
    char pad18[0x28 - 0x18];
};
struct Sub5B60 {
    Ent5B60 *arr;
};
struct Obj5B60 {
    char pad0[0xD40];
    Sub5B60 sub;
};
extern int X_5B60_D_007B2580 asm("D_007B2580");
extern "C" int X_5B60_func_001800D0(int *, int) asm("func_001800D0");
struct Obj7D08 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct Node7D08 {
    Obj7D08 *obj;
    int pad[4];
    int flags;
};
extern "C" void X_7D08___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_7D08_func_001E7698(void *, Node7D08 *) asm("func_001E7698");
struct Node7184 {
    void *obj;
    Node7184 *next;
    char pad08[0x2C];
    unsigned int prio;
};
struct List7184 {
    Node7184 *head;
};
struct Sub7D7C {
    char pad[0x280];
    int arr[0x100];
};
struct TskLogger7D7C {
    void *vt;
    int unk04;
    Sub7D7C sub;
};
struct Node76B8 {
    void *obj;
    Node76B8 *next;
    int state;
    int unk0C;
};
struct List76B8 {
    Node76B8 *head;
};
extern "C" void X_76B8_func_001E7698(List76B8 *, Node76B8 *) asm("func_001E7698");
extern "C" int X_def_func_001E76B8(List76B8 *arg0, int arg1) asm("func_001E76B8");
struct Sub7DE8 {
    char pad[0x280];
    int arr[0x100];
};
struct TskLogger7DE8 {
    void *vt;
    int unk04;
    Sub7DE8 sub;
};
struct Node7414 {
    void *obj;
    Node7414 *next;
    int state;
    int unk0C;
};
struct List7414 {
    Node7414 *head;
};
extern "C" void X_7414_func_001E7340(void *, Node7414 *, int) asm("func_001E7340");
struct Ent4908 {
    char name[0x1C];
    int unk1C;
    char pad[0x38 - 0x20];
};
struct Ent5BE0 {
    char pad0[0x14];
    int unk14;
    char pad18[0x28 - 0x18];
};
struct Sub5BE0 {
    Ent5BE0 *arr;
};
struct Obj5BE0 {
    char pad0[0xD40];
    Sub5BE0 sub;
};
extern int X_5BE0_D_007B2580 asm("D_007B2580");
extern "C" int X_5BE0_func_001800D0(int *, int) asm("func_001800D0");
struct Ent6368 {
    int unk0;
    int unk4;
    int unk8;
    int unk0C;
    char pad10[0x28 - 0x10];
};
struct Sub6368 {
    Ent6368 *arr;
};
struct Obj6368 {
    char pad0[0xD40];
    Sub6368 sub;
};
extern int X_6368_D_007B2580 asm("D_007B2580");
extern "C" int X_6368_func_00180CA8(int *, int) asm("func_00180CA8");
struct Sub7094 {
    char pad[0x44];
    Sub7094() asm("func_00203D94");
};
struct Obj7094 {
    int head0;
    int head4;
    int unk08;
    char pad0C[0x34];
    Sub7094 sub40;
    int arr[0x80];
    int *end;
    int unk288;
    Obj7094() asm("func_001E7094");
};
extern char D_007812C0[];
extern int _vt$9TskLogger;
extern "C" int X_7ED8_func_001CBE38(void *, unsigned int) asm("func_001CBE38");
struct TskLogger7ED8 {
    void *vt;
    int unk04;
    int unk08;
    TskLogger7ED8(int arg1) asm("func_001E7ED8");
};
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
extern "C" void X_237___builtin_delete(void *) asm("__builtin_delete");
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

// NON_MATCHING: func_001E0C2C itself is MATCH (0x144), blocked on .rodata alignment of D_002FD770 (.align 3 in asm vs .align 4)
#ifdef NON_MATCHING
struct SndSub0C2C {
    char pad00[0x20];
    unsigned int m_flags;   // +0x20 (elem +0x28, node +0x30)
    void orFlags(unsigned int f) { m_flags |= f; }
    void andNotFlags(unsigned int f) { m_flags &= ~f; }
};
struct SndElem0C2C {
    char m_pad00[0x08];
    SndSub0C2C m_sub;       // +0x08 (node +0x10)
    char m_pad2C[0x34 - 0x2C];
    int m_unk34;            // +0x34 (node +0x3C)
    char m_pad38[0x20];
};
struct SndNode0C2C {
    SndNode0C2C *m_prev;
    SndNode0C2C *m_next;
    SndElem0C2C m_elem;
};
class SndIt0C2C {
public:
    SndNode0C2C *m_node;
    SndIt0C2C() : m_node(0) {}
    SndIt0C2C(SndNode0C2C *theNode) : m_node(theNode) {}
    SndIt0C2C(const SndIt0C2C &theIt) : m_node(theIt.m_node) {}
    SndElem0C2C &operator*() const { return m_node->m_elem; }
    SndIt0C2C &operator++()
    {
        m_node = m_node->m_next;
        return *this;
    }
};
struct SndChain0C2C {
    SndNode0C2C m_head;
    int m_num;
    SndIt0C2C begin() { return SndIt0C2C(m_head.m_next); }
    SndIt0C2C end() { return SndIt0C2C(&m_head); }
};
extern "C" void X_0C2C_func_001C6A40(char *, int) asm("func_001C6A40");

extern "C" int func_001E0C2C(char *arg0, int arg1, int arg2, unsigned int arg3)
{
    char *base = arg0 + 0xC1C0;
    int count = *(int *)(base + 0x190);
    if (count == 0)
        return 0;
    SndIt0C2C it;
    SndIt0C2C last;
    it = SndIt0C2C(*(SndNode0C2C **)(base + 0xD4));
    last = ((SndChain0C2C *)(base + 0xD0))->end();
    do {
        if ((*it).m_unk34 == arg2 || arg2 == 0) {
            switch (arg1) {
            case 1:
                (*it).m_sub.m_flags = arg3;
                break;
            case 2:
                (*it).m_sub.orFlags(arg3);
                break;
            case 3:
                (*it).m_sub.andNotFlags(arg3);
                break;
            case 4:
                return ((*it).m_sub.m_flags & arg3) != 0;
            case 5:
                if ((*it).m_sub.m_flags & 0x20000000) {
                    X_0C2C_func_001C6A40(D_007812C0, 0x8000);
                    (*it).m_sub.andNotFlags(0x20000000);
                    return 1;
                }
                return 0;
            }
            if (arg2 != 0)
                return 1;
        }
        ++it;
    } while (--count != 0);
    return arg2 == 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E0C2C);
#endif

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
        return X_237___builtin_delete(arg0);
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

// NON_MATCHING: 14/101 differ, 14 edits
#ifdef NON_MATCHING
struct Ent15A0_1620 {
    int unk00_1620;
    int unk04_1620;
    int unk08_1620;
    int unk0C_1620;
    int unk10_1620;
    int unk14_1620;
    int unk18_1620;
    int unk1C_1620;
    int unk20_1620;
}; // 1620
struct Ent1654_1620 {
    int unk00_1620;
    int unk04_1620;
    int unk08_1620;
}; // 1620
struct Obj1620 {
    char pad0000_1620[0x15A0];
    Ent15A0_1620 arr15A0_1620[5];
    Ent1654_1620 arr1654_1620[3];
    char pad1678_1620[0xC];
    int unk1684_1620;
}; // 1620
extern "C" void func_001E1620(Obj1620 *arg0, int arg1, int arg2, int arg3) {
    if (arg0->unk1684_1620 < 0) {
        return;
    }
    arg0->unk1684_1620 = 0;

    if (arg1 != 1) {
        int *p = &arg0->arr15A0_1620[0].unk0C_1620;
        if (arg3 != -1) {
            if (arg3 != *p) {
                goto after_if1;
            }
            *p = -1;
        } else {
            *p = arg3;
        }
        arg0->arr15A0_1620[arg0->unk1684_1620].unk10_1620 = 0;
        arg0->arr15A0_1620[arg0->unk1684_1620].unk14_1620 = 0;
    }
after_if1:

    if (arg1 != 2) {
        if (arg2 != 0) {
            if (arg2 == arg0->arr15A0_1620[arg0->unk1684_1620].unk00_1620) {
                arg0->arr15A0_1620[arg0->unk1684_1620].unk00_1620 = 0;
                arg0->arr15A0_1620[arg0->unk1684_1620].unk04_1620 = 0;
                arg0->arr15A0_1620[arg0->unk1684_1620].unk08_1620 = 0;
            }
            if (arg2 == arg0->arr1654_1620[arg0->unk1684_1620].unk00_1620) {
                arg0->arr1654_1620[arg0->unk1684_1620].unk00_1620 = 0;
                goto clear_1658;
            }
        } else {
            arg0->arr15A0_1620[arg0->unk1684_1620].unk00_1620 = 0;
            arg0->arr15A0_1620[arg0->unk1684_1620].unk04_1620 = 0;
            arg0->arr15A0_1620[arg0->unk1684_1620].unk08_1620 = 0;
            arg0->arr1654_1620[arg0->unk1684_1620].unk00_1620 = 0;
        clear_1658:
            arg0->arr1654_1620[arg0->unk1684_1620].unk04_1620 = 0;
            arg0->arr1654_1620[arg0->unk1684_1620].unk08_1620 = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1620);
#endif

extern "C" void func_001E17B4(Obj17B4 *arg0, int arg1)
{
    SndMsg17B4 msg;

    X_17B4_func_001E111C(arg0, 0);
    int val = arg0->arr15A0[arg0->arr1680[0].unk04].unk0C;
    if (val != -1 && arg1 != 1) {
        msg.unk14 = 0x1E;
        msg.unk04 = 0;
        msg.unk08 = 0;
        X_17B4_func_001E5660(arg0, val, 0x1B, &msg);
    }
    if (arg1 != 2) {
        int val2 = arg0->arr15A0[arg0->arr1680[0].unk04].unk00;
        if (val2 != 0) {
            msg.unk14 = 0x1E;
            msg.unk04 = 0;
            msg.unk08 = 0;
            X_17B4_func_001E5E58(arg0, val2, 0x13, &msg);
        }
        int val3 = arg0->arr1654[arg0->arr1680[0].unk04].unk00;
        if (val3 != 0) {
            msg.unk14 = 0x1E;
            msg.unk04 = 0;
            msg.unk08 = 0;
            X_17B4_func_001E5E58(arg0, val3, 0x14, &msg);
        }
    }
    for (int i = 0; i < arg0->unk1708; i++) {
        msg.unk14 = 0x1E;
        msg.unk04 = 0;
        msg.unk08 = 0;
        X_17B4_func_001E5E58(arg0, arg0->arr1680[i].unk08, 0x15, &msg);
    }
    X_17B4_func_001E4120(arg0);
    arg0->unk1870 |= 1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1920);

// NON_MATCHING: 37/118 differ (size 0x1D8, game 0x1D4), 27 edits
#ifdef NON_MATCHING
struct SndNode1FA4 { // 1FA4
    SndNode1FA4 *m_prev; // 1FA4
    SndNode1FA4 *m_next; // 1FA4
    char m_data[0x58]; // 1FA4
}; // SndNode1FA4
struct SndChain1FA4 { // 1FA4
    SndNode1FA4 m_head; // 1FA4
    int m_num; // 1FA4
    void splice(SndChain1FA4 &theOther) { // 1FA4
        if (theOther.m_num != 0) { // 1FA4
            m_head.m_prev->m_next = theOther.m_head.m_next; // 1FA4
            SndNode1FA4 *last = m_head.m_prev; // 1FA4
            last->m_next->m_prev = last; // 1FA4
            SndNode1FA4 *tail = theOther.m_head.m_prev; // 1FA4
            m_head.m_prev = tail; // 1FA4
            tail->m_next = &m_head; // 1FA4
            m_num += theOther.m_num; // 1FA4
            theOther.m_num = 0; // 1FA4
            theOther.m_head.m_prev = &theOther.m_head; // 1FA4
            theOther.m_head.m_next = &theOther.m_head; // 1FA4
        } // 1FA4 splice if
    } // 1FA4 splice
}; // SndChain1FA4
struct SndQue1FA4 { // 1FA4
    SndChain1FA4 m_free; // 1FA4
    char m_pad64[0x0C]; // 1FA4
    SndChain1FA4 m_used; // 1FA4
    char m_padD4[0x0C]; // 1FA4
    int m_max; // 1FA4
    void clear() { // 1FA4
        if (m_used.m_num != 0) { // 1FA4
            m_free.splice(m_used); // 1FA4
        } // 1FA4 clear if
    } // 1FA4 clear
}; // SndQue1FA4
struct Elem1FA4 { // 1FA4
    int unk00; // 1FA4
    int unk04; // 1FA4
    int unk08; // 1FA4
    int unk0C; // 1FA4
    char pad10[0x08]; // 1FA4
    int unk18; // 1FA4
    char pad1C[0x28 - 0x1C]; // 1FA4
}; // Elem1FA4
struct Range1FA4 { // 1FA4
    Elem1FA4 *m_begin; // 1FA4
    Elem1FA4 *m_end; // 1FA4
    int m_max; // 1FA4
    char pad0C[0x34]; // 1FA4
    Elem1FA4 m_buf[0x30]; // 1FA4
    void clear() { // 1FA4
        for (Elem1FA4 *p = m_begin; p != m_end; p++) { // 1FA4
            p->~Elem1FA4(); // 1FA4
        } // 1FA4 loop
        m_end = m_buf; // 1FA4
        m_max = 0x30; // 1FA4
        m_begin = m_buf; // 1FA4
    } // 1FA4 clear
}; // Range1FA4
struct Item1FA4 { // 1FA4
    int unk00; // 1FA4
    char pad04[0x08]; // 1FA4
    int unk0C; // 1FA4
    char pad10[0x14]; // 1FA4
}; // Item1FA4
struct Sub1580_1FA4 { // 1FA4
    char pad00[0x20]; // 1FA4
    Item1FA4 arr[4]; // 1FA4
}; // Sub1580_1FA4
struct Obj1FA4 { // 1FA4
    char pad00[0x40]; // 1FA4
    SndQue1FA4 m_que; // 1FA4
    char pad124[0xD40 - 0x124]; // 1FA4
    Range1FA4 m_range; // 1FA4
    char pad1500[0x1580 - 0x1500]; // 1FA4
    Sub1580_1FA4 m_sub; // 1FA4
    char pad1630[0x1684 - 0x1630]; // 1FA4
    int unk1684; // 1FA4
    char pad1688[0x1708 - 0x1688]; // 1FA4
    int unk1708; // 1FA4
    int unk170C; // 1FA4
    int unk1710; // 1FA4
    int unk1714; // 1FA4
    int unk1718; // 1FA4
}; // Obj1FA4
extern int X_1FA4_D_007A3D80 asm("D_007A3D80");
extern "C" int X_1FA4_func_001E7D7C(void *, int) asm("func_001E7D7C");
extern "C" void X_1FA4_func_001E7724(void *, int) asm("func_001E7724");
extern "C" void X_def_func_001E1FA4(Obj1FA4 *arg0) asm("func_001E1FA4"); // 1FA4
extern "C" void X_def_func_001E1FA4(Obj1FA4 *arg0)
{
    Range1FA4 *r;
    int i;

    arg0->unk1684 = -1;
    arg0->unk1708 = 0;
    for (i = 0; i < 4; i++) {
        arg0->m_sub.arr[i].unk0C = -1;
        arg0->m_sub.arr[i].unk00 = 0;
    }
    r = &arg0->m_range;
    for (i = 0; i < 0x30; i++) {
        (r->m_begin + i)->unk00 = 0;
        (r->m_begin + i)->unk0C = 0;
        (r->m_begin + i)->unk18 = -1;
        (r->m_begin + i)->unk04 = 0;
        (r->m_begin + i)->unk08 = 0;
    }
    if (X_1FA4_func_001E7D7C(&X_1FA4_D_007A3D80, arg0->unk170C) != 0) {
        X_1FA4_func_001E7724(&X_1FA4_D_007A3D80, arg0->unk170C);
    }
    if (X_1FA4_func_001E7D7C(&X_1FA4_D_007A3D80, arg0->unk1710) != 0) {
        X_1FA4_func_001E7724(&X_1FA4_D_007A3D80, arg0->unk1710);
    }
    if (X_1FA4_func_001E7D7C(&X_1FA4_D_007A3D80, arg0->unk1718) != 0) {
        X_1FA4_func_001E7724(&X_1FA4_D_007A3D80, arg0->unk1718);
    }
    arg0->unk1718 = -1;
    arg0->unk170C = -1;
    arg0->unk1710 = -1;
    r->clear();
    arg0->m_que.clear();
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1FA4);
#endif

// NON_MATCHING: 74/110 differ, 1 reloc differs (size 0x1B8, game 0x1D8), 49 edits
#ifdef NON_MATCHING
struct ALIGNED(16) Ent2178 { // 2178
    char pad00[0x20]; // 2178
    int unk20; // 2178
    int unk24; // 2178
    unsigned int flags; // 2178
    char pad2C[0x24]; // 2178
}; // Ent2178
template <class T> class GamList2178 {
public: // GamList2178
    struct Node { // GamList2178
        Node *m_prev; // 2178
        Node *m_next; // 2178
        T m_data; // 2178
    }; // Node 2178
    struct Chain { // GamList2178
        Node m_head; // 2178
        int m_num; // 2178
        void push_back(Node *theNode) { // 2178
            if (m_num == 0) { // 2178
                m_head.m_next = theNode; // 2178
                theNode->m_prev = &m_head; // 2178
            } else { // 2178
                m_head.m_prev->m_next = theNode; // 2178
                theNode->m_prev = m_head.m_prev; // 2178
            } // push_back 2178
            theNode->m_next = &m_head; // 2178
            m_head.m_prev = theNode; // 2178
            ++m_num; // 2178
        } // push_back end 2178
        void unlink(Node *theNode) { // 2178
            Node *head = &m_head; // 2178
            if (theNode == head->m_next) { // 2178
                Node *next = theNode->m_next; // 2178
                head->m_next = next; // 2178
                next->m_prev = head; // 2178
            } else { // unlink 2178
                Node *p = theNode->m_prev; // 2178
                if (theNode == head->m_prev) { // 2178
                    head->m_prev = p; // 2178
                    p->m_next = head; // 2178
                } else { // unlink mid 2178
                    p->m_next = theNode->m_next; // 2178
                    Node *prev = theNode->m_prev; // 2178
                    p = theNode->m_next; // 2178
                    p->m_prev = prev; // 2178
                } // unlink mid end 2178
            } // unlink else end 2178
            --m_num; // 2178
        } // unlink end 2178
    }; // Chain 2178
    class iterator { // GamList2178
    public: // GamList2178 iterator
        Node *m_node; // 2178
        iterator() : m_node(0) {} // 2178
        iterator(Node *theNode) : m_node(theNode) {} // 2178
        iterator(const iterator &theOther) : m_node(theOther.m_node) {} // 2178
        T &operator*() { return m_node->m_data; } // 2178
        bool operator!=(const iterator &theOther) const { return m_node != theOther.m_node; } // 2178
        iterator &operator++() { m_node = m_node->m_next; return *this; } // 2178
    }; // iterator 2178
    Chain m_free; // 2178
    Chain m_used; // 2178
    int m_max; // 2178
    iterator begin() { return iterator(m_used.m_head.m_next); } // 2178
    iterator end() { return iterator(&m_used.m_head); } // 2178
    iterator erase(iterator thePos) { // 2178
        iterator next = thePos; // 2178
        ++next; // 2178
        Node *n = thePos.m_node; // 2178
        m_used.unlink(n); // 2178
        m_free.push_back(n); // 2178
        return next; // 2178
    } // erase 2178
}; // GamList2178
template <class T, int N> class GamPool2178 : public GamList2178<T> {
public: // GamPool2178
    typename GamList2178<T>::Node m_nodes[N]; // 2178
}; // GamPool2178
struct Obj2178 { // 2178
    char pad00[0x40]; // 2178
    GamPool2178<Ent2178, 6> m_que; // 2178
}; // Obj2178
extern "C" int X_2178_func_001E5660(Obj2178 *, int, int, int) asm("func_001E5660");
extern "C" void X_2178_func_001E649C(Obj2178 *, unsigned int, int) asm("func_001E649C");
extern "C" void func_001E2178(Obj2178 *arg0)
{
    GamList2178<Ent2178>::iterator it;
    GamList2178<Ent2178>::iterator last;
    it = arg0->m_que.begin();
    last = arg0->m_que.end();
    while (it != last) {
        if ((*it).flags & 2) {
            if ((*it).flags & 1) {
                X_2178_func_001E5660(arg0, (*it).unk20, 1, 0);
            }
            it = arg0->m_que.erase(it);
        } else if ((*it).flags & 4) {
            X_2178_func_001E649C(arg0, (*it).unk20, (*it).unk24);
            (*it).unk24 = -1;
            it = arg0->m_que.erase(it);
        } else {
            ++it;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2178);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2350);

// NON_MATCHING: 90/217 differ (size 0x364, game 0x368), 32 edits
#ifdef NON_MATCHING
struct Vec239C { float m_x,m_y,m_z; }; // vec239C
extern "C" float sqrtf(float); // decl239C
extern "C" int scene239C(void *) asm("func_001C6C28"); // decl239C
extern "C" void *find239C(void *, int) asm("func_0017EA44"); // decl239C
extern "C" int lookup239C(void *, unsigned int, void **, unsigned int) asm("func_001E4908"); // decl239C
extern "C" int check239C(void *, unsigned int, int, void *) asm("func_001E5E58"); // decl239C
extern "C" int play239C(void *, unsigned int, int, Vec239C *, int) asm("func_001E4EBC"); // decl239C
extern char world239C[] asm("D_007812C0"); // decl239C
extern char bank239C[] asm("D_00298EE0"); // decl239C
struct ALIGNED(16) Item239C { // decl239C
    char unused[0x10];
    Vec239C position; // decl239C
    int pad1C; // decl239C // decl239C
    unsigned int id; // decl239C
    int handle; // decl239C
    unsigned int flags; // decl239C
    int zero; // decl239C
    int scene; // decl239C
    void *data; // decl239C
    float distance; // decl239C
    int a,b; // decl239C
    char tail[12]; // decl239C
}; // item239C // decl239C
struct Node239C { Node239C *prev,*next; Item239C data; }; // node239C // decl239C
class Iter239C { public: // decl239C
    Node239C *node; // decl239C
    Iter239C() : node(0) {} // decl239C
    Iter239C(Node239C *n) : node(n) {} // decl239C
    Iter239C(const Iter239C &n) : node(n.node) {} // decl239C
    Item239C &operator*() const { return node->data; } // decl239C
    Iter239C &operator++() { node = node->next; return *this; } // decl239C
    bool operator!=(const Iter239C &n) const { return node != n.node; } // decl239C
}; // iter239C // decl239C
struct Chain239C { // decl239C
    Node239C head; // decl239C
    int count; // decl239C
    void push(Node239C *n) { // decl239C
        if (count == 0) { head.next = n; n->prev = &head; } // decl239C
        else { head.prev->next = n; n->prev = head.prev; } // decl239C
        n->next = &head; // decl239C
        head.prev = n; // decl239C
        ++count; // decl239C
    } // decl239C
}; // chain239C // decl239C
struct Que239C { // decl239C
    Chain239C free, used; // decl239C
    Iter239C begin() { return Iter239C(used.head.next); } // decl239C
    Iter239C end() { return Iter239C(&used.head); } // decl239C
    Iter239C insert(Iter239C where, const Item239C &item) { // decl239C
        Node239C *n = free.head.prev; // decl239C
        Node239C *previous = n->prev; // decl239C
        free.head.prev = previous; // decl239C
        previous->next = &free.head; // decl239C
        --free.count; // decl239C
        n->data = item; // decl239C
        Node239C *target = where.node; // decl239C
        Node239C *p = target->prev; // decl239C
        n->prev = p; // decl239C
        p->next = n; // decl239C
        n->next = target; // decl239C
        target->prev = n; // decl239C
        ++used.count; // decl239C
        return where; // decl239C
    } // decl239C
    void push(const Item239C &item) { // decl239C
        Node239C *n = free.head.prev; // decl239C
        Node239C *previous = n->prev; // decl239C
        free.head.prev = previous; // decl239C
        previous->next = &free.head; // decl239C
        --free.count; // decl239C
        n->data = item; // decl239C
        used.push(n); // decl239C
    } // decl239C
}; // que239C // decl239C
struct Obj239C { char pad[0x40]; Que239C queue; }; // obj239C // decl239C
extern "C" void func_001E239C(Obj239C *self, unsigned int id, Vec239C *position, int scene, int flags)
{
    if (scene == -1) scene = scene239C(world239C);
    float *entry = (float *)find239C(bank239C, scene);
    if (entry) {
        Item239C item;
        item.scene = scene;
        item.distance = 3000.0f;
        item.handle = -1;
        item.flags = flags;
        item.id = id;
        item.zero = 0;
        item.a = 0;
        item.b = 0;
        item.position.m_x = position->m_x + entry[8];
        item.position.m_y = position->m_y + entry[9];
        item.position.m_z = position->m_z + entry[10];
        float horizontal = sqrtf(item.position.m_x * item.position.m_x + item.position.m_z * item.position.m_z);
        float distance = sqrtf(item.position.m_y * item.position.m_y + horizontal * horizontal);
        lookup239C(self, id, &item.data, 1);
        if (item.data) {
            if (flags & 0x20) {
                if (check239C(self, item.id, 0x16, 0) != 0) return;
                item.flags |= 0x200;
                item.handle = play239C(self, item.id, 0, position, 0x80);
            }
            register Que239C *queue PS2_REG("$4") = &self->queue;
            Iter239C it;
            Iter239C last;
            it = queue->begin();
            last = queue->end();
            while (it != last) {
                if (distance <= (*it).distance) {
                    queue->insert(it, item);
                    return;
                }
                ++it;
            }
            queue->push(item);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E239C);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2704);

// NON_MATCHING: 22/104 differ, 25 edits
#ifdef NON_MATCHING
struct ALIGNED(16) Ent2AA0 { // 2AA0
    char pad00[0x20]; // 2AA0
    unsigned int unk20; // 2AA0
    int unk24; // 2AA0
    char pad28[0x08]; // 2AA0
    int unk30; // 2AA0
    char pad34[0x1C]; // 2AA0
}; // Ent2AA0
struct SndNode2AA0 {
    SndNode2AA0 *m_prev; // 2AA0
    SndNode2AA0 *m_next; // 2AA0
    Ent2AA0 m_data; // 2AA0
}; // SndNode2AA0
struct SndChain2AA0 {
    SndNode2AA0 m_head; // 2AA0
    int m_num; // 2AA0
    void push_back(SndNode2AA0 *theNode) {
        if (m_num == 0) { // 2AA0
            m_head.m_next = theNode; // 2AA0
            theNode->m_prev = &m_head; // 2AA0
        } else { // 2AA0
            m_head.m_prev->m_next = theNode; // 2AA0
            theNode->m_prev = m_head.m_prev; // 2AA0
        } // push_back 2AA0
        theNode->m_next = &m_head; // 2AA0
        m_head.m_prev = theNode; // 2AA0
        ++m_num; // 2AA0
    } // push_back end 2AA0
    void unlink(SndNode2AA0 *theNode) {
        if (theNode == m_head.m_next) { // 2AA0
            SndNode2AA0 *next = theNode->m_next; // 2AA0
            m_head.m_next = next; // 2AA0
            next->m_prev = &m_head; // 2AA0
        } else { // unlink 2AA0
            SndNode2AA0 *p = theNode->m_prev; // 2AA0
            if (theNode == m_head.m_prev) { // 2AA0
                m_head.m_prev = p; // 2AA0
                p->m_next = &m_head; // 2AA0
            } else { // unlink mid 2AA0
                p->m_next = theNode->m_next; // 2AA0
                SndNode2AA0 *prev = theNode->m_prev; // 2AA0
                p = theNode->m_next; // 2AA0
                p->m_prev = prev; // 2AA0
            } // unlink mid end 2AA0
        } // unlink else end 2AA0
        --m_num; // 2AA0
    } // unlink end 2AA0
}; // SndChain2AA0
class SndIt2AA0 {
public: // SndIt2AA0
    SndNode2AA0 *m_node; // 2AA0
    SndIt2AA0() : m_node(0) {}
    SndIt2AA0(SndNode2AA0 *theNode) : m_node(theNode) {}
    SndIt2AA0(const SndIt2AA0 &theIt) : m_node(theIt.m_node) {}
    Ent2AA0 &operator*() const { return m_node->m_data; }
    SndIt2AA0 &operator++() { // 2AA0
        m_node = m_node->m_next; // 2AA0
        return *this; // 2AA0
    } // op++ 2AA0
    bool operator!=(const SndIt2AA0 &theIt) const { return m_node != theIt.m_node; }
}; // SndIt2AA0
class SndQue2AA0 {
public: // SndQue2AA0
    SndChain2AA0 m_free; // 2AA0
    SndChain2AA0 m_used; // 2AA0
    int m_max; // 2AA0
    SndIt2AA0 begin() { return SndIt2AA0(m_used.m_head.m_next); }
    SndIt2AA0 end() { return SndIt2AA0(&m_used.m_head); }
    SndIt2AA0 erase(SndIt2AA0 thePos) {
        SndIt2AA0 next = thePos; // 2AA0
        ++next; // 2AA0
        SndNode2AA0 *n = thePos.m_node; // 2AA0
        m_used.unlink(n); // 2AA0
        m_free.push_back(n); // 2AA0
        return next; // 2AA0
    } // erase 2AA0
}; // SndQue2AA0
struct Obj2AA0 {
    char pad00[0x40]; // 2AA0
    SndQue2AA0 m_que; // 2AA0
}; // Obj2AA0
extern "C" void X_2AA0_func_001E649C(Obj2AA0 *, unsigned int, int) asm("func_001E649C");
extern "C" void func_001E2AA0(Obj2AA0 *arg0, unsigned int arg1, int arg2) {
    SndIt2AA0 it;
    SndIt2AA0 last;
    it = arg0->m_que.begin();
    last = arg0->m_que.end();
    while (it != last) {
        if ((*it).unk20 == arg1 && (arg2 == -1 || (*it).unk30 == arg2)) {
            X_2AA0_func_001E649C(arg0, (*it).unk20, (*it).unk24);
            (*it).unk24 = -1;
            it = arg0->m_que.erase(it);
        } else {
            ++it;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2AA0);
#endif

// NON_MATCHING: 22/93 differ, 25 edits
#ifdef NON_MATCHING
struct ALIGNED(16) Ent2C40 {
    char pad00_2C40[0x20];
    unsigned int unk20;
    int unk24;
    char pad28_2C40[0x04];
    int unk2C;
    char pad30_2C40[0x20];
}; // Ent2C40
struct SndNode2C40 {
    SndNode2C40 *m_prev2C40;
    SndNode2C40 *m_next2C40;
    Ent2C40 m_data2C40;
}; // SndNode2C40
struct SndChain2C40 {
    SndNode2C40 m_head2C40;
    int m_num2C40;
    void push_back(SndNode2C40 *theNode) {
        if (m_num2C40 == 0) {
            m_head2C40.m_next2C40 = theNode;
            theNode->m_prev2C40 = &m_head2C40;
        } else { // 2C40
            m_head2C40.m_prev2C40->m_next2C40 = theNode;
            theNode->m_prev2C40 = m_head2C40.m_prev2C40;
        } // push_back else 2C40
        theNode->m_next2C40 = &m_head2C40;
        m_head2C40.m_prev2C40 = theNode;
        ++m_num2C40;
    } // push_back 2C40
    void unlink(SndNode2C40 *theNode) {
        if (theNode == m_head2C40.m_next2C40) {
            SndNode2C40 *next = theNode->m_next2C40;
            m_head2C40.m_next2C40 = next;
            next->m_prev2C40 = &m_head2C40;
        } else { // unlink not front 2C40
            SndNode2C40 *prev = theNode->m_prev2C40;
            if (theNode == m_head2C40.m_prev2C40) {
                m_head2C40.m_prev2C40 = prev;
                prev->m_next2C40 = &m_head2C40;
            } else { // unlink mid 2C40
                prev->m_next2C40 = theNode->m_next2C40;
                SndNode2C40 *prev2 = theNode->m_prev2C40;
                prev = theNode->m_next2C40;
                prev->m_prev2C40 = prev2;
            } // unlink mid end 2C40
        } // unlink else end 2C40
        --m_num2C40;
    } // unlink 2C40
}; // SndChain2C40
class SndIt2C40 {
public: // SndIt2C40
    SndNode2C40 *m_node2C40;
    SndIt2C40() : m_node2C40(0) {}
    SndIt2C40(SndNode2C40 *node) : m_node2C40(node) {}
    SndIt2C40(const SndIt2C40 &rhs) : m_node2C40(rhs.m_node2C40) {}
    Ent2C40 &operator*() { return m_node2C40->m_data2C40; }
    SndIt2C40 &operator++() { m_node2C40 = m_node2C40->m_next2C40; return *this; }
    bool operator!=(const SndIt2C40 &rhs) const { return m_node2C40 != rhs.m_node2C40; }
}; // SndIt2C40
class SndQue2C40 {
public: // SndQue2C40
    SndChain2C40 m_free2C40;
    SndChain2C40 m_used2C40;
    SndIt2C40 begin() { return SndIt2C40(m_used2C40.m_head2C40.m_next2C40); }
    SndIt2C40 end() { return SndIt2C40(&m_used2C40.m_head2C40); }
    SndIt2C40 erase(SndIt2C40 thePos) {
        SndIt2C40 next = thePos; // 2C40
        ++next; // 2C40
        SndNode2C40 *n = thePos.m_node2C40;
        m_used2C40.unlink(n);
        m_free2C40.push_back(n);
        return next; // 2C40
    } // erase 2C40
}; // SndQue2C40
struct Obj2C40 {
    char pad00_2C40[0x40];
    SndQue2C40 m_que2C40;
}; // Obj2C40
extern "C" int X_2C40_func_001E649C(Obj2C40 *, unsigned int, int) asm("func_001E649C");
extern "C" void func_001E2C40(Obj2C40 *arg0, int arg1) {
    SndChain2C40 *used = &arg0->m_que2C40.m_used2C40;
    SndIt2C40 it;
    SndIt2C40 last;
    it = arg0->m_que2C40.begin();
    last = SndIt2C40(&used->m_head2C40);
    while (it != last) {
        if ((*it).unk2C == arg1) {
            X_2C40_func_001E649C(arg0, (*it).unk20, (*it).unk24);
            (*it).unk24 = -1;
            it = arg0->m_que2C40.erase(it);
        } else {
            ++it;
        }
    }
}

// ---- end
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2C40);
#endif

extern "C" void func_001E2DB4(Obj2DB4 *self, unsigned int id, Vec2DB4 *position, int scene, int flags)
{
    if (scene == -1) scene = scene2DB4(world2DB4);
    float *entry = (float *)find2DB4(bank2DB4, scene);
    if (entry) {
        Item2DB4 item;
        item.flags = flags | 1;
        item.distance = 3000.0f;
        item.scene = scene;
        item.handle = -1;
        item.id = id;
        item.zero = 0;
        item.position.m_x = position->m_x + entry[8];
        item.position.m_y = position->m_y + entry[9];
        item.position.m_z = position->m_z + entry[10];
        void *data;
        if (lookup2DB4(self, id, &data)) item.data = data;
        else item.data = 0;
        float horizontal = sqrtf(item.position.m_x * item.position.m_x + item.position.m_z * item.position.m_z);
        float distance = sqrtf(item.position.m_y * item.position.m_y + horizontal * horizontal);
        Que2DB4 *queue = &self->queue;
        Iter2DB4 it;
        Iter2DB4 last;
        it = queue->begin();
        last = queue->end();
        if (flags & 0x20) {
            if (check2DB4(self, item.id, 0x16, 0) != 0) return;
            item.flags |= 0x200;
            item.handle = play2DB4(self, item.id, 1, position, 0, 0x80);
        }
            while (it != last) {
                if (distance <= (*it).distance) {
                    queue->insert(it, item);
                    return;
                }
                ++it;
            }
            queue->push(item);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3138);

// NON_MATCHING: 22/107 differ, 25 edits
#ifdef NON_MATCHING
struct ALIGNED(16) Ent34EC { // 34EC
    char pad00[0x20]; // 34EC
    int unk20; // 34EC
    char pad24[0x0C]; // 34EC
    int unk30; // 34EC
    char pad34[0x1C]; // 34EC
}; // Ent34EC
template <class T> class GamList34EC {
public: // GamList34EC
    struct Node { // GamList34EC
        Node *m_prev; // 34EC
        Node *m_next; // 34EC
        T m_data; // 34EC
    }; // Node 34EC
    struct Chain { // GamList34EC
        Node m_head; // 34EC
        int m_num; // 34EC
        void push_back(Node *theNode) { // 34EC
            if (m_num == 0) { // 34EC
                m_head.m_next = theNode; // 34EC
                theNode->m_prev = &m_head; // 34EC
            } else { // 34EC
                m_head.m_prev->m_next = theNode; // 34EC
                theNode->m_prev = m_head.m_prev; // 34EC
            } // push_back 34EC
            theNode->m_next = &m_head; // 34EC
            m_head.m_prev = theNode; // 34EC
            ++m_num; // 34EC
        } // push_back end 34EC
        void unlink(Node *theNode) { // 34EC
            Node *head = &m_head; // 34EC
            if (theNode == head->m_next) { // 34EC
                Node *next = theNode->m_next; // 34EC
                head->m_next = next; // 34EC
                next->m_prev = head; // 34EC
            } else { // unlink 34EC
                Node *p = theNode->m_prev; // 34EC
                if (theNode == head->m_prev) { // 34EC
                    head->m_prev = p; // 34EC
                    p->m_next = head; // 34EC
                } else { // unlink mid 34EC
                    p->m_next = theNode->m_next; // 34EC
                    Node *prev = theNode->m_prev; // 34EC
                    p = theNode->m_next; // 34EC
                    p->m_prev = prev; // 34EC
                } // unlink mid end 34EC
            } // unlink else end 34EC
            --m_num; // 34EC
        } // unlink end 34EC
    }; // Chain 34EC
    class iterator { // GamList34EC
    public: // iterator 34EC
        Node *m_node; // 34EC
        iterator() : m_node(0) {} // 34EC
        iterator(Node *theNode) : m_node(theNode) {} // 34EC
        iterator(const iterator &theIt) : m_node(theIt.m_node) {} // 34EC
        T &operator*() const { return m_node->m_data; } // 34EC
        iterator &operator++() { // 34EC
            m_node = m_node->m_next; // 34EC
            return *this; // 34EC
        } // op++ 34EC
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; } // 34EC
    }; // iterator 34EC
    Chain m_free; // 34EC
    Chain m_used; // 34EC
    int m_max; // 34EC
    iterator begin() { return iterator(m_used.m_head.m_next); } // 34EC
    iterator end() { return iterator(&m_used.m_head); } // 34EC
    iterator erase(iterator thePos) { // 34EC
        iterator next = thePos; // 34EC
        ++next; // 34EC
        Node *n = thePos.m_node; // 34EC
        m_used.unlink(n); // 34EC
        m_free.push_back(n); // 34EC
        return next; // 34EC
    } // erase 34EC
}; // GamList34EC
template <class T, int N> class GamPool34EC : public GamList34EC<T> { // 34EC
public: // GamPool34EC
    typename GamList34EC<T>::Node m_nodes[N] ALIGNED(64); // 34EC
}; // GamPool34EC
struct Obj34EC { // 34EC
    char pad00[0x40]; // 34EC
    GamPool34EC<Ent34EC, 6> m_que; // 34EC
}; // Obj34EC
extern "C" int X_34EC_func_001E5660(Obj34EC *, int, int, int) asm("func_001E5660");
extern "C" int X_34EC_func_001E4CBC(Obj34EC *, int) asm("func_001E4CBC");
extern "C" void func_001E34EC(Obj34EC *arg0, int arg1, int arg2) {
    GamList34EC<Ent34EC>::iterator it;
    GamList34EC<Ent34EC>::iterator last;
    it = arg0->m_que.begin();
    last = arg0->m_que.end();
    while (it != last) {
        if ((*it).unk20 == arg1 && (arg2 == -1 || (*it).unk30 == arg2)) {
            X_34EC_func_001E5660(arg0, arg1, 1, 0);
            it = arg0->m_que.erase(it);
            X_34EC_func_001E4CBC(arg0, arg1);
        } else {
            ++it;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E34EC);
#endif

// NON_MATCHING: 24/91 differ, 27 edits
#ifdef NON_MATCHING
struct ALIGNED(16) Ent3698 {
    char pad00_3698[0x20];
    int unk20; // 3698
    char pad24_3698[0x08];
    int unk2C; // 3698
    char pad30_3698[0x20];
}; // Ent3698
struct SndNode3698 {
    SndNode3698 *m_prev3698;
    SndNode3698 *m_next3698;
    Ent3698 m_data3698;
}; // SndNode3698
struct SndChain3698 {
    SndNode3698 m_head3698;
    int m_num3698;
    void push_back(SndNode3698 *theNode) {
        if (m_num3698 == 0) {
            m_head3698.m_next3698 = theNode;
            theNode->m_prev3698 = &m_head3698;
        } else { // 3698
            m_head3698.m_prev3698->m_next3698 = theNode;
            theNode->m_prev3698 = m_head3698.m_prev3698;
        } // push_back else 3698
        theNode->m_next3698 = &m_head3698;
        m_head3698.m_prev3698 = theNode;
        ++m_num3698;
    } // push_back 3698
    void unlink(SndNode3698 *theNode) {
        if (theNode == m_head3698.m_next3698) {
            SndNode3698 *next = theNode->m_next3698;
            m_head3698.m_next3698 = next;
            next->m_prev3698 = &m_head3698;
        } else { // unlink not front 3698
            SndNode3698 *prev = theNode->m_prev3698;
            if (theNode == m_head3698.m_prev3698) {
                m_head3698.m_prev3698 = prev;
                prev->m_next3698 = &m_head3698;
            } else { // unlink mid 3698
                prev->m_next3698 = theNode->m_next3698;
                theNode->m_next3698->m_prev3698 = theNode->m_prev3698;
            } // unlink mid end 3698
        } // unlink else end 3698
        --m_num3698;
    } // unlink 3698
}; // SndChain3698
class SndIt3698 {
public: // SndIt3698
    SndNode3698 *m_node3698;
    SndIt3698() : m_node3698(0) {}
    SndIt3698(SndNode3698 *node) : m_node3698(node) {}
    SndIt3698(const SndIt3698 &rhs) : m_node3698(rhs.m_node3698) {}
    Ent3698 &operator*() { return m_node3698->m_data3698; }
    SndIt3698 &operator++() { m_node3698 = m_node3698->m_next3698; return *this; }
    bool operator!=(const SndIt3698 &rhs) const { return m_node3698 != rhs.m_node3698; }
}; // SndIt3698
class SndQue3698 {
public: // SndQue3698
    SndChain3698 m_free3698;
    SndChain3698 m_used3698;
    SndIt3698 begin() { return SndIt3698(m_used3698.m_head3698.m_next3698); }
    SndIt3698 end() { return SndIt3698(&m_used3698.m_head3698); }
    SndIt3698 erase(SndIt3698 thePos) {
        SndIt3698 next = thePos; // 3698
        ++next; // 3698
        SndNode3698 *n = thePos.m_node3698;
        m_used3698.unlink(n);
        m_free3698.push_back(n);
        return next; // 3698
    } // erase 3698
}; // SndQue3698
struct Obj3698 {
    char pad00_3698[0x40];
    SndQue3698 m_que3698;
}; // Obj3698
extern "C" int X_3698_func_001E5660(Obj3698 *, int, int, int) asm("func_001E5660");
extern "C" void func_001E3698(Obj3698 *arg0, int arg1) {
    SndIt3698 it;
    SndIt3698 last;
    it = arg0->m_que3698.begin();
    last = arg0->m_que3698.end();
    while (it != last) {
        if ((*it).unk2C == arg1) {
            X_3698_func_001E5660(arg0, (*it).unk20, 1, 0);
            it = arg0->m_que3698.erase(it);
        } else {
            ++it;
        }
    }
}

// ---- end
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3698);
#endif

extern "C" void func_001E3804(char *arg0)
{
    ((SndQue *)(arg0 + 0x40))->clear();
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E386C);

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3C24);

// NON_MATCHING: 132/138 differ, 7 relocs differ (size 0x228, game 0x234), 54 edits
#ifdef NON_MATCHING
 // 4120decl
struct Iter4120 { // 4120decl
    int node; // 4120decl
    Iter4120() : node(0) {} // 4120decl
    Iter4120(int n) : node(n) {} // 4120decl
    Iter4120(const Iter4120 &i) : node(i.node) {} // 4120decl
    Iter4120 &operator++() { node = *(int *)(node+4); return *this; } // 4120decl
    bool operator!=(const Iter4120 &i) const { return node != i.node; } // 4120decl
}; // 4120decl
struct Sub4120 { int *arr; }; // 4120decl
extern "C" int X___builtin_new(...) asm("__builtin_new"); // 4120decl
extern "C" void X_func_001E5660(int, unsigned int, int, void *) asm("func_001E5660"); // 4120decl
extern "C" int X_func_001E5B60(...) asm("func_001E5B60"); // 4120decl
extern "C" int X_func_001E6368(...) asm("func_001E6368"); // 4120decl
extern "C" int X_func_001E71FC(...) asm("func_001E71FC"); // 4120decl
extern "C" int X_func_001F8FC0(...) asm("func_001F8FC0"); // 4120decl
extern int D_007A3D80; // 4120decl
extern "C" void func_001E4120(int arg0)
{
    Iter4120 it;
    Iter4120 last;
    struct { unsigned int sp30; int sp34; int sp38; int sp3C; char pad40[4]; int sp44; char pad48[8]; int sp50; int sp54; int sp58; char pad5C[20]; } stack;
    int temp_a4_2;
    int temp_a5;
    int temp_s0;
    unsigned int temp_a1;
    unsigned int temp_a1_2;
    int temp_v0_3;
    int temp_a4;
    int temp_v0;
    int temp_v0_2;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;

    it = Iter4120(M2C_FIELD(arg0, int *, 0xB4));
    last = Iter4120(arg0 + 0xB0);
    {
        while (it != last) {
            temp_v0_2 = it.node + 0x10;
            temp_a1 = M2C_FIELD(temp_v0_2, unsigned int *, 0x20);
            temp_s0 = M2C_FIELD(temp_v0_2, int *, 0x24);
            if (M2C_FIELD(temp_v0_2, int *, 0x28) & 1) {
                if (X_func_001E5B60(arg0, temp_a1, temp_s0) != 0) {
                    temp_a1_2 = M2C_FIELD(it.node, unsigned int *, 0x30);
                    temp_a5 = temp_s0 * 0x28;
                    stack.sp30 = temp_a1_2;
                    Sub4120 *sub = (Sub4120 *)(arg0 + 0xD40);
                    temp_a4 = (int)sub->arr + temp_a5;
                    stack.sp3C = M2C_FIELD(temp_a4, int *, 0x18);
                    stack.sp50 = M2C_FIELD(temp_a4, int *, 4);
                    stack.sp44 = 0x1E;
                    stack.sp54 = M2C_FIELD(temp_a4, int *, 8);
                    stack.sp34 = 0;
                    stack.sp38 = 0;
                    M2C_FIELD(((M2C_FIELD(arg0, int *, 0x1684) * 0x24) + arg0), unsigned int *, 0x15B8) = (unsigned int) M2C_FIELD(it.node, unsigned int *, 0x30);
                    M2C_FIELD(((M2C_FIELD(arg0, int *, 0x1684) * 0x24) + arg0), int *, 0x15BC) = (int) M2C_FIELD(((int)sub->arr + temp_a5), int *, 4);
                    temp_a4_2 = M2C_FIELD(arg0, int *, 0x1684);
                    M2C_FIELD(((temp_a4_2 * 0x24) + arg0), int *, 0x15C0) = (int) M2C_FIELD(((int)sub->arr + temp_a5), int *, 8);
                    X_func_001E5660(arg0, temp_a1_2, 0x15, &stack.sp30);
                }
            } else if (X_func_001E6368(arg0, temp_a1, temp_s0) != 0) {
                temp_v1_3 = M2C_FIELD(arg0, int *, 0xD40) + (temp_s0 * 0x28);
                stack.sp30 = M2C_FIELD(it.node, unsigned int *, 0x30);
                stack.sp3C = M2C_FIELD(temp_v1_3, int *, 0x18);
                stack.sp50 = M2C_FIELD(temp_v1_3, int *, 4);
                stack.sp44 = 0x3C;
                stack.sp54 = M2C_FIELD(temp_v1_3, int *, 8);
                stack.sp34 = 0;
                stack.sp38 = 0;
                stack.sp58 = 0;
                temp_v0_3 = X___builtin_new(0xC0);
                X_func_001F8FC0(temp_v0_3, 0, (int)&stack.sp30);
                X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0_3, 0, 0, 1);
            }
            ++it;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4120);
#endif

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

extern "C" void func_001E4540(int arg0, char *arg1, int arg2) {
    char path[0x40];
    int bank;
    int val;
    void *buf;
    char *name;

    X_4540_func_001E6734(arg0, 0x11, 0, 0, 0, -1);
    FileReader reader;
    buf = X_4540_alloc__BedMemory((int)&D_006E9800, 0x80040, &D_002FD770, 0x616, 0, 1);
    X_4540_func_001E43E0(arg0, arg1, &bank, &val);
    name = (char *)(arg0 + 0x182C);
    X_4540_strcpy(name, arg1);
    *(char *)(arg0 + 0x1830) = '.';
    *(char *)(arg0 + 0x1831) = 's';
    *(char *)(arg0 + 0x1832) = 'e';
    *(char *)(arg0 + 0x1833) = '\0';
    X_4540_snprintf(path, 0x40, "data/snd/xv/%s", name);
    FileReadReq req;
    req.m_unk08 = 1;
    req.m_name = path;
    req.m_unk14 = 0;
    req.m_offset = 0;
    req.m_buf = buf;
    req.m_size = 0x80000;
    req.m_unk20 = 1;
    reader.func_001BE524(&req, 0);
    X_4540_func_001E44B4(arg0, bank, val, buf, arg2);
    *(int *)(arg0 + bank * 4 + 0x1728) = val;
    X_4540_heapFree(buf);
}

// ---- end

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

extern "C" int func_001E4908(int arg0, int arg1, int *arg2, int arg3)
{
    Ent4908 *e = *(Ent4908 **)(arg0 + 0x1540);
    if (e == 0) {
        return 0;
    }
    int i = 1;
    if (e->unk1C != 0) {
        do {
            if (arg1 == e->unk1C) {
                *(Ent4908 **)arg2 = e;
                return 1;
            }
            e++;
            if (i++ >= 0x400) {
                break;
            }
        } while (e->unk1C != 0);
    }
    *(Ent4908 **)arg2 = 0;
    return 0;
}

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

// NON_MATCHING: 123/130 differ, 7 relocs differ (size 0x208, game 0x20C), 18 edits
#ifdef NON_MATCHING
struct Entry4E { int a,b,c,d,e,f,g,h,i,j; };
struct Sub4E { Entry4E *arr; };
struct Obj4E { int first; char pad[0xD3C]; Sub4E sub; };
extern int D_007A320C;
inline bool flag4E() { return (D_007A320C & 1) != 0; }
extern "C" int X_func_0017F8FC(...) asm("func_0017F8FC");
extern "C" void X_func_00180CE0(void *, int, int, int, float, int) asm("func_00180CE0");
extern "C" int X_func_001E4908(int, unsigned int, int *, unsigned int) asm("func_001E4908");
extern "C" void X_func_001E6E00(int, void *, int, int *, int *, float) asm("func_001E6E00");
extern int D_007A320C;
extern "C" int func_001E4EBC(int arg0, unsigned int arg1, int arg2, int arg3, int arg4)
{
    struct { int sp0; int sp4; int sp8; char padC[4]; Vec5250 vec; } stack;
    float temp_f0;
    int temp_a0;
    int var_s1;
    int var_v0;

    var_v0 = -1;
    if (!flag4E()) {
        if (X_func_001E4908(arg0, arg1, &stack.sp8, 1U) == 0) {
            return -1;
        }
        if (arg3 != 0) {
            stack.vec.x = ((Vec5250 *)arg3)->x;
            stack.vec.y = ((Vec5250 *)arg3)->y;
            stack.vec.z = ((Vec5250 *)arg3)->z;
            stack.vec.w = ((Vec5250 *)arg3)->w;
            X_func_001E6E00(M2C_FIELD(arg0, int *, 0), &stack.vec, stack.sp8, &stack.sp0, &stack.sp4, 100.0f);
            var_s1 = X_func_0017F8FC(&D_007B2580, arg1);
            X_func_00180CE0(&D_007B2580, var_s1, stack.sp0, stack.sp4, -1024.0f, 0);
        } else {
            var_s1 = X_func_0017F8FC(&D_007B2580, arg1);
            if (arg2 != 0) {
                temp_f0 = (float) M2C_FIELD(stack.sp8, unsigned short *, 0x28) * 0.00390625f;
                stack.sp0 = (int)((float) M2C_FIELD(stack.sp8, unsigned short *, 0x26) * temp_f0);
                stack.sp4 = (int)((float) M2C_FIELD(stack.sp8, unsigned short *, 0x26) * (1.0f - temp_f0));
            } else {
                stack.sp0 = 100;
                stack.sp4 = 100;
            }
            X_func_00180CE0(&D_007B2580, var_s1, stack.sp0, stack.sp4, -1024.0f, 0);
        }
        var_v0 = var_s1;
        temp_a0 = var_s1 * 0x28;
        Sub4E *sub = &((Obj4E *)arg0)->sub;
        *(int *)((int)sub->arr + temp_a0) = arg4;
        M2C_FIELD(((int)sub->arr + temp_a0), unsigned int *, 0xC) = arg1;
        M2C_FIELD(((int)sub->arr + temp_a0), int *, 0x18) = var_s1;
        M2C_FIELD(((int)sub->arr + temp_a0), int *, 4) = stack.sp0;
        M2C_FIELD(((int)sub->arr + temp_a0), int *, 8) = stack.sp4;
        
        return var_v0;
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E4EBC);
#endif

extern "C" int func_001E50C8(int arg0, int arg1, int arg2, int arg3, float fparg0, int arg4, int arg5, int arg6) {
    Msg50C8 msg;
    if (arg5 != 0) {
        msg.unk00 = arg1;
        msg.unk04 = arg2;
        msg.unk08 = arg3;
        msg.unk18 = fparg0;
        msg.unk10 = arg4;
        int prio = X_50C8_D_007A3D80.m_prio + arg5;
        void *node = X_50C8_builtin_new(0xC0);
        X_50C8_func_001F8FC0(node, 5, &msg);
        X_50C8_func_001E71FC(&X_50C8_D_007A3D80, 1, prio, 1, 0, node, 0, 0, 1);
        return -1;
    }
    if (X_50C8_D_007A320C.chkSysFlg(1)) {
        return -1;
    }
    int idx = X_50C8_func_0017F8FC(&X_50C8_D_007B2580, arg1);
    X_50C8_func_00180CE0(&X_50C8_D_007B2580, idx, arg2, arg3, fparg0, arg4);
    Range50C8 *r = (Range50C8 *)(arg0 + 0xD40);
    int off = idx * sizeof(Elem28_50C8);
    ((Elem28_50C8 *)(r->m_begin + off))->unk00 = arg6;
    ((Elem28_50C8 *)(r->m_begin + off))->unk0C = arg1;
    ((Elem28_50C8 *)(r->m_begin + off))->unk18 = idx;
    ((Elem28_50C8 *)(r->m_begin + off))->unk04 = arg2;
    ((Elem28_50C8 *)(r->m_begin + off))->unk08 = arg3;
    return idx;
}

// ---- end

extern "C" int func_001E5250(Obj5250 *arg0, int arg1, int arg2, Vec5250 *arg3, int arg4, int arg5) {
    char buf[0x40];
    int sp40;
    int sp44;
    void *sp48;
    int s1;

    X_5250_snprintf(buf, 0x40, "s%06d.str", arg1);
    if (arg3 != 0) {
        if (!X_5250_func_001E4C1C(arg0, arg1, &sp48)) {
            return -1;
        }
        Vec5250 v;
        v.x = arg3->x;
        v.y = arg3->y;
        v.z = arg3->z;
        v.w = arg3->w;
        X_5250_func_001E6E00(arg0->unk0, &v, sp48, &sp40, &sp44, 100.0f);
        s1 = X_5250_func_0017FD58(&X_5250_D_007B2580, buf, arg1 > 0x1869F, arg2, (arg5 >> 8) & 1);
        X_5250_func_00180078(&X_5250_D_007B2580, s1, 0);
        X_5250_func_0017FF58(&X_5250_D_007B2580, -1024.0f, s1, sp40, sp44, 0);
    } else {
        s1 = X_5250_func_0017FD58(&X_5250_D_007B2580, buf, arg1 > 0x1869F, arg2, (arg5 >> 8) & 1);
        sp40 = 0x80;
        sp44 = 0x80;
    }
    Sub5250 *sub = &arg0->sub;
    int off = s1 * sizeof(Ent5250);
    ((Ent5250 *)((char *)sub->arr + off))->unk00 = (arg4 != 0) ? (arg5 | 9) : (arg5 | 1);
    ((Ent5250 *)((char *)sub->arr + off))->unk14 = arg1;
    ((Ent5250 *)((char *)sub->arr + off))->unk18 = s1;
    ((Ent5250 *)((char *)sub->arr + off))->unk04 = sp40;
    ((Ent5250 *)((char *)sub->arr + off))->unk08 = sp44;
    return s1;
}

extern "C" int func_001E5428(Obj5428 *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, float fparg0)
{
    int idx = X_5428_func_001E5250(arg0, arg1, arg5, 0, 0, arg6);
    X_5428_func_0017FF58(&X_5428_D_007B2580, idx, arg2, arg3, 0, fparg0);
    X_5428_func_00180078(&X_5428_D_007B2580, idx, arg4);
    Sub5428 *sub = &arg0->sub;
    int off = idx * sizeof(Ent5428);
    ((Ent5428 *)((char *)sub->arr + off))->unk00 = arg6 | 1;
    ((Ent5428 *)((char *)sub->arr + off))->unk14 = arg1;
    ((Ent5428 *)((char *)sub->arr + off))->unk18 = idx;
    ((Ent5428 *)((char *)sub->arr + off))->unk04 = arg2;
    ((Ent5428 *)((char *)sub->arr + off))->unk08 = arg3;
    return idx;
}

extern "C" void func_001E5540(Obj5540 *arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    Ent5540 *p;
    Ent5540 tmp;

    if (X_5540_func_001E4C1C(arg0, arg1, &p) != 0) {
        p->unk2A = arg2;
        p->unk2C = arg3;
        p->unk2E = arg4;
        p->unk30 = arg5;
        return;
    }
    tmp = arg0->unk1550;
    tmp.unk2A = arg2;
    tmp.unk2C = arg3;
    tmp.unk2E = arg4;
    tmp.unk30 = arg5;
    X_5540_func_001E4B48(arg0, arg1, &tmp);
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5660);

extern "C" int func_001E5B60(Obj5B60 *arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        return 0;
    }
    if (X_5B60_func_001800D0(&X_5B60_D_007B2580, arg2) == -1) {
        return 0;
    }
    Sub5B60 *sub = &arg0->sub;
    int off = arg2 * sizeof(Ent5B60);
    return ((Ent5B60 *)((char *)sub->arr + off))->unk14 == arg1;
}

extern "C" int func_001E5BE0(Obj5BE0 *arg0, int arg1)
{
    if (arg1 < 0) {
        return -1;
    }
    if (X_5BE0_func_001800D0(&X_5BE0_D_007B2580, arg1) == -1) {
        return -1;
    }
    Sub5BE0 *sub = &arg0->sub;
    int off = arg1 * sizeof(Ent5BE0);
    return ((Ent5BE0 *)((char *)sub->arr + off))->unk14;
}

extern "C" int func_001E5C40(Obj5C40 *arg0, int arg1, int arg2, int arg3, int arg4)
{
    if (arg2 < 0) {
        return 0;
    }
    if (X_5C40_func_001800D0(&X_5C40_D_007B2580, arg2) == -1) {
        return 0;
    }
    Sub5C40 *sub = &arg0->sub;
    int off = arg2 * sizeof(Ent5C40);
    if (((Ent5C40 *)((char *)sub->arr + off))->unk14 != arg1) {
        return 0;
    }
    ((Ent5C40 *)((char *)sub->arr + off))->unk04 = arg3;
    ((Ent5C40 *)((char *)sub->arr + off))->unk08 = arg4;
    X_5C40_func_0017FF58(&X_5C40_D_007B2580, arg2, arg3, arg4, 0, -1024.0f);
    return 1;
}

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

extern "C" int func_001E6368(Obj6368 *arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        return 0;
    }
    Sub6368 *sub = &arg0->sub;
    int off = arg2 * sizeof(Ent6368);
    if (((Ent6368 *)((char *)sub->arr + off))->unk0C != arg1) {
        return 0;
    }
    return X_6368_func_00180CA8(&X_6368_D_007B2580, arg2) != -1;
}

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

// NON_MATCHING: 13/53 differ, 10 edits
#ifdef NON_MATCHING
struct Ent649C {
    char pad0[4];
    int unk04;
    int unk08;
    unsigned int unk0C;
    char pad10[0x8];
    int unk18;
    char pad1C[0x28 - 0x1C];
};
struct Sub649C {
    char *m_begin;
};
struct Obj649C {
    char pad0[0xD40];
    Sub649C sub;
};
extern int X_649C_D_007B2580 asm("D_007B2580");
extern "C" int X_649C_func_00180CA8(int *, int) asm("func_00180CA8");
extern "C" void X_649C_func_00180EA8(int *, int) asm("func_00180EA8");
extern "C" int X_def_func_001E649C(Obj649C *, unsigned int, int) asm("func_001E649C");

extern "C" int X_def_func_001E649C(Obj649C *arg0, unsigned int arg1, int arg2)
{
    int off = arg2 * 0x28;
    Sub649C *sub = &arg0->sub;
    if (arg2 < 0) {
        return 0;
    }
    if (((Ent649C *)(sub->m_begin + off))->unk0C != arg1) {
        return 0;
    }
    if (X_649C_func_00180CA8(&X_649C_D_007B2580, arg2) == -1) {
        return 0;
    }
    X_649C_func_00180EA8(&X_649C_D_007B2580, arg2);
    ((Ent649C *)(sub->m_begin + off))->unk04 = 0;
    ((Ent649C *)(sub->m_begin + off))->unk08 = 0;
    ((Ent649C *)(sub->m_begin + off))->unk0C = 0;
    ((Ent649C *)(sub->m_begin + off))->unk18 = -1;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E649C);
#endif

extern "C" void func_001E6570(Obj6570 *arg0, int arg1) {
    Ent6570 def;
    int i;
    switch (arg1) {
    case 0:
        for (i = 0; i < 0x30; i++) {
            Ent6570 *p = arg0->sub.arr + i;
            *p = def;
        }
        break;
    case 1:
        for (i = 0; i < 0x30; i++) {
            Ent6570 *p = arg0->sub.arr + i;
            if ((p->flags & 1) == 0) {
                *p = def;
            }
        }
        break;
    case 2:
        for (i = 0; i < 0x30; i++) {
            if (!arg0->sub.arr[i].isFree()) {
                arg0->sub.arr[i] = def;
            }
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6734);

extern "C" int func_001E6CAC(Obj6CAC *arg0)
{
    for (int i = 0; i < 0x30; i++) {
        Ent6CAC *p = &arg0->sub.arr[i];
        if (!p->isFree() && (p->flags & 8)) {
            if (p->unk14 != -1 && X_6CAC_func_001800D0(&X_6CAC_D_007B2580, p->unk18) != -1) {
                return 1;
            }
        }
    }
    return 0;
}

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

// NON_MATCHING: 99/160 differ, 4 relocs differ (size 0x280, game 0x294), 37 edits
#ifdef NON_MATCHING
extern "C" float sqrtf(float);
extern "C" void sub6E00(void *, const void *, const void *) asm("func_00237408");
extern "C" float pan6E00(void *) asm("func_001E6D54");
extern char global6E00[] asm("D_006FBD80");
extern char camera6E00[] asm("D_007812C0");
struct ALIGNED(16) Vec6E00 { float x,y,z,w; }; // 6E00vec
struct Pan6E00 { Vec6E00 *a; Vec6E00 *b; float angle; Vec6E00 *src; }; // 6E00pan
extern "C" void func_001E6E00(int mode, Vec6E00 *src, unsigned short *info, int *left, int *right)
{
    register Vec6E00 *source PS2_REG("$21") = src;
    Vec6E00 pos;
    Vec6E00 dir;
    Pan6E00 pan;
    Vec6E00 delta;
    memset(&pos, 0, 16);
    pos.w = 1.0f;
    register Vec6E00 *direction PS2_REG("$20") = &dir;
    memset(direction, 0, 16);
    register float farDist PS2_REG("$f24") = info[0x2C/2];
    register float farVol PS2_REG("$f22") = info[0x30/2];
    register float nearVol PS2_REG("$f23") = info[0x2E/2];
    register float nearDist PS2_REG("$f21") = info[0x2A/2];
    if (mode != 0) {
        if (mode != 1) {
            *right = 64;
            *left = 64;
            return;
        }
        register int base PS2_REG("$2") = (int)global6E00;
        base += 0x2AB70;
        float *p = (float *)base;
        float px = p[0x40/4], py = p[0x44/4], pz = p[0x48/4];
        float dx = p[0x50/4], dy = p[0x54/4], dz = p[0x58/4];
        pos.x = px; pos.y = py; pos.z = pz;
        direction->x = dx; dir.y = dy; dir.z = dz;
    } else {
        register int base PS2_REG("$3") = (int)camera6E00;
        register Vec6E00 *tmp PS2_REG("$4") = &delta;
        register u_long128 copy PS2_REG("$6");
        copy = *(u_long128 *)(base + 0x22020);
        *(u_long128 *)tmp = copy;
        *(long long *)&pos = *(long long *)&delta;
        *(int *)&pos.z = *(int *)&delta.z;
        copy = *(u_long128 *)(base + 0x22030);
        *(u_long128 *)tmp = copy;
        *(long long *)&dir = *(long long *)&delta;
        *(int *)&dir.z = *(int *)&delta.z;
    }
    sub6E00(&delta, source, &pos);
    float distance = sqrtf(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
    register float volume PS2_REG("$f20");
    volume = farVol;
    if (!(nearDist <= distance)) {
        volume = nearVol;
        if (!(distance <= farDist)) {
            volume = farVol + ((nearVol-farVol)*(distance-nearDist))/(farDist-nearDist);
        }
    }
    if (volume <= 0.0f) {
        *right = 0;
        *left = 0;
        return;
    }
    pan.a = &pos;
    pan.b = direction;
    pan.angle = -1.0471976f;
    pan.src = source;
    *left = (int)(volume * pan6E00(&pan));
    pan.angle = 1.0471976f;
    *right = (int)(volume * pan6E00(&pan));
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6E00);
#endif

Obj7094::Obj7094()
{
    head4 = 0;
    unk288 = -1;
    unk08 = 2;
    end = arr;
    head0 = 0;
}

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

extern "C" void func_001E7184(List7184 *arg0, Node7184 *arg1)
{
    Node7184 *cur = arg0->head;
    if (cur == 0) {
        arg1->next = 0;
        arg0->head = arg1;
        return;
    }
    if (cur->prio > arg1->prio) {
        arg1->next = cur;
        arg0->head = arg1;
        return;
    }
    Node7184 *p = cur;
    while (p != 0) {
        Node7184 *next = p->next;
        if (next == 0) {
            arg1->next = 0;
            p->next = arg1;
            return;
        }
        if (next->prio > arg1->prio) {
            arg1->next = next;
            p->next = arg1;
            break;
        }
        p = next;
    }
}

extern "C" void func_001E71F4(void) {
}

extern "C" int func_001E71FC(Obj71FC *arg0, int arg1, int arg2, int arg3, int arg4, VObj71FC *arg5, void *arg6, int *arg7, void *arg8)
{
    if (arg2 == -1) {
        arg2 = arg0->unk58;
    }
    Node71FC *node = (Node71FC *)X_71FC___builtin_new(sizeof(Node71FC));
    if (node == 0) {
        return 0;
    }
    node->obj = arg5;
    node->next = arg0->head4;
    node->state = 0;
    node->unk14 = arg8;
    node->id = arg0->nextId++;
    if (arg7 != 0) {
        node->unk10 = arg7;
        *arg7 = node->id;
    }
    X_71FC_func_001E7E50(arg0, node->id);
    node->unk18 = arg6;
    node->unk20 = arg5->v1();
    node->unk28 = arg3;
    node->unk24 = arg2;
    if (arg4 == 0) {
        node->unk2C = 0;
    } else {
        node->unk2C = arg2 + arg4 - 1;
    }
    node->prio = arg2;
    arg5->v3();
    X_71FC_func_001E7184(arg0, node);
    return 1;
}

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

extern "C" void func_001E7414(List7414 *arg0, int arg1, int arg2)
{
    if (arg1 != -1) {
        Node7414 *p = arg0->head;
        while (p != 0) {
            if (p->unk0C == arg1) {
                X_7414_func_001E7340(arg0, p, arg2);
                p->state = arg2;
                break;
            }
            p = p->next;
        }
    }
}

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

extern "C" int X_def_func_001E76B8(List76B8 *arg0, int arg1)
{
    Node76B8 *p = arg0->head;
    int ret = 0;
    while (p != 0) {
        if (p->unk0C == arg1 && p->state != 2) {
            p->state = 2;
            X_76B8_func_001E7698(arg0, p);
            ret = 1;
            break;
        }
        p = p->next;
    }
    return ret;
}

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

// NON_MATCHING: 104/149 differ, 6 relocs differ (size 0x254, game 0x25C), 40 edits
#ifdef NON_MATCHING
class Virtual7A20 { public:
    virtual void X__vfunc_00();
    virtual void X__vfunc_01();
    virtual void X__vfunc_02();
    virtual int X__vfunc_03(int, int, int);
}; // 7A20
extern "C" void X_func_001C57A0(int) asm("func_001C57A0");
extern "C" void X_func_001E7184(int, int) asm("func_001E7184");
extern "C" void X_func_001E785C(int) asm("func_001E785C");
extern "C" void X_func_001E7C7C(int, int) asm("func_001E7C7C");
extern "C" void X_func_00204090(int) asm("func_00204090");
extern "C" int func_001E7A20(int arg0)
{
    volatile int current;
    int temp_s3;
    int temp_v0_2;
    int temp_v1;
    int var_s3;
    int var_s4;
    unsigned int temp_v1_3;
    int temp_a0;
    int temp_a1;
    int temp_a1_2;
    int temp_a1_3;
    int var_s0;
    int var_s2;
    int var_s2_2;
    int temp_v1_2;
    int temp_s0;
    int temp_v0;

    temp_s0 = arg0 + 0x40;
    temp_s3 = arg0 + 0x84;
    var_s2 = 0;
    current = 0;
    X_func_00204090(temp_s0);
    temp_a1 = M2C_FIELD(arg0, int *, 0);
    M2C_FIELD(arg0, int *, 0x284) = temp_s3;
    current = temp_a1;
    if (temp_a1 != 0) {
        if ((unsigned int) M2C_FIELD(temp_s0, unsigned int *, 0x18) < (unsigned int) M2C_FIELD(temp_a1, unsigned int *, 0x34)) {
            current = 0;
        } else {
            M2C_FIELD(arg0, int *, 0) = M2C_FIELD(temp_a1, int *, 4);
            M2C_FIELD(temp_a1, int *, 4) = 0;
            current = temp_a1;
        }
    } else {
        current = 0;
    }
loop_28:
    if (current != 0) {
        temp_v1 = M2C_FIELD(current, int *, 8);
        if (temp_v1 == 0) {                          
            temp_v0_2 = ((Virtual7A20 *)M2C_FIELD(current, int *, 0))->X__vfunc_03(M2C_FIELD(current, int *, 0xC), M2C_FIELD(arg0, int *, 0x64), M2C_FIELD(current, int *, 0x18));
            M2C_FIELD(current, unsigned int *, 0x30) = (unsigned int) M2C_FIELD(current, unsigned int *, 0x34);
            M2C_FIELD(current, unsigned int *, 0x34) = (unsigned int) (M2C_FIELD(current, unsigned int *, 0x34) + M2C_FIELD(current, int *, 0x28));
            if (temp_v0_2 != 0) {
                var_s2 = current;
            } else if (M2C_FIELD(current, unsigned int *, 0x2C) != 0 && M2C_FIELD(current, unsigned int *, 0x2C) < M2C_FIELD(current, unsigned int *, 0x34)) {
                var_s2 = current;
            } else {
                X_func_001E7184(arg0, current);
            }
        } else if (temp_v1 == 2) {
            var_s2 = current;
        } else {
            M2C_FIELD(current, unsigned int *, 0x30) = (unsigned int) M2C_FIELD(current, unsigned int *, 0x34);
            M2C_FIELD(current, unsigned int *, 0x34) = (unsigned int) (M2C_FIELD(current, unsigned int *, 0x34) + M2C_FIELD(current, int *, 0x28));
            X_func_001E7184(arg0, current);
        }
        temp_a0 = M2C_FIELD(arg0, int *, 0);
        if (temp_a0 == 0) {
            current = 0;
        } else if ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x58) < (unsigned int) M2C_FIELD(temp_a0, unsigned int *, 0x34)) {
            current = 0;
        } else {
            M2C_FIELD(arg0, int *, 0) = M2C_FIELD(temp_a0, int *, 4);
            M2C_FIELD(temp_a0, int *, 4) = 0;
            current = temp_a0;
        }
        temp_a1_2 = var_s2;
        if (var_s2 != 0) {
            var_s2 = 0;
            X_func_001E7C7C(arg0, temp_a1_2);
        }
        goto loop_28;
    }
    if (M2C_FIELD(arg0, int *, 0x284) != temp_s3) {
        X_func_001E785C(arg0);
    }
    var_s0 = M2C_FIELD(arg0, int *, 0);
    var_s4 = 0;
    var_s2_2 = 0;
    if (var_s0 != 0) {
        var_s3 = 0x280;
        do {
            if (M2C_FIELD(var_s0, int *, 8) == 2) {
                temp_a1_3 = var_s0;
                var_s0 = M2C_FIELD(var_s0, int *, 4);
                if (temp_a1_3 == M2C_FIELD(arg0, int *, 0)) {
                    M2C_FIELD(arg0, int *, 0) = var_s0;
                } else if (var_s2_2 != var_s0) {
                    M2C_FIELD(var_s2_2, int *, 4) = var_s0;
                } else {
                    M2C_FIELD(var_s0, int *, 4) = 0;
                }
                X_func_001E7C7C(arg0, temp_a1_3);
            } else {
                var_s2_2 = var_s0;
                var_s4 += 1;
                M2C_FIELD((arg0 + var_s3), int *, 8) = (int) M2C_FIELD(var_s0, int *, 0xC);
                var_s3 += 4;
                var_s0 = M2C_FIELD(var_s0, int *, 4);
            }
        } while (var_s0 != 0);
    }
    M2C_FIELD((int) (&((int *)(arg0))[var_s4]), int *, 0x288) = -1;
    X_func_001C57A0((int)&D_007812C0);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7A20);
#endif

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

extern "C" void func_001E7D08(void *arg0, Node7D08 *arg1)
{
    X_7D08_func_001E7698(arg0, arg1);
    if (arg1->obj != 0) {
        arg1->obj->v5();
        if (arg1->flags & 1) {
            X_7D08___builtin_delete(arg1->obj);
            arg1->flags &= ~1;
        }
        arg1->obj = 0;
    }
}

extern "C" int func_001E7D7C(TskLogger7D7C *arg0, int arg1)
{
    if (arg1 == -1) {
        return 0;
    }
    for (int i = 0; i < 0x100 && arg0->sub.arr[i] != -1; i++) {
        if (arg0->sub.arr[i] == arg1) {
            return 1;
        }
    }
    return 0;
}

extern "C" void func_001E7DE8(TskLogger7DE8 *arg0, int arg1)
{
    if (arg1 == -1) {
        return;
    }
    for (int i = 0; i < 0x100 && arg0->sub.arr[i] != -1; i++) {
        if (arg0->sub.arr[i] == arg1) {
            arg0->sub.arr[i] = -2;
        }
    }
}

extern "C" void func_001E7E50(TskLogger7DE8 *arg0, int arg1)
{
    if (arg1 == -1) {
        return;
    }
    int i;
    for (i = 0; i < 0x100 && arg0->sub.arr[i] != -1; i++) {
        if (arg0->sub.arr[i] == arg1) {
            return;
        }
    }
    if (i < 0xFE) {
        arg0->sub.arr[i] = arg1;
        arg0->sub.arr[i + 1] = -1;
    }
}

extern "C" int TskTest__vfunc_04()
{
    return 0;
}


TskLogger7ED8::TskLogger7ED8(int arg1)
{
    unk04 = arg1;
    vt = &_vt$9TskLogger;
    unk08 = X_7ED8_func_001CBE38(D_007812C0, (unsigned int)arg1);
}

extern "C" int TskLogger__vfunc_04()
{
    int x;
    noop(&x);
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD900);
INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD910);
INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD920);
