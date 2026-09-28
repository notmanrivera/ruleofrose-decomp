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
#define ASSERT(e) ((e) ? (void)0 : ror_assert(__FILE__, __LINE__, #e))

#endif
