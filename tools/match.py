#!/usr/bin/env python3
"""Compile one source file and compare it with the original, section by section.

    tools/.venv/bin/python tools/match.py bed/bedsubmode          # summary
    tools/.venv/bin/python tools/match.py bed/bedsubmode --diff   # side-by-side for mismatches

The file's original ranges come from config/splits.tsv. The Nth function in
the object is compared with the game's Nth function, at its real address
(from splat's asm/<file>.s), so one function of the wrong size does not
shift the others. Exit status 0 = the whole object matches.

Relocations (jump targets, %hi/%lo halves, 32-bit pointers in data) are
filled in the way the linker would, with the addresses the symbols have in
the game: imported names from the last link map (build/SLUS_214.48.map, or
the symbol lists for a name added since), the object's own functions at the
game's addresses, and its .rodata/.data/.bss at the file's starts. So a call
to the wrong function, or two symbol loads swapped, do not match; each wrong
reference is listed ("reloc at +0x10: _end (0x00828E94), game 0x00081000").

Partial files (still with INCLUDE_ASM) are fine: their asm functions are
listed as "asm" (splat's `nonmatching` macro leaves a <name>.NON_MATCHING
symbol) and their .data/.bss stay in asm, so the object must have none.

Compiles inside the ror-build image from src/, so __FILE__ is the original
relative path (e.g. "bed/bedsubmode.cpp") that the game's asserts contain.
"""
import argparse
import bisect
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402  (flags and split table)

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x00100000
R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 2, 4, 5, 6
# The bits of the word each relocation type fills in.
FIELD = {R_MIPS_32: 0xFFFFFFFF, R_MIPS_26: 0x03FFFFFF, R_MIPS_HI16: 0xFFFF, R_MIPS_LO16: 0xFFFF}
LINK_MAP = ROOT / "build/SLUS_214.48.map"
# What the next link takes its names from, for names added since the last one.
SYMBOL_LISTS = ("symbols/symbol_addrs.txt", "config/symbol_addrs_manual.txt",
                "build/undefined_funcs_auto.txt", "build/undefined_syms_auto.txt")


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


def word(buf, o):
    return int.from_bytes(buf[o:o + 4], "little")


def sext(v, bits):
    v &= (1 << bits) - 1
    return v - (1 << bits) if v >> (bits - 1) else v


def plus(n):
    return f"+0x{n:X}" if n > 0 else f"-0x{-n:X}" if n < 0 else ""


def pair(hi, lo):
    """The address a %hi/%lo pair of instructions builds."""
    return (((hi & 0xFFFF) << 16) + sext(lo, 16)) & 0xFFFFFFFF


def link_symbols():
    """{name: address} for the names an object imports: the last link map,
    or the symbol lists for a name added since."""
    syms = {}
    for path in SYMBOL_LISTS:
        if (ROOT / path).exists():
            for m in re.finditer(r"^\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;",
                                 (ROOT / path).read_text(), re.M):
                syms[m.group(1)] = int(m.group(2), 16)
    if LINK_MAP.exists():
        # "0x00105650  utlIsTcc__FPCc", and linker script assignments
        # "0x00080000  _stack_size = 0x80000"
        for m in re.finditer(r"^[ \t]+0x([0-9a-f]{8,16})[ \t]+([A-Za-z_.$][\w.$]*)[ \t]*(?:=|$)",
                             LINK_MAP.read_text(errors="replace"), re.M):
            syms[m.group(2)] = int(m.group(1), 16)
    else:
        print(f"({LINK_MAP.relative_to(ROOT)} missing, run tools/dock ninja: "
              "only names in the symbol lists resolve)")
    syms.pop(".", None)  # the location counter
    return syms


def namer(syms):
    """name_of(address): the symbol there, or the nearest one below plus the
    offset; "" outside the game's memory."""
    best = {}
    for n, a in syms.items():
        if n.endswith(".NON_MATCHING") or n.startswith("main_") or n in ("_gp", "__romPos"):
            continue  # linker script bookkeeping
        auto = re.match(r"(func|D|jtbl)_[0-9A-F]+$|\.L", n) is not None
        if a not in best or (best[a][0] and not auto):
            best[a] = (auto, n)
    addrs = sorted(best)

    def name_of(v):
        i = bisect.bisect_right(addrs, v) - 1
        if i < 0 or not BASE <= v < 0x02000000:
            return ""
        return best[addrs[i]][1] + plus(v - addrs[i])
    return name_of


@dataclass
class Reloc:
    type: int
    sym: int              # symbol index: a %hi and its %lo share it
    label: str            # symbol+addend, for messages
    word: int = None      # the word as the linker writes it; None if unknown (see note)
    checked: bool = True  # False: into a section of the wrong size (see note)
    note: str = ""


def link(elf, sec_name, raw, place, syms, text_name, moved):
    """{offset: Reloc} for a section of the object, each relocated word
    filled in as the linker does it. place(section, offset) is the game
    address of a byte of the object (None if it has none); imported names
    come from syms; references into the object's sections in `moved` are
    not checked. The addends are in the words (REL): a %hi completes its
    addend with the next %lo of the same symbol in the table, which the
    assembler may have taken from another function (same symbol and addend)."""
    symtab = elf.get_section_by_name(".symtab")
    out = {}
    for rel in (elf.get_section_by_name(f".rel{sec_name}"), elf.get_section_by_name(f".rela{sec_name}")):
        if not isinstance(rel, RelocationSection):
            continue
        rels = list(rel.iter_relocations())
        lo_addend = {}  # index of a %lo -> the whole addend of the %hi it completes
        for i, r in enumerate(rels):
            o, t, si = r["r_offset"], r["r_info_type"], r["r_info_sym"]
            if t == 0:  # R_MIPS_NONE
                continue
            sym, w = symtab.get_symbol(si), word(raw, o)
            if rel.is_RELA():
                a = r["r_addend"]
            elif t == R_MIPS_26:
                a = (w & 0x3FFFFFF) << 2
                if sym["st_info"]["bind"] != "STB_LOCAL":
                    a = sext(a, 28)
            elif t == R_MIPS_HI16:
                a = (w & 0xFFFF) << 16
                j = next((j for j in range(i + 1, len(rels)) if rels[j]["r_info_type"] == R_MIPS_LO16
                          and rels[j]["r_info_sym"] == si), None)
                if j is not None:
                    a += sext(word(raw, rels[j]["r_offset"]), 16)
                    lo_addend.setdefault(j, a)
            elif t == R_MIPS_LO16:
                a = lo_addend.get(i, sext(w, 16))
            else:
                a = sext(w, 32)
            shndx = sym["st_shndx"]
            sec = elf.get_section(shndx).name if isinstance(shndx, int) and shndx else None
            if sec:  # defined in this object
                v = place(sec, sym["st_value"] + a)
            elif shndx == "SHN_ABS" or si == 0:
                v = sym["st_value"] + a
            else:
                v = None
            if v is None and sym.name in syms:
                v = syms[sym.name] + a
            label = (sym.name + plus(a) if sym.name else text_name(a) if sec == ".text"
                     else (sec or "*ABS*") + plus(a))
            rr = out[o] = Reloc(t, si, label)
            if t not in FIELD:
                rr.note = f"relocation type {t}, which match.py does not handle"
            elif v is None:
                rr.note = (f"the object's {sec}, which has no place in the game" if sec
                           else "not in the link map or the symbol lists")
            else:
                if sec in moved:
                    rr.checked = False
                    rr.note = f"not checked: {sec} has another size"
                if t == R_MIPS_26:
                    rr.word = (w & ~0x3FFFFFF) | ((v >> 2) & 0x3FFFFFF)
                elif t == R_MIPS_HI16:
                    rr.word = (w & ~0xFFFF) | (((v + 0x8000) >> 16) & 0xFFFF)
                elif t == R_MIPS_LO16:
                    rr.word = (w & ~0xFFFF) | (v & 0xFFFF)
                else:
                    rr.word = v & 0xFFFFFFFF
    return out


def check(raw, relocs, offsets, game):
    """The offsets whose word, as linked, differs from the game's: outside
    the relocated field (the instruction), and inside it or not linkable."""
    bad, rbad = set(), set()
    for o in offsets:
        r = relocs.get(o)
        mine = word(raw, o) if r is None or r.word is None else r.word
        diff = mine ^ game(o)
        field = FIELD.get(r.type, 0xFFFFFFFF) if r else 0
        if diff & ~field:
            bad.add(o)
        if r and r.checked and (r.word is None or diff & field):
            rbad.add(o)
    return bad, rbad


def reloc_lines(relocs, offsets, raw, game, pc, rbad, name_of, base):
    """One line per wrong reference among the relocations at offsets. A %hi
    and the %lo based on its register (the next ones after it) are one."""
    refs, his = {}, []
    for o in sorted(o for o in offsets if o in relocs):
        r = relocs[o]
        if r.type == R_MIPS_LO16:
            rs = (word(raw, o) >> 21) & 31
            h = next((h for h in reversed(his)
                      if relocs[h].sym == r.sym and (word(raw, h) >> 16) & 31 == rs), None)
            if h is not None:
                refs[h].append(o)
                continue
        elif r.type == R_MIPS_HI16:
            his.append(o)
        refs[o] = [o]
    lines = []
    for o, parts in refs.items():
        if rbad.isdisjoint(parts):
            continue
        r, g = relocs[o], game(o)
        if r.word is None:
            what = f"{r.label}: {r.note}"
        elif r.type in (R_MIPS_HI16, R_MIPS_LO16) and len(parts) == 1:  # half of a pair
            half = "hi" if r.type == R_MIPS_HI16 else "lo"
            what = f"%{half}({r.label}) 0x{r.word & 0xFFFF:04X}, game 0x{g & 0xFFFF:04X}"
        else:
            if r.type == R_MIPS_HI16:  # the address the pair builds, with the %lo that differs
                lo = next((p for p in parts[1:] if p in rbad), parts[1])
                ours, theirs = pair(r.word, relocs[lo].word), pair(g, game(lo))
            elif r.type == R_MIPS_26:
                top = (pc(o) + 4) & 0xF0000000
                ours, theirs = top | ((r.word & 0x3FFFFFF) << 2), top | ((g & 0x3FFFFFF) << 2)
            else:
                ours, theirs = r.word, g
            n = name_of(theirs)
            what = f"{r.label} (0x{ours:08X}), game 0x{theirs:08X}" + (f" ({n})" if n else "")
        lines.append(f"reloc at +0x{o - base:X}: {what}")
    return lines


def functions(elf):
    """[(offset, size, name, from_asm)] of the object's .text."""
    text_idx = elf.get_section_index(".text")
    syms = [s for s in elf.get_section_by_name(".symtab").iter_symbols() if s["st_shndx"] == text_idx]
    asm = {s.name.removesuffix(".NON_MATCHING") for s in syms if s.name.endswith(".NON_MATCHING")}
    fns = [(s["st_value"], s["st_size"], s.name, s.name in asm) for s in syms
           if s["st_info"]["type"] == "STT_FUNC" and not s.name.endswith(".NON_MATCHING")]
    return sorted(fns)


def original_functions(name):
    """[(address, size)] of the file's functions in the game, from splat's
    whole-file disassembly (kept for decompiled files too), or None."""
    path = ROOT / "asm" / f"{name}.s"
    if not path.exists():
        return None
    out, size = [], None
    for line in path.read_text(errors="replace").splitlines():
        m = re.match(r"nonmatching (\S+), (0x[0-9A-Fa-f]+)", line)
        if m:
            size = int(m.group(2), 16)
            continue
        m = re.match(r"\s+/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", line)
        if m and size is not None:
            out.append((int(m.group(1), 16), size))
            size = None
    return out


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
    syms = link_symbols()
    name_of = namer(syms)
    ok = True
    n_asm = 0
    with open(obj, "rb") as f:
        elf = ELFFile(f)

        # The object's .rodata/.data next to the game's bytes, and whether
        # each data section has the game's size. In one that does not, all
        # that follows the wrong piece moves, so references into it are not
        # checked (its own line below shows the difference).
        chunks, moved = {}, set()
        for sec_name in (".rodata", ".data"):
            if sec_name in rng:
                sec = elf.get_section_by_name(sec_name)
                mine = sec.data() if sec else b""
                lo, hi = rng[sec_name]
                want = rom[lo - BASE:(hi or lo + len(mine)) - BASE]
                # Zeros after the object's end are the next object's alignment
                # padding; with no bytes at all there is nothing to pad.
                size_ok = (len(mine) <= len(want) and not any(want[len(mine):])
                           and len(want) - len(mine) < 16 and (len(mine) > 0 or not want))
                chunks[sec_name] = (mine, want, size_ok)
                if not size_ok:
                    moved.add(sec_name)
        bss = elf.get_section_by_name(".bss")
        bss_size = bss["sh_size"] if bss is not None else 0
        if ".bss" in rng:
            lo, hi = rng[".bss"]
            bss_ok = hi is not None and 0 <= (hi - lo) - bss_size < 16
            if not bss_ok:
                moved.add(".bss")

        # .text, function by function
        text = elf.get_section_by_name(".text")
        data = text.data() if text else b""
        start = rng[".text"][0]
        print(f"{name}  (.text at 0x{start:08X})")
        fns = functions(elf)
        # Compare the Nth function with the game's Nth (at its real address),
        # so one function of the wrong size does not shift all the others.
        orig = original_functions(name)
        if orig is None or len(orig) != len(fns):
            orig = [(start + off, None) for off, _, _, _ in fns]
        spans = [(off, size, addr, fname) for (off, size, fname, _), (addr, _) in zip(fns, orig)]

        def place(sec, off):
            """Game address of the object's byte sec+off: code in the game's
            function of the same index, data at the file's section starts."""
            if sec == ".text":
                return next((addr + off - o for o, n, addr, _ in spans if o <= off < o + n), start + off)
            return rng[sec][0] + off if sec in rng else None

        def text_name(off):
            return next((fname + plus(off - o) for o, n, _, fname in spans if o <= off < o + n),
                        ".text" + plus(off))

        relocs = link(elf, ".text", data, place, syms, text_name, moved)
        for (off, size, fname, from_asm), (addr, osize) in zip(fns, orig):
            n_asm += from_asm
            delta = addr - off  # object offset -> game address

            def game(o):
                return word(rom, o + delta - BASE)

            offsets = range(off, off + size, 4)
            bad, rbad = check(data, relocs, offsets, game)
            lines = reloc_lines(relocs, offsets, data, game, lambda o: o + delta, rbad, name_of, off)
            status = [f"{len(bad)}/{size // 4} differ"] if bad else []
            if lines:
                status.append(f"{len(lines)} relocs differ" if len(lines) > 1 else "1 reloc differs")
            status = ", ".join(status) or ("asm" if from_asm else "MATCH")
            size_ok = osize is None or osize == size
            if not size_ok:
                status += f" (size 0x{size:X}, game 0x{osize:X})"
            ok &= not bad and not rbad and size_ok
            print(f"  0x{addr:08X} {fname:40} {size:#6x}  {status}")
            # Wrong references are worth reading when the code matches;
            # otherwise --diff shows them with everything else.
            if lines and (a.diff or not bad):
                for line in lines:
                    print(f"      {line}")
            if (bad or rbad or not size_ok) and a.diff:
                for o in range(off, off + max(size, osize or 0), 4):
                    pc = o + delta
                    r = relocs.get(o) if o < off + size else None
                    mine = (None if o >= off + size else r.word if r and r.word is not None
                            else word(data, o))
                    mark = "*" if o in bad or o in rbad or mine is None else " "
                    note = f"  # {r.label}" + (f" ({r.note})" if r.note else "") if r else ""
                    print(f"    {mark} {disasm(game(o), pc):38} | "
                          f"{disasm(mine, pc) if mine is not None else ''}{note}")
        end = rng[".text"][1]
        if end is not None and len(data) != end - start:
            ok = False
            print(f"  .text size 0x{len(data):X}, original file spans 0x{end - start:X}")

        # .rodata / .data: words, relocations linked; .bss: size
        unchecked = ", references to it not checked"
        for sec_name in (".rodata", ".data"):
            if sec_name not in rng:
                sec = elf.get_section_by_name(sec_name)
                if sec is not None and sec.data_size:
                    ok = False
                    print(f"  {sec_name}: object has 0x{sec.data_size:X} bytes, "
                          f"{'still in asm (partial file)' if partial else 'original file has none'}")
                continue
            mine, want, size_ok = chunks[sec_name]
            lo = rng[sec_name][0]
            relocs = link(elf, sec_name, mine, place, syms, text_name, moved)
            offsets = range(0, min(len(mine), len(want)) & ~3, 4)
            bad, rbad = check(mine, relocs, offsets, lambda o: word(want, o))
            lines = reloc_lines(relocs, offsets, mine, lambda o: word(want, o), lambda o: lo + o,
                                rbad, name_of, 0)
            ok &= not bad and not rbad and size_ok
            status = [f"{len(bad)} words differ"] if bad else []
            if lines:
                status.append(f"{len(lines)} relocs differ" if len(lines) > 1 else "1 reloc differs")
            status = ", ".join(status) or ("MATCH" if size_ok else "0 words differ")
            print(f"  {sec_name}: 0x{len(mine):X} bytes vs 0x{len(want):X}, {status}"
                  f"{unchecked if sec_name in moved else ''}")
            if lines and (a.diff or not bad):
                for line in lines:
                    print(f"      {line}")
        if bss_size and ".bss" not in rng:
            ok = False
            print(f"  .bss: object has 0x{bss_size:X} bytes, "
                  f"{'still in asm (partial file)' if partial else 'original file has none'}")
        elif ".bss" in rng:
            lo, hi = rng[".bss"]
            print(f"  .bss: 0x{bss_size:X} bytes vs 0x{(hi or lo) - lo:X}{unchecked if not bss_ok else ''}")
            ok &= bss_ok

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
