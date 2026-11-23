#!/usr/bin/env python3
"""A fact sheet for class-header work on one file, so the work can start
without reading the whole .cpp (it is often thousands of lines).

    tools/.venv/Scripts/python.exe tools/header_brief.py unk/EffWater1     # prints; also build/briefs/unk/EffWater1.md

Sections: the file's address range; its classes and their methods from the
game's symbols (with each function's state here: C, NON_MATCHING with its
measured distance, or asm); the headers it includes and the classes they
already define; the M2C_FIELD offsets each function uses (what a header
must provide); the layout tools/layouts.py infers from the asm for the
file's classes; the NON_MATCHING attempts closest first.
"""
import collections
import csv
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "src"


def file_range(name):
    rows = [l.split("\t") for l in (ROOT / "config/splits.tsv").read_text().splitlines()
            if l and not l.startswith("#")]
    starts = sorted((int(r[0], 16), r[4]) for r in rows if len(r) > 4 and re.fullmatch(r"[0-9A-Fa-f]{8}", r[0]))
    for i, (a, n) in enumerate(starts):
        if n == name:
            return a, starts[i + 1][0] if i + 1 < len(starts) else None
    return None, None


def states(text):
    """{function: 'asm' | 'near' | 'C'} for the names the file mentions."""
    out = {}
    nm = set(re.findall(r'^#else\nINCLUDE_ASM\("[^"]+", (\w+)\);', text, re.M))
    for fn in re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', text):
        out[fn] = "near" if fn in nm else "asm"
    return out


def triage():
    out = {}
    p = ROOT / "build/regalloc_triage.tsv"
    if p.exists():
        for l in p.read_text(encoding="utf8").splitlines()[1:]:
            w = l.split("\t")
            if len(w) >= 4:
                e = re.search(r"(\d+) edits", w[3])
                out[(w[0], w[1])] = (w[2], int(e.group(1)) if e else None)
    return out


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    name = sys.argv[1].removeprefix("src/").removesuffix(".cpp")
    text = (SRC / f"{name}.cpp").read_text(encoding="utf8", errors="replace")
    lo, hi = file_range(name)
    st, tri = states(text), triage()
    out = [f"# {name}: fact sheet (tools/header_brief.py)", ""]
    out.append(f"{len(text.splitlines())} lines; .text {lo:#x}-{hi:#x}" if lo else f"{len(text.splitlines())} lines")
    out.append(f"functions: {sum(1 for v in st.values() if v == 'asm')} asm, "
               f"{sum(1 for v in st.values() if v == 'near')} NON_MATCHING, the rest C")
    # classes and methods from the symbols
    by_cls = collections.defaultdict(list)
    for r in csv.DictReader(open(ROOT / "symbols/ghidra_symbols.tsv", encoding="utf8"), delimiter="\t"):
        a = int(r["addr"], 16)
        if lo and lo <= a < (hi or 1 << 32) and r["class"]:
            fn = r["mangled"] if r["mangled"] in st or r["mangled"] in text else f"func_{a:08X}"
            alias = f"{r['class']}__{r['name']}"
            s = st.get(fn) or st.get(alias) or ("C" if (fn in text or alias in text) else "?")
            by_cls[r["class"]].append(f"{r['name']} ({a:#x}, {r['kind']}, {s})")
    out += ["", "## Classes here (game symbols)", ""]
    for c, ms in sorted(by_cls.items(), key=lambda kv: -len(kv[1])):
        out.append(f"- **{c}**: " + ", ".join(ms[:24]) + (" ..." if len(ms) > 24 else ""))
    if not by_cls:
        out.append("(no class symbols in this range: free functions; arg0's type comes from the callers or the data)")
    # headers
    out += ["", "## Headers included and the classes they define", ""]
    for inc in re.findall(r'^\s*#\s*include\s+"([^"]+)"', text, re.M):
        p = next((q for q in (SRC / inc, (SRC / name).parent / inc) if q.exists()), None)
        if p:
            cls = re.findall(r"^(?:class|struct)\s+([A-Za-z_]\w*)\s*(?::[^{;]*)?\{", p.read_text(encoding="utf8", errors="replace"), re.M)
            out.append(f"- {inc}: {', '.join(cls[:20])}" + (" ..." if len(cls) > 20 else ""))
        else:
            out.append(f"- {inc} (include/)")
    local = re.findall(r"^(?:class|struct)\s+([A-Za-z_]\w*)\s*(?::[^{;]*)?\{", text, re.M)
    if local:
        out.append(f"- defined in the .cpp itself: {', '.join(local[:30])}" + (" ..." if len(local) > 30 else ""))
    # M2C_FIELD per function
    out += ["", "## M2C_FIELD offsets by function (what a header must give)", ""]
    import perm_official as po
    for kind, it in po.top_items(text.replace("#ifdef NON_MATCHING", "").replace("#else", "").replace("#endif", "")):
        if kind != "func":
            continue
        uses = re.findall(r"M2C_FIELD\(\s*([^,]+?)\s*,\s*([^,]+?)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*\)", it)
        if not uses:
            continue
        head = re.search(r"([A-Za-z_][\w:]*)\s*\(", it.split("{", 1)[0])
        recv = collections.Counter(u[0] for u in uses)
        offs = sorted({(u[0], int(u[2], 0), u[1].rstrip(" *")) for u in uses}, key=lambda t: (t[0], t[1]))
        out.append(f"- {head.group(1) if head else '?'}: {len(uses)} uses; "
                   + "; ".join(f"{r}: " + ", ".join(f"{o:#x} {t}" for rr, o, t in offs if rr == r)[:200]
                               for r, _ in recv.most_common(3)))
    # layouts of the classes here
    if by_cls:
        top = [c for c, _ in sorted(by_cls.items(), key=lambda kv: -len(kv[1]))[:4]]
        r = subprocess.run([sys.executable, str(ROOT / "tools/layouts.py"), *top], cwd=ROOT, capture_output=True, text=True)
        out += ["", "## Layouts from the asm (tools/layouts.py; offsets the methods use on this)", "", "```cpp",
                r.stdout.strip()[:6000], "```"]
    # local hints: RoR-Port's descriptive names mapped by tools/map_pal_names.py
    # (build/ror_port_names.tsv, not committed: GPL project, guesses)
    hints = ROOT / "build" / "ror_port_names.tsv"
    if lo and hints.exists():
        rows = [l.split("\t") for l in hints.read_text(encoding="utf8").splitlines()[1:]]
        here = [r for r in rows if lo <= int(r[0], 16) < (hi or 1 << 32)]
        if here:
            out += ["", "## Hints from RoR-Port (local only; their guesses: verify, do not copy names into src/; addresses inside their notes are PAL, not ours)", ""]
            out += [f"- {r[0]} {r[4]}: \"{r[2]}\" — {r[7][:160]}" for r in here[:40]]
    # attempts
    near = sorted(((d or 999, fn, k) for (f, fn), (k, d) in tri.items() if f == name), key=lambda t: t[0])
    out += ["", "## NON_MATCHING attempts, closest first (build/regalloc_triage.tsv)", ""]
    out += [f"- {fn}: {k}, {d if d != 999 else '?'} edits" for d, fn, k in near[:25]] or ["(none measured)"]
    text_out = "\n".join(out) + "\n"
    dest = ROOT / "build" / "briefs" / f"{name}.md"
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text(text_out, encoding="utf8")
    if sys.platform == "win32":
        sys.stdout.reconfigure(encoding="utf-8")
    print(text_out)


if __name__ == "__main__":
    sys.path.insert(0, str(ROOT / "tools"))
    main()
