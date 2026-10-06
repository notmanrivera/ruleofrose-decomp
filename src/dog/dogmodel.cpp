#include "ror.h"
#include "dog/dogmodel.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"
#include "sdk/string.h"
#include "include_asm.h"

extern BedMemory D_006E9800;     // the global heap

// unk/00106658.
struct I3dOwner;
int i3dCallLocked(void *a, void *b, void *c, void *d, void *e);
int i3dSetUserAll(I3dOwner *theOwner, int theValue);
void vecNormalize(float *v);
float vecDot(float *a, float *b);
void vecDirToRot(float *theDir, float *theRot);

// The timer at DogModel::m_unk16C (names ours).
struct DogModelTimer {
    int m_unk00;
    float m_start;
    float m_end;
    float m_time;
    float m_step;
    int m_loop;
};

// The user values from m_user on, copied as one block (setUser).
struct DogModelUser {
    float m_value[12];
} __attribute__((aligned(8)));

// i3d's axes to the game's: (x, y, z) -> (-x, -z, -y), w = 1 (name ours).
static inline void fromI3d(float *theOut, const float *theIn)
{
    theOut[0] = -theIn[0];
    theOut[1] = -theIn[2];
    theOut[2] = -theIn[1];
    theOut[3] = 1.0f;
}

// (x, y, z, 1) (name ours).
static inline void setVec(float *theOut, float x, float y, float z)
{
    theOut[0] = x;
    theOut[1] = y;
    theOut[2] = z;
    theOut[3] = 1.0f;
}

// theOut = a - b, w = 1 (name ours).
static inline void subVec(float *theOut, const float *a, const float *b)
{
    theOut[0] = a[0] - b[0];
    theOut[1] = a[1] - b[1];
    theOut[2] = a[2] - b[2];
    theOut[3] = 1.0f;
}

// 0x00114034: collision callback: keeps the nearest hit in the query's
// DogModelHit, in the game's axes.
static int func_00114034(I3cQuery *theQuery, void *, unsigned short *theTri, float (*theVert)[4],
                         float *theNormal, float *theHit)
{
    DogModelHit *hit = (DogModelHit *)theQuery->m_user;
    hit->m_node = theQuery->m_group;
    if (hit->m_pos.m_w >= 0.0f && hit->m_pos.m_w < theHit[3]) {
        return 1;
    }
    fromI3d(&hit->m_pos.m_x, theHit);
    hit->m_pos.m_w = theHit[3];
    fromI3d(&hit->m_normal.m_x, theNormal);
    vecNormalize(&hit->m_normal.m_x);
    for (int i = 0; i < 3; i++) {
        fromI3d(&hit->m_tri[i].m_x, theVert[theTri[i]]);
    }
    const char *name = 0;
    if (theQuery->m_group >= 0) {
        name = func_0022C018(theQuery->m_root, theQuery->m_group);
    }
    if (name) {
        for (int i = 0; i < 0x1C; i++) {
            hit->m_name[i] = name[i];
            if (name[i] == 0) {
                break;
            }
        }
    }
    return 1;
}

// 0x001141C8: the same for walls: faces whose normal is within 60 degrees
// of horizontal.
static int func_001141C8(I3cQuery *theQuery, void *, unsigned short *theTri, float (*theVert)[4],
                         float *theNormal, float *theHit)
{
    DogModelHit *hit = (DogModelHit *)theQuery->m_user;
    float n[4];
    fromI3d(n, theNormal);
    vecNormalize(n);
    float up[4];
    setVec(up, 0.0f, 1.0f, 0.0f);
    float d = vecDot(n, up);
    if (d >= -0.5f && d <= 0.5f) {
        if (hit->m_pos.m_w >= 0.0f && hit->m_pos.m_w < theHit[3]) {
            return 1;
        }
        hit->m_node = theQuery->m_group;
        fromI3d(&hit->m_pos.m_x, theHit);
        hit->m_pos.m_w = theHit[3];
        fromI3d(&hit->m_normal.m_x, theNormal);
        vecNormalize(&hit->m_normal.m_x);
        for (int i = 0; i < 3; i++) {
            fromI3d(&hit->m_tri[i].m_x, theVert[theTri[i]]);
        }
        const char *name = 0;
        if (theQuery->m_group >= 0) {
            name = func_0022C018(theQuery->m_root, theQuery->m_group);
        }
        if (name) {
            for (int i = 0; i < 0x1C; i++) {
                hit->m_name[i] = name[i];
                if (name[i] == 0) {
                    break;
                }
            }
        }
    }
    return 1;
}






























































































































// 0x0011440C: the nearest hit of the segment theFrom-theTo; its distance,
// or -1.
float DogModel::collide(DogModelHit *theHit, const float *theFrom, const float *theTo)
{
    I3cQuery query;
    float seg[8];
    float mat[64][4][4];
    seg[0] = theFrom[0];
    seg[1] = theFrom[1];
    seg[2] = theFrom[2];
    seg[3] = 0.0f;
    seg[4] = theTo[0];
    seg[5] = theTo[1];
    seg[6] = theTo[2];
    seg[7] = 0.0f;
    ASSERT(m_i3c_root);
    query.m_root = m_i3c_root;
    int nNode = func_0022BFD8(m_i3c_root);
    ASSERT(nNode >= 0);

    ASSERT(m_mat_model);
    query.m_mat = m_mat_model;

    ASSERT(m_colli_tbl);
    query.m_colli_tbl = m_colli_tbl;
    query.m_func = func_00114034;
    query.m_unk20 = 1;
    theHit->m_node = -1;
    theHit->m_pos.m_w = -1.0f;
    query.m_unk14 = 0;
    query.m_user = theHit;







    ASSERT(nNode <= 64);
    for (int i = 0; i < nNode; i++) {
        func_00237340(mat[i]);
    }
    func_00232508(&query, seg, mat);
    if (theHit->m_node < -1) {
        return -1.0f;
    }
    return theHit->m_pos.m_w;
}














































// 0x001145C0: the same for a sphere.
float DogModel::collideSphere(DogModelHit *theHit, const float *thePos, float theRadius)
{
    I3cQuery query;
    float sphere[8];                // as big as a segment
    float mat[64][4][4];
    sphere[0] = thePos[0];
    sphere[1] = thePos[1];
    sphere[2] = thePos[2];
    sphere[3] = theRadius;
    ASSERT(m_i3c_root);
    query.m_root = m_i3c_root;
    int nNode = func_0022BFD8(m_i3c_root);
    ASSERT(nNode >= 0);

    ASSERT(m_mat_model);
    query.m_mat = m_mat_model;

    ASSERT(m_colli_tbl);
    query.m_colli_tbl = m_colli_tbl;
    query.m_func = func_00114034;
    query.m_unk20 = 1;
    theHit->m_node = -1;
    theHit->m_pos.m_w = -1.0f;
    query.m_unk14 = 0;
    query.m_user = theHit;




    ASSERT(nNode <= 64);
    for (int i = 0; i < nNode; i++) {
        func_00237340(mat[i]);
    }
    func_002324B8(&query, sphere, mat);
    if (theHit->m_node < -1) {
        return -1.0f;
    }
    return theHit->m_pos.m_w;
}







































// 0x00114758: the height where theFrom-theTo first meets the model, group
// by group; theFrom's when it does not.
float DogModel::getGroundY(const float *theFrom, const float *theTo)
{
    I3cQuery query;
    float seg[8];
    DogModelHit hit;
    float mat[64][4][4];
    seg[0] = theFrom[0];
    seg[1] = theFrom[1];
    seg[2] = theFrom[2];
    seg[3] = 0.0f;
    seg[4] = theTo[0];
    seg[5] = theTo[1];
    seg[6] = theTo[2];
    seg[7] = 0.0f;
    ASSERT(m_i3c_root);
    query.m_root = m_i3c_root;
    int nNode = func_0022BFD8(m_i3c_root);
    ASSERT(nNode >= 0);

    ASSERT(m_mat_model);
    query.m_mat = m_mat_model;

    ASSERT(m_colli_tbl);
    query.m_colli_tbl = m_colli_tbl;
    query.m_func = func_00114034;
    query.m_user = &hit;
    query.m_unk14 = 0;
    int ng = get_nGroup();


    ASSERT(ng >= 0);
    hit.m_node = -1;
    hit.m_pos.m_w = -1.0f;



    ASSERT(nNode <= 64);
    for (int i = 0; i < nNode; i++) {
        func_00237340(mat[i]);
    }
    for (int g = -1; g < ng; g++) {
        query.m_group = g;
        func_00232508(&query, seg, mat);
    }
    if (hit.m_node >= -1) {
        return hit.m_pos.m_y;
    }
    return theFrom[1];
}




































// 0x001149D4: walls along theFrom-theTo with theRadius; the nearest
// hit's distance, or -1.
float DogModel::collideWall(const float *theFrom, const float *theTo, DogModelHit *theHit, float theRadius)
{
    if (!m_i3c_root) {
        return -1.0f;
    }
    I3cQuery query;
    float seg[8];
    DogModelHit hit;
    float mat[64][4][4];
    seg[0] = theFrom[0];
    seg[1] = theFrom[1];
    seg[2] = theFrom[2];
    seg[3] = theRadius;
    seg[4] = theTo[0];
    seg[5] = theTo[1];
    seg[6] = theTo[2];
    seg[7] = 0.0f;
    ASSERT(m_i3c_root);
    query.m_root = m_i3c_root;
    int nNode = func_0022BFD8(m_i3c_root);
    ASSERT(nNode >= 0);

    ASSERT(m_mat_model);
    query.m_mat = m_mat_model;

    ASSERT(m_colli_tbl);
    if (!theHit) {
        theHit = &hit;
    }
    query.m_colli_tbl = m_colli_tbl;
    query.m_group = -1;
    query.m_func = func_001141C8;
    query.m_unk20 = 1;
    query.m_unk14 = 0;
    query.m_user = theHit;
    int ng = get_nGroup();

    ASSERT(ng >= 0);
    theHit->m_node = -100;
    theHit->m_pos.m_w = -1.0f;



    ASSERT(nNode <= 64);
    for (int i = 0; i < nNode; i++) {
        func_00237340(mat[i]);
    }
    func_002325A8(&query, seg, mat);
    if (theHit->m_node < -1) {
        return -1.0f;
    }
    return theHit->m_pos.m_w;
}

// 0x00114C54
void DogModel::init()
{
    getSubMode()->m_step = -1;
    getSubMode()->m_mode = -1;
    m_clip_radius = -1.0f;
    m_flag = 0;
    m_load_flag = LOAD_NONE;
    m_ref_count = 0;
    m_tex_info = 0;
    m_pack_file = 0;
    m_original = 0;
    m_i3r_root = 0;
    m_unk120 = 0;
    m_i3c_root = 0;
    m_colli_tbl = 0;
    m_hide = 0;
    m_attach_node = -1;
    m_attention = -1;
    m_mat_model = 0;
    m_mat_local = 0;
    m_mat_flag = 0;
    m_light_id = 0;
    m_shadow_light = -1;
    m_shadow_count = 0;
    m_unk16C = 0;
    m_shadow_light_old = -1;
    m_user_scale[0] = m_user_scale[1] = m_user_scale[2] = m_user_scale[3] = 1.0f;
    m_user190 = m_user[0] = m_user[1] = m_user[2] = m_user[3] = 0.0f;
    m_user194 = 1;
    m_user195 = 1;







}



























































// 0x00114D04: takes theRoot (nothing loaded yet).
void DogModel::vfunc05(tag_I3rRoot_s *theRoot)
{
    getSubMode()->m_step = -1;
    getSubMode()->m_mode = -1;
    tag_I3rRoot_s *p = theRoot;
    ASSERT(I3D_OK == I3rRoot__CheckIdString( p ));
    m_i3r_root = p;
    m_hide = 0;
    m_i3c_root = 0;
    m_mat_model = 0;
    m_mat_local = 0;
    m_mat_flag = 0;
    if (p) {
        unpack();
    }
}

// 0x00114D8C: the model's position: on its parent's attach node, its
// parent's, or its own.
void DogModel::func_00114D8C(u_long128 *thePos)
{
    DogEntityEx *parent = m_parent;
    if (parent) {
        if (m_attach_node >= 0) {
            float (*mat)[4][4] = ((DogModel *)parent)->getModelMatrix();
            float m[4][4];
            parent->transform();
            func_002377D0(m, parent->m_unk00, mat[m_attach_node]);
            *thePos = *(u_long128 *)m[3];
        } else {
            parent->transform();
            *thePos = *(u_long128 *)parent->m_unk00[3];
        }
    } else {
        *thePos = *(u_long128 *)&m_unk40;
    }
}


























// 0x00114E38: a billboard's matrix, facing thePos or along theDir.
// NON_MATCHING: the game computes &p and &r before ASSERT(thePos), in $s1
// and $s5, and three of the four paths share the rotY + translate tail;
// here they are computed after the assert. Tried: p and r declared before
// the assert, do/for wrappers, reads of r through a pointer, an empty
// ~DogVector, other forms of y.
#ifdef NON_MATCHING
int DogModel::vfunc11(DogVector *theDir, DogVector *thePos)
{
    int mode = m_flag >> 1;
    if (mode & 1) {
        int tilt = mode & 2;
        if (mode & 4) {
            ASSERT(thePos);
            DogVector d(*thePos);
            DogVector p;
            DogVector r;
            p.m_x = m_unk40.m_x;
            p.m_y = m_unk40.m_y;
            p.m_z = m_unk40.m_z;
            subVec(&d.m_x, &d.m_x, &p.m_x);



            vecDirToRot(&d.m_x, &r.m_x);
            if (tilt) {
                func_00237340(m_unk00);
                func_00237818(m_unk00, m_unk00, r.m_x);
                func_00237830(m_unk00, m_unk00, r.m_y);
            } else {
                func_00237340(m_unk00);
                func_00237830(m_unk00, m_unk00, r.m_y);
            }
            func_00237640(m_unk00, m_unk00, &m_unk40.m_x);
            func_00237640(m_unk00, m_unk00, &m_unk70.m_x);
            return 1;
        }







        ASSERT(theDir);
        float y = theDir->m_y + DOG_PI;
        if (y >= DOG_PI) {
            y -= DOG_PI2;
        }
        if (y < -DOG_PI) {
            y += DOG_PI2;
        }
        if (tilt) {
            func_00237340(m_unk00);
            func_00237818(m_unk00, m_unk00, theDir->m_x);
            func_00237830(m_unk00, m_unk00, y);
        } else {
            func_00237340(m_unk00);
            func_00237830(m_unk00, m_unk00, y);
        }
        func_00237640(m_unk00, m_unk00, &m_unk40.m_x);
        func_00237640(m_unk00, m_unk00, &m_unk70.m_x);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/dog/dogmodel", vfunc11__8DogModelP9DogVectorT1);
#endif

// 0x001150C0
void DogModel::transform()
{
    int changed = makeMatrix(m_local);
    DogEntityEx *p = m_parent;
    if (p) {
        if (m_attach_node >= 0) {
            float m[4][4];
            memset(m, 0, sizeof(m));
            m[0][0] = -1.0f;
            m[1][2] = -1.0f;
            m[2][1] = -1.0f;
            m[3][3] = 1.0f;
            if (changed) {
                func_002377D0(m_local, m_local, m);
            }
            func_002377D0(m_unk00, ((DogModel *)m_parent)->m_mat_model[m_attach_node], m_local);
            p = m_parent;
            p->transform();
            func_002377D0(m_unk00, p->m_unk00, m_unk00);
            return;
        }
        p->transform();
        func_002377D0(m_unk00, p->m_unk00, m_local);
        return;
    }
    func_002372F0(m_unk00, m_local);
}



























































// 0x001151F4: draws the model.
void DogModel::vfunc12(void *theRenderStage, void *a, void *b)
{
    if (!vfunc11((DogVector *)a, (DogVector *)b)) {
        transform();
    }
    if (!m_hide) {
        ASSERT(I3D_OK == I3rRoot__CheckIdString( m_i3r_root ));
        i3dCallLocked(theRenderStage, m_i3r_root, m_mat_model, this, 0);
    }
}
















// 0x001152A8: draws it with a unit matrix.
void DogModel::vfunc13(void *theRenderStage)
{
    float m[4][4];
    func_00237340(m);
    ASSERT(I3D_OK == I3rRoot__CheckIdString( m_i3r_root ));
    i3dCallLocked(theRenderStage, m_i3r_root, 0, m, 0);
}

// 0x0011531C
void DogModel::setBillboard(int theMode)
{
    m_flag = (m_flag & ~0xE) | ((theMode & 7) << 1);
}


















































































































// 0x0011533C: the node matrices and flags, from the model's own.
void DogModel::func_0011533C()
{
    if (isAlive() && !m_mat_local) {
        int n = func_0022B370(m_i3r_root);
        m_mat_local = (float (*)[4][4])D_006E9800.alloc(n * (sizeof(float[4][4]) * 2 + sizeof(int)), -1);
        ASSERT(__null != m_mat_local);
        m_mat_model = m_mat_local + n;
        m_mat_flag = (int *)(m_mat_local + n * 2);
        memset(m_mat_flag, 0, n * sizeof(int));
        copyLocalBasicTransform((tag_I3dMatrixF4x4_s *)m_mat_local);
        convertLocalToModel((tag_I3dMatrixF4x4_s *)m_mat_model, (tag_I3dMatrixF4x4_s *)m_mat_local);
    }
}

// 0x001154CC
void DogModel::func_001154CC()
{
    if (m_mat_local) {
        D_006E9800.free(m_mat_local);
        m_mat_local = 0;
        m_mat_model = 0;
    }
}

















// 0x0011550C: nodes named "ba_..." face the camera (1), "by_..." turn
// around Y only (2).
void DogModel::setMatFlag()
{
    if (isAlive()) {
        ASSERT(m_mat_flag);
        int n = get_nNode();
        for (int i = 0; i < n; i++) {
            const char *name = getNodeName(i);
            if (name[0] == 'b' && name[2] == '_') {
                if (name[1] == 'a') {
                    m_mat_flag[i] = 1;
                } else if (name[1] == 'y') {
                    m_mat_flag[i] = 2;
                }
            }
        }
    }
}

















// 0x00115694: the model node of every collision node.
short *DogModel::makeColliTbl()
{
    if (!m_i3c_root) {
        m_colli_tbl = 0;
        return 0;
    }
    ASSERT(m_colli_tbl == __null);
    int n = func_0022BFD8(m_i3c_root);
    m_colli_tbl = (short *)D_006E9800.alloc(n * sizeof(short), -1);





    ASSERT(m_colli_tbl);
    for (int i = 0; i < n; i++) {
        int node = func_0022B3D8(m_i3r_root, func_0022BFE0(m_i3c_root, i));
        // The entry's address is summed as an integer, index first.
        short *t = (short *)(i * sizeof(short) + (unsigned int)m_colli_tbl);
        if (node >= 0) {
            *t = node;
        } else {
            *t = -1;
        }
    }
    return m_colli_tbl;
}





















































































































































































// 0x00115790: a model from a root, its textures and collision already in
// memory.
int DogModel::vfunc15(void *theData, void *theA, void *theB)
{
    vfunc05((tag_I3rRoot_s *)theA);
    if (assignTex((DogTexInfo *)theData) != 0) {
        ASSERT(0);
    }
    m_i3c_root = theB;
    if (theB) {
        if (func_0022BBA0(theB) != 0) {









            ASSERT(0);
            return -1;
        }
        makeColliTbl();
        func_0022C1D8(m_i3c_root, 1);
    }
    if (!m_mat_model) {
        func_0011533C();
    }
    func_0011533C();
    m_load_flag = LOAD_DATA;
    m_ref_count = 1;
    m_tex_info = (DogTexInfo *)theData;
    m_original = 0;
    m_pack_file = 0;
    reset();
    return 0;
}
















// 0x001158EC: a model from a .RPK: textures, root, and an alternative root
// if there is a third file.
int DogModel::vfunc14(void *theTex, BedPfh *thePfh, int theA, int theB)
{
    ASSERT(m_pack_file == __null);
    ASSERT(m_load_flag == LOAD_NONE);
    ASSERT(m_ref_count == 0);
    m_pack_file = thePfh->m_top;
    if (!m_pack_file) {
        return -1;
    }
    ASSERT(m_pack_file);            // folded: its string stays
    BedPfh tex(thePfh->getFileTop(0));
    ((DogTexInfo *)theTex)->func_001170B8(&tex, 0, 0, theA);
    vfunc05((tag_I3rRoot_s *)thePfh->getFileTop(1));
    if (theA && theB) {
        m_user_scale[0] = m_user_scale[1] = m_user_scale[2] = 0.0f;
        m_user_scale[3] = 1.0f;
        m_user[0] = m_user[1] = m_user[2] = 1.0f;
        m_user[3] = 0.0f;
        i3dSetUserAll((I3dOwner *)m_i3r_root, (int)m_user);
    }
    if (assignTex((DogTexInfo *)theTex) != 0) {
        ((DogTexInfo *)theTex)->func_0011764C();



























        ASSERT(0);
    }
    if (thePfh->getNumFile() >= 3 && thePfh->getFileSize(2) > 0) {
        m_unk120 = thePfh->getFileTop(2);
        if (m_unk120) {
            func_0022B330((tag_I3rRoot_s *)m_unk120);
        }
    }
    func_0011533C();
    m_load_flag = LOAD_DATA;
    m_ref_count = 1;
    m_tex_info = (DogTexInfo *)theTex;
    m_original = 0;
    reset();
    return 0;
}



































































// 0x00115C60: a copy of theOriginal (which keeps the data).
int DogModel::vfunc16(DogModel *theOriginal)
{
    ASSERT(theOriginal);
    theOriginal->incRefCount();
    m_load_flag = LOAD_COPY;
    m_ref_count = 1;
    m_original = 0;
    m_tex_info = 0;
    reset();
    return 0;
}























// 0x00115CEC: drops a reference (all of them if theForce) and frees what
// the model loaded when none is left.
void DogModel::vfunc06(int theForce)
{
    if (theForce) {
        m_ref_count = 0;
    } else if (decRefCount() > 0) {
        return;
    }
    ASSERT(m_ref_count <= 0);




    ASSERT(m_load_flag != LOAD_NONE);
    switch (m_load_flag) {
    case LOAD_NONE:
        break;
    case LOAD_PACK: {
        if (m_colli_tbl) {
            D_006E9800.free(m_colli_tbl);
            m_colli_tbl = 0;
        }












        ASSERT(m_pack_file);
        // The file offsets follow the header; the textures are file 0.
        int *offset = (int *)((BedPfhHeader *)m_pack_file + 1);
        ASSERT(m_tex_info);
        m_tex_info->func_001169D0((char *)m_pack_file + offset[0]);
        D_006E9800.free(m_pack_file);
        m_pack_file = 0;
        break;
    }
    case LOAD_FILE:
        if (m_colli_tbl) {
            D_006E9800.free(m_colli_tbl);
            m_colli_tbl = 0;
        }
        if (m_i3c_root) {
            D_006E9800.free(m_i3c_root);
            m_i3c_root = 0;
        }











        ASSERT(m_tex_info);
        m_tex_info->func_001167F4(this);



        ASSERT(m_i3r_root);
        D_006E9800.free(m_i3r_root);
        break;
    case LOAD_COPY:



        ASSERT(m_original);
        m_original->vfunc06(0);
        break;
    case LOAD_DATA:
        if (m_colli_tbl) {
            D_006E9800.free(m_colli_tbl);
            m_colli_tbl = 0;
        }
        if (m_pack_file) {











            ASSERT(m_tex_info);
            BedPfh pfh(m_pack_file);
            m_tex_info->func_001169D0(pfh.getFileTop(0));
            m_pack_file = 0;
        }
        break;
    default:





        ASSERT(0);
        break;
    }
    if (m_mat_local) {
        D_006E9800.free(m_mat_local);
    }
    if (m_unk16C) {
        D_006E9800.free(m_unk16C);
    }
    init();
}

// 0x00116038: the clip sphere's radius, read once.
float DogModel::getClipRadius()
{
    if (m_clip_radius < 0.0f) {
        float c[4];
        copyClipSphere(c, &m_clip_radius);
    }
    return m_clip_radius;
}

// 0x001160A8
void DogModel::func_001160A8()
{
    if (!m_unk16C) {
        m_unk16C = D_006E9800.alloc(sizeof(DogModelTimer), -1);
        ((DogModelTimer *)m_unk16C)->m_unk00 = 0;
        ((DogModelTimer *)m_unk16C)->m_loop = 1;
        ((DogModelTimer *)m_unk16C)->m_end = 5.0f;
        ((DogModelTimer *)m_unk16C)->m_start = 0.0f;
        ((DogModelTimer *)m_unk16C)->m_time = 0.0f;
        ((DogModelTimer *)m_unk16C)->m_step = 0.01f;
    }
}

// 0x00116130
void DogModel::func_00116130()
{
    if (m_unk16C) {
        ((DogModelTimer *)m_unk16C)->m_time += ((DogModelTimer *)m_unk16C)->m_step;
        DogModelTimer *t = (DogModelTimer *)m_unk16C;
        if (t->m_time > t->m_end) {
            if (!t->m_loop) {
                t->m_time = t->m_end;
            } else {
                t->m_time = t->m_time - (t->m_end - t->m_start);
            }
        }
    }
}

// 0x0011618C
void DogModel::setUser(const float *theUser)
{
    *(DogModelUser *)m_user = *(const DogModelUser *)theUser;
    i3dSetUserAll((I3dOwner *)m_i3r_root, (int)m_user);
}
