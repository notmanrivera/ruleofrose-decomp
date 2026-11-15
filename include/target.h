// Target-dependent basics for the Rule of Rose decomp, included by ror.h and
// include_asm.h (so by every source file).
#ifndef ROR_TARGET_H
#define ROR_TARGET_H

// Target. The matching build is for the PS2 (the default); tools/host_check.py
// compiles every file again with a modern g++ for a 32-bit PC and defines
// TARGET_PC, as the PC and Vita ports will. PS2-only code goes under
// #ifdef TARGET_PS2 with a portable #else (docs/DECOMPILING.md, "Portability").
#ifndef TARGET_PC
#define TARGET_PS2 1
#endif

// EE 128-bit integer (Sony SDK name). Copies of it compile to lq/sq; on a PC
// it is 16 aligned bytes, so copies work (arithmetic on it does not).
#ifdef TARGET_PS2
typedef unsigned int u_long128 __attribute__((mode(TI)));
#else
typedef struct { unsigned int w[4]; } __attribute__((aligned(16))) u_long128;
#endif

// A register hint that only the PS2 build needs to match:
//   register int i PS2_REG("$5") = 0;
#ifdef TARGET_PS2
#define PS2_REG(r) asm(r)
#else
#define PS2_REG(r)
#endif

// Compile-time checks of recovered layouts (C++98 has no static_assert):
//   STATIC_ASSERT(sizeof(GamMan) == 0x22AC0, GamMan_size);
#define STATIC_ASSERT(cond, name) typedef char ror_static_assert_##name[(cond) ? 1 : -1]

#define UNUSED __attribute__((unused))
#define ALIGNED(n) __attribute__((aligned(n)))

#endif
