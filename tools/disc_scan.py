#!/usr/bin/env python3
"""Scan PS2 disc images for symbol donors: extract the executables and say
whether they carry the RX library, a symbol table or debug sections.

    tools/.venv/Scripts/python.exe tools/disc_scan.py <image>... [--out disc/<id>] [--deep]

<image> is an .iso (2048-byte sectors) or a raw .bin (2352, MODE1 or MODE2).
For each one: the volume, SYSTEM.CNF, and every executable on the disc
(256 KB or more; --all: every ELF; --irx: IOP modules too), with its size, sha256, sections, symbol count and functions,
the RX library version ($RX_SCE_LIBRARY_VERSION), and how many of its
function names are new to symbols/donor_symbols.tsv. With --out the ELFs are
written there (keep it under disc/, which git ignores).

--deep also looks inside large files for whole disc images left there by
the mastering tools (Arc the Lad's ARC.000 kept a 2002 build): ISO images
on 2048-byte sectors and images stored as 2348-byte records (4-byte sector
number, 16 bytes of header, 2048 of data, 280 of EDC/ECC).

A donor is useful only with symbols: then add it to DONORS in
tools/donor_symbols.py and rerun tools/ror_symbols.py.
"""
import argparse
import hashlib
import io
import os
import re
import struct
import sys

from elftools.elf.elffile import ELFFile

MAIN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MIN_EXE = 256 << 10      # game scripts compiled to MIPS ELFs (Arc's .SCP, RoR's ARA) are smaller
MIN_FUNCS = 100          # a donor names a library, not a handful of script entry points
DEBUG_SECTIONS = {".debug", ".line", ".mwcats", ".stab", ".debug_info", ".debug_line"}


class Volume:
    """An ISO 9660 volume inside a file: sector n's data is at
    base + n * size + skip. A record layout with sector numbers is checked."""

    def __init__(self, f, base, size, skip, numbered=False, limit=None):
        self.f, self.base, self.size, self.skip, self.numbered = f, base, size, skip, numbered
        self.limit = limit
        pvd = self.sector(16)
        if pvd[1:6] != b"CD001":
            raise ValueError("no ISO 9660 volume")
        self.name = pvd[40:72].decode("latin1").strip()
        self.sectors = struct.unpack("<I", pvd[80:84])[0]
        self.created = pvd[813:827].decode("latin1")
        root = pvd[156:190]
        self.root = (struct.unpack("<I", root[2:6])[0], struct.unpack("<I", root[10:14])[0])

    def sector(self, n, count=1):
        out = []
        for i in range(count):
            self.f.seek(self.base + (n + i) * self.size)
            rec = self.f.read(self.size)
            if self.numbered and struct.unpack("<I", rec[:4])[0] != n + i:
                raise ValueError(f"record for sector {n + i} is missing")
            out.append(rec[self.skip:self.skip + 2048])
        return b"".join(out)

    def read(self, lba, length):
        return self.sector(lba, (length + 2047) // 2048)[:length]

    def entries(self, lba, length):
        data, i, out = self.sector(lba, (length + 2047) // 2048), 0, []
        while i < length:
            n = data[i]
            if n == 0:
                i = (i // 2048 + 1) * 2048
                continue
            rec = data[i:i + n]
            name = rec[33:33 + rec[32]].decode("latin1").split(";")[0]
            if name not in ("\x00", "\x01"):
                out.append((name, struct.unpack("<I", rec[2:6])[0],
                            struct.unpack("<I", rec[10:14])[0], bool(rec[25] & 2)))
            i += n
        return out

    def walk(self, lba=None, length=None, path="/", depth=0):
        if lba is None:
            lba, length = self.root
        for name, a, n, is_dir in self.entries(lba, length):
            if is_dir:
                if depth < 6:
                    yield from self.walk(a, n, path + name + "/", depth + 1)
            else:
                yield path + name, a, n


def open_image(f):
    f.seek(0)
    head = f.read(16)
    if head[:12] == b"\x00" + b"\xff" * 10 + b"\x00":
        return Volume(f, 0, 2352, 16 if head[15] == 1 else 24)
    return Volume(f, 0, 2048, 0)


def known_names():
    path = os.path.join(MAIN, "symbols", "donor_symbols.tsv")
    names = set()
    if os.path.exists(path):
        for line in open(path, encoding="utf-8"):
            parts = line.rstrip("\n").split("\t")
            if len(parts) > 2 and not line.startswith(("#", "addr")):
                names.add(parts[2])
    return names


def is_executable(data):
    """An EE executable: ELF32 little-endian MIPS, ET_EXEC (overlays, .DLL
    modules and data files that happen to be ELFs are ET_REL or tiny)."""
    return len(data) >= MIN_EXE and struct.unpack("<HH", data[16:20]) == (2, 8)


def report_elf(label, data, out, known):
    sha = hashlib.sha256(data).hexdigest()
    try:
        summary(label, data, sha, out, known)
    except Exception as exc:  # noqa: BLE001 - leftovers inside ARC.000-style files are often damaged
        print(f"  {label}: {len(data)} B sha256 {sha}, damaged ELF ({type(exc).__name__}: {exc})")


def summary(label, data, sha, out, known):
    elf = ELFFile(io.BytesIO(data))
    sections = [s for s in elf.iter_sections()]
    names = [s.name for s in sections]
    symtab = elf.get_section_by_name(".symtab")
    nsym = symtab.num_symbols() if symtab and symtab["sh_size"] else 0
    funcs = set()
    if nsym:
        funcs = {s.name for s in symtab.iter_symbols()
                 if s["st_info"]["type"] == "STT_FUNC" and s.name}
    debug = sorted(n for n in names if n in DEBUG_SECTIONS or n.startswith(".mdebug")
                   and next(s for s in sections if s.name == n)["sh_size"])
    rx = re.search(rb"[$]RX_SCE_LIBRARY_VERSION:([0-9]+)", data)
    verdict = ("DONOR CANDIDATE" if len(funcs) >= MIN_FUNCS
               else f"only {len(funcs)} named functions" if funcs else "stripped")
    print(f"  {label}: {len(data)} B sha256 {sha}")
    print(f"    RX library: {'version ' + rx.group(1).decode() if rx else 'no'}"
          f"{' (rxsnd)' if b'rxsnd :' in data else ''}; symbols {nsym}, functions {len(funcs)}"
          f" ({len(funcs - known)} not yet in donor_symbols.tsv); debug {debug or 'none'} -> {verdict}")
    print(f"    sections: {', '.join(n or "''" for n in names if not n.startswith('.DVP'))}")
    if out:
        os.makedirs(out, exist_ok=True)
        dest = os.path.join(out, label.strip().strip("/").replace("/", "_"))
        with open(dest, "wb") as h:
            h.write(data)
        print(f"    written to {os.path.relpath(dest, MAIN)}")


def scan_volume(vol, args, known, prefix=""):
    print(f"{prefix}volume {vol.name!r}, {vol.sectors} sectors, created {vol.created}")
    for path, lba, length in vol.walk():
        if path.upper() == "/SYSTEM.CNF":
            cnf = vol.read(lba, length).decode("latin1").strip().replace("\r\n", " | ")
            print(f"{prefix}  SYSTEM.CNF: {cnf}")
    big, others = [], 0
    for path, lba, length in vol.walk():
        if length < 4096:
            continue
        if path.upper().endswith(".IRX") and not args.irx:
            continue
        try:
            head = vol.read(lba, 4)
        except ValueError:
            continue
        if head == b"\x7fELF":
            try:
                data = vol.read(lba, length)
            except ValueError as exc:
                print(f"{prefix}  {path}: {exc}")
                continue
            if is_executable(data) or args.all:
                report_elf(prefix + path, data, args.out, known)
            else:
                others += 1
        elif length >= 64 << 20:
            big.append((path, lba, length))
    if others:
        print(f"{prefix}  ({others} other ELF files under 256 KB or not executables: overlays, scripts, data; --all shows them)")
    return big


def nested(f, start, length):
    """Disc images inside [start, start+length) of f: (base, size, skip, numbered)."""
    found, pos, chunk = [], 0, 64 << 20
    while pos < length:
        f.seek(start + pos)
        blk = f.read(min(chunk + 8, length - pos))
        i = blk.find(b"\x01CD001")
        while i != -1 and i < chunk:
            at = start + pos + i
            if (at - start) % 2048 == 0:
                found.append((at - 16 * 2048, 2048, 0, False))
            else:
                f.seek(at - 20)
                n = struct.unpack("<I", f.read(4))[0]
                if n == 16:
                    found.append((at - 20 - 16 * 2348, 2348, 20, True))
            i = blk.find(b"\x01CD001", i + 1)
        pos += chunk
    return found


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("images", nargs="+")
    ap.add_argument("--out", help="write the ELFs here (under disc/)")
    ap.add_argument("--deep", action="store_true", help="look for disc images inside large files")
    ap.add_argument("--all", action="store_true", help="report every ELF, not only executables of 256 KB or more")
    ap.add_argument("--irx", action="store_true", help="also report IOP modules (.IRX)")
    args = ap.parse_args()
    known = known_names()
    for image in args.images:
        print(f"== {image}")
        with open(image, "rb") as f:
            try:
                vol = open_image(f)
            except ValueError as exc:
                print(f"  {exc}")
                continue
            big = scan_volume(vol, args, known)
            if args.deep:
                for path, lba, length in big:
                    if vol.size != 2048:
                        print(f"  --deep needs a 2048-byte image, skipping {path}")
                        continue
                    for base, size, skip, numbered in nested(f, lba * 2048, length):
                        try:
                            inner = Volume(f, base, size, skip, numbered)
                        except ValueError:
                            continue
                        print(f"  inside {path} at {base - lba * 2048:#x} ({size}-byte sectors):")
                        scan_volume(inner, args, known, prefix="    ")
    return 0


if __name__ == "__main__":
    sys.exit(main())
