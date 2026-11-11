#!/usr/bin/env python3
"""Turn m2c's drafts into C++ mechanically and keep only what matches.

    tools/.venv/bin/python tools/match.py --server start     # once: fast compiles
    tools/.venv/bin/python tools/auto_m2c.py                 # every game file
    tools/.venv/bin/python tools/auto_m2c.py unk/GotMain -j1 # some files
    tools/.venv/bin/python tools/auto_m2c.py --report        # why the rest failed
    tools/.venv/bin/python tools/auto_m2c.py --apply         # results into src/

For each INCLUDE_ASM left in a file, each strategy (see STRATEGIES) rewrites
m2c's draft of the function into C++ that knows nothing about the game's
types: pointers are ints, fields are loads at an offset, callees are
declared from their mangled name when they have one. The file is compiled
with every candidate at once (tools/match.py, in a scratch copy under
build/auto/) and the ones that do not come out byte for byte are dropped,
until what is left matches as a whole object. Nothing is written to src/
without --apply, and --apply still needs the full build (tools/dock ninja)
before a commit: this only checks objects.

The output is a placeholder for real decompilation, not a substitute: it
pins the code down (the build no longer needs the asm) and shows the
control flow, to be rewritten with real classes later.

Every attempt is logged to build/auto/log.jsonl (file, function, size,
strategy, status, detail). --report groups what did not match: by reason,
and by "family" (functions whose drafts are equal but for numbers and
names), which is where one new rewrite rule pays off many times.

A file without a .cpp needs its skeleton and asm/nonmatchings first:
--prepare makes them for every such file in one splat run (through
tools/dock) and keeps the skeletons in build/auto/skel/, out of src/.
"""
import argparse
import collections
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
import threading
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402
import match  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
WORK = ROOT / "build/auto"
LOG = WORK / "log.jsonl"
GAME_END = 0x00280E88  # first address after the game's own code (SDK and middleware follow)
HEADER = "// Translated mechanically from m2c drafts: only what matches byte for byte.\n"
FIELD_MACRO = "#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))\n"
FUNC_RE = re.compile(r"^(\S[^\n]*\b\w+\([^\n]*\) \{)\n(.*?)^\}\n", re.S | re.M)
KEYWORDS = {"if", "for", "while", "switch", "return", "sizeof", "do", "else", "case",
            "int", "char", "unsigned", "short", "signed", "long", "float", "M2C_FIELD", "M2C_ULONG"}
U128 = "typedef unsigned int u_long128 __attribute__((mode(TI)));"  # as in ror.h
ULONG = ("struct m2c_ulong { long v; } __attribute__((packed));\n"
         "#define M2C_ULONG(expr, offset) (((m2c_ulong *)((char *)(expr) + (offset)))->v)")
CTYPE = {"s128": "u_long128", "u128": "u_long128", "s32": "int", "u32": "unsigned int", "s16": "short", "u16": "unsigned short",
         "s8": "signed char", "u8": "unsigned char", "f32": "float",
         "s64": "long", "u64": "unsigned long"}
log_lock = threading.Lock()


class Reject(Exception):
    """The translator does not handle this draft; the message is the reason."""


# ---------------------------------------------------------------- inputs

def game_files():
    rows = configure.load_splits()
    return [r[4] for r in rows if r[0] < GAME_END and not r[4].startswith(("sdk", "sce", "mw/"))
            and (ROOT / f"asm/{r[4]}.s").exists()]


def flat(name):
    return name.replace("/", "_")


UNALIGNED = re.compile(r"^(\s+/\*[^*]*\*/\s+)(l|s)dl(\s+)(\$\w+), (-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)$")


def join_unaligned(text):
    """ldl/ldr and sdl/sdr pairs (a 64-bit access to memory that may not be
    aligned: struct copies) as ld and sd, which m2c knows; the second
    instruction of each pair becomes a nop."""
    lines = text.split("\n")
    for i, line in enumerate(lines[:-1]):
        m = UNALIGNED.match(line)
        if not m:
            continue
        pre, ls, gap, reg, off, base = m.groups()
        low = int(off, 0) - 7
        n = re.match(r"^(\s+/\*[^*]*\*/\s+)" + ls + r"dr\s+" + re.escape(reg) + r", (?:(-?0x[0-9A-Fa-f]+|-?\d+))?\("
                     + re.escape(base) + r"\)$", lines[i + 1])
        if n and int(n.group(2) or "0", 0) == low:
            lines[i] = f"{pre}{ls}d{gap} {reg}, {'-' if low < 0 else ''}{abs(low):#x}({base})"
            lines[i + 1] = n.group(1) + "nop"
    return "\n".join(lines)


N32 = {"t0": "a4", "t1": "a5", "t2": "a6", "t3": "a7", "t4": "t0", "t5": "t1", "t6": "t2", "t7": "t3"}


def m2c(name, key, flags, context=None, force=False):
    """m2c's output for a whole file, cached by the dates of the asm and of
    the context (prototypes) it was given."""
    asm = ROOT / f"asm/{name}.s"
    out = WORK / "m2c" / f"{flat(name)}.{key}.c"
    if context:
        flags = [*flags, "--context", str(context)]
    if (force or not out.exists() or out.stat().st_mtime < asm.stat().st_mtime
            or (context and out.stat().st_mtime < context.stat().st_mtime)):
        out.parent.mkdir(parents=True, exist_ok=True)
        if "mipsee-gcc-c" in flags:
            # splat names registers 8-15 $t0-$t7; m2c's EE target calls them
            # $a4-$a7 (the fifth to eighth arguments) and $t0-$t3.
            n32 = WORK / "m2c" / f"{flat(name)}.s"
            text = re.sub(r"\$(t[0-7])\b", lambda m: "$" + N32[m.group(1)],
                          asm.read_text(encoding="utf8", errors="replace"))
            n32.write_text(join_unaligned(text), encoding="utf8")
            asm = n32
        r = subprocess.run([sys.executable, "-m", "m2c.main", *flags, str(asm)],
                           capture_output=True, text=True, encoding="utf8", errors="replace")
        out.write_text(r.stdout, encoding="utf8")
    return out.read_text(encoding="utf8")


SAVED = re.compile(r"\$(s[0-7]|fp|ra|gp|f2[0-9]|f3[01]), (0x[0-9A-Fa-f]+|\d+)\(\$sp\)")


def asm_functions(name):
    """{function: (size, ends in a jump to another function, where its
    locals end, has unaligned 64-bit accesses)} from splat's disassembly
    of the whole file. The locals of
    a frame lie below the registers the prologue saves (or fill the frame,
    if it saves none); None when the function has no frame."""
    out, fn = {}, None
    for line in (ROOT / f"asm/{name}.s").read_text(errors="replace").splitlines():
        m = re.match(r"nonmatching (\S+), (0x[0-9A-Fa-f]+)", line)
        if m:
            fn, size = m.group(1), int(m.group(2), 16)
            prologue, frame = True, None
            continue
        m = re.match(r"\s+/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(\S+)\s*(.*)", line)
        if not m or not fn:
            continue
        op, args = m.groups()
        if op.startswith("."):
            fn = None  # data
            continue
        if fn not in out:
            out[fn] = [size, False, None, False]
        if op in ("ldl", "sdl"):
            out[fn][3] = True
        if op == "j" and re.match(r"[A-Za-z_]", args):
            out[fn][1] = True
        if prologue:
            g = re.match(r"\$sp, \$sp, -(0x[0-9A-Fa-f]+|\d+)", args)
            if op == "addiu" and g and frame is None:
                frame = int(g.group(1), 0)
                out[fn][2] = frame
            g = SAVED.match(args)
            if g and frame is not None and op in ("sd", "sq", "swc1", "sdc1"):
                out[fn][2] = min(out[fn][2], int(g.group(2), 0))
            if op[0] in "jb" and op not in ("break",):
                prologue = False
    return {k: tuple(v) for k, v in out.items()}


def string_labels(name):
    """{text: D_ label} of the file's strings that splat put in files of
    their own (shared with asm functions, so they stay INCLUDE_RODATA)."""
    d = {}
    base = ROOT / f"asm/nonmatchings/{name}"
    if base.is_dir():
        for f in base.glob("D_*.s"):
            m = re.search(r'dlabel (D_\w+)\n\s*/\*.*?\*/ \.asciz "(.*?)"', f.read_text(errors="replace"))
            if m:
                d[m.group(2)] = m.group(1)
    return d


# ------------------------------------------------- g++ 2.x mangled names

BUILTIN = {"v": "void", "c": "char", "s": "short", "i": "int", "l": "long", "x": "long long",
           "f": "float", "d": "double", "b": "bool", "w": "int", "r": "long double"}


def demangle_params(sym):
    """The parameter types of a g++ 2.x mangled function name as C types we
    can declare it with ("this" included for a method), or None. Pointers
    and references are "int" (the same register, and our values are ints);
    a type passed by value under its own name is taken for an enum."""
    m = re.match(r"^(?:_GLOBAL_\.[ID]\.)?(.+?)__(?=[0-9FCQt])(.*)$", sym)
    if not m or sym.startswith("__"):
        return None
    s = m.group(2)
    pos = 0
    types = []

    def named():
        nonlocal pos
        mm = re.match(r"\d+", s[pos:])
        if not mm:
            raise ValueError
        n = int(mm.group(0))
        pos += len(mm.group(0)) + n
        if pos > len(s):
            raise ValueError

    def one():
        """Parse one type; return its C spelling."""
        nonlocal pos
        ptr = False
        sign = ""
        while pos < len(s) and s[pos] in "PRCVUS":
            if s[pos] in "PR":
                ptr = True
            elif s[pos] == "U":
                sign = "unsigned "
            elif s[pos] == "S":
                sign = "signed "
            pos += 1
        if pos >= len(s):
            raise ValueError
        c = s[pos]
        if c in BUILTIN:
            pos += 1
            t = BUILTIN[c]
            if t in ("double", "long double") and not ptr:
                raise ValueError
            return "int" if ptr else (sign + t if t not in ("float", "bool", "void") else t)
        if c.isdigit():
            named()
            return "int"
        if c == "Q":
            pos += 1
            n = int(s[pos])
            pos += 1
            for _ in range(n):
                named()
            return "int"
        if c == "F":  # function type: only behind a pointer
            pos += 1
            while s[pos] != "_":
                one()
            pos += 1
            one()
            if not ptr:
                raise ValueError
            return "int"
        if c == "A":
            mm = re.match(r"A(\d+)_", s[pos:])
            pos += len(mm.group(0))
            one()
            if not ptr:
                raise ValueError
            return "int"
        raise ValueError

    try:
        if s[pos] == "F":
            pos += 1
        else:
            if s[pos] == "C":
                pos += 1
            one()  # the class
            types.append("int")  # this
        while pos < len(s):
            c = s[pos]
            if c == "e":
                return None  # variadic: declare it that way
            if c == "T":
                mm = re.match(r"T(\d)", s[pos:])
                pos += 2
                types.append(types[int(mm.group(1))])
            elif c == "N":
                mm = re.match(r"N(\d)(\d)", s[pos:])
                pos += 3
                types.extend([types[int(mm.group(2))]] * int(mm.group(1)))
            else:
                types.append(one())
    except (ValueError, IndexError, AttributeError):
        return None
    return [t for t in types if t != "void"]


SIG_LETTER = {"int": "i", "unsigned int": "u", "float": "f", "char": "c", "unsigned char": "h",
              "signed char": "a", "short": "s", "unsigned short": "t", "long": "l",
              "unsigned long": "m", "long long": "x", "unsigned long long": "y", "bool": "b"}


# ------------------------------------------------------- signatures
# m2c only shows the arguments a call sets: one that passes its own first
# parameter along (`this`, in most methods) comes out without it. Given the
# callee's prototype it writes the whole call, so we work out a prototype
# for every function of the game and hand m2c all of them as its context:
#   - parameter types from the mangled name, where there is one;
#   - else as many parameters as the function's own draft reads, grown when
#     a draft made with the context reads $a0 without it being set (it
#     passes `this` along and nothing in it reads it). Only $a0: growing on
#     the other registers spreads one wrong guess to every caller.

EE_FLAGS = ["-t", "mipsee-gcc-c", "--valid-syntax"]
SIGS = WORK / "sigs.json"
CONTEXT = WORK / "context.c"
TYPEDEFS = ("typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;\n"
            "typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;\n"
            "typedef float f32; typedef double f64;\n")
M2C_OF = {v: k for k, v in {"s32": "int", "u32": "unsigned int", "s16": "short", "u16": "unsigned short",
                            "s8": "char", "u8": "unsigned char", "f32": "float", "s64": "long long",
                            "u64": "unsigned long long"}.items()}
M2C_OF.update({"signed char": "s8", "long": "s64", "unsigned long": "u64", "bool": "u8"})
# (return type, parameters) of what the game calls from the C library, the
# C++ runtime and the compiler's own double arithmetic.
LIB = {
    "memset": ("void *", ["void *", "s32", "s32"]), "memcpy": ("void *", ["void *", "void *", "s32"]),
    "memmove": ("void *", ["void *", "void *", "s32"]), "memcmp": ("s32", ["void *", "void *", "s32"]),
    "strlen": ("s32", ["void *"]), "strcpy": ("void *", ["void *", "void *"]),
    "strncpy": ("void *", ["void *", "void *", "s32"]), "strcmp": ("s32", ["void *", "void *"]),
    "strncmp": ("s32", ["void *", "void *", "s32"]), "strcasecmp": ("s32", ["void *", "void *"]),
    "strstr": ("void *", ["void *", "void *"]), "strchr": ("void *", ["void *", "s32"]),
    "strrchr": ("void *", ["void *", "s32"]), "strcat": ("void *", ["void *", "void *"]),
    "atoi": ("s32", ["void *"]), "rand": ("s32", []),
    "sinf": ("f32", ["f32"]), "cosf": ("f32", ["f32"]), "sqrtf": ("f32", ["f32"]), "fabsf": ("f32", ["f32"]),
    "__builtin_new": ("void *", ["s32"]), "__builtin_vec_new": ("void *", ["s32"]),
    "__builtin_delete": ("void", ["void *"]), "__builtin_vec_delete": ("void", ["void *"]),
    "ror_assert": ("void", ["void *", "s32", "void *"]),
}


def ctx_type(t):
    """One of m2c's types as something its context parser takes."""
    t = t.strip()
    base = t.replace("*", "").replace("const", "").strip()
    if "*" in t:
        return ("void" if base not in CTYPE and base != "f64" or "128" in base else base) + " " + "*" * t.count("*")
    return t if (t in CTYPE or t in ("void", "f64")) and "128" not in t else "s32"


def definitions(draft):
    """({function: (return type, {int register: type}, float registers
    used, registers it reads that nothing set)}, {functions called for a
    result the draft could not find}) from a draft."""
    out, returns = {}, set()
    for hdr, body in FUNC_RE.findall(draft):
        m = re.match(r"^(.*?)\b(\w+)\((.*)\) \{$", hdr)
        ints, floats = {}, 0
        ok = True
        for q in split_args(m.group(3)):
            g = re.match(r"^(.*?)\b(fp)?arg(\d+)$", q)
            if q.strip() == "void":
                continue
            if not g or "s128" in q:
                ok = False
            elif g.group(2):
                floats = max(floats, int(g.group(3)) + 1)
            else:
                ints[int(g.group(3))] = ctx_type(g.group(1))
        unset = set(re.findall(r"Read from unset register \$(a0)", body))
        # a call whose result is read, to a function the context calls void
        last = None
        for line in body.split("\n"):
            if "Read from unset register $v0" in line and last:
                returns.add(last)
            g = re.match(r"^\s*(\w+)\(.*\);$", line)
            if g:
                last = g.group(1)
        if ok:
            out[m.group(2)] = (m.group(1).strip(), ints, floats, unset)
    return out, returns


def write_context(sigs):
    lines = [TYPEDEFS]
    for name, (ret, ints, floats) in sorted(sigs.items()):
        if re.fullmatch(r"[A-Za-z_]\w*", name):
            lines.append(f"{ret} {name}({', '.join(ints + ['f32'] * floats) or 'void'});\n")
    text = "".join(lines)
    if not CONTEXT.exists() or CONTEXT.read_text(encoding="utf8") != text:
        CONTEXT.write_text(text, encoding="utf8", newline="\n")


def signatures(jobs, rebuild=False):
    """{function: [return type, [int parameter types], float parameters]}
    for the whole game, in m2c's types; made once and kept in
    build/auto/sigs.json with the context file for m2c beside it."""
    if SIGS.exists() and CONTEXT.exists() and not rebuild:
        return json.loads(SIGS.read_text(encoding="utf8"))
    names = game_files()
    sigs, frozen = {}, set()
    for name, (ret, params) in LIB.items():
        sigs[name] = [ret, [q for q in params if q != "f32"], params.count("f32")]
        frozen.add(name)

    def merge(found):
        defs, returns = found
        changed = 0
        for fn in returns:
            if fn in sigs and sigs[fn][0] == "void" and fn not in LIB:
                sigs[fn][0] = "s32"
                changed += 1
        for fn, (ret, ints, floats, unset) in defs.items():
            need_i = max([max(ints) + 1 if ints else 0] + [int(r[1]) + 1 for r in unset if r[0] == "a"])
            need_f = max([floats] + [int(r[1:]) - 11 for r in unset if r[0] == "f"])
            if fn not in sigs:
                dm = demangle_params(fn)
                if dm is not None and all(t in M2C_OF or t == "int" for t in dm):
                    sigs[fn] = [ctx_type(ret), [M2C_OF.get(t, "s32") for t in dm if t != "float"],
                                dm.count("float")]
                    frozen.add(fn)
                else:
                    sigs[fn] = [ctx_type(ret), [], 0]
                changed += 1
            if fn in frozen:
                continue
            cur = sigs[fn]
            types = [ints.get(i, cur[1][i] if i < len(cur[1]) else "s32") for i in range(max(need_i, len(cur[1])))]
            if types != cur[1] and len(types) > len(cur[1]) or need_f > cur[2]:
                changed += 1
            cur[1], cur[2] = types, max(cur[2], need_f)
        return changed

    with ThreadPoolExecutor(jobs) as ex:
        for it in range(5):
            if it:
                write_context(sigs)
                m2c(names[0], "sig", EE_FLAGS, CONTEXT, force=True)  # one alone: it caches the parsed context
            drafts = list(ex.map(lambda n: m2c(n, "sig", EE_FLAGS, CONTEXT if it else None, force=True), names))
            changed = sum(merge(definitions(d)) for d in drafts)
            print(f"signatures, pass {it}: {changed} changed", flush=True)
            if not changed:
                break
    write_context(sigs)
    SIGS.write_text(json.dumps(sigs, indent=0, sort_keys=True), encoding="utf8")
    return sigs


# ----------------------------------------------------- text helpers

def close_paren(s, i):
    """Index of the bracket that closes the one at s[i]."""
    op = s[i]
    cl = {"(": ")", "[": "]"}[op]
    n = 0
    for k in range(i, len(s)):
        if s[k] == op:
            n += 1
        elif s[k] == cl:
            n -= 1
            if n == 0:
                return k
    raise Reject("unbalanced")


def split_args(s):
    """Top-level comma split."""
    out, depth, cur = [], 0, ""
    for c in s:
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= 1
        if c == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += c
    if cur.strip():
        out.append(cur.strip())
    return out


def operand_start(s, i):
    """Start of the operand that ends just before s[i]."""
    j = i
    while True:
        if s[j - 1] in ")]":
            op, cl = ("(", ")") if s[j - 1] == ")" else ("[", "]")
            k, n = j - 1, 0
            while True:
                if s[k] == cl:
                    n += 1
                elif s[k] == op:
                    n -= 1
                    if n == 0:
                        break
                k -= 1
            j = k
            while j > 0 and (s[j - 1].isalnum() or s[j - 1] == "_"):
                j -= 1
            if s[j - 1] in ")]":
                continue
            return j
        k = j
        while k > 0 and (s[k - 1].isalnum() or s[k - 1] == "_"):
            k -= 1
        return k


VALUE_CAST = re.compile("[(](?:unsigned |signed )?(?:int|char|short|long|float)[)]$")
CAST = re.compile("[(](?:unsigned |signed )?(?:int|char|short|long|float|u_long128) [*][)]")


def deref(s, ptype):
    """`*p` for the pointers we turned into ints."""
    out, i = [], 0
    while i < len(s):
        c = s[i]
        if c == "*":
            k = i - 1
            while k >= 0 and s[k] == " ":
                k -= 1
            prev = s[k] if k >= 0 else ""
            after_cast = prev == ")" and VALUE_CAST.search(s[:k + 1])  # `(int) *p` is no product
            if (after_cast or not (prev.isalnum() or prev in "_)]")) and s[i + 1:i + 2] != "=":
                m = re.match(r"\*([A-Za-z_]\w*)", s[i:])
                if m:
                    ty = ptype.get(m.group(1), "int")
                    out.append(f"(*({ty} *)({m.group(1)}))")
                    i += len(m.group(0))
                    continue
                if s[i + 1] == "(" and not CAST.match(s, i + 1):  # not one we already typed
                    out.append("*(int *)")
                    i += 1
                    continue
        out.append(c)
        i += 1
    return "".join(out)


# The two-case flag chain of the enemy files: m2c nests what the source
# wrote as `if (a == X && p == 0) f = 1; else if (a == Y && q == 0) f = 1;
# else f = 0;`, and only that shape compiles back to the same branches.
FLAG_CHAIN = re.compile(r"""(?P<i> +)(?:(?P<r>\w+) = 0;\n(?P=i))?if \(\((?P<t>\w+) != (?P<a>\w+)\) \|\| \((?P<v>\w+) = 1, \((?P<x>.+?) != 0\)\)\) \{
(?P=i)    (?P=v) = 0;
(?P=i)    if \((?P=t) == (?P<b>\w+)\) \{
(?P=i)        (?P=v) = 1;
(?P=i)        if \((?P<y>.+?) != 0\) \{
(?P=i)            (?P=v) = 0;
(?P=i)        \}
(?P=i)    \}
(?P=i)\}
(?P=i)if \((?P=v) == 0\) \{
""")


def flag_chain(body):
    fix = []

    def r(m):
        d = m.groupdict()
        i, t, a, v, x, b2, y, rr = d["i"], d["t"], d["a"], d["v"], d["x"], d["b"], d["y"], d["r"]
        o = (f"{i}if ({t} == {a} && {x} == 0) {v} = 1;\n{i}else if ({t} == {b2} && {y} == 0) {v} = 1;\n"
             f"{i}else {v} = 0;\n")
        if rr and i == "    " and body.rstrip().endswith("    }\n    return " + rr + ";"):
            fix.extend([rr, v, t])
            o += i + "if (" + v + " != 0) return 0;\n    {\n"
        else:
            o += (f"{i}{rr} = 0;\n" if rr else "") + f"{i}if ({v} == 0) {{\n"
        return o + f"@@{v},{t}@@"

    body = FLAG_CHAIN.sub(r, body)
    if len(fix) == 3:
        e = "    }\n    return " + fix[0] + ";"
        body = body.rstrip()[:-len(e)] + "        return " + fix[0] + ";\n    }\n"
        # the flag must be declared before the value it tests
        dv, dt = "    s32 " + fix[1] + ";\n", "    s32 " + fix[2] + ";\n"
        if dv in body and dt in body:
            body = body.replace(dv, "", 1).replace(dt, dv + dt, 1)
        body = re.sub(r"\{\n@@(\w+,\w+)@@        " + fix[0] + r" = ([^\n]+);\n        return " + fix[0] + ";\n",
                      r"{\n@@\1@@        return \2;\n", body)
    while True:
        m = re.search(r"@@(\w+),(\w+)@@", body)
        if not m:
            break
        v, t = m.groups()
        body = body[:m.start()] + re.sub(r", " + v + r", " + t + r"(, \w+)?\)", ")", body[m.end():])
    return body


# `if (a || b) return X; return Y;` comes back from m2c as two nested ifs and
# a goto, which compile to a plain branch where the game has a likely one.
OR_RETURN = re.compile(r"""^( +)if \((.+)\) \{
\1    if \((.+)\) \{
\1        return (.+);
\1    \}
\1    goto (block_\d+);
\1\}
\5:
\1return (.+);""", re.M)


# The three-case flag chain (DwfMain and the like): two cases as in
# FLAG_CHAIN and a third with a body of its own.
FLAG_CHAIN3 = re.compile(r"""^    if \((?P<t>\w+) == (?P<a>\w+)\) \{
        (?P<v>\w+) = 1;
        if \((?P<x>.+) != 0\) \{
            goto (?P<p>block_\d+);
        \}
    \} else \{
(?P=p):
        if \((?P=t) == (?P<b>\w+)\) \{
            (?P=v) = 1;
            if \((?P<y>.+) != 0\) \{
                goto (?P<q>block_\d+);
            \}
        \} else \{
(?P=q):
            (?P=v) = 0;
            if \((?P=t) == (?P<c>\w+)\) \{
(?P<body>(?:                .*\n)+)            \}
        \}
    \}
(?P<tail>    if \((?P=v) == 0\) \{
        return (?P<e>.+);
    \}
    return 0;
)?""", re.M)


def flag_chain3(body):
    def r(m):
        d = m.groupdict()
        inner = "".join(ln[8:] + "\n" for ln in d["body"].rstrip("\n").split("\n"))
        out = (f"    if ({d['t']} == {d['a']} && {d['x']} == 0) {d['v']} = 1;\n"
               f"    else if ({d['t']} == {d['b']} && {d['y']} == 0) {d['v']} = 1;\n"
               f"    else if ({d['t']} == {d['c']}) {{\n        {d['v']} = 0;\n{inner}    }} else {d['v']} = 0;\n")
        if d["tail"]:
            out += f"    if ({d['v']}) return 0;\n    return {d['e']};\n"
        return out
    return FLAG_CHAIN3.sub(r, body)


class Candidate:
    def __init__(self, text, pre):
        self.text = text  # the function
        self.pre = pre    # declarations it needs before it, one per line


# --------------------------------------------------- strategy "plain"
# m2c's default output (fields as ->unkNN), everything an int. No floats,
# no stack variables, no calls through pointers.

PLAIN_T = {k: v for k, v in CTYPE.items() if k not in ("f32", "s64", "u64")}
PLAIN_BAD = re.compile(r"M2C_ERROR|\bf32\b|\bf64\b|\d\.\d|\bsp\b|\bsp\d|\bsp[0-9A-F]+\b|subroutine_arg|\$|\.unk"
                       r"|\bs64\b|\bu64\b|s128|bitwise|unaligned|saved_reg|__builtin|\bnanf?\b|_struct"
                       r"|\bunksp|->unk\w+\(|\\0|\[\]|\(\*\)")


def plain_fields(s):
    while True:
        m = re.search(r"->unk([0-9A-F]+)\b", s)
        if not m:
            return s
        st = operand_start(s, m.start())
        base = s[st:m.start()]
        ty = "int"
        pre = re.search(r"\((s32|u32|s16|u16|s8|u8)\) *$", s[:st])
        if pre:
            ty = PLAIN_T[pre.group(1)]
        s = s[:st] + f"(*({ty} *)((char *)({base}) + 0x{m.group(1)}))" + s[m.end():]


def plain(ctx, fn, hdr, body):
    body = flag_chain(body)
    m = re.match(r"^(.*?)\b(\w+)\((.*)\) \{$", hdr)
    ret, params = m.group(1).strip(), m.group(3).strip()
    bad = PLAIN_BAD.search(hdr + "\n" + body)
    if bad:
        raise Reject(re.sub(r"(?<!M)\d", "N", bad.group(0))[:12])
    body = re.sub(r"/\*.*?\*/", "", body)
    ptype, ps, pre = {}, {}, set()
    if params and params != "void":
        for p in params.split(","):
            p = p.strip()
            g = re.match(r"^(.*?)\s*\*?\s*(arg(\d+))$", p)
            if not g:
                raise Reject("param")
            ps[int(g.group(3))] = g.group(2)
            pm = re.match(r"^(s32|u32|s16|u16|s8|u8) \*", p)
            if pm:
                ptype[g.group(2)] = PLAIN_T[pm.group(1)]
    plist = ", ".join(f"int arg{i}" for i in range(max(ps) + 1 if ps else 0))
    decl, lines = [], []
    for line in body.split("\n"):
        g = re.match(r"^    (s32|u32|s16|u16|s8|u8|void|\?)( \*+)? *(\w+);$", line)
        if g:
            ty, pt, v = g.groups()
            if pt:
                if ty in PLAIN_T:
                    ptype[v] = PLAIN_T[ty]
                decl.append(f"    int {v};")
            else:
                decl.append(f"    {PLAIN_T.get(ty, 'int')} {v};")
            continue
        if re.match(r"^    \w[\w ]*\*+ *\w+;$", line):
            raise Reject("local type")
        lines.append(line)
    b = "\n".join(lines)
    b = re.sub(r"\((?:void|\?|s32|u32|s16|u16|s8|u8) \*+\) ?", "(int) ", b)
    b = plain_fields(b)
    if "->" in b or re.search(r"\b(\w+)\[", b) and not all(x in ptype for x in re.findall(r"\b([a-z_]\w*)\[", b)):
        raise Reject("index")
    for v, ty in ptype.items():
        b = re.sub(r"\b" + v + r"\[", f"(({ty} *)({v}))[", b)
    b = deref(b, ptype)
    for k, v in PLAIN_T.items():
        b = re.sub(r"\(" + k + r"\)", "(" + v + ")", b)
    b = re.sub(r"\bNULL\b", "0", b)

    def string(mm):
        if mm.group(1) in ctx.labels:
            pre.add(f"extern const char {ctx.labels[mm.group(1)]}[];")
            return ctx.labels[mm.group(1)]
        return mm.group(0)

    b = re.sub(r'"((?:[^"\\]|\\.)*)"', string, b)
    strings = set(ctx.labels.values())
    for g in set(re.findall(r"\bD_[0-9A-F]+\b|\bjtbl_\w+", b)):
        if g in strings:
            continue
        if re.search(r"\b" + g + r"\s*[\[.]", b):
            raise Reject("global index")
        pre.add(f"extern int {g};")
    b = re.sub(r"&(D_[0-9A-F]+)", r"(int)&\1", b)
    for g in strings:
        b = re.sub(r"\(int\)&" + g + r"\b", g, b)
    for c in set(re.findall(r"\b([A-Za-z_]\w*)\(", b)):
        if c in KEYWORDS:
            continue
        pre.add(f'extern "C" int X_{c}(...) asm("{c}");')
        b = re.sub(r"\b" + c + r"\(", "X_" + c + "(", b)
    rt = "void" if ret == "void" else "int"
    if ctx.funcs.get(fn, (0, False))[1]:
        rt = "int"
        b = tail_call(b)
    text = f'extern "C" {rt} {fn}({plist})\n{{\n' + "\n".join(decl) + ("\n" if decl else "") + b + "}\n"
    return Candidate(text, pre)


def tail_call(b):
    """A function that ends in a jump returns what the callee returns."""
    b = re.sub(r"^( +)(X\w*_\w+\(.*\);)\n +return;$", r"\1return \2", b, flags=re.M)
    b = re.sub(r"^( +)(X\w*_\w+\(.*\);)\n$", r"\1return \2\n", b, flags=re.M)
    ls = b.rstrip().split("\n")
    if ls and re.match(r"^ +X\w*_\w+\(.*\);$", ls[-1]):
        ls[-1] = re.sub(r"^( +)", r"\1return ", ls[-1])
        b = "\n".join(ls) + "\n"
    return b


# --------------------------------------------------- strategy "typed"
# m2c --valid-syntax for the EE: every field access says its type
# (M2C_FIELD), so floats and narrow stores come out right; callees and the
# function itself take their parameter types from the mangled name.

TYPED_BAD = re.compile(r"M2C_(?!FIELD\b|UNK\b)\w+|\bf64\b|saved_reg|\bnanf?\b"
                       r"|subroutine_arg|unksp|\\0")
FLOAT = re.compile(r"(?<![\w.])(\d+\.\d+(?:e[-+]?\d+)?)f\b")


def float_literal(mm):
    """A float constant that this compiler turns into the same bits. It
    cuts decimals off instead of rounding them (0.1f is 0x3DCCCCCC in the
    game), and m2c prints the shortest decimal that rounds to the bits,
    which can then come out one lower: so unless the text is exact, write
    a value a quarter of a step above the float."""
    v = float(mm.group(1))
    bits = struct.unpack("<I", struct.pack("<f", v))[0]
    f = struct.unpack("<f", struct.pack("<I", bits))[0]
    if f == v:
        return mm.group(0)
    up = struct.unpack("<f", struct.pack("<I", bits + 1))[0]
    return repr(f + (up - f) / 4) + "f"


SIZEOF = {"u_long128": 16, "int": 4, "unsigned int": 4, "short": 2, "unsigned short": 2, "signed char": 1,
          "unsigned char": 1, "float": 4, "long": 8, "unsigned long": 8}


def ctype(t):
    """(C type we use, pointee C type or None) for one of m2c's types."""
    t = t.strip()
    if "(" in t:
        raise Reject("fnptr")
    if "*" in t:
        base = t.replace("*", "").replace("const", "").strip()
        return "int", (CTYPE.get(base) if t.count("*") == 1 else "int")
    if t in CTYPE:
        return CTYPE[t], None
    if t in ("?", "M2C_UNK", "void", ""):
        return "int", None
    raise Reject("type " + re.sub(r"\d", "N", t)[:12])


def fn_type(t):
    """`RET (*)(PARAMS)` in our types for one of m2c's function pointer
    types, or None if it is not one."""
    m = re.match(r"^(.*?)\(\*\w*\)\((.*)\)$", t.strip())
    if not m:
        return None
    ret = m.group(1).strip()
    rt = "void" if ret == "void" else "float" if ret == "f32" else "int"
    params = [ctype(re.sub(r"\b(arg|fparg)\d+$", "", q))[0] for q in split_args(m.group(2))
              if q.strip() != "void"]
    return f"{rt} (*)({', '.join(params)})"


def typed_fields(b, calls, unaligned=False):
    """M2C_FIELD(p, T *, off) with T as a C type, inner accesses first. A
    field that is a pointer to a function is cast to it: the cast goes to
    `calls` and a mark @F<n>@ stands for it until the text is done."""
    out, i = [], 0
    while True:
        k = b.find("M2C_FIELD(", i)
        if k < 0:
            return "".join(out) + b[i:]
        e = close_paren(b, k + 9)
        args = split_args(b[k + 10:e])
        if len(args) != 3:
            raise Reject("field")
        inner = f"{typed_fields(args[0], calls, unaligned)}"
        ft = fn_type(args[1].replace("(**", "(*", 1)) if "(**" in args[1] else None
        before = b[i:k]
        if ft:
            calls.append(f"(({ft})M2C_FIELD({inner}, int *, {args[2]}))")
            out.append(before + f"@F{len(calls) - 1}@")
        else:
            if not args[1].endswith("*"):
                raise Reject("field")
            fty, pointee = ctype(args[1][:-1])
            field = f"M2C_FIELD({inner}, {fty} *, {typed_fields(args[2], calls, unaligned)})"
            if unaligned and fty in ("long", "unsigned long"):
                field = f"M2C_ULONG({inner}, {args[2]})"
            # a field that is a pointer, dereferenced or indexed
            if before.endswith("*") and args[1].count("*") > 1:
                before, field = before[:-1], f"(*({pointee or 'int'} *){field})"
            elif b[e + 1:e + 2] == "[" and args[1].count("*") > 1:
                field = f"(({pointee or 'int'} *){field})"
            out.append(before + field)
        i = e + 1


def stack_frame(stack, end):
    """The declaration of one struct that lays the function's stack
    variables out at the offsets m2c saw them at. stack: [(offset, name,
    C type or None if unknown, element count or None)]."""
    if end is None:
        raise Reject("stack: no frame")
    fields, at = [], 0
    stack = sorted(stack)
    for n, (off, name, ty, count) in enumerate(stack):
        nxt = stack[n + 1][0] if n + 1 < len(stack) else end
        if off < at:
            raise Reject("stack overlap")
        if off > at:
            fields.append(f"char pad{at:X}[{off - at}];")
        if ty is None:
            size = nxt - off
            if size <= 0:
                raise Reject("stack overlap")
            fields.append(f"char {name}[{size}];")
        else:
            if off % SIZEOF[ty]:
                raise Reject("stack align")
            size = SIZEOF[ty] * (count or 1)
            fields.append(f"{ty} {name}{f'[{count}]' if count else ''};")
        at = off + size
    if not fields:
        fields.append(f"char pad0[{end}];")
    return "    struct { " + " ".join(fields) + " } stack;"


def prototypes(text):
    """{name: (return type, [parameter types])} from the declarations m2c
    writes above the functions."""
    out = {}
    for m in re.finditer(r"^([\w? ]+?\**)\s*\b(\w+)\(([^;{]*)\);", text, re.M):
        params = [re.sub(r"\b(arg|fparg)\d+$", "", p).strip() for p in split_args(m.group(3))]
        out[m.group(2)] = (m.group(1).strip(), [p for p in params if p != "void"])
    return out


def global_types(text):
    out = {}
    for m in re.finditer(r"^(?:extern|static) ([\w? ]+?\**)\s*(?<![\w$])([\w$]+)(\[[^\]]*\])?(?: = [^;]*)?;", text, re.M):
        out[m.group(2)] = (m.group(1).strip(), bool(m.group(3)))
    return out


def callee(ctx, name, counts):
    """(alias, declaration) to call the function `name` with. counts: how
    many arguments each call in the function passes."""
    ret, mparams = ctx.protos.get(name, ("M2C_UNK", []))
    params = None
    if name in ctx.sigs:
        ret, ints, floats = ctx.sigs[name]
        mparams = ints + ["f32"] * floats
        params = [ctype(q)[0] for q in mparams]
    rt = "float" if ret == "f32" else "int"
    if params is None and "f32" in mparams:
        try:
            params = [ctype(q)[0] for q in mparams]
        except Reject:
            params = None
    if params is not None and counts != {len(params)}:
        params = None  # the draft passes something else: leave it to the call
    if params is None:
        if rt == "int":
            return f"X_{name}", f'extern "C" int X_{name}(...) asm("{name}");'
        return f"Xf_{name}", f'extern "C" float Xf_{name}(...) asm("{name}");'
    try:
        code = SIG_LETTER[rt] + "".join(SIG_LETTER[p] for p in params)
    except KeyError:
        raise Reject("callee type")
    return f"X{code}_{name}", f'extern "C" {rt} X{code}_{name}({", ".join(params)}) asm("{name}");'


def typed(ctx, fn, hdr, body):
    body = flag_chain(body)
    body = re.sub(r"/\*.*?\*/", "", body)
    body = flag_chain3(body)
    body = OR_RETURN.sub(r"\1if (!(\2) || !(\3)) return \6;\n\1return \4;", body)
    body = re.sub(r"^(\s*\w+:)\n(\s*\})", r"\1;\n\2", body, flags=re.M)  # a label needs a statement
    m = re.match(r"^(.*?)\b(\w+)\((.*)\) \{$", hdr)
    ret, params = m.group(1).strip(), m.group(3).strip()
    bad = TYPED_BAD.search(hdr + "\n" + body)
    if bad:
        raise Reject(re.sub(r"(?<!M)\d", "N", bad.group(0))[:16])
    ptype, pre = {}, set()

    # parameters: aN is argN, f(12+N) is fpargN
    ints, floats = {}, {}
    if params and params != "void":
        for p in split_args(params):
            g = re.match(r"^(.*?)\b((fp)?arg(\d+))$", p)
            if not g:
                raise Reject("param")
            ty, pointee = ctype(g.group(1))
            if g.group(3):
                floats[int(g.group(4))] = g.group(2)
            else:
                ints[int(g.group(4))] = (g.group(2), ty)
                if pointee:
                    ptype[g.group(2)] = pointee
    own = demangle_params(fn)
    plist = []
    if own is not None:
        ni = nf = 0
        for t in own:
            if t == "float":
                plist.append(f"float fparg{nf}")
                nf += 1
            else:
                plist.append(f"{t} arg{ni}")
                ni += 1
        if (ints and max(ints) >= ni) or (floats and max(floats) >= nf):
            own = None  # the draft uses a register the name does not account for
    if own is None:
        plist = [f"{ints[i][1] if i in ints and ints[i][1] != 'float' else 'int'} arg{i}"
                 for i in range(max(ints) + 1 if ints else 0)]
        plist += [f"float fparg{i}" for i in range(max(floats) + 1 if floats else 0)]

    # locals; the ones m2c calls spNN are stack slots at that offset
    decl, lines, names, stack, arrays, fnptr, calls = [], [], set(), [], set(), {}, []
    top = True
    for line in body.split("\n"):
        g = re.match(r"^    (.+?)\(\*(\w+)\)\((.*)\);$", line) if top else None
        if g:
            fnptr[g.group(2)] = fn_type(f"{g.group(1)}(*)({g.group(3)})")
            decl.append(f"    int {g.group(2)};")
            names.add(g.group(2))
            continue
        g = re.match(r"^    ([\w?][\w ]*?\**)\s*\b(\w+)(?:\[(\w+)\])?;$", line) if top else None
        if g and g.group(1).split()[0] not in ("return", "goto", "break", "continue"):
            name, count = g.group(2), int(g.group(3), 0) if g.group(3) else None
            sp = re.fullmatch(r"sp([0-9A-F]+)", name)
            if count and not sp:
                raise Reject("local array")
            if g.group(1).strip() == "?" and sp:
                ty, pointee = None, None
            else:
                ty, pointee = ctype(g.group(1))
            if pointee:
                ptype[name] = pointee
            if sp:
                stack.append((int(sp.group(1), 16), name, ty, count))
                if count or ty is None:
                    arrays.add(name)
            else:
                decl.append(f"    {ty} {name};")
            names.add(name)
            continue
        if line.strip():
            top = False
        lines.append(line)
    b = "\n".join(lines)
    if stack or re.search(r"\bsp\b", b):
        decl.insert(0, stack_frame(stack, ctx.funcs.get(fn, (0, False, None))[2]))

    # Constants; a shift into the high word needs a 64-bit operand.
    b = FLOAT.sub(float_literal, b)
    b = re.sub(r"\((0x[0-9A-F]+|\d+) << (0x[23][0-9A-F])\)", r"((long) \1 << \2)", b)

    # fields
    b = typed_fields(b, calls, ctx.funcs.get(fn, (0, False, None, False))[3])
    if "M2C_FIELD(" in b or any("M2C_FIELD(" in c for c in calls):
        pre.add(FIELD_MACRO.rstrip("\n"))
    if "M2C_ULONG(" in b:
        pre.update(ULONG.split("\n"))

    # casts, indexing, dereferences
    b = re.sub(r"\((?:const )?(?:void|\?|M2C_UNK|s32|u32|s16|u16|s8|u8|f32|s64|u64|struct \w+) \*+\) ?", "(int) ", b)
    for k, v in CTYPE.items():
        b = re.sub(r"\(" + k + r"\)", "(" + v + ")", b)
    if "->" in b:
        raise Reject("->")
    for v in set(re.findall(r"\b([A-Za-z_]\w*)\[", b)):
        if v in ptype:
            b = re.sub(r"(&?)\b" + v + r"\[", lambda mm: ("&" if mm.group(1) else "") + f"(({ptype[v]} *)({v}))[", b)
        elif v not in ctx.globals and v not in arrays:
            raise Reject("index")
    b = deref(b, ptype)
    b = re.sub(r"\bNULL\b", "0", b)

    # strings and globals
    def string(mm):
        if mm.group(1) in ctx.labels:
            pre.add(f"extern const char {ctx.labels[mm.group(1)]}[];")
            return ctx.labels[mm.group(1)]
        return mm.group(0)

    b = re.sub(r'(?<!\(int\) )"((?:[^"\\]|\\.)*)"', string, b)
    strings = set(ctx.labels.values())
    b = re.sub(r'(?<![\w"])("(?:[^"\\]|\\.)*")', r"(int) \1", b)
    for g in strings:
        b = re.sub(r"(?<![\w&])" + g + r"\b", f"(int) {g}", b)
    # Globals go through their address, whatever the file declares them as.
    for g in set(re.findall(r"[\w$]+", b)) & (set(ctx.globals) | set(re.findall(r"\bD_[0-9A-F]+\b", b))):
        if g in strings or g in names or re.search(r"(?<![\w$])" + re.escape(g) + r"\(", b):
            continue
        gty, arr = ctx.globals.get(g, ("?", False))
        ty, pointee = ctype(gty)

        def use(mm):
            amp, star, idx = mm.group(1), mm.group(2), mm.group(3)
            if amp and idx:
                return f"&(({ty} *)&{g})["
            if amp or (arr and not idx and not star):
                return f"(int)&{g}"
            if idx:
                return f"(({ty} *)&{g})["
            if star and arr:
                return f"(*({ty} *)&{g})"
            if star:
                return f"(*({pointee or 'int'} *)(*(int *)&{g}))"
            return f"(*({ty} *)&{g})"

        if re.search(r"(?<![\w$])" + re.escape(g) + r"\s*\.", b):
            raise Reject("global struct")
        b = re.sub(r"(&)?(?:(?<![\w)\]])(\*))?(?<![\w$])" + re.escape(g) + r"(?![\w$])(\[)?", use, b)
        if not re.search(r"^(?:extern|static)\b[^;(]*(?<![\w$])" + re.escape(g) + r"(?![\w$])[^;(]*;", ctx.text, re.M):
            pre.add(f"extern int {g};")
    if re.search(r"\bjtbl_\w+", b):
        raise Reject("jump table")
    # the address of an element is a pointer, and our pointers are ints
    while True:
        mm = re.search(r"(?<!\(int\) \()&\(\((?:[\w ]+) \*\)(?:\(\w+\)|&[\w$]+)\)\[", b)
        if not mm:
            break
        e = close_paren(b, mm.end() - 1)
        b = b[:mm.start()] + "(int) (" + b[mm.start():e + 1] + ")" + b[e + 1:]

    # calls
    for c in set(re.findall(r"\b([A-Za-z_]\w*)\(", b)):
        if c in KEYWORDS:
            continue
        if c in fnptr and fnptr[c]:
            calls.append(f"(({fnptr[c]}){c})")
            b = re.sub(r"(?<![\w.])" + c + r"\(", f"@F{len(calls) - 1}@(", b)
            continue
        if c in names or re.fullmatch(r"(fp)?arg\d+", c):
            raise Reject("call through pointer")
        counts = set()
        for mm in re.finditer(r"(?<![\w.])" + c + r"\(", b):
            counts.add(len(split_args(b[mm.end():close_paren(b, mm.end() - 1)])))
        alias, d = callee(ctx, c, counts)
        # A mangled name gives the real order of the parameters, and the
        # arguments are worked out in that order; m2c lists ints, then floats.
        order = demangle_params(c)
        if (order and "float" in order and order[-order.count("float"):] != ["float"] * order.count("float")
                and counts == {len(order)} and alias[1:2] in SIG_LETTER.values()):
            try:
                code = alias[1] + "".join(SIG_LETTER[t] for t in order)
            except KeyError:
                code = None
            if code:
                rt = "float" if alias[1] == "f" else "int"
                alias = f"X{code}_{c}"
                d = f'extern "C" {rt} {alias}({", ".join(order)}) asm("{c}");'
                ni = len(order) - order.count("float")
                while True:
                    mm = re.search(r"(?<![\w.])" + c + r"\(", b)
                    if not mm:
                        break
                    e = close_paren(b, mm.end() - 1)
                    args = split_args(b[mm.end():e])
                    ints, floats = args[:ni], args[ni:]
                    new = [floats.pop(0) if t == "float" else ints.pop(0) for t in order]
                    b = b[:mm.start()] + alias + "(" + ", ".join(new) + b[e:]
        pre.add(d)
        b = re.sub(r"(?<![\w.])" + c + r"\(", alias + "(", b)
    if re.search(r"\)\(", re.sub(r"\((?:unsigned |signed )?(?:int|char|short|long|float)(?: \*+)?\)\(", "(", b)):
        raise Reject("call through pointer")
    for n in reversed(range(len(calls))):
        b = b.replace(f"@F{n}@", calls[n])
    if "@F" in b:
        raise Reject("call through pointer")
    # stack slots
    for name in arrays:
        b = re.sub(r"&" + name + r"\b(?!\[)", f"(int)&{name}", b)
    b = re.sub(r"&(sp[0-9A-F]+)\b(?!\[)", r"(int)&\1", b)
    b = b.replace("(int)(int)&", "(int)&")
    b = re.sub(r"\bsp\b", "(int)&stack", b)
    b = re.sub(r"\b(sp[0-9A-F]+)\b", r"stack.\1", b)
    rt = "void" if ret == "void" else "float" if ret == "f32" else "int"
    if ctx.funcs.get(fn, (0, False))[1] and rt != "float":
        rt = "int"
        b = tail_call(b)
    text = (f'extern "C" {rt} {fn}({", ".join(plist)})\n{{\n' + "\n".join(decl) + ("\n" if decl else "")
            + b + "}\n")
    if "u_long128" in text:
        pre.add(U128)
    text = block_moves(text, pre)
    text = virtual_calls(text, pre)
    return Candidate(text, pre)


VCALL = re.compile(r"\(\((\w+) \(\*\)\(([^()]*)\)\)M2C_FIELD\(\((\w+) \+ (0x[0-9A-F]+|\d+)\), int \*, 4\)\)\(")


def virtual_calls(text, pre):
    """A call through g++ 2.x's vtable (8-byte entries: the adjustment of
    `this` and the function) as a real virtual call, on a class made up
    for it with its vtable pointer at the same offset and the function in
    the same slot: only that makes the compiler address the entry first
    and read its two halves from there, as the game does."""
    pos = 0
    while True:
        m = VCALL.search(text, pos)
        if not m:
            return text
        pos = m.end()
        ret, params, vt, entry = m.group(1), split_args(m.group(2)), m.group(3), int(m.group(4), 0)
        end = close_paren(text, m.end() - 1)
        args = split_args(text[m.end():end])
        tail = f" + M2C_FIELD({vt}, short *, {m.group(4)})"
        if not args or not args[0].endswith(tail) or not params or entry % 8:
            continue
        obj = args[0][:-len(tail)]
        d = re.search(r"^ +" + vt + r" = M2C_FIELD\((.+), int \*, (0x[0-9A-F]+|\d+)\);\n", text[:m.start()], re.M)
        defs = list(re.finditer(r"^ +" + vt + r" = M2C_FIELD\((.+), int \*, (0x[0-9A-F]+|\d+)\);\n", text[:m.start()], re.M))
        if not defs or defs[-1].group(1) != obj:
            continue
        d = defs[-1]
        at = int(d.group(2), 0)
        try:
            code = SIG_LETTER[ret] if ret != "void" else "v"
            code += "".join(SIG_LETTER[q] for q in params[1:])
        except KeyError:
            continue
        name = f"m2c_v{at:X}_{entry:X}_{code}"
        slots = "".join(f"virtual void v{n}(); " for n in range(1, entry // 8))
        pad = f"char pad[{at}]; " if at else ""
        pre.add(f"struct {name} {{ {pad}{slots}virtual {ret} call({', '.join(params[1:])}); }};")
        call = f"(({name} *)({obj}))->call({', '.join(args[1:])})"
        text = text[:m.start()] + call + text[end + 1:]
        if len(re.findall(r"\b" + vt + r"\b", text)) == 2:  # its declaration and this assignment
            text = text[:d.start()] + text[d.end():]
        pos = 0


ULONG_COPY = re.compile(r"^( +)M2C_ULONG\((.+), (-?0x[0-9A-F]+|-?\d+)\) = \(long\) M2C_ULONG\((.+), (-?0x[0-9A-F]+|-?\d+)\);$")
TAIL_COPY = re.compile(r"^( +)M2C_FIELD\((.+), (int|short|signed char|unsigned char|unsigned short|unsigned int) \*, "
                       r"(0x[0-9A-F]+|\d+)\) = \((?:int|short|signed char|unsigned char|unsigned short|unsigned int)\) "
                       r"M2C_FIELD\((.+), (?:int|short|signed char|unsigned char|unsigned short|unsigned int) \*, "
                       r"(0x[0-9A-F]+|\d+)\);$")


def block_moves(text, pre):
    """A run of unaligned 64-bit copies at consecutive offsets (and the
    word that may follow them) is the assignment of a struct of that size
    whose alignment is 4: written as one, the compiler loads up to four
    pieces before it stores them, as in the game."""
    if "M2C_ULONG(" in text:  # a global on the other side is one too
        text = re.sub(r"\(\*\((?:unsigned )?long \*\)&([\w$]+)\)", r"M2C_ULONG(&\1, 0)", text)
    lines = text.split("\n")
    out, i = [], 0
    while i < len(lines):
        m = ULONG_COPY.match(lines[i])
        if not m:
            out.append(lines[i])
            i += 1
            continue
        ind, dst, d0, src, s0 = m.group(1), m.group(2), int(m.group(3), 0), m.group(4), int(m.group(5), 0)
        n, j = 8, i + 1
        while j < len(lines):
            g = ULONG_COPY.match(lines[j])
            if not g or (g.group(2), int(g.group(3), 0), g.group(4), int(g.group(5), 0)) != (dst, d0 + n, src, s0 + n):
                break
            n, j = n + 8, j + 1
        if j < len(lines):
            g = TAIL_COPY.match(lines[j])
            if g and SIZEOF[g.group(3)] == 4 and (g.group(2), int(g.group(4), 0), g.group(5), int(g.group(6), 0)) == (dst, d0 + n, src, s0 + n):
                n, j = n + 4, j + 1
        pre.add(f"struct m2c_block{n} {{ int w[{n // 4}]; }};")
        out.append(f"{ind}*(m2c_block{n} *)((char *)({dst}) + {d0}) = *(m2c_block{n} *)((char *)({src}) + {s0});")
        i = j
    return "\n".join(out)


STORE_RUN = re.compile(r"^( +)(\S.*) = ([^=;]+);\n(?:\1\S.* = \3;\n)+", re.M)


def swapped(ctx, fn, hdr, body, mask=7):
    """typed, with runs of statements that store the same value in the
    opposite order: this compiler can emit such stores last to first (the
    source probably had `a = b = 0;`), so the draft, which follows the
    code, has them backwards. Not every run is: bit n of mask says whether
    to turn the runs number n, n+3, n+6... of the function, and the
    strategies swapped1 to swapped6 try the other combinations."""
    c = typed(ctx, fn, hdr, body)
    seen = [0]

    def chain(m):
        seen[0] += 1
        if not mask >> ((seen[0] - 1) % 3) & 1:
            return m.group(0)
        lines = m.group(0).rstrip("\n").split("\n")
        targets = [ln.strip()[:-len(" = " + m.group(3) + ";")] for ln in lines]
        if any(" = " in t or not t.startswith(("M2C_FIELD(", "(*(")) for t in targets):
            return m.group(0)
        return "".join(ln + "\n" for ln in reversed(lines))

    text = STORE_RUN.sub(chain, c.text)
    if text == c.text:
        raise Reject("nothing to swap")
    return Candidate(text, c.pre)


TAIL_STORES = re.compile(r"^( +)(M2C_FIELD\(.*\) = [\w.+-]+;)\n\1(M2C_FIELD\(.*\) = [\w.+-]+;)\n(?=( *)(?:\}|return\b))", re.M)


def swaptail(ctx, fn, hdr, body):
    """typed, with the last two stores of each block the other way round
    when they store constants or variables: like the stores of one value
    (see swapped), these can come out of the compiler exchanged."""
    c = typed(ctx, fn, hdr, body)
    text = TAIL_STORES.sub(lambda m: f"{m.group(1)}{m.group(3)}\n{m.group(1)}{m.group(2)}\n", c.text)
    if text == c.text:
        raise Reject("nothing to swap")
    return Candidate(text, c.pre)


HOISTED = re.compile(r"^( +)(\w+) = (M2C_FIELD\(.+\));\n(\1if \(.*\) \{\n\1    )(.*)\n", re.M)


def inlined(ctx, fn, hdr, body):
    """typed, without the temporaries m2c makes for a load in the delay
    slot of a branch: `t = p->x; if (c) { use(t); }` back to
    `if (c) { use(p->x); }` when that is the only use. The compiler puts
    the load in the delay slot again, and can then also skip a second copy
    of it at the branch's target, which it does not do for a variable."""
    c = typed(ctx, fn, hdr, body)
    text = c.text
    while True:
        for m in HOISTED.finditer(text):
            t = m.group(2)
            if len(re.findall(r"\b" + t + r"\b", text)) == 3 and len(re.findall(r"\b" + t + r"\b", m.group(5))) == 1:
                use = re.sub(r"\b" + t + r"\b", lambda _: m.group(3), m.group(5))
                text = text[:m.start()] + m.group(4) + use + "\n" + text[m.end():]
                text = re.sub(r"^    \w[\w ]* " + t + r";\n", "", text, count=1, flags=re.M)
                break
        else:
            break
    if text == c.text:
        raise Reject("nothing to reorder")
    return Candidate(text, c.pre)


def redeclared(ctx, fn, hdr, body, order):
    """typed, with the locals declared in another order: the order decides
    which register each one gets. order: "reverse", or "vars" for the
    variables (var_*) before the temporaries."""
    c = typed(ctx, fn, hdr, body)
    m = re.match(r"^([^\n]*\n\{\n)((?:    (?!struct )[\w ]+ \w+;\n)+)", c.text)
    if not m:
        raise Reject("nothing to reorder")
    decls = m.group(2).splitlines(keepends=True)
    if order == "reverse":
        new = decls[::-1]
    else:
        new = sorted(decls, key=lambda d: " var_" not in d)
    if new == decls:
        raise Reject("nothing to reorder")
    return Candidate(m.group(1) + "".join(new) + c.text[m.end():], c.pre)


# name: (translator, m2c flags, whether m2c gets the game's prototypes)
STRATEGIES = {
    "plain": (plain, ["-t", "mips-gcc-c"], False),
    "typed": (typed, EE_FLAGS, True),
    "reversed": (lambda ctx, fn, hdr, body: redeclared(ctx, fn, hdr, body, "reverse"), EE_FLAGS, True),
    "varsfirst": (lambda ctx, fn, hdr, body: redeclared(ctx, fn, hdr, body, "vars"), EE_FLAGS, True),
    "inlined": (inlined, EE_FLAGS, True),
    "swaptail": (swaptail, EE_FLAGS, True),
    "swapped": (swapped, EE_FLAGS, True),
    **{f"swapped{n}": (lambda ctx, fn, hdr, body, n=n: swapped(ctx, fn, hdr, body, n), EE_FLAGS, True)
       for n in range(1, 7)},
}


# ------------------------------------------------------------ one file

class Context:
    pass


def log(rows):
    with log_lock, open(LOG, "a", encoding="utf8") as f:
        for r in rows:
            f.write(json.dumps(r) + "\n")


def pending(text, name):
    """The functions still INCLUDE_ASM, except those a NON_MATCHING block
    keeps a hand-written attempt for."""
    out = []
    for m in re.finditer(r'^INCLUDE_ASM\("asm/nonmatchings/' + re.escape(name) + r'", (\w+)\);$', text, re.M):
        if not text[:m.start()].rstrip().endswith("#else"):
            out.append(m.group(1))
    return out


def assemble(text, name, cand):
    """The file with the candidates in place: (text, {function: (first
    line, last line)}, {line: declaration})."""
    have = set(text.split("\n"))
    pre = sorted({d for c in cand.values() for d in c.pre} - have)
    # macros first, so the order of what is already there never matters
    pre.sort(key=lambda d: not d.startswith(("struct m2c_", "typedef ")))
    block = "".join(d + "\n" for d in pre)
    if '#include "include_asm.h"\n' in text:
        text = text.replace('#include "include_asm.h"\n', '#include "include_asm.h"\n' + block, 1)
    else:
        j = [m.end() for m in re.finditer(r"^#include [^\n]*\n", text, re.M)][-1]
        text = text[:j] + block + text[j:]
    for fn, c in cand.items():
        text = text.replace(f'INCLUDE_ASM("asm/nonmatchings/{name}", {fn});', c.text.rstrip("\n"), 1)
    spans, decls = {}, {}
    lines = text.split("\n")
    for n, line in enumerate(lines, 1):
        if line in pre:
            decls[n] = line
    for fn, c in cand.items():
        first = c.text.split("\n")[0]
        n = lines.index(first) + 1
        spans[fn] = (n, n + c.text.rstrip("\n").count("\n"))
    return text, spans, decls


def settle(name, text, cand, strategy, sizes, sync):
    """Compile the file with the candidates and drop the ones that fail,
    until the object matches. Returns (text with the survivors, their names)."""
    rows = []
    scratch = WORK / "scratch" / f"{flat(name)}.cpp"
    scratch.parent.mkdir(parents=True, exist_ok=True)

    def drop(fn, status, detail):
        del cand[fn]
        rows.append({"file": name, "fn": fn, "size": sizes.get(fn, (0,))[0], "strategy": strategy,
                     "status": status, "detail": detail})

    result = text
    redeclared, gone = set(), set()
    while cand:
        trial, spans, decls = assemble(text, name, cand)
        scratch.write_text(trial, encoding="utf8", newline="\n")
        try:
            ok, report = match.compare(name, scratch, sync=sync)
        except match.CompileError as e:
            errs = re.findall(r"\.cpp:(\d+): (?!warning)([^\n]*)", str(e))
            bad = {}
            for ln, msg in errs:
                ln = int(ln)
                for fn, (a, b) in spans.items():
                    if a <= ln <= b:
                        bad.setdefault(fn, msg)
                if ln in decls:
                    if "previous declaration" in msg or "conflicting types" in msg:
                        # a header of the file declares it already, as something
                        # else: our uses go through the address, so do without ours
                        redeclared.add(decls[ln])
                        continue
                    for fn, c in cand.items():
                        if decls[ln] in c.pre:
                            bad.setdefault(fn, "declaration: " + msg)
            if not bad and redeclared - gone:
                gone.update(redeclared)
                for c in cand.values():
                    c.pre -= redeclared
                continue
            if not bad:
                for fn in list(cand):
                    drop(fn, "compile", "unattributed: " + str(e).strip().split("\n")[-1][:120])
                break
            for fn, msg in bad.items():
                drop(fn, "compile", msg[:160])
            continue
        finally:
            sync = False
        status = {}
        for line in report:
            g = re.match(r"^  0x[0-9A-F]+ (\S+)\s+0x[0-9a-f]+\s+(.*)$", line)
            if g:
                status[g.group(1)] = g.group(2).strip()
        bad = [fn for fn in cand if not status.get(fn, "").endswith("MATCH")]
        if bad:
            for fn in bad:
                drop(fn, "differs", status.get(fn, "missing"))
            continue
        if ok:
            result = trial
            for fn in cand:
                rows.append({"file": name, "fn": fn, "size": sizes.get(fn, (0,))[0], "strategy": strategy,
                             "status": "match", "detail": ""})
            break
        # the functions match but the object does not: data of its own
        lit = [fn for fn, c in cand.items() if '"' in c.text]
        why = next((ln.strip() for ln in report if ln.startswith("  .")), report[-1] if report else "")
        for fn in (lit or list(cand)):
            drop(fn, "object", why[:160])
    else:
        cand = {}
    log(rows)
    return result, [r["fn"] for r in rows if r["status"] == "match"]


def run_file(name, strategies, sigs):
    src = ROOT / f"src/{name}.cpp"
    out = WORK / "out" / f"{name}.cpp"
    skel = WORK / "skel" / f"{name}.cpp"
    new = not src.exists()
    if out.exists() and (new or out.stat().st_mtime > src.stat().st_mtime):
        text = out.read_text(encoding="utf8")  # carry on from the last run
    elif not new:
        text = src.read_text(encoding="utf8")
    elif skel.exists():
        text = skel.read_text(encoding="utf8")
        # the skeleton's own empty functions need C linkage
        text = re.sub(r"^(void|int) (\w+)\(void\) \{$", r'extern "C" \1 \2(void) {', text, flags=re.M)
        text = text.replace('#include "ror.h"\n', "").replace(
            '#include "include_asm.h"\n', '#include "include_asm.h"\n' + HEADER, 1)
    else:
        return name, 0, "no .cpp and no skeleton (--prepare)"
    ctx = Context()
    ctx.funcs = asm_functions(name)
    ctx.labels = string_labels(name)
    ctx.sigs = sigs
    start = text
    got = []
    sync = True
    for s in strategies:
        fn_translate, flags, context = STRATEGIES[s]
        todo = pending(text, name)
        if not todo:
            break
        draft = m2c(name, "sig" if context else s, flags, CONTEXT if context else None)
        ctx.protos, ctx.globals, ctx.text = prototypes(draft), global_types(draft), text
        cand, rows = {}, []
        for hdr, body in FUNC_RE.findall(draft):
            fn = re.match(r"^.*?\b(\w+)\(", hdr).group(1)
            if fn not in todo:
                continue
            try:
                cand[fn] = fn_translate(ctx, fn, hdr, body)
            except Reject as e:
                rows.append({"file": name, "fn": fn, "size": ctx.funcs.get(fn, (0,))[0], "strategy": s,
                             "status": "rejected", "detail": str(e)})
            except Exception as e:  # a draft the rewriting did not foresee
                rows.append({"file": name, "fn": fn, "size": ctx.funcs.get(fn, (0,))[0], "strategy": s,
                             "status": "rejected", "detail": "error " + type(e).__name__})
        for fn in set(todo) - set(cand) - {r["fn"] for r in rows}:
            rows.append({"file": name, "fn": fn, "size": ctx.funcs.get(fn, (0,))[0], "strategy": s,
                         "status": "rejected", "detail": "no draft"})
        log(rows)
        if cand:
            text, ok = settle(name, text, cand, s, ctx.funcs, sync)
            sync = False
            got += ok
    if text != start:
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(text, encoding="utf8", newline="\n")
    return name, sum(ctx.funcs.get(f, (0,))[0] for f in got), f"{len(got)} functions" if got else ""


def show(name, fn, strategies, sigs):
    """One function alone: each strategy's candidate and how it compares."""
    src = next(q for q in (WORK / "out" / f"{name}.cpp", ROOT / f"src/{name}.cpp", WORK / "skel" / f"{name}.cpp")
               if q.exists())
    text = src.read_text(encoding="utf8")
    ctx = Context()
    ctx.funcs, ctx.labels, ctx.sigs = asm_functions(name), string_labels(name), sigs
    for s in strategies:
        fn_translate, flags, context = STRATEGIES[s]
        draft = m2c(name, "sig" if context else s, flags, CONTEXT if context else None)
        ctx.protos, ctx.globals, ctx.text = prototypes(draft), global_types(draft), text
        hdr, body = next((h, b) for h, b in FUNC_RE.findall(draft) if re.match(r"^.*?\b(\w+)\(", h).group(1) == fn)
        print(f"==== {s}: m2c\n{hdr}\n{body}}}")
        try:
            c = fn_translate(ctx, fn, hdr, body)
        except Reject as e:
            print(f"==== {s}: rejected: {e}")
            continue
        print(f"==== {s}: candidate\n" + "\n".join(sorted(c.pre)) + "\n" + c.text)
        trial, _, _ = assemble(text, name, {fn: c})
        scratch = WORK / "scratch" / f"{flat(name)}.show.cpp"
        scratch.parent.mkdir(parents=True, exist_ok=True)
        scratch.write_text(trial, encoding="utf8", newline="\n")
        try:
            _, report = match.compare(name, scratch, diff=True)
        except match.CompileError as e:
            print("==== compile error\n" + str(e))
            continue
        on = False
        for line in report:
            g = re.match(r"^  0x[0-9A-F]+ (\S+)", line)
            if g or line.startswith("  ."):
                on = bool(g) and g.group(1) == fn
            if on:
                print(line)


# ------------------------------------------------------------ commands

def prepare():
    """Skeletons and asm/nonmatchings for the files that have no .cpp."""
    todo = [n for n in game_files() if not (ROOT / f"src/{n}.cpp").exists()
            and not (WORK / "skel" / f"{n}.cpp").exists()]
    if not todo:
        return print("nothing to prepare")
    args = [a for n in todo for a in ("--new", n)]
    r = subprocess.run(["sh", str(ROOT / "tools/dock"), "python3", "tools/configure.py", *args],
                       capture_output=True, text=True, cwd=ROOT)
    for n in todo:
        src = ROOT / f"src/{n}.cpp"
        if src.exists():
            dst = WORK / "skel" / f"{n}.cpp"
            dst.parent.mkdir(parents=True, exist_ok=True)
            os.replace(src, dst)
    print(f"{len(todo)} skeletons in build/auto/skel/" if r.returncode == 0 else r.stdout[-2000:] + r.stderr[-2000:])
    print("config/SLUS_214.48.yaml and build.ninja now name files that are not in src/: "
          "run tools/dock python3 tools/configure.py before the next build")


def apply():
    n = 0
    for out in sorted((WORK / "out").rglob("*.cpp")):
        name = out.relative_to(WORK / "out").with_suffix("").as_posix()
        src = ROOT / f"src/{name}.cpp"
        if src.exists() and src.stat().st_mtime > out.stat().st_mtime:
            print(f"{name}: src/ is newer than the result, skipped")
            continue
        ok, report = match.compare(name, out)
        if not ok:
            print(f"{name}: does not match any more, skipped")
            continue
        src.parent.mkdir(parents=True, exist_ok=True)
        src.write_text(out.read_text(encoding="utf8"), encoding="utf8", newline="\n")
        out.unlink()
        n += 1
        print(f"{name}: written")
    print(f"{n} files written to src/. Now: tools/dock python3 tools/configure.py && tools/dock ninja")


def family(body):
    """A draft with its numbers and names blanked: equal for functions that
    differ only in constants, offsets and callees."""
    t = re.sub(r"/\*.*?\*/", "", body)
    t = re.sub(r"\b(func|D|jtbl)_[0-9A-Fa-f]+\b", r"\1", t)
    t = re.sub(r"\b0x[0-9A-Fa-f]+\b|\b\d+(\.\d+)?f?\b", "N", t)
    t = re.sub(r"unk[0-9A-F]+\b", "unk", t)
    t = re.sub(r'"(?:[^"\\]|\\.)*"', '"S"', t)
    return hashlib.sha1(re.sub(r"\s+", " ", t).encode()).hexdigest()[:10]


def report():
    best = {}   # (file, fn) -> row: a match wins, else the last attempt
    for line in LOG.read_text(encoding="utf8").splitlines():
        r = json.loads(line)
        if r["detail"] in ("nothing to swap", "nothing to reorder"):
            continue
        k = (r["file"], r["fn"])
        if k not in best or best[k]["status"] != "match":
            best[k] = r
    # what is still asm in src/ or in a pending result
    left = {}
    for name in game_files():
        p = next((q for q in (WORK / "out" / f"{name}.cpp", ROOT / f"src/{name}.cpp") if q.exists()), None)
        funcs = asm_functions(name)
        todo = pending(p.read_text(encoding="utf8"), name) if p else list(funcs)
        for fn in todo:
            left[(name, fn)] = funcs.get(fn, (0,))[0]
    total = sum(left.values())
    print(f"still asm: {len(left)} functions, {total:,} bytes")
    why = collections.Counter()
    count = collections.Counter()
    for k, size in left.items():
        r = best.get(k)
        key = f"{r['status']}: {r['detail'] if r['status'] == 'rejected' else ''}".rstrip(": ") if r else "never tried"
        if r and r["status"] == "compile":
            key = "compile: " + re.sub(r"`[^']*'", "`x'", r["detail"])[:60]
        why[key] += size
        count[key] += 1
    print("\nby reason (bytes, functions):")
    for key, size in why.most_common(40):
        print(f"  {size:8,} {count[key]:5}  {key}")
    fams = collections.defaultdict(list)
    for name in sorted({f for f, _ in left}):
        draft = WORK / "m2c" / f"{flat(name)}.plain.c"
        if not draft.exists():
            continue
        for hdr, body in FUNC_RE.findall(draft.read_text(encoding="utf8")):
            fn = re.match(r"^.*?\b(\w+)\(", hdr).group(1)
            if (name, fn) in left:
                fams[family(body)].append((name, fn, left[(name, fn)]))
    print("\nfamilies (bytes, functions, an example, its last result):")
    rows = sorted(((sum(s for _, _, s in v), len(v), v) for v in fams.values() if len(v) >= 3), reverse=True)
    for size, n, v in rows[:40]:
        r = best.get(v[0][:2])
        print(f"  {size:8,} {n:4}  {v[0][0]} {v[0][1]}  [{(r['status'] + ' ' + r['detail'])[:50] if r else ''}]")


def alive(pid):
    """Whether a process with this id exists."""
    if not pid.isdigit():
        return False
    if sys.platform == "win32":
        import ctypes
        k = ctypes.windll.kernel32
        h = k.OpenProcess(0x1000, False, int(pid))  # PROCESS_QUERY_LIMITED_INFORMATION
        if not h:
            return False
        code = ctypes.c_ulong()
        k.GetExitCodeProcess(h, ctypes.byref(code))
        k.CloseHandle(h)
        return code.value == 259  # STILL_ACTIVE
    try:
        os.kill(int(pid), 0)
    except ProcessLookupError:
        return False
    except PermissionError:
        pass
    return True


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("names", nargs="*", help="files as in config/splits.tsv (default: every game file)")
    ap.add_argument("-j", "--jobs", type=int, default=6)
    ap.add_argument("--strategies", default=",".join(k for k in STRATEGIES if k not in ("reversed", "varsfirst")),
                    help="default: all but reversed and varsfirst (declaration order: found nothing)")
    ap.add_argument("--prepare", action="store_true", help="skeletons for the files without a .cpp")
    ap.add_argument("--apply", action="store_true", help="copy the results that match into src/")
    ap.add_argument("--report", action="store_true", help="why what is left did not match")
    ap.add_argument("--signatures", action="store_true", help="work the game's prototypes out again")
    ap.add_argument("--show", metavar="FUNCTION", help="one function of the file given: candidates and diffs")
    a = ap.parse_args()
    WORK.mkdir(parents=True, exist_ok=True)
    if a.report:
        return report()
    if a.show:
        return show(a.names[0], a.show, a.strategies.split(","), signatures(a.jobs))
    lock = WORK / "lock"
    if lock.exists() and not alive(lock.read_text().strip()):
        lock.unlink()  # left by a run that was killed
    try:
        fd = os.open(lock, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
    except FileExistsError:
        sys.exit(f"{lock.relative_to(ROOT)}: another run is going (process {lock.read_text().strip()})")
    try:
        os.write(fd, str(os.getpid()).encode())
        os.close(fd)
        if a.prepare:
            return prepare()
        if a.apply:
            return apply()
        if not match.server_up():
            print("compile server down (tools/match.py --server start): this will be slow")
        names = a.names or game_files()
        strategies = a.strategies.split(",")
        sigs = signatures(a.jobs, a.signatures)
        total = 0
        with ThreadPoolExecutor(a.jobs) as ex:
            for name, size, note in ex.map(lambda n: run_file(n, strategies, sigs), names):
                total += size
                if note:
                    print(f"{name}: {note}" + (f", {size:,} bytes" if size else ""), flush=True)
        print(f"total: {total:,} bytes newly matching, in build/auto/out/ (--apply to take them)")
    finally:
        lock.unlink()


if __name__ == "__main__":
    main()
