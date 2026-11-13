// game/gamtrg.h (a guess: ObjStat's out-of-line methods, its destructor at
// 0x001D88C8 and the two functions below, are in game/gamtrg.cpp).
//
// ObjStat, a game object, and ACHRstat/FCHRstat (notes/class_hierarchy.txt:
// both derive from it). The classes, tagColParam and every inline method here
// are original names: the game keeps linkonce copies of the inline methods
// (0x0028F874-0x0028FDB0, symbols/symbol_addrs.txt), and each copy shows its
// member's offset. Member names follow the method (getChrID -> m_chrID): the
// offset and width are certain, the spelling is ours. m_unkXXX is what nothing
// names yet. Where the vtable pointer sits is not known (not declared).
#ifndef GAME_GAMTRG_H
#define GAME_GAMTRG_H

// setColPrm takes one by value and copies it as six doublewords: 0x30 bytes
// aligned to 8. What is inside is unknown.
struct tagColParam {
    long m_unk00[6];
};

class ObjStat {
public:
    unsigned char m_unk000[0x100];
    int m_oid;                      // +0x100: getOID, get_o_oid
    int m_curStat;                  // +0x104: getCurStat, setCurStat, get_o_stat
    int m_chrID;                    // +0x108: getChrID, setChrID, get_o_chr_id
    int *m_sectaKeep;               // +0x10C: getSectaKeepPtr
    unsigned char m_unk110[0x4];
    int *m_secta;                   // +0x114: getSectaPtr; getSectaID returns its first word, or -1
    float m_smellRange;             // +0x118: get_o_smell_range
    float m_scale;                  // +0x11C: get_o_scale
    unsigned int m_flg;             // +0x120: getFlg, setFlg, unsetFlg, checkFlg, updateFlg
    unsigned short m_unk124;
    unsigned short m_lp;            // +0x126: ACHRstat::get_a_lp
    unsigned short m_uid;           // +0x128: getUID, get_o_uid
    unsigned char m_unk12A[0x6];
    int m_areaNo;                   // +0x130: get_o_area_no
    unsigned char m_unk134[0x4];
    int m_inuFunc;                  // +0x138: get_o_inu_func
    unsigned char m_unk13C[0x4];
    unsigned int m_flgV;            // +0x140: get_flg_v, set_flg_v
    float m_tmp;                    // +0x144: getTmp, setTmp
    unsigned char m_unk148[0x8];
    tagColParam m_colPrm;           // +0x150: getColPrm, setColPrmImdy, restoreColPrm
    unsigned char m_unk180[0x10];
    float m_posParam[4];            // +0x190: getPosParam
    float m_rotParam[4];            // +0x1A0: getRotParam
    unsigned char m_unk1B0[0x40];
    float m_keepPos[3];             // +0x1F0: getKeepPosPtr, setKeepPos
    unsigned char m_unk1FC[0x24];
    tagColParam m_colPrmKeep;       // +0x220: getColPrmKeep, setColPrm (which also sets m_colPrm)
    float m_tmp2;                   // +0x250: getTmp2, setTmp2
    int m_attachID;                 // +0x254: get_attach_id, set_attach_id

    int getOID() const { return m_oid; }
    unsigned short getUID() const { return m_uid; }
    int getCurStat() const { return m_curStat; }
    void setCurStat(int theStat) { m_curStat = theStat; }
    int getChrID() const { return m_chrID; }
    void setChrID(int theID) { m_chrID = theID; }
    int *getSectaPtr() const { return m_secta; }
    int *getSectaKeepPtr() const { return m_sectaKeep; }
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
    int get_attach_id() { return m_attachID; }
    void set_attach_id(int theID) { m_attachID = theID; }
    void get_o_oid(void *theOut) { *(int *)theOut = m_oid; }
    void get_o_uid(void *theOut) { *(unsigned short *)theOut = m_uid; }
    void get_o_chr_id(void *theOut) { *(int *)theOut = m_chrID; }
    void get_o_stat(void *theOut) { *(int *)theOut = m_curStat; }
    void get_o_area_no(void *theOut) { *(int *)theOut = m_areaNo; }
    void get_o_inu_func(void *theOut) { *(int *)theOut = m_inuFunc; }
    void get_o_scale(void *theOut) { *(float *)theOut = m_scale; }
    void get_o_smell_range(void *theOut) { *(float *)theOut = m_smellRange; }
};

// A character that acts (the player, the dog, enemies...). Only what its
// inline methods (get_o_name_eng..get_a_neck_rot_range) read is known:
//   +0x3D4 int        get_a_move_type
//   +0x3FC float      get_a_offset_rot
//   +0x400 pointer    get_o_name_jpn; of it: +0x20 name_eng, +0x42 icon_no,
//                     +0x44 chr_id_high, +0x46 chr_id_low, +0x48/4A/4C
//                     smell_uid_1..3, +0x50 menu_offset_pos, +0x60
//                     menu_offset_rot (16 bytes each), +0x74 node_name
//   +0x404 pointer    to unsigned shorts: max_lp, st, def, avoid, agi,
//                     neck_rot_range
// Not declared as members yet: ObjStat's own size is not known.
class ACHRstat : public ObjStat {
};

class FCHRstat : public ObjStat {
};

// Still asm (game/gamtrg.cpp).
extern "C" {
void func_001DB31C(ObjStat *obj, int kind, void *value);   // one value by kind (8: the area)
void func_001DB71C(ObjStat *obj, float *pos);              // position
}

#endif
