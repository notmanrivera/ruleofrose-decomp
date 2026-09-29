// Sony libvib (SDK 3.0), reconstructed: only what the game's code uses.
// Function names come from tools/sce_symbols.py; the types are ours.
#ifndef SDK_LIBVIB_H
#define SDK_LIBVIB_H

extern "C" {

int sceVibSetActParam(int socket, int profileSize, unsigned char *profile,
                      int dataSize, unsigned char *data);

}

#endif
