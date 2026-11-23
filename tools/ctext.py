#!/usr/bin/env python3
"""C/C++ source text helpers that respect string and character literals and
comments: brace matching and substitutions done on the code only.

    mask(text)            the text with the inside of every literal and
                          comment blanked (same length and line breaks), for
                          finding braces, semicolons and names by index
    code_sub(p, r, text)  re.sub on the code only, literals and comments as
                          they were ("Status 3" keeps its 3, "a { b" its brace)
    block_end(text, i)    index of the '}' closing the '{' at i, or None
"""
import re

LITERAL = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)


def mask(text):
    def blank(m):
        s = m.group(0)
        if s.startswith(("//", "/*")):
            return re.sub(r"[^\n]", " ", s)
        return s[0] + re.sub(r"[^\n]", " ", s[1:-1]) + s[-1]
    return LITERAL.sub(blank, text)


def code_sub(pattern, repl, text, count=0, flags=0):
    """re.sub applied to the code between literals and comments only."""
    out, pos, n = [], 0, 0
    pat = re.compile(pattern, flags) if isinstance(pattern, str) else pattern
    for m in LITERAL.finditer(text):
        seg = text[pos:m.start()]
        if count and n >= count:
            out.append(seg)
        else:
            seg, k = pat.subn(repl, seg, count=(count - n) if count else 0)
            n += k
            out.append(seg)
        out.append(m.group(0))
        pos = m.end()
    seg = text[pos:]
    if not count or n < count:
        seg = pat.sub(repl, seg, count=(count - n) if count else 0)
    out.append(seg)
    return "".join(out)


def block_end(text, i, masked=None):
    """Index of the '}' closing the '{' at text[i] (literals and comments
    skipped), or None."""
    t = masked if masked is not None else mask(text)
    depth = 0
    for j in range(i, len(t)):
        if t[j] == "{":
            depth += 1
        elif t[j] == "}":
            depth -= 1
            if depth == 0:
                return j
    return None
