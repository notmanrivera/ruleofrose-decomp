#include "include_asm.h"
#include "task/cmnitask.h"

struct TskEnemyTurnParam {
    int m_oid;                          // +0x00
    int m_targetOid;                    // +0x04
    int *m_donePtr;                     // +0x08
    int m_sndType;                      // +0x0C
    float m_speed;                      // +0x10
    float m_stopAngle;                  // +0x14
};

struct TskEnemyTurnObj {
    unsigned char m_pad00[0x108];
    int m_chrID;                        // +0x108
};

struct TskEnemyTurnActor {
    unsigned char m_pad00[0x1E8];
    float m_mtnSpeed;                   // +0x1E8
    unsigned char m_pad1EC[0x4D0 - 0x1EC];
}; // size 0x4D0

class TskEnemyTurn : public CmnITask {
public:
    int m_active;                       // +0x04
    int m_oid;                          // +0x08
    int m_chrID;                        // +0x0C
    TskEnemyTurnActor *m_actor;         // +0x10
    int *m_donePtr;                     // +0x14
    int m_targetOid;                    // +0x18
    float m_mtnSpeed;                   // +0x1C
    int m_curMtn;                       // +0x20
    int m_turnDir;                      // +0x24
    float m_stopAngle;                  // +0x28
    float m_targetPos[3];               // +0x2C..+0x37
    int m_unk38;                        // +0x38
    int m_sndHandle;                    // +0x3C
    int m_sndTimer;                     // +0x40
    int m_sndType;                      // +0x44
    int m_paused;                       // +0x48

    virtual int get_task_type() { return 0x15; }
    virtual void pause(bool);
    virtual void init();
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskEnemyTurn();
};

extern "C" char vtbl_12TskEnemyTurn[] asm("_vt$12TskEnemyTurn");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" float X_func_0010A650__8DogActor(void *) asm("func_0010A650__8DogActor");
extern "C" int X_func_0010A834__8DogActor(void *) asm("func_0010A834__8DogActor");
extern "C" void X_func_0010B1B0__8DogActoriifii(void *, int, int, float, int, int) asm("func_0010B1B0__8DogActoriifii");
extern "C" void X_func_0016A594(int, float *) asm("func_0016A594");
extern "C" void X_func_00180EA8(void *, int) asm("func_00180EA8");
extern "C" int X_func_001D046C(void *, int) asm("func_001D046C");
extern "C" TskEnemyTurnObj *X_func_001D2B8C(void *, int) asm("func_001D2B8C");
extern "C" void X_func_00203684(TskEnemyTurn *, float *) asm("func_00203684");
extern "C" void X_func_00203828(TskEnemyTurn *, float *) asm("func_00203828");
extern "C" void X_func_00203A28(TskEnemyTurn *, float *) asm("func_00203A28");
extern "C" void X_func_00203B44(TskEnemyTurn *, int, float *) asm("func_00203B44");
extern "C" float X_atan2f(float, float) asm("func_0026CB00");
struct TskEnemyTurnScene {
    unsigned char m_pad00[0x2920];
    TskEnemyTurnActor m_actors[1];      // +0x2920
};

extern TskEnemyTurnActor D_006FE6A0[];
extern TskEnemyTurnScene D_006FBD80;
extern int D_007812C0;
extern int D_007B2580;

extern "C" void TskEnemyTurn__vfunc_05(TskEnemyTurn *self)
{
    int h = self->m_sndHandle;
    if (h >= 0) {
        X_func_00180EA8(&D_007B2580, h);
    }
}

extern "C" void TskEnemyTurn__vfunc_03(TskEnemyTurn *self)
{
    int h = self->m_sndHandle;
    if (h >= 0) {
        X_func_00180EA8(&D_007B2580, h);
    }
}

extern "C" void func_002034C0(TskEnemyTurn *self)
{
    self->m_actor = 0;
    self->m_active = 0;
    *(void **)self = vtbl_12TskEnemyTurn;
}

extern "C" void TskEnemyTurn__vfunc_06(TskEnemyTurn *self, int arg1)
{
    *(void **)self = vtbl_12TskEnemyTurn;
    if (arg1 & 1) {
        return X___builtin_delete(self);
    }
}

extern "C" void func_0020350C(TskEnemyTurn *self, TskEnemyTurnParam *arg1)
{
    self->m_active = 1;
    int oid = arg1->m_oid;
    self->m_oid = oid;
    int chrId = X_func_001D2B8C(&D_007812C0, oid)->m_chrID;
    self->m_chrID = chrId;
    self->m_actor = &D_006FE6A0[chrId];
    int *done = arg1->m_donePtr;
    self->m_donePtr = done;
    *done = 0;
    self->m_targetOid = arg1->m_targetOid;
    self->m_mtnSpeed = arg1->m_speed * 0.016666694078594446f;
    self->m_turnDir = 1;
    self->m_curMtn = 0;
    self->m_stopAngle = arg1->m_stopAngle;
    self->m_sndTimer = X_func_0010423C(0xF, 0x1E);
    self->m_sndHandle = -1;
    self->m_sndType = arg1->m_sndType;
}

extern "C" int TskEnemyTurn__vfunc_04(TskEnemyTurn *self)
{
    float pos[4];

    if (self->m_paused != 0) {
        return 0;
    }
    if (self->m_active == 0) {
        return 0;
    }
    if (X_func_001D046C(&D_007812C0, self->m_targetOid) == 0) {
        *self->m_donePtr = 2;
        self->m_targetPos[0] = self->m_targetPos[1] = self->m_targetPos[2] = 0.0f;
    } else {
        X_func_0016A594(self->m_oid, pos);
        X_func_00203B44(self, self->m_targetOid, self->m_targetPos);
        X_func_00203828(self, pos);
        X_func_00203684(self, pos);
        X_func_00203A28(self, pos);
    }
    return 0;
}

static inline TskEnemyTurnActor *getTurnActor(void *base, int idx)
{
    return (TskEnemyTurnActor *)(((char *)base + idx * 0x4D0) + 0x2920);
}

static inline float absF(float v)
{
    return (v < 0.0f) ? -v : v;
}

static inline float angleSub(const float &a, const float &b)
{
    return a - b;
}

extern "C" void func_00203684(TskEnemyTurn *self, float *pos)
{
    volatile float yaw0;
    volatile float yaw1;
    volatile float *p1 = &yaw1;
    float diff;

    yaw0 = X_atan2f(self->m_targetPos[0] - pos[0], self->m_targetPos[2] - pos[2]);
    *p1 = X_func_0010A650__8DogActor(self->m_actor);
    diff = yaw0 - yaw1;
    if (diff < -3.14159265358979323846) {
        diff = diff + 6.28318530717958647692;
    }
    if (diff > 3.14159265358979323846) {
        diff = diff - 6.28318530717958647692;
    }
    if (diff > 0.0f) {
        if (self->m_turnDir != 0) {
            X_func_00203828(self, pos);
        }
    } else {
        if (self->m_turnDir == 0) {
            X_func_00203828(self, pos);
        }
    }
    if (X_func_0010A834__8DogActor(getTurnActor(&D_006FBD80, self->m_chrID)) == 0) {
        X_func_00203828(self, pos);
    }
    if (absF(diff) < self->m_stopAngle) {
        *self->m_donePtr = 1;
    }
}

extern "C" void func_00203828(TskEnemyTurn *self, float *pos)
{
    volatile float yaw1;
    volatile float yaw0;
    volatile float *p0 = &yaw0;
    float diff;
    int mtn;

    *p0 = X_atan2f(self->m_targetPos[0] - pos[0], self->m_targetPos[2] - pos[2]);
    yaw1 = X_func_0010A650__8DogActor(self->m_actor);
    diff = yaw0 - yaw1;
    if (diff < -3.14159265358979323846) {
        diff = diff + 6.28318530717958647692;
    }
    if (diff > 3.14159265358979323846) {
        diff = diff - 6.28318530717958647692;
    }
    if (diff > 0.0f) {
        self->m_turnDir = 0;
        mtn = 9;
    } else {
        mtn = 8;
        self->m_turnDir = 1;
    }
    if (self->m_curMtn != mtn) {
        X_func_0010B1B0__8DogActoriifii(self->m_actor, mtn, 1, self->m_mtnSpeed, -1, -1);
        self->m_curMtn = mtn;
    }
}

extern "C" void TskEnemyTurn__vfunc_02(TskEnemyTurn *self, int arg1)
{
    if (self->m_active != 0) {
        TskEnemyTurnActor *actor = self->m_actor;
        if (arg1 != 0) {
            if (actor != 0) {
                actor->m_mtnSpeed = 9.999999583953922e-08f;
            }
        } else if (actor != 0) {
            actor->m_mtnSpeed = self->m_mtnSpeed;
        }
    }
}
