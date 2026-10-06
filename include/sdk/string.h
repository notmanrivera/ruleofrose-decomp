// libc (SDK 3.0, newlib), reconstructed: only what the game's code uses.
#ifndef SDK_STRING_H
#define SDK_STRING_H

#include "sdk/stdlib.h"

extern "C" {

void *memset(void *dst, int c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
int strcmp(const char *s1, const char *s2);
size_t strlen(const char *s);
char *strstr(const char *s, const char *find);

}

#endif
