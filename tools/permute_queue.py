#!/usr/bin/env python3
"""Run tools/permute.py over the near misses, one after another, as a worker
with no agent: in its own worktree (tools/new_worktree.sh perm), committing
each MATCH there for tools/merge_worker.sh perm to take.

    (in ../ror-wt-perm) tools/.venv/bin/python tools/permute_queue.py --minutes 10 --max-off 8

Near misses are the NON_MATCHING attempts in src/ whose note gives few
instructions off ("// NON_MATCHING: 4/115 differ, 3 edits"), closest
first, leaving out files another worker holds (build/workers/*.env in the
main checkout) and functions already permuted for as long
(build/work/.permuted). Before each one the worktree is reset to the main
branch when it is clean, so it works on the merged state; after a MATCH it
runs work.py --done, commits "<file>: <function> (permuter)" and, with
--merge, runs the main checkout's merge_worker.sh perm --defer.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import backlog  # noqa: E402
import work  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
LOG = ROOT / "build/work/.permuted"
NOTE = re.compile(r"^// NON_MATCHING: (.*)$")


def main_checkout():
    common = subprocess.run(["git", "rev-parse", "--path-format=absolute", "--git-common-dir"],
                            cwd=ROOT, capture_output=True, text=True, check=True).stdout.strip()
    return Path(common).parent


def held_files(main):
    out = set()
    for env in (main / "build/workers").glob("*.env"):
        m = re.search(r"^FILE='(.*)'$", env.read_text(errors="replace"), re.M)
        if m and env.stem != "perm":
            out.add(m.group(1))
    return out


def note_off(note):
    """Instructions off as a NON_MATCHING note states it, or None."""
    for pat in (r"(\d+) edits", r"(\d+)/\d+ differ", r"(\d+) of \d+ instructions"):
        m = re.search(pat, note)
        if m:
            return int(m.group(1))
    return None


def measured():
    """{(file, function): (kind, edits)} from tools/regalloc_triage.py's last
    run (build/regalloc_triage.tsv of the main checkout): the distance each
    attempt really has as work.py builds it, where the note in src/ may be
    old (headers change under the attempts)."""
    p = main_checkout() / "build" / "regalloc_triage.tsv"
    out = {}
    try:
        for ln in p.read_text(encoding="utf8").splitlines()[1:]:
            w = ln.split("\t")
            if len(w) >= 4:
                e = re.search(r"(\d+) edits", w[3])
                out[(w[0], w[1])] = (w[2], int(e.group(1)) if e else None)
    except OSError:
        pass
    return out


def near_misses(max_off, skip_files):
    """[(off, file, function, status)], closest first. The distance is the
    triage's measure when it has one (else the note's); broken attempts and
    ones whose function already matches (the object does not) are left out."""
    real = measured()
    found = []
    for cpp in sorted((ROOT / "src").rglob("*.cpp")):
        name = cpp.relative_to(ROOT / "src").with_suffix("").as_posix()
        if name in skip_files:
            continue
        lines = cpp.read_text(encoding="utf8", errors="replace").split("\n")
        for i, line in enumerate(lines):
            m = NOTE.match(line)
            if not m or i + 1 >= len(lines) or not lines[i + 1].startswith("#ifdef NON_MATCHING"):
                continue
            # the function is the INCLUDE_ASM of the block's #else
            for j in range(i + 2, min(i + 2000, len(lines))):
                g = backlog.INCLUDE.search(lines[j])
                if g and lines[j - 1].startswith("#else"):
                    kind, edits = real.get((name, g.group(2)), (None, None))
                    if kind in ("broken", "fn_match"):
                        break
                    off = edits if edits is not None else note_off(m.group(1))
                    if off is None or off <= max_off:     # unknown: measured when its turn comes
                        found.append((99 if off is None else off, name, g.group(2), m.group(1)))
                    break
    return sorted(found)


def done_before(minutes):
    if not LOG.exists():
        return set()
    out = set()
    for ln in LOG.read_text().splitlines():
        w = ln.split()
        if len(w) >= 3 and float(w[2]) >= minutes:
            out.add((w[0], w[1]))
    return out


def git(*args, check=True):
    return subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True, check=check)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--minutes", type=float, default=10, help="per function")
    ap.add_argument("--max-off", type=int, default=8, help="only attempts this close")
    ap.add_argument("--avoid", default="", help="skip files under these prefixes (another worker's), comma-separated")
    ap.add_argument("--skip", help="file of '<file> <function>' lines to leave out (another permuter's)")
    ap.add_argument("--jobs", type=int, default=4, help="compiles at once (permute.py --jobs)")
    ap.add_argument("--merge", action="store_true", help="merge each MATCH right away")
    ap.add_argument("--list", action="store_true", help="only list the queue")
    a = ap.parse_args()
    main_dir = main_checkout()
    if main_dir == ROOT and not a.list:
        sys.exit("run it in its own worktree (tools/new_worktree.sh perm), not in the main checkout")
    py = sys.executable
    avoid = tuple(p for p in a.avoid.split(",") if p) or ("\0",)
    queue = [q for q in near_misses(a.max_off, held_files(main_dir)) if not q[1].startswith(avoid)
             and (q[1], q[2]) not in done_before(a.minutes)]
    if a.skip:                       # "<file> <function>" lines another permuter has
        skip = {tuple(ln.split()[:2]) for ln in Path(a.skip).read_text().splitlines() if ln.strip()}
        queue = [q for q in queue if (q[1], q[2]) not in skip]
    for off, name, fn, status in queue:
        print(f"{off:4} off  {name} {fn}  ({status})")
    if a.list:
        return
    branch = git("-C", str(main_dir), "branch", "--show-current").stdout.strip()
    subprocess.run([py, "tools/match.py", "--server", "start"], cwd=ROOT, check=True)   # this worktree's
    for off, name, fn, status in queue:
        if not git("status", "--porcelain", "--untracked-files=no").stdout.strip():
            git("reset", "-q", "--hard", branch)
        print(f"\n== {name} {fn}: {status}", flush=True)
        r = subprocess.run([py, "tools/work.py", name, fn], cwd=ROOT, capture_output=True, text=True)
        st = re.search(rf"^  0x[0-9A-F]+ {re.escape(fn)}\s+0x[0-9a-f]+\s+(.*)$", r.stdout, re.M)
        if not st:
            print("  does not compile as it is; next")
            continue
        if work.score(st.group(1).strip()) > a.max_off:
            print(f"  {st.group(1).strip()}: further off than --max-off; next")
            continue
        subprocess.run([py, "tools/permute.py", name, fn, "--minutes", str(a.minutes), "--jobs", str(a.jobs)], cwd=ROOT)
        LOG.parent.mkdir(parents=True, exist_ok=True)
        with open(LOG, "a") as log:
            log.write(f"{name} {fn} {a.minutes}\n")
        best = work.BEST / name / f"{fn}.cpp"
        if best.exists() and best.read_text(encoding="utf8").startswith("// best: MATCH"):
            d = subprocess.run([py, "tools/work.py", name, fn, "--done"], cwd=ROOT, capture_output=True, text=True)
            if d.returncode == 0:
                git("commit", "-qam", f"{name}: {fn} (permuter)")
                print(f"  MATCH committed: {name}: {fn}", flush=True)
                if a.merge:
                    m = subprocess.run(["sh", str(main_dir / "tools/merge_worker.sh"), "perm", "--defer"],
                                       cwd=main_dir, capture_output=True, text=True)
                    print("  " + m.stdout.strip().replace("\n", "\n  "), flush=True)
            else:
                print("  the permuter's MATCH did not pass work.py --done:\n" + d.stdout + d.stderr)


if __name__ == "__main__":
    main()
