#include "include_asm.h"
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
typedef unsigned int u_long128_d8f04 __attribute__((mode(TI)));
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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D96EC);

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
typedef unsigned int u_long128_dbb74 __attribute__((mode(TI)));
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
typedef unsigned int u_long128_dbc5c __attribute__((mode(TI)));
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
typedef unsigned int u_long128_dbdf0 __attribute__((mode(TI)));
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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD414);

extern "C" GamTrgCopy_dd558 *func_001DD558(int arg0, const GamTrgCopy_dd558 *arg1)
{
    GamTrgCopy_dd558 *p = (GamTrgCopy_dd558 *)Xiiiiiii_alloc__9BedMemoryiPCciii((int)&D_006E9800, 0xB0, (int)"game/gamtrg.cpp", 0x62, 0, 1);
    *p = *arg1;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD5E8);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD7BC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDAA8);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDC80);

extern "C" void func_001DDDAC(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x18B5C)) = 0;
}


INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDDBC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDF48);

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

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE6FC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE8AC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEA40);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEAAC);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEC14);

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
