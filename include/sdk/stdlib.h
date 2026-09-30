// libc (SDK 3.0, newlib), reconstructed: only what the game's code uses.
#ifndef SDK_STDLIB_H
#define SDK_STDLIB_H

typedef unsigned int size_t;

extern "C" {

void *malloc(size_t size);
void free(void *ptr);

}

#endif
