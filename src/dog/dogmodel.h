// dog/dogmodel.h: DogModel, an i3d model with its matrices (the base of
// DogActor). Reduced to what decompiled code uses. The class name, the
// virtual methods' order and the inline methods' names come from the
// vtable and linkonce copies; vfuncNN are placeholders for unnamed
// virtual methods, and fields are ours unless an assert names them.
#ifndef DOG_DOGMODEL_H
#define DOG_DOGMODEL_H

#include "dog/dogentity.h"
#include "mw/i3d.h"

class BedPfh;

// The 16-byte state DogModel::getSubMode returns (BedSubMode stacks them).
union DogSubMode {
    u_long128 m_all;
    struct {
        int m_mode;
        int m_step;
        int m_unk08;
        int m_unk0C;
    };
};

class DogModel : public DogEntityEx {
public:
    DogSubMode m_submode;           // +0xF0
    int m_unk100;                   // +0x100
    int m_unk104;                   // +0x104: references (DogActor::release)
    unsigned char m_unk108[0x8];    // +0x108
    int m_unk110;                   // +0x110: 3 for a copy (DogActor)
    unsigned char m_unk114[0x4];    // +0x114
    DogModel *m_original;           // +0x118: the model this one copies
    void *m_i3r_root;               // +0x11C
    void *m_unk120;                 // +0x120: drawn instead of m_i3r_root
    unsigned char m_unk124[0x8];    // +0x124
    float (*m_mat_local)[4][4];     // +0x12C
    float (*m_mat_model)[4][4];     // +0x130
    unsigned char m_unk134[0x8];    // +0x134
    int m_unk13C;                   // +0x13C: light (getLightID)
    int m_unk140;                   // +0x140: release pending
    unsigned char m_unk144[0x1C];   // +0x144
    int m_unk160;                   // +0x160
    int m_unk164;                   // +0x164
    int m_unk168;                   // +0x168
    void *m_unk16C;                 // +0x16C
    unsigned char m_unk170[0x30];   // +0x170

    DogModel()
    {
        m_submode.m_all = 0;
        init();
    }
    void init();                    // 0x00114C54
    DogSubMode *getSubMode() { return &m_submode; }
    int decRefCount() { return m_unk104 > 0 ? --m_unk104 : 0; }
    void incRefCount() { m_unk104++; }
    void func_0011533C();
    void func_00116130();
    void func_001154CC();
    virtual void transform();
    virtual ~DogModel() { vfunc06(1); }
    virtual void vfunc05();
    virtual void vfunc06(int);
    virtual float (*getNodeMatrixPtr(int theNode))[4][4] { return 0; }
    virtual void setHide(bool theHide);
    virtual bool isHide() const;
    virtual void setAttachNode(int theNode);
    virtual int vfunc11(void *a, void *b);
    virtual void vfunc12(void *theRenderStage, void *a, void *b);
    virtual void vfunc13();
    virtual int vfunc14(void *theTex, BedPfh *thePfh, int theA, int theB);
    virtual int vfunc15(void *theData, void *theA, void *theB);
    virtual void vfunc16();






































































































































































































































    int getNodeIndexByName(const char *p) { ASSERT(m_i3r_root); ASSERT(p); return func_0022B3D8(m_i3r_root, p); }

    void convertLocalToModel(float (*a)[4][4], const float (*c)[4][4]) { ASSERT(m_i3r_root); ASSERT(a); ASSERT(c); func_0021A760(m_i3r_root, a, c); }
    void convertLocalToModel(tag_I3dMatrixF4x4_s *a, const tag_I3dMatrixF4x4_s *c) { ASSERT(m_i3r_root); ASSERT(a); ASSERT(c); func_0021A760(m_i3r_root, a, c); }
};

#endif
