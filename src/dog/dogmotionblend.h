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

// mw/i3d's pose of one node (0x30 bytes).
struct tag_I3mPosture_s {
    float m_unk00[12];
};
typedef struct tag_I3mPosture_s I3mPosture;

// An entry of the motion table (0x20 bytes).
struct DogMotionData {
    void *m_i3m_root;               // +0x00: the i3m motion
    int *m_unk04;                   // +0x04: [0] is its link time
    unsigned char m_unk08[0x18];
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
};

#endif
