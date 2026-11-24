#include "include_asm.h"
struct GamMan25E4 {
    unsigned char m_pad00[0x21F48];
    unsigned int m_sysFlg;
};
extern "C" void func_0013FB3C(void *, int, int);
extern "C" float func_001D4A3C(void *, unsigned int, int);
extern "C" void func_001DA740(void *, int, void *);
extern "C" void func_001DB520(void *, int, void *);
extern "C" void func_001D0EFC(int, void *, float, int);
struct Obj2C0CItem {
    unsigned char m_pad00[0x100];
    unsigned int m_oid;
};
struct Obj2C0C {
    struct Node {
        Node *m_prev;
        Node *m_next;
        Obj2C0CItem *m_data;
    };
    class iterator {
    public:
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        Obj2C0CItem *&operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    unsigned char m_pad00[0x1D990];
    Node m_head;
    iterator begin() { return iterator(m_head.m_next); }
    iterator end() { return iterator(&m_head); }
};
struct Obj2D00;
extern "C" int func_001DB17C(int, int);
extern "C" int func_001D046C(int, unsigned int);
extern "C" int func_001D2B8C(int, int);
extern "C" int func_001D2BA8(int, unsigned int);
extern "C" void *func_001D2D00(Obj2D00 *, unsigned int);
struct Vec2_4730 {
    float x;
    float y;
};
extern "C" void Xviii_func_001DB19C(int, int, int) asm("func_001DB19C");
extern "C" void Xviii_func_001DB18C(int, int, int) asm("func_001DB18C");
struct Obj2D7C {
    struct Node {
        Node *m_prev;
        Node *m_next;
        void *m_data;
    };
    class iterator {
    public:
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        void *&operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    unsigned char pad[0x1DCD0];
    Node m_head;
    iterator begin() { return iterator(m_head.m_next); }
    iterator end() { return iterator(&m_head); }
};
struct Vec2A14 {
    float x;
    float y;
    float z;
};
extern "C" int X_func_001D890C(...) asm("func_001D890C");
extern "C" int X_func_001D89C4(...) asm("func_001D89C4");
extern "C" void Xvpi_func_00130DE0(void *, int) asm("func_00130DE0");
struct Obj2D00 {
    struct Node {
        Node *m_prev;
        Node *m_next;
        void *m_data;
    };
    class iterator {
    public:
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        void *&operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    unsigned char pad[0x1DCD0];
    Node m_head;
    iterator begin() { return iterator(m_head.m_next); }
    iterator end() { return iterator(&m_head); }
};
struct Obj2B10 {
    struct Node {
        Node *m_prev;
        Node *m_next;
        void *m_data;
    };
    class iterator {
    public:
        Node *m_node;
        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        void *&operator*() const { return m_node->m_data; }
        iterator &operator++()
        {
            m_node = m_node->m_next;
            return *this;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };
    unsigned char pad[0x1DCD0];
    Node m_head;
    iterator begin() { return iterator(m_head.m_next); }
    iterator end() { return iterator(&m_head); }
};
extern "C" void X_func_001D1C80(void *, unsigned int, int, void *) asm("func_001D1C80");
extern "C" void X_func_001D1D5C(void *, unsigned int, int, void *) asm("func_001D1D5C");
extern "C" void Xv_func_001DAC8C(int, int, int) asm("func_001DAC8C");
extern "C" float Xf_func_001D8C50(int) asm("func_001D8C50");
extern "C" void Xvp_func_001D10D0(int, int, int) asm("func_001D10D0");
extern "C" void Xvp_func_001D1410(int, int, int) asm("func_001D1410");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001D3A38(int, int) asm("func_001D3A38");
extern "C" int Xiiiii_attachActor__9MagSystemiii(int, int, int, int) asm("attachActor__9MagSystemiii");
extern "C" int Xiiu_func_001CBE38(int, unsigned int) asm("func_001CBE38");
extern "C" int Xiiu_func_001D046C(int, unsigned int) asm("func_001D046C");
extern "C" int Xiiu_func_001D2B8C(int, unsigned int) asm("func_001D2B8C");
extern "C" int Xiiu_func_001D2D00(int, unsigned int) asm("func_001D2D00");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_attachActor__9MagSystemiii(...) asm("attachActor__9MagSystemiii");
extern "C" int X_func_00130DE0(...) asm("func_00130DE0");
extern "C" int X_func_001CBE38(...) asm("func_001CBE38");
extern "C" int X_func_001D046C(...) asm("func_001D046C");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D2B8C(...) asm("func_001D2B8C");
extern "C" int X_func_001D2BA8(...) asm("func_001D2BA8");
extern "C" int X_func_001D2D00(...) asm("func_001D2D00");
extern "C" int X_func_001D3A38(...) asm("func_001D3A38");
extern "C" int X_func_001D9F08(...) asm("func_001D9F08");
extern "C" int X_func_001DA228(...) asm("func_001DA228");
extern "C" int X_func_001DAC8C(...) asm("func_001DAC8C");
extern "C" int X_func_001DB18C(...) asm("func_001DB18C");
extern "C" int X_func_001DB19C(...) asm("func_001DB19C");
extern "C" int X_func_001DB31C(...) asm("func_001DB31C");
extern int D_006E9840;
extern int D_006FBD80;
extern int D_006FE6A0;
extern int D_00724EA0;
extern int D_007812C0;
extern int D_007B205C;

extern "C" void func_001D1BEC(int arg0, unsigned int arg1, unsigned int arg2)
{
    if (Xiiu_func_001D046C((int) arg0, arg1) != 0) {
        Xiiiii_attachActor__9MagSystemiii((int) (int)&D_006E9840, Xiiu_func_001CBE38((int)&D_007812C0, arg1), -1, 0);
        if (((arg2 >> 0x1C) & 3) == 1) {
            M2C_FIELD(Xiiu_func_001D2B8C(arg0, arg2), int *, 0x254) = -1;
        }
    }
}

extern "C" int func_001D1C80(int arg0, unsigned int arg1, int arg2, int arg3)
{
    int var_v0 = X_func_001D046C(arg0, arg1);

    if (var_v0 != 0) {
        switch ((arg1 >> 0x1C) & 3) {
            case 0:
                X_func_001DB31C(X_func_001D2D00(arg0, arg1), arg2, arg3);
                break;
            case 1:
                X_func_001DA228(X_func_001D2B8C(arg0, arg1), arg2, arg3);
                break;
            case 2:
                X_func_001DB31C(X_func_001D2BA8(arg0, arg1), arg2, arg3);
                break;
        }
        return 0;
    }
    return var_v0;
}

extern "C" int func_001D1D5C(int arg0, unsigned int arg1, int arg2, void *arg3)
{
    if (func_001D046C(arg0, arg1) == 0) {
        return 0;
    }
    switch ((arg1 >> 0x1C) & 3) {
    case 0:
        func_001DB520(func_001D2D00((Obj2D00 *)arg0, arg1), arg2, arg3);
        break;
    case 1:
        {
            void *obj = (void *)func_001D2B8C(arg0, arg1);
            func_001DA740(obj, arg2, arg3);
            if (arg2 == 0x18 && ((arg1 >> 0x17) & 0x1F) == 2) {
                func_001D0EFC(arg0, obj, func_001D4A3C((void *)arg0, arg1, 0), 0);
            }
        }
        break;
    case 2:
        func_001DB520((void *)func_001D2BA8(arg0, arg1), arg2, arg3);
        break;
    }
    return 1;
}

extern "C" void func_001D1E88(int arg0, unsigned int arg1, float fparg0)
{
    int temp_v0;

    X_func_001D046C(arg0, arg1);
    switch ((arg1 >> 0x1C) & 3) {
        case 1:
        case 2:
            temp_v0 = (int)&D_006FE6A0 + (X_func_001CBE38(arg0, arg1) * 0x4D0);
            M2C_FIELD(temp_v0, float *, 0x68) = fparg0;
            M2C_FIELD(temp_v0, float *, 0x64) = fparg0;
            M2C_FIELD(temp_v0, float *, 0x60) = fparg0;
            M2C_FIELD(temp_v0, int *, 0x90) = 1;
            break;
    }
}

extern "C" float func_001D1F14(int arg0, unsigned int arg1)
{
    switch ((arg1 >> 0x1C) & 3) {
        case 1:
            return Xf_func_001D8C50(X_func_001D2B8C(arg0, arg1));
        case 2:
            return Xf_func_001D8C50(X_func_001D2BA8(arg0, arg1));
        default:
            return 0.0f;
    }
}

extern "C" void func_001D1F74(int arg0, unsigned int arg1, int arg2, int arg3)
{
    if (((arg1 >> 0x1C) & 3) == 1) {
        return Xv_func_001DAC8C(X_func_001D2B8C(arg0, arg1), arg2, arg3);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D1FD8);

extern "C" int func_001D217C(int arg0, unsigned int arg1, int arg2)
{
    if (func_001D046C(arg0, arg1) == 0) {
        return -1;
    }
    switch ((arg1 >> 0x1C) & 3) {
    case 0:
        return func_001DB17C((int)func_001D2D00((Obj2D00 *)arg0, arg1), arg2);
    case 1:
        return func_001DB17C(func_001D2B8C(arg0, arg1), arg2);
    case 2:
        return func_001DB17C(func_001D2BA8(arg0, arg1), arg2);
    }
    return 0;
}

extern "C" int func_001D2270(int arg0, unsigned int arg1, int arg2, int arg3)
{
    if (X_func_001D046C(arg0, arg1) != 0) {
        switch ((arg1 >> 0x1C) & 3) {
            case 0:
                Xviii_func_001DB18C(X_func_001D2D00(arg0, arg1), arg2, arg3);
                break;
            case 1:
                Xviii_func_001DB18C(X_func_001D2B8C(arg0, arg1), arg2, arg3);
                break;
            case 2:
                Xviii_func_001DB18C(X_func_001D2BA8(arg0, arg1), arg2, arg3);
                break;
        }
    }
}

extern "C" int func_001D2334(int arg0, unsigned int arg1, int arg2, int arg3)
{
    if (X_func_001D046C(arg0, arg1) != 0) {
        switch ((arg1 >> 0x1C) & 3) {
            case 0:
                Xviii_func_001DB19C(X_func_001D2D00(arg0, arg1), arg2, arg3);
                break;
            case 1:
                Xviii_func_001DB19C(X_func_001D2B8C(arg0, arg1), arg2, arg3);
                break;
            case 2:
                Xviii_func_001DB19C(X_func_001D2BA8(arg0, arg1), arg2, arg3);
                break;
        }
    }
}

extern "C" void func_001D23F8(int arg0, int arg1, int arg2)
{
    if (arg2 != 0) {
        Xvp_func_001D10D0(arg0, arg1, 1);
        return;
    }
    Xvp_func_001D1410(arg0, arg1, 1);
}

extern "C" void func_001D2428(int arg0, unsigned int arg1, int arg2)
{
    int *temp_v0;

    switch ((arg1 >> 0x1C) & 3) {
        case 1:
        case 2:
            temp_v0 = &D_00724EA0 + X_func_001CBE38(arg0, arg1);
            *temp_v0 = (*temp_v0 & ~0x60) | ((arg2 & 3) << 5);
            break;
    }
}

extern "C" void func_001D2494(GamMan25E4 *arg0, int arg1)
{
    int off = 0x12540;

    switch (arg1) {
    case 0:
        func_0013FB3C((char *)&D_006E9840 + off, 7, 0);
        if (arg0->m_sysFlg & 0x04000000) {
            func_0013FB3C((char *)&D_006E9840 + off, 6, 1);
            arg0->m_sysFlg |= 0x10000000;
        }
        arg0->m_sysFlg |= 0x08000000;
        break;
    case 1:
        if (arg0->m_sysFlg & 0x04000000) {
            func_0013FB3C((char *)&D_006E9840 + off, 6, 1);
            arg0->m_sysFlg |= 0x10000000;
        }
        break;
    case 2:
        func_0013FB3C((char *)&D_006E9840 + off, 7, 0);
        arg0->m_sysFlg |= 0x08000000;
        break;
    }
}

extern "C" void func_001D25E4(GamMan25E4 *arg0, int arg1)
{
    int off = 0x12540;

    switch (arg1) {
    case 0:
        if (arg0->m_sysFlg & 0x08000000) {
            func_0013FB3C((char *)&D_006E9840 + off, arg1, 7);
        }
        if (arg0->m_sysFlg & 0x10000000) {
            return func_0013FB3C((char *)&D_006E9840 + off, 1, 6);
        }
        return;
    case 1:
        if (arg0->m_sysFlg & 0x10000000) {
            return func_0013FB3C((char *)&D_006E9840 + off, arg1, 6);
        }
        break;
    case 2:
        if (arg0->m_sysFlg & 0x08000000) {
            func_0013FB3C((char *)&D_006E9840 + off, 0, 7);
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2724);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D27DC);

extern "C" void func_001D2A14(int arg0, unsigned int arg1, Vec2A14 *arg2)
{
    Vec2A14 stack;
    float x = arg2->x;
    float y = arg2->y;
    float z = arg2->z;
    int temp_v0;

    if (((arg1 >> 0x1C) & 3) == 1) {
        temp_v0 = X_func_001D2B8C(arg0, arg1);
        X_func_001D890C(temp_v0, (int)&stack);
        stack.x += x;
        stack.y += y;
        stack.z += z;
        X_func_001D89C4(temp_v0, (int)&stack);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2AAC);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2ADC);

extern "C" int func_001D2B10(Obj2B10 *arg0, int arg1)
{
    Obj2B10::iterator it;
    Obj2B10::iterator last;

    it = arg0->begin();
    last = arg0->end();

    while (it != last) {
        if (*(int *)((char *)(*it) + 0x100) == arg1) {
            return 1;
        }
        ++it;
    }
    return 0;
}

extern "C" int func_001D2B8C(int arg0, int arg1)
{
    return (*(int *)(int *)((char *)((((arg1 & 0x1FF) * 4) + arg0)) + 0x21340));
}


extern "C" int func_001D2BA8(int arg0, unsigned int arg1)
{
    int var_v0;

    if ((((arg1 >> 0x17) & 0x1F) != 5) || (var_v0 = Xiiu_func_001D2D00((int) arg0, arg1), (var_v0 == 0))) {
        var_v0 = M2C_FIELD((((arg1 & 0x1FF) * 4) + arg0), int *, 0x21540);
    }
    return var_v0;
}

extern "C" Obj2C0CItem *func_001D2C0C(Obj2C0C *arg0, int arg1)
{
    int val;
    Obj2C0C::iterator it;
    Obj2C0C::iterator last;

    it = arg0->begin();
    last = arg0->end();

    while (it != last) {
        unsigned int oid = (*it)->m_oid;
        if (((oid >> 0x17) & 0x1F) == 9) {
            func_001D1C80((int)arg0, oid, 0x41, (int)&val);
            if (val == arg1) {
                return *it;
            }
        }
        ++it;
    }
    return 0;
}

extern "C" void *func_001D2D00(Obj2D00 *arg0, unsigned int arg1)
{
    Obj2D00::iterator it;
    Obj2D00::iterator last;

    it = arg0->begin();
    last = arg0->end();

    while (it != last) {
        void *item = *it;
        if (*(unsigned int *)((char *)item + 0x100) == arg1) {
            return item;
        }
        ++it;
    }
    return 0;
}

extern "C" int func_001D2D7C(Obj2D7C *arg0, int arg1, int arg2)
{
    Obj2D7C::iterator it;
    Obj2D7C::iterator last;
    int out;

    it = arg0->begin();
    last = arg0->end();

    while (it != last) {
        X_func_001DB31C(*it, arg1, &out);
        if (arg2 == out) {
            return 1;
        }
        ++it;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2E2C);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D2FF0);

INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D327C);

extern "C" void func_001D3588(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x21F48)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x21F48)) | 0x40000);
}


INCLUDE_ASM("asm/nonmatchings/unk/001D1BEC", func_001D35AC);

extern "C" void func_001D3A14()
{
    X_func_001D9F08(X_func_001D2B8C());
}


extern "C" void func_001D3A38(int arg0, int arg1)
{
    if (!(M2C_FIELD(arg0, int *, 0x21F48) & 0x40)) {
        int val = M2C_FIELD(arg0, int *, 0x21FA0);
        int off = 0x418F0;
        char *p = (char *)&D_006FBD80 + off;
        M2C_FIELD(arg0, int *, 0x22218) = arg1;
        Xvpi_func_00130DE0(p, (int)(((float)(arg1 * val) / 255.0f) * 2.0f));
    }
}

extern "C" void func_001D3AC8(int arg0, int arg1)
{
    int temp_v0;

    if (arg1 != 0) {
        temp_v0 = M2C_FIELD(arg0, int *, 0x22214);
        if (temp_v0 != -1) {
            Xiii_func_001D3A38(arg0, temp_v0);
            M2C_FIELD(arg0, int *, 0x22214) = -1;
        }
    } else {
        M2C_FIELD(arg0, int *, 0x22214) = (int) M2C_FIELD(arg0, int *, 0x22218);
        Xiii_func_001D3A38(arg0, arg1);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0C0);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0E0);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001D1BEC", D_002FC0F0);
