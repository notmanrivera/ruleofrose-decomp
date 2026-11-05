#include "ror.h"
#include "include_asm.h"
#include "mag/magscene.h"
#include "game/gamman.h"
struct MagMsgReq {
    int m_param[16];
    int m_id;
    char *m_buf;
    int m_size;
};
class MagMsgWork {
public:
    unsigned char m_unk[0x3BC];
    MagMsgWork() asm("func_0018330C");
    ~MagMsgWork() asm("func_00183B24");
    void func_00184128(MagMsgReq *theReq) asm("func_00184128");
};
struct MagGameState {
    unsigned char m_unk00[0x54];
    int m_unk54;
    unsigned char m_unk58[0x114];
    int m_unk16C;
    int m_unk170;
};
struct MagGameFlags {
    int m_unk00;
    int m_flags;
};
struct MagGameGlobals {
    unsigned char m_unk0000[0xDC1C];
    MagGameState *m_state;          // +0xDC1C
    MagGameFlags *m_flags;          // +0xDC20
};

extern MagGameGlobals D_007A4440;
extern MagGameState *D_007B205C;
extern MagGameFlags *D_007B2060;
extern "C" void func_001C5E1C(void *theGame);
extern "C" void func_001C5F70(void *theGame, int theA);
extern "C" int func_001C97C8(void *theGame);
extern "C" void func_001C97F0(void *theGame);
extern "C" int func_001832E8(int theType);
extern "C" int func_00134730(MagScene *theScene, int theW, int theH, int theA, int theB);
extern "C" void func_001348B0(MagScene *theScene, int theNo);
extern "C" void func_00134A00(MagScene *theScene, int theNo, int theX, int theY, int theZ);
extern "C" void func_00134AB8(MagScene *theScene, int theNo, int theW, int theH);
extern "C" void func_00134CD0(MagScene *theScene, int theNo, int theX, int theY, int theW, int theH);
extern "C" void func_00135494(MagScene *theScene, int theNo, int theOn);
extern "C" void func_00135594(MagScene *theScene, int theNo);

INCLUDE_ASM("asm/nonmatchings/unk/0013E2EC", func_0013E2EC);

INCLUDE_ASM("asm/nonmatchings/unk/0013E2EC", func_0013E4C0);

INCLUDE_ASM("asm/nonmatchings/unk/0013E2EC", func_0013E548);














INCLUDE_RODATA("asm/nonmatchings/unk/0013E2EC", D_002EE874);

INCLUDE_RODATA("asm/nonmatchings/unk/0013E2EC", jtbl_002EE880);

void MagScene::func_0013F07C(int theA)
{
    func_001C5E1C(&D_007812C0);
}
void MagScene::func_0013F09C()
{
    func_001C5F70(&D_007812C0, 0);
}
int MagScene::func_0013F0C0()
{
    int r = 0;
    int mode = *(int *)&m_pc;
    if (mode != 7 && mode != 0x13 && mode != 0xA) {
        r = func_001C97C8(&D_007812C0) != 0;
    }
    return r;
}
void MagScene::func_0013F114()
{
    return func_001C97F0(&D_007812C0);
}
void MagScene::func_0013F130()
{
    D_007B205C->m_unk54 = 0xA;
}
int MagScene::func_0013F144()
{
    int flags = D_007A4440.m_flags->m_flags;
    if (flags & 0x04000000) {
        return 0;
    }
    if (flags & 0x02000000) {
        return D_007A4440.m_state->m_unk170;
    }
    return 0xF;
}
int MagScene::func_0013F194()
{
    int flags = D_007A4440.m_flags->m_flags;
    if (flags & 0x04000000) {
        return 0;
    }
    if (flags & 0x02000000) {
        return D_007A4440.m_state->m_unk16C;
    }
    return 0xF;
}
void MagScene::func_0013F1E4()
{
    int *p = &D_007B2060->m_flags;
    *p &= 0xFDFFFFFF;
}
void MagScene::func_0013F208()
{
}
int MagScene::func_0013F210()
{
    BedSubMode *sub = &m_sub_mode;
    int mode = 5;
    sub->push();
    ((int *)sub)[1] = -1;
    ((int *)sub)[0] = mode;
    func_0013F07C(0x1000A);
    func_0013F09C();
    sub->pop();
    return 0;
}
int MagScene::func_0013F280(int theType, const int *theParam, int theA)
{
    char buf[0x400];
    MagMsgReq req;
    register int id asm("$17") = func_001832E8(theType);
    if (theParam) {
        for (int i = 0; i < 16; i++) {
            req.m_param[i] = theParam[i];
        }
    }
    req.m_size = 0x400;
    req.m_buf = buf;
    req.m_id = id;
    register char *msg asm("$17");
    {
        MagMsgWork work[2];
        work[0].func_00184128(&req);
        buf[0x3FF] = 0;
        msg = buf;
    }
    int no = func_00134730(this, 0x100, 0x100, 0, 100);
    if (no >= 0) {
        func_00135494(this, no, theA);
        func_00135594(this, no);
        func_00134AB8(this, no, 0x100, 0x60);
        func_00135234(no, 0, 0, (int)msg, 0);
        func_00134A00(this, no, 0x80, 0xE0, 30000);
        func_00134CD0(this, no, 0, 0, 0x100, 0x60);
    }
    BedSubMode *sub = &m_sub_mode;
    int mode = 5;
    sub->push();
    ((int *)sub)[1] = -1;
    ((int *)sub)[0] = mode;
    m_unk43718 = no;
    func_0013F07C(0x1000A);
    return no;
}
int MagScene::func_0013F444(int theNo)
{
    return m_window[theNo] != 0;
}
void MagScene::func_0013F458(int theNo)
{
    func_0013F09C();
    func_001348B0(this, theNo);
    m_sub_mode.pop();
}
