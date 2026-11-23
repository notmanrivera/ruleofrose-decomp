#!/usr/bin/env python3
"""Check a change the way a merge does, in one command: every .cpp the
change touches, and every .cpp that includes (directly or through other
headers) a header it touches, must still match; host_check must not get
worse. A full build is not run (the coordinator's merge does one).

    tools/.venv/Scripts/python.exe tools/verify_change.py            # changes since pr-merge, committed or not
    tools/.venv/Scripts/python.exe tools/verify_change.py --base HEAD   # only what is not committed yet
    tools/.venv/Scripts/python.exe tools/verify_change.py src/unk/Eff0.h src/unk/EffFire1.cpp

Prints one line per file and a last line "OK: N files match, host check
not worse" or "FAILED: ...", and exits 0 or 1.
"""
import argparse
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

os.environ.setdefault("ROR_QUIET_HI16", "1")
ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "src"
sys.path.insert(0, str(ROOT / "tools"))


def git(*args):
    r = subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True)
    return r.stdout.splitlines() if r.returncode == 0 else []


def changed(base):
    """src/ paths changed on this branch since it left base (committed or
    not: base...HEAD, so what base gained meanwhile does not count) and
    untracked ones."""
    out = set(git("diff", "--name-only", f"{base}...HEAD", "--", "src")) if base != "HEAD" else set()
    out |= set(git("diff", "--name-only", "--", "src"))
    out |= set(git("ls-files", "--others", "--exclude-standard", "--", "src"))
    return {p for p in out if p.endswith((".cpp", ".h")) and (ROOT / p).exists()}


def include_graph():
    """{header path: set of files (src/... paths) that include it directly}."""
    inc = {}
    for p in list(SRC.rglob("*.cpp")) + list(SRC.rglob("*.h")):
        rel = p.relative_to(ROOT).as_posix()
        for name in re.findall(r'^\s*#\s*include\s+"([^"]+)"', p.read_text(encoding="utf8", errors="replace"), re.M):
            for cand in (SRC / name, p.parent / name):
                if cand.exists():
                    inc.setdefault(cand.resolve().relative_to(ROOT.resolve()).as_posix(), set()).add(rel)
                    break
    return inc


def includers(headers, graph):
    """Every .cpp that includes one of the headers, through any chain."""
    seen, todo, cpps = set(), list(headers), set()
    while todo:
        h = todo.pop()
        for f in graph.get(h, ()):
            if f in seen:
                continue
            seen.add(f)
            (cpps.add(f) if f.endswith(".cpp") else todo.append(f))
    return cpps


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("paths", nargs="*", help="files to check as changed (default: from git)")
    ap.add_argument("--base", default="pr-merge", help="compare with this commit (default pr-merge)")
    ap.add_argument("--jobs", type=int, default=4)
    a = ap.parse_args()
    import match
    import host_check
    paths = {Path(p).as_posix() for p in a.paths} if a.paths else changed(a.base)
    paths = {p if p.startswith("src/") else "src/" + p for p in paths}
    if not paths:
        print("OK: nothing changed under src/")
        return
    graph = include_graph()
    cpps = {p for p in paths if p.endswith(".cpp")} | includers({p for p in paths if p.endswith(".h")}, graph)
    names = sorted(p[4:-4] for p in cpps)
    print(f"{len(paths)} changed: {', '.join(sorted(paths))}")
    print(f"{len(names)} files to check" + (f" ({len(names) - len([p for p in paths if p.endswith('.cpp')])} through headers)"
                                            if any(p.endswith('.h') for p in paths) else ""))
    if not match.server_up():
        match.server("start")

    def one(name, sync=False):
        # the server's copy of headers and asm is brought up to date once,
        # by the first compile alone: several syncing at once race
        try:
            ok, rep = match.compare(name, sync=sync)
            return name, ok, rep[-1] if rep else "", [l for l in rep if "differ" in l or "size" in l][:4]
        except match.CompileError as e:
            err = next((l for l in str(e).splitlines() if re.search(r":\d+: (?!warning)", l)), str(e)[-200:])
            return name, False, "does not compile: " + err.strip()[:200], []

    bad = []
    first = one(names[0], sync=True)
    with ThreadPoolExecutor(a.jobs) as pool:
        for name, ok, last, why in [first] + list(pool.map(one, names[1:])):
            print(f"  {'ok ' if ok else 'BAD'} {name}: {last}")
            if not ok:
                bad.append(name)
                for w in why:
                    print(f"        {w.strip()}")
    worse = []
    try:
        res = host_check.check(names)
        base = host_check.load_baseline()
        for f, r in res.items():
            b = base.get(f, {t: 0 for t in host_check.COMPILERS})
            if any(len(r[t]) > b[t] for t in host_check.COMPILERS):
                worse.append(f)
                print(f"  WORSE host check {f}: " + "; ".join(r[t][0] for t in host_check.COMPILERS if r[t])[:200])
    except SystemExit as e:
        print(f"  host check could not run: {e}")
        worse.append("(host check)")
    if bad or worse:
        print(f"FAILED: {len(bad)} not matching ({', '.join(bad)})" + (f"; host check worse: {', '.join(worse)}" if worse else ""))
        sys.exit(1)
    print(f"OK: {len(names)} files match, host check not worse (the coordinator runs the full build at merge)")


if __name__ == "__main__":
    main()
