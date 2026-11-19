// unk/TskMsgMan.h: CmnITask and the 17 Tsk* task classes whose methods live in
// unk/TskMsgMan.cpp.
//
// Evidence:
// - Inheritance and vtable layout: notes/class_hierarchy.txt and
//   asm/data/vtbl/_vt_*Tsk*.data.s. CmnITask has 5 virtual slots (1..5):
//   get_task_type (get_task_type__8CmnITask), pause (pause__8CmnITaskb),
//   init, exec (exec__11PLScenePlayiiPv), term. CmnITask has no virtual
//   destructor (TskTest has only 6 vtable slots [0..5] and func_001E7C7C
//   calls __builtin_delete directly); each subclass here adds virtual ~Class()
//   at slot 6.
// - Inline methods: linkonce copies in asm/inline/ (0x0028A694,
//   0x00290198-0x002907D4).
// - Member offsets and types: accesses in asm/unk/TskMsgMan.s and
//   tools/layouts.py. Exact original member names: m_window_no (printf in
//   func_001F4A24), m_colScaleDist (set_col_scale_dist__11TskSeqEventf),
//   m_step (ret_step__8TskMovie). Other names are ours.
// - Object sizes: __builtin_new call sites across asm/ (all multiples of 0x40).
#ifndef UNK_TSKMSGMAN_H
#define UNK_TSKMSGMAN_H

#include "game/gamtrg.h"
#include "game/gamman.h"

struct TskVec4 {
    float f[4];
} __attribute__((aligned(16)));

class CmnITask {
public:
    virtual int get_task_type() { return 0; }
    virtual void pause(bool) {}
    virtual void init() = 0;
    virtual int exec(int, int, void *) = 0;
    virtual void term() = 0;
};

// sizeof 0xC0 (__builtin_new in unk/GrgMain, unk/MrtMain, unk/TskMsgMan)
class TskMoveTypeGen : public CmnITask {
public:
    ObjStat *m_obj;                     // +0x04
    unsigned int m_oid;                 // +0x08
    int m_chrID;                        // +0x0C
    unsigned int m_unk10;               // +0x10
    float m_unk14;                      // +0x14
    float m_unk18;                      // +0x18
    int m_type;                         // +0x1C
    TskVec4 m_targetPos;                // +0x20
    TskVec4 m_pos;                      // +0x30
    TskVec4 m_rot;                      // +0x40
    TskVec4 m_vel;                      // +0x50
    int m_cnt;                          // +0x60
    int m_halfCnt;                      // +0x64
    int m_unk68;                        // +0x68
    unsigned int m_unk6C;               // +0x6C
    int m_unk70;                        // +0x70
    float m_unk74;                      // +0x74
    float m_unk78;                      // +0x78
    void (TskMoveTypeGen::*m_func)();   // +0x7C
    int m_unk84;                        // +0x84
    unsigned char m_pad88[0x8];
    TskVec4 m_unk90;                    // +0x90
    float m_unkA0;                      // +0xA0
    int m_unkA4;                        // +0xA4
    unsigned int m_flg;                 // +0xA8
    int m_unkAC;                        // +0xAC
    int m_unkB0;                        // +0xB0
    float m_unkB4;                      // +0xB4
    unsigned char m_padB8[0x8];

    virtual int get_task_type() { return 8; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMoveTypeGen();
};

// sizeof 0x80 (__builtin_new)
class TskMoveTypeRound : public CmnITask {
public:
    ObjStat *m_obj;                     // +0x04
    unsigned int m_oid;                 // +0x08
    int m_chrID;                        // +0x0C
    unsigned int m_targetOid;           // +0x10
    int m_targetChrID;                  // +0x14
    int m_unk18;                        // +0x18
    float m_unk1C;                      // +0x1C
    int m_unk20;                        // +0x20
    float m_unk24;                      // +0x24
    float m_unk28;                      // +0x28
    int m_mode;                         // +0x2C
    TskVec4 m_targetPos;                // +0x30
    TskVec4 m_pos;                      // +0x40
    TskVec4 m_rot;                      // +0x50
    int (TskMoveTypeRound::*m_func)();  // +0x60
    int m_unk68;                        // +0x68
    unsigned char m_pad6C[0x4];
    TskVec4 m_prevPos;                  // +0x70

    virtual int get_task_type() { return 9; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMoveTypeRound();
};

// sizeof 0xC0 (__builtin_new)
class TskMovePointPath : public CmnITask {
public:
    ObjStat *m_obj;                     // +0x04
    unsigned int m_oid;                 // +0x08
    int m_chrID;                        // +0x0C
    float *m_points;                    // +0x10
    int m_unk14;                        // +0x14
    int m_unk18;                        // +0x18
    int m_unk1C;                        // +0x1C
    int m_unk20;                        // +0x20
    unsigned char m_pad24[0x8];
    float m_unk2C;                      // +0x2C
    int m_unk30;                        // +0x30
    unsigned char m_pad34[0xC];
    TskVec4 m_pos;                      // +0x40
    TskVec4 m_rot;                      // +0x50
    TskVec4 m_vel;                      // +0x60
    int (TskMovePointPath::*m_func)();  // +0x70
    int m_unk78;                        // +0x78
    int m_unk7C;                        // +0x7C
    float m_unk80;                      // +0x80
    unsigned char m_pad84[0x3C];

    virtual int get_task_type() { return 0xA; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMovePointPath();
};

// sizeof 0x2C0 (__builtin_new)
class TskMoveSectaFindPath : public CmnITask {
public:
    ObjStat *m_obj;                         // +0x004
    unsigned int m_oid;                     // +0x008
    int m_chrID;                            // +0x00C
    unsigned char m_pathBuf[0x1FC];         // +0x010
    int m_unk20C;                           // +0x20C
    unsigned char m_pad210[0x8];
    int m_unk218;                           // +0x218
    int m_cnt;                              // +0x21C
    int m_halfCnt;                          // +0x220
    int m_unk224;                           // +0x224
    int m_unk228;                           // +0x228
    unsigned char m_pad22C[0x4];
    TskVec4 m_unk230;                       // +0x230
    TskVec4 m_targetPos;                    // +0x240
    TskVec4 m_pos;                          // +0x250
    TskVec4 m_rot;                          // +0x260
    TskVec4 m_vel;                          // +0x270
    TskVec4 m_prevPos;                      // +0x280
    int *m_unk290;                          // +0x290
    int m_unk294;                           // +0x294
    int m_unk298;                           // +0x298
    int m_unk29C;                           // +0x29C
    float m_unk2A0;                         // +0x2A0
    float m_unk2A4;                         // +0x2A4
    int m_unk2A8;                           // +0x2A8
    int m_unk2AC;                           // +0x2AC
    int m_unk2B0;                           // +0x2B0
    float m_unk2B4;                         // +0x2B4
    int (TskMoveSectaFindPath::*m_func)();  // +0x2B8

    virtual int get_task_type() { return 0xB; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMoveSectaFindPath();
};

// sizeof 0x80 (__builtin_new)
class TskMoveSecta : public CmnITask {
public:
    ObjStat *m_obj;                     // +0x04
    unsigned int m_oid;                 // +0x08
    int m_unk0C;                        // +0x0C
    int m_unk10;                        // +0x10
    int m_unk14;                        // +0x14
    int m_unk18;                        // +0x18
    int m_unk1C;                        // +0x1C
    unsigned char m_pad20[0xC];
    float m_unk2C;                      // +0x2C
    int m_unk30;                        // +0x30
    unsigned char m_pad34[0x4];
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    float m_unk44;                      // +0x44
    unsigned char m_pad48[0x38];

    virtual int get_task_type() { return 0xC; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMoveSecta();
};

// sizeof 0x40
class TskMoveAdj : public CmnITask {
public:
    unsigned char m_pad04[0xC];
    TskVec4 m_pos;                      // +0x10
    int m_unk20;                        // +0x20
    float m_unk24;                      // +0x24
    float *m_unk28;                     // +0x28
    int m_unk2C;                        // +0x2C
    int m_unk30;                        // +0x30
    int m_unk34;                        // +0x34
    unsigned char m_pad38[0x8];

    virtual int get_task_type() { return 0xD; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMoveAdj();
};

// sizeof 0x40
class TskRotAdj : public CmnITask {
public:
    int m_chrID;                        // +0x04
    float m_unk08;                      // +0x08
    float m_unk0C;                      // +0x0C
    int m_unk10;                        // +0x10
    int m_unk14;                        // +0x14
    unsigned char m_pad18[0x8];
    TskVec4 m_rot;                      // +0x20
    unsigned char m_pad30[0x10];

    virtual int get_task_type() { return 0xE; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskRotAdj();
};

// sizeof 0x80 (__builtin_new)
class TskMovePhysic : public CmnITask {
public:
    unsigned char m_pad04[0x4];
    ObjStat *m_obj;                     // +0x08
    unsigned int m_oid;                 // +0x0C
    int m_chrID;                        // +0x10
    unsigned char m_pad14[0xC];
    TskVec4 m_pos;                      // +0x20
    TskVec4 m_vel;                      // +0x30
    TskVec4 m_acc;                      // +0x40
    unsigned char m_pad50[0x8];
    int m_unk58;                        // +0x58
    int m_unk5C;                        // +0x5C
    float m_unk60;                      // +0x60
    int m_unk64;                        // +0x64
    unsigned char m_pad68[0x8];
    int (TskMovePhysic::*m_func)();     // +0x70
    unsigned char m_pad78[0x8];

    virtual int get_task_type() { return 0; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMovePhysic();
};

// sizeof 0xC0 (__builtin_new)
class TskAvoidMove : public CmnITask {
public:
    ObjStat *m_obj;                     // +0x04
    unsigned char m_pad08[0x4];
    unsigned int m_oid;                 // +0x0C
    unsigned int m_unk10;               // +0x10
    int m_chrID;                        // +0x14
    unsigned char m_pad18[0x8];
    TskVec4 m_unk20;                    // +0x20
    TskVec4 m_unk30;                    // +0x30
    TskVec4 m_unk40;                    // +0x40
    int m_unk50;                        // +0x50
    unsigned char m_pad54[0x4];
    int m_unk58;                        // +0x58
    unsigned char m_pad5C[0x4];
    int m_unk60;                        // +0x60
    int m_unk64;                        // +0x64
    int m_unk68;                        // +0x68
    int m_unk6C;                        // +0x6C
    int m_unk70;                        // +0x70
    float m_unk74;                      // +0x74
    float m_unk78;                      // +0x78
    int (TskAvoidMove::*m_func)();      // +0x7C
    unsigned char m_pad84[0x3C];

    virtual int get_task_type() { return 0; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskAvoidMove();
};

// sizeof 0x80 (__builtin_new)
class TskChrRot : public CmnITask {
public:
    unsigned char m_pad04[0xC];
    TskVec4 m_rot;                      // +0x10
    unsigned int m_oid;                 // +0x20
    int m_chrID;                        // +0x24
    unsigned char m_pad28[0x8];
    float m_unk30;                      // +0x30
    float m_unk34;                      // +0x34
    int m_unk38;                        // +0x38
    int m_unk3C;                        // +0x3C
    int m_unk40;                        // +0x40
    int m_unk44;                        // +0x44
    float m_unk48;                      // +0x48
    int m_unk4C;                        // +0x4C
    int m_unk50;                        // +0x50
    int m_unk54;                        // +0x54
    int (TskChrRot::*m_func)();         // +0x58
    unsigned char m_pad60[0x20];

    virtual int get_task_type() { return 0xE; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskChrRot();
};

// sizeof 0x80 (__builtin_new)
class TskFrameFunc : public CmnITask {
public:
    int m_type;                         // +0x04
    int (TskFrameFunc::*m_func)();      // +0x08
    int m_step;                         // +0x10
    int m_cnt;                          // +0x14
    void *m_unk18;                      // +0x18
    unsigned char m_pad1C[0x4];
    union {
        int i[17];
        unsigned int u[17];
        unsigned short us[34];
        float f[17];
    } m_param;                          // +0x20..+0x63
    unsigned char m_pad64[0x1C];

    virtual int get_task_type() { return 7; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskFrameFunc();
};

// sizeof 0x40 (__builtin_new in unk/TskCamera)
class TskGenFrameFunc : public CmnITask {
public:
    unsigned char m_pad04[0x4];
    int (TskGenFrameFunc::*m_func)();   // +0x08
    int m_param;                        // +0x10
    unsigned char m_pad14[0x2C];

    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term() {}
    virtual ~TskGenFrameFunc();
};

// sizeof 0x80 (__builtin_new)
class TskSysFunc : public CmnITask {
public:
    int m_type;                         // +0x04
    int (TskSysFunc::*m_func)();        // +0x08
    int m_step;                         // +0x10
    int m_cnt;                          // +0x14
    int m_unk18;                        // +0x18
    int m_unk1C;                        // +0x1C
    int m_unk20;                        // +0x20
    int m_unk24;                        // +0x24
    unsigned char m_pad28[0x58];

    virtual int get_task_type() { return 0x17; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskSysFunc();
};

// sizeof 0x80 (__builtin_new in system/sysnowloading, unk/TskMsgMan)
class TskMovie : public CmnITask {
public:
    int m_unk04;                        // +0x04
    int m_step;                         // +0x08: ret_step
    int m_unk0C;                        // +0x0C
    char m_fileName[0x40];              // +0x10
    int m_unk50;                        // +0x50
    int m_unk54;                        // +0x54
    unsigned char m_pad58[0x28];

    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMovie();

    int ret_step() { return m_step; }
};

// sizeof 0x80 (__builtin_new)
class TskSeqEvent : public CmnITask {
public:
    int (TskSeqEvent::*m_func)();       // +0x04
    int m_type;                         // +0x0C
    unsigned char m_pad10[0xC];
    ObjStat *m_obj;                     // +0x1C
    int m_frameMax;                     // +0x20
    unsigned char m_pad24[0x18];
    int m_frameCnt;                     // +0x3C
    unsigned char m_pad40[0x8];
    float m_colScaleDist;               // +0x48: set_col_scale_dist
    float m_unk4C;                      // +0x4C
    unsigned char m_pad50[0x30];

    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskSeqEvent() {}

    void set_col_scale_dist(float theDist) { m_colScaleDist = theDist; }
};

// Embedded message-window sub-object in TskMsgMan (ctor func_0018330C,
// dtor func_00183B24 in msg/msgman).
struct TskMsgSub {
    unsigned char m_data[0x3BC];
};

// sizeof 0x9C0 (__builtin_new in game/gamman)
class TskMsgMan : public CmnITask {
public:
    char m_text[0x200];                 // +0x004
    int m_mode;                         // +0x204
    int m_unk208;                       // +0x208
    unsigned char m_pad20C[0x4];
    int m_time;                         // +0x210
    int m_window_no;                    // +0x214: original name (printf in ctor)
    unsigned char m_pad218[0x4];
    int m_cnt;                          // +0x21C
    const char *m_msgPtr;               // +0x220
    TskMsgSub m_sub[2];                 // +0x224..+0x99B
    GamMsgRect m_rect;                  // +0x99C..+0x9BB
    unsigned char m_pad9BC[0x4];

    virtual int get_task_type() { return 0x10; }
    virtual void pause(bool);
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskMsgMan();
};

// sizeof 0x40 (__builtin_new in system/sysnowloading)
class TskAttach : public CmnITask {
public:
    unsigned int m_oid;                 // +0x04
    int m_chrID;                        // +0x08
    const char *m_nodeName;             // +0x0C
    int m_attachID;                     // +0x10
    unsigned char m_pad14[0x2C];

    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term();
    virtual ~TskAttach();
};

#endif
