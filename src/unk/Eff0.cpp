#include "include_asm.h"
#include "unk/Eff0.h"
#include "dog/doglightpool.h"
#include "sdk/string.h"
struct EffBloodSpray1Particle {
    EffVec3 m_pos;                      // +0x00
    float m_unk0C;                      // +0x0C
    EffVec3 m_vel;                      // +0x10
    float m_unk1C;                      // +0x1C
    short m_alpha;                      // +0x20
    short m_fade;                       // +0x22
    unsigned short m_fadeAcc;           // +0x24
    unsigned short m_pad26;             // +0x26
    float m_speed;                      // +0x28
    float m_grav;                       // +0x2C
    float m_rot;                        // +0x30
    float m_drot;                       // +0x34
    unsigned char m_pad38[0x08];        // +0x38
}; // size 0x40
struct EffBloodSpray1 : public Eff0 {
    int m_timer24;                      // +0x24
    unsigned char m_pad28[0x18];        // +0x28
    EffBloodSpray1Particle m_particles[9]; // +0x40
};
struct EffBreath1 : public Eff0 {
    unsigned char m_pad24[0x4C];        // +0x24
    int m_unk70;                        // +0x70
    unsigned char m_pad74[0x110];       // +0x74
    float m_unk184;                     // +0x184
    float m_unk188;                     // +0x188
    float m_unk18C;                     // +0x18C
    float m_unk190;                     // +0x190
};
struct Obj_E65C;
extern "C" int func_0016E65C(Obj_E65C *);
extern "C" void func_0016E438(char *);
struct EffBreath1SpaceArg : public Eff0Arg {
    float m_p0[3];                      // +0x10
    float m_p1[3];                      // +0x1C
    float m_unk28;                      // +0x28
    EffVec4 m_unk2C;                    // +0x2C
};
struct EffBreath1Space_02 : public Eff0 {
    float m_min[3];                     // +0x24
    float m_max[3];                     // +0x30
    float m_unk3C;                      // +0x3C
    EffVec4 m_unk40;                    // +0x40
    int m_unk50[0x80];                  // +0x50
    int m_unk250;                       // +0x250
};
struct EffStay2Pair {
    EffVec4 a;
    EffVec4 b;
};
struct Obj_Stay2_D3E4 {
    unsigned char m_pad00[0x30];        // +0x00
    EffStay2Pair m_30[32];              // +0x30
    unsigned char m_pad430[0x4B8 - 0x430];
    float m_4B8;                        // +0x4B8
    unsigned char m_pad4BC[0x4C8 - 0x4BC];
    int m_4C8;                          // +0x4C8
};
extern "C" void func_00237360(EffVec4 *, EffVec4 *, float);
extern "C" void func_002373D8(EffVec4 *, EffVec4 *, EffVec4 *);
extern "C" void func_00237560(EffVec4 *, EffVec4 *, EffVec4 *);
extern "C" void func_002375D8(EffVec4 *, EffVec4 *);
struct Param_D8E8 {
    int m_kind;
    int m_unk04;
    int m_unk08;
    int m_pad[29];
};
struct Entry_D8E8 {
    unsigned char pad00[0x24];
    int m_24[1];
};
struct EffMgr_D8E8 {
    int m_00;
    Entry_D8E8 *m_04[1];
};
struct Scene_D8E8 {
    unsigned char pad00[0x837E0];
    EffMgr_D8E8 m_effMgr;
};
extern "C" int func_00176CC8(void *, void *);
extern "C" float modff(float, float *);
struct EffBg1Chunk {
    unsigned short m_type;              // +0x00
    unsigned short m_size;              // +0x02
    float m_tag[8];                     // +0x04
    float m_du;                         // +0x24
    float m_dv;                         // +0x28
    float m_u;                          // +0x2C
    float m_v;                          // +0x30
};
struct EffBg1Data {
    unsigned short m_flags;             // +0x00
    unsigned short m_chunkCount;        // +0x02
    unsigned char m_pad04[0x0C];        // +0x04
    EffBg1Chunk m_chunks[1];            // +0x10
};
struct EffBg1 : public Eff0 {
    unsigned char m_pad24[0x1C];        // +0x24
    EffBg1Data *m_data;                 // +0x40
    unsigned short m_curFrame;          // +0x44
    unsigned short m_maxFrame;          // +0x46
};
extern "C" int X_func_00223558(...) asm("func_00223558");
struct Arg_Stay2 {
    unsigned char pad00[0x10];
    float *m_10;
    int m_14;
    float m_18;
    float m_1C;
};
struct Obj_Stay2 {
    unsigned char pad00[0x4B0];
    float *m_4B0;
    int m_4B4;
    float m_4B8;
    float m_4BC;
    float m_4C0;
    float m_4C4;
    int m_4C8;
    int m_4CC;
    float m_4D0[4];
    float m_4E0[4];
};
extern "C" int X_func_0016AD94(...) asm("func_0016AD94");
struct ALIGNED(8) Stay02Vec { float x,y,z,w; };
extern "C" void stay02Matrix(int, Stay02Vec *) asm("func_0016FDA0");
struct Obj_Stay1_v5 {
    unsigned short m_00;
    unsigned char pad02[0x06];
    int m_08;
    int m_0C;
    unsigned char pad10[0xA4];
    int m_B4;
    float m_B8;
    int m_BC;
};
struct Scene_AF20 {
    unsigned char unk[0x2050];
    DogLightPool m_light_pool;
};
extern Scene_AF20 *D_00298E08_AF20 asm("D_00298E08");
struct Eff0VCall {
    unsigned short m_flags;             // +0x00
    unsigned short m_pad02;             // +0x02
    int m_timer;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    float m_zDepth;                     // +0x10
    void *m_parent;                     // +0x14
    int m_kind;                         // +0x18
    int m_delay;                        // +0x1C
    virtual void v1();                  // +0x08
    virtual void v2();                  // +0x10
    virtual void v3();                  // +0x18
    virtual void v4();                  // +0x20
    virtual int liveExec();             // +0x28 (slot 5)
    virtual void v6();                  // +0x30
    virtual void renderPreMain(EffRenderParam *); // +0x38 (slot 7)
    virtual int renderMain(EffRenderParam *, int, int); // +0x40 (slot 8)
    virtual int createPacketEntry(int); // +0x48 (slot 9)
    virtual void v10();                 // +0x50
    virtual void liveActivateExec();    // +0x58 (slot 11)
};
struct Vec3_E65C {
    float x;
    float y;
    float z;
};
struct Sub50_E65C {
    unsigned char pad[0x40];
    Vec3_E65C pos;
};
struct Obj_E65C {
    unsigned char pad00[0x24];
    float minX;
    float minY;
    float minZ;
    float maxX;
    float maxY;
    float maxZ;
    unsigned char pad3C[0x14];
    Sub50_E65C *sub;
};
#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)
struct m2c_block12 { int w[3]; };
struct m2c_ulong { long v; } __attribute__((packed));
extern "C" float Xii_func_0016FF18(int, int) asm("func_0016FF18");
extern "C" int Xii_func_0016A914(int) asm("func_0016A914");
extern "C" int Xii_func_00173DF8(int) asm("func_00173DF8");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" char vtbl_4Eff0[] asm("_vt$4Eff0");
extern int _vt$14EffBloodSpray1;
extern int _vt$14EffBloodSpray2;
extern int _vt$6EffBg1;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xi_func_0016AD94() asm("func_0016AD94");
extern "C" int Xii_func_0016BEDC(int) asm("func_0016BEDC");
extern "C" int Xiii_Eff0__vfunc_02(int, int) asm("Eff0__vfunc_02");
extern "C" int Xiii_func_0016B50C(int, int) asm("func_0016B50C");
extern "C" int Xiii_func_00174BB0(int, int) asm("func_00174BB0");
extern "C" int Xiii_func_00174BD8(int, int) asm("func_00174BD8");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_Eff0__vfunc_02(...) asm("Eff0__vfunc_02");
extern "C" int X_I3rRoot__CheckIdString(...) asm("I3rRoot__CheckIdString");
extern "C" int X_func_00139568(...) asm("func_00139568");
extern "C" int X_func_0016B50C(...) asm("func_0016B50C");
extern "C" int X_func_0016E92C(...) asm("func_0016E92C");
extern "C" int X_func_0016E9F4(...) asm("func_0016E9F4");
extern "C" int X_func_0016FF18(...) asm("func_0016FF18");
extern "C" int X_func_001700B0(...) asm("func_001700B0");
extern "C" int X_func_00174BB0(...) asm("func_00174BB0");
extern "C" int X_func_00174BD8(...) asm("func_00174BD8");
extern "C" int X_func_0017756C(...) asm("func_0017756C");
extern "C" int X_func_0022AAB8(...) asm("func_0022AAB8");
extern "C" int X_memset(...) asm("memset");
extern "C" int X_ror_assert(...) asm("ror_assert");
extern "C" int X_strcasecmp(...) asm("strcasecmp");
extern const char D_002F21D0[];
extern int D_00298E08;
extern int D_00308050;
extern int D_007812C0;
extern int D_007B2140;
extern int D_008282A0[];
extern int D_00828378;
extern float D_002F1ED0;
extern "C" void X_func_0016A594(int, float *) asm("func_0016A594");
extern "C" int X_func_00163EA0(void *, int, int) asm("func_00163EA0");
extern "C" int X_func_001E4EBC(void *, int, int, float *, int) asm("func_001E4EBC");
extern "C" void X_func_00223228(int, int) asm("func_00223228");
extern "C" int X_func_00223298(int, float) asm("func_00223298");
extern "C" void X_func_002232F0(int, int) asm("func_002232F0");

extern "C" int func_0016A8A4(int arg0, int arg1)
{
    float pos[4];
    int id;
    int off = 0x18E00;

    X_func_0016A594(arg0, pos);
    id = X_func_00163EA0(&D_007B2140, arg0, arg1);
    return X_func_001E4EBC((char *)&D_007812C0 + off, id, 0, pos, 0);
}

extern "C" void func_0016A914(Eff0 *self)
{
    register void *vt PS2_REG("$2") = vtbl_4Eff0;
    float z = D_002F1ED0;
    self->m_timer = -1;
    self->m_vtbl = vt;
    self->m_zDepth = z;
    self->m_kind = 0;
    self->m_flags = 0;
    self->m_delay = 0;
    self->m_unk08 = 0;
    self->m_unk0C = 0;
    self->m_parent = 0;
}

extern "C" void X_Eff0__vfunc_03(Eff0 *) asm("Eff0__vfunc_03");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void dtor_4Eff0(Eff0 *, int) asm("_$_4Eff0");

extern "C" void dtor_4Eff0(Eff0 *self, int arg1)
{
    self->m_vtbl = vtbl_4Eff0;
    X_Eff0__vfunc_03(self);
    if (arg1 & 1) {
        return X___builtin_delete(self);
    }
}

extern "C" int Eff0__vfunc_02(Eff0 *self, Eff0Arg *arg1)
{
    void *parent;

    self->m_kind = arg1->m_kind;
    self->m_delay = arg1->m_delay;
    parent = arg1->m_parent;
    if (parent != 0) {
        self->m_parent = parent;
        M2C_FIELD(parent, int *, 0x2C) = M2C_FIELD(parent, int *, 0x2C) + 1;
    }
    return 1;
}


extern "C" void Eff0__vfunc_03(Eff0 *self)
{
    void *parent;

    parent = self->m_parent;
    self->m_flags = 0;
    self->m_kind = 0;
    if (parent != 0) {
        M2C_FIELD(parent, int *, 0x2C) = M2C_FIELD(parent, int *, 0x2C) - 1;
    }
}

extern "C" void Eff0__vfunc_10(Eff0 *self, int arg1)
{
    unsigned short flags = self->m_flags;

    self->m_flags = arg1 != 0 ? (flags & 0xFFFB) : (flags | 4);
    self->m_flags |= 8;
}

extern "C" int Eff0__vfunc_04(Eff0 *self)
{
    int temp_v0;
    int temp_v1;
    int var_v0;

    temp_v0 = self->m_delay;
    temp_v1 = temp_v0 - 1;
    if ((temp_v0 < 0) || (self->m_delay = temp_v1, var_v0 = 1, (temp_v1 < 0))) {
        if (self->m_flags & 8) {
            ((Eff0VCall *)self)->liveActivateExec();
        }
        if (self->m_timer >= 0) {
            if (--self->m_timer <= 0) {
                self->m_timer = -1;
                self->m_flags |= 2;
            }
        }
        var_v0 = ((Eff0VCall *)self)->liveExec();
    }
    return var_v0;
}

extern "C" void render__4Eff0PQ24Eff011RENDERPARAM(Eff0 *self, EffRenderParam *param)
{
    if (self->m_delay < 0) {
        param->m_unk08 = param->m_unk00;
        ((Eff0VCall *)self)->renderPreMain(param);
    }
}

extern "C" void renderPreMain__4Eff0PQ24Eff011RENDERPARAM(Eff0 *self, EffRenderParam *param)
{
    int *tbl = D_008282A0;
    if (tbl[self->m_kind] == 0) {
        tbl[self->m_kind] = ((Eff0VCall *)self)->createPacketEntry(param->m_unk08);
    }
    int pkt = tbl[self->m_kind];
    X_func_00223228(param->m_unk08, pkt);
    int ctx = X_func_00223298(param->m_unk08, 0.0f);
    int res = ((Eff0VCall *)self)->renderMain(param, pkt, ctx);
    X_func_002232F0(param->m_unk08, res);
}

struct Arg223558_PE {
    float unk00;
    void *unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct Sub14Hdr_PE {
    unsigned char pad00[0x30];
    int data[8];
    int unk50;
    int unk54;
    int unk58;
};
extern "C" int X_func_00223558_PE(int, Arg223558_PE *) asm("func_00223558");
extern "C" int createPacketEntry__4Eff0P20tag_I3dRenderStage_s(Eff0 *self, int arg1)
{
  int arr[8];
  Arg223558_PE q;
  int ret = 0;
  Sub14Hdr_PE *sub = (Sub14Hdr_PE *)self->m_parent;
  if (sub->unk58 != 0)
  {
    int i = 0;
    int *src = &sub->data[sub->unk50 + sub->unk54];
    if (sub->unk58 > 0)
    {
      int *dst = arr;
      do
      {
        *(dst++) = *(src++);
        i++;
      }
      while (i < ((Sub14Hdr_PE *)self->m_parent)->unk58);
    }
    q.unk00 = 1.0f;
    q.unk04 = arr;
    q.unk08 = ((Sub14Hdr_PE *)self->m_parent)->unk58;
    q.unk0C = 0;
    q.unk10 = 0;
    q.unk14 = 0;
    ret = X_func_00223558_PE(arg1, &q);
  }
  return ret;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016AC84);

extern "C" int func_0016AD94()
{
    int *p = &D_00308050;
    int old = *p;
    int idx = old + 1;
    int t = (idx < 0) ? (old + 0x100) : idx;
    int d = idx - ((t >> 8) << 8);

    *p = d;
    return ((unsigned char *)&D_00828378)[d];
}

extern "C" void func_0016ADD8()
{
    X_memset((int)&D_008282A0, 0, 0xD8);
}


INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016AE00);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E88);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E90);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1E98);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EA0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EA8);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EB0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EB8);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1EC0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1ED0);

extern "C" void func_0016AF20(float *arg0)
{
    DogLightAmbient *amb = D_00298E08_AF20->m_light_pool.getAmbient(0);
    arg0[0] *= amb->m_color[0];
    arg0[1] *= amb->m_color[1];
    arg0[2] *= amb->m_color[2];
}

extern "C" void func_0016AFCC(int arg0)
{
    Xii_func_00173DF8(arg0);
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$6EffBg1;
}

extern "C" void X_dtor_11EffGeneric1(int, int) asm("_$_11EffGeneric1");
extern "C" void dtor_6EffBg1(int, int) asm("_$_6EffBg1");

extern "C" void dtor_6EffBg1(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$6EffBg1;
    X_dtor_11EffGeneric1(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F38);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F40);

// NON_MATCHING: 35/185 differ (size 0x2E4, game 0x2E8), 10 edits
#ifdef NON_MATCHING
struct Bg02Pack { char *top; int *size; int *offset; short *user; char *name; // Bg02 declaration
    void *file(int n) const { // Bg02 declaration
        if (!top) ror_assert("bed/bedpfh.h",85,"m_top"); // Bg02 declaration
        if (!(n>=0 && n<((short *)top)[7])) ror_assert("bed/bedpfh.h",86,"n >= 0 && n < m_top->m_num_file"); // Bg02 declaration
        return top + offset[n]; // Bg02 declaration
    } // Bg02 declaration
}; // Bg02Pack // Bg02 declaration
struct Bg02Data { int words[8]; }; // Bg02 declaration
extern "C" void bg02Clear(Bg02Pack *) asm("clear__6BedPfh"); // Bg02 declaration
extern "C" void bg02Top(Bg02Pack *,void *) asm("setTop__6BedPfhPv"); // Bg02 declaration
extern "C" const char *bg02Name(Bg02Pack *,int) asm("getName__C6BedPfhi"); // Bg02 declaration
extern "C" int bg02Compare(const char *,const char *) asm("strcasecmp"); // Bg02 declaration
extern char bg02Heap[] asm("D_006E9800"); // Bg02 declaration
extern "C" void *bg02Alloc(void *,int,int) asm("alloc__9BedMemoryii"); // Bg02 declaration
extern "C" void *bg02Copy(void *,const void *,unsigned int) asm("memcpy"); // Bg02 declaration
extern "C" void *bg02Zero(void *,int,unsigned int) asm("memset"); // Bg02 declaration
extern "C" int bg02Count(int) asm("func_0022AEC0"); // Bg02 declaration
extern "C" int EffBg1__vfunc_02(int obj,int param)
{
    Bg02Pack pack;
    register int result PS2_REG("$2")=Xiii_Eff0__vfunc_02(obj,param);
    if (result!=0) {
        int scene=D_00298E08+0x29550;
        result=0;
        if (scene!=0) {
            int data=M2C_FIELD(scene,int *,0x11C);
            M2C_FIELD(obj,int *,0x24)=data;
            if (data!=0) {
                bg02Clear(&pack);
                bg02Top(&pack,M2C_FIELD(M2C_FIELD(param,int *,12),void **,0x28));
                int source=M2C_FIELD(param,int *,12);
                int index=M2C_FIELD(source,int *,0x50)+M2C_FIELD(source,int *,0x54)+M2C_FIELD(source,int *,0x58);
                if (bg02Compare(bg02Name(&pack,index),"eff")==0) {
                    int size=pack.size ? pack.size[index] : -1;
                    void *allocated=bg02Alloc(bg02Heap,size,-1);
                    M2C_FIELD(obj,void **,0x40)=allocated;
                    bg02Copy(allocated,pack.file(index),size);
                } else {
                    void *allocated=bg02Alloc(bg02Heap,16,-1);
                    M2C_FIELD(obj,void **,0x40)=allocated;
                    bg02Zero(allocated,0,16);
                    M2C_FIELD(M2C_FIELD(obj,void **,0x40),short *,0)=7;
                }
                char *record=M2C_FIELD(obj,char **,0x40)+16;
                register int i PS2_REG("$6")=0;
                if (M2C_FIELD(M2C_FIELD(obj,void **,0x40),unsigned short *,2)!=0) {
                    do {
                        switch (M2C_FIELD(record,unsigned short *,0)) {
                        case 4: *(Bg02Data *)(record+4)=*(Bg02Data *)(param+0x1C); break;
                        case 5: *(Bg02Data *)(record+4)=*(Bg02Data *)(param+0x1C); break;
                        case 6: *(Bg02Data *)(record+4)=*(Bg02Data *)(param+0x1C); break;
                        }
                        register void *header PS2_REG("$2")=M2C_FIELD(obj,void **,0x40);
                        i++;
                        register int stride PS2_REG("$3")=M2C_FIELD(record,unsigned short *,2);
                        int max=M2C_FIELD(header,unsigned short *,2);
                        record+=stride;
                    } while (i < M2C_FIELD(M2C_FIELD(obj,void **,0x40),unsigned short *,2));
                }
                M2C_FIELD(obj,short *,0x44)=0;
                M2C_FIELD(obj,unsigned short *,0x46)=M2C_FIELD(M2C_FIELD(obj,void **,0x40),unsigned short *,4);
                register int count PS2_REG("$16")=bg02Count(M2C_FIELD(obj,int *,0x24)+16);
                if (count>0) {
                    M2C_FIELD(obj,void **,0x3C)=bg02Alloc(bg02Heap,count*16,-1);
                    register int n PS2_REG("$6")=0;
                    if (count>0) {
                        do {
                            int offset=n*16;
                            n++;
                            float *p=(float *)(offset+M2C_FIELD(obj,int *,0x3C));
                            p[0]=p[1]=0.0f;
                            float *q=(float *)(offset+M2C_FIELD(obj,int *,0x3C));
                            q[2]=q[3]=1.0f;
                        } while(n<count);
                    }
                    return 1;
                }
                M2C_FIELD(obj,void **,0x3C)=0;
                result=1;
            }
        }
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBg1__vfunc_02);
#endif

extern "C" int EffBg1__vfunc_05(EffBg1 *self)
{
    float ipart;
    self->m_curFrame++;
    if (self->m_curFrame > self->m_maxFrame) {
        self->m_curFrame = self->m_curFrame - self->m_maxFrame - 1;
    }
    char *p = (char *)self->m_data->m_chunks;
    for (int i = 0; i < self->m_data->m_chunkCount; i++) {
        EffBg1Chunk *c = (EffBg1Chunk *)p;
        if (c->m_type == 4) {
            c->m_u += c->m_du / 60.0f;
            c->m_v += c->m_dv / 60.0f;
            c->m_u = modff(c->m_u, &ipart);
            c->m_v = modff(c->m_v, &ipart);
        }
        p += c->m_size;
    }
    return 1;
}

extern "C" void renderPreMain__6EffBg1PQ24Eff011RENDERPARAM(int arg0, int arg1)
{
    int var_s2;
    unsigned short temp_v1;
    int temp_v0;
    int var_s0;

    var_s2 = 0;
    temp_v0 = M2C_FIELD(arg0, int *, 0x40);
    var_s0 = temp_v0 + 0x10;
    if (M2C_FIELD(temp_v0, unsigned short *, 2) != 0) {
        do {
            temp_v1 = M2C_FIELD(var_s0, unsigned short *, 0);
            switch (temp_v1) {                      
            case 4:
                Xiii_func_00174BB0(arg0, var_s0);
                break;
            case 5:
                Xiii_func_00174BD8((int) arg0, var_s0);
                break;
            case 6:
                Xiii_func_0016B50C((int) arg0, var_s0);
                break;
            }
            var_s2 += 1;
            var_s0 += M2C_FIELD(var_s0, unsigned short *, 2);
        } while (var_s2 < (int) M2C_FIELD(M2C_FIELD(arg0, int *, 0x40), unsigned short *, 2));
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016B50C);

extern "C" int func_0016B62C(int arg0)
{
    Xii_func_0016A914(arg0);
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$14EffBloodSpray1;
    return Xiiii_memset(arg0 + 0x40, 0, 0x240);
}

// NON_MATCHING: 12/196 differ, 8 edits
#ifdef NON_MATCHING
struct Spray02Table { float angle[9][2]; };
struct ALIGNED(8) Spray02Vec { float x,y,z,w; };
extern Spray02Table spray02Angles asm("D_002F1FA0");
extern "C" void spray02Identity(void *) asm("func_00237340");
extern "C" void spray02RotateX(void *,void *,float) asm("func_00237818");
extern "C" void spray02RotateZ(void *,void *,float) asm("func_00237848");
extern "C" void spray02Transform(Spray02Vec *,void *,Spray02Vec *) asm("func_002373A8");
extern "C" float fabsf(float);
extern "C" int EffBloodSpray1__vfunc_02(int obj,int param)
{
    Spray02Table angles ALIGNED(16);
    long long matrix[8];
    Spray02Vec direction;
    Spray02Vec temp;
    int result=Xiii_Eff0__vfunc_02(obj,param);
    if (result!=0) {
        M2C_FIELD(obj,int *,0x24)=0;
        float spread=M2C_FIELD(param,float *,0x28)*4.5f;
        float speed=M2C_FIELD(param,float *,0x28);
        float size=spread*0.5f;
        float life=spread*3.0f;
        angles=spray02Angles;
        char *particle=(char *)(obj+0x40);
        int count=8;
        M2C_FIELD(obj,float *,0x30)=M2C_FIELD(param,float *,0x10);
        M2C_FIELD(obj,float *,0x34)=M2C_FIELD(param,float *,0x14);
        M2C_FIELD(obj,float *,0x38)=M2C_FIELD(param,float *,0x18);
        M2C_FIELD(obj,float *,0x3C)=1.0f;
        int index=(X_func_0016AD94()%9U)&0xFF;
        do {
            register int offset PS2_REG("$17")=index*8;
            float y=M2C_FIELD(param,float *,0x20);
            register float x PS2_REG("$f0")=M2C_FIELD(param,float *,0x1C);
            register float z PS2_REG("$f2")=M2C_FIELD(param,float *,0x24);
            temp.y=y;
            count--;
            temp.x=x; temp.z=z; temp.w=0;
            long long lo=*(long long *)&temp;
            long long hi=*((long long *)&temp+1);
            *(long long *)&direction=lo;
            *((long long *)&direction+1)=hi;
            spray02Identity(matrix);
            spray02RotateX(matrix,matrix,*(float *)((char *)&angles+offset));
            spray02RotateZ(matrix,matrix,*(float *)((char *)&angles+offset+4));
            spray02Transform(&direction,matrix,&direction);
            M2C_FIELD(particle,short *,0x20)=0x7F00;
            M2C_FIELD(particle,short *,0x22)=0;
            M2C_FIELD(particle,short *,0x24)=(int)(speed*192.0f)+0x300;
            register float decay PS2_REG("$f1")=0.8f;
            speed*=1.25f;
            long long dirLo=*(long long *)&direction;
            long long dirHi=*((long long *)&direction+1);
            *(long long *)particle=*(long long *)(obj+0x30);
            long long originHi=*(long long *)(obj+0x38);
            *(long long *)(particle+0x10)=dirLo;
            M2C_FIELD(particle,float *,0x28)=life;
            life*=decay;
            register float height PS2_REG("$f0")=M2C_FIELD(particle,float *,0x14)*0.5f;
            *(long long *)(particle+8)=originHi;
            *(long long *)(particle+0x18)=dirHi;
            register float gravity PS2_REG("$f1")=M2C_FIELD(param,float *,0x28)*0.01f;
            M2C_FIELD(particle,float *,0x34)=size;
            size*=1.1f;
            M2C_FIELD(particle,float *,0x30)=spread;
            height=fabsf(height);
            gravity+=0.04f;
            height+=0.5f;
            M2C_FIELD(particle,float *,0x2C)=height*gravity;
            index=(index+1)%9;
            particle+=0x40;
        } while(count>=0);
        result=1;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray1__vfunc_02);
#endif

extern "C" int EffBloodSpray1__vfunc_05(EffBloodSpray1 *arg0)
{
    int i;
    EffBloodSpray1Particle *p;

    arg0->m_timer24++;
    if (arg0->m_timer24 >= 9) {
        p = arg0->m_particles;
        for (i = 0; i < 9; i++, p++) {
            if (p->m_alpha >= 0x100) {
                if (p->m_alpha < p->m_fade) {
                    p->m_alpha = 0;
                } else {
                    p->m_alpha = (unsigned short)p->m_alpha - (unsigned short)p->m_fade;
                    p->m_fade = (unsigned short)p->m_fade + p->m_fadeAcc;
                }
            }
        }
    }
    p = arg0->m_particles;
    for (i = 0; i < 9; i++, p++) {
        if (p->m_alpha >= 0x100) {
            p->m_pos.x += p->m_vel.x * p->m_speed;
            p->m_pos.y += p->m_vel.y * p->m_speed;
            p->m_pos.z += p->m_vel.z * p->m_speed;
            p->m_vel.y += p->m_grav;
            p->m_speed *= 0.975f;
            p->m_rot += p->m_drot;
        }
    }
    if (arg0->m_particles[0].m_alpha < 0x100) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray1__vfunc_08);

extern "C" void updateZDepth__14EffBloodSpray1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70, arg0 + 0x30);
}

extern "C" int func_0016BE14(int arg0)
{
    Xii_func_0016A914(arg0);
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0x20) = (int)&_vt$14EffBloodSpray2;
    M2C_FIELD(arg0, float *, 0x38) = 1.0f;
    M2C_FIELD(arg0, int *, 0x28) = 0;
    M2C_FIELD(arg0, int *, 0x2C) = 0;
    M2C_FIELD(arg0, int *, 0x30) = 0;
    M2C_FIELD(arg0, int *, 0x34) = 0;
    return Xiiii_memset(arg0 + 0x40, 0, 0x550);
}

extern "C" int EffBloodSpray2__vfunc_02(int arg0, int arg1)
{
    int var_v0;

    var_v0 = Xiii_Eff0__vfunc_02(arg0, arg1);
    if (var_v0 != 0) {
        M2C_FIELD(arg0, int *, 0x30) = (int) M2C_FIELD(arg1, int *, 0x10);
        M2C_FIELD(arg0, int *, 0x34) = (int) M2C_FIELD(arg1, int *, 0x14);
        M2C_FIELD(arg0, float *, 0x38) = (float) M2C_FIELD(arg1, float *, 0x18);
        M2C_FIELD(arg0, int *, 0x28) = (int) M2C_FIELD(arg1, int *, 0x1C);
        M2C_FIELD(arg0, int *, 0x2C) = Xi_func_0016AD94();
        Xii_func_0016BEDC(arg0);
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016BEDC);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray2__vfunc_05);

// NON_MATCHING: 187/206 differ, 15 relocs differ (size 0x338, game 0x348), 119 edits
#ifdef NON_MATCHING
struct ALIGNED(8) Spray08Entry { int index; float distance; };
struct ALIGNED(8) Spray08Vec { float x,y,z,w; };
struct Spray08Mat { long long q[8]; };
struct Spray08Camera { char data[0x94]; virtual void X__vfunc_00(); virtual void X__vfunc_01(); };
extern Spray08Vec spray08Scale asm("D_002F1FF0");
extern Spray08Vec spray08Color asm("D_002F2000");
extern Spray08Vec spray08UV asm("D_002F2010");
extern "C" float spray08Distance(void *,void *) asm("func_0016FF18");
extern "C" int spray08Texture(int,int) asm("func_0021B5A0");
extern "C" int spray08Write(int,int,unsigned long long) asm("func_0021B550");
extern "C" int spray08Start(int,int,int) asm("func_0021E5A0");
extern "C" int spray08SetUV(int,void *) asm("func_0021E488");
extern "C" void spray08Light(void *) asm("func_0016AF20");
extern "C" void spray08Fog(void *,float) asm("func_0016AE00");
extern "C" void spray08ScaleMat(void *,void *,void *) asm("func_00237A40");
extern "C" int spray08State(int,int) asm("func_0021B260");
extern "C" int spray08Join(int,int) asm("func_0021B4F8");
extern "C" int spray08Matrix(int,void *) asm("func_0021E428");
extern "C" int spray08Vertex(int,void *,void *) asm("func_0021E690");
extern "C" int spray08End(int) asm("func_0021E688");
extern "C" int EffBloodSpray2__vfunc_08(char *obj,int render,int state,int packet) {
    Spray08Entry entries[17];
    Spray08Entry tmp;
    Spray08Mat matrix;
    Spray08Vec scale,color,uv;
    char *part=obj+0x40;
    Spray08Camera *camera=(Spray08Camera *)(D_00298E08+0x2AB70);
    int count=0;
    Spray08Entry *out=entries;
    int i=0;
    do {
        if (M2C_FIELD(part,short *,0x34)>=256) {
            out->index=i; count++;
            out->distance=spray08Distance(camera,part); out++;
        }
        i++; part+=0x50;
    } while(i<17);
    if (count>0) {
        for(i=0;i<count-1;i++) {
            int best=i;
            for(int j=i+1;j<count;j++) if(entries[best].distance<entries[j].distance) best=j;
            if(best!=i) { tmp=entries[i]; entries[i]=entries[best]; entries[best]=tmp; }
        }
        camera->X__vfunc_01();
        short last=-1;
        scale=spray08Scale; color=spray08Color;
        int cmd=spray08Write(spray08Texture(packet,M2C_FIELD(render,int *,8)),0x42,0x44);
        uv=spray08UV;
        cmd=spray08SetUV(spray08Start(cmd,M2C_FIELD(render,int *,8),1),&uv);
        spray08Light(&color); spray08Fog(&color,M2C_FIELD(obj,float *,0x10));
        out=entries;
        if(count>0) {
            i=count;
            do {
                part=obj+out->index*0x50+0x40; out++;
                color.w=(float)M2C_FIELD(part,short *,0x34)*0.000030517578125f;
                matrix=*(Spray08Mat *)camera;
                *(Spray08Vec *)((char *)&matrix+0x30)=*(Spray08Vec *)part;
                scale.x=scale.y=M2C_FIELD(part,float *,0x28);
                spray08ScaleMat(&matrix,&matrix,&scale);
                short mode=M2C_FIELD(part,short *,0x30);
                if(mode!=last) { last=M2C_FIELD(part,short *,0x30); cmd=spray08Join(cmd,spray08State(state,mode)); }
                i--;
                cmd=spray08Vertex(spray08Matrix(cmd,&matrix),(char *)&matrix+0x30,&color);
            } while(i);
        }
        return spray08End(cmd);
    }
    return packet;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodSpray2__vfunc_08);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", updateZDepth__14EffBloodSpray2);

extern "C" int EffBloodStay1__vfunc_02(int in0, int in1)
{
    register int arg0 PS2_REG("$19") = in0;
    register int arg1 PS2_REG("$16") = in1;
    struct { Stay02Vec copy; Stay02Vec temp; } stack;
    float temp_f4;
    float temp_f5;
    int temp_s0;
    register int temp_s1 PS2_REG("$17");
    int temp_v0;
    int var_s4;
    int var_v0;
    register int temp_s2 PS2_REG("$18");

    var_v0 = Xiii_Eff0__vfunc_02(arg0,arg1);
    if (var_v0 != 0) {
        unsigned short flags = M2C_FIELD(arg0,unsigned short *,0);
        stack.temp.w = 0;
        var_s4 = 0;
        M2C_FIELD(arg0, unsigned short *, 0) = (unsigned short)(flags | 0x10);
        float x = M2C_FIELD(arg1, float *, 0x1C);
        float y = M2C_FIELD(arg1, float *, 0x20);
        float z = M2C_FIELD(arg1, float *, 0x24);
        stack.temp.x=x; stack.temp.y=y; stack.temp.z=z;
        long long lo=*(long long *)&stack.temp;
        long long hi=*((long long *)&stack.temp+1);
        *(long long *)&stack.copy=lo;
        *((long long *)&stack.copy+1)=hi;
        stay02Matrix(arg0 + 0x70, &stack.copy);
        temp_f5 = M2C_FIELD(arg1, float *, 0x10);
        M2C_FIELD(arg0, float *, 0xA0) = temp_f5;
        temp_f4 = M2C_FIELD(arg1, float *, 0x14);
        M2C_FIELD(arg0, float *, 0xA4) = temp_f4;
        register float dx PS2_REG("$f2") = M2C_FIELD(arg0,float *,0x90) * 0.5f;
        register float dy PS2_REG("$f3") = M2C_FIELD(arg0,float *,0x94) * 0.5f;
        register float dz PS2_REG("$f1") = M2C_FIELD(arg0,float *,0x98) * 0.5f;
        float pz = M2C_FIELD(arg1,float *,0x18);
        M2C_FIELD(arg0,float *,0xAC) = 1.0f;
        M2C_FIELD(arg0,float *,0xA0) = temp_f5 + dx;
        M2C_FIELD(arg0,float *,0xA4) = temp_f4 + dy;
        M2C_FIELD(arg0,float *,0xA8) = pz + dz;
        M2C_FIELD(arg0, float *, 0xB0) = (float) M2C_FIELD(arg1, float *, 0x28);
        M2C_FIELD(arg0, int *, 0xB4) = 0;
        M2C_FIELD(arg0, int *, 0xBC) = (int) M2C_FIELD(arg1, int *, 0x2C);
        M2C_FIELD(arg0, float *, 0xB8) = 1.0f;
        temp_v0 = (X_func_0016AD94() % 3U) + 2;
        M2C_FIELD(arg0, int *, 0x64) = temp_v0;
        if (temp_v0 != 0) {
            do {
                temp_s0 = var_s4 * 0x10;
                temp_s1 = temp_s0 + 0x20;
                temp_s2 = arg0 + 4;
                var_s4 += 1;
                *(float *)(temp_s2 + temp_s1) = M2C_FIELD(arg0, float *, 0xB0) * ((((float) X_func_0016AD94() / 255.0f) * 0.8f) - 0.4f);
                M2C_FIELD((temp_s0 + temp_s2), float *, 0x24) = (float) (M2C_FIELD(arg0, float *, 0xB0) * ((((float) X_func_0016AD94() / 255.0f) * 0.8f) - 0.4f));
                M2C_FIELD((arg0 + temp_s1), float *, 0xC) = (float) (((((float) X_func_0016AD94() * 360.0f) / 255.0f) * 3.14159265f) / 180.0f);
            } while (var_s4 < M2C_FIELD(arg0, int *, 0x64));
        }
        var_v0 = 1;
        M2C_FIELD(arg0, float *, 0x24) = M2C_FIELD(arg0, float *, 0x28) = 0.0f;
    }
    return var_v0;
}

extern "C" int EffBloodStay1__vfunc_05(Obj_Stay1_v5 *arg0)
{
    int step = ++arg0->m_B4;
    switch (arg0->m_08 = arg0->m_0C) {
    case 0:
        if (step >= 121) {
            arg0->m_0C = 10;
        }
        break;
    case 10:
        if ((arg0->m_BC >= 0 && step >= arg0->m_BC) || (arg0->m_00 & 2)) {
            arg0->m_0C = 20;
        }
        break;
    case 20:
        arg0->m_B8 -= 0.01f;
        if (arg0->m_B8 <= 0.0f) {
            return 0;
        }
        break;
    }
    return 1;
}

extern "C" float Stay08_distance(int, int) asm("func_0016FF18");
extern "C" int X_func_0016CCB8(...) asm("func_0016CCB8");
extern "C" int X_func_0021B260(...) asm("func_0021B260");
extern "C" int X_func_0021B4F8(...) asm("func_0021B4F8");
extern "C" int Stay08_write(int,int,unsigned long long) asm("func_0021B550");
extern "C" int X_func_0021B5A0(...) asm("func_0021B5A0");
extern "C" int X_func_0021E488(...) asm("func_0021E488");
extern "C" int Stay08_start(int,int,int) asm("func_0021E5A0");
extern "C" int X_func_0021E688(...) asm("func_0021E688");
extern int D_002F20A0;
extern int D_002F20B0;
extern int D_002F20C0;
struct Stay08Words { int w[4]; };
struct Stay08Pair { long long x,y; };
extern "C" void EffBloodStay1__vfunc_08(int arg0, int arg1, int arg2, int arg3)
{
    struct { Stay08Words words; int sp10; float sp14; float sp18; int sp1C; int sp20; int sp24; char pad28[8]; Stay08Words scales; } stack;
    int var_v0;
    int temp_a0;
    int temp_s0;
    int temp_v0;
    int temp_v0_2;
    int var_s1;
    int var_s4;
    int var_s0;
    int temp_a2;

    var_s4 = 0;
    temp_s0 = Stay08_write(X_func_0021B5A0(arg3, M2C_FIELD(arg1, int *, 8)), 0x42, 0x44);
    temp_a0 = Stay08_write(X_func_0021B4F8(temp_s0, X_func_0021B260(arg2, 0)), 0x47, 0x51001);
    int texture = M2C_FIELD(arg1, int *, 8);
    *(Stay08Pair *)&stack.words = *(Stay08Pair *)&D_002F20A0;
    temp_v0 = X_func_0021E488(Stay08_start(temp_a0, texture, 1), (int)&stack);
    temp_a2 = arg0 + 0x24;
    stack.sp10 = temp_a2;
    stack.sp20 = arg1;
    stack.sp24 = temp_v0;
    float distance = Stay08_distance((*(int *)&D_00298E08) + 0x2AB70, arg0 + 0xA0);
    register int count PS2_REG("$4") = M2C_FIELD(arg0, int *, 0x64);
    stack.sp14 = distance;
    stack.words = *(Stay08Words *)&D_002F20B0;
    stack.scales = *(Stay08Words *)&D_002F20C0;
    int age;
    if ((count > 0) && ((int) stack.words.w[0] < (age = M2C_FIELD(arg0, int *, 0xB4)))) {
        var_s0 = (int)&stack;
        var_s1 = 0;
loop_3:
        var_v0 = (int)&stack.scales + var_s1;
        var_s1 += 4;
        var_s4 += 1;
        stack.sp18 = M2C_FIELD(arg0, float *, 0xB0) * (*(float *)(var_v0));
        temp_v0_2 = (*(int *)(var_s0));
        var_s0 += 4;
        stack.sp1C = age - temp_v0_2;
        temp_v0 = X_func_0016CCB8(arg0, (int)&stack.sp10);
        int next = stack.sp10 + 0x10;
        count = M2C_FIELD(arg0, int *, 0x64);
        stack.sp24 = temp_v0;
        stack.sp10 = next;
        if ((count = var_s4 < count)) {
            age = M2C_FIELD(arg0, int *, 0xB4);
            if ((*(int *)(var_s0)) < age) {
                goto loop_3;
            }
        }
    }
    Stay08_write(X_func_0021E688(stack.sp24), 0x47, 0x5000D);
}

// NON_MATCHING: 106/129 differ, 9 relocs differ, 76 edits
#ifdef NON_MATCHING
struct ALIGNED(8) VecCCB8 { float x,y,z,w; };
struct ALIGNED(8) MatCCB8 { long long a,b,c,d,e,f,g,h; };
extern VecCCB8 ccScale asm("D_002F20D0");
extern "C" double ccSin(double) asm("sin");
extern "C" void ccScaleMat(MatCCB8 *, MatCCB8 *, VecCCB8 *) asm("func_00237A40");
extern "C" void ccLight(VecCCB8 *) asm("func_0016AF20");
extern "C" void ccColor(VecCCB8 *, float) asm("func_0016AE00");
extern "C" int ccMatrix(int, MatCCB8 *) asm("func_0021E428");
extern "C" int ccVertex(int, VecCCB8 *, VecCCB8 *) asm("func_0021E690");
extern "C" int func_0016CCB8(int obj, int param)
{
    MatCCB8 matrix;
    VecCCB8 scale;
    VecCCB8 color;
    VecCCB8 temp;
    register float ratio PS2_REG("$f20") = (float)M2C_FIELD(param,int *,12) / 20.0f;
    register float one PS2_REG("$f0") = 1.0f;
    float capped = one;
    if (!(ratio > one)) capped = ratio;
    ratio = capped;
    long long scale0 = *(long long *)&ccScale;
    long long scale1 = *((long long *)&ccScale + 1);
    long long r0 = M2C_FIELD(obj,long long *,0x70);
    long long r2 = M2C_FIELD(obj,long long *,0x80);
    long long r3 = M2C_FIELD(obj,long long *,0x88);
    long long r4 = M2C_FIELD(obj,long long *,0x90);
    long long r6 = M2C_FIELD(obj,long long *,0xA0);
    long long r1 = M2C_FIELD(obj,long long *,0x78);
    long long r7 = M2C_FIELD(obj,long long *,0xA8);
    long long r5 = M2C_FIELD(obj,long long *,0x98);
    matrix.a = r0;
    matrix.b = r1;
    matrix.c = r2;
    matrix.d = r3;
    matrix.e = r4;
    matrix.f = r5;
    matrix.g = r6;
    matrix.h = r7;
    *(long long *)&scale = scale0;
    *((long long *)&scale + 1) = scale1;
    float amount = (float)(ccSin((double)((((ratio * 45.0f) + 45.0f) * 3.14159265f) / 180.0f)) * (double)M2C_FIELD(param,float *,8));
    scale.y = amount;
    scale.x = amount;
    ccScaleMat(&matrix, &matrix, &scale);
    temp.x = 1.0f;
    temp.y = 1.0f;
    temp.z = 1.0f;
    temp.w = 2.0f * (M2C_FIELD(obj,float *,0xB8) * ratio);
    color = temp;
    one = 1.0f;
    float alpha = one;
    if (!(color.w > one)) alpha = color.w;
    color.w = alpha;
    ccLight(&color);
    ccColor(&color, M2C_FIELD(param,float *,4));
    float *pos = M2C_FIELD(param,float **,0);
    VecCCB8 *translation = (VecCCB8 *)((char *)&matrix + 0x30);
    translation->x += pos[0];
    translation->y += -2.0f;
    translation->z += pos[1];
    int packet = ccMatrix(M2C_FIELD(param,int *,0x14), &matrix);
    M2C_FIELD(param,int *,0x14) = packet;
    return ccVertex(packet,translation,&color);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016CCB8);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016CEBC);

extern "C" int X_Eff0__vfunc_02_Stay2(Obj_Stay2 *, Arg_Stay2 *) asm("Eff0__vfunc_02");
extern "C" int EffBloodStay2__vfunc_02(Obj_Stay2 *arg0, Arg_Stay2 *arg1)
{
  float new_var;
  if (!X_Eff0__vfunc_02_Stay2(arg0, arg1))
  {
    return 0;
  }
  float *v = arg1->m_10;
  float z = 0.0f;
  float one = 1.0f;
  arg0->m_4B0 = v;
  arg0->m_4B4 = arg1->m_14;
  arg0->m_4B8 = arg1->m_18;
  arg0->m_4BC = arg1->m_1C / 31.0f;
  arg0->m_4C4 = z;
  arg0->m_4C0 = z;
  arg0->m_4D0[0] = v[0];
  arg0->m_4D0[1] = (new_var = v[1]);
  float vz = v[2];
  arg0->m_4D0[3] = one;
  arg0->m_4E0[1] = (arg0->m_4E0[2] = (arg0->m_4E0[3] = z));
  arg0->m_4D0[2] = vz;
  arg0->m_4E0[0] = z;
  arg0->m_4C8 = 0;
  return 1;
}

// NON_MATCHING: 106/196 differ, 5 relocs differ (size 0x310, game 0x314), 19 edits
#ifdef NON_MATCHING
struct ALIGNED(8) S205Vec { float x,y,z,w; };
extern "C" void s205Sub(S205Vec *,S205Vec *,S205Vec *) asm("func_00237408");
extern "C" float s205Len(S205Vec *) asm("func_0016FC20");
extern "C" void s205Norm(S205Vec *,S205Vec *) asm("func_002375D8");
extern "C" float s205Dot(S205Vec *,S205Vec *) asm("func_00237580");
extern "C" double s205Cos(double) asm("cos");
extern "C" void s205Add(void *,S205Vec *,S205Vec *,S205Vec *) asm("func_0016D3E4");
extern "C" int EffBloodStay2__vfunc_05(char *obj) {
    struct { S205Vec pos, vel, delta, dir; } stack;
#define pos stack.pos
#define vel stack.vel
#define delta stack.delta
#define dir stack.dir
    int again;
    if ((M2C_FIELD(obj,int *,8)=M2C_FIELD(obj,int *,12)) == -1) return 1;
    {
        float *p=M2C_FIELD(obj,float **,0x4B0);
        float *v=M2C_FIELD(obj,float **,0x4B4);
        vel.x=p[0]; vel.y=p[1]; vel.z=p[2]; vel.w=1.0f;
        pos=vel;
        delta.x=v[0]; delta.y=v[1]; delta.z=v[2]; delta.w=0.0f;
        vel=delta;
        do {
            S205Vec *prev=(S205Vec *)(obj+0x4D0);
            again=0;
            s205Sub(&delta,&pos,prev);
            float len=s205Len(&delta);
            if (len>0.0f) s205Norm(&dir,&delta);
            else dir=*(S205Vec *)(obj+0x4E0);
            switch (M2C_FIELD(obj,int *,8)=M2C_FIELD(obj,int *,12)) {
            case 0:
                if (len>0.0f) {
                    s205Add(obj,prev,&vel,&dir);
                    again=1;
                    M2C_FIELD(obj+M2C_FIELD(obj,int *,0x4C8)*4,float *,0x430)=0.0f;
                    long long lo=*(long long *)&dir;
                    long long hi=*((long long *)&dir+1);
                    M2C_FIELD(obj,long long *,0x4E0)=lo;
                    M2C_FIELD(obj,long long *,0x4E8)=hi;
                    M2C_FIELD(obj,int *,12)=10;
                    M2C_FIELD(obj,int *,0x4C8)++;
                }
                break;
            case 10:
                s205Add(obj,&pos,&vel,&dir);
                char *entry=M2C_FIELD(obj,int *,0x4C8)*4+obj;
                M2C_FIELD(entry,float *,0x430)=M2C_FIELD(entry,float *,0x42C)+len/(M2C_FIELD(obj,float *,0x4B8)*3.0f);
                M2C_FIELD(obj,float *,0x4C0)=M2C_FIELD(obj,float *,0x4C4)+len;
                if (M2C_FIELD(obj,float *,0x4BC)<=len) {
                    again=1;
                    M2C_FIELD(obj,int *,0x4C8)++;
                    *(S205Vec *)(obj+0x4D0)=pos;
                    *(S205Vec *)(obj+0x4E0)=dir;
                    M2C_FIELD(obj,float *,0x4C4)=M2C_FIELD(obj,float *,0x4C0);
                } else if ((double)s205Dot(&dir,(S205Vec *)(obj+0x4E0)) < s205Cos((double)(((90.0f-len*90.0f/M2C_FIELD(obj,float *,0x4BC))*3.14159265f)/180.0f))) {
                    again=1;
                    M2C_FIELD(obj,int *,0x4C8)++;
                    *(S205Vec *)(obj+0x4D0)=pos;
                    *(S205Vec *)(obj+0x4E0)=dir;
                    M2C_FIELD(obj,float *,0x4C4)=M2C_FIELD(obj,float *,0x4C0);
                }
                if (M2C_FIELD(obj,int *,0x4C8)>=32) {
                    M2C_FIELD(obj,int *,0x4C8)=31; again=0; M2C_FIELD(obj,int *,12)=-1;
                }
                break;
            }
        } while(again);
    }
    return 1;
}

#undef pos
#undef vel
#undef delta
#undef dir
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay2__vfunc_05);
#endif

extern "C" void func_0016D3E4(Obj_Stay2_D3E4 *arg0, EffVec4 *arg1, EffVec4 *arg2, EffVec4 *arg3)
{
    EffVec4 side;
    func_00237560(&side, arg2, arg3);
    func_002375D8(&side, &side);
    EffStay2Pair *pair = &arg0->m_30[arg0->m_4C8];
    EffVec4 *b = &pair->b;
    EffVec4 *a = &pair->a;
    b->w = 1.0f;
    a->w = 1.0f;
    func_00237360(a, &side, arg0->m_4B8 * 0.5f);
    func_002373D8(a, a, arg1);
    func_00237360(b, &side, -arg0->m_4B8 * 0.5f);
    func_002373D8(b, b, arg1);
}

// NON_MATCHING: 145/203 differ, 2 relocs differ (size 0x32C, game 0x348), 114 edits
#ifdef NON_MATCHING
struct ALIGNED(8) S208Vec { float x,y,z,w; };
struct ALIGNED(8) S208Quad { S208Vec v[4]; };
struct ALIGNED(8) S208Pair { S208Vec a,b; };
extern S208Quad s208Colors asm("D_002F20F0");
extern S208Quad s208UV asm("D_002F2130");
extern "C" int s208Write(int,int,unsigned long long) asm("func_0021B550");
extern "C" int s208Texture(int,int) asm("func_0021B5A0");
extern "C" int s208State(int,int) asm("func_0021B260");
extern "C" int s208Join(int,int) asm("func_0021B4F8");
extern "C" int s208Setup(int,int) asm("func_0021B5D0");
extern "C" void s208Identity(void *) asm("func_00237340");
extern "C" void *s208Zero(void *,int,unsigned int) asm("memset");
extern "C" float s208Mod(float,float *) asm("modff");
extern "C" int s208Draw(int,void *,int,void *,void *,void *,int) asm("func_0021DB40");
extern "C" int EffBloodStay2__vfunc_08(char *obj,int render,int state,int packet) {
    struct { long long matrix[8]; S208Quad positions,colors,uv; float integral; } stack;
#define matrix stack.matrix
#define positions stack.positions
#define colors stack.colors
#define uv stack.uv
#define integral stack.integral
    if (M2C_FIELD(obj,int *,0x4C8)>0) {
        int index=1;
        packet=s208Texture(s208Write(s208Write(packet,0x4E,0x13A0000E0ULL),0x42,0x44),M2C_FIELD(render,int *,8));
        packet=s208Setup(s208Join(packet,s208State(state,0)),M2C_FIELD(render,int *,8));
        s208Identity(matrix);
        float *velocity=M2C_FIELD(obj,float **,0x4B4);
        ((float *)matrix)[12]=velocity[0]*0.5f;
        ((float *)matrix)[13]=velocity[1]*0.5f;
        ((float *)matrix)[14]=velocity[2]*0.5f;
        s208Zero(&positions,0,64);
        positions.v[3].w=1.0f;
        colors=s208Colors; uv=s208UV;
        positions.v[0].w=1.0f; positions.v[1].w=1.0f; positions.v[2].w=1.0f;
        int count=M2C_FIELD(obj,int *,0x4C8);
        positions.v[2]=*(S208Vec *)(obj+0x30); positions.v[3]=*(S208Vec *)(obj+0x40);
        char *next=obj+0x50;
        if(count>0) {
            float *length=(float *)(obj+0x430);
            do {
                positions.v[0]=positions.v[2]; positions.v[1]=positions.v[3];
                positions.v[2]=*(S208Vec *)next; next+=16;
                positions.v[3]=*(S208Vec *)next; next+=16;
                s208Mod(length[0],&integral);
                float end=length[1];
                float start=length[0]; length++;
                float u0=start-integral, u1=end-integral;
                uv.v[0].y=u0; uv.v[1].y=u0; uv.v[2].y=u1; uv.v[3].y=u1;
                colors.v[0].w=colors.v[2].w;
                colors.v[1].w=colors.v[2].w;
                if(index==count) { colors.v[2].w=0.0f; colors.v[3].w=0.0f; }
                else {
                    float width=M2C_FIELD(obj,float *,0x4B8);
                    float fade=(M2C_FIELD(obj,float *,0x4C0)-width*3.0f*end)/width;
                    float capped=1.0f;
                    if(!(fade>1.0f)) capped=fade;
                    float alpha;
                    if(capped>1.0f) alpha=127.0f; else alpha=capped*127.0f;
                    colors.v[3].w=alpha; colors.v[2].w=alpha;
                }
                index++;
                packet=s208Draw(packet,matrix,4,&uv,&colors,&positions,0);
            } while(count>=index);
        }
    }
    return packet;
}

#undef matrix
#undef positions
#undef colors
#undef uv
#undef integral
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay2__vfunc_08);
#endif

extern "C" char vtbl_13EffBloodStay3[] asm("_vt$13EffBloodStay3");
extern int D_00298E10;
extern "C" void dtor_13EffBloodStay3(Eff0 *, int) asm("_$_13EffBloodStay3");

extern "C" void dtor_13EffBloodStay3(Eff0 *arg0, int arg1)
{
    arg0->m_vtbl = vtbl_13EffBloodStay3;
    D_00298E10 = -1;
    dtor_4Eff0(arg0, 0);
    if (arg1 & 1) {
        return X___builtin_delete(arg0);
    }
}

extern "C" int EffBloodStay3__vfunc_02(int arg0, int arg1)
{
    if (Xiii_Eff0__vfunc_02(arg0, arg1) == 0) {
        return 0;
    }
    Xiiii_memset(arg0 + 0x24, 0, 8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBloodStay3__vfunc_05);

extern "C" int func_0016D8E8(int arg0, int arg1)
{
    Param_D8E8 param;
    if (D_00298E10 == -1) {
        param.m_kind = 5;
        param.m_unk08 = 0;
        D_00298E10 = func_00176CC8(&((Scene_D8E8 *)D_00298E08)->m_effMgr, &param);
        if (D_00298E10 == -1) {
            return 0;
        }
    }
    EffMgr_D8E8 *mgr = &((Scene_D8E8 *)D_00298E08)->m_effMgr;
    mgr->m_04[D_00298E10]->m_24[arg0] = arg1;
    return 1;
}

extern "C" int EffBloodStay3Prim__vfunc_02(int arg0, int arg1)
{
    int temp_v1;

    if (Xiii_Eff0__vfunc_02(arg0, arg1) == 0) {
        return 0;
    }
    M2C_FIELD(arg0, int *, 0x24) = (int) M2C_FIELD(arg1, int *, 0x10);
    M2C_FIELD(arg0, int *, 0x28) = (int) M2C_FIELD(arg1, int *, 0x14);
    temp_v1 = M2C_FIELD(arg1, int *, 0x18);
    *(m2c_block12 *)((char *)(arg0) + 48) = *(m2c_block12 *)((char *)(temp_v1) + 0);
    M2C_FIELD(arg0, float *, 0x3C) = 1.0f;
    M2C_FIELD(arg0, float *, 0x40) = (float) M2C_FIELD(arg1, float *, 0x1C);
    M2C_FIELD(arg0, float *, 0x44) = (float) M2C_FIELD(arg1, float *, 0x20);
    M2C_FIELD(arg0, int *, 0x48) = 0;
    return 1;
}

extern "C" int EffBloodStay3Prim__vfunc_05(int arg0)
{
    int temp_v0;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x48)) + 1;
    (*(int *)(int *)((char *)(arg0) + 0x48)) = temp_v0;
    return temp_v0 < 0xA5;
}


struct ALIGNED(8) Prim08Vec { float x,y,z,w; };
struct Prim08Pair { long long a,b; };
extern "C" int prim08Write(int,int,unsigned long long) asm("func_0021B550");
extern "C" int prim08Texture(int,int) asm("func_0021B5A0");
extern "C" int prim08State(int,int) asm("func_0021B260");
extern "C" int prim08Join(int,int) asm("func_0021B4F8");
extern "C" int prim08Start(int,int,int) asm("func_0021E5A0");
extern "C" int prim08UV(int,Prim08Vec *) asm("func_0021E488");
extern "C" void prim08Light(Prim08Vec *) asm("func_0016AF20");
extern "C" void prim08Clear(void *,int,unsigned int) asm("memset");
extern "C" void prim08Matrix(void *,Prim08Vec *) asm("func_0016FDA0");
extern "C" void prim08Rotate(void *,void *,float) asm("func_00237830");
extern "C" void prim08Scale(void *,void *,Prim08Vec *) asm("func_00237A40");
extern "C" int prim08Packet(int,void *) asm("func_0021E428");
extern "C" int prim08Vertex(int,void *,Prim08Vec *) asm("func_0021E690");
extern "C" void prim08End(int) asm("func_0021E688");
extern "C" void EffBloodStay3Prim__vfunc_08(int obj, int render, int state, int packet)
{
  Prim08Vec uv;
  Prim08Vec color;
  Prim08Vec *new_var;
  Prim08Vec temp;
  long long matrix[8];
  float size = 0.0f;
  int cmd = prim08Texture(prim08Write(packet, 0x42, 0x44), *((int *) (((char *) render) + 8)));
  cmd = prim08Start(prim08Join(cmd, prim08State(state, 0)), *((int *) (((char *) render) + 8)), 1);
  switch (*((int *) (((char *) obj) + 0x24)))
  {
    case 0:
      if ((*((int *) (((char *) obj) + 0x28))) == 0)
    {
      uv.x = 0.0f;
      uv.z = 0.5f;
    }
    else
    {
      uv.x = 0.5f;
      uv.z = -0.5f;
    }
      uv.y = 0.0f;
      uv.w = 1.0f;
      size = 1.0f;
      break;

    case 1:
      if (!((*((int *) (((char *) obj) + 0x28))) & 2))
    {
      uv.x = 0.5f;
      uv.z = 0.5f;
    }
    else
    {
      uv.x = 1.0f;
      uv.z = -0.5f;
    }
      uv.y = 0.0f;
      uv.w = 1.0f;
      size = 1.0f;
      break;

  }

  cmd = prim08UV(cmd, &uv);
  temp.w = *((float *) (((char *) obj) + 0x44));
  temp.x = 1.0f;
  temp.y = 1.0f;
  new_var = &color;
  temp.z = 1.0f;
  color = temp;
  prim08Light(new_var);
  int age = *((int *) (((char *) obj) + 0x48));
  register float fade PS2_REG("$f0");
  register float alpha PS2_REG("$f1");
  register float denominator PS2_REG("$f2");
  if (age < 15)
  {
    fade = (float) age;
    denominator = 15.0f;
    fade /= denominator;
    alpha = color.w;
    goto fadeAlpha;
  }
  if (age >= 135)
  {
    denominator = 30.0f;
    fade = (float) (age - 135);
    alpha = color.w;
    fade = 1.0f - (fade / denominator);
    fadeAlpha:
    alpha *= fade;

    if (age || obj)
    {
      color.w = alpha;
    }
    else
    {
      color.w = alpha;
    }
  }
  prim08Clear(&temp, 0, 16);
  temp.y = -1.0f;
  prim08Matrix(matrix, &temp);
  prim08Rotate(matrix, matrix, *((float *) (((char *) obj) + 0x40)));
  temp.y = size;
  temp.x = size;
  temp.w = 1.0f;
  temp.z = 1.0f;
  prim08Scale(matrix, matrix, &temp);
  prim08End(prim08Vertex(prim08Packet(cmd, matrix), (void *) (obj + 0x30), new_var));
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1__vfunc_02);

extern "C" int EffBreath1__vfunc_05(EffBreath1 *arg0)
{
    func_0016E438((char *)arg0);
    int t = (arg0->m_unk70 + 1) % 70;
    arg0->m_unk70 = t;
    if (t == 0) {
        if (func_0016E65C((Obj_E65C *)arg0) != 0) {
            arg0->m_unk188 = 0.06f;
            arg0->m_unk18C = 8.0f;
            arg0->m_unk184 = 0.0f;
            arg0->m_unk190 = 0.0f;
        } else {
            arg0->m_unk70 = 0x37;
            arg0->m_unk188 = 0.0f;
            arg0->m_unk18C = 0.0f;
            arg0->m_unk190 = 0.0f;
            arg0->m_unk184 = 0.0f;
        }
    } else {
        float f = arg0->m_unk184 + arg0->m_unk188;
        arg0->m_unk184 = f;
        if (f >= 1.0f) {
            arg0->m_unk184 = 1.0f;
            arg0->m_unk188 = -0.015f;
        }
        float g = arg0->m_unk190 + 0.015f;
        arg0->m_unk190 = g;
        arg0->m_unk18C += g;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1__vfunc_08);

extern "C" void updateZDepth__10EffBreath1(int arg0)
{
    M2C_FIELD(arg0, float *, 0x10) = Xii_func_0016FF18(D_00298E08 + 0x2AB70,
        arg0 + (M2C_FIELD(arg0, int *, 0x180) << 5) + 0x80);
}

// NON_MATCHING: 22/136 differ, 2 relocs differ (size 0x220, game 0x224), 4 edits
#ifdef NON_MATCHING
struct ALIGNED(8) E438Vec { float x,y,z,w; };
struct E438Model {
    char pad[0x94];
    virtual void X__vfunc_00();
    virtual void X__vfunc_01();
    virtual void X__vfunc_02();
    virtual void X__vfunc_03();
    virtual void X__vfunc_04();
    virtual void X__vfunc_05();
    virtual int X__vfunc_06(int);
}; // E438 model
extern "C" void e438Matrix(void *, E438Model *, int) asm("func_002377D0");
extern "C" void e438Transform(E438Vec *, void *, void *) asm("func_002373A8");
extern "C" void e438Sub(E438Vec *, E438Vec *, E438Vec *) asm("func_00237408");
extern "C" float e438Length(E438Vec *) asm("func_0016FC20");
static inline double e438Abs(double x) { if (x < 0.0) x = 0.0 - x; return x; }
extern "C" void func_0016E438(char *obj)
{
    E438Vec pos;
    long long matrix[8];
    int node = M2C_FIELD(obj,E438Model **,0x50)->X__vfunc_06(M2C_FIELD(obj,int *,0x54));
    E438Model *model = M2C_FIELD(obj,E438Model **,0x50);
    model->X__vfunc_01();
    e438Matrix(matrix, model, node);
    e438Transform(&pos, matrix, (void *)(obj + 0x60));
    int index = M2C_FIELD(obj,int *,0x180);
    register int previousOffset PS2_REG("$2") = (index << 5) + 0x80;
    E438Vec *previous = (E438Vec *)(obj + previousOffset);
    if (e438Abs((double)(pos.x - previous->x)) < 3.0) {
        if (e438Abs((double)(pos.z - previous->z)) < 3.0) {
            float y = previous->y;
            if (e438Abs((double)(pos.y - y)) < 5.0) pos.y = y;
        }
    }
    register int increment PS2_REG("$5") = index + 1;
    int next = increment % 8;
    register int offset PS2_REG("$16") = next * 32;
    long long low = *(long long *)&pos;
    long long high = *((long long *)&pos + 1);
    register int target PS2_REG("$2") = (int)(offset + obj);
    offset = (int)((unsigned int)offset + (unsigned int)obj);
    long long *dest = (long long *)(target + 0x80);
    dest[1] = high;
    dest[0] = low;
    e438Sub(&pos,&pos,(E438Vec *)(obj + M2C_FIELD(obj,int *,0x180) * 32 + 0x80));
    M2C_FIELD(offset,float *,0x90) = e438Length(&pos);
    M2C_FIELD(obj,int *,0x180) = next;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E438);
#endif

extern "C" int func_0016E65C(Obj_E65C *arg0)
{
    float p[3];
    Sub50_E65C *sub = arg0->sub;
    p[0] = sub->pos.x;
    p[1] = sub->pos.y;
    p[2] = sub->pos.z;
    if (arg0->minX <= p[0] && p[0] <= arg0->maxX &&
        arg0->minZ <= p[2] && p[2] <= arg0->maxZ &&
        arg0->minY <= p[1] && p[1] <= arg0->maxY) {
        return 1;
    }
    return 0;
}

extern "C" int EffBreath1Space__vfunc_02(EffBreath1Space_02 *arg0, EffBreath1SpaceArg *arg1)
{
    if (!Eff0__vfunc_02(arg0, arg1)) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (arg1->m_p0[i] <= arg1->m_p1[i]) {
            arg0->m_min[i] = arg1->m_p0[i];
            arg0->m_max[i] = arg1->m_p1[i];
        } else {
            arg0->m_min[i] = arg1->m_p1[i];
            arg0->m_max[i] = arg1->m_p0[i];
        }
    }
    arg0->m_unk3C = arg1->m_unk28;
    arg0->m_unk40 = arg1->m_unk2C;
    arg0->m_unk250 = 0;
    memset(arg0->m_unk50, -1, sizeof(arg0->m_unk50));
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1F90);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1FA0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F1FF0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2000);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2010);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2020);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2068);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2080);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20A0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20B0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20C0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20D0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20E0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F20F0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2130);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2170);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2180);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2190);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21A0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21C0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21D0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21E0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F21F0);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2200);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2210);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2230);

INCLUDE_RODATA("asm/nonmatchings/unk/Eff0", D_002F2240);

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", EffBreath1Space__vfunc_05);

// NON_MATCHING: 3/50 differ, 5 edits
#ifdef NON_MATCHING
struct EffBreath1Param {
    int m_kind;                         // +0x00
    int m_unk04;                        // +0x04
    int m_unk08;                        // +0x08
    int m_unk0C;                        // +0x0C
    EffVec3 m_unk10;                    // +0x10
    EffVec3 m_unk1C;                    // +0x1C
    float m_unk28;                      // +0x28
    EffVec4 m_unk2C;                    // +0x2C
    void *m_unk3C;                      // +0x3C
    unsigned char m_pad40[0x40];        // +0x40
};

struct EffBreath1Space : public Eff0 {
    EffVec3 m_unk24;                    // +0x24
    EffVec3 m_unk30;                    // +0x30
    float m_unk3C;                      // +0x3C
    EffVec4 m_unk40;                    // +0x40
    int m_unk50[1];                     // +0x50
};

struct SceneUnk2920 {
    unsigned char m_pad00[0x4D0];       // +0x000
};

struct Scene_E92C {
    unsigned char m_pad00[0x2920];      // +0x0000
    SceneUnk2920 m_unk2920[1];          // +0x2920
    unsigned char m_pad2DF0[0x837E0 - 0x2DF0];
    int m_effMgr;                       // +0x837E0
};

extern "C" void func_0016E92C(EffBreath1Space *arg0, int arg1)
{
    EffBreath1Param param;
    Scene_E92C *scene = (Scene_E92C *)D_00298E08;
    param.m_kind = 8;
    param.m_unk28 = arg0->m_unk3C;
    param.m_unk3C = &scene->m_unk2920[arg1];
    param.m_unk08 = 0;
    param.m_unk10 = arg0->m_unk24;
    param.m_unk1C = arg0->m_unk30;
    param.m_unk2C = arg0->m_unk40;
    int *slot = arg0->m_unk50 + arg1;
    *slot = func_00176CC8(&scene->m_effMgr, &param);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E92C);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/Eff0", func_0016E9F4);
