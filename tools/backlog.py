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


def skipped():
    """{(file, name)} a worker gave up on."""
    if not SKIPPED.exists():
        return set()
    return {tuple(l.split()[:2]) for l in SKIPPED.read_text().splitlines() if len(l.split()) >= 2}


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--max", type=int, default=30, help="largest function counted as small (instructions)")
    ap.add_argument("--file", help="list one file's small functions")
    ap.add_argument("--names", type=int, metavar="N", help="with --file: print the first N names, comma-separated")
    ap.add_argument("--exclude", default="", help="comma-separated files to leave out (taken by a worker)")
    ap.add_argument("--nonmatching", action="store_true", help="also list NON_MATCHING attempts")
    ap.add_argument("--top", type=int, default=25, help="files shown in the summary")
    ap.add_argument("--skipped", action="store_true", help="also list functions a worker skipped")
    args = ap.parse_args()
    exclude = {e.strip() for e in args.exclude.split(",") if e.strip()}
    skip = set() if args.skipped else skipped()

    files = [args.file] if args.file else sorted(
        str(p.relative_to(ROOT / "src").with_suffix("")).replace("\\", "/") for p in (ROOT / "src").rglob("*.cpp"))
    rows = {}                      # file -> [(insns, name, nm)]
    for f in files:
        cpp = ROOT / "src" / f"{f}.cpp"
        if f in exclude or not cpp.exists():
            continue
        for name, nm in pending(cpp):
            n = insns(f, name)
            if (f, name) in skip:
                continue
            if n is not None and n <= args.max and (args.nonmatching or not nm):
                rows.setdefault(f, []).append((n, name, nm))

    if args.file:
        import twins
        idx = twins.index()
        tw = {name for _, name, _ in rows.get(args.file, []) if twins.twin_of(args.file, name, idx)}
        items = sorted(rows.get(args.file, []), key=lambda r: (r[1] not in tw, r[0], r[1]))
        if args.names:
            print(", ".join([name for _, name, nm in items if not nm][: args.names]))
            return
        for n, name, nm in items:
            print(f"{n:5}  {name}{'  (NON_MATCHING attempt)' if nm else ''}{'  twin' if name in tw else ''}")
        print(f"{len(items)} functions of up to {args.max} instructions")
        return

    summary = sorted(((len(v), sum(n for n, _, _ in v), f) for f, v in rows.items()), reverse=True)
    print(f"files with functions of up to {args.max} instructions still in asm:")
    for count, total, f in summary[: args.top]:
        print(f"{count:5} functions {total * 4:7,} B  {f}")
    print(f"total: {sum(c for c, _, _ in summary)} functions in {len(summary)} files")


if __name__ == "__main__":
    main()
