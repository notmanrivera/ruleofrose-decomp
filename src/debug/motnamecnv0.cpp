// debug/motnamecnv0.cpp: converts motion names to motion numbers in a
// table of entries (debug build helper). Names are ours; p, tbl and str
// come from the assert strings.
//
// Matching decompilation. The ASSERTs must stay on lines 119, 120, 207.

#include "ror.h"

extern char D_006FBD80;
extern "C" int func_001437C0(void *theSelf, int theArg1, int theArg2);
extern "C" int func_001436D4(void *theSelf, const char *theStr);

// An entry of the table (0x48 bytes); type 2 holds a name key in m_value.
struct MotEntry {
    int m_unk00;
    int m_type;                     // +0x04: 0 ends the table
    int m_value;                    // +0x08
    char m_unk0C[0x3C];
};

// One row of the name table: id, then the key that selects it.
struct MotKey {
    int m_id;
    int m_key;
};

// 0x0021614C
void motNop()
{
}

// 0x00216154
static int lookupName(int theArg1, int theArg2)
{
    int off = 0x854E8;
    return func_001437C0((char *)&D_006FBD80 + off, theArg1, theArg2);
}

// 0x00216184
int motConvert(int theArg, MotEntry *p, MotKey *tbl)
{













































































    ASSERT(p);
    ASSERT(tbl);
    int ok = 1;
    for (; p->m_type != 0; p++) {
        if (p->m_type == 2) {
            int found = 0;
            MotKey *t = tbl;
            int r = -1;
            for (; t->m_id != 0; t++) {
                if (t->m_key == p->m_value) {
                    found = t->m_id;
                    r = lookupName(theArg, found);
                    p->m_value = r;
                    break;
                }
            }
            if (found) {
                if (r == -1) {
                    p->m_value = 0;
                    ok = 0;
                }
            } else {
                ok = 0;
            }
        }
    }
    return ok;
}

// 0x0021628C
int motSetName(const char *str)
{
























































    ASSERT(str);
    int off = 0x854E8;
    return func_001436D4((char *)&D_006FBD80 + off, str);
}
