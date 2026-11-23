# ee-gcc 2.96: what changes the code (short list)

For a function a few instructions off. Each item is a source change and the
difference it fixes. Sources: our own `DECOMPILING.md` §3 (the long reference,
with this project's cases: search it, do not read it whole), the Gran Turismo
4 decomp's [ee-gcc-2.96.md](https://github.com/gustavocanepa/gt4-decomp/blob/master/knowledge/ee-gcc-2.96.md)
and Xenosaga's [MATCHING-PLAYBOOK.md](https://github.com/LinuxJessi/decomp-compat-kit/blob/main/docs/MATCHING-PLAYBOOK.md),
same compiler. Theirs use `-O2`, ours `-Os`: treat their items as ideas to
check, not facts about this game.

**How to work:** one hypothesis per check; after 4 checks in a row that do
not lower the "edits" count, change approach or move on. Do not read the
whole `src/<file>.cpp`: work.py's scratch file has the draft, the twin, the
earlier attempt and the class layout; grep the file for the names you need.

## Branches: `bnel`/`beql` (likely) vs `bne`/`beq`

- **`throw()` on the callees near the branch** (`ASM_NOTHROW`, include/ror.h):
  a callee known not to throw lets reorg use the likely form with the
  target's first instruction in the slot. A function compiled earlier in the
  file counts as nothrow; an `INCLUDE_ASM` one does not, so its declaration
  needs `ASM_NOTHROW`. Try it on each nearby callee, on or off.
- Invert the `if`/`else` (test the opposite condition, swap the arms).
- `if (f() == 0) { ...; return N; } return 0;` gives `bnel` with zero in the
  slot; `if (f() != 0) return 0; ...` gives a plain `bne`.
- Test a local flag (`int ok = f() == K; if (!ok) ...`) instead of the call
  directly (DogModel::loadTM2).
- `__builtin_expect(p, 0)` on the value itself (not `p != 0`) makes reorg
  stop taking from the target. A diagnostic: prefer a natural form that does
  the same.

## Registers (`$v0`/`$v1`/`$a0`, `$sN`, `$fN`)

- The allocator follows live ranges and use counts, not declaration order
  (reordering declarations alone did nothing in 813 of our functions).
  `tools/regalloc.py <file> <func> [--nm] [--src variant.cpp]` prints each
  pseudo's register, uses, live length and priority (about
  floor(log2 uses) * uses * size / live length): the value that should win
  a register needs more uses or a shorter life.
- Two constants stored one after the other (`... = 1; q[2] = 2;`) become two
  registers loaded at the top; one local set twice (`c = 1; ... = c; c = 2;
  q[2] = c;`) shares one register and keeps the second load late
  (MnuPBook__vfunc_07, confirmed at -Os). Give it its own local, not one
  that also holds a call's result.
- Add or remove a temporary; assign a value later (after the early returns)
  or before a call; read a field again after a call instead of keeping it.
- One variable used for two roles is one register: split it, or merge two.
- The callee's real return type: `void` frees `$v0` (the next temporary
  takes it), `int` keeps it busy (the next one takes `$v1`).
- A constant swapped with a loaded value (`$v0`/`$v1`): pass the constant
  through a `static inline` helper's parameter.
- Narrow types show as masks: `andi 0xff` is `u8`, `sll 16; sra 16` is
  `s16`; none means `int`. Signedness picks `lh`/`lhu`, `slti`/`sltiu`.
- Floats: a value used before and after a call lives in `$f20`+; one float
  local reused keeps one register, separate locals change them;
  `float a = 0.0f` at the declaration vs in a branch changes `mov.s`.

## Store and instruction order

- Among stores ready at once, the one that is the last use of its register
  goes first; otherwise source order. Write a constructor's vtable store
  first, then the fields by ascending offset.
- `a = b = 0.0f` routes the zero through an FPU register (`swc1`); separate
  statements store `$zero` (`sw`), and can change the order.
- `M2C_FIELD(p, int *, off)` accesses may alias anything, so they keep their
  order; a typed struct field lets the scheduler move them, which may be what
  the game did.
- Order of a call's arguments decides the order of their setup.
- `p += a; p += b;` keeps two adds; `p + a + b` folds them.

## Addresses and `addu` operand order

- `E *e = p->arr + i; e->x = v;` vs `p->arr[i].x = v` flip which register
  holds the base.
- `p[i]` vs `*(p + i)`, and `base + i*size + off` vs `((T *)(base + off))[i]`,
  flip the `addu` operands.
- An array inside the struct (`t->arr[i]`) takes two address registers; a
  pointer member (`T *arr`) one.

## Control flow, switch, loops

- Blocks come out in source order; a body after unrelated code is a `goto`.
- A shared `return K;` in the middle (a `b` to an epilogue with a `nop` slot)
  is `goto fail; ... fail: return K;`.
- A jump table needs about 5 distinct cases; fewer give a compare tree.
  Write each case on its own (identical bodies merge later), cases in
  address order, explicit `default:` and empty low cases.
- `x = c ? A : B` gives `movz`/`movn`; an `if` keeps the branch.
- A natural `for (i = 0; i < N; i++)` lets the compiler make the
  down-counter; a hand-written `do`/`while` with `p++` usually does not match.
- `for (j = 0, p = base; ...)` and `for (p = base, j = 0; ...)` fill the
  delay slot differently.
- `return f(...)` (non-void) is a tail call `j`; a final call with the result
  unused keeps `jal` and the epilogue.

## Ideas from gt4-decomp: confirmed at `-Os`

Tested at `-Os` against this repo's `NON_MATCHING` functions (sources: gt4-decomp
`knowledge/ee-gcc-2.96.md` (ee) and `gcc296-codegen-map.md` (map)):

- **A `const` table removes false load/store dependences** (ee 171-172):
  **MATCH** on `unk/FshMain::FshOutAtk__vfunc_02` — changing `extern int D_002F0BF8;`
  to `extern const int D_002F0BF8[];` flipped the `sh $zero, 0x42($s0)` / `0x40($s0)`
  store order (works even under `-fno-strict-aliasing` via `RTX_UNCHANGING_P`).
- **Constructor initializer list vs body assignments (`name(n ? n : D_x)` vs `if`)**
  (map 117-122): **MATCH** on `unk/TskMsgMan::func_001F5244` — writing it as a C++
  constructor with `: m_oid(arg1)` fixed the epilogue `ld $s0/$s2` swap. Comparing
  `: m_nodeName(arg3 ? arg3 : D_002FDBF0)` (`0x64` bytes) against
  `if (arg3 == 0) arg3 = D_002FDBF0; m_nodeName = arg3;` in the body (`0x70` bytes)
  also confirmed distinct live ranges and register allocation.
- **Pointer local vs the address written at each use** (map 495-509):
  confirmed on `game/gamman::func_001CD044` — caching `char *sw = (char *)sysWork_CD044();`
  vs rematerialising `sysWork_CD044()` at each use changed codegen by `0x18` bytes
  (`0x1E0` -> `0x1C8`).
- **Loop-free scheduling region 10 basic blocks / 100 insns** (map 227-232):
  confirmed on `unk/FshMain::FshOutAtk__vfunc_02` — adding one extra `||` branch
  (crossing 10 BBs) stopped hoisting `daddu $a0, $s0`, `addiu $a3, 0x20`,
  `addiu $a2, 0x100`, `addiu $t0, 1` above the branch chain (`0xB8` -> `0xC0`);
  similarly on `game/gamman::func_001CD044` when removing a condition.
- **Split `if (a) return 0; if (f()) return 0;` (plain) vs `if (a || f()) return 0;`
  (likely)** (map 243-246): confirmed on `game/gamstat::func_001D5A0C` —
  `if (arg2 == 0 || func_001D1720(...) != 0) return 0;` emitted `beql $v0, $zero`,
  whereas split `if (arg2 == 0) return 0; if (func_001D1720(...) != 0) return 0;`
  emitted plain branches. (Tried on `unk/00166AD0::func_00167CA0` and
  `unk/MnuPBook::func_00193D1C` without a match.)
- **A store through a `volatile` pointer never goes into a delay slot** (ee 148-151):
  diagnostic confirmed on `game/gamstat::func_001D5A0C` (not committed) — making
  the `u_long128 *` store `volatile` pulled `sq $a2, 0x0($v0)` out of the `beqz $s3`
  delay slot (`6/111` -> `4/111` differ). A branch delay slot filled with a store
  proves it was not `volatile`.
- **A store written in both arms of an `if`/`else` can come out as a likely slot
  after it** (ee 280-281, 366-370): confirmed on `unk/FshMain::FshOutAtk__vfunc_02`
  — writing the `0x42`/`0x40` stores in both arms emits `bnel` with `sh $zero, 0x42($s0)`
  in its delay slot (matching the game), whereas factoring them into a local `v`
  after the `if` drops `bnel` to plain `bne` + `andi`. Also changed branching on
  `unk/0020ED9C::func_002107AC`.
- **Float locals: reading a field into a local first (`float ay = a->y;`) and
  initialization order picking `$f20`+** (map 135-143, ee 838-842): reading fields
  into locals first changed float register allocation (`$f0` -> `$f2`) and load/store
  interleaving on `game/gamstat::func_001D811C`. For `$f20`+, **initialization order**
  (`float life = spread * 3.0f; float size = spread * 0.5f;` vs `size` then `life` on
  `unk/Eff0::EffBloodSpray1__vfunc_02`) swapped `$f20` and `$f21` cleanly (bare
  uninitialized declaration order alone did nothing; see below).
- **Bottom-tested loop `k = 0; goto test; do { ... test:; } while (...)`**
  (ee 832-837): confirmed on `unk/MnuPBook::func_00194688` — produced the game's
  `b .Ltest` bottom-entry loop without `volatile` (`5` edits vs `for`'s `14`).
- **2-value range `switch` as a compare tree** (ee 424-427): confirmed on
  `unk/0020ED9C::func_002107AC` — `switch (arg1)` with `case 0`/`case 1` emits a
  2-value compare tree distinct from `if (arg1 != 1) ... else ...`.
- **Callee declared `__attribute__((const))` lets loads stay across the call**
  (ee 517-521): confirmed on `unk/MnuPBook::func_00193D1C` (`func_00193E20`,
  `0xE0` -> `0xCC`, eliminated post-call reloads of `arg0+0x18`/`0x20`) and
  `unk/TskMsgMan::func_001F2920` (`func_001311F4`, `0x164` -> `0x11C`). Caveats:
  `__attribute__((const))` must follow `asm("...")`, and GCC will drop calls to
  `const` functions whose return value is unused.

## Ideas from gt4-decomp: no effect seen at `-Os`

- **C++ class members having alias set 0 vs `int *` / `M2C_FIELD`** (map 379-394):
  zero instruction change on `unk/FshMain::FshOutAtk__vfunc_02` (without `const`),
  `mcd/mcdman::func_00188EC0`, and `unk/Eff0::EffBloodSpray1__vfunc_02` (struct
  `int` store before `float` load). Explained by `-fno-strict-aliasing` in
  `tools/configure.py`'s `CFLAGS`: every access already has alias set 0.
- **Bare declaration order of uninitialized `float` locals picking `$f20`+**
  (ee 838-842): zero change on `unk/Eff0::EffBloodSpray1__vfunc_02` when reordering
  `float life, size, speed, spread;` before identical assignment order (reordering
  first initializations does swap `$f20`/`$f21`; see above).
- **Loop bound reset inside body / rotated `if (j < n) do ... while (j < n);`**
  (ee 136-140, 232-235): zero change on `unk/EffFire1::EffDust2__vfunc_05`
  (`n = 12;` reset inside loop) and `unk/MnuPBook::func_00193D1C`
  (`if (i < count) do { ... } while (i < count);` vs `while (i < count)`).
- **Switch full-copy cases merged later** (ee 481-485): not merged at `-Os` on
  `unk/TskMsgMan::func_001EC344` — duplicating `case 0..3` into `case 4..7` grew
  the function from `0x258` to `0x2A8` instead of merging back.

## Data (.rodata)

- A string or float literal goes to `.rodata` when the first function using
  it is compiled, in first-use order. A string the asm still uses stays an
  `INCLUDE_RODATA`: refer to its `D_` symbol (`ASSERT_S`, `ASSERT_FILE`).
- Alignment, measured on ee-gcc 2.96 -Os with `-S` (2026-11-23): every
  string literal (any length, 8 to 32 bytes tried), every named array
  (char, short, int, float, double) and struct goes `.align 3` (8 bytes):
  the R5900's word is 64 bits. Jump tables go `.align 4` (16). In the game
  the assert file-name strings sit 76 times at 0 mod 16 and 66 times at 8
  mod 16: no 16 rule for strings; a 16-aligned one has something else
  before it (game/gamsnd: 12 zero bytes after its jump table).
- When a function MATCHes but its object's .rodata does not, an
  INCLUDE_RODATA piece after it usually needs splat's `.align` raised:
  `tools/rodata_align_fix.py <file> <func>` finds it and writes
  `config/rodata_align_manual.tsv` (merge by hand: config/).

## Not allowed as a fix

Inline asm with instructions, `.word`, `volatile` added only to pin an
access, and raw address casts where the game used a symbol (`&D_...`).

## Our compiler is the stock decompme ee-gcc2.96 (2026-11-23)

docker/Dockerfile downloads `ee-gcc2.96.tar.xz` from decompme/compilers
(cc1 "2.96-ee-001003-1"). decomp-compat-kit (LinuxJessi; Xenosaga, `-O2`)
byte-patches that cc1 to match Xenosaga's retail code (literal rounding,
loop padding, LO_SUM alias, gcse, extendqidi2). Rule of Rose does not need
the literal patch: stock cc1 truncates decimal float literals (0.1f ->
0x3DCCCCCC, 0.3f -> 0x3E999999) and the game has exactly those (4 each,
never the rounded 0x3DCCCCCD / 0x3E99999A); test in
notes/research/float_literal_test_2026-11-23.cpp. The other patches are
unmeasured here; hundreds of functions match with the stock cc1.
Measured 2026-11-23 with tools/order_probe.py on the 40 "order" near misses
that compile: no global load (R_MIPS_LO16) is ever ordered differently from
a store, in either direction; the 35 load/store pairs that differ are other
loads, split 15 game-first / 20 ours-first. So nothing points to Xenosaga's
A3 (LO_SUM alias) fix: an "order" near miss here is a source-order or
temporary problem, not a compiler build.
