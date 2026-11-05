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
    unsigned char m_unk30[0x90];    // +0x30
    int m_font_tex;                 // +0xC0
    unsigned char m_unkC4[0x1C];    // +0xC4

    virtual int processPad(const BedPad &thePad0, const BedPad &thePad1);
    void func_0012FE30(int theW, int theH) asm("func_0012FE30");
    void func_00130778(void *thePage) asm("func_00130778");
};

class MagLifeWindowDebug : public MagLifeWindow {
public:
    MagLifeWindowDebug() asm("func_00144214");
};

#endif
