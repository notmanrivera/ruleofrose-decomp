#include "ror.h"
#include "include_asm.h"
#include "mag/maglifebwn.h"
extern "C" void func_001249B4(MagLifeBwn *);
extern "C" int func_001233F4(MagLifeBwn *, int, int, int);
extern "C" void func_00125368(MagLifeBwn *);
extern int D_002EBB40[];
struct MagLifeBwnModeV {
    virtual void vfunc01();
    virtual void vfunc02(MagLifeBwn *);
};
extern "C" void func_0012481C(MagLifeBwn *, int, float);
extern "C" int func_00103F38();
extern "C" int func_00103F08();
extern "C" void func_00103EDC(int);
extern "C" int func_001252C4(MagLifeBwn *);
extern const char D_002EB208[];
extern "C" void func_00125A20(MagLifeBwn *, int);
extern "C" float func_001040A0();
extern "C" int func_00104004(DogVector *thePos, unsigned int *theOut, float theA);
extern "C" int Xiii_func_00125704(MagLifeBwn *, int) asm("func_00125704");
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern const char D_002EB870[];
extern "C" int Xi_func_00103F08() asm("func_00103F08");
extern "C" int Xi_func_00103F38() asm("func_00103F38");
typedef MagLifeBwn MagBwn;
extern "C" int func_00125704(MagBwn *self, int theA);
extern "C" void func_00125A90(MagBwn *self);
extern "C" void func_0011A14C(MagBwn *self);
extern "C" void func_0012498C(MagBwn *self);

extern "C" void MagLifeBwn__vfunc_16(MagLifeBwn *arg0, int arg1, int arg2, int arg3)
{
    int *next = arg0->m_nextMode;
    next[1] = -1;
    next[0] = arg1;
    arg0->m_nextMode[2] = arg2;
    arg0->m_nextMode[3] = arg3;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EAFA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EAFB0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EAFC8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EAFE0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EAFF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB010);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB028);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB048);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB068);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB088);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB0A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB0C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB0D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB0F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB108);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB120);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB138);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB150);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB168);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB180);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB198);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB1B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB1D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB1E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB1F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB200);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB208);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB210);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB218);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB220);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB228);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB230);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB238);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB248);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB250);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB260);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB270);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB278);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB288);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB298);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB2A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB2B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB2C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB2C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB2D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB2D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB2E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB2F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB308);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB310);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB318);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB328);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB338);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB340);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB348);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB358);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB368);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB378);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB388);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB390);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB398);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB3A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB3A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB3B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB3C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB3D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB3E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB3F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB3F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB408);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB418);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB428);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB438);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB448);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB458);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB468);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB478);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB488);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB498);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB4A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB4B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB4C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB4D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB4E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB4F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB500);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB508);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB510);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB520);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB530);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB540);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB550);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB560);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB570);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB580);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB590);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB598);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB5A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB5B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB5C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB5D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB5E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB5F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB608);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB618);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB620);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB630);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB640);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB650);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB660);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB670);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB680);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB690);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB6A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB6A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB6B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB6C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB6D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB6E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB6F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB708);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB718);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB728);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB738);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB748);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB758);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB770);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB778);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB788);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB798);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB7A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB7B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB7C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB7D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB7E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB7F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB800);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB810);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB820);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB830);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB840);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB848);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB858);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB860);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB870);

extern "C" int func_001233F4(MagLifeBwn *arg0, int arg1, int arg2, int arg3)
{
    int var_v0;

    if (arg1 < 0) {
        Xiiii_ror_assert((int) D_002EB870, 0x10E, (int) "theMode >= 0");
    }
    if ((arg0->m_unk00 != arg1) || (var_v0 = 0, (arg1 == 0))) {
        arg0->vfunc16(arg1, arg2, arg3);
        Xiii_func_00125704(arg0, 0);
        var_v0 = 1;
    }
    return var_v0;
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_0012349C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_0012391C);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_00123BB8);

extern "C" unsigned int func_00123F78(MagLifeBwn *arg0, const DogVector *arg1)
{
    DogVector pos;
    unsigned int oid;
    DogActor *actor = arg0->m_actor;
    pos.m_x = actor->m_unk40.m_x + arg1->m_x;
    pos.m_y = actor->m_unk40.m_y + arg1->m_y;
    pos.m_z = actor->m_unk40.m_z + arg1->m_z;
    int ret = func_00104004(&pos, &oid, func_001040A0());
    if (ret != 0) {
        return (((oid >> 23) & 0x1F) == 2) ? oid : 0;
    }
    return ret;
}

// NON_MATCHING: fn matches; D_002EB980 needs .align 3 in config/rodata_align_manual.tsv
#ifdef NON_MATCHING
extern "C" int func_00124008(MagLifeBwn *arg0, int thePosIndex, float theDist)
{
    int posidx = thePosIndex;
    float dist = theDist;

    if (posidx < 0 || posidx > ((arg0->m_unkCA0 - 1) << 16)) {
        ror_assert(D_002EB870, 0x2E3, "0 <= thePosIndex && thePosIndex <= ((m_num_search_line-1)<<16)");
    }

    do {
        if (!(0 <= posidx && posidx <= ((arg0->m_unkCA0 - 1) << 16))) {
            ror_assert(D_002EB870, 0x2E8, "0 <= posidx && posidx <= ((m_num_search_line-1)<<16)");
        }
        int maxIdx = (arg0->m_unkCA0 - 1) << 16;
        if (posidx >= maxIdx) {
            posidx = maxIdx;
            break;
        } else {
            unsigned int idx = (unsigned int)posidx >> 16;
            float len = arg0->m_pathPoints[idx].w;
            float rem = len * (float)(0x10000 - (posidx & 0xFFFF)) * (1.0f / 65536.0f);
            if (rem <= dist) {
                dist -= rem;
                posidx = (idx + 1) << 16;
            } else {
                posidx += (int)((dist * 65536.0f) / len);
                dist = 0.0f;
            }
        }
    } while (dist > 0.0f);

    return posidx;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_00124008);
#endif

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_00124150);

// NON_MATCHING: 20/22 differ, 1 reloc differs (size 0x58, game 0x54), 11 edits
#ifdef NON_MATCHING
extern "C" int message__10MagLifeBwniiPv(MagLifeBwn *arg0, int arg1, int arg2, void *arg3)
{
    if (arg0->m_actor != 0 && (unsigned int)arg1 < 0xAU) {
        if (arg0->m_nextMode[0] >= 0 && arg0->m_nextMode[0] == arg1) {
            return -2;
        }
        if (func_001233F4(arg0, arg1, arg2, (int)arg3) == 0) {
            return -1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", message__10MagLifeBwniiPv);
#endif

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB980);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB988);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB998);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB9A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB9B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB9C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB9D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB9E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EB9F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBA08);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBA18);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_0012481C);

extern "C" void func_0012498C(MagBwn *self)
{
    self->m_actor->func_0010B328(0, -1, 0);
}


INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_001249B4);

extern "C" void func_00124D7C(MagLifeBwn *arg0)
{
    int mode = arg0->m_unkCB8;
    const char *nodes[] = {
        "Bip01 L Clavicle",
        "Bip01 L UpperArm",
        "Bip01 L Forearm",
        "Bip01 L Hand",
        "Bip01 L Finger0",
        0,
    };
    if (mode == 3) {
        if (arg0->m_actor->m_motion_now.m_sub[1].m_no < 0) {
            arg0->m_actor->func_0010B620(1, "w_blend_wait", nodes);
        }
    } else if (arg0->m_actor->m_motion_now.m_sub[1].m_no >= 0) {
        arg0->m_actor->func_0010B328(1, -1, nodes);
    }
}

extern "C" void func_00124E18(MagBwn *self)
{
    self->m_actor->func_0010B328(1, -1, 0);
}


extern "C" void live__10MagLifeBwn(MagLifeBwn *arg0)
{
    if (arg0->m_actor == 0) {
        return;
    }
    if (arg0->m_unkCE4 != 0) {
        func_001249B4(arg0);
        return;
    }
    arg0->m_unkCBC = arg0->m_unkCB8;
    arg0->m_unk04++;
    arg0->m_unkCB8 = func_001252C4(arg0);
    arg0->func_0011A738(D_002EBB40);
    func_001249B4(arg0);
    if (arg0->m_unkCEC == 0) {
        func_001233F4(arg0, 2, 0, 0);
    }
    if (func_00125704(arg0, 1) == 0) {
        if (arg0->m_unkCEC != 0) {
            ((MagLifeBwnModeV *)arg0->m_unkCEC)->vfunc02(arg0);
        }
        if (arg0->m_unkCC4 > 0) {
            arg0->m_unkCAC = 0;
        } else {
            arg0->m_unkCC4 = 1;
            arg0->m_unkCAC++;
        }
    }
    func_00125368(arg0);
}

extern "C" void reset4MapJump__10MagLifeBwn(MagLifeBwn *arg0)
{
    arg0->MagLifeControlChara::reset4MapJump();
    arg0->message(0, 0, 0);
    arg0->func_0011A130();
    func_0012481C(arg0, -1, 0.0f);
    arg0->m_unkCAC = 0;
    arg0->m_unkCD0 = -1;
    int maxHp = func_00103F38() / 5;
    int hp = func_00103F08();
    if (hp < maxHp) {
        hp += maxHp / 4;
        if (hp > maxHp) {
            hp = maxHp;
        }
        func_00103EDC(hp + 1);
    }
    arg0->m_unkCB8 = func_001252C4(arg0);
}

// NON_MATCHING: 54/57 differ, 2 relocs differ (size 0xE4, game 0xF0), 22 edits
#ifdef NON_MATCHING
void vecLerp(float *theOut, const float *a, const float *b, float t);
float vecYaw(const float *v);
extern "C" void func_00125014(MagLifeBwn *arg0)
{
    DogVector pos;
    unsigned int val = arg0->m_unkCA8;
    int frac = val & 0xFFFF;

    if (frac != 0) {
        int idx = val >> 16;
        vecLerp(&pos.m_x, &arg0->m_pathPoints[idx].x, &arg0->m_pathPoints[idx + 1].x,
                (float)frac * (1.0f / 65536.0f));
    } else {
        int idx = val >> 16;
        pos = *(DogVector *)&arg0->m_pathPoints[idx];
    }

    DogVector actorPos = arg0->m_actor->m_unk40;
    pos.m_x -= actorPos.m_x;
    pos.m_z -= actorPos.m_z;
    pos.m_w = 1.0f;
    pos.m_y -= actorPos.m_y;
    arg0->m_unkCB4 = vecYaw(&pos.m_x);
    arg0->m_unkCB0 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_00125014);
#endif

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_00125104);

extern "C" int func_001252C4(MagLifeBwn *)
{
    float temp_f1;
    int temp_s0;
    int var_v0;

    temp_s0 = Xi_func_00103F08();
    temp_f1 = (float) temp_s0 / (float) Xi_func_00103F38();
    var_v0 = 4;
    if (!(temp_f1 <= 0.0f)) {
        var_v0 = 3;
        if (!(temp_f1 < 0.19999999180436134f)) {
            var_v0 = 2;
            if (!(temp_f1 < 0.3999999836087227f)) {
                var_v0 = 1;
                if (!(temp_f1 < 0.7999999672174454f)) {
                    var_v0 = 0;
                }
            }
        }
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_00125368);

extern "C" void setActor__10MagLifeBwnP8DogActorii(MagBwn *self, DogActor *theActor, int theA, int theB)
{
    self->m_unk54 = theB;
    self->m_unk50 = theA;
    self->m_actor = theActor;
    if (!theActor) {
        func_0012498C(self);
    }
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBB40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBB70);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBB78);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBB80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBB88);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBB90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBB98);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBBA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBBA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBBB0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBBB8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBBC0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwn", func_00125704);

extern "C" void func_001258A4(MagLifeBwn *arg0)
{
    arg0->m_unkCE4 = 1;
    if (arg0->m_actor != 0) {
        arg0->m_unkCE8 = arg0->m_actor->getMotionNo();
        int st = arg0->func_0011A028();
        int flag = (st >= 0) ? (arg0->m_tbl_motion_state[st].m_flag & 0xF0) : 0x30;
        if (flag != 0) {
            if (flag == 0x10) {
                arg0->m_actor->func_0010B1B0(arg0->m_actor->func_0010AA5C(D_002EB208), 0, 0.016666694f, -1, -1);
            } else if (flag == 0x30) {
                arg0->m_actor->m_motion_now.setMainSpeed(0.0f);
            }
        }
    }
    func_00125A20(arg0, 0);
}

extern "C" void func_00125980(MagBwn *self)
{
    self->m_unkCE4 = 0;
    DogActor *actor = self->m_actor;
    if (actor) {
        if (actor->m_motion_now.getMainMotionNo() != self->m_unkCE8) {
            return func_00125A90(self);
        }
        self->m_actor->m_motion_now.setMainSpeed(0.016666694f);
    }
}


extern "C" void renderPostProcess__10MagLifeBwn(MagBwn *self)
{
    if (self->m_actor && self->m_unkCE4 == 0) {
        func_0011A14C(self);
    }
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBBF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBC08);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwn", D_002EBC20);
