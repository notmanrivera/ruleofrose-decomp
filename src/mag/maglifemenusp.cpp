#include "ror.h"
#include "include_asm.h"
#undef ASSERT_FILE
#define ASSERT_FILE D_002ED070
extern const char D_002ED070[];
extern const char D_002ED088[];
struct MagMenuSp {
    int m_unk00[0x30 / 4];
    void *m_scene;                  // +0x30
    int m_unk34[3];
    int m_chara[5];                 // +0x40
};
extern "C" void func_00139010(void *theScene, int theN);
extern "C" void func_0013CA10(void *theScene);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial__vfunc_09);

extern "C" void MagLifeMenuSpecial__vfunc_10(MagMenuSp *self)
{
    if (self->m_chara[0] >= 0) {
#line 76
        ASSERT_S(self->m_scene, D_002ED088);
        int *p = self->m_chara;
        for (int i = 0; i < 5; i++) {
            func_00139010(self->m_scene, *p);
            *p = -1;
            p++;
        }
        func_0013CA10(self->m_scene);
    }
}


extern "C" int MagLifeMenuSpecial__vfunc_11(MagMenuSp *self)
{
    return self->m_chara[4] >= 0;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial__vfunc_12);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECEF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECF08);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECF20);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECF38);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECF50);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECF68);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECF80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECF98);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECFB0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECFC8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECFE0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ECFF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED010);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED028);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED040);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED070);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED088);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED090);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0C0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", func_0012E23C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_09);

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void MagLifeMenuSpecial2__vfunc_10(MagMenuSp *self)
{
    if (self->m_chara[0] >= 0) {
#line 430
        ASSERT_S(self->m_scene, D_002ED088);
        int *p = &self->m_chara[3];
        for (int i = 0; i < 4; i++) {
            func_00139010(self->m_scene, *p);
            *p = -1;
            p--;
        }
        func_0013CA10(self->m_scene);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_10);
#endif


extern "C" int MagLifeMenuSpecial2__vfunc_11(MagMenuSp *self)
{
    return self->m_chara[3] >= 0;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_12);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0F8);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_06);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", func_0012EEF0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_01);
