// dog/dogmotionblend.cpp: DogMotionBlend, see dog/dogmotionblend.h.
//
// Matching decompilation. The asserts must stay on their lines (83-87,
// 113-120, 139-143, 207-302, 365-447, 522-557, 585-587): the runs of blank
// lines stand for lost code or comments. Method names are ours.

#include "ror.h"
#include "dog/dogmotionblend.h"

// Still asm (mw/i3d).
extern "C" {
float func_0022E958(void *theRoot);        // the motion's length in frames
int func_0022B6F8(void *theRoot);           // its number of nodes
void func_0022E960(void *theRoot, I3mPosture *theOut, int theFlags, float theTime);
void func_0022F610(I3mPosture *theOut, I3mPosture *a, I3mPosture *b, float theRatio);
}

// 0x0010737C: drops the motions whose data is gone; everything when the
// table is.
void DogMotionBlend::validate()
{
    if (m_motion == 0) {
        m_main.m_no = -1;
        m_main.m_speed = 0.016666694f;
        m_main.m_time = 0.0f;
        for (int i = 0; i < 4; i++) {
            m_sub[i].m_no = -1;
            m_sub[i].m_time = 0.0f;
            m_sub[i].m_speed = 0.016666694f;
            m_sub[i].m_ratio = -1.0f;
            m_sub[i].m_unk18 = 1.0f;
            m_sub[i].m_ratio = -1.0f;
            for (int j = 0; j < 4; j++) {
                m_sub[i].m_mask[j] = 0;
            }
        }
        return;
    }
    int no = getMotionNo();
    if (no >= 0 && m_motion[no].m_i3m_root == 0) {
        m_main.m_no = -1;
        m_main.m_speed = 0.016666694f;
        m_main.m_time = 0.0f;
    }
    for (int i = 0; i < 4; i++) {
        if (m_sub[i].m_no >= 0 && m_motion[m_sub[i].m_no].m_i3m_root == 0) {
            m_sub[i].m_no = -1;
            m_sub[i].m_time = 0.0f;
            m_sub[i].m_speed = 0.016666694f;
            m_sub[i].m_ratio = -1.0f;
            m_sub[i].m_unk18 = 1.0f;
            m_sub[i].m_ratio = -1.0f;
            for (int j = 3; j >= 0; j--) {
                m_sub[i].m_mask[j] = 0;
            }
        }
    }
}




















// 0x00107560: how far the main motion is, 0 to 1.
float DogMotionBlend::getTimeRatio()
{
    if (m_main.m_no >= 0) {
        ASSERT(m_main.m_no >= 0 && m_main.m_no < m_max_motion);
        ASSERT(m_motion[m_main.m_no].m_i3m_root);
        float mf = func_0022E958(m_motion[m_main.m_no].m_i3m_root);

        ASSERT(mf >= 0.0f);
        if (m_main.m_time <= 0.0f) {
            return 0.0f;
        }
        if (mf < m_main.m_time) {
            return 1.0f;
        }
        return m_main.m_time / mf;
    }
    return 0.0f;
}












// 0x00107678
float DogMotionBlend::setTimeRatio(float theRatio)
{
    ASSERT(0.0f <= theRatio && theRatio <= 1.0f);
    if (m_main.m_no >= 0) {

        ASSERT(m_main.m_no >= 0 && m_main.m_no < m_max_motion);
        ASSERT(m_motion[m_main.m_no].m_i3m_root);
        float mf = func_0022E958(m_motion[m_main.m_no].m_i3m_root);

        ASSERT(mf >= 0.0f);
        m_main.m_time = mf * theRatio;
    }
    return 0.0f;
}










// 0x0010779C: getTimeRatio for a sub motion.
float DogMotionBlend::getSubTimeRatio(int theNo)
{
    if (m_sub[theNo].m_no >= 0) {
        ASSERT(m_sub[theNo].m_no >= 0 && m_sub[theNo].m_no < m_max_motion);
        ASSERT(m_motion[m_sub[theNo].m_no].m_i3m_root);
        float mf = func_0022E958(m_motion[m_sub[theNo].m_no].m_i3m_root);

        ASSERT(mf >= 0.0f);
        if (m_sub[theNo].m_time <= 0.0f) {
            return 0.0f;
        }
        if (mf < m_sub[theNo].m_time) {
            return 1.0f;
        }
        return m_sub[theNo].m_time / mf;
    }
    return 0.0f;
}

// 0x001078DC: how much the first sub motion on theNode weighs (1 unless it
// is fading in).
float DogMotionBlend::getNodeWeight(int theNode)
{
    int n = theNode / 32;
    int b = theNode % 32;
    for (int i = 0; i < 4; i++) {
        if (m_sub[i].m_no >= 0 && ((m_sub[i].m_mask[n] >> b) & 1)) {
            if (m_sub[i].m_state == 2) {
                if (m_sub[i].m_blendTime <= 0) {
                    return 1.0f;
                }
                float w = (float)(m_sub[i].m_blendCount + 1) / (float)m_sub[i].m_blendTime;
                if (w < 0.0f) {
                    return 0.0f;
                }
                if (w > 1.0f) {
                    return 1.0f;
                }
                return w;
            }
            return 1.0f;
        }
    }
    return 1.0f;
}

// 0x001079D8: one tick, looping. Returns 1 when the main motion wrapped
// forwards, 2 backwards, else 0.
int DogMotionBlend::update()
{





















    ASSERT(m_motion);
    int ret = 0;
    if (m_main.m_no >= 0) {




























        ASSERT(m_main.m_no >= 0 && m_main.m_no < m_max_motion);
        ASSERT(m_motion[m_main.m_no].m_i3m_root);
        float mf = func_0022E958(m_motion[m_main.m_no].m_i3m_root);

        ASSERT(mf >= 0.0f);
        float step = m_main.m_speed * m_speedRatio;
        if (mf < step) {
            step = mf;
        }
        if (mf == 0.0f) {
            m_main.m_time = 0.0f;
        } else {
            m_main.m_time += step;
            if (step > 0.0f) {
                float d = m_main.m_time - mf;
                if (d >= -0.00001f && d <= 0.00001f) {
                    m_main.m_time = 0.0f;
                    ret = 1;
                } else if (d > 0.0f) {
                    ret = 1;
                    m_main.m_time -= mf;
                }
            } else if (step < 0.0f) {
                if (m_main.m_time < 0.0f) {
                    ret = 2;
                    m_main.m_time += mf;
                }
            } else {
                ret = 1;
            }



















            ASSERT(0.0f <= m_main.m_time && m_main.m_time < mf);
        }
    }
    for (int i = 0; i < 4; i++) {
        if (m_sub[i].m_no < 0) {
            continue;
        }




        ASSERT(m_sub[i].m_no >= 0 && m_sub[i].m_no < m_max_motion);
        ASSERT(m_motion[m_sub[i].m_no].m_i3m_root);
        float mf = func_0022E958(m_motion[m_sub[i].m_no].m_i3m_root);

        ASSERT(mf >= 0.0f);
        if (m_sub[i].m_state == 0) {
            if (mf == 0.0f) {
                m_sub[i].m_time = 0.0f;
            } else {
                float step = m_sub[i].m_speed * m_speedRatio;
                m_sub[i].m_time += step;
                if (step > 0.0f) {
                    if (m_sub[i].m_ratio >= 0.0f && m_sub[i].m_ratio * mf <= m_sub[i].m_time) {
                        m_sub[i].m_time = m_sub[i].m_ratio * mf;
                    }
                    if (mf <= m_sub[i].m_time) {
                        m_sub[i].m_time -= mf;
                    }
                } else if (step < 0.0f) {
                    if (m_sub[i].m_ratio >= 0.0f && m_sub[i].m_time <= m_sub[i].m_ratio * mf) {
                        m_sub[i].m_time = m_sub[i].m_ratio * mf;
                    }
                    if (m_sub[i].m_time < 0.0f) {
                        m_sub[i].m_time += mf;
                    }
                }
            }
        } else if (m_sub[i].m_state == 2) {
            m_sub[i].m_time = m_sub[i].m_ratio * mf;
            m_sub[i].m_speed = 0.0f;
            if (m_sub[i].m_blendCount >= m_sub[i].m_blendTime) {
                m_sub[i].m_blendCount = m_sub[i].m_blendTime;
            } else {
                m_sub[i].m_blendCount++;
            }
        }
    }
    return ret;
}

// 0x00107E30: one tick, stopping at the ends. Returns 1 at the end, 2 at
// the start, 3 when not moving, else 0.
int DogMotionBlend::updateOnce()
{























    ASSERT(m_motion);
    int ret = 0;
    if (m_main.m_no >= 0) {


























        ASSERT(m_main.m_no >= 0 && m_main.m_no < m_max_motion);
        ASSERT(m_motion[m_main.m_no].m_i3m_root);
        float mf = func_0022E958(m_motion[m_main.m_no].m_i3m_root);

        ASSERT(mf >= 0.0f);
        if (mf == 0.0f) {
            m_main.m_time = 0.0f;
            ret = 3;
        } else {
            float step = m_main.m_speed * m_speedRatio;
            m_main.m_time += step;
            if (step > 0.0f) {
                if (mf <= m_main.m_time) {
                    m_main.m_time = mf;
                    ret = 1;
                }
            } else if (step < 0.0f) {
                if (m_main.m_time < 0.0f) {
                    m_main.m_time = 0.0f;
                    ret = 2;
                }
            } else {
                ret = 3;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (m_sub[i].m_no < 0) {
            continue;
        }



















        ASSERT(m_sub[i].m_no >= 0 && m_sub[i].m_no < m_max_motion);
        ASSERT(m_motion[m_sub[i].m_no].m_i3m_root);
        float mf = func_0022E958(m_motion[m_sub[i].m_no].m_i3m_root);

        ASSERT(mf >= 0.0f);
        if (m_sub[i].m_state == 0) {
            if (mf == 0.0f) {
                m_sub[i].m_time = 0.0f;
            } else {
                m_sub[i].m_time += m_sub[i].m_speed * m_speedRatio;
                if (m_sub[i].m_speed > 0.0f) {
                    if (mf <= m_sub[i].m_time) {
                        m_sub[i].m_time -= mf;
                    }
                } else if (m_sub[i].m_time < 0.0f) {
                    m_sub[i].m_time += mf;
                }
            }
        } else if (m_sub[i].m_state == 2) {
            m_sub[i].m_time = m_sub[i].m_ratio * mf;
            m_sub[i].m_speed = 0.0f;
            if (m_sub[i].m_blendCount >= m_sub[i].m_blendTime) {
                m_sub[i].m_blendCount = m_sub[i].m_blendTime;
            } else {
                m_sub[i].m_blendCount++;
            }
        }
    }
    return ret;
}

// 0x00108178
void DogMotionBlend::stop()
{
    m_main.m_speed = 0.0f;
    for (int i = 3; i >= 0; i--) {
        m_sub[i].m_speed = 0.0f;
    }
}

// 0x001081A8
int DogMotionBlend::getMotionNo()
{
    return m_main.m_no;
}

// 0x001081B0: the pose at the current times: the main motion, then each
// sub motion over its nodes. Returns the number of nodes (0 without a
// main motion).
int DogMotionBlend::getPosture(I3mPosture *thePosture)
{
    if (m_main.m_no >= 0) {



























        ASSERT(thePosture);
        ASSERT(m_motion);




        ASSERT((m_main.m_no >= 0) && (m_main.m_no < m_max_motion));
        int maxnode = func_0022B6F8(m_motion[m_main.m_no].m_i3m_root);


        ASSERT(maxnode <= (((int)(sizeof(int)*8))*4));
        func_0022E960(m_motion[m_main.m_no].m_i3m_root, thePosture, 0x111, m_main.m_time);
        for (int i = 0; i < 4; i++) {
            int no = m_sub[i].m_no;
            if (no < 0) {
                continue;
            }
            I3mPosture posture[128];
















            ASSERT(no >= 0 && no < m_max_motion);
            ASSERT(m_motion[no].m_i3m_root);
            func_0022E960(m_motion[no].m_i3m_root, posture, 0x111, m_sub[i].m_time);
            int bits = 0;
            for (int n = 0; n < maxnode; n++) {
                if ((n & 0x1F) == 0) {
                    bits = m_sub[i].m_mask[n / 32];
                }
                if (bits & 1) {
                    func_0022F610(&thePosture[n], &thePosture[n], &posture[n], 0.0f);
                }
                bits >>= 1;
            }
        }
        return maxnode;
    }
    return 0;
}

// 0x00108428: holds sub motion theNo at theRatio of its length, fading it
// in over theTime ticks; at ratio 0, once faded, it goes.
void DogMotionBlend::setSub(int theNo, float theRatio, int theTime)
{






    ASSERT(theNo >= 0 && theNo < 4);
    ASSERT(theRatio >= 0.0 && theRatio <= 1.0f);
    ASSERT(theTime >= 0 && theTime < 1000);
    if (m_sub[theNo].m_ratio != theRatio) {
        m_sub[theNo].m_ratio = theRatio;
        m_sub[theNo].m_blendTime = theTime;
        m_sub[theNo].m_blendCount = 0;
        m_sub[theNo].m_state = 2;
    } else if (theRatio == 0.0f && m_sub[theNo].m_no >= 0) {
        if (m_sub[theNo].m_blendCount >= m_sub[theNo].m_blendTime) {
            m_sub[theNo].m_no = -1;
        }
    }
}
