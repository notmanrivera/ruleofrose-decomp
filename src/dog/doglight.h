// dog/doglight.h (a guess, from dog/doglight.cpp): DogLight, the lights one
// object is lit by, kept in one block and handed to i3d as a light list.
// The class name follows the file; m_num, m_ambient, m_direct, m_point,
// m_spot, m_hemi, m_dist and the parameter names come from the asserts.
#ifndef DOG_DOGLIGHT_H
#define DOG_DOGLIGHT_H

#include "dog/doglightpool.h"

class DogLight {
public:
    I3dLightList m_list;            // +0x00: built by getList
    void *m_data;                   // +0x40: the lights below
    DogLightAmbient *m_ambient;     // +0x44
    DogLightDirect *m_direct;       // +0x48
    DogLightPoint *m_point;         // +0x4C
    DogLightSpot *m_spot;           // +0x50
    DogLightHemi *m_hemi;           // +0x54
    DogLightDist *m_dist;           // +0x58
    int m_num[DOG_MAX_LIGHT_TYPE];  // +0x5C
    unsigned int m_mask;            // +0x74: types in use (bit per type)
    int m_dirty;                    // +0x78: m_list is out of date

    void init();
    void reset();
    void release();
    int getSize(const int *theNum);
    void create(const int *theNum);
    void setParam(int theType, int theNo, int theParam, const float *theValue);
    void getParam(int theType, int theNo, int theParam, float *theValue) const;
    void copyTo(DogLight *theDst);
    I3dLightList *getList();
};

#endif
