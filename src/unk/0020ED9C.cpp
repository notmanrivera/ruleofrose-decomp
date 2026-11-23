#include "include_asm.h"
#include "unk/0020ED9C.h"
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
struct State12A5C { int data[28]; ScrBlock780 *buffer; int rest[3]; } ALIGNED(8);
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
struct Global47E0_b {
    unsigned char unk00[0x70];
    ScrBlock780 *unk70;
    unsigned char unk74[0x0C];
};
extern int X47E0_D_007B4640 asm("D_007B4640");
extern Global47E0_b X47E0_D_007B4700 asm("D_007B4700");
extern "C" int func_002149A8();
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
extern ScrBlock80 D_002D9C08[];
extern Elem48_4310 D_007B4850[];
extern int X4310_D_007B4700[32] asm("D_007B4700");
extern int D_007B47E0;
extern int D_007B47F0;
extern int D_007B4800;
extern int D_007B4820;
extern int D_007B4830;
extern "C" void *X20F1FC_memset(void *, int, unsigned int) asm("memset");
extern int D_007B4770;
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
struct Block30000_1 { char b[0x30000]; };
extern ScrBlock80 D_007B4920[];
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

extern "C" int Xiiii_func_00211E84(int, int, int) asm("func_00211E84");
extern "C" int Xiiii_func_00213F48(int, int, int) asm("func_00213F48");
extern "C" void func_0020EEA8(int arg0, int arg1)
{
    __builtin_memcpy((void *)*(int *)arg0, (void *)arg1, 0x20000);
    Xiiii_func_00213F48(arg0, *(int *)arg0, 0);
    Xiiii_func_00211E84(arg0, 0x04000000, D_007B47D0 - 0xA4);
}

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

extern "C" int func_0020F140(ScrMan *arg0)
{
    if (arg0->m_flags & 0x100) {
        return arg0->m_immCtx.m_arg;
    }
    return (*(ScrCtxNode **)&D_007B4640)->m_ctx.m_arg;
}

extern "C" int func_0020F174(ScrMan *arg0)
{
    if (arg0->m_flags & 0x100) {
        return arg0->m_immCtx.m_id;
    }
    return (*(ScrCtxNode **)&D_007B4640)->m_ctx.m_id;
}

extern "C" void func_0020F1A8(ScrMan *arg0)
{
    X_memset(arg0->m_varBufA, 0, 0x800);
    X_memset(arg0->m_varBufB + 4, 0, 0x7FC);
}

extern "C" void func_0020F1FC(ScrMan *arg0)
{
    X20F1FC_memset(arg0->m_varBufA + 0x300, 0, 0x200);
    X20F1FC_memset(arg0->m_varBufB + 0x20, 0, 0x200);
    ScrHookList::iterator it;
    ScrHookList::iterator end;
    it = arg0->m_hookList.begin();
    end = arg0->m_hookList.end();
    for (; it != end; ++it) {
        if (((*it).a >> 30) == 1) {
            it = arg0->m_hookList.erase(it);
        }
    }
}

extern "C" void func_0020F37C(ScrMan *arg0)
{
    ScrCtxList *temp_s0 = arg0->m_slot0;
    if (temp_s0 != 0) {
        void *temp_a0 = temp_s0->m_poolBuf;
        if (temp_a0 != 0) {
            Xii___builtin_vec_delete((int)temp_a0);
        }
        Xii___builtin_delete((int)temp_s0);
    }
    ScrCtxList *temp_s0_2 = arg0->m_slot1;
    if (temp_s0_2 != 0) {
        void *temp_a0_2 = temp_s0_2->m_poolBuf;
        if (temp_a0_2 != 0) {
            Xii___builtin_vec_delete((int)temp_a0_2);
        }
        Xii___builtin_delete((int)temp_s0_2);
    }
    ScrCtxList *temp_s0_3 = arg0->m_slot2;
    if (temp_s0_3 != 0) {
        void *temp_a0_3 = temp_s0_3->m_poolBuf;
        if (temp_a0_3 != 0) {
            Xii___builtin_vec_delete((int)temp_a0_3);
        }
        Xii___builtin_delete((int)temp_s0_3);
    }
    arg0->m_slot0 = 0;
    arg0->m_slot1 = 0;
    arg0->m_slot2 = 0;
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

extern "C" void func_0020F788(ScrMan *arg0)
{
    int temp_v0_2;
    int temp_v1;
    ScrCtxNode *temp_a2;
    ScrCtxChain *temp_a3;
    ScrCtxNode *temp_v0;
    ScrCtxNode *temp_v0_3;
    ScrCtxChain *temp_v1_2;
    ScrCtx *var_a0;
    ScrCtx *var_a1;

    X_func_00214310((*(int *)((int)&D_007B4DD0)));
    if ((*(ScrCtxNode **)&D_007B4640) != (*(ScrCtxNode **)((int)&D_007B4650))) {
        do {
            X_func_00214664(arg0);
            int *flags = &(*(ScrCtxNode **)&D_007B4640)->m_ctx.m_flags;
            temp_v1 = *flags;
            if (temp_v1 & 0x80) {
                *flags = temp_v1 & ~0x80;
                X_func_00214BCC((*(ScrCtxNode **)&D_007B4640)->m_ctx.m_regSlot);
            }
            temp_v0_2 = X_func_00214C24((*(ScrCtxNode **)&D_007B4640)->m_ctx.m_pc);
            if (temp_v0_2 != 0) {
                (*(ScrCtxNode **)&D_007B4640)->m_ctx.m_pc = temp_v0_2;
            } else {
                temp_a3 = &arg0->m_doneList.m_free;
                var_a0 = &(*(ScrCtxNode **)&D_007B4640)->m_ctx;
                temp_a2 = arg0->m_doneList.m_free.m_head.m_prev;
                temp_v0_3 = temp_a2->m_prev;
                var_a1 = &temp_a2->m_ctx;
                arg0->m_doneList.m_free.m_head.m_prev = temp_v0_3;
                temp_v0_3->m_next = &temp_a3->m_head;
                temp_a3->m_num = temp_a3->m_num - 1;
                *(F788_block *)var_a1 = *(F788_block *)var_a0;
                temp_v1_2 = (ScrCtxChain *)((char *)temp_a3 + 0xD0);
                if (temp_v1_2->m_num == 0) {
                    temp_v1_2->m_head.m_next = temp_a2;
                    temp_a2->m_prev = &temp_v1_2->m_head;
                } else {
                    temp_v1_2->m_head.m_prev->m_next = temp_a2;
                    temp_a2->m_prev = temp_v1_2->m_head.m_prev;
                }
                temp_a2->m_next = &temp_v1_2->m_head;
                temp_v1_2->m_head.m_prev = temp_a2;
                temp_v1_2->m_num = temp_v1_2->m_num + 1;
            }
            temp_v0 = (*(ScrCtxNode **)&D_007B4640)->m_next;
            (*(ScrCtxNode **)&D_007B4640) = temp_v0;
        } while (temp_v0 != (*(ScrCtxNode **)((int)&D_007B4650)));
    }
    X_func_002144C4((*(int *)((int)&D_007B4DD0)));
}

// NON_MATCHING: 342/360 differ, 16 relocs differ (size 0x5A0, game 0x5A8), 6 edits
#ifdef NON_MATCHING
extern "C" void F98C_cleanup(ScrMan *) asm("func_0020F4FC");
extern "C" void F98C_finish(void *) asm("func_001CD25C");
extern "C" void func_0020F98C(ScrMan *arg0)
{
    if (arg0->m_flags & 1) return;
    {
        ScrCtxList *pending = &arg0->m_doneList;
        ScrCtxList *active = &arg0->m_queueList;
        if (pending->m_used.m_num != 0) {
            F98C_cleanup(arg0);
            if (pending->m_used.m_num != 0) {
                ScrCtxChain *used = &arg0->m_doneList.m_used;
                if (used->m_num != 0) {
                    pending->m_free.m_head.m_prev->m_next = used->m_head.m_next;
                    ScrCtxNode *p = pending->m_free.m_head.m_prev;
                    p->m_next->m_prev = p;
                    ScrCtxNode *last = used->m_head.m_prev;
                    pending->m_free.m_head.m_prev = last;
                    last->m_next = &pending->m_free.m_head;
                    pending->m_free.m_num += used->m_num;
                    used->m_num = 0;
                    used->m_head.m_prev = &used->m_head;
                    used->m_head.m_next = &used->m_head;
                    active = &arg0->m_queueList;
                }
            }
        }
        if (active->m_used.m_num != 0) {
            ScrCtxChain *used = &arg0->m_queueList.m_used;
            Iter12FBC it;
            Iter12FBC end;
            it = Iter12FBC((int *)active->m_used.m_head.m_next);
            end = Iter12FBC((int *)used);
            for (; it != end; ++it) {
                ScrCtx *data = (ScrCtx *)((char *)it.node + 0x10);
                int kind = data->m_id >> 30;
                switch (kind) {
                case 0: arg0->m_slot0->push_back(*data); break;
                case 1: arg0->m_slot1->push_back(*data); break;
                case 2: arg0->m_slot2->push_back(*data); break;
                }
                int id = it.node[12];
                if (id) func_001E0C2C(D_007812C0.getTrg(), 3, id, 0x02000000);
            }
            if (active->m_used.m_num != 0 && used->m_num != 0) {
                active->m_free.m_head.m_prev->m_next = used->m_head.m_next;
                ScrCtxNode *p = active->m_free.m_head.m_prev;
                p->m_next->m_prev = p;
                ScrCtxNode *last = used->m_head.m_prev;
                active->m_free.m_head.m_prev = last;
                last->m_next = &active->m_free.m_head;
                active->m_free.m_num += used->m_num;
                used->m_num = 0;
                used->m_head.m_prev = &used->m_head;
                used->m_head.m_next = &used->m_head;
            }
        }
        D_007B4DD0 = 0;
        if (arg0->m_slot0->m_used.m_num != 0) {
            D_007B4640 = (int)arg0->m_slot0->m_used.m_head.m_next;
            D_007B4650 = (int)&arg0->m_slot0->m_used.m_head;
            Iter12FBC temp((int *)D_007B4650);
            func_0020F788(arg0);
        }
        D_007B4DD0 = 1;
        if (arg0->m_slot1->m_used.m_num != 0) {
            D_007B4640 = (int)arg0->m_slot1->m_used.m_head.m_next;
            D_007B4650 = (int)&arg0->m_slot1->m_used.m_head;
            Iter12FBC temp((int *)D_007B4650);
            func_0020F788(arg0);
        }
        D_007B4DD0 = 2;
        if (arg0->m_slot2->m_used.m_num != 0) {
            D_007B4640 = (int)arg0->m_slot2->m_used.m_head.m_next;
            D_007B4650 = (int)&arg0->m_slot2->m_used.m_head;
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

// NON_MATCHING: 1/32 differ, 1 edits
#ifdef NON_MATCHING
extern "C" void func_002107AC(unsigned int arg0, unsigned int arg1, int arg2)
{
    if (arg1 != 1) {
        if (arg1 == 0) {
            register unsigned int off PS2_REG("$2") = arg0 << 2;
            if (*(int *)((char *)&D_007B4700 + off) < 0) {
                goto do_branch;
            }
        }
        return;
    } else if (((int *)&D_007B4700)[arg0] < 0) {
        return;
    }
do_branch:
    register int delta PS2_REG("$3") = (*(int *)&D_007B4780);
    delta -= (*(int *)&D_007B47D0);
    int result = (short)(arg2 * 4) + delta;
    delta = 0x80000000;
    (*(int *)&D_007B47C0) = (result + 0x8164) | delta;
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
    case 0x44000000U: {
        register unsigned int fs PS2_REG("$3") = arg3 >> 9;
        register unsigned int ft PS2_REG("$4") = arg3 >> 14;
        register unsigned int src PS2_REG("$2") = fs & 0x7C;
        register unsigned int dst PS2_REG("$3") = ft & 0x7C;
        *(int *)((char *)&D_007B4700 + dst) = *(int *)((char *)&D_007B4680 + src);
        return;
    }
    case 0x44800000U: {
        register unsigned int ft PS2_REG("$4") = arg3 >> 14;
        register unsigned int fs PS2_REG("$3") = arg3 >> 9;
        register unsigned int src PS2_REG("$2") = ft & 0x7C;
        register unsigned int dst PS2_REG("$3") = fs & 0x7C;
        *(int *)((char *)&D_007B4680 + dst) = *(int *)((char *)&D_007B4700 + src);
        break;
    }
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

extern "C" int func_00211318(ScrMan *arg0, int arg1)
{
    ScrCtx *temp_a0 = &(*(ScrCtxNode **)&D_007B4640)->m_ctx;
    int temp_v1 = temp_a0->m_timer;
    if (temp_v1 == -1 || (arg0->m_flags & 0x400)) {
        arg0->m_flags &= ~0x400;
        (*(ScrCtxNode **)&D_007B4640)->m_ctx.m_timer = arg1;
        return 1;
    } else {
        int temp_v0 = temp_v1 - 1;
        temp_a0->m_timer = temp_v0;
        if (temp_v0 == 0) {
            (*(ScrCtxNode **)&D_007B4640)->m_ctx.m_timer = -1;
            return 0;
        }
        return 1;
    }
}

extern "C" void func_002113A4(ScrMan *arg0, int arg1)
{
    (*(unsigned int *)&D_007B47B0) = (arg1 + (*(int *)&D_007B47D0)) - arg0->m_slotBase[*(int *)((int)&D_007B4DD0)];
}

extern "C" void func_002113DC(ScrMan *arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, const char *arg7)
{
    State12A5C backup;
    unsigned int index = arg1 >> 30;
    int var_a3 = arg2 + D_007B4850[index].unk00 - arg0->m_slotBase[index];
    if (F113DC_check((int)arg0, arg1, arg3) != 0) return;
    backup = F12A5C_state;
    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
        var_a3 += 4;
        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
            var_a3 += 4;
            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 -= 0x1C;
                    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                        var_a3 += 4;
                        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                            var_a3 += 4;
                            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                                var_a3 += 4;
                                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                                    var_a3 += 4;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    arg0->m_immCtx.m_flags = arg4;
    arg0->m_immCtx.m_id = arg1;
    arg0->m_immCtx.m_pc = var_a3;
    arg0->m_immCtx.m_timer = -1;
    arg0->m_immCtx.m_trgId = arg6;
    arg0->m_immCtx.m_state = 1;
    arg0->m_immCtx.m_arg = arg3;
    arg0->m_immCtx.m_savedStack = 0;
    F11E_strncpy(arg0->m_immCtx.m_name, arg7, 8);
    if (arg5) arg0->m_immCtx.m_regSlot = F113DC_alloc();
    F113DC_select(index);
    if (arg5) F113DC_load(arg0->m_immCtx.m_regSlot);
    arg0->m_flags |= 0x100;
    register int result PS2_REG("$4");
    result = F113DC_exec(arg0->m_immCtx.m_pc);
#ifdef TARGET_PS2
    asm("" : "+r"(result) : : "$7");
#endif
    ScrCtxChain *chain = &arg0->m_queueList.m_free;
    if (result != 0) {
        arg0->m_immCtx.m_pc = result;
        result = (int)&arg0->m_immCtx;
        ScrCtxNode *node = chain->m_head.m_prev;
        ScrCtxNode *prev = node->m_prev;
        chain->m_head.m_prev = prev;
        prev->m_next = &chain->m_head;
        --chain->m_num;
        *(F11E_record *)&node->m_ctx = *(F11E_record *)result;
        ScrCtxChain *used = (ScrCtxChain *)((char *)chain + 0xD0);
        if (used->m_num == 0) {
            used->m_head.m_next = node;
            node->m_prev = &used->m_head;
        } else {
            used->m_head.m_prev->m_next = node;
            node->m_prev = used->m_head.m_prev;
        }
        node->m_next = &used->m_head;
        used->m_head.m_prev = node;
        ++used->m_num;
    } else {
        func_0020F428((int)arg0, (char *)&arg0->m_immCtx);
    }
    arg0->m_flags &= ~0x100;
    F113DC_select(D_007B4DD0);
    F12A5C_state = backup;
}

extern "C" int F11830_check(int, unsigned int, int) asm("func_00213D00");
extern "C" int F11830_alloc() asm("func_00214AC4");
extern "C" void F11830_select(unsigned int) asm("func_00214310");
extern "C" void F11830_load(int) asm("func_00214BCC");
extern "C" int F11830_exec(int) asm("func_00214C24");
extern "C" void func_00211830(ScrMan *arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5)
{
    unsigned int index = arg1 >> 30;
    int var_a3 = arg2 + D_007B4850[index].unk00 - arg0->m_slotBase[index];
    if (F11830_check((int)arg0, arg1, arg3) != 0) return;
    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
        var_a3 += 4;
        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
            var_a3 += 4;
            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 -= 0x1C;
                    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                        var_a3 += 4;
                        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                            var_a3 += 4;
                            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                                var_a3 += 4;
                                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                                    var_a3 += 4;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    arg0->m_immCtx.m_flags = arg4;
    arg0->m_immCtx.m_id = arg1;
    arg0->m_immCtx.m_pc = var_a3;
    arg0->m_immCtx.m_timer = -1;
    arg0->m_immCtx.m_state = 1;
    arg0->m_immCtx.m_arg = arg3;
    arg0->m_immCtx.m_trgId = 0;
    arg0->m_immCtx.m_savedStack = 0;
    F11E_strncpy(arg0->m_immCtx.m_name, "imdy", 8);
    if (arg5) arg0->m_immCtx.m_regSlot = F11830_alloc();
    F11830_select(index);
    if (arg5) F11830_load(arg0->m_immCtx.m_regSlot);
    arg0->m_flags |= 0x100;
    register int result PS2_REG("$4");
    result = F11830_exec(arg0->m_immCtx.m_pc);
#ifdef TARGET_PS2
    asm("" : "+r"(result) : : "$7");
#endif
    ScrCtxChain *chain = &arg0->m_queueList.m_free;
    if (result != 0) {
        arg0->m_immCtx.m_pc = result;
        result = (int)&arg0->m_immCtx;
        ScrCtxNode *node = chain->m_head.m_prev;
        ScrCtxNode *prev = node->m_prev;
        chain->m_head.m_prev = prev;
        prev->m_next = &chain->m_head;
        --chain->m_num;
        *(F11E_record *)&node->m_ctx = *(F11E_record *)result;
        ScrCtxChain *used = (ScrCtxChain *)((char *)chain + 0xD0);
        if (used->m_num == 0) {
            used->m_head.m_next = node;
            node->m_prev = &used->m_head;
        } else {
            used->m_head.m_prev->m_next = node;
            node->m_prev = used->m_head.m_prev;
        }
        node->m_next = &used->m_head;
        used->m_head.m_prev = node;
        ++used->m_num;
    } else {
        func_0020F428((int)arg0, (char *)&arg0->m_immCtx);
    }
    arg0->m_flags &= ~0x100;
    F11830_select(2);
}

extern "C" void func_00211BE4(ScrMan *arg0, unsigned int arg1, int arg2, int arg3, int arg4)
{
    F11E_record stack;
    int var_a3;
    ScrCtxNode *temp_a1_2;
    ScrCtxChain *temp_s0;
    ScrCtxNode *temp_v0;
    ScrCtxChain *temp_v1;
    ScrCtx *var_a0;

    unsigned int index = arg1 >> 30;
    register unsigned int base PS2_REG("$7") = arg0->m_slotBase[index];
    var_a3 = arg2 + D_007B4850[index].unk00 - base;
    if (F11BE4_check((int)arg0, arg1, arg3, base) != 0) return;
    temp_s0 = &arg0->m_queueList.m_free;
    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
        var_a3 += 4;
        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
            var_a3 += 4;
            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 -= 0x1C;
                    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                        var_a3 += 4;
                        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                            var_a3 += 4;
                            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                                var_a3 += 4;
                                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
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
    F11E_strncpy(arg0->m_immCtx.m_name, "single", 8);
    temp_a1_2 = temp_s0->m_head.m_prev;
    temp_v0 = temp_a1_2->m_prev;
    var_a0 = &temp_a1_2->m_ctx;
    temp_s0->m_head.m_prev = temp_v0;
    temp_v0->m_next = &temp_s0->m_head;
    temp_s0->m_num = temp_s0->m_num - 1;
    *(F11E_record *)var_a0 = stack;
    temp_v1 = (ScrCtxChain *)((char *)temp_s0 + 0xD0);
    if (temp_v1->m_num == 0) {
        temp_v1->m_head.m_next = temp_a1_2;
        temp_a1_2->m_prev = &temp_v1->m_head;
    } else {
        temp_v1->m_head.m_prev->m_next = temp_a1_2;
        temp_a1_2->m_prev = temp_v1->m_head.m_prev;
    }
    temp_a1_2->m_next = &temp_v1->m_head;
    temp_v1->m_head.m_prev = temp_a1_2;
    temp_v1->m_num = temp_v1->m_num + 1;
}

extern "C" void func_00211E84(int arg0, int arg1, int arg2)
{
    ScrMan *self = (ScrMan *)arg0;
    ScrEntryBlock *blk = (ScrEntryBlock *)arg2;
    F11E_record stack;
    int temp_a1;
    int var_a3;
    ScrCtxNode *temp_a1_2;
    ScrCtxChain *temp_s0;
    ScrCtxNode *temp_v0;
    ScrCtxChain *temp_v1;
    ScrCtx *var_a0;

    var_a3 = (int)&blk->m_insnA4;
    temp_s0 = &self->m_queueList.m_free;
    temp_a1 = var_a3;
    if ((blk->m_insnA4 & 0xFFFF0000) != 0x27BD0000) {
        var_a3 = (int)&blk->m_insnA8;
        if ((blk->m_insnA8 & 0xFFFF0000) != 0x27BD0000) {
            var_a3 = (int)&blk->m_insnAC;
            if ((blk->m_insnAC & 0xFFFF0000) != 0x27BD0000) {
                var_a3 = (int)&blk->m_insnB0;
                if ((blk->m_insnB0 & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 = (int)&blk->m_insn94;
                    if ((blk->m_insn94 & 0xFFFF0000) != 0x27BD0000) {
                        var_a3 = (int)&blk->m_insn98;
                        if ((blk->m_insn98 & 0xFFFF0000) != 0x27BD0000) {
                            var_a3 = (int)&blk->m_insn9C;
                            if ((blk->m_insn9C & 0xFFFF0000) != 0x27BD0000) {
                                var_a3 = (int)&blk->m_insnA0;
                                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) var_a3 = temp_a1;
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
    F11E_strncpy(self->m_immCtx.m_name, "mst", 8);
    temp_a1_2 = temp_s0->m_head.m_prev;
    temp_v0 = temp_a1_2->m_prev;
    var_a0 = &temp_a1_2->m_ctx;
    temp_s0->m_head.m_prev = temp_v0;
    temp_v0->m_next = &temp_s0->m_head;
    temp_s0->m_num = temp_s0->m_num - 1;
    *(F11E_record *)var_a0 = stack;
    temp_v1 = (ScrCtxChain *)((char *)temp_s0 + 0xD0);
    if (temp_v1->m_num == 0) {
        temp_v1->m_head.m_next = temp_a1_2;
        temp_a1_2->m_prev = &temp_v1->m_head;
    } else {
        temp_v1->m_head.m_prev->m_next = temp_a1_2;
        temp_a1_2->m_prev = temp_v1->m_head.m_prev;
    }
    temp_a1_2->m_next = &temp_v1->m_head;
    temp_v1->m_head.m_prev = temp_a1_2;
    temp_v1->m_num = temp_v1->m_num + 1;
}

// NON_MATCHING: 108/160 differ, 2 relocs differ (size 0x280, game 0x284), 18 edits
#ifdef NON_MATCHING
extern "C" int F120AC_alloc() asm("func_00214AC4");
extern "C" void func_002120AC(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, const char *arg6)
{
    ScrMan *self = (ScrMan *)arg0;
    F11E_record stack;
    ScrCtxNode *temp_a1_2, *temp_v0;
    ScrCtxChain *temp_s0, *temp_v1;
    ScrCtx *var_a0;
    unsigned int index = (unsigned)arg1 >> 30;
    int var_a3 = arg2 + D_007B4850[index].unk00 - self->m_slotBase[index];
    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000 &&
        (var_a3 += 4, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) &&
        (var_a3 += 4, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000)) {
        var_a3 += 4;
        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000 &&
            (var_a3 -= 0x1C, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000)) {
            var_a3 += 4;
            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 += 4;
                    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) var_a3 += 4;
                }
            }
        }
    }
    stack.data[0] = arg4;
    temp_s0 = &self->m_queueList.m_free;
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
    temp_a1_2 = temp_s0->m_head.m_prev;
    temp_v0 = temp_a1_2->m_prev;
    var_a0 = &temp_a1_2->m_ctx;
    temp_s0->m_head.m_prev = temp_v0;
    temp_v0->m_next = &temp_s0->m_head;
    temp_s0->m_num = temp_s0->m_num - 1;
    *(F11E_record *)var_a0 = stack;
    temp_v1 = (ScrCtxChain *)((char *)temp_s0 + 0xD0);
    if (temp_v1->m_num == 0) {
        temp_v1->m_head.m_next = temp_a1_2;
        temp_a1_2->m_prev = &temp_v1->m_head;
    } else {
        temp_v1->m_head.m_prev->m_next = temp_a1_2;
        temp_a1_2->m_prev = temp_v1->m_head.m_prev;
    }
    temp_a1_2->m_next = &temp_v1->m_head;
    temp_v1->m_head.m_prev = temp_a1_2;
    temp_v1->m_num = temp_v1->m_num + 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002120AC);
#endif

extern "C" void func_00212330(ScrMan *arg0, ScrBindRec *arg1, int arg2, int arg3)
{
    F11E_record stack;
    ScrCtxNode *temp_a1_2, *temp_v0;
    ScrCtxChain *temp_s0, *temp_v1;
    ScrCtx *var_a0;
    unsigned int index = arg1->m_slotTag >> 30;
    int var_a3 = arg1->m_entryOff + D_007B4850[index].unk00 - arg0->m_slotBase[index];
    int recordArg = arg1->m_id;
    temp_s0 = &arg0->m_queueList.m_free;
    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000 &&
        (var_a3 += 4, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) &&
        (var_a3 += 4, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000)) {
        var_a3 += 4;
        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000 &&
            (var_a3 -= 0x1C, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000)) {
            var_a3 += 4;
            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 += 4;
                    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) var_a3 += 4;
                }
            }
        }
    }
    stack.data[0] = arg3;
    stack.data[1] = recordArg;
    stack.data[2] = var_a3;
    stack.data[7] = -1;
    stack.data[8] = (int)arg1;
    stack.data[9] = 1;
    stack.data[10] = arg2;
    stack.data[43] = 0;
    F11E_strncpy((char *)&stack.data[4], D_00301710, 8);
    temp_a1_2 = temp_s0->m_head.m_prev;
    temp_v0 = temp_a1_2->m_prev;
    var_a0 = &temp_a1_2->m_ctx;
    temp_s0->m_head.m_prev = temp_v0;
    temp_v0->m_next = &temp_s0->m_head;
    temp_s0->m_num = temp_s0->m_num - 1;
    *(F11E_record *)var_a0 = stack;
    temp_v1 = (ScrCtxChain *)((char *)temp_s0 + 0xD0);
    if (temp_v1->m_num == 0) {
        temp_v1->m_head.m_next = temp_a1_2;
        temp_a1_2->m_prev = &temp_v1->m_head;
    } else {
        temp_v1->m_head.m_prev->m_next = temp_a1_2;
        temp_a1_2->m_prev = temp_v1->m_head.m_prev;
    }
    temp_a1_2->m_next = &temp_v1->m_head;
    temp_v1->m_head.m_prev = temp_a1_2;
    temp_v1->m_num = temp_v1->m_num + 1;
}

extern "C" void func_00212598(ScrMan *arg0, unsigned int arg1, int arg2, int arg3, int arg4, int arg5)
{
    F11E_record stack;
    ScrCtxNode *temp_a1_2, *temp_v0;
    ScrCtxChain *temp_s0, *temp_v1;
    ScrCtx *var_a0;
    unsigned int index = arg1 >> 30;
    int var_a3 = arg3 + D_007B4850[index].unk00 - arg0->m_slotBase[index];
    temp_s0 = &arg0->m_queueList.m_free;
    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000 &&
        (var_a3 += 4, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) &&
        (var_a3 += 4, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000)) {
        var_a3 += 4;
        if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000 &&
            (var_a3 -= 0x1C, (*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000)) {
            var_a3 += 4;
            if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                var_a3 += 4;
                if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) {
                    var_a3 += 4;
                    if ((*(int *)var_a3 & 0xFFFF0000) != 0x27BD0000) var_a3 += 4;
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
    temp_a1_2 = temp_s0->m_head.m_prev;
    temp_v0 = temp_a1_2->m_prev;
    var_a0 = &temp_a1_2->m_ctx;
    temp_s0->m_head.m_prev = temp_v0;
    temp_v0->m_next = &temp_s0->m_head;
    temp_s0->m_num = temp_s0->m_num - 1;
    *(F11E_record *)var_a0 = stack;
    temp_v1 = (ScrCtxChain *)((char *)temp_s0 + 0xD0);
    if (temp_v1->m_num == 0) {
        temp_v1->m_head.m_next = temp_a1_2;
        temp_a1_2->m_prev = &temp_v1->m_head;
    } else {
        temp_v1->m_head.m_prev->m_next = temp_a1_2;
        temp_a1_2->m_prev = temp_v1->m_head.m_prev;
    }
    temp_a1_2->m_next = &temp_v1->m_head;
    temp_v1->m_head.m_prev = temp_a1_2;
    temp_v1->m_num = temp_v1->m_num + 1;
}

extern "C" void func_002127F4(int arg0)
{
    ScrMan *obj = (ScrMan *)arg0;
    ScrHookList::iterator it;
    ScrHookList::iterator end;
    it = obj->m_hookList.begin();
    end = obj->m_hookList.end();
    while (it != end) {
        if (((*it).a >> 30) == 1) {
            it = obj->m_hookList.erase(it);
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

extern "C" void func_00212A5C(ScrMan *self, unsigned int arg1, int arg2, int arg3)
{
    ScrHookList::iterator it;
    ScrHookList::iterator end;
    struct {
        State12A5C state;
        ScrBlock780 buffer;
        char unused[0x1680];
    } backup;
    it = self->m_hookList.begin();
    end = self->m_hookList.end();
    for (; it != end; ++it) {
        if ((*it).a == arg1) {
            D_007B4DB0 = D_007B4780;
            F12A5C_mode = 2;
            backup.state = F12A5C_state;
            backup.buffer = *(ScrBlock780 *)F12A5C_state.buffer;
            F12A5C_run((int)self, arg1, (*it).b, arg2, 2, arg3);
            F12A5C_state = backup.state;
            *(ScrBlock780 *)F12A5C_state.buffer = backup.buffer;
            return;
        }
    }
}

extern "C" void func_00212D08(ScrMan *arg0, int arg1, int arg2)
{
    ScrCtxNode *p = 0;
    if (X2D08_func_00213C6C((int)arg0, arg1, (int)&p, arg2) != 0) {
        arg0->m_doneList.push_back(p->m_ctx);
    }
}

extern "C" void func_00212E64(ScrMan *arg0, int arg1)
{
    ScrCtxNode *p = 0;
    if (func_00213D90((int)arg0, arg1, (int)&p) != 0) {
        arg0->m_doneList.push_back(p->m_ctx);
    }
}

extern "C" void func_00212FBC(ScrMan *self, int arg1)
{
    Iter12FBC it;
    Iter12FBC end;
    it = Iter12FBC((int *)self->m_slot0->m_used.m_head.m_next);
    end = Iter12FBC((int *)&self->m_slot0->m_used.m_head);
    for (; it != end; ++it) {
        ScrCtx *data = (ScrCtx *)((char *)it.node + 0x10);
        if (data->m_arg == arg1) {
            self->m_doneList.push_back(*data);
        }
    }
    it = Iter12FBC((int *)self->m_slot1->m_used.m_head.m_next);
    end = Iter12FBC((int *)&self->m_slot1->m_used.m_head);
    for (; it != end; ++it) {
        ScrCtx *data = (ScrCtx *)((char *)it.node + 0x10);
        if (data->m_arg == arg1) {
            self->m_doneList.push_back(*data);
        }
    }
    it = Iter12FBC((int *)self->m_slot2->m_used.m_head.m_next);
    end = Iter12FBC((int *)&self->m_slot2->m_used.m_head);
    for (; it != end; ++it) {
        ScrCtx *data = (ScrCtx *)((char *)it.node + 0x10);
        if (data->m_arg == arg1) {
            self->m_doneList.push_back(*data);
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

// NON_MATCHING: 1/37 differ, 1 edits
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
    register NodeIter *end_ptr PS2_REG("$10");
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
        register int out PS2_REG("$8");
        register NodeIter *begin PS2_REG("$6");
        do {
            out = a2;
            begin = &beg;
        } while (0);
        int *firstNode = *(int **)(p + 0xD4);
        int *endNode = (int *)(p + 0xD0);
        register NodeIter *endArg PS2_REG("$7") = end_ptr;
        beg.m_node = firstNode;
        end_ptr->m_node = endNode;
        return func_00213B28(arg0, arg1, (int)begin, (int)endArg, out, arg3);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213C6C);
#endif

// NON_MATCHING: 1/36 differ, 1 edits
#ifdef NON_MATCHING
extern "C" int func_00213ADC(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" int func_00213D00(int arg0, unsigned int arg1, int arg2)
{
    NodeIter beg;
    NodeIter end0;
    NodeIter end1;
    NodeIter end2;
    register NodeIter *end_ptr PS2_REG("$9");
    register int *p PS2_REG("$2");
    register int self PS2_REG("$7") = arg0;
    switch ((int)(arg1 >> 30)) {
    case 0:
        p = *(int **)(self + 0x10);
        end_ptr = &end0;
        goto do_call;
    case 1:
        p = *(int **)(self + 0x14);
        end_ptr = &end1;
        goto do_call;
    case 2:
        p = *(int **)(self + 0x18);
        end_ptr = &end2;
    do_call:;
        register NodeIter *begin PS2_REG("$6");
        register int out PS2_REG("$8");
        do {
            out = arg2;
            begin = &beg;
        } while (0);
        int *firstNode = (int *)p[0xD4 / 4];
        int *endNode = &p[0xD0 / 4];
        register NodeIter *endArg PS2_REG("$7") = end_ptr;
        beg.m_node = firstNode;
        end_ptr->m_node = endNode;
        return func_00213ADC(arg0, arg1, (int)begin, (int)endArg, out);
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
extern ScrBlock780 *F13F48_buffers[] asm("D_002D9E08");
extern "C" void func_00213F48(int arg0, int arg1, int arg2)
{
    ScrMan *self = (ScrMan *)arg0;
    ScrBinHdr *hdr = (ScrBinHdr *)arg1;
    int base = arg1 + 0x30;
    D_007B47D0 = base;
    D_007B4820 = hdr->m_unk20;
    D_007B4830 = hdr->m_unk24;
    D_007B47E0 = arg1 + hdr->m_unk14 + hdr->m_unk18;
    D_007B4800 = arg1 + hdr->m_unk14;
    D_007B47F0 = D_007B4800 - hdr->m_unk1C + 8;
    *(char **)(D_007B47E0 - 0x20) = self->m_varBufA;
    *(char **)(D_007B47E0 - 0x10) = self->m_varBufB;
    D_007B47D0 = base;
    D_007B47E0 = hdr->m_unk10;
    D_007B4800 = arg1 + hdr->m_unk14;
    D_007B47F0 = D_007B4800 + hdr->m_unk1C + 8;
    D_007B4820 = hdr->m_unk20;
    D_007B4830 = hdr->m_unk24;
    int tail = arg1 + hdr->m_unk0C + (hdr->m_unk18 + hdr->m_unk14);
    X4310_D_007B4700[28] = tail + 0x8000;
    X4310_D_007B4700[29] = tail + 0x8780;
    D_002D9C08[arg2] = *(ScrBlock80 *)X4310_D_007B4700;
    *F13F48_buffers[arg2] = *(ScrBlock780 *)X4310_D_007B4700[28];
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
    *(ScrBlock80 *)X4310_D_007B4700 = D_002D9C08[arg0];
    X4310_D_007B4700[31] = 0;
}

extern "C" void func_002144C4(void) {
}

extern "C" void func_002144CC(ScrMan *arg0)
{
    ScrCtx *inner = arg0->m_savedCtx;
    if (inner != 0) {
        if (inner->m_flags & 0x200) {
            *(ScrBlock80 *)&D_007B4700 = inner->m_savedRegs;
        }
        if (arg0->m_savedCtx->m_savedStack != 0) {
            **(ScrBlock780 **)&D_007B4770 = *arg0->m_savedCtx->m_savedStack;
        }
    }
    arg0->m_savedCtx = 0;
}

extern "C" void func_00214664(void)
{
    ScrCtxNode *obj = *(ScrCtxNode **)&D_007B4640;
    if (obj->m_ctx.m_flags & 0x200) {
        *(ScrBlock80 *)&D_007B4700 = obj->m_ctx.m_savedRegs;
    }
    if ((*(ScrCtxNode **)&D_007B4640)->m_ctx.m_savedStack != 0) {
        **(ScrBlock780 **)&D_007B4770 = *(*(ScrCtxNode **)&D_007B4640)->m_ctx.m_savedStack;
    }
}

extern "C" void func_002147E0(ScrMan *arg0)
{
    ScrCtx *inner = &(*(ScrCtxNode **)&D_007B4640)->m_ctx;
    if (arg0->m_flags & 0x100) {
        inner = &arg0->m_immCtx;
    }
    inner->m_savedRegs = *(ScrBlock80 *)&X47E0_D_007B4700;
    inner->m_flags |= 0x200;
    if (inner->m_savedStack == 0) {
        inner->m_savedStack = (ScrBlock780 *)func_002149A8();
    }
    *inner->m_savedStack = *(ScrBlock780 *)X47E0_D_007B4700.unk70;
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
    D_007B4920[i] = *(ScrBlock80 *)&D_007B4700;
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
                (*(ScrCtxNode **)&D_007B4640)->m_ctx.m_state = 1;
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

