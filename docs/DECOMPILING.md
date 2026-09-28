# Decompiling a file

The loop for turning one original source file back into matching C++.
Whole files only for now: a file's code and data switch from asm to the
compiled object together (partial files need `INCLUDE_ASM`, not set up yet).

## 1. Pick a file

`config/splits.tsv` lists every file with its `.text`/`.rodata`/`.data`/`.bss`
starts. Small game files with real names (from assert paths) are the easiest.
`tools/.venv/bin/python tools/progress.py` shows what is done.

## 2. Draft it

```bash
tools/.venv/bin/python -m m2c.main -t mips-gcc-c++ asm/<file>.s
```

Ghidra (`tools/ghidra_setup.sh`) helps with types and callers. Useful facts
straight from the binary:

- **Asserts**: a call to `ror_assert` (0x00215A30) passes the file path,
  the `__LINE__` (`addiu $a1, $zero, <line>`) and the expression text.
  Reproduce them with `ASSERT(expr)` on exactly that source line (pad with
  blank lines); the expression text is in the file's `.rodata`.
- **Member and parameter names** often appear in those expressions
  (`m_depth < MAX_STACK`, `theName`).
- `lq`/`sq` are 128-bit copies: `u_long128` (see `include/ror.h`).

## 3. Match it

Write `src/<file>.cpp` (and a header under `src/` if other code needs the
types), then:

```bash
tools/.venv/bin/python tools/match.py <file> --diff
```

It compiles inside Docker from `src/` (so `__FILE__` is the original path)
and compares every function, `.rodata`, `.data` and `.bss` against the game.
Iterate until it prints `OK: whole object matches`. `--src` compiles a
variant file and `--extra` adds compiler flags for experiments.

Things that changed codegen so far:

- `-fno-strict-aliasing` is required (the game re-reads values after
  stores through other types).
- Walking a string with a separate pointer (`for (const char *p = name; ...)`)
  vs. modifying the parameter changes register use.
- `x[i++] = y` vs `x[i] = y; i++` changes the order of stores.

## 4. Name it

Functions in the binary are referenced by other (asm) files, so the C++ name
must be known to splat: add the **GCC2-mangled** name to
`config/symbol_addrs_manual.txt`, and say which names are ours:

```
push__10BedSubMode = 0x00100258; // type:func size:0x68
```

Exact names from `symbols/symbol_addrs.txt` (provenance `linkonce`) win
over invented ones.

## 5. Build

```bash
tools/dock python3 tools/configure.py
tools/dock ninja
```

`configure.py` switches the file to a `cpp` segment when `src/<file>.cpp`
exists. `build/ok` must be recreated (SHA-1 of the whole image matches);
if not, `tools/.venv/bin/python tools/first_diff.py` points at the first
difference.
