#include "include_asm.h"
#include "001A6830.h"
#include "game/gamman.h"
extern "C" void func_001AF024(MnuItem *);
extern "C" int func_0018741C(MnuMsgWin *);
extern "C" void Xvp_func_001AEBC8(void *) asm("func_001AEBC8");
struct SprAE9F4 {
    unsigned char m_unk[0x8EC];
    ~SprAE9F4() asm("func_0018BC18");
};
struct Sub1B64_AE9F4 {
    unsigned char m_unk[0x104];
    ~Sub1B64_AE9F4() asm("func_001A0684");
};
struct MsgAE9F4 {
    unsigned char m_unk[0x3BC];
    ~MsgAE9F4() asm("func_00183B24");
};
struct Base1_AE9F4 {
    unsigned char m_pad00[0x98];
    SprAE9F4 m_spr0;
    SprAE9F4 m_spr1;
    SprAE9F4 m_spr2;
    unsigned char m_pad1B5C[8];
    Sub1B64_AE9F4 m_1B64;
    inline ~Base1_AE9F4() {}
};
struct Base2_AE9F4 {
    MsgAE9F4 m_msg[2];
    inline ~Base2_AE9F4() {}
};
struct ObjAE9F4 : public Base1_AE9F4, public Base2_AE9F4 {
    unsigned char m_pad23E0[0xA0];
    int m_2480;
    ~ObjAE9F4() asm("func_001AE9F4");
};
extern "C" int Xvp_snprintf(void *, int, const char *, ...) asm("snprintf");
extern "C" char *Xvp_strcpy(char *, const char *) asm("strcpy");
extern "C" unsigned int Xvp_strlen(const char *) asm("strlen");
extern int D_002F9428;
extern int D_002F9430;
static inline unsigned int padTrigU_F40(int p) { return *(unsigned short *)((char *)p + 0x7A); }
extern MnuRpkEntry X_D_002ACA20[] asm("D_002ACA20");
extern MnuBoardTblEnt X_D_002ABDB8[] asm("D_002ABDB8");
extern "C" void Xvp_func_0018F744(void *, void *, const char *) asm("func_0018F744");
extern "C" int Xvp_func_0018FEBC(void *) asm("func_0018FEBC");
extern "C" void Xvp_func_001AB5E4(void *) asm("func_001AB5E4");
extern "C" void Xvp_func_001AB6F4(void *) asm("func_001AB6F4");
struct MsgAB4E0 {
    unsigned char m_unk[0x3BC];
    ~MsgAB4E0() asm("func_00183B24");
};
struct SprAB4E0 {
    unsigned char m_unk[0x8FC];
    ~SprAB4E0() asm("func_0018BC18");
};
struct PadAB4E0 {
    unsigned char m_pad[0x58];
};
struct BaseAB4E0 {
    MsgAB4E0 m_msg[2];
    inline ~BaseAB4E0() {}
};
struct ObjAB4E0 : public PadAB4E0, public BaseAB4E0 {
    SprAB4E0 m_spr;
    int m_10CC;
    ~ObjAB4E0() asm("func_001AB4E0");
};
extern "C" void Xvp_func_0018BC18(void *, int) asm("func_0018BC18");
extern "C" void Xvp_func_001AD870(void *) asm("func_001AD870");
extern "C" void Xvp_func_001AD940(void *) asm("func_001AD940");
struct MsgAD72C {
    unsigned char m_unk[0x3BC];
    ~MsgAD72C() asm("func_00183B24");
};
struct ObjAD72C {
    MsgAD72C m_msg[2];
    unsigned char m_pad778[0x93C];
    int m_10B4;
    ~ObjAD72C() asm("func_001AD72C");
};
extern int D_007A3210;
extern int D_007A4440;
// declarations from the code that moved to mnu/mnusvld (0x1A6830-0x1A90EC):
static inline int *sysFlags_F130()
{
    char *p = (char *)&D_007A4440;
    return *(int **)(p + 0xDC20);
}
extern "C" void Xv___builtin_delete_9150(void *) asm("__builtin_delete");
extern "C" int X_func_0018BC18(...) asm("func_0018BC18");
extern "C" int X_func_001A0684(...) asm("func_001A0684");
extern "C" int X_func_001A12A8(...) asm("func_001A12A8");
extern "C" int X_func_001A5A34(...) asm("func_001A5A34");
extern "C" int X_func_001A9258(...) asm("func_001A9258");
extern "C" int X_func_001AB4E0(...) asm("func_001AB4E0");
extern "C" int X_func_0018C190_1(int, int) asm("func_0018C190");
extern int D_002A8848;
extern int D_002AAD70;
extern "C" int X_func_001AF024(...) asm("func_001AF024");
extern "C" int X_func_001AF3F0(...) asm("func_001AF3F0");
extern "C" int X_func_001DC48C(...) asm("func_001DC48C");
extern "C" void Xv_func_001AE574(int) asm("func_001AE574");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xii_func_0018BC18(int, int) asm("func_0018BC18");
extern "C" void Xv_func_001ADFE4(int) asm("func_001ADFE4");
extern "C" int Xiiii_func_001A6C90(int, int, int) asm("func_001A6C90");
extern "C" int Xii_func_0018741C(int) asm("func_0018741C");
extern "C" int Xiii_func_001AF44C(int, int) asm("func_001AF44C");
extern "C" int Xii_func_0018330C(int) asm("func_0018330C");
extern "C" int Xii_func_0018BB8C(int) asm("func_0018BB8C");
extern "C" int Xii_func_001A066C(int) asm("func_001A066C");
extern "C" int Xii_func_001AEB7C(int) asm("func_001AEB7C");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_001A97F4(int) asm("func_001A97F4");
extern "C" int Xiii_func_0018BCC0(int, int) asm("func_0018BCC0");
extern "C" int Xiii_func_0018C190(int, int) asm("func_0018C190");
extern int D_002A7858;
extern int D_002A80C0;
extern int D_002ABB08;
extern int D_002ABCE8;
extern int D_002AC7B8;
extern int D_002AC980;
extern int D_006FE04C;
extern int _9MagSystem$m_current_system;
extern "C" int Xii_func_0018FEBC(int) asm("func_0018FEBC");
extern "C" int Xiiii_func_0018F744(int, int, int) asm("func_0018F744");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00118980__9MagSystemiiiiii(...) asm("func_00118980__9MagSystemiiiiii");
extern "C" int X_func_00131184(...) asm("func_00131184");
extern "C" int X_func_001311BC(...) asm("func_001311BC");
extern "C" int X_func_00131550(...) asm("func_00131550");
extern "C" int X_func_00134730(...) asm("func_00134730");
extern "C" int X_func_001348B0(...) asm("func_001348B0");
extern "C" int X_func_00135088(...) asm("func_00135088");
extern "C" int X_func_0013511C(...) asm("func_0013511C");
extern "C" int X_func_001351B0(...) asm("func_001351B0");
extern "C" int X_func_00135594(...) asm("func_00135594");
extern "C" int X_func_0017F264(...) asm("func_0017F264");
extern "C" int X_func_0017F308(...) asm("func_0017F308");
extern "C" int X_func_0017F5E8(...) asm("func_0017F5E8");
extern "C" int X_func_0017F8FC(...) asm("func_0017F8FC");
extern "C" int X_func_001832E8(...) asm("func_001832E8");
extern "C" int X_func_0018330C(...) asm("func_0018330C");
extern "C" int X_func_0018741C(...) asm("func_0018741C");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001874AC(...) asm("func_001874AC");
extern "C" int X_func_001874F4(...) asm("func_001874F4");
extern "C" int X_func_0018BB8C(...) asm("func_0018BB8C");
extern "C" int X_func_0018BCC0(...) asm("func_0018BCC0");
extern "C" int X_func_0018BD94(...) asm("func_0018BD94");
extern "C" int X_func_0018C068(...) asm("func_0018C068");
extern "C" int X_func_0018C130(...) asm("func_0018C130");
extern "C" int X_func_0018C2E4(...) asm("func_0018C2E4");
extern "C" int X_func_0018C4D8(...) asm("func_0018C4D8");
extern "C" int X_func_0018C6C4(...) asm("func_0018C6C4");
extern "C" int X_func_0018D7EC(...) asm("func_0018D7EC");
extern "C" int X_func_0018F060(...) asm("func_0018F060");
extern "C" int X_func_0018F09C(...) asm("func_0018F09C");
extern "C" int X_func_0018F0B4(...) asm("func_0018F0B4");
extern "C" int X_func_0018F1F4(...) asm("func_0018F1F4");
extern "C" int X_func_0018F41C(...) asm("func_0018F41C");
extern "C" int X_func_0018F744(...) asm("func_0018F744");
extern "C" int X_func_0018F808(...) asm("func_0018F808");
extern "C" int X_func_0018F9CC(...) asm("func_0018F9CC");
extern "C" int X_func_0018FAB4(...) asm("func_0018FAB4");
extern "C" int X_func_0018FBB0(...) asm("func_0018FBB0");
extern "C" int X_func_0018FEBC(...) asm("func_0018FEBC");
extern "C" int X_func_001A066C(...) asm("func_001A066C");
extern "C" int X_func_001A1244(...) asm("func_001A1244");
extern "C" int X_func_001A1658(...) asm("func_001A1658");
extern "C" int X_func_001A1C8C(...) asm("func_001A1C8C");
extern "C" int X_func_001A59B8(...) asm("func_001A59B8");
extern "C" int X_func_001A5AF4(...) asm("func_001A5AF4");
extern "C" int X_func_001A5BF4(...) asm("func_001A5BF4");
extern "C" int X_func_001A5CC4(...) asm("func_001A5CC4");
extern "C" int X_func_001A5CD8(...) asm("func_001A5CD8");
extern "C" int X_func_001A5DA0(...) asm("func_001A5DA0");
extern "C" int X_func_001A6BF8(...) asm("func_001A6BF8");
extern "C" int X_func_001A6C90(...) asm("func_001A6C90");
extern "C" int X_func_001A6FE8(...) asm("func_001A6FE8");
extern "C" int X_func_001A7088(...) asm("func_001A7088");
extern "C" int X_func_001A7498(...) asm("func_001A7498");
extern "C" int X_func_001A90DC(...) asm("func_001A90DC");
extern "C" int X_func_001A90E4(...) asm("func_001A90E4");
extern "C" int X_func_001A9828(...) asm("func_001A9828");
extern "C" int X_func_001A9844(...) asm("func_001A9844");
extern "C" int X_func_001AB474(...) asm("func_001AB474");
extern "C" int X_func_001AB598(...) asm("func_001AB598");
extern "C" int X_func_001AB5E4(...) asm("func_001AB5E4");
extern "C" int X_func_001AB66C(...) asm("func_001AB66C");
extern "C" int X_func_001AB680(...) asm("func_001AB680");
extern "C" int X_func_001AB6AC(...) asm("func_001AB6AC");
extern "C" int X_func_001AB6F4(...) asm("func_001AB6F4");
extern "C" int X_func_001AB720(...) asm("func_001AB720");
extern "C" int X_func_001ABA44(...) asm("func_001ABA44");
extern "C" int X_func_001ABA98(...) asm("func_001ABA98");
extern "C" int X_func_001ABB24(...) asm("func_001ABB24");
extern "C" int X_func_001AC5B0(...) asm("func_001AC5B0");
extern "C" int X_func_001AD7D4(...) asm("func_001AD7D4");
extern "C" int X_func_001AD90C(...) asm("func_001AD90C");
extern "C" int X_func_001AD940(...) asm("func_001AD940");
extern "C" int X_func_001AD96C(...) asm("func_001AD96C");
extern "C" int X_func_001ADBD8(...) asm("func_001ADBD8");
extern "C" int X_func_001ADC0C(...) asm("func_001ADC0C");
extern "C" int X_func_001ADC6C(...) asm("func_001ADC6C");
extern "C" int X_func_001ADCD8(...) asm("func_001ADCD8");
extern "C" int X_func_001ADDD0(...) asm("func_001ADDD0");
extern "C" int X_func_001AE024(...) asm("func_001AE024");
extern "C" int X_func_001AE188(...) asm("func_001AE188");
extern "C" int X_func_001AE1BC(...) asm("func_001AE1BC");
extern "C" int X_func_001AE1E8(...) asm("func_001AE1E8");
extern "C" int X_func_001AE2D8(...) asm("func_001AE2D8");
extern "C" int X_func_001AE318(...) asm("func_001AE318");
extern "C" int X_func_001AE328(...) asm("func_001AE328");
extern "C" int X_func_001AE330(...) asm("func_001AE330");
extern "C" int X_func_001AE5BC(...) asm("func_001AE5BC");
extern "C" int X_func_001AE640(...) asm("func_001AE640");
extern "C" int X_func_001AE674(...) asm("func_001AE674");
extern "C" int X_func_001AE6A0(...) asm("func_001AE6A0");
extern "C" int X_func_001AE7F0(...) asm("func_001AE7F0");
extern "C" int X_func_001AE7F8(...) asm("func_001AE7F8");
extern "C" int X_func_001AE848(...) asm("func_001AE848");
extern "C" int X_func_001AE868(...) asm("func_001AE868");
extern "C" int X_func_001AEB7C(...) asm("func_001AEB7C");
extern "C" int X_func_001AEC50(...) asm("func_001AEC50");
extern "C" int func_001AED5C(MnuItem *);
extern "C" int X_func_001AEE50(...) asm("func_001AEE50");
extern "C" int X_func_001AF21C(...) asm("func_001AF21C");
extern "C" int X_func_001AF44C(...) asm("func_001AF44C");
extern "C" int X_func_001AF5E0(...) asm("func_001AF5E0");
extern "C" int X_func_001B1CD4(...) asm("func_001B1CD4");
extern "C" int X_func_001B2F64(...) asm("func_001B2F64");
extern "C" int X_func_001B3534(...) asm("func_001B3534");
extern "C" int X_func_001B3E20(...) asm("func_001B3E20");
extern "C" int X_func_001B3E28(...) asm("func_001B3E28");
extern "C" int X_func_001B4488(...) asm("func_001B4488");
extern "C" int X_func_001B5C20(...) asm("func_001B5C20");
extern "C" int X_func_001B64C4(...) asm("func_001B64C4");
extern "C" int X_func_001BA3A0(...) asm("func_001BA3A0");
extern "C" int X_func_001BA8E4(...) asm("func_001BA8E4");
extern "C" int X_func_001BB12C(...) asm("func_001BB12C");
extern "C" int X_func_001BB4F0(...) asm("func_001BB4F0");
extern "C" int X_func_001BBCFC(...) asm("func_001BBCFC");
extern "C" int X_func_001BC370(...) asm("func_001BC370");
extern "C" int X_func_001C5094(...) asm("func_001C5094");
extern "C" int X_func_001C5168(...) asm("func_001C5168");
extern "C" int X_func_001C51E0(...) asm("func_001C51E0");
extern "C" int X_func_001C5240(...) asm("func_001C5240");
extern "C" int X_func_001C8214(...) asm("func_001C8214");
extern "C" int X_func_001DD00C(...) asm("func_001DD00C");
extern "C" int X_func_00279C98(...) asm("func_00279C98");
extern "C" int X_setDisplay448__9MagSystem(...) asm("setDisplay448__9MagSystem");
extern "C" int X_strcpy(...) asm("strcpy");
extern "C" int X_strlen(...) asm("strlen");
extern const char D_002F9248[];
extern const char D_002F9268[];
extern const char D_002F9278[];
extern int D_002A7798;
extern int D_002A87E8;
extern int D_002ABAD8;
extern int D_002AC4E0;
extern int D_002AC788;
extern int D_002B5F38;
extern int D_002B60C0;
extern int D_006E9840;
extern int D_007812AC;
extern int D_007A34CC;
extern int D_007A34CE;
extern int D_007B205C;
extern int D_007B2060;
extern int D_007B2580;

extern "C" void func_001A90EC(MnuTitle *arg0)
{
    MnuSvld *svld = &arg0->m_svld;

    X_func_001A1244();
    X_func_001A59B8(svld);
    svld->m_isLoad = 0;
    X_func_001AB474(&arg0->m_opt);
    X_func_001A066C(&arg0->m_sub4C68);
    X_func_0018BB8C(&arg0->m_rpk);
    arg0->m_open = 0;
    X_func_001A9844(arg0);
    arg0->m_active = 0;
}


extern "C" void func_001A9150(MnuTitle *arg0, int arg1)
{
    X_func_001A9828();
    if (arg0->m_active == 1) {
        X_func_001A9258(arg0);
    }
    X_func_0018BC18(&arg0->m_rpk, 2);
    X_func_001A0684(&arg0->m_sub4C68, 2);
    X_func_001AB4E0(&arg0->m_opt, 2);
    X_func_001A5A34(&arg0->m_svld, 2);
    X_func_001A12A8(arg0, 2);
    if (arg1 & 1) {
        return Xv___builtin_delete_9150(arg0);
    }
}

extern "C" void func_001A91F4(MnuTitle *arg0, int arg1)
{
    (*(int *)&D_006FE04C) = 0;
    Xiii_func_0018BCC0((int)&arg0->m_rpk, 0xF);
    arg0->m_rpk.m_param = arg1;
    arg0->m_param = arg1;
    arg0->m_sys = _9MagSystem$m_current_system;
    Xii_func_001A97F4((int)arg0);
    arg0->m_active = 1;
}

extern "C" void func_001A9258(MnuTitle *arg0)
{
    if (arg0->m_active != 0) {
        X_func_0018C130(&arg0->m_rpk);
        X_func_001A9828(arg0);
        arg0->m_active = 0;
    }
}


extern "C" int func_001A9298(MnuTitle *arg0)
{
    return arg0->m_active;
}






































INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9820);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9830);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9840);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9850);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9860);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9870);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9880);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9888);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9898);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F98A8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F98B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F98C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F98D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F98E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F98F8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9900);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001A92A0);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001A972C);

extern "C" void func_001A97B0(MnuTitle *arg0)
{
    unsigned char *loader = arg0->m_rpk.m_loader;

    Xiiii_func_0018F744((int)loader, (int)&D_002A7798, (int) "data/mnurpk/mnutitle.rpk");
    do {

    } while (Xii_func_0018FEBC((int)loader) == 0);
}

extern "C" int func_001A97F4(MnuTitle *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_step0 = 0;
    arg0->m_mode = 0;
    arg0->m_subStep = 0;
    arg0->m_unk4DEC = 7;
    return 0;
}

extern "C" int func_001A9828(MnuTitle *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    arg0->m_open = 0;
    return 0;
}

extern "C" int func_001A9844(MnuTitle *arg0)
{
    int i = 8;
    int *p = &arg0->m_cursor[8];

    do {
        i -= 1;
        *p = 0;
        p -= 1;
    } while (i >= 0);
    arg0->m_max[1] = 5;
    arg0->m_max[0] = 3;
    arg0->m_max[2] = 2;
    return 0;
}

extern "C" void func_001A988C(MnuTitle *arg0)
{
    MnuRpk *rpk = &arg0->m_rpk;

    arg0->m_sys = _9MagSystem$m_current_system;
    rpk->m_tbl = &D_002A7858;
    Xiii_func_0018C190((int)rpk, (int)&D_002A80C0);
    rpk->m_unk04 = 1;
}

extern "C" int func_001A98DC(MnuTitle *arg0)
{
    X_func_0018C068(&arg0->m_rpk);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001A98FC);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AA248);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AA7D0);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AABB4);

extern "C" int func_001AAED0(MnuTitle *arg0)
{
    register MnuTitle *self PS2_REG("$16") = arg0;
    int ret = 0;

    switch (self->m_subStep) {
    case 0:
        self->m_cursor[3] = 0;
        self->m_unk4DB8 = 0;
        X_func_001A5AF4(&self->m_svld, self->m_param);
        self->m_subStep = 1;
    case 1:
        self->m_subStep = 0xF;
        break;
    case 0xF: {
        MnuSvld *p = &self->m_svld;
        if (X_func_001A5CC4(p) != 0) {
            ret = (p->m_result == 0) ? 1 : 2;
            X_func_001A5BF4(p);
            self->m_subStep = 0;
        }
        break;
    }
    }
    return ret;
}

extern "C" int func_001AAF98(MnuTitle *arg0)
{
    int ret = 0;

    switch (arg0->m_subStep) {
    case 0:
        arg0->m_cursor[4] = 0;
        arg0->m_unk4DB8 = 0;
        X_func_001AB598(&arg0->m_opt, arg0->m_param);
        arg0->m_subStep = 1;
    case 1:
        arg0->m_subStep = 0xF;
        break;
    case 0xF: {
        MnuOpt *p = &arg0->m_opt;
        if (X_func_001AB66C(p) != 0) {
            ret = 1;
            X_func_001AB5E4(p);
            arg0->m_subStep = 0;
        }
        break;
    }
    }
    return ret;
}

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9BE8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9C40);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9C58);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9C70);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9C88);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9CA0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9CB8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9CD0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9D28);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9D40);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9D58);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9D70);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9D88);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9DA0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9DF8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9E10);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9E28);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9E40);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9E58);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9E70);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9EC8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9EE0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9EF8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9F10);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9F28);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9F40);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9F98);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9FB0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9FC8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9FE0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002F9FF8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA010);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA068);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA080);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA098);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA0B0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA0C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA0E0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA138);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA150);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA168);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA180);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA198);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA1B0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA1D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA1F0);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AB04C);

extern "C" void func_001AB474(MnuOpt *arg0)
{
    int i = 1;
    MnuMsgWin *w = arg0->m_msgWin;

    do {
        MnuMsgWin *cur = w;
        w += 1;
        X_func_0018330C(cur);
        i -= 1;
    } while (i != -1);
    X_func_0018BB8C(&arg0->m_rpk);
    arg0->m_open = 0;
    X_func_001ABA44(arg0);
    arg0->m_active = 0;
}


ObjAB4E0::~ObjAB4E0()
{
    Xvp_func_001AB6F4(this);
    if (m_10CC == 1) {
        Xvp_func_001AB5E4(this);
    }
}

extern "C" void func_001AB598(MnuOpt *arg0, int arg1)
{
    X_func_0018BCC0(&arg0->m_rpk, 0x41);
    arg0->m_rpk.m_param = arg1;
    X_func_001AB6AC(arg0);
    arg0->m_active = 1;
}


extern "C" void func_001AB5E4(MnuOpt *arg0)
{
    int temp_s0;

    if (arg0->m_active != 0) {
        X_func_0018C130(&arg0->m_rpk);
        temp_s0 = (int)&D_006E9840;
        temp_s0 += 0x12540;
        X_func_00135594(temp_s0, arg0->m_winId);
        X_func_001348B0(temp_s0, arg0->m_winId);
        X_func_00187464(&arg0->m_msgWin[0]);
        X_func_001AB6F4(arg0);
        arg0->m_active = 0;
    }
}

extern "C" int func_001AB65C(MnuOpt *arg0)
{
    return arg0->m_active;
}


extern "C" void func_001AB664(void) {
}

extern "C" int func_001AB66C()
{
    return X_func_001AB720();
}


extern "C" void func_001AB680(MnuOpt *arg0, int arg1)
{
    MnuRpk *rpk = &arg0->m_rpk;

    arg0->m_renderCtx = arg1;
    if (arg1 != 0) {
        rpk->m_renderCtx = arg1;
        X_func_0018BD94(rpk);
    }
}


extern "C" int func_001AB6AC(MnuOpt *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_unk54 = 1;
    arg0->m_step0 = 0;
    arg0->m_mode = 0;
    arg0->m_subStep = 0;
    Xii_func_0018741C((int)&arg0->m_msgWin[0]);
    return 0;
}

extern "C" int func_001AB6F4(MnuOpt *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    arg0->m_open = 0;
    return 0;
}

extern "C" int func_001AB710()
{
    return 0;
}


extern "C" int func_001AB718()
{
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA280);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA290);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA2A0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA2B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA2C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA2D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA2E8);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AB720);

extern "C" int func_001ABA44(MnuOpt *arg0)
{
    for (int i = 0; i < 8; i++) {
        arg0->m_cursor[i] = 0;
    }
    arg0->m_max[0] = 6;
    arg0->m_max[1] = 2;
    arg0->m_max[2] = 9;
    arg0->m_max[3] = 9;
    arg0->m_max[4] = 9;
    arg0->m_max[6] = 2;
    arg0->m_max[5] = 9;
    return 0;
}

extern "C" void func_001ABA98(MnuOpt *arg0)
{
    int one = 1;
    int five = 5;
    MnuRpk *rpk = &arg0->m_rpk;
    arg0->m_sys = _9MagSystem$m_current_system;
    rpk->m_tbl = &D_002A8848;
    X_func_0018C190_1((int)rpk, (int)&D_002AAD70);
    arg0->m_cursor[0] = 0;
    arg0->m_cursor[2] = five;
    arg0->m_cursor[3] = five;
    arg0->m_cursor[4] = five;
    arg0->m_cursor[5] = five;
    arg0->m_cursor[6] = 0;
    arg0->m_cursor[1] = 0;
    rpk->m_unk04 = one;
}

extern "C" int func_001ABB24(MnuOpt *arg0)
{
    X_func_0018C068(&arg0->m_rpk);
    X_func_001874AC(&arg0->m_msgWin[0]);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001ABB58);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AC5B0);

extern "C" void func_001AD6B4(MnuBoard *arg0)
{
    int i = 1;
    MnuMsgWin *w = arg0->m_msgWin;

    do {
        MnuMsgWin *cur = w;
        w += 1;
        X_func_0018330C(cur);
        i -= 1;
    } while (i != -1);
    X_func_0018BB8C(&arg0->m_rpk);
    arg0->m_open = 0;
    arg0->m_unk10B8 = 0x40001;
    X_func_001ADBD8(arg0);
    arg0->m_active = 0;
}


ObjAD72C::~ObjAD72C()
{
    Xvp_func_001AD940(this);
    if (m_10B4 == 1) {
        Xvp_func_001AD870(this);
    }
    Xvp_func_0018BC18((char *)this + 0x7A4, 2);
}

extern "C" int func_001AD7D4(int arg0)
{
    for (int i = 0; X_D_002ABDB8[i].m_key != -1; i++) {
        if (arg0 == X_D_002ABDB8[i].m_key) {
            return X_D_002ABDB8[i].m_val;
        }
    }
    return 0;
}

extern "C" void func_001AD824(MnuBoard *arg0, int arg1)
{
    X_func_0018BCC0(&arg0->m_rpk, 3);
    arg0->m_rpk.m_param = arg1;
    X_func_001AD90C(arg0);
    arg0->m_active = 1;
}


extern "C" void func_001AD870(MnuBoard *arg0)
{
    if (arg0->m_active != 0) {
        if (arg0->m_skipClose == 0) {
            X_func_0018C130(&arg0->m_rpk);
        }
        X_func_001AD940(arg0);
        arg0->m_active = 0;
    }
}


extern "C" int func_001AD8BC(MnuBoard *arg0)
{
    return arg0->m_active;
}


extern "C" void func_001AD8C4(void) {
}

extern "C" int func_001AD8CC()
{
    return X_func_001AD96C();
}


extern "C" void func_001AD8E0(MnuBoard *arg0, int arg1)
{
    MnuRpk *rpk = &arg0->m_rpk;

    arg0->m_renderCtx = arg1;
    if (arg1 != 0) {
        rpk->m_renderCtx = arg1;
        X_func_0018BD94(rpk);
    }
}


extern "C" int func_001AD90C(MnuBoard *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_step0 = 0;
    arg0->m_mode = 0;
    arg0->m_subStep = 0;
    arg0->m_unk7A0 = 2;
    return 0;
}

extern "C" int func_001AD940(MnuBoard *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    arg0->m_open = 0;
    return 0;
}

extern "C" int func_001AD95C()
{
    return 0;
}


extern "C" int func_001AD964()
{
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA3C0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA3D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA3D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA3E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA3F0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA3F8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA408);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA410);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA418);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA420);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA428);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA438);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA448);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA458);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA460);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA470);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA478);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA480);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA488);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA490);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA498);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA4A0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA4A8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA4B0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA4B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA4C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA4D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA4E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA4F8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA500);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA510);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA520);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA530);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA540);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA548);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA550);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA558);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA560);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA568);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA570);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA580);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA590);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5A0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5B0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5C0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5E0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5F0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA5F8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA608);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA618);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA628);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA638);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA648);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA658);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA668);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA678);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA688);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA690);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6A0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6B0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6C0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6E0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6F0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA6F8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA700);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA708);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA710);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA718);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA720);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA728);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA730);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA738);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA740);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA748);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA750);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA758);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA760);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA768);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA770);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA778);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA780);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA788);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA790);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA798);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7A0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7A8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7B0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7C0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7E0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7F0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA7F8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA800);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA808);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA810);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA818);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA820);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA828);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA830);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA838);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA840);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA848);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA850);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA858);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA860);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA868);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA870);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA878);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA880);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA888);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA890);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA898);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8A0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8A8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8B0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8C0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8E0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8F0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA8F8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA900);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA908);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA910);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA918);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA920);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA928);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA930);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA938);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA940);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA948);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA950);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA958);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA960);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA968);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA970);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA978);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA980);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA988);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA990);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA998);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9A0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9A8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9B0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9B8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9C0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9C8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9D0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9D8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9E8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FA9F8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA00);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA08);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA10);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA18);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA20);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA28);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA30);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA38);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA40);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA48);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA50);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA58);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA60);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA68);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA70);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA78);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA80);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA88);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA90);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAA98);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAA0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAA8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAB0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAB8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAC0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAC8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAD0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAD8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAE0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAE8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAF0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAAF8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB00);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB08);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB10);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB18);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB20);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB28);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB30);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB38);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB40);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB48);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB50);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB58);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB60);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB68);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB70);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB78);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB80);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB88);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB90);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAB98);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABA0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABA8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABB0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABB8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABC0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABC8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABD0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABD8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABE0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABE8);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FABF0);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AD96C);

extern "C" int func_001ADBD8(MnuBoard *arg0)
{
    for (int i = 0; i < 2; i++) {
        arg0->m_cursor[i] = 0;
    }
    arg0->m_max0 = 1;
    return 0;
}

extern "C" void func_001ADC0C(MnuBoard *arg0)
{
    MnuRpk *rpk = &arg0->m_rpk;

    arg0->m_sys = _9MagSystem$m_current_system;
    rpk->m_tbl = &D_002ABB08;
    Xiii_func_0018C190((int)rpk, (int)&D_002ABCE8);
    arg0->m_cursor[0] = 0;
    rpk->m_unk04 = 1;
}

extern "C" int func_001ADC6C(MnuBoard *arg0)
{
    int *p;
    bool ok;

    X_func_0018C068(&arg0->m_rpk);
    ok = !(X_func_00131550(arg0->m_sys + 0x12540) < 5);
    if (ok == 1) {
        p = (int *)(*(int *)&D_007B2060 + 4);
        *p = *p | 0x40000000;
    }
    return 0;
}

// NON_MATCHING: 19/62 differ, 4 relocs differ, 20 edits
#ifdef NON_MATCHING
extern "C" int func_00131550(void *);
extern "C" int func_0017F8FC(void *, int);
extern "C" int func_001ADCD8(MnuBoard *arg0)
{
    int ret = 0;
    switch (arg0->m_subStep) {
    case 0:
        arg0->m_subStep = 1;
        arg0->m_unk1098 = 0;
    case 1:
        arg0->m_subStep = 3;
        break;
    case 4: {
        bool ok = !(func_00131550((char *)arg0->m_sys + 0x12540) < 5);
        if (ok == 1) {
            arg0->m_subStep = 0;
            ret = arg0->m_unk1098;
        }
        return ret;
    }
    case 3:
    default:
        break;
    }
    if (!(*(int *)(*(char **)&D_007B2060 + 4) & 0x80)) {
        arg0->m_subStep = 4;
        arg0->m_unk1098 = 1;
        func_0017F8FC(&D_007B2580, 4);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001ADCD8);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001ADDD0);

extern "C" void func_001ADF04(MnuMovie *arg0)
{
    X_func_0018BB8C(&arg0->m_rpk);
    arg0->m_open = 0;
    X_func_001AE2D8(arg0);
    arg0->m_active = 0;
}


extern "C" void func_001ADF3C(MnuMovie *arg0, int arg1)
{
    X_func_001AE1BC(arg0);
    if (arg0->m_active == 1) {
        Xv_func_001ADFE4((int)arg0);
    }
    Xii_func_0018BC18((int)&arg0->m_rpk, 2);
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void func_001ADFB0(MnuMovie *arg0)
{
    X_func_001AE188();
    X_func_001AE024(arg0);
    arg0->m_active = 1;
}


extern "C" void func_001ADFE4(MnuMovie *arg0)
{
    if (arg0->m_active != 0) {
        X_func_001AE1BC();
        arg0->m_active = 0;
    }
}


extern "C" int func_001AE01C(MnuMovie *arg0)
{
    return arg0->m_active;
}


extern "C" void func_001AE024(void) {
}

extern "C" int func_001AE02C()
{
    return X_func_001AE1E8();
}


INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AE040);

extern "C" int func_001AE188(MnuMovie *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_step0 = 0;
    arg0->m_mode = 0;
    arg0->m_subStep = 0;
    arg0->m_unk50 = 2;
    return 0;
}

extern "C" int func_001AE1BC(MnuMovie *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    arg0->m_open = 0;
    return 0;
}

extern "C" int func_001AE1D8()
{
    return 0;
}


extern "C" int func_001AE1E0()
{
    return 0;
}


INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAC50);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAC58);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AE1E8);

extern "C" int func_001AE2D8(MnuMovie *arg0)
{
    for (int i = 0; i < 7; i++) {
        arg0->m_cursor[i] = 0;
    }
    arg0->m_max[0] = 5;
    arg0->m_max[1] = 2;
    arg0->m_max[2] = 2;
    return 0;
}

extern "C" void func_001AE318(MnuMovie *arg0)
{
    arg0->m_sys = _9MagSystem$m_current_system;
}

extern "C" int func_001AE328()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AE330);

extern "C" void func_001AE474(MnuNow *arg0)
{
    X_func_0018BB8C(&arg0->m_rpk);
    arg0->m_open = 0;
    X_func_001AE7F0(arg0);
    arg0->m_active = 0;
}


extern "C" void func_001AE4AC(MnuNow *arg0, int arg1)
{
    X_func_001AE674(arg0);
    if (arg0->m_active == 1) {
        Xv_func_001AE574((int)arg0);
    }
    Xii_func_0018BC18((int)&arg0->m_rpk, 2);
    if (arg1 & 1) {
        return Xv___builtin_delete(arg0);
    }
}

extern "C" void func_001AE520(MnuNow *arg0, int arg1)
{
    X_func_0018BCC0(&arg0->m_rpk, 2);
    arg0->m_rpk.m_param = arg1;
    X_func_001AE640(arg0);
    X_func_001AE5BC(arg0);
    arg0->m_active = 1;
}


extern "C" void func_001AE574(MnuNow *arg0)
{
    if (arg0->m_active != 0) {
        X_func_0018C130(&arg0->m_rpk);
        X_func_001AE674(arg0);
        arg0->m_active = 0;
    }
}


extern "C" int func_001AE5B4(MnuNow *arg0)
{
    return arg0->m_active;
}


INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAC90);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FACA0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FACB0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FACB8);

extern "C" void func_001AE5BC(MnuNow *arg0)
{
    unsigned char *loader = arg0->m_rpk.m_loader;

    Xiiii_func_0018F744((int)loader, (int)&D_002AC788, (int) "data/mnurpk/mnunow.rpk");
    do {

    } while (Xii_func_0018FEBC((int)loader) == 0);
}

extern "C" int func_001AE600()
{
    return X_func_001AE6A0();
}


extern "C" void func_001AE614(MnuNow *arg0, int arg1)
{
    MnuRpk *rpk = &arg0->m_rpk;

    arg0->m_renderCtx = arg1;
    if (arg1 != 0) {
        rpk->m_renderCtx = arg1;
        X_func_0018BD94(rpk);
    }
}


extern "C" int func_001AE640(MnuNow *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_step0 = 0;
    arg0->m_mode = 0;
    arg0->m_subStep = 0;
    arg0->m_unk10 = 2;
    return 0;
}

extern "C" int func_001AE674(MnuNow *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    arg0->m_open = 0;
    return 0;
}

extern "C" int func_001AE690()
{
    return 0;
}


extern "C" int func_001AE698()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AE6A0);

extern "C" int func_001AE7F0()
{
    return 0;
}


extern "C" void func_001AE7F8(MnuNow *arg0)
{
    MnuRpk *rpk = &arg0->m_rpk;

    arg0->m_sys = _9MagSystem$m_current_system;
    rpk->m_tbl = &D_002AC7B8;
    Xiii_func_0018C190((int)rpk, (int)&D_002AC980);
    rpk->m_unk04 = 1;
}

extern "C" int func_001AE848(MnuNow *arg0)
{
    X_func_0018C068(&arg0->m_rpk);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AE868);

extern "C" void func_001AE954(MnuItem *arg0)
{
    int i = 1;
    MnuMsgWin *w;

    Xii_func_0018BB8C((int)&arg0->m_rpk[0]);
    w = arg0->m_msgWin;
    Xii_func_0018BB8C((int)&arg0->m_rpk[1]);
    Xii_func_0018BB8C((int)&arg0->m_rpk[2]);
    Xii_func_001A066C((int)&arg0->m_sub1B64);
    do {
        MnuMsgWin *cur = w;
        w += 1;
        Xii_func_0018330C((int)cur);
        i -= 1;
    } while (i != -1);
    arg0->m_open = 0;
    Xii_func_001AEB7C((int)arg0);
    arg0->m_active = 0;
    arg0->m_weaponId = 0xA00;
    arg0->m_subItemId = 0xA23;
    arg0->m_unk2490 = 0;
    arg0->m_unk249C = 0;
    arg0->m_unk24A0 = 0;
}

ObjAE9F4::~ObjAE9F4()
{
    if (m_2480 == 1) {
        Xvp_func_001AEBC8(this);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAD20);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAD30);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAD40);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAD50);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAD60);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAD70);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAD80);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAD90);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FADA0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FADB0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FADC0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FADD0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FADE0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FADF0);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAE00);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAE10);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAE20);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAE30);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAE40);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAE48);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAE58);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAE68);

extern "C" void func_001AEACC(MnuItem *arg0, int arg1)
{
    const char *font;
    MnuRpk *rpk = &arg0->m_rpk[0];

    if (arg0->m_active == 0) {
        arg0->m_param = arg1;
        arg0->m_unk24A0 = 0;
        arg0->m_unk2490 = 0;
        arg0->m_unk249C = 0;
        X_func_0018BCC0(rpk, 0x78);
        rpk->m_unk8E8 = 1;
        arg0->m_rpk[0].m_param = arg1;
        font = "fnt16US.bin";
        func_001AED5C(arg0);
        X_func_001AEC50(arg0);
        rpk->m_unk8E8 = 1;
        X_func_0018C2E4(rpk, font, 0);
        X_func_0018C2E4(rpk, font, 1);
        arg0->m_active = 1;
    }
}

extern "C" void func_001AEB7C(MnuItem *arg0)
{
    arg0->m_canDog2 = 1;
    arg0->m_canDog = 1;
    arg0->m_canOpt2 = 1;
    arg0->m_canOpt = 1;
    for (int i = 0; i < 10; i++) {
        arg0->m_cursor[i] = 0;
    }
    arg0->m_max[0] = 4;
    arg0->m_max[1] = 2;
    arg0->m_max[2] = 2;
}

extern "C" void func_001AEBC8(MnuItem *arg0)
{
    int temp_s0;

    if (arg0->m_active != 0) {
        arg0->m_unk2490 = 0;
        arg0->m_unk249C = 0;
        X_func_0018C130(&arg0->m_rpk[0]);
        char *base = (char *)&D_006E9840;
        temp_s0 = (int)(base + 0x12540);
        X_func_00135594(temp_s0, arg0->m_winId);
        X_func_001348B0(temp_s0, arg0->m_winId);
        X_func_00187464(&arg0->m_msgWin[0]);
        X_func_001AEE50(arg0);
        arg0->m_active = 0;
    }
}

extern "C" int func_001AEC48(MnuItem *arg0)
{
    return arg0->m_active;
}


extern "C" void func_001AEC50(MnuItem *arg0)
{
    int lang = D_007812AC;
    int i;
    void *p;

    for (i = 0; X_D_002ACA20[i].m_id != -1; i++) {
        if (X_D_002ACA20[i].m_id == 1) {
            if (lang != 0) {
                if (lang >= 0) {
                    if (lang < 5) {
                        X_D_002ACA20[i].m_name = "tex01_eu.tm2";
                    }
                }
            }
            break;
        }
    }
    p = arg0->m_rpk[0].m_loader;
    Xvp_func_0018F744(p, X_D_002ACA20, "data/mnurpk/mnuitem.rpk");
    while (Xvp_func_0018FEBC(p) == 0) {
    }
}

extern "C" void func_001AED08(MnuItem *arg0, int arg1)
{
    MnuRpk *rpk2 = &arg0->m_rpk[2];

    if (arg1 != 0) {
        rpk2->m_renderCtx = arg1;
        X_func_0018BD94(rpk2);
        MnuRpk *rpk1 = &arg0->m_rpk[1];
        rpk1->m_renderCtx = arg1;
        X_func_0018BD94(rpk1);
        MnuRpk *rpk0 = &arg0->m_rpk[0];
        rpk0->m_renderCtx = arg1;
        X_func_0018BD94(rpk0);
    }
}


extern "C" int func_001AED5C(MnuItem *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_equipIdx = -1;
    arg0->m_weaponIdx = -1;
    arg0->m_unk54 = 0;
    arg0->m_unk58 = 0;
    arg0->m_unk5C = 0;
    arg0->m_unk24A0 = 0;
    func_001AF024(arg0);
    arg0->m_unk23F4 = 100;
    arg0->m_unk23FC = 70;
    arg0->m_unk2404 = 30;
    arg0->m_unk23F8 = 100;
    arg0->m_unk2400 = 70;
    arg0->m_unk2408 = 30;
    if (D_007812C0.m_cursolInitFlgItem != 0) {
        for (int i = 0; i < 10; i++) {
            arg0->m_cursor[i] = 0;
        }
        D_007812C0.m_cursolInitFlgItem = 0;
    }
    arg0->m_cursor[0] = 2;
    arg0->m_subItemId = 0xA23;
    arg0->m_weaponId = 0xA00;
    arg0->m_cursor[3] = 0;
    arg0->m_unk246C = 0;
    arg0->m_unk2470 = 0;
    arg0->m_unk2474 = 0;
    arg0->m_unk2420 = 0;
    func_0018741C(&arg0->m_msgWin[0]);
    return 0;
}

extern "C" int func_001AEE50(MnuItem *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    Xiii_func_001AF44C((int)arg0, 1);
    arg0->m_open = 0;
    return 0;
}

extern "C" void func_001AEE8C(MnuItem *arg0)
{
    for (int i = 0; X_D_002ACA20[i].m_id != -1; i++) {
        X_func_0018FBB0(arg0->m_rpk[0].m_loader, X_D_002ACA20[i].m_id);
    }
}

extern "C" void func_001AEF14(MnuItem *arg0)
{
    for (int i = 0; X_D_002ACA20[i].m_id != -1; i++) {
        X_func_0018F9CC(arg0->m_rpk[0].m_loader, X_D_002ACA20[i].m_id);
    }
}

extern "C" void func_001AEF9C(MnuItem *arg0)
{
    for (int i = 0; X_D_002ACA20[i].m_id != -1; i++) {
        X_func_0018FAB4(arg0->m_rpk[0].m_loader, X_D_002ACA20[i].m_id);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AF024);

extern "C" void func_001AF130(MnuItem *arg0)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    int one = 1;

    temp_v0 = sysFlags_F130()[1] & one;
    if (temp_v0 == one) {
        arg0->m_canDog2 = one;
        arg0->m_canDog = one;
    } else {
        arg0->m_canDog2 = 0;
        arg0->m_canDog = 0;
    }
    if (D_007A3210 == 7) {
        arg0->m_canDog = 0;
    }
    temp_v0_2 = sysFlags_F130()[1] & 2;
    if (temp_v0_2 != 0) {
        int temp_v1 = temp_v0_2 != 0;
        arg0->m_canOpt2 = temp_v1;
        arg0->m_canOpt = temp_v1;
    } else {
        arg0->m_canOpt2 = 0;
        arg0->m_canOpt = 0;
    }
    temp_v0_3 = sysFlags_F130()[1] & 4;
    arg0->m_canMap = (temp_v0_3 != 0);
}

extern "C" int func_001AF1D4()
{
    char *base = (char *)&D_007812C0;
    int temp_a2;
    int var_a1;
    unsigned short temp_v0;
    int var_a0;

    int *p = (int *)(base + 0x1A6C0);
    var_a0 = p[0];
    temp_a2 = p[1];
    var_a1 = 0;
    if (var_a0 != temp_a2) {
        do {
            temp_v0 = M2C_FIELD(var_a0, unsigned short *, 8);
            var_a0 += 0x10;
            if ((temp_v0 ^ 0xA00) != 0) {
                var_a1 += 1;
            }
        } while (var_a0 != temp_a2);
    }
    return var_a1;
}

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AF21C);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AF3F0);

extern "C" void func_001AF44C(MnuItem *arg0, int arg1)
{
    if (arg1 == 0) {
        X_func_001AF024();
        X_func_001AF21C(arg0, -1);
        char *base = (char *)&D_007812C0;
        arg0->m_equipIdx = X_func_001AF3F0(arg0, M2C_FIELD(base, unsigned short *, 0x2220C));
        arg0->m_weaponId = (int) M2C_FIELD(base, unsigned short *, 0x2220E);
        arg0->m_weaponIdx = X_func_001AF3F0(arg0, M2C_FIELD(base, unsigned short *, 0x2220E));
    }
}

extern "C" int func_001AF4D0(int arg0, int arg1)
{
    switch (arg1) {                                 
    case 0xB3B:
        
    case 0xA00:
        return (int)&D_002B5F38;
    default:
        return (int)&D_002B60C0;
    }
}


extern "C" int func_001AF4FC(int arg0, int arg1)
{
    struct { unsigned short sp0; } stack;
    int temp_v0;

    if ((arg1 == 0xA00) || (arg1 == 0xB3B)) {
        return 0;
    }
    char *base = (char *)&D_007812C0;
    X_func_001DC48C((int)(base + 0x22220), arg1 & 0xFFFF, 0xD, (int)&stack);
    if (stack.sp0 != 0) {
        stack.sp0 += 0xFFFF;
    }
    temp_v0 = (stack.sp0 * 4) + 0xD0;
    return (temp_v0 >= 0x2B2) ? 0xD0 : temp_v0;
}

extern "C" void func_001AF578(MnuItem *arg0, int arg1)
{
    MnuItemStockEnt *ent = arg0->m_slots[arg1];
    if (ent->m_count > 1) {
        ent->m_count--;
    } else {
        X_func_001C8214(&D_007812C0, arg1);
    }
    X_func_001AF21C(arg0, -1);
    X_func_001AF5E0(arg0);
}

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AF5E0);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AF928);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001AFF5C);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B05EC);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B070C);

INCLUDE_RODATA("asm/nonmatchings/unk/001A6830", D_002FAEB0);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B0784);

extern "C" int func_001B0908(MnuItem *arg0, int arg1)
{
    if (arg1 >= 12) {
        return 0;
    }
    unsigned short id = arg0->m_slots[arg1]->m_itemId;
    if (id == 0xA00) {
        return 0;
    }
    return id == *(unsigned short *)&D_007A34CC;
}

extern "C" int func_001B0948(MnuItem *arg0, int arg1)
{
    unsigned short temp_v1;

    if (arg1 == 0xD) {
        return arg0->m_weaponId == (*(unsigned short *)&D_007A34CE);
    }
    temp_v1 = arg0->m_slots[arg1]->m_itemId;
    if (temp_v1 == 0xA00) {
        return 0;
    }
    return temp_v1 == (*(unsigned short *)&D_007A34CE);
}

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B099C);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B113C);

extern "C" int func_001B1B34(MnuItem *arg0, int arg1)
{
    if (arg1 < 0) {
        return 0xA00;
    }
    if (arg1 < 0xC) {
        return arg0->m_slots[arg1]->m_itemId;
    }
    if (arg1 == 0xC) {
        return arg0->m_subItemId;
    }
    if (arg1 == 0xD) {
        return arg0->m_weaponId;
    }
    return 0xA00;
}

extern "C" int func_001B1B80()
{
    int bit = M2C_FIELD((*(int *)&D_007B2060), int *, 4) & 0x20;

    return bit != 0;
}

extern "C" int func_001B1B98()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B1BA0);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B1CD4);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B2F64);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B3534);

extern "C" int func_001B3E20()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B3E28);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B4488);

INCLUDE_ASM("asm/nonmatchings/unk/001A6830", func_001B5C20);
