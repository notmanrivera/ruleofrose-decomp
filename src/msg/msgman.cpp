#include "msg/msgman.h"
#include "mag/magsystem.h"
#include "game/gamman.h"
#include "spr/sprtexture.h"
#include "include_asm.h"
extern "C" void func_00135088(MagScene *, int, int, int, int);
extern "C" void func_0013511C(MagScene *, int, int, int, int);
extern "C" void func_00134A00(MagScene *, unsigned int, int, int, int);
extern "C" void func_00135594(MagScene *, unsigned int);
extern "C" void func_00134FA0(MagScene *, int, int);
extern "C" void func_00135014(MagScene *, int, int);
extern "C" void func_00134F2C(MagScene *, int, int);
extern "C" int func_00191BA8(S2dMes *, int, int, int);
extern "C" int func_00191C64(S2dMes *, int, int, int);
extern "C" int func_00191D20(S2dMes *, int, int);
extern "C" int func_00191D74(S2dMes *, int, int);
extern "C" int func_00191DC8(S2dMes *, int, int);
extern "C" int func_00191E04(S2dMes *, int, int);
extern "C" int func_00191E58(S2dMes *, int, int);
extern "C" int func_00191ED0(S2dMes *, int);
extern "C" int func_00191F98(S2dMes *, int);
extern "C" int func_001E5250(void *, int, int, int, int, int);
extern "C" int func_001DC48C(void *, int, int, int *);
extern "C" void func_001801C8(void *, int);
extern "C" int func_00279C98(char *, const char *, ...);
extern "C" long long func_0027BBA8(const char *, int, int);
extern "C" int func_00183BB8(MsgWin *);
extern "C" int func_00184A94(MsgWin *);
extern "C" int func_00184F2C(MsgWin *, const char *);
extern "C" int func_001850FC(MsgWin *, const char *);
extern "C" void func_00185594(MsgWin *, int);
extern "C" int atoi(const char *);

extern "C" int func_001831A8(MsgQueue *arg0);
extern "C" int func_001831C4(MsgQueue *self);
extern "C" int func_001831CC(MsgQueue *self);
extern "C" void func_001831F8(MsgQueue *self, const char *src, int len);
extern "C" char *func_001832A4(MsgQueue *self);
extern "C" void func_001832B8(MsgQueue *self, int theN);
extern "C" int func_00183B74(MsgWin *arg0);
extern "C" int func_00183C4C(MsgWin *self);
extern "C" int func_00184008(MsgWin *arg0);
extern "C" char *func_00184048(MsgWin *arg0, int arg1);
extern "C" int func_001844C4(MsgWin *arg0, const char *arg1, const char *arg2);
extern "C" int func_0018454C(MsgWin *self, const char *theStr);
extern "C" int func_00184578(MsgWin *self, const char *theStr, int *theOut);
extern "C" int func_00184600(MsgWin *self, const char *theStr, int *theOut);
extern "C" int func_00184698(MsgWin *self, const char *theStr, char *theOut);
extern "C" int func_00184710(MsgWin *arg0, char *arg1);
extern "C" char *func_001847BC(MsgWin *arg0, int theId);
extern "C" int func_00184820(MsgWin *arg0, signed char arg1);
extern "C" void func_00185268(MsgWin *self, int arg1);
extern "C" void func_00185348(MsgWin *self);
extern "C" void func_001853CC(MsgWin *arg0, int arg1);
extern "C" void func_001854AC(MsgWin *self);
extern "C" void func_00185670(MsgWin *self);
extern "C" void func_001856F4(MsgWin *self, int theA);
extern "C" void func_00185704(MsgWin *self);
extern "C" int func_00185760(MsgWin *arg0);
extern "C" int func_001857C8(MsgWin *arg0, int arg1, int arg2, unsigned int arg3);
extern "C" int func_001857FC();
extern "C" int func_00185804();
extern "C" int func_0018580C(MsgWin *arg0);
extern "C" int func_00185848();
extern "C" int func_00185850(MsgWin *arg0);
extern "C" int func_00185954();
extern "C" int func_0018595C(MsgWin *arg0);
extern "C" int func_001859CC(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_001859FC(MsgWin *arg0);
extern "C" int func_00185A74(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00185AA4(MsgWin *self);
extern "C" int func_00185B58(MsgWin *arg0, unsigned char *arg1, int *arg2);
extern "C" int func_00185BBC(MsgWin *arg0);
extern "C" int func_00185BF8(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00185C04(MsgWin *arg0);
extern "C" int func_00185C84(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00185C90(MsgWin *arg0);
extern "C" int func_00185CDC(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00185CE8(MsgWin *arg0);
extern "C" int func_00185D20(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00185D2C(MsgWin *self);
extern "C" int func_00185DEC(MsgWin *self, const unsigned char *theStr, int *theLen);
extern "C" int func_00185EA4(MsgWin *self);
extern "C" int func_00185F68(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186018(MsgWin *arg0);
extern "C" int func_00186088(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_001861CC(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186204(MsgWin *self);
extern "C" int func_00186258(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186290(MsgWin *self);
extern "C" int func_001862E4(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_001863BC(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186494(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_001864CC(MsgWin *self);
extern "C" int func_00186540(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186578(MsgWin *self);
extern "C" int func_001865EC(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186624(MsgWin *self);
extern "C" int func_00186714(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_0018674C(MsgWin *self);
extern "C" int func_00186804(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_0018683C(MsgWin *self);
extern "C" int func_00186880(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_001868B8(MsgWin *arg0);
extern "C" int func_00186928(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186960(MsgWin *self);
extern "C" int func_00186A04(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186A3C(MsgWin *self);
extern "C" int func_00186AB4(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186AEC(MsgWin *self);
extern "C" int func_00186B44(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186B80(MsgWin *self);
extern "C" int func_00186C38(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186C70(MsgWin *self);
extern "C" int func_00186CB8(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186CF4(MsgWin *self);
extern "C" int func_00186D0C();
extern "C" int func_00186D14(MsgWin *self);
extern "C" int func_00186DC4(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186EF4(MsgWin *self);
extern "C" int func_00186F90(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00186FC0(MsgWin *self);
extern "C" int func_0018704C(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_0018707C(MsgWin *self);
extern "C" int func_00187114(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00187220(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_00187250(MsgWin *self);
extern "C" int func_0018728C();
extern "C" int func_00187294(MsgWin *self);
extern "C" int func_001872CC();
extern "C" int func_001872D4(MsgWin *self);
extern "C" int func_00187368(MsgWin *self, const char *theStr, int *theLen);
extern "C" int func_001873FC();
extern "C" int func_00187404();
extern "C" int func_0018740C();
extern "C" int func_00187414();
extern "C" int func_0018741C(MsgWin *arg0);
extern "C" int func_00187464(MsgWin *arg0);
extern "C" int func_001874AC(MsgWin *arg0);


extern MsgWin::Command D_002F6F40;
extern MsgWin::Parser D_002F6F48;
extern MsgWin::Command D_002F6F50;
extern MsgWin::Parser D_002F6F58;
extern MsgWin::Command D_002F6F60;
extern MsgWin::Parser D_002F6F68;
extern MsgWin::Command D_002F6F70;
extern MsgWin::Parser D_002F6F78;
extern MsgWin::Command D_002F6F80;
extern MsgWin::Parser D_002F6F88;
extern MsgWin::Command D_002F6F90;
extern MsgWin::Parser D_002F6F98;
extern MsgWin::Command D_002F6FA0;
extern MsgWin::Parser D_002F6FA8;
extern MsgWin::Command D_002F6FB0;
extern MsgWin::Parser D_002F6FB8;
extern MsgWin::Command D_002F6FC0;
extern MsgWin::Parser D_002F6FC8;
extern MsgWin::Command D_002F6FD0;
extern MsgWin::Parser D_002F6FD8;
extern MsgWin::Command D_002F6FE0;
extern MsgWin::Parser D_002F6FE8;
extern MsgWin::Command D_002F6FF0;
extern MsgWin::Parser D_002F6FF8;
extern MsgWin::Command D_002F7000;
extern MsgWin::Parser D_002F7008;
extern MsgWin::Command D_002F7010;
extern MsgWin::Parser D_002F7018;
extern MsgWin::Command D_002F7020;
extern MsgWin::Parser D_002F7028;
extern MsgWin::Command D_002F7030;
extern MsgWin::Parser D_002F7038;
extern MsgWin::Command D_002F7040;
extern MsgWin::Parser D_002F7048;
extern MsgWin::Command D_002F7050;
extern MsgWin::Parser D_002F7058;
extern MsgWin::Command D_002F7060;
extern MsgWin::Parser D_002F7068;
extern MsgWin::Command D_002F7070;
extern MsgWin::Parser D_002F7078;
extern MsgWin::Command D_002F7080;
extern MsgWin::Parser D_002F7088;
extern MsgWin::Command D_002F7090;
extern MsgWin::Parser D_002F7098;
extern MsgWin::Command D_002F70A0;
extern MsgWin::Parser D_002F70A8;
extern MsgWin::Command D_002F70B0;
extern MsgWin::Parser D_002F70B8;
extern MsgWin::Command D_002F70C0;
extern MsgWin::Parser D_002F70C8;
extern MsgWin::Command D_002F70D0;
extern MsgWin::Parser D_002F70D8;
extern MsgWin::Command D_002F70E0;
extern MsgWin::Parser D_002F70E8;
extern MsgWin::Command D_002F70F0;
extern MsgWin::Parser D_002F70F8;
extern MsgWin::Command D_002F7100;
extern MsgWin::Parser D_002F7108;
extern MsgWin::Command D_002F7110;
extern MsgWin::Parser D_002F7118;
extern MsgWin::Command D_002F7120;
extern MsgWin::Parser D_002F7128;
extern MsgWin::Command D_002F7130;
extern MsgWin::Parser D_002F7138;
extern MsgWin::Command D_002F7140;
extern MsgWin::Parser D_002F7148;
extern MsgWin::Command D_002F7150;
extern MsgWin::Parser D_002F7158;
extern MsgWin::Command D_002F7160;
extern MsgWin::Parser D_002F7168;
extern MsgWin::Command D_002F7170;
extern MsgWin::Parser D_002F7178;
extern MsgWin::Command D_002F7180;
extern MsgWin::Parser D_002F7188;
extern MsgWin::Command D_002F7190;
extern MsgWin::Parser D_002F7198;
extern MsgWin::Command D_002F71A0;
extern MsgWin::Parser D_002F71A8;
extern MsgWin::Command D_002F71B0;
extern MsgWin::Parser D_002F71B8;
#include "sdk/string.h"
static inline S2dMes *messageSprites(MagScene *scene) { return &scene->m_s2dMes; }
static inline void *uniqueObjects(GamMan *game) { return game->m_unq; }
static inline void *getGamSnd(GamMan *game) { return game->m_snd; }
static inline void msg6624_set(S2dMes *sub, int ch, int val)
{
    func_00191F98(sub, ch);
    func_00191E04(sub, ch, val);
}
extern char *D_002997D0[];


extern const char D_002F7200[];
extern int *D_007B205C;
extern int D_007B2580;
extern MagScene D_006FBD80;

extern MsgNameEnt D_00299738[];
extern int D_002F73E4;
extern char D_002F71F0[];
extern GamMan D_007812C0;
extern const char *D_00298FE8[];



extern "C" int func_001831A8(MsgQueue *arg0)
{
    int used = arg0->m_used;
    int space = arg0->m_size - arg0->m_pos;
    return used < space ? used : space;
}


extern "C" int func_001831C4(MsgQueue *self)
{
    return self->m_used;
}


extern "C" int func_001831CC(MsgQueue *self)
{
    return self->m_size - func_001831C4(self);
}


extern "C" void func_001831F8(MsgQueue *self, const char *src, int len)
{
    while (len > 0) {
        int chunk = self->m_size - self->m_wpos;
        if (len < chunk) {
            chunk = len;
        }
        if (chunk < 0) {
            chunk = 0;
        }
        len -= chunk;
        memcpy(self->m_buf + self->m_wpos, src, chunk);
        src += chunk;
        self->m_wpos = (self->m_wpos + chunk) % self->m_size;
        self->m_used += chunk;
    }
}

extern "C" char *func_001832A4(MsgQueue *self)
{
    return self->m_buf + self->m_pos;
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


MsgWin::MsgWin()
{
    this->m_open = 0;
    this->m_str = 0;
    this->m_commands[0] = D_002F6F40;
    this->m_parsers[0] = D_002F6F48;
    this->m_commands[1] = D_002F6F50;
    this->m_parsers[1] = D_002F6F58;
    this->m_commands[2] = D_002F6F60;
    this->m_parsers[2] = D_002F6F68;
    this->m_commands[3] = D_002F6F70;
    this->m_parsers[3] = D_002F6F78;
    this->m_commands[4] = D_002F6F80;
    this->m_parsers[4] = D_002F6F88;
    this->m_commands[5] = D_002F6F90;
    this->m_parsers[5] = D_002F6F98;
    this->m_commands[6] = D_002F6FA0;
    this->m_parsers[6] = D_002F6FA8;
    this->m_commands[7] = D_002F6FB0;
    this->m_parsers[7] = D_002F6FB8;
    this->m_commands[8] = D_002F6FC0;
    this->m_parsers[8] = D_002F6FC8;
    this->m_commands[9] = D_002F6FD0;
    this->m_parsers[9] = D_002F6FD8;
    this->m_commands[10] = D_002F6FE0;
    this->m_parsers[10] = D_002F6FE8;
    this->m_commands[11] = D_002F6FF0;
    this->m_parsers[11] = D_002F6FF8;
    this->m_commands[12] = D_002F7000;
    this->m_parsers[12] = D_002F7008;
    this->m_commands[13] = D_002F7010;
    this->m_parsers[13] = D_002F7018;
    this->m_commands[14] = D_002F7020;
    this->m_parsers[14] = D_002F7028;
    this->m_commands[15] = D_002F7030;
    this->m_parsers[15] = D_002F7038;
    this->m_commands[16] = D_002F7040;
    this->m_parsers[16] = D_002F7048;
    this->m_commands[17] = D_002F7050;
    this->m_parsers[17] = D_002F7058;
    this->m_commands[18] = D_002F7060;
    this->m_parsers[18] = D_002F7068;
    this->m_commands[19] = D_002F7070;
    this->m_parsers[19] = D_002F7078;
    this->m_commands[20] = D_002F7080;
    this->m_parsers[20] = D_002F7088;
    this->m_commands[21] = D_002F7090;
    this->m_parsers[21] = D_002F7098;
    this->m_commands[22] = D_002F70A0;
    this->m_parsers[22] = D_002F70A8;
    this->m_commands[23] = D_002F70B0;
    this->m_parsers[23] = D_002F70B8;
    this->m_commands[24] = D_002F70C0;
    this->m_parsers[24] = D_002F70C8;
    this->m_commands[25] = D_002F70D0;
    this->m_parsers[25] = D_002F70D8;
    this->m_commands[26] = D_002F70E0;
    this->m_parsers[26] = D_002F70E8;
    this->m_commands[27] = D_002F70F0;
    this->m_parsers[27] = D_002F70F8;
    this->m_commands[28] = D_002F7100;
    this->m_parsers[28] = D_002F7108;
    this->m_commands[29] = D_002F7110;
    this->m_parsers[29] = D_002F7118;
    this->m_commands[30] = D_002F7120;
    this->m_parsers[30] = D_002F7128;
    this->m_commands[31] = D_002F7130;
    this->m_parsers[31] = D_002F7138;
    this->m_commands[32] = D_002F7140;
    this->m_parsers[32] = D_002F7148;
    this->m_commands[33] = D_002F7150;
    this->m_parsers[33] = D_002F7158;
    this->m_commands[34] = D_002F7160;
    this->m_parsers[34] = D_002F7168;
    this->m_commands[35] = D_002F7170;
    this->m_parsers[35] = D_002F7178;
    this->m_commands[36] = D_002F7180;
    this->m_parsers[36] = D_002F7188;
    this->m_commands[37] = D_002F7190;
    this->m_parsers[37] = D_002F7198;
    this->m_commands[38] = D_002F71A0;
    this->m_parsers[38] = D_002F71A8;
    this->m_commands[39] = D_002F71B0;
    this->m_parsers[39] = D_002F71B8;
    this->m_commands[40] = D_002F6F40;
    this->m_parsers[40] = D_002F6F48;
    func_00183B74(this);
}

MsgWin::~MsgWin()
{
    func_00183C4C(this);
}

extern "C" int func_00183B74(MsgWin *arg0)
{
    arg0->m_unk2C = 1;
    arg0->m_unk68 = 0x9C;
    arg0->m_unk28 = arg0->m_no = -1;
    arg0->m_unk20 = 0;
    arg0->m_system = 0;
    arg0->m_str104 = 0;
    arg0->m_unk90 = 0;
    arg0->m_unk84 = 0;
    arg0->m_unk24 = 0;
    arg0->m_unk0C = 0;
    arg0->m_str = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00183BB8);

extern "C" int func_00183C4C(MsgWin *self)
{
    if (self->m_open == 0) {
        return -1;
    }

    self->m_no = -1;
    func_00185268(self, 0);
    func_001853CC(self, 0);
    func_00185594(self, 0);
    func_001856F4(self, 0);
    self->m_system = 0;
    self->m_open = 0;
    if (self->m_unk28 != -1) {
        func_001801C8(&D_007B2580, self->m_unk28);
        self->m_unk28 = -1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00183CE0);

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00183DB0);

extern "C" int func_00184008(MsgWin *arg0)
{
    if (arg0->m_open == 0) {
        return -1;
    }
    if (arg0->m_unk14 == 1) {
        func_00184A94(arg0);
    }
    return 0;
}

extern "C" char *func_00184048(MsgWin *arg0, int arg1)
{
    void *unq = uniqueObjects(&D_007812C0);
    int v = 0;
    func_001DC48C(unq, arg1 & 0xFFFF, 0xC, &v);
    if (!v) {
        return D_002F71F0;
    }
    return (char *)v;
}

// NON_MATCHING: 4/36 differ, 6 edits
#ifdef NON_MATCHING
extern "C" char *func_00184098(MsgWin *self, char *text)
{
    int v;
    unsigned int cmd = func_00184710(self, text);
    if (cmd != 0x29) {
        char *args = text + strlen(func_001847BC(self, cmd));
        if (cmd == 0x19) {
            func_00184578(self, args, &v);
            return func_00184048(self, v);
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00184098);
#endif

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

extern "C" int func_001844C4(MsgWin *arg0, const char *arg1, const char *arg2)
{
    int len = strlen(arg1);
    if (len == 0) {
        return (*arg2 == 0) ? 0 : -1;
    }
    for (int i = 0; i < len; i++) {
        if (arg1[i] != arg2[i]) {
            return -1;
        }
    }
    return 0;
}

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


extern "C" int func_00184578(MsgWin *self, const char *theStr, int *theOut)
{
    char buf[16];
    memset(buf, 0, sizeof(buf));
    int n = func_0018454C(self, theStr);
    if (n == 0) return 0;
    {
        memcpy(buf, theStr, n < 16 ? n : 15);
        *theOut = atoi(buf);
    }
    return n;
}


extern "C" int func_00184600(MsgWin *self, const char *theStr, int *theOut)
{
    char buf[16];
    memset(buf, 0, sizeof(buf));
    int n = func_0018454C(self, theStr);
    if (n == 0) return 0;
    {
        memcpy(buf, theStr, n < 16 ? n : 15);
        *theOut = (int)func_0027BBA8(buf, 0, 16);
    }
    return n;
}


extern "C" int func_00184698(MsgWin *self, const char *theStr, char *theOut)
{
    int n;

    memset(theOut, 0, 16);
    n = func_0018454C(self, theStr);
    if (!n) {
        return n;
    }
    memcpy(theOut, theStr, n < 16 ? n : 15);
    return n;
}


extern "C" int func_00184710(MsgWin *arg0, char *arg1)
{
    if (*arg1 == 0x1A) {
        *arg1 = 0;
    }
    int i = 0;
    while (D_00299738[i].id != 0x29) {
        if (func_001844C4(arg0, D_00299738[i].name, arg1) == 0) {
            return D_00299738[i].id;
        }
        i++;
    }
    return 0x29;
}

extern "C" char *func_001847BC(MsgWin *arg0, int theId)
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

extern "C" int func_00184820(MsgWin *arg0, signed char arg1)
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

extern "C" void func_00185268(MsgWin *self, int arg1)
{
    if (arg1 == 1) {
        self->m_unkC8 = arg1;
        S2dMes *s2d = messageSprites(&D_006FBD80);
        S2dMes *s = s2d;
        int n = self->m_unkCC;
        func_00191F98(s, 0);
        func_00191ED0(s, 0);
        func_00191D20(s, 0, 1);
        func_00191D74(s, 0, 1);
        func_00191DC8(s, 0, (n <= 0) ? 0 : (n - 1));
    } else {
        self->m_unkC8 = 0;
        S2dMes *s2d = messageSprites(&D_006FBD80);
        S2dMes *s = s2d;
        func_00191D20(s, 0, 0);
        func_00191D74(s, 0, 0);
    }
}

extern "C" void func_00185348(MsgWin *self)
{
    if (self->m_unkC8 == 1) {
        S2dMes *s2d = messageSprites(&D_006FBD80);
        S2dMes *sub = s2d;
        func_00191BA8(sub, 0, self->m_unk5C * 0x10, self->m_unk60 * 0x10);
        func_00191C64(sub, 0, self->m_unk38 * 0x10, self->m_unk3C * 0x10);
    }
}

extern "C" void func_001853CC(MsgWin *arg0, int arg1)
{
    MsgWin *self = arg0;
    if (arg1 == 1) {
        self->m_unkD0 = arg1;
        S2dMes *s2d = messageSprites(&D_006FBD80);
        S2dMes *s = s2d;
        int n = self->m_unkD4;
        func_00191F98(s, 2);
        func_00191ED0(s, 2);
        func_00191D20(s, 2, 1);
        func_00191D74(s, 2, 1);
        func_00191DC8(s, 2, (n <= 0) ? 0 : (n - 1));
    } else {
        self->m_unkD0 = 0;
        S2dMes *s2d = messageSprites(&D_006FBD80);
        S2dMes *s = s2d;
        func_00191D20(s, 2, 0);
        func_00191D74(s, 2, 0);
    }
}

extern "C" void func_001854AC(MsgWin *self)
{
    if (self->m_unkD0 == 1) {
        if (self->m_unkC4 == 2) {
            S2dMes *s2d = messageSprites(&D_006FBD80);
            S2dMes *sub = s2d;
            func_00191BA8(sub, 2, self->m_unk50 * 0x10, self->m_unk54 * 0x10);
            int x = (self->m_unk68 >> 1) - 0xC;
            func_00191C64(sub, 2, x * 0x10, 0xBA0);
        } else {
            S2dMes *s2d = messageSprites(&D_006FBD80);
            S2dMes *sub = s2d;
            func_00191BA8(sub, 2, self->m_unk5C * 0x10, self->m_unk60 * 0x10);
            func_00191C64(sub, 2, self->m_unk38 * 0x10, self->m_unk3C * 0x10);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00185594);

extern "C" void func_00185670(MsgWin *self)
{
    if (self->m_unkD8 == 1) {
        S2dMes *s2d = messageSprites(&D_006FBD80);
        S2dMes *sub = s2d;
        func_00191BA8(sub, 1, self->m_unk5C * 0x10, self->m_unk60 * 0x10);
        func_00191C64(sub, 1, self->m_unk48 * 0x10, self->m_unk4C * 0x10);
    }
}

extern "C" void func_001856F4(MsgWin *self, int theA)
{
    self->m_unk24 = theA;
}


extern "C" void func_001856FC(MsgWin *arg0) {
}

extern "C" void func_00185704(MsgWin *self)
{
    if (self->m_system) {
        func_00134FA0(&self->m_system->m_scene, self->m_no, self->m_unk88);
        func_00135014(&self->m_system->m_scene, self->m_no, self->m_unk8C);
    }
}


extern "C" int func_00185760(MsgWin *arg0)
{
    int temp_a1;
    int var_v0 = 0;

    func_00185704(arg0);
    temp_a1 = arg0->m_unk34;
    if (temp_a1 != 0) {
        if (temp_a1 == 1) {
            var_v0 = ((arg0->m_unk78 - arg0->m_unk70) >> 1) -
                     (func_00184F2C(arg0, arg0->m_str + arg0->m_pos) >> 1);
        }
    }
    return var_v0;
}

extern "C" int func_001857C8(MsgWin *arg0, int arg1, int arg2, unsigned int arg3)
{
    int temp_v1;

    temp_v1 = ((int) ((arg3 >> 0x1F) + arg3) >> 1) - ((int) (arg1 * arg2) / 2);
    return ((arg0->m_unk44 ^ 0x26) != 0) ? temp_v1 : (temp_v1 + 0xA);
}

extern "C" int func_001857FC()
{
    return 0;
}


extern "C" int func_00185804()
{
    return 0;
}


extern "C" int func_0018580C(MsgWin *arg0)
{
    arg0->m_unk38 = func_00185760(arg0);
    arg0->m_unk3C = (int) (arg0->m_unk3C + arg0->m_unk44);
    return 0;
}


extern "C" int func_00185848()
{
    return 0;
}


extern "C" int func_00185850(MsgWin *arg0)
{
    int temp_a3;
    int temp_v0;
    int temp_v0_2;

    if (arg0->m_unk2C == 1) {
        func_00135594(&arg0->m_system->m_scene, arg0->m_no);
    }
    arg0->m_unk38 = func_00185760(arg0);
    arg0->m_unk3C = 0;
    arg0->m_unkB4 = 0;
    arg0->m_unkA4 = 0;
    arg0->m_unkA8 = 0;
    if (arg0->m_unk84 == 1) {
        temp_v0 = func_001850FC(arg0, arg0->m_str + arg0->m_pos);
        arg0->m_unk80 = temp_v0;
        temp_a3 = arg0->m_unk54 + func_001857C8(arg0, arg0->m_unk44, temp_v0, arg0->m_unk6C);
        arg0->m_unk60 = temp_a3;
        func_00134A00(&arg0->m_system->m_scene, arg0->m_no, arg0->m_unk5C, temp_a3, arg0->m_unk64);
    } else {
        temp_v0_2 = arg0->m_unk54;
        arg0->m_unk60 = temp_v0_2;
        func_00134A00(&arg0->m_system->m_scene, arg0->m_no, arg0->m_unk5C, temp_v0_2, arg0->m_unk64);
    }
    return 1;
}

extern "C" int func_00185954()
{
    return 0;
}


extern "C" int func_0018595C(MsgWin *arg0)
{
    int v;
    int n = func_00184578(arg0, arg0->m_str + arg0->m_pos, &v);
    int c;

    arg0->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    c = v;
    if (c == 0) {
        arg0->m_unkA0 = 0;
    } else {
        arg0->m_unkA0 = 1;
    }
    arg0->m_unkB0 = c;
    arg0->m_unkAC = c;
    return 0;
}

extern "C" int func_001859CC(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_001859FC(MsgWin *arg0)
{
    int v;
    int n = func_00184578(arg0, arg0->m_str + arg0->m_pos, &v);
    int c;

    arg0->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    c = v;
    if (c == 0) {
        arg0->m_unkA0 = 0;
        arg0->m_unkA8 = 0;
    } else {
        arg0->m_unkA0 = 1;
        arg0->m_unkA8 = 1;
    }
    arg0->m_unkB0 = c;
    arg0->m_unkAC = c;
    return 0;
}

extern "C" int func_00185A74(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00185AA4(MsgWin *self)
{
    int v;
    if (self->m_str[self->m_pos] == 'g') {
        self->m_pos++;
        int n = func_00184578(self, self->m_str + self->m_pos, &v);
        self->m_pos += n;
        if (n <= 0) {
            return 0;
        }
        v = D_007B205C[v];
    } else {
        int n = func_00184600(self, self->m_str + self->m_pos, &v);
        self->m_pos += n;
        if (n <= 0) {
            return 0;
        }
    }
    self->m_unk90 = v;
    return 0;
}

extern "C" int func_00185B58(MsgWin *arg0, unsigned char *arg1, int *arg2)
{
    int v;

    if (*arg1 == 0x67) {
        int n = 1;
        *arg2 = n;
        *arg2 += func_00184578(arg0, (const char *)(arg1 + n), &v);
    } else {
        *arg2 = func_00184600(arg0, (const char *)arg1, &v);
    }
    return 0;
}

extern "C" int func_00185BBC(MsgWin *arg0)
{
    arg0->m_unk34 = 1;
    arg0->m_unk38 = func_00185760(arg0);
    func_001856FC(arg0);
    return 0;
}


extern "C" int func_00185BF8(MsgWin *self, const char *theStr, int *theLen)
{
    *theLen = 0;
    return 0;
}


extern "C" int func_00185C04(MsgWin *arg0)
{
    int temp_a3;
    int temp_v0;

    arg0->m_unk84 = 1;
    temp_v0 = func_001850FC(arg0, arg0->m_str + arg0->m_pos);
    arg0->m_unk80 = temp_v0;
    temp_a3 = arg0->m_unk54 + func_001857C8(arg0, arg0->m_unk44, temp_v0, arg0->m_unk6C);
    arg0->m_unk60 = temp_a3;
    func_00134A00(&arg0->m_system->m_scene, arg0->m_no, arg0->m_unk5C, temp_a3, arg0->m_unk64);
    return 0;
}

extern "C" int func_00185C84(MsgWin *self, const char *theStr, int *theLen)
{
    *theLen = 0;
    return 0;
}


extern "C" int func_00185C90(MsgWin *arg0)
{
    int temp_v1;

    arg0->m_unk84 = 0;
    temp_v1 = arg0->m_unk54;
    arg0->m_unk60 = temp_v1;
    func_00134A00(&arg0->m_system->m_scene, arg0->m_no, arg0->m_unk5C, temp_v1, arg0->m_unk64);
    return 0;
}

extern "C" int func_00185CDC(MsgWin *self, const char *theStr, int *theLen)
{
    *theLen = 0;
    return 0;
}


extern "C" int func_00185CE8(MsgWin *arg0)
{
    arg0->m_unk34 = 0;
    arg0->m_unk38 = func_00185760(arg0);
    func_001856FC(arg0);
    return 0;
}


extern "C" int func_00185D20(MsgWin *self, const char *theStr, int *theLen)
{
    *theLen = 0;
    return 0;
}


extern "C" int func_00185D2C(MsgWin *self)
{
    int v;
    if (self->m_str[self->m_pos] == 'g') {
        self->m_pos++;
        int n = func_00184578(self, self->m_str + self->m_pos, &v);
        self->m_pos += n;
        if (n <= 0) {
            return 0;
        }
        v = D_007B205C[v];
    } else {
        int n = func_00184578(self, self->m_str + self->m_pos, &v);
        self->m_pos += n;
        if (n <= 0) {
            return 0;
        }
    }
    char *s = func_00184048(self, v);
    self->m_unkFC = 0;
    self->m_str104 = s;
    return 0;
}

extern "C" int func_00185DEC(MsgWin *self, const unsigned char *theStr, int *theLen)
{
    int v;
    int n;
    if (*theStr == 'g') {
        *theLen = 1;
        n = func_00184578(self, (const char *)(theStr + *theLen), &v);
        *theLen += n;
        if (n <= 0) {
            return 0;
        }
        v = D_007B205C[v];
    } else {
        n = func_00184578(self, (const char *)theStr, &v);
        *theLen = n;
        if (n <= 0) {
            return 0;
        }
    }
    char *s = func_00184048(self, v);
    self->m_unk100 = 0;
    self->m_str108 = s;
    return 0;
}

extern "C" int func_00185EA4(MsgWin *self)
{
    char buf[32];
    memset(self->m_str104, 0, 0x20);
    int n = func_00184698(self, self->m_str + self->m_pos, buf);
    if (n < 0) {
        return 0;
    }
    self->m_pos += n;
    for (int i = 0; i < n; i++) {
        self->m_buf10C[i * 2] = D_002997D0[buf[i]][0];
        self->m_buf10C[i * 2 + 1] = D_002997D0[buf[i]][1];
    }
    self->m_unkFC = 0;
    self->m_str104 = self->m_buf10C;
    return 0;
}

extern "C" int func_00185F68(MsgWin *self, const char *theStr, int *theLen)
{
    char buf[32];
    int n = func_00184698(self, theStr, buf);
    if (n < 0) {
        return 0;
    }
    *theLen += n;
    for (int i = 0; i < n; i++) {
        self->m_buf10C[i * 2] = D_002997D0[buf[i]][0];
        self->m_buf10C[i * 2 + 1] = D_002997D0[buf[i]][1];
    }
    self->m_unkFC = 0;
    self->m_str104 = self->m_buf10C;
    return 0;
}

extern "C" int func_00186018(MsgWin *arg0)
{
    int v;
    int n = func_00184578(arg0, arg0->m_str + arg0->m_pos, &v);
    int c;

    arg0->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    c = v;
    if (c == 0) {
        arg0->m_unk94 = 0;
    } else {
        arg0->m_unk94 = 1;
    }
    arg0->m_unk9C = c;
    arg0->m_unk98 = c;
    return 1;
}

extern "C" int func_00186088(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


// NON_MATCHING: 53/65 differ, 6 relocs differ (size 0x104, game 0x10C), 10 edits
#ifdef NON_MATCHING
extern "C" int func_001860C0(MsgWin *arg0)
{
    int value;
    int temp_a2;
    int temp_a3;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = func_00184578(arg0, arg0->m_str + arg0->m_pos, &value);
    temp_a2 = arg0->m_pos + temp_v0;
    arg0->m_pos = temp_a2;
    if (temp_v0 > 0) {
        arg0->m_unk24 = value;
        if (value == 0) {
            temp_v0_2 = arg0->m_unk54;
            arg0->m_unk84 = 0;
            arg0->m_unk60 = temp_v0_2;
            func_00134A00(&arg0->m_system->m_scene, arg0->m_no, arg0->m_unk5C, temp_v0_2, arg0->m_unk64);
        } else {
            arg0->m_unk84 = 1;
            arg0->m_unk44 = 0x26;
            temp_v0_3 = func_001850FC(arg0, arg0->m_str + temp_a2);
            arg0->m_unk80 = temp_v0_3;
            temp_a3 = arg0->m_unk54 + func_001857C8(arg0, arg0->m_unk44, temp_v0_3, arg0->m_unk6C);
            arg0->m_unk60 = temp_a3;
            func_00134A00(&arg0->m_system->m_scene, arg0->m_no, arg0->m_unk5C, temp_a3, arg0->m_unk64);
        }
        func_001856F4(arg0, arg0->m_unk24);
        func_001856FC(arg0);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001860C0);
#endif

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
        self->m_unk38 = v;
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
        self->m_unk3C = v;
    }
    return 0;
}


extern "C" int func_001862E4(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


// NON_MATCHING: 21/38 differ, 5 relocs differ (size 0x98, game 0xA0), 11 edits
#ifdef NON_MATCHING
extern "C" int func_0018631C(MsgWin *self)
{
    int result = 0;
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n > 0) {
        self->m_unk50 = v;
        self->m_unk5C = v;
        func_00134A00(&self->m_system->m_scene, self->m_no, v, self->m_unk60, self->m_unk64);
        func_001856FC(self);
        func_001854AC(self);
        func_00185348(self);
        func_00185670(self);
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_0018631C);
#endif

extern "C" int func_001863BC(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


// NON_MATCHING: 21/38 differ, 5 relocs differ (size 0x98, game 0xA0), 11 edits
#ifdef NON_MATCHING
extern "C" int func_001863F4(MsgWin *self)
{
    int result = 0;
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n > 0) {
        self->m_unk54 = v;
        self->m_unk60 = v;
        func_00134A00(&self->m_system->m_scene, self->m_no, self->m_unk5C, v, self->m_unk64);
        func_001856FC(self);
        func_001854AC(self);
        func_00185348(self);
        func_00185670(self);
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001863F4);
#endif

extern "C" int func_00186494(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_001864CC(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);

    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m_unk88 = v;
    func_00134FA0(&self->m_system->m_scene, self->m_no, v);
    return 0;
}


extern "C" int func_00186540(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186578(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);

    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m_unk8C = v;
    func_00135014(&self->m_system->m_scene, self->m_no, v);
    return 0;
}


extern "C" int func_001865EC(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186624(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    func_00135088(&self->m_system->m_scene, self->m_no, v, 0, 0x80);
    S2dMes *s2d = messageSprites(&D_006FBD80);
    S2dMes *sub = s2d;
    msg6624_set(sub, 0, v);
    msg6624_set(sub, 2, v);
    msg6624_set(sub, 1, v);
    return 0;
}

extern "C" int func_00186714(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_0018674C(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    func_0013511C(&self->m_system->m_scene, self->m_no, v, 0, 0x80);
    S2dMes *s2d = messageSprites(&D_006FBD80);
    S2dMes *sub = s2d;
    func_00191E58(sub, 0, v);
    func_00191E58(sub, 2, v);
    func_00191E58(sub, 1, v);
    return 0;
}

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


extern "C" int func_001868B8(MsgWin *arg0)
{
    int v;
    int n = func_00184578(arg0, arg0->m_str + arg0->m_pos, &v);

    arg0->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    S2dMes *s2d = messageSprites(&D_006FBD80);
    func_00191E58(s2d, 3, v);
    return 0;
}

extern "C" int func_00186928(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186960(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    if (self->m_unk28 != -1) {
        func_001801C8(&D_007B2580, self->m_unk28);
        self->m_unk28 = -1;
    }
    self->m_unk28 = func_001E5250(getGamSnd(&D_007812C0), v, -1, 0, 0, 0);
    return 0;
}

extern "C" int func_00186A04(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen += func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186A3C(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    if (self->m_unk28 == -1) {
        return 0;
    }
    func_001801C8(&D_007B2580, self->m_unk28);
    self->m_unk28 = -1;
    return 0;
}

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
        self->m_unk40 = v;
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


extern "C" int func_00186B80(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m_unk44 = v;
    if (self->m_unk84 == 1) {
        int a = func_001850FC(self, self->m_str + self->m_pos);
        self->m_unk80 = a;
        int y = self->m_unk54 + func_001857C8(self, self->m_unk44, a, (unsigned int)self->m_unk6C);
        self->m_unk60 = y;
        func_00134A00(&self->m_system->m_scene, (unsigned int)self->m_no, self->m_unk5C, y, self->m_unk64);
    }
    return 0;
}

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
    self->m_unk20 = self->m_unk20 != 1;
    return 1;
}


extern "C" int func_00186D0C()
{
    return 1;
}


extern "C" int func_00186D14(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m_unkC0 = 1;
    self->m_unkCC = v;
    if (v == 0) {
        func_00185268(self, 0);
    } else {
        func_00185268(self, 1);
    }
    func_001853CC(self, 0);
    if (self->m_unkC4 == 1) {
        self->m_unk38 = self->m_unk68 - self->m_unk40;
    }
    return 1;
}

extern "C" int func_00186DC4(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00186DF4);

extern "C" int func_00186EF4(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m_unkD4 = v;
    if (v == 0) {
        func_001853CC(self, 0);
    } else {
        func_001853CC(self, 1);
    }
    if (self->m_unkC4 == 1) {
        self->m_unk38 = self->m_unk68 - self->m_unk40;
    }
    return 0;
}

extern "C" int func_00186F90(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00186FC0(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m_unkC0 = 1;
    self->m_unkD4 = v;
    if (v == 0) {
        func_001853CC(self, 0);
    } else {
        func_001853CC(self, 1);
    }
    self->m_unkC4 = 2;
    return 1;
}

extern "C" int func_0018704C(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_0018707C(MsgWin *self)
{
    int v;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n <= 0) {
        return 0;
    }
    self->m_unkDC = v;
    if (v == 0) {
        func_00185594(self, 0);
    } else {
        func_00185594(self, 1);
    }
    self->m_unk48 = self->m_unk38;
    self->m_unk4C = self->m_unk3C;
    self->m_unk38 += self->m_unk40;
    return 0;
}

extern "C" int func_00187114(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


// NON_MATCHING: 40/51 differ (size 0xCC, game 0xDC), 25 edits
#ifdef NON_MATCHING
extern "C" int func_00187144(MsgWin *arg0)
{
    int value;
    float var_f0;
    int temp_a1;
    int temp_hi;
    int temp_lo;
    int temp_v0;
    int var_v0;

    temp_v0 = func_00184578(arg0, arg0->m_str + arg0->m_pos, &value);
    var_v0 = 0;
    arg0->m_pos = (int) (arg0->m_pos + temp_v0);
    if (temp_v0 > 0) {
        arg0->m_unkE0 = 1;
        temp_hi = value % 10;
        temp_lo = value / 10;
        temp_a1 = arg0->m_unk44 * temp_hi;
        if (temp_lo != 0) {
            arg0->m_unkF4 = temp_a1;
            arg0->m_unkF8 = 0;
            arg0->m_unkE4 = temp_lo;
            arg0->m_unkE8 = temp_hi;
            var_f0 = (float) temp_a1 / (float) temp_lo;
        } else {
            var_f0 = (float) temp_a1;
            arg0->m_unkF4 = temp_a1;
            arg0->m_unkF8 = 0;
            arg0->m_unkE4 = 0;
            arg0->m_unkE8 = temp_hi;
        }
        arg0->m_unkF0 = 0;
        arg0->m_unkEC = var_f0;
        var_v0 = 1;
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_00187144);
#endif

extern "C" int func_00187220(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    *theLen = func_00184578(self, theStr, &v);
    return 0;
}


extern "C" int func_00187250(MsgWin *self)
{
    self->m_unk30 = 1;
    func_00134F2C(&self->m_system->m_scene, self->m_no, 1);
    return 0;
}


extern "C" int func_0018728C()
{
    return 0;
}


extern "C" int func_00187294(MsgWin *self)
{
    self->m_unk30 = 0;
    func_00134F2C(&self->m_system->m_scene, self->m_no, 0);
    return 0;
}


extern "C" int func_001872CC()
{
    return 0;
}


extern "C" int func_001872D4(MsgWin *self)
{
    int v;
    char *buf = self->m_buf10C;
    int n = func_00184578(self, self->m_str + self->m_pos, &v);
    self->m_pos += n;
    if (n < 0) {
        return 0;
    }
    v = D_007B205C[v];
    func_00279C98(buf, D_002F7200, v);
    self->m_str104 = buf;
    self->m_unkFC = 0;
    return 0;
}

extern "C" int func_00187368(MsgWin *self, const char *theStr, int *theLen)
{
    int v;
    int n = func_00184578(self, theStr, &v);
    *theLen += n;
    if (n < 0) {
        return 0;
    }
    v = D_007B205C[v];
    func_00279C98(self->m_buf10C, D_002F7200, v);
    self->m_str108 = self->m_buf10C;
    self->m_unk100 = 0;
    return 0;
}

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


// Update both message windows.
extern "C" int func_0018741C(MsgWin *windows)
{
    MsgWin *p = windows;
    // The original keeps the two-window loop counter in s1.
    register int i PS2_REG("$17") = 1;
    for (; i >= 0; i--) {
        func_00183BB8(p);
        p++;
    }
    return 0;
}

extern "C" int func_00187464(MsgWin *windows)
{
    MsgWin *p = windows;
    // The original keeps the two-window loop counter in s1.
    register int i PS2_REG("$17") = 1;
    for (; i >= 0; i--) {
        func_00183C4C(p);
        p++;
    }
    return 0;
}

extern "C" int func_001874AC(MsgWin *windows)
{
    MsgWin *p = windows;
    // The original keeps the two-window loop counter in s1.
    register int i PS2_REG("$17") = 1;
    for (; i >= 0; i--) {
        func_00184008(p);
        p++;
    }
    return 0;
}

// NON_MATCHING: 37/50 differ, 1 reloc differs (size 0xC8, game 0xCC), 11 edits
#ifdef NON_MATCHING
extern "C" void func_00183DB0(MsgWin *, int, char *);
extern "C" void func_001874F4(MsgWin *windows, int id, char *text)
{
    if (id >= 0) {
        int slot = 0x378;
        for (int i = 0; i < 2; i++) {
            if (windows[i].m_no == id) return;
        }
        for (int i = 0; i < 2; i++) {
            if (windows[i].m_unk04 == 1) {
                slot = i;
                break;
            }
        }
        if (slot != 0x378) func_00183DB0(&windows[slot], id, text);
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/msg/msgman", func_001874F4);
#endif

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
