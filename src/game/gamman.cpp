#include "include_asm.h"
#include "game/gamtrg.h"
#include "game/gamman.h"
extern "C" void X_func_001D95C4_CF518(ObjStat *, int) asm("func_001D95C4");
struct Tbl4_C58C0 {
    int a, b, c, d; };
extern const Tbl4_C58C0 D_002FB920;
extern int D_007B45C0;
extern "C" int X_func_001CBDB8_C58C0(GamMan *, unsigned int) asm("func_001CBDB8");
extern "C" void X_func_001DA130_C58C0(ACHRstat *, int, int) asm("func_001DA130");
extern "C" void X_func_001E747C_C58C0(void *, void *, int) asm("func_001E747C");
extern "C" void X_func_001E7414_C58C0(void *, int, int) asm("func_001E7414");
extern "C" void X_func_001CBB80_CB74C(GamMan *, int) asm("func_001CBB80");
extern "C" void X_func_0013166C_CB74C(void *, int, int) asm("func_0013166C");
class EntityStub_C5A5C {
public:
    char pad00[0x94];
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void setHide(bool theHide); };
class ActorStub_C5A5C : public EntityStub_C5A5C {
public:
    char pad98[0x4D0 - 0x98]; };
struct SceneStub_C5A5C {
    char pad00[0x2920];
    ActorStub_C5A5C m_actor[128];
    void setActorHide(int theNo, bool theHide) { m_actor[theNo].setHide(theHide); } };
extern SceneStub_C5A5C gScene_C5A5C asm("D_006FBD80");
extern "C" void X_func_001DA228_C5A5C(ACHRstat *, int, unsigned int *) asm("func_001DA228");
extern "C" void X_func_001D1410_C5A5C(GamMan *, unsigned int, int) asm("func_001D1410");
static inline unsigned int &flg3F4_C5A5C(ACHRstat *p) { return *(unsigned int *)((char *)p + 0x3F4); }
static inline bool chk3F4_C5A5C(ACHRstat *p, unsigned int f) { return (flg3F4_C5A5C(p) & f) != 0; }
extern "C" void X_ror_assert_D1A5C(const char *, int, const char *) asm("ror_assert");
extern char D_002FBB78[];
extern char D_002FBB88[];
extern char D_002FBB98[];
extern "C" void *X_memset_D1A5C(void *, int, unsigned int) asm("memset");
extern "C" int func_0022B3D8(void *, const char *);
extern "C" int func_00260110(const char *, ...);
extern "C" void attachActor__9MagSystemiii(void *, int, int, int);
struct ModelStub_D1A5C {
    char pad00[0x11C];
    void *m_i3r_root;
    char pad120[0x4D0 - 0x120];
    int getNodeIndexByName(const char *p)
    {
        if (!m_i3r_root) X_ror_assert_D1A5C(D_002FBB78, 0x131, D_002FBB88);
        if (!p) X_ror_assert_D1A5C(D_002FBB78, 0x131, D_002FBB98);
        return func_0022B3D8(m_i3r_root, p);
    } };
extern ModelStub_D1A5C D_006FE6A0_D1A5C[] asm("D_006FE6A0");
class EntityStub_687C {
public:
    char pad00[0x94];
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void setHide(bool theHide);
};
class ActorStub_687C : public EntityStub_687C {
public:
    char pad98[0x4D0 - 0x98];
};
struct SceneStub_687C {
    char pad00[0x2920];
    ActorStub_687C m_actor[128];
    void setActorHide(int theNo, bool theHide)
    {
        m_actor[theNo].setHide(theHide);
    }
};
extern SceneStub_687C gScene_687C asm("D_006FBD80");
extern "C" int Xiiu_func_001CBE38(int, unsigned int) asm("func_001CBE38");
extern "C" void func_001F688C();
extern "C" void func_001D8F04(void *, float *);
extern "C" void func_001D8964(void *, float *);
extern "C" void func_001E100C(void *, float *);
extern "C" void func_001DEE78(void *, float *, float *);
static inline GamItem *itemAt_8AE8(GamItem *base, int off)
{
    return (GamItem *)((char *)base + off);
}
extern "C" void func_001C5BF4(GamMan *, int) throw();
extern "C" int Xiii_func_001D9F10(int, int) asm("func_001D9F10");
extern "C" void Xiiii_setPlayer__9MagSystemii(int, int, int) asm("setPlayer__9MagSystemii");
extern "C" int Xiiuhi_func_001C7210(int, unsigned int, unsigned char, int) asm("func_001C7210");
struct MapModelHide {
    int hide;
    char pad[0x520 - 4];
};
extern MapModelHide D_00725410[];
struct ActorStub_CA8E8 {
    char pad00[0x60];
    float m_x;
    float m_y;
    float m_z;
    float m_w;
    char pad70[0x20];
    int m_unk90;
    char pad94[0x4D0 - 0x94];
};
struct SceneStub_CA8E8 {
    char pad00[0x2920];
    ActorStub_CA8E8 m_actor[128];
};
struct SystemStub_CA8E8 {
    char pad00[0x12540];
    SceneStub_CA8E8 m_scene;
    void setScale(int theNo, float x, float y, float z)
    {
        ActorStub_CA8E8 *p = &m_scene.m_actor[theNo];
        p->m_z = p->m_y = p->m_x = x;
        p->m_unk90 = 1;
    }
};
extern "C" void func_001D1C80(GamMan *, unsigned int, int, void *);
extern "C" void func_001D88FC(ObjStat *);
extern "C" void func_001E7544(void *, int);
extern "C" int func_001C574C() throw();
extern "C" int X_func_001C58B8(GamMan *, int) asm("func_001C58B8");
extern "C" void func_001C58C0(GamMan *, int);
extern "C" void func_001D3B44(GamMan *);
extern "C" void X_void_191E04(void *, int, int) asm("func_00191E04");
extern "C" void X_void_191E58(void *, int, int) asm("func_00191E58");
extern "C" void func_00191C00(void *, int, int, int, int);
extern "C" void func_001CF95C(GamMan *);
extern "C" void func_001CDBF0(GamMan *);
extern "C" void func_001C143C(GamMan *);
extern "C" void func_001CF518(GamMan *, int);
extern "C" void func_001E77B4(void *, int);
struct GamList16 {
    struct Node {
        Node *m_prev;
        Node *m_next;
        int m_data[4];
    };
    struct Chain {
        Node m_head;
        int m_num;
        void splice(Chain &theOther)
        {
            if (theOther.m_num != 0) {
                m_head.m_prev->m_next = theOther.m_head.m_next;
                Node *last = m_head.m_prev;
                last->m_next->m_prev = last;
                Node *tail = theOther.m_head.m_prev;
                m_head.m_prev = tail;
                tail->m_next = &m_head;
                m_num += theOther.m_num;
                theOther.m_num = 0;
                theOther.m_head.m_prev = &theOther.m_head;
                theOther.m_head.m_next = &theOther.m_head;
            }
        }
    };
    Chain m_free;
    Chain m_used;
    int m_max;
    int size() const { return m_used.m_num; }
    void clear() { m_free.splice(m_used); }
};
extern "C" void X_func_001C6A40(GamMan *, int) asm("func_001C6A40");
extern "C" int X_func_001F184C(...) asm("func_001F184C");
extern "C" void func_001D5DA0(GamMan *, int);
extern "C" void func_001D3588(GamMan *);
extern "C" void func_0017756C(void *, int);
extern "C" int X_func_001D2BA8(...) asm("func_001D2BA8");
extern "C" int X_func_00191E04(...) asm("func_00191E04");
struct Item1A6C0 {
    int unk0;
    int unk4;
    unsigned short unk8;
    unsigned short unkA;
    int unkC;
    Item1A6C0(void *sub, unsigned short id);
};
extern "C" void func_001C7A4C(GamMan *, unsigned short);
extern "C" void func_001C9784(GamMan *, unsigned short);
extern "C" int func_001DBFA0(void *, unsigned short);
inline Item1A6C0::Item1A6C0(void *sub, unsigned short id)
{
    unk0 = func_001DBFA0(sub, id);
    unk8 = id;
}
extern "C" int X_func_0017F200(...) asm("func_0017F200");
extern "C" int X_func_0024B3F8(...) asm("func_0024B3F8");
extern "C" int X_func_00191D20(...) asm("func_00191D20");
extern "C" int X_func_00191D74(...) asm("func_00191D74");
extern "C" int X_func_00191DC8(...) asm("func_00191DC8");
extern "C" int X_func_00191ED0(...) asm("func_00191ED0");
extern "C" int X_func_00191F98(...) asm("func_00191F98");
extern "C" int func_001C8A28(void *, int, int);
extern "C" int func_001BFFCC(int, int);
extern "C" int func_001C020C(int, int);
extern "C" int func_001C0254(int, int);
extern "C" int func_001BE084(int);
extern "C" void func_001BDC54(int);
extern "C" void func_0018BC18(char *, int);
extern "C" void func_00183B24(char *, int);
extern "C" void X_del(void *) asm("__builtin_delete");
extern "C" void func_0017762C(void *);
struct ListNode {
    ListNode *prev;
    ListNode *next;
    char pad[8];
    int count;
};
extern "C" int func_00143D7C(char *, char *, int);
extern "C" int func_001C6FE0(GamMan *, int, int, int);
extern "C" void func_001CC250(GamMan *, int, int, int, int, int);
extern "C" int func_001CFBE4(int, unsigned int, int);
extern "C" int func_0017EA44(void *, int);
extern "C" int func_001DB8E8(char *, int, int);
extern "C" int func_00279C98(void *, const char *, ...);
extern "C" void X_func_001CF7D0(char *, const void *) asm("func_001CF7D0");
extern "C" void X_func_001CF854(char *, void *, int, int) asm("func_001CF854");
extern int D_00298EE0;
extern int D_006E9640;
struct Header1F84 {
    int data[8];
};
struct Entry1F84 {
    int data[12];
};
struct DstEntry1F84 {
    Entry1F84 entry;
    int pad[8];
};
extern "C" int func_001D2AAC(int, unsigned int);
extern "C" int func_001D2ADC(int, unsigned int);
extern "C" int func_001D2B10(int, unsigned int);
extern "C" int func_001D890C(int, int);
extern "C" int Xiii_func_001DB71C(int, int) asm("func_001DB71C");
extern "C" int func_001D89C4(int, int);
extern "C" int func_001DB7CC(int, int);
extern "C" int X_func_001D84B0(...) asm("func_001D84B0");
extern "C" void func_001331F4(void *, int, int, int, int, int, float);
extern "C" char vtbl_GamMan[] asm("_vt$6GamMan");
extern "C" void GamSndMan__vfunc_01(void *, int);
extern "C" void func_001DD3EC(void *, int);
extern "C" float func_0010A650__8DogActor(void *);
extern "C" int X_func_001C772C(...) asm("func_001C772C");
extern "C" int X_func_001E4540(...) asm("func_001E4540");
extern "C" void *bsearch(const void *, const void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern "C" int func_001C0534(int, unsigned int);
extern "C" int func_001BFFAC(unsigned short *, unsigned short *);
extern "C" int Xiiu_func_001D2D00(int, unsigned int) asm("func_001D2D00");
extern "C" int func_001D966C(int);
extern "C" int X_loadModel__9MagSystemii(void *, int, int) asm("loadModel__9MagSystemii");
extern "C" void func_001CCC30(GamMan *, int);
extern "C" int func_001C0148(int, int);
extern "C" int func_001C0298(int, int);
extern "C" int func_001C02B8(int, int);
struct __attribute__((aligned(8))) DogVector {
    float m_x;
    float m_y;
    float m_z;
    float m_w;
    DogVector() {}
    DogVector(float x, float y, float z, float w)
    {
        m_x = x;
        m_y = y;
        m_z = z;
        m_w = w;
    }
};
struct PcEffParam {
    int m_kind;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    DogVector m_pos;
    float m_rot[3];
    int m_num;
    int m_pad[20];
};
extern "C" int func_00176CC8(void *, void *);
extern "C" void func_001CBA0C(GamMan *, void *, int);
extern "C" int X_func_0018741C(...) asm("func_0018741C");
extern "C" int X_func_00187464(...) asm("func_00187464");
extern "C" int X_func_001874AC(...) asm("func_001874AC");
extern "C" int X_func_001874F4(...) asm("func_001874F4");
extern "C" int X_func_001875C0(...) asm("func_001875C0");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern int D_002B8C90;
extern "C" void func_001348B0(void *, int) asm("func_001348B0");
extern "C" void func_00135594(void *, int) asm("func_00135594");
extern "C" void *func_001D2B8C();
extern "C" void *func_001D2BA8();
extern "C" void func_00191D20(void *, int, int);
extern "C" void func_00191D74(void *, int, int);
extern "C" int func_001E7D7C(void *, int);
extern "C" int func_0013F444(void *, int);
extern "C" int func_001DC48C(void *, int, int, int *);
extern "C" int func_001DD00C(void *, int, int);
extern int D_002B8870;
extern "C" void func_00191BA8(char *, int, int, int);
extern "C" void func_00191C64(char *, int, int, int);
extern "C" void setActorLight__9MagSystemii(void *, int, int);
extern "C" void ror_assert(const char *, int, const char *);
struct MapModel {
    int val;
    char pad[0x520 - 4];
};
extern MapModel D_007257B8[];
extern "C" void func_001CB01C(GamMan *, int);
extern "C" void func_001CDF5C(GamMan *, int, int);
extern "C" void func_0018BD94(char *);
extern "C" int X4_func_0013F280(int, int, int, int) asm("func_0013F280");
extern "C" int X_func_00243C40(int, int, int) asm("func_00243C40");
extern "C" int X_func_001CBE38(int, int) asm("func_001CBE38");
extern int D_006FE6A0;
extern "C" void X_func_00144500(...) asm("func_00144500");
extern "C" int func_001C0298(int arg0, int arg1);
extern char *D_007B205C;
extern "C" int X_func_00191E58(...) asm("func_00191E58");
extern char D_006FBD80[];
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void X_func_001BE564(...) asm("func_001BE564");
extern "C" int Xiiiii_func_001BE444(int, int, int, int) asm("func_001BE444");
extern "C" int Xiii_func_001BE3C4(int, int) asm("func_001BE3C4");
extern "C" int Xiiiii_func_001BE36C(int, int, int, int) asm("func_001BE36C");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int X_FlushCache(...) asm("FlushCache");
extern "C" int X_func_001E71FC(...) asm("func_001E71FC");
extern "C" int X_sceGsExecLoadImage(...) asm("sceGsExecLoadImage");
extern "C" int X_sceGsSetDefLoadImage(...) asm("sceGsSetDefLoadImage");
extern "C" int X_sceGsSyncPath(...) asm("sceGsSyncPath");
extern "C" int Xii___builtin_new(int) asm("__builtin_new");
extern "C" int Xii_func_00144334(int) asm("func_00144334");
extern "C" int Xii_func_0018741C(int) asm("func_0018741C");
extern "C" int Xii_func_00187464(int) asm("func_00187464");
extern "C" int Xii_func_0018FEBC(int) asm("func_0018FEBC");
extern "C" int Xii_func_001BE048(int) asm("func_001BE048");
extern "C" int Xii_func_001D8DC4(int) asm("func_001D8DC4");
extern "C" void Xii_func_001D8FEC(int, int) asm("func_001D8FEC");
extern "C" int Xii_func_001D9F40(int) asm("func_001D9F40");
extern "C" int Xii_func_001D9F84(int) asm("func_001D9F84");
extern "C" int Xii_func_001DA05C(int) asm("func_001DA05C");
extern "C" int Xiii_func_0018BCC0(int, int) asm("func_0018BCC0");
extern "C" int Xiii_func_001CBAFC(int, int) asm("func_001CBAFC");
extern "C" int Xiii_func_001D8964(int, int) asm("func_001D8964");
extern "C" int Xiii_func_001DB774(int, int) asm("func_001DB774");
extern "C" int Xiii_func_001E7724(int, int) asm("func_001E7724");
extern "C" int Xiii_func_001E7D7C(int, int) asm("func_001E7D7C");
extern "C" int Xiiii_func_0011825C__9MagSystemii(int, int, int) asm("func_0011825C__9MagSystemii");
extern "C" int Xiiii_func_0018F744(int, int, int) asm("func_0018F744");
extern "C" int Xiiii_func_001C82F8(int, int, int) asm("func_001C82F8");
extern "C" int Xiiii_func_001C94D8(int, int, int) asm("func_001C94D8");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiiii_ror_assert(int, int, int) asm("ror_assert");
extern "C" int Xiiiii_func_001CB970(int, int, int, int) asm("func_001CB970");
extern "C" int Xiiiiii_func_00134730(int, int, int, int, int) asm("func_00134730");
extern "C" int Xiiiiiiii_func_001F4A24(int, int, int, int, int, int, int) asm("func_001F4A24");
extern "C" int Xiiu_func_001348B0(int, unsigned int) asm("func_001348B0");
extern "C" int Xiiu_func_00135594(int, unsigned int) asm("func_00135594");
extern "C" int Xiiu_func_001D046C(int, unsigned int) asm("func_001D046C");
extern "C" int Xiiu_func_001D2B8C(int, unsigned int) asm("func_001D2B8C");
extern "C" int Xiiu_func_001D2BA8(int, unsigned int) asm("func_001D2BA8");
extern "C" int Xiiui_func_001351B0(int, unsigned int, int) asm("func_001351B0");
extern "C" int Xiiui_func_001D05F4(int, unsigned int, int) asm("func_001D05F4");
extern "C" float func_00217F10(float, float);
extern "C" int Xiiuii_func_00134AB8(int, unsigned int, int, int) asm("func_00134AB8");
extern "C" int Xiiuiii_func_00134A00(int, unsigned int, int, int, int) asm("func_00134A00");
extern const char D_002FB330[];
extern const char D_002FB350[];
extern int D_002B89E0;
extern int D_006FE04C;
extern int D_00727BD0;
extern "C" int X_func_00118ED8__9MagSystemiii(...) asm("func_00118ED8__9MagSystemiii");
extern "C" int X_func_00118F30__9MagSystemii(...) asm("func_00118F30__9MagSystemii");
extern "C" int X_func_00163AB8(...) asm("func_00163AB8");
extern "C" int X_func_0017F5E8(...) asm("func_0017F5E8");
extern "C" int X_func_00180B30(...) asm("func_00180B30");
extern "C" int X_func_0018330C(...) asm("func_0018330C");
extern "C" int X_func_0018BB8C(...) asm("func_0018BB8C");
extern "C" int X_func_0018C130(...) asm("func_0018C130");
extern "C" int X_func_0018C190(...) asm("func_0018C190");
extern "C" int X_func_001BE084(...) asm("func_001BE084");
extern "C" int X_func_001BE0C0(...) asm("func_001BE0C0");
extern "C" int X_func_001C02F8(...) asm("func_001C02F8");
extern "C" int X_func_001C0D70(...) asm("func_001C0D70");
extern "C" int X_func_001C2848(...) asm("func_001C2848");
extern "C" int X_func_001C4FA4(...) asm("func_001C4FA4");
extern "C" int X_func_001C96C8(...) asm("func_001C96C8");
extern "C" int X_func_001CB8E4(...) asm("func_001CB8E4");
extern "C" int X_func_001CBEDC(...) asm("func_001CBEDC");
extern "C" int X_func_001CED18(...) asm("func_001CED18");
extern "C" int X_func_001D10D0(...) asm("func_001D10D0");
extern "C" int X_func_001D1410(...) asm("func_001D1410");
extern "C" int X_func_001D2B8C(...) asm("func_001D2B8C");
extern "C" int X_func_001DA228(...) asm("func_001DA228");
extern "C" int X_func_001DA740(...) asm("func_001DA740");
extern "C" int X_func_001DCD38(...) asm("func_001DCD38");
extern "C" int X_func_001E7724(...) asm("func_001E7724");
extern "C" int X_func_001E7D7C(...) asm("func_001E7D7C");
extern "C" int X_func_00243788(...) asm("func_00243788");
extern "C" int X_func_002437F8(...) asm("func_002437F8");
extern "C" int X_func_00243938(...) asm("func_00243938");
extern "C" int X_func_00243CD8(...) asm("func_00243CD8");
extern "C" int X_func_00247EB8(...) asm("func_00247EB8");
extern "C" int X_func_00247F00(...) asm("func_00247F00");
extern "C" int X_func_00247F10(...) asm("func_00247F10");
extern "C" int X_setPlayer__9MagSystemii(...) asm("setPlayer__9MagSystemii");
extern int D_002B8A10;
extern int D_002B8BF0;
extern int D_002B8F50;
extern int D_006E9840;
extern int D_007A3D80;
extern int D_007B2140;
extern int D_007B2580;
// Translated mechanically from m2c drafts: only what matches byte for byte.

static inline void *gamSub22220() {
    void *p = (void *)&D_007812C0;
    return (char *)p + 0x22220;
}

extern "C" int func_001BE414(int);

class FileReader {
public:
    int unk0;
    int unk4;
    ~FileReader();
};

extern "C" void func_001C0D44(int arg0)
{
    X_func_001C4FA4();
    X_func_001C0D70(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C0D70);

extern "C" void func_001C1378(GamMan *arg0)
{
    struct { char pad0[16]; } stack;
    int temp_a0;
    int temp_v0;

    temp_v0 = (int)arg0->m_pc;
    if (temp_v0 != 0) {
        X_func_001DA228(temp_v0, 0x1C, (int)&stack);
        X_func_001DA740((int)arg0->m_pc, 0x1B, (int)&stack);
    }
    temp_a0 = (int)arg0->m_dog;
    if (temp_a0 != 0) {
        X_func_001DA228(temp_a0, 0x1C, (int)&stack);
        X_func_001DA740((int)arg0->m_dog, 0x1B, (int)&stack);
    }
    X_func_001D84B0((int)arg0);
    arg0->m_unk21FF0 = 0;
    arg0->m_unk22004 = 0;
    arg0->m_unk22008 = 0;
    (*(int *)&arg0->m_vcount) = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C143C);

// NON_MATCHING: 37/41 differ (size 0xA4, game 0xA8), 9 edits
#ifdef NON_MATCHING
extern "C" void func_001C19C4(GamMan *arg0, int *arg1)
{
    register int *var_a2 PS2_REG("$6");
    register int *temp_t0 PS2_REG("$8");
    register int temp_a3 PS2_REG("$7");
    register int var_a5 PS2_REG("$9");
    register int var_v1 PS2_REG("$3");

    var_a2 = arg1 + 8;
    temp_t0 = var_a2;
    temp_a3 = *var_a2;
    arg0->m_unk22200 = temp_t0;
    var_a2 = arg1 + 9;
    *temp_t0 = 0;
    var_a5 = 0;
    while (*var_a2 != 0) {
        *var_a2 -= temp_a3;
        var_a2++;
        var_a5++;
    }
    if ((int)var_a2 & 0xF) {
        var_a2 = (int *)((int)var_a2 / 0x10 * 0x10 + 0x10);
    }
    temp_a3 = (int)var_a2;
    var_a2 = temp_t0;
    if (var_a5 > 0) {
        var_v1 = var_a5;
        do {
            var_v1--;
            *var_a2 = temp_a3 + *var_a2 + 0x10;
            var_a2++;
        } while (var_v1 != 0);
    }
    M2C_FIELD(arg0, int **, 0x22204) = (int *)temp_a3;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C19C4);
#endif

extern "C" int func_001C1A6C(GamMan *self, int theIdx)
{
    int *p = self->m_unk22200;

    return p[theIdx];
}

extern "C" void func_001C1A88(void) {
}

extern "C" void func_001C1A90(int arg0, int arg1)
{
    struct { char pad0[96]; } stack;
    Xiiii_memset(arg1, 0, 0x100000);
    X_sceGsSetDefLoadImage((int)&stack, 0, 8, 0, 0, -4, 0x200, 0xE4);
    X_FlushCache(0);
    X_sceGsExecLoadImage((int)&stack, arg1);
    X_sceGsSyncPath(0, 0);
    X_sceGsSetDefLoadImage((int)&stack, 0, 8, 0, 0, 0xDC, 0x200, 0xE4);
    X_FlushCache(0);
    X_sceGsExecLoadImage((int)&stack, arg1);
    X_sceGsSyncPath(0, 0);
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3C8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3E8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB3F0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C1B48);

extern "C" void func_001C1F84(int unused, Header1F84 *dst_header, const Header1F84 *src_header, int count)
{
    *dst_header = *src_header;
    DstEntry1F84 *dst = (DstEntry1F84 *)(dst_header + 1);
    const Entry1F84 *src = (const Entry1F84 *)(src_header + 1);
    if (count > 0) {
        do {
            dst->entry = *src;
            dst++;
            src++;
        } while (--count != 0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB418);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB438);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C204C);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB540);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB558);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB560);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB578);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB580);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB598);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB5F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB600);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB618);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB620);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB638);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB640);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB658);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB660);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB678);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB680);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB698);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6D8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6E0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB6F8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB700);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB718);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB720);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB738);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C2848);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C2F50);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C387C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C3A48);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C3D38);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C4168);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C43F0);

extern "C" void func_001C4610(GamMan *arg0)
{
    GamList<ObjStat *>::iterator it;
    GamList<ObjStat *>::iterator last;
    GamList<ObjStat *> *list = arg0->getAVFchrListPtr();

    it = list->begin();
    last = list->end();

    while (it != last) {
        ObjStat *actor = *it;
        char *p = (char *)&D_006E9840;
        int off = 0x12540;
        int no = actor->getChrID();
        func_001331F4(p + off, no, 1, 0, 0, 0, 0.016666694f);
        ++it;
    }
}

extern "C" void func_001C46C8(GamMan *arg0)
{
    int temp_v0;

    temp_v0 = arg0->m_unk21FE0;
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, float *, 0x1E8) = 9.999999583953922e-08f;
    }
}

extern "C" void func_001C46F4(void) {
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB898);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8A0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8A8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8B0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8B8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB8C0);

extern "C" void func_001C46FC(GamMan *arg0)
{
    if (func_0017EA44(&D_00298EE0, arg0->m_unk21F7C) != 0) {
        func_00279C98(&D_006E9640, "%s #f060 \n", func_001DB8E8((char *)arg0->m_mapObj, 2, -1));
        GamMsgRect param;
        param.m_x = 0x30;
        param.m_y = 0xE0;
        param.m_w = 0xFFFF;
        param.m_h = 0x100;
        param.m_unk10 = 0x20;
        param.m_unk14 = 0;
        param.m_unk18 = 0;
        X_func_001CF7D0((char *)arg0, &param);
        X_func_001CF854((char *)arg0, &D_006E9640, 0, 0xB4);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C47C4);

extern "C" void func_001C4F30(void) {
}

extern "C" void func_001C4F38(GamMan *arg0, int arg1)
{
    X_func_00118ED8__9MagSystemiii((int)&D_006E9840, arg0->m_pcChrNo, arg1, 1);
}

extern "C" void func_001C4F70(GamMan *arg0, int arg1)
{
    X_func_00118F30__9MagSystemii((int)&D_006E9840, arg0->m_pcChrNo, arg1);
}

extern "C" void func_001C4FA4()
{
    X_func_001CED18();
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C4FC0);

extern "C" void func_001C5094(int arg0, int arg1, int arg2, int arg3)
{
    unsigned int off = 0x42BB0;

    if (arg2 != 0) {
        char *p = D_006FBD80 + off;
        X_func_00191F98(p);
        X_func_00191ED0(p, arg1);
        X_func_00191D20(p, arg1, 1);
        X_func_00191D74(p, arg1, 1);
        X_func_00191DC8(p, arg1, (arg3 <= 0) ? 0 : (arg3 - 1));
        return;
    }

    char *p = D_006FBD80 + off;
    X_func_00191D20(p);
    X_func_00191D74(p, arg1, 0);
}

extern "C" void func_001C5168(int unused, int arg1, int arg2, int arg3)
{
    unsigned int off = 0x42BB0;
    char *p = D_006FBD80 + off;
    func_00191BA8(p, arg1, 0, 0);
    func_00191C64(p, arg1, arg2 << 4, arg3 << 4);
}

extern "C" void func_001C51E0(int arg0, int arg1, int arg2)
{
    unsigned int off = 0x42BB0;
    char *p = D_006FBD80 + off;

    X_func_00191F98((int)p, arg1);
    X_func_00191E04((int)p, arg1, arg2);
}

extern "C" void func_001C5240()
{
    char *p = D_006FBD80;

    X_func_00191E58((int)(p + 0x42BB0));
}

extern "C" void func_001C526C(GamMan *arg0)
{
    func_001F688C();
    arg0->m_vcount++;
    arg0->m_sysFlg &= ~0x40001;
    if ((arg0->m_vcount % 25) == 0) {
        arg0->m_sysFlg |= 1;
    }
    if (!arg0->chkSysFlg2(0x8000000)) {
        if (arg0->m_pc != 0) {
            func_001D8F04(arg0->m_pc, arg0->m_pcPos);
            func_001D8964(arg0->m_pc, arg0->m_pcRot);
        }
        if (arg0->m_dog != 0) {
            func_001D8F04(arg0->m_dog, arg0->m_dogPos);
        }
    }
    func_001E100C(arg0->m_snd, arg0->m_pcPos);
    if (arg0->chkSysFlg(2)) {
        func_001DEE78(arg0->m_trg, arg0->m_pcPos, arg0->m_pcRot);
    }
}

extern "C" void func_001C53D8(void) {
}

extern "C" void func_001C53E0(GamMan *arg0, int arg1)
{
    arg0->m_unk21FF0 = arg1;
    X_setPlayer__9MagSystemii((int)&D_006E9840, arg0->m_pcChrNo, arg1);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C541C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C574C);

extern "C" void func_001C57A0(GamMan *arg0)
{
    if (arg0->chkSysFlg2(0xC)) {
        if (arg0->chkSysFlg2(4)) {
            func_001E7544(&D_007A3D80, 1);
            X_func_001C58B8(arg0, 1);
            func_001C58C0(arg0, 1);
            Xii_func_00144334(0);
            arg0->m_sysFlg2 &= ~4;
        } else {
            if (func_001C574C() == 0 || arg0->chkSysFlg2(0x10)) {
                arg0->m_sysFlg2 &= ~0x10;
                func_001E7544(&D_007A3D80, 0);
                func_001C58C0(arg0, 0);
                X_func_001C58B8(arg0, 0);
                func_001D3B44(arg0);
                arg0->m_sysFlg2 &= ~8;
            }
        }
    }
}

extern "C" int func_001C58B8()
{
    return 0;
}

extern "C" int X_func_001C58C0(GamMan *self, int arg1) asm("func_001C58C0");
extern "C" int X_func_001C58C0(GamMan *self, int arg1)
{
    GamList<ACHRstat *>::iterator it;
    GamList<ACHRstat *>::iterator last;

    if (self->chkSysFlg2(0x10000) ? (arg1 == 1) : (arg1 == 0)) {
        return 0;
    }

    it = self->m_achrList.begin();
    last = self->m_achrList.end();
    while (it != last) {
        if ((((unsigned int)(*it)->getOID() >> 23) & 0x1F) == 2) {
            X_func_001CBDB8_C58C0(self, (*it)->getOID());
            X_func_001DA130_C58C0(*it, arg1, 1);
        }
        ++it;
    }

    Tbl4_C58C0 tbl = D_002FB920;
    X_func_001E747C_C58C0(&D_007A3D80, &tbl, arg1);
    X_func_001E7414_C58C0(&D_007A3D80, D_007B45C0, arg1);
    if (arg1 == 1) {
        self->setSysFlg2(0x10000);
    } else {
        self->unsetSysFlg2(0x30000);
    }
    return 1;
}

extern "C" void func_001C5A5C(GamMan *self, int arg1)
{
    GamList<ACHRstat *>::iterator it;
    GamList<ACHRstat *>::iterator last;
    unsigned int sp20;

    it = self->m_achrList.begin();
    last = self->m_achrList.end();
    while (it != last) {
        if ((((unsigned int)(*it)->getOID() >> 23) & 0x1F) == 2) {
            int chrID = (*it)->getChrID();
            if (arg1 == 0) {
                if (chk3F4_C5A5C(*it, 1)) {
                    X_func_001DA228_C5A5C(*it, 0x67, &sp20);
                    if (sp20 != 0) {
                        X_func_001D1410_C5A5C(self, sp20, 1);
                    }
                    gScene_C5A5C.setActorHide(chrID, false);
                    flg3F4_C5A5C(*it) &= ~1;
                }
            } else {
                gScene_C5A5C.setActorHide(chrID, true);
                flg3F4_C5A5C(*it) |= 1;
            }
        }
        ++it;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C5BF4);

extern "C" void func_001C5D08(GamMan *arg0, int arg1)
{
    if (arg1 != 0) {
        *(int *)(D_007B205C + 0x54) = 0;
    }
    *(int *)(D_007B205C + 0xA0) = -1;
    X_func_001C6A40(&D_007812C0, 0x2000);
    D_007812C0.unsetSysFlg2(0x80);
    if ((arg0->chkSysFlg2(0x80000)) && (Xiii_func_001E7D7C((int)&D_007A3D80, arg0->m_itemUseTaskID) == 0)) {
        int temp_v0 = Xii___builtin_new(0x80);
        X_func_001F184C(temp_v0, 0x15, 0, 0);
        X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0, 0, (int)&arg0->m_itemUseTaskID, 0x11);
    }
}

extern "C" void func_001C5E1C(GamMan *arg0, int arg1)
{
    arg0->setSysFlg2(4);
    X_func_001C6A40(arg0, 2);
    do {
        switch (arg1) {
        case -2:
        case -1:
        case 0:
        case 0x10005:
        case 0x10006:
        case 0x10007:
            break;
        case 0x10000:
        case 0x10002:
        case 0x10003:
        case 0x10004:
            func_001C5BF4(arg0, 1);
            break;
        case 0x10001:
            func_001C5BF4(arg0, 2);
            break;
        case 0x1000A:
            arg0->setSysFlg2(0x20);
            func_001C5BF4(arg0, 1);
            break;
        case 0x10008:
        case 0x10009:
        default:
            if (arg1 < 0x20000 || arg1 >= 0x400000) {
                func_001C5BF4(arg0, 1);
            }
            break;
        }
    } while (0);
}

extern "C" void func_001C5F70(GamMan *arg0)
{
    if ((int)arg0->m_sysFlg2 & 0x20) {
        unsigned int off = 0x42BB0;
        char *p = D_006FBD80 + off;
        func_00191D20(p, 2, 0);
        func_00191D74(p, 2, 0);
    }
    (*(int *)&arg0->m_sysFlg2) |= 8;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C5FFC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C621C);

extern "C" void func_001C6470(GamMan *arg0)
{
    register int i PS2_REG("$5") = 0;

    if (arg0->m_unk22540[0].m_val != -1.0f) {
        do {
            i++;
            if (i >= 3) {
                return;
            }
            register int v0 PS2_REG("$2") = i << 5;
            v0 += (int)arg0;
            if (*(float *)((char *)v0 + 0x22540) == -1.0f) {
                break;
            }
        } while (1);
    }

    if (i < 3) {
        register char *dest PS2_REG("$3") = (char *)((i << 5) + (int)arg0);     // &arg0->m_unk22540[i]
        char *v0 = (char *)&D_006FBD80;
        unsigned int off = 0x2AAE0;
        v0 += off;
        unsigned int dest_off = 0x22540;
        dest += dest_off;
        *(GamElem22540 *)dest = *(GamElem22540 *)v0;
    }
}

extern "C" void func_001C651C(GamMan *arg0)
{
    register char *arg0_reg PS2_REG("$18") = (char *)arg0;
    register int i PS2_REG("$17") = 2;

    if (*(float *)(arg0_reg + 0x22580) == -1.0f) {
        do {
            i--;
            if (i < 0) {
                return;
            }
            register int v0 PS2_REG("$2") = i << 5;
            v0 += (int)arg0_reg;
            if (*(float *)(v0 + 0x22540) != -1.0f) {
                break;
            }
        } while (1);
    }

    if (i >= 0) {
        register unsigned int off PS2_REG("$16") = 0x22540;
        char *p = (char *)&D_006E9840;
        char *target = arg0_reg + (i << 5);
        i = (i << 5) + off;
        target += off;
        func_00143D7C(p + 0x12540, target, 0);
        *(float *)(arg0_reg + i) = -1.0f;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C65E8);

extern "C" void func_001C687C(GamMan *self, unsigned int theOID)
{
    if (Xiiu_func_001D046C((int)self, theOID) != 0 && ((theOID >> 28) & 3) == 1) {
        int attach = ((ObjStat *)Xiiu_func_001D2B8C((int)self, theOID))->get_attach_id();
        if (attach != -1) {
            gScene_687C.setActorHide(Xiiu_func_001CBE38((int)self, attach), 0);
        }
        if (((theOID >> 23) & 0x1F) == 0) {
            if (self->m_unk22004 != 0 && Xiiu_func_001D046C((int)self, self->m_unk22004) != 0) {
                gScene_687C.setActorHide(Xiiu_func_001CBE38((int)self, self->m_unk22004), 0);
            }
            if (self->m_unk22008 != 0 && Xiiu_func_001D046C((int)self, self->m_unk22008) != 0) {
                gScene_687C.setActorHide(Xiiu_func_001CBE38((int)self, self->m_unk22008), 0);
            }
        }
    }
}

extern "C" void func_001C6A04(int arg0)
{
    X_func_00163AB8((int)&D_007B2140, arg0 + 0x22004, arg0 + 0x22008);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6A40);

extern "C" int func_001C6C28(GamMan *arg0)
{
    return arg0->m_unk21F7C;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6C38);

extern "C" int func_001C6C98(GamMan *arg0)
{
    return arg0->m_playTime + ((unsigned int) (int)arg0->m_vcount / 1800U);
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB920);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FB930);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6CCC);

extern "C" void func_001C6F08(char *arg0, int arg1, void *arg2)
{
    switch (arg1) {
    case 17:
        *(int *)(arg0 + 0x21F8C) = *(int *)arg2;
        break;
    case 18:
        *(int *)(arg0 + 0x21F90) = *(int *)arg2;
        break;
    case 19:
        *(int *)(arg0 + 0x21F94) = *(int *)arg2;
        break;
    case 20:
        *(int *)(arg0 + 0x21F98) = *(int *)arg2;
        break;
    case 22:
        *(float *)(arg0 + 0x21FBC) = *(float *)arg2;
        break;
    case 23:
        *(float *)(arg0 + 0x21FC0) = *(float *)arg2;
        break;
    case 24:
        *(float *)(arg0 + 0x21FC4) = *(float *)arg2;
        break;
    case 27:
        *(int *)(arg0 + 0x21F54) = *(int *)arg2;
        break;
    case 28:
        *(int *)(arg0 + 4) = *(int *)arg2;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C6FE0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C7210);

extern "C" int func_001C7494(GamMan *arg0)
{
    unsigned int no = arg0->m_unk1D300;
    if (no >= 4) {
        ror_assert("mag/magscene.h", 0x330, "no >= 0 && no < MAX_MAP_MODEL");
    }
    return D_007257B8[no].val;
}

extern "C" void func_001C7500(GamMan *arg0, int arg1)
{
    char *snd = (char *)&D_007B2580;
    X_func_0017F5E8((int)snd, 8);
    X_func_00180B30((int)snd, 0xB);
    X_func_00180B30((int)snd, 0x20);
    X_func_00180B30((int)snd, 0x40);

    char *base = (char *)&D_007812C0;
    int off = 0x18E00;
    X_func_001E4540((int)(base + off), arg1, 0);
    X_func_001C772C((int)base, 0xA00, 1);
    (*(int *)&arg0->m_sysFlg2) |= 0x1000000;
}

extern "C" void func_001C75BC(GamMan *arg0, int arg1)
{
    char *snd = (char *)&D_007B2580;
    X_func_0017F5E8((int)snd, 8);
    X_func_00180B30((int)snd, 0x20);
    X_func_00180B30((int)snd, 0x40);

    char *base = (char *)&D_007812C0;
    int off = 0x18E00;
    X_func_001E4540((int)(base + off), arg1, 0);
    X_func_001C772C((int)base, 0xA00, 1);
    (*(int *)&arg0->m_sysFlg2) |= 0x2000000;
}

extern "C" void func_001C766C(GamMan *arg0)
{
    X_func_0017F5E8((int)&D_007B2580, 8);
    X_func_00180B30((int)&D_007B2580, 0x1F);
    X_func_001C2848((int)arg0, arg0->m_chapter, 1);
}

extern "C" void func_001C76CC(GamMan *arg0)
{
    X_func_0017F5E8((int)&D_007B2580, 8);
    X_func_00180B30((int)&D_007B2580, 0xC);
    X_func_001C2848((int)arg0, arg0->m_chapter, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C772C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C7A4C);

extern "C" void func_001C7D04(GamMan *arg0, int arg1)
{
    int found = 0;
    int i = 0;
    int *p = arg0->m_unk1F240;
    int *start = p;

    while (1) {
        int val = *p++;
        if (val != 0) {
            if (val == arg1) {
                found = 1;
            }
        }
        i++;
        if (i >= 0x169 || found != 0) {
            break;
        }
    }

    if (found == 0) {
        p = start;
        i = 0;
        if (*p != 0) {
            do {
                p++;
                i++;
                if (*p == 0) {
                    break;
                }
            } while (i < 0x169);
        }
        *p = arg1;
    }

    func_001CCC30(arg0, arg1);
}

extern "C" int func_001C7DA8(GamMan *self, int theValue)
{
    int *p = self->m_unk1F240;

    for (int i = 0; i < 0x169; i++) {
        if (*p == theValue) {
            return 1;
        }
        p++;
    }
    return 0;
}

extern "C" void func_001C7DEC(GamMan *arg0)
{
    int var_a0;
    int var_v1;

    var_v1 = (int)arg0->m_unk1F240;
    var_a0 = 0x168;
    do {
        if (((unsigned int) (*(unsigned int *)(var_v1)) >> 0x1E) != 0) {
            (*(unsigned int *)(var_v1)) = 0;
        }
        var_a0 -= 1;
        var_v1 += 4;
    } while (var_a0 >= 0);
}

extern "C" int func_001C7E28(int arg0, int arg1)
{
    return (int)&D_002B8F50 + ((arg1 & 0xFFFF) << 9);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C7E40);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C812C);

extern "C" void func_001C8214(GamMan *arg0, int arg1)
{
    // m_itemHave.m_begin[arg1], kept as a byte offset: indexing the GamItem
    // array reloads m_begin in another register order.
    char **vec = (char **)((char *)&arg0->m_itemHave.m_begin);
    int off = arg1 * 0x10;
    if (((Item1A6C0 *)(*vec + off))->unk8 == arg0->m_pcEquipItem) {
        func_001C7A4C(arg0, 0xA00);
    }
    if (((Item1A6C0 *)(*vec + off))->unk8 == arg0->m_findTargetItem) {
        func_001C9784(arg0, 0xA00);
    }
    Item1A6C0 tmp(gamSub22220(), 0xA00);
    *(Item1A6C0 *)(*vec + off) = tmp;
}

extern "C" void func_001C82F8(GamMan *self, unsigned short theUID, int theOne)
{
    if (theUID == self->getPcEquipItem()) {
        func_001C7A4C(self, 0xA00);
    }
    if (theUID == self->getFindTargetItem()) {
        func_001C9784(self, 0xA00);
    }
    for (int i = 0; i < 12; i++) {
        int off = i * 0x10;
        if (((GamItem *)((char *)self->getItemHavePtr()->m_begin + off))->m_uid == theUID) {
            if (func_001DD00C(self->m_unq, theUID, 0x20000) != 0) {
                if (((GamItem *)((char *)self->getItemHavePtr()->m_begin + off))->m_num >= 2) {
                    ((GamItem *)((char *)self->getItemHavePtr()->m_begin + off))->m_num--;
                    return;
                }
            }
            ((GamItem *)((char *)self->m_itemHave.m_begin + off))->m_uid = 0xA00;
            if (theOne != 0) {
                return;
            }
        }
    }
}

extern "C" void func_001C8414(int arg0, int arg1)
{
    int temp_s1;

    temp_s1 = arg1 & 0xFFFF;
    Xiiii_func_001C82F8((int) arg0, temp_s1, 0);
    Xiiii_func_001C94D8(arg0, temp_s1, 0);
}

// NON_MATCHING: 17/43 differ (size 0xAC, game 0xAC), 17 edits
#ifdef NON_MATCHING
extern "C" void func_001C845C(GamMan *arg0)
{
    GamItemHave *have = &arg0->m_itemHave;
    GamItem *end = have->m_end;
    GamItem *buf = have->m_buf;
    GamItem *p = have->m_begin;
    GamItem item;
    GamItem **out;
    int i;

    if (p != end) {
        p++;
        do {
            asm volatile("" ::: "memory");
        } while (++p != end);
    }
    have->m_max = 0xC;
    i = 0xB;
    have->m_end = buf;
    item.m_uid = 0xA00;
    have->m_begin = buf;
    out = &arg0->m_itemHave.m_end;
    do {
        GamItem *dst;
        i--;
        dst = *out;
        *dst = item;
        *out = dst + 1;
    } while (i >= 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C845C);
#endif

extern "C" int func_001C8508(int arg0, unsigned short arg1)
{
    int temp_v0;
    int var_a2;
    int temp_v1;

    var_a2 = 0;
loop_1:
    temp_v0 = var_a2 * 0x10;
    var_a2 += 1;
    temp_v1 = M2C_FIELD(arg0, int *, 0x1A6C0) + temp_v0;
    if (M2C_FIELD(temp_v1, unsigned short *, 8) == (arg1 & 0xFFFF)) {
        return (int) M2C_FIELD(temp_v1, unsigned short *, 0xA);
    }
    if (var_a2 >= 0xC) {
        return 0;
    }
    goto loop_1;
}

extern "C" int func_001C854C(int self)
{
    for (int i = 0; i < 0xC; i++) {
        int base = *(int *)(self + 0x1A6C0);
        if (*(unsigned short *)(base + (i << 4) + 8) == *(unsigned short *)(self + 0x2220C)) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8598);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8604);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C870C);

extern "C" int func_001C898C(GamMan *arg0)
{
    return arg0->m_unk1D200;
}

extern "C" void func_001C899C(GamMan *arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = arg0->m_unk1D200;
    if (temp_v0 > 0) {
        temp_v1 = (int)arg0->m_unk1D204;
        arg0->m_unk1D200 = (int) (temp_v0 - 1);
        if (temp_v1 != 0) {
            M2C_FIELD(temp_v1, unsigned short *, 0xA) = (unsigned short) (M2C_FIELD(temp_v1, unsigned short *, 0xA) + 0xFFFF);
        }
    }
}

extern "C" int func_001C89E4(int arg0)
{
    int var_a2 = 0;
    int var_a1 = 0;

loop_1:
    int temp_v0 = M2C_FIELD(arg0, int *, 0x1A6C0);
    int temp_v1 = var_a1 * 0x10;
    var_a1 += 1;
    int temp_v2 = temp_v0 + temp_v1;
    unsigned short val = M2C_FIELD(temp_v2, unsigned short *, 8);
    int diff = val ^ 0xA00;
    if (diff != 0) {
        var_a2++;
    }
    if (var_a1 < 0xC) {
        goto loop_1;
    }
    return var_a2;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8A28);

extern "C" int func_001C8AE8(GamMan *self, unsigned short theUID, int theStock)
{
    int count = 0;

    for (int i = 0; i < 12; i++) {
        if (itemAt_8AE8(self->getItemHavePtr()->m_begin, i * 0x10)->m_uid == theUID) {
            if (func_001DD00C(self->m_unq, itemAt_8AE8(self->getItemHavePtr()->m_begin, i * 0x10)->m_uid, 0x20000) != 0) {
                count += itemAt_8AE8(self->getItemHavePtr()->m_begin, i * 0x10)->m_num;
            } else {
                count++;
            }
        }
    }

    if (theStock != 0) {
        GamList<GamItemStock>::iterator it;
        GamList<GamItemStock>::iterator last;
        GamPool<GamItemStock, 0x14E> *list = self->getItemStockPtr();
        it = list->begin();
        last = list->end();
        while (it != last) {
            if ((*it).m_item.m_uid == theUID) {
                if (func_001DD00C(self->m_unq, (*it).m_item.m_uid, 0x20000) != 0) {
                    count += (*it).m_item.m_num;
                } else {
                    count++;
                }
            }
            ++it;
        }
    }

    return count;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8C50);

static inline GamItem *itemAt(GamItem *base, int off)
{
    return (GamItem *)((char *)base + off);
}

extern "C" int func_001C8CA4(GamMan *self, unsigned int theOID, unsigned short theUID)
{
    unsigned short sp0 = 0;

    if (theUID != 0) {
        sp0 = theUID;
    } else if (Xiiu_func_001D046C((int)self, theOID) != 0) {
        func_001D1C80(self, theOID, 2, &sp0);
    }

    int i;
    for (i = 0; i < 12; i++) {
        if (itemAt(self->m_itemHave.m_begin, i * 0x10)->m_uid == 0xA00) {
            break;
        }
        if (itemAt(self->getItemHavePtr()->m_begin, i * 0x10)->m_uid == sp0 && itemAt(self->getItemHavePtr()->m_begin, i * 0x10)->m_uid != 0) {
            if (func_001DD00C(self->m_unq, sp0, 0x20000) != 0) {
                if (itemAt(self->getItemHavePtr()->m_begin, i * 0x10)->m_num < 99) {
                    return 1;
                }
            }
        }
    }
    return i < 12;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C8DC8);

extern "C" int func_001C8E14()
{
    return 0;
}

extern "C" void func_001C8E1C(int arg0, int arg1)
{
    X_func_001DCD38(arg0 + 0x22220, X_func_001CBEDC(), 4);
    X_func_001D10D0(arg0, arg1, 2);
    X_func_001D1410(arg0, arg1, 1);
    if (X_func_001C96C8(arg0, arg1) != 0) {
        X_func_001CB8E4(arg0, arg1, 0x32, 0);
    }
}

extern "C" void func_001C8EAC(void) {
}

extern "C" void func_001C8EB4(char *arg0, int arg1, int arg2)
{
    int sp0;
    unsigned short temp_s3 = arg1 & 0xFFFF;
    func_001DC48C(arg0 + 0x22220, temp_s3, 0xF, &sp0);
    int temp_s2 = X_loadModel__9MagSystemii(&D_006E9840, (unsigned short)sp0, -1);
    int temp_v0 = func_001C6FE0((GamMan *)(arg0), 2, 5, -1);
    func_001CC250(&D_007812C0, temp_s2, temp_v0, temp_s3, 0, 0);
    func_001CFBE4((int)&D_007812C0, temp_v0, arg2);
}

// Puts theNum (or one) of an item in the stock: on its pile when its record
// allows piling, else as a new entry. 1 when the stock or the pile is full.
extern "C" int func_001C8F7C(GamMan *self, unsigned short theUID, int theNum)
{
    GamList<GamItemStock>::iterator it;
    GamList<GamItemStock>::iterator last;
    GamItemStock item;
    GamPool<GamItemStock, 0x14E> *list = self->getItemStockPtr();

    if ((unsigned int)list->size() < 0x14E) {
        if (func_001DD00C(self->m_unq, theUID, 0x20000) != 0) {
            it = list->begin();
            last = list->end();
            while (it != last) {
                if ((*it).m_item.m_uid == theUID) {
                    if (theNum != 0) {
                        (*it).m_item.m_num += theNum;
                    } else {
                        (*it).m_item.m_num++;
                    }
                    if ((*it).m_item.m_num >= 100) {
                        (*it).m_item.m_num = 99;
                        return 1;
                    }
                    return 0;
                }
                ++it;
            }
        }
        if (theNum != 0) {
            item.m_item.m_num = theNum;
        } else {
            item.m_item.m_num = 1;
        }
        if (item.m_item.m_num >= 100) {
            item.m_item.m_num = 99;
        }
        item.m_item.m_uid = theUID;
        item.m_item.m_unq = func_001DBFA0(self->m_unq, theUID);
        item.m_item.m_oid = func_001C6FE0(self, 2, 5, -1);
        self->m_itemStock.push_back(item);
    } else {
        return 1;
    }
    return 0;
}

// Adds an item to the stock: on top of one with the same uid when the item's
// record allows piling (at most 99), else as a new entry. 1 when it is full.
extern "C" int func_001C9198(GamMan *self, GamItemStock theItem)
{
    GamList<GamItemStock>::iterator it;
    GamList<GamItemStock>::iterator last;
    GamPool<GamItemStock, 0x14E> *list = self->getItemStockPtr();

    if ((unsigned int)list->size() < 0x14E) {
        if (*(int *)(theItem.m_item.m_unq + 0xB0) & 0x20000) {
            it = list->begin();
            last = list->end();
            while (it != last) {
                if ((*it).m_item.m_uid == theItem.m_item.m_uid) {
                    (*it).m_item.m_num += theItem.m_item.m_num;
                    if ((*it).m_item.m_num >= 100) {
                        (*it).m_item.m_num = 99;
                    }
                    return 0;
                }
                ++it;
            }
        }
        if ((unsigned int)self->getItemStockPtr()->size() >= 0x14E) {
            return 0;
        }
        self->getItemStockPtr()->push_back(theItem);
    } else {
        return 1;
    }
    return 0;
}

// NON_MATCHING: 28/105 differ, 28 edits
#ifdef NON_MATCHING
// Removes the stock entry of an item by its object id. 1 when it was there.
extern "C" int func_001C9334(GamMan *self, int theOID)
{
    GamList<GamItemStock>::iterator it;
    GamList<GamItemStock>::iterator last;
    GamPool<GamItemStock, 0x14E> *list = self->getItemStockPtr();

    if (list->size() != 0) {
        it = list->begin();
        last = list->end();
        while (it != last) {
            if ((*it).m_item.m_oid == theOID) {
                if (self->m_itemStock.size() == 1) {
                    self->m_itemStock.clear();
                    return 1;
                }
                it = self->m_itemStock.erase(it);
                return 1;
            }
            ++it;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9334);
#endif

// Takes an item out of the stock by uid: one unit of a pile when theOne is
// set and its record allows piling, else the whole entry (every entry with
// that uid when theOne is 0). 1 when an entry was removed.
extern "C" int func_001C94D8(GamMan *self, unsigned short theUID, int theOne)
{
    GamList<GamItemStock>::iterator it;
    GamList<GamItemStock>::iterator last;
    GamPool<GamItemStock, 0x14E> *list = self->getItemStockPtr();

    if (list->size() != 0) {
        it = list->begin();
        last = list->end();
        while (it != last) {
            if ((*it).m_item.m_uid == theUID) {
                if (func_001DD00C(self->m_unq, theUID, 0x20000) != 0 && theOne != 0) {
                    if ((*it).m_item.m_num >= 2) {
                        (*it).m_item.m_num--;
                        return 0;
                    }
                }
                it = self->m_itemStock.erase(it);
                if (theOne != 0 || self->m_itemStock.size() == 0) {
                    return 1;
                }
            } else {
                ++it;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C96C8);

extern "C" void func_001C9784(GamMan *self, unsigned short theA)
{
    self->m_findTargetItem = theA;
    if (theA == 0xA00) {
        return X_func_00144500(0);
    }
    X_func_00144500(theA);
}

extern "C" int func_001C97C8(GamMan *arg0)
{
    return ((*(long *)&arg0->m_sysFlg) & (((long) 0x800 << 0x20) | 4)) == 4;
}

extern "C" int func_001C97F0(void *arg0)
{
    if ((func_001C8A28(arg0, 0xAD0, 1) && func_001C6C38((GamMan *)(arg0)) == 0) ||
        (func_001C8A28(arg0, 0xAD1, 1) && func_001C6C38((GamMan *)(arg0)) == 2) ||
        (func_001C8A28(arg0, 0xAD2, 1) && func_001C6C38((GamMan *)(arg0)) == 1)) {
        if ((*(unsigned long long*)((char*)arg0 + 0x21F48) & 0x80000000004ULL) == 4) {
            return 1;
        }
    }
    return 0;
}

extern "C" void func_001C98B8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C98C0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBB78);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBB88);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBB98);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9920);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001C9C1C);

extern "C" void func_001C9E20(GamMan *self, int theStat)
{
    GamList<GamElem1D240>::iterator it;
    GamList<GamElem1D240>::iterator last;
    GamList<GamElem1D240> *list = &self->m_unk1D240;

    it = list->begin();
    last = list->end();
    while (it != last) {
        switch (theStat) {
        case 1:
            D_00725410[(*it).m_unk04[1]].hide = 0;
            break;
        case 3:
            if (((unsigned int)(*it).m_flg >> 30) == 2) {
                D_00725410[(*it).m_unk04[1]].hide = 1;
            } else if (((unsigned int)(*it).m_flg >> 30) == 3) {
                D_00725410[(*it).m_unk04[1]].hide = 0;
                self->m_unk1D300 = (*it).m_unk04[1];
            }
            break;
        case 2:
            if (((unsigned int)(*it).m_flg >> 30) == 2) {
                D_00725410[(*it).m_unk04[1]].hide = 0;
                self->m_unk1D300 = (*it).m_unk04[1];
            } else if (((unsigned int)(*it).m_flg >> 30) == 3) {
                D_00725410[(*it).m_unk04[1]].hide = 1;
            }
            break;
        }
        ++it;
    }
}

extern "C" void func_001C9F94(GamMan *self)
{
    GamList<GamElem1D240>::iterator it;
    GamList<GamElem1D240>::iterator last;
    GamList<GamElem1D240> *list = &self->m_unk1D240;

    it = list->begin();
    last = list->end();
    while (it != last) {
        if (self->m_curStat != 2) {
            if (self->m_curStat == 3) {
                if (((unsigned int)(*it).m_flg >> 30) == 2) {
                    D_00725410[(*it).m_unk04[1]].hide = 1;
                } else if (((unsigned int)(*it).m_flg >> 30) == 3) {
                    D_00725410[(*it).m_unk04[1]].hide = 0;
                    self->m_unk1D300 = (*it).m_unk04[1];
                }
            }
        } else {
            if (((unsigned int)(*it).m_flg >> 30) == 2) {
                D_00725410[(*it).m_unk04[1]].hide = 0;
                self->m_unk1D300 = (*it).m_unk04[1];
            } else if (((unsigned int)(*it).m_flg >> 30) == 3) {
                D_00725410[(*it).m_unk04[1]].hide = 1;
            }
        }
        ++it;
    }
}

extern "C" void func_001CA0CC(void) {
}

extern "C" void func_001CA0D4(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CA0DC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CA38C);

extern "C" void func_001CA598(int unused, int arg1, unsigned int arg2)
{
    switch ((arg2 >> 23) & 0x1F) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 5:
        setActorLight__9MagSystemii(&D_006E9840, arg1, 1);
        break;
    case 4:
    case 9:
        setActorLight__9MagSystemii(&D_006E9840, arg1, 0);
        break;
    default:
        break;
    }
}

extern "C" const char *func_001CA604(int arg0, int arg1)
{
    switch (arg1) {
    case 0:
        return "data/ch/action/ACTION.RPK";
    case 1:
        return "data/ch/target/TRG.RPK";
    case 2:
        return "data/ch/fix/FIX.RPK";
    case 3:
        return "data/ch/item/ITEM.RPK";
    case 4:
        return "data/ch/inst/INST.RPK";
    case 5:
        return "data/ch/enemy/ENEMY.RPK";
    case 6:
        return "data/ch/door/DOOR.RPK";
    case 10:
        return "data/ch/01/CHAP01.RPK";
    case 11:
        return "data/ch/02/CHAP02.RPK";
    case 12:
        return "data/ch/03/CHAP03.RPK";
    case 13:
        return "data/ch/04/CHAP04.RPK";
    case 14:
        return "data/ch/05/CHAP05.RPK";
    case 15:
        return "data/ch/06/CHAP06.RPK";
    case 16:
        return "data/ch/07/CHAP07.RPK";
    case 17:
        return "data/ch/08/CHAP08.RPK";
    case 18:
        return "data/ch/09/CHAP09.RPK";
    case 19:
        return "data/ch/10/CHAP10.RPK";
    case 20:
        return "data/ch/11/CHAP11.RPK";
    case 21:
        return "data/ch/12/CHAP12.RPK";
    case 8:
        return "data/ch/pc/PC.RPK";
    case 9:
        return "data/ch/bwn/BWN.RPK";
    default:
        return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CA72C);

extern "C" int func_001CA8E8(int arg0, unsigned short arg1, unsigned int arg2, unsigned short arg3, int arg4, int arg5, int arg6)
{
    if (arg2 != 0 && Xiiu_func_001D046C(arg0, arg2) != 0) {
        return -1;
    }
    int temp_v0 = X_loadModel__9MagSystemii(&D_006E9840, arg1, -1);
    func_001CA598(arg0, temp_v0, arg2);
    if (arg6 != 0) {
        func_001CC250(&D_007812C0, temp_v0, arg2, arg3, arg4, arg5);
    }
    if (arg1 == 0x800) {
        ((SystemStub_CA8E8 *)&D_006E9840)->setScale(temp_v0, 9.999999583953922e-08f, 9.999999583953922e-08f, 9.999999583953922e-08f);
    }
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CAA14);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CABD4);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CAD88);

extern "C" int func_001CAF78(int arg0, unsigned short arg1, int arg2)
{
    int sp0 = arg1;
    int temp_s0 = Xiiu_func_001D2B8C(arg0, arg2);
    func_001D966C(temp_s0);
    int sp4 = X_loadModel__9MagSystemii(&D_006E9840, arg1, -1);
    func_001CA598(arg0, sp4, arg2);
    X_func_001DA740(temp_s0, 3, (int)&sp4);
    X_func_001DA740(temp_s0, 0x1000, (int)&sp0);
    return sp4;
}

// NON_MATCHING: 10/105 differ, 10 edits
#ifdef NON_MATCHING
extern "C" void func_001386D4(void *, int);
extern "C" void func_00218470(const char *, ...);
extern "C" void heapFree__FPv(void *);
// dropMap: frees every loaded map pack, then the buffer they were kept in.
extern "C" void func_001CB01C(GamMan *self, int unused)
{
    GamList<GamElem1D240>::iterator it;
    GamList<GamElem1D240>::iterator last;
    GamList<GamElem1D240> *list = &self->m_unk1D240;
    bool dropped = false;

    it = list->begin();
    last = list->end();
    while (it != last) {
        char *p = (char *)&D_006E9840;
        int off = 0x12540;
        func_001386D4(p + off, (*it).m_unk04[1]);
        it = self->m_unk1D240.erase(it);
        dropped = true;
    }
    if (dropped) {
        func_00218470("dropMap : m_p_keep_buf %x \n", self->m_unk225E8);
        heapFree__FPv((void *)self->m_unk225E8);
        self->m_unk225E8 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB01C);
#endif

extern "C" int func_001CB1C0(GamMan *arg0)
{
    GamList<GamElem1D240>::iterator it;
    GamList<GamElem1D240>::iterator last;
    GamList<GamElem1D240> *list = &arg0->m_unk1D240;
    it = list->begin();
    last = list->end();
    while (it != last) {
        if ((*it).m_flg & 1) {
            (*it).m_flg &= ~1;
        }
        ++it;
    }
    return 0;
}

extern "C" void func_001CB24C(int arg0, int arg1)
{
    int temp_v0_2;
    int temp_a3;
    int temp_v0;

    if (arg1 == -1) {
        return Xiiii_setPlayer__9MagSystemii((int)&D_006E9840, arg1, 0);
    }
    M2C_FIELD(arg0, int *, 0x21FCC) = arg1;
    temp_v0 = Xiiu_func_001D2B8C(arg0, (unsigned int)arg1);
    M2C_FIELD(arg0, int *, 0x22090) = temp_v0;
    if (temp_v0 != 0) {
        Xiii_func_001D9F10(temp_v0, 1);
        temp_a3 = M2C_FIELD(arg0, int *, 0x22090);
        M2C_FIELD(temp_a3, int *, 0x120) = M2C_FIELD(temp_a3, int *, 0x120) | 0x10000;
        temp_v0_2 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x22090), int *, 0x108);
        M2C_FIELD(arg0, int *, 0x21FDC) = temp_v0_2;
        M2C_FIELD(arg0, int *, 0x21FE0) = (int)&D_006FE6A0 + (temp_v0_2 * 0x4D0);
        Xiiii_setPlayer__9MagSystemii((int)&D_006E9840, -1, 0);
        M2C_FIELD(arg0, int *, 0x21F70) = M2C_FIELD(arg0, int *, 0x21FDC);
        M2C_FIELD(arg0, int *, 0x21F74) = -1;
        Xiiuhi_func_001C7210(arg0, M2C_FIELD(arg0, unsigned int *, 0x21F6C), M2C_FIELD(arg0, unsigned char *, 0x21F78), 0);
    }
}

extern "C" int func_001CB384(int arg0, int arg1)
{
    int temp_a1;
    int temp_v0;

    if (arg1 == -1) {
        return Xii_func_00144334(0);
    }
    M2C_FIELD(arg0, int *, 0x21FD0) = arg1;
    temp_v0 = Xiiu_func_001D2B8C((int) arg0, (unsigned int) arg1);
    M2C_FIELD(arg0, int *, 0x22094) = temp_v0;
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, int *, 0x120) = (int) (M2C_FIELD(temp_v0, int *, 0x120) | 0x10000);
        temp_a1 = M2C_FIELD(M2C_FIELD(arg0, int *, 0x22094), int *, 0x108);
        M2C_FIELD(arg0, int *, 0x21FE8) = temp_a1;
        Xiiii_func_0011825C__9MagSystemii((int) (int)&D_006E9840, temp_a1, 0);
    }
}

extern "C" void func_001CB424(GamMan *arg0, int arg1)
{
    arg0->m_unk21FD8 = arg1;
    (*(int *)&arg0->m_murder) = X_func_001D2B8C();
}

extern "C" void func_001CB460(GamMan *arg0)
{
    int temp_v0;

    temp_v0 = (int)arg0->m_pc;
    if (temp_v0 != 0) {
        X_func_001DA228(temp_v0);
    }
}

extern "C" void func_001CB490(GamMan *arg0)
{
    int temp_v0;

    temp_v0 = (int)arg0->m_dog;
    if (temp_v0 != 0) {
        X_func_001DA228(temp_v0);
    }
}

extern "C" void func_001CB4C0(GamMan *arg0)
{
    int temp_v0;

    temp_v0 = (int)arg0->m_murder;
    if (temp_v0 != 0) {
        X_func_001DA228(temp_v0);
    }
}

extern "C" void func_001CB4F0(GamMan *arg0)
{
    int temp_v0;

    temp_v0 = (int)arg0->m_pc;
    if (temp_v0 != 0) {
        X_func_001DA740(temp_v0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB520);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CB57C);

extern "C" void func_001CB5D8(GamMan *arg0)
{
    int temp_v0;

    temp_v0 = (int)arg0->m_dog;
    if (temp_v0 != 0) {
        X_func_001DA740(temp_v0);
    }
}

extern "C" void func_001CB608(GamMan *arg0)
{
    int temp_v0;

    temp_v0 = (int)arg0->m_murder;
    if (temp_v0 != 0) {
        X_func_001DA740(temp_v0);
    }
}

extern "C" void func_001CB638(GamMan *arg0)
{
    X_func_001C6A40(arg0, 0x100000);
    func_001CF95C(arg0);
    func_001CB01C(arg0, 2);
    func_001CDBF0(arg0);
    func_001C143C(arg0);
    func_001CF518(arg0, 1);
    X_func_001CED18(arg0);
    func_001E77B4(&D_007A3D80, 0x13);
    func_001E77B4(&D_007A3D80, 0x14);
    func_001E77B4(&D_007A3D80, 5);
    GamList16 *list = (GamList16 *)arg0->m_unk2246C;
    if (list->size() != 0) {
        list->clear();
    }
    arg0->m_unk21FF0 = 0;
    arg0->m_inuMode = 2;
}

extern "C" void func_001CB74C(GamMan *self, int theKey, int theOn)
{
    GamPair pair;
    GamList<GamPair>::iterator it;
    GamList<GamPair>::iterator last;

    it = self->m_unk20B00.begin();
    last = self->m_unk20B00.end();
    if (theOn != 0) {
        while (it != last) {
            if ((*it).m_key == theKey) {
                return;
            }
            ++it;
        }
        pair.m_key = theKey;
        pair.m_val = -1;
        self->m_unk20B00.push_back(pair);
        if (theKey == (int)0x85FFFE01) {
            char *p = (char *)&D_006E9840;
            X_func_0013166C_CB74C(p + 0x12540, 14, 0);
        }
    } else {
        while (it != last) {
            if ((*it).m_key == theKey) {
                X_func_001CBB80_CB74C(self, theKey);
                if (theKey == (int)0x85FFFE01) {
                    char *p = (char *)&D_006E9840;
                    X_func_0013166C_CB74C(p + 0x12540, 15, 0);
                }
                return;
            }
            ++it;
        }
    }
}

extern "C" void func_001CB8E4(int arg0, int arg1, int arg2)
{
    struct { char pad0[16]; } stack;
    if (Xiii_func_001CBAFC(arg0, (int) arg1) == -1) {
        Xiiui_func_001D05F4((int)&D_007812C0, (unsigned int) arg1, (int)&stack);
        if (arg2 == 0x32) {
            Xiiiii_func_001CB970(arg0, arg1, 0x32, (int)&stack);
            return;
        }
        Xiiiii_func_001CB970(arg0, arg1, arg2, (int)&stack);
    }
}

extern "C" void func_001CB970(void *arg0, void *arg1, int arg2, float *arg3)
{
    if (arg2 == 0x32) {
        DogVector pos(arg3[0], arg3[1], arg3[2], 50.0f);
        PcEffParam param;
        param.m_kind = arg2;
        param.m_pos = pos;
        param.m_unk08 = 0;
        unsigned int off = 0x837E0;
        char *p = D_006FBD80 + off;
        func_001CBA0C((GamMan *)(arg0), arg1, func_00176CC8(p, &param));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CBA0C);

extern "C" int func_001CBAFC(GamMan *arg0, int arg1)
{
    GamList<GamPair>::iterator it;
    GamList<GamPair>::iterator last;
    GamList<GamPair> *list = &arg0->m_unk20B00;
    it = list->begin();
    last = list->end();
    while (it != last) {
        if ((*it).m_key == arg1) {
            return (*it).m_val;
        }
        ++it;
    }
    return -1;
}

extern "C" void func_001CBB80(GamMan *self, int theKey)
{
    GamList<GamPair>::iterator it;
    GamList<GamPair>::iterator last;
    GamList<GamPair> *list = &self->m_unk20B00;

    it = list->begin();
    last = list->end();
    while (it != last) {
        if ((*it).m_key == theKey) {
            if ((*it).m_val != -1) {
                char *v0 = (char *)&D_006FBD80;
                unsigned int off = 0x837E0;
                v0 += off;
                func_0017756C(v0, (*it).m_val);
            }
            it = self->m_unk20B00.erase(it);
        } else {
            ++it;
        }
    }
}

extern "C" void func_001CBD0C(GamMan *arg0)
{
    char *v0 = (char *)&D_006FBD80;
    unsigned int off = 0x837E0;
    v0 += off;
    func_0017762C(v0);

    // m_unk20B00.clear(): every node in use goes back to the free chain.
    // Kept on ListNode: written with GamList<GamPair>::Chain the stores come
    // out in another order (8 bytes longer).
    ListNode *head1 = (ListNode *)((char *)&arg0->m_unk20B00.m_used.m_head.m_prev);
    ListNode *head2 = (ListNode *)((char *)&arg0->m_unk20B00.m_free.m_head.m_prev);

    if (*(int *)((char *)head2 + 0x24) != 0 && head1->count != 0) {
        head2->prev->next = head1->next;
        head2->prev->next->prev = head2->prev;
        head2->prev = head1->prev;
        head2->prev->next = head2;
        head2->count += head1->count;
        head1->next = head1;
        head1->count = 0;
        asm("":::"memory");
        head1->prev = head1;
    }
}

extern "C" int func_001CBDB8(int theA, int theB)
{
    int r = X_func_001CBE38((int)&D_007812C0, theB);

    if (r == -1) {
        return 0;
    }
    return (int)&D_006FE6A0 + r * 0x4D0;
}

extern "C" void func_001CBDFC(int arg0, int arg1, int arg2)
{
    int var_v1;

    var_v1 = M2C_FIELD(arg2, unsigned char *, 0) * M2C_FIELD(arg2, unsigned char *, 1);
    if (var_v1 & 0xF) {
        var_v1 = (var_v1 & 0xFFF0) + 0x10;
    }
    M2C_FIELD(arg2, int *, 0xC) = (int) (arg2 - var_v1);
    M2C_FIELD(((arg1 * 4) + arg0), int *, 0x222E4) = arg2;
}

extern "C" int func_001CBE38(int arg0, unsigned int arg1)
{
    void *var_v0;

    if (Xiiu_func_001D046C(arg0, arg1) != 0) {
        switch ((arg1 >> 28) & 3) {
        case 1:
            var_v0 = (void *)Xiiu_func_001D2B8C(arg0, arg1);
            break;
        case 2:
            var_v0 = (void *)Xiiu_func_001D2BA8(arg0, arg1);
            break;
        case 0:
            var_v0 = (void *)Xiiu_func_001D2D00(arg0, arg1);
            break;
        default:
            return -1;
        }
        if (var_v0 != 0) {
            return *(int *)((char *)var_v0 + 0x108);
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CBEDC);

extern "C" int func_001CBF4C(int arg0, unsigned int arg1)
{
    int temp_v0;
    int temp_a2;
    int var_v1;
    int var_v0;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {
    case 1:
        var_v0 = X_func_001D2B8C(arg0, arg1);
        var_v1 = -1;
        break;
    case 2:
        var_v0 = X_func_001D2BA8(arg0, arg1);
        var_v1 = -1;
        break;
    default:
        return -1;
    }
    temp_v0 = M2C_FIELD(var_v0, int *, 0x114);
    if (temp_v0 != 0) {
        var_v1 = (*(int *)(temp_v0));
    }
    return var_v1;
}

extern "C" void *func_001CBFB0(int arg0, unsigned int arg1)
{
    int var_a2 = 0;
    int var_a4 = 0;
    unsigned int off = 0x1F24CU;

loop_1:
    int temp_v0 = var_a2 * 4;
    var_a2 += 1;
    int temp_v1 = temp_v0 + arg0;
    int *p = (int *)(temp_v1 + off);
    if (*p == 0) {
        *p = arg1;
        return *(char **)(arg0 + 0x1F248) + var_a4;
    }
    var_a4 += 0x2C0;
    if (var_a2 < 0x180) {
        goto loop_1;
    }
    return 0;
}

extern "C" void func_001CC004(GamMan *self, int arg1)
{
    for (int i = 0; i < 0x180; i++) {
        if (self->m_unk1F24C[i] == arg1) {
            self->m_unk1F24C[i] = 0;
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CC044);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CC250);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CC560);

// Deletes the FCHRstat with this object id, if there is one.
extern "C" void func_001CC7C8(GamMan *self, int theOID)
{
    GamList<FCHRstat *>::iterator it;
    GamList<FCHRstat *>::iterator last;
    GamList<FCHRstat *> *list = self->getFchrListPtr();

    it = list->begin();
    last = list->end();
    while (it != last) {
        FCHRstat *stat = *it;
        if (stat->getOID() == theOID) {
            self->delete_fchr_core(stat);
            delete *it;
            self->m_fchrList.erase(it);
            return;
        }
        ++it;
    }
}

// Removes the object with this id from the AVFchr and VFchr lists, freeing
// its model.
extern "C" void func_001CC970(GamMan *self, int theOID)
{
    if (self->m_vfchrList.size() != 0) {
        func_001D5DA0(self, theOID);

        GamList<ObjStat *>::iterator it;
        GamList<ObjStat *>::iterator last;
        GamList<ObjStat *> *list = self->getAVFchrListPtr();
        it = list->begin();
        last = list->end();
        while (it != last) {
            if ((*it)->getOID() == theOID) {
                it = self->m_avfchrList.erase(it);
            } else {
                ++it;
            }
        }

        list = self->getVFchrListPtr();
        it = list->begin();
        last = list->end();
        while (it != last) {
            ObjStat *obj = *it;
            if (obj->getOID() == theOID) {
                if (obj->getChrID() != -1) {
                    func_001D3588(self);
                    func_001D966C((int)*it);
                }
                func_001CC004(self, theOID);
                self->m_vfchrList.erase(it);
                return;
            }
            ++it;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CCC30);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD044);

extern "C" void func_001CD224(int arg0)
{
    func_001CB01C((GamMan *)(arg0), 2);
    func_001CDF5C((GamMan *)(arg0), 2, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD25C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD404);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD60C);

extern "C" void func_001CD7C0(void) {
}

// NON_MATCHING: 22/99 differ, 1 reloc differs, 25 edits
#ifdef NON_MATCHING
extern char D_007A4440[];
static inline int *sysWork_CD7C8() { char *p = D_007A4440; return *(int **)(p + 0xDC1C); }
extern "C" void func_001C47C4(GamMan *);
extern "C" void func_001CD60C(GamMan *);
extern "C" void func_001FBBD0();
extern "C" void func_001C204C(GamMan *, int);
extern "C" void func_001C65E8(GamMan *, int);
extern "C" void func_001CD7C8(GamMan *self)
{
    if (self->m_curStat == 2) {
        func_001CD224((int)self);
        func_001C47C4(self);
        self->m_unk225E4 = 0;
        func_001CD60C(self);
        func_001FBBD0();
    } else if (self->m_curStat == 3) {
        func_001C4F30();
    } else if (self->m_curStat == 1) {
        self->m_sysFlg &= ~0x20;
        sysWork_CD7C8()[5] = 0;
        sysWork_CD7C8()[7] = 0;
        func_001C204C(self, self->m_chapter);
    }
    sysWork_CD7C8()[3] = self->m_unk21F84;
    sysWork_CD7C8()[4] = self->m_unk21F88;
    sysWork_CD7C8()[1] = self->m_unk21F7C;
    sysWork_CD7C8()[2] = (self->m_unk2221C != 2) ? self->m_unk21F80 : -1;
    func_001C65E8(self, 2);
    func_001E7544(&D_007A3D80, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD7C8);
#endif

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF50);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF58);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF60);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF68);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBF70);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CD954);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CDBF0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CDF5C);

// Frees the model of every object of the VFchr list; with theKeep 0 the list
// is emptied too.
extern "C" void func_001CEA44(GamMan *self, int theKeep)
{
    GamList<ObjStat *>::iterator it;
    GamList<ObjStat *>::iterator last;
    int area;
    GamList<ObjStat *> *list = self->getVFchrListPtr();

    it = list->begin();
    last = list->end();
    while (it != last) {
        int chr = (*it)->getChrID();
        int oid = (*it)->getOID();
        func_001DB31C(*it, 8, &area);
        if (chr != -1) {
            func_001D966C((int)*it);
        }
        if (theKeep == 0) {
            func_001CC004(self, oid);
            it = self->m_vfchrList.erase(it);
        } else {
            ++it;
        }
    }
}

extern "C" void func_001CEBF8(GamMan *self)
{
    GamList<ACHRstat *>::iterator it1;
    GamList<ACHRstat *>::iterator last1;
    GamList<FCHRstat *>::iterator it2;
    GamList<FCHRstat *>::iterator last2;

    it1 = self->m_achrList.begin();
    last1 = self->m_achrList.end();
    while (it1 != last1) {
        func_001D88FC(*it1);
        ++it1;
    }

    it2 = self->m_fchrList.begin();
    last2 = self->m_fchrList.end();
    while (it2 != last2) {
        func_001D88FC(*it2);
        ++it2;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CED18);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CF2E8);

extern "C" void func_001CF518(GamMan *self, int arg1)
{
    GamList<ACHRstat *>::iterator it1;
    GamList<ACHRstat *>::iterator last1;
    GamList<ObjStat *>::iterator it2;
    GamList<ObjStat *>::iterator last2;

    func_001D3588(self);

    for (it1 = self->m_achrList.begin(), last1 = self->m_achrList.end(); it1 != last1; ++it1) {
        X_func_001D95C4_CF518(*it1, arg1);
    }

    for (it2 = ((GamList<ObjStat *> *)&self->m_fchrList)->begin(), last2 = ((GamList<ObjStat *> *)&self->m_fchrList)->end(); it2 != last2; ++it2) {
        X_func_001D95C4_CF518(*it2, arg1);
    }

    for (it2 = self->m_avfchrList.begin(), last2 = self->m_avfchrList.end(); it2 != last2; ++it2) {
        X_func_001D95C4_CF518(*it2, arg1);
    }
}

struct S2dMes {
    void setMessageSpriteDispOn_(int a, int b, bool c = true)
    {
        X_func_00191F98(this, a);
        X_func_00191ED0(this, a);
        X_func_00191D20(this, a, 1);
        X_func_00191D74(this, a, 1);
        if (c) {
            X_func_00191DC8(this, a, b);
        }
    }
    void setMessageSpriteStdPoint(int a, int b, int c, int d)
    {
        func_00191C00(this, a, b, c, d);
    }
    void setMessageSpriteOffPoint(int a, int b, int c)
    {
        func_00191C64((char *)this, a, b, c);
    }
    void setMessageSpriteFadeIn_(int a, int b)
    {
        X_func_00191F98(this, a);
        X_void_191E04(this, a, b);
    }
    void setMessageSpriteFadeOut(int a, int b)
    {
        X_void_191E58(this, a, b);
    }
};

static inline S2dMes *getS2dMes()
{
    unsigned int off = 0x42BB0;
    return (S2dMes *)(D_006FBD80 + off);
}

extern "C" void func_001CF6BC(int arg0, int arg1, int *arg2)
{
    if (arg1 != 0) {
        getS2dMes()->setMessageSpriteDispOn_(3, arg2[0], true);
        getS2dMes()->setMessageSpriteStdPoint(3, arg2[1] << 4, arg2[2] << 4, 0x80010);
        getS2dMes()->setMessageSpriteOffPoint(3, arg2[5] << 4, arg2[6] << 4);
        return getS2dMes()->setMessageSpriteFadeIn_(3, arg2[3]);
    } else {
        getS2dMes()->setMessageSpriteFadeOut(3, arg2[4]);
    }
}

extern "C" void func_001CF7D0(GamMan *arg0, const GamMsgRect *arg1)
{
    arg0->m_unk22280 = *arg1;
}

extern "C" void func_001CF854(GamMan *arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (Xiii_func_001E7D7C((int)&D_007A3D80, arg0->m_msgTaskID) != 0) {
        Xiii_func_001E7724((int)&D_007A3D80, arg0->m_msgTaskID);
        arg0->m_msgTaskID = -1;
    }
    temp_v0 = Xii___builtin_new(0x9C0);
    Xiiiiiiii_func_001F4A24(temp_v0, arg1, arg2, (int)&arg0->m_unk22280, 1, arg0->m_msgMode, arg3);
    X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, temp_v0, 0, (int)&arg0->m_msgTaskID, 0x11);
}

extern "C" void func_001CF95C(GamMan *arg0)
{
    if (X_func_001E7D7C((int)&D_007A3D80, arg0->m_msgTaskID) != 0) {
        X_func_001E7724((int)&D_007A3D80, arg0->m_msgTaskID);
        arg0->m_msgTaskID = -1;
    }
    arg0->m_msgMode = 0;
}

extern "C" int func_001CF9D4(GamMan *self)
{
    register char *self_reg PS2_REG("$16") = (char *)self;
    register int var_s1 PS2_REG("$17") = 0;
    int temp_v0;

    if (func_001E7D7C(&D_007A3D80, *(int *)(self_reg + 0x222A0)) == 0) {
        temp_v0 = *(int *)(self_reg + 0x2227C);
        if (temp_v0 != -1) {
            char *p = (char *)&D_006E9840;
            if (func_0013F444(p + 0x12540, temp_v0) != 0) {
                goto block_3;
            }
        }
    } else {
block_3:
        var_s1 = 1;
    }
    return var_s1;
}

extern "C" void func_001CFA5C(GamMan *self, int theA)
{
    char *p = (char *)&D_006E9840;

    self->m_sysMsgHND = X4_func_0013F280((int)(p + 0x12540), theA, 0, 0);
}

extern "C" void func_001CFAA8(GamMan *arg0)
{
    int temp_v0 = arg0->m_sysMsgHND;
    if (temp_v0 != -1) {
        char *p = (char *)&D_006E9840;
        func_00135594(p + 0x12540, temp_v0);
        func_001348B0(p + 0x12540, arg0->m_sysMsgHND);
        arg0->m_sysMsgHND = -1;
    }
    arg0->m_msgMode = 0;
}

extern "C" void func_001CFB38(GamMan *arg0, int arg1)
{
    arg0->m_sysMsgHND = arg1;
}

extern "C" float func_001CFB48(int arg0, unsigned int arg1, unsigned int arg2)
{
    DogVector v1;
    DogVector v2;

    if (Xiiu_func_001D046C(arg0, arg1) == 0 || Xiiu_func_001D046C(arg0, arg2) == 0) {
        return 0.0f;
    }
    Xiiui_func_001D05F4(arg0, arg1, (int)&v1);
    Xiiui_func_001D05F4(arg0, arg2, (int)&v2);
    return func_00217F10(v2.m_x - v1.m_x, v2.m_z - v1.m_z);
}

extern "C" int func_001CFBE4(int arg0, unsigned int arg1, int arg2)
{
    if (Xiiu_func_001D046C(arg0, arg1) == 0) {
        return 0;
    }

    switch ((arg1 >> 28) & 3) {
    case 0:
        func_001DB7CC(Xiiu_func_001D2D00(arg0, arg1), arg2);
        break;
    case 1:
        func_001D89C4(Xiiu_func_001D2B8C(arg0, arg1), arg2);
        break;
    case 2:
        func_001DB7CC(Xiiu_func_001D2BA8(arg0, arg1), arg2);
        break;
    }

    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CFCA8);

extern "C" void func_001CFDA4(int arg0, unsigned int arg1, int arg2)
{
    register unsigned int v0 PS2_REG("$2") = arg1 >> 28;
    register unsigned int a3 PS2_REG("$7") = v0 & 3;
    switch (a3) {
    case 1:
        Xii_func_001D8FEC(Xiiu_func_001D2B8C(arg0, arg1), arg2);
        break;
    case 2:
        Xii_func_001D8FEC(Xiiu_func_001D2BA8(arg0, arg1), arg2);
        break;
    }
}

extern "C" int func_001CFE1C(int arg0, unsigned int arg1)
{
    int temp_a2;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {                              
    case 1:
        return Xii_func_001D8DC4(Xiiu_func_001D2B8C(arg0, arg1));
    case 2:
        return Xii_func_001D8DC4(Xiiu_func_001D2BA8(arg0, arg1));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001CFE78);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D024C);

extern "C" int func_001D044C(GamMan *arg0)
{
    return arg0->m_achrList.m_used.m_num;
}

extern "C" int func_001D045C(GamMan *arg0)
{
    return arg0->m_fchrList.m_used.m_num;
}

extern "C" int func_001D046C(int arg0, unsigned int arg1)
{
    switch ((arg1 >> 28) & 3) {
    case 0:
        return func_001D2B10(arg0, arg1);
    case 1:
        return func_001D2AAC(arg0, arg1);
    case 2:
        if (((arg1 >> 23) & 0x1F) == 5) {
            if (func_001D2B10(arg0, arg1) != 0) {
                return 1;
            }
            return func_001D2ADC(arg0, arg1) != 0;
        }
        return func_001D2ADC(arg0, arg1);
    default:
        return 0;
    }
}

extern "C" int func_001D0530(GamMan *arg0, int arg1)
{
    GamList<GamItemStock>::iterator it;
    GamList<GamItemStock>::iterator last;
    GamList<GamItemStock> *list = arg0->getItemStockPtr();
    it = list->begin();
    last = list->end();
    while (it != last) {
        if ((*it).m_item.m_oid == arg1) {
            return 1;
        }
        ++it;
    }

    GamItemHave *vec = arg0->getItemHavePtr();
    GamItem *start = vec->m_begin;
    GamItem *finish = vec->m_end;
    for (; start != finish; start++) {
        if (start->m_oid == arg1) {
            return 1;
        }
    }
    return 0;
}

extern "C" int func_001D05F4(int arg0, unsigned int arg1, int arg2)
{
    if (Xiiu_func_001D046C(arg0, arg1) == 0) {
        return 0;
    }

    switch ((arg1 >> 28) & 3) {
    case 0:
        Xiii_func_001DB71C(Xiiu_func_001D2D00(arg0, arg1), arg2);
        break;
    case 1:
        func_001D890C(Xiiu_func_001D2B8C(arg0, arg1), arg2);
        break;
    case 2:
        Xiii_func_001DB71C(Xiiu_func_001D2BA8(arg0, arg1), arg2);
        break;
    }

    return 1;
}

extern "C" int func_001D06B8(int arg0, unsigned int arg1, int arg2)
{
    int var_v0;
    int temp_v1;

    var_v0 = Xiiu_func_001D046C(arg0, arg1);
    temp_v1 = (arg1 >> 0x1C) & 3;
    if (var_v0 != 0) {
        switch (temp_v1) {                          
        case 1:
            Xiii_func_001D8964(Xiiu_func_001D2B8C((int) arg0, arg1), (int) arg2);
block_6:
            var_v0 = (int) 1;
            
            return var_v0;
        case 2:
            Xiii_func_001DB774(Xiiu_func_001D2BA8((int) arg0, arg1), arg2);
            goto block_6;
        default:
            return (int) 1;
        }
    } else {
        return var_v0;
    }
}

extern "C" int func_001D0758(int arg0, unsigned int arg1, float *arg2)
{
    void *actor = 0;
    if (Xiiu_func_001D046C(arg0, arg1) != 0) {
        switch ((arg1 >> 28) & 3) {
        case 1:
            actor = (void *)Xiiu_func_001D2B8C(arg0, arg1);
            break;
        case 2:
            actor = (void *)Xiiu_func_001D2BA8(arg0, arg1);
            break;
        }
        *arg2 = func_0010A650__8DogActor((void *)((char *)&D_006FE6A0 + *(int *)((char *)actor + 0x108) * 0x4D0));
        return 1;
    }
    return 0;
}

// NON_MATCHING: 44/67 differ, 7 relocs differ (size 0x10C, game 0x110), 12 edits
#ifdef NON_MATCHING
extern "C" int X_func_00135E20(...) asm("func_00135E20");
extern "C" int X_func_001D932C(...) asm("func_001D932C");
extern "C" int Xiiii_func_001D5BC8(int, int, int) asm("func_001D5BC8");
extern "C" void func_001D080C(int arg0, unsigned int arg1, int arg2)
{
    void *actor = 0;
    int pos2 = arg2 + 0x10;

    if (Xiiu_func_001D046C(arg0, arg1) != 0) {
        switch ((arg1 >> 28) & 3) {
        case 1:
            actor = (void *)Xiiu_func_001D2B8C(arg0, arg1);
            break;
        case 2:
            actor = (void *)Xiiu_func_001D2BA8(arg0, arg1);
            break;
        }
        register void *a0 PS2_REG("$4") = actor;
        X_func_001D932C(a0, 5, arg2);
        X_func_001D932C(actor, 6, pos2);
        Xiiii_func_001D5BC8(arg0, 0, arg1);

        int stack[12];
        stack[0] = 5;
        stack[1] = 0;
        char *p = (char *)&D_006E9840;
        int off = 0x12540;
        stack[6] = X_func_00135E20(p + off, arg2, pos2);
        X_func_001D932C(actor, 0x18, stack);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D080C);
#endif

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D091C);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D0C64);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D0EFC);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D10D0);

INCLUDE_ASM("asm/nonmatchings/game/gamman", func_001D1410);

extern "C" int func_001D1720(int arg0, unsigned int arg1, int arg2)
{
    void *var_v0_2;

    if (Xiiu_func_001D046C(arg0, arg1) != 0) {
        switch ((arg1 >> 28) & 3) {
        case 0:
            var_v0_2 = (void *)Xiiu_func_001D2D00(arg0, arg1);
            break;
        case 1:
            var_v0_2 = (void *)Xiiu_func_001D2B8C(arg0, arg1);
            break;
        case 2:
            var_v0_2 = (void *)Xiiu_func_001D2BA8(arg0, arg1);
            break;
        default:
            return 0;
        }
        return (*(int *)((char *)var_v0_2 + 0x120) & arg2) != 0;
    }
    return 0;
}

extern "C" int func_001D17C8(int arg0, unsigned int arg1, unsigned int arg2)
{
    switch ((arg1 >> 0x1C) & 3) {
    case 1:
        return (M2C_FIELD((((arg2 >> 0x18) * 4) + Xiiu_func_001D2B8C(arg0, arg1)), int *, 0x3EC) & arg2 & 0xFFFFFF) != 0;
    case 2:
        return 0;
    default:
        return 0;
    }
}

extern "C" void func_001D1838(int unused, unsigned int arg1, unsigned int arg2)
{
    register unsigned int v0 PS2_REG("$2") = arg1 >> 28;
    register unsigned int a3 PS2_REG("$7") = v0 & 3;
    switch (a3) {
    case 1: {
        register char *ret PS2_REG("$2") = (char *)func_001D2B8C();
        int mask = arg2 & 0x00FFFFFF;
        register int idx PS2_REG("$3") = (arg2 >> 24) << 2;
        idx += (int)ret;
        idx += 0x3EC;
        *(int *)idx |= mask;
        break;
    }
    case 2:
        *(int *)((char *)func_001D2BA8() + 0x120) |= arg2;
        break;
    default:
        break;
    }
}

extern "C" void func_001D18C4(int unused, unsigned int arg1, unsigned int arg2)
{
    register unsigned int v0 PS2_REG("$2") = arg1 >> 28;
    register unsigned int a3 PS2_REG("$7") = v0 & 3;
    switch (a3) {
    case 1: {
        register char *ret PS2_REG("$2") = (char *)func_001D2B8C();
        int mask = arg2 & 0x00FFFFFF;
        register int idx PS2_REG("$3") = (arg2 >> 24) << 2;
        idx += (int)ret;
        idx += 0x3EC;
        *(int *)idx &= ~mask;
        break;
    }
    case 2:
        *(int *)((char *)func_001D2BA8() + 0x120) &= ~arg2;
        break;
    default:
        break;
    }
}

extern "C" int func_001D1958(int arg0, unsigned int arg1)
{
    int temp_a2;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {                              
    case 1:
        return Xii_func_001D9F40(Xiiu_func_001D2B8C(arg0, arg1));
    case 2:
        return 0;
    default:
        return 0;
    }
}

extern "C" int func_001D19A8(int arg0, unsigned int arg1)
{
    int temp_a2;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {                              
    case 1:
        return Xii_func_001D9F84(Xiiu_func_001D2B8C(arg0, arg1));
    case 2:
        return 0;
    default:
        return 0;
    }
}

extern "C" int func_001D19F8(int arg0, unsigned int arg1)
{
    int temp_a2;

    temp_a2 = (arg1 >> 0x1C) & 3;
    switch (temp_a2) {                              
    case 1:
        return Xii_func_001DA05C(Xiiu_func_001D2B8C(arg0, arg1));
    case 2:
        return 0;
    default:
        return 0;
    }
}

extern "C" int func_001D1A48()
{
    return ~(*(int *)((int)&D_00727BD0)) != 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFD0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFE0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFE8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFF0);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FBFF8);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC000);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC008);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC010);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC018);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC020);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC028);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC030);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC038);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC040);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC048);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC050);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC058);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC060);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC068);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC070);

INCLUDE_RODATA("asm/nonmatchings/game/gamman", D_002FC078);

extern "C" void func_001D1A5C(GamMan *self, unsigned int oid1, unsigned int oid2, const char *nodeName)
{
    if (Xiiu_func_001D046C((int)self, oid1) != 0 && Xiiu_func_001D046C((int)self, oid2) != 0) {
        int buf[4];
        X_memset_D1A5C(buf, 0, 0x10);
        int chr1 = Xiiu_func_001CBE38((int)&D_007812C0, oid1);
        int chr2 = Xiiu_func_001CBE38((int)&D_007812C0, oid2);
        func_001CFBE4((int)self, oid1, (int)buf);
        int node = D_006FE6A0_D1A5C[chr2].getNodeIndexByName(nodeName);
        if (chr1 == -1 || chr2 == -1 || node == -1) {
            func_00260110("chr_id : %d , %d node %s invalid attach param. \n", chr1, chr2, nodeName);
        } else {
            attachActor__9MagSystemiii(&D_006E9840, chr1, chr2, node);
            if (((oid2 >> 28) & 3) == 1) {
                *(unsigned int *)((char *)Xiiu_func_001D2B8C((int)self, oid2) + 0x254) = oid1;
            }
        }
    }
}
