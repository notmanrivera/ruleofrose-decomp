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

## Data (.rodata)

- A string or float literal goes to `.rodata` when the first function using
  it is compiled, in first-use order. A string the asm still uses stays an
  `INCLUDE_RODATA`: refer to its `D_` symbol (`ASSERT_S`, `ASSERT_FILE`).
- 8-byte data is 8-aligned (`config/rodata_align_manual.tsv` when splat's
  piece lacks the `.align`); jump tables are 16-aligned.

## Not allowed as a fix

Inline asm with instructions, `.word`, `volatile` added only to pin an
access, and raw address casts where the game used a symbol (`&D_...`).
