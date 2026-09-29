// bed/bedpfh.h: pack file header ("RTPK" archives).
//
// Member names from assert strings in this file and its users (m_top,
// getFileOffset, getNumFile); the class name follows the file name like
// BedPad and BedSubMode, and is ours. Several inline methods of this header
// assert with "bed/bedpfh.h", so their line numbers matter once written.
#ifndef BED_BEDPFH_H
#define BED_BEDPFH_H

#include "ror.h"

class BedPfh {
public:
    void *m_top;        // +0x00: the loaded header
    int m_unk04;        // +0x04
    int m_unk08;        // +0x08
    int m_unk0C;        // +0x0C
    int m_unk10;        // +0x10

    void clear();
};

#endif
