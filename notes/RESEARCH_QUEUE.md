# Research queue

Questions for research subagents (Claude Sonnet): read-only investigations
whose findings the coordinator checks and applies. Anyone can add one under
"Open"; the coordinator takes the first open item when no investigation is
running, at most about four a day, and none while Claude's quota is tight
(it shares the coordinator's). A finding is applied only once the
coordinator has checked its evidence (a full build with `build/ok`, and
`match.py` on every file touched); the result goes under "Done".

Format: `- [ ] R<n> <title>`, then what to find out, what is known, and
where to look.

## Open

- [ ] R5 unk/HfmMain: the small file before it. 0x2EF238-0x2EF260
  ("18MagLifeWindowDebug", "8MagLife0") ends at HfmMain's first table;
  the MagLifeWindowDebug code (constructor func_00144214, wrappers
  0x144244-0x1445D0 on D_006FBD80) seems to be its own file. Find its
  text start (0x143D3C-0x144214 are scene-camera helpers on +0x2AB40:
  magsceneif's or the new file's?) and a likely name (asserts, RTTI).
- [ ] R6 unk/001D1BEC, unk/EffFindItem1, unk/BdlMain, unk/DwfOutAtkFar:
  the same question for each (split ranges in notes/NEXT_SESSION.md and
  in the memory of 2026-11-15: 001D1BEC in (0x1D27DC, 0x1D3B44], second
  rodata 0x2FC100; EffFindItem1 from ~0x176A34, rodata 0x2F2AC0; BdlMain
  ~0x14C2FC, rodata 0x2EF690; DwfOutAtkFar from 0x161230, rodata 0x2F10C0).
- [ ] R7 game/gamtrg func_001DD00C and func_001DBA3C: each matches as a
  function, but compiling it moves the .rodata references of later C++
  functions (func_001DD558, func_001DEAAC, func_001DEE78; func_001DBB74,
  func_001DBC5C). Find what in their .rodata the compiler emits in
  another order than the asm piece (strings? the table?) and the source
  shape that gives the game's order.
- [ ] R8 Recurring near-miss patterns: across the ~100 NON_MATCHING
  attempts (`// NON_MATCHING:` notes, tools/permute_queue.py --list),
  group the causes (bnel vs bnez, $v0/$v1 swaps, store order, delay-slot
  placement) and find, in already-matched functions with the same
  instruction patterns, the source idioms that produce them. Deliver
  ready-to-paste bullets for docs/DECOMPILING.md.
- [ ] R9 Other wrong boundaries without jump tables: scan every file's
  .rodata start for the signs found so far (RTTI names of the previous
  file's classes at the start, an assert __FILE__ string of another file
  inside the range, a function using data of a file it does not belong
  to) and list suspects with evidence.

- [ ] R11 C++ matching lessons from other ee-gcc decomps: read the
  docs/CONTRIBUTING of TheOnlyZac/Sly1, Komasia/sly2-decomp, ethteck/kh1
  and denzi-gh/crashwoc-decomp-ps2 (web), note each one's exact compiler
  and flags, and extract what applies to ee-gcc 2.96 C++ here (vtables,
  RTTI and key methods, pointers to members, jump tables and .rodata
  boundaries, inline emission, permuter use with C++, objdiff setup) as
  ready-to-paste bullets for docs/DECOMPILING.md, marking what is already
  there.
- [ ] R12 objdiff for this project: can encounter/objdiff compare our
  build/match objects against the game's per function (its config for a
  splat PS2 project, e.g. Sly 2's), and would it beat tools/match.py's
  diff for workers? A short how-to if yes.

## Done

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
