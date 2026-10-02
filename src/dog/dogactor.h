// dog/dogactor.h: DogActor, an animated i3d model (the characters, the
// dog...): its motions and blending, and its node matrices.
//
// DogActor, the inline methods' names and the fields named in assert
// strings are original; the rest is ours. The inline methods that assert
// must stay on their lines (233-383): the blank lines keep them there.
#ifndef DOG_DOGACTOR_H
#define DOG_DOGACTOR_H

#include "ror.h"
#include "dog/dogmodel.h"
#include "dog/dogmotionblend.h"
#include "mw/i3d.h"

// The longest motion command list, and the most motion packs (assert
// strings).
#define DOG_MAX_MOTION_CMD 8
#define DOG_MAX_PACK_MOTION (4)

// DogActor::m_flag_motion_data: how the motions were loaded (EACH is
// original, from an assert string).
enum {
    FLAG_MOTION_PACK = 0,   // from packs (m_pack_motion)
    FLAG_MOTION_EACH = 1    // one allocation per motion
};

class DogActor : public DogModel {
public:
    int m_id;                       // +0x1A0
    void *m_unk1A4;                 // +0x1A4
    int m_flag_motion_data;         // +0x1A8: FLAG_MOTION_*, -1 = none
    void *m_pack_motion[DOG_MAX_PACK_MOTION]; // +0x1AC: the motion packs
    int m_unk1BC;                   // +0x1BC
    int m_max_motion;               // +0x1C0
    DogMotionData *m_motion_data;   // +0x1C4
    int m_unk1C8;                   // +0x1C8: nodes of the main motion
    I3mPosture *m_posture;          // +0x1CC
    I3mPosture *m_unk1D0;           // +0x1D0: m_posture + nodes
    short *m_assign_tbl;            // +0x1D4: model node of each motion node
    int m_interpolation;            // +0x1D8
    float m_motion_speed0;          // +0x1DC: setMotionSpeed0 (< 0: from the end)
    float m_motion_time0;           // +0x1E0: setMotionTime0
    DogMotionBlend m_motion_now;    // +0x1E4
    DogMotionBlend m_motion_old;    // +0x2C4
    unsigned char m_unk3A4[0xC];    // +0x3A4
    DogVector m_unk3B0;             // +0x3B0
    DogVector m_base_rot;           // +0x3C0
    float m_rot_y_aar;              // +0x3D0
    int m_control_node;             // +0x3D4
    int m_control_node_flg;         // +0x3D8
    unsigned char m_unk3DC[0x4];    // +0x3DC
    DogVector m_unk3E0;             // +0x3E0
    int m_motion_flag[2];           // +0x3F0
    int m_scale_node_no[5];         // +0x3F8: nodes scaled by m_scale_node_val (-1: free)
    float m_scale_node_val[5];      // +0x40C
    float m_trans_ofs_y_save;       // +0x420
    float m_rot_ofs_y;              // +0x424
    int m_motion_loop_trig;         // +0x428
    int m_unk42C[DOG_MAX_MOTION_CMD]; // +0x42C: motion commands
    int m_motion_cmd_idx;           // +0x44C: next command
    int m_unk450;                   // +0x450
    int m_unk454;                   // +0x454
    float m_unk458;                 // +0x458
    int m_unk45C;                   // +0x45C
    int m_unk460;                   // +0x460
    unsigned char m_unk464[0xC];    // +0x464
    float m_unk470[4];              // +0x470: eye texture rectangle
    int m_unk480;                   // +0x480: eye texture
    void *m_unk484;                 // +0x484: eye material
    int m_unk488;                   // +0x488: eye flags
    int m_unk48C;                   // +0x48C: eye frame
    int m_unk490;                   // +0x490
    int m_unk494;                   // +0x494
    unsigned char m_unk498[0x8];    // +0x498
    float m_unk4A0[4];              // +0x4A0: (0, 0, 0, 0) after init
    float m_unk4B0[4];              // +0x4B0: (1, 1, 1, 1) after init
    float m_unk4C0;                 // +0x4C0
    unsigned char m_unk4C4;         // +0x4C4
    unsigned char m_unk4C5;         // +0x4C5
    unsigned char m_unk4C6[0xA];    // +0x4C6

    DogActor();
    int getMode() const { return m_submode.m_mode; }
    int getMotionNo() const { return m_motion_now.getMainMotionNo(); }
    void saveTransOfsY() { m_trans_ofs_y_save = m_unk70.m_y; }
    void ready() { getSubMode()->m_step = -1; getSubMode()->m_mode = 0; }
    void clearRotYAAR() { m_rot_y_aar = 0.0f; }
    DogActor(int theN);
    virtual ~DogActor();
    virtual void vfunc12(void *theRenderStage, void *a, void *b);
    virtual int vfunc14(void *theTex, BedPfh *thePfh, int theA, int theB);
    virtual int vfunc15(void *theData, void *theA, void *theB);
    virtual void vfunc17(float (*theOut)[4], int theNode);
    virtual void vfunc18(DogVector &theOut, int theNode);
    virtual void vfunc19(void *theRenderStage, int theUseMatrix, DogEntity *theParent);
    virtual void vfunc20(void *theRenderStage);
    virtual int vfunc21(DogActor *theSrc);
    void init();
    void allocMotion(int theN);
    void release(int theAll);
    void nextStep();
    int allocPosture(int theNo);
    void freePosture();
    void allocLastMotion();
    int getTagNumFrame(const DogMotionTag *theTag);
    int getTagType(const DogMotionTag *theTag);
    int getTagSize(const DogMotionTag *theTag);
    void getTagVector(const DogMotionTag *theTag, float *theOut, int theFrame);
    float getTagFloat(const DogMotionTag *theTag, int theFrame);
    int func_00108C90(DogVector &theResult, float theTime);
    void func_00109284(DogVector &theResult);
    int func_00109348(float theFrom, float theTo, DogVector &theResult, float *theTurn, DogVector *theAbs);
    int func_00109634(float *theLast);
    void func_00109B48();
    void func_00109B88(int theId);
    void func_00109DEC();
    void func_00109E28(int theAll);
    void func_00109FB4(int theAll);
    void func_0010A038(const DogVector &theMove, float theRot, float theAar);
    void func_0010A090(const DogVector &theMove, float theRot, float theAar);
    void func_0010A1C8(const DogVector &thePos, float theRot, float theAar);
    void func_0010A2D0(DogVector &thePos, DogVector &theRot);
    void func_0010A448(DogVector &theRot);
    float func_0010A584();
    float func_0010A650();
    int func_0010A834();
    void func_0010A840();
    int func_0010A874(int theId);
    int func_0010A8B8(const char *theName);
    int func_0010AA5C(const char *theName);
    int func_0010AA9C(const char *theName);
    int func_0010AB40(const char *theName);
    void func_0010ABF4(const int *theCmd, int theLength);
    void func_0010AC98();
    void func_0010AD0C(int theN, int theFrame);
    void func_0010AE10(int theID);
    void func_0010AE58();
    void func_0010AE90(int theN, int theUnused);
    int func_0010AF18(int theID, int theFlag, float theSpeed, int theLoop, int theInterp);
    int func_0010B1B0(int theNo, float theSpeed, int theFlag, int theNext, int theInterp);
    int func_0010B328(int theSub, int theID, const char **theNodes);
    int func_0010B620(int theSub, const char *theName, const char **theNodes);
    void func_0010B918(int n, float theRatio);
    void func_0010BA20(int theS, float theR);
    void func_0010BAC4(int theS, float theR, int theTime);
    float func_0010BBAC(int n);
    int func_0010BCC8(int theID, float theFrom, float theTo);
    int func_0010BE1C();
    int func_0010BE80(float theUnused);
    int func_0010BED0(float theUnused);
    void func_0010ED2C(float theRot);
    void func_0010E328(int theN);
    void func_0010E7B4();
    void func_0010E7DC(float theRot);
    int func_0010E848(float *theY, float *theRot);
    int func_0010E9AC(const char *theName);
    DogVector *func_0010EAA4();
    void func_0010EAAC(const DogVector &theV);
    void func_0010EDBC();
    void func_0010EBA0(int theNode, float theScale);
    void func_0010EC8C();
    void func_0010EDEC();
    void func_0010F298();
    int func_0010F2DC(const char *theName);
    void func_0010F3A4();
    void func_0010F480();
    void func_0010F5E4(int theFrame);
    void func_0010F70C();
    void func_0010F73C();
    void func_0010F7A0();
    void func_0010F808();
    void func_0010E930();
    float func_0010D0E8(int theID);
    int func_0010D1D0(int theID, int theFlag);
    void func_0010D388();
    int func_0010CD5C(BedPfh *thePfh, void *theTex, int theMode, int theFlag);
    int func_0010C568(BedPfh *thePfh, int theIndex);
    int func_0010C17C(const char *theFileName, int theIndex, int theLevel);
    float func_0010D9EC();
    float func_0010DA18();
    float func_0010DA4C();
    float func_0010DA80();
    const char *func_0010DA98(int theID);
    float func_0010DAD8();
    int func_0010DB18();
    float func_0010DB48();
    float func_0010DD30(int theNode);
    int func_0010DF54(int theFlag) ASM_NOTHROW;
    int func_0010DB38();
    void func_0010BF00(int theFrame);
    int func_0010BF08(int theNo);
    void func_0010EC50();








































    void setMotionSpeedSub(int n, float s) { ASSERT(n>=0 && n<=4); m_motion_now.m_sub[n].m_speed = s; }
    float getMotionSpeedSub(int n) const { ASSERT(n>=0 && n<=4); return m_motion_now.m_sub[n].m_speed; }






















    int getMotionNoSub(int n) { ASSERT(n>=0 && n<=4); return m_motion_now.m_sub[n].m_no; }
































































    virtual float (*getNodeMatrixPtr(int n))[4][4] { ASSERT(m_mat_model); return &m_mat_model[n]; }



















    void *GetI3mRootPtr(int n) { ASSERT(n>=0); ASSERT(m_motion_data); ASSERT(m_motion_data[n].m_i3m_root); return m_motion_data[n].m_i3m_root; }


    DogMotionTag *getMotionAuxData(int n) const { if (n < 0) return 0; ASSERT(n>=0); ASSERT(m_motion_data); return m_motion_data[n].m_aux_data; }
    DogMotionEvents *getMotionTagData(int n) const { if (n < 0) return 0; ASSERT(n>=0); ASSERT(m_motion_data); return m_motion_data[n].m_tag_data; }













    float getMaxTime0(int no) const { ASSERT(no>=0 && no < m_max_motion); ASSERT(m_motion_data[no].m_i3m_root); return func_0022E958(m_motion_data[no].m_i3m_root); }







    int unpack(int n) { ASSERT(n>=0 & n<m_max_motion); ASSERT(m_motion_data); ASSERT(m_motion_data[n].m_i3m_root); return func_0022B518(m_motion_data[n].m_i3m_root); }
    int get_nNode(int n) { ASSERT(n>=0 & n<m_max_motion); ASSERT(m_motion_data); ASSERT(m_motion_data[n].m_i3m_root); return func_0022B6F8(m_motion_data[n].m_i3m_root); }
    const char *getNodeName(int n, int i) { ASSERT(n>=0 & n<m_max_motion); ASSERT(m_motion_data); ASSERT(m_motion_data[n].m_i3m_root); ASSERT(0<=i); return func_0022B730(m_motion_data[n].m_i3m_root, i); }

    int i3mGetNodeIndexByName(int n, const char *p) { ASSERT(n>=0 & n<m_max_motion); ASSERT(m_motion_data); ASSERT(m_motion_data[n].m_i3m_root); ASSERT(p); return func_0022B790(m_motion_data[n].m_i3m_root, p); }

    void getMotion(int n, I3mPosture *p, float t, I3M_INTER i) { ASSERT(n>=0 & n<m_max_motion); ASSERT(m_motion_data); ASSERT(m_motion_data[n].m_i3m_root); ASSERT(p); ASSERT(t>=0); func_0022E960(m_motion_data[n].m_i3m_root, p, i, t); }

    void getBlendMotion(int m1, I3mPosture *p, float t1, int m2, float t2, float r, I3M_INTER i) {
        ASSERT(m_motion_data);
        ASSERT(m_motion_data[m1].m_i3m_root);
        ASSERT(m_motion_data[m2].m_i3m_root);
        ASSERT(p);
        ASSERT(t1>=0.0f);
        ASSERT(t2>=0.0f);
        ASSERT(r >= 0.0f && r <= 1.0f);
        func_0022EAB0(m_motion_data[m1].m_i3m_root, p, m_motion_data[m2].m_i3m_root, i, t1, t2, r);
    }
};

#endif
