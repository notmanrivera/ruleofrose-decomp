#include "ror.h"
#include "include_asm.h"
struct m2c_block8 { int w[2]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xii_func_00183B74(int) asm("func_00183B74");
extern int D_002F6F40;
extern int D_002F6F48;
extern int D_002F6F50;
extern int D_002F6F58;
extern int D_002F6F60;
extern int D_002F6F68;
extern int D_002F6F70;
extern int D_002F6F78;
extern int D_002F6F80;
extern int D_002F6F88;
extern int D_002F6F90;
extern int D_002F6F98;
extern int D_002F6FA0;
extern int D_002F6FA8;
extern int D_002F6FB0;
extern int D_002F6FB8;
extern int D_002F6FC0;
extern int D_002F6FC8;
extern int D_002F6FD0;
extern int D_002F6FD8;
extern int D_002F6FE0;
extern int D_002F6FE8;
extern int D_002F6FF0;
extern int D_002F6FF8;
extern int D_002F7000;
extern int D_002F7008;
extern int D_002F7010;
extern int D_002F7018;
extern int D_002F7020;
extern int D_002F7028;
extern int D_002F7030;
extern int D_002F7038;
extern int D_002F7040;
extern int D_002F7048;
extern int D_002F7050;
extern int D_002F7058;
extern int D_002F7060;
extern int D_002F7068;
extern int D_002F7070;
extern int D_002F7078;
extern int D_002F7080;
extern int D_002F7088;
extern int D_002F7090;
extern int D_002F7098;
extern int D_002F70A0;
extern int D_002F70A8;
extern int D_002F70B0;
extern int D_002F70B8;
extern int D_002F70C0;
extern int D_002F70C8;
extern int D_002F70D0;
extern int D_002F70D8;
extern int D_002F70E0;
extern int D_002F70E8;
extern int D_002F70F0;
extern int D_002F70F8;
extern int D_002F7100;
extern int D_002F7108;
extern int D_002F7110;
extern int D_002F7118;
extern int D_002F7120;
extern int D_002F7128;
extern int D_002F7130;
extern int D_002F7138;
extern int D_002F7140;
extern int D_002F7148;
extern int D_002F7150;
extern int D_002F7158;
extern int D_002F7160;
extern int D_002F7168;
extern int D_002F7170;
extern int D_002F7178;
extern int D_002F7180;
extern int D_002F7188;
extern int D_002F7190;
extern int D_002F7198;
extern int D_002F71A0;
extern int D_002F71A8;
extern int D_002F71B0;
extern int D_002F71B8;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xii_func_00185760(int) asm("func_00185760");
extern "C" int Xiii_func_001850FC(int, int) asm("func_001850FC");
extern "C" int Xiiiiu_func_001857C8(int, int, int, unsigned int) asm("func_001857C8");
extern "C" int Xiiu_func_00135594(int, unsigned int) asm("func_00135594");
extern "C" int Xiiuiii_func_00134A00(int, unsigned int, int, int, int) asm("func_00134A00");
extern "C" int X_func_001856FC(...) asm("func_001856FC");
extern "C" int X_func_00185760(...) asm("func_00185760");
#include "sdk/string.h"
extern "C" int Xiii_func_00191E58(int, int, int) asm("func_00191E58");
extern int D_006FBD80;
extern "C" int Xii_func_00185704(int) asm("func_00185704");
extern "C" int Xiii_func_00184F2C(int, int) asm("func_00184F2C");
extern "C" int Xiiii_func_00184578(int, int, int) asm("func_00184578");
extern "C" int Xiiii_func_00184600(int, int, int) asm("func_00184600");
struct MsgNameEnt { int id; char *name; };
extern MsgNameEnt D_00299738[];
extern int D_002F73E4;
extern "C" int Xiiiii_func_001DC48C(int, int, int, int) asm("func_001DC48C");
extern char D_002F71F0[];
extern int D_007812C0;
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" int Xi_func_00184008(void *) asm("func_00184008");
extern "C" void Xv_func_00183C4C(void *) asm("func_00183C4C");
extern "C" void Xv_func_00183BB8(void *) asm("func_00183BB8");
extern "C" int Xii_func_00184A94(int) asm("func_00184A94");
extern "C" int atoi(const char *);
extern "C" int func_0027BBA8(const char *theStr, int theA, int theBase);
extern const char *D_00298FE8[];
extern "C" void func_00134FA0(void *theScene, int theNo, int theA);
extern "C" void func_00135014(void *theScene, int theNo, int theA);
extern "C" void func_00134F2C(void *theScene, int theNo, int theA);
struct MsgWin {
    union {
        int m[0x40];
        struct {
            int m_no;           // +0x00
            int m_unk04[3];
            void *m_system;     // +0x10: MagSystem (its scene is at +0x12540)
            int m_unk14;
            char *m_str;        // +0x18
            int m_pos;          // +0x1C
        };
    };
};
struct MsgQueue {
    int m_unk00;
    int m_pos;                  // +0x04
    int m_used;                 // +0x08
    int m_unk0C;
    int m_size;                 // +0x10
};
extern "C" int func_001831C4(MsgQueue *self);
extern "C" int func_0018454C(MsgWin *self, const char *theStr);
extern "C" int func_00184578(MsgWin *self, const char *theStr, int *theOut);

extern "C" int func_001831A8(int arg0)
{
    int temp_a0;
    int temp_v0;

    temp_a0 = (*(int *)(int *)((char *)(arg0) + 0x8));
    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x10)) - (*(int *)(int *)((char *)(arg0) + 0x4));
    return (temp_a0 < temp_v0) ? temp_a0 : temp_v0;
}


extern "C" int func_001831C4(MsgQueue *self)
{
    return self->m_used;
}


extern "C" int func_001831CC(MsgQueue *self)
{
    return self->m_size - func_001831C4(self);
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001831F8);

extern "C" char *func_001832A4(MsgQueue *self)
{
    return (char *)self + self->m_pos + 0x40;
}


extern "C" void func_001832B8(MsgQueue *self, int theN)
{
    self->m_used -= theN;
    self->m_pos = (self->m_pos + theN) % self->m_size;
}


extern "C" const char *func_001832E8(unsigned int theN)
{
    const char *p = 0;
    if (theN < 468) {
        p = D_00298FE8[theN];
    }
    return p;
}


extern "C" int func_0018330C(int arg0)
{
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    *(m2c_block8 *)((char *)(arg0) + 0x12c) = *(m2c_block8 *)((char *)(&D_002F6F40) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x274) = *(m2c_block8 *)((char *)(&D_002F6F48) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x134) = *(m2c_block8 *)((char *)(&D_002F6F50) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x27c) = *(m2c_block8 *)((char *)(&D_002F6F58) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x13c) = *(m2c_block8 *)((char *)(&D_002F6F60) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x284) = *(m2c_block8 *)((char *)(&D_002F6F68) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x144) = *(m2c_block8 *)((char *)(&D_002F6F70) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x28c) = *(m2c_block8 *)((char *)(&D_002F6F78) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x14c) = *(m2c_block8 *)((char *)(&D_002F6F80) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x294) = *(m2c_block8 *)((char *)(&D_002F6F88) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x154) = *(m2c_block8 *)((char *)(&D_002F6F90) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x29c) = *(m2c_block8 *)((char *)(&D_002F6F98) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x15c) = *(m2c_block8 *)((char *)(&D_002F6FA0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2a4) = *(m2c_block8 *)((char *)(&D_002F6FA8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x164) = *(m2c_block8 *)((char *)(&D_002F6FB0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2ac) = *(m2c_block8 *)((char *)(&D_002F6FB8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x16c) = *(m2c_block8 *)((char *)(&D_002F6FC0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2b4) = *(m2c_block8 *)((char *)(&D_002F6FC8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x174) = *(m2c_block8 *)((char *)(&D_002F6FD0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2bc) = *(m2c_block8 *)((char *)(&D_002F6FD8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x17c) = *(m2c_block8 *)((char *)(&D_002F6FE0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2c4) = *(m2c_block8 *)((char *)(&D_002F6FE8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x184) = *(m2c_block8 *)((char *)(&D_002F6FF0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2cc) = *(m2c_block8 *)((char *)(&D_002F6FF8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x18c) = *(m2c_block8 *)((char *)(&D_002F7000) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2d4) = *(m2c_block8 *)((char *)(&D_002F7008) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x194) = *(m2c_block8 *)((char *)(&D_002F7010) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2dc) = *(m2c_block8 *)((char *)(&D_002F7018) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x19c) = *(m2c_block8 *)((char *)(&D_002F7020) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2e4) = *(m2c_block8 *)((char *)(&D_002F7028) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1a4) = *(m2c_block8 *)((char *)(&D_002F7030) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2ec) = *(m2c_block8 *)((char *)(&D_002F7038) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1ac) = *(m2c_block8 *)((char *)(&D_002F7040) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2f4) = *(m2c_block8 *)((char *)(&D_002F7048) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1b4) = *(m2c_block8 *)((char *)(&D_002F7050) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x2fc) = *(m2c_block8 *)((char *)(&D_002F7058) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1bc) = *(m2c_block8 *)((char *)(&D_002F7060) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x304) = *(m2c_block8 *)((char *)(&D_002F7068) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1c4) = *(m2c_block8 *)((char *)(&D_002F7070) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x30c) = *(m2c_block8 *)((char *)(&D_002F7078) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1cc) = *(m2c_block8 *)((char *)(&D_002F7080) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x314) = *(m2c_block8 *)((char *)(&D_002F7088) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1d4) = *(m2c_block8 *)((char *)(&D_002F7090) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x31c) = *(m2c_block8 *)((char *)(&D_002F7098) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1dc) = *(m2c_block8 *)((char *)(&D_002F70A0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x324) = *(m2c_block8 *)((char *)(&D_002F70A8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1e4) = *(m2c_block8 *)((char *)(&D_002F70B0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x32c) = *(m2c_block8 *)((char *)(&D_002F70B8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1ec) = *(m2c_block8 *)((char *)(&D_002F70C0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x334) = *(m2c_block8 *)((char *)(&D_002F70C8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1f4) = *(m2c_block8 *)((char *)(&D_002F70D0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x33c) = *(m2c_block8 *)((char *)(&D_002F70D8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x1fc) = *(m2c_block8 *)((char *)(&D_002F70E0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x344) = *(m2c_block8 *)((char *)(&D_002F70E8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x204) = *(m2c_block8 *)((char *)(&D_002F70F0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x34c) = *(m2c_block8 *)((char *)(&D_002F70F8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x20c) = *(m2c_block8 *)((char *)(&D_002F7100) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x354) = *(m2c_block8 *)((char *)(&D_002F7108) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x214) = *(m2c_block8 *)((char *)(&D_002F7110) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x35c) = *(m2c_block8 *)((char *)(&D_002F7118) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x21c) = *(m2c_block8 *)((char *)(&D_002F7120) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x364) = *(m2c_block8 *)((char *)(&D_002F7128) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x224) = *(m2c_block8 *)((char *)(&D_002F7130) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x36c) = *(m2c_block8 *)((char *)(&D_002F7138) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x22c) = *(m2c_block8 *)((char *)(&D_002F7140) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x374) = *(m2c_block8 *)((char *)(&D_002F7148) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x234) = *(m2c_block8 *)((char *)(&D_002F7150) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x37c) = *(m2c_block8 *)((char *)(&D_002F7158) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x23c) = *(m2c_block8 *)((char *)(&D_002F7160) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x384) = *(m2c_block8 *)((char *)(&D_002F7168) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x244) = *(m2c_block8 *)((char *)(&D_002F7170) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x38c) = *(m2c_block8 *)((char *)(&D_002F7178) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x24c) = *(m2c_block8 *)((char *)(&D_002F7180) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x394) = *(m2c_block8 *)((char *)(&D_002F7188) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x254) = *(m2c_block8 *)((char *)(&D_002F7190) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x39c) = *(m2c_block8 *)((char *)(&D_002F7198) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x25c) = *(m2c_block8 *)((char *)(&D_002F71A0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x3a4) = *(m2c_block8 *)((char *)(&D_002F71A8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x264) = *(m2c_block8 *)((char *)(&D_002F71B0) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x3ac) = *(m2c_block8 *)((char *)(&D_002F71B8) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x26c) = *(m2c_block8 *)((char *)(&D_002F6F40) + 0x0);
    *(m2c_block8 *)((char *)(arg0) + 0x3b4) = *(m2c_block8 *)((char *)(&D_002F6F48) + 0x0);
    return Xii_func_00183B74(arg0);
}

extern "C" void func_00183B24(int arg0, int arg1)
{
    Xv_func_00183C4C((void *)arg0);
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

extern "C" int func_00183B74(int arg0)
{
    M2C_FIELD(arg0, int *, 0x2C) = 1;
    M2C_FIELD(arg0, int *, 0x68) = 0x9C;
    M2C_FIELD(arg0, int *, 0x28) = M2C_FIELD(arg0, int *, 0x0) = -1;
    M2C_FIELD(arg0, int *, 0x20) = 0;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x104) = 0;
    M2C_FIELD(arg0, int *, 0x90) = 0;
    M2C_FIELD(arg0, int *, 0x84) = 0;
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00183BB8);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00183C4C);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00183CE0);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00183DB0);

extern "C" int func_00184008(int arg0)
{
    if (M2C_FIELD(arg0, int *, 8) == 0) {
        return -1;
    }
    if (M2C_FIELD(arg0, int *, 0x14) == 1) {
        Xii_func_00184A94(arg0);
    }
    return 0;
}

extern "C" char *func_00184048(int arg0, int arg1)
{
    char *base = (char *)&D_007812C0;
    int v = 0;
    Xiiiii_func_001DC48C((int)(base + 0x22220), arg1 & 0xFFFF, 0xC, (int)&v);
    if (!v) {
        return D_002F71F0;
    }
    return (char *)v;
}

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184098);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3280);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3288);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3290);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F32B0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F32D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3308);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3330);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3348);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3370);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3378);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F33A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F33B8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F33C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F33D8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F33E8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3430);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F34C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3528);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3530);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F35C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3630);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F36A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3708);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3730);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F37A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F37C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3830);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3868);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F38D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3930);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3938);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F39A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3A10);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3A30);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3A50);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3A90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3AD0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3B10);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3B50);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3B90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3BD0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3C10);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3C50);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3C98);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3CE0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3CF8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3D10);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3D20);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3D38);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3D50);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3D68);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3D80);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3D90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3DA0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3DB8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3DD0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3DE8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3DF8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3E10);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3E18);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3E20);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3F48);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F3FF0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F40F0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4208);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F42D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4350);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F43D8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4460);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4508);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F46C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4740);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4788);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4790);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4830);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F48A8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4900);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4990);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F49E0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4A80);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4B48);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4B98);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4C20);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4CB0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4D28);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4D78);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4DB8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4E38);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4ED8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4F78);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F4FF0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5098);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F50D8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5118);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F51B0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5258);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F52C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5318);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5370);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F53C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F53E0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5420);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5470);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F54C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5508);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5550);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F55C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5630);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F56A8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F56F8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5790);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5820);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5860);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5898);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F58C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5908);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5958);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5970);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5978);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F59C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5A18);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5A70);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5AC8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5B20);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5B80);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5B90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5BA8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5BE0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5C30);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5C90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5D10);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5D28);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5D98);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5DD8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5E38);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5E70);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5EE8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5F58);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F5FB8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6008);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6048);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6080);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F60D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F60E8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6130);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6168);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F61D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F61F0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6230);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6260);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6288);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F62C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6330);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6370);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6388);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F63D8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6408);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6468);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6480);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F64A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F64C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F64F0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6558);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6598);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F65C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6610);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6640);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6678);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6710);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6748);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6780);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F67D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F68A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F68C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F68F8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6968);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F69C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F69D8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6A08);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6A30);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6A60);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6A90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6AF8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6B60);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6B98);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6BB0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6C08);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6C38);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6C50);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6C80);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6CB0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6CE0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6D18);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6D40);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6D50);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6D60);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6D70);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6D80);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6D90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6DA0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6DB0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6DC0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6DD8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6DE8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E00);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E08);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E28);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E30);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E38);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E40);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E48);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E50);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E58);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E60);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E68);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E70);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E78);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E80);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E88);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6E98);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EA0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EA8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EB0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EB8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EC0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EC8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6ED0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6ED8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EE0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EE8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EF0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6EF8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F00);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F08);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F10);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F18);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F20);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F28);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F30);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F38);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F40);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F48);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F50);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F58);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F60);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F68);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F70);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F78);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F80);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F88);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F90);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6F98);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FA0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FA8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FB0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FB8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FC0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FC8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FD0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FD8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FE0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FE8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FF0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F6FF8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7000);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7008);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7010);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7018);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7020);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7028);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7030);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7038);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7040);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7048);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7050);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7058);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7060);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7068);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7070);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7078);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7080);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7088);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7090);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7098);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70A8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70B0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70B8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70D8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70E0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70E8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70F0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F70F8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7100);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7108);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7110);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7118);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7120);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7128);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7130);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7138);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7140);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7148);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7150);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7158);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7160);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7168);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7170);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7178);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7180);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7188);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7190);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7198);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F71A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F71A8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F71B0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F71B8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F71C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F71D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F71E0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F71F0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7200);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184128);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001844C4);

extern "C" int func_0018454C(MsgWin *self, const char *theStr)
{
    const unsigned char *p = (const unsigned char *)theStr;
    int n = 0;
loop:
    if ((unsigned int)(p[n] - 0x30) < 10) {
        n++;
        goto loop;
    }
    return n;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_00184578(MsgWin *self, const char *theStr, int *theOut)
{
    char buf[16];
    memset(buf, 0, sizeof(buf));
    int n = func_0018454C(self, theStr);
    if (n) {
        memcpy(buf, theStr, n < 16 ? n : 15);
        *theOut = atoi(buf);
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184578);
#endif


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_00184600(MsgWin *self, const char *theStr, int *theOut)
{
    char buf[16];
    memset(buf, 0, sizeof(buf));
    int n = func_0018454C(self, theStr);
    if (n) {
        memcpy(buf, theStr, n < 16 ? n : 15);
        *theOut = (int)func_0027BBA8(buf, 0, 16);
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184600);
#endif


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_00184698(MsgWin *self, const char *theStr, char *theOut)
{
    memset(theOut, 0, 16);
    int n = func_0018454C(self, theStr);
    if (n) {
        memcpy(theOut, theStr, n < 16 ? n : 15);
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184698);
#endif


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184710);

extern "C" char *func_001847BC(int arg0, int theId)
{
    int i = 0;

    while (D_00299738[i].id != 0x29) {
        if (theId == D_00299738[i].id) {
            return D_00299738[i].name;
        }
        i++;
    }
    return D_00299738[i].name;
}

extern "C" int func_00184820(int arg0, signed char arg1)
{
    int temp_a1 = arg1 & 0xFF;
    unsigned int temp_v1 = temp_a1 - 0x20;
    int var_v0;

    if (((*(int *)&D_002F73E4) ^ 3) != 0) {
        var_v0 = 1;
        if (temp_v1 < 0x60U) {
            return 1;
        }
        if ((unsigned int)(temp_a1 - 0xA0) < 0x40U) {
            return 1;
        }
        goto block_5;
    }
    var_v0 = 1;
    if (temp_v1 >= 0xE0U) {
block_5:
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184874);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001848C4);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184A94);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184F2C);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F72B8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F72C0);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001850FC);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185268);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185348);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001853CC);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001854AC);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185594);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185670);

extern "C" void func_001856F4(MsgWin *self, int theA)
{
    self->m[9] = theA;
}


extern "C" void func_001856FC(void) {
}

extern "C" void func_00185704(MsgWin *self)
{
    if (self->m_system) {
        func_00134FA0((char *)self->m_system + 0x12540, self->m_no, self->m[0x88 / 4]);
        func_00135014((char *)self->m_system + 0x12540, self->m_no, self->m[0x8C / 4]);
    }
}


extern "C" int func_00185760(int arg0)
{
    int temp_a1;
    int var_v0 = 0;

    Xii_func_00185704(arg0);
    temp_a1 = M2C_FIELD(arg0, int *, 0x34);
    if (temp_a1 != 0) {
        if (temp_a1 == 1) {
            var_v0 = ((M2C_FIELD(arg0, int *, 0x78) - M2C_FIELD(arg0, int *, 0x70)) >> 1) -
                     (Xiii_func_00184F2C(arg0, M2C_FIELD(arg0, int *, 0x18) + M2C_FIELD(arg0, int *, 0x1C)) >> 1);
        }
    }
    return var_v0;
}

extern "C" int func_001857C8(int arg0, int arg1, int arg2, unsigned int arg3)
{
    int temp_v1;

    temp_v1 = ((int) ((arg3 >> 0x1F) + arg3) >> 1) - ((int) (arg1 * arg2) / 2);
    return ((M2C_FIELD(arg0, int *, 0x44) ^ 0x26) != 0) ? temp_v1 : (temp_v1 + 0xA);
}

extern "C" int func_001857FC()
{
    return 0;
}


extern "C" int func_00185804()
{
    return 0;
}


extern "C" int func_0018580C(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x38)) = X_func_00185760();
    (*(int *)(int *)((char *)(arg0) + 0x3C)) = (int) ((*(int *)(int *)((char *)(arg0) + 0x3C)) + (*(int *)(int *)((char *)(arg0) + 0x44)));
    return 0;
}


extern "C" int func_00185848()
{
    return 0;
}


extern "C" int func_00185850(int arg0)
{
    int temp_a3;
    int temp_v0;
    int temp_v0_2;

    if (M2C_FIELD(arg0, int *, 0x2C) == 1) {
        Xiiu_func_00135594(M2C_FIELD(arg0, int *, 0x10) + 0x12540, M2C_FIELD(arg0, unsigned int *, 0));
    }
    M2C_FIELD(arg0, int *, 0x38) = Xii_func_00185760(arg0);
    M2C_FIELD(arg0, int *, 0x3C) = 0;
    M2C_FIELD(arg0, int *, 0xB4) = 0;
    M2C_FIELD(arg0, int *, 0xA4) = 0;
    M2C_FIELD(arg0, int *, 0xA8) = 0;
    if (M2C_FIELD(arg0, int *, 0x84) == 1) {
        temp_v0 = Xiii_func_001850FC(arg0, M2C_FIELD(arg0, int *, 0x18) + M2C_FIELD(arg0, int *, 0x1C));
        M2C_FIELD(arg0, int *, 0x80) = temp_v0;
        temp_a3 = M2C_FIELD(arg0, int *, 0x54) + Xiiiiu_func_001857C8(arg0, M2C_FIELD(arg0, int *, 0x44), temp_v0, M2C_FIELD(arg0, unsigned int *, 0x6C));
        M2C_FIELD(arg0, int *, 0x60) = temp_a3;
        Xiiuiii_func_00134A00(M2C_FIELD(arg0, int *, 0x10) + 0x12540, M2C_FIELD(arg0, unsigned int *, 0), M2C_FIELD(arg0, int *, 0x5C), temp_a3, M2C_FIELD(arg0, int *, 0x64));
    } else {
        temp_v0_2 = M2C_FIELD(arg0, int *, 0x54);
        M2C_FIELD(arg0, int *, 0x60) = temp_v0_2;
        Xiiuiii_func_00134A00(M2C_FIELD(arg0, int *, 0x10) + 0x12540, M2C_FIELD(arg0, unsigned int *, 0), M2C_FIELD(arg0, int *, 0x5C), temp_v0_2, M2C_FIELD(arg0, int *, 0x64));
    }
    return 1;
}

extern "C" int func_00185954()
{
    return 0;
}


extern "C" int func_0018595C(int arg0)
{
    int v;
    int n = Xiiii_func_00184578(arg0, M2C_FIELD(arg0, int *, 0x18) + M2C_FIELD(arg0, int *, 0x1C), (int)&v);
    int c;

    M2C_FIELD(arg0, int *, 0x1C) += n;
    if (n <= 0) {
        return 0;
    }
    c = v;
    if (c == 0) {
        M2C_FIELD(arg0, int *, 0xA0) = 0;
    } else {
        M2C_FIELD(arg0, int *, 0xA0) = 1;
    }
    M2C_FIELD(arg0, int *, 0xB0) = c;
    M2C_FIELD(arg0, int *, 0xAC) = c;
    return 0;
}

extern "C" int func_001859CC(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001859FC);

extern "C" int func_00185A74(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185AA4);

extern "C" int func_00185B58(int arg0, unsigned char *arg1, int *arg2)
{
    int v;

    if (*arg1 == 0x67) {
        int n = 1;
        *arg2 = n;
        *arg2 += Xiiii_func_00184578(arg0, (int)(arg1 + n), (int)&v);
    } else {
        *arg2 = Xiiii_func_00184600(arg0, (int)arg1, (int)&v);
    }
    return 0;
}

extern "C" int func_00185BBC(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x34)) = 1;
    (*(int *)(int *)((char *)(arg0) + 0x38)) = X_func_00185760();
    X_func_001856FC(arg0);
    return 0;
}


extern "C" int func_00185BF8(MsgWin *self, const char *theStr, int *theLen)
{
    *theLen = 0;
    return 0;
}


extern "C" int func_00185C04(int arg0)
{
    int temp_a3;
    int temp_v0;

    M2C_FIELD(arg0, int *, 0x84) = 1;
    temp_v0 = Xiii_func_001850FC(arg0, M2C_FIELD(arg0, int *, 0x18) + M2C_FIELD(arg0, int *, 0x1C));
    M2C_FIELD(arg0, int *, 0x80) = temp_v0;
    temp_a3 = M2C_FIELD(arg0, int *, 0x54) + Xiiiiu_func_001857C8(arg0, M2C_FIELD(arg0, int *, 0x44), temp_v0, M2C_FIELD(arg0, unsigned int *, 0x6C));
    M2C_FIELD(arg0, int *, 0x60) = temp_a3;
    Xiiuiii_func_00134A00(M2C_FIELD(arg0, int *, 0x10) + 0x12540, M2C_FIELD(arg0, unsigned int *, 0), M2C_FIELD(arg0, int *, 0x5C), temp_a3, M2C_FIELD(arg0, int *, 0x64));
    return 0;
}

extern "C" int func_00185C84(MsgWin *self, const char *theStr, int *theLen)
{
    *theLen = 0;
    return 0;
}


extern "C" int func_00185C90(int arg0)
{
    int temp_v1;

    M2C_FIELD(arg0, int *, 0x84) = 0;
    temp_v1 = M2C_FIELD(arg0, int *, 0x54);
    M2C_FIELD(arg0, int *, 0x60) = temp_v1;
    Xiiuiii_func_00134A00(M2C_FIELD(arg0, int *, 0x10) + 0x12540, M2C_FIELD(arg0, unsigned int *, 0), M2C_FIELD(arg0, int *, 0x5C), temp_v1, M2C_FIELD(arg0, int *, 0x64));
    return 0;
}

extern "C" int func_00185CDC(MsgWin *self, const char *theStr, int *theLen)
{
    *theLen = 0;
    return 0;
}


extern "C" int func_00185CE8(int arg0)
{
    (*(int *)(int *)((char *)(arg0) + 0x34)) = 0;
    (*(int *)(int *)((char *)(arg0) + 0x38)) = X_func_00185760();
    X_func_001856FC(arg0);
    return 0;
}


extern "C" int func_00185D20(MsgWin *self, const char *theStr, int *theLen)
{
    *theLen = 0;
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185D2C);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185DEC);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185EA4);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185F68);

extern "C" int func_00186018(int arg0)
{
    int v;
    int n = Xiiii_func_00184578(arg0, M2C_FIELD(arg0, int *, 0x18) + M2C_FIELD(arg0, int *, 0x1C), (int)&v);
    int c;

    M2C_FIELD(arg0, int *, 0x1C) += n;
    if (n <= 0) {
        return 0;
    }
    c = v;
    if (c == 0) {
        M2C_FIELD(arg0, int *, 0x94) = 0;
    } else {
        M2C_FIELD(arg0, int *, 0x94) = 1;
    }
    M2C_FIELD(arg0, int *, 0x9C) = c;
    M2C_FIELD(arg0, int *, 0x98) = c;
    return 1;
}

extern "C" int func_00186088(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001860C0);

extern "C" int func_001861CC(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186204(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n > 0) {
        self->m[14] = v;
    }
    return 0;
}


extern "C" int func_00186258(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186290(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n > 0) {
        self->m[15] = v;
    }
    return 0;
}


extern "C" int func_001862E4(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_0018631C);

extern "C" int func_001863BC(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001863F4);

extern "C" int func_00186494(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_001864CC(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n > 0) {
        self->m[34] = v;
        func_00134FA0((char *)self->m_system + 0x12540, self->m_no, v);
    }
    return 0;
}
#else
extern "C" int func_001864CC(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);

    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m[0x22] = v;
    func_00134FA0((char *)self->m_system + 0x12540, self->m_no, v);
    return 0;
}
#endif


extern "C" int func_00186540(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


// NON_MATCHING: close, not identical yet.
#ifdef NON_MATCHING
extern "C" int func_00186578(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n > 0) {
        self->m[35] = v;
        func_00135014((char *)self->m_system + 0x12540, self->m_no, v);
    }
    return 0;
}
#else
extern "C" int func_00186578(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);

    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m[0x23] = v;
    func_00135014((char *)self->m_system + 0x12540, self->m_no, v);
    return 0;
}
#endif


extern "C" int func_001865EC(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186624);

extern "C" int func_00186714(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_0018674C);

extern "C" int func_00186804(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_0018683C(MsgWin *self)
{
    int v;
    self->m_pos += func_00184578(self, self->m_str + self->m_pos, &v);
    return 0;
}


extern "C" int func_00186880(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_001868B8(int arg0)
{
    int v;
    int n = Xiiii_func_00184578(arg0, M2C_FIELD(arg0, int *, 0x18) + M2C_FIELD(arg0, int *, 0x1C), (int)&v);

    M2C_FIELD(arg0, int *, 0x1C) += n;
    if (n <= 0) {
        return 0;
    }
    char *p = (char *)&D_006FBD80;
    Xiii_func_00191E58((int)(p + 0x42BB0), 3, v);
    return 0;
}

extern "C" int func_00186928(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186960);

extern "C" int func_00186A04(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186A3C);

extern "C" int func_00186AB4(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186AEC(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);

    self->m_pos += n;
    if (n > 0) {
        self->m[0x10] = v;
        return 1;
    }
    return 0;
}

extern "C" int func_00186B44(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    int n = func_00184578(self, theStr, &v);
    *theLen += n;
    return n > 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186B80);

extern "C" int func_00186C38(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186C70(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    return n > 0;
}


extern "C" int func_00186CB8(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    int n = func_00184578(self, theStr, &v);
    *theLen += n;
    return n > 0;
}


extern "C" int func_00186CF4(MsgWin *self)
{
    self->m[8] = self->m[8] != 1;
    return 1;
}


extern "C" int func_00186D0C()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186D14);

extern "C" int func_00186DC4(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186DF4);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186EF4);

extern "C" int func_00186F90(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186FC0);

extern "C" int func_0018704C(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_0018707C);

extern "C" int func_00187114(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00187144);

extern "C" int func_00187220(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00187250(MsgWin *self)
{
    self->m[0x30 / 4] = 1;
    func_00134F2C((char *)self->m_system + 0x12540, self->m_no, 1);
    return 0;
}


extern "C" int func_0018728C()
{
    return 0;
}


extern "C" int func_00187294(MsgWin *self)
{
    self->m[0x30 / 4] = 0;
    func_00134F2C((char *)self->m_system + 0x12540, self->m_no, 0);
    return 0;
}


extern "C" int func_001872CC()
{
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001872D4);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00187368);

extern "C" int func_001873FC()
{
    return 1;
}


extern "C" int func_00187404()
{
    return 1;
}


extern "C" int func_0018740C()
{
    return 0;
}


extern "C" int func_00187414()
{
    return 0;
}


// Two windows of 0x3BC bytes: the copied pointer keeps the first call's
// argument separate from the parameter (the game copies $a0 to $s0 and back).
extern "C" int func_0018741C(int arg0)
{
    MsgWin *p = (MsgWin *)arg0;
    MsgWin *q;
    int i;
    q = p;
    i = 1;
    for (; i >= 0; i--) {
        Xv_func_00183BB8(q);
        q = (MsgWin *)((char *)q + 0x3BC);
        p = q;
    }
    return 0;
}

extern "C" int func_00187464(int arg0)
{
    MsgWin *p = (MsgWin *)arg0;
    MsgWin *q;
    int i;
    q = p;
    i = 1;
    for (; i >= 0; i--) {
        Xv_func_00183C4C(q);
        q = (MsgWin *)((char *)q + 0x3BC);
        p = q;
    }
    return 0;
}

extern "C" int func_001874AC(int arg0)
{
    MsgWin *p = (MsgWin *)arg0;
    MsgWin *q;
    int i;
    q = p;
    i = 1;
    for (; i >= 0; i--) {
        Xi_func_00184008(q);
        q = (MsgWin *)((char *)q + 0x3BC);
        p = q;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001874F4);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F7398);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73A0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73A8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73B0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73B8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73C0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73C8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73D0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73D8);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73E0);

INCLUDE_RODATA("asm/nonmatchings/msg/msgman", D_002F73E4);
