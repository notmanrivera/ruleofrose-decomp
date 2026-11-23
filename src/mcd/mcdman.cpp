#include "include_asm.h"
#include "utl/filereader.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"
extern "C" int F894_open(...) asm("sceMcOpen");
extern "C" int F899_rename(...) asm("sceMcRename");
extern "C" const char *F899_strrchr(const char *, int) asm("strrchr");
extern "C" char *F899_strcpy(char *, const char *) asm("strcpy");
extern "C" int F89F_write(...) asm("sceMcWrite");
extern "C" int F897_read(...) asm("sceMcRead");
extern "C" int X7C4C_func_00187E44(int) asm("func_00187E44");
extern "C" int X7C4C_func_001880CC(int) asm("func_001880CC");
extern "C" int X7C4C_func_001881C0(int) asm("func_001881C0");
extern "C" int X7C4C_func_001883C0(int) asm("func_001883C0");
extern "C" int X7C4C_func_001885D4(int) asm("func_001885D4");
extern "C" int X7C4C_func_0018894C(int) asm("func_0018894C");
extern "C" int X7C4C_func_00188BFC(int) asm("func_00188BFC");
extern "C" int X7C4C_func_00188CD4(int) asm("func_00188CD4");
extern "C" int X7C4C_func_00188EC0(int) asm("func_00188EC0");
extern "C" int X7C4C_func_00189068(int) asm("func_00189068");
extern "C" int X7C4C_func_001892B0(int) asm("func_001892B0");
extern "C" int X7C4C_func_001894D4(int) asm("func_001894D4");
extern "C" int X7C4C_func_00189718(int) asm("func_00189718");
extern "C" int X7C4C_func_0018993C(int) asm("func_0018993C");
extern "C" int X7C4C_func_00189B7C(int) asm("func_00189B7C");
extern "C" int X7C4C_func_00189D94(int) asm("func_00189D94");
extern "C" int X7C4C_func_00189F58(int) asm("func_00189F58");
extern "C" int X7C4C_func_0018A50C(int) asm("func_0018A50C");
extern "C" int X7C4C_func_0018AD0C(int) asm("func_0018AD0C");
extern "C" int X7C4C_func_0018ADE0(int) asm("func_0018ADE0");
extern "C" int X7C4C_func_0018B12C(int) asm("func_0018B12C");
extern "C" int X7C4C_func_0018B2BC(int) asm("func_0018B2BC");
extern "C" int Xii_func_001885D4(int) asm("func_001885D4");
extern "C" int Xii_func_001894D4(int) asm("func_001894D4");
extern "C" int Xii_func_00189718(int) asm("func_00189718");
extern "C" char *X_strchr_ci(const char *, int) asm("strchr");
extern "C" char *X_strcpy_cc(char *, const char *) asm("strcpy");
extern "C" const char *X_strrchr_ci(const char *, int) asm("strrchr");
extern const char *D_002998D0[];
extern BedMemory D_006E9800;
extern const char *D_0029993C;
extern const char D_002F7728[];
extern "C" void Xv_heapFree(void *) asm("heapFree__FPv");
extern "C" int Xc_func_001BE768(const char *) asm("func_001BE768");
extern "C" int Xii_func_00189068(int) asm("func_00189068");
extern "C" const char *Xcc_strstr(const char *, const char *) asm("strstr");
extern "C" int X_matchName(const struct McdMgr *, const char *, const char *) asm("func_0018B918");
extern "C" int Xi_strcmp(const char *, const char *) asm("strcmp");
struct McdDirEntry {
    int size;
    char pad[0xC];
    char name[0x30];
};
struct McdMgr {
    char pad0[0x90];
    int m_num;
    char pad1[0x13C];
    McdDirEntry m_dir[16];
    const char *getName(int i) const {
        return (i < m_num) ? m_dir[i].name : 0;
    }
    int getSize(int i) const {
        return (i < m_num) ? m_dir[i].size : 0;
    }
};
struct McdSlot {
    int f0;
    int f4;
    char pad[0x18];
    int f20;
    char pad2[0x398];
};
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" void Xv_func_001879C4(void *) asm("func_001879C4");
extern "C" int Xii_heapFree__FPv(int) asm("heapFree__FPv");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00185268(...) asm("func_00185268");
extern "C" int X_func_001853CC(...) asm("func_001853CC");
extern "C" int X_func_00185594(...) asm("func_00185594");
extern "C" int X_func_001856F4(...) asm("func_001856F4");
extern "C" int X_func_00187788(...) asm("func_00187788");
extern "C" int X_func_001879E0(...) asm("func_001879E0");
extern "C" int X_func_00187C30(...) asm("func_00187C30");
extern "C" int X_func_00187E44(...) asm("func_00187E44");
extern "C" int X_func_001880CC(...) asm("func_001880CC");
extern "C" int X_func_001881C0(...) asm("func_001881C0");
extern "C" int X_func_001883C0(...) asm("func_001883C0");
extern "C" int X_func_001885D4(...) asm("func_001885D4");
extern "C" int X_func_001887C0(...) asm("func_001887C0");
extern "C" int X_func_0018894C(...) asm("func_0018894C");
extern "C" int X_func_00188BFC(...) asm("func_00188BFC");
extern "C" int X_func_00188CD4(...) asm("func_00188CD4");
extern "C" int X_func_00188EC0(...) asm("func_00188EC0");
extern "C" int X_func_00189068(...) asm("func_00189068");
extern "C" int X_func_001892B0(...) asm("func_001892B0");
extern "C" int X_func_001894D4(...) asm("func_001894D4");
extern "C" int X_func_00189718(...) asm("func_00189718");
extern "C" int X_func_0018993C(...) asm("func_0018993C");
extern "C" int X_func_00189B7C(...) asm("func_00189B7C");
extern "C" int X_func_00189D94(...) asm("func_00189D94");
extern "C" int X_func_00189F58(...) asm("func_00189F58");
extern "C" int X_func_0018A50C(...) asm("func_0018A50C");
extern "C" int X_func_0018AD0C(...) asm("func_0018AD0C");
extern "C" int X_func_0018ADE0(...) asm("func_0018ADE0");
extern "C" int X_func_0018B12C(...) asm("func_0018B12C");
extern "C" int X_func_0018B2BC(...) asm("func_0018B2BC");
extern "C" int X_func_0018B918(...) asm("func_0018B918");
extern "C" int X_heapFree__FPv(...) asm("heapFree__FPv");
extern "C" int X_sceMcChdir(...) asm("sceMcChdir");
extern "C" int X_sceMcClose(...) asm("sceMcClose");
extern "C" int X_sceMcDelete(...) asm("sceMcDelete");
extern "C" int X_sceMcFlush(...) asm("sceMcFlush");
extern "C" int X_sceMcFormat(...) asm("sceMcFormat");
extern "C" int X_sceMcGetDir(...) asm("sceMcGetDir");
extern "C" int X_sceMcGetEntSpace(...) asm("sceMcGetEntSpace");
extern "C" int X_sceMcGetInfo(...) asm("sceMcGetInfo");
extern "C" int X_sceMcGetSlotMax(...) asm("sceMcGetSlotMax");
extern "C" int X_sceMcMkdir(...) asm("sceMcMkdir");
extern "C" int X_sceMcOpen(...) asm("sceMcOpen");
extern "C" int X_sceMcRead(...) asm("sceMcRead");
extern "C" int X_sceMcRename(...) asm("sceMcRename");
extern "C" int X_sceMcSeek(...) asm("sceMcSeek");
extern "C" int X_sceMcSync(...) asm("sceMcSync");
extern "C" int X_sceMcUnformat(...) asm("sceMcUnformat");
extern "C" int X_sceMcWrite(...) asm("sceMcWrite");
extern "C" int X_strchr(...) asm("strchr");
extern "C" int X_strcmp(...) asm("strcmp");
extern "C" int X_strcpy(...) asm("strcpy");
extern "C" int X_strrchr(...) asm("strrchr");
extern "C" int X_strstr(...) asm("strstr");
extern const char D_002F7898[];
extern const char D_002F78A0[];
extern const char D_002F78C8[];

extern "C" int func_001875C0(struct McdSlot *arg0, int arg1)
{
    int i;

    if (arg1 < 0) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (arg1 == arg0[i].f0) {
            int res = (arg0[i].f4 == 0);
            if (arg0[i].f20 == 1) {
                res |= 2;
            }
            return res;
        }
    }
    return 0;
}

extern "C" void func_0018761C(int arg0, int arg1)
{
    int var_s1;
    int var_s0;

    if (arg1 >= 0) {
        var_s0 = arg0;
        var_s1 = 1;
        do {
            if (arg1 == (*(int *)(int *)((char *)(var_s0) + 0x0))) {
                X_func_00185268(var_s0, 0);
                X_func_001853CC(var_s0, 0);
                X_func_00185594(var_s0, 0);
                X_func_001856F4(var_s0, 0);
                (*(int *)(int *)((char *)(var_s0) + 0x0)) = -1;
                (*(int *)(int *)((char *)(var_s0) + 0x4)) = 1;
            }
            var_s1 -= 1;
            var_s0 += 0x3BC;
        } while (var_s1 >= 0);
    }
}


extern "C" void func_001876B0(int arg0, int arg1)
{
    int var_v1;
    int var_a0;

    var_a0 = arg0;
    if (arg1 >= 0) {
        var_v1 = 1;
        do {
            var_v1 -= 1;
            if (arg1 == (*(int *)(int *)((char *)(var_a0) + 0x0))) {
                (*(int *)(int *)((char *)(var_a0) + 0x20)) = (int) ((*(int *)(int *)((char *)(var_a0) + 0x20)) != 1);
            }
            var_a0 += 0x3BC;
        } while (var_v1 >= 0);
    }
}


extern "C" void func_001876E8(int arg0, int arg1, int arg2)
{
    int var_v1;
    int var_a0;

    var_a0 = arg0;
    if (arg1 >= 0) {
        var_v1 = 1;
        do {
            var_v1 -= 1;
            if (arg1 == M2C_FIELD(var_a0, int *, 0)) {
                M2C_FIELD(var_a0, int *, 0xBC) = arg2;
                M2C_FIELD(var_a0, int *, 0xB8) = arg2;
                M2C_FIELD(var_a0, int *, 0xB4) = 1;
                M2C_FIELD(var_a0, int *, 0xAC) = 1;
            }
            var_a0 += 0x3BC;
        } while (var_v1 >= 0);
    }
}

extern "C" int func_00187724()
{
    return X_func_00187788();
}


extern "C" void func_00187738(int arg0, int arg1)
{
    Xv_func_001879C4((void *)arg0);
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F73F0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7410);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7430);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7450);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7460);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7470);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7480);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7490);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74A0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74B0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74C0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74D0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74E0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F74F0);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7500);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7510);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7520);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7530);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7540);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7558);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7570);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7588);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F75A0);

// NON_MATCHING: 138/143 differ, 21 relocs differ, 45 edits
#ifdef NON_MATCHING
extern "C" void func_00187788(int arg0)
{
    M2C_FIELD(arg0, int *, 0) = 1;
    M2C_FIELD(arg0, int *, 4) = 2;
    M2C_FIELD(arg0, int *, 8) = 3;
    M2C_FIELD(arg0, int *, 0xC) = 4;
    M2C_FIELD(arg0, int *, 0x10) = 5;
    M2C_FIELD(arg0, int *, 0x14) = 6;
    M2C_FIELD(arg0, int *, 0x18) = 7;
    M2C_FIELD(arg0, int *, 0x1C) = 8;
    M2C_FIELD(arg0, int *, 0x20) = 9;
    M2C_FIELD(arg0, int *, 0x24) = 0xA;
    M2C_FIELD(arg0, int *, 0x28) = 0xB;
    M2C_FIELD(arg0, int *, 0x2C) = 0xC;
    M2C_FIELD(arg0, int *, 0x30) = 0xD;
    M2C_FIELD(arg0, int *, 0x34) = 0xE;
    M2C_FIELD(arg0, int *, 0x38) = 0xF;
    M2C_FIELD(arg0, int *, 0x3C) = 0x10;
    M2C_FIELD(arg0, int *, 0x40) = 0x11;
    M2C_FIELD(arg0, int *, 0x44) = 0x12;
    M2C_FIELD(arg0, int *, 0x48) = 0x13;
    M2C_FIELD(arg0, int *, 0x4C) = 0x14;
    M2C_FIELD(arg0, int *, 0x50) = 0x15;
    M2C_FIELD(arg0, int *, 0x54) = 0x16;
    M2C_FIELD(arg0, int *, 0x58) = 1;
    M2C_FIELD(arg0, int *, 0x5C) = 0;
    M2C_FIELD(arg0, int *, 0x64) = 0;
    M2C_FIELD(arg0, int *, 0xC8) = 1;
    M2C_FIELD(arg0, int *, 0x70) = 0;
    M2C_FIELD(arg0, int *, 0x74) = 0;
    M2C_FIELD(arg0, int *, 0x7C) = 0;
    M2C_FIELD(arg0, int *, 0x84) = 0;
    M2C_FIELD(arg0, int *, 0x88) = 0;
    M2C_FIELD(arg0, int *, 0x98) = 0;
    M2C_FIELD(arg0, signed char *, 0x114) = 0;
    M2C_FIELD(arg0, signed char *, 0x154) = 0;
    M2C_FIELD(arg0, int *, 0x684) = (int) "ERR_NoErr\0\0\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x688) = (int) "ERR_CmdErr\0\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x68C) = (int) "ERR_Capacity\0\0\0";
    M2C_FIELD(arg0, int *, 0x690) = (int) "ERR_NoInit\0\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x694) = (int) "ERR_NotPathName";
    M2C_FIELD(arg0, int *, 0x698) = (int) "ERR_Semapho\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x69C) = (int) "ERR_NoFormat\0\0\0";
    M2C_FIELD(arg0, int *, 0x6A0) = (int) "ERR_DeniedPermit\0\0\0\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x6A4) = (int) "ERR_NoMemoryCard\0\0\0\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x6A8) = (int) "ERR_NoFunction\0";
    M2C_FIELD(arg0, int *, 0x6AC) = (int) "ERR_NotFd\0\0\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x6B0) = (int) "ERR_NotFileName";
    M2C_FIELD(arg0, int *, 0x6B4) = (int) "ERR_NotOpen\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x6B8) = (int) "ERR_NotMemCardAccess\0\0\0";
    M2C_FIELD(arg0, int *, 0x6BC) = (int) "ERR_NotEmpty\0\0\0";
    M2C_FIELD(arg0, int *, 0x6C0) = (int) "ERR_FullDevice\0";
    M2C_FIELD(arg0, int *, 0x6C4) = (int) "ERR_ExistEntry\0";
    M2C_FIELD(arg0, int *, 0x6C8) = (int) "ERR_UpLimitHandle\0\0\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x6CC) = (int) "ERR_NotRead\0\0\0\0";
    M2C_FIELD(arg0, int *, 0x6D0) = (int) "ERR_FailReplace";
    M2C_FIELD(arg0, int *, 0x6D4) = (int) "ERR_ChangedCard";
    M2C_FIELD(arg0, int *, 0x6D8) = 0;
    M2C_FIELD(arg0, int *, 0x6DC) = 0;
    M2C_FIELD(arg0, int *, 0x6E0) = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00187788);
#endif

extern "C" void func_001879C4()
{
    X_func_00187C30();
}


extern "C" int func_001879E0(int arg0)
{
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x6E0);
    if (temp_v0 != 0) {
        Xii_heapFree__FPv(temp_v0);
        M2C_FIELD(arg0, int *, 0x6E0) = 0;
        M2C_FIELD(arg0, int *, 0x6E4) = 0;
        M2C_FIELD(arg0, int *, 0x6DC) = 0;
        M2C_FIELD(arg0, int *, 0x6D8) = 0;
    }
    return 0;
}

extern "C" int func_00187A28(int arg0)
{
    FileReader reader;
    void *buf = M2C_FIELD(arg0, void **, 0x6E0);

    if (buf != 0) {
        Xv_heapFree(buf);
        M2C_FIELD(arg0, int *, 0x6E0) = 0;
        M2C_FIELD(arg0, int *, 0x6E4) = 0;
    }
    M2C_FIELD(arg0, int *, 0x6E4) = Xc_func_001BE768(D_0029993C);
    int attr = 2;
    M2C_FIELD(arg0, void **, 0x6E0) = D_006E9800.alloc(M2C_FIELD(arg0, int *, 0x6E4), D_002F7728, 0x119, 0, attr);
    FileReadReq req;
    const char *name = D_0029993C;
    int rsize = M2C_FIELD(arg0, int *, 0x6E4);
    void *rbuf = M2C_FIELD(arg0, void **, 0x6E0);
    req.m_name = name;
    req.m_size = rsize;
    req.m_buf = rbuf;
    req.m_unk08 = 1;
    req.m_unk20 = 1;
    req.m_unk14 = 0;
    req.m_offset = 0;
    reader.func_001BE524(&req, 0);
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7728);

extern "C" int func_00187B10(int arg0, int arg1)
{
    BedPfh pfh;
    if (M2C_FIELD(arg0, void **, 0x6E0) == 0) {
        func_00187A28(arg0);
    }
    pfh.setTop(M2C_FIELD(arg0, void **, 0x6E0));
    int idx = pfh.getIndex(D_002998D0[arg1]);
    if (idx >= 0) {
        int off = (arg1 * 4) + 0x6D0;
        char *p1 = (char *)arg0 + 0xC;
        *(void **)(p1 + off) = pfh.getFileTop(idx);
        char *p2 = (char *)arg0 + 8;
        *(int *)(p2 + off) = pfh.getFileSize(idx);
    }
    return 0;
}

extern "C" void func_00187C30()
{
    X_func_001879E0();
}


extern "C" void func_00187C4C(int arg0)
{
    switch (M2C_FIELD(arg0, int *, 0x5C)) {
    case 0:
        break;
    case 1:
        if (X7C4C_func_00187E44(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 2:
        if (X7C4C_func_001880CC(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 3:
        if (X7C4C_func_001881C0(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 4:
        if (X7C4C_func_001883C0(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 5:
        if (X7C4C_func_001885D4(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 6:
        if (X7C4C_func_0018894C(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 7:
        if (X7C4C_func_00188BFC(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 8:
        if (X7C4C_func_00188CD4(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 9:
        if (X7C4C_func_00188EC0(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 10:
        if (X7C4C_func_00189068(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 11:
        if (X7C4C_func_001892B0(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 12:
        if (X7C4C_func_001894D4(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 13:
        if (X7C4C_func_00189718(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 14:
        if (X7C4C_func_0018993C(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 15:
        if (X7C4C_func_00189B7C(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 16:
        if (X7C4C_func_00189D94(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 17:
        if (X7C4C_func_00189F58(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 18:
        if (X7C4C_func_0018A50C(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 19:
        if (X7C4C_func_0018AD0C(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 20:
        if (X7C4C_func_0018ADE0(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 21:
        if (X7C4C_func_0018B12C(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    case 22:
        if (X7C4C_func_0018B2BC(arg0) == 1) {
            M2C_FIELD(arg0, int *, 0x5C) = 0;
            M2C_FIELD(arg0, int *, 0x60) = 0;
        }
        break;
    }
}

extern "C" int func_00187E00(int arg0)
{
    return (*(int *)(int *)((char *)(arg0) + 0x64));
}


extern "C" int func_00187E08(int *arg0, int arg1)
{
    int *p = &arg0[arg1];
    int var_a1 = 1;

    if (M2C_FIELD(arg0, int *, 0x5C) == 0) {
        M2C_FIELD(arg0, int *, 0x5C) = *p;
        M2C_FIELD(arg0, int *, 0x64) = 1;
        M2C_FIELD(arg0, int *, 0x68) = 0;
    } else {
        var_a1 = 6;
    }
    return var_a1;
}

extern "C" void func_00187E3C(void) {
}

extern "C" int func_00187E44(int arg0)
{
    int temp_a0;
    int temp_a2;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_a0;
    int var_s3;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s3 = 0;
    switch (temp_v1) {                              
    case 0:                                         
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:                                         
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = X_sceMcGetInfo(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), arg0 + 0x7C, arg0 + 0x84, arg0 + 0x88);
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -210: M2C_FIELD(arg0, int *, 0x58) = 5; break;
        case -200: M2C_FIELD(arg0, int *, 0x58) = 2; break;
        case -100: M2C_FIELD(arg0, int *, 0x58) = 4; break;
        default: M2C_FIELD(arg0, int *, 0x58) = 2; break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:                                         
        var_s3 = 1;
        break;
    case 4:                                         
        temp_v0 = X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0);
        switch (temp_v0) {                          
        case 0:                                     
            break;
        case 1:                                     
            temp_a2 = M2C_FIELD(arg0, int *, 0xD0);
            switch (temp_a2) {
            case 0:
                if (M2C_FIELD(arg0, int *, 0x88) == 0) {
                    if (M2C_FIELD(arg0, int *, 0xBC) < 8) {
                        M2C_FIELD(arg0, int *, 0x60) = 3;
                    } else {
                        M2C_FIELD(arg0, int *, 0x64) = 2;
                        M2C_FIELD(arg0, int *, 0x60) = 5;
                        M2C_FIELD(arg0, int *, 0x58) = 7;
                        M2C_FIELD(arg0, int *, 0x90) = 0;
                    }
                } else {
                    M2C_FIELD(arg0, int *, 0x64) = 2;
                    M2C_FIELD(arg0, int *, 0x60) = 5;
                    M2C_FIELD(arg0, int *, 0x58) = temp_v0;
                }
                break;
            case -1:
                M2C_FIELD(arg0, int *, 0x64) = 2;
                        M2C_FIELD(arg0, int *, 0x60) = 5;
                        M2C_FIELD(arg0, int *, 0x58) = 21;
                        M2C_FIELD(arg0, int *, 0x90) = 0;
                break;
            case -2:
                if (M2C_FIELD(arg0, int *, 0xBC) < 8) {
                    M2C_FIELD(arg0, int *, 0x60) = 3;
                } else {
                    M2C_FIELD(arg0, int *, 0x64) = 2;
                        M2C_FIELD(arg0, int *, 0x60) = 5;
                        M2C_FIELD(arg0, int *, 0x58) = 7;
                        M2C_FIELD(arg0, int *, 0x90) = 0;
                }
                break;
            case -5:
                M2C_FIELD(arg0, int *, 0x64) = 2;
                        M2C_FIELD(arg0, int *, 0x60) = 5;
                        M2C_FIELD(arg0, int *, 0x58) = 8;
                        M2C_FIELD(arg0, int *, 0x90) = 0;
                break;
            default:
                M2C_FIELD(arg0, int *, 0x64) = 2;
                        M2C_FIELD(arg0, int *, 0x60) = 5;
                        M2C_FIELD(arg0, int *, 0x58) = 14;
                        M2C_FIELD(arg0, int *, 0x90) = 0;
                break;
            }
            temp_v1_2 = M2C_FIELD(arg0, int *, 0x7C);
            switch (temp_v1_2) {                    
            case 0:
            case 2:                                 
                break;
            case 1:
                M2C_FIELD(arg0, int *, 0x58) = 0xE;
                break;
            case 3:                                 
                M2C_FIELD(arg0, int *, 0x58) = 0xE;
                break;
            }
            break;
        case -1:                                    
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x90) = 0;
            break;
        }
        break;
    }
    int one = 1;
    return M2C_FIELD(arg0, int *, 0x64) == one ? var_s3 : one;
}

extern "C" int func_001880CC(int arg0)
{
    int temp_a0;
    int temp_v1;
    int var_s2;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s2 = 0;
    switch (temp_v1) {                              
    case 0:                                         
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:                                         
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = X_sceMcGetSlotMax(M2C_FIELD(arg0, int *, 0x70));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        if (temp_a0 >= 0) {
            M2C_FIELD(arg0, int *, 0x58) = 1;
            M2C_FIELD(arg0, int *, 0x64) = 2;
            M2C_FIELD(arg0, int *, 0x78) = temp_a0;
            M2C_FIELD(arg0, int *, 0x60) = 5;
        } else {
            if (temp_a0 == -100) {
                M2C_FIELD(arg0, int *, 0x60) = 5;
                M2C_FIELD(arg0, int *, 0x58) = 4;
            } else if (temp_a0 == -200) {
                M2C_FIELD(arg0, int *, 0x60) = 5;
                M2C_FIELD(arg0, int *, 0x58) = 6;
            } else {
                M2C_FIELD(arg0, int *, 0x60) = 5;
                M2C_FIELD(arg0, int *, 0x58) = 2;
            }
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:                                         
        var_s2 = 1;
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s2 : 1;
}

// NON_MATCHING: 8/128 differ, 6 edits
#ifdef NON_MATCHING
extern "C" int F881_space(...) asm("sceMcGetEntSpace");
extern "C" int F881_sync(int, int *, int *) asm("sceMcSync");
extern "C" int func_001881C0(int arg0)
{
    int done = 0;
    switch (M2C_FIELD(arg0, int *, 0x60)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3: {
        M2C_FIELD(arg0, int *, 0x60) = 5;
        int result = F881_space(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), arg0 + 0x114);
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = result;
        switch (result) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -210:
            M2C_FIELD(arg0, int *, 0x58) = 5;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) += 1;
        break;
    }
    case 4: {
        int *out = (int *)(arg0 + 0xD0);
        int sync = F881_sync(M2C_FIELD(arg0, int *, 0xC8), (int *)(arg0 + 0xCC), out);
        switch (sync) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            if (*out >= 0) {
                M2C_FIELD(arg0, int *, 0x8C) = *out;
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
            } else {
            if (*out == -2) {
                register int error PS2_REG("$4") = 7;
                M2C_FIELD(arg0, int *, 0x58) = error;
                if (__builtin_expect(M2C_FIELD(arg0, int *, 0xBC) >= 8, 1)) break;
                {
                    M2C_FIELD(arg0, int *, 0x60) = 3;
                    M2C_FIELD(arg0, int *, 0x64) = 1;
                    M2C_FIELD(arg0, int *, 0x58) = 1;
                }
                break;
            }
            if (*out == -5) {
                M2C_FIELD(arg0, int *, 0x58) = 8;
                break;
            }
            if (*out <= -10) {
                M2C_FIELD(arg0, int *, 0x58) = 9;
            }
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 10;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    case 5:
        done = 1;
        break;
    }
    return M2C_FIELD(arg0, int *, 0x64) == 1 ? done : 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001881C0);
#endif

// NON_MATCHING: 1/133 differ, 1 edits
#ifdef NON_MATCHING
extern "C" int F883_chdir(...) asm("sceMcChdir");
extern "C" int F883_sync(int, int *, int *) asm("sceMcSync");
extern "C" int func_001883C0(int arg0)
{
    int done = 0;
    int status;
    switch (M2C_FIELD(arg0, int *, 0x60)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3: {
        M2C_FIELD(arg0, int *, 0x60) = 5;
        int result = F883_chdir(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), arg0 + 0x114, arg0 + 0x154);
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = result;
        switch (result) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -210:
            M2C_FIELD(arg0, int *, 0x58) = 5;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) += 1;
        break;
    }
    case 4: {
        int *out = (int *)(arg0 + 0xD0);
        int sync = F883_sync(M2C_FIELD(arg0, int *, 0xC8), (int *)(arg0 + 0xCC), out);
        switch (sync) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            if (*out == 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
                break;
            }
            if (*out == -2) {
                register int error PS2_REG("$4") = 7;
                M2C_FIELD(arg0, int *, 0x58) = error;
                if (M2C_FIELD(arg0, int *, 0xBC) < 8) {
                    M2C_FIELD(arg0, int *, 0x60) = 3;
                    M2C_FIELD(arg0, int *, 0x64) = 1;
                    M2C_FIELD(arg0, int *, 0x58) = 1;
                } else {
                    status = M2C_FIELD(arg0, int *, 0x64);
                    goto finish;
                }
                break;
            }
            if (*out == -4) {
                M2C_FIELD(arg0, int *, 0x58) = 5;
                break;
            }
            if (*out == -5) {
                M2C_FIELD(arg0, int *, 0x58) = 8;
                break;
            }
            if (*out <= -10) {
                M2C_FIELD(arg0, int *, 0x58) = 9;
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 10;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    case 5:
        done = 1;
        break;
    }
    status = M2C_FIELD(arg0, int *, 0x64);
finish:
    return status == 1 ? done : 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001883C0);
#endif

// NON_MATCHING: 50/121 differ (size 0x1E4, game 0x1EC), 26 edits
#ifdef NON_MATCHING
extern "C" int F885_sync(int, int *, int *) asm("sceMcSync");
extern "C" int func_001885D4(int arg0)
{
    int done = 0;
    switch (M2C_FIELD(arg0, int *, 0x60)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3: {
        M2C_FIELD(arg0, int *, 0x60) = 5;
        int result = X_sceMcClose(M2C_FIELD(arg0, int *, 0x94));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = result;
        switch (result) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) += 1;
        break;
    }
    case 4: {
        int *out = (int *)(arg0 + 0xD0);
        int sync = F885_sync(M2C_FIELD(arg0, int *, 0xC8), (int *)(arg0 + 0xCC), out);
        switch (sync) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            if (*out == 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
                break;
            }
            if (*out == -2) {
                M2C_FIELD(arg0, int *, 0x58) = 7;
                if (M2C_FIELD(arg0, int *, 0xBC) < 8) {
                    M2C_FIELD(arg0, int *, 0x60) = 3;
                    M2C_FIELD(arg0, int *, 0x58) = 1;
                    M2C_FIELD(arg0, int *, 0x64) = 1;
                }
                break;
            }
            if (*out == -4) {
                M2C_FIELD(arg0, int *, 0x58) = 11;
                break;
            }
            if (*out == -5) {
                M2C_FIELD(arg0, int *, 0x58) = 8;
                break;
            }
            if (*out <= -10) {
                M2C_FIELD(arg0, int *, 0x58) = 9;
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 10;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    case 5:
        done = 1;
        break;
    }
    return M2C_FIELD(arg0, int *, 0x64) == 1 ? done : 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001885D4);
#endif

extern "C" int func_001887C0(const McdMgr *arg0, int arg1, const char *arg2, char *arg3)
{
    char buf[64];
    if (arg1 >= arg0->m_num) {
        return -1;
    }
    const char *slash = X_strrchr_ci(arg2, '/');
    if (slash != 0) {
        X_strcpy_cc(buf, slash + 1);
    } else {
        X_strcpy_cc(buf, arg2);
    }
    char *star = X_strchr_ci(buf, '*');
    if (star == 0) {
        return -1;
    }
    *star = '\0';
    for (int i = arg1; i < arg0->m_num; i++) {
        if (Xcc_strstr(arg0->getName(i), buf) != 0) {
            arg1 = i;
            if (slash != 0) {
                X_strcpy_cc(buf, arg2);
                X_strcpy_cc((char *)X_strrchr_ci(buf, '/') + 1, arg0->getName(arg1));
                X_strcpy_cc(arg3, buf);
            } else {
                X_strcpy_cc(arg3, arg0->getName(arg1));
            }
            break;
        }
    }
    return arg1 + 1;
}

// NON_MATCHING: 80/171 differ (size 0x2AC, game 0x2B0), 27 edits
#ifdef NON_MATCHING
extern "C" int F889_sync(int, int *, int *) asm("sceMcSync");
extern "C" int func_0018894C(int arg0)
{
    int temp_a0_2;
    int temp_a1;
    int temp_a2_2;
    int temp_v0;
    register int temp_v0_2 PS2_REG("$4");
    int var_s2;
    int var_v0;
    int temp_a0;
    int temp_a2;
    unsigned int temp_v1;

    temp_v1 = M2C_FIELD(arg0, unsigned int *, 0x60);
    var_s2 = 0;
    switch (temp_v1) {                              
    case 0:                                         
        M2C_FIELD(arg0, unsigned int *, 0x60) = 1U;
        M2C_FIELD(arg0, int *, 0xB8) = -1;
        if ((X_strchr(arg0 + 0x114, 0x2A) != 0) && (M2C_FIELD(arg0, int *, 0x90) > 0)) {
            M2C_FIELD(arg0, int *, 0xB8) = 0;
        }
        
    case 1:                                         
        temp_a1 = M2C_FIELD(arg0, int *, 0xB8);
        temp_a2 = arg0 + 0x114;
        temp_a0 = arg0 + 0xD4;
        if (temp_a1 == -1) {
            X_strcpy(temp_a0, temp_a2, temp_a2);
            goto block_9;
        }
        temp_v0 = X_func_001887C0(arg0, temp_a1, temp_a2, temp_a0);
        M2C_FIELD(arg0, int *, 0xB8) = temp_v0;
        if (temp_v0 < 0) {
            M2C_FIELD(arg0, int *, 0x64) = 2;
            M2C_FIELD(arg0, unsigned int *, 0x60) = 5U;
            M2C_FIELD(arg0, int *, 0xD0) = 0;
        } else {
block_9:
            M2C_FIELD(arg0, int *, 0xBC) = 0;
            M2C_FIELD(arg0, unsigned int *, 0x60) = 3U;
        case 3:                                     
            M2C_FIELD(arg0, unsigned int *, 0x60) = 5U;
            temp_a0_2 = X_sceMcDelete(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), arg0 + 0xD4);
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x6C) = temp_a0_2;
        switch (temp_a0_2) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -210: M2C_FIELD(arg0, int *, 0x58) = 5; break;
        case -200: M2C_FIELD(arg0, int *, 0x58) = 2; break;
        case -100: M2C_FIELD(arg0, int *, 0x58) = 4; break;
        default: M2C_FIELD(arg0, int *, 0x58) = 2; break;
        }
            M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        }
        break;
    case 4:                                         
        temp_v0_2 = F889_sync(M2C_FIELD(arg0, int *, 0xC8), (int *)(arg0 + 0xCC), (int *)(arg0 + 0xD0));
        switch (temp_v0_2) {                        
        case 0:                                     
            break;
        case 1:                                     
            M2C_FIELD(arg0, int *, 0x64) = 3;
            temp_a2_2 = M2C_FIELD(arg0, int *, 0xD0);
            if (temp_a2_2 == 0) {
                M2C_FIELD(arg0, unsigned int *, 0x60) = 5U;
                if (M2C_FIELD(arg0, int *, 0xB8) != -1) {
                    M2C_FIELD(arg0, int *, 0x64) = temp_v0_2;
                } else {
                    M2C_FIELD(arg0, int *, 0x64) = 2;
                }
                break;
            }
            if (temp_a2_2 == -2) {
                M2C_FIELD(arg0, int *, 0x58) = 7;
                if (M2C_FIELD(arg0, int *, 0xBC) < 8) {
                    M2C_FIELD(arg0, unsigned int *, 0x60) = 3U;
                    M2C_FIELD(arg0, int *, 0x58) = temp_v0_2;
                    M2C_FIELD(arg0, int *, 0x64) = temp_v0_2;
                }
                break;
            }
            if (temp_a2_2 == -5) {
                M2C_FIELD(arg0, int *, 0x58) = 8;
                break;
            }
            if (temp_a2_2 == -4) {
                M2C_FIELD(arg0, int *, 0x58) = 12;
                break;
            }
            if (temp_a2_2 < -9) {
                M2C_FIELD(arg0, int *, 0x58) = 9;
            }
            break;
        case -1:                                    
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, unsigned int *, 0x60) = 5U;
            break;
        }
        break;
    case 5:                                         
        if (M2C_FIELD(arg0, int *, 0xB8) == -1) {
            var_s2 = 1;
        } else {
            M2C_FIELD(arg0, unsigned int *, 0x60) = 1U;
        }
        break;
    }
    int one = 1;
    return M2C_FIELD(arg0, int *, 0x64) == one ? var_s2 : one;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018894C);
#endif

extern "C" int func_00188BFC(int arg0)
{
    int temp_a0;
    int temp_v1;
    int var_s2;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s2 = 0;
    switch (temp_v1) {                              
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = X_sceMcDelete(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), arg0 + 0x114);
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        if (temp_a0 == 1) {
            M2C_FIELD(arg0, int *, 0x58) = temp_a0;
            M2C_FIELD(arg0, int *, 0x64) = 2;
            M2C_FIELD(arg0, int *, 0x60) = 5;
        } else {
            M2C_FIELD(arg0, int *, 0x58) = 2;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:
        var_s2 = 1;
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s2 : 1;
}

// NON_MATCHING: 42/121 differ (size 0x1E4, game 0x1EC), 14 edits
#ifdef NON_MATCHING
extern "C" int F8CD_sync(int, int *, int *) asm("sceMcSync");
extern "C" int func_00188CD4(int arg0)
{
    int done = 0;
    switch (M2C_FIELD(arg0, int *, 0x60)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3: {
        M2C_FIELD(arg0, int *, 0x60) = 5;
        int result = X_sceMcFlush(M2C_FIELD(arg0, int *, 0x94));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = result;
        switch (result) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) += 1;
        break;
    }
    case 4: {
        int *out = (int *)(arg0 + 0xD0);
        int sync = F8CD_sync(M2C_FIELD(arg0, int *, 0xC8), (int *)(arg0 + 0xCC), out);
        switch (sync) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            if (*out == 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
                break;
            }
            if (*out == -2) {
                register int error PS2_REG("$4") = 7;
                M2C_FIELD(arg0, int *, 0x58) = error;
                if (M2C_FIELD(arg0, int *, 0xBC) >= 8) break;
                {
                    M2C_FIELD(arg0, int *, 0x60) = 3;
                    M2C_FIELD(arg0, int *, 0x64) = 1;
                    M2C_FIELD(arg0, int *, 0x58) = 1;
                }
                break;
            }
            if (*out == -4) {
                M2C_FIELD(arg0, int *, 0x58) = 13;
                break;
            }
            if (*out == -5) {
                M2C_FIELD(arg0, int *, 0x58) = 14;
                break;
            }
            if (*out <= -10) {
                M2C_FIELD(arg0, int *, 0x58) = 9;
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 10;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    case 5:
        done = 1;
        break;
    }
    return M2C_FIELD(arg0, int *, 0x64) == 1 ? done : 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00188CD4);
#endif

// NON_MATCHING: 3/106 differ, 2 edits
#ifdef NON_MATCHING
extern "C" int func_00188EC0(int arg0)
{
    int temp_a0;
    int var_s3;

    var_s3 = 0;
    switch (M2C_FIELD(arg0, int *, 0x60)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = X_sceMcFormat(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = M2C_FIELD(arg0, int *, 0xBC) + 1;
        break;
    case 5:
        var_s3 = 1;
        break;
    case 4:
        switch (X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0)) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            if (M2C_FIELD(arg0, int *, 0xD0) == 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
            } else if (M2C_FIELD(arg0, int *, 0xD0) == -5) {
                M2C_FIELD(arg0, int *, 0x58) = 0xE;
            } else if (M2C_FIELD(arg0, int *, 0xD0) <= -10) {
                M2C_FIELD(arg0, int *, 0x58) = 9;
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            M2C_FIELD(arg0, int *, 0x64) = 3;
            break;
        }
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s3 : 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00188EC0);
#endif

// NON_MATCHING: 48/144 differ (size 0x240, game 0x248), 15 edits
#ifdef NON_MATCHING
extern "C" int func_00189068(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_s3;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s3 = 0;
    switch (temp_v1) {                              
    case 0:                                         
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0x90) = 0;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:                                         
        M2C_FIELD(arg0, int *, 0x90) = 0;
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = X_sceMcGetDir(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), arg0 + 0x114, M2C_FIELD(arg0, int *, 0x98), 0x13, arg0 + 0x1C0);
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -210: M2C_FIELD(arg0, int *, 0x58) = 5; break;
        case -200: M2C_FIELD(arg0, int *, 0x58) = 2; break;
        case -100: M2C_FIELD(arg0, int *, 0x58) = 4; break;
        default: M2C_FIELD(arg0, int *, 0x58) = 2; break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:                                         
        var_s3 = 1;
        break;
    case 4:                                         
        temp_v0 = X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0);
        switch (temp_v0) {                          
        case 0:                                     
            break;
        case 1:                                     
            M2C_FIELD(arg0, int *, 0x64) = 3;
            temp_v1_2 = M2C_FIELD(arg0, int *, 0xD0);
            if (temp_v1_2 != 0) {
                if (temp_v1_2 > 0) {
                    M2C_FIELD(arg0, int *, 0x64) = 2;
                    M2C_FIELD(arg0, int *, 0x60) = 5;
                    M2C_FIELD(arg0, int *, 0x90) = (int) M2C_FIELD(arg0, int *, 0xD0);
                } else {
                    if (temp_v1_2 == -2) {
                        M2C_FIELD(arg0, int *, 0x58) = 7;
                        if (M2C_FIELD(arg0, int *, 0xBC) < 8) {
                            M2C_FIELD(arg0, int *, 0x60) = 3;
                            M2C_FIELD(arg0, int *, 0x64) = temp_v0;
                            M2C_FIELD(arg0, int *, 0x58) = temp_v0;
                        }
                        break;
                    }
                    if (temp_v1_2 == -4) {
block_37:
                        M2C_FIELD(arg0, int *, 0x58) = 5;
                        break;
                    }
                    if (temp_v1_2 == -5) {
                        M2C_FIELD(arg0, int *, 0x58) = 8;
                        break;
                    } else if (temp_v1_2 == -6) {
                        M2C_FIELD(arg0, int *, 0x58) = 15;
                    } else if (temp_v1_2 < -9) {
                        M2C_FIELD(arg0, int *, 0x58) = 9;
                    }
                }
            } else {
                goto block_37;
            }
            break;
        case -1:                                    
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    int one = 1;
    return M2C_FIELD(arg0, int *, 0x64) == one ? var_s3 : one;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00189068);
#endif

// NON_MATCHING: 12/137 differ, 10 edits
#ifdef NON_MATCHING
extern "C" int F892_mkdir(...) asm("sceMcMkdir");
extern "C" int func_001892B0(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_s3;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s3 = 0;
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = F892_mkdir(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), arg0 + 0x114);
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        case -210:
            M2C_FIELD(arg0, int *, 0x58) = 5;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:
        var_s3 = 1;
        break;
    case 4:
        temp_v0 = X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0);
        switch (temp_v0) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            temp_v1_2 = M2C_FIELD(arg0, int *, 0xD0);
            if (temp_v1_2 == 0) {
                M2C_FIELD(arg0, int *, 0x60) = 5;
                M2C_FIELD(arg0, int *, 0x64) = 2;
            } else {
                if (temp_v1_2 == -2) {
                    register int error PS2_REG("$4") = 7;
                    M2C_FIELD(arg0, int *, 0x58) = error;
                    if (!__builtin_expect(M2C_FIELD(arg0, int *, 0xBC) >= 8, 1)) {
                        M2C_FIELD(arg0, int *, 0x60) = 3;
                        M2C_FIELD(arg0, int *, 0x64) = 1;
                        M2C_FIELD(arg0, int *, 0x58) = 1;
                    }
                } else if (temp_v1_2 == -3) {
                    M2C_FIELD(arg0, int *, 0x58) = 16;
                } else if (temp_v1_2 == -4) {
                    M2C_FIELD(arg0, int *, 0x58) = 17;
                } else if (temp_v1_2 == -5) {
                    M2C_FIELD(arg0, int *, 0x58) = 8;
                } else if (temp_v1_2 <= -10) {
                    M2C_FIELD(arg0, int *, 0x58) = 9;
                }
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s3 : 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_001892B0);
#endif

extern "C" int func_001894D4(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_s3;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s3 = 0;
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = F894_open(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), arg0 + 0x114, M2C_FIELD(arg0, int *, 0x9C));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -210:
            M2C_FIELD(arg0, int *, 0x58) = 5;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:
        var_s3 = 1;
        break;
    case 4:
        temp_v0 = X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0);
        switch (temp_v0) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            temp_v1_2 = M2C_FIELD(arg0, int *, 0xD0);
            if (temp_v1_2 >= 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
                M2C_FIELD(arg0, int *, 0x94) = (int) M2C_FIELD(arg0, int *, 0xD0);
            } else {
                if (temp_v1_2 == -2) {
                    register int retry PS2_REG("$2") = M2C_FIELD(arg0, int *, 0xBC);
                    M2C_FIELD(arg0, int *, 0x58) = 7;
                    if (retry < 8) {
                        M2C_FIELD(arg0, int *, 0x60) = 3;
                        M2C_FIELD(arg0, int *, 0x64) = 1;
                        M2C_FIELD(arg0, int *, 0x58) = 1;
                    } else {
                        __asm__("" ::: "memory");
                    }
                } else if (temp_v1_2 == -3) {
                    M2C_FIELD(arg0, int *, 0x58) = 16;
                } else if (temp_v1_2 == -4) {
                    M2C_FIELD(arg0, int *, 0x58) = 5;
                } else if (temp_v1_2 == -5) {
                    M2C_FIELD(arg0, int *, 0x58) = 8;
                } else if (temp_v1_2 == -7) {
                    M2C_FIELD(arg0, int *, 0x58) = 18;
                } else if (temp_v1_2 <= -10) {
                    M2C_FIELD(arg0, int *, 0x58) = 9;
                }
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s3 : 1;
}

extern "C" int func_00189718(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_s3;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s3 = 0;
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = F897_read(M2C_FIELD(arg0, int *, 0x94), M2C_FIELD(arg0, int *, 0xB4), M2C_FIELD(arg0, int *, 0xB0));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:
        var_s3 = 1;
        break;
    case 4:
        temp_v0 = X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0);
        switch (temp_v0) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            temp_v1_2 = M2C_FIELD(arg0, int *, 0xD0);
            if (temp_v1_2 >= 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
                M2C_FIELD(arg0, int *, 0xA0) = (int) M2C_FIELD(arg0, int *, 0xD0);
            } else {
                if (temp_v1_2 == -2) {
                    register int retry PS2_REG("$2") = M2C_FIELD(arg0, int *, 0xBC);
                    M2C_FIELD(arg0, int *, 0x58) = 7;
                    if (retry < 8) {
                        M2C_FIELD(arg0, int *, 0x60) = 3;
                        M2C_FIELD(arg0, int *, 0x64) = 1;
                        M2C_FIELD(arg0, int *, 0x58) = 1;
                    } else {
                        __asm__("" ::: "memory");
                    }
                } else if (temp_v1_2 == -3) {
                    M2C_FIELD(arg0, int *, 0x58) = 19;
                } else if (temp_v1_2 == -4) {
                    M2C_FIELD(arg0, int *, 0x58) = 13;
                } else if (temp_v1_2 == -5) {
                    M2C_FIELD(arg0, int *, 0x58) = 8;
                } else if (temp_v1_2 == -7) {
                    M2C_FIELD(arg0, int *, 0x58) = 18;
                } else if (temp_v1_2 <= -10) {
                    M2C_FIELD(arg0, int *, 0x58) = 9;
                }
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s3 : 1;
}

extern "C" int func_0018993C(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_s3;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s3 = 0;
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3: {
        M2C_FIELD(arg0, int *, 0x60) = 5;
        const char *name = (const char *)(arg0 + 0x154);
        const char *oldName = (const char *)(arg0 + 0x114);
        const char *part = F899_strrchr(name, '/');
        if (part) {
            F899_strcpy((char *)(arg0 + 0xD4), part + 1);
        } else {
            F899_strcpy((char *)(arg0 + 0xD4), name);
        }
        temp_a0 = F899_rename(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74), oldName, arg0 + 0xD4);
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -210:
            M2C_FIELD(arg0, int *, 0x58) = 5;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    }
    case 5:
        var_s3 = 1;
        break;
    case 4:
        temp_v0 = X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0);
        switch (temp_v0) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            temp_v1_2 = M2C_FIELD(arg0, int *, 0xD0);
            if (temp_v1_2 == 0) {
                register int ready PS2_REG("$2") = 2;
                register int finished PS2_REG("$3") = 5;
                M2C_FIELD(arg0, int *, 0x64) = ready;
                __asm__("" : : "r"(ready), "r"(finished) : "memory");
                M2C_FIELD(arg0, int *, 0x60) = finished;
            } else {
                if (temp_v1_2 == -2) {
                    register int retry PS2_REG("$2") = M2C_FIELD(arg0, int *, 0xBC);
                    register int error PS2_REG("$4") = 7;
                    M2C_FIELD(arg0, int *, 0x58) = error;
                    if (retry < 8) {
                        M2C_FIELD(arg0, int *, 0x60) = 3;
                        M2C_FIELD(arg0, int *, 0x64) = 1;
                        M2C_FIELD(arg0, int *, 0x58) = 1;
                    } else {
                        __asm__("" ::: "memory");
                    }
                } else if (temp_v1_2 == -4) {
                    M2C_FIELD(arg0, int *, 0x58) = 12;
                } else if (temp_v1_2 == -5) {
                    M2C_FIELD(arg0, int *, 0x58) = 14;
                } else if (temp_v1_2 <= -10) {
                    M2C_FIELD(arg0, int *, 0x58) = 9;
                }
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s3 : 1;
}

// NON_MATCHING: 8/134 differ, 6 edits
#ifdef NON_MATCHING
extern "C" int func_00189B7C(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_s3;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s3 = 0;
    switch (temp_v1) {                              
    case 0:                                         
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:                                         
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = X_sceMcSeek(M2C_FIELD(arg0, int *, 0x94), M2C_FIELD(arg0, int *, 0xA8), M2C_FIELD(arg0, int *, 0xAC));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        case -210:
            M2C_FIELD(arg0, int *, 0x58) = 5;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:                                         
        var_s3 = 1;
        break;
    case 4:                                         
        temp_v0 = X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0);
        switch (temp_v0) {                          
        case 0:                                     
            break;
        case 1:                                     
            M2C_FIELD(arg0, int *, 0x64) = 3;
            temp_v1_2 = M2C_FIELD(arg0, int *, 0xD0);
            if (temp_v1_2 >= 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
                M2C_FIELD(arg0, int *, 0xA4) = (int) M2C_FIELD(arg0, int *, 0xD0);
            } else {
                if (temp_v1_2 == -2) {
                    do {
                    M2C_FIELD(arg0, int *, 0x58) = 7;
                    if (!__builtin_expect(M2C_FIELD(arg0, int *, 0xBC) >= 8, 1)) {
                        M2C_FIELD(arg0, int *, 0x60) = 3;
                        M2C_FIELD(arg0, int *, 0x64) = 1;
                        M2C_FIELD(arg0, int *, 0x58) = 1;
                    }
                    } while (0);
                } else if (temp_v1_2 == -4) {
                    M2C_FIELD(arg0, int *, 0x58) = 13;
                } else if (temp_v1_2 == -5) {
                    M2C_FIELD(arg0, int *, 0x58) = 14;
                } else if (temp_v1_2 <= -10) {
                    M2C_FIELD(arg0, int *, 0x58) = 9;
                }
            }
            break;
        case -1:                                    
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s3 : 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_00189B7C);
#endif

extern "C" int func_00189D94(int arg0)
{
    int temp_a0;
    int var_s3;

    var_s3 = 0;
    switch (M2C_FIELD(arg0, int *, 0x60)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = X_sceMcUnformat(M2C_FIELD(arg0, int *, 0x70), M2C_FIELD(arg0, int *, 0x74));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        case -210:
            M2C_FIELD(arg0, int *, 0x58) = 5;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = M2C_FIELD(arg0, int *, 0xBC) + 1;
        break;
    case 4:
        switch (X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0)) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            if (M2C_FIELD(arg0, int *, 0xD0) == 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
            } else if (M2C_FIELD(arg0, int *, 0xD0) == -5) {
                M2C_FIELD(arg0, int *, 0x58) = 0xE;
            } else if (M2C_FIELD(arg0, int *, 0xD0) <= -10) {
                M2C_FIELD(arg0, int *, 0x58) = 9;
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    case 5:
        var_s3 = 1;
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s3 : 1;
}

extern "C" int func_00189F58(int arg0)
{
    int temp_a0;
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int var_s3;
    int var_v0;

    temp_v1 = M2C_FIELD(arg0, int *, 0x60);
    var_s3 = 0;
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 3;
        M2C_FIELD(arg0, int *, 0xBC) = 0;
    case 3:
        M2C_FIELD(arg0, int *, 0x60) = 5;
        temp_a0 = F89F_write(M2C_FIELD(arg0, int *, 0x94), M2C_FIELD(arg0, int *, 0xB4), M2C_FIELD(arg0, int *, 0xB0));
        M2C_FIELD(arg0, int *, 0x64) = 3;
        M2C_FIELD(arg0, int *, 0x6C) = temp_a0;
        switch (temp_a0) {
        case 0:
            M2C_FIELD(arg0, int *, 0x60) = 4;
            M2C_FIELD(arg0, int *, 0x64) = 1;
            M2C_FIELD(arg0, int *, 0x58) = 1;
            break;
        case -100:
            M2C_FIELD(arg0, int *, 0x58) = 4;
            break;
        case -200:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        default:
            M2C_FIELD(arg0, int *, 0x58) = 2;
            break;
        }
        M2C_FIELD(arg0, int *, 0xBC) = (int) (M2C_FIELD(arg0, int *, 0xBC) + 1);
        break;
    case 5:
        var_s3 = 1;
        break;
    case 4:
        temp_v0 = X_sceMcSync(M2C_FIELD(arg0, int *, 0xC8), arg0 + 0xCC, arg0 + 0xD0);
        switch (temp_v0) {
        case 0:
            break;
        case 1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            temp_v1_2 = M2C_FIELD(arg0, int *, 0xD0);
            if (temp_v1_2 >= 0) {
                M2C_FIELD(arg0, int *, 0x64) = 2;
                M2C_FIELD(arg0, int *, 0x60) = 5;
                M2C_FIELD(arg0, int *, 0xA0) = (int) M2C_FIELD(arg0, int *, 0xD0);
            } else {
                if (temp_v1_2 == -2) {
                    register int retry PS2_REG("$2") = M2C_FIELD(arg0, int *, 0xBC);
                    M2C_FIELD(arg0, int *, 0x58) = 7;
                    if (retry < 8) {
                        M2C_FIELD(arg0, int *, 0x60) = 3;
                        M2C_FIELD(arg0, int *, 0x64) = 1;
                        M2C_FIELD(arg0, int *, 0x58) = 1;
                    } else {
                        __asm__("" ::: "memory");
                    }
                } else if (temp_v1_2 == -3) {
                    M2C_FIELD(arg0, int *, 0x58) = 19;
                } else if (temp_v1_2 == -4) {
                    M2C_FIELD(arg0, int *, 0x58) = 13;
                } else if (temp_v1_2 == -5) {
                    M2C_FIELD(arg0, int *, 0x58) = 8;
                } else if (temp_v1_2 == -8) {
                    M2C_FIELD(arg0, int *, 0x58) = 20;
                } else if (temp_v1_2 <= -10) {
                    M2C_FIELD(arg0, int *, 0x58) = 9;
                }
            }
            break;
        case -1:
            M2C_FIELD(arg0, int *, 0x64) = 3;
            M2C_FIELD(arg0, int *, 0x58) = 0xA;
            M2C_FIELD(arg0, int *, 0x60) = 5;
            break;
        }
        break;
    }
    return (M2C_FIELD(arg0, int *, 0x64) == 1) ? var_s3 : 1;
}

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7800);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7830);

// NON_MATCHING: 147/158 differ, 3 relocs differ, 112 edits
#ifdef NON_MATCHING
union MCD_A17_colors { int v[16]; long long q[8]; };
struct MCD_A17_vec { long long v[6]; };
extern MCD_A17_vec D_002F7800, D_002F7830;
extern long long D_00299940[2];
extern const char D_002F7868[];
extern const char D_002F7450[];
extern "C" void *memset(void *, int, unsigned int);
extern "C" char *strcpy(char *, const char *);
extern "C" void func_0018A17C(char *arg0)
{
    MCD_A17_colors colors;
    MCD_A17_vec v1, v2;
    memset(&colors, 0, 0x40);
    colors.v[0] = colors.v[5] = colors.v[10] = 0x80;
    colors.v[12] = colors.v[13] = colors.v[14] = 0x80;
    v1 = D_002F7800;
    v2 = D_002F7830;
    memset(arg0 + 0x6E8, 0, 0x3C4);
    strcpy(arg0 + 0x6E8, "PS2D");
    *(long long *)(arg0 + 0x7A8) = *(const long long *)(D_002F7868);
    *(long long *)(arg0 + 0x7B0) = *(const long long *)(D_002F7868 + 8);
    *(long long *)(arg0 + 0x7B8) = *(const long long *)(D_002F7868 + 16);
    arg0[0x7C0] = D_002F7868[24];
    *(short *)(arg0 + 0x6EE) = 0x20;
    *(int *)(arg0 + 0x6F4) = 0x60;
    *(MCD_A17_colors *)(arg0 + 0x6F8) = colors;
    *(MCD_A17_vec *)(arg0 + 0x738) = v1;
    *(MCD_A17_vec *)(arg0 + 0x768) = v2;
    *(long long *)(arg0 + 0x798) = D_00299940[0];
    *(long long *)(arg0 + 0x7A0) = D_00299940[1];
    strcpy(arg0 + 0x7EC, "slime1.ico");
    strcpy(arg0 + 0x82C, "slime1.ico");
    strcpy(arg0 + 0x86C, "slime1.ico");
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018A17C);
#endif

// NON_MATCHING: 26/56 differ, 2 relocs differ, 33 edits
#ifdef NON_MATCHING
extern "C" int X_strlen(const char *) asm("strlen");
extern "C" char *Xcc_strcpy(char *, const char *) asm("strcpy");
extern const char D_002F7888[];
extern const char D_002F7898[];
extern const char D_002F78A0[];
static inline char *mcd_strcat(char *dst, const char *src)
{
    return Xcc_strcpy(dst + X_strlen(dst), src);
}
extern "C" void func_0018A3F4(int arg0, int arg1, char *arg2)
{
    struct S14 {
        char c[14];
    };
    char buf[3];
    int d1 = 10;
    int d2 = 10;
    buf[0] = (arg1 / d1) + '0';
    arg2[0] = '\0';
    *(struct S14 *)arg2 = *(const struct S14 *)D_002F7888;
    buf[1] = (arg1 % d2) + '0';
    buf[2] = '\0';
    mcd_strcat(arg2, D_002F7898);
    mcd_strcat(arg2, buf);
    mcd_strcat(arg2, D_002F78A0);
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018A3F4);
#endif

extern "C" void func_0018A4D4(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x80));
    if (temp_v0 != 0) {
        X_heapFree__FPv(temp_v0);
        (*(int *)(int *)((char *)(arg0) + 0x80)) = 0;
    }
}


INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7868);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7888);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F7898);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F78A0);

INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018A50C);

extern "C" int func_0018AD0C(int arg0)
{
    int ret = 0;

    switch (M2C_FIELD(arg0, int *, 0x68)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 0;
        M2C_FIELD(arg0, int *, 0x64) = 1;
        M2C_FIELD(arg0, int *, 0x68) = 1;
    case 1:
        if (Xii_func_00189068(arg0) == 1) {
            switch (M2C_FIELD(arg0, int *, 0x64)) {
            case 2:
                M2C_FIELD(arg0, int *, 0x64) = 1;
                M2C_FIELD(arg0, int *, 0x68) = 0x6E;
                M2C_FIELD(arg0, int *, 0x60) = 0;
                break;
            case 3:
                ret = 1;
                break;
            }
        }
        break;
    case 0x6E:
        M2C_FIELD(arg0, int *, 0x64) = 2;
        ret = 1;
        break;
    }
    return ret;
}

// NON_MATCHING: 143/212 differ, 6 relocs differ (size 0x350, game 0x34C), 57 edits
#ifdef NON_MATCHING
extern "C" int func_0018ADE0(int arg0)
{
    int done = 0;
    int r;
    switch (M2C_FIELD(arg0, int *, 0x68)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x64) = 1;
        M2C_FIELD(arg0, int *, 0xC0) = 0;
        M2C_FIELD(arg0, int *, 0x60) = 0;
        M2C_FIELD(arg0, int *, 0x194) = 0;
        if (M2C_FIELD(arg0, signed char *, 0x154)) {
            int p = X_strstr(arg0 + 0x154, (int)D_002F7898);
            M2C_FIELD(arg0, int *, 0x194) = p;
            if (p) {
                M2C_FIELD(arg0, int *, 0x194) = p + 5;
                M2C_FIELD(p, char *, 5) = '1';
            }
        }
        if (!M2C_FIELD(arg0, char *, 0x114)) M2C_FIELD(arg0, int *, 0x68) = 60;
        else M2C_FIELD(arg0, int *, 0x68) = 10;
        break;
    case 10:
        r = X_func_0018993C(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                M2C_FIELD(arg0, int *, 0x68) = 60;
                M2C_FIELD(arg0, int *, 0x64) = r;
                M2C_FIELD(arg0, int *, 0x60) = 0;
            } else if (M2C_FIELD(arg0, int *, 0x64) == 3) {
                if (M2C_FIELD(arg0, int *, 0x58) == 12) {
                    M2C_FIELD(arg0, int *, 0x64) = r;
                    M2C_FIELD(arg0, int *, 0x68) = 60;
                    M2C_FIELD(arg0, int *, 0x60) = 0;
                } else done = 1;
            }
        }
        break;
    case 60: {
        int name = arg0 + 0x154;
        M2C_FIELD(arg0, int *, 0x68) = 70;
        M2C_FIELD(arg0, int *, 0x64) = 1;
        M2C_FIELD(arg0, int *, 0x60) = 0;
        if (!name) M2C_FIELD(arg0, char *, 0x114) = 0;
        else X_strcpy(arg0 + 0x114, name);
        M2C_FIELD(arg0, int *, 0x9C) = 3;
        break;
    }
    case 70:
        r = X_func_001894D4(arg0);
        if (r == 1) {
            switch (M2C_FIELD(arg0, int *, 0x64)) {
            case 2:
                M2C_FIELD(arg0, int *, 0x68) = 80;
                M2C_FIELD(arg0, int *, 0x64) = r;
                M2C_FIELD(arg0, int *, 0x60) = 0;
                break;
            case 3:
                done = 1;
                if (M2C_FIELD(arg0, int *, 0x58) == 5 && M2C_FIELD(arg0, int *, 0xC0) == 0) {
                    M2C_FIELD(arg0, int *, 0x60) = 0;
                    M2C_FIELD(arg0, int *, 0x9C) = 0x203;
                    M2C_FIELD(arg0, int *, 0x64) = 1;
                    done = 0;
                }
                M2C_FIELD(arg0, int *, 0xC0)++;
                break;
            }
        }
        break;
    case 80:
        M2C_FIELD(arg0, int *, 0x68) = 90;
    case 90:
        r = X_func_00189F58(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                M2C_FIELD(arg0, int *, 0x64) = r;
                M2C_FIELD(arg0, int *, 0x68) = 100;
                M2C_FIELD(arg0, int *, 0x60) = 0;
            } else if (M2C_FIELD(arg0, int *, 0x64) == 3) done = 1;
        }
        break;
    case 100:
        r = X_func_001885D4(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                M2C_FIELD(arg0, int *, 0x64) = r;
                M2C_FIELD(arg0, int *, 0x68) = 101;
                M2C_FIELD(arg0, int *, 0x60) = 0;
            } else if (M2C_FIELD(arg0, int *, 0x64) == 3) done = 1;
        }
        break;
    case 101:
        if (M2C_FIELD(arg0, int *, 0x194)) {
            M2C_FIELD(arg0, int *, 0x68) = 102;
            X_strcpy(arg0 + 0x114, arg0 + 0x154);
            *(char *)M2C_FIELD(arg0, int *, 0x194) = '0';
        } else M2C_FIELD(arg0, int *, 0x68) = 110;
        break;
    case 102:
        r = X_func_0018993C(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                M2C_FIELD(arg0, int *, 0x64) = r;
                M2C_FIELD(arg0, int *, 0x68) = 110;
                M2C_FIELD(arg0, int *, 0x60) = 0;
            } else if (M2C_FIELD(arg0, int *, 0x64) == 3) {
                if (M2C_FIELD(arg0, int *, 0x58) == 12) {
                    M2C_FIELD(arg0, int *, 0x64) = r;
                    M2C_FIELD(arg0, int *, 0x68) = 110;
                    M2C_FIELD(arg0, int *, 0x60) = 0;
                } else done = 1;
            }
        }
        break;
    case 110:
        done = 1;
        M2C_FIELD(arg0, int *, 0x64) = 2;
        break;
    }
    return done;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018ADE0);
#endif

extern "C" int func_0018B12C(int arg0)
{
    int ret = 0;

    switch (M2C_FIELD(arg0, int *, 0x68)) {
    case 0:
        M2C_FIELD(arg0, int *, 0x60) = 0;
        M2C_FIELD(arg0, int *, 0x64) = 1;
        M2C_FIELD(arg0, int *, 0x68) = 0x3C;
    case 0x3C:
        M2C_FIELD(arg0, int *, 0x60) = 0;
        M2C_FIELD(arg0, int *, 0x64) = 1;
        M2C_FIELD(arg0, int *, 0x68) = 0x46;
        M2C_FIELD(arg0, int *, 0x9C) = 1;
        break;
    case 0x46:
        if (Xii_func_001894D4(arg0) == 1) {
            switch (M2C_FIELD(arg0, int *, 0x64)) {
            case 2:
                M2C_FIELD(arg0, int *, 0x64) = 1;
                M2C_FIELD(arg0, int *, 0x68) = 0x50;
                M2C_FIELD(arg0, int *, 0x60) = 0;
                break;
            case 3:
                ret = 1;
                break;
            }
        }
        break;
    case 0x50:
        M2C_FIELD(arg0, int *, 0x68) = 0x5A;
    case 0x5A:
        if (Xii_func_00189718(arg0) == 1) {
            switch (M2C_FIELD(arg0, int *, 0x64)) {
            case 2:
                M2C_FIELD(arg0, int *, 0x64) = 1;
                M2C_FIELD(arg0, int *, 0x68) = 0x64;
                M2C_FIELD(arg0, int *, 0x60) = 0;
                break;
            case 3:
                ret = 1;
                break;
            }
        }
        break;
    case 0x64:
        if (Xii_func_001885D4(arg0) == 1) {
            switch (M2C_FIELD(arg0, int *, 0x64)) {
            case 2:
                M2C_FIELD(arg0, int *, 0x64) = 1;
                M2C_FIELD(arg0, int *, 0x68) = 0x6E;
                M2C_FIELD(arg0, int *, 0x60) = 0;
                break;
            case 3:
                ret = 1;
                break;
            }
        }
        break;
    case 0x6E:
        M2C_FIELD(arg0, int *, 0x64) = 2;
        ret = 1;
        break;
    }
    return ret;
}

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F78C8);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F78D8);

INCLUDE_RODATA("asm/nonmatchings/mcd/mcdman", D_002F78F8);

// NON_MATCHING: 251/366 differ, 15 relocs differ, 150 edits
#ifdef NON_MATCHING
extern "C" int X_func_0018A17C(...) asm("func_0018A17C");
extern int D_00299928;
extern int D_00299938;
extern "C" void F_B2_icon(int) asm("func_0018A17C");
extern "C" int func_0018B2BC(int arg0)
{
    int done = 0;
    int r;
    int next;
    int name;
    switch (M2C_FIELD(arg0, int *, 0x68)) {
    case 0:
        name = (int)"/FEBDUMMY";
        M2C_FIELD(arg0, int *, 0x68) = 1;
        M2C_FIELD(arg0, int *, 0x60) = 0;
        M2C_FIELD(arg0, int *, 0x64) = 1;
        if (!name) M2C_FIELD(arg0, char *, 0x114) = 0;
        else X_strcpy(arg0 + 0x114, name);
    case 1:
        r = X_func_001892B0(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) { next = 4; goto reset; }
            if (M2C_FIELD(arg0, int *, 0x64) == 3) {
                if (M2C_FIELD(arg0, int *, 0x58) != 17) done = 1;
                else {
                    M2C_FIELD(arg0, int *, 0x58) = r;
                    M2C_FIELD(arg0, int *, 0x68) = 4;
                    M2C_FIELD(arg0, int *, 0x60) = 0;
                    M2C_FIELD(arg0, int *, 0x64) = r;
                }
            }
        }
        break;
    case 4:
        M2C_FIELD(arg0, int *, 0xC4) = 0;
    case 5:
        M2C_FIELD(arg0, int *, 0x64) = 1;
        M2C_FIELD(arg0, int *, 0x68) = 10;
        M2C_FIELD(arg0, int *, 0x60) = 0;
        name = ((int *)&D_00299928)[M2C_FIELD(arg0, int *, 0xC4)];
        goto copyName;
    case 10:
        next = 20;
        goto openFile;
    case 20: {
        M2C_FIELD(arg0, int *, 0x68) = 30;
        int p = arg0 + (M2C_FIELD(arg0, int *, 0xC4) * 4 + 0x6D0);
        M2C_FIELD(arg0, int *, 0xB0) = M2C_FIELD(p, int *, 8);
        M2C_FIELD(arg0, int *, 0xB4) = M2C_FIELD(p, int *, 12);
        break;
    }
    case 30:
        r = X_func_00189F58(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                next = 40;
                goto reset;
            }
            goto fail;
        }
        break;
    case 40:
        next = 50;
        goto closeFile;
    case 50:
        ++M2C_FIELD(arg0, int *, 0xC4);
        if (M2C_FIELD(arg0, int *, 0xC4) > 0) M2C_FIELD(arg0, int *, 0x68) = 60;
        else M2C_FIELD(arg0, int *, 0x68) = 5;
        break;
    case 60:
        M2C_FIELD(arg0, int *, 0x68) = 70;
        M2C_FIELD(arg0, int *, 0x64) = 1;
        M2C_FIELD(arg0, int *, 0x60) = 0;
        F_B2_icon(arg0);
        name = (int)"/FEBDUMMY/icon.sys";
copyName:
        if (!name) M2C_FIELD(arg0, char *, 0x114) = 0;
        else X_strcpy(arg0 + 0x114, name);
        M2C_FIELD(arg0, int *, 0x9C) = 0x203;
        break;
    case 70:
        r = X_func_001894D4(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                next = 80;
                goto reset;
            }
            goto fail;
        }
        break;
    case 80:
        M2C_FIELD(arg0, int *, 0xB4) = arg0 + 0x6E8;
        M2C_FIELD(arg0, int *, 0x68) = 90;
        M2C_FIELD(arg0, int *, 0xB0) = 0x3C4;
        break;
    case 90:
        r = X_func_00189F58(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                next = 100;
                goto reset;
            }
            goto fail;
        }
        break;
    case 100:
        r = X_func_001885D4(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                next = 110;
                goto reset;
            }
            goto fail;
        }
        break;
    case 110:
        M2C_FIELD(arg0, int *, 0x68) = 120;
        break;
    case 120:
        r = X_func_00187E44(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                next = 130;
                goto reset;
            }
            goto fail;
        }
        break;
    case 130:
        if (M2C_FIELD(arg0, int *, 0x84) < 2) M2C_FIELD(arg0, int *, 0x68) = 161;
        name = D_00299938;
        if (!name) M2C_FIELD(arg0, char *, 0x114) = 0;
        else X_strcpy(arg0 + 0x114, name);
        M2C_FIELD(arg0, int *, 0x68) = 140;
        M2C_FIELD(arg0, int *, 0x9C) = 0x203;
        break;
    case 140:
        next = 150;
openFile:
        r = X_func_001894D4(arg0);
        goto advance;
    case 150:
        M2C_FIELD(arg0, int *, 0xC4) = 1;
        M2C_FIELD(arg0, int *, 0x68) = 151;
        break;
    case 151: {
        M2C_FIELD(arg0, int *, 0x68) = 152;
        int n = M2C_FIELD(arg0, int *, 0x84) - M2C_FIELD(arg0, int *, 0xC4);
        if (n < 100) M2C_FIELD(arg0, int *, 0xAAC) = n;
        else M2C_FIELD(arg0, int *, 0xAAC) = 100;
        M2C_FIELD(arg0, int *, 0xB4) = arg0 + 0x6E8;
        M2C_FIELD(arg0, int *, 0xB0) = M2C_FIELD(arg0, int *, 0xAAC) << 10;
    }
    case 152:
        r = X_func_00189F58(arg0);
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                next = 153;
                goto reset;
            }
            goto fail;
        }
        break;
    case 153:
        M2C_FIELD(arg0, int *, 0xC4) += M2C_FIELD(arg0, int *, 0xAAC);
        if (M2C_FIELD(arg0, int *, 0xC4) < M2C_FIELD(arg0, int *, 0x84)) M2C_FIELD(arg0, int *, 0x68) = 151;
        else M2C_FIELD(arg0, int *, 0x68) = 160;
        break;
    case 160:
        next = 161;
closeFile:
        r = X_func_001885D4(arg0);
advance:
        if (r == 1) {
            if (M2C_FIELD(arg0, int *, 0x64) == 2) {
                M2C_FIELD(arg0, int *, 0x68) = next;
                M2C_FIELD(arg0, int *, 0x64) = r;
                M2C_FIELD(arg0, int *, 0x60) = 0;
            } else if (M2C_FIELD(arg0, int *, 0x64) == 3) done = 1;
        }
        break;
reset:
        M2C_FIELD(arg0, int *, 0x64) = r;
        M2C_FIELD(arg0, int *, 0x68) = next;
        M2C_FIELD(arg0, int *, 0x60) = 0;
        break;
fail:
        if (M2C_FIELD(arg0, int *, 0x64) == 3) done = 1;
        break;
    case 161:
        M2C_FIELD(arg0, int *, 0x68) = 999;
        break;
    case 999:
        done = 1;
        M2C_FIELD(arg0, int *, 0x64) = 2;
        break;
    }
    return done;
}
#else
INCLUDE_ASM("asm/nonmatchings/mcd/mcdman", func_0018B2BC);
#endif

extern "C" int func_0018B874(const McdMgr *arg0)
{
    for (int i = 0; i < arg0->m_num; i++) {
        if (Xi_strcmp(arg0->getName(i), D_002F78C8) == 0 && arg0->getSize(i) == 0x3C4) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_0018B918(int arg0, const char *s1, const char *s2)
{
    int i = 0;

    if (s1 == 0) {
        return -1;
    }
    if (s2 == 0) {
        return -1;
    }
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) {
            goto fail;
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;
    }
fail:
    return -1;
}

extern "C" int func_0018B9B8(const McdMgr *arg0, const char *arg1)
{
    for (int i = 0; i < arg0->m_num; i++) {
        if (X_matchName(arg0, arg0->getName(i), arg1) == 0) {
            return Xcc_strstr(arg0->getName(i), D_002F78A0) == 0;
        }
    }
    return 0;
}

extern "C" int func_0018BA68(const McdMgr *arg0, const char *arg1, int arg2)
{
    for (int i = 0; i < arg0->m_num; i++) {
        if (X_matchName(arg0, arg0->getName(i), arg1) == 0) {
            return (arg0->getSize(i) == arg2) ? 1 : 2;
        }
    }
    return 0;
}
