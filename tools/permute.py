#!/usr/bin/env python3
"""Search source variants of a near miss until it matches: a small
permuter for our C++ (decomp-permuter parses C only).

    tools/.venv/bin/python tools/permute.py game/gamman func_001BEDC0 --minutes 20

It starts from the function's best version so far (tools/work.py keeps it
in build/work/.best/; else its scratch file) and tries rewrites that can
change what ee-gcc 2.96 emits: swapping two neighbouring independent
statements (also two stores to different targets of one object) or
declarations, swapping the operands of a commutative operator (any
'X = A op B', two neighbouring terms of any sum or product), an && or a
comparison, signed/unsigned locals, inverting an if/else, for <-> while,
putting a repeated p->m or any subexpression in a temporary, inlining a
single-use temporary.
Every single rewrite is tried first, then random chains of them (a random
walk over variants no worse than the current one, back to the best after
300 tries without progress). Each variant is compiled with the compile
server (tools/match.py --server start) and scored by tools/work.py's score
(match.py's aligned edits).

Only a MATCH is trusted (the bytes prove it does what the game does): it is
written to the scratch file, ready for work.py --done, and as the best
version. A closer non-match is saved apart, in build/work/.best/<file>/
<function>.perm.cpp, since a rewrite may change what the code means.
"""
import argparse
import hashlib
import os

os.environ.setdefault("ROR_QUIET_HI16", "1")   # before match imports fix_hi16
import random
import re
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import work  # noqa: E402

SIMPLE = re.compile(r"^\s*[^\s{}#/][^{}]*;\s*$")             # one statement, no block
CONTROL = re.compile(r"^\s*(return|goto|break|continue|case|default|if|else|for|while|do|switch)\b|^\s*\w+:")
DECL = re.compile(r"^(\s*)((?:(?:unsigned|signed|const|volatile|register)\s+)*)(int|short|char|long)\b"
                  r"(\s*\**\s*[A-Za-z_]\w*(?:\s*\[[^\]]*\])?\s*;\s*)$")
OPERAND = r"(?:[A-Za-z_]\w*(?:(?:->|\.)\w+|\[[^\[\]]+\])*|\d+|0x[0-9A-Fa-f]+)"
COMMUTE = re.compile(rf"({OPERAND}) ([+*&|^]|==|!=) ({OPERAND})")
COMPARE = re.compile(rf"({OPERAND}) (<=|>=|<|>) ({OPERAND})")
FLIP = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}
IDENT = re.compile(r"[A-Za-z_]\w*")
KEYWORDS = {"int", "short", "char", "long", "unsigned", "signed", "return", "if", "else", "goto", "void"}


def body(lines):
    """Indexes of the lines inside the function's outermost braces."""
    start = next(i for i, ln in enumerate(lines) if "{" in ln) + 1
    return range(start, len(lines) - 1)


def alone(line, m):
    """Whether the match's neighbours bind less tightly than its operator, so
    swapping its operands keeps the meaning of the expression around it."""
    before, after = line[:m.start()].rstrip(), line[m.end():].lstrip()
    ok_before = before == "" or before.endswith(("(", "=", ",", "?", ":", "return", "&&", "||", "{", ";"))
    ok_after = after == "" or after.startswith((")", ";", ",", "?", ":", "&&", "||"))
    return ok_before and ok_after and not before.endswith(("==", "!=", "<=", ">="))


def idents(line):
    return set(IDENT.findall(line)) - KEYWORDS


def lhs(stmt):
    """The target of 'X = ...;' / 'X op= ...;' (top level), or None."""
    depth = 0
    for i, c in enumerate(stmt):
        depth += {"(": 1, "[": 1, ")": -1, "]": -1}.get(c, 0)
        if depth == 0 and c == "=" and stmt[i + 1:i + 2] != "=" and stmt[i - 1:i] not in ("=", "!", "<", ">"):
            j = i - 1 if stmt[i - 1:i] in "+-*/%&|^" and stmt[i - 1:i] else i
            if stmt[j - 1:j + 1] in ("<<", ">>"):
                j -= 1
            return stmt[:j].strip()
    return None


def uses(text, target):
    """Whether text mentions target (a whole name, or the same expression)."""
    if IDENT.fullmatch(target):
        return re.search(rf"\b{re.escape(target)}\b", text) is not None
    return target.replace(" ", "") in text.replace(" ", "")


def independent(a, b):
    """Two plain statements that can trade places: identifiers apart, or two
    stores whose targets the other one does not mention (stores to
    different fields of one object; the bytes decide the rest)."""
    if not idents(a) & idents(b):
        return True
    la, lb = lhs(a), lhs(b)
    if la is None or lb is None or la.replace(" ", "") == lb.replace(" ", ""):
        return False
    return not uses(b, la) and not uses(a, lb)


def swaps(lines):
    out = []
    for i in body(lines):
        a, b = lines[i], lines[i + 1] if i + 1 < len(lines) else ""
        if (SIMPLE.match(a) and SIMPLE.match(b) and not CONTROL.match(a) and not CONTROL.match(b)
                and not DECL.match(a) and not DECL.match(b) and independent(a.strip(), b.strip())):
            new = list(lines)
            new[i], new[i + 1] = b, a
            out.append(new)
    return out


def decl_swaps(lines):
    """Two neighbouring declarations in the other order (it can change which
    register a local gets)."""
    out = []
    pat = re.compile(r"^\s*(?:(?:unsigned|signed|const|volatile|register|struct)\s+)*[A-Za-z_]\w*[\s*]+[A-Za-z_]\w*"
                     r"(?:\s*\[[^\]]*\])?\s*(?:=\s*[^;]+)?;\s*$")
    for i in body(lines):
        a, b = lines[i], lines[i + 1] if i + 1 < len(lines) else ""
        if pat.match(a) and pat.match(b) and not CONTROL.match(a) and not CONTROL.match(b):
            na = re.findall(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*(?:=|;)", a)[:1]
            if na and "=" in b and re.search(rf"\b{na[0]}\b", b.split("=", 1)[1]):
                continue                      # b's initialiser reads a
            new = list(lines)
            new[i], new[i + 1] = b, a
            out.append(new)
    return out


def top_split(expr):
    """[(start, end, op)] of the operators at paren depth 0 of expr."""
    out, depth, i = [], 0, 0
    while i < len(expr):
        c = expr[i]
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= 1
        elif depth == 0 and expr[i:i + 3] in (" + ", " * ", " & ", " | ", " ^ ", " - ", " / ", " % ",
                                               " < ", " > ", " ? ", " : "):
            out.append((i, i + 3, expr[i + 1]))
            i += 3
            continue
        elif depth == 0 and expr[i:i + 4] in (" << ", " >> ", " && ", " || ", " == ", " != ", " <= ", " >= "):
            out.append((i, i + 4, expr[i + 1:i + 3]))
            i += 4
            continue
        i += 1
    return out


def wide_commutes(lines):
    """'X = A op B;' -> 'X = B op A;' for one commutative top-level operator,
    whatever A and B are (casts, calls, parentheses)."""
    out = []
    pat = re.compile(r"^(\s*[^=;]*?[^=!<>+\-*/%&|^]=\s*)([^;]+?)(;\s*)$")
    for i in body(lines):
        m = pat.match(lines[i])
        if not m or CONTROL.match(lines[i]):
            continue
        ops = top_split(m.group(2))
        if len(ops) == 1 and ops[0][2] in ("+", "*", "&", "|", "^"):
            s0, e0, _ = ops[0]
            rhs = m.group(2)
            new = list(lines)
            new[i] = f"{m.group(1)}{rhs[e0:].strip()} {ops[0][2]} {rhs[:s0].strip()}{m.group(3)}"
            if new[i] != lines[i]:
                out.append(new)
    return out


def regex_cands(lines, pattern, repl):
    out = []
    for i in body(lines):
        if lines[i].lstrip().startswith(("//", "#")):
            continue
        for m in pattern.finditer(lines[i]):
            if alone(lines[i], m):
                new = list(lines)
                new[i] = lines[i][:m.start()] + repl(m) + lines[i][m.end():]
                if new[i] != lines[i]:
                    out.append(new)
    return out


def commutes(lines):
    return regex_cands(lines, COMMUTE, lambda m: f"{m.group(3)} {m.group(2)} {m.group(1)}")


def compares(lines):
    return regex_cands(lines, COMPARE, lambda m: f"{m.group(3)} {FLIP[m.group(2)]} {m.group(1)}")


def ands(lines):
    """'if (A && B)' -> 'if (B && A)' for two plain conditions."""
    out = []
    pat = re.compile(r"\bif \(([^()&|]+(?:\([^()]*\))?[^()&|]*) (&&|\|\|) ([^()&|]+(?:\([^()]*\))?[^()&|]*)\)")
    for i in body(lines):
        for m in pat.finditer(lines[i]):
            new = list(lines)
            new[i] = lines[i][:m.start()] + f"if ({m.group(3)} {m.group(2)} {m.group(1)})" + lines[i][m.end():]
            out.append(new)
    return out


def signedness(lines):
    out = []
    for i in body(lines):
        m = DECL.match(lines[i])
        if not m or "const" in m.group(2):
            continue
        quals = m.group(2)
        quals = (quals.replace("unsigned ", "") if "unsigned" in quals else quals + "unsigned ")
        new = list(lines)
        new[i] = f"{m.group(1)}{quals}{m.group(3)}{m.group(4)}"
        out.append(new)
    return out


def block_end(text, open_brace):
    """Index of the '}' closing the '{' at open_brace."""
    depth, i = 0, open_brace
    while i < len(text):
        depth += {"{": 1, "}": -1}.get(text[i], 0)
        if depth == 0:
            return i
        i += 1
    return None


def invert_ifs(lines):
    """'if (c) {A} else {B}' -> 'if (!(c)) {B} else {A}'."""
    text, out = "\n".join(lines), []
    for m in re.finditer(r"\bif \(([^\n]*)\) \{\n", text):
        a_end = block_end(text, m.end() - 2)
        if a_end is None:
            continue
        e = re.match(r"\s*else \{\n", text[a_end + 1:])
        if not e:
            continue
        b_open = a_end + 1 + e.end() - 2
        b_end = block_end(text, b_open)
        if b_end is None:
            continue
        a, b = text[m.end():a_end], text[b_open + 2:b_end]
        new = text[:m.start()] + f"if (!({m.group(1)})) {{\n{b}{text[a_end:b_open + 2]}{a}" + text[b_end:]
        out.append(new.split("\n"))
    return out


def loops(lines):
    """'for (i; c; s) {B}' <-> 'i; while (c) {B s;}' (no continue inside)."""
    text, out = "\n".join(lines), []
    for m in re.finditer(r"^(\s*)for \(([^;\n]*); ([^;\n]*); ([^)\n]*)\) \{\n", text, re.M):
        end = block_end(text, m.end() - 2)
        if end is None or "continue" in text[m.end():end]:
            continue
        ind, init, cond, step = m.groups()
        head = (f"{ind}{init};\n" if init.strip() else "") + f"{ind}while ({cond or '1'}) {{\n"
        tail = f"{ind}    {step};\n" if step.strip() else ""
        out.append((text[:m.start()] + head + text[m.end():end] + tail + text[end:]).split("\n"))
    return out


def temps(lines):
    """Put a field read that appears twice or more in one temporary."""
    out, rng = [], body(lines)
    exprs = {}
    for i in rng:
        for m in re.finditer(r"\b[A-Za-z_]\w*->\w+\b(?!\s*\()", lines[i]):
            exprs.setdefault(m.group(0), []).append(i)
    for n, (expr, at) in enumerate(sorted(exprs.items())):
        if len(at) < 2 or any(re.search(re.escape(expr) + r"\s*[-+*/|&^]?=(?!=)", lines[i]) for i in at):
            continue
        first = at[0]
        ind = re.match(r"\s*", lines[first]).group(0)
        name = f"perm_t{n}"
        new = list(lines)
        for i in sorted(set(at)):
            new[i] = re.sub(re.escape(expr) + r"\b(?!\s*\()", name, new[i])
        new.insert(first, f"{ind}__typeof__({expr}) {name} = {expr};")
        out.append(new)
    return out


def inlines(lines):
    """'t = E; ... use(t)' -> 'use((E))' for a local assigned once, used once."""
    out = []
    text = "\n".join(lines[i] for i in body(lines))
    for i in body(lines):
        m = re.match(r"^\s*([A-Za-z_]\w*) = ([^;]+);\s*$", lines[i])
        if not m:
            continue
        v = m.group(1)
        uses = [j for j in body(lines) if j != i and re.search(rf"\b{v}\b", lines[j])
                and not DECL.match(lines[j])]
        if len(re.findall(rf"\b{v}\b", text)) != 2 + sum(1 for j in body(lines) if DECL.match(lines[j])
                                                          and re.search(rf"\b{v}\b", lines[j])) or len(uses) != 1:
            continue
        j = uses[0]
        if j < i:
            continue
        new = list(lines)
        new[j] = re.sub(rf"\b{v}\b", f"({m.group(2)})", lines[j], count=1)
        del new[i]
        out.append(new)
    return out


LOWER = ("<<", ">>", "<", ">", "<=", ">=", "==", "!=", "&", "^", "|", "&&", "||", "?", ":")


def spans(line):
    """(start, end) of every expression in the line: each parenthesised
    group's contents (split at its top-level commas) and what follows an
    '=' or 'return'."""
    out, stack = [], []
    for i, c in enumerate(line):
        if c in "([":
            stack.append(i)
        elif c in ")]" and stack:
            o = stack.pop()
            depth, start = 0, o + 1
            for j in range(o + 1, i + 1):
                ch = line[j]
                if ch in "([":
                    depth += 1
                elif ch in ")]":
                    depth -= 1
                if (ch == "," and depth == 0) or j == i:
                    out.append((start, j))
                    start = j + 1
    m = re.search(r"(?:[^=!<>+\-*/%&|^]=|\breturn)\s*(.+?);\s*$", line)
    if m:
        out.append((m.start(1), m.end(1)))
    return out


def term_swaps(lines):
    """In any sum (or product) whose operators bind tightest at its top
    level, two neighbouring '+' (or '*') terms in the other order:
    'A + B + 4' -> 'B + A + 4'. Inside casts, calls and dereferences too
    (func_0018C794: one addu's operand order)."""
    out = []
    for i in body(lines):
        line = lines[i]
        if line.lstrip().startswith(("//", "#")):
            continue
        for a, b in spans(line):
            expr = line[a:b]
            lead = len(expr) - len(expr.lstrip())
            core = expr.strip()
            ops = top_split(core)
            if not ops or any(op in LOWER for _, _, op in ops):
                continue
            for kind, also in (("+", "-"), ("*", "/%")):
                sel = [o for o in ops if o[2] == kind or o[2] in also]
                if not sel or (kind == "*" and any(o[2] in "+-" for o in ops)):
                    continue
                if kind == "+" and len(sel) != len([o for o in ops if o[2] in "+-"]):
                    continue
                cuts = [0] + [x for o in sel for x in (o[0], o[1])] + [len(core)]
                terms = [core[cuts[k]:cuts[k + 1]] for k in range(0, len(cuts), 2)]
                signs = [kind] + [o[2] for o in sel]
                for k in range(len(terms) - 1):
                    if signs[k + 1] != kind or (k > 0 and signs[k] != kind):
                        continue
                    t = list(terms)
                    t[k], t[k + 1] = t[k + 1], t[k]
                    new_core = t[0] + "".join(f" {signs[n]} {t[n]}" for n in range(1, len(t)))
                    if new_core == core:
                        continue
                    new = list(lines)
                    new[i] = line[:a] + expr[:lead] + new_core + expr[lead + len(core):] + line[b:]
                    out.append(new)
    return out


def extracts(lines):
    """A subexpression of a plain statement (a sum, product, shift, call
    argument...) computed first into a temporary of the same type:
    'f(a + b);' -> '__typeof__(a + b) perm_e = a + b; f(perm_e);'. It can
    change which register holds it, as decomp-permuter's temporaries do."""
    out = []
    for i in body(lines):
        line = lines[i]
        if not SIMPLE.match(line) or CONTROL.match(line) or DECL.match(line):
            continue
        ind = re.match(r"\s*", line).group(0)
        for a, b in spans(line):
            expr = line[a:b].strip()
            if not top_split(expr) or "=" in expr.replace("==", "").replace("!=", "").replace("<=", "").replace(">=", ""):
                continue                      # a plain name, or an assignment inside
            if "++" in expr or "--" in expr:
                continue
            k = line.index(expr, a)
            name = f"perm_e{sum('perm_e' in ln for ln in lines)}"
            new = list(lines)
            new[i] = line[:k] + name + line[k + len(expr):]
            new.insert(i, f"{ind}__typeof__({expr}) {name} = {expr};")
            out.append(new)
    return out


# ---- Rewrites from the near misses matched by hand (notes/research/R23):
# the callee's exception spec, the shape of the control flow, register pins.

# Lines "//@nothrow NAME" before the function's signature ask for NAME's
# declarations in the file to have their throw() (or ASM_NOTHROW) toggled:
# with -fno-exceptions, g++ 2.96 schedules a call to a function it knows
# cannot throw differently (a bnel/beql vs bne/beq, a delay slot).
MARK = "//@nothrow "
TOGGLE = set()      # callees whose declarations the file has (set in main)
REGS = []           # registers worth pinning a local to (set in main)


# a parameter list: its own parentheses (one level inside, for function
# pointers), not those of an asm("label") after it
PARAMS = r"\([^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*\)"


def proto_re(callee):
    return re.compile(rf"^(?P<pre>[A-Za-z_][^;{{}}\n]*\b{re.escape(callee)}\s*{PARAMS}(?:\s*const)?)"
                      rf"(?P<spec>\s*(?:ASM_NOTHROW|throw\s*\(\s*\)))?(?P<post>[^;{{}}\n]*;)", re.M)


def toggled(text):
    """The assembled file with every //@nothrow mark applied."""
    for callee in re.findall(rf"^\s*{re.escape(MARK)}(\w+)\s*$", text, re.M):
        text = proto_re(callee).sub(lambda m: m.group("pre") + flip_spec(m.group("spec"), m.group("post")), text)
    return text


def flip_spec(spec, post):
    """The declaration's tail with throw() taken out, or put in before an
    asm("label") (the exception spec belongs to the declarator)."""
    if spec:
        return post
    a = re.search(r"\s*(?:__asm__|asm)\s*\(", post)
    return (post[:a.start()] + " throw()" + post[a.start():]) if a else " throw()" + post


def nothrows(lines):
    """Toggle one callee's exception spec (add a mark, or drop one)."""
    marked = {ln.strip()[len(MARK):] for ln in lines if ln.strip().startswith(MARK)}
    called = set(re.findall(r"\b([A-Za-z_]\w*)\s*\(", "\n".join(lines[i] for i in body(lines))))
    out = []
    for callee in sorted((called & TOGGLE) - marked):
        out.append([MARK + callee] + list(lines))
    for i, ln in enumerate(lines):
        if ln.strip().startswith(MARK):
            out.append(lines[:i] + lines[i + 1:])
    return out


def dedent(block, n=4):
    return "\n".join(ln[n:] if ln.startswith(" " * n) else ln for ln in block.split("\n"))


def indent(block, n=4):
    return "\n".join((" " * n + ln) if ln.strip() else ln for ln in block.split("\n"))


def early_returns(lines):
    """'if (c) { BODY } return X; }' at the end <-> 'if (!(c)) return X; BODY return X; }',
    and 'if (c) return X; REST }' -> 'if (!(c)) { REST } return X; }'."""
    text, out = "\n".join(lines), []
    # nested -> early return: the function ends with the if's block and a return
    for m in re.finditer(r"^(\s+)if \(([^\n]*)\) \{\n", text, re.M):
        end = block_end(text, m.end() - 2)
        if end is None:
            continue
        rest = re.match(rf"\}}\n({re.escape(m.group(1))}return\b[^;\n]*;)\n\}}\s*$", text[end:])
        if not rest or re.match(r"\s*else\b", text[end + 1:]):
            continue
        ret = rest.group(1).strip()
        blk = text[m.end():end].rstrip()
        new = (text[:m.start()] + f"{m.group(1)}if (!({m.group(2)})) {ret}\n" + dedent(blk) + "\n"
               + rest.group(1) + "\n}")
        out.append(new.split("\n"))
    # early return -> nested: 'if (c) return X;' then the rest of the function
    for m in re.finditer(r"^(\s+)if \(([^\n]*)\) (return\b[^;\n]*;)\n", text, re.M):
        rest = text[m.end():]
        if not rest.rstrip().endswith("}") or not re.match(rf"{re.escape(m.group(1))}\S", rest):
            continue
        tail = rest.rstrip()[:-1].rstrip("\n")       # up to the function's closing brace
        if "\n}" in tail or re.search(rf"^{re.escape(m.group(1))}\w+:", tail, re.M):
            continue                                # another top-level block or a label: unsafe
        new = (text[:m.start()] + f"{m.group(1)}if (!({m.group(2)})) {{\n" + indent(tail) + "\n"
               + f"{m.group(1)}}}\n{m.group(1)}{m.group(3)}\n}}")
        out.append(new.split("\n"))
    return out


def shared_returns(lines):
    """Two or more 'return K;' of one constant: all but the last become
    'goto perm_ret;' and the last gets the label (one shared exit block)."""
    out = []
    by = {}
    for i in body(lines):
        m = re.match(r"^(.*?)\breturn ?(-?(?:0x[0-9A-Fa-f]+|\d+)|[A-Za-z_]\w*)?;\s*$", lines[i])
        if m and "//" not in m.group(1):
            by.setdefault(m.group(2) or "", []).append(i)
    for k, at in by.items():
        if len(at) < 2:
            continue
        new = list(lines)
        last = at[-1]
        ind = re.match(r"\s*", lines[last]).group(0)
        if not re.match(r"^\s*return\b", lines[last]):
            continue                      # the last one must be a plain statement to take the label
        for i in at[:-1]:
            new[i] = re.sub(r"\breturn ?[^;]*;\s*$", "goto perm_ret;", lines[i])
        new[last] = f"perm_ret:\n{ind}return{' ' + k if k else ''};"
        out.append("\n".join(new).split("\n"))
    return out


def do_whiles(lines):
    """'for (i; c; s) {B}' -> 'i; if (c) { do { B s; } while (c); }' and
    'while (c) {B}' -> 'if (c) { do {B} while (c); }' (no continue in B)."""
    text, out = "\n".join(lines), []
    for m in re.finditer(r"^(\s*)(?:for \(([^;\n]*); ([^;\n]+); ([^)\n]*)\)|while \(([^\n]+)\)) \{\n", text, re.M):
        end = block_end(text, m.end() - 2)
        if end is None or "continue" in text[m.end():end]:
            continue
        ind, init, cond, step, wcond = m.groups()
        cond = cond or wcond
        blk = text[m.end():end].rstrip()
        head = (f"{ind}{init};\n" if init and init.strip() else "")
        body_ = indent(blk) + (f"\n{ind}        {step};" if step and step.strip() else "")
        new = (text[:m.start()] + head + f"{ind}if ({cond}) {{\n{ind}    do {{\n" + body_ + "\n"
               + f"{ind}    }} while ({cond});\n{ind}" + text[end:])
        out.append(new.split("\n"))
    return out


PIN = re.compile(r'\s*PS2_REG\("[^"]*"\)')
LOCAL = re.compile(r"^(\s+)((?:(?:const|unsigned|signed)\s+)*"
                   r"(?:int|short|char|long|float|u_int|u_short|u_char|u_long|s32|u32|s16|u16|s8|u8|"
                   r"[A-Z]\w*\s*\*|void\s*\*|char\s*\*|int\s*\*|float\s*\*)\s*\**)\s*([A-Za-z_]\w*)(\s*=\s*[^;]+)?;\s*$")


def pins(lines):
    """Drop one register pin, or pin one local to a callee-saved register
    the game's function uses ($16-$23, $f20-$f30)."""
    out = []
    for i in body(lines):
        if 'PS2_REG("' in lines[i]:
            new = list(lines)
            new[i] = re.sub(r"\bregister\s+", "", PIN.sub("", lines[i]), count=1)
            out.append(new)
            continue
        m = LOCAL.match(lines[i])
        if not m or CONTROL.match(lines[i]) or "register" in lines[i]:
            continue
        ind, typ, var, init = m.group(1), m.group(2).strip(), m.group(3), m.group(4) or ""
        flt = typ.startswith("float") and "*" not in typ
        for r in REGS:
            if r.startswith("$f") != flt:
                continue
            new = list(lines)
            new[i] = f'{ind}register {typ} {var} PS2_REG("{r}"){init};'
            out.append(new)
    return out


def game_regs(name, fn):
    """Callee-saved registers the game's function uses, as PS2_REG names."""
    p = match.ROOT / "asm" / "nonmatchings" / name / f"{fn}.s"
    try:
        s = p.read_text(errors="replace")
    except OSError:
        return []
    # splat writes registers by number ($16) or by name ($s0)
    gp = {int(n) for n in re.findall(r"\$(1[6-9]|2[0-3])\b", s)} | {16 + int(n) for n in re.findall(r"\$s([0-7])\b", s)}
    fp = sorted({int(n) for n in re.findall(r"\$f(\d+)\b", s) if 20 <= int(n) <= 30})
    # and the temporaries it uses most ($2-$15, $24, $25): hand matches pinned
    # those too (a value that must sit in $v1 or $a2)
    temps = {}
    for n in re.findall(r"\$(\d+)\b", s):
        n = int(n)
        if 2 <= n <= 15 or n in (24, 25):
            temps[n] = temps.get(n, 0) + 1
    top = [n for n, _ in sorted(temps.items(), key=lambda kv: -kv[1])[:6]]
    return [f"${n}" for n in sorted(gp)] + [f"${n}" for n in top] + [f"$f{n}" for n in fp]


def file_callees(name, fn):
    """Names with a one-line prototype in src/<name>.cpp and no definition
    there (g++ already knows a function it compiled cannot throw)."""
    text = (match.ROOT / "src" / f"{name}.cpp").read_text(encoding="utf8", errors="replace")
    protos = set(re.findall(rf"^[A-Za-z_][^;{{}}\n]*?\b([A-Za-z_]\w*)\s*{PARAMS}[^;{{}}\n]*;", text, re.M))
    defined = set(re.findall(rf"^[A-Za-z_][^;{{}}\n]*?\b([A-Za-z_]\w*)\s*{PARAMS}\s*(?:const\s*)?\n?\{{", text, re.M))
    return protos - defined - {fn}


INLINE = {}         # method -> [(class, [param names], body statement)] (set in main)


def header_inlines(name):
    """One-statement inline methods of the classes the file sees (its own
    text and the src/ headers it includes, one level deep)."""
    import perm_official as po
    src = match.ROOT / "src"
    text = (src / f"{name}.cpp").read_text(encoding="utf8", errors="replace")
    texts = [text]
    for inc in re.findall(r'^#\s*include\s+"([^"]+)"', text, re.M):
        for p in (src / inc, src / Path(name).parent / inc):
            if p.exists():
                texts.append(p.read_text(encoding="utf8", errors="replace"))
                break
    out = {}
    for t in texts:
        # without preprocessor lines: an include guard would make the whole
        # header one #if block for top_items
        t = "\n".join(ln for ln in t.split("\n") if not ln.lstrip().startswith("#"))
        for kind, it in po.top_items(t):
            m = re.match(r"\s*(?:class|struct)\s+([A-Za-z_]\w*)\s*(?::[^{]*)?\{(.*)\}\s*;\s*$", it, re.S)
            if not m:
                continue
            for mem in po.members(re.sub(r"\b(public|private|protected)\s*:", "", m.group(2))):
                g = re.match(r"^[^{;()]*?\b([A-Za-z_]\w*)\s*\(([^(){};]*)\)\s*(?:const\s*)?\{\s*([^{};]*;)\s*\}$", mem, re.S)
                if not g or re.search(r"\b(virtual|static)\b", mem.split("(")[0]):
                    continue
                params = [p.split()[-1].lstrip("*&") for p in g.group(2).split(",") if p.strip() and p.strip() != "void"]
                out.setdefault(g.group(1), []).append((m.group(1), params, " ".join(g.group(3).split())))
    return out


def inline_calls(lines):
    """'X->m(a)' as m's one-statement inline body with this = X: a whole
    statement for a void method, the returned expression for the others."""
    out = []
    for i in body(lines):
        line = lines[i]
        for mm in re.finditer(r"([A-Za-z_]\w*(?:(?:->|\.)\w+|\[[^\[\]]+\])*)\s*(->|\.)\s*([A-Za-z_]\w*)\s*\(([^()]*)\)", line):
            for cls, params, stmt in INLINE.get(mm.group(3), [])[:2]:
                args = [a.strip() for a in mm.group(4).split(",") if a.strip()]
                if len(args) != len(params):
                    continue
                recv = mm.group(1) if mm.group(2) == "->" else f"(&{mm.group(1)})"
                s = stmt
                for p, a in zip(params, args):
                    s = re.sub(rf"\b{re.escape(p)}\b", f"({a})", s)
                s = re.sub(r"\bthis\s*->", f"{recv}->", s)
                # the class's own names: anything not a call, a param, a literal or after -> / .
                s = re.sub(r"(?<![\w.>])\b(m_\w+)\b", rf"{recv}->\1", s)
                new = list(lines)
                if s.startswith("return "):
                    new[i] = line[:mm.start()] + f"({s[7:].rstrip(';').strip()})" + line[mm.end():]
                elif line.strip() == mm.group(0) + ";":
                    new[i] = re.match(r"\s*", line).group(0) + s
                else:
                    continue
                out.append(new)
    return out


def retypes(lines):
    """'X->f op= v;' with the field read as int or unsigned int: the
    signedness of a flag field changes ori/xori and the shifts g++ picks."""
    out = []
    for i in body(lines):
        m = re.match(r"^(\s*)([A-Za-z_]\w*(?:(?:->|\.)\w+)+)\s*(\|=|&=|\^=|\+=|-=)\s*(.+;)\s*$", lines[i])
        if not m:
            continue
        for t in ("int", "unsigned int"):
            new = list(lines)
            new[i] = f"{m.group(1)}(*({t} *)&{m.group(2)}) {m.group(3)} {m.group(4)}"
            out.append(new)
    return out


MUTATIONS = [swaps, commutes, compares, ands, signedness, invert_ifs, loops, temps, inlines,
             decl_swaps, wide_commutes, term_swaps, extracts,
             nothrows, early_returns, shared_returns, do_whiles, pins, inline_calls, retypes]


def split(work_text):
    head, func = work_text.split(work.FUNC, 1)
    return head + work.FUNC + "\n", func.strip("\n")


def status_of(name, fn, path, slot, sync):
    """The check's status text for one variant, or None if it does not compile."""
    trial = work.WORK / name / f"{fn}.perm{slot}.trial.cpp"
    trial.write_text(toggled(work.assemble(name, fn, path)), encoding="utf8", newline="\n")
    try:
        _, report = match.compare(name, trial, diff=False, sync=sync)
    except match.CompileError:
        return None
    for line in report:
        g = re.match(r"^  0x[0-9A-F]+ (\S+)\s+0x[0-9a-f]+\s+(.*)$", line)
        if g and g.group(1) == fn:
            return g.group(2).strip()
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("name")
    ap.add_argument("function")
    ap.add_argument("--minutes", type=float, default=15)
    ap.add_argument("--jobs", type=int, default=4, help="compiles at once")
    ap.add_argument("--seed", type=int)
    a = ap.parse_args()
    name, fn = a.name.removeprefix("src/").removesuffix(".cpp"), a.function
    if not match.server_up():
        sys.exit("start the compile server first: tools/match.py --server start")
    best_file = work.BEST / name / f"{fn}.cpp"
    near_file = work.BEST / name / f"{fn}.perm.cpp"
    scratch = work.WORK / name / f"{fn}.cpp"
    if best_file.exists():
        start = best_file.read_text(encoding="utf8").split("\n", 1)[1]
    elif scratch.exists():
        start = scratch.read_text(encoding="utf8")
    else:
        sys.exit(f"nothing to start from: run tools/work.py {name} {fn} first")
    head, func = split(start)
    TOGGLE.update(file_callees(name, fn))
    REGS.extend(game_regs(name, fn))
    INLINE.update(header_inlines(name))
    rng = random.Random(a.seed)
    slots = [work.WORK / name / f"{fn}.perm{i}.cpp" for i in range(a.jobs)]
    seen = set()

    def run(slot, lines, sync=False):
        slots[slot].write_text(head + "\n".join(lines) + "\n", encoding="utf8", newline="\n")
        return status_of(name, fn, slots[slot], slot, sync)

    def fresh(lines):
        h = hashlib.sha1("\n".join(lines).encode()).digest()
        if h in seen:
            return False
        seen.add(h)
        return True

    base = func.split("\n")
    fresh(base)
    st = run(0, base, sync=True)
    if st is None:
        sys.exit("the starting version does not compile")
    best, best_score = base, work.score(st)
    cur, cur_score = base, best_score
    print(f"start: {st}")
    tries = since = 0
    t0 = time.time()
    end = t0 + a.minutes * 60
    # Every single rewrite of the start first, then random chains.
    queue = [c for mut in MUTATIONS for c in mut(base) if fresh(c)]
    rng.shuffle(queue)
    print(f"{len(queue)} single rewrites")

    def next_variant():
        if queue:
            return queue.pop()
        for _ in range(50):
            lines = list(cur)
            for _ in range(rng.choice((1, 1, 2, 3))):
                cands = rng.choice(MUTATIONS)(lines)
                if cands:
                    lines = rng.choice(cands)
            if fresh(lines):
                return lines
        return None

    with ThreadPoolExecutor(a.jobs) as pool:
        while time.time() < end and best_score > 0:
            batch = [v for v in (next_variant() for _ in range(a.jobs)) if v is not None]
            if not batch:
                break
            results = list(pool.map(lambda p: (p[1], run(p[0], p[1])), enumerate(batch)))
            tries += len(batch)
            since += len(batch)
            for lines, st in results:
                if st is None:
                    continue
                s = work.score(st)
                if s <= cur_score:
                    cur, cur_score = lines, s
                if s < best_score:
                    best, best_score, since = lines, s, 0
                    print(f"{tries:6} tries  {st}")
                    near_file.parent.mkdir(parents=True, exist_ok=True)
                    near_file.write_text(f"// best: {st}\n" + head + "\n".join(best) + "\n",
                                         encoding="utf8", newline="\n")
            if since >= 300:                      # stuck: back to the best
                cur, cur_score, since = best, best_score, 0
    for p in slots:
        for q in (p, p.with_name(p.stem + ".trial.cpp")):
            q.unlink(missing_ok=True)
    why = "" if time.time() >= end or best_score == 0 else " (no rewrite left to try)"
    print(f"{tries} tries in {(time.time() - t0) / 60:.1f} min{why}; best: {best_score} off")
    if best_score == 0:
        marks = [ln for ln in best if ln.strip().startswith(MARK)]
        if marks:
            # the match needs those declarations toggled in the file itself:
            # done here, in the worktree's src/ (work.py --done checks it with
            # them), and the marks leave the function
            src = match.ROOT / "src" / f"{name}.cpp"
            src.write_text(toggled("\n".join(marks) + "\n" + src.read_text(encoding="utf8"))
                           .split("\n", len(marks))[len(marks)], encoding="utf8", newline="\n")
            # and in the scratch file itself: its declarations and the lines
            # above the function's signature (work.py copies there those of
            # the attempt's NON_MATCHING block)
            head = toggled("\n".join(marks) + "\n" + head).split("\n", len(marks))[len(marks)]
            best = toggled("\n".join(best)).split("\n")
            best = [ln for ln in best if not ln.strip().startswith(MARK)]
            print("declarations toggled in src/: " + ", ".join(m.strip()[len(MARK):] for m in marks))
        text = head + "\n".join(best) + "\n"
        scratch.parent.mkdir(parents=True, exist_ok=True)
        scratch.write_text(text, encoding="utf8", newline="\n")
        best_file.write_text("// best: MATCH\n" + text, encoding="utf8", newline="\n")
        near_file.unlink(missing_ok=True)
        print(f"MATCH, written to {scratch.relative_to(work.ROOT)}: tools/work.py {name} {fn} --done")


if __name__ == "__main__":
    main()
