#!/usr/bin/env python3
"""Put a source file's asserts back on their original lines.

    tools/.venv/bin/python tools/pad_asserts.py src/dog/dogmotionblend.cpp 83,84,87,113,...

Give the original __LINE__ of every ASSERT/ASSERT_S in the file, in order
(tools/asserts.py <file>.cpp lists them). Blank lines are added right
before each assert that is too early; an assert that is already too late
is reported, and the code before it has to get shorter. Move the blank
lines somewhere tidier afterwards (above the function, when the assert is
its first statement); only the assert lines matter.
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
        if i + 1 > want:
            late += 1
            print(f"assert {k + 1} ({lines[i].strip()}) is on line {i + 1}, wanted {want}")
        elif i + 1 < want:
            lines[i:i] = [""] * (want - i - 1)
    open(path, "w").write("\n".join(lines))
    sys.exit(1 if late else 0)


if __name__ == "__main__":
    main()
