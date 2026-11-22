# R22: shared class headers for the class families

Research only (no source touched). Date 2026-11-22. Evidence tags:
**[exact]** = from symbols/ghidra_symbols.tsv, notes/class_hierarchy.txt,
config/splits.tsv or the src tree; **[inferred]** = my reading of M2C_FIELD
offset statistics and `tools/layouts.py` output.

Counts come from `src/**/*.cpp`: *pend* = `INCLUDE_ASM` lines left, *NM* =
`#ifdef NON_MATCHING` blocks, *M2C* = `M2C_FIELD` uses (the `#define` line
counts too, +1 per file). *Yield* = pend + NM + M2C, a rough proxy only.
Class-to-file mapping: each method/ctor/dtor/vtable/typeinfo address in
ghidra_symbols.tsv mapped through splits.tsv. Linkonce/compiler-generated
members land in a `sdk/libgcc_2` bucket and are ignored for the mapping.

## 1. Summary

| # | Family | Base classes (hierarchy) | Files | Existing headers | Proposed header | pend / NM / M2C | Priority |
|---|--------|--------------------------|-------|------------------|-----------------|-----------------|----------|
| 1 | Enemies | `EmyMain [7]` -> 11 `*Main`; `EmyOut [5]` -> ~85 `*Out*` | emy/emy_main + 16 unk/*Main, *Out* | none | `src/emy/emy.h` (EmyMain, EmyOut, EmyManager), then one per enemy | 213 / 28 / 1909 | 1 |
| 2 | Tasks | `CmnITask [7]` -> 35 Tsk*/EmyManager/EventTestTask/PLScenePlay | unk/Tsk* (9), EventTestTask, task/* (3) | unk/TskMsgMan.h (CmnITask + 17 classes) | split `src/task/cmnitask.h` out of TskMsgMan.h; then `TskEnemyMove.h` etc. | 128 / 46 / 1485 | 2 |
| 3 | Book menus | `mnuBase [12]` -> MnuDiary, MnuMap, MnuPBook | unk/MnuDiary, MnuPBook, mnuBase | unk/MnuDiary.h (MnuBase, MnuPBook, MnuDiary, MnuStock) | move base + MnuPBook to `src/unk/mnuBase.h` | 43 / 29 / 1082 | 3 |
| 4 | Effects | `Eff0 [13]` -> 42 Eff* (EffFire1Ex, EffBg1 one level lower) | unk/Eff0, EffBreath2Prim, EffFire1, EffLight2, EffWater1, EffMan | unk/EffLight2.h (declares `Eff0Base`, EffVec*, EffMat4 + 9 classes) | `src/unk/Eff0.h` (Eff0 + shared vec/mat types) + per-file headers | 78 / 26 / 652 | 4 |
| 5 | Game state | `GamMan [2]`, `ObjStat -> ACHRstat, FCHRstat`, `GamSndMan` | game/gam*, unk/001B64C4, 001BE2CC, 0020ED9C, 00166AD0 | game/gamman.h, game/gamtrg.h (consistent) | none for the family; per-file headers for the unclassified files | 174 / 68 / 1120 | 5 |
| 6 | Dialog/save menus | MnuDlg, MnuSvld, MnuMcd, MnuSub104, MnuMsgWin, MnuRpk (no RTTI; names inferred) | mnu/mnusvld, mnudlg, unk/001A6830, mnuselect, mnuSelectLanguage | mnu/mnusvld.h, mnu/mnudlg.h, unk/001A6830.h (conflicting) | `src/mnu/mnucommon.h` merging the three | 75 / 12 / 215 | 6 (fix conflict early) |
| 7 | MagLifeBwn | `MagLifeControlChara -> MagLifeBwn`; `MagLifeBwnCtrl [10]`; `MagLifeBwnCtrlMode [3]` x15; `MagLifeBwnMode [5]` x10 | mag/maglifebwn, bwnctrl, bwnmode, unk/MagLifeBwnModeSit | none (maglife.h has the base) | `src/mag/maglifebwn.h` | 76 / 0 / 55 | 7 |
| 8 | MagLifePC | `MagLifePC [17]`; `MagLifePCMode [4]` x21 | mag/maglifepc, pc2, pc3, pcbtl, pcmode, pcmove | mag/maglifepc.h (full, 0x220) | extend maglifepc.h; drop partial copy in magscene.h | 66 / 9 / 79 | 8 |
| 9 | MagScene | `MagSceneIF [2]`, MagScene (no RTTI) | mag/magscene, 2, camera, focus, render | mag/magscene.h | add includes; fix MagLifePC duplicate | 95 / 7 / 29 | 9 |
| 10 | Wrd / Sct | `WrdSrv [2]`, `SctLayer [2]` | unk/WrdSrv, unk/SctLayer | unk/WrdSrv.h (already has SctLayer) | SctLayer.cpp just includes WrdSrv.h | 20 / 8 / 202 | 10 (cheap) |
| 11 | MagLifeMenu | `MagLifeMenuBase` -> 16 MagLifeMenu* | mag/maglifemenu, menusp | none | small, later | 19 / 1 / 3 | 11 |

Note: EmyMain is a root in class_hierarchy.txt, not a CmnITask child [exact].
Sums for rows 1-4 cover all files listed under "Files" (row 2 includes
task/tsk_bg_load, tsk_scene, naga_chunk and EventTestTask).

## 2. Method

Inventory: 37 headers, 127 .cpp. Outside the headers' own file, only
gamman.h/gamtrg.h (12 includers each, game/utl/mnu/unk), maglife.h (6),
magscene.h (10) and dogactor.h (8) are shared today; every other family header
has exactly one includer. Step 4 ran `layouts.py` on Eff0, EmyMain, EmyOut,
CmnITask, TskEnemyMove, TskEnemyTurn, mnuBase and MnuPBook, and I computed
M2C offset histograms per family (offsets used in several files).

## 3. Per-family detail

### 3.1 Enemies (top yield)

- Classes [exact]: `EmyMain [7]` roots Bdl, Bds, Clr (8 slots), Dwf, Fsh, Got,
  Grg, Hfm (8), Mrt, Nor (8), Pig `*Main`. `EmyOut [5]` roots about 85 state
  classes (`DwfOutWalk`, `HfmOutDead`, ...). EmyMain/EmyManager methods are in
  emy/emy_main.cpp, EmyOut's in unk/EmyOut.cpp.
- File layout [exact]: each enemy lives in 1-2 files (Dwf in three: DwfMain,
  DwfOutAtkFar, DwfOutFort; Bdl in BdlMain+BdlOutAtk; Nor in NorMain+
  NorOutAttack). No cross-enemy collision, but all share the base.
- Base layout [exact]: layouts.py gives EmyMain >= 0x204 bytes with the vtable
  at +0x200 (DwfMain.cpp:137 stores `_vt$7DwfMain` at 0x200); EmyOut >= 0x38
  with the vtable at +0x34.
- Evidence that the base matters [inferred]: of 1653 M2C accesses in the 16
  enemy files, ~90% are at offsets below 0x204 (Dwf 454/508, Clr 173/198, Hfm
  232/247, NorOutAttack 191/195). Offsets 0x0, 0x4, 0xC, 0x3C, 0x38, 0x40,
  0x24, 0x14, 0x44 occur in 11-14 of the 16 files. Derived data starts around
  0x204 (Bdl/Bds/Clr/Hfm) or 0x258-0x26C (Dwf/Fsh/Got/Pig).
- Caveat [inferred]: `M2C_FIELD(arg0, ...)` may be a different object than
  `this` (ObjStat or DogActor held by the enemy, or EmyOut's owner pointer
  at EmyOut +0xC, 8 accesses). The low 0x48 bytes may be ObjStat/DogActor
  rather than EmyMain fields. Verify per function before typing.
- Proposal: `src/emy/emy.h` beside emy_main.cpp: EmyMain (0x204, real fields
  only where proven), EmyOut (0x38), EmyManager; then `DwfMain.h`, `HfmMain.h`
  ... per enemy (derived classes). Includers: the 17 files. Order: emy.h,
  then DwfMain (508 M2C, 13 NM), HfmMain (247 M2C, 20 pend), ClrMain (198,
  19 pend), NorOutAttack (195, 20 pend).
- Risk: EmyMain gains a vtable; keep sizes/slots exact (7 or 8 slots per
  hierarchy). Start with a plain-struct view and add virtuals per class when
  its ctor matches.

### 3.2 Tasks

- `CmnITask [7]` roots 35 classes [exact]: EmyManager, EventTestTask,
  PLScenePlay, ScenePlay, TskAttach, TskAttack, TskAvoidMove, TskBGLoad(+Area,
  +Map), TskCamera, TskChrRot, TskDamage, TskEnemyMove, TskEnemyTurn,
  TskFrameFunc, TskGenFrameFunc, TskLogger, TskMove*, TskMovie, TskMsgMan,
  TskMtnMove(+2), TskRotAdj, TskSeqEvent, TskSnd, TskSysFunc, TskTest.
- Where [exact]: 17 in unk/TskMsgMan (unk/TskMsgMan.h:29 defines CmnITask,
  :25 TskVec4); TskBGLoad* in task/tsk_bg_load; TskCamera/Snd/Attack/Damage/
  EnemyMove/EnemyTurn/MtnMove each in its own unk/ file; TskLogger/TskTest in
  game/gamsnd; EmyManager in emy/emy_main; EventTestTask in unk/EventTestTask.
- Shared fields [inferred]: TskMoveTypeGen puts object ptr/oid/chrID at +0x04..
  +0x0C; M2C offsets 0x10 (124 uses), 0x1C, 0x4, 0x8, 0x24, 0x28 occur in 3-4
  of the Tsk files. layouts.py CmnITask reports no direct accesses (all in
  subclasses); TskEnemyMove >= 0xAC8 bytes, vtable at +0.
- Problem: TskMsgMan.h is included only by TskMsgMan.cpp, but the root is
  needed by 8 other files. Split `src/task/cmnitask.h` (CmnITask + TskVec4,
  ~15 lines) out: TskMsgMan.h includes it, so the change cannot affect
  TskMsgMan.cpp. Then `TskEnemyMove.h` (719 M2C, 15 NM, 17 pend). Order:
  TskEnemyMove, rest of TskMsgMan (35 pend, 29 NM), gamsnd Tsk parts, TskMtnMove.

### 3.3 mnuBase / book menus

- `mnuBase [12]` -> MnuDiary, MnuMap, MnuPBook [exact]. Files: unk/mnuBase
  (base methods: 273 M2C, 6 pend, 3 NM), unk/MnuDiary (309 M2C, 22 pend, 14
  NM), unk/MnuPBook (MnuPBook + MnuMap: 500 M2C, 15 pend, 12 NM).
- Existing [exact]: unk/MnuDiary.h:65 defines `MnuBase` (fields +0x0..+0xAC,
  vtable +0x10C), MnuPBook (:95), MnuDiary (:107), MnuStock; only MnuDiary.cpp
  includes it. MnuPBook.cpp and mnuBase.cpp include nothing and use M2C at
  +0x4 (148 uses), +0x8, +0x14, +0x9C, +0xA4... the offsets MnuBase names;
  layouts.py mnuBase and MnuPBook agree [inferred].
- Naming: RTTI/class name is `mnuBase` (lower case) [exact]; the header uses
  MnuBase with `asm("func_00192AC0")`. Check before declaring virtuals.
- Proposal: `src/unk/mnuBase.h` with MnuBase, the slot structs, MnuPBook,
  MnuMap; MnuDiary.h keeps MnuDiary/MnuStock and includes it. MnuPBook.cpp
  (47 distinct offsets) is the biggest typing win after the enemies/tasks.
- Conflict: `MnuMsgWin`/`MnuRpk` also defined in unk/001A6830.h:31/45 (see 3.6).

### 3.4 Effects

- `Eff0 [13]` roots 42 classes [exact]. Files [exact]: unk/Eff0 (Eff0, EffBg1,
  EffBloodSpray1/2, EffBloodStay1-3, EffBreath1...: 10 classes),
  unk/EffBreath2Prim (Breath2 trio + EffCameraAnim1), unk/EffFire1 (Dust2,
  Fire1/Ex, Fire2, Fog1-3), unk/EffLight2 (FindItem1, Foot1/2, Generic1,
  Light1-3), unk/EffWater1 (Cloud1, MuzzleFlash1, Reload1, Steam1/2, Water1/3);
  unk/EffMan is the manager.
- Conflict/gap [exact]: the base is declared in unk/EffLight2.h:41 as
  `Eff0Base` (flags +0x0, zDepth +0x10, +0x1C, vtbl +0x20; 0x24 bytes) though
  the class is `Eff0`. layouts.py Eff0 agrees (+0x0 ushort, +0x4, +0x14,
  +0x18, +0x1C, vtable +0x20). The other four Eff files use M2C on the same low
  offsets (0x0..0x58; 20+ offsets occur in 4/4 files) [inferred] but cannot
  include EffLight2.h without nine unrelated classes and the wrong base name.
- Proposal: `src/unk/Eff0.h` = EffVec2/3/4, EffVec4A8, EffMat4,
  EffRenderParam, `Eff0` (13 slots) moved out of EffLight2.h (which includes
  it and keeps its nine classes). Then EffWater1 (247 M2C), Eff0 (203),
  EffFire1 (123), EffBreath2Prim (63) get their own headers. EffLight2 is
  the reference for the finished pattern (0 M2C left).
- Risk: renaming Eff0Base -> Eff0 is safe while it has no virtuals in the
  header. Adding the 13-slot vtable must happen in the file with Eff0's
  methods (Eff0.cpp).

### 3.5 Game state

- No collision [exact]: gamman.h:20-22 forward-declares ObjStat/ACHRstat/
  FCHRstat; the full classes are in gamtrg.h:112/212/305; utlfind.h/utlgame.h
  forward-declare only.
- Gap: unk/001B64C4 (297 M2C), 001BE2CC (GamMan), 0020ED9C (290), 00166AD0
  (148, DogActor) and unk/0018BD94 (357, only bedpfh.h) have no class symbols
  in the TSV beyond GamMan/DogActor mentions; their families are unknown.
  00166AD0 and 0020ED9C include neither gamman.h nor dogactor.h.

### 3.6 Dialog/save menus (mnu/*, unk/001A6830)

- Duplicate definitions [exact]: `MnuSub104` is an opaque 0x104-byte struct in
  unk/001A6830.h:50 and a real class (base `MnuSub104Base`, subStep, result,
  lines[32]) in mnu/mnudlg.h:19. `MnuMcdStub`/`MnuSvldStub` (001A6830.h:55/60)
  are opaque twins of `MnuMcd` (mnudlg.h) / `MnuSvld` (mnusvld.h). `MnuMsgWin`/
  `MnuRpk` (001A6830.h) twin `MnuSvldMsgWin`/`MnuSvldRpk`/`MnuDlgMsgWin`
  (mnu headers) and `MnuMsgWinCtor`/`MnuStockRpk` (MnuDiary.h). `MnuDlg` is
  declared in mnusvld.h although mnudlg.cpp holds MnuDlg code.
- unk/001A6830.cpp (37 pend, 6 M2C) is the menu manager embedding all of
  these (MnuOpt, MnuTitle, MnuBoard, MnuMovie, MnuNow, MnuItem...).
- Proposal: `src/mnu/mnucommon.h` with MnuSub104, MnuMsgWin, MnuRpk,
  MnuRpkEntry once, included by 001A6830.h, mnudlg.h, mnusvld.h, MnuDiary.h;
  then replace the Stub types in 001A6830.h by the real MnuMcd/MnuSvld.
- Risk: moderate. Each header compiles alone today; after merging every
  sizeof/offset must stay equal (add static checks).

### 3.7 MagLifeBwn

- Classes [exact]: `MagLifeBwn [17]`, `MagLifeBwnCtrl [10]`, 15 `MagLifeBwnCtrlMode*`
  (base `[3]`), 10 `MagLifeBwnMode*` (base `[5]`). Files: mag/maglifebwn (18
  pend), mag/maglifebwnctrl (44 pend, 40 M2C; Ctrl + all 15 ctrl modes),
  mag/maglifebwnmode (5), unk/MagLifeBwnModeSit (9; base + Fuse/Move/Null/Sit/
  Wait). maglifebwn.cpp includes maglife.h only; maglifebwnctrl.cpp includes
  nothing and uses ad hoc `m2c_v14_*` structs (lines 6-7).
- Proposal: `src/mag/maglifebwn.h`. Yield here is mostly ctors/dtors and
  vtables, so declare the vtables first: 76 pend / 55 M2C.

### 3.8 MagLifePC / MagScene

- maglifepc.h declares the full MagLifePC (0x220) and 21 modes; included by
  maglifepc.cpp and maglifepcbtl.cpp only. maglifepcmode (35 pend),
  maglifepcmove (15), maglifepc2, maglifepc3 (33 M2C) do not include it.
- Conflict [exact]: magscene.h:40 defines `class MagLifePC` partially ("only
  what MagSystem reads", embedded as `m_pc` at 0x2ADC0) while maglifepc.h:15
  also defines it; maglifepc.h:314-340 holds `BedPad`/`DogActor`/`MagScene`
  `*_PartialLayout` copies. A TU including both headers breaks. Fix: one
  definition in maglifepc.h, magscene.h includes it (preserve sizeof 0x220 and
  offsets in every magscene includer: 10 files).
- magscene.cpp (41 pend) and magscene2.cpp already include magscene.h;
  magscenecamera/focus/render (10/16/15 pend) include nothing: add includes.
- SctLayer.cpp (12 pend) should include WrdSrv.h (SctLayer already declared).

### 3.9 Not families but big

mcd/mcdman (876 M2C, McdMgr/McdSlot/McdDirEntry, 15 pend, 14 NM), unk/0018BD94
(357), unk/0020ED9C (290), msg/msgman (MsgWin, 94), snd/rxmpeg (57): per-file
headers, same pattern as the six that worked.

## 4. Order by expected yield

1. `src/emy/emy.h` + per-enemy headers: ~2150 (213 / 28 / 1909).
2. cmnitask.h split + TskEnemyMove.h: ~1660 (128 / 46 / 1485).
3. `mnuBase.h` (MnuBase/MnuPBook/MnuMap out of MnuDiary.h): ~1150 (43 / 29 / 1082).
4. `Eff0.h` (Eff0 + shared types out of EffLight2.h): ~760 (78 / 26 / 652).
5. mnucommon.h (~300), then MagLifeBwn (~130), MagLifePC (~150).
Parallel single-file work: mcdman, 0018BD94, 001B64C4, 0020ED9C.
Cheap, any time: SctLayer.cpp include, magscene* includes.

## 5. Open questions

- Is the 0x0..0x48 range in enemy files EmyMain, ObjStat or DogActor? Check
  `this` vs member dereference on a sample; prototype by typing only EmyMain's
  low bytes and recompiling one Main file.
- Is `mnuBase` really lower-case in the source (RTTI `7mnuBase`) while
  MnuDiary.h calls it MnuBase? It matters only if virtuals are declared.
- Does every Eff class use one 13-slot vtable of Eff0, so a single `Eff0` with
  13 virtual slots suffices?
- Are the opaque MnuMcdStub/MnuSvldStub sizes (0x1400/0x2780) equal to the
  full MnuMcd/MnuSvld sizes in the other headers? Check with a static_assert.
- Families of unk/0018BD94, 00166AD0, 0020ED9C, 001B64C4 are unknown (no
  class symbols).
- Counts include one M2C_FIELD `#define` line per file and NM blocks that may
  be stale after later matches.
