// mag/magscene.h (a guess): MagScene, the game world MagSystem owns
// (+0x12540): the actors, the lights, the camera and the player. The class
// name comes from mnuBase::setScene(MagScene *); its methods are still asm
// (mag/magscene*), so they are named by address. Only what decompiled code
// uses is declared, and the field names are ours.
#ifndef MAG_MAGSCENE_H
#define MAG_MAGSCENE_H

#include "ror.h"
#include "dog/dogactor.h"
class DogCamera;
#include "dog/dogtexinfo.h"
#include "sdk/libgraph.h"
#include "bed/bedsubmode.h"
#include "mag/maglifeman.h"
#include "mag/maglifepc.h"
#include "mag/maglifebwn.h"
#include "spr/sprtexture.h"

class BedPad;
class MagLifeWindow;

class MagLifeMenu : public MagLife {
public:
    virtual void vfunc09();
    virtual void vfunc10();
};

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
struct MagUnk437E0Sub {
    int m_unk00;                    // +0x00
    int m_unk04;                    // +0x04
    int m_unk08;                    // +0x08
    short m_unk0C;                  // +0x0C
    short m_unk0E;                  // +0x0E
}; // size 0x10

struct MagUnk437E0 {
    union {
        float m_unk00;              // +0x00
        int m_unk00_i;
    };
    float m_unk04;                  // +0x04
    float m_unk08;                  // +0x08
    float m_unk0C;                  // +0x0C
    MagUnk437E0Sub m_sub;           // +0x10..+0x1F
} ALIGNED(8); // size 0x20

struct MagPrivateColli {
    DogVector m_p1;
    DogVector m_p2;
};

struct MagUnk29890Sub {
    unsigned char m_unk00[0x20];
    int m_unk20;                    // +0x20
    unsigned char m_unk24[0x4];
    float m_unk28;                  // +0x28
};

struct MagUnk29890 {
    DogModel m_model;               // +0x000
    int m_unk1A0;                   // +0x1A0
    unsigned char m_unk1A4[0x8];    // +0x1A4
    MagUnk29890Sub **m_unk1AC;      // +0x1AC
    unsigned char m_unk1B0[0x370];  // +0x1B0
};
#ifdef TARGET_PS2
STATIC_ASSERT(sizeof(MagUnk29890) == 0x520, MagUnk29890_size);
#endif

struct I3dDraw;

// The scene's actors (the characters, the dog...).
#define MAG_MAX_ACTOR 128

class MagScene {
public:
    MagPrivateColli m_private_colli[256]; // +0x00000
    unsigned char m_unk02000[0x40];
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
    int m_unk29120[0x100];          // +0x29120: per model (func_00138ED0's result)
    DogTexInfo m_tex_info;          // +0x29520
    unsigned char m_unk29540[0x350];
    DogModel m_unk29890;            // +0x29890..+0x29A2F
    int m_unk29A30;                 // +0x29A30
    unsigned char m_unk29A34[0xF9C];
    int m_shadow[4];                // +0x2A9D0
    int m_shadow_direct_on;         // +0x2A9E0
    void *m_shadow_direct;          // +0x2A9E4
    int m_unk2A9E8[2];
    int m_shadow_point_on;          // +0x2A9F0
    void *m_shadow_point;           // +0x2A9F4
    unsigned char m_unk2A9F8[0x18];
    float m_unk2AA10;               // +0x2AA10
    float m_unk2AA14;               // +0x2AA14
    unsigned char m_unk2AA18[0x30];
    float m_unk2AA48;               // +0x2AA48
    float m_unk2AA4C;               // +0x2AA4C
    unsigned char m_unk2AA50[0x34];
    int m_unk2AA84;                 // +0x2AA84
    unsigned char m_unk2AA88[0xE8];
    DogEntityEx m_soundTransform;   // +0x2AB70 (transform__11DogEntityEx)
    unsigned char m_unk2AC60[0x54];
    float m_opt_zoom_ratio;         // +0x2ACB4
    unsigned char m_unk2ACB8[0x98];
    int m_unk2AD50;                 // +0x2AD50
    int m_unk2AD54;                 // +0x2AD54
    int m_unk2AD58;                 // +0x2AD58
    float m_unk2AD5C;               // +0x2AD5C
    float m_unk2AD60;               // +0x2AD60
    int m_unk2AD64;                 // +0x2AD64
    int m_unk2AD68;                 // +0x2AD68
    unsigned char m_unk2AD6C[0x14];
    int m_unk2AD80;                 // +0x2AD80
    int m_unk2AD84;                 // +0x2AD84
    int m_unk2AD88;                 // +0x2AD88
    float m_unk2AD8C;               // +0x2AD8C
    float m_unk2AD90;               // +0x2AD90
    int m_unk2AD94;                 // +0x2AD94
    int m_unk2AD98;                 // +0x2AD98
    int m_unk2AD9C;                 // +0x2AD9C
    DogVector m_unk2ADA0;           // +0x2ADA0
    DogVector m_unk2ADB0;           // +0x2ADB0
    MagLifePC m_pc;                 // +0x2ADC0..+0x2AFDF (size 0x220)
    MagLifeBwn m_bwn;               // +0x2AFE0..+0x2BD1B (size 0xD3C)
    unsigned char m_pad2BD1C[4];
    int m_unk2BD20;                 // +0x2BD20
    unsigned char m_unk2BD24[0x12C];
    int m_unk2BE50;                 // +0x2BE50
    int m_unk2BE54;                 // +0x2BE54
    int m_unk2BE58;                 // +0x2BE58
    MagLifeMenu *m_unk2BE5C;        // +0x2BE5C
    unsigned char m_unk2BE60[0x159F0];
    MagLife m_unk41850;             // +0x41850
    unsigned char m_unk41880[0x10];
    MagLife m_unk41890;             // +0x41890
    unsigned char m_unk418C0[0x12F0];
    S2dMes m_s2dMes;                 // +0x42BB0: message sprites
    unsigned char m_unk43500[0x200];
    int m_unk43700;                 // +0x43700
    unsigned char m_unk43704[0x14];
    int m_unk43718;                 // +0x43718
    TxtToken m_option_bucket[16];   // +0x4371C
    unsigned char m_unk437DC[4];
    MagUnk437E0 m_unk437E0[0x2000]; // +0x437E0
    unsigned char m_unk837E0[0x12C8]; // +0x837E0
    unsigned char m_unk84AA8[0x90C];  // +0x84AA8
    int m_unk853B4;                 // +0x853B4
    unsigned char m_unk853B8[0x128];
    MagScene *m_unk854E0;           // +0x854E0
    int m_unk854E4;                 // +0x854E4
    MagScene *m_unk854E8;           // +0x854E8
    unsigned char m_unk854EC[0x14];

    MagScene();
    ~MagScene();
    DogActor *getActor(int n) { return &m_actor[n]; }
    DogCamera *getCamera() { return (DogCamera *)&m_soundTransform; }
    MagUnk29890 *getUnk29890(int n) { return &((MagUnk29890 *)&m_unk29890)[n]; }
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
