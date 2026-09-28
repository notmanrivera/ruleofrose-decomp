#!/usr/bin/env python3
"""Decompilation progress: which files are C++ and how much code they cover.

    tools/.venv/bin/python tools/progress.py

A file counts as decompiled when src/<file>.cpp exists; the matching build
(tools/dock ninja) is what proves it matches. Sizes are .text bytes from
config/splits.tsv; the SDK region is reported apart because the port
replaces those libraries instead of decompiling them.
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
TEXT_END = 0x00280E88


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
        if (ROOT / "src" / f"{name}.cpp").exists():
            g[1] += 1
            g[3] += end - start
            done.append((name, end - start))
    print(f"{'':12} {'files':>12} {'.text bytes':>24}")
    for group, (files, files_done, size, size_done) in groups.items():
        pct = 100 * size_done / size if size else 0
        print(f"{group:12} {files_done:5} / {files:<5} {size_done:9,} / {size:<9,} {pct:6.2f}%")
    print("\ndecompiled:", ", ".join(f"{n} ({s:,} B)" for n, s in done) or "none")


if __name__ == "__main__":
    main()
