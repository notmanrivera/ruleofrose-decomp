#!/usr/bin/env python3
"""Try source variants of a function and report how each one compiles.

    tools/.venv/bin/python tools/try_variants.py bed/bedmemory init variants.json
    tools/.venv/bin/python tools/try_variants.py bed/bedmemory init variants.json --extra=-DNON_MATCHING

variants.json maps a variant name to a list of [old, new] text
replacements for src/<file>.cpp:

    {"swap": [["    a = 1;\\n    b = 2;\\n", "    b = 2;\\n    a = 1;\\n"]]}

Each variant is compiled and compared with tools/match.py; the status of
every function whose name contains the given text is printed. The source
file is restored at the end. Generate the JSON with a few lines of Python
to try all orders of some statements (itertools.permutations) or several
expression shapes. Keep the line count unchanged, or the ASSERT line
numbers move. --extra passes compiler flags on to match.py, e.g.
-DNON_MATCHING for a function kept under #ifdef NON_MATCHING.
"""
import json
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--extra=")]
    extra = [a for a in sys.argv[1:] if a.startswith("--extra=")]
    if len(args) != 3:
        sys.exit(__doc__)
    name, func, variants = args[0], args[1], json.loads(Path(args[2]).read_text())
    src = ROOT / "src" / f"{name}.cpp"
    orig = src.read_text()
    try:
        for vname, reps in variants.items():
            text = orig
            for old, new in reps:
                if old not in text:
                    sys.exit(f"{vname}: text not found: {old[:60]!r}")
                text = text.replace(old, new)
            src.write_text(text)
            time.sleep(1.5)  # Docker's file sharing on macOS can lag behind the write
            r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), name] + extra,
                               capture_output=True, text=True, cwd=ROOT)
            lines = [l.split(None, 2)[2] for l in r.stdout.splitlines()
                     if l.startswith("  0x") and func in l]
            print(f"{vname:14} " + ("; ".join(lines) if lines else "ERROR " + (r.stdout + r.stderr)[-300:]),
                  flush=True)
    finally:
        src.write_text(orig)


if __name__ == "__main__":
    main()
