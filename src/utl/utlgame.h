// utl/utlgame.h: what decompiled code uses from utl/utlgame.cpp, still asm.
#ifndef UTL_UTLGAME_H
#define UTL_UTLGAME_H

class ObjStat;

extern "C" {
int func_00102B6C(int x, int *uid, int num);
ObjStat *func_00102D54(int uid);                // the object with this UID, or 0
int func_00103240(int *uid, int max, int key);
int func_001033F0(unsigned short uid);       // fills uid with the objects for key
}

#endif
