#include "include_asm.h"
#include "game/gamman.h"
struct StatElem16 {
    int m_unk00;
    int m_pad[3];
};
extern "C" char *func_001D2B8C(void *, unsigned int);
extern "C" void *func_001D2BA8(void *, unsigned int);
extern "C" void func_001D8DC4(void *);
extern "C" void X_func_001D890C_v(void *, void *) asm("func_001D890C");
extern "C" void func_001DB71C(void *, void *);
extern const int D_002FC1F8[][8];
extern "C" float func_001D817C(int, int *, void *, int);
extern "C" void *X_memset_p(void *, int, unsigned int) asm("memset");
extern "C" int func_0017DED0(void *, int, void *, float);
extern char D_006FBD80[];
extern "C" void X_func_001D83C0_v(void *, int) asm("func_001D83C0");
extern "C" void func_0017C340(void *, void *, void *, int, float, float);
extern "C" float func_0017DD5C(float, void *, int, void *);
extern "C" int Xiiiiii_func_001D81F0(int, int, int, int, int) asm("func_001D81F0");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_alloc__9BedMemoryiPCciii(...) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_func_001D83C0(...) asm("func_001D83C0");
extern "C" int X_memset(...) asm("memset");
extern int D_006E9800;
extern int D_007811B4;

// NON_MATCHING: 4/57 differ, 6 edits
#ifdef NON_MATCHING
struct Cb8 {
    int w0;
    int w1;
};

extern const Cb8 D_002FC1D8;
extern "C" int func_001D046C(void *, unsigned int);
extern "C" void func_001D890C(void *, void *);
extern "C" float func_001D4A3C(void *, unsigned int, int);
extern "C" int func_001D7C20(void *, int, unsigned int, unsigned int, void *);

extern "C" int func_001D5610(void *arg0, unsigned int arg1)
{
    if (func_001D046C(arg0, arg1) == 0) {
        return 0;
    }
    char *obj = func_001D2B8C(arg0, arg1);
    int unk114 = *(int *)(obj + 0x114);
    if (*(int *)(obj + 0x120) & 0x80) {
        return 0;
    }
    u_long128 pos;
    func_001D890C(obj, &pos);
    int off = 0x225B0;
    u_long128 *dst = (u_long128 *)((char *)arg0 + off);
    register u_long128 tmp PS2_REG("$6") = pos;
    *dst = tmp;
    *(float *)((char *)arg0 + 0x225A0) = func_001D4A3C(arg0, arg1, 0);
    *(Cb8 *)((char *)arg0 + 0x225D0) = D_002FC1D8;
    return func_001D7C20(arg0, unk114, arg1, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5610);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D56F4);

#ifdef NON_MATCHING
struct Cb8_58D8 {
    unsigned int m_a;
    unsigned int m_b;
};

extern const Cb8_58D8 D_002FC1E0;
extern "C" float Xff_sinf(float) asm("sinf");
extern "C" float Xff_cosf(float) asm("cosf");
extern "C" void *func_001D8064(void *arg0, void *arg1, void *arg2, int arg3);

extern "C" int func_001D58D8(void *arg0, void *arg1, float fparg0) {
    register void *p1 PS2_REG("$16") = arg1;
    register void *p0 PS2_REG("$17") = arg0;
    void *temp_v1 = *(void **)((char *)p0 + 0x22094);
    if (temp_v1 == 0 || (*(int *)((char *)temp_v1 + 0x120) & 0x80)) {
        return 0;
    }
    func_001D8064(p0, p1, *(void **)((char *)temp_v1 + 0x114), 0);
    {
        register u_long128 *dst1 PS2_REG("$2") = (u_long128 *)((char *)p0 + 0x225B0);
        register u_long128 tmp1 PS2_REG("$6") = *(u_long128 *)p1;
        *dst1 = tmp1;
    }
    *(float *)p1 += Xff_sinf(fparg0) * *(float *)((char *)p0 + 0x21FC4);
    *(float *)((char *)p1 + 8) += Xff_cosf(fparg0) * *(float *)((char *)p0 + 0x21FC4);
    {
        register u_long128 *dst2 PS2_REG("$2") = (u_long128 *)((char *)p0 + 0x225C0);
        register u_long128 tmp2 PS2_REG("$6") = *(u_long128 *)p1;
        *dst2 = tmp2;
    }
    {
        register float f1 PS2_REG("$f1") = *(float *)((char *)p0 + 0x21FBC);
        register float f0 PS2_REG("$f0") = *(float *)((char *)p0 + 0x21FC0);
        *(float *)((char *)p0 + 0x225A0) = f1;
        *(float *)((char *)p0 + 0x225A4) = f0;
    }
    *(Cb8_58D8 *)((char *)p0 + 0x225D0) = D_002FC1E0;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D58D8);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5A0C);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5BC8);

extern "C" void func_001D5DA0(void *arg0, int arg1) {
    GamList<StatElem16>::iterator it;
    GamList<StatElem16>::iterator last;
    GamList<StatElem16> *list = *(GamList<StatElem16> **)((char *)arg0 + 0x2246C);
    if (list->size() != 0) {
        it = list->begin();
        last = list->end();
        while (it != last) {
            if ((*it).m_unk00 == arg1) {
                list->erase(it);
                return;
            }
            ++it;
        }
    }
}

// NON_MATCHING: 26/109 differ, 38 edits
#ifdef NON_MATCHING
extern "C" void func_001D5EC4(void *arg0, int arg1) {
    GamList<StatElem16>::iterator it;
    GamList<StatElem16>::iterator last;
    if ((*(GamList<StatElem16> **)((char *)arg0 + 0x2246C))->size() != 0 && arg1 >= 0) {
        switch (arg1) {
        case 3:
            it = (*(GamList<StatElem16> **)((char *)arg0 + 0x2246C))->begin();
            last = (*(GamList<StatElem16> **)((char *)arg0 + 0x2246C))->end();
            while (it != last) {
                if (((unsigned int)(*it).m_unk00 >> 30) == 3) {
                    it = (*(GamList<StatElem16> **)((char *)arg0 + 0x2246C))->erase(it);
                } else {
                    ++it;
                }
            }
            break;
        case 0:
        case 1:
        case 2:
            if ((*(GamList<StatElem16> **)((char *)arg0 + 0x2246C))->size() != 0) {
                (*(GamList<StatElem16> **)((char *)arg0 + 0x2246C))->clear();
            }
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D5EC4);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D6078);

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D68A0);

extern "C" void func_001D7B00(void) {
}

extern "C" int func_001D7B08(void *arg0, unsigned int arg1, int arg2)
{
    int off = 0x8542C;
    float pos[4];
    int *out[4];

    switch ((arg1 >> 28) & 3) {
    case 1: {
        void *obj = func_001D2B8C(arg0, arg1);
        if (((arg1 >> 23) & 0x1F) == 0) {
            func_001D8DC4(*(void **)((char *)arg0 + 0x22090));
        }
        X_func_001D890C_v(obj, pos);
        break;
    }
    case 2:
        func_001DB71C(func_001D2BA8(arg0, arg1), pos);
        break;
    }

    func_0017C340(D_006FBD80 + off, pos, out, 0, 40.0f, 0.0f);
    int **p = &out[arg2];
    if (*p == 0) {
        return -1;
    }
    X_func_001D83C0_v(arg0, 0);
    return **p;
}

INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D7C20);

extern "C" float func_001D7DE4(void *arg0, void *arg1)
{
    int *sp[4];
    int off = 0x8542C;
    func_0017C340(D_006FBD80 + off, arg1, sp, 0, 40.0f, 0.0f);
    int i = *(int *)((char *)arg0 + 0x22AB0);
    int *p = sp[i];
    if (p == 0) {
        for (i = 0; i < 4; i++) {
            if (sp[i] != 0) {
                break;
            }
        }
        if (i == 4) {
            return 0.0f;
        }
        p = sp[i];
    }
    return func_001D817C((int)arg0, p, arg1, i);
}

extern "C" void func_001D7EB8()
{
    X_func_001D83C0();
}


extern "C" void *func_001D7ED4(void *arg0, int arg1, int arg2)
{
    X_func_001D83C0_v(arg0, arg2);
    char *entry = (char *)&D_007811B4 + arg2 * 0x18;
    char *ptr = 0;
    if (*(int *)(entry + 4) != 0) {
        char *base = *(char **)(entry + 0xC);
        if (base != 0) {
            ptr = base + arg1 * 0x90;
        }
    }
    return ptr;
}

extern "C" int func_001D7F48(void *arg0, void *arg1, int arg2)
{
    int sp[4];
    int off = 0x8542C;
    X_func_001D83C0_v(arg0, arg2);
    func_0017C340(D_006FBD80 + off, arg1, sp, 0, 40.0f, 0.0f);
    return sp[arg2];
}

extern "C" void *func_001D7FB8(void *arg0, void *arg1, int *arg2, int arg3)
{
    X_func_001D83C0_v(arg0, arg3);
    char *entry = (char *)&D_007811B4 + arg3 * 0x18;
    int idx = func_0017DED0(entry, *arg2, arg1, 40.0f);
    if (idx == -1) {
        return 0;
    }
    char *ptr = 0;
    if (*(int *)(entry + 4) != 0) {
        char *base = *(char **)(entry + 0xC);
        if (base != 0) {
            ptr = base + idx * 0x90;
        }
    }
    return ptr;
}

extern "C" void *func_001D8064(void *arg0, void *arg1, void *arg2, int arg3)
{
    void *sp[4];
    int off = 0x8542C;
    X_func_001D83C0_v(arg0, arg3);
    X_memset_p(sp, 0, sizeof(sp));
    sp[arg3] = arg2;
    func_0017C340(D_006FBD80 + off, arg1, sp, arg2 != 0, 200.0f, 0.0f);
    if (sp[arg3] != 0 && (*(int *)((char *)sp[arg3] + 8) & 4) != 0) {
        return 0;
    }
    return sp[arg3];
}

extern "C" void func_001D8114(void) {
}

// NON_MATCHING: 6/24 differ, 6 edits
#ifdef NON_MATCHING
extern "C" void *func_001D811C(int arg0, int arg1, float *arg2, int arg3)
{
    char *entry = (char *)&D_007811B4 + arg3 * 0x18;
    register char *ptr PS2_REG("$4") = 0;
    if (*(int *)(entry + 4) != 0) {
        char *base = *(char **)(entry + 0xC);
        if (base != 0) {
            ptr = base + arg1 * 0x90;
        }
    }
    arg2[0] = *(float *)(ptr + 0x10);
    arg2[1] = *(float *)(ptr + 0x14);
    arg2[2] = *(float *)(ptr + 0x18);
    return ptr;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D811C);
#endif

extern "C" float func_001D817C(int arg0, int *arg1, void *arg2, int arg3)
{
    float ret = 100000.0f;
    if (arg1 != 0) {
        ret = func_0017DD5C(0.0f, (char *)&D_007811B4 + arg3 * 0x18, *arg1, arg2);
    }
    return ret;
}

extern "C" void func_001D81C4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    struct { char pad0[512]; } stack;
    Xiiiiii_func_001D81F0(arg0, arg6, arg1, arg2, (int)&stack);
}

#ifdef NON_MATCHING
extern int D_007811AC;
extern "C" int func_0017D298(void *, void *);

struct StatTblEntry81F0 {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
};

struct StatCallParam81F0 {
    int m_unk00;
    int *m_unk04;
    int *m_unk08;
    void *m_unk0C;
};

extern "C" int func_001D81F0(int arg0, int arg1, int arg2, int arg3, int arg4) {
    StatCallParam81F0 param;
    int sp10[4];
    int sp20[4];
    int ptr1;
    int ptr2;
    int off;
    StatTblEntry81F0 *e1;
    StatTblEntry81F0 *e2;
    int ret;

    (void)arg0;
    X_memset_p(sp10, 0, sizeof(sp10));
    X_memset_p(sp20, 0, sizeof(sp20));

    ptr2 = 0;
    off = arg1 * 0x18;
    ptr1 = 0;
    e1 = (StatTblEntry81F0 *)((char *)&D_007811B4 + off);
    e2 = (StatTblEntry81F0 *)((unsigned int)((char *)&D_007811AC + off) + 8);

    if (e1->m_unk04 != 0 && e1->m_unk0C != 0) {
        ptr1 = e1->m_unk0C + arg2 * 0x90;
    }
    sp10[arg1] = ptr1;

    if (e2->m_unk04 != 0) {
        int base2 = e2->m_unk0C;
        ptr2 = 0;
        if (base2 != 0) {
            ptr2 = base2 + arg3 * 0x90;
        }
    }
    sp20[arg1] = ptr2;

    param.m_unk00 = arg1;
    param.m_unk04 = sp10;
    param.m_unk08 = sp20;
    param.m_unk0C = (void *)arg4;

    ret = func_0017D298(e2, &param);
    if (ret != 0) {
        ret = *(int *)((char *)arg4 + 0x1FC);
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D81F0);
#endif

extern "C" int func_001D831C()
{
    return 0;
}


extern "C" int func_001D8324()
{
    return 0;
}


extern "C" int func_001D832C()
{
    return 0;
}


extern "C" int func_001D8334()
{
    return 0;
}


extern "C" int func_001D833C()
{
    return 0;
}


extern "C" int func_001D8344()
{
    return 0;
}


extern "C" int func_001D834C()
{
    return 0;
}


extern "C" void func_001D8354(void) {
}

extern "C" void func_001D835C(void) {
}

extern "C" int func_001D8364()
{
    return 0;
}


extern "C" int func_001D836C(void *arg0, int arg1)
{
    char *entry = (char *)&D_007811B4 + *(int *)((char *)arg0 + 0x22AB0) * 0x18;
    char *ptr = 0;
    if (*(int *)(entry + 4) != 0) {
        char *base = *(char **)(entry + 0xC);
        if (base != 0) {
            ptr = base + arg1 * 0x90;
        }
    }
    return *(int *)(ptr + 8);
}

extern "C" void func_001D83C0(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x22AB0)) = arg1;
}


extern "C" int func_001D83D0(int arg0, int arg1, int arg2, int arg3)
{
    int ret = -1;
    switch (arg1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
        for (int i = 0; D_002FC1F8[i][arg1] != -1; i++) {
            if (arg2 == D_002FC1F8[i][arg1]) {
                ret = D_002FC1F8[i][arg3];
                break;
            }
        }
        break;
    case 5:
        break;
    case 0x63:
        ret = D_002FC1F8[arg2][arg3];
        break;
    }
    return ret;
}

extern "C" int func_001D84A8()
{
    return 1;
}


extern "C" int func_001D84B0()
{
    return 0;
}


extern "C" int func_001D84B8()
{
    return 0;
}


extern "C" int func_001D84C0()
{
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1F0);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC1F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC3D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC3E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC3F8);

// NON_MATCHING: func_001D84C8 itself is MATCH (0xd4), blocked on .rodata alignment of D_002FC418 (.align 3 before D_002FC418)
#ifdef NON_MATCHING
extern "C" void *X_alloc__9BedMemoryiPCciii_p(void *, int, const char *, int, int, int) asm("alloc__9BedMemoryiPCciii");
extern "C" void func_001D84C8(void *arg0, int arg1, int arg2)
{
    int size = arg2 * 2;
    *(void **)((char *)arg0 + 4) = X_alloc__9BedMemoryiPCciii_p(&D_006E9800, size, "game/gamstat.cpp", 0x1F, 0, 2);
    *(void **)((char *)arg0 + 8) = X_alloc__9BedMemoryiPCciii_p(&D_006E9800, size, "game/gamstat.cpp", 0x21, 0, 2);
    X_memset_p(*(void **)((char *)arg0 + 4), 0, size);
    X_memset_p(*(void **)((char *)arg0 + 8), 0, size);
    *(int *)((char *)arg0 + 0xC) = arg1;
    *(int *)arg0 = arg2;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamstat", func_001D84C8);
#endif

INCLUDE_RODATA("asm/nonmatchings/game/gamstat", D_002FC418);
