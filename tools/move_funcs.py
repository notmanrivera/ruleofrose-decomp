"""Split a source file at a new file boundary: move the functions at or past
a text address, and the .rodata at or past a rodata address, from
src/<old>.cpp to src/<new>.cpp (or, with --head, those before them).

    tools/move_funcs.py unk/BdlMain unk/BdlOutAtk 0x14C2FC 0x2EF690
    tools/move_funcs.py unk/HfmMain unk/MagLifeWindowDebug 0x1445D8 0x2EF260 --head

The file is cut into top-level chunks (separated by blank lines outside
braces and #if blocks). A chunk with INCLUDE_ASM / INCLUDE_RODATA, or one
that defines a function, gets that symbol's address (from asm/<old>.s, or
the D_XXXXXXXX name); the others are declarations and are copied to both
files (unused declarations cost nothing). INCLUDE paths are rewritten.
Run it after the splits change and before configure.py: asm/<old>.s must
still be the old file's. Then build and match.py both files."""
import argparse
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def chunks(text):
    out, cur, depth, ifd = [], [], 0, 0
    for line in text.split("\n"):
        s = line.strip()
        if s.startswith("#if"):
            ifd += 1
        if s.startswith("#endif"):
            ifd -= 1
        cur.append(line)
        depth += line.count("{") - line.count("}")
        if depth == 0 and ifd == 0 and s == "":
            out.append(cur)
            cur = []
    if cur:
        out.append(cur)
    return out


def addresses(old):
    addr, name = {}, None
    for line in (ROOT / "asm" / f"{old}.s").read_text(errors="replace").splitlines():
        m = re.match(r"\s*glabel (\S+)", line)
        if m:
            name = m.group(1)
            continue
        m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ", line)
        if m and name:
            addr[name] = int(m.group(1), 16)
            name = None
    return addr


def where(chunk, addr):
    """('text'|'rodata', address) of a chunk, or None for declarations."""
    t = "\n".join(chunk)
    m = re.search(r'INCLUDE_RODATA\("[^"]+",\s*(\w+)\)', t)
    if m:
        return "rodata", int(m.group(1)[-8:], 16)
    m = re.search(r'INCLUDE_ASM\("[^"]+",\s*(\w+)\)', t)
    if m:
        return "text", addr[m.group(1)]
    if "{" not in t:
        return None
    # a definition's first line has no ';' (a prototype's has)
    for m in re.finditer(r'^\S[^;\n]*?\b(\w+)\s*\([^;\n]*$', t, re.M):
        if m.group(1) in addr:
            return "text", addr[m.group(1)]
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("old")
    ap.add_argument("new")
    ap.add_argument("text", type=lambda s: int(s, 16))
    ap.add_argument("rodata", type=lambda s: int(s, 16))
    ap.add_argument("--head", action="store_true",
                    help="the new file is the part before the addresses")
    a = ap.parse_args()
    addr = addresses(a.old)
    keep, move = [], []
    for c in chunks((ROOT / "src" / f"{a.old}.cpp").read_text(encoding="utf8")):
        w = where(c, addr)
        t = "\n".join(c)
        if w is None and re.search(r"\)\s*(const\s*)?\n?\{", t) and "inline" not in t \
                and not re.match(r"\s*(//[^\n]*\n\s*)*(struct|class|union|enum|typedef)\b", t):
            # A function definition whose symbol is not a glabel here (a C++
            # method: its asm name is mangled). Left in the old file; check it.
            first = next(l for l in c if re.match(r"\S", l) and not l.startswith("//"))
            print(f"not placed (kept in {a.old}): {first.strip()[:100]}")
            keep.append(c)
            continue
        if w is None:
            keep.append(c)
            move.append(c)
            continue
        past = w[1] >= (a.text if w[0] == "text" else a.rodata)
        (move if past != a.head else keep).append(c)
    nmove = sum(1 for c in move if where(c, addr))
    text = "\n".join("\n".join(c) for c in move)
    text = text.replace(f'"asm/nonmatchings/{a.old}"', f'"asm/nonmatchings/{a.new}"')
    dst = ROOT / "src" / f"{a.new}.cpp"
    assert not dst.exists(), f"{dst} exists"
    dst.write_text(text, encoding="utf8", newline="\n")
    (ROOT / "src" / f"{a.old}.cpp").write_text("\n".join("\n".join(c) for c in keep),
                                               encoding="utf8", newline="\n")
    print(f"moved {nmove} functions/rodata blocks to src/{a.new}.cpp")


if __name__ == "__main__":
    main()
