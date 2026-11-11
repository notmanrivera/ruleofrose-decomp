#include "ror.h"
#include "include_asm.h"
#include "mag/maglife.h"
#include "sdk/string.h"

#undef ASSERT_FILE
#define ASSERT_FILE D_002E9598

extern const char D_002E9598[];     // "mag/maglife.cpp"
extern const char D_002E95E8[];     // "m_actor"
extern const char D_002E95F0[];     // "theState >= 0"

extern "C" void func_0017C340(float, float, void *, DogVector *, void *, int);
extern "C" float func_0017DD5C(float, void *, int, DogVector *);
extern "C" float func_00133454(MagScene *, DogModelHit *, DogVector *,
                               DogVector *, int);
extern "C" void func_001026B0(int, int, DogVector *);
void vecDirToRot(float *, float *);
void vecNormalize(float *);
extern "C" void func_0025B890(DogVector *, DogVector *, DogVector *);
extern "C" char vtbl_MagLifeControlChara[] asm("_vt$19MagLifeControlChara");

extern "C" void func_0011A320(MagLifeControlChara *, int, int);
extern "C" int func_0011A4EC(MagLifeControlChara *, const char *, int, float,
                              int, int);
extern "C" void func_0011A704(MagLifeControlChara *, int);

extern "C" int func_0010A834_3(DogActor *, MagLifeMotionState *, DogActor *)
    asm("func_0010A834__8DogActor");
extern "C" void func_0011A03C_2(MagLifeControlChara *, int) asm("func_0011A03C");
extern "C" void func_0011A704_3(MagLifeControlChara *, int, DogActor *)
    asm("func_0011A704");
void vecTurnY(float *, float);
static inline void scaleXYZ(DogVector *p, float d) { p->m_x *= d; p->m_y *= d; p->m_z *= d; p->m_w = 1.0f; }

static inline void initRot(DogVector *p, float theRot)
{
    p->m_x = 0.0f;
    p->m_y = 0.0f;
    p->m_z = theRot;
    p->m_w = 1.0f;
}

extern "C" void func_00119B34(MagLifeControlChara *self)
{
    self->m_sctFlag = -1;
    memset(self->m_sctPos, 0, 0x10);
}

extern "C" int func_00119B60(MagLifeControlChara *self, DogVector *theOut,
                             float theRot)
{
    DogVector *out = theOut;
    if (!self->m_actor)
        return -1;

    DogVector v = *(DogVector *)((char *)self->m_actor + 0x40);
    if (theRot != 0.0f) {
        DogVector rot(0.0f, 0.0f, theRot, 1.0f);
        DogVector *rp = &rot;
        vecTurnY((float *)rp, self->m_actor->m_unk50.m_y);
        v.m_x += rp->m_x;
        v.m_y += rp->m_y;
        v.m_z += rp->m_z;
        v.m_w = 1.0f;
        if (out)
            *out = v;
    }

    int sct[4];
    memset(sct, 0, sizeof(sct));
    sct[0] = self->m_sctPos[0];
    func_0017C340(180.0f, 0.0f, (char *)self->m_scene + 0x8542C, &v, sct,
                  sct[0] != 0);

    if (sct[0]) {
        int *sector = (int *)sct[0];
        if (sector[2] & 0x20000) {
            float h = func_0017DD5C(0.0f,
                                    (char *)self->m_scene + 0x85434,
                                    sector[0], &v);
            float diff = h - v.m_y;
            if (diff > 10.0f)
                return 3;
            if (diff < -10.0f)
                return 2;
            return 0;
        } else {
            return 0;
        }
    } else {
        return -1;
    }
}

extern "C" int func_00119CEC(MagLifeControlChara *self, DogVector *theOut,
                             float theRot)
{
    DogVector *out = theOut;
    if (!self->m_actor)
        return -1;

    DogVector v = *(DogVector *)((char *)self->m_actor + 0x40);
    if (theRot != 0.0f) {
        DogVector rot(0.0f, 0.0f, theRot, 1.0f);
        DogVector *rp = &rot;
        vecTurnY((float *)rp, self->m_actor->m_unk50.m_y);
        v.m_x += rp->m_x;
        v.m_y += rp->m_y;
        v.m_z += rp->m_z;
        v.m_w = 1.0f;
        if (out)
            *out = v;
    }

    int sct[4];
    memset(sct, 0, sizeof(sct));
    sct[0] = self->m_sctPos[0];
    func_0017C340(40.0f, 0.0f, (char *)self->m_scene + 0x8542C, &v, sct,
                  sct[0] != 0);

    int ret = -1;
    if (sct[0]) {
        int *sector = (int *)sct[0];
        ret = 2;
        if (!(sector[2] & 0x20000))
            ret = 0;
    }
    return ret;
}

extern "C" float func_00119E1C(MagLifeControlChara *self)
{
    DogVector v = self->m_actor->m_unk40;
    v.m_y -= 60.0f;
    DogVector a(0.0f, 120.0f, 0.0f, 1.0f);
    DogModelHit hit;
    hit.m_node = -1;

    float r = func_00133454(self->m_scene, &hit, &v, &a, -1);
    float ret = 0.0f;
    if (0.0f <= r && r <= 1.0f)
        ret = (r - 0.5f) * 60.0f;
    if (ret < -7.0f)
        ret = -7.0f;
    else if (ret > 7.0f)
        ret = 7.0f;
    if (ret != 0.0f) {
        DogActor *actor = self->m_actor;
        actor->m_unk90 = 1;
        actor->m_unk40.m_y += ret;
    }
    return ret;
}

extern "C" void func_00119F88(MagLifeControlChara *self, DogVector *theOut)
{
    if (self->m_actor)
        *theOut = *(DogVector *)((char *)self->m_actor + 0x40);
}

extern "C" DogVector *func_00119FA4(MagLifeControlChara *self)
{
    return (DogVector *)((char *)self->m_actor + 0x40);
}

extern "C" float func_00119FB0(MagLifeControlChara *self)
{
    if (self->m_actor)
        return self->m_actor->func_0010A650();
    return 0.0f;
}

extern "C" void MagLifeControlChara__vfunc_09(MagLifeControlChara *self, int theA, int theB)
{
    if (self->m_unk00) {
        *(long long *)&self->m_last0 = *(long long *)&self->m_unk00;
        *(long long *)&self->m_last2 = *(long long *)&self->m_unk08;
    }
    self->m_unk08 = theB;
    self->m_unk00 = theA;
    self->m_unk04 = -1;
}

extern "C" void func_0011A010(MagLifeControlChara *self, int theState)
{
    int *state = &self->m_state;

    state[0] = theState;
    state[1] = 0;
    self->m_unk4C = 0;
    self->m_mode = 0;
}

extern "C" int func_0011A028(MagLifeControlChara *self)
{
    return self->m_state;
}

extern "C" void func_0011A030(MagLifeControlChara *self)
{
    self->m_mode = 1;
}

extern "C" void func_0011A03C(MagLifeControlChara *self)
{
    self->m_mode = 2;
}

extern "C" int func_0011A048(MagLifeControlChara *self)
{
    return self->m_mode > 0;
}

extern "C" int func_0011A054(MagLifeControlChara *self)
{
    return self->m_mode >= 2;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglife", D_002E9598);











































































































int MagLifeControlChara::func_0011A064()
{
    register MagLifeControlChara *p asm("$19") = this;
    register int cnt asm("$18") = 0;
    int st = func_0011A028();
    for (;;) {
        if (p->m_tbl_motion_state[st].m_count < 0)
            return 1;
        ASSERT_S(p->m_tbl_motion_state[st].m_next_state != st, "m_tbl_motion_state[st].m_next_state != st");
        st = p->m_tbl_motion_state[st].m_next_state;
        if (st < 0)
            return 0;
        cnt++;


        ASSERT(cnt < 10);
    }
}

extern "C" void func_0011A130(MagLifeControlChara *self)
{
    int *state = &self->m_state;

    state[1] = -1;
    state[0] = -1;
}

extern "C" void func_0011A144(MagLifeControlChara *self, MagLifeMotionState *theTable)
{
    self->m_tbl_motion_state = theTable;
}
// NON_MATCHING: two `lui`s come out swapped in the delay slot of the first
// branch (delay-slot filling sees $a0 as live at the branch target); see
// func_0011A320 below, whose only difference has the same cause.

#ifdef NON_MATCHING
void MagLifeControlChara::func_0011A14C()
{

        ASSERT_S(m_actor, D_002E95E8);

    if (func_0011A054() == 0 && func_0011A048() != 0) {
        int theState = func_0011A028();

        if (m_tbl_motion_state[theState].m_count > 0) {
            if (m_actor->func_0010A834() == 0) {
                int *stateGroup = &m_state;
                stateGroup[1]++;
                if (stateGroup[1] >= m_tbl_motion_state[theState].m_count) {
                    int next = m_tbl_motion_state[theState].m_next_state;
                    if (next >= 0)
                        func_0011A320(next, -1);
                    else
                        func_0011A03C();
                }
            }
        } else if (m_actor->m_motion_loop_trig != 0) {
            if (m_tbl_motion_state[theState].m_sound > 0)
                func_0011A704(m_tbl_motion_state[theState].m_sound);
            int *stateGroup = &m_state;
            stateGroup[1]++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglife", func_0011A14C);
#endif






















extern "C" void func_0011A27C(MagLifeControlChara *self, int theState, int theArg)
{
    ASSERT_S(theState >= 0, D_002E95F0);

    int next = self->m_tbl_motion_state[theState].m_next_state;
    if (next >= 0)
        func_0011A320(self, next, theArg);
    else
        func_0011A320(self, theState, theArg);
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglife", D_002E95E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglife", D_002E95F0);

// NON_MATCHING: the game has `bnez` where this has `bnel` (same cause).
#ifdef NON_MATCHING
void MagLifeControlChara::func_0011A320(int theState, int theArg)
{
    ASSERT_S(theState >= 0, D_002E95F0);
    if (func_0011A054() == 0 && func_0011A028() == theState)
        return;

    func_0011A010(theState);
    if (theState <= 0)
        return;
    ASSERT(m_tbl_motion_state[theState].m_state_id == theState);

    float speed = 0.016666694f;
    int flags = m_tbl_motion_state[theState].m_count < 1;
    if (m_tbl_motion_state[theState].m_flag & 1)
        flags |= 0x40;
    if (m_tbl_motion_state[theState].m_speed != 0)
        speed = (float)m_tbl_motion_state[theState].m_speed *
                0.016666694f / 100.0f;

    int next;
    if (theArg < 0) {
        next = m_tbl_motion_state[theState].m_unk08;











        ASSERT_S(m_actor, D_002E95E8);
        if (next == 0) {
            if (m_actor->func_0010DB38() != 0)
                next = 5;
        }
    } else {
        next = theArg;
    }

    func_0011A4EC(m_tbl_motion_state[theState].m_motion, flags, speed, 0,
                  next);
    if (m_tbl_motion_state[theState].m_sound > 0)
        func_0011A704(m_tbl_motion_state[theState].m_sound);
    func_0011A030();
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglife", func_0011A320);
#endif

int MagLifeControlChara::func_0011A4EC(const char *theMotion, int theFlag,
                                        float theSpeed, int theInterp,
                                        int theNext)
{














    ASSERT(theMotion);
    ASSERT_S(m_actor, D_002E95E8);
    if (!m_actor)
        return -1;
    if (!theMotion)
        return -1;

    int motion = m_actor->func_0010AA5C(theMotion);
    if (motion < 0)
        motion = m_actor->func_0010AB40(theMotion);
    if (motion < 0)
        return motion;

    int next = -1;
    if (theInterp) {
        next = m_actor->func_0010AA5C((const char *)theInterp);
        if (next < 0)
            next = m_actor->func_0010AB40((const char *)theInterp);
    }

    int next2 = theNext;
    if (m_zeroLink) {
        m_zeroLink = 0;
        next2 = 0;
    }

    return m_actor->func_0010B1B0(motion, theFlag, theSpeed, next, next2);
}
































extern "C" int *func_0011A64C(MagLifeControlChara *self)
{
    if (self->m_sctPos[0] == 0) {
        DogVector v = *(DogVector *)((char *)self->m_actor + 0x40);
        func_0017C340(40.0f, 0.0f, (char *)self->m_scene + 0x8542C,
                      &v, self->m_sctPos, 0);
    }
    return self->m_sctPos;
}

extern "C" void func_0011A6B0(MagLifeControlChara *self)
{
    DogVector v = *(DogVector *)((char *)self->m_actor + 0x40);
    func_0017C340(40.0f, 0.0f, (char *)self->m_scene + 0x8542C,
                  &v, self->m_sctPos, self->m_sctPos[0] != 0);
}

extern "C" void func_0011A704(MagLifeControlChara *self, int theSound)
{
    if (self->m_actor) {
        DogVector v = *(DogVector *)((char *)self->m_actor + 0x40);
        func_001026B0(theSound, 0, &v);
    }
}

void MagLifeControlChara::func_0011A738(int *theSounds)
{
    if (!m_actor)
        return;

    float f = m_actor->func_0010DA4C();
    if (!(f >= 0.0f))
        return;
    if ((m_actor->func_0010BCC8(-1, f, f + 1.0f) & 1) == 0)
        return;

    int sndid = -1;
    int *p = func_0011A64C();
    if (p && *p) {
        register int idx asm("$4") = *(int *)(*p + 4);
        char *sct = (char *)m_scene + 0x85434;
        int *q = 0;
        if (*(int *)(sct + 4) && *(int *)(sct + 8)) {
            register int off asm("$2") = idx << 7;
            q = (int *)(*(int *)(sct + 8) + off);
        }
        if (q)
            sndid = q[18];
    }
    if (sndid < 0) {
        sndid = *(int *)((char *)m_scene + 0x854A4);
        if (sndid < 0)
            return;
    }
    ASSERT(sndid < 12);
    int sound = theSounds[sndid] + ((m_unk04 / 13) & 1);
    if (sound < 0)
        return;
    func_0011A704(sound);
}

void MagLifeControlChara::func_0011A888()
{
    volatile u_long128 *state = (volatile u_long128 *)&m_state;
    m_unk10 = 1;
    *(u_long128 *)&m_unk00 = 0;
    *(void **)((char *)this + 0x14) = vtbl_MagLifeControlChara;
    *(u_long128 *)&m_last0 = 0;
    m_unk04 = -1;
    m_unk00 = 0;
    m_unk24 = 0;
    m_scene = 0;
    *state = 0;
    m_sctPos[0] = 0;
    m_unk54 = 0;
    m_actor = 0;
    m_unk74 = 0;
    m_zeroLink = 0;
    m_unk50 = -1;
    return func_0011A130();
}









void MagLifeBillboard::liveBillboard()
{
    m_unk04++;
    ASSERT(m_scene);

    MagScene *scene = m_scene;
    DogVector axis;
    ((DogEntity *)((char *)scene + 0x2AB70))->getAxisZ(&axis);

    DogVector rot;
    vecDirToRot(&axis.m_x, &rot.m_x);
    rot.m_x = -rot.m_x;
    if (rot.m_x >= DOG_PI)
        rot.m_x -= DOG_PI2;
    if (rot.m_x < -DOG_PI)
        rot.m_x += DOG_PI2;
    rot.m_y += DOG_PI;
    if (rot.m_y >= DOG_PI)
        rot.m_y -= DOG_PI2;
    if (rot.m_y < -DOG_PI)
        rot.m_y += DOG_PI2;

    DogActor *actor = m_actor;
    actor->m_unk50 = rot;
    actor->normalizeRot();
    actor->m_unk90 = 1;

    DogVector a;
    m_actor->func_00114D8C((u_long128 *)&a);
    DogVector b;
    b = *(DogVector *)((char *)scene + 0x2ABB0);
    DogVector c;
    func_0025B890(&c, &b, &a);
    vecNormalize(&c.m_x);
    scaleXYZ(&c, m_distance);
    DogActor *q = m_actor;
    q->m_unk40 = c;
    q->m_unk90 = 1;
}
