#include "ror.h"
#include "dog/dogentity.h"
#include "mw/i3d.h"

// unk/00106658.
void vecDirToRot(float *theDir, float *theRot);
float vecYaw(const float *v);
float vecPitch(const float *v);

// 0x0010FC7C
void DogEntity::setRot(float x, float y, float z)
{
    m_unk50.m_x = x;
    m_unk50.m_y = y;
    m_unk50.m_z = z;
    normalizeRot();
    m_unk90 = 1;
}

// 0x0010FCB4: sets m_rot_offset's Y, kept in [-DOG_PI, DOG_PI).
void DogEntity::setRotOffsetY(float theRot)
{
    m_rot_offset.m_y = theRot;
    if (m_rot_offset.m_y < -DOG_PI) {
        m_rot_offset.m_y += DOG_PI2;
    }
    if (m_rot_offset.m_y >= DOG_PI) {
        m_rot_offset.m_y -= DOG_PI2;
    }
    m_unk90 = 1;
}

// 0x0010FD18: theMat from the scale, rotation (Z, X, then Y) and position,
// if they changed; 1 if it was recomputed.
int DogEntity::makeMatrix(float (*theMat)[4])
{
    if (m_unk90) {
        func_00237340(theMat);
        func_00237A78(theMat, theMat, &m_unk60.m_x);
        float r = m_unk50.m_z + m_rot_offset.m_z;
        while (r >= DOG_PI) {
            r -= DOG_PI2;
        }
        while (r < -DOG_PI) {
            r += DOG_PI2;
        }
        func_00237848(theMat, theMat, r);
        r = m_unk50.m_x + m_rot_offset.m_x;
        while (r >= DOG_PI) {
            r -= DOG_PI2;
        }
        while (r < -DOG_PI) {
            r += DOG_PI2;
        }
        func_00237818(theMat, theMat, r);
        r = m_unk50.m_y + m_rot_offset.m_y;
        while (r >= DOG_PI) {
            r -= DOG_PI2;
        }
        while (r < -DOG_PI) {
            r += DOG_PI2;
        }
        func_00237830(theMat, theMat, r);
        func_00237640(theMat, theMat, &m_unk40.m_x);
        func_00237640(theMat, theMat, &m_unk70.m_x);
        m_unk90 = 0;
        return 1;
    }
    return 0;
}

// 0x0010FF74: keeps the rotation's angles in [-DOG_PI, DOG_PI).
void DogEntity::normalizeRot()
{
    while (m_unk50.m_x >= DOG_PI) {
        m_unk50.m_x -= DOG_PI2;
    }
    while (m_unk50.m_x < -DOG_PI) {
        m_unk50.m_x += DOG_PI2;
    }
    while (m_unk50.m_y >= DOG_PI) {
        m_unk50.m_y -= DOG_PI2;
    }
    while (m_unk50.m_y < -DOG_PI) {
        m_unk50.m_y += DOG_PI2;
    }
    while (m_unk50.m_z >= DOG_PI) {
        m_unk50.m_z -= DOG_PI2;
    }
    while (m_unk50.m_z < -DOG_PI) {
        m_unk50.m_z += DOG_PI2;
    }
}

// 0x00110114
DogVector *DogEntity::getAxisZ(DogVector *theOut)
{
    *theOut = *(DogVector *)m_unk00[2];
    return theOut;
}

// 0x00110124
DogVector *DogEntity::getAxisX(DogVector *theOut)
{
    *theOut = *(DogVector *)m_unk00[0];
    return theOut;
}

// 0x00110134
DogVector *DogEntity::getAxisY(DogVector *theOut)
{
    *theOut = *(DogVector *)m_unk00[1];
    return theOut;
}

// 0x00110144: turns to look at thePos: fully (theMode 0), or only around
// Y (odd theMode) or X (even).
void DogEntity::lookAt(const DogVector &thePos, int theMode)
{
    DogVector d;
    d.m_x = thePos.m_x - m_unk40.m_x;
    d.m_y = thePos.m_y - m_unk40.m_y;
    d.m_z = thePos.m_z - m_unk40.m_z;
    if (theMode == 0) {
        vecDirToRot(&d.m_x, &m_unk50.m_x);
    } else if ((theMode & 1) == 0) {
        m_unk50.m_x = vecPitch(&d.m_x);
    } else {
        m_unk50.m_y = vecYaw(&d.m_x);
    }
    m_unk90 = 1;
}

// 0x001101F0
void DogEntity::getPos(DogVector *theOut)
{
    *theOut = *(DogVector *)m_unk00[3];
}

// 0x001101FC: the rotation that looks along the Z axis.
void DogEntity::getDirRot(DogVector *theRot)
{
    DogVector v;
    v = *(DogVector *)m_unk00[2];
    vecDirToRot(&v.m_x, &theRot->m_x);
}

// 0x0011023C
void DogEntityEx::reset()
{
    DogEntity::reset();
    func_00237340(m_local);
    m_parent = 0;
}












































































































































// 0x001102B4: theParent must not have this entity's parent among its own
// parents.
void DogEntityEx::setParent(DogEntityEx *theParent)
{
    m_parent = theParent;
    if (theParent) {
        for (DogEntityEx *p = theParent->m_parent; p; p = p->m_parent) {
            ASSERT(p != m_parent);
        }
    }
    m_unk70.set(0.0f, 0.0f, 0.0f, 1.0f);
    m_unk70.m_w = 1.0f;
    m_unk90 = 1;
}

// 0x0011034C
void DogEntityEx::transform()
{
    makeMatrix(m_local);
    DogEntityEx *p = m_parent;
    if (p) {
        p->transform();
        return func_002377D0(m_unk00, p->m_unk00, m_local);
    }
    func_002372F0(m_unk00, m_local);
}
