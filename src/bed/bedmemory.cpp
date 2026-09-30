// bed/bedmemory.cpp: the game's heaps (BedMemory). A heap is one buffer
// (filled with "$RUNTIME") cut into blocks, each after a BEDMEMHEADER;
// blocks are found first-fit from the bottom or the top, and remember the
// file and line that asked for them.
//
// 14 of 17 functions match. init, shrink and cutHead are still the game's
// asm; their C++ (under NON_MATCHING) only differs in register allocation
// and scheduling details. Until they match, .data/.bss stay in asm and the
// strings shared with them are INCLUDE_RODATA symbols (ASSERT_FILE,
// ASSERT_S). Method names are ours; BEDMEMHEADER and m_* names are original.

// Strings the asm functions share with the C++ ones (INCLUDE_RODATA).
#define ASSERT_FILE D_002E5340
extern const char D_002E5340[];     // "bed/bedmemory.cpp"
extern const char D_002E53B0[];     // "thePtr != __null"
extern const char D_002E5500[];     // "(((int)thePtr)%4) == 0"

#include "bed/bedmemory.h"
#include "include_asm.h"
#include "sdk/stdlib.h"
#include "sdk/string.h"

// .bss, still in asm: the last block check and getInfo visited (for the
// debugger).
extern BEDMEMHEADER *D_00308244;
extern BEDMEMHEADER *D_00308248;

INCLUDE_RODATA("asm/nonmatchings/bed/bedmemory", D_002E5340);

// 0x00100354: a heap in a new malloc'd buffer.
void BedMemory::create(int theSize, int theAttr)
{
    m_unk04 = 0;
    m_attr = theAttr;
    m_buffer = 0;
    m_size = 0;
    m_own = 0;
    void *h = ::malloc((theSize >> 4) << 4);








































    ASSERT(h != __null);
    init(h, theSize, theAttr);
    m_own = 1;
    m_count = 0;
}

#ifdef NON_MATCHING
// 0x001003F8: a heap in theBuffer. Aligns it to 16 bytes, fills it with
// "$RUNTIME" and makes it one free block.
void BedMemory::init(void *theBuffer, int theSize, int theAttr)
{







    ASSERT(theBuffer != __null);
    ASSERT(theSize >= 256);
    m_attr = theAttr;
    m_unk04 = 0;
    m_buffer = 0;
    m_size = 0;
    m_own = 0;
    m_alloc = theBuffer;
    char *ptr = (char *)theBuffer;
    int size = theSize;
    int pad = (int)ptr & 15;
    if (pad != 0) {
        int n = 16 - pad;
        ptr += n;
        size -= n;
    }
    size = (size >> 4) << 4;


    ASSERT((((int)ptr) & (15) ) == 0);
    unsigned long *p = (unsigned long *)ptr;
    int n = size / sizeof(unsigned long);
    for (int i = 0; i < n; i++) {
        *p++ = 0x454D49544E555224UL;
    }
    m_size = size;
    m_buffer = (BEDMEMHEADER *)ptr;
    m_unk04 = (BEDMEMHEADER *)ptr;
    m_own = 0;
    BEDMEMHEADER *h = (BEDMEMHEADER *)ptr;
    h->m_chunk_size = size - sizeof(BEDMEMHEADER);
    h->m_header_size = sizeof(BEDMEMHEADER);
    h->m_line = -1;
    h->m_ptr = h + 1;
    h->m_flag = 0;
    h->m_prev = 0;
    h->m_next = 0;
    h->m_filename = 0;
    h->m_attr = theAttr;
}
#else
INCLUDE_ASM("asm/nonmatchings/bed/bedmemory", init__9BedMemoryPvii);
#endif

// 0x00100568
void BedMemory::destroy()
{
    if (m_own) {
        ::free(m_alloc);
    }
    m_unk04 = 0;
    m_buffer = 0;
    m_size = 0;
    m_own = 0;
}

INCLUDE_RODATA("asm/nonmatchings/bed/bedmemory", D_002E53B0);

// 0x001005AC: align the block of free header thePtr up to its alignment
// (theAttr) by growing its header. Returns the bytes moved, 0 if already
// aligned, -1 if theSize would no longer fit.
int BedMemory::alignBottom(BEDMEMHEADER *thePtr, int theSize, int theAttr)
{









    ASSERT_S(thePtr != __null, D_002E53B0);
    ASSERT(((int)thePtr & 3) == 0);

    ASSERT(theSize > 0);
    int align = theAttr & 7;
    if (align == 7) {
        align = m_attr & 7;
    }
    int gr;
    switch (align) {
    case 0:
        gr = 32;
        break;
    case 1:
        gr = 64;
        break;
    case 2:
        gr = 128;
        break;
    default:
        gr = 4;
        break;
    }
    int mod = (int)thePtr->m_ptr & (gr - 1);
    int ns = gr - mod;
    if (mod == 0) {
        thePtr->m_header_size = sizeof(BEDMEMHEADER);
        return 0;
    }
    if (thePtr->m_chunk_size < theSize + ns) {
        return -1;
    }
    int newptr = (int)thePtr->m_ptr + ns;























    ASSERT((newptr & ( gr-1)) == 0);
    thePtr->m_ptr = (void *)newptr;
    thePtr->m_header_size = ns + sizeof(BEDMEMHEADER);
    ((int *)newptr)[-1] = ns + sizeof(BEDMEMHEADER);
    thePtr->m_chunk_size -= ns;
    return ns;
}

// 0x00100714: take theSize bytes from the top of free block thePtr, as a
// new block with its own header, aligned per theAttr. Falls back to the
// bottom of the block when the top does not fit.
BEDMEMHEADER *BedMemory::alignTop(BEDMEMHEADER *thePtr, int theSize, int theAttr)
{









    ASSERT_S(thePtr != __null, D_002E53B0);
    ASSERT(((int)thePtr & 3) == 0);

    ASSERT(theSize > 0);
    int align = theAttr & 7;
    if (align == 7) {
        align = m_attr & 7;
    }
    int gr;
    switch (align) {
    case 0:
        gr = 32;
        break;
    case 1:
        gr = 64;
        break;
    case 2:
        gr = 128;
        break;
    default:
        gr = 4;
        break;
    }
    int rest = thePtr->m_chunk_size - theSize;
    int ptr = (int)thePtr->m_ptr;
    int pad = (ptr + rest) & (gr - 1);
    if (pad >= rest) {
    bottom:
        int ns = alignBottom(thePtr, theSize, theAttr);
        if (ns == 0) {
            return thePtr;
        }
        thePtr->m_header_size = ns + sizeof(BEDMEMHEADER);
        thePtr->m_ptr = (char *)thePtr->m_ptr + ns;
        ((int *)thePtr->m_ptr)[-1] = ns + sizeof(BEDMEMHEADER);
        thePtr->m_chunk_size -= ns;
        return thePtr;
    }
    rest -= pad;
    if (rest < 64) {
        goto bottom;
    }
    int size = rest - sizeof(BEDMEMHEADER);
    int total = theSize + pad;
    BEDMEMHEADER *header = (BEDMEMHEADER *)(size + ptr);





















    ASSERT((((int)(header+1)) & ( gr-1)) == 0);
    BEDMEMHEADER *next = thePtr->m_next;
    thePtr->m_chunk_size = size;
    thePtr->m_next = header;
    header->m_prev = thePtr;
    header->m_header_size = sizeof(BEDMEMHEADER);
    header->m_ptr = header + 1;
    header->m_line = -1;
    header->m_chunk_size = total;
    header->m_flag = 0;
    header->m_next = next;
    header->m_filename = 0;
    if (next != 0) {
        next->m_prev = header;
    }
    return header;
}

// 0x001008F0: the first free block, from the bottom, that fits theSize.
BEDMEMHEADER *BedMemory::findBottom(int theSize, int theAttr)
{
    for (BEDMEMHEADER *p = m_buffer; p != 0; p = p->m_next) {
        if (p->m_flag & 1) {
            continue;
        }
        if (p->m_chunk_size < theSize) {
            continue;
        }
        if (alignBottom(p, theSize, theAttr) < 0) {
            continue;
        }
        return p;
    }
    return 0;
}

// 0x00100988: the first free block, from the top, that fits theSize: the
// new block alignTop cuts from it.
BEDMEMHEADER *BedMemory::findTop(int theSize, int theAttr)
{
    BEDMEMHEADER *p = m_buffer;
    while (p != 0 && p->m_next != 0) {
        p = p->m_next;
    }
    for (; p != 0; p = p->m_prev) {
        if (p->m_flag & 1) {
            continue;
        }
        if (p->m_chunk_size < theSize) {
            continue;
        }
        BEDMEMHEADER *h = alignTop(p, theSize, theAttr);
        if (h != 0) {
            return h;
        }
    }
    return 0;
}

// 0x00100A3C: a zeroed block of theSize bytes (rounded up to 16), or 0.
void *BedMemory::alloc(int theSize, int theAttr)
{































    ASSERT(m_size > 0);
    ASSERT(m_buffer > 0);



    ASSERT(theSize > 0);
    int top = (theAttr & 0x1C0) == 0x100;
    int size = (theSize + 15) >> 4 << 4;
    BEDMEMHEADER *p;
    if (top) {
        p = findTop(size, theAttr);
    } else {
        p = findBottom(size, theAttr);
    }
    if (p == 0) {
        check(0);














        ASSERT(0);
        return 0;
    }
    p->m_flag = 1;
    // The second ASSERT has = for ==: always true, and it sets the header
    // size (its string is in .rodata, its call is not).
    if (top) {











        ASSERT(p->m_chunk_size >= theSize);
        ASSERT(p->m_header_size = sizeof( BEDMEMHEADER ));
        ASSERT(p->m_next != p);
    } else {
        int rest = p->m_chunk_size - size;
        if (rest >= 64) {
            BEDMEMHEADER *p2 = (BEDMEMHEADER *)((char *)p->m_ptr + size);
            p->m_chunk_size = size;
            p2->m_chunk_size = rest - sizeof(BEDMEMHEADER);
            p2->m_line = -1;
            p2->m_ptr = p2 + 1;
            p2->m_header_size = sizeof(BEDMEMHEADER);
            p2->m_flag = 0;
            p2->m_filename = 0;
            p2->m_prev = p;
            p2->m_next = p->m_next;
            if (p2->m_next != 0) {
                p2->m_next->m_prev = p2;
            }
            p->m_next = p2;













            ASSERT(p2->m_next != p2);
            ASSERT(p->m_next != p);
        }
    }
    memset(p->m_ptr, 0, p->m_chunk_size);
    m_count++;
    return p->m_ptr;
}

// 0x00100C84: alloc, noting in the header who asked (file, line, tag).
void *BedMemory::alloc(int theSize, const char *theFile, int theLine, int theId, int theAttr)
{
    void *ptr = alloc(theSize, theAttr);
    if (ptr != 0) {
        BEDMEMHEADER *h = (BEDMEMHEADER *)((char *)ptr - ((int *)ptr)[-1]);
        h->m_line = theLine;
        h->m_filename = theFile;
        h->m_id = theId;
    }
    return ptr;
}

// 0x00100CE4: the header of the block at thePtr.
BEDMEMHEADER *BedMemory::getHeader(void *thePtr)
{
    int headersize = ((int *)thePtr)[-1];
    BEDMEMHEADER *h = (BEDMEMHEADER *)((char *)thePtr - headersize);




















    ASSERT(h->m_header_size == headersize);
    return h;
}

#ifdef NON_MATCHING
// 0x00100D30: shrink the block at thePtr to theNewSize, in place; the rest
// becomes a free block (merged with the next one if that is free). When
// the next block is in use its m_prev is not updated (as in the game).
void *BedMemory::shrink(void *thePtr, int theNewSize, int)
{





    ASSERT(thePtr != __null);
    ASSERT(theNewSize > 0);
    BEDMEMHEADER *h = getHeader(thePtr);




    ASSERT((((int)thePtr)%4) == 0);
    int newsize = (theNewSize + 15) >> 4 << 4;
    int rest = h->m_chunk_size - newsize;
    if (rest >= 64) {
        BEDMEMHEADER *next = h->m_next;
        BEDMEMHEADER *h2 = (BEDMEMHEADER *)((char *)h->m_ptr + newsize);
        h->m_chunk_size = newsize;
        if (next == 0) {
            h->m_next = h2;
            h2->m_chunk_size = rest - sizeof(BEDMEMHEADER);
            h2->m_line = -1;
            h2->m_ptr = h2 + 1;
            h2->m_header_size = sizeof(BEDMEMHEADER);
            h2->m_prev = h;
            h2->m_next = 0;
            h2->m_flag = 0;
            h2->m_filename = 0;
            h2->m_id = 0;
        } else if (next->m_flag == 0) {
            rest += next->m_chunk_size + next->m_header_size;
            h->m_next = h2;
            h2->m_line = -1;
            h2->m_ptr = h2 + 1;
            h2->m_header_size = sizeof(BEDMEMHEADER);
            h2->m_chunk_size = rest - sizeof(BEDMEMHEADER);
            h2->m_prev = h;
            h2->m_flag = 0;
            h2->m_filename = 0;
            h2->m_id = 0;
            h2->m_next = next->m_next;
            if (h2->m_next != 0) {
                h2->m_next->m_prev = h2;
            }
        } else {
            h->m_next = h2;
            h2->m_next = next;
            h2->m_chunk_size = rest - sizeof(BEDMEMHEADER);
            h2->m_line = -1;
            h2->m_ptr = h2 + 1;
            h2->m_header_size = sizeof(BEDMEMHEADER);
            h2->m_prev = h;
            h2->m_flag = 0;
            h2->m_filename = 0;
            h2->m_id = 0;
        }
    }
    return thePtr;
}
#else
INCLUDE_ASM("asm/nonmatchings/bed/bedmemory", shrink__9BedMemoryPvii);
#endif

INCLUDE_RODATA("asm/nonmatchings/bed/bedmemory", D_002E5500);

#ifdef NON_MATCHING
// 0x00100ECC: move the start of the block at theOldPtr up to theNewPtr;
// the part cut off becomes a free block (merged with the previous one if
// that is free). newsize subtracts both pointers (as in the game).
void *BedMemory::cutHead(void *theOldPtr, void *theNewPtr)
{
























    ASSERT(theOldPtr);
    ASSERT(theNewPtr);
    ASSERT(theNewPtr > theOldPtr);
    BEDMEMHEADER *h = getHeader(theOldPtr);




    ASSERT((((int)theNewPtr)%4) == 0);
    int oldsize = h->m_chunk_size;
    int newsize = oldsize - (int)theNewPtr - (int)theOldPtr;

    ASSERT(newsize > 0);
    if (oldsize - newsize < 64) {
        return theOldPtr;
    }
    BEDMEMHEADER *h2 = (BEDMEMHEADER *)theNewPtr - 1;
    *h2 = *h;
    h2->m_chunk_size = newsize;
    h2->m_ptr = theNewPtr;
    h2->m_header_size = sizeof(BEDMEMHEADER);
    h2->m_prev = h;
    h->m_chunk_size = (int)h2 - (int)h - sizeof(BEDMEMHEADER);
    BEDMEMHEADER *prev = h->m_prev;
    h->m_ptr = h + 1;
    h->m_line = -1;
    h->m_header_size = sizeof(BEDMEMHEADER);
    h->m_next = h2;
    h->m_attr = 0;
    h->m_flag = 0;
    h->m_filename = 0;
    if (prev != 0 && prev->m_flag == 0) {
        prev->m_next = h2;
        prev->m_chunk_size += h->m_chunk_size + h->m_header_size;
        h->m_next->m_prev = prev;
    }
    return theNewPtr;
}
#else
INCLUDE_ASM("asm/nonmatchings/bed/bedmemory", cutHead__9BedMemoryPvT1);
#endif

// 0x001010A4: resize the block at thePtr, in place when the next block is
// free and big enough, else by alloc + memcpy + free. When it grows in
// place and splits the next block, h->m_next is not updated (as in the
// game).
void *BedMemory::realloc(void *thePtr, int theNewSize)
{
    if (thePtr == 0) {
        if (theNewSize > 0) {
            return alloc(theNewSize, -1);
        }




























        ASSERT(0);
        return 0;
    }
    if (theNewSize <= 0) {
        free(thePtr);
        return 0;
    }
    BEDMEMHEADER *h = getHeader(thePtr);













    ASSERT_S((((int)thePtr)%4) == 0, D_002E5500);
    int oldsize = h->m_chunk_size;
    int newsize = (theNewSize + 15) >> 4 << 4;
    if (newsize == oldsize) {
        return thePtr;
    }
    if (newsize < oldsize) {
        return shrink(thePtr, theNewSize, 0);
    }
    BEDMEMHEADER *next = h->m_next;
    int mode = 0;
    if (next != 0) {
        if (next->m_flag != 0) {
            mode = 1;
        } else {
            mode = 2;
            if (newsize < oldsize + (next->m_chunk_size + next->m_header_size)) {
                mode = 3;
            }
        }
    }
    if (mode < 3) {
        void *p = alloc(theNewSize, -1);
        if (p != 0) {
            memcpy(p, thePtr, oldsize);
            free(thePtr);
        }
        return p;
    }
    int ns = next->m_chunk_size + next->m_header_size;














    ASSERT(newsize < oldsize + ns);
    int rest = oldsize + ns - newsize;
    if (rest < 64) {
        h->m_chunk_size += ns;
        h->m_next = next->m_next;
        if (next->m_next != 0) {
            next->m_next->m_prev = h;
        }
    } else {
        BEDMEMHEADER *h2 = (BEDMEMHEADER *)((char *)h->m_ptr + newsize);
        h->m_chunk_size = newsize;
        h2->m_chunk_size = rest - sizeof(BEDMEMHEADER);
        h2->m_line = -1;
        h2->m_ptr = h2 + 1;
        h2->m_header_size = sizeof(BEDMEMHEADER);
        h2->m_prev = h;
        h2->m_flag = 0;
        h2->m_filename = 0;
        h2->m_id = 0;
        h2->m_next = next->m_next;
        if (next->m_next != 0) {
            next->m_next->m_prev = h2;
        }
    }
    return thePtr;
}

// 0x00101328: free the block at thePtr, merging it with free neighbours.
void BedMemory::free(void *thePtr)
{










    ASSERT_S(thePtr != __null, D_002E53B0);
    BEDMEMHEADER *h = getHeader(thePtr);
    int total = h->m_header_size;




















    ASSERT(h->m_flag == 1);
    BEDMEMHEADER *next = h->m_next;
    total += h->m_chunk_size;
    h->m_line = -1;
    h->m_flag = 0;
    h->m_filename = 0;
    h->m_id = 0;
    if (next != 0) {









        ASSERT(next != next->m_next);
        if (next->m_flag == 0) {
            total += next->m_header_size + next->m_chunk_size;
            next = next->m_next;
        }
    }
    h->m_header_size = sizeof(BEDMEMHEADER);
    h->m_chunk_size = total - sizeof(BEDMEMHEADER);
    h->m_ptr = h + 1;
    h->m_next = next;
    if (next != 0) {
        next->m_prev = h;














        ASSERT(((int)next) == ((int)h)+total);
    }
    BEDMEMHEADER *prev = h->m_prev;
    if (prev != 0) {
        if (prev->m_next != h) {
            check(0);








            ASSERT(prev->m_next == h);
        }
        if (prev->m_flag == 0) {
            total += prev->m_header_size + prev->m_chunk_size;
            prev->m_next = h->m_next;
            prev->m_header_size = sizeof(BEDMEMHEADER);
            prev->m_ptr = prev + 1;
            prev->m_chunk_size = total - sizeof(BEDMEMHEADER);
            if (prev->m_next != 0) {
                prev->m_next->m_prev = prev;
            }





            ASSERT(prev != prev->m_next);
        }
    }
    m_count--;
}

// 0x00101518: walk the blocks checking the list; theMode 2 also counts
// broken back links, theMode 1 skips blocks in use. The last block
// visited stays in a static (for the debugger).
void BedMemory::check(int theMode)
{
    int errcnt = 0;
    for (BEDMEMHEADER *p = m_buffer; p != 0; D_00308244 = p, p = p->m_next) {
        if (theMode == 1 && p->m_flag != 0) {
            continue;
        }
        if (0) {
            // Debug output the game compiled out: only its strings are left
            // in .rodata (Shift-JIS white circle and black square).
            const char *mark = p->m_flag == 0 ? "\x81\x9b" : "\x81\xa1";
            ASSERT(p->m_filename);
            ASSERT(p->m_filename == __null);
        }
        if (theMode == 2) {
            BEDMEMHEADER *prev = p->m_prev;
            BEDMEMHEADER *next = p->m_next;
            if (prev != 0 && prev->m_next != p) {
                errcnt++;
            }
            if (next != 0 && next->m_prev != p) {
                errcnt++;
            }
        }














































































        ASSERT(p != p->m_next);
    }

    ASSERT(errcnt == 0);
}

// 0x001015FC: free space (total and largest block) and size; checks each
// block on the way.
void BedMemory::getInfo(BedMemoryInfo *theInfo)
{
    int maxfree = 0;
    int total = 0;
    for (BEDMEMHEADER *p = m_buffer; p != 0; p = p->m_next) {
        if ((int)p & 3) {
            check(0);














            ASSERT(0);
        }
        if (p->m_flag != 0 && p->m_flag != 1) {
            check(0);




            ASSERT(0);
        }
        if (p->m_flag == 0) {
            total += p->m_chunk_size;
            if (maxfree < p->m_chunk_size) {
                maxfree = p->m_chunk_size;
            }
        }




        ASSERT(p != p->m_next);
        D_00308248 = p;
    }
    if (theInfo != 0) {
        theInfo->m_size = m_size;
        theInfo->m_maxFree = maxfree;
        theInfo->m_totalFree = total;
    }
}

// 0x00101718
BedMemory::BedMemory()
{
    m_buffer = 0;
    m_unk04 = 0;
    m_alloc = 0;
    m_size = 0;
    m_attr = 0;
    m_count = 0;
    m_own = 0;
}
