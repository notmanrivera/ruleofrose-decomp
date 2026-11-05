// mag/magsceneif.h: MagSceneIf, the debug tools' window on a MagScene: its
// lists of models and motions and its actors' motion names. The member
// m_scene_ptr and the argument names come from the asserts; the class name
// comes from the file name. Other files call the methods as plain symbols.
#ifndef MAG_MAGSCENEIF_H
#define MAG_MAGSCENEIF_H

#include "mag/magscene.h"

// Lists kept by the scene (+0x2278 and +0x2228): both have a getMax(), as the
// asserts show. Their names are ours.
class MagSceneIfList1 {
public:
    MagScene *m_scene_ptr;

    int getMax() asm("func_00143498");
    const char *func_001434E4(int theIndex) asm("func_001434E4");
    void func_00143578(const char *theName) asm("func_00143578");
};

class MagSceneIfList2 {
public:
    MagScene *m_scene_ptr;

    int getMax() asm("func_001435F4");
    const char *func_00143640(int theIndex) asm("func_00143640");
    void func_001436D4(const char *theName) asm("func_001436D4");
};

class MagSceneIf {
public:
    MagScene *m_scene_ptr;

    int func_00143750(int theArg) asm("func_00143750");
    int func_001437A8(int theCharaID) asm("func_001437A8");
    int func_001437C0(int theCharaID, const char *theName) asm("func_001437C0");
    const char *func_001438B0(int theCharaID, int theMotionID) asm("func_001438B0");
    void func_0014395C(char *theName, int theSize, int theCharaID, int theMotionID,
                       int theFlag) asm("func_0014395C");
    int func_00143BA0(int theCharaID) asm("func_00143BA0");
    const char *func_00143C48(int theCharaID, int theNodeNo) asm("func_00143C48");
};

#endif
