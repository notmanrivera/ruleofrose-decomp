// mag/magloader.h: the disc catalogues of characters and map units: packs on
// the disc, with one name list per catalogue. Class and most field names are
// ours; m_data, m_num_chara and the argument names come from the asserts.
#ifndef MAG_MAGLOADER_H
#define MAG_MAGLOADER_H

#include "ror.h"
#include "utl/filereader.h"

// Names, sizes and offsets of the files of a pack, in one block of the heap.
class MagNameList {
public:
    int m_num;                      // +0x00
    void *m_data;                   // +0x04
    int m_data_size;                // +0x08
    int *m_size;                    // +0x0C
    int *m_offset;                  // +0x10
    const char **m_name;            // +0x14
    unsigned char *m_len;           // +0x18
    int m_name_size;                // +0x1C
    char *m_name_buf;               // +0x20

    int getSize(int n) { return m_size[n]; }
    int getOffset(int n) { return m_offset[n]; }
    void func_00141E44() asm("func_00141E44");
    int func_00141E78(int theNum, int theNameSize) asm("func_00141E78");
    int func_00141E90(int *theLen, int *theOffset, int theNum, const char *theNameBuf)
        asm("func_00141E90");
    int func_00141F54(int theNum, const char *theNameBuf, const int *theOffset,
                      const int *theSize, int theBase) asm("func_00141F54");
    void func_001420F8(int theNum, const char *theNameBuf, const int *theOffset,
                       const int *theSize, int theBase, int theSort) asm("func_001420F8");
    int func_00142500(const char *theName) asm("func_00142500");
    void func_0014257C() asm("func_0014257C");
    void func_0014259C() asm("func_0014259C");
};

class MagCharaLoader {
public:
    FileReader m_reader;            // +0x00
    FileReadReq m_req;              // +0x08
    int m_num_chara[20];            // +0x2C
    int m_first[20];                // +0x7C
    MagNameList m_list;             // +0xCC

    int func_001425DC() asm("func_001425DC");
    int func_00142908() asm("func_00142908");
    void *func_00142B18(int theIndex) asm("func_00142B18");
    int getCat(int theIndex);
    int func_00142C2C(int theIndex) asm("func_00142C2C");
    int func_00142C88(int theID) asm("func_00142C88");
    int func_00142DAC(int theIndex) asm("func_00142DAC");
    void func_00142E84() asm("func_00142E84");
};

class MagMapLoader {
public:
    FileReader m_reader;            // +0x00
    FileReadReq m_req;              // +0x08
    MagNameList m_list;             // +0x2C

    int func_00142ED8() asm("func_00142ED8");
    void *func_00142FD0(const char *theName) asm("func_00142FD0");
};

#endif
