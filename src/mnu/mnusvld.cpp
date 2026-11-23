#include "include_asm.h"
#include "mnu/mnusvld.h"
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" void func_001A5BF4(MnuSvld *);
extern "C" void func_001A5C80(MnuSvld *);
extern "C" int func_001A5D04(MnuSvld *);
extern "C" int func_001A5D74(MnuSvld *);
extern "C" int func_001A65F0(MnuSvld *);
extern "C" void func_001A6BF8(MnuSvld *);
extern "C" int Xii_func_001A6BF8(int) asm("func_001A6BF8");
extern "C" void X_func_001A6C90_6FE8(MnuSvld *, int, int) asm("func_001A6C90");
extern "C" void func_001A6FE8(MnuSvld *);
extern "C" void Xiii_func_0018C190(void *, void *) asm("func_0018C190");
extern "C" int Xiiii_func_0018C4D8(int, int, int) asm("func_0018C4D8");
extern "C" void X_func_0018C6C4_7418(void *, int, int) asm("func_0018C6C4");
extern "C" void Xiiii_func_001A4E34(void *, void *, int) asm("func_001A4E34");
extern "C" int Xiiiii_func_001A4DB8(void *, void *, int, int) asm("func_001A4DB8");
extern "C" int Xiii_func_001A5584(void *, int) asm("func_001A5584");
extern "C" void Xvii_func_001A557C(void *, int) asm("func_001A557C");
extern "C" void *X_alloc__9BedMemoryiPCciii(void *, int, const char *, int, int, int) asm("alloc__9BedMemoryiPCciii");
extern "C" int X_func_00131550(void *) asm("func_00131550");
extern "C" void X_func_001348B0(void *, int) asm("func_001348B0");
extern "C" void X_func_00135088(void *, int, int, int, int) asm("func_00135088");
extern "C" void X_func_0013511C(void *, int, int, int, int) asm("func_0013511C");
extern "C" void X_func_001351B0(void *, int, int) asm("func_001351B0");
extern "C" void X_func_00135594(void *, int) asm("func_00135594");
extern "C" void X_func_0017F8FC(void *, int) asm("func_0017F8FC");
extern "C" void X_func_0018741C(void *) asm("func_0018741C");
extern "C" void X_func_00187464(void *) asm("func_00187464");
extern "C" void X_func_001874AC(void *) asm("func_001874AC");
extern "C" void X_func_0018BCC0(void *, int) asm("func_0018BCC0");
extern "C" void X_func_0018BD94(void *) asm("func_0018BD94");
extern "C" void X_func_0018C068(void *) asm("func_0018C068");
extern "C" void X_func_0018C130(void *) asm("func_0018C130");
extern "C" void X_func_0018C2E4(void *, const char *, int) asm("func_0018C2E4");
extern "C" void X_func_0018F744(void *, void *, const char *) asm("func_0018F744");
extern "C" int X_func_0018FEBC(void *) asm("func_0018FEBC");
extern "C" void X_func_001A1514(void *, void *) asm("func_001A1514");
extern "C" int X_func_001A5ED0(...) asm("func_001A5ED0");
extern "C" void X_func_001C5094(void *, int, int, int) asm("func_001C5094");
extern "C" void X_func_001C51E0(void *, int, int) asm("func_001C51E0");
extern "C" void X_func_001C5240(void *, int, int) asm("func_001C5240");
extern "C" void X_func_001D6078(void *, void *) asm("func_001D6078");
extern "C" void X_func_001D68A0(void *, void *) asm("func_001D68A0");
extern "C" void X_func_002155F4(const char *, int, const char *) asm("func_002155F4");
extern "C" void X_heapFree__FPv(void *) asm("heapFree__FPv");
extern "C" void *X_memset(void *, int, int) asm("memset");
extern "C" int X_func_00279C98(char *, const char *, ...) asm("func_00279C98");
extern "C" int Xvp_snprintf(void *, int, const char *, ...) asm("snprintf");
extern "C" char *Xvp_strcpy(char *, const char *) asm("strcpy");
extern "C" unsigned int Xvp_strlen(const char *) asm("strlen");
extern int D_002A4530;
extern int D_002A45C0;
extern int D_002A64E0;
extern int _9MagSystem$m_current_system;
extern const char D_002F91E8[];
extern const char D_002F91F8[];
extern const char D_002F9248[];
extern const char D_002F9268[];
extern const char D_002F9278[];
extern int D_002F9428;
extern int D_002F9430;
extern int D_006E9800;
extern int D_006E9840;
extern int D_007812C0;
extern int D_007B2060;
extern int D_007B2580;

static inline unsigned int padTrigU_F40(int p) { return *(unsigned short *)((char *)p + 0x7A); }

// func_001A4E88 .. func_001A4FF0 were game/mnudlg's: config/splits_manual.tsv
extern "C" int func_001A4E88(MnuDlg *arg0, int arg1)
{
    int ret = 0;

    if (arg0->m_open == 0) {
        return -1;
    }
    switch (arg0->m_step) {
    case 0:
        arg0->m_step = 1;
        break;
    case 1:
        arg0->m_step = 2;
        break;
    case 2:
        if (arg0->m_mode == 0) {
            int r = Xiii_func_001A5584(arg0, arg1);
            if (r == 0) {
            } else if (r == 1) {
                arg0->m_step = 4;
            }
        }
        Xvii_func_001A557C(arg0, arg1);
        break;
    case 4:
        arg0->m_step = 5;
    case 3:
    case 5:
    default:
        ret = 1;
        break;
    }
    return ret;
}

extern "C" int func_001A4F60(MnuDlg *arg0)
{
    int i;

    arg0->m_winId = -1;
    for (i = 0; i < 7; i++) {
        arg0->m_cursor[i] = 0;
    }
    arg0->m_active = 0;
    arg0->m_max[1] = 2;
    arg0->m_max[2] = 2;
    arg0->m_max[0] = 1;
    for (i = 0; i < 16; i++) {
        arg0->m_titleLines[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        arg0->m_bodyLines[i] = 0;
    }
    return 0;
}

extern "C" void func_001A4FF0(MnuDlg *arg0)
{
    Xiiiii_func_001A4DB8(arg0, arg0->m_titleLines, 0x10, 0x100);
    Xiiiii_func_001A4DB8(arg0, arg0->m_bodyLines, 0x10, 0x100);
}

extern "C" void func_001A5034(MnuDlg *arg0)
{
    Xiiii_func_001A4E34(arg0, arg0->m_titleLines, 0x10);
    Xiiii_func_001A4E34(arg0, arg0->m_bodyLines, 0x10);
}

// NON_MATCHING: 178/180 differ, 20 relocs differ (size 0x2D0, game 0x2F8), 208 edits
#ifdef NON_MATCHING
extern "C" int Xii_strlen(int) asm("strlen");
extern "C" int X5070_strcpy(int, int) asm("strcpy");
extern "C" int Xiii_strstr(int, int) asm("strstr");
extern "C" int Xiiii_strncpy(int, int, int) asm("strncpy");
extern const char D_002F9118[];
extern const char D_002F9120[];
extern "C" char *S5070_find(const char *, const char *) asm("strstr");
extern "C" unsigned int S5070_len(const char *) asm("strlen");
extern "C" char *S5070_copy(char *, const char *) asm("strcpy");
extern "C" char *S5070_ncopy(char *, const char *, unsigned int) asm("strncpy");
extern "C" void func_001A5070(int arg0, char *arg1, char *arg2, int arg3, int arg4, int arg5, int arg6)
{
    if (M2C_FIELD(arg0, int *, 0) && M2C_FIELD(arg0, int *, 0x7D8) != 1) {
        M2C_FIELD(arg0, int *, 0x7D8) = 1;
        M2C_FIELD(arg0, int *, 0x7D4) = -1;
        M2C_FIELD(arg0, int *, 0x7DC) = arg3;
        M2C_FIELD(arg0, int *, 0x7E0) = arg4;
        M2C_FIELD(arg0, int *, 0x7E4) = arg5;
        M2C_FIELD(arg0, int *, 0x7E8) = arg6;
        { char *p = arg1; char **slots = (char **)(arg0 + 0x7F4); int n = 0;
        while (*p) {
            char *a = S5070_find(p, D_002F9118);
            char *b = S5070_find(p, D_002F9120);
            if (!a) {
                if (!b) {
                    if (S5070_len(p)) S5070_copy(slots[n++], p);
                } else {
                    int length = b - p;
                    char **slot = &slots[n++];
                    S5070_ncopy(*slot, p, length);
                    (*slot)[length] = 0;
                }
                break;
            } else {
                int length = a - p;
                char **slot = &slots[n++];
                if (!b) {
                    S5070_ncopy(*slot, p, length);
                    p = a + 2;
                    (*slot)[length] = 0;
                } else if (length < b - p) {
                    S5070_ncopy(*slot, p, length);
                    p = a + 2;
                    (*slot)[length] = 0;
                } else {
                    length = b - p;
                    S5070_ncopy(*slot, p, length);
                    (*slot)[length] = 0;
                    break;
                }
            }
        }
        M2C_FIELD(arg0, int *, 0x20) = n; }

        { char *p = arg2; char **slots = (char **)(arg0 + 0x834); int n = 0;
        while (*p) {
            char *a = S5070_find(p, D_002F9118);
            char *b = S5070_find(p, D_002F9120);
            if (!a) {
                if (!b) {
                    if (S5070_len(p)) S5070_copy(slots[n++], p);
                } else {
                    int length = b - p;
                    char **slot = &slots[n++];
                    S5070_ncopy(*slot, p, length);
                    (*slot)[length] = 0;
                }
                break;
            } else {
                int length = a - p;
                char **slot = &slots[n++];
                if (!b) {
                    S5070_ncopy(*slot, p, length);
                    p = a + 2;
                    (*slot)[length] = 0;
                } else if (length < b - p) {
                    S5070_ncopy(*slot, p, length);
                    p = a + 2;
                    (*slot)[length] = 0;
                } else {
                    length = b - p;
                    S5070_ncopy(*slot, p, length);
                    (*slot)[length] = 0;
                    break;
                }
            }
        }
        M2C_FIELD(arg0, int *, 0x24) = n; }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5070);
#endif

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5368);

extern "C" int func_001A5540(MnuDlg *arg0)
{
    if (arg0->m_open == 0) {
        return -2;
    }
    return arg0->m_result;
}

extern "C" void func_001A5558(MnuDlg *arg0)
{
    if (arg0->m_open != 0 && arg0->m_active == 1) {
        arg0->m_subStep = 4;
    }
}

extern "C" int func_001A557C()
{
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9118);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9120);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5584);

MnuSvld::MnuSvld()
{
    m_open = 0;
    m_isLoad = 1;
    func_001A65F0(this);
    m_active = 0;
    m_saveBuf = 0;
}

MnuSvld::~MnuSvld()
{
    if (m_active == 1) {
        func_001A5BF4(this);
    }
}

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9130);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9140);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9150);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9160);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9170);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9180);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9190);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91B0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91C0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91D0);

extern "C" void func_001A5AF4(MnuSvld *arg0, int arg1)
{
    MnuRpk *rpk = &arg0->m_rpk;
    X_func_0018BCC0(rpk, 0x49);
    rpk->setUnk8E8(1);
    arg0->m_rpk.m_param = arg1;
    func_001A5D04(arg0);
    func_001A5C80(arg0);
    rpk->setUnk8E8(1);
    X_func_0018C2E4(rpk, "fnt16US.bin", 0);
    X_func_0018C2E4(rpk, "fnt16US.bin", 1);
    arg0->m_active = 1;
    arg0->m_result = 0;
    if (arg0->m_saveBuf == 0) {
        arg0->m_saveBuf = X_alloc__9BedMemoryiPCciii(&D_006E9800, 0x3000, D_002F91E8, 0x86, 0, 2);
        if (arg0->m_saveBuf == 0) {
            X_func_002155F4(D_002F91E8, 0x87, D_002F91F8);
        }
        X_memset(arg0->m_saveBuf, 0, 0x3000);
    }
}

extern "C" void func_001A5BF4(MnuSvld *arg0)
{
    if (arg0->m_active != 0) {
        X_func_0018C130(&arg0->m_rpk);
        register char *base PS2_REG("$16") = (char *)&D_006E9840;
        func_001A5D74(arg0);
        char *sc = base + 0x12540;
        X_func_00135594(sc, arg0->m_winId);
        X_func_001348B0(sc, arg0->m_winId);
        X_func_00187464(arg0->m_msgWin);
        X_heapFree__FPv(arg0->m_saveBuf);
        arg0->m_saveBuf = 0;
        arg0->m_active = 0;
    }
}

extern "C" int func_001A5C78(MnuSvld *arg0)
{
    return arg0->m_active;
}

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91E8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F91F8);

extern "C" void func_001A5C80(MnuSvld *arg0)
{
    X_func_0018F744(arg0->m_rpk.m_loader, &D_002A4530, "data/mnurpk/mnusvld.rpk");
    do {
    } while (X_func_0018FEBC(arg0->m_rpk.m_loader) == 0);
}

extern "C" int func_001A5CC4()
{
    return X_func_001A5ED0();
}

extern "C" void func_001A5CD8(MnuSvld *arg0, int arg1)
{
    MnuRpk *rpk = &arg0->m_rpk;
    arg0->m_renderCtx = arg1;
    if (arg1 != 0) {
        rpk->setRenderCtx(arg1);
        X_func_0018BD94(rpk);
    }
}

// NON_MATCHING: 3/28 differ (size 0x70, game 0x70), 2 edits (store order)
#ifdef NON_MATCHING
extern "C" int func_001A5D04(MnuSvld *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_mode = 1;
    arg0->m_step = 0;
    arg0->m_subStep = 0;
    arg0->m_unk24EC = 0;
    arg0->m_unk24F4 = 0;
    arg0->m_unk24FC = 0;
    arg0->m_unk2500 = 0;
    arg0->m_unk2504 = 0;
    arg0->m_cursor[1] = 0;
    arg0->m_cursor[2] = 0;
    arg0->m_unk1470 = 6;
    arg0->m_unk24E4 = 3;
    X_func_0018741C(arg0->m_msgWin);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5D04);
#endif

extern "C" int func_001A5D74(MnuSvld *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    arg0->m_open = 0;
    return 0;
}

extern "C" int func_001A5D90()
{
    return 0;
}

extern "C" int func_001A5D98()
{
    return 0;
}

extern "C" void func_001A5DA0(MnuSvld *arg0, int show)
{
    if (show != 0) {
        if (arg0->m_winShown == 0) {
            register char *base PS2_REG("$16") = (char *)&D_006E9840;
            char *sc = base + 0x12540;
            X_func_001351B0(sc, arg0->m_winId, 0);
            X_func_001C5094(&D_007812C0, 5, 1, 0);
            X_func_001C5094(&D_007812C0, 4, 1, 0);
            X_func_00135088(sc, arg0->m_winId, 0xF, 0, 0x80);
            X_func_001C51E0(&D_007812C0, 5, 0xF);
            X_func_001C51E0(&D_007812C0, 4, 0xF);
            arg0->m_winShown = 1;
        }
    } else {
        if (arg0->m_winShown != 0) {
            register char *base PS2_REG("$4") = (char *)&D_006E9840;
            char *sc = base + 0x12540;
            X_func_0013511C(sc, arg0->m_winId, 0xF, 0, 0x80);
            X_func_001C5240(&D_007812C0, 5, 0xF);
            X_func_001C5240(&D_007812C0, 4, 0xF);
            arg0->m_winShown = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A5ED0);

extern "C" int func_001A65F0(MnuSvld *arg0)
{
    int i;

    for (i = 0; i < 9; i++) {
        arg0->m_cursor[i] = 0;
    }
    func_001A6BF8(arg0);
    arg0->m_slotMax = 0xC;
    arg0->m_visMax = 5;
    arg0->m_gridMax = 0x24;
    arg0->m_unk24F0 = 0;
    return 0;
}

extern "C" void func_001A665C(MnuSvld *arg0)
{
    MnuRpk *rpk = &arg0->m_rpk;
    arg0->m_sys = _9MagSystem$m_current_system;
    rpk->setTbl(&D_002A45C0);
    Xiii_func_0018C190(rpk, &D_002A64E0);
    int v = arg0->m_isLoad;
    if (v != 0) {
        if (v == 1) {
            Xiiii_func_0018C4D8((int)rpk, 0x3E, 1);
        }
    } else {
        Xiiii_func_0018C4D8((int)rpk, 0x3E, 3);
    }
    rpk->setUnk04(1);
}

extern "C" int func_001A66F0(MnuSvld *arg0)
{
    X_func_001874AC(arg0->m_msgWin);
    X_func_0018C068(&arg0->m_rpk);
    bool ok = X_func_00131550((char *)arg0->m_sys + 0x12540) >= 5;
    if (ok == 1) {
        int *p = (int *)(*(char **)&D_007B2060 + 4);
        *p |= 0x40000000;
    }
    return 0;
}

extern "C" void *func_001A6764(MnuSvld *arg0)
{
    if (arg0->m_saveBuf == 0) {
        X_func_002155F4(D_002F91E8, 0x2C4, D_002F91F8);
    }
    X_memset(arg0->m_saveBuf, 0, 0x3000);
    X_func_001D6078(&D_007812C0, arg0->m_saveBuf);
    X_func_001A1514(arg0, arg0->m_saveBuf);
    return arg0->m_saveBuf;
}

extern "C" int func_001A67D8(MnuSvld *arg0)
{
    if (arg0->m_saveBuf == 0) {
        X_func_002155F4(D_002F91E8, 0x2D7, D_002F91F8);
    }
    X_func_001D68A0(&D_007812C0, arg0->m_saveBuf);
    return 1;
}

extern "C" int func_001A6830(MnuSvld *arg0, int arg1)
{
    return (unsigned int)(~arg0->m_slots[arg1].m_status) >> 31;
}

extern "C" void func_001A6858(MnuSvld *arg0, int arg1, char *arg2)
{
    X_func_00279C98(
        arg2, D_002F9248, D_002F9268, D_002F9278,
        arg1,
        arg0->m_slots[arg1].m_status,
        arg0->m_slots[arg1].m_clearFlg,
        arg0->m_slots[arg1].m_chapter,
        arg0->m_slots[arg1].m_hours,
        arg0->m_slots[arg1].m_minutes
    );
}

extern "C" void func_001A68E0(MnuSvld *arg0, int arg1, char *arg2)
{
    X_func_00279C98(
        arg2, D_002F9248, D_002F9268, D_002F9278,
        arg1,
        arg0->m_slots[arg1].m_status,
        arg0->m_slots[arg1].m_clearFlg,
        arg0->m_slots[arg1].m_chapter,
        arg0->m_slots[arg1].m_hours,
        arg0->m_slots[arg1].m_minutes
    );
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A6968);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9248);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9268);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9278);

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A6AB8);

extern "C" void func_001A6BF8(MnuSvld *arg0)
{
    for (int i = 0; i < 12; i++) {
        arg0->m_slots[i].m_status = -1;
        arg0->m_slots[i].m_clearFlg = -1;
        arg0->m_slots[i].m_chapter = -1;
        arg0->m_slots[i].m_hours = -1;
        arg0->m_slots[i].m_minutes = -1;
        arg0->m_slots[i].m_year = -1;
        arg0->m_slots[i].m_month = -1;
        arg0->m_slots[i].m_day = -1;
        arg0->m_slots[i].m_hour = -1;
        arg0->m_slots[i].m_min = -1;
        arg0->m_slots[i].m_sec = -1;
    }
}


INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92A8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92B0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92B8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92C0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92C8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92D0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92D8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92E0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92E8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92F0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F92F8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9300);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9318);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9330);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9340);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9350);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9360);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9370);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9380);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9390);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93B0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93C0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93D0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93E0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F93F0);

// NON_MATCHING: 164/216 differ, 5 relocs differ (size 0x360, game 0x358), 75 edits
#ifdef NON_MATCHING
extern int D_002A7460;
extern char D_006E9450[];
struct Text6_6C90 { char text[6]; } __attribute__((packed));
extern "C" int C6C90_sprite(int, int, int) asm("func_0018C4D8");
extern "C" void func_001A6C90(int object, int arg1, int arg2)
{
    register int arg0 PS2_REG("$21") = object;
    register int number PS2_REG("$22") = arg1 + 0x29;
    int sub = arg0 + 0x1474;
    M2C_FIELD(number * 0x154 + M2C_FIELD(sub, int *, 0x4AC), int *, 0x150) = (int)&D_002A7460;
    if (arg2 < 12) {
        int data = M2C_FIELD(sub, int *, 0x4AC);
        int sprite = arg1 + 0x1D;
        unsigned int value = M2C_FIELD(arg0 + arg2 * 0x2C, unsigned int *, 0x2510);

        if (value >= 13) {
            int offset = sprite * 0x154;
            M2C_FIELD(offset + data, int *, 0xD8) = 10;
            C6C90_sprite(sub, sprite, 0);
            M2C_FIELD(offset + M2C_FIELD(sub, int *, 0x4AC), int *, 0xC) = 0;
            M2C_FIELD(offset + M2C_FIELD(sub, int *, 0x4AC), int *, 0x10) = 0;
            M2C_FIELD(M2C_FIELD(sub, int *, 0x4AC), int *, 0x57B8) = 0;
            M2C_FIELD(M2C_FIELD(sub, int *, 0x4AC), int *, 0x5510) = 0;
            M2C_FIELD(M2C_FIELD(sub, int *, 0x4AC), int *, 0x5664) = 0;
            M2C_FIELD(M2C_FIELD(sub, int *, 0x4AC), int *, 0x590C) = 0;
        } else {
            int offset = sprite * 0x154;
            M2C_FIELD(offset + data, int *, 0xD8) = value + 10;
            M2C_FIELD(offset + M2C_FIELD(sub, int *, 0x4AC), int *, 0x10) = 1;
            C6C90_sprite(sub, sprite, 0);
            M2C_FIELD(offset + M2C_FIELD(sub, int *, 0x4AC), int *, 0xC) = 1;
        }
        int *baseHours = (int *)(arg0 + 0x14);
        int *hours = (int *)((char *)baseHours + (arg2 * 0x2C + 0x2500));
        int h = *hours;

        if (h < 0) {
            *(Text6_6C90 *)(D_006E9450 + arg1 * 6) = *(const Text6_6C90 *)"--:--";
        } else {
            if (h >= 100) {
                D_006E9450[arg1 * 6 + 0] = '9'; D_006E9450[arg1 * 6 + 1] = '9';
            } else {
                D_006E9450[arg1 * 6 + 0] = h / 10 + '0';
                D_006E9450[arg1 * 6 + 1] = *hours % 10 + '0';
            }
            D_006E9450[arg1 * 6 + 2] = ':';
            int *minutes = (int *)(arg0 + 8 + (arg2 * 0x2C + 0x2510));
            int m = *minutes;
            if (m >= 60) {
                D_006E9450[arg1 * 6 + 3] = '5'; D_006E9450[arg1 * 6 + 4] = '9';
            } else {
                D_006E9450[arg1 * 6 + 3] = m / 10 + '0';
                D_006E9450[arg1 * 6 + 4] = *minutes % 10 + '0';
            }
            D_006E9450[arg1 * 6 + 5] = 0;
        }
        int textOffset = ((number * 4) + number) * 0x44;
        M2C_FIELD(textOffset + M2C_FIELD(sub, int *, 0x4AC), int *, 0x144) = 0;
        M2C_FIELD(textOffset + M2C_FIELD(sub, int *, 0x4AC), int *, 0x148) = 0;
        M2C_FIELD(textOffset + M2C_FIELD(sub, int *, 0x4AC), int *, 0x14C) = (int)(D_006E9450 + arg1 * 6);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A6C90);
#endif

extern "C" void func_001A6FE8(MnuSvld *arg0)
{
    int i;

    for (i = 0; i < arg0->m_slotMax; i++) {
        X_func_001A6C90_6FE8(arg0, i, i);
    }
}

extern "C" int func_001A7040(unsigned char arg0)
{
    unsigned int temp_v0;

    temp_v0 = arg0 & 0xFF;
    return ((temp_v0 >> 4) * 0xA) + (temp_v0 & 0xF);
}

extern "C" int func_001A7060(int arg0)
{
    return ((arg0 / 10) * 0x10) + (arg0 % 10);
}


// NON_MATCHING: 197/222 differ, 15 relocs differ (size 0x378, game 0x390), 148 edits
#ifdef NON_MATCHING
extern "C" void F7088_clear(int) asm("func_001A6BF8");
extern "C" int F7088_count(int) asm("func_001A1C8C");
extern "C" int F7088_atoi(const char *) asm("atoi");
extern "C" int F7088_bcd(int) asm("func_001A7060");
extern "C" int F7088_decimal(unsigned char) asm("func_001A7040");
extern "C" void F7088_local(void *) asm("sceScfGetLocalTimefromRTC");
extern "C" void func_001A7088(int object)
{
    register int arg0 PS2_REG("$22") = object;
    int values[5];
    char digits[3];
    unsigned char rtc[8];
    int base8;
    int base14;
    F7088_clear(arg0);
    if (F7088_count(arg0) > 0) {
        int i = 0;
loop_7088:
        int sub = arg0 + 0xC0;
        if (i < F7088_count(arg0)) {

            char *name = (char *)(sub + (i << 6) + 0x1E0);
            if (i >= M2C_FIELD(sub, int *, 0x90)) name = 0;
            if (name[0] == 'd' && name[1] == 't') {
                char *p = name;
                int error = 0;
                int n = 0;
                int *out = values;
                do {
                    char a = p[2];
                    digits[0] = a;
                    char b = p[3];
                    p += 2;
                    digits[2] = 0;
                    digits[1] = b;
                    if (a == '_' || b == '_') error = 1;
                    else {
                        int value = F7088_atoi(digits);
                        if (value < 0) { error = 1; break; }
                        *out = value;
                    }
                    n++;
                    out++;
                } while (n < 5);
                if (error != 1 && values[0] >= 0) {
                    base8 = arg0 + 8;
                    if (values[0] < M2C_FIELD(arg0, int *, 0x142C)) {
                        base14 = arg0 + 0x14;
                        int offset = values[0] * 0x2C;
                        int baseC = arg0 + 0xC;
                        int base10 = arg0 + 0x10;
                        *(int *)(base8 + offset + 0x2500) = values[1] / 10;
                        *(int *)(baseC + offset + 0x2500) = values[1] % 10;
                        *(int *)(base10 + offset + 0x2500) = values[2];
                        *(int *)(base14 + offset + 0x2500) = values[3];
                        M2C_FIELD(offset + base8, int *, 0x2510) = values[4];
                        unsigned short year = 0;
                        if (i < M2C_FIELD(sub, int *, 0x90)) year = M2C_FIELD(sub + (i << 6), unsigned short *, 0x1CE);
                        rtc[7] = F7088_bcd(year < 2000 ? year : year - 2000);
                        unsigned char v0 = 0;
                        if (i < M2C_FIELD(sub, int *, 0x90)) v0 = M2C_FIELD(sub + (i << 6), unsigned char *, 0x1CD);
                        rtc[6] = F7088_bcd(v0);

                        unsigned char v1 = 0;
                        if (i < M2C_FIELD(sub, int *, 0x90)) v1 = M2C_FIELD(sub + (i << 6), unsigned char *, 0x1CC);
                        rtc[5] = F7088_bcd(v1);

                        unsigned char v2 = 0;
                        if (i < M2C_FIELD(sub, int *, 0x90)) v2 = M2C_FIELD(sub + (i << 6), unsigned char *, 0x1CB);
                        rtc[3] = F7088_bcd(v2);

                        unsigned char v3 = 0;
                        if (i < M2C_FIELD(sub, int *, 0x90)) v3 = M2C_FIELD(sub + (i << 6), unsigned char *, 0x1CA);
                        rtc[2] = F7088_bcd(v3);

                        unsigned char v4 = 0;
                        if (i < M2C_FIELD(sub, int *, 0x90)) v4 = M2C_FIELD(sub + (i << 6), unsigned char *, 0x1C9);
                        rtc[1] = F7088_bcd(v4);
                        F7088_local(rtc);
                        int y = F7088_decimal(rtc[7]);
                        int m = F7088_decimal(rtc[6]);
                        int d = F7088_decimal(rtc[5]);
                        int h = F7088_decimal(rtc[3]);
                        int min = F7088_decimal(rtc[2]);
                        int sec = F7088_decimal(rtc[1]);
                        int offset2 = values[0] * 0x2C;
                        int date = offset2 + 0x2510;
                        int time = offset2 + 0x2520;
                        *(int *)(baseC + date) = y;
                        *(int *)(base10 + date) = m;
                        *(int *)(base14 + date) = d;
                        *(int *)(base8 + time) = h;
                        *(int *)(baseC + time) = min;
                        *(int *)(base10 + time) = sec;
                    }
                }
            }
            i++;
            goto loop_7088;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A7088);
#endif

// NON_MATCHING: 6/32 differ (size 0x80, game 0x80), 4 edits
#ifdef NON_MATCHING
extern "C" void func_001A7418(MnuSvld *arg0, int type)
{
    int row = arg0->m_cursor[1] - arg0->m_cursor[2];
    switch (type) {
    case 0: {
        MnuRpk *rpk = &arg0->m_rpk;
        X_func_0018C6C4_7418(rpk, 1, row);
        rpk->setSpr08(1, 5);
        break;
    }
    case 1: {
        MnuRpk *rpk = &arg0->m_rpk;
        X_func_0018C6C4_7418(rpk, type, row);
        rpk->setSpr08(1, 5);
        break;
    }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A7418);
#endif

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A7498);

extern "C" void *func_001A7B90(void *arg0, const unsigned char *arg1)
{
    char buf[64];
    int count = 0;

    while (arg1[0] == 0x81 && arg1[1] == 0x40) {
        arg1 += 2;
        count++;
    }
    buf[0] = '\0';
    for (int i = 0; i < count; i++) {
        const char *s = (const char *)&D_002F9428;
        Xvp_strcpy(buf + Xvp_strlen(buf), s);
    }
    Xvp_snprintf(arg0, 0x40, (const char *)&D_002F9430, buf, arg1, 0);
    return arg0;
}

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9428);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9430);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9440);

// NON_MATCHING: 131/185 differ, 10 relocs differ (size 0x2E4, game 0x2EC), 66 edits
#ifdef NON_MATCHING
extern "C" int Xiii_func_001A7B90(int, int) asm("func_001A7B90");
extern "C" int Xiii_strcpy(int, int) asm("strcpy");
extern "C" int Xiu_func_001832E8(unsigned int) asm("func_001832E8");
extern int D_002A7470;
extern int D_002F9440;
extern int D_006E94A0;
extern int D_006E9520;
extern int D_006E95A0;
extern "C" void func_001A7C54(int object, int index)
{
    register int arg0 PS2_REG("$18") = object;
    register int arg1 PS2_REG("$20") = index;
    register int one PS2_REG("$6") = 1;
    int temp_v0_2;
    int temp_a1;
    int temp_t3;
    int temp_v1;
    int temp_a0;
    int temp_a4;
    int temp_hi;
    int temp_s1;
    int temp_s1_2;
    unsigned short temp_s3;
    int var_a1;
    int temp_a2;
    int temp_s0;
    int temp_s6;
    int temp_v0;

    temp_s0 = arg0 + 0x1474;
    temp_s6 = arg0 + 0xC;
    temp_s3 = (*(unsigned short *)&D_002F9440);
    temp_s1 = arg1 * 0x2C;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x57B8) = one;
    temp_a4 = temp_s1 + 0x2510;
    temp_t3 = temp_s6 + temp_a4;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5510) = one;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5664) = one;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x590C) = one;
    M2C_FIELD((int)&D_006E94A0, unsigned short *, 0) = temp_s3;
    (*(unsigned short *)&D_006E9520) = temp_s3;
    M2C_FIELD((int)&D_006E95A0, unsigned short *, 0) = temp_s3;
    if ((*(int *)(temp_t3)) > 0) {
        temp_v1 = arg0 + 0x10 + temp_a4;
        temp_a1 = arg0 + 0x14 + temp_a4;
        M2C_FIELD((int)&D_006E94A0, signed char *, 0) = (signed char) (((int) (*(int *)(temp_v1)) / 10) + 0x30);
        M2C_FIELD((int)&D_006E94A0, signed char *, 2) = 0x2F;
        M2C_FIELD((int)&D_006E94A0, signed char *, 1) = (signed char) (((int) (*(int *)(temp_v1)) % 10) + 0x30);
        M2C_FIELD((int)&D_006E94A0, signed char *, 3) = (signed char) (((int) (*(int *)(temp_a1)) / 10) + 0x30);
        M2C_FIELD((int)&D_006E94A0, signed char *, 5) = 0x2F;
        M2C_FIELD((int)&D_006E94A0, signed char *, 4) = (signed char) (((int) (*(int *)(temp_a1)) % 10) + 0x30);
        temp_hi = (int) (*(int *)(temp_t3)) % 1000;
        M2C_FIELD((int)&D_006E94A0, signed char *, 6) = (signed char) ((temp_hi / 10) + 0x30);
        M2C_FIELD((int)&D_006E94A0, signed char *, 8) = 0;
        M2C_FIELD((int)&D_006E94A0, signed char *, 7) = (signed char) (((int) (temp_hi % 10) % 10) + 0x30);
    }
    temp_s1_2 = temp_s1 + 0x2500;
    temp_a0 = M2C_FIELD((arg0 + temp_s1_2), int *, 0x10);
    if (temp_a0 >= 0) {
        var_a1 = 0;
        if ((unsigned int) temp_a0 < 0xDU) {
            var_a1 = Xiu_func_001832E8(temp_a0 + 0x1C6);
        }
        if (*(int *)(temp_s6 + temp_s1_2) != 0) {
            Xiii_func_001A7B90((int)&D_006E9520, var_a1);
        } else if (var_a1 == 0) {
            (*(unsigned short *)&D_006E9520) = temp_s3;
        } else {
            Xiii_strcpy((int)&D_006E9520, var_a1);
        }
    }
    temp_v0 = (arg1 * 0x2C) + arg0;
    if (M2C_FIELD(temp_v0, int *, 0x2508) == 1) {
        temp_v0_2 = (int) "Save data is corrupted.    ";
        int tail = M2C_FIELD(temp_v0_2, int *, 0x18);
        long long a = M2C_FIELD(temp_v0_2, long long *, 0);
        long long b = M2C_FIELD(temp_v0_2, long long *, 8);
        long long c = M2C_FIELD(temp_v0_2, long long *, 0x10);
        char *dst = (char *)&D_006E95A0;
        *(int *)(dst + 0x18) = tail;
        *(long long *)dst = a;
        *(long long *)(dst + 8) = b;
        *(long long *)(dst + 0x10) = c;
    }
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5650) = (int)&D_002A7470;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x57A4) = (int)&D_002A7470;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x58F8) = (int)&D_002A7470;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5A4C) = (int)&D_002A7470;
    temp_a2 = M2C_FIELD(temp_s0, int *, 0x4AC);
    if (M2C_FIELD(temp_v0, int *, 0x2508) == 1) {
        M2C_FIELD(temp_a2, int *, 0x58EC) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x58F0) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x58F4) = (int)&D_006E95A0;
        return;
    }
    M2C_FIELD(temp_a2, int *, 0x5644) = 0;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5648) = 0;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x564C) = (int)&D_006E94A0;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5798) = 0;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x579C) = 0;
    M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x57A0) = (int)&D_006E9520;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A7C54);
#endif

extern "C" int func_001A7F40(MnuSvld *arg0, int arg1)
{
    int var_s2 = 0;

    switch (arg0->m_subStep) {
    case 13:
        break;
    case 0:
        arg0->m_cursor[0] = 0;
        arg0->m_subStep = 0xD;
        func_001A6BF8(arg0);
        func_001A6FE8(arg0);
        break;
    case 17:
        arg0->m_subStep = 0;
        break;
    case 1:
        arg0->m_subStep = 0xD;
        break;
    }
    if ((padTrigU_F40(arg1) >> 0xD) & 1) {
        var_s2 = 2;
        X_func_0017F8FC(&D_007B2580, 2);
    }
    return var_s2;
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8000);

// NON_MATCHING: 85/125 differ, 8 relocs differ (size 0x1F4, game 0x1EC), 17 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_001A6FE8(int) asm("func_001A6FE8");
extern "C" int Xii_func_001A7088(int) asm("func_001A7088");
extern "C" int Xiii_func_001A1658(int, int) asm("func_001A1658");
extern "C" int Xiii_func_001A5DA0(int, int) asm("func_001A5DA0");
extern "C" int Xiiiu_func_001A7498(int, int, unsigned int) asm("func_001A7498");
extern "C" int func_001A8730(int arg0)
{
    int temp_s1;
    int var_s1;
    int var_s2;
    unsigned int temp_v1;
    unsigned int var_v0;
    int temp_s0;
    int temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, unsigned int *, 0x1454);
    var_s2 = 0;
    switch (temp_v1) {                              
    case 0:                                         
        temp_v1_2 = arg0 + 0x1474;
        M2C_FIELD(arg0, unsigned int *, 0x1454) = 1U;
        M2C_FIELD(M2C_FIELD(temp_v1_2, int *, 0x4AC), int *, 0x4FC0) = 0;
        M2C_FIELD(M2C_FIELD(temp_v1_2, int *, 0x4AC), int *, 0x5114) = 0;
        Xiiiu_func_001A7498(arg0, 0xC, 3U);
        Xiii_func_001A5DA0(arg0, 0);
        
    case 1:                                         
        temp_s1 = M2C_FIELD(arg0, int *, 0x24E8);
        switch (temp_s1) {                          
        case 1:                                     
            if (Xiii_func_001A1658(arg0, 2) == temp_s1) {
                var_v0 = 2;
block_25:
                M2C_FIELD(arg0, unsigned int *, 0x1454) = var_v0;
            }
        default:                                    
            break;
        case 0:                                     
            if (Xiii_func_001A1658(arg0, 3) == 1) {
                var_v0 = 2;
                goto block_25;
            }
            break;
        }
        break;
    case 2:                                         
        var_s1 = 0;
        if (M2C_FIELD(arg0, int *, 0x24) == 4) {
            var_s1 = M2C_FIELD(arg0, int *, 0x1390);
        }
        M2C_FIELD(arg0, int *, 0x24E0) = var_s1;
        switch (var_s1) {                           
        case 0:                                     
            Xii_func_001A6BF8(arg0);
            Xii_func_001A6FE8(arg0);
            break;
        case 1:                                     
            if (M2C_FIELD(arg0, int *, 0x2754) != var_s1) {
                Xiii_func_001A5DA0(arg0, 1);
            }
            M2C_FIELD(arg0, int *, 0x274C) = var_s1;
            Xii_func_001A7088(arg0);
            Xii_func_001A6FE8(arg0);
            M2C_FIELD(arg0, int *, 0x1450) = 0;
            M2C_FIELD(arg0, unsigned int *, 0x1454) = 0U;
            break;
        case 2:                                     
            M2C_FIELD(arg0, unsigned int *, 0x1454) = 0U;
            M2C_FIELD(arg0, int *, 0x144C) = 6;
            break;
        }
        break;
    case 13: break;
    case 17:                                        
        var_s2 = 1;
        Xiiiu_func_001A7498(arg0, 0xC, 4U);
        M2C_FIELD(arg0, int *, 0x1450) = 0;
        var_v0 = 0xD;
        goto block_25;
    }
    var_s1 = M2C_FIELD(arg0, int *, 0x13BC);
    temp_s0 = arg0 + 0x1474;
    if (var_s1 == 1) {
        Xiiii_func_0018C4D8(temp_s0, 0x45, 0);
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB0) = var_s1;
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB4) = var_s1;
    } else {
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB0) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB4) = 0;
    }
    return var_s2;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8730);
#endif

// NON_MATCHING: 137/148 differ, 11 relocs differ (size 0x250, game 0x260), 79 edits
#ifdef NON_MATCHING
extern "C" int Xii_func_001A6764(int) asm("func_001A6764");
extern "C" int X891C_1658(int, int) asm("func_001A1658");
extern "C" int X891C_5DA0(int, int) asm("func_001A5DA0");
extern "C" int Xiiii_func_001A6968(int, int, int) asm("func_001A6968");
extern "C" int Xiiii_func_001A6AB8(int, int, int) asm("func_001A6AB8");
extern "C" int X891C_1B8C(int, int, int, int, int, int, int) asm("func_001A1B8C");
extern "C" int X891C_7498(int, int, unsigned int) asm("func_001A7498");
extern "C" int func_001A891C(int arg0)
{
    struct { char pad0[64]; char sp40[64]; } stack;
    int *index = (int *)(arg0 + 0x1408);
    int var_a0;
    int var_s3;
    int var_v0;
    unsigned int temp_v1;
    int temp_s0;
    int temp_s0_2;

    temp_v1 = M2C_FIELD(arg0, unsigned int *, 0x1454);
    var_s3 = 0;
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, unsigned int *, 0x1454) = 1U;
        M2C_FIELD((*(int *)&D_007B2060), int *, 8) = (int) (M2C_FIELD((*(int *)&D_007B2060), int *, 8) & 0xFFFEFFFF);
        X891C_5DA0(arg0, 0);
    default:
block_21:
        var_v0 = var_s3;
        break;
    case 1:
        temp_s0 = arg0 + 0x1474;
        Xiiii_func_0018C4D8(temp_s0, 0x45, 0);
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB0) = 1;
        M2C_FIELD(M2C_FIELD(temp_s0, int *, 0x4AC), int *, 0x5BB4) = 1;
        Xiiii_func_001A6AB8(arg0, (*index), (int)&stack);
        Xiiii_func_001A6968((int) arg0, (*index), (int)&stack.sp40);
        Xii_func_001A6764(arg0);
        X891C_1B8C(arg0, (int)&stack.sp40, (int)&stack, 0x3000, M2C_FIELD(arg0, int *, 0x2740), 0x3000, M2C_FIELD(arg0, int *, 0x2740));
        X891C_7498(arg0, 0xC, 3U);
        M2C_FIELD(arg0, unsigned int *, 0x1454) = 0xDU;
        break;
    case 2:
        var_v0 = var_s3;
        if (X891C_1658(arg0, 4) == 1) {
            X891C_7498(arg0, 0xC, 4U);
            M2C_FIELD(arg0, unsigned int *, 0x1454) = 3U;
            break;
        }
        
        break;
    case 3:
        var_a0 = 0;
        if (M2C_FIELD(arg0, int *, 0x24) == 4) {
            var_a0 = M2C_FIELD(arg0, int *, 0x1390);
        }
        M2C_FIELD(arg0, int *, 0x24E0) = var_a0;
        if (var_a0 == 1) {
            M2C_FIELD(arg0, int *, 0x274C) = var_a0;
            M2C_FIELD(arg0, unsigned int *, 0x1454) = 2U;
            break;
        }
block_15:
        var_v0 = var_s3;
        if (var_a0 >= 2) {
            if (var_a0 != 2) {
                break;
            }
            M2C_FIELD(arg0, unsigned int *, 0x1454) = 0x11U;
            break;
        }
        
        break;
    case 13:
        var_v0 = var_s3;
        if (X891C_1658(arg0, 5) == 1) {
            M2C_FIELD(arg0, unsigned int *, 0x1454) = 0xEU;
            break;
        }
        
        break;
    case 14:
        var_a0 = 0;
        if (M2C_FIELD(arg0, int *, 0x24) == 4) {
            var_a0 = M2C_FIELD(arg0, int *, 0x1390);
        }
        M2C_FIELD(arg0, int *, 0x24E0) = var_a0;
        if (var_a0 != 1) {
            goto block_15;
        }
        M2C_FIELD((*(int *)&D_007B2060), int *, 8) = (int) (M2C_FIELD((*(int *)&D_007B2060), int *, 8) | 0x10000);
        M2C_FIELD(arg0, unsigned int *, 0x1454) = 0x11U;
        break;
    case 17:
        temp_s0_2 = arg0 + 0x1474;
        Xiiii_func_0018C4D8(temp_s0_2, 0x45, 0);
        var_s3 = 1;
        M2C_FIELD(M2C_FIELD(temp_s0_2, int *, 0x4AC), int *, 0x5BB0) = 0;
        M2C_FIELD(M2C_FIELD(temp_s0_2, int *, 0x4AC), int *, 0x5BB4) = 0;
        M2C_FIELD(arg0, unsigned int *, 0x1454) = 0U;
        M2C_FIELD(arg0, int *, 0x1450) = 0;
        break;
    }
    return var_s3;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A891C);
#endif

INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8B7C);

// NON_MATCHING: 62/79 differ, 1 reloc differs (size 0x13C, game 0x140), 11 edits
#ifdef NON_MATCHING
extern "C" int func_001A8D44(MnuSvld *obj, int arg1)
{
    register MnuSvld *arg0 PS2_REG("$18") = obj;
    int ret = 0;

    switch (arg0->m_subStep) {
    case 0: {
        MnuRpk *rpk = &arg0->m_rpk;
        arg0->m_cursor[5] = 0;
        arg0->m_subStep = 0xD;
        Xiiii_func_0018C4D8((int)rpk, 0x45, 0);
        register int one PS2_REG("$17") = 1;
        rpk->setSprVis0C(0x45, one);
        rpk->setSprVis10(0x45, one);
        break;
    }
    case 1:
    case 13:
        break;
    case 17:
        ret = 1;
        arg0->m_rpk.m_sprTbl[0x45].m_vis10 = 0;
        arg0->m_mode = 0;
        arg0->m_subStep = 0;
        arg0->m_unk24FC = 0;
        break;
    }
    if (ret == 0 && arg0->m_unk24EC == 0) {
        unsigned int trig = padTrigU_F40(arg1);
        if ((trig >> 14) & 1) {
        } else if (M2C_FIELD(arg1, int *, 0x70) & 0x10) {
        } else if (M2C_FIELD(arg1, int *, 0x70) & 0x40) {
        } else if (M2C_FIELD(arg1, int *, 0x70) & 0x80) {
        } else if (M2C_FIELD(arg1, int *, 0x70) & 0x20) {
        } else if ((trig >> 13) & 1) {
            arg0->m_subStep = 0x11;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8D44);
#endif

// NON_MATCHING: 106/109 differ, 2 relocs differ (size 0x1B4, game 0x258), 105 edits
#ifdef NON_MATCHING
extern "C" int Xcall90DC(int, int) asm("func_001A90DC");
extern "C" int Xcall90E4(int, int) asm("func_001A90E4");
extern "C" int func_001A8E84(int arg0, int arg1, unsigned short arg2)
{
    int temp_a1;
    int temp_a1_2;
    int temp_s1;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int var_s3;
    int var_s4;
    int var_v0;
    int var_v0_2;
    unsigned int temp_a2;
    int *cursor = (int *)(arg0 + 0x1424);
    int sub = arg0 + 4;

    var_s3 = 0;
    temp_v1 = M2C_FIELD(arg0, int *, 0x1454);
    var_s4 = 0;
    switch (temp_v1) {                              
    
    case 1:                                         
        break;
    case 0:                                         
        (*cursor) = 0;
        M2C_FIELD(arg0, int *, 0x1454) = 0xD;
        var_s3 = 1;
        break;
    }
    temp_v1_2 = (*cursor);
    if (M2C_FIELD(arg0, int *, 0x24EC) == 0) {
        temp_a2 = M2C_FIELD(arg1, unsigned short *, 0x7A);
        if ((temp_a2 >> 0xE) & 1) {
            var_s3 |= 2;
            M2C_FIELD(arg0, int *, 0x24EC) = 1;
        } else {
            temp_a1 = M2C_FIELD(arg1, int *, 0x70);
            if (temp_a1 & 0x10) {
                var_s3 |= 1;
                if (temp_v1_2 > 0) {
                    (*cursor) = (int) (temp_v1_2 - 1);
                } else {
                    (*cursor) = (int) (M2C_FIELD(arg0, int *, 0x1448) - 1);
                }
            } else if (temp_a1 & 0x40) {
                var_s3 |= 1;
                if (temp_v1_2 < (M2C_FIELD(arg0, int *, 0x1448) - 1)) {
                    (*cursor) = (int) (temp_v1_2 + 1);
                } else {
                    (*cursor) = 0;
                }
            } else if (temp_a1 & 0x80) {
                var_s3 |= 1;
                if (temp_v1_2 < 9) {
                    (*cursor) = (int) ((M2C_FIELD(arg0, int *, 0x1448) + temp_v1_2) - 9);
                } else {
                    (*cursor) = (int) (temp_v1_2 - 9);
                }
            } else if (temp_a1 & 0x20) {
                temp_a1_2 = M2C_FIELD(arg0, int *, 0x1448);
                var_s3 |= 1;
                if (temp_v1_2 < (temp_a1_2 - 9)) {
                    (*cursor) = (int) (temp_v1_2 + 9);
                } else {
                    (*cursor) = (int) (9 - (temp_a1_2 - temp_v1_2));
                }
            } else {
                var_s4 = ((temp_a2 >> 0xD) & 1) != 0;
            }
        }
    }
    temp_v1_3 = M2C_FIELD(arg0, int *, 0x24EC);
    switch (temp_v1_3) {                            
    case 2:                                         
        temp_v0 = Xcall90E4(arg0, M2C_FIELD(sub, int *, 0x1420));
        if (temp_v0 == 1) {
            M2C_FIELD(arg0, int *, 0x24F4) = temp_v0;
block_37:
            M2C_FIELD(arg0, int *, 0x24EC) = 0;
        }
        break;
    
    case 1:                                         
        temp_s1 = M2C_FIELD(arg0, int *, 0x24F4);
        if (temp_s1 == 2) {
            if (Xcall90DC(arg0, M2C_FIELD(sub, int *, 0x1420)) != 0) {
                M2C_FIELD(arg0, int *, 0x24F4) = 1;
                goto block_37;
            }
            M2C_FIELD(arg0, int *, 0x24EC) = temp_s1;
            M2C_FIELD(arg0, int *, 0x24F4) = 0;
        }
        break;
    }
    if ((var_s3 != 0) && (var_s3 & 7) && (var_s3 & 1)) {
        var_v0 = 0;
        do {
            var_v0 -= 1;
        } while (var_v0 >= 0);
        var_v0_2 = 0;
        do {
            var_v0_2 -= 1;
        } while (var_v0_2 >= 0);
    }
    return var_s4;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnusvld", func_001A8E84);
#endif

extern "C" int func_001A90DC()
{
    return 0;
}


extern "C" int func_001A90E4()
{
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F95D8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F95E8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F95F8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9608);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9618);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9628);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9638);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9648);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9658);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9668);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9678);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9688);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9698);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96A8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96B8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96C8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96D8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96E8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F96F8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9708);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9718);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9728);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9738);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9748);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9758);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9768);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9778);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9788);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9798);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97A8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97B8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97C8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97D8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97E8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F97F8);
INCLUDE_RODATA("asm/nonmatchings/mnu/mnusvld", D_002F9808);
