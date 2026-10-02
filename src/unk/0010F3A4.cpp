// unk/0010F3A4: DogActor's eye: the eye material and blinking.
//
// Matching decompilation. These methods follow dog/dogactor.cpp in .text,
// but their .rodata ("eye" and the frame tables) comes after
// dog/dogactor.cpp's, which ends with the RTTI names and inline-method
// strings a translation unit emits last: they are a file of their own,
// name unknown.

#include "ror.h"
#include "dog/dogactor.h"
#include "sdk/string.h"

// utl/utlbtl: a random number from theMin to theMax.
extern "C" int func_0010423C(int theMin, int theMax);

// 0x0010F3A4: finds the eye material (the first named "...eye...") and
// resets the blinking.
void DogActor::func_0010F3A4()
{
    void *list = (char *)m_i3r_root + 0x10;
    int num = func_0022AEC0(list);
    for (int i = 0; i < num; i++) {
        if (strstr(func_0022AF08(list, i), "eye")) {
            m_unk484 = func_0022AED8(list, i);
            if (m_unk484) {
                m_unk480 = func_0022AAD0(m_unk484, 0);
            }
            break;
        }
    }
    m_unk470[0] = m_unk470[1] = 0.0f;
    m_unk470[2] = m_unk470[3] = 1.0f;
    m_unk488 = 0;
    m_unk490 = 0;
    m_unk494 = 0;
    m_unk48C = 0;
    func_0010F70C();
}

// 0x0010F480: blinks: after m_unk494 ticks, steps through the closing and
// opening frames, then waits again 60-90 ticks (or blinks again at once).
void DogActor::func_0010F480()
{
    if (!(m_unk488 & 1)) {
        return;
    }
    if (++m_unk490 < m_unk494) {
        return;
    }
    int t = m_unk490 - m_unk494;
    int tbl[] = {3, 2, 1, 1, 1, 0, -1};
    int i = 0;
    for (;;) {
        if (t <= tbl[i]) {
            func_0010F5E4(tbl[i + 1]);
            break;
        }
        t -= tbl[i];
        i += 2;
        if (tbl[i] == -1) {
            break;
        }
    }
    if ((m_unk488 & 2) && tbl[i + 1] == 0) {
        m_unk488 &= ~3;
        return;
    }
    if (tbl[i] != -1) {
        return;
    }
    m_unk494 = (m_unk494 < 60 || func_0010423C(0, 1)) ? func_0010423C(60, 90) : 0;
    m_unk490 = 0;
}

// 0x0010F5E4: shows eye frame theFrame (0 open, 2 closed).
void DogActor::func_0010F5E4(int theFrame)
{
    if (theFrame == m_unk48C) {
        return;
    }
    m_unk484 = 0;
    m_unk480 = 0;
    void *list = (char *)m_i3r_root + 0x10;
    int num = func_0022AEC0(list);
    for (int i = 0; i < num; i++) {
        if (strstr(func_0022AF08(list, i), "eye")) {
            m_unk484 = func_0022AED8(list, i);
            if (m_unk484) {
                m_unk480 = func_0022AAD0(m_unk484, 0);
            }
            break;
        }
    }
    if (m_unk484 && m_unk480) {
        float v[] = {0.0f, 0.3203125f, 0.6484375f};
        m_unk470[1] = v[theFrame];
        func_0021AB30(m_unk480, m_unk470);
        ((unsigned short *)*(void **)m_unk484)[4]++;
    }
    m_unk48C = theFrame;
}

// 0x0010F70C: starts blinking.
void DogActor::func_0010F70C()
{
    if (m_unk484 && m_unk480) {
        m_unk488 = (m_unk488 | 1) & ~2;
    }
}

// 0x0010F73C: closes the eyes (starts a blink when not blinking).
void DogActor::func_0010F73C()
{
    if (m_unk484 && m_unk480) {
        if (m_unk488 & 1) {
            if (m_unk490 < m_unk494) {
                m_unk490 = 0;
                m_unk494 = 1;
            }
        } else if (m_unk48C == 0) {
            m_unk488 |= 3;
            m_unk490 = 0;
            m_unk494 = 1;
        } else {
            m_unk488 |= 3;
        }
    }
}

// 0x0010F7A0
void DogActor::func_0010F7A0()
{
    if (m_unk484 && m_unk480) {
        if (m_unk488 & 1) {
            if (m_unk490 < m_unk494) {
                m_unk488 &= ~3;
            } else {
                m_unk488 |= 2;
            }
        } else if (m_unk490 >= m_unk494) {
            m_unk488 |= 3;
        }
    }
}

// 0x0010F808: stops blinking with the eyes closed.
void DogActor::func_0010F808()
{
    if (m_unk484 && m_unk480) {
        func_0010F5E4(2);
        m_unk488 &= ~3;
        m_unk490 = 0;
        m_unk494 = 0;
    }
}
