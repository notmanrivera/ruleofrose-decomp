#!/usr/bin/env python3
"""Show how cc1 allocates registers in one function (research item R20).

Most NON_MATCHING attempts differ from the game only in which register a
value gets. ee-gcc 2.96 decides that from each pseudo register's priority:
roughly floor(log2(refs)) * refs * size / live_length (global.c, local-alloc
uses the same idea per block). This compiles the file (or a variant of it)
with -dlg, reads cc1's local-alloc (.lreg) and global-alloc (.greg) dumps for
the function and prints every pseudo with its hard register, references,
live length and priority, highest first: to swap two registers, the pseudo
that should win needs more priority (more uses, a shorter life).

    tools/.venv/Scripts/python.exe tools/regalloc.py game/gamman func_001CD044
    tools/.venv/Scripts/python.exe tools/regalloc.py unk/MnuPBook func_00196EFC --nm
    tools/.venv/Scripts/python.exe tools/regalloc.py bed/bedsubmode push__10BedSubMode --src build/try.cpp

The function is found by its `;; Function` header (cc1 prints the demangled
C++ name): an extern "C" name as is, a mangled name by its method part.
--nm compiles with -DNON_MATCHING (attempts still linked from asm).
Written for this project (the idea comes from gt4-decomp's MIT knowledge
notes; no code copied from the GPL rac1/rac3 tools).
"""
import argparse
import math
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
NAMES = {2: "v0", 3: "v1", 29: "sp", 30: "s8", 31: "ra", 24: "t8", 25: "t9", 28: "gp", 1: "at"}
NAMES.update({i: f"a{i - 4}" for i in range(4, 8)})
NAMES.update({i: f"t{i - 8}" for i in range(8, 16)})
NAMES.update({i: f"s{i - 16}" for i in range(16, 24)})
NAMES.update({i: f"f{i - 32}" for i in range(32, 64)})
REG = re.compile(r"^Register (\d+) used (\d+) times? across (\d+) insns?( in block \d+)?;(.*)$")


def hard(n):
    return "$" + NAMES.get(n, str(n))


def section(text, func):
    """The dump's part for one function."""
    parts = re.split(r"^;; Function (.*)$", text, flags=re.M)
    heads = parts[1::2]
    method = func.split("__")[0] if "__" in func and not func.startswith("__") else None
    for i, h in enumerate(heads):
        if re.search(rf"(^|\W){re.escape(func)}(\W|$)", h) or (method and f"::{method} (" in h):
            return h, parts[2 + 2 * i]
    sys.exit(f"no ';; Function' for {func}; functions here: " + "; ".join(heads))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name", help="file as in config/splits.tsv, e.g. game/gamman")
    ap.add_argument("function")
    ap.add_argument("--src", help="compile this variant of the file instead")
    ap.add_argument("--nm", action="store_true", help="compile with -DNON_MATCHING")
    a = ap.parse_args()
    dumps = Path("build/match/dumps") / a.name
    for old in (ROOT / dumps).glob("*") if (ROOT / dumps).exists() else []:
        old.unlink()
    extra = "-dlg" + (" -DNON_MATCHING" if a.nm else "")
    match.compile_file(a.name, a.src, extra=extra, dumps=dumps.as_posix())
    lreg = next((ROOT / dumps).glob("*.lreg"), None)
    greg = next((ROOT / dumps).glob("*.greg"), None)
    if not lreg or not greg:
        sys.exit(f"cc1 left no .lreg/.greg in {dumps}")
    head, lsec = section(lreg.read_text(errors="replace"), a.function)
    _, gsec = section(greg.read_text(errors="replace"), a.function)
    disp = {}
    m = re.search(r";; Register dispositions:\n(.*?)\n\n", gsec, re.S)
    for p, h in re.findall(r"(\d+) in (\d+)", m.group(1) if m else ""):
        disp[int(p)] = int(h)
    rows = []
    for ln in lsec.splitlines():
        r = REG.match(ln)
        if not r:
            continue
        pseudo, refs, live = int(r.group(1)), int(r.group(2)), int(r.group(3))
        rest = r.group(5)
        size = int(re.search(r"(\d+) bytes", rest).group(1)) if "bytes" in rest else 4
        prio = (math.floor(math.log2(refs)) if refs > 1 else 0) * refs * size / max(live, 1)
        tags = [t for t in ("user var", "crosses") if t in rest]
        if r.group(4):
            tags.append("local" + r.group(4).replace(" in block", ""))
        if "FP_REGS" in rest:
            tags.append("float")
        rows.append((prio, pseudo, refs, live, disp.get(pseudo), ", ".join(tags)))
    print(f"{head}  ({a.name}{', NON_MATCHING' if a.nm else ''})")
    print(f"  {'pseudo':>6} {'reg':>5} {'refs':>4} {'live':>5} {'priority':>8}  notes")
    for prio, pseudo, refs, live, h, tags in sorted(rows, key=lambda r: -r[0]):
        print(f"  {pseudo:>6} {hard(h) if h is not None else 'mem':>5} {refs:>4} {live:>5} {prio:>8.2f}  {tags}")
    print(f"dumps: {dumps.as_posix()}/ (.lreg = local alloc, .greg = global alloc)")


if __name__ == "__main__":
    main()
