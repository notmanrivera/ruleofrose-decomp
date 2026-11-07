// mag/magsceneif.cpp: MagSceneIf (see the header).
#include "mag/magsceneif.h"
#include "sdk/string.h"

extern "C" int func_00142500(void *theList, const char *theName);
extern "C" int func_00142C2C(void *theList, int theArg);
void utlStrCopy(char *theDest, int theSize, const char *theSrc);



















int MagSceneIfList1::getMax()
{
    ASSERT(m_scene_ptr);
    return *(int *)((char *)m_scene_ptr + 0x2278);
}




const char *MagSceneIfList1::func_001434E4(int theIndex)
{
    ASSERT(m_scene_ptr);
    ASSERT(0 <= theIndex && theIndex < getMax());
    return (*(const char ***)((char *)m_scene_ptr + 0x228C))[theIndex];
}




void MagSceneIfList1::func_00143578(const char *theName)
{
    ASSERT(m_scene_ptr);
    ASSERT(theName);
    func_00142500((char *)m_scene_ptr + 0x2278, theName);
}













int MagSceneIfList2::getMax()
{
    ASSERT(m_scene_ptr);
    return *(int *)((char *)m_scene_ptr + 0x2228);
}




const char *MagSceneIfList2::func_00143640(int theIndex)
{
    ASSERT(m_scene_ptr);
    ASSERT(0 <= theIndex && theIndex < getMax());
    return (*(const char ***)((char *)m_scene_ptr + 0x223C))[theIndex];
}




void MagSceneIfList2::func_001436D4(const char *theName)
{
    ASSERT(m_scene_ptr);
    ASSERT(theName);
    func_00142500((char *)m_scene_ptr + 0x2228, theName);
}




int MagSceneIf::func_00143750(int theArg)
{
    ASSERT(m_scene_ptr);
    return func_00142C2C((char *)m_scene_ptr + 0x215C, theArg);
}

int MagSceneIf::func_001437A8(int theCharaID)
{
    DogActor *p = &m_scene_ptr->m_actor[theCharaID];
    return p->m_max_motion;
}













int MagSceneIf::func_001437C0(int theCharaID, const char *theName)
{
    char buf[0x100];
    ASSERT(m_scene_ptr);
    DogActor *actor = &m_scene_ptr->m_actor[theCharaID];
    int r = actor->func_0010AB40(theName);
    if (r < 0) {
        utlStrCopy(buf, 0x100, theName);
        buf[0xFF] = 0;
        for (char *p = buf; *p; p++) {
            if (*p == '*' || *p == '+') {
                *p = 0;
                break;
            }
        }
        r = actor->func_0010AA5C(buf);
    }
    return r;
}















const char *MagSceneIf::func_001438B0(int theCharaID, int theMotionID)
{
    ASSERT(m_scene_ptr);
    ASSERT(theCharaID >= 0);
    ASSERT(theMotionID >= 0);
    return m_scene_ptr->m_actor[theCharaID].func_0010DA98(theMotionID);
}








void MagSceneIf::func_0014395C(char *theName, int theSize, int theCharaID, int theMotionID, int theFlag)
{
    ASSERT(m_scene_ptr);
    ASSERT(theName);
    ASSERT(theSize > 16);
    ASSERT(theCharaID >= 0);
    ASSERT(theMotionID >= 0);
    memset(theName, 0, theSize);
    const char *name = func_001438B0(theCharaID, theMotionID);
    if (name) {
        const char *p = name;
        while (*p != '_' && *p != 0) {
            p++;
        }
        if (*p == 0) {
            return utlStrCopy(theName, theSize, name);
        }
        if (*p == '_') {
            p++;
        } else {


















            ASSERT(0);
        }
        int i = 0;
        if (theFlag) {
            for (; *p && i < theSize - 1; i++) {
                theName[i] = *p++;
            }
            theName[i] = 0;
        } else {
            for (; *p && !(*p == '_' && p[1] == '_') && i < theSize - 1; i++) {
                theName[i] = *p++;
            }
            theName[i] = 0;
        }
    }
}






















int MagSceneIf::func_00143BA0(int theCharaID)
{
    ASSERT(m_scene_ptr);
    ASSERT(theCharaID >= 0);
    return m_scene_ptr->m_actor[theCharaID].DogModel::get_nNode();
}






const char *MagSceneIf::func_00143C48(int theCharaID, int theNodeNo)
{
    ASSERT(m_scene_ptr);
    ASSERT(theCharaID >= 0);
    ASSERT(theNodeNo >= 0);
    return m_scene_ptr->m_actor[theCharaID].DogModel::getNodeName(theNodeNo);
}
