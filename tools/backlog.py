#!/usr/bin/env python3
"""Functions still in asm, by size: what to hand out next.

    tools/.venv/bin/python tools/backlog.py                      # files with small functions left
    tools/.venv/bin/python tools/backlog.py --max 60             # "small" = up to 60 instructions
    tools/.venv/bin/python tools/backlog.py --file snd/rxmpeg    # that file's list, smallest first
    tools/.venv/bin/python tools/backlog.py --file snd/rxmpeg --names 15   # first 15, comma-separated
    tools/.venv/bin/python tools/backlog.py --exclude mag/maglifepc2,snd/sndman

Only files that already have src/<file>.cpp count (a file is started with
`configure.py --new`). Functions whose INCLUDE_ASM sits under
`#ifdef NON_MATCHING ... #else` are attempts someone already made; they are
left out unless --nonmatching is given (then listed apart). With --file,
functions with a matched twin (tools/twins.py: same instructions as one
already in C++) come first, marked "twin" in the listing.

Functions a worker already skipped are left out too: build/workers/skipped.txt
(not in git) holds one "<file> <function>" per line; tools/orca/next_batch.sh
fills it from the workers' reports. --skipped also lists them.
"""
import argparse
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SKIPPED = ROOT / "build/workers/skipped.txt"
INCLUDE = re.compile(r'INCLUDE_ASM\("asm/nonmatchings/([^"]+)",\s*([^)\s]+)\)')
SIZE = re.compile(r"^\s*(?:nonmatching|glabel)\s+\S+,\s*(0x[0-9A-Fa-f]+)", re.M)
INSN = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/", re.M)


def pending(cpp):
    """[(name, is_nonmatching_attempt)] for one src file, in file order."""
    out, state = [], None          # state: None, "if" (NON_MATCHING branch), "else"
    for line in cpp.read_text(errors="replace").splitlines():
        s = line.strip()
        if s.startswith("#ifdef NON_MATCHING") or s.startswith("#if defined(NON_MATCHING)"):
            state = "if"
        elif s.startswith("#else") and state == "if":
            state = "else"
        elif s.startswith("#endif") and state:
            state = None
        m = INCLUDE.search(line)
        if m and not s.startswith("//"):
            out.append((m.group(2), state == "else"))
    return out


def insns(file, name):
    path = ROOT / "asm/nonmatchings" / file / f"{name}.s"
    if not path.exists():
        return None
    text = path.read_text(errors="replace")
    m = SIZE.search(text)
    return int(m.group(1), 16) // 4 if m else len(INSN.findall(text))


def skipped_by():
    """{(file, name): {workers that gave up on it}}."""
    out = {}
    if SKIPPED.exists():
        for l in SKIPPED.read_text().splitlines():
            w = l.split()
            if len(w) >= 2:
                out.setdefault((w[0], w[1]), set()).update(w[2:3])
    return out


def skipped():
    """{(file, name)} a worker gave up on."""
    return set(skipped_by())


def families(idx=None):
    """{(file, fn): (representative, size)} for pending functions with the
    same instructions as other pending ones and no matched twin yet: once
    the representative (the first of the family by file and name) matches,
    tools/twin_fill.py fills the others with no model. size counts the
    family's members."""
    import twins
    matched, pending = idx or twins.index()
    fam = {}
    for key, shape in pending.items():
        if shape not in matched:
            fam.setdefault(shape, []).append(key)
    out = {}
    for members in fam.values():
        if len(members) > 1:
            rep = min(members)
            for m in members:
                out[m] = (rep, len(members))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--max", type=int, default=30, help="largest function counted as small (instructions)")
    ap.add_argument("--min", type=int, default=0, help="smallest function listed (instructions)")
    ap.add_argument("--file", help="list one file's small functions")
    ap.add_argument("--names", type=int, metavar="N", help="with --file: print the first N names, comma-separated")
    ap.add_argument("--exclude", default="", help="comma-separated files to leave out (taken by a worker)")
    ap.add_argument("--nonmatching", action="store_true", help="also list NON_MATCHING attempts")
    ap.add_argument("--top", type=int, default=25, help="files shown in the summary")
    ap.add_argument("--budget", type=int, default=0, metavar="INSNS",
                    help="with --names: stop adding functions once the batch has this many instructions")
    ap.add_argument("--by-yield", action="store_true",
                    help="order the summary by expected yield: pending bytes, less the share of the "
                         "file's functions workers skipped")
    ap.add_argument("--skipped", action="store_true", help="also list functions a worker skipped")
    ap.add_argument("--retry", metavar="WORKER",
                    help="only functions other workers skipped and WORKER has not (a second try)")
    args = ap.parse_args()
    exclude = {e.strip() for e in args.exclude.split(",") if e.strip()}
    by = skipped_by()
    skip = set() if args.skipped else set(by)

    files = [args.file] if args.file else sorted(
        str(p.relative_to(ROOT / "src").with_suffix("")).replace("\\", "/") for p in (ROOT / "src").rglob("*.cpp"))
    rows = {}                      # file -> [(insns, name, nm)]
    for f in files:
        cpp = ROOT / "src" / f"{f}.cpp"
        if f in exclude or not cpp.exists():
            continue
        for name, nm in pending(cpp):
            n = insns(f, name)
            if args.retry:
                if args.retry in by.get((f, name), {args.retry}):
                    continue
            elif (f, name) in skip:
                continue
            if n is not None and args.min <= n <= args.max and (args.nonmatching or args.retry or not nm):
                rows.setdefault(f, []).append((n, name, nm))

    if args.file:
        import twins
        idx = twins.index()
        tw = {name for _, name, _ in rows.get(args.file, []) if twins.twin_of(args.file, name, idx)}
        fam = families(idx)

        def order(r):
            # twins first; then a representative of each family (biggest
            # family first: matching it fills the rest); then the others,
            # the non-representative members of families last
            key = (args.file, r[1])
            rep, size = fam.get(key, (None, 1))
            kind = 0 if r[1] in tw else 1 if rep == key else 3 if rep else 2
            return (kind, -size if kind == 1 else 0, r[0], r[1])
        items = sorted(rows.get(args.file, []), key=order)
        if args.names:
            pick, total, reps = [], 0, set()
            for n, name, nm in items:
                if not (args.retry or not nm) or len(pick) >= args.names:
                    continue
                rep = fam.get((args.file, name), (None, 1))[0]
                if rep and rep in reps:
                    continue                  # its family's representative is in this batch
                if rep:
                    reps.add(rep)
                if args.budget and pick and total + n > args.budget:
                    break
                pick.append(name)
                total += n
            print(", ".join(pick))
            return
        for n, name, nm in items:
            f_rep, f_size = fam.get((args.file, name), (None, 1))
            fam_note = (f"  family of {f_size} (representative)" if f_rep == (args.file, name)
                        else f"  family of {f_size}: {f_rep[0]} {f_rep[1]} first" if f_rep else "")
            print(f"{n:5}  {name}{'  (NON_MATCHING attempt)' if nm else ''}{'  twin' if name in tw else ''}{fam_note}")
        print(f"{len(items)} functions of up to {args.max} instructions")
        return

    summary = sorted(((len(v), sum(n for n, _, _ in v), f) for f, v in rows.items()), reverse=True)
    if args.by_yield:
        skipped_in = {}
        for f, _ in by:
            skipped_in[f] = skipped_in.get(f, 0) + 1

        # a family representative is worth its whole family
        bonus = {}
        for (f, fn), (rep, size) in families().items():
            if rep == (f, fn):
                bonus[f] = bonus.get(f, 0) + (size - 1) * (insns(f, fn) or 0)

        def expected(row):
            count, total, f = row
            sk = skipped_in.get(f, 0)
            return (total + bonus.get(f, 0)) * (1 - sk / (sk + count))
        summary.sort(key=expected, reverse=True)
    print(f"files with functions of up to {args.max} instructions still in asm:")
    for count, total, f in summary[: args.top]:
        print(f"{count:5} functions {total * 4:7,} B  {f}")
    print(f"total: {sum(c for c, _, _ in summary)} functions in {len(summary)} files")


if __name__ == "__main__":
    main()
