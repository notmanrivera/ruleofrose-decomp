// utl/utlfind.cpp: helpers for Brown's "find" mode (see utl/utlfind.h).
// Matching decompilation. The asserts must stay on lines 22, 36, 48, 60
// and 172. Names are ours except ObjStat, GamMan and their inline methods
// (linkonce copies) and theHandle (assert string).

#include "ror.h"
#include "game/gamman.h"
#include "game/gamtrg.h"
#include "sdk/math.h"
#include "utl/utlfind.h"
#include "utl/utlgame.h"







// 0x001060E8: the object's area (kind 8 of func_001DB31C).
int utlFindGetArea(ObjStat *theHandle)
{
    ASSERT(theHandle != 0);
    int area;
    func_001DB31C(theHandle, 8, &area);
    return area;
}






// 0x00106138
int utlFindGetUID(ObjStat *theHandle)
{
    ASSERT(theHandle != 0);
    return theHandle->getUID();
}






// 0x00106178
int utlFindGetOID(ObjStat *theHandle)
{
    ASSERT(theHandle != 0);
    return theHandle->getOID();
}






// 0x001061B8: the object's position.
void utlFindGetPos(ObjStat *theHandle, float *thePos)
{
    ASSERT(theHandle != 0);
    func_001DB71C(theHandle, thePos);
}

// 0x0010620C
void utlFindClear(UtlFind *theFind)
{
    for (int i = 0; i < 4; i++) {
        theFind->m_uid[i] = -1;
    }
    theFind->m_num = 0;
    theFind->m_unk14 = 0;
}

// 0x00106240: is there anything to find?
int utlFindIsSet(UtlFind *theFind)
{
    for (int i = 0; i < theFind->m_num; i++) {
        if (theFind->m_uid[i] > 0) {
            return 1;
        }
    }
    return 0;
}

// 0x00106280: the objects for theKey (utl/utlgame's func_00103240).
void utlFindSet(UtlFind *theFind, int theKey, int theFlag)
{
    theFind->m_unk14 = theFlag;
    theFind->m_num = func_00103240(theFind->m_uid, 4, theKey);
}

// 0x001062B4
int utlFindIsTarget(UtlFind *theFind, int theX)
{
    return func_00102B6C(theX, theFind->m_uid, theFind->m_num);
}

// 0x001062D8: the first of them that exists.
ObjStat *utlFindFirst(UtlFind *theFind)
{
    for (int i = 0; i < theFind->m_num; i++) {
        ObjStat *obj = func_00102D54(theFind->m_uid[i]);
        if (obj) {
            return obj;
        }
    }
    return 0;
}

// Still asm elsewhere.
class WrdSrv;
extern WrdSrv D_00298EE0;       // unk/WrdSrv, in .data
extern "C" {
// unk/WrdSrv: thePos in theArea, in world coordinates (theOut).
void func_0017EB3C(WrdSrv *theWrdSrv, float *theOut, int theArea, float *thePos);
// debug/mimu_debug: formats a vector's four numbers (and prints nothing).
void func_00215BB4(float *v);
}
























// 0x00106344: the object Brown smells best from thePos: the smell range
// divided by the distance (height counting ten times), at least 1. Once one
// is in theArea, only those count. Without thePos, utlFindFirst.
ObjStat *utlFindNearest(UtlFind *theFind, float *thePos, int theArea)
{
    if (thePos == 0) {
        return utlFindFirst(theFind);
    }
    int sameArea = 0;
    func_00215BB4(thePos);
    GamList<ObjStat *>::iterator it;
    GamList<ObjStat *> *list = D_007812C0.getVFchrListPtr();
    GamList<ObjStat *>::iterator first = list->begin();
    GamList<ObjStat *>::iterator last = list->end();
    ObjStat *result = 0;
    float best = 0.0f;
    for (int i = 0; i < theFind->m_num; i++) {
        for (it = first; it != last; it++) {
            unsigned short uid = (*it)->getUID();
            if (theFind->m_uid[i] != uid) {
                continue;
            }
            float range;
            (*it)->get_o_smell_range(&range);
            if (range == 0.0f) {
                range = 1000000.0f;
            }
            int area = -100;
            func_001DB31C(*it, 8, &area);
            ASSERT(area >= 0);
            if (!sameArea) {
                if (area == theArea) {
                    best = 0.0f;
                    result = 0;
                    sameArea = 1;
                }
            } else if (area != theArea) {
                continue;
            }
            float pos[4];
            func_001DB71C(*it, pos);
            float wpos[4];
            float *w = wpos;
            w[0] = w[1] = w[2] = 0.0f;
            w[3] = 1.0f;
            func_0017EB3C(&D_00298EE0, w, area, pos);
            float dx = thePos[0] - wpos[0];
            float dy = thePos[1] - wpos[1];
            float dz = thePos[2] - wpos[2];
            float smell = sqrtf(dx * dx + dy * dy * 100.0f + dz * dz) / 100.0f;
            smell = range / smell;
            func_00215BB4(wpos);
            if (smell >= 1.0f) {
                if (theFind->m_unk14 == 0 && func_001033F0(uid)) {
                    smell /= 10.0f;
                }
                if (best < smell) {
                    best = smell;
                    result = *it;
                }
            }
        }
    }
    return result;
}
