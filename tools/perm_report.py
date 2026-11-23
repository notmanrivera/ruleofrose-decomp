#!/usr/bin/env python3
"""What the permuters' runs teach: read their logs and outputs, and say what
to improve next.

    tools/.venv/Scripts/python.exe tools/perm_report.py        # prints, and writes build/workers/perm-report.md

- Cyrax (tools/permute.py): which rewrites improve or match near misses,
  from build/workers/cyrax-stats.tsv (permute.py also weighs its choices by
  it) and the "via" of each improvement in build/workers/perm-loop.log.
- Sektor (tools/perm_official.py): why near misses could not be prepared
  (the converter's next fix), from build/workers/perm-official.log; and
  what decomp-permuter changed in the variants that got closer (ideas for
  Cyrax rewrites), from build/perm_off/<file>/<fn>/out in every worktree.
"""
import collections
import difflib
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
WORKERS = ROOT / "build" / "workers"


def cyrax():
    out = ["## Cyrax: rewrites that work", ""]
    p = WORKERS / "cyrax-stats.tsv"
    rows = []
    if p.exists():
        for ln in p.read_text().splitlines()[1:]:
            w = ln.split("\t")
            if len(w) >= 4:
                rows.append((w[0], int(w[1]), int(w[2]), int(w[3])))
    if rows:
        out.append("| rewrite | tried | improved | matched | improved per 1000 tries |")
        out.append("|---|---:|---:|---:|---:|")
        for n, t, i, m in sorted(rows, key=lambda r: (-r[3], -r[2], -r[1])):
            out.append(f"| {n} | {t} | {i} | {m} | {1000 * i / t if t else 0:.1f} |")
        dead = [n for n, t, i, m in rows if t >= 500 and i == 0]
        if dead:
            out.append("")
            out.append(f"Never helped in 500+ tries (candidates to drop or fix): {', '.join(sorted(dead))}")
    via = collections.Counter()
    log = WORKERS / "perm-loop.log"
    if log.exists():
        for ln in log.read_text(errors="replace").splitlines():
            m = re.search(r"\bvia (\S+)", ln)
            if m:
                via[m.group(1)] += 1
    if via:
        out.append("")
        out.append("Chains behind the improvements in perm-loop.log: "
                   + ", ".join(f"{k} ({v})" for k, v in via.most_common(10)))
    return out


def failure_class(reason):
    """A short class of a Sektor preparation failure."""
    r = reason
    if "parser rejects" in r:
        return "the C parser rejects the function (C++ left in it: methods, references, virtual calls...)"
    errs = re.findall(r"x\.cpp:\d+: ([^\n]*?)(?= x\.cpp:\d+:|$)", r)
    errs = [e for e in errs if not e.startswith("warning")]
    if errs:
        e = re.sub(r"`[^']*'", "`X'", errs[0])
        return "base.c: " + e[:90]
    if "base.c" in r:
        return "base.c does not compile (no message)"
    return r[:80]


def sektor_failures():
    out = ["## Sektor: why near misses could not be prepared", ""]
    log = WORKERS / "perm-official.log"
    if not log.exists():
        return out + ["(no log)"]
    last = {}
    lines = log.read_text(errors="replace").splitlines()
    # only the runs that keep the compiler's errors (from the first "== Sektor run" mark)
    first = next((i for i, ln in enumerate(lines) if ln.startswith("== Sektor run")), 0)
    for ln in lines[first:]:
        m = re.match(r"^\[\d+/\d+\] (\S+ \S+): skipped, (.*)$", ln)
        if m:
            last[m.group(1)] = m.group(2)
        m = re.match(r"^\[\d+/\d+\] (\S+ \S+): (MATCH|no match)", ln)
        if m:
            last.pop(m.group(1), None)
    c = collections.Counter(failure_class(r) for r in last.values())
    for k, v in c.most_common(12):
        out.append(f"- {v} x {k}")
    return out


def change_kind(a, b):
    """What one changed statement pair looks like."""
    na, nb = re.sub(r"\s+", " ", a.strip()), re.sub(r"\s+", " ", b.strip())
    if "new_var" in nb and "new_var" not in na:
        return ("temporary introduced (decomp-permuter's new_var)" if re.match(r"[\w\s\*]+new_var\w*\s*[=;]", nb)
                or not na else "an operand replaced by a temporary")
    if not na:
        return "statement added"
    if not nb:
        return "statement removed (moved or merged)"
    ta, tb = re.findall(r"\w+|\S", na), re.findall(r"\w+|\S", nb)
    if sorted(ta) == sorted(tb):
        return "same tokens, other order (operands swapped)"
    if re.sub(r"\([^()]*\)", "", na) == re.sub(r"\([^()]*\)", "", nb):
        return "cast or parenthesised part changed"
    if re.match(r"^(extern\s+)?[\w\s\*]+\(", na) and na.endswith(";") and nb.endswith(";") and "(" in nb:
        return "declaration changed (type of a callee or parameter)"
    if set(re.findall(r"\b(int|unsigned|short|char|float|long|s32|u32|u8|s8|u16|s16)\b", na)) != \
            set(re.findall(r"\b(int|unsigned|short|char|float|long|s32|u32|u8|s8|u16|s16)\b", nb)):
        return "a type changed"
    return "expression rewritten"


def statements(path, fn):
    """The function fn of a C file as a list of statements, spacing
    normalised (decomp-permuter reprints the whole file in its own style)."""
    import perm_official as po
    text = path.read_text(errors="replace")
    f = next((it for k, it in po.top_items(text) if k == "func" and re.search(rf"\b{re.escape(fn)}\s*\(", it.split("{", 1)[0])), None)
    if not f:
        return None
    f = re.sub(r"\s+", " ", f)
    f = re.sub(r"\s*([(){};,=+\-*/<>!&|\[\]])\s*", r"\1", f)      # no spaces around punctuation
    f = re.sub(r"\(\(([^()]*)\)\)", r"(\1)", f)                     # redundant parentheses
    return [s for s in re.split(r"(?<=[;{}])", f) if s.strip()]


def sektor_changes():
    out = ["## Sektor: what decomp-permuter changed in variants that got closer", ""]
    kinds = collections.Counter()
    examples = collections.defaultdict(list)
    n = 0
    for wt in [ROOT] + sorted(ROOT.parent.glob("ror-wt-*")):
        base_dir = wt / "build" / "perm_off"
        if not base_dir.exists():
            continue
        for d in base_dir.glob("*/*/*"):
            outs = sorted((d / "out").glob("output-*"), key=lambda p: int(p.name.split("-")[1])
                          if p.name.split("-")[1].isdigit() else 1 << 30)
            if not outs or not (d / "base.c").exists():
                continue
            src = outs[0] / "source.c"
            if not src.exists():
                continue
            a = statements(d / "base.c", d.name)
            b = statements(src, d.name)
            if not a or not b:
                continue
            n += 1
            # compared without parentheses: the reprint adds them everywhere
            ka, kb = [re.sub(r"[()]", "", s) for s in a], [re.sub(r"[()]", "", s) for s in b]
            sm = difflib.SequenceMatcher(None, ka, kb, autojunk=False)
            moved = collections.Counter(ka) & collections.Counter(kb)
            for tag, i1, i2, j1, j2 in sm.get_opcodes():
                if tag == "equal":
                    continue
                pa, pb = a[i1:i2], b[j1:j2]
                if sorted(ka[i1:i2]) == sorted(kb[j1:j2]):
                    kinds["statements reordered"] += 1
                    continue
                if tag == "replace" and len(pa) == len(pb):
                    pairs = list(zip(pa, pb))
                else:
                    # a statement removed here and added elsewhere is a move
                    pairs = [(x, "") for x, k in zip(pa, ka[i1:i2]) if not moved[k]] + \
                            [("", y) for y, k in zip(pb, kb[j1:j2]) if not moved[k]]
                    if len(pairs) < len(pa) + len(pb):
                        kinds["a statement moved"] += 1
                for x, y in pairs:
                    k = change_kind(x, y)
                    kinds[k] += 1
                    if len(examples[k]) < 3:
                        examples[k].append(f"`{x.strip()[:70]}` -> `{y.strip()[:70]}`  ({d.parent.name}/{d.name})")
    out.append(f"{n} improved variants read.")
    out.append("")
    for k, v in kinds.most_common(10):
        out.append(f"- {v} x {k}")
        for e in examples[k]:
            out.append(f"    - {e}")
    return out


def main():
    text = "\n".join(["# Permuter report (tools/perm_report.py)", ""] + cyrax() + [""] + sektor_failures()
                     + [""] + sektor_changes()) + "\n"
    (WORKERS / "perm-report.md").write_text(text, encoding="utf8")
    if sys.platform == "win32":
        sys.stdout.reconfigure(encoding="utf-8")
    print(text)


if __name__ == "__main__":
    main()
