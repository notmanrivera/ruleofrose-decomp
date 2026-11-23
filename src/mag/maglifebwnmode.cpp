#include "include_asm.h"
#include "mag/maglifebwn.h"

extern "C" int Xiif_func_00119B60(MagLifeBwn *, int, float) asm("func_00119B60");
extern "C" float Xfi_func_00119FB0(MagLifeBwn *) asm("func_00119FB0");
extern "C" int Xii_func_0011A028(MagLifeBwn *) asm("func_0011A028");
extern "C" int Xii_func_0011A03C(MagLifeBwn *) asm("func_0011A03C");
extern "C" int Xii_func_0011A054(MagLifeBwn *) asm("func_0011A054");
extern "C" int Xii_func_00123BB8(MagLifeBwn *) asm("func_00123BB8");
extern "C" int Xii_func_00124150(MagLifeBwn *) asm("func_00124150");
extern "C" int Xii_func_00124D7C(MagLifeBwn *) asm("func_00124D7C");
extern "C" int Xii_func_00124E18(MagLifeBwn *) asm("func_00124E18");
extern "C" int Xii_func_00125014(MagLifeBwn *) asm("func_00125014");
extern "C" int X_live__14MagLifeBwnModeR10MagLifeBwn(MagLifeBwnMode *, MagLifeBwn *) asm("live__14MagLifeBwnModeR10MagLifeBwn");
extern "C" void Xiiii_ror_assert(const char *, int, const char *) asm("ror_assert");
extern "C" int Xiiis_func_0011A320(MagLifeBwn *, int, short) asm("func_0011A320");
extern const char D_002EBC70[];
extern "C" void func_001264F8(MagLifeBwnModeRotate *, MagLifeBwn *);

extern "C" void init__18MagLifeBwnModePathR10MagLifeBwn(MagLifeBwnModePath *arg0, MagLifeBwn *arg1)
{
    arg0->m_unk0C = 0;
    Xii_func_0011A03C(arg1);
    Xii_func_00125014(arg1);
    Xii_func_00124D7C(arg1);
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifebwnmode", D_002EBC70);

INCLUDE_ASM("asm/nonmatchings/mag/maglifebwnmode", live__18MagLifeBwnModePathR10MagLifeBwn);

extern "C" int term__18MagLifeBwnModePathR10MagLifeBwni(MagLifeBwnModePath *arg0, MagLifeBwn *arg1, int arg2)
{
    if (arg2 == 0) {
        if (arg0->m_unk08 == 0x1000) {
            return 0;
        }
        int st = Xii_func_0011A028(arg1);
        if (st >= 0x60 && st < 0x68) {
            Xiiis_func_0011A320(arg1, 0x68, -1);
            return 0;
        }
        return 1;
    }
    if (arg0->m_unk08 == 0x1000) {
        Xii_func_00124150(arg1);
        int sct = Xiif_func_00119B60(arg1, 0, 75.0f);
        arg1->m_sctFlag = sct;
        if (sct == 0) {
            arg0->m_unk08 = 0;
        }
        return 1;
    }
    Xii_func_00123BB8(arg1);
    return Xii_func_0011A054(arg1) != 0;
}

extern "C" void init__18MagLifeBwnModeTurnR10MagLifeBwn(MagLifeBwnModeTurn *arg0, MagLifeBwn *arg1)
{
    Xiiis_func_0011A320(arg1, arg1->m_unk0C + 0x2B, -1);
    Xii_func_00124D7C(arg1);
}

extern "C" void init__17MagLifeBwnModeOneR10MagLifeBwn(MagLifeBwnModeOne *arg0, MagLifeBwn *arg1)
{
    arg1->m_unkCC0 = 0;
    Xiiis_func_0011A320(arg1, 0, -1);
    Xiiis_func_0011A320(arg1, arg1->m_unk08, -1);
    Xii_func_00124E18(arg1);
}

extern "C" int live__17MagLifeBwnModeOneR10MagLifeBwn(MagLifeBwnModeOne *arg0, MagLifeBwn *arg1)
{
    if (arg1->m_unk0C == 0) {
        return X_live__14MagLifeBwnModeR10MagLifeBwn(arg0, arg1);
    }
    if (arg1->m_unkCC0 == 0) {
        Xii_func_00123BB8(arg1);
        if (Xii_func_0011A054(arg1) != 0) {
            arg1->m_unkCC0 = 1;
        }
    }
    return 0;
}

extern "C" void init__18MagLifeBwnModeWallR10MagLifeBwn(MagLifeBwnModeWall *arg0, MagLifeBwn *arg1)
{
    int table[4] = { 0x1D, 0x1F, 0x21, 0x23 };
    Xiiis_func_0011A320(arg1, table[arg1->m_unk08 % 4], -1);
    Xii_func_00124E18(arg1);
}

extern "C" void init__20MagLifeBwnModeRotateR10MagLifeBwn(MagLifeBwnModeRotate *arg0, MagLifeBwn *arg1)
{
    arg0->m_target_rot = *(float *)&arg1->m_unk08;
    func_001264F8(arg0, arg1);
}

extern "C" void func_001264F8(MagLifeBwnModeRotate *arg0, MagLifeBwn *arg1)
{
    float temp_f1;
    float var_f1;
    int var_a1;

    temp_f1 = arg0->m_target_rot;
    if (!(temp_f1 >= -3.141593039035797f) || !(temp_f1 < 3.141593039035797f)) {
        Xiiii_ror_assert(D_002EBC70, 0x278, "(m_target_rot >= -DOG_PI) && (m_target_rot < DOG_PI)");
    }
    arg1->m_unkCC0 = 0;
    var_f1 = arg0->m_target_rot - Xfi_func_00119FB0(arg1);
    if (var_f1 < -3.141593039035797f) {
        var_f1 += 6.283186078071594f;
    } else if (var_f1 >= 3.141593039035797f) {
        var_f1 -= 6.283186078071594f;
    }
    var_a1 = 0x39;
    arg0->m_diff_rot = var_f1;
    if (!(var_f1 < -1.5707962810993195f)) {
        var_a1 = 0x2C;
        if (!(var_f1 < -0.7853981405496597f)) {
            var_a1 = 0x2B;
            if (!(var_f1 < -0.034906589426100254f)) {
                var_a1 = 0x3A;
                if (!(var_f1 > 1.5707962810993195f)) {
                    var_a1 = 0x2F;
                    if (!(var_f1 > 0.7853981405496597f)) {
                        if (var_f1 > 0.034906589426100254f) {
                            var_a1 = 0x2E;
                            goto block_16;
                        }
                        arg1->m_unkCC0 = 1;
                        arg1->m_unk08 = 1;
                        return;
                    }
                }
            }
        }
    }
block_16:
    Xiiis_func_0011A320(arg1, var_a1, -1);
    Xii_func_00124D7C(arg1);
}

extern "C" int live__20MagLifeBwnModeRotateR10MagLifeBwn(MagLifeBwnModeRotate *arg0, MagLifeBwn *arg1)
{
    if (arg1->m_unkCC0 != 0) {
        return 0;
    }
    if (Xii_func_00123BB8(arg1) == -1) {
        Xiiis_func_0011A320(arg1, 2, -1);
        return 0;
    }
    float tmp = arg0->m_target_rot - Xfi_func_00119FB0(arg1);
    float diff;
    if (tmp < -DOG_PI) {
        diff = tmp + DOG_PI2;
    } else {
        diff = tmp;
        if (diff >= DOG_PI) {
            diff -= DOG_PI2;
        }
    }
    if ((diff > -0.034906589426100254f && diff < 0.034906589426100254f) || (diff * arg0->m_diff_rot < 0.0f)) {
        arg1->m_unkCC0 = 1;
    }
    arg0->m_diff_rot = diff;
    if (Xii_func_0011A054(arg1) != 0) {
        func_001264F8(arg0, arg1);
    }
    return 0;
}
