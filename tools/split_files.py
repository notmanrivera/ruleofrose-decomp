#!/usr/bin/env python3
"""Infer where each original source file starts in .text, .rodata, .data and .bss.

    tools/.venv/bin/python tools/split_files.py      # writes config/splits.tsv

Needs a finished build (build/SLUS_214.48.map) and splat's asm/.

Evidence, strongest first:
  1. Assert source paths (symbols/function_sources.tsv) name the file of
     529 functions; runs of the same path give known files in link order.
  2. The linker lays out each object's .rodata in the same order as its
     .text, so a real boundary separates every earlier function's .rodata
     references from every later one's. References into the SDK libraries'
     .rodata (e.g. newlib's _ctype_) are excluded: any file may use them.
  3. Between two known files, the cut is chosen among those positions by
     class membership (methods of one class live in one file) and by
     callers/callees, then as early as possible.
  4. The SDK library region (after the last game file) is split per library
     run, from the signatures in symbols/sce_symbols.tsv.
  5. .data and .bss follow the same link order, but globals are shared, so
     only ownership evidence counts: a symbol referenced by the code of a
     single file, or (for .data) a table whose pointers all lead to one
     file's functions or .rodata. The chunk starts come from the longest
     run of that evidence that respects link order; the rest is noise
     (extern globals, COMMON symbols allocated at the end of .bss).

Unknown files without asserts can hide inside the ranges; the confidence
column says how well each boundary is pinned down.
"""
import bisect
import csv
import re
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TEXT_START = 0x00100000
TEXT_END = 0x00280E88          # end of .text proper (linkonce sections follow)
RODATA = (0x002E5300, 0x00307F70)
DATA = (0x00295F00, 0x002E014C)
BSS = (0x00308100, 0x00828E94)


def load_map():
    names = {}
    for line in (ROOT / "build/SLUS_214.48.map").read_text(errors="replace").splitlines():
        m = re.match(r"\s+0x([0-9a-f]{8,16})\s+([A-Za-z_.$][\w.$]*)\s*$", line)
        if m:
            names[m.group(2)] = int(m.group(1), 16)
    return names


def linked_asm():
    """asm files the current linker script uses (a re-split leaves stale ones)."""
    ld = (ROOT / "build/SLUS_214.48.ld").read_text()
    return sorted(ROOT / f"{p}.s" for p in set(re.findall(r"build/(asm/\S+?)\.o\(", ld)))


def parse_asm(names):
    """Functions in .text proper: start -> dict(name, refs, data, bss, calls)."""
    funcs = {}
    for path in linked_asm():
        if "/data/" in str(path) or "/inline/" in str(path):
            continue
        label, cur = None, None
        for line in path.read_text(errors="replace").splitlines():
            m = re.match(r"(glabel|jlabel) (\S+)", line)
            if m:
                label = m.group(2)
                continue
            m = re.match(r"\s+/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)", line)
            if not m:
                continue
            pc = int(m.group(1), 16)
            if label is not None:
                cur = funcs.setdefault(pc, dict(name=label, refs=set(), data=set(), bss=set(),
                                                calls=set()))
                label = None
            if cur is None or not TEXT_START <= pc < TEXT_END:
                continue
            op, args = m.group(2), m.group(3)
            for sym in re.findall(r"%(?:lo|hi|gp_rel)\(([^)+\-\s]+)", args):
                a = resolve(sym, names)
                if a is None:
                    continue
                for key, (lo, hi) in (("refs", RODATA), ("data", DATA), ("bss", BSS)):
                    if lo <= a < hi:
                        cur[key].add(a)
            if op == "jal":
                a = resolve(args.split()[0], names)
                if a is not None:
                    cur["calls"].add(a)
    return funcs


def resolve(sym, names):
    if sym in names:
        return names[sym]
    m = re.match(r"(?:D|jtbl|func|STR|FLT|DBL)_([0-9A-F]{6,8})$", sym)
    return int(m.group(1), 16) if m else None


def known_files():
    """[(addr, file)] for functions tagged with exactly one .c/.cpp."""
    tags = []
    with open(ROOT / "symbols/function_sources.tsv") as f:
        for row in csv.DictReader(f, delimiter="\t"):
            cpp = [p for p in row["source_files"].split(", ") if not p.endswith(".h")]
            if len(cpp) == 1:
                tags.append((int(row["addr"], 16), cpp[0]))
    return sorted(tags)


def function_classes():
    cls = {}
    with open(ROOT / "symbols/ghidra_symbols.tsv") as f:
        for row in csv.DictReader(f, delimiter="\t"):
            if row["class"] and row["kind"] != "vtable":
                cls[int(row["addr"], 16)] = row["class"]
    return cls


def main():
    names = load_map()
    funcs = parse_asm(names)
    starts = sorted(funcs)
    tags = known_files()
    rom = (ROOT / "build/SLUS_214.48.rom").read_bytes()

    # The game code ends where the SDK objects begin: they are 8-aligned, so
    # the first function after the last tagged one that follows nop padding.
    last_game = max(a for a, _ in tags)
    game_end = next((b for a, b in zip(starts, starts[1:])
                     if b > last_game and has_padding(rom, a, b)), TEXT_END)
    game = [a for a in starts if a < game_end]
    lib = [a for a in starts if a >= game_end]
    lib_ro = min((r for a in lib for r in funcs[a]["refs"]), default=RODATA[1])
    refs = [{r for r in funcs[a]["refs"] if r < lib_ro} for a in game]
    n = len(game)

    pmax, cur = [0] * n, 0
    for k in range(n):
        cur = max([cur, *refs[k]])
        pmax[k] = cur
    smin, cur = [RODATA[1]] * (n + 1), RODATA[1]
    for k in range(n - 1, -1, -1):
        cur = min([cur, *refs[k]])
        smin[k] = cur

    def violations(k):
        """References that a cut after game[k] would leave on the wrong side."""
        return sum(1 for j in range(k + 1, n) for r in refs[j] if r < pmax[k])

    # Class -> majority file, and call-graph neighbours, from the tags.
    tag_of = dict(tags)
    classes = function_classes()
    votes = defaultdict(Counter)
    for a, f in tags:
        if a in classes:
            votes[classes[a]][f] += 1
    class_file = {c: v.most_common(1)[0][0] for c, v in votes.items()}
    callers = defaultdict(set)
    for a in game:
        for t in funcs[a]["calls"]:
            callers[t].add(a)

    def evidence(a):
        ev = Counter()
        if classes.get(a) in class_file:
            ev[class_file[classes[a]]] += 2
        for other in funcs[a]["calls"] | callers[a]:
            if other in tag_of:
                ev[tag_of[other]] += 1
        return ev

    # Runs of known files, in address order.
    runs = []
    for a, f in tags:
        if a >= game_end:
            continue
        if runs and runs[-1][2] == f:
            runs[-1][1] = a
        else:
            runs.append([a, a, f])

    # Everything before the first tagged function is crt0 plus whatever
    # untagged code precedes it.
    first = bisect.bisect_left(game, runs[0][0])
    rows = [[game[0], None, "sdk/crt0", "likely"],
            [game[first], None, module_name(runs[0][2]), "likely"]]
    for (_, e1, f1), (s2, _, f2) in zip(runs, runs[1:]):
        i, j = bisect.bisect_left(game, e1), bisect.bisect_left(game, s2)
        cands = range(i, j)
        clean = [k for k in cands if pmax[k] < smin[k + 1]]
        pool = clean or list(cands)
        best = min(pool, key=lambda k: (violations(k) if not clean else 0,
                                        -score(k, i, j, game, evidence, f1, f2), k))
        conf = "certain" if len(clean) == 1 else "likely" if clean else "conflict"
        rows.append([game[best + 1], None, module_name(f2), conf])

    assign_rodata(rows, game, refs, names, lib_ro)
    rows += sdk_rows(game_end, lib_ro, TEXT_END)
    for r in rows:
        r[2:2] = [None, None]  # data, bss
    stats = assign_owned(rows, funcs, names, rom)

    out = ROOT / "config/splits.tsv"
    with open(out, "w") as f:
        f.write("# Generated by tools/split_files.py: where each original file starts.\n")
        f.write("# confidence: certain = only one consistent cut; likely = chosen among several\n")
        f.write("# by class/call evidence; conflict = no cut separates the .rodata references;\n")
        f.write("# signature = SDK library identified by tools/sce_symbols.py; unknown = unidentified.\n")
        f.write("# rodata/data/bss '-' = no chunk of its own (shares the previous file's).\n")
        f.write("text\trodata\tdata\tbss\tfile\tconfidence\n")
        for t, ro, da, bs, name, conf in rows:
            cols = [f"{t:08X}"] + ["-" if x is None else f"{x:08X}" for x in (ro, da, bs)]
            f.write("\t".join(cols + [name, conf]) + "\n")
    print(f"{len(rows)} files -> {out.relative_to(ROOT)}; game code ends at 0x{game_end:08X}")
    print("confidence:", dict(Counter(r[5] for r in rows)))
    for sec, (owned, kept) in stats.items():
        print(f"{sec}: {owned} symbols with a single owner, {kept} consistent with link order, "
              f"{sum(1 for r in rows if r[2 if sec == '.data' else 3] is not None)} files get a chunk")


def has_padding(rom, a, b):
    """True if the function at `a` ends with nop padding before `b`."""
    words = [int.from_bytes(rom[o - TEXT_START:o - TEXT_START + 4], "little") for o in range(a, b, 4)]
    k = len(words)
    while k and words[k - 1] == 0:
        k -= 1
    jr = max((i for i, w in enumerate(words[:k + 1]) if w == 0x03E00008), default=-1)
    end = max(k, jr + 2) if jr >= 0 else k
    return len(words) > end


def score(k, i, j, game, evidence, f1, f2):
    """How well a cut after game[k] agrees with class/call evidence in the gap."""
    s = 0
    for m in range(i + 1, j):
        ev = evidence(game[m])
        s += ev[f1] - ev[f2] if m <= k else ev[f2] - ev[f1]
    return s


def assign_rodata(rows, game, refs, names, lib_ro):
    """Give each game file the .rodata chunk its functions reference.

    Chunks are in link order, so each file's chunk starts where the fewest
    references would land in the wrong file: earlier files' references at or
    after the cut, or this file's before it. With clean data that is the
    first 8-aligned symbol after the previous files' last reference. Files
    that reference no .rodata get none (they share the previous chunk).
    """
    cands = sorted({a for a in names.values() if RODATA[0] <= a < lib_ro and a % 8 == 0})
    bounds = [bisect.bisect_left(game, r[0]) for r in rows] + [len(game)]
    per_file = [sorted(x for k in range(bounds[i], bounds[i + 1]) for x in refs[k])
                for i in range(len(rows))]
    before, last = [], RODATA[0] - 1
    for i, mine in enumerate(per_file):
        if not mine:
            continue
        if last < RODATA[0]:
            cut = RODATA[0]
        else:
            lo = bisect.bisect_right(cands, last)
            hi = bisect.bisect_right(cands, mine[-1])
            def wrong(c):
                return (len(before) - bisect.bisect_left(before, c)) + bisect.bisect_left(mine, c)
            options = cands[lo:hi] or [cands[lo]] if lo < len(cands) else []
            if not options:
                continue
            cut = min(options, key=lambda c: (wrong(c), c))
        rows[i][1] = cut
        last = cut
        before = sorted(before + mine)


def assign_owned(rows, funcs, names, rom):
    """Fill the data/bss columns of `rows` from single-owner symbols."""
    starts = [r[0] for r in rows]
    ro_rows = [(r[1], i) for i, r in enumerate(rows) if r[1] is not None]
    ro_starts = [a for a, _ in ro_rows]

    def file_of(addr):
        return bisect.bisect_right(starts, addr) - 1

    def ro_file_of(addr):
        k = bisect.bisect_right(ro_starts, addr) - 1
        return ro_rows[k][1] if k >= 0 else None

    stats = {}
    for col, key, (lo, hi), name in ((2, "data", DATA, ".data"), (3, "bss", BSS, ".bss")):
        syms = sorted({a for a in names.values() if lo <= a < hi} | {lo})
        owners = defaultdict(set)
        for f, info in funcs.items():
            for a in info[key]:
                owners[a].add(file_of(f))
        if key == "data":
            # Tables of pointers into one file's functions or .rodata.
            for addr in range(lo, hi, 4):
                v = int.from_bytes(rom[addr - TEXT_START:addr - TEXT_START + 4], "little")
                owner = (file_of(v) if v in funcs else
                         ro_file_of(v) if RODATA[0] <= v < RODATA[1] else None)
                if owner is not None:
                    owners[syms[bisect.bisect_right(syms, addr) - 1]].add(owner)
        points = sorted((a, next(iter(o))) for a, o in owners.items() if len(o) == 1)
        keep = longest_nondecreasing([f for _, f in points])
        kept = [points[i] for i in keep]
        # Each owner's chunk starts at the first 8-aligned symbol after the
        # previous owner's last kept symbol (the first owner at the section start).
        prev_a, prev_f = None, None
        for a, f in kept:
            if f != prev_f and rows[f][col] is None:
                if prev_a is None:
                    rows[f][col] = lo
                else:
                    i = bisect.bisect_right(syms, prev_a)
                    while i < len(syms) and syms[i] < a and syms[i] % 8:
                        i += 1
                    rows[f][col] = syms[i] if i < len(syms) and syms[i] <= a else a
            prev_a, prev_f = a, f
        stats[name] = (len(points), len(kept))
    return stats


def longest_nondecreasing(seq):
    """Indices of a longest non-decreasing subsequence of `seq`."""
    tails, tails_i, prev = [], [], [-1] * len(seq)
    for i, x in enumerate(seq):
        j = bisect.bisect_right(tails, x)
        if j == len(tails):
            tails.append(x)
            tails_i.append(i)
        else:
            tails[j], tails_i[j] = x, i
        prev[i] = tails_i[j - 1] if j else -1
    out, k = [], tails_i[-1] if tails_i else -1
    while k != -1:
        out.append(k)
        k = prev[k]
    return out[::-1]


def sdk_rows(game_end, lib_ro, text_end):
    """One segment per run of functions from the same SDK library."""
    runs = []
    path = ROOT / "symbols/sce_symbols.tsv"
    if path.exists():
        for line in path.read_text().splitlines():
            if line.startswith(("#", "addr")):
                continue
            a, lib, *_ = line.split("\t")
            a = int(a, 16)
            if a < game_end or a >= text_end:
                continue
            if not runs or runs[-1][1] != lib:
                runs.append([a, lib])
    rows, seen = [], Counter()
    if not runs or runs[0][0] > game_end:
        rows.append([game_end, lib_ro, f"sdk/unknown_{game_end:08X}", "unknown"])
    for a, lib in runs:
        seen[lib] += 1
        name = f"sdk/{lib}" + (f"_{seen[lib]}" if seen[lib] > 1 else "")
        rows.append([a, None if rows else lib_ro, name, "signature"])
    return rows


def module_name(path):
    return re.sub(r"\.(cpp|c)$", "", path)


if __name__ == "__main__":
    main()
