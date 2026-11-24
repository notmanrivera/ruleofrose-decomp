#include "ror.h"
#include "include_asm.h"
struct MagMenuSp2 {
    int m_mode;                     // +0x00
    int m_unk04;                    // +0x04
    int m_unk08;                    // +0x08
    int m_unk0C;                    // +0x0C
    int m_unk10;                    // +0x10
    void *m_vtable;                 // +0x14
    int m_unk18;                    // +0x18
    int m_unk1C;                    // +0x1C
    void *m_scene20;                // +0x20
    int m_hide;                     // +0x24
    int m_unk28;                    // +0x28
    int m_unk2C;                    // +0x2C
    void *m_scene;                  // +0x30
    int m_unk34;                    // +0x34
    int m_unk38;                    // +0x38
    int m_unk3C;                    // +0x3C
    int m_chara[4];                 // +0x40
    int m_unk50;                    // +0x50
    int m_unk54[3];                 // +0x54
    int m_unk60[3];                 // +0x60
    int m_unk6C;                    // +0x6C
};
extern void *_vt$19MagLifeMenuSpecial2[];
struct MagMenuSp1 {
    int m_mode;                     // +0x00
    int m_unk04;                    // +0x04
    int m_unk08;                    // +0x08
    int m_unk0C;                    // +0x0C
    int m_unk10;                    // +0x10
    void *m_vtable;                 // +0x14
    int m_unk18;                    // +0x18
    int m_unk1C;                    // +0x1C
    void *m_scene20;                // +0x20
    int m_hide;                     // +0x24
    int m_unk28;                    // +0x28
    int m_unk2C;                    // +0x2C
    void *m_scene;                  // +0x30
    int m_unk34;                    // +0x34
    int m_unk38;                    // +0x38
    int m_unk3C;                    // +0x3C
    int m_chara[5];                 // +0x40
    int m_unk54;                    // +0x54
    int m_unk58[3];                 // +0x58
    int m_unk64[3];                 // +0x64
    int m_unk70;                    // +0x70
};
extern void *_vt$18MagLifeMenuSpecial[];
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_0013CA10(int) asm("func_0013CA10");
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern "C" int Xiiu_func_00139010(int, unsigned int) asm("func_00139010");
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

// D_002ECEF8: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECF08: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECF20: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECF38: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECF50: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECF68: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECF80: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECF98: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECFB0: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECFC8: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECFE0: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ECFF8: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ED010: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ED028: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

// D_002ED040: the end of mag/maglifemenu's .rodata now (config/splits_manual.tsv)

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED070);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED088);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED090);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0C0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial__vfunc_06);

extern "C" void func_0012E23C(MagMenuSp1 *self)
{
    int i;

#ifdef TARGET_PS2
    *(u_long128 *)&self->m_mode = 0;
#else
    self->m_mode = self->m_unk04 = self->m_unk08 = self->m_unk0C = 0;
#endif
    self->m_unk10 = 1;
    self->m_unk04 = -1;
    self->m_mode = 0;
    self->m_hide = 0;
    self->m_scene20 = 0;
    self->m_vtable = _vt$18MagLifeMenuSpecial;
    self->m_scene = 0;
    self->m_unk54 = 0;
    self->m_unk70 = 0;
    for (i = 0; i < 5; i++) {
        self->m_chara[i] = -1;
    }
    self->m_unk34 = -1;
    self->m_scene = 0;
    for (i = 0; i < 3; i++) {
        self->m_unk58[i] = 0;
        self->m_unk64[i] = 0;
    }
    self->m_unk04 = -1;
    self->m_mode = 0;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_09);

extern "C" void MagLifeMenuSpecial2__vfunc_10(MagMenuSp *self)
{
    if (self->m_chara[0] >= 0) {
#line 430
        ASSERT_S(self->m_scene, D_002ED088);
        int *p;
        int i;
        for (i = 3, p = &self->m_chara[3]; i >= 0; i--) {
            func_00139010(self->m_scene, *p);
            *p = -1;
            p--;
        }
        func_0013CA10(self->m_scene);
    }
}


extern "C" int MagLifeMenuSpecial2__vfunc_11(MagMenuSp *self)
{
    return self->m_chara[3] >= 0;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_12);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED0F8);

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_06);

extern "C" void func_0012EEF0(MagMenuSp2 *self)
{
    int i;

#ifdef TARGET_PS2
    *(u_long128 *)&self->m_mode = 0;
#else
    self->m_mode = self->m_unk04 = self->m_unk08 = self->m_unk0C = 0;
#endif
    self->m_unk10 = 1;
    self->m_unk04 = -1;
    self->m_mode = 0;
    self->m_hide = 0;
    self->m_scene20 = 0;
    self->m_vtable = _vt$19MagLifeMenuSpecial2;
    self->m_scene = 0;
    self->m_unk50 = 0;
    self->m_unk6C = 0;
    for (i = 0; i < 4; i++) {
        self->m_chara[i] = -1;
    }
    self->m_unk34 = -1;
    self->m_scene = 0;
    for (i = 0; i < 3; i++) {
        self->m_unk54[i] = 0;
        self->m_unk60[i] = 0;
    }
    self->m_unk04 = -1;
    self->m_mode = 0;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifemenusp", MagLifeMenuSpecial2__vfunc_01);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED148);
INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED158);
INCLUDE_RODATA("asm/nonmatchings/mag/maglifemenusp", D_002ED170);
