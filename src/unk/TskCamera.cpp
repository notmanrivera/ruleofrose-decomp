#include "include_asm.h"
#include "task/cmnitask.h"

struct TskCameraParam0 {
    int m_unk00;                        // +0x00
    float m_pos[3];                     // +0x04..+0x0F
    float m_target[3];                  // +0x10..+0x1B
    float m_up[3];                      // +0x1C..+0x27
    float m_unk28;                      // +0x28
};

class TskCamera : public CmnITask {
public:
    int (TskCamera::*m_func)();         // +0x04 (8 bytes)
    int m_unk0C;                        // +0x0C
    float m_unk10;                      // +0x10
    int m_mode;                         // +0x14
    int m_pad18[2];                     // +0x18..+0x1F
    TskVec4 m_vec20;                    // +0x20
    TskVec4 m_vec30;                    // +0x30
    TskVec4 m_vec40;                    // +0x40
    float m_unk50;                      // +0x50
    float m_unk54[7];                   // +0x54..+0x6F
    TskVec4 m_vec70;                    // +0x70
    TskVec4 m_vec80;                    // +0x80

    virtual int get_task_type() { return 0xF; }
    virtual void init() {}
    virtual int exec(int, int, void *);
    virtual void term() {}
    virtual ~TskCamera() {}
};

extern int (TskCamera::*D_002FEFB0)();

extern "C" char vtbl_9TskCamera[] asm("_vt$9TskCamera");
extern "C" void func_001FBC6C(TskCamera *, void *);
extern "C" void func_001FBD2C(TskCamera *, void *);
extern "C" int func_001FC210(TskCamera *);
extern "C" int func_001FC46C();
extern "C" int Xiii_func_00218470(int, int, int) asm("func_00218470");
extern "C" int Xiii_getInfo__9BedMemoryP13BedMemoryInfoi(int, int, int) asm("getInfo__9BedMemoryP13BedMemoryInfoi");
extern int D_006E9800;

extern "C" int func_001FBBA4()
{
    int info[4];

    Xiii_getInfo__9BedMemoryP13BedMemoryInfoi((int)&D_006E9800, (int)info, 0);
    return info[0];
}

extern "C" void func_001FBBD0()
{
    static const char msg[0x30] = "free mem   max/total/size   = %d/%d \n";
    int info[4];

    Xiii_getInfo__9BedMemoryP13BedMemoryInfoi((int)&D_006E9800, (int)info, 0);
    Xiii_func_00218470((int)msg, info[0], info[1]);
}

extern "C" int func_001FBC0C(TskCamera *self, int mode, void *param)
{
    *(void **)self = vtbl_9TskCamera;
    self->m_mode = mode;
    switch (mode) {
    case 0:
        func_001FBC6C(self, param);
        break;
    case 1:
        func_001FBD2C(self, param);
        break;
    }
}

extern "C" void func_001FBC6C(TskCamera *self, void *arg1)
{
    TskCameraParam0 *param = (TskCameraParam0 *)arg1;

    self->m_unk0C = 0;
    self->m_func = D_002FEFB0;
    self->m_vec20.f[0] = param->m_pos[0];
    self->m_vec20.f[1] = param->m_pos[1];
    self->m_vec20.f[2] = param->m_pos[2];
    self->m_vec20.f[3] = 0.0f;
    self->m_vec30.f[0] = param->m_target[0];
    self->m_vec30.f[1] = param->m_target[1];
    self->m_vec30.f[2] = param->m_target[2];
    self->m_vec30.f[3] = 0.0f;
    self->m_vec40.f[0] = param->m_up[0];
    self->m_vec40.f[1] = param->m_up[1];
    self->m_vec40.f[2] = param->m_up[2];
    self->m_vec40.f[3] = 0.0f;
    self->m_unk10 = param->m_unk28;
    self->m_vec70.f[0] = self->m_vec70.f[1] = self->m_vec70.f[2] = self->m_vec70.f[3] = 0.0f;
    self->m_vec80.f[0] = self->m_vec80.f[1] = self->m_vec80.f[2] = self->m_vec80.f[3] = 0.0f;
    self->m_unk50 = self->m_unk54[0] = self->m_unk54[1] = self->m_unk54[2] = self->m_unk54[3] = self->m_unk54[4] = self->m_unk54[5] = self->m_unk54[6] = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FBD2C);

extern "C" void TskCamera__vfunc_03(void) {
}

extern "C" void TskCamera__vfunc_05(void) {
}

extern "C" int TskCamera__vfunc_04(TskCamera *self)
{
    switch (self->m_mode) {
    case 0:
        return func_001FC210(self);
    case 1:
        return func_001FC46C();
    }
    return (self->*(self->m_func))();
}

INCLUDE_ASM("asm/nonmatchings/unk/TskCamera", func_001FC210);

extern "C" int func_001FC46C()
{
    return 0;
}

extern "C" int func_001FC474()
{
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFB0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFC0);

INCLUDE_RODATA("asm/nonmatchings/unk/TskCamera", D_002FEFD0);
