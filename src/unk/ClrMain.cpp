#include "include_asm.h"
#include "emy/emy.h"
#include "ror.h"

struct ClrVtblEntry {
    short m_delta;
    short m_index;
    void *m_fn;
};

struct ClrStateTable {
    unsigned char m_unk00;
    unsigned char m_count;
    unsigned char m_pad02[0xA];
    signed char *m_flags;
};

struct ClrActorPtr {
    unsigned char m_pad00[0x100];
    int m_id;
};

struct ClrDmgEntry {
    int m_active;
    int m_delay;
    int m_duration;
    int m_kind;
    float m_radius;
    float m_pos[3];
};

struct ClrMain : public EmyMain {
    unsigned char m_unk204;             // +0x204
    unsigned char m_pad205[3];
    int m_condFlags[14];                // +0x208..+0x23F
    int m_unk240;                       // +0x240
    unsigned char m_unk244;             // +0x244
    unsigned char m_pad245[3];
    int m_unk248;                       // +0x248
    int m_unk24C;                       // +0x24C
    float m_pos[4];                     // +0x250..+0x25F
    int m_phase;                        // +0x260
    int m_heightMode;                   // +0x264
    int m_unk268;                       // +0x268
    int m_unk26C;                       // +0x26C
    int m_dmgCursor;                    // +0x270
    ClrDmgEntry m_dmgList[64];          // +0x274..+0xA73
};

struct ClrOutUp : public EmyOut {
    unsigned char m_pad38[0x08];        // +0x38
    float m_pos[4];                     // +0x40
    unsigned char m_pad50[0x40];        // +0x50
    int m_unk90;                        // +0x90
    float m_timer;                      // +0x94
    int m_unk98;                        // +0x98
    int m_step;                         // +0x9C
    int m_unkA0;                        // +0xA0
    int m_unkA4;                        // +0xA4
    int m_unkA8;                        // +0xA8
    int m_effId;                        // +0xAC
    unsigned char m_padB0[0x30];        // +0xB0
}; // size 0xE0

struct ClrOutDeathUp : public EmyOut {
    unsigned char m_pad38[0x08];        // +0x38
    float m_pos[4];                     // +0x40
    unsigned char m_pad50[0x40];        // +0x50
    int m_unk90;                        // +0x90
    int m_unk94;                        // +0x94
    int m_unk98;                        // +0x98
    int m_step;                         // +0x9C
    unsigned char m_padA0[0x10];        // +0xA0
}; // size 0xB0

struct ClrOutMove : public EmyOut {
    unsigned char m_pad38[0x08];        // +0x38
    float m_pos[4];                     // +0x40
    float m_basePos[4];                 // +0x50
    unsigned char m_pad60[0x10];        // +0x60
    float m_rot[4];                     // +0x70
    unsigned char m_pad80[0x10];        // +0x80
    int m_unk90;                        // +0x90
    float m_timer;                      // +0x94
    float m_targetY;                    // +0x98
    int m_step;                         // +0x9C
    int m_hit0;                         // +0xA0
    int m_hit1;                         // +0xA4
    int m_waitTimer;                    // +0xA8
    int m_seHandle;                     // +0xAC
    int m_effId;                        // +0xB0
    unsigned char m_padB4[0x24];        // +0xB4
    float m_effPos[4];                  // +0xD8
    float m_effDir[4];                  // +0xE8
    unsigned char m_padF8[0x08];        // +0xF8
}; // size 0x100

struct ClrOutAtk : public EmyOut {
    unsigned char m_pad38[0x140];       // +0x38
    int m_unk178;                       // +0x178
    int m_unk17C;                       // +0x17C
    int m_unk180;                       // +0x180
    int m_unk184;                       // +0x184
    float m_yawSpeed;                   // +0x188
    int m_unk18C;                       // +0x18C
    int m_unk190;                       // +0x190
    int m_unk194;                       // +0x194
    int m_unk198;                       // +0x198
}; // size 0x19C

struct ClrOutWin : public EmyOut {
    float m_dist;                       // +0x38
};

struct ClrOutVtbl {
    unsigned char m_pad00[0x34];
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
};

struct ClrMainVtbl {
    unsigned char m_pad00[0x200];
    virtual void v1();
    virtual int v2();
};

struct ClrGlobal7B205C {
    unsigned char m_pad00[0x788];
    int m_effId;                        // +0x788
};

struct ClrEffParamA {
    int m_kind;                         // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    float *m_p0;                        // +0x10
    float *m_p1;                        // +0x14
    float m_f18;                        // +0x18
    float m_f1C;                        // +0x1C
    float m_f20;                        // +0x20
    float m_f24;                        // +0x24
    float m_f28;                        // +0x28
    float m_f2C;                        // +0x2C
    float m_f30;                        // +0x30
    int m_i34;                          // +0x34
    int m_pad[18];                      // +0x38..+0x7F
};

struct ClrEffParamC {
    int m_kind;                         // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    float m_pos[3];                     // +0x10..+0x1B
    float m_unk1C;                      // +0x1C
    float m_col[4];                     // +0x20..+0x2F
    int m_dur;                          // +0x30
    int m_pad[19];                      // +0x34..+0x7F
};

extern int vtbl_ClrMain asm("_vt$7ClrMain");
extern int vtbl_ClrOutUp asm("_vt$8ClrOutUp");
extern int vtbl_ClrOutDeathUp asm("_vt$13ClrOutDeathUp");
extern int vtbl_ClrOutMove asm("_vt$10ClrOutMove");
extern int vtbl_ClrOutAtk asm("_vt$9ClrOutAtk");

extern char D_006FBD80[];
extern char D_006FE6A0[];
extern int D_00724EA0[];
extern char D_007812C0[];
extern ClrActorPtr *D_007A3350;
extern ClrActorPtr *D_007A3354;
extern ClrGlobal7B205C *D_007B205C;

extern "C" void *X___builtin_new(unsigned int) asm("__builtin_new");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_EmyMain__vfunc_01(void *, int) asm("EmyMain__vfunc_01");
extern "C" int X_func_0010423C(int, int) asm("func_0010423C");
extern "C" float X_func_001044B8(float, float) asm("func_001044B8");
extern "C" float X_func_0010A650(void *) asm("func_0010A650__8DogActor");
extern "C" int X_func_0014E4D4(ClrMain *) asm("func_0014E4D4");
extern "C" int X_func_0014E850(ClrOutUp *, int) asm("func_0014E850");
extern "C" int X_func_0014FEBC(ClrOutAtk *, int) asm("func_0014FEBC");
extern "C" int X_func_00165A68(ClrMain *) asm("func_00165A68");
extern "C" int X_func_00165AA8(ClrMain *) asm("func_00165AA8");
extern "C" int X_func_00165D7C(ClrMain *) asm("func_00165D7C");
extern "C" void X_func_0016649C(EmyMain *, int) asm("func_0016649C");
extern "C" void X_func_00166A1C(EmyOut *, int, void *, EmyMain *) asm("func_00166A1C");
extern "C" void X_func_00166AD0(void) asm("func_00166AD0");
extern "C" void X_func_00166B74(EmyOut *, float *) asm("func_00166B74");
extern "C" void X_func_00166DA4(EmyOut *, int) asm("func_00166DA4");
extern "C" void X_func_00166F50(EmyOut *, int, float) asm("func_00166F50");
extern "C" int X_func_001679B4(EmyOut *, int, int, float, float) asm("func_001679B4");
extern "C" void X_func_001680A0(EmyOut *, int, int) asm("func_001680A0");
extern "C" int X_func_0016968C(void *, int) asm("func_0016968C");
extern "C" int X_func_00169BAC(int, int, void *, float, float) asm("func_00169BAC");
extern "C" void X_func_0016A6B4(float *) asm("func_0016A6B4");
extern "C" void X_func_00176CC8(void *, void *) asm("func_00176CC8");
extern "C" int X_func_001CBE38(void *, int) asm("func_001CBE38");
extern "C" void X_func_001D10D0(void *, int, int) asm("func_001D10D0");
extern "C" void X_func_001D1410(void *, int, int) asm("func_001D1410");
extern "C" void X_func_001D890C(void *, float *) asm("func_001D890C");
extern "C" void X_func_001D8964(void *, float *) asm("func_001D8964");
extern "C" void X_func_001D89C4(void *, float *) asm("func_001D89C4");
extern "C" void X_func_001D8A8C(void *, float *) asm("func_001D8A8C");
extern "C" void X_func_00202F10(void *) asm("func_00202F10");
extern "C" float X_func_0026CB00(float, float) asm("func_0026CB00");
extern "C" void *X_memset(void *, int, unsigned int) asm("memset");

extern "C" int func_0014E2EC(ClrMain *self);
extern "C" int func_0014E300(ClrMain *self);
extern "C" int func_0014E314(ClrMain *self);
extern "C" int func_0014E328(ClrMain *self);
extern "C" int func_0014E33C(ClrMain *self);
extern "C" int func_0014E350(ClrMain *self);
extern "C" int func_0014E364(void);
extern "C" int func_0014E36C(ClrMain *self);
extern "C" int func_0014E374(ClrMain *self);
extern "C" int func_0014E37C(ClrMain *self);
extern "C" int func_0014E384(ClrMain *self);
extern "C" int func_0014E38C(ClrMain *self);
extern "C" int func_0014E3D0(ClrMain *self, float *pos, int delay, int duration, int kind, float radius);
extern "C" int func_0014ED10(ClrOutDeathUp *self, int reset);

// NON_MATCHING: 78/118 differ, 3 relocs differ (size 0x1D8 == game 0x1D8), 86 edits
#ifdef NON_MATCHING
extern "C" void ClrMain__vfunc_07(ClrMain *self)
{
    int i;
    EmyOut *out;

    *(int *)(self->m_padEC + 0x08) = 6;
    *(int *)(self->m_padEC + 0x28) = 0xC;
    self->m_phase = 5;
    *(int *)(self->m_padEC + 0x04) = 5;
    *(int *)(self->m_padEC + 0x24) = 0xC;
    *(int *)(self->m_padEC + 0x1C) = 0x12;
    self->m_heightMode = 1;
    self->m_unk204 = 0;
    self->m_unk244 = 0;
    *(int *)(self->m_padEC + 0x00) = 1;
    self->m_stateFlags[0] = 0;
    self->m_stateFlags[1] = 1;
    self->m_stateFlags[2] = 1;
    self->m_stateFlags[3] = 1;
    self->m_stateFlags[4] = 1;
    self->m_stateFlags[5] = 1;
    self->m_unk26C = X_func_0010423C(0x5A, 0xD2);
    X_func_001D890C(self->m_objStat, self->m_pos);
    self->m_pos[1] = -52.652984619140625f;
    X_func_001D89C4(self->m_objStat, self->m_pos);

    out = (EmyOut *)X___builtin_new(0x100);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_ClrOutMove;
    ((EmyOut **)self->m_unk48)[1] = out;

    out = (EmyOut *)X___builtin_new(0x19C);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_ClrOutAtk;
    ((EmyOut **)self->m_unk48)[2] = out;

    out = (EmyOut *)X___builtin_new(0xE0);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_ClrOutUp;
    ((EmyOut **)self->m_unk48)[3] = out;

    out = (EmyOut *)X___builtin_new(0xB0);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_ClrOutDeathUp;
    ((EmyOut **)self->m_unk48)[4] = out;

    out = (EmyOut *)X___builtin_new(0xE0);
    X_func_00166A1C(out, self->m_id, self->m_objStat, self);
    out->m_vtbl = &vtbl_ClrOutUp;
    ((EmyOut **)self->m_unk48)[5] = out;

    self->m_dmgCursor = 0;
    for (i = 0; i < 0x40; i++) {
        self->m_dmgList[i].m_active = 0;
    }
    self->m_unk24C = 0;
    self->m_unk248 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_07);
#endif

extern "C" void ClrMain__vfunc_01(ClrMain *self, int flags)
{
    self->m_vtbl = &vtbl_ClrMain;
    X_EmyMain__vfunc_01(self, 0);
    if (flags & 1) {
        return Xv___builtin_delete(self);
    }
}

extern "C" void ClrMain__vfunc_04(ClrMain *self)
{
    int temp_v0;
    int temp_v1;

    if ((self->m_unk28 != 0) && (self->m_unk2C != 0) && (self->m_nextState == -1)) {
        if ((self->m_condFlags[13] != 0) && (func_0014E364() != 0)) {
            self->m_nextState = 0xD;
        }
        if ((self->m_condFlags[12] != 0) && (func_0014E36C(self) != 0)) {
            self->m_nextState = 0xC;
        }
        if ((self->m_condFlags[11] != 0) && (func_0014E374(self) != 0)) {
            self->m_nextState = 0xB;
        }
        if ((self->m_condFlags[10] != 0) && (func_0014E37C(self) != 0)) {
            self->m_nextState = 0xA;
        }
        if ((self->m_condFlags[9] != 0) && (func_0014E384(self) != 0)) {
            self->m_nextState = 9;
        }
        temp_v1 = func_0014E38C(self);
        if (self->m_unk204 != 0) {
            temp_v0 = (unsigned char)(self->m_unk204 = temp_v1);
            if (temp_v0 == 0) {
                if (self->m_condFlags[2] != 0) {
                    self->m_nextState = 2;
                }
            } else {
                if ((self->m_condFlags[3] != 0) && (func_0014E2EC(self) != 0)) {
                    self->m_nextState = 3;
                }
                if ((self->m_condFlags[4] != 0) && (func_0014E300(self) != 0)) {
                    self->m_nextState = 4;
                }
                if ((self->m_condFlags[5] != 0) && (func_0014E314(self) != 0)) {
                    self->m_nextState = 5;
                }
                if ((self->m_condFlags[6] != 0) && (func_0014E328(self) != 0)) {
                    self->m_nextState = 6;
                }
                if ((self->m_condFlags[7] != 0) && (func_0014E33C(self) != 0)) {
                    self->m_nextState = 7;
                }
                if (self->m_condFlags[8] != 0) {
                    if (func_0014E350(self) != 0) {
                        self->m_nextState = 8;
                    }
                }
            }
        } else {
            temp_v0 = (unsigned char)(self->m_unk204 = temp_v1);
            if (temp_v0 != 0) {
                if (self->m_condFlags[0] != 0) {
                    self->m_nextState = 0;
                }
                if (self->m_condFlags[1] != 0) {
                    self->m_nextState = 1;
                }
            }
        }
    }
}

// NON_MATCHING: 17/46 differ (beql+bltzl clamp vs movz+movn), 13 edits
#ifdef NON_MATCHING
static inline int ClrClampState(int v)
{
    if (v >= 6) {
        return 0;
    }
    if (v < 0) {
        return 0;
    }
    return v;
}

extern "C" void ClrMain__vfunc_05(ClrMain *self)
{
    int flags;

    self->m_stateChanged = 0;
    flags = self->m_flags30;
    if (flags & 2) {
        self->m_stateChanged = 1;
        self->m_curState = 4;
    } else {
        int nextState = self->m_nextState;
        if (nextState != -1) {
            int next = ClrClampState(X_func_0016968C(self->m_brain, nextState));
            if (next != 0) {
                self->m_curState = next;
                self->m_stateChanged = 1;
                self->m_unk24C = 0;
                self->m_unk204 = 0;
            }
        } else if (flags & 1) {
            ((EmyBrainView *)self->m_brain)->m_state = self->m_curState;
            self->m_stateChanged = 1;
            self->m_unk24C++;
        }
    }
    self->m_flags30 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrMain__vfunc_05);
#endif

extern "C" void ClrMain__vfunc_06(ClrMain *self)
{
    int idx = X_func_001CBE38(D_007812C0, self->m_id) & 0xFFFF;
    D_00724EA0[idx] &= ~0x60;
    X_func_0014E4D4(self);
    if (self->m_stateChanged != 0) {
        ((ClrOutVtbl *)self->m_curOut)->v4();
        ((ClrMainVtbl *)self)->v2();
    }
    self->m_nextState = ((ClrOutVtbl *)self->m_curOut)->v3();
}

extern "C" int ClrMain__vfunc_02(ClrMain *self)
{
    int v;
    EmyOut *obj;
    ClrVtblEntry *vt;
    register ClrStateTable *e8 PS2_REG("$3");
    int count;
    register signed char *base PS2_REG("$7");
    register int v2 PS2_REG("$2");
    int i;
    int *dst;

    v = self->m_curState;
    if (v != 0) {
        if (v >= 0) {
            if (v < 6) {
                char *slot = (char *)((v * 4) + (int)self);
                obj = ((EmyOut **)(slot + 0x48))[0];
                self->m_curOut = obj;
                vt = (ClrVtblEntry *)((char *)obj->m_vtbl + 0x10);
                ((void (*)(char *))vt->m_fn)((char *)obj + vt->m_delta);
            }
        }
    }
    i = 0;
    e8 = (ClrStateTable *)self->m_unkE8;
    count = e8->m_count;
    v2 = self->m_curState;
    base = e8->m_flags + (v2 * count);
    for (; i < count; i++) {
        dst = (int *)((char *)self + 8);
        if (base[i] != 0) {
            ((int *)((char *)(dst + i) + 0x200))[0] = 1;
        } else {
            ((int *)((char *)(dst + i) + 0x200))[0] = 0;
        }
    }
    return 0;
}

extern "C" int func_0014E2EC(ClrMain *self)
{
    return X_func_00165A68(self);
}

extern "C" int func_0014E300(ClrMain *self)
{
    return X_func_00165A68(self);
}

extern "C" int func_0014E314(ClrMain *self)
{
    return X_func_00165AA8(self);
}

extern "C" int func_0014E328(ClrMain *self)
{
    return X_func_00165AA8(self);
}

extern "C" int func_0014E33C(ClrMain *self)
{
    return X_func_00165D7C(self);
}

extern "C" int func_0014E350(ClrMain *self)
{
    return X_func_00165D7C(self);
}

extern "C" int func_0014E364(void)
{
    return 0;
}

extern "C" int func_0014E36C(ClrMain *self)
{
    (void)self;
    return 0;
}

extern "C" int func_0014E374(ClrMain *self)
{
    (void)self;
    return 0;
}

extern "C" int func_0014E37C(ClrMain *self)
{
    (void)self;
    return 0;
}

extern "C" int func_0014E384(ClrMain *self)
{
    (void)self;
    return 0;
}

extern "C" int func_0014E38C(ClrMain *self)
{
    int var_a1;

    var_a1 = 0;
    if (D_007A3350 != 0) {
        var_a1 = D_007A3350->m_id;
    }
    return X_func_00169BAC(1, var_a1, self->m_objStat, 0.0f, 2.356194317340851f);
}

extern "C" int func_0014E3D0(ClrMain *self, float *pos, int delay, int duration, int kind, float radius)
{
    int ret = -1;
    int pass;

    for (pass = 0; pass < 2; pass++) {
        int start = self->m_dmgCursor;
        int end = 0x40;
        int i;

        if (pass != 0) {
            end = start;
            start = 0;
        }
        for (i = start; i < end; i++) {
            if (self->m_dmgList[i].m_active == 0) {
                self->m_dmgList[i].m_active = 1;
                self->m_dmgList[i].m_delay = delay;
                self->m_dmgList[i].m_duration = duration;
                self->m_dmgList[i].m_kind = kind;
                self->m_dmgList[i].m_radius = radius;
                self->m_dmgList[i].m_pos[0] = pos[0];
                self->m_dmgList[i].m_pos[1] = pos[1];
                self->m_dmgList[i].m_pos[2] = pos[2];
                self->m_dmgCursor = i + 1;
                if (i + 1 >= 0x40) {
                    self->m_dmgCursor = 0;
                }
                ret = i;
                break;
            }
        }
        if (ret >= 0) {
            break;
        }
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E4D4);

extern "C" void ClrOutUp__vfunc_02(ClrOutUp *self)
{
    self->m_effId = D_007B205C->m_effId;
}

extern "C" int ClrOutUp__vfunc_03(ClrOutUp *self)
{
    int ret = -1;
    ClrMain *owner = (ClrMain *)self->m_owner;

    switch (owner->m_phase) {
    case 5:
        owner->m_phase = 6;
        X_func_0016649C(self->m_owner, 0);
        X_func_001D10D0(D_007812C0, self->m_unk00, 0x400);
    case 6:
        X_func_0014E850(self, 1);
        ((ClrMain *)self->m_owner)->m_phase = 7;
        break;
    case 7:
        if (X_func_0014E850(self, 0) == 1) {
            ClrMain *o;
            ((ClrMain *)self->m_owner)->m_phase = 0;
            ret = 0xD;
            o = (ClrMain *)self->m_owner;
            o->m_unk26C = X_func_0010423C(0x1E, 0x96);
        }
        break;
    }
    return ret;
}

extern "C" void ClrOutUp__vfunc_04(void)
{
    X_func_00166AD0();
}

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014E850);

extern "C" void ClrOutDeathUp__vfunc_02(ClrOutDeathUp *self)
{
    ClrMain *owner;

    X_func_001D1410(D_007812C0, self->m_unk00, 0x40);
    X_func_001D10D0(D_007812C0, self->m_unk00, 0x10000000);
    X_func_001D10D0(D_007812C0, self->m_unk00, 0x400);
    owner = (ClrMain *)self->m_owner;
    if (owner->m_phase == 5) {
        owner->m_phase = 6;
    }
}

// D_002EF7B8: the end of unk/MrtMain's .rodata now (config/splits_manual.tsv)
// D_002EF7C8: the end of unk/MrtMain's .rodata now (config/splits_manual.tsv)
// D_002EF7D8: the end of unk/MrtMain's .rodata now (config/splits_manual.tsv)
// D_002EF7E8: the end of unk/MrtMain's .rodata now (config/splits_manual.tsv)

extern "C" int ClrOutDeathUp__vfunc_03(ClrOutDeathUp *self)
{
    switch (((ClrMain *)self->m_owner)->m_phase) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
        break;
    case 5:
        X_func_001D1410(D_007812C0, self->m_unk00, 0x40);
        X_func_001D10D0(D_007812C0, self->m_unk00, 0x10000000);
        X_func_001D10D0(D_007812C0, self->m_unk00, 0x400);
        ((ClrMain *)self->m_owner)->m_phase = 6;
        break;
    case 6:
        func_0014ED10(self, 1);
        ((ClrMain *)self->m_owner)->m_phase = 7;
        break;
    case 7:
        X_func_001D1410(D_007812C0, self->m_unk00, 0x40);
        X_func_001D10D0(D_007812C0, self->m_unk00, 0x10000000);
        X_func_001D10D0(D_007812C0, self->m_unk00, 0x400);
        if (func_0014ED10(self, 0) == 1) {
            ClrMain *o;
            ((ClrMain *)self->m_owner)->m_phase = 0;
            o = (ClrMain *)self->m_owner;
            o->m_unk26C = X_func_0010423C(0x1E, 0x96);
        }
        break;
    }
    return -1;
}

extern "C" void ClrOutDeathUp__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" int func_0014ED10(ClrOutDeathUp *self, int reset)
{
    int ret = 0;

    X_func_0016649C(self->m_owner, 0);
    X_func_001D10D0(D_007812C0, self->m_unk00, 0x400);
    if (reset == 1) {
        self->m_step = 0;
    }
    switch (self->m_step) {
    case 0:
        self->m_step = 1;
        self->m_unk90 = 0;
        X_func_001680A0(self, 0xA, 0x100);
    case 1:
        X_func_001D890C((void *)self->m_unk08, self->m_pos);
        self->m_pos[1] -= 2.0f;
        if (self->m_pos[1] <= -347.345977783203125f) {
            self->m_pos[1] = -347.345977783203125f;
            X_func_001680A0(self, 1, 0x100);
            self->m_step = 2;
            ret = 1;
        }
        X_func_001D89C4((void *)self->m_unk08, self->m_pos);
        break;
    case 2:
        self->m_step = 9999;
    case 9999:
        ret = 1;
        break;
    }
    return ret;
}

extern "C" void ClrOutMove__vfunc_02(ClrOutMove *self)
{
    X_func_0016649C(self->m_owner, 1);
    X_func_001D1410(D_007812C0, self->m_unk00, 0x400);
    X_func_00166DA4(self, 0x64);
    self->m_effId = D_007B205C->m_effId;
}

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF828);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutMove__vfunc_03);

extern "C" void ClrOutMove__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" int func_0014F23C(ClrOutMove *self)
{
    float targetPos[4];
    float selfPos[4];
    float rot[4];
    float yaw;

    X_func_001D890C(D_007A3350, targetPos);
    X_func_001D890C((void *)self->m_unk08, selfPos);
    yaw = X_func_0026CB00(targetPos[0] - selfPos[0], targetPos[2] - selfPos[2]);
    X_func_001D8964((void *)self->m_unk08, rot);
    yaw -= rot[1];
    if ((double)yaw < -3.14159265358979323846) {
        yaw = (float)((double)yaw + 6.28318530717958647692);
    }
    if ((double)yaw > 3.14159265358979323846) {
        yaw = (float)((double)yaw - 6.28318530717958647692);
    }
    rot[1] = yaw;
    X_func_001D8A8C((void *)self->m_unk08, rot);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F360);

// NON_MATCHING: 19/88 differ (size 0x160 == game 0x160, store scheduling), 15 edits
#ifdef NON_MATCHING
extern "C" void func_0014F72C(ClrOutMove *self)
{
    ClrEffParamA param0;
    ClrEffParamC param1;
    int off = 0x837E0;
    char *effMgr = D_006FBD80 + off;
    float one = 1.0f;
    float half = 0.5f;

    {
        register float x PS2_REG("$f2") = self->m_pos[0];
        register float y PS2_REG("$f0") = self->m_pos[1];
        register float z PS2_REG("$f1") = self->m_pos[2];
        self->m_effPos[0] = x;
        self->m_effPos[1] = y;
        self->m_effPos[2] = z;
    }
    self->m_effPos[3] = 0.0f;
    self->m_effDir[0] = 0.0f;
    self->m_effDir[1] = one;
    self->m_effDir[2] = 0.0f;
    self->m_effDir[3] = 0.0f;

    X_memset(&param0, 0, sizeof(param0));
    param0.m_kind = 0xA;
    param0.m_p0 = self->m_effPos;
    param0.m_p1 = self->m_effDir;
    param0.m_f18 = half;
    param0.m_f1C = one;
    param0.m_f20 = one;
    param0.m_f24 = one;
    param0.m_f28 = one;
    param0.m_f2C = one;
    param0.m_f30 = one;
    param0.m_i34 = 8;
    param0.m_unk08 = 0;
    X_func_00176CC8(effMgr, &param0);

    param1.m_col[2] = one;
    param1.m_col[3] = half;
    param1.m_dur = 0x64;
    param1.m_col[0] = one;
    param1.m_col[1] = one;
    param1.m_kind = 0xC;
    param1.m_unk08 = 0x14;
    param1.m_pos[0] = self->m_pos[0];
    param1.m_pos[1] = -10.0f;
    param1.m_pos[2] = self->m_pos[2];
    param1.m_unk1C = 100.0f;
    X_func_00176CC8(effMgr, &param1);

    func_0014E3D0((ClrMain *)self->m_owner, param1.m_pos, param1.m_unk08, param1.m_dur, 1, 25.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014F72C);
#endif

extern "C" void ClrOutAtk__vfunc_02(ClrOutAtk *self)
{
    X_func_00166DA4(self, 0x64);
    X_func_0014FEBC(self, 1);
    X_func_0016649C(self->m_owner, 1);
    X_func_001D1410(D_007812C0, self->m_unk00, 0x400);
    self->m_unk184 = -1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF888);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF898);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8B0);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", ClrOutAtk__vfunc_03);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8D8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8E0);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8E8);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF8F0);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_0014FEBC);

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_00150290);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF950);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF960);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF970);

INCLUDE_RODATA("asm/nonmatchings/unk/ClrMain", D_002EF978);

extern "C" int func_001506A0(ClrOutAtk *self)
{
    float selfPos[4];
    float targetPos[4];
    char *actor;
    float yaw;
    register int ret PS2_REG("$2");

    actor = D_006FE6A0 + X_func_001CBE38(D_007812C0, self->m_unk00) * 0x4D0;
    X_func_00166B74(self, selfPos);
    X_func_0016A6B4(targetPos);
    yaw = X_func_0026CB00(targetPos[0] - selfPos[0], targetPos[2] - selfPos[2]);
    yaw -= X_func_0010A650(actor);
    if ((double)yaw < -3.14159265358979323846) {
        yaw = (float)((double)yaw + 6.28318530717958647692);
    }
    if ((double)yaw > 3.14159265358979323846) {
        yaw = (float)((double)yaw - 6.28318530717958647692);
    }
    if ((double)yaw < (3.14159265358979323846 / 3.0) && (double)yaw > (-3.14159265358979323846 / 3.0)) {
        ret = 0;
    } else if (yaw > 0.0f) {
        ret = 2;
    } else {
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/unk/ClrMain", func_00150804);

extern "C" int func_00150A1C(void)
{
    return 0;
}

extern "C" void ClrOutAtk__vfunc_04(void)
{
    X_func_00166AD0();
}

extern "C" void ClrOutWin__vfunc_02(ClrOutWin *self)
{
    self->m_dist = X_func_001044B8(100.0f, 200.0f);
    X_func_00166F50(self, self->m_unk14, 10.0f);
    self->m_unk04 = 0;
}

extern "C" int ClrOutWin__vfunc_03(ClrOutWin *self)
{
    if ((self->m_unk04 == 0) && (X_func_001679B4(self, self->m_unk14, 1, self->m_dist, 0.7853981405496597f) != 0)) {
        X_func_00202F10(self->m_owner->m_unk1F0);
        X_func_001680A0(self, 0x15, 0x100);
        self->m_unk04 = 1;
    }
    return -1;
}

extern "C" void ClrOutWin__vfunc_04(void)
{
    X_func_00166AD0();
}
