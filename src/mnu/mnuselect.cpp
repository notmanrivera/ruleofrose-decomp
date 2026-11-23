#include "ror.h"
#include "include_asm.h"
#include "mnu/mnucommon.h"

extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int func_001A074C(MnuSub104 *self);
extern "C" int func_001A0788(MnuSub104 *self, int arg1);
extern "C" int func_001A0860(MnuSub104 *self);
extern "C" void func_001A08D4(MnuSub104 *self);
extern "C" void func_001A0950(MnuSub104 *self);
extern "C" void func_001A0BDC(MnuSub104 *self, int arg1);
extern "C" int func_001A0BE4(MnuSub104 *self, int arg1);
extern "C" void *alloc__9BedMemoryiPCciii(void *, int, const char *, int, int, int);
extern char D_006E9800[];

extern "C" int func_001A066C(MnuSub104 *self)
{
    self->m_open = 0;
    return func_001A0860(self);
}


extern "C" void func_001A0684(MnuSub104 *arg0, int arg1)
{
    func_001A074C(arg0);
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}


extern "C" int func_001A06D4(MnuSub104 *self, int arg1)
{
    return func_001A0788(self, arg1);
}


// NON_MATCHING: 2/25 differ, 2 edits
#ifdef NON_MATCHING
extern "C" int func_001A06E8(MnuSub104 *self)
{
    if (self->m_open == 1) {
        return -1;
    }
    register int v100 PS2_REG("$5") = 100;
    do {
    self->m_unk5C = 0x7FFF;
    self->m_open = 1;
    self->m_unk60 = -1;
    self->m_active = 0;
    self->m_unk58 = v100;
    self->m_unk68 = 0;
    self->m_step = 0;
    self->m_mode = 0;
    self->m_subStep = 0;
    } while (0);
    self->m_unk54 = v100;
    func_001A08D4(self);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A06E8);
#endif


extern "C" int func_001A074C(MnuSub104 *self)
{
    if (self->m_open == 0) {
        return -1;
    }
    func_001A0950(self);
    self->m_open = 0;
    return 0;
}


extern "C" int func_001A0788(MnuSub104 *self, int arg1)
{
    int r = 0;
    if (self->m_open == 0) {
        return -1;
    }
    switch (self->m_step) {
    case 0:
        self->m_step = 1;
        break;
    case 1:
        self->m_step = 2;
        break;
    case 2:
        if (self->m_mode == 0) {
            switch (func_001A0BE4(self, arg1)) {
            case 0:
                break;
            case 1:
                self->m_step = 4;
                break;
            }
        }
        func_001A0BDC(self, arg1);
        break;
    case 4:
        self->m_step = 5;
    case 3:
    case 5:
    default:
        r = 1;
        break;
    }
    return r;
}


// NON_MATCHING: 6/29 differ (size 0x74 == game 0x74; $v1/$a0 swapped in 2nd loop)
#ifdef NON_MATCHING
extern "C" int func_001A0860(MnuSub104 *self)
{
    for (int i = 0; i < 7; i++) {
        self->m_cursor[i] = 0;
    }
    self->m_max[0] = 1;
    self->m_unk6C = 0;
    self->m_max[1] = 2;
    self->m_active = 0;
    self->m_max[2] = 2;
    self->m_unk60 = -1;
    for (int i = 0; i < 32; i++) {
        self->m_lines[i] = 0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A0860);
#endif


INCLUDE_ASM("asm/nonmatchings/mnu/mnuselect", func_001A08D4);
