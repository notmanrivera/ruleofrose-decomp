// Project-wide definitions for the Rule of Rose decomp.
//
// Names here are ours unless noted: the original headers are lost, so
// types and helpers are reconstructed from how the binary uses them.
#ifndef ROR_H
#define ROR_H

// EE 128-bit integer (Sony SDK name). Copies of it compile to lq/sq.
typedef unsigned int u_long128 __attribute__((mode(TI)));

// The game's assert handler at 0x00215A30 prints
// "Assertion Failed: %s(%d)   %s\n" and spins. Its real name is unknown.
extern "C" void ror_assert(const char *file, int line, const char *expr);

// Original assert strings are "<file>(<line>) <expression>", so the macro
// passes __FILE__ and __LINE__; sources compile from src/ so __FILE__ is
// the original relative path, e.g. "bed/bedsubmode.cpp".
#define ASSERT(e) ((e) ? (void)0 : ror_assert(ASSERT_FILE, __LINE__, #e))

// In a partial file the __FILE__ string can still be an INCLUDE_RODATA
// (asm functions use it too): name it before including this header, e.g.
//   #define ASSERT_FILE D_002E56C8
// and drop both once the last function using it is C++.
#ifndef ASSERT_FILE
#define ASSERT_FILE __FILE__
#endif

#endif
