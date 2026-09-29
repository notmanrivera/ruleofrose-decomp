// bed/bedpfh.cpp: pack file header ("RTPK" archives).
//
// Partial decompilation: the INCLUDE_ASM functions are still the original
// asm. Method names are ours.

#include "bed/bedpfh.h"
#include "include_asm.h"

INCLUDE_ASM("asm/nonmatchings/bed/bedpfh", func_00101718);

// 0x00101738
void BedPfh::clear()
{
    m_top = 0;
    m_unk04 = 0;
    m_unk08 = 0;
    m_unk0C = 0;
    m_unk10 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/bed/bedpfh", D_002E5668);

INCLUDE_RODATA("asm/nonmatchings/bed/bedpfh", D_002E5678);

INCLUDE_RODATA("asm/nonmatchings/bed/bedpfh", D_002E5680);

INCLUDE_ASM("asm/nonmatchings/bed/bedpfh", func_00101750);

INCLUDE_ASM("asm/nonmatchings/bed/bedpfh", func_00101928);

INCLUDE_ASM("asm/nonmatchings/bed/bedpfh", func_001019F0);
