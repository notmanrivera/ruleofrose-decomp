#include "ror.h"
#include "include_asm.h"
extern "C" int X_ror_assert(...) asm("ror_assert");
extern const char D_002E5728[];
extern const char D_002E5878[];
extern int D_007A329C;
extern int D_007A32CC;
extern const char D_002E5738[];
extern const char D_002E57A8[];
#undef ASSERT_FILE
#define ASSERT_FILE D_002E5728
extern const char D_002E5728[];
#include "game/gamman.h"
#include "game/gamtrg.h"
struct DogEntityStub_3510 {
    unsigned char m_unk00[0x94];
    virtual void X__vfunc_01();
    virtual void X__vfunc_02();
    virtual void X__vfunc_03();
    virtual void X__vfunc_04();
    virtual void X__vfunc_05();
    virtual void X__vfunc_06();
    virtual void X__vfunc_07();
    virtual void X__vfunc_08();
    virtual void X__vfunc_09();
    virtual void X__vfunc_10();
    virtual void X__vfunc_11();
    virtual void X__vfunc_12();
    virtual void X__vfunc_13();
    virtual void X__vfunc_14();
    virtual void X__vfunc_15();
    virtual void X__vfunc_16();
    virtual void X__vfunc_17();
    virtual void X__vfunc_18(void *theOut, int theNode);
};
struct DogActorStub_3510 : public DogEntityStub_3510 {
    unsigned char m_unk98[0x11C - 0x98];
    void *m_i3r_root;
    unsigned char m_unk120[0x4D0 - 0x120];
};
STATIC_ASSERT(sizeof(DogActorStub_3510) == 0x4D0, DogActorStub_3510_size);
extern DogActorStub_3510 X_D_006FE6A0_3510[] asm("D_006FE6A0");
extern "C" int func_0022B3D8(void *theRoot, const char *theName);
extern const char D_002E57C8[];
extern const char D_002E57D8[];
extern const char D_002E57E8[];
extern const char D_002E57F8[];
extern const char D_002E5800[];
extern "C" float func_001638FC(void *theEmy, int theId);
extern "C" float func_00163958(void *theEmy, int theId);
static inline int getNodeIndexByName_3510(DogActorStub_3510 *self, const char *p)
{
    if (!self->m_i3r_root) ror_assert(D_002E57D8, 0x131, D_002E57E8);
    if (!p) ror_assert(D_002E57D8, 0x131, D_002E57F8);
    return func_0022B3D8(self->m_i3r_root, p);
}
extern const char D_002E5808[];
extern const char D_002E5830[];
struct UtlEnemyInfo {
    unsigned char m_unk00[0x30];
    float m_dist;
    float m_ang;
    unsigned char m_unk38[0x8];
};
struct UtlEnemyInfoBuf {
    enum { MAX_INFO = 0x20 };
    UtlEnemyInfo m_info[MAX_INFO];
    int m_count;
};
extern const char D_002E57B8[];
extern "C" void X_func_001DC48C_s(void *theObj, int theId, int theA, short *theOut) asm("func_001DC48C");
extern "C" int X_func_001033F0(int theA) asm("func_001033F0");
extern "C" unsigned long long X_func_0010315C(float *theOut, int theA) asm("func_0010315C");
extern "C" int func_001D1A48(int arg0);
extern "C" void func_001C6A40(void *theGamMan, int theA);
extern "C" void func_001D1C80(GamMan *theGamMan, int theA, int theB, int *theOut);
extern "C" void func_001C7E40(GamMan *theGamMan, int theA, int theB);
extern "C" void func_001CCC30(GamMan *theGamMan, int theA);
extern "C" void func_001DC48C(void *theObj, int theId, int theA, int *theOut);
extern "C" void func_001DD00C(void *theObj, int theA, int theB);
extern "C" void func_001DCD38(void *theObj, int theA, int theB);
static inline void *gamSub22220() { GamMan *g = &D_007812C0; return (char *)g + 0x22220; }
extern "C" int func_001CBE38(int arg0, int arg1);
extern "C" void func_001C6CCC(int arg0, int arg1, void *theOut);
extern "C" void func_001C8E1C(int arg0, int arg1);
extern "C" void func_001D046C(void *theSnd, int arg0);
struct GameFlags {
    int m_unk00;
    int m_flags;
};
extern GameFlags *D_007B2060;
struct TblSound {
    int m_oid;
    int m_alias;
    int m_tag;
    const char *m_name;
};
extern TblSound tbl_sound[] asm("D_002E6978");
extern char D_007B2140;
extern "C" void func_001026B0(int theN, int theFade, int theA);
extern "C" int func_001025C0(unsigned int theN);
static inline char *getSnd(GamMan *g) { return (char *)g + 0x18E00; }
extern "C" void func_001E4EBC(void *theSnd, int theOID, int theA, int theB, int theC);
extern "C" int func_001E5E58(void *theSnd, int theOID, int theA, int theB);
extern "C" void func_001F97C8(int theOID, int theFade);
extern "C" int func_0010423C(int theMin, int theMax);
extern "C" void func_001D05F4(void *theGame, int theA, void *theOut);
extern "C" void func_00163A10(void *theA, int theOID);
extern "C" void func_00163770(void *theA, int theOID);
extern "C" int func_0010315C(void *theOut, int theA);
extern "C" int func_00102BF0(void *theOut, int theA);

extern "C" int func_00102490(unsigned short theA)
{
    int v;

    func_001DC48C(gamSub22220(), theA, 0xF, &v);
    return (unsigned short)v;
}

extern "C" const char *func_001024D0(int theN)
{
  int alias = tbl_sound[theN].m_alias;
  int no = theN;
  if (alias >= 0)
  {
    no = alias;
    (tbl_sound[no].m_tag == no) ? ((void) 0) : (ror_assert(D_002E5728, 325, D_002E5738));
  }
  return tbl_sound[no].m_name;
}


extern "C" int func_0010254C(int theOID, int theA)
{
    if (theA) {
        func_001E4EBC(getSnd(&D_007812C0), theOID, 1, theA, 0);
    } else {
        func_001E4EBC(getSnd(&D_007812C0), theOID, 1, 0, 0);
    }
}


INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5728);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5738);

extern "C" int func_001025C0(unsigned int theN)
{
  if (theN >= 200)
  {
    return 0;
  }
  {
    (tbl_sound[theN].m_tag == theN) ? ((void) 0) : (ror_assert(D_002E5728, 356, "tbl_sound[theN].m_tag == theN"));
    unsigned int no = theN;
    if (tbl_sound[theN].m_alias >= 0)
    {
      no = tbl_sound[theN].m_alias;
      if (((!tbl_sound) && (!tbl_sound)) && (!tbl_sound))
      {
      }
      (tbl_sound[no].m_tag == no) ? ((void) 0) : (ror_assert(D_002E5728, 379, D_002E5738));
    }
    int oid = tbl_sound[no].m_oid;
    if (tbl_sound)
    {
      (oid != 0) ? ((void) 0) : (ror_assert(D_002E5728, 388, "oid != 0"));
      return oid;
    }
    else
    {
      (oid != 0) ? ((void) 0) : (ror_assert(D_002E5728, 388, "oid != 0"));
      return oid;
    }
  }
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_001026B0(int theN, int theFade, int theA)
{
    int oid = func_001025C0(theN);
    if (oid) {
        if (theA) {
            func_001E4EBC(getSnd(&D_007812C0), oid, 1, theA, 0);
        } else if (theFade > 0) {
            func_001F97C8(oid, theFade);
        } else {
            func_001E4EBC(getSnd(&D_007812C0), oid, 1, 0, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utlgame", func_001026B0);
#endif


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_00102758(int theN)
{
    int oid = func_001025C0(theN);
    void *snd = getSnd(&D_007812C0);
    if (oid && func_001E5E58(snd, oid, 0x16, 0) == 0) {
        func_001E4EBC(snd, oid, 1, 0, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utlgame", func_00102758);
#endif


extern "C" int func_001027D4(int theN)
{
    int oid = func_001025C0(theN);

    if (oid && func_001E5E58(getSnd(&D_007812C0), oid, 0x16, 0) != 0) {
        func_001E5E58(getSnd(&D_007812C0), oid, 1, 0);
    }
}


extern "C" int func_0010284C(int theN, int theLimit, int theMax)
{
    if (func_0010423C(0, theMax) < theLimit) {
        func_001026B0(theN, 0, 0);
        return 1;
    }
    return 0;
}


extern "C" void func_001028A8(int theA, int theB)
{
    if (func_0010423C(0, 200) < 100) {
        return func_001026B0(theA, 0, 0);
    }
    func_001026B0(theB, 0, 0);
}


extern "C" void func_00102918(int theA, int theB, int theC)
{
    int r = func_0010423C(0, 300);
    if (r < 100) {
        return func_001026B0(theA, 0, 0);
    }
    if (r < 200) {
        return func_001026B0(theB, 0, 0);
    }
    func_001026B0(theC, 0, 0);
}


extern "C" void func_001029C4(int theA, int theB, int theC, int theD)
{
    int r = func_0010423C(0, 400);
    if (r < 100) {
        return func_001026B0(theA, 0, 0);
    }
    if (r < 200) {
        return func_001026B0(theB, 0, 0);
    }
    if (r < 300) {
        return func_001026B0(theC, 0, 0);
    }
    func_001026B0(theD, 0, 0);
}


extern "C" void func_00102AB8(void *theOut, int theA)
{
    func_001D05F4(&D_007812C0, theA, theOut);
}


extern "C" void func_00102ADC(int theOID)
{
#line 575
    ASSERT_S(theOID != 0, D_002E57A8);
    return func_00163A10(&D_007B2140, theOID);
}


extern "C" void func_00102B24(int theOID)
{
#line 584
    ASSERT_S(theOID != 0, D_002E57A8);
    return func_00163770(&D_007B2140, theOID);
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_00102B6C(void *theOut, int *theList, int theNum)
{
    int i;
    int *p = theList;
    for (i = 0; i < theNum; i++) {
        int r = func_0010315C(theOut, *p);
        if (r) {
            return r;
        }
        r = func_00102BF0(theOut, *p);
        p++;
        if (r) {
            return r;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utlgame", func_00102B6C);
#endif


INCLUDE_ASM("asm/nonmatchings/utl/utlgame", func_00102BF0);

extern "C" ObjStat *func_00102D54(int theUid)
{
    GamList<ObjStat *> *list = D_007812C0.getVFchrListPtr();

    for (GamList<ObjStat *>::iterator it = list->begin(); it != list->end(); it++) {
        ObjStat *obj = *it;
        if (theUid == obj->getUID()) {
            return obj;
        }
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E57A8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E57B8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E57C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E57D8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E57E8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E57F8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5800);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5808);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5830);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5878);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5884);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5888);

INCLUDE_ASM("asm/nonmatchings/utl/utlgame", func_00102DC0);

extern "C" unsigned long long X_func_0010315C(float *theOut, int theA)
{
    GamList<FCHRstat *> *list = D_007812C0.getFchrListPtr();

    for (GamList<FCHRstat *>::iterator it = list->begin(); it != list->end(); it++) {
        if (theA == (*it)->getUID()) {
            if (X_func_001033F0(theA) == 0) {
                func_001DB71C(*it, theOut);
                return (unsigned int)(*it)->getOID() | ((unsigned long long)theA << 32);
            }
        }
    }
    return 0;
}

extern "C" int func_00103240(int *theOut, int theMax, int theA)
{
    short v;
    int id = theA & 0xFFFF;
#line 797
    ASSERT_S(theMax >= 4, D_002E57B8);

    X_func_001DC48C_s(gamSub22220(), id, 0x10, &v);
    theOut[0] = v;
    X_func_001DC48C_s(gamSub22220(), id, 0x11, &v);
    theOut[1] = v;
    X_func_001DC48C_s(gamSub22220(), id, 0x12, &v);
    theOut[2] = v;

    if ((theA >> 9) != 6) {
        theOut[3] = theA;
        return 4;
    }
    theOut[3] = -1;
    return 3;
}

extern "C" void func_0010332C(int theA)
{
    GamMan *g = &D_007812C0;
    int v = 0;

    func_001D1C80(g, theA, 2, &v);
    func_001C7E40(g, (unsigned short)v, 0);
    func_001CCC30(g, theA);
}

extern "C" int func_00103390(unsigned int arg0)
{
    int t = (arg0 >> 0x17) & 0x1F;

    if (t == 5) {
        return 1;
    }
    return t == 6 ? 2 : 0;
}

extern "C" void func_001033B8(unsigned short theA)
{
    func_001DCD38(gamSub22220(), theA, 2);
}

extern "C" void func_001033F0(unsigned short theA)
{
    func_001DD00C(gamSub22220(), theA, 2);
}

extern "C" void func_00103428(int theA)
{
    func_001C8E1C((int)&D_007812C0, theA);
}

extern "C" void func_0010344C(int arg0)
{
    return func_001D046C(&D_007812C0, arg0);
}

extern "C" int func_0010346C()
{
    if (D_007B2060->m_flags & 4) {
        return 1;
    }
    return 0;
}

extern "C" int func_00103484()
{
    int v = 0;

    func_001C6CCC((int)&D_007812C0, 0x12, &v);
    return v != 0;
}

extern "C" int func_001034B8()
{
    int v;

    func_001C6CCC((int)&D_007812C0, 5, &v);
    return v;
}

extern "C" short func_001034E4(int theA)
{
    return func_001CBE38((int)&D_007812C0, theA);
}

extern "C" float func_00103510(void *theOut, int theId, int theFlag)
{
    int id = (short)func_001CBE38((int)&D_007812C0, theId);
    float r = 0.0f;
    if ((unsigned int)id < 0x80U) {
        DogActorStub_3510 *actor = &X_D_006FE6A0_3510[id];
        int n = getNodeIndexByName_3510(actor, D_002E57C8);
#line 931
        ASSERT_S(n >= 0, D_002E5800);
        actor->X__vfunc_18(theOut, n);
        if (theFlag) {
            r = func_001638FC(&D_007B2140, theId);
        } else {
            r = func_00163958(&D_007B2140, theId);
        }
    }
    return r;
}

extern "C" int func_00103654(UtlEnemyInfoBuf &theInfo, float theR)
{
#line 967
    ASSERT_S(-3.141593039035797f <= theR && theR < 3.141593039035797f, D_002E5808);
#line 968
    ASSERT_S(0 <= theInfo.m_count && theInfo.m_count <= UtlEnemyInfoBuf::MAX_INFO, D_002E5830);

    int n = theInfo.m_count;
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        return 0;
    }

    float minDist = 1e10f;
    int best = -1;
    int i = 0;
    if (n > 0) {
        UtlEnemyInfo *p = theInfo.m_info;
        do {
            float ang = p->m_ang;
            if (ang < -theR || theR < ang) {
            } else {
                float dist = p->m_dist;
                if (dist < minDist) {
                    minDist = dist;
                    best = i;
                }
            }
            i++;
            p++;
        } while (i < n);
    }
    return best;
}

INCLUDE_ASM("asm/nonmatchings/utl/utlgame", func_0010376C);

INCLUDE_ASM("asm/nonmatchings/utl/utlgame", func_00103A90);

// NON_MATCHING: 24/70 differ, 1 reloc differs, 11 edits
#ifdef NON_MATCHING
struct UtlEnemySub { int m_oid; int m_uid; };
struct UtlEnemyInfo2 { float m_pos[4]; unsigned char m_unk10[0x10]; UtlEnemySub m_sub; unsigned char m_unk28[0x18]; };
extern "C" int func_00103CCC(UtlEnemyInfo2 *theOut, int theFlg)
{
    int count = 0;
    GamList<ObjStat *> *list = D_007812C0.getAVFchrListPtr();
    GamList<ObjStat *>::iterator end = list->end();
    UtlEnemyInfo2 *p = theOut;

    for (GamList<ObjStat *>::iterator it = list->begin(); it != end; it++) {
        if (theFlg && (*it)->checkFlg(0x20)) {
            continue;
        }
        theOut[count].m_sub.m_uid = (*it)->getUID();
        theOut[count].m_sub.m_oid = (*it)->getOID();
        func_001DB71C(*it, p->m_pos);
        count++;
        p++;
        if (count >= 0x20) {
            return count;
        }
    }
    return count;
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utlgame", func_00103CCC);
#endif

extern "C" int func_00103DE4()
{
    GamMan *g = &D_007812C0;

    if (func_001D1A48((int)g)) {
        return 0;
    }
    func_001C6A40(g, 0x100000);
    *(int *)((char *)g + 0x21F48) |= 0x400;
    return 1;
}

extern "C" int func_00103E4C()
{
    int temp_s0;

    temp_s0 = D_007A32CC;
    if (temp_s0 >= 0x80) {
        X_ror_assert(D_002E5728, 0x4D9, D_002E5878);
    }
    return temp_s0;
}


extern "C" int func_00103E94()
{
    int temp_s0;

    temp_s0 = D_007A329C;
    if (temp_s0 >= 0x80) {
        X_ror_assert(D_002E5728, 0x4E3, D_002E5878);
    }
    return temp_s0;
}


INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5890);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E58A0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E58B0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E58B8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E58C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E58E0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E58F8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5910);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5928);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5940);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5958);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5968);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5978);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5988);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5998);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E59A8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E59B8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E59C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E59D8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E59F0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5A00);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5A18);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5A30);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5A48);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5A60);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5A70);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5A80);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5A90);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5AA0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5AB0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5AC0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5AD0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5AE0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5AF0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5B00);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5B10);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5B28);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5B40);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5B58);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5B68);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5B78);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5B88);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5BA0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5BB8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5BD0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5BE8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C00);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C10);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C20);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C38);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C48);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C58);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C68);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C78);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5C88);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5CA0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5CB8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5CD0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5CE0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5CF0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D00);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D10);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D20);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D38);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D48);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D50);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D60);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D78);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5D88);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5DA0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5DB8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5DD0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5DE8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5E00);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5E18);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5E30);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5E48);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5E60);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5E78);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5E90);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5EA8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5EC0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5ED8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5EF0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5F08);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5F20);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5F38);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5F50);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5F68);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5F80);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5F98);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5FB0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5FC8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5FE0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E5FF8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6010);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6028);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6040);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6058);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6068);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6078);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6088);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6098);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E60B0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E60C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E60E0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E60F8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6110);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6120);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6130);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6140);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6150);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6168);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6180);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6198);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E61B0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E61C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E61D8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E61F0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6208);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6220);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6238);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6250);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6268);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6280);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6298);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E62A8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E62B8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E62C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E62E0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E62F0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6308);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6318);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6328);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6338);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6350);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6368);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6378);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6388);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6398);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E63A8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E63C0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E63D8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E63F0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6408);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6420);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6438);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6450);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6468);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6480);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6498);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E64B0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E64C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E64E8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6508);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6528);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6540);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6558);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6578);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6598);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E65B0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E65C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E65E8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6608);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6620);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6638);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6650);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6668);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6680);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6698);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E66B0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E66C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E66E0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E66F8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6710);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6728);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6740);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6760);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6780);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E67A0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E67B8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E67D0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E67F0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6810);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6828);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6840);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6860);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6880);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6898);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E68B0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E68C8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E68E0);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E68F8);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6910);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6918);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6928);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6930);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6940);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6950);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6960);

INCLUDE_RODATA("asm/nonmatchings/utl/utlgame", D_002E6978);
