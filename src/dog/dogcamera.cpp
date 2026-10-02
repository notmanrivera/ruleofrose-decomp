#include "ror.h"
#include "dog/dogcamera.h"
















// 0x0010F860: saves the position, rotation, scale and m_unk140.
void DogCamera::save()
{
    ASSERT(m_saved==0);
    m_saved_unk140 = m_unk140;
    m_saved_unk40 = m_unk40;
    m_saved_unk50 = m_unk50;
    m_saved_unk60 = m_unk60;
    m_saved++;
}




// 0x0010F8CC: back to the state save() kept.
void DogCamera::restore()
{
    ASSERT(m_saved != 0);
    m_unk140 = m_saved_unk140;
    m_unk40 = m_saved_unk40;
    m_unk50 = m_saved_unk50;
    m_unk60 = m_saved_unk60;
    m_unk90 = 1;
    m_saved--;
}
