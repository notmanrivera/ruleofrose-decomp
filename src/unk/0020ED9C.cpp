#include "include_asm.h"
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

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020EDA4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020EEA8);

extern "C" void func_0020EFA4(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020EFAC);

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


INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F1FC);

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

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F4FC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F788);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_0020F98C);

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

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00210D3C);

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

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002113DC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211830);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211BE4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00211E84);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002120AC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212330);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212598);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002127F4);

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

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212A5C);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212D08);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212E64);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00212FBC);

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

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00213F48);

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

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214310);

extern "C" void func_002144C4(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002144CC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214664);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002147E0);

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

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214AC4);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214BCC);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214C24);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00214E98);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002150B0);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_002152B8);

INCLUDE_ASM("asm/nonmatchings/unk/0020ED9C", func_00215430);

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

