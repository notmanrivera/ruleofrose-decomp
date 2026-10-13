// utl/utlbtl.cpp: battle helpers: the game's random numbers (a linear
// congruential generator), queries to GamMan about the player, and two
// geometric tests (a rotated line, a cone/range test). Matching
// decompilation. The asserts sit on lines 60-62, 148, 149 and 153 (the
// original file is denser than ours, so #line places them).
// Names are func_<address> because other files call them that way.
#include "ror.h"
#include "game/gamman.h"
#include "game/gamtrg.h"
#include "sdk/math.h"
#include "sdk/libvu0.h"
#include "sdk/string.h"
#include "utl/utlbtl.h"
#include "include_asm.h"

// The __FILE__ string, shared with the asm functions (INCLUDE_RODATA).
#undef ASSERT_FILE
#define ASSERT_FILE D_002E75F8
extern const char D_002E75F8[];     // "utl/utlbtl.cpp"

// Still in other (asm) files.
extern "C" {
void func_001CB5D8(GamMan *g, int kind, int *value);
void func_001CB490(GamMan *g, int kind, int *value);
int func_00163FF4(void *obj, int a);
void func_00163F1C(void *obj, int a);
int func_00163B20(void *obj, int a);
void func_001D49D0(GamMan *g, int oid);
void func_001D5A0C(GamMan *g, float *vec, int oid, int a, int b, int *out);
void func_001D4A3C(GamMan *g, int oid, int a);
void func_001D10D0(GamMan *g, int oid, int a);
void func_001D1C80(GamMan *g, int a, int b, int *value);
void func_002375D8(float *q);
void func_00237390(float *dst, float ang, float *src);
void func_00235608(float *target, float *v, float *origin, float *q);
void func_00234DC0(float *target, float *origin, float *q);
void func_00234ED0(float *origin, float *target, float *v);
void func_00234D40(float *origin, float *target);
void func_0025B890(float *dst, float *a, float *b);
float func_0026CAD0(float x);
}
extern char D_007B2140[];

extern unsigned int D_00308484;     // the random number state
#define sSeed D_00308484

// 0x00103EDC
extern "C" void func_00103EDC(int theValue)
{
    int v = theValue;
    func_001CB5D8(&D_007812C0, 0x1B, &v);
}

// 0x00103F08
extern "C" int func_00103F08()
{
    int v = 0;
    func_001CB490(&D_007812C0, 0x1B, &v);
    return v;
}

// 0x00103F38
extern "C" int func_00103F38()
{
    int v = 0;
    func_001CB490(&D_007812C0, 0x1C, &v);
    return v;
}

// 0x00103F68
extern "C" int func_00103F68(int a)
{
    return func_00163FF4(D_007B2140, a);
}

// 0x00103F88
extern "C" void func_00103F88(int a)
{
    func_00163F1C(D_007B2140, a);
}

// 0x00103FAC
extern "C" int func_00103FAC(int a)
{
    return func_00163B20(D_007B2140, a) == 7;
}

// 0x00103FD8
extern "C" int func_00103FD8(int a)
{
    return func_00163B20(D_007B2140, a) == 4;
}

// The player's object ID, or 0 (an inline method of GamMan in the game).
static inline int utlPlayerOID(GamMan *g)
{
    ObjStat *p = g->getPlayer();
    return p ? p->getOID() : 0;
}

// NON_MATCHING: the game keeps the player's object ID in $s0, theOut in $s1,
// the copy of the position's address in $s2 and the GamMan in $s3;
// ours allocates them in another order.
#ifdef NON_MATCHING
// 0x00104004
extern "C" void func_00104004(u_long128 *thePos, int *theOut)
{
    GamMan *g = &D_007812C0;
    int out[8];
    float vec[4];
    int oid = utlPlayerOID(g);
    u_long128 *pv = (u_long128 *)vec;
    *pv = *thePos;
    func_001D49D0(g, oid);
    func_001D5A0C(g, vec, oid, 0, 1, out);
    if (theOut) *theOut = out[4];
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utlbtl", func_00104004);
#endif

// 0x001040A0
extern "C" void func_001040A0()
{
    int oid = utlPlayerOID(&D_007812C0);
    return func_001D4A3C(&D_007812C0, oid, 0);
}

// 0x001040DC
extern "C" void func_001040DC()
{
    func_001D49D0(&D_007812C0, utlPlayerOID(&D_007812C0));
}

// 0x0010411C
extern "C" int func_0010411C(int a)
{
    int v = 0;
    func_001D1C80(&D_007812C0, a, 2, &v);
    return v;
}

// 0x00104150
extern "C" void func_00104150(int a)
{
    if (a) return func_001D10D0(&D_007812C0, utlPlayerOID(&D_007812C0), 0x40);
    func_001D10D0(&D_007812C0, utlPlayerOID(&D_007812C0), 0x40);
}

// 0x001041C4: next random number state.
extern "C" void func_001041C4()
{
    sSeed = sSeed * 0x769 + 0x7CF9;
}

// 0x001041E4: random number in [0, n).
extern "C" int func_001041E4(int n)
{
    func_001041C4();
    return (int)(((long)sSeed * n) >> 32);
}

// 0x0010421C
extern "C" void func_0010421C()
{
    sSeed = 0xC45330AF;
}

// 0x00104230
extern "C" void func_00104230(int theSeed)
{
    sSeed = theSeed;
}

// 0x0010423C: random number in [theMin, theMax].
extern "C" int func_0010423C(int theMin, int theMax)
{
    return func_001041E4(theMax - theMin + 1) + theMin;
}

// 0x0010426C: average of theNum random numbers in [theMin, theMax].
extern "C" int func_0010426C(int theMin, int theMax, int theNum)
{
    int range = theMax - theMin + 1;
    int sum = 0;
    for (int i = 0; i < theNum; i++) sum += func_001041E4(range);
    return sum / theNum + theMin;
}

// 0x001042EC
extern "C" int func_001042EC(int theMin, int theMax, int theNum)
{
    int sum = 0;
    int d = theMax - theMin;
    int range = d * 2 + 1;
    for (int i = 0; i < theNum; i++) sum += func_001041E4(range);
    sum /= theNum;
    if (sum < d) sum = d + (d - sum);
    return theMin + (sum - d);
}

// 0x00104394
extern "C" int func_00104394(int theMin, int theMax, int theNum)
{
    int sum = 0;
    int d = theMax - theMin;
    int range = d * 2 + 1;
    for (int i = 0; i < theNum; i++) sum += func_001041E4(range);
    sum /= theNum;
    if (sum > d) sum = d - (sum - d);
    return sum + theMin;
}

// 0x00104438: skewed around theMid.
extern "C" int func_00104438(int theMin, int theMax, int theMid, int theNum)
{
    if (theMid < func_0010423C(theMin, theMax)) return func_00104394(theMin, theMid, theNum);
    return func_001042EC(theMid, theMax, theNum);
}

// 0x001044B8: random float in [a, b] (0 when the draw is 0).
extern "C" float func_001044B8(float a, float b)
{
    float d = b - a;
    float s = d * 65536.0f;
    int r = func_0010423C(0, (int)s);
    if (r == 0) return 0.0f;
    return (float)r / s * d + a;
}

// 0x0010452C
extern "C" void func_0010452C(void *p)
{
    memset(p, 0, 0x28);
}

// 0x0010454C
extern "C" void func_0010454C(void *p)
{
    memset(p, 0, 0x14);
}

INCLUDE_RODATA("asm/nonmatchings/utl/utlbtl", D_002E75F8);

// NON_MATCHING: three instructions differ; the game loads m_rotate into $a1
// where ours uses $v0.
#ifdef NON_MATCHING
// 0x0010456C
extern "C" void func_0010456C(UtlHitLine *theHitCheck)
{
#line 60
    ASSERT(theHitCheck);
    ASSERT(theHitCheck->m_origin_pos);
    ASSERT(theHitCheck->m_target_pos);
    if (theHitCheck->m_rotate) {
        float q[4];
        func_002375D8(q);
        func_00237390(q, theHitCheck->m_angle, q);
        if (theHitCheck->m_scale == 0.0f) {
            func_00234DC0(theHitCheck->m_target_pos, theHitCheck->m_origin_pos, q);
        } else {
            float v[4];
            v[0] = 0.0f;
            v[1] = theHitCheck->m_scale;
            v[2] = 0.0f;
            v[3] = 0.0f;
            func_00235608(theHitCheck->m_target_pos, v, theHitCheck->m_origin_pos, q);
        }
    } else {
        if (theHitCheck->m_scale != 0.0f) {
            float v[4];
            v[0] = 0.0f;
            v[1] = theHitCheck->m_scale;
            v[2] = 0.0f;
            v[3] = 0.0f;
            func_00234ED0(theHitCheck->m_origin_pos, theHitCheck->m_target_pos, v);
        } else {
            func_00234D40(theHitCheck->m_origin_pos, theHitCheck->m_target_pos);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/utl/utlbtl", func_0010456C);
#endif

// 0x001046B4
extern "C" int func_001046B4(UtlHitCone *theHitCheck)
{
    int ret = 0;
#line 148
    ASSERT(theHitCheck->m_pos_self);
    ASSERT(theHitCheck->m_pos_aim);
    float aim[4];
    func_0025B890(aim, theHitCheck->m_pos_aim, theHitCheck->m_pos_self);
    sceVu0Normalize(aim, aim);
    float tgt[4];
#line 153
    ASSERT(theHitCheck->m_pos_target);
    func_0025B890(tgt, theHitCheck->m_pos_target, theHitCheck->m_pos_self);
    float dist = sqrtf(tgt[0] * tgt[0] + tgt[1] * tgt[1] + tgt[2] * tgt[2]);
    sceVu0Normalize(tgt, tgt);
    float dot = sceVu0InnerProduct(aim, tgt);
    switch (theHitCheck->m_type) {
    case 3: {
        if (dist > 500.0f) break;
        if (dot <= 0.0f) break;
        float a = func_0026CAD0(dot);
        int r = func_0010426C(-10000, 10000, 4);
        float t = (float)r / 100.0f;
        t = t * 3.14159265f / 180.0f;
        a = a + t;
        if (dist * tanf(a) <= theHitCheck->m_size) ret = 1;
        break;
    }
    case 0:
        if (dist > 100.0f) break;
        if (dot <= 0.3f) break;
        ret = 1;
        break;
    case 1:
        if (dist > 120.0f) break;
        if (dot <= 0.3f) break;
        ret = 1;
        break;
    case 2: {
        if (theHitCheck->m_size + (float)theHitCheck->m_range < dist) break;
        if (dot <= 0.0f) break;
        float a = func_0026CAD0(dot);
        if (dist * tanf(a) <= theHitCheck->m_size) ret = 1;
        break;
    }
    }
    return ret;
}

// The game's .rodata for this file ends with 8 zero bytes after the last
// string (utl/utltm2's strings start at a multiple of 16). What they were is
// unknown: reproduced as an unused constant with external linkage (so it is
// emitted), which a file puts after everything else.
extern const long long gUtlBtlRodataTail = 0;
