// mag/maglifeman.h: MagLifeManager, the pool of the scene's "life" objects
// (the player, the dog, the billboards...), owned by MagScene (+0x2330).
// It is a fixed array of 64 slots (MAX_LIFE); each live slot links its
// MagLife into a list sorted by a priority word (0x8000 | the kind of life,
// see mag/magscene*.cpp), so live() and render() walk the lives in order.
//
// The class name is original (MagLife0::attached's mangled name takes a
// MagLifeManager); m_life_buf and MAX_LIFE are original too (assert
// strings). The layout comes from the code: the vptr of a MagLife is at
// +0x14 because this compiler puts it after the data, and the fields below
// are the ones the manager touches.
#ifndef MAG_MAGLIFEMAN_H
#define MAG_MAGLIFEMAN_H

#include "ror.h"

class MagLifeManager;
struct tag_I3dRenderStage_s;

// MagLife0 / MagLife: the base of every life object (mag/maglife.cpp, whose
// methods are still asm). Only what MagLifeManager needs is declared here:
// the vtable slots must keep the original order (the dtor first, then live,
// attached, getLevel, getName; MagLife adds getName, render, setHide,
// getHide), and the fields before the vptr must keep +0x10 a mask word.
class MagLife0 {
public:
    int m_unk00;                    // +0x00
    int m_unk04;                    // +0x04
    int m_unk08;                    // +0x08
    int m_unk0C;                    // +0x0C
    int m_unk10;                    // +0x10: live() mask
    // +0x14: vtable

    virtual ~MagLife0();
    virtual void live();
    virtual void attached(MagLifeManager *theMan);
    virtual int getLevel();
    virtual const char *getName() = 0;
};

class MagLife : public MagLife0 {
public:
    virtual const char *getName();
    virtual void render(tag_I3dRenderStage_s *theStage);
    virtual void setHide(bool theHide);
    virtual int getHide();
};

// One slot of the pool: one life and its list links (0x10 bytes).
struct MagLifePod {
    MagLife *plife;                 // +0x00: 0: the slot is free
    int flags;                      // +0x04: the list is sorted by this
                                    //        (ascending); 0x8000 | kind
    MagLifePod *prev;               // +0x08: 0 on the head, 0 on free slots
    MagLifePod *next;               // +0x0C
};

enum {
    MAX_LIFE = 64
};

class MagLifeManager {
public:
    MagLifePod m_life_buf[MAX_LIFE];    // +0x000
    MagLifePod *m_head;                 // +0x400: oldest first (see init)

    void clearPod(MagLifePod *ppod);
    void unlink(MagLifePod *ppod);
    void insertBefore(MagLifePod *thePod1, MagLifePod *thePod2);
    void insertAfter(MagLifePod *thePod1, MagLifePod *thePod2);
    void init();
    void term();
    int add(MagLife *theLife, int theFlags);
    int remove(MagLife *theLife);
    int indexOf(MagLife *theLife);
    void removeAt(int theNo);
    void live(int theMask);
    void render(tag_I3dRenderStage_s *theStage, int theType);
};

#endif
