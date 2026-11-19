#!/usr/bin/env python3
"""Per-file compiler flag sweep (research item R19).

Other ee-gcc 2.96 decomps (sotc config/ee_cflags.json, gt4 build markers)
build a few files with flags that differ from the project default. This
compiles every file that has NON_MATCHING attempts with -DNON_MATCHING plus
one extra flag at a time, through tools/match.py --extra, and compares each
function with the same build without the flag:

    tools/.venv/Scripts/python.exe tools/flag_sweep.py               # all files, all flags
    tools/.venv/Scripts/python.exe tools/flag_sweep.py unk/MnuPBook  # one file
    tools/.venv/Scripts/python.exe tools/flag_sweep.py --flags -fno-gcse,-fno-rerun-loop-opt

A flag is a lead for a file when some attempt becomes MATCH (or loses
edits) and no function that matched without it stops matching. Results go
to build/flag_sweep.tsv (file, flag, gained, broken, edits before/after)
and the summary to stdout; progress in build/workers/flag-sweep.log.
Nothing in src/ or config/ is changed.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LOG = ROOT / "build/workers/flag-sweep.log"
OUT = ROOT / "build/flag_sweep.tsv"
FLAGS = [
    "-fno-gcse", "-fno-rerun-loop-opt", "-fno-sched-interblock", "-fno-sched-spec",
    "-fno-schedule-insns", "-fno-cse-follow-jumps", "-fno-cse-skip-blocks",
    "-fno-expensive-optimizations", "-fno-strength-reduce", "-fno-peephole",
    "-fno-regmove", "-fno-thread-jumps", "-fno-caller-saves", "-fno-defer-pop",
    "-fno-force-mem", "-fno-builtin", "-fno-rerun-cse-after-loop",
]
LINE = re.compile(r"^\s+0x([0-9A-Fa-f]{8}) (\S+)\s+0x[0-9a-f]+\s+(.*)$")


def run(name, extra):
    p = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), name, f"--extra={extra}"],
                       cwd=ROOT, capture_output=True, text=True)
    funcs = {}
    for ln in p.stdout.splitlines():
        m = LINE.match(ln)
        if not m:
            continue
        st = m.group(3).strip()
        if st == "asm":
            continue
        e = re.search(r"(\d+) edits", st)
        funcs[m.group(2)] = 0 if st == "MATCH" else int(e.group(1)) if e else 999
    return funcs, (p.stdout + p.stderr)[-300:]


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("names", nargs="*")
    ap.add_argument("--flags", help="comma-separated list instead of the default set")
    a = ap.parse_args()
    flags = a.flags.split(",") if a.flags else FLAGS
    names = a.names or sorted(
        str(p.relative_to(ROOT / "src").with_suffix("")).replace("\\", "/")
        for p in (ROOT / "src").rglob("*.cpp") if "#ifdef NON_MATCHING" in p.read_text(errors="replace"))
    LOG.parent.mkdir(parents=True, exist_ok=True)
    rows = []
    with open(LOG, "w") as log:
        log.write(f"flag sweep: {len(names)} files x {len(flags)} flags\n")
        for k, name in enumerate(names, 1):
            base, tail = run(name, "-DNON_MATCHING")
            if not base:
                log.write(f"[{k}/{len(names)}] {name}: baseline failed: {tail!r}\n"); log.flush()
                continue
            for f in flags:
                got, tail = run(name, f"-DNON_MATCHING {f}")
                if not got:
                    rows.append((name, f, "", "", "", "", "compile failed: " + tail.strip().splitlines()[-1][:120]))
                    continue
                gained = [fn for fn, v in got.items() if v == 0 and base.get(fn, 1) != 0]
                broken = [fn for fn, v in got.items() if v != 0 and base.get(fn) == 0]
                eb = sum(v for fn, v in base.items() if v)
                eg = sum(v for fn, v in got.items() if v)
                rows.append((name, f, ",".join(gained), ",".join(broken), str(eb), str(eg), ""))
            log.write(f"[{k}/{len(names)}] {name}: done\n"); log.flush()
    OUT.write_text("file\tflag\tgained\tbroken\tedits_before\tedits_after\tnote\n"
                   + "".join("\t".join(r) + "\n" for r in rows))
    print("leads (gained, nothing broken):")
    for r in rows:
        if r[2] and not r[3]:
            print(f"  {r[0]} {r[1]}: +{r[2]} (edits {r[4]} -> {r[5]})")
    print("gained but breaks others:")
    for r in rows:
        if r[2] and r[3]:
            print(f"  {r[0]} {r[1]}: +{r[2]} / -{r[3]}")
    bad = sorted({r[1] for r in rows if r[6]})
    if bad:
        print("flags the compiler refused somewhere:", " ".join(bad))


if __name__ == "__main__":
    main()
