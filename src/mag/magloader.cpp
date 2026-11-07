// mag/magloader.cpp: see the header.
#include "mag/magloader.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"
#include "sdk/string.h"
#include "include_asm.h"

inline void *operator new(unsigned int, void *p) { return p; }

extern BedMemory D_006E9800;        // the global heap
extern "C" int func_001BE84C(const char *theName);
int utlStrCaseEqual(const char *theA, const char *theB);
extern "C" int strncmp(const char *, const char *, unsigned int);

void MagNameList::func_00141E44()
{
    for (int i = 0; i < m_num; i++) {
    }
}

int MagNameList::func_00141E78(int theNum, int theNameSize)
{
    return theNum * 13 + theNameSize;
}



































int MagNameList::func_00141E90(int *theLen, int *theOffset, int theNum, const char *theNameBuf)
{
    ASSERT(theNameBuf);
    const char *p = theNameBuf;
    int total = 0;
    for (int i = 0; i < theNum; i++) {
        theOffset[i] = total;
        int n = strlen(p);
        theLen[i] = n;
        total += n + 1;
        p += n + 1;
    }
    return total;
}











int MagNameList::func_00141F54(int theNum, const char *theNameBuf, const int *theOffset, const int *theSize, int theBase)
{
    ASSERT(0 < theNum && theNum <= 1024);
    int len[1024];
    int ofs[1024];
    m_name_size = func_00141E90(len, ofs, theNum, theNameBuf);
    m_data_size = func_00141E78(theNum, m_name_size);
    m_data = D_006E9800.alloc(m_data_size, -1);







    ASSERT(m_data);
    m_size = (int *)m_data;
    m_offset = m_size + theNum;
    m_name = (const char **)(m_offset + theNum);
    m_len = (unsigned char *)(m_name + theNum);
    char *names = (char *)m_len + theNum;
    memcpy(names, theNameBuf, m_name_size);
    for (int i = 0; i < theNum; i++) {
        m_size[i] = theSize[i];
        m_offset[i] = theOffset[i] + theBase;
        m_len[i] = len[i];
        m_name[i] = names + ofs[i];
    }
    m_name_buf = names;
    m_num = theNum;
    return 1;
}































































































// NON_MATCHING: $s2 and $s3 are swapped (data and name).
#ifdef NON_MATCHING
void MagNameList::func_001420F8(int theNum, const char *theNameBuf, const int *theOffset, const int *theSize, int theBase, int theSort)
{
    int old = m_num;
    if (old == 0) {
        func_00141F54(theNum, theNameBuf, theOffset, theSize, theBase);
        return;
    }
    int len[1024];
    int ofs[1024];
    int total = old + theNum;
    int nameSize = func_00141E90(len, ofs, theNum, theNameBuf);
    int allNames = m_name_size + nameSize;
    int dataSize = func_00141E78(total, allNames);
    int *data = (int *)D_006E9800.alloc(dataSize, -1);
    ASSERT(data);
    int *offset = data + total;
    const char **name = (const char **)(offset + total);
    unsigned char *lens = (unsigned char *)(name + total);
    char *names = (char *)lens + total;
    memcpy(names, m_name_buf, m_name_size);
    memcpy(names + m_name_size, theNameBuf, nameSize);
    for (int i0 = 0; i0 < m_num; i0++) {
        ((int *)name)[i0] = (int)m_name[i0] - (int)m_name_buf;
    }
    for (int i1 = m_num; i1 < total; i1++) {
        ((int *)name)[i1] = ofs[i1 - m_num] + m_name_size;
    }
    for (int i2 = 0; i2 < total; i2++) {
        name[i2] = names + (int)name[i2];
    }
    for (int i3 = 0; i3 < m_num; i3++) {
        data[i3] = m_size[i3];
        offset[i3] = m_offset[i3];
        lens[i3] = m_len[i3];
    }
    for (int i4 = 0; i4 < theNum; i4++) {
        data[i4 + m_num] = theSize[i4];
        offset[i4 + m_num] = theOffset[i4] + theBase;
        lens[i4 + m_num] = len[i4];
    }
    func_0014259C();
    m_num = total;
    m_size = data;
    m_data_size = dataSize;
    m_offset = offset;
    m_name = name;
    m_len = lens;
    m_name_buf = names;
    m_name_size = allNames;
    m_data = data;
    if (theSort) {
        int last = total - 1;
        for (int a = old; a < last; a++) {
            for (int b = last; a < b; b--) {
                if (strncmp(m_name[a], m_name[b], 0x20) > 0) {
                    const char *s = m_name[a];
                    m_name[a] = m_name[b];
                    m_name[b] = s;
                    int t = m_size[a];
                    m_size[a] = m_size[b];
                    m_size[b] = t;
                    t = m_offset[a];
                    m_offset[a] = m_offset[b];
                    m_offset[b] = t;
                    unsigned char c = m_len[a];
                    m_len[a] = m_len[b];
                    m_len[b] = c;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magloader", func_001420F8);
#endif

int MagNameList::func_00142500(const char *theName)
{
    for (int i = 0; i < m_num; i++) {
        if (utlStrCaseEqual(theName, m_name[i])) {
            return i;
        }
    }
    return -1;
}

void MagNameList::func_0014257C()
{
    m_num = 0;
    m_data = 0;
    m_data_size = 0;
    m_name = 0;
    m_len = 0;
    m_size = 0;
    m_offset = 0;
}

void MagNameList::func_0014259C()
{
    if (m_data) {
        D_006E9800.free(m_data);
    }
    func_0014257C();
}

















































































































int MagCharaLoader::func_001425DC()
{
    FileReadReq *req = &m_req;
    MagNameList *list = &m_list;
    new (req) FileReadReq;
    list->func_0014257C();
    char tmp[0x840];
    memset(tmp, 0, sizeof(tmp));
    m_req.m_unk08 = 1;
    m_req.m_name = "data/ch/CHARA.RPK";
    m_req.m_buf = (void *)((int)tmp / 0x40 * 0x40 + 0x40);
    m_req.m_size = 0x800;
    m_reader.func_001BE524(req, 0);
    BedPfh pfh(m_req.m_buf);
    const char *names[] = {
        "PC", "BWN", "ACTION", "ITEM", "FIX", "ENEMY", "DOOR", "INST",
        "CHAP01", "CHAP02", "CHAP03", "CHAP04", "CHAP05", "CHAP06",
        "CHAP07", "CHAP08", "CHAP09", "CHAP10", "CHAP11", "CHAP12"
    };
    int first = 0;
    for (int i = 0; i < 20; i++) {
        m_num_chara[i] = 0;
        m_first[i] = first;
        int n = pfh.getIndex(names[i]);
        if (n >= 0) {
            ASSERT(n >= 0 && n < 32);
            int size = pfh.m_file_size ? pfh.m_file_size[n] : -1;
            if (size > 0) {
                int offset = pfh.m_file_offset ? pfh.m_file_offset[n] : -1;
                char tmp2[0x2040];
                memset(tmp2, 0, sizeof(tmp2));
                void *bb = (void *)((int)tmp2 / 0x40 * 0x40 + 0x40);
                m_req.m_size = 0x2000;
                m_req.m_unk08 = 0;
                m_req.m_offset = offset;
                m_req.m_buf = bb;
                m_req.m_unk14 = 0;
                m_req.m_name = 0;
                m_reader.func_001BE524(req, 0);
                BedPfh pfh2(m_req.m_buf);
                int num = pfh2.getNumFile();
                m_num_chara[i] = num;
                m_first[i] = first;
                first += num;
                if (num > 0) {
                    list->func_001420F8(num, pfh2.m_name, pfh2.m_file_offset, pfh2.m_file_size, offset, 0);
                }
            }
        }
    }
    return 1;
}































































INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEE00);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEE18);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEE30);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEE50);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEE68);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEE80);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEE98);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEEB0);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEEC8);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEEE0);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEEF8);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEF10);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEF28);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEF40);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEF58);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEF70);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEF88);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEFA0);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEFB8);
INCLUDE_RODATA("asm/nonmatchings/mag/magloader", D_002EEFD0);
// NON_MATCHING: a few instructions in another order.
#ifdef NON_MATCHING
int MagCharaLoader::func_00142908()
{
    extern const char *D_00298D80[];
    MagNameList *list = &m_list;
    list->func_0014257C();
    char tmp[0x2040];
    memset(tmp, 0, sizeof(tmp));
    int pad = 0x40 - ((int)tmp - (int)tmp / 0x40 * 0x40);
    FileReader reader;
    int first = 0;
    for (int i = 0; i < 20; i++) {
        m_num_chara[i] = 0;
        m_first[i] = first;
        FileReadReq req;
        if (func_001BE84C(D_00298D80[i])) {
            new (&req) FileReadReq;
            req.m_name = D_00298D80[i];
            req.m_unk20 = 1;
            req.m_buf = tmp + pad;
            req.m_size = 0x2000;
            req.m_unk08 = 1;
            if (reader.func_001BE524(&req, 0) >= 0) {
                BedPfh pfh(req.m_buf);
                int num = pfh.getNumFile();
                m_num_chara[i] = num;
                m_first[i] = first;
                first += num;
                if (num > 0) {
                    list->func_001420F8(num, pfh.m_name, pfh.m_file_offset, pfh.m_file_size, 0, 0);
                    list->func_00141E44();
                } else {
                    ASSERT(0);
                }
            } else {




                ASSERT(0);
            }
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magloader", func_00142908);
#endif













void *MagCharaLoader::func_00142B18(int theIndex)
{
    MagNameList *list = &m_list;
    ASSERT(theIndex >= 0);
    int size = list->m_size[theIndex];

    ASSERT(size > 0);
    int offset = list->m_offset[theIndex];

    ASSERT(offset > 0);
    void *pbuf = D_006E9800.alloc(size, 1);

    ASSERT(pbuf);
    m_req.m_offset = offset;
    m_req.m_size = size;
    m_req.m_buf = pbuf;
    m_req.m_unk14 = 0;
    m_reader.func_001BE524(&m_req, 0);
    return pbuf;
}

inline int MagCharaLoader::getCat(int theIndex)
{
    int i;
    for (i = 19; i > 0; i--) {
        if (m_num_chara[i] && theIndex >= m_first[i]) {
            break;
        }
    }
    return i;
}

int MagCharaLoader::func_00142C2C(int theIndex)
{
    return getCat(theIndex);
}


int MagCharaLoader::func_00142C88(int theID)
{
    int no = theID / 1024;
    if (!(theID >= 0 && theID < (0x5800))) {
        ASSERT(theID >= 0 && theID < (0x5800));
        return -1;
    }
    signed char table[] = { 2, -1, 4, 3, 7, 5, 6, -1, 0, 1, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    int n = no;
    no = theID - (n << 10);
    int cat = table[n];



























    ASSERT(cat >= 0);

    ASSERT(no < m_num_chara[cat]);
    return m_first[cat] + no;
}

int MagCharaLoader::func_00142DAC(int theIndex)
{
    int i = getCat(theIndex);
    short table[] = {
        0x2000, 0x2400, 0x0000, 0x0C00, 0x0800, 0x1400, 0x1800, 0x1000, 0x2800, 0x2C00,
        0x3000, 0x3400, 0x3800, 0x3C00, 0x4000, 0x4400, 0x4800, 0x4C00, 0x5000, 0x5400
    };
    return table[i] + (theIndex - m_first[i]);
}

void MagCharaLoader::func_00142E84()
{
    new (&m_reader) FileReader;
    m_list.func_0014257C();
    for (int i = 0; i < 20; i++) {
        m_num_chara[i] = 0;
        m_first[i] = 0;
    }
}

int MagMapLoader::func_00142ED8()
{
    FileReadReq *req = &m_req;
    MagNameList *list = &m_list;
    new (req) FileReadReq;
    list->func_0014257C();
    char tmp[0x2040];
    memset(tmp, 0, sizeof(tmp));
    m_req.m_unk08 = 1;
    m_req.m_name = "data/bg/mapunit.bin";
    m_req.m_size = 0x2000;
    m_req.m_buf = (void *)((int)tmp / 0x40 * 0x40 + 0x40);
    m_reader.func_001BE524(req, 0);
    BedPfh pfh(m_req.m_buf);
    list->func_00141F54(pfh.getNumFile(), pfh.m_name, pfh.m_file_offset, pfh.m_file_size, 0);
    return 1;
}





































































void *MagMapLoader::func_00142FD0(const char *theName)
{
    ASSERT(theName);
    MagNameList *list = &m_list;
    int idx = list->func_00142500(theName);

    ASSERT(idx >= 0);
    int size = list->m_size[idx];

    ASSERT(size > 0);
    int offset = list->m_offset[idx];

    ASSERT(offset > 0);
    void *pbuf = D_006E9800.alloc(size, 1);

    ASSERT(pbuf);
    m_req.m_offset = offset;
    m_req.m_size = size;
    m_req.m_buf = pbuf;
    m_req.m_unk14 = 0;
    m_reader.func_001BE524(&m_req, 0);
    return pbuf;
}
