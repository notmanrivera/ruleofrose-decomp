#!/usr/bin/env python3
"""Check that the sources are valid C++ for a PC too (as sm64 does with its
host gcc pass): every file is compiled again with a modern g++ for a 32-bit
target, syntax only, with TARGET_PC, NON_MATCHING and AVOID_UB defined.

    tools/.venv/bin/python tools/host_check.py                  # all files, against the baseline
    tools/.venv/bin/python tools/host_check.py game/gamman      # some files
    tools/.venv/bin/python tools/host_check.py --errors game/gamman   # and print their errors
    tools/.venv/bin/python tools/host_check.py --update         # write the baseline

It runs in the ror-host image (docker/host/: `docker build --platform
linux/amd64 -t ror-host docker/host/`). config/host_check.tsv holds the
number of errors each file had when it was last updated: code written
before this check has some (inline asm, 2.96-only C++), and they are
paid down over time. A file with more errors than its baseline fails the
check (exit 1): tools/merge_worker.sh runs it on the files a merge
touches, so new code stays portable. 32-bit (-m32) because the ports keep
the game's 32-bit pointers (the PS Vita is 32-bit ARM).
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASELINE = ROOT / "config/host_check.tsv"
IMAGE = "ror-host"
FLAGS = "-m32 -std=gnu++98 -fsyntax-only -w -fno-exceptions -DTARGET_PC -DNON_MATCHING -DAVOID_UB -I. -I../include"
sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402  (docker's path)


def all_files():
    return sorted(p.relative_to(ROOT / "src").with_suffix("").as_posix()
                  for p in (ROOT / "src").rglob("*.cpp"))


def check(files, jobs=8):
    """{file: [error lines]} from one container."""
    names = " ".join(f"{f}.cpp" for f in files)
    # One g++ per file, several at once; each file's output is framed so it
    # can be told apart.
    script = (f"cd /work/src && printf '%s\\n' {names} | xargs -P {jobs} -I{{}} sh -c "
              f"'out=$(g++ {FLAGS} {{}} 2>&1); printf \"@@@ %s\\n%s\\n\" {{}} \"$out\"'")
    r = subprocess.run([match.docker(), "run", "--rm", "--platform", "linux/amd64", "-v", f"{ROOT}:/work",
                        IMAGE, "sh", "-c", script], capture_output=True, text=True)
    if r.returncode and "@@@" not in r.stdout:
        sys.exit(f"host check could not run (is the {IMAGE} image built?):\n{r.stderr[-2000:]}")
    out, cur = {f: [] for f in files}, None
    for line in r.stdout.splitlines():
        if line.startswith("@@@ "):
            cur = line[4:].removesuffix(".cpp")
        elif cur and re.search(r"\berror:", line):
            out[cur].append(line)
    return out


def load_baseline():
    if not BASELINE.exists():
        return {}
    rows = [ln.split("\t") for ln in BASELINE.read_text().splitlines() if ln and not ln.startswith("#")]
    return {r[0]: int(r[1]) for r in rows if len(r) >= 2}


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
        if a.files:
            base.update({f: len(e) for f, e in res.items()})
        else:
            base = {f: len(e) for f, e in res.items()}
        BASELINE.write_text("# file\terrors with a modern g++ -m32 (tools/host_check.py --update)\n"
                            + "".join(f"{f}\t{n}\n" for f, n in sorted(base.items())))
        clean = sum(1 for n in base.values() if n == 0)
        print(f"baseline: {clean} of {len(base)} files clean, {sum(base.values())} errors in all")
        return
    worse = []
    for f, errs in res.items():
        b = base.get(f, 0)
        mark = "WORSE" if len(errs) > b else ("better" if len(errs) < b else "")
        if mark == "WORSE":
            worse.append(f)
        if a.errors or mark == "WORSE":
            print(f"{f}: {len(errs)} errors (baseline {b}) {mark}")
            for e in errs[: 20 if a.errors else 5]:
                print("    " + e)
        elif mark:
            print(f"{f}: {len(errs)} errors (baseline {b}) {mark}: run --update {f}")
    total = sum(len(e) for e in res.values())
    print(f"host check: {len(files)} files, {total} errors, {len(worse)} worse than the baseline")
    sys.exit(1 if worse else 0)


if __name__ == "__main__":
    main()
