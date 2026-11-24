#include "ror.h"
#include "include_asm.h"
#include "mag/magscene.h"
#include "mag/maglifewindow.h"
#include "dog/dogtexinfo.h"
#include "utl/utltm2.h"
#include "bed/bedmemory.h"
#include "sdk/math.h"
extern "C" float func_002337E0(const float *, const float *, const float *, float *);
void vecNormalize(float *v);
extern "C" void func_00130258(MagLifeWindow *w, int a, int b, const char *str, int d);
extern const char D_002ED4B8[];
extern "C" void live__10MagLifeBwn(MagLifeBwn *);
extern "C" void MagLifeBwnCtrl__vfunc_02(void *);
extern "C" float func_00133454(MagScene *, DogModelHit *, DogVector *, DogVector *, int);
extern BedMemory D_006E9800;
extern "C" void func_00176C50(void *);
extern "C" void func_0019237C(void *);
extern "C" void func_00138804(MagScene *);
extern "C" void func_00194548();
class MagScene;
extern "C" void func_001311F4(MagScene *, int *);
struct MagLifeBase {
    unsigned char m_unk00[0x14];
    void *m_vtbl;
    unsigned char m_unk18[0x68];
};
struct MagLifeTest : public MagLifeBase {
    int m_unk80;
    int m_unk84;
    MagLifeTest() asm("func_0013114C");
};
extern "C" void func_0011A888(MagLifeTest *);
extern "C" char _vt$11MagLifeTest[];
extern "C" int Xii_func_0011DD40(int) asm("func_0011DD40");
extern "C" int Xiiiii_setActor__9MagLifePCP8DogActorii(int, int, int, int) asm("setActor__9MagLifePCP8DogActorii");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern const char D_002ED4A0[];
extern const char D_002ED680[];

#undef ASSERT_FILE
#define ASSERT_FILE D_002ED4A0
#define MAX_WINDOW 4

extern const char D_002ED4A0[];     // "mag/magscene.cpp"
extern const char D_002ED680[];     // "winNo >= 0 && winNo < MAX_WINDOW"
extern const char D_002ED6A8[];     // "theN >= 0 && theN < MAX_WINDOW"

extern "C" void func_00130214(MagLifeWindow *w, int a, int b);
extern "C" void func_00130230(MagLifeWindow *w, int a, int b, int c);
extern "C" void func_0012FCA8(MagLifeWindow *w, int a, int b, int c, int d);
extern "C" void func_0012FD30(MagLifeWindow *w, int a);
extern "C" void func_0012FD88(MagLifeWindow *w, int a);
extern "C" void func_0012FDDC(MagLifeWindow *w, int a);
extern "C" void func_0012FE68(MagLifeWindow *w, int a, int b, int c);
extern "C" void func_0012FEF8(MagLifeWindow *w, int a, int b, int c);
extern "C" void func_001BEBEC(void *thePage, void *theArg);
extern "C" void func_001BFF28(void *thePage, int theA);
extern "C" void func_001BFF5C(void *thePage, int theA);
extern "C" void func_001BFF64(void *thePage, int theA);
extern "C" void func_001C047C(void *thePage, int theA);
extern "C" void setActor__9MagLifePCP8DogActorii(void *thePC, DogActor *theActor, int theNo, int theType);
extern "C" void setActor__10MagLifeBwnP8DogActorii(void *theBwn, DogActor *theActor, int theNo, int theType);
extern "C" void func_0011DD40(void *thePC);
extern "C" void func_00132430(MagScene *self, int theNo);
extern "C" void transform__11DogEntityEx(void *theCamera);
extern const char D_002ED570[];
extern const char D_002ED580[];
extern "C" void func_00133144(MagScene *self, int theNo, int theID, int theA, int theB, int theC, float theD);
extern "C" void func_001331F4(MagScene *self, int theNo, int theID, int theA, int theB, int theC, float theD);
extern "C" void func_0012F790(void *theFader, void *theTexInfo);
extern "C" void func_0012FC80(void *theFader, float theMagnify, int theA);
extern "C" void func_0012F518(void *theFader, void *theTexInfo, const char *theName);
extern "C" void func_0012F7F4(void *theFader, int theA, int theB);
extern "C" void func_001BEEB4(void *thePage);
extern "C" void func_001BFE30(void *thePage, int theA);
extern "C" void updatePicture(void *thePicture) asm("func_00219A98");
extern "C" void func_001305EC(MagLifeWindow *w, int a, int b);
extern "C" void func_0011AF04(void *thePC);
extern "C" void message__9MagLifePCiiPv(void *thePC, int theA, int theB, void *theC);
extern "C" void func_0012C9C0(void *thePC);

MagLifeTest::MagLifeTest()
{
    func_0011A888(this);
    m_vtbl = _vt$11MagLifeTest;
    m_unk80 = 0;
    m_unk84 = 0;
}

extern "C" void func_00131184(MagScene *arg0, int arg1, int arg2, int arg3)
{
    int arr[8];
    arr[0] = arg3 ? 4 : 0;
    arr[1] = 2;
    arr[2] = arg1;
    arr[5] = arg2;
    func_001311F4(arg0, arr);
}

extern "C" void func_001311BC(MagScene *arg0, int arg1, int arg2, int arg3)
{
    int arr[8];
    arr[0] = arg3 ? 4 : 0;
    arr[1] = 6;
    arr[2] = arg1;
    arr[5] = arg2;
    func_001311F4(arg0, arr);
}

// D_002ED478: the end of mag/maglifetest's .rodata now (config/splits_manual.tsv)

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED4A0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED4B8);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001311F4);

extern "C" int func_00131550(MagScene *self)
{
    int mode;
    switch (self->m_unk43700) {
    case 0:
    case 4:
        mode = self->m_unk41850.m_unk00;
        break;
    case 1:
    case 2:
        mode = self->m_unk41890.m_unk00;
        break;
    default:
        return 0;
    }
    switch (mode) {
    case 1:
    case 5:
        return 2;
    case 2:
    case 3:
        return 3;
    case 6:
    case 7:
        return 4;
    case 4:
        return 5;
    case 8:
        return 6;
    }
    return 0;
}

extern "C" int func_00131608(MagScene *self)
{
    return *(int *)((char *)self + 0x41880);
}


extern "C" void func_00131618(MagScene *arg0, float fparg0)
{
    arg0->m_unk2AA4C = fparg0;
    arg0->m_unk2AA48 = arg0->m_unk2AA10;
    arg0->m_unk2AA14 = fparg0;
}

extern "C" void func_0013164C(MagScene *self)
{
    return func_0011AF04(&self->m_pc);
}


extern "C" void func_0013166C(MagScene *self, int theA, int theB)
{
    return message__9MagLifePCiiPv(&self->m_pc, theA, theB, 0);
}


extern "C" void func_00131690(MagScene *self)
{
    func_0012C9C0(&self->m_pc);
}


void MagScene::func_001316B8(int theNo, int theType)
{
    BedSubMode *sub = &m_sub_mode;
    *(int *)((char *)this + 0x853B8) = theNo;
    *(int *)((char *)this + 0x22AC) = theType;
    if (theNo >= 0) {
        setActor__9MagLifePCP8DogActorii(&m_pc, &m_actor[theNo], theNo, theType);
        m_unk29120[theNo] |= 0x60;
        func_0011DD40(&m_pc);
        ((int *)sub)[0] = 1;
        ((int *)sub)[1] = -1;
    } else {
        setActor__9MagLifePCP8DogActorii(&m_pc, 0, theNo, theType);
        ((int *)sub)[1] = -1;
        ((int *)sub)[0] = 0;
    }
}


void MagScene::func_00131790(int theNo, int theType)
{
    *(int *)((char *)this + 0x853B4) = theNo;
    if (theNo >= 0) {
        setActor__10MagLifeBwnP8DogActorii((char *)this + 0x2AFE0, &m_actor[theNo], theNo, theType);
        char *ctrl = (char *)this + 0x2BD20;
        *(void **)(ctrl + 0x70) = (char *)this + 0x2AFE0;
        *(void **)(ctrl + 0x74) = &m_pc;
    } else {
        setActor__10MagLifeBwnP8DogActorii((char *)this + 0x2AFE0, 0, -1, 0);
        char *ctrl = (char *)this + 0x2BD20;
        *(void **)(ctrl + 0x70) = 0;
        *(void **)(ctrl + 0x74) = 0;
    }
}


INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED500);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131840__8MagScene);

// NON_MATCHING: function matches (0x168/0x168), blocked on .rodata (D_002ED538 needs .align 3 in config/rodata_align_manual.tsv)
#ifdef NON_MATCHING
struct I3dPicture {
    unsigned char m_unk00[0x50];
    void *m_pixels;
};
extern "C" void func_00137330(MagScene *);
extern "C" Tm2Picture *func_00104E64(Tm2Header *h, int theN);
extern "C" int func_001BEDC0(MagWindowPage *arg0, void *arg1, int arg2, int arg3, int arg4);

void MagScene::func_00131A28()
{
    func_00137330(this);
    tag_I3dTexInfo_s *texInfo = m_tex_info.m_tex_info;
    for (int i = 0; i < 4; i++) {
        void *p = ((I3dPicture *)texInfo[m_unk028F4[i]].pPicture)->m_pixels;
#line 554
        ASSERT(p);
        DogTexData *d = &m_tex_info.m_tex_data[m_unk028F4[i]];
        Tm2Picture *pic = func_00104E64((Tm2Header *)d->m_data, 0);
        if (pic->ImageType == 5) {
            func_001BEDC0(&m_unk02744[i], p, 0x200, 0x100, 8);
        } else {
            func_001BEDC0(&m_unk02744[i], p, 0x200, 0x100, 4);
        }
    }
    m_unk854E0 = this;
    m_unk854E8 = this;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131A28__8MagScene);
#endif

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00131B90__8MagSceneP7I3dDraw);

void func_00131F6C(void) {
}

extern "C" void func_00131F74(MagScene *self)
{
    func_00176C50(self->m_unk837E0);
    func_0019237C(self->m_unk84AA8);
    if (self->m_unk02908) {
        D_006E9800.free(self->m_unk02908);
        self->m_unk02908 = 0;
    }
    for (int i = 0; i < MAG_MAX_ACTOR; i++) {
        self->m_actor[i].release(0);
    }
    func_00138804(self);
    self->m_tex_info.release();
    self->m_life_man.remove(&self->m_unk41850);
    self->m_life_man.term();
    func_00194548();
}

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED538);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED570);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED580);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00132048);

extern "C" void func_0013233C(MagScene *self)
{
    MagLifeBwn *bwn = &self->m_bwn;
    if (bwn->m_actor) {
        live__10MagLifeBwn(bwn);
        MagLifeBwnCtrl__vfunc_02(&self->m_unk2BD20);
        if (self->m_pc.m_actor) {
            DogVector bwnPos = bwn->m_actor->m_unk40;
            DogVector pcPos = self->m_pc.m_actor->m_unk40;
            float dy = bwnPos.m_y - pcPos.m_y;
            if (-250.0f <= dy && dy <= 250.0f) {
                self->m_unk29120[self->m_unk853B4] |= 0x60;
            } else {
                self->m_unk29120[self->m_unk853B4] &= ~0x60;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00132430);

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_0013262C(MagScene *self, int theA)
{
    int *flag = self->m_unk29120;
    for (int i = 0; i < 128; i++) {
        DogActor *actor = &self->m_actor[i];
        if (actor->m_i3r_root && I3rRoot__CheckIdString(actor->m_i3r_root) != 0) {
            ror_assert(D_002ED570, 248, D_002ED580);
        }
        if (actor->m_i3r_root) {
            if (theA == 0) {
                if (!(*flag & 8)) {
                    self->m_actor[i].func_0010D388();
                    if (flag[0x80]) {
                        func_00132430(self, i);
                    }
                }
            } else if (*flag & 8) {
                self->m_actor[i].func_0010D388();
            }
        }
        flag++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013262C);
#endif


extern "C" void func_00132744(MagScene *self)
{
    BedSubMode *sub = &self->m_sub_mode;
    int mode = 8;
    sub->push();
    ((int *)sub)[0] = mode;
    ((int *)sub)[1] = -1;
}


extern "C" void func_00132784(MagScene *self)
{
    self->m_sub_mode.pop();
}


extern "C" void func_001327A0(MagScene *self)
{
    self->m_life_man.live(4);
    transform__11DogEntityEx((char *)self + 0x2AB70);
}


INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_001327DC__8MagSceneP6BedPadT1);

extern "C" int func_00133090(MagScene *self, DogActor *thePtr)
{
#line 1495
    ASSERT(thePtr);
    return (unsigned int)((char *)thePtr - (char *)self - 0x2920) / sizeof(DogActor);
}


extern "C" int func_001330F4(MagScene *self, int theNo)
{
    DogMotionBlend *m = &self->m_actor[theNo].m_motion_now;
    int r;
    if (*(float *)((char *)m + 4) == 0.0f) {
        r = ~m->getMainMotionNo();
    } else {
        r = m->getMainMotionNo();
    }
    return r;
}


extern "C" void func_00133144(MagScene *self, int theNo, int theID, int theA, int theB, int theC, float theD)
{
    if (theA >= 0) {
        self->m_actor[theNo].func_0010BF00(theA);
    }
    DogActor *actor = &self->m_actor[theNo];
    actor->func_0010AF18(theID, 0, theD, -1, -1);
    actor->m_motion_flag[0] = theB >> 8;
    actor->m_motion_flag[1] = theB & 0xFF;
}

extern "C" void func_001331F4(MagScene *self, int theNo, int theID, int theA, int theB, int theC, float theD)
{
    if (theA >= 0) {
        self->m_actor[theNo].func_0010BF00(theA);
    }
    self->m_actor[theNo].func_0010B1B0(theID, theB >> 8, theD, theB & 0xFF, -1);
}

extern "C" void func_00133288(MagScene *self, int theNo, const char *theName, int theA, int theB, int theC, float theD)
{
    int id = self->m_actor[theNo].func_0010AA9C(theName);
    if (id >= 0) {
        func_00133144(self, theNo, id, theA, theB, theC, theD);
    }
}


extern "C" void func_00133324(MagScene *self, int theNo, const char *theName, int theA, int theB, int theC, float theD)
{
    int id = self->m_actor[theNo].func_0010AA9C(theName);
    if (id >= 0) {
        func_001331F4(self, theNo, id, theA, theB, theC, theD);
    }
}


extern "C" void func_001333C0(MagScene *self, int theNo, float theSpeed)
{
    self->m_actor[theNo].m_motion_now.setMainSpeed(theSpeed * 0.016666694f);
}


extern "C" float func_001333E4(MagScene *self, int theNo, int theID)
{
    if (theID < 0) {
        theID = self->m_actor[theNo].m_motion_now.getMainMotionNo();
    }
    return self->m_actor[theNo].func_0010D0E8(theID);
}


extern "C" float func_00133440(MagScene *self, int theNo)
{
    return *(float *)((char *)&self->m_actor[theNo] + 0x1E8);
}


INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133454);

// NON_MATCHING: 33/72 differ, 1 reloc differs (size 0x120, game 0x124), 13 edits
#ifdef NON_MATCHING
extern "C" float func_00133B80(MagScene *, DogModelHit *, const float *, float);
static inline bool modelIsAlive(DogModel *m)
{
    if (m->m_i3r_root) {
        ((I3D_OK == I3rRoot__CheckIdString(m->m_i3r_root)) ? (void)0 : ror_assert(D_002ED570, 248, D_002ED580));
    }
    return m->m_i3r_root != 0;
}

extern "C" float func_00133658(MagScene *self, DogModelHit *arg1, const float *arg2, float fparg0)
{
    float ret = -1.0f;
    if (fparg0 > 0.0f) {
        ret = func_00133B80(self, arg1, arg2, fparg0);
        if (ret < 0.0f) {
            ret = -1.0f;
            if (self->m_unk29A30 >= 0) {
                if (modelIsAlive(&self->m_unk29890)) {
                    return self->m_unk29890.collideSphere(arg1, arg2, fparg0);
                }
                ret = -1.0f;
            }
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133658);
#endif

extern "C" float func_0013377C(MagScene *self, DogVector *arg1, DogVector *arg2)
{
    DogModelHit hit;
    hit.m_node = -1;
    float r = func_00133454(self, &hit, arg1, arg2, 0);
    if (0.0f <= r && r <= 1.0f) {
        return arg1->m_y + arg2->m_y * r;
    }
    return 100000.0f;
}

// NON_MATCHING: 4/104 differ, 4 edits
#ifdef NON_MATCHING
extern "C" float fabsf(float);
extern "C" float func_0013386C(MagScene *self, DogModelHit *theHit, const float *thePos, float theH, float theR)
{
#line 1683
    ASSERT(theH < 0.0f);
    float rr = theR * theR;
    float cy = thePos[1] + theH * 0.5f;
    float h = fabsf(theH);
    MagPrivateColli *p = self->m_private_colli;
    for (int i = 0; i < 256; i++, p++) {
        if (p->m_p1.m_y == p->m_p2.m_y) {
            continue;
        }
        if (fabsf((p->m_p1.m_y + p->m_p2.m_y) * 0.5f - cy) > (fabsf(p->m_p1.m_y - p->m_p2.m_y) + h) * 0.5f) {
            continue;
        }
        DogVector p1 = p->m_p1;
        p1.m_y = thePos[1];
        DogVector d = p->m_p2;
        float *pd = &d.m_x;
        pd[0] -= p->m_p1.m_x;
        pd[3] = 1.0f;
        pd[1] = 0.0f;
        pd[2] -= p->m_p1.m_z;
        float t;
        if (func_002337E0(thePos, &p1.m_x, pd, &t) <= rr) {
            if (theHit) {
                theHit->m_normal.m_x = -d.m_z;
                theHit->m_normal.m_y = 0.0f;
                theHit->m_normal.m_z = d.m_x;
                vecNormalize(&theHit->m_normal.m_x);
            }
            return 1.0f;
        }
    }
    return -1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013386C);
#endif

// NON_MATCHING: 19/93 differ, 19 edits
#ifdef NON_MATCHING
extern "C" float func_00234050(const DogVector *, const DogVector *, const DogVector *, const DogVector *, float *, float *);
void vecNormalize(float *v);
extern "C" float fabsf(float);
extern "C" float func_00133A0C(MagScene *self, DogModelHit *theHit, const DogVector &theP, const DogVector &theD)
{
#line 1740
    ASSERT(theD.m_y == 0.0f);
    MagPrivateColli *p = self->m_private_colli;
    for (int i = 0; i < 256; i++, p++) {
        if (p->m_p1.m_y == p->m_p2.m_y) {
            continue;
        }
        if (fabsf((p->m_p1.m_y + p->m_p2.m_y) * 0.5f - theP.m_y) > fabsf(p->m_p1.m_y - p->m_p2.m_y) * 0.5f) {
            continue;
        }
        MagPrivateColli col = *p;
        col.m_p1.m_y = theP.m_y;
        col.m_p2.m_x -= p->m_p1.m_x;
        col.m_p2.m_y = 0.0f;
        col.m_p2.m_z -= p->m_p1.m_z;
        col.m_p2.m_w = 1.0f;
        float t0, t1;
        if (func_00234050(&theP, &theD, &col.m_p1, &col.m_p2, &t0, &t1) == 0.0f) {
            if (theHit) {
                theHit->m_normal.m_x = -col.m_p2.m_z;
                theHit->m_normal.m_y = 0.0f;
                theHit->m_normal.m_z = col.m_p2.m_x;
                vecNormalize(&theHit->m_normal.m_x);
            }
            return t0;
        }
    }
    return -1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133A0C);
#endif

extern "C" float fabsf(float);
extern "C" float func_00133B80(MagScene *self, DogModelHit *theHit, const float *thePos, float theR)
{
#line 1794
    ASSERT(theR > 0.0f);
    MagPrivateColli *p = self->m_private_colli;
    for (int i = 0; i < 256; i++, p++) {
        if (p->m_p1.m_y == p->m_p2.m_y) {
            continue;
        }
        if (fabsf((p->m_p1.m_y + p->m_p2.m_y) * 0.5f - thePos[1]) > fabsf(p->m_p1.m_y - p->m_p2.m_y) * 0.5f) {
            continue;
        }
        DogVector p1 = p->m_p1;
        p1.m_y = thePos[1];
        DogVector d = p->m_p2;
        float *pd = &d.m_x;
        pd[0] -= p->m_p1.m_x;
        pd[3] = 1.0f;
        pd[1] = 0.0f;
        pd[2] -= p->m_p1.m_z;
        float t;
        if (sqrtf(func_002337E0(thePos, &p1.m_x, pd, &t)) <= theR) {
            if (theHit) {
                theHit->m_normal.m_x = -d.m_z;
                theHit->m_normal.m_y = 0.0f;
                theHit->m_normal.m_z = d.m_x;
                vecNormalize(&theHit->m_normal.m_x);
            }
            return 1.0f;
        }
    }
    return -1.0f;
}

// NON_MATCHING: 81/94 differ, 7 relocs differ (size 0x178, game 0x184), 27 edits
#ifdef NON_MATCHING
extern "C" float func_0013386C(MagScene *, DogModelHit *, const float *, float, float);
static inline bool isAliveModel(DogModel *m)
{
    if (m->m_i3r_root) {
        ((I3D_OK == I3rRoot__CheckIdString(m->m_i3r_root)) ? (void)0 : ror_assert(D_002ED570, 248, D_002ED580));
    }
    return m->m_i3r_root != 0;
}

static inline bool isAliveModel(const DogModel *m)
{
    if (m->m_i3r_root) {
        ((I3D_OK == I3rRoot__CheckIdString(m->m_i3r_root)) ? (void)0 : ror_assert(D_002ED570, 248, D_002ED580));
    }
    return m->m_i3r_root != 0;
}

extern "C" float func_00133D10(MagScene *self, const float *theFrom, const float *theTo, int theNo, DogModelHit *theHit, float theRadius)
{
    float ret = func_0013386C(self, theHit, theFrom, theTo[1], theRadius);
    if (ret >= 0.0f) {
        return ret;
    }
    if (theNo >= 0) {
        return self->getUnk29890(theNo)->m_model.collideWall(theFrom, theTo, theHit, theRadius);
    }
    MagUnk29890 *p = self->getUnk29890(0);
    for (int i = 0; i < 4; i++, p++) {
        if (p->m_unk1A0 >= 0) {
            const DogModel *m = &p->m_model;
            if (isAliveModel(m)) {
                ret = p->m_model.collideWall(theFrom, theTo, theHit, theRadius);
                if (ret >= 0.0f) {
                    return ret;
                }
            }
        }
    }
    return -1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133D10);
#endif

// NON_MATCHING: 4/26 differ, 4 edits
#ifdef NON_MATCHING
extern "C" int func_00133E94(MagScene *self, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    for (int i = 0; i < 0x2000; i++) {
        MagUnk437E0Sub &sub = self->m_unk437E0[i].m_sub;
        if (sub.m_unk0E == -1) {
            sub.m_unk04 = arg4;
            sub.m_unk08 = arg5;
            sub.m_unk0C = arg1;
            sub.m_unk00 = arg2;
            sub.m_unk0E = 0;
            self->m_unk437E0[i].m_unk00_i = arg3;
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133E94);
#endif

// NON_MATCHING: 4/27 differ, 4 edits
#ifdef NON_MATCHING
extern "C" int func_00133EFC(MagScene *self, int arg1, int arg2, int arg3, int arg4)
{
    for (int i = 0; i < 0x2000; i++) {
        MagUnk437E0Sub *sub = &(&self->m_unk437E0[0])[i].m_sub;
        if (sub->m_unk0E == -1) {
            sub->m_unk0E = 1;
            sub->m_unk0C = arg1;
            sub->m_unk00 = arg2;
            sub->m_unk04 = arg4;
            self->m_unk437E0[i].m_unk00_i = arg3;
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133EFC);
#endif

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00133F68);

INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134114);

extern "C" int func_001342BC(MagScene *self, int arg1, unsigned int arg2)
{
    for (int i = 0; i < 0x2000; i++) {
        if (self->m_unk437E0[i].m_sub.m_unk0E == -1) {
            self->m_unk437E0[i].m_sub.m_unk0E = 4;
            self->m_unk437E0[i].m_sub.m_unk00 = arg1;
            self->m_unk437E0[i].m_unk00 = (float)(arg2 & 0xFF) / 255.0f;
            self->m_unk437E0[i].m_unk04 = (float)((arg2 >> 8) & 0xFF) / 255.0f;
            self->m_unk437E0[i].m_unk08 = (float)((arg2 >> 16) & 0xFF) / 255.0f;
            self->m_unk437E0[i].m_unk0C = (float)((arg2 >> 24) & 0xFF) / 128.0f;
            return i;
        }
    }
    return -1;
}

// NON_MATCHING: 4/25 differ, 4 edits
#ifdef NON_MATCHING
extern "C" int func_00134460(MagScene *self, int arg1, float fparg0)
{
    for (int i = 0; i < 0x2000; i++) {
        MagUnk437E0Sub *sub = &self->m_unk437E0[i].m_sub;
        if (sub->m_unk0E == -1) {
            sub->m_unk0E = 5;
            sub->m_unk04 = arg1;
            self->m_unk437E0[i].m_unk00 = fparg0;
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134460);
#endif

extern "C" int func_001344C4(MagScene *self, int arg1, unsigned int arg2)
{
    self->m_unk437E0[arg1].m_unk00 = (float)(arg2 & 0xFF) / 255.0f;
    self->m_unk437E0[arg1].m_unk04 = (float)((arg2 >> 8) & 0xFF) / 255.0f;
    self->m_unk437E0[arg1].m_unk08 = (float)((arg2 >> 16) & 0xFF) / 255.0f;
    self->m_unk437E0[arg1].m_unk0C = (float)((arg2 >> 24) & 0xFF) / 128.0f;
    return 1;
}

extern "C" int func_00134624(MagScene *self, const MagUnk437E0 *arg1)
{
    for (int i = 0; i < 0x2000; i++) {
        if (self->m_unk437E0[i].m_sub.m_unk0E == -1) {
            self->m_unk437E0[i] = *arg1;
            return i;
        }
    }
    return -1;
}

// NON_MATCHING: 10/38 differ, 12 edits
#ifdef NON_MATCHING
extern "C" void func_00134698(MagScene *self, int arg1)
{
    if (arg1 < 0) {
        for (int i = 0; i < 0x2000; i++) {
            MagUnk437E0Sub *sub = &self->m_unk437E0[i].m_sub;
            sub->m_unk0E = sub->m_unk08 = -1;
            sub->m_unk0C = 0;
            sub->m_unk00 = 0;
            self->m_unk437E0[i].m_unk00_i = 0;
        }
    } else {
        MagUnk437E0Sub *sub = &self->m_unk437E0[arg1].m_sub;
        sub->m_unk0E = sub->m_unk08 = -1;
        sub->m_unk0C = 0;
        sub->m_unk00 = 0;
        self->m_unk437E0[arg1].m_unk00_i = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134698);
#endif

extern "C" int func_00134730(MagScene *self, int theW, int theH, int theA, int theFlag)
{
    int n;
    for (n = 0; n < 4; n++) {
        if (!self->m_window[n]) {
            break;
        }
    }
    if (n >= 4) {
        return -1;
    }
    self->m_window[n] = new MagLifeWindow;
#line 2110
    ASSERT_S(self->m_window[n], "m_window[ n ]");
    self->m_window[n]->func_0012FE30(theW, theH);
    func_001BEBEC(&self->m_unk02744[n], self->m_unk02908);
    self->m_window[n]->func_00130778((MagFntMan *)&self->m_unk02744[n]);
    self->m_window[n]->m_font_tex = self->m_unk028F4[n];
    self->m_window[n]->m_unk80 = theFlag;
    if (theFlag > 0) {
        BedSubMode *sub = &self->m_sub_mode;
        ((int *)sub)[0] = 2;
        ((int *)sub)[1] = -1;
    }
    self->m_life_man.add(self->m_window[n], 0x800C);
    return n;
}


extern "C" void func_001348B0(MagScene *self, int winNo)
{
#line 2137
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        self->m_life_man.remove(self->m_window[winNo]);
        delete self->m_window[winNo];
        self->m_window[winNo] = 0;
    }
}


// NON_MATCHING: the float registers come out in another order.
#ifdef NON_MATCHING
void MagScene::func_00134944(int theN, int *theParam)
{
#line 2156
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    if (m_window[theN]) {
        DogVector pos((float)theParam[0], (float)theParam[1], (float)theParam[2], 1.0f);
        m_window[theN]->m_pos = pos;
        m_window[theN]->m_h = theParam[4];
        m_window[theN]->m_w = theParam[3];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00134944__8MagSceneiPi);
#endif


extern "C" void func_00134A00(MagScene *self, int winNo, int theX, int theY, int theZ)
{
#line 2179
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    MagLifeWindow *w = self->m_window[winNo];
    if (w) {
        register float x PS2_REG("$f3") = (float)theX;
        register float y PS2_REG("$f1") = (float)theY;
        register float z PS2_REG("$f2") = (float)theZ;
        register float weight PS2_REG("$f0") = 1.0f;
        float pos[4] __attribute__((aligned(16)));
        pos[3] = weight;
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        *(u_long128 *)&w->m_pos = *(u_long128 *)pos;
    }
}


extern "C" void func_00134AB8(MagScene *self, int winNo, int theW, int theH)
{
#line 2194
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    MagLifeWindow *w = self->m_window[winNo];
    if (w) {
        w->m_w = theW;
        w->m_h = theH;
    }
}


extern "C" void func_00134B34(MagScene *self, int winNo, int a, int b)
{
#line 2205
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_00130214(self->m_window[winNo], a, b);
    }
}


extern "C" void func_00134BB8(MagScene *self, int winNo, int a, int b, int c)
{
#line 2215
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_00130230(self->m_window[winNo], a, b, c);
    }
}


extern "C" void func_00134C4C(MagScene *self, int theN, int *theW, int *theH)
{
#line 2225
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    MagLifeWindow *w = self->m_window[theN];
    if (w) {
        *theW = w->m_w;
        *theH = w->m_h;
    }
}


extern "C" void func_00134CD0(MagScene *self, int theN, int theX, int theY, int theW, int theH)
{
#line 2242
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    MagLifeWindow *w = self->m_window[theN];
    if (w) {
        w->m_unk84 = theX;
        w->m_unk88 = theY;
        w->m_unk8C = theW;
        w->m_unk90 = theH;
    }
}


extern "C" void func_00134D6C(MagScene *self, int theN, int *theX, int *theY, int *theW, int *theH)
{
#line 2252
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    MagLifeWindow *w = self->m_window[theN];
    if (w) {
        *theX = w->m_unk84;
        *theY = w->m_unk88;
        *theW = w->m_unk8C;
        *theH = w->m_unk90;
    }
}


extern "C" void func_00134E18(MagScene *self, int theN, int *theOut)
{
#line 2262
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    MagLifeWindow *w = self->m_window[theN];
    if (w) {
        *theOut = w->m_ch_h;
    }
}


extern "C" void func_00134E88(MagScene *self, int winNo, int a, int b, int c, int d)
{
#line 2272
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_0012FCA8(self->m_window[winNo], a, b, c, d);
    }
}


extern "C" void func_00134F2C(MagScene *self, int winNo, int a)
{
#line 2282
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_0012FD30(self->m_window[winNo], a);
    }
}


extern "C" void func_00134FA0(MagScene *self, int winNo, int a)
{
#line 2292
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_0012FD88(self->m_window[winNo], a);
    }
}


extern "C" void func_00135014(MagScene *self, int winNo, int a)
{
#line 2302
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_0012FDDC(self->m_window[winNo], a);
    }
}


extern "C" void func_00135088(MagScene *self, int theN, int a, int b, int c)
{
#line 2318
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    if (self->m_window[theN]) {
        func_0012FE68(self->m_window[theN], a, b, c);
    }
}


extern "C" void func_0013511C(MagScene *self, int theN, int a, int b, int c)
{
#line 2333
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    if (self->m_window[theN]) {
        func_0012FEF8(self->m_window[theN], a, b, c);
    }
}


extern "C" void func_001351B0(MagScene *self, int winNo, int theHide)
{
#line 2349
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        self->m_window[winNo]->setHide(theHide != 0);
    }
}


INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED680);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene", D_002ED6A8);

void MagScene::func_00135234(int winNo, int theB, int theC, int str, int theE)
{
#line 2369
    ASSERT(str != __null);
#line 2371
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (m_window[winNo]) {
        func_00130258(m_window[winNo], theB, theC, (const char *)str, theE);
        tag_I3dTexInfo_s *pti = m_tex_info.getTexInfo(m_unk028F4[winNo]);
#line 2381
        ASSERT(pti);
        ASSERT(pti->pPicture);
        updatePicture(pti->pPicture);
    }
}

extern "C" void func_00135364(MagScene *self, int winNo, int theA, int theB)
{
#line 2395
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    if (self->m_window[winNo]) {
        func_001305EC(self->m_window[winNo], theA, theB);
        tag_I3dTexInfo_s *tab = ((DogTexInfo *)((char *)self + 0x29520))->m_tex_info;
    updatePicture(tab[self->m_unk028F4[winNo]].pPicture);
    }
}


extern "C" void func_00135418(MagScene *self, int winNo, int theA)
{
#line 2409
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    func_001BFF28(&self->m_unk02744[winNo], theA);
}


extern "C" void func_00135494(MagScene *self, int winNo, int theA)
{
#line 2417
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    func_001BFF5C(&self->m_unk02744[winNo], theA);
    func_00135418(self, winNo, 0);
}


extern "C" void func_00135520(MagScene *self, int theN, int theA)
{
    func_001BFF64(&self->m_unk02744[theN], theA);
}


extern "C" void func_0013555C(MagScene *self, int theN, int theA)
{
    return func_001C047C(&self->m_unk02744[theN], theA);
}


extern "C" void func_00135594(MagScene *self, int winNo)
{
#line 2452
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    func_001BEEB4(&self->m_unk02744[winNo]);
    tag_I3dTexInfo_s *tab = ((DogTexInfo *)((char *)self + 0x29520))->m_tex_info;
    updatePicture(tab[self->m_unk028F4[winNo]].pPicture);
}


extern "C" void func_00135628(MagScene *self, int winNo)
{
#line 2469
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    tag_I3dTexInfo_s *tab = ((DogTexInfo *)((char *)self + 0x29520))->m_tex_info;
    updatePicture(tab[self->m_unk028F4[winNo]].pPicture);
}


extern "C" void func_0013569C(MagScene *self, int theN, int theA)
{
#line 2478
    ASSERT_S(theN >= 0 && theN < MAX_WINDOW, D_002ED6A8);
    func_001BFE30(&self->m_unk02744[theN], theA);
    tag_I3dTexInfo_s *tab = ((DogTexInfo *)((char *)self + 0x29520))->m_tex_info;
    updatePicture(tab[self->m_unk028F4[theN]].pPicture);
}


extern "C" void func_00135740(MagScene *self, int winNo)
{
#line 2489
    ASSERT_S(winNo >= 0 && winNo < MAX_WINDOW, D_002ED680);
    func_001BEBEC(&self->m_unk02744[winNo], self->m_unk02908);
}


extern "C" void X_func_0013F07C_57B0(MagScene *) asm("func_0013F07C");
extern "C" void func_001357B0(MagScene *self, int theA, int theB)
{
    BedSubMode *sub = &self->m_sub_mode;
    ((int *)sub)[0] = 3;
    register int next PS2_REG("$3") = -1;
    ((int *)sub)[1] = next;
    *(int *)((char *)self + 0x2BE54) = theB;
    *(int *)((char *)self + 0x22D8) = theA;
    *(int *)((char *)self + 0x22DC) = *(unsigned short *)((char *)self + 0x853B8) | (*(unsigned short *)((char *)self + 0x22AC) << 16);
    X_func_0013F07C_57B0(self);
}


INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_0013580C);

extern "C" int func_00135B64(MagScene *self)
{
    return *(int *)((char *)self + 0x2BE58) == 0;
}


extern "C" void func_00135B78(MagScene *self)
{
    if (self->m_unk2BE5C) {
        int kind = self->m_unk2BE50;
        if (kind != 0x10000) {
            self->m_unk2BE5C->vfunc10();
        }
        self->m_life_man.remove(self->m_unk2BE5C);
        if (self->m_unk2BE50 >= 0x1000B && self->m_unk2BE50 <= 0x1000F) {
            delete self->m_unk2BE5C;
        }
        self->m_unk2BE5C = 0;
        self->m_unk2BE50 = -1;
        self->func_0013F09C();
        BedSubMode *sub = &self->m_sub_mode;
        ((int *)sub)[1] = -1;
        ((int *)sub)[0] = 4;
        if (kind == 0x10010) {
            self->func_0013F1E4();
            func_001357B0(self, 0x10005, 0);
        }
    }
}

extern "C" void func_00135CAC(MagScene *self, const char *theTexName)
{
#line 2711
    ASSERT(theTexName);
    MagLife *fader = (MagLife *)((char *)self + 0x41890);
    func_0012F518(fader, (char *)self + 0x29520, theTexName);
    MagLifeManager *man = &self->m_life_man;
    func_0012F7F4(fader, 5, 0);
    if (man->indexOf(fader) < 0) {
        man->add(fader, 0x8003);
    }
}


extern "C" void func_00135D58(MagScene *self, float theMagnify, int theA)
{
#line 2725
    ASSERT(theMagnify > 0.0f);
    func_0012FC80((char *)self + 0x41890, theMagnify, theA);
}


extern "C" void func_00135DCC(MagScene *self)
{
    MagLife *fader = (MagLife *)((char *)self + 0x41890);
    self->m_life_man.remove(fader);
    func_0012F790(fader, (char *)self + 0x29520);
}


extern "C" int func_00135E20(MagPrivateColli *theColli, const float *theP1, const float *theP2)
{
#line 2740
    ASSERT(theP1);
    ASSERT(theP2);
    ASSERT(theP1[1] != theP2[1]);
    MagPrivateColli *p = theColli;
    for (int i = 0; i < 256; i++, p++) {
        if (p->m_p1.m_y == p->m_p2.m_y) {
            p->m_p1.m_x = theP1[0];
            p->m_p1.m_y = theP1[1];
            p->m_p1.m_z = theP1[2];
            p->m_p1.m_w = 0.0f;
            p->m_p2.m_x = theP2[0];
            p->m_p2.m_y = theP2[1];
            p->m_p2.m_z = theP2[2];
            p->m_p2.m_w = 0.0f;
            return i;
        }
    }
#line 2764
    ASSERT_S(0, D_002ED4B8);
    return -1;
}

// NON_MATCHING: function matches (0x60/0x60), blocked on .rodata (D_002ED788 bundles 0x50 bytes of trailing maglifebwnctrl.h / 9DogEntity strings)
#ifdef NON_MATCHING
#define MAX_PRIVATE_COLLI 256
extern "C" void func_00135F44(MagPrivateColli *theColli, int theID)
{
#line 2773
    ASSERT(theID >= 0 && theID < MAX_PRIVATE_COLLI);
    MagPrivateColli *p = &theColli[theID];
    p->m_p1.m_y = p->m_p2.m_y = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magscene", func_00135F44);
#endif
