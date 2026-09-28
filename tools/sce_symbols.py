#!/usr/bin/env python3
"""Name Sony SDK / libgcc / libc functions by signature.

    python3 tools/sce_symbols.py        # writes symbols/sce_symbols.tsv

Uses the symbol database that ships with PS2Recomp's analyzer (GPL-3.0,
from the sce-symbol-scanner project). It is downloaded at a pinned commit
into build/cache and never committed; only the resulting names are.

A function matches when the SHA-1 of its bytes, with the database entry's
relocation fields masked (R_MIPS_26 keeps the opcode, HI16/LO16/GPREL16
keep the upper half), equals the entry's hash. Like the upstream scanner,
entries with fewer than 256 non-relocated bits are ignored, names that
differ at one address are dropped as ambiguous, and so are single matches
from a library that matches nowhere else (almost always coincidences).

Needs a finished build: function starts come from splat's asm/, the image
from build/SLUS_214.48.rom.
"""
import hashlib
import json
import re
import struct
import urllib.request
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PS2RECOMP_COMMIT = "75d729ce40d7eed9649fd4bb05628dee520f3d0c"
DB_URL = (f"https://raw.githubusercontent.com/ran-j/PS2Recomp/{PS2RECOMP_COMMIT}/"
          "ps2xAnalyzer/include/ps2recomp/sce_symbol_database_data.h")
DB_PATH = ROOT / "build/cache/sce_symbol_database_data.h"
BASE, TEXT_END = 0x00100000, 0x00280E88
MASK = {"MIPS_26": 0xFC000000, "MIPS_HI16": 0xFFFF0000, "MIPS_LO16": 0xFFFF0000,
        "MIPS_GPREL16": 0xFFFF0000, "MIPS_LITERAL": 0xFFFF0000, "MIPS_32": 0}
RELOC_BITS = {"MIPS_26": 26, "MIPS_HI16": 16, "MIPS_LO16": 16, "MIPS_GPREL16": 16,
              "MIPS_LITERAL": 16, "MIPS_32": 32}


def load_db():
    if not DB_PATH.exists():
        DB_PATH.parent.mkdir(parents=True, exist_ok=True)
        print(f"downloading {DB_URL}")
        urllib.request.urlretrieve(DB_URL, DB_PATH)
    text = DB_PATH.read_text()
    start = text.index("kSymbolsJsonChunks")
    end = text.index("kTreeJsonChunks") if "kTreeJsonChunks" in text else len(text)
    db = json.loads("".join(re.findall(r'R"PS2SDB\((.*?)\)PS2SDB"', text[start:end], re.S)))
    by_size = defaultdict(list)
    for lib, syms in db.items():
        for name, hashes in syms.items():
            for sha, variants in hashes.items():
                for meta in variants.values():
                    size = meta.get("size", 0)
                    if meta.get("type") != "FUNCTION" or not size:
                        continue
                    relocs = meta.get("relocations", {})
                    static = size * 8 - sum(RELOC_BITS.get(r["type"], 0) for r in relocs.values())
                    if static < 256:
                        continue
                    mask = tuple(sorted((int(o, 0), MASK.get(r["type"], 0xFFFFFFFF))
                                        for o, r in relocs.items()))
                    by_size[size].append((sha, lib, name, mask))
    return by_size


def function_starts():
    starts = set()
    for path in (ROOT / "asm").glob("**/*.s"):
        if "/data/" in str(path):
            continue
        label = False
        for line in path.read_text(errors="replace").splitlines():
            if re.match(r"(glabel|jlabel) ", line):
                label = True
                continue
            m = re.match(r"\s+/\* [0-9A-F]+ ([0-9A-F]{8}) ", line)
            if m and label:
                a = int(m.group(1), 16)
                if BASE <= a < TEXT_END:
                    starts.add(a)
                label = False
    return sorted(starts)


def masked_sha1(rom, off, size, mask):
    b = bytearray(rom[off:off + size])
    for o, m in mask:
        if o + 4 <= size:
            struct.pack_into("<I", b, o, struct.unpack_from("<I", b, o)[0] & m)
    return hashlib.sha1(b).hexdigest()


def main():
    by_size = load_db()
    rom = (ROOT / "build/SLUS_214.48.rom").read_bytes()
    starts = function_starts() + [TEXT_END]

    hits = defaultdict(set)
    for k, a in enumerate(starts[:-1]):
        # splat may split one library function in two, and objects end with
        # up to three words of nop padding: try every nearby end.
        ends = {e - pad for e in starts[k + 1:k + 12] for pad in (0, 4, 8, 12)}
        for end in ends:
            size = end - a
            cache = {}
            for sha, lib, name, mask in by_size.get(size, ()):
                if mask not in cache:
                    cache[mask] = masked_sha1(rom, a - BASE, size, mask)
                if cache[mask] == sha:
                    hits[a].add((lib, name, size))

    per_lib = Counter(next(iter(h))[0] for h in hits.values())
    rows = []
    for a in sorted(hits):
        names = {n for _, n, _ in hits[a]}
        libs = {l for l, _, _ in hits[a]}
        if len(names) != 1 or len(libs) != 1:
            continue
        lib = next(iter(libs))
        if per_lib[lib] < 2:
            continue
        rows.append((a, lib, names.pop(), max(s for *_, s in hits[a])))

    out = ROOT / "symbols/sce_symbols.tsv"
    with open(out, "w") as f:
        f.write(f"# Generated by tools/sce_symbols.py (PS2Recomp symbol database @ {PS2RECOMP_COMMIT[:12]})\n")
        f.write("addr\tlibrary\tname\tsize\n")
        for a, lib, name, size in rows:
            f.write(f"{a:08x}\t{lib}\t{name}\t{size:x}\n")
    print(f"{len(rows)} SDK functions named -> {out.relative_to(ROOT)}")
    print(dict(Counter(r[1] for r in rows).most_common()))


if __name__ == "__main__":
    main()
