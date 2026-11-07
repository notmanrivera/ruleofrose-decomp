#include "ror.h"
#include "include_asm.h"
#include "sdk/string.h"
struct BgIter {
    char *m_top;                    // +0x00
    int m_unk04;
    int m_end;                      // +0x08
    int m_no;                       // +0x0C
    union {
        char m_name[0xC];           // +0x10
        struct {
            int m_name0;
            int m_name1;
            int m_name2;
        };
    };
};
extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" int func_001FCC68(BgIter *self, const int *theName);
extern "C" int func_001BE564(void *theReader, int theA);

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_001FCC20(BgIter *self)
{
    int r = 0;
    if (!self->m_end) {
        self->m_no++;
        r = 1;
        if (*(int *)(self->m_top + self->m_no * 0x10) == 0) {
            r = 0;
            self->m_end = 1;
        }
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FCC20);
#endif


extern "C" int func_001FCC68(BgIter *self, const int *theName)
{
    if (self->m_end) {
        return 0;
    }
    self->m_no++;
    int *p = (int *)(self->m_top + self->m_no * 0x10);
    while (*p) {
        if (p[0] == theName[0] && p[1] == theName[1]) {
            return 1;
        }
        p += 4;
        self->m_no++;
    }
    self->m_end = 1;
    return 0;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_001FCCF4(BgIter *self, const char *theName)
{
    int name[2];
    memset(name, 0, 8);
    strncpy((char *)name, theName, 8);
    func_001FCC68(self, name);
}
#else
INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FCCF4);
#endif


extern "C" void func_001FCD4C(BgIter *self, int theNo)
{
    self->m_no = theNo;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" char *func_001FCD54(BgIter *self)
{
    char *name = self->m_name;
    self->m_name2 = 0;
    self->m_name1 = 0;
    self->m_name0 = 0;
    strncpy(name, self->m_top + self->m_no * 0x10, 8);
    return name;
}
#else
INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FCD54);
#endif


extern "C" char *func_001FCDA4(BgIter *self)
{
    return self->m_top + self->m_no * 0x10;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" char *func_001FCDB8(BgIter *self)
{
    return self->m_top + *(int *)(self->m_top + self->m_no * 0x10 + 8);
}
#else
INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FCDB8);
#endif


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_001FCDD4(BgIter *self)
{
    return *(int *)(self->m_top + *(int *)(self->m_top + self->m_no * 0x10 + 8));
}
#else
INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FCDD4);
#endif


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_001FCDF4(BgIter *self)
{
    return *(int *)(self->m_top + self->m_no * 0x10 + 0xC);
}
#else
INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FCDF4);
#endif


extern "C" void TskBGLoad__vfunc_03(void) {
}

extern "C" void term__9TskBGLoad(void) {
}

extern "C" int TskBGLoad__vfunc_04(char *self)
{
    return func_001BE564(self + 4, 1) == 0;
}


INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FCE40);

INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FCEF8);

INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", TskBGLoadArea__vfunc_07);

INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", TskBGLoadArea__vfunc_04);

INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", func_001FD200);

INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", TskBGLoadMap__vfunc_07);

INCLUDE_ASM("asm/nonmatchings/task/tsk_bg_load", TskBGLoadMap__vfunc_04);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_bg_load", D_002FF010);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_bg_load", D_002FF020);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_bg_load", D_002FF028);
