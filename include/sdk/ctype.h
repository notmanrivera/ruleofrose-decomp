// libc (SDK 3.0, newlib), reconstructed: only what the game's code uses.
// newlib's ctype macros index _ctype_ + 1 (entry -1 is EOF) with the char
// itself, sign-extended.
#ifndef SDK_CTYPE_H
#define SDK_CTYPE_H

#define _N 04
#define _X 0100

extern "C" {

extern const char _ctype_[];

}

#define isdigit(c) ((_ctype_ + 1)[(unsigned)(c)] & _N)
#define isxdigit(c) ((_ctype_ + 1)[(unsigned)(c)] & (_X | _N))

#endif
