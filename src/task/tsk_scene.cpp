#include "include_asm.h"
#include "task/cmnitask.h"
#include "task/tsk_scene.h"
#include "sdk/string.h"
#include "game/gamman.h"
#include "game/gamsnd.h"
#include "mag/magsystem.h"
#include "bed/bedmemory.h"
#include "utl/filereader.h"
#include "dog/dogactor.h"
#include "mag/magscene.h"
#include "sdk/libvu0.h"
extern "C" float func_00133440(MagScene *, int);
struct SceneGameState {
    unsigned char m_pad00[0x7C];
    int m_unk7C;
};
extern BedMemory D_006E9800;
extern SceneGameState *D_007B205C;
extern const char D_002FE858[];
extern "C" int snprintf(char *, size_t, const char *, ...);
extern "C" int func_001BE768(const char *);
extern "C" void func_001417E4(MagScene *, void *, int);
void heapFree(void *);
extern MagSystem D_006E9840;
extern MagScene D_006FBD80;
extern "C" void func_001F723C(void *);
extern "C" void func_001FBBD0(void);
extern "C" void func_00139010(MagScene *, int);
extern "C" void func_0017756C(void *, int);
extern "C" void func_001F6DFC(void *, int, int);
static inline MagScene *getMagScene(MagSystem *s) { return &s->m_scene; }
static inline void *getEffMan(MagScene *s) { return s->m_unk837E0; }
extern "C" void *__builtin_new(size_t);
extern "C" void func_001F764C(ScenePlaySingle *, int, ScenePlayCmd *);
static inline ScenePlaySingle *make_single(int arg1, ScenePlayCmd *arg2)
{
    ScenePlaySingle *p = (ScenePlaySingle *)__builtin_new(0xC0);
    func_001F764C(p, arg1, arg2);
    return p;
}
extern "C" int func_001F7788(ScenePlaySingle *, int);
static inline GamSndMan *getSnd(GamMan *g) { return (GamSndMan *)g->m_snd; }
extern "C" void func_001F6CB8(void *);
extern "C" void func_001F71B8(void *);
extern "C" void ScenePlay__vfunc_05(ScenePlay *);
extern "C" void VoiceManager__vfunc_01(void *, int);
extern "C" void SeManager__vfunc_01(void *, int);
extern "C" void DisplayMessage__vfunc_01(void *, int);
extern "C" void __builtin_delete(void *);
extern "C" void ScenePlay__vfunc_03(ScenePlay *);
extern "C" void func_001F6C64(void *);
extern "C" void func_001F6EDC(void *);
extern "C" void func_001F73D4(void *);
extern void *_vt$9ScenePlay[];
extern "C" int func_00279C98(char *, const char *, ...);
extern "C" char *strncpy(char *, const char *, size_t);
extern "C" char vtbl_15ScenePlaySingle[] asm("_vt$15ScenePlaySingle");
extern "C" char vtbl_11PLScenePlay[] asm("_vt$11PLScenePlay");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" void ScenePlaySingle__vfunc_01(int arg0, int arg1);
extern "C" void PLScenePlay__vfunc_06(int arg0, int arg1);
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_func_001F7644(...) asm("func_001F7644");
extern "C" int X_func_001F76E0(...) asm("func_001F76E0");
extern "C" int X_func_001F7C0C(...) asm("func_001F7C0C");

extern "C" void func_001F7570(SceneVoice *self, int id, int vol, int pan, int arg4)
{
    self->m_unk08 = arg4;
    self->m_unk04 = 0;
    self->m_unk00 = id;
    int left = (pan >= 0) ? ((0x3F - pan) * vol) / 64 : vol;
    int right = (pan > 0) ? vol : ((pan + 0x3F) * vol) / 64;
    func_001E5428(getSnd(&D_007812C0), id, left, right, 0, 1, 0, 1.0f);
}

extern "C" void func_001F7610(int arg0)
{
    int temp_v0;
    int temp_v1;

    temp_v0 = (*(int *)(int *)((char *)(arg0) + 0x8));
    temp_v1 = temp_v0 - 1;
    if (temp_v0 != 0) {
        (*(int *)(int *)((char *)(arg0) + 0x8)) = temp_v1;
        if (temp_v1 == 0) {
            X_func_001F7644(arg0);
        }
    }
}


extern "C" void func_001F7644(void) {
}

extern "C" void func_001F764C(ScenePlaySingle *self, int arg1, ScenePlayCmd *arg2)
{
    *(void **)&self->m_pad1C[0x80] = vtbl_15ScenePlaySingle;
    self->m_unk04 = 1;
    self->m_unk00 = arg2;
    self->m_unk08 = arg1;
    self->m_unk0C = -1;
    self->m_unk10 = 0;
    self->m_oid = -1;
}

extern "C" void ScenePlaySingle__vfunc_01(int arg0, int arg1)
{
    M2C_FIELD(arg0, void **, 0x9c) = vtbl_15ScenePlaySingle;
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

extern "C" int func_001F76B0(int arg0)
{
    X_func_001F76E0();
    X_func_001F7C0C(arg0);
    return 0;
}


extern "C" int func_001F76E0(ScenePlaySingle *self)
{
    if (self->m_unk04 == 0) {
        return 0;
    }
    self->m_unk0C++;
    ScenePlayCmd *cmd = &self->m_unk00[self->m_unk10];
    if (cmd->m_unk04 == 0) {
        return 0;
    }
    int next;
    do {
        next = 0;
        ScenePlayCmd *cur = &self->m_unk00[self->m_unk10];
        if (self->m_unk0C >= cur->m_unk00) {
            next = func_001F7788(self, 0);
        }
    } while (next != 0);
    return self->m_unk04 != 0;
}

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F7788);

extern "C" void func_001F7C0C(ScenePlaySingle *self)
{
    DogActor *actor = D_006FBD80.getActor(self->m_unk08);
    float turn = 0.0f;
    DogVector move;
    move.m_y = move.m_z = 0.0f;
    DogVector abs;
    float t = actor->func_0010DA80();
    actor->func_00109348(t, t + 2.0f * (func_00133440(&D_006FBD80, self->m_unk08) * 60.0f), move, &turn, &abs);
    float ry = actor->m_base_rot.m_y;
    move.m_y = 0.0f;
    move.m_w = 1.0f;
    float rot = abs.m_y;
    sceVu0FMATRIX mat;
    sceVu0UnitMatrix(mat);
    sceVu0RotMatrixY(mat, mat, ry);
    sceVu0ApplyMatrix(&move.m_x, mat, &move.m_x);
    actor->func_0010A038(move, rot, turn);
}

extern "C" void func_001F7D54(ScenePlay *self, int arg1)
{
    self->m_vtable = _vt$9ScenePlay;
    func_001F6C64(self->m_displayMessage);
    func_001F6EDC(self->m_seManager);
    func_001F73D4(self->m_voiceManager);
    ScenePlay__vfunc_03(self);
    self->m_unk3C = arg1;
    self->m_unk30 = 0;
    self->m_camera_eff_id = -1;
    self->m_imd_load_chr_num = 0;
    self->m_unk44 = 0;
    self->m_unk88 = 0;
}

extern "C" void ScenePlay__vfunc_06(ScenePlay *self, int flags)
{
    self->m_vtable = _vt$9ScenePlay;
    ScenePlay__vfunc_05(self);
    VoiceManager__vfunc_01(self->m_voiceManager, 2);
    SeManager__vfunc_01(self->m_seManager, 2);
    DisplayMessage__vfunc_01(self->m_displayMessage, 2);
    if (flags & 1) {
        return __builtin_delete(self);
    }
}

extern "C" void ScenePlay__vfunc_03(ScenePlay *) {
}

extern "C" void ScenePlay__vfunc_05(ScenePlay *self)
{
    func_001F723C(self->m_seManager);
    func_001FBBD0();
    for (int i = 0; i < self->m_imd_load_chr_num; i++) {
        func_00139010(getMagScene(&D_006E9840), self->m_imd_load_chr_id[i]);
    }
    self->m_imd_load_chr_num = 0;
    for (int i = 0; i < self->m_unk30; i++) {
        delete self->m_unk04[i];
    }
    self->m_unk30 = 0;
    if (self->m_camera_eff_id != -1) {
        func_0017756C(getEffMan(&D_006FBD80), self->m_camera_eff_id);
        self->m_camera_eff_id = -1;
    }
    func_001F6DFC(self->m_displayMessage, -1, 0);
}

extern "C" void func_001F7F68(ScenePlay *self, int arg1, ScenePlayCmd *arg2, int arg3)
{
    self->m_unk04[self->m_unk30] = make_single(arg1, arg2);
    self->m_unk04[self->m_unk30]->m_unk18 = self;
    self->m_unk04[self->m_unk30]->m_oid = arg3;
    self->m_unk30++;
}

extern "C" void func_001F8028(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x38) = arg1;
    M2C_FIELD(arg0, int *, 0x34) = arg1;
}

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F8034);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE858);

extern "C" void func_001F81A8(ScenePlay *self, const char *arg1)
{
    int stage = D_007B205C->m_unk7C;
    if (self->m_unk88 != 0) {
        heapFree(self->m_unk88);
        self->m_unk88 = 0;
    }
    if (arg1 != 0 && strlen(arg1) != 0) {
        char *path = self->m_unk8C;
        FileReader reader;
        snprintf(path, 0x40, "data/evt/%02d/focus/%s", stage, arg1);
        int size = func_001BE768(path);
        self->m_unk88 = D_006E9800.alloc(size, D_002FE858, 0x354, 0, 1);
        FileReadReq req;
        req.m_unk08 = 1;
        req.m_name = path;
        req.m_unk14 = 0;
        req.m_offset = 0;
        req.m_buf = self->m_unk88;
        req.m_size = size;
        req.m_unk20 = 1;
        reader.func_001BE524(&req, 0);
        func_001417E4(&MagSystem::m_current_system->m_scene, self->m_unk88, size);
    }
}

extern "C" int ScenePlay__vfunc_04(ScenePlay *self)
{
    for (int i = 0; i < self->m_unk30; i++) {
        func_001F76B0((int)self->m_unk04[i]);
    }
    if (--self->m_unk34 <= 0) {
        return 1;
    }
    func_001F6CB8(self->m_displayMessage);
    func_001F71B8(self->m_seManager);
    func_001F7610((int)self->m_voiceManager);
    return 0;
}

extern "C" void func_001F836C(ScenePlay *self, const char *str)
{
    strncpy(self->m_unk110, str, 0x1F);
    self->m_unk110[0x1F] = '\0';
}

extern "C" char *func_001F839C(char *dst, const char *src)
{
    char buf[0x20];
    strcpy(buf, src);
    *strstr(buf, ".") = '\0';
    func_00279C98(dst, "%s/%s", buf, buf);
    return dst;
}

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE898);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE8A0);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE8B0);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE8B8);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F83F4);

INCLUDE_ASM("asm/nonmatchings/task/tsk_scene", func_001F8CEC);

extern "C" void func_001F8F70(int arg0)
{
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, void **, 0) = vtbl_11PLScenePlay;
}

extern "C" void PLScenePlay__vfunc_06(int arg0, int arg1)
{
    M2C_FIELD(arg0, void **, 0x0) = vtbl_11PLScenePlay;
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE980);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE998);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE9A8);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE9B8);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE9D0);

INCLUDE_RODATA("asm/nonmatchings/task/tsk_scene", D_002FE9E0);
