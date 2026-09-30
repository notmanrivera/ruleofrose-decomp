// utl/utlfind.h: what Brown's "find" mode looks for (MagLifeBwnCtrl).
// Names are ours.
#ifndef UTL_UTLFIND_H
#define UTL_UTLFIND_H

class ObjStat;

// Up to 4 objects to find, by UID (ObjStat::getUID).
struct UtlFind {
    int m_uid[4];       // +0x00: -1 when unused
    int m_num;          // +0x10
    int m_unk14;        // +0x14: when 0, objects func_001033F0 accepts smell 10 times weaker
};

int utlFindGetArea(ObjStat *theHandle);
int utlFindGetUID(ObjStat *theHandle);
int utlFindGetOID(ObjStat *theHandle);
void utlFindGetPos(ObjStat *theHandle, float *thePos);
void utlFindClear(UtlFind *theFind);
int utlFindIsSet(UtlFind *theFind);
void utlFindSet(UtlFind *theFind, int theKey, int theFlag);
int utlFindIsTarget(UtlFind *theFind, int theX);
ObjStat *utlFindFirst(UtlFind *theFind);
ObjStat *utlFindNearest(UtlFind *theFind, float *thePos, int theArea);

#endif
