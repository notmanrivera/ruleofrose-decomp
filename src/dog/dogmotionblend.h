// dog/dogmotionblend.h: DogMotionBlend, the motion player of a DogActor
// (its member at +0x1E4): one main motion, and up to 4 more laid over it
// on chosen nodes.
//
// DogMotionBlend, m_main, m_sub, m_no, m_time, m_motion, m_max_motion,
// m_i3m_root and getMainMotionNo come from assert strings (DogActor's
// member is m_motion_now); the rest is ours. DogActor's inline
// methods (getMotionNo, setMotionSpeed, setMotionTickTime...) use the
// fields at +0x04 to +0x14. Lines 122-123 hold inline methods that assert
// m_motion and n>=0 && n<m_max_motion (DogActor::getMotionLinkTime), not
// written yet.
#ifndef DOG_DOGMOTIONBLEND_H
#define DOG_DOGMOTIONBLEND_H

#include "ror.h"

// mw/i3d's pose of one node (0x30 bytes).
struct tag_I3mPosture_s {
    float m_unk00[12];
} __attribute__((aligned(16)));
typedef struct tag_I3mPosture_s I3mPosture;

// An entry of the motion table (0x20 bytes), DogActor's m_motion_data.
// m_i3m_root and m_tag_data are original (assert strings).
struct DogMotionTag {
    int m_numframe;                 // +0x00: an int, or a float's bits
    int m_type;                     // +0x04: the same
    int m_unk08[2];
    float m_data[1];                // +0x10: m_numframe frames of values
};

// A motion's event track: per frame, bits for events (DogActor::func_0010BCC8).
struct DogMotionEvents {
    int m_numframe;                 // +0x00: frames, plus a flag in bit 31
    int m_bits[1];                  // +0x04: one word per frame
};


struct DogMotionData {
    void *m_i3m_root;               // +0x00: the i3m motion
    int *m_unk04;                   // +0x04: [0] is its link time
    DogMotionTag *m_aux_data;       // +0x08: DogActor::getMotionAuxData
    DogMotionEvents *m_tag_data;    // +0x0C: DogActor::getMotionTagData
    int m_unk10;                    // +0x10: DogActor::func_0010AF18 flag 0x40 (low byte)
    int m_unk14;                    // +0x14: -1 when empty
    int m_unk18;                    // +0x18: -1 when empty
    char *m_unk1C;                  // +0x1C: name, "<prefix>_<name>"
};

class DogMotionBlend {
public:
    struct Main {
        int m_no;                   // +0x00: motion, -1 = none
        float m_speed;              // +0x04: frames per tick
        float m_time;               // +0x08: current frame
    };

    // A motion laid over the main one, on the nodes set in m_mask.
    struct Sub {
        int m_mask[4];              // +0x00: one bit per node, 128 nodes
        float m_speed;              // +0x10
        float m_time;               // +0x14
        float m_unk18;              // +0x18: 1.0 after a reset
        float m_ratio;              // +0x1C: where it stops, times its length (-1: runs)
        int m_no;                   // +0x20: motion, -1 = none
        int m_state;                // +0x24: 0 runs, 2 held at m_ratio (setSub)
        int m_blendTime;            // +0x28: ticks to fade in
        int m_blendCount;           // +0x2C
    };

    Main m_main;                    // +0x00
    float m_speedRatio;             // +0x0C: DogActor::setMotionSpeedRatio
    int m_tickTime;                 // +0x10: DogActor::setMotionTickTime
    int m_unk14;                    // +0x14
    int m_max_motion;               // +0x18
    DogMotionData *m_motion;        // +0x1C
    Sub m_sub[4];                   // +0x20

    DogMotionBlend();
    void setMainMotion(int theNo)
    {
        m_main.m_no = theNo;
        m_main.m_speed = 0.016666694f;
        m_main.m_time = 0.0f;
    }
    void setMainMotionNo(int theNo) { m_main.m_no = theNo; }
    void setMainTime(float theTime) { m_main.m_time = theTime; }
    void setSubRatio(int n, float theRatio, float theTime) { m_sub[n].m_ratio = theRatio; m_sub[n].m_time = theTime; }
    void setSubMotion(int n, int theNo) { m_sub[n].m_no = theNo; m_sub[n].m_time = 0.0f; m_sub[n].m_speed = 0.016666694f; m_sub[n].m_ratio = -1.0f; }
    void setMainSpeed(float theSpeed) { m_main.m_speed = theSpeed; }
    void setMain(int theNo, float theSpeed)
    {
        m_main.m_no = theNo;
        m_main.m_time = 0.0f;
        m_main.m_speed = theSpeed;
    }
    void setSubMotionNo(int n, int theNo) { m_sub[n].m_no = theNo; }
    void setMotionTable(DogMotionData *theTable, int theNum)
    {
        m_motion = theTable;
        m_max_motion = theNum;
        validate();
    }
    void validate();
    float getTimeRatio();
    float setTimeRatio(float theRatio);
    float getSubTimeRatio(int theNo);
    float getNodeWeight(int theNode);
    int update();
    int updateOnce();
    void stop();
    int getMainMotionNo() const;
    int getPosture(I3mPosture *thePosture);
    void setSub(int theNo, float theRatio, int theTime);







    int getUnk10(int n) const { ASSERT(m_motion); ASSERT(n>=0 && n<m_max_motion); return (unsigned char)m_motion[n].m_unk10; }
    int *getLinkData(int n) const { ASSERT(m_motion); ASSERT(n>=0 && n<m_max_motion); return m_motion[n].m_unk04; }
};

#endif
