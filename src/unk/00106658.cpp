// unk/00106658: the functions between utl/utlfind and dog/dogmotionblend.
// No assert or string names their file (or files): a sound-id lookup,
// helpers for i3d models, and vector math over libvu0. Every name here is
// ours.

#include "ror.h"
#include "game/gamman.h"
#include "sdk/libvu0.h"
#include "sdk/math.h"

#define PI 3.141593f
#define PI2 6.283186f
#define HALF_PI 1.5707963f

// 0x00295F08: rows of the same sound in the three id ranges 0x0A00xxxx,
// 0x0A01xxxx and 0x0A02xxxx (-1: none), ended by -2.
int gSndIdTable[][3] = {
    {0x0A00008E, 0x0A010192, 0x0A020293},
    {0x0A00008F, 0x0A010193, 0x0A020294},
    {0x0A00009A, 0x0A0101A0, 0x0A020295},
    {0x0A00009B, 0x0A0101A1, 0x0A020296},
    {0x0A000090, 0x0A01019A, 0x0A020299},
    {0x0A000091, 0x0A01019B, 0x0A02029A},
    {-1, 0x0A010198, 0x0A020297},
    {-1, 0x0A010199, 0x0A020298},
    {0x0A000096, 0x0A010196, -1},
    {0x0A000097, 0x0A010197, -1},
    {0x0A00009E, 0x0A0101A2, -1},
    {0x0A00009F, 0x0A0101A3, -1},
    {0x0A0000A2, 0x0A0101A4, -1},
    {0x0A0000A3, 0x0A0101A5, -1},
    {0x0A0000B2, 0x0A0101B2, -1},
    {0x0A0000B3, 0x0A0101B3, -1},
    {0x0A0000AA, 0x0A0101A8, -1},
    {0x0A0000AB, 0x0A0101A9, -1},
    {0x0A0000B0, 0x0A0101B4, -1},
    {0x0A0000B1, 0x0A0101B5, -1},
    {0x0A000089, 0x0A010183, 0x0A020288},
    {0x0A00008A, 0x0A010184, 0x0A02028B},
    {0x0A000084, -1, 0x0A020291},
    {0x0A000085, -1, 0x0A020292},
    {0x0A0000B4, -1, 0x0A02029B},
    {0x0A0000B5, -1, 0x0A02029C},
    {0x00000003, 0x0A0101B6, 0x0A02029D},
    {0x00000003, 0x0A0101B7, 0x0A02029E},
    {0x0A0000B8, 0x0A0101B8, 0x0A02029F},
    {0x0A0000B9, 0x0A0101B9, 0x0A0202A0},
    {0x0A0000BA, 0x0A0101BA, -1},
    {0x0A0000BB, 0x0A0101BB, -1},
    {0x0A0000BC, 0x0A0101BC, 0x0A0202A6},
    {0x0A0000BD, 0x0A0101BD, 0x0A0202A1},
    {0x0A0000BE, 0x0A0101BE, 0x0A0202A2},
    {0x0A0000BF, 0x0A0101BF, 0x0A0202A3},
    {0x0A0000C0, 0x0A0101C0, 0x0A0202A4},
    {0x0A0000C6, -1, 0x0A0202A5},
    {0x0A0000C7, 0x0A0101C7, -1},
    {0x0A0000C9, 0x0A0101CB, -1},
    {0x0A0000CA, 0x0A0101CC, -1},
    {0x0A0000CB, 0x0A0101CD, -1},
    {0x0A0000CC, 0x0A0101CE, -1},
    {0x0A0000CE, 0x0A0101D3, -1},
    {0x0A0000CF, 0x0A0101D4, -1},
    {0x0A0000D0, 0x0A0101D5, -1},
    {0x0A0000D1, 0x0A0101D6, -1},
    {0x0A0000D2, 0x0A0101D7, -1},
    {0x0A0000D3, 0x0A0101D8, -1},
    {0x0A0000D4, 0x0A0101D9, -1},
    {0x0A0000D5, 0x0A0101DA, -1},
    {0x0A0000D6, 0x0A0101DB, -1},
    {0x0A0000D7, 0x0A0101DC, -1},
    {-2, -2, -2},
};

// Still asm (mw/i3d, and the interrupt switch in mw/sound).
extern "C" {
int func_0021FE68(void *a, void *b, void *c, void *d, void *e);
int func_0022B0D0(void *theModel);
void *func_0022B0E8(void *theModel, int theNo);
int *func_0022AC08(void *theNode);
void func_0024A8C8();
void func_0024A958();
}

// An object with an i3d model at +0x10 (DogModel?).
struct I3dOwner {
    unsigned char m_unk00[0x10];
    unsigned char m_model[4];       // +0x10
};

// A vector that can be copied by assignment.
struct UtlVector {
    float x, y, z, w;
} __attribute__((aligned(16)));

// 0x00106658: theId as the same sound in the id range func_001C6C38 picks
// (SndMan).
int sndConvertId(int theId)
{
    int col;
    int *p;
    switch (theId & 0xFFFF0000) {
    case 0x0A000000:
        col = 0;
        p = &gSndIdTable[0][0];
        break;
    case 0x0A010000:
        col = 1;
        p = &gSndIdTable[0][1];
        break;
    case 0x0A020000:
        col = 2;
        p = &gSndIdTable[0][2];
        break;
    default:
        return theId;
    }
    int cur = func_001C6C38(&D_007812C0);
    if (col == cur || cur == -1) {
        return theId;
    }
    do {
        if (*p == theId) {
            return p[cur - col];
        }
        p += 3;
    } while (*p != -2);
    return theId;
}

// 0x00106760: an i3d call with interrupts off.
int i3dCallLocked(void *a, void *b, void *c, void *d, void *e)
{
    func_0024A8C8();
    int ret = func_0021FE68(a, b, c, d, e);
    func_0024A958();
    return ret;
}

// 0x001067D8: theValue into the user word of every node of the model.
int i3dSetUserAll(I3dOwner *theOwner, int theValue)
{
    void *model = theOwner->m_model;
    if (!model) {
        return 1;
    }
    int n = func_0022B0D0(model);
    for (int i = 0; i < n; i++) {
        void *node = func_0022B0E8(model, i);
        if (node) {
            int *user = func_0022AC08(node);
            if (user) {
                *user = theValue;
            }
        }
    }
    return 0;
}

// 0x0010686C
int i3dSetUser(I3dOwner *theOwner, int theValue, int theNo)
{
    void *model = theOwner->m_model;
    if (!model) {
        return 1;
    }
    void *node = func_0022B0E8(model, theNo);
    if (!node) {
        return 1;
    }
    int *user = func_0022AC08(node);
    if (!user) {
        return 1;
    }
    *user = theValue;
    return 0;
}

// 0x001068D4
int i3dGetUser(I3dOwner *theOwner, int theNo)
{
    void *model = theOwner->m_model;
    if (!model) {
        return 0;
    }
    void *node = func_0022B0E8(model, theNo);
    if (!node) {
        return 0;
    }
    int *user = func_0022AC08(node);
    if (user) {
        return *user;
    }
    return 0;
}

// 0x00106920: theOut = theIn turned by theAngle around X.
void vecRotateX(UtlVector *theOut, const UtlVector *theIn, float theAngle)
{
    float c = cosf(theAngle);
    float s = sinf(theAngle);
    UtlVector v;
    v.x = theIn->x;
    v.y = theIn->y * c - theIn->z * s;
    v.z = theIn->y * s + theIn->z * c;
    *theOut = v;
}

// 0x001069B0: around Y.
void vecRotateY(UtlVector *theOut, const UtlVector *theIn, float theAngle)
{
    float c = cosf(theAngle);
    float s = sinf(theAngle);
    UtlVector v;
    v.x = theIn->x * c - theIn->z * s;
    v.y = theIn->y;
    v.z = theIn->x * s + theIn->z * c;
    *theOut = v;
}

// 0x00106A40: around Z.
void vecRotateZ(UtlVector *theOut, const UtlVector *theIn, float theAngle)
{
    float c = cosf(theAngle);
    float s = sinf(theAngle);
    UtlVector v;
    v.x = theIn->x * c - theIn->y * s;
    v.y = theIn->x * s + theIn->y * c;
    v.z = theIn->z;
    *theOut = v;
}

// 0x00106AD0
float vecLength3(const float *v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

// 0x00106B24: theVec turned by theAngle around X, with a VU0 matrix.
void vecTurnX(float *theVec, float theAngle)
{
    sceVu0FMATRIX m;
    sceVu0UnitMatrix(m);
    if (theAngle >= PI) {
        theAngle -= PI2;
    } else if (theAngle < -PI) {
        theAngle += PI2;
    }
    sceVu0RotMatrixX(m, m, theAngle);
    sceVu0ApplyMatrix(theVec, m, theVec);
}

// 0x00106BC8: around Y.
void vecTurnY(float *theVec, float theAngle)
{
    sceVu0FMATRIX m;
    sceVu0UnitMatrix(m);
    if (theAngle >= PI) {
        theAngle -= PI2;
    } else if (theAngle < -PI) {
        theAngle += PI2;
    }
    sceVu0RotMatrixY(m, m, theAngle);
    sceVu0ApplyMatrix(theVec, m, theVec);
}

// 0x00106C6C: around Z.
void vecTurnZ(float *theVec, float theAngle)
{
    sceVu0FMATRIX m;
    sceVu0UnitMatrix(m);
    if (theAngle >= PI) {
        theAngle -= PI2;
    } else if (theAngle < -PI) {
        theAngle += PI2;
    }
    sceVu0RotMatrixZ(m, m, theAngle);
    sceVu0ApplyMatrix(theVec, m, theVec);
}

// 0x00106D10
float vecDot(float *a, float *b)
{
    return sceVu0InnerProduct(a, b);
}

// 0x00106D24
void vecCross(float *theOut, float *a, float *b)
{
    sceVu0OuterProduct(theOut, a, b);
}

// 0x00106D40: theOut = a + (b - a) * t, all four components.
void vecLerp(float *theOut, const float *a, const float *b, float t)
{
    theOut[0] = b[0] * t + a[0] * (1.0f - t);
    theOut[1] = b[1] * t + a[1] * (1.0f - t);
    theOut[2] = b[2] * t + a[2] * (1.0f - t);
    theOut[3] = b[3] * t + a[3] * (1.0f - t);
}

// 0x00106DB0
void vecNormalize(float *v)
{
    v[3] = 0.0f;
    sceVu0Normalize(v, v);
}

// 0x00106DD0
float vecLength(float *v)
{
    return sqrtf(sceVu0InnerProduct(v, v));
}

// 0x00106E14: squared distance.
float vecDist2(const float *a, const float *b)
{
    sceVu0FVECTOR d;
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = 0.0f;
    return sceVu0InnerProduct(d, d);
}

// 0x00106E70
float vecDist(const float *a, const float *b)
{
    return sqrtf(vecDist2(a, b));
}

// 0x00106EB4: the same, in one.
float vecDist3(const float *a, const float *b)
{
    sceVu0FVECTOR d;
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = 0.0f;
    return sqrtf(sceVu0InnerProduct(d, d));
}

// 0x00106F38: on the ground (X and Z).
float vecDistXZ(const float *a, const float *b)
{
    sceVu0FVECTOR d;
    d[0] = a[0] - b[0];
    d[2] = a[2] - b[2];
    d[1] = d[3] = 0.0f;
    return sqrtf(sceVu0InnerProduct(d, d));
}

// 0x00106FB4: the distance from a to b, and the yaw to face b.
float vecDistYaw(const float *a, float *theYaw, const float *b)
{
    sceVu0FVECTOR d;
    d[0] = b[0] - a[0];
    d[1] = b[1] - a[1];
    d[2] = b[2] - a[2];
    d[3] = 0.0f;
    float len = sqrtf(sceVu0InnerProduct(d, d));
    if (d[2] != 0.0f) {
        *theYaw = atanf(d[0] / d[2]);
        if (d[2] < 0.0f) {
            *theYaw += PI;
            if (*theYaw >= PI) {
                *theYaw -= PI2;
            }
        }
    } else if (d[0] == 0.0f) {
        *theYaw = 0.0f;
    } else {
        *theYaw = d[0] < 0.0f ? -HALF_PI : HALF_PI;
    }
    return len;
}

// 0x001070F8: the yaw of v (around Y, 0 along +Z).
float vecYaw(const float *v)
{
    float a;
    if (v[2] == 0.0f) {
        if (v[0] == 0.0f) {
            a = 0.0f;
        } else {
            a = v[0] < 0.0f ? -HALF_PI : HALF_PI;
        }
    } else {
        a = atanf(v[0] / v[2]);
        if (v[2] < 0.0f) {
            a += PI;
            if (a >= PI) {
                a -= PI2;
            }
        }
    }
    return a;
}

// 0x001071C8: the pitch of v (around X).
float vecPitch(const float *v)
{
    float a;
    if (v[2] == 0.0f) {
        if (v[0] == 0.0f) {
            a = HALF_PI;
        } else {
            a = asinf(-v[1]);
        }
    } else if (v[1] == 0.0f) {
        a = 0.0f;
    } else {
        a = asinf(-v[1]);
    }
    return a;
}

// 0x00107248: theRot = the pitch and yaw that point along theDir
// (normalised in place); theRot[2] = 0. The tests compare with theRot[2]:
// the game reloads it after zeroing it instead of using a 0.0f constant.
void vecDirToRot(float *theDir, float *theRot)
{
    vecNormalize(theDir);
    theRot[2] = 0.0f;
    if (theDir[2] == theRot[2]) {
        if (theDir[0] == theRot[2]) {
            theRot[1] = theRot[2];
            theRot[0] = HALF_PI;
            return;
        }
        theRot[1] = theDir[0] < theRot[2] ? -HALF_PI : HALF_PI;
        theRot[0] = asinf(-theDir[1]);
    } else {
        if (theDir[1] == theRot[2]) {
            theRot[0] = theRot[2];
        } else {
            theRot[0] = asinf(-theDir[1]);
        }
        theRot[1] = atanf(theDir[0] / theDir[2]);
        if (theDir[2] < 0.0f) {
            theRot[1] += PI;
            if (theRot[1] >= PI) {
                theRot[1] -= PI2;
            }
        }
    }
}
