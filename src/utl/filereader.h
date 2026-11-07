// utl/filereader.h: the game's disc file reader (code at 0x001BE2CC-0x001BE768,
// between mnu/mnuSelectLanguage and game/gamman). Names are ours; the layout
// comes from how the callers fill the request (dog/dogactor, debug/naga_debug).
#ifndef UTL_FILEREADER_H
#define UTL_FILEREADER_H

// A disc file read request.
struct FileReadReq {
    int m_unk00;                    // +0x00: -1 after construction
    int m_unk04;                    // +0x04
    int m_unk08;                    // +0x08: 1 to read
    const char *m_name;             // +0x0C: the file
    int m_offset;                   // +0x10: where to read from
    int m_unk14;                    // +0x14
    void *m_buf;                    // +0x18
    int m_size;                     // +0x1C: bytes, whole sectors
    int m_unk20;                    // +0x20

    FileReadReq();                  // 0x001BE734
};

class FileReader {
public:
    FileReadReq *m_req;             // +0x00
    int m_unk04;                    // +0x04: >= 0 while open

    FileReader();                   // 0x001BE2CC
    ~FileReader();                  // 0x001BE2DC
    int func_001BE524(FileReadReq *theReq, int theFlag);
};

#endif
