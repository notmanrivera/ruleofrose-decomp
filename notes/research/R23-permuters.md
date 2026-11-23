# R23: making Sektor and Cyrax find more matches

Date 2026-11-22. Read-only research (no permuter was run). Sektor = official
decomp-permuter via `tools/perm_official.py`. Cyrax = our `tools/permute.py` +
`tools/permute_queue.py`.

## Summary

- Both permuters fail for structural reasons, not for lack of compute. Codex's
  28 hand matches today are mostly kinds of edit that neither tool can express:
  `throw()` on a callee declaration (5), register pins added or removed (5),
  control-flow restructuring such as early return / shared tail label (6), loop
  shape (2), 64-bit types (3).
- Cyrax edits only the function body (`split()` in permute.py keeps everything
  above `// ---- function` frozen) and has 13 rewrites, all expression or
  statement shuffles. Of the 28 dataset fixes it could plausibly find 3-4. Its
  log: 44 functions tried, 0 real finds (the one "MATCH" started as MATCH),
  partial progress on 3.
- Sektor prepared only 15 of the last 77 queue entries (62 skipped: 38 "parser
  rejects the function", 23 "base.c does not compile as C++", 1 preprocess
  error). Of the 15 that ran, 7 matched; over all queue runs 17 exact. The
  functions it can prepare are the easy ones, and none of the 28 dataset
  functions were found by it: 12 were skipped at preparation, 5 ran without
  finding, 11 were never run. Preparation is the bottleneck.
- Of the 78 current near misses (`permute_queue.py --list --max-off 12`): 34
  failed Sektor's preparation in its last run, 17 ran with no match, 27 were
  never run (new).

## 1. Dataset: what fixed the near misses (Codex, 2026-11-22)

Source: `git log --since="2026-11-22 13:00" pr-merge` (93 commits, 28 are
function matches by Codex), the "Fix" column of the tables in
`build/workers/codex-loop.log`, and the diffs of 17 of them (`git show`).

| Function | Fix | Kind |
|---|---|---|
| mag/maglife func_0011A320 | call an already compiled C getter, so the callee is known nothrow | NOTHROW |
| mag/maglife func_0011A14C | same, compiled C getter exposes nothrow | NOTHROW |
| unk/MnuPBook MnuPBook__vfunc_05 | `ASM_NOTHROW` on a callee decl (+ 16-aligned constant, data only) | NOTHROW |
| game/gamman func_001CD044 | `ASM_NOTHROW`; signed flag access | NOTHROW |
| unk/001B64C4 func_001BC8F8 | pointer helper, `ASM_NOTHROW`, cached stack value | NOTHROW |
| unk/001BE2CC func_001BE564 | `register T *r PS2_REG("$3") = self->req` | PIN add |
| unk/001BE2CC func_001BEB70 | pin two constants to $v0/$v1 and reorder two stores | PIN add + store order |
| mag/maglifepcbtl func_0012CA28 | split locals, pin, explicit clamp | PIN add + split local |
| game/gamman func_001C19C4 | remove `PS2_REG("$6")` hint; read header before saving pointer | PIN remove |
| game/gamsnd func_001E2704 | remove queue pointer register hint | PIN remove |
| unk/MnuDiary func_0019946C | `if (f & 2) goto tick;` jump to the shared counter update | CF: goto shared tail |
| game/gamtrg func_001D9F84 | `goto ret0`, shared zero-return label | CF: shared return label |
| msg/msgman func_00184578 | early `return 0` for zero instead of nested if | CF: early return |
| msg/msgman func_00184600 | early return and callee declared `long long` | CF early return + 64-bit |
| mag/maglifepc func_0011C1E8 | explicit tail return (+ assert filename) | CF: tail return |
| mag/magscene2 func_00138610 | return the allocated index directly | CF: return form |
| unk/MnuPBook func_00193D1C | `goto test; do {...} while`, with `bool more = i < count` before `p += 0x30` | loop shape |
| utl/utlgame func_00102B6C | `i = 0; if (n > 0) { p = list; do {...} while (i < n); }` | loop shape (guard) |
| mag/maglifepc func_0011BC64 | two 64-bit copies through `struct { long long w[2]; }` (+ assert text) | 64-bit copy |
| mag/maglifepc func_0011BCD8 | same | 64-bit copy |
| unk/00166AD0 func_00167CA0 | widen the flag before the boolean conversion | width/type |
| mag/maglifemenusp MagLifeMenuSpecial2__vfunc_10 | initialize the counter before the pointer | init order |
| mag/maglifepc3 func_0011DC64 | initialize a local after the first call | init placement |
| utl/utlgame func_00102758 | recompute `getSnd(&D_...)` at each call instead of a shared local | un-CSE |
| mag/magscene2 func_00138ED0 | reuse the index local | temp reuse |
| unk/0020ED9C func_0020EEA8 | `__builtin_memcpy(dst, src, 0x20000)` replaces both alignment loops | builtin |
| unk/001693A4 func_0016A7AC | inline member accessor `getOid()` with the right base registers | inline accessor |
| mag/maglifepc func_0011AF10 | typed fields (header) and direct returns | types + return |

Rewrite-kind totals (a fix can count in two kinds):

| Rewrite kind | Count |
|---|---|
| `throw()` / nothrow on callee (declaration or compiled C getter) | 5 |
| `PS2_REG` pin added | 3 |
| `PS2_REG` hint removed | 2 |
| control-flow restructure: early return, goto to shared tail or return label, explicit tail return | 6 |
| loop shape (goto-into-test do-while, `if (n>0) do-while`, bool before advance) | 2 |
| 64-bit types (`long long` return, two 64-bit copies) | 3 |
| width/type change of a value | 1 |
| init order / where a local is initialised | 2 |
| un-CSE / temp reuse | 2 |
| store reorder | 1 |
| helper, builtin, inline accessor | 3 |
| not a search move: assert text/filename, constant alignment | 4 |

## 2. Cyrax gap table

Cyrax rewrites (all inside the function body): `swaps` (neighbouring
independent statements and stores), `decl_swaps`, `commutes`, `wide_commutes`,
`term_swaps`, `compares`, `ands`, `signedness` (flip unsigned on a plain
int/short/char local), `invert_ifs` (only if/else with both blocks), `loops`
(for <-> while), `temps` (repeated `p->m` into a temporary), `inlines`
(single-use temporary), `extracts`.

| Rewrite kind | Dataset | In Cyrax? |
|---|---|---|
| nothrow on callee (declaration edit above the function) | 5 | no (head is frozen) |
| PS2_REG pin added to a local or temp | 3 | no |
| PS2_REG hint removed | 2 | no |
| early return vs nested if; goto to shared tail / return label | 6 | no (`invert_ifs` needs an else) |
| do-while with guard / goto-into-test / bool before advance | 2 | partial (`loops` is only for <-> while) |
| `long long` / 64-bit copy, callee return type | 3 | no |
| widen flag before bool | 1 | partial (`signedness`, locals only) |
| init order / move initialiser after a call | 2 | partial (`swaps` skips DECL lines; `decl_swaps` swaps declarations only) |
| un-CSE / temp reuse | 2 | partial (`inlines` only single-use; `temps` goes the other way) |
| store reorder | 1 | yes (`swaps`) |
| helper / builtin / inline accessor | 3 | no |

Estimate: Cyrax could have found 3-4 of 28 (store reorder, init order, the
single-use inline), consistent with ~1 in 35.

## 3. Why Cyrax scores so low (build/workers/perm-loop.log)

1. The rewrite set cannot reach most fixes (table above). 41 of 44 attempted
   functions ended at their start score; 3 improved partially (func_001E386C
   5 -> 2, func_00196A9C 5 -> 3, one more by 1).
2. The one logged "MATCH" (unk/MnuDiary func_0019AE78) printed `start: MATCH`
   and `0 tries`: it was already a match when picked (another worker fixed it);
   it is not a find.
3. Tiny search space for small functions: single-rewrite counts are 2-93, and 6
   runs ended "no rewrite left to try" in 0.0-1.4 min (func_0018C794: 3 tries;
   func_00193D1C: 46 tries; func_00188EC0: 279). The rest ran the full 8
   minutes at about 8 tries/s (3000-4200 tries) in a plateau walk that accepts
   variants "no worse than current" (`s <= cur_score`) and so stays near the
   start.
4. 14 queue entries "does not compile as it is; next" (8 distinct functions:
   TskMsgMan func_001EC344/001ECDD4/001EAC38/001F14CC, TskEnemyMove
   func_001FE87C/00201FA4, maglifepcbtl func_0012CA28, gamstat func_001D811C).
   They get zero search. Cause unconfirmed (the log keeps no error text).
5. Noise: 12,695 of the log's 15,350 lines are fix_hi16 warnings
   (`.text+0x..: 0x8C420000 -> lui $2 (as 2.10 bug)`) written for every compile;
   harmless, but they bury the progress lines.
6. Scoring is match.py's aligned edit count with a floor of 1 for any
   difference, so register-only fixes look flat until the final move
   (coarse landscape).
7. Queue policy: `--max-off 8`, 10 min per function, then cached in
   `.permuted` and never retried; best-so-far is kept per function only.

## 4. Why Sektor cannot prepare C++ (perm_official.py)

Pipeline: `raw_source()` writes a C file made of `target.h`, a few macros, only
the `#define` lines of the file (every `#include` is dropped), each top-level
declaration before the attempt that does not match `CXX_ONLY` (`class`, `::`,
`template`, `virtual`, `operator`, `public:`, `namespace`, `new`, `delete`,
`inline`, and `&name,` / `&name)`), then the attempt with `extern "C"` removed.
It is preprocessed and each item is kept only if pycparser accepts it
(`keep_parsable`); the function itself must parse. `compile.sh` wraps the C in
`extern "C" {}` and compiles it as C++.

Last queue (77): 38 "parser rejects the function", 23 "base.c does not compile
as C++", 1 preprocess/target error (a missing include, `dog/dogactor.h`), 15
prepared (7 MATCH, 8 no match).

Classification of the 34 skipped entries among the current near misses, from
the function text (heuristic: build/perm_off was not available, so these
counts are estimates):

| Cause | About | Examples |
|---|---|---|
| Types defined in headers (`#include` dropped; classes with methods or `inline` dropped by `CXX_ONLY`): `BedMemory`, `GamMan`, `ObjStat`, `MnuSub104`, `NodeIter`, `MagScene`, `DogModel` | 12 | mcdman, gamtrg func_001D8F04/001D95C4, mnuselect, 0020ED9C func_00213C6C, magscene, EffWater1 func_00178EEC |
| Method definitions `Class::fn(...)`, `this`, `m_field` cannot be C | 8 | magloader func_001420F8/00142908, magscene, maglife func_0011A320, maglifepc |
| C++ syntax in bodies (references, `::` calls, casts) | 5 | gamstat func_001D5A0C, TskMsgMan func_001ECDD4, gamman func_001CB01C |
| Declaration filter too aggressive (the `&name,` regex drops any declaration with a reference/address; `inline` helpers dropped) or parser-hostile `__attribute__`/`asm` forms | 5 | TskMsgMan (hundreds of `X_func_... asm()` aliases), gamsnd func_001E386C |
| Missing include at preprocess | 1 | EffFire1 |
| Unexplained | 3-5 | utlgame func_001026B0, gamman func_001C9C1C |

Also: `base.c does not compile as C++:` is followed by nothing in the log,
because `compile.sh` sends the compiler's stderr to `/dev/null`, so the 23
"base" failures cannot be diagnosed from the log. And a winning variant is
applied back only as a free `extern "C"` function (`apply_output`), never as a
method.

Dataset view: of 28 Codex functions Sektor had 12 skipped (parser: 0011A320,
001CD044, 0012CA28, 00138610, 00138ED0, 0011AF10, 0011BC64, 001C19C4,
0011BCD8, 001E2704, 0011C1E8; base.c: MnuPBook05, 00184578, 00184600, 001D9F84,
00102758), 5 run with no match (00193D1C, 0019946C, MagLifeMenuSpecial2
vfunc_10, 00167CA0, 00102B6C), the rest never run. The five that ran need
goto / early-return / guarded-loop restructuring, which random C mutations do
not produce.

Estimate: a translation that keeps header types, maps methods to free functions
with an explicit `this`, and stops dropping declarations by regex could prepare
about 25 of the 34 skipped near misses. At ~20-30% yield on prepared functions
(17 exact overall; 7 of 15 in the last queue, but those were easy ones), that
is +4-7 matches.

## 5. Ranked plan

Only a MATCH verified by `tools/match.py` and the full build counts, so
semantics-changing rewrites are acceptable as search moves.

### Cyrax

| # | Improvement | Covers | Yield | Cost | Risk |
|---|---|---|---|---|---|
| C1 | Head-level move: toggle `throw()` (literal, because `ASM_NOTHROW` is empty under NON_MATCHING) on each callee declaration the function calls, and on getters defined in the file. Make the declarations section mutable in `split()`. | 5/28 | +2-4 now (the `bnel` vs `bnez` entries, e.g. DwfMain func_0015D680/0015D738) | small | low |
| C2 | Control-flow moves: nested `if (c) {...}` at the end -> `if (!c) return X; ...`; several `return` arms -> `goto retN;` shared label and back; `while (c) {B}` -> `if (c) do {B} while (c);` and `goto test; do { ... test: } while`; `if (a) goto tail`. | 8/28 | +3-5 | medium | low-medium (many variants: dedupe and cap) |
| C3 | PS2_REG moves guided by the diff: for a local or repeated subexpression add `register T v PS2_REG("$N")` with N read from the asm register at the first differing instruction (match.py already prints it); also remove existing pins. | 5/28 | +2-3 | medium | low (owner keeps pins as full matches) |
| C4 | Type moves: `long long` callee return or 8-byte copy; `struct { long long a, b; }` for 16-byte copies; widen/narrow a flag cast (`!= 0`, `& 1`, `(unsigned char)`). | 4/28 | +1-2 | medium | medium (compile gate catches nonsense) |
| C5 | Local init moves: move `T x = e;` to its first use or after the first call; `int x; x = ...` <-> `int x = ...`; swap initialisers across a call. | 2-3/28 | +1 | small | low |
| C6 | Search policy: restarts from the best with annealing (accept +1), several seeds, dedupe by compiled bytes instead of source text, second pass for the "no rewrite left" functions once C1-C5 land, filter the fix_hi16 noise in the log. | all | about double useful tries | small | low |

### Sektor

| # | Improvement | Covers | Yield | Cost | Risk |
|---|---|---|---|---|---|
| S4 | Show the failure: let `compile.sh` and the preprocess step print compiler stderr into the log. Needed to classify the 23 blind failures. | all skipped | enables S1-S3 | small | none |
| S3 | Loosen `CXX_ONLY`: drop a declaration only when pycparser fails on it; remove the `&name,` regex; keep `inline` helpers by stripping the keyword; add the missing `-I` (dog/dogactor.h). | ~8/34 | +1-2 | small | low |
| S1 | Keep header types: do not drop `#include`; convert classes to plain structs (strip methods, flatten bases, use `tools/layouts.py` offsets) so `BedMemory`, `GamMan`, `ObjStat`, `MnuSub104`, `NodeIter` parse. | ~12/34 | +2-3 | medium-large | medium (layout errors change code; compile gate) |
| S2 | Method -> function: turn `Class::fn(args)` into `extern "C" R fn(Class *this_, args)` with `this_->` fields, keep the mangled label with `asm`, map the winner back to method form in `apply_output`. | ~8/34 | +1-3 | large | medium |
| S5 | Feed Sektor the output of Cyrax C1-C3 (restructured bases): Sektor's random mutations are good at register shuffles but cannot restructure control flow. | multiplier | | small | low |
| S6 | Add hand-written `PERM_*` macros at the sites the dataset shows (shared return label, loop guard, 64-bit copy). | 8/28 | +1-2 | medium | low |

Suggested order: C1 and S4 (about an hour each), then S3, C2, C3, S1. Together
C1+S4+S3 should give 3-6 matches within a day; C2/C3/S1 are the next tier.

## 6. Open questions

- Why do 8 functions "not compile as they are" in Cyrax's work.py path
  (TskMsgMan, TskEnemyMove, maglifepcbtl, gamstat func_001D811C)? The log keeps
  no error text.
- C1: does the scratch build define NON_MATCHING (so `ASM_NOTHROW` expands to
  nothing)? If so the toggle must write `throw()` itself and the final merge
  turns it back into the macro. Check in `tools/work.py`.
- Sektor failure classes are heuristic; verify by running
  `perm_official.py --prepare` on 5 samples once S4 prints compiler output.
- The perm-loop log predates today's matches (some "near misses" were fixed by
  hand meanwhile); re-run the queue after C1-C5 and recount.
