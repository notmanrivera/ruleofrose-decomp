// Sony sifdev (SDK 3.0), reconstructed: only what the game's code uses.
#ifndef SDK_SIFDEV_H
#define SDK_SIFDEV_H

#define SCE_WRONLY 0x0002
#define SCE_CREAT 0x0200
#define SCE_TRUNC 0x0400

extern "C" {

int sceOpen(const char *filename, int flag, ...);
int sceClose(int fd);
int sceWrite(int fd, const void *buf, int nbyte);

}

#endif
