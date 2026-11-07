// mag/magscenelight.cpp: MagScene's lights and shadow light.
#include "mag/magscene.h"
#include "dog/doglightpool.h"

#define MAG_MAX_LIGHT_TYPE 6

extern "C" void func_00215BB4(float *theColor);






















void MagScene::func_0013F49C(int theNo)
{
    ASSERT(theNo < (8));
}























void MagScene::func_0013F4D0(int theNo)
{
    ASSERT(theNo < (8));
    ((DogLightPool *)m_light_pool)->clearSet(theNo);
}


























void MagScene::func_0013F528(int *theNum, int theNo)
{
    ASSERT(theNo < (8));

    ASSERT(theNum);
    ((DogLightPool *)m_light_pool)->setSet(theNo, theNum);
    if (theNo == 0) {
        if (theNum[2] > 0) {
            return func_0013FBE4(2, 0);
        } else if (theNum[3] > 0) {
            return func_0013FBE4(3, 0);
        } else if (theNum[5] > 0) {
            return func_0013FBE4(5, 0);
        } else if (theNum[1] > 0) {
            func_0013FBE4(1, 0);
        }
    }
}


























void MagScene::func_0013F658(int *theData)
{
    ASSERT(theData);
    DogLightPool *pool = (DogLightPool *)m_light_pool;
    float *p = (float *)(theData + 4);
    pool->release();
    pool->init();
    int numDirect = theData[0];
    int numPoint = theData[1];
    int shadow = theData[2];
    float color[4];
    int id = pool->allocID(0);
    pool->setID(0, 0, id);
    pool->setID(1, 0, id);
    color[0] = p[0];
    color[1] = p[1];
    color[2] = p[2];
    color[3] = 1.0f;
    p += 4;
    func_00215BB4(color);
    func_0013F980(0, id, 2, color, -1);
    if (numDirect > 0) {
        int id1 = pool->allocID(1);
        pool->setID(1, 1, id1);
        color[0] = p[0];
        color[1] = p[1];
        color[2] = p[2];
        color[3] = 0.0f;
        func_00215BB4(color);
        func_0013F980(1, id1, 2, color, -1);
        func_0013F980(1, id1, 1, (float *)(theData + 11), -1);
        if (shadow == 0) {
            func_0013FBE4(1, id1);
        }
        p += 8;
        shadow--;
    }
    for (int i = 0; i < numPoint; i++) {
        int id2 = pool->allocID(2);
        pool->setID(1, 2, id2);
        float f = p[6];
        color[0] = p[0] * f;
        color[1] = p[1] * f;
        color[2] = p[2] * f;
        color[3] = 0.0f;
        func_00215BB4(color);
        func_0013F980(2, id2, 2, color, -1);
        func_0013F980(2, id2, 0, p + 3, -1);
        if (shadow == 0) {
            func_0013FBE4(2, id2);
        }
        shadow--;
        p += 8;
    }
}

void MagScene::func_0013F8E4()
{
    DogLightPool *pool = (DogLightPool *)m_light_pool;
    float ambient[] = { 0.75f, 0.75f, 0.75f, 1.0f };
    int id = pool->allocID(0);
    pool->setID(6, 0, id);
    func_0013F980(0, id, 2, ambient, -1);
}



















































































void MagScene::func_0013F980(int theType, int theID, int theMode, float *theColor, int theNo)
{
    DogLightPool *pool = (DogLightPool *)m_light_pool;
    ASSERT(theNo < (8));
    if (theNo < 0) {
        pool->setParam(theType, theID, theMode, theColor);
    } else {
        pool->setSetParam(theType, theID, theMode, theColor, theNo);
    }
}












void MagScene::func_0013FA50(int theType, int theID, int theMode, float *theA, int theNo)
{
    DogLightPool *pool = (DogLightPool *)m_light_pool;
    ASSERT(theNo < (8));
    ASSERT(theA);
    if (theNo < 0) {
        pool->getParam(theType, theID, theMode, theA);
    } else {
        pool->getSetParam(theType, theID, theMode, theA, theNo);
    }
}












void MagScene::func_0013FB3C(int theD, int theS)
{
    ASSERT(theD >=0 && theD < (8));
    ASSERT(theS >=0 && theS < (8));
    ASSERT(theD != theS);
    ((DogLightPool *)m_light_pool)->copySet(theD, theS);
}

static const float ShadowAmbient[4] __attribute__((aligned(16))) = { 0.0f, 0.0f, 0.0f, 0.0f };


















void MagScene::func_0013FBE4(int theLight, int theNo)
{
    ASSERT(theLight >= 0 && theLight < MAG_MAX_LIGHT_TYPE);
    ASSERT(theNo >= 0);
    func_0021AC80((I3dLightList *)m_shadow);





    ASSERT((((int)(&ShadowAmbient)) & 0x0f) == 0);
    func_002372E0((float *)m_shadow, (const float *)&ShadowAmbient);
    m_shadow_type = theLight;
    switch (theLight) {
    case 2: {
        const DogLightPool *pool = (const DogLightPool *)m_light_pool;
        m_shadow_light = (void *)pool->getPoint(theNo);
        m_shadow_point_on = 1;
        m_shadow_point = (char *)this + 0x2000;
        break;
    }
    case 3: {
        const DogLightPool *pool = (const DogLightPool *)m_light_pool;
        m_shadow_light = (void *)pool->getSpot(theNo);
        m_shadow_point_on = 1;
        m_shadow_point = (char *)this + 0x2000;
        break;
    }
    case 1: {
        const DogLightPool *pool = (const DogLightPool *)m_light_pool;
        m_shadow_light = (void *)pool->getDirect(theNo);
        m_shadow_direct_on = 1;
        m_shadow_direct = (char *)this + 0x2000;
        break;
    }
    default:
        m_shadow_light = 0;
    }
}
