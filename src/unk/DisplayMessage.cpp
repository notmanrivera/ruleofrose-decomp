#include "include_asm.h"
extern "C" void X_func_001E71FC(int, int, int, int, int, int, int, int *, int) asm("func_001E71FC");
extern "C" int Xii___builtin_new(int) asm("__builtin_new");
extern "C" void Xiiiiiiuf_func_001E8FC4(int, int, int, int, int, unsigned int, float) asm("func_001E8FC4");
extern "C" void X_func_001DC48C(void *, int, int, void *) asm("func_001DC48C");
extern "C" void X_func_001CA604(int, int) asm("func_001CA604");
extern "C" int X_func_001CA72C(int, int, int, int, int, int, int, int) asm("func_001CA72C");
extern "C" int X_loadModel__9MagSystemii(int, int, int) asm("loadModel__9MagSystemii");
extern int D_006E9840;
extern "C" int X_func_001C6FE0(int, int, int, int) asm("func_001C6FE0");
extern "C" void X_func_001CC250(int, int, int, int, int, int) asm("func_001CC250");
extern "C" void X_func_001CFBE4(int, int, int) asm("func_001CFBE4");
extern "C" void X_func_001CFE78(int, int, int) asm("func_001CFE78");
extern "C" void X_func_001D1D5C(int, int, int, void *) asm("func_001D1D5C");
extern "C" int X_func_001D046C(int, unsigned int) asm("func_001D046C");
extern "C" void X_func_001E7724(int, int) asm("func_001E7724");
extern "C" void X_func_001F6308(int, int, int, int, unsigned int, float, int) asm("func_001F6308");
extern "C" int Xiii_func_001E79C0(int, int) asm("func_001E79C0");
extern "C" int Xiii_func_001E7D7C(int, int) asm("func_001E7D7C");
extern "C" int Xiiu_func_001D2B8C(int, unsigned int) asm("func_001D2B8C");
extern int D_007A3D80;
extern "C" int Xii___builtin_delete(int) asm("__builtin_delete");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern int _vt$7ObjStat;
extern "C" void Xv_ObjStatDtor(int arg0, int arg1) asm("DisplayMessage__vfunc_01");
extern "C" void Xv___builtin_delete(void *) asm("__builtin_delete");
extern "C" void Xv_ObjStatDtor(int arg0, int arg1) asm("DisplayMessage__vfunc_01");
extern int _vt$14DisplayMessage;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" float Xff_cosf(float) asm("cosf");
extern "C" float Xff_sinf(float) asm("sinf");
extern "C" int Xiii_func_0010AA5C__8DogActorPCc(int, int) asm("func_0010AA5C__8DogActorPCc");
extern "C" int Xiiiiiff_func_001F5E48(int, int, int, int, float, float) asm("func_001F5E48");
extern "C" int Xiiu_func_001CBE38(int, unsigned int) asm("func_001CBE38");
extern int D_006FE6A0;
extern int D_007812C0;
extern "C" int X_memset(...) asm("memset");
extern int D_002D8F68;
extern int D_002D8F70;
// Translated mechanically from m2c drafts: only what matches byte for byte.

extern "C" void func_001F59AC(void) {
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F59B4);

// NON_MATCHING: 6/109 differ, 6 edits
#ifdef NON_MATCHING
extern "C" int Xiii_func_0010AA9C__8DogActorPCc(int, int) throw() asm("func_0010AA9C__8DogActorPCc");
extern "C" int F5BDC_new(int) throw() asm("__builtin_new");
extern "C" void F5BDC_ctor(int, int, int, int, int, unsigned int, float) throw() asm("func_001E8FC4");
extern "C" void F5BDC_71FC(int, int, int, int, int, int, int, int *, int) throw() asm("func_001E71FC");
extern "C" int func_001F5BDC(int arg0, int arg1, int arg2, int arg3, int arg4, float fparg0)
{
    if (((arg0 >> 0x1C) & 3) == 1) {
        char *obj = (char *)Xiiu_func_001D2B8C((int)&D_007812C0, (unsigned int)arg0);
        int *p = (int *)(obj + 0x3DC);
        int idx = *(int *)(obj + 0x108);
        if (arg4 != 0) {
            arg1 = Xiii_func_0010AA9C__8DogActorPCc((int)&D_006FE6A0 + idx * 0x4D0, arg4);
        }
        if (Xiii_func_001E7D7C((int)&D_007A3D80, *p) != 0) {
            X_func_001E7724((int)&D_007A3D80, *p);
            *p = -1;
        }
        *(int *)(obj + 0x13C) = arg1;
        int ret = F5BDC_new(0x100);
        F5BDC_ctor(ret, idx, arg1, arg2, arg3, (unsigned int)arg0, fparg0);
        F5BDC_71FC((int)&D_007A3D80, 1, -1, 1, 0, ret, 0, p, 0x11);
        return ret;
    }
    int ret = F5BDC_new(0x100);
    F5BDC_ctor(ret, -1, arg1, arg2, arg3, (unsigned int)arg0, fparg0);
    F5BDC_71FC((int)&D_007A3D80, 1, -1, 1, 0, ret, 0, 0, 1);
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F5BDC);
#endif

extern "C" int func_001F5D90(int arg0, int arg1, int arg2, int arg3, float fparg0, float fparg1)
{
    int temp_v0;
    int temp_v0_2;

    temp_v0 = Xiiu_func_001CBE38((int)&D_007812C0, (unsigned int) arg0);
    if (temp_v0 != -1) {
        temp_v0_2 = Xiii_func_0010AA5C__8DogActorPCc((int) ((int)&D_006FE6A0 + (temp_v0 * 0x4D0)), arg1);
        Xiiiiiff_func_001F5E48(arg0, (temp_v0_2 >= 0) ? temp_v0_2 : 0, arg2, arg3, fparg0, fparg1);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F5E48);

extern "C" int func_001F603C(int arg0, int arg1, int arg2, int arg3, float fparg0)
{
    int temp_fp = (arg0 >> 0x1C) & 3;
    if (temp_fp == 1) {
        char *obj = (char *)Xiiu_func_001D2B8C((int)&D_007812C0, (unsigned int)arg0);
        if (obj != 0) {
            int *p = (int *)(obj + 0x3DC);
            *(int *)(obj + 0x13C) = arg1;
            int tmp = *(int *)(obj + 0x108);
            if (Xiii_func_001E7D7C((int)&D_007A3D80, *p) != 0) {
                X_func_001E7724((int)&D_007A3D80, *p);
            }
            int ret = Xii___builtin_new(0x100);
            Xiiiiiiuf_func_001E8FC4(ret, tmp, arg1, arg2, arg3, (unsigned int)arg0, fparg0);
            X_func_001E71FC((int)&D_007A3D80, 1, -1, 1, 0, ret, 0, p, temp_fp);
            return ret;
        }
        return (int)obj;
    }
    return 0;
}

extern "C" void func_001F616C(unsigned int arg0, float fparg0)
{
    if (((arg0 >> 0x1C) & 3) == 1) {
        char *obj = (char *)Xiiu_func_001D2B8C((int)&D_007812C0, arg0);
        if (obj != 0) {
            int *p = (int *)(obj + 0x3DC);
            if (Xiii_func_001E7D7C((int)&D_007A3D80, *p) != 0) {
                M2C_FIELD(Xiii_func_001E79C0((int)&D_007A3D80, *p), float *, 0x6C) = fparg0;
            }
        }
    }
}

extern "C" void func_001F61EC(unsigned int arg0)
{
    if (X_func_001D046C((int)&D_007812C0, arg0) != 0 && ((arg0 >> 0x1C) & 3) == 1) {
        char *obj = (char *)Xiiu_func_001D2B8C((int)&D_007812C0, arg0);
        int *p = (int *)(obj + 0x3DC);
        if (Xiii_func_001E7D7C((int)&D_007A3D80, *p) != 0) {
            X_func_001E7724((int)&D_007A3D80, *p);
            *p = -1;
        }
    }
}

extern "C" void func_001F627C(unsigned int arg0, int arg1, int arg2, int arg3, float fparg0, int arg4)
{
    X_func_001F6308(Xiiu_func_001CBE38((int)&D_007812C0, arg0), arg1, arg2, arg3, arg0, fparg0, arg4);
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F6308);

extern "C" void func_001F6570(void) {
}

extern "C" int func_001F6578(unsigned short arg0, int arg1, int arg2)
{
    unsigned short sp0;
    int sp4;
    int ret;
    void *p = (void *)&D_007812C0;

    X_func_001DC48C((char *)p + 0x22220, arg0, 0xF, &sp0);
    X_func_001DC48C((char *)p + 0x22220, arg0, 0xB, &sp4);
    X_func_001CA604((int)&D_007812C0, sp0 >> 0xA);
    if (sp0 != 0xFFFF) {
        ret = X_func_001CA72C((int)&D_007812C0, sp0, sp4, 5, 0, 0xFFFF, 0, -1);
    } else {
        ret = 0;
        X_func_001CC250((int)&D_007812C0, -1, 0, arg0, 0, 0);
    }
    if (arg1 != 0) {
        X_func_001CFBE4((int)&D_007812C0, ret, arg1);
    }
    if (arg2 != 0) {
        X_func_001CFE78((int)&D_007812C0, ret, arg2);
    }
    return ret;
}

extern "C" int func_001F6694(unsigned short arg0, int arg1, int arg2, int arg3)
{
    int type = -1;
    int model;

    if (arg0 != 0xFFFF) {
        model = X_loadModel__9MagSystemii((int)&D_006E9840, arg0, -1);
    } else {
        model = -1;
    }
    switch (arg1) {
    case 0:
    case 1:
    case 2:
    case 3:
        type = 1;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        type = 2;
        break;
    }
    int r = X_func_001C6FE0((int)&D_007812C0, type, arg1, -1);
    X_func_001CC250((int)&D_007812C0, model, r, (unsigned short)arg1, 0, 0);
    if (arg2 != 0) {
        X_func_001CFBE4((int)&D_007812C0, r, arg2);
    }
    if (arg3 != 0) {
        X_func_001CFE78((int)&D_007812C0, r, arg3);
    }
    return r;
}

extern "C" int func_001F67A0(int arg0, int arg1, short arg2, float fparg0)
{
    int r = X_func_001C6FE0((int)&D_007812C0, 2, 6, -1);
    X_func_001CC250((int)&D_007812C0, -1, r, 0xFFFF, 0, 0);
    if (arg0 != 0) {
        X_func_001CFBE4((int)&D_007812C0, r, arg0);
    }
    if (arg1 != 0) {
        X_func_001CFE78((int)&D_007812C0, r, arg1);
    }
    X_func_001D1D5C((int)&D_007812C0, r, 0x32, &arg2);
    X_func_001D1D5C((int)&D_007812C0, r, 0x33, &fparg0);
    return r;
}

extern "C" int func_001F6878(unsigned int arg0)
{
    return ((arg0 >> 0x17) & 0x1F) == 2;
}

extern "C" void func_001F688C()
{
    X_memset((int)&D_002D8F70, 0, 0x20);
    D_002D8F68 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/DisplayMessage", func_001F68BC);

extern "C" void func_001F6B28(int arg0, float fparg0, float fparg1)
{
    M2C_FIELD(arg0, float *, 0) = (float) (M2C_FIELD(arg0, float *, 0) + (Xff_sinf(fparg0) * fparg1));
    M2C_FIELD(arg0, float *, 8) = (float) (M2C_FIELD(arg0, float *, 8) + (Xff_cosf(fparg0) * fparg1));
}

extern "C" int func_001F6B8C(float fparg0, float fparg1)
{
    int n = (int)(fparg0 / (fparg1 * 0.05232999846339226f));
    if (n < 0.0f) {
        n = -n;
    }
    return n;
}

extern "C" int func_001F6BD0(float fparg0, float fparg1)
{
    int n = (int)(fparg0 / (fparg1 * 0.02778f));
    if (n < 0.0f) {
        n = -n;
    }
    return n;
}

extern "C" float func_001F6C14(int arg0, float fparg0)
{
    float var_f0;

    var_f0 = 0.0f;
    if (arg0 != 0) {
        var_f0 = (fparg0 / (float) arg0) / 0.02777999872341752f;
    }
    return var_f0;
}

extern "C" float func_001F6C54()
{
    char buf[0x50];
    (void)&buf;
    return 0.0f;
}

extern "C" void func_001F6C64(int arg0)
{
    M2C_FIELD(arg0, int *, 0x8C) = (int)&_vt$14DisplayMessage;
    M2C_FIELD(arg0, int *, 0x84) = -1;
    M2C_FIELD(arg0, int *, 0x80) = 0;
    M2C_FIELD(arg0, int *, 0x88) = 0;
}

extern "C" void Xv_ObjStatDtor(int arg0, int arg1)
{
    M2C_FIELD(arg0, int *, 0x8c) = (int)&_vt$14DisplayMessage;
    if (arg1 & 1) {
        return Xv___builtin_delete((void *)arg0);
    }
}
