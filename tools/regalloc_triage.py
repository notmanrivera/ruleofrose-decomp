#!/usr/bin/env python3
"""Sort the NON_MATCHING attempts by kind of difference (no AI).

For every file with NON_MATCHING attempts, compiles it with -DNON_MATCHING
through tools/match.py --diff and looks at each attempt's differing lines:

- regs:   same instructions in the same order, only register numbers differ
          (the cases tools/regalloc.py is for);
- order:  the same multiset of instructions, in another order (scheduling);
- other:  different instructions or sizes.

    tools/.venv/Scripts/python.exe tools/regalloc_triage.py            # all files
    tools/.venv/Scripts/python.exe tools/regalloc_triage.py unk/MnuPBook

Writes build/regalloc_triage.tsv (file, function, kind, differing lines,
size) and prints the "regs" ones, smallest first. Progress in
build/workers/regalloc-triage.log.
"""
import re
import subprocess
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LOG = ROOT / "build/workers/regalloc-triage.log"
OUT = ROOT / "build/regalloc_triage.tsv"
HEAD = re.compile(r"^  0x([0-9A-Fa-f]{8}) (\S+)\s+0x([0-9a-f]+)\s+(.*)$")
ROW = re.compile(r"^    ([* ]) (.*?)\s*\| (.*)$")


def mnem(s):
    return s.split()[0] if s.split() else ""


def norm(s):
    """An instruction with its registers blanked out."""
    s = s.split("#")[0]
    return re.sub(r"\$\w+", "$r", " ".join(s.split()))


def classify(rows):
    ours = [a for _, a, _ in rows]
    game = [b for _, _, b in rows]
    if len(ours) != len(game):
        return "other"
    if [norm(a) for a in ours] == [norm(b) for b in game]:
        return "regs"
    if Counter(norm(a) for a in ours) == Counter(norm(b) for b in game):
        return "order"
    return "other"


def triage(name):
    p = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), name, "--diff",
                        "--extra=-DNON_MATCHING"], cwd=ROOT, capture_output=True, text=True)
    out, cur, rows = [], None, []
    for ln in p.stdout.splitlines() + ["  0x00000000 END 0x0 x"]:
        h = HEAD.match(ln)
        if h:
            if cur and rows:
                out.append((name, cur[1], classify(rows), cur[2], cur[0]))
            st = h.group(4)
            cur = (int(h.group(3), 16), h.group(2), st) if "differ" in st else None
            rows = []
            continue
        r = ROW.match(ln)
        if cur and r:
            rows.append((r.group(1), r.group(2).strip(), r.group(3).strip()))
    return [(n, fn, kind, st, size) for n, fn, kind, st, size in out]


def main():
    names = sys.argv[1:] or sorted(
        str(p.relative_to(ROOT / "src").with_suffix("")).replace("\\", "/")
        for p in (ROOT / "src").rglob("*.cpp") if "#ifdef NON_MATCHING" in p.read_text(errors="replace"))
    LOG.parent.mkdir(parents=True, exist_ok=True)
    allrows = []
    with open(LOG, "w") as log:
        for k, name in enumerate(names, 1):
            got = triage(name)
            allrows += got
            log.write(f"[{k}/{len(names)}] {name}: {sum(r[2] == 'regs' for r in got)} regs, "
                      f"{sum(r[2] == 'order' for r in got)} order, {sum(r[2] == 'other' for r in got)} other\n")
            log.flush()
    OUT.write_text("file\tfunction\tkind\tstatus\tsize\n"
                   + "".join(f"{n}\t{fn}\t{kind}\t{st}\t{size}\n" for n, fn, kind, st, size in allrows))
    c = Counter(r[2] for r in allrows)
    print(f"{len(allrows)} attempts: {c['regs']} register-only, {c['order']} order-only, {c['other']} other")
    for n, fn, kind, st, size in sorted((r for r in allrows if r[2] == "regs"), key=lambda r: r[4]):
        print(f"  {n} {fn} ({size} B): {st}")


if __name__ == "__main__":
    main()
