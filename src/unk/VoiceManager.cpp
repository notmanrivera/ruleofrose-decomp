#include "include_asm.h"
#include "game/gamman.h"
extern "C" int func_001E50C8(void *, int, int, int, float, int, int, int);
extern "C" int func_001E5E58(void *, unsigned int, int, void *);
static inline void *getGamSnd(GamMan *g) { return g->m_snd; }
struct VoiceEntry {
    int m_id;
    int m_unk04;
    int m_timer;
};
struct VoiceManager {
    VoiceEntry m_entries[0x40];
    int m_count;
};
extern "C" void func_001F728C(VoiceManager *, int);
extern "C" int Xi_func_001F7644() asm("func_001F7644");
extern "C" int Xii___builtin_delete(int) asm("__builtin_delete");
extern int _vt$10EmyManager;
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("VoiceManager__vfunc_01");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("VoiceManager__vfunc_01");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("VoiceManager__vfunc_01");
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" void func_001F7644(int);
extern "C" void EmyManager_vfunc06(int arg0, int arg1) asm("VoiceManager__vfunc_01");
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern int _vt$12VoiceManager;
// Translated mechanically from m2c drafts: only what matches byte for byte.

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F6F4C);

extern "C" void func_001F70C8(VoiceManager *self, int arg1, int arg2, int arg3, int arg4)
{
    int left;
    int right;

    self->m_entries[self->m_count].m_id = arg1;
    self->m_entries[self->m_count].m_unk04 = 0;
    self->m_entries[self->m_count].m_timer = arg4;
    left = (arg3 >= 0) ? ((0x3F - arg3) * arg2) / 64 : arg2;
    right = (arg3 <= 0) ? ((arg3 + 0x3F) * arg2) / 64 : arg2;
    func_001E50C8(getGamSnd(&D_007812C0), arg1, left, right, 1.0f, 0, 0, 0);
    self->m_count++;
}

extern "C" void func_001F71B8(VoiceManager *self)
{
    for (int i = 0; i < self->m_count; i++) {
        if (self->m_entries[i].m_timer != 0) {
            if (--self->m_entries[i].m_timer == 0) {
                func_001F728C(self, i--);
            }
        }
    }
}

extern "C" void func_001F723C(VoiceManager *self)
{
    int n = self->m_count;
    for (int i = 0; i < n; i++) {
        func_001F728C(self, 0);
    }
}

extern "C" void func_001F728C(VoiceManager *self, int idx)
{
    if (idx < self->m_count) {
        func_001E5E58(getGamSnd(&D_007812C0), self->m_entries[idx].m_id, 1, 0);
        int last = --self->m_count;
        if (last != idx) {
            self->m_entries[idx] = self->m_entries[last];
        }
    }
}

extern "C" void func_001F7338(VoiceManager *self, int arg1, int arg2)
{
    for (int i = 0; i < self->m_count; i++) {
        if (self->m_entries[self->m_count].m_unk04 == arg2 &&
            self->m_entries[self->m_count].m_id == arg1) {
            func_001F728C(self, i--);
        }
    }
}

extern "C" void func_001F73D4(int arg0)
{
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = (int)&_vt$12VoiceManager;
}

extern "C" void EmyManager_vfunc06(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 12) = (int)&_vt$12VoiceManager;
    func_001F7644(arg0);
    if (arg1 & 1) {
        return X___builtin_delete((void *)arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unk/VoiceManager", func_001F7444);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7D8);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7E0);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE7F0);

INCLUDE_RODATA("asm/nonmatchings/unk/VoiceManager", D_002FE800);
