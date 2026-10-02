// mw/i3d.h: the i3d middleware (C), reduced to what decompiled code calls.
// Its function names are lost; these are placeholders by address.
#ifndef MW_I3D_H
#define MW_I3D_H

struct tag_I3mPosture_s;

// The interpolation mode passed with motion lookups (name from the
// mangled DogActor::getMotion; values unknown).
enum I3M_INTER {
    I3M_INTER_DEFAULT
};

struct tag_I3dMatrixF4x4_s {
    float m[4][4];
};

extern "C" {

int func_0022B518(void *theRoot);                        // unpack a motion; 0 = ok
int func_0022B6F8(void *theRoot);                        // number of nodes
const char *func_0022B730(void *theRoot, unsigned short theNode);   // node name
int func_0022B790(void *theRoot, const char *theName);   // node index by name
int func_0022B3D8(void *theRoot, const char *theName);   // model node index by name
int func_0022AEC0(void *theList);                        // number of materials
void *func_0022AED8(void *theList, int theN);            // material
const char *func_0022AF08(void *theList, int theN);      // material name
int func_0022AAD0(void *theMaterial, int theN);          // its texture
void func_0021AB30(int theTex, float *theRect);          // sets a texture's rectangle
void func_0021A760(void *theRoot, const void *theModel, const void *theLocal);   // model matrices from local ones
void func_0022F7A0(tag_I3mPosture_s *thePosture, void *theLocal, short *theAssign);  // local matrices from a pose
void func_00231198(float *theQuat, const float *theRot);  // quaternion from angles
void func_00230470(float *theOut, const float *a, const float *b);  // quaternion product
void func_00230660(float *theOut, const float *theIn);   // normalized quaternion
void func_00237390(float *theOut, const float *theIn, float theScale);  // scaled vector
float func_0022E958(void *theRoot);                      // length in frames
void func_0022E960(void *theRoot, tag_I3mPosture_s *theOut, int theFlags, float theTime);
// Blends motion theA at theTimeA with theB at theTimeB by theRate into theOut.
void func_0022EAB0(void *theA, tag_I3mPosture_s *theOut, void *theB, int theFlags, float theTimeA, float theTimeB, float theRate);
void func_0022F610(tag_I3mPosture_s *theOut, tag_I3mPosture_s *a, tag_I3mPosture_s *b, float theRatio);

}

#endif
