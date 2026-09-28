#!/usr/bin/env python3
"""Disassemble functions from SLUS_214.48 as R5900 GNU-as assembly.

Useful as target asm for decomp.me scratches or for quick inspection.

Usage:
  tools/.venv/bin/python tools/disasm.py 0x281030           # by address
  tools/.venv/bin/python tools/disasm.py setMotionSpeedSub   # by name (substring)
  tools/.venv/bin/python tools/disasm.py 0x100008 --count 40 # raw instruction count

Function size comes from symbols/ghidra_symbols.tsv when known; otherwise
disassembly stops after the first `jr $ra` + delay slot.
"""
import argparse
import csv
import sys
from pathlib import Path

import rabbitizer

sys.path.insert(0, str(Path(__file__).resolve().parent))
import ror_symbols as R  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent


def load_symbols():
    path = ROOT / "symbols/ghidra_symbols.tsv"
    with open(path) as f:
        return list(csv.DictReader(f, delimiter="\t"))


def resolve(query, syms):
    if query.lower().startswith("0x"):
        addr = int(query, 16)
        row = next((s for s in syms if int(s["addr"], 16) == addr), None)
        return [(addr, row)]
    hits = [s for s in syms if query in s["name"] or query in s["mangled"]]
    return [(int(s["addr"], 16), s) for s in hits if s["kind"] != "vtable"]


def disasm(elf, addr, size=None, count=None, names=None):
    out, pc, n, stop_after = [], addr, 0, None
    while True:
        word = elf.word(pc)
        if word is None:
            break
        ins = rabbitizer.Instruction(word, vram=pc, category=rabbitizer.InstrCategory.R5900)
        text = ins.disassemble()
        if ins.isJumpWithAddress() and names:
            target = ins.getInstrIndexAsVram()
            if target in names:
                text += f"  # {names[target]}"
        out.append(f"/* {pc:08X} {word:08X} */  {text}")
        pc += 4
        n += 1
        if size and pc >= addr + size:
            break
        if count and n >= count:
            break
        if not size and not count:
            if stop_after is not None and pc >= stop_after:
                break
            if ins.isJrRa():
                stop_after = pc + 4  # include the delay slot
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("query", help="address (0x...) or name substring")
    ap.add_argument("--count", type=int, help="number of instructions")
    ap.add_argument("--elf", default=str(ROOT / "disc/SLUS_214.48"))
    a = ap.parse_args()

    elf = R.Elf(Path(a.elf))
    syms = load_symbols()
    names = {int(s["addr"], 16): (f"{s['class']}::" if s["class"] else "") + s["name"] for s in syms}
    for addr, row in resolve(a.query, syms):
        size = int(row["size"], 16) if row and row["size"] != "0" else None
        title = names.get(addr, f"func_{addr:08X}")
        sig = row["signature"] if row else ""
        print(f"\n# {title}  {sig}".rstrip())
        print(f"glabel func_{addr:08X}")
        print("\n".join(disasm(elf, addr, size, a.count, names)))


if __name__ == "__main__":
    main()
