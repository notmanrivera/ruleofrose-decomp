#include "ror.h"
#include "dog/dogcamera.h"
#include "mw/i3d.h"
#include "sdk/math.h"














// 0x0010F860: saves the position, rotation, scale and field of view.
void DogCamera::save()
{
    ASSERT(m_saved==0);
    m_saved_fov = m_fov;
    m_saved_unk40 = m_unk40;
    m_saved_unk50 = m_unk50;
    m_saved_unk60 = m_unk60;
    m_saved++;
}




// 0x0010F8CC: back to the state save() kept.
void DogCamera::restore()
{
    ASSERT(m_saved != 0);
    m_fov = m_saved_fov;
    m_unk40 = m_saved_unk40;
    m_unk50 = m_saved_unk50;
    m_unk60 = m_saved_unk60;
    m_unk90 = 1;
    m_saved--;
}

// unk/00106658.
void vecLerp(float *theOut, const float *a, const float *b, float t);
void vecNormalize(float *v);
float vecYaw(const float *v);

// 0x0010F944: one frame of the move moveTo started.
void DogCamera::update()
{
    if (m_move_frames > 0) {
        if (m_submode.m_step < m_move_frames) {
            float t = (float)m_submode.m_step / (float)m_move_frames;
            DogVector v;
            vecLerp(&v.m_x, &m_move_pos0.m_x, &m_move_pos.m_x, t);
            m_unk40 = v;
            m_unk90 = 1;
            vecLerp(&v.m_x, &m_move_rot0.m_x, &m_move_rot.m_x, t);
            m_unk50 = v;
            func_0010FF74();
            m_unk90 = 1;
            nextStep();
            if (m_submode.m_step < m_move_frames) {
                return;
            }
        }
        m_submode.m_step = 0;
        m_move_frames = 0;
    }
}

// 0x0010FA40: moves from the current position and rotation to thePos and
// theRot in theFrames frames (update).
void DogCamera::moveTo(const DogVector &thePos, const DogVector &theRot, int theFrames)
{
    m_move_frames = theFrames;
    m_move_pos0 = m_unk40;
    m_move_rot0 = m_unk50;
    m_submode.m_step = 0;
    m_move_pos = thePos;
    m_move_rot = theRot;
}

// 0x0010FA6C
float (*DogCamera::getViewMatrix())[4]
{
    transform();
    func_00237678(m_view, m_unk00);
    return m_view;
}

// 0x0010FAC0: m_fov through a table in 15-degree steps (0 to 180 degrees
// becomes 0 to 180, curved). r holds two values, as in the game: one
// variable for both changes the register allocation.
float DogCamera::func_0010FAC0()
{
    float tbl[13] = {
        0.0f, 28.0f, 57.0f, 82.0f, 99.5f, 114.5f, 128.0f,
        139.0f, 148.0f, 156.5f, 164.75f, 172.75f, 180.0f,
    };
    float n;
    float r = m_fov * 180.0f / DOG_PI;
    float f = modff(r / 15.0f, &n);
    int i = (int)n;
    r = tbl[i] + (tbl[i + 1] - tbl[i]) * f;
    return r * DOG_PI / 180.0f;
}

// 0x0010FBD4
float DogCamera::func_0010FBD4()
{
    return m_fov / m_aspect / 0.9015264f;
}

// 0x0010FC08: the inverse of func_0010FBD4.
void DogCamera::func_0010FC08(float theValue)
{
    m_fov = theValue * m_aspect * 0.9015264f;
}

// 0x0010FC28: the angle around Y the camera looks at.
float DogCamera::getYaw()
{
    transform();
    DogVector v(*(DogVector *)m_unk00[2]);
    v.m_y = 0.0f;
    vecNormalize(&v.m_x);
    return vecYaw(&v.m_x);
}
