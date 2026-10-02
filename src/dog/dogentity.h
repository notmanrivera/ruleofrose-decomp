// dog/dogentity.h (a guess, from dog/dogentity.cpp): DogEntity and
// DogEntityEx, the bases of every dog/ object. The class names, the virtual
// methods and their order come from the vtables (_vt$9DogEntity,
// _vt$11DogEntityEx) and the linkonce copies of the inline methods; fields
// are ours unless an assert names them.
#ifndef DOG_DOGENTITY_H
#define DOG_DOGENTITY_H

#include "ror.h"

// DOG_PI is original (assert strings); DOG_PI2 is ours.
#define DOG_PI 3.141593f
#define DOG_PI2 6.283186f

// A 4-float vector. m_x..m_w are original (assert strings); the class name
// is ours.
class DogVector {
public:
    float m_x;
    float m_y;
    float m_z;
    float m_w;

    DogVector()
    {
        m_x = m_y = m_z = 0.0f;
        m_w = 1.0f;
    }
    void set(float x, float y, float z, float w)
    {
        m_z = z;
        m_y = y;
        m_x = x;
        m_w = w;
    }
    DogVector(const DogVector &theV)
    {
        *(u_long128 *)this = *(const u_long128 *)&theV;
    }
    DogVector &operator=(const DogVector &theV)
    {
        *(u_long128 *)this = *(const u_long128 *)&theV;
        return *this;
    }
} __attribute__((aligned(16)));

class DogEntity {
public:
    float m_unk00[4][4];        // +0x00
    DogVector m_unk40;          // +0x40
    DogVector m_unk50;          // +0x50
    DogVector m_unk60;          // +0x60: (1, 1, 1, 1) after reset
    DogVector m_unk70;          // +0x70
    DogVector m_rot_offset;     // +0x80
    int m_unk90;                // +0x90
                                // +0x94: vtable

    DogEntity() { init(); }
    void init()
    {
        m_unk50 = m_unk40 = m_unk70 = m_rot_offset;
        m_unk60.set(1.0f, 1.0f, 1.0f, 1.0f);
        m_unk90 = 1;
    }
    virtual void reset()
    {
        m_rot_offset.m_x = m_rot_offset.m_z = m_rot_offset.m_y = 0.0f;
        m_rot_offset.m_w = 1.0f;
        init();
    }
    void setRotOffset(float x, float y, float z)
    {
        m_rot_offset.set(x, y, z, 1.0f);
        m_unk90 = 1;
    }
    // Turns by theRot around Y, keeping the angle in [-DOG_PI, DOG_PI).
    void addRotY(float theRot)
    {
        m_unk50.m_y += theRot;
        if (m_unk50.m_y < -DOG_PI) {
            m_unk50.m_y += DOG_PI2;
        } else if (m_unk50.m_y >= DOG_PI) {
            m_unk50.m_y -= DOG_PI2;
        }
        m_unk90 = 1;
    }
    void func_0010FCB4(float theRot);
    void func_0010FD18(DogEntity *theEntity);
    void func_0010FF74();
    virtual void transform() { func_0010FD18(this); }
    virtual ~DogEntity() {}
};

class DogEntityEx : public DogEntity {
public:
    unsigned char m_unkA0[0x40];    // +0xA0
    DogEntityEx *m_parent;          // +0xE0
    unsigned char m_unkE4[0xC];     // +0xE4

    DogEntityEx() { m_parent = 0; }
    virtual void reset();
    virtual void transform();
    virtual ~DogEntityEx() {}
    virtual DogEntityEx *getParent() { return m_parent; }
};

#endif
