#include "ror.h"
#include "include_asm.h"
struct MnuSel;
#define I(p, off) (*(int *)((char *)(p) + (off)))
extern "C" void __builtin_delete(void *);
extern "C" void func_001A0860(void *self);
extern "C" void func_001A074C(MnuSel *self);
extern "C" void func_001A0788(MnuSel *self);
extern "C" void func_001A08D4(MnuSel *self, int theA);

extern "C" void func_001A066C(int *self)
{
    *self = 0;
    return func_001A0860(self);
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_001A0684(MnuSel *self, int theFlag)
{
    func_001A074C(self);
    if (theFlag & 1) {
        __builtin_delete(self);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A0684);
#endif


extern "C" void func_001A06D4(MnuSel *self)
{
    return func_001A0788(self);
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_001A06E8(MnuSel *self)
{
    int r = -1;
    if (I(self, 0) != 1) {
        I(self, 0x5C) = 0x7FFF;
        I(self, 0) = 1;
        I(self, 0x70) = 0;
        I(self, 0x60) = -1;
        I(self, 0x58) = 100;
        I(self, 0x68) = 0;
        I(self, 0x3C) = 0;
        I(self, 0x40) = 0;
        I(self, 0x44) = 0;
        I(self, 0x54) = 100;
        func_001A08D4(self, 1);
        r = 0;
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A06E8);
#endif


INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A074C);

INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A0788);

INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A0860);

INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A08D4);
