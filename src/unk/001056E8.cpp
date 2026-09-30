// unk/001056E8: the functions between utl/utlmisc and utl/utlfile. No
// assert or string names their file (or files): VU0 conversions, a text
// tokenizer, a frame counter, the global operator new/delete and wrappers
// of the global heap. Every name here is ours.

#include "ror.h"
#include "bed/bedmemory.h"
#include "sdk/ctype.h"
#include "sdk/stdlib.h"

// Linker script symbols (crt0 passes them to SetupHeap and SetupThread).
extern char _end[];             // end of .bss: malloc's heap starts here
extern char _stack_size[];

// The global heap, defined (and constructed) with the other globals of the
// main file (0x002041F8).
extern BedMemory D_006E9800;

// One line of a parameter text, split by txtParse: a name, then maybe a
// value.
enum {
    TXT_NONE,       // name only
    TXT_INT,        // 123 or $7F
    TXT_FLOAT,      // 1.5
    TXT_STRING      // "text"
};

struct TxtToken {
    char *m_name;
    int m_type;     // TXT_*
    union {
        int m_int;
        float m_float;
        char *m_string;
    };
};

void *heapAlloc(int size);
void *heapAlloc(int size, const char *file, int line, int id);
void heapFree(void *p);

// 0x001056E8: theOut = theIn in fixed point with 15 fraction bits (VU0
// vftoi15), in the style of the SDK's sceVu0FTOI4Vector.
void vu0FTOI15Vector(int *theOut, const float *theIn)
{
    __asm__ __volatile__(
        "lqc2 $vf4, 0x0(%1)\n"
        "vftoi15.xyzw $vf5, $vf4\n"
        "sqc2 $vf5, 0x0(%0)\n"
        : : "r"(theOut), "r"(theIn));
}

// 0x001056F8: the same for one float (DogActor). The asm reads the argument
// from $f12 itself and clobbers $f12, so g++ also copies the input operand
// to $f0 (the game has that dead mov.s too).
int vu0FTOI15(float theValue)
{
    int ret;
    __asm__ __volatile__(
        "mfc1 %0, $f12\n"
        "qmtc2.ni %0, $vf4\n"
        "vftoi15.x $vf4, $vf4\n"
        "qmfc2.ni %0, $vf4\n"
        : "=r"(ret) : "f"(theValue) : "$f12");
    return ret;
}

// 0x00105710
char *txtSkipSpace(char *p)
{
    while (*p == ' ' || *p == '\t') {
        p++;
    }
    return p;
}

// 0x00105750: skips control characters (not the NUL).
char *txtSkipCtrl(char *p)
{
    while ((*p > 0 && *p < ' ') || *p == 0x7F) {
        p++;
    }
    return p;
}

// 0x001057A8: skips a name (letters, digits and '_').
char *txtSkipName(char *p)
{
    while ((*p >= '0' && *p <= '9') || (*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')
           || *p == '_') {
        p++;
    }
    return p;
}

// 0x00105838: the start of the next line, or 0 at the end of the text. Bytes
// from 0x80 up (Shift-JIS) count as text.
char *txtNextLine(char *theText)
{
    unsigned char *p = (unsigned char *)theText;
    while (*p >= ' ' || *p == '\t') {
        p++;
    }
    if (*p == '\0') {
        return 0;
    }
    char *next = txtSkipCtrl((char *)p);
    if (*next == '\0') {
        return 0;
    }
    return next;
}

// 0x001058A0: splits theText, one "name value" per line, into up to theMax
// tokens; returns how many. Ends names and strings with NULs in place.
// (MagSceneOption reads its settings with it.)
int txtParse(TxtToken *theToken, int theMax, char *theText)
{
    int n = 0;
    while (theText) {
        char *p = theText;
        theText = txtNextLine(p);
        p = txtSkipSpace(p);
        theToken->m_name = p;
        char *e = txtSkipName(p);
        if (*e == '\0') {
            theToken->m_type = TXT_NONE;
        } else {
            p = txtSkipSpace(e);
            *e = '\0';
            if (*p == '"') {
                p++;
                for (e = p; *e != '"' && *e != '\0'; e++) {
                }
                *e = '\0';
                theToken->m_type = TXT_STRING;
                theToken->m_string = p;
            } else if (*p == '$') {
                int value = 0;
                for (p++; isxdigit(*p); p++) {
                    char c = *p;
                    value *= 16;
                    value += (c >= 'a' ? c - 'a' + 10 : c >= 'A' ? c - 'A' + 10 : c - '0');
                }
                theToken->m_type = TXT_INT;
                theToken->m_int = value;
            } else if (*p >= '0' && *p <= '9') {
                int ival = 0;
                float fval = 0.0f;
                float div = 0.0f;
                while (isdigit(*p) || *p == '.') {
                    if (*p == '.') {
                        div = 10.0f;
                        fval = ival;
                    } else if (div == 0.0f) {
                        ival *= 10;
                        ival += *p - '0';
                    } else {
                        fval += (*p - '0') / div;
                        div *= 10.0f;
                    }
                    p++;
                }
                if (div == 0.0f) {
                    theToken->m_type = TXT_INT;
                    theToken->m_int = ival;
                } else {
                    theToken->m_type = TXT_FLOAT;
                    theToken->m_float = fval;
                }
            }
        }
        n++;
        theToken++;
        if (n >= theMax) {
            break;
        }
    }
    return n;
}

// 0x00295F00 (.data: g++ 2.96 puts zero-initialised globals there; the
// zero word after it is padding or an unused global)
int gFrameCount = 0;

// 0x00105B3C: once per frame (MagSystem).
void countFrame()
{
    gFrameCount++;
}

// 0x00105B54: operator new, from the global heap.
void *operator new(size_t size)
{
    return heapAlloc(size);
}

// 0x00105B68: new with the caller's file and line (unused).
void *operator new(size_t size, const char *file, int line, int id)
{
    return heapAlloc(size, file, line, id);
}

// 0x00105B7C
void *operator new[](size_t size)
{
    return heapAlloc(size);
}

// 0x00105B90 (unused)
void *operator new[](size_t size, const char *file, int line, int id)
{
    return heapAlloc(size, file, line, id);
}

// 0x00105BA4
void operator delete(void *p)
{
    if (p) {
        heapFree(p);
    }
}

// 0x00105BC4
void operator delete[](void *p)
{
    if (p) {
        heapFree(p);
    }
}

// 0x00105BE4: makes the global heap as big as malloc allows (in steps of
// 256 bytes), leaving room for the stack; create() then mallocs it.
void heapInit()
{
    int max = 0x1FFEFF0 - ((int)_end + ((int)_stack_size + 0x1000));
    max = (max >> 8) << 8;
    int size;
    void *p;
    do {
        for (size = max; size > 0; size -= 0x100) {
            p = malloc(size);
            if (p) {
                free(p);
                break;
            }
        }
        p = malloc(size);
    } while (p == 0);
    free(p);
    D_006E9800.create(size, 0);
}

// 0x00105C80
void heapExit()
{
    D_006E9800.destroy();
}

// 0x00105CA0 (the sound library's malloc too)
void *heapAlloc(int size)
{
    return D_006E9800.alloc(size, -1);
}

// 0x00105CC4: BedMemory's alignment attribute for 32, 64 or 128 bytes.
// The code tests 32 first: the switch has one more case below 32 that does
// nothing (its value is lost; 0 is a guess).
int heapAlignAttr(int align)
{
    int attr = 0;
    switch (align) {
    case 0:
        break;
    case 32:
        attr = 0;
        break;
    case 64:
        attr = 1;
        break;
    case 128:
        attr = 2;
        break;
    }
    return attr;
}

// 0x00105D08
void *heapAlloc(int size, int align)
{
    int attr = heapAlignAttr(align);
    return D_006E9800.alloc(size, attr);
}

// 0x00105D40
void *heapAlloc(int size, const char *file, int line, int id)
{
    return D_006E9800.alloc(size, file, line, id, -1);
}

// 0x00105D78
void *heapAlloc(int size, int align, const char *file, int line, int id)
{
    int attr = heapAlignAttr(align);
    return D_006E9800.alloc(size, file, line, id, attr);
}

// 0x00105DE0 (the sound library's realloc too)
void *heapRealloc(void *p, int size)
{
    return D_006E9800.realloc(p, size);
}

// 0x00105E08 (the sound library's free too)
void heapFree(void *p)
{
    D_006E9800.free(p);
}

// 0x00105E2C
void heapCheck()
{
    D_006E9800.check(0);
}
