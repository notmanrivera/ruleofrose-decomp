#include "include_asm.h"
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


INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4790);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E484C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4908);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4B48);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E4EBC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E50C8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5250);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5428);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5540);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5660);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5B60);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5BE0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5C40);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5D1C);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E5E58);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6368);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E63C0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E649C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6570);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6734);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6CAC);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E6E00);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7094);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7184);

extern "C" void func_001E71F4(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E71FC);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7340);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7414);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E747C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7544);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E76B8);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7910);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7A20);

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

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7D08);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7D7C);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7DE8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7E50);

extern "C" int TskTest__vfunc_04()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7ED8);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskLogger__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7F28);

extern "C" void TskMtnMove__vfunc_05(void) {
}

extern "C" void TskMtnMove__vfunc_04(int arg0)
{
    short idx;
    long ent;
    int fp;
    short base;
    int off;
    int p;

    idx = M2C_FIELD(arg0, short *, 0x82);
    if (idx >= 0) {
        p = *(int *) (arg0 + M2C_FIELD(arg0, short *, 0x84));
        p += idx * 8;
        ent = *((long *) p - 1);
        fp = (int) (ent >> 32);
    } else {
        fp = M2C_FIELD(arg0, int *, 0x84);
    }
    base = M2C_FIELD(arg0, short *, 0x80);
    off = (idx >= 0) ? (short) ent + base : base;
    ((void (*)(int)) fp)(arg0 + off);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskMtnMove__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E85D0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E89C0);

extern "C" int func_001E8F88(int arg0)
{
    return X_func_0010A834__8DogActor((int)&D_006FE6A0 + ((*(int *)(int *)((char *)(arg0) + 0xC)) * 0x4D0)) == 0;
}


extern "C" int func_001E8FBC()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E8FC4);

extern "C" void TskMtnMove2__vfunc_05(void) {
}

extern "C" void TskMtnMove2__vfunc_04(int arg0)
{
    short idx;
    long ent;
    int fp;
    short base;
    int off;
    int p;

    idx = M2C_FIELD(arg0, short *, 0xCE);
    if (idx >= 0) {
        p = *(int *) (arg0 + M2C_FIELD(arg0, short *, 0xD0));
        p += idx * 8;
        ent = *((long *) p - 1);
        fp = (int) (ent >> 32);
    } else {
        fp = M2C_FIELD(arg0, int *, 0xD0);
    }
    base = M2C_FIELD(arg0, short *, 0xCC);
    off = (idx >= 0) ? (short) ent + base : base;
    ((void (*)(int)) fp)(arg0 + off);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskMtnMove2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E93EC);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD900);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD910);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD920);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD940);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD948);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD950);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD958);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD960);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD968);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD970);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD978);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD980);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD988);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD990);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD998);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA48);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA50);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA58);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA70);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E9614);
