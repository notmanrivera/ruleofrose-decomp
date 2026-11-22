#include "include_asm.h"
#include "mnu/mnudlg.h"

extern "C" void *X_alloc__9BedMemoryiPCciii(void *, int, const char *, int, int, int) asm("alloc__9BedMemoryiPCciii");
extern "C" void X_func_001348B0(void *, int) asm("func_001348B0");
extern "C" void X_func_001351B0(void *, int, int) asm("func_001351B0");
extern "C" void X_func_0018741C(void *) asm("func_0018741C");
extern "C" void X_func_00187464(void *) asm("func_00187464");
extern "C" void X_func_001879C4(void *) asm("func_001879C4");
extern "C" void X_func_00187C30(void *) asm("func_00187C30");
extern "C" void X_func_00187C4C(void *) asm("func_00187C4C");
extern "C" int X_func_001A17FC(...) asm("func_001A17FC");
extern "C" int X_func_001A1CE4(...) asm("func_001A1CE4");
extern "C" int X_func_001A47F0(void *) asm("func_001A47F0");
extern "C" int X_func_001A4E88(...) asm("func_001A4E88");
extern "C" int X_func_001A4F60(void *) asm("func_001A4F60");
extern "C" void X_func_001A4FF0(void *) asm("func_001A4FF0");
extern "C" void X_func_001A5034(void *) asm("func_001A5034");
extern "C" void X_heapFree__FPv(void *) asm("heapFree__FPv");
extern "C" char *X_strcpy(char *, const char *) asm("strcpy");
extern int _9MagSystem$m_current_system;
extern int D_006E9800;

extern "C" int func_001A1430(MnuMcd *);
extern "C" int func_001A1468(MnuMcd *);
extern "C" int func_001A1684(MnuMcd *, int);
extern "C" int func_001A16B4(MnuMcd *, int, int);
extern "C" void func_001A1714(MnuMcd *, int);
extern "C" int func_001A171C(MnuMcd *, int, int);
extern "C" int func_001A17DC(MnuMcd *);
extern "C" int func_001A1B2C(MnuMcd *);
extern "C" int func_001A4D38(MnuDlgObj *);

static inline bool checkPortValid(const int &port)
{
    return port < 2;
}

extern "C" void func_001A0950(MnuSub104 *arg0)
{
    if (arg0->m_lines[0] != 0) {
        for (int i = 0; i < 32; i++) {
            X_heapFree__FPv(arg0->m_lines[i]);
            arg0->m_lines[i] = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A09B8);

extern "C" int func_001A0BA0(MnuSub104 *arg0)
{
    if (arg0->m_open == 0) {
        return -2;
    }
    return arg0->m_result;
}

extern "C" void func_001A0BB8(MnuSub104 *arg0)
{
    if (arg0->m_open != 0 && arg0->m_active == 1) {
        arg0->m_subStep = 4;
    }
}

extern "C" int func_001A0BDC()
{
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A0BE4);

MnuMcd::MnuMcd()
{
    m_open = 0;
    func_001A1B2C(this);
}

MnuMcd::~MnuMcd()
{
    func_001A1468(this);
}

extern "C" void func_001A134C(MnuMcd *arg0)
{
    arg0->m_winId0 = -1;
    arg0->m_winId1 = -1;
    arg0->m_unk88 = 0;
    func_001A1430(arg0);
    arg0->m_active = 1;
    arg0->m_unk70 = 0;
    arg0->m_unk6C = 0;
    for (int i = 0; i < 2; i++) {
        arg0->m_portState[i] = 0;
    }
    arg0->m_unk8C = 0;
    arg0->m_reqOp = 0;
    arg0->m_sys = _9MagSystem$m_current_system;
    func_001A1714(arg0, 0);
    arg0->m_statusFlags = 2;
    arg0->m_subState = 10;
    arg0->m_slotState = 0;
    arg0->m_unk13B8 = 0;
    arg0->m_busy = 0;
}

extern "C" void func_001A13F0(MnuMcd *arg0)
{
    func_001A1468(arg0);
}

extern "C" int func_001A140C(MnuMcd *arg0)
{
    return arg0->m_active;
}

extern "C" int func_001A1414()
{
    return X_func_001A17FC();
}

extern "C" void func_001A1428(void)
{
}

extern "C" int func_001A1430(MnuMcd *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    arg0->m_open = 1;
    arg0->m_step = 0;
    arg0->m_mode = 4;
    arg0->m_unk2C = 0;
    arg0->m_reqCmd = 0;
    arg0->m_subStep = 0;
    return 0;
}

extern "C" int func_001A1468(MnuMcd *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    if (arg0->m_winId0 >= 0) {
        X_func_001348B0((char *)arg0->m_sys + 0x12540, arg0->m_winId0);
        arg0->m_winId0 = -1;
    }
    if (arg0->m_winId1 >= 0) {
        X_func_001348B0((char *)arg0->m_sys + 0x12540, arg0->m_winId1);
        arg0->m_winId1 = -1;
    }
    X_func_00187C30(&arg0->m_card);
    X_func_001879C4(&arg0->m_card);
    X_func_00187464(arg0->m_msgWin);
    arg0->m_open = 0;
    arg0->m_active = 0;
    return 0;
}

extern "C" void func_001A1514(MnuMcd *arg0, unsigned char *buf)
{
    (void)arg0;
    unsigned char *colSum = buf + 0x2D10;
    unsigned char *rowSum = buf + 0x2D20;
    for (int r = 0; r < 0x2D1; r++) {
        for (int c = 0; c < 0x10; c++) {
            *rowSum += *buf;
            colSum[c] += *buf;
            buf++;
        }
        rowSum++;
    }
}

// NON_MATCHING: 43/53 differ (size 0xD4, game 0xDC), 18 edits
#ifdef NON_MATCHING
extern "C" int func_001A1574(MnuMcd *arg0, unsigned char *buf)
{
    (void)arg0;
    int nonZero = 0;
    unsigned char *colSum = buf + 0x2D10;
    unsigned char *rowSum = buf + 0x2D20;
    unsigned char col[16];
    int i;
    for (i = 15; i >= 0; i--) {
        col[i] = 0;
    }

    for (int r = 0; r < 0x2D1; r++) {
        unsigned char sum = 0;
        for (i = 0; i < 0x10; i++) {
            sum += *buf;
            if (*buf != 0) {
                nonZero = 1;
            }
            col[i] += *buf;
            buf++;
        }
        if (sum != *rowSum) {
            return 0;
        }
        rowSum++;
    }
    if (nonZero == 0) {
        return 0;
    }
    for (i = 0; i < 0x10; i++) {
        if (col[i] != colSum[i]) {
            return 0;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A1574);
#endif

extern "C" void func_001A1650(MnuMcd *arg0, int arg1)
{
    arg0->m_unk13B8 = arg1;
}

extern "C" int func_001A1658(MnuMcd *arg0, int arg1)
{
    if ((arg0->m_step ^ 4) != 0) {
        return 0;
    }
    arg0->m_reqCmd = arg1;
    arg0->m_result = 0;
    arg0->m_mode = 2;
    return 1;
}

extern "C" int func_001A1684(MnuMcd *arg0, int port)
{
    if ((checkPortValid(port) ^ 1) & 1) {
        return 8;
    }
    return arg0->m_portState[port];
}

extern "C" int func_001A16B4(MnuMcd *arg0, int port, int val)
{
    if ((checkPortValid(port) ^ 1) & 1) {
        return 0;
    }
    arg0->m_portState[port] = val;
    return 1;
}

extern "C" void func_001A16E8(MnuMcd *arg0, int val)
{
    for (int i = 0; i < 2; i++) {
        arg0->m_portState[i] = val;
    }
}

extern "C" void func_001A1714(MnuMcd *arg0, int arg1)
{
    arg0->m_port = arg1;
}

extern "C" int func_001A171C(MnuMcd *arg0, int port, int op)
{
    arg0->m_unk70 = 0;
    if (arg0->m_reqOp == 0) {
        func_001A1714(arg0, port);
        func_001A16B4(arg0, arg0->m_port, 0);
        arg0->m_reqOp = op;
        return 1;
    }
    return 0;
}

extern "C" void func_001A177C(MnuMcd *arg0, int arg1)
{
    int flags = arg0->m_statusFlags;
    if (arg1 == arg0->m_slotState) {
        arg0->m_statusFlags = flags & ~0x10;
        return;
    }
    arg0->m_slotState = arg1;
    arg0->m_subState = 0xA;
    arg0->m_statusFlags = flags | 0x14;
}

extern "C" void func_001A17B0(MnuMcd *arg0, int arg1)
{
    int flags = arg0->m_statusFlags;
    if (arg1 == arg0->m_subState) {
        arg0->m_statusFlags = flags & ~0x20;
        return;
    }
    arg0->m_subState = arg1;
    arg0->m_statusFlags = flags | 0x20;
}

extern "C" int func_001A17DC(MnuMcd *arg0)
{
    return func_001A1684(arg0, arg0->m_port) != 0;
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A17FC);

extern "C" int func_001A1B2C(MnuMcd *arg0)
{
    for (int i = 0; i < 7; i++) {
        arg0->m_cursor[i] = 0;
    }
    return 0;
}

extern "C" int func_001A1B54(MnuMcd *arg0)
{
    X_func_001A1CE4(arg0);
    X_func_00187C4C(&arg0->m_card);
    X_func_001A47F0(arg0);
    return 0;
}

extern "C" void func_001A1B8C(MnuMcd *arg0, const char *dir, const char *file, int size, int buf)
{
    if (dir == 0) {
        arg0->m_dirName[0] = 0;
    } else {
        X_strcpy(arg0->m_dirName, dir);
    }
    if (file == 0) {
        arg0->m_fileName[0] = 0;
    } else {
        X_strcpy(arg0->m_fileName, file);
    }
    arg0->m_saveSize = size;
    arg0->m_saveBuf = buf;
}

extern "C" void func_001A1C08(MnuMcd *arg0, const char *dir, int size, int buf)
{
    if (dir == 0) {
        arg0->m_dirName[0] = 0;
    } else {
        X_strcpy(arg0->m_dirName, dir);
    }
    arg0->m_saveBuf = buf;
    arg0->m_saveSize = size;
    arg0->m_fileName[0] = 0;
}

extern "C" void func_001A1C64(MnuMcd *arg0, const char *file)
{
    if (file == 0) {
        arg0->m_fileName[0] = 0;
        return;
    }
    X_strcpy(arg0->m_fileName, file);
}

extern "C" int func_001A1C8C(MnuMcd *arg0)
{
    return arg0->m_card.m_dirCount;
}

extern "C" char *func_001A1C94(MnuMcd *arg0, int idx)
{
    return arg0->m_card.getName(idx);
}

extern "C" int func_001A1CBC(MnuMcd *arg0, int idx)
{
    return arg0->m_card.getSize(idx);
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A1CE4);

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A239C);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F88E0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8910);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8940);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8970);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F89A0);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F89D8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8A10);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8A38);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8A68);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8A90);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8AB8);

INCLUDE_RODATA("asm/nonmatchings/mnu/mnudlg", D_002F8AE8);

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A2B14);

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A30CC);

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A3568);

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A36C4);

extern "C" int func_001A3B80(MnuMcd *arg0)
{
    int ret = 0;

    switch (arg0->m_subStep) {
    case 0:
        if (func_001A171C(arg0, 0, 1) == 1) {
            arg0->m_subStep = 1;
        }
        break;
    case 1: {
        int r = func_001A17DC(arg0);
        if (r == 1) {
            func_001A1684(arg0, arg0->m_port);
            arg0->m_result = r;
            arg0->m_subStep = 0x32;
        }
        break;
    }
    case 50:
        arg0->m_subStep = 0;
        ret = 1;
        break;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A3C4C);

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A44FC);

INCLUDE_ASM("asm/nonmatchings/mnu/mnudlg", func_001A47F0);

MnuDlgObj::MnuDlgObj()
{
    m_open = 0;
    X_func_001A4F60(this);
}

MnuDlgObj::~MnuDlgObj()
{
    func_001A4D38(this);
}

extern "C" int func_001A4CC8()
{
    return X_func_001A4E88();
}

extern "C" int func_001A4CDC(MnuDlgObj *arg0)
{
    if (arg0->m_open == 1) {
        return -1;
    }
    int cur = _9MagSystem$m_current_system;
    arg0->m_open = 1;
    arg0->m_sys = cur;
    arg0->m_step = 0;
    arg0->m_mode = 0;
    arg0->m_subStep = 0;
    X_func_001A4FF0(arg0);
    X_func_0018741C(arg0->m_msgWin);
    return 0;
}

extern "C" int func_001A4D38(MnuDlgObj *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    X_func_001A5034(arg0);
    X_func_00187464(arg0->m_msgWin);
    if (arg0->m_winId >= 0) {
        X_func_001351B0((char *)arg0->m_sys + 0x12540, arg0->m_winId, 1);
        X_func_001348B0((char *)arg0->m_sys + 0x12540, arg0->m_winId);
    }
    arg0->m_open = 0;
    return 0;
}

extern "C" void func_001A4DB8(MnuDlgObj *arg0, char **lines, int count, int size)
{
    (void)arg0;
    if (count > 0) {
        char **p = lines;
        int n = count;
        do {
            if (*p == 0) {
                *p = (char *)X_alloc__9BedMemoryiPCciii(&D_006E9800, size, "mnu/mnudlg.cpp", 0x78, 0, 2);
            }
            n--;
            p++;
        } while (n != 0);
    }
}

extern "C" void func_001A4E34(MnuDlgObj *arg0, char **lines, int count)
{
    (void)arg0;
    if (count > 0) {
        char **p = lines;
        int n = count;
        do {
            if (*p != 0) {
                X_heapFree__FPv(*p);
            }
            n--;
            *p = 0;
            p++;
        } while (n != 0);
    }
}
