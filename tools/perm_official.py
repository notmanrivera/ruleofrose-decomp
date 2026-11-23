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
    # every compile here is on the container's own filesystem: no ee-cc mirror
    r = subprocess.run(["sh", str(ROOT / "tools/dock"), "sh", "-c", "export EE_CC_MIRROR=0; " + cmd], cwd=ROOT,
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
    # C++'s f(...) is not C: (int, ...) here, and compile.sh writes it back
    s = s.replace("(...)", "(int, ...)")
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
    # include/target.h is plain C (ALIGNED, PS2_REG, u_long128, ...); of
    # ror.h only its C part: ASSERT with the file's own name for __FILE__,
    # and ASM_NOTHROW as a mark that compile.sh turns back into throw()
    out = [f'#line 1 "{name}.cpp"',
           '#define ROR_H',          # its C part is below; its C++ part must not come in through a header
           '#include "target.h"',
           '#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))',
           'typedef unsigned int size_t;',
           # C++ wants them declared (g++ expands them as builtins all the same)
           'extern void *memcpy(void *, const void *, size_t);',
           'extern void *memset(void *, int, size_t);',
           'extern void ror_assert(const char *file, int line, const char *expr);',
           '#ifndef ASSERT_FILE',
           '#define ASSERT_FILE __FILE__',
           '#endif',
           '#define ASSERT(e) ((e) ? (void)0 : ror_assert(ASSERT_FILE, __LINE__, #e))',
           '#define ASSERT_S(e, str) ((e) ? (void)0 : ror_assert(ASSERT_FILE, __LINE__, str))',
           '#define ASM_NOTHROW __attribute__((ror_nothrow))']
    PRELUDE = len(out)
    for kind, it in top_items(before):
        if kind == "pp":
            if re.match(r"#\s*define\s", it) and "M2C_FIELD" not in it and "PS2_REG" not in it:
                out.append(it)
            # the file's own headers (src/**.h): their types are what the
            # attempt uses; keep_parsable turns their classes into C structs
            inc = re.match(r'#\s*include\s+"([^"]+)"', it)
            if inc and inc.group(1) not in ("include_asm.h", "ror.h", "target.h") \
                    and ((ROOT / "src" / inc.group(1)).exists() or (ROOT / "src" / Path(name).parent / inc.group(1)).exists()):
                out.append(it)
        elif kind == "decl":
            # everything but what is never C; the rest is kept when the
            # parser accepts it (keep_parsable), not guessed from its words
            if "INCLUDE_ASM" not in it and "INCLUDE_RODATA" not in it \
                    and not it.lstrip().startswith(("using", "static_assert", "STATIC_ASSERT", "template")):
                out.append(plain_c(it))
    out.append(plain_c(m.group(1)))
    # C++ lets a struct's tag stand alone as a type name, C does not: a
    # typedef of each tag defined here (valid in both; the code is the same)
    body = "\n".join(out)
    tags = sorted(set(re.findall(r"\b(struct|union)\s+(?:(?:__attribute__\s*\(\(.*?\)\)|ALIGNED\(\d+\))\s*)?([A-Za-z_]\w*)\s*\{", body)))
    typedefs = [f"typedef {kind} {tag} {tag};" for kind, tag in tags]
    return "\n".join(out[:PRELUDE] + typedefs + out[PRELUDE:]) + "\n"


def parses(text):
    from perm_pycparser import c_parser
    try:
        c_parser.CParser().parse(text)
        return True
    except Exception:
        return False


def members(body):
    """A class body's top-level members: the text of each declaration up to
    its ';', and each inline function as one item (body included)."""
    out, depth, start, i = [], 0, 0, 0
    while i < len(body):
        c = body[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0 and re.search(r"\)\s*(?:const\s*)?(?::[^{;]*)?\{", body[start:i + 1], re.S) \
                    and not re.match(r"\s*(?:struct|class|union|enum)\b[^({;]*\{", body[start:i + 1]):
                out.append(body[start:i + 1])         # an inline method or constructor (not a nested type)
                start = i + 1
        elif c == ";" and depth == 0:
            out.append(body[start:i + 1])
            start = i + 1
        i += 1
    return [m.strip() for m in out if m.strip() and m.strip() != ";"]


FIELD = re.compile(r"^(?:(?:const|volatile|unsigned|signed|struct|union|enum)\s+)*[A-Za-z_][\w\s\*]*?"
                   r"[\s\*]([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*(?::\s*\d+\s*)?;$", re.S)


def c_struct(item, structs, sizes=None):
    """A C++ class/struct definition as a C struct with the same layout, as
    g++ 2.96 lays it out: the bases' fields first (flattened, so code using
    an inherited field still finds it by name), then its own data members,
    then a vtable pointer at the end of the first class in the line that
    declares a virtual function. Methods, access labels, static members
    and nested types go. Unchanged when it is not a class definition; None
    when it cannot be expressed (then the parser decides)."""
    m = re.match(r"\s*(class|struct)\s+([A-Za-z_]\w*)\s*(?::\s*([^{]+?))?\s*\{(.*)\}\s*;\s*$", item, re.S)
    fwd = re.match(r"\s*(class|struct)\s+([A-Za-z_]\w*)\s*;\s*$", item)
    if fwd:
        return f"typedef struct {fwd.group(2)} {fwd.group(2)};"
    if not m:
        return item
    _, name, bases, body = m.groups()
    sizes = sizes if sizes is not None else {}
    fields, vptr = [], False
    for b in (bases or "").split(","):
        b = re.sub(r"\b(public|private|protected|virtual)\b", "", b).strip()
        if not b:
            continue
        BASES.setdefault(name, []).append(b)
        if b not in structs:
            return opaque(name, structs, sizes)   # a base we could not lay out
        bf, bv = structs[b]
        fields += bf
        vptr = vptr or bv
    body = re.sub(r"\b(public|private|protected)\s*:", "", body)
    # nested types go to file scope under the class's name (two classes may
    # both have a Node): Outer_Node, and Outer::Node elsewhere is renamed too
    for nested in set(re.findall(r"(?:struct|class|union)\s+([A-Za-z_]\w*)\s*\{", body)):
        if not nested.startswith(name + "_"):
            body = re.sub(rf"\b{nested}\b", f"{name}_{nested}", body)
            NESTED[f"{name}::{nested}"] = f"{name}_{nested}"
    own_virtual = False
    hoisted = []
    for mem in members(body):
        if re.search(r"\bvirtual\b", mem):
            own_virtual = True
        # a pointer to member function: g++ 2.96 stores {short delta, short
        # index, pfn}, 8 bytes
        pm = re.match(r"^[^;()]*\(\s*[A-Za-z_]\w*\s*::\s*\*\s*([A-Za-z_]\w*)\s*\)\s*\([^;]*\)\s*;$", mem, re.S)
        if pm:
            fields.append(f"struct {{ short delta; short index; void *pfn; }} {pm.group(1)};")
            continue
        # a nested struct/union with a declarator is a member as it is
        if re.match(r"(?:struct|union)\b[^;{]*\{.*\}\s*[A-Za-z_]\w*(?:\s*\[[^\]]*\])*\s*;$", mem, re.S):
            fields.append(re.sub(r"\b(public|private|protected)\s*:", "", mem))
            continue
        # a nested type alone: hoisted to file scope (C has no nested scope)
        if re.match(r"(?:struct|class)\s+[A-Za-z_]\w*\s*(?::[^{]*)?\{.*\}\s*;$", mem, re.S):
            h = c_struct(mem, structs, sizes)
            if h:
                hoisted.append(h)
            continue
        if re.match(r"enum\b[^;]*\{.*\}\s*;$", mem, re.S):
            hoisted.append(mem)
            continue
        if (re.search(r"\(", mem) and not re.search(r"\(\s*\*", mem)) or mem.endswith("}") \
                or re.match(r"(static|typedef|friend|using|enum|struct|union|class)\b", mem):
            mi = method_info(name, mem)       # a method: kept apart, as a C function if called
            if mi:
                METHODS.setdefault(name, {})[mi[0]] = mi[1]
            continue                          # methods, ctors, statics, other nested types
        mem = re.sub(r"\bmutable\s+", "", mem)
        if "<" in mem and TEMPLATES:
            mem = template_uses(mem, structs, sizes)
        bare = re.sub(r"\s*__attribute__\s*\(\(.*?\)\)", "", mem)   # aligned(64) and such stay in the field
        if FIELD.match(bare) or re.search(r"\(\s*\*\s*\w+\s*\)", mem):
            fields.append(mem)
        else:
            return opaque(name, structs, sizes)
    if own_virtual and not vptr:
        fields.append(f"void *_vptr_{name};")
        vptr = True
    structs[name] = (fields, vptr)
    return ("\n".join(hoisted + [""]) if hoisted else "") + \
        f"typedef struct {name} {name};\nstruct {name} {{\n    " + "\n    ".join(fields or ["char _empty;"]) + "\n};"


# ---- Non-virtual method calls as plain C calls. A method gets the object as
# its first argument in $a0 either way, so 'p->m(x)' and 'C__m((C *)(p), x)'
# compile to the same code: the inline methods of the headers become static
# inline C functions with an explicit this_, the others extern declarations
# with the game's mangled name. Virtual calls (through the vtable) stay out.

METHODS, BASES = {}, {}    # class -> {method: info}, class -> [bases]; per keep_parsable call
HELPERS = {}               # "C__m" -> "m" for the helpers made (apply_output turns calls back)
NESTED = {}                # "Outer::Inner" -> "Outer_Inner" for the hoisted nested types

METHOD_DEF = re.compile(r"^(?P<head>[^{;]*?)\b(?P<m>[A-Za-z_]\w*)\s*\((?P<params>[^(){};]*)\)\s*(?P<const>const)?\s*"
                        r"(?:asm\s*\(\s*\"(?P<label>[^\"]+)\"\s*\))?\s*(?:\{(?P<body>.*)\}|;)$", re.S)


def method_info(cls, mem):
    """(name, dict) for a non-virtual, non-static method member, or None."""
    m = METHOD_DEF.match(mem.strip())
    if not m or m.group("m") in (cls, "operator") or "~" in m.group("head"):
        return None
    head = m.group("head").strip()
    if re.search(r"\b(virtual|static|friend|operator|template)\b", head) or not head:
        return None
    params = m.group("params").strip()
    if "&" in params or "=" in params or "..." in params:
        return None                        # references, defaults, varargs: not as C
    ret = re.sub(r"\binline\b", "", head).strip()
    return m.group("m"), {"cls": cls, "ret": ret, "params": "" if params == "void" else params,
                          "body": m.group("body"), "label": m.group("label"), "const": bool(m.group("const"))}


def link_name(cls, name, info):
    """The symbol a call to cls::name links to: its asm label, the game's
    mangled name from the symbols, or g++ 2.96's mangling of it."""
    return info["label"] or mangled(cls, name) or mangle(cls, name, info["params"], info["const"])


def field_names(fields):
    out = set()
    for f in fields:
        g = re.search(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*(?::\s*\d+\s*)?;\s*$", f)
        if g:
            out.add(g.group(1))
    return out


def operand_before(code, end):
    """Start index of the expression that ends at code[end] (the receiver
    before '->' or '.'): names, member chains, [index] and (calls/parens)."""
    i = end
    while True:
        while i > 0 and code[i - 1] in " \t":
            i -= 1
        if i > 0 and code[i - 1] in ")]":
            close = code[i - 1]
            opn = "(" if close == ")" else "["
            depth, j = 0, i - 1
            while j >= 0:
                depth += {close: 1, opn: -1}.get(code[j], 0)
                if depth == 0:
                    break
                j -= 1
            i = j
            continue
        j = i
        while j > 0 and (code[j - 1].isalnum() or code[j - 1] == "_"):
            j -= 1
        if j == i:
            return i
        i = j
        k = i
        while k > 0 and code[k - 1] in " \t":
            k -= 1
        if code[k - 2:k] == "->":
            i = k - 2
        elif k > 0 and code[k - 1] == "." and not code[k - 2:k - 1].isdigit():
            i = k - 1
        else:
            return i


def resolve(name, methods, bases, receiver_cls=None):
    """The class whose method 'name' a call means: the receiver's class or
    the nearest base defining it; else the only class defining it."""
    def up(c):
        seen = []
        while c and c not in seen:
            seen.append(c)
            if name in methods.get(c, {}):
                return c
            c = (bases.get(c) or [None])[0]
        return None
    owner = up(receiver_cls) if receiver_cls else None
    if not receiver_cls:
        owners = [c for c, ms in methods.items() if name in ms]
        owner = owners[0] if len(owners) == 1 else None
    # only a method a C function can stand for: inline body, asm label or a
    # known mangled name (else the call stays and the parser decides)
    if owner:
        info = methods[owner][name]
        if info["body"] is None and not link_name(owner, name, info):
            return None
    return owner


def receiver_class(operand, code, structs):
    """The class of a plain-name receiver from its declaration in code."""
    if not re.fullmatch(r"[A-Za-z_]\w*", operand.strip()):
        return None
    m = re.search(rf"\b([A-Za-z_]\w*)\s*\*?\s*(?:const\s*)?\b{re.escape(operand.strip())}\b\s*(?:=|;|\[|,|\))", code)
    return m.group(1) if m and m.group(1) in structs else None


def rewrite_calls(code, methods, bases, structs, used, this_cls=None, fields=()):
    """code with every resolvable non-virtual method call made a C call;
    the helpers it needs are added to used."""
    names = {n for ms in methods.values() for n in ms}
    out, pos = [], 0
    # group 3: an unqualified call, only inside a method's body
    pat = re.compile(r"(->|\.)\s*([A-Za-z_]\w*)\s*\(|" + (r"(?<![\w.>])([A-Za-z_]\w*)\s*\(" if this_cls else r"(?!)(x)"))
    for m in pat.finditer(code):
        name = m.group(2) or m.group(3)
        if name not in names or m.start() < pos:
            continue
        if m.group(3):                         # an unqualified call inside a method body
            if name in fields:
                continue
            cls = resolve(name, methods, bases, this_cls)
            if not cls:
                continue
            out.append(code[pos:m.start()] + f"{cls}__{name}(({cls} *)this_")
            used.add((cls, name))
            pos = m.end()
            out.append("" if re.match(r"\s*\)", code[pos:]) else ", ")
            continue
        start = operand_before(code, m.start())
        if start < pos:
            continue
        operand = code[start:m.start()].strip()
        if not operand:
            continue
        cls = resolve(name, methods, bases, receiver_class(operand, code, structs))
        if not cls:
            continue
        arg = f"({cls} *)({operand})" if m.group(1) == "->" else f"({cls} *)&({operand})"
        out.append(code[pos:start] + f"{cls}__{name}({arg}")
        used.add((cls, name))
        pos = m.end()
        out.append("" if re.match(r"\s*\)", code[pos:]) else ", ")
    out.append(code[pos:])
    return "".join(out)


BUILTIN = {"void": "v", "char": "c", "signed char": "Sc", "unsigned char": "Uc", "short": "s",
           "unsigned short": "Us", "int": "i", "unsigned int": "Ui", "unsigned": "Ui", "long": "l",
           "unsigned long": "Ul", "long long": "x", "unsigned long long": "Ux", "float": "f",
           "double": "d", "bool": "b", "u_int": "Ui", "u_char": "Uc", "u_short": "Us", "u_long": "Ul"}


TYPE_WORDS = {"void", "char", "short", "int", "long", "float", "double", "bool", "unsigned", "signed", "const"}


def mangle_type(t):
    """g++ 2.x code of one parameter type ('const char *p' -> 'PCc'), or None."""
    toks = re.sub(r"\b(struct|class|register)\b", " ", t).replace("*", " * ").split()
    if len(toks) >= 2 and re.fullmatch(r"[A-Za-z_]\w*", toks[-1]) and toks[-1] not in TYPE_WORDS:
        toks.pop()                         # the parameter's name
    code = ""
    while toks and toks[-1] == "*":
        toks.pop()
        code += "P"
    if toks and toks[0] == "const":
        toks = toks[1:]
        code += "C"
    t = " ".join(toks)
    base = BUILTIN.get(t)
    if base is None:
        if not re.fullmatch(r"[A-Za-z_]\w*", t):
            return None
        base = ("" if code else "G") + f"{len(t)}{t}"   # a class by value is G<len><name>
    return code + base


def mangle(cls, name, params, const):
    """cls::name's g++ 2.96 mangled name for simple signatures, or None
    (the back-references g++ writes for a repeated class type are not made)."""
    codes, seen = [], []
    for p in [p for p in params.split(",") if p.strip()]:
        c = mangle_type(p)
        if c is None:
            return None
        core = c.lstrip("PCG")
        if core[:1].isdigit():
            if core in seen:
                return None
            seen.append(core)
        codes.append(c)
    return f"{name}__{'C' if const else ''}{len(cls)}{cls}{''.join(codes) or 'v'}"


SYMBOLS = None


def mangled(cls, name):
    """The game's mangled name for cls::name (symbols/ghidra_symbols.tsv),
    when there is exactly one."""
    global SYMBOLS
    if SYMBOLS is None:
        SYMBOLS = {}
        try:
            for ln in (ROOT / "symbols/ghidra_symbols.tsv").read_text(encoding="utf8").splitlines()[1:]:
                w = ln.split("\t")
                if len(w) >= 7 and w[2] and w[6]:
                    SYMBOLS.setdefault((w[2], w[3]), []).append(w[6])
        except OSError:
            pass
    got = SYMBOLS.get((cls, name), [])
    return got[0] if len(got) == 1 else None


def helper(cls, name, info, methods, bases, structs, used):
    """The C function standing for cls::name, or None."""
    params = f"{cls} *this_" + (f", {info['params']}" if info["params"] else "")
    if info["body"] is None:
        label = link_name(cls, name, info)
        return f'extern {info["ret"]} {cls}__{name}({params}) asm("{label}");' if label else None
    fields = field_names(structs.get(cls, ([], False))[0])
    own = {p.split()[-1].lstrip("*") for p in info["params"].split(",") if p.strip()}
    body = re.sub(r"\bthis\s*->", "this_->", info["body"])
    body = re.sub(r"(?<![\w.>])\*\s*this\b", "(*this_)", body)
    body = re.sub(rf"(?<![\w.>])\b({'|'.join(map(re.escape, sorted(fields - own))) or '(?!)'})\b(?!\s*\()",
                  r"this_->\1", body)
    body = rewrite_calls(body, methods, bases, structs, used, this_cls=cls, fields=fields)
    return f"static inline {info['ret']} {cls}__{name}({params}) {{{body}}}"


def method_calls_back(code, helpers):
    """The C calls of the helpers turned back into C++ method calls:
    'C__m((C *)(p), x)' -> '(p)->m(x)', 'C__m((C *)&(o))' -> '(o).m()'."""
    for cname, m in helpers.items():
        cls = cname[:-len(m) - 2]
        while True:
            k = code.find(cname + "(")
            if k < 0:
                break
            i, depth, args, start = k + len(cname) + 1, 1, [], k + len(cname) + 1
            while i < len(code) and depth:
                c = code[i]
                depth += {"(": 1, ")": -1}.get(c, 0)
                if (c == "," and depth == 1) or depth == 0:
                    args.append(code[start:i].strip())
                    start = i + 1
                i += 1
            first, rest = args[0], [a for a in args[1:] if a]
            g = re.fullmatch(rf"\(\s*{re.escape(cls)}\s*\*\s*\)\s*(&?)\s*\((.*)\)", first, re.S)
            if g:
                call = f"({g.group(2)}){'.' if g.group(1) else '->'}{m}({', '.join(rest)})"
            else:
                call = f"(({cls} *)({first}))->{m}({', '.join(rest)})"
            code = code[:k] + call + code[i:]
    return code


# ---- Class templates (game/gamlist.h's GamList<T>, GamPool<T, N>): each use
# as a member type becomes a concrete struct (GamPool_int_8), its nested types
# renamed after it (GamList_int_Node), the parameters put in as text.
TEMPLATES = {}             # name -> (params, bases, body); per keep_parsable call
INSTANCES = []             # struct texts made, emitted before the struct that used them


def template_def(item):
    m = re.match(r"\s*template\s*<([^>]*)>\s*(?:class|struct)\s+([A-Za-z_]\w*)\s*(?::\s*([^{]+?))?\s*\{(.*)\}\s*;\s*$",
                 item, re.S)
    if not m:
        return False
    params = [p.split()[-1] for p in m.group(1).split(",") if p.strip()]
    TEMPLATES[m.group(2)] = (params, m.group(3) or "", m.group(4))
    return True


def instance(tname, args, structs, sizes):
    """The concrete struct name for tname<args> (made on first use), or None."""
    if tname not in TEMPLATES:
        return None
    params, bases, body = TEMPLATES[tname]
    args = [a.strip() for a in args]
    if len(args) != len(params):
        return None
    name = tname + "_" + "_".join(re.sub(r"\W+", "", a) for a in args)
    if name in structs:
        return name
    def subst(text):
        for p, a in zip(params, args):
            text = re.sub(rf"\b{re.escape(p)}\b", a, text)
        return re.sub(r"\btypename\s+", "", text)
    body, bases = subst(body), subst(bases)
    # its nested types get its name
    for nested in re.findall(r"(?:struct|class)\s+([A-Za-z_]\w*)\s*\{", body):
        body = re.sub(rf"\b{nested}\b", f"{name}_{nested}", body)
    # X<args> in its bases and members: instances too
    body = template_uses(body, structs, sizes)
    bases = template_uses(bases, structs, sizes)
    text = c_struct(f"class {name}{' : ' + bases if bases.strip() else ''} {{{body}}};", structs, sizes)
    if text is None:
        return None
    INSTANCES.append(text)
    return name


def template_uses(text, structs, sizes):
    """Each X<args> (and X<args>::Nested) in text as its instance's name."""
    def one(m):
        inst = instance(m.group(1), m.group(2).split(","), structs, sizes)
        if not inst:
            return m.group(0)
        return inst + (f"_{m.group(3)}" if m.group(3) else "")
    return re.sub(r"\b([A-Za-z_]\w*)\s*<([^<>;{}]*)>(?:\s*::\s*([A-Za-z_]\w*))?", one, text)


def opaque(name, structs, sizes):
    """A class we cannot lay out field by field, as bytes of its known size
    (STATIC_ASSERT(sizeof(X) == N) in the headers): code reaching into it
    is lost, but structs holding it and pointers to it keep their layout.
    None when its size is unknown."""
    if name not in sizes:
        return None
    structs[name] = ([f"char _opaque[{sizes[name]:#x}];"], False)
    return f"typedef struct {name} {name};\nstruct {name} {{\n    char _opaque[{sizes[name]:#x}];\n}};"


def class_sizes(text):
    """{class: size} from the STATIC_ASSERT(sizeof(X) == N) lines (and the
    typedef'd negative-array form they expand to)."""
    out = {}
    for m in re.finditer(r"sizeof\s*\(\s*([A-Za-z_]\w*)\s*\)\s*==\s*(0x[0-9A-Fa-f]+|\d+)", text):
        out[m.group(1)] = int(m.group(2), 0)
    return out


def unwrap_extern_c(text):
    """'extern "C" { ... }' blocks (SDK headers) without their braces: C has
    none, and top_items would take a whole block for one declaration."""
    while True:
        m = re.search(r'extern\s+"C"\s*\{', text)
        if not m:
            return text
        depth, i = 0, m.end() - 1
        while i < len(text):
            depth += {"{": 1, "}": -1}.get(text[i], 0)
            if depth == 0:
                break
            i += 1
        text = text[:m.start()] + text[m.end():i] + text[i + 1:]


def keep_parsable(pre, fn):
    """The preprocessed text with each top-level item kept only when the
    parser accepts it after the ones already kept; the function must stay.
    C++ class definitions (from the file's headers) become C structs first."""
    pre = unwrap_extern_c(pre)
    items = [it for kind, it in top_items(pre) if kind != "pp"]
    structs = {}
    sizes = class_sizes(pre)
    METHODS.clear()
    BASES.clear()
    HELPERS.clear()
    TEMPLATES.clear()
    NESTED.clear()
    conv = []
    for it in items:
        if re.match(r"\s*template\b", it):
            template_def(it)
            continue
        for q, flat in NESTED.items():
            if q.split("::")[0] in it:
                it = re.sub(rf"\b{q.replace('::', r'\s*::\s*')}\b", flat, it)
        del INSTANCES[:]
        c = c_struct(it, structs, sizes) if re.match(r"\s*(class|struct)\b", it) else it
        conv.extend(INSTANCES)                 # template instances it needed, before it
        if c is not None:
            conv.append(c)
    # a base class pointer parameter of a declared function as void *: the
    # flattened structs lost their C++ bases, so g++ would refuse a derived
    # pointer for it (same code: a pointer is a pointer)
    based = {b for bs in BASES.values() for b in bs}
    if based:
        bre = re.compile(rf"\b(?:struct\s+)?(?:{'|'.join(map(re.escape, sorted(based)))})\s*\*(?!\s*\*)")
        for k, it in enumerate(conv):
            if re.search(r"\)\s*(?:asm\s*\([^)]*\)\s*)?;\s*$", it) and "{" not in it and "(" in it:
                head, sep, rest = it.partition("(")
                conv[k] = head + sep + bre.sub("void *", rest)
    # method calls in the file's functions as C calls, and the C functions
    # standing for the methods called (recursively), just before the target
    used, done, helpers = set(), set(), []
    for k, it in enumerate(conv):
        if re.search(r"\)\s*\{", it) and not re.match(r"\s*(typedef|struct|union|enum)\b", it):
            conv[k] = rewrite_calls(it, METHODS, BASES, structs, used)
    while used - done:
        cls, name = sorted(used - done)[0]
        done.add((cls, name))
        h = helper(cls, name, METHODS[cls][name], METHODS, BASES, structs, used)
        if h:
            helpers.append(h)
            HELPERS[f"{cls}__{name}"] = name
    t = next((k for k, it in enumerate(conv) if re.search(rf"\b{re.escape(fn)}\s*\([^;{{]*\)\s*\{{", it)), None)
    if t is not None and helpers:
        conv[t:t] = list(reversed(helpers))    # a helper's own helpers were added after it
    items = conv
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
{ printf 'extern "C" {\\n'; sed 's/(int, \\.\\.\\.)/(...)/g; s/__attribute__((ror_nothrow))/throw()/g' "$1"; printf '\\n}\\n'; } > "$d/x.cpp"
cd "$d"
# -fpermissive: the flattened structs lost their C++ bases, so a derived
# pointer passed for a base one is only a warning (no effect on the code)
ee-cc @COMPILER@ @CFLAGS@ -fpermissive -c x.cpp -o out.o 2>"$d/err" || { cat "$d/err" >&2; exit 1; }
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
                     f"(cd /work/src && find . -name '*.h' | tar cf - -T -) | (cd $T/src && tar xf -); "
                     f"cp /work/{rel}/raw.c /work/{rel}/target.cpp $T/; "
                     f"cd $T && ee-cc {configure.COMPILER} -E -P -x c -Iinclude -Isrc -Isrc/{Path(name).parent.as_posix()} "
                     f"raw.c -o pre.c; "
                     f"cd $T/src && ee-cc {configure.COMPILER} {configure.CFLAGS} -c ../target.cpp -o ../target.o; "
                     f"python3 /work/tools/fix_hi16.py $T/target.o >/dev/null; "
                     f"cp $T/pre.c $T/target.o /work/{rel}/")
    if code or not (d / "pre.c").exists() or not (d / "target.o").exists():
        return None, "preprocess/target failed: " + out[-300:]
    base = keep_parsable((d / "pre.c").read_text(encoding="utf8", errors="replace"), fn)
    if base is None:
        return None, "the parser rejects the function"
    (d / "base.c").write_text(base, encoding="utf8", newline="\n")
    (d / "helpers.tsv").write_text("".join(f"{c}\t{m}\n" for c, m in sorted(HELPERS.items())),
                                   encoding="utf8", newline="\n")
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
    status, why = apply_output(name, fn, zero[0])
    return status, best + (f" ({why})" if why else "")


def apply_output(name, fn, out_dir):
    """A score-0 variant (out_dir/source.c) into work.py's scratch file:
    the attempt's own declarations (its NON_MATCHING block's extern lines)
    and the permuter's function, as extern "C"; checked by work.py, then
    --done and a commit. ("MATCH", None) or ("no match", why)."""
    src = (out_dir / "source.c").read_text(encoding="utf8", errors="replace")
    func = next((it for kind, it in top_items(src) if kind == "func"
                 and re.search(rf"\b{re.escape(fn)}\s*\(", it.split("{", 1)[0])), None)
    if not func:
        return "no match", "score 0, but its function was not found"
    func = re.sub(r"^\s*(?:extern\s+)+", "", func.strip())
    hp = out_dir.parent.parent / "helpers.tsv"
    if hp.exists():
        func = method_calls_back(func, dict(ln.split("\t") for ln in hp.read_text(encoding="utf8").splitlines() if ln))
    # register variables come back with PS2_REG expanded: put the macro back,
    # or the PC compilers of tools/host_check.py refuse "$f0" and the merge stops
    func = re.sub(r'\b(register[^;=]*\b[A-Za-z_]\w*)\s+(?:__asm__|asm)\("(\$[a-z0-9]+)"\)', r'\1 PS2_REG("\2")', func)
    block = work.nm_block((ROOT / "src" / f"{name}.cpp").read_text(encoding="utf8"), name, fn)
    # everything the attempt's block holds but its function: declarations,
    # structs, inline helpers (bSetYaw in unk/00166AD0), as they were
    decls = [it for kind, it in top_items(block.group(1) if block else "")
             if not (kind == "func" and re.search(rf"\b{re.escape(fn)}\s*\(", it.split("{", 1)[0]))]
    # the permuter also mutates declarations (a callee's return type, say):
    # a prototype the attempt's block has, changed in the variant, comes in
    # changed (as C++ again: extern "C", (...), ASM_NOTHROW)
    def proto_name(d):
        g = re.search(r"\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*(?:__attribute__\s*\(\([^)]*\)\)\s*)?(?:asm\s*\(\"[^\"]*\"\)\s*)?;\s*$", d.strip())
        return g.group(1) if g and "{" not in d else None
    changed = {proto_name(it): it for kind, it in top_items(src) if kind == "decl" and proto_name(it)}
    for k, d in enumerate(decls):
        n = proto_name(d)
        if n and n in changed:
            v = changed[n].strip().replace("(int, ...)", "(...)").replace("__attribute__((ror_nothrow))", "ASM_NOTHROW")
            if re.sub(r"\s+", " ", plain_c(d).strip()) != re.sub(r"\s+", " ", changed[n].strip()):
                if re.match(r'\s*extern\s+"C"', d) and not v.startswith('extern "C"'):
                    v = re.sub(r"^\s*(?:extern\s+)?", 'extern "C" ', v, count=1)
                decls[k] = v
    # one declared elsewhere in the file: changed there, in this worktree's
    # src/ (work.py checks the whole object, so a caller it breaks shows)
    srcp = ROOT / "src" / f"{name}.cpp"
    stext = srcp.read_text(encoding="utf8")
    inblock = {proto_name(d) for d in decls}
    for n, v in changed.items():
        if n in inblock or n == fn:
            continue
        m = re.search(rf"^(extern\s+\"C\"\s+)?([^\n;{{}}#]*\b{re.escape(n)}\s*\([^;{{}}]*\)[^;{{}}\n]*;)[ \t]*$", stext, re.M)
        if not m:
            continue
        new = v.strip().replace("(int, ...)", "(...)").replace("__attribute__((ror_nothrow))", "ASM_NOTHROW")
        new = re.sub(r"^\s*extern\s+", "", new)
        if re.sub(r"\s+", " ", plain_c(m.group(2))) != re.sub(r"\s+", " ", plain_c(new)):
            stext = stext[:m.start()] + (m.group(1) or "") + ("" if m.group(1) or new.startswith("extern") else "extern ") + new + stext[m.end():]
    srcp.write_text(stext, encoding="utf8", newline="\n")
    scratch = work.WORK / name / f"{fn}.cpp"
    subprocess.run([sys.executable, "tools/work.py", name, fn], cwd=ROOT, capture_output=True, text=True)
    head = scratch.read_text(encoding="utf8").split(work.FUNC, 1)[0]
    # work.py may have put some of them in the scratch file's declarations
    # already (a struct twice is an error): only the ones it lacks
    flat = re.sub(r"\s+", " ", head.split(work.DECL, 1)[-1])   # the declarations, not the comments
    decls = [d for d in decls if re.sub(r"\s+", " ", d.strip()) not in flat]
    scratch.write_text(head + work.FUNC + "\n" + "\n".join(decls) + "\nextern \"C\" " + func + "\n",
                       encoding="utf8", newline="\n")
    r = subprocess.run([sys.executable, "tools/work.py", name, fn], cwd=ROOT, capture_output=True, text=True)
    st = re.search(rf"^  0x[0-9A-F]+ {re.escape(fn)}\s+0x[0-9a-f]+\s+(.*)$", r.stdout, re.M)
    if not st or st.group(1).strip() != "MATCH":
        err = re.search(r"^\S+\.cpp:\d+: .*$", r.stdout + r.stderr, re.M)
        return "no match", "score 0, but work.py says " + (st.group(1).strip() if st else
                                                          "it does not compile: " + (err.group(0)[:120] if err else "?"))
    dn = subprocess.run([sys.executable, "tools/work.py", name, fn, "--done"], cwd=ROOT, capture_output=True, text=True)
    if dn.returncode:
        return "no match", "MATCH, but work.py --done refused it"
    subprocess.run(["git", "commit", "-q", "-m", f"{name}: {fn} (permuter)", "--", f"src/{name}.cpp"], cwd=ROOT)
    return "MATCH", None


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name", nargs="?")
    ap.add_argument("function", nargs="?")
    ap.add_argument("--minutes", type=float, default=10)
    ap.add_argument("--jobs", type=int, default=14)
    ap.add_argument("--queue", action="store_true", help="every attempt within --max-off, closest first")
    ap.add_argument("--max-off", type=int, default=12)
    ap.add_argument("--avoid", default="", help="skip files under these prefixes (another worker's), comma-separated")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--merge", action="store_true", help="merge each MATCH right away (tools/merge_worker.sh)")
    ap.add_argument("--prepare", action="store_true", help="only make the directory (to look at base.c)")
    ap.add_argument("--apply", action="store_true", help="take an earlier run's score-0 variant again")
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
        avoid = tuple(p for p in a.avoid.split(",") if p)
        jobs = [q for q in permute_queue.near_misses(a.max_off, set()) if (q[1], q[2]) not in done
                and not q[1].startswith(avoid or ("\0",))]
    if a.list:
        for off, name, fn, st in jobs:
            print(f"{off:4} off  {name} {fn}  ({st})")
        return
    if a.prepare:
        d, why = prepare(a.name, a.function)
        print(d or why)
        return
    if a.apply:
        zero = sorted((WORK / a.name / a.function / "out").glob("output-0-*"))
        print(apply_output(a.name, a.function, zero[0]) if zero else "no score-0 output")
        return
    # work.py must compile through this worktree's server: without it the old
    # compiler reads the Windows mount and dies ("init_c_lex")
    subprocess.run([sys.executable, "tools/match.py", "--server", "start"], cwd=ROOT, capture_output=True)
    print(f"queue: {len(jobs)}", flush=True)
    for k, (off, name, fn, st) in enumerate(jobs, 1):
        t0 = time.time()
        print(f"[{k}/{len(jobs)}] {name} {fn}: start ({st})", flush=True)
        status, best = run(name, fn, a.minutes, a.jobs)
        print(f"[{k}/{len(jobs)}] {name} {fn}: {status}, {best} ({(time.time() - t0) / 60:.1f} min)", flush=True)
        if status == "MATCH" and a.merge:
            main_dir = permute_queue.main_checkout()
            worker = ROOT.name.removeprefix("ror-wt-")
            m = subprocess.run(["sh", str(main_dir / "tools/merge_worker.sh"), worker, "--defer"],
                               cwd=main_dir, capture_output=True, text=True)
            print("  " + (m.stdout + m.stderr).strip().replace("\n", "\n  "), flush=True)
        if status != "skipped":
            LOG.parent.mkdir(parents=True, exist_ok=True)
            with open(LOG, "a") as log:
                log.write(f"{name} {fn} {a.minutes}\n")


if __name__ == "__main__":
    main()
