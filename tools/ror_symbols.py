#!/usr/bin/env python3
"""Extract every recoverable symbol from the Rule of Rose (SLUS-214.48) ELF.

The retail ELF has no .symtab, but it was linked without discarding the
per-function `.gnu.linkonce.*` sections that EE-GCC 2.9x emits for inline
methods, vtables and RTTI. This script:

  1. reads those section names (GCC2-mangled) and their addresses,
  2. demangles them (GCC 2.x ABI, the subset this game uses),
  3. rebuilds the class hierarchy from the `__tf<Class>` RTTI functions,
     and finds the type_info object `__ti<Class>` each one returns,
  4. walks every vtable and propagates method names through overrides
     (a child slot that overrides a named parent slot gets the same name),
  5. locates the source-path strings left behind by asserts.

Outputs (all derived data, no game code or assets):
  symbols/ghidra_symbols.tsv   input for ghidra_scripts/ImportRoRSymbols.java
  symbols/symbol_addrs.txt     splat-style symbol list for the decomp build
  symbols/source_strings.tsv   source-path strings for TagSourceFiles.java
  notes/class_hierarchy.txt    inheritance tree with vtable sizes

Usage: python3 tools/ror_symbols.py [path/to/SLUS_214.48]
"""
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ELF = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / "disc" / "SLUS_214.48"

# ---------------------------------------------------------------- ELF reading

class Elf:
    def __init__(self, path):
        self.d = d = path.read_bytes()
        if d[:4] != b"\x7fELF":
            sys.exit(f"{path}: not an ELF file")
        phoff, shoff = struct.unpack_from("<II", d, 0x1C)
        phnum, _, shnum, shstrndx = struct.unpack_from("<HHHH", d, 0x2C)
        self.segs = [struct.unpack_from("<8I", d, phoff + i * 32) for i in range(phnum)]
        sh = [struct.unpack_from("<10I", d, shoff + i * 40) for i in range(shnum)]
        stroff = sh[shstrndx][4]
        self.sections = []
        for s in sh:
            name = d[stroff + s[0]:d.index(b"\0", stroff + s[0])].decode()
            self.sections.append((name, s[1], s[3], s[4], s[5]))  # name,type,addr,off,size

    def word(self, va):
        for _, off, vaddr, _, filesz, *_ in self.segs:
            if vaddr <= va < vaddr + filesz:
                return struct.unpack_from("<I", self.d, off + va - vaddr)[0]
        return None

    def section(self, name):
        return next(s for s in self.sections if s[0] == name)


# ------------------------------------------------------- GCC 2.x demangling

BUILTIN = {
    "v": "void", "b": "bool", "c": "char", "s": "short", "i": "int",
    "l": "long", "x": "long long", "f": "float", "d": "double",
    "r": "long double", "w": "wchar_t", "e": "...",
}
OPERATORS = {
    "nw": "new", "dl": "delete", "vn": "new[]", "vd": "delete[]",
    "as": "=", "eq": "==", "ne": "!=", "lt": "<", "gt": ">", "le": "<=",
    "ge": ">=", "pl": "+", "mi": "-", "ml": "*", "dv": "/", "md": "%",
    "apl": "+=", "ami": "-=", "aml": "*=", "adv": "/=", "vc": "[]",
    "cl": "()", "nt": "!", "aa": "&&", "oo": "||", "ad": "&", "or": "|",
    "er": "^", "co": "~", "ls": "<<", "rs": ">>", "pp": "++", "mm": "--",
    "rf": "->",
}


class Demangle(Exception):
    pass


def _class_name(s, i):
    """Parse <len><name> or Q<n><...>; return (qualified name, next index)."""
    if i < len(s) and s[i] == "Q":
        i += 1
        if s[i] == "_":
            j = s.index("_", i + 1)
            n, i = int(s[i + 1:j]), j + 1
        else:
            n, i = int(s[i]), i + 1
        parts = []
        for _ in range(n):
            part, i = _class_name(s, i)
            parts.append(part)
        return "::".join(parts), i
    m = re.match(r"\d+", s[i:])
    if not m:
        raise Demangle(s)
    n = int(m.group())
    start = i + len(m.group())
    if start + n > len(s):
        raise Demangle(s)
    return s[start:start + n], start + n


def _type(s, i, seen):
    quals = []
    while i < len(s) and s[i] in "CVUS":
        quals.append({"C": "const", "V": "volatile", "U": "unsigned", "S": "signed"}[s[i]])
        i += 1
    c = s[i]
    if c in "PR":
        inner, i = _type(s, i + 1, seen)
        t = inner + (" *" if c == "P" else " &")
        if "const" in quals:
            t += " const"
        return t, i
    if c == "A":
        j = s.index("_", i)
        inner, k = _type(s, j + 1, seen)
        return f"{inner}[{s[i + 1:j]}]", k
    if c == "F":
        args, i = _params(s, i + 1, stop="_")
        ret, i = _type(s, i + 1, seen)
        return f"{ret} (*)({', '.join(args)})", i
    if c == "G":  # class/struct passed by value
        c, i = s[i + 1], i + 1
    if c.isdigit() or c == "Q":
        name, i = _class_name(s, i)
    elif c in BUILTIN:
        name, i = BUILTIN[c], i + 1
    else:
        raise Demangle(s)
    return " ".join(quals + [name]), i


def _params(s, i, stop=None):
    out = []
    while i < len(s) and s[i] != stop:
        c = s[i]
        if c == "T":  # repeat of an earlier parameter (1-digit index)
            idx = int(s[i + 1])
            out.append(out[idx - 1] if 0 < idx <= len(out) else f"<T{idx}>")
            i += 2
        elif c == "N":  # repeat count, then index
            cnt, idx = int(s[i + 1]), int(s[i + 2])
            ref = out[idx - 1] if 0 < idx <= len(out) else f"<T{idx}>"
            out.extend([ref] * cnt)
            i += 3
        else:
            t, i = _type(s, i, out)
            out.append(t)
    return out, i


def demangle(m):
    """Return dict(cls, name, args, const, kind) or raise Demangle."""
    if m.startswith("_vt$"):
        parts = m[4:].split("$")
        cls, _ = _class_name(parts[0], 0)
        sub = [ _class_name(p, 0)[0] for p in parts[1:] ]
        return dict(cls=cls, name="vtable" + "".join("_" + p for p in sub),
                    args=None, const=False, kind="vtable")
    if m.startswith("__tf"):
        cls, i = _class_name(m, 4)
        if i != len(m):
            raise Demangle(m)
        return dict(cls=cls, name="__tf", args=None, const=False, kind="typeinfo_fn")
    if m.startswith("_$_"):
        cls, i = _class_name(m, 3)
        return dict(cls=cls, name="~" + cls.split("::")[-1], args=[], const=False, kind="dtor")
    if m.startswith("__") and (m[2].isdigit() or m[2] == "Q"):
        cls, i = _class_name(m, 2)
        args, _ = _params(m, i)
        return dict(cls=cls, name=cls.split("::")[-1], args=args, const=False, kind="ctor")
    op = re.match(r"__([a-z]{2,3})__", m)
    if op and op.group(1) in OPERATORS:
        name, rest = "operator" + OPERATORS[op.group(1)], m[op.end():]
        return _method(name, rest, m)
    # plain method/function: split at the first '__' whose tail parses
    # (overlapping search: names may end in '_', e.g. "dispOn___5S2dBgi")
    for sep in [k for k in range(1, len(m) - 1) if m[k:k + 2] == "__"]:
        try:
            return _method(m[:sep], m[sep + 2:], m)
        except (Demangle, ValueError, IndexError):
            continue
    raise Demangle(m)


def _method(name, rest, m):
    const = False
    if rest.startswith("F"):
        args, i = _params(rest, 1)
        cls = None
    else:
        if rest.startswith("C"):
            const, rest = True, rest[1:]
        cls, i = _class_name(rest, 0)
        args, i = _params(rest, i)
    if i != len(rest):
        raise Demangle(m)
    return dict(cls=cls, name=name, args=[] if args == ["void"] else args,
                const=const, kind="method" if cls else "function")


def signature(info):
    if info["args"] is None:
        return ""
    q = f"{info['cls']}::" if info["cls"] else ""
    return f"{q}{info['name']}({', '.join(info['args'])}){' const' if info['const'] else ''}"


# ------------------------------------------------------------------ analysis

def jal_targets(elf, start, size):
    out = []
    for pc in range(start, start + size, 4):
        w = elf.word(pc)
        if w is not None and w >> 26 == 3:
            out.append(((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
    return out


def first_address(elf, start, size):
    """The first address a function builds with lui + addiu, or None."""
    hi = {}
    for pc in range(start, start + size, 4):
        w = elf.word(pc)
        op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op == 0x0F:  # lui
            hi[rt] = imm << 16
        elif op == 0x09 and rs in hi:  # addiu
            return (hi[rs] + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xFFFFFFFF
    return None


def main():
    elf = Elf(ELF)
    text = elf.section(".text")
    text_lo, text_hi = text[2], text[2] + text[4]
    link_lo = min(s[2] for s in elf.sections if s[0].startswith(".gnu.linkonce.t."))
    link_hi = max(s[2] + s[4] for s in elf.sections if s[0].startswith(".gnu.linkonce.t."))

    def in_code(a):
        return text_lo <= a < text_hi or link_lo <= a < link_hi

    # symbols[addr] = dict(mangled, cls, name, sig, kind, size, source)
    syms = {}
    failed = []
    for name, _, addr, _, size in elf.sections:
        for pre, is_func in ((".gnu.linkonce.t.", True), (".gnu.linkonce.d.", False)):
            if not name.startswith(pre):
                continue
            mangled = name[len(pre):]
            try:
                info = demangle(mangled)
            except (Demangle, ValueError, IndexError):
                info = dict(cls=None, name=mangled, args=None, const=False,
                            kind="function" if is_func else "data")
                failed.append(mangled)
            syms[addr] = dict(mangled=mangled, cls=info["cls"], name=info["name"],
                              sig=signature(info), params=info["args"], kind=info["kind"], size=size,
                              source="linkonce")

    # --- class hierarchy from RTTI functions (__tf<Class> calls __tf<Base>)
    tf_by_addr = {a: s["cls"] for a, s in syms.items() if s["kind"] == "typeinfo_fn"}
    parents = {}
    helper_calls = defaultdict(lambda: defaultdict(int))  # callee -> n_bases -> count
    for a, cls in tf_by_addr.items():
        targets = jal_targets(elf, a, syms[a]["size"])
        bases = [tf_by_addr[t] for t in targets if t in tf_by_addr and t != a]
        parents[cls] = bases
        for t in targets:
            if t not in tf_by_addr:
                helper_calls[t][min(len(bases), 2)] += 1
    # The non-__tf callee of RTTI functions is libgcc's __rtti_{user,si,class}.
    for callee, by_bases in helper_calls.items():
        if callee in syms:
            continue
        kind = max(by_bases, key=by_bases.get)
        nm = {0: "__rtti_user", 1: "__rtti_si", 2: "__rtti_class"}[kind]
        syms[callee] = dict(mangled=nm, cls=None, name=nm, sig="", params=None, kind="function",
                            size=0, source="rtti-helper")

    # --- type_info objects: __tf<X> fills in and returns __ti<X>, the first
    # address it builds (libgcc's __rtti_* write it on first use, so it is
    # zero-initialised: a COMMON symbol of every file that emits __tf<X>).
    # Its type follows the helper: __user_type_info (8 bytes),
    # __si_type_info (0xC) or __class_type_info (0x10).
    node_size = {"__rtti_user": 0x8, "__rtti_si": 0xC, "__rtti_class": 0x10}
    nobits = [(s[2], s[2] + s[4]) for s in elf.sections if s[1] == 8]  # SHT_NOBITS
    nodes = {}
    for a in tf_by_addr:
        node = first_address(elf, a, syms[a]["size"])
        helper = [syms[t]["name"] for t in jal_targets(elf, a, syms[a]["size"])
                  if t not in tf_by_addr and t in syms]
        if node is None or node in nodes or len(helper) != 1 or \
                not any(lo <= node < hi for lo, hi in nobits):
            sys.exit(f"{syms[a]['mangled']}: no type_info object found")
        nodes[node] = dict(mangled="__ti" + syms[a]["mangled"][len("__tf"):],
                           size=node_size[helper[0]])

    classes = sorted({s["cls"] for s in syms.values() if s["cls"]})

    def depth(c, seen=()):
        if c in seen:
            return 0
        return 1 + max((depth(p, seen + (c,)) for p in parents.get(c, [])), default=0)

    order = sorted(classes, key=lambda c: (depth(c), c))  # bases first

    # --- vtables: slot tables per class (primary vtable only)
    vtables = {}
    for a, s in syms.items():
        if s["kind"] != "vtable":
            continue
        slots = []
        for off in range(8, s["size"], 8):  # entry 0 is {0, __tf}
            pfn = elf.word(a + off + 4)
            slots.append(pfn if pfn and in_code(pfn) else None)
        if s["name"] == "vtable":
            vtables[s["cls"]] = (a, slots)

    # Functions used at more than one slot index are shared stubs, not
    # methods of one class: GCC2 fills every pure virtual slot of an abstract
    # class with libgcc's __pure_virtual. Name them and keep them out of the
    # override propagation, or one method name would leak into every class
    # that has a pure virtual.
    slot_uses = defaultdict(set)
    for cls, (_, slots) in vtables.items():
        for i, pfn in enumerate(slots):
            if pfn is not None:
                slot_uses[pfn].add(i)
    shared = sorted((p for p, idx in slot_uses.items() if len(idx) > 1),
                    key=lambda p: -len(slot_uses[p]))
    for n, pfn in enumerate(shared):
        if syms.get(pfn, {}).get("source") == "linkonce":
            continue
        nm = "__pure_virtual" if n == 0 else f"shared_vfunc_{pfn:08X}"
        syms[pfn] = dict(mangled=nm, cls=None, name=nm, sig="", params=None, kind="function",
                         size=0, source="shared-stub")
    shared = set(shared)

    # Name propagation through overrides, iterated to a fixpoint.
    def slot_name(addr):
        s = syms.get(addr)
        return None if s is None or s["source"] in ("vtable-slot", "shared-stub") else s

    changed = True
    while changed:
        changed = False
        for cls in order:
            if cls not in vtables:
                continue
            _, slots = vtables[cls]
            relatives = parents.get(cls, [])[:1] + [c for c in classes if parents.get(c, [])[:1] == [cls]]
            for i, pfn in enumerate(slots):
                if pfn is None or pfn in shared or slot_name(pfn):
                    continue
                for rel in relatives:
                    if rel not in vtables or i >= len(vtables[rel][1]):
                        continue
                    other = slot_name(vtables[rel][1][i])
                    if not other or other["kind"] not in ("method", "dtor"):
                        continue
                    nm = "~" + cls.split("::")[-1] if other["kind"] == "dtor" else other["name"]
                    sig = other["sig"].replace(f"{other['cls']}::{other['name']}", f"{cls}::{nm}", 1)
                    syms[pfn] = dict(mangled=override_mangled(other, cls), cls=cls, name=nm, sig=sig,
                                     params=other["params"], kind=other["kind"], size=0,
                                     source="vtable-override")
                    changed = True
                    break

    # Remaining unnamed slots: attribute to the base-most class that owns them.
    for cls in order:
        if cls not in vtables:
            continue
        for i, pfn in enumerate(vtables[cls][1]):
            if pfn is not None and pfn not in syms:
                syms[pfn] = dict(mangled="", cls=cls, name=f"vfunc_{i + 1:02d}", sig="", params=None,
                                 kind="method", size=0, source="vtable-slot")

    # --- SDK / libgcc / libc names matched by signature (tools/sce_symbols.py)
    sce = ROOT / "symbols/sce_symbols.tsv"
    if sce.exists():
        for line in sce.read_text().splitlines():
            if line.startswith(("#", "addr")):
                continue
            a, lib, nm, size = line.split("\t")
            a = int(a, 16)
            if syms.get(a, {}).get("source") == "linkonce":
                continue
            syms[a] = dict(mangled=nm, cls=None, name=nm, sig="", params=None, kind="function",
                           size=int(size, 16), source="sce-sdb")

    # --- source-path strings left by asserts
    # Strings in .rodata are word-aligned; the byte before one can be the
    # tail of a float (0x3F = '?'), so align rather than look behind.
    src_re = re.compile(rb"([A-Za-z0-9_]*[a-z0-9_]+/[a-z0-9_]+\.(?:cpp|c|h))\x00")
    src_strings = []
    for name, _, addr, off, size in elf.sections:
        if name in (".rodata", ".data"):
            for m in src_re.finditer(elf.d, off, off + size):
                start = m.start(1)
                while (addr + start - off) % 4 and start < m.end(1):
                    start += 1
                path = elf.d[start:m.end(1)].decode()
                if re.fullmatch(r"[a-z0-9_]+/[a-z0-9_]+\.(?:cpp|c|h)", path):
                    src_strings.append((addr + start - off, path))

    write_outputs(syms, nodes, parents, vtables, order, src_strings, failed)


def override_mangled(other, cls):
    """GCC2 mangled name of `cls`'s override of `other`: same method name and
    parameters, different class. Empty when it can't be derived safely."""
    m, oc = other["mangled"], other["cls"]
    if not m or "::" in cls or "::" in (oc or ""):
        return ""
    old, new = f"{len(oc)}{oc}", f"{len(cls)}{cls}"
    if other["kind"] == "dtor":
        return f"_$_{new}"
    prefix = other["name"] + "__"
    if not m.startswith(prefix):
        return ""  # operators and other special encodings
    rest = m[len(prefix):]
    const = rest.startswith("C")
    rest = rest[1:] if const else rest
    if not rest.startswith(old):
        return ""
    return prefix + ("C" if const else "") + new + rest[len(old):]


def params_col(params):
    """';'-joined parameter types; '-' = no parameters, '' = unknown."""
    if params is None:
        return ""
    return ";".join(params) if params else "-"


def write_outputs(syms, nodes, parents, vtables, order, src_strings, failed):
    (ROOT / "symbols").mkdir(exist_ok=True)
    (ROOT / "notes").mkdir(exist_ok=True)

    with open(ROOT / "symbols/ghidra_symbols.tsv", "w") as f:
        f.write("addr\tkind\tclass\tname\tsize\tsource\tmangled\tsignature\tparams\n")
        for a in sorted(syms):
            s = syms[a]
            f.write(f"{a:08x}\t{s['kind']}\t{s['cls'] or ''}\t{s['name']}\t{s['size']:x}\t"
                    f"{s['source']}\t{s['mangled']}\t{s['sig']}\t{params_col(s['params'])}\n")

    with open(ROOT / "symbols/symbol_addrs.txt", "w") as f:
        f.write("// Generated by tools/ror_symbols.py -- do not edit by hand.\n")
        f.write("// Names are GCC2-mangled: exact for provenance=linkonce, derived from the\n")
        f.write("// overridden method for provenance=vtable-override. Class__vfunc_NN names are\n")
        f.write("// placeholders until the real method is identified.\n")
        f.write("_start = 0x00100008; // type:func // provenance=elf-entry\n")
        used = set()
        for a in sorted(syms):
            s = syms[a]
            if s["mangled"]:
                nm = s["mangled"]
            else:
                nm = f"{(s['cls'] or '').replace('::', '_')}__{s['name'].replace('~', 'dtor_')}".lstrip("_")
            if nm in used:
                nm = f"{nm}_{a:08X}"
            used.add(nm)
            attrs = [] if s["kind"] == "vtable" else ["type:func"]
            if s["size"]:
                attrs.append(f"size:0x{s['size']:X}")
            f.write(f"{nm} = 0x{a:08X}; // {' '.join(attrs)} // provenance={s['source']}\n")
        for a in sorted(nodes):
            f.write(f"{nodes[a]['mangled']} = 0x{a:08X}; // size:0x{nodes[a]['size']:X} "
                    f"// provenance=rtti-node\n")

    with open(ROOT / "symbols/source_strings.tsv", "w") as f:
        f.write("addr\tpath\n")
        for a, p in sorted(src_strings):
            f.write(f"{a:08x}\t{p}\n")

    children = defaultdict(list)
    roots = []
    for c in order:
        ps = parents.get(c, [])
        (children[ps[0]] if ps else roots).append(c)
    with open(ROOT / "notes/class_hierarchy.txt", "w") as f:
        f.write("# Class hierarchy rebuilt from RTTI (__tf) functions.\n")
        f.write("# [n] = virtual slots in the primary vtable; (+Base) = extra bases.\n\n")

        def emit(c, ind):
            n = len(vtables[c][1]) if c in vtables else 0
            extra = "".join(f" (+{b})" for b in parents.get(c, [])[1:])
            f.write(f"{'  ' * ind}{c}{f' [{n}]' if n else ''}{extra}\n")
            for ch in sorted(children[c]):
                emit(ch, ind + 1)
        for r in sorted(roots):
            emit(r, 0)

    by_src = defaultdict(int)
    for s in syms.values():
        by_src[s["source"]] += 1
    print(f"symbols: {len(syms)}  " + "  ".join(f"{k}={v}" for k, v in sorted(by_src.items())))
    print(f"classes: {len(order)}  with vtable: {len(vtables)}  roots: {len(roots)}")
    print(f"source strings: {len(src_strings)}  demangle failures: {len(failed)}")
    for m in failed[:20]:
        print("  undemangled:", m)


if __name__ == "__main__":
    main()
