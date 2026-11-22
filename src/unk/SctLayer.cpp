#include "include_asm.h"
#include "unk/WrdSrv.h"
extern "C" void X_func_0017E4D0_17C4F4(SctLayer *, int, int) asm("func_0017E4D0");
extern "C" void X_func_0017C2C0_17C14C(void *) throw() asm("func_0017C2C0");
struct SctLayerDtorStub_17C14C {
    char pad[20];
    virtual void dtor(int) throw();
}; // SctLayerDtorStub_17C14C
extern "C" void X_func_0017C754_17C2C0(SctLayer *) throw() asm("func_0017C754");
extern "C" void X_free__9BedMemoryPv_17C2C0(void *, void *) asm("free__9BedMemoryPv");
extern "C" int X_func_0017C7B0_17C3F0(void *) asm("func_0017C7B0");
extern "C" void X_func_0017C58C_17C0F0(SctLayer *) throw() asm("func_0017C58C");
extern "C" void X_func_0017E464_17C45C(SctLayer *, int, int) asm("func_0017E464");

struct SctMapHeader {
    int m_unk00;                // +0x00
    int m_layerOff[4];          // +0x04
};

struct SctMap {
    int m_flags;                // +0x00 (bit 1: owns m_data allocation)
    SctMapHeader *m_data;       // +0x04
    SctLayer m_layers[4];       // +0x08 (stride 0x18)
};

extern int vtbl_SctLayer asm("_vt$8SctLayer");
extern int D_006E9800;

extern "C" void *X_alloc__9BedMemoryii(void *, int, int) asm("alloc__9BedMemoryii");
extern "C" void *X_memcpy(void *, const void *, int) asm("memcpy");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_func_0017C3F0(SctMapHeader *) asm("func_0017C3F0");
extern "C" void X_func_0017C60C(SctLayer *, void *, int) asm("func_0017C60C");
extern "C" void X_func_0017C754(SctLayer *) asm("func_0017C754");

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017B7CC);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017B918);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017BA54);

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017BB50);

extern "C" void func_0017C0F0(SctMap *self)
{
    SctLayer *p = self->m_layers;
    int n = 3;
    do {
        X_func_0017C58C_17C0F0(p++);
        n--;
    } while (n != -1);
    self->m_flags = 0;
    self->m_data = 0;
}

extern "C" void func_0017C14C(SctMap *self, int arg1)
{
    X_func_0017C2C0_17C14C(self);
    if (self->m_layers != 0) {
        SctLayerDtorStub_17C14C *p = (SctLayerDtorStub_17C14C *)self->m_layers + 4;
        SctLayerDtorStub_17C14C *begin = (SctLayerDtorStub_17C14C *)self->m_layers;
        while (begin != p) {
            p--;
            p->dtor(2);
        }
    }
    if (arg1 & 1) {
        return X___builtin_delete(self);
    }
}

extern "C" int func_0017C1F4(SctMap *self, SctMapHeader *hdr, int copy)
{
    if (copy != 0) {
        int size = X_func_0017C3F0(hdr);
        SctMapHeader *buf = (SctMapHeader *)X_alloc__9BedMemoryii(&D_006E9800, size, -1);
        X_memcpy(buf, hdr, size);
        self->m_data = buf;
        self->m_flags |= 2;
    } else {
        self->m_data = hdr;
    }
    for (int i = 0; i < 4; i++) {
        SctMapHeader *data = self->m_data;
        int off = data->m_layerOff[i];
        if (off != 0) {
            X_func_0017C60C(&self->m_layers[i], (char *)data + off, 0);
        }
    }
    return 1;
}

extern "C" void func_0017C2C0(SctMap *self)
{
    for (int i = 0; i < 4; i++) {
        X_func_0017C754_17C2C0(&self->m_layers[i]);
    }
    if ((self->m_flags & 2) && self->m_data != 0) {
        X_free__9BedMemoryPv_17C2C0(&D_006E9800, self->m_data);
    }
    self->m_data = 0;
    self->m_flags = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/SctLayer", func_0017C340);

extern "C" int func_0017C3F0(SctMapHeader *hdr)
{
    int size = 0x20;
    for (int i = 0; i < 4; i++) {
        int off = hdr->m_layerOff[i];
        if (off != 0) {
            size += X_func_0017C7B0_17C3F0((char *)hdr + off);
        }
    }
    return size;
}

extern "C" void func_0017C45C(SctMap *self, int arg1, int arg2, int arg3)
{
    if (arg3 < 0) {
        for (int i = 0; i < 4; i++) {
            X_func_0017E464_17C45C(&self->m_layers[i], arg1, arg2);
        }
    } else {
        X_func_0017E464_17C45C(&self->m_layers[arg3], arg1, arg2);
    }
}

extern "C" void func_0017C4F4(SctMap *self, int arg1, int arg2, int arg3)
{
    if (arg3 < 0) {
        for (int i = 0; i < 4; i++) {
            X_func_0017E4D0_17C4F4(&self->m_layers[i], arg1, arg2);
        }
    } else {
        X_func_0017E4D0_17C4F4(&self->m_layers[arg3], arg1, arg2);
    }
}

extern "C" void func_0017C58C(SctLayer *self)
{
    self->m_vtbl = &vtbl_SctLayer;
    self->m_flags = 0;
    self->m_layer = 0;
    self->m_groups = 0;
    self->m_cells = 0;
    self->m_areas = 0;
}

extern "C" void SctLayer_dtor(SctLayer *self, int flags) asm("SctLayer__vfunc_01");
extern "C" void SctLayer_dtor(SctLayer *self, int flags)
{
    self->m_vtbl = &vtbl_SctLayer;
    X_func_0017C754(self);
    if (flags & 1) {
        return X___builtin_delete(self);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/SctLayer", D_002F3060);

INCLUDE_RODATA("asm/nonmatchings/unk/SctLayer", D_002F3070);
