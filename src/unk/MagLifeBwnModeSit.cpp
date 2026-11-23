#include "include_asm.h"
#include "target.h"
#include "mag/maglifebwn.h"

extern "C" void X_func_0011A888(MagLifeBwn *) asm("func_0011A888");
extern "C" void X_func_0011A144(MagLifeBwn *, void *) asm("func_0011A144");
extern "C" char vtbl_MagLifeBwn[] asm("_vt$10MagLifeBwn");
extern "C" char vtbl_MagLifeBwnModeNull[] asm("_vt$18MagLifeBwnModeNull");
extern "C" char vtbl_MagLifeBwnModeOne[] asm("_vt$17MagLifeBwnModeOne");
extern "C" char vtbl_MagLifeBwnModeWait[] asm("_vt$18MagLifeBwnModeWait");
extern "C" char vtbl_MagLifeBwnModeSit[] asm("_vt$17MagLifeBwnModeSit");
extern "C" char vtbl_MagLifeBwnModeFuse[] asm("_vt$18MagLifeBwnModeFuse");
extern "C" char vtbl_MagLifeBwnModeMove[] asm("_vt$18MagLifeBwnModeMove");
extern "C" char vtbl_MagLifeBwnModePath[] asm("_vt$18MagLifeBwnModePath");
extern "C" char vtbl_MagLifeBwnModeTurn[] asm("_vt$18MagLifeBwnModeTurn");
extern "C" char vtbl_MagLifeBwnModeWall[] asm("_vt$18MagLifeBwnModeWall");
extern "C" char vtbl_MagLifeBwnModeRotate[] asm("_vt$20MagLifeBwnModeRotate");
extern char D_00297418[];

extern "C" int Xiif_func_00119B60(MagLifeBwn *, int, float) asm("func_00119B60");
extern "C" int Xii_func_00124D7C(MagLifeBwn *) asm("func_00124D7C");
extern "C" int Xii_func_00124E18(MagLifeBwn *) asm("func_00124E18");
extern "C" void Xiiiii_func_001233F4(MagLifeBwn *, int, int, int) asm("func_001233F4");
extern "C" int Xii_func_0011A028(MagLifeBwn *) asm("func_0011A028");
extern "C" int Xii_func_0011A054(MagLifeBwn *) asm("func_0011A054");
extern "C" int Xii_func_00123BB8(MagLifeBwn *) asm("func_00123BB8");
extern "C" int Xiiis_func_0011A320(MagLifeBwn *, int, short) asm("func_0011A320");

extern "C" void func_00125A20(MagLifeBwn *arg0, int arg1)
{
    if (arg0->m_unkCD4 != arg1) {
        arg0->m_unkCD4 = arg1;
        arg0->m_unkCD8 = 1;
    }
}

extern "C" void func_00125A3C(MagLifeBwn *arg0, MagBwnVec4 *arg1)
{
    if ((arg0->m_targetPos.x != arg1->x) || (arg0->m_targetPos.y != arg1->y) || (arg0->m_targetPos.z != arg1->z)) {
        *(u_long128 *)&arg0->m_targetPos = *(u_long128 *)arg1;
        arg0->m_unkCD8 = 1;
    }
}

extern "C" void func_00125A90(MagLifeBwn *arg0)
{
    arg0->m_unkCEC = 0;
    arg0->m_unk04 = -1;
    arg0->m_unk00 = -1;
}

extern "C" void func_00125AA4(MagLifeBwn *arg0)
{
    X_func_0011A888(arg0);
    *(void **)((char *)arg0 + 0x14) = vtbl_MagLifeBwn;
#ifdef TARGET_PS2
    *(u_long128 *)&arg0->m_nextMode[0] = 0;
#else
    static const u_long128 zero128 = {{0, 0, 0, 0}};
    *(u_long128 *)&arg0->m_nextMode[0] = zero128;
#endif
    MagBwnVec4 *v0 = &arg0->m_targetPos;
    v0->x = v0->y = v0->z = 0.0f;
    v0->w = 1.0f;
    MagBwnVec4 *arr = arg0->m_pathPoints;
    int i = 0x7E;
    do {
        i--;
        arr->x = arr->y = arr->z = 0.0f;
        arr->w = 1.0f;
        arr++;
    } while (i != -1);
    arg0->m_unkCDC = -1;
    arg0->m_unkCE0 = 0.0f;
    arg0->m_modeNull.m_vtbl = vtbl_MagLifeBwnModeNull;
    arg0->m_modeOne.m_vtbl = vtbl_MagLifeBwnModeOne;
    arg0->m_modeWait.m_vtbl = vtbl_MagLifeBwnModeWait;
    arg0->m_modeSit.m_vtbl = vtbl_MagLifeBwnModeSit;
    arg0->m_modeFuse.m_vtbl = vtbl_MagLifeBwnModeFuse;
    arg0->m_modeMove.m_vtbl = vtbl_MagLifeBwnModeMove;
    arg0->m_modePath.m_vtbl = vtbl_MagLifeBwnModePath;
    arg0->m_modeTurn.m_vtbl = vtbl_MagLifeBwnModeTurn;
    arg0->m_modeWall.m_vtbl = vtbl_MagLifeBwnModeWall;
    arg0->m_modeRotate.m_vtbl = vtbl_MagLifeBwnModeRotate;
    arg0->m_unkCB8 = 0;
    arg0->m_unkCBC = 0;
    arg0->m_unkCD0 = 0;
    arg0->m_unkCD8 = 0;
    arg0->m_unkCE4 = 0;
    arg0->m_unkCEC = 0;
    return X_func_0011A144(arg0, D_00297418);
}

extern "C" int live__14MagLifeBwnModeR10MagLifeBwn(MagLifeBwnMode *arg0, MagLifeBwn *arg1)
{
    Xii_func_00123BB8(arg1);
    if (Xii_func_0011A054(arg1) != 0) {
        Xiiiii_func_001233F4(arg1, 0, 0, 0);
    }
    return 0;
}

extern "C" void init__18MagLifeBwnModeNullR10MagLifeBwn(void) {
}

extern "C" void init__18MagLifeBwnModeWaitR10MagLifeBwn(MagLifeBwnModeWait *arg0, MagLifeBwn *arg1)
{
    int temp_v0;
    int var_a1;

    temp_v0 = Xiif_func_00119B60(arg1, 0, 0.0f);
    arg1->m_sctFlag = temp_v0;
    var_a1 = 0x25;
    if (arg1->m_last0 != 9) {
        var_a1 = 0x6A;
        if (temp_v0 != 2) {
            var_a1 = (temp_v0 == 3) ? 0x6C : 2;
        }
    }
    Xiiis_func_0011A320(arg1, var_a1, -1);
    arg0->m_unk04 = 0;
    arg0->m_unk08 = 0;
    Xii_func_00124D7C(arg1);
}

extern "C" void init__17MagLifeBwnModeSitR10MagLifeBwn(MagLifeBwnModeSit *arg0, MagLifeBwn *arg1)
{
    if ((unsigned int) (arg1->m_sctFlag - 2) < 2U) {
        return Xiiiii_func_001233F4(arg1, 2, 0, 0);
    }
    func_00125A20(arg1, 0);
    Xii_func_00124E18(arg1);
    Xiiis_func_0011A320(arg1, (arg1->m_last0 == 4) ? 0xF : 7, -1);
}

extern "C" int term__17MagLifeBwnModeSitR10MagLifeBwni(MagLifeBwnModeSit *arg0, MagLifeBwn *arg1, int arg2)
{
    int var_v0;

    if (arg2 == 0) {
        if (arg1->m_nextMode[0] == 4) {
            return 1;
        }
        if (Xii_func_0011A028(arg1) == 8) {
            Xiiis_func_0011A320(arg1, 9, -1);
            return 0;
        }
        return 1;
    }
    Xii_func_00123BB8(arg1);
    var_v0 = Xii_func_0011A054(arg1) != 0;
    return var_v0;
}

extern "C" void init__18MagLifeBwnModeFuseR10MagLifeBwn(MagLifeBwnModeFuse *arg0, MagLifeBwn *arg1)
{
    if ((unsigned int) (arg1->m_sctFlag - 2) < 2U) {
        return Xiiiii_func_001233F4(arg1, 2, 0, 0);
    }
    func_00125A20(arg1, 0);
    Xii_func_00124E18(arg1);
    Xiiis_func_0011A320(arg1, (arg1->m_last0 == 3) ? 0x10 : 0xC, -1);
}

extern "C" int term__18MagLifeBwnModeFuseR10MagLifeBwni(MagLifeBwnModeFuse *arg0, MagLifeBwn *arg1, int arg2)
{
    int var_v0;

    if (arg2 == 0) {
        if (arg1->m_nextMode[0] == 3) {
            return 1;
        }
        if (Xii_func_0011A028(arg1) == 0xD) {
            Xiiis_func_0011A320(arg1, 0xE, -1);
            return 0;
        }
        return 1;
    }
    Xii_func_00123BB8(arg1);
    var_v0 = Xii_func_0011A054(arg1) != 0;
    return var_v0;
}

extern "C" void init__18MagLifeBwnModeMoveR10MagLifeBwn(MagLifeBwnModeMove *arg0, MagLifeBwn *arg1)
{
    int idx = arg1->m_unk08;
    if (arg1->m_unkCB8 >= 3) {
        idx = 1;
    }
    int table[4] = { 0x57, 0x4E, 0x60, 0x45 };
    int motion = table[idx] + arg1->m_unk0C;
    arg0->m_motion = motion;
    Xiiis_func_0011A320(arg1, motion, -1);
    Xii_func_00124D7C(arg1);
    arg0->m_state = 0;
}

extern "C" int live__18MagLifeBwnModeMoveR10MagLifeBwn(MagLifeBwnModeMove *arg0, MagLifeBwn *arg1)
{
    int temp_v0;
    int temp_v0_2;

    temp_v0 = Xiif_func_00119B60(arg1, 0, 75.0f);
    arg1->m_sctFlag = temp_v0;
    temp_v0_2 = arg0->m_state;
    if (temp_v0_2 < 0x2000) {
        if (temp_v0_2 >= 0x1000) {
            if (temp_v0 == 0) {
                Xiiis_func_0011A320(arg1, arg0->m_motion, -1);
                arg0->m_state = 0;
            }
        } else {
            if (temp_v0 == 3) {
                Xiiis_func_0011A320(arg1, 0x6B, -1);
                arg0->m_state = 0x1000;
            } else if (temp_v0 == 2) {
                Xiiis_func_0011A320(arg1, 0x69, -1);
                arg0->m_state = 0x1000;
            }
        }
    }
    Xii_func_00123BB8(arg1);
    return 1;
}
