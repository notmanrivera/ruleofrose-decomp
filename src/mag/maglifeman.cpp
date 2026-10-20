// mag/maglifeman.cpp: MagLifeManager (see mag/maglifeman.h), the pool and
// sorted list of the scene's "life" objects. MagScene owns one at +0x2330
// and uses it to register the player, the dog and the billboards (add), to
// look them up (indexOf, remove, removeAt), to run their per-frame update
// (live, filtered by a mask) and to draw them (render, by 0x8000 kind).
//
// The pool is a fixed array of 64 pods, each with its list links:
//
//   m_life_buf[0] ... m_life_buf[63]      m_head -> the pod with the
//   +--------+--------+ ... +--------+             lowest flags (0 when
//   | pod    | pod    |     | pod    |             the list is empty)
//   +--------+--------+ ... +--------+
//
// init() zeroes the array and points m_head at m_life_buf[0]; the first
// add() takes that free slot, so the head is an occupied pod whenever the
// list is walked. add() links the new pod before the first pod whose flags
// are >= its own, so the list stays ascending and live() and render() walk
// it lowest-first. unlink() cuts a pod out, clearPod() forgets what it held.
//
// The 64 pods are 0x10 bytes each (MagLifePod), so m_head sits at +0x400.
// The functions are the game's, in address order, with its ASSERTs: a fired
// assert only prints and spins, so the walks rely on them holding.

#include "ror.h"
#include "mag/maglifeman.h"
#include "sdk/string.h"

// 0x001194B4: forgets what a pod held. The order of the stores is the
// game's (plife, prev, next, flags): this compiler emits the four only in
// this order, and the game's instructions prove the original had it.
void MagLifeManager::clearPod(MagLifePod *ppod)
{
    ppod->plife = 0;
    ppod->prev = 0;
    ppod->next = 0;
    ppod->flags = 0;
}

// 0x001194C8: cuts ppod out of the list (or moves the head past it) and
// clears it.
void MagLifeManager::unlink(MagLifePod *ppod)
{
    MagLifePod *prev = ppod->prev;
    MagLifePod *next = ppod->next;
    if (prev)
        prev->next = next;
    else
        m_head = next;
    if (next)
        next->prev = prev;
    clearPod(ppod);
}













































// 0x0011950C: links thePod2 just before thePod1 (both already in the list,
// or thePod2 a new pod). A pod cannot precede itself: that would be
// thePod1 already at the head, so only the head needs fixing.
void MagLifeManager::insertBefore(MagLifePod *thePod1, MagLifePod *thePod2)
{
    ASSERT(thePod1);
    ASSERT(thePod2);
    MagLifePod *prev = thePod1->prev;
    if (thePod1 == thePod2) {
        if (!prev)
            m_head = thePod1;
        return;
    }
    if (prev)
        prev->next = thePod2;
    else
        m_head = thePod2;
    thePod2->prev = prev;
    thePod2->next = thePod1;
    thePod1->prev = thePod2;
}














// 0x001195AC: links thePod2 just after thePod1, for a new pod that goes
// after every pod already in the list: add() passes the last pod before
// it (or 0 when the list is empty, which trips the assert).
void MagLifeManager::insertAfter(MagLifePod *thePod1, MagLifePod *thePod2)
{
    if (thePod1 == thePod2)
        return;
    ASSERT(thePod1);
    ASSERT(thePod2);
    MagLifePod *next = thePod1->next;
    thePod1->next = thePod2;
    thePod2->prev = thePod1;
    thePod2->next = next;
    if (next)
        next->prev = thePod2;
}

// 0x00119630: empties the pool and points m_head at m_life_buf[0]: the
// next add() takes that free slot, so the head is an occupied pod as soon
// as the list is walked again (see the note at the top of the file).
void MagLifeManager::init()
{
    memset(m_life_buf, 0, sizeof(m_life_buf));
    m_head = &m_life_buf[0];
}

// 0x00119660: deletes every life in the pool (not through the list: a
// destroyed life must not be able to unlink itself) and re-inits it.
void MagLifeManager::term()
{
    MagLifePod *ppod = &m_life_buf[0];
    for (int i = MAX_LIFE - 1; i >= 0; i--) {
        if (ppod->plife) {
            delete ppod->plife;
            ppod->plife = 0;
        }
        ppod++;
    }
    init();
}

















// 0x001196D4: takes the first free slot for theLife, then links it before
// the first pod whose flags are >= theFlags (the list stays ascending).
// Returns the slot number, or -1 if the pool is full. (With the list empty
// it would reach insertAfter below with a null pod and trip its assert.)
int MagLifeManager::add(MagLife *theLife, int theFlags)
{
    int no;
    for (no = 0; no < MAX_LIFE; no++) {
        if (!m_life_buf[no].plife)
            break;
    }
    if (no >= MAX_LIFE)
        return -1;
    m_life_buf[no].plife = theLife;
    m_life_buf[no].flags = theFlags;
    m_life_buf[no].prev = 0;
    m_life_buf[no].next = 0;
    MagLifePod *thePrev = 0;
    MagLifePod *ppod;
    for (ppod = m_head; ppod; ppod = ppod->next) {
        ASSERT(ppod >= &m_life_buf[0] && ppod < &m_life_buf[MAX_LIFE]);
        if (ppod->flags >= theFlags) {
            insertBefore(ppod, &m_life_buf[no]);
            return no;
        }
        thePrev = ppod;
    }
    insertAfter(thePrev, &m_life_buf[no]);
    return no;
}







// 0x00119810: cuts theLife out of the list (1) or reports it was not
// there (0).
int MagLifeManager::remove(MagLife *theLife)
{
    for (MagLifePod *ppod = m_head; ppod; ppod = ppod->next) {
        ASSERT(ppod >= &m_life_buf[0] && ppod < &m_life_buf[MAX_LIFE]);
        MagLife *plife = ppod->plife;

        ASSERT(plife);
        if (plife == theLife) {
            unlink(ppod);
            return 1;
        }
    }
    return 0;
}

// 0x001198D0: the slot theLife is in, or -1.
int MagLifeManager::indexOf(MagLife *theLife)
{
    for (int i = 0; i < MAX_LIFE; i++) {
        if (m_life_buf[i].plife == theLife)
            return i;
    }
    return -1;
}










// 0x00119908: cuts the life of slot theNo out of the list. A bad slot
// asserts; a negative one then does nothing (the >= 0 test is what the
// game's assert leaves in the code).
void MagLifeManager::removeAt(int theNo)
{
    ASSERT(theNo >= 0 && theNo < MAX_LIFE);
    if (theNo >= 0)
        unlink(&m_life_buf[theNo]);
}



















// 0x00119968: runs the per-frame update of every life with a bit of
// +0x10 set in theMask, in list order.
void MagLifeManager::live(int theMask)
{
    for (MagLifePod *ppod = m_head; ppod; ppod = ppod->next) {
        ASSERT(ppod >= &m_life_buf[0] && ppod < &m_life_buf[MAX_LIFE]);
        MagLife *plife = ppod->plife;

        ASSERT(plife);
        if (plife->m_unk10 & theMask)
            plife->live();
    }
}




// 0x00119A38: draws every visible life whose kind (the 0x8000 bits of
// flags) is theType, in list order. theStage is the i3d stage to draw
// into.
void MagLifeManager::render(tag_I3dRenderStage_s *theStage, int theType)
{
    for (MagLifePod *ppod = m_head; ppod; ppod = ppod->next) {
        ASSERT(ppod >= &m_life_buf[0] && ppod < &m_life_buf[MAX_LIFE]);
        if ((ppod->flags & 0xC000) == theType) {
            MagLife *plife = ppod->plife;


            ASSERT(plife);
            if (!plife->getHide())
                plife->render(theStage);
        }
    }
}
