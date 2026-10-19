// mag/magsystem.cpp: MagSystem, the game's main object (see
// mag/magsystem.h): display and pad set-up, the frame loop, screenshots and
// the wrappers the game calls on its scene.
//
// 54 of 55 functions match. endFrame is still the game's asm; the C++ under
// NON_MATCHING only differs in where the prologue saves $ra (a scheduling
// tie). Until it matches, .data/.bss stay in asm and the strings it shares
// with the C++ functions are INCLUDE_RODATA symbols (ASSERT_FILE). Names
// are ours unless an assert string gives them.
#include "ror.h"
#include "mag/magsystem.h"
#include "bed/bedmemory.h"
#include "mw/i3d.h"
#include "sdk/eekernel.h"
#include "sdk/libdma.h"
#include "sdk/libgraph.h"
#include "sdk/libvu0.h"
#include "sdk/sifdev.h"
#include "sdk/string.h"
#include "include_asm.h"

// The __FILE__ string, shared with the asm functions (INCLUDE_RODATA). It is
// set after the headers, whose inline methods assert with their own file.
#undef ASSERT_FILE
#define ASSERT_FILE D_002E9050
extern const char D_002E9050[];     // "mag/magsystem.cpp"

extern BedMemory D_006E9800;     // the global heap

// unk/001056E8, utl/utlbtl, utl/utlgame (names ours but countFrame).
void countFrame();
extern "C" void func_0010421C();
extern "C" int func_00103484();             // the vibration option

// Other modules (names ours): the movie player and the sound manager (their
// global objects), the sequencer and a debug print.
extern int D_007B40C0[];
extern int D_007B2580[];
extern "C" void func_00181204(void *theMovie, int theField);
extern "C" void func_00182118(int theCount);
extern "C" void func_0017F200(void *theSound);
extern "C" void func_0024AFA0(int);
extern "C" void func_0024B3F8(int);
extern "C" void func_0020E3D8(int theNo, int theA);
extern "C" void func_00215B5C(float x, float y, float z);

// .data and .bss, still in asm.
extern const char *D_002961A8[];            // the chapter packs
extern unsigned char D_00308580[];          // the drawing packets

// A .bmp header (the screenshots).
struct MagBmpHeader {
    unsigned char bfType[2];        // +0x00: "BM"
    unsigned int bfSize;            // +0x02
    unsigned short bfReserved1;     // +0x06
    unsigned short bfReserved2;     // +0x08
    unsigned int bfOffBits;         // +0x0A
    unsigned int biSize;            // +0x0E
    int biWidth;                    // +0x12
    int biHeight;                   // +0x16: < 0: top to bottom
    unsigned short biPlanes;        // +0x1A
    unsigned short biBitCount;      // +0x1C
    unsigned int biCompression;     // +0x1E
    unsigned int biSizeImage;       // +0x22
    int biXPelsPerMeter;            // +0x26
    int biYPelsPerMeter;            // +0x2A
    unsigned int biClrUsed;         // +0x2E
    unsigned int biClrImportant;    // +0x32
} __attribute__((packed));

// 0x00117654: the vsync handler: signals m_v_sema every m_v_rate vsyncs.
int vsyncHandler(int)
{
    MagSystem::m_v_count++;
    func_00182118(MagSystem::m_v_count);
    if (MagSystem::m_v_count >= MagSystem::m_v_rate) {
        MagSystem::m_v_count = 0;
        iSignalSema(MagSystem::m_v_sema);
    }
    ExitHandler();
    return 0;
}

// 0x001176BC: the same for every vsync (unused).
int vsyncHandler1(int)
{
    if (++MagSystem::m_v_count > 0) {
        MagSystem::m_v_count = 0;
        iSignalSema(MagSystem::m_v_sema);
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E9050);

// 0x001176FC
MagSystem::MagSystem()
    : m_frame(0), m_vibrate_time(0), m_vibrate(0), m_store_image_filename(0), m_store_image(0)
{




















































































    ASSERT(m_current_system == __null);
    m_current_system = this;
    m_packet = 0;
    func_0010421C();
    memset(&m_info, 0, sizeof(m_info));
    m_unk97A6C = 0;
    m_unk97A70 = 1;
}

// 0x00117808
MagSystem::~MagSystem()
{
    m_current_system = 0;
}

// 0x001178B8: starts sequence theNo once.
int MagSystem::startSequence(int theNo)
{
    if (!m_unk97A70) {
        return 0;
    }
    func_0020E3D8(theNo, 1);
    m_unk97A6C = theNo;
    m_unk97A70 = 0;
    return 1;
}

// 0x00117924
void MagSystem::vibrate(int theTime)
{
    if (m_vibrate) {
        getPad(0)->vibrate(0, 255);
        m_vibrate_time = theTime;
    }
}

// 0x00117974
void MagSystem::setActorLight(int theNo, int theLight)
{
    m_scene.m_actor[theNo].m_light_id = theLight;
}

// 0x00117990: opens the pads, resets the DMA, the VU0 and the GS, and sets
// up the double buffer and the drawing context.
void MagSystem::init()
{
    for (int i = 0; i < 2; i++) {
        BedPad *pad = &m_pad[i]; pad->open(i);
        pad->m_repeatDelay = 15;
        pad->m_repeatInterval = 10;
        m_pad_ref[i].m_pad = pad;
    }
    m_dma = sceDmaGetChan(SCE_DMA_VIF1);
    sceDmaReset(1);
    sceVpu0Reset();
    sceGsResetPath();
    sceGsResetGraph(0, SCE_GS_INTERLACE, SCE_GS_NTSC, SCE_GS_FIELD);
    sceGsSetDefDBuff(&m_db, SCE_GS_PSMCT32, 512, 448, SCE_GS_ZGEQUAL, SCE_GS_PSMZ16S, 1);
    *(unsigned long *)&m_db.clear1.rgbaq = 0;
    *(unsigned long *)&m_db.clear0.rgbaq = 0;
    m_db.disp[1].dispfb.FBP = 0x70;
    m_db.disp[0].dispfb.FBP = 0;
    m_db.draw0.frame1.FBP = 0x70;
    m_db.draw1.frame1.FBP = 0;
    m_db.draw0.zbuf1.ZBP = m_db.draw1.zbuf1.ZBP = (*(unsigned int *)&m_db.disp[1].dispfb & 0x1FF) * 2;


    // The sizes of i3d's types this game was built with.
    int size[] = {
        0x20, 0x130, 0x130, 0x1E, 0x38, 0x38, 6, 0x18, 8,
        0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x20,
        0x4D0, 0x3B0, 0x80, 0xA0, 8, 0x44, 0x18, 0x20, 0x12168,
        0x12168, 0x10, 0x18, 0x60, 0x400, 0x400, 0x18, 0x20, 0x38
    };
    for (unsigned int i = 0; i < sizeof(size) / sizeof(size[0]); i++) {
        if (size[i] != func_0021F1A8(i)) {
            // "Package version i3d_package_version 050121-stable-050826:
            // fatal error. A debug build or a library from another build
            // is linked into the release application. Fix the libraries
            // you link."
            func_00237C68("\245\321\245\303\245\261\241\274\245\270\245\320\241\274\245\270\245\347\245\363"
                          " i3d_package_version 050121-stable-050826 : "
                          "\303\327\314\277\305\252\245\250\245\351\241\274\n"
                          "\245\352\245\352\241\274\245\271\310\307\244\316\245\242\245\327\245\352\245\261"
                          "\241\274\245\267\245\347\245\363\244\313\241\242\245\307\245\320\245\303\245\260"
                          "\310\307\244\336\244\277\244\317\n"
                          "\260\333\244\312\244\353\245\323\245\353\245\311\244\316\245\351\245\244\245\326"
                          "\245\351\245\352\244\254\245\352\245\363\245\257\244\265\244\354\244\306\244\244"
                          "\244\336\244\271\241\243\n"
                          "\245\352\245\363\245\257\244\271\244\353\245\351\245\244\245\326\245\351\245\352"
                          "\244\362\275\244\300\265\244\267\244\306\244\257\244\300\244\265\244\244\241\243\n");
            for (;;) {
            }
        }
    }
    if (!func_0021EB28()) {
        m_packet = D_00308580;
        func_0021F900(&m_draw, D_00308580, 0x35C000, 2);
        m_info.m_packet_size = 0x1AE000;
        func_0021ED10(&m_draw, 0x158, 0xA8);
    }
}

// 0x00117C58: 512x448.
void MagSystem::setDisplay448()
{
    sceGsSetDefDBuff(&m_db, SCE_GS_PSMCT32, 512, 448, SCE_GS_ZGEQUAL, SCE_GS_PSMZ16S, 1);
    *(unsigned long *)&m_db.clear1.rgbaq = 0;
    *(unsigned long *)&m_db.clear0.rgbaq = 0;
    m_db.disp[1].dispfb.FBP = 0x70;
    m_db.disp[0].dispfb.FBP = 0;
    m_db.draw0.frame1.FBP = 0x70;
    m_db.draw1.frame1.FBP = 0;
    m_db.draw0.zbuf1.ZBP = m_db.draw1.zbuf1.ZBP = (*(unsigned int *)&m_db.disp[1].dispfb & 0x1FF) * 2;

}

// 0x00117D14: 512x384.
void MagSystem::setDisplay384()
{
    sceGsSetDefDBuff(&m_db, SCE_GS_PSMCT32, 512, 384, SCE_GS_ZGEQUAL, SCE_GS_PSMZ16S, 1);
    m_db.disp[0].dispfb.FBP = 0;
    m_db.disp[1].dispfb.FBP = 0x60;
    m_db.draw0.frame1.FBP = 0x60;
    m_db.draw1.frame1.FBP = 0;
    m_db.draw0.zbuf1.ZBP = m_db.draw1.zbuf1.ZBP = (*(unsigned int *)&m_db.disp[1].dispfb & 0x1FF) * 2;

}

// 0x00117DC8
void MagSystem::func_00117DC8()
{
    init();
    m_scene.func_00131840();
}

// 0x00117DFC
void MagSystem::func_00117DFC()
{
    func_00117DC8();
}

























































































































































































































































// 0x00117E18: starts the scene and the vsync semaphore.
void MagSystem::start()
{
    m_scene.func_00131A28();
    SemaParam param;
    param.maxCount = 0x7FFFFFFF;
    param.initCount = 0;
    param.option = 0;
    m_v_sema = CreateSema(&param);
    ASSERT(m_v_sema >= 0);
    sceGsSyncVCallback(vsyncHandler);
    D_006E9800.check(0);
    m_scene.func_00131B90(&m_draw);
}

// 0x00117EC0
void MagSystem::func_00117EC0()
{
    m_scene.m_unk022CC = 0;
}





























































// 0x00117ED0
void MagSystem::term()
{
    if (m_packet) {
        D_006E9800.free(m_packet);
        m_packet = 0;
    }
    func_0021F8C8(&m_draw);
    for (int i = 0; i < 2; i++) {
        m_pad[i].close();
    }
    sceGsSyncVCallback(0);
    ASSERT(m_v_sema);
    DeleteSema(m_v_sema);
}

// 0x00117F80
void MagSystem::func_00117F80(int theA, int theB, int theC, int, int, int, int theG)
{
    int param[6];
    param[0] = theA; param[1] = theB; param[2] = theC; param[3] = 0; param[4] = 0; param[5] = 0;
    m_scene.func_0013F528(param, theG);
}
























// 0x00117FC4
void MagSystem::func_00117FC4(unsigned int theType, int theA, float *theColor0, float *theColor1)
{
    int no = m_scene.func_0013FE64(theType, theA);
    if (no < 0) {
        return;
    }
    m_scene.func_0013F980(theType, no, 2, theColor0, -1);
    switch (theType) {
    case 0:
        break;
    case 1:
        return m_scene.func_0013F980(1, no, 1, theColor1, -1);
    case 2:
        return m_scene.func_0013F980(2, no, 0, theColor1, -1);
    default:
        ASSERT(0);
        break;
    }



}

// 0x001180EC: the player's actor (-1: none) and how it is played.
void MagSystem::setPlayer(int theNo, int theType)
{
    if (theNo >= 0) {
        m_pad[0].clearLast();
        m_pad[1].clearLast();
        m_unk97A60 = theNo;
        m_unk97A68 = theNo;
    } else {
        if (m_unk97A60 >= 0) {
            m_unk97A68 = m_unk97A60;
        }
        m_unk97A60 = theNo;
        if (m_vibrate) {
            m_vibrate_time = 0;
            getPad(0)->vibrate(0, 0);
        }
    }
    int type;
    switch (theType) {
    case 0:
    case 1:
    case 2:
    case 3:
        type = theType;
        break;
    case 'NORM':
    case 'RMAL':
        type = 0;
        break;
    case 'PC02':
        type = 1;
        break;
    case 'JNFC':
        type = 2;
        break;
    case 'PC05':
        type = 3;
        break;
    default:
        type = 0;
        break;
    }
    m_scene.func_001316B8(theNo, type);
    m_vibrate = func_00103484();
}

// 0x0011825C
void MagSystem::func_0011825C(int theA, int theB)
{
    m_unk97A64 = theA;
    m_scene.func_00131790(theA, theB);
}

// 0x0011828C: a frame without the scene.
void MagSystem::func_0011828C()
{
    m_pad[0].update();
    m_pad[1].update();
    beginDraw();
    endFrame();
    waitVSync();
    sendPacket();
}

























































































































// 0x001182DC: a frame.
void MagSystem::update()
{
    unsigned int start = *T0_COUNT;
    if (m_vibrate_time > 0) {
        if (--m_vibrate_time <= 0) {
            getPad(0)->vibrate(0, 0);
        }
    }
    m_pad[0].update();
    m_pad[1].update();
    func_00181204(D_007B40C0, m_frame & 1);
    m_scene.func_001327DC(&m_pad[0], &m_pad[1]);
    func_0017F200(D_007B2580);
    beginDraw();
    m_scene.func_0013BCC0(&m_draw, &m_db, m_frame);
    m_scene.func_0013C29C();
    m_info.m_update_time = *T0_COUNT - start;
    int r = func_0021F200(&m_draw);
    ASSERT(r != 0);
    endFrame();
    waitVSync();
    m_info.m_draw_time -= start;
    sendPacket();
    m_frame++;
    countFrame();
}

// 0x00118440
void MagSystem::beginDraw()
{
    func_0021F6A0(&m_draw);
}






















































































// 0x0011845C: writes the front buffer to m_store_image_filename (.bmp).
void MagSystem::storeImage()
{
    ASSERT(m_store_image_filename);
    int fd = sceOpen(m_store_image_filename, SCE_WRONLY | SCE_CREAT | SCE_TRUNC);
    if (fd < 0) {
        return;
    }
    MagBmpHeader h;
    memset(&h, 0, sizeof(h));
    h.bfType[0] = 'B';
    h.bfType[1] = 'M';
    h.bfSize = sizeof(h) + 512 * 448 * 3;
    h.bfOffBits = sizeof(h);
    h.biSize = 0x28;
    h.biWidth = 512;
    h.biHeight = -448;
    h.biPlanes = 1;
    h.biBitCount = 24;
    h.biCompression = 0;
    sceWrite(fd, &h, sizeof(h));
    sceDmaSync(sceDmaGetChan(SCE_DMA_VIF1), 0, 0);
    sceGsSyncPath(0, 0);
    unsigned int line[512];
    unsigned char rgb[512 * 3];
    for (int y = 0; y < 448; y++) {
        sceGsStoreImage si;
        sceGsSetDefStoreImage(&si, 0, 8, SCE_GS_PSMCT32, 0, y, 512, 1);
        FlushCache(0);
        unsigned char *src = (unsigned char *)line;
        sceGsExecStoreImage(&si, src);
        sceGsSyncPath(0, 0);
        unsigned char *dst = rgb;
        for (int x = 0; x < 512; x++) {
            dst[0] = src[2];
            dst[1] = src[1];
            dst[2] = src[0];
            src += 4;
            dst += 3;
        }
        sceWrite(fd, rgb, sizeof(rgb));
    }
    sceClose(fd);
    m_dma->chcr.TTE = 1;
    sceGsSyncPath(0, 0);
    if (0) {
        unsigned char *p = 0;
        long lv = 0;






















        ASSERT(p[0] == lv);
        ASSERT(p[1] == lv);
        ASSERT(p[2] == lv);
        ASSERT(p[3] == lv);
        ASSERT(p[4] == lv);
        ASSERT(p[5] == lv);
        ASSERT(p[6] == lv);
        ASSERT(p[7] == lv);
    }
}











































// 0x00118640: closes the frame's packet and takes the statistics.
#ifdef NON_MATCHING
void MagSystem::endFrame()
{
    m_info.m_packet_used = func_0021F200(&m_draw);
    m_info.m_trash_overrun = func_0021F250(&m_draw);
    ASSERT(m_info.m_trash_overrun == 0);
    BedMemoryInfo info;
    D_006E9800.getInfo(&info, 0);
    m_info.m_max_free = info.m_maxFree;
    m_info.m_total_free = info.m_totalFree;
    func_0021F760(&m_draw);
    if (m_store_image) {
        m_store_image = 0;
        sceGsSyncPath(0, 0);
        storeImage();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/mag/magsystem", endFrame__9MagSystem);
#endif

// 0x001186F0
void MagSystem::getPacketSize()
{
    int used = func_0021F200(&m_draw);
    int size = 0x1AE000;
    int rate = used / size;
}


// 0x0011871C
void MagSystem::setPmodeEn2(int theOn)
{
    m_db.disp[0].pmode.EN2 = theOn != 0;
    m_db.disp[1].pmode.EN2 = theOn != 0;
    *GS_PMODE = *(unsigned long *)&m_db.disp[0].pmode;
}

// 0x00118754: waits for the vsync and the DMA, then swaps the buffers.
void MagSystem::waitVSync()
{
    if (D_007B40C0[0]) {
        func_0024AFA0(0);
    }
    m_info.m_draw_time = *T0_COUNT;
    if (m_v_count >= m_v_rate) {
        func_0024B3F8(0);
    }
    if (m_v_sema >= 0) {
        WaitSema(m_v_sema);
        while (PollSema(m_v_sema) >= 0) {
        }
    } else {
        sceGsSyncPath(0, 0);
    }
    while (sceDmaSync(m_dma, 1, 0)) {
        func_0024B3F8(0);
    }
    m_info.m_vsync_time = *T0_COUNT;
    FlushCache(0);
    sceGsSwapDBuff(&m_db, m_frame & 1);
}

// 0x00118840
void MagSystem::sendPacket()
{
    sceGsSyncPath(0, 0);
    sceDmaSend(m_dma, func_0021F1F8(&m_draw));
}

// 0x00118880
void MagSystem::func_00118880(int theA, int theB)
{
    m_scene.func_0013CAF0(theA, theB);
}

// 0x001188A8
void MagSystem::func_001188A8(int theType, int theNo, int theMode, float r, float g, float b, float a)
{
    float c[4];
    c[0] = r;
    c[1] = g;
    c[2] = b;
    c[3] = a;
    m_scene.func_0013F980(theType, theNo, theMode, c, -1);
}

// 0x001188E4
void MagSystem::func_001188E4(int theType, int theNo, int theMode, float *r, float *g, float *b,
                              float *a)
{
    float c[4];
    m_scene.func_0013FA50(theType, theNo, theMode, c, -1);
    *r = c[0];
    *g = c[1];
    *b = c[2];
    *a = c[3];
}

// 0x00118960
void MagSystem::func_00118960(int *theOut)
{
    return m_scene.func_0013D5AC(theOut);
}

// 0x00118980
void MagSystem::func_00118980(int theA, int theB, int theC, int theD, int theE, int theF)
{
    int param[5] = {theB, theC, theD, theE, theF};
    m_scene.func_00134944(theA, param);
}

// 0x001189BC
void MagSystem::func_001189BC(int theA, int theB, int theC, int theD, int theE)
{
    m_scene.func_00135234(theA, theB, theC, theD, theE);
}

// 0x001189E4
void MagSystem::func_001189E4(int theA, int theB, int theC)
{
    return m_scene.func_001377F0(&m_draw, theA, theB, theC);
}













































































































































































































// 0x00118A18: attaches actor theNo to node theNode of actor theParent (-1:
// detaches it).
void MagSystem::attachActor(int theNo, int theParent, int theNode)
{
    ASSERT(theNo >= 0);
    DogActor *p = m_scene.getActor(theNo);
    if (theParent >= 0) {
        p->setParent(m_scene.getActor(theParent));
        p->setAttachNode(theNode);
    } else {
        p->setParent(0);
    }
}













// 0x00118ADC
void MagSystem::getActorNodeMatrix(int no, tag_I3dMatrixF4x4_s *theOut, int n)
{
    ASSERT(no >= 0);
    ASSERT(n >= 0);
    tag_I3dMatrixF4x4_s m;
    m_scene.m_actor[no].vfunc17(m.m, n);
    *theOut = m;
}










// 0x00118C14
void MagSystem::getActorNodeMatrix(int no, float (*theOut)[4], int n)
{
    ASSERT(no >= 0);
    ASSERT(n >= 0);
    m_scene.m_actor[no].vfunc17(theOut, n);
}

// 0x00118CCC
int MagSystem::getActorNodeMatrix(int theNo, tag_I3dMatrixF4x4_s *theOut, const char *theName)
{
    DogActor *p = &m_scene.m_actor[theNo];
    int n = p->getNodeIndexByName(theName);
    if (n >= 0) {
        getActorNodeMatrix(theNo, theOut, n);
    }
    return n;
}

// 0x00118D9C
int MagSystem::getActorNodeMatrix(int theNo, float (*theOut)[4], const char *theName)
{
    DogActor *p = &m_scene.m_actor[theNo];
    int n = p->getNodeIndexByName(theName);
    if (n >= 0) {
        getActorNodeMatrix(theNo, theOut, n);
    }
    return n;
}

// 0x00118E6C
int MagSystem::func_00118E6C(int theNo, float theFrom, float theTo, DogVector &theResult,
                             float *theTurn, DogVector *theAbs)
{
    return m_scene.m_actor[theNo].func_00109348(theFrom, theTo, theResult, theTurn, theAbs);
}

// 0x00118EA4
void MagSystem::func_00118EA4(int theNo, const DogVector &theMove, float theRot, float theAar)
{
    m_scene.m_actor[theNo].func_0010A038(theMove, theRot, theAar);
}

// 0x00118ED8
void MagSystem::func_00118ED8(int theA, int theB, int theC)
{
    return m_scene.func_001390D4(theA, theC, theB);
}

// 0x00118F04
void MagSystem::func_00118F04(int theA, int theB, int theC)
{
    return m_scene.func_0013910C(theA, theC, theB);
}

// 0x00118F30
void MagSystem::func_00118F30(int theNo, int theId)
{
    m_scene.m_actor[theNo].func_00109B88(theId);
}

// 0x00118F64
void MagSystem::func_00118F64(const float *thePos, const float *theDir)
{
    DogVector pos(thePos[0], thePos[1], thePos[2], thePos[3]);
    DogVector dir(theDir[0], theDir[1], theDir[2], theDir[3]);








    m_scene.func_0013C2EC(pos, dir);
}

// 0x00118FDC
int MagSystem::func_00118FDC()
{
    return m_scene.m_unk2AEA4;
}

// 0x00118FEC: the player's state, as the pause menu sees it.
int MagSystem::func_00118FEC()
{
    MagLifePC *pc = &m_scene.m_pc;
    int r;
    switch (pc->m_unk00) {
    case 5:
    case 6:
        r = 1;
        break;
    case 10:
        r = 2;
        break;
    case 12:
        r = 3;
        break;
    case 9:
        r = pc->m_unk0C == 1 ? 3 : 11;
        break;
    case 22:
    case 23:
        r = 4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        r = pc->func_0011E080();
        break;
    case 14:
        r = 9;
        break;
    default:
        r = 12;
        break;
    }
    return r;
}

// 0x00119090
int MagSystem::func_00119090()
{
    switch (m_scene.m_unk2BD20) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    case 10:
        return 10;
    case 11:
        return 11;
    case 12:
        return 12;
    case 13:
        return 13;
    }
    return -1;
}

// 0x00119138
int MagSystem::loadModel(int theA, int theChapter)
{
    const char *pack = 0;
    if (theChapter >= 0) {
        pack = D_002961A8[theChapter];
    }
    int r = m_scene.func_00138ED0(&m_draw, theA, pack);
    int type = theA & 0xFF00;
    if (r >= 0) {
        if (type == 0x2000 || type == 0x2400) {
            m_scene.setModelFlag(r, 0x60);
        }
    }

    return r;
}

// 0x001191E0
void MagSystem::func_001191E0(int theA, int theB, int theChapter)
{
    const char *pack = 0;
    if (theChapter >= 0) {
        pack = D_002961A8[theChapter];
    }
    return m_scene.func_00138BC4(&m_draw, theA, theB, pack);
}

// 0x00119234
void MagSystem::setActorPos(int theNo, float x, float y, float z)
{
    if (theNo == m_unk97A68) {
        func_00215B5C(x, y, z);
    }
    DogActor *p = &m_scene.m_actor[theNo];
    p->m_unk40.m_x = x;
    p->m_unk40.m_y = y;
    p->m_unk40.m_z = z;
    p->m_unk90 = 1;
}




















































































































































// 0x001192C8
void MagSystem::setActorRot(int theNo, float x, float y, float z)
{
    DogActor *p = m_scene.getActor(theNo);
    ASSERT(p);
    p->setRot(x, y, z);
    p->m_base_rot.set(x, y, z);
    p->m_rot_offset.clear();
    p->m_unk90 = 1;
    p->clearRotYAAR();
}







// 0x0011939C
void MagSystem::setActorRot(int theNo, const float *theRot)
{
    DogActor *p = m_scene.getActor(theNo);
    ASSERT(p);
    p->m_unk50 = DogVector(theRot[0], theRot[1], theRot[2], theRot[3]);


    p->normalizeRot();
    p->m_unk90 = 1;
    p->m_base_rot.set(theRot);
    p->m_rot_offset.clear();
    p->m_unk90 = 1;
    p->m_rot_ofs_y = 0.0f;
    p->clearRotYAAR();
}

// 0x0011948C
void MagSystem::func_0011948C()
{
    m_scene.func_0013604C();
}

// The chapter packs D_002961A8 (.data, still asm) points to; a file-scope
// table's strings come after the functions' .rodata.
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E93D8);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E93F0);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E9408);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E9420);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E9438);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E9450);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E9468);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E9480);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E9498);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E94B0);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E94C8);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E94E0);
INCLUDE_RODATA("asm/nonmatchings/mag/magsystem", D_002E94F8);
