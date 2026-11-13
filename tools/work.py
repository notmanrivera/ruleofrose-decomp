#!/usr/bin/env python3
"""Work on one function: a scratch file, and its diff with the game on every save.

    tools/.venv/bin/python tools/match.py --server start        # once: 1.5 s compiles
    tools/.venv/bin/python tools/work.py mag/maglifepc func_0011B2C4          # start, or check
    tools/.venv/bin/python tools/work.py mag/maglifepc func_0011B2C4 --watch  # check on every save
    tools/.venv/bin/python tools/work.py mag/maglifepc func_0011B2C4 --done   # into src/ if it matches
    tools/.venv/bin/python tools/work.py mag/maglifepc func_0011B2C4 --keep   # giving up: best try into src/

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
touched by --done and --keep.

Every check that compiles remembers the best version so far (fewest
instructions off) in build/work/.best/<file>/<function>.cpp. --keep writes
that one into src/ under #ifdef NON_MATCHING (the asm stays what is built):
it does what the game does, which the PC port can use, and the next try
starts from it. A function that already has a NON_MATCHING attempt starts
from that attempt, and --done replaces the whole #ifdef block.
"""
import argparse
import re
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import auto_m2c as auto  # noqa: E402
import match  # noqa: E402
import twins  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
WORK = ROOT / "build/work"
BEST = WORK / ".best"                 # apart from the scratch files: workers delete those
DECL, FUNC = "// ---- declarations", "// ---- function"


def nm_block(text, name, fn):
    """The '#ifdef NON_MATCHING ... #else INCLUDE_ASM #endif' block around the
    function's INCLUDE_ASM (with its '// NON_MATCHING' note), or None."""
    return re.search(r"(?:^// NON_MATCHING[^\n]*\n)?^#ifdef NON_MATCHING\n((?:(?!^#ifdef NON_MATCHING).)*?)^#else\n"
                     + re.escape(include_line(name, fn)) + r"\n#endif\n", text, re.S | re.M)


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
    old = nm_block(src.read_text(encoding="utf8"), name, fn)
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
    if old:                               # an earlier attempt beats m2c's draft
        text = old.group(1)
        comment += "// The function below is the NON_MATCHING attempt already in src/: go on from it.\n"
        print("starting from the NON_MATCHING attempt in src/")
    twin = twins.twin_of(name, fn)
    body = twins.source_of(*twin) if twin else None
    if body:
        comment += (f"//\n// Same instructions as {twin[0]} {twin[1]}, already matched: its C++\n"
                    "// with this function's names, offsets and constants is the best start.\n"
                    + "".join(f"// {ln}\n" for ln in body.split("\n")))
        print(f"twin: {twin[0]} {twin[1]} (its C++ is in the scratch file)")
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
    # one-line declarations the file already has are not repeated; anything
    # else (a class, an inline function) goes in whole
    block = "".join(d + "\n" for d in decls.split("\n")
                    if d.strip() and not (d in have and d.startswith(("#include", "#define", "extern "))))
    ends = [m.end() for m in re.finditer(r"^#include [^\n]*\n", text, re.M)]
    at = ends[-1] if ends else 0
    text = text[:at] + block + text[at:]
    if include_line(name, fn) not in text:
        sys.exit(f"{fn} is no longer INCLUDE_ASM in src/{name}.cpp")
    old = nm_block(text, name, fn)
    if old:                               # the attempt and its #ifdef go
        return text[:old.start()] + func + "\n" + text[old.end():]
    return text.replace(include_line(name, fn), func, 1)


def kept(name, fn, path, status):
    """src/<name>.cpp with the scratch file's function under #ifdef NON_MATCHING."""
    work = path.read_text(encoding="utf8")
    func = work[work.index(FUNC) + len(FUNC):].strip("\n")
    if func.strip() == include_line(name, fn):
        sys.exit("nothing to keep: the best version is still the INCLUDE_ASM line")
    block = (f"// NON_MATCHING: {status}\n#ifdef NON_MATCHING\n{func}\n#else\n"
             f"{include_line(name, fn)}\n#endif")
    text = assemble(name, fn, path)       # the declarations go in as for a check
    return text.replace(func, block, 1) if func in text else None


def score(status):
    """Instructions off for a check's status text ('MATCH' 0, '8/23 differ' 8);
    a wrong size or differing relocations count extra."""
    if status.endswith("MATCH"):
        return 0
    m = re.search(r"(\d+)/\d+ differ", status)
    n = int(m.group(1)) if m else 0
    r = re.search(r"(\d+) relocs? differ", status)
    n += int(r.group(1)) if r else 0
    return n + (1000 if "size" in status else 0)


def check(name, fn, path, quiet=False):
    """Print the function's comparison; return whether it and the object match."""
    trial = WORK / name / f"{fn}.trial.cpp"
    trial.write_text(assemble(name, fn, path), encoding="utf8", newline="\n")
    try:
        ok, report = match.compare(name, trial, diff=True)
    except match.CompileError as e:
        print(re.sub(r"^.*?\.cpp:", f"{name}.cpp:", str(e).strip(), flags=re.M))
        return False, False
    mine, on, good, status = [], False, False, None
    for line in report:
        g = re.match(r"^  0x[0-9A-F]+ (\S+)\s+0x[0-9a-f]+\s+(.*)$", line)
        if g or line.startswith("  .") or not line.startswith(" "):
            on = bool(g) and g.group(1) == fn
            if on:
                status = g.group(2).strip()
                good = status.endswith("MATCH")
        if on:
            mine.append(line)
    print("\n".join(mine[:1] if good or quiet else mine))
    if status is not None:                # compiled: is it the best one yet?
        best = BEST / name / f"{fn}.cpp"
        prev = best.read_text(encoding="utf8").split("\n", 1)[0].removeprefix("// best: ") if best.exists() else None
        if prev is None or score(status) <= score(prev):
            best.parent.mkdir(parents=True, exist_ok=True)
            best.write_text(f"// best: {status}\n" + path.read_text(encoding="utf8"), encoding="utf8", newline="\n")
    if good and not ok:
        print("the function matches, but not the whole object:")
        print("\n".join(ln for ln in report if ln.startswith("  .") or "NOT MATCHING" in ln
                        or (re.match(r"^  0x", ln) and not re.search(r"(MATCH|asm)$", ln))))
    return good, ok


def keep(name, fn):
    best = BEST / name / f"{fn}.cpp"
    if not best.exists():
        sys.exit(f"no best version of {fn} yet: check it with work.py first")
    status, body = best.read_text(encoding="utf8").split("\n", 1)
    status = status.removeprefix("// best: ")
    if status.endswith("MATCH"):
        sys.exit("its best version matches: use --done")
    tmp = WORK / name / f"{fn}.keep.cpp"
    tmp.parent.mkdir(parents=True, exist_ok=True)
    tmp.write_text(body, encoding="utf8", newline="\n")
    text = kept(name, fn, tmp, status)
    if text is None:
        sys.exit("could not place the function in the file")
    # With NON_MATCHING undefined the asm is what compiles: the object must
    # still match (the declarations must not add code or data).
    trial = WORK / name / f"{fn}.trial.cpp"
    trial.write_text(text, encoding="utf8", newline="\n")
    try:
        ok, _ = match.compare(name, trial, diff=False)
    except match.CompileError as e:
        sys.exit(f"not written: the file does not compile with it\n{e}")
    if not ok:
        sys.exit("not written: its declarations change the object")
    (ROOT / f"src/{name}.cpp").write_text(text, encoding="utf8", newline="\n")
    tmp.unlink()
    print(f"src/{name}.cpp: {fn} kept under NON_MATCHING ({status}). "
          f'Commit it: git commit -am "{name}: {fn} (NON_MATCHING)"')


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name", help="file as in config/splits.tsv, e.g. mag/maglifepc")
    ap.add_argument("function")
    ap.add_argument("--watch", action="store_true", help="check again whenever the scratch file is saved")
    ap.add_argument("--done", action="store_true", help="write the function into src/ if the object matches")
    ap.add_argument("--keep", action="store_true",
                    help="giving up: write the best version tried into src/ under #ifdef NON_MATCHING")
    a = ap.parse_args()
    name = a.name.removeprefix("src/").removesuffix(".cpp")
    path = WORK / name / f"{a.function}.cpp"
    if a.keep:
        keep(name, a.function)
        return
    if not match.server_up():
        print("compile server down (tools/match.py --server start): each check takes a minute on Windows")
    if not path.exists():
        start(name, a.function, path)
    # A log of what was tried, kept apart from the scratch files (workers clean
    # those up): tools/orca/next_batch.sh counts a tried function still in asm
    # as skipped.
    with open(WORK / ".tried", "a", encoding="utf8") as log:
        log.write(f"{name} {a.function}\n")
    good, ok = check(name, a.function, path)
    if a.done:
        if not (good and ok):
            sys.exit("not written: it does not match")
        (ROOT / f"src/{name}.cpp").write_text(assemble(name, a.function, path), encoding="utf8", newline="\n")
        path.rename(path.with_suffix(".done.cpp"))
        if (ROOT / ".git").is_file():   # a worker's worktree: the coordinator builds
            print(f'src/{name}.cpp updated. Commit it: git commit -am "{name}: {a.function}"')
        else:
            print(f"src/{name}.cpp updated. Before committing: tools/dock ninja (build/ok)")
    while a.watch:
        seen = path.stat().st_mtime
        while path.stat().st_mtime == seen:
            time.sleep(0.3)
        print(f"\n--- {time.strftime('%H:%M:%S')}")
        check(name, a.function, path)


if __name__ == "__main__":
    main()
