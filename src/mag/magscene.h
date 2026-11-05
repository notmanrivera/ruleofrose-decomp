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
#include "bed/bedsubmode.h"
#include "mag/maglifeman.h"

class BedPad;
class MagLifeWindow;

// The 0x6C bytes MagScene keeps per window; func_001BEBEC fills them.
struct MagWindowPage {
    unsigned char m_unk00[0x6C];
};

// One line of a parameter text, split by txtParse (unk/001056E8.cpp).
struct TxtToken {
    char *m_name;
    int m_type;
    union {
        int m_int;
        float m_float;
        char *m_str;
    };
};
int txtParse(TxtToken *theToken, int theMax, char *theText);
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
    void func_0011B964(int theID, float theValue) asm("func_0011B964");
    void func_0012CDB0();           // mag/maglifepceff.cpp: ASSERT(0) stubs
    void func_0012CDDC();
    void func_0012CE08();
};

class MagScene {
public:
    unsigned char m_unk00000[0x2040];
    int m_shadow_type;              // +0x02040
    void *m_shadow_light;           // +0x02044
    unsigned char m_unk02048[8];
    unsigned char m_light_pool[0x250]; // +0x02050: DogLightPool (and what follows it)
    float m_opt_shadow_blackness;   // +0x022A0
    float m_opt_shadow_offset;      // +0x022A4
    float m_opt_ambient_extra;      // +0x022A8
    unsigned char m_unk022AC[0x10];
    int m_dbg_window[4];            // +0x022BC
    int m_unk022CC;                 // +0x022CC
    BedSubMode m_sub_mode;          // +0x022D0
    MagLifeManager m_life_man;      // +0x02330
    MagLifeWindow *m_window[4];     // +0x02734
    MagWindowPage m_unk02744[4];    // +0x02744
    int m_unk028F4[4];              // +0x028F4
    int m_unk02904;                 // +0x02904
    void *m_unk02908;               // +0x02908
    unsigned char m_unk0290C[0x14];
    DogActor m_actor[MAG_MAX_ACTOR]; // +0x02920
    int m_unk29120[0x200];          // +0x29120: per model (func_00138ED0's result)
    unsigned char m_unk29920[0x10B0];
    int m_shadow[4];                // +0x2A9D0
    int m_shadow_direct_on;         // +0x2A9E0
    void *m_shadow_direct;          // +0x2A9E4
    int m_unk2A9E8[2];
    int m_shadow_point_on;          // +0x2A9F0
    void *m_shadow_point;           // +0x2A9F4
    unsigned char m_unk2A9F8[0x2BC];
    float m_opt_zoom_ratio;         // +0x2ACB4
    unsigned char m_unk2ACB8[0xE4];
    int m_unk2AD9C;                 // +0x2AD9C
    DogVector m_unk2ADA0;           // +0x2ADA0
    DogVector m_unk2ADB0;           // +0x2ADB0
    MagLifePC m_pc;                 // +0x2ADC0
    int m_unk2AEA0;                 // +0x2AEA0
    int m_unk2AEA4;                 // +0x2AEA4
    unsigned char m_unk2AEA8[0xE78];
    int m_unk2BD20;                 // +0x2BD20
    unsigned char m_unk2BD24[0x179F4];
    int m_unk43718;                 // +0x43718
    TxtToken m_option_bucket[16];   // +0x4371C
    unsigned char m_unk437DC[0x41D24];

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
    MagLifeWindow *func_00143114(int theLevel) asm("func_00143114");
    void func_0014313C(const BedPad &thePad0, const BedPad &thePad1) asm("func_0014313C");
    int func_0014324C(int theLevel) asm("func_0014324C");
    void func_00143430(int theLevel) asm("func_00143430");
    void func_0013C29C();
    void func_0013C2EC(const DogVector &thePos, const DogVector &theDir);
    void func_0013C328(char *theText) asm("func_0013C328");
    void func_0013CAF0(int theA, int theB);
    void func_0013D5AC(int *theOut);
    void func_0013F07C(int theA = 0) asm("func_0013F07C");
    void func_0013F09C() asm("func_0013F09C");
    int func_0013F0C0() asm("func_0013F0C0");
    void func_0013F114() asm("func_0013F114");
    void func_0013F130() asm("func_0013F130");
    int func_0013F144() asm("func_0013F144");
    int func_0013F194() asm("func_0013F194");
    void func_0013F1E4() asm("func_0013F1E4");
    void func_0013F208() asm("func_0013F208");
    int func_0013F210() asm("func_0013F210");
    int func_0013F280(int theType, const int *theParam, int theA) asm("func_0013F280");
    int func_0013F444(int theNo) asm("func_0013F444");
    void func_0013F458(int theNo) asm("func_0013F458");
    void func_0013F49C(int theNo) asm("func_0013F49C");
    void func_0013F4D0(int theNo) asm("func_0013F4D0");
    void func_0013F528(int *theNum, int theNo);
    void func_0013F658(int *theData) asm("func_0013F658");
    void func_0013F8E4() asm("func_0013F8E4");
    void func_0013FB3C(int theD, int theS) asm("func_0013FB3C");
    void func_0013FBE4(int theLight, int theNo) asm("func_0013FBE4");
    void func_0013F980(int theType, int theNo, int theMode, float *theColor, int theA);
    void func_0013FA50(int theType, int theNo, int theMode, float *theColor, int theA);
    int func_0013FE64(int theType, int theMask);
    void func_0013FF00(int theNo);
};

#endif
