// mag/magscene.h (a guess): MagScene, the game world MagSystem owns
// (+0x12540): the actors, the lights, the camera and the player. The class
// name comes from mnuBase::setScene(MagScene *); its methods are still asm
// (mag/magscene*), so they are named by address. Only what decompiled code
// uses is declared, and the field names are ours.
#ifndef MAG_MAGSCENE_H
#define MAG_MAGSCENE_H

#include "ror.h"
#include "dog/dogactor.h"
#include "sdk/libgraph.h"

class BedPad;
struct I3dDraw;

// The scene's actors (the characters, the dog...).
#define MAG_MAX_ACTOR 128

// MagLifePC (mag/maglifepc*.cpp), the player: only what MagSystem reads.
class MagLifePC {
public:
    int m_unk00;                    // +0x00: the player's state
    int m_unk04;                    // +0x04
    int m_unk08;                    // +0x08
    int m_unk0C;                    // +0x0C
    unsigned char m_unk10[0xD0];    // +0x10

    int func_0011E080();
};

class MagScene {
public:
    unsigned char m_unk00000[0x22CC];
    int m_unk022CC;                 // +0x022CC
    unsigned char m_unk022D0[0x650];
    DogActor m_actor[MAG_MAX_ACTOR]; // +0x02920
    int m_unk29120[0x200];          // +0x29120: per model (func_00138ED0's result)
    unsigned char m_unk29920[0x14A0];
    MagLifePC m_pc;                 // +0x2ADC0
    int m_unk2AEA0;                 // +0x2AEA0
    int m_unk2AEA4;                 // +0x2AEA4
    unsigned char m_unk2AEA8[0xE78];
    int m_unk2BD20;                 // +0x2BD20
    unsigned char m_unk2BD24[0x597DC];

    MagScene();
    ~MagScene();
    DogActor *getActor(int n) { return &m_actor[n]; }
    void setModelFlag(int n, int f) { m_unk29120[n] |= f; }
    void func_00131840();
    void func_00131A28();
    void func_00131B90(I3dDraw *theDraw);
    void func_001316B8(int theNo, int theType);
    void func_00131790(int theA, int theB);
    void func_001327DC(BedPad *thePad0, BedPad *thePad1);
    void func_00134944(int theA, int *theParam);
    void func_00135234(int theA, int theB, int theC, int theD, int theE);
    void func_0013604C();
    void func_001377F0(I3dDraw *theDraw, int theA, int theB, int theC);
    void func_00138BC4(I3dDraw *theDraw, int theA, int theB, const char *thePack);
    int func_00138ED0(I3dDraw *theDraw, int theA, const char *thePack);
    void func_001390D4(int theA, int theB, int theC);
    void func_0013910C(int theA, int theB, int theC);
    void func_0013BCC0(I3dDraw *theDraw, sceGsDBuff *theDb, int theFrame);
    void func_0013C29C();
    void func_0013C2EC(const DogVector &thePos, const DogVector &theDir);
    void func_0013CAF0(int theA, int theB);
    void func_0013D5AC(int *theOut);
    void func_0013F528(int *theParam, int theA);
    void func_0013F980(int theType, int theNo, int theMode, float *theColor, int theA);
    void func_0013FA50(int theType, int theNo, int theMode, float *theColor, int theA);
    int func_0013FE64(int theType, int theA);
};

#endif
