// game/gamsnd.h: sound routing and the game's task queue.
// GamSndMan, SND_PARAM, TskTest, TskLogger and CmnITask are symbol names.
// Other names are ours; member offsets follow the constructors and callers.
#ifndef GAME_GAMSND_H
#define GAME_GAMSND_H
#include "ror.h"
#ifdef TARGET_PS2
#pragma interface
#endif
#include "game/gamlist.h"
#include "task/cmnitask.h"
#include "utl/filereader.h"
#include "unk/Eff0.h"

struct ALIGNED(8) SND_PARAM {
    char name[0x1C];
    int id;                            // +0x1C
    unsigned short m_unk20, m_unk22, m_unk24, m_unk26;
    unsigned short m_unk28;
    unsigned short m_unk2A, m_unk2C, m_unk2E, m_unk30;
    unsigned short m_unk32, m_unk34, m_unk36;
};
// File buffers have word alignment. Whole-table assignment emits the game's
// runtime eight-byte alignment check; individual SND_PARAM copies are aligned.
struct GamSndSETable { SND_PARAM m_entries[0x400]; } __attribute__((packed, aligned(4)));
struct GamSndStreamTable { SND_PARAM m_entries[0x384]; } __attribute__((packed, aligned(4)));
struct GamSndMessage {
    union { int m_unk00; unsigned int m_u00; float m_f00; };
    int m_unk04;
    union { int m_unk08; float m_f08; };
    int m_unk0C;
    int m_unk10, m_unk14;
    float m_unk18;
    int m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C;
    int m_unk30, m_unk34, m_unk38, m_unk3C;
};
struct GamSndChannel {
    unsigned int flags;                 // +0x00
    int m_unk04, m_unk08;
    unsigned int m_unk0C;
    int m_unk10, m_unk14, m_unk18, m_unk1C, m_unk20, m_unk24;
    GamSndChannel() { m_unk14 = -1; m_unk18 = -1; }
    bool isFree() const { return (flags & 1) == 0; }
};
struct GamSndChannels {
    GamSndChannel *m_begin, *m_end;      // +0x00
    int m_max;                         // +0x08
    unsigned char m_unk0C[0x34];
    GamSndChannel m_buf[0x30];          // +0x40
    void clear()
    {
        for (GamSndChannel *p = m_begin; p != m_end; ++p) p->~GamSndChannel();
        m_end = m_buf;
        m_max = 0x30;
        m_begin = m_buf;
    }
};
struct ALIGNED(16) GamSnd3D {
    TskVec4 m_unk00;
    EffVec3 position;                // +0x10
    int m_unk1C;
    unsigned int id;                    // +0x20
    int handle;                        // +0x24
    unsigned int flags;                 // +0x28
    int zero;                          // +0x2C
    int scene;                         // +0x30
    SND_PARAM *data;                    // +0x34
    float distance;                    // +0x38
    int a, b;                          // +0x3C, +0x40
    unsigned char m_unk44[0x0C];
};
struct GamSndBgm {
    int m_unk00, m_unk04, m_unk08, m_unk0C, m_unk10;
    int m_unk14, m_unk18, m_unk1C, m_unk20;
};
struct GamSndStream { int m_unk00, m_unk04, m_unk08; };
struct GamSndAmbient { int m_unk00, m_unk04, m_unk08, m_unk0C; };
struct GamSndMan {
    int m_mode;                        // +0x0000
    unsigned char m_unk04[0x3C];
    GamPool<GamSnd3D, 32> m_queue;      // +0x0040
    GamSndChannels m_channels;          // +0x0D40
    char m_unk1500[0x40];
    SND_PARAM *m_seTable;           // +0x1540
    SND_PARAM *m_streamTable;   // +0x1544
    int m_unk1548, m_unk154C;
    SND_PARAM m_default;                // +0x1550
    int m_unk1588, m_unk158C, m_unk1590, m_unk1594, m_unk1598, m_unk159C;
    GamSndBgm m_unk15A0[5];             // +0x15A0
    GamSndStream m_unk1654[3];          // +0x1654
    int m_unk1678, m_unk167C;
    int m_unk1680, m_currentBgm;       // +0x1680, +0x1684
    GamSndAmbient m_ambient[8];        // +0x1688
    int m_unk1708, m_unk170C;
    int m_unk1710, m_unk1714, m_unk1718;
    int m_unk171C, m_unk1720, m_unk1724;
    int m_bankIds[65];                  // +0x1728
    char m_filename[0x40];              // +0x182C
    float m_unk186C;
    unsigned int m_unk1870;
    void *m_vtable;                     // +0x1874 (original virtual base layout)
};

struct GamTaskNode {
    CmnITask *obj;
    GamTaskNode *next;
    int state, id;
    int *m_unk10;
    unsigned int flags;
    void *m_unk18;
    int m_unk1C, m_unk20, m_unk24, m_unk28, m_unk2C, m_unk30;
    unsigned int prio;
    int m_unk38, m_unk3C;
};
struct GamTaskBase {
    void *m_vtable;
    int m_unk04, m_unk08, m_unk0C, m_unk10, m_unk14;
    int m_prio;
    int m_unk1C, m_unk20, m_unk24;
    int m_unk28;
    unsigned char m_unk2C[0x18];
    GamTaskBase() asm("func_00203D94");
    ~GamTaskBase() asm("func_00203DA8");
};
struct GamTaskMan {
    GamTaskNode *head0, *head4;
    int m_unk08;
    unsigned char m_unk0C[0x34];
    GamTaskBase m_base;                 // +0x40
    int arr[0x80];                      // +0x84
    int *end;                          // +0x284
    int m_history[0x100];               // +0x288
    GamTaskNode *popReady()
    {
        GamTaskNode *p = head0;
        if (p == 0 || (unsigned int)m_base.m_prio < p->prio) return 0;
        head0 = p->next;
        p->next = 0;
        return p;
    }
    GamTaskMan() asm("func_001E7094");
    ~GamTaskMan() asm("func_001E70DC");
};
struct GamSndPan { const TskVec4 *m_position; const TskVec4 *m_direction; float m_angle; const TskVec4 *m_source; };
class TskSnd;
class TskLogger : public CmnITask {
public:
    int m_unk04, m_unk08;
    TskLogger(int) asm("func_001E7ED8");
    virtual int get_task_type() { return 0x11; }
    virtual void init() {}
    virtual int exec(int, int, void *) asm("TskLogger__vfunc_04");
    virtual void term() {}
    virtual ~TskLogger();
};
class TskTest : public CmnITask {
public:
    virtual int get_task_type() { return 0; }
    virtual void init() {}
    virtual int exec(int, int, void *) asm("TskTest__vfunc_04");
    virtual void term() {}
};

STATIC_ASSERT(sizeof(SND_PARAM) == 0x38, SND_PARAM_size);
STATIC_ASSERT(sizeof(GamSndSETable) == 0xE000, GamSndSETable_size);
STATIC_ASSERT(sizeof(GamSndStreamTable) == 0xC4E0, GamSndStreamTable_size);
STATIC_ASSERT(sizeof(GamSndChannel) == 0x28, GamSndChannel_size);
STATIC_ASSERT(sizeof(GamSndMessage) == 0x40, GamSndMessage_size);
STATIC_ASSERT(sizeof(GamSnd3D) == 0x50, GamSnd3D_size);
STATIC_ASSERT(sizeof(GamSndMan) == 0x1880, GamSndMan_size);
STATIC_ASSERT(sizeof(GamTaskNode) == 0x40, GamTaskNode_size);

extern "C" {
void func_001E107C(GamSndMan *);
void func_001E111C(GamSndMan *, int);
void func_001E1FA4(GamSndMan *);
void func_001E1920(GamSndMan *, int, int, int);
void func_001E3C24(GamSndMan *, EffVec3 *);
void func_001E4120(GamSndMan *);
int func_001E43A4(GamSndMan *, unsigned int, int, unsigned int);
void func_001E43E0(GamSndMan *, char *, int *, int *);
void func_001E44B4(GamSndMan *, int, int, void *, int);
void func_001E46B8(GamSndMan *, int);
int func_001E4908(GamSndMan *, int, SND_PARAM **, int);
int func_001E4A0C(GamSndMan *, const char *);
int func_001E4B48(GamSndMan *, int, SND_PARAM *);
int func_001E4C1C(GamSndMan *, int, SND_PARAM **);
int func_001E4CBC(GamSndMan *, int);
int func_001E4D04(GamSndMan *, const char *);
int func_001E4EBC(GamSndMan *, unsigned int, int, EffVec4 *, int);
int func_001E50C8(GamSndMan *, int, int, int, float, int, int, int);
int func_001E5250(GamSndMan *, int, int, EffVec4 *, int, int);
int func_001E5428(GamSndMan *, int, int, int, int, int, int, float);
int func_001E5660(GamSndMan *, unsigned int, int, GamSndMessage *);
int func_001E5B60(GamSndMan *, int, int);
int func_001E5C40(GamSndMan *, int, int, int, int);
int func_001E5E58(GamSndMan *, unsigned int, int, GamSndMessage *);
int func_001E6368(GamSndMan *, int, int);
int func_001E63C0(GamSndMan *, int, int, int, int);
int func_001E649C(GamSndMan *, unsigned int, int);
void func_001E6570(GamSndMan *, int);
void func_001E6734(GamSndMan *, int, int, int, int, int);
void func_001E6E00(int, void *, SND_PARAM *, int *, int *, float);
void func_001E34EC(GamSndMan *, int, int);
void func_001E2AA0(GamSndMan *, unsigned int, int);
void func_001E7184(GamTaskMan *, GamTaskNode *);
int func_001E71FC(GamTaskMan *, int, int, int, int, CmnITask *, void *, int *, int);
void func_001E7340(GamTaskMan *, GamTaskNode *, int);
void func_001E7698(GamTaskMan *, GamTaskNode *);
int func_001E76B8(GamTaskMan *, int);
void func_001E7724(GamTaskMan *, int);
CmnITask *func_001E79C0(GamTaskMan *, int);
void func_001E7C7C(GamTaskMan *, GamTaskNode *);
void func_001E7D08(GamTaskMan *, GamTaskNode *);
int func_001E7D7C(GamTaskMan *, int);
void func_001E7DE8(GamTaskMan *, int);
void func_001E7E50(GamTaskMan *, int);
}
#endif
