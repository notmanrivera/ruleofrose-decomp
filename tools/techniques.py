"""What made functions match, from the workers' commit messages.

    tools/.venv/Scripts/python.exe tools/techniques.py              # summary
    tools/.venv/Scripts/python.exe tools/techniques.py --list       # every tagged commit
    tools/.venv/Scripts/python.exe tools/techniques.py --since 2026-11-24

Workers add a line to each commit (docs/WORKER_BRIEF.md):
  "Technique: <the change that closed the last difference>" on a MATCH,
  "Blocker: <what still differs>" on a NON_MATCHING attempt.
This groups them into rough families (by keywords, see FAMILIES) and by
model: the model comes from build/workers/stats.tsv, the batch of the same
file whose merge was logged closest after the commit landed. The point is
to see which techniques pay off, for which models, and to move the ones
that keep working into docs/EE_GCC_TECHNIQUES.md and the briefs.
"""
import argparse
import bisect
import collections
import os
import re
import subprocess
from datetime import datetime

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STATS = os.path.join(ROOT, "build", "workers", "stats.tsv")
TAG = re.compile(r"^(Technique|Blocker):\s*(.+)$", re.M | re.I)
SUBJECT = re.compile(r"^([\w./]+): (\S+)( \(NON_MATCHING\))?$")
# First family whose pattern matches wins; order matters.
FAMILIES = [
    ("first draft", r"first draft|as drafted|m2c draft|twin"),
    ("nothrow / calls", r"nothrow|ASM_NOTHROW|inline|call|extern|prototype|declar"),
    ("register hint", r"PS2_REG|register|\breg\b|\$[asvtf][0-9]"),
    ("locals / temps", r"local|temp|variable|split|merge(d)? .*var|reuse"),
    ("statement order", r"order|swap|reorder|mov(ed|e)|before|after|hoist"),
    ("branches / loops", r"bnel|beql|likely|branch|condition|\bif\b|else|loop|while|for\b|switch|goto|return"),
    ("types / casts", r"type|signed|unsigned|cast|short|char|float|int\b|bool|u_long128|pointer"),
    ("class layout / header", r"member|header|struct|class|vtable|constructor|field|layout|offset"),
    ("data / constants", r"rodata|const|static|literal|string|table"),
]


def git_log(since):
    args = ["git", "-C", ROOT, "log", "--format=%x1e%H%x1f%ct%x1f%s%x1f%b"]
    if since:
        args.append(f"--since={since}")
    out = subprocess.run(args, capture_output=True, text=True, encoding="utf-8", errors="replace").stdout
    for rec in out.split("\x1e")[1:]:
        h, ct, subj, body = (rec.split("\x1f") + ["", "", "", ""])[:4]
        m = SUBJECT.match(subj.strip())
        if not m:
            continue
        tags = TAG.findall(body)
        yield dict(hash=h[:7], time=int(ct), file=m.group(1), func=m.group(2),
                   nm=bool(m.group(3)), tags=[(k.capitalize(), v.strip()) for k, v in tags])


def load_stats():
    """file -> sorted [(merge time, model)]"""
    by = collections.defaultdict(list)
    try:
        lines = open(STATS, encoding="utf-8").read().splitlines()[1:]
    except OSError:
        return by
    for ln in lines:
        p = ln.split("\t")
        if len(p) < 4:
            continue
        try:
            t = int(datetime.strptime(p[0], "%Y-%m-%d %H:%M").timestamp())
        except ValueError:
            continue
        model = p[2].removeprefix("auto · ")
        for f in p[3].split(","):
            by[f.strip()].append((t, model))
    for v in by.values():
        v.sort()
    return by


def model_of(stats, file, t):
    rows = stats.get(file, [])
    i = bisect.bisect_left(rows, (t - 120, ""))   # logged after the merge, allow 2 min skew
    if i < len(rows) and rows[i][0] - t < 6 * 3600:
        return rows[i][1]
    return "?"


def family(text):
    for name, pat in FAMILIES:
        if re.search(pat, text, re.I):
            return name
    return "other"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--since", help="git --since value, e.g. 2026-11-24")
    ap.add_argument("--list", action="store_true", help="print every tagged commit")
    a = ap.parse_args()
    stats = load_stats()
    commits = list(git_log(a.since))
    tagged = [c for c in commits if c["tags"]]
    print(f"{len(commits)} function commits, {len(tagged)} with a Technique/Blocker line"
          + (f" (since {a.since})" if a.since else ""))
    if not tagged:
        print("nothing tagged yet: workers add the line from docs/WORKER_BRIEF.md on.")
        return
    fam = {"Technique": collections.Counter(), "Blocker": collections.Counter()}
    by_model = collections.defaultdict(collections.Counter)
    for c in tagged:
        c["model"] = model_of(stats, c["file"], c["time"])
        for kind, text in c["tags"]:
            f = family(text)
            fam[kind][f] += 1
            if kind == "Technique":
                by_model[c["model"]][f] += 1
    for kind, title in (("Technique", "What closed the last difference (MATCH)"),
                        ("Blocker", "What still differs (NON_MATCHING)")):
        if not fam[kind]:
            continue
        print(f"\n{title}:")
        for f, n in fam[kind].most_common():
            print(f"  {n:4}  {f}")
    if by_model:
        print("\nBy model (MATCH techniques):")
        for m, cnt in sorted(by_model.items(), key=lambda kv: -sum(kv[1].values())):
            top = ", ".join(f"{f} {n}" for f, n in cnt.most_common(4))
            print(f"  {sum(cnt.values()):4}  {m}: {top}")
    if a.list:
        print()
        for c in tagged:
            for kind, text in c["tags"]:
                print(f"{c['hash']}  {kind[0]}  {family(text):<22} {c['file']} {c['func']}  [{c['model']}]  {text}")


if __name__ == "__main__":
    main()
