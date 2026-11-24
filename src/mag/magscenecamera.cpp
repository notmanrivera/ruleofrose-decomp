#include "include_asm.h"
#include "mag/magscene.h"
#include "sdk/math.h"
extern const char D_002EE5D0[];
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_RODATA("asm/nonmatchings/mag/magscenecamera", D_002EE5D0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenecamera", D_002EE5E8);

INCLUDE_ASM("asm/nonmatchings/mag/magscenecamera", func_0013C664);

extern "C" void func_0013C928(void) {
}

extern "C" void func_0013C930(MagScene *arg0)
{
    arg0->getCamera()->save();
    arg0->m_unk2AD84 = arg0->m_unk2AD50;
    arg0->m_unk2AD88 = arg0->m_unk2AD58;
    arg0->m_unk2AD8C = arg0->m_unk2AD5C;
    arg0->m_unk2AD90 = arg0->m_unk2AD60;
    arg0->m_unk2AD94 = arg0->m_unk2AD64;
    arg0->m_unk2AD98 = arg0->m_unk2AD68;
    arg0->m_unk2AD80++;
}

INCLUDE_ASM("asm/nonmatchings/mag/magscenecamera", func_0013CA10);

INCLUDE_ASM("asm/nonmatchings/mag/magscenecamera", func_0013CAF0__8MagSceneii);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenecamera", D_002EE768);

INCLUDE_RODATA("asm/nonmatchings/mag/magscenecamera", D_002EE778);

INCLUDE_ASM("asm/nonmatchings/mag/magscenecamera", func_0013D240);

extern "C" float func_0013D4D0(int arg0)
{
    int temp_v0;

    temp_v0 = *(int *)((M2C_FIELD(arg0, int *, 0x2AD64) * 4) + M2C_FIELD(((M2C_FIELD(arg0, int *, 0x2AD68) * 0x520) + arg0), int *, 0x29A3C));
    return (float) M2C_FIELD(temp_v0, int *, 0x20) + M2C_FIELD(temp_v0, float *, 0x28);
}

extern "C" void func_0013D52C(MagScene *arg0, float fparg0)
{
    float ipart;
    MagUnk29890Sub *p = (*(MagUnk29890 (*)[3])&arg0->m_unk29890)[arg0->m_unk2AD68].m_unk1AC[arg0->m_unk2AD64];
    p->m_unk28 = modff(fparg0, &ipart);
    p->m_unk20 = (int)ipart;
}

extern "C" int func_0013D5AC__8MagScenePi(int arg0, int arg1)
{
    if (arg1 != 0) {
        (*(int *)(int *)((char *)(arg1) + 0x0)) = (int) (*(int *)(int *)((char *)(arg0) + 0x2AD50));
        (*(int *)(int *)((char *)(arg1) + 0x4)) = (int) (*(int *)(int *)((char *)(arg0) + 0x2AD58));
    }
    return (*(int *)(int *)((char *)(arg0) + 0x2AD50));
}


INCLUDE_ASM("asm/nonmatchings/mag/magscenecamera", func_0013D5E4);

INCLUDE_ASM("asm/nonmatchings/mag/magscenecamera", func_0013D8F8);

INCLUDE_ASM("asm/nonmatchings/mag/magscenecamera", func_0013DFE0);

extern "C" void func_0013E190(MagScene *self, const DogVector *thePos, int theI, int theMax, float theF)
{
    if (!thePos) {
        ror_assert(D_002EE5D0, 0x398, "thePos");
    }
    if (!(theI >= 0 && theI < theMax)) {
        ror_assert(D_002EE5D0, 0x399, "theI >= 0 && theI < theMax");
    }
    if (!(theF >= 0.0f && theF <= 1.0f)) {
        ror_assert(D_002EE5D0, 0x39A, "theF >= 0.0f && theF <= 1.0f");
    }
    const DogVector *p1 = thePos + theI;
    float z = p1->m_z;
    float y = p1->m_y;
    float x = p1->m_x;
    const DogVector *p2 = thePos + (theI + 1) % theMax;
    if (theF > 0.0f) {
        x += (p2->m_x - x) * theF;
        y += (p2->m_y - y) * theF;
        z += (p2->m_z - z) * theF;
    }
    DogCamera *cam = self->getCamera();
    cam->m_unk40.m_x = x;
    cam->m_unk40.m_y = y;
    cam->m_unk40.m_z = z;
    cam->m_unk90 = 1;
}
