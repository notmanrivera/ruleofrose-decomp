// Sony libpad2 (SDK 3.0), reconstructed: only what the game's code uses.
// Function names come from tools/sce_symbols.py; the types are ours.
#ifndef SDK_LIBPAD2_H
#define SDK_LIBPAD2_H

extern "C" {

// Argument of scePad2CreateSocket, 0x20 bytes (layout from bed/bedpad.cpp).
struct scePad2SocketParam {
    int option;                 // +0x00
    int port;                   // +0x04
    int slot;                   // +0x08
    int number;                 // +0x0C
    unsigned char name[16];     // +0x10
};

int scePad2CreateSocket(scePad2SocketParam *param, void *dmaBuf);
int scePad2DeleteSocket(int socket);

}

#endif
