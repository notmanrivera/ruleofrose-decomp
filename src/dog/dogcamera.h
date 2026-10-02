// dog/dogcamera.h (a guess, from dog/dogcamera.cpp): DogCamera, a camera
// placed like any dog/ object. The class name and its virtual methods come
// from _vt$9DogCamera and the linkonce copy of its destructor; m_saved
// comes from the asserts, the other names are ours.
#ifndef DOG_DOGCAMERA_H
#define DOG_DOGCAMERA_H

#include "dog/dogentity.h"

class DogCamera : public DogEntityEx {
public:
    float m_view[4][4];             // +0xF0: view matrix (getViewMatrix)
    DogSubMode m_submode;           // +0x130: m_step counts the move's frames
    float m_fov;                    // +0x140: field of view, radians
    float m_aspect;                 // +0x144
    float m_saved_fov;              // +0x148
    DogVector m_saved_unk40;        // +0x150
    DogVector m_saved_unk50;        // +0x160
    DogVector m_saved_unk60;        // +0x170
    int m_saved;                    // +0x180: 1 while a state is saved
    DogVector m_move_pos;           // +0x190: where a move ends
    DogVector m_move_rot;           // +0x1A0
    DogVector m_move_pos0;          // +0x1B0: where it started
    DogVector m_move_rot0;          // +0x1C0
    int m_move_frames;              // +0x1D0: its length; 0 when not moving

    DogSubMode *getSubMode() { return &m_submode; }
    void nextStep() { ++getSubMode()->m_step; }
    void save();
    void restore();
    void update();
    void moveTo(const DogVector &thePos, const DogVector &theRot, int theFrames);
    float (*getViewMatrix())[4];
    float func_0010FAC0();
    float func_0010FBD4();
    void func_0010FC08(float theValue);
    float getYaw();
    virtual ~DogCamera() {}
};

#endif
