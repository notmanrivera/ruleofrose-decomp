// game/gamsnd.h: types used by game/gamsnd.cpp.
// These are the existing reconstructed layouts, moved without changing their
// copy/alignment behavior. TskLogger reuses CmnITask and vectors reuse Eff0.h.
// Function-suffixed record and manager types still
// need consolidation once their differing aligned/unaligned copies are resolved.
#ifndef GAME_GAMSND_H
#define GAME_GAMSND_H
#include "ror.h"
#ifdef TARGET_PS2
#pragma interface
#endif
#include "task/cmnitask.h"
#include "utl/filereader.h"
#include "unk/Eff0.h"

struct ALIGNED(16) Item2DB4 {
    char unused[0x10];
    EffVec3 position;
    int pad1C; // decl2DB4
    unsigned int id;
    int handle;
    unsigned int flags;
    int zero;
    int scene;
    void *data;
    float distance;
    int a,b;
    char tail[12];
};

struct Node2DB4 { Node2DB4 *prev,*next; Item2DB4 data; };

class Iter2DB4 { public:
    Node2DB4 *node;
    Iter2DB4() : node(0) {}
    Iter2DB4(Node2DB4 *n) : node(n) {}
    Iter2DB4(const Iter2DB4 &n) : node(n.node) {}
    Item2DB4 &operator*() const { return node->data; }
    Iter2DB4 &operator++() { node = node->next; return *this; }
    bool operator!=(const Iter2DB4 &n) const { return node != n.node; }
};

struct Chain2DB4 {
    Node2DB4 head;
    int count;
    void insert(Node2DB4 *target, Node2DB4 *n) {
        Node2DB4 *p = target->prev;
        n->prev = p;
        p->next = n;
        n->next = target;
        target->prev = n;
        ++count;
    }
    void push(Node2DB4 *n) {
        if (count == 0) { head.next = n; n->prev = &head; }
        else { head.prev->next = n; n->prev = head.prev; }
        n->next = &head;
        head.prev = n;
        ++count;
    }
};

struct Que2DB4 {
    Chain2DB4 free, used;
    Iter2DB4 begin() { return Iter2DB4(used.head.next); }
    Iter2DB4 end() { return Iter2DB4(&used.head); }
    Iter2DB4 insert(Iter2DB4 where, const Item2DB4 &item) {
        Node2DB4 *n = free.head.prev;
        Node2DB4 *previous = n->prev;
        free.head.prev = previous;
        previous->next = &free.head;
        --free.count;
        n->data = item;
        used.insert(where.node, n);
        return where;
    }
    void push(const Item2DB4 &item) {
        Node2DB4 *n = free.head.prev;
        Node2DB4 *previous = n->prev;
        free.head.prev = previous;
        previous->next = &free.head;
        --free.count;
        n->data = item;
        used.push(n);
    }
};

struct Obj2DB4 { char pad[0x40]; Que2DB4 queue; };

struct Ent5250 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    char pad0C[8];
    int m_unk14;
    int m_unk18;
    char pad1C[0xC];
};

struct Sub5250 {
    Ent5250 *arr;
};

struct Obj5250 {
    int m_unk00;
    char pad4[0xD40 - 4];
    Sub5250 sub;
};

struct Ent6570 {
    unsigned int flags;
    char pad4[0x10];
    int m_unk14;
    int m_unk18;
    char pad1C[0x28 - 0x1C];
    Ent6570() { m_unk14 = -1; m_unk18 = -1; }
    bool isFree() const { return (flags & 1) == 0; }
};

struct Sub6570 {
    Ent6570 *arr;
};

struct Obj6570 {
    char pad0[0xD40];
    Sub6570 sub;
};

struct Msg50C8 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    float m_unk18;
    char pad1C[0x40 - 0x1C];
};

struct Elem28_50C8 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
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

struct SndMsg17B4 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    char pad18[0x40 - 0x18];
};

struct Ent15A0 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    char pad10[0x24 - 0x10];
};

struct Ent1654 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
};

struct Ent1680 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
};

struct Obj17B4 {
    char pad0000[0x15A0];
    Ent15A0 arr15A0[5];     // +0x15A0
    Ent1654 arr1654[3];     // +0x1654
    char pad1678[0x1680 - 0x1678];
    Ent1680 arr1680[8];     // +0x1680 (arr1680[0].m_unk04 is +0x1684)
    int m_unk1700;
    int m_unk1704;
    int m_unk1708;            // +0x1708
    char pad170C[0x1870 - 0x170C];
    int m_unk1870;            // +0x1870
};

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
    int *m_unk10;         // +0x10
    void *m_unk14;        // +0x14
    void *m_unk18;        // +0x18
    int m_unk1C;          // +0x1C
    int m_unk20;          // +0x20
    int m_unk24;          // +0x24
    int m_unk28;          // +0x28
    int m_unk2C;          // +0x2C
    int m_unk30;          // +0x30
    int prio;           // +0x34
    char pad38[0x40 - 0x38];
};

struct Obj71FC {
    Node71FC *head0;    // +0x00
    Node71FC *head4;    // +0x04
    int nextId;         // +0x08
    char pad0C[0x58 - 0x0C];
    int m_unk58;          // +0x58
};

struct Ent5540 {
    char pad00[0x2A];
    short m_unk2A;
    short m_unk2C;
    short m_unk2E;
    short m_unk30;
    char pad32[0x38 - 0x32];
};

struct Obj5540 {
    char pad00[0x1550];
    Ent5540 m_unk1550;
};

struct Ent5428 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    char pad0C[0x14 - 0x0C];
    int m_unk14;
    int m_unk18;
    char pad1C[0x28 - 0x1C];
};

struct Sub5428 {
    Ent5428 *arr;
};

struct Obj5428 {
    char pad0[0xD40];
    Sub5428 sub;
};

struct Ent5C40 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    char pad0C[0x14 - 0x0C];
    int m_unk14;
    char pad18[0x28 - 0x18];
};

struct Sub5C40 {
    Ent5C40 *arr;
};

struct Obj5C40 {
    char pad0[0xD40];
    Sub5C40 sub;
};

struct Ent6CAC {
    unsigned int flags;
    char pad4[0x10];
    int m_unk14;
    int m_unk18;
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

struct Ent5B60 {
    char pad0[0x14];
    int m_unk14;
    char pad18[0x28 - 0x18];
};

struct Sub5B60 {
    Ent5B60 *arr;
};

struct Obj5B60 {
    char pad0[0xD40];
    Sub5B60 sub;
};

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
    int m_unk04;
    Sub7D7C sub;
};

struct Node76B8 {
    void *obj;
    Node76B8 *next;
    int state;
    int m_unk0C;
};

struct List76B8 {
    Node76B8 *head;
};

struct Sub7DE8 {
    char pad[0x280];
    int arr[0x100];
};

struct TskLogger7DE8 {
    void *vt;
    int m_unk04;
    Sub7DE8 sub;
};

struct Node7414 {
    void *obj;
    Node7414 *next;
    int state;
    int m_unk0C;
};

struct List7414 {
    Node7414 *head;
};

struct Ent4908 {
    char name[0x1C];
    int m_unk1C;
    char pad[0x38 - 0x20];
};

struct Ent5BE0 {
    char pad0[0x14];
    int m_unk14;
    char pad18[0x28 - 0x18];
};

struct Sub5BE0 {
    Ent5BE0 *arr;
};

struct Obj5BE0 {
    char pad0[0xD40];
    Sub5BE0 sub;
};

struct Ent6368 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    char pad10[0x28 - 0x10];
};

struct Sub6368 {
    Ent6368 *arr;
};

struct Obj6368 {
    char pad0[0xD40];
    Sub6368 sub;
};

struct Sub7094 {
    char pad[0x44];
    Sub7094() asm("func_00203D94");
};

struct Obj7094 {
    int head0;
    int head4;
    int m_unk08;
    char pad0C[0x34];
    Sub7094 sub40;
    int arr[0x80];
    int *end;
    int m_unk288;
    Obj7094() asm("func_001E7094");
};

// Original class name and base: _vt$9TskLogger and notes/class_hierarchy.txt.
class TskLogger : public CmnITask {
public:
    int m_unk04;                       // +0x04
    int m_unk08;                       // +0x08
    TskLogger(int arg1) asm("func_001E7ED8");
    virtual int get_task_type() { return 0x11; }
    virtual void init() {}
    virtual int exec(int, int, void *) asm("TskLogger__vfunc_04");
    virtual void term() {}
    virtual ~TskLogger();
};

struct SndElem {
    char m_pad00[0x34];
    int m_unk34;            // +0x34 (node +0x3C)
    char m_pad38[0x20];
};

struct SndNode {
    SndNode *m_prev;        // +0x00
    SndNode *m_next;        // +0x04
    SndElem m_data;      // +0x08
};



class SndIt {
public:
    SndNode *m_node;
    SndIt() : m_node(0) {}
    SndIt(SndNode *theNode) : m_node(theNode) {}
    SndIt(const SndIt &theIt) : m_node(theIt.m_node) {}
    SndElem &operator*() const { return m_node->m_data; }
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

struct Elem28 { int a[10]; };

struct Range { char *m_begin; char *m_end; int m_max; };

struct m2c_block36 { int w[9]; };

struct m2c_ulong { long v; } __attribute__((packed));

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

struct Ent15A0_1620 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
};

struct Ent1654_1620 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
};

struct Obj1620 {
    char pad0000_1620[0x15A0];
    Ent15A0_1620 arr15A0_1620[5];
    Ent1654_1620 arr1654_1620[3];
    char pad1678_1620[0xC];
    int m_unk1684;
};

struct SndNode1FA4 {
    SndNode1FA4 *m_prev;
    SndNode1FA4 *m_next;
    char m_data[0x58];
};

struct SndChain1FA4 {
    SndNode1FA4 m_head;
    int m_num;
    void splice(SndChain1FA4 &theOther) {
        if (theOther.m_num != 0) {
            m_head.m_prev->m_next = theOther.m_head.m_next;
            SndNode1FA4 *last = m_head.m_prev;
            last->m_next->m_prev = last;
            SndNode1FA4 *tail = theOther.m_head.m_prev;
            m_head.m_prev = tail;
            tail->m_next = &m_head;
            m_num += theOther.m_num;
            theOther.m_num = 0;
            theOther.m_head.m_prev = &theOther.m_head;
            theOther.m_head.m_next = &theOther.m_head;
        } // 1FA4 splice if
    } // 1FA4 splice
};

struct SndQue1FA4 {
    SndChain1FA4 m_free;
    char m_pad64[0x0C];
    SndChain1FA4 m_used;
    char m_padD4[0x0C];
    int m_max;
    void clear() {
        if (m_used.m_num != 0) {
            m_free.splice(m_used);
        } // 1FA4 clear if
    } // 1FA4 clear
};

struct Elem1FA4 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    char pad10[0x08];
    int m_unk18;
    char pad1C[0x28 - 0x1C];
};

struct Range1FA4 {
    Elem1FA4 *m_begin;
    Elem1FA4 *m_end;
    int m_max;
    char pad0C[0x34];
    Elem1FA4 m_buf[0x30];
    void clear() {
        for (Elem1FA4 *p = m_begin; p != m_end; p++) {
            p->~Elem1FA4();
        } // 1FA4 loop
        m_end = m_buf;
        m_max = 0x30;
        m_begin = m_buf;
    } // 1FA4 clear
};

struct Item1FA4 {
    int m_unk00;
    char pad04[0x08];
    int m_unk0C;
    char pad10[0x14];
};

struct Sub1580_1FA4 {
    char pad00[0x20];
    Item1FA4 arr[4];
};

struct Obj1FA4 {
    char pad00[0x40];
    SndQue1FA4 m_que;
    char pad124[0xD40 - 0x124];
    Range1FA4 m_range;
    char pad1500[0x1580 - 0x1500];
    Sub1580_1FA4 m_sub;
    char pad1630[0x1684 - 0x1630];
    int m_unk1684;
    char pad1688[0x1708 - 0x1688];
    int m_unk1708;
    int m_unk170C;
    int m_unk1710;
    int m_unk1714;
    int m_unk1718;
};

struct ALIGNED(16) Ent2178 {
    char pad00[0x20];
    int m_unk20;
    int m_unk24;
    unsigned int flags;
    char pad2C[0x24];
};

template <class T> class GamList2178 {
public:
    struct Node {
        Node *m_prev;
        Node *m_next;
        T m_data;
    };
    struct Chain {
        Node m_head;
        int m_num;
        void push_back(Node *theNode) {
            if (m_num == 0) {
                m_head.m_next = theNode;
                theNode->m_prev = &m_head;
            } else {
                m_head.m_prev->m_next = theNode;
                theNode->m_prev = m_head.m_prev;
            }
            theNode->m_next = &m_head;
            m_head.m_prev = theNode;
            ++m_num;
        }
        void unlink(Node *theNode) {
            Node *head = &m_head;
            if (theNode == head->m_next) {
                Node *next = theNode->m_next;
                head->m_next = next;
                next->m_prev = head;
            } else {
                Node *p = theNode->m_prev;
                if (theNode == head->m_prev) {
                    head->m_prev = p;
                    p->m_next = head;
                } else {
                    p->m_next = theNode->m_next;
                    Node *prev = theNode->m_prev;
                    p = theNode->m_next;
                    p->m_prev = prev;
                }
            }
            --m_num;
        }
    };
    class iterator {
    public: // GamList2178 iterator
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theOther) : m_node(theOther.m_node) {}
        T &operator*() { return m_node->m_data; }
        bool operator!=(const iterator &theOther) const { return m_node != theOther.m_node; }
        iterator &operator++() { m_node = m_node->m_next; return *this; }
    };
    Chain m_free;
    Chain m_used;
    int m_max;
    iterator begin() { return iterator(m_used.m_head.m_next); }
    iterator end() { return iterator(&m_used.m_head); }
    iterator erase(iterator thePos) {
        iterator next = thePos;
        ++next;
        Node *n = thePos.m_node;
        m_used.unlink(n);
        m_free.push_back(n);
        return next;
    }
};

template <class T, int N> class GamPool2178 : public GamList2178<T> {
public:
    typename GamList2178<T>::Node m_nodes[N];
};

struct Obj2178 {
    char pad00[0x40];
    GamPool2178<Ent2178, 6> m_que;
};

struct ALIGNED(16) Item239C {
    char unused[0x10];
    EffVec3 position;
    int pad1C; // decl239C
    unsigned int id;
    int handle;
    unsigned int flags;
    int zero;
    int scene;
    void *data;
    float distance;
    int a,b;
    char tail[12];
};

struct Node239C { Node239C *prev,*next; Item239C data; };

class Iter239C { public:
    Node239C *node;
    Iter239C() : node(0) {}
    Iter239C(Node239C *n) : node(n) {}
    Iter239C(const Iter239C &n) : node(n.node) {}
    Item239C &operator*() const { return node->data; }
    Iter239C &operator++() { node = node->next; return *this; }
    bool operator!=(const Iter239C &n) const { return node != n.node; }
};

struct Chain239C {
    Node239C head;
    int count;
    void push(Node239C *n) {
        if (count == 0) { head.next = n; n->prev = &head; }
        else { head.prev->next = n; n->prev = head.prev; }
        n->next = &head;
        head.prev = n;
        ++count;
    }
};

struct Que239C {
    Chain239C free, used;
    Iter239C begin() { return Iter239C(used.head.next); }
    Iter239C end() { return Iter239C(&used.head); }
    Iter239C insert(Iter239C where, const Item239C &item) {
        Node239C *n = free.head.prev;
        Node239C *previous = n->prev;
        free.head.prev = previous;
        previous->next = &free.head;
        --free.count;
        n->data = item;
        Node239C *target = where.node;
        Node239C *p = target->prev;
        n->prev = p;
        p->next = n;
        n->next = target;
        target->prev = n;
        ++used.count;
        return where;
    }
    void push(const Item239C &item) {
        Node239C *n = free.head.prev;
        Node239C *previous = n->prev;
        free.head.prev = previous;
        previous->next = &free.head;
        --free.count;
        n->data = item;
        used.push(n);
    }
};

struct Obj239C { char pad[0x40]; Que239C queue; };

struct ALIGNED(16) Ent2AA0 {
    char pad00[0x20];
    unsigned int m_unk20;
    int m_unk24;
    char pad28[0x08];
    int m_unk30;
    char pad34[0x1C];
};

struct SndNode2AA0 {
    SndNode2AA0 *m_prev;
    SndNode2AA0 *m_next;
    Ent2AA0 m_data;
};

struct SndChain2AA0 {
    SndNode2AA0 m_head;
    int m_num;
    void push_back(SndNode2AA0 *theNode) {
        if (m_num == 0) {
            m_head.m_next = theNode;
            theNode->m_prev = &m_head;
        } else {
            m_head.m_prev->m_next = theNode;
            theNode->m_prev = m_head.m_prev;
        }
        theNode->m_next = &m_head;
        m_head.m_prev = theNode;
        ++m_num;
    }
    void unlink(SndNode2AA0 *theNode) {
        if (theNode == m_head.m_next) {
            SndNode2AA0 *next = theNode->m_next;
            m_head.m_next = next;
            next->m_prev = &m_head;
        } else {
            SndNode2AA0 *p = theNode->m_prev;
            if (theNode == m_head.m_prev) {
                m_head.m_prev = p;
                p->m_next = &m_head;
            } else {
                p->m_next = theNode->m_next;
                SndNode2AA0 *prev = theNode->m_prev;
                p = theNode->m_next;
                p->m_prev = prev;
            }
        }
        --m_num;
    }
};

class SndIt2AA0 {
public: // SndIt2AA0
    SndNode2AA0 *m_node;
    SndIt2AA0() : m_node(0) {}
    SndIt2AA0(SndNode2AA0 *theNode) : m_node(theNode) {}
    SndIt2AA0(const SndIt2AA0 &theIt) : m_node(theIt.m_node) {}
    Ent2AA0 &operator*() const { return m_node->m_data; }
    SndIt2AA0 &operator++() {
        m_node = m_node->m_next;
        return *this;
    }
    bool operator!=(const SndIt2AA0 &theIt) const { return m_node != theIt.m_node; }
};

class SndQue2AA0 {
public: // SndQue2AA0
    SndChain2AA0 m_free;
    SndChain2AA0 m_used;
    int m_max;
    SndIt2AA0 begin() { return SndIt2AA0(m_used.m_head.m_next); }
    SndIt2AA0 end() { return SndIt2AA0(&m_used.m_head); }
    SndIt2AA0 erase(SndIt2AA0 thePos) {
        SndIt2AA0 next = thePos;
        ++next;
        SndNode2AA0 *n = thePos.m_node;
        m_used.unlink(n);
        m_free.push_back(n);
        return next;
    }
};

struct Obj2AA0 {
    char pad00[0x40];
    SndQue2AA0 m_que;
};

struct ALIGNED(16) Ent2C40 {
    char pad00_2C40[0x20];
    unsigned int m_unk20;
    int m_unk24;
    char pad28_2C40[0x04];
    int m_unk2C;
    char pad30_2C40[0x20];
};

struct SndNode2C40 {
    SndNode2C40 *m_prev2C40;
    SndNode2C40 *m_next2C40;
    Ent2C40 m_data2C40;
};

struct SndChain2C40 {
    SndNode2C40 m_head2C40;
    int m_num2C40;
    void push_back(SndNode2C40 *theNode) {
        if (m_num2C40 == 0) {
            m_head2C40.m_next2C40 = theNode;
            theNode->m_prev2C40 = &m_head2C40;
        } else {
            m_head2C40.m_prev2C40->m_next2C40 = theNode;
            theNode->m_prev2C40 = m_head2C40.m_prev2C40;
        }
        theNode->m_next2C40 = &m_head2C40;
        m_head2C40.m_prev2C40 = theNode;
        ++m_num2C40;
    }
    void unlink(SndNode2C40 *theNode) {
        if (theNode == m_head2C40.m_next2C40) {
            SndNode2C40 *next = theNode->m_next2C40;
            m_head2C40.m_next2C40 = next;
            next->m_prev2C40 = &m_head2C40;
        } else {
            SndNode2C40 *prev = theNode->m_prev2C40;
            if (theNode == m_head2C40.m_prev2C40) {
                m_head2C40.m_prev2C40 = prev;
                prev->m_next2C40 = &m_head2C40;
            } else {
                prev->m_next2C40 = theNode->m_next2C40;
                SndNode2C40 *prev2 = theNode->m_prev2C40;
                prev = theNode->m_next2C40;
                prev->m_prev2C40 = prev2;
            }
        }
        --m_num2C40;
    }
};

class SndIt2C40 {
public: // SndIt2C40
    SndNode2C40 *m_node2C40;
    SndIt2C40() : m_node2C40(0) {}
    SndIt2C40(SndNode2C40 *node) : m_node2C40(node) {}
    SndIt2C40(const SndIt2C40 &rhs) : m_node2C40(rhs.m_node2C40) {}
    Ent2C40 &operator*() { return m_node2C40->m_data2C40; }
    SndIt2C40 &operator++() { m_node2C40 = m_node2C40->m_next2C40; return *this; }
    bool operator!=(const SndIt2C40 &rhs) const { return m_node2C40 != rhs.m_node2C40; }
};

class SndQue2C40 {
public: // SndQue2C40
    SndChain2C40 m_free2C40;
    SndChain2C40 m_used2C40;
    SndIt2C40 begin() { return SndIt2C40(m_used2C40.m_head2C40.m_next2C40); }
    SndIt2C40 end() { return SndIt2C40(&m_used2C40.m_head2C40); }
    SndIt2C40 erase(SndIt2C40 thePos) {
        SndIt2C40 next = thePos;
        ++next;
        SndNode2C40 *n = thePos.m_node2C40;
        m_used2C40.unlink(n);
        m_free2C40.push_back(n);
        return next;
    }
};

struct Obj2C40 {
    char pad00_2C40[0x40];
    SndQue2C40 m_que2C40;
};

struct ALIGNED(16) Ent34EC {
    char pad00[0x20];
    int m_unk20;
    char pad24[0x0C];
    int m_unk30;
    char pad34[0x1C];
};

template <class T> class GamList34EC {
public:
    struct Node {
        Node *m_prev;
        Node *m_next;
        T m_data;
    };
    struct Chain {
        Node m_head;
        int m_num;
        void push_back(Node *theNode) {
            if (m_num == 0) {
                m_head.m_next = theNode;
                theNode->m_prev = &m_head;
            } else {
                m_head.m_prev->m_next = theNode;
                theNode->m_prev = m_head.m_prev;
            }
            theNode->m_next = &m_head;
            m_head.m_prev = theNode;
            ++m_num;
        }
        void unlink(Node *theNode) {
            Node *head = &m_head;
            if (theNode == head->m_next) {
                Node *next = theNode->m_next;
                head->m_next = next;
                next->m_prev = head;
            } else {
                Node *p = theNode->m_prev;
                if (theNode == head->m_prev) {
                    head->m_prev = p;
                    p->m_next = head;
                } else {
                    p->m_next = theNode->m_next;
                    Node *prev = theNode->m_prev;
                    p = theNode->m_next;
                    p->m_prev = prev;
                }
            }
            --m_num;
        }
    };
    class iterator {
    public:
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        T &operator*() const { return m_node->m_data; }
        iterator &operator++() {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    Chain m_free;
    Chain m_used;
    int m_max;
    iterator begin() { return iterator(m_used.m_head.m_next); }
    iterator end() { return iterator(&m_used.m_head); }
    iterator erase(iterator thePos) {
        iterator next = thePos;
        ++next;
        Node *n = thePos.m_node;
        m_used.unlink(n);
        m_free.push_back(n);
        return next;
    }
};

template <class T, int N> class GamPool34EC : public GamList34EC<T> {
public:
    typename GamList34EC<T>::Node m_nodes[N] ALIGNED(64);
};

struct Obj34EC {
    char pad00[0x40];
    GamPool34EC<Ent34EC, 6> m_que;
};

struct ALIGNED(16) Ent3698 {
    char pad00_3698[0x20];
    int m_unk20;
    char pad24_3698[0x08];
    int m_unk2C;
    char pad30_3698[0x20];
};

struct SndNode3698 {
    SndNode3698 *m_prev3698;
    SndNode3698 *m_next3698;
    Ent3698 m_data3698;
};

struct SndChain3698 {
    SndNode3698 m_head3698;
    int m_num3698;
    void push_back(SndNode3698 *theNode) {
        if (m_num3698 == 0) {
            m_head3698.m_next3698 = theNode;
            theNode->m_prev3698 = &m_head3698;
        } else {
            m_head3698.m_prev3698->m_next3698 = theNode;
            theNode->m_prev3698 = m_head3698.m_prev3698;
        }
        theNode->m_next3698 = &m_head3698;
        m_head3698.m_prev3698 = theNode;
        ++m_num3698;
    }
    void unlink(SndNode3698 *theNode) {
        if (theNode == m_head3698.m_next3698) {
            SndNode3698 *next = theNode->m_next3698;
            m_head3698.m_next3698 = next;
            next->m_prev3698 = &m_head3698;
        } else {
            SndNode3698 *prev = theNode->m_prev3698;
            if (theNode == m_head3698.m_prev3698) {
                m_head3698.m_prev3698 = prev;
                prev->m_next3698 = &m_head3698;
            } else {
                prev->m_next3698 = theNode->m_next3698;
                theNode->m_next3698->m_prev3698 = theNode->m_prev3698;
            }
        }
        --m_num3698;
    }
};

class SndIt3698 {
public: // SndIt3698
    SndNode3698 *m_node3698;
    SndIt3698() : m_node3698(0) {}
    SndIt3698(SndNode3698 *node) : m_node3698(node) {}
    SndIt3698(const SndIt3698 &rhs) : m_node3698(rhs.m_node3698) {}
    Ent3698 &operator*() { return m_node3698->m_data3698; }
    SndIt3698 &operator++() { m_node3698 = m_node3698->m_next3698; return *this; }
    bool operator!=(const SndIt3698 &rhs) const { return m_node3698 != rhs.m_node3698; }
};

class SndQue3698 {
public: // SndQue3698
    SndChain3698 m_free3698;
    SndChain3698 m_used3698;
    SndIt3698 begin() { return SndIt3698(m_used3698.m_head3698.m_next3698); }
    SndIt3698 end() { return SndIt3698(&m_used3698.m_head3698); }
    SndIt3698 erase(SndIt3698 thePos) {
        SndIt3698 next = thePos;
        ++next;
        SndNode3698 *n = thePos.m_node3698;
        m_used3698.unlink(n);
        m_free3698.push_back(n);
        return next;
    }
};

struct Obj3698 {
    char pad00_3698[0x40];
    SndQue3698 m_que3698;
};

struct Entry386C { int unused, left, right; char rest[0x1C]; };

struct Obj386C {
    int mode;
    char pad04[0xD3C];
    Entry386C *entries;
    char padD44[0x80C];
    char fallback[0x31C];
    float multiplier;
};

struct ALIGNED(16) Item3C24 {
    float unused[4];
    float x,y,z; int pad;
    unsigned int id; int handle; unsigned int flags; int zero;
    int scene; void *data; float distance; int a,b; char tail[12];
};

struct Node3C24 { Node3C24 *prev,*next; Item3C24 item; };

struct Iter3C24 {
    Node3C24 *node;
    Iter3C24():node(0) {}
    Iter3C24(Node3C24 *n):node(n) {}
    Iter3C24(const Iter3C24 &i):node(i.node) {}
    bool operator!=(const Iter3C24 &i) const { return node!=i.node; }
    Item3C24 &operator*() const { return node->item; }
    Iter3C24 &operator++() { node=node->next; return *this; }
};

struct Iter4120 { // 4120decl
    int node; // 4120decl
    Iter4120() : node(0) {} // 4120decl
    Iter4120(int n) : node(n) {} // 4120decl
    Iter4120(const Iter4120 &i) : node(i.node) {} // 4120decl
    Iter4120 &operator++() { node = *(int *)(node+4); return *this; } // 4120decl
    bool operator!=(const Iter4120 &i) const { return node != i.node; } // 4120decl
};

struct Sub4120 { int *arr; };

struct Ent63C0 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    char pad10[0x28 - 0x10];
};

struct Sub63C0 {
    Ent63C0 *arr;
};

struct Obj63C0 {
    char pad0[0xD40];
    Sub63C0 sub;
};

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
    long m_unk20;
    long m_unk28;
    long m_unk30;
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

struct Ent5D1C {
    char pad0[0x14];
    int m_unk14;
    int m_unk18;
    char pad1C[0x28 - 0x1C];
};

struct Sub5D1C {
    Ent5D1C *arr;
};

struct Obj5D1C {
    char pad0[0xD40];
    Sub5D1C sub;
};

struct Big484C {
    int w[0xC4E0 / 4];
};

struct Obj484C {
    char pad[0x1544];
    Big484C *m_unk1544;
};

struct Big4790 {
    int w[0xE000 / 4];
};

struct Obj4790 {
    char pad[0x1540];
    Big4790 *m_unk1540;
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

struct Obj6D54 {
    void *m_unk00;
    int m_unk04;
    float m_unk08;
    void *m_unk0C;
};

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

struct Node70DC {
    int m_unk00;
    Node70DC *next;
};

struct Sub70DC {
    int m_unk00;
    ~Sub70DC() asm("func_00203DA8");
};

struct Obj70DC {
    Node70DC *head0;
    Node70DC *head4;
    char pad8[0x38];
    Sub70DC sub40;
    ~Obj70DC() asm("func_001E70DC");
};

struct Ent4C1C {
    char name[0x1C];
    int id;
    char pad[0x38 - 0x20];
};

struct Obj4C1C {
    char pad[0x1544];
    Ent4C1C *list;
};

struct Ent4970 {
    char name[0x1C];
    int m_unk1C;
    char pad[0x38 - 0x20];
};

struct Obj4970 {
    char pad[0x1540];
    Ent4970 *list;
};

struct Ent4D18 {
    char pad0[0xC];
    unsigned int m_unk0C;
    char pad10[0x8];
    int m_unk18;
    char pad1C[0x28 - 0x1C];
};

struct Obj4D18 {
    char pad0[0xD40];
    Ent4D18 *arr;
};

struct Obj7724 {
    char pad0[0x84];
    int arr[0x80];
    int *end;
};

struct Ent4AB8 {
    char name[0x1C];
    int id;
    char pad[0x38 - 0x20];
};

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

struct TskObj7618 {
    virtual int vfunc1(int);
};

struct TskNode7618 {
    TskObj7618 *obj;
    TskNode7618 *next;
    int state;
};

struct Entry4E { int a,b,c,d,e,f,g,h,i,j; };

struct Sub4E { Entry4E *arr; };

struct Obj4E { int first; char pad[0xD3C]; Sub4E sub; };

struct Ent649C {
    char pad0[4];
    int m_unk04;
    int m_unk08;
    unsigned int m_unk0C;
    char pad10[0x8];
    int m_unk18;
    char pad1C[0x28 - 0x1C];
};

struct Sub649C {
    char *m_begin;
};

struct Obj649C {
    char pad0[0xD40];
    Sub649C sub;
};

struct Msg6734 { int id, left, right, d, e, time, g, h, oldLeft, oldRight; char tail[0x18]; };

struct Bank6734 { char pad[0x1B04]; int left, right; };

struct ALIGNED(16) Vec6E00 { float x,y,z,w; };

struct Pan6E00 { Vec6E00 *a; Vec6E00 *b; float angle; Vec6E00 *src; };

class Virtual7A20 { public:
    virtual void X__vfunc_00();
    virtual void X__vfunc_01();
    virtual void X__vfunc_02();
    virtual int X__vfunc_03(int, int, int);
};

#endif
