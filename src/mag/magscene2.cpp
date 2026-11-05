#include "ror.h"
#include "include_asm.h"
#undef ASSERT_FILE
#define ASSERT_FILE D_002EDC58
extern const char D_002EDC58[];
extern const char D_002EDF08[];
extern const char D_002EDED0[];
#include "mag/magscene.h"
#include "dog/dogtexinfo.h"

extern "C" int func_001425DC(void *theLoader);
extern "C" int func_00142ED8(void *theLoader);
extern "C" void func_001386D4(MagScene *self, int theNo);
extern "C" void termWorld__9MagLifePC(void *thePC);
extern "C" int sceGsSyncPath(int theMode, unsigned short theTimeout);
struct UtlFind;
void utlFindClear(UtlFind *theFind);

extern const char D_002EDDB0[];
extern const char D_002EDED8[];

static inline bool actorAlive(DogModel *theModel)
{
    if (theModel->m_i3r_root && I3rRoot__CheckIdString(theModel->m_i3r_root) != 0) {
        ror_assert(D_002EDDB0, 248, D_002EDED8);
    }
    return theModel->m_i3r_root != 0;
}

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_00135FA4);

void MagScene::func_0013604C()
{
    *(int *)((char *)this + 0x2BD98) = 0;
    utlFindClear((UtlFind *)((char *)this + 0x2BD68));
    termWorld__9MagLifePC(&m_pc);
}


void func_00136098(void) {
}

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", __8MagScene);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", _$_8MagScene);

extern "C" int func_00137300(MagScene *self)
{
    return func_001425DC((char *)self + 0x215C);
}


extern "C" int func_00137318(MagScene *self)
{
    return func_00142ED8((char *)self + 0x224C);
}


INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED800);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED810);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED820);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED830);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED858);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED898);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED8A8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED8B8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED8C8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED8D8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED8E8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED8F8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED908);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED918);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED928);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED938);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED948);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED958);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED968);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED978);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED988);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED998);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED9A8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED9B8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED9C8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED9D8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED9E8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002ED9F8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDA08);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDA28);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDA48);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDA60);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDA78);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDA90);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDAA8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDAC0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDAD8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDAF0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDB08);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDB20);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDB38);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDB50);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDB68);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDB80);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDB98);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDBB0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDBC8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDBE0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDBF8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDC10);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_00137330);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDC58);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDC70);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDC98);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDCB0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDCC0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDCD8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDCE8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDCF0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDCF8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD10);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD18);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD20);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD28);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD30);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD38);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD50);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD68);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD78);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDD80);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_001377F0__8MagSceneP7I3dDrawiii);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDDA8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDDB0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDDD0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDDE0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDDF0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDDF8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDE08);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDE18);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDE20);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDE30);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_0013836C);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_00138610);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_001386D4);

extern "C" void func_00138804(MagScene *self)
{
    for (int i = 0; i < 4; i++) {
        func_001386D4(self, i);
    }
}


extern "C" int func_0013884C(MagScene *self)
{
    int i;
    for (i = 0; i < 128 && actorAlive(&self->m_actor[i]); i++) {
    }
    return i < 128 ? i : -1;
}


extern "C" int func_001388E8(MagScene *self, int theID)
{
    if (theID < 0) {
#line 867
        ASSERT_S(theID >= 0, D_002EDF08);
    } else {
        for (int i = 0; i < 128; i++) {
            if (actorAlive(&self->m_actor[i]) && self->m_actor[i].m_id == theID) {
                return i;
            }
        }
    }
    return -1;
}


extern "C" int func_001389C4(MagScene *self, const char *theName)
{
    if (!theName) {
#line 891
        ASSERT_S(theName, D_002EDED0);
    } else {
        for (int i = 0; i < 128; i++) {
            if (actorAlive(&self->m_actor[i]) && self->m_actor[i].func_0010F2DC(theName)) {
                return i;
            }
        }
    }
    return -1;
}


extern "C" int func_00138AA8(MagScene *self, int theID)
{
    return theID % 1024 & 0x3FF;
}


extern "C" int func_00138AB0(MagScene *self, int theID)
{
    return theID / 1024;
}


INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDEA8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDEB8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDED0);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDED8);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDF08);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_00138AC8);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_00138BC4__8MagSceneP7I3dDrawiiPCc);

INCLUDE_RODATA("asm/nonmatchings/mag/magscene2", D_002EDF50);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_00138CE8);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_00138ED0__8MagSceneP7I3dDrawiPCc);

extern "C" void func_00139010(MagScene *self, int theN)
{
    sceGsSyncPath(0, 0);
#line 1383
    ASSERT(theN >= 0 && theN < 128);;
    self->m_actor[theN].release((int)self + 0x29520);
    self->m_unk29120[theN] = 0;
    self->m_unk29120[theN + 0x80] = 0;
    if (theN == *(int *)((char *)self + 0x853B8)) {
        self->func_001316B8(-1, 0);
    }
}


INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_001390D4__8MagSceneiii);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_0013910C__8MagSceneiii);

INCLUDE_ASM("asm/nonmatchings/mag/magscene2", func_00139308);
