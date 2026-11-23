#include "include_asm.h"
#include "mag/maglifepc.h"

struct PcTarget {
    DogVector m_pos;
    DogVector m_unk10;
    int m_id;
    int m_unk24;
    int m_unk28[6];
};

struct PcTargetList {
    PcTarget m_item[32];
    int m_num;
};

struct PairF {
    float a;
    float b;
};

extern "C" void X_func_001026B0(int, int, int) asm("func_001026B0");
extern "C" int func_00103654(PcTargetList *theList, float theAngle);
extern "C" int func_0010376C(PcTargetList *theList, DogVector *theA, float theD, int theB, int theC, float theE);
extern "C" void X_func_00119F88(...) asm("func_00119F88");
extern "C" DogVector *X_func_00119FA4(MagLifePC *) asm("func_00119FA4");
extern "C" float X_func_00119FB0(MagLifePC *) asm("func_00119FB0");
extern "C" int Xiiiui_func_0011C1E8(MagLifePC *, int, unsigned int, int) asm("func_0011C1E8");
extern "C" float X_func_0011CE5C(MagLifePC *, DogVector *, int, int) asm("func_0011CE5C");
extern "C" int X_func_0011D15C(MagLifePC *) asm("func_0011D15C");
extern "C" int X_func_0011D1B0(MagLifePC *, int) asm("func_0011D1B0");
extern "C" int Xiiuui_func_0011D1CC(MagLifePC *, unsigned int, unsigned int, int) asm("func_0011D1CC");
extern "C" int Xiiif_func_0011D3D0(MagLifePC *, int, float) asm("func_0011D3D0");
extern "C" int Xiiiiiif_func_0011D7C0(MagLifePC *, const char *, int, const char *, int, float) asm("func_0011D7C0");
extern "C" int Xii_func_0011DFD0(MagLifePC *) asm("func_0011DFD0");
extern "C" float func_0012BC20(MagLifePC *arg0, DogVector *arg1);
extern "C" const char *func_0012C104(MagLifePC *arg0, unsigned int theWeapon, unsigned int theHeight, unsigned int theCombo);
extern "C" int func_0012CAA4(MagLifePC *arg0, const float *arg1, int arg2);
extern "C" void Xiiii_ror_assert(const char *, int, const char *) asm("ror_assert");
extern "C" float Xf_vecDistXZ__FPCfT0(const float *, const float *) asm("vecDistXZ__FPCfT0");
void vecDirToRot(float *theDir, float *theRot);

extern const char *D_00298228[4][5][3];
extern const char D_002EC8B0[];
extern const PairF D_002EC9C8;
extern const PairF D_002EC9D0;
extern const PairF D_002EC9D8[4];
extern const PairF D_002EC9F8[4][3];
extern const PairF D_002ECA58[4][3];
extern const char D_002ECAD8[];
extern const char D_002ECAF8[];
extern const char D_002ECB18[];

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012B870);

extern "C" void func_0012BA2C(int arg0)
{
    int temp_v0 = *(int *)((char *)arg0 + 0x70);
    if (temp_v0 != 0) {
        X_func_00119F88(temp_v0);
    }
}

extern "C" int func_0012BA54(MagLifePC *arg0)
{
    if (arg0->m_unk00 == 0xB) {
        if (arg0->m_unk08 == 3) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012BA80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC4B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC4D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC4F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC510);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC530);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC550);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC570);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC590);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC5B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC5D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC5E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC608);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC628);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC648);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC668);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC680);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC6F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC708);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC718);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC720);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC730);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC740);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC750);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC760);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC770);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC780);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC790);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7B0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC7F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC800);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC810);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC820);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC830);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC840);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC850);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC860);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC870);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC880);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC890);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC8A0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC8B0);

extern "C" float func_0012BC20(MagLifePC *arg0, DogVector *arg1)
{
    DogActor *actor = arg0->m_actor;
    arg1->m_x = actor->m_unk40.m_x;
    arg1->m_y = actor->m_unk40.m_y;
    arg1->m_z = actor->m_unk40.m_z;
    arg1->m_y += -120.0f;
    if (arg0->m_actor == 0) {
        Xiiii_ror_assert(D_002EC8B0, 0xFB, "m_actor");
    }
    return arg0->m_actor->m_unk50.m_y;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012BC98);

extern "C" float func_0012BEDC(MagLifePC *arg0, float *theYaw, float *thePitch, const DogVector *thePos)
{
    DogVector pos = arg0->m_actor->m_unk40;
    DogVector dir;
    DogVector *dp = &dir;
    *dp = *thePos;
    dp->m_x -= pos.m_x;
    dp->m_y -= pos.m_y;
    dp->m_z -= pos.m_z;
    dp->m_w = 1.0f;
    DogVector rot;
    vecDirToRot(&dp->m_x, &rot.m_x);
    *theYaw = rot.m_y;
    *thePitch = rot.m_x;
    float d = *theYaw - arg0->m_actor->m_unk50.m_y;
    if (d < -DOG_PI) {
        d += DOG_PI2;
    } else if (d > DOG_PI) {
        d -= DOG_PI2;
    }
    return d;
}

extern "C" void func_0012C014(MagLifePC *arg0, float *arg1, float *arg2)
{
    int n = arg0->m_atk_height;
    PairF def = D_002EC9C8;
    const PairF *p;
    if (n >= 4) {
        p = &D_002EC9D0;
    } else {
        switch (arg0->m_atk_weapon) {
        case 0:
            p = &D_002EC9D8[n];
            break;
        case 1:
            p = &def;
            break;
        case 2:
            p = &D_002EC9F8[n][arg0->m_atk_combo];
            break;
        case 3:
            p = &D_002ECA58[n][arg0->m_atk_combo];
            break;
        default:
            p = &def;
            break;
        }
    }
    *arg1 = p->a;
    *arg2 = p->b;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC9C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC9D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC9D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002EC9F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECA58);

extern "C" const char *func_0012C104(MagLifePC *arg0, unsigned int theWeapon, unsigned int theHeight, unsigned int theCombo)
{
    if (theCombo >= 3U) {
        Xiiii_ror_assert(D_002EC8B0, 0x250, "theCombo >= 0 && theCombo < 3");
    }
    if (theWeapon >= 4U) {
        Xiiii_ror_assert(D_002EC8B0, 0x251, D_002ECAD8);
    }
    if (theHeight >= 5U) {
        Xiiii_ror_assert(D_002EC8B0, 0x252, D_002ECAF8);
    }
    if (theWeapon == 1 && X_func_0011D15C(arg0) <= 0) {
        return D_002ECB18;
    }
    return D_00298228[theWeapon][theHeight][theCombo];
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECAD8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECAF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB38);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB48);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB58);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB68);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB78);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECB90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBB0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBD0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBE0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECBF0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC20);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC30);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC50);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC70);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECC98);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCA0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCB8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCC8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCD8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCE8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECCF8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECD08);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECD18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECD28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepcbtl", D_002ECD38);

extern "C" void func_0012C1FC(MagLifePC *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    if ((unsigned int) (arg3 + 1) >= 4U) {
        Xiiii_ror_assert(D_002EC8B0, 0x291, "theCombo >= -1 && theCombo < 3");
    }
    if (arg1 >= 4U) {
        Xiiii_ror_assert(D_002EC8B0, 0x292, D_002ECAD8);
    }
    if (arg2 >= 5U) {
        Xiiii_ror_assert(D_002EC8B0, 0x293, D_002ECAF8);
    }
    arg0->m_atk_weapon = arg1;
    arg0->m_atk_height = arg2;
    arg0->m_atk_combo = arg3;
    Xiiiiiif_func_0011D7C0(arg0, func_0012C104(arg0, arg1, arg2, arg3), 0, 0, -1, 0.01666669361293316f);
    Xii_func_0011DFD0(arg0);
    X_func_001026B0(Xiiuui_func_0011D1CC(arg0, arg2, arg3, 0), 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifepcbtl", func_0012C31C);

extern "C" void func_0012C9C0(MagLifePC *arg0, int arg1, int arg2)
{
    if ((arg0->m_actor != 0) && ((arg0->m_unk00 != 0xE) || (arg0->m_unk08 >= 8))) {
        Xiiiui_func_0011C1E8(arg0, 0xE, (unsigned int) arg1, 1);
        arg0->m_unk0C = arg2;
    }
}

extern "C" int func_0012CA28(MagLifePC *arg0)
{
    int node = arg0->m_target_id;
    if (node != 0) {
        DogVector vec;
        X_func_0011CE5C(arg0, &vec, node, 0);
        return func_0012CAA4(arg0, &vec.m_x, arg0->m_target_id);
    }
    register int ret PS2_REG("$3") = arg0->m_unk1B0;
    if (ret < 0) ret = 0;
    return ret;
}

extern "C" int func_0012CAA4(MagLifePC *arg0, const float *arg1, int arg2)
{
    DogVector vec;
    func_0012BC20(arg0, &vec);
    float dist = Xf_vecDistXZ__FPCfT0(&vec.m_x, arg1);
    if (X_func_0011D1B0(arg0, arg2) == 0 && dist <= 80.0f) {
        return 4;
    }
    return Xiiif_func_0011D3D0(arg0, arg2, dist);
}

extern "C" void func_0012CB50(MagLifePC *arg0)
{
    if (arg0->m_unk00 != 0xB) {
        Xiiii_ror_assert(D_002EC8B0, 0x4AF, "m_submode.getMode() == MAG_PC_MODE_TARGETTING");
    }
    if (arg0->m_unk21C == 1) {
        X_func_001026B0(0x7D, 0, 0);
    }
    arg0->m_target_id = 0;
    arg0->m_target_unk = -1;
    PcTargetList list;
    list.m_num = 0;
    DogVector *a = X_func_00119FA4(arg0);
    if (func_0010376C(&list, a, X_func_00119FB0(arg0), 0, 1, 500.0f) > 0) {
        int i = func_00103654(&list, 1.5707965f);
        if (i >= 0) {
            int id = list.m_item[i].m_id;
            int u = list.m_item[i].m_unk24;
            arg0->m_unk1C0 = list.m_item[i].m_pos;
            arg0->m_target_id = id;
            arg0->m_target_unk = u;
        } else {
            arg0->m_target_id = 0;
        }
    } else {
        arg0->m_target_id = 0;
    }
    Xiiiui_func_0011C1E8(arg0, 5, 0, 0);
}
