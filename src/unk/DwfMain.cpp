#include "include_asm.h"
#include "emy/emy.h"

struct DwfVtblEntry {
    short m_delta;
    short m_index;
    void *m_fn;
};

struct DwfStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[0xA];
    signed char *m_flags;
};

struct DwfActorPtr {
    unsigned char m_pad00[0x100];
    int m_id;
};

struct DwfGlobals7812C0 {
    unsigned char m_pad00[0x22090];
    DwfActorPtr *m_pc;                  // +0x22090
    DwfActorPtr *m_dog;                 // +0x22094
    unsigned char m_pad22098[0x188];
    unsigned char m_itemDb[4];          // +0x22220
};

struct DwfAppearEntry {
    int m_anim;                         // +0x00
    unsigned char m_pad04[0x38];        // +0x04
}; // size 0x3C

struct DwfObjStatView : public EmyObjStatView {
    unsigned char m_pad128[0x2B8];      // +0x128
    int m_unk3E0;                       // +0x3E0
    int m_unk3E4;                       // +0x3E4
    int m_unk3E8;                       // +0x3E8
    int m_partsFlags;                   // +0x3EC
    int m_partsFlags2;                  // +0x3F0
};

struct DwfMain : public EmyMain {
    int m_condFlags[22];                // +0x204..+0x25B
    int m_unk25C;                       // +0x25C
    int m_unk260;                       // +0x260
    signed char m_unk264;               // +0x264
    signed char m_unk265;               // +0x265
    unsigned char m_unk266;             // +0x266
    unsigned char m_pad267;
    int m_unk268;                       // +0x268
    int m_unk26C;                       // +0x26C
    int m_unk270;                       // +0x270
};

struct DwfOutWalk : public EmyOut {
    int m_type;                         // +0x38
    int m_timer;                        // +0x3C
};

struct DwfOutPickup : public EmyOut {
    int m_type;                         // +0x38
    int m_targetId;                     // +0x3C
};

struct DwfOutAtkNear : public EmyOut {
    int m_type;                         // +0x38
    int m_subMode;                      // +0x3C
    int m_unk40;                        // +0x40
    int m_hitCount;                     // +0x44
    int m_maxHits;                      // +0x48
    int m_unk4C;                        // +0x4C
    unsigned char m_pad50[0x18];        // +0x50
    float m_range;                      // +0x68
};

struct DwfOutVtbl {
    unsigned char m_pad00[0x34];
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
};

struct DwfMainVtbl {
    unsigned char m_pad00[0x200];
    virtual void v1();
    virtual int v2();
    virtual int v3();
};

extern int vtbl_DwfMain asm("_vt$7DwfMain");
extern int vtbl_DwfOutDead asm("_vt$10DwfOutDead");
extern int vtbl_DwfOutFort asm("_vt$10DwfOutFort");
extern int vtbl_DwfOutTest asm("_vt$10DwfOutTest");
extern int vtbl_DwfOutWait asm("_vt$10DwfOutWait");
extern int vtbl_DwfOutWalk asm("_vt$10DwfOutWalk");
extern int vtbl_DwfOutParts asm("_vt$11DwfOutParts");
extern int vtbl_DwfOutSerch asm("_vt$11DwfOutSerch");
extern int vtbl_DwfOutAppear asm("_vt$12DwfOutAppear");
extern int vtbl_DwfOutAtkFar asm("_vt$12DwfOutAtkFar");
extern int vtbl_DwfOutPickup asm("_vt$12DwfOutPickup");
extern int vtbl_DwfOutStared asm("_vt$12DwfOutStared");
extern int vtbl_DwfOutAtkNear asm("_vt$13DwfOutAtkNear");
extern int vtbl_DwfOutIrritate asm("_vt$14DwfOutIrritate");
extern int vtbl_DwfOutDisappear asm("_vt$15DwfOutDisappear");
extern int vtbl_DwfOutWin asm("_vt$9DwfOutWin");

extern float D_002F0FC0[];
extern float D_002F0FD0[];
extern char D_006E9840[];
extern DwfGlobals7812C0 D_007812C0;
extern int D_007A3208;
extern DwfAppearEntry D_007B2294[];

extern "C" void *X___builtin_new(unsigned int) asm("__builtin_new");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_EmyMain__vfunc_01(void *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" unsigned int X_func_00118FEC(void *) asm("func_00118FEC__9MagSystem");
extern "C" int X_func_0015DAA8(void *) asm("func_0015DAA8");
extern "C" int X_func_0015DD74(void *) asm("func_0015DD74");
extern "C" int X_func_0015F37C(DwfOutAtkNear *) asm("func_0015F37C");
extern "C" int X_func_0015F8AC(DwfOutAtkNear *) asm("func_0015F8AC");
extern "C" int X_func_0015FF54(DwfOutAtkNear *) asm("func_0015FF54");
extern "C" int X_func_00165734(void) asm("func_00165734");
extern "C" int X_func_00165794(DwfMain *) asm("func_00165794");
extern "C" int X_func_00165A68(DwfMain *) asm("func_00165A68");
extern "C" int X_func_00165AA8(DwfMain *) asm("func_00165AA8");
extern "C" int X_func_00165D38(DwfMain *) asm("func_00165D38");
extern "C" int X_func_00165D7C(DwfMain *) asm("func_00165D7C");
extern "C" int X_func_00166004(DwfMain *) asm("func_00166004");
extern "C" int X_func_00166048(DwfMain *) asm("func_00166048");
extern "C" int X_func_00166108(DwfMain *) asm("func_00166108");
extern "C" int X_func_00166128(DwfMain *) asm("func_00166128");
extern "C" int X_func_00166178(DwfMain *) asm("func_00166178");
extern "C" int X_func_00166198(DwfMain *) asm("func_00166198");
extern "C" void X_func_0016649C(EmyMain *, int) asm("func_0016649C");
extern "C" void X_func_00166A1C(EmyOut *, int, void *, EmyMain *) asm("func_00166A1C");
extern "C" void X_func_00166AD0_v(void) asm("func_00166AD0");
extern "C" void X_func_00166AD0_p(EmyOut *) asm("func_00166AD0");
extern "C" void X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" void X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" int X_func_001679B4(EmyOut *, int, int, float, float) asm("func_001679B4");
extern "C" void X_func_001682B0(EmyOut *) asm("func_001682B0");
extern "C" void X_func_001687BC(EmyOut *, int, int) asm("func_001687BC");
extern "C" void X_func_00168844(EmyOut *) asm("func_00168844");
extern "C" void X_func_001694CC(EmyOut *, int) asm("func_001694CC");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_001696FC(void *, int) asm("func_001696FC");
extern "C" int X_func_00169BAC(float, float, int, int, void *) asm("func_00169BAC");
extern "C" unsigned short X_func_001CBEDC(void *, unsigned int) asm("func_001CBEDC");
extern "C" void X_func_001D10D0(void *, int, int) asm("func_001D10D0");
extern "C" void X_func_001D1410(void *, int, int) asm("func_001D1410");
extern "C" int X_func_001D19A8(void *, int) asm("func_001D19A8");
extern "C" void X_func_001D23F8(void *, int, int) asm("func_001D23F8");
extern "C" void X_func_001DA228(void *, int, void *) asm("func_001DA228");
extern "C" void X_func_001DA740(void *, int, void *) asm("func_001DA740");
extern "C" void X_func_001DC48C(void *, int, int, void *) asm("func_001DC48C");
extern "C" void X_func_001F9D90(int, void *) asm("func_001F9D90");
extern "C" void X_func_00202F10(void *) asm("func_00202F10");

extern "C" int func_0015CE88(DwfMain *self);
extern "C" int func_0015CF30(DwfMain *self);
extern "C" int func_0015D08C(DwfMain *self);
extern "C" int func_0015D134(DwfMain *self);
extern "C" int func_0015D1DC(DwfMain *self);
extern "C" int func_0015D284(DwfMain *self);
extern "C" int func_0015D32C(DwfMain *self);
extern "C" int func_0015D3E0(DwfMain *self);
extern "C" int func_0015D488(DwfMain *self);
extern "C" int func_0015D530(DwfMain *self);
extern "C" int func_0015D5D8(DwfMain *self);
extern "C" int func_0015D680(DwfMain *self);
extern "C" int func_0015D738(DwfMain *self);
extern "C" int func_0015D7F0(DwfMain *self);
extern "C" int func_0015D890(DwfMain *self);
extern "C" int func_0015D948(DwfMain *self);
extern "C" int func_0015DA00(DwfMain *self);

static inline int DwfAnimDone(void *world, EmyOut *obj)
{
    int r = X_func_001D19A8(world, obj->m_unk00);
    if (r) {
        obj->m_owner->m_unk2C = 1;
    }
    return r;
}

extern "C" void DwfMain__vfunc_01(DwfMain *self, int flags)
{
    self->m_vtbl = &vtbl_DwfMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return Xv___builtin_delete(self);
    }
}

extern "C" void func_0015C304(DwfMain *self)
{
    struct {
        int sp0;
        int sp4;
        char pad8[40];
    } stack;
    EmyOut *out;

    register int three PS2_REG("$3") = 3;
    register int one PS2_REG("$18") = 1;
    register int mode46 PS2_REG("$8") = 46;
    register int mode36 PS2_REG("$9") = 36;
    register int eight PS2_REG("$10") = 8;
    register int nine PS2_REG("$11") = 9;
    register int fourteen PS2_REG("$12") = 14;
    register int fifteen PS2_REG("$13") = 15;
    register int seven PS2_REG("$5") = 7;
    register int eleven PS2_REG("$6") = 11;
    register int two PS2_REG("$7") = 2;
    register int ten PS2_REG("$2") = 10;

    *(int *)(self->m_padEC + 0x08) = three;
    *(int *)(self->m_padEC + 0x20) = mode46;
    *(int *)(self->m_padEC + 0x24) = mode36;
    *(int *)(self->m_padEC + 0x2C) = eight;
    *(int *)(self->m_padEC + 0x30) = nine;
    *(int *)(self->m_padEC + 0x34) = fourteen;
    *(int *)(self->m_padEC + 0x38) = fifteen;
    *(int *)(self->m_padEC + 0x0C) = seven;
    *(int *)(self->m_padEC + 0x10) = eleven;
    *(int *)(self->m_padEC + 0x18) = two;
    *(int *)(self->m_padEC + 0x04) = ten;
    *(int *)(self->m_padEC + 0x00) = one;
    *(int *)(self->m_padEC + 0x28) = one;
    self->m_stateFlags[0] = one;
    self->m_stateFlags[2] = one;
    self->m_stateFlags[7] = one;
    self->m_stateFlags[3] = one;
    self->m_stateFlags[11] = one;
    self->m_stateFlags[10] = one;
    self->m_stateFlags[12] = one;
    self->m_stateFlags[5] = one;
    self->m_unk266 = 0;
    self->m_unk265 = 0;
    self->m_unk264 = 0;
    self->m_stateFlags[1] = 0;
    self->m_stateFlags[8] = 0;
    self->m_stateFlags[9] = 0;
    self->m_stateFlags[4] = 0;
    self->m_stateFlags[6] = 0;
    self->m_stateFlags[13] = 0;
    self->m_stateFlags[14] = one;
    self->m_stateFlags[15] = 0;

    out = (EmyOut *)X___builtin_new(0x38);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutDisappear;
    ((EmyOut **)self->m_unk48)[1] = out;

    out = (EmyOut *)X___builtin_new(0x38);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutAppear;
    ((EmyOut **)self->m_unk48)[2] = out;

    out = (EmyOut *)X___builtin_new(0x84);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutAtkNear;
    ((EmyOut **)self->m_unk48)[3] = out;

    out = (EmyOut *)X___builtin_new(0x40);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutDead;
    ((EmyOut **)self->m_unk48)[4] = out;

    out = (EmyOut *)X___builtin_new(0x48);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutStared;
    ((EmyOut **)self->m_unk48)[5] = out;

    out = (EmyOut *)X___builtin_new(0x40);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutWin;
    ((EmyOut **)self->m_unk48)[6] = out;

    out = (EmyOut *)X___builtin_new(0x38);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutSerch;
    ((EmyOut **)self->m_unk48)[7] = out;

    out = (EmyOut *)X___builtin_new(0x50);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutWalk;
    ((EmyOut **)self->m_unk48)[8] = out;

    out = (EmyOut *)X___builtin_new(0x38);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutWait;
    ((EmyOut **)self->m_unk48)[9] = out;

    out = (EmyOut *)X___builtin_new(0x40);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutAtkFar;
    ((EmyOut **)self->m_unk48)[10] = out;

    out = (EmyOut *)X___builtin_new(0x40);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutPickup;
    ((EmyOut **)self->m_unk48)[11] = out;

    out = (EmyOut *)X___builtin_new(0x3C);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutParts;
    ((EmyOut **)self->m_unk48)[12] = out;

    out = (EmyOut *)X___builtin_new(0x68);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutFort;
    ((EmyOut **)self->m_unk48)[13] = out;

    out = (EmyOut *)X___builtin_new(0x44);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutIrritate;
    ((EmyOut **)self->m_unk48)[14] = out;

    out = (EmyOut *)X___builtin_new(0x38);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_DwfOutTest;
    ((EmyOut **)self->m_unk48)[15] = out;

    X_func_001DA228(self->m_objStat, 0x18, &stack);
    {
        void *actor = self->m_objStat;
        stack.sp4 = one;
        X_func_001DA740(actor, 0x18, &stack);
    }
    self->m_unk06 = X_func_0010423C(0, 2);
    self->m_unk07 = X_func_0010423C(0, 3);
    self->m_unk26C = X_func_0015DAA8(self->m_objStat);
    self->m_unk270 = X_func_0015DD74(self->m_objStat);
}

extern "C" void DwfMain__vfunc_04(DwfMain *self)
{
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_5;
    int temp_v1_6;
    int var_a0;
    int var_a0_2;
    int var_a0_3;
    int var_a0_4;
    int var_a0_5;
    int temp_v1;

    if (D_007A3208 & 0x40000) {
        self->m_unk26C = X_func_0015DAA8(self->m_objStat);
        self->m_unk270 = X_func_0015DD74(self->m_objStat);
    }
    if ((self->m_unk28 != 0) && (self->m_unk2C != 0) && (self->m_nextState == -1)) {
        if ((self->m_condFlags[21] != 0) && (func_0015DA00(self) != 0)) {
            self->m_nextState = 0x15;
        }
        if ((self->m_condFlags[20] != 0) && (func_0015D948(self) != 0)) {
            self->m_nextState = 0x14;
        }
        if ((self->m_condFlags[19] != 0) && (func_0015D890(self) != 0)) {
            self->m_nextState = 0x13;
        }
        if ((self->m_condFlags[18] != 0) && (func_0015D7F0(self) != 0)) {
            self->m_nextState = 0x12;
        }
        if ((self->m_condFlags[17] != 0) && (func_0015D738(self) != 0)) {
            self->m_nextState = 0x11;
        }
        if ((self->m_condFlags[16] != 0) && (func_0015D680(self) != 0)) {
            self->m_nextState = 0x10;
        }
        if ((self->m_condFlags[15] != 0) && (func_0015D5D8(self) != 0)) {
            self->m_nextState = 0xF;
        }
        if ((self->m_condFlags[14] != 0) && (func_0015D530(self) != 0)) {
            self->m_nextState = 0xE;
        }
        if ((self->m_condFlags[13] != 0) && (func_0015D488(self) != 0)) {
            self->m_nextState = 0xD;
        }
        temp_v1 = func_0015CF30(self);
        if (self->m_unk266 != 0) {
            temp_v0_3 = temp_v1;
            self->m_unk266 = temp_v0_3;
            if ((temp_v1 & 0xFF) == 0) {
                if (self->m_condFlags[6] != 0) {
                    temp_v0_2 = X_func_001696FC(self->m_brain, 6);
                    if ((temp_v0_2 == 0xB) && (self->m_unk26C == 0)) {
                        var_a0 = 1;
                    } else if ((temp_v0_2 == 0xC) && (self->m_unk270 == 0)) {
                        var_a0 = 1;
                    } else if (temp_v0_2 == 0xE) {
                        var_a0 = 0;
                        temp_v1_2 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
                        if (temp_v1_2 & 8) {
                            var_a0 = 1;
                            if (!(temp_v1_2 & 0x10)) {
                                var_a0 = 0;
                            }
                        }
                    } else {
                        var_a0 = 0;
                    }
                    if (var_a0 == 0) {
                        self->m_nextState = 6;
                    }
                }
            } else {
                if ((self->m_condFlags[12] != 0) && (func_0015D3E0(self) != 0)) {
                    self->m_nextState = 0xC;
                }
                if ((self->m_condFlags[11] != 0) && (func_0015D32C(self) != 0)) {
                    self->m_nextState = 0xB;
                }
                if ((self->m_condFlags[10] != 0) && (func_0015D284(self) != 0)) {
                    self->m_nextState = 0xA;
                }
                if ((self->m_condFlags[9] != 0) && (func_0015D1DC(self) != 0)) {
                    self->m_nextState = 9;
                }
                if ((self->m_condFlags[8] != 0) && (func_0015D134(self) != 0)) {
                    self->m_nextState = 8;
                }
                if (self->m_condFlags[7] != 0) {
                    if (func_0015D08C(self) != 0) {
                        self->m_nextState = 7;
                    }
                }
            }
        } else {
            self->m_unk266 = temp_v1;
            if (((temp_v1 & 0xFF) != 0) && (self->m_condFlags[5] != 0)) {
                temp_v0_3 = X_func_001696FC(self->m_brain, 5);
                if ((temp_v0_3 == 0xB) && (self->m_unk26C == 0)) {
                    var_a0_2 = 1;
                } else if ((temp_v0_3 == 0xC) && (self->m_unk270 == 0)) {
                    var_a0_2 = 1;
                } else if (temp_v0_3 == 0xE) {
                    var_a0_2 = 0;
                    temp_v1_3 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
                    if (temp_v1_3 & 8) {
                        var_a0_2 = 1;
                        if (!(temp_v1_3 & 0x10)) {
                            var_a0_2 = 0;
                        }
                    }
                } else {
                    var_a0_2 = 0;
                }
                if (var_a0_2 == 0) {
                    self->m_nextState = 5;
                }
            }
        }
        if ((self->m_condFlags[4] != 0) && (self->m_flags30 & 1)) {
            temp_v0_4 = X_func_001696FC(self->m_brain, 4);
            if ((temp_v0_4 == 0xB) && (self->m_unk26C == 0)) {
                var_a0_3 = 1;
            } else if ((temp_v0_4 == 0xC) && (self->m_unk270 == 0)) {
                var_a0_3 = 1;
            } else if (temp_v0_4 == 0xE) {
                var_a0_3 = 0;
                temp_v1_4 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
                if (temp_v1_4 & 8) {
                    var_a0_3 = 1;
                    if (!(temp_v1_4 & 0x10)) {
                        var_a0_3 = 0;
                    }
                }
            } else {
                var_a0_3 = 0;
            }
            if (var_a0_3 == 0) {
                self->m_nextState = 4;
            }
        }
        if ((self->m_condFlags[3] != 0) && (self->m_flags30 & 8)) {
            temp_v0_5 = X_func_001696FC(self->m_brain, 3);
            if ((temp_v0_5 == 0xB) && (self->m_unk26C == 0)) {
                var_a0_4 = 1;
            } else {
                temp_v1_3 = temp_v0_5;
                if ((temp_v1_3 == 0xC) && (self->m_unk270 == 0)) {
                    var_a0_4 = 1;
                } else if (temp_v1_3 == 0xE) {
                    var_a0_4 = 0;
                    temp_v1_5 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
                    if (temp_v1_5 & 8) {
                        var_a0_4 = 1;
                        if (!(temp_v1_5 & 0x10)) {
                            var_a0_4 = 0;
                        }
                    }
                } else {
                    var_a0_4 = 0;
                }
            }
            if (var_a0_4 == 0) {
                self->m_nextState = 3;
            }
        }
        if ((self->m_condFlags[2] != 0) && (self->m_flags30 & 4)) {
            temp_v0_6 = X_func_001696FC(self->m_brain, 2);
            if ((temp_v0_6 == 0xB) && (self->m_unk26C == 0)) {
                var_a0_5 = 1;
            } else if ((temp_v0_6 == 0xC) && (self->m_unk270 == 0)) {
                var_a0_5 = 1;
            } else if (temp_v0_6 == 0xE) {
                var_a0_5 = 0;
                temp_v1_6 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
                if (temp_v1_6 & 8) {
                    var_a0_5 = 1;
                    if (!(temp_v1_6 & 0x10)) {
                        var_a0_5 = 0;
                    }
                }
            } else {
                var_a0_5 = 0;
            }
            if (var_a0_5 == 0) {
                self->m_nextState = 2;
            }
        }
        if ((self->m_condFlags[1] != 0) && (func_0015CE88(self) != 0)) {
            self->m_nextState = 1;
        }
    }
}

extern "C" void DwfMain__vfunc_05(DwfMain *self)
{
    int temp_a0;
    int temp_v0;
    int temp_v0_2;

    self->m_stateChanged = 0;
    temp_a0 = self->m_flags30;
    if (temp_a0 & 2) {
        self->m_curState = 4;
        ((EmyBrainView *)self->m_brain)->m_state = 4;
        self->m_stateChanged = 1;
    } else {
        temp_v0 = self->m_nextState;
        if (temp_v0 != -1) {
            temp_v0_2 = X_func_0016968C(self->m_brain, temp_v0);
            self->m_unk265 = 0;
            self->m_unk264 = 0;
            self->m_unk266 = 0;
            if (temp_v0_2 != 0) {
                self->m_curState = temp_v0_2;
                self->m_stateChanged = 1;
            } else {
                ((EmyBrainView *)self->m_brain)->m_state = self->m_curState;
            }
        } else if (temp_a0 & 1) {
            ((EmyBrainView *)self->m_brain)->m_state = self->m_curState;
            self->m_stateChanged = 1;
        }
    }
    self->m_flags30 = 0;
}

extern "C" void DwfMain__vfunc_06(DwfMain *self)
{
    if (self->m_stateChanged != 0) {
        ((DwfOutVtbl *)self->m_curOut)->v4();
        ((DwfMainVtbl *)self)->v2();
    }
    self->m_nextState = ((DwfOutVtbl *)self->m_curOut)->v3();
}

extern "C" int DwfMain__vfunc_02(DwfMain *self)
{
    int v;
    EmyOut *obj;
    DwfVtblEntry *vt;
    register DwfStateTable *e8 PS2_REG("$3");
    int count;
    register signed char *base PS2_REG("$7");
    register int v2 PS2_REG("$2");
    int i;
    int *dst;

    v = self->m_curState;
    if (v != 0) {
        if (v >= 0) {
            if (v < 0x10) {
                char *slot = (char *)((v * 4) + (int)self);
                obj = ((EmyOut **)(slot + 0x48))[0];
                self->m_curOut = obj;
                vt = (DwfVtblEntry *)((char *)obj->m_vtbl + 0x10);
                ((void (*)(char *))vt->m_fn)((char *)obj + vt->m_delta);
            }
        }
    }
    i = 0;
    e8 = (DwfStateTable *)self->m_unkE8;
    count = e8->m_count;
    v2 = self->m_curState;
    base = e8->m_flags + (v2 * count);
    for (; i < count; i++) {
        dst = (int *)((char *)self + 4);
        if (base[i] != 0) {
            ((int *)((char *)(dst + i) + 0x200))[0] = 1;
        } else {
            ((int *)((char *)(dst + i) + 0x200))[0] = 0;
        }
    }
    return 0;
}

extern "C" int func_0015CE74(void)
{
    return X_func_00165734();
}

extern "C" int func_0015CE88(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 1);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00165794(self);
}

// D_002F0DD8: the end of unk/PigMain's .rodata now (config/splits_manual.tsv)
// D_002F0DE8: the end of unk/PigMain's .rodata now (config/splits_manual.tsv)
// D_002F0DF8: the end of unk/PigMain's .rodata now (config/splits_manual.tsv)
// D_002F0E08: the end of unk/PigMain's .rodata now (config/splits_manual.tsv)

static inline int DwfHasBit0(DwfObjStatView *s)
{
    int v = s->m_partsFlags & 1;
    return v != 0;
}

// NON_MATCHING: 68/83 differ (size 0x14C, game 0x15C), 23 edits
#ifdef NON_MATCHING
extern "C" int func_0015CF30(DwfMain *self)
{
    float sp0;
    float maxDist;
    int r1;
    int r2;
    int mode;
    int targetId;
    DwfActorPtr *p;

    X_func_001DA228(self->m_objStat, 0x5F, &sp0);
    if (DwfHasBit0((DwfObjStatView *)self->m_objStat) || (self->m_curState == 1)) {
        switch (X_func_00118FEC(D_006E9840)) {
        case 2:
        case 3:
        case 7:
            maxDist = 200.0f;
            break;
        case 6:
            maxDist = 100.0f;
            break;
        case 0:
        case 12:
        default:
            maxDist = 60.0f;
            break;
        }
        mode = 0;
        if (maxDist < sp0) {
            sp0 = maxDist;
        }
    } else {
        mode = 1;
    }
    targetId = 0;
    p = *(DwfActorPtr **)((char *)&D_007812C0 + 0x22090);
    if (p != 0) {
        targetId = p->m_id;
    }
    {
        register float pi1 PS2_REG("$f13") = 3.1415926218032837f;
        r1 = X_func_00169BAC(sp0, pi1, mode, targetId, self->m_objStat);
    }
    targetId = 0;
    p = *(DwfActorPtr **)((char *)&D_007812C0 + 0x22094);
    if (p != 0) {
        targetId = p->m_id;
    }
    {
        register float pi2 PS2_REG("$f13") = 3.1415926218032837f;
        r2 = X_func_00169BAC(sp0, pi2, mode, targetId, self->m_objStat);
    }
    return (r1 != 0) | (r2 != 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015CF30);
#endif

extern "C" int func_0015D08C(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 7);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00165A68(self);
}

extern "C" int func_0015D134(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 8);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00165AA8(self);
}

extern "C" int func_0015D1DC(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 9);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00165D38(self);
}

extern "C" int func_0015D284(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 0xA);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00165D7C(self);
}

extern "C" int func_0015D32C(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;
    int k = 0xB;

    temp_v0 = X_func_001696FC(self->m_brain, k);
    if (temp_v0 == k && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00166004(self);
}

extern "C" int func_0015D3E0(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 0xC);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00166048(self);
}

extern "C" int func_0015D488(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 13);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00166128(self);
}

extern "C" int func_0015D530(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 0xE);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00166108(self);
}

extern "C" int func_0015D5D8(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 0xF);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00166178(self);
}

// NON_MATCHING: 3/46 differ (bnel vs bnez, andi $a0 vs $v0), 3 edits
#ifdef NON_MATCHING
extern "C" int func_0015D680(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 0x10);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0 == 0) {
        register DwfObjStatView *obj20 PS2_REG("$2") = (DwfObjStatView *)self->m_objStat;
        register int f PS2_REG("$3") = obj20->m_partsFlags;
        if (!(f & 8)) {
            return 0;
        }
        if (f & 0x10) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D680);
#endif

// NON_MATCHING: 3/46 differ (bnel vs bnez, andi $a0 vs $v0), 3 edits
#ifdef NON_MATCHING
extern "C" int func_0015D738(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 0x11);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0 == 0) {
        register DwfObjStatView *obj20 PS2_REG("$2") = (DwfObjStatView *)self->m_objStat;
        register int f PS2_REG("$3") = obj20->m_partsFlags;
        if (!(f & 2)) {
            return 0;
        }
        if (f & 4) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015D738);
#endif

extern "C" int func_0015D7F0(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;
    int var_v0;

    temp_v0 = X_func_001696FC(self->m_brain, 0x12);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    var_v0 = 0;
    if (var_a0 == 0) {
        var_v0 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags & 1;
    }
    return var_v0;
}

extern "C" int func_0015D890(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 0x13);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0 == 0) {
        register DwfObjStatView *obj20 PS2_REG("$2") = (DwfObjStatView *)self->m_objStat;
        register int temp_v1_2 PS2_REG("$3") = obj20->m_partsFlags;
        if (!(temp_v1_2 & 2)) {
            if (!(temp_v1_2 & 4)) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

extern "C" int func_0015D948(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 0x14);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0 == 0) {
        register DwfObjStatView *obj20 PS2_REG("$2") = (DwfObjStatView *)self->m_objStat;
        register int temp_v1_2 PS2_REG("$3") = obj20->m_partsFlags;
        if (!(temp_v1_2 & 8)) {
            if (!(temp_v1_2 & 0x10)) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

extern "C" int func_0015DA00(DwfMain *self)
{
    int temp_v0;
    int temp_v1;
    int var_a0;

    temp_v0 = X_func_001696FC(self->m_brain, 21);
    if (temp_v0 == 0xB && self->m_unk26C == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xC && self->m_unk270 == 0) {
        var_a0 = 1;
    } else if (temp_v0 == 0xE) {
        var_a0 = 0;
        temp_v1 = ((DwfObjStatView *)self->m_objStat)->m_partsFlags;
        if (temp_v1 & 8) {
            var_a0 = 1;
            if (!(temp_v1 & 0x10)) {
                var_a0 = 0;
            }
        }
    } else {
        var_a0 = 0;
    }
    if (var_a0) {
        return 0;
    }
    return X_func_00166198(self);
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015DAA8);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015DD74);

extern "C" void DwfOutDisappear__vfunc_02(EmyOut *self)
{
    X_func_001D23F8(&D_007812C0, self->m_unk00, 1);
    X_func_001687BC(self, 0x1D, 0x100);
    self->m_owner->m_unk0C = 0;
    X_func_001D1410(&D_007812C0, self->m_unk00, 0x40);
    X_func_001D10D0(&D_007812C0, self->m_unk00, 0x10000000);
    X_func_001D10D0(&D_007812C0, self->m_unk00, 0x400);
    self->m_unk04 = 0;
}

extern "C" void DwfOutDisappear__vfunc_04(EmyOut *self)
{
    X_func_001D23F8(&D_007812C0, self->m_unk00, 0);
    self->m_owner->m_unk0C = 1;
    X_func_001D10D0(&D_007812C0, self->m_unk00, 0x40);
    X_func_001D1410(&D_007812C0, self->m_unk00, 0x10000000);
    X_func_001D1410(&D_007812C0, self->m_unk00, 0x400);
    X_func_00166AD0_p(self);
}

extern "C" void DwfOutAppear__vfunc_02(EmyOut *self)
{
    EmyObjStatView *objStat;

    self->m_owner->m_unk0C = 0;
    objStat = (EmyObjStatView *)self->m_unk08;
    objStat->m_flags |= 0x400;
    self->m_unk04 = 0;
}

extern "C" int DwfOutAppear__vfunc_03(EmyOut *self)
{
    int ret = -1;

    switch (self->m_unk04) {
    case 0:
        X_func_001D23F8(&D_007812C0, self->m_unk00, 0);
        X_func_001D1410(&D_007812C0, self->m_unk00, 0x40);
        X_func_001D10D0(&D_007812C0, self->m_unk00, 0x10000000);
        X_func_001D10D0(&D_007812C0, self->m_unk00, 0x400);
        X_func_001687BC(self, D_007B2294[self->m_owner->m_unk1C8].m_anim, 0);
        self->m_unk04 = 1;
        break;
    case 1:
        if (DwfAnimDone(&D_007812C0, self) != 0) {
            ret = 0x16;
            X_func_001D10D0(&D_007812C0, self->m_unk00, 0x40);
            X_func_001D1410(&D_007812C0, self->m_unk00, 0x10000000);
            X_func_001D1410(&D_007812C0, self->m_unk00, 0x400);
            self->m_owner->m_unk0C = 1;
            ((EmyObjStatView *)self->m_unk08)->m_flags &= ~0x400;
            ((EmyObjStatView *)self->m_unk08)->m_flags &= ~0x2000;
        }
        break;
    }
    return ret;
}

extern "C" void DwfOutWait__vfunc_02(EmyOut *self)
{
    if (((DwfMainVtbl *)self->m_owner)->v3() == 2) {
        X_func_00168844(self);
    } else {
        X_func_001682B0(self);
    }
    self->m_unk04 = 0;
}

extern "C" int DwfOutWait__vfunc_03(void)
{
    return -1;
}

extern "C" void DwfOutWalk__vfunc_02(DwfOutWalk *self)
{
    int type;

    type = ((DwfMainVtbl *)self->m_owner)->v3();
    switch ((unsigned int)type) {
    case 1:
        self->m_type = type;
        break;
    case 0:
        self->m_type = 0;
        break;
    case 2:
        self->m_type = type;
        break;
    }
    if (self->m_type == 2) {
        X_func_00168844(self);
    } else {
        X_func_001682B0(self);
    }
    X_func_00166DA4(self, 0x64);
    self->m_unk04 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0E58);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0E68);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0E80);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0E90);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutWalk__vfunc_03);

extern "C" void DwfOutWalk__vfunc_04(void)
{
    X_func_00166AD0_v();
}

extern "C" void func_0015EAA8(DwfOutWalk *self, int state)
{
    if (self->m_unk04 != state) {
        self->m_unk04 = state;
        self->m_timer = 0;
    }
}

extern "C" void DwfOutSerch__vfunc_02(EmyOut *self)
{
    X_func_00166DA4(self, 0x64);
    X_func_00166F50(self, self->m_unk14, 10.0f);
}

extern "C" int DwfOutSerch__vfunc_03(EmyOut *self)
{
    int var_s1;
    int type;

    if (X_func_001679B4(self, self->m_unk14, 0, 200.0f, 3.141592562198639f) == 0) {
        var_s1 = -1;
    } else {
        type = ((DwfMainVtbl *)self->m_owner)->v3();
        switch ((unsigned int)type) {
        case 1:
            var_s1 = 0x16;
            break;
        case 0:
            var_s1 = 0x16;
            break;
        case 2:
            var_s1 = 0x16;
            break;
        }
        X_func_00202F10(self->m_owner->m_unk1F0);
    }
    return var_s1;
}

extern "C" void DwfOutSerch__vfunc_04(void)
{
    X_func_00166AD0_v();
}

extern "C" void DwfOutPickup__vfunc_02(DwfOutPickup *self)
{
    int type;

    type = ((DwfMainVtbl *)self->m_owner)->v3();
    switch ((unsigned int)type) {
    case 1:
        self->m_type = type;
        break;
    case 0:
        self->m_type = 0;
        break;
    case 2:
        self->m_type = type;
        break;
    }
    self->m_unk04 = 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0EC0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0ED0);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutPickup__vfunc_03);

extern "C" void DwfOutPickup__vfunc_04(void)
{
    X_func_00166AD0_v();
}

extern "C" void DwfOutAtkNear__vfunc_04(void)
{
    X_func_00166AD0_v();
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", DwfOutAtkNear__vfunc_02);

extern "C" int DwfOutAtkNear__vfunc_03(DwfOutAtkNear *self)
{
    int var_a2 = -1;

    switch (self->m_subMode) {
    case 0:
        var_a2 = X_func_0015F37C(self);
        break;
    case 1:
        var_a2 = X_func_0015F8AC(self);
        break;
    case 2:
        var_a2 = X_func_0015FF54(self);
        break;
    }
    return var_a2;
}

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015F37C);

// NON_MATCHING: 81/85 differ (size 0x154, game 0x168), 29 edits
#ifdef NON_MATCHING
extern "C" int func_0015F744(DwfOutAtkNear *self)
{
    struct {
        unsigned int sp0;
        char pad4[0xC];
        int sp10;
        int sp14;
        int sp18;
        char pad1C[0x8];
        unsigned int sp24;
        char pad28[0x10];
        float sp38;
        char pad3C[0x4];
        unsigned short sp40;
        char pad42[0xE];
    } stack;
    unsigned short itemId;

    X_func_001DA228((void *)self->m_unk08, 0x67, &stack.sp0);
    if (stack.sp0 != 0) {
        self->m_hitCount++;
        X_func_0016649C(self->m_owner, 0);
        stack.sp10 = self->m_unk14;
        stack.sp14 = self->m_type;
        itemId = X_func_001CBEDC(&D_007812C0, stack.sp0);
        if (self->m_type == 2 && itemId == 0xA2E) {
            int hits = self->m_hitCount;
            stack.sp24 = stack.sp0;
            if (hits == 0) {
                if (X_func_0010423C(0, 0x63) < 0x32) {
                    stack.sp18 = 0x14;
                    self->m_hitCount = 1;
                } else {
                    stack.sp18 = 0x13;
                }
            } else if (hits == 1) {
                stack.sp18 = 0x14;
            } else {
                stack.sp18 = 0x13;
            }
            stack.sp38 = self->m_range;
        } else {
            stack.sp18 = 0x12;
            X_func_001DC48C(D_007812C0.m_itemDb, itemId, 0x28, &stack.sp40);
            if (stack.sp40 == 4) {
                stack.sp38 = D_002F0FC0[self->m_type];
            } else {
                stack.sp38 = D_002F0FD0[self->m_type];
            }
        }
        X_func_001F9D90(self->m_unk00, &stack.sp10);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015F744);
#endif

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0F00);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0F10);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0F20);

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015F8AC);

// NON_MATCHING: 7/27 differ (size 0x6C == game 0x6C, movz vs beql+bnez), 7 edits
#ifdef NON_MATCHING
extern "C" int func_0015FEE8(DwfOutAtkNear *self)
{
    register int ret PS2_REG("$2") = 0;
    int f = ((DwfObjStatView *)self->m_unk08)->m_partsFlags;

    if (!DwfHasBit0((DwfObjStatView *)self->m_unk08)) {
        int anim;
        if (!(f & 8)) {
            anim = 0x3F;
        } else if (f & 0x10) {
            anim = 0x3C;
        } else {
            anim = 0x3F;
        }
        X_func_001687BC(self, anim, 0);
        X_func_001694CC(self, 0xB);
        ret = 1;
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015FEE8);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/DwfMain", func_0015FF54);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FA0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FA8);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FB0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FC0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FD0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FE0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F0FF0);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1000);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1010);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1020);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1030);

INCLUDE_RODATA("asm/nonmatchings/unk/DwfMain", D_002F1040);
