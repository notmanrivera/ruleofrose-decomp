#include "include_asm.h"
#include "task/cmnitask.h"
struct Ent63C0 {
    int unk0;
    int unk4;
    int unk8;
    int unk0C;
    char pad10[0x28 - 0x10];
};
struct Sub63C0 {
    Ent63C0 *arr;
};
struct Obj63C0 {
    char pad0[0xD40];
    Sub63C0 sub;
};
extern "C" int func_00180CA8(int *, int);
extern "C" void func_00180CE0(int *, int, int, int, int, float);
struct VObj7544 {
    virtual int vfunc1();
};
struct Node7544 {
    VObj7544 *obj;
    Node7544 *next;
    int state;
};
struct List7544 {
    Node7544 *head;
};
extern "C" void X7544_func_001E7340(List7544 *, Node7544 *, int) asm("func_001E7340");
struct VObj7340 {
    virtual int vfunc1();
    virtual void vfunc2(int);
};
struct Node7340 {
    VObj7340 *obj;
    Node7340 *next;
    int state;
};
struct Ent4B48 {
    char name[0x1C];
    int id;
    long unk20;
    long unk28;
    long unk30;
};
struct Obj4B48 {
    char pad[0x1544];
    Ent4B48 *list;
};
struct VObj747C {
    virtual int vfunc1();
};
struct Node747C {
    VObj747C *obj;
    Node747C *next;
    int state;
};
struct List747C {
    Node747C *head;
};
extern "C" void X747C_func_001E7340(List747C *, Node747C *, int) asm("func_001E7340");
struct Ent5D1C {
    char pad0[0x14];
    int unk14;
    int unk18;
    char pad1C[0x28 - 0x1C];
};
struct Sub5D1C {
    Ent5D1C *arr;
};
struct Obj5D1C {
    char pad0[0xD40];
    Sub5D1C sub;
};
extern "C" int func_001800D0(int *, int);
extern "C" void func_001801C8(int *, int);
struct Big484C {
    int w[0xC4E0 / 4];
};
struct Obj484C {
    char pad[0x1544];
    Big484C *unk1544;
};
struct Big4790 {
    int w[0xE000 / 4];
};
struct Obj4790 {
    char pad[0x1540];
    Big4790 *unk1540;
};
struct VObj7910 {
    virtual int vfunc1();
};
struct Node7910 {
    VObj7910 *obj;
    Node7910 *next;
    int state;
    int id;
};
struct List7910 {
    Node7910 *head;
};
extern "C" void X7910_func_001E7724(List7910 *, int) asm("func_001E7724");
struct Node785C {
    void *obj;
    Node785C *next;
    int state;
    int id;
};
struct Obj785C {
    Node785C *head;
    char pad4[0x80];
    int arr[0x80];
    int *end;
};
extern "C" void X785C_func_001E7D08(Obj785C *, Node785C *) asm("func_001E7D08");
struct Obj6D54 {
    void *unk0;
    int unk4;
    float unk8;
    void *unkC;
};
extern "C" void func_00237340(void *);
extern "C" void func_00237830(void *, void *, float);
extern "C" void func_002378B0(void *, void *, int);
extern "C" void func_00237408(void *, void *, void *);
extern "C" void func_002375D8(void *, void *);
extern "C" float func_00237580(void *, void *);
struct Ent4A0C {
    char name[0x1C];
    int id;
    char pad[0x38 - 0x20];
};
struct Obj4A0C {
    char pad[0x1540];
    Ent4A0C *list;
};
struct VObj77B4 {
    virtual int vfunc1();
};
struct Node77B4 {
    VObj77B4 *obj;
    Node77B4 *next;
    int state;
};
struct List77B4 {
    Node77B4 *head;
};
extern "C" void X77B4_func_001E7698(List77B4 *, Node77B4 *) asm("func_001E7698");
extern "C" void X77B4_func_001E7D08(List77B4 *, Node77B4 *) asm("func_001E7D08");
struct Node70DC {
    int unk0;
    Node70DC *next;
};
struct Sub70DC {
    int unk0;
    ~Sub70DC() asm("func_00203DA8");
};
struct Obj70DC {
    Node70DC *head0;
    Node70DC *head4;
    char pad8[0x38];
    Sub70DC sub40;
    ~Obj70DC() asm("func_001E70DC");
};
extern "C" void X70DC_func_001E7C7C(Obj70DC *, Node70DC *) asm("func_001E7C7C");
struct Ent4C1C {
    char name[0x1C];
    int id;
    char pad[0x38 - 0x20];
};
struct Obj4C1C {
    char pad[0x1544];
    Ent4C1C *list;
};
extern "C" int X4E20_func_001E4D04(int, int) asm("func_001E4D04");
extern "C" int func_001E50C8(int, int, int, int, float, int, int, int);
struct Ent4970 {
    char name[0x1C];
    int unk1C;
    char pad[0x38 - 0x20];
};
struct Obj4970 {
    char pad[0x1540];
    Ent4970 *list;
};
struct Ent4D18 {
    char pad0[0xC];
    unsigned int unk0C;
    char pad10[0x8];
    int unk18;
    char pad1C[0x28 - 0x1C];
};
struct Obj4D18 {
    char pad0[0xD40];
    Ent4D18 *arr;
};
extern "C" void func_001E649C(Obj4D18 *, unsigned int, int);
struct Obj7724 {
    char pad0[0x84];
    int arr[0x80];
    int *end;
};
extern "C" int func_001E76B8(Obj7724 *);
struct Ent4AB8 {
    char name[0x1C];
    int id;
    char pad[0x38 - 0x20];
};
extern "C" int strcmp(const char *, const char *);
struct Obj7C7C {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct Node7C7C {
    Obj7C7C *obj;
    int pad[4];
    int flags;
};
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void *X_memset(void *, int, unsigned int) asm("memset");
struct TskObj7618 {
    virtual int vfunc1(int);
};
struct TskNode7618 {
    TskObj7618 *obj;
    TskNode7618 *next;
    int state;
};
extern "C" int Xiiii_func_001E4908(int, int, int, int) asm("func_001E4908");
extern "C" int Xii_func_001E4D04(int) asm("func_001E4D04");
extern "C" int Xiiiiii_func_001E4EBC(int, int, int, int, int) asm("func_001E4EBC");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001E7DE8(int, int) asm("func_001E7DE8");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_0010A834__8DogActor(...) asm("func_0010A834__8DogActor");
extern "C" int X_func_0017F5E8(...) asm("func_0017F5E8");
extern "C" int X_func_001800D0(...) asm("func_001800D0");
extern "C" int X_func_001801C8(...) asm("func_001801C8");
extern "C" int X_func_00180B30(...) asm("func_00180B30");
extern "C" int X_func_00180CA8(...) asm("func_00180CA8");
extern "C" int X_func_00180EA8(...) asm("func_00180EA8");
extern "C" int X_func_001E46B8(...) asm("func_001E46B8");
extern "C" int X_func_001E4A0C(...) asm("func_001E4A0C");
extern "C" int X_func_001E4D04(...) asm("func_001E4D04");
extern "C" int X_func_001E4EBC(...) asm("func_001E4EBC");
extern "C" int X_func_001E649C(...) asm("func_001E649C");
extern "C" int X_func_001E7340(...) asm("func_001E7340");
extern "C" int X_func_001E7698(...) asm("func_001E7698");
extern "C" int X_func_001E76B8(...) asm("func_001E76B8");
extern "C" int X_func_001E7D08(...) asm("func_001E7D08");
extern "C" int X_func_001E7DE8(...) asm("func_001E7DE8");
extern "C" int X_func_00203D94(...) asm("func_00203D94");
extern "C" int X_func_0023A080(...) asm("func_0023A080");
extern "C" int X_func_0023A0B8(...) asm("func_0023A0B8");
extern "C" int X_strcmp(...) asm("strcmp");
extern int D_006FE6A0;
extern int D_007B2580;

// declarations from the code that moved to game/gamsnd:

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E7F28);

extern "C" void TskMtnMove__vfunc_05(void) {
}

extern "C" void TskMtnMove__vfunc_04(int arg0)
{
    short idx;
    long ent;
    int fp;
    short base;
    int off;
    int p;

    idx = M2C_FIELD(arg0, short *, 0x82);
    if (idx >= 0) {
        p = *(int *) (arg0 + M2C_FIELD(arg0, short *, 0x84));
        p += idx * 8;
        ent = *((long *) p - 1);
        fp = (int) (ent >> 32);
    } else {
        fp = M2C_FIELD(arg0, int *, 0x84);
    }
    base = M2C_FIELD(arg0, short *, 0x80);
    off = (idx >= 0) ? (short) ent + base : base;
    ((void (*)(int)) fp)(arg0 + off);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskMtnMove__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E85D0);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E89C0);

extern "C" int func_001E8F88(int arg0)
{
    return X_func_0010A834__8DogActor((int)&D_006FE6A0 + ((*(int *)(int *)((char *)(arg0) + 0xC)) * 0x4D0)) == 0;
}


extern "C" int func_001E8FBC()
{
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E8FC4);

extern "C" void TskMtnMove2__vfunc_05(void) {
}

extern "C" void TskMtnMove2__vfunc_04(int arg0)
{
    short idx;
    long ent;
    int fp;
    short base;
    int off;
    int p;

    idx = M2C_FIELD(arg0, short *, 0xCE);
    if (idx >= 0) {
        p = *(int *) (arg0 + M2C_FIELD(arg0, short *, 0xD0));
        p += idx * 8;
        ent = *((long *) p - 1);
        fp = (int) (ent >> 32);
    } else {
        fp = M2C_FIELD(arg0, int *, 0xD0);
    }
    base = M2C_FIELD(arg0, short *, 0xCC);
    off = (idx >= 0) ? (short) ent + base : base;
    ((void (*)(int)) fp)(arg0 + off);
}

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", TskMtnMove2__vfunc_02);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E93EC);




INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD940);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD948);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD950);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD958);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD960);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD968);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD970);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD978);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD980);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD988);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD990);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD998);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9A0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9A8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9B0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9B8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9C0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9C8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9D0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9D8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9E0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9E8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9F0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FD9F8);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA00);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA08);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA10);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA18);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA20);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA28);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA30);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA38);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA40);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA48);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA50);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA58);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA60);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA68);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA70);

INCLUDE_ASM("asm/nonmatchings/unk/TskMtnMove", func_001E9614);

INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA88);
INCLUDE_RODATA("asm/nonmatchings/unk/TskMtnMove", D_002FDA98);

// ---- once unk/TskMsgMan's head, the same file as the code above (config/splits_manual.tsv);
// its declarations as they were there:
struct TskVec4_f1670 {
    float f[4];
} __attribute__((aligned(16)));
extern "C" int X_func_001D2B8C_f1670(int, unsigned int) asm("func_001D2B8C");
extern "C" int X_func_001E7D7C_f1670(int, int) asm("func_001E7D7C");
extern "C" void X_func_001E7724_f1670(int, int) asm("func_001E7724");
extern "C" void X_func_001D06B8_f1670(void *, unsigned int, TskVec4_f1670 *) asm("func_001D06B8");
extern "C" int X___builtin_new_f1670(int) asm("__builtin_new");
extern "C" void X_func_001F0434_f1670(int, unsigned int, int, int, float, float, float, int, int) asm("func_001F0434");
extern "C" int X_func_001E71FC_f1670(int, int, int, int, int, int, int, int *, int) asm("func_001E71FC");
extern "C" void X_func_00191F44_v2(int, int) asm("func_00191F44");
extern "C" void X_func_00191F98_v2(int, int) asm("func_00191F98");
extern "C" void X_func_001351B0_v2(int, unsigned int, int) asm("func_001351B0");
static inline void pause_v2(unsigned int no, char *base)
{
    X_func_001351B0_v2((int)(base + 0x12540), no, 1);
    int s = (int)(base + 0x550F0);
    X_func_00191F44_v2(s, 0);
    X_func_00191F44_v2(s, 2);
    X_func_00191F44_v2(s, 1);
    X_func_00191F44_v2(s, 3);
    X_func_00191F44_v2(s, 5);
    X_func_00191F44_v2(s, 4);
    X_func_00191F44_v2(s, 6);
    X_func_00191F44_v2(s, 7);
    X_func_00191F44_v2(s, 8);
    X_func_00191F44_v2(s, 9);
    X_func_00191F44_v2(s, 0xA);
    X_func_00191F44_v2(s, 0xB);
    X_func_00191F44_v2(s, 0xC);
    X_func_00191F44_v2(s, 0xD);
}
static inline void resume_v2(unsigned int no, char *base)
{
    X_func_001351B0_v2((int)(base + 0x12540), no, 0);
    int s = (int)(base + 0x550F0);
    X_func_00191F98_v2(s, 0);
    X_func_00191F98_v2(s, 2);
    X_func_00191F98_v2(s, 1);
    X_func_00191F98_v2(s, 3);
    X_func_00191F98_v2(s, 5);
    X_func_00191F98_v2(s, 4);
    X_func_00191F98_v2(s, 6);
    X_func_00191F98_v2(s, 7);
    X_func_00191F98_v2(s, 8);
    X_func_00191F98_v2(s, 9);
    X_func_00191F98_v2(s, 0xA);
    X_func_00191F98_v2(s, 0xB);
    X_func_00191F98_v2(s, 0xC);
    X_func_00191F98_v2(s, 0xD);
}
extern "C" float X_func_002180E4_ecf3c(float *, float, float) asm("func_002180E4");
extern "C" void X_func_001F11A0_ecf3c(int, float, float, float) asm("func_001F11A0");
extern "C" int X_func_001E7D7C_ecf3c(int, int) asm("func_001E7D7C");
extern "C" int X_func_001EE7F0_ecf3c(unsigned int, unsigned short, float, float, int *, int, float) asm("func_001EE7F0");
extern "C" float X_func_002180E4_eacb8(float *, float, float) asm("func_002180E4");
extern "C" void X_func_001F11A0_eacb8(int, float, float, float) asm("func_001F11A0");
extern "C" int X_func_001E7D7C_eacb8(int, int) asm("func_001E7D7C");
extern "C" int X_func_001EE7F0_eacb8(unsigned int, unsigned short, float, float, int *, int, float) asm("func_001EE7F0");
struct TskVec4_ee954 {
    float f[4];
};
extern "C" float X_func_001333E4_ee954(int, int, int) asm("func_001333E4");
extern "C" void X_func_001331F4_ee954(int, int, int, int, int, int, float) asm("func_001331F4");
extern "C" int X_func_00118E6C_ee954(void *, int, float, float, TskVec4_ee954 *, float *, TskVec4_ee954 *) asm("func_00118E6C__9MagSystemiffR9DogVectorPfP9DogVector");
extern "C" float X_func_001F6C14_ee954(int, float) asm("func_001F6C14");
extern "C" int X_func_001F59B4_ee954(unsigned int, int, int, int, int, float, float) asm("func_001F59B4");
extern "C" void X_func_0018741C_50b8(int) asm("func_0018741C");
extern "C" int X_func_00187464_50b8(int) asm("func_00187464");
extern "C" void X_func_001874F4_50b8(int, int, int, int) asm("func_001874F4");
extern "C" char *X_strncpy_50b8(char *, const char *, int) asm("strncpy");
extern "C" int X_func_00134730_50b8(int, int, int, int, int) asm("func_00134730");
extern "C" void X_func_00118980__9MagSystemiiiiii(void *, int, int, int, int, int, int) asm("func_00118980__9MagSystemiiiiii");
extern "C" int X_func_001348B0_50b8(int, unsigned int) asm("func_001348B0");
extern "C" int X_func_00135594_50b8(int, unsigned int) asm("func_00135594");
extern "C" int X_func_001351B0_50b8(int, unsigned int, int) asm("func_001351B0");
extern "C" void X_func_00135418_50b8(int, unsigned int, int) asm("func_00135418");
extern "C" void X_func_00135494_50b8(int, unsigned int, int) asm("func_00135494");
extern "C" void X_func_00134CD0_50b8(int, unsigned int, int, int, int, int) asm("func_00134CD0");
struct TskVec4;
extern "C" float sqrtf(float);
extern "C" int X_func_001F59B4_ee7f0(unsigned int, int, int, int, int, float, float) asm("func_001F59B4");
extern "C" float Xf_func_001333E4_ee7f0(int, int, int) asm("func_001333E4");
extern "C" int X_func_00118E6C__9MagSystemiffR9DogVectorPfP9DogVector(
    void *, int, float, float, TskVec4 *, float *, TskVec4 *) asm("func_00118E6C__9MagSystemiffR9DogVectorPfP9DogVector");
extern "C" int Xiii_func_00143D7C(int, float *, int) asm("func_00143D7C");
extern int D_006FE6A0;
extern "C" int Xiiu_func_001CBE38(void *, unsigned int) asm("func_001CBE38");
extern "C" int X_func_001311F4_loc(int, int *) asm("func_001311F4");
extern "C" int Xiiiii_func_001311BC_loc(int, int, int, int) asm("func_001311BC");
struct DogVtblEntry {
    short delta;
    short unk2;
    void (*fn)(void *, float *, int);
};
extern "C" int Xipu_func_001CBDB8(void *, unsigned int) asm("func_001CBDB8");
extern "C" void X_ror_assert(const char *, int, const char *) asm("ror_assert");
extern "C" int Xiii_func_0022B3D8(int, int) asm("func_0022B3D8");
extern const char D_002FE698[];
extern const char D_002FE6A8[];
extern const char D_002FE6B8[];
extern "C" int Xiiu_func_001D2BA8(int, unsigned int) asm("func_001D2BA8");
extern int D_002FDFB0;
extern "C" float Xfi_func_001E9CB4(int) asm("func_001E9CB4");
extern "C" int Xiiff_func_001F0F9C(int, float, float) asm("func_001F0F9C");
extern "C" int Xiifff_func_001F11A0(int, float, float, float) asm("func_001F11A0");
extern "C" int Xiii_func_001D8964(int, int) asm("func_001D8964");
struct DogActorStub {
    char pad0[0x40];
    float unk40[3];
    char pad4C[4];
    float unk50[3];
    char pad5C[0x4D0 - 0x5C];
};
struct DogManStub {
    char pad0[0x2920];
    struct DogActorStub actors[1];
};
static inline struct DogActorStub *getDogActor(void *base, int idx)
{
    return (struct DogActorStub *)(((char *)base + idx * 0x4D0) + 0x2920);
}
struct TskMovePointPathObj {
    char pad0[4];
    int m_unk04;
    int m_unk08;
    char pad0C[0x14];
    int m_unk20;
    char pad24[0xC];
    int m_unk30;
    char pad34[0xC];
    float m_unk40[4];
    char pad50[0x10];
    float m_unk60[4];
    int (TskMovePointPathObj::*m_func)();
    char pad78[0x8];
    float m_unk80;
};
extern "C" int Xiii_func_001D8ADC_mpp(int, int) asm("func_001D8ADC");
extern "C" void Xv_func_001EC834_mpp(TskMovePointPathObj *) asm("func_001EC834");
extern "C" void Xv_func_001F59B4_mpp(int, int, int, int, int, float, float) asm("func_001F59B4");
extern "C" int X_func_001E71FC(int, int, int, int, int, int, int, int, int) asm("func_001E71FC");
extern "C" int Xii___builtin_new(int) asm("__builtin_new");
extern "C" int Xiii_func_001E7724(int, int) asm("func_001E7724");
extern "C" int Xiii_func_001E7D7C_2(int, int) asm("func_001E7D7C");
extern "C" int Xfunc_001F0434(int, unsigned int, int, int, float, float, float, int, int) asm("func_001F0434");
extern "C" void Xv_func_001CFE78(int, unsigned int, int) asm("func_001CFE78");
extern "C" int Xiu_func_001EE7F0(unsigned int, unsigned short, int, float, float, int, float) asm("func_001EE7F0");
extern "C" void Xv_setActorRot__9MagSystemiPCf(int, int, int) asm("setActorRot__9MagSystemiPCf");
extern "C" void Xv_func_001E6734(int, int, int, int, int, int) asm("func_001E6734");
extern "C" void Xv_func_0017F5E8(int, int) asm("func_0017F5E8");
extern "C" void Xv_strncpy(char *, const char *, int) asm("strncpy");
extern "C" void Xv_func_00191E58(int, int, int) asm("func_00191E58");
extern "C" void Xv_func_00192834(int, char *) asm("func_00192834");
extern "C" void Xv_func_001F0E90(unsigned int, float, int) asm("func_001F0E90");
extern "C" int Xiff_func_001F6B8C(float, float) asm("func_001F6B8C");
extern "C" void Xv_func_001F1298(int, float, int, float) asm("func_001F1298");
struct GamHitInfo {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    GamHitInfo() { unk10 = 0; }
};
extern "C" void Xvp_func_001D890C(int, int) asm("func_001D890C");
extern "C" int Xiii_func_001D8B5C(int, int) asm("func_001D8B5C");
extern "C" void Xvp_func_001D89C4(int, int) asm("func_001D89C4");
extern "C" float Xff_cosf(float) asm("cosf");
extern "C" float Xff_sinf(float) asm("sinf");
extern "C" float Xfpff_func_002180E4(float *, float, float) asm("func_002180E4");
struct TskMoveSectaFindPathObj {
    char pad0[0x20C];
    int m_unk20C;
    char pad210[0x8];
    int m_unk218;
    int m_unk21C;
    char pad220[0x70];
    int *m_unk290;
    char pad294[0x24];
    int (TskMoveSectaFindPathObj::*m_func)();
};
extern "C" int X_func_001ED1D0(TskMoveSectaFindPathObj *) asm("func_001ED1D0");
struct TskHitCheck {
    void *m_origin_pos;
    int m_rotate;
    float m_angle;
    void *m_target_pos;
    float m_scale;
};
extern "C" void Xv_func_001D05F4(void *, unsigned int, TskVec4 *) asm("func_001D05F4");
extern "C" void Xv_func_001D06B8(void *, unsigned int, TskVec4 *) asm("func_001D06B8");
extern "C" float Xf_func_001D4A3C(void *, unsigned int, int) asm("func_001D4A3C");
extern "C" int Xi_func_0010456C(TskHitCheck *) asm("func_0010456C");
extern "C" float Xfi_func_001EA5EC(int) asm("func_001EA5EC");
extern "C" int Xiif_func_001EAFB0(int, float) asm("func_001EAFB0");
extern "C" int Xiu_func_001F61EC(unsigned int) asm("func_001F61EC");
extern "C" void Xv_TskMsgMan__vfunc_05(int) asm("TskMsgMan__vfunc_05");
extern "C" void Xvii_func_00183B24(int, int) asm("func_00183B24");
extern int _vt$9TskMsgMan;
struct TskAvoidMoveObj {
    char pad0[0xC];
    unsigned int m_unk0C;
    char pad10[0x6C];
    int (TskAvoidMoveObj::*m_func)();
};
struct TskMoveTypeGenObj {
    char pad0[0x60];
    int m_unk60;
    char pad64[0x18];
    void (TskMoveTypeGenObj::*m_func)();
};
extern "C" void Xv_func_001EAF00(void *) asm("func_001EAF00");
extern "C" void Xv_func_0025B878(...) asm("func_0025B878");
extern "C" void Xvii_func_001D8B9C(int, int) asm("func_001D8B9C");
extern "C" int Xii_func_00187464(int) asm("func_00187464");
extern "C" int Xiiu_func_001348B0(int, unsigned int) asm("func_001348B0");
extern "C" int Xiiu_func_00135594(int, unsigned int) asm("func_00135594");
extern "C" int Xiiui_func_001351B0(int, unsigned int, int) asm("func_001351B0");
extern int D_002FE590;
extern "C" int Xi_rand() asm("rand");
struct MagGameFlags2 {
    int m_unk00;
    int m_flags;
};
extern MagGameFlags2 *D_007B2060;
extern "C" int Xii_func_00192920(int) asm("func_00192920");
extern "C" int Xii_func_001CF95C(int) asm("func_001CF95C");
extern int _9MagSystem$m_v_rate;
extern int _vt$8TskMovie;
extern "C" void TskMovie__vfunc_05();
extern "C" int Xii_func_001A06D4(int, int) asm("func_001A06D4");
extern "C" int Xii_func_001A0BA0(int) asm("func_001A0BA0");
extern int D_007B205C;
extern int _9MagSystem$m_current_system;
extern "C" int Xiiu_func_001D19A8(int, unsigned int) asm("func_001D19A8");
// u_long128: include/target.h
extern int _vt$10TskSysFunc;
extern int _vt$9TskRotAdj;
extern int _vt$16TskMoveTypeRound;
extern int _vt$14TskMoveTypeGen;
extern int _vt$12TskMoveSecta;
extern int _vt$20TskMoveSectaFindPath;
extern int _vt$16TskMovePointPath;
extern int _vt$13TskMovePhysic;
extern int _vt$10TskMoveAdj;
extern int _vt$12TskFrameFunc;
extern int _vt$9TskChrRot;
extern int _vt$12TskAvoidMove;
extern "C" void Xv___builtin_delete(int) asm("__builtin_delete");
extern int _vt$9TskAttach;
struct m2c_block8 { int w[2]; };
struct m2c_ulong { long v; } __attribute__((packed));
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
extern "C" int Xiiu_func_001D2B8C(int, unsigned int) asm("func_001D2B8C");
extern int D_002FE588;
extern int D_002FE5E0;
extern int D_002FE5E8;
extern int _vt$11TskSeqEvent;
extern int _vt$15TskGenFrameFunc;
extern "C" float Xfi_func_0010A650__8DogActor(int) asm("func_0010A650__8DogActor");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_001C5D08(int, int) asm("func_001C5D08");
extern "C" int Xiii_func_001CB57C(int, int) asm("func_001CB57C");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiiiii_getActorNodeMatrix__9MagSystemiP19tag_I3dMatrixF4x4_sPCc(int, int, int, int) asm("getActorNodeMatrix__9MagSystemiP19tag_I3dMatrixF4x4_sPCc");
extern "C" int Xiiiiiii_func_0013F980__8MagSceneiiiPfi(int, int, int, int, int, int) asm("func_0013F980__8MagSceneiiiPfi");
extern "C" int Xiiiiiii_func_001CD044(int, int, int, int, int, int) asm("func_001CD044");
extern "C" int Xiiu_func_001D046C(int, unsigned int) asm("func_001D046C");
extern "C" int Xiiui_func_00213D00(int, unsigned int, int) asm("func_00213D00");
extern "C" int Xiiuiii_func_00211BE4(int, unsigned int, int, int, int) asm("func_00211BE4");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_00131184(...) asm("func_00131184");
extern "C" int X_func_001348B0(...) asm("func_001348B0");
extern "C" int X_func_001351B0(...) asm("func_001351B0");
extern "C" int X_func_00135594(...) asm("func_00135594");
extern "C" int X_func_0017F8FC(...) asm("func_0017F8FC");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001913C4(...) asm("func_001913C4");
extern "C" int X_func_0019143C(...) asm("func_0019143C");
extern "C" int X_func_00191478(...) asm("func_00191478");
extern "C" int X_func_00191F44(...) asm("func_00191F44");
extern "C" int X_func_00191F98(...) asm("func_00191F98");
extern "C" int X_func_001A0684(...) asm("func_001A0684");
extern "C" int X_func_001A074C(...) asm("func_001A074C");
extern "C" int X_func_001C5D08(...) asm("func_001C5D08");
extern "C" int X_func_001C65E8(...) asm("func_001C65E8");
extern "C" int X_func_001C6A40(...) asm("func_001C6A40");
extern "C" int X_func_001CD044(...) asm("func_001CD044");
extern "C" int X_func_001CF9D4(...) asm("func_001CF9D4");
extern "C" int X_func_001CFA5C(...) asm("func_001CFA5C");
extern "C" int X_func_001D046C(...) asm("func_001D046C");
extern "C" int X_func_001D19A8(...) asm("func_001D19A8");
extern "C" int X_func_001E7724(...) asm("func_001E7724");
extern "C" int X_func_001E7D7C(...) asm("func_001E7D7C");
extern "C" int X_func_001EA5EC(...) asm("func_001EA5EC");
extern "C" int X_func_001EAFB0(...) asm("func_001EAFB0");
extern "C" int X_func_001F61EC(...) asm("func_001F61EC");
extern "C" int X_func_00211BE4(...) asm("func_00211BE4");
extern "C" int X_func_00213D00(...) asm("func_00213D00");
extern "C" int X_rand(...) asm("rand");
extern int D_006E9840;
extern int D_006FBD80;
extern int D_0073E91C;
extern int D_007812C0;
extern int D_007A3D80;
extern int D_007A4440;
extern int D_007B2580;

extern "C" int func_001E9A34()
{
    return 1;
}


