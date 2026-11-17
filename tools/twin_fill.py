#!/usr/bin/env python3
"""Fill pending twins mechanically: a twin (tools/twins.py) has the same
instructions as a function already in C++, so its C++ with the other
function's names, offsets and constants often matches as it is.

    (in a worker's worktree, not the main checkout)
    tools/.venv/Scripts/python.exe tools/twin_fill.py            # every pending twin
    tools/.venv/Scripts/python.exe tools/twin_fill.py --list     # only show the plan
    tools/.venv/Scripts/python.exe tools/twin_fill.py --file unk/BdlMain

For each pending function with a twin: the two functions' asm
(asm/nonmatchings/<file>/<fn>.s) are compared instruction by instruction;
each operand that differs (an immediate, a symbol, a call target) gives a
substitution twin -> this one, and a token that would map to two values
stops it. The twin's C++ (twins.source_of) with the function's own name and
those substitutions goes into the scratch file (tools/work.py), which is
checked. Only a MATCH is kept: work.py --done and a commit
"<file>: <fn> (twin)", for tools/merge_worker.sh to verify again. Nothing
else is written to src/.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import twins  # noqa: E402
import work  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
INSN = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$")
TOKEN = re.compile(r"-?0x[0-9A-Fa-f]+|-?\d+|[A-Za-z_][\w.$]*")


def asm_lines(name, fn):
    path = ROOT / "asm/nonmatchings" / name / f"{fn}.s"
    if not path.exists():
        return None
    out = []
    for line in path.read_text(errors="replace").splitlines():
        m = INSN.match(line)
        if m:
            ops = re.sub(r"\$\w+", "", m.group(2))          # registers are the same in twins
            ops = re.sub(r"\.L[0-9A-F_]+|\.\s*\+.*", "", ops)    # local branch targets
            out.append((m.group(1), TOKEN.findall(ops)))
    return out


def number(tok):
    try:
        return int(tok, 0)
    except ValueError:
        return None


def mapping(theirs, ours):
    """{twin token: our token} from two instruction lists, or None on a clash."""
    if theirs is None or ours is None or len(theirs) != len(ours):
        return None
    out = {}
    for (m1, t1), (m2, t2) in zip(theirs, ours):
        if m1 != m2 or len(t1) != len(t2):
            return None
        for a, b in zip(t1, t2):
            if a in ("%hi", "%lo", "hi", "lo") or a == b:
                continue
            if out.get(a, b) != b:
                return None
            out[a] = b
    return out


def apply(body, subst):
    """The C++ with each substitution made: symbols by name, numbers by value
    (an immediate shows in C as hex or decimal)."""
    syms = {a: b for a, b in subst.items() if number(a) is None}
    nums = {number(a): number(b) for a, b in subst.items() if number(a) is not None and number(b) is not None}
    for a, b in syms.items():
        body = re.sub(rf"\b{re.escape(a)}\b", b, body)

    def num(m):
        v = int(m.group(0), 0)
        if v in nums:
            n = nums[v]
            return hex(n) if m.group(0).lower().startswith("0x") else str(n)
        return m.group(0)
    return re.sub(r"(?<![\w.])(?:0x[0-9A-Fa-f]+|\d+)(?![\w.])", num, body)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--file", help="only this file's pending twins")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()
    py = sys.executable
    matched, pending = idx = twins.index()
    jobs = []
    for (name, fn), shape in sorted(pending.items()):
        if a.file and name != a.file:
            continue
        tw = twins.twin_of(name, fn, idx)
        if tw:
            jobs.append((name, fn, tw))
    done = 0
    for name, fn, (tname, tfn) in jobs:
        body = twins.source_of(tname, tfn)
        subst = mapping(asm_lines(tname, tfn), asm_lines(name, fn))
        if body is None or subst is None:
            print(f"{name} {fn}: no plan ({'no C++ for the twin' if body is None else 'operands clash'})")
            continue
        # The rename: an extern "C" func_XXXXXXXX twin carries its label as
        # its C name; a method (Class::f) or an alias keeps its C name, and
        # only a label in asm("...") is renamed (the match then tells).
        subst.setdefault(tfn, fn)
        if a.list:
            print(f"{name} {fn} <- {tname} {tfn}: {len(subst)} substitutions")
            continue
        scratch = work.WORK / name / f"{fn}.cpp"
        r = subprocess.run([py, "tools/work.py", name, fn], cwd=ROOT, capture_output=True, text=True)
        if not scratch.exists():
            print(f"{name} {fn}: work.py could not start it")
            continue
        head = scratch.read_text(encoding="utf8").split(work.FUNC, 1)[0]
        scratch.write_text(head + work.FUNC + "\n" + apply(body, subst) + "\n", encoding="utf8", newline="\n")
        r = subprocess.run([py, "tools/work.py", name, fn], cwd=ROOT, capture_output=True, text=True)
        st = re.search(rf"^  0x[0-9A-F]+ {re.escape(fn)}\s+0x[0-9a-f]+\s+(.*)$", r.stdout, re.M)
        status = st.group(1).strip() if st else "does not compile"
        if status != "MATCH":
            print(f"{name} {fn} <- {tname} {tfn}: {status}")
            continue
        d = subprocess.run([py, "tools/work.py", name, fn, "--done"], cwd=ROOT, capture_output=True, text=True)
        if d.returncode != 0:
            print(f"{name} {fn}: MATCH, but work.py --done refused it:\n{d.stdout}{d.stderr}")
            continue
        subprocess.run(["git", "commit", "-q", "-m", f"{name}: {fn} (twin)", "--", f"src/{name}.cpp"], cwd=ROOT)
        done += 1
        print(f"{name} {fn} <- {tname} {tfn}: MATCH, committed")
    if not a.list:
        print(f"{done} of {len(jobs)} twins matched")


if __name__ == "__main__":
    main()
