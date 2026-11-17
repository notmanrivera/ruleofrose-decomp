#!/usr/bin/env python3
"""Run decomp-permuter (github.com/simonlindholm/decomp-permuter, cloned to
build/decomp-permuter, not in git) on NON_MATCHING attempts, inside the
ror-build image: the real ee-gcc 2.96, mips objdump and fix_hi16.

    (in a worker's worktree, not the main checkout)
    tools/.venv/Scripts/python.exe tools/perm_official.py unk/MnuPBook func_00193D1C --minutes 10
    tools/.venv/Scripts/python.exe tools/perm_official.py --queue --minutes 10 --max-off 12   # all, closest first
    tools/.venv/Scripts/python.exe tools/perm_official.py --list                              # what would run

decomp-permuter parses C only. Our attempts are C with C++ around them, so
for each one a plain C file is made: the attempt (its NON_MATCHING block,
`extern "C"` dropped; asm("label") declarations and PS2_REG are GNU C) and
the file's top-level declarations before it, preprocessed, keeping each one
that the permuter's parser accepts after those already kept. The compile
script wraps that file in extern "C" { } and compiles it as C++ with the
build's flags, so the names and the code are what the build makes. The
target is the function's asm compiled through INCLUDE_ASM, as the build does.

A variant with score 0 is only a candidate: its function goes into
tools/work.py's scratch file and is checked there (function and whole
object); only then work.py --done and a commit "<file>: <fn> (permuter)".
Progress: build/workers/perm-official.log (tools/orca/bars.py).
"""
import argparse
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402
import permute_queue  # noqa: E402
import work  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
PERM = ROOT / "build/decomp-permuter"
WORK = ROOT / "build/perm_off"
LOG = ROOT / "build/work/.permuted_official"
sys.path.insert(0, str(PERM))

CXX_ONLY = re.compile(r"\bclass\b|::|\btemplate\b|\bvirtual\b|\boperator\b|\bpublic:|\bprivate:|\bprotected:|"
                      r"\bnamespace\b|\bextern \"C\+\+\"|\bnew\b|\bdelete\b|&\s*\w+\s*[,)]|\binline\b")


def dock(cmd, timeout=None):
    r = subprocess.run(["sh", str(ROOT / "tools/dock"), "sh", "-c", cmd], cwd=ROOT,
                       capture_output=True, text=True, timeout=timeout)
    return r.returncode, r.stdout + r.stderr


def top_items(text):
    """Top-level items of a C++ file: (kind, text) with kind "pp" for a
    preprocessor line, "func" for a function definition, "decl" otherwise.
    NON_MATCHING blocks and other #if blocks are taken whole as "pp"."""
    items, i, n = [], 0, len(text)
    while i < n:
        if text[i] in " \t\n":
            i += 1
            continue
        if text.startswith("//", i):
            i = text.find("\n", i) + 1 or n
            continue
        if text.startswith("/*", i):
            i = text.find("*/", i) + 2
            continue
        if text[i] == "#":
            if re.match(r"#\s*if", text[i:i + 8]):
                depth, j = 0, i
                while j < n:
                    line_end = text.find("\n", j)
                    line_end = n if line_end < 0 else line_end
                    s = text[j:line_end].strip()
                    if s.startswith("#if"):
                        depth += 1
                    elif s.startswith("#endif"):
                        depth -= 1
                        if depth == 0:
                            j = line_end
                            break
                    j = line_end + 1
                items.append(("ppblock", text[i:j]))
                i = j
                continue
            j = i
            while True:
                e = text.find("\n", j)
                e = n if e < 0 else e
                if text[e - 1:e] != "\\":
                    break
                j = e + 1
            items.append(("pp", text[i:e]))
            i = e
            continue
        # a declaration or definition: up to ';' at depth 0, or a '}' closing
        # a function body (a '{' after a ')')
        depth, j, start = 0, i, i
        kind = "decl"
        while j < n:
            c = text[j]
            if c == '"' or c == "'":
                q = c
                j += 1
                while j < n and text[j] != q:
                    j += 2 if text[j] == "\\" else 1
            elif text.startswith("//", j):
                j = text.find("\n", j)
                continue
            elif c == "{":
                if depth == 0 and re.search(r"\)\s*(?:const\s*)?(?:asm\([^)]*\)\s*)?$", text[start:j]):
                    kind = "func"
                depth += 1
            elif c == "}":
                depth -= 1
                if depth == 0 and kind == "func":
                    j += 1
                    break
            elif c == ";" and depth == 0:
                j += 1
                break
            j += 1
        items.append((kind, text[start:j]))
        i = j
    return items


def plain_c(s):
    s = re.sub(r'\bextern\s+"C"\s*', "extern ", s)
    s = re.sub(r"\bextern\s+extern\b", "extern", s)
    s = re.sub(r"\bbool\b", "int", s)
    s = re.sub(r"\btrue\b", "1", s)
    s = re.sub(r"\bfalse\b", "0", s)
    return s


def raw_source(name, fn):
    """The C text before preprocessing: macros, the file's declarations up
    to the attempt, and the attempt; None when there is none."""
    text = (ROOT / "src" / f"{name}.cpp").read_text(encoding="utf8", errors="replace")
    m = work.nm_block(text, name, fn)
    if not m:
        return None
    before = text[:m.start()]
    out = ['#define PS2_REG(r) __asm__(r)',
           '#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))',
           'typedef int u_long128 __attribute__((mode(TI)));',
           'typedef unsigned int size_t;']
    for kind, it in top_items(before):
        if kind == "pp":
            if re.match(r"#\s*define\s", it) and "M2C_FIELD" not in it and "PS2_REG" not in it:
                out.append(it)
        elif kind == "decl":
            if not CXX_ONLY.search(it) and "INCLUDE_ASM" not in it and "INCLUDE_RODATA" not in it \
                    and not it.lstrip().startswith(("using", "static_assert", "STATIC_ASSERT")):
                out.append(plain_c(it))
    out.append(plain_c(m.group(1)))
    return "\n".join(out) + "\n"


def parses(text):
    from perm_pycparser import c_parser
    try:
        c_parser.CParser().parse(text)
        return True
    except Exception:
        return False


def keep_parsable(pre, fn):
    """The preprocessed text with each top-level item kept only when the
    parser accepts it after the ones already kept; the function must stay."""
    items = [it for kind, it in top_items(pre) if kind != "pp"]
    kept = []
    for it in items:
        is_target = re.search(rf"\b{re.escape(fn)}\s*\([^;{{]*\)\s*\{{", it) is not None
        trial = "\n".join(kept + [it])
        if parses(trial):
            kept.append(it)
        elif is_target:
            return None
    text = "\n".join(kept) + "\n"
    return text if re.search(rf"\b{re.escape(fn)}\s*\(", text) else None


COMPILE = """#!/bin/sh
# decomp-permuter's compiler: $1 input.c -o $3 output.o. The C file goes in
# extern "C" { } and is compiled as C++ with the build's flags.
set -e
out=$(cd "$(dirname "$3")" && pwd)/$(basename "$3")
d=$(mktemp -d)
trap 'rm -rf "$d"' EXIT
{ printf 'extern "C" {\\n'; cat "$1"; printf '\\n}\\n'; } > "$d/x.cpp"
cd "$d"
ee-cc @COMPILER@ @CFLAGS@ -c x.cpp -o out.o 2>/dev/null
python3 /work/tools/fix_hi16.py out.o >/dev/null
cp out.o "$out"
"""


def prepare(name, fn):
    """build/perm_off/<file>/<fn>/ ready for the permuter, or a reason."""
    d = WORK / name / fn
    if d.exists():
        shutil.rmtree(d)
    d.mkdir(parents=True)
    raw = raw_source(name, fn)
    if raw is None:
        return None, "no NON_MATCHING attempt"
    (d / "raw.c").write_text(raw, encoding="utf8", newline="\n")
    (d / "target.cpp").write_text(f'#include "include_asm.h"\nINCLUDE_ASM("asm/nonmatchings/{name}", {fn});\n',
                                  encoding="utf8", newline="\n")
    cflags = configure.CFLAGS.replace("-x c++", "-x c++").replace("-I. -I../include -Wa,-I..", "")
    (d / "compile.sh").write_text(COMPILE.replace("@COMPILER@", configure.COMPILER).replace("@CFLAGS@", cflags),
                                  encoding="utf8", newline="\n")
    (d / "settings.toml").write_text(f'func_name = "{fn}"\ncompiler_type = "gcc"\n', encoding="utf8", newline="\n")
    rel = d.relative_to(ROOT).as_posix()
    # preprocess (C, line markers off) and build the target in src/, as the build
    # (in the container's own filesystem: the old compiler trips on the
    # Windows mount, "Value too large for defined data type")
    code, out = dock(f"set -e; T=/tmp/t; rm -rf $T; mkdir -p $T/src $T/asm/nonmatchings/{name}; "
                     f"cp -r /work/include $T/; cp -r /work/asm/nonmatchings/{name}/. $T/asm/nonmatchings/{name}/; "
                     f"cp /work/{rel}/raw.c /work/{rel}/target.cpp $T/; "
                     f"cd $T && ee-cc {configure.COMPILER} -E -P -x c raw.c -o pre.c; "
                     f"cd $T/src && ee-cc {configure.COMPILER} {configure.CFLAGS} -c ../target.cpp -o ../target.o; "
                     f"python3 /work/tools/fix_hi16.py $T/target.o >/dev/null; "
                     f"cp $T/pre.c $T/target.o /work/{rel}/")
    if code or not (d / "pre.c").exists() or not (d / "target.o").exists():
        return None, "preprocess/target failed: " + out[-300:]
    base = keep_parsable((d / "pre.c").read_text(encoding="utf8", errors="replace"), fn)
    if base is None:
        return None, "the parser rejects the function"
    (d / "base.c").write_text(base, encoding="utf8", newline="\n")
    code, out = dock(f"cd /work/{rel} && sh compile.sh base.c -o base.o && echo COMPILED")
    if "COMPILED" not in out:
        return None, "base.c does not compile as C++: " + out[-300:]
    return d, None


def run(name, fn, minutes, jobs):
    """(status, best) after a permuter run; status "MATCH" when work.py agrees."""
    d, why = prepare(name, fn)
    if d is None:
        return "skipped", why
    rel = d.relative_to(ROOT).as_posix()
    # run in the container's own filesystem (the Windows mount is slow and
    # trips the old compiler), copy results back
    secs = int(minutes * 60)
    # the image has no cpp: the permuter's calls go to ee-gcc's preprocessor
    cpp = f"mkdir -p /tmp/bin && printf '#!/bin/sh\\nexec ee-cc {configure.COMPILER} -E -x c \"$@\"\\n' > /tmp/bin/cpp && chmod +x /tmp/bin/cpp && "
    code, out = dock(cpp + f"export PATH=/tmp/bin:$PATH EE_CC_MIRROR=0 && "
                     f"rm -rf /tmp/p && cp -r /work/{rel} /tmp/p && cd /tmp/p && chmod +x compile.sh && "
                     f"timeout {secs} env PYTHONPATH=/work/build/decomp-permuter/pylib python3 /work/build/decomp-permuter/permuter.py . -j {jobs} --stop-on-zero "
                     f"--best-only >/tmp/p/permuter.log 2>&1; "
                     f"rm -rf /work/{rel}/out && mkdir -p /work/{rel}/out && "
                     f"cp -r /tmp/p/output-* /work/{rel}/out/ 2>/dev/null; cp /tmp/p/permuter.log /work/{rel}/", timeout=secs + 600)
    log = (d / "permuter.log").read_text(errors="replace") if (d / "permuter.log").exists() else ""
    base = re.search(r"base score = (\d+)", log)
    scores = [int(s) for s in re.findall(r"(?:new best|found a better score)[^\d]*(\d+)", log)]
    outs = sorted((d / "out").glob("output-*"), key=lambda p: int(p.name.split("-")[1]) if p.name.split("-")[1].isdigit() else 1 << 30)
    best = f"base {base.group(1) if base else '?'}" + (f", best {min(scores)}" if scores else "")
    zero = [p for p in outs if p.name.startswith("output-0-")]
    if not zero:
        return "no match", best
    src = (zero[0] / "source.c").read_text(encoding="utf8", errors="replace")
    func = next((it for kind, it in top_items(src) if kind == "func"
                 and re.search(rf"\b{re.escape(fn)}\s*\(", it.split("{", 1)[0])), None)
    if not func:
        return "no match", best + " (score 0, but its function was not found)"
    # into work.py's scratch file: the attempt's declarations stay, the
    # function is the permuter's, as extern "C"
    scratch = work.WORK / name / f"{fn}.cpp"
    subprocess.run([sys.executable, "tools/work.py", name, fn], cwd=ROOT, capture_output=True, text=True)
    text = scratch.read_text(encoding="utf8")
    head, body = text.split(work.FUNC, 1)
    decls = "\n".join(ln for ln in body.split("\n") if ln.strip().startswith("extern") and ln.strip().endswith(";"))
    scratch.write_text(head + work.FUNC + "\n" + decls + "\nextern \"C\" " + func.strip() + "\n",
                       encoding="utf8", newline="\n")
    r = subprocess.run([sys.executable, "tools/work.py", name, fn], cwd=ROOT, capture_output=True, text=True)
    st = re.search(rf"^  0x[0-9A-F]+ {re.escape(fn)}\s+0x[0-9a-f]+\s+(.*)$", r.stdout, re.M)
    if not st or st.group(1).strip() != "MATCH":
        return "no match", best + f" (score 0, but work.py says {st.group(1).strip() if st else 'it does not compile'})"
    dn = subprocess.run([sys.executable, "tools/work.py", name, fn, "--done"], cwd=ROOT, capture_output=True, text=True)
    if dn.returncode:
        return "no match", best + " (MATCH, but work.py --done refused it)"
    subprocess.run(["git", "commit", "-q", "-m", f"{name}: {fn} (permuter)", "--", f"src/{name}.cpp"], cwd=ROOT)
    return "MATCH", best


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name", nargs="?")
    ap.add_argument("function", nargs="?")
    ap.add_argument("--minutes", type=float, default=10)
    ap.add_argument("--jobs", type=int, default=14)
    ap.add_argument("--queue", action="store_true", help="every attempt within --max-off, closest first")
    ap.add_argument("--max-off", type=int, default=12)
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--prepare", action="store_true", help="only make the directory (to look at base.c)")
    a = ap.parse_args()
    if not PERM.exists():
        sys.exit("git clone https://github.com/simonlindholm/decomp-permuter build/decomp-permuter")
    if a.name and a.function:
        jobs = [(0, a.name, a.function, "")]
    else:
        done = set()
        if LOG.exists():
            done = {tuple(ln.split()[:2]) for ln in LOG.read_text().splitlines() if len(ln.split()) >= 3
                    and float(ln.split()[2]) >= a.minutes}
        jobs = [q for q in permute_queue.near_misses(a.max_off, set()) if (q[1], q[2]) not in done]
    if a.list:
        for off, name, fn, st in jobs:
            print(f"{off:4} off  {name} {fn}  ({st})")
        return
    if a.prepare:
        d, why = prepare(a.name, a.function)
        print(d or why)
        return
    print(f"queue: {len(jobs)}", flush=True)
    for k, (off, name, fn, st) in enumerate(jobs, 1):
        t0 = time.time()
        print(f"[{k}/{len(jobs)}] {name} {fn}: start ({st})", flush=True)
        status, best = run(name, fn, a.minutes, a.jobs)
        print(f"[{k}/{len(jobs)}] {name} {fn}: {status}, {best} ({(time.time() - t0) / 60:.1f} min)", flush=True)
        if status != "skipped":
            LOG.parent.mkdir(parents=True, exist_ok=True)
            with open(LOG, "a") as log:
                log.write(f"{name} {fn} {a.minutes}\n")


if __name__ == "__main__":
    main()
