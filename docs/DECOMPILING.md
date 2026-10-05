# Decompiling a file

The loop for turning one original source file back into matching C++,
one function at a time.

## 1. Pick a file and start it

`config/splits.tsv` lists every file with its `.text`/`.rodata`/`.data`/`.bss`
starts. Small game files with real names (from assert paths) are the easiest.
`tools/.venv/bin/python tools/progress.py` shows what is done.

Check its edges first: boundaries marked `likely` can be off by a function
or two. `bed/bedpfh` was split one function early: its first function was
`bed/bedmemory`'s heap constructor (another class's fields, called only from
a static initialiser). If the first or last functions belong elsewhere
(class layout, callers), move the start with a row in
`config/splits_manual.tsv` (with the evidence), then run
`tools/.venv/bin/python tools/split_files.py` and reconfigure. Assert line
numbers help too: `utl/utlfile.cpp`'s first asserts are on lines 15-16, so
the function holding them is the file's first, and the 25 functions before
it (placed there by `split_files.py`, which starts a file as early as it
can) became `unk/001056E8`. A row can also force where a file's `.rodata`
starts, when the inferred cut is wrong: `unk/0010F3A4`'s strings come after
`dog/dogactor`'s RTTI names, which a file emits last.

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
- A function of the file that is still asm and is called by C++ further
  down ends its declaration in `ASM_NOTHROW` (`include/ror.h`). With
  `-fno-exceptions`, g++ 2.96 knows that a function it has already compiled
  cannot throw, and a call to it can compile differently (`beql` instead of
  `beq` in `DogActor::vfunc12`); an asm function is never compiled.
- Asm that uses a label inside the compiled `.rodata` (the linkonce copies
  of the file's inline methods, an `INCLUDE_ASM` function using a string
  the C++ emits) gets it from `build/cpp_syms.ld`, which `configure.py`
  writes.
- A string used by both C++ and asm functions stays an `INCLUDE_RODATA`;
  the C++ asserts name it with `ASSERT_S(expr, D_xxxxxxxx)` (and
  `ASSERT_FILE` for the `__FILE__` string). Back to `ASSERT` once the file
  has no asm left.
- A function that will not match yet keeps its C++ next to the asm, the
  usual decomp convention (`bed/bedmemory`):

  ```cpp
  #ifdef NON_MATCHING
  void Foo::bar() { ... }
  #else
  INCLUDE_ASM("asm/nonmatchings/foo/foo", bar__3Foo);
  #endif
  ```

  `tools/match.py <file> --extra=-DNON_MATCHING` shows how close it is.

The `.s` files are assembled by ee-gcc 2.96's own assembler (GNU as
2.10-ee) as part of the compiler's output; `include/include_asm.h` and
`include/labels.inc` are ours (splat's generation is off).

Classes with virtual methods: the file with a class's key method (its first
non-inline virtual, e.g. `~DogActor`) emits the vtable, the `__tf<Class>`
RTTI function and its copies of the inline methods as linkonce sections.
The build drops the compiler's copies and links the game's from
`asm/inline/` and `asm/data/vtbl/`, but their strings stay in the file: the
RTTI names (`8DogActor`) and the inline methods' assert strings close its
`.rodata`. A class without a key method (`DogEntity`, all virtuals inline)
emits them in every file that constructs one. The `__ti<Class>` type_info
objects are COMMON symbols of those files; `symbols/symbol_addrs.txt` names
them (provenance `rtti-node`) so they resolve to the game's `.bss`.

## 2. Draft a function

```bash
tools/.venv/bin/python -m m2c.main -t mips-gcc-c --function <func> asm/<file>.s
```

Use the whole-file `asm/<file>.s` (splat keeps it for decompiled files too):
the `asm/nonmatchings/` copies use numbered registers (`$31`), and m2c then
fails to see the returns. m2c does not know the R5900's `sqrt.s`, which
spimdisasm prints as `c1 0xC0084`: that is g++'s inline `sqrtf` (see below).

Ghidra (`tools/ghidra_setup.sh`) helps with types and callers. Useful facts
straight from the binary:

- **Asserts**: a call to `ror_assert` (0x00215A30) passes the file path,
  the `__LINE__` (`addiu $a1, $zero, <line>`) and the expression text.
  Reproduce them with `ASSERT(expr)` on exactly that source line (pad with
  blank lines); the expression text is in the file's `.rodata`.
- **Member and parameter names** often appear in those expressions
  (`m_depth < MAX_STACK`, `theName`).
- `tools/.venv/bin/python tools/asserts.py <file> [--lines]` lists every
  assert of a source file across the game. Inline methods of a header assert
  with the header's path and line, so run it on the `.h` first: it tells
  which line each inline sits on (keep them there) and what it reads, from
  every file that includes it (`bed/bedpfh.h`: lines 70-73, 81, 85-86, 91).
- `lq`/`sq` are 128-bit copies: `u_long128` (see `include/ror.h`).
- g++ 2.96 names the global `operator new(size_t)`, `new[]`, `delete` and
  `delete[]` `__builtin_new`, `__builtin_vec_new`, `__builtin_delete` and
  `__builtin_vec_delete`; other overloads mangle normally (`__nw__FUiPCcii`).
- Linker script symbols (`_end`, `_stack_size`, `_ctype_`) are named in
  `config/symbol_addrs_manual.txt`; declare them `extern char _end[];`.

## 3. Match it

Replace the function's `INCLUDE_ASM` line in `src/<file>.cpp` with C++ (and
put the types in a header under `src/` if other code needs them), then:

```bash
tools/.venv/bin/python tools/match.py <file> --diff
```

It compiles inside Docker from `src/` (so `__FILE__` is the original path)
and compares every function, `.rodata`, `.data` and `.bss` against the game;
functions still in asm are listed as `asm`. Each function is compared at its
address in the game, so one of the wrong size does not throw off the rest.
Relocations are filled in the way the linker would, with the game's
addresses (imported names from the last link map, `build/SLUS_214.48.map`),
so a call to the wrong function or a load of the wrong symbol shows as
`N relocs differ`, one line per reference, e.g. `reloc at +0x74:
txtSkipCtrl__FPc (0x00105750), game 0x00105710 (txtSkipSpace__FPc)`. While
the object's `.rodata`, `.data` or `.bss` has the wrong size, everything
after the wrong piece moves, so references into it are not checked (its
line says so). Iterate until it prints `OK:
object matches (N functions still INCLUDE_ASM)`, or `OK: whole object
matches` once the file is complete. `--src` compiles a
variant file and `--extra` adds compiler flags for experiments. Imported
addresses come from the last link: after a failed build, references into
everything it moved show as wrong until the build is green again.

Things that changed codegen so far:

- `-fno-strict-aliasing` is required (the game re-reads values after
  stores through other types).
- Walking a string with a separate pointer (`for (const char *p = name; ...)`)
  vs. modifying the parameter changes register use.
- `x[i++] = y` vs `x[i] = y; i++` changes the order of stores.
- Equivalent loops can differ: skipping a string with `while (*p) p++; p++;`
  matched where `while (*p++);` gave `lbu` instead of `lb` and a different
  loop (`BedPfh::getName`). m2c's draft is a start, not the answer.
- A tail call (`j callee` instead of `jal`) only happens when the function
  returns the callee's value: `int close() { ...; return scePad2DeleteSocket(s); }`
  (`BedPad::close`). A `void` function gets one from `return f();` with a
  `void` f (`DogEntityEx::transform`), never from a plain call statement.
- Chained assignments share one register: `m_x = m_y = 0.0f` stores
  `mtc1 $zero` + `swc1`, separate `= 0.0f` store `sw $zero`. The chain's
  order sets the order of the stores (`BedPad::update`).
- Write the members, not locals, when the original does: `m_press = ~raw;
  m_trigger = m_press & ~m_old;` keeps the 32-bit value and truncates only
  where a 16-bit value is compared (`andi 0xFFFF`); a local `unsigned short`
  truncates at once.
- Bit tests: `(m_press >> 4) & 1` on an `unsigned short` compiles to
  `srl; andi 1; andi 0xFFFF`, `m_press & 0x10` to `andi 0x10`, and a bit
  field to `lw` + `andi`.
- A value re-read from memory in each branch (`lbu` again) means the source
  used the member each time; a helper function, even inline, reads it once.
- Evaluation order follows statements: `d = d * 100.0f * 0.001f; return
  a + d;` differs from `return a + d * 100.0f * 0.001f;`.
- Operand order matters for jump threading: after `if (dir == m_dir ...)`,
  `if (dir != m_dir)` is recognised as the same test and skipped, `if (m_dir
  != dir)` is not.
- A load in the delay slot of a plain (non-likely) branch was before the
  branch in the source: GCC never moves a load from the code after a branch
  into its delay slot (it could trap if the branch is taken).
- `sqrtf` declared `extern "C" float sqrtf(float);` (`include/sdk/math.h`)
  becomes the inline `sqrt.s` + NaN check + call that the game has.
- Stores through two different pointers (`this` and a header pointer)
  keep their source order: GCC cannot tell that they do not alias. The
  same goes for a load after such a store, so when the original reads a
  field before writing elsewhere, so must the source (`BedMemory::free`,
  `shrink`). Stores through one pointer to different fields can be
  reordered, and a run of them often comes out with the last one first.
- Register choice follows priority: uses per instruction of lifetime. A
  local working copy of a parameter (`int size = theSize;`) starts later
  and can win a register the parameter lost (`BedMemory::init`).
  Temporaries of equal priority take `$v0`, `$v1`, `$a0`... in the order
  they were created, i.e. source order.
- `.rodata` strings no code refers to are real: an assert whose condition
  is always true (`ASSERT(p->m_header_size = sizeof( BEDMEMHEADER ))`, `=`
  for `==`) or code under `if (0)` still emit their strings. Reproduce
  them the same way (`BedMemory::alloc`, `check`).
- `tools/pad_asserts.py src/<file>.cpp <lines>` adds or removes blank lines
  so every assert sits on its original line, and moves the padding above
  the function (`tools/asserts.py <file>.cpp` lists the lines; it misses
  asserts whose arguments are set far from the call, which m2c's draft
  shows).
- `tools/try_variants.py <file> <function> variants.json` compiles text
  variants of a file one after another and prints each function's status:
  the fastest way to find a statement order; `--extra=-DNON_MATCHING` tries
  a function kept under `NON_MATCHING`.
- `-fno-schedule-insns` breaks nearly every matched function: the first
  scheduling pass is on, and the flags in CLAUDE.md stand.
- To see why GCC placed something, dump its passes: copy `src/` to
  `build/dump/` and compile there with `-da -S` inside the image; the
  `.28.mach` file shows each branch's `REG_BR_PROB` (the delay-slot pass
  fills from the target when it is 5000 or more).
- A value computed into the variable's own register (`sll $s1` after
  `subu $s1`) means an assignment to it: `max = ...; max = (max >> 8) << 8;`,
  `ival *= 10; ival += c - '0';` (`heapInit`, `txtParse`).
- A `char c` local is a byte register: `lbu`, then `sll 24`/`sra 24` where
  it is used as an int. `*p` used directly is `lb`. Reading through an
  `unsigned char *` gives `lbu` and unsigned compares (`sltiu`) throughout
  (`txtNextLine`).
- `for (p++; test(*p); p++) { char c = *p; ... }` loads `*p` separately in
  the test and the body, like the game; `c = *p++` let CSE merge the loads.
- A call used as an argument (`heap.alloc(size, attr(align))`) comes after
  g++ has loaded the other arguments (here `&heap`), which then take saved
  registers across it; with a local first (`int a = attr(align);
  heap.alloc(size, a);`) they are loaded after the call.
- A small `switch` is a balanced tree: with cases 32, 64, 128 g++ tests 64
  first. The game testing 32 first (then `< 33`) means a fourth case below
  32 that did nothing, so its test vanished (`heapAlignAttr`).
- A `for (;;)`/`break` retry loop and the equivalent `do { } while` place
  the argument set-up of the next call differently; try both (`heapInit`).
- `sym1 + (sym2 + K)` loads `sym2+K` with `lui`/`addiu` and adds `sym1` as
  `la sym1($reg)`; `(sym1 + sym2) + K` does the reverse. `match.py` reports
  the swap as two wrong references (`reloc at +0x0: _end (0x00828E94), game
  0x00081000`).
- Inline asm: an `"f"` input that the asm itself reads from `$f12` (and
  clobbers) makes g++ copy it to `$f0` first, a dead `mov.s` the game has
  (`vu0FTOI15`). The assembler fills the `jr $ra` delay slot with the asm's
  last instruction.
- g++ 2.96 puts zero-initialised globals (`int n = 0;`) in `.data`.
- A class with a user-written copy constructor is BLKmode: its locals get
  16-byte stack slots, in declaration order (`GamList::iterator` in
  `utlFindNearest`: 0x0, 0x10, 0x20). Without one they pack 4 bytes apart.
- CSE reuses a register that holds an array's address only for element 0:
  `float *w = wpos; w[0] = w[1] = w[2] = 0.0f;` stores `[0]` through the
  register and the rest `$sp`-relative, as the game does, and the extra use
  moves that register up in the allocation order.
- An inline accessor that writes through a `void *` (`get_o_smell_range(&r)`)
  keeps the local in the frame.
- A constant loaded before a branch, with the store in a `bc1tl` delay slot,
  is a conditional expression: `*yaw = x < 0.0f ? -HALF_PI : HALF_PI;`; the
  same `if`/`else` loads each constant in its own block (`vecDistYaw`).
- `if (col == cur || cur == -1) return id;` and two separate `if`s pick
  different delay-slot fillers (`sndConvertId`).
- A local initialised where it is declared (`float a = 0.0f;`) shares the
  register of that constant; assigned later, in a branch, it gets its own
  register and a `mov.s` copy (`vecPitch`).
- Then and else blocks keep their source order: `if (mf == 0.0f) { m_time
  = 0; } else { ... }` puts the short block first (a `b` over the long
  one), `if (mf != 0.0f)` the other way round (`DogMotionBlend::update`).
- An early `if (no < 0) return 0.0f;` loads the 0.0 at the top of the
  function; `if (no >= 0) { ... } return 0.0f;` loads it in the last block
  (`getTimeRatio`, `getPosture`).
- In a loop, `if (a && b) { ... }` and two `continue` tests give different
  code (`getNodeWeight`).
- Code hoisting (`-Os` GCSE) moves an expression to the block that
  dominates its uses only when two or more blocks compute it, so writing a
  call or store in both branches instead of once after them changes the
  result (`DogActor::func_0010BF08`, `func_0010F73C`).
- `int r; if (c) r = f(); else r = 1;` and `int r = 1; if (c) r = f();`
  differ in CSE and register allocation; try both (`func_0010CD5C`,
  `func_0010C568`, `vfunc12`).
- `while (c) { }` and `do { } while (c)` differ in CSE's jump following, e.g.
  whether repeated `$a0 = this` copies are deleted (`func_0010D388`).
- A negation passed through an inline function's parameter stays `neg.s` +
  `add.s`; written directly, `a + -b` folds to `sub.s`.
- An inline whose `if (n < 0) return 0;` makes a following `ASSERT(n >= 0)`
  always true drops the test but still emits its string.
- String literals go to `.rodata` when a function using them is first
  expanded, so `.rodata` follows the order of first use in the file.
- The original `ASSERT` stringified its expression after macro expansion:
  `#define`d constants appear expanded (`theIndex < (4)`, `== (2048)`,
  `__null` for `NULL`) while enum and `const` names stay. Ours does not
  expand, so write the expanded form.
- A register that holds a value before a call is not always an argument:
  `$a2` before `func_0010BF08`'s call was only a free register.
- `getSubMode()->m_step++` and `++getSubMode()->m_step` differ: the
  post-increment folds the member offset into the pointer (`addiu $v1,
  $s1, 0x134`) and later reads reuse the value; the pre-increment keeps
  `0x130` + `4($v1)` and the next read loads again (`DogCamera::update`).
- One local variable reused for two values (`r = deg; ...; r = result;`)
  dies twice, so local allocation leaves it to global allocation and the
  registers change; two variables, or none, give other registers
  (`DogCamera::func_0010FAC0`).
- Stores to a member struct through an inline method of that struct
  (`m_rot_offset.clear()`, `m_unk70.set(...)`) use a pointer (`addiu $v0,
  $s0, 0x80` and offsets 0 to 0xC); stores written member by member use
  offsets from `this` (0x80 to 0x8C). The order of a chained assignment
  (`m_x = m_y = m_z = 0.0f`) sets the order of the stores
  (`DogEntityEx::reset`, `setParent`).
- A function returning early (`if (!m_unk90) return 0;`) loads the 0 into
  `$v0` before the test; `if (m_unk90) { ...; return 1; } return 0;` loads
  it at the end (`DogEntity::makeMatrix`), as with floats above.
- g++ 2.x mangles `float (*)[4]` as `PA3_f`: the array bound minus one.
- A `switch` with five or more cases becomes a jump table in `.rodata`;
  a chain of compares in the game (each `bne` in turn, in source order)
  means `if`/`else if` (`DogLightPool::setParam`: 5, 0, 1, 2, 3, 4).
- `xori $v0, $x, 1; andi $v0, $v0, 1; bnez` is a negated flag kept in a
  variable: `bool off = !(mask & 1); mask >>= 1; if (!off)`
  (`getNearestPoint`); `(mask & 1) == 1` gives `bne` against a register
  holding 1.
- A return value (`-1`) loaded into `$v0` before an early test means an
  early `return -1;` was hoisted ahead of it; `if (n >= 32) return -1;` at
  the top leaves `$v0` free and loads it in the branch delay slot
  (`DogLightPool::add`).
- Arguments past the fourth come in `$t0`, `$t1` (EABI). Check which value
  each callee receives before naming them: swapped names compile to the
  same mangled signature (`setSetParam`).
- A copy of `this` (`const T *self = this;`) to call `const` overloads is
  one more register; make the method `const` instead (`apply`).
- A function-scope `static const` table goes to `.rodata` right after that
  function's strings; a file-scope one after everything the file emits.
  Count the game's entries: a table can have more than the code reads
  (`sLightSize[8]` with six types).
- Stores that stay in source order where the scheduler would hoist the
  constants ahead of them sit in a `do { } while (0)` (a macro, most
  likely): its loop notes stop the scheduler (`DogLight::init`).
- An assert the compiler can prove (`if (!m_spot) return; ASSERT(m_spot);`)
  leaves no code but still emits its string where it is expanded; strings
  in `.rodata` that no code of the function uses, in that function's
  order, point to such asserts (`DogLight::setParam`).
- A struct copied with `ld`/`sd` (neither `lw`/`sw` nor `lq`/`sq`) has
  8-byte alignment (`DogLightAmbient`); a static one placed at a multiple
  of 16 also needs `__attribute__((aligned(16)))` on the variable.

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
