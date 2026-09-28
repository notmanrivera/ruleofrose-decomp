// utl/utlmisc.cpp
//
// Matching decompilation. The ASSERT must stay on line 22 (0x16).
// Function name is ours; the parameter name comes from the assert string.

#include "ror.h"

// 0x00105650: does the name contain "_tcc"?











int utlIsTcc(const char *theName)
{
    ASSERT(theName);
    for (const char *p = theName; *p != '\0'; p++) {
        if (p[0] == '_' && p[1] == 't' && p[2] == 'c' && p[3] == 'c') {
            return 1;
        }
    }
    return 0;
}
