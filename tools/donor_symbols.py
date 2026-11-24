#!/usr/bin/env python3
"""Name functions shared with other games whose executables kept symbols.

    tools/.venv/bin/python tools/donor_symbols.py      # writes symbols/donor_symbols.tsv

A donor is an executable of another game, extracted from the owner's own
disc into disc/<dir>/ (never committed), that still has its .symtab and the
relocations of its code. Today: PoPoLoCrois - Tsuki no Okite no Bouken
(SCPS-15063, Japan, 2004; build with .symtab, .relmain, DWARF 1 .debug and
.line; its own code built with Metrowerks, Sony's RX library with GCC).
Both games link SCE Japan's RX library (RX_SCE_LIBRARY_VERSION:4: our
mw/sound, rxSnd*/rxFile*/rxTh*/rxSys*/rxGs*) and much of the same SDK.

Arc the Lad: Twilight of the Spirits's hidden 2002 disc (inside ARC.000 on
the US retail SCUS-97231, found by tools/disc_scan.py --deep) keeps two
debug builds, DATAIMG/KOGA/MAIN.ELF and MAIN_OLD.ELF (.symtab, .mdebug,
.stab, RX library version 4) without relocations: for those the masks come
from the instructions themselves (see heuristic_masks).

A donor function names one of ours when the donor's bytes, with its own
relocation fields masked (R_MIPS_26 keeps the opcode, HI16/LO16 the upper
half, R_MIPS_32 the whole word), equal ours at one of our function starts
with the same mask. As in tools/sce_symbols.py: functions with fewer than
256 non-relocated bits are ignored; an address that matches several names
is dropped, and so is a global name that matches several addresses. Only
the names (and sizes) are written; nothing of the donor's code.

Precedence (tools/ror_symbols.py): linkonce and sce-sdb names win; a donor
name never replaces one, nor takes a name already used elsewhere.
"""
import collections
import hashlib
import re
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import sce_symbols as ss  # noqa: E402

DONORS = [
    # (id, path, sha256, code section, its relocation section)
    ("popolo", "disc/popolo/SCPS_150.63",
     "f97b7bc048d6ca3d833579ab05b20d3f223d9c2768a989f6d54361183b1a2e4b", "main", ".relmain"),
    # relocation section None: linked executables, masks from the instructions
    ("arc2002", "disc/arc_koga/DATAIMG_KOGA_MAIN.ELF",
     "bda0381c685b6c183a4799e255aee64928e3457c1bd64dc2f1ebb15d2e04a580", ".text", None),
    ("arc2002old", "disc/arc_koga/DATAIMG_KOGA_MAIN_OLD.ELF",
     "e6885b4b6e722ac54a1008b55bcce6cb2a23c99bc2c827b8ed0773d748600b1b", ".text", None),
]
# I-type opcodes whose immediate can be the %lo of an address: addiu, ori
# and the loads/stores (lb..sw, lwc1/swc1, ld/sd, lq/sq, ldl/ldr/sdl/sdr...)
LO_OPS = {0x09, 0x0D, 0x1A, 0x1B, 0x1E, 0x1F} | set(range(0x20, 0x30)) | {0x31, 0x37, 0x39, 0x3F}
OUT = ROOT / "symbols/donor_symbols.tsv"
RELOC_MASK = {2: 0, 4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000, 7: 0xFFFF0000}   # R_MIPS_32/26/HI16/LO16/GPREL16
FREE_BITS = {0: 32, 0xFC000000: 26, 0xFFFF0000: 16}


def heuristic_masks(body, base):
    """Masks for a linked executable without relocations, per function the
    caller slices: j/jal targets (R_MIPS_26), every lui immediate (HI16),
    and the immediate of an addiu/ori/load/store whose base register a lui
    set earlier in the same function (LO16). Over-masking only costs
    matches (the 256-bit floor), it never names a wrong function."""
    masks, lui_regs = {}, set()
    for o in range(0, len(body) - 3, 4):
        w = int.from_bytes(body[o:o + 4], "little")
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op in (2, 3):
            masks[base + o] = 0xFC000000
        elif op == 0x0F:
            masks[base + o] = 0xFFFF0000
            lui_regs.add(rt)
        elif op in LO_OPS and rs in lui_regs:
            masks[base + o] = 0xFFFF0000
    return masks


def donor_functions(path, sha, code, relsec):
    data = (ROOT / path).read_bytes()
    if hashlib.sha256(data).hexdigest() != sha:
        raise SystemExit(f"{path}: not the expected build (sha256 differs)")
    e = ELFFile(open(ROOT / path, "rb"))
    sec = e.get_section_by_name(code)
    idx = next(i for i, s in enumerate(e.iter_sections()) if s.name == code)
    base = sec["sh_addr"]
    body = sec.data()
    masks = {}
    if relsec:
        for r in e.get_section_by_name(relsec).iter_relocations():
            m = RELOC_MASK.get(r["r_info_type"])
            if m is not None:
                masks[r["r_offset"]] = m
    for s in e.get_section_by_name(".symtab").iter_symbols():
        if s["st_info"]["type"] != "STT_FUNC" or s["st_shndx"] != idx or s["st_size"] < 32:
            continue
        a, size = s["st_value"], s["st_size"]
        if not relsec:
            masks = heuristic_masks(body[a - base:a - base + size], a)
        mk = [(o - a, m) for o in range(a, a + size, 4) if (m := masks.get(o)) is not None]
        if 32 * (size // 4) - sum(FREE_BITS[m] for _, m in mk) < 256:
            continue
        yield (s.name, s["st_info"]["bind"], body[a - base:a - base + size], mk)


def main():
    rom = (ROOT / "build/SLUS_214.48.rom").read_bytes()
    starts = ss.function_starts()
    by_first = collections.defaultdict(list)
    for a in starts:
        by_first[rom[a - ss.BASE:a - ss.BASE + 4]].append(a)
    rows = []
    for did, path, sha, code, relsec in DONORS:
        at = collections.defaultdict(set)        # our address -> {(name, bind, size)}
        where = collections.defaultdict(set)     # name -> {our addresses}
        n = 0
        for name, bind, fb, mk in donor_functions(path, sha, code, relsec):
            n += 1
            masked0 = dict(mk)
            if 0 in masked0:
                continue        # first word relocated: no cheap prefilter (rare)
            h = ss.masked_sha1(fb, 0, len(fb), mk)
            for a in by_first.get(fb[:4], ()):
                if ss.masked_sha1(rom, a - ss.BASE, len(fb), mk) == h:
                    at[a].add((name, bind, len(fb)))
                    where[name].add(a)
        kept = 0
        for a in sorted(at):
            names = {x[0] for x in at[a]}
            if len(names) != 1:
                continue
            name, bind, size = next(iter(at[a]))
            if bind == "STB_GLOBAL" and len(where[name]) != 1:
                continue
            rows.append((a, did, name, size))
            kept += 1
        print(f"{did}: {n} donor functions tried, {len(at)} of our addresses matched, {kept} named")
    # Donors that name one address differently (a debug-print stub each game
    # calls its own way) leave it unnamed; agreeing donors keep one row each.
    names_at = collections.defaultdict(set)
    for a, did, name, size in rows:
        names_at[a].add(name)
    split = sorted(a for a, n in names_at.items() if len(n) > 1)
    if split:
        print("donors disagree, dropped: " + ", ".join(f"{a:08x} {sorted(names_at[a])}" for a in split))
    rows = [r for r in rows if len(names_at[r[0]]) == 1]
    with open(OUT, "w", encoding="utf8", newline="\n") as f:
        f.write("# Generated by tools/donor_symbols.py (names only; donors are the owner's discs)\n")
        f.write("addr\tdonor\tname\tsize\n")
        for a, did, name, size in rows:
            f.write(f"{a:08x}\t{did}\t{name}\t{size:x}\n")
    print(f"{len(rows)} names -> {OUT.relative_to(ROOT)}")
    pre = collections.Counter(re.match(r"_*([A-Za-z][a-z]*(?:[A-Z][a-z]+)?)", n).group(1) for _, _, n, _ in rows)
    print(dict(pre.most_common(15)))


if __name__ == "__main__":
    main()
