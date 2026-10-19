#!/usr/bin/env python3
"""Rank EE-GCC builds and flag sets by how closely they reproduce the game.

Compiles matching/compiler_id/candidates.cpp with every compiler in the
ror-build Docker image and every flag set below, then compares each
candidate function word by word against SLUS_214.48. Fields the linker
fills in (R_MIPS_26 jump targets, HI16/LO16 immediates) are masked out.

Usage: tools/.venv/bin/python tools/compiler_id.py [--flags "-O2 -G0" ...]
Requires: docker (image built from docker/), pyelftools in tools/.venv.
"""
import argparse
import csv
import shutil
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
import ror_symbols as R  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
SRC = "matching/compiler_id/candidates.cpp"
OUT = ROOT / "build/compiler_id"
DEFAULT_FLAGS = ["-O1 -G0", "-O2 -G0", "-O3 -G0", "-Os -G0", "-O2 -G8"]
MASK = {4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000}  # R_MIPS_26, HI16, LO16


def docker():
    for c in ("docker", str(Path.home() / ".docker/bin/docker"),
              r"C:\Program Files\Docker\Docker\resources\bin\docker.exe"):
        if shutil.which(c):
            return shutil.which(c)
    sys.exit("docker not found")


def volume_path(path):
    """Host path for `docker run -v`: docker.exe on Windows takes C:/..."""
    return str(path).replace("\\", "/")


def compile_all(flag_sets):
    if OUT.exists():
        shutil.rmtree(OUT)
    OUT.mkdir(parents=True)
    script = []
    for i, flags in enumerate(flag_sets):
        script.append(
            f'for id in $(ee-cc --list); do ee-cc $id {flags} -c {SRC} '
            f'-o build/compiler_id/$id@{i}.o 2>build/compiler_id/$id@{i}.err || true; done')
    subprocess.run([docker(), "run", "--rm", "--platform", "linux/amd64",
                    "-v", f"{volume_path(ROOT)}:/work", "-w", "/work", "ror-build", "sh", "-c", "; ".join(script)],
                   check=True)


def object_functions(path):
    """{symbol: [(word, mask), ...]} for every function in .text."""
    with open(path, "rb") as f:
        elf = ELFFile(f)
        text = elf.get_section_by_name(".text")
        data = text.data()
        masks = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection) and sec.name in (".rel.text", ".rela.text"):
                for rel in sec.iter_relocations():
                    masks[rel["r_offset"]] = MASK.get(rel["r_info_type"], 0xFFFFFFFF)
        funcs = {}
        text_idx = elf.get_section_index(".text")
        for sym in elf.get_section_by_name(".symtab").iter_symbols():
            if sym["st_info"]["type"] != "STT_FUNC" or sym["st_shndx"] != text_idx:
                continue
            start, size = sym["st_value"], sym["st_size"]
            funcs[sym.name] = [
                (int.from_bytes(data[o:o + 4], "little"), masks.get(o, 0xFFFFFFFF))
                for o in range(start, start + size, 4)]
        return funcs


def score(target, cand):
    """Number of differing instructions, counting length differences."""
    diff = abs(len(target) - len(cand))
    for t, (c, m) in zip(target, cand):
        if (t & m) != (c & m):
            diff += 1
    return diff


def show(elf, syms, obj):
    import rabbitizer

    def dis(w, pc):
        return rabbitizer.Instruction(w, vram=pc, category=rabbitizer.InstrCategory.R5900).disassemble()

    for name, cand in object_functions(obj).items():
        if name not in syms:
            continue
        addr, size = int(syms[name]["addr"], 16), int(syms[name]["size"], 16)
        target = [elf.word(addr + o) for o in range(0, size, 4)]
        print(f"\n{name}  (target | candidate, * = differs)")
        for i in range(max(len(target), len(cand))):
            t = dis(target[i], addr + 4 * i) if i < len(target) else ""
            c, m = cand[i] if i < len(cand) else (None, 0xFFFFFFFF)
            cs = dis(c, addr + 4 * i) if c is not None else ""
            bad = i >= len(target) or c is None or (target[i] & m) != (c & m)
            print(f"{'*' if bad else ' '} {t:<40} | {cs}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--flags", nargs="*", default=DEFAULT_FLAGS)
    ap.add_argument("--no-build", action="store_true", help="reuse build/compiler_id")
    ap.add_argument("--show", metavar="COMPILER@N",
                    help="side-by-side diff for one result, e.g. ee-gcc2.96@1 (N = flag set index)")
    a = ap.parse_args()
    if a.show:
        a.no_build = True

    elf = R.Elf(ROOT / "disc/SLUS_214.48")
    syms = {r["mangled"]: r for r in csv.DictReader(
        open(ROOT / "symbols/ghidra_symbols.tsv"), delimiter="\t") if r["mangled"]}

    if not a.no_build:
        compile_all(a.flags)

    if a.show:
        show(elf, syms, OUT / f"{a.show}.o")
        return

    results = []
    for obj in sorted(OUT.glob("*.o")):
        cid, idx = obj.stem.rsplit("@", 1)
        funcs = object_functions(obj)
        per = {}
        for name, cand in funcs.items():
            if name not in syms:
                continue
            addr, size = int(syms[name]["addr"], 16), int(syms[name]["size"], 16)
            target = [elf.word(addr + o) for o in range(0, size, 4)]
            per[name] = (score(target, cand), len(target))
        total = sum(d for d, _ in per.values())
        results.append((total, cid, a.flags[int(idx)], per))

    failed = sorted({p.stem for p in OUT.glob("*.err") if p.stat().st_size and
                     not (OUT / f"{p.stem}.o").exists()})
    results.sort(key=lambda r: (r[0], r[1]))
    names = sorted({n for r in results for n in r[3]})
    short = [n.split("__")[0] for n in names]
    print(f"{'diff':>4}  {'compiler':<32} {'flags':<10} " + "  ".join(f"{s:>18}" for s in short))
    for total, cid, flags, per in results:
        cells = "  ".join(f"{per[n][0]:>9}/{per[n][1]:<8}" if n in per else f"{'missing':>18}"
                          for n in names)
        print(f"{total:>4}  {cid:<32} {flags:<10} {cells}")
    for f in failed:
        print(f"compile failed: {f} (see build/compiler_id/{f}.err)")


if __name__ == "__main__":
    main()
