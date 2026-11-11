#!/usr/bin/env python3
"""Work on one function: a scratch file, and its diff with the game on every save.

    tools/.venv/bin/python tools/match.py --server start        # once: 1.5 s compiles
    tools/.venv/bin/python tools/work.py mag/maglifepc func_0011B2C4          # start, or check
    tools/.venv/bin/python tools/work.py mag/maglifepc func_0011B2C4 --watch  # check on every save
    tools/.venv/bin/python tools/work.py mag/maglifepc func_0011B2C4 --done   # into src/ if it matches

The first call writes build/work/<file>/<function>.cpp: m2c's draft as a
comment, and under it a first version of the function (auto_m2c's mechanical
translation when there is one, else the INCLUDE_ASM line itself). Edit what
is under the "// ---- function" line; lines above it and under the "// ----
declarations" line go right after the file's #includes (prototypes, externs,
classes you are trying out).

Each check puts the function in a copy of src/<file>.cpp in place of its
INCLUDE_ASM (the function is compiled with everything the file already
includes and declares), compiles it and prints the function's status and,
if it differs, the instructions side by side: game | ours. src/ is only
touched by --done.
"""
import argparse
import re
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import auto_m2c as auto  # noqa: E402
import match  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
WORK = ROOT / "build/work"
DECL, FUNC = "// ---- declarations", "// ---- function"


def include_line(name, fn):
    return f'INCLUDE_ASM("asm/nonmatchings/{name}", {fn});'


def start(name, fn, path):
    src = ROOT / f"src/{name}.cpp"
    if not src.exists():
        sys.exit(f"src/{name}.cpp does not exist: start the file first (docs/DECOMPILING.md, step 1)")
    if include_line(name, fn) not in src.read_text(encoding="utf8"):
        sys.exit(f"no {include_line(name, fn)} in src/{name}.cpp")
    draft = auto.m2c(name, "sig", auto.EE_FLAGS, auto.CONTEXT if auto.CONTEXT.exists() else None)
    found = next(((h, b) for h, b in auto.FUNC_RE.findall(draft)
                  if re.match(r"^.*?\b(\w+)\(", h).group(1) == fn), None)
    pre, text = [], include_line(name, fn) + "\n"
    comment = "// m2c has no draft for this function\n"
    if found:
        hdr, body = found
        comment = "".join(f"// {ln}\n" for ln in (hdr + "\n" + body + "}").split("\n"))
        ctx = auto.Context()
        ctx.funcs, ctx.labels = auto.asm_functions(name), auto.string_labels(name)
        ctx.sigs = auto.signatures(1) if auto.SIGS.exists() else {}
        ctx.protos, ctx.globals = auto.prototypes(draft), auto.global_types(draft)
        ctx.text = src.read_text(encoding="utf8")
        try:
            c = auto.typed(ctx, fn, hdr, body)
            pre, text = sorted(c.pre), c.text
        except auto.Reject as e:
            comment += f"// (no mechanical translation: {e})\n"
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(f"// {name}, {fn}: m2c's draft\n{comment}\n{DECL}\n" + "".join(d + "\n" for d in pre)
                    + f"\n{FUNC}\n{text}", encoding="utf8", newline="\n")
    print(f"wrote {path.relative_to(ROOT)}")


def assemble(name, fn, path):
    work = path.read_text(encoding="utf8")
    if DECL not in work or FUNC not in work:
        sys.exit(f"{path.name}: the '{DECL}' and '{FUNC}' lines must stay")
    decls = work[work.index(DECL) + len(DECL):work.index(FUNC)].strip("\n")
    func = work[work.index(FUNC) + len(FUNC):].strip("\n")
    text = (ROOT / f"src/{name}.cpp").read_text(encoding="utf8")
    have = set(text.split("\n"))
    block = "".join(d + "\n" for d in decls.split("\n") if d.strip() and d not in have)
    ends = [m.end() for m in re.finditer(r"^#include [^\n]*\n", text, re.M)]
    at = ends[-1] if ends else 0
    text = text[:at] + block + text[at:]
    if include_line(name, fn) not in text:
        sys.exit(f"{fn} is no longer INCLUDE_ASM in src/{name}.cpp")
    return text.replace(include_line(name, fn), func, 1)


def check(name, fn, path, quiet=False):
    """Print the function's comparison; return whether it and the object match."""
    trial = WORK / name / f"{fn}.trial.cpp"
    trial.write_text(assemble(name, fn, path), encoding="utf8", newline="\n")
    try:
        ok, report = match.compare(name, trial, diff=True)
    except match.CompileError as e:
        print(re.sub(r"^.*?\.cpp:", f"{name}.cpp:", str(e).strip(), flags=re.M))
        return False, False
    mine, on, good = [], False, False
    for line in report:
        g = re.match(r"^  0x[0-9A-F]+ (\S+)\s+0x[0-9a-f]+\s+(.*)$", line)
        if g or line.startswith("  .") or not line.startswith(" "):
            on = bool(g) and g.group(1) == fn
            if on:
                good = g.group(2).strip().endswith("MATCH")
        if on:
            mine.append(line)
    print("\n".join(mine[:1] if good or quiet else mine))
    if good and not ok:
        print("the function matches, but not the whole object:")
        print("\n".join(ln for ln in report if ln.startswith("  .") or "NOT MATCHING" in ln))
    return good, ok


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name", help="file as in config/splits.tsv, e.g. mag/maglifepc")
    ap.add_argument("function")
    ap.add_argument("--watch", action="store_true", help="check again whenever the scratch file is saved")
    ap.add_argument("--done", action="store_true", help="write the function into src/ if the object matches")
    a = ap.parse_args()
    name = a.name.removeprefix("src/").removesuffix(".cpp")
    path = WORK / name / f"{a.function}.cpp"
    if not match.server_up():
        print("compile server down (tools/match.py --server start): each check takes a minute on Windows")
    if not path.exists():
        start(name, a.function, path)
    good, ok = check(name, a.function, path)
    if a.done:
        if not (good and ok):
            sys.exit("not written: it does not match")
        (ROOT / f"src/{name}.cpp").write_text(assemble(name, a.function, path), encoding="utf8", newline="\n")
        path.rename(path.with_suffix(".done.cpp"))
        print(f"src/{name}.cpp updated. Before committing: tools/dock python3 tools/configure.py && tools/dock ninja")
    while a.watch:
        seen = path.stat().st_mtime
        while path.stat().st_mtime == seen:
            time.sleep(0.3)
        print(f"\n--- {time.strftime('%H:%M:%S')}")
        check(name, a.function, path)


if __name__ == "__main__":
    main()
