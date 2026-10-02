#include "ror.h"
#include "dog/dogactor.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"
#include "sdk/ctype.h"
#include "sdk/string.h"

extern BedMemory D_006E9800;     // the global heap
extern int D_006E9840;           // a frame counter

// utl/utlbtl: a random number from theMin to theMax.
extern "C" int func_0010423C(int theMin, int theMax);
// unk/001056E8 and unk/00106658.
struct I3dOwner;
int i3dCallLocked(void *a, void *b, void *c, void *d, void *e);
int i3dSetUser(I3dOwner *theOwner, int theValue, int theNo);
int i3dGetUser(I3dOwner *theOwner, int theNo);
int vu0FTOI15(float theValue);
void vecTurnY(float *theVec, float theAngle);


// A disc file read (code at 0x001BE2CC-0x001BE768, between
// mnu/mnuSelectLanguage and game/gamman); the names are ours.
struct FileReadReq {
    int m_unk00;                    // +0x00: -1 after construction
    int m_unk04;                    // +0x04
    int m_unk08;                    // +0x08
    const char *m_name;             // +0x0C: the file
    int m_offset;                   // +0x10: where to read from
    int m_unk14;                    // +0x14
    void *m_buf;                    // +0x18
    int m_size;                     // +0x1C: bytes, whole sectors
    int m_unk20;                    // +0x20

    FileReadReq();                  // 0x001BE734
};

class FileReader {
public:
    FileReadReq *m_req;             // +0x00
    int m_unk04;                    // +0x04: >= 0 while open

    FileReader();                   // 0x001BE2CC
    ~FileReader();                  // 0x001BE2DC
    int func_001BE524(FileReadReq *theReq, int theFlag);
};
#include "include_asm.h"

// Sets a 4-float vector (ours; DogVector::set stores in another order).
static inline void vecSet(float *theVec, float x, float y, float z, float w)
{
    theVec[0] = x;
    theVec[1] = y;
    theVec[2] = z;
    theVec[3] = w;
}

// 0x00108660
void DogActor::nextStep()
{
    getSubMode()->m_step++;
}















// 0x00108674: the pose buffers for motion theNo (two poses and a word per
// node); 0, or -1 without motions or memory.
int DogActor::allocPosture(int theNo)
{
    if (m_max_motion <= 0) {
        return -1;
    }
    if (!m_posture) {
        m_unk1C8 = get_nNode(theNo);
        int size = m_unk1C8 * sizeof(I3mPosture) * 2 + (m_unk1C8 + 1) * 2;
        m_posture = (I3mPosture *)D_006E9800.alloc(size, -1);
        if (!m_posture) {
            ASSERT(m_posture != __null);
            if (!m_posture) {
                return -1;
            }
        }
        memset(m_posture, 0, size);
        m_unk1D0 = m_posture + m_unk1C8;
        m_assign_tbl = (short *)(m_posture + m_unk1C8 * 2);
        func_0010BF08(theNo);
        m_motion_now.setMainMotion(theNo);
    }
    return 0;
}

// 0x00108814
void DogActor::freePosture()
{
    if (m_posture) {
        D_006E9800.free(m_posture);
        m_posture = 0;
    }
}
















// 0x00108850: when the last motion is missing, shrinks the table past the
// trailing missing ones.
void DogActor::allocLastMotion()
{
    ASSERT(m_max_motion > 0);
    if (m_motion_data[m_max_motion - 1].m_i3m_root == 0) {
        int i;
        for (i = m_max_motion - 2; i >= 0 && m_motion_data[i].m_i3m_root == 0; i--) {
        }
        if (i >= 0) {
            i++;
        }
        allocMotion(i);
    }
}

// 0x001088FC: the frame count of a tag record (an int, or a float's bits).
int DogActor::getTagNumFrame(const DogMotionTag *theTag)
{
    if (!theTag) {
        return 0;
    }
    int v = theTag->m_numframe;
    if (v & ~0x7FF) {
        return (int)*(float *)&v;
    }
    return v;
}

// 0x0010893C: its type, stored the same way.
int DogActor::getTagType(const DogMotionTag *theTag)
{
    if (!theTag) {
        return 0;
    }
    int v = theTag->m_type;
    if (v & ~0xFF) {
        return (int)*(float *)&v;
    }
    return v;
}
























// 0x0010897C: floats per frame for each type.
int DogActor::getTagSize(const DogMotionTag *theTag)
{
    if (!theTag) {
        return 0;
    }
    int size = 0;
    switch (getTagType(theTag)) {
    case 1:
        size = 6;
        break;
    case 2:
    case 18:
        size = 2;
        break;
    case 3:
    case 19:
        size = 3;
        break;
    case 0:
    case 4:
    case 20:
        size = 4;
        break;
    case 5:
    case 6:
    case 21:
        size = 1;
        break;
    default:
        ASSERT(0);
        break;
    }
    return size;
}







// 0x00108A14: frame theFrame of a tag record, as a vector.
void DogActor::getTagVector(const DogMotionTag *theTag, float *theOut, int theFrame)
{
    if (!theTag) {
        theOut[0] = theOut[1] = theOut[2] = 0.0f;
        theOut[3] = 1.0f;
        return;
    }
    const float *v = theTag->m_data + theFrame * getTagSize(theTag);
    switch (getTagType(theTag)) {
    case 0:
        ASSERT(0);
        break;
    case 1:
        vecSet(theOut, v[4], v[2], v[5], v[3]);
        break;
    case 2:
    case 18:
        vecSet(theOut, 0.0f, v[0], 0.0f, v[1]);
        break;
    case 3:
    case 19:
        vecSet(theOut, v[0], v[1], v[2], 0.0f);
        break;
    case 4:
    case 20:
        vecSet(theOut, v[0], v[1], v[2], v[3]);
        break;
    case 5:
    case 21:
        vecSet(theOut, 0.0f, v[0], 0.0f, 0.0f);
        break;
    case 6:
        vecSet(theOut, 0.0f, 0.0f, 0.0f, v[0]);
        break;
    default:
        ASSERT(0);
        break;
    }
}




// 0x00108BB0: frame theFrame of a tag record, as one float.
float DogActor::getTagFloat(const DogMotionTag *theTag, int theFrame)
{
    if (!theTag) {
        return 0.0f;
    }
    const float *v = theTag->m_data + theFrame * getTagSize(theTag);
    switch (getTagType(theTag)) {
    case 0:
        ASSERT(0);
        break;
    case 2:
    case 18:
        return v[1];
    case 1:
    case 4:
    case 20:
        return v[3];
    case 3:
    case 5:
    case 19:
    case 21:
        break;
    case 6:
        return v[0];
    default:



        ASSERT(0);
        break;
    }
    return 0.0f;
}




























// 0x00108C90: the main motion's aux track at frame theTime, interpolated
// between frames. Outside the track the time wraps around once and the
// track's displacement over a loop is added (loopflag -1 or 1). Returns 0
// without a track, 1, or 2 when it wrapped.
int DogActor::func_00108C90(DogVector &theResult, float theTime)
{
    const DogMotionTag *tag = getMotionAuxData(m_motion_now.getMainMotionNo());
    if (!tag) {
        theResult.set(0.0f, 0.0f, 0.0f, 0.0f);
        return 0;
    }
    int size = getTagSize(tag);
    int numframe = getTagNumFrame(tag);
    int type = getTagType(tag);
    float t = theTime;
    int loopflag = 0;
    if (t == 0.0f) {
        getTagVector(tag, (float *)&theResult, 0);
        return 1;
    }
    if (t < 0.0f) {
        loopflag = -1;
        t += numframe - 1;
    } else if (t >= numframe - 1) {
        t -= numframe - 1;
        loopflag = 1;
    }
    int fr = vu0FTOI15(t);
    int frno = fr >> 15;
    int frfr = fr & 0x7FFF;
    if (frno == numframe - 1) {
        ASSERT(frfr == 0);
        getTagVector(tag, (float *)&theResult, frno);
    } else {
        float r = frfr * (1.0f / 32768.0f);
        float r1 = 1.0f - r;
        const float *v = tag->m_data + frno * size;




        ASSERT(frno <= numframe-2);
        float work[6];
        for (int i = 0; i < size; i++) {
            work[i] = v[i] * r1 + v[i + size] * r;
        }
        const float *end = tag->m_data + (numframe - 1) * size;
        switch (type) {
        case 1:
            theResult.m_x = work[4];
            theResult.m_y = work[2];
            theResult.m_z = work[5];
            theResult.m_w = work[3];
            if (loopflag) {
                float f = loopflag;
                theResult.m_x = work[4] + (end[4] - tag->m_data[4]) * f;
                theResult.m_y = work[2] + (end[2] - tag->m_data[2]) * f;
                theResult.m_z = work[5] + (end[5] - tag->m_data[5]) * f;
                theResult.m_w = work[3] + (end[3] - tag->m_data[3]) * f;
            }
            break;
        case 2:
        case 18:
            theResult.m_x = 0.0f;
            theResult.m_y = work[0];
            theResult.m_z = 0.0f;
            theResult.m_w = work[1];
            if (loopflag) {
                float f = loopflag;
                theResult.m_y = work[0] + (end[0] - tag->m_data[0]) * f;
                theResult.m_w = work[1] + (end[1] - tag->m_data[1]) * f;
            }
            break;
        case 3:
        case 19:
            theResult.m_x = work[0];
            theResult.m_y = work[1];
            theResult.m_z = work[2];
            theResult.m_w = 0.0f;
            if (loopflag) {
                float f = loopflag;
                theResult.m_x = work[0] + (end[0] - tag->m_data[0]) * f;
                theResult.m_y = work[1] + (end[1] - tag->m_data[1]) * f;
                theResult.m_z = work[2] + (end[2] - tag->m_data[2]) * f;
            }
            break;
        case 4:
        case 20:
            theResult.m_x = work[0];
            theResult.m_y = work[1];
            theResult.m_z = work[2];
            theResult.m_w = work[3];
            if (loopflag) {

















                ASSERT(loopflag == 1);
                float dw = end[3] - tag->m_data[3];
                vecTurnY((float *)&theResult, dw);
                theResult.m_x += end[0] - tag->m_data[0];
                theResult.m_y += end[1] - tag->m_data[1];
                theResult.m_z += end[2] - tag->m_data[2];
                theResult.m_w += dw;
            }
            break;
        case 5:
        case 21:
            theResult.m_x = 0.0f;
            theResult.m_y = work[0];
            theResult.m_z = 0.0f;
            theResult.m_w = 0.0f;
            if (loopflag) {
                float f = loopflag;
                theResult.m_y = work[0] + (end[0] - tag->m_data[0]) * f;
            }
            break;
        case 6:
            theResult.m_x = 0.0f;
            theResult.m_y = 0.0f;
            theResult.m_z = 0.0f;
            theResult.m_w = work[0];
            if (loopflag) {
                float f = loopflag;
                theResult.m_w = work[0] + (end[0] - tag->m_data[0]) * f;
            }
            break;
        case 0:










            ASSERT(0);
            break;
        default:
            ASSERT(0);
            break;
        }
    }
    if (theResult.m_w < -DOG_PI) {
        theResult.m_w += DOG_PI2;
    }
    if (theResult.m_w >= DOG_PI) {
        theResult.m_w -= DOG_PI2;
    }









    ASSERT((theResult.m_w >= -DOG_PI) && (theResult.m_w < DOG_PI));
    return loopflag ? 2 : 1;
}

// 0x00109284: the last frame of the main motion's aux track.
void DogActor::func_00109284(DogVector &theResult)
{
    const DogMotionTag *tag = getMotionAuxData(m_motion_now.getMainMotionNo());
    if (!tag) {
        theResult.set(0.0f, 0.0f, 0.0f, 0.0f);
        return;
    }
    getTagVector(tag, (float *)&theResult, getTagNumFrame(tag) - 1);
}

// 0x00109348: the change of the main motion's aux track from frame theFrom
// to theTo (the height only for tracks that have it); theAbs (optional)
// gets the value at theTo and *theTurn the turn added by a loop in between.
// Returns 0 without a track, 2 when the motion looped, else 1.
int DogActor::func_00109348(float theFrom, float theTo, DogVector &theResult, float *theTurn, DogVector *theAbs)
{
    DogMotionBlend *blend = &m_motion_now;
    const DogMotionTag *tag = getMotionAuxData(blend->getMainMotionNo());
    if (tag) {
        int loop = m_motion_flag[0] & 7;
        if ((loop & 1) == 0) {
            float last = getTagNumFrame(tag) - 1;
            if (theFrom > last) {
                theFrom = last;
            }
            if (theTo > last) {
                theTo = last;
            }
        }
        DogVector from;
        func_00108C90(from, theFrom);
        func_00108C90(theResult, theTo);
        if (theAbs) {
            *theAbs = theResult;
        }
        theResult.m_x -= from.m_x;
        theResult.m_y -= from.m_y;
        theResult.m_z -= from.m_z;
        theResult.m_w -= from.m_w;
        if (!(getTagType(tag) & 0x10)) {
            theResult.m_y = 0.0f;
        } else {
            DogVector base;
            func_00108C90(base, 0.0f);
            if (theAbs) {
                theAbs->m_y = base.m_y;
            }
        }
        *theTurn = 0.0f;
        if (loop & 1) {
            float speed = blend->m_main.m_speed;
            int numframe = getTagNumFrame(tag);
            float turn = getTagFloat(tag, numframe - 1);
            if (speed > 0.0f) {
                float last = numframe - 1.0f;
                if ((theFrom < last && last <= theTo) || (theFrom >= 0.0f && theTo >= 0.0f && theTo < theFrom)) {
                    *theTurn = turn;
                    return 2;
                }
            } else if (speed < 0.0f) {
                if (theFrom >= 0.0f && theTo < 0.0f) {
                    *theTurn = -turn;
                    return 2;
                }
            }
        }
        return 1;
    }
    *theTurn = 0.0f;
    theResult.m_x = theResult.m_y = theResult.m_z = *theTurn;
    theResult.m_w = 1.0f;
    return 0;
}

// 0x00109634: the length of the main motion's aux track in frames (0
// without one); theLast (optional) gets its last frame.
int DogActor::func_00109634(float *theLast)
{
    const DogMotionTag *tag = getMotionAuxData(m_motion_now.getMainMotionNo());
    if (!tag) {
        if (theLast) {
            theLast[0] = theLast[1] = theLast[2] = 0.0f;
            theLast[3] = 1.0f;
        }
        return 0;
    }
    int numframe = getTagNumFrame(tag);
    if (theLast) {
        getTagVector(tag, theLast, numframe - 1);
    }
    return numframe;
}

// 0x00109714
void DogActor::init()
{
    DogModel::init();
    getSubMode()->m_step = -1;
    getSubMode()->m_mode = -1;
    m_id = -1;
    m_unk1A4 = 0;
    m_unk1BC = 0;
    m_max_motion = 0;
    m_motion_data = 0;
    m_flag_motion_data = -1;
    m_posture = 0;
    m_assign_tbl = 0;
    m_interpolation = 0;
    m_motion_now.setMotionTable(0, 0);
    m_motion_old.setMotionTable(0, 0);
    m_control_node = -1;
    m_control_node_flg = 0;
    func_0010EC50();
    m_trans_ofs_y_save = m_rot_ofs_y = 0.0f;
    m_motion_flag[1] = -1;
    int i;
    for (i = 0; i < 4; i++) {
        m_pack_motion[i] = 0;
    }
    m_motion_cmd_idx = -1;
    for (i = 0; i < 8; i++) {
        m_unk42C[i] = -1;
    }
    m_rot_y_aar = 0.0f;
    m_unk454 = 0;
    m_unk4B0[0] = m_unk4B0[1] = m_unk4B0[2] = m_unk4B0[3] = 1.0f;
    m_unk4A0[0] = m_unk4A0[1] = m_unk4A0[2] = m_unk4A0[3] = m_rot_y_aar;
    m_unk4C0 = 0.1f;
    m_unk4C4 = 1;
    m_unk4C5 = 1;
}













































































































// 0x00109860: resizes the motion table to theN entries (new ones empty).
void DogActor::allocMotion(int theN)
{
    int i;
    ASSERT(theN >= 0);
    if (m_max_motion < theN) {
        DogMotionData *p = (DogMotionData *)D_006E9800.alloc(theN * sizeof(DogMotionData), -1);






        ASSERT(p);
        if (m_motion_data) {



            ASSERT(m_max_motion != 0);
            memcpy(p, m_motion_data, m_max_motion * sizeof(DogMotionData));
            D_006E9800.free(m_motion_data);
            m_motion_data = 0;
        }
        for (i = m_max_motion; i < theN; i++) {
            p[i].m_i3m_root = 0;
            p[i].m_aux_data = 0;
            p[i].m_unk18 = -1;
            p[i].m_unk14 = -1;
            p[i].m_unk1C = 0;
        }
        m_motion_data = p;
        m_max_motion = theN;
    } else if (theN < m_max_motion) {











        ASSERT(m_motion_data);
        for (i = theN; i < m_max_motion; i++) {
            if (m_flag_motion_data == FLAG_MOTION_EACH && m_motion_data[i].m_i3m_root) {
                D_006E9800.free(m_motion_data[i].m_i3m_root);
            }
            m_motion_data[i].m_i3m_root = 0;
            m_motion_data[i].m_aux_data = 0;
            m_motion_data[i].m_unk18 = -1;
            m_motion_data[i].m_unk14 = -1;
            m_motion_data[i].m_unk1C = 0;
        }
        if (theN > 0) {
            DogMotionData *p = (DogMotionData *)D_006E9800.alloc(theN * sizeof(DogMotionData), -1);








            ASSERT(p);
            memcpy(p, m_motion_data, theN * sizeof(DogMotionData));
            D_006E9800.free(m_motion_data);
            m_motion_data = p;
        } else {
            m_flag_motion_data = -1;
            D_006E9800.free(m_motion_data);
            m_motion_data = 0;
        }
        m_max_motion = theN;
    } else {
        return;
    }
    m_motion_now.setMotionTable(m_motion_data, m_max_motion);
    m_motion_old.setMotionTable(m_motion_data, m_max_motion);











    ASSERT(m_max_motion > 0);
}

// 0x00109B48: frees the motion table.
void DogActor::func_00109B48()
{
    if (m_motion_data) {
        D_006E9800.free(m_motion_data);
        m_motion_data = 0;
    }
    m_max_motion = 0;
}


































// 0x00109B88: unloads the motions of group theId (1-3) and stops whatever
// played them.
void DogActor::func_00109B88(int theId)
{
    if (theId > 0) {
        ASSERT(theId >= 0 && theId < (4));
        if (m_flag_motion_data == FLAG_MOTION_EACH) {
            for (int i = m_max_motion - 1; i >= 0; i--) {
                DogMotionData *pm = &m_motion_data[i];
                if (pm->m_unk18 == theId) {





                    ASSERT(pm->m_i3m_root);
                    D_006E9800.free(pm->m_i3m_root);
                    pm->m_i3m_root = 0;
                    pm->m_unk1C = 0;
                    pm->m_unk14 = -1;
                    pm->m_unk18 = -1;
                }
            }
        } else if (m_flag_motion_data == FLAG_MOTION_PACK && m_pack_motion[theId]) {
            for (int i = m_max_motion - 1; i >= 0; i--) {
                DogMotionData *pm = &m_motion_data[i];
                if (pm->m_unk18 == theId) {









                    ASSERT(pm->m_i3m_root);
                    pm->m_unk1C = 0;
                    pm->m_i3m_root = 0;
                    pm->m_unk14 = -1;
                    pm->m_unk18 = -1;
                }
            }
            D_006E9800.free(m_pack_motion[theId]);
            m_pack_motion[theId] = 0;
            if (!m_motion_data[m_motion_now.getMainMotionNo()].m_i3m_root) {
                m_motion_now.setMainMotionNo(-1);
            }
            for (int n = 0; n < 4; n++) {
                int no = getMotionNoSub(n);
                if (no > 0 && !m_motion_data[no].m_i3m_root) {
                    m_motion_now.setSubMotionNo(n, -1);
                }
            }
        }
        if (m_max_motion > 0 && !m_motion_data[m_max_motion - 1].m_i3m_root) {
            allocLastMotion();
        }
    }
}

// 0x00109DEC: unloads the current motion group.
void DogActor::func_00109DEC()
{
    if (m_unk1BC > 0) {
        func_00109B88(m_unk1BC);
        m_unk1BC = -1;
    }
}

// 0x00109E28: frees all motions, buffers and the model's own data.
void DogActor::func_00109E28(int theAll)
{
    for (int i = 0; i < 4; i++) {
        func_00109B88(i);
    }
    if (m_motion_data) {
        D_006E9800.free(m_motion_data);
        m_motion_data = 0;
    }
    if (m_posture) {
        D_006E9800.free(m_posture);
        m_posture = 0;
    }
    DogModel::vfunc06(1);
    if (m_unk1A4) {
        D_006E9800.free(m_unk1A4);
        m_unk1A4 = 0;
    }
}












































































































// 0x00109ED0: releases the model. A copy releases its own buffers and
// drops a reference to its original; an original is freed when the last
// reference goes (until then only marked).
void DogActor::release(int theAll)
{
    if (m_original) {
        for (int i = 1; i < 4; i++) {
            ASSERT(m_pack_motion[i] == __null);
        }
        ((DogActor *)m_original)->func_00109FB4(theAll);
        func_00109B48();
        freePosture();
        func_001154CC();
    } else {
        if (decRefCount() > 0) {
            m_unk140 = 1;
            return;
        }
        func_00109E28(theAll);
    }
    init();
}
































// 0x00109FB4: drops a reference to this original; frees it with the last.
void DogActor::func_00109FB4(int theAll)
{
    ASSERT(m_original == __null);
    if (decRefCount() <= 0) {
        func_00109E28(theAll);
        init();
    }
}

// 0x0010A038: moves the model by theMove and sets its rotation.
void DogActor::func_0010A038(const DogVector &theMove, float theRot, float theAar)
{
    DogVector *pos = &m_unk40;
    pos->m_x += theMove.m_x;
    pos->m_y += theMove.m_y;
    pos->m_z += theMove.m_z;
    pos->m_w = 1.0f;
    m_unk70.m_y = theRot;
    m_unk70.m_w = 1.0f;
    m_unk90 = 1;
    m_rot_y_aar = theAar;
}

// Brings theAngle into [-DOG_PI, DOG_PI) (once).
static inline void angleNormalize(float &theAngle)
{
    if (theAngle < -DOG_PI) {
        theAngle += DOG_PI2;
    } else if (theAngle >= DOG_PI) {
        theAngle -= DOG_PI2;
    }
}

// 0x0010A090: moves the model by theMove and turns it to theAar, minus the
// aux track's turn at the current frame.
void DogActor::func_0010A090(const DogVector &theMove, float theRot, float theAar)
{
    DogVector *pos = &m_unk40;
    pos->m_x += theMove.m_x;
    pos->m_y += theMove.m_y;
    pos->m_z += theMove.m_z;
    pos->m_w = 1.0f;
    m_unk70.m_y = theRot;
    m_unk70.m_w = 1.0f;
    m_unk90 = 1;
    DogVector aux;
    func_00108C90(aux, func_0010DA4C() * 2.0f);
    float rot = theAar - aux.m_w;
    angleNormalize(rot);
    m_unk50.m_y = rot;
    normalizeRot();
    m_unk90 = 1;
    m_base_rot.m_y = rot;
    setRotOffsetY(0.0f);
}

// 0x0010A1C8: func_0010A090 with a position instead of a move.
void DogActor::func_0010A1C8(const DogVector &thePos, float theRot, float theAar)
{
    m_unk40 = thePos;
    m_unk70.m_y = theRot;
    m_unk70.m_w = 1.0f;
    m_unk90 = 1;
    DogVector aux;
    func_00108C90(aux, func_0010DA4C() * 2.0f);
    float rot = theAar - aux.m_w;
    angleNormalize(rot);
    m_unk50.m_y = rot;
    normalizeRot();
    m_unk90 = 1;
    m_base_rot.m_y = rot;
    setRotOffsetY(0.0f);
}

// 0x0010A2D0: the model's position and rotation with the main motion's aux
// track applied at the current frame.
void DogActor::func_0010A2D0(DogVector &thePos, DogVector &theRot)
{
    const DogMotionTag *tag = getMotionAuxData(m_motion_now.getMainMotionNo());
    if (tag) {
        float t = func_0010DA4C() * 2.0f;
        if (t >= 0.0f) {
            func_00108C90(thePos, t);
            DogVector base = m_base_rot;
            theRot.set(0.0f + base.m_x, thePos.m_w + base.m_y, 0.0f + base.m_z, 1.0f);
            if (theRot.m_y <= -DOG_PI) {
                theRot.m_y += DOG_PI2;
            } else if (theRot.m_y > DOG_PI) {
                theRot.m_y -= DOG_PI2;
            }
            thePos = m_unk40;
        } else {
            thePos = m_unk3B0;
            theRot = m_base_rot;
        }
    } else {
        thePos = m_unk40;
        theRot = m_unk50;
    }
}

// 0x0010A448: the model's rotation with the aux track's turn at the current
// frame.
void DogActor::func_0010A448(DogVector &theRot)
{
    const DogMotionTag *tag = getMotionAuxData(m_motion_now.getMainMotionNo());
    if (tag) {
        theRot = m_base_rot;
        float t = func_0010DA4C() * 2.0f;
        if (t >= 0.0f) {
            DogVector aux;
            func_00108C90(aux, t);
            theRot.m_y += aux.m_w;
            if (theRot.m_y < -DOG_PI) {
                theRot.m_y += DOG_PI2;
            }
            if (theRot.m_y >= DOG_PI) {
                theRot.m_y -= DOG_PI2;
            }
        }
    } else {
        theRot = m_unk50;
    }
}










































































































































// 0x0010A584: the turn of the main motion's aux track at the current frame.
float DogActor::func_0010A584()
{
    if (func_0010DB38()) {
        return -m_rot_offset.m_y;
    }
    float t = func_0010DA4C() * 2.0f;
    if (t >= 0.0f) {
        DogVector v;
        func_00108C90(v, t);
        ASSERT((v.m_w >= -DOG_PI) && (v.m_w < DOG_PI));
        return v.m_w;
    }
    return 0.0f;
}










// 0x0010A650: the model's current rotation around y.
float DogActor::func_0010A650()
{
    if (func_0010DB38()) {
        return m_unk50.m_y;
    }
    float rot;
    const DogMotionTag *tag = getMotionAuxData(m_motion_now.getMainMotionNo());
    if (tag) {
        rot = m_base_rot.m_y + m_rot_offset.m_y;
        ASSERT((m_base_rot.m_y >= -DOG_PI) && (m_base_rot.m_y < DOG_PI));
        ASSERT((m_rot_offset.m_y >= -DOG_PI) && (m_rot_offset.m_y < DOG_PI));
        if (rot < -DOG_PI) {
            rot += DOG_PI2;
        } else if (rot >= DOG_PI) {
            rot -= DOG_PI2;
        }
        rot += func_0010A584();
    } else {
        rot = m_unk50.m_y;
    }
    if (rot < -DOG_PI) {
        rot += DOG_PI2;
    } else if (rot >= DOG_PI) {
        rot -= DOG_PI2;
    }
    return rot;
}

// 0x0010A834: is a sub mode set?
int DogActor::func_0010A834()
{
    return getSubMode()->m_mode != 0;
}

// 0x0010A840: walks the motion table and does nothing (a debug dump, emptied).
void DogActor::func_0010A840()
{
    int n = m_max_motion;
    for (int i = 0; i < n; i++) {
    }
}

// 0x0010A874: the motion with id theId, or -1.
int DogActor::func_0010A874(int theId)
{
    for (int i = 0; i < m_max_motion; i++) {
        if (m_motion_data[i].m_unk14 == theId) {
            return i;
        }
    }
    return -1;
}














































// 0x0010A8B8: the motion named theName (after the prefix up to '_', any
// case; the name may go on with '+', '*' or "__"), or -1.
int DogActor::func_0010A8B8(const char *theName)
{
    ASSERT(theName);
    for (int i = 0; i < m_max_motion; i++) {
        const char *p = m_motion_data[i].m_unk1C;
        if (!p) {
            continue;
        }
        while (*p != '_') {
            if (*p == '\0') {
                goto notfound;
            }
            p++;
        }
        p++;
        const char *q = theName;
        while (toupper(*q) == toupper(*p)) {
            q++;
            p++;
            if (*q == '\0') {
                break;
            }
        }
        if (*q != '\0') {
            continue;
        }
        if (*p == '\0' || *p == '+' || *p == '*' || (*p == '_' && p[1] == '_')) {
            return i;
        }
    }
notfound:
    return -1;
}

// 0x0010AA5C: the id of the motion named theName (as func_0010A8B8), or -1.
int DogActor::func_0010AA5C(const char *theName)
{
    int no = func_0010A8B8(theName);
    if (no < 0) {
        return -1;
    }
    return m_motion_data[no].m_unk14;
}




























// 0x0010AA9C: the motion whose full name is theName, or -1.
int DogActor::func_0010AA9C(const char *theName)
{
    ASSERT(theName);
    for (int i = 0; i < m_max_motion; i++) {
        if (m_motion_data[i].m_unk1C && strcmp(m_motion_data[i].m_unk1C, theName) == 0) {
            return i;
        }
    }
    return -1;
}













// 0x0010AB40: the id of the motion whose full name is theName, or -1.
int DogActor::func_0010AB40(const char *theName)
{
    ASSERT(theName);
    for (int i = 0; i < m_max_motion; i++) {
        if (m_motion_data[i].m_unk1C && strcmp(m_motion_data[i].m_unk1C, theName) == 0) {
            return m_motion_data[i].m_unk14;
        }
    }
    return -1;
}













// 0x0010ABF4: sets the motion command list.
void DogActor::func_0010ABF4(const int *theCmd, int theLength)
{
    ASSERT(theCmd);
    ASSERT(theLength > 0 && theLength <= DOG_MAX_MOTION_CMD);
    for (int i = 0; i < theLength; i++) {
        m_unk42C[i] = theCmd[i];
    }
    m_motion_cmd_idx = 0;
}

// 0x0010AC98: takes the current motion's offsets into the model's base
// position and rotation.
void DogActor::func_0010AC98()
{
    func_0010E930();
    m_unk50.m_y = func_0010A650();
    normalizeRot();
    m_unk90 = 1;
    m_rot_offset.set(0.0f, 0.0f, 0.0f, 1.0f);
    m_unk90 = 1;
    func_0010A2D0(m_unk3B0, m_base_rot);
}

















// 0x0010AD0C: sets the interpolation time for motion theN: theFrame, or
// the motion's link time when negative.
void DogActor::func_0010AD0C(int theN, int theFrame)
{
    ASSERT(m_max_motion > 0);
    ASSERT(theN >= 0 && theN < m_max_motion);
    int frame;
    if (theFrame >= 0) {
        frame = theFrame;
    } else {
        int *link = m_motion_now.getLinkData(theN);
        frame = link ? *link : 0;
    }
    func_0010BF00(frame);
}

// 0x0010AE10: puts the main motion at its start, or at its end (motion
// theID's length) when m_motion_speed0 is negative.
void DogActor::func_0010AE10(int theID)
{
    if (m_motion_speed0 >= 0.0f) {
        m_motion_now.setMainTime(0.0f);
    } else {
        m_motion_now.setMainTime(func_0010D0E8(theID));
    }
}

// 0x0010AE58: restarts the sub mode for a new motion (bit 1: interpolated,
// bit 0: at once or with flag 0x40; bit 3 is kept).
void DogActor::func_0010AE58()
{
    int mode = getSubMode()->m_mode & 8;
    if (m_interpolation > 0) {
        mode |= 2;
        if (m_motion_flag[0] & 0x40) {
            mode |= 1;
        }
    } else {
        mode |= 1;
    }
    mode |= 4;
    getSubMode()->m_step = 0;
    getSubMode()->m_mode = mode;
}





































// 0x0010AE90: makes motion theN the main one.
void DogActor::func_0010AE90(int theN, int theUnused)
{
    ASSERT(m_max_motion > 0);
    ASSERT(theN >= 0 && theN < m_max_motion);
    m_motion_now.m_main.m_no = theN;
    func_0010AE58();
}

// 0x0010AF18: plays the motion with id theID as the main one, at theSpeed
// frames per tick (flag 0x80 or a negative speed: from its end). Unless
// the sub mode keeps it (bit 2), the old motion is saved for blending and
// the model takes the motion's start offset. theInterp < 0: the motion's
// own link time. Returns the motion's index, or -1.
int DogActor::func_0010AF18(int theID, int theFlag, float theSpeed, int theLoop, int theInterp)
{
    ASSERT(m_max_motion > 0);
    int mode = getSubMode()->m_mode;
    int no = func_0010A874(theID);
    if (no >= 0 && no < m_max_motion) {
        if (m_motion_data[no].m_i3m_root) {
            int keep = mode & 4;
            if (!keep) {
                func_0010EDEC();
            }
            m_motion_now.setMain(no, theSpeed);
            if ((theFlag & 0x80) || theSpeed < 0.0f) {
                m_motion_now.setMainTime(func_0010D0E8(no));
            }
            if (theInterp >= 0) {
                func_0010BF00(theInterp);
            } else {
                int *link = m_motion_now.getLinkData(no);
                if (link) {
                    func_0010BF00(*link);
                }
            }
            if (!keep && m_interpolation <= 0) {
                DogVector aux;
                func_00108C90(aux, 0.0f);
                m_unk70.m_w = 1.0f;
                m_unk70.m_y = aux.m_y;
                m_unk90 = 1;
            }
            int flag = theFlag;
            if (m_motion_now.getUnk10(no) && m_interpolation > 0) {
                flag |= 0x40;
            }
            m_motion_flag[0] = flag;
            m_motion_flag[1] = theLoop;
            func_0010AE58();
            return no;
        }
    }
    return -1;
}





















































// 0x0010B1B0: plays motion theNo (an id, as func_0010AF18) unless, with
// flag 4, it or theNext already plays: then only the speed changes and it
// returns -1. Otherwise the model first takes the old motion's offsets.
int DogActor::func_0010B1B0(int theNo, float theSpeed, int theFlag, int theNext, int theInterp)
{
    ASSERT(theNo >= 0);
    if (theFlag & 4) {
        int no = func_0010A874(theNo);
        if (m_motion_now.getMainMotionNo() == no) {
            m_motion_now.setMainSpeed(theSpeed);
            return -1;
        }
        if (theNext >= 0) {
            no = func_0010A874(theNext);
            if (m_motion_now.getMainMotionNo() == no) {
                m_motion_now.setMainSpeed(theSpeed);
                return -1;
            }
        }
    }
    if (!(getSubMode()->m_mode & 4)) {
        func_0010E930();
        float rot = func_0010A650();
        m_unk50.m_y = rot;
        normalizeRot();
        m_unk90 = 1;
        func_0010ED2C(rot);
        setRotOffset(0.0f, 0.0f, 0.0f);
    }
    func_0010AF18(theNo, theFlag, theSpeed, -1, theInterp);
    m_motion_flag[1] = theNext;
    return theNo;
}




















































// 0x0010B328: plays the motion with id theID as sub motion theSub over the
// nodes named in theNodes (null-terminated); their pose is copied as the
// blend start. theID < 0 stops the sub motion. Returns the motion's index,
// -1 when stopped, -2 without such a motion, -3 when it is not loaded.
int DogActor::func_0010B328(int theSub, int theID, const char **theNodes)
{
    if (theID < 0) {
        m_motion_now.setSubMotion(theSub, -1);
        return -1;
    }
    int n = func_0010A874(theID);
    if (n < 0 || n >= m_max_motion) {
        return -2;
    }
    if (!m_motion_data[n].m_i3m_root) {
        return -3;
    }
    for (int i = 0; i < 4; i++) {
        m_motion_now.m_sub[theSub].m_mask[i] = 0;
    }
    for (const char **p = theNodes; *p; p++) {
        int i = i3mGetNodeIndexByName(n, *p);
        ASSERT(i >= 0);
        m_motion_now.m_sub[theSub].m_mask[i / 32] |= 1 << i;
        m_unk1D0[i] = m_posture[i];
    }
    m_motion_now.setSubMotion(theSub, n);
    return n;
}






























// 0x0010B620: func_0010B328 with the motion named theName (as
// func_0010A8B8); a null name stops the sub motion.
int DogActor::func_0010B620(int theSub, const char *theName, const char **theNodes)
{
    if (!theName) {
        m_motion_now.setSubMotion(theSub, -1);
        return -1;
    }
    int n = func_0010A8B8(theName);
    if (n < 0 || n >= m_max_motion) {
        return -2;
    }
    if (!m_motion_data[n].m_i3m_root) {
        return -3;
    }
    for (int i = 0; i < 4; i++) {
        m_motion_now.m_sub[theSub].m_mask[i] = 0;
    }
    for (const char **p = theNodes; *p; p++) {
        int i = i3mGetNodeIndexByName(n, *p);
        ASSERT(i >= 0);
        m_motion_now.m_sub[theSub].m_mask[i / 32] |= 1 << i;
        m_unk1D0[i] = m_posture[i];
    }
    m_motion_now.setSubMotion(theSub, n);
    return n;
}

// 0x0010B918: puts sub motion n at theRatio of its length.
void DogActor::func_0010B918(int n, float theRatio)
{
    float t = getMaxTime0(getMotionNoSub(n));
    m_motion_now.setSubRatio(n, theRatio, t * theRatio);
}
















// 0x0010BA20: where sub motion theS stops, as a ratio of its length.
void DogActor::func_0010BA20(int theS, float theR)
{
    ASSERT(theS >= 0);
    ASSERT(theR >= 0.0f && theR <= 1.0f);
    m_motion_now.m_sub[theS].m_ratio = theR;
}



// 0x0010BAC4: DogMotionBlend::setSub for sub motion theS.
void DogActor::func_0010BAC4(int theS, float theR, int theTime)
{
    ASSERT(theS >= 0);
    ASSERT(theR >= 0.0f && theR <= 1.0f);
    ASSERT(theTime >= 0.0f && theTime <= 1000);
    m_motion_now.setSub(theS, theR, theTime);
}

// 0x0010BBAC: how far sub motion n has played, as a ratio of its length.
float DogActor::func_0010BBAC(int n)
{
    float len = getMaxTime0(getMotionNoSub(n));
    if (len <= 0.0f) {
        return 0.0f;
    }
    float t = m_motion_now.m_sub[n].m_time;
    if (t <= 0.0f) {
        return 0.0f;
    }
    return t / len;
}

// 0x0010BCC8: the event bits of motion theID (an index when above 0xFFFF,
// the main motion when negative) on the frames after theFrom up to theTo,
// wrapping around the end; 0 outside the motion.
int DogActor::func_0010BCC8(int theID, float theFrom, float theTo)
{
    int no;
    if (theID < 0) {
        no = m_motion_now.getMainMotionNo();
    } else if (theID <= 0xFFFF) {
        no = func_0010A874(theID);
    } else {
        no = theID;
    }
    const DogMotionEvents *tag = getMotionTagData(no);
    if (!tag) {
        return 0;
    }
    int from = vu0FTOI15(theFrom) >> 15;
    int numframe = tag->m_numframe & 0x7FFFFFFF;
    if (from < 0 || from >= numframe) {
        return 0;
    }
    int to = vu0FTOI15(theTo) >> 15;
    if (to < 0 || to >= numframe) {
        return 0;
    }
    if (from == to) {
        return 0;
    }
    int bits = 0;
    int i = from;
    do {
        i++;
        if (i >= numframe) {
            i -= numframe;
        }
        bits |= tag->m_bits[i];
    } while (i != to);
    return bits;
}

// 0x0010BE1C: the main motion's event bits on the current frame.
int DogActor::func_0010BE1C()
{
    float t = func_0010DA4C();
    if (t >= 0.0f) {
        return func_0010BCC8(-1, t, t + 1.0f);
    }
    return 0;
}

void func_0010BE78(void) {
}

// 0x0010BE80: advances the motions (DogMotionBlend::update) when a main
// motion plays; 0 otherwise.
int DogActor::func_0010BE80(float theUnused)
{
    if (m_max_motion <= 0 || m_motion_now.getMainMotionNo() < 0) {
        return 0;
    }
    return m_motion_now.update();
}

// 0x0010BED0: DogMotionBlend::updateOnce when there are motions.
int DogActor::func_0010BED0(float theUnused)
{
    if (m_max_motion <= 0) {
        return 0;
    }
    return m_motion_now.updateOnce();
}

// 0x0010BF00
void DogActor::func_0010BF00(int theFrame)
{
    m_interpolation = theFrame;
}
































































// 0x0010BF08: fills m_assign_tbl for motion theNo: its node count, then the
// model node of each motion node (-1 if the model has none by that name).
// Returns the number of nodes not found.
int DogActor::func_0010BF08(int theNo)
{
    int num = get_nNode(theNo);
    ASSERT(m_assign_tbl);
    short *p = m_assign_tbl;
    int err = 0;
    *p++ = num;
    for (int i = 0; i < num; i++) {
        int node = getNodeIndexByName(getNodeName(theNo, i));
        if (node >= 0) {
            *p++ = node;
        } else {
            *p++ = -1;
            err++;
        }
    }
    return err;
}























// 0x0010C17C: reads file theIndex of the pack file theFileName and adds its
// motions (func_0010C568) as pack theLevel (the first free one when
// negative); a copy has its original load them and copies the table.
// Returns the pack's index, or -1.
int DogActor::func_0010C17C(const char *theFileName, int theIndex, int theLevel)
{
    char work[0x800 + 0x40];
    DogActor *org = (DogActor *)m_original;
    if (org) {
        theLevel = org->func_0010C17C(theFileName, theIndex, theLevel);
        int n = org->m_max_motion;
        ASSERT(n>=0);
        allocMotion(n);
        if (org->m_motion_data && n > 0) {
            memcpy(m_motion_data, org->m_motion_data, n * sizeof(DogMotionData));
        }
        return theLevel;
    }








    ASSERT(theFileName);
    int lev;
    if (theLevel >= 0) {
        if (m_pack_motion[theLevel]) {
            func_00109B88(theLevel);





            ASSERT(m_pack_motion[theLevel] == __null);
        }
        lev = theLevel;
    } else {
        int i;
        for (i = 0; i < DOG_MAX_PACK_MOTION; i++) {
            if (!m_pack_motion[i]) {
                break;
            }
        }
        lev = i;
    }
    if (lev < 0 || lev >= DOG_MAX_PACK_MOTION) {
        return -1;
    }








    ASSERT(m_pack_motion[lev] == __null);
    FileReader reader;
    FileReadReq req;
    req.m_unk08 = 1;
    req.m_name = theFileName;
    req.m_buf = (void *)(((int)work / 64 + 1) * 64);
    req.m_size = 0x800;
    reader.func_001BE524(&req, 0);
    BedPfh pfh1(req.m_buf);










    ASSERT(pfh1.getFileOffset(0) == (2048));

    ASSERT(theIndex >= 0 && theIndex < pfh1.getNumFile());
    int size = pfh1.getFileSize(theIndex);
    if (size <= 0) {



        ASSERT(0);
        return -1;
    }
    int bytes = (size + 2047) / 2048 * 2048;

    void *p = D_006E9800.alloc(bytes, __FILE__, __LINE__, 0, 1);
    ASSERT(p != __null);
    ASSERT((((int)p)%64)==0);
    req.m_offset = pfh1.getFileOffset(theIndex);
    req.m_unk14 = 0;
    req.m_buf = p;
    req.m_size = bytes;
    req.m_unk20 = 1;
    reader.func_001BE524(&req, 0);
    BedPfh pfh2(p);
    if (func_0010C568(&pfh2, lev) < 0) {
        D_006E9800.free(p);
        return -1;
    }
    return lev;
}

















// 0x0010C568: adds the motions of a motion pack (thePfh) after the current
// ones, as pack theIndex (the first free one when theIndex is out of
// range). Each file is a motion, or a pack of motion, link table, aux track
// and events. Returns the pack's index; -100 for a copy, -1 or -3 on
// failure.
int DogActor::func_0010C568(BedPfh *thePfh, int theIndex)
{
    if (m_original) {
        return -100;
    }
    ASSERT(theIndex < (4));
    int i;
    int index;
    if (theIndex >= 0 && theIndex < DOG_MAX_PACK_MOTION) {
        index = theIndex;
    } else {
        for (i = 0; i < DOG_MAX_PACK_MOTION; i++) {
            if (!m_pack_motion[i]) {
                break;
            }
        }
        index = i;
    }
    if (index < 0 || index >= DOG_MAX_PACK_MOTION) {
        return -1;
    }















    ASSERT(m_pack_motion[index] == __null);
    int num = thePfh->getNumFile();
    if (num == 0) {
        return 0;
    }



    ASSERT(num > 0);
    int base = m_max_motion;
    allocMotion(base + num);




    ASSERT(m_flag_motion_data != FLAG_MOTION_EACH);
    m_flag_motion_data = FLAG_MOTION_PACK;
    m_pack_motion[0] = 0;
    m_pack_motion[index] = thePfh->m_top;
    if (thePfh->getFlags() & BEDPFH_USER_DATA) {
        for (i = 0; i < num; i++) {
            int id = thePfh->getUserData(i) & 0xFFF;
            m_motion_data[base + i].m_unk14 = id;
            m_motion_data[base + i].m_unk10 = id;
            m_motion_data[base + i].m_unk18 = index;
        }
    } else {
        for (i = 0; i < num; i++) {
            m_motion_data[base + i].m_unk14 = base + i;
            m_motion_data[base + i].m_unk18 = index;
        }
    }
    char *name = thePfh->m_name;
    for (i = 0; i < num; i++) {
        int m = i + base;
        m_motion_data[m].m_aux_data = 0;
        m_motion_data[m].m_tag_data = 0;
        m_motion_data[m].m_unk04 = 0;
        m_motion_data[m].m_unk10 = 0;
        m_motion_data[m].m_unk1C = name;
        if (name) {
            while (*name) {
                name++;
            }
            name++;
        }
        char *file = (char *)thePfh->getFileTop(i);
        if (*(int *)file == BEDPFH_ID) {
            BedPfh pfh(file);
            m_motion_data[m].m_i3m_root = pfh.getFileTop(0);
            int *link = (int *)pfh.getFileTop(1);
            m_motion_data[m].m_unk10 = *link;
            m_motion_data[m].m_unk04 = link + 1;
            if (pfh.getNumFile() >= 3) {
                if (pfh.getFileSize(2) > 0) {
                    m_motion_data[m].m_aux_data = (DogMotionTag *)pfh.getFileTop(2);
                }
                if (pfh.getNumFile() >= 4) {
                    if (pfh.getFileSize(3) > 0) {
                        m_motion_data[m].m_tag_data = (DogMotionEvents *)pfh.getFileTop(3);
                    }
                }
            }
        } else {
            m_motion_data[m].m_i3m_root = file;
            int *head = (int *)m_motion_data[m].m_i3m_root;
            if (head[3] != thePfh->getFileSize(i)) {
                char *aux = (char *)head + head[3];
                m_motion_data[m].m_aux_data = (DogMotionTag *)aux;
                int size = getTagNumFrame(m_motion_data[m].m_aux_data) * getTagSize(m_motion_data[m].m_aux_data) + 0x10;
                if (size + head[3] > thePfh->getFileSize(i)) {
                    m_motion_data[m].m_tag_data = (DogMotionEvents *)(aux + size);


























































                    ASSERT(m_motion_data[m].m_tag_data->m_numframe & 0x80000000);
                }
            }
        }
        if (unpack(m)) {
            return -1;
        }
        if (allocPosture(m) < 0) {
            return -3;
        }
    }
    return index;
}















































// 0x0010CD5C: sets the actor up from a pack (thePfh; a copy of it when
// theMode is 2, kept in m_unk1A4 when theMode > 0): its first file is the
// model (vfunc14), its second, if any, the motions (func_0010C568).
int DogActor::func_0010CD5C(BedPfh *thePfh, void *theTex, int theMode, int theFlag)
{
    reset();
    void *top;
    if (theMode == 2) {
        top = D_006E9800.alloc(thePfh->getSize(), __FILE__, __LINE__, 0, 1);
        memcpy(top, thePfh->m_top, thePfh->getSize());
    } else {
        top = thePfh->m_top;
    }
    BedPfh pfh;
    pfh.setTop(top);
    if (theMode > 0) {
        m_unk1A4 = top;
    }
    BedPfh model(pfh.getFileTop(0));
    pfh.getName(0);
    int rrr = vfunc14(theTex, &model, theFlag, 1);

















    ASSERT(rrr>=0);
    func_0011533C();
    if (pfh.getNumFile() >= 2) {
        BedPfh motion(pfh.getFileTop(1));
        func_0010C568(&motion, -1);
    }
    return 0;
}












































































// 0x0010CFFC: makes this actor a copy of theSrc, sharing its original's
// model and motions.
int DogActor::vfunc21(DogActor *theSrc)
{
    init();
    int n = theSrc->m_max_motion;
    ASSERT(n>=0);
    allocMotion(n);
    DogActor *orig = theSrc->m_original ? (DogActor *)theSrc->m_original : theSrc;
    m_unk110 = 3;
    m_original = orig;
    m_id = theSrc->m_id;
    m_i3r_root = orig->m_i3r_root;
    func_0011533C();
    if (orig->m_motion_data && n > 0) {
        memcpy(m_motion_data, orig->m_motion_data, n * sizeof(DogMotionData));
        allocPosture(0);
    }
    orig->incRefCount();
    ready();
    return 0;
}














































// 0x0010D0E8: the length in frames of the motion with id theID.
float DogActor::func_0010D0E8(int theID)
{
    ASSERT(theID >= 0);
    ASSERT(m_motion_data);
    int n = func_0010A874(theID);


    ASSERT(n>=0 && n < m_max_motion);
    ASSERT(m_motion_data[n].m_i3m_root);
    return func_0022E958(m_motion_data[n].m_i3m_root);
}

// 0x0010D1D0: plays the motion with id theID. Flag 1: not if it already
// plays (-1); flag 4: from the current frame (flag 8: scaled to the
// motion's length).
int DogActor::func_0010D1D0(int theID, int theFlag)
{
    ASSERT(theID >= 0);
    int no = func_0010A874(theID);
    int same = (theFlag & 1) && m_motion_now.getMainMotionNo() == no;
    if (same) {
        return -1;
    }
    float t = 0.0f;
    if (theFlag & 4) {
        float now = func_0010D9EC();
        if (now < t) {
            now = t;
        }
        float len = getMaxTime0(no);
        float newlen = func_0010D0E8(theID);
        if (theFlag & 8) {
            t = now * newlen / len;
        } else {
            t = now;
            if (newlen < t) {
                t = newlen;
            }
        }
    }
    func_0010B1B0(theID, 0.016666694f, 0, -1, -1);
    if (t != 0.0f) {
        m_motion_now.m_main.m_time = t;
    }
    m_unk450 = 1;
    return theID;
}






















// 0x0010D388: runs the motion commands (m_unk42C from m_motion_cmd_idx),
// or else the main motion's end (m_motion_flag); then the blend-in offsets
// and the eyes.
void DogActor::func_0010D388()
{
    if (m_motion_cmd_idx >= 0) {
        ASSERT(m_motion_cmd_idx < DOG_MAX_MOTION_CMD);
        int loop = 1;
        while (loop) {
            int wait = 0;
            int cmd = m_unk42C[m_motion_cmd_idx];
            int op = (cmd >> 28) & 0xF;
            int flags = (cmd >> 22) & 0x3F;
            int p = (cmd >> 12) & 0x3FF;
            int op1 = cmd & 0x3FF;
            if (flags & 1) {
                if (func_0010A874(op1) == m_motion_now.getMainMotionNo()) {
                }
            }
            switch (op) {
            case 1:


















                ASSERT(op1 < DOG_MAX_MOTION_CMD);
                m_motion_cmd_idx = op1;
                m_unk450 = 0;
                break;
            case 2:
                if (!m_unk450 && func_0010D1D0(op1, flags) < 0) {
                    goto next;
                }
                wait = 1;
                break;
            case 3:
                if (!m_unk450 && func_0010D1D0(op1, flags) < 0) {
                    goto next;
                }
                wait = 2;
                break;
            case 4:
                if (!m_unk450) {
                    if (func_0010423C(0, 1000) >= p || func_0010D1D0(op1, flags) < 0) {
                        goto next;
                    }
                }
                if (m_unk450 == 1) {
                    wait = 1;
                }
                break;
            case 8:
            case 9:
                break;
            default:
                wait = 0;
                break;
            }
            if (wait == 1) {
                loop = 0;
                if ((m_motion_loop_trig = func_0010BED0(0.0f)) != 0) {
                next:
                    if (flags & 0x20) {
                        ready();
                        m_motion_now.stop();
                    } else {
                        m_unk450 = 0;
                        m_motion_cmd_idx++;
















                        ASSERT(m_motion_cmd_idx < DOG_MAX_MOTION_CMD);
                        loop = 1;
                    }
                }
            } else if (wait == 2) {
                loop = 0;
                int r = m_motion_loop_trig = func_0010BE80(0.0f);
                if (r == 1) {
                    DogVector aux;
                    func_00109284(aux);
                    if (aux.m_w != 0.0f) {
                        addRotY(aux.m_w);
                        func_0010E7DC(aux.m_w);
                        clearRotYAAR();
                    }
                } else if (r == 2) {
                    DogVector aux;
                    func_00109284(aux);
                    if (aux.m_w != 0.0f) {
                        addRotY(-aux.m_w);
                        func_0010E7DC(-aux.m_w);
                        clearRotYAAR();
                    }
                }
            }
        }
    } else {
        DogSubMode *sm = getSubMode();
        if (sm->m_mode & 4) {
            sm->m_step = 0;
            sm->m_mode &= ~4;
        } else if (sm->m_mode & 1) {
            int flag = m_motion_flag[0];
            int loop = flag & 7;
            if (flag & 1) {
                int r = m_motion_loop_trig = func_0010BE80(0.0f);
                if (r == 1) {
                    DogVector aux;
                    func_00109284(aux);
                    if (aux.m_w != 0.0f) {
                        addRotY(aux.m_w);
                        func_0010E7DC(aux.m_w);
                        clearRotYAAR();
                    }
                } else if (r == 2) {
                    DogVector aux;
                    func_00109284(aux);
                    if (aux.m_w != 0.0f) {
                        addRotY(-aux.m_w);
                        func_0010E7DC(-aux.m_w);
                        clearRotYAAR();
                    }
                }
            } else if ((m_motion_loop_trig = func_0010BED0(0.0f)) != 0) {
                if (loop == 0) {
                    ready();
                    m_motion_now.stop();
                } else if (flag & 2) {
                    func_0010B1B0(m_motion_flag[1], 0.016666694f, 1, -1, -1);
                    sm->m_mode = 1;
                    sm->m_step = 0;
                    m_motion_flag[1] = -1;
                }
            }
        } else {
            m_motion_loop_trig = 0;
        }
    }
    float y;
    float rot;
    if (func_0010E848(&y, &rot)) {
        m_unk70.m_y = y;
        m_unk70.m_w = 1.0f;
        m_unk90 = 1;
        setRotOffsetY(rot);
    }
    func_0010F480();
}

// 0x0010D9EC: the main motion's frame (sub mode 2: from its step).
float DogActor::func_0010D9EC()
{
    if (getMode() == 2) {
        return -m_submode.m_step - 1;
    }
    return m_motion_now.m_main.m_time;
}

// 0x0010DA18: the main motion's time ratio (0 in sub mode 2).
float DogActor::func_0010DA18()
{
    if (getSubMode()->m_mode == 2) {
        return 0.0f;
    }
    return m_motion_now.getTimeRatio();
}

// 0x0010DA4C: the main motion's frame at 60 per second (sub mode 2: from
// its step).
float DogActor::func_0010DA4C()
{
    if (getMode() == 2) {
        return -m_submode.m_step - 1;
    }
    return m_motion_now.m_main.m_time * 60.0f;
}

// 0x0010DA80: the main motion's frame at 120 per second.
float DogActor::func_0010DA80()
{
    return m_motion_now.m_main.m_time * 60.0f * 2.0f;
}

// 0x0010DA98: the name of the motion with id theID, or null.
const char *DogActor::func_0010DA98(int theID)
{
    int n = func_0010A874(theID);
    if (n >= 0) {
        return m_motion_data[n].m_unk1C;
    }
    return 0;
}

// 0x0010DAD8: the main motion's speed in frames per 1/60 s; 0 while a
// command list runs and its last command is not reached.
float DogActor::func_0010DAD8()
{
    if (m_unk45C > 0 && m_unk460 != m_unk45C - 1) {
        return 0.0f;
    }
    return m_motion_now.m_main.m_speed / 0.016666694f;
}

// 0x0010DB18: the sub mode's step in mode 2, else -1.
int DogActor::func_0010DB18()
{
    if (getMode() == 2) {
        return m_submode.m_step;
    }
    return -1;
}

// 0x0010DB38: is bit 1 of the sub mode set?
int DogActor::func_0010DB38()
{
    return (getSubMode()->m_mode >> 1) & 1;
}









































































































// 0x0010DB48: how far the interpolation into the new motion has gone (0 to
// 1): from the motion's link table when its length is m_interpolation,
// else linear; 1 when not interpolating.
float DogActor::func_0010DB48()
{
    if (getMode() < 0) {
        return 1.0f;
    }
    if (!(getMode() & 2)) {
        return 1.0f;
    }
    ASSERT(m_interpolation > 0);
    int no = m_motion_now.getMainMotionNo();
    if (no >= 0) {
        int *link = m_motion_now.getLinkData(no);
        if (link && link[0] == m_interpolation && m_submode.m_step >= 0) {
            return link[1 + m_submode.m_step] / 100.0f;
        }
    }











    ASSERT(m_interpolation > 0);
    float r = (m_submode.m_step + 1) / (float)m_interpolation;
    if (r < 0.0f) { r = 0.0f; }
    else if (r > 1.0f) { r = 1.0f; }
    ASSERT(0.0f <= r && r <= 1.0f);
    return r;
}








// 0x0010DD30: func_0010DB48 for node theNode, which a sub motion may
// already weigh down.
float DogActor::func_0010DD30(int theNode)
{
    ASSERT(theNode >= 0 && theNode <= (int)(((int)(sizeof(int)*8))*4));
    float w = m_motion_now.getNodeWeight(theNode);
    if (w < 1.0f) {
        return w;
    }
    if (getMode() < 0) {
        return 1.0f;
    }
    if (!(getMode() & 2)) {
        return 1.0f;
    }

    ASSERT(m_interpolation > 0);
    int no = m_motion_now.getMainMotionNo();
    if (no >= 0) {
        int *link = m_motion_now.getLinkData(no);
        if (link && link[0] == m_interpolation && m_submode.m_step >= 0) {
            return link[1 + m_submode.m_step] / 100.0f;
        }
    }












    ASSERT(m_interpolation > 0);
    float r = (m_submode.m_step + 1) / (float)m_interpolation;
    if (r < 0.0f) { r = 0.0f; }
    else if (r > 1.0f) { r = 1.0f; }
    ASSERT(0.0f <= r && r <= 1.0f);
    return r;
}

// 0x0010DF54: the pose of the current frame: the motions, blended per node
// from the saved pose while interpolating, the control node's turn, then
// the node matrices (scaled nodes too). Returns 0 without a motion.
// NON_MATCHING: in the first loop the game keeps i++ at the bottom (i in
// $s2, the pose pointer in $s3); here sched1 moves it to the top and the
// two registers swap.
#ifdef NON_MATCHING


int DogActor::func_0010DF54(int theStep)
{
    if (m_motion_now.getMainMotionNo() < 0 || m_max_motion <= 0) {
        return 0;
    }
    ASSERT((m_motion_now.getMainMotionNo() >= 0) && (m_motion_now.getMainMotionNo() < m_max_motion));
    ASSERT(__null != m_posture);
    m_motion_now.getPosture(m_posture);
    DogSubMode *sm = getSubMode();
    if (sm->m_mode & 8) {
        func_0010EDBC();
    }
    for (int i = 0; i < m_unk1C8; i++) {
        float rrr = func_0010DD30(i);















        ASSERT(0.0f <= rrr && rrr <= 1.0f);
        if (rrr != 1.0f) {
            func_0022F610(&m_posture[i], &m_posture[i], &m_unk1D0[i], rrr);
        }
    }
    if (sm->m_mode & 2) {
        if (func_0010DB48() >= 1.0f) {
            sm->m_mode = (sm->m_mode & ~2) | 1;
        }
    }
    if (m_control_node >= 0) {
        float *rot = m_posture[m_control_node].m_unk00 + 4;
        DogVector q;
        if (m_control_node_flg == 0) {
            func_00231198((float *)&q, (float *)&m_unk3E0);
            func_00230470(rot, (float *)&q, rot);
            func_00230660(rot, rot);
        } else {
            func_00231198(rot, (float *)&m_unk3E0);
            func_00230660(rot, rot);
        }
    }

















































































    ASSERT(__null != m_mat_local);
    func_0022F7A0(m_posture, m_mat_local, m_assign_tbl);
    for (int i = 0; i < 5; i++) {
        if (m_scale_node_no[i] > 0) {
            func_00237390(m_mat_local[m_scale_node_no[i]][0], m_mat_local[m_scale_node_no[i]][0], m_scale_node_val[i]);
            func_00237390(m_mat_local[m_scale_node_no[i]][1], m_mat_local[m_scale_node_no[i]][1], m_scale_node_val[i]);
            func_00237390(m_mat_local[m_scale_node_no[i]][2], m_mat_local[m_scale_node_no[i]][2], m_scale_node_val[i]);
            func_00237390(m_mat_local[m_scale_node_no[i]][3], m_mat_local[m_scale_node_no[i]][3], m_scale_node_val[i]);
        }
    }
    convertLocalToModel((tag_I3dMatrixF4x4_s *)m_mat_model, (tag_I3dMatrixF4x4_s *)m_mat_local);
    if (m_unk16C) {
        func_00116130();
    }
    if (theStep) {
        nextStep();
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/dog/dogactor", func_0010DF54__8DogActori);
#endif

// 0x0010E328: plays motion theN from its start, without interpolation and
// with the rotation offsets cleared.
void DogActor::func_0010E328(int theN)
{
    m_rot_y_aar = 0.0f;
    float r = m_rot_y_aar;
    m_rot_offset.set(r, r, r, 1.0f);
    m_unk70.m_w = 1.0f;
    m_unk90 = 1;
    m_unk70.m_y = r;
    func_0010BF00(0);
    func_0010AE90(theN, 0);
    m_motion_now.m_main.m_time = r;
}

// The extra drawing parameters i3d takes (ours).
struct DogDrawParam {
    int m_flags;
    float m_value[5];
};

// 0x0010E3AC: draws the model (with node matrices when theUseMatrix); a
// light makes it pulse, and m_unk16C gives drawing parameters.
void DogActor::vfunc19(void *theRenderStage, int theUseMatrix, DogEntity *theParent)
{
    int user = 0;
    if (m_unk13C >= 0) {
        int f = D_006E9840 & 0x1F;
        if (f >= 16) {
            f = 31 - f;
        }
        user = i3dGetUser((I3dOwner *)m_i3r_root, m_unk13C);
        m_unk4B0[0] = m_unk4B0[1] = m_unk4B0[2] = f * 0.25f + 1.0f;
        i3dSetUser((I3dOwner *)m_i3r_root, (int)m_unk4A0, m_unk13C);
    }
    if (m_unk16C) {
        DogDrawParam param;
        DogDrawParam tmp;
        tmp.m_flags = 0x1F;
        tmp.m_value[0] = ((float *)m_unk16C)[3];
        tmp.m_value[1] = ((float *)m_unk16C)[3];
        tmp.m_value[2] = ((float *)m_unk16C)[3];
        tmp.m_value[3] = ((float *)m_unk16C)[3];
        tmp.m_value[4] = ((float *)m_unk16C)[3];
        param = tmp;
        i3dCallLocked(theRenderStage, m_i3r_root, 0, theParent ? theParent : this, &param);
    } else {
        i3dCallLocked(theRenderStage, m_i3r_root, theUseMatrix ? m_mat_model : 0, theParent ? theParent : this, 0);
    }
    if (m_unk13C >= 0) {
        i3dSetUser((I3dOwner *)m_i3r_root, user, m_unk13C);
    }
}
































































































































































































































































// 0x0010E534: draws the model.
void DogActor::vfunc20(void *theRenderStage)
{
    ASSERT(theRenderStage);
    ASSERT(m_i3r_root);
    i3dCallLocked(theRenderStage, m_unk120 ? m_unk120 : m_i3r_root, m_mat_model, this, 0);
}


























// 0x0010E5C0: one frame: advances the motion (every m_unk45C ticks), moves
// and draws the model, applies the pending turn.
void DogActor::vfunc12(void *theRenderStage, void *a, void *b)
{
    ASSERT(theRenderStage);
    ASSERT(m_i3r_root);
    int tick = 1;
    if (m_unk45C > 0) {
        if (++m_unk460 >= m_unk45C) {
            m_unk460 = 0;
        } else {
            tick = 0;
        }
    }
    int r;
    if (tick) {
        r = func_0010DF54(0);
    } else {
        r = 1;
    }
    if (!vfunc11(a, b)) {
        transform();
    }
    if (!m_unk140) {
        vfunc19(theRenderStage, r, 0);
    }
    if (m_rot_y_aar != 0.0f) {
        m_unk50.m_y += m_rot_y_aar;
        if (m_unk50.m_y < -DOG_PI) {
            m_unk50.m_y += DOG_PI2;
        } else if (m_unk50.m_y >= DOG_PI) {
            m_unk50.m_y -= DOG_PI2;
        }
        m_unk90 = 1;
        func_0010E7DC(m_rot_y_aar);
        m_rot_y_aar = 0.0f;
    }
    if (tick) {
        nextStep();
    }
    getSubMode()->m_mode &= ~8;
}

// 0x0010E7B4: keeps the aux track's turn (func_0010A584) in m_rot_ofs_y.
void DogActor::func_0010E7B4()
{
    m_rot_ofs_y = func_0010A584();
}

// 0x0010E7DC: turns the base rotation by theRot.
void DogActor::func_0010E7DC(float theRot)
{
    m_base_rot.m_y += theRot;
    if (m_base_rot.m_y < -DOG_PI) {
        m_base_rot.m_y += DOG_PI2;
    } else if (m_base_rot.m_y >= DOG_PI) {
        m_base_rot.m_y -= DOG_PI2;
    }
}

// 0x0010E848: while blending in from a saved offset (func_0010DB38), the
// height and turn still to add, fading with func_0010DB48; returns 1 then,
// else 0 (and zeros).
int DogActor::func_0010E848(float *theY, float *theRot)
{
    *theY = *theRot = 0.0f;
    if (func_0010DB38()) {
        DogVector aux;
        float r = func_0010DB48();
        func_00108C90(aux, 0.0f);
        *theY = m_trans_ofs_y_save * (1.0f - r) + aux.m_y * r;
        float rot = m_rot_ofs_y;
        if (rot < -3.1415918f) {
            rot = DOG_PI;
        }
        *theRot = -rot * (1.0f - r);
        return 1;
    }
    return 0;
}

// 0x0010E930: saves the height offset (the aux track's start while
// blending, else m_unk70.m_y) and the aux turn.
void DogActor::func_0010E930()
{
    if (func_0010DB38()) {
        DogVector aux;
        func_00108C90(aux, 0.0f);
        m_trans_ofs_y_save = aux.m_y;
        func_0010E7B4();
    } else {
        saveTransOfsY();
        func_0010E7B4();
    }
}

// 0x0010E9AC: m_control_node = the main motion's node named theName (-1
// without one); returns it.
int DogActor::func_0010E9AC(const char *theName)
{
    int no;
    if (!theName || (no = getMotionNo()) < 0) {
        return m_control_node = -1;
    }
    return m_control_node = i3mGetNodeIndexByName(no, theName);
}

// 0x0010EAA4
DogVector *DogActor::func_0010EAA4()
{
    return &m_unk3E0;
}

// 0x0010EAAC
void DogActor::func_0010EAAC(const DogVector &theV)
{
    m_unk3E0 = theV;
}












































































































// 0x0010EAB8: the world matrix of node theNode.
void DogActor::vfunc17(float (*theOut)[4], int theNode)
{
    ASSERT(m_mat_model);
    func_002377D0(theOut, m_unk00, m_mat_model[theNode]);
}


















// 0x0010EB28: the world position of node theNode.
void DogActor::vfunc18(DogVector &theOut, int theNode)
{
    ASSERT(m_mat_model);
    float m[4][4];
    func_002377D0(m, m_unk00, m_mat_model[theNode]);
    theOut = *(DogVector *)m[3];
}

// 0x0010EBA0: scales node theNode by theScale (1 removes it); up to 5.
void DogActor::func_0010EBA0(int theNode, float theScale)
{
    for (int i = 0; i < 5; i++) {
        if (m_scale_node_no[i] == theNode) {
            if (theScale == 1.0f) {
                m_scale_node_no[i] = -1;
            } else {
                m_scale_node_val[i] = theScale;
            }
            return;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (m_scale_node_no[i] < 0 || m_scale_node_val[i] == 1.0f) {
            m_scale_node_no[i] = theNode;
            m_scale_node_val[i] = theScale;
            return;
        }
    }
}

// 0x0010EC50
void DogActor::func_0010EC50()
{
    for (int i = 0; i < 5; i++) {
        m_scale_node_no[i] = -1;
        m_scale_node_val[i] = 1.0f;
    }
}






















// 0x0010EC8C: checks that no node is scaled.
void DogActor::func_0010EC8C()
{
    for (int i = 0; i < 5; i++) {
        ASSERT(m_scale_node_no[i] == -1);
        ASSERT(m_scale_node_val[i] == 1.0f);
    }
}


// 0x0010ED2C: sets the base rotation around y.
void DogActor::func_0010ED2C(float theRot)
{
    if (theRot < -DOG_PI) {
        theRot += DOG_PI2;
    }
    if (theRot >= DOG_PI) {
        theRot -= DOG_PI2;
    }
    m_base_rot.m_y = theRot;
    ASSERT((m_base_rot.m_y >= -DOG_PI) && (m_base_rot.m_y < DOG_PI));
}

// 0x0010EDBC: the current pose becomes the blend start.
void DogActor::func_0010EDBC()
{
    memcpy(m_unk1D0, m_posture, m_unk1C8 * sizeof(I3mPosture));
}

// 0x0010EDEC: saves the current pose and motion state for blending.
void DogActor::func_0010EDEC()
{
    func_0010EDBC();
    m_motion_old = m_motion_now;
}

// 0x0010EEBC
DogActor::DogActor()
{
    init();
}

// 0x0010F008
DogActor::DogActor(int theN)
{
    init();
    allocMotion(theN);
}

// 0x0010F16C. Matches, but defining DogActor's key method here makes g++
// emit its vtable and RTTI name: kept in asm until the file is complete.
DogActor::~DogActor()
{
    release(0);
}

// 0x0010F1F0
int DogActor::vfunc15(void *theData, void *theA, void *theB)
{
    int ret = DogModel::vfunc15(theData, theA, theB);
    memset(m_unk470, 0, 0x30);
    if (ret >= 0) {
        func_0010F3A4();
    }
    return ret;
}

// 0x0010F244
int DogActor::vfunc14(void *theTex, BedPfh *thePfh, int theA, int theB)
{
    int ret = DogModel::vfunc14(theTex, thePfh, theA, theB);
    memset(m_unk470, 0, 0x30);
    if (ret >= 0) {
        func_0010F3A4();
    }
    return ret;
}

// 0x0010F298
void DogActor::func_0010F298()
{
    m_unk164 = m_unk160;
    m_unk160 = -1;
    m_unk168 = -1;
    getSubMode()->m_mode |= 8;
    m_motion_now.setMainMotion(0);
}
































































































































































































































































































































































// 0x0010F2DC: is theName the name of the first file in m_unk1A4's pack
// (up to its extension)?
int DogActor::func_0010F2DC(const char *theName)
{
    if (!theName) {
        ASSERT(theName);
        return 0;
    }
    if (!m_unk1A4) {
        return 0;
    }
    BedPfh pfh(m_unk1A4);
    const char *name = pfh.getName(0);
    if (!name) {
        return 0;
    }
    const char *p = theName;
    for (;;) {
        char c = *p++;
        if (c == '\0') {
            if (*name == '\0' || *name == '.') {
                return 1;
            }
            return 0;
        }
        if (*name == '\0' || *name == '.') {
            return 0;
        }
        if (*name != c) {
            return 0;
        }
        name++;
    }
}

