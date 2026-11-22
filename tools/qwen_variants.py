#!/usr/bin/env python3
"""Let a local model (Ollama) propose rewrites of a NON_MATCHING attempt and
keep the ones the compiler scores better: a free variant generator, judged
only by tools/match.py.

    tools/.venv/bin/python tools/qwen_variants.py unk/0020ED9C func_00213C6C
    tools/.venv/bin/python tools/qwen_variants.py --queue build/qwen/queue.tsv   # "<file>\t<func>" lines

Each round shows the model the function's current best C code with line
numbers and the differing instructions (game | ours); it answers with a few
variants, each a list of operations by line number (swap two lines, move a
line before another, replace one line). Each variant is applied to a copy
of src/<file>.cpp (src/ is never written), compiled with -DNON_MATCHING and
scored by the function's edit count (plus differing relocations). The best
one so far is the next round's start. The body keeps its line count (blank
lines are added or taken at its end), so later code keeps its __LINE__.

Nothing is committed: the best version goes to build/qwen/<file>/<func>.cpp
and a MATCH is reported for the coordinator to verify (tools/work.py).
Log for the progress bar: build/workers/qwen.log; per-variant results for
judging the model: build/qwen/results.tsv; raw answers: build/qwen/raw/.
"""
import argparse
import json
import os
import re
import sys
import time
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402
import work  # noqa: E402

OUT = ROOT / "build/qwen"
LOG = ROOT / "build/workers/qwen.log"
URL = "http://localhost:11434/api/generate"
NL = "\n"

PROMPT = """You help match a decompilation: C++ compiled by GCC 2.96 for the PS2 (MIPS) at -Os must give exactly the game's instructions.
Our C++ function below (lines numbered) computes the right thing but compiles to slightly different instructions. Lines marked * differ (game | ours).

Our C++ code (line number: code):
{code}

Differing instructions (game | ours):
{diff}

Propose {n} different small changes to the C++ CODE (never to the assembly) that keep the exact meaning but could change GCC's instruction order or registers:
{ops}
{avoid}
Answer only JSON: {{"variants": [{{"why": "short reason", "ops": [ ... ]}}]}}"""


OPS = {
    "all": """swap two independent statements, move a statement or declaration earlier or later, rewrite one line (add or remove a temporary, flip a comparison, swap operands, split a chained assignment).
Use only these operations, by line number of the code above:
  {"op": "swap", "a": 5, "b": 6}
  {"op": "move", "line": 7, "before": 3}
  {"op": "replace", "line": 4, "text": "    int t = p->x;"}""",
    # Reordering is what tools/permute.py does exhaustively without a model;
    # the model's own value is rewriting an expression.
    "replace": """rewrite one or two lines: use the pointer variable or write the address out again, add or remove a cast,
use the other variable holding the same value, flip a comparison (a < b -> b > a), swap the operands of + * == & |, write x = x + 1 as x += 1 or ++x,
split a chained assignment, index an array instead of pointer arithmetic or the other way round. Every variable you use must already be declared above that line.
Use only this operation, by line number of the code above (one or two per variant):
  {"op": "replace", "line": 4, "text": "    int t = p->x;"}""",
}


def log(msg):
    LOG.parent.mkdir(parents=True, exist_ok=True)
    with open(LOG, "a", encoding="utf-8") as f:
        f.write(f"{time.strftime('%H:%M:%S')} {msg}{NL}")
    print(msg, flush=True)


def ask(model, prompt, temperature):
    body = json.dumps({"model": model, "prompt": prompt, "format": "json", "stream": False,
                       "options": {"temperature": temperature, "num_ctx": 8192}}).encode()
    req = urllib.request.Request(URL, body, {"Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=600) as r:
        return json.loads(r.read())["response"]


def score(name, func, text):
    """(edits or None if it does not compile, status text, diff lines) of the
    function, the file compiled with NON_MATCHING from this text."""
    src = OUT / "tmp" / f"qv{os.getpid()}_{time.time_ns()}.cpp"
    src.parent.mkdir(parents=True, exist_ok=True)
    src.write_text(text, newline=NL)
    try:
        _, report = match.compare(name, source=str(src), extra="-DNON_MATCHING", diff=True)
    except match.CompileError as e:
        return None, "compile error: " + str(e)[-200:].replace(NL, " "), []
    finally:
        src.unlink(missing_ok=True)
        (ROOT / "build/match" / f"{name}.{src.stem}.o").unlink(missing_ok=True)
    status, diff, inside = None, [], False
    for line in report:
        if line.startswith("  0x"):
            inside = line.split()[1] == func
            if inside:
                status = line.split(None, 3)[3]
            continue
        if inside and line.startswith("    "):
            diff.append(line[4:])
    if status is None:
        return None, f"{func} not in the report", []
    if status.startswith("MATCH"):
        return 0, status, []
    m = re.search(r"(\d+) edits", status)
    relocs = re.search(r"(\d+) relocs? differ", status)
    return (int(m.group(1)) if m else 999) + (int(relocs.group(1)) if relocs else 0), status, diff


def numbered(body):
    return NL.join(f"{i}: {l}" for i, l in enumerate(body.split(NL), 1) if l.strip())


def apply(body, ops):
    """(the body after the model's operations, by line numbers of the body
    it was shown; or None, why not)."""
    lines = body.split(NL)
    n = len(lines)
    order = list(range(n))          # position -> original line index
    text = {}
    if not isinstance(ops, list) or not ops:
        return None, "no ops"
    try:
        for o in ops:
            op = o.get("op")
            if op == "swap":
                a, b = int(o["a"]) - 1, int(o["b"]) - 1
                if not (0 <= a < n and 0 <= b < n) or a == b:
                    return None, "bad line"
                ia, ib = order.index(a), order.index(b)
                order[ia], order[ib] = order[ib], order[ia]
            elif op == "move":
                a, b = int(o["line"]) - 1, int(o["before"]) - 1
                if not (0 <= a < n and 0 <= b < n) or a == b:
                    return None, "bad line"
                order.remove(a)
                order.insert(order.index(b), a)
            elif op == "replace":
                a = int(o["line"]) - 1
                t = str(o["text"])
                if not 0 <= a < n or NL in t.strip():
                    return None, "bad replace"
                text[a] = t.rstrip()
            else:
                return None, f"unknown op {op!r}"
    except (KeyError, ValueError, TypeError, AttributeError):
        return None, "malformed op"
    out = [text.get(i, lines[i]) for i in order]
    if out == lines:
        return None, "no change"
    return NL.join(out), None


def short_diff(diff, limit=60):
    """The differing lines and one line of context around each."""
    keep = set()
    for i, l in enumerate(diff):
        if l.startswith("*"):
            keep.update((i - 1, i, i + 1))
    rows = [diff[i] for i in sorted(keep) if 0 <= i < len(diff)]
    return NL.join(rows[:limit]) + (NL + "..." if len(rows) > limit else "")


def run(name, func, model, rounds, n, tag, results, mode="all", resume=False):
    text = (ROOT / "src" / f"{name}.cpp").read_text()
    m = work.nm_block(text, name, func)
    if not m:
        log(f"{tag} {name} {func}: no NON_MATCHING attempt, skipped")
        return None
    head, body, tail = text[:m.start(1)], m.group(1), text[m.end(1):]
    base, status, diff = score(name, func, text)
    if base is None:
        log(f"{tag} {name} {func}: the attempt does not compile ({status}), skipped")
        return None
    log(f"{tag} {name} {func}: start, base {base} ({status})")
    best, best_body, best_diff = base, body, diff
    saved = OUT / name / f"{func}.cpp"
    if resume and saved.exists():
        sb = saved.read_text()
        sc, st, df = score(name, func, head + sb + tail)
        if sc is not None and sc < best and sb.count(NL) == body.count(NL):
            best, best_body, best_diff = sc, sb, df
            log(f"{tag} {name} {func}: resumed from the saved best, {sc} ({st})")
    tried, errors = [], []
    for r in range(1, rounds + 1):
        if best == 0:
            break
        avoid = ("Already tried without success: " + "; ".join(tried[-8:])) if tried else ""
        if errors:
            avoid += (NL if avoid else "") + "These did not compile, do not repeat them: " + "; ".join(errors[-3:])
        prompt = PROMPT.format(code=numbered(best_body), diff=short_diff(best_diff), n=n, avoid=avoid,
                               ops=OPS[mode])
        t0 = time.time()
        try:
            answer = ask(model, prompt, 0.7 + 0.05 * r)
            raw = OUT / "raw" / name / f"{func}.r{r}.json"
            raw.parent.mkdir(parents=True, exist_ok=True)
            raw.write_text(answer, encoding="utf-8")
            variants = json.loads(answer).get("variants", [])
        except Exception as e:  # noqa: BLE001  (a bad answer is one more data point)
            log(f"{tag} {name} {func}: round {r}/{rounds}: no usable answer ({type(e).__name__})")
            results.append((name, func, r, "", "bad_json", "", best))
            continue
        secs = time.time() - t0
        variants = variants if isinstance(variants, list) else []
        for var in variants:
            why = str(var.get("why", ""))[:80] if isinstance(var, dict) else ""
            ops = var.get("ops", []) if isinstance(var, dict) else []
            if mode == "replace" and isinstance(ops, list):
                ops = [o for o in ops if isinstance(o, dict) and o.get("op") == "replace"]
            nb, err = apply(best_body, ops)
            if nb is None:
                results.append((name, func, r, why, "not_applied", err, best))
                continue
            sc, st, df = score(name, func, head + nb + tail)
            if sc is None:
                results.append((name, func, r, why, "compile_error", "", best))
                tried.append(why)
                msg = re.findall(r"error: ([^\n]*)|:\d+: ([^\n]*)", st)
                what = ", ".join(f"line {o.get('line')} -> {str(o.get('text', '')).strip()!r}"
                                 for o in ops if isinstance(o, dict) and o.get("op") == "replace")
                errors.append(f"{what or why} ({(msg[-1][0] or msg[-1][1])[:80] if msg else 'error'})")
                continue
            verdict = "better" if sc < best else ("same" if sc == best else "worse")
            results.append((name, func, r, why, verdict, sc, best))
            if sc < best:
                best, best_body, best_diff = sc, nb, df
                log(f"{tag} {name} {func}: round {r}/{rounds}: better {sc} ({st}) - {why}")
            else:
                tried.append(why)
        log(f"{tag} {name} {func}: round {r}/{rounds} done, {len(variants)} variants in {secs:.0f} s, "
            f"best {best} (base {base})")
    dest = OUT / name / f"{func}.cpp"
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text(best_body, newline=NL)
    log(f"{tag} {name} {func}: {'MATCH' if best == 0 else 'end'}, base {base} -> best {best}"
        + (f" (saved {dest.relative_to(ROOT).as_posix()})" if best < base else ""))
    return base, best


def main():
    ap = argparse.ArgumentParser(description=__doc__.split(NL)[0])
    ap.add_argument("name", nargs="?")
    ap.add_argument("func", nargs="?")
    ap.add_argument("--queue", help="file of '<file><TAB><func>' lines")
    ap.add_argument("--model", default="qwen2.5-coder:7b-instruct")
    ap.add_argument("--rounds", type=int, default=6)
    ap.add_argument("--n", type=int, default=4, help="variants asked per round")
    ap.add_argument("--mode", choices=sorted(OPS), default="all",
                    help="operations offered: all, or replace (rewrites only; reordering is permute.py's job)")
    ap.add_argument("--resume", action="store_true", help="start from build/qwen/<file>/<func>.cpp when better")
    a = ap.parse_args()
    jobs = ([tuple(l.split("\t")[:2]) for l in Path(a.queue).read_text().splitlines() if l.strip()]
            if a.queue else [(a.name, a.func)])
    if not match.server_up():
        match.server("start")
    log(f"qwen run: {len(jobs)} functions, {a.rounds} rounds x {a.n} variants, model {a.model}, mode {a.mode}")
    results, summary = [], []
    for i, (name, func) in enumerate(jobs, 1):
        r = run(name, func, a.model, a.rounds, a.n, f"[{i}/{len(jobs)}]", results, a.mode, a.resume)
        summary.append((name, func, r))
        rt = OUT / "results.tsv"
        new = not rt.exists()
        with open(rt, "a", encoding="utf-8", newline=NL) as f:
            if new:
                f.write("file\tfunc\tround\twhy\tverdict\tdetail\tbest_before" + NL)
            for row in results:
                f.write("\t".join(str(x).replace("\t", " ") for x in row) + NL)
        results.clear()
    log("qwen run done: " + ", ".join(f"{f} {r[0]}->{r[1]}" if r else f"{f} skipped" for _, f, r in summary))


if __name__ == "__main__":
    main()
