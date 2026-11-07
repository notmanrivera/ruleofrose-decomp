#include "ror.h"
#include "include_asm.h"
#define I(p, off) (*(int *)((char *)(p) + (off)))
extern "C" int func_0018BCC0(void *self, int theN);

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_0018BB28(char *self)
{
    int n = I(self, 0x90);
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += i < n ? I(self + i * 0x40, 0x1D0) : 0;
    }
    int r = 1;
    int v = I(self, 0x84);
    if (v < 0xED - total) {
        r = v >= 0xED;
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/spr/sprman", func_0018BB28);
#endif


INCLUDE_ASM("asm/nonmatchings/spr/sprman", func_0018BB8C);

INCLUDE_ASM("asm/nonmatchings/spr/sprman", func_0018BC18);

extern "C" int func_0018BCA8(void *self)
{
    return func_0018BCC0(self, 0x100);
}


INCLUDE_ASM("asm/nonmatchings/spr/sprman", func_0018BCC0);
