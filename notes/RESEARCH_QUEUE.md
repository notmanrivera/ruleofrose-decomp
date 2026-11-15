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

- [ ] R3 unk/001A6830: split point. Its first jump table (0x2F9410, used by
  func_001A7498) is 8 mod 16 from its .rodata start 0x2F9248, so the file
  is two: the first part (rodata 0x2F9248-0x2F9410, no tables, needs
  func_001A6C90 which uses D_002F9400) ends somewhere in (0x1A6C90,
  0x1A7498], most likely 0x1A7418 or 0x1A7498. Find the exact first
  function of the second part (calls, shared data, asserts, vtables),
  and whether the first part belongs to mnu/mnusvld (func_001A5ED0 calls
  func_001A6FE8). 30 jump tables wait on this.
- [ ] R4 unk/TskMtnMove: where game/gamsnd really ends. 0x1E46B8-~0x1E5428
  looks like gamsnd's tail ("data/snd/xv/%s", "s%06d.str", D_007B2580);
  the first table (0x2FD7B0) is used at 0x1E5660. Find the first
  TskMtnMove function.
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

## Done

- [x] R1 game/gamtrg's .rodata start (2026-11-15, Sonnet + coordinator):
  0x2FC418 -> 0x2FC420; jump tables are 16-aligned (all 267). Applied in
  bcfa96a; +3 functions matched.
- [x] R2 The 20 files with jump tables and a .rodata start not a multiple
  of 16 (2026-11-15): 11 started on the previous file's RTTI names
  (08bd270), EventTestTask on padding and mnusvld three functions early
  (5cac105). The other 7 are R3-R6.
