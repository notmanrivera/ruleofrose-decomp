#!/usr/bin/env python3
"""Pay down raw offsets mechanically: replace `M2C_FIELD(p, T *, 0x58)` and
`*(T *)((char *)p + 0x58)` in matched code with `p->m_x` when p is declared
as a class whose header has a member at that offset, and keep only what
still compiles to the game's bytes.

    tools/.venv/Scripts/python.exe tools/retype.py unk/mnuBase          # rewrite, verify, keep what matches
    tools/.venv/Scripts/python.exe tools/retype.py unk/mnuBase --dry-run  # only list the proposals
    tools/.venv/Scripts/python.exe tools/retype.py --all                # every file in config/rules_check.tsv

How: the base's class comes from its declaration in the enclosing function
(`MnuBase *arg0`, a local, or `this` in `MnuBase::f`); only plain names are
handled. The class's members (and its bases') are read from its header, and
their offsets and sizes come from ee-gcc itself (a probe compiled with the
file's includes), so vtables, padding and inheritance are exact. A member
fits when it starts at the offset and has the access's size; an array fits
element by element (`p->m_tbl[3]`). Several members at one offset (unions)
are skipped. Each function's rewrites are kept only if tools/match.py still
says "object matches" with them (a wrong member type changes the code:
lw/lwc1, lb/lbu); otherwise that function is put back. At the end the file's
baseline in config/rules_check.tsv is updated.

It never adds members: an offset the header lacks stays (listed with
--dry-run as "no member"), for whoever works on the header (the G tasks)
to name; run this again after a header grows or a parameter gets its class.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "src"
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402
import rules_check  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402

M2C = re.compile(r"M2C_FIELD\(\s*(\w+)\s*,\s*([\w\s]+?)\s*\*\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*\)")
DEREF = re.compile(r"\*\s*\(\s*([\w\s]+?)\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*(\w+)\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)")
SKIP_DECL = re.compile(r"^\s*(?:static|typedef|friend|enum|using|virtual|template|public|private|protected|struct\s+\w+\s*;|class\s+\w+\s*;)\b")


def headers():
    out = {}
    for top in (SRC, ROOT / "include"):
        for h in top.rglob("*.h"):
            text = h.read_text(encoding="utf8", errors="replace")
            inc = h.relative_to(top).as_posix()
            for m in re.finditer(r"^\s*(?:class|struct)\s+(\w+)\s*(:[^{;]*)?\{", text, re.M):
                out.setdefault(m.group(1), (text, m.end() - 1, m.group(2) or "", inc))
    return out


def body(text, brace):
    depth = 0
    for i in range(brace, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return text[brace + 1:i]
    return ""


def body_members(src):
    """[(name, array dims)] of the data members declared in a class body;
    members of anonymous unions/structs count as the class's own."""
    out, i, cur = [], 0, ""
    while i < len(src):
        ch = src[i]
        if ch == "{":
            depth, j = 1, i + 1
            while j < len(src) and depth:
                depth += {"{": 1, "}": -1}.get(src[j], 0)
                j += 1
            inner = src[i + 1:j - 1]
            k = src.find(";", j)
            k = len(src) if k < 0 else k
            after = src[j:k].strip()
            prefix = " ".join(cur.split())
            prefix = re.sub(r"^(?:public|private|protected)\s*:\s*", "", prefix)
            if re.fullmatch(r"(?:union|struct)", prefix) and not after:
                out += body_members(inner)              # anonymous: its members are ours
            elif re.fullmatch(r"(?:union|struct)(?:\s+\w+)?", prefix) and re.fullmatch(r"\w+(?:\[[^\]]*\])*", after):
                m = re.match(r"(\w+)((?:\[[^\]]*\])*)", after)
                out.append((m.group(1), m.group(2).count("[")))
            cur = ""
            i = k + 1 if (after or re.fullmatch(r"(?:union|struct|enum)(?:\s+\w+)?", prefix)) else j
            continue
        if ch == ";":
            stmt = " ".join(cur.split())
            cur = ""
            stmt = re.sub(r"^(?:public|private|protected)\s*:\s*", "", stmt)
            if stmt and "(" not in stmt and ":" not in stmt and "operator" not in stmt and not SKIP_DECL.match(stmt):
                head, *rest = [x.strip() for x in stmt.split(",")]
                names = [re.search(r"(\w+)\s*((?:\[[^\]]*\])*)\s*(?:=.*)?$", head)] + \
                        [re.search(r"^\**\s*(\w+)\s*((?:\[[^\]]*\])*)", r) for r in rest]
                for m in names:
                    if m and m.group(1) not in ("const", "volatile", "unsigned", "signed"):
                        out.append((m.group(1), m.group(2).count("[")))
        elif ch == "}":
            cur = ""
        else:
            cur += ch
        i += 1
    return out


def members(cls, hdrs, seen=None):
    """[(member name, array dims)] of cls and its bases, data members only."""
    seen = seen or set()
    if cls in seen or cls not in hdrs:
        return []
    seen.add(cls)
    text, brace, bases, _ = hdrs[cls]
    out = []
    for b in re.findall(r"(?:public|private|protected)?\s*(\w+)\s*(?:,|$)", bases.lstrip(":")):
        out += members(b, hdrs, seen)
    return out + body_members(re.sub(r"//[^\n]*|/\*.*?\*/", "", body(text, brace), flags=re.S))


def base_type(lines, f0, n, base):
    """The class a plain name has at line n (1-based) inside the function that
    starts at f0: its declaration there (parameter or local), or for `this`
    the class in the function's qualified name. None when it is declared as
    anything else (int arg0 is not a class: that is the G tasks' work)."""
    for k in range(n, f0 - 1, -1):
        line = lines[k - 1]
        if base == "this":
            m = re.search(r"\b(\w+)::~?\w+\s*\(", line)
            if m and k <= f0 + 2:
                return m.group(1)
            continue
        m = re.search(r"\b(\w+)\s*\*\s*(?:const\s+)?\b" + re.escape(base) + r"\b\s*(?:[,)=;\[]|$)", line)
        if m:
            return m.group(1)
        if re.search(r"\b(?:int|char|short|long|float|void|unsigned|u32|s32|u8|s8)\b[\s\*]*\b" + re.escape(base) + r"\b\s*[,)=;]",
                     line):
            return None
    return None


def functions(lines):
    """[(first line, last line)] of top-level definitions outside NON_MATCHING."""
    out, depth, start, nm = [], 0, None, 0
    for i, line in enumerate(lines, 1):
        s = line.strip()
        if nm:
            if s.startswith("#if"):
                nm += 1
            elif s.startswith("#endif"):
                nm -= 1
            elif s.startswith("#else") and nm == 1:
                nm = 0
            continue
        if s.startswith("#ifdef NON_MATCHING") or s.startswith("#if defined(NON_MATCHING)"):
            nm = 1
            continue
        if depth == 0 and "{" in line and start is None and not s.startswith(("struct", "class", "enum", "namespace", "extern \"C\" {")):
            start = i
            while start > 1 and lines[start - 2].strip() and not lines[start - 2].strip().endswith((";", "}")) \
                    and not lines[start - 2].strip().startswith("#"):
                start -= 1
        depth += line.count("{") - line.count("}")
        if depth == 0 and start is not None:
            out.append((start, i))
            start = None
    return out


def proposals(name, hdrs):
    lines = (SRC / f"{name}.cpp").read_text(encoding="utf8", errors="replace").splitlines()
    out = []
    for f0, f1 in functions(lines):
        for n in range(f0, f1 + 1):
            for rx, bi, ti, oi in ((M2C, 1, 2, 3), (DEREF, 2, 1, 3)):
                for m in rx.finditer(lines[n - 1]):
                    base, ty, off = m.group(bi), " ".join(m.group(ti).split()), int(m.group(oi), 0)
                    cls = base_type(lines, f0, n, base)
                    out.append(dict(func=(f0, f1), line=n, text=m.group(0), base=base, type=ty,
                                    off=off, cls=cls if cls in hdrs else None))
    return lines, out


def probe_one(name, includes, entries):
    src = ("#define private public\n#define protected public\n" + "\n".join(includes) +
           "\nint ror_probe[] = {\n" + ",\n".join(entries + ["0"]) + "\n};\n")
    path = ROOT / "build/retype" / (name.replace("/", "_") + "_probe.cpp")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(src, encoding="utf8")
    obj, _ = match.compile_file(name, source=str(path))
    with open(obj, "rb") as f:
        e = ELFFile(f)
        sym = next(s for s in e.get_section_by_name(".symtab").iter_symbols() if s.name.startswith("ror_probe"))
        data = e.get_section(sym["st_shndx"]).data()[sym["st_value"]:]
    return [int.from_bytes(data[i:i + 4], "little") for i in range(0, 4 * len(entries), 4)]


def probe(name, lines, classes, types, hdrs):
    """{cls: [(member, offset, size, element size)]}, {type: size} from ee-gcc,
    one compile per class (a class that does not compile is left out)."""
    base_inc = [l for l in lines if l.startswith("#include")]
    lay, failed = {}, []
    for cls in sorted(classes):
        inc = base_inc + [f'#include "{hdrs[cls][3]}"']
        mems = members(cls, hdrs)
        entries = []
        for mem, dims in mems:
            e = f"(({cls} *)0)->{mem}"
            entries += [f"(int)&{e}", f"sizeof({e})", f"sizeof({e}{'[0]' * dims})"]
        try:
            vals = probe_one(name, inc, entries)
        except (match.CompileError, StopIteration) as exc:
            errs = [l for l in str(exc).splitlines() if "error" in l or "invalid" in l] or [str(exc)]
            failed.append(f"{cls}: {errs[0][:160]}")
            continue
        lay[cls] = [(mem, *vals[3 * k:3 * k + 3]) for k, (mem, _) in enumerate(mems)]
    sizes = {}
    try:
        tl = sorted(types)
        sizes = dict(zip(tl, probe_one(name, base_inc, [f"sizeof({t})" for t in tl])))
    except match.CompileError as exc:
        failed.append(f"types: {str(exc)[:160]}")
    for f in failed:
        print(f"{name}: probe left out {f}")
    return lay, sizes


def resolve(p, lay, sizes):
    size = sizes.get(p["type"])
    hits = []
    for mem, off, total, elem in lay.get(p["cls"], []):
        if off == p["off"] and total == size:
            hits.append(f"{p['base']}->{mem}")
        elif off <= p["off"] < off + total and elem == size and total != elem and (p["off"] - off) % elem == 0 \
                and total % elem == 0:
            hits.append(f"{p['base']}->{mem}[{(p['off'] - off) // elem}]")
    return hits[0] if len(hits) == 1 else None, len(hits)


def run(name, hdrs, dry, quiet=False):
    path = SRC / f"{name}.cpp"
    lines, props = proposals(name, hdrs)
    typed = [p for p in props if p["cls"]]
    if not typed:
        if not quiet:
            print(f"{name}: {len(props)} raw offsets, none with a class-typed base")
        return 0
    lay, sizes = probe(name, lines, {p["cls"] for p in typed}, {p["type"] for p in typed}, hdrs)
    by_func = {}
    for p in typed:
        new, n = resolve(p, lay, sizes)
        if dry:
            what = new or ("no member" if n == 0 else f"{n} members (union?)")
            print(f"  {name}:{p['line']}: {p['text']}  [{p['cls']}+{p['off']:#x}] -> {what}")
        if new:
            by_func.setdefault(p["func"], []).append((p, new))
    print(f"{name}: {len(props)} raw offsets, {len(typed)} on a class-typed base, "
          f"{sum(len(v) for v in by_func.values())} with a header member")
    if dry or not by_func:
        return 0
    original = path.read_text(encoding="utf8")
    ok, _ = match.compare(name)
    if not ok:
        print(f"{name}: does not match before any change; left alone")
        return 0
    kept = 0
    for (f0, f1), reps in sorted(by_func.items()):
        before = path.read_text(encoding="utf8")
        cur = before.splitlines(keepends=True)
        for p, new in reps:
            i = p["line"] - 1
            cur[i] = cur[i].replace(p["text"], new, 1)
        path.write_text("".join(cur), encoding="utf8", newline="")
        why = "no match"
        try:
            good, report = match.compare(name)
            if not good:
                why = "no match: " + " | ".join(l for l in report if "differ" in l or "MISMATCH" in l)[:200]
        except match.CompileError as exc:
            good = False
            why = "compile error: " + next((l for l in str(exc).splitlines() if "error" in l), str(exc))[:200]
        if good:
            kept += len(reps)
            print(f"  lines {f0}-{f1}: {len(reps)} kept")
        else:
            path.write_text(before, encoding="utf8", newline="")
            print(f"  lines {f0}-{f1}: {len(reps)} put back ({why})")
    if kept:
        subprocess.run([sys.executable, str(ROOT / "tools/rules_check.py"), "--update", name], cwd=ROOT,
                       stdout=subprocess.DEVNULL)
    elif path.read_text(encoding="utf8") != original:
        path.write_text(original, encoding="utf8", newline="")
    print(f"{name}: {kept} raw offsets replaced by members")
    return kept


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("names", nargs="*")
    ap.add_argument("--all", action="store_true", help="every file with raw offsets in config/rules_check.tsv")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()
    names = a.names
    if a.all:
        names = [l.split("\t")[0] for l in (ROOT / "config/rules_check.tsv").read_text(encoding="utf8").splitlines()
                 if l and not l.startswith(("#", "file")) and l.split("\t")[1] != "0"]
    if not names:
        ap.error("name a file or use --all")
    hdrs = headers()
    total = sum(run(n.removeprefix("src/").removesuffix(".cpp"), hdrs, a.dry_run, quiet=a.all) for n in names)
    if not a.dry_run:
        print(f"total: {total} raw offsets replaced")


if __name__ == "__main__":
    main()
