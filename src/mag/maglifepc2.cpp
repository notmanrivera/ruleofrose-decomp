#include "ror.h"
#include "include_asm.h"
#include "game/gamman.h"
#include "dog/dogentity.h"
#include "dog/dogactor.h"
extern "C" int func_00163BE4(void *theEmy);
struct EmyDistEntry {
    const char *m_name;
    int m_id;
    float m_range[8];
};
struct EmyDistTable {
    EmyDistEntry m_entries[10];
};
extern const EmyDistTable D_002EA450;
extern "C" int func_0011C520(void *self);
extern "C" void func_001C870C(void *theGamMan, int theA);
extern "C" void func_00176CC8(void *theObj, void *theParam);
struct PcEffParam { int m_kind; int m_unk04; int m_unk08; int m_unk0C; float m_pos[3]; float m_rot[3]; int m_num; int m_pad[21]; };
extern "C" int func_001FB5D4(int theA, int theB);
extern "C" void func_001FAC60(int theKind, int theOwner, int theB, DogVector *thePos, int theC, int theD, int theE);
extern char *D_007A3350;
extern const char D_002EA208[];
extern "C" void func_001DC48C(void *theObj, int theId, int theA, int *theOut);
// The object at +0x22220 of the game manager. Through a pointer, as an inline
// method of GamMan would reach it: the game adds the offset at run time,
// where `(char *)&D_007812C0 + 0x22220` folds into the symbol's address.
static inline void *gamSub22220() { GamMan *g = &D_007812C0; return (char *)g + 0x22220; }
extern "C" int func_0011CAF8(void *self, int theA);
extern char D_007B2140;
extern unsigned short D_007A34CC;
extern short D_007A32CC;
extern "C" void func_001CB4F0(void *, int, int *);
extern "C" void func_001CB460(void *, int, int *);
extern "C" void func_001C89E4(void *);
extern "C" void func_001C8CA4(void *, int, int);
extern "C" void func_001C898C(void *);
extern "C" void func_001C899C(void *);
extern "C" int func_001C8604(void *, int);
extern "C" void func_001639B4(void *);
extern "C" void func_0016373C(void *);
extern "C" int func_001D56F4(void *, u_long128 *, int *);

extern "C" int func_0011C464(void *self)
{
    int v = 0;
    func_001CB460(&D_007812C0, 0x1B, &v);
    return v;
}

extern "C" void func_0011C494(void *self, int theValue)
{
    int v = theValue;
    func_001CB4F0(&D_007812C0, 0x1B, &v);
}


extern "C" int func_0011C4C0(void *self)
{
    int v = 0;
    func_001CB460(&D_007812C0, 0x1C, &v);
    return v;
}


extern "C" int func_0011C4F0(void *self)
{
    int v = 0;
    func_001CB460(&D_007812C0, 0, &v);
    return v;
}


extern "C" int func_0011C520(void *self)
{
    return D_007A34CC;
}


extern "C" void func_001DA228(void *theObj, int theKind, int *theOut);
extern "C" void func_001D890C(void *theObj, void *thePos);
static inline GamList<void *> *achrList(GamMan *g = &D_007812C0)
{
    int o = 0x1D340;
    return (GamList<void *> *)((char *)g + o);
}

extern "C" int func_0011C52C(void *self, char *thePos, int theMax)
{
    int count = 0;
    GamList<void *>::iterator it;
    GamList<void *>::iterator last;
    GamList<void *> *list = achrList();
    int secta = func_0011C4F0(self);
    last = list->end();
    it = list->begin();
    for (; it != last; it.m_node = it.m_node->m_next) {
        void *obj = *it;
        if (*(int *)((char *)obj + 0x120) & 0x10000) {
            continue;
        }
        int obj_secta;
        func_001DA228(obj, 0, &obj_secta);
        if (secta == obj_secta) {
            func_001D890C(*it, thePos + count * 0x10);
            count++;
            if (count >= theMax) {
                break;
            }
        }
    }
    return count;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA1E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA208);

void vecTurnY(float *theVec, float theAngle);
extern "C" void func_001D35AC(GamMan *theGamMan, DogVector *thePos, void *theList, int theKind, int theMask1, int theMask2, float theRange);
extern "C" void func_001DB71C(ObjStat *theObj, void *thePos);

template <class T> class GamPoolList {
public:
    struct Node {
        Node *m_prev;
        Node *m_next;
        T m_data;
    };

    class iterator {
    public:
        Node *m_node;

        iterator() : m_node(0) {}
        iterator(Node *theNode) : m_node(theNode) {}
        iterator(const iterator &theIt) : m_node(theIt.m_node) {}
        T &operator*() const { return m_node->m_data; }
        iterator operator++(int)
        {
            iterator tmp = *this;
            m_node = m_node->m_next;
            return tmp;
        }
        bool operator!=(const iterator &theIt) const { return m_node != theIt.m_node; }
    };

    struct SubList {
        Node m_head;
        int m_count;

        SubList()
        {
            m_count = 0;
            m_head.m_prev = &m_head;
            m_head.m_next = &m_head;
        }
        void clear()
        {
            m_count = 0;
            m_head.m_prev = &m_head;
            m_head.m_next = &m_head;
        }
        iterator begin() { return iterator(m_head.m_next); }
        iterator end() { return iterator(&m_head); }
    };

    SubList m_free;
    SubList m_used;
    int m_max;
    int m_pad[7];
    Node *m_pool;
    int m_pad2[15];

    GamPoolList(int theMax) : m_max(0)
    {
        Node *pool = new Node[theMax];
        m_max = theMax;
        m_pool = pool;
        GamPoolList *self = this;
        for (int i = 0; i < self->m_max; i++) {
            pool[i].m_prev = &pool[i - 1];
            pool[i].m_next = &pool[i + 1];
        }
        self->m_used.clear();
        self->m_free.m_head.m_next = pool;
        self->m_free.m_count = self->m_max;
        pool[0].m_prev = &self->m_free.m_head;
        Node *last = &self->m_free.m_head.m_next[self->m_free.m_count - 1];
        self->m_free.m_head.m_prev = last;
        last->m_next = &self->m_free.m_head;
    }

    ~GamPoolList()
    {
        delete[] m_pool;
    }

    iterator begin() { return m_used.begin(); }
    iterator end() { return m_used.end(); }
};

struct PcTargetData {
    float m_pos[4];
    int m_oid;
    int m_uid;
    int m_unk18;
    short m_unk1C;
    short m_unk1E;
};

class ObjStatEx {
public:
    unsigned char m_unk000[0x100];
    int m_oid;
    unsigned char m_unk104[0x4];
    int m_unk108;
    unsigned char m_unk10C[0x1C];
    unsigned short m_uid;

    int getOID() const { return m_oid; }
    int getUnk108() const { return m_unk108; }
    unsigned short getUID() const { return m_uid; }
};

static inline void addVec(DogVector *a, DogVector *b)
{
    a->m_x += b->m_x;
    a->m_w = 1.0f;
    a->m_y += b->m_y;
    a->m_z += b->m_z;
}

extern "C" int func_0011C64C(void *self, PcTargetData *theData, int theMax, float theRange)
{
    if (!(theRange >= 5.0f)) ror_assert(D_002EA208, 0xCC, "theRange >= 5.0f");
    if (!theData) ror_assert(D_002EA208, 0xCD, "theData");
    if (!(theMax >= 10)) ror_assert(D_002EA208, 0xCE, "theMax >= 10");

    GamPoolList<ObjStatEx *> list(0x20);
    int count = 0;

    DogActor *actor = *(DogActor **)((char *)self + 0x58);
    DogVector pos = actor->m_unk40;
    float rot = actor->func_0010A650();
    DogVector ofs(0.0f, 0.0f, theRange - 5.0f, 1.0f);
    DogVector *op = &ofs;
    vecTurnY(&op->m_x, rot);
    addVec(&pos, op);

    func_001D35AC(&D_007812C0, &pos, &list, 5, 0x100000, 0x04008001, theRange);

    GamPoolList<ObjStatEx *>::iterator last = list.end();
    GamPoolList<ObjStatEx *>::iterator it = list.begin();
    for (; it != last; it++) {
        func_001DB71C((ObjStat *)*it, theData[count].m_pos);
        float dy = theData[count].m_pos[1] - pos.m_y;
        if (dy < -200.0f || dy > 30.0f) {
            continue;
        }
        ObjStatEx *&obj = *it;
        unsigned short uid = obj->getUID();
        if (uid == 0xFFFF) {
            continue;
        }
        theData[count].m_uid = uid;
        theData[count].m_oid = obj->getOID();
        theData[count].m_unk1C = obj->getUnk108();
        count++;
        if (count >= theMax) {
            break;
        }
    }
    return count;
}

extern "C" void func_0011C974(void *self, int theA, int theB, int theC)
{
    int type = 7;
    DogVector pos;
    char *actor = *(char **)((char *)self + 0x58);
    pos.m_x = *(float *)(actor + 0x40);
    pos.m_y = *(float *)(actor + 0x44);
    pos.m_z = *(float *)(actor + 0x48);
    if (theC == 0) {
        int weapon = func_0011C520(self);
        if (weapon < 0 || weapon == 0xA00) {
            theB = 0;
        }
        type = func_0011CAF8(self, weapon);
    }
    int b = func_001FB5D4(theA, type);
    func_001FAC60(0xB, D_007A3350 ? *(int *)(D_007A3350 + 0x100) : 0, b, &pos, type, theA, theB);
}

extern "C" void func_0011CA60(void *self, int theA)
{
    DogVector pos;
    char *actor = *(char **)((char *)self + 0x58);
    pos.m_x = *(float *)(actor + 0x40);
    pos.m_y = *(float *)(actor + 0x44);
    pos.m_z = *(float *)(actor + 0x48);
    int b = func_001FB5D4(theA, 2);
    func_001FAC60(0xB, D_007A3350 ? *(int *)(D_007A3350 + 0x100) : 0, b, &pos, 2, theA, 0);
}

extern "C" int func_0011CAF8(void *self, int theId)
{
    if (theId <= 0) {
        return 2;
    }
    int attack_type = 0;
    func_001DC48C(gamSub22220(), theId & 0xFFFF, 0x27, &attack_type);
    if (!(attack_type >= 0 && attack_type < 0x10000)) ror_assert(D_002EA208, 0x14E, "attack_type >= 0 && attack_type < 0x10000");
    return attack_type;
}

extern "C" int func_0011CB70(void *self, int theA)
{
    int no = *(int *)((char *)self + 0x1AC);
    if (no >= 0) {
        return no;
    }
    int r;
    switch (func_0011CAF8(self, theA)) {
    case 5:
        r = 3;
        break;
    case 4:
        r = 2;
        break;
    case 6:
        r = 1;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

extern "C" void func_0011CBD0()
{
    return func_001C89E4(&D_007812C0);
}


extern "C" int func_0011CBEC()
{
    return 1;
}


extern "C" void func_0011CBF4(void *self, int theA)
{
    return func_001C8CA4(&D_007812C0, theA, 0);
}


extern "C" int func_0011CBF4_i(void *self, int theA) asm("func_0011CBF4");
extern "C" void func_001D1C80(GamMan *theGamMan, int theA, int theB, int *theOut);
extern "C" void func_001C7E40(GamMan *theGamMan, int theA, int theB);
extern "C" void func_001D4540(GamMan *theGamMan);
extern "C" void func_001CCC30(GamMan *theGamMan, int theA);
extern char D_007A4440[];
// The pointer at +0xDC1C of the object at D_007A4440, reached the way an
// inline method would (see gamSub22220).
static inline int *sysWork() { char *p = D_007A4440; return *(int **)(p + 0xDC1C); }
static inline void setSysWork(int theIdx, int theVal) { sysWork()[theIdx] = theVal; }

extern "C" int func_0011CC14(void *self, int theA)
{
    if (func_0011CBF4_i(self, theA) == 0) {
        return -1;
    }
    GamMan *g = &D_007812C0;
    int v = 0;
    func_001D1C80(g, theA, 2, &v);
    func_001C7E40(g, (unsigned short)v, 0);
    setSysWork(0xA0 / 4, 0x13);
    setSysWork(0xA4 / 4, v);
    setSysWork(0xA8 / 4, theA);
    func_001D4540(g);
    func_001CCC30(g, theA);
    return 0;
}

extern "C" int func_0011CCD4(void *self, const u_long128 *thePos, int *theOut)
{
    int out[8];
    DogVector pos(*(const DogVector *)thePos);
    int r = func_001D56F4(&D_007812C0, (u_long128 *)&pos, out);
    if (theOut) {
        *theOut = out[4];
    }
    return r;
}


extern "C" void func_00102AB8(DogVector *theOut, int theA);
void vecNormalize(float *v);
float vecDot(float *a, float *b);
float vecLength(float *v);

extern "C" void func_0011CD20(void *self, DogVector *theOut, DogVector *theIn, int theA)
{
    DogVector pos = *(DogVector *)((char *)*(void **)((char *)self + 0x58) + 0x40);
    DogVector dir;
    DogVector *dp = &dir;
    func_00102AB8(dp, theA);
    dp->m_x -= pos.m_x;
    dp->m_y = 0.0f;
    dp->m_z -= pos.m_z;
    dp->m_w = 1.0f;
    vecNormalize(&dp->m_x);
    float d = vecDot(&dp->m_x, &theIn->m_x);
    dp->m_x *= d;
    dp->m_y *= d;
    dp->m_z *= d;
    dp->m_w = 1.0f;
    *theOut = *theIn;
    theOut->m_x -= dp->m_x;
    theOut->m_y -= dp->m_y;
    theOut->m_z -= dp->m_z;
    theOut->m_w = 1.0f;
    if (vecLength(&theOut->m_x) < 1.0f) {
        vecNormalize(&theOut->m_x);
    }
}

extern "C" int func_0011CE50(void *self)
{
    return D_007A32CC;
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA280);

extern "C" int func_001CBE38(GamMan *theGamMan, int theId);
extern "C" float func_001638FC(void *theEmy, int theId);
extern "C" float func_00163958(void *theEmy, int theId);
extern const char D_002EA280[];
extern const char D_002EA298[];
extern const char D_002EA2A8[];
extern const char D_002EA2B8[];
extern const char D_002EA2C0[];
extern const char D_002EA2D0[];

static inline int getNodeIndexByName_ce5c(DogActor *self, const char *p)
{
    if (!self->m_i3r_root) ror_assert(D_002EA298, 0x131, D_002EA2A8);
    if (!p) ror_assert(D_002EA298, 0x131, D_002EA2B8);
    return func_0022B3D8(self->m_i3r_root, p);
}

extern "C" float func_0011CE5C(void *self, DogVector *theOut, int theId, int theFlag)
{
    int id = (short)func_001CBE38(&D_007812C0, theId);
    if (id < 0 || id >= 0x80) {
        return 0.0f;
    }
    if (!*(char **)((char *)self + 0x20)) ror_assert(D_002EA208, 0x23A, D_002EA280);
    DogActor *actor = (DogActor *)(*(char **)((char *)self + 0x20) + id * 0x4D0 + 0x2920);
    int n = getNodeIndexByName_ce5c(actor, "p_fuckme");
    if (n < 0) {
        n = getNodeIndexByName_ce5c(actor, D_002EA2C0);
        if (!(n >= 0)) ror_assert(D_002EA208, 0x24E, D_002EA2D0);
    }
    actor->vfunc18(*theOut, n);
    float r;
    if (theFlag) {
        r = func_001638FC(&D_007B2140, theId);
    } else {
        r = func_00163958(&D_007B2140, theId);
    }
    return r;
}

extern "C" void func_0011D028()
{
    return func_001639B4(&D_007B2140);
}


extern "C" int func_0011D044()
{
    return func_001C8604(&D_007812C0, 0) != 0;
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA298);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA2A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA2B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA2C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA2D0);

extern "C" void func_0011D06C(void *self)
{
    func_001C870C(&D_007812C0, -1);
    if (*(int *)((char *)self + 0x118) > 0) {
        PcEffParam param;
        param.m_kind = 0x27;
        param.m_unk04 = param.m_unk08 = 0;
        char *actor = *(char **)((char *)self + 0x58);
        param.m_pos[0] = *(float *)(actor + 0x40);
        param.m_pos[1] = *(float *)(actor + 0x44);
        param.m_pos[2] = *(float *)(actor + 0x48);
        param.m_rot[0] = *(float *)(actor + 0x50);
        param.m_rot[1] = *(float *)(actor + 0x54);
        param.m_rot[2] = *(float *)(actor + 0x58);
        param.m_num = *(int *)((char *)self + 0x118);
        func_00176CC8(*(char **)((char *)self + 0x20) + 0x837E0, &param);
    }
    *(int *)((char *)self + 0x118) = 0;
    int id = func_0011CE50(self);
    if (id >= 0) {
        DogActor *actor = (DogActor *)(*(char **)((char *)self + 0x20) + id * 0x4D0 + 0x2920);
        actor->func_0010B1B0(actor->func_0010AA5C("reload"), 0, 0.016666694f, -1, -1);
    }
}

extern "C" void func_0011D15C()
{
    return func_001C898C(&D_007812C0);
}


extern "C" void func_0011D178(char *self)
{
    func_001C899C(&D_007812C0);
    (*(int *)(self + 0x118))++;
}


extern "C" void func_0011D1B0()
{
    return func_0016373C(&D_007B2140);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011D1CC);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA340);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA378);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA3F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA3F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA408);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA410);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA418);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA420);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA428);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA430);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA438);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA440);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA450);

extern "C" int func_0011D3D0(void *self, int theId, float theDist)
{
    int kind = func_00163BE4(&D_007B2140);
    if (kind < 0) {
        return -1;
    }
    EmyDistTable table = D_002EA450;
    int idx;
    if (kind == 6) {
        idx = 8;
        int id = (short)func_001CBE38(&D_007812C0, theId);
        if (id >= 0) {
            if (!*(char **)((char *)self + 0x20)) ror_assert(D_002EA208, 0x3A9, D_002EA280);
            DogActor *actor = (DogActor *)(*(char **)((char *)self + 0x20) + id * 0x4D0 + 0x2920);
            int node = getNodeIndexByName_ce5c(actor, "Bip01 Neck");
            DogVector pos;
            actor->vfunc18(pos, node < 0 ? 0 : node);
            if (pos.m_y >= -140.0f) {
                idx = 9;
            }
        }
    } else {
        for (idx = 0; idx < 8; idx++) {
            if (table.m_entries[idx].m_id == kind) {
                break;
            }
        }
        if (idx >= 8) {
            idx = 0;
        }
    }
    int ret = -1;
    if (theDist < table.m_entries[idx].m_range[0] && theDist >= table.m_entries[idx].m_range[1]) {
        ret = 1;
    } else if (theDist < table.m_entries[idx].m_range[2] && theDist >= table.m_entries[idx].m_range[3]) {
        ret = 0;
    } else if (theDist < table.m_entries[idx].m_range[4] && theDist >= table.m_entries[idx].m_range[5]) {
        ret = 3;
    } else if (theDist < table.m_entries[idx].m_range[6] && theDist >= table.m_entries[idx].m_range[7]) {
        ret = 2;
    }
    return ret;
}
