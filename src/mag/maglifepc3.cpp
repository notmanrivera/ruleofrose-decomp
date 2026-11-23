#include "include_asm.h"
#include "mag/maglifepc.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"

extern BedMemory D_006E9800;

struct FileReadReq {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    const char *m_name;
    int m_offset;
    int m_unk14;
    void *m_buf;
    int m_size;
    int m_unk20;
    FileReadReq();
};

class FileReader {
public:
    FileReadReq *m_req;
    int m_unk04;
    FileReader();
    ~FileReader();
    int func_001BE524(FileReadReq *theReq, int theFlag);
};

struct PcWeaponInfo {
    const char *m_motion;
    int m_unk04[5];
}; // size 0x18

extern "C" void X_func_00109B88__8DogActori(DogActor *, int) asm("func_00109B88__8DogActori");
extern "C" int X_func_0010A834__8DogActor(DogActor *) asm("func_0010A834__8DogActor");
extern "C" int X_func_0010A8B8__8DogActorPCc(DogActor *, const char *) asm("func_0010A8B8__8DogActorPCc");
extern "C" int X_func_0010AA5C__8DogActorPCc(DogActor *, const char *) asm("func_0010AA5C__8DogActorPCc");
extern "C" int Xiii_func_0010AA9C__8DogActorPCc(DogActor *, const char *) asm("func_0010AA9C__8DogActorPCc");
extern "C" int X_func_0010AB40__8DogActorPCc(DogActor *, const char *) asm("func_0010AB40__8DogActorPCc");
extern "C" int Xiiifii_func_0010B1B0__8DogActoriifii(DogActor *, int, int, float, int, int) asm("func_0010B1B0__8DogActoriifii");
extern "C" int X_func_0010C17C__8DogActorPCcii(DogActor *, const char *, int, int) asm("func_0010C17C__8DogActorPCcii");
extern "C" int X_func_0010C568__8DogActorP6BedPfhi(DogActor *, BedPfh *, int) asm("func_0010C568__8DogActorP6BedPfhi");
extern "C" float Xfi_func_0010DAD8__8DogActor(DogActor *) asm("func_0010DAD8__8DogActor");
extern "C" int X_getMainMotionNo__C14DogMotionBlend(const DogMotionBlend *) asm("getMainMotionNo__C14DogMotionBlend");
extern "C" void X_func_0011C2AC(MagLifePC *, int) asm("func_0011C2AC");
extern "C" int X_func_0011C520(void) asm("func_0011C520");
extern "C" int X_func_0011CB70(MagLifePC *, int) asm("func_0011CB70");
extern "C" void X_func_0011DF7C(MagLifePC *) asm("func_0011DF7C");
extern "C" void Xiiii_ror_assert(const char *, int, const char *) asm("ror_assert");
extern "C" char *X_strcpy(char *, const char *) asm("strcpy");
extern "C" int func_0011D790(MagLifePC *, int, int, int, int, float);
extern "C" int func_0011D7C0(MagLifePC *, const char *, int, const char *, int, float);
extern "C" void func_0011DC64(MagLifePC *, int, int);

extern const float D_002EA740[];
extern const char D_002EA758[];
extern const char D_002EA7A8[];
extern const char D_002EA7C0[];
extern char D_002971D5[];
extern const int D_00297210[4];
extern PcWeaponInfo D_00298178[];

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

extern "C" float func_0011D720(MagLifePC *arg0)
{
    float temp_f20;

    if ((unsigned int) arg0->m_unkE4 >= 5U) {
        Xiiii_ror_assert(D_002EA758, 0x69, "0 <= m_health_stat && m_health_stat < HEALTH_END");
    }
    temp_f20 = D_002EA740[(unsigned int) arg0->m_unkE4];
    return temp_f20 * Xfi_func_0010DAD8__8DogActor(arg0->m_actor);
}

extern "C" int func_0011D790(MagLifePC *arg0, int arg1, int arg2, int arg3, int arg4, float fparg0)
{
    Xiiii_ror_assert(D_002EA758, 0xBA, D_002EA7A8);
    return -1;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA7A8);

extern "C" int func_0011D7C0(MagLifePC *arg0, const char *arg1, int arg2, const char *arg3, int arg4, float fparg0)
{
    if (arg1 == 0) {
        Xiiii_ror_assert(D_002EA758, 0xC5, "theMotion");
    }
    if (arg0->m_actor == 0) {
        Xiiii_ror_assert(D_002EA758, 0xC6, D_002EA7C0);
    }
    int var_v0 = -1;
    if (arg1 != 0 && arg0->m_actor != 0) {
        int var_s0;
        int var_s5 = -1;
        if (arg0->m_unk54 == 2) {
            char *temp_s3 = D_002971D5;
            char *temp_s6 = temp_s3 - 5;
            X_strcpy(temp_s3, arg1 + 3);
            var_s0 = X_func_0010AB40__8DogActorPCc(arg0->m_actor, temp_s6);
            if (var_s0 < 0) {
                var_s0 = X_func_0010AB40__8DogActorPCc(arg0->m_actor, arg1);
                if (var_s0 < 0) {
                    var_v0 = var_s0;
                    goto end;
                }
            }
            if (arg3 != 0) {
                X_strcpy(temp_s3, arg3 + 3);
                var_s5 = X_func_0010AB40__8DogActorPCc(arg0->m_actor, temp_s6);
                if (var_s5 < 0) {
                    var_s5 = X_func_0010AB40__8DogActorPCc(arg0->m_actor, arg3);
                }
            }
        } else {
            var_s0 = X_func_0010AA5C__8DogActorPCc(arg0->m_actor, arg1);
            if (var_s0 < 0) {
                var_v0 = var_s0;
                goto end;
            }
            if (arg3 != 0) {
                var_s5 = X_func_0010AA5C__8DogActorPCc(arg0->m_actor, arg3);
            }
        }
        return Xiiifii_func_0010B1B0__8DogActoriifii(arg0->m_actor, var_s0, arg2, fparg0, var_s5, arg4);
    }
end:
    return var_v0;
}

INCLUDE_RODATA("asm/nonmatchings/mag/maglifepc3", D_002EA7C0);

extern "C" int func_0011D990(MagLifePC *arg0, int arg1, const char *theFileName, int theIndex)
{
    char work[0x800 + 0x40];
    if (!theFileName) {
        Xiiii_ror_assert(D_002EA758, 0xFC, "theFileName");
    }
    X_func_00109B88__8DogActori(arg0->m_actor, arg1);
    FileReader reader;
    FileReadReq req;
    req.m_unk08 = 1;
    req.m_name = theFileName;
    req.m_buf = (void *)(((int)work / 64 + 1) * 64);
    req.m_size = 0x800;
    reader.func_001BE524(&req, 0);
    BedPfh pfh1(req.m_buf);
    if (pfh1.getFileOffset(0) != 2048) {
        Xiiii_ror_assert(D_002EA758, 0x114, "pfh1.getFileOffset(0) == (2048)");
    }
    if (!(theIndex >= 0 && theIndex < pfh1.getNumFile())) {
        Xiiii_ror_assert(D_002EA758, 0x116, "theIndex >= 0 && theIndex < pfh1.getNumFile()");
    }
    int size = pfh1.getFileSize(theIndex);
    if (size <= 0) {
        Xiiii_ror_assert(D_002EA758, 0x11C, D_002EA7A8);
        return 0;
    }
    int bytes = (size + 2047) / 2048 * 2048;
    void *p = D_006E9800.alloc(bytes, D_002EA758, 0x121, 0, 1);
    if (!(p != __null)) {
        Xiiii_ror_assert(D_002EA758, 0x122, "p != __null");
    }
    if (!((((int)p) % 64) == 0)) {
        Xiiii_ror_assert(D_002EA758, 0x123, "(((int)p)%64)==0");
    }
    req.m_offset = pfh1.getFileOffset(theIndex);
    req.m_unk14 = 0;
    req.m_buf = p;
    req.m_size = bytes;
    req.m_unk20 = 1;
    reader.func_001BE524(&req, 0);
    BedPfh pfh2(p);
    if (X_func_0010C568__8DogActorP6BedPfhi(arg0->m_actor, &pfh2, arg1) <= 0) {
        D_006E9800.free(p);
        return 0;
    }
    return 1;
}

extern "C" void func_0011DC64(MagLifePC *arg0, int arg1, int arg2)
{
    int temp_s3 = 3;
    if (arg2 >= 0) {
        temp_s3 = arg2;
    }
    X_func_00109B88__8DogActori(arg0->m_actor, temp_s3);
    int var_s2 = 0;
    if (arg1 < 0) {
        switch (arg0->m_unkDC) {
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
            Xiiii_ror_assert(D_002EA758, 0x168, D_002EA7A8);
            break;
        }
    } else {
        var_s2 = arg1;
    }
    X_func_0010C17C__8DogActorPCcii(arg0->m_actor, "data/ch/pc/pc/MOTIONPK.RPK", var_s2, temp_s3);
}

#ifdef NON_MATCHING
// NON_MATCHING: 1 delay slot (lw %lo(D_00297210) before jal func_0011DC64 instead of in delay slot)
extern "C" void func_0011DD40(MagLifePC *arg0)
{
    if (arg0->m_actor != 0) {
        int wep = X_func_0011CB70(arg0, X_func_0011C520());
        arg0->m_unk21C = wep;
        if (X_func_0010A8B8__8DogActorPCc(arg0->m_actor, D_00298178[wep].m_motion) < 0) {
            func_0011DC64(arg0, D_00297210[arg0->m_unk21C], -1);
            X_func_0011DF7C(arg0);
            if (X_getMainMotionNo__C14DogMotionBlend(&arg0->m_actor->m_motion_now) <= 0) {
                X_func_0011C2AC(arg0, 1);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/maglifepc3", func_0011DD40);
#endif

extern "C" int func_0011DDF4(MagLifePC *arg0, int arg1, float fparg0)
{
    if (arg1 < 0) {
        Xiiii_ror_assert(D_002EA758, 0x1E3, "theNo >= 0");
    }
    if (arg0->m_unkF4 < 0) {
        func_0011D790(arg0, arg1, 0, -1, -1, fparg0);
        arg0->m_unkF4 = arg1;
    }
    return -1;
}

extern "C" int func_0011DE78(MagLifePC *arg0, const char *arg1, float fparg0)
{
    int temp_s2;

    if (arg1 == 0) {
        Xiiii_ror_assert(D_002EA758, 0x1F6, "theMotion != __null");
    }
    temp_s2 = Xiii_func_0010AA9C__8DogActorPCc(arg0->m_actor, arg1);
    if (arg0->m_unkF4 < 0) {
        func_0011D7C0(arg0, arg1, 0, 0, -1, fparg0);
        arg0->m_unkF4 = temp_s2;
    }
    return -1;
}

extern "C" int func_0011DF14(MagLifePC *arg0)
{
    if (arg0->m_unkF4 < 0) {
        return 1;
    }
    if (arg0->m_actor == 0) {
        Xiiii_ror_assert(D_002EA758, 0x20E, D_002EA7C0);
    }
    if (X_func_0010A834__8DogActor(arg0->m_actor) == 0) {
        arg0->m_unkF4 = -1;
        return 1;
    }
    return 0;
}
