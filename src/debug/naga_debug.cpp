// debug/naga_debug.cpp: a debug file loader and its assert handler copy.
//
// Matching decompilation. The alloc call must stay on line 111 (0x6F): the
// original __LINE__ is compiled into the code. Names are ours.

#include "bed/bedmemory.h"
#include "utl/filereader.h"

extern BedMemory D_006E9800;        // the global heap

extern "C" int func_00260110(const char *theFormat, ...);   // SDK printf
extern "C" int func_001BE768(const char *theName);

// 0x00216728: this file's own copy of the assert handler (ror_assert at
// 0x00215A30 is another copy). Never returns.
static void assertFail(const char *theFile, int theLine, const char *theExpr)
{
    func_00260110("Assertion Failed: %s(%d)   %s\n", theFile, theLine, theExpr);
    for (;;) {
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
        __asm__ volatile("nop");
    }
}

// 0x00216768: reads the whole file theName into a new block of the global
// heap and returns it.
void *nagaLoadFile(const char *theName)
{
    FileReader reader;
    int size = func_001BE768(theName);













































































    void *p = D_006E9800.alloc(size, __FILE__, __LINE__, 0, 2);
    FileReadReq req;
    req.m_unk08 = 1;
    req.m_name = theName;
    req.m_unk14 = 0;
    req.m_offset = 0;
    req.m_buf = p;
    req.m_size = size;
    req.m_unk20 = 1;
    reader.func_001BE524(&req, 0);
    return p;
}
