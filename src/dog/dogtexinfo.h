// dog/dogtexinfo.h (a guess, from dog/dogtexinfo.cpp): DogTexInfo, the
// textures of a model, loaded from TM2 images and shared by name. The
// class name follows the file (and DogModel::assignTex's mangled name);
// m_max_tex, m_num_tex, m_tex_info, m_tex_data and the parameter names
// come from the asserts, the rest is ours.
#ifndef DOG_DOGTEXINFO_H
#define DOG_DOGTEXINFO_H

#include "ror.h"

struct tag_I3dTexInfo_s;
struct tag_I3rRoot_s;
class BedPfh;
class DogModel;

// One texture's data (names ours).
struct DogTexData {                 // 0x198
    unsigned char m_picture[0x130]; // +0x000: i3d's picture
    unsigned char m_clut[0x38];     // +0x130: i3d's palette
    void *m_data;                   // +0x168: the TM2 image
    short m_own;                    // +0x16C: m_data is a copy to free
    short m_ref;                    // +0x16E: users of this texture
    char m_name[0x28];              // +0x170
};

class DogTexInfo {
public:
    int m_max_tex;                  // +0x00
    int m_num_tex;                  // +0x04: entries in use, empty ones too
    tag_I3dTexInfo_s *m_tex_info;   // +0x08: m_max_tex of them
    DogTexData *m_tex_data;         // +0x0C: m_max_tex of them
    int m_dirty;                    // +0x10: changed since func_0011756C
    int m_unk14;                    // +0x14: 255, 220, 152 by default;
    int m_unk18;                    // +0x18: passed to func_0010559C with
    int m_unk1C;                    // +0x1C: each TM2 (loadPack)

    tag_I3dTexInfo_s *getTexInfo(int theN);
    void func_0011626C(int theA, int theB, int theC);
    void clear();
    void create(int theMax);
    int find(const char *theName);
    int findFree();
    void release();
    void releaseTex(int theN);
    void releaseModel(DogModel *theModel);
    void releasePack(void *thePack);
    int func_00116B5C(void *theSrc, const char *theName);
    int loadTM2(const char *theTexName, void *theTM2, int theFlags, int theTcc);
    int loadPack(BedPfh *thePfh, tag_I3rRoot_s *theI3r, int theFlags, int theTint);
    void func_001173D4(const char *theTo, const char *theFrom);
    void func_001174BC();
    void setTcc(int theNo, int theTcc);
    void func_0011756C(void *p);
    void func_0011764C();
};

#endif
