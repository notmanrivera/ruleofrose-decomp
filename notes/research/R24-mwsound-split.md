# R24: splitting mw/sound with PoPoLoCrois's debug info

Status: research only, nothing applied to `config/`. Proposed rows:
`build/research/R24/mwsound_split.tsv` (columns of `config/splits_manual.tsv`) and
`build/research/R24/mwsound_split_full.tsv` (adds `text_end`, `data`, `bss`, confidence).
Scripts are in `build/research/R24/`.

## Headline

1. The queue's range is off: `mw/sound`'s text is **0x237D00-0x24B490** (the row's second number,
   0x303CB0, is its `.rodata` start; the next text file is `sdk/libcdvd` at 0x24B490).
   `asm/mw/sound.s` has 584 functions in that range, and all 586 donor matches of
   `symbols/donor_symbols.tsv` span 0x237DD0-0x28xxxx (mw/sound plus the SDK/libc files after it).
2. It is not one RX file: it is **25 consecutive object files** of the RX library: sound (11),
   sys (2), file (10), thread (2), gs vsync (1).
3. **The donor has no file names for RX.** There are no `STT_FILE` symbols at all, and the DWARF 1
   `.debug` (8683 compile units) only covers the game and its templates; 0x1015A0-0x190E90 (the whole
   RX library plus SDK) has no compile unit. The only `rx` paths in DWARF are headers
   (`D:\psx2\rx\include\rxgeom.h, rxpkt.h, rxvram.h, rxstate.h, gifmac.h, rxclut.h, rxshader.h,
   rxxim.h, rxrmodel.h, eeinc.h`), none about sound/sys/file/thread. So the names below are
   **placeholders** derived from function-name prefixes, not recovered paths.
4. What does work: the donor symtab keeps **one `.text` STT_SECTION symbol per object file** (276;
   263 also have a `__gnu_compiled_c` marker at the same address), and likewise `.data/.rodata/.bss`
   section symbols per object (96/121/86). Those give exact object starts and data chunk sizes.

## Method

1. Parsed `.symtab` (pyelftools), `.debug` (DWARF 1 by hand, little endian) and `.relmain` (r_offset is an
   absolute address; HI16/LO16 hold the final linked address).
2. Donor object starts = `.text` section symbols. For each donor function (STT_FUNC) the object = last
   start <= address.
3. Our side: `symbols/donor_symbols.tsv` (586 functions; all 586 found in the donor symtab by name and equal
   size; 12 duplicate-name statics resolved by address delta to the nearest unique anchor). Our function
   boundaries come from the `glabel`s of the local `asm/mw/sound.s` (git-ignored).
4. Per object: if its first donor function is byte-matched, our object start = that function's address
   (exact). Otherwise the start is fixed by aligning the sequence of padded function sizes (tail of the
   previous object + head of this one) against our unmatched functions in the window.
   Full-sequence check: the 97 function sizes of the donor sys object occur in ours exactly once, at 0x23FF58.
5. Data: each donor object references its own `.data/.rodata/.bss` chunk (HI16/LO16 relocs). For each of our
   objects I collected the `D_xxxxxxxx` addresses its code references and took the lowest per section.

## Order and contiguity

- Within an object our function order equals the donor's (sizes agree function by function in most objects;
  a third of objects differ in a few functions: slightly different RX version).
- Object order in ours is NOT the donor's link order (donor: sys 0x1015A0, file 0x13E3A8, gs 0x14EE10,
  sound 0x15B220, thread 0x16F1E8; ours: sound, sys, file, thread, gs). The donor therefore gives
  object contents, not neighbours across objects.
- Data/rodata/bss chunks in our binary follow our text order (monotone, no overlaps found).

## Proposed boundaries (text)

| text start | end | placeholder name | conf | donor object |
|---|---|---|---|---|
| 0x237D00 | 0x237DD0 | mw/sound/sndinit | low | 0x15B220: ThreadChangeCallback, CheckBgThread, rxSndInit, rxSndTerm (no byte match; ours has 3 fns) |
| 0x237DD0 | 0x238538 | mw/sound/sndsys | high | 0x15B308 rxSndSysInit.. |
| 0x238538 | 0x238DC8 | mw/sound/sndiop | high | 0x15BA08 MemCopy, rxSndIop* |
| 0x238DC8 | 0x239E58 | mw/sound/sndspu | high | 0x15C210 rxSndSpuBlock* |
| 0x239E58 | 0x23A180 | mw/sound/sndreverb | high | 0x15D2F8 |
| 0x23A180 | 0x23B238 | mw/sound/sndxseq | high | 0x15D620 xseq/XVab/Riff |
| 0x23B238 | 0x23BD70 | mw/sound/sndbgm | high | 0x15E718 |
| 0x23BD70 | 0x23CB08 | mw/sound/sndse | high | 0x15F170 |
| 0x23CB08 | 0x23DBD0 | mw/sound/sndpcm | high | 0x15FF08 |
| 0x23DBD0 | 0x23F960 | mw/sound/sndadpcm | medium | 0x160F28 |
| 0x23F960 | 0x23FF58 | mw/sound/sndrpc | medium | 0x162878 RpcOpen.._SndRpc* |
| 0x23FF58 | 0x242AA8 | mw/sys/sys | high | 0x1015A0 (97 fns) |
| 0x242AA8 | 0x2433E8 | mw/sys/sysmon | high | 0x1040F0 rxSysMon*, loadScreen |
| 0x2433E8 | 0x245948 | mw/file/file | high | 0x13E3A8 |
| 0x245948 | 0x245CB0 | mw/file/fileload | high | 0x140880 |
| 0x245CB0 | 0x246278 | mw/file/sif | high | 0x140D68 rxSif* |
| 0x246278 | 0x246318 | mw/file/device | high | 0x141330 |
| 0x246318 | 0x246840 | mw/file/devhost | high | 0x1413D0 |
| 0x246840 | 0x248018 | mw/file/devcdrom | high | 0x1418F8 |
| 0x248018 | 0x248660 | mw/file/devhdd | high | 0x142DC8 |
| 0x248660 | 0x248FD8 | mw/file/devlocal | high | 0x143410 |
| 0x248FD8 | 0x249B88 | mw/file/request | high | 0x143D88 |
| 0x249B88 | 0x24AFE8 | mw/thread/thread | high | 0x16F410 |
| 0x24AFE8 | 0x24B1F8 | mw/thread/threadsync | low | 0x16F1E8 (see below) |
| 0x24B1F8 | 0x24B490 | mw/gs/vsync | high | 0x14EE10 SyncVCallback..rxGsVSync |

Every start coincides with one of our function starts. The end of the last row equals the start of
`sdk/libcdvd` (0x24B490), a consistency check (the last function ends exactly there).

## Gaps and ambiguities

- **0x237D00-0x237DD0** (3 fns, 0xD0 B): donor object 0x15B220 has 4 fns / 0xE8 B and no byte match; placement
  is by elimination. Could be merged into sndsys.
- **sndadpcm / sndrpc** (0x23F960 vs 0x23F9B0): the first donor Rpc fns (RpcOpen/Close/Call) differ in size
  from ours. 0x23F960 (0x50 B: memset + CreateSema) is only called from RpcOpen (0x23F9B0), so it is attached to
  the Rpc object. Supporting evidence: the Adpcm rodata chunk then ends at exactly its donor size (0xD0,
  0x3042C8-0x304398), and the strings RpcOpen uses (0x304398..0x3043D0) fall in the next chunk (donor Rpc rodata
  chunk is 0x50). The boundary could be 0x23F9B0.
- **0x247EB8-0x248018** (5 fns, 0x160 B) has no donor counterpart. They share `.data` 0x2DC1E0-0x2DC1F8 with the
  CD-ROM device code, so they stay in `devcdrom`.
- **0x2433D8 / 0x2433E0** (two 8-byte fns) before `_FileThreadChangeCallback` are kept in `sysmon`.
- **0x24AFE8-0x24B1F8**: the donor has `rxThDrawSync/DmaSync` (obj 0x16F1E8) linked before the thread object;
  ours has 9 functions here calling `sceGsSyncPath`/`sceDmaSync`, but they share `.data` 0x2DC274-0x2DC280 with the
  previous functions, so it may be part of `thread`. Low confidence; merging is safe.
- Donor objects absent from ours (not linked in this game): 0x140BE8 (rxFileLoadMalloc*), sound streaming/utility
  objects 0x162E30-0x16F1E8 (rxSndStr*, rxSndUt*), and the tail of 0x1040F0 (MW C++ runtime: `__throw`,
  `UnwindStack`..., 32 fns).
- The ~323 of our 584 functions with no donor name all fall inside the objects above; no unmatched gap sits
  between two objects other than the ones listed.

## Data / rodata / bss

The donor has per-object chunks (section symbols) and they map cleanly. Starts are the lowest referenced
address in our code (a chunk may start up to 0x10 earlier because of alignment). Full table in
`mwsound_split_full.tsv`; summary:

- `.data` 0x2DB638-0x2DC2D0: sndsys 0x2DB638, sndiop 0x2DB95C, sndspu 0x2DB968, sndadpcm 0x2DB980, sndrpc 0x2DB9C0,
  sys 0x2DB9D0, sysmon 0x2DBEA0, file 0x2DC1B0 (shared `_gFileDebugFlag`), devhost 0x2DC1B8, devcdrom 0x2DC1C0,
  devhdd 0x2DC220, request 0x2DC228, thread 0x2DC260, vsync 0x2DC284.
- `.rodata` 0x303CB0-0x305048: sndinit 0x303CB0 (its donor chunk size 0x38 matches the next start 0x303CE8),
  sndiop 0x303CE8, sndspu 0x303D10, sndxseq 0x303F38, sndbgm 0x3041A8, sndse 0x3041F0, sndpcm 0x304238,
  sndadpcm 0x3042C8, sndrpc 0x304398, sys ~0x304400, sysmon 0x304A48, file 0x304AD8, fileload 0x304B38,
  sif 0x304B90, devhost 0x304D40, devcdrom 0x304D68, devhdd 0x304E10, devlocal 0x304E70, request 0x304F30,
  thread 0x304FC8. (sndreverb, device, vsync have none.)
- `.bss` 0x7B5AC0-0x818680: sndsys 0x7B5AC0, sndiop 0x7B6B00, sndspu 0x7B6B80, sndxseq 0x7B97C0, sndbgm 0x7BBBC0,
  sndse 0x7BBED0, sndpcm 0x7BC400, sndadpcm 0x7BEFC0, sndrpc 0x7C9300, sys 0x7CC340, sysmon 0x7CE800,
  file 0x7DABB0, device 0x7DF9C0, devhost 0x7DFA50, devcdrom 0x7DFB80, devhdd 0x7F1DC0, devlocal 0x7F1EC0,
  request 0x7F6910, thread 0x807F40, vsync 0x818640. Treat bss starts as lower bounds (some chunks are shared).
- Before applying, verify with `tools/split_files.py` that no `.rodata`/`.data` reference crosses a new cut.

## Non-rx units

No SDK compile unit (libsd, libcdvd...) exists in the donor DWARF; SDK/libc objects are identifiable only by
their `.text` section symbols and names (already used by `sce_symbols.tsv` / `donor_symbols.tsv`). Nothing from
libsd/libcdvd falls inside mw/sound's text; `sdk/libcdvd` starts exactly where gs/vsync ends.

## Verification

- 586/586 donor_symbols names found in the donor symtab with equal size (0 size mismatches).
- 276 `.text` section symbols = 276 object starts.
- Function-by-function equal sizes: sound 0x15D2F8, 0x15F170; file 0x140880, 0x140D68, 0x141330, 0x1413D0,
  0x142DC8, 0x143410; sys 0x1015A0 (unique 97-function hit); gs 0x14EE10.
- Data chunk sizes agree with the code boundaries (donor Adpcm rodata 0xD0 = 0x3042C8..0x304398; donor
  sndinit chunk 0x38 = 0x303CB0..0x303CE8).
- Range end 0x24B490 equals the next file's start in `config/splits.tsv`.

## Caveats

- Names are placeholders; the donor carries no path for any of these units.
- Our RX version differs slightly from the donor (some functions have different sizes), so "identical" holds
  per function, not per object.
