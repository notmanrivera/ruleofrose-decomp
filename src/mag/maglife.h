// mag/maglife.h: the base classes of every "life" object of a scene
// (MagLife0, MagLife) and MagLifeControlChara, the life that drives a
// DogActor, with MagLifeBillboard. The hierarchy is the game's RTTI
// (notes/class_hierarchy.txt):
//
//   MagLife0 -> MagLife -> MagLifeControlChara -> MagLifeBillboard
//                                              -> MagLifeBwn, MagLifePC,
//                                                 MagLifeTest
//                       -> MagLifeBwnCtrl, MagLifeFader, MagLifeNoise,
//                          MagLifeFadeKeyHole, MagLifeMenuBase (menus),
//                          MagLifePos -> MagLifeWindow, S2dBg, ...
//
// Every method of MagLife0 and MagLife, and all of MagLifeControlChara's
// but vfunc09, is inline: their out-of-line copies are linkonce
// (asm/inline/), and every file that emits a MagLife class's RTTI also
// emits "8MagLife0" (and "7MagLife" when it emits a direct child's). The
// bodies below are those copies. vfunc09 is MagLifeControlChara's key
// method and live is MagLifeBillboard's: mag/maglife.cpp defines both, so it
// emits both classes' vtables and RTTI names ("19MagLifeControlChara",
// "16MagLifeBillboard", "8MagLife0", "7MagLife" close its .rodata).
//
// Layout: g++ 2.96 puts the vptr after the first polymorphic class's data,
// so it sits at +0x14 for all of them. MagLife's fields are +0x18..+0x2F:
// every MagLife constructor zeroes +0x20 and +0x24 (setHide/getHide), and
// the classes derived from MagLife start their own fields at +0x30.
#ifndef MAG_MAGLIFE_H
#define MAG_MAGLIFE_H

#include "ror.h"
#include "dog/dogactor.h"

class MagLifeManager;
class MagScene;
struct tag_I3dRenderStage_s;

class MagLife0 {
public:
    int m_unk00;                    // +0x00: the mode (vfunc09)
    int m_unk04;                    // +0x04: frame counter (live)
    int m_unk08;                    // +0x08
    int m_unk0C;                    // +0x0C
    int m_unk10;                    // +0x10: live() mask
    // +0x14: vtable

    virtual ~MagLife0() {}
    virtual void live() { m_unk04++; }
    virtual void attached(MagLifeManager *theMan) {}
    virtual int getLevel() { return 0; }
    virtual const char *getName() = 0;
};

class MagLife : public MagLife0 {
public:
    int m_unk18;                    // +0x18
    int m_unk1C;                    // +0x1C
    // Named by MagLifeBillboard::live's assert; every MagLife constructor
    // zeroes it, but the menus keep their scene at +0x30 instead.
    MagScene *m_scene;              // +0x20
    int m_hide;                     // +0x24
    int m_unk28;                    // +0x28
    int m_unk2C;                    // +0x2C

    virtual void live() { m_unk04++; }
    virtual const char *getName() { return 0; }
    virtual void render(tag_I3dRenderStage_s *theStage) {}
    virtual void setHide(bool theHide) { m_hide = theHide; }
    virtual int getHide() { return m_hide; }
};

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

// Virtual slots 1 to 8 are MagLife0's and MagLife's; this class adds 9 to 15
// (_vt$19MagLifeControlChara). Slot 16 is not its: MagLifeBwn, MagLifePC and
// MagLifeTest each add their own, with different parameters.
class MagLifeControlChara : public MagLife {
public:
    int m_last0;                    // +0x30: the previous mode (vfunc09)
    int m_last1;                    // +0x34
    int m_last2;                    // +0x38
    int m_last3;                    // +0x3C
    int m_state;                    // +0x40
    int m_count;                    // +0x44
    int m_mode;                     // +0x48
    int m_unk4C;                    // +0x4C
    int m_unk50;                    // +0x50: setActor's second argument
    int m_unk54;                    // +0x54: setActor's third argument
    DogActor *m_actor;              // +0x58
    MagLifeMotionState *m_tbl_motion_state; // +0x5C
    int m_sctPos[4];                // +0x60
    int m_sctFlag;                  // +0x70
    int m_unk74;                    // +0x74
    int m_zeroLink;                 // +0x78
    int m_unk7C;                    // +0x7C

    virtual ~MagLifeControlChara() {}
    virtual void live() { m_unk04++; }
    virtual const char *getName() { return 0; }
    virtual void vfunc09(int theA, int theB) asm("MagLifeControlChara__vfunc_09");
    virtual void setActor(DogActor *theActor, int theA, int theB)
    {
        m_actor = theActor;
        m_unk50 = theA;
        m_unk54 = theB;
    }
    virtual DogActor *getActor() { return m_actor; }
    virtual void reset4MapJump()
    {
        *(u_long128 *)&m_last0 = 0;
        func_00119B34();
    }
    virtual void termWorld() {}
    virtual int message(int theMsg, int theArg, void *theData) { return 0; }
    virtual void renderPostProcess()
    {
        if (m_actor)
            func_0011A14C();
    }

    int getMotionStateCount() const { return m_count; }
    int getLastMode() const { return m_last0; }
    int getSctFlag() const { return m_sctFlag; }
    void clearZeroLink() { m_zeroLink = 0; }
    void setZeroLink() { m_zeroLink = 1; }
    int *getSctPos() { return m_sctPos; }

    void func_00119B34() asm("func_00119B34");
    int func_00119B60(DogVector *theOut, float theRot) asm("func_00119B60");
    int func_00119CEC(DogVector *theOut, float theRot) asm("func_00119CEC");
    float func_00119E1C() asm("func_00119E1C");
    void func_00119F88(DogVector *theOut) asm("func_00119F88");
    DogVector *func_00119FA4() asm("func_00119FA4");
    float func_00119FB0() asm("func_00119FB0");
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
    // The constructor (it stores this class's vtable); a plain method until
    // its body is written as a real constructor.
    void func_0011A888() asm("func_0011A888");
};

class MagLifeBillboard : public MagLifeControlChara {
public:
    float m_distance;               // +0x80

    virtual ~MagLifeBillboard() {}
    virtual void live();
    void setDistance(float theDistance) { m_distance = theDistance; }
    float getDistance() const { return m_distance; }
};

#endif
