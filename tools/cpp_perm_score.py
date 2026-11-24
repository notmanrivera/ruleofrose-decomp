#!/usr/bin/env python3
"""Score for cpp_permuter (--score-cmd): how far one function in a candidate
object is from the same function in the target object (the game's bytes,
assembled from INCLUDE_ASM). Runs inside the ror-build container.

    python3 tools/cpp_perm_score.py CANDIDATE.o TARGET.o SYMBOL

Prints "score N" (0 = identical .text bytes, relocations included) as its
last line. Instruction words that carry a relocation are compared by
(opcode bits, relocation type, symbol); a replaced instruction costs 1 if
the opcode is the same (register or immediate difference), 3 otherwise;
an inserted or missing one costs 5. A candidate of another length pays 5
more per word of difference (R28: a shorter function is no progress); one
of the same length costs at most its count of differing words, so a pure
reorder has a gradient (3 swapped stores cost 3). The final judge is still
match.py.
"""
import difflib
import sys

from elftools.elf.elffile import ELFFile


def function(path, symbol):
    """[(word or key)] for symbol's instructions in .text."""
    with open(path, "rb") as f:
        e = ELFFile(f)
        text = e.get_section_by_name(".text")
        idx = e.get_section_index(".text")
        data = text.data()
        syms = [s for s in e.get_section_by_name(".symtab").iter_symbols()
                if s["st_shndx"] == idx and s.name and s["st_info"]["type"] in ("STT_FUNC", "STT_NOTYPE")
                and not s.name.startswith(("$", "."))]
        start = next((s["st_value"] for s in syms if s.name == symbol), None)
        if start is None:
            sys.exit(f"{path}: no symbol {symbol}")
        size = next((s["st_size"] for s in syms if s.name == symbol), 0)
        if not size:
            later = sorted(s["st_value"] for s in syms if s["st_value"] > start)
            size = (later[0] if later else len(data)) - start
        relocs = {}
        symtab = e.get_section_by_name(".symtab")
        for sec in e.iter_sections():
            if sec.name in (".rel.text", ".rela.text"):
                for r in sec.iter_relocations():
                    s = symtab.get_symbol(r["r_info_sym"])
                    name = s.name or e.get_section(s["st_shndx"]).name if s["st_shndx"] not in ("SHN_UNDEF", "SHN_ABS") else s.name
                    relocs[r["r_offset"]] = (r["r_info_type"], name)
    out = []
    for off in range(start, start + size - 3, 4):
        w = int.from_bytes(data[off:off + 4], "little")
        out.append(("R", w >> 26, *relocs[off]) if off in relocs else w)
    while out and out[-1] == 0:          # alignment padding after the function
        out.pop()
    return out


def opcode(x):
    return x[1] if isinstance(x, tuple) else x >> 26


def score(a, b):
    total = 0
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if tag == "equal":
            continue
        pairs = min(i2 - i1, j2 - j1)
        total += sum(1 if opcode(a[i1 + k]) == opcode(b[j1 + k]) else 3 for k in range(pairs))
        total += 5 * (max(i2 - i1, j2 - j1) - pairs)
    return total


def full_score(a, b):
    if len(a) != len(b):
        return score(a, b) + 5 * abs(len(a) - len(b))
    return min(score(a, b), sum(1 for x, y in zip(a, b) if x != y))


if __name__ == "__main__":
    cand, target, sym = sys.argv[1:4]
    print(f"score {full_score(function(cand, sym), function(target, sym))}")
