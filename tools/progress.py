#!/usr/bin/env python3
"""Decompilation progress: which files are C++ and how much code they cover.

    tools/.venv/bin/python tools/progress.py

A file counts once src/<file>.cpp exists; the matching build (tools/dock
ninja) is what proves it matches. Sizes are .text bytes from
config/splits.tsv, minus the functions a partial file still pulls in with
INCLUDE_ASM (their size is on the `nonmatching` line of their .s). The SDK
region is reported apart because the port replaces those libraries instead
of decompiling them.
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
TEXT_END = 0x00280E88


def asm_bytes(name, src):
    """.text bytes of src still coming from INCLUDE_ASM."""
    total = 0
    for func in re.findall(r"^INCLUDE_ASM\(\s*\"[^\"]*\"\s*,\s*([^\s)]+)\s*\)", src.read_text(), re.M):
        s = ROOT / "asm/nonmatchings" / name / f"{func}.s"
        if not s.exists():
            sys.exit(f"{s.relative_to(ROOT)} missing: run tools/dock python3 tools/configure.py")
        total += int(re.search(r"^nonmatching \S+, (0x[0-9A-Fa-f]+)", s.read_text(), re.M).group(1), 16)
    return total


def main():
    rows = configure.load_splits()
    groups = {"game": [0, 0, 0, 0], "middleware": [0, 0, 0, 0], "sdk": [0, 0, 0, 0]}
    done = []
    for i, row in enumerate(rows):
        start, name = row[0], row[4]
        end = rows[i + 1][0] if i + 1 < len(rows) else TEXT_END
        group = "sdk" if name.startswith("sdk/") else "middleware" if name.startswith("mw/") else "game"
        g = groups[group]
        g[0] += 1
        g[2] += end - start
        src = ROOT / "src" / f"{name}.cpp"
        if src.exists():
            size = end - start - asm_bytes(name, src)
            g[1] += 1
            g[3] += size
            done.append((name, size, end - start))
    print(f"{'':12} {'files':>12} {'.text bytes':>24}")
    for group, (files, files_done, size, size_done) in groups.items():
        pct = 100 * size_done / size if size else 0
        print(f"{group:12} {files_done:5} / {files:<5} {size_done:9,} / {size:<9,} {pct:6.2f}%")
    print("\ndecompiled:", ", ".join(f"{n} ({s:,} B)" if s == t else f"{n} ({s:,} of {t:,} B)"
                                     for n, s, t in done) or "none")


if __name__ == "__main__":
    main()
