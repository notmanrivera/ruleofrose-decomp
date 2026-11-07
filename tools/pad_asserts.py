#!/usr/bin/env python3
"""Put a source file's asserts back on their original lines.

    tools/.venv/bin/python tools/pad_asserts.py src/dog/dogmotionblend.cpp 83,84,87,113,...

Give the original __LINE__ of every ASSERT/ASSERT_S in the file, in order
(tools/asserts.py <file>.cpp lists them). Blank lines are added right
before each assert that is too early; for one that is too late, blank
lines between it and the previous assert are removed (the last ones
first). If there are not enough, it is reported, and the code before it
has to get shorter. Blank lines between a function's opening brace and
its first assert then move above the function's comment; only the assert
lines matter.
"""
import re
import sys


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    path, targets = sys.argv[1], [int(x) for x in sys.argv[2].split(",")]
    lines = open(path).read().split("\n")

    def asserts():
        return [i for i, l in enumerate(lines) if re.match(r"\s*ASSERT(_S)?\(", l)]

    if len(asserts()) != len(targets):
        sys.exit(f"{len(asserts())} asserts in the file, {len(targets)} lines given")
    late = 0
    for k, want in enumerate(targets):
        i = asserts()[k]
        lo = asserts()[k - 1] + 1 if k else 0
        extra = i + 1 - want
        for j in range(i - 1, lo - 1, -1):
            if extra <= 0:
                break
            if not lines[j].strip():
                del lines[j]
                extra -= 1
        i = asserts()[k]
        if i + 1 > want:
            late += 1
            print(f"assert {k + 1} ({lines[i].strip()}) is on line {i + 1}, wanted {want}")
        elif i + 1 < want:
            lines[i:i] = [""] * (want - i - 1)
    tidy(lines)
    open(path, "w", newline="\n").write("\n".join(lines))
    sys.exit(1 if late else 0)


def tidy(lines):
    """Moves the blank lines between a function's `{` and its first assert
    above the function's leading comment."""
    i = 0
    while i < len(lines):
        if lines[i] == "{" and i > 0 and lines[i - 1] and not lines[i - 1].startswith((" ", "//", "#")):
            j = i + 1
            blanks = []
            while j < len(lines) and lines[j] != "}" and not re.match(r"\s*ASSERT(_S)?\(", lines[j]):
                if not lines[j].strip():
                    blanks.append(j)
                j += 1
            if j < len(lines) and lines[j] != "}" and blanks:
                for b in reversed(blanks):
                    del lines[b]
                k = i - 1
                while k > 0 and lines[k - 1].startswith("//"):
                    k -= 1
                lines[k:k] = [""] * len(blanks)
                i += len(blanks)
        i += 1


if __name__ == "__main__":
    main()
