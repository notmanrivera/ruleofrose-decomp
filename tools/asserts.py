#!/usr/bin/env python3
"""List the game's assert calls: where, and the file, line and expression.

    tools/.venv/bin/python tools/asserts.py                    # all of them
    tools/.venv/bin/python tools/asserts.py bed/bedpfh.h       # one source file
    tools/.venv/bin/python tools/asserts.py bed/bedpfh.h --lines   # distinct lines

Every ror_assert (0x00215A30) call passes the original __FILE__, __LINE__
and expression text. For a header, the lines tell where each inline method
sits (they must stay on those lines), and the expressions often give member
and method names. Reads splat's asm (decompiled files included, see
tools/split_files.py) and needs a finished build.
"""
import argparse
import re
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import split_files  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x00100000
ARGS = {"$a0": 0, "$4": 0, "$a1": 1, "$5": 1, "$a2": 2, "$6": 2}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file", nargs="?", help="only asserts of this source file, e.g. bed/bedpfh.h")
    ap.add_argument("--lines", action="store_true", help="one row per line and expression, with a count")
    a = ap.parse_args()

    rom = (ROOT / "build/SLUS_214.48.rom").read_bytes()
    names = split_files.load_map()

    def string(sym):
        addr = split_files.resolve(sym, names)
        if addr is None or not 0 <= addr - BASE < len(rom):
            return sym
        o = addr - BASE
        return rom[o:rom.index(b"\0", o)].decode("latin-1")

    calls = {}
    for path in split_files.linked_asm():
        if "/data/" in str(path) or not path.exists():
            continue
        lines = path.read_text(errors="replace").splitlines()
        func = None
        for i, line in enumerate(lines):
            m = re.match(r"glabel (\S+)", line)
            if m:
                func = m.group(1)
            if not re.search(r"\bjal\s+ror_assert\b", line):
                continue
            pc = re.search(r"/\* \w+ ([0-9A-F]{8}) ", line).group(1)
            args = [None, None, None]
            # The arguments are set in the few instructions before the call
            # and in its delay slot.
            for t in lines[max(0, i - 12):i] + lines[i + 1:i + 2]:
                m = re.search(r"addiu\s+(\$\w+), \$(?:zero|0), (-?0x[0-9A-Fa-f]+|\d+)\b", t)
                if m and m.group(1) in ARGS:
                    args[ARGS[m.group(1)]] = int(m.group(2), 0)
                m = re.search(r"addiu\s+(\$\w+), \$\w+, %lo\(([^)]+)\)", t)
                if m and m.group(1) in ARGS:
                    args[ARGS[m.group(1)]] = string(m.group(2))
            calls[int(pc, 16)] = (func, *args)

    rows = [(pc, *c) for pc, c in sorted(calls.items()) if a.file is None or c[1] == a.file]
    if a.lines:
        counts = Counter((f, line, expr) for _, _, f, line, expr in rows)
        for (f, line, expr), n in sorted(counts.items(), key=lambda x: (str(x[0][0]), x[0][1] or 0)):
            print(f"{f}:{line}\t{n}\t{expr}")
    else:
        for pc, func, f, line, expr in rows:
            print(f"0x{pc:08X}\t{func}\t{f}:{line}\t{expr}")


if __name__ == "__main__":
    main()
