#!/usr/bin/env python3
"""Do our "order" near misses look like decomp-compat-kit's A3 (LO_SUM
alias) difference? Stock ee-gcc 2.96 treats a lui/%lo global address as
varying, so sched1 never moves a load from a global above an earlier
store; Xenosaga's retail compiler did. If Rule of Rose's compiler had that
fix, the game would put such loads before stores where we put them after.

    tools/.venv/Scripts/python.exe tools/order_probe.py          # every "order" row of build/regalloc_triage.tsv

For each attempt (compiled in place of its INCLUDE_ASM), the instructions
both sides share are aligned by content (relocated words by opcode,
relocation type and symbol); every pair (load, store) whose relative order
differs is counted by kind: load of a global (R_MIPS_LO16) vs other loads,
game load-first vs ours load-first.
"""
import collections
import os
import re
import sys
from pathlib import Path

os.environ.setdefault("ROR_QUIET_HI16", "1")
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402
import regalloc_triage  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402

LOADS = {0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x37, 0x31, 0x1E}   # lb lh lw lbu lhu lwu ld lwc1 lq
STORES = {0x28, 0x29, 0x2B, 0x3F, 0x39, 0x1F}                      # sb sh sw sd swc1 sq


def func(path, symbol):
    with open(path, "rb") as f:
        e = ELFFile(f)
        text, idx = e.get_section_by_name(".text"), e.get_section_index(".text")
        data = text.data()
        symtab = e.get_section_by_name(".symtab")
        syms = [s for s in symtab.iter_symbols() if s["st_shndx"] == idx and s.name and not s.name.startswith(("$", "."))]
        start = next((s["st_value"] for s in syms if s.name == symbol), None)
        if start is None:
            return None
        later = sorted(s["st_value"] for s in syms if s["st_value"] > start)
        end = later[0] if later else len(data)
        rel = {}
        for sec in e.iter_sections():
            if sec.name in (".rel.text", ".rela.text"):
                for r in sec.iter_relocations():
                    s = symtab.get_symbol(r["r_info_sym"])
                    rel[r["r_offset"]] = (r["r_info_type"], s.name)
    out = []
    for off in range(start, end - 3, 4):
        w = int.from_bytes(data[off:off + 4], "little")
        out.append((w >> 26, rel.get(off), w if off not in rel else w & 0xFC1F0000))
    while out and out[-1][2] == 0 and out[-1][1] is None:
        out.pop()
    return out


def pairs(game, ours):
    """[(kind, game_load_first)] for every load/store pair whose order differs."""
    # match each instruction by its full key, k-th occurrence to k-th occurrence
    def keyed(seq):
        seen = collections.Counter()
        out = []
        for i, ins in enumerate(seq):
            k = (ins[2], ins[1])
            out.append(((k, seen[k]), i))
            seen[k] += 1
        return out
    g = dict(keyed(game))
    o = dict(keyed(ours))
    common = [k for k in g if k in o]
    mem = [(k, "load" if k[0][0] >> 26 in LOADS else "store") for k in common if (k[0][0] >> 26) in LOADS | STORES]
    res = []
    for i, (a, ka) in enumerate(mem):
        for b, kb in mem[i + 1:]:
            if ka == kb:
                continue
            load, store = (a, b) if ka == "load" else (b, a)
            gf = g[load] < g[store]
            of = o[load] < o[store]
            if gf != of:
                glob = load[0][1] is not None and load[0][1][0] == 6   # R_MIPS_LO16
                res.append(("global load" if glob else "other load", gf))
    return res


def main():
    rows = [l.split("\t") for l in (ROOT / "build/regalloc_triage.tsv").read_text(encoding="utf8").splitlines()[1:]]
    rows = [r for r in rows if len(r) > 2 and r[2] == "order"]
    if not match.server_up():
        match.server("start")
    total = collections.Counter()
    funcs = collections.Counter()
    for name, fn, *_ in rows:
        text = (ROOT / "src" / f"{name}.cpp").read_text(encoding="utf8")
        m = next((m for m in regalloc_triage.NM.finditer(text) if m.group(2) == fn), None)
        if not m:
            continue
        tmp = ROOT / "build" / "triage" / f"order_{fn}.cpp"
        tmp.parent.mkdir(parents=True, exist_ok=True)
        tmp.write_text(text[:m.start()] + m.group(1) + text[m.end():], encoding="utf8", newline="\n")
        try:
            match.compare(name, source=str(tmp))
        except match.CompileError:
            continue
        ours = func(ROOT / "build" / "match" / f"{name}.{tmp.stem}.o", fn)
        game = func(ROOT / "build" / "src" / f"{name}.o", fn)
        if not ours or not game:
            continue
        p = pairs(game, ours)
        c = collections.Counter(p)
        total.update(c)
        kinds = {k for k, gf in p if gf}
        funcs["functions measured"] += 1
        if ("global load", True) in c:
            funcs["game moves a global load above a store"] += 1
        if ("global load", False) in c:
            funcs["we move a global load above a store"] += 1
        print(f"{name} {fn}: " + ", ".join(f"{k} {'game' if gf else 'ours'} first x{n}" for (k, gf), n in sorted(c.items())) or "no load/store pair moved", flush=True)
    print("pairs:", dict(total))
    print("functions:", dict(funcs))


if __name__ == "__main__":
    main()
