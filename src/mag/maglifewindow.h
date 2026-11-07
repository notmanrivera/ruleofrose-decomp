// mag/maglifewindow.h: MagLifePos (a life with a position) and MagLifeWindow
// (a 2D window). The virtual order comes from their vtables. Only what the
// decompiled code uses is declared, and most field names are ours.
#ifndef MAG_MAGLIFEWINDOW_H
#define MAG_MAGLIFEWINDOW_H

#include "mag/maglifeman.h"
#include "dog/dogentity.h"

class BedPad;

// The window's text buffer (a character grid). The name is from the assert
// string m_fntman; the fields from MagLifeWindow::func_00130778.
struct MagFntMan {
    unsigned char m_unk00[0x10];
    int m_buf_w;                    // +0x10
    int m_buf_h;                    // +0x14
    unsigned char m_unk18[0x10];
    int m_unk28;                    // +0x28
    int m_unk2C;
    int m_unk30;                    // +0x30
    int m_unk34;                    // +0x34
    int m_ch_w;                     // +0x38
    int m_ch_h;                     // +0x3C
};

class MagLifePos : public MagLife {
public:
    unsigned char m_unk18[0x18];    // +0x18

    virtual void updatePos();
    virtual void updateSpeed();
    virtual void move();
};

class MagLifeWindow : public MagLifePos {
public:
    DogVector m_pos;                // +0x30
    unsigned char m_unk40[0x40];    // +0x40
    int m_unk80;                    // +0x80
    int m_unk84;                    // +0x84
    int m_unk88;                    // +0x88
    int m_unk8C;                    // +0x8C
    int m_unk90;                    // +0x90
    int m_w;                        // +0x94
    int m_h;                        // +0x98
    unsigned char m_unk9C[0x10];    // +0x9C
    int m_unkAC;                    // +0xAC
    float m_unkB0;                  // +0xB0
    float m_unkB4;                  // +0xB4
    float m_unkB8;                  // +0xB8
    float m_unkBC;                  // +0xBC
    int m_font_tex;                 // +0xC0
    MagFntMan *m_fntman;            // +0xC4
    int m_ch_w;                     // +0xC8
    int m_ch_h;                     // +0xCC
    int m_buf_w;                    // +0xD0
    int m_buf_h;                    // +0xD4
    unsigned char m_unkD8[8];       // +0xD8

    MagLifeWindow() asm("func_001308BC");

    virtual int processPad(const BedPad &thePad0, const BedPad &thePad1);
    void func_0012FE30(int theW, int theH) asm("func_0012FE30");
    void func_00130778(MagFntMan *thefontManager) asm("func_00130778");
};

class MagLifeWindowDebug : public MagLifeWindow {
public:
    MagLifeWindowDebug() asm("func_00144214");
};

#endif
