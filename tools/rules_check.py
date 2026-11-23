#!/usr/bin/env python3
"""Readability rules for matched code: count the debts, refuse new ones.

    tools/.venv/bin/python tools/rules_check.py                      # all files, against the baseline
    tools/.venv/bin/python tools/rules_check.py unk/MnuDiary         # some files
    tools/.venv/bin/python tools/rules_check.py --list unk/MnuDiary  # and print each one
    tools/.venv/bin/python tools/rules_check.py --update [<file>...] # write the baseline

Two counts per file, both outside `#ifdef NON_MATCHING` blocks (attempts
may still break them; fixing that is part of retrying):

1. Raw offsets (CLAUDE.md, "typed members"): matched code reads and writes
   fields by name (`obj->m_radius`), never by a fixed offset
   (`M2C_FIELD(obj, float *, 0x58)`, `*(float *)((char *)obj + 0x58)`). An
   unknown field gets a member named by its offset (`int m_unk58;`) in the
   class's header. Counted: each M2C_FIELD(...) use, and each cast of a
   byte-pointer sum (`(char *)x + 0x58`).
2. Alias declarations (CLAUDE.md, "one declaration per symbol"): an
   `extern` giving a game symbol another name, `extern "C" int
   Xiii_func_001E7D7C(int, int) asm("func_001E7D7C");` or `extern int
   D_x_v2 asm("D_007812C0");`. Declare the symbol under its own name with
   its real types (`extern "C" int func_001E7D7C(MnuStock *, int);`),
   once, ideally in the owning file's header: two declarations that
   disagree then fail to compile instead of hiding a wrong type. Library
   functions come from their headers (<sdk/string.h> for memset).

config/rules_check.tsv holds each file's counts when last updated (code
matched before the rules has many; 2026-11-23: 2,395 raw offsets in 74
files), paid down over time. A file with more of either than its baseline
fails (exit 1). tools/merge_worker.sh, tools/verify_change.py and
tools/cpp_perm_queue.py run it on the files they touch, so the counts only
go down; after paying some down, `--update <file>`.
"""
import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "src"
BASELINE = ROOT / "config/rules_check.tsv"
OFFSET = [
    re.compile(r"\bM2C_FIELD\("),
    re.compile(r"\(\s*(?:unsigned\s+)?(?:char|u8|s8|unsigned char)\s*\*\s*\)\s*\(?\s*[\w.\->\[\]]+\s*\)?"
               r"\s*\+\s*(?:0x[0-9A-Fa-f]+|\d+)\b"),
]
ALIAS = re.compile(r'^\s*extern\b[^;]*?\b(\w+)\s*(?:\([^;]*\))?\s*(?:\[[^\]]*\])?\s*asm\("([^"]+)"\)\s*;')


def scan(name):
    """([(line, text)] raw offsets, [(line, text)] alias declarations) outside NON_MATCHING."""
    offs, alis = [], []
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
        offs += [(n, s)] * sum(len(p.findall(line)) for p in OFFSET)
        m = ALIAS.match(line)
        if m and m.group(1) != m.group(2):
            alis.append((n, s))
    return offs, alis


def accesses(name):
    return scan(name)[0]


def aliases(name):
    return scan(name)[1]


def load_baseline():
    """{file: (raw offsets, alias declarations)}"""
    base = {}
    if BASELINE.exists():
        for l in BASELINE.read_text(encoding="utf8").splitlines():
            if l and not l.startswith("#"):
                w = l.split("\t")
                base[w[0]] = (int(w[1]), int(w[2]) if len(w) > 2 else 0)
    return base


def worse(name, base=None):
    """What this file breaks beyond its baseline, as text ('' = fine)."""
    base = load_baseline() if base is None else base
    o, a = scan(name)
    bo, ba = base.get(name, (0, 0))
    out = []
    if len(o) > bo:
        out.append(f"{len(o)} raw offsets (baseline {bo}): use typed members")
    if len(a) > ba:
        out.append(f"{len(a)} alias declarations (baseline {ba}): declare symbols under their own names")
    return "; ".join(out)


def all_names():
    return sorted(p.relative_to(SRC).with_suffix("").as_posix() for p in SRC.rglob("*.cpp"))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("files", nargs="*", help="src/ paths without .cpp (default: all)")
    ap.add_argument("--update", action="store_true", help="write these counts as the baseline")
    ap.add_argument("--list", action="store_true", help="print each offset and alias")
    a = ap.parse_args()
    names = [f[4:] if f.startswith("src/") else f for f in a.files] or all_names()
    names = [n[:-4] if n.endswith(".cpp") else n for n in names]
    names = [n for n in names if (SRC / f"{n}.cpp").exists()]
    counts = {n: scan(n) for n in names}
    base = load_baseline()
    if a.update:
        base.update({n: (len(o), len(al)) for n, (o, al) in counts.items()})
        lines = ["# file\traw offsets\talias declarations, in matched code (tools/rules_check.py --update)"]
        lines += [f"{f}\t{o}\t{al}" for f, (o, al) in sorted(base.items()) if o or al]
        BASELINE.write_text("\n".join(lines) + "\n", encoding="utf8", newline="\n")
        print(f"baseline: {sum(o for o, _ in base.values())} raw offsets, "
              f"{sum(al for _, al in base.values())} alias declarations")
        return
    bad = []
    for n, (o, al) in counts.items():
        if a.list:
            for ln, s in o:
                print(f"  offset src/{n}.cpp:{ln}: {s[:105]}")
            for ln, s in al:
                print(f"  alias  src/{n}.cpp:{ln}: {s[:105]}")
        w = worse(n, base)
        bo, ba = base.get(n, (0, 0))
        if w:
            bad.append(n)
            print(f"WORSE {n}: {w}")
        elif len(o) < bo or len(al) < ba:
            print(f"better {n}: {len(o)} offsets, {len(al)} aliases (baseline {bo}, {ba}); run --update {n}")
    print(f"rules check: {sum(len(o) for o, _ in counts.values())} raw offsets, "
          f"{sum(len(al) for _, al in counts.values())} alias declarations in matched code, {len(names)} files"
          + (f"; {len(bad)} worse" if bad else ", none worse"))
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
