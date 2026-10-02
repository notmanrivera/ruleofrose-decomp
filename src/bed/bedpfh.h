// bed/bedpfh.h: pack file header, the "RTPK" archives (*.RPK on the disc).
//
// Original names: m_top, m_user_data, m_num_file, getNumFile, checkID and
// getFileOffset (from assert strings here and in the files that include
// this header); the rest are ours. The inline methods assert with this
// file's __LINE__, so they must stay on their lines (70-73, 81, 85-86 and
// 91).
#ifndef BED_BEDPFH_H
#define BED_BEDPFH_H

#include "ror.h"

// The first 0x20 bytes of a pack. The tables BedPfh::setTop finds follow
// it; files start at multiples of m_align, after the tables.
struct BedPfhHeader {
    int m_id;               // +0x00: BEDPFH_ID
    int m_size;             // +0x04: whole pack, header included
    short m_unk08;          // +0x08: 0 in every pack seen
    short m_flags;          // +0x0A: BEDPFH_* tables present
    short m_align;          // +0x0C: 0x800 (a DVD sector) or 0x20
    short m_num_file;       // +0x0E
    int m_name_size;        // +0x10: bytes of the name table
    int m_unk14[3];         // +0x14
};

enum {
    BEDPFH_ID = 0x4B505452,         // "RTPK" in memory
    BEDPFH_FILE_SIZE = 0x0001,      // int per file
    BEDPFH_FILE_OFFSET = 0x0002,    // int per file, from the header's start
    BEDPFH_USER_DATA = 0x0010,      // short per file; 0x0020, 0x0040... add more
    BEDPFH_NAME = 0x8000            // NUL-terminated names, in file order
};

// A view of a pack already in memory (m_top): pointers to its tables.
class BedPfh {
public:
    BedPfhHeader *m_top;    // +0x00
    int *m_file_size;       // +0x04
    int *m_file_offset;     // +0x08
    short *m_user_data;     // +0x0C
    char *m_name;           // +0x10

    // Callers call clear() right after reserving a BedPfh, so the
    // constructor is inline.
    BedPfh() { clear(); }
    BedPfh(void *top) { setTop(top); }

    void clear();
    void setTop(void *top);
    const char *getName(int theN) const;
    int getIndex(const char *theName) const;


















    int getFlags() const { ASSERT(m_top); return m_top->m_flags; }
    int getNumFile() const { ASSERT(m_top); return m_top->m_num_file; }
    int getSize() const { ASSERT(m_top); return m_top->m_size; }
    int getNameSize() const { ASSERT(m_top); return m_top->m_name_size; }


    // -1 without a size table.
    int getFileSize(int n) const { return m_file_size ? m_file_size[n] : -1; }
    int getFileOffset(int n) const { return m_file_offset ? m_file_offset[n] : -1; }


    short getUserData(int n) const { ASSERT(m_user_data); return m_user_data[n]; }


    void *getFileTop(int n) const {
        ASSERT(m_top);
        ASSERT(n >= 0 && n < m_top->m_num_file);
        return (char *)m_top + m_file_offset[n];
    }


    bool checkID() const { ASSERT(m_top); return m_top->m_id == BEDPFH_ID; }
};

#endif
