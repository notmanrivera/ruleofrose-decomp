#!/usr/bin/env python3
"""Compile one source file and compare it with the original, section by section.

    tools/.venv/bin/python tools/match.py bed/bedsubmode          # summary
    tools/.venv/bin/python tools/match.py bed/bedsubmode --diff   # side-by-side for mismatches

The file's original ranges come from config/splits.tsv. Functions are
compared in order: the Nth function in the object against the code at the
file's start plus the sizes of the N-1 before it, so a whole-file decomp
lines up naturally. Fields the linker fills in (jump targets, %hi/%lo
halves, 32-bit pointers in data) are masked out. Exit status 0 = the whole
object matches.

Partial files (still with INCLUDE_ASM) are fine: their asm functions are
listed as "asm" (splat's `nonmatching` macro leaves a <name>.NON_MATCHING
symbol) and their .data/.bss stay in asm, so the object must have none.

Compiles inside the ror-build image from src/, so __FILE__ is the original
relative path (e.g. "bed/bedsubmode.cpp") that the game's asserts contain.
"""
import argparse
import shutil
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402  (flags and split table)

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x00100000
MASK = {2: 0, 4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000}  # R_MIPS_32, 26, HI16, LO16


def docker():
    for c in ("docker", str(Path.home() / ".docker/bin/docker")):
        if shutil.which(c):
            return shutil.which(c)
    sys.exit("docker not found")


def compile_file(name, source=None, extra=""):
    out = ROOT / f"build/match/{name}.o"
    out.parent.mkdir(parents=True, exist_ok=True)
    src = f"{name}.cpp" if source is None else f"../{Path(source).resolve().relative_to(ROOT)}"
    cmd = (f"cd src && ee-cc {configure.COMPILER} {configure.CFLAGS.replace('-Isrc', '-I.').replace('-Iinclude', '-I../include')} "
           f"{extra} -c {src} -o ../{out.relative_to(ROOT)}")
    r = subprocess.run([docker(), "run", "--rm", "--platform", "linux/amd64", "-v", f"{ROOT}:/work",
                        "-w", "/work", "ror-build", "sh", "-c", cmd], capture_output=True, text=True)
    if r.returncode:
        sys.exit(r.stdout + r.stderr)
    if r.stderr.strip():
        print(r.stderr.strip())
    return out


def ranges(name):
    """Original [start, end) of each section for this file, from splits.tsv."""
    rows = configure.load_splits()
    cols = {".text": 0, ".rodata": 1, ".data": 2, ".bss": 3}
    out = {}
    for sec, col in cols.items():
        starts = [r[col] for r in rows if r[col] is not None]
        mine = next((r[col] for r in rows if r[4] == name), None)
        if mine is not None:
            later = [s for s in starts if s > mine]
            out[sec] = (mine, min(later) if later else None)
    return out


def section_words(elf, name):
    sec = elf.get_section_by_name(name)
    if sec is None:
        return None, {}
    masks = {}
    for rel_name in (f".rel{name}", f".rela{name}"):
        rel = elf.get_section_by_name(rel_name)
        if isinstance(rel, RelocationSection):
            for r in rel.iter_relocations():
                masks[r["r_offset"]] = MASK.get(r["r_info_type"], 0xFFFFFFFF)
    return sec, masks


def functions(elf):
    """[(offset, size, name, from_asm)] of the object's .text."""
    text_idx = elf.get_section_index(".text")
    syms = [s for s in elf.get_section_by_name(".symtab").iter_symbols() if s["st_shndx"] == text_idx]
    asm = {s.name.removesuffix(".NON_MATCHING") for s in syms if s.name.endswith(".NON_MATCHING")}
    fns = [(s["st_value"], s["st_size"], s.name, s.name in asm) for s in syms
           if s["st_info"]["type"] == "STT_FUNC" and not s.name.endswith(".NON_MATCHING")]
    return sorted(fns)


def disasm(word, pc):
    import rabbitizer
    return rabbitizer.Instruction(word, vram=pc, category=rabbitizer.InstrCategory.R5900).disassemble()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name", help="file name as in config/splits.tsv, e.g. bed/bedsubmode")
    ap.add_argument("--diff", action="store_true", help="show mismatching functions side by side")
    ap.add_argument("--src", help="compile this file instead of src/<name>.cpp (variant testing)")
    ap.add_argument("--extra", default="", help="extra compiler flags (flag experiments)")
    a = ap.parse_args()
    name = a.name.removeprefix("src/").removesuffix(".cpp")

    rom = (ROOT / "build/SLUS_214.48.rom").read_bytes()
    obj = compile_file(name, a.src, a.extra)
    rng = ranges(name)
    partial = configure.is_partial(Path(a.src) if a.src else ROOT / "src" / f"{name}.cpp")
    if partial:
        # .data/.bss stay in asm until the file has no INCLUDE_ASM left
        rng = {k: v for k, v in rng.items() if k not in (".data", ".bss")}
    ok = True
    n_asm = 0
    with open(obj, "rb") as f:
        elf = ELFFile(f)

        # .text, function by function
        text, masks = section_words(elf, ".text")
        data = text.data() if text else b""
        start = rng[".text"][0]
        print(f"{name}  (.text at 0x{start:08X})")
        for off, size, fname, from_asm in functions(elf):
            n_asm += from_asm
            bad = []
            for o in range(off, off + size, 4):
                mine = int.from_bytes(data[o:o + 4], "little")
                want = int.from_bytes(rom[start + o - BASE:start + o - BASE + 4], "little")
                m = masks.get(o, 0xFFFFFFFF)
                if (mine & m) != (want & m):
                    bad.append((o, mine, want))
            status = ("asm" if from_asm else "MATCH") if not bad else f"{len(bad)}/{size // 4} differ"
            ok &= not bad
            print(f"  0x{start + off:08X} {fname:40} {size:#6x}  {status}")
            if bad and a.diff:
                for o in range(off, off + size, 4):
                    mine = int.from_bytes(data[o:o + 4], "little")
                    want = int.from_bytes(rom[start + o - BASE:start + o - BASE + 4], "little")
                    mark = "*" if any(o == b[0] for b in bad) else " "
                    print(f"    {mark} {disasm(want, start + o):38} | {disasm(mine, start + o)}")
        end = rng[".text"][1]
        if end is not None and len(data) != end - start:
            ok = False
            print(f"  .text size 0x{len(data):X}, original file spans 0x{end - start:X}")

        # .rodata / .data: bytes, relocations masked; .bss: size
        for sec_name in (".rodata", ".data"):
            sec, masks = section_words(elf, sec_name)
            size = sec.data_size if sec else 0
            if sec_name not in rng:
                if size:
                    ok = False
                    print(f"  {sec_name}: object has 0x{size:X} bytes, "
                          f"{'still in asm (partial file)' if partial else 'original file has none'}")
                continue
            lo, hi = rng[sec_name]
            want = rom[lo - BASE:(hi or lo + size) - BASE]
            mine = sec.data() if sec else b""
            diffs = sum(1 for o in range(0, min(len(mine), len(want)) & ~3, 4)
                        if (int.from_bytes(mine[o:o + 4], "little") ^ int.from_bytes(want[o:o + 4], "little"))
                        & masks.get(o, 0xFFFFFFFF))
            pad = want[len(mine):]
            size_ok = len(mine) <= len(want) and not any(pad) and len(want) - len(mine) < 16
            ok &= diffs == 0 and size_ok
            print(f"  {sec_name}: 0x{len(mine):X} bytes vs 0x{len(want):X}, "
                  f"{'MATCH' if diffs == 0 and size_ok else f'{diffs} words differ'}")
        bss = elf.get_section_by_name(".bss")
        if bss is not None and bss["sh_size"] and ".bss" not in rng:
            ok = False
            print(f"  .bss: object has 0x{bss['sh_size']:X} bytes, "
                  f"{'still in asm (partial file)' if partial else 'original file has none'}")
        elif ".bss" in rng:
            lo, hi = rng[".bss"]
            size = bss["sh_size"] if bss is not None else 0
            print(f"  .bss: 0x{size:X} bytes vs 0x{(hi or lo) - lo:X}")
            ok &= hi is not None and 0 <= (hi - lo) - size < 16

    if not ok:
        print("NOT MATCHING")
    elif n_asm:
        print(f"OK: object matches ({n_asm} functions still INCLUDE_ASM)")
    elif partial:
        print("OK: object matches (INCLUDE_RODATA and .data/.bss still asm)")
    else:
        print("OK: whole object matches")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
