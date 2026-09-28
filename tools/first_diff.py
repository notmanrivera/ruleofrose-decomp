#!/usr/bin/env python3
"""Show where the built image differs from the original.

    tools/.venv/bin/python tools/first_diff.py [-n 20]

Compares build/SLUS_214.48.built.rom against build/SLUS_214.48.rom (both
start at vram 0x00100000) and names each differing region with the nearest
preceding symbol from the linker map.
"""
import argparse
import bisect
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x00100000


def map_symbols(path):
    syms = []
    for line in path.read_text(errors="replace").splitlines():
        m = re.match(r"\s+0x([0-9a-f]{8,16})\s+([A-Za-z_.$][\w.$]*)\s*$", line)
        if m:
            syms.append((int(m.group(1), 16), m.group(2)))
    syms.sort()
    return syms


def where(syms, addrs, vram):
    i = bisect.bisect_right(addrs, vram) - 1
    if i < 0:
        return "?"
    a, name = syms[i]
    return f"{name}+0x{vram - a:X}"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-n", type=int, default=20, help="number of regions to show")
    a = ap.parse_args()

    want = (ROOT / "build/SLUS_214.48.rom").read_bytes()
    got = (ROOT / "build/SLUS_214.48.built.rom").read_bytes()
    syms = map_symbols(ROOT / "build/SLUS_214.48.map")
    addrs = [s for s, _ in syms]

    if len(want) != len(got):
        print(f"size differs: built 0x{len(got):X}, original 0x{len(want):X}")
    regions, i, end = [], 0, min(len(want), len(got))
    while i < end:
        if want[i] != got[i]:
            j = i
            while j < end and (want[j] != got[j] or (j + 1 < end and want[j + 1] != got[j + 1])):
                j += 1
            regions.append((i, j))
            i = j
        i += 1
    total = sum(j - i for i, j in regions)
    print(f"{len(regions)} differing regions, {total} bytes")
    for s, e in regions[:a.n]:
        v = BASE + s
        print(f"  0x{v:08X}  {e - s:6} bytes  {where(syms, addrs, v)}")
        print(f"      want {want[s:s + 16].hex(' ')}")
        print(f"      got  {got[s:s + 16].hex(' ')}")


if __name__ == "__main__":
    main()
