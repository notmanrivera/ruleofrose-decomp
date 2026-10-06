// dog/dogtexinfo.h (a guess, from dog/dogtexinfo.cpp): DogTexInfo, a
// model's textures. m_num_tex and m_tex_info come from the asserts; the
// class name follows the file (and DogModel::assignTex's mangled name).
#ifndef DOG_DOGTEXINFO_H
#define DOG_DOGTEXINFO_H

#include "ror.h"

struct tag_I3dTexInfo_s;
class BedPfh;
class DogModel;

class DogTexInfo {
public:
    int m_unk00;                    // +0x00
    int m_num_tex;                  // +0x04
    tag_I3dTexInfo_s *m_tex_info;   // +0x08

    void func_001167F4(DogModel *theModel);
    void func_001169D0(void *theData);
    void func_001170B8(BedPfh *thePfh, int theA, int theB, int theC);
    void func_0011764C();
};

#endif
