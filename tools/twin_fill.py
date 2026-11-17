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
import itertools
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import twins  # noqa: E402
import work  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
INSN = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$")
MAX_CHOICES = 6                     # ambiguous literals tried in every combination
TOKEN = re.compile(r"-?0x[0-9A-Fa-f]+|-?\d+|[A-Za-z_][\w.$]*")


def asm_text(name, fn):
    """The function's asm: its own piece, or (a matched function of a file
    with no pieces left) its part of the whole-file asm/<name>.s."""
    path = ROOT / "asm/nonmatchings" / name / f"{fn}.s"
    if path.exists():
        return path.read_text(errors="replace")
    whole = ROOT / "asm" / f"{name}.s"
    if not whole.exists():
        return None
    out, on = [], False
    for line in whole.read_text(errors="replace").splitlines():
        m = twins.FUNC.match(line)
        if m:
            on = m.group(1) == fn
        elif on and re.match(r"^\s*(?:end|\.size)\b|^\s*enddlabel|^\s*endlabel", line):
            on = False
        if on:
            out.append(line)
    return "\n".join(out) if out else None


def asm_lines(name, fn):
    text = asm_text(name, fn)
    if text is None:
        return None
    out = []
    for line in text.splitlines():
        m = INSN.match(line)
        if m:
            # registers are the same in twins ($2, $f0); not the $ inside
            # a symbol such as _vt$7BdlMain
            ops = re.sub(r"(?<![\w$])\$\w+", "", m.group(2))
            ops = re.sub(r"\.L[0-9A-F_]+|\.\s*\+.*", "", ops)    # local branch targets
            out.append((m.group(1), TOKEN.findall(ops)))
    return out


def number(tok):
    try:
        return int(tok, 0)
    except ValueError:
        return None


def mapping(theirs, ours):
    """({twin token: our token}, {number: other number}) from two instruction
    lists, or None on a clash. A number that stays itself in one instruction
    and changes in another (DwfMain: 7 is a call argument and, elsewhere, 1)
    is ambiguous: which of its C literals change is tried (main())."""
    if theirs is None or ours is None or len(theirs) != len(ours):
        return None
    out, same, amb = {}, set(), {}
    for (m1, t1), (m2, t2) in zip(theirs, ours):
        if m1 != m2 or len(t1) != len(t2):
            return None
        for a, b in zip(t1, t2):
            if a in ("%hi", "%lo", "hi", "lo"):
                continue
            if a == b:
                same.add(a)
                continue
            if out.get(a, b) != b:
                return None
            out[a] = b
    for a in [a for a in out if a in same]:
        if number(a) is None:
            return None                       # a symbol both kept and renamed
        amb[a] = out.pop(a)
    return out, amb


def apply(body, subst):
    """The C++ with each substitution made: symbols by name, numbers by value
    (an immediate shows in C as hex or decimal)."""
    syms = {a: b for a, b in subst.items() if number(a) is None}
    nums = {number(a): number(b) for a, b in subst.items() if number(a) is not None and number(b) is not None}
    for a, b in syms.items():
        # also inside an alias of it: Xiii_func_00166DA4 (declared with
        # asm("func_00166DA4") in this project's style) -> Xiii_func_0014BE48
        body = re.sub(rf"(?<![\w$])((?:X\w*?_)?){re.escape(a)}(?![\w$])", lambda m: m.group(1) + b, body)

    def num(m):
        v = int(m.group(0), 0)
        if v in nums:
            n = nums[v]
            return hex(n) if m.group(0).lower().startswith("0x") else str(n)
        return m.group(0)
    return re.sub(r"(?<![\w.])(?:0x[0-9A-Fa-f]+|\d+)(?![\w.])", num, body)


IDENT = re.compile(r"[A-Za-z_][\w$]*")


def declarations(body, twin_file, target_file, subst):
    """The one-line 'extern ...;' declarations of the twin's file that the
    body needs and the target file lacks, substitutions applied (so the
    function's own asm("label") alias and its vtable get this function's
    names)."""
    twin_text = (ROOT / "src" / f"{twin_file}.cpp").read_text(errors="replace")
    # A name only inside an asm("label") or a string is not declared there.
    target_text = re.sub(r'asm\("[^"]*"\)|"[^"]*"', "",
                         (ROOT / "src" / f"{target_file}.cpp").read_text(errors="replace"))
    need = set(IDENT.findall(body))
    out = []
    for line in twin_text.splitlines():
        s = line.strip()
        if not s.startswith("extern") or not s.endswith(";") or "{" in s:
            continue
        new = apply(s, subst)                 # compared with the body, which is substituted too
        names = set(IDENT.findall(re.sub(r'asm\("[^"]*"\)|"[^"]*"', "", new)))
        hit = [n for n in names & need if n not in ("extern", "int", "void", "char", "short", "unsigned", "C")]
        if not hit:
            continue
        declared = [n for n in IDENT.findall(re.sub(r'asm\("[^"]*"\)|"[^"]*"', "", new)) if n in need]
        if all(re.search(rf"(?<![\w$]){re.escape(n)}(?![\w$])", target_text) for n in declared):
            continue                          # the target file has them already
        if new not in out:
            out.append(new)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--file", help="only this file's pending twins")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()
    py = sys.executable
    # this worktree's compile server: without it work.py compiles on the
    # Windows mount, where the old compiler dies ("init_c_lex") and every
    # twin looks like "does not compile" (after a reboot, before resume.sh)
    if not a.list:
        subprocess.run([py, "tools/match.py", "--server", "start"], cwd=ROOT, capture_output=True)
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
        plan = mapping(asm_lines(tname, tfn), asm_lines(name, fn))
        subst, amb = plan if plan else (None, {})
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
        base = apply(body, subst)
        decls = declarations(base, tname, name, subst)
        # Ambiguous numbers: every choice of which of their C literals
        # change (up to MAX_CHOICES positions, 2^n checks).
        spots = [(m.start(), m.end(), amb_n)
                 for a_tok, b_tok in amb.items()
                 for amb_n in [(number(a_tok), number(b_tok))]
                 for m in re.finditer(r"(?<![\w.])(?:0x[0-9A-Fa-f]+|\d+)(?![\w.])", base)
                 if int(m.group(0), 0) == amb_n[0]]
        if len(spots) > MAX_CHOICES:
            print(f"{name} {fn} <- {tname} {tfn}: {len(spots)} ambiguous literals; too many to try")
            continue
        status = "does not compile"
        for pick in itertools.product((False, True), repeat=len(spots)):
            text = base
            for (s0, e0, (_, nb)), on in sorted(zip(spots, pick), reverse=True):
                if on:
                    lit = text[s0:e0]
                    text = text[:s0] + (hex(nb) if lit.lower().startswith("0x") else str(nb)) + text[e0:]
            scratch.write_text(head.rstrip("\n") + "\n" + "".join(d + "\n" for d in decls) + "\n"
                               + work.FUNC + "\n" + text + "\n", encoding="utf8", newline="\n")
            r = subprocess.run([py, "tools/work.py", name, fn], cwd=ROOT, capture_output=True, text=True)
            st = re.search(rf"^  0x[0-9A-F]+ {re.escape(fn)}\s+0x[0-9a-f]+\s+(.*)$", r.stdout, re.M)
            status = st.group(1).strip() if st else "does not compile"
            if status == "MATCH":
                break
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
