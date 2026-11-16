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

## Leads from the owner's outside research (2026-11-16)

Unchecked unless marked. Source: the owner's report (ChatGPT search of
Lost Releases, Hidden Palace, Retro Reversing, PCSX2 forums/wiki).

- Rule of Rose promos: SCPS-15093 (Japanese promo, same serial as retail:
  probably the retail ELF; **checked**: the retail ELF is above) and
  SLES-54218 (European promo, same serial as the European retail). Hidden
  Palace lists only the July 19 2006 prototype. A Japanese auction titled
  "開発ロム 体験版" (development ROM / trial) is unverified.
- **Sony libraries (sdk/, 0 %)**: Retro Reversing's "PS2 Demo Disks with
  Debug Symbols" lists SDK 3.0.x builds with symbols: Rumble Roses PAL demo
  (SCED-52170, SDK 3.0.1, .MAP file), Athens 2004 PAL demo (SCED-53122,
  3.0.0, .MAP), Full Spectrum Warrior PAL demo (SCED-53160, 3.0.0, 19,690
  symbols in .sndata), a Resident Evil 4 prototype (.mdebug). A .MAP of a
  build with our SDK version would name the sdk/ functions and their
  object files (= file boundaries). Our sdk/ names now come from SDK
  signatures (sce-sdb); compare versions before trusting a .MAP.
- **Sound (mw/sound, 0x237D00-0x24B490, ~78 KB; with mw/i3d ~204 KB)**:
  RXSNDDRV.IRX ("Start RX - sound RPC server", "Installed sound driver
  version 1.00", SE / ADPCM stream / PCM stream systems, loaded after
  LIBSD.IRX) is also loaded by Arc the Lad: Twilight of the Spirits
  (SCUS-97231) and Wild Arms 5 (SLUS-21615); Retro Reversing counts six
  discs with it. Their ELFs may share the EE client library (rxSnd*,
  rxmpeg): an instruction comparison like the i3d one would tell, and any
  of them with symbols would name it.
- Punchline / Shirogumi interview (PlayStation C.A.M.P., January 2006,
  Shuji Ishikawa and Makoto Hanafusa): Punchline programmed, Shirogumi did
  the graphics and cut scenes; **three simultaneous light sources**, the
  rest painted into vertex colours and textures; motion capture for the
  children and Brown. For the port: keep vertex colours, texture
  modulation and the original render states, not only the dynamic lights.
  Nothing explains the Mag/Dog prefixes.
- Million Monkeys trial (PCPX-98041): **checked**, no i3d (notes/I3D.md).

## Sound library and SDK, other games (checked 2026-11-16)

The owner's discs: Wild Arms: The Vth Vanguard trial (Japan, PAPX_905.24),
Arc the Lad: Seirei no Tasogare premiere disc (Japan demo, PAPX_902.30),
Arc the Lad: Twilight of the Spirits (USA, SCUS_972.31), Athens 2004 PAL
demo (SCED_524.91; not the SCED-53122 that Retro Reversing lists with a
.MAP: no .MAP or symbols on this disc). All stripped.

| ELF | SDK | mw/sound chunks found | sdk/ chunks found |
|---|---|---|---|
| Wild Arms 5 trial | 3.0.0 (libdbc 3030) | 370/375 (75.6 of 76.8 KB) | 469/1376 (125 of 264 KB) |
| Arc the Lad JP demo | 2.6.0 | 264/375 (40.6 KB) | 298/1376 (75 KB) |
| Arc the Lad USA | 2.4.x | 6/375 | 149/1376 |
| Athens 2004 demo | 3.0.0 | 0 | 211/1376 (59 KB) |

- mw/sound is SCE's shared "rx" library (RXSNDDRV.IRX on the IOP; rxSnd*,
  rxFile, rxThread on the EE), nearly identical in Wild Arms 5: not
  Punchline's own code. Same treatment as i3d: work done on it serves
  other games, and Wild Arms 5 is the reference copy.
- Names: the rx strings that code references, in functions identical to
  ours, give only what our own ELF already says: 0x23B3B4 (uses
  "rxSndBgmStop"), 0x23C0F8 ("rxSndSeStop"), 0x23CE94 ("rxSndPcmClose"),
  0x23E01C ("rxSndAdpcmClose"), 0x2480A8 (rxFile HDD I/O error),
  0x24A258 (rxThAddCallback failed), 0x24AFF4 / 0x24B048 (rxThread
  messages). Likely those functions' names or their callers' (unchecked).
  The Arc the Lad demo's other 70 rx strings (rxHdd*, rxGsSyncPath) are
  modules Rule of Rose does not link.
- No .MAP among these, so the sdk/ names still come from signatures.
