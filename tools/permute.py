#!/usr/bin/env python3
"""Search source variants of a near miss until it matches: a small
permuter for our C++ (decomp-permuter parses C only).

    tools/.venv/bin/python tools/permute.py game/gamman func_001BEDC0 --minutes 20

It starts from the function's best version so far (tools/work.py keeps it
in build/work/.best/; else its scratch file) and tries random rewrites
that change nothing a C++ reader cares about but can change what ee-gcc
emits: swapping two neighbouring simple statements, reordering the local
declarations, swapping the operands of a commutative operator or a
comparison, and inverting an if/else. Each variant is compiled with the
compile server (tools/match.py --server start) and scored by instructions
off; a variant no worse than the current one becomes the current one
(a random walk over equally good ones), and every few hundred tries
without progress it goes back to the best. A better version is saved as
the best (so work.py --keep and the next try use it); a MATCH is written
to the scratch file, ready for work.py --done.
"""
import argparse
import random
import re
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import work  # noqa: E402

SIMPLE = re.compile(r"^\s*[^\s{}#/][^{}]*;\s*$")             # one statement, no block
CONTROL = re.compile(r"^\s*(return|goto|break|continue|case|default|if|else|for|while|do|switch)\b|^\s*\w+:")
DECL = re.compile(r"^\s*(?:(?:unsigned|signed|const|volatile|register|struct)\s+)*[A-Za-z_]\w*[\s*&]+[A-Za-z_]\w*"
                  r"(?:\s*\[[^\]]*\])?\s*;\s*$")
OPERAND = r"(?:[A-Za-z_]\w*(?:(?:->|\.)\w+|\[[^\[\]]+\])*|\d+|0x[0-9A-Fa-f]+)"
COMMUTE = re.compile(rf"(?<![\w>.\]])({OPERAND}) ([+*&|^]|==|!=) ({OPERAND})(?![\w(\[])")
COMPARE = re.compile(rf"(?<![\w>.\]])({OPERAND}) (<=|>=|<|>) ({OPERAND})(?![\w(\[])")
FLIP = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}


def body_range(lines):
    """Indexes of the lines inside the function's outermost braces."""
    start = next(i for i, ln in enumerate(lines) if "{" in ln) + 1
    return start, len(lines) - 1


def swap_statements(lines, rng):
    lo, hi = body_range(lines)
    cand = [i for i in range(lo, hi - 1)
            if SIMPLE.match(lines[i]) and SIMPLE.match(lines[i + 1])
            and not CONTROL.match(lines[i]) and not CONTROL.match(lines[i + 1])
            and not DECL.match(lines[i]) and not DECL.match(lines[i + 1])]
    if not cand:
        return None
    i = rng.choice(cand)
    lines[i], lines[i + 1] = lines[i + 1], lines[i]
    return lines


def shuffle_decls(lines, rng):
    lo, hi = body_range(lines)
    idx = [i for i in range(lo, hi) if DECL.match(lines[i]) and "=" not in lines[i]]
    if len(idx) < 2:
        return None
    a, b = rng.sample(idx, 2)
    lines[a], lines[b] = lines[b], lines[a]
    return lines


def regex_edit(lines, rng, pattern, repl):
    lo, hi = body_range(lines)
    spots = [(i, m) for i in range(lo, hi) if not lines[i].lstrip().startswith("//")
             for m in pattern.finditer(lines[i])]
    if not spots:
        return None
    i, m = rng.choice(spots)
    lines[i] = lines[i][:m.start()] + repl(m) + lines[i][m.end():]
    return lines


def commute(lines, rng):
    return regex_edit(lines, rng, COMMUTE, lambda m: f"{m.group(3)} {m.group(2)} {m.group(1)}")


def flip_compare(lines, rng):
    return regex_edit(lines, rng, COMPARE, lambda m: f"{m.group(3)} {FLIP[m.group(2)]} {m.group(1)}")


def invert_if(lines, rng):
    """'if (c) {A} else {B}' -> 'if (!(c)) {B} else {A}', for one-line-headed blocks."""
    text = "\n".join(lines)
    spots = [m for m in re.finditer(r"if \(([^\n]*)\) \{\n", text)]
    rng.shuffle(spots)
    for m in spots:
        depth, i = 1, m.end()
        while i < len(text) and depth:
            depth += {"{": 1, "}": -1}.get(text[i], 0)
            i += 1
        a_end = i - 1                                    # the '}' closing A
        e = re.match(r"\s*else \{\n", text[i:])
        if not e:
            continue
        j = i + e.end()
        depth, k = 1, j
        while k < len(text) and depth:
            depth += {"{": 1, "}": -1}.get(text[k], 0)
            k += 1
        a, b = text[m.end():a_end], text[j:k - 1]
        new = f"if (!({m.group(1)})) {{\n{b}{text[a_end:i]} else {{\n{a}"
        return (text[:m.start()] + new + text[k - 1:]).split("\n")
    return None


MUTATIONS = [swap_statements, swap_statements, shuffle_decls, commute, flip_compare, invert_if]


def split(work_text):
    head, func = work_text.split(work.FUNC, 1)
    return head + work.FUNC + "\n", func.strip("\n")


def status_of(name, fn, path, slot):
    """The check's status text for one variant, or None if it does not compile."""
    trial = work.WORK / name / f"{fn}.perm{slot}.trial.cpp"
    trial.write_text(work.assemble(name, fn, path), encoding="utf8", newline="\n")
    try:
        _, report = match.compare(name, trial, diff=False)
    except match.CompileError:
        return None
    for line in report:
        g = re.match(r"^  0x[0-9A-F]+ (\S+)\s+0x[0-9a-f]+\s+(.*)$", line)
        if g and g.group(1) == fn:
            return g.group(2).strip()
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name")
    ap.add_argument("function")
    ap.add_argument("--minutes", type=float, default=15)
    ap.add_argument("--jobs", type=int, default=4, help="compiles at once")
    ap.add_argument("--seed", type=int)
    a = ap.parse_args()
    name, fn = a.name.removeprefix("src/").removesuffix(".cpp"), a.function
    if not match.server_up():
        sys.exit("start the compile server first: tools/match.py --server start")
    best_file = work.BEST / name / f"{fn}.cpp"
    scratch = work.WORK / name / f"{fn}.cpp"
    if best_file.exists():
        start = best_file.read_text(encoding="utf8").split("\n", 1)[1]
    elif scratch.exists():
        start = scratch.read_text(encoding="utf8")
    else:
        sys.exit(f"nothing to start from: run tools/work.py {name} {fn} first")
    head, func = split(start)
    rng = random.Random(a.seed)
    slots = [work.WORK / name / f"{fn}.perm{i}.cpp" for i in range(a.jobs)]

    def run(slot, lines):
        slots[slot].write_text(head + "\n".join(lines) + "\n", encoding="utf8", newline="\n")
        return status_of(name, fn, slots[slot], slot)

    base = func.split("\n")
    st = run(0, base)
    if st is None:
        sys.exit("the starting version does not compile")
    best, best_score = base, work.score(st)
    cur, cur_score = base, best_score
    print(f"start: {st}")
    tries = since = 0
    end = time.time() + a.minutes * 60
    with ThreadPoolExecutor(a.jobs) as pool:
        while time.time() < end and best_score > 0:
            batch = []
            for _ in range(a.jobs):
                lines = list(cur)
                for _ in range(rng.choice((1, 1, 1, 2, 3))):
                    lines = rng.choice(MUTATIONS)(list(lines), rng) or lines
                batch.append(lines)
            results = list(pool.map(lambda p: (p[1], run(p[0], p[1])), enumerate(batch)))
            tries += len(batch)
            since += len(batch)
            for lines, st in results:
                if st is None:
                    continue
                s = work.score(st)
                if s <= cur_score:
                    cur, cur_score = lines, s
                if s < best_score:
                    best, best_score, since = lines, s, 0
                    print(f"{tries:6} tries  {st}")
                    best_file.parent.mkdir(parents=True, exist_ok=True)
                    best_file.write_text(f"// best: {st}\n" + head + "\n".join(best) + "\n",
                                         encoding="utf8", newline="\n")
            if since >= 300:                      # stuck: back to the best
                cur, cur_score, since = best, best_score, 0
    for p in slots:
        for q in (p, p.with_name(p.stem + ".trial.cpp")):
            q.unlink(missing_ok=True)
    print(f"{tries} tries in {a.minutes:g} min; best: {best_score} off")
    if best_score == 0:
        scratch.parent.mkdir(parents=True, exist_ok=True)
        scratch.write_text(head + "\n".join(best) + "\n", encoding="utf8", newline="\n")
        print(f"MATCH, written to {scratch.relative_to(work.ROOT)}: tools/work.py {name} {fn} --done")


if __name__ == "__main__":
    main()
