// mag/magsystem.h: MagSystem, the game's main object: it sets up the
// display, the pads and the i3d drawing context, owns the scene (MagScene)
// and runs each frame (update, draw, vsync, swap).
//
// The fields named in assert strings (m_current_system, m_v_sema,
// m_store_image_filename, m_info.m_trash_overrun) and the inline getPad's
// assert (n >= 0 && n < 2) are original; the class name follows the file
// and the rest is ours.
#ifndef MAG_MAGSYSTEM_H
#define MAG_MAGSYSTEM_H

#include "ror.h"
#include "bed/bedpad.h"
#include "mag/magscene.h"
#include "mw/i3d.h"
#include "sdk/libdma.h"
#include "sdk/libgraph.h"

// Frame statistics (+0x0C, 0x28 bytes, cleared together).
struct MagSystemInfo {
    int m_unk00;                    // +0x00
    int m_unk04;                    // +0x04
    int m_max_free;                 // +0x08: the global heap (BedMemory::getInfo)
    int m_total_free;               // +0x0C
    int m_packet_size;              // +0x10: the drawing packet buffer
    int m_packet_used;              // +0x14
    int m_trash_overrun;            // +0x18
    int m_vsync_time;               // +0x1C: timer 0 after the swap
    int m_update_time;              // +0x20: update and draw, in timer 0 ticks
    int m_draw_time;                // +0x24: to the end of the vsync wait
};

// One pad as the game sees it (+0x97A40, 0x10 bytes).
struct MagSystemPad {
    BedPad *m_pad;                  // +0x00: m_pad[n], once init has opened it
    int m_unk04[3];                 // +0x04

    MagSystemPad() { m_pad = 0; }
};

class MagSystem {
public:
    int m_frame;                    // +0x00: frames drawn
    int m_vibrate_time;             // +0x04: frames until the vibration stops
    int m_vibrate;                  // +0x08: vibration enabled (option)
    MagSystemInfo m_info;           // +0x0C
    const char *m_store_image_filename; // +0x34: screenshot file
    int m_store_image;              // +0x38: take a screenshot after this frame
    int m_unk3C;                    // +0x3C
    BedPad m_pad[2];                // +0x40
    sceDmaChan *m_dma;              // +0x160: VIF1
    int m_unk164[3];                // +0x164
    sceGsDBuff m_db;                // +0x170
    I3dDraw m_draw;                 // +0x3A0
    void *m_packet;                 // +0x12508: the packet buffer given to m_draw
    unsigned char m_unk1250C[0x34]; // +0x1250C
    MagScene m_scene;               // +0x12540
    MagSystemPad m_pad_ref[2];      // +0x97A40
    int m_unk97A60;                 // +0x97A60: the player's actor (-1: none)
    int m_unk97A64;                 // +0x97A64
    int m_unk97A68;                 // +0x97A68: the last player's actor
    int m_unk97A6C;                 // +0x97A6C: the sequence started
    int m_unk97A70;                 // +0x97A70: a sequence can start

    static MagSystem *m_current_system;
    static int m_v_count;           // vsyncs since the last frame
    static int m_v_rate;            // vsyncs per frame (2)
    static int m_v_sema;            // signalled every m_v_rate vsyncs

    BedPad *getPad(int n) { ASSERT(n >= 0 && n < 2); return m_pad_ref[n].m_pad; }

    MagSystem();
    ~MagSystem();
    int startSequence(int theNo);
    void vibrate(int theTime);
    void setActorLight(int theNo, int theLight);
    void init();
    void setDisplay448();
    void setDisplay384();
    void func_00117DC8();
    void func_00117DFC();
    void start();
    void func_00117EC0();
    void term();
    void func_00117F80(int theA, int theB, int theC, int theD, int theE, int theF, int theG);
    void func_00117FC4(unsigned int theType, int theA, float *theColor0, float *theColor1);
    void setPlayer(int theNo, int theType);
    void func_0011825C(int theA, int theB);
    void func_0011828C();
    void update();
    void beginDraw();
    void storeImage();
    void endFrame();
    void getPacketSize();
    void setPmodeEn2(int theOn);
    void waitVSync();
    void sendPacket();
    void func_00118880(int theA, int theB);
    void func_001188A8(int theType, int theNo, int theMode, float r, float g, float b, float a);
    void func_001188E4(int theType, int theNo, int theMode, float *r, float *g, float *b, float *a);
    void func_00118960(int *theOut);
    void func_00118980(int theA, int theB, int theC, int theD, int theE, int theF);
    void func_001189BC(int theA, int theB, int theC, int theD, int theE);
    void func_001189E4(int theA, int theB, int theC);
    void attachActor(int theNo, int theParent, int theNode);
    void getActorNodeMatrix(int theNo, tag_I3dMatrixF4x4_s *theOut, int theNode);
    void getActorNodeMatrix(int theNo, float (*theOut)[4], int theNode);
    int getActorNodeMatrix(int theNo, tag_I3dMatrixF4x4_s *theOut, const char *theName);
    int getActorNodeMatrix(int theNo, float (*theOut)[4], const char *theName);
    int func_00118E6C(int theNo, float theFrom, float theTo, DogVector &theResult, float *theTurn,
                      DogVector *theAbs);
    void func_00118EA4(int theNo, const DogVector &theMove, float theRot, float theAar);
    void func_00118ED8(int theA, int theB, int theC);
    void func_00118F04(int theA, int theB, int theC);
    void func_00118F30(int theNo, int theId);
    void func_00118F64(const float *thePos, const float *theDir);
    int func_00118FDC();
    int func_00118FEC();
    int func_00119090();
    int loadModel(int theA, int theChapter);
    void func_001191E0(int theA, int theB, int theChapter);
    void setActorPos(int theNo, float x, float y, float z);
    void setActorRot(int theNo, float x, float y, float z);
    void setActorRot(int theNo, const float *theRot);
    void func_0011948C();
};

#endif
