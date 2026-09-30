// libc (SDK 3.0, newlib), reconstructed: only what the game's code uses.
// newlib's ctype macros index _ctype_ + 1 (entry -1 is EOF) with the char
// itself, sign-extended.
#ifndef SDK_CTYPE_H
#define SDK_CTYPE_H

#define _L 02
#define _N 04
#define _X 0100

extern "C" {

extern const char _ctype_[];

}

#define islower(c) ((_ctype_ + 1)[(unsigned)(c)] & _L)
#define isdigit(c) ((_ctype_ + 1)[(unsigned)(c)] & _N)
#define isxdigit(c) ((_ctype_ + 1)[(unsigned)(c)] & (_X | _N))

#define toupper(c) \
    __extension__ ({ int __x = (c); islower(__x) ? (__x - 'a' + 'A') : __x; })

#endif
