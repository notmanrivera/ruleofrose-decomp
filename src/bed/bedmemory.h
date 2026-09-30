// bed/bedmemory.h: the game's heaps (BedMemory).
//
// A heap is one buffer cut into blocks, each preceded by a BEDMEMHEADER;
// the headers form a doubly linked list in address order. Original names:
// BEDMEMHEADER (from an assert string, sizeof( BEDMEMHEADER )), m_buffer,
// m_size, m_next, m_chunk_size, m_flag, m_filename, m_header_size and the
// parameter names; everything else is ours, including the class name
// (after the file, like BedPad).
#ifndef BED_BEDMEMORY_H
#define BED_BEDMEMORY_H

#include "ror.h"

struct BEDMEMHEADER {
    BEDMEMHEADER *m_next;       // +0x00: next block (higher address)
    BEDMEMHEADER *m_prev;       // +0x04
    int m_chunk_size;           // +0x08: bytes at m_ptr
    void *m_ptr;                // +0x0C: the block, m_header_size bytes on
    short m_attr;               // +0x10: the heap's attributes (first block)
    short m_flag;               // +0x12: 1 = in use
    short m_id;                 // +0x14: tag given to BedMemory::alloc
    short m_line;               // +0x16: __LINE__ given to alloc, -1 if none
    const char *m_filename;     // +0x18: __FILE__ given to alloc
    int m_header_size;          // +0x1C: bytes from the header to m_ptr
};

// The int right before every block is its header size, so a block pointer
// leads back to its header (BedMemory::getHeader).

// Attributes (theAttr): bits 0-2 pick the block alignment (0: 32, 1: 64,
// 2: 128, 3-6: 4 bytes, 7: the heap's own m_attr); bits 6-8 = 0x100
// allocates from the top of the heap instead of the bottom.

// BedMemory::getInfo's result.
struct BedMemoryInfo {
    int m_maxFree;              // largest free block
    int m_totalFree;            // free bytes
    int m_size;                 // heap size
};

class BedMemory {
public:
    BEDMEMHEADER *m_buffer;     // +0x00: first block
    BEDMEMHEADER *m_unk04;      // +0x04
    void *m_alloc;              // +0x08: the buffer as given (before aligning)
    int m_size;                 // +0x0C
    int m_attr;                 // +0x10
    int m_count;                // +0x14: blocks in use
    int m_own;                  // +0x18: m_alloc came from malloc (create)

    BedMemory();
    void create(int theSize, int theAttr);
    void init(void *theBuffer, int theSize, int theAttr);
    void destroy();
    int alignBottom(BEDMEMHEADER *thePtr, int theSize, int theAttr);
    BEDMEMHEADER *alignTop(BEDMEMHEADER *thePtr, int theSize, int theAttr);
    BEDMEMHEADER *findBottom(int theSize, int theAttr);
    BEDMEMHEADER *findTop(int theSize, int theAttr);
    void *alloc(int theSize, int theAttr);
    void *alloc(int theSize, const char *theFile, int theLine, int theId, int theAttr);
    BEDMEMHEADER *getHeader(void *thePtr);
    void *shrink(void *thePtr, int theNewSize, int = 0);   // realloc passes 0; unused
    void *cutHead(void *theOldPtr, void *theNewPtr);
    void *realloc(void *thePtr, int theNewSize);
    void free(void *thePtr);
    void check(int theMode);
    void getInfo(BedMemoryInfo *theInfo);
};

#endif
