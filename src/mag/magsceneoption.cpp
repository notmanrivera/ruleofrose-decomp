// mag/magsceneoption.cpp: MagScene's option text.
#include "mag/magscene.h"
#include "mag/maglife.h"
extern "C" void renderPostProcess__10MagLifeBwn(void *);
#include "sdk/string.h"

enum {
    UTLVB_TYPE_FLOAT = 2,
    UTLVB_TYPE_STR = 3
};

void MagScene::func_0013C29C()
{
    MagLifeControlChara *pc = (MagLifeControlChara *)&m_pc;
    if (pc->m_actor) {
        pc->func_0011A14C();
    }
    renderPostProcess__10MagLifeBwn((char *)this + 0x2AFE0);
}

void MagScene::func_0013C2EC(const DogVector &thePos, const DogVector &theDir)
{
    m_unk2ADA0 = thePos;
    m_unk2ADB0 = theDir;
    m_unk2AD9C = 1;
}

struct MagOption {
    const char *m_name;
    int m_id;
};













































static const MagOption sOption[] = {
    { "MAGTEST", 0 },
    { "CAMERA_MOVE_SPEED", 1 },
    { "ZOOM_RATIO", 2 },
    { "SHADOW_BLACKNESS", 3 },
    { "SHADOW_OFFSET", 4 },
    { "AMBIENT_EXTRA", 5 },
    { "PC_MOVE_LIMIT", 6 },
    { "PC_PAD_ROTATE", 7 },
    { "PC_PAD_FORWARD", 8 },
    { "PC_ROTATE_SPEED", 9 },
    { "PC_R180_LIMIT", 10 },
    { "PC_PADDIFF_LIMIT", 11 },
    { "PC_HIT_SIZE", 12 },
    { "PC_HIT_OFFSET", 13 },
    { "PC_HIT_CHECK_DISP", 14 },
    { 0, -1 },
    { 0, 0 },
};
void MagScene::func_0013C328(char *theText)
{
    int n = txtParse(m_option_bucket, 16, theText);
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < 15; j++) {
            if (strcmp(m_option_bucket[i].m_name, sOption[j].m_name) == 0) {
                break;
            }
        }
        float v;
        if (m_option_bucket[i].m_type == UTLVB_TYPE_FLOAT) {
            v = m_option_bucket[i].m_float;
        } else {
            v = (float)m_option_bucket[i].m_int;
        }
        switch (sOption[j].m_id) {
        case 0:
            ASSERT(m_option_bucket[i].m_type == UTLVB_TYPE_STR);
            break;
        case 1:


            ASSERT(m_option_bucket[i].m_type == UTLVB_TYPE_FLOAT);
            break;
        case 2:
            m_opt_zoom_ratio = v;
            break;
        case 3:



            ASSERT(m_option_bucket[i].m_type == UTLVB_TYPE_FLOAT);
            m_opt_shadow_blackness = v;
            break;
        case 4:


            ASSERT(m_option_bucket[i].m_type == UTLVB_TYPE_FLOAT);
            m_opt_shadow_offset = v;

            ASSERT(m_opt_shadow_offset >= 0.9f && m_opt_shadow_offset <= 1.9f);
            break;
        case 5:

            ASSERT(m_option_bucket[i].m_type == UTLVB_TYPE_FLOAT);
            m_opt_ambient_extra = v;

            ASSERT(m_opt_ambient_extra >= 0.0f && m_opt_ambient_extra <= 2.0f);
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            m_pc.func_0011B964(sOption[j].m_id, v);
            break;
        }
    }
}
