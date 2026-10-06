// dog/dogmodel.h: DogModel, an i3d model with its matrices and collision
// (the base of DogActor). The class name, the virtual methods' order and
// the inline methods' names come from the vtable and the linkonce copies;
// vfuncNN are placeholders for unnamed virtual methods, and fields are ours
// unless an assert or an inline method's name gives them. The inline
// methods with asserts must stay on their lines (248, 263-268, 296-317).
#ifndef DOG_DOGMODEL_H
#define DOG_DOGMODEL_H

#include "dog/dogentity.h"
#include "dog/dogtexinfo.h"
#include "mw/i3d.h"

class BedPfh;
struct tag_I3rRoot_s;

// How a DogModel got its data (m_load_flag; names ours but LOAD_NONE).
enum {
    LOAD_NONE,
    LOAD_PACK,                      // an .RPK it owns (m_pack_file, freed)
    LOAD_FILE,                      // a root and collision it owns
    LOAD_COPY,                      // shares m_original's (vfunc16)
    LOAD_DATA                       // given by the caller (vfunc14, vfunc15)
};

// What a collision query fills in (names ours).
struct DogModelHit {                // 0x70
    DogVector m_pos;                // +0x00: w = the hit's distance
    DogVector m_normal;             // +0x10
    DogVector m_tri[3];             // +0x20: the triangle hit
    int m_node;                     // +0x50
    char m_name[0x1C];              // +0x54: the node's name
};

class DogModel : public DogEntityEx {
public:
    DogSubMode m_submode;           // +0xF0
    int m_flag;                     // +0x100: bits 1-3: billboard (setBillboard)
    int m_ref_count;                // +0x104
    float m_clip_radius;            // +0x108: < 0 until getClipRadius
    DogTexInfo *m_tex_info;         // +0x10C
    int m_load_flag;                // +0x110
    void *m_pack_file;              // +0x114
    DogModel *m_original;           // +0x118: the model this one copies
    tag_I3rRoot_s *m_i3r_root;      // +0x11C
    void *m_unk120;                 // +0x120: drawn instead of m_i3r_root
    void *m_i3c_root;               // +0x124: collision
    short *m_colli_tbl;             // +0x128: collision node -> model node
    float (*m_mat_local)[4][4];     // +0x12C
    float (*m_mat_model)[4][4];     // +0x130
    int *m_mat_flag;                // +0x134: per node (getNodeFlag)
    int m_attach_node;              // +0x138: of m_parent; -1: none
    int m_attention;                // +0x13C
    int m_hide;                     // +0x140
    int m_light_id;                 // +0x144
    unsigned char m_unk148[0x18];   // +0x148
    int m_shadow_light;             // +0x160
    int m_shadow_light_old;         // +0x164
    int m_shadow_count;             // +0x168
    void *m_unk16C;                 // +0x16C: a timer (func_001160A8)
    float m_user[4];                // +0x170: i3dSetUserAll
    float m_user_scale[4];          // +0x180
    float m_user190;                // +0x190
    unsigned char m_user194;        // +0x194
    unsigned char m_user195;        // +0x195
    unsigned char m_unk196[0xA];    // +0x196

    DogModel()
    {
        m_submode.m_all = 0;
        init();
    }
    void init();
    DogSubMode *getSubMode() { return &m_submode; }
    int decRefCount() { return m_ref_count > 0 ? --m_ref_count : 0; }
    void incRefCount() { m_ref_count++; }
    int getAttention() const { return m_attention; }
    void setAttention(int theA) { m_attention = theA; }
    int getLightID() const { return m_light_id; }
    void setLightID(int theID) { m_light_id = theID; }
    int *getNodeFlag() { return m_mat_flag; }
    short *getColliAssignTbl() { return m_colli_tbl; }
    void *getI3cRootPtr() { return m_i3c_root; }
    tag_I3rRoot_s *getI3rRootPtr() { return m_i3r_root; }
    float (*getModelMatrix())[4][4] { return m_mat_model; }
    float collide(DogModelHit *theHit, const float *theFrom, const float *theTo);
    float collideSphere(DogModelHit *theHit, const float *thePos, float theRadius);
    float getGroundY(const float *theFrom, const float *theTo);
    float collideWall(const float *theFrom, const float *theTo, DogModelHit *theHit, float theRadius);
    void func_00114D8C(u_long128 *thePos);
    void setBillboard(int theMode);
    void func_0011533C();
    void func_001154CC();
    void setMatFlag();
    short *makeColliTbl();
    float getClipRadius();
    void func_001160A8();
    void func_00116130();
    void setUser(const float *theUser);
    virtual void transform();
    virtual ~DogModel() { vfunc06(1); }
    virtual void vfunc05(tag_I3rRoot_s *theRoot);
    virtual void vfunc06(int theForce);
    virtual float (*getNodeMatrixPtr(int theNode))[4][4] { return 0; }
    virtual void setHide(bool theHide) { m_hide = theHide; }
    virtual bool isHide() const { return m_hide; }
    virtual void setAttachNode(int theNode) { m_attach_node = theNode; }
    virtual int vfunc11(DogVector *theDir, DogVector *thePos);
    virtual void vfunc12(void *theRenderStage, void *a, void *b);
    virtual void vfunc13(void *theRenderStage);
    virtual int vfunc14(void *theTex, BedPfh *thePfh, int theA, int theB);
    virtual int vfunc15(void *theData, void *theA, void *theB);
    virtual int vfunc16(DogModel *theOriginal);






































































































































    bool isAlive() const { if (m_i3r_root) { ASSERT(I3D_OK == I3rRoot__CheckIdString( m_i3r_root )); } return m_i3r_root != __null; }














    int assignTex(DogTexInfo *t)
    {
        ASSERT(m_i3r_root);
        ASSERT(t);
        return func_0021A5B0(m_i3r_root, t->m_tex_info, t->m_num_tex);
    }



























    int unpack() { ASSERT(m_i3r_root); return func_0022B330(m_i3r_root); }
    int get_nNode() { ASSERT(m_i3r_root); return func_0022B370(m_i3r_root); }
    int get_nTex() { ASSERT(m_i3r_root); return func_0022B428(m_i3r_root); }
    const char *getTexName(int i) { ASSERT(m_i3r_root); ASSERT(i>=0); return func_0022B438(m_i3r_root, i); }
    int assignTex(const tag_I3dTexInfo_s *p, int n) { ASSERT(m_i3r_root); ASSERT(p); ASSERT(n>0); return func_0021A5B0(m_i3r_root, p, n); }


    void copyLocalBasicTransform(tag_I3dMatrixF4x4_s *m) { ASSERT(m_i3r_root); func_0021A700(m_i3r_root, m); }

    int getNodeIndexByName(const char *p) { ASSERT(m_i3r_root); ASSERT(p); return func_0022B3D8(m_i3r_root, p); }

    void convertLocalToModel(float (*a)[4][4], const float (*c)[4][4]) { ASSERT(m_i3r_root); ASSERT(a); ASSERT(c); func_0021A760(m_i3r_root, a, c); }
    void convertLocalToModel(tag_I3dMatrixF4x4_s *a, const tag_I3dMatrixF4x4_s *c) { ASSERT(m_i3r_root); ASSERT(a); ASSERT(c); func_0021A760(m_i3r_root, a, c); }

    const char *getNodeName(int i) { ASSERT(m_i3r_root); ASSERT(i>=0); return func_0022B388(m_i3r_root, i); }
    void copyClipSphere(float *c, float *r) { ASSERT(c); ASSERT(r); func_0021A828(m_i3r_root, c, r); }





    int get_nGroup() const { ASSERT(m_i3c_root); return func_0022C010(m_i3c_root); }

};

#endif
