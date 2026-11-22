#!/usr/bin/env python3
"""Try source variants of a function and report how each one compiles.

    tools/.venv/bin/python tools/try_variants.py bed/bedmemory init variants.json
    tools/.venv/bin/python tools/try_variants.py bed/bedmemory init variants.json --extra=-DNON_MATCHING

variants.json maps a variant name to a list of [old, new] text
replacements for src/<file>.cpp:

    {"swap": [["    a = 1;\n    b = 2;\n", "    b = 2;\n    a = 1;\n"]]}

Each old text must occur exactly once in the file (add context until it
does). Each variant is written to a copy of its own under build/variants/
(named by process and variant, so several runs can go on at once) and
compiled from there with tools/match.py: src/<file>.cpp is only read, never
written. The status of every function whose name contains the given text is
printed. Generate the JSON with a few lines of Python to try all orders of
some statements (itertools.permutations) or several expression shapes. Keep
the line count unchanged, or the ASSERT line numbers move. --extra passes
compiler flags on to match.py, e.g. -DNON_MATCHING for a function kept
under #ifdef NON_MATCHING.
"""
import json
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402


def apply(text, reps):
    """The text with the replacements made, or the reason it can't be."""
    for old, new in reps:
        n = text.count(old)
        if n != 1:
            return None, f"text found {n} times (must be once): {old[:60]!r}"
        text = text.replace(old, new)
    return text, None


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--extra=")]
    extra = " ".join(a.removeprefix("--extra=") for a in sys.argv[1:] if a.startswith("--extra="))
    if len(args) != 3:
        sys.exit(__doc__)
    name, func, variants = args[0], args[1], json.loads(Path(args[2]).read_text())
    orig = (ROOT / "src" / f"{name}.cpp").read_text()
    tmpdir = ROOT / "build" / "variants"
    tmpdir.mkdir(parents=True, exist_ok=True)
    failed = 0
    for i, (vname, reps) in enumerate(variants.items()):
        text, why = apply(orig, reps)
        if text is None:
            print(f"{vname:14} SKIPPED {why}", flush=True)
            failed += 1
            continue
        src = tmpdir / f"tv{os.getpid()}_{i}.cpp"
        src.write_text(text)
        try:
            ok, report = match.compare(name, source=str(src), extra=extra)
            lines = [l.split(None, 2)[2] for l in report if l.startswith("  0x") and func in l]
            print(f"{vname:14} " + ("; ".join(lines) if lines else f"no function matching {func!r}"),
                  flush=True)
        except match.CompileError as e:
            print(f"{vname:14} COMPILE ERROR " + str(e)[-300:].replace("\n", " "), flush=True)
            failed += 1
        finally:
            src.unlink(missing_ok=True)
            obj = ROOT / "build" / "match" / f"{name}.{src.stem}.o"
            obj.unlink(missing_ok=True)
    sys.exit(1 if failed == len(variants) else 0)


if __name__ == "__main__":
    main()
