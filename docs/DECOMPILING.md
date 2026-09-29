# Decompiling a file

The loop for turning one original source file back into matching C++,
one function at a time.

## 1. Pick a file and start it

`config/splits.tsv` lists every file with its `.text`/`.rodata`/`.data`/`.bss`
starts. Small game files with real names (from assert paths) are the easiest.
`tools/.venv/bin/python tools/progress.py` shows what is done.

```bash
tools/dock python3 tools/configure.py --new bed/bedpfh
```

writes `src/bed/bedpfh.cpp` with one `INCLUDE_ASM` per function (and an
`INCLUDE_RODATA` per piece of `.rodata` several functions share), and puts
each function in `asm/nonmatchings/bed/bedpfh/<name>.s` together with the
`.rodata` only it uses. That file already builds identical: `tools/dock
ninja` must stay green before you change anything.

While a `.cpp` still has `INCLUDE_ASM`/`INCLUDE_RODATA` it is **partial**:

- `.text` and `.rodata` come from the compiled object, in source order, so
  keep the functions in their original order.
- `.data` and `.bss` stay in asm (`asm/data/<file>.{data,bss}.s`); refer to
  them as `extern` with their `D_xxxxxxxx` names (`#define zDmaBuf
  D_00308280` keeps the code readable). They move to C++ once nothing is
  asm any more.
- The `__FILE__` string is usually shared by several functions, so it is an
  `INCLUDE_RODATA`: `#define ASSERT_FILE D_xxxxxxxx` before including
  `ror.h` makes `ASSERT` use it instead of a second copy of `__FILE__`.
- C++ calling a function that is still asm declares it `extern "C"` with its
  `func_xxxxxxxx` name, or names it first (step 4).

The `.s` files are assembled by ee-gcc 2.96's own assembler (GNU as
2.10-ee) as part of the compiler's output; `include/include_asm.h` and
`include/labels.inc` are ours (splat's generation is off).

## 2. Draft a function

```bash
tools/.venv/bin/python -m m2c.main -t mips-gcc-c++ asm/nonmatchings/<file>/<func>.s
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

Replace the function's `INCLUDE_ASM` line in `src/<file>.cpp` with C++ (and
put the types in a header under `src/` if other code needs them), then:

```bash
tools/.venv/bin/python tools/match.py <file> --diff
```

It compiles inside Docker from `src/` (so `__FILE__` is the original path)
and compares every function, `.rodata`, `.data` and `.bss` against the game;
functions still in asm are listed as `asm`. Iterate until it prints `OK:
object matches (N functions still INCLUDE_ASM)`, or `OK: whole object
matches` once the file is complete. `--src` compiles a
variant file and `--extra` adds compiler flags for experiments.

Things that changed codegen so far:

- `-fno-strict-aliasing` is required (the game re-reads values after
  stores through other types).
- Walking a string with a separate pointer (`for (const char *p = name; ...)`)
  vs. modifying the parameter changes register use.
- `x[i++] = y` vs `x[i] = y; i++` changes the order of stores.
- A tail call (`j callee` instead of `jal`) only happens when the function
  returns the callee's value: `int close() { ...; return scePad2DeleteSocket(s); }`
  (`BedPad::close`), not with a `void` function.

## 4. Name it

Functions in the binary are referenced by other (asm) files, so the C++ name
must be known to splat: add the **GCC2-mangled** name to
`config/symbol_addrs_manual.txt`, and say which names are ours:

```
push__10BedSubMode = 0x00100258; // type:func size:0x68
```

Exact names from `symbols/symbol_addrs.txt` (provenance `linkonce`) win
over invented ones. Naming a function that is still `INCLUDE_ASM` renames its
`.s` too: change its `INCLUDE_ASM` line to match, then reconfigure. Names
with `$` (destructors, `_$_6BedPad`) work.

## 5. Build

```bash
tools/dock python3 tools/configure.py
tools/dock ninja
```

`configure.py` (without `--no-split`, so splat sees the new names and
`INCLUDE_ASM` lines) switches the file to a `cpp` segment when
`src/<file>.cpp` exists. `build/ok` must be recreated (SHA-1 of the whole image matches);
if not, `tools/.venv/bin/python tools/first_diff.py` points at the first
difference.
