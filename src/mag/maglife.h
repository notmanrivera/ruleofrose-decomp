// mag/maglife.h: MagLifeControlChara and MagLifeBillboard, the life objects
// that drive a DogActor and the floating billboards. The class names and the
// virtual order come from the vtables (_vt$19MagLifeControlChara,
// _vt$16MagLifeBillboard); the fields are reconstructed from mag/maglife.cpp.
//
// The out-of-line methods are free functions in mag/maglife.cpp with their
// original symbols: the game calls them directly, so keeping the symbols is
// what lets the rest of the asm link against this file.
#ifndef MAG_MAGLIFE_H
#define MAG_MAGLIFE_H

#include "ror.h"
#include "dog/dogactor.h"

class MagScene;

// One entry of a MagLifeControlChara's motion-state table. The table is a
// 0x18-byte stride; the assert strings name m_state_id, m_next_state and
// m_motion_state (the table itself).
struct MagLifeMotionState {
    int m_state_id;                 // +0x00
    const char *m_motion;           // +0x04
    short m_unk08;                  // +0x08
    short m_count;                  // +0x0A
    short m_speed;                  // +0x0C
    short m_unk0E;                  // +0x0E
    short m_flag;                   // +0x10
    short m_next_state;             // +0x12
    int m_sound;                    // +0x14
};

// The vptr is at +0x14 because this compiler puts it after the data (the
// same layout as MagLife0/MagLife in maglifeman.h).
struct MagLifeControlChara {
    int m_unk00[4];                 // +0x00
    int m_unk10;                    // +0x10
    void *m_vptr;                   // +0x14
    int m_unk18;                    // +0x18
    int m_unk1C;                    // +0x1C
    MagScene *m_scene;              // +0x20
    int m_unk24;                    // +0x24
    int m_unk28;                    // +0x28
    int m_unk2C;                    // +0x2C
    int m_last0;                    // +0x30
    int m_last1;                    // +0x34
    int m_last2;                    // +0x38
    int m_last3;                    // +0x3C
    int m_state;                    // +0x40
    int m_count;                    // +0x44
    int m_mode;                     // +0x48
    int m_unk4C;                    // +0x4C
    int m_unk50;                    // +0x50
    int m_unk54;                    // +0x54
    DogActor *m_actor;              // +0x58
    MagLifeMotionState *m_tbl_motion_state; // +0x5C
    int m_sctPos[4];                // +0x60
    int m_sctFlag;                  // +0x70
    int m_unk74;                    // +0x74
    int m_zeroLink;                 // +0x78
    int m_unk7C;                    // +0x7C

    void func_00119B34() asm("func_00119B34");
    int func_00119B60(DogVector *theOut, float theRot) asm("func_00119B60");
    int func_00119CEC(DogVector *theOut, float theRot) asm("func_00119CEC");
    float func_00119E1C() asm("func_00119E1C");
    void func_00119F88(DogVector *theOut) asm("func_00119F88");
    DogVector *func_00119FA4() asm("func_00119FA4");
    float func_00119FB0() asm("func_00119FB0");
    void vfunc09(int theA, int theB) asm("MagLifeControlChara__vfunc_09");
    void func_0011A010(int theState) asm("func_0011A010");
    int func_0011A028() asm("func_0011A028");
    void func_0011A030() asm("func_0011A030");
    void func_0011A03C() asm("func_0011A03C");
    int func_0011A048() asm("func_0011A048");
    int func_0011A054() asm("func_0011A054");
    int func_0011A064() asm("func_0011A064");
    void func_0011A130() asm("func_0011A130");
    void func_0011A144(MagLifeMotionState *theTable) asm("func_0011A144");
    void func_0011A14C() asm("func_0011A14C");
    void func_0011A27C(int theState, int theArg) asm("func_0011A27C");
    void func_0011A320(int theState, int theArg) asm("func_0011A320");
    int func_0011A4EC(const char *theMotion, int theFlag, float theSpeed,
                      int theInterp, int theNext) asm("func_0011A4EC");
    int *func_0011A64C() asm("func_0011A64C");
    void func_0011A6B0() asm("func_0011A6B0");
    void func_0011A704(int theSound) asm("func_0011A704");
    void func_0011A738(int *theSounds) asm("func_0011A738");
    void func_0011A888() asm("func_0011A888");
};

struct MagLifeBillboard : MagLifeControlChara {
    float m_distance;               // +0x80

    void live() asm("live__16MagLifeBillboard");
};

#endif
