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

- [ ] R15 R9's leads, not applied yet: (1) "mnu/mnuSelectLanguage.cpp"
  (0x2FB330) is game/gamman's .rodata and is the __FILE__ of asserts at
  0x1BDCB8, 0x1BDD64, 0x1BDDDC: a second file inside gamman's range (find
  its text and .rodata bounds; gamman is partly decompiled, so its C++ must
  move with it). (2) "task/naga_chunk.cpp" (0x2FEFF0) sits in
  unk/TskCamera's .rodata and is used at 0x1FC4F0-0x1FCB14, so naga_chunk's
  real text is at TskCamera's end and its row at 0x1F8F70 is wrong.
  (3) 29 files whose .rodata starts with another class's type names
  (build/workers/research-R9.md, table (a)); check each against the
  previous file's code before moving. (4) unk/EventTestTask reads
  D_00301AF8 (8 zero bytes before its .rodata start).
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
- [ ] R11 **[flash]** C++ matching lessons from other ee-gcc decomps: read the
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

- [ ] R13 mw/i3d's architecture (the owner's outside brief, 2026-11-15),
  READ-ONLY: (A) MagSystem's version check is known (src/mag/magsystem.cpp
  ~250-275: 36 i3d type sizes checked through func_0021F1A8(i), message
  "i3d_package_version 050121-stable-050826"); (B) inventory every call
  from game code into 0x218500-0x237D00 (address, callers, known or
  provisional name, prototype evidence); (C) classify them (resource
  loading, node hierarchies, matrices, animation, lighting, textures,
  render state, DMA/VIF/VU, memory); (D) compare the structures/offsets
  DogModel, DogTexInfo, DogLightPool and MagSystem use with the public
  model parsers (Murugo's Misc-Game-Research PS2/Rule of Rose/mdl2obj.py,
  Durik256's Noesis fmt_i3dg.py: 0x10-byte nodes, types 0x25 materials,
  0x2A bones, 0x2D meshes, 0x59 instances, VIF) and the 36 sizes; (E) map
  i3d functions to Ape Escape 3's copy (disc/ape3/SCPS_150.96, see the
  Done entry below) to find which of its strings/asserts name them; (F) a
  minimal compatibility API for the PC/Vita ports (not just "replace the
  renderer"). Needs Sonnet (judgement) plus [web] for the parsers.
- [ ] R14 **[web]** Other games built on SCE Japan's "i3d package" (2005-
  2006, i3d_package_version 0501xx; formats I3D_BIN/I3D_I3M/I3D_I3C; VU
  overlays .DVP.overlay..0x0.3420215670.9.0): which ones, and does any
  have symbols (debug ELF, prototype, .map) or a decompilation? Ape
  Escape 3 is one; Rule of Rose was published in Japan by SCE.

## Done

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

