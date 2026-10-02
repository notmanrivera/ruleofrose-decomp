// dog/dogcamera.h (a guess, from dog/dogcamera.cpp): DogCamera, a camera
// placed like any dog/ object. The class name and its virtual methods come
// from _vt$9DogCamera and the linkonce copy of its destructor; m_saved
// comes from the asserts, the other names are ours.
#ifndef DOG_DOGCAMERA_H
#define DOG_DOGCAMERA_H

#include "dog/dogentity.h"

class DogCamera : public DogEntityEx {
public:
    unsigned char m_unkF0[0x50];    // +0xF0
    float m_unk140;                 // +0x140
    float m_unk144;                 // +0x144
    float m_saved_unk140;           // +0x148
    DogVector m_saved_unk40;        // +0x150
    DogVector m_saved_unk50;        // +0x160
    DogVector m_saved_unk60;        // +0x170
    int m_saved;                    // +0x180: 1 while a state is saved

    void save();
    void restore();
    virtual ~DogCamera() {}
};

#endif
