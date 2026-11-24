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

- [x] R24 Split mw/sound into its real files from PoPoLoCrois's debug info
  (2026-11-23). disc/popolo/SCPS_150.63 (owner's disc, git-ignored) keeps
  .symtab, DWARF 1 .debug and .line, and its RX library is byte-identical
  to ours (tools/donor_symbols.py: 586 names, symbols/donor_symbols.tsv,
  313 of the 583 functions in mw/sound). Find, for every donor function
  that we matched: its compile unit / source file name (DWARF 1
  TAG_compile_unit AT_name, .line ranges, or STT_FILE entries in .symtab)
  and its order inside that unit; map them to our addresses and propose
  file boundaries for mw/sound (rows for config/splits_manual.tsv: start,
  end, name, evidence), with .data/.rodata/.bss boundaries where the donor
  shows them. Note gaps (our functions with no donor match) and whether
  they fall inside one donor file. Derive names/paths only, never code.
  Tools: pyelftools (DWARF 1 is not supported: parse .debug by hand, the
  format is in zipzip11/ps2-dwarf1 and the DWARF 1.1 spec). Read-only;
  output notes/research/R24-mwsound-split.md plus a TSV in build/research/.
  Done 2026-11-23 (Sonnet): no RX file names in the donor (its DWARF covers
  only game code) but one .text section symbol per object gives 25 objects;
  applied as mw/sound/*, mw/sys/*, mw/file/*, mw/thread/*, mw/gs/vsync
  (placeholder names), full build green. Then renamed to the real file
  names (rx/rxsnd, rx/sndse, rx/rxfile, rx/filecdrom...) from Arc the Lad's
  hidden 2002 debug build (.mdebug file descriptors). R25 must look for RX types in
  the rx/include headers the DWARF does list (rxgeom.h, rxpkt.h...).
- [x] R25 RX library types (2026-11-23; source changed: PoPoLoCrois's DWARF
  covers only its own code and rx graphics headers, see R24; Arc the Lad's
  2002 debug build, disc/arc_koga/DATAIMG_KOGA_MAIN.ELF, has .mdebug with
  stabs, which should hold the RX structs: read those instead). From
  the same .debug: the structs, enums and function prototypes of the RX
  library (rxSnd*, rxSys*, rxFile*, rxTh*, rxGs*, rxmpeg), with member
  names, offsets, sizes and types, and which ones our code uses (our
  snd/rxmpeg, callers of rx* in src/). Output a proposed header layout
  (include/rx/*.h, one per original header if the DWARF shows them) in
  notes/research/R25-rx-types.md; names and types only, no code. Depends
  on R24's DWARF parser (reuse it).
  Done 2026-11-23 (Sonnet): the RX library in Arc's build was compiled
  without -g, so no internal structs and no prototypes; only the public API
  types its game code included (tagRXFileBranchParam, tagRXFileStrMarkParam,
  tagRXSysRpcClientData, callback typedefs with return types, RX_* enums),
  all checked against our asm (EnableMark, EnableBranch, rxSysRpcOpen/Call:
  no disagreement). Drafts in build/research/R25/include/rx/ (to move into
  include/ when rx/ is decompiled). Appendix A lists Arc's static function
  and variable names per RX file (SlotAlloc, gFileMgr...): candidates for
  our unnamed rx/ functions by size and call graph, not yet applied.
- [ ] R27 Where to pay the readability debt cheapest (2026-11-23; partly
  answered by tools/retype.py: only ~150 raw offsets sit on a class-typed
  base, and their headers lack those members; the rest are int arg0 in
  m2c code, i.e. G-task work. Keep R27 for ranking those).
  tools/rules_check.py --list gives 2,395 raw offsets and 3,501 alias
  declarations in matched code (config/rules_check.tsv). Rank files by
  offsets that a header already names (the class header exists and has a
  member at that offset) vs offsets that need a new member; group by
  class; estimate the effort per file; list the alias declarations that a
  real prototype could replace without changing the bytes (same arg types
  in registers). Exclude the G8-G14 files reserved for Neon/Argon
  (build/workers/fable-tasks.tsv) and files a worker owns
  (build/workers/codex-owns.txt). Output
  notes/research/R27-readability-debt.md: a per-file plan, top 15 first.
- [ ] R29 What rule-of-rose-recomp knows (2026-11-24; [web]).
  https://github.com/ptfpinho23/rule-of-rose-recomp (MIT, Pedro Pinho):
  a static recompiler of the PAL release (SLES-542.18) to x86-64, with a
  hand-written PS2 runtime (recomp/rt/: kernel HLE, GS/VIF/VU1/IPU, IOP
  modules incl. iop_rxsnd.c for the game's RXSNDDRV.IRX, memory card).
  Read recomp/NOTES.md, docs/STATUS.md, recomp/docs/ (rxsnddrv.md) and
  recomp/rt/iop_rxsnd.c. Find out: (1) every PAL game address it names
  (pad read 0x101ccc, VU1 builder 0x221000, camera 0x228b80, scheduler
  0x24c5a0, ...), mapped to NTSC with the code-bytes method of
  tools/map_pal_names.py (disc/pal/SLES_542.18), as name candidates with
  their evidence; (2) the RXSNDDRV RPC protocol (command ids, packet
  layouts) against our rx/ snd code and rxSnd* callers, for names and
  types; (3) which runtime parts the PC/Vita port could reuse (MIT allows
  it with attribution) and what they assume. Names and facts only, no
  code copied. Output notes/research/R29-recomp.md.
- [ ] R30 Check RozuRecomp's SDK/libgcc name leads (2026-11-24; [flash]).
  RozuRecomp (github.com/RibhuNoodleBoodle/RozuRecomp, GPL, PS2Recomp on
  our NTSC SLUS_214.48) names ~29 functions we leave unnamed; the list is
  in build/research/R30/rozu_leads.txt (not committed: its names come
  from PS2Recomp's signature database). Most are tiny libmpeg accessors
  (sceMpegDispWidth, 0x10 bytes), libcdvd/sif/tty wrappers, kernel TLB
  handlers and libgcc exception helpers (__sjthrow...). Byte signatures
  that short collide (sceVu0ClampVector is given to three addresses), so
  confirm each with independent evidence: callers and argument use, the
  neighbouring named functions of the same library (link order), strings,
  our donors (tools/donor_symbols.py). Output a list of confirmed names
  with their evidence, for config/symbol_addrs_manual.txt. main was
  confirmed and applied (crt0's last call).
- [x] R28 Which near misses Smoke can close (2026-11-23). Smoke
  (tools/cpp_perm.py + tools/cpp_perm_queue.py, log
  build/workers/cpp-perm.log, runs in build/cpp_perm/) has 3 matches in
  its history; the 11-23 round took 20 candidates (exact size, right
  relocations) with no new match. From the log and the run directories:
  base score vs best score per candidate, minutes spent, which mutations
  improved the score, and what the remaining diff is (registers only,
  instruction order, extra/missing instruction). Recommend: candidate
  filter (base score cutoff, size), minutes per function, and whether to
  use more of its mutation passes or a second pass with Cyrax rewrites.
  Output notes/research/R28-smoke-yield.md. Done 2026-11-23 (Sonnet):
  hits are small order/expression-shape near misses, all within 2.5 min;
  applied: 3 min per function, kind/edit filter, no raw-offset code,
  remove_stmt off and the hit passes weighted up, a length-aware score.
  Not yet: --resume of partials, a PS2_REG/callee-declaration search tool.
- [x] R26 Other games with the RX library and symbols (2026-11-23, owner
  with ChatGPT; prompt notes/research/R26-rx-donors-prompt.md). Results and
  checks in notes/research/R26-rx-donors.md: Suikoden Tactics has no RX;
  Arc the Lad's hidden 2002 CD (inside ARC.000) has RX 4 but is stripped.
  Next discs to get: Wa ga Ryuu o Miyo PAPX-90521 / SCPS-15080.

- [x] R23 Make our permuters find more matches (2026-11-22). Code names:
  **Sektor** = the official decomp-permuter (tools/perm_official.py; random
  mutations; C only: 62 of 77 queued near misses could not be prepared,
  "base.c does not compile as C"; 18 exact overall), **Cyrax** = ours
  (tools/permute.py + tools/permute_queue.py; directed rewrites on C++; 1
  match in ~35). Today Codex matched ~28 near misses by hand: its commits on
  pr-merge from 2026-11-22 (git log --since=2026-11-22 --author, messages
  "<file>: <func>", and the reports in build/workers/codex-loop.log tables:
  "what fixed it") are a labelled dataset of rewrites that work at -Os.
  Find: (1) which of those fixes Cyrax could have found (already in its
  rewrite list?) and which rewrites it lacks (e.g. ASM_NOTHROW/throw() on
  callees, a local bool before a test, early return vs nested, 64-bit
  return/copy types, PS2_REG pins, initializing a local after a call,
  recomputing an address per use, shared return label, removing a hint);
  (2) why Cyrax scored 1/35 (search budget, scoring, rewrites never
  applicable, bugs: read build/workers/perm-loop.log); (3) what blocks
  Sektor on C++ (perm_official.py's C translation: classes, references,
  this->, asm labels) and whether a better translation could prepare most
  of them; (4) a ranked plan with expected yield and cost. Read-only;
  output notes/research/R23-permuters.md. Done 2026-11-22 (Sonnet); checked:
  12,695/15,350 perm-loop.log lines are fix_hi16 noise, 8 "no rewrite left",
  Sektor sends compiler errors to /dev/null, Cyrax has no throw() rewrite.

- [x] R22 Plan shared class headers for the class families (2026-11-22).
  Lesson of the day: a class header (real fields and types instead of
  M2C_FIELD offsets) gave +76 functions in one session (worker Neon, task E),
  far more than function-by-function work; but families spread over several
  files (unk/EffLight2 vs other Eff* files) collide when each file gets its
  own header. Find, from vtables/RTTI (symbols/ghidra_symbols.tsv,
  notes/class_hierarchy.txt), field accesses (tools/layouts.py) and the
  existing headers (src/**/*.h): the class families whose classes live in
  several src/ files (enemies: unk/*Main, *Out* such as HfmMain, ClrMain,
  NorOutAttack, FshMain, DwfMain, GrgMain, BdlMain, GotMain; effects:
  unk/Eff*; tasks: Tsk*; menus: Mnu*; mag/maglife*), their common bases and
  shared fields, which existing header already defines part of each, and a
  plan: one header per family or base, what it declares, which files
  include it, an order by expected yield (pending functions + NON_MATCHING
  attempts + M2C_FIELD uses each unlocks). Output:
  notes/research/R22-class-families.md. Done 2026-11-22 (Sonnet); checked:
  MagLifePC defined twice, CmnITask only in TskMsgMan.h, MnuPBook/mnuBase
  include no header, EmyMain/EmyOut/Eff0/mnuBase are game classes. Became
  task F of build/workers/fable-brief.md.

- [x] R16 Split unk/TskCamera (game/gamman done in c6d41ad; TskCamera
  range done in wt/fable):
  - task/tsk_scene absorbs unk/001F836C (0x1F836C-0x1F8FB7, including
    PLScenePlay ctor/dtor previously misassigned to task/naga_chunk;
    contiguous .rodata 0x2FE810-0x2FE9FF with 16-aligned jump tables and
    shared RTTI tail 0x2FE980-0x2FE9FF).
  - Split TskCamera's range into unk/TskSnd (0x1F8FB8, .rodata 0x2FEA00),
    unk/TskAttack (0x1F985C, .rodata 0x2FEA90), unk/TskDamage (0x1F9E38,
    .rodata 0x2FEB60), unk/TskCamera (0x1FBBA4, .rodata 0x2FEF80), and
    task/naga_chunk (0x1FC47C, .rodata 0x2FEFF0).
  - Open from it: unk/DisplayMessage, unk/SeManager, unk/VoiceManager share
    tsk_scene's reverse vtable block (0x2E4D90-0x2E4E58) and RTTI tail
    (0x2FE980-0x2FE9B7); exact text placement of func_001F8FB8,
    func_001F97C8, and func_001FBBA4/001FBBD0; unk/WrdSrv's .rodata start
    (EffWater type names) stays unsettled.

- [x] External deep research (2026-11-18, owner): no public inspection of
  SLUS-28063/28064 for symbols; checked locally again: the trade demo
  (SYSTEM.CNF boots SLUS_280.63), the JP SCPS_150.93 and retail have no
  .symtab/.strtab and an empty .mdebug.eabi64. No other PS2 game known
  with ee-gcc 2.96 -Os. Its -Os branch/register advice is already in
  docs/DECOMPILING.md; GT4's -O2 levers are R21.
- [x] R18 Deep read of gt4/god-hand/sotc/rac1 (2026-11-18, Sonnet):
  leads became R19-R21. gt4 and god-hand treat register-asm pins as
  fakematches (gt4 tools/asm_policy.py, god-hand
  scripts/check_forced_regs.py with an allowlist meant to stay empty);
  our PS2_REG has 373 uses in 29 files. Our perm_official already sets
  compiler_type = "gcc" (god-hand's pitfall).
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

