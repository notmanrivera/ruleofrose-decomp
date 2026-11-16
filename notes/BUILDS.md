# Other builds of Rule of Rose

What the other builds (the owner's discs, extracted to the git-ignored
`disc/`) add to the decompilation. None has symbols: all are stripped
(`.mdebug.eabi64` is empty, an ABI marker). Method: code split at
`jr $ra`, each chunk of 48 bytes or more reduced to its instruction shape
(registers kept, immediates and jump targets masked) and looked up in the
other ELF. Multi-return functions are split, so counts are of chunks.

## Japanese retail, SCPS-15093 (January 2006): `disc/ror_jp/SCPS_150.93`

Checked 2026-11-16.

- Same compiler and the same i3d package
  (`i3d_package_version 050121-stable-050826`); .text 1,570,200 B, 6.4 KB
  less than ours (.text 0x100000, .data 0x294500, .rodata 0x2E3680).
- Of our 3,329 game-code chunks, 3,200 are in the Japanese build; 129
  (130 KB) are not, nearly all in the menus and text layout:
  unk/001A6830 (26 chunks, 35.5 KB), unk/001B64C4 (9, 25 KB), unk/MnuDiary
  (11, 18 KB), game/gamtrg (2, 7.7 KB), mag/magscene2 (3, 6 KB),
  unk/TskMsgMan (2, 4.5 KB), mag/magscene (14, 4.3 KB), mnu/mnusvld (8,
  4.3 KB), unk/001BE2CC (11, 4 KB), system/sysnowloading, mnu/mnudlg,
  game/gamman, msg/msgman, ... (a localisation pass for the US release).
- `mnu/mnuSelectLanguage.cpp` exists only in the US build: the Japanese
  game has no language menu. That confirms the file found inside the old
  game/gamman range (R16) as a US addition.
- Use: for the 129 changed functions, the Japanese version is a second,
  differently compiled view of the same source (handy to read, not to
  match). Everything else is the same code at other addresses, which also
  separates pointers from constants in .data/.rodata (see below).

## US trade demo / prototype, SLUS-28063 (July 19 2006)

Checked by Fable 2026-11-16: of 3,328 game-code chunks 3,322 are in the
demo; only 6 differ (2,616 B: 0x1A7088, 0x1A7C54, 0x12A03C, 0x126BD8,
0x129F98, 0x12B788). All 464 i3d chunks and all 357 sound chunks are in
it. Same compiler and source otherwise, so no extra asserts.

## Pointer detection (an idea, untested)

Both builds lay the same code and data out at other addresses (only 521
of the identical functions are byte-identical in the demo). A word of
.data/.rodata that differs between builds by the layout shift is a
pointer; one that is equal is a constant. That gives the PC port the list
of words that must become symbols (a possible tools/reloc_from_demo.py).

## Ape Escape 3 (mw/i3d)

See notes/I3D.md: 336 of our 464 i3d chunks are instruction-identical in
its three builds.
