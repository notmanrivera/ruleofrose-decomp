# R28: which near misses Smoke can close

Date 2026-11-23. Read-only research (no permuter run). Smoke = cpp_permuter via
`tools/cpp_perm.py` / `tools/cpp_perm_queue.py`. Sources: `build/workers/cpp-perm.log`
(5385 lines), `build/workers/mnudiary-perm.log`, run dirs `build/cpp_perm/<func>/`
(52 with a `permuter_out`), `build/regalloc_triage.tsv` (kinds), cpp_permuter's
`docs/passes.md`. Raw scripts and tables: `build/research/R28/`.

## Summary

- Smoke is good for **one** kind of near miss: a statement/declaration/temporary order or a
  small expression-form change in a function that is already the right size (triage kind
  "order", plus a "size" case that was really one expression form). Every result it ever
  produced (func_0017B918, func_00192BA4, func_0014D308, func_00199B3C, and EffSteam1Prim
  vfunc_08, which was blocked by the alias rule) appeared **within 2.5 minutes**, after only
  7, 18, 36, 630 and 878 compiles. In 52 runs nothing was found later: the other ~10 minutes
  of each run (5k-23k more compiles) produced nothing.
- It never helped "regs" (0 of 7 reached 0; only the two large ones moved, 28->17 and
  134->82), nor small "other" (delay-slot, constant-in-register or likely-branch
  differences: 0 of 6 with 1-5 edits moved at all).
- The score is a moderate proxy (Spearman 0.80 between triage edits and base score) with two
  exploitable flaws that produce "best" outputs that are not progress: dropping an
  instruction, and `remove_stmt` deleting a real initialisation (examples in section 4).
- Smoke's near-best outputs are useful to humans: Codex's hand match of func_001420F8
  (commit 3314559) is exactly Smoke's best-13 output (same moves of `names`, `total`,
  `old + theNum`). Nobody was told to read it.
- Biggest wins for the least work: 3 minutes per function instead of 10, run the 17 untried
  strict candidates first (9 are "order" with 2-5 edits, the profile of the hits), weight
  `remove_stmt` to 0, exclude "regs" and tiny "other".

## 1. Every candidate (2026-11-23 rounds, MnuDiary batch, pilot)

Base/best are scorer values (0 = identical bytes; a replaced instruction costs 1 or 3, an
inserted or missing one 5). "best" = base when Smoke found nothing better. Minutes: queue
rounds 10 min each (about 11 wall), first round 11 min, MnuDiary batch about 16 min; matches
ended the run as soon as they appeared (1.0-2.3 min). Kind "matched" = no longer in the
triage file: the 3 Smoke matches, plus func_0020544C and func_001420F8 which Codex closed by
hand later. "new-best events" is the checkpoint's `improvements` counter.

| function | file | triage kind | edits | base | best | rel. | compiles | new-best events |
|---|---|---|---|---|---|---|---|---|
| func_00192BA4 | unk/mnuBase | matched | 2 | 2 | 0 | 100% | 630 | 1 |
| func_0014D308 | unk/MrtMain | matched | 3 | 6 | 0 | 100% | 36 | 1 |
| func_0017B918 | unk/SctLayer | matched | -1 | 25 | 0 | 100% | 878 | 4 |
| func_0020544C | system/sysnowloading | matched | 3 | 10 | 10 | 0% | 8425 | 0 |
| func_001420F8 | mag/magloader | matched | 3 | 26 | 13 | 50% | 14878 | 3 |
| EffSteam1Prim__vfunc_08 | unk/EffWater1 | order | 16 | 77 | 0 | 100% | 7 | 1 |
| func_00199B3C | unk/MnuDiary | order | 26 | 34 | 0 | 100% | 18 | 2 |
| func_001A06E8 | mnu/mnuselect | order | 4 | 10 | 6 | 40% | 21914 | 1 |
| func_001BEBEC | unk/001BE2CC | order | 18 | 9 | 9 | 0% | 16799 | 0 |
| func_00188EC0 | mcd/mcdman | order | 2 | 10 | 10 | 0% | 13685 | 0 |
| func_001F2BCC | unk/TskMsgMan | order | 5 | 20 | 13 | 35% | 7189 | 2 |
| func_00142908 | mag/magloader | order | 5 | 21 | 14 | 33% | 15601 | 1 |
| func_001F5BDC | unk/DisplayMessage | order | 4 | 20 | 18 | 10% | 23342 | 1 |
| func_0014F72C | unk/ClrMain | order | 14 | 55 | 18 | 67% | 16085 | 6 |
| EffFog2__vfunc_05 | unk/EffFire1 | order | 17 | 25 | 21 | 16% | 14015 | 1 |
| func_001CB01C | game/gamman | order | 10 | 31 | 22 | 29% | 4787 | 3 |
| func_0017C7B0 | unk/WrdSrv | order | 16 | 83 | 28 | 66% | 17537 | 6 |
| func_00196EFC | unk/MnuPBook | order | 28 | 112 | 38 | 66% | 9527 | 5 |
| func_001DDC80 | game/gamtrg | order | 12 | 52 | 40 | 23% | 8638 | 1 |
| func_001C845C | game/gamman | order | 17 | 71 | 40 | 44% | 5632 | 5 |
| func_00209528 | system/sysnowloading | order | 22 | 103 | 57 | 45% | 8821 | 9 |
| func_001E3698 | game/gamsnd | order | 27 | 59 | 59 | 0% | 12284 | 0 |
| func_00209D4C | system/sysnowloading | order | 27 | 108 | 73 | 32% | 8066 | 6 |
| func_001883C0 | mcd/mcdman | other | 1 | 3 | 3 | 0% | 12251 | 0 |
| func_00188CD4 | mcd/mcdman | other | 1 | 3 | 3 | 0% | 13104 | 0 |
| func_002107AC | unk/0020ED9C | other | 1 | 4 | 4 | 0% | 9401 | 0 |
| func_0015D680 | unk/DwfMain | other | 3 | 5 | 5 | 0% | 12665 | 0 |
| func_0015D738 | unk/DwfMain | other | 3 | 5 | 5 | 0% | 12654 | 0 |
| func_00198CA8 | unk/MnuDiary | other | 14 | 45 | 7 | 84% | 9379 | 4 |
| func_0011DD40 | mag/maglifepc3 | other | 4 | 20 | 12 | 40% | 20189 | 1 |
| func_001FE87C | unk/TskEnemyMove | other | 4 | 16 | 12 | 25% | 8768 | 1 |
| func_0015FEE8 | unk/DwfMain | other | 7 | 13 | 13 | 0% | 7738 | 0 |
| func_0018F9CC | spr/sprtexture | other | 23 | 52 | 13 | 75% | 15609 | 4 |
| func_0019AFB0 | unk/MnuDiary | other | 13 | 23 | 20 | 13% | 13637 | 2 |
| func_0017820C | unk/EffMan | other | 5 | 34 | 21 | 38% | 17827 | 2 |
| EffBloodSpray1__vfunc_02 | unk/Eff0 | other | 8 | 26 | 25 | 4% | 12255 | 1 |
| func_00176430 | unk/EffLight2 | other | 10 | 46 | 26 | 43% | 11979 | 3 |
| func_00170158 | unk/EffBreath2Prim | other | 12 | 40 | 34 | 15% | 16221 | 1 |
| func_0019A054 | unk/MnuDiary | other | 15 | 47 | 42 | 11% | 8362 | 2 |
| MnuDiary__vfunc_06 | unk/MnuDiary | other | 26 | 107 | 46 | 57% | 10310 | 3 |
| func_001ECDD4 | unk/TskMsgMan | other | 4 | 121 | 73 | 40% | 5993 | 4 |
| func_0016A6B4 | unk/001693A4 | regs | 2 | 1 | 1 | 0% | 11513 | 0 |
| func_001C9C1C | game/gamman | regs | 4 | 2 | 2 | 0% | 5669 | 0 |
| func_00193A1C | unk/MnuPBook | regs | 3 | 3 | 3 | 0% | 9646 | 0 |
| func_001EC344 | unk/TskMsgMan | regs | 4 | 4 | 4 | 0% | 5851 | 0 |
| func_001F14CC | unk/TskMsgMan | regs | 5 | 5 | 5 | 0% | 7024 | 0 |
| func_001C9334 | game/gamman | regs | 28 | 28 | 17 | 39% | 5401 | 2 |
| func_001D5EC4 | game/gamstat | regs | 36 | 134 | 82 | 39% | 15066 | 5 |
| MnuDiary__vfunc_05 | unk/MnuDiary | size | 33 | 85 | 4 | 95% | 10755 | 4 |
| func_0016E438 | unk/Eff0 | size | 4 | 19 | 6 | 68% | 13919 | 3 |
| func_0020F98C | unk/0020ED9C | size | 6 | 16 | 9 | 44% | 7534 | 3 |
| func_00194688 | unk/MnuPBook | size | 5 | 25 | 21 | 16% | 9847 | 2 |
| func_0019BD6C | unk/MnuDiary | size | 8 | 24 | 24 | 0% | 12324 | 0 |

### By triage kind

| kind | runs | reached 0 | best <= 10 | improved at all | median relative improvement |
|---|---|---|---|---|---|
| order | 18 | 2 (EffSteam1Prim vfunc_08, 199B3C) | 5 | 15 | 34 % |
| other | 18 | 0 | 6 (the 1-5 edit ones never moved; 198CA8 reached 7) | 12 | 14 % |
| regs | 7 | 0 | 5 (untouched: base already 1-5) | 2 (only the 28- and 36-edit ones) | 0 % |
| size | 5 | 0 (MnuDiary vfunc_05 reached 4) | 3 | 4 | 44 % |
| matched later (kind lost) | 5 | 3 (192BA4, 14D308, 17B918 pilot) | | | |

Hit rate by edits: <= 3 edits 2 of about 9 tried; 10-30 edits 3 of about 26; > 30 edits
0 of 4 (vfunc_05: 85 -> 4, no match). Overall about 5 usable results in about 55 runs (9 %).
The 20-candidate round of 2026-11-23 had one score-0 (EffSteam1Prim, refused for 74 alias
declarations) and merged 0.

Throughput is about 23 compiles/s with `-j5` (func_0018F9CC: 15609 compiles in 11 min), so a
10-minute run is 10k-23k candidates, 15-25 % of which fail to compile.

## 2. What the winning mutations were (diff base vs best in the run dirs)

| function | base -> 0 | compiles | mutation (cpp_permuter pass) |
|---|---|---|---|
| func_0014D308 (size 0x1C vs 0x18, 3 edits) | 6 -> 0 | 36 | `unsigned long long bit = ...; return bit != 0;` became `bool cond = ...; if (cond) return true; return false;` (`bool_return`) |
| func_00192BA4 | 2 -> 0 | 630 | reorder of declarations and of two independent statements (`temp_s6 = arg4 * 0x10` earlier, `temp_s0 = arg2 * 0x30` later) (`reorder_saves` / `move_stmt`) |
| func_0017B918 | 25 -> 0 | 878 | one float local (`s`) reused for `w` and `h` instead of two locals, one `h` inlined into a condition (`reuse_local`, `inline_local`); the earlier steps 25 -> 22 -> 11 -> 6 were the same changes one at a time |
| func_00199B3C (MnuDiary) | 34 -> 0 | 18 | `int cur2 = arg1 * 2` sunk to its use; `e = &arr[idx]` moved above `zero`; `zero` and `next` swapped (`move_stmt`, `sink_decl`) |
| EffSteam1Prim vfunc_08 | 77 -> 0 | 7 | one statement moved: `v = D_002F2EC0;` up above the `alpha` computation (`move_stmt`) |

Near misses (best <= 10), remaining difference read with `match.py --src` on the best
`source.cpp` (`build/research/R28/best/`):

| function | base -> best | what is left |
|---|---|---|
| MnuDiary vfunc_05 | 85 -> 4 | 4 instructions: `daddu $v0,$s2,$zero` vs `$zero,$zero`, and `$v0` vs `$v1` twice. The game uses the constant 0 where ours copies a live register: register/lifetime choice |
| renderPreMain (EffWater1) | 6 -> 4 | 4 instructions: `lwc1 $f3/$f4` pair swapped (load order of two floats). Needs a PS2_REG pin or the other load order; not a cpp_permuter mutation |
| func_00198CA8 (MnuDiary) | 45 -> 7 | the game keeps a loop counter in `$a0` with `a1 = 1`; ours uses callee-saved `$s2` (live range / constant hoist) |
| func_001A06E8 | 10 -> 6 | false progress: the best is 0x60 bytes, the game 0x64 |
| func_0016E438 | 19 -> 6 | best is 0x220 bytes vs 0x224 (size not fixed) |
| func_0020F98C | 16 -> 9 | size differs by 8 bytes |

## 3. Why five stalled ones stalled (remaining diff of the base, `match.py --diff`)

| function | base | remaining difference | missing mutation |
|---|---|---|---|
| func_001883C0, func_00188CD4 (mcdman) | 3 | one instruction: ours puts `lw $v1,0x64($s0)` in a branch delay slot where the game has `addiu $v1,$zero,3` (constant already in `$s2`) | delay-slot filling and constant CSE are not source-level reorders; the source is a raw M2C switch (`M2C_FIELD` offsets), so the arm grouping is probably wrong |
| func_00188EC0 (mcdman) | 10 | three stores swapped (`0x64`, `0x58`, `0x60`) in the `case 0:` arm; 13.7k compiles never found it | the order comes from switch-arm tail merging; `reorder_cases` does not reach it |
| func_001C9C1C (gamman) | 2 | a temp in `$a0` vs `$v0` and a stack-argument store (`sw $v0,0($sp)` vs `$a2`) | register pin or temp copy; not in the pass list |
| func_001F14CC (TskMsgMan) | 5 | `$a2`/`$a3` copies swapped (4 `daddu`) | parameter or declaration order, `register` pin; pure register numbering |
| func_0015D680, func_0015D738 | 5 | `bnez` vs `bnel` (branch-likely) and `$a0` vs `$v0` for `andi` | the if/else shape that makes gcc fill the delay slot from the target |

Pattern: stalls are (a) register numbering (needs PS2_REG pins; R23 counted 5 of 28 Codex
hand fixes as pins), (b) delay-slot / likely-branch shape, (c) differences outside the body
(callee return type or `throw()`: func_0020544C, "prologue lui schedule", was fixed by
making two callee declarations `void`), and (d) M2C code with raw offsets whose structure is
wrong.

## 4. Is the score a good proxy? Is 10 minutes enough?

Proxy:
- Base score tracks triage edits (Spearman 0.80, n = 52), but score/edits ranges from 0.5
  to 30 for the same count of differing words, because a pure reorder costs 5 + 5 per moved
  instruction (SequenceMatcher: delete + insert) while a register change costs 1. So
  "order" candidates look far away (EffSteam1Prim: 77 for one statement move) yet are the
  easiest.
- A lower score does not always mean fewer wrong words:
  - func_001A06E8: best 6 < base 10, but the best candidate is 0x60 bytes against the
    game's 0x64 (a dropped instruction beats a reorder). Same for func_0016E438.
  - func_0018F9CC: best 13 (from 52) deleted `var_v1 = 0x18;`, leaving an uninitialised
    induction variable. That is `remove_stmt`, a semantics-breaking pass (the cpp_permuter
    README: passes "don't prove" equivalence). It lowers the score and cannot be correct.
- The other bests inspected (func_0014F72C, func_001420F8) are behaviour-preserving moves and
  scope changes; the 17B918 trace shows a genuine stepwise gradient.

Timing:
- Output dirs are copied out of the container at the end of a run (all mtimes are equal) and
  the checkpoint keeps only counts, so the time of each improvement is not logged. The best
  evidence is the compile counts at the five hits: 7, 18, 36, 630, 878, all under 2.5
  minutes; every failure had 5k-23k compiles. The improvement counter was 0-9 per run. No
  run that had not matched by about 4k compiles (3 min) matched later.
- The one long partial is MnuDiary vfunc_05 (85 -> 4 in a 16-minute run): not a match, and
  its remaining 4 words are register-class issues Smoke cannot fix.

## 5. Recommendations, ranked by expected yield per cost

1. **Minutes per function: 3 instead of 10.** Saves about 70 % of the queue time with no
   known loss (all hits < 2.5 min). Cost: one flag. Use the time for items 2 and 6.
2. **Run the 17 untried strict candidates first**, "order" with 2-5 edits first: they match
   the profile of the hits (2 and 3 edits matched after 630 and 36 compiles). Expected 1-2
   matches for about 50 minutes at 3 min each. Untried now: func_001790E4, func_0017AFD8,
   func_00173948, func_00173DF8 (order, 2 edits); func_001F2920 (order, 2);
   EffCameraAnim1 vfunc_05 (3); func_001D58D8 (4); func_00213C6C, func_00213D00 (5);
   func_001BEDC0 (likely, 1); func_001881C0, func_00189B7C, func_001892B0, func_001677D0,
   func_001685C0 (other, 1-5, low odds); func_00166DA4 (17); MnuMap vfunc_05 (24).
3. **Filter by kind and edits, not by score.** Keep "order" (edits <= 30), "other" with 5-30
   edits, and "size" only when the difference is one instruction and edits <= 6 (the 14D308
   case; the pool is 11 functions, 4 already tried with no further hit). Drop "regs" (0 of 7;
   use `tools/regalloc.py` or a PS2_REG pin search), "other" with <= 3 edits (0 of 6 moved),
   and anything over 40 edits. A base-score cutoff is a bad filter: the steam match was base
   77 and the 192BA4 one base 2.
4. **Fix the proxy in `tools/cpp_perm_score.py`** (small change, removes false bests):
   - penalise or reject a candidate whose function length differs from the target's when the
     base length equals it (for example 10 per word of difference);
   - when the lengths are equal, use min(SequenceMatcher cost, count of differing words):
     pure reorders then have a gradient (3 swapped stores cost 3, not 10).
5. **cpp_permuter options in `tools/cpp_perm.py`.** Today it passes no `-p` or `--weight`
   (all passes, default weights). Pass `--weight remove_stmt=0`; lower the passes that exist
   for VC6 and cannot matter with gcc 2.96 (`inequalities`, `locals_to_array`, `named_op`,
   `use_getter`, `cast_operand`); raise those behind the hits (`move_stmt`, `reorder_saves`,
   `reuse_local`, `split_local`, `bool_return`, `inline_local`, `sink_decl`, `hoist_decl`,
   `chain_assign`). No per-pass statistics are logged, so this is judgement from the five wins
   in section 2; confirm with `--show-timings` or by logging the pass in `diff.txt`.
6. **Resume rather than restart partials** (`--resume`, same options) for runs whose best
   dropped by 50 % or more and ended <= 10: MnuDiary vfunc_05 (4), func_00198CA8 (7),
   renderPreMain (4); func_0018F9CC (13) only after removing `remove_stmt`. Cheap, low
   expectation: the rest is register numbering.
7. **Show workers the near-best output, not only the queue.** Smoke's best at 25-60 % of
   base already held the solution for func_001420F8. Log the path of the best `diff.txt` for
   each partial in the queue log or `notes/NEXT_SESSION.md`. Cost: a few log lines.
8. **A second pass with Cyrax rewrites (`tools/permute.py`) has low yield.** R23 recorded 0
   real finds in 44 functions, and what the Smoke stalls need (PS2_REG pin retargeting
   from the asm diff, callee return type / `throw()` toggles, delay-slot shape, typed
   members) is not in Cyrax either. If a new tool is worth building, make it a small
   pin/declaration search: for regs-only or float-pair diffs, try
   `register T x PS2_REG("$fN")` from the differing register pairs; for "prologue schedule"
   diffs, toggle callee extern return types `int` <-> `void` and `throw()`. About a day;
   plausible hits among the 7 "regs" and several "other". Do it after items 1-4.
9. **Stop using Smoke** on "regs" and on raw-offset M2C functions (`M2C_FIELD` everywhere,
   such as mcdman): the rules check refuses the match anyway (EffSteam1Prim: 74 alias
   declarations) and the diff is not a source-order problem. Type the members first, then
   permute.

## Method notes and limits

- Kinds come from `build/regalloc_triage.tsv` as it is now (230 rows); already matched
  functions are gone from it, hence five rows with kind "matched".
- No per-improvement timing exists; the minutes analysis uses compile counts at the hits.
- Remaining diffs of stalled bases: `match.py --diff --extra=-DNON_MATCHING`
  (`build/research/R28/*.diff.txt`); of best outputs: `match.py --src` on the run's
  `source.cpp` (`build/research/R28/best/`).
- Nothing in src/, config/ or tools/ was changed and no permuter was run.
