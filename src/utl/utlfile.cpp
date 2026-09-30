// utl/utlfile.cpp: bounded string copies, used to build file names.
//
// Matching decompilation. The asserts must stay on lines 15-16 and 36-37.
// Function names and theSrc* are ours; theDest and theSize come from the
// assert strings.

#include "ror.h"

// 0x00105E50: copies theSrc into theDest, a buffer of theSize bytes,
// cutting it short if it does not fit; theDest always ends with a NUL.


void utlStrCopy(char *theDest, int theSize, const char *theSrc)
{
    ASSERT(theDest);
    ASSERT(2 <= theSize && theSize <= 1024);
    char *p = theDest;
    if (theSrc) {
        const char *s = theSrc;
        while (p < theDest + theSize - 1 && *s != '\0') {
            *p++ = *s++;
        }
    }
    *p = '\0';
}

// 0x00105F0C: theDest = theSrc1 followed by theSrc2, cut short like
// utlStrCopy. Callers join a directory and a name ("movie/" + name) or a
// name and a suffix (name + "_c.bin").




void utlStrJoin(char *theDest, int theSize, const char *theSrc1, const char *theSrc2)
{
    ASSERT(theDest);
    ASSERT(2 <= theSize && theSize <= 1024);
    char *p = theDest;
    if (theSrc1) {
        const char *s = theSrc1;
        while (p < theDest + theSize - 1 && *s != '\0') {
            *p++ = *s++;
        }
    }
    if (theSrc2) {
        const char *s = theSrc2;
        while (p < theDest + theSize - 1 && *s != '\0') {
            *p++ = *s++;
        }
    }
    *p = '\0';
}
