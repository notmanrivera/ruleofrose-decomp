#include "include_asm.h"
#include "mag/maglifebwn.h"
#include "utl/utlfind.h"
#include "mag/magscene.h"
void vecNormalize(float *);
extern "C" void func_00125A20(MagLifeBwn *, int);
extern const char D_002EC320[];
extern const char D_002EC328[];
extern const char D_002EC330[];
extern const char D_002EC338[];
extern const char D_002EC340[];
extern const char D_002EC348[];
extern const char D_002EC358[];
extern const char D_002EC360[];
extern const char D_002EC370[];
extern const char D_002EC378[];
extern const char D_002EC380[];
extern const char D_002EC388[];
extern const char D_002EC390[];
extern const char D_002EC398[];
extern "C" void func_0017C340(void *, DogVector *, void **, int, float, float);
float vecYaw(const float *);
extern "C" int func_0012B19C(MagLifeBwnCtrl *);
extern "C" int func_0010423C(int, int);
extern "C" int func_0012AB20(MagLifeBwnCtrl *) ASM_NOTHROW;
extern "C" int func_0012ADEC(MagLifeBwnCtrl *) ASM_NOTHROW;
extern "C" int func_0012AF70(MagLifeBwnCtrl *) ASM_NOTHROW;
extern "C" void func_0012A56C(MagLifeBwnCtrl *, int, int, int);
float vecDist(const float *, const float *);
struct BwnTarget {
    DogVector m_pos;
    DogVector m_unk10;
    int m_id;
    int m_unk24;
    int m_unk28[2];
    float m_unk30;
    int m_unk34[3];
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
    virtual void vfunc01(MagLifeBwnCtrl *);
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

extern "C" void MagLifeBwnCtrlModeNull__vfunc_02(int arg0, MagLifeBwnCtrl *arg1)
{
    if (arg1->m_unk6C != 0) {
        return;
    }
    if (arg1->m_bwn->m_unkCB8 == 4) {
        return func_0012A56C(arg1, 0xD, 0, 0);
    }
    int unk78 = arg1->m_unk78;
    if (unk78 == 1) {
        return func_0012A56C(arg1, 4, 0, 0);
    } else if (unk78 == 2) {
        return func_0012A56C(arg1, 3, 0, 0);
    } else if (unk78 == 4) {
        return func_0012A56C(arg1, 0xC, -1, 0);
    }
    if (func_001268B4(arg0, arg1) == 0) {
        func_0012A56C(arg1, 1, 0, 0);
    }
}

extern "C" void MagLifeBwnCtrlModeWait__vfunc_01(int arg0, MagLifeBwnCtrl *arg1)
{
    MagLifeBwn *bwn = arg1->m_bwn;
    MagBwnVec4 v0;
    MagBwnVec4 v1;
    if (bwn == 0) {
        return;
    }
    if (arg1->m_unk78 == 1) {
        func_0012A56C(arg1, 4, 0, 0);
        return;
    }
    if (arg1->m_unk78 == 2) {
        func_0012A56C(arg1, 3, 0, 0);
        return;
    }
    if (arg1->m_unk74 == 0) {
        goto msg2;
    }
    ((DogVector *)&v0)->clear();
    arg1->m_unk74->func_00119F88((DogVector *)&v0);
    ((DogVector *)&v1)->clear();
    if (arg1->m_bwn == 0) {
        return;
    }
    arg1->m_bwn->func_00119F88((DogVector *)&v1);
    if (vecDist(&v1.x, &v0.x) > 170.0f) {
        func_0012A56C(arg1, 2, 0, 0);
        return;
    }
    bwn = arg1->m_bwn;
    if (bwn->m_unkCB8 == 4) {
        func_0012A56C(arg1, 0xD, 0, 0);
        return;
    }
    if (bwn->m_unkCB8 == 3) {
    msg2:
        bwn->message(2, 0, 0);
        return;
    }
    if (func_001267F4(arg0, arg1, 500.0f) > 0) {
        func_0012A56C(arg1, 0xB, 0, 0);
    } else {
        arg1->m_bwn->message(2, 0, 0);
    }
}

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

extern "C" int func_00128724(MagLifeBwnCtrlModeFind *arg0, DogVector *arg1)
{
    DogVector v = *arg1;
    MagBwnVec4 *pos = &arg0->m_unk10;
    v.m_y -= pos->y;
    v.m_w = 1.0f;
    v.m_x -= pos->x;
    v.m_z -= pos->z;
    if (v.m_y < -50.0f || v.m_y > 50.0f) {
        return 0;
    }
    vecTurnY(&v.m_x, -arg0->m_unk20);
    if (v.m_x >= -30.0f && v.m_x <= 30.0f) {
        if (arg0->m_unk27 != 0) {
            if (v.m_z > 76.0f && v.m_z <= 100.0f) {
                return 1;
            }
        } else {
            if (v.m_z >= -100.0f && v.m_z < -76.0f) {
                return 1;
            }
        }
    }
    return 0;
}

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

extern "C" int func_00128E6C(int arg0, MagLifeBwnCtrl *arg1, BwnTargetList *arg2, int arg3)
{
    register int ret PS2_REG("$2") = 0;
    MagLifeControlChara *ch = arg1->m_unk74;
    DogVector pos;
    if (ch != 0) {
        MagLifeBwn *bwn = arg1->m_bwn;
        if (bwn != 0) {
            switch (arg3) {
            case 0:
                ch = bwn;
            case 1:
                ch->func_00119F88(&pos);
                break;
            case 2:
                {
                    ch->func_00119F88(&pos);
                    float rot = arg1->m_unk74->func_00119FB0();
                    DogVector ofs(0.0f, 0.0f, 500.0f, 1.0f);
                    DogVector *pOfs = &ofs;
                    vecTurnY(&pOfs->m_x, rot);
                    pos.m_x += pOfs->m_x;
                    pos.m_y += pOfs->m_y;
                    pos.m_z += pOfs->m_z;
                    pos.m_w = 1.0f;
                }
                break;
            default:
                ror_assert(D_002EBE28, 0x851, D_002EBE40);
                break;
            }
            int n = func_0010376C(arg2, &pos, 0.0f, 0, 1, 500.0f);
            ret = -1;
            if (n > 0) {
                ret = 0;
                if (n != 1) {
                    int best = -1;
                    float minDist = 100000.0f;
                    for (int i = 0; i < n; i++) {
                        if (arg2->m_item[i].m_unk30 < minDist) {
                            minDist = arg2->m_item[i].m_unk30;
                            best = i;
                        }
                    }
                    ret = best;
                }
            }
        }
    }
    return ret;
}

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

extern "C" void MagLifeBwnCtrlModeHug__vfunc_02(MagLifeBwnCtrlModeHug *arg0, MagLifeBwnCtrl *arg1)
{
    int unk04 = arg0->m_unk04;
    if (unk04 == 0) {
        DogVector v0;
        arg1->m_unk74->func_00119F88(&v0);
        DogVector v1;
        DogVector *pv1 = &v1;
        arg1->m_bwn->func_00119F88(pv1);
        float d = vecDist(&v0.m_x, &pv1->m_x) - 100.0f;
        if (d != 0.0f) {
            if (d > 1.0f) {
                d = 1.0f;
            }
            DogVector diff = v0;
            DogVector *pd = &diff;
            pd->m_x -= pv1->m_x;
            pd->m_w = 1.0f;
            pd->m_y -= pv1->m_y;
            pd->m_z -= pv1->m_z;
            vecNormalize(&pd->m_x);
            pd->m_x *= d;
            pd->m_w = 1.0f;
            pd->m_y *= d;
            pd->m_z *= d;
            DogActor *actor = arg1->m_bwn->getActor();
            DogVector *pos = &actor->m_unk40;
            pos->m_x += pd->m_x;
            pos->m_y += pd->m_y;
            pos->m_z += pd->m_z;
            pos->m_w = 1.0f;
            actor->m_unk90 = 1;
        }
    } else if (unk04 == 1 || unk04 == 2) {
        MagLifeBwn *bwn = arg1->m_bwn;
        if (bwn->m_unkCC0 != 0 || bwn->func_0011A064() != 0) {
            arg1->m_unk78 = 0;
            func_0012A56C(arg1, 0, 0, 0);
        }
    }
}

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

extern "C" void func_0012A394(MagLifeBwnCtrl *arg0)
{
    int mode = arg0->m_unk00;
    const char *tbl[14] = {
        D_002EC320, D_002EC328, D_002EC330, D_002EC338,
        D_002EC340, D_002EC348, D_002EC358, D_002EC360,
        D_002EC370, D_002EC378, D_002EC380, D_002EC388,
        D_002EC390, D_002EC398,
    };
    switch (mode) {
    case 0:
        arg0->m_unk88 = &arg0->m_modeNull;
        break;
    case 1:
        arg0->m_unk88 = &arg0->m_modeWait;
        break;
    case 2:
        arg0->m_unk88 = &arg0->m_modeFollow;
        break;
    case 3:
        arg0->m_unk88 = &arg0->m_modeStay;
        break;
    case 4:
        arg0->m_unk88 = &arg0->m_modeFind;
        break;
    case 5:
        arg0->m_unk88 = &arg0->m_modeFindEnd;
        break;
    case 6:
        arg0->m_unk88 = &arg0->m_modeMove;
        break;
    case 7:
        arg0->m_unk88 = &arg0->m_modeMoveEnd;
        break;
    case 8:
        arg0->m_unk88 = &arg0->m_modeRot;
        break;
    case 9:
        arg0->m_unk88 = &arg0->m_modeRotEnd;
        break;
    case 10:
        arg0->m_unk88 = &arg0->m_modeDamage;
        break;
    case 11:
        arg0->m_unk88 = &arg0->m_modeBark;
        break;
    case 12:
        arg0->m_unk88 = &arg0->m_modeHug;
        break;
    case 13:
        arg0->m_unk88 = &arg0->m_modeWound;
        break;
    default:
        arg0->m_unk88 = 0;
        ror_assert(D_002EBE28, 0xBF0, D_002EBE40);
        break;
    }
    arg0->m_unk84 = 0;
    if (arg0->m_unk88 != 0) {
        if (mode == 1) {
            func_00125A20(arg0->m_bwn, 2);
        } else {
            func_00125A20(arg0->m_bwn, 0);
        }
        ((MagLifeBwnCtrlModeV2 *)arg0->m_unk88)->vfunc01(arg0);
    }
}

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
    arg0->m_unk44 = arg1;
    if (arg1 >= 0) {
        utlFindSet(&arg0->m_find, arg1, arg3);
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

extern "C" int func_0012ADEC(MagLifeBwnCtrl *arg0)
{
    int ret = 0;
    if (arg0->m_unk74 != 0) {
        int found = 0;
        DogVector pos;
        register int i PS2_REG("$16") = 0;
        arg0->m_unk74->func_00119F88(&pos);
        float rot = arg0->m_unk74->func_00119FB0();
        DogVector dir(0.0f, 0.0f, 1.0f, 1.0f);
        DogVector *pDir = &dir;
        vecTurnY(&pDir->m_x, rot);
        do {
            i++;
            float dist = i * 300.0f;
            DogVector p = *pDir;
            DogVector *pp = &p;
            pp->m_x *= dist;
            pp->m_w = 1.0f;
            pp->m_y *= dist;
            pp->m_z *= dist;
            pp->m_x += pos.m_x;
            pp->m_w = 1.0f;
            pp->m_y += pos.m_y;
            pp->m_z += pos.m_z;
            void *hit;
            func_0017C340(&arg0->m_scene->m_unk437DC[0x41C50], pp, &hit, 0, 100.0f, 0.0f);
            if (hit == 0) {
                break;
            }
            found = 1;
            *(u_long128 *)&arg0->m_targetPos = *(u_long128 *)pp;
        } while (i < 10);
        ret = found;
    }
    return ret;
}

// NON_MATCHING: 45/88 differ, 4 relocs differ, 17 edits
#ifdef NON_MATCHING
extern "C" int func_0012AF70(MagLifeBwnCtrl *arg0)
{
    int ret = 0;
    MagLifeBwn *bwn = arg0->m_bwn;
    if (bwn != 0 && bwn->m_unkCB8 < 3) {
        DogVector pos;
        BwnTargetList list;
        if (arg0->m_unk74 != 0) {
            arg0->m_unk74->func_00119F88(&pos);
            float rot = arg0->m_unk74->func_00119FB0();
            DogVector ofs(0.0f, 0.0f, 500.0f, 1.0f);
            DogVector *pOfs = &ofs;
            vecTurnY(&pOfs->m_x, rot);
            pos.m_x += pOfs->m_x;
            pos.m_y += pOfs->m_y;
            pos.m_z += pOfs->m_z;
            pos.m_w = 1.0f;
            ret = func_0010376C(&list, &pos, 0.0f, 0, 1, 500.0f) > 0;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnctrl", func_0012AF70);
#endif

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

extern "C" int func_0012B19C(MagLifeBwnCtrl *arg0)
{
    DogVector v0;
    arg0->m_unk74->func_00119F88(&v0);
    DogVector v1;
    DogVector *pv1 = &v1;
    arg0->m_bwn->func_00119F88(pv1);
    DogVector d = v0;
    DogVector *pd = &d;
    pd->m_x -= pv1->m_x;
    pd->m_w = 1.0f;
    pd->m_y -= pv1->m_y;
    pd->m_z -= pv1->m_z;
    float yaw = vecYaw(&pd->m_x);
    float diff = arg0->m_bwn->func_00119FB0() - yaw;
    float r;
    if (diff < -DOG_PI) {
        r = diff + DOG_PI2;
    } else {
        r = diff;
        if (r >= DOG_PI) {
            r -= DOG_PI2;
        }
    }
    if (r < -0.052359883f || r > 0.052359883f) {
        arg0->m_targetRot = yaw;
        return 1;
    }
    return 0;
}

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

extern "C" void func_0012B4A0(MagLifeBwnCtrl *arg0)
{
    MagLifeBwn *bwn = arg0->m_bwn;
    if (bwn != 0 && bwn->m_unkCB8 < 4) {
        bwn->func_0011A704(0xB);
        arg0->m_unk78 = 0;
        if (func_0012B300(arg0) != 0) {
            func_0012A56C(arg0, 2, 0, 1);
            return;
        }
        if (func_0012B19C(arg0) != 0) {
            func_0012A56C(arg0, 8, 0, 0);
            return;
        }
        if (func_0012B3D0(arg0) != 0) {
            arg0->m_bwn->message(1, 0x44, (void *)1);
            return;
        }
        MagLifeBwn *bwn2 = arg0->m_bwn;
        bwn2->m_unk04 = -1;
        bwn2->m_unk00 = -1;
        const int tbl[6] = { 3, 4, 5, 6, 0x27, 0x12 };
        arg0->m_bwn->message(1, tbl[func_0010423C(0, 5)], (void *)1);
    }
}

extern "C" void func_0012B5F8(MagLifeBwnCtrl *arg0)
{
    MagLifeBwn *bwn = arg0->m_bwn;
    if (bwn != 0 && bwn->m_unkCB8 < 4) {
        if (bwn->func_00119CEC(0, 0.0f) == 0) {
            Xiiiii_func_0012A56C(arg0, 3, 0, 0);
        }
    }
}

extern "C" int func_0012B65C(MagLifeBwnCtrl *arg0)
{
    register int ret PS2_REG("$2") = 0;
    MagLifeBwn *bwn = arg0->m_bwn;
    if (bwn != 0 && bwn->m_unkCB8 < 4) {
        arg0->m_unk78 = 0;
        if (utlFindIsSet(&arg0->m_find) != 0) {
            func_0012A56C(arg0, 4, 0, 1);
        } else if (func_0012AF70(arg0) != 0) {
            arg0->m_bwn->func_0011A704(0xB);
            func_0012A56C(arg0, 0xB, 0, 0);
        } else if (func_0012B0D0(arg0) != 0) {
            arg0->m_bwn->func_0011A704(0xB);
            func_0012A56C(arg0, 0xB, 0, 0);
        } else if (func_0012AB20(arg0) != 0) {
            func_0012A56C(arg0, 4, 1, 1);
        } else if (func_0012ADEC(arg0) != 0) {
            arg0->m_bwn->func_0011A704(0xB);
            func_0012A56C(arg0, 6, 0, 0);
        } else {
            arg0->m_bwn->func_0011A704(0xB);
            arg0->m_unk78 = 0;
            func_0012A56C(arg0, 2, 0, 0);
        }
        ret = 1;
    }
    return ret;
}

extern "C" void func_0012B788(MagLifeBwnCtrl *arg0, int arg1)
{
    Xiiiii_func_0012A56C(arg0, 0xC, arg1, 1);
    if (arg1 >= 0) {
        arg0->m_modeHug.m_unk04 = arg1;
    }
}

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
