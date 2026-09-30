// game/gamtrg.h (a guess: ObjStat's out-of-line methods, its destructor at
// 0x001D88C8 and the two functions below, are in game/gamtrg.cpp).
//
// ObjStat, a game object, reduced to what decompiled code reads so far.
// ObjStat, getOID and getUID are original names (linkonce copies of the
// inline methods); the rest is ours.
#ifndef GAME_GAMTRG_H
#define GAME_GAMTRG_H

class ObjStat {
public:
    unsigned char m_unk000[0x100];
    int m_oid;                      // +0x100: getOID
    unsigned char m_unk104[0x14];
    float m_smellRange;             // +0x118: get_o_smell_range
    unsigned char m_unk11C[0xC];
    unsigned short m_uid;           // +0x128: getUID

    int getOID() const { return m_oid; }
    unsigned short getUID() const { return m_uid; }
    void get_o_smell_range(void *theOut) { *(float *)theOut = m_smellRange; }
};

// Still asm (game/gamtrg.cpp).
extern "C" {
void func_001DB31C(ObjStat *obj, int kind, void *value);   // one value by kind (8: the area)
void func_001DB71C(ObjStat *obj, float *pos);              // position
}

#endif
