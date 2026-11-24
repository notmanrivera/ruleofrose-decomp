#include "include_asm.h"
#include "mag/maglifebwn.h"
#include "utl/utlfind.h"
float vecDist(const float *, const float *);
struct BwnTarget {
    DogVector m_pos;
    DogVector m_unk10;
    int m_id;
    int m_unk24;
    int m_unk28[6];
};
struct BwnTargetList {
    BwnTarget m_item[32];
    int m_num;
    BwnTargetList() { m_num = 0; }
};
extern "C" int func_0010376C(BwnTargetList *, DogVector *, float, int, int, float);
void vecTurnY(float *, float);
extern "C" int func_0012349C(MagLifeBwn *, MagBwnVec4 *);
extern "C" void func_00104150(int);
extern "C" void func_0012A394(MagLifeBwnCtrl *);
extern "C" void func_00125980(MagLifeBwn *);
extern "C" void func_001258A4(MagLifeBwn *);
struct MagLifeBwnCtrlModeV2 {
    virtual void vfunc01();
    virtual void vfunc02(MagLifeBwnCtrl *);
};
extern "C" int func_001267F4(int, MagLifeBwnCtrl *, float);
struct MagLifeBwnCtrlModeV {
    virtual void vfunc01();
    virtual void vfunc02();
};

extern "C" int Xii_getMainMotionNo__C14DogMotionBlend(const DogMotionBlend *) asm("getMainMotionNo__C14DogMotionBlend");
extern "C" int Xiii_func_0010AA5C__8DogActorPCc(DogActor *, const char *) asm("func_0010AA5C__8DogActorPCc");
extern "C" void Xiiii_ror_assert(const char *, int, const char *) asm("ror_assert");
extern "C" float Xfi_func_0010A650__8DogActor(DogActor *) asm("func_0010A650__8DogActor");
extern "C" int Xii_func_00103428(int) asm("func_00103428");
extern "C" int Xii_func_0010344C(int) asm("func_0010344C");
extern "C" void X_func_00104150(int) asm("func_00104150");
extern "C" int Xiiiii_func_0012A56C(MagLifeBwnCtrl *, int, int, int) asm("func_0012A56C");
extern "C" void X_func_00126928(...) asm("func_00126928");
extern "C" int func_00129F50(MagLifeBwnCtrlModeBark *, MagLifeBwnCtrl *, int);
extern "C" void func_00129F78(MagLifeBwnCtrlMode *, MagLifeBwnCtrl *, int);
extern "C" int X_utlFindIsTarget__FP7UtlFindi(...) asm("utlFindIsTarget__FP7UtlFindi");
extern "C" int X_utlFindNearest__FP7UtlFindPfi(...) asm("utlFindNearest__FP7UtlFindPfi");
extern const char D_002EBE28[];
extern const char D_002EBE40[];

extern "C" int func_001267C0(int arg0, int arg1, int arg2)
{
    return X_utlFindIsTarget__FP7UtlFindi(arg2);
}

extern "C" int func_001267D8(int arg0, int arg1, int arg2, int arg3)
{
    return X_utlFindNearest__FP7UtlFindPfi(arg1, arg3);
}

extern "C" int func_001267F4(int arg0, MagLifeBwnCtrl *arg1, float arg2)
{
    register int ret PS2_REG("$2") = 0;
    if (arg1->m_bwn->m_unkCB8 < 3) {
        DogVector pos;
        arg1->m_bwn->func_00119F88(&pos);
        BwnTargetList list;
        ret = func_0010376C(&list, &pos, 0.0f, 0, 1, arg2);
    }
    return ret;
}

extern "C" int func_001268B4(int arg0, MagLifeBwnCtrl *arg1)
{
    int ret = 0;
    MagLifeBwn *bwn = arg1->m_bwn;
    if (bwn == 0) {
        return ret;
    }
    if (bwn->m_unkCB8 >= 3) {
        return ret;
    }
    if (func_001267F4(arg0, arg1, 200.0f) > 0) {
        Xiiiii_func_0012A56C(arg1, 0xB, 0, 0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00126928);

extern "C" void MagLifeBwnCtrlModeNull__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    if (arg1->m_bwn != 0) {
        ((MagLifeBwnCtrlModeV *)arg0)->vfunc02();
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeNull__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeWait__vfunc_01);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeWait__vfunc_02);

extern "C" void MagLifeBwnCtrlModeFollow__vfunc_01(MagLifeBwnCtrlModeFollow *arg0, MagLifeBwnCtrl *arg1)
{
    MagLifeBwn *bwn = arg1->m_bwn;
    if (bwn != 0) {
        bwn->m_unkCC4 = 0;
        arg1->m_unk60 = 0;
        arg1->m_unk08 = 0;
        arg0->m_unk04 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFollow__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00127558);

extern "C" void MagLifeBwnCtrlModeStay__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    arg1->m_unk08 = 0;
    if (arg1->m_bwn != 0) {
        arg1->m_unk78 = 2;
    }
}

extern "C" void MagLifeBwnCtrlModeStay__vfunc_02(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    int &step = arg1->m_unk08;
    if (arg1->m_bwn != 0) {
        if (step == 0) {
            if (arg1->m_bwn->message(3, 0, 0) >= 0) {
                step = 1;
            }
        }
        if (arg1->m_bwn->m_unkCB8 == 4) {
            Xiiiii_func_0012A56C(arg1, 0xD, 0, 0);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD00);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD18);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD30);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD48);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD60);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD78);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBD90);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBDA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBDC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBDD8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBDF0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE28);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE48);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBE60);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFind__vfunc_01);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBEA8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBED8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBF10);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBF40);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBF80);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EBFC0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC000);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC028);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFind__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00128724);

extern "C" int func_00128854(MagLifeBwnCtrlModeFind *arg0, MagLifeBwnCtrl *arg1, MagBwnVec4 *arg2, int arg3)
{
    float z = 95.0f;
    if (arg3 == 0) {
        z = -95.0f;
    }
    arg2->z = z;
    arg2->w = 1.0f;
    arg2->x = 0.0f;
    arg2->y = 0.0f;
    vecTurnY(&arg2->x, arg0->m_unk20);
    MagBwnVec4 *pos = &arg0->m_unk10;
    arg2->x += pos->x;
    arg2->y += pos->y;
    arg2->z += pos->z;
    arg2->w = 1.0f;
    return func_0012349C(arg1->m_bwn, arg2);
}

extern "C" void MagLifeBwnCtrlModeFindEnd__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    arg1->m_unk78 = 0;
    if (Xii_func_0010344C(arg1->m_unk64) != 0) {
        arg1->m_unk7C = 1;
        Xii_func_00103428(arg1->m_unk64);
        arg1->m_unk08 = 0;
        return;
    }
    arg1->m_unk7C = -1;
    Xiiiii_func_0012A56C(arg1, 1, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeFindEnd__vfunc_02);

extern "C" void MagLifeBwnCtrlModeMove__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    arg1->m_unk80 = 0;
    if (func_0012349C(arg1->m_bwn, &arg1->m_targetPos) >= 0) {
        arg1->m_bwn->message(6, 0, 0);
        arg1->m_unk08 = 0;
        arg1->m_unk0C = 0;
    }
}

extern "C" int MagLifeBwnCtrlModeMove__vfunc_02(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    MagLifeBwn *bwn = arg1->m_bwn;
    if (bwn->m_unkCC0 != 0) {
        return Xiiiii_func_0012A56C(arg1, 7, 0, 0);
    }
    if (bwn->m_unkCAC != 0) {
        Xiiiii_func_0012A56C(arg1, 7, 0, 0);
    }
}

extern "C" void MagLifeBwnCtrlModeMoveEnd__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    arg1->m_unk80 = 1;
    Xiiiii_func_0012A56C(arg1, 0, 0, 0);
}

extern "C" void MagLifeBwnCtrlModeMoveEnd__vfunc_02(void) {
}

extern "C" void MagLifeBwnCtrlModeRot__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    arg1->m_unk80 = 0;
    arg1->m_unk08 = 0;
}

extern "C" void MagLifeBwnCtrlModeRot__vfunc_02()
{
    X_func_00126928();
}

extern "C" void MagLifeBwnCtrlModeRotEnd__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    arg1->m_unk80 = 1;
    Xiiiii_func_0012A56C(arg1, 0, 0, 0);
}

extern "C" void MagLifeBwnCtrlModeRotEnd__vfunc_02(void) {
}

extern "C" void MagLifeBwnCtrlModeDamage__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    int var_s1 = 0;
    switch ((unsigned int)arg1->m_unk08) {
    case 3:
    case 4:
        break;
    case 0:
        var_s1 = 0x6D;
        break;
    case 1:
        var_s1 = 0x6E;
        break;
    case 2:
        Xiiii_ror_assert(D_002EBE28, 0x7F6, D_002EBE40);
        break;
    default:
        Xiiii_ror_assert(D_002EBE28, 0x800, D_002EBE40);
        break;
    }
    MagLifeBwn *bwn = arg1->m_bwn;
    bwn->m_unk04 = -1;
    bwn->m_unk00 = -1;
    arg1->m_bwn->message(1, var_s1, (void *)1);
}

extern "C" void MagLifeBwnCtrlModeDamage__vfunc_02(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    MagLifeBwn *bwn = arg1->m_bwn;
    if (bwn->m_unkCC0 != 0) {
        Xiiiii_func_0012A56C(arg1, 1, 0, 0);
        return;
    }
    if (bwn->func_0011A064() != 0) {
        Xiiii_ror_assert(D_002EBE28, 0x813, "!theBwnCtrl.m_bwn->isMotionStateEndless()");
    }
}

extern "C" void MagLifeBwnCtrlModeBark__vfunc_01(MagLifeBwnCtrlModeBark *arg0, MagLifeBwnCtrl *arg1)
{
    int &step = arg1->m_unk08;
    arg0->m_unk24 = 0;
    arg0->m_unk28 = 0;
    X_func_00104150(1);
    if (step == 0) {
        step = 0;
    } else {
        step = 0xE;
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_00128E6C);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC108);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC118);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC128);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC138);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC148);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC158);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC168);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC178);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC188);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC198);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1B8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1C8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1D8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC1F8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC208);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC220);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC230);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeBark__vfunc_02);

extern "C" int func_00129F50(MagLifeBwnCtrlModeBark *arg0, MagLifeBwnCtrl *arg1, int arg2)
{
    if (arg1->m_unk08 == 0xB && arg0->m_unk24 == arg2) {
        return 1;
    }
    return -1;
}

extern "C" void func_00129F78(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1, int arg2)
{
    arg1->m_unk0C = arg2;
    arg1->m_unk08 = 0xC;
}

extern "C" void MagLifeBwnCtrlModeSitOut__vfunc_01(void) {
}

extern "C" void MagLifeBwnCtrlModeSitOut__vfunc_02(void) {
}

extern "C" void MagLifeBwnCtrlModeHug__vfunc_01(MagLifeBwnCtrlModeHug *arg0, MagLifeBwnCtrl *arg1)
{
    int &unk04 = arg0->m_unk04;
    if (unk04 == 1 || unk04 == 2) {
        arg1->m_bwn->message(1, unk04 + 0x7E, (void *)1);
    } else {
        unk04 = 0;
        MagLifeBwn *bwn = arg1->m_bwn;
        bwn->m_unk04 = -1;
        bwn->m_unk00 = -1;
        arg1->m_bwn->message(1, 2, (void *)1);
    }
    arg1->m_unk78 = 4;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", MagLifeBwnCtrlModeHug__vfunc_02);

extern "C" void MagLifeBwnCtrlModeWound__vfunc_01(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    DogActor *actor = arg1->m_bwn->getActor();
    if (actor == 0) {
        Xiiii_ror_assert(D_002EBE28, 0xB73, "actor");
    }
    int motion = Xiii_func_0010AA5C__8DogActorPCc(actor, "dmgl_wait");
    if (motion != Xii_getMainMotionNo__C14DogMotionBlend(&actor->m_motion_now)) {
        MagLifeBwn *bwn = arg1->m_bwn;
        bwn->m_unk04 = -1;
        bwn->m_unk00 = -1;
        arg1->m_bwn->message(1, 0x82, 0);
    }
    arg1->m_unk08 = 0;
}

extern "C" void MagLifeBwnCtrlModeWound__vfunc_02(MagLifeBwnCtrlMode *arg0, MagLifeBwnCtrl *arg1)
{
    int &step = arg1->m_unk08;
    MagLifeBwn *bwn = arg1->m_bwn;
    if (step == 0) {
        if (bwn->m_unkCB8 < 3) {
            bwn->m_unk04 = -1;
            bwn->m_unk00 = -1;
            arg1->m_bwn->message(1, 0x70, 0);
            step = 1;
        }
    } else if (bwn->func_0011A054() != 0) {
        Xiiiii_func_0012A56C(arg1, 0, 0, 0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC320);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC328);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC330);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC338);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC340);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC348);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC358);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC360);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC370);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC378);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC380);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC388);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC390);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC398);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC3A0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012A394);

extern "C" void func_0012A56C(MagLifeBwnCtrl *arg0, int arg1, int arg2, int arg3)
{
    if (arg1 < 0) {
        ror_assert(D_002EBE28, 0xC0B, "theMode >= 0");
    }
    func_00104150(1);
    if ((arg1 == 0xD || arg0->m_bwn->func_00119CEC(0, 0.0f) <= 0) && (arg0->m_unk00 != arg1 || arg3 != 0)) {
        arg0->m_unk00 = arg1;
        arg0->m_unk08 = arg2;
        arg0->m_unk04 = -1;
        func_0012A394(arg0);
    }
}

extern "C" void MagLifeBwnCtrl__vfunc_02(MagLifeBwnCtrl *arg0)
{
    if (arg0->m_unk6C != 2) {
        if (arg0->m_unk88 == 0) {
            Xiiiii_func_0012A56C(arg0, 0, 0, 1);
            if (arg0->m_unk88 == 0) {
                return;
            }
        }
        arg0->m_unk84++;
        ((MagLifeBwnCtrlModeV2 *)arg0->m_unk88)->vfunc02(arg0);
    }
}

extern "C" void MagLifeBwnCtrl__vfunc_09(void) {
}

extern "C" void func_0012A6A8(MagLifeBwnCtrl *arg0, int arg1)
{
    Xiiiii_func_0012A56C(arg0, 0xA, arg1, 0);
}

extern "C" int func_0012A6CC(MagLifeBwnCtrl *arg0)
{
    return arg0->m_unk00 == 0xA;
}

extern "C" int func_0012A6DC(MagLifeBwnCtrl *arg0, int arg1)
{
    if (arg0->m_unk00 == 0xB) {
        return func_00129F50(&arg0->m_modeBark, arg0, arg1);
    }
    return -1;
}

extern "C" void func_0012A71C(MagLifeBwnCtrl *arg0, int arg1)
{
    if (arg0->m_unk00 == 0xB) {
        return func_00129F78(&arg0->m_modeBark, arg0, arg1);
    }
}

extern "C" void func_0012A758(MagLifeBwnCtrl *arg0, int arg1, int arg2, int arg3)
{
    *(int *)&arg0->m_pad44[0] = arg1;
    if (arg1 >= 0) {
        utlFindSet((UtlFind *)&arg0->m_pad44[4], arg1, arg3);
    }
    if (arg2 != 0) {
        Xiiiii_func_0012A56C(arg0, 4, 0, 1);
        return;
    }
    arg0->m_unk78 = 0;
}

extern "C" void func_0012A7CC(MagLifeBwnCtrl *arg0)
{
    if ((unsigned int) (arg0->m_unk00 - 4) < 2U) {
        arg0->m_unk78 = 0;
        Xiiiii_func_0012A56C(arg0, 1, 0, 1);
    }
}

extern "C" void func_0012A808(MagLifeBwnCtrl *arg0, MagBwnVec4 *arg1)
{
    if (arg0->m_bwn != 0) {
        if (arg0->m_bwn->getActor() != 0) {
            DogActor *actor = arg0->m_bwn->getActor();
            *(u_long128 *)&actor->m_unk40 = *(u_long128 *)arg1;
            actor->m_unk90 = 1;
            Xiiiii_func_0012A56C(arg0, 0, 0, 0);
        }
    }
}

extern "C" void func_0012A89C(MagLifeBwnCtrl *arg0, MagBwnVec4 *arg1)
{
    if (arg0->m_bwn != 0) {
        if (arg0->m_bwn->getActor() != 0) {
            DogActor *actor = arg0->m_bwn->getActor();
            *(u_long128 *)&actor->m_unk50 = *(u_long128 *)arg1;
            actor->normalizeRot();
            actor->m_unk90 = 1;
            actor->m_base_rot.set(&arg1->x);
            actor->setRotOffsetY(0.0f);
            func_0012A56C(arg0, 0, 0, 0);
        }
    }
}

extern "C" void func_0012A974(MagLifeBwnCtrl *arg0, MagBwnVec4 *arg1)
{
    if (arg0->m_bwn != 0) {
        if (arg0->m_bwn->getActor() != 0) {
            *(u_long128 *)arg1 = *(u_long128 *)&arg0->m_bwn->getActor()->m_unk40;
        }
    }
}

extern "C" void func_0012A9EC(MagLifeBwnCtrl *arg0, MagBwnVec4 *arg1)
{
    if (arg0->m_bwn != 0) {
        if (arg0->m_bwn->getActor() != 0) {
            DogActor *actor = arg0->m_bwn->getActor();
            *(u_long128 *)arg1 = *(u_long128 *)&actor->m_unk50;
            arg1->y = Xfi_func_0010A650__8DogActor(actor);
        }
    }
}

extern "C" void func_0012AA70(MagLifeBwnCtrl *arg0, const float *arg1)
{
    ((DogVector *)&arg0->m_targetPos)->set(arg1[0], arg1[1], arg1[2]);
    Xiiiii_func_0012A56C(arg0, 6, 0, 0);
}

extern "C" void func_0012AAC0(MagLifeBwnCtrl *arg0, float fparg0)
{
    arg0->m_targetRot = fparg0;
    Xiiiii_func_0012A56C(arg0, 0, 0, 0);
}

extern "C" void func_0012AAE8(MagLifeBwnCtrl *arg0, float fparg0)
{
    arg0->m_targetRot = fparg0;
    Xiiiii_func_0012A56C(arg0, 8, 0, 0);
}

extern "C" int func_0012AB10(MagLifeBwnCtrl *arg0)
{
    return arg0->m_unk80;
}

extern "C" void func_0012AB18(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012AB20);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012ADEC);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012AF70);

extern "C" int func_0012B0D0(MagLifeBwnCtrl *arg0)
{
    register int ret PS2_REG("$2") = 0;
    MagLifeBwn *bwn = arg0->m_bwn;
    if (bwn != 0 && bwn->m_unkCB8 < 3) {
        MagLifeControlChara *ch = arg0->m_unk74;
        if (ch != 0) {
            DogVector pos;
            ch->func_00119F88(&pos);
            BwnTargetList list;
            ret = func_0010376C(&list, &pos, 0.0f, 0, 1, 500.0f) > 0;
        }
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B19C);

extern "C" int func_0012B300(MagLifeBwnCtrl *arg0)
{
    DogVector v0;
    arg0->m_unk74->func_00119F88(&v0);
    DogVector v1;
    arg0->m_bwn->func_00119F88(&v1);
    float dy = v1.m_y - v0.m_y;
    if (dy < -100.0f || dy > 100.0f) {
        return 1;
    }
    if (vecDist(&v1.m_x, &v0.m_x) >= 130.0f) {
        return 1;
    }
    return 0;
}

extern "C" int func_0012B3D0(MagLifeBwnCtrl *arg0)
{
    DogVector v0;
    arg0->m_unk74->func_00119F88(&v0);
    DogVector v1;
    arg0->m_bwn->func_00119F88(&v1);
    float dy = v1.m_y - v0.m_y;
    if (dy < -100.0f || dy > 100.0f) {
        return 1;
    }
    if (vecDist(&v1.m_x, &v0.m_x) < 95.0f) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B4A0);

extern "C" void func_0012B5F8(MagLifeBwnCtrl *arg0)
{
    MagLifeBwn *bwn = arg0->m_bwn;
    if (bwn != 0 && bwn->m_unkCB8 < 4) {
        if (bwn->func_00119CEC(0, 0.0f) == 0) {
            Xiiiii_func_0012A56C(arg0, 3, 0, 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012B65C);

extern "C" void func_0012B788(MagLifeBwnCtrl *arg0, int arg1)
{
    Xiiiii_func_0012A56C(arg0, 0xC, arg1, 1);
    if (arg1 >= 0) {
        arg0->m_unk124 = arg1;
    }
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnctrl", D_002EC448);

extern "C" void func_0012B7CC(MagLifeBwnCtrl *arg0, int theLevel)
{
    if (!(theLevel >= 0 && theLevel <= 2)) {
        Xiiii_ror_assert(D_002EBE28, 0xF52, "theLevel >= MAG_BWNCTRL_LEVEL_AUTO && theLevel <= MAG_BWNCTRL_LEVEL_MANUAL");
    }
    if (arg0->m_unk6C == theLevel) {
        return;
    }
    arg0->m_unk6C = theLevel;
    if (theLevel == 0) {
        func_00125980(arg0->m_bwn);
        Xiiiii_func_0012A56C(arg0, 0, 0, 1);
    } else if (theLevel == 2) {
        if (arg0->m_bwn != 0) {
            func_001258A4(arg0->m_bwn);
        }
    }
}
