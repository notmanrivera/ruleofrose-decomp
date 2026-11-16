# mw/i3d: SCE Japan's "i3d package"

What is known about the graphics library at 0x218500-0x237D00 (C, built
with other flags than the game: every function 8-aligned). Sources: our
binary, the owner's discs (in `disc/`, git-ignored) and outside research
(ChatGPT, 2026-11-15; links at the end). Checked facts are marked so.

## Identity

- **Checked:** it is SCE Japan's internal "i3d package". Rule of Rose says
  `i3d_package_version 050121-stable-050826` (MagSystem's size check,
  `src/mag/magsystem.cpp` ~250-275: 36 i3d type sizes through
  `func_0021F1A8(i)`); Ape Escape 3 (SCPS-15096, SCEJ 2005) says
  `i3d_package_version 050121`. 68 % of our i3d instruction 24-grams are
  in Ape Escape 3's ELF (Chulip: 0.05 %, game code 0 %). Both share the
  formats `I3D_BIN`, `I3D_I3M`, `I3D_I3C`, the names `I3DROOT_NODE`,
  `I3mPosture_s`, `I3dRender`, and the VU overlay sections
  (`.DVP.overlay..0x0.3420215670.9.0`, `..0x28a0.293874280.13.21`).
- **Reported (not checked):** ChainDive (SCPS-15054, Alvion/SCEI, 2003)
  has I3D_I / I3D_I3M blocks in its `.fld` archives: the package existed
  by 2003. Alvion later did support work on Ape Escape titles.
- Rule of Rose was published in Japan by SCE, which fits SCEJ handing its
  library to Punchline.

## Symbols

No ELF with symbols is known. Checked stripped: Rule of Rose retail
(SLUS-21448), its Jul 19 2006 prototype / trade demo (SLUS_280.63),
Ape Escape 3 retail JP (SCPS_150.96) and the US demo (SCUS-97548,
/APEESC3/APEESC3.ELF), Chulip. Not yet checked, candidates from the
outside research: Ape Escape 3 Japanese kiosk demo **PCPX-96657**, the
European review disc **SCES-53642 (Review)**, ChainDive retail
its demo on Official U.S. PlayStation Magazine **disc 79** (the retail
and the Japanese demo are checked, below), Saru! Get You! Million Monkeys demo
**PCPX-98041** (i3d use unconfirmed). Ape Escape 3 retail keeps a debug
menu and a `debug/` folder in DATA.BIN, but no symbols.

**Checked 2026-11-15, ChainDive** (owner's discs: retail SCPS_150.54 and the
Japanese demo PAPX_902.32): both stripped (the `.mdebug.eabi64` section is
empty, an ABI marker that Rule of Rose has too), and only the string
`I3D_I3M`; 0.1 % of our i3d instruction 24-grams (SDK 53 %). So its 2003
"i3d" shares the animation file format at most, not the code: no use for a
three-way comparison. Ape Escape 3 (68 %) stays the reference.

## Formats (public tools, for R13 and the port)

| Tool | Covers |
|---|---|
| Murugo/Misc-Game-Research `PS2/Rule of Rose/mdl2obj.py` | RoR `.mdl` (and an Ape Escape 3 `.i3d` put inside one) to `.obj`; no skeleton or vertex colours |
| Durik256/Noesis-Plugins `fmt_i3dg.py` | I3D_BIN meshes (Ape Escape 3) |
| Bigchillghost `fmt_RuleOfRose(PS2)_i3d` (ResHax topic 406) | RoR skeleton (bones) |
| Quake332 `fmt_RuleOfRose_PS2_i3d.py` (ResHax topic 406) | RoR skinning (weights) |
| pxdl/ae3-player (MIT) | Ape Escape 3 I3D models, TIM2 materials, skeletal animation |
| Ukkitan0/Getchu-3-PC | its own I3D renderer, I3C collision decoder, I3M animation |

Nodes are 0x10 bytes; types 0x25 materials, 0x2A bones, 0x2D meshes, 0x59
instances (Murugo); I3D_I3M (animation) and I3D_I3C (collision) have no
public viewer support beyond Getchu-3-PC. RoR packs its i3d blocks in
`.mdl` files inside `.RPK`/`.RTPK` archives (aluigi's
`rule_of_rose_rtpk.bms`); an Ape Escape 3 `.i3d` block dropped into a RoR
`.mdl` converts with mdl2obj.py, so the model format is the same.

## Port notes

- Ape Escape 3 runs through PS2Recomp in Yuukii-i/ApeEscape3_Recomp
  (boots to gameplay; VU1 interpreter plus generated native code, software
  and Vulkan GS) and Wifly413/ape-escape-3-recomp (PAL; D3D12/Vulkan via
  wgpu): the same i3d and VU microcode, so the hardest rendering work of a
  recompiled port of Rule of Rose has a working reference. Their fixes:
  VU0 macro-op base 0x11004000 with 4 KB wrap, `VIF1 MARK` interrupt
  (cause 5) that the engine waits on each frame, `sceGsSyncPath` draining
  DMAC handlers; `replaceFunction` swaps recompiled functions for
  hand-written ones (the hybrid-port mechanism).
- PCSX2-on-PS4 needs `--vif1-ignore-cmd-ints=1 --vif1-instant-xfer=0
  --vu1=jit-sync` for Ape Escape 3: the engine watches the VIF1/VU1 queue
  from the EE, so VIF1 transfers must not be instant and VU1 must run in
  step.
- VU1 microcode: captured at run time or taken from the ELF's
  `.DVP.ovlytab` overlays, then interpreted or translated ahead of time
  (`tools/vu1/generate_vu1.cpp` in the PS2Recomp ecosystem). Known VU
  pitfalls (PS2Recomp issues): vf0 writes in instruction pairs (#393),
  JR/JALR reading VI (#418), FE_TOWARDZERO left on at XGKICK (#422),
  sceVu0MulMatrix order (#361), VSQI/VSQD operands (#309). Skinning
  weights arrive through VIF UNPACK V4-5.
- PS2Recomp is GPL-3.0: a port linking its runtime would be GPL.

## Links

ResHax topic 406 (Ape Escape 3 / Rule of Rose .i3d), ResHax 19145
(ChainDive .fld), Hidden Palace "Rule of Rose (Jul 19, 2006 prototype)",
redump.org (Ape Escape demos), PCSX2 issues #11386 and #2607,
github.com/ran-j/PS2Recomp, github.com/exoteric33/ps2-native-recomp,
github.com/danielalves96/gow-pc-port (docs/dev/RENDERING.md, BUILD.md).
