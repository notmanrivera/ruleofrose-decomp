#!/usr/bin/env python3
"""Fix the .rodata alignment that keeps a matching function's object from
matching (regalloc_triage kind "fn_match"), the way game/gamsnd
func_001E0C2C and unk/EffLight2 func_0017653C were fixed by hand.

    (in a worktree of its own: it runs configure.py there)
    tools/.venv/Scripts/python.exe tools/rodata_align_fix.py unk/00166AD0 func_001685C0
    tools/.venv/Scripts/python.exe tools/rodata_align_fix.py --all        # every fn_match in build/regalloc_triage.tsv
    ... --apply                                                          # also work.py --done (then: full build, commit)

The attempt is compiled in place of its INCLUDE_ASM (as work.py does) and
its object's .rodata compared with the game's, relocated words skipped. At
the first difference: when the game has zero bytes there and our bytes
come right after them (shifted by 4, 8 or 12), the INCLUDE_RODATA piece
starting at that offset needs a larger .align; a line goes into
config/rodata_align_manual.tsv, configure.py runs, and the check repeats
(up to 4 fixes). The worktree's config/ is changed: merge by hand
(merge_worker.sh refuses config/), after a full build.
"""
import argparse
import os
import re
import subprocess
import sys
from pathlib import Path

os.environ.setdefault("ROR_QUIET_HI16", "1")
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402
import regalloc_triage  # noqa: E402

ALIGN = ROOT / "config" / "rodata_align_manual.tsv"


def compile_attempt(name, fn):
    """(report lines, object path) with the attempt in place, or (None, why)."""
    text = (ROOT / "src" / f"{name}.cpp").read_text(encoding="utf8")
    m = next((m for m in regalloc_triage.NM.finditer(text) if m.group(2) == fn), None)
    if not m:
        return None, "no NON_MATCHING attempt"
    tmp = ROOT / "build" / "triage" / f"align_{fn}.cpp"
    tmp.parent.mkdir(parents=True, exist_ok=True)
    tmp.write_text(text[:m.start()] + m.group(1) + text[m.end():], encoding="utf8", newline="\n")
    try:
        _, report = match.compare(name, source=str(tmp))
    except match.CompileError as e:
        return None, "does not compile: " + str(e)[-160:]
    return report, ROOT / "build" / "match" / f"{name}.{tmp.stem}.o"


def first_shift(name, obj):
    """(offset, shift, symbol) of the first .rodata difference that is the
    game's zero padding, or (offset, None, why)."""
    from elftools.elf.elffile import ELFFile
    with open(obj, "rb") as f:
        e = ELFFile(f)
        sec = e.get_section_by_name(".rodata")
        ours = sec.data() if sec else b""
        idx = e.get_section_index(".rodata")
        relocated = set()
        for s in e.iter_sections():
            if s.name in (".rel.rodata", ".rela.rodata"):
                relocated |= {r["r_offset"] + k for r in s.iter_relocations() for k in range(4)}
        syms = {}
        for s in e.get_section_by_name(".symtab").iter_symbols():
            if s["st_shndx"] == idx and s.name and not s.name.endswith(".NON_MATCHING"):
                syms.setdefault(s["st_value"], s.name)
    lo, hi = match.ranges(name)[".rodata"]
    rom = match.rom_bytes(match.stamp(ROOT / "build/SLUS_214.48.rom"))
    want = rom[lo - match.BASE:(hi or lo + len(ours)) - match.BASE]
    d = next((i for i in range(min(len(ours), len(want))) if i not in relocated and ours[i] != want[i]), None)
    if d is None:
        return None, None, "no difference outside relocations"
    for shift in (4, 8, 12):
        if any(want[d:d + shift]):
            continue
        n = min(32, len(ours) - d, len(want) - d - shift)
        if n > 0 and all(ours[d + k] == want[d + shift + k] or d + k in relocated for k in range(n)):
            sym = syms.get(d)
            return d, shift, sym or f"no symbol starts at +{d:#x}"
    return d, None, f"first difference at +{d:#x} is not the game's zero padding"


def align_for(addr, shift):
    """The smallest .align (power of two) that moves addr to addr + shift."""
    for p in range(2, 5):
        a = 1 << p
        if (addr + a - 1) & -a == addr + shift:
            return p
    return None


def configure():
    r = subprocess.run(["sh", str(ROOT / "tools/dock"), "python3", "tools/configure.py"], cwd=ROOT,
                       capture_output=True, text=True)
    return r.returncode == 0


def fix(name, fn, apply=False):
    for step in range(4):
        report, obj = compile_attempt(name, fn)
        if report is None:
            return f"{name} {fn}: {obj}"
        fline = next((l for l in report if l.startswith("  0x") and l.split()[1] == fn), "")
        if "MATCH" not in fline:
            return f"{name} {fn}: the function itself does not match ({fline.split(None, 3)[-1] if fline else '?'})"
        if any(l.startswith("OK") for l in report):
            if apply:
                subprocess.run([sys.executable, "tools/work.py", name, fn], cwd=ROOT, capture_output=True)
                d = subprocess.run([sys.executable, "tools/work.py", name, fn, "--done"], cwd=ROOT,
                                   capture_output=True, text=True)
                return f"{name} {fn}: MATCH after {step} fix(es)" + ("; written to src/" if d.returncode == 0 else
                                                                    "; work.py --done refused")
            return f"{name} {fn}: MATCH after {step} fix(es) (--apply to write it)"
        d, shift, sym = first_shift(name, obj)
        if shift is None or not sym or sym.startswith("no symbol"):
            return f"{name} {fn}: {sym}"
        lo = match.ranges(name)[".rodata"][0]
        p = align_for(lo + d, shift)
        if p is None:
            return f"{name} {fn}: {sym} at {lo + d:#x} would need a shift of {shift} no .align gives"
        line = (f"{sym}\t{p}\t{name}: {sym} at {lo + d + shift:#x} is {1 << p}-aligned in the game ({shift} zero "
                f"bytes before it); once {fn} compiles from C++ the piece lands {shift} bytes early "
                f"(tools/rodata_align_fix.py)\n")
        text = ALIGN.read_text(encoding="utf8")
        if re.search(rf"^{re.escape(sym)}\t", text, re.M):
            return f"{name} {fn}: {sym} already has a manual .align and still lands early"
        ALIGN.write_text(text + line, encoding="utf8", newline="\n")
        print(f"  {name} {fn}: {sym} .align {p}; configure", flush=True)
        if not configure():
            return f"{name} {fn}: configure.py failed"
    return f"{name} {fn}: still not matching after 4 fixes"


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name", nargs="?")
    ap.add_argument("function", nargs="?")
    ap.add_argument("--all", action="store_true", help="every fn_match of build/regalloc_triage.tsv")
    ap.add_argument("--apply", action="store_true", help="on a whole-object match, work.py --done")
    a = ap.parse_args()
    if a.all:
        tsv = ROOT / "build" / "regalloc_triage.tsv"
        jobs = [tuple(l.split("\t")[:2]) for l in tsv.read_text().splitlines()[1:] if l.split("\t")[2:3] == ["fn_match"]]
    else:
        jobs = [(a.name, a.function)]
    if not match.server_up():
        match.server("start")
    for name, fn in jobs:
        print(fix(name, fn, a.apply), flush=True)


if __name__ == "__main__":
    main()
