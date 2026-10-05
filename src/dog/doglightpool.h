// dog/doglightpool.h: the scene's lights. A DogLightPool keeps every light of
// each type and up to 8 sets of them; DogLightSet holds one set's copies as
// i3d reads them. Types, m_light, m_num, m_data and parameter names come from
// asserts; other names but DogLightPool are ours. The inline getters must
// stay on lines 129-132 and 140-143 (their asserts carry this __LINE__).
#ifndef DOG_DOGLIGHTPOOL_H
#define DOG_DOGLIGHTPOOL_H

#include "ror.h"

enum {
    DOG_LIGHT_AMBIENT,
    DOG_LIGHT_DIRECT,
    DOG_LIGHT_POINT,
    DOG_LIGHT_SPOT,
    DOG_LIGHT_HEMI,
    DOG_LIGHT_DIST,
    DOG_MAX_LIGHT_TYPE
};

// What setParam/getParam read or write (values ours).
enum {
    DOG_LIGHT_PARAM_POS,            // point, spot, dist
    DOG_LIGHT_PARAM_DIR,            // direct, spot, hemi
    DOG_LIGHT_PARAM_COLOR,
    DOG_LIGHT_PARAM_COLOR2,         // hemi
    DOG_LIGHT_PARAM_DIST,           // dist
    DOG_LIGHT_PARAM_ANGLE,          // spot: two angles, in degrees outside
    DOG_LIGHT_PARAM_ENABLE          // DogLight: the type on (value != 0) or off
};

struct DogLightAmbient {            // 0x10; copied 8 bytes at a time
    float m_color[4];
} __attribute__((aligned(8)));

struct DogLightDirect {             // 0x20
    float m_dir[4];
    float m_color[4];
};

struct DogLightPoint {              // 0x20
    float m_pos[4];
    float m_color[4];
};

struct DogLightSpot {               // 0x40
    float m_pos[4];
    float m_dir[4];
    float m_color[4];
    float m_angle[2];               // radians
    float m_unk38[2];
};
struct DogLightHemi;               // both defined below the getters
struct DogLightDist;
// The light list i3d draws with (func_0021AC80 clears it).
struct I3dLightList {               // 0x40
    DogLightAmbient m_ambient;      // +0x00
    int m_num_direct;               // +0x10
    DogLightDirect *m_direct;       // +0x14
    int m_num_point;                // +0x18
    DogLightPoint *m_point;         // +0x1C
    int m_num_spot;                 // +0x20
    DogLightSpot *m_spot;           // +0x24
    int m_num_hemi;                 // +0x28
    DogLightHemi *m_hemi;           // +0x2C
    int m_num_dist;                 // +0x30
    DogLightDist *m_dist;           // +0x34
    int m_unk38;                    // +0x38
    int m_unk3C;                    // +0x3C
};

extern "C" {
void func_0021AC80(I3dLightList *theList);                     // clears it
void func_0021B148(void *theTarget, I3dLightList *theList);    // gives it to theTarget
void func_002372D0(float *theOut, const float *theIn);         // copies x, y, z (w = 1)
void func_002372E0(float *theOut, const float *theIn);         // copies a vector
}

class DogLightSet {
public:
    DogLightAmbient m_ambient[8];   // +0x000
    DogLightDirect m_direct[8];     // +0x080
    DogLightPoint m_point[16];      // +0x180
    DogLightSpot m_spot[8];         // +0x380
    I3dLightList m_list;            // +0x580
    int m_num[DOG_MAX_LIGHT_TYPE];  // +0x5C0

    void set(int theType, const void *theLight, unsigned int theMask);
    void setup();
    void clear();
};

class DogLightPool {
public:
    void *m_light[DOG_MAX_LIGHT_TYPE];          // +0x000
    int m_num[DOG_MAX_LIGHT_TYPE];              // +0x018
    unsigned int m_used[DOG_MAX_LIGHT_TYPE];    // +0x030: lights some set uses
    unsigned int m_set[8][DOG_MAX_LIGHT_TYPE];  // +0x048: lights of each set
    void *m_data;                               // +0x108: all of them (init)

    DogLightAmbient *getSetAmbient(int theSetNo, int theNo);
    DogLightDirect *getSetDirect(int theSetNo, int theNo);
    DogLightPoint *getSetPoint(int theSetNo, int theNo);
    DogLightSpot *getSetSpot(int theSetNo, int theNo);
    void clear();
    void freeLights();
    void release();
    int add(int theType);
    void func_00110D58();
    int getDataSize();
    int init();
    void init(const int *theNum);
    void clearSet(int theSet);
    void setSet(int theSet, const int *theNum);
    int allocID(int theType);
    void freeID(int theType, int theNo);
    void setID(int theSet, int theType, int theID);
    void setID(int theType, int theID);
    void makeSet(DogLightSet *theSet, const unsigned int *theMask);
    void getMask(unsigned int *theMask, int theSet);
    void copySet(int theDst, int theSrc);
    void setParam(int theType, int theNo, int theParam, const float *theValue);
    void getParam(int theType, int theNo, int theParam, float *theValue) const;
    void setSetParam(int theType, int theNo, int theParam, const float *theValue, int theSetNo);
    void getSetParam(int theType, int theNo, int theParam, float *theValue, int theSetNo);
    void apply(void *theTarget, int theSet, float theScale, int theGray) const;
    int getNearestPoint(int theSet, const float *thePos);

    DogLightAmbient *getAmbient(int n) { ASSERT(n>=0 && n<m_num[DOG_LIGHT_AMBIENT]); ASSERT(m_light[DOG_LIGHT_AMBIENT]); return &((DogLightAmbient *)m_light[DOG_LIGHT_AMBIENT])[n]; }
    DogLightDirect *getDirect(int n) { ASSERT(n>=0 && n<m_num[DOG_LIGHT_DIRECT]); ASSERT(m_light[DOG_LIGHT_DIRECT]); return &((DogLightDirect *)m_light[DOG_LIGHT_DIRECT])[n]; }
    DogLightPoint *getPoint(int n) { ASSERT(n>=0 && n<m_num[DOG_LIGHT_POINT]); ASSERT(m_light[DOG_LIGHT_POINT]); return &((DogLightPoint *)m_light[DOG_LIGHT_POINT])[n]; }
    DogLightSpot *getSpot(int n) { ASSERT(n>=0 && n<m_num[DOG_LIGHT_SPOT]); ASSERT(m_light[DOG_LIGHT_SPOT]); return &((DogLightSpot *)m_light[DOG_LIGHT_SPOT])[n]; }







    const DogLightAmbient *getAmbient(int n) const { ASSERT(n>=0 && n<m_num[DOG_LIGHT_AMBIENT]); ASSERT(m_light[DOG_LIGHT_AMBIENT]); return &((const DogLightAmbient *)m_light[DOG_LIGHT_AMBIENT])[n]; }
    const DogLightDirect *getDirect(int n) const { ASSERT(n>=0 && n<m_num[DOG_LIGHT_DIRECT]); ASSERT(m_light[DOG_LIGHT_DIRECT]); return &((const DogLightDirect *)m_light[DOG_LIGHT_DIRECT])[n]; }
    const DogLightPoint *getPoint(int n) const { ASSERT(n>=0 && n<m_num[DOG_LIGHT_POINT]); ASSERT(m_light[DOG_LIGHT_POINT]); return &((const DogLightPoint *)m_light[DOG_LIGHT_POINT])[n]; }
    const DogLightSpot *getSpot(int n) const { ASSERT(n>=0 && n<m_num[DOG_LIGHT_SPOT]); ASSERT(m_light[DOG_LIGHT_SPOT]); return &((const DogLightSpot *)m_light[DOG_LIGHT_SPOT])[n]; }
};

// Grey: each of r, g, b becomes their luminance.
void dogLightGray(float *theColor);


struct DogLightHemi {               // 0x30
    float m_dir[4];
    float m_color[4];
    float m_color2[4];              // setParam 3
};

struct DogLightDist {               // 0x30
    float m_pos[4];
    float m_color[4];
    float m_unk20[4];               // setParam 4
};

#endif
