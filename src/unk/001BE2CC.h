// unk/001BE2CC.h: FileReader / FileReadReq and font canvas structures for
// unk/001BE2CC.cpp.
#ifndef UNK_001BE2CC_H
#define UNK_001BE2CC_H

#include "target.h"

struct FileReadReq {
    int m_fd;                           // +0x00
    int m_state;                        // +0x04
    int m_unk08;                        // +0x08
    int m_path;                         // +0x0C
    int m_seekOffset;                   // +0x10
    int m_seekWhence;                   // +0x14
    int m_buf;                          // +0x18
    int m_size;                         // +0x1C
    int m_closeFlag;                    // +0x20
}; // size 0x24

class FileReader {
public:
    FileReadReq *m_req;                 // +0x00
    int m_fd;                           // +0x04

    ~FileReader();
}; // size 0x08

struct FntDataHdr {
    int m_unk00;                        // +0x00
    int m_unk04;                        // +0x04
    unsigned char m_unk08[3];           // +0x08..+0x0A
    unsigned char m_flags0B;            // +0x0B
    unsigned short m_glyphCount;        // +0x0C
    unsigned char m_cellW;              // +0x0E
    unsigned char m_cellH;              // +0x0F
    unsigned char m_bpp;                // +0x10
    unsigned char m_pad11[3];           // +0x11..+0x13
    int m_codeTblOff;                   // +0x14
    int m_unk18;                        // +0x18
    int m_metricTblOff;                 // +0x1C
    int m_bmpTblOff;                    // +0x20
}; // size 0x24

struct FntCanvas {
    int m_unk00;                        // +0x00
    int m_ownBuf;                       // +0x04
    int m_unk08;                        // +0x08
    unsigned char *m_buf;               // +0x0C
    int m_width;                        // +0x10
    int m_height;                       // +0x14
    int m_bpp;                          // +0x18
    int m_bufSize;                      // +0x1C
    int m_unk20;                        // +0x20
    int m_hasMetrics;                   // +0x24
    int m_useProp;                      // +0x28
    int m_fgColor;                      // +0x2C
    int m_fixedStep;                    // +0x30
    int m_propStep;                     // +0x34
    int m_cellW;                        // +0x38
    int m_cellH;                        // +0x3C
    int m_fntBpp;                       // +0x40
    int m_glyphCount;                   // +0x44
    int m_totalBmpSize;                 // +0x48
    int m_rowBytes;                     // +0x4C
    int m_glyphBytes;                   // +0x50
    FntDataHdr *m_fnt;                  // +0x54
    int m_codeTbl;                      // +0x58
    int m_metricTbl;                    // +0x5C
    int m_bmpTbl;                       // +0x60
    int m_bgColor;                      // +0x64
    int m_alphaFlag;                    // +0x68
}; // size 0x6C

STATIC_ASSERT(sizeof(FileReadReq) == 0x24, FileReadReq_size);
STATIC_ASSERT(sizeof(FileReader) == 0x08, FileReader_size);
STATIC_ASSERT(sizeof(FntDataHdr) == 0x24, FntDataHdr_size);
STATIC_ASSERT(sizeof(FntCanvas) == 0x6C, FntCanvas_size);

#endif // UNK_001BE2CC_H
