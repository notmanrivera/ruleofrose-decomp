// bed/bedpfh.cpp: pack file header, the "RTPK" archives (*.RPK).
//
// Matching decompilation. The ASSERTs must stay on lines 53 and 90 (0x35,
// 0x5A). Method names are ours except checkID and getNumFile.

#include "bed/bedpfh.h"

// 0x00101738
void BedPfh::clear()
{
    m_top = 0;
    m_file_size = 0;
    m_file_offset = 0;
    m_user_data = 0;
    m_name = 0;
}































// 0x00101750: point at a pack in memory and find its tables.
void BedPfh::setTop(void *top)
{
    clear();
    m_top = (BedPfhHeader *)top;
    ASSERT(checkID());
    char *p = (char *)(m_top + 1);
    int flags = getFlags();
    if (flags & BEDPFH_FILE_SIZE) {
        m_file_size = (int *)p;
        p += getNumFile() * sizeof(int);
    }
    if (flags & BEDPFH_FILE_OFFSET) {
        m_file_offset = (int *)p;
        p += getNumFile() * sizeof(int);
    }
    if (flags & BEDPFH_USER_DATA) {
        m_user_data = (short *)p;
        int n = 0;
        while (flags & (BEDPFH_USER_DATA << n)) {
            n++;
        }
        p += n * getNumFile() * sizeof(short);
    }
    if (flags & BEDPFH_NAME) {
        m_name = p;
        p += getNameSize();
    }
}










// 0x00101928: name of file theN (theN == getNumFile(): the end of the table).
const char *BedPfh::getName(int theN) const
{
    ASSERT(theN >= 0 && theN <= getNumFile());
    const char *p = m_name;
    for (int i = 0; i < theN; i++) {
        while (*p) {
            p++;
        }
        p++;
    }
    return p;
}

// 0x001019F0: index of the file called theName, or -1.
int BedPfh::getIndex(const char *theName) const
{
    const char *p = m_name;
    if (p == 0) {
        return -1;
    }
    int num = getNumFile();
    for (int i = 0; i < num; i++) {
        const char *q = p;
        int j = 0;
        while (*q == theName[j]) {
            if (*q == '\0') {
                return i;
            }
            q++;
            j++;
        }
        while (*p) {
            p++;
        }
        p++;
    }
    return -1;
}
