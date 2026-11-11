#include "ror.h"
#include "include_asm.h"
#include "game/gamman.h"
#include "dog/dogentity.h"
extern "C" int func_001FB5D4(int theA, int theB);
extern "C" void func_001FAC60(int theKind, int theOwner, int theB, DogVector *thePos, int theC, int theD, int theE);
extern char *D_007A3350;
extern const char D_002EA208[];
extern "C" void func_001DC48C(void *theObj, int theId, int theA, int *theOut);
// The object at +0x22220 of the game manager. Through a pointer, as an inline
// method of GamMan would reach it: the game adds the offset at run time,
// where `(char *)&D_007812C0 + 0x22220` folds into the symbol's address.
static inline void *gamSub22220() { GamMan *g = &D_007812C0; return (char *)g + 0x22220; }
extern "C" int func_0011CAF8(void *self, int theA);
extern char D_007B2140;
extern unsigned short D_007A34CC;
extern short D_007A32CC;
extern "C" void func_001CB4F0(void *, int, int *);
extern "C" void func_001CB460(void *, int, int *);
extern "C" void func_001C89E4(void *);
extern "C" void func_001C8CA4(void *, int, int);
extern "C" void func_001C898C(void *);
extern "C" void func_001C899C(void *);
extern "C" int func_001C8604(void *, int);
extern "C" void func_001639B4(void *);
extern "C" void func_0016373C(void *);
extern "C" int func_001D56F4(void *, u_long128 *, int *);

extern "C" int func_0011C464(void *self)
{
    int v = 0;
    func_001CB460(&D_007812C0, 0x1B, &v);
    return v;
}

extern "C" void func_0011C494(void *self, int theValue)
{
    int v = theValue;
    func_001CB4F0(&D_007812C0, 0x1B, &v);
}


extern "C" int func_0011C4C0(void *self)
{
    int v = 0;
    func_001CB460(&D_007812C0, 0x1C, &v);
    return v;
}


extern "C" int func_0011C4F0(void *self)
{
    int v = 0;
    func_001CB460(&D_007812C0, 0, &v);
    return v;
}


extern "C" int func_0011C520(void *self)
{
    return D_007A34CC;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C52C);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA1E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc2", D_002EA208);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C64C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011C974);

extern "C" void func_0011CA60(void *self, int theA)
{
    DogVector pos;
    char *actor = *(char **)((char *)self + 0x58);
    pos.m_x = *(float *)(actor + 0x40);
    pos.m_y = *(float *)(actor + 0x44);
    pos.m_z = *(float *)(actor + 0x48);
    int b = func_001FB5D4(theA, 2);
    func_001FAC60(0xB, D_007A3350 ? *(int *)(D_007A3350 + 0x100) : 0, b, &pos, 2, theA, 0);
}

extern "C" int func_0011CAF8(void *self, int theId)
{
    if (theId <= 0) {
        return 2;
    }
    int attack_type = 0;
    func_001DC48C(gamSub22220(), theId & 0xFFFF, 0x27, &attack_type);
    if (!(attack_type >= 0 && attack_type < 0x10000)) ror_assert(D_002EA208, 0x14E, "attack_type >= 0 && attack_type < 0x10000");
    return attack_type;
}

extern "C" int func_0011CB70(void *self, int theA)
{
    int no = *(int *)((char *)self + 0x1AC);
    if (no >= 0) {
        return no;
    }
    int r;
    switch (func_0011CAF8(self, theA)) {
    case 5:
        r = 3;
        break;
    case 4:
        r = 2;
        break;
    case 6:
        r = 1;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

extern "C" void func_0011CBD0()
{
    return func_001C89E4(&D_007812C0);
}


extern "C" int func_0011CBEC()
{
    return 1;
}


extern "C" void func_0011CBF4(void *self, int theA)
{
    return func_001C8CA4(&D_007812C0, theA, 0);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifepc2", func_0011CC14);

extern "C" int func_0011CCD4(void *self, const u_long128 *thePos, int *theOut)
{
    int out[8];
    DogVector pos(*(const DogVector *)thePos);
    int r = func_001D56F4(&D_007812C0, (u_long128 *)&pos, out);
    if (theOut) {
        *theOut = out[4];
    }
    return r;
}


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
