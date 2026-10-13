// mag/magscenetenkyu.cpp: MagScene's "tenkyu" (sky dome) parts: its light
// set and its models. Names are ours.
//
// Matching decompilation. The ASSERT must stay on line 80 (0x50).

#include "mag/magscene.h"
#include "dog/doglightpool.h"
#include "dog/dogtexinfo.h"
#include "bed/bedmemory.h"
#include "mw/i3d.h"

extern BedMemory D_006E9800;        // the global heap

// A sky model slot (0x520 bytes each, from MagScene+0x29A44).
struct MagTenkyu {
    tag_I3rRoot_s *m_root;          // +0x00: the model, in the global heap
    void *m_unk04;                  // +0x04: a block of the global heap
    int m_unk08;                    // +0x08
    int m_unk0C;                    // +0x0C
    unsigned char m_unk10[0x510];
};

// 0x0013FE64: gives every light set in theMask the light theType (a new one
// from the pool at +0x2050); returns its id, or < 0.
int MagScene::func_0013FE64(int theType, int theMask)
{
    DogLightPool *pool = (DogLightPool *)((char *)this + 0x2050);
    int id = pool->allocID(theType);
    if (id >= 0) {
        int bit = 1;
        for (int set = 0; set < 9; set++) {
            if (theMask & bit) {
                pool->setID(set, theType, id);
            }
            bit <<= 1;
        }
    }
    return id;
}

// 0x0013FF00: frees slot theNo: its model and the textures it used.
void MagScene::func_0013FF00(int theNo)
{
    MagTenkyu *s = (MagTenkyu *)((char *)this + 0x29A44) + theNo;
    if (s->m_root) {
        int n = func_0022B428(s->m_root);
        for (int i = 0; i < n; i++) {
            const char *psz = func_0022B438(s->m_root, i);































            ASSERT(psz!=__null);
            DogTexInfo *tex = (DogTexInfo *)((char *)this + 0x29520);
            int no = tex->find(psz);
            if (no >= 0) {
                tex->releaseTex(no);
            }
        }
        D_006E9800.free(s->m_root);
        s->m_root = 0;
    }
    if (s->m_unk04) {
        D_006E9800.free(s->m_unk04);
        s->m_unk04 = 0;
        s->m_unk08 = 0;
    }
    s->m_unk0C = 0;
}
