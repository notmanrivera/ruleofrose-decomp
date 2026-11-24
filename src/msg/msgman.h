// msg/msgman.h: message windows, their command handlers, and the input queue.
// Member-function pointer tables at +0x12C and +0x274 each contain 41 entries:
// the original rodata stores {delta=0, index=-1, function address} per entry.
#ifndef MSG_MSGMAN_H
#define MSG_MSGMAN_H
#include "ror.h"
class MagSystem;
struct MagMsgReq;
struct MsgWin {
    typedef int (MsgWin::*Command)();
    typedef int (MsgWin::*Parser)(const char *, int *);
    int m_no; // +0x000
    int m_unk04; // +0x004
    int m_open; // +0x008
    int m_unk0C; // +0x00C
    MagSystem * m_system; // +0x010
    int m_unk14; // +0x014
    char * m_str; // +0x018
    int m_pos; // +0x01C
    int m_unk20; // +0x020
    int m_unk24; // +0x024
    int m_unk28; // +0x028
    int m_unk2C; // +0x02C
    int m_unk30; // +0x030
    int m_unk34; // +0x034
    int m_unk38; // +0x038
    int m_unk3C; // +0x03C
    int m_unk40; // +0x040
    int m_unk44; // +0x044
    int m_unk48; // +0x048
    int m_unk4C; // +0x04C
    int m_unk50; // +0x050
    int m_unk54; // +0x054
    int m_unk58; // +0x058
    int m_unk5C; // +0x05C
    int m_unk60; // +0x060
    int m_unk64; // +0x064
    int m_unk68; // +0x068
    unsigned int m_unk6C; // +0x06C
    int m_unk70; // +0x070
    int m_unk74; // +0x074
    int m_unk78; // +0x078
    int m_unk7C; // +0x07C
    int m_unk80; // +0x080
    int m_unk84; // +0x084
    int m_unk88; // +0x088
    int m_unk8C; // +0x08C
    int m_unk90; // +0x090
    int m_unk94; // +0x094
    int m_unk98; // +0x098
    int m_unk9C; // +0x09C
    int m_unkA0; // +0x0A0
    int m_unkA4; // +0x0A4
    int m_unkA8; // +0x0A8
    int m_unkAC; // +0x0AC
    int m_unkB0; // +0x0B0
    int m_unkB4; // +0x0B4
    int m_unkB8; // +0x0B8
    int m_unkBC; // +0x0BC
    int m_unkC0; // +0x0C0
    int m_unkC4; // +0x0C4
    int m_unkC8; // +0x0C8
    int m_unkCC; // +0x0CC
    int m_unkD0; // +0x0D0
    int m_unkD4; // +0x0D4
    int m_unkD8; // +0x0D8
    int m_unkDC; // +0x0DC
    int m_unkE0; // +0x0E0
    int m_unkE4; // +0x0E4
    int m_unkE8; // +0x0E8
    float m_unkEC; // +0x0EC
    int m_unkF0; // +0x0F0
    int m_unkF4; // +0x0F4
    int m_unkF8; // +0x0F8
    int m_unkFC; // +0x0FC
    int m_unk100; // +0x100
    char * m_str104; // +0x104
    char * m_str108; // +0x108
    char m_buf10C[0x20];               // +0x10C
    Command m_commands[41];            // +0x12C
    Parser m_parsers[41];              // +0x274
    MsgWin() asm("func_0018330C");
    ~MsgWin() asm("func_00183B24");
    int func_00184128(MagMsgReq *) asm("func_00184128");
};
struct MsgQueue {
    int m_wpos;                        // +0x00
    int m_pos;                         // +0x04
    int m_used;                        // +0x08
    int m_unk0C;                       // +0x0C
    int m_size;                        // +0x10
    char m_unk14[0x2C];                // +0x14
    char m_buf[1];                     // +0x40: variable-sized queue storage
};
// Text substitution request consumed by func_00184128.
struct MagMsgReq {
    int m_param[16];                   // +0x00
    const char *m_source;                     // +0x40
    char *m_buf;                       // +0x44
    int m_size;                     // +0x48
};
STATIC_ASSERT(sizeof(MagMsgReq) == 0x4C, MagMsgReq_size);
typedef MsgWin MagMsgWork;
typedef MsgQueue RingBuf;
struct MsgNameEnt { int id; char *name; };
STATIC_ASSERT(sizeof(MsgWin::Command) == 8, MsgWin_Command_size);
STATIC_ASSERT(sizeof(MsgWin::Parser) == 8, MsgWin_Parser_size);
STATIC_ASSERT(sizeof(MsgWin) == 0x3BC, MsgWin_size);
extern "C" const char *func_001832E8(unsigned int);
#endif
