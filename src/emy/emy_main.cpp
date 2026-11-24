#include "include_asm.h"
#include "emy/emy.h"

struct EmyVtblEntry {
    short m_delta;
    short m_index;
    void *m_fn;
};

extern EmyMemFn D_002F14B0;
extern int vtbl_EmyMain asm("_vt$7EmyMain");
extern int vtbl_EmyManager asm("_vt$10EmyManager");

extern "C" void *X_memset(void *, int, int) asm("memset");
extern "C" void X_memset_v(void *, int, int) asm("memset");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_func_0014582C(EmyMain *, int) asm("func_0014582C");
extern "C" int X_func_00154734(EmyMain *) asm("func_00154734");
extern "C" void X_func_00154748(EmyMain *) asm("func_00154748");
extern "C" void X_func_0016278C(...) asm("func_0016278C");
extern "C" void X_func_001629C0(EmyManager *) asm("func_001629C0");
extern "C" void X_func_00162C88(int, int, unsigned short, int, int, int, int, int, int, int, int) asm("func_00162C88");
extern "C" EmyMain *X_func_001636A4(...) asm("func_001636A4");
extern "C" EmyMain *X_func_001636A4_ii(EmyManager *, int) asm("func_001636A4");
extern "C" int X_func_001656B4(EmyMain *) asm("func_001656B4");
extern "C" int X_func_00165710(EmyMain *) asm("func_00165710");
extern "C" void X_func_001661DC(EmyMain *, int) asm("func_001661DC");
extern "C" void X_func_00166378(EmyMain *, int) asm("func_00166378");
extern "C" void X_func_001664A4(EmyMain *, int) asm("func_001664A4");
extern "C" void X_func_00166518(EmyMain *) asm("func_00166518");
extern "C" int X_func_001665B8(EmyMain *, int) asm("func_001665B8");
extern "C" int X_func_00166A0C(EmyMain *) asm("func_00166A0C");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" void X_func_001DA740(void *, int, int) asm("func_001DA740");
extern "C" void X_func_00202F10(void *) asm("func_00202F10");

extern "C" void func_00162698(EmyManager *self);
extern "C" void func_00163570(EmyManager *self);

extern "C" void func_0016265C(EmyManager *self)
{
    self->m_vtbl = &vtbl_EmyManager;
    func_00162698(self);
    return X_memset_v(self->m_unk104, 0x64, sizeof(self->m_unk104));
}

extern "C" void func_00162698(EmyManager *self)
{
    X_memset(self->m_emy, 0, sizeof(self->m_emy));
    X_memset(self->m_slotVal, 0, sizeof(self->m_slotVal));
    self->m_flag134 = 0;
    self->m_flag135 = 0;
    self->m_unk138 = 0;
    self->m_unk13C = 0;
    X_memset(self->m_groups, 0, sizeof(self->m_groups));
    self->m_unk144 = 0;
    self->m_unk140 = 0;
}

extern "C" void EmyManager_vfunc06(EmyManager *self, int flags) asm("EmyManager__vfunc_06");
extern "C" void EmyManager_vfunc06(EmyManager *self, int flags)
{
    self->m_vtbl = &vtbl_EmyManager;
    func_00163570(self);
    if (flags & 1) {
        return X___builtin_delete(self);
    }
}

extern "C" int EmyManager__vfunc_04(EmyManager *self)
{
    X_func_0016278C();
    X_func_001629C0(self);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_0016278C);

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_001629C0);

extern "C" void func_00162AFC(EmyManager *self, int idx, int val)
{
    self->m_groups[idx].m_unk24 = val;
}

extern "C" int func_00162B14(EmyManager *self, int idx)
{
    int *p = (int *)((char *)self + 0x10);
    int *q = (int *)((char *)self + 0x8);
    int off = idx * 0x3C + 0x170;
    p = (int *)((char *)p + off);
    q = (int *)((char *)q + off);
    int old = *p;
    *p = old + 1;
    (*q)--;
    return old;
}

extern "C" void func_00162B50(EmyManager *self, int idx)
{
    self->m_groups[idx].m_unk28 = 0;
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00162B68);

extern "C" void func_00162C2C(int a0, int a1, unsigned short a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    X_func_00162C88(a0, a1, a2, a3, a4, a5, a6, a7, a8, 1, 0);
}

extern "C" void func_00162C5C(int a0, int a1, unsigned short a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    X_func_00162C88(a0, a1, a2, a3, a4, a5, a6, a7, 0, 0, a8);
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00162C88);

// NON_MATCHING: 31/38 differ (size 0x98, game 0x9C), 4 edits
#ifdef NON_MATCHING
extern "C" void func_001634D4(EmyManager *self, int id)
{
    int i = 0;
    EmyMain *e = self->m_emy[0];
    while (e == 0 || e->m_id != id) {
        i++;
        if (i == 0x40) {
            return;
        }
        e = self->m_emy[i];
    }
    EmyVtblEntry *entry = (EmyVtblEntry *)e->m_vtbl + 1;
    ((void (*)(char *, int))entry->m_fn)((char *)e + entry->m_delta, 3);
    self->m_emy[i] = 0;
    self->m_slotVal[i] = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_001634D4);
#endif

extern "C" void func_00163570(EmyManager *self)
{
    for (int i = 0; i < 0x40; i++) {
        EmyMain *e = self->m_emy[i];
        if (e != 0) {
            EmyVtblEntry *entry = (EmyVtblEntry *)e->m_vtbl + 1;
            ((void (*)(char *, int))entry->m_fn)((char *)e + entry->m_delta, 3);
        }
    }
    func_00162698(self);
}

extern "C" void func_001635E0(EmyManager *self)
{
    self->m_flag134 = 0;
    self->m_flag135 = 0;
    self->m_unk138 = 0;
    self->m_unk13C = 0;
    X_memset(self->m_groups, 0, sizeof(self->m_groups));
    self->m_unk144 = 0;
}

extern "C" void func_00163624(EmyManager *self, int id, int arg2)
{
    (void)self;
    (void)id;
    EmyMain *e = X_func_001636A4();
    if (e != 0) {
        X_func_001661DC(e, arg2);
    }
}

extern "C" void func_0016365C(EmyManager *self, int idx, int val)
{
    self->m_unk104[idx] = val;
}

extern "C" void func_0016366C(EmyManager *self, int id, int arg2)
{
    (void)self;
    (void)id;
    EmyMain *e = X_func_001636A4();
    if (e != 0) {
        X_func_00166378(e, arg2);
    }
}

extern "C" EmyMain *func_001636A4(EmyManager *self, int id)
{
    for (int i = 0; i < 0x40; i++) {
        EmyMain *e = self->m_emy[i];
        if (e != 0 && e->m_id == id) {
            return e;
        }
    }
    return 0;
}

extern "C" int func_001636E4(EmyManager *self, int idx)
{
    if (idx == 0) {
        return self->m_flag134 != 0;
    }
    return self->m_flag135 != 0;
}

extern "C" void func_00163700(EmyManager *self, int idx, int val)
{
    if (idx == 0) {
        self->m_unk138 = val;
        self->m_flag134 = 1;
        return;
    }
    self->m_unk13C = val;
    self->m_flag135 = 1;
}

extern "C" void func_00163720(EmyManager *self, int idx)
{
    if (idx == 0) {
        self->m_flag134 = 0;
        self->m_unk138 = 0;
    } else {
        self->m_flag135 = 0;
        self->m_unk13C = 0;
    }
}

extern "C" int func_0016373C()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    return X_func_001656B4(p);
}

extern "C" int func_00163770()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    return X_func_00165710(p);
}

extern "C" int func_001637A4()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        return p->m_unk0C;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_001637CC);

extern float D_002F1360[];

extern "C" float func_001638FC()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        goto fail;
    }
    {
        EmyVtblEntry *entry = (EmyVtblEntry *)p->m_vtbl + 3;
        float *tbl = D_002F1360;
        int r = ((int (*)(char *))entry->m_fn)((char *)p + entry->m_delta);
        return tbl[r];
    }
fail:
    return 0.0f;
}

extern float D_002F1390[];

extern "C" float func_00163958()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        goto fail;
    }
    {
        EmyVtblEntry *entry = (EmyVtblEntry *)p->m_vtbl + 3;
        float *tbl = D_002F1390;
        int r = ((int (*)(char *))entry->m_fn)((char *)p + entry->m_delta);
        return tbl[r];
    }
fail:
    return 0.0f;
}

extern float D_002F13C0[];

extern "C" float func_001639B4()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        goto fail;
    }
    {
        EmyVtblEntry *entry = (EmyVtblEntry *)p->m_vtbl + 3;
        float *tbl = D_002F13C0;
        int r = ((int (*)(char *))entry->m_fn)((char *)p + entry->m_delta);
        return tbl[r];
    }
fail:
    return 0.0f;
}

extern "C" int func_00163A10()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    int v = ((EmyObjStatView *)p->m_objStat)->m_flags & 0x200;
    return v != 0;
}

extern "C" void func_00163A44()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        EmyObjStatView *st = (EmyObjStatView *)p->m_objStat;
        st->m_flags &= ~0x400;
    }
}

extern "C" int func_00163A78(EmyManager *self)
{
    return (self->m_flag134 | self->m_flag135) != 0;
}

extern "C" int func_00163A8C()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    return p->m_unk150 != 0;
}

extern "C" void func_00163AB8(EmyManager *self, int *arg1, int *arg2)
{
    *arg1 = self->m_unk138;
    *arg2 = self->m_unk13C;
}

extern "C" void func_00163ACC(EmyManager *self, int id, int val)
{
    (void)self;
    (void)id;
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        p->m_unk10 = val;
    }
}

extern "C" int func_00163AF8()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        return p->m_unk14;
    }
    return 0;
}

extern "C" int func_00163B20()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        return p->m_curState;
    }
    return 0;
}

extern "C" int func_00163B48(EmyManager *self, int id, int val)
{
    (void)self;
    (void)id;
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        *(int *)((char *)p + 0x238) = val;
        return 1;
    }
    return 0;
}

extern "C" int func_00163B80()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        return X_func_00154734(p);
    }
    return 1;
}

extern "C" void func_00163BB8()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        X_func_00154748(p);
    }
}

extern "C" void func_00163BE4()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return;
    }
    EmyVtblEntry *entry = (EmyVtblEntry *)p->m_vtbl + 3;
    ((void (*)(char *))entry->m_fn)((char *)p + entry->m_delta);
}

extern "C" void func_00163C24()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        p->m_unk18 = 1;
    }
}

extern "C" void func_00163C50()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        p->m_unk18 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00163C74);

extern "C" int func_00163D90()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        return p->m_unk1D8;
    }
    return 0;
}

extern int D_002F1470[];

extern "C" int func_00163DB8()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    int *tbl = D_002F1470;
    EmyVtblEntry *entry = (EmyVtblEntry *)p->m_vtbl + 3;
    int r = ((int (*)(char *))entry->m_fn)((char *)p + entry->m_delta);
    return tbl[r];
}

extern "C" void func_00163E10(EmyManager *self, int id, int arg2)
{
    (void)self;
    (void)id;
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        X_func_001664A4(p, arg2);
    }
}

extern "C" void func_00163E48()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        X_func_00202F10(p->m_unk1F0);
    }
}

extern "C" void func_00163E74()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        p->m_unk1E4 = 6;
    }
}

extern "C" int func_00163EA0(EmyManager *self, int id, int arg2)
{
    EmyMain *p = X_func_001636A4_ii(self, id);
    if (p != 0) {
        return X_func_001665B8(p, arg2);
    }
    return 0;
}

extern "C" void func_00163EE4(EmyManager *self, int id, int arg2)
{
    (void)self;
    (void)id;
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        X_func_0014582C(p, arg2);
    }
}

extern "C" int func_00163F1C()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        return *(int *)((char *)p + 0x238);
    }
    return 0;
}

extern "C" int func_00163F44()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    EmyVtblEntry *entry = (EmyVtblEntry *)p->m_vtbl + 3;
    int r = ((int (*)(char *))entry->m_fn)((char *)p + entry->m_delta);
    if (r != 0xA) {
        return 0;
    }
    return *(int *)((char *)p + 0x24C);
}

extern "C" int func_00163F9C()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    EmyVtblEntry *entry = (EmyVtblEntry *)p->m_vtbl + 3;
    int r = ((int (*)(char *))entry->m_fn)((char *)p + entry->m_delta);
    if (r != 6) {
        return 0;
    }
    return *(int *)((char *)p + 0x23C);
}

extern "C" int func_00163FF4()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    EmyVtblEntry *entry = (EmyVtblEntry *)p->m_vtbl + 3;
    int r = ((int (*)(char *))entry->m_fn)((char *)p + entry->m_delta);
    if (r != 8) {
        return 0;
    }
    return *(int *)((char *)p + 0x248);
}

extern "C" void func_0016404C()
{
    EmyMain *p = X_func_001636A4();
    if (p != 0) {
        X_func_00166518(p);
    }
}

extern "C" int func_00164078()
{
    EmyMain *p = X_func_001636A4();
    if (p == 0) {
        return 0;
    }
    return X_func_00166A0C(p);
}

extern "C" void func_001640AC(EmyManager *self, int id, int val)
{
    for (int i = 0; i < 0x40; i++) {
        EmyMain *e = self->m_emy[i];
        if (e != 0 && e->m_id == id) {
            int *slot = (int *)((i * 4) + (int)self);
            slot[0xCC] = val;
        }
    }
}

extern "C" int func_001640E8(EmyManager *self)
{
    int count = 0;
    int off = 0x300;
    for (int rem = 0x3F; rem >= 0; rem--) {
        char *p = (char *)self + off;
        off += 4;
        if (*(int *)(p + 0x30) != 0) {
            count++;
        }
    }
    return count;
}

extern "C" void *func_00164118(EmyMain *self, int id, int arg2, void *objStat, int arg4, int arg5, int arg6)
{
    (void)arg2;
    (void)arg4;
    self->m_id = id;
    self->m_vtbl = &vtbl_EmyMain;
    self->m_nextState = -1;
    self->m_unkE8 = arg5;
    self->m_unk08 = 1;
    self->m_unk0C = 1;
    self->m_unk10 = 0;
    self->m_unk14 = 0;
    self->m_brain = 0;
    self->m_objStat = 0;
    self->m_curOut = 0;
    self->m_unk28 = 1;
    self->m_unk2C = 1;
    self->m_flags30 = 0;
    self->m_unk150 = 0;
    self->m_callback = D_002F14B0;
    self->m_unk1C4 = 1.0f;
    self->m_unk06 = 0;
    self->m_unk1EC = 0;
    self->m_unk1F0 = 0;
    self->m_unk1F8 = 0;
    X_memset(&self->m_unk154, 0, 0x70);
    self->m_objStat = objStat;
    if (arg6 != 0) {
        X_func_001DA740(objStat, 0x59, arg6);
    }
    return X_memset(self->m_unk48, 0, sizeof(self->m_unk48));
}

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", EmyMain__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00164364);

INCLUDE_ASM("asm/nonmatchings/emy/emy_main", func_00164508);

extern "C" void EmyMain__vfunc_05(EmyMain *self)
{
    self->m_stateChanged = 0;
    int next = self->m_nextState;
    if (next != -1) {
        int st = X_func_0016968C(self->m_brain, next);
        if (st != 0) {
            self->m_curState = st;
            self->m_stateChanged = 1;
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1290);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F12A0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F12D0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1300);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1330);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1360);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1390);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F13C0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F13F0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1400);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1410);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1420);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1430);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1440);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1450);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1460);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F1470);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F14A0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F14B0);

INCLUDE_RODATA("asm/nonmatchings/emy/emy_main", D_002F14B8);
