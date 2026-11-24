#include "game/gamman.h"
#include "game/gamtrg.h"
#include "mag/magscene.h"
#include "sdk/math.h"
#include "game/gamsnd.h"
#include "sdk/string.h"
#include "bed/bedmemory.h"
#include "snd/sndman.h"
#include "ror.h"
#include "include_asm.h"
#include "task/cmnitask.h"
#include "utl/filereader.h"


void heapFree(void *);
void *operator new(unsigned int);
void operator delete(void *);
extern SndMan D_007B2580;
extern GamMan D_007812C0;
extern GamTaskMan D_007A3D80;
extern unsigned int D_007A320C;
extern BedMemory D_006E9800;
extern MagScene D_006FBD80;
extern char D_00298EE0[];
extern const char D_002FD770[];
extern int _vt$9GamSndMan;
extern "C" {
int atoi(const char *);
int abs(int);
int snprintf(char *, unsigned int, const char *, ...);
void func_001C6A40(GamMan *, unsigned int);
int func_001C6C28(GamMan *);
int func_001CBE38(GamMan *, unsigned int);
GamTrgMapInfo *func_0017EA44(void *, int);
void func_001DBA3C(GamMapObj *, unsigned int, float *, int);
int func_0017F5E8(SndMan *, int);
int func_0017F8FC(SndMan *, int);
int func_0017FD58(SndMan *, char *, int, int, int);
int func_0017FF58(SndMan *, float, int, int, int, int);
void func_00180078(SndMan *, int, int);
int func_001800D0(SndMan *, int);
void func_001801C8(SndMan *, int);
int func_001809D8(SndMan *, int, void *, int);
int func_00180B30(SndMan *, int);
int func_00180CA8(SndMan *, int);
int func_00180CE0(SndMan *, int, int, int, float, int);
int func_00180EA8(SndMan *, int);
void func_001F8FC0(TskSnd *, unsigned int, GamSndMessage *);
void func_0023A080(int);
void rxSndReverbSetDepth(int, int);
void func_002378B0(void *, void *, const void *);
void func_00237408(void *, const void *, const void *);
void func_002375D8(void *, void *);
float func_00237580(void *, void *);
}
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))

// The generic byte-copy inline preserves the unaligned default-record copy.
static inline GamSndChannel *channelAt(GamSndChannels *channels, int byteOffset)
{
    return (GamSndChannel *)((char *)channels->m_begin + byteOffset);
}
static inline void copySoundParam(void *dst, const void *src) { memcpy(dst, src, sizeof(SND_PARAM)); }
static inline DogEntityEx *soundCamera(MagScene *scene) { return &scene->m_soundTransform; }
static inline GamMapObj *soundMap(GamMan *game) { return (GamMapObj *)game->m_mapObj; }
static inline bool soundDisabled(const unsigned int *flags, unsigned int mask) { return (*flags & mask) != 0; }
extern "C" int func_001E0BB0(GamTrgMan *arg0, int arg1)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;

    it = GamList<GamTrgElem>::iterator(arg0->m_list2.m_used.m_head.m_next);
    last = arg0->m_list2.end();
    while (it != last) {
        if ((*it).m_id == arg1)
            return 1;
        ++it;
    }
    return 0;
}

extern "C" int func_001E0C2C(GamTrgMan *arg0, int arg1, int arg2, unsigned int arg3)
{
    GamPool<GamTrgElem, 0x100> *base = &arg0->m_list1;
    int count = base->m_used.m_num;
    if (count == 0)
        return 0;
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;
    it = GamList<GamTrgElem>::iterator(base->m_used.m_head.m_next);
    last = base->end();
    do {
        if ((*it).m_id == arg2 || arg2 == 0) {
            switch (arg1) {
            case 1:
                (*it).m_flg = arg3;
                break;
            case 2:
                (*it).m_flg |= arg3;
                break;
            case 3:
                (*it).m_flg &= ~arg3;
                break;
            case 4:
                return ((*it).m_flg & arg3) != 0;
            case 5:
                if ((*it).m_flg & 0x20000000) {
                    func_001C6A40(&D_007812C0, 0x8000);
                    (*it).m_flg &= ~0x20000000;
                    return 1;
                }
                return 0;
            }
            if (arg2 != 0)
                return 1;
        }
        ++it;
    } while (--count != 0);
    return arg2 == 0;
}

extern "C" int func_001E0D70(GamList<GamTrgElem> *arg0, int arg1)
{
    GamList<GamTrgElem>::iterator it;
    GamList<GamTrgElem>::iterator last;

    if (arg0->m_used.m_num == 0)
        return 0;
    it = GamList<GamTrgElem>::iterator(arg0->m_used.m_head.m_next);
    last = arg0->end();
    while (it != last) {
        if ((*it).m_id == arg1)
            return 1;
        ++it;
    }
    return 0;
}

extern "C" void func_001E0DF0(GamSndMan *arg0)
{
    GamSndChannels *r;

    arg0->m_vtable = &_vt$9GamSndMan;
    arg0->m_queue.initPool(arg0->m_queue.m_nodes, 0x20);
    r = &arg0->m_channels;
    r->m_end = arg0->m_channels.m_buf;
    r->m_max = 0x30;
    r->m_begin = arg0->m_channels.m_buf;
}

extern "C" void GamSndMan__vfunc_01(GamSndMan *arg0, int arg1)
{
    GamSndChannels *r;
    GamSndChannel *p;
    GamSndChannel *e;

    arg0->m_vtable = &_vt$9GamSndMan;
    r = &arg0->m_channels;
    e = (GamSndChannel *)r->m_end;
    p = (GamSndChannel *)r->m_begin;
    while (p != e) {
        p->~GamSndChannel();
        p++;
    }
    if (arg1 & 1) {
        return operator delete(arg0);
    }
}

extern "C" void func_001E0F1C(GamSndMan *arg0)
{
    func_001E107C(arg0);
    func_001E1FA4(arg0);
    arg0->m_seTable = (SND_PARAM *)D_006E9800.alloc( 0xE000, D_002FD770, 0x51, 0, 1);
    arg0->m_streamTable = (SND_PARAM *)D_006E9800.alloc( 0xC4E0, D_002FD770, 0x52, 0, 1);
    arg0->m_default.m_unk26 = 0x80;
    arg0->m_default.m_unk28 = 0x80;
    arg0->m_default.m_unk2A = 0x6A4;
    arg0->m_default.m_unk2C = 0x64;
    arg0->m_default.m_unk2E = 0x80;
    arg0->m_default.m_unk30 = 0;
    arg0->m_unk15A0[4].m_unk0C = -1;
    arg0->m_unk170C = -1;
    arg0->m_unk1710 = -1;
    arg0->m_unk1718 = -1;
    arg0->m_currentBgm = -1;
    arg0->m_unk15A0[0].m_unk0C = -1;
    arg0->m_unk15A0[4].m_unk00 = 0;
    arg0->m_unk15A0[0].m_unk00 = 0;
    arg0->m_unk186C = 0.5F;
    memset(arg0->m_bankIds, -1, 0x104);
}

extern "C" void func_001E100C(GamSndMan *arg0, EffVec3 *v)
{
    EffVec3 tmp;
    DogEntityEx *src;

    if (arg0->m_queue.m_used.m_num != 0) {
        if (arg0->m_mode == 1) {
            src = soundCamera(&D_006FBD80);
            tmp.x = src->m_unk40.m_x;
            tmp.y = src->m_unk40.m_y;
            tmp.z = src->m_unk40.m_z;
            func_001E3C24(arg0, &tmp);
        } else {
            func_001E3C24(arg0, v);
        }
    }
}

extern "C" void func_001E107C(GamSndMan *arg0)
{
    arg0->m_unk171C = 4;
    arg0->m_unk1720 = 0x80;
    arg0->m_unk1724 = 0x80;
    arg0->m_mode = 0;
    func_001E6734(arg0, 0xD, 0x80, 0x80, 0, -1);
    arg0->m_unk1598 = 0x80;
    arg0->m_unk159C = 0x80;
    arg0->m_unk1590 = 0x80;
    arg0->m_unk1594 = 0x80;
    func_001E6734(arg0, 0xE, 0x80, 0x80, 0, -1);
    func_001E6734(arg0, 0xF, 0x80, 0x80, 0, -1);
}

// NON_MATCHING: 282/294 differ, 11 relocs differ (size 0x498, game 0x4B4), 57 edits
#ifdef NON_MATCHING
extern "C" int func_001F9658(TskSnd *, int *, int *);
extern "C" void func_001E111C(GamSndMan *self, int mode)
{
    SND_PARAM *param;
    if (self->m_currentBgm < 0) {
        self->m_unk1708 = 0;
        ++self->m_currentBgm;
        self->m_unk15A0[self->m_currentBgm].m_unk00 = 0;
        self->m_unk15A0[self->m_currentBgm].m_unk0C = -1;
        self->m_unk15A0[self->m_currentBgm].m_unk18 = -1;
        self->m_unk1654[self->m_currentBgm].m_unk00 = 0;
        int offset = 0;
        int remaining = 47;
        do {
            GamSndChannels *entries = &self->m_channels;
            GamSndChannel *channel = channelAt(entries, offset);
            unsigned int flags = channel->flags;
            if (!(flags & 0x80)) {
                if (flags & 1) {
                    if (mode != 1) {
                        unsigned int id = channel->m_unk14;
                        if (id != -1U && (flags & 0x100)) {
                            int status = func_001E5B60(self, id, channel->m_unk18);
                            if (status != 5 && status != -1) {
                                self->m_unk15A0[self->m_currentBgm].m_unk0C = channelAt(entries, offset)->m_unk14;
                                if (func_001E7D7C(&D_007A3D80, self->m_unk1718)) {
                                    TskSnd *task = (TskSnd *)func_001E79C0(&D_007A3D80, self->m_unk1718);
                                    func_001F9658(task, &self->m_unk15A0[self->m_currentBgm].m_unk10, &self->m_unk15A0[self->m_currentBgm].m_unk14);
                                } else {
                                    self->m_unk15A0[self->m_currentBgm].m_unk10 = channelAt(entries, offset)->m_unk04;
                                    self->m_unk15A0[self->m_currentBgm].m_unk14 = channelAt(entries, offset)->m_unk08;
                                }
                            }
                            int index = self->m_currentBgm;
                            if (self->m_unk15A0[index].m_unk10 == 0 && self->m_unk15A0[index].m_unk14 == 0 && index > 0) {
                                self->m_unk15A0[index].m_unk0C = self->m_unk15A0[index-1].m_unk0C;
                                self->m_unk15A0[self->m_currentBgm].m_unk10 = self->m_unk15A0[self->m_currentBgm-1].m_unk10;
                                self->m_unk15A0[self->m_currentBgm].m_unk14 = self->m_unk15A0[self->m_currentBgm-1].m_unk14;
                            }
                        }
                    }
                } else if (mode != 2) {
                    unsigned int id = channel->m_unk0C;
                    if (id != 0 && id != 0x0B030352 && func_001E6368(self, id, channel->m_unk18)) {
                        GamSndChannel *active = channelAt(entries, offset);
                        id = active->m_unk0C;
                        if ((id >> 24) == 0xB) {
                            int index = self->m_currentBgm;
                            GamSndBgm *bgm = &self->m_unk15A0[index];
                            if (bgm->m_unk00 == 0) {
                                bgm->m_unk00 = id;
                                if (func_001E7D7C(&D_007A3D80, self->m_unk1710)) {
                                    TskSnd *task = (TskSnd *)func_001E79C0(&D_007A3D80, self->m_unk1710);
                                    func_001F9658(task, &self->m_unk15A0[self->m_currentBgm].m_unk04, &self->m_unk15A0[self->m_currentBgm].m_unk08);
                                } else {
                                    self->m_unk15A0[self->m_currentBgm].m_unk04 = channelAt(entries, offset)->m_unk04;
                                    self->m_unk15A0[self->m_currentBgm].m_unk08 = channelAt(entries, offset)->m_unk08;
                                }
                            } else {
                                self->m_unk1654[index].m_unk00 = id;
                                self->m_unk1654[self->m_currentBgm].m_unk04 = channelAt(entries, offset)->m_unk04;
                                self->m_unk1654[self->m_currentBgm].m_unk08 = channelAt(entries, offset)->m_unk08;
                            }
                        } else {
                            param = 0;
                            func_001E4908(self, active->m_unk0C, &param, 1);
                            GamSndChannel *entry = channelAt(entries, offset);
                            if ((entry->flags & 0x10) || (param && param->m_unk36)) {
                                self->m_ambient[self->m_unk1708].m_unk00 = entry->m_unk0C;
                                self->m_ambient[self->m_unk1708].m_unk04 = channelAt(entries, offset)->m_unk04;
                                self->m_ambient[self->m_unk1708].m_unk08 = channelAt(entries, offset)->m_unk08;
                                ++self->m_unk1708;
                            }
                        }
                    }
                }
            }
            --remaining;
            offset += sizeof(GamSndChannel);
        } while (remaining >= 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E111C);
#endif

extern "C" void func_001E15D0(GamSndMan *arg0, const GamSndBgm *arg1)
{
    arg0->m_currentBgm = 0;
    arg0->m_unk15A0[0] = *arg1;
}

// Existing address-preparation debt: retain until the original inline is identified.
static inline int *relative1620(char *base, int offset) { return (int *)(base + offset); }
extern "C" void func_001E1620(GamSndMan *arg0, int arg1, int arg2, int arg3) {
    if (arg0->m_currentBgm < 0) {
        return;
    }
    arg0->m_currentBgm = 0;

    if (arg1 != 1) {
        int *p = &arg0->m_unk15A0[0].m_unk0C;
        if (arg3 != -1) {
            if (arg3 != *p) {
                goto after_if1;
            }
            *p = -1;
        } else {
            *p = arg3;
        }
        arg0->m_unk15A0[arg0->m_currentBgm].m_unk10 = 0;
        arg0->m_unk15A0[arg0->m_currentBgm].m_unk14 = 0;
    }
after_if1:

    if (arg1 != 2) {
        char *base20 = (char *)arg0 + 0x20;
        register int index PS2_REG("$3") = arg0->m_currentBgm;
        char *base14 = (char *)arg0 + 0x14;
        if (arg2 != 0) {
            if (arg2 == *relative1620(base20, index * 0x24 + 0x1580)) {
                *relative1620(base20, arg0->m_currentBgm * 0x24 + 0x1580) = 0;
                arg0->m_unk15A0[arg0->m_currentBgm].m_unk04 = 0;
                arg0->m_unk15A0[arg0->m_currentBgm].m_unk08 = 0;
            }
            if (arg2 == *relative1620(base14, arg0->m_currentBgm * 0xC + 0x1640)) {
                *relative1620(base14, arg0->m_currentBgm * 0xC + 0x1640) = 0;
                goto clear_1658;
            }
        } else {
            *relative1620(base20, index * 0x24 + 0x1580) = 0;
            arg0->m_unk15A0[arg0->m_currentBgm].m_unk04 = 0;
            arg0->m_unk15A0[arg0->m_currentBgm].m_unk08 = 0;
            *relative1620(base14, arg0->m_currentBgm * 0xC + 0x1640) = 0;
        clear_1658:
            arg0->m_unk1654[arg0->m_currentBgm].m_unk04 = 0;
            arg0->m_unk1654[arg0->m_currentBgm].m_unk08 = 0;
        }
    }
}

extern "C" void func_001E17B4(GamSndMan *arg0, int arg1)
{
    GamSndMessage msg;

    func_001E111C(arg0, 0);
    int val = arg0->m_unk15A0[arg0->m_currentBgm].m_unk0C;
    if (val != -1 && arg1 != 1) {
        msg.m_unk14 = 0x1E;
        msg.m_unk04 = 0;
        msg.m_unk08 = 0;
        func_001E5660(arg0, val, 0x1B, &msg);
    }
    if (arg1 != 2) {
        int val2 = arg0->m_unk15A0[arg0->m_currentBgm].m_unk00;
        if (val2 != 0) {
            msg.m_unk14 = 0x1E;
            msg.m_unk04 = 0;
            msg.m_unk08 = 0;
            func_001E5E58(arg0, val2, 0x13, &msg);
        }
        int val3 = arg0->m_unk1654[arg0->m_currentBgm].m_unk00;
        if (val3 != 0) {
            msg.m_unk14 = 0x1E;
            msg.m_unk04 = 0;
            msg.m_unk08 = 0;
            func_001E5E58(arg0, val3, 0x14, &msg);
        }
    }
    for (int i = 0; i < arg0->m_unk1708; i++) {
        msg.m_unk14 = 0x1E;
        msg.m_unk04 = 0;
        msg.m_unk08 = 0;
        func_001E5E58(arg0, arg0->m_ambient[i].m_unk00, 0x15, &msg);
    }
    func_001E4120(arg0);
    arg0->m_unk1870 |= 1;
}

// NON_MATCHING: 214/412 differ, 12 relocs differ (size 0x670, game 0x684), 99 edits
#ifdef NON_MATCHING
extern const int D_002FD780[2];
extern "C" void func_001E1920(GamSndMan *self, int restart, int mode, int reset)
{
    GamSndMessage fade, volume, query;
    self->m_unk1870 &= ~1;
    if (self->m_currentBgm >= 0) {
        if (reset) self->m_currentBgm = 0;
        memcpy(&volume, D_002FD780, sizeof(D_002FD780));
        if (mode != 1) {
            int id = self->m_unk15A0[self->m_currentBgm].m_unk0C;
            if (id != -1) {
                if (restart || !func_001E5660(self, id, 0x16, 0)) {
                    func_001E5250(self, self->m_unk15A0[self->m_currentBgm].m_unk0C, 0, 0, 0, 0x100);
                    func_001E5660(self, self->m_unk15A0[self->m_currentBgm].m_unk0C, 4, (GamSndMessage *)1);
                } else func_001E5660(self, self->m_unk15A0[self->m_currentBgm].m_unk0C, 0x18, 0);
                func_001E5660(self, self->m_unk15A0[self->m_currentBgm].m_unk0C, 2, &volume);
                fade.m_unk04 = self->m_unk15A0[self->m_currentBgm].m_unk10;
                fade.m_unk08 = self->m_unk15A0[self->m_currentBgm].m_unk14;
                fade.m_unk14 = 30;
                func_001E5660(self, self->m_unk15A0[self->m_currentBgm].m_unk0C, 0x13, &fade);
                self->m_unk15A0[self->m_currentBgm].m_unk0C = -1;
            }
            id = self->m_unk15A0[self->m_currentBgm].m_unk18;
            if (id != -1) {
                func_001E5660(self, id, 0x18, 0);
                func_001E5660(self, self->m_unk15A0[self->m_currentBgm].m_unk18, 2, &volume);
                fade.m_unk04 = self->m_unk15A0[self->m_currentBgm].m_unk1C;
                fade.m_unk08 = self->m_unk15A0[self->m_currentBgm].m_unk20;
                fade.m_unk14 = 30;
                func_001E5660(self, self->m_unk15A0[self->m_currentBgm].m_unk18, 0x14, &fade);
                self->m_unk15A0[self->m_currentBgm].m_unk18 = -1;
            }
        }
        if (mode != 2) {
            int id = self->m_unk15A0[self->m_currentBgm].m_unk00;
            if (id) {
                if (!func_001E5E58(self, id, 0x16, 0)) func_001E4EBC(self, self->m_unk15A0[self->m_currentBgm].m_unk00, 0, 0, 0);
                if (self->m_unk15A0[self->m_currentBgm].m_unk00 == 0x0B030352) func_001E5E58(self, 0x0B030352, 4, 0);
                query.m_unk00 = self->m_unk15A0[self->m_currentBgm].m_unk04;
                query.m_unk04 = self->m_unk15A0[self->m_currentBgm].m_unk08;
                if (!func_001E5E58(self, self->m_unk15A0[self->m_currentBgm].m_unk00, 0x21, &query)) {
                    func_001E5E58(self, self->m_unk15A0[self->m_currentBgm].m_unk00, 2, &volume);
                    fade.m_unk04 = self->m_unk15A0[self->m_currentBgm].m_unk04;
                    fade.m_unk08 = self->m_unk15A0[self->m_currentBgm].m_unk08;
                    fade.m_unk14 = 30;
                    func_001E5E58(self, self->m_unk15A0[self->m_currentBgm].m_unk00, 0x13, &fade);
                }
                self->m_unk15A0[self->m_currentBgm].m_unk00 = 0;
            }
            id = self->m_unk1654[self->m_currentBgm].m_unk00;
            if (id) {
                if (!func_001E5E58(self, id, 0x16, 0)) func_001E4EBC(self, self->m_unk1654[self->m_currentBgm].m_unk00, 0, 0, 0);
                if (self->m_unk1654[self->m_currentBgm].m_unk00 == 0x0B030352) func_001E5E58(self, 0x0B030352, 4, 0);
                query.m_unk00 = self->m_unk1654[self->m_currentBgm].m_unk04;
                query.m_unk04 = self->m_unk1654[self->m_currentBgm].m_unk08;
                if (!func_001E5E58(self, self->m_unk1654[self->m_currentBgm].m_unk00, 0x21, &query)) {
                    func_001E5E58(self, self->m_unk1654[self->m_currentBgm].m_unk00, 2, &volume);
                    fade.m_unk04 = self->m_unk1654[self->m_currentBgm].m_unk04;
                    fade.m_unk08 = self->m_unk1654[self->m_currentBgm].m_unk08;
                    fade.m_unk14 = 30;
                    func_001E5E58(self, self->m_unk1654[self->m_currentBgm].m_unk00, 0x14, &fade);
                }
                self->m_unk1654[self->m_currentBgm].m_unk00 = 0;
            }
        }
        if (self->m_unk1708 > 0) {
            int i = 0;
            do {
                GamSndAmbient *ambient = &self->m_ambient[i];
                if (!func_001E5E58(self, ambient->m_unk00, 0x16, 0)) func_001E4EBC(self, self->m_ambient[self->m_currentBgm].m_unk00, 0, 0, 0);
                func_001E5E58(self, ambient->m_unk00, 4, (GamSndMessage *)1);
                ++i;
                func_001E5E58(self, ambient->m_unk00, 2, &volume);
                fade.m_unk04 = ambient->m_unk04;
                fade.m_unk08 = ambient->m_unk08;
                fade.m_unk14 = 30;
                func_001E5E58(self, ambient->m_unk00, 0x15, &fade);
            } while (i < self->m_unk1708);
            self->m_unk1708 = 0;
        }
        --self->m_currentBgm;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1920);
#endif

// NON_MATCHING: 37/118 differ (size 0x1D8, game 0x1D4), 27 edits
#ifdef NON_MATCHING
extern "C" void func_001E1FA4(GamSndMan *self)
{
    GamSndChannels *channels;
    int i;
    self->m_currentBgm = -1;
    self->m_unk1708 = 0;
    for (i = 0; i < 4; i++) {
        self->m_unk15A0[i].m_unk0C = -1;
        self->m_unk15A0[i].m_unk00 = 0;
    }
    channels = &self->m_channels;
    for (i = 0; i < 48; i++) {
        (channels->m_begin + i)->flags = 0;
        (channels->m_begin + i)->m_unk0C = 0;
        (channels->m_begin + i)->m_unk18 = -1;
        (channels->m_begin + i)->m_unk04 = 0;
        (channels->m_begin + i)->m_unk08 = 0;
    }
    if (func_001E7D7C(&D_007A3D80, self->m_unk170C)) func_001E7724(&D_007A3D80, self->m_unk170C);
    if (func_001E7D7C(&D_007A3D80, self->m_unk1710)) func_001E7724(&D_007A3D80, self->m_unk1710);
    if (func_001E7D7C(&D_007A3D80, self->m_unk1718)) func_001E7724(&D_007A3D80, self->m_unk1718);
    self->m_unk1718 = -1;
    self->m_unk170C = -1;
    self->m_unk1710 = -1;
    channels->clear();
    self->m_queue.clearUsed();
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E1FA4);
#endif

// NON_MATCHING: 74/110 differ, 1 reloc differs (size 0x1B8, game 0x1D8), 49 edits
#ifdef NON_MATCHING
extern "C" void func_001E2178(GamSndMan *self)
{
    GamList<GamSnd3D>::iterator it;
    GamList<GamSnd3D>::iterator end;
    it = self->m_queue.begin();
    end = self->m_queue.end();
    while (it != end) {
        if ((*it).flags & 2) {
            if ((*it).flags & 1) func_001E5660(self, (*it).id, 1, 0);
            it = self->m_queue.erase(it);
        } else if ((*it).flags & 4) {
            func_001E649C(self, (*it).id, (*it).handle);
            (*it).handle = -1;
            it = self->m_queue.erase(it);
        } else ++it;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E2178);
#endif

extern "C" void func_001E2350(GamSndMan *, GamSnd3D *item, const TskVec4 *point, const EffVec3 *origin, float distance)
{
    item->distance = distance;
    register const TskVec4 *source PS2_REG("$2") = point;
    if (origin != 0) {
        item->m_unk00.f[0] = source->f[0] - origin->x;
        item->m_unk00.f[1] = source->f[1] - origin->y;
        item->m_unk00.f[2] = source->f[2] - origin->z;
        return;
    }
    // Keep the full-vector copy in a2 while source remains in v0.
    register u_long128 copy PS2_REG("$6") = *(const u_long128 *)source;
    *(u_long128 *)&item->m_unk00 = copy;
}

// NON_MATCHING: 22/218 differ, 23 edits
#ifdef NON_MATCHING
extern "C" void func_001E239C(GamSndMan *self, unsigned int id, EffVec3 *position, int scene, int flags)
{
    if (scene == -1) scene = func_001C6C28(&D_007812C0);
    GamTrgMapInfo *entry = func_0017EA44(D_00298EE0, scene);
    if (entry) {
        GamSnd3D item;
        item.scene = scene;
        item.distance = 3000.0f;
        item.handle = -1;
        item.flags = flags;
        item.id = id;
        item.zero = 0;
        item.a = 0;
        item.b = 0;
        item.position.x = position->x + entry->m_unk20;
        item.position.y = position->y + entry->m_unk24;
        item.position.z = position->z + entry->m_unk28;
        float horizontal = sqrtf(item.position.x * item.position.x + item.position.z * item.position.z);
        float distance = sqrtf(item.position.y * item.position.y + horizontal * horizontal);
        func_001E4908(self, id, &item.data, 1);
        if (item.data) {
            if (flags & 0x20) {
                if (func_001E5E58(self, item.id, 0x16, 0) != 0) return;
                item.flags |= 0x200;
                item.handle = func_001E4EBC(self, item.id, 0, (EffVec4 *)position, 0x80);
            }
            register GamList<GamSnd3D> *queue PS2_REG("$4") = &self->m_queue;
            GamList<GamSnd3D>::iterator it;
            GamList<GamSnd3D>::iterator last;
            it = queue->begin();
            last = queue->end();
            while (it != last) {
                if (distance <= (*it).distance) {
                    queue->insert(it, item);
                    return;
                }
                ++it;
            }
            queue->push_back(item);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E239C);
#endif

extern "C" void func_001E2704(GamSndMan *self, unsigned int id, int key, int flags)
{
    GamSnd3D item;
    item.distance = 3000.0f;
    item.flags = flags | 4;
    item.id = id;
    item.zero = key;
    item.scene = func_001C6C28(&D_007812C0);
    item.handle = -1;
    func_001DBA3C((GamMapObj *)D_007812C0.m_mapObj, 2, &item.position.x, 0);
    func_001E4908(self, id, &item.data, 1);
    float horizontal = sqrtf(item.position.x * item.position.x + item.position.z * item.position.z);
    float distance = sqrtf(item.position.y * item.position.y + horizontal * horizontal);
    if (flags & 0x20) {
        if (func_001E5E58(self, item.id, 0x16, 0) != 0) return;
        item.flags |= 0x200;
        item.handle = func_001E50C8(self, item.id, 1, 1, 1.0f, 1, 0, 0x80);
    }
    GamList<GamSnd3D> *queue = &self->m_queue;
    GamList<GamSnd3D>::iterator it;
    GamList<GamSnd3D>::iterator last;
    it = queue->begin();
    last = queue->end();
    while (it != last) {
        if ((*it).zero == key && (*it).id == id) return;
        ++it;
    }
    {
    GamList<GamSnd3D> *queue = &self->m_queue;
    it = queue->begin();
    last = queue->end();
    while (it != last) {
        if (distance <= (*it).distance) {
            queue->insert(it, item);
            return;
        }
        ++it;
    }
    queue->push_back(item);
    }
}
extern "C" void func_001E2AA0(GamSndMan *arg0, unsigned int arg1, int arg2) {
    register GamList<GamSnd3D>::Chain *idle PS2_REG("$17") = &arg0->m_queue.m_free;
    GamList<GamSnd3D>::iterator it;
    GamList<GamSnd3D>::iterator last;
    it = ((GamList<GamSnd3D> *)idle)->begin();
    last = arg0->m_queue.end();
    while (it != last) {
        if ((*it).id == arg1 && (arg2 == -1 || (*it).scene == arg2)) {
            func_001E649C(arg0, (*it).id, (*it).handle);
            (*it).handle = -1;
            it = arg0->m_queue.erase(it);
        } else {
            ++it;
        }
    }
}
extern "C" void func_001E2C40(GamSndMan *arg0, int arg1) {
    register GamList<GamSnd3D>::Chain *idle PS2_REG("$17") = &arg0->m_queue.m_free;
    GamList<GamSnd3D>::Chain *used = &arg0->m_queue.m_used;
    GamList<GamSnd3D>::iterator it;
    GamList<GamSnd3D>::iterator last;
    it = ((GamList<GamSnd3D> *)idle)->begin();
    last = GamList<GamSnd3D>::iterator(&used->m_head);
    while (it != last) {
        if ((*it).zero == arg1) {
            func_001E649C(arg0, (*it).id, (*it).handle);
            (*it).handle = -1;
            it = arg0->m_queue.erase(it);
        } else {
            ++it;
        }
    }
}

extern "C" void func_001E2DB4(GamSndMan *self, unsigned int id, EffVec3 *position, int scene, int flags)
{
    if (scene == -1) scene = func_001C6C28(&D_007812C0);
    GamTrgMapInfo *entry = func_0017EA44(D_00298EE0, scene);
    if (entry) {
        GamSnd3D item;
        item.flags = flags | 1;
        item.distance = 3000.0f;
        item.scene = scene;
        item.handle = -1;
        item.id = id;
        item.zero = 0;
        item.position.x = position->x + entry->m_unk20;
        item.position.y = position->y + entry->m_unk24;
        item.position.z = position->z + entry->m_unk28;
        SND_PARAM *data;
        if (func_001E4C1C(self, id, &data)) item.data = data;
        else item.data = 0;
        float horizontal = sqrtf(item.position.x * item.position.x + item.position.z * item.position.z);
        float distance = sqrtf(item.position.y * item.position.y + horizontal * horizontal);
        GamList<GamSnd3D> *queue = &self->m_queue;
        GamList<GamSnd3D>::iterator it;
        GamList<GamSnd3D>::iterator last;
        it = queue->begin();
        last = queue->end();
        if (flags & 0x20) {
            if (func_001E5660(self, item.id, 0x16, 0) != 0) return;
            item.flags |= 0x200;
            item.handle = func_001E5250(self, item.id, 1, (EffVec4 *)position, 0, 0x80);
        }
            while (it != last) {
                if (distance <= (*it).distance) {
                    queue->insert(it, item);
                    return;
                }
                ++it;
            }
            queue->push_back(item);
    }
}

extern "C" void func_001E3138(GamSndMan *self, unsigned int id, unsigned int key, int flags)
{
    unsigned int kind = (key >> 30) ^ 2;
    GamSnd3D item;
    item.flags = flags | 5;
    item.distance = 3000.0f;
    item.id = id;
    item.zero = key;
    item.handle = -1;
    if (kind == 0) item.scene = func_001C6C28(&D_007812C0);
    else item.scene = -1;
    register GamMapObj *world PS2_REG("$4") = soundMap(&D_007812C0);
    func_001DBA3C(world, 2, &item.position.x, 0);
    item.data = 0;
    float horizontal = sqrtf(item.position.x * item.position.x + item.position.z * item.position.z);
    float distance = sqrtf(item.position.y * item.position.y + horizontal * horizontal);
    GamList<GamSnd3D> *queue = &self->m_queue;
    register GamList<GamSnd3D>::Node *sentinel PS2_REG("$21") = &queue->m_used.m_head;
    GamList<GamSnd3D>::iterator it;
    GamList<GamSnd3D>::iterator last;
    it = queue->begin();
    last = GamList<GamSnd3D>::iterator(sentinel);
    while (it != last) {
        if ((unsigned int)(*it).zero == key && (*it).id == id) return;
        ++it;
    }
    if (flags & 0x20) {
        if (func_001E5660(self, item.id, 0x16, 0) != 0) return;
        item.flags |= 0x200;
        item.handle = func_001E5428(self, item.id, 1, 1, 0, 1, 0, 1.0f);
    }
    it = queue->begin();
    last = GamList<GamSnd3D>::iterator(sentinel);
    while (it != last) {
        if (distance <= (*it).distance) {
            queue->insert(it, item);
            return;
        }
        ++it;
    }
    queue->push_back(item);
}
extern "C" void func_001E34EC(GamSndMan *arg0, int arg1, int arg2) {
    register GamList<GamSnd3D>::Chain *idle PS2_REG("$17") = &arg0->m_queue.m_free;
    GamList<GamSnd3D>::iterator it;
    GamList<GamSnd3D>::iterator last;
    it = ((GamList<GamSnd3D> *)idle)->begin();
    last = arg0->m_queue.end();
    while (it != last) {
        if ((*it).id == arg1 && (arg2 == -1 || (*it).scene == arg2)) {
            func_001E5660(arg0, arg1, 1, 0);
            it = arg0->m_queue.erase(it);
            func_001E4CBC(arg0, arg1);
        } else {
            ++it;
        }
    }
}

// NON_MATCHING: 22/91 differ, 25 edits
#ifdef NON_MATCHING
extern "C" void func_001E3698(GamSndMan *self, int key)
{
    GamList<GamSnd3D>::iterator it;
    GamList<GamSnd3D>::iterator end;
    it = self->m_queue.begin();
    end = self->m_queue.end();
    while (it != end) {
        if ((*it).zero == key) {
            func_001E5660(self, (*it).id, 1, 0);
            it = self->m_queue.erase(it);
        } else ++it;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3698);
#endif

extern "C" void func_001E3804(GamSndMan *arg0)
{
    arg0->m_queue.clearUsed();
}
extern "C" void func_001E386C(GamSndMan *self, GamSnd3D *item)
{
    int left, right;
    int oldLeft = 0;
    int oldRight = 0;
    int handle = item->handle;
    register int flags PS2_REG("$9") = item->flags;
    SND_PARAM *data = item->data;
    int mode = self->m_mode;
    float distance = item->distance;
    if (handle != -1) {
        GamSndChannel *entry = &self->m_channels.m_begin[handle];
        oldLeft = entry->m_unk04;
        oldRight = entry->m_unk08;
    }
    // Keep the flag test in v0; t1 holds the cached flags.
    register int is3D PS2_REG("$2") = item->flags & 1;
    if (is3D) {
        if (data) {
            func_001E6E00(mode, item, data, &left, &right, distance);
        } else {
            func_001E6E00(mode, item, &self->m_default, &left, &right, distance);
        }
        if (!left || abs(left - oldLeft) >= 33) left = (int)((left + oldLeft) * 0.75f);
        if (!right || abs(right - oldRight) >= 33) right = (int)((right + oldRight) * 0.75f);
        if (item->scene != func_001C6C28(&D_007812C0)) {
            float factor = self->m_unk186C;
            left = (int)((float)left * factor);
            right = (int)((float)right * factor);
        }
        item->a = left;
        item->b = right;
        if (!func_001E5B60(self, item->id, item->handle)) {
            if ((*(long long *)&item->flags & 0x60) == 0x60 || (item->flags & 0x200)) {
                func_001E34EC(self, item->id, -1);
            } else {
                item->handle = func_001E5428(self, item->id, left, right, 0, 1, 0x80, 1.0f);
                item->flags |= 0x40;
            }
        }
        func_001E5C40(self, item->id, item->handle, left, right);
        return;
    }
        if (data) {
            func_001E6E00(mode, item, data, &left, &right, distance);
        } else {
            func_001E6E00(mode, item, &self->m_default, &left, &right, distance);
        }
        if (!left || abs(left - oldLeft) >= 33) left = (int)((left + oldLeft) * 0.75f);
        if (!right || abs(right - oldRight) >= 33) right = (int)((right + oldRight) * 0.75f);
        if (item->scene != func_001C6C28(&D_007812C0)) {
            float factor = self->m_unk186C;
            left = (int)((float)left * factor);
            right = (int)((float)right * factor);
        }
        left = (unsigned int)left >= 256 ? 0 : left;
        right = (unsigned int)right >= 256 ? 0 : right;
        item->a = left;
        item->b = right;
        if (!func_001E6368(self, item->id, item->handle)) {
            if ((*(long long *)&item->flags & 0x60) == 0x60 || (item->flags & 0x200)) {
                func_001E2AA0(self, item->id, -1);
            } else {
                item->handle = func_001E50C8(self, item->id, left, right, 1.0f, 1, 0, 0x80);
                item->flags |= 0x40;
            }
        }
        func_001E63C0(self, item->id, item->handle, left, right);
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E3C24);

extern "C" void func_001E4120(GamSndMan *self)
{
    GamList<GamSnd3D>::iterator it, last;
    GamSndMessage msg;
    it = self->m_queue.begin();
    last = self->m_queue.end();
    while (it != last) {
        GamSnd3D *item = &*it;
        unsigned int id = item->id;
        int handle = item->handle;
        if (item->flags & 1) {
            if (func_001E5B60(self, id, handle)) {
                unsigned int id = (*it).id;
                int offset = handle * sizeof(GamSndChannel);
                GamSndChannels *channels = &self->m_channels;
                GamSndChannel *channel = channelAt(channels, offset);
                msg.m_u00 = id;
                msg.m_unk0C = channel->m_unk18;
                msg.m_unk20 = channel->m_unk04;
                msg.m_unk24 = channel->m_unk08;
                msg.m_unk14 = 30;
                msg.m_unk04 = 0;
                msg.m_unk08 = 0;
                self->m_unk15A0[self->m_currentBgm].m_unk18 = (*it).id;
                self->m_unk15A0[self->m_currentBgm].m_unk1C = channelAt(channels, offset)->m_unk04;
                self->m_unk15A0[self->m_currentBgm].m_unk20 = channelAt(channels, offset)->m_unk08;
                func_001E5660(self, id, 0x15, &msg);
            }
        } else if (func_001E6368(self, id, handle)) {
            GamSndChannel *channel = &self->m_channels.m_begin[handle];
            msg.m_u00 = (*it).id;
            msg.m_unk0C = channel->m_unk18;
            msg.m_unk20 = channel->m_unk04;
            msg.m_unk24 = channel->m_unk08;
            msg.m_unk14 = 60;
            msg.m_unk04 = 0;
            msg.m_unk08 = 0;
            msg.m_unk28 = 0;
            TskSnd *task = (TskSnd *)operator new(0xC0);
            func_001F8FC0(task, 0, &msg);
            func_001E71FC(&D_007A3D80, 1, -1, 1, 0, (CmnITask *)task, 0, 0, 1);
        }
        ++it;
    }
}

extern "C" void func_001E4354(void) {
}

extern "C" int func_001E435C(GamSndMan *arg0, int arg1)
{
    SND_PARAM *p;
    int r;

    r = func_001E4908(arg0, arg1, &p, 1);
    if (r != 0) {
        r = func_001E43A4(arg0, p->m_unk20,
                          p->m_unk32, 1);
    }
    return r;
}

extern "C" int func_001E43A4(GamSndMan *self, unsigned int bank, int, unsigned int check)
{
    // The result stays in a0 until the final boolean normalization.
    register int result PS2_REG("$4") = 1;
    if (bank >= 65U) result = 0;
    else if (check != 0) {
        register int value PS2_REG("$2") = self->m_bankIds[bank];
        value = ~value;
        result = value != 0;
    }
    return result != 0;
}

extern "C" void func_001E43E0(GamSndMan *arg0, char *arg1, int *arg2, int *arg3)
{
    char buf[4];

    buf[0] = arg1[2];
    buf[1] = arg1[3];
    buf[2] = 0;
    *arg3 = atoi(buf);
    buf[2] = 0;
    buf[0] = arg1[0];
    buf[1] = arg1[1];
    *arg2 = atoi(buf);
}

extern "C" void func_001E4458(GamSndMan *arg0, char *arg1, void *arg2, int arg3)
{
    int a;
    int b;

    func_001E43E0(arg0, arg1, &a, &b);
    func_001E44B4(arg0, a, b, arg2, arg3);
}

extern "C" void func_001E44B4(GamSndMan *arg0, int arg1, int arg2, void *arg3, int arg4)
{
    func_001E6734(arg0, 0x11, 0, 0, 0, -1);
    func_001809D8(&D_007B2580, arg1, arg3, arg4);
    arg0->m_bankIds[arg1] = arg2;
}

extern const char D_002FD770[] __attribute__((section(".rodata"), aligned(16))) = "game/gamsnd.cpp";

INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD780);

extern "C" void func_001E4540(GamSndMan *arg0, char *arg1, int arg2) {
    char path[0x40];
    int bank;
    int val;
    void *buf;
    char *name;

    func_001E6734(arg0, 0x11, 0, 0, 0, -1);
    FileReader reader;
    buf = D_006E9800.alloc( 0x80040, D_002FD770, 0x616, 0, 1);
    func_001E43E0(arg0, arg1, &bank, &val);
    name = arg0->m_filename;
    strcpy(name, arg1);
    arg0->m_filename[4] = '.';
    arg0->m_filename[5] = 's';
    arg0->m_filename[6] = 'e';
    arg0->m_filename[7] = '\0';
    snprintf(path, 0x40, "data/snd/xv/%s", name);
    FileReadReq req;
    req.m_unk08 = 1;
    req.m_name = path;
    req.m_unk14 = 0;
    req.m_offset = 0;
    req.m_buf = buf;
    req.m_size = 0x80000;
    req.m_unk20 = 1;
    reader.func_001BE524(&req, 0);
    func_001E44B4(arg0, bank, val, buf, arg2);
    arg0->m_bankIds[bank] = val;
    heapFree(buf);
}

#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))

extern "C" void func_001E46B8(GamSndMan *arg0, int arg1)
{
    func_00180B30(&D_007B2580, arg1);
    arg0->m_bankIds[arg1] = -1;
}

extern "C" void func_001E4700(GamSndMan *arg0)
{
    func_0017F5E8(&D_007B2580, 8);
    func_001E46B8(arg0, 0);
    func_001E46B8(arg0, 0xA);
    func_001E46B8(arg0, 0xB);
    func_001E46B8(arg0, 0xC);
    func_001E46B8(arg0, 0x1F);
    func_001E46B8(arg0, 0x20);
    func_001E46B8(arg0, 0x21);
    func_001E46B8(arg0, 0x40);
}

extern "C" void func_001E4790(GamSndMan *arg0, int arg1, const GamSndSETable *arg2)
{
    *(GamSndSETable *)arg0->m_seTable = *arg2;
}

extern "C" void func_001E484C(GamSndMan *arg0, int arg1, const GamSndStreamTable *arg2)
{
    *(GamSndStreamTable *)arg0->m_streamTable = *arg2;
}

extern "C" int func_001E4908(GamSndMan *arg0, int arg1, SND_PARAM **arg2, int arg3)
{
    SND_PARAM *e = arg0->m_seTable;
    if (e == 0) {
        return 0;
    }
    int i = 1;
    if (e->id != 0) {
        do {
            if (arg1 == e->id) {
                *(SND_PARAM **)arg2 = e;
                return 1;
            }
            e++;
            if (i++ >= 0x400) {
                break;
            }
        } while (e->id != 0);
    }
    *(SND_PARAM **)arg2 = 0;
    return 0;
}

extern "C" int func_001E4970(GamSndMan *arg0, const char *arg1, SND_PARAM **arg2)
{
    SND_PARAM *p = arg0->m_seTable;
    if (p == 0) {
        return 0;
    }
    int i = 0;
    while (i++ < 0x400 && p->id != 0) {
        if (strcmp(arg1, p->name) == 0) {
            *arg2 = p;
            return 1;
        }
        p++;
    }
    *arg2 = 0;
    return 0;
}

extern "C" int func_001E4A0C(GamSndMan *arg0, const char *arg1)
{
    SND_PARAM *p = arg0->m_seTable;
    if (*arg1 == '.' || *arg1 == '*') {
        arg1++;
    }
    if (p == 0) {
        return 0;
    }
    int i = 0;
    while (i++ < 0x400 && p->id != -1) {
        if (strcmp(arg1, p->name) == 0) {
            return p->id;
        }
        p++;
    }
    return 0;
}

extern "C" int func_001E4AB8(GamSndMan *arg0, const char *arg1)
{
    SND_PARAM *p = arg0->m_streamTable;
    if (p == 0) {
        return 0;
    }
    int i = 0;
    while (i++ < 0x384 && p->id != -1) {
        if (strcmp(arg1, p->name) == 0) {
            return p->id;
        }
        p++;
    }
    return 0;
}

extern "C" int func_001E4B48(GamSndMan *arg0, int arg1, SND_PARAM *arg2)
{
    int idx = (arg1 % 100000) / 2;
    for (int i = 0; i < 0x384; i++, idx++) {
        if (arg0->m_streamTable[idx].id == -1 || idx >= 0x385) {
            idx = 0;
        }
        if (arg0->m_streamTable[idx].id == arg1) {
            arg2->id = arg1;
            arg0->m_streamTable[idx] = *arg2;
            return 1;
        }
    }
    return 0;
}

extern "C" int func_001E4C1C(GamSndMan *arg0, int arg1, SND_PARAM **arg2)
{
    int idx = (arg1 % 100000) / 2;
    for (int i = 0; i < 0x384; i++, idx++) {
        if (arg0->m_streamTable[idx].id == -1 || idx >= 0x385) {
            idx = 0;
        }
        if (arg0->m_streamTable[idx].id == arg1) {
            *arg2 = &arg0->m_streamTable[idx];
            return 1;
        }
    }
    *arg2 = 0;
    return 0;
}

extern "C" int func_001E4CBC(GamSndMan *, int)
{
    return 0;
}

extern "C" void func_001E4CC4(GamSndMan *arg0, int arg1, int arg2, int arg3)
{
    arg0->m_unk1720 = arg2;
    arg0->m_unk1724 = arg3;
    arg0->m_unk171C = arg1;
    func_0023A080(arg1);
    rxSndReverbSetDepth(arg0->m_unk1720, arg0->m_unk1724);
}

extern "C" int func_001E4D04(GamSndMan *arg0, const char *name)
{
    return func_001E4A0C(arg0, name);
}

extern "C" void func_001E4D18(GamSndMan *arg0, int arg1)
{
    if (arg1 == 0) {
        return;
    }
    if (arg1 == 1) {
        for (int i = 0; i < 0x30; i++) {
            if (arg1 == 1) {
                GamSndChannel *e = &arg0->m_channels.m_begin[i];
                if ((e->m_unk0C >> 24) != 0xB) {
                    func_001E649C(arg0, e->m_unk0C, e->m_unk18);
                }
            }
        }
    }
}

extern "C" int func_001E4DB0(GamSndMan *arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    temp_v0 = func_001E4D04(arg0, (const char *)arg1);
    if (temp_v0 != 0) {
        return func_001E4EBC(arg0, temp_v0, arg2, (EffVec4 *)arg3, 0);
    }
    return -1;
}

extern "C" int func_001E4E20(GamSndMan *arg0, int arg1, int arg2, int arg3, int arg4, float fparg0)
{
    int temp_v0 = func_001E4D04(arg0, (const char *)arg1);
    if (temp_v0 != 0) {
        return func_001E50C8(arg0, temp_v0, arg2, arg3, fparg0, arg4, 0, 0);
    }
    return -1;
}

extern "C" int func_001E4EBC(GamSndMan *self, unsigned int id, int pan, EffVec4 *position, int flags)
{
    struct { int left, right; SND_PARAM *param; TskVec4 vec; } stack;
    int handle;
    if (soundDisabled(&D_007A320C, 1)) return -1;
    if (!func_001E4908(self, id, &stack.param, 1)) return -1;
    if (position) {
        stack.vec.f[0] = position->x; stack.vec.f[1] = position->y;
        stack.vec.f[2] = position->z; stack.vec.f[3] = position->w;
        func_001E6E00(self->m_mode, &stack.vec, stack.param, &stack.left, &stack.right, 100.0f);
        handle = func_0017F8FC(&D_007B2580, id);
        func_00180CE0(&D_007B2580, handle, stack.left, stack.right, -1024.0f, 0);
    } else {
        handle = func_0017F8FC(&D_007B2580, id);
        if (pan) {
            float factor = (float)stack.param->m_unk28 * 0.00390625f;
            stack.left = (int)((float)stack.param->m_unk26 * factor);
            stack.right = (int)((float)stack.param->m_unk26 * (1.0f - factor));
        } else { stack.left = 100; stack.right = 100; }
        func_00180CE0(&D_007B2580, handle, stack.left, stack.right, -1024.0f, 0);
    }
    GamSndChannels *channels = &self->m_channels;
    int offset = handle * sizeof(GamSndChannel);
    channelAt(channels, offset)->flags = flags;
    channelAt(channels, offset)->m_unk0C = id;
    channelAt(channels, offset)->m_unk18 = handle;
    channelAt(channels, offset)->m_unk04 = stack.left;
    channelAt(channels, offset)->m_unk08 = stack.right;
    return handle;
}

extern "C" int func_001E50C8(GamSndMan *arg0, int arg1, int arg2, int arg3, float fparg0, int arg4, int arg5, int arg6) {
    GamSndMessage msg;
    if (arg5 != 0) {
        msg.m_unk00 = arg1;
        msg.m_unk04 = arg2;
        msg.m_unk08 = arg3;
        msg.m_unk18 = fparg0;
        msg.m_unk10 = arg4;
        int prio = D_007A3D80.m_base.m_prio + arg5;
        TskSnd *node = (TskSnd *)operator new(0xC0);
        func_001F8FC0(node, 5, &msg);
        func_001E71FC(&D_007A3D80, 1, prio, 1, 0, (CmnITask *)node, 0, 0, 1);
        return -1;
    }
    if (soundDisabled(&D_007A320C, 1)) {
        return -1;
    }
    int idx = func_0017F8FC(&D_007B2580, arg1);
    func_00180CE0(&D_007B2580, idx, arg2, arg3, fparg0, arg4);
    GamSndChannels *r = &arg0->m_channels;
    int off = idx * sizeof(GamSndChannel);
    ((GamSndChannel *)((char *)r->m_begin + off))->flags = arg6;
    ((GamSndChannel *)((char *)r->m_begin + off))->m_unk0C = arg1;
    ((GamSndChannel *)((char *)r->m_begin + off))->m_unk18 = idx;
    ((GamSndChannel *)((char *)r->m_begin + off))->m_unk04 = arg2;
    ((GamSndChannel *)((char *)r->m_begin + off))->m_unk08 = arg3;
    return idx;
}

extern "C" int func_001E5250(GamSndMan *arg0, int arg1, int arg2, EffVec4 *arg3, int arg4, int arg5) {
    char buf[0x40];
    int sp40;
    int sp44;
    SND_PARAM *sp48;
    int s1;

    snprintf(buf, 0x40, "s%06d.str", arg1);
    if (arg3 != 0) {
        if (!func_001E4C1C(arg0, arg1, &sp48)) {
            return -1;
        }
        EffVec4 v;
        v.x = arg3->x;
        v.y = arg3->y;
        v.z = arg3->z;
        v.w = arg3->w;
        func_001E6E00(arg0->m_mode, &v, sp48, &sp40, &sp44, 100.0f);
        s1 = func_0017FD58(&D_007B2580, buf, arg1 > 0x1869F, arg2, (arg5 >> 8) & 1);
        func_00180078(&D_007B2580, s1, 0);
        func_0017FF58(&D_007B2580, -1024.0f, s1, sp40, sp44, 0);
    } else {
        s1 = func_0017FD58(&D_007B2580, buf, arg1 > 0x1869F, arg2, (arg5 >> 8) & 1);
        sp40 = 0x80;
        sp44 = 0x80;
    }
    GamSndChannels *sub = &arg0->m_channels;
    int off = s1 * sizeof(GamSndChannel);
    ((GamSndChannel *)((char *)sub->m_begin + off))->flags = (arg4 != 0) ? (arg5 | 9) : (arg5 | 1);
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk14 = arg1;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk18 = s1;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk04 = sp40;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk08 = sp44;
    return s1;
}

extern "C" int func_001E5428(GamSndMan *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, float fparg0)
{
    int idx = func_001E5250(arg0, arg1, arg5, 0, 0, arg6);
    func_0017FF58(&D_007B2580, fparg0, idx, arg2, arg3, 0);
    func_00180078(&D_007B2580, idx, arg4);
    GamSndChannels *sub = &arg0->m_channels;
    int off = idx * sizeof(GamSndChannel);
    ((GamSndChannel *)((char *)sub->m_begin + off))->flags = arg6 | 1;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk14 = arg1;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk18 = idx;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk04 = arg2;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk08 = arg3;
    return idx;
}

extern "C" void func_001E5540(GamSndMan *arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    SND_PARAM *p;
    SND_PARAM tmp;

    if (func_001E4C1C(arg0, arg1, &p) != 0) {
        p->m_unk2A = arg2;
        p->m_unk2C = arg3;
        p->m_unk2E = arg4;
        p->m_unk30 = arg5;
        return;
    }
    copySoundParam(&tmp, &arg0->m_default);
    tmp.m_unk2A = arg2;
    tmp.m_unk2C = arg3;
    tmp.m_unk2E = arg4;
    tmp.m_unk30 = arg5;
    func_001E4B48(arg0, arg1, &tmp);
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5660);

extern "C" int func_001E5B60(GamSndMan *arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        return 0;
    }
    if (func_001800D0(&D_007B2580, arg2) == -1) {
        return 0;
    }
    GamSndChannels *sub = &arg0->m_channels;
    int off = arg2 * sizeof(GamSndChannel);
    return ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk14 == arg1;
}

extern "C" int func_001E5BE0(GamSndMan *arg0, int arg1)
{
    if (arg1 < 0) {
        return -1;
    }
    if (func_001800D0(&D_007B2580, arg1) == -1) {
        return -1;
    }
    GamSndChannels *sub = &arg0->m_channels;
    int off = arg1 * sizeof(GamSndChannel);
    return ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk14;
}

extern "C" int func_001E5C40(GamSndMan *arg0, int arg1, int arg2, int arg3, int arg4)
{
    if (arg2 < 0) {
        return 0;
    }
    if (func_001800D0(&D_007B2580, arg2) == -1) {
        return 0;
    }
    GamSndChannels *sub = &arg0->m_channels;
    int off = arg2 * sizeof(GamSndChannel);
    if (((GamSndChannel *)((char *)sub->m_begin + off))->m_unk14 != arg1) {
        return 0;
    }
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk04 = arg3;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk08 = arg4;
    func_0017FF58(&D_007B2580, -1024.0f, arg2, arg3, arg4, 0);
    return 1;
}

extern "C" int func_001E5D1C(GamSndMan *arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        return 0;
    }
    if (func_001800D0(&D_007B2580, arg2) == -1) {
        return 0;
    }
    GamSndChannels *sub = &arg0->m_channels;
    int off = arg2 * sizeof(GamSndChannel);
    if (((GamSndChannel *)((char *)sub->m_begin + off))->m_unk14 != arg1) {
        return 0;
    }
    func_001801C8(&D_007B2580, arg2);
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk14 = -1;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk18 = -1;
    return 1;
}

extern "C" void func_001E5DE4(GamSndMan *arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    int p[4];

    if (func_001E4908(arg0, arg1, (SND_PARAM **)p, 1) != 0) {
        *(short *)(p[0] + 0x2A) = arg2;
        *(short *)(p[0] + 0x2C) = arg3;
        *(short *)(p[0] + 0x2E) = arg4;
        *(short *)(p[0] + 0x30) = arg5;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E5E58);

extern "C" int func_001E6368(GamSndMan *arg0, int arg1, int arg2)
{
    if (arg2 < 0) {
        return 0;
    }
    GamSndChannels *sub = &arg0->m_channels;
    int off = arg2 * sizeof(GamSndChannel);
    if (((GamSndChannel *)((char *)sub->m_begin + off))->m_unk0C != arg1) {
        return 0;
    }
    return func_00180CA8(&D_007B2580, arg2) != -1;
}

extern "C" int func_001E63C0(GamSndMan *arg0, int arg1, int arg2, int arg3, int arg4)
{
    if (arg2 < 0) {
        return 0;
    }
    GamSndChannels *sub = &arg0->m_channels;
    int off = arg2 * sizeof(GamSndChannel);
    if (((GamSndChannel *)((char *)sub->m_begin + off))->m_unk0C != arg1) {
        return 0;
    }
    if (func_00180CA8(&D_007B2580, arg2) == -1) {
        return 0;
    }
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk04 = arg3;
    ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk08 = arg4;
    func_00180CE0(&D_007B2580, arg2, arg3, arg4, -1024.0f, 0);
    return 1;
}

extern "C" int func_001E649C(GamSndMan *arg0, unsigned int arg1, int arg2)
{
    register int scaled PS2_REG("$2") = arg2 * 5;
    int off = scaled << 3;
    GamSndChannels *sub = &arg0->m_channels;
    if (arg2 < 0) {
        return 0;
    }
    if (((GamSndChannel *)((char *)sub->m_begin + off))->m_unk0C != arg1) {
        return 0;
    }
    if (func_00180CA8(&D_007B2580, arg2) == -1) {
        return 0;
    }
    func_00180EA8(&D_007B2580, arg2);
    register int result PS2_REG("$2") = 1;
    {
        ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk04 = 0;
        ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk08 = 0;
        ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk0C = 0;
        ((GamSndChannel *)((char *)sub->m_begin + off))->m_unk18 = -1;
    }
    return result;
}

extern "C" void func_001E6570(GamSndMan *arg0, int arg1) {
    GamSndChannel def;
    int i;
    switch (arg1) {
    case 0:
        for (i = 0; i < 0x30; i++) {
            GamSndChannel *p = arg0->m_channels.m_begin + i;
            *p = def;
        }
        break;
    case 1:
        for (i = 0; i < 0x30; i++) {
            GamSndChannel *p = arg0->m_channels.m_begin + i;
            if ((p->flags & 1) == 0) {
                *p = def;
            }
        }
        break;
    case 2:
        for (i = 0; i < 0x30; i++) {
            if (!arg0->m_channels.m_begin[i].isFree()) {
                arg0->m_channels.m_begin[i] = def;
            }
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6734);

extern "C" int func_001E6CAC(GamSndMan *arg0)
{
    for (int i = 0; i < 0x30; i++) {
        GamSndChannel *p = &arg0->m_channels.m_begin[i];
        if (!p->isFree() && (p->flags & 8)) {
            if (p->m_unk14 != -1 && func_001800D0(&D_007B2580, p->m_unk18) != -1) {
                return 1;
            }
        }
    }
    return 0;
}

extern "C" float func_001E6D54(GamSndPan *arg0)
{
    float mat[4][4];
    char vec[0x10];

    func_00237340(mat);
    func_00237830(mat, mat, arg0->m_angle);
    func_002378B0(mat, mat, arg0->m_direction);
    func_00237408(vec, arg0->m_source, arg0->m_position);
    func_002375D8(vec, vec);
    return ((func_00237580(mat[2], vec) + 1.0f) * 0.5f * 0.7f) + 0.3f;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E6E00);

GamTaskMan::GamTaskMan()
{
    head4 = 0;
    m_history[0] = -1;
    m_unk08 = 2;
    end = arr;
    head0 = 0;
}

GamTaskMan::~GamTaskMan()
{
    GamTaskNode *p = head4;
    while (p != 0) {
        GamTaskNode *cur = p;
        p = p->next;
        func_001E7C7C(this, cur);
    }
    p = head0;
    while (p != 0) {
        GamTaskNode *cur = p;
        p = p->next;
        func_001E7C7C(this, cur);
    }
}

extern "C" void func_001E7184(GamTaskMan *arg0, GamTaskNode *arg1)
{
    GamTaskNode *cur = arg0->head0;
    if (cur == 0) {
        arg1->next = 0;
        arg0->head0 = arg1;
        return;
    }
    if (cur->prio > arg1->prio) {
        arg1->next = cur;
        arg0->head0 = arg1;
        return;
    }
    GamTaskNode *p = cur;
    while (p != 0) {
        GamTaskNode *next = p->next;
        if (next == 0) {
            arg1->next = 0;
            p->next = arg1;
            return;
        }
        if (next->prio > arg1->prio) {
            arg1->next = next;
            p->next = arg1;
            break;
        }
        p = next;
    }
}

extern "C" void func_001E71F4(void) {
}

extern "C" int func_001E71FC(GamTaskMan *arg0, int arg1, int arg2, int arg3, int arg4, CmnITask *arg5, void *arg6, int *arg7, int arg8)
{
    if (arg2 == -1) {
        arg2 = arg0->m_base.m_prio;
    }
    GamTaskNode *node = (GamTaskNode *)operator new(sizeof(GamTaskNode));
    if (node == 0) {
        return 0;
    }
    node->obj = arg5;
    node->next = arg0->head4;
    node->state = 0;
    node->flags = arg8;
    node->id = arg0->m_unk08++;
    if (arg7 != 0) {
        node->m_unk10 = arg7;
        *arg7 = node->id;
    }
    func_001E7E50(arg0, node->id);
    node->m_unk18 = arg6;
    node->m_unk20 = arg5->get_task_type();
    node->m_unk28 = arg3;
    node->m_unk24 = arg2;
    if (arg4 == 0) {
        node->m_unk2C = 0;
    } else {
        node->m_unk2C = arg2 + arg4 - 1;
    }
    node->prio = arg2;
    arg5->init();
    func_001E7184(arg0, node);
    return 1;
}

extern "C" void func_001E7340(GamTaskMan *arg0, GamTaskNode *arg1, int arg2)
{
    int id = arg1->obj->get_task_type();
    if ((id == 0x10 || id == 5 || id == 0x13 || id == 0x14) && arg1->state != arg2) {
        if (arg2 == 1) {
            arg1->obj->pause(1);
        } else if (arg2 == 0) {
            arg1->obj->pause(0);
        }
    }
}

extern "C" void func_001E7414(GamTaskMan *arg0, int arg1, int arg2)
{
    if (arg1 != -1) {
        GamTaskNode *p = arg0->head0;
        while (p != 0) {
            if (p->id == arg1) {
                func_001E7340(arg0, p, arg2);
                p->state = arg2;
                break;
            }
            p = p->next;
        }
    }
}

extern "C" void func_001E747C(GamTaskMan *arg0, int *arg1, int arg2)
{
    for (GamTaskNode *node = arg0->head0; node != 0; node = node->next) {
        for (int *p = arg1; *p != -1; p++) {
            if (node->obj->get_task_type() == *p && node->state != 2) {
                func_001E7340(arg0, node, arg2);
                node->state = arg2;
            }
        }
    }
}

extern "C" void func_001E7544(GamTaskMan *arg0, int arg1)
{
    for (GamTaskNode *node = arg0->head0; node != 0; node = node->next) {
        int id = node->obj->get_task_type();
        if ((node->obj == 0 || (id != 1 && id != 0x12 && id != 2 && id != 7 && id != 0xF && id != 0x17 && id != 0x11 && id != 5)) && node->state != 2) {
            func_001E7340(arg0, node, arg1);
            node->state = arg1;
        }
    }
}

extern "C" void func_001E7618(GamTaskNode **arg0, int arg1)
{
    GamTaskNode *p = *arg0;
    if (p != 0) {
        do {
            int res = p->obj->get_task_type();
            arg1 = 2;
            if (p->obj == 0 || ((unsigned int)(res - 1) >= 3U && res != 0x11)) {
                p->state = 2;
            }
            p = p->next;
        } while (p != 0);
    }
}

extern "C" void func_001E7698(GamTaskMan *arg0, GamTaskNode *arg1)
{
    if (arg1 != 0) {
        func_001E7DE8(arg0, arg1->id);
    }
}

extern "C" int func_001E76B8(GamTaskMan *arg0, int arg1)
{
    GamTaskNode *p = arg0->head0;
    int ret = 0;
    while (p != 0) {
        if (p->id == arg1 && p->state != 2) {
            p->state = 2;
            func_001E7698(arg0, p);
            ret = 1;
            break;
        }
        p = p->next;
    }
    return ret;
}

extern "C" void func_001E7724(GamTaskMan *arg0, int arg1)
{
    if (arg1 != -1 && func_001E76B8(arg0, arg1) == 0) {
        for (int *p = arg0->arr; p != arg0->end; p++) {
            if (*p == arg1) {
                return;
            }
        }
        *arg0->end = arg1;
        arg0->end++;
    }
}

extern "C" void func_001E77B4(GamTaskMan *arg0, int arg1)
{
    GamTaskNode *p = arg0->head0;
    while (p != 0) {
        if (p->state != 2) {
            CmnITask *obj = p->obj;
            if (obj != 0 && arg1 == obj->get_task_type()) {
                func_001E7D08(arg0, p);
                p->state = 2;
                func_001E7698(arg0, p);
            }
        }
        p = p->next;
    }
}

extern "C" void func_001E785C(GamTaskMan *arg0)
{
    GamTaskNode *node = arg0->head0;
    while (node != 0 && arg0->end != arg0->arr) {
        int *p = arg0->arr;
        if (node->state != 2) {
            do {
                if (node->id == *p) {
                    func_001E7D08(arg0, node);
                    node->state = 2;
                    if (--arg0->end == arg0->arr) {
                        return;
                    }
                }
                p++;
            } while (p < arg0->end);
        }
        node = node->next;
    }
}

extern "C" void func_001E7908(void) {
}

extern "C" void func_001E7910(GamTaskMan *arg0, int *arg1)
{
    GamTaskNode *node = arg0->head0;
    while (node != 0) {
        GamTaskNode *next = node->next;
        for (int *p = arg1; *p != -1; p++) {
            if (node->obj->get_task_type() == *p) {
                func_001E7724(arg0, node->id);
            }
        }
        node = next;
    }
}

extern "C" CmnITask *func_001E79C0(GamTaskMan *arg0, int arg1)
{
    GamTaskNode *n = arg0->head4;

    while (n != 0) {
        if (n->id == arg1) {
            return n->obj;
        }
        n = n->next;
    }
    n = arg0->head0;
    while (n != 0) {
        if (n->id == arg1) {
            return n->obj;
        }
        n = n->next;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamsnd", func_001E7A20);

extern "C" void func_001E7C7C(GamTaskMan *arg0, GamTaskNode *arg1)
{
    func_001E7698(arg0, arg1);
    if (arg1->obj != 0) {
        arg1->obj->term();
        if (arg1->flags & 1) {
            operator delete(arg1->obj);
            arg1->flags &= ~1;
        }
        arg1->obj = 0;
    }
    memset(arg1, 0, 0x40);
    operator delete(arg1);
}

extern "C" void func_001E7D08(GamTaskMan *arg0, GamTaskNode *arg1)
{
    func_001E7698(arg0, arg1);
    if (arg1->obj != 0) {
        arg1->obj->term();
        if (arg1->flags & 1) {
            operator delete(arg1->obj);
            arg1->flags &= ~1;
        }
        arg1->obj = 0;
    }
}

extern "C" int func_001E7D7C(GamTaskMan *arg0, int arg1)
{
    if (arg1 == -1) {
        return 0;
    }
    for (int i = 0; i < 0x100 && arg0->m_history[i] != -1; i++) {
        if (arg0->m_history[i] == arg1) {
            return 1;
        }
    }
    return 0;
}

extern "C" void func_001E7DE8(GamTaskMan *arg0, int arg1)
{
    if (arg1 == -1) {
        return;
    }
    for (int i = 0; i < 0x100 && arg0->m_history[i] != -1; i++) {
        if (arg0->m_history[i] == arg1) {
            arg0->m_history[i] = -2;
        }
    }
}

extern "C" void func_001E7E50(GamTaskMan *arg0, int arg1)
{
    if (arg1 == -1) {
        return;
    }
    int i;
    for (i = 0; i < 0x100 && arg0->m_history[i] != -1; i++) {
        if (arg0->m_history[i] == arg1) {
            return;
        }
    }
    if (i < 0xFE) {
        arg0->m_history[i] = arg1;
        arg0->m_history[i + 1] = -1;
    }
}

int TskTest::exec(int, int, void *)
{
    return 0;
}

TskLogger::TskLogger(int arg1)
{
    m_unk04 = arg1;
    m_unk08 = func_001CBE38(&D_007812C0, (unsigned int)arg1);
}

int TskLogger::exec(int, int, void *)
{
    char debugBuffer[16];
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD900);
INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD910);
INCLUDE_RODATA("asm/nonmatchings/game/gamsnd", D_002FD920);
