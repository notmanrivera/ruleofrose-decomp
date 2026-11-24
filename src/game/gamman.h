// game/gamman.h: GamMan, the game manager (one object, D_007812C0, built by
// the main file's static initialiser), and the containers it is made of.
//
// Evidence. GamMan, ACHRstat, FCHRstat, ObjStat, DOOR_OBJ_HEAD, DOOR_OBJ and
// every method declared inline here are original names: the game keeps
// linkonce copies of GamMan's 180 inline methods (0x0028E254-0x0028F834,
// symbols/symbol_addrs.txt), and each copy shows the offset its member has.
// Members named m_<word> take that method's name (getChapter -> m_chapter):
// the offset and width are certain, the spelling is ours. m_unkXXXXX are
// offsets game/gamman.cpp or another file reads or writes with nothing to
// name them; m_padXXXXX is everything nobody has been seen touching.
// The containers (GamList, GamPool, GamItemHave) and their element types are
// our names: their layout comes from GamMan's constructor (func_001C05C0),
// which builds each one in line.
#ifndef GAME_GAMMAN_H
#define GAME_GAMMAN_H

#include "game/gamlist.h"

class ObjStat;
class ACHRstat;
class FCHRstat;
struct DOOR_OBJ_HEAD;
struct DOOR_OBJ;

// An item the player carries. 16 bytes, copied with ldl/ldr (aligned to 4).
struct GamItem {
    int m_unq;                  // +0x00: getUnqPtr(m_uid)'s record (flags at +0xB0 of it)
    int m_oid;                  // +0x04: func_001D0530 looks an item up by it; the name is a guess
    unsigned short m_uid;       // +0x08: compared with getPcEquipItem() and getFindTargetItem()
    unsigned short m_num;       // +0x0A: how many, kept under 100 (func_001C9198)
    int m_unk0C;                // +0x0C
};

// getItemHavePtr: up to 12 items in an array inside the object, with
// begin/end pointers like a vector (constructor: both = m_buf, m_max = 12;
// the destructor walks them 16 bytes at a time).
struct GamItemHave {
    GamItem *m_begin;           // +0x00
    GamItem *m_end;             // +0x04
    int m_max;                  // +0x08
    GamItem m_buf[12] __attribute__((aligned(64)));     // +0x40
};

// getItemStockPtr's element: the item sits at +0x10 of a 0x20-byte node, so
// it is aligned to 16 there but not in GamItemHave. The wrapper is ours.
struct GamItemStock {
    GamItem m_item;

    // Storing one in a node copies the item unaligned (ldl/ldr) although
    // both sides are aligned: an assignment of the inner struct.
    GamItemStock &operator=(const GamItemStock &theOther)
    {
        m_item = theOther.m_item;
        return *this;
    }
} __attribute__((aligned(16)));

// m_unk1D240's element, 16 bytes; func_001CB1C0 clears bit 0 of the first word.
struct GamElem1D240 {
    int m_flg;                  // +0x00
    int m_unk04[3];
};

// m_unk1F880's element, 12 bytes.
struct GamElem1F880 {
    int m_unk00[3];
};

// m_unk20B00's element (func_001CBAFC returns m_val of the one with m_key).
struct GamPair {
    int m_key;
    int m_val;
};

// 0x20 bytes copied whole into GamMan by func_001CF7D0; func_001C46FC fills
// the first 0x1C on its stack. Field names are guesses.
struct GamMsgRect {
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
};

// m_unk22540's element: 0x20 bytes copied with ld/sd (aligned to 8).
struct GamElem22540 {
    float m_val;                // +0x00
    char m_unk04[28];
} __attribute__((aligned(8)));

// m_unk225D0's 8-byte callback/entry (ldl/ldr aligned to 4).
struct GamCb225D0 {
    int m_w0;
    int m_w1;
};

// Still asm (game/gamtrg.cpp); what it returns is not known.
extern "C" int func_001D966C(int);

// sizeof 0x22AC0: the next object in .bss, D_007A3D80, starts there.
// Vtable pointer at +0x22AB4, after the last member (constructor), as g++ 2.96
// places it for a class with no base; two slots, the destructor only
// (notes/class_hierarchy.txt). The destructor is GamMan__vfunc_01 in
// game/gamman.cpp, still written as a plain function.
class GamMan {
public:
    int m_rate;                                     // +0x00000: getRate; the constructor sets 1
    unsigned char m_pad00004[0x3C];
    unsigned char m_trg[0x18B80];                   // +0x00040: trigger manager (game/gamtrg.cpp: ctor func_001DD1E8, dtor func_001DD3EC; create_trg..regist_ftb pass this+0x40); real size unknown (game/gamtrg.cpp reads this+0x18B40..0x18B5C)
    int m_unk18BC0;                                 // +0x18BC0
    int m_unk18BC4;                                 // +0x18BC4
    unsigned char m_pad18BC8[0x4];
    DOOR_OBJ_HEAD *m_doorObjHead;                   // +0x18BCC: getDoorObj
    DOOR_OBJ *m_doorObj;                            // +0x18BD0: getDoorObj
    unsigned char m_pad18BD4[0x2C];
    unsigned char m_mapObj[0x200];                  // +0x18C00: getMapObjPtr (getMapName, cnvPosW2L: func_001DB8E8, func_001DBA3C); the ctor clears +0x1C4 and +0x1C8
    unsigned char m_snd[0x1880];                    // +0x18E00: GamSndMan (game/gamsnd.cpp: ctor func_001E0DF0). +0x0 setSnd3DCnt, +0x1500 getSndFileName, +0x1540 getSndParam, +0x1588 getMstVol, +0x1598 getMstVolStr; real size unknown
    int m_unk1A680;                                 // +0x1A680
    int m_unk1A684;                                 // +0x1A684
    unsigned char m_pad1A688[0x38];
    GamItemHave m_itemHave;                         // +0x1A6C0: getItemHavePtr
    GamPool<GamItemStock, 0x14E> m_itemStock;       // +0x1A7C0: getItemStockPtr
    int m_unk1D200;                                 // +0x1D200: m_num of the item m_unk1D204 points to (func_001C8598)
    GamItem *m_unk1D204;                            // +0x1D204: an item of m_itemHave picked by uid (func_001C8598), or 0
    unsigned char m_pad1D208[0x38];
    GamPool<GamElem1D240, 4> m_unk1D240;            // +0x1D240: ctor; func_001CA38C, func_001CB01C, func_001CB1C0
    unsigned int m_unk1D300;                        // +0x1D300: index into D_007257B8 (MagScene map models), asserted < MAX_MAP_MODEL
    unsigned char m_pad1D304[0x3C];
    GamPool<ACHRstat *, 0x80> m_achrList;           // +0x1D340: getAchrListPtr
    GamPool<FCHRstat *, 0x40> m_fchrList;           // +0x1D980: getFchrListPtr
    GamPool<ObjStat *, 0x180> m_vfchrList;          // +0x1DCC0: getVFchrListPtr
    GamPool<ObjStat *, 0x40> m_avfchrList;          // +0x1EF00: getAVFchrListPtr
    int *m_unk1F240;                                // +0x1F240: 0x169 ints: func_001C7D04, func_001C7DA8, func_001C7DEC
    int m_unk1F244;                                 // +0x1F244
    int m_unk1F248;                                 // +0x1F248
    int m_unk1F24C[0x180];                          // +0x1F24C: func_001CC004 fills it with one value
    unsigned char m_pad1F84C[0x34];
    GamPool<GamElem1F880, 0x80> m_unk1F880;         // +0x1F880: ctor; func_001C47C4
    GamPool<GamPair, 0x80> m_unk202C0;              // +0x202C0: ctor; func_001C143C (8-byte elements, layout unknown)
    GamPool<GamPair, 0x80> m_unk20B00;              // +0x20B00: key/value pairs: func_001CBAFC, func_001CBB80, func_001CBD0C
    ACHRstat *m_achrTbl[0x80];                      // +0x21340: set_achr: [oid & 0x1FF]
    FCHRstat *m_fchrTbl[0x200];                     // +0x21540: delete_fchr_core: [oid & 0x1FF]; the size is a guess (0x40 + 0x180 + 0x40 list nodes)
    unsigned char m_pad21D40[0x200];
    int m_curStat;                                  // +0x21F40: getCurStat
    unsigned char m_pad21F44[0x4];
    unsigned int m_sysFlg;                          // +0x21F48: getSysFlg, chkSysFlg, isOneSec (bit 0), setExistMenu (0x400)
    unsigned int m_sysFlg2;                         // +0x21F4C: chkSysFlg2, setSysFlg2, unsetSysFlg2
    int m_chapter;                                  // +0x21F50: getChapter
    int m_unk21F54;                                 // +0x21F54
    int m_diffPlace;                                // +0x21F58: getDiffPlace
    unsigned char m_pad21F5C[0x4];
    unsigned int m_vcount;                          // +0x21F60: getVCount, getSysTime
    int m_playTime;                                 // +0x21F64: getPlayTime
    unsigned char m_pad21F68[0x4];
    int m_cameraMode;                               // +0x21F6C: getCameraMode
    int m_cameraTarget;                             // +0x21F70: setCameraTarget
    int m_unk21F74;                                 // +0x21F74
    int m_unk21F78;                                 // +0x21F78
    int m_unk21F7C;                                 // +0x21F7C: getMapName passes it to func_001DB8E8: the map (area) number
    int m_unk21F80;                                 // +0x21F80
    int m_unk21F84;                                 // +0x21F84
    int m_unk21F88;                                 // +0x21F88
    int m_unk21F8C;                                 // +0x21F8C
    int m_unk21F90;                                 // +0x21F90
    int m_unk21F94;                                 // +0x21F94
    int m_unk21F98;                                 // +0x21F98
    int m_unk21F9C;                                 // +0x21F9C
    unsigned char m_pad21FA0[0x4];
    int m_unk21FA4;                                 // +0x21FA4
    int m_unk21FA8;                                 // +0x21FA8
    unsigned char m_pad21FAC[0x10];
    float m_unk21FBC[3];                            // +0x21FBC
    unsigned char m_pad21FC8[0x4];
    int m_unk21FCC;                                 // +0x21FCC
    int m_unk21FD0;                                 // +0x21FD0
    int m_inuMode;                                  // +0x21FD4: getInuMode
    int m_unk21FD8;                                 // +0x21FD8
    int m_pcChrNo;                                  // +0x21FDC: getPcChrNo
    int m_unk21FE0;                                 // +0x21FE0: an object: func_001C46C8 writes a float at +0x1E8 of it
    int m_pcLastMot;                                // +0x21FE4: get_pc_last_mot, set_pc_last_mot
    int m_dogChrNo;                                 // +0x21FE8: getDogChrNo
    int m_murderChrNo;                              // +0x21FEC: getMurderChrNo
    int m_unk21FF0;                                 // +0x21FF0: is_pc_jnfc: == 2
    int m_pcCostume;                                // +0x21FF4: setPcCostume, first argument
    int m_pcCostume2;                               // +0x21FF8: setPcCostume, second argument
    float m_unk21FFC;                               // +0x21FFC
    float m_unk22000;                               // +0x22000
    int m_unk22004;                                 // +0x22004
    int m_unk22008;                                 // +0x22008
    int m_pcEquipItemChrID;                         // +0x2200C: getPcEquipItemChrID
    int m_inuTask;                                  // +0x22010: get_inu_task, set_inu_task
    unsigned char m_pad22014[0xC];
    float m_pcPos[4] __attribute__((aligned(16)));  // +0x22020: getPcPos (lq/sq)
    float m_pcRot[4] __attribute__((aligned(16)));  // +0x22030: getPcRot
    float m_dogPos[4] __attribute__((aligned(16))); // +0x22040: getDogPos
    float m_pcPosAMJ[4] __attribute__((aligned(16)));// +0x22050: setPCPosAMJ
    unsigned char m_pad22060[0xC];
    float m_unk2206C;                               // +0x2206C
    unsigned char m_pad22070[0xC];
    float m_unk2207C;                               // +0x2207C
    unsigned char m_pad22080[0x10];
    ACHRstat *m_pc;                                 // +0x22090: getPCPtr
    ACHRstat *m_dog;                                // +0x22094: getDogPtr
    ACHRstat *m_murder;                             // +0x22098: getMurderPtr
    unsigned char m_pad2209C[0x164];
    int *m_unk22200;                                // +0x22200: an array: func_001C1A6C reads [theIdx]
    unsigned char m_pad22204[0x4];
    int m_pcEquipItemOID;                           // +0x22208: getPcEquipItemOID
    unsigned short m_pcEquipItem;                   // +0x2220C: getPcEquipItem
    unsigned short m_findTargetItem;                // +0x2220E: getFindTargetItem
    unsigned short m_findTargetItemCandidate;       // +0x22210: getFindTargetItemCandidate
    unsigned char m_pad22212[0x2];
    int m_unk22214;                                 // +0x22214: chkNoise: != -1
    int m_unk22218;                                 // +0x22218
    int m_unk2221C;                                 // +0x2221C
    unsigned char m_unq[0x5C];                      // +0x22220: unique-object table (game/gamtrg.cpp: getUnqParam, getUnqPtr, setUnqFlg... pass this+0x22220); real size unknown
    int m_sysMsgHND;                                // +0x2227C: getSysMsgHND
    GamMsgRect m_unk22280;                          // +0x22280: copied whole by func_001CF7D0 (ldl/ldr: aligned to 4)
    int m_msgTaskID;                                // +0x222A0: getMsgTaskID
    int m_selectTaskID;                             // +0x222A4: getSelectTaskID
    int m_unk222A8;                                 // +0x222A8
    int m_seqEvtTaskID;                             // +0x222AC: getSeqEvtTaskID
    int m_sysTaskID;                                // +0x222B0: getSysTaskID
    int m_movieTaskID;                              // +0x222B4: getMovieTaskID
    int m_camTaskID;                                // +0x222B8: getCamTaskID
    int m_bgLoadTaskID;                             // +0x222BC: getBGLoadTaskID
    int m_itemUseTaskID;                            // +0x222C0: getItemUseTaskID
    unsigned int m_callBackEhon[2];                 // +0x222C4: regist_call_back_ehon(a, b): [0] = b, [1] = a
    unsigned int m_callBackMenu[2];                 // +0x222CC: regist_call_back_menu
    unsigned int m_callBackSeqEvt[2];               // +0x222D4: regist_call_back_seq_evt
    unsigned int m_jumpAreaAct[2];                  // +0x222DC: regist_jump_area_act, get_jump_area_act
    unsigned char m_pad222E4[0x80];
    unsigned int m_emyParam;                        // +0x22364: setEmyParam
    unsigned int m_unk22368;                        // +0x22368
    char m_unk2236C[4][0x40];                       // +0x2236C: four strings: func_001C143C clears the first byte of each
    int m_unk2246C;                                 // +0x2246C
    unsigned char m_pad22470[0xC0];
    int m_unk22530;                                 // +0x22530
    unsigned char m_pad22534[0xC];
    GamElem22540 m_unk22540[3];                     // +0x22540: func_001C6470 copies one in from D_006FBD80+0x2AAE0; m_val -1.0f means unused
    float m_unk225A0;                               // +0x225A0
    unsigned char m_pad225A4[0xC];
    float m_unk225B0[4];                            // +0x225B0
    unsigned char m_pad225C0[0x10];
    GamCb225D0 m_unk225D0;                          // +0x225D0
    int m_msgMode;                                  // +0x225D8: chgMsgMode (MSG_MODE)
    unsigned int m_realMemSize;                     // +0x225DC: get_real_mem_size, reveal_mem_size
    unsigned char m_pad225E0[0x4];
    int m_unk225E4;                                 // +0x225E4
    int m_unk225E8;                                 // +0x225E8
    unsigned char m_pad225EC[0x4];
    int m_unk225F0;                                 // +0x225F0
    int m_unk225F4[26];                             // +0x225F4: func_001C0D70 sets them one by one
    unsigned char m_pad2265C[0x424];
    int m_evtPack;                                  // +0x22A80: getEvtPack (a pointer)
    int m_unk22A84;                                 // +0x22A84
    int m_cursolInitFlgItem;                        // +0x22A88: getCursolInitFlg_Item
    int m_cursolInitFlgStock;                       // +0x22A8C: getCursolInitFlg_Stock
    unsigned char m_pad22A90[0x10];
    int m_playTimeHH;                               // +0x22AA0: getPlayTime_HH
    int m_playTimeMM;                               // +0x22AA4: getPlayTime_MM
    unsigned char m_pad22AA8[0x8];
    int m_unk22AB0;                                 // +0x22AB0

    virtual ~GamMan();                                  // vtable pointer: +0x22AB4

    // Original inline methods (bodies written from their linkonce copies;
    // only those decompiled code needs so far).
    int getRate() { return m_rate; }
    int getCurStat() const { return m_curStat; }
    unsigned int getSysFlg() const { return m_sysFlg; }
    bool chkSysFlg(unsigned int theFlg) const { return (m_sysFlg & theFlg) != 0; }
    bool chkSysFlg2(unsigned int theFlg) const { return (m_sysFlg2 & theFlg) != 0; }
    void setSysFlg2(unsigned int theFlg) { m_sysFlg2 |= theFlg; }
    void unsetSysFlg2(unsigned int theFlg) { m_sysFlg2 &= ~theFlg; }
    int getChapter() const { return m_chapter; }
    unsigned int getVCount() const { return m_vcount; }
    unsigned int getSysTime()
    {
        m_unk22368 = (unsigned int)((float)(m_vcount * 1000) / 25.0f);
        return m_unk22368;
    }
    int getPcChrNo() const { return m_pcChrNo; }
    int getDogChrNo() const { return m_dogChrNo; }
    ACHRstat *getPCPtr() const { return m_pc; }
    ACHRstat *getDogPtr() const { return m_dog; }
    ACHRstat *getMurderPtr() const { return m_murder; }
    unsigned short getPcEquipItem() const { return m_pcEquipItem; }
    unsigned short getFindTargetItem() const { return m_findTargetItem; }
    GamItemHave *getItemHavePtr() { return &m_itemHave; }
    GamPool<GamItemStock, 0x14E> *getItemStockPtr() { return &m_itemStock; }
    void *getMapObjPtr() { return m_mapObj; }
    GamList<ACHRstat *> *getAchrListPtr() { return &m_achrList; }
    GamList<FCHRstat *> *getFchrListPtr() { return &m_fchrList; }
    GamList<ObjStat *> *getVFchrListPtr() { return &m_vfchrList; }
    GamList<ObjStat *> *getAVFchrListPtr() { return &m_avfchrList; }

    // delete_fchr_core (linkonce copy at 0x0028F794). It needs FCHRstat:
    // only for files that include game/gamtrg.h first (some older files
    // declare their own ObjStat instead).
#ifdef GAME_GAMTRG_H
    void delete_fchr_core(FCHRstat *theStat)
    {
        func_001D966C((int)theStat);
        m_fchrTbl[theStat->getOID() & 0x1FF] = 0;
    }
#endif

    // Not original: older decompiled files call the object at +0x22094 "the
    // player". It is the dog (getDogPtr); the player is m_pc (getPCPtr).
    ObjStat *getPlayer() { return (ObjStat *)m_dog; }
};

// The game manager, constructed by the main file's static initialiser.
extern GamMan D_007812C0;

// Still asm (game/gamman.cpp).
extern "C" int func_001C6C38(GamMan *theGamMan);    // 0-2 or -1: which sound-id column is in use

#endif
