# Research queue

Questions for research subagents (Claude Sonnet): read-only investigations
whose findings the coordinator checks and applies. Anyone can add one under
"Open"; the coordinator takes the first open item when no investigation is
running, at most about four a day, and none while Claude's quota is tight
(it shares the coordinator's). A finding is applied only once the
coordinator has checked its evidence (a full build with `build/ok`, and
`match.py` on every file touched); the result goes under "Done".

Format: `- [ ] R<n> <title>`, then what to find out, what is known, and
where to look. Items marked **[flash]** are survey work (scans,
classifications, reading other projects' docs): they go to a cheap model
with `tools/orca/research_flash.sh R<n>` (DeepSeek V4.1 Flash, read-only,
in an idle worktree) instead of a Sonnet subagent; the others need
judgement and go to Sonnet.

## Open

- [ ] R16 Split unk/TskCamera (game/gamman done in c6d41ad; R15's findings, Sonnet,
  2026-11-16; needs moving decompiled C++ between files, so a careful
  session, not a worker):
  - mnu/mnuSelectLanguage is text [0x1BDAE4, 0x1BE2CC), .rodata from
    0x2FB1A0 ("location.tm2"; "mnusllg.rpk" ends 0x2FB398), .data from
    0x2B89E0. Evidence: its asserts (0x1BDCB8...), MagLifeMenuSelLang calls
    func_001BDC00/func_001BDE58 on self+0x40 (src/mag/maglifemenu.cpp:49-72),
    all functions use one layout (+0x78C, +0x1078..0x1084). 14 of its 16
    functions are decompiled in src/game/gamman.cpp (lines ~315-519).
  - After it, 0x1BE2CC (FileReader, a date helper with the days table
    0x2B8DA8; .rodata 0x2FB398, tags BIT/CDH/CDF/PRP) is another file;
    game/gamman proper has .rodata from 0x2FB3C0 ("game/gamman.cpp" at
    0x2FB3C8, first used by 0x1C0D70) and text from at most 0x1C0D44 (exact
    start unsettled; no function in 0x1BE2CC-0x1C0D44 reads .rodata).
    gamman.cpp has compiled switches, so its .rodata must start at a
    multiple of 16: 0x2FB398 cannot be gamman's.
  - Before it, 0x1B64C4-0x1BDAE4 is probably not gamman either (no
    gamman.cpp assert before 0x1C0EF8; its data points into the previous
    mnu file's .rodata, "mnuboard.rpk").
  - task/naga_chunk is text [0x1FC47C, 0x1FCC20), .rodata 0x2FEFF0-0x2FF010
    ("task/naga_chunk.cpp", "host:%s"); its row at 0x1F8F70 is PLScenePlay's
    constructor + deleting destructor, which belong to unk/001F836C (whose
    .rodata start 0x2FE888 must become a multiple of 16: it has 2 jump
    tables). TskCamera's .rodata starts at 0x2FEA00 (0x2FE980-0x2FE9FF are
    001F836C's type names), and the range is several files: TskSnd
    (vtable 0x1F8FC4), TskAttack, TskDamage, TskCamera (~0x1FBBA4, .rodata
    0x2FEF80).
  - unk/WrdSrv's .rodata start (EffWater type names) stays unsettled.

- [ ] R18 Deep read of R17's top 3 repos (Sonnet, after R17): concrete
  techniques we could adopt for our open problems: NON_MATCHING near
  misses (register allocation, bnel, store order), the permuter queue,
  worker briefs, and keeping matched C++ compilable on PC (our PS2_REG
  macro). Each lead with the repo file it comes from and how we would try it.
## Done

- [x] R17 Survey of 10 PS2 decomps (2026-11-18, Flash): all use -O2
  (we are the only -Os); gt4-decomp is ee-gcc 2.96 C++ at 98 % with an
  agent harness and knowledge/ee-gcc-2.96.md; god-hand (2.96) audits
  forced registers and per-file flags; sotc (2.96) has per-file cflags
  (-fno-rerun-loop-opt). gt4 counts register-asm pins as fakematches and
  rac1 forbids them (our PS2_REG). Top 3 for R18: gt4, god-hand, sotc.
- [x] R7 gamtrg func_001DBA3C / func_001DD00C (2026-11-16, Codex): both
  match in the whole object (cd350e0, 85b1060). Cause: in the game, a
  jump table is followed by padding our compile does not emit (5-entry
  table: 4 bytes; 10-entry: 8 bytes), so the next .rodata moved. Codex's
  fix forces the next item's alignment: the float table D_002FC748 as an
  ALIGNED(8) const array, and the alloc source string as a named
  ALIGNED(16) "game/gamtrg.cpp". Byte-identical, but the original source
  shape (why the padding is there) is still unknown: revisit if another
  file shows the same pattern.
- [x] R13 mw/i3d's architecture (2026-11-16, Sonnet): 143 entry points,
  1193 call sites, grouped; the version table compared with Ape Escape
  3's; format checks against pxdl/Murugo; AE3 counterparts; a port API.
  All in notes/I3D.md "Interface used by the game".
- [x] R12 objdiff (2026-11-16, Sonnet): feasible, medium effort, a
  complement to match.py (which stays the authority). objdiff reads the
  R5900 ISA from e_flags (or mips_instr_category) and pairs HI16/LO16.
  Needs: per-file target objects (whole-file asm + its data chunks, one
  `as`/`ld -r`), a -DSKIP_ASM branch in include_asm.h so INCLUDE_ASM
  functions do not count as matched, base objects through fix_hi16/strip,
  a generated objdiff.json (custom_make "tools/dock ninja"), as Sly1's
  configure.py --objects does. Risk: named D_ symbols in the target vs
  .LC/.rodata+off in ours read as reloc mismatches (symbol_mappings or
  object rewriting). `objdiff-cli diff ... --format json` gives a
  per-function diff for workers; `report generate` per-unit percentages
  (decomp.dev would need a local report: the ELF cannot be in CI).
  Next step if wanted: prototype bed/bedpad by hand.
- [x] R5, R6 The five files with jump tables and a .rodata start off 16
  (2026-11-16, Sonnet + coordinator): applied 2aee43d and the EffMan
  commit. New files unk/MagLifeWindowDebug (head of HfmMain),
  unk/BdlOutAtk, unk/DwfOutFort, unk/001D3B44, unk/EffMan; EffFindItem1's
  methods merged into unk/EffLight2. All 185 files with tables now start
  at a multiple of 16. Uncertain text starts (rodata is certain):
  001D3B44 in (0x1D27DC, 0x1D3B44]; BdlOutAtk could start at BdlOutSearch
  (0x14C1F4); DwfOutFort at DwfOutParts; MagLifeWindowDebug's 0x143D3C-
  0x144210 could be magsceneif's tail.
- [x] R15 R9's leads (2026-11-16, Sonnet): applied 4cd12d3, the .rodata
  starts of MagLifeBwnModeSit (0x2EBC60), MnuPBook (0x2F7D30) and
  maglifepc2 (0x2EA208); the larger splits are R16.
- [x] R14 Other i3d games (2026-11-15, Flash, web): only Rule of Rose and
  Ape Escape 3 are known; no symbols anywhere; Million Monkeys untested.
  Notes in notes/I3D.md.
- [x] R11 Lessons from Sly1/Sly2/kh1/crashwoc (2026-11-15, Flash): their
  compilers are 2.95.x (Sly) and 2.96 C-only (kh1), mostly -O2/-ffast-math,
  so little transfers; four bullets added to DECOMPILING.md. Unchecked
  leads: Sly2's vtable entry layout vs ours; an -O2 experiment on a stuck
  file; objdiff setup (Sly1 configure.py --objects) for R12.
- [x] R9 Other wrong boundaries (2026-11-15, Flash): applied 473875d,
  0x20313C and .rodata 0x2FF578-0x2FF61F moved to unk/TskEnemyMove (its
  func_00202FE4 reads the tables after them). The other leads are R15.
- [x] R8 Near-miss patterns (2026-11-15, Flash): branch-probability
  flips, register order, store order, type tells from loads, tail calls;
  bullets added to docs/DECOMPILING.md "What this compiler does".
  Unsettled: what flips `addu` operand order.
- [x] R1 game/gamtrg's .rodata start (2026-11-15, Sonnet + coordinator):
  0x2FC418 -> 0x2FC420; jump tables are 16-aligned (all 267). Applied in
  bcfa96a; +3 functions matched.
- [x] R2 The 20 files with jump tables and a .rodata start not a multiple
  of 16 (2026-11-15): 11 started on the previous file's RTTI names
  (08bd270), EventTestTask on padding and mnusvld three functions early
  (5cac105). The other 7 are R3-R6.
- [x] R3 unk/001A6830 (2026-11-15, Sonnet, high confidence for the main
  point): no split inside it; 0x1A6830-0x1A90EC is mnu/mnusvld's (one
  this layout, cross calls, its .data table points at those strings, all
  tables 16-aligned from mnusvld's 0x2F9100). The next file starts at
  0x1A90EC, MagLifeMenuTitle's constructor, rodata 0x2F9820: still
  called unk/001A6830 (likely mnu/mnutitle, from "mnutitle.rpk"; no
  assert names it). Applied: 507 lines of C++ and 36 .rodata pieces moved
  to mnusvld.cpp, split_files.py rows named '-' drop a generated start.
  Open from it: where the title file ends (around func_001AB474, the
  MagLifeMenuOpt constructor, or func_001AB04C), and its real name.
- [x] R4 game/gamsnd / unk/TskMtnMove (2026-11-15, Sonnet, high
  confidence): TskMtnMove starts at its constructor 0x1E7F28 (.rodata
  0x2FD940, after a second "8CmnITask" that ends the previous unit);
  0x1E46B8-0x1E7F27 is gamsnd's (GamMan's funcStr/playStr inlines jump
  into it, gamsnd calls 0x1E5660 15 times, D_007B2580 and the snd API,
  its tables 16-aligned from 0x2FD750). func_001E9A34 is TskMtnMove2's
  last method (D_002FDA60 points at it), so TskMsgMan starts at
  0x1E9A3C. Applied: 480 lines (36 C++ functions) moved to gamsnd.cpp.
  Open from it: TskTest/TskLogger (to 0x1E7F27) may be a small file of
  their own, start at most 0x1E7E50 (medium-low).
- [x] Trade demo SLUS_280.63 (owner's disc "SLUS-28064 TRADE DEMO",
  2026-11-15, coordinator): stripped like the retail (no .symtab, .mdebug,
  .pdr, DWARF or .comment; only the VU overlay sections), the same 86
  source names, 0x800 bytes less code; one inline differs
  (MagLifeBwnCtrlModeHug::setMode only in retail). No names to gain.
  Kept in disc/demo/ (ignored by git).
- [x] R10 Chulip (SLUS-20742, owner's disc, 2026-11-15, coordinator): no
  shared engine. Its ELF is stripped, C only (no .cpp), and has none of
  I3D_BIN/I3D_I3M/I3D_I3C, i3d, MagLife, Dog*, GamMan. Instruction-shape
  24-grams (opcode/funct only) shared with it: mw/i3d 13 of 28,166 (noise),
  mw/sound 0, game code 0, but the Sony SDK libraries 6,315 of 28,064: the
  same SDK versions in part. So chulip-decomp can only help with our sdk/
  files (0 %, and the ports replace the SDK anyway): low priority. ELF kept
  in disc/chulip/ (ignored by git).
- [x] Ape Escape 3 / Saru! Get You! 3 (SCPS-15096, owner's disc, 2026-11-15,
  coordinator): it links the same i3d library. Instruction-shape 24-grams
  of our mw/i3d found in its ELF: 19,152 of 28,166 (68 %; Chulip: 13);
  game code 0 %, sound 0 %, SDK 93 %. Its strings: "i3d_package_version
  050121" (ours: "050121-stable-050826", a later stable branch of the same
  package), I3D_BIN/I3D_I3M/I3D_I3C, I3DROOT_NODE, "I3D Trash", I3dRender,
  I3mPosture_s; the same VU overlay sections. So i3d is SCE Japan's
  "i3d package", not Punchline's own. Its ELF is stripped too (no
  .symtab). Kept in disc/ape3/ (ignored by git).
- [x] Ape Escape 3 US demo (SCUS-97548 disc, game at /APEESC3/APEESC3.ELF,
  owner's image, 2026-11-15): stripped too (no .symtab or debug
  sections), the same "i3d_package_version 050121", 6.49 MB vs the
  Japanese retail's 6.34 MB; only 5 more C++ function-name strings (its
  own game code: LoadScreenProcessState, Recorder, SoundStream...), none
  about i3d. Kept in disc/ape3demo/ (ignored by git).

