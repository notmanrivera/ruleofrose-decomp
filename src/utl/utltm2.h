// utl/utltm2.h: the TIM2 ("TM2") image format as utl/utltm2.cpp reads it.
// Names follow the public TIM2 layout, except Pictures, which an assert
// string gives.
#ifndef UTL_UTLTM2_H
#define UTL_UTLTM2_H

// File header (0x10 bytes, or 0x80 when FormatID is 1).
struct Tm2Header {
    char FileID[4];                 // +0x00: "TIM2"
    unsigned char FormatVersion;    // +0x04
    unsigned char FormatID;         // +0x05: 0 = 16-byte, 1 = 128-byte alignment
    unsigned short Pictures;        // +0x06
};

// Header of one picture; its image data follows at HeaderSize, then the
// palette (CLUT).
struct Tm2Picture {
    int TotalSize;                  // +0x00
    int ClutSize;                   // +0x04
    int ImageSize;                  // +0x08
    unsigned short HeaderSize;      // +0x0C
    unsigned short ClutColors;      // +0x0E
    unsigned char PictureFormat;    // +0x10
    unsigned char MipMapTextures;   // +0x11
    unsigned char ClutType;         // +0x12: low 6 bits: 1 = 16 bit, 2 = 24 bit, 3 = 32 bit
    unsigned char ImageType;        // +0x13: 1 = 16 bit, 2 = 24, 3 = 32, 4 = 4 bit, 5 = 8 bit
};

#endif
