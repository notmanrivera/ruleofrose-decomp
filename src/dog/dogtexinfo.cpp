#include "ror.h"
#include "dog/dogtexinfo.h"
#include "dog/dogmodel.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"
#include "mw/i3d.h"
#include "sdk/string.h"
#include "include_asm.h"

extern BedMemory D_006E9800;     // the global heap

// utl/utlfile, utl/utlmisc.
void utlStrCopy(char *theDest, int theSize, const char *theSrc);
int utlIsTcc(const char *theName);

// utl/utltm2 (names ours).
extern "C" int func_00104E1C(void *theTM2);                 // the TM2's size
extern "C" void func_0010559C(void *theTM2, int theA, int theB, int theC);

























// 0x001161E4
tag_I3dTexInfo_s *DogTexInfo::getTexInfo(int theN)
{
    ASSERT(m_tex_info);
    ASSERT((theN >= 0) && (theN < m_num_tex));
    return &m_tex_info[theN];
}

// 0x0011626C
void DogTexInfo::func_0011626C(int theA, int theB, int theC)
{
    m_unk14 = theA;
    m_unk18 = theB;
    m_unk1C = theC;
}

// 0x0011627C
void DogTexInfo::clear()
{
    m_unk14 = 255;
    m_unk18 = 220;
    m_unk1C = 152;
    m_max_tex = 0;
    m_num_tex = 0;
    m_tex_info = 0;
    m_tex_data = 0;
    m_dirty = 0;
}
























// 0x001162AC: room for theMax textures.
void DogTexInfo::create(int theMax)
{
    ASSERT(theMax > 0);
    release();
    m_max_tex = theMax;
    int size = theMax * sizeof(tag_I3dTexInfo_s);
    m_tex_info = (tag_I3dTexInfo_s *)D_006E9800.alloc(size, -1);



    ASSERT(m_tex_info);
    memset(m_tex_info, 0, size);
    size = theMax * sizeof(DogTexData);
    m_tex_data = (DogTexData *)D_006E9800.alloc(size, -1);


    ASSERT(m_tex_data);
    ASSERT(( ((int)m_tex_data) % 8 ) == 0);
    memset(m_tex_data, 0, size);
}

// 0x001163DC: the texture called theName, or -1.
int DogTexInfo::find(const char *theName)
{
    for (int i = 0; i < m_num_tex; i++) {
        const char *name = m_tex_info[i].pszTexName;
        if (name && name[0] && strcmp(name, theName) == 0) {
            return i;
        }
    }
    return -1;
}

// 0x0011646C: the first empty entry, or a new one, or -1. The two
// empty-name cases are separate checks in the game; the tail keeps
// m_num_tex in $v0 and sets -1 only when the table is full. The loop
// loads m_tex_info once before the first iteration.
int DogTexInfo::findFree()
{
    int i;
    for (i = 0; i < m_num_tex; i++) {
        const char *name = m_tex_info[i].pszTexName;
        if (!name) return i;
        // (the game checks both, in this order)
        if (!name[0]) return i;
    }
    if (m_num_tex >= m_max_tex) {
        return -1;
    }
    return m_num_tex;
}

// 0x001164D0
void DogTexInfo::release()
{
    if (m_tex_data) {
        if (m_num_tex > 0) {
            for (int i = 0; i < m_num_tex; i++) {
                if (m_tex_data[i].m_own && m_tex_data[i].m_data) {
                    D_006E9800.free(m_tex_data[i].m_data);
                    m_tex_data[i].m_data = 0;
                }
            }
        }
        D_006E9800.free(m_tex_data);
        m_tex_data = 0;
    }
    if (m_tex_info) {
        if (m_num_tex > 0) {
            for (int i = 0; i < m_num_tex; i++) {
                if (m_tex_info[i].pszTexName) {
                    if (m_tex_info[i].pPicture) {
                        func_00219E98(m_tex_info[i].pPicture);
                    }
                    if (m_tex_info[i].pUnk08) {
                        func_00219EF8(m_tex_info[i].pUnk08);
                    }
                }
            }
        }
        D_006E9800.free(m_tex_info);
        m_tex_info = 0;
    }
    clear();
}



























































// 0x00116618: drops a user of texture theN; frees it after the last.
void DogTexInfo::releaseTex(int theN)
{
    if (theN >= 0 && theN < m_max_tex && theN < m_num_tex) {
        ASSERT(m_tex_info);
        ASSERT(m_tex_data);
        ASSERT(m_tex_info[theN].pszTexName != __null);
        if (m_tex_info[theN].pszTexName) {
            DogTexData *p = (DogTexData *)m_tex_info[theN].pPicture;



            ASSERT(p);
            if (--p->m_ref <= 0) {
                if (m_tex_info[theN].pPicture) {
                    func_00219E98(m_tex_info[theN].pPicture);
                }
                if (m_tex_info[theN].pUnk08) {
                    func_00219EF8(m_tex_info[theN].pUnk08);
                }
                m_tex_info[theN].pszTexName = "";
                m_tex_info[theN].pPicture = 0;
                m_tex_info[theN].pUnk08 = 0;





                ASSERT(p);
                if (p) {
                    if (p->m_own) {
                        D_006E9800.free(p->m_data);
                    }
                    memset(p, 0, sizeof(DogTexData));
                }
            }
        }
        m_dirty = 1;
    }
}




// 0x001167F4: releases the textures theModel uses.
void DogTexInfo::releaseModel(DogModel *theModel)
{
    int i;
    ASSERT(m_tex_info);
    ASSERT(m_tex_data);
    for (i = 0; i < theModel->get_nTex(); i++) {
        const char *name = theModel->getTexName(i);
        for (int j = 0; j < m_num_tex; j++) {
            if (m_tex_info[j].pszTexName && strcmp(m_tex_info[j].pszTexName, name) == 0) {
                releaseTex(j);
                break;
            }
        }
    }
    // m_num_tex down to the last texture with a name.
    for (i = m_num_tex - 1; i >= 0; i--) {
        const char *name = m_tex_info[i].pszTexName;
        if (name && name[0]) {
            m_num_tex = i + 1;
            break;
        }
    }
    if (i < 0) {
        m_num_tex = 0;
    }
}














// 0x001169D0: releases the textures named in thePack (a pack header with
// only file offsets, then the names).
// NON_MATCHING: the game counts the first loop down (loop.c reverses it)
// and allocates other registers.
#ifdef NON_MATCHING
void DogTexInfo::releasePack(void *thePack)
{
    BedPfhHeader *h = (BedPfhHeader *)thePack;
    int n = h->m_num_file;
    const char *name = (const char *)(h + 1) + n * sizeof(int);
    int i;
    for (i = 0; i < n; i++) {
        ASSERT(name);
        ASSERT((*name)!=0);
        for (int j = 0; j < m_num_tex; j++) {
            if (m_tex_info[j].pszTexName && strcmp(m_tex_info[j].pszTexName, name) == 0) {
                releaseTex(j);
                break;
            }
        }
        while (*name++) {
        }
    }
    for (i = m_num_tex - 1; i >= 0; i--) {
        const char *s = m_tex_info[i].pszTexName;
        if (s && s[0]) {
            m_num_tex = i + 1;
            break;
        }
    }
    if (i < 0) {
        m_num_tex = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/dog/dogtexinfo", releasePack__10DogTexInfoPv);
#endif



































// 0x00116B5C: a texture named theName drawn from theSrc's picture; the
// existing one if there is.
int DogTexInfo::func_00116B5C(void *theSrc, const char *theName)
{
    int i;
    int found = 0;
    int place = -1;
    for (i = 0; i < m_num_tex; i++) {
        if (!m_tex_info[i].pszTexName || !m_tex_info[i].pszTexName[0]) {
            place = i;
        } else if (strcmp(m_tex_info[i].pszTexName, theName) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        return i;
    }
    if (place < 0) {
        if (m_num_tex >= m_max_tex) {
            return -1;
        }
        place = m_num_tex;
        m_num_tex = place + 1;
        ASSERT(m_num_tex <= m_max_tex);
    }
    void *pic = m_tex_data[place].m_picture;
    int result = func_00219E58(pic);





    ASSERT(result == I3D_OK);
    func_002197C8(pic, theSrc);
    m_tex_info[place].pPicture = pic;
    m_tex_info[place].pszTexName = theName;
    m_tex_info[place].pUnk08 = 0;
    m_tex_info[place].nUnk0C = 0;
    m_tex_data[place].m_data = 0;
    m_tex_data[place].m_own = 0;
    m_tex_data[place].m_ref = 1;
    m_dirty = 1;
    return place;
}













// 0x00116D14: loads theTM2 as texture theTexName (shared unless theFlags
// & 2; copied if theFlags). theTcc < 0: from the name. Returns its
// number, or -1 (full), -2 (no memory), 3 (bad TM2).
// NON_MATCHING: one branch differs: after func_00219AB0 the game uses a
// beql (predicted taken) where this compiles to a beqz.
#ifdef NON_MATCHING
int DogTexInfo::loadTM2(const char *theTexName, void *theTM2, int theFlags, int theTcc)
{
    ASSERT(theTM2);
    ASSERT(theTexName);
    ASSERT(strlen(theTexName) < 40);
    int place;
    if (!(theFlags & 2)) {
        place = find(theTexName);
        if (place >= 0) {
            m_tex_data[place].m_ref++;
            return place;
        }
    }
    place = findFree();
    if (place < 0) {
        return -1;
    }
    void *data;
    int own;
















    if (theFlags) {
        int size = func_00104E1C(theTM2);
        void *p;
        if (func_00104E1C(theTM2) == 0) {
            p = D_006E9800.alloc(size, __FILE__, __LINE__, place, 0);
        } else {


            p = D_006E9800.alloc(size, __FILE__, __LINE__, place, 2);
        }
        if (!p) {
            return -2;
        }
        memcpy(p, theTM2, size);
        data = p;
        own = 1;
    } else {
        data = theTM2;
        own = 0;
    }
    m_tex_data[place].m_data = data;
    m_tex_data[place].m_own = own;
    m_tex_data[place].m_ref = 1;
    utlStrCopy(m_tex_data[place].m_name, sizeof(m_tex_data[place].m_name), theTexName);
    void *pic = m_tex_data[place].m_picture;
    int result = func_00219E58(pic);





















    ASSERT(result == I3D_OK);
    if (func_002193F0(pic, data, 0, 0) != 0) {
        return 3;
    }
    func_00219D80(pic, theTcc < 0 ? utlIsTcc(theTexName) : theTcc & 1);
    func_00219DA8(pic, 0);
    void *clut = m_tex_data[place].m_clut;
    result = func_00219EB8(clut);


















    ASSERT(result == I3D_OK);
    if (func_00219AB0(clut, data, 0, 0) != 0) {
        func_00219EF8(clut);
        clut = 0;
    }
    m_tex_info[place].pszTexName = m_tex_data[place].m_name;
    m_tex_info[place].pPicture = pic;
    m_tex_info[place].pUnk08 = clut;
    m_tex_info[place].nUnk0C = 0;
    if (place == m_num_tex) {
        m_num_tex = place + 1;
    }

























    ASSERT(place < m_num_tex);
    ASSERT(m_num_tex <= m_max_tex);
    m_dirty = 1;
    return place;
}
#else
INCLUDE_ASM("asm/nonmatchings/dog/dogtexinfo", loadTM2__10DogTexInfoPCcPvii);
#endif























// 0x001170B8: loads a pack's TM2 files, as named: those theI3r uses, or
// all of them. theTint: pass m_unk14..1C to func_0010559C first.
// NON_MATCHING: loop.c moves the `return -2`/`return -1` blocks out of
// the loops; the game keeps them in place.
#ifdef NON_MATCHING
int DogTexInfo::loadPack(BedPfh *thePfh, tag_I3rRoot_s *theI3r, int theFlags, int theTint)
{
    const char *names[256];
    int i;
    const char *name;
    int numtex = thePfh->getNumFile();
    ASSERT(numtex <= 256);
    name = thePfh->m_name;
    for (i = 0; i < numtex; i++) {
        names[i] = name;
        name += strlen(name) + 1;
    }
    if (theI3r) {




        ASSERT(I3D_OK == I3rRoot__CheckIdString( theI3r ));
        int ntex = func_0022B428(theI3r);
        ASSERT(ntex >= 0);
        for (int t = 0; t < ntex; t++) {
            name = func_0022B438(theI3r, t);
            for (i = 0; ; i++) {
                if (i >= numtex) {
                    return -3;
                }
                if (strcmp(names[i], name) == 0) {
                    break;
                }
            }
            void *tm2 = thePfh->getFileTop(i);
            if (theTint) {
                func_0010559C(tm2, m_unk14, m_unk18, m_unk1C);
            }
            if (loadTM2(name, tm2, theFlags, -1) < 0) {
                return -2;
            }
        }
        return 0;
    }
    for (i = 0; i < numtex; i++) {
        name = names[i];
        void *tm2 = thePfh->getFileTop(i);
        if (theTint) {
            func_0010559C(tm2, m_unk14, m_unk18, m_unk1C);
        }
        if (loadTM2(name, tm2, theFlags, -1) < 0) {
            return -1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/dog/dogtexinfo", loadPack__10DogTexInfoP6BedPfhP13tag_I3rRoot_sii);
#endif

































// 0x001173D4: texture theTo shows theFrom's picture.
void DogTexInfo::func_001173D4(const char *theTo, const char *theFrom)
{
    int fn = find(theTo);
    ASSERT(fn >= 0);
    int en = find(theFrom);

    ASSERT(en >= 0);
    m_tex_info[fn].pPicture = m_tex_info[en].pPicture;
    m_tex_info[fn].pUnk08 = m_tex_info[en].pUnk08;
    m_tex_info[fn].nUnk0C = m_tex_info[en].nUnk0C;
    func_00219A98(m_tex_info[fn].pPicture, &m_tex_info[fn]);
    m_dirty = 1;
}

// 0x001174BC
void DogTexInfo::func_001174BC()
{
}















// 0x001174C4
void DogTexInfo::setTcc(int theNo, int theTcc)
{
    ASSERT(theNo >= 0 && theNo < m_max_tex);
    ASSERT(m_tex_info[theNo].pPicture);
    func_00219D80(m_tex_info[theNo].pPicture, theTcc);
}











































// 0x0011756C: gives the textures, up to the last with a picture, to p.
void DogTexInfo::func_0011756C(void *p)
{
    ASSERT(p != __null);
    ASSERT(m_tex_info != __null);
    ASSERT(m_num_tex > 0);
    int n;
    for (n = m_num_tex - 1; n >= 0; n--) {
        if (m_tex_info[n].pPicture) {
            break;
        }
    }
    m_dirty = 0;
    m_num_tex = n + 1;
    return func_0021F1E8(p, m_tex_info, n + 1);
}

// 0x0011764C
void DogTexInfo::func_0011764C()
{
}
