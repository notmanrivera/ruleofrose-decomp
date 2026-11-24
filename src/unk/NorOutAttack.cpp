#include "include_asm.h"
#include "unk/NorMain.h"
extern "C" int func_001513EC(EmyMain *);
extern "C" void func_00166C8C(EmyOut *, float *);
extern "C" void func_001D89C4(void *, float *);
extern const int D_002EFA60[];
extern int *D_00298DD8[];

struct NorActorPtr {
    unsigned char m_pad00[0x100];
    unsigned int m_objStat100;          // +0x100
};

struct NorGlobalB {
    unsigned char m_pad00[0x64C];
    int m_unk64C;                       // +0x64C
    int m_unk650;                       // +0x650
};

struct NorOutAttack : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    int m_unk44;                        // +0x44
    int m_unk48;                        // +0x48
    int m_unk4C;                        // +0x4C
    int m_unk50;                        // +0x50
    int m_unk54;                        // +0x54
    int m_unk58;                        // +0x58
    int m_unk5C;                        // +0x5C
    int m_unk60;                        // +0x60
    int m_unk64;                        // +0x64
    float m_unk68[3];                   // +0x68..+0x73
    float m_unk74;                      // +0x74
    int m_unk78;                        // +0x78
};
STATIC_ASSERT(sizeof(NorOutAttack) == 0x7C, NorOutAttack_size);

struct NorOutBitten : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    int m_unk44;                        // +0x44
};
STATIC_ASSERT(sizeof(NorOutBitten) == 0x48, NorOutBitten_size);

struct NorOutWalk : EmyOut {
    short m_unk38;                      // +0x38
    short m_unk3A;                      // +0x3A
    int m_unk3C;                        // +0x3C
    unsigned int m_unk40;               // +0x40
    int m_unk44;                        // +0x44
    int m_unk48;                        // +0x48
};
STATIC_ASSERT(sizeof(NorOutWalk) == 0x4C, NorOutWalk_size);

struct NorOutDead : EmyOut {
};

struct NorOutBrownEv : EmyOut {
};

struct NorOutCounter : EmyOut {
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
};
STATIC_ASSERT(sizeof(NorOutCounter) == 0x44, NorOutCounter_size);

struct NorOutCoax : EmyOut {
};

struct NorOutTest : EmyOut {
};

extern int D_006E9840;
extern int D_006FBD80;
extern int D_007812C0;
extern NorActorPtr *D_007A3350;
extern NorActorPtr *D_007A3354;
extern NorGlobalB *D_007B205C;

extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" int X_func_00104394(int, int, int) asm("func_00104394");
extern "C" float X_func_001044B8(float, float) asm("func_001044B8");
extern "C" float X_func_0010A650(int) asm("func_0010A650__8DogActor");
extern "C" int X_func_00118FEC(void *) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_00119090(void *) asm("func_00119090__9MagSystem");
extern "C" int X_func_0013166C(int, int, int) asm("func_0013166C");
extern "C" int X_func_001442DC(int) asm("func_001442DC");
extern "C" int X_func_00144308(int) asm("func_00144308");
extern "C" int X_func_00151448(EmyMain *) asm("func_00151448");
extern "C" void func_001517E0(NorOutAttack *);
extern "C" void func_0015195C(NorOutAttack *);
extern "C" int func_001519B8(NorOutAttack *);
extern "C" int X_func_00151F1C(NorOutAttack *) asm("func_00151F1C");
extern "C" int func_001520CC(NorOutAttack *);
extern "C" void func_0015246C(NorOutAttack *);
extern "C" int X_func_00152544(NorOutAttack *) asm("func_00152544");
extern "C" void func_00152B24(NorOutAttack *);
extern "C" void func_00152BB4(NorOutAttack *);
extern "C" void func_00152C60(NorOutAttack *);
extern "C" void func_00152CFC(NorOutAttack *);
extern "C" void func_00152DA4(NorOutAttack *);
extern "C" void func_00152E40(NorOutAttack *);
extern "C" void func_00152E90(NorOutAttack *);
extern "C" void func_00152F3C(NorOutAttack *);
extern "C" int func_001536CC(void);
extern "C" void func_0016649C(EmyMain *, int);
extern "C" int X_func_00166AD0(...) asm("func_00166AD0");
extern "C" int X_func_00166B74(EmyOut *, float *) asm("func_00166B74");
extern "C" int X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" int X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" int X_func_001670DC(EmyOut *, float *, float) asm("func_001670DC");
extern "C" int X_func_00167230(EmyOut *, int, float) asm("func_00167230");
extern "C" int X_func_00167D88(EmyOut *, void *, float) asm("func_00167D88");
extern "C" float X_func_00167E38(EmyOut *) asm("func_00167E38");
extern "C" int X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" int X_func_001682B0(EmyOut *) asm("func_001682B0");
extern "C" int X_func_001693EC(EmyOut *, int, int, int) asm("func_001693EC");
extern "C" int X_func_0016947C(EmyOut *) asm("func_0016947C");
extern "C" int X_func_001694CC(EmyOut *, int) asm("func_001694CC");
extern "C" int X_func_0016976C(void *, void *) asm("func_0016976C");
extern "C" int X_func_00169BAC(int, int, int, float, float) asm("func_00169BAC");
extern "C" int X_func_00169F94(unsigned int, int, unsigned int, float) asm("func_00169F94");
extern "C" int X_func_0016A1DC(unsigned int, int, unsigned int, float) asm("func_0016A1DC");
extern "C" int X_func_0017C340(void *, void *, void *, int, float, float) asm("func_0017C340");
extern "C" int X_func_001CBE38(void *, unsigned int) asm("func_001CBE38");
extern "C" int X_func_001D10D0(void *, unsigned int, int) asm("func_001D10D0");
extern "C" int X_func_001D1410(void *, unsigned int, int) asm("func_001D1410");
extern "C" int X_func_001D19A8(void *, unsigned int) asm("func_001D19A8");
extern "C" float X_func_001D7DE4(void *, void *) asm("func_001D7DE4");
extern "C" int X_func_001FAC60(unsigned int, int, int, int, int, unsigned int, int) asm("func_001FAC60");
extern "C" int X_func_00202F10(void *) asm("func_00202F10");

static inline void NorInc(int *p) { (*p)++; }

static inline unsigned int NorInRange(int n, int lo, int hi)
{
    if (n < lo) return 0;
    if (n > hi) return 0;
    return 1;
}

static inline int NorAnimDone(void *world, EmyOut *obj)
{
    int r = X_func_001D19A8(world, (unsigned int)obj->m_unk00);
    if (r) {
        obj->m_owner->m_unk2C = 1;
    }
    return r;
}

static inline void NorHitSlash(NorOutAttack *self, unsigned int target)
{
    if (X_func_0016A1DC((unsigned int)self->m_unk00, 4, target, 55.0f) != 0) {
        self->m_unk60 = 1;
        X_func_001694CC(self, 0x51);
        X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x23, target, 0);
    }
}

static inline void NorHitBite(NorOutAttack *self, unsigned int target)
{
    if (X_func_0016A1DC((unsigned int)self->m_unk00, 2, target, 20.0f) != 0) {
        NorMain *owner = (NorMain *)self->m_owner;
        NorInc(&owner->m_unk23C);
        X_func_001694CC(self, 0x50);
        self->m_unk60 = 1;
        X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x21, target, 0);
    }
}

extern "C" int func_001515C4(NorMain *self)
{
    if (++self->m_unk254 == D_002EFA60[self->m_unk250]) {
        int r = X_func_0010423C(0, 0x63);
        if (r < 0x1E) {
            self->m_unk250 = 0;
        } else if (r < 0x3C) {
            self->m_unk250 = 1;
        } else if (r < 0x5A) {
            self->m_unk250 = 2;
        } else {
            self->m_unk250 = 3;
        }
        self->m_unk254 = 0;
    }
    return D_00298DD8[self->m_unk250][self->m_unk254];
}

extern "C" void NorOutAttack__vfunc_02(NorOutAttack *self)
{
    X_func_00166DA4(self, 0x64);
    self->m_owner->m_unk150 = 0;
    func_001517E0(self);
}

extern "C" int NorOutAttack__vfunc_03(NorOutAttack *self)
{
    int mode;
    int ret;
    int res;

    mode = self->m_unk40;
    ret = -1;
    switch (mode) {
        case 0:
            res = func_001520CC(self);
block_11:
            ret = res;
            break;
        case 1:
            res = X_func_00152544(self);
            goto block_11;
        case 2:
            res = func_001519B8(self);
            goto block_11;
        case 3:
            res = X_func_00151F1C(self);
            goto block_11;
    }
    return ret;
}

extern "C" void NorOutAttack__vfunc_04(NorOutAttack *self)
{
    X_func_00166AD0();
    D_007B205C->m_unk650 = 0;
    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
    func_0016649C(self->m_owner, 1);
    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
}

extern "C" void func_001517E0(NorOutAttack *self)
{
    float dist;
    self->m_unk3C = 0;
    self->m_unk48 = 0;
    self->m_unk54 = 0;
    if (((NorMain *)self->m_owner)->m_unk218 == 0) {
        int mode = func_001515C4((NorMain *)self->m_owner);
        self->m_unk40 = mode;
        switch (mode) {
        case 0: {
            dist = 88.5f;
            int tmp = X_func_00104394(0xA, 0x96, 3);
            self->m_unk04 = 0;
            self->m_unk38 = tmp;
            break;
        }
        case 1:
            self->m_unk04 = 0;
            dist = 155.999985f;
            break;
        case 2:
            self->m_unk60 = 0;
            self->m_unk64 = 0;
            self->m_unk48 = 0;
            dist = 386.0f;
            self->m_unk04 = 0;
            break;
        case 3:
            self->m_unk78 = 0;
            X_func_00167230(self, 0, 0.39269906282424927f);
            self->m_unk04 = 0;
            return func_0016649C(self->m_owner, 0);
        }
    } else {
        int r = X_func_0010423C(0, 0x63);
        if (((NorMain *)self->m_owner)->m_unk230 == 0) {
            r = 0;
        }
        if (r < 0x32) {
            self->m_unk40 = 0;
            int tmp = X_func_00104394(0xA, 0x96, 3);
            self->m_unk04 = 0;
            dist = 88.5f;
            self->m_unk38 = tmp;
        } else {
            self->m_unk04 = 0;
            self->m_unk40 = 1;
            dist = 155.999985f;
        }
    }
    X_func_00166F50(self, self->m_unk14, dist);
}

extern "C" void func_0015195C(NorOutAttack *self)
{
    int rnd;

    self->m_unk3C = 0;
    self->m_unk48 = 0;
    self->m_unk54 = 0;
    self->m_unk40 = 0;
    rnd = X_func_00104394(0xA, 0x96, 3);
    self->m_unk04 = 0;
    self->m_unk38 = rnd;
    X_func_00166F50(self, self->m_unk14, 88.5f);
}

extern "C" int func_001519B8(NorOutAttack *self)
{
    float inRange1;
    float inRange2;
    int arrived;
    int state;
    int frame;
    int ret;
    register unsigned int targetPc PS2_REG("$6");
    unsigned int targetDog;

    state = self->m_unk04;
    ret = -1;
    switch (state) {
        case 0:
            if (self->m_unk24 != 0) {
                X_func_00202F10(self->m_owner->m_unk1F0);
                arrived = self->m_unk24;
                if (arrived == 1) {
                    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x20000000);
                    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
                    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
                    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
                    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
                    X_func_001694CC(self, 0x54);
                    X_func_001694CC(self, 0x62);
                    X_func_001680A0(self, 0x2B, 0);
                    self->m_unk04 = arrived;
                } else {
                    return 9;
                }
            }
            break;
        case 1:
            frame = self->m_unk48 + 1;
            self->m_unk48 = frame;
            inRange1 = (float)NorInRange(frame, 15, 55);
            if (inRange1 != 0.0f) {
                func_0016649C(self->m_owner, 0);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            } else {
                func_0016649C(self->m_owner, 1);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            }
            inRange2 = (float)NorInRange(self->m_unk48, 20, 50);
            if (inRange2 != 0.0f) {
                if ((self->m_unk60 == 0) && (X_func_00118FEC(&D_006E9840) != 9)) {
                    targetPc = 0;
                    if (D_007A3350 != 0) {
                        targetPc = D_007A3350->m_objStat100;
                    }
                    NorHitSlash(self, targetPc);
                }
                if (self->m_unk64 == 0) {
                    if ((X_func_00119090(&D_006E9840) != 0xA) && (X_func_00119090(&D_006E9840) != 0xD)) {
                        targetDog = 0;
                        if (D_007A3354 != 0) {
                            targetDog = D_007A3354->m_objStat100;
                        }
                        if (X_func_0016A1DC((unsigned int)self->m_unk00, 4, targetDog, 55.0f) != 0) {
                            self->m_unk64 = 1;
                            X_func_001694CC(self, 0x51);
                            X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x23, targetDog, 0);
                        }
                    }
                }
            }
            if (NorAnimDone(&D_007812C0, self)) {
                ret = 8;
                func_0016649C(self->m_owner, 1);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
            }
            break;
        default:
            break;
    }
    return ret;
}

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA50);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA60);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA70);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFA98);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFAB8);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFAD8);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00151D4C);

INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00151F1C);

extern "C" int func_001520CC(NorOutAttack *self)
{
    float inRange;
    int arrived;
    unsigned int frame1;
    unsigned int frame3;
    register unsigned int targetPc PS2_REG("$6");
    unsigned int targetDog;
    EmyMain *owner1;
    EmyMain *owner3;
    NorMain *norOwner;

    switch (self->m_unk04) {
        case 0:
            arrived = self->m_unk24;
            if (arrived == 2) {
                X_func_00202F10(self->m_owner->m_unk1F0);
                return 9;
            }
            if ((arrived == 1) || ((unsigned int)self->m_unk3C >= (unsigned int)self->m_unk38)) {
                X_func_00202F10(self->m_owner->m_unk1F0);
                X_func_001694CC(self, 0x53);
                X_func_001694CC(self, 0x63);
                self->m_unk64 = 0;
                self->m_unk60 = 0;
                X_func_001680A0(self, 0x1C, 0);
                self->m_unk48 = 0;
                self->m_unk04 = 1;
            }
            break;
        case 1:
            owner1 = self->m_owner;
            frame1 = (unsigned int)self->m_unk48 + 1;
            self->m_unk48 = (int)frame1;
            if (frame1 >= 0xFU) {
                func_0016649C(owner1, 0);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            } else {
                func_0016649C(owner1, 1);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            }
            inRange = (float)NorInRange(self->m_unk48, 19, 25);
            if (inRange != 0.0f) {
                if ((self->m_unk60 == 0) && (X_func_00118FEC(&D_006E9840) != 9)) {
                    targetPc = 0;
                    if (D_007A3350 != 0) {
                        targetPc = D_007A3350->m_objStat100;
                    }
                    NorHitBite(self, targetPc);
                }
                norOwner = (NorMain *)self->m_owner;
                if (((norOwner->m_unk218 == 0) || (norOwner->m_unk230 != 0)) && (self->m_unk64 == 0) && (X_func_00119090(&D_006E9840) != 0xA) && (X_func_00119090(&D_006E9840) != 0xD)) {
                    targetDog = 0;
                    if (D_007A3354 != 0) {
                        targetDog = D_007A3354->m_objStat100;
                    }
                    if (X_func_0016A1DC((unsigned int)self->m_unk00, 2, targetDog, 20.0f) != 0) {
                        X_func_001694CC(self, 0x50);
                        self->m_unk64 = 1;
                        X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x21, targetDog, 0);
                    }
                }
            }
            if (self->m_unk48 == 0x19) {
                self->m_unk04 = 3;
            }
            break;
        case 3:
            owner3 = self->m_owner;
            frame3 = (unsigned int)self->m_unk48 + 1;
            self->m_unk48 = (int)frame3;
            if (frame3 < 0x1EU) {
                func_0016649C(owner3, 0);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            } else {
                func_0016649C(owner3, 1);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            }
            if (NorAnimDone(&D_007812C0, self)) {
                func_0016649C(self->m_owner, 1);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
                self->m_unk48 = 0;
                func_001517E0(self);
            }
            break;
    }
    return -1;
}

extern "C" void func_0015246C(NorOutAttack *self)
{
    int off = 0x12540;
    X_func_0016947C(self);
    self->m_owner->m_unk150 = 0;
    if (self->m_unk50 == 0) {
        X_func_0013166C((int)&D_006E9840 + off, 6, 0);
    } else {
        X_func_0013166C((int)&D_006E9840 + off, 9, 0);
    }
    X_func_001694CC(self, 0x5B);
    if (((NorMain *)self->m_owner)->m_unk218 == 0) {
        X_func_001694CC(self, 0x65);
    } else {
        X_func_001694CC(self, 0x64);
    }
    X_func_001680A0(self, 0x23, 0);
    self->m_unk04 = 6;
    func_0016649C(self->m_owner, 1);
}

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB28);

// NON_MATCHING: 81/126 differ, 18 relocs differ (size 0x1F8, game 0x204), 11 edits
#ifdef NON_MATCHING
extern "C" void func_00152748(NorOutAttack *);
extern "C" int func_00152544(NorOutAttack *self)
{
    struct {
        char pad0[16];
        int sp10;
        int sp14;
        char pad18[8];
    } stack;
    register int minusOne PS2_REG("$16") = -1;
    unsigned int arrived;
    unsigned int st;

    st = (unsigned int)self->m_unk04;
    if (st == 3 || st == 8) {
        if (X_func_001442DC(self->m_unk00) != minusOne) {
            X_func_00144308(1);
            func_0015246C(self);
            return -1;
        }
    }
    switch ((unsigned int)self->m_unk04) {
        case 0:
            if (self->m_unk24 != 0) {
                X_func_00202F10(self->m_owner->m_unk1F0);
                arrived = (unsigned int)self->m_unk24;
                if (arrived != 1) {
                    return 9;
                }
                X_func_00167D88(self, &stack, 63.0f);
                X_func_0017C340((char *)&D_006FBD80 + 0x8542C, &stack, &stack.sp10, 0, 40.0f, 0.0f);
                if (stack.sp14 == 0) {
                    func_0015195C(self);
                } else {
                    X_func_001694CC(self, 0x54);
                    X_func_001694CC(self, 0x61);
                    X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
                    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
                    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
                    X_func_001680A0(self, 0x21, 0);
                    self->m_unk48 = 0;
                    self->m_unk04 = (int)arrived;
                }
            }
            return -1;
        case 1:
            func_00152748(self);
            return -1;
        case 2:
            func_00152B24(self);
            return -1;
        case 3:
            func_00152BB4(self);
            return -1;
        case 8:
            func_00152E90(self);
            return -1;
        case 4:
            func_00152C60(self);
            return -1;
        case 5:
            func_00152CFC(self);
            return -1;
        case 6:
            func_00152DA4(self);
            return -1;
        case 7:
            func_00152E40(self);
            return -1;
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152544);
#endif

// NON_MATCHING: 205/249 differ, 39 relocs differ (size 0x3E4, game 0x3DC), 51 edits
#ifdef NON_MATCHING
extern "C" void func_00152748(NorOutAttack *incoming)
{
    register NorOutAttack *self PS2_REG("$16") = incoming;
    register EmyMain *owner PS2_REG("$5") = self->m_owner;
    unsigned int frame = (unsigned int)self->m_unk48 + 1;
    self->m_unk48 = (int)frame;
    if (frame >= 11U) {
        func_0016649C(owner, 0);
        X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
    } else {
        func_0016649C(owner, 1);
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
    }
    if (!NorAnimDone(&D_007812C0, self)) {
        float active = (float)NorInRange(self->m_unk48, 21, 25);
        if (active != 0.0f && X_func_00169BAC(1, self->m_unk14, self->m_unk08, 80.0f, 0.7853981633974483f)) {
            int motion = (int)&D_006E9840 + 0x12540;
            unsigned int worldFlags = *(unsigned int *)((char *)&D_007812C0 + 0x21F48);
            if (!(bool)X_func_0013166C(motion, 22, 0) && !(worldFlags & 0x2000) && (worldFlags & 4)) {
                int anim;
                func_0016649C(self->m_owner, 0);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
                self->m_unk74 = X_func_0010A650(X_func_001CBE38(&D_007812C0, (unsigned int)self->m_unk00) * 0x4D0 + motion + 0x2920);
                X_func_001CBE38(&D_007812C0, (unsigned int)self->m_unk14);
                int side = (double)X_func_00167E38(self) >= 1.57079632679489661923;
                self->m_unk50 = side;
                ((NorMain *)self->m_owner)->m_unk24C = side;
                if (self->m_unk50 == 0) {
                    self->m_owner->m_unk150 = 3;
                    X_func_0013166C(motion, 2, 0);
                    X_func_00167D88(self, self->m_unk68, 60.0f);
                    anim = 0x28;
                    float yaw = (float)((double)self->m_unk74 - 3.14159265358979323846);
                    if ((double)yaw < -3.14159265358979323846) yaw = (float)((double)yaw + 6.28318530717958647692);
                    if ((double)yaw > 3.14159265358979323846) yaw = (float)((double)yaw - 6.28318530717958647692);
                    self->m_unk74 = yaw;
                } else {
                    self->m_owner->m_unk150 = 4;
                    X_func_0013166C(motion, 7, 0);
                    X_func_00167D88(self, self->m_unk68, 60.0f);
                    anim = 0x29;
                }
                X_func_001680A0(self, anim, 0);
                self->m_unk54 = 0;
                self->m_unk48 = 0;
                self->m_unk04 = 2;
            }
        }
    } else {
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
        X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
        func_0016649C(self->m_owner, 1);
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
        func_001517E0(self);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", func_00152748);
#endif

extern "C" void func_00152B24(NorOutAttack *self)
{
    if (!NorAnimDone(&D_007812C0, self)) {
        return func_00152F3C(self);
    }
    X_func_001680A0(self, (self->m_unk50 == 0) ? 0x24 : 0x25, 0x100);
    self->m_unk04 = 3;
    self->m_unk58 = X_func_0010423C(5, 0x12);
}

extern "C" void func_00152BB4(NorOutAttack *self)
{
    func_00152F3C(self);
    X_func_001693EC(self, 0xC, 0x1E, 0x58);
    if (--self->m_unk58 <= 0) {
        self->m_unk5C = X_func_0010423C(1, 3);
        X_func_001680A0(self, 0x1D, 0);
        self->m_unk04 = 4;
    } else if (X_func_00118FEC(&D_006E9840) == 3) {
        X_func_001680A0(self, (self->m_unk50 == 0) ? 0x26 : 0x27, 0x100);
        self->m_unk04 = 8;
    }
}

extern "C" void func_00152C60(NorOutAttack *self)
{
    X_func_001693EC(self, 0xC, 0x1E, 0x58);
    if (++self->m_unk48 == 3) {
        NorInc(&((NorMain *)self->m_owner)->m_unk23C);
        X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x22, (unsigned int)self->m_unk14, 0);
        self->m_unk48 = 0;
        if (--self->m_unk5C == 0) {
            self->m_unk04 = 2;
        } else {
            self->m_unk04 = 5;
        }
    }
}

extern "C" void func_00152CFC(NorOutAttack *self)
{
    X_func_001693EC(self, 0xC, 0x1E, 0x58);
    if (NorAnimDone(&D_007812C0, self)) {
        if (X_func_00118FEC(&D_006E9840) == 3) {
            X_func_001680A0(self, (self->m_unk50 == 0) ? 0x26 : 0x27, 0x100);
            self->m_unk04 = 8;
        } else {
            X_func_001680A0(self, 0x1D, 0);
            self->m_unk04 = 4;
        }
    }
}

extern "C" void func_00152DA4(NorOutAttack *self)
{
    if (NorAnimDone(&D_007812C0, self)) {
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x04000000);
        X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x40);
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x10000000);
        X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
        func_001517E0(self);
    }
}

extern "C" void func_00152E40(NorOutAttack *self)
{
    if (NorAnimDone(&D_007812C0, self)) {
        func_001517E0(self);
    }
}

extern "C" void func_00152E90(NorOutAttack *self)
{
    X_func_001693EC(self, 0xC, 0x1E, 0x58);
    if (X_func_00118FEC(&D_006E9840) == 3) {
        if (++self->m_unk54 >= 0x51) {
            return func_0015246C(self);
        }
    } else {
        X_func_001680A0(self, (self->m_unk50 == 0) ? 0x24 : 0x25, 0x100);
        self->m_unk04 = 3;
        self->m_unk58 = X_func_0010423C(5, 0x12);
    }
}

extern "C" void func_00152F34(void)
{
}

extern "C" void func_00152F3C(NorOutAttack *self)
{
    struct {
        float vec[4];
        int sp10;
        int sp14;
    } stack;
    int base;
    int s1;

    X_func_00166B74(self, stack.vec);
    stack.vec[3] = self->m_unk74;
    base = (int)&D_006E9840;
    s1 = base + 0x12540;
    if (X_func_0013166C(s1, 0x15, (int)stack.vec) == 0) {
        X_func_00167D88(self, stack.vec, -30.0f);
        if (X_func_0013166C(s1, 0x15, (int)stack.vec) == 0) {
            func_00166C8C(self, stack.vec);
            X_func_0017C340((void *)(base + 0x9796C), stack.vec, &stack.sp10, 0, 40.0f, 0.0f);
            if (stack.sp14 != 0) {
                func_001D89C4((void *)self->m_unk08, stack.vec);
            }
        } else {
            func_001D89C4((void *)self->m_unk08, stack.vec);
        }
    }
}

extern "C" void NorOutBitten__vfunc_02(NorOutBitten *self)
{
    self->m_unk04 = 0;
    X_func_001680A0(self, 0x17, 0x100);
    self->m_unk44 = 0;
    self->m_unk40 = 0;
}

// NON_MATCHING: 93/178 differ, 13 relocs differ (size 0x2C8, game 0x2D8), 23 edits
#ifdef NON_MATCHING
extern "C" int NorOutBitten__vfunc_03(NorOutBitten *self)
{
    float inRange;
    int frame;
    int ret = -1;
    unsigned int targetPc;

    if (X_func_001442DC(self->m_unk00) == -1 && self->m_unk04 == 0) {
        X_func_00144308(1);
        return 8;
    }
    switch (self->m_unk04) {
        case 0:
            X_func_001693EC(self, 0xA, 0x19, 0x52);
            if (X_func_00151448(self->m_owner) == 0) {
                X_func_0016947C(self);
                func_0016649C(self->m_owner, 0);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
                X_func_001680A0(self, 0x18, 0);
                self->m_unk3C = 0;
                self->m_unk38 = 0;
                X_func_001694CC(self, 0x56);
                X_func_001694CC(self, 0x63);
                func_0016649C(self->m_owner, 0);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
                self->m_unk04 = 1;
            }
            return ret;
        case 1:
            frame = self->m_unk3C + 1;
            self->m_unk3C = frame;
            if (frame < 0x30) {
                func_0016649C(self->m_owner, 0);
                X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            } else {
                func_0016649C(self->m_owner, 1);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            }
            inRange = (float)NorInRange(self->m_unk3C, 0x1D, 0x2B);
            if ((inRange != 0.0f) && (self->m_unk40 == 0) && (X_func_00118FEC(&D_006E9840) != 9)) {
                targetPc = (D_007A3350 != 0) ? D_007A3350->m_objStat100 : 0;
                if (X_func_00169F94((unsigned int)self->m_unk00, 3, targetPc, 40.0f) != 0) {
                    self->m_unk40 = 1;
                    X_func_001694CC(self, 0x51);
                    X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x24, targetPc, 0);
                }
            }
            if (++self->m_unk38 == 0x17) {
                X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x25, D_007A3354->m_objStat100, 0);
                X_func_00144308(0);
            }
            if (NorAnimDone(&D_007812C0, self)) {
                ret = 8;
                func_0016649C(self->m_owner, 1);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            }
            return ret;
        default:
            return ret;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutBitten__vfunc_03);
#endif

extern "C" void NorOutBitten__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void NorOutWalk__vfunc_02(NorOutWalk *self)
{
    int timer;

    self->m_unk3A = func_001536CC();
    timer = X_func_0010423C(0x3E8, 0x7D0);
    self->m_unk04 = 0;
    self->m_unk44 = timer;
}

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB68);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB70);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB78);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB80);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB88);

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFB90);

extern "C" int NorOutWalk__vfunc_03(NorOutWalk *self)
{
    struct {
        int flags[3];
        int pad;
        float target[4];
        float origin[4];
    } stack;
    float *dst;
    float *src;
    float val;
    int rnd;
    int timer;
    int animDone;
    int waitTimer;
    int count;
    register int tries PS2_REG("$18");
    unsigned int state;
    unsigned int stepCount;

    state = (unsigned int)self->m_unk04;
    self->m_unk44 = self->m_unk44 - 1;
    switch (state) {
        case 2:
        case 5:
        case 6:
        case 7:
        case 8:
            break;
walk_success:
            X_func_001670DC(self, &stack.target[0], 0.0f);
            self->m_unk04 = 1;
            goto walk_after;

        case 0:
            stack.flags[2] = 0;
            tries = 0;
            stack.flags[1] = 0;
            stack.flags[0] = 0;
            X_func_00166B74(self, &stack.origin[0]);
            rnd = X_func_0010423C(0, 0x59);
            do {
                dst = &stack.target[0];
                count = 3;
                src = &stack.origin[0];
                do {
                    val = *src;
                    src++;
                    count -= 1;
                    *dst = val;
                    dst++;
                } while (count != -1);
                if (stack.flags[0] == 0) {
                    if (rnd >= 0x1E) {
                        goto block_11;
                    }
                    stack.target[0] += X_func_001044B8(-120.0f, -80.0f);
                    stack.target[2] += X_func_001044B8(80.0f, 120.0f);
                    stack.flags[0] = 1;
                } else {
block_11:
                    if ((stack.flags[1] == 0) && (rnd < 0x3C)) {
                        stack.target[0] += X_func_001044B8(-20.0f, 20.0f);
                        stack.target[2] += X_func_001044B8(120.0f, 160.0f);
                        stack.flags[1] = 1;
                    } else {
                        stack.target[0] += X_func_001044B8(-20.0f, 20.0f);
                        stack.target[2] += X_func_001044B8(120.0f, 160.0f);
                        stack.flags[2] = 1;
                    }
                }
                stack.target[1] += X_func_001D7DE4(&D_007812C0, &stack.origin[0]);
                if (X_func_0016976C(&stack.origin[0], &stack.target[0]) == 0) {
                    tries += 1;
                } else {
                    goto walk_success;
                }
            } while (tries < 3);
walk_after:
            if (tries == 3) {
                if (self->m_unk40 >= 2U) {
                    X_func_0010423C(0, 0x63);
                }
                X_func_001680A0(self, 0xC, 0);
                self->m_unk04 = 4;
            }
            break;

        case 1:
            if (self->m_unk24 != 0) {
                X_func_00202F10(self->m_owner->m_unk1F0);
                self->m_unk40 = 0U;
                self->m_unk04 = 0;
            }
            break;

        case 3:
            timer = self->m_unk48 - 1;
            self->m_unk48 = timer;
            if (timer < 0) {
                self->m_unk04 = 0;
                self->m_unk40 = self->m_unk40 + 1;
            }
            break;

        case 4:
            animDone = X_func_001D19A8(&D_007812C0, (unsigned int)self->m_unk00);
            if (animDone != 0) {
                tries = animDone != 0;
                self->m_owner->m_unk2C = 1;
                if (tries) {
                    stepCount = self->m_unk40 + 1;
                    self->m_unk40 = stepCount;
                    if ((stepCount < 3U) && (X_func_0010423C(0, 0x63) < 0x32)) {
                        self->m_unk04 = 0;
                    } else {
                        X_func_001682B0(self);
                        waitTimer = X_func_0010423C(0x14, 0x32);
                        self->m_unk48 = waitTimer;
                        self->m_unk04 = 3;
                    }
                }
            }
            break;
    }

    return -1;
}

extern "C" int func_001536CC(void)
{
    return 0;
}

extern "C" int func_001536D4(void)
{
    return 0;
}

extern "C" void NorOutWalk__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void NorOutDead__vfunc_02(NorOutDead *self)
{
    EmyObjStatView *stat0;
    EmyObjStatView *stat1;

    stat0 = (EmyObjStatView *)self->m_unk08;
    stat0->m_flags |= 0x400;
    stat1 = (EmyObjStatView *)self->m_unk08;
    stat1->m_flags |= 0x2000;
    X_func_001680A0(self, 1, 0x100);
}

extern "C" int NorOutDead__vfunc_03(void)
{
    return -1;
}

extern "C" void NorOutDead__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void NorOutBrownEv__vfunc_02(NorOutBrownEv *self)
{
    X_func_001680A0(self, 1, 0);
    self->m_unk04 = 0;
    D_007B205C->m_unk64C = 1;
}

extern "C" int NorOutBrownEv__vfunc_03(NorOutBrownEv *self)
{
    if (NorAnimDone(&D_007812C0, self)) {
        D_007B205C->m_unk64C = 0;
        return 8;
    }
    return -1;
}

extern "C" void NorOutCounter__vfunc_02(NorOutCounter *self)
{
    self->m_owner->m_unk150 = 0;
    X_func_001694CC(self, 0x56);
    X_func_001694CC(self, 0x63);
    X_func_001680A0(self, 0x2A, 0);
    self->m_unk38 = 0;
    self->m_unk40 = 0;
    self->m_unk3C = 0;
    self->m_unk04 = 0;
    X_func_00166DA4(self, 0x64);
}

// NON_MATCHING: 148/169 differ, 21 relocs differ (size 0x2A4, game 0x2B4), 44 edits
#ifdef NON_MATCHING
extern "C" int NorOutCounter__vfunc_03(NorOutCounter *self)
{
    int ret = -1;
    unsigned int targetPc;
    unsigned int targetDog;

    switch (self->m_unk04) {
        case 0:
            self->m_unk38++;
            func_0016649C(self->m_owner, 0);
            X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            if ((float)NorInRange(self->m_unk38, 17, 38) != 0.0f) {
                if ((self->m_unk3C == 0) && (X_func_00118FEC(&D_006E9840) != 9)) {
                    targetPc = (D_007A3350 != 0) ? D_007A3350->m_objStat100 : 0;
                    if (X_func_00169F94((unsigned int)self->m_unk00, 4, targetPc, 65.0f) != 0) {
                        NorInc(&((NorMain *)self->m_owner)->m_unk23C);
                        X_func_001694CC(self, 0x50);
                        self->m_unk3C = 1;
                        X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x24, targetPc, 0);
                    }
                }
                NorMain *norOwner = (NorMain *)self->m_owner;
                if (((norOwner->m_unk218 == 0) || (norOwner->m_unk230 != 0)) && (self->m_unk40 == 0) && (X_func_00119090(&D_006E9840) != 0xA) && (X_func_00119090(&D_006E9840) != 0xD)) {
                    targetDog = (D_007A3354 != 0) ? D_007A3354->m_objStat100 : 0;
                    if (X_func_00169F94((unsigned int)self->m_unk00, 4, targetDog, 65.0f) != 0) {
                        X_func_001694CC(self, 0x50);
                        self->m_unk40 = 1;
                        X_func_001FAC60(0xBU, self->m_unk00, 0, 0, 0x24, targetDog, 0);
                    }
                }
            }
            if (self->m_unk38 == 0x26) {
                self->m_unk04 = 2;
            }
            return ret;
        case 2:
            self->m_unk38++;
            func_0016649C(self->m_owner, 0);
            X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            if (NorAnimDone(&D_007812C0, self)) {
                ret = 8;
                func_0016649C(self->m_owner, 1);
                X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            }
            return ret;
        default:
            return -1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/NorOutAttack", NorOutCounter__vfunc_03);
#endif

extern "C" void NorOutCounter__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void NorOutCoax__vfunc_02(NorOutCoax *self)
{
    X_func_00167230(self, 0, 0.39269906282424927f);
    self->m_unk04 = 0;
    func_0016649C(self->m_owner, 0);
}

extern "C" int NorOutCoax__vfunc_03(NorOutCoax *self)
{
    func_0016649C(self->m_owner, 0);
    X_func_001D10D0(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
    if (func_001513EC(self->m_owner) == 0 && self->m_unk04 != 2) {
        X_func_001680A0(self, 0x14, 0);
        self->m_unk04 = 2;
    }
    switch (self->m_unk04) {
    case 0:
        if (self->m_unk28 != 0) {
            ((EmyOut *)self->m_owner->m_unk1F8)->m_unk04 = 0;
            X_func_001694CC(self, 0x59);
            X_func_001680A0(self, 0x12, 0);
            self->m_unk04 = 1;
        }
        break;
    case 1:
        if (NorAnimDone(&D_007812C0, self)) {
            X_func_001680A0(self, 0x13, 0x100);
        }
        break;
    case 2:
        if (NorAnimDone(&D_007812C0, self)) {
            func_0016649C(self->m_owner, 1);
            X_func_001D1410(&D_007812C0, (unsigned int)self->m_unk00, 0x400);
            func_0016649C(self->m_owner, 1);
            return 8;
        }
        break;
    }
    return -1;
}

extern "C" void NorOutTest__vfunc_02(NorOutTest *self)
{
    self->m_unk04 = 0;
    X_func_001680A0(self, 0x21, 0);
}

extern "C" int NorOutTest__vfunc_03(NorOutTest *self)
{
    switch (self->m_unk04) {
    case 0:
        if (NorAnimDone(&D_007812C0, self)) {
            X_func_001680A0(self, 0x28, 0);
            self->m_unk04 = 1;
        }
        break;
    case 1:
        if (NorAnimDone(&D_007812C0, self)) {
            X_func_001680A0(self, 0x28, 0);
            self->m_unk04 = 2;
        }
        break;
    case 2:
        if (NorAnimDone(&D_007812C0, self)) {
            X_func_001680A0(self, 0x28, 0);
            self->m_unk04 = 0;
        }
        break;
    }
    return -1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFBC8);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFBD8);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFBE8);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFBF8);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC08);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC18);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC28);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC38);
INCLUDE_RODATA("asm/nonmatchings/unk/NorOutAttack", D_002EFC48);
