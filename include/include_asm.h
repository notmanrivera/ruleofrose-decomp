// INCLUDE_ASM / INCLUDE_RODATA for partially decompiled files.
//
// Ours, not splat's (generate_asm_macros_files is off in the yaml).
// `tools/dock python3 tools/configure.py --new <file>` writes a src/<file>.cpp
// with one INCLUDE_ASM per function; splat puts each function in
// asm/nonmatchings/<file>/<name>.s together with the .rodata only it uses.
// Rodata shared by several functions (e.g. the __FILE__ string of the
// asserts) gets its own INCLUDE_RODATA. Replace them one at a time with C++.
//
// The .s files are assembled by ee-gcc 2.96's own assembler (GNU as
// 2.10-ee), inside the compiler's output, so they use include/labels.inc.
// Paths are relative to the repo root (-Wa,-I.. in tools/configure.py).
//
// After the included asm the assembler is left in .text: the compiler does
// not know the asm changed sections, and assumes it is still wherever it was.
#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#if !defined(M2CTX) && !defined(PERMUTER)

#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )

#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__( \
        ".section .rodata\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        ".section .text" \
    )

__asm__(".include \"include/labels.inc\"\n");

#else

#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

#endif

#endif
