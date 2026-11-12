#!/usr/bin/env python3
"""Twins: functions still in asm whose instruction sequence (the mnemonics,
in order) is the same as a function already in C++.

    tools/.venv/bin/python tools/twins.py                 # how many, with examples
    tools/.venv/bin/python tools/twins.py mag/maglifepc   # one file's pending twins

A twin's C++ is usually the matched one with other names, offsets or
constants, so it is the best first draft there is: tools/work.py puts it in
the scratch file, and tools/backlog.py hands out functions with a twin first.
Shapes come from the whole-file asm/<file>.s (splat keeps it for decompiled
files too) and are cached in build/twins.json, per file, by its mtime.
"""
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import backlog  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
CACHE = ROOT / "build/twins.json"
FUNC = re.compile(r"^\s*(?:nonmatching|glabel)\s+([^\s,]+)")
INSN = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(\S+)")
MIN_INSNS = 6                      # shorter ones are all alike


def file_shapes(name):
    """{function: "mnemonic mnemonic ..."} of asm/<name>.s."""
    out, fn = {}, None
    path = ROOT / "asm" / f"{name}.s"
    if not path.exists():
        return out
    for line in path.read_text(errors="replace").splitlines():
        m = FUNC.match(line)
        if m:
            fn = m.group(1) if not m.group(1).startswith(("D_", "jtbl_")) else None
            if fn:
                out.setdefault(fn, [])
            continue
        m = INSN.match(line)
        if m and fn:
            out[fn].append(m.group(1))
    return {f: " ".join(v) for f, v in out.items() if len(v) >= MIN_INSNS}


def all_files():
    return sorted(p.relative_to(ROOT / "src").with_suffix("").as_posix()
                  for p in (ROOT / "src").rglob("*.cpp"))


def index():
    """(matched: {shape: [(file, fn)]}, pending: {(file, fn): shape})."""
    try:
        cache = json.loads(CACHE.read_text())
    except (OSError, ValueError):
        cache = {}
    changed = False
    matched, pending = {}, {}
    for name in all_files():
        asm, cpp = ROOT / "asm" / f"{name}.s", ROOT / "src" / f"{name}.cpp"
        if not asm.exists():
            continue
        key = f"{asm.stat().st_mtime_ns}"
        if cache.get(name, {}).get("key") != key:
            cache[name] = {"key": key, "shapes": file_shapes(name)}
            changed = True
        todo = {f for f, _ in backlog.pending(cpp)}
        for fn, shape in cache[name]["shapes"].items():
            if fn in todo:
                pending[(name, fn)] = shape
            else:
                matched.setdefault(shape, []).append((name, fn))
    if changed:
        CACHE.parent.mkdir(parents=True, exist_ok=True)
        CACHE.write_text(json.dumps(cache))
    return matched, pending


def twin_of(name, fn, idx=None):
    """The matched (file, fn) with the same shape as this pending one, or None.
    One in the same file wins."""
    matched, pending = idx or index()
    cands = matched.get(pending.get((name, fn)), [])
    return next((c for c in cands if c[0] == name), cands[0] if cands else None)


def source_of(name, fn):
    """The C++ text of a function in src/<name>.cpp, found by its name, or None."""
    text = (ROOT / "src" / f"{name}.cpp").read_text(errors="replace")
    names = [re.escape(fn)]               # extern "C" name or asm("...") label
    alias = re.search(rf"\b(\w+)\s*\([^;{{]*\)[^;{{]*asm\(\"{re.escape(fn)}\"\)\s*;", text)
    if alias:                             # declared under another C name
        names.append(re.escape(alias.group(1)))
    g = re.match(r"^(\w+?)__(\d+)([A-Za-z_]\w*)", fn)   # method__<n>Class...
    if g:
        names.append(re.escape(g.group(3)[: int(g.group(2))] + "::" + g.group(1)))
    elif "__" in fn and not fn.startswith("_"):
        names.append(re.escape(fn.split("__")[0]) + r"(?=\s*\()")  # func__F<args>
    m = None
    for n in names:
        m = re.search(rf"^[^\n;{{}}#]*\b{n}\s*\([^;{{]*\)[^;{{]*\{{", text, re.M)
        if not m and n == names[0]:   # a member with an asm label: the label comes after
            m = re.search(rf"^[^\n;{{}}#]*\([^;{{]*\)[^;{{]*asm\(\"{n}\"\)[^;{{]*\{{", text, re.M)
        if m:
            break
    if not m:
        return None
    depth, i = 0, m.end() - 1
    while i < len(text):
        depth += {"{": 1, "}": -1}.get(text[i], 0)
        if depth == 0:
            return text[m.start():i + 1]
        i += 1
    return None


def main():
    idx = index()
    matched, pending = idx
    names = sys.argv[1:]
    rows = [(k, twin_of(*k, idx)) for k in sorted(pending) if not names or k[0] in names]
    rows = [(k, t) for k, t in rows if t]
    for (f, fn), (tf, tfn) in rows[: None if names else 15]:
        print(f"{f} {fn}  ==  {tf} {tfn}  ({len(pending[(f, fn)].split())} insns)")
    print(f"{len(rows)} pending functions have a matched twin")


if __name__ == "__main__":
    main()
