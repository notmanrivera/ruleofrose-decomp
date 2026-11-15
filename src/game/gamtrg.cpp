#include "include_asm.h"
struct ObjStat_ddf48 {
    unsigned char pad0[0x100];
    int m_oid;
    unsigned char pad104[0x24];
    unsigned short m_uid;
};
template <class T> class GamPoolList_ddf48 {
public:
    struct Node {
        Node *m_prev;
        Node *m_next;
        T m_data;
    };
    class iterator {
    public:
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        T &operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    struct SubList {
        Node m_head;
        int m_count;
        SubList()
        {
            m_count = 0;
            m_head.m_prev = &m_head;
            m_head.m_next = &m_head;
        }
        void clear()
        {
            m_count = 0;
            m_head.m_prev = &m_head;
            m_head.m_next = &m_head;
        }
        iterator begin() { return iterator(m_head.m_next); }
        iterator end() { return iterator(&m_head); }
    };
    SubList m_free;
    SubList m_used;
    int m_max;
    int m_pad[7];
    Node *m_pool;
    int m_pad2[15];
    GamPoolList_ddf48(int theMax) : m_max(0)
    {
        Node *pool = new Node[theMax];
        m_max = theMax;
        m_pool = pool;
        GamPoolList_ddf48 *self = this;
        for (int i = 0; i < self->m_max; i++) {
            pool[i].m_prev = &pool[i - 1];
            pool[i].m_next = &pool[i + 1];
        }
        self->m_used.clear();
        self->m_free.m_head.m_next = pool;
        self->m_free.m_count = self->m_max;
        pool[0].m_prev = &self->m_free.m_head;
        Node *last = &self->m_free.m_head.m_next[self->m_free.m_count - 1];
        self->m_free.m_head.m_prev = last;
        last->m_next = &self->m_free.m_head;
    }
    ~GamPoolList_ddf48()
    {
        delete[] m_pool;
    }
    int size() const { return m_used.m_count; }
    iterator begin() { return m_used.begin(); }
    iterator end() { return m_used.end(); }
};
extern int D_007812C0_ddf48 asm("D_007812C0");
extern "C" void X_func_001D35AC_ddf48(void *, void *, void *, int, int, int, float) asm("func_001D35AC");
extern "C" void *X_memset_de6fc(void *, int, __SIZE_TYPE__) asm("memset");
struct Elem_de6fc {
    int key;
    int vals[8];
};
struct Node_de6fc {
    Node_de6fc *m_prev;
    Node_de6fc *m_next;
    Elem_de6fc m_data __attribute__((aligned(16)));
};
struct Chain_de6fc {
    Node_de6fc m_head;
    int m_num;
    void push_back(Node_de6fc *theNode) {
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
    Node_de6fc *pop_back() {
        Node_de6fc *node = m_head.m_prev;
        Node_de6fc *prev = node->m_prev;
        m_head.m_prev = prev;
        prev->m_next = &m_head;
        --m_num;
        return node;
    }
};
struct Iter_de6fc {
    Node_de6fc *m_node;
    Iter_de6fc() : m_node(0) {}
    Iter_de6fc(Node_de6fc *n) : m_node(n) {}
    Iter_de6fc(const Iter_de6fc &o) : m_node(o.m_node) {}
    Elem_de6fc &operator*() const { return m_node->m_data; }
    Iter_de6fc &operator++() { m_node = m_node->m_next; return *this; }
    bool operator!=(const Iter_de6fc &o) const { return m_node != o.m_node; }
};
struct Pool_de6fc {
    Chain_de6fc m_free;
    Chain_de6fc m_used;
    Iter_de6fc begin() { return Iter_de6fc(m_used.m_head.m_next); }
    Iter_de6fc end() { return Iter_de6fc(&m_used.m_head); }
    void push_back(const Elem_de6fc &data) {
        Node_de6fc *node = m_free.pop_back();
        node->m_data = data;
        m_used.push_back(node);
    }
};
struct Mgr_de6fc {
    unsigned char pad[0x18B40];
    Pool_de6fc *m_pool;
};
struct Vec2_de8ac {
    float x, y;
} __attribute__((aligned(16)));
struct Elem_dddbc {
    unsigned int u0[11];
    unsigned int flg2C;
    unsigned int u30[(0xB0 - 0x30) / 4];
} __attribute__((aligned(16)));
struct Node_dddbc { Node_dddbc *m_prev; Node_dddbc *m_next; Elem_dddbc m_data; };
struct Chain_dddbc {
    Node_dddbc m_head;
    int m_num;
    void push_back(Node_dddbc *theNode) {
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
    void unlink(Node_dddbc *theNode) {
        if (theNode == m_head.m_next) {
            Node_dddbc *next = theNode->m_next;
            m_head.m_next = next;
            next->m_prev = &m_head;
        } else {
            Node_dddbc *p = theNode->m_prev;
            if (theNode == m_head.m_prev) {
                m_head.m_prev = p;
                p->m_next = &m_head;
            } else {
                p->m_next = theNode->m_next;
                Node_dddbc *prev = theNode->m_prev;
                p = theNode->m_next;
                p->m_prev = prev;
            }
        }
        --m_num;
    }
};
struct Iter_dddbc {
    Node_dddbc *m_node;
    Iter_dddbc() : m_node(0) {}
    Iter_dddbc(Node_dddbc *n) : m_node(n) {}
    Iter_dddbc(const Iter_dddbc &o) : m_node(o.m_node) {}
    Elem_dddbc &operator*() const { return m_node->m_data; }
    Iter_dddbc &operator++() { m_node = m_node->m_next; return *this; }
    bool operator!=(const Iter_dddbc &o) const { return m_node != o.m_node; }
};
struct List_dddbc {
    Chain_dddbc m_free;
    Chain_dddbc m_used;
    int m_max;
    Iter_dddbc begin() { return Iter_dddbc(m_used.m_head.m_next); }
    Iter_dddbc end() { return Iter_dddbc(&m_used.m_head); }
    int size() const { return m_used.m_num; }
    Iter_dddbc erase(Iter_dddbc it) {
        Iter_dddbc next(it);
        ++next;
        Node_dddbc *node = it.m_node;
        m_used.unlink(node);
        m_free.push_back(node);
        return next;
    }
};
struct Mgr_dddbc { char pad[0xC1C0]; List_dddbc list; };
extern "C" void Xii_func_001DDDAC_dddbc(int) asm("func_001DDDAC");
struct Elem_deaac {
    float minX;
    float minZ;
    float maxX;
    float maxZ;
    unsigned int u10[4];
    unsigned int flg;
    unsigned int u24[2];
    int id;
    int u30;
    int u34;
    unsigned int u38[3];
    int u44;
    unsigned int u48[(0xB0 - 0x48) / 4];
} __attribute__((aligned(16)));
struct Node_deaac { Node_deaac *m_prev; Node_deaac *m_next; Elem_deaac m_data; };
struct Chain_deaac { Node_deaac m_head; int m_num; };
struct Iter_deaac {
    Node_deaac *m_node;
    Iter_deaac() : m_node(0) {}
    Iter_deaac(Node_deaac *n) : m_node(n) {}
    Iter_deaac(const Iter_deaac &o) : m_node(o.m_node) {}
    Elem_deaac &operator*() const { return m_node->m_data; }
    Iter_deaac &operator++() { m_node = m_node->m_next; return *this; }
    bool operator!=(const Iter_deaac &o) const { return m_node != o.m_node; }
};
struct List_deaac {
    Chain_deaac m_free;
    Chain_deaac m_used;
    int m_max;
    Iter_deaac begin() { return Iter_deaac(m_used.m_head.m_next); }
    Iter_deaac end() { return Iter_deaac(&m_used.m_head); }
    int size() const { return m_used.m_num; }
};
struct Mgr_deaac {
    char pad[0xC1C0];
    List_deaac list;
};
struct Pc_deaac {
    char pad[0x100];
    int m_oid;
};
struct GamMan_deaac {
    char pad[0x22090];
    Pc_deaac *m_pc;
};
extern GamMan_deaac D_007812C0_deaac asm("D_007812C0");
extern int D_007A4440_deaac asm("D_007A4440");
extern const char D_002FD640_deaac[] asm("D_002FD640");
extern "C" void X_func_002113DC(void *, int, int, int, int, int, int, const char *) asm("func_002113DC");
struct Elem_dec14 {
    float minX;
    float minZ;
    float maxX;
    float maxZ;
    unsigned int u10[4];
    unsigned int flg;
    unsigned int u24[2];
    int id;
    int u30;
    int u34;
    unsigned int u38[(0x70 - 0x38) / 4];
    unsigned int flg70;
    unsigned int u74[(0xB0 - 0x74) / 4];
} __attribute__((aligned(16)));
struct Node_dec14 { Node_dec14 *m_prev; Node_dec14 *m_next; Elem_dec14 m_data; };
struct Chain_dec14 { Node_dec14 m_head; int m_num; };
struct Iter_dec14 {
    Node_dec14 *m_node;
    Iter_dec14() : m_node(0) {}
    Iter_dec14(Node_dec14 *n) : m_node(n) {}
    Iter_dec14(const Iter_dec14 &o) : m_node(o.m_node) {}
    Elem_dec14 &operator*() const { return m_node->m_data; }
    Iter_dec14 &operator++() { m_node = m_node->m_next; return *this; }
    bool operator!=(const Iter_dec14 &o) const { return m_node != o.m_node; }
};
struct List_dec14 {
    Chain_dec14 m_free;
    Chain_dec14 m_used;
    int m_max;
    Iter_dec14 begin() { return Iter_dec14(m_used.m_head.m_next); }
    Iter_dec14 end() { return Iter_dec14(&m_used.m_head); }
    int size() const { return m_used.m_num; }
};
struct Mgr_dec14 {
    char pad[0xC1C0];
    List_dec14 list;
};
struct Pc_dec14 {
    char pad[0x100];
    int m_oid;
};
struct GamMan_dec14 {
    char pad[0x22090];
    Pc_dec14 *m_pc;
};
extern GamMan_dec14 D_007812C0_dec14 asm("D_007812C0");
extern "C" int Xiiui_func_001D05F4(void *, unsigned int, float *) asm("func_001D05F4");
extern "C" void Xviiii_func_001E0C2C(void *, int, int, unsigned int) asm("func_001E0C2C");
struct Elem_dd414 {
    unsigned char pad[0x30];
} __attribute__((aligned(16)));
struct Node_dd414 {
    Node_dd414 *m_prev;
    Node_dd414 *m_next;
    Elem_dd414 m_data;
};
struct Chain_dd414 {
    Node_dd414 m_head;
    int m_num;
    void init() {
        m_num = 0;
        m_head.m_prev = &m_head;
        m_head.m_next = &m_head;
    }
    Chain_dd414() { init(); }
    void splice(Chain_dd414 &theOther) {
        if (theOther.m_num != 0) {
            m_head.m_prev->m_next = theOther.m_head.m_next;
            Node_dd414 *last = m_head.m_prev;
            last->m_next->m_prev = last;
            Node_dd414 *tail = theOther.m_head.m_prev;
            m_head.m_prev = tail;
            tail->m_next = &m_head;
            m_num += theOther.m_num;
            theOther.init();
        }
    }
};
struct Pool_dd414 {
    Chain_dd414 m_free;
    Chain_dd414 m_used;
    int m_max;
    unsigned char padA4[0x1C];
    Node_dd414 *m_nodes;
    unsigned char padC4[0x3C];
    Pool_dd414(int n) : m_max(0) {
        Node_dd414 *nodes = new Node_dd414[64];
        m_max = n;
        m_nodes = nodes;
        Node_dd414 *p = nodes;
        for (int i = 0; i < m_max; i++) {
            p->m_prev = p - 1;
            p->m_next = p + 1;
            p++;
        }
        m_used.init();
        m_free.m_head.m_next = nodes;
        m_free.m_num = m_max;
        nodes[0].m_prev = &m_free.m_head;
        m_free.m_head.m_prev = (Node_dd414 *)((char *)m_free.m_head.m_next + m_free.m_num * sizeof(Node_dd414) - sizeof(Node_dd414));
        m_free.m_head.m_prev->m_next = &m_free.m_head;
    }
    int size() const { return m_used.m_num; }
    void clear() { m_free.splice(m_used); }
};
struct Mgr_dd414 {
    unsigned char pad[0x18B40];
    Pool_dd414 *m_pool;
};
struct GamTrgCopy_d96ec {
    int data[0xB0 / 4];
};
struct ObjStat_d96ec {
    unsigned char pad0[0x100];
    GamTrgCopy_d96ec data;
    // +0x100: copy struct (0xB0 bytes), +0x108: m_chrID, +0x190: pos, +0x1A0: rot
};
struct DogActor_d96ec {
    unsigned char pad0[0x40];
    float pos[4];
    float rot[4];
    void getPos(float *out) {
        out[0] = pos[0];
        out[1] = pos[1];
        out[2] = pos[2];
    }
    void getRot(float *out) {
        out[0] = rot[0];
        out[1] = rot[1];
        out[2] = rot[2];
    }
};
extern int D_006FBD80_d96ec asm("D_006FBD80");
static inline DogActor_d96ec *getDogActor_d96ec(void *base, int idx) {
    return (DogActor_d96ec *)(((char *)base + idx * 0x4D0) + 0x2920);
}
struct Elem_de5dc { unsigned int u0[8]; unsigned int flg; unsigned int u24[2]; int id; unsigned int u30[(0xB0 - 0x30) / 4]; } __attribute__((aligned(16))); // de5dc
struct Node_de5dc { Node_de5dc *m_prev; Node_de5dc *m_next; Elem_de5dc m_data; }; // de5dc
struct Chain_de5dc {
    Node_de5dc m_head;
    int m_num;
    void push_back(Node_de5dc *theNode) {
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
    void unlink(Node_de5dc *theNode) {
        if (theNode == m_head.m_next) {
            Node_de5dc *next = theNode->m_next;
            m_head.m_next = next;
            next->m_prev = &m_head;
        } else {
            Node_de5dc *p = theNode->m_prev;
            if (theNode == m_head.m_prev) {
                m_head.m_prev = p;
                p->m_next = &m_head;
            } else {
                p->m_next = theNode->m_next;
                Node_de5dc *prev = theNode->m_prev;
                p = theNode->m_next;
                p->m_prev = prev;
            }
        }
        --m_num;
    }
}; // de5dc
struct Iter_de5dc {
    Node_de5dc *m_node;
    Iter_de5dc() : m_node(0) {}
    Iter_de5dc(Node_de5dc *n) : m_node(n) {}
    Iter_de5dc(const Iter_de5dc &o) : m_node(o.m_node) {}
    Elem_de5dc &operator*() const { return m_node->m_data; }
    Iter_de5dc &operator++() { m_node = m_node->m_next; return *this; }
    bool operator!=(const Iter_de5dc &o) const { return m_node != o.m_node; }
}; // de5dc
struct List_de5dc {
    Chain_de5dc m_free;
    Chain_de5dc m_used;
    int m_max;
    Iter_de5dc begin() { return Iter_de5dc(m_used.m_head.m_next); }
    Iter_de5dc end() { return Iter_de5dc(&m_used.m_head); }
    Iter_de5dc erase(Iter_de5dc it) {
        Iter_de5dc next(it);
        ++next;
        Node_de5dc *node = it.m_node;
        m_used.unlink(node);
        m_free.push_back(node);
        return next;
    }
}; // de5dc
struct Mgr_de5dc { char pad[0xC1C0]; List_de5dc list; }; // de5dc
struct Elem_de4e4 { unsigned int u0[8]; unsigned int flg; unsigned int u24[(0xB0 - 0x24) / 4]; } __attribute__((aligned(16)));
struct Node_de4e4 { Node_de4e4 *m_prev; Node_de4e4 *m_next; Elem_de4e4 m_data; };
struct Chain_de4e4 { Node_de4e4 m_head; int m_num; };
struct Iter_de4e4 { Node_de4e4 *m_node; Iter_de4e4() : m_node(0) {} Iter_de4e4(Node_de4e4 *n) : m_node(n) {} Iter_de4e4(const Iter_de4e4 &o) : m_node(o.m_node) {} Elem_de4e4 &operator*() const { return m_node->m_data; } Iter_de4e4 &operator++() { m_node = m_node->m_next; return *this; } bool operator!=(const Iter_de4e4 &o) const { return m_node != o.m_node; } };
struct List_de4e4 { Chain_de4e4 m_free; Chain_de4e4 m_used; int m_max; Iter_de4e4 begin() { return Iter_de4e4(m_used.m_head.m_next); } Iter_de4e4 end() { return Iter_de4e4(&m_used.m_head); } int size() const { return m_used.m_num; } };
extern "C" void func_001DDC80(List_de4e4 *);
extern "C" void func_001DE104(List_de4e4 *, Elem_de4e4);
struct GamTrgCopy_d9830 {
    int data[0xB0 / 4];
};
extern "C" void Xvii_func_001D7EB8(int, int) asm("func_001D7EB8");
extern "C" void Xvii_func_001D890C(int, int) asm("func_001D890C");
extern "C" void Xvii_func_001D8D28(int, int) asm("func_001D8D28");
extern "C" int Xiiii_func_001D7F48(int, int, int) asm("func_001D7F48");
extern "C" int Xiu_func_001F6878(unsigned int) asm("func_001F6878");
extern int X_vt_7ObjStat asm("_vt$7ObjStat");
struct GamTrgNode_d87f4 {
    GamTrgNode_d87f4 *m_prev;
    GamTrgNode_d87f4 *m_next;
    int m_data;
};
struct GamTrgChain_d87f4 {
    GamTrgNode_d87f4 m_head;
    int m_num;
    void init() {
        m_num = 0;
        m_head.m_prev = &m_head;
        m_head.m_next = &m_head;
    }
};
struct GamTrgList_d87f4 {
    GamTrgChain_d87f4 m_free;
    GamTrgChain_d87f4 m_used;
    int m_max;
    void init(GamTrgNode_d87f4 *theNodes, int theMax) {
        m_free.init();
        m_used.init();
        m_max = theMax;
        int i = 0;
        GamTrgNode_d87f4 *p = theNodes;
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
};
struct ObjStat_d87f4 {
    unsigned char m_unk000[0x40];
    GamTrgList_d87f4 m_pool;        // +0x40 .. +0x64
    unsigned char m_unk064[0x1C];
    GamTrgNode_d87f4 m_nodes[8];    // +0x80 .. +0xE0
    unsigned char m_unk0E0[0x20];
    int m_oid;                      // +0x100
    int m_curStat;                  // +0x104
    int m_chrID;                    // +0x108
    int *m_sectaKeep;               // +0x10C
    int m_unk110;                   // +0x110
    int *m_secta;                   // +0x114
    unsigned char m_unk118[0x10];
    unsigned short m_uid;           // +0x128
    unsigned char m_unk12A[0x6];
    int m_areaNo;                   // +0x130
    unsigned char m_unk134[0xC];
    unsigned int m_flgV;            // +0x140
    unsigned char m_unk144[0x114];
    void *m_vtbl;                   // +0x258
};
struct GamTrgCopy_dd558 {
    long data[0xB0 / 8];
};
extern "C" int Xiiiiiii_alloc__9BedMemoryiPCciii(int, int, int, int, int, int) asm("alloc__9BedMemoryiPCciii");
extern int D_006E9800;
struct GamTrg0_d8778 {
    unsigned int count;
    unsigned short *unk04;
    unsigned short *unk08;
    int unk0C;
};
struct GamTrg0_d85f8 {
    unsigned int count;
    unsigned short *unk04;
    unsigned short *unk08;
};
extern "C" int Xii_heapFree__FPv(int) asm("heapFree__FPv");
extern "C" void Xv_func_001E8F88(int) asm("func_001E8F88");
extern "C" int Xiii_func_001D811C(int, int, int, int) asm("func_001D811C");
extern "C" int Xiiif_func_001333C0(int, int, float) asm("func_001333C0");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xiiii_func_001D5BC8(int, int, int) asm("func_001D5BC8");
struct m2c_block8 { int w[2]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern int D_002FC418;
extern int D_002FC420;
extern int D_002FC428;
extern int D_002FC430;
extern int D_002FC438;
extern int D_002FC440;
extern int D_002FC448;
extern int D_002FC450;
extern int D_002FC458;
extern int D_002FC460;
extern int D_002FC468;
extern int D_002FC470;
extern int D_002FC478;
extern int D_002FC480;
extern int D_002FC488;
extern int D_002FC490;
extern int D_002FC498;
extern int D_002FC4A0;
extern int D_002FC4A8;
extern int D_002FC4B0;
extern int D_002FC4B8;
extern int D_002FC4C0;
extern int D_002FC4C8;
extern int D_002FC4D0;
extern int D_002FC4D8;
extern int D_002FC4E0;
extern int D_002FC4E8;
extern int D_002FC4F0;
extern int D_002FC4F8;
extern int D_002FC500;
extern int D_002FC508;
extern int D_002FC510;
extern "C" int Xiii_func_001E7724(int, int) asm("func_001E7724");
extern "C" int Xiii_func_001E7D7C(int, int) asm("func_001E7D7C");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfiiii_func_001D817C(int, int, int, int) asm("func_001D817C");
extern "C" int Xii_func_001C6C28(int) asm("func_001C6C28");
extern "C" int Xii_func_001DA07C(int) asm("func_001DA07C");
extern "C" int Xiii_func_0017EA44(int, int) asm("func_0017EA44");
extern "C" int Xiii_func_001D89C4(int, int) asm("func_001D89C4");
extern "C" int Xiii_func_001D8D28(int, int) asm("func_001D8D28");
extern "C" int Xiiii_setActorRot__9MagSystemiPCf(int, int, int) asm("setActorRot__9MagSystemiPCf");
extern "C" int Xiiiii_func_001D8064(int, int, int, int) asm("func_001D8064");
extern int D_006FE6A0;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001333C0(...) asm("func_001333C0");
extern "C" int X_func_00139010(...) asm("func_00139010");
extern "C" int X_func_0017EA44(...) asm("func_0017EA44");
extern "C" int X_func_001C6C28(...) asm("func_001C6C28");
extern "C" int X_func_001CBB80(...) asm("func_001CBB80");
extern "C" int X_func_001D8064(...) asm("func_001D8064");
extern "C" int X_func_001D966C(...) asm("func_001D966C");
extern "C" int X_func_001DA07C(...) asm("func_001DA07C");
extern "C" int X_func_001E7414(...) asm("func_001E7414");
extern "C" int X_func_001E7724(...) asm("func_001E7724");
extern "C" int X_func_001E7D7C(...) asm("func_001E7D7C");
extern "C" int X_func_001E8F88(...) asm("func_001E8F88");
extern int D_00298EE0;
extern int D_002D8F60;
extern int D_006E9840;
extern int D_007812C0;
extern int D_007A320C;
extern int D_007A3D80;
extern int D_007B2060;

extern "C" void func_001D859C(int arg0, int arg1)
{
    Xii_heapFree__FPv(M2C_FIELD(arg0, int *, 4));
    Xii_heapFree__FPv(M2C_FIELD(arg0, int *, 8));
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

extern "C" void func_001D85F8(GamTrg0_d85f8 *arg0, unsigned short arg1, unsigned short arg2)
{
    unsigned int i;

    for (i = 0; i < arg0->count; i++) {
        if (arg0->unk08[i] == 0) {
            break;
        }
    }
    if (i < arg0->count) {
        arg0->unk08[i] = arg2;
        arg0->unk04[i] = arg1;
    }
}

extern "C" void func_001D8674(GamTrg0_d85f8 *arg0, int arg1)
{
    unsigned int i;

    for (i = 0; i < arg0->count; i++) {
        if (arg0->unk08[i] == arg1) {
            break;
        }
    }
    if (i < arg0->count) {
        arg0->unk04[i] = 0;
        arg0->unk08[i] = 0;
        while (i < arg0->count - 1 && arg0->unk08[i] == 0) {
            arg0->unk04[i] = arg0->unk04[i + 1];
            arg0->unk08[i] = arg0->unk08[i + 1];
            i++;
        }
        arg0->unk04[i] = 0;
        arg0->unk08[i] = 0;
    }
}

extern "C" int func_001D8778(GamTrg0_d8778 *arg0, int arg1)
{
    unsigned int i;
    int ret = arg0->unk0C;

    for (i = 0; i < arg0->count; i++) {
        if (arg0->unk08[i] == 0) {
            break;
        }
        if (arg1 == arg0->unk04[i]) {
            ret = arg0->unk08[i];
            break;
        }
    }
    return (i == arg0->count) ? 0 : ret;
}

extern "C" void func_001D87F4(ObjStat_d87f4 *arg0, int arg1, int arg2, int arg3, unsigned short arg4)
{
    arg0->m_vtbl = &X_vt_7ObjStat;
    arg0->m_pool.init(arg0->m_nodes, 8);
    arg0->m_oid = arg2;
    arg0->m_uid = arg4;
    arg0->m_chrID = arg3;
    arg0->m_curStat = arg1;
    arg0->m_secta = 0;
    arg0->m_unk110 = 0;
    arg0->m_areaNo = 0;
    arg0->m_flgV = 0;
}

extern int _vt$7ObjStat;
extern "C" void Xv_ObjStatDtor(int arg0, int arg1) asm("_$_7ObjStat");
extern "C" void Xv_ObjStatDtor(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x258) = (int)&_vt$7ObjStat;
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

extern "C" void func_001D88FC(int arg0)
{
    M2C_FIELD(arg0, int *, 0x114) = 0;
    M2C_FIELD(arg0, int *, 0x110) = 0;
    M2C_FIELD(arg0, int *, 0x10C) = 0;
}

extern "C" void func_001D890C(int arg0, int arg1)
{
    int temp_v1;
    int temp_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    if (temp_v1 == -1) {
        M2C_FIELD(arg1, float *, 0) = M2C_FIELD(arg0, float *, 0x190);
        M2C_FIELD(arg1, float *, 4) = M2C_FIELD(arg0, float *, 0x194);
        M2C_FIELD(arg1, float *, 8) = M2C_FIELD(arg0, float *, 0x198);
        return;
    }
    temp_v0 = (int)&D_006FE6A0 + (temp_v1 * 0x4D0);
    M2C_FIELD(arg1, float *, 0) = M2C_FIELD(temp_v0, float *, 0x40);
    M2C_FIELD(arg1, float *, 4) = M2C_FIELD(temp_v0, float *, 0x44);
    M2C_FIELD(arg1, float *, 8) = M2C_FIELD(temp_v0, float *, 0x48);
}

extern "C" void func_001D8964(int arg0, int arg1)
{
    int temp_v1;
    int temp_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    if (temp_v1 == -1) {
        M2C_FIELD(arg1, float *, 0) = M2C_FIELD(arg0, float *, 0x1A0);
        M2C_FIELD(arg1, float *, 4) = M2C_FIELD(arg0, float *, 0x1A4);
        M2C_FIELD(arg1, float *, 8) = M2C_FIELD(arg0, float *, 0x1A8);
        return;
    }
    temp_v0 = (int)&D_006FE6A0 + (temp_v1 * 0x4D0);
    M2C_FIELD(arg1, float *, 0) = M2C_FIELD(temp_v0, float *, 0x50);
    M2C_FIELD(arg1, float *, 4) = M2C_FIELD(temp_v0, float *, 0x54);
    M2C_FIELD(arg1, float *, 8) = M2C_FIELD(temp_v0, float *, 0x58);
}

extern "C" int func_001D89BC()
{
    return 0;
}


extern "C" void func_001D89C4(int arg0, int arg1)
{
    int temp_a4;
    int temp_a0;
    int temp_v0_2;
    int temp_v0;

    M2C_FIELD(arg0, float *, 0x190) = M2C_FIELD(arg1, float *, 0);
    M2C_FIELD(arg0, float *, 0x194) = M2C_FIELD(arg1, float *, 4);
    M2C_FIELD(arg0, float *, 0x198) = M2C_FIELD(arg1, float *, 8);
    temp_a4 = arg0 + 0x190;
    temp_a0 = M2C_FIELD(arg0, int *, 0x108);
    if (temp_a0 != -1) {
        temp_v0 = (int)&D_006FE6A0 + (temp_a0 * 0x4D0);
        M2C_FIELD(temp_v0, float *, 0x40) = M2C_FIELD(temp_a4, float *, 0);
        M2C_FIELD(temp_v0, float *, 0x44) = M2C_FIELD(temp_a4, float *, 4);
        M2C_FIELD(temp_v0, float *, 0x48) = M2C_FIELD(temp_a4, float *, 8);
        M2C_FIELD(temp_v0, int *, 0x90) = 1;
        temp_v0_2 = M2C_FIELD(arg0, int *, 0x114);
        if (temp_v0_2 == 0 || (M2C_FIELD(arg0, int *, 0x120) & 0x40)) {
            Xiii_func_001D8D28(arg0, Xiiiii_func_001D8064((int)&D_007812C0, temp_a4, temp_v0_2, (((unsigned int)M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2));
        }
    }
}

extern "C" void func_001D8A8C(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    M2C_FIELD(arg0, float *, 0x1A0) = (float) M2C_FIELD(arg1, float *, 0);
    M2C_FIELD(arg0, float *, 0x1A4) = (float) M2C_FIELD(arg1, float *, 4);
    M2C_FIELD(arg0, float *, 0x1A8) = (float) M2C_FIELD(arg1, float *, 8);
    if (temp_v1 != -1) {
        Xiiii_setActorRot__9MagSystemiPCf((int) (int)&D_006E9840, temp_v1, (int) (arg0 + 0x1A0));
    }
}

extern "C" int func_001D8ADC(int arg0, int arg1)
{
    int a = Xiiiii_func_001D8064((int)&D_007812C0, arg1, M2C_FIELD(arg0, int *, 0x114), (((unsigned int)M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2);
    if (a != 0) {
        Xiii_func_001D8D28(arg0, a);
        M2C_FIELD(arg1, float *, 4) = M2C_FIELD(arg0, float *, 0x194);
        Xiii_func_001D89C4(arg0, arg1);
        return 1;
    }
    return 0;
}

extern "C" int func_001D8B5C(int arg0, int arg1)
{
    return Xiiiii_func_001D8064((int)&D_007812C0, arg1, M2C_FIELD(arg0, int *, 0x114),
                                (((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2) != 0;
}

extern "C" void func_001D8B9C(int arg0, int arg1)
{
    float temp_f0;
    int temp_v0;

    temp_v0 = Xiiiii_func_001D8064((int) (int)&D_007812C0, (int) arg1, M2C_FIELD(arg0, int *, 0x114), (((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2);
    Xiii_func_001D8D28(arg0, temp_v0);
    temp_f0 = Xfiiii_func_001D817C((int) (int)&D_007812C0, (int) temp_v0, (int) arg1, 0);
    if (temp_f0 != 100000.0f) {
        M2C_FIELD(arg1, float *, 4) = temp_f0;
    }
    Xiii_func_001D89C4(arg0, arg1);
}

extern "C" float func_001D8C50(int arg0)
{
    int var_s2 = 0;

    if (M2C_FIELD(arg0, int *, 0x114) == 0) {
        int r = Xiu_func_001F6878(M2C_FIELD(arg0, unsigned int *, 0x100));
        Xvii_func_001D7EB8((int)&D_007812C0, r);
        var_s2 = Xiiii_func_001D7F48((int)&D_007812C0, arg0 + 0x190, 0);
        Xvii_func_001D7EB8((int)&D_007812C0, 0);
        if (var_s2 != 0) {
            Xvii_func_001D8D28(arg0, var_s2);
        } else {
            return 0.0f;
        }
    }
    Xvii_func_001D890C(arg0, arg0 + 0x190);
    return Xfiiii_func_001D817C((int)&D_007812C0, var_s2, arg0 + 0x190, 0);
}

extern "C" int func_001D8D28(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x120);
    if (temp_v1 & 0x40) {
        if (!(temp_v1 & 0x10000000)) {
            Xiiii_func_001D5BC8((int)&D_007812C0, arg1, M2C_FIELD(arg0, int *, 0x100));
        }
        M2C_FIELD(arg0, int *, 0x114) = arg1;
        M2C_FIELD(arg0, int *, 0x110) = arg1;
        if (arg1 != 0) {
            M2C_FIELD(arg0, int *, 0x10C) = arg1;
            M2C_FIELD(arg0, float *, 0x1F0) = (float) M2C_FIELD(arg0, float *, 0x190);
            M2C_FIELD(arg0, float *, 0x1F4) = (float) M2C_FIELD(arg0, float *, 0x194);
            M2C_FIELD(arg0, float *, 0x1F8) = (float) M2C_FIELD(arg0, float *, 0x198);
            M2C_FIELD(arg0, float *, 0x1FC) = (float) M2C_FIELD(arg0, float *, 0x19C);
        }
        return 1;
    }
    M2C_FIELD(arg0, int *, 0x114) = arg1;
    M2C_FIELD(arg0, int *, 0x110) = arg1;
    return 0;
}

extern "C" void func_001D8DC4(int arg0)
{
    int temp_v1;
    float temp_f1;
    float temp_f1_2;
    int temp_v0_3;
    int temp_a0;
    int temp_v0;
    int temp_v0_2;

    temp_v1 = arg0 + 0x190;
    temp_a0 = M2C_FIELD(arg0, int *, 0x108);
    if ((temp_a0 != -1) && ((temp_v0 = (int)&D_006FE6A0 + (temp_a0 * 0x4D0), temp_f1 = M2C_FIELD(temp_v0, float *, 0x40), M2C_FIELD(arg0, float *, 0x190) = temp_f1, M2C_FIELD(temp_v1, float *, 4) = (float) M2C_FIELD(temp_v0, float *, 0x44), M2C_FIELD(temp_v1, float *, 8) = (float) M2C_FIELD(temp_v0, float *, 0x48), temp_v0_2 = M2C_FIELD(arg0, int *, 0x114), (temp_v0_2 == 0)) || !(M2C_FIELD(temp_v0_2, float *, 0x1C) <= temp_f1) || !(temp_f1 <= M2C_FIELD(temp_v0_2, float *, 0x24)) || (temp_f1_2 = M2C_FIELD(arg0, float *, 0x198), !(M2C_FIELD(temp_v0_2, float *, 0x20) <= temp_f1_2)) || !(temp_f1_2 <= M2C_FIELD(temp_v0_2, float *, 0x28)))) {
        temp_v0_3 = Xiiiii_func_001D8064((int) (int)&D_007812C0, (int) temp_v1, (int) temp_v0_2, (((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2);
        if (temp_v0_3 != 0) {
            Xiii_func_001D8D28(arg0, (int) temp_v0_3);
        }
    }
}

extern "C" void func_001D8EA8(int arg0)
{
    int temp_v0;

    temp_v0 = Xiiiii_func_001D8064((int) (int)&D_007812C0, (int) (arg0 + 0x190), M2C_FIELD(arg0, int *, 0x114), (((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, int *, 0x110) = 0;
        Xiii_func_001D8D28(arg0, (int) temp_v0);
    }
}

// NON_MATCHING: 16/58 differ, 2 relocs differ, 8 edits
#ifdef NON_MATCHING
typedef u_long128 u_long128_d8f04;
extern "C" void func_001D8F04(int arg0, u_long128_d8f04 *arg1)
{
    int temp_a3;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    float temp_f1;
    float temp_f1_2;

    temp_v0 = (int)&D_006FE6A0 + (M2C_FIELD(arg0, int *, 0x108) * 0x4D0);
    temp_a3 = arg0 + 0x190;
    M2C_FIELD(temp_a3, float *, 0) = M2C_FIELD(temp_v0, float *, 0x40);
    M2C_FIELD(temp_a3, float *, 4) = M2C_FIELD(temp_v0, float *, 0x44);
    M2C_FIELD(temp_a3, float *, 8) = M2C_FIELD(temp_v0, float *, 0x48);
    *arg1 = *(u_long128_d8f04 *)temp_a3;
    temp_v0_2 = M2C_FIELD(arg0, int *, 0x114);
    int mgr = (int)&D_007812C0;
    if ((temp_v0_2 == 0) || (temp_f1 = *(float *)temp_a3, !(M2C_FIELD(temp_v0_2, float *, 0x1C) <= temp_f1)) || !(temp_f1 <= M2C_FIELD(temp_v0_2, float *, 0x24)) || (temp_f1_2 = M2C_FIELD(arg0, float *, 0x198), !(M2C_FIELD(temp_v0_2, float *, 0x20) <= temp_f1_2)) || !(temp_f1_2 <= M2C_FIELD(temp_v0_2, float *, 0x28))) {
        temp_v0_3 = Xiiiii_func_001D8064(mgr, temp_a3, temp_v0_2, (((unsigned int)M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2);
        if (temp_v0_3 != 0) {
            Xiii_func_001D8D28(arg0, temp_v0_3);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8F04);
#endif

extern "C" void func_001D8FEC(int arg0, int arg1)
{
    int buf[4];

    Xiii_func_001D8D28(arg0, Xiii_func_001D811C((int)&D_007812C0, arg1, (int)buf, 0));
    if (M2C_FIELD(arg0, int *, 0x114) != 0) {
        Xiii_func_001D89C4(arg0, (int)buf);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9044);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D932C);

// NON_MATCHING: 18/41 differ, 1 reloc differs (size 0xA4, game 0xA8), 11 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_001D8EA8(int) asm("func_001D8EA8");
extern "C" int Xiii_func_001D5DA0(int, int) asm("func_001D5DA0");
struct DogEntityStub_d95c4 {
    char pad0[0x94];
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(int);
};
extern "C" void func_001D95C4(int arg0, int arg1)
{
    int idx;

    if (arg1 != 0) {
        if (M2C_FIELD(arg0, int *, 0x120) & 0x40) {
            Xiii_func_001D5DA0((int)&D_007812C0, M2C_FIELD(arg0, int *, 0x100));
        }
    } else {
        if (M2C_FIELD(arg0, int *, 0x120) & 0x40) {
            Xii_func_001D8EA8(arg0);
        }
    }
    idx = M2C_FIELD(arg0, int *, 0x108);
    if (idx != -1) {
        ((DogEntityStub_d95c4 *)((idx * 0x4D0) + (int)&D_006FE6A0))->vf8(arg1 != 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D95C4);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D966C);

extern "C" void func_001D96E0(int arg0)
{
    M2C_FIELD(arg0, int *, 0x114) = 0;
    M2C_FIELD(arg0, int *, 0x110) = 0;
}

extern "C" int func_001D96EC(ObjStat_d96ec *arg0, GamTrgCopy_d96ec *arg1)
{
    if (*(int *)((char *)arg0 + 0x108) != -1) {
        getDogActor_d96ec(&D_006FBD80_d96ec, *(int *)((char *)arg0 + 0x108))->getPos((float *)((char *)arg0 + 0x190));
        getDogActor_d96ec(&D_006FBD80_d96ec, *(int *)((char *)arg0 + 0x108))->getRot((float *)((char *)arg0 + 0x1A0));
    }
    *arg1 = arg0->data;
    return 0xB0;
}

extern "C" int func_001D9830(int arg0, const GamTrgCopy_d9830 *arg1)
{
    *(GamTrgCopy_d9830 *)((char *)arg0 + 0x100) = *arg1;
    M2C_FIELD(arg0, int *, 0x10C) = 0;
    M2C_FIELD(arg0, int *, 0x110) = 0;
    M2C_FIELD(arg0, int *, 0x114) = 0;
    return 0xB0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9908);

extern "C" void func_001D9B2C(int arg0)
{
    Xiiii_memset(arg0 + 0x280, 0, 0x109);
    *(m2c_block8 *)((char *)(arg0) + 0x288) = *(m2c_block8 *)((char *)(&D_002FC418) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x290) = *(m2c_block8 *)((char *)(&D_002FC420) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x298) = *(m2c_block8 *)((char *)(&D_002FC428) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2a0) = *(m2c_block8 *)((char *)(&D_002FC430) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2a8) = *(m2c_block8 *)((char *)(&D_002FC438) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2b0) = *(m2c_block8 *)((char *)(&D_002FC440) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2b8) = *(m2c_block8 *)((char *)(&D_002FC448) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2c0) = *(m2c_block8 *)((char *)(&D_002FC450) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2d0) = *(m2c_block8 *)((char *)(&D_002FC458) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x340) = *(m2c_block8 *)((char *)(&D_002FC460) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2d8) = *(m2c_block8 *)((char *)(&D_002FC468) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2e0) = *(m2c_block8 *)((char *)(&D_002FC470) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2e8) = *(m2c_block8 *)((char *)(&D_002FC478) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2f0) = *(m2c_block8 *)((char *)(&D_002FC480) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2f8) = *(m2c_block8 *)((char *)(&D_002FC488) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x300) = *(m2c_block8 *)((char *)(&D_002FC490) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x308) = *(m2c_block8 *)((char *)(&D_002FC498) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x310) = *(m2c_block8 *)((char *)(&D_002FC4A0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x318) = *(m2c_block8 *)((char *)(&D_002FC4A8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x320) = *(m2c_block8 *)((char *)(&D_002FC4B0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x328) = *(m2c_block8 *)((char *)(&D_002FC4B8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x330) = *(m2c_block8 *)((char *)(&D_002FC4C0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x338) = *(m2c_block8 *)((char *)(&D_002FC4C8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x348) = *(m2c_block8 *)((char *)(&D_002FC4D0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x350) = *(m2c_block8 *)((char *)(&D_002FC4D8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x358) = *(m2c_block8 *)((char *)(&D_002FC4E0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x360) = *(m2c_block8 *)((char *)(&D_002FC4E8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x368) = *(m2c_block8 *)((char *)(&D_002FC4F0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x370) = *(m2c_block8 *)((char *)(&D_002FC4F8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x378) = *(m2c_block8 *)((char *)(&D_002FC500) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x380) = *(m2c_block8 *)((char *)(&D_002FC508) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x388) = *(m2c_block8 *)((char *)(&D_002FC510) + 0x0);
}

extern "C" void func_001D9E9C(int arg0)
{
    X_func_001D966C();
    if (X_func_001E7D7C((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E8))) != 0) {
        X_func_001E7724((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E8)));
    }
    if (X_func_001E7D7C((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E4))) != 0) {
        X_func_001E7724((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E4)));
    }
}


extern "C" void func_001D9F08(void) {
}

extern "C" void func_001D9F10(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x114) = 0;
    M2C_FIELD(arg0, int *, 0x110) = 0;
    if (arg1 != 0) {
        M2C_FIELD(arg0, int *, 0x10C) = 0;
    }
    Xii_func_001DA07C(arg0);
}

extern "C" void func_001D9F40(int arg0)
{
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3DC)) != 0) {
        return Xv_func_001E8F88(M2C_FIELD(arg0, int *, 0x3D0));
    }
}

// NON_MATCHING: 13/52 differ (size 0xD0, game 0xD8), 7 edits
#ifdef NON_MATCHING
extern "C" float Xfii_func_00133440(int, int) asm("func_00133440");
extern "C" int Xii_func_0010A834__8DogActor(int) asm("func_0010A834__8DogActor");
extern int D_006FBD80;
static inline int getDogActor_d9f84(void *base, int idx) { return (int)(((char *)base + idx * 0x4D0) + 0x2920); }
extern "C" int func_001D9F84(int arg0)
{
    int temp_s2 = Xii_func_0010A834__8DogActor(getDogActor_d9f84(&D_006FBD80, M2C_FIELD(arg0, int *, 0x108))) == 0;
    if (M2C_FIELD(arg0, int *, 0x120) & 0x100) {
        if (Xfii_func_00133440((int)&D_006FBD80, M2C_FIELD(arg0, int *, 0x108)) < 0.0f) {
            if (Xfii_func_00133440((int)&D_006FBD80, M2C_FIELD(arg0, int *, 0x108)) >= -0.0000001f) {
                return 0;
            }
        } else {
            if (Xfii_func_00133440((int)&D_006FBD80, M2C_FIELD(arg0, int *, 0x108)) <= 0.0000001f) {
                return 0;
            }
        }
    }
    return temp_s2;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9F84);
#endif

extern "C" int func_001DA05C(int arg0)
{
    return ~(*(int *)(int *)((char *)(arg0) + 0x3D8)) == 0;
}


extern "C" void func_001DA06C(void) {
}

extern "C" void func_001DA074(void) {
}

extern "C" void func_001DA07C(int arg0)
{
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3DC)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3DC));
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D4)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D4));
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3E0)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3E0));
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D8)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D8));
    }
    M2C_FIELD(arg0, int *, 0x3DC) = -1;
    M2C_FIELD(arg0, int *, 0x3D4) = -1;
    M2C_FIELD(arg0, int *, 0x3E0) = -1;
    M2C_FIELD(arg0, int *, 0x3D8) = -1;
}

extern "C" void func_001DA130(int arg0, int arg1, int arg2)
{
    if (arg2 != 0) {
        X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3DC)), arg1);
    }
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3D4)), arg1);
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3E0)), arg1);
    X_func_001E7414((int)&D_007A3D80, (*(int *)(int *)((char *)(arg0) + 0x3D8)), arg1);
}


extern "C" void func_001DA1B4(int arg0)
{
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D4)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3D4));
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3E0)) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, M2C_FIELD(arg0, int *, 0x3E0));
    }
    M2C_FIELD(arg0, int *, 0x3D4) = -1;
    M2C_FIELD(arg0, int *, 0x3E0) = -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DA228);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DA740);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC418);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC420);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC428);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC430);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC438);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC440);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC448);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC450);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC458);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC460);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC468);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC470);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC478);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC480);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC488);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC490);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC498);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4D0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4F0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC500);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC508);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC510);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DAC8C);

extern "C" int func_001DB17C(int arg0, int arg1)
{
    return (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x1B0));
}


extern "C" void func_001DB18C(int arg0, int arg1, int arg2)
{
    (*(int *)(int *)((char *)(((arg1 * 4) + arg0)) + 0x1B0)) = arg2;
}


extern "C" void func_001DB19C(int arg0, int arg1, int arg2)
{
    int off;

    off = arg1 * 4 + 0x1B0;
    M2C_FIELD(arg0 + off, int *, 0) += arg2;
}

extern "C" void func_001DB1B8(int arg0, float fparg0)
{
    int off = 0x12540;

    M2C_FIELD(arg0, float *, 0x418) = fparg0;
    Xiiif_func_001333C0((int)&D_006E9840 + off, M2C_FIELD(arg0, int *, 0x108), fparg0);
}

// NON_MATCHING: 7/75 differ, 4 edits
#ifdef NON_MATCHING
struct Copy48_db1f0 {
    long long d0;
    long long d1;
    long long d2;
    long long d3;
    long long d4;
    long long d5;
}; // db1f0
struct Unq_db1f0 {
    unsigned char pad0[0x48];
    unsigned short f48;
    unsigned short f4A;
    unsigned short f4C;
    unsigned char pad4E[0x70 - 0x4E];
    float f70;
    unsigned char pad74[0x80 - 0x74];
    unsigned char f80[0x30];
    int fB0;
}; // db1f0
struct Obj_db1f0 {
    unsigned char pad0[0x110];
    int f110;
    int f114;
    float f118;
    int pad11C;
    int f120;
    unsigned char pad124[6];
    unsigned short f12A;
    unsigned short f12C;
    unsigned short f12E;
    unsigned char pad130[4];
    int f134;
    int f138;
    int f13C;
    unsigned char pad140[0x10];
    union { Copy48_db1f0 c; struct { int f0; int f4; } s; } f150;
    unsigned char pad180[0x220 - 0x180];
    Copy48_db1f0 f220;
    int pad250;
    int f254;
    unsigned char pad258[0x280 - 0x258];
    Unq_db1f0 *f280;
    void *f284;
    Unq_db1f0 *f288;
    int f28C;
    short f290;
    short pad292;
    int f294;
}; // db1f0
struct GamMan_db1f0 {
    unsigned char pad0[0x22220];
    unsigned char m_unq[4];
}; // db1f0
extern GamMan_db1f0 X_gm_db1f0 asm("D_007812C0"); // db1f0
extern "C" Unq_db1f0 *X_func_001DBFA0(void *, unsigned short) asm("func_001DBFA0"); // db1f0
static inline void *gamSub22220_db1f0() { void *p = (void *)&X_gm_db1f0; return (char *)p + 0x22220; } // db1f0
extern "C" void func_001DB1F0(Obj_db1f0 *arg0, int arg1)
{
    unsigned short id = arg1;
    arg0->f150.s.f0 = 2;
    arg0->f150.s.f4 = 2;
    arg0->f220 = arg0->f150.c;
    arg0->f114 = 0;
    arg0->f110 = 0;
    arg0->f138 = -1;
    arg0->f13C = -1;
    arg0->f254 = -1;
    arg0->f120 = 0;
    arg0->f280 = 0;

    switch (id >> 9) {
    case 6:
    case 7:
    case 8:
        break;
    case 4:
        arg0->f120 = 0;
        break;
    case 5: {
        Unq_db1f0 *p = X_func_001DBFA0(gamSub22220_db1f0(), id);
        arg0->f134 = 0;
        arg0->f288 = p;
        arg0->f284 = p->f80;
        arg0->f120 = p->fB0;
        arg0->f290 = 1;
        arg0->f280 = p;
        break;
    }
    case 9:
        arg0->f28C = -1;
        arg0->f294 = -1;
        break;
    }

    if (arg0->f280 != 0) {
        arg0->f12A = arg0->f280->f48;
        arg0->f12C = arg0->f280->f4A;
        arg0->f12E = arg0->f280->f4C;
        arg0->f118 = arg0->f280->f70;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB1F0);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB31C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB520);

extern "C" void func_001DB71C(int arg0, int arg1)
{
    int temp_v1;
    int temp_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    if (temp_v1 == -1) {
        M2C_FIELD(arg1, float *, 0) = M2C_FIELD(arg0, float *, 0x190);
        M2C_FIELD(arg1, float *, 4) = M2C_FIELD(arg0, float *, 0x194);
        M2C_FIELD(arg1, float *, 8) = M2C_FIELD(arg0, float *, 0x198);
        return;
    }
    temp_v0 = (int)&D_006FE6A0 + (temp_v1 * 0x4D0);
    M2C_FIELD(arg1, float *, 0) = M2C_FIELD(temp_v0, float *, 0x40);
    M2C_FIELD(arg1, float *, 4) = M2C_FIELD(temp_v0, float *, 0x44);
    M2C_FIELD(arg1, float *, 8) = M2C_FIELD(temp_v0, float *, 0x48);
}

extern "C" void func_001DB774(int arg0, int arg1)
{
    int temp_v1;
    int temp_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    if (temp_v1 == -1) {
        M2C_FIELD(arg1, float *, 0) = M2C_FIELD(arg0, float *, 0x1A0);
        M2C_FIELD(arg1, float *, 4) = M2C_FIELD(arg0, float *, 0x1A4);
        M2C_FIELD(arg1, float *, 8) = M2C_FIELD(arg0, float *, 0x1A8);
        return;
    }
    temp_v0 = (int)&D_006FE6A0 + (temp_v1 * 0x4D0);
    M2C_FIELD(arg1, float *, 0) = M2C_FIELD(temp_v0, float *, 0x50);
    M2C_FIELD(arg1, float *, 4) = M2C_FIELD(temp_v0, float *, 0x54);
    M2C_FIELD(arg1, float *, 8) = M2C_FIELD(temp_v0, float *, 0x58);
}

extern "C" void func_001DB7CC(int arg0, int arg1)
{
    int temp_a0;
    int temp_a2;
    int temp_v0_2;
    int temp_v0;

    M2C_FIELD(arg0, float *, 0x190) = M2C_FIELD(arg1, float *, 0);
    M2C_FIELD(arg0, float *, 0x194) = M2C_FIELD(arg1, float *, 4);
    M2C_FIELD(arg0, float *, 0x198) = M2C_FIELD(arg1, float *, 8);
    temp_a0 = arg0 + 0x190;
    temp_a2 = M2C_FIELD(arg0, int *, 0x108);
    if (temp_a2 != -1) {
        temp_v0 = (int)&D_006FE6A0 + (temp_a2 * 0x4D0);
        M2C_FIELD(temp_v0, float *, 0x40) = M2C_FIELD(temp_a0, float *, 0);
        M2C_FIELD(temp_v0, float *, 0x44) = M2C_FIELD(temp_a0, float *, 4);
        M2C_FIELD(temp_v0, float *, 0x48) = M2C_FIELD(temp_a0, float *, 8);
        M2C_FIELD(temp_v0, int *, 0x90) = 1;
    }
    temp_v0_2 = M2C_FIELD(arg0, int *, 0x114);
    if ((temp_v0_2 == 0) || (M2C_FIELD(arg0, int *, 0x120) & 0x40)) {
        Xiii_func_001D8D28(arg0, Xiiiii_func_001D8064((int)&D_007812C0, temp_a0, temp_v0_2, (((unsigned int)M2C_FIELD(arg0, unsigned int *, 0x100) >> 0x17) & 0x1F) == 2));
    }
}

extern "C" void func_001DB898(int arg0, int arg1)
{
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0x108);
    M2C_FIELD(arg0, float *, 0x1A0) = (float) M2C_FIELD(arg1, float *, 0);
    M2C_FIELD(arg0, float *, 0x1A4) = (float) M2C_FIELD(arg1, float *, 4);
    M2C_FIELD(arg0, float *, 0x1A8) = (float) M2C_FIELD(arg1, float *, 8);
    if (temp_v1 != -1) {
        Xiiii_setActorRot__9MagSystemiPCf((int) (int)&D_006E9840, temp_v1, (int) (arg0 + 0x1A0));
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC6E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC700);

// NON_MATCHING: 1 reloc differs, 1 edits
#ifdef NON_MATCHING
extern "C" int func_001DB8E8(int arg0, unsigned int arg1, int arg2)
{
    int var_v0;

    if (Xii_func_001C6C28((int)&D_007812C0) != -1) {
        if (arg2 == -1) {
            var_v0 = Xiii_func_0017EA44((int)&D_00298EE0, Xii_func_001C6C28((int)&D_007812C0));
        } else {
            var_v0 = Xiii_func_0017EA44((int)&D_00298EE0, arg2);
        }
        if (var_v0 != 0) {
            switch (arg1) {
            case 0:
                return M2C_FIELD(var_v0, int *, 8);
            case 2:
                return M2C_FIELD(var_v0, int *, 0x10);
            case 3:
                return M2C_FIELD(var_v0, int *, 0x14);
            case 1:
            case 4:
                return M2C_FIELD(var_v0, int *, 0xC);
            }
        }
    }
    return D_002D8F60;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB8E8);
#endif

extern "C" float func_001DB9C4()
{
    float var_f0;
    int temp_v0;

    temp_v0 = Xiii_func_0017EA44((int)&D_00298EE0, Xii_func_001C6C28((int)&D_007812C0));
    var_f0 = 0.0f;
    if (temp_v0 != 0) {
        var_f0 = M2C_FIELD(temp_v0, float *, 0x20);
    }
    return var_f0;
}

extern "C" float func_001DBA00()
{
    float var_f0;
    int temp_v0;

    temp_v0 = Xiii_func_0017EA44((int)&D_00298EE0, Xii_func_001C6C28((int)&D_007812C0));
    var_f0 = 0.0f;
    if (temp_v0 != 0) {
        var_f0 = M2C_FIELD(temp_v0, float *, 0x28);
    }
    return var_f0;
}

// NON_MATCHING: function matches (.text 0xfc MATCH), whole-object .rodata +8 jtbl alignment
#ifdef NON_MATCHING
extern "C" void Xvvvv_func_0017EB3C(int, void *, int, int) asm("func_0017EB3C");
extern "C" void Xvvvv_func_0017EBAC(int, void *, int, int) asm("func_0017EBAC");
extern "C" void func_001DBA3C(int arg0, unsigned int arg1, void *arg2, int arg3)
{
    int temp_v0;

    switch (arg1) {
    case 0:
        Xvvvv_func_0017EBAC((int)&D_00298EE0, arg2, arg3, Xii_func_001C6C28((int)&D_007812C0));
        return;
    case 1:
        Xvvvv_func_0017EB3C((int)&D_00298EE0, arg2, Xii_func_001C6C28((int)&D_007812C0), arg3);
        return;
    case 2:
        temp_v0 = Xiii_func_0017EA44((int)&D_00298EE0, Xii_func_001C6C28((int)&D_007812C0));
        M2C_FIELD(arg2, float *, 0) = M2C_FIELD(temp_v0, float *, 0x20);
        M2C_FIELD(arg2, float *, 4) = 0.0f;
        M2C_FIELD(arg2, float *, 8) = M2C_FIELD(temp_v0, float *, 0x28);
        return;
    case 3:
    case 4:
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBA3C);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBB38);

// NON_MATCHING: 44/56 differ, 1 reloc differs (size 0xE0, game 0xE8), 30 edits
#ifdef NON_MATCHING
typedef u_long128 u_long128_dbb74;
typedef float Vec4_dbb74[4] __attribute__((aligned(16)));
struct MapBounds_dbb74 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
};
extern MapBounds_dbb74 X_D_002FC748[] asm("D_002FC748");
extern "C" float Xfi_func_001DBA00(int) asm("func_001DBA00");
extern "C" void func_001DBB74(int arg0, int arg1, const Vec4_dbb74 arg2, Vec4_dbb74 arg3)
{
    Vec4_dbb74 v;
    float temp_f20;
    float temp_f0;
    MapBounds_dbb74 *p;

    temp_f20 = func_001DB9C4();
    temp_f0 = Xfi_func_001DBA00(arg0);
    do {
        *(u_long128_dbb74 *)v = *(const u_long128_dbb74 *)arg2;
    } while (0);
    p = &X_D_002FC748[arg1];
    v[2] = ((p->unkC * (v[2] + temp_f0)) / p->unk4) + p->unk14;
    v[0] = ((p->unk8 * -(v[0] + temp_f20)) / p->unk0) + p->unk10;
    do {
        *(u_long128_dbb74 *)arg3 = *(u_long128_dbb74 *)v;
    } while (0);
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBB74);
#endif

// NON_MATCHING: 31/34 differ, 1 reloc differs (size 0x88, game 0x94), 29 edits
#ifdef NON_MATCHING
typedef u_long128 u_long128_dbc5c;
union Vec4_dbc5c {
    u_long128_dbc5c q;
    float f[4];
};
struct MapBounds_dbc5c {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
};
extern MapBounds_dbc5c D_002FC748[];
extern "C" void func_001DBC5C(int arg0, int arg1, const Vec4_dbc5c *arg2, Vec4_dbc5c *arg3)
{
    Vec4_dbc5c v;
    MapBounds_dbc5c *p;

    v.q = arg2->q;
    p = &D_002FC748[arg1];
    v.f[0] = (p->unk8 * -v.f[0]) / p->unk0 + p->unk10;
    v.f[2] = (p->unkC * v.f[2]) / p->unk4 + p->unk14;
    arg3->q = v.q;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBC5C);
#endif

extern "C" void func_001DBCF0(int arg0)
{
    int temp_v0;

    temp_v0 = Xiii_func_0017EA44((int)&D_00298EE0, Xii_func_001C6C28((int)&D_007812C0));
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, int *, 0x1D0) = 0;
        return;
    }
    M2C_FIELD(arg0, int *, 0x1D0) = (int) M2C_FIELD(temp_v0, int *, 0x18);
    M2C_FIELD(arg0, int *, 0x1C0) = (int) M2C_FIELD(temp_v0, int *, 0x1C);
}

extern "C" void func_001DBD4C(void) {
}

extern "C" int func_001DBD54(int arg0)
{
    int base = (int)&D_007812C0;

    if ((M2C_FIELD(base + 0x21F4C, int *, 0) & 0x40000) == 0) {
        return M2C_FIELD(arg0, int *, 0x1C0);
    }
    return M2C_FIELD(base + 0x21F58, int *, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBD90);

// NON_MATCHING: 61/66 differ, 5 relocs differ (size 0x108, game 0x100), 43 edits
#ifdef NON_MATCHING
typedef u_long128 u_long128_dbdf0;
struct GamMan_dbdf0 {
    unsigned char pad0[0x21F4C];
    unsigned int m_sysFlg2;
    unsigned char pad1[0x22020 - 0x21F50];
    float m_pcPos[4] __attribute__((aligned(16)));
    float m_pcRot[4] __attribute__((aligned(16)));
    bool chkSysFlg2(unsigned int theFlg) const { return (m_sysFlg2 & theFlg) != 0; }
    void getPcPos(float (&thePos)[4]) const { *(u_long128_dbdf0 *)thePos = *(const u_long128_dbdf0 *)m_pcPos; }
    void getPcRot(float (&theRot)[4]) const { *(u_long128_dbdf0 *)theRot = *(const u_long128_dbdf0 *)m_pcRot; }
}; // dbdf0
struct Marker_dbdf0 {
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    float vec[4] __attribute__((aligned(16)));
}; // dbdf0
extern "C" int Xii_func_001C6C38(GamMan_dbdf0 *) asm("func_001C6C38");
extern "C" void Xviiiii_func_001DBB74(int, int, float *, float *) asm("func_001DBB74");
extern "C" void Xvi_func_00144418(float *) asm("func_00144418");
extern "C" void Xvi_func_0014448C(float *) asm("func_0014448C");
extern "C" int func_001DBDF0(int arg0, int arg1, Marker_dbdf0 *arg2)
{
    int ret = 0;
    float v0[4] __attribute__((aligned(16)));
    float v1[4] __attribute__((aligned(16)));

    if (!((GamMan_dbdf0 *)&D_007812C0)->chkSysFlg2(0x40000)) {
        int s1 = Xii_func_001C6C38((GamMan_dbdf0 *)&D_007812C0);
        arg2->unk04 = 1;
        ((GamMan_dbdf0 *)&D_007812C0)->getPcPos(v0);
        ((GamMan_dbdf0 *)&D_007812C0)->getPcRot(v1);
        Xviiiii_func_001DBB74(arg0, s1, v0, arg2->vec);
        arg2->unk0C = v1[1];
        arg2++;
        arg2->unk04 = 2;
        Xvi_func_00144418(v0);
        Xvi_func_0014448C(v1);
        Xviiiii_func_001DBB74(arg0, s1, v0, arg2->vec);
        arg2->unk0C = v1[1];
        ret = 2;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBDF0);
#endif

extern "C" void func_001DBEF0(void) {
}

extern "C" void func_001DBEF8(int arg0, int arg1)
{
    int temp_a2;
    int temp_a1;
    int temp_v1;

    M2C_FIELD(arg0, int *, 0x58) = arg1;
    temp_a1 = arg1 + 0x10;
    temp_v1 = arg1 + 0x40;
    temp_a2 = M2C_FIELD(arg1, int *, 0x10);
    M2C_FIELD(arg0, int *, 0) = temp_v1;
    M2C_FIELD(arg0, int *, 4) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 4) - temp_a2));
    M2C_FIELD(arg0, int *, 8) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 8) - temp_a2));
    M2C_FIELD(arg0, int *, 0xC) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0xC) - temp_a2));
    M2C_FIELD(arg0, int *, 0x10) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x10) - temp_a2));
    M2C_FIELD(arg0, int *, 0x14) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x14) - temp_a2));
    M2C_FIELD(arg0, int *, 0x18) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x18) - temp_a2));
    M2C_FIELD(arg0, int *, 0x1C) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x1C) - temp_a2));
    M2C_FIELD(arg0, int *, 0x20) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x20) - temp_a2));
    M2C_FIELD(arg0, int *, 0x24) = (int) (temp_v1 + (M2C_FIELD(temp_a1, int *, 0x24) - temp_a2));
}

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC748);

// NON_MATCHING: 1 reloc differs, 1 edits
#ifdef NON_MATCHING
extern "C" int func_001DBFA0(int *arg0, unsigned short arg1)
{
    int idx = arg1 & 0x1FF;
    switch (arg1 >> 9) {
    case 0:
        return arg0[0] + idx * 0xA0;
    case 1:
        return arg0[1] + idx * 0xA0;
    case 2:
        return arg0[2] + idx * 0xC0;
    case 3:
        return arg0[3] + idx * 0xE0;
    case 4:
        return arg0[4] + idx * 0xC0;
    case 5:
        return arg0[5] + idx * 0x200;
    case 6:
        return arg0[6] + idx * 0xC0;
    case 7:
        return arg0[7] + idx * 0xC0;
    case 8:
        return arg0[8] + idx * 0xC0;
    case 9:
        return arg0[9] + idx * 0xC0;
    default:
        return 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBFA0);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DC070);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DC48C);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD0F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD100);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD110);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD190);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD2A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD320);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD3A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD480);

// NON_MATCHING: 12/62 differ, 1 reloc differs, 13 edits
#ifdef NON_MATCHING
struct S_A0_dcd38 { char pad[0x90]; int val; char pad2[0xC]; };
struct S_C0_90_dcd38 { char pad[0x90]; int val; char pad2[0x2C]; };
struct S_E0_dcd38 { char pad[0x90]; int val; char pad2[0x4C]; };
struct S_C0_B0_dcd38 { char pad[0xB0]; int val; char pad2[0xC]; };
struct S_200_dcd38 { char pad[0xB0]; int val; char pad2[0x14C]; };
struct Mgr_dcd38 { S_A0_dcd38 *a0; S_A0_dcd38 *a1; S_C0_90_dcd38 *a2; S_E0_dcd38 *a3; S_C0_B0_dcd38 *a4; S_200_dcd38 *a5; S_C0_B0_dcd38 *a6; S_C0_B0_dcd38 *a7; S_C0_B0_dcd38 *a8; S_C0_B0_dcd38 *a9; };
extern "C" void func_001DCD38(Mgr_dcd38 *arg0, unsigned short arg1, int arg2)
{
    unsigned int idx = arg1 & 0x1FF;

    switch (arg1 >> 9) {
    case 0:
        arg0->a0[idx].val |= arg2;
        return;
    case 1:
        arg0->a1[idx].val |= arg2;
        return;
    case 2:
        arg0->a2[idx].val |= arg2;
        return;
    case 3:
        arg0->a3[idx].val |= arg2;
        return;
    case 4:
        arg0->a4[idx].val |= arg2;
        return;
    case 5:
        arg0->a5[idx].val |= arg2;
        return;
    case 6:
        arg0->a6[idx].val |= arg2;
        return;
    case 7:
        arg0->a7[idx].val |= arg2;
        return;
    case 8:
        arg0->a8[idx].val |= arg2;
        return;
    case 9:
        arg0->a9[idx].val |= arg2;
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DCD38);
#endif

// NON_MATCHING: 1 reloc differs, 1 edits
#ifdef NON_MATCHING
struct S_A0_dce30 { char pad[0x90]; int val; char pad2[0xC]; };
struct S_C0_90_dce30 { char pad[0x90]; int val; char pad2[0x2C]; };
struct S_E0_dce30 { char pad[0x90]; int val; char pad2[0x4C]; };
struct S_C0_B0_dce30 { char pad[0xB0]; int val; char pad2[0xC]; };
struct S_200_dce30 { char pad[0xB0]; int val; char pad2[0x14C]; };
struct Mgr_dce30 { S_A0_dce30 *a0; S_A0_dce30 *a1; S_C0_90_dce30 *a2; S_E0_dce30 *a3; S_C0_B0_dce30 *a4; S_200_dce30 *a5; S_C0_B0_dce30 *a6; S_C0_B0_dce30 *a7; S_C0_B0_dce30 *a8; S_C0_B0_dce30 *a9; };
extern "C" void func_001DCE30(Mgr_dce30 *arg0, unsigned short arg1, int arg2)
{
    int idx = arg1 & 0x1FF;

    switch (arg1 >> 9) {
    case 0: { S_A0_dce30 *p = arg0->a0; p += idx; p->val &= ~arg2; return; }
    case 1: { S_A0_dce30 *p = arg0->a1; p += idx; p->val &= ~arg2; return; }
    case 2: { S_C0_90_dce30 *p = arg0->a2; p += idx; p->val &= ~arg2; return; }
    case 3: { S_E0_dce30 *p = arg0->a3; p += idx; p->val &= ~arg2; return; }
    case 4: { S_C0_B0_dce30 *p = arg0->a4; p += idx; p->val &= ~arg2; return; }
    case 5: { S_200_dce30 *p = arg0->a5; p += idx; p->val &= ~arg2; return; }
    case 6: { S_C0_B0_dce30 *p = arg0->a6; p += idx; p->val &= ~arg2; return; }
    case 7: { S_C0_B0_dce30 *p = arg0->a7; p += idx; p->val &= ~arg2; return; }
    case 8: { S_C0_B0_dce30 *p = arg0->a8; p += idx; p->val &= ~arg2; return; }
    case 9: { S_C0_B0_dce30 *p = arg0->a9; p += idx; p->val &= ~arg2; return; }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DCE30);
#endif

// NON_MATCHING: 24/55 differ, 1 reloc differs (size 0xDC, game 0xE4), 19 edits
#ifdef NON_MATCHING
extern "C" int func_001DCF28(char **arg0, unsigned short arg1)
{
    int idx = arg1 & 0x1FF;

    switch (arg1 >> 9) {
    case 0: {
        char *p = arg0[0];
        return *(int *)(p + idx * 0xA0 + 0x90);
    }
    case 1: {
        char *p = arg0[1];
        return *(int *)(p + idx * 0xA0 + 0x90);
    }
    case 2: {
        char *p = arg0[2];
        return *(int *)(p + idx * 0xC0 + 0x90);
    }
    case 3: {
        char *p = arg0[3];
        return *(int *)(p + idx * 0xE0 + 0x90);
    }
    case 4: {
        char *p = arg0[4];
        return *(int *)(p + idx * 0xC0 + 0xB0);
    }
    case 5: {
        char *p = arg0[5];
        return *(int *)(p + idx * 0x200 + 0xB0);
    }
    case 6: {
        char *p = arg0[6];
        return *(int *)(p + idx * 0xC0 + 0xB0);
    }
    case 7: {
        char *p = arg0[7];
        return *(int *)(p + idx * 0xC0 + 0xB0);
    }
    case 8: {
        char *p = arg0[8];
        return *(int *)(p + idx * 0xC0 + 0xB0);
    }
    case 9: {
        char *p = arg0[9];
        return *(int *)(p + idx * 0xC0 + 0xB0);
    }
    default:
        return 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DCF28);
#endif

// NON_MATCHING: 1 reloc differs, 1 edits
#ifdef NON_MATCHING
struct S_A0_dd00c { char pad[0x90]; int val; char pad2[0xC]; }; // dd00c
struct S_C0_90_dd00c { char pad[0x90]; int val; char pad2[0x2C]; }; // dd00c
struct S_E0_dd00c { char pad[0x90]; int val; char pad2[0x4C]; }; // dd00c
struct S_C0_B0_dd00c { char pad[0xB0]; int val; char pad2[0xC]; }; // dd00c
struct S_200_dd00c { char pad[0xB0]; int val; char pad2[0x14C]; }; // dd00c
struct Mgr_dd00c { S_A0_dd00c *a0; S_A0_dd00c *a1; S_C0_90_dd00c *a2; S_E0_dd00c *a3; S_C0_B0_dd00c *a4; S_200_dd00c *a5; S_C0_B0_dd00c *a6; S_C0_B0_dd00c *a7; S_C0_B0_dd00c *a8; S_C0_B0_dd00c *a9; }; // dd00c
extern "C" int func_001DD00C(Mgr_dd00c *arg0, unsigned short arg1, int arg2)
{
    int idx = arg1 & 0x1FF;

    switch (arg1 >> 9) {
    case 0: { S_A0_dd00c *p = arg0->a0; p += idx; return (p->val & arg2) != 0; }
    case 1: { S_A0_dd00c *p = arg0->a1; p += idx; return (p->val & arg2) != 0; }
    case 2: { S_C0_90_dd00c *p = arg0->a2; p += idx; return (p->val & arg2) != 0; }
    case 3: { S_E0_dd00c *p = arg0->a3; p += idx; return (p->val & arg2) != 0; }
    case 4: { S_C0_B0_dd00c *p = arg0->a4; p += idx; return (p->val & arg2) != 0; }
    case 5: { S_200_dd00c *p = arg0->a5; p += idx; return (p->val & arg2) != 0; }
    case 6: { S_C0_B0_dd00c *p = arg0->a6; p += idx; return (p->val & arg2) != 0; }
    case 7: { S_C0_B0_dd00c *p = arg0->a7; p += idx; return (p->val & arg2) != 0; }
    case 8: { S_C0_B0_dd00c *p = arg0->a8; p += idx; return (p->val & arg2) != 0; }
    case 9: { S_C0_B0_dd00c *p = arg0->a9; p += idx; return (p->val & arg2) != 0; }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD00C);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD118);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD154);

extern "C" int func_001DD194(int arg0, unsigned short arg1, int arg2, int arg3)
{
    unsigned int hi;
    unsigned int idx;

    hi = arg1 >> 9;
    idx = arg1 & 0x1FF;
    if (hi == 2) {
        int temp_v0 = M2C_FIELD(arg0, int *, 8) + idx * 0xC0;
        return (M2C_FIELD(temp_v0, int *, 0x94) & arg3) != 0;
    }
    return 0;
}

extern "C" void func_001DD1D8(void) {
}

extern "C" void func_001DD1E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD1E8);

extern "C" void func_001DD3EC(void *arg0, int arg1)
{
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void func_001DD414(Mgr_dd414 *arg0)
{
    Pool_dd414 *p = new Pool_dd414(64);
    arg0->m_pool = p;
    if (p->size() != 0) {
        p->clear();
    }
}

extern "C" GamTrgCopy_dd558 *func_001DD558(int arg0, const GamTrgCopy_dd558 *arg1)
{
    GamTrgCopy_dd558 *p = (GamTrgCopy_dd558 *)Xiiiiiii_alloc__9BedMemoryiPCciii((int)&D_006E9800, 0xB0, (int)"game/gamtrg.cpp", 0x62, 0, 1);
    *p = *arg1;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD5E8);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD7BC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDAA8);

// NON_MATCHING: 11/75 differ, 12 edits
#ifdef NON_MATCHING
struct Elem_ddc80 { unsigned int u0[8]; unsigned int flg; unsigned int u24[2]; int id; unsigned int u30[(0xB0 - 0x30) / 4]; } __attribute__((aligned(16)));
struct Node_ddc80 { Node_ddc80 *m_prev; Node_ddc80 *m_next; Elem_ddc80 m_data; };
struct Chain_ddc80 {
    Node_ddc80 m_head;
    int m_num;
    void push_back(Node_ddc80 *theNode) {
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
    void unlink(Node_ddc80 *theNode) {
        if (theNode == m_head.m_next) {
            Node_ddc80 *next = theNode->m_next;
            m_head.m_next = next;
            next->m_prev = &m_head;
        } else {
            Node_ddc80 *p = theNode->m_prev;
            if (theNode == m_head.m_prev) {
                m_head.m_prev = p;
                p->m_next = &m_head;
            } else {
                p->m_next = theNode->m_next;
                theNode->m_next->m_prev = theNode->m_prev;
            }
        }
        --m_num;
    }
};
struct Iter_ddc80 {
    Node_ddc80 *m_node;
    Iter_ddc80() : m_node(0) {}
    Iter_ddc80(Node_ddc80 *n) : m_node(n) {}
    Iter_ddc80(const Iter_ddc80 &o) : m_node(o.m_node) {}
    Elem_ddc80 &operator*() const { return m_node->m_data; }
    Iter_ddc80 &operator++() { m_node = m_node->m_next; return *this; }
    bool operator!=(const Iter_ddc80 &o) const { return m_node != o.m_node; }
};
struct List_ddc80 {
    Chain_ddc80 m_free;
    Chain_ddc80 m_used;
    int m_max;
    Iter_ddc80 begin() { return Iter_ddc80(m_used.m_head.m_next); }
    Iter_ddc80 end() { return Iter_ddc80(&m_used.m_head); }
    int size() const { return m_used.m_num; }
    Iter_ddc80 erase(Iter_ddc80 it) {
        Iter_ddc80 next(it);
        ++next;
        Node_ddc80 *node = it.m_node;
        m_used.unlink(node);
        m_free.push_back(node);
        return next;
    }
};
struct Mgr_ddc80 { char pad[0xC1C0]; List_ddc80 list; };
extern "C" void Xii_func_001DDDAC(int) asm("func_001DDDAC");
extern "C" void X_func_001DDC80(Mgr_ddc80 *) asm("func_001DDC80");
extern "C" void X_func_001DDC80(Mgr_ddc80 *arg0)
{
    Iter_ddc80 it;
    Iter_ddc80 last;
    if (arg0->list.size() != 0) {
        it = arg0->list.begin();
        last = arg0->list.end();
        while (it != last) {
            it = arg0->list.erase(it);
        }
    }
    Xii_func_001DDDAC((int)arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDC80);
#endif

extern "C" void func_001DDDAC(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x18B5C)) = 0;
}


extern "C" void func_001DDDBC(Mgr_dddbc *arg0, int arg1)
{
    Iter_dddbc it;
    Iter_dddbc last;

    if (arg0->list.size() != 0) {
        it = arg0->list.begin();
        last = arg0->list.end();
        while (it != last) {
            switch (arg1) {
            case 0:
            case 1:
            default:
                break;
            case 2:
                if (((*it).flg2C >> 30) == 1) {
                    ++it;
                    continue;
                }
                break;
            case 3:
                if (((*it).flg2C >> 30) != 3) {
                    ++it;
                    continue;
                }
                break;
            }
            it = arg0->list.erase(it);
        }
    }
    Xii_func_001DDDAC_dddbc((int)arg0);
}

extern "C" int func_001DDF48(int arg0, float *arg1, unsigned short arg2)
{
    GamPoolList_ddf48<ObjStat_ddf48 *> list(8);
    X_func_001D35AC_ddf48(&D_007812C0_ddf48, arg1, &list, 5, 0x8000, 0x04000001, 50.0f);
    if (list.size() != 0) {
        GamPoolList_ddf48<ObjStat_ddf48 *>::iterator last = list.end();
        int count = 0;
        GamPoolList_ddf48<ObjStat_ddf48 *>::iterator it = list.begin();
        while (it != last) {
            unsigned short uid = (*it)->m_uid;
            if (uid != 0xFFFF) {
                if (uid == arg2) {
                    return (*it)->m_oid;
                }
                if (count++ >= 8) {
                    break;
                }
            }
            ++it;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE104);

extern "C" void func_001DE4E4(List_de4e4 *arg0)
{
    Iter_de4e4 it;
    Iter_de4e4 last;
    func_001DDC80(arg0);
    if (arg0->size() != 0) {
        it = arg0->begin();
        last = arg0->end();
        while (it != last) {
            if ((*it).flg & 0x01000000) {
                func_001DE104(arg0, *it);
            }
            ++it;
        }
    }
}

extern "C" void func_001DE5DC(Mgr_de5dc *arg0, int arg1)
{
    Iter_de5dc it;
    Iter_de5dc last;

    it = arg0->list.begin();
    last = arg0->list.end();
    while (it != last) {
        if ((*it).id == arg1) {
            arg0->list.erase(it);
            break;
        }
        ++it;
    }
}

extern "C" void func_001DE6FC(Mgr_de6fc *arg0, int arg1, unsigned int arg2)
{
    Iter_de6fc it;
    Iter_de6fc last;
    Elem_de6fc elem;

    if (arg2 & 0x80000000) {
        arg2 |= 0x80000000;
    }
    it = arg0->m_pool->begin();
    last = arg0->m_pool->end();
    while (it != last) {
        if ((*it).key == arg1) {
            int i = 1;
            do {
                if ((*it).vals[i] == (int)arg2) {
                    return;
                }
                if ((*it).vals[i] == 0) {
                    (*it).vals[i] = (int)arg2;
                    return;
                }
            } while (i++ < 8);
        }
        ++it;
    }
    X_memset_de6fc(&elem, 0, sizeof(elem));
    elem.key = arg1;
    elem.vals[0] = (int)arg2;
    arg0->m_pool->push_back(elem);
}

extern "C" bool func_001DE8AC(int arg0, const float *arg1, const Vec2_de8ac *const *arg2)
{
    int count = 0;
    while (arg2[1] != 0) {
        const Vec2_de8ac *p0 = arg2[0];
        const Vec2_de8ac *p1 = arg2[1];
        Vec2_de8ac v0, v1, v2;
        if (p0->y == p1->y && p0->y == arg1[2]) {
            if (p0->x < p1->x && p0->x < arg1[0]) {
                count++;
            } else if (p1->x < p0->x && p1->x < arg1[0]) {
                count++;
            }
        } else if (p0->y < p1->y && p0->y <= arg1[2] && arg1[2] < p1->y) {
            v0.x = p1->x - p0->x;
            v0.y = p1->y - p0->y;
            v1.x = arg1[0] - p0->x;
            v1.y = arg1[2] - p0->y;
            if ((v0.x * v1.y - v0.y * v1.x) > 0.0f) {
                count++;
            }
        } else if (p1->y < p0->y && p1->y < arg1[2] && arg1[2] <= p0->y) {
            v0.x = p0->x - p1->x;
            v0.y = p0->y - p1->y;
            v2.x = arg1[0] - p1->x;
            v2.y = arg1[2] - p1->y;
            if ((v0.x * v2.y - v0.y * v2.x) > 0.0f) {
                count++;
            }
        }
        arg2++;
    }
    if (count & 1) {
        return true;
    }
    return false;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEA40);

extern "C" void func_001DEAAC(Mgr_deaac *arg0)
{
    Iter_deaac it;
    Iter_deaac last;
    float pos[4];
    int oid = D_007812C0_deaac.m_pc ? D_007812C0_deaac.m_pc->m_oid : 0;

    Xiiui_func_001D05F4(&D_007812C0_deaac, oid, pos);
    if (arg0->list.size() != 0) {
        it = arg0->list.begin();
        last = arg0->list.end();
        while (it != last) {
            if (((*it).flg & 0x04000001) == 0x04000001 &&
                (*it).minX <= pos[0] && pos[0] <= (*it).maxX &&
                (*it).minZ <= pos[2] && pos[2] <= (*it).maxZ &&
                (*it).u30 != 0 && (*it).u34 != 0) {
                X_func_002113DC(&D_007A4440_deaac, (*it).u30, (*it).u34, (*it).u44, 2, 0, (*it).id, D_002FD640_deaac);
                return;
            }
            ++it;
        }
    }
}

extern "C" void func_001DEC14(Mgr_dec14 *arg0)
{
    Iter_dec14 it;
    Iter_dec14 last;
    float pos[4];
    int oid = D_007812C0_dec14.m_pc ? D_007812C0_dec14.m_pc->m_oid : 0;
    Xiiui_func_001D05F4(&D_007812C0_dec14, oid, pos);
    if (arg0->list.size() != 0) {
        it = arg0->list.begin();
        last = arg0->list.end();
        while (it != last) {
            if (((*it).flg & 1) && ((*it).flg70 & 2) &&
                (*it).minX <= pos[0] && pos[0] <= (*it).maxX &&
                (*it).minZ <= pos[2] && pos[2] <= (*it).maxZ &&
                (*it).u30 != 0 && (*it).u34 != 0) {
                Xviiii_func_001E0C2C(arg0, 2, (*it).id, 0x10000000);
                return;
            }
            ++it;
        }
    }
}

// NON_MATCHING: 42/68 differ (size 0x110, game 0x108), 23 edits
#ifdef NON_MATCHING
struct BedPad_ded70 {
    unsigned char pad0[0x78];
    unsigned short m_press;
    unsigned short m_trigger;
}; // ded70
extern "C" int Xii_func_00118FEC__9MagSystem(void *) asm("func_00118FEC__9MagSystem");
extern "C" int func_001DED70(int arg0, int arg1, int *arg2)
{
    char *gm = (char *)&D_007812C0;

    if (!(*(int *)(gm + 0x21F48) & 4)) {
        return 0;
    }
    char *ms = (char *)&D_006E9840;
    if ((unsigned int)(Xii_func_00118FEC__9MagSystem(ms) - 5) >= 3U) {
        return 0;
    }
    if (Xiii_func_001E7D7C((int)&D_007A3D80, *(int *)(gm + 0x222C0)) != 0) {
        return 0;
    }
    BedPad_ded70 *pad = *(BedPad_ded70 **)(ms + 0x97A40);
    if ((pad->m_trigger ^ 0x4000) != 0) {
        return 0;
    }
    if (pad->m_press >> 15) {
        return 0;
    }
    if ((pad->m_press >> 12) & 1) {
        return 0;
    }
    if ((pad->m_press >> 13) & 1) {
        return 0;
    }
    if ((pad->m_press >> 3) & 1) {
        return 0;
    }
    *arg2 |= 0x10;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DED70);
#endif

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD640);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD668);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD670);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD678);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD680);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD688);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD690);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD698);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6D0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6F0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD700);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD708);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD710);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD718);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD720);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEE78);
