#include "ror.h"
#include "dog/doglightpool.h"
#include "dog/dogentity.h"
#include "bed/bedmemory.h"
#include "sdk/string.h"

extern BedMemory D_006E9800;     // the global heap

// The size of one light of each type (8 entries in the game).
static const int sLightSize[8] = { 16, 32, 32, 64, 48, 48 };





























































// 0x001103DC: copies the lights of theType that theMask selects from the
// array theLight, as many as fit.
void DogLightSet::set(int theType, const void *theLight, unsigned int theMask)
{
    ASSERT(theType >= 0 && theType < DOG_MAX_LIGHT_TYPE);
    ASSERT(theLight);
    int n = 0;
    if (theMask) {
        char *dst = 0;
        switch (theType) {
        case DOG_LIGHT_AMBIENT:
            dst = (char *)m_ambient;
            break;
        case DOG_LIGHT_DIRECT:
            dst = (char *)m_direct;
            break;
        case DOG_LIGHT_POINT:
            dst = (char *)m_point;
            break;
        case DOG_LIGHT_SPOT:
            dst = (char *)m_spot;
            break;
        default:















            ASSERT(0);
            break;
        }
        static const int sMax[DOG_MAX_LIGHT_TYPE] = { 8, 8, 16, 8, 0, 0 };
        const char *src = (const char *)theLight;
        int max = sMax[theType];
        int size = sLightSize[theType];
        for (unsigned int bit = 1; bit; bit <<= 1, src += size) {
            if (theMask & bit) {
                memcpy(dst, src, size);
                dst += size;
                if (++n >= max) {
                    break;
                }
            }
        }
    }
    m_num[theType] = n;
}

// 0x00110578: the i3d light list from the copies. The game reads the
// direct, point and spot counts past the end of m_num.
void DogLightSet::setup()
{
    func_0021AC80(&m_list);
    if (m_num[DOG_LIGHT_AMBIENT] > 0) {
        func_002372E0(m_list.m_ambient, m_ambient[0].m_color);
    }
    if (m_num[8] > 0) {
        m_list.m_num_direct = m_num[8];
        m_list.m_direct = m_direct;
    }
    if (m_num[16] > 0) {
        m_list.m_num_point = m_num[16];
        m_list.m_point = m_point;
    }
    if (m_num[8] > 0) {
        m_list.m_num_spot = m_num[8];
        m_list.m_spot = m_spot;
    }
    m_list.m_unk28 = 0;
    m_list.m_unk2C = 0;
    m_list.m_unk30 = 0;
    m_list.m_unk34 = 0;
}

// 0x00110614
void DogLightSet::clear()
{
    func_0021AC80(&m_list);
    for (int i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        m_num[i] = 0;
    }
}






































































































// 0x00110660: the theNo-th ambient light of set theSetNo, or 0.
DogLightAmbient *DogLightPool::getSetAmbient(int theSetNo, int theNo)
{
    const int type = DOG_LIGHT_AMBIENT;
    ASSERT(m_light[type]);
    ASSERT(theSetNo >= 0 && theSetNo < 8);
    ASSERT(theNo >= 0 && theNo < m_num[type]);
    int n = theNo;
    for (int i = 0; i < m_num[type]; i++) {
        if (m_set[theSetNo][type] & (1 << i)) {
            if (--n < 0) {
                return &((DogLightAmbient *)m_light[type])[i];
            }
        }
    }
    return 0;
}







// 0x0011076C
DogLightDirect *DogLightPool::getSetDirect(int theSetNo, int theNo)
{
    const int type = DOG_LIGHT_DIRECT;
    ASSERT(m_light[type]);
    ASSERT(theSetNo >= 0 && theSetNo < 8);
    ASSERT(theNo >= 0 && theNo < m_num[type]);
    int n = theNo;
    for (int i = 0; i < m_num[type]; i++) {
        if (m_set[theSetNo][type] & (1 << i)) {
            if (--n < 0) {
                return &((DogLightDirect *)m_light[type])[i];
            }
        }
    }
    return 0;
}







// 0x00110878
DogLightPoint *DogLightPool::getSetPoint(int theSetNo, int theNo)
{
    const int type = DOG_LIGHT_POINT;
    ASSERT(m_light[type]);
    ASSERT(theSetNo >= 0 && theSetNo < 8);
    ASSERT(theNo >= 0 && theNo < m_num[type]);
    int n = theNo;
    for (int i = 0; i < m_num[type]; i++) {
        if (m_set[theSetNo][type] & (1 << i)) {
            if (--n < 0) {
                return &((DogLightPoint *)m_light[type])[i];
            }
        }
    }
    return 0;
}







// 0x00110988
DogLightSpot *DogLightPool::getSetSpot(int theSetNo, int theNo)
{
    const int type = DOG_LIGHT_SPOT;
    ASSERT(m_light[type]);
    ASSERT(theSetNo >= 0 && theSetNo < 8);
    ASSERT(theNo >= 0 && theNo < m_num[type]);
    int n = theNo;
    for (int i = 0; i < m_num[type]; i++) {
        if (m_set[theSetNo][type] & (1 << i)) {
            if (--n < 0) {
                return &((DogLightSpot *)m_light[type])[i];
            }
        }
    }
    return 0;
}

// 0x00110A94
void DogLightPool::clear()
{
    for (int i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        m_light[i] = 0;
        m_num[i] = 0;
        m_used[i] = 0;
        for (int j = 0; j < 8; j++) {
            m_set[j][i] = 0;
        }
    }
    m_data = 0;
}















// 0x00110AF8: frees lights allocated one type at a time (init(const int
// *)). It asserts first: the game does not use it.
void DogLightPool::freeLights()
{
    ASSERT(0);
    for (int i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        if (m_light[i]) {
            D_006E9800.free(m_light[i]);
        }
    }
    clear();
}

// 0x00110B78
void DogLightPool::release()
{
    if (m_data) {
        D_006E9800.free(m_data);
    }
    clear();
}

// 0x00110BB8
void dogLightGray(float *theColor)
{
    float y = theColor[0] * 0.299f + theColor[1] * 0.587f + theColor[2] * 0.114f;
    theColor[0] = theColor[1] = theColor[2] = y;
}
















// 0x00110C0C: one more light of theType (at most 32); its ID (theType in
// bits 5 and up), or -1.
int DogLightPool::add(int theType)
{
    ASSERT(theType >= 0 && theType < DOG_MAX_LIGHT_TYPE);
    if (m_num[theType] >= 32) {
        return -1;
    }
    int size = sLightSize[theType];
    void *a = D_006E9800.alloc((m_num[theType] + 1) * size, -1);

    ASSERT(a);
    if (a == 0) {
        return -1;
    }
    if (m_light[theType]) {
        memcpy(a, m_light[theType], m_num[theType] * size);
        D_006E9800.free(m_light[theType]);
        m_light[theType] = 0;
    }
    memset((char *)a + m_num[theType] * size, 0, size);
    m_light[theType] = a;
    int id = (theType << 5) + m_num[theType];
    m_num[theType]++;
    return id;
}

// 0x00110D58
void DogLightPool::func_00110D58()
{
}

// 0x00110D60
int DogLightPool::getDataSize()
{
    return sizeof(DogLightAmbient) * 8 + sizeof(DogLightDirect) * 8 + sizeof(DogLightPoint) * 16
        + sizeof(DogLightSpot) * 8;
}









































// 0x00110D68: one block for 8 ambient, 8 direct, 16 point and 8 spot
// lights.
int DogLightPool::init()
{
    ASSERT(m_data == __null);
    clear();
    int size = getDataSize();




    ASSERT(m_data == __null);
    m_data = D_006E9800.alloc(size, -1);




    ASSERT(m_data);
    char *p = (char *)m_data;
    m_light[DOG_LIGHT_AMBIENT] = p;
    p += sizeof(DogLightAmbient) * 8;
    m_light[DOG_LIGHT_DIRECT] = p;
    p += sizeof(DogLightDirect) * 8;
    m_light[DOG_LIGHT_POINT] = p;
    p += sizeof(DogLightPoint) * 16;
    m_light[DOG_LIGHT_SPOT] = p;
    m_num[DOG_LIGHT_AMBIENT] = 8;
    m_num[DOG_LIGHT_DIRECT] = 8;
    m_num[DOG_LIGHT_POINT] = 16;
    m_num[DOG_LIGHT_SPOT] = 8;
    m_num[DOG_LIGHT_HEMI] = 0;
    m_num[DOG_LIGHT_DIST] = 0;
    return 1;
}


















































// 0x00110E64: theNum[type] lights of each type, one block per type.
void DogLightPool::init(const int *theNum)
{
    freeLights();
    for (int i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        if (m_light[i]) {
            D_006E9800.free(m_light[i]);
            m_light[i] = 0;
        }
        m_num[i] = 0;
        if (theNum[i]) {
            int size = sLightSize[i] * theNum[i];
            void *p = D_006E9800.alloc(size, -1);
            ASSERT(p);
            memset(p, 0, size);
            m_light[i] = p;
            m_num[i] = theNum[i];
        }
    }
}












// 0x00110F78: empties set theSet; all of them (and init) when it is < 0.
void DogLightPool::clearSet(int theSet)
{
    int i;
    if (theSet < 0) {
        clear();
        init();
        return;
    }
    ASSERT(theSet >= 0 && theSet < 8);
    for (i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        m_set[theSet][i] = 0;
    }
    for (i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        unsigned int used = 0;
        for (int j = 0; j < 8; j++) {
            used |= m_set[j][i];
        }
        m_used[i] = used;
    }
}

// 0x00111064: set theSet gets theNum[type] free lights of each type.
void DogLightPool::setSet(int theSet, const int *theNum)
{
    clearSet(theSet);
    for (int i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        for (int j = 0; j < theNum[i]; j++) {
            m_set[theSet][i] |= 1 << allocID(i);
        }
    }
}
























































































































































// 0x00111120: the first light of theType no set uses, now used.
int DogLightPool::allocID(int theType)
{
    ASSERT(theType >= 0 && theType < DOG_MAX_LIGHT_TYPE);
    for (int i = 0; i < m_num[theType]; i++) {
        unsigned int bit = 1 << i;
        if (!(m_used[theType] & bit)) {
            m_used[theType] |= bit;
            return i;
        }
    }







    ASSERT(0);
    return -1;
}



// 0x001111E4
void DogLightPool::freeID(int theType, int theNo)
{
    ASSERT(theNo >= 0);

    ASSERT(theType >= 0 && theType < DOG_MAX_LIGHT_TYPE);
    unsigned int mask = ~(1 << theNo);
    m_used[theType] &= mask;
    for (int i = 0; i < 8; i++) {
        m_set[i][theType] &= mask;
    }
}





// 0x001112A8
void DogLightPool::setID(int theSet, int theType, int theID)
{
    ASSERT(theSet >= 0 && theSet < 8);
    ASSERT(theID >= 0);
    ASSERT(theType >= 0 && theType < DOG_MAX_LIGHT_TYPE);
    unsigned int bit = 1 << (theID & 0x1F);
    m_used[theType] |= bit;
    m_set[theSet][theType] |= bit;
}






// 0x0011139C: in every set.
void DogLightPool::setID(int theType, int theID)
{
    ASSERT(theID >= 0);
    ASSERT(theType >= 0 && theType < DOG_MAX_LIGHT_TYPE);
    unsigned int bit = 1 << (theID & 0x1F);
    m_used[theType] |= bit;
    for (int i = 0; i < 8; i++) {
        m_set[i][theType] |= bit;
    }
}

// 0x00111460
void DogLightPool::makeSet(DogLightSet *theSet, const unsigned int *theMask)
{
    for (int i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        if (m_light[i] && theMask[i]) {
            theSet->set(i, m_light[i], theMask[i]);
        }
    }
    theSet->setup();
}

// 0x001114EC
void DogLightPool::getMask(unsigned int *theMask, int theSet)
{
    for (int i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        theMask[i] = m_set[theSet][i];
    }
}

// 0x00111528
void DogLightPool::copySet(int theDst, int theSrc)
{
    for (int i = 0; i < DOG_MAX_LIGHT_TYPE; i++) {
        m_set[theDst][i] = m_set[theSrc][i];
    }
}


















































// 0x00111584: sets a light's position, direction, colour or (spot) cone
// angles from theValue.
void DogLightPool::setParam(int theType, int theNo, int theParam, const float *theValue)
{
    float *p = 0;
    if (theParam == DOG_LIGHT_PARAM_ANGLE) {
        if (theType == DOG_LIGHT_SPOT) {
            getSpot(theNo)->m_angle[0] = theValue[0] * DOG_PI / 180.0f;
            getSpot(theNo)->m_angle[1] = theValue[1] * DOG_PI / 180.0f;
        } else {
            ASSERT(0);
        }
        return;
    }
    if (theParam == DOG_LIGHT_PARAM_POS) {
        if (theType == DOG_LIGHT_POINT) {
            p = getPoint(theNo)->m_pos;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSpot(theNo)->m_pos;
        } else {












            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_DIR) {
        if (theType == DOG_LIGHT_DIRECT) {
            p = getDirect(theNo)->m_dir;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSpot(theNo)->m_dir;
        } else {













            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_COLOR) {
        if (theType == DOG_LIGHT_AMBIENT) {
            p = getAmbient(theNo)->m_color;
        } else if (theType == DOG_LIGHT_POINT) {
            p = getPoint(theNo)->m_color;
        } else if (theType == DOG_LIGHT_DIRECT) {
            p = getDirect(theNo)->m_color;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSpot(theNo)->m_color;
        } else {























            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_3) {










        ASSERT(0);
    } else if (theParam == DOG_LIGHT_PARAM_4) {











        ASSERT(0);
    } else {




























        ASSERT(0);
    }
    if (p) {
        for (int i = 0; i < 4; i++) {
            p[i] = theValue[i];
        }
    }
}













// 0x00111B5C: the other way round.
void DogLightPool::getParam(int theType, int theNo, int theParam, float *theValue) const
{
    const float *p = 0;
    if (theParam == DOG_LIGHT_PARAM_ANGLE) {
        if (theType == DOG_LIGHT_SPOT) {
            theValue[0] = getSpot(theNo)->m_angle[0] * 180.0f / DOG_PI;
            theValue[1] = getSpot(theNo)->m_angle[1] * 180.0f / DOG_PI;
        } else {
            ASSERT(0);
        }
        return;
    }
    if (theParam == DOG_LIGHT_PARAM_POS) {
        if (theType == DOG_LIGHT_POINT) {
            p = getPoint(theNo)->m_pos;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSpot(theNo)->m_pos;
        } else {












            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_DIR) {
        if (theType == DOG_LIGHT_DIRECT) {
            p = getDirect(theNo)->m_dir;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSpot(theNo)->m_dir;
        } else {













            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_COLOR) {
        if (theType == DOG_LIGHT_AMBIENT) {
            p = getAmbient(theNo)->m_color;
        } else if (theType == DOG_LIGHT_POINT) {
            p = getPoint(theNo)->m_color;
        } else if (theType == DOG_LIGHT_DIRECT) {
            p = getDirect(theNo)->m_color;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSpot(theNo)->m_color;
        } else {























            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_3) {










        ASSERT(0);
    } else if (theParam == DOG_LIGHT_PARAM_4) {











        ASSERT(0);
    } else {




















        ASSERT(0);
    }
    if (p) {
        for (int i = 0; i < 4; i++) {
            theValue[i] = p[i];
        }
    }
}




























// 0x00112134: setParam for the theNo-th light of set theSetNo.
void DogLightPool::setSetParam(int theType, int theNo, int theParam, const float *theValue, int theSetNo)
{
    float *p = 0;
    if (theParam == DOG_LIGHT_PARAM_ANGLE) {
        if (theType == DOG_LIGHT_SPOT) {
            getSetSpot(theSetNo, theNo)->m_angle[0] = theValue[0] * DOG_PI / 180.0f;
            getSetSpot(theSetNo, theNo)->m_angle[1] = theValue[1] * DOG_PI / 180.0f;
        } else {
            ASSERT(0);
        }
        return;
    }
    if (theParam == DOG_LIGHT_PARAM_POS) {
        if (theType == DOG_LIGHT_POINT) {
            p = getSetPoint(theSetNo, theNo)->m_pos;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSetSpot(theSetNo, theNo)->m_pos;
        } else {






            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_DIR) {
        if (theType == DOG_LIGHT_DIRECT) {
            p = getSetDirect(theSetNo, theNo)->m_dir;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSetSpot(theSetNo, theNo)->m_dir;
        } else {







            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_COLOR) {
        if (theType == DOG_LIGHT_AMBIENT) {
            p = getSetAmbient(theSetNo, theNo)->m_color;
        } else if (theType == DOG_LIGHT_POINT) {
            p = getSetPoint(theSetNo, theNo)->m_color;
        } else if (theType == DOG_LIGHT_DIRECT) {
            p = getSetDirect(theSetNo, theNo)->m_color;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSetSpot(theSetNo, theNo)->m_color;
        } else {











            ASSERT(0);
        }
    } else {


        ASSERT(0);
    }
    if (p) {
        for (int i = 0; i < 4; i++) {
            p[i] = theValue[i];
        }
    }
}










// 0x001123B0: getParam for the theNo-th light of set theSetNo.
void DogLightPool::getSetParam(int theType, int theNo, int theParam, float *theValue, int theSetNo)
{
    float *p = 0;
    if (theParam == DOG_LIGHT_PARAM_ANGLE) {
        if (theType == DOG_LIGHT_SPOT) {
            theValue[0] = getSetSpot(theSetNo, theNo)->m_angle[0] * 180.0f / DOG_PI;
            theValue[1] = getSetSpot(theSetNo, theNo)->m_angle[1] * 180.0f / DOG_PI;
        } else {
            ASSERT(0);
        }
        return;
    }
    if (theParam == DOG_LIGHT_PARAM_POS) {
        if (theType == DOG_LIGHT_POINT) {
            p = getSetPoint(theSetNo, theNo)->m_pos;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSetSpot(theSetNo, theNo)->m_pos;
        } else {






            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_DIR) {
        if (theType == DOG_LIGHT_DIRECT) {
            p = getSetDirect(theSetNo, theNo)->m_dir;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSetSpot(theSetNo, theNo)->m_dir;
        } else {







            ASSERT(0);
        }
    } else if (theParam == DOG_LIGHT_PARAM_COLOR) {
        if (theType == DOG_LIGHT_AMBIENT) {
            p = getSetAmbient(theSetNo, theNo)->m_color;
        } else if (theType == DOG_LIGHT_POINT) {
            p = getSetPoint(theSetNo, theNo)->m_color;
        } else if (theType == DOG_LIGHT_DIRECT) {
            p = getSetDirect(theSetNo, theNo)->m_color;
        } else if (theType == DOG_LIGHT_SPOT) {
            p = getSetSpot(theSetNo, theNo)->m_color;
        } else {











            ASSERT(0);
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

// 0x0011262C: gives theTarget set theSet's ambient, direct and point
// lights, their colours times theScale, grey if theGray.
void DogLightPool::apply(void *theTarget, int theSet, float theScale, int theGray) const
{
    I3dLightList list;
    DogLightDirect direct[8];
    DogLightPoint point[16];

    func_0021AC80(&list);
    if (m_set[theSet][DOG_LIGHT_AMBIENT]) {
        unsigned int bit = 1;
        for (int i = 0; i < 8; i++, bit <<= 1) {
            if (m_set[theSet][DOG_LIGHT_AMBIENT] & bit) {
                const float *c = getAmbient(i)->m_color;
                if (theScale == 1.0f) {
                    func_002372E0(list.m_ambient, c);
                } else {
                    list.m_ambient[0] = c[0] * theScale;
                    list.m_ambient[1] = c[1] * theScale;
                    list.m_ambient[2] = c[2] * theScale;
                }
                if (theGray) {
                    dogLightGray(list.m_ambient);
                }
                break;
            }
        }
    }
    list.m_ambient[3] = 1.0f;
    if (m_set[theSet][DOG_LIGHT_DIRECT]) {
        int n = 0;
        unsigned int bit = 1;
        for (int i = 0; i < 8; i++) {
            if (m_set[theSet][DOG_LIGHT_DIRECT] & bit) {
                const DogLightDirect *l = getDirect(i);
                func_002372D0(direct[n].m_dir, l->m_dir);
                func_002372E0(direct[n].m_color, l->m_color);
                if (theGray) {
                    dogLightGray(direct[n].m_color);
                }
                n++;
            }
            bit <<= 1;
        }
        list.m_num_direct = n;
        list.m_direct = direct;
    }
    if (m_set[theSet][DOG_LIGHT_POINT]) {
        int n = 0;
        unsigned int bit = 1;
        for (int i = 0; i < 16; i++) {
            if (m_set[theSet][DOG_LIGHT_POINT] & bit) {
                const DogLightPoint *l = getPoint(i);
                func_002372D0(point[n].m_pos, l->m_pos);
                func_002372E0(point[n].m_color, l->m_color);
                if (theGray) {
                    dogLightGray(point[n].m_color);
                }
                n++;
            }
            bit <<= 1;
        }
        list.m_num_point = n;
        list.m_point = point;
    }
    func_0021B148(theTarget, &list);
}

// 0x001129CC: the point light of set theSet nearest to thePos, or -1.
int DogLightPool::getNearestPoint(int theSet, const float *thePos)
{
    static const int sMaxDist = 0x7FFFFFFF;
    unsigned int mask = m_set[theSet][DOG_LIGHT_POINT];
    int best = -1;
    float d = *(const float *)&sMaxDist;
    for (int i = 0; mask; i++) {
        bool off = !(mask & 1);
        mask >>= 1;
        if (!off) {
            const float *p = getPoint(i)->m_pos;
            float x = p[0] - thePos[0];
            float y = p[1] - thePos[1];
            float z = p[2] - thePos[2];
            float dd = x * x + y * y + z * z;
            if (dd < d) {
                d = dd;
                best = i;
            }
        }
    }
    return best;
}
