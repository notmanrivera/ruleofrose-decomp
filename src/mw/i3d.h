// mw/i3d.h: the i3d middleware (C), reduced to what decompiled code calls.
// Its function names are lost; these are placeholders by address.
#ifndef MW_I3D_H
#define MW_I3D_H

struct tag_I3mPosture_s;
struct tag_I3rRoot_s;
struct tag_I3dTexInfo_s;

// i3d's result codes (I3D_OK from DogModel's asserts).
enum {
    I3D_OK
};

// A collision query (names ours): the callback gets every triangle hit.
struct I3cQuery {
    void *m_root;                   // +0x00: i3c root
    float (*m_mat)[4][4];           // +0x04: node matrices
    short *m_colli_tbl;             // +0x08: i3c node -> matrix
    int m_group;                    // +0x0C: -1: all
    int (*m_func)(I3cQuery *theQuery, void *, unsigned short *theTri, float (*theVert)[4],
                  float *theNormal, float *theHit);   // +0x10
    int m_unk14;                    // +0x14
    void *m_user;                   // +0x18
    int m_unk1C;                    // +0x1C
    int m_unk20;                    // +0x20
    int m_unk24;                    // +0x24
    int m_unk28;                    // +0x28
    int m_unk2C;                    // +0x2C
};

// The interpolation mode passed with motion lookups (name from the
// mangled DogActor::getMotion; values unknown).
enum I3M_INTER {
    I3M_INTER_DEFAULT
};

struct tag_I3dMatrixF4x4_s {
    float m[4][4];
};

// The drawing context MagSystem keeps (+0x3A0): its packet buffer and
// state. 0x12168 bytes, which i3d itself reports (func_0021F1A8); the name
// is ours.
struct I3dDraw {
    unsigned char m_unk[0x12168];
};

// A texture as a model's root sees it (pszTexName and pPicture from
// DogTexInfo's asserts; DogTexInfo keeps an array of them).
struct tag_I3dTexInfo_s {           // 0x10
    const char *pszTexName;         // +0x00
    void *pPicture;                 // +0x04: the picture (DogTexData)
    void *pUnk08;                   // +0x08: its palette, if any
    int nUnk0C;                     // +0x0C
};

extern "C" {

int I3rRoot__CheckIdString(tag_I3rRoot_s *theRoot);     // I3D_OK if theRoot is one
int func_0022B330(tag_I3rRoot_s *theRoot);               // unpacks it
int func_0022B370(tag_I3rRoot_s *theRoot);               // number of nodes
const char *func_0022B388(tag_I3rRoot_s *theRoot, int theNode);   // node name
void func_0021A700(tag_I3rRoot_s *theRoot, void *theLocal);  // local matrices
void func_0021A828(tag_I3rRoot_s *theRoot, float *theCenter, float *theRadius);  // clip sphere
int func_0021A5B0(tag_I3rRoot_s *theRoot, const tag_I3dTexInfo_s *theTex, int theNum);  // assigns textures
int func_0022B428(tag_I3rRoot_s *theRoot);               // number of textures
const char *func_0022B438(tag_I3rRoot_s *theRoot, int theTex);   // texture name
int func_002193F0(void *thePicture, void *theTM2, int, int);  // loads a TM2 picture
void func_002197C8(void *thePicture, void *theSrc);      // copies theSrc
void func_00219A98(void *thePicture, tag_I3dTexInfo_s *theInfo);
int func_00219AB0(void *theClut, void *theTM2, int, int);   // loads a TM2 palette
void func_00219D80(void *thePicture, int theTcc);
void func_00219DA8(void *thePicture, int);
int func_00219E58(void *thePicture);                     // I3D_OK: cleared
void func_00219E98(void *thePicture);                    // releases it
int func_00219EB8(void *theClut);                        // I3D_OK: cleared
void func_00219EF8(void *theClut);                       // releases it
void func_0021F1E8(void *theTarget, tag_I3dTexInfo_s *theInfo, int theNum);
int func_0022BBA0(void *theColli);                       // 0 if theColli is a collision root
int func_0022BFD8(void *theColli);                       // number of nodes
const char *func_0022BFE0(void *theColli, unsigned short theNode);  // node name
int func_0022C010(void *theColli);                       // number of groups
const char *func_0022C018(void *theColli, unsigned short theGroup);  // group name
void func_0022C1D8(void *theColli, int);
void func_002324B8(I3cQuery *theQuery, float *theSphere, float (*theMat)[4][4]);
void func_00232508(I3cQuery *theQuery, float *theSegment, float (*theMat)[4][4]);
int func_0021EB28();                                     // 0 if not set up yet
int func_0021F1A8(int theType);                          // sizeof of an i3d type
void func_0021F900(I3dDraw *theDraw, void *theBuf, int theSize, int theN);
void func_0021ED10(I3dDraw *theDraw, int theX, int theY);
void func_0021F8C8(I3dDraw *theDraw);
void func_0021F6A0(I3dDraw *theDraw);
int func_0021F200(I3dDraw *theDraw);                     // packet bytes used
int func_0021F250(I3dDraw *theDraw);                     // trash overrun
void func_0021F760(I3dDraw *theDraw);
void *func_0021F1F8(I3dDraw *theDraw);                   // DMA tag of the packet
int func_00237C68(const char *theFormat, ...);           // printf
void func_002325A8(I3cQuery *theQuery, float *theCapsule, float (*theMat)[4][4]);

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
// 4x4 float matrices (rows: x, y, z axes and the position).
void func_002372F0(float (*theOut)[4], float (*theIn)[4]);                 // copy
void func_00237340(float (*theMat)[4]);                                     // unit matrix
void func_00237640(float (*theOut)[4], float (*theIn)[4], const float *theVec);  // translated
void func_00237678(float (*theOut)[4], float (*theIn)[4]);                 // DogCamera's view matrix from its matrix
void func_002377D0(float (*theOut)[4], float (*a)[4], float (*b)[4]);      // product
void func_00237818(float (*theOut)[4], float (*theIn)[4], float theRot);   // rotated around X
void func_00237830(float (*theOut)[4], float (*theIn)[4], float theRot);   // rotated around Y
void func_00237848(float (*theOut)[4], float (*theIn)[4], float theRot);   // rotated around Z
void func_00237A78(float (*theOut)[4], float (*theIn)[4], const float *theScale);  // scaled
float func_0022E958(void *theRoot);                      // length in frames
void func_0022E960(void *theRoot, tag_I3mPosture_s *theOut, int theFlags, float theTime);
// Blends motion theA at theTimeA with theB at theTimeB by theRate into theOut.
void func_0022EAB0(void *theA, tag_I3mPosture_s *theOut, void *theB, int theFlags, float theTimeA, float theTimeB, float theRate);
void func_0022F610(tag_I3mPosture_s *theOut, tag_I3mPosture_s *a, tag_I3mPosture_s *b, float theRatio);

}

#endif
