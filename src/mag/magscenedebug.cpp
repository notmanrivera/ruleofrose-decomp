// mag/magscenedebug.cpp: MagScene's debug windows, one per level.
#include "mag/magscene.h"
#include "mag/maglifewindow.h"

extern "C" void func_001BEBEC(void *thePage, void *theArg);
extern "C" void func_001348B0(MagScene *theScene, int theNo);
extern "C" void func_00134A00(MagScene *theScene, int theNo, int theX, int theY, int theZ);
extern "C" void func_00134AB8(MagScene *theScene, int theNo, int theW, int theH);
extern "C" void func_00134CD0(MagScene *theScene, int theNo, int theX, int theY, int theW, int theH);
extern "C" void func_00135494(MagScene *theScene, int theNo, int theOn);
extern "C" void func_00135594(MagScene *theScene, int theNo);

MagLifeWindow *MagScene::func_00143114(int theLevel)
{
    int n = m_dbg_window[theLevel];
    if (n < 0) {
        return 0;
    }
    return m_window[n];

}






void MagScene::func_0014313C(const BedPad &thePad0, const BedPad &thePad1)
{
    for (int i = 3; i >= 0; i--) {
        if (m_dbg_window[i] >= 0) {
            ASSERT(m_window[m_dbg_window[i]]);
            m_window[m_dbg_window[i]]->live();
            if (m_window[m_dbg_window[i]]->processPad(thePad0, thePad1)) {
                return;
            }
        }
    }
}


int MagScene::func_0014324C(int theLevel)
{
    ASSERT(m_dbg_window[theLevel] < 0);
    int n;
    for (n = 0; n < 4; n++) {
        if (!m_window[n]) {
            break;
        }
    }
    if (n >= 4) {
        return -1;
    }
    m_window[n] = new MagLifeWindowDebug;

    ASSERT(m_window[n]);
    m_window[n]->func_0012FE30(0x200, 0x100);
    func_001BEBEC(&m_unk02744[n], m_unk02908);
    m_window[n]->func_00130778(&m_unk02744[n]);
    m_window[n]->m_font_tex = m_unk028F4[n];
    m_life_man.add(m_window[n], 0x8000);
    func_00135494(this, n, 1);
    func_00135594(this, n);
    func_00134AB8(this, n, 0x200, 0x100);
    func_00134A00(this, n, 0, 0xA0, 30000);
    func_00134CD0(this, n, 0, 0, 0x200, 0x100);
    m_dbg_window[theLevel] = n;
    return n;
}

















void MagScene::func_00143430(int theLevel)
{
    ASSERT(m_dbg_window[theLevel] >= 0);
    func_001348B0(this, m_dbg_window[theLevel]);
    m_dbg_window[theLevel] = -1;
}
