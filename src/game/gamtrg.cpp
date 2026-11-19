#include "include_asm.h"
#include "game/gamtrg.h"
#include "game/gamman.h"

#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))

struct GamTrgDogActor {
    unsigned char pad0[0x40];
    float pos[4];
    float rot[4];
    unsigned char pad60[0x30];
    int m_dirty;                        // +0x90
    unsigned char pad94[0x4D0 - 0x94];

    void getPos(float *out)
    {
        out[0] = pos[0];
        out[1] = pos[1];
        out[2] = pos[2];
    }
    void getRot(float *out)
    {
        out[0] = rot[0];
        out[1] = rot[1];
        out[2] = rot[2];
    }
};

struct GamTrgCopy64 {
    long m_data[0xB0 / 8];
};

struct GamTrgVec2 {
    float x, y;
} __attribute__((aligned(16)));

struct GamTrgMapInfo {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    float m_unk20;
    float m_unk24;
    float m_unk28;
};

struct GamTrgSecta {
    unsigned char m_unk00[0x1C];
    float m_minX;                       // +0x1C
    float m_minZ;                       // +0x20
    float m_maxX;                       // +0x24
    float m_maxZ;                       // +0x28
};

struct GamTrgUnqHeader {
    unsigned int m_unk00[4];
    int m_off[10];                      // +0x10..+0x37
};

extern int D_006FBD80;
extern GamTrgDogActor D_006FE6A0[];

static inline GamTrgDogActor *getDogActor(void *base, int idx)
{
    return (GamTrgDogActor *)(((char *)base + idx * 0x4D0) + 0x2920);
}

extern "C" char vtbl_7ObjStat[] asm("_vt$7ObjStat");

extern "C" int X_func_001C6FE0(void *, int, int) asm("func_001C6FE0");
extern "C" void X_func_001DE104(GamTrgMan *, GamTrgElem) asm("func_001DE104");
extern "C" void X_func_001D35AC(void *, float *, void *, int, int, int, float) asm("func_001D35AC");
extern "C" void *X_memset(void *, int, __SIZE_TYPE__) asm("memset");
extern "C" void func_001DDDAC(GamTrgMan *);
extern "C" void func_001DDC80(GamTrgMan *);
extern "C" void X_func_002113DC(void *, int, int, int, int, int, int, const char *) asm("func_002113DC");
extern "C" int X_func_001D05F4(void *, unsigned int, float *) asm("func_001D05F4");
extern "C" void X_func_001E0C2C(void *, int, int, unsigned int) asm("func_001E0C2C");
extern "C" void X_func_001D7EB8(void *, int) asm("func_001D7EB8");
extern "C" void func_001D890C(ObjStat *, float *);
extern "C" int func_001D8D28(ObjStat *, int *);
extern "C" int *X_func_001D7F48(void *, float *, int) asm("func_001D7F48");
extern "C" int X_func_001F6878(unsigned int) asm("func_001F6878");
extern "C" void *X_alloc__9BedMemory(void *, int, const char *, int, int, int) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_heapFree(void *) asm("heapFree__FPv");
extern "C" void X_func_001E8F88(int) asm("func_001E8F88");
extern "C" int *X_func_001D811C(void *, int, void *, int) asm("func_001D811C");
extern "C" int X_func_001333C0(void *, int, float) asm("func_001333C0");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_func_001D5BC8(void *, int *, int) asm("func_001D5BC8");
extern "C" int X_func_001E7724(void *, int) asm("func_001E7724");
extern "C" int X_func_001E7D7C(void *, int) asm("func_001E7D7C");
extern "C" int X_func_001E7414(void *, int, int) asm("func_001E7414");
extern "C" float X_func_001D817C(void *, int *, float *, int) asm("func_001D817C");
extern "C" int X_func_001C6C28(void *) asm("func_001C6C28");
extern "C" void func_001DA07C(ACHRstat *);
extern "C" GamTrgMapInfo *X_func_0017EA44(void *, int) asm("func_0017EA44");
extern "C" void func_001D89C4(ObjStat *, float *);
extern "C" int X_setActorRot(void *, int, const float *) asm("setActorRot__9MagSystemiPCf");
extern "C" int *X_func_001D8064(void *, float *, int *, int) asm("func_001D8064");
extern "C" void X_func_0017EB3C(void *, void *, int, int) asm("func_0017EB3C");
extern "C" void X_func_0017EBAC(void *, void *, int, int) asm("func_0017EBAC");
extern "C" GamUnq200 *func_001DBFA0(GamUnqMan *, unsigned short);
extern "C" int X_func_001D966C_v(...) asm("func_001D966C");

extern int D_006E9800;
extern int D_00298EE0;
extern int D_002D8F60;
extern int D_006E9840;
extern int D_007A3D80;
extern int D_007A4440;
extern const char D_002FD640[];

extern ACHRstat::GetterSlot D_002FC418;
extern ACHRstat::GetterSlot D_002FC420;
extern ACHRstat::GetterSlot D_002FC428;
extern ACHRstat::GetterSlot D_002FC430;
extern ACHRstat::GetterSlot D_002FC438;
extern ACHRstat::GetterSlot D_002FC440;
extern ACHRstat::GetterSlot D_002FC448;
extern ACHRstat::GetterSlot D_002FC450;
extern ACHRstat::GetterSlot D_002FC458;
extern ACHRstat::GetterSlot D_002FC460;
extern ACHRstat::GetterSlot D_002FC468;
extern ACHRstat::GetterSlot D_002FC470;
extern ACHRstat::GetterSlot D_002FC478;
extern ACHRstat::GetterSlot D_002FC480;
extern ACHRstat::GetterSlot D_002FC488;
extern ACHRstat::GetterSlot D_002FC490;
extern ACHRstat::GetterSlot D_002FC498;
extern ACHRstat::GetterSlot D_002FC4A0;
extern ACHRstat::GetterSlot D_002FC4A8;
extern ACHRstat::GetterSlot D_002FC4B0;
extern ACHRstat::GetterSlot D_002FC4B8;
extern ACHRstat::GetterSlot D_002FC4C0;
extern ACHRstat::GetterSlot D_002FC4C8;
extern ACHRstat::GetterSlot D_002FC4D0;
extern ACHRstat::GetterSlot D_002FC4D8;
extern ACHRstat::GetterSlot D_002FC4E0;
extern ACHRstat::GetterSlot D_002FC4E8;
extern ACHRstat::GetterSlot D_002FC4F0;
extern ACHRstat::GetterSlot D_002FC4F8;
extern ACHRstat::GetterSlot D_002FC500;
extern ACHRstat::GetterSlot D_002FC508;
extern ACHRstat::GetterSlot D_002FC510;

extern "C" void func_001D859C(GamTrg0 *arg0, int arg1)
{
    X_heapFree(arg0->m_keys);
    X_heapFree(arg0->m_vals);
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

extern "C" void func_001D85F8(GamTrg0 *arg0, unsigned short arg1, unsigned short arg2)
{
    unsigned int i;

    for (i = 0; i < arg0->m_count; i++) {
        if (arg0->m_vals[i] == 0) {
            break;
        }
    }
    if (i < arg0->m_count) {
        arg0->m_vals[i] = arg2;
        arg0->m_keys[i] = arg1;
    }
}

extern "C" void func_001D8674(GamTrg0 *arg0, int arg1)
{
    unsigned int i;

    for (i = 0; i < arg0->m_count; i++) {
        if (arg0->m_vals[i] == arg1) {
            break;
        }
    }
    if (i < arg0->m_count) {
        arg0->m_keys[i] = 0;
        arg0->m_vals[i] = 0;
        while (i < arg0->m_count - 1 && arg0->m_vals[i] == 0) {
            arg0->m_keys[i] = arg0->m_keys[i + 1];
            arg0->m_vals[i] = arg0->m_vals[i + 1];
            i++;
        }
        arg0->m_keys[i] = 0;
        arg0->m_vals[i] = 0;
    }
}

extern "C" int func_001D8778(GamTrg0 *arg0, int arg1)
{
    unsigned int i;
    int ret = arg0->m_defaultVal;

    for (i = 0; i < arg0->m_count; i++) {
        if (arg0->m_vals[i] == 0) {
            break;
        }
        if (arg1 == arg0->m_keys[i]) {
            ret = arg0->m_vals[i];
            break;
        }
    }
    return (i == arg0->m_count) ? 0 : ret;
}

extern "C" void func_001D87F4(ObjStat *arg0, int arg1, int arg2, int arg3, unsigned short arg4)
{
    *(void **)((char *)arg0 + 0x258) = vtbl_7ObjStat;
    arg0->m_pool.init();
    arg0->m_oid = arg2;
    arg0->m_uid = arg4;
    arg0->m_chrID = arg3;
    arg0->m_curStat = arg1;
    arg0->m_secta = 0;
    arg0->m_unk110 = 0;
    arg0->m_areaNo = 0;
    arg0->m_flgV = 0;
}

extern "C" void Xv_ObjStatDtor(ObjStat *arg0, int arg1) asm("_$_7ObjStat");
extern "C" void Xv_ObjStatDtor(ObjStat *arg0, int arg1)
{
    *(void **)((char *)arg0 + 0x258) = vtbl_7ObjStat;
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

extern "C" void func_001D88FC(ObjStat *arg0)
{
    arg0->m_secta = 0;
    arg0->m_unk110 = 0;
    arg0->m_sectaKeep = 0;
}

extern "C" void func_001D890C(ObjStat *arg0, float *arg1)
{
    int chrID = arg0->m_chrID;
    if (chrID == -1) {
        arg1[0] = arg0->m_posParam[0];
        arg1[1] = arg0->m_posParam[1];
        arg1[2] = arg0->m_posParam[2];
        return;
    }
    GamTrgDogActor *actor = &D_006FE6A0[chrID];
    arg1[0] = actor->pos[0];
    arg1[1] = actor->pos[1];
    arg1[2] = actor->pos[2];
}

extern "C" void func_001D8964(ObjStat *arg0, float *arg1)
{
    int chrID = arg0->m_chrID;
    if (chrID == -1) {
        arg1[0] = arg0->m_rotParam[0];
        arg1[1] = arg0->m_rotParam[1];
        arg1[2] = arg0->m_rotParam[2];
        return;
    }
    GamTrgDogActor *actor = &D_006FE6A0[chrID];
    arg1[0] = actor->rot[0];
    arg1[1] = actor->rot[1];
    arg1[2] = actor->rot[2];
}

extern "C" int func_001D89BC()
{
    return 0;
}

extern "C" void func_001D89C4(ObjStat *arg0, float *arg1)
{
    arg0->m_posParam[0] = arg1[0];
    arg0->m_posParam[1] = arg1[1];
    arg0->m_posParam[2] = arg1[2];
    float *pos = arg0->m_posParam;
    int chrID = arg0->m_chrID;
    if (chrID != -1) {
        GamTrgDogActor *actor = &D_006FE6A0[chrID];
        actor->pos[0] = pos[0];
        actor->pos[1] = pos[1];
        actor->pos[2] = pos[2];
        actor->m_dirty = 1;
        int *secta = arg0->m_secta;
        if (secta == 0 || (arg0->m_flg & 0x40)) {
            func_001D8D28(arg0, X_func_001D8064(&D_007812C0, pos, secta, (((unsigned int)arg0->m_oid >> 0x17) & 0x1F) == 2));
        }
    }
}

extern "C" void func_001D8A8C(ObjStat *arg0, float *arg1)
{
    int chrID = arg0->m_chrID;
    arg0->m_rotParam[0] = arg1[0];
    arg0->m_rotParam[1] = arg1[1];
    arg0->m_rotParam[2] = arg1[2];
    if (chrID != -1) {
        X_setActorRot(&D_006E9840, chrID, arg0->m_rotParam);
    }
}

extern "C" int func_001D8ADC(ObjStat *arg0, float *arg1)
{
    int *a = X_func_001D8064(&D_007812C0, arg1, arg0->m_secta, (((unsigned int)arg0->m_oid >> 0x17) & 0x1F) == 2);
    if (a != 0) {
        func_001D8D28(arg0, a);
        arg1[1] = arg0->m_posParam[1];
        func_001D89C4(arg0, arg1);
        return 1;
    }
    return 0;
}

extern "C" int func_001D8B5C(ObjStat *arg0, float *arg1)
{
    return X_func_001D8064(&D_007812C0, arg1, arg0->m_secta,
                           (((unsigned int)arg0->m_oid >> 0x17) & 0x1F) == 2) != 0;
}

extern "C" void func_001D8B9C(ObjStat *arg0, float *arg1)
{
    int *secta = X_func_001D8064(&D_007812C0, arg1, arg0->m_secta, (((unsigned int)arg0->m_oid >> 0x17) & 0x1F) == 2);
    func_001D8D28(arg0, secta);
    float y = X_func_001D817C(&D_007812C0, secta, arg1, 0);
    if (y != 100000.0f) {
        arg1[1] = y;
    }
    func_001D89C4(arg0, arg1);
}

extern "C" float func_001D8C50(ObjStat *arg0)
{
    int *var_s2 = 0;

    if (arg0->m_secta == 0) {
        int r = X_func_001F6878((unsigned int)arg0->m_oid);
        X_func_001D7EB8(&D_007812C0, r);
        var_s2 = X_func_001D7F48(&D_007812C0, arg0->m_posParam, 0);
        X_func_001D7EB8(&D_007812C0, 0);
        if (var_s2 != 0) {
            func_001D8D28(arg0, var_s2);
        } else {
            return 0.0f;
        }
    }
    func_001D890C(arg0, arg0->m_posParam);
    return X_func_001D817C(&D_007812C0, var_s2, arg0->m_posParam, 0);
}

extern "C" int func_001D8D28(ObjStat *arg0, int *arg1)
{
    unsigned int flg = arg0->m_flg;
    if (flg & 0x40) {
        if (!(flg & 0x10000000)) {
            X_func_001D5BC8(&D_007812C0, arg1, arg0->m_oid);
        }
        arg0->m_secta = arg1;
        arg0->m_unk110 = arg1;
        if (arg1 != 0) {
            arg0->m_sectaKeep = arg1;
            arg0->m_keepPos[0] = arg0->m_posParam[0];
            arg0->m_keepPos[1] = arg0->m_posParam[1];
            arg0->m_keepPos[2] = arg0->m_posParam[2];
            arg0->m_keepPos[3] = arg0->m_posParam[3];
        }
        return 1;
    }
    arg0->m_secta = arg1;
    arg0->m_unk110 = arg1;
    return 0;
}

extern "C" void func_001D8DC4(ObjStat *arg0)
{
    float *pos = arg0->m_posParam;
    int chrID = arg0->m_chrID;
    GamTrgDogActor *actor;
    float x;
    float z;
    GamTrgSecta *secta;
    int *newSecta;

    if ((chrID != -1) && ((actor = &D_006FE6A0[chrID], x = actor->pos[0], arg0->m_posParam[0] = x, pos[1] = actor->pos[1], pos[2] = actor->pos[2], secta = (GamTrgSecta *)arg0->m_secta, (secta == 0)) || !(secta->m_minX <= x) || !(x <= secta->m_maxX) || (z = arg0->m_posParam[2], !(secta->m_minZ <= z)) || !(z <= secta->m_maxZ))) {
        newSecta = X_func_001D8064(&D_007812C0, pos, (int *)secta, (((unsigned int)arg0->m_oid >> 0x17) & 0x1F) == 2);
        if (newSecta != 0) {
            func_001D8D28(arg0, newSecta);
        }
    }
}

extern "C" void func_001D8EA8(ObjStat *arg0)
{
    int *secta = X_func_001D8064(&D_007812C0, arg0->m_posParam, arg0->m_secta, (((unsigned int)arg0->m_oid >> 0x17) & 0x1F) == 2);
    if (secta != 0) {
        arg0->m_unk110 = 0;
        func_001D8D28(arg0, secta);
    }
}

// NON_MATCHING: 16/58 differ, 2 relocs differ, 8 edits
#ifdef NON_MATCHING
extern "C" void func_001D8F04(ObjStat *arg0, u_long128 *arg1)
{
    GamTrgDogActor *actor = &D_006FE6A0[arg0->m_chrID];
    float *pos = arg0->m_posParam;
    pos[0] = actor->pos[0];
    pos[1] = actor->pos[1];
    pos[2] = actor->pos[2];
    *arg1 = *(u_long128 *)pos;
    GamTrgSecta *secta = (GamTrgSecta *)arg0->m_secta;
    GamMan *mgr = &D_007812C0;
    float x;
    float z;
    if ((secta == 0) || (x = pos[0], !(secta->m_minX <= x)) || !(x <= secta->m_maxX) || (z = arg0->m_posParam[2], !(secta->m_minZ <= z)) || !(z <= secta->m_maxZ)) {
        int *newSecta = X_func_001D8064(mgr, pos, (int *)secta, (((unsigned int)arg0->m_oid >> 0x17) & 0x1F) == 2);
        if (newSecta != 0) {
            func_001D8D28(arg0, newSecta);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D8F04);
#endif

extern "C" void func_001D8FEC(ObjStat *arg0, int arg1)
{
    float buf[4];

    func_001D8D28(arg0, X_func_001D811C(&D_007812C0, arg1, buf, 0));
    if (arg0->m_secta != 0) {
        func_001D89C4(arg0, buf);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9044);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D932C);

// NON_MATCHING: 18/41 differ, 1 reloc differs (size 0xA4, game 0xA8), 11 edits
#ifdef NON_MATCHING
extern "C" void X_func_001D5DA0(void *, int) asm("func_001D5DA0");
struct DogEntityStub_d95c4 {
    char pad0[0x94];
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(bool);
    char pad98[0x4D0 - 0x98];
};
extern DogEntityStub_d95c4 X_D_006FE6A0_d95c4[] asm("D_006FE6A0");
extern "C" void func_001D95C4(ObjStat *arg0, int arg1)
{
    int idx;

    if (arg1 != 0) {
        if (arg0->m_flg & 0x40) {
            X_func_001D5DA0(&D_007812C0, arg0->m_oid);
        }
    } else {
        if (arg0->m_flg & 0x40) {
            func_001D8EA8(arg0);
        }
    }
    idx = arg0->m_chrID;
    if (idx != -1) {
        X_D_006FE6A0_d95c4[idx].vf8(arg1 != 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D95C4);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D966C);

extern "C" void func_001D96E0(ObjStat *arg0)
{
    arg0->m_secta = 0;
    arg0->m_unk110 = 0;
}

extern "C" int func_001D96EC(ObjStat *arg0, ObjStatSave *arg1)
{
    if (arg0->m_chrID != -1) {
        getDogActor(&D_006FBD80, arg0->m_chrID)->getPos(arg0->m_posParam);
        getDogActor(&D_006FBD80, arg0->m_chrID)->getRot(arg0->m_rotParam);
    }
    *arg1 = *(ObjStatSave *)&arg0->m_oid;
    return 0xB0;
}

extern "C" int func_001D9830(ObjStat *arg0, const ObjStatSave *arg1)
{
    *(ObjStatSave *)&arg0->m_oid = *arg1;
    arg0->m_sectaKeep = 0;
    arg0->m_unk110 = 0;
    arg0->m_secta = 0;
    return 0xB0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9908);

extern "C" void func_001D9B2C(ACHRstat *arg0)
{
    X_memset(arg0->m_unk280, 0, 0x109);
    arg0->m_getters[0] = D_002FC418;
    arg0->m_getters[1] = D_002FC420;
    arg0->m_getters[2] = D_002FC428;
    arg0->m_getters[3] = D_002FC430;
    arg0->m_getters[4] = D_002FC438;
    arg0->m_getters[5] = D_002FC440;
    arg0->m_getters[6] = D_002FC448;
    arg0->m_getters[7] = D_002FC450;
    arg0->m_getters[9] = D_002FC458;
    arg0->m_getters[23] = D_002FC460;
    arg0->m_getters[10] = D_002FC468;
    arg0->m_getters[11] = D_002FC470;
    arg0->m_getters[12] = D_002FC478;
    arg0->m_getters[13] = D_002FC480;
    arg0->m_getters[14] = D_002FC488;
    arg0->m_getters[15] = D_002FC490;
    arg0->m_getters[16] = D_002FC498;
    arg0->m_getters[17] = D_002FC4A0;
    arg0->m_getters[18] = D_002FC4A8;
    arg0->m_getters[19] = D_002FC4B0;
    arg0->m_getters[20] = D_002FC4B8;
    arg0->m_getters[21] = D_002FC4C0;
    arg0->m_getters[22] = D_002FC4C8;
    arg0->m_getters[24] = D_002FC4D0;
    arg0->m_getters[25] = D_002FC4D8;
    arg0->m_getters[26] = D_002FC4E0;
    arg0->m_getters[27] = D_002FC4E8;
    arg0->m_getters[28] = D_002FC4F0;
    arg0->m_getters[29] = D_002FC4F8;
    arg0->m_getters[30] = D_002FC500;
    arg0->m_getters[31] = D_002FC508;
    arg0->m_getters[32] = D_002FC510;
}

extern "C" void func_001D9E9C(ACHRstat *arg0)
{
    X_func_001D966C_v();
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_unk3E8) != 0) {
        X_func_001E7724(&D_007A3D80, arg0->m_unk3E8);
    }
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_unk3E4) != 0) {
        X_func_001E7724(&D_007A3D80, arg0->m_unk3E4);
    }
}

extern "C" void func_001D9F08(void) {
}

extern "C" void func_001D9F10(ACHRstat *arg0, int arg1)
{
    arg0->m_secta = 0;
    arg0->m_unk110 = 0;
    if (arg1 != 0) {
        arg0->m_sectaKeep = 0;
    }
    func_001DA07C(arg0);
}

extern "C" void func_001D9F40(ACHRstat *arg0)
{
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_mtnTaskID) != 0) {
        return X_func_001E8F88(arg0->m_unk3D0);
    }
}

// NON_MATCHING: 13/52 differ (size 0xD0, game 0xD8), 7 edits
#ifdef NON_MATCHING
extern "C" float X_func_00133440(void *, int) asm("func_00133440");
extern "C" int X_func_0010A834__8DogActor(GamTrgDogActor *) asm("func_0010A834__8DogActor");
extern "C" int func_001D9F84(ACHRstat *arg0)
{
    int temp_s2 = X_func_0010A834__8DogActor(getDogActor(&D_006FBD80, arg0->m_chrID)) == 0;
    if (arg0->m_flg & 0x100) {
        if (X_func_00133440(&D_006FBD80, arg0->m_chrID) < 0.0f) {
            if (X_func_00133440(&D_006FBD80, arg0->m_chrID) >= -0.0000001f) {
                return 0;
            }
        } else {
            if (X_func_00133440(&D_006FBD80, arg0->m_chrID) <= 0.0000001f) {
                return 0;
            }
        }
    }
    return temp_s2;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001D9F84);
#endif

extern "C" int func_001DA05C(ACHRstat *arg0)
{
    return ~arg0->m_rotTaskID == 0;
}

extern "C" void func_001DA06C(void) {
}

extern "C" void func_001DA074(void) {
}

extern "C" void func_001DA07C(ACHRstat *arg0)
{
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_mtnTaskID) != 0) {
        X_func_001E7724(&D_007A3D80, arg0->m_mtnTaskID);
    }
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_moveTaskID) != 0) {
        X_func_001E7724(&D_007A3D80, arg0->m_moveTaskID);
    }
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_unk3E0) != 0) {
        X_func_001E7724(&D_007A3D80, arg0->m_unk3E0);
    }
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_rotTaskID) != 0) {
        X_func_001E7724(&D_007A3D80, arg0->m_rotTaskID);
    }
    arg0->m_mtnTaskID = -1;
    arg0->m_moveTaskID = -1;
    arg0->m_unk3E0 = -1;
    arg0->m_rotTaskID = -1;
}

extern "C" void func_001DA130(ACHRstat *arg0, int arg1, int arg2)
{
    if (arg2 != 0) {
        X_func_001E7414(&D_007A3D80, arg0->m_mtnTaskID, arg1);
    }
    X_func_001E7414(&D_007A3D80, arg0->m_moveTaskID, arg1);
    X_func_001E7414(&D_007A3D80, arg0->m_unk3E0, arg1);
    X_func_001E7414(&D_007A3D80, arg0->m_rotTaskID, arg1);
}

extern "C" void func_001DA1B4(ACHRstat *arg0)
{
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_moveTaskID) != 0) {
        X_func_001E7724(&D_007A3D80, arg0->m_moveTaskID);
    }
    if (X_func_001E7D7C(&D_007A3D80, arg0->m_unk3E0) != 0) {
        X_func_001E7724(&D_007A3D80, arg0->m_unk3E0);
    }
    arg0->m_moveTaskID = -1;
    arg0->m_unk3E0 = -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DA228);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DA740);

// D_002FC418 (0x2FC418): the end of game/gamstat's .rodata now (config/splits_manual.tsv)

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC420);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC428);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC430);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC438);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC440);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC448);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC450);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC458);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC460);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC468);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC470);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC478);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC480);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC488);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC490);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC498);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4D0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4F0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC4F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC500);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC508);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC510);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DAC8C);

extern "C" int func_001DB17C(ObjStat *arg0, int arg1)
{
    return arg0->m_unk1B0[arg1];
}

extern "C" void func_001DB18C(ObjStat *arg0, int arg1, int arg2)
{
    arg0->m_unk1B0[arg1] = arg2;
}

extern "C" void func_001DB19C(ObjStat *arg0, int arg1, int arg2)
{
    arg0->m_unk1B0[arg1] += arg2;
}

extern "C" void func_001DB1B8(ACHRstat *arg0, float fparg0)
{
    int off = 0x12540;

    arg0->m_unk418 = fparg0;
    X_func_001333C0((char *)&D_006E9840 + off, arg0->m_chrID, fparg0);
}

// NON_MATCHING: 5/75 differ, 5 edits
#ifdef NON_MATCHING
static inline GamUnqMan *gamSub22220_db1f0() { void *p = (void *)&D_007812C0; return (GamUnqMan *)((char *)p + 0x22220); }
extern "C" void func_001DB1F0(FCHRstat *arg0, int arg1)
{
    unsigned short id = arg1;
    arg0->m_colPrm.m_unk00 = 2;
    arg0->m_colPrm.m_unk04 = 2;
    arg0->m_colPrmKeep = arg0->m_colPrm;
    arg0->m_secta = 0;
    arg0->m_unk110 = 0;
    arg0->m_inuFunc = -1;
    arg0->m_unk13C = -1;
    arg0->m_attachID = -1;
    arg0->m_flg = 0;
    arg0->m_unq = 0;

    switch (id >> 9) {
    case 6:
    case 7:
    case 8:
        break;
    case 4:
        arg0->m_flg = 0;
        break;
    case 5: {
        GamUnq200 *p = func_001DBFA0(gamSub22220_db1f0(), id);
        arg0->m_unk134 = 0;
        arg0->m_unk288 = p;
        arg0->m_flg = p->m_flg;
        arg0->m_unk290 = 1;
        arg0->m_unk284 = p->m_sub80;
        arg0->m_unq = p;
        break;
    }
    case 9:
        arg0->m_unk28C = -1;
        arg0->m_unk294 = -1;
        break;
    }

    if (arg0->m_unq != 0) {
        arg0->m_smellUid[0] = arg0->m_unq->m_common.m_smellUid1;
        arg0->m_smellUid[1] = arg0->m_unq->m_common.m_smellUid2;
        arg0->m_smellUid[2] = arg0->m_unq->m_common.m_smellUid3;
        arg0->m_smellRange = arg0->m_unq->m_common.m_smellRange;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB1F0);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB31C);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DB520);

extern "C" void func_001DB71C(ObjStat *arg0, float *arg1)
{
    int chrID = arg0->m_chrID;
    if (chrID == -1) {
        arg1[0] = arg0->m_posParam[0];
        arg1[1] = arg0->m_posParam[1];
        arg1[2] = arg0->m_posParam[2];
        return;
    }
    GamTrgDogActor *actor = &D_006FE6A0[chrID];
    arg1[0] = actor->pos[0];
    arg1[1] = actor->pos[1];
    arg1[2] = actor->pos[2];
}

extern "C" void func_001DB774(ObjStat *arg0, float *arg1)
{
    int chrID = arg0->m_chrID;
    if (chrID == -1) {
        arg1[0] = arg0->m_rotParam[0];
        arg1[1] = arg0->m_rotParam[1];
        arg1[2] = arg0->m_rotParam[2];
        return;
    }
    GamTrgDogActor *actor = &D_006FE6A0[chrID];
    arg1[0] = actor->rot[0];
    arg1[1] = actor->rot[1];
    arg1[2] = actor->rot[2];
}

extern "C" void func_001DB7CC(ObjStat *arg0, float *arg1)
{
    arg0->m_posParam[0] = arg1[0];
    arg0->m_posParam[1] = arg1[1];
    arg0->m_posParam[2] = arg1[2];
    float *pos = arg0->m_posParam;
    int chrID = arg0->m_chrID;
    if (chrID != -1) {
        GamTrgDogActor *actor = &D_006FE6A0[chrID];
        actor->pos[0] = pos[0];
        actor->pos[1] = pos[1];
        actor->pos[2] = pos[2];
        actor->m_dirty = 1;
    }
    int *secta = arg0->m_secta;
    if ((secta == 0) || (arg0->m_flg & 0x40)) {
        func_001D8D28(arg0, X_func_001D8064(&D_007812C0, pos, secta, (((unsigned int)arg0->m_oid >> 0x17) & 0x1F) == 2));
    }
}

extern "C" void func_001DB898(ObjStat *arg0, float *arg1)
{
    int chrID = arg0->m_chrID;
    arg0->m_rotParam[0] = arg1[0];
    arg0->m_rotParam[1] = arg1[1];
    arg0->m_rotParam[2] = arg1[2];
    if (chrID != -1) {
        X_setActorRot(&D_006E9840, chrID, arg0->m_rotParam);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC6E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FC700);

extern "C" int func_001DB8E8(GamMapObj *arg0, unsigned int arg1, int arg2)
{
    GamTrgMapInfo *info;

    if (X_func_001C6C28(&D_007812C0) != -1) {
        if (arg2 == -1) {
            info = X_func_0017EA44(&D_00298EE0, X_func_001C6C28(&D_007812C0));
        } else {
            info = X_func_0017EA44(&D_00298EE0, arg2);
        }
        if (info != 0) {
            switch (arg1) {
            case 0:
                return info->m_unk08;
            case 2:
                return info->m_unk10;
            case 3:
                return info->m_unk14;
            case 1:
            case 4:
                return info->m_unk0C;
            }
        }
    }
    return D_002D8F60;
}

extern "C" float func_001DB9C4()
{
    float var_f0;
    GamTrgMapInfo *info;

    info = X_func_0017EA44(&D_00298EE0, X_func_001C6C28(&D_007812C0));
    var_f0 = 0.0f;
    if (info != 0) {
        var_f0 = info->m_unk20;
    }
    return var_f0;
}

extern "C" float func_001DBA00()
{
    float var_f0;
    GamTrgMapInfo *info;

    info = X_func_0017EA44(&D_00298EE0, X_func_001C6C28(&D_007812C0));
    var_f0 = 0.0f;
    if (info != 0) {
        var_f0 = info->m_unk28;
    }
    return var_f0;
}

extern "C" void func_001DBA3C(GamMapObj *arg0, unsigned int arg1, float *arg2, int arg3)
{
    GamTrgMapInfo *info;

    switch (arg1) {
    case 0:
        X_func_0017EBAC(&D_00298EE0, arg2, arg3, X_func_001C6C28(&D_007812C0));
        return;
    case 1:
        X_func_0017EB3C(&D_00298EE0, arg2, X_func_001C6C28(&D_007812C0), arg3);
        return;
    case 2:
        info = X_func_0017EA44(&D_00298EE0, X_func_001C6C28(&D_007812C0));
        arg2[0] = info->m_unk20;
        arg2[1] = 0.0f;
        arg2[2] = info->m_unk28;
        return;
    case 3:
    case 4:
        return;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBB38);

// NON_MATCHING: 44/56 differ, 1 reloc differs (size 0xE0, game 0xE8), 30 edits
#ifdef NON_MATCHING
typedef float Vec4_dbb74[4] __attribute__((aligned(16)));
struct MapBounds_dbb74 {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
};
extern MapBounds_dbb74 X_D_002FC748[] asm("D_002FC748");
extern "C" float Xfi_func_001DBA00(GamMapObj *) asm("func_001DBA00");
extern "C" void func_001DBB74(GamMapObj *arg0, int arg1, const Vec4_dbb74 arg2, Vec4_dbb74 arg3)
{
    Vec4_dbb74 v;
    float temp_f20;
    float temp_f0;
    MapBounds_dbb74 *p;

    temp_f20 = func_001DB9C4();
    temp_f0 = Xfi_func_001DBA00(arg0);
    do {
        *(u_long128 *)v = *(const u_long128 *)arg2;
    } while (0);
    p = &X_D_002FC748[arg1];
    v[2] = ((p->unkC * (v[2] + temp_f0)) / p->unk4) + p->unk14;
    v[0] = ((p->unk8 * -(v[0] + temp_f20)) / p->unk0) + p->unk10;
    do {
        *(u_long128 *)arg3 = *(u_long128 *)v;
    } while (0);
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBB74);
#endif

// NON_MATCHING: 31/34 differ, 1 reloc differs (size 0x88, game 0x94), 29 edits
#ifdef NON_MATCHING
union Vec4_dbc5c {
    u_long128 q;
    float f[4];
};
struct MapBounds_dbc5c {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
};
extern MapBounds_dbc5c D_002FC748[];
extern "C" void func_001DBC5C(GamMapObj *arg0, int arg1, const Vec4_dbc5c *arg2, Vec4_dbc5c *arg3)
{
    Vec4_dbc5c v;
    MapBounds_dbc5c *p;

    v.q = arg2->q;
    p = &D_002FC748[arg1];
    v.f[0] = (p->unk8 * -v.f[0]) / p->unk0 + p->unk10;
    v.f[2] = (p->unkC * v.f[2]) / p->unk4 + p->unk14;
    arg3->q = v.q;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBC5C);
#endif

extern "C" void func_001DBCF0(GamMapObj *arg0)
{
    GamTrgMapInfo *info = X_func_0017EA44(&D_00298EE0, X_func_001C6C28(&D_007812C0));
    if (info == 0) {
        arg0->m_unk1D0 = 0;
        return;
    }
    arg0->m_unk1D0 = info->m_unk18;
    arg0->m_unk1C0 = info->m_unk1C;
}

extern "C" void func_001DBD4C(void) {
}

extern "C" int func_001DBD54(GamMapObj *arg0)
{
    if (!D_007812C0.chkSysFlg2(0x40000)) {
        return arg0->m_unk1C0;
    }
    return D_007812C0.m_diffPlace;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBD90);

// NON_MATCHING: 61/66 differ, 5 relocs differ (size 0x108, game 0x100), 43 edits
#ifdef NON_MATCHING
struct Marker_dbdf0 {
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    float vec[4] __attribute__((aligned(16)));
};
extern "C" void Xviiiii_func_001DBB74(GamMapObj *, int, float *, float *) asm("func_001DBB74");
extern "C" void Xvi_func_00144418(float *) asm("func_00144418");
extern "C" void Xvi_func_0014448C(float *) asm("func_0014448C");
extern "C" int func_001DBDF0(GamMapObj *arg0, int arg1, Marker_dbdf0 *arg2)
{
    int ret = 0;
    float v0[4] __attribute__((aligned(16)));
    float v1[4] __attribute__((aligned(16)));

    if (!D_007812C0.chkSysFlg2(0x40000)) {
        int s1 = func_001C6C38(&D_007812C0);
        arg2->unk04 = 1;
        *(u_long128 *)v0 = *(const u_long128 *)D_007812C0.m_pcPos;
        *(u_long128 *)v1 = *(const u_long128 *)D_007812C0.m_pcRot;
        Xviiiii_func_001DBB74(arg0, s1, v0, arg2->vec);
        arg2->unk0C = v1[1];
        arg2++;
        arg2->unk04 = 2;
        Xvi_func_00144418(v0);
        Xvi_func_0014448C(v1);
        Xviiiii_func_001DBB74(arg0, s1, v0, arg2->vec);
        arg2->unk0C = v1[1];
        ret = 2;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DBDF0);
#endif

extern "C" void func_001DBEF0(void) {
}

extern "C" void func_001DBEF8(GamUnqMan *arg0, GamTrgUnqHeader *arg1)
{
    arg0->m_raw = arg1;
    int *off = arg1->m_off;
    char *base = (char *)arg1 + 0x40;
    int off0 = arg1->m_off[0];
    arg0->m_a0 = (GamUnqA0 *)base;
    arg0->m_a1 = (GamUnqA0 *)(base + (off[1] - off0));
    arg0->m_a2 = (GamUnqC0_90 *)(base + (off[2] - off0));
    arg0->m_a3 = (GamUnqE0 *)(base + (off[3] - off0));
    arg0->m_a4 = (GamUnqC0_B0 *)(base + (off[4] - off0));
    arg0->m_a5 = (GamUnq200 *)(base + (off[5] - off0));
    arg0->m_a6 = (GamUnqC0_B0 *)(base + (off[6] - off0));
    arg0->m_a7 = (GamUnqC0_B0 *)(base + (off[7] - off0));
    arg0->m_a8 = (GamUnqC0_B0 *)(base + (off[8] - off0));
    arg0->m_a9 = (GamUnqC0_B0 *)(base + (off[9] - off0));
}

extern const float mapBoundsR7[26] asm("D_002FC748") ALIGNED(8) = {
38400,6400,3072,512,24,514,6400,6400,512,512,128,354,6400,6400,512,512,155,185,0,0,0,0,0,0,0,0};

extern "C" GamUnq200 *func_001DBFA0(GamUnqMan *arg0, unsigned short arg1)
{
    int idx = arg1 & 0x1FF;
    switch (arg1 >> 9) {
    case 0:
        return (GamUnq200 *)&arg0->m_a0[idx];
    case 1:
        return (GamUnq200 *)&arg0->m_a1[idx];
    case 2:
        return (GamUnq200 *)&arg0->m_a2[idx];
    case 3:
        return (GamUnq200 *)&arg0->m_a3[idx];
    case 4:
        return (GamUnq200 *)&arg0->m_a4[idx];
    case 5:
        return (GamUnq200 *)&arg0->m_a5[idx];
    case 6:
        return (GamUnq200 *)&arg0->m_a6[idx];
    case 7:
        return (GamUnq200 *)&arg0->m_a7[idx];
    case 8:
        return (GamUnq200 *)&arg0->m_a8[idx];
    case 9:
        return (GamUnq200 *)&arg0->m_a9[idx];
    default:
        return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DC070);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DC48C);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD0F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD100);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD110);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD190);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD2A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD320);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD3A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", jtbl_002FD480);

extern "C" void func_001DCD38(GamUnqMan *arg0, unsigned short arg1, unsigned int arg2)
{
    int idx = arg1 & 0x1FF;

    switch (arg1 >> 9) {
    case 0: { GamUnqA0 *p = arg0->m_a0; p += idx; p->m_flg |= arg2; return; }
    case 1: { GamUnqA0 *p = arg0->m_a1; p += idx; p->m_flg |= arg2; return; }
    case 2: { GamUnqC0_90 *p = arg0->m_a2; p += idx; p->m_flg |= arg2; return; }
    case 3: { GamUnqE0 *p = arg0->m_a3; p += idx; p->m_flg |= arg2; return; }
    case 4: { GamUnqC0_B0 *p = arg0->m_a4; p += idx; p->m_flg |= arg2; return; }
    case 5: { GamUnq200 *p = arg0->m_a5; p += idx; p->m_flg |= arg2; return; }
    case 6: { GamUnqC0_B0 *p = arg0->m_a6; p += idx; p->m_flg |= arg2; return; }
    case 7: { GamUnqC0_B0 *p = arg0->m_a7; p += idx; p->m_flg |= arg2; return; }
    case 8: { GamUnqC0_B0 *p = arg0->m_a8; p += idx; p->m_flg |= arg2; return; }
    case 9: { GamUnqC0_B0 *p = arg0->m_a9; p += idx; p->m_flg |= arg2; return; }
    }
}

extern "C" void func_001DCE30(GamUnqMan *arg0, unsigned short arg1, unsigned int arg2)
{
    int idx = arg1 & 0x1FF;

    switch (arg1 >> 9) {
    case 0: { GamUnqA0 *p = arg0->m_a0; p += idx; p->m_flg &= ~arg2; return; }
    case 1: { GamUnqA0 *p = arg0->m_a1; p += idx; p->m_flg &= ~arg2; return; }
    case 2: { GamUnqC0_90 *p = arg0->m_a2; p += idx; p->m_flg &= ~arg2; return; }
    case 3: { GamUnqE0 *p = arg0->m_a3; p += idx; p->m_flg &= ~arg2; return; }
    case 4: { GamUnqC0_B0 *p = arg0->m_a4; p += idx; p->m_flg &= ~arg2; return; }
    case 5: { GamUnq200 *p = arg0->m_a5; p += idx; p->m_flg &= ~arg2; return; }
    case 6: { GamUnqC0_B0 *p = arg0->m_a6; p += idx; p->m_flg &= ~arg2; return; }
    case 7: { GamUnqC0_B0 *p = arg0->m_a7; p += idx; p->m_flg &= ~arg2; return; }
    case 8: { GamUnqC0_B0 *p = arg0->m_a8; p += idx; p->m_flg &= ~arg2; return; }
    case 9: { GamUnqC0_B0 *p = arg0->m_a9; p += idx; p->m_flg &= ~arg2; return; }
    }
}

extern "C" unsigned int func_001DCF28(GamUnqMan *arg0, unsigned short arg1)
{
    int idx = arg1 & 0x1FF;

    switch (arg1 >> 9) {
    case 0: { GamUnqA0 *p = arg0->m_a0; p += idx; return p->m_flg; }
    case 1: { GamUnqA0 *p = arg0->m_a1; p += idx; return p->m_flg; }
    case 2: { GamUnqC0_90 *p = arg0->m_a2; p += idx; return p->m_flg; }
    case 3: { GamUnqE0 *p = arg0->m_a3; p += idx; return p->m_flg; }
    case 4: { GamUnqC0_B0 *p = arg0->m_a4; p += idx; return p->m_flg; }
    case 5: { GamUnq200 *p = arg0->m_a5; p += idx; return p->m_flg; }
    case 6: { GamUnqC0_B0 *p = arg0->m_a6; p += idx; return p->m_flg; }
    case 7: { GamUnqC0_B0 *p = arg0->m_a7; p += idx; return p->m_flg; }
    case 8: { GamUnqC0_B0 *p = arg0->m_a8; p += idx; return p->m_flg; }
    case 9: { GamUnqC0_B0 *p = arg0->m_a9; p += idx; return p->m_flg; }
    }
    return 0;
}

extern "C" int func_001DD00C(GamUnqMan *arg0, unsigned short arg1, unsigned int arg2)
{
    int idx = arg1 & 0x1FF;

    switch (arg1 >> 9) {
    case 0: { GamUnqA0 *p = arg0->m_a0; p += idx; return (p->m_flg & arg2) != 0; }
    case 1: { GamUnqA0 *p = arg0->m_a1; p += idx; return (p->m_flg & arg2) != 0; }
    case 2: { GamUnqC0_90 *p = arg0->m_a2; p += idx; return (p->m_flg & arg2) != 0; }
    case 3: { GamUnqE0 *p = arg0->m_a3; p += idx; return (p->m_flg & arg2) != 0; }
    case 4: { GamUnqC0_B0 *p = arg0->m_a4; p += idx; return (p->m_flg & arg2) != 0; }
    case 5: { GamUnq200 *p = arg0->m_a5; p += idx; return (p->m_flg & arg2) != 0; }
    case 6: { GamUnqC0_B0 *p = arg0->m_a6; p += idx; return (p->m_flg & arg2) != 0; }
    case 7: { GamUnqC0_B0 *p = arg0->m_a7; p += idx; return (p->m_flg & arg2) != 0; }
    case 8: { GamUnqC0_B0 *p = arg0->m_a8; p += idx; return (p->m_flg & arg2) != 0; }
    case 9: { GamUnqC0_B0 *p = arg0->m_a9; p += idx; return (p->m_flg & arg2) != 0; }
    }
    return 0;
}

extern "C" void func_001DD118(GamUnqMan *arg0, unsigned short arg1, int arg2, int arg3)
{
    unsigned int hi = arg1 >> 9;
    unsigned int idx = arg1 & 0x1FF;
    if (hi == 2) {
        GamUnqC0_90 *p = arg0->m_a2;
        p += idx;
        p->m_flg94 |= arg3;
    }
}

extern "C" void func_001DD154(GamUnqMan *arg0, unsigned short arg1, int arg2, int arg3)
{
    unsigned int hi = arg1 >> 9;
    unsigned int idx = arg1 & 0x1FF;
    if (hi == 2) {
        GamUnqC0_90 *p = arg0->m_a2;
        p += idx;
        p->m_flg94 &= ~arg3;
    }
}

extern "C" int func_001DD194(GamUnqMan *arg0, unsigned short arg1, int arg2, int arg3)
{
    unsigned int hi;
    unsigned int idx;

    hi = arg1 >> 9;
    idx = arg1 & 0x1FF;
    if (hi == 2) {
        GamUnqC0_90 *p = (GamUnqC0_90 *)((char *)arg0->m_a2 + idx * 0xC0);
        return (p->m_flg94 & arg3) != 0;
    }
    return 0;
}

extern "C" void func_001DD1D8(void) {
}

extern "C" void func_001DD1E0(void) {
}

extern "C" void func_001DD1E8(GamTrgMan *arg0)
{
    arg0->m_list0.init();
    arg0->m_list1.init();
    arg0->m_list2.init();
    arg0->m_unk18B58 = 0;
}

extern "C" void func_001DD3EC(GamTrgMan *arg0, int arg1)
{
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

extern "C" void func_001DD414(GamTrgMan *arg0)
{
    GamDynPool<GamTrgFtb> *p = new GamDynPool<GamTrgFtb>(64);
    arg0->m_ftbPool = p;
    if (p->size() != 0) {
        p->clear();
    }
}

// Keep the allocation source string on the boundary after the ten-entry switch table.
extern const char trgSourceFile[] ALIGNED(16) = "game/gamtrg.cpp";

extern "C" GamTrgCopy64 *func_001DD558(GamTrgMan *arg0, const GamTrgCopy64 *arg1)
{
    GamTrgCopy64 *p = (GamTrgCopy64 *)X_alloc__9BedMemory(&D_006E9800, 0xB0, trgSourceFile, 0x62, 0, 1);
    *p = *arg1;
    return p;
}

extern "C" void func_001DD5E8(GamTrgMan *arg0, GamTrgElem *arg1, int arg2)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;
    if (arg1->m_flg70 != 0) {
        arg1->m_flg |= 0x400000;
    }
    if (arg2 != 0) {
        arg1->m_id = X_func_001C6FE0(&D_007812C0, 0, 0xD);
    }
    it = arg0->m_list0.begin();
    last = arg0->m_list0.end();
    while (it != last) {
        if ((*it).m_id == arg1->m_id) {
            return;
        }
        ++it;
    }
    arg0->m_list0.push_back(*arg1);
    if (arg1->m_flg & 0x01000000) {
        X_func_001DE104(arg0, *arg1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DD7BC);

// NON_MATCHING: 74/117 differ (size 0x1D4, game 0x1D8), 41 edits
#ifdef NON_MATCHING
extern "C" void func_001DDAA8(GamTrgMan *arg0)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;
    it = arg0->m_list0.begin();
    last = arg0->m_list0.end();
    if (arg0->m_list1.size() != 0) {
        arg0->m_list1.clear();
    }
    if (arg0->m_ftbPool->size() != 0) {
        arg0->m_ftbPool->clear();
    }
    while (it != last) {
        it = arg0->m_list0.erase(it);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDAA8);
#endif

// NON_MATCHING: 11/75 differ, 12 edits
#ifdef NON_MATCHING
extern "C" void func_001DDC80(GamTrgMan *arg0)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;
    if (arg0->m_list1.size() != 0) {
        it = arg0->m_list1.begin();
        last = arg0->m_list1.end();
        while (it != last) {
            it = arg0->m_list1.erase(it);
        }
    }
    func_001DDDAC(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DDC80);
#endif

extern "C" void func_001DDDAC(GamTrgMan *arg0)
{
    arg0->m_unk18B5C = 0;
}

extern "C" void func_001DDDBC(GamTrgMan *arg0, int arg1)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;

    if (arg0->m_list1.size() != 0) {
        it = arg0->m_list1.begin();
        last = arg0->m_list1.end();
        while (it != last) {
            switch (arg1) {
            case 0:
            case 1:
            default:
                break;
            case 2:
                if (((unsigned int)(*it).m_id >> 30) == 1) {
                    ++it;
                    continue;
                }
                break;
            case 3:
                if (((unsigned int)(*it).m_id >> 30) != 3) {
                    ++it;
                    continue;
                }
                break;
            }
            it = arg0->m_list1.erase(it);
        }
    }
    func_001DDDAC(arg0);
}

extern "C" int func_001DDF48(GamTrgMan *arg0, float *arg1, unsigned short arg2)
{
    GamDynPool<ObjStat *> list(8);
    X_func_001D35AC(&D_007812C0, arg1, &list, 5, 0x8000, 0x04000001, 50.0f);
    if (list.size() != 0) {
        GamDynPool<ObjStat *>::iterator last = list.end();
        int count = 0;
        GamDynPool<ObjStat *>::iterator it = list.begin();
        while (it != last) {
            unsigned short uid = (*it)->m_uid;
            if (uid != 0xFFFF) {
                if (uid == arg2) {
                    return (*it)->m_oid;
                }
                if (count++ >= 8) {
                    break;
                }
            }
            ++it;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DE104);

extern "C" void func_001DE4E4(GamTrgMan *arg0)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;
    func_001DDC80(arg0);
    if (arg0->m_list0.size() != 0) {
        it = arg0->m_list0.begin();
        last = arg0->m_list0.end();
        while (it != last) {
            if ((*it).m_flg & 0x01000000) {
                X_func_001DE104(arg0, *it);
            }
            ++it;
        }
    }
}

extern "C" void func_001DE5DC(GamTrgMan *arg0, int arg1)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;

    it = arg0->m_list1.begin();
    last = arg0->m_list1.end();
    while (it != last) {
        if ((*it).m_id == arg1) {
            arg0->m_list1.erase(it);
            break;
        }
        ++it;
    }
}

extern "C" void func_001DE6FC(GamTrgMan *arg0, int arg1, unsigned int arg2)
{
    GamList<GamTrgFtb>::iterator it;
    GamList<GamTrgFtb>::iterator last;
    GamTrgFtb elem;

    if (arg2 & 0x80000000) {
        arg2 |= 0x80000000;
    }
    it = arg0->m_ftbPool->begin();
    last = arg0->m_ftbPool->end();
    while (it != last) {
        if ((*it).m_data.m_key == arg1) {
            int i = 1;
            do {
                if ((*it).m_data.m_vals[i] == (int)arg2) {
                    return;
                }
                if ((*it).m_data.m_vals[i] == 0) {
                    (*it).m_data.m_vals[i] = (int)arg2;
                    return;
                }
            } while (i++ < 8);
        }
        ++it;
    }
    X_memset(&elem.m_data, 0, sizeof(elem.m_data));
    elem.m_data.m_key = arg1;
    elem.m_data.m_vals[0] = (int)arg2;
    arg0->m_ftbPool->push_back(elem);
}

extern "C" bool func_001DE8AC(GamTrgMan *arg0, const float *arg1, const GamTrgVec2 *const *arg2)
{
    int count = 0;
    while (arg2[1] != 0) {
        const GamTrgVec2 *p0 = arg2[0];
        const GamTrgVec2 *p1 = arg2[1];
        GamTrgVec2 v0, v1, v2;
        if (p0->y == p1->y && p0->y == arg1[2]) {
            if (p0->x < p1->x && p0->x < arg1[0]) {
                count++;
            } else if (p1->x < p0->x && p1->x < arg1[0]) {
                count++;
            }
        } else if (p0->y < p1->y && p0->y <= arg1[2] && arg1[2] < p1->y) {
            v0.x = p1->x - p0->x;
            v0.y = p1->y - p0->y;
            v1.x = arg1[0] - p0->x;
            v1.y = arg1[2] - p0->y;
            if ((v0.x * v1.y - v0.y * v1.x) > 0.0f) {
                count++;
            }
        } else if (p1->y < p0->y && p1->y < arg1[2] && arg1[2] <= p0->y) {
            v0.x = p0->x - p1->x;
            v0.y = p0->y - p1->y;
            v2.x = arg1[0] - p1->x;
            v2.y = arg1[2] - p1->y;
            if ((v0.x * v2.y - v0.y * v2.x) > 0.0f) {
                count++;
            }
        }
        arg2++;
    }
    if (count & 1) {
        return true;
    }
    return false;
}

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEA40);

extern "C" void func_001DEAAC(GamTrgMan *arg0)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;
    float pos[4];
    int oid = D_007812C0.m_pc ? D_007812C0.m_pc->m_oid : 0;

    X_func_001D05F4(&D_007812C0, oid, pos);
    if (arg0->m_list1.size() != 0) {
        it = arg0->m_list1.begin();
        last = arg0->m_list1.end();
        while (it != last) {
            if (((*it).m_flg & 0x04000001) == 0x04000001 &&
                (*it).m_minX <= pos[0] && pos[0] <= (*it).m_maxX &&
                (*it).m_minZ <= pos[2] && pos[2] <= (*it).m_maxZ &&
                (*it).m_unk30 != 0 && (*it).m_unk34 != 0) {
                X_func_002113DC(&D_007A4440, (*it).m_unk30, (*it).m_unk34, (*it).m_unk44, 2, 0, (*it).m_id, D_002FD640);
                return;
            }
            ++it;
        }
    }
}

extern "C" void func_001DEC14(GamTrgMan *arg0)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;
    float pos[4];
    int oid = D_007812C0.m_pc ? D_007812C0.m_pc->m_oid : 0;
    X_func_001D05F4(&D_007812C0, oid, pos);
    if (arg0->m_list1.size() != 0) {
        it = arg0->m_list1.begin();
        last = arg0->m_list1.end();
        while (it != last) {
            if (((*it).m_flg & 1) && ((*it).m_flg70 & 2) &&
                (*it).m_minX <= pos[0] && pos[0] <= (*it).m_maxX &&
                (*it).m_minZ <= pos[2] && pos[2] <= (*it).m_maxZ &&
                (*it).m_unk30 != 0 && (*it).m_unk34 != 0) {
                X_func_001E0C2C(arg0, 2, (*it).m_id, 0x10000000);
                return;
            }
            ++it;
        }
    }
}

// NON_MATCHING: 42/68 differ (size 0x110, game 0x108), 23 edits
#ifdef NON_MATCHING
struct BedPad_ded70 {
    unsigned char pad0[0x78];
    unsigned short m_press;
    unsigned short m_trigger;
};
extern "C" int Xii_func_00118FEC__9MagSystem(void *) asm("func_00118FEC__9MagSystem");
extern "C" int func_001DED70(GamTrgMan *arg0, int arg1, int *arg2)
{
    if (!D_007812C0.chkSysFlg(4)) {
        return 0;
    }
    char *ms = (char *)&D_006E9840;
    if ((unsigned int)(Xii_func_00118FEC__9MagSystem(ms) - 5) >= 3U) {
        return 0;
    }
    if (X_func_001E7D7C(&D_007A3D80, D_007812C0.m_itemUseTaskID) != 0) {
        return 0;
    }
    BedPad_ded70 *pad = *(BedPad_ded70 **)(ms + 0x97A40);
    if ((pad->m_trigger ^ 0x4000) != 0) {
        return 0;
    }
    if (pad->m_press >> 15) {
        return 0;
    }
    if ((pad->m_press >> 12) & 1) {
        return 0;
    }
    if ((pad->m_press >> 13) & 1) {
        return 0;
    }
    if ((pad->m_press >> 3) & 1) {
        return 0;
    }
    *arg2 |= 0x10;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DED70);
#endif

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD640);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD668);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD670);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD678);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD680);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD688);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD690);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD698);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6D0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6F0);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD6F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD700);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD708);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD710);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD718);

INCLUDE_RODATA("asm/nonmatchings/game/gamtrg", D_002FD720);

INCLUDE_ASM("asm/nonmatchings/game/gamtrg", func_001DEE78);
