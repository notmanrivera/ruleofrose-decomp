// bed/bedsubmode.cpp: push, pop and clear for BedSubMode's state stack.
//
// Matching decompilation. The ASSERTs must stay on lines 25 and 35: the
// original __LINE__ values (0x19, 0x23) are compiled into the code.
// Needs -fno-strict-aliasing: the original re-reads m_depth after the
// 128-bit store, which the compiler only does when stores may alias.

#include "bed/bedsubmode.h"

// 0x00100258












void BedSubMode::push()
{
    ASSERT(m_depth < MAX_STACK);
    m_stack[m_depth] = m_cur;
    m_depth++;
}

// 0x001002C0


void BedSubMode::pop()
{
    ASSERT(m_depth > 0);
    m_depth--;
    m_cur = m_stack[m_depth];
}

// 0x00100320: called from the owner's constructor, after the inline part
// has zeroed m_cur and m_stack (mag/magscene2).
void BedSubMode::clear()
{
    m_depth = 0;
    for (int i = MAX_STACK - 1; i >= 0; i--) {
        m_stack[i] = 0;
    }
}
