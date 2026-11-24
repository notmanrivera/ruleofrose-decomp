// game/gamtrg.h: ObjStat, ACHRstat, FCHRstat, and the trigger/map/unique
// managers defined in game/gamtrg.cpp.
//
// Evidence:
// - ObjStat, ACHRstat, FCHRstat, tagColParam and every inline method here are
//   original names from the linkonce copies (0x0028F874-0x0028FDB0 and
//   _$_7ObjStat / ___8ACHRstat / ___8FCHRstat, symbols/symbol_addrs.txt).
// - Exact object sizes come from __builtin_new in game/gamman.s:
//   ObjStat 0x280, FCHRstat 0x2C0, ACHRstat 0x480 (64-byte aligned because
//   ObjStat embeds GamPool<int, 8> at +0x40, whose m_nodes[8] is 64-aligned).
// - GamTrg0, GamMapObj, GamUnqMan, GamTrgElem, GamTrgFtb, GamTrgMan are our
//   names for the structs whose methods live in game/gamtrg.cpp and sit inside
//   GamMan (+0x00040 m_trg, +0x18C00 m_mapObj, +0x22220 m_unq).
#ifndef GAME_GAMTRG_H
#define GAME_GAMTRG_H

#include "target.h"
#include "game/gamlist.h"

// setColPrm takes one by value and copies it as six doublewords: 0x30 bytes
// aligned to 8. func_001D9908 and func_001DB1F0 write 2 to +0x00 and +0x04.
struct tagColParam {
    int m_unk00;
    int m_unk04;
    long m_unk08[5];
};

// Common 0x80-byte header of every GamUnqMan entry (ACHRstat::m_unqInfo at
// +0x400, FCHRstat::m_unq at +0x280). Offsets from ACHRstat's linkonce inline
// methods (get_o_name_jpn..get_o_node_name) and func_001D9908/func_001DB1F0.
struct GamUnqCommon {
    char m_nameJpn[0x20];           // +0x00: get_o_name_jpn
    char m_nameEng[0x20];           // +0x20: get_o_name_eng
    unsigned short m_unk40;         // +0x40
    unsigned short m_iconNo;        // +0x42: get_o_icon_no
    unsigned short m_chrIdHigh;     // +0x44: get_o_chr_id_high
    unsigned short m_chrIdLow;      // +0x46: get_o_chr_id_low
    unsigned short m_smellUid1;     // +0x48: get_o_smell_uid_1
    unsigned short m_smellUid2;     // +0x4A: get_o_smell_uid_2
    unsigned short m_smellUid3;     // +0x4C: get_o_smell_uid_3
    unsigned short m_unk4E;         // +0x4E
    float m_menuOffsetPos[4];       // +0x50: get_o_menu_offset_pos (lq/sq)
    float m_menuOffsetRot[4];       // +0x60: get_o_menu_offset_rot (lq/sq)
    float m_smellRange;             // +0x70: copied to ObjStat::m_smellRange
    char m_nodeName[0x0C];          // +0x74: get_o_node_name
};

// Actor stats block at +0x80 of GamUnqMan types 0..3 (ACHRstat::m_unqStat at
// +0x404). Offsets from ACHRstat's linkonce get_a_max_lp..get_a_neck_rot_range.
struct ACHRUnqStat {
    unsigned short m_maxLp;         // +0x00: get_a_max_lp
    unsigned short m_st;            // +0x02: get_a_st
    unsigned short m_def;           // +0x04: get_a_def
    unsigned short m_avoid;         // +0x06: get_a_avoid
    unsigned short m_agi;           // +0x08: get_a_agi
    unsigned short m_neckRotRange;  // +0x0A: get_a_neck_rot_range
    unsigned char m_unk0C[0x4];     // +0x0C
};

// Five GamUnqMan record layouts (strides 0xA0, 0xC0, 0xE0, 0xC0, 0x200).
// Types 0..3 keep flags at +0x90; types 4..9 keep flags at +0xB0.
struct GamUnqA0 {
    GamUnqCommon m_common;          // +0x00
    ACHRUnqStat m_stat;             // +0x80
    unsigned int m_flg;             // +0x90
    unsigned char m_unk94[0x0C];
};

struct GamUnqC0_90 {
    GamUnqCommon m_common;          // +0x00
    ACHRUnqStat m_stat;             // +0x80
    unsigned int m_flg;             // +0x90
    unsigned int m_flg94;           // +0x94: func_001DD118/154/194
    unsigned char m_unk98[0x28];
};

struct GamUnqE0 {
    GamUnqCommon m_common;          // +0x00
    ACHRUnqStat m_stat;             // +0x80
    unsigned int m_flg;             // +0x90
    unsigned char m_unk94[0x4C];
};

struct GamUnqC0_B0 {
    GamUnqCommon m_common;          // +0x00
    unsigned char m_sub80[0x30];    // +0x80
    unsigned int m_flg;             // +0xB0
    unsigned char m_unkB4[0x0C];
};

struct GamUnq200 {
    GamUnqCommon m_common;          // +0x00
    unsigned char m_sub80[0x30];    // +0x80: FCHRstat::m_unk284 points here
    unsigned int m_flg;             // +0xB0
    unsigned char m_unkB4[0x14C];
};

// Small lookup table helper at the start of game/gamtrg.cpp (0x001D859C-0x001D8778).
struct GamTrg0 {
    unsigned int m_count;           // +0x00
    unsigned short *m_keys;         // +0x04
    unsigned short *m_vals;         // +0x08
    int m_defaultVal;               // +0x0C
};

// 0xB0-byte snapshot of ObjStat +0x100..+0x1AF (func_001D96EC / func_001D9830).
struct ObjStatSave {
    int m_data[0xB0 / 4];
};

// sizeof 0x280 (64-byte aligned via m_pool). Vtable pointer at +0x258.
class ObjStat {
public:
    unsigned char m_unk000[0x40];
    GamPool<int, 8> m_pool;         // +0x040..+0x0FF (m_nodes[8] at +0x80)
    int m_oid;                      // +0x100: getOID, get_o_oid
    int m_curStat;                  // +0x104: getCurStat, setCurStat, get_o_stat
    int m_chrID;                    // +0x108: getChrID, setChrID, get_o_chr_id
    int *m_sectaKeep;               // +0x10C: getSectaKeepPtr
    int *m_unk110;                  // +0x110
    int *m_secta;                   // +0x114: getSectaPtr; getSectaID returns its first word, or -1
    float m_smellRange;             // +0x118: get_o_smell_range
    float m_scale;                  // +0x11C: get_o_scale
    unsigned int m_flg;             // +0x120: getFlg, setFlg, unsetFlg, checkFlg, updateFlg
    unsigned short m_unk124;        // +0x124
    unsigned short m_lp;            // +0x126: ACHRstat::get_a_lp
    unsigned short m_uid;           // +0x128: getUID, get_o_uid
    unsigned short m_smellUid[3];   // +0x12A..+0x12E: copied from GamUnqCommon::m_smellUid1..3
    int m_areaNo;                   // +0x130: get_o_area_no
    int m_unk134;                   // +0x134
    int m_inuFunc;                  // +0x138: get_o_inu_func
    int m_unk13C;                   // +0x13C
    unsigned int m_flgV;            // +0x140: get_flg_v, set_flg_v
    float m_tmp;                    // +0x144: getTmp, setTmp
    int m_unk148;                   // +0x148
    int m_unk14C;                   // +0x14C
    tagColParam m_colPrm;           // +0x150: getColPrm, setColPrmImdy, restoreColPrm
    unsigned char m_unk180[0x10];
    float m_posParam[4];            // +0x190: getPosParam
    float m_rotParam[4];            // +0x1A0: getRotParam
    int m_unk1B0[0x10];             // +0x1B0..+0x1EF: func_001DB17C/18C/19C
    float m_keepPos[4];             // +0x1F0: getKeepPosPtr, setKeepPos; func_001D8D28 copies 4 floats
    unsigned char m_unk200[0x20];
    tagColParam m_colPrmKeep;       // +0x220: getColPrmKeep, setColPrm (which also sets m_colPrm)
    float m_tmp2;                   // +0x250: getTmp2, setTmp2
    int m_attachID;                 // +0x254: get_attach_id, set_attach_id

    // Vtable pointer at +0x258: GamMan's func_001CC7C8 deletes one through
    // it (slot 1, the destructor at 0x001D88C8). Two slots. Tail-padded to 0x280.
    virtual ~ObjStat();

    int getOID() const { return m_oid; }
    unsigned short getUID() const { return m_uid; }
    int getCurStat() const { return m_curStat; }
    void setCurStat(int theStat) { m_curStat = theStat; }
    int getChrID() const { return m_chrID; }
    void setChrID(int theID) { m_chrID = theID; }
    int *getSectaPtr() const { return m_secta; }
    int *getSectaKeepPtr() const { return m_sectaKeep; }
    int getSectaID() const { return m_secta ? *m_secta : -1; }
    bool checkFlg(unsigned int theFlg) const { return (m_flg & theFlg) != 0; }
    void setFlg(unsigned int theFlg) { m_flg |= theFlg; }
    void unsetFlg(unsigned int theFlg) { m_flg &= ~theFlg; }
    unsigned int getFlg() { return m_flg; }
    void updateFlg(unsigned int theFlg) { m_flg = theFlg; }
    void set_flg_v(unsigned int theFlg) { m_flgV = theFlg; }
    unsigned int get_flg_v() { return m_flgV; }
    float getTmp() const { return m_tmp; }
    void setTmp(float theTmp) { m_tmp = theTmp; }
    float getTmp2() const { return m_tmp2; }
    void setTmp2(float theTmp) { m_tmp2 = theTmp; }
    float *getKeepPosPtr() { return m_keepPos; }
    void setKeepPos(float x, float y, float z) { m_keepPos[0] = x; m_keepPos[1] = y; m_keepPos[2] = z; }
    void getPosParam(float *theOut)
    {
        theOut[0] = m_posParam[0];
        theOut[1] = m_posParam[1];
        theOut[2] = m_posParam[2];
        theOut[3] = m_posParam[3];
    }
    void getRotParam(float *theOut)
    {
        theOut[0] = m_rotParam[0];
        theOut[1] = m_rotParam[1];
        theOut[2] = m_rotParam[2];
        theOut[3] = m_rotParam[3];
    }
    void getColPrm(void *theOut) { *(tagColParam *)theOut = m_colPrm; }
    void getColPrmKeep(void *theOut) { *(tagColParam *)theOut = m_colPrmKeep; }
    void setColPrm(tagColParam thePrm)
    {
        m_colPrmKeep = thePrm;
        m_colPrm = thePrm;
    }
    void setColPrmImdy(tagColParam thePrm) { m_colPrm = thePrm; }
    void restoreColPrm() { m_colPrm = m_colPrmKeep; }
    int get_attach_id() { return m_attachID; }
    void set_attach_id(int theID) { m_attachID = theID; }
    void get_o_oid(void *theOut) { *(int *)theOut = m_oid; }
    void get_o_uid(void *theOut) { *(unsigned short *)theOut = m_uid; }
    void get_o_chr_id(void *theOut) { *(int *)theOut = m_chrID; }
    void get_o_stat(void *theOut) { *(int *)theOut = m_curStat; }
    void get_o_area_no(void *theOut) { *(int *)theOut = m_areaNo; }
    void get_o_secta_id(void *theOut) { *(int *)theOut = m_secta ? *m_secta : -1; }
    void get_o_inu_func(void *theOut) { *(int *)theOut = m_inuFunc; }
    void get_o_scale(void *theOut) { *(float *)theOut = m_scale; }
    void get_o_smell_range(void *theOut) { *(float *)theOut = m_smellRange; }
};

// A character that acts (the player, the dog, enemies...). sizeof 0x480
// (from __builtin_new in game/gamman.s).
class ACHRstat : public ObjStat {
public:
    struct GetterSlot {
        int m_w[2];
    };

    unsigned char m_unk280[0x08];       // +0x280 (func_001D9B2C memsets +0x280, 0x109)
    GetterSlot m_getters[33];           // +0x288..+0x38F: PTMF table populated by func_001D9B2C
    int m_unk390[16];                   // +0x390..+0x3CF
    int m_unk3D0;                       // +0x3D0
    int m_moveTaskID;                   // +0x3D4: get_a_move_type; task ID cleared in func_001DA07C
    int m_rotTaskID;                    // +0x3D8: task ID checked in func_001DA05C / cleared in 1DA07C
    int m_mtnTaskID;                    // +0x3DC: task ID checked in func_001D9F40 / cleared in 1DA07C
    int m_unk3E0;                       // +0x3E0: task ID cleared in func_001DA07C / 1DA1B4
    int m_unk3E4;                       // +0x3E4: task ID cleared in func_001D9E9C
    int m_unk3E8;                       // +0x3E8: task ID cleared in func_001D9E9C
    unsigned char m_unk3EC[0x10];
    float m_offsetRot;                  // +0x3FC: get_a_offset_rot
    GamUnqCommon *m_unqInfo;            // +0x400: get_o_name_jpn..get_o_node_name
    ACHRUnqStat *m_unqStat;             // +0x404: get_a_max_lp..get_a_neck_rot_range
    float m_unk408;                     // +0x408
    int m_unk40C;                       // +0x40C
    int m_unk410;                       // +0x410
    int m_unk414;                       // +0x414
    float m_unk418;                     // +0x418: func_001DB1B8
    float m_unk41C;                     // +0x41C
    float m_unk420;                     // +0x420
    GamUnqCommon *m_unk424;             // +0x424: GamUnqMan entry pointer
    unsigned short m_unk428;            // +0x428
    unsigned short m_unk42A;            // +0x42A
    unsigned short m_unk42C;            // +0x42C
    unsigned short m_unk42E;            // +0x42E
    unsigned short m_unk430;            // +0x430
    unsigned short m_unk432;            // +0x432
    unsigned short m_unk434;            // +0x434
    unsigned char m_unk436[0x06];
    int m_unk43C;                       // +0x43C
    unsigned short m_unk440;            // +0x440
    unsigned short m_unk442;            // +0x442
    float m_unk444;                     // +0x444
    float m_unk448;                     // +0x448
    unsigned short m_unk44C;            // +0x44C
    unsigned short m_unk44E;            // +0x44E
    float m_unk450;                     // +0x450
    unsigned short m_unk454;            // +0x454
    unsigned short m_unk456;            // +0x456
    unsigned short m_unk458;            // +0x458
    unsigned short m_unk45A;            // +0x45A
    int m_unk45C;                       // +0x45C
    float m_unk460;                     // +0x460
    unsigned short m_unk464;            // +0x464
    unsigned short m_unk466;            // +0x466
    unsigned short m_unk468;            // +0x468
    unsigned short m_unk46A;            // +0x46A
    unsigned short m_unk46C;            // +0x46C
    unsigned short m_unk46E;            // +0x46E
    unsigned short m_unk470;            // +0x470
    unsigned short m_unk472;            // +0x472
    unsigned short m_unk474;            // +0x474
    unsigned char m_pad476[0x0A];       // -> 0x480

    void get_a_lp(void *theOut) { *(unsigned short *)theOut = m_lp; }
    void get_a_move_type(void *theOut) { *(int *)theOut = m_moveTaskID; }
    void get_a_offset_rot(void *theOut) { *(float *)theOut = m_offsetRot; }
    void get_o_name_jpn(void *theOut) { if (m_unqInfo) *(const char **)theOut = m_unqInfo->m_nameJpn; }
    void get_o_name_eng(void *theOut) { if (m_unqInfo) *(const char **)theOut = m_unqInfo->m_nameEng; }
    void get_o_icon_no(void *theOut) { if (m_unqInfo) *(unsigned short *)theOut = m_unqInfo->m_iconNo; }
    void get_o_chr_id_high(void *theOut) { if (m_unqInfo) *(unsigned short *)theOut = m_unqInfo->m_chrIdHigh; }
    void get_o_chr_id_low(void *theOut) { if (m_unqInfo) *(unsigned short *)theOut = m_unqInfo->m_chrIdLow; }
    void get_o_smell_uid_1(void *theOut) { if (m_unqInfo) *(unsigned short *)theOut = m_unqInfo->m_smellUid1; }
    void get_o_smell_uid_2(void *theOut) { if (m_unqInfo) *(unsigned short *)theOut = m_unqInfo->m_smellUid2; }
    void get_o_smell_uid_3(void *theOut) { if (m_unqInfo) *(unsigned short *)theOut = m_unqInfo->m_smellUid3; }
    void get_o_menu_offset_pos(void *theOut)
    {
        if (m_unqInfo) {
            *(u_long128 *)theOut = *(const u_long128 *)m_unqInfo->m_menuOffsetPos;
        }
    }
    void get_o_menu_offset_rot(void *theOut)
    {
        if (m_unqInfo) {
            *(u_long128 *)theOut = *(const u_long128 *)m_unqInfo->m_menuOffsetRot;
        }
    }
    void get_a_max_lp(void *theOut) { if (m_unqStat) *(unsigned short *)theOut = m_unqStat->m_maxLp; }
    void get_a_st(void *theOut) { if (m_unqStat) *(unsigned short *)theOut = m_unqStat->m_st; }
    void get_a_def(void *theOut) { if (m_unqStat) *(unsigned short *)theOut = m_unqStat->m_def; }
    void get_a_avoid(void *theOut) { if (m_unqStat) *(unsigned short *)theOut = m_unqStat->m_avoid; }
    void get_a_agi(void *theOut) { if (m_unqStat) *(unsigned short *)theOut = m_unqStat->m_agi; }
    void get_a_neck_rot_range(void *theOut) { if (m_unqStat) *(unsigned short *)theOut = m_unqStat->m_neckRotRange; }
};

// A field object / item / prop. sizeof 0x2C0 (from __builtin_new in game/gamman.s).
class FCHRstat : public ObjStat {
public:
    GamUnq200 *m_unq;                   // +0x280: GamUnqMan entry pointer
    void *m_unk284;                     // +0x284: points to m_unq->m_sub80
    GamUnq200 *m_unk288;                // +0x288
    int m_unk28C;                       // +0x28C
    short m_unk290;                     // +0x290
    short m_unk292;                     // +0x292
    int m_unk294;                       // +0x294
    int m_unk298;                       // +0x298
    unsigned char m_pad29C[0x24];       // -> 0x2C0
};

// Map object sub-struct at GamMan + 0x18C00 (size 0x200).
// Methods: func_001DB8E8..func_001DBDF0.
struct GamMapObj {
    unsigned char m_unk000[0x1C0];
    int m_unk1C0;                       // +0x1C0: func_001DBCF0, func_001DBD54
    unsigned char m_unk1C4[0x0C];
    int m_unk1D0;                       // +0x1D0: func_001DBCF0
    unsigned char m_unk1D4[0x2C];       // -> 0x200
};

// Unique-object table manager at GamMan + 0x22220 (size 0x5C).
// Methods: func_001DBEF8..func_001DD1E0.
struct GamUnqMan {
    GamUnqA0 *m_a0;                     // +0x00: stride 0xA0, flg +0x90
    GamUnqA0 *m_a1;                     // +0x04: stride 0xA0, flg +0x90
    GamUnqC0_90 *m_a2;                  // +0x08: stride 0xC0, flg +0x90, flg94 +0x94
    GamUnqE0 *m_a3;                     // +0x0C: stride 0xE0, flg +0x90
    GamUnqC0_B0 *m_a4;                  // +0x10: stride 0xC0, flg +0xB0
    GamUnq200 *m_a5;                    // +0x14: stride 0x200, flg +0xB0
    GamUnqC0_B0 *m_a6;                  // +0x18: stride 0xC0, flg +0xB0
    GamUnqC0_B0 *m_a7;                  // +0x1C: stride 0xC0, flg +0xB0
    GamUnqC0_B0 *m_a8;                  // +0x20: stride 0xC0, flg +0xB0
    GamUnqC0_B0 *m_a9;                  // +0x24: stride 0xC0, flg +0xB0
    unsigned char m_unk28[0x30];
    void *m_raw;                        // +0x58: raw unq data header
};

struct GamTrgMapInfo {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    float m_unk20;
    float m_unk24;
    float m_unk28;
};

// Trigger entry (0xB0 bytes, aligned 16 -> GamList::Node is 0xC0 bytes).
struct GamTrgElem {
    float m_minX;                       // +0x00
    float m_minZ;                       // +0x04
    float m_maxX;                       // +0x08
    float m_maxZ;                       // +0x0C
    unsigned int m_unk10[4];            // +0x10..+0x1F
    unsigned int m_flg;                 // +0x20
    unsigned int m_unk24[2];            // +0x24..+0x2B
    int m_id;                           // +0x2C (also top 2 bits checked in func_001DDDBC)
    int m_unk30;                        // +0x30
    int m_unk34;                        // +0x34
    unsigned int m_unk38[3];            // +0x38..+0x43
    int m_unk44;                        // +0x44
    unsigned int m_unk48[10];           // +0x48..+0x6F
    unsigned int m_flg70;               // +0x70
    unsigned int m_unk74[(0xB0 - 0x74) / 4];
} __attribute__((aligned(16)));

// Ftb entry stored in GamTrgMan::m_ftbPool (0x24 bytes data, aligned 16 in
// GamList::Node so sizeof(Node) == 0x40; operator= copies the 0x24-byte inner
// struct, matching GamItemStock in game/gamman.h).
struct GamTrgFtbData {
    int m_key;                          // +0x00
    int m_vals[8];                      // +0x04..+0x23
};

struct GamTrgFtb {
    GamTrgFtbData m_data;

    GamTrgFtb &operator=(const GamTrgFtb &theOther)
    {
        m_data = theOther.m_data;
        return *this;
    }
} __attribute__((aligned(16)));

// Trigger manager at GamMan + 0x00040 (size 0x18B80).
// Methods: func_001DD1E8..func_001DEE78.
class GamTrgMan {
public:
    GamPool<GamTrgElem, 0x100> m_list0; // +0x00000..+0x0C1BF (nodes at +0x001C0)
    GamPool<GamTrgElem, 0x100> m_list1; // +0x0C1C0..+0x1837F (nodes at +0x0C380)
    GamPool<GamTrgElem, 0x8> m_list2;   // +0x18380..+0x18B3F (nodes at +0x18540)
    GamDynPool<GamTrgFtb> *m_ftbPool;   // +0x18B40: allocated in func_001DD414
    unsigned char m_unk18B44[0x14];
    int m_unk18B58;                     // +0x18B58: zeroed in func_001DD1E8
    int m_unk18B5C;                     // +0x18B5C: zeroed in func_001DDDAC
    unsigned char m_unk18B60[0x20];     // -> 0x18B80
};

// Still asm (game/gamtrg.cpp).
extern "C" {
void func_001DB31C(ObjStat *obj, int kind, void *value);   // one value by kind (8: the area)
void func_001DB71C(ObjStat *obj, float *pos);              // position
}

#endif
