// unk/TskEnemyMove.h: TskEnemyMove (enemy pathfinding/movement task, inherits CmnITask).
//
// Evidence:
// - Vtable _vt$12TskEnemyMove (0x002E5040): CmnITask slots 1..5 plus virtual dtor at slot 6.
// - Layout recovered from func_002006B0, func_00200700, TskEnemyMove__vfunc_02..06,
//   func_00200BC4..func_00202FE4, and tools/layouts.py.
#ifndef UNK_TSKENEMYMOVE_H
#define UNK_TSKENEMYMOVE_H

#include "task/cmnitask.h"

struct TskEnemyObj {
    unsigned char m_pad00[0x108];       // +0x000
    int m_chrID;                        // +0x108
};

struct TskEnemyActor {
    unsigned char m_pad00[0x40];        // +0x000
    float m_pos[4];                     // +0x040
    float m_rot[4];                     // +0x050
    unsigned char m_pad60[0x188];       // +0x060
    float m_mtnSpeed;                   // +0x1E8
    unsigned char m_pad1EC[0x4D0 - 0x1EC];
}; // size 0x4D0

struct TskEnemyMoveParam {
    unsigned int m_oid;                 // +0x00
    int *m_donePtr;                     // +0x04
    int m_unk08;                        // +0x08
    float m_speedScale;                 // +0x0C
    float m_walkSpeed;                  // +0x10
    float m_unk14;                      // +0x14
    float m_unk18;                      // +0x18
    float m_unk1C;                      // +0x1C
    int m_moveMode;                     // +0x20
    int m_unk24;                        // +0x24
    int m_targetOid;                    // +0x28
    float m_unk2C;                      // +0x2C
    float m_unk30;                      // +0x30
    float m_unk34;                      // +0x34
    float m_unk38;                      // +0x38
    float m_stopAngle;                  // +0x3C
    int m_unk40;                        // +0x40
    int m_unk44;                        // +0x44
    int m_unk48;                        // +0x48
    int m_unk4C;                        // +0x4C
    int m_unk50;                        // +0x50
    int m_sndType;                      // +0x54
    float m_unk58;                      // +0x58
    float m_stopMargin;                 // +0x5C
}; // size 0x60

class TskEnemyMove : public CmnITask {
public:
    int m_active;                       // +0x004
    unsigned int m_oid;                 // +0x008
    int m_chrID;                        // +0x00C
    int m_unk10;                        // +0x010
    int m_sectaId;                      // +0x014
    int m_hitTbl[4];                    // +0x018..+0x027
    TskEnemyActor *m_actor;             // +0x028
    int m_moveState;                    // +0x02C
    int *m_donePtr;                     // +0x030
    int m_unk34;                        // +0x034
    int m_targetOid;                    // +0x038
    float m_unk3C;                      // +0x03C
    float m_unk40;                      // +0x040
    float m_unk44;                      // +0x044
    float m_unk48;                      // +0x048
    float m_mtnSpeed;                   // +0x04C
    float m_walkSpeed;                  // +0x050
    float m_unk54;                      // +0x054
    float m_unk58;                      // +0x058
    int m_curMtn;                       // +0x05C
    int m_unk60;                        // +0x060
    int m_unk64;                        // +0x064
    int m_unk68;                        // +0x068
    int m_unk6C;                        // +0x06C
    int m_unk70;                        // +0x070
    int m_pathCount;                    // +0x074
    float m_targetPos[3];               // +0x078..+0x083
    unsigned char m_pad84[0x200];       // +0x084..+0x283
    int m_unk284;                       // +0x284
    float m_pathPts[127][4];            // +0x288..+0xA77
    int m_pathNum;                      // +0xA78
    int m_pathIdx;                      // +0xA7C
    int m_turnDir;                      // +0xA80
    float m_stopAngle;                  // +0xA84
    float m_selfRadius;                 // +0xA88
    float m_stopDist;                   // +0xA8C
    float m_unkA90;                     // +0xA90
    float m_unkA94;                     // +0xA94
    int m_unkA98;                       // +0xA98
    int m_unkA9C;                       // +0xA9C
    int m_unkAA0;                       // +0xAA0
    int m_unkAA4;                       // +0xAA4
    int m_unkAA8;                       // +0xAA8
    int m_unkAAC;                       // +0xAAC
    int m_unkAB0;                       // +0xAB0
    float m_unkAB4;                     // +0xAB4
    int m_sndHandle;                    // +0xAB8
    int m_sndTimer;                     // +0xABC
    int m_sndType;                      // +0xAC0
    int m_paused;                       // +0xAC4

    virtual int get_task_type() { return 0x14; }
    virtual void pause(bool);
    virtual void init();
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskEnemyMove();
}; // size 0xAC8

typedef char TskEnemyMove_size_check[sizeof(TskEnemyMove) == 0xAC8 ? 1 : -1];
typedef char TskEnemyActor_size_check[sizeof(TskEnemyActor) == 0x4D0 ? 1 : -1];

#endif
