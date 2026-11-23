#!/usr/bin/env python3
"""Count raw-offset accesses in matched code and refuse new ones.

    tools/.venv/bin/python tools/offset_check.py                    # all files, against the baseline
    tools/.venv/bin/python tools/offset_check.py unk/MnuDiary       # some files
    tools/.venv/bin/python tools/offset_check.py --list unk/MnuDiary  # and print each access
    tools/.venv/bin/python tools/offset_check.py --update [<file>...] # write the baseline

Rule (CLAUDE.md, "Typed members"): matched code reads and writes fields by
name (`obj->m_radius`), never by a fixed offset (`M2C_FIELD(obj, float *,
0x58)`, `*(float *)((char *)obj + 0x58)`). An unknown field gets a named
member in the class's header (`int m_unk58;`), never an offset in the code.

What counts, outside `#ifdef NON_MATCHING` blocks (attempts may still have
them; converting them is part of retrying):
- a use of M2C_FIELD(...);
- a cast of a byte-pointer sum: `((char *)x + 0x58)`, `((u8 *)x + 88)`.

config/offset_check.tsv holds each file's count when it was last updated:
code matched before the rule has many (2,122 on 2026-11-23), paid down
over time. A file with more than its baseline fails (exit 1);
tools/merge_worker.sh, tools/verify_change.py and tools/cpp_perm_queue.py
run it on the files they touch, so the count only goes down.
"""
import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "src"
BASELINE = ROOT / "config/offset_check.tsv"
PATTERNS = [
    re.compile(r"\bM2C_FIELD\("),
    re.compile(r"\(\s*(?:unsigned\s+)?(?:char|u8|s8|unsigned char)\s*\*\s*\)\s*\(?\s*[\w.\->\[\]]+\s*\)?\s*\+\s*(?:0x[0-9A-Fa-f]+|\d+)\b"),
]


def accesses(name):
    """(line number, line) of each raw-offset access in matched code."""
    out = []
    depth = 0           # inside #ifdef NON_MATCHING (nested #if counted)
    for n, line in enumerate((SRC / f"{name}.cpp").read_text(encoding="utf8", errors="replace").splitlines(), 1):
        s = line.strip()
        if depth:
            if s.startswith("#if"):
                depth += 1
            elif s.startswith("#endif"):
                depth -= 1
            elif s.startswith("#else") and depth == 1:
                depth = 0
            continue
        if s.startswith("#ifdef NON_MATCHING") or s.startswith("#if defined(NON_MATCHING)"):
            depth = 1
            continue
        if s.startswith("#define") or s.startswith("//"):
            continue
        k = sum(len(p.findall(line)) for p in PATTERNS)
        out += [(n, s)] * k
    return out


def all_names():
    return sorted(p.relative_to(SRC).with_suffix("").as_posix() for p in SRC.rglob("*.cpp"))


def load_baseline():
    base = {}
    if BASELINE.exists():
        for l in BASELINE.read_text(encoding="utf8").splitlines():
            if l and not l.startswith("#"):
                f, c = l.split("\t")
                base[f] = int(c)
    return base


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("files", nargs="*", help="src/ paths without .cpp (default: all)")
    ap.add_argument("--update", action="store_true", help="write these counts as the baseline")
    ap.add_argument("--list", action="store_true", help="print each access")
    a = ap.parse_args()
    names = [f[4:] if f.startswith("src/") else f for f in a.files] or all_names()
    names = [n[:-4] if n.endswith(".cpp") else n for n in names]
    names = [n for n in names if (SRC / f"{n}.cpp").exists()]
    counts = {n: accesses(n) for n in names}
    if a.update:
        base = load_baseline()
        base.update({n: len(v) for n, v in counts.items()})
        lines = ["# file\traw-offset accesses in matched code (tools/offset_check.py --update)"]
        lines += [f"{f}\t{c}" for f, c in sorted(base.items()) if c]
        BASELINE.write_text("\n".join(lines) + "\n", encoding="utf8", newline="\n")
        print(f"baseline: {sum(base.values())} accesses in {sum(1 for c in base.values() if c)} files")
        return
    base = load_baseline()
    worse = []
    for n, acc in counts.items():
        b = base.get(n, 0)
        if a.list:
            for ln, s in acc:
                print(f"  src/{n}.cpp:{ln}: {s[:110]}")
        if len(acc) > b:
            worse.append(n)
            print(f"WORSE {n}: {len(acc)} raw-offset accesses in matched code (baseline {b}); use typed members")
        elif len(acc) < b:
            print(f"better {n}: {len(acc)} (baseline {b}); run --update {n}")
    total = sum(len(v) for v in counts.values())
    print(f"offset check: {total} raw-offset accesses in matched code, {len(names)} files"
          + (f"; {len(worse)} worse" if worse else ", none worse"))
    sys.exit(1 if worse else 0)


if __name__ == "__main__":
    main()
