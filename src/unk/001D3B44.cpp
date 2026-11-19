#include "include_asm.h"
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
extern "C" int X_func_0013FB3C(...) asm("func_0013FB3C");
extern "C" int X_func_001CBE38(...) asm("func_001CBE38");
extern "C" int X_func_001D046C(...) asm("func_001D046C");
extern "C" int X_func_001D0EFC(...) asm("func_001D0EFC");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D2B8C(...) asm("func_001D2B8C");
extern "C" int X_func_001D2BA8(...) asm("func_001D2BA8");
extern "C" int X_func_001D2D00(...) asm("func_001D2D00");
extern "C" int X_func_001D3A38(...) asm("func_001D3A38");
extern "C" int X_func_001D4A3C(...) asm("func_001D4A3C");
extern "C" int X_func_001D9F08(...) asm("func_001D9F08");
extern "C" int X_func_001DA228(...) asm("func_001DA228");
extern "C" int X_func_001DA740(...) asm("func_001DA740");
extern "C" int X_func_001DAC8C(...) asm("func_001DAC8C");
extern "C" int X_func_001DB17C(...) asm("func_001DB17C");
extern "C" int X_func_001DB18C(...) asm("func_001DB18C");
extern "C" int X_func_001DB19C(...) asm("func_001DB19C");
extern "C" int X_func_001DB31C(...) asm("func_001DB31C");
extern "C" int X_func_001DB520(...) asm("func_001DB520");
extern int D_006E9840;
extern int D_006FBD80;
extern int D_006FE6A0;
extern int D_00724EA0;
extern int D_007812C0;
extern int D_007B205C;




INCLUDE_ASM("asm/nonmatchings/unk/001D3B44", func_001D3B44);

INCLUDE_ASM("asm/nonmatchings/unk/001D3B44", func_001D4370);

extern "C" int func_001D44E4(int arg0)
{
    int a = M2C_FIELD(arg0, int *, 0x222C4);
    int b = M2C_FIELD(arg0, int *, 0x222C8);
    int var_a1 = 0;

    if ((a != 0) && (b != 0) && (M2C_FIELD((*(int *)&D_007B205C), int *, 0x190) == M2C_FIELD((*(int *)&D_007B205C), int *, 0x194))) {
        int mask = M2C_FIELD(arg0, int *, 0x21F48) & 0x8000;
        var_a1 = (mask == 0);
    }
    return var_a1;
}

INCLUDE_ASM("asm/nonmatchings/unk/001D3B44", func_001D4540);

extern "C" void func_001D4730(int arg0, Vec2_4730 *arg1)
{
    int i;
    int j;

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (arg1[j].x < arg1[i].x && arg1[j].y < arg1[i].y) {
                Vec2_4730 tmp = arg1[j];
                arg1[j] = arg1[i];
                arg1[i] = tmp;
            }
        }
    }
    Vec2_4730 tmp = arg1[3];
    arg1[3] = arg1[2];
    arg1[2] = tmp;
}

INCLUDE_ASM("asm/nonmatchings/unk/001D3B44", func_001D480C);

extern "C" void func_001D49D0(int arg0, unsigned int arg1, float fparg0)
{
    struct {
        int f0;
        int f4;
        int f8;
        int fC;
        float f10;
        char pad[0x1C];
    } stack;
    X_func_001D1C80(&D_007812C0, arg1, 0x18, &stack);
    stack.f4 = 4;
    stack.f10 = fparg0;
    X_func_001D1D5C(&D_007812C0, arg1, 0x18, &stack);
}

INCLUDE_RODATA("asm/nonmatchings/unk/001D3B44", D_002FC130);

extern "C" float func_001D4A3C(void *arg0, unsigned int arg1, int *arg2)
{
    struct {
        int f0;
        int f4;
        int f8;
        int fC;
        float f10;
        char pad[0x1C];
    } stack;
    float ret = 0.0f;

    X_func_001D1C80(arg0, arg1, 0x18, &stack);
    switch (stack.f4) {
    case 0:
        ret = 0.0f;
        break;
    case 1:
        ret = 17.0f;
        break;
    case 2:
        ret = 25.0f;
        break;
    case 3:
        ret = 45.0f;
        break;
    case 4:
        ret = stack.f10;
        break;
    default:
        return ret;
    }
    if (arg2 != 0) {
        *arg2 = stack.f0;
    }
    return ret;
}

extern "C" float func_001D4AEC(void *arg0, unsigned int arg1, int *arg2)
{
    struct {
        int f0;
        int f4;
        int f8;
        int fC;
        float f10;
        char pad[0x1C];
    } stack;
    float ret = 0.0f;

    X_func_001D1C80(arg0, arg1, 0x1005, &stack);
    switch (stack.f4) {
    case 0:
        ret = 0.0f;
        break;
    case 1:
        ret = 17.0f;
        break;
    case 2:
        ret = 25.0f;
        break;
    case 3:
        ret = 45.0f;
        break;
    case 4:
        ret = stack.f10;
        break;
    default:
        return ret;
    }
    if (arg2 != 0) {
        *arg2 = stack.f0;
    }
    return ret;
}

INCLUDE_RODATA("asm/nonmatchings/unk/001D3B44", D_002FC178);

INCLUDE_ASM("asm/nonmatchings/unk/001D3B44", func_001D4B9C);

INCLUDE_ASM("asm/nonmatchings/unk/001D3B44", func_001D50A8);

extern "C" void func_001D5444(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/001D3B44", func_001D544C);
