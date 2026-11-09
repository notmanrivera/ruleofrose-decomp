#include "ror.h"
#include "include_asm.h"
#include "game/gamman.h"
extern char D_007B2140;
extern unsigned short D_007A34CC;
extern short D_007A32CC;
extern "C" void func_001CB4F0(void *, int, int *);
extern "C" void func_001CB460(void *, int, int *);
extern "C" void func_001C89E4(void *);
extern "C" void func_001C8CA4(void *, int);
extern "C" void func_001C898C(void *);
extern "C" void func_001C899C(void *);
extern "C" int func_001C8604(void *, int);
extern "C" void func_001639B4(void *);
extern "C" void func_0016373C(void *);
extern "C" void func_001D56F4(void *, u_long128 *, int *);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C464);

extern "C" void func_0011C494(void *self, int theValue)
{
    int v = theValue;
    func_001CB4F0(&D_007812C0, 0x1B, &v);
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_0011C4C0(void *self)
{
    int v;
    func_001CB460(&D_007812C0, 0x1C, &v);
    return v;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C4C0);
#endif


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_0011C4F0(void *self)
{
    int v;
    func_001CB460(&D_007812C0, 0, &v);
    return v;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C4F0);
#endif


extern "C" int func_0011C520(void *self)
{
    return D_007A34CC;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C52C);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA1E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA208);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C64C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C974);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CA60);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CAF8);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CB70);

extern "C" void func_0011CBD0()
{
    return func_001C89E4(&D_007812C0);
}


extern "C" int func_0011CBEC()
{
    return 1;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_0011CBF4()
{
    return func_001C8CA4(&D_007812C0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CBF4);
#endif


INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CC14);

// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" void func_0011CCD4(void *self, const u_long128 *thePos, int *theOut)
{
    int out[8];
    u_long128 pos = *thePos;
    func_001D56F4(&D_007812C0, &pos, out);
    if (theOut) {
        *theOut = out[4];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CCD4);
#endif


INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CD20);

extern "C" int func_0011CE50(void *self)
{
    return D_007A32CC;
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA280);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CE5C);

extern "C" void func_0011D028()
{
    return func_001639B4(&D_007B2140);
}


extern "C" int func_0011D044()
{
    return func_001C8604(&D_007812C0, 0) != 0;
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA298);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA2A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA2B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA2C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA2D0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011D06C);

extern "C" void func_0011D15C()
{
    return func_001C898C(&D_007812C0);
}


extern "C" void func_0011D178(char *self)
{
    func_001C899C(&D_007812C0);
    (*(int *)(self + 0x118))++;
}


extern "C" void func_0011D1B0()
{
    return func_0016373C(&D_007B2140);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011D1CC);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA340);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA378);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA3F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA3F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA408);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA410);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA418);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA420);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA428);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA430);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA438);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA440);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA450);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011D3D0);
