#!/usr/bin/env python3
"""Class layouts from the asm: what each class's methods read and write at
which offset of `this`, as a struct to start a header from.

    tools/.venv/Scripts/python.exe tools/layouts.py                 # every class: one line each
    tools/.venv/Scripts/python.exe tools/layouts.py TskMsgMan       # one class's struct
    tools/.venv/Scripts/python.exe tools/layouts.py --write         # build/layouts/<Class>.h, all

A class's methods are the functions whose name says the class: mangled
methods (getNodeIndexByName__8DogActorPCc), placeholders that keep it
(func_00131790__8MagSceneii, TskSnd__vfunc_04), constructors (__7ObjStat...)
and destructors (_$_7ObjStat). In each, `this` is $a0 on entry and every
register a plain copy of it goes to (daddu/addu/or $x, $a0, $zero); a copy
dies when its register is written again (calls clobber $a0-$t9, $v0/$v1).
Each load or store at an offset of such a register is noted with its width,
signedness and float-ness; a store of %lo(_vt$...) marks the vtable pointer.
The scan is linear (it ignores branches), so a rare offset can be noise: the
struct lists how many accesses back each field.

Facts only from the instructions; the names (m_unkXX) are placeholders, and
a field's type is its commonest access. Base classes are not told apart:
the struct is the whole object as its methods see it.
"""
import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "build/layouts"
INSN = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$")
FUNC = re.compile(r"^\s*(?:nonmatching|glabel)\s+([^\s,]+)")
MEM = re.compile(r"^(\$\w+), (-?0x[0-9A-Fa-f]+|-?\d+|%lo\([^)]*\))\((\$\w+)\)$")
LOADS = {"lb": (1, "s"), "lbu": (1, "u"), "lh": (2, "s"), "lhu": (2, "u"), "lw": (4, "s"), "lwu": (4, "u"),
         "ld": (8, "s"), "lq": (16, "s"), "lwc1": (4, "f"), "ldc1": (8, "f")}
STORES = {"sb": 1, "sh": 2, "sw": 4, "sd": 8, "sq": 16, "swc1": 4, "sdc1": 8}
CALL_CLOBBERS = {f"${n}" for n in range(1, 16)} | {"$24", "$25", "$31"}   # $at, v0-v1, a0-a3, t0-t9, ra
TYPES = {(1, "s"): "char", (1, "u"): "unsigned char", (2, "s"): "short", (2, "u"): "unsigned short",
         (4, "s"): "int", (4, "u"): "unsigned int", (4, "f"): "float", (8, "s"): "long", (8, "f"): "double",
         (16, "s"): "u_long128", (4, "p"): "void *"}


def class_of(fn):
    """The class a function's name says it belongs to, or None."""
    m = re.match(r"^_\$_(\d+)([A-Za-z_]\w*)", fn)                 # destructor _$_7ObjStat
    if m:
        return m.group(2)[: int(m.group(1))]
    m = re.match(r"^__(\d+)([A-Za-z_]\w*)", fn)                   # constructor __7ObjStat...
    if m:
        return m.group(2)[: int(m.group(1))]
    m = re.match(r"^([A-Za-z_]\w*?)__vfunc_\d+$", fn)             # placeholder Class__vfunc_NN
    if m:
        return m.group(1)
    m = re.match(r"^[A-Za-z_]\w*?__(?:C)?(\d+)([A-Za-z_]\w*)", fn)  # method__<n>Class<args>
    if m and int(m.group(1)) <= len(m.group(2)):
        return m.group(2)[: int(m.group(1))]
    return None


REG_NAMES = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
             "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
REG_NUM = {n: f"${i}" for i, n in enumerate(REG_NAMES)} | {"s8": "$30"}


def numeric(ops):
    """Operands with named registers ($a0) as numbers ($4), as in the pieces."""
    return re.sub(r"\$([a-z][a-z0-9]?)\b", lambda m: REG_NUM.get(m.group(1), m.group(0)), ops)


def functions():
    """{name: [(addr, mnemonic, operands)]} from every whole-file asm."""
    out = {}
    for path in sorted((ROOT / "asm").rglob("*.s")):
        if "nonmatchings" in path.parts:
            continue
        fn = None
        for line in path.read_text(errors="replace").splitlines():
            m = FUNC.match(line)
            if m:
                fn = m.group(1) if not m.group(1).startswith(("D_", "jtbl_")) else None
                if fn:
                    out.setdefault(fn, [])
                continue
            i = INSN.match(line)
            if fn and i:
                out[fn].append((int(i.group(1), 16), i.group(2), numeric(i.group(3).strip())))
    return out


def dest(mn, ops):
    """The register an instruction writes, or None (stores, branches...)."""
    if mn in STORES or mn.startswith(("b", "j")) and mn not in ("jal", "jalr") or mn in ("nop", "sync", "cache"):
        return None
    first = ops.split(",")[0].strip()
    return first if first.startswith("$") and not first.startswith("$f") else None


def scan(insns):
    """[(offset, width, kind, is_store, pointer)] of the accesses through
    `this`. kind "p": a word whose value is then used as an address (the
    base of a load or store, or a jalr target) before it is overwritten."""
    this = {"$4"}
    loaded = {}                      # register -> index in out of the lw that filled it
    out = []
    for _, mn, ops in insns:
        parts = [p.strip() for p in ops.split(",")]
        if mn in ("daddu", "addu", "or", "move") and len(parts) >= 2 and parts[1] in this and \
                (len(parts) == 2 or parts[2] in ("$0", "$zero")):
            this.add(parts[0])
            loaded.pop(parts[0], None)
            continue
        m = MEM.match(ops)
        if m and (mn in LOADS or mn in STORES):
            reg, off, base = m.groups()
            if base in loaded:                          # a field's value used as an address
                o, w, k, st, _ = out[loaded[base]]
                out[loaded[base]] = (o, w, "p", st, True)
            if base in this and not off.startswith("%"):
                off = int(off, 0)
                if mn in LOADS:
                    w, k = LOADS[mn]
                    out.append((off, w, k, False, False))
                    if mn == "lw":
                        loaded[reg] = len(out) - 1
                        if reg in this:
                            this.discard(reg)
                        continue
                else:
                    out.append((off, STORES[mn], "f" if mn.endswith("c1") else "s", True, False))
        if mn == "jalr" and parts and parts[-1] in loaded:
            o, w, k, st, _ = out[loaded[parts[-1]]]
            out[loaded[parts[-1]]] = (o, w, "p", st, True)
        if mn in ("jal", "jalr"):
            this -= CALL_CLOBBERS
            for r in list(loaded):
                if r in CALL_CLOBBERS:
                    del loaded[r]
            continue
        d = dest(mn, ops)
        # p + index, p + constant: still the field's pointer for this purpose
        src = next((r for r in parts[1:3] if r in loaded), None) \
            if mn in ("addu", "daddu", "addiu", "daddiu") else None
        if d:
            this.discard(d)
            if src is not None:
                loaded[d] = loaded[src]
            else:
                loaded.pop(d, None)
    return out


def vtable_stores(insns):
    """Offsets where a %lo(_vt$...) address is stored through `this`."""
    this, vt_regs, out = {"$4"}, {}, set()
    for _, mn, ops in insns:
        parts = [p.strip() for p in ops.split(",")]
        if mn in ("daddu", "addu", "or") and len(parts) == 3 and parts[1] in this and parts[2] in ("$0", "$zero"):
            this.add(parts[0])
        if mn == "addiu" and len(parts) == 3 and "%lo(_vt$" in parts[2]:
            vt_regs[parts[0]] = True
        m = MEM.match(ops)
        if m and mn == "sw" and m.group(1) in vt_regs and m.group(3) in this and not m.group(2).startswith("%"):
            out.add(int(m.group(2), 0))
    return out


def layouts(funcs=None):
    """{class: {"methods": n, "fields": {off: Counter((w, kind))}, "stores": Counter(off), "vtable": set}}"""
    funcs = funcs or functions()
    out = {}
    for fn, insns in funcs.items():
        c = class_of(fn)
        if not c:
            continue
        L = out.setdefault(c, {"methods": 0, "fields": collections.defaultdict(collections.Counter),
                               "stores": collections.Counter(), "vtable": set()})
        L["methods"] += 1
        for off, w, k, st, _ in scan(insns):
            L["fields"][off][(w, k)] += 1
            if st:
                L["stores"][off] += 1
        L["vtable"] |= vtable_stores(insns)
    return out


def struct_text(name, L):
    lines = [f"// {name}: from {L['methods']} methods' accesses to `this` (tools/layouts.py).",
             f"struct {name} {{"]
    at = 0
    fields = L["fields"]
    for off in sorted(o for o in fields if o >= 0):
        if off < at:
            continue                                   # overlaps the field before: a union or noise
        kinds = fields[off]
        if kinds.get((4, "p")):                        # used as an address even once: a pointer
            (w, k), n = (4, "p"), sum(kinds.values())
        else:
            (w, k), n = kinds.most_common(1)[0]
        if off % min(w, 8):
            w, k = 1, "u"                              # misaligned for its width: bytes
        if off > at:
            lines.append(f"    unsigned char m_pad{at:X}[0x{off - at:X}];")
        if off in L["vtable"]:
            lines.append(f"    void *m_vtable;                     // +0x{off:X}, set to _vt$...")
        else:
            other = ", ".join(f"{TYPES.get(x, '?')} x{c}" for x, c in kinds.most_common()[1:3])
            lines.append(f"    {TYPES.get((w, k), 'int')} m_unk{off:X};".ljust(40)
                         + f"// +0x{off:X}, {n} access{'es' if n != 1 else ''}" + (f" (also {other})" if other else ""))
        at = off + w
    lines.append(f"}};  // at least 0x{at:X} bytes")
    return "\n".join(lines)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("classes", nargs="*")
    ap.add_argument("--write", action="store_true", help="build/layouts/<Class>.h for every class")
    a = ap.parse_args()
    L = layouts()
    if a.classes:
        for c in a.classes:
            print(struct_text(c, L[c]) if c in L else f"{c}: no methods found")
        return
    if a.write:
        OUT.mkdir(parents=True, exist_ok=True)
        for c, lay in L.items():
            (OUT / f"{c}.h").write_text(struct_text(c, lay) + "\n")
        print(f"{len(L)} classes written to {OUT.relative_to(ROOT)}")
        return
    rows = sorted(L.items(), key=lambda kv: -sum(sum(v.values()) for v in kv[1]["fields"].values()))
    for c, lay in rows:
        acc = sum(sum(v.values()) for v in lay["fields"].values())
        size = max((o + max(w for w, _ in v) for o, v in lay["fields"].items() if o >= 0), default=0)
        print(f"{c:28} {lay['methods']:4} methods {len(lay['fields']):5} offsets {acc:6} accesses  >= 0x{size:X} bytes")
    print(f"{len(L)} classes")


if __name__ == "__main__":
    main()
