// debug/motnamecnv.cpp: wrappers around the motion-name table kept in the
// global at D_006FBD80+0x854E8 (debug build helper). Names are ours; p, str,
// theBuf, theSize, chara_num and motion_num come from the assert strings.
//
// Matching decompilation. The ASSERTs must stay on lines 191, 216, 261-264,
// 318 and 319.

#include "ror.h"

extern char D_006FBD80;
extern "C" void *memset(void *theDest, int theByte, unsigned int theSize);
extern "C" char *utlStrCopyUpper__FPciPCc(char *theDest, int theSize, const char *theSrc);
extern "C" void func_00143750(void *theSelf, int theArg);
extern "C" void func_00143498(void *theSelf);
extern "C" void func_001434E4(void *theSelf);
extern "C" void func_00143578(void *theSelf);
extern "C" void func_001435F4(void *theSelf);
extern "C" const char *func_00143640(void *theSelf, int theNo);
extern "C" int func_001436D4(void *theSelf, const char *theStr);
extern "C" void func_001437A8(void *theSelf);
extern "C" const char *func_001438B0(void *theSelf, int theChara, int theMotion);
extern "C" void func_0014395C(void *theSelf, char *theBuf, int theSize, int theChara, int theMotion, int theFlag);

// The first argument of the wrappers below is unused (their `this`).

// 0x002162E0
void motFunc0(int theArg)
{
    int off = 0x854E8;
    return func_00143750(&D_006FBD80 + off, theArg);
}

// 0x0021630C
void motFunc1()
{
    int off = 0x854E0;
    return func_00143498(&D_006FBD80 + off);
}

// 0x00216334
void motFunc2()
{
    int off = 0x854E0;
    return func_001434E4(&D_006FBD80 + off);
}

// 0x0021635C
void motFunc3()
{
    int off = 0x854E0;
    return func_00143578(&D_006FBD80 + off);
}

// 0x00216384
void motFunc4()
{
    int off = 0x854E8;
    return func_001435F4(&D_006FBD80 + off);
}

// 0x002163AC: the name of motion theNo, "----" if negative.
const char *motGetName(int theUnused, int theNo)
{
    int off = 0x854E8;
    char *tbl = &D_006FBD80 + off;
    const char *p;
    if (theNo >= 0) {
        p = func_00143640(tbl, theNo);
    } else {
        p = "----";
    }























































































































    ASSERT(p);
    return p;
}

// 0x0021641C: the motion number of a name, or -1; names starting "PC" count
// as motion 0.
int motFindName(int theUnused, const char *str)
{

















    ASSERT(str);
    int off = 0x854E8;
    int no = func_001436D4(&D_006FBD80 + off, str);
    if (no >= 0) {
        return no;
    }
    if (str[0] == 'P') {
        if (str[1] == 'C') {
            return 0;
        }
    }
    return -1;
}

// 0x0021649C
char *motGetName2(int theUnused, char *theBuf, int theSize, int chara_num, int motion_num)
{




























    ASSERT(theBuf);
    ASSERT(theSize > 16);
    ASSERT(chara_num >= 0);
    ASSERT(motion_num >= 0);
    memset(theBuf, 0, theSize);
    int off = 0x854E8;
    func_0014395C(&D_006FBD80 + off, theBuf, theSize, chara_num, motion_num, 1);
    return theBuf;
}

// 0x00216598
void motFunc5()
{
    int off = 0x854E8;
    return func_001437A8(&D_006FBD80 + off);
}

// 0x002165C0
char *motGetName3(int theUnused, char *theBuf, int theSize, int chara_num, int motion_num)
{





































    ASSERT(theBuf);
    ASSERT(theSize > 16);
    memset(theBuf, 0, theSize);
    int off = 0x854E8;
    const char *name = func_001438B0(&D_006FBD80 + off, chara_num, motion_num);
    if (name) {
        utlStrCopyUpper__FPciPCc(theBuf, theSize, name);
    }
    return theBuf;
}
