#!/usr/bin/env python3
"""Map RoR-Port's hand names (PAL SLES-542.18 addresses, GPL project, kept
outside the repo in ../ext/ror-port) to our NTSC addresses by code bytes.

    tools/.venv/Scripts/python.exe tools/map_pal_names.py      # needs disc/pal/SLES_542.18

For each PAL address, the function's first instructions are compared with
the NTSC code, immediates and jump targets masked (addresses differ
between the releases), near the address the neighbours' delta predicts,
then anywhere. A name is mapped when exactly one NTSC function start
matches at the longest window that still tells them apart (at least 8
instructions). Writes build/ror_port_names.tsv: a lead list, not
committed (the names are the port's descriptive guesses).
"""
import csv
import glob
import os
import re
import struct
import collections
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
NAMES = ROOT.parent / "ext" / "ror-port" / "tools" / "ghidra_scripts" / "names"


def load(path):
    """{vaddr: bytes} of the ELF's loadable segments."""
    d = open(path, "rb").read()
    phoff, = struct.unpack_from("<I", d, 28)
    phnum, = struct.unpack_from("<H", d, 44)
    segs = []
    for i in range(phnum):
        t, off, va, _, fsz, _, _, _ = struct.unpack_from("<8I", d, phoff + 32 * i)
        if t == 1 and fsz:
            segs.append((va, d[off:off + fsz]))
    return segs


def words(segs, addr, n):
    for va, b in segs:
        if va <= addr and addr + 4 * n <= va + len(b):
            o = addr - va
            return list(struct.unpack_from(f"<{n}I", b, o))
    return None


def mask(w):
    op = w >> 26
    if op in (2, 3):                  # j, jal: target
        return w & 0xFC000000
    if op == 0 or op in (0x10, 0x11, 0x12, 0x1C):   # R-type, cop0/1/2, MMI: keep
        return w
    return w & 0xFFFF0000             # I-type: immediate (addresses, offsets)


def starts():
    out = {}
    for p in glob.glob(str(ROOT / "asm/nonmatchings/**/*.s"), recursive=True):
        with open(p, encoding="utf8", errors="replace") as fh:
            for line in fh:
                m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ", line)
                if m:
                    out[int(m.group(1), 16)] = os.path.splitext(os.path.basename(p))[0]
                    break
    return out


def main():
    pal, ntsc = load(ROOT / "disc/pal/SLES_542.18"), load(ROOT / "disc/SLUS_214.48")
    st = starts()
    syms = {int(r["addr"], 16): r for r in csv.DictReader(open(ROOT / "symbols/ghidra_symbols.tsv", encoding="utf8"), delimiter="\t")}
    sce = {}
    for r in csv.DictReader(open(ROOT / "symbols/sce_symbols.tsv", encoding="utf8"), delimiter="\t"):
        try:
            sce[int(r.get("addr") or r.get("address"), 16)] = r.get("name", "")
        except (TypeError, ValueError):
            pass
    # every NTSC start (ours from asm + SDK ones) indexed by its first 8 masked words
    # every 4-aligned NTSC position, by its 8 masked words; function starts
    # are preferred when a window also occurs inside other functions
    allstarts = set(st) | set(sce)
    index = collections.defaultdict(list)
    for va, b in ntsc:
        n = len(b) // 4
        ws = [mask(x) for x in struct.unpack_from(f"<{n}I", b, 0)]
        for i in range(n - 8):
            index[tuple(ws[i:i + 8])].append(va + 4 * i)
    rows = []
    for f in sorted(NAMES.glob("*.csv")):
        for line in open(f, encoding="utf8"):
            if line.startswith(("#", "address")) or not line.strip():
                continue
            w = next(csv.reader([line]))
            try:
                a = int(w[0], 16)
            except ValueError:
                continue
            rows.append((a, w[1], w[2], w[3] if len(w) > 3 else "", w[4] if len(w) > 4 else "", f.name))
    out, stat = [], collections.Counter()
    for a, ns, n, kind, ev, fname in rows:
        pw = words(pal, a, 8)
        if not pw:
            stat["PAL address outside code"] += 1
            continue
        cands = index.get(tuple(map(mask, pw)), [])
        if len(cands) > 1 and any(c in allstarts for c in cands):
            cands = [c for c in cands if c in allstarts]
        k = 8
        while len(cands) > 1 and k < 64:      # longer windows tell twins apart
            k *= 2
            p = words(pal, a, k)
            if not p:
                break
            cands = [c for c in cands if (words(ntsc, c, k) or [None]) and list(map(mask, words(ntsc, c, k) or [])) == list(map(mask, p))]
        if len(cands) != 1:
            stat["ambiguous" if cands else "no match"] += 1
            continue
        b = cands[0]
        exact = words(pal, a, 8) == words(ntsc, b, 8)
        ours = st.get(b) or sce.get(b, "")
        cls = syms.get(b, {}).get("class", "")
        stat["mapped"] += 1
        stat["at a known start" if b in allstarts else "inside a function (not a start here)"] += 1
        stat["ours unnamed" if re.fullmatch(r"func_[0-9A-F]{8}", ours or "") else "ours named"] += 1
        out.append((b, a, f"{ns}::{n}" if ns else n, kind, ours, cls, "same bytes" if exact else "masked", ev[:200], fname))
    dest = ROOT / "build" / "ror_port_names.tsv"
    with open(dest, "w", encoding="utf8", newline="\n") as o:
        o.write("ntsc\tpal\ttheir_name\tkind\tour_symbol\tour_class\tcompare\tevidence\tfile\n")
        for r in sorted(out):
            o.write(f"{r[0]:08X}\t{r[1]:08X}\t" + "\t".join(r[2:]) + "\n")
    print(dict(stat), "->", dest)


if __name__ == "__main__":
    main()
