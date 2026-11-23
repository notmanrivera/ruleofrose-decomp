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
import os
import subprocess

os.environ.setdefault("ROR_QUIET_HI16", "1")   # before match imports fix_hi16
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


LIKELY = {"beql", "bnel", "beqzl", "bnezl", "blezl", "bgtzl", "bltzl", "bgezl", "bc1tl", "bc1fl"}
PLAIN = {m[:-1] for m in LIKELY}


def ops(s):
    """An instruction with registers and numbers blanked out (its shape)."""
    return re.sub(r"-?\b0x[0-9A-Fa-f]+\b|-?\b\d+\b", "N", norm(s))


def classify(rows):
    """(kind, detail) of one attempt's differences. kind: regs (only
    register numbers), order (same instructions, other order), likely (a
    branch-likely where the game has a plain branch, or the reverse: try
    ASM_NOTHROW on callees, a local bool, the other if shape), operands
    (same instructions, other constants or offsets: a type, field or
    constant), size (instructions missing or extra), reloc (only the
    references), other. detail: counts that help pick the lever."""
    game = [a for _, a, _ in rows]          # match.py --diff prints game | ours
    ours = [b for _, _, b in rows]
    diff = [(a, b) for m, a, b in rows if m == "*"]
    likely = sum(1 for a, b in diff if mnem(a) != mnem(b) and
                 ((mnem(a) in LIKELY and mnem(b) in PLAIN | LIKELY) or (mnem(b) in LIKELY and mnem(a) in PLAIN | LIKELY))
                 and mnem(a).rstrip("l") == mnem(b).rstrip("l"))
    fpr = all(re.findall(r"\$f\d+", a) != re.findall(r"\$f\d+", b) for a, b in diff) and diff
    nlen = sum(1 for g in game if g) - sum(1 for o in ours if o)
    detail = []
    if likely:
        detail.append(f"likely:{likely}")
    if nlen:
        detail.append(f"size:{-nlen:+d}")
    if fpr:
        detail.append("fpr")
    detail.append(f"rows:{len(diff)}")
    detail = " ".join(detail)
    if nlen == 0 and [norm(a) for a in game] == [norm(b) for b in ours]:
        return "regs", detail
    if nlen == 0 and Counter(norm(a) for a in game) == Counter(norm(b) for b in ours):
        return "order", detail
    if likely and len(diff) - likely <= 3:
        return "likely", detail
    if nlen == 0 and [ops(a) for a in game] == [ops(b) for b in ours]:
        return "operands", detail
    if not diff:
        return "reloc", detail
    if nlen:
        return "size", detail
    return "other", detail


NM = re.compile(r"(?:^// NON_MATCHING[^\n]*\n)?^#ifdef NON_MATCHING\n((?:(?!^#ifdef NON_MATCHING).)*?)^#else\n"
                r'INCLUDE_ASM\("asm/nonmatchings/[^"]+", (\w+)\);\n#endif\n', re.S | re.M)


def triage(name):
    """Each NON_MATCHING attempt of the file compiled the way tools/work.py
    checks it (the attempt in place of its INCLUDE_ASM, no -DNON_MATCHING:
    that would also empty ASM_NOTHROW and change the code), one at a time."""
    sys.path.insert(0, str(ROOT / "tools"))
    import match
    text = (ROOT / "src" / f"{name}.cpp").read_text(encoding="utf8", errors="replace")
    out = []
    tmp = ROOT / "build" / "triage" / f"tri{abs(hash(name)) % 10**8}.cpp"
    tmp.parent.mkdir(parents=True, exist_ok=True)
    for m in NM.finditer(text):
        fn = m.group(2)
        tmp.write_text(text[:m.start()] + m.group(1) + text[m.end():], encoding="utf8", newline="\n")
        try:
            _, report = match.compare(name, source=str(tmp), diff=True)
        except match.CompileError as e:
            # an attempt that no longer compiles (a header changed under it):
            # worth fixing before anyone tries to get it closer
            err = next((ln for ln in str(e).splitlines() if re.search(r":\d+: (?!warning)", ln)), str(e)[-120:])
            out.append((name, fn, "broken", re.sub(r"\s+", " ", err)[:160], 0, "does not compile"))
            continue
        out += parse(name, report, only=fn)
    tmp.unlink(missing_ok=True)
    return out


def parse(name, report_lines, only=None):
    out, cur, rows = [], None, []
    for ln in list(report_lines) + ["  0x00000000 END 0x0 x"]:
        h = HEAD.match(ln)
        if h:
            if cur and rows:
                kind, detail = classify(rows)
                out.append((name, cur[1], kind, cur[2], cur[0], detail))
            st = h.group(4)
            if only and h.group(2) == only and st.startswith("MATCH"):
                # an attempt kept as NON_MATCHING that matches as work.py builds it
                out.append((name, only, "fn_match", st, int(h.group(3), 16), "function matches: check the whole object with work.py (.rodata?)"))
            cur = (int(h.group(3), 16), h.group(2), st) if "differ" in st and (only is None or h.group(2) == only) else None
            rows = []
            continue
        r = ROW.match(ln)
        if cur and r:
            rows.append((r.group(1), r.group(2).strip(), r.group(3).strip()))
    return out


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
            c = Counter(r[2] for r in got)
            log.write(f"[{k}/{len(names)}] {name}: " + ", ".join(f"{v} {kd}" for kd, v in sorted(c.items())) + "\n")
            log.flush()
    # columns: the first five as before (scripts read them), the detail last
    OUT.write_text("file\tfunction\tkind\tstatus\tsize\tdetail\n"
                   + "".join(f"{n}\t{fn}\t{kind}\t{st}\t{size}\t{d}\n" for n, fn, kind, st, size, d in allrows))
    c = Counter(r[2] for r in allrows)
    print(f"{len(allrows)} attempts: " + ", ".join(f"{v} {kd}" for kd, v in c.most_common()))
    for n, fn, kind, st, size, d in sorted((r for r in allrows if r[2] in ("regs", "likely")), key=lambda r: r[4]):
        print(f"  {kind:7} {n} {fn} ({size} B): {st}  [{d}]")


if __name__ == "__main__":
    main()
