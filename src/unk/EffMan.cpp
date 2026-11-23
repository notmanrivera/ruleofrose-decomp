#include "include_asm.h"
#include "unk/EffMan.h"

struct EffNameTable {
    const char *names[54];
};
extern "C" const EffNameTable D_002F2CD0;

struct Eff0Poly {
    unsigned short m_flags;             // +0x00
    unsigned short m_pad02;             // +0x02
    int m_timer;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    float m_zDepth;                     // +0x10
    void *m_parent;                     // +0x14
    int m_kind;                         // +0x18
    int m_delay;                        // +0x1C
    virtual int vfunc_08(int);          // +0x08 (dtor)
    virtual void vfunc_10();            // +0x10 (init)
    virtual void vfunc_18();            // +0x18 (term)
    virtual int vfunc_20();             // +0x20 (exec)
    virtual void vfunc_28();            // +0x28 (liveExec)
    virtual void vfunc_30(int *);       // +0x30 (render)
    virtual void vfunc_38();            // +0x38
    virtual void vfunc_40();            // +0x40
    virtual void vfunc_48();            // +0x48
    virtual void vfunc_50();            // +0x50
    virtual void vfunc_58();            // +0x58
    virtual void vfunc_60();            // +0x60 (updateZDepth)
};

struct EffSceneStub {
    char pad0[0x2050];
    char m_lightPool[0x2AA10 - 0x2050];
    char m_unk2AA10[0x2AA84 - 0x2AA10];
    int m_fogFlag;                      // +0x2AA84
    char pad2AA88[0x2AAE0 - 0x2AA88];
    char m_fogParam[0x2AB70 - 0x2AAE0];
    char m_camera[0x10];                // +0x2AB70
};

struct EffLoadInfo {
    EffManEntry *entry;                 // +0x00
    int arg1;                           // +0x04
    char name[0x20];                    // +0x08
    void *arg3;                         // +0x28
    int pad_2C;                         // +0x2C
};

extern "C" unsigned int X_strlen(const char *) asm("strlen");
extern "C" void *X_memcpy(void *, const void *, unsigned int) asm("memcpy");
extern "C" void *X_memmove(void *, const void *, unsigned int) asm("memmove");
extern "C" void *X_memset(void *, int, unsigned int) asm("memset");
extern "C" int X_memcmp(const void *, const void *, unsigned int) asm("memcmp");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");

extern "C" void X___10FileReader(void *) asm("__10FileReader");
extern "C" void X_dtor_10FileReader(void *, int) asm("_$_10FileReader");
extern "C" void X___11FileReadReq(EffFileReadReq *) asm("__11FileReadReq");
extern "C" void *X_alloc__9BedMemoryii(void *, int, int) asm("alloc__9BedMemoryii");
extern "C" void X_free__9BedMemoryPv(void *, void *) asm("free__9BedMemoryPv");
extern "C" int X_func_001BE524__10FileReaderP11FileReadReqi(int *, EffFileReadReq *, int) asm("func_001BE524__10FileReaderP11FileReadReqi");

extern "C" int X_func_0016AC84() asm("func_0016AC84");
extern "C" void X_func_0016ADD8() asm("func_0016ADD8");
extern "C" void X_func_00176C50(EffMan *) asm("func_00176C50");
extern "C" void X_func_0017756C(EffMan *, int) asm("func_0017756C");
extern "C" void X_func_0017762C(EffMan *) asm("func_0017762C");
extern "C" int X_func_001776C4(EffMan *) asm("func_001776C4");
extern "C" int X_func_001779B8(EffMan *) asm("func_001779B8");
extern "C" int X_func_00177A8C(EffMan *) asm("func_00177A8C");
extern "C" void X_func_00177C00(EffMan *, int) asm("func_00177C00");
extern "C" int X_func_00177D20(EffMan *, int, float) asm("func_00177D20");
extern "C" void X_func_00177E24(EffMan *, int) asm("func_00177E24");
extern "C" int X_func_00177E9C(EffMan *) asm("func_00177E9C");
extern "C" void X_func_00177EF8(EffMan *, int) asm("func_00177EF8");
extern "C" void X_func_00177F54(int, char *, const char *) asm("func_00177F54");
extern "C" void X_func_001780C0(EffMan *) asm("func_001780C0");
extern "C" int X_func_00178148(EffMan *, int, const char *) asm("func_00178148");
extern "C" int X_func_001781D0(EffMan *) asm("func_001781D0");
extern "C" int X_func_0017820C(EffMan *, int, const char *, void *) asm("func_0017820C");
extern "C" int X_func_001782CC(EffMan *, EffLoadInfo *) asm("func_001782CC");
extern "C" int X_func_00178894(EffMan *, int) asm("func_00178894");

extern "C" int X_func_0021A158(int, void *) asm("func_0021A158");
extern "C" int X_func_0021B550(int, int, unsigned long) asm("func_0021B550");
extern "C" int X_func_0021F7E0(int) asm("func_0021F7E0");
extern "C" void X_func_00223240(int, int) asm("func_00223240");
extern "C" void X_func_00223250(int, int) asm("func_00223250");
extern "C" void X_func_00223260(int, int) asm("func_00223260");
extern "C" int X_func_00223378(int) asm("func_00223378");
extern "C" void X_func_00223398(int, int) asm("func_00223398");
extern "C" int X_func_00226C58(int, void *, int) asm("func_00226C58");
extern "C" int X_getViewMatrix__9DogCamera(void *) asm("getViewMatrix__9DogCamera");
extern "C" int X_apply__C12DogLightPoolPvifi(void *, int, int, float, int) asm("apply__C12DogLightPoolPvifi");

extern int D_00298E08;
extern int D_00298E0C;
extern int D_006E9800;


extern "C" void func_00176A34(void) {
}

extern "C" void *func_00176A3C(EffMan *self)
{
    X___10FileReader(self->m_reader);
    self->m_scene = 0;
    self->m_nextIdx = 0;
    self->m_activeCount = 0;
    X_memset(self->m_ptrs, 0, 0x440);
    X_memset(self->m_sortList, 0, 0x440);
    self->m_effBinBuf = 0;
    return X_memset(self->m_entries, 0, 0x600);
}


extern "C" void func_00176AA0(EffMan *self, int arg1)
{
    X_func_00176C50(self);
    X_dtor_10FileReader(self->m_reader, 2);
    if (arg1 & 1) {
        return X___builtin_delete(self);
    }
}

extern "C" int func_00176AFC(EffMan *self, int arg1, void *arg2)
{
    self->m_scene = arg2;
    self->m_nextIdx = 0;
    self->m_activeCount = 0;
    X_memset(self->m_ptrs, 0, 0x440);
    for (int i = 0; i < 0x110; i++) {
        self->m_sortList[i] = i;
    }
    self->m_unk1294 = -1;
    self->m_unk1298 = -1;
    self->m_queueCount = 0;
    D_00298E08 = (int)self->m_scene;
    D_00298E0C = arg1;
    X_func_0016AC84();
    X_func_001780C0(self);
    X_func_0017820C(self, 1, 0, (void *)1);
    X_func_0017820C(self, 2, 0, (void *)1);
    X_func_0017820C(self, 3, 0, (void *)1);
    X_func_0017820C(self, 4, 0, (void *)1);
    X_func_0017820C(self, 0x32, 0, (void *)1);
    X_func_0017820C(self, 0x1F, 0, (void *)1);
    X_func_0017820C(self, 0x26, 0, (void *)1);
    X_func_0017820C(self, 0x27, 0, (void *)1);
    X_func_0017820C(self, 0x1A, 0, (void *)1);
    return 1;
}

extern "C" void func_00176C50(EffMan *self)
{
    void *buf;

    X_func_0017762C(self);
    X_func_00178894(self, 1);
    buf = self->m_effBinBuf;
    if (buf != 0) {
        X_free__9BedMemoryPv(&D_006E9800, buf);
        self->m_effBinBuf = 0;
    }
    self->m_req.m_buf = 0;
    self->m_req.m_unk20 = 1;
    X_func_001BE524__10FileReaderP11FileReadReqi(self->m_reader, &self->m_req, 0);
    self->m_scene = 0;
    D_00298E08 = 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_00176CC8);

extern "C" int func_001774E0(EffMan *self, Eff0 *arg1)
{
    int idx = X_func_001776C4(self);
    if (idx == -1) {
        idx = X_func_00177E9C(self);
        if (idx == -1) {
            return -1;
        }
        X_func_00177EF8(self, idx);
    }
    self->m_ptrs[idx] = arg1;
    self->m_activeCount++;
    return idx;
}

extern "C" void func_0017756C(EffMan *self, int arg1)
{
    if (self->m_ptrs[arg1] != 0) {
        if (arg1 == self->m_unk1294) {
            self->m_unk1294 = -1;
        } else if (arg1 == self->m_unk1298) {
            self->m_unk1298 = -1;
        }
        unsigned int flags = self->m_ptrs[arg1]->m_flags;
        if ((flags >> 4) & 1) {
            X_func_00177E24(self, arg1);
        }
        if (self->m_ptrs[arg1] != 0) {
            ((Eff0Poly *)self->m_ptrs[arg1])->vfunc_08(3);
        }
        self->m_ptrs[arg1] = 0;
        self->m_activeCount--;
    }
}

extern "C" void func_0017762C(EffMan *self)
{
    for (int i = 0; i < 0x110; i++) {
        if (self->m_ptrs[i] != 0) {
            ((Eff0Poly *)self->m_ptrs[i])->vfunc_08(3);
            self->m_ptrs[i] = 0;
        }
    }
    self->m_activeCount = 0;
    self->m_unk1294 = -1;
    self->m_unk1298 = -1;
    self->m_queueCount = 0;
    X_func_00178894(self, 0);
}

extern "C" int func_001776C4(EffMan *self)
{
    int idx = self->m_nextIdx;
    for (int i = 0; i < 0x100; i++) {
        if (self->m_ptrs[idx] == 0) {
            self->m_nextIdx = (idx + 1) % 0x100;
            return idx;
        }
        idx = (idx + 1) % 0x100;
    }
    return -1;
}

extern "C" void func_0017772C(EffMan *self)
{
    int i;
    Eff0 **p = &self->m_ptrs[0x100];
    for (i = 0x100; i < 0x110; i++, p++) {
        if (*p != 0) {
            if (((Eff0Poly *)*p)->vfunc_20() == 0) {
                if (self->m_ptrs[i] != 0) {
                    ((Eff0Poly *)self->m_ptrs[i])->vfunc_08(3);
                }
                self->m_ptrs[i] = 0;
            }
        }
    }
    if (self->m_activeCount != 0) {
        p = self->m_ptrs;
        for (i = 0; i < 0x100; i++, p++) {
            if (*p != 0) {
                if (((Eff0Poly *)*p)->vfunc_20() == 0) {
                    X_func_0017756C(self, i);
                }
            }
        }
    }
}

extern "C" void func_00177830(EffMan *self, int arg1)
{
    int sp[2];
    if (self->m_activeCount != 0) {
        int i;
        Eff0 **ptrs = self->m_ptrs;
        Eff0 **p = ptrs;
        sp[0] = X_func_00177D20(self, arg1, 850.0f);
        X_func_00223398(sp[0], X_func_0021B550(X_func_0021B550(X_func_00223378(sp[0]), 8, 0), 0x47, 0x5000DUL));
        sp[1] = X_func_00177D20(self, arg1, 855.0f);
        X_func_00223398(sp[1], X_func_0021B550(X_func_0021B550(X_func_00223378(sp[1]), 8, 0), 0x47, 0x3000DUL));
        for (i = 0; i < 0x110; i++, p++) {
            if (*p != 0) {
                ((Eff0Poly *)*p)->vfunc_60();
            }
        }
        int n = X_func_001779B8(self);
        X_func_0016ADD8();
        for (i = 0; i < n; i++) {
            ((Eff0Poly *)self->m_ptrs[self->m_sortList[i]])->vfunc_30(sp);
        }
    }
}

extern "C" int func_001779B8(EffMan *self)
{
    int n = X_func_00177A8C(self);
    Eff0 *prev = self->m_ptrs[self->m_sortList[0]];
    for (int i = 1; i < n; i++) {
        Eff0 *cur = self->m_ptrs[self->m_sortList[i]];
        if (prev->m_zDepth < cur->m_zDepth) {
            X_func_00177C00(self, i);
            prev = self->m_ptrs[self->m_sortList[i]];
        } else {
            prev = cur;
        }
    }
    return n;
}

extern "C" int func_00177A8C(EffMan *self)
{
    int tmp[0x110];
    int i;
    for (i = 0; i < 0x110; i++) {
        if (self->m_ptrs[self->m_sortList[i]] == 0) {
            int j;
            for (j = i + 1; j < 0x110; j++) {
                if (self->m_ptrs[self->m_sortList[j]] != 0) {
                    break;
                }
            }
            if (j == 0x110) {
                break;
            }
            int count = j - i;
            if (count == 1) {
                tmp[0] = self->m_sortList[i];
                X_memmove(&self->m_sortList[i], &self->m_sortList[j], (0x110 - j) * 4);
                self->m_sortList[0x110 - 1] = tmp[0];
            } else {
                X_memcpy(tmp, &self->m_sortList[i], count * 4);
                X_memmove(&self->m_sortList[i], &self->m_sortList[j], (0x110 - j) * 4);
                X_memcpy((void *)((int)((0x110 - count) * 4 + (int)self) + 0x44C), tmp, count * 4);
            }
        }
    }
    return i;
}

extern "C" void func_00177C00(EffMan *self, int arg1)
{
    int lo = 0;
    int hi = arg1 - 1;
    int idx;
    Eff0 *target = self->m_ptrs[self->m_sortList[arg1]];
    while (hi - lo > 0) {
        idx = lo + (hi - lo + 1) / 2;
        Eff0 *obj = self->m_ptrs[self->m_sortList[idx]];
        if (target->m_zDepth < obj->m_zDepth) {
            lo = idx + 1;
        } else if (obj->m_zDepth < target->m_zDepth) {
            hi = idx - 1;
        } else {
            break;
        }
    }
    if (target->m_zDepth < self->m_ptrs[self->m_sortList[lo]]->m_zDepth) {
        lo++;
    }
    idx = self->m_sortList[arg1];
    X_memmove(&self->m_sortList[lo + 1], &self->m_sortList[lo], (arg1 - lo) * 4);
    self->m_sortList[lo] = idx;
}

extern "C" int func_00177D20(EffMan *self, int arg1)
{
    int temp_s2;
    EffSceneStub *scene;

    temp_s2 = X_func_0021F7E0(arg1);
    X_func_00223240(temp_s2, X_apply__C12DogLightPoolPvifi(((EffSceneStub *)self->m_scene)->m_lightPool, arg1, 0, 1.0f, 0));
    scene = (EffSceneStub *)self->m_scene;
    if (scene->m_fogFlag != 0) {
        X_func_00223250(temp_s2, X_func_0021A158(arg1, scene->m_fogParam));
    }
    int temp_a0 = (int)self->m_scene;
    int p = temp_a0 + 0x2AA10;
    X_func_00223260(temp_s2, X_func_00226C58(arg1, (void *)p, X_getViewMatrix__9DogCamera((void *)(temp_a0 + 0x2AB70))));
    return temp_s2;
}

extern "C" void func_00177E04(EffMan *self, int arg1)
{
    self->m_queue[self->m_queueCount++] = arg1;
}

extern "C" void func_00177E24(EffMan *self, int arg1)
{
    for (int i = 0; i < self->m_queueCount; i++) {
        if (self->m_queue[i] == arg1) {
            X_memmove(&self->m_queue[i], &self->m_queue[i + 1], (self->m_queueCount - i - 1) * 4);
            self->m_queueCount--;
            return;
        }
    }
}

extern "C" int func_00177E9C(EffMan *self)
{
    if (self->m_queueCount == 0) {
        return -1;
    }
    int first = self->m_queue[0];
    X_memmove(&self->m_queue[0], &self->m_queue[1], (self->m_queueCount - 1) * 4);
    self->m_queueCount--;
    return first;
}

extern "C" void func_00177EF8(EffMan *self, int arg1)
{
    for (int i = 0x100; i < 0x110; i++) {
        if (self->m_ptrs[i] == 0) {
            self->m_ptrs[i] = self->m_ptrs[arg1];
            self->m_ptrs[arg1] = 0;
            self->m_ptrs[i]->m_timer = 0;
            self->m_activeCount--;
            return;
        }
    }
}

extern "C" void func_00177F54(int arg0, char *arg1, const char *arg2)
{
    EffNameTable table = D_002F2CD0;
    const char *s = table.names[arg0];
    int len = X_strlen(s);
    X_memcpy(arg1, s, len);
    if (arg2 != 0) {
        int len2 = X_strlen(arg2);
        X_memcpy(arg1 + len, arg2, len2);
        len += len2;
    }
    arg1[len] = 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2B90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2B98);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BA8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BB8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BD8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BE8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2BF8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C00);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C08);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C10);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C18);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C20);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C28);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C30);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C38);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C40);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C48);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C50);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C58);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C60);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C68);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C70);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C80);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C88);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C90);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2C98);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CA0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CA8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CB0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CC0);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CC8);

INCLUDE_RODATA("asm/nonmatchings/unk/EffMan", D_002F2CD0);

extern "C" void func_001780C0(EffMan *self)
{
    self->m_effBinBuf = X_alloc__9BedMemoryii(&D_006E9800, 0x800, -1);
    X___11FileReadReq(&self->m_req);
    self->m_req.m_name = "data/eff/eff.bin";
    self->m_req.m_size = 0x800;
    self->m_req.m_buf = self->m_effBinBuf;
    self->m_req.m_unk14 = 0;
    self->m_req.m_offset = 0;
    self->m_req.m_unk20 = 0;
    X_func_001BE524__10FileReaderP11FileReadReqi(self->m_reader, &self->m_req, 0);
    self->m_req.m_buf = 0;
}

extern "C" int func_00178148(EffMan *self, int arg1, const char *arg2)
{
    EffManEntry *p = self->m_entries;
    for (int i = 0; i < 16; i++, p++) {
        if (p->m_active != 0 &&
            X_memcmp(p->m_name, arg2, X_strlen(p->m_name)) == 0) {
            return i;
        }
    }
    return -1;
}

extern "C" int func_001781D0(EffMan *self)
{
    for (int i = 0; i < 16; i++) {
        if (self->m_entries[i].m_active == 0) {
            return i;
        }
    }
    return -1;
}

// NON_MATCHING: 12/48 differ, 1 reloc differs (size 0xC0 == game 0xC0), 8 edits
#ifdef NON_MATCHING
extern "C" int func_0017820C(EffMan *self, int arg1, const char *arg2, void *arg3)
{
    EffLoadInfo info;
    int ret = -1;
    X_func_00177F54(arg1, info.name, arg2);
    if (info.name[0] != 0) {
        int res = X_func_00178148(self, arg1, info.name);
        if (res != -1) {
            return res;
        }
        int idx = X_func_001781D0(self);
        info.arg1 = arg1;
        info.arg3 = arg3;
        info.entry = &self->m_entries[idx];
        if (X_func_001782CC(self, &info) != 0) {
            ret = idx;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_0017820C);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/EffMan", func_001782CC);
