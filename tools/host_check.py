#!/usr/bin/env python3
"""Check that the sources are valid C++ for a PC too (as sm64 does with its
host gcc pass, and N64Recomp by testing its output with several compilers):
every file is compiled again with a modern g++ and clang++ for a 32-bit
target, syntax only, with TARGET_PC, NON_MATCHING and AVOID_UB defined.

    tools/.venv/bin/python tools/host_check.py                  # all files, against the baseline
    tools/.venv/bin/python tools/host_check.py game/gamman      # some files
    tools/.venv/bin/python tools/host_check.py --errors game/gamman   # and print their errors
    tools/.venv/bin/python tools/host_check.py --update [<file>...]   # write the baseline

It runs in the ror-host image (docker/host/: `docker build --platform
linux/amd64 -t ror-host docker/host/`). config/host_check.tsv holds the
number of errors each file had, per compiler, when it was last updated:
code written before this check has some (2.96-only C++, integers assigned
to u_long128), and they are paid down over time. A file with more errors
than its baseline for either compiler fails the check (exit 1):
tools/merge_worker.sh runs it on the files a merge touches, so new code
stays portable. 32-bit (-m32) because the ports keep the game's 32-bit
pointers (the PS Vita is 32-bit ARM).
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASELINE = ROOT / "config/host_check.tsv"
IMAGE = "ror-host"
COMMON = "-m32 -std=gnu++98 -fsyntax-only -w -fno-exceptions -DTARGET_PC -DNON_MATCHING -DAVOID_UB -I. -I../include"
COMPILERS = {"gcc": "g++", "clang": "clang++ -Wno-everything"}
sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402  (docker's path)


def all_files():
    return sorted(p.relative_to(ROOT / "src").with_suffix("").as_posix()
                  for p in (ROOT / "src").rglob("*.cpp"))


def check(files, jobs=8):
    """{file: {compiler: [error lines]}} from one container. Each compile
    writes its output and exit code to a file of its own (parallel jobs
    never interleave). A compiler that fails without an "error:" line, or a
    result that is missing, is a failure of the check itself, never a pass."""
    names = " ".join(f"{f}.cpp" for f in files)
    runs = "; ".join(f'out=$({cmd} {COMMON} "$1" 2>&1); rc=$?; '
                     f'printf "@@@ %s {tag} %s\\n%s\\n" "$1" "$rc" "$out" > "$T/$(echo "$1" | tr / _).{tag}"'
                     for tag, cmd in COMPILERS.items())
    script = (f"set -e; T=$(mktemp -d); export T; cd /work/src && printf '%s\\n' {names} "
              f"| xargs -P {jobs} -I{{}} sh -c '{runs}' _ {{}}; cat $T/*")
    r = subprocess.run([match.docker(), "run", "--rm", "--platform", "linux/amd64", "-v", f"{ROOT}:/work",
                        IMAGE, "sh", "-c", script], capture_output=True, text=True)
    if r.returncode or "@@@" not in r.stdout:
        sys.exit(f"host check could not run (is the {IMAGE} image built?), exit {r.returncode}:\n"
                 f"{r.stderr[-2000:]}")
    out = {f: {tag: [] for tag in COMPILERS} for f in files}
    rcs = {}
    cur = None
    for line in r.stdout.splitlines():
        m = re.match(r"^@@@ (\S+)\.cpp (\w+) (\d+)$", line)
        if m:
            cur = (m.group(1), m.group(2))
            rcs[cur] = int(m.group(3))
        elif cur and cur[0] in out and re.search(r"\berror:", line):
            out[cur[0]][cur[1]].append(line)
    infra = []
    for f in files:
        for tag in COMPILERS:
            if (f, tag) not in rcs:
                infra.append(f"{f} [{tag}]: no result")
            elif rcs[(f, tag)] and not out[f][tag]:
                infra.append(f"{f} [{tag}]: exit {rcs[(f, tag)]} with no error line")
    if infra:
        sys.exit("host check failed to run some compiles (not counted as passing):\n  "
                 + "\n  ".join(infra[:20]))
    return out


def load_baseline():
    """{file: {compiler: count}}; a line from before clang counts for gcc only."""
    base = {}
    if BASELINE.exists():
        for ln in BASELINE.read_text().splitlines():
            w = ln.split("\t")
            if ln and not ln.startswith("#") and len(w) >= 2:
                base[w[0]] = {"gcc": int(w[1]), "clang": int(w[2]) if len(w) > 2 else int(w[1])}
    return base


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("files", nargs="*")
    ap.add_argument("--update", action="store_true", help="write the current counts as the baseline")
    ap.add_argument("--errors", action="store_true", help="print each file's errors")
    a = ap.parse_args()
    files = [f.removeprefix("src/").removesuffix(".cpp") for f in a.files] or all_files()
    res = check(files)
    base = load_baseline()
    if a.update:
        counts = {f: {t: len(e) for t, e in r.items()} for f, r in res.items()}
        base = {**base, **counts} if a.files else counts
        BASELINE.write_text("# file\tg++ errors\tclang++ errors (tools/host_check.py --update)\n"
                            + "".join(f"{f}\t{c['gcc']}\t{c['clang']}\n" for f, c in sorted(base.items())),
                            newline="\n")
        clean = sum(1 for c in base.values() if not any(c.values()))
        print(f"baseline: {clean} of {len(base)} files clean for both compilers; "
              + ", ".join(f"{t} {sum(c[t] for c in base.values())} errors" for t in COMPILERS))
        return
    worse = []
    for f, r in res.items():
        b = base.get(f, {t: 0 for t in COMPILERS})
        marks = {t: "WORSE" if len(r[t]) > b[t] else ("better" if len(r[t]) < b[t] else "") for t in COMPILERS}
        line = f"{f}: " + ", ".join(f"{t} {len(r[t])} (baseline {b[t]}){' ' + marks[t] if marks[t] else ''}"
                                    for t in COMPILERS)
        if "WORSE" in marks.values():
            worse.append(f)
        if a.errors or "WORSE" in marks.values():
            print(line)
            for t in COMPILERS:
                for e in r[t][: 20 if a.errors else 5]:
                    print(f"    [{t}] {e}")
        elif any(marks.values()):
            print(line + f": run --update {f}")
    totals = ", ".join(f"{t} {sum(len(r[t]) for r in res.values())}" for t in COMPILERS)
    print(f"host check: {len(files)} files, errors {totals}, {len(worse)} worse than the baseline")
    sys.exit(1 if worse else 0)


if __name__ == "__main__":
    main()
