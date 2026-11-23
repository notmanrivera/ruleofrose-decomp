#!/usr/bin/env python3
"""Pilot: run cpp_permuter (CriminalRETeam, C++ aware, MIT) on one
NON_MATCHING attempt with ee-gcc 2.96, inside the ror-build container.

    tools/.venv/Scripts/python.exe tools/cpp_perm.py unk/SctLayer func_0017B918 --minutes 20
    ... --check-parse          only check that cpp_permuter parses the attempt

Needs build/cpp_permuter/cpp_permuter.bin (a static Linux build, see
notes/research/cpp-permuter-pilot.md). The attempt is spliced in place of
its INCLUDE_ASM in a copy of src/ under the container's /tmp; the target
object is the same file compiled as is (the function's INCLUDE_ASM: the
game's bytes); tools/cpp_perm_score.py scores. Results are copied to
build/cpp_perm/<function>/ (permuter_out/output-<score>-<n>/). A score of 0
is a lead, not a match: apply it and check with match.py.
"""
import argparse
import re
import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import configure  # noqa: E402
import regalloc_triage  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name")
    ap.add_argument("function")
    ap.add_argument("--minutes", type=float, default=20)
    ap.add_argument("--jobs", type=int, default=6)
    ap.add_argument("--check-parse", action="store_true")
    ap.add_argument("--extra", default="", help="more cpp_permuter options")
    a = ap.parse_args()
    text = (ROOT / "src" / f"{a.name}.cpp").read_text(encoding="utf8")
    m = next((m for m in regalloc_triage.NM.finditer(text) if m.group(2) == a.function), None)
    if not m:
        sys.exit(f"{a.name}: no NON_MATCHING attempt of {a.function}")
    # the name cpp_permuter must find: Class::method or the free function's
    # name. The block may start with helper structs and declarations: take
    # the head of the last top-level definition (a line ending in ')' or
    # 'const', followed by '{' at column 0)
    blk = m.group(1)
    strip = lambda h: re.sub(r"\b(?:asm|__asm__|__attribute__|throw)\s*\((?:[^()]|\([^()]*\))*\)", "", h)
    names = []
    for d in re.finditer(r"^([^\s#/}][^\n;{}]*\)[^\n;{}]*?)\s*\n?\{", blk, re.M):
        f = re.findall(r"([A-Za-z_~][\w:~]*)\s*\(", strip(d.group(1)))
        if f and f[0] not in ("if", "while", "for", "switch", "return", "sizeof"):
            names.append(f[0])
    short = a.function.split("__")[0] if "__" in a.function and not a.function.startswith("func_") else a.function
    fname = next((n for n in reversed(names) if short in n), names[-1] if names else None)
    if not fname:
        sys.exit(f"{a.name} {a.function}: could not find the function's name in its attempt")
    out = ROOT / "build" / "cpp_perm" / a.function
    out.mkdir(parents=True, exist_ok=True)
    pilot = out / "attempt.cpp"
    pilot.write_text(text[:m.start()] + m.group(1) + text[m.end():], encoding="utf8", newline="\n")
    flags = configure.CFLAGS
    rel = f"{a.name}.cpp"
    # no cd: {obj} is relative to cpp_permuter's directory
    absflags = flags.replace("-I. ", "-I/tmp/cp/src ").replace("-I../include", "-I/tmp/cp/include").replace("-Wa,-I..", "-Wa,-I/tmp/cp")
    compile_cmd = f"ee-cc {configure.COMPILER} {absflags} -I{{dir}} -c {{src}} -o {{obj}}"
    score_cmd = f"python3 /work/tools/cpp_perm_score.py {{obj}} /tmp/cp/target.o {a.function}"
    perm = ["/work/build/cpp_permuter/cpp_permuter.bin", "-s", f"/tmp/cp/src/{rel}", "-f", fname,
            "-c", compile_cmd, "--score-cmd", score_cmd, "-j", str(a.jobs), "--keep-ties",
            *shlex.split(a.extra)]
    if a.check_parse:
        perm = ["/work/build/cpp_permuter/cpp_permuter.bin", "--check-parse", f"/tmp/cp/src/{rel}"]
    dest = f"/work/build/cpp_perm/{a.function}"
    script = f"""set -e
rm -rf /tmp/cp && mkdir -p /tmp/cp/asm/nonmatchings /tmp/cp/out
cp -r /work/src /work/include /tmp/cp/
mkdir -p /tmp/cp/asm/nonmatchings/{Path(a.name).parent.as_posix()}
cp -r /work/asm/nonmatchings/{a.name} /tmp/cp/asm/nonmatchings/{Path(a.name).parent.as_posix()}/
[ -d /work/asm/data ] && cp -r /work/asm/data /tmp/cp/asm/ || true
cd /tmp/cp/src && ee-cc {configure.COMPILER} {flags} -c {rel} -o /tmp/cp/target.o
cp {dest}/attempt.cpp /tmp/cp/src/{rel}
cd /tmp/cp/src && ee-cc {configure.COMPILER} {flags} -c {rel} -o /tmp/cp/base.o
echo "base: $(python3 /work/tools/cpp_perm_score.py /tmp/cp/base.o /tmp/cp/target.o {a.function})"
cd /tmp/cp/out
rc=0; timeout {int(a.minutes * 60)} {' '.join(shlex.quote(x) for x in perm)} || rc=$?
echo "cpp_permuter exit $rc"
rm -rf {dest}/permuter_out; [ -d permuter_out ] && cp -r permuter_out {dest}/ || true
"""
    (out / "run.sh").write_text(script, encoding="utf8", newline="\n")
    r = subprocess.run(["sh", str(ROOT / "tools/dock"), "sh", f"/work/build/cpp_perm/{a.function}/run.sh"], cwd=ROOT)
    sys.exit(r.returncode)


if __name__ == "__main__":
    main()
