#include "include_asm.h"
struct Iter12FBC {
    int *node;
    Iter12FBC() : node(0) {}
    Iter12FBC(int *n) : node(n) {}
    Iter12FBC(const Iter12FBC &rhs) : node(rhs.node) {}
    bool operator!=(const Iter12FBC &rhs) const { return node != rhs.node; }
    Iter12FBC &operator++() { node = (int *)node[1]; return *this; }
};
extern "C" int F113DC_check(int, unsigned int, int) asm("func_00213D00");
extern "C" int F113DC_alloc() asm("func_00214AC4");
extern "C" void F113DC_select(unsigned int) asm("func_00214310");
extern "C" void F113DC_load(int) asm("func_00214BCC");
extern "C" int F113DC_exec(int) asm("func_00214C24");
struct Block780_47E0;
struct State12A5C { int data[28]; Block780_47E0 *buffer; int rest[3]; } ALIGNED(8);
extern State12A5C F12A5C_state asm("D_007B4700");
extern int F12A5C_mode asm("D_007B4DC0");
extern "C" void F12A5C_run(int, unsigned int, int, int, int, int) asm("func_00211830");
extern "C" int F11BE4_check(int, unsigned int, int, unsigned int) asm("func_00213D00");
#ifdef NON_MATCHING

struct Data20F4FC { unsigned char b[0xB0]; };
struct List20F4FC {
    struct Node {
        Node *m_prev;
        Node *m_next;
        int pad[2];
        Data20F4FC m_data;
    } ALIGNED(16);
    struct Chain {
        Node m_head;
        int m_num;
        void push_back(Node *theNode)
        {
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
        void unlink(Node *theNode)
        {
            if (theNode == m_head.m_next) {
                Node *next = theNode->m_next;
                m_head.m_next = next;
                next->m_prev = &m_head;
            } else if (theNode == m_head.m_prev) {
                Node *p = theNode->m_prev;
                m_head.m_prev = p;
                p->m_next = &m_head;
            } else {
                Node *p = theNode->m_prev;
                p->m_next = theNode->m_next;
                Node *prev = theNode->m_prev;
                p = theNode->m_next;
                p->m_prev = prev;
            }
            --m_num;
        }
    };
    struct iterator {
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        Data20F4FC &operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    Chain m_free;
    Chain m_used;
    iterator begin() { return iterator(m_used.m_head.m_next); }
    iterator end() { return iterator(&m_used.m_head); }
    iterator erase(iterator thePos)
    {
        iterator next = thePos;
        ++next;
        Node *n = thePos.m_node;
        m_used.unlink(n);
        m_free.push_back(n);
        return next;
    }
};

struct Obj20F4FC { char pad[0x6200]; List20F4FC list; };
extern "C" void F4FC_start(void *) asm("func_001C4168");
extern "C" void F4FC_stop(void *) asm("func_001C43F0");
#endif
extern const char D_00301710[];
extern "C" int X_strncpy(...) asm("strncpy");
struct F11E_record { int data[44]; };
extern "C" char *F11E_strncpy(char *, const char *, unsigned int) asm("strncpy");
struct F14E_block { int data[0x151]; };
struct F14E_out { char data[0x544]; };
struct F14E_part { int data[16]; };
struct F150_block { char data[0x400]; };
struct F150_part { int data[16]; };
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int X_func_00214310(...) asm("func_00214310");
extern "C" int X_func_002144C4(...) asm("func_002144C4");
extern "C" int X_func_00214664(...) asm("func_00214664");
extern "C" int X_func_00214BCC(...) asm("func_00214BCC");
extern "C" int X_func_00214C24(...) asm("func_00214C24");
struct m2c_block16 { int w[4]; };
struct m2c_block32 { int w[8]; };
struct m2c_ulong { long v; } __attribute__((packed));
struct F788_block { char data[0xB0]; };
struct Block80_47E0 {
    unsigned char b[0x80];
};
struct Block780_47E0 {
    unsigned char b[0x780];
};
struct Inner47E0 {
    int flags;
    unsigned char unk04[0x28];
    Block80_47E0 unk2C;
    Block780_47E0 *unkAC;
};
struct Obj47E0 {
    unsigned char pad0000[0xDC24];
    int unkDC24;
    unsigned char padDC28[8];
    Inner47E0 unkDC30;
};
struct Global47E0_b {
    unsigned char unk00[0x70];
    Block780_47E0 *unk70;
    unsigned char unk74[0x0C];
};
extern int X47E0_D_007B4640 asm("D_007B4640");
extern Global47E0_b X47E0_D_007B4700 asm("D_007B4700");
extern "C" int func_002149A8();
struct Block80_4310 {
    unsigned char b[0x80];
};
struct Elem48_4310 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
extern Block80_4310 D_002D9C08[];
extern Elem48_4310 D_007B4850[];
extern int X4310_D_007B4700[32] asm("D_007B4700");
extern int D_007B47E0;
extern int D_007B47F0;
extern int D_007B4800;
extern int D_007B4820;
extern int D_007B4830;
struct Block80_44CC {
    unsigned char b[0x80];
};
struct Block780_44CC {
    unsigned char b[0x780];
};
struct Inner44CC {
    int flags;
    unsigned char unk04[0x28];
    Block80_44CC unk2C;
    Block780_44CC *unkAC;
};
struct Obj44CC {
    unsigned char pad[0xDCE0];
    Inner44CC *unkDCE0;
};
extern "C" void *X20F1FC_memset(void *, int, unsigned int) asm("memset");
struct Item20F1FC {
    unsigned int a;
    int b;
    int c;
    int d;
};
struct List20F1FC {
    struct Node {
        Node *m_prev;
        Node *m_next;
        Item20F1FC m_data;
    };
    struct Chain {
        Node m_head;
        int m_num;
        void push_back(Node *theNode)
        {
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
        void unlink(Node *theNode)
        {
            if (theNode == m_head.m_next) {
                Node *next = theNode->m_next;
                m_head.m_next = next;
                next->m_prev = &m_head;
            } else {
                Node *p = theNode->m_prev;
                if (theNode == m_head.m_prev) {
                    m_head.m_prev = p;
                    p->m_next = &m_head;
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
    struct iterator {
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        Item20F1FC &operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    Chain m_free;
    Chain m_used;
    iterator begin() { return iterator(m_used.m_head.m_next); }
    iterator end() { return iterator(&m_used.m_head); }
    iterator erase(iterator thePos)
    {
        iterator next = thePos;
        ++next;
        Node *n = thePos.m_node;
        m_used.unlink(n);
        m_free.push_back(n);
        return next;
    }
};
struct Obj20F1FC {
    unsigned char pad0000[0xC3C0];
    List20F1FC m_list;
    unsigned char padC3F8[0xDC1C - (0xC3C0 + sizeof(List20F1FC))];
    char *m_state;
    char *m_flags;
};
extern int D_007B4770;
struct Block80_4664 {
    unsigned char b[0x80];
};
struct Block780_4664 {
    unsigned char b[0x780];
};
struct Obj4640 {
    unsigned char unk00[0x10];
    int flags;
    unsigned char unk14[0x28];
    Block80_4664 unk3C;
    Block780_4664 *unkBC;
};
struct Block40_B8 {
    unsigned char b[0x40];
};
struct Block544 {
    unsigned char b[0x544];
};
struct State2152B8 {
    unsigned char pad[0x504];
    Block40_B8 lang[13];
};
struct Src2152B8 {
    unsigned char unk0[0x504];
    Block40_B8 unk504;
};
struct Obj2152B8 {
    unsigned char pad[0xDC1C];
    State2152B8 *m_state;
};
extern int D_007A3210;
struct Block360 {
    unsigned char b[0x360];
};
struct Block40 {
    unsigned char b[0x40];
};
struct Src215430 {
    Block360 unk0;
    Block40 unk360;
};
struct Obj215430 {
    unsigned char pad[0xDC20];
    unsigned char *m_flags;
};
extern "C" int X2D08_func_00213C6C(int arg0, int arg1, int arg2, int arg3) asm("func_00213C6C");
extern "C" int func_00213D90(int arg0, int arg1, int arg2);
struct Data212E64 {
    unsigned char b[0xB0];
};
struct List212E64 {
    struct Node {
        Node *m_prev;
        Node *m_next;
        int m_pad08;
        int m_pad0C;
        Data212E64 m_data;
    } ALIGNED(16);
    struct Chain {
        Node m_head;
        int m_num;
        Node *pop_back()
        {
            Node *n = m_head.m_prev;
            Node *prev = n->m_prev;
            m_head.m_prev = prev;
            prev->m_next = &m_head;
            --m_num;
            return n;
        }
        void push_back(Node *theNode)
        {
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
    };
    Chain m_free;
    Chain m_used;
    void push_back(const Data212E64 &theData)
    {
        Node *n = m_free.pop_back();
        n->m_data = theData;
        m_used.push_back(n);
    }
};
struct Obj212E64 {
    unsigned char pad[0x6200];
    List212E64 m_list;
};
struct Item2127F4 {
    unsigned int a;
    int b;
    int c;
    int d;
};
struct List2127F4 {
    struct Node {
        Node *m_prev;
        Node *m_next;
        Item2127F4 m_data;
    };
    struct Chain {
        Node m_head;
        int m_num;
        void push_back(Node *theNode)
        {
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
        void unlink(Node *theNode)
        {
            if (theNode == m_head.m_next) {
                Node *next = theNode->m_next;
                m_head.m_next = next;
                next->m_prev = &m_head;
            } else {
                Node *p = theNode->m_prev;
                if (theNode == m_head.m_prev) {
                    m_head.m_prev = p;
                    p->m_next = &m_head;
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
    struct iterator {
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        Item2127F4 &operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    Chain m_free;
    Chain m_used;
    iterator begin() { return iterator(m_used.m_head.m_next); }
    iterator end() { return iterator(&m_used.m_head); }
    iterator erase(iterator thePos)
    {
        iterator next = thePos;
        ++next;
        Node *n = thePos.m_node;
        m_used.unlink(n);
        m_free.push_back(n);
        return next;
    }
};
struct Obj2127F4 {
    unsigned char pad[0xC3C0];
    List2127F4 m_list;
};
struct Block30000_1 { char b[0x30000]; };
struct Elem214AC4 {
    unsigned char b[0x80];
};
extern Elem214AC4 D_007B4920[];
extern "C" void func_00211E84(int, int, int);
extern "C" void func_00213F48(int, int, int);
struct Block18000_1 { char b[0x18000]; };
extern "C" int func_00213B7C(int arg0, int arg1, int arg2, int arg3, int arg4);
struct NodeIter3D90 {
    int *m_node;
    NodeIter3D90() {}
    NodeIter3D90(const NodeIter3D90 &other) : m_node(other.m_node) {}
};
static inline int checkRange3D90(int arg0, int arg1, char *p, NodeIter3D90 *beg, NodeIter3D90 *end, int arg2) {
    beg->m_node = *(int **)(p + 0xD4);
    end->m_node = (int *)(p + 0xD0);
    return func_00213B7C(arg0, arg1, (int)beg, (int)end, arg2);
}
extern "C" int func_001E0C2C(void *, int, int, int);
extern "C" void func_001C6A40(void *, int);
extern "C" void func_00214A94(int arg0);
extern "C" void *Xv_memset(void *, int, unsigned int) asm("memset");
struct GamMan20F428 {
    unsigned char pad[0x40];
    unsigned char m_trg[1];
    unsigned char *getTrg() { return m_trg; }
};
extern GamMan20F428 D_007812C0;
struct NodeIter3E78 {
    int *m_node;
    NodeIter3E78() {}
    NodeIter3E78(const NodeIter3E78 &other) : m_node(other.m_node) {}
};
extern "C" int func_00213BFC(int arg0, int arg1, int arg2, int arg3);
static inline int checkRange3E78(int arg0, int arg1, char *p, NodeIter3E78 *beg, NodeIter3E78 *end) {
    beg->m_node = *(int **)(p + 0xD4);
    end->m_node = (int *)(p + 0xD0);
    return func_00213BFC(arg0, arg1, (int)beg, (int)end);
}
extern "C" void func_002120AC(int, int, int, int, int, int, const char *);
struct RevIter2129B8 {
    int *m_node;
    RevIter2129B8() : m_node(0) {}
    RevIter2129B8(int *n) : m_node(n) {}
    RevIter2129B8(const RevIter2129B8 &other) : m_node(other.m_node) {}
    bool operator!=(const RevIter2129B8 &rhs) const { return m_node != rhs.m_node; }
    RevIter2129B8 &operator--() {
        m_node = (int *)m_node[1];
        return *this;
    }
};
struct NodeItem212920 {
    int a;
    int b;
    int c;
    int d;
};
struct Node212920 {
    Node212920 *next;
    Node212920 *prev;
    NodeItem212920 item;
};
struct List212920 {
    Node212920 *head;
    Node212920 *tail;
    int pad[4];
    int count;
};
extern "C" void func_002127F4(int arg0);
extern "C" void func_00213450(int arg0, int arg1, int arg2);
// A one-pointer iterator class with a copy constructor: BLKmode, so a local
// keeps its 16-byte stack slot (like GamList<T>::iterator in gamman.h).
struct NodeIter {
    int *m_node;
    NodeIter() {}
    NodeIter(const NodeIter &other) : m_node(other.m_node) {}
};
// gas 2.10-ee's macro expansion for `li`, `dsll $r,$r,32` and `la $r,K($r)`
// leaves its $at bookkeeping dirty: a later `lw $r, sym($reg)` or
// `s.s $f, sym($reg)` then loses its `lui $at`. The assembler directives
// INCLUDE_ASM wraps its .s files in (with reorder off and on) reset it.
#define RESET_AT_STATE asm(".set noat\n.set noreorder\n.set reorder\n.set at\n")
extern "C" int strcmp(const char *, const char *);
extern "C" int Xii___builtin_delete(int) asm("__builtin_delete");
extern "C" int Xii___builtin_vec_delete(int) asm("__builtin_vec_delete");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern int D_002D9950;
extern int D_007B4790;
extern int D_007B4D20;
extern int D_007B4D30;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_002155A8(...) asm("func_002155A8");
extern "C" int X_memset(...) asm("memset");
extern int D_002D90F8;
extern int D_007B4640;
extern int D_007B4650;
extern int D_007B4680;
extern int D_007B4700;
extern int D_007B477C;
extern int D_007B4780;
extern int D_007B47A0;
extern int D_007B47B0;
extern int D_007B47C0;
extern int D_007B47D0;
extern int D_007B4810;
extern int D_007B4840;
extern int D_007B4DB0;
extern int D_007B4DD0;

extern "C" void func_0020ED9C(void) {
}

extern "C" void func_0020EDA4(int arg0, int arg1)
{
    int src = arg1;
    int dst = *(int *)(arg0 + 4);
    *(Block18000_1 *)dst = *(Block18000_1 *)src;
    func_00213F48(arg0, *(int *)(arg0 + 4), 1);
    func_00211E84(arg0, 0x44000000, D_007B47D0 - 0xA4);
}

// NON_MATCHING: 28/61 differ, 3 relocs differ (size 0xF4, game 0xFC), 14 edits
#ifdef NON_MATCHING
extern "C" int Xiiii_func_00211E84(int, int, int) asm("func_00211E84");
extern "C" int Xiiii_func_00213F48(int, int, int) asm("func_00213F48");
struct Block32_4 { int w[8]; };
struct Block32_8 { int w[8]; } ALIGNED(8);
extern "C" void func_0020EEA8(int arg0, int arg1)
{
    int src = arg1;
    int dst = *(int *)arg0;
    if ((src | dst) & 7) {
        int end = src + 0x20000;
        do {
            *(Block32_4 *)dst = *(Block32_4 *)src;
            src += 0x20;
            dst += 0x20;
        } while (src != end);
    } else {
        int end = src + 0x20000;
        do {
            *(Block32_8 *)dst = *(Block32_8 *)src;
            src += 0x20;
            dst += 0x20;
        } while (src != end);
    }
    Xiiii_func_00213F48(arg0, *(int *)arg0, 0);
    Xiiii_func_00211E84(arg0, 0x04000000, D_007B47D0 - 0xA4);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020EEA8);
#endif

extern "C" void func_0020EFA4(void) {
}

extern "C" void func_0020EFAC(int arg0, int arg1, int arg2)
{
    switch (arg1) {
    case 1:
        break;
    case 2:
        *(Block30000_1 *)*(int *)(arg0 + 8) = *(Block30000_1 *)arg2;
        func_00213F48(arg0, *(int *)(arg0 + 8), 2);
        func_00211E84(arg0, 0x84000000, D_007B47D0 - 0xA4);
        break;
    }
}

extern "C" void func_0020F0C8(int arg0, int arg1)
{
    switch (arg1) {
    case 1:
        func_002127F4(arg0);
        func_00213450(arg0, 1, 0);
        return func_00213450(arg0, 2, 0);
    case 2:
        return func_00213450(arg0, arg1, 0);
    }
}

extern "C" int func_0020F140(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0xDC24) & 0x100) {
        return M2C_FIELD(arg0, int *, 0xDC58);
    }
    return M2C_FIELD((*(int *)&D_007B4640), int *, 0x38);
}

extern "C" int func_0020F174(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0xDC24) & 0x100) {
        return M2C_FIELD(arg0, int *, 0xDC34);
    }
    return M2C_FIELD((*(int *)&D_007B4640), int *, 0x14);
}

extern "C" void func_0020F1A8(int arg0)
{
    X_memset((*(int *)(int *)((char *)(arg0) + 0xDC1C)), 0, 0x800);
    X_memset((*(int *)(int *)((char *)(arg0) + 0xDC20)) + 4, 0, 0x7FC);
}


extern "C" void func_0020F1FC(Obj20F1FC *arg0)
{
    X20F1FC_memset(arg0->m_state + 0x300, 0, 0x200);
    X20F1FC_memset(arg0->m_flags + 0x20, 0, 0x200);
    List20F1FC::iterator it;
    List20F1FC::iterator end;
    it = arg0->m_list.begin();
    end = arg0->m_list.end();
    for (; it != end; ++it) {
        if (((*it).a >> 30) == 1) {
            it = arg0->m_list.erase(it);
        }
    }
}

extern "C" void func_0020F37C(int arg0)
{
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;

    temp_s0 = M2C_FIELD(arg0, int *, 0x10);
    if (temp_s0 != 0) {
        temp_a0 = M2C_FIELD(temp_s0, int *, 0x1C0);
        if (temp_a0 != 0) {
            Xii___builtin_vec_delete(temp_a0);
        }
        Xii___builtin_delete(temp_s0);
    }
    temp_s0_2 = M2C_FIELD(arg0, int *, 0x14);
    if (temp_s0_2 != 0) {
        temp_a0_2 = M2C_FIELD(temp_s0_2, int *, 0x1C0);
        if (temp_a0_2 != 0) {
            Xii___builtin_vec_delete(temp_a0_2);
        }
        Xii___builtin_delete(temp_s0_2);
    }
    temp_s0_3 = M2C_FIELD(arg0, int *, 0x18);
    if (temp_s0_3 != 0) {
        temp_a0_3 = M2C_FIELD(temp_s0_3, int *, 0x1C0);
        if (temp_a0_3 != 0) {
            Xii___builtin_vec_delete(temp_a0_3);
        }
        Xii___builtin_delete(temp_s0_3);
    }
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
}

extern "C" void func_0020F428(int arg0, char *arg1)
{
    int temp_v0 = *(int *)(arg1 + 0x20);
    if (temp_v0 != 0) {
        unsigned char *trg = D_007812C0.getTrg();
        func_001E0C2C(trg, 2, temp_v0, 0x02000000);
        if (func_001E0C2C(trg, 4, *(int *)(arg1 + 0x20), 0x10) != 0) {
            func_001E0C2C(trg, 3, *(int *)(arg1 + 0x20), 0x10000000);
        }
        func_001E0C2C(trg, 5, *(int *)(arg1 + 0x20), 0);
    }
    if (*(int *)arg1 & 0x40) {
        func_001C6A40(&D_007812C0, 0x8000);
    }
    int temp_a0 = *(int *)(arg1 + 0xAC);
    if (temp_a0 != 0) {
        func_00214A94(temp_a0);
        *(int *)(arg1 + 0xAC) = 0;
    }
    Xv_memset(arg1, 0, 0xB0);
}

// NON_MATCHING: 84/145 differ, 1 reloc differs (size 0x244, game 0x28C), 62 edits
#ifdef NON_MATCHING
extern "C" void func_0020F4FC(Obj20F4FC *self)
{

    List20F4FC::iterator it;
    List20F4FC::iterator end;
    List20F4FC::iterator found;
    it = self->list.begin();
    end = self->list.end();
    for (; it != end; ++it) {
        unsigned int id = *(unsigned int *)((*it).b + 4);
        int kind = id >> 30;
        if (X2D08_func_00213C6C((int)self, id, (int)&found, *(int *)((*it).b + 0x28))) {
            if (*(unsigned int *)((*it).b + 4) == 0x44000000) F4FC_start(&D_007812C0);
            if (*(unsigned int *)((*it).b + 4) == 0x84000000) F4FC_stop(&D_007812C0);
            switch (kind) {
            case 0: ((List20F4FC *)*(int *)((char *)self + 0x10))->erase(found); break;
            case 1: ((List20F4FC *)*(int *)((char *)self + 0x14))->erase(found); break;
            case 2: ((List20F4FC *)*(int *)((char *)self + 0x18))->erase(found); break;
            }
            func_0020F428((int)self, (char *)&*found);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F4FC);
#endif

extern "C" void func_0020F788(int arg0)
{
    int temp_v0_2;
    int temp_v1;
    int temp_a2;
    int temp_a3;
    int temp_a4;
    int temp_v0;
    int temp_v0_3;
    int temp_v1_2;
    int var_a0;
    int var_a1;

    X_func_00214310((*(int *)((int)&D_007B4DD0)));
    if ((*(int *)&D_007B4640) != (*(int *)((int)&D_007B4650))) {
        do {
            X_func_00214664(arg0);
            int *flags = (int *)((*(int *)&D_007B4640) + 0x10);
            temp_v1 = *flags;
            if (temp_v1 & 0x80) {
                *flags = temp_v1 & ~0x80;
                X_func_00214BCC(M2C_FIELD((*(int *)&D_007B4640), int *, 0x1C));
            }
            temp_v0_2 = X_func_00214C24(M2C_FIELD((*(int *)&D_007B4640), int *, 0x18));
            if (temp_v0_2 != 0) {
                M2C_FIELD((*(int *)&D_007B4640), int *, 0x18) = temp_v0_2;
            } else {
                temp_a3 = arg0 + 0x6200;
                var_a0 = (*(int *)&D_007B4640) + 0x10;
                temp_a2 = M2C_FIELD(arg0, int *, 0x6200);
                temp_a4 = (*(int *)&D_007B4640) + 0xB0;
                temp_v0_3 = M2C_FIELD(temp_a2, int *, 0);
                var_a1 = temp_a2 + 0x10;
                M2C_FIELD(arg0, int *, 0x6200) = temp_v0_3;
                M2C_FIELD(temp_v0_3, int *, 4) = temp_a3;
                M2C_FIELD(temp_a3, int *, 0xC0) = (int) (M2C_FIELD(temp_a3, int *, 0xC0) - 1);
                *(F788_block *)var_a1 = *(F788_block *)var_a0;
                temp_v1_2 = temp_a3 + 0xD0;
                if (M2C_FIELD(temp_v1_2, int *, 0xC0) == 0) {
                    M2C_FIELD(temp_v1_2, int *, 4) = temp_a2;
                    M2C_FIELD(temp_a2, int *, 0) = temp_v1_2;
                } else {
                    M2C_FIELD(M2C_FIELD(temp_v1_2, int *, 0), int *, 4) = temp_a2;
                    M2C_FIELD(temp_a2, int *, 0) = M2C_FIELD(temp_v1_2, int *, 0);
                }
                M2C_FIELD(temp_a2, int *, 4) = temp_v1_2;
                M2C_FIELD(temp_v1_2, int *, 0) = temp_a2;
                M2C_FIELD(temp_v1_2, int *, 0xC0) = (int) (M2C_FIELD(temp_v1_2, int *, 0xC0) + 1);
            }
            temp_v0 = M2C_FIELD((*(int *)&D_007B4640), int *, 4);
            (*(int *)&D_007B4640) = temp_v0;
        } while (temp_v0 != (*(int *)((int)&D_007B4650)));
    }
    X_func_002144C4((*(int *)((int)&D_007B4DD0)));
}

// NON_MATCHING: 342/360 differ, 16 relocs differ (size 0x5A0, game 0x5A8), 6 edits
#ifdef NON_MATCHING
extern "C" void F98C_cleanup(int) asm("func_0020F4FC");
extern "C" void F98C_finish(void *) asm("func_001CD25C");
extern "C" void func_0020F98C(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0xDC24) & 1) return;
    {
        List212E64 *pending = (List212E64 *)(arg0 + 0x6200);
        List212E64 *active = (List212E64 *)(arg0 + 0x40);
        if (pending->m_used.m_num != 0) {
            F98C_cleanup(arg0);
            if (pending->m_used.m_num != 0) {
                List212E64::Chain *used = (List212E64::Chain *)(arg0 + 0x62D0);
                if (used->m_num != 0) {
                    pending->m_free.m_head.m_prev->m_next = used->m_head.m_next;
                    List212E64::Node *p = pending->m_free.m_head.m_prev;
                    p->m_next->m_prev = p;
                    List212E64::Node *last = used->m_head.m_prev;
                    pending->m_free.m_head.m_prev = last;
                    last->m_next = &pending->m_free.m_head;
                    pending->m_free.m_num += used->m_num;
                    used->m_num = 0;
                    used->m_head.m_prev = &used->m_head;
                    used->m_head.m_next = &used->m_head;
                    active = (List212E64 *)(arg0 + 0x40);
                }
            }
        }
        if (active->m_used.m_num != 0) {
            List212E64::Chain *used = (List212E64::Chain *)(arg0 + 0x110);
            Iter12FBC it;
            Iter12FBC end;
            it = Iter12FBC((int *)active->m_used.m_head.m_next);
            end = Iter12FBC((int *)used);
            for (; it != end; ++it) {
                Data212E64 *data = (Data212E64 *)((char *)it.node + 0x10);
                int kind = *(unsigned int *)(data->b + 4) >> 30;
                switch (kind) {
                case 0: ((List212E64 *)M2C_FIELD(arg0, int *, 0x10))->push_back(*data); break;
                case 1: ((List212E64 *)M2C_FIELD(arg0, int *, 0x14))->push_back(*data); break;
                case 2: ((List212E64 *)M2C_FIELD(arg0, int *, 0x18))->push_back(*data); break;
                }
                int id = it.node[12];
                if (id) func_001E0C2C(D_007812C0.getTrg(), 3, id, 0x02000000);
            }
            if (active->m_used.m_num != 0 && used->m_num != 0) {
                active->m_free.m_head.m_prev->m_next = used->m_head.m_next;
                List212E64::Node *p = active->m_free.m_head.m_prev;
                p->m_next->m_prev = p;
                List212E64::Node *last = used->m_head.m_prev;
                active->m_free.m_head.m_prev = last;
                last->m_next = &active->m_free.m_head;
                active->m_free.m_num += used->m_num;
                used->m_num = 0;
                used->m_head.m_prev = &used->m_head;
                used->m_head.m_next = &used->m_head;
            }
        }
        D_007B4DD0 = 0;
        if (M2C_FIELD(M2C_FIELD(arg0, int *, 16), int *, 0x190) != 0) {
            D_007B4640 = M2C_FIELD(M2C_FIELD(arg0, int *, 16), int *, 0xD4);
            D_007B4650 = M2C_FIELD(arg0, int *, 16) + 0xD0;
            Iter12FBC temp((int *)D_007B4650);
            func_0020F788(arg0);
        }
        D_007B4DD0 = 1;
        if (M2C_FIELD(M2C_FIELD(arg0, int *, 20), int *, 0x190) != 0) {
            D_007B4640 = M2C_FIELD(M2C_FIELD(arg0, int *, 20), int *, 0xD4);
            D_007B4650 = M2C_FIELD(arg0, int *, 20) + 0xD0;
            Iter12FBC temp((int *)D_007B4650);
            func_0020F788(arg0);
        }
        D_007B4DD0 = 2;
        if (M2C_FIELD(M2C_FIELD(arg0, int *, 24), int *, 0x190) != 0) {
            D_007B4640 = M2C_FIELD(M2C_FIELD(arg0, int *, 24), int *, 0xD4);
            D_007B4650 = M2C_FIELD(arg0, int *, 24) + 0xD0;
            Iter12FBC temp((int *)D_007B4650);
            func_0020F788(arg0);
        }
        D_007B4DD0 = 0;
        F98C_finish(&D_007812C0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F98C);
#endif

extern "C" void func_0020FF34(void) {
}

extern "C" void func_0020FF3C(int arg0, int arg1, int arg2)
{
    if (arg1 == 0) {
        ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0];
        return;
    }
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] + ((int *)&D_007B4700)[arg1];
}

extern "C" void func_0020FF8C(int arg0, int arg1, int arg2)
{
    if (arg1 == 0) {
        ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0];
        return;
    }
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] + ((int *)&D_007B4700)[arg1];
}

// unk/0020ED9C, func_0020FFDC: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_0020FFDC(unsigned int arg0, unsigned int arg1, int arg2)
{
    if (arg0 == 0) {
        ((int *)&D_007B4700)[arg1] = (short) arg2;
    } else {
        ((int *)&D_007B4700)[arg1] = ((int *)&D_007B4700)[arg0] + (short) arg2;
    }
};

// unk/0020ED9C, func_00210024: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00210024(unsigned int arg0, unsigned int arg1, int arg2)
{
    if (arg0 == 0) {
        ((int *)&D_007B4700)[arg1] = (short) arg2;
    } else {
        ((int *)&D_007B4700)[arg1] = ((int *)&D_007B4700)[arg0] + (short) arg2;
    }
};

extern "C" void func_0021006C(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] & ((int *)&D_007B4700)[arg1];
}

extern "C" void func_002100A0(unsigned int arg0, unsigned int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg1] = ((int *)&D_007B4700)[arg0] & arg2;
}

extern "C" void func_002100C8(int arg0, int arg1)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = ((int *)&D_007B4700)[arg0];
    temp_v1 = ((int *)&D_007B4700)[arg1];
    (*(int *)&D_007B47A0) = temp_v0 / temp_v1;
    (*(int *)&D_007B4790) = temp_v0 % temp_v1;
}

extern "C" void func_00210110(int arg0, int arg1)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = ((int *)&D_007B4700)[arg0];
    temp_v1 = ((int *)&D_007B4700)[arg1];
    (*(int *)&D_007B47A0) = temp_v0 / temp_v1;
    (*(int *)&D_007B4790) = temp_v0 % temp_v1;
}

extern "C" void func_00210158(unsigned int arg0, unsigned int arg1)
{
    unsigned long long p = (unsigned long long)((unsigned int *)&D_007B4700)[arg0] * ((unsigned int *)&D_007B4700)[arg1];

    (*(int *)&D_007B47A0) = (int)p;
    (*(int *)&D_007B4790) = (int)(p >> 32);
}

extern "C" void func_002101B4(int arg0, int arg1)
{
    long long p = (long long)(unsigned int)((int *)&D_007B4700)[arg0] * (unsigned int)((int *)&D_007B4700)[arg1];

    (*(int *)&D_007B47A0) = (int)p;
    (*(int *)&D_007B4790) = (int)(p >> 32);
}

RESET_AT_STATE;

extern "C" void func_00210210(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ~(((int *)&D_007B4700)[arg0] | ((int *)&D_007B4700)[arg1]);
}

extern "C" void func_00210244(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] | ((int *)&D_007B4700)[arg1];
}

// unk/0020ED9C, func_00210278: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00210278(unsigned int arg0, unsigned int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg1] = ((int *)&D_007B4700)[arg0] | arg2;
};

extern "C" void func_002102A0(int arg0, int arg1, int arg2, int arg3)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg1] << arg3;
}

extern "C" void func_002102C8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg1] << ((int *)&D_007B4700)[arg0];
}

extern "C" void func_002102FC(int arg0, int arg1, int arg2, int arg3)
{
    ((int *)&D_007B4700)[arg2] = (int) ((int *)&D_007B4700)[arg1] >> arg3;
}

extern "C" void func_00210324(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = (int) ((int *)&D_007B4700)[arg1] >> ((int *)&D_007B4700)[arg0];
}

extern "C" void func_00210358(int arg0, int arg1, int arg2, int arg3)
{
    ((int *)&D_007B4700)[arg2] = (int) ((unsigned int) ((int *)&D_007B4700)[arg1] >> arg3);
}

extern "C" void func_00210380(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = (int) ((unsigned int) ((int *)&D_007B4700)[arg1] >> ((int *)&D_007B4700)[arg0]);
}

extern "C" void func_002103B4(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] - ((int *)&D_007B4700)[arg1];
}

extern "C" void func_002103E8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] - ((int *)&D_007B4700)[arg1];
}

extern "C" void func_0021041C(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((int *)&D_007B4700)[arg0] ^ ((int *)&D_007B4700)[arg1];
}

extern "C" void func_00210450(unsigned int arg0, unsigned int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg1] = ((int *)&D_007B4700)[arg0] ^ arg2;
}

extern "C" void func_00210478(int arg0, unsigned int arg1, unsigned int arg2)
{
    if (arg2 == 0x45 || arg2 == 0x41) {
        ((int *)&D_007B4700)[arg1] = (*(int *)&D_007B4810);
    } else if (arg2 == 0x46 || arg2 == 0x42) {
        ((int *)&D_007B4700)[arg1] = (*(int *)&D_007B4810) + 0x10000;
    } else {
        ((int *)&D_007B4700)[arg1] = arg2 << 0x10;
    }
}

// unk/0020ED9C, func_002104EC: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_002104EC(unsigned int arg0, unsigned int arg1, unsigned int arg2)
{
    if (((int *)&D_007B4700)[arg0] < ((int *)&D_007B4700)[arg1]) {
        ((int *)&D_007B4700)[arg2] = 1;
    } else {
        ((int *)&D_007B4700)[arg2] = 0;
    }
};

// unk/0020ED9C, func_00210534: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00210534(unsigned int arg0, unsigned int arg1, short arg2)
{
    if (((int *)&D_007B4700)[arg0] < arg2) {
        ((int *)&D_007B4700)[arg1] = 1;
    } else {
        ((int *)&D_007B4700)[arg1] = 0;
    }
};

// unk/0020ED9C, func_00210578: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00210578(unsigned int arg0, unsigned int arg1, unsigned int arg2)
{
    if (((unsigned int *)&D_007B4700)[arg0] < ((unsigned int *)&D_007B4700)[arg1]) {
        ((unsigned int *)&D_007B4700)[arg2] = 1;
    } else {
        ((unsigned int *)&D_007B4700)[arg2] = 0;
    }
};

// unk/0020ED9C, func_002105C0: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_002105C0(unsigned int arg0, unsigned int arg1, unsigned int arg2)
{
    if (((unsigned int *)&D_007B4700)[arg0] < arg2) {
        ((unsigned int *)&D_007B4700)[arg1] = 1;
    } else {
        ((unsigned int *)&D_007B4700)[arg1] = 0;
    }
};

extern "C" void func_002105FC(unsigned int arg0, unsigned int arg1, int arg2)
{
    if (arg0 == 0) {
        (*(int *)&D_007B47C0) = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;
        return;
    }
    if (((int *)&D_007B4700)[arg0] == ((int *)&D_007B4700)[arg1]) {
        (*(int *)&D_007B47C0) = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;
    }
}

extern "C" void func_002106A0(unsigned int arg0, int arg1, unsigned int arg2)
{
    if (((int *)&D_007B4700)[arg0] > 0) {
        (*(int *)&D_007B47C0) = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;
    }
}

extern "C" void func_002106F4(unsigned int arg0, int arg1, unsigned int arg2)
{
    if (((int *)&D_007B4700)[arg0] <= 0) {
        (*(int *)&D_007B47C0) = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;
    }
}

extern "C" void func_00210748(unsigned int arg0, unsigned int arg1, int arg2)
{
    int v = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;

    if (((int *)&D_007B4700)[arg0] != ((int *)&D_007B4700)[arg1]) {
        (*(int *)&D_007B47C0) = v;
    }
}

RESET_AT_STATE;

// NON_MATCHING: 6/32 differ, 1 reloc differs, 4 edits
#ifdef NON_MATCHING
extern "C" void func_002107AC(unsigned int arg0, unsigned int arg1, int arg2)
{
    if (arg1 != 1) {
        if ((arg1 == 0) && (((int *)&D_007B4700)[arg0] < 0)) {
            (*(int *)&D_007B47C0) = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;
        }
    } else if (((int *)&D_007B4700)[arg0] >= 0) {
        (*(int *)&D_007B47C0) = ((short) (arg2 * 4) + ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8164) | 0x80000000;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002107AC);
#endif

extern "C" void func_0021082C(int arg0, int arg1, int arg2, int arg3)
{
    D_007B47C0 = ((arg3 & 0x03FFFFFF) * 4) | (D_007B4780 & 0xF8000000) | 0x80000000;
}


extern "C" void func_00210864(int arg0, int arg1, unsigned int arg2)
{
    int v = ((arg2 * 4) & 0x03FFFFFF) | ((*(int *)&D_007B4780) & 0xF0000000) | 0x80000000;

    (*(int *)&D_007B477C) = ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8168;
    (*(int *)&D_007B47C0) = v;
}

extern "C" void func_002108B8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = ((*(int *)&D_007B4780) - (*(int *)&D_007B47D0)) + 0x8168;
    (*(int *)&D_007B47C0) = ((int *)&D_007B4700)[arg0] | 0x80000000;
}

extern "C" void func_00210908(int arg0)
{
    (*(int *)&D_007B47C0) = ((int *)&D_007B4700)[arg0] | 0x80000000;
}

extern "C" void func_0021092C(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + ((int) (arg2 << 0x10) >> 0xE));
}

extern "C" void func_00210960(unsigned int arg0, unsigned int arg1, short arg2)
{
    int temp_v1;

    temp_v1 = ((int *)&D_007B4700)[arg0];
    ((int *)&D_007B4700)[arg1] = (*(int *)(temp_v1 + arg2) << 8) | (temp_v1 & 0xFF);
}

extern "C" void func_002109A0(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + arg2);
}

extern "C" void func_002109D4(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + ((int) (arg2 << 0x10) >> 0xE));
}

extern "C" void func_00210A08(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + arg2);
}

extern "C" void func_00210A3C(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + arg2);
}

extern "C" void func_00210A70(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((int *)&D_007B4700)[arg1] = *(int *)(((int *)&D_007B4700)[arg0] + arg2);
}

extern "C" void func_00210AA4(unsigned int arg0, unsigned int arg1, short arg2)
{
    *(int *)(((int *)&D_007B4700)[arg0] + arg2) = ((int *)&D_007B4700)[arg1];
}

extern "C" void func_00210AD8(unsigned int arg0, unsigned int arg1, short arg2)
{
    *(int *)(((int *)&D_007B4700)[arg0] + arg2) = ((int *)&D_007B4700)[arg1];
}

extern "C" void func_00210B0C(unsigned int arg0, unsigned int arg1, short arg2)
{
    int temp_a0;

    temp_a0 = ((int *)&D_007B4700)[arg0] + arg2;
    (*(int *)(temp_a0)) = ((unsigned int) ((int *)&D_007B4700)[arg1] >> 8) | ((*(int *)(temp_a0)) & 0xFF000000);
}

extern "C" void func_00210B54(unsigned int arg0, unsigned int arg1, short arg2)
{
    char *p = (char *)(((int *)&D_007B4700)[arg0] + arg2);

    p++;
    *(int *)p = (((int *)&D_007B4700)[arg1] << 0x18) | (*(int *)p & 0xFFFFFF);
}

RESET_AT_STATE;

extern "C" void func_00210BA4(unsigned int arg0, unsigned int arg1, short arg2)
{
    *(int *)(((int *)&D_007B4700)[arg0] + arg2) = ((int *)&D_007B4700)[arg1];
}

extern "C" void func_00210BD8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = (*(int *)&D_007B4790);
}

extern "C" void func_00210BF8(int arg0, int arg1, int arg2)
{
    ((int *)&D_007B4700)[arg2] = (*(int *)&D_007B47A0);
}

extern "C" void func_00210C18(int arg0, int arg1, int arg2)
{
    (*(int *)&D_007B4790) = ((int *)&D_007B4700)[arg2];
}

extern "C" void func_00210C34(int arg0, int arg1, int arg2)
{
    (*(int *)&D_007B47A0) = ((int *)&D_007B4700)[arg2];
}

extern "C" void func_00210C50(void) {
}

extern "C" void func_00210C58(void) {
}

extern "C" void func_00210C60(void) {
}

// unk/0020ED9C, func_00210C68: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00210C68(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((float *)&D_007B4680)[arg1] = *(float *)(((int *)&D_007B4700)[arg0] + arg2);
};

extern "C" void func_00210CA0(void) {
}

extern "C" void func_00210CA8(void) {
}

extern "C" void func_00210CB0(void) {
}

extern "C" void func_00210CB8(unsigned int arg0, unsigned int arg1, short arg2)
{
    *(int *)(((int *)&D_007B4700)[arg0] + arg2) = ((int *)&D_007B4680)[arg1];
}

extern "C" void func_00210CEC(void) {
}

extern "C" void func_00210CF4(void) {
}

// unk/0020ED9C, func_00210CFC: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00210CFC(unsigned int arg0, unsigned int arg1, short arg2)
{
    ((float *)&D_007B4680)[arg1] = *(float *)(((int *)&D_007B4700)[arg0] + arg2);
};

extern "C" void func_00210D34(void) {
}

// NON_MATCHING: 6/96 differ, 6 edits
#ifdef NON_MATCHING
typedef void (*Cop1Func210D3C)(unsigned int, unsigned int, unsigned int, unsigned int);
extern Cop1Func210D3C D_002D9B08[];
extern "C" void func_00210D3C(int arg0, int arg1, int arg2, unsigned int arg3)
{
    if ((arg3 & 0xFE000000U) == 0x46000000U) {
        unsigned int fmt = (arg3 >> 21) & 0xF;
        unsigned int ft = (arg3 >> 16) & 0x1F;
        unsigned int fs = (arg3 >> 11) & 0x1F;
        unsigned int fd = (arg3 >> 6) & 0x1F;
        D_002D9B08[arg3 & 0x3F](fs, ft, fd, fmt);
        return;
    }
    switch (arg3 & 0xFFE00000U) {
    case 0x44000000U:
        *(int *)((char *)&D_007B4700 + ((arg3 >> 14) & 0x7C)) = *(int *)((char *)&D_007B4680 + ((arg3 >> 9) & 0x7C));
        return;
    case 0x44800000U:
        *(int *)((char *)&D_007B4680 + ((arg3 >> 9) & 0x7C)) = *(int *)((char *)&D_007B4700 + ((arg3 >> 14) & 0x7C));
        break;
    case 0x45000000U:
        if ((arg3 & 0x10000) == 0) {
            if (D_007B4840 == 0) {
                goto block_branch;
            }
            return;
        } else if (D_007B4840 != 0) {
block_branch:
            D_007B47C0 = ((short)(arg2 * 4) + (D_007B4780 - D_007B47D0) + 0x8164) | 0x80000000;
        }
        break;
    case 0x45800000U:
        D_007B47C0 = 0x80000000;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210D3C);
#endif

extern "C" void func_00210EBC(void) {
}

extern "C" void func_00210EC4(void) {
}

extern "C" void func_00210ECC(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg0] + ((float *)&D_007B4680)[arg1];
}

extern "C" void func_00210F00(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg0] - ((float *)&D_007B4680)[arg1];
}

extern "C" void func_00210F34(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg0] * ((float *)&D_007B4680)[arg1];
}

extern "C" void func_00210F68(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg0] / ((float *)&D_007B4680)[arg1];
}

// unk/0020ED9C, func_00210FA4: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00210FA4(int arg0, int arg1)
{
    D_007B4840 = ((float *)&D_007B4680)[arg0] < ((float *)&D_007B4680)[arg1];
};

// unk/0020ED9C, func_00210FE4: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00210FE4(int arg0, int arg1)
{
    D_007B4840 = ((float *)&D_007B4680)[arg0] == ((float *)&D_007B4680)[arg1];
};

// unk/0020ED9C, func_00211024: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00211024(int arg0, int arg1)
{
    D_007B4840 = ((float *)&D_007B4680)[arg0] <= ((float *)&D_007B4680)[arg1];
};

extern "C" void func_00211064(int arg0, int arg1, int arg2)
{
    float *dst = &((float *)&D_007B4680)[arg2];
    double d = ((float *)&D_007B4680)[arg1];
    if (d < 0.0) {
        d = -d;
    }
    *dst = d;
}

extern "C" void func_002110E4(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = ((float *)&D_007B4680)[arg1];
}

extern "C" void func_00211108(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = -((float *)&D_007B4680)[arg1];
}

extern "C" void func_00211130(int arg0, int arg1, int arg2)
{
    ((float *)&D_007B4680)[arg2] = (float) ((int *)&D_007B4680)[arg0];
}

extern "C" void func_00211158(void) {
}

extern "C" void func_00211160(void) {
}

extern "C" void func_00211168()
{
    D_007B4840 = 0;
}


extern "C" void func_00211174(void) {
}

// unk/0020ED9C, func_0021117C: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_0021117C(int arg0, int arg1)
{
    D_007B4840 = ((float *)&D_007B4680)[arg0] == ((float *)&D_007B4680)[arg1];
};

extern "C" void func_002111BC(void) {
}

extern "C" void func_002111C4(void) {
}

extern "C" void func_002111CC(void) {
}

extern "C" void func_002111D4(void) {
}

extern "C" void func_002111DC(void) {
}

extern "C" void func_002111E4()
{
    D_007B4840 = 0;
}


extern "C" void func_002111F0(void) {
}

extern "C" void func_002111F8(void) {
}

extern "C" void func_00211200(void) {
}

// unk/0020ED9C, func_00211208: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00211208(int arg0, int arg1)
{
    D_007B4840 = ((float *)&D_007B4680)[arg0] < ((float *)&D_007B4680)[arg1];
};

extern "C" void func_00211248(void) {
}

// unk/0020ED9C, func_00211250: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_00211250(int arg0, int arg1)
{
    D_007B4840 = ((float *)&D_007B4680)[arg0] <= ((float *)&D_007B4680)[arg1];
};

extern "C" void func_00211290(void) {
}

extern "C" void func_00211298(void) {
}

// unk/0020ED9C, func_002112A0: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_002112A0(int arg0, int arg1, int arg2)
{
    int v = (int)((float *)&D_007B4680)[arg1];
    ((float *)&D_007B4680)[arg2] = *(float *)&v;
};

// unk/0020ED9C, func_002112D8: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_002112D8(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    char *base = (char *)&D_007B4700;
    int x = *(int *)(base + ((arg3 >> 19) & 0x7C));
    int y = *(int *)(base + ((arg3 >> 14) & 0x7C));
    *(int *)(base + ((arg3 >> 9) & 0x7C)) = x * y;
};

extern "C" int func_00211318(int arg0, int arg1)
{
    int temp_a0 = (*(int *)&D_007B4640) + 0x10;
    int temp_v1 = M2C_FIELD(temp_a0, int *, 0x1C);
    if (temp_v1 == -1 || (M2C_FIELD(arg0, int *, 0xDC24) & 0x400)) {
        M2C_FIELD(arg0, int *, 0xDC24) &= ~0x400;
        M2C_FIELD((*(int *)&D_007B4640), int *, 0x2C) = arg1;
        return 1;
    } else {
        int temp_v0 = temp_v1 - 1;
        M2C_FIELD(temp_a0, int *, 0x1C) = temp_v0;
        if (temp_v0 == 0) {
            M2C_FIELD((*(int *)&D_007B4640), int *, 0x2C) = -1;
            return 0;
        }
        return 1;
    }
}

extern "C" void func_002113A4(int arg0, int arg1)
{
    (*(unsigned int *)&D_007B47B0) = (arg1 + (*(int *)&D_007B47D0)) - M2C_FIELD((((*(int *)((int)&D_007B4DD0)) * 4) + arg0), int *, 0xDC08);
}

extern "C" void func_002113DC(int arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, const char *arg7)
{
    State12A5C backup;
    unsigned int index = arg1 >> 30;
    int var_a3 = arg2 + D_007B4850[index].unk00 - M2C_FIELD(arg0 + index * 4, int *, 0xDC08);
    if (F113DC_check(arg0, arg1, arg3) != 0) return;
    backup = F12A5C_state;
    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
        var_a3 += 4;
        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
            var_a3 += 4;
            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 -= 0x1C;
                    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                        var_a3 += 4;
                        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                            var_a3 += 4;
                            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                                var_a3 += 4;
                                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                                    var_a3 += 4;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    M2C_FIELD(arg0, int *, 0xDC30) = arg4;
    M2C_FIELD(arg0, int *, 0xDC34) = arg1;
    M2C_FIELD(arg0, int *, 0xDC38) = var_a3;
    M2C_FIELD(arg0, int *, 0xDC4C) = -1;
    M2C_FIELD(arg0, int *, 0xDC50) = arg6;
    M2C_FIELD(arg0, int *, 0xDC54) = 1;
    M2C_FIELD(arg0, int *, 0xDC58) = arg3;
    M2C_FIELD(arg0, int *, 0xDCDC) = 0;
    F11E_strncpy((char *)(arg0 + 0xDC40), arg7, 8);
    if (arg5) M2C_FIELD(arg0, int *, 0xDC3C) = F113DC_alloc();
    F113DC_select(index);
    if (arg5) F113DC_load(M2C_FIELD(arg0, int *, 0xDC3C));
    M2C_FIELD(arg0, int *, 0xDC24) |= 0x100;
    register int result PS2_REG("$4");
    result = F113DC_exec(M2C_FIELD(arg0, int *, 0xDC38));
#ifdef TARGET_PS2
    asm("" : "+r"(result) : : "$7");
#endif
    int chain = arg0 + 0x40;
    if (result != 0) {
        M2C_FIELD(arg0, int *, 0xDC38) = result;
        result = arg0 + 0xDC30;
        int node = M2C_FIELD(chain, int *, 0);
        int prev = M2C_FIELD(node, int *, 0);
        M2C_FIELD(chain, int *, 0) = prev;
        M2C_FIELD(prev, int *, 4) = chain;
        --M2C_FIELD(chain, int *, 0xC0);
        *(F11E_record *)(node + 0x10) = *(F11E_record *)result;
        int used = chain + 0xD0;
        if (M2C_FIELD(used, int *, 0xC0) == 0) {
            M2C_FIELD(used, int *, 4) = node;
            M2C_FIELD(node, int *, 0) = used;
        } else {
            M2C_FIELD(M2C_FIELD(used, int *, 0), int *, 4) = node;
            M2C_FIELD(node, int *, 0) = M2C_FIELD(used, int *, 0);
        }
        M2C_FIELD(node, int *, 4) = used;
        M2C_FIELD(used, int *, 0) = node;
        ++M2C_FIELD(used, int *, 0xC0);
    } else {
        func_0020F428(arg0, (char *)(arg0 + 0xDC30));
    }
    M2C_FIELD(arg0, int *, 0xDC24) &= ~0x100;
    F113DC_select(D_007B4DD0);
    F12A5C_state = backup;
}

// NON_MATCHING: 3/237 differ, 3 edits
#ifdef NON_MATCHING
extern "C" int F11830_check(int, unsigned int, int) asm("func_00213D00");
extern "C" int F11830_alloc() asm("func_00214AC4");
extern "C" void F11830_select(unsigned int) asm("func_00214310");
extern "C" void F11830_load(int) asm("func_00214BCC");
extern "C" int F11830_exec(int) asm("func_00214C24");
extern "C" void func_00211830(int arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5)
{
    unsigned int index = arg1 >> 30;
    int var_a3 = arg2 + D_007B4850[index].unk00 - M2C_FIELD(arg0 + index * 4, int *, 0xDC08);
    if (F11830_check(arg0, arg1, arg3) != 0) return;
    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
        var_a3 += 4;
        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
            var_a3 += 4;
            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 -= 0x1C;
                    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                        var_a3 += 4;
                        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                            var_a3 += 4;
                            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                                var_a3 += 4;
                                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                                    var_a3 += 4;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    M2C_FIELD(arg0, int *, 0xDC30) = arg4;
    M2C_FIELD(arg0, int *, 0xDC34) = arg1;
    M2C_FIELD(arg0, int *, 0xDC38) = var_a3;
    M2C_FIELD(arg0, int *, 0xDC4C) = -1;
    M2C_FIELD(arg0, int *, 0xDC54) = 1;
    M2C_FIELD(arg0, int *, 0xDC58) = arg3;
    M2C_FIELD(arg0, int *, 0xDC50) = 0;
    M2C_FIELD(arg0, int *, 0xDCDC) = 0;
    F11E_strncpy((char *)(arg0 + 0xDC40), "imdy", 8);
    if (arg5) M2C_FIELD(arg0, int *, 0xDC3C) = F11830_alloc();
    F11830_select(index);
    if (arg5) F11830_load(M2C_FIELD(arg0, int *, 0xDC3C));
    M2C_FIELD(arg0, int *, 0xDC24) |= 0x100;
    var_a3 = F11830_exec(M2C_FIELD(arg0, int *, 0xDC38));
    int chain = arg0 + 0x40;
    if (var_a3 != 0) {
        M2C_FIELD(arg0, int *, 0xDC38) = var_a3;
        var_a3 = arg0 + 0xDC30;
        int node = M2C_FIELD(chain, int *, 0);
        int prev = M2C_FIELD(node, int *, 0);
        M2C_FIELD(chain, int *, 0) = prev;
        M2C_FIELD(prev, int *, 4) = chain;
        --M2C_FIELD(chain, int *, 0xC0);
        *(F11E_record *)(node + 0x10) = *(F11E_record *)var_a3;
        int used = chain + 0xD0;
        if (M2C_FIELD(used, int *, 0xC0) == 0) {
            M2C_FIELD(used, int *, 4) = node;
            M2C_FIELD(node, int *, 0) = used;
        } else {
            M2C_FIELD(M2C_FIELD(used, int *, 0), int *, 4) = node;
            M2C_FIELD(node, int *, 0) = M2C_FIELD(used, int *, 0);
        }
        M2C_FIELD(node, int *, 4) = used;
        M2C_FIELD(used, int *, 0) = node;
        ++M2C_FIELD(used, int *, 0xC0);
    } else {
        func_0020F428(arg0, (char *)(arg0 + 0xDC30));
    }
    M2C_FIELD(arg0, int *, 0xDC24) &= ~0x100;
    F11830_select(2);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211830);
#endif

extern "C" void func_00211BE4(int arg0, unsigned int arg1, int arg2, int arg3, int arg4)
{
    F11E_record stack;
    int temp_a1;
    int var_a3;
    int temp_a1_2;
    int temp_s0;
    int temp_v0;
    int temp_v1;
    int var_a0;
    int var_a2;

    unsigned int index = arg1 >> 30;
    register unsigned int base PS2_REG("$7") = M2C_FIELD(arg0 + index * 4, int *, 0xDC08);
    var_a3 = arg2 + D_007B4850[index].unk00 - base;
    if (F11BE4_check(arg0, arg1, arg3, base) != 0) return;
    temp_s0 = arg0 + 0x40;
    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
        var_a3 += 4;
        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
            var_a3 += 4;
            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 -= 0x1C;
                    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                        var_a3 += 4;
                        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                            var_a3 += 4;
                            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                                var_a3 += 4;
                                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                                    var_a3 += 4;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    stack.data[0] = arg4;
    stack.data[1] = arg1;
    stack.data[2] = var_a3;
    stack.data[7] = -1;
    stack.data[8] = 0;
    stack.data[9] = 1;
    stack.data[10] = arg3;
    stack.data[43] = 0;
    F11E_strncpy((char *)(arg0 + 0xDC40), "single", 8);
    temp_a1_2 = M2C_FIELD(temp_s0, int *, 0);
    var_a2 = (int)&stack;
    temp_v0 = M2C_FIELD(temp_a1_2, int *, 0);
    var_a0 = temp_a1_2 + 0x10;
    M2C_FIELD(temp_s0, int *, 0) = temp_v0;
    M2C_FIELD(temp_v0, int *, 4) = temp_s0;
    M2C_FIELD(temp_s0, int *, 0xC0) = (int) (M2C_FIELD(temp_s0, int *, 0xC0) - 1);
    *(F11E_record *)var_a0 = stack;
    temp_v1 = temp_s0 + 0xD0;
    if (M2C_FIELD(temp_v1, int *, 0xC0) == 0) {
        M2C_FIELD(temp_v1, int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = temp_v1;
    } else {
        M2C_FIELD(M2C_FIELD(temp_v1, int *, 0), int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = M2C_FIELD(temp_v1, int *, 0);
    }
    M2C_FIELD(temp_a1_2, int *, 4) = temp_v1;
    M2C_FIELD(temp_v1, int *, 0) = temp_a1_2;
    M2C_FIELD(temp_v1, int *, 0xC0) = (int) (M2C_FIELD(temp_v1, int *, 0xC0) + 1);
}

extern "C" void func_00211E84(int arg0, int arg1, int arg2)
{
    F11E_record stack;
    int temp_a1;
    int var_a3;
    int temp_a1_2;
    int temp_s0;
    int temp_v0;
    int temp_v1;
    int var_a0;
    int var_a2;

    var_a3 = arg2 + 0xA4;
    temp_s0 = arg0 + 0x40;
    temp_a1 = var_a3;
    if ((M2C_FIELD(arg2, int *, 0xA4) & 0xFFFF0000) != 0x27BD0000) {
        var_a3 = arg2 + 0xA8;
        if ((M2C_FIELD(arg2, int *, 0xA8) & 0xFFFF0000) != 0x27BD0000) {
            var_a3 = arg2 + 0xAC;
            if ((M2C_FIELD(arg2, int *, 0xAC) & 0xFFFF0000) != 0x27BD0000) {
                var_a3 = arg2 + 0xB0;
                if ((M2C_FIELD(arg2, int *, 0xB0) & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 = arg2 + 0x94;
                    if ((M2C_FIELD(arg2, int *, 0x94) & 0xFFFF0000) != 0x27BD0000) {
                        var_a3 = arg2 + 0x98;
                        if ((M2C_FIELD(arg2, int *, 0x98) & 0xFFFF0000) != 0x27BD0000) {
                            var_a3 = arg2 + 0x9C;
                            if ((M2C_FIELD(arg2, int *, 0x9C) & 0xFFFF0000) != 0x27BD0000) {
                                var_a3 = arg2 + 0xA0;
                                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) var_a3 = temp_a1;
                            }
                        }
                    }
                }
            }
        }
    }
    stack.data[0] = 0;
    stack.data[1] = arg1;
    stack.data[2] = var_a3;
    stack.data[7] = -1;
    stack.data[8] = 0;
    stack.data[9] = 1;
    stack.data[10] = 0;
    stack.data[43] = 0;
    F11E_strncpy((char *)(arg0 + 0xDC40), "mst", 8);
    temp_a1_2 = M2C_FIELD(temp_s0, int *, 0);
    var_a2 = (int)&stack;
    temp_v0 = M2C_FIELD(temp_a1_2, int *, 0);
    var_a0 = temp_a1_2 + 0x10;
    M2C_FIELD(temp_s0, int *, 0) = temp_v0;
    M2C_FIELD(temp_v0, int *, 4) = temp_s0;
    M2C_FIELD(temp_s0, int *, 0xC0) = (int) (M2C_FIELD(temp_s0, int *, 0xC0) - 1);
    *(F11E_record *)var_a0 = stack;
    temp_v1 = temp_s0 + 0xD0;
    if (M2C_FIELD(temp_v1, int *, 0xC0) == 0) {
        M2C_FIELD(temp_v1, int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = temp_v1;
    } else {
        M2C_FIELD(M2C_FIELD(temp_v1, int *, 0), int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = M2C_FIELD(temp_v1, int *, 0);
    }
    M2C_FIELD(temp_a1_2, int *, 4) = temp_v1;
    M2C_FIELD(temp_v1, int *, 0) = temp_a1_2;
    M2C_FIELD(temp_v1, int *, 0xC0) = (int) (M2C_FIELD(temp_v1, int *, 0xC0) + 1);
}

// NON_MATCHING: 108/160 differ, 2 relocs differ (size 0x280, game 0x284), 18 edits
#ifdef NON_MATCHING
extern "C" int F120AC_alloc() asm("func_00214AC4");
extern "C" void func_002120AC(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, const char *arg6)
{
    F11E_record stack;
    int temp_a1_2, temp_s0, temp_v0, temp_v1, var_a0, var_a2;
    unsigned int index = (unsigned)arg1 >> 30;
    int var_a3 = arg2 + D_007B4850[index].unk00 - M2C_FIELD(arg0 + index * 4, int *, 0xDC08);
    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000 &&
        (var_a3 += 4, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) &&
        (var_a3 += 4, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000)) {
        var_a3 += 4;
        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000 &&
            (var_a3 -= 0x1C, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000)) {
            var_a3 += 4;
            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 += 4;
                    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) var_a3 += 4;
                }
            }
        }
    }
    stack.data[0] = arg4;
    temp_s0 = arg0 + 0x40;
    stack.data[1] = arg1;
    stack.data[2] = var_a3;
    stack.data[7] = -1;
    stack.data[8] = 0;
    stack.data[9] = 1;
    stack.data[10] = arg3;
    stack.data[43] = 0;
    F11E_strncpy((char *)&stack.data[4], arg6, 8);
    if (arg5) {
        stack.data[0] |= 0x80;
        stack.data[3] = F120AC_alloc();
    }
    temp_a1_2 = M2C_FIELD(temp_s0, int *, 0);
    var_a2 = (int)&stack;
    temp_v0 = M2C_FIELD(temp_a1_2, int *, 0);
    var_a0 = temp_a1_2 + 0x10;
    M2C_FIELD(temp_s0, int *, 0) = temp_v0;
    M2C_FIELD(temp_v0, int *, 4) = temp_s0;
    M2C_FIELD(temp_s0, int *, 0xC0) = (int) (M2C_FIELD(temp_s0, int *, 0xC0) - 1);
    *(F11E_record *)var_a0 = stack;
    temp_v1 = temp_s0 + 0xD0;
    if (M2C_FIELD(temp_v1, int *, 0xC0) == 0) {
        M2C_FIELD(temp_v1, int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = temp_v1;
    } else {
        M2C_FIELD(M2C_FIELD(temp_v1, int *, 0), int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = M2C_FIELD(temp_v1, int *, 0);
    }
    M2C_FIELD(temp_a1_2, int *, 4) = temp_v1;
    M2C_FIELD(temp_v1, int *, 0) = temp_a1_2;
    M2C_FIELD(temp_v1, int *, 0xC0) = (int) (M2C_FIELD(temp_v1, int *, 0xC0) + 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002120AC);
#endif

extern "C" void func_00212330(int arg0, int arg1, int arg2, int arg3)
{
    F11E_record stack;
    int temp_a1_2, temp_s0, temp_v0, temp_v1, var_a0, var_a2;
    unsigned int index = M2C_FIELD(arg1, unsigned int *, 0x2C) >> 30;
    int var_a3 = M2C_FIELD(arg1, int *, 0x34) + D_007B4850[index].unk00 - M2C_FIELD(arg0 + index * 4, int *, 0xDC08);
    int recordArg = M2C_FIELD(arg1, int *, 0x30);
    temp_s0 = arg0 + 0x40;
    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000 &&
        (var_a3 += 4, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) &&
        (var_a3 += 4, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000)) {
        var_a3 += 4;
        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000 &&
            (var_a3 -= 0x1C, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000)) {
            var_a3 += 4;
            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 += 4;
                    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) var_a3 += 4;
                }
            }
        }
    }
    stack.data[0] = arg3;
    stack.data[1] = recordArg;
    stack.data[2] = var_a3;
    stack.data[7] = -1;
    stack.data[8] = arg1;
    stack.data[9] = 1;
    stack.data[10] = arg2;
    stack.data[43] = 0;
    F11E_strncpy((char *)&stack.data[4], D_00301710, 8);
    temp_a1_2 = M2C_FIELD(temp_s0, int *, 0);
    var_a2 = (int)&stack;
    temp_v0 = M2C_FIELD(temp_a1_2, int *, 0);
    var_a0 = temp_a1_2 + 0x10;
    M2C_FIELD(temp_s0, int *, 0) = temp_v0;
    M2C_FIELD(temp_v0, int *, 4) = temp_s0;
    M2C_FIELD(temp_s0, int *, 0xC0) = (int) (M2C_FIELD(temp_s0, int *, 0xC0) - 1);
    *(F11E_record *)var_a0 = stack;
    temp_v1 = temp_s0 + 0xD0;
    if (M2C_FIELD(temp_v1, int *, 0xC0) == 0) {
        M2C_FIELD(temp_v1, int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = temp_v1;
    } else {
        M2C_FIELD(M2C_FIELD(temp_v1, int *, 0), int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = M2C_FIELD(temp_v1, int *, 0);
    }
    M2C_FIELD(temp_a1_2, int *, 4) = temp_v1;
    M2C_FIELD(temp_v1, int *, 0) = temp_a1_2;
    M2C_FIELD(temp_v1, int *, 0xC0) = (int) (M2C_FIELD(temp_v1, int *, 0xC0) + 1);
}

extern "C" void func_00212598(int arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5)
{
    F11E_record stack;
    int temp_a1_2, temp_s0, temp_v0, temp_v1, var_a0, var_a2;
    unsigned int index = arg1 >> 30;
    int var_a3 = arg3 + D_007B4850[index].unk00 - M2C_FIELD(arg0 + index * 4, int *, 0xDC08);
    temp_s0 = arg0 + 0x40;
    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000 &&
        (var_a3 += 4, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) &&
        (var_a3 += 4, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000)) {
        var_a3 += 4;
        if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000 &&
            (var_a3 -= 0x1C, (M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000)) {
            var_a3 += 4;
            if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 += 4;
                    if ((M2C_FIELD(var_a3, int *, 0) & 0xFFFF0000) != 0x27BD0000) var_a3 += 4;
                }
            }
        }
    }
    stack.data[0] = arg5;
    stack.data[1] = arg2;
    stack.data[2] = var_a3;
    stack.data[7] = -1;
    stack.data[8] = arg1;
    stack.data[9] = 1;
    stack.data[10] = arg4;
    stack.data[43] = 0;
    F11E_strncpy((char *)&stack.data[4], D_00301710, 8);
    temp_a1_2 = M2C_FIELD(temp_s0, int *, 0);
    var_a2 = (int)&stack;
    temp_v0 = M2C_FIELD(temp_a1_2, int *, 0);
    var_a0 = temp_a1_2 + 0x10;
    M2C_FIELD(temp_s0, int *, 0) = temp_v0;
    M2C_FIELD(temp_v0, int *, 4) = temp_s0;
    M2C_FIELD(temp_s0, int *, 0xC0) = (int) (M2C_FIELD(temp_s0, int *, 0xC0) - 1);
    *(F11E_record *)var_a0 = stack;
    temp_v1 = temp_s0 + 0xD0;
    if (M2C_FIELD(temp_v1, int *, 0xC0) == 0) {
        M2C_FIELD(temp_v1, int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = temp_v1;
    } else {
        M2C_FIELD(M2C_FIELD(temp_v1, int *, 0), int *, 4) = temp_a1_2;
        M2C_FIELD(temp_a1_2, int *, 0) = M2C_FIELD(temp_v1, int *, 0);
    }
    M2C_FIELD(temp_a1_2, int *, 4) = temp_v1;
    M2C_FIELD(temp_v1, int *, 0) = temp_a1_2;
    M2C_FIELD(temp_v1, int *, 0xC0) = (int) (M2C_FIELD(temp_v1, int *, 0xC0) + 1);
}

extern "C" void func_002127F4(int arg0)
{
    Obj2127F4 *obj = (Obj2127F4 *)arg0;
    List2127F4::iterator it;
    List2127F4::iterator end;
    it = obj->m_list.begin();
    end = obj->m_list.end();
    while (it != end) {
        if (((*it).a >> 30) == 1) {
            it = obj->m_list.erase(it);
        } else {
            ++it;
        }
    }
}

extern "C" void func_00212920(char *arg0, int arg1, int arg2)
{
    List212920 *freeList = (List212920 *)(arg0 + 0xC3C0);
    List212920 *usedList = (List212920 *)(arg0 + 0xC3DC);
    NodeItem212920 item;
    item.a = arg1;
    item.b = arg2;

    Node212920 *node = freeList->head;
    Node212920 *next = node->next;
    freeList->head = next;
    next->prev = (Node212920 *)freeList;
    freeList->count--;

    node->item = item;

    if (usedList->count == 0) {
        usedList->tail = node;
        node->next = (Node212920 *)usedList;
    } else {
        usedList->head->prev = node;
        node->next = usedList->head;
    }
    node->prev = (Node212920 *)usedList;
    usedList->head = node;
    usedList->count++;
}

INCLUDE_RODATA("asm/nonmatchings/unk/0020ED9C", D_00301710);

extern "C" void func_002129B8(int arg0, int arg1, int arg2, int arg3)
{
    int *used = (int *)(arg0 + 0xC3DC);
    int *tail = *(int **)(arg0 + 0xC3E0);
    RevIter2129B8 it;
    RevIter2129B8 end;

    it = RevIter2129B8(tail);
    end = RevIter2129B8(used);
    while (it != end) {
        int *sub = (int *)((char *)it.m_node + 8);
        int val = sub[1];
        if (sub[0] == arg1) {
            func_002120AC(arg0, arg1, val, arg2, 2, arg3, "none");
            return;
        }
        --it;
    }
}

extern "C" void func_00212A5C(Obj2127F4 *self, unsigned int arg1, int arg2, int arg3)
{
    List2127F4::iterator it;
    List2127F4::iterator end;
    struct {
        State12A5C state;
        Block780_47E0 buffer;
        char unused[0x1680];
    } backup;
    it = self->m_list.begin();
    end = self->m_list.end();
    for (; it != end; ++it) {
        if ((*it).a == arg1) {
            D_007B4DB0 = D_007B4780;
            F12A5C_mode = 2;
            backup.state = F12A5C_state;
            backup.buffer = *F12A5C_state.buffer;
            F12A5C_run((int)self, arg1, (*it).b, arg2, 2, arg3);
            F12A5C_state = backup.state;
            *F12A5C_state.buffer = backup.buffer;
            return;
        }
    }
}

extern "C" void func_00212D08(int arg0, int arg1, int arg2)
{
    List212E64::Node *p = 0;
    if (X2D08_func_00213C6C(arg0, arg1, (int)&p, arg2) != 0) {
        ((Obj212E64 *)arg0)->m_list.push_back(p->m_data);
    }
}

extern "C" void func_00212E64(int arg0, int arg1)
{
    List212E64::Node *p = 0;
    if (func_00213D90(arg0, arg1, (int)&p) != 0) {
        ((Obj212E64 *)arg0)->m_list.push_back(p->m_data);
    }
}

extern "C" void func_00212FBC(int arg0, int arg1)
{
    struct Object {
        char pad[0x10];
        List212E64 *pools[3];
        char pad1C[0x6200 - 0x1C];
        List212E64 list;
    };
    Object *self = (Object *)arg0;
    Iter12FBC it;
    Iter12FBC end;
    it = Iter12FBC((int *)self->pools[0]->m_used.m_head.m_next);
    end = Iter12FBC((int *)&self->pools[0]->m_used.m_head);
    for (; it != end; ++it) {
        Data212E64 *data = (Data212E64 *)((char *)it.node + 0x10);
        if (*(int *)(data->b + 0x28) == arg1) {
            self->list.push_back(*data);
        }
    }
    it = Iter12FBC((int *)self->pools[1]->m_used.m_head.m_next);
    end = Iter12FBC((int *)&self->pools[1]->m_used.m_head);
    for (; it != end; ++it) {
        Data212E64 *data = (Data212E64 *)((char *)it.node + 0x10);
        if (*(int *)(data->b + 0x28) == arg1) {
            self->list.push_back(*data);
        }
    }
    it = Iter12FBC((int *)self->pools[2]->m_used.m_head.m_next);
    end = Iter12FBC((int *)&self->pools[2]->m_used.m_head);
    for (; it != end; ++it) {
        Data212E64 *data = (Data212E64 *)((char *)it.node + 0x10);
        if (*(int *)(data->b + 0x28) == arg1) {
            self->list.push_back(*data);
        }
    }
}

extern "C" void func_00213448(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213450);

extern "C" int func_00213ADC(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    NodeIter it;
    int *end = *(int **)arg3;

    it.m_node = *(int **)arg2;
    while (it.m_node != end) {
        int *sub = (int *)((char *)it.m_node + 0x10);
        if (sub[1] == arg1 && sub[10] == arg4) {
            return 1;
        }
        it.m_node = (int *)it.m_node[1];
    }
    return 0;
}

extern "C" int func_00213B28(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    NodeIter it;
    int *end = *(int **)arg3;
    int **found = (int **)arg4;

    it.m_node = *(int **)arg2;
    while (it.m_node != end) {
        int *sub = (int *)((char *)it.m_node + 0x10);
        if (sub[1] == arg1 && sub[10] == arg5) {
            *found = it.m_node;
            return 1;
        }
        it.m_node = (int *)it.m_node[1];
    }
    return 0;
}

extern "C" int func_00213B7C(int arg0, int arg1, int arg2, int arg3, int arg4)
{
    NodeIter it;

    it.m_node = *(int **)arg2;
    while (it.m_node != *(int **)arg3) {
        if (strcmp((char *)it.m_node + 0x20, (char *)arg1) == 0) {
            *(int **)arg4 = it.m_node;
            return 1;
        }
        it.m_node = (int *)it.m_node[1];
    }
    return 0;
}

extern "C" int func_00213BFC(int arg0, int arg1, int arg2, int arg3)
{
    NodeIter it;

    it.m_node = *(int **)arg2;
    while (it.m_node != *(int **)arg3) {
        if (strcmp((char *)it.m_node + 0x20, (char *)arg1) == 0) {
            return 1;
        }
        it.m_node = (int *)it.m_node[1];
    }
    return 0;
}

// NON_MATCHING: 6/37 differ, 5 edits
#ifdef NON_MATCHING
extern "C" int func_00213B28(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" int func_00213C6C(int arg0, unsigned int arg1, int arg2, int arg3)
{
    register int self PS2_REG("$7") = arg0;
    int a2 = arg2;
    NodeIter beg;
    NodeIter end0;
    NodeIter end1;
    NodeIter end2;
    NodeIter *end_ptr;
    register char *p PS2_REG("$2");
    switch ((int)(arg1 >> 30)) {
    case 0:
        p = *(char **)(self + 0x10);
        end_ptr = &end0;
        goto do_call;
    case 1:
        p = *(char **)(self + 0x14);
        end_ptr = &end1;
        goto do_call;
    case 2:
        p = *(char **)(self + 0x18);
        end_ptr = &end2;
    do_call:
        beg.m_node = *(int **)(p + 0xD4);
        end_ptr->m_node = (int *)(p + 0xD0);
        return func_00213B28(arg0, arg1, (int)&beg, (int)end_ptr, a2, arg3);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213C6C);
#endif

// NON_MATCHING: 32/35 differ, 1 reloc differs (size 0x8C, game 0x90), 13 edits
#ifdef NON_MATCHING
extern "C" int func_00213ADC(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" int func_00213D00(int arg0, unsigned int arg1, int arg2)
{
    NodeIter beg;
    NodeIter end0;
    NodeIter end1;
    NodeIter end2;
    NodeIter *end_ptr;
    int *p;
    switch ((int)(arg1 >> 30)) {
    case 0:
        p = *(int **)(arg0 + 0x10);
        end_ptr = &end0;
        goto do_call;
    case 1:
        p = *(int **)(arg0 + 0x14);
        end_ptr = &end1;
        goto do_call;
    case 2:
        p = *(int **)(arg0 + 0x18);
        end_ptr = &end2;
    do_call:
        beg.m_node = (int *)p[0xD4 / 4];
        end_ptr->m_node = &p[0xD0 / 4];
        return func_00213ADC(arg0, arg1, (int)&beg, (int)end_ptr, arg2);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213D00);
#endif

extern "C" int func_00213D90(int arg0, int arg1, int arg2)
{
    NodeIter3D90 beg0, end0, beg1, end1, beg2, end2;
    if ((checkRange3D90(arg0, arg1, *(char **)(arg0 + 0x10), &beg0, &end0, arg2) ^ 1) == 0 ||
        (checkRange3D90(arg0, arg1, *(char **)(arg0 + 0x14), &beg1, &end1, arg2) ^ 1) == 0 ||
        (checkRange3D90(arg0, arg1, *(char **)(arg0 + 0x18), &beg2, &end2, arg2) ^ 1) == 0) {
        return 1;
    }
    return 0;
}

extern "C" int func_00213E78(int arg0, int arg1)
{
    NodeIter3E78 beg0, end0, beg1, end1, beg2, end2;
    if ((checkRange3E78(arg0, arg1, *(char **)(arg0 + 0x10), &beg0, &end0) ^ 1) == 0 ||
        (checkRange3E78(arg0, arg1, *(char **)(arg0 + 0x14), &beg1, &end1) ^ 1) == 0 ||
        (checkRange3E78(arg0, arg1, *(char **)(arg0 + 0x18), &beg2, &end2) ^ 1) == 0) {
        return 1;
    }
    return 0;
}

// NON_MATCHING: 84/224 differ, 14 relocs differ (size 0x380, game 0x378), 85 edits
#ifdef NON_MATCHING
extern Block780_47E0 *F13F48_buffers[] asm("D_002D9E08");
extern "C" void func_00213F48(int arg0, int arg1, int arg2)
{
    int base = arg1 + 0x30;
    D_007B47D0 = base;
    D_007B4820 = M2C_FIELD(arg1, int *, 0x20);
    D_007B4830 = M2C_FIELD(arg1, int *, 0x24);
    D_007B47E0 = arg1 + M2C_FIELD(arg1, int *, 0x14) + M2C_FIELD(arg1, int *, 0x18);
    D_007B4800 = arg1 + M2C_FIELD(arg1, int *, 0x14);
    D_007B47F0 = D_007B4800 - M2C_FIELD(arg1, int *, 0x1C) + 8;
    M2C_FIELD(D_007B47E0, int *, -0x20) = M2C_FIELD(arg0, int *, 0xDC1C);
    M2C_FIELD(D_007B47E0, int *, -0x10) = M2C_FIELD(arg0, int *, 0xDC20);
    D_007B47D0 = base;
    D_007B47E0 = M2C_FIELD(arg1, int *, 0x10);
    D_007B4800 = arg1 + M2C_FIELD(arg1, int *, 0x14);
    D_007B47F0 = D_007B4800 + M2C_FIELD(arg1, int *, 0x1C) + 8;
    D_007B4820 = M2C_FIELD(arg1, int *, 0x20);
    D_007B4830 = M2C_FIELD(arg1, int *, 0x24);
    int tail = arg1 + M2C_FIELD(arg1, int *, 0xC) + (M2C_FIELD(arg1, int *, 0x18) + M2C_FIELD(arg1, int *, 0x14));
    X4310_D_007B4700[28] = tail + 0x8000;
    X4310_D_007B4700[29] = tail + 0x8780;
    D_002D9C08[arg2] = *(Block80_4310 *)X4310_D_007B4700;
    *F13F48_buffers[arg2] = *(Block780_47E0 *)X4310_D_007B4700[28];
    int off = arg2 * 0x30;
    int off10 = off + 0x10;
    D_007B4850[arg2].unk00 = D_007B47D0;
    *(int *)(off + (char *)&D_007B4850[0].unk04) = D_007B47E0;
    int result = X4310_D_007B4700[28] - D_007B47E0 + 0x450000;
    *(int *)(off + (char *)&D_007B4850[0].unk08) = D_007B4800;
    D_007B4850[arg2].unk0C = D_007B47F0;
    D_007B4850[arg2].unk10 = D_007B4820;
    *(int *)(off10 + (char *)&D_007B4850[0].unk04) = D_007B4830;
    D_007B4850[arg2].unk20 = X4310_D_007B4700[28];
    *(int *)(off + 0x20 + (char *)&D_007B4850[0].unk04) = X4310_D_007B4700[29];
    *(int *)(off10 + (char *)&D_007B4850[0].unk08) = result;
    D_007B4810 = result;
    X4310_D_007B4700[1] = result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213F48);
#endif

extern "C" void func_002142C0(void)
{
    int i;

    i = 0x1FF;
    do {
        i -= 0x20;
        asm("nop");
    } while (i >= 0);
    i = 0x1FF;
    do {
        i -= 0x20;
        asm("nop");
    } while (i >= 0);
}

extern "C" void func_00214310(unsigned int arg0)
{
    D_007B47D0 = D_007B4850[arg0].unk00;
    D_007B47E0 = D_007B4850[arg0].unk04;
    D_007B4800 = D_007B4850[arg0].unk08;
    D_007B47F0 = D_007B4850[arg0].unk0C;
    D_007B4820 = D_007B4850[arg0].unk10;
    D_007B4830 = D_007B4850[arg0].unk14;
    X4310_D_007B4700[28] = D_007B4850[arg0].unk20;
    X4310_D_007B4700[29] = D_007B4850[arg0].unk24;
    D_007B4810 = D_007B4850[arg0].unk18;
    *(Block80_4310 *)X4310_D_007B4700 = D_002D9C08[arg0];
    X4310_D_007B4700[31] = 0;
}

extern "C" void func_002144C4(void) {
}

extern "C" void func_002144CC(Obj44CC *arg0)
{
    Inner44CC *inner = arg0->unkDCE0;
    if (inner != 0) {
        if (inner->flags & 0x200) {
            *(Block80_44CC *)&D_007B4700 = inner->unk2C;
        }
        if (arg0->unkDCE0->unkAC != 0) {
            **(Block780_44CC **)&D_007B4770 = *arg0->unkDCE0->unkAC;
        }
    }
    arg0->unkDCE0 = 0;
}

extern "C" void func_00214664(void)
{
    Obj4640 *obj = *(Obj4640 **)&D_007B4640;
    if (obj->flags & 0x200) {
        *(Block80_4664 *)&D_007B4700 = obj->unk3C;
    }
    if ((*(Obj4640 **)&D_007B4640)->unkBC != 0) {
        **(Block780_4664 **)&D_007B4770 = *(*(Obj4640 **)&D_007B4640)->unkBC;
    }
}

extern "C" void func_002147E0(Obj47E0 *arg0)
{
    Inner47E0 *inner = (Inner47E0 *)(X47E0_D_007B4640 + 0x10);
    if (arg0->unkDC24 & 0x100) {
        inner = &arg0->unkDC30;
    }
    inner->unk2C = *(Block80_47E0 *)&X47E0_D_007B4700;
    inner->flags |= 0x200;
    if (inner->unkAC == 0) {
        inner->unkAC = (Block780_47E0 *)func_002149A8();
    }
    *inner->unkAC = *X47E0_D_007B4700.unk70;
}

extern "C" int func_002149A8()
{
    int temp_v0;
    int temp_v0_2;
    int temp_s1;

    temp_s1 = (*(int *)&D_007B4D20) + ((*(int *)&D_002D9950) << 0xB);
    ((int *)&D_007B4D30)[(*(int *)&D_002D9950)] = 1;
    Xiiii_memset(temp_s1, 0, 0x800);
    temp_v0 = (*(int *)&D_002D9950) + 1;
    (*(int *)&D_002D9950) = temp_v0;
    if (temp_v0 >= 0x20) {
        (*(int *)&D_002D9950) = 0;
    }
    if (((int *)&D_007B4D30)[(*(int *)&D_002D9950)] != 0) {
        do {
            temp_v0_2 = (*(int *)&D_002D9950) + 1;
            (*(int *)&D_002D9950) = temp_v0_2;
            if (temp_v0_2 >= 0x20) {
                (*(int *)&D_002D9950) = 0;
            }
        } while (((int *)&D_007B4D30)[(*(int *)&D_002D9950)] != 0);
    }
    return (int) temp_s1;
}

extern "C" void func_00214A94(int arg0)
{
    unsigned int temp_a0;

    temp_a0 = (unsigned int) (arg0 - (*(int *)&D_007B4D20)) >> 0xB;
    (*(int *)&D_002D9950) = (int) temp_a0;
    ((int *)&D_007B4D30)[temp_a0] = 0;
}

extern "C" int func_00214AC4(void)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (*(unsigned int *)D_007B4920[i].b == 0xCCCCCCCCU) {
            break;
        }
    }
    D_007B4920[i] = *(Elem214AC4 *)&D_007B4700;
    return i;
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214BCC);

// NON_MATCHING: 88/160 differ, 11 relocs differ (size 0x280, game 0x274), 23 edits
#ifdef NON_MATCHING
extern char D_007A4440[];
extern "C" int F14C_nop(int, int, int, int) asm("func_0020FF34");
extern "C" void F14C_flush(void *, int *) asm("func_002147E0");
extern int (*F14C_special[64])(unsigned, unsigned, unsigned, unsigned, unsigned) asm("D_002D9A58");
extern int (*F14C_main[64])(unsigned, unsigned, unsigned, unsigned, unsigned) asm("D_002D9958");
extern int (*F14C_sys[])(int,int,int,int,int,int) asm("D_002D90F8");
extern "C" int *func_00214C24(int *pc)
{
    D_007B47C0 = 0;
    D_007B47B0 = 0;
    for (;;) {
        D_007B4780 = (int)pc;
        register unsigned insn PS2_REG("$8") = *pc;
        if (insn == 0x0C102031) return 0;
        unsigned op = insn >> 26;
        if (op == 0) {
            if (insn == 0) F14C_nop(0,0,0,0);
            else F14C_special[insn & 63]((insn >> 21) & 31, (insn >> 16) & 31, (insn >> 11) & 31, (insn >> 6) & 31, insn);
        } else F14C_main[op]((insn >> 21) & 31, (insn >> 16) & 31, insn & 65535, insn, insn);
        if (D_007B47B0) {
            if ((unsigned)D_007B47B0 <= 0x815F) {
                int *regs = (int *)&D_007B4700;
                regs[2] = F14C_sys[((unsigned)(D_007B47B0 - 0x144) >> 6) & 65535](regs[4],regs[5],regs[6],regs[7],regs[8],regs[9]);
                D_007B47C0 = 0;
                M2C_FIELD((*(int *)&D_007B4640), int *, 0x34) = 1;
                if (regs[2] == 0) ++pc;
                else if ((unsigned)regs[2] == 0xCCCCCCCC) {
                    regs[31] = 0;
                    F14C_flush(&D_007A4440, &D_007B47C0);
                    return pc - 1;
                } else if ((unsigned)regs[2] == 0xCCCCCCCD) {
                    regs[31] = 0;
                    F14C_flush(&D_007A4440, &D_007B47C0);
                    return pc;
                } else if ((unsigned)regs[2] == 0xCCCCCCCE) {
                    F14C_flush(&D_007A4440, &D_007B47C0);
                    return (int *)D_007B47B0;
                } else if ((unsigned)regs[2] == 0xCCCCCCCA) {
                    D_007B47B0 = 0;
                    return 0;
                } else if ((unsigned)regs[2] == 0xCCCCCCC9) pc = (int *)(D_007B4DB0 + 4);
                else ++pc;
            } else pc = (int *)(D_007B47D0 + D_007B47B0 - 0x8160);
            D_007B47B0 = 0;
        } else ++pc;
        if (D_007B47C0) {
            unsigned next = D_007B47C0 & 0x7FFFFFFF;
            D_007B47B0 = next;
            if (!next) return 0;
            D_007B47C0 = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214C24);
#endif

extern "C" int func_00214E98(char *arg0, F14E_out *arg1)
{
    char *source = *(char **)(arg0 + 0xDC1C);
    int n = D_007A3210;
    if ((unsigned)(n - 1) >= 13) n = 9;
    F14E_block block = *(F14E_block *)source;
    *(F14E_part *)((char *)block.data + 0x504) = *(F14E_part *)(n * 64 + (int)source + 0x4C4);
    *arg1 = *(F14E_out *)&block;
    return 0x544;
}

extern "C" int func_002150B0(char *arg0, F150_block *arg1)
{
    char *source = *(char **)(arg0 + 0xDC20);
    int n = D_007A3210;
    if ((unsigned)(n - 1) >= 13) n = 9;
    F150_block block = *(F150_block *)source;
    *(F150_part *)(block.data + 0x360) = *(F150_part *)(((n * 0x200 + 0x1900) >> 3) + (int)source);
    *arg1 = block;
    return 0x400;
}

extern "C" int func_002152B8(Obj2152B8 *arg0, Src2152B8 *arg1)
{
    int lang = D_007A3210;
    if (lang < 1 || lang > 13) {
        lang = 9;
    }
    *(Block544 *)arg0->m_state = *(Block544 *)arg1;
    arg0->m_state->lang[lang - 1] = arg1->unk504;
    return 0x544;
}

extern "C" int func_00215430(Obj215430 *arg0, Src215430 *arg1)
{
    int lang = D_007A3210;
    if (lang < 1 || lang > 13) {
        lang = 9;
    }
    *(Block360 *)arg0->m_flags = arg1->unk0;
    *(Block40 *)((((lang - 1) * 512 + 0x1B00) >> 3) + (long)arg0->m_flags) = arg1->unk360;
    return 0x400;
}

extern "C" void func_002155A0(void) {
}

// unk/0020ED9C, func_002155A8: m2c's draft

// ---- declarations

// ---- function
extern "C" void func_002155A8(int arg0, int arg1)
{
    if (arg1 == 0xFFFF && arg0 == 1) {
        D_007B4640 = 0;
    }
    if (arg1 == 0xFFFF && arg0 == 1) {
        D_007B4650 = 0;
    }
};

extern "C" void func_002155D4()
{
    X_func_002155A8(1, 0xFFFF);
}

