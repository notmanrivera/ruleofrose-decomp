#include "include_asm.h"
extern "C" int Xiiifii_func_0010B1B0__8DogActoriifii(int, int, int, float, int, int) asm("func_0010B1B0__8DogActoriifii");
extern "C" int Xiiiiiif_func_0011D790(int, int, int, int, int, float) asm("func_0011D790");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xfi_func_0010DAD8__8DogActor(int) asm("func_0010DAD8__8DogActor");
extern "C" int Xiii_func_0010AA9C__8DogActorPCc(int, int) asm("func_0010AA9C__8DogActorPCc");
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern "C" int Xiiiiiif_func_0011D7C0(int, int, int, int, int, float) asm("func_0011D7C0");
extern int D_002EA740;
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00109B88__8DogActori(...) asm("func_00109B88__8DogActori");
extern "C" int X_func_0010A834__8DogActor(...) asm("func_0010A834__8DogActor");
extern "C" int X_func_0010AA5C__8DogActorPCc(...) asm("func_0010AA5C__8DogActorPCc");
extern "C" int X_func_0010AB40__8DogActorPCc(...) asm("func_0010AB40__8DogActorPCc");
extern "C" int X_func_0010B1B0__8DogActoriifii(...) asm("func_0010B1B0__8DogActoriifii");
extern "C" int X_func_0010C17C__8DogActorPCcii(...) asm("func_0010C17C__8DogActorPCcii");
extern "C" int X_func_0011D790(...) asm("func_0011D790");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern "C" int X_strcpy(...) asm("strcpy");
extern const char D_002EA758[];
extern const char D_002EA7A8[];
extern const char D_002EA7C0[];
extern int D_002971D5;
extern int D_00297210[];
extern int D_00298178[];
extern "C" int X_func_0010A8B8__8DogActorPCc(...) asm("func_0010A8B8__8DogActorPCc");
extern "C" int X_func_0011C2AC(...) asm("func_0011C2AC");
extern "C" int X_func_0011C520(...) asm("func_0011C520");
extern "C" int X_func_0011CB70(...) asm("func_0011CB70");
extern "C" int X_func_0011DC64(...) asm("func_0011DC64");
extern "C" int X_func_0011DF7C(...) asm("func_0011DF7C");
extern "C" int X_getMainMotionNo__C14DogMotionBlend(...) asm("getMainMotionNo__C14DogMotionBlend");

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA5F0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA608);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA618);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA628);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA638);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA650);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA660);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA670);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA680);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA690);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA6A8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA6C0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA6D0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA6E0);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA6E8);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA700);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA718);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA728);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA738);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA740);

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA758);

extern "C" float func_0011D720(int arg0)
{
    float temp_f20;

    if ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0xE4) >= 5U) {
        Xiiii_ror_assert((int) D_002EA758, 0x69, (int) "0 <= m_health_stat && m_health_stat < HEALTH_END");
    }
    temp_f20 = ((float *)&D_002EA740)[M2C_FIELD(arg0, unsigned int *, 0xE4)];
    return temp_f20 * Xfi_func_0010DAD8__8DogActor(M2C_FIELD(arg0, int *, 0x58));
}

extern "C" int func_0011D790()
{
    X_ror_assert(D_002EA758, 0xBA, D_002EA7A8);
    return -1;
}


INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA7A8);

extern "C" int func_0011D7C0(int arg0, int arg1, int arg2, int arg3, int arg4, float fparg0)
{
    if (arg1 == 0) {
        X_ror_assert((int) D_002EA758, 0xC5, (int) "theMotion");
    }
    if (M2C_FIELD(arg0, int *, 0x58) == 0) {
        X_ror_assert((int) D_002EA758, 0xC6, (int) D_002EA7C0);
    }
    int var_v0 = -1;
    if (arg1 != 0 && M2C_FIELD(arg0, int *, 0x58) != 0) {
        int var_s0;
        int var_s5 = -1;
        if (M2C_FIELD(arg0, int *, 0x54) == 2) {
            int temp_s3 = (int)&D_002971D5;
            int temp_s6 = temp_s3 - 5;
            X_strcpy(temp_s3, arg1 + 3);
            var_s0 = X_func_0010AB40__8DogActorPCc(M2C_FIELD(arg0, int *, 0x58), temp_s6);
            if (var_s0 < 0) {
                var_s0 = X_func_0010AB40__8DogActorPCc(M2C_FIELD(arg0, int *, 0x58), arg1);
                if (var_s0 < 0) {
                    var_v0 = var_s0;
                    goto end;
                }
            }
            if (arg3 != 0) {
                X_strcpy(temp_s3, arg3 + 3);
                var_s5 = X_func_0010AB40__8DogActorPCc(M2C_FIELD(arg0, int *, 0x58), temp_s6);
                if (var_s5 < 0) {
                    var_s5 = X_func_0010AB40__8DogActorPCc(M2C_FIELD(arg0, int *, 0x58), arg3);
                }
            }
        } else {
            var_s0 = X_func_0010AA5C__8DogActorPCc(M2C_FIELD(arg0, int *, 0x58), arg1);
            if (var_s0 < 0) {
                var_v0 = var_s0;
                goto end;
            }
            if (arg3 != 0) {
                var_s5 = X_func_0010AA5C__8DogActorPCc(M2C_FIELD(arg0, int *, 0x58), arg3);
            }
        }
        return Xiiifii_func_0010B1B0__8DogActoriifii(M2C_FIELD(arg0, int *, 0x58), var_s0, arg2, fparg0, var_s5, arg4);
    }
end:
    return var_v0;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA7C0);

INCLUDE_ASM("asm/nonmatchings/mag/maglifepc3", func_0011D990);

#ifdef NON_MATCHING
// NON_MATCHING: 11 of 55 instructions
extern "C" void func_0011DC64(int arg0, int arg1, int arg2)
{
    int var_s2 = 0;
    int temp_s3 = 3;
    if (arg2 >= 0) {
        temp_s3 = arg2;
    }
    X_func_00109B88__8DogActori(M2C_FIELD(arg0, int *, 0x58), temp_s3);
    if (arg1 < 0) {
        switch (M2C_FIELD(arg0, int *, 0xDC)) {
        case 0:
            return;
        case 1:
            var_s2 = 0;
            break;
        case 2:
            var_s2 = 3;
            break;
        case 3:
            var_s2 = 2;
            break;
        case 4:
            var_s2 = 1;
            break;
        default:
            X_ror_assert((int) D_002EA758, 0x168, (int) D_002EA7A8);
            break;
        }
    } else {
        var_s2 = arg1;
    }
    X_func_0010C17C__8DogActorPCcii(M2C_FIELD(arg0, int *, 0x58), (int) "data/ch/pc/pc/MOTIONPK.RPK", var_s2, temp_s3);
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc3", func_0011DC64);
#endif

#ifdef NON_MATCHING
// NON_MATCHING: 19 of 46 instructions
extern "C" void func_0011DD40(int arg0)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 0x58) != 0) {
        temp_v0 = X_func_0011CB70(arg0, X_func_0011C520());
        M2C_FIELD(arg0, int *, 0x21C) = temp_v0;
        if (X_func_0010A8B8__8DogActorPCc(M2C_FIELD(arg0, int *, 0x58), *(int *)((int)D_00298178 + (temp_v0 * 0x18))) < 0) {
            X_func_0011DC64(arg0, D_00297210[M2C_FIELD(arg0, int *, 0x21C)], -1);
            X_func_0011DF7C(arg0);
            if (X_getMainMotionNo__C14DogMotionBlend(M2C_FIELD(arg0, int *, 0x58) + 0x1E4) <= 0) {
                X_func_0011C2AC(arg0, 1);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc3", func_0011DD40);
#endif

extern "C" int func_0011DDF4(int arg0, int arg1, float fparg0)
{
    if (arg1 < 0) {
        X_ror_assert((int) D_002EA758, 0x1E3, (int) "theNo >= 0");
    }
    if (M2C_FIELD(arg0, int *, 0xF4) < 0) {
        Xiiiiiif_func_0011D790(arg0, arg1, 0, -1, -1, fparg0);
        M2C_FIELD(arg0, int *, 0xF4) = arg1;
    }
    return -1;
}

extern "C" int func_0011DE78(int arg0, int arg1, float fparg0)
{
    int temp_s2;

    if (arg1 == 0) {
        Xiiii_ror_assert((int) D_002EA758, 0x1F6, (int) "theMotion != __null");
    }
    temp_s2 = Xiii_func_0010AA9C__8DogActorPCc(M2C_FIELD(arg0, int *, 0x58), (int) arg1);
    if (M2C_FIELD(arg0, int *, 0xF4) < 0) {
        Xiiiiiif_func_0011D7C0(arg0, arg1, 0, 0, -1, fparg0);
        M2C_FIELD(arg0, int *, 0xF4) = temp_s2;
    }
    return -1;
}

extern "C" int func_0011DF14(int arg0)
{
    if (M2C_FIELD(arg0, int *, 0xF4) < 0) {
        return 1;
    }
    if (M2C_FIELD(arg0, int *, 0x58) == 0) {
        X_ror_assert((int) D_002EA758, 0x20E, (int) D_002EA7C0);
    }
    if (X_func_0010A834__8DogActor(M2C_FIELD(arg0, int *, 0x58)) == 0) {
        M2C_FIELD(arg0, int *, 0xF4) = -1;
        return 1;
    }
    return 0;
}
