// mag/maglifewindow.h: MagLifePos (a life with a position) and MagLifeWindow
// (a 2D window). The virtual order comes from their vtables. Only what the
// decompiled code uses is declared, and most field names are ours.
#ifndef MAG_MAGLIFEWINDOW_H
#define MAG_MAGLIFEWINDOW_H

#include "mag/maglifeman.h"
#include "dog/dogentity.h"

class BedPad;

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
    unsigned char m_unk9C[0x24];    // +0x9C
    int m_font_tex;                 // +0xC0
    unsigned char m_unkC4[8];       // +0xC4
    int m_unkCC;                    // +0xCC
    unsigned char m_unkD0[0x10];    // +0xD0

    MagLifeWindow() asm("func_001308BC");

    virtual int processPad(const BedPad &thePad0, const BedPad &thePad1);
    void func_0012FE30(int theW, int theH) asm("func_0012FE30");
    void func_00130778(void *thePage) asm("func_00130778");
};

class MagLifeWindowDebug : public MagLifeWindow {
public:
    MagLifeWindowDebug() asm("func_00144214");
};

#endif
