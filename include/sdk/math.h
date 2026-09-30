// libm (SDK 3.0, newlib), reconstructed: only what the game's code uses.
// The toolchain has no libc headers. Declared like this, g++ treats sqrtf
// as a builtin: an inline sqrt.s that calls sqrtf only for a NaN result.
#ifndef SDK_MATH_H
#define SDK_MATH_H

extern "C" {

float sqrtf(float x);
float cosf(float x);
float sinf(float x);
float atanf(float x);
float asinf(float x);

}

#endif
