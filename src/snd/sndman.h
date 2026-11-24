// snd/sndman.h: low-level sound driver state (name inferred from the module).
// func_0017F0D0 initializes the master volumes at +0x1B04/+0x1B08.
// D_007B2580 occupies 0x1B40 bytes before D_007B40C0.
#ifndef SND_SNDMAN_H
#define SND_SNDMAN_H
#include "ror.h"
struct SndMan {
    int m_unk00;
    unsigned char m_unk04[0x20];
    int m_unk24, m_unk28;
    unsigned char m_unk2C[0x1AC8];
    int m_unk1AF4, m_unk1AF8;
    unsigned char m_unk1AFC[8];
    int m_masterLeft, m_masterRight;
    unsigned char m_unk1B0C[0x34];
};
STATIC_ASSERT(sizeof(SndMan) == 0x1B40, SndMan_size);
#endif
