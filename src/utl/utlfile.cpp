// utl/utlfile.cpp: string helpers for file names (bounded copies, a join,
// a case-insensitive compare).
//
// Matching decompilation. The asserts must stay on lines 15-16 and 36-37.
// Function names and theSrc* are ours; theDest and theSize come from the
// assert strings.

#include "ror.h"
#include "sdk/ctype.h"

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

// 0x00106010: are a and b the same, ignoring case? (MagLoader)
int utlStrCaseEqual(const char *a, const char *b)
{
    int ca, cb;
    do {
        ca = *a++;
        cb = *b++;
        if (ca >= 'a' && ca <= 'z') {
            ca -= 'a' - 'A';
        }
        if (cb >= 'a' && cb <= 'z') {
            cb -= 'a' - 'A';
        }
        if (ca != cb) {
            return 0;
        }
    } while (ca != '\0');
    return 1;
}

// 0x00106064: utlStrCopy in upper case; returns theDest.
char *utlStrCopyUpper(char *theDest, int theSize, const char *theSrc)
{
    char *p = theDest;
    for (int i = 0; i < theSize; i++, p++, theSrc++) {
        if ((*p = toupper(*theSrc)) == '\0') {
            break;
        }
    }
    theDest[theSize - 1] = '\0';
    return theDest;
}
