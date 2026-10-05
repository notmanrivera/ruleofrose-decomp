#include "ror.h"
#include "dog/doglight.h"
#include "dog/dogentity.h"
#include "bed/bedmemory.h"
#include "sdk/string.h"

extern BedMemory D_006E9800;     // the global heap

// 0x00112B08: no lights, every type on.
void DogLight::init()
{
    func_0021AC80(&m_list);
    // In do { } while (0), maybe a macro in the original: its loop notes
    // keep the scheduler from moving the stores below ahead of these.
    do {
        m_data = 0;
        m_ambient = 0;
        m_direct = 0;
        m_point = 0;
        m_spot = 0;
        m_hemi = 0;
        m_dist = 0;
    } while (0);
    m_mask = 0xFFFFFFFF;
    m_dirty = 1;
}

// 0x00112B58
void DogLight::reset()
{
    release();
    init();
}

// 0x00112B84
void DogLight::release()
{
    if (m_data) {
        D_006E9800.free(m_data);
        m_data = 0;
    }
    init();
}













































// 0x00112BC8: the bytes theNum[type] lights of each type take.
int DogLight::getSize(const int *theNum)
{
    ASSERT(theNum);

    ASSERT(theNum[DOG_LIGHT_AMBIENT] >= 0 && theNum[DOG_LIGHT_AMBIENT] <= 1);
    ASSERT(theNum[DOG_LIGHT_DIRECT] >= 0 && theNum[DOG_LIGHT_DIRECT] <= 16);
    ASSERT(theNum[DOG_LIGHT_POINT] >= 0 && theNum[DOG_LIGHT_POINT] <= 16);
    ASSERT(theNum[DOG_LIGHT_SPOT] >= 0 && theNum[DOG_LIGHT_SPOT] <= 16);
    ASSERT(theNum[DOG_LIGHT_HEMI] >= 0 && theNum[DOG_LIGHT_HEMI] <= 16);
    ASSERT(theNum[DOG_LIGHT_DIST] >= 0 && theNum[DOG_LIGHT_DIST] <= 16);
    int sz = theNum[DOG_LIGHT_AMBIENT] * sizeof(DogLightAmbient)
        + theNum[DOG_LIGHT_DIRECT] * sizeof(DogLightDirect)
        + theNum[DOG_LIGHT_POINT] * sizeof(DogLightPoint)
        + theNum[DOG_LIGHT_SPOT] * sizeof(DogLightSpot)
        + theNum[DOG_LIGHT_HEMI] * sizeof(DogLightHemi)
        + theNum[DOG_LIGHT_DIST] * sizeof(DogLightDist);





    ASSERT(sz > 0);
    return sz;
}












// 0x00112D60: room for theNum[type] lights of each type, all zero.
void DogLight::create(const int *theNum)
{
    ASSERT(theNum);



    ASSERT(theNum[DOG_LIGHT_AMBIENT] >= 0 && theNum[DOG_LIGHT_AMBIENT] <= 1);
    ASSERT(theNum[DOG_LIGHT_DIRECT] >= 0 && theNum[DOG_LIGHT_DIRECT] <= 16);
    ASSERT(theNum[DOG_LIGHT_POINT] >= 0 && theNum[DOG_LIGHT_POINT] <= 16);
    ASSERT(theNum[DOG_LIGHT_SPOT] >= 0 && theNum[DOG_LIGHT_SPOT] <= 16);
    ASSERT(theNum[DOG_LIGHT_HEMI] >= 0 && theNum[DOG_LIGHT_HEMI] <= 16);
    ASSERT(theNum[DOG_LIGHT_DIST] >= 0 && theNum[DOG_LIGHT_DIST] <= 16);
    release();
    int sz = getSize(theNum);
    if (sz > 0) {
        m_data = D_006E9800.alloc(sz, -1);
        char *p = (char *)m_data;
        memset(p, 0, sz);
        m_num[DOG_LIGHT_AMBIENT] = theNum[DOG_LIGHT_AMBIENT];
        if (theNum[DOG_LIGHT_AMBIENT] > 0) {
            m_ambient = (DogLightAmbient *)p;
            p += theNum[DOG_LIGHT_AMBIENT] * sizeof(DogLightAmbient);
        }
        m_num[DOG_LIGHT_DIRECT] = theNum[DOG_LIGHT_DIRECT];
        if (theNum[DOG_LIGHT_DIRECT] > 0) {
            m_direct = (DogLightDirect *)p;
            p += theNum[DOG_LIGHT_DIRECT] * sizeof(DogLightDirect);
        }
        m_num[DOG_LIGHT_POINT] = theNum[DOG_LIGHT_POINT];
        if (theNum[DOG_LIGHT_POINT] > 0) {
            m_point = (DogLightPoint *)p;
            p += theNum[DOG_LIGHT_POINT] * sizeof(DogLightPoint);
        }
        m_num[DOG_LIGHT_SPOT] = theNum[DOG_LIGHT_SPOT];
        if (theNum[DOG_LIGHT_SPOT] > 0) {
            m_spot = (DogLightSpot *)p;
            p += theNum[DOG_LIGHT_SPOT] * sizeof(DogLightSpot);
        }
        m_num[DOG_LIGHT_HEMI] = theNum[DOG_LIGHT_HEMI];
        if (theNum[DOG_LIGHT_HEMI] > 0) {
            m_hemi = (DogLightHemi *)p;
            p += theNum[DOG_LIGHT_HEMI] * sizeof(DogLightHemi);
        }
        m_num[DOG_LIGHT_DIST] = theNum[DOG_LIGHT_DIST];
        if (theNum[DOG_LIGHT_DIST] > 0) {
            m_dist = (DogLightDist *)p;
        }
    }
    m_dirty = 1;
}






















































































// 0x00112FC8: like DogLightPool::setParam, for the lights that exist; a
// colour other than the ambient gets w = 0. DOG_LIGHT_PARAM_DIST checks
// m_hemi, not m_dist (as in the game).
void DogLight::setParam(int theType, int theNo, int theParam, const float *theValue)
{
    float *p = 0;
    int color = 0;
    if (theParam == DOG_LIGHT_PARAM_ANGLE) {
        if (theType == DOG_LIGHT_SPOT) {
            if (m_spot) {
                ASSERT(m_spot);
                ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_SPOT]);
                m_spot[theNo].m_angle[0] = theValue[0] * DOG_PI / 180.0f;
                m_spot[theNo].m_angle[1] = theValue[1] * DOG_PI / 180.0f;
            }
        } else {

            ASSERT(0);
        }
        return;
    }
    if (theParam == DOG_LIGHT_PARAM_POS) {
        if (theType == DOG_LIGHT_POINT) {
            if (!m_point) {
                return;
            }

            ASSERT(m_point);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_POINT]);
            p = m_point[theNo].m_pos;
        } else if (theType == DOG_LIGHT_SPOT) {
            if (!m_spot) {
                return;
            }

            ASSERT(m_spot);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_SPOT]);
            p = m_spot[theNo].m_pos;
        } else if (theType == DOG_LIGHT_DIST) {
            if (!m_dist) {
                return;
            }

            ASSERT(m_dist);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIST]);
            p = m_dist[theNo].m_pos;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_DIR) {
        if (theType == DOG_LIGHT_DIRECT) {
            if (!m_direct) {
                return;
            }


            ASSERT(m_direct);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIRECT]);
            p = m_direct[theNo].m_dir;
        } else if (theType == DOG_LIGHT_SPOT) {
            if (!m_spot) {
                return;
            }

            ASSERT(m_spot);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_SPOT]);
            p = m_spot[theNo].m_dir;
        } else if (theType == DOG_LIGHT_HEMI) {
            if (!m_hemi) {
                return;
            }

            ASSERT(m_hemi);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_HEMI]);
            p = m_hemi[theNo].m_dir;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_COLOR) {
        if (theType == DOG_LIGHT_AMBIENT) {
            if (!m_ambient) {
                return;
            }


            ASSERT(m_ambient);
            ASSERT(theNo == 0);
            p = m_ambient->m_color;
        } else if (theType == DOG_LIGHT_POINT) {
            if (!m_point) {
                return;
            }

            ASSERT(m_point);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_POINT]);
            p = m_point[theNo].m_color;
            color = 1;
        } else if (theType == DOG_LIGHT_DIRECT) {
            if (!m_direct) {
                return;
            }

            ASSERT(m_direct);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIRECT]);
            p = m_direct[theNo].m_color;
            color = 1;
        } else if (theType == DOG_LIGHT_SPOT) {
            if (!m_spot) {
                return;
            }

            ASSERT(m_spot);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_SPOT]);
            p = m_spot[theNo].m_color;
            color = 1;
        } else if (theType == DOG_LIGHT_HEMI) {
            if (!m_hemi) {
                return;
            }

            ASSERT(m_hemi);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_HEMI]);
            p = m_hemi[theNo].m_color;
            color = 1;
        } else if (theType == DOG_LIGHT_DIST) {
            if (!m_dist) {
                return;
            }

            ASSERT(m_dist);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIST]);
            p = m_dist[theNo].m_color;
            color = 1;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_COLOR2) {
        if (theType == DOG_LIGHT_HEMI) {
            if (!m_hemi) {
                return;
            }


            ASSERT(m_hemi);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_HEMI]);
            p = m_hemi[theNo].m_color2;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_DIST) {
        if (theType == DOG_LIGHT_DIST) {
            if (!m_hemi) {
                return;
            }


            ASSERT(m_hemi);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIST]);
            p = m_dist[theNo].m_unk20;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_ENABLE) {
        unsigned int bit = 1 << theType;
        if (theValue && theValue[0] != 0.0f) {
            m_mask |= bit;
        } else {
            m_mask &= ~bit;
        }
    } else {


















        ASSERT(0);
    }
    if (p) {
        for (int i = 0; i < 4; i++) {
            p[i] = theValue[i];
        }
        if (color) {
            p[3] = 0.0f;
        }
    }
    m_dirty = 1;
}











// 0x001136D0: the other way round.
void DogLight::getParam(int theType, int theNo, int theParam, float *theValue) const
{
    const float *p = 0;
    if (theParam == DOG_LIGHT_PARAM_ANGLE) {
        if (theType == DOG_LIGHT_SPOT) {
            ASSERT(m_spot);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_SPOT]);
            theValue[0] = m_spot[theNo].m_angle[0] * 180.0f / DOG_PI;
            theValue[1] = m_spot[theNo].m_angle[1] * 180.0f / DOG_PI;
        } else {


            ASSERT(0);
        }
        return;
    }
    if (theParam == DOG_LIGHT_PARAM_POS) {
        if (theType == DOG_LIGHT_POINT) {


            ASSERT(m_point);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_POINT]);
            p = m_point[theNo].m_pos;
        } else if (theType == DOG_LIGHT_SPOT) {


            ASSERT(m_spot);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_SPOT]);
            p = m_spot[theNo].m_pos;
        } else if (theType == DOG_LIGHT_DIST) {


            ASSERT(m_dist);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIST]);
            p = m_dist[theNo].m_pos;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_DIR) {
        if (theType == DOG_LIGHT_DIRECT) {



            ASSERT(m_direct);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIRECT]);
            p = m_direct[theNo].m_dir;
        } else if (theType == DOG_LIGHT_SPOT) {


            ASSERT(m_spot);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_SPOT]);
            p = m_spot[theNo].m_dir;
        } else if (theType == DOG_LIGHT_HEMI) {


            ASSERT(m_hemi);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_HEMI]);
            p = m_hemi[theNo].m_dir;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_COLOR) {
        if (theType == DOG_LIGHT_AMBIENT) {



            ASSERT(m_ambient);
            ASSERT(theNo == 0);
            p = m_ambient->m_color;
        } else if (theType == DOG_LIGHT_POINT) {


            ASSERT(m_point);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_POINT]);
            p = m_point[theNo].m_color;
        } else if (theType == DOG_LIGHT_DIRECT) {


            ASSERT(m_direct);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIRECT]);
            p = m_direct[theNo].m_color;
        } else if (theType == DOG_LIGHT_SPOT) {


            ASSERT(m_spot);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_SPOT]);
            p = m_spot[theNo].m_color;
        } else if (theType == DOG_LIGHT_HEMI) {


            ASSERT(m_hemi);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_HEMI]);
            p = m_hemi[theNo].m_color;
        } else if (theType == DOG_LIGHT_DIST) {


            ASSERT(m_dist);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIST]);
            p = m_dist[theNo].m_color;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_COLOR2) {
        if (theType == DOG_LIGHT_HEMI) {



            ASSERT(m_hemi);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_HEMI]);
            p = m_hemi[theNo].m_color2;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_DIST) {
        if (theType == DOG_LIGHT_DIST) {



            ASSERT(m_dist);
            ASSERT(theNo >= 0 && theNo < m_num[DOG_LIGHT_DIST]);
            p = m_dist[theNo].m_unk20;
        } else {


            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_ENABLE) {
        if (m_mask & (1 << theType)) {
            theValue[0] = 1.0f;
        } else {
            theValue[0] = 0.0f;
        }
    } else {











        ASSERT(0);
    }
    if (p) {
        for (int i = 0; i < 4; i++) {
            theValue[i] = p[i];
        }
    }
}

// 0x00113EA8: theDst gets this one's lights.
void DogLight::copyTo(DogLight *theDst)
{
    theDst->create(m_num);
    memcpy(theDst->m_data, m_data, getSize(m_num));
    theDst->m_dirty = 1;
}

// 0x00113F28: the light list of the types in use, rebuilt when out of
// date.
I3dLightList *DogLight::getList()
{
    static const DogLightAmbient sNoAmbient __attribute__((aligned(16))) = { { 0.0f, 0.0f, 0.0f, 1.0f } };
    if (m_dirty) {
        unsigned int mask = m_mask;
        if ((mask & (1 << DOG_LIGHT_AMBIENT)) && m_ambient) {
            m_list.m_ambient = *m_ambient;
        } else {
            m_list.m_ambient = sNoAmbient;
        }
        if (mask & (1 << DOG_LIGHT_DIRECT)) {
            m_list.m_num_direct = m_num[DOG_LIGHT_DIRECT];
            m_list.m_direct = m_direct;
        } else {
            m_list.m_num_direct = 0;
            m_list.m_direct = 0;
        }
        if (mask & (1 << DOG_LIGHT_POINT)) {
            m_list.m_num_point = m_num[DOG_LIGHT_POINT];
            m_list.m_point = m_point;
        } else {
            m_list.m_num_point = 0;
            m_list.m_point = 0;
        }
        if (mask & (1 << DOG_LIGHT_SPOT)) {
            m_list.m_num_spot = m_num[DOG_LIGHT_SPOT];
            m_list.m_spot = m_spot;
        } else {
            m_list.m_num_spot = 0;
            m_list.m_spot = 0;
        }
        if (mask & (1 << DOG_LIGHT_HEMI)) {
            m_list.m_num_hemi = m_num[DOG_LIGHT_HEMI];
            m_list.m_hemi = m_hemi;
        } else {
            m_list.m_num_hemi = 0;
            m_list.m_hemi = 0;
        }
        if (mask & (1 << DOG_LIGHT_DIST)) {
            m_list.m_num_dist = m_num[DOG_LIGHT_DIST];
            m_list.m_dist = m_dist;
        } else {
            m_list.m_num_dist = 0;
            m_list.m_dist = 0;
        }
        m_dirty = 0;
    }
    return &m_list;
}
