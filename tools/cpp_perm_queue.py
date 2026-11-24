#!/usr/bin/env python3
"""Run tools/cpp_perm.py (cpp_permuter) over the NON_MATCHING attempts,
closest first, and merge what it matches. Runs in the main checkout:
the search compiles in the container's /tmp; src/ is written only to
apply a match, under build/workers/merge.lock, with a full build.

    tools/.venv/Scripts/python.exe tools/cpp_perm_queue.py --minutes 10 --max-off 40 \\
        --skip build/workers/codex-owns.txt --avoid unk/001B64C4,unk/00166AD0

A score of 0 is applied (the function's NON_MATCHING block replaced by the
permuted text), checked with match.py (whole object), then the full build
must give build/ok; otherwise everything is put back. Functions already
tried (build/cpp_perm/<function>/permuter_out exists) are skipped unless
--retry. Log: build/workers/cpp-perm.log.
"""
import argparse
import os
import re
import subprocess
import sys
import time
from pathlib import Path

os.environ.setdefault("ROR_QUIET_HI16", "1")
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402
import rules_check  # noqa: E402
import regalloc_triage  # noqa: E402

LOG = ROOT / "build" / "workers" / "cpp-perm.log"
LOCK = ROOT / "build" / "workers" / "merge.lock"


def log(msg):
    line = f"{time.strftime('%H:%M')} {msg}"
    print(line, flush=True)
    with open(LOG, "a", encoding="utf8") as f:
        f.write(line + "\n")


def raw_offsets(name, fn):
    """True when the function's NON_MATCHING attempt still reads fields by
    offset (M2C_FIELD or a (char *) cast plus a constant)."""
    try:
        text = (ROOT / "src" / f"{name}.cpp").read_text(encoding="utf8")
    except OSError:
        return False
    blocks = [b for b in re.findall(r"#ifdef NON_MATCHING\n(.*?)#else", text, re.S) if fn in b]
    body = blocks[0] if blocks else ""
    return "M2C_FIELD" in body or bool(re.search(r"\(char \*\)\s*\w+\s*\+\s*0x", body))


def candidates(a):
    skip = set()
    for p in a.skip:
        try:
            skip |= set(re.findall(r"func_[0-9A-F]{8}|\w+__\w+", Path(p).read_text(encoding="utf8")))
        except OSError:
            pass
    avoid = [x for x in a.avoid.split(",") if x]
    out = []
    for l in (ROOT / "build" / "regalloc_triage.tsv").read_text(encoding="utf8").splitlines()[1:]:
        w = l.split("\t")
        if len(w) < 4 or w[2] in ("broken", "fn_match"):
            continue
        name, fn = w[0], w[1]
        e = re.search(r"(\d+) edits", w[3])
        if not e or int(e.group(1)) > a.max_off or fn in skip or any(name.startswith(x) for x in avoid):
            continue
        # Permute only register/schedule plateaus: an attempt of another size
        # or calling/loading the wrong things needs source work first (types,
        # inlines, control flow), which no permutation finds.
        if not a.loose and ("(size 0x" in w[3] or "reloc" in w[3]):
            continue
        # Which kinds Smoke closes (R28, notes/research/R28-smoke-yield.md):
        # every hit was an "order" or an "other" source-shape near miss.
        # "regs" never moved (0 of 7: regalloc.py / PS2_REG work instead),
        # "other" at 3 edits or fewer never moved (0 of 6), and code still
        # written with raw offsets is refused by rules_check.py anyway.
        edits = int(e.group(1))
        if not a.loose and (w[2] == "regs" or (w[2] == "order" and edits > 30)
                            or (w[2] == "other" and not 5 <= edits <= 30)):
            continue
        if not a.loose and raw_offsets(name, fn):
            continue
        if not a.retry and (ROOT / "build" / "cpp_perm" / fn / "permuter_out").exists():
            continue
        out.append((int(e.group(1)), name, fn))
    return sorted(out)


def git(*args):
    return subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True)


def apply_match(name, fn):
    outs = sorted((ROOT / "build" / "cpp_perm" / fn / "permuter_out").glob("output-0-*"))
    if not outs:
        return False
    src = ROOT / "src" / f"{name}.cpp"
    while LOCK.exists() or subprocess.run(["sh", "-c", "pgrep -f 'ninja|merge_worker'"], capture_output=True).returncode == 0:
        time.sleep(15)
    LOCK.mkdir()
    try:
        if git("status", "--porcelain", "--", "src").stdout.strip():
            log(f"  {fn}: src/ has uncommitted changes, not applying")
            return False
        text = src.read_text(encoding="utf8")
        m = next((m for m in regalloc_triage.NM.finditer(text) if m.group(2) == fn), None)
        if not m:
            log(f"  {fn}: its NON_MATCHING block is gone (matched meanwhile?)")
            return False
        pre, suf = text[:m.start()], text[m.end():]
        for out in outs:
            cand = (out / "source.cpp").read_text(encoding="utf8")
            if not (cand.startswith(pre) and cand.endswith(suf)):
                log(f"  {fn}: {out.name} was made from an older file, skipped")
                continue
            ok, rep = match.compare(name, source=str(out / "source.cpp"))
            if not ok:
                log(f"  {fn}: {out.name} scores 0 but match.py says: {rep[-1] if rep else '?'}")
                continue
            src.write_text(cand, encoding="utf8", newline="\n")
            why = rules_check.worse(name)
            if why:
                # CLAUDE.md readability rules: such a match waits for typing
                log(f"  {fn}: MATCH in {out.name} but {why}; not merged, clean it first")
                src.write_text(text, encoding="utf8", newline="\n")
                return False
            (ROOT / "build" / "ok").unlink(missing_ok=True)
            subprocess.run(["sh", str(ROOT / "tools/dock"), "ninja"], cwd=ROOT, capture_output=True)
            if not (ROOT / "build" / "ok").exists():
                log(f"  {fn}: full build failed, put back")
                src.write_text(text, encoding="utf8", newline="\n")
                subprocess.run(["sh", str(ROOT / "tools/dock"), "ninja"], cwd=ROOT, capture_output=True)
                return False
            git("add", str(src))
            git("commit", "-q", "-m", f"{name}: match {fn} (cpp_permuter)\n\n"
                "Found by tools/cpp_perm_queue.py; checked with match.py and the full build.\n\n"
                "Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>")
            log(f"  {fn}: MATCH merged ({git('log', '--oneline', '-1').stdout.strip()})")
            return True
        return False
    finally:
        LOCK.rmdir()


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--minutes", type=float, default=3,
                    help="per function (R28: every hit came within 2.5 minutes)")
    ap.add_argument("--jobs", type=int, default=5)
    ap.add_argument("--max-off", type=int, default=40, help="skip attempts further than this many edits")
    ap.add_argument("--skip", action="append", default=[], help="file listing functions others own")
    ap.add_argument("--avoid", default="", help="comma list of file prefixes to leave alone")
    ap.add_argument("--retry", action="store_true", help="also functions already tried")
    ap.add_argument("--loose", action="store_true",
                    help="also attempts of another size or with wrong relocations, register-only ones, "
                         "'other' ones under 5 or over 30 edits, and raw-offset code (default: R28's filter)")
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args()
    if not match.server_up():
        match.server("start")
    todo = candidates(a)
    if a.limit:
        todo = todo[:a.limit]
    log(f"== cpp_permuter queue: {len(todo)} functions, {a.minutes} min each")
    found = 0
    for i, (e, name, fn) in enumerate(todo, 1):
        text = (ROOT / "src" / f"{name}.cpp").read_text(encoding="utf8")
        if not any(m.group(2) == fn for m in regalloc_triage.NM.finditer(text)):
            continue
        log(f"[{i}/{len(todo)}] {name} {fn} ({e} edits)")
        r = subprocess.run([sys.executable, str(ROOT / "tools/cpp_perm.py"), name, fn, "--minutes", str(a.minutes),
                            "--jobs", str(a.jobs)], cwd=ROOT, capture_output=True, text=True)
        out = r.stdout + r.stderr
        base = re.search(r"^base: score (\d+)", out, re.M)
        best = sorted(int(p.name.split("-")[1]) for p in (ROOT / "build" / "cpp_perm" / fn / "permuter_out").glob("output-*"))
        err = re.search(r"^error: .*", out, re.M)
        log(f"  base {base.group(1) if base else '?'}, best {best[0] if best else 'none'}" + (f"; {err.group(0)[:100]}" if err else ""))
        if best and best[0] == 0 and apply_match(name, fn):
            found += 1
    log(f"== queue done: {found} merged")


if __name__ == "__main__":
    main()
