#include "include_asm.h"
#define MAGLIFE_EXTERNAL_RTTI
#include "mag/maglife.h"
#include "bed/bedpad.h"
class MagLifeTest : public MagLifeControlChara {
public:
    int m_unk80;                    // +0x80
};
static inline unsigned int padTriggerU(const BedPad *p) { return p->m_trigger; }
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00130A2C(...) asm("func_00130A2C");
extern "C" int X_func_0021B550(...) asm("func_0021B550");

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_001308BC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_00130A2C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_00130C34);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", func_00130DA4);

extern "C" void func_00130DE0(int arg0, int arg1)
{
    (*(int *)(int *)((char *)(arg0) + 0x30)) = arg1;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", MagLifeNoise__vfunc_06);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED3C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED3D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED408);

INCLUDE_ASM("asm/nonmatchings/mag/maglifetest", live__11MagLifeTest);

extern "C" void MagLifeTest__vfunc_16(MagLifeTest *self, BedPad *thePad)
{
    if (self->m_actor != 0 && ((padTriggerU(thePad) >> BEDPAD_BIT_R2) & 1)) {
        self->m_unk80 = 1;
    }
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifetest", D_002ED478);
