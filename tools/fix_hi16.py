#!/usr/bin/env python3
"""Repair the lui that ee-gcc 2.96's assembler (GNU as 2.10-ee) sometimes
loses, in place:

    tools/fix_hi16.py <object.o>...

The bug: a macro load or store through a symbol (`lw $2,$L12($2)`,
`sw $0,D_xxx($3)`) expands to lui $at,%hi(sym) / addu / op %lo(sym)($at),
but in a relaxed frag the assembler can write another instruction of the
expansion over the lui (`lw $2,0($1)`, `sw $0,0($1)`), keeping the
R_MIPS_HI16 relocation on it. It depends on the assembler's internal state,
so it comes and goes as a file changes (an INCLUDE_ASM turned into C++,
.rodata moving), and the game's own build did not have it: its lui is
there. The original compiler only puts R_MIPS_HI16 on lui, so any other
instruction under one is this bug. The repair rebuilds the lui: its register
is the base register of the paired R_MIPS_LO16 instruction (same symbol,
next one after it), its immediate stays the word's low half (the %hi part of
the addend).

Plain stdlib (ELF32 little endian), so it runs in the build image and on the
host (tools/match.py). Prints one line per repaired instruction.
"""
import struct
import sys

R_MIPS_HI16, R_MIPS_LO16 = 5, 6
SHT_REL = 9
SHF_EXECINSTR = 4


def fix(path):
    data = bytearray(open(path, "rb").read())
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 1:
        return 0
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    secs = [struct.unpack_from("<10I", data, shoff + i * shentsize) for i in range(shnum)]
    names_off = secs[shstrndx][4]

    def name(sec):
        end = data.index(0, names_off + sec[0])
        return data[names_off + sec[0]:end].decode()

    fixed = 0
    for rel in secs:
        if rel[1] != SHT_REL:
            continue
        target = secs[rel[7]]          # sh_info: the section relocated
        if not target[2] & SHF_EXECINSTR:
            continue
        base = target[4]
        entries = [struct.unpack_from("<II", data, rel[4] + i * 8) for i in range(rel[5] // 8)]
        for i, (off, info) in enumerate(entries):
            if info & 0xFF != R_MIPS_HI16:
                continue
            word, = struct.unpack_from("<I", data, base + off)
            if word >> 26 == 0x0F:     # a lui: fine
                continue
            sym = info >> 8
            lo = next((o for o, inf in entries[i + 1:]
                       if inf & 0xFF == R_MIPS_LO16 and inf >> 8 == sym and o > off), None)
            if lo is None:
                print(f"{path}: {name(target)}+0x{off:X}: R_MIPS_HI16 on 0x{word:08X} "
                      "with no R_MIPS_LO16 after it; left as is", file=sys.stderr)
                continue
            lo_word, = struct.unpack_from("<I", data, base + lo)
            reg = (lo_word >> 21) & 31
            new = 0x3C000000 | reg << 16 | (word & 0xFFFF)
            struct.pack_into("<I", data, base + off, new)
            print(f"{path}: {name(target)}+0x{off:X}: 0x{word:08X} -> lui ${reg} (as 2.10 bug)",
                  file=sys.stderr)
            fixed += 1
    if fixed:
        open(path, "wb").write(data)
    return fixed


if __name__ == "__main__":
    for p in sys.argv[1:]:
        fix(p)
