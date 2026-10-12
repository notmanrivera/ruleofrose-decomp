# Streamed audio (`DATA/SND/XWS/*.STR`)

`DATA/SND/XWS` holds the game's streamed audio: 844 `S######.STR` files
(voices, music, jingles) and their table, `STR_TBL.BIN`. There are no `.STR`
files anywhere else on the disc. Little-endian. Names from asserts or
strings are quoted; the rest are ours.

## `S######.STR`

Raw PS-ADPCM (the SPU's 4-bit ADPCM, 16-byte frames of 28 samples), with
no header. The number in the name is the sound id.

| Files | Ids | Channels | Interleave |
|---|---|---|---|
| `S0xxxxx.STR` (777) | below 100000 | 1 | |
| `S1xxxxx.STR` (67) | 100000 and up | 2 | 0x10: the frames alternate left, right |

The sample rate is 48,000 Hz for both.

Evidence:

- `snd/sndman.cpp`, 0x180230: opens `"data/snd/xws/"` + the file name as a
  stream of the sound library (0x2437A8, buffers of 0x40000 and 0x20000
  bytes), then creates the voice with 48000 (0x23DCC8; the library turns
  it into an SPU pitch, rate × 4096 / 48000, so 48000 plays at 1:1).
- The channel count comes from 0x17FD58, which stores 0 (mono) or 2
  (stereo) in the stream; the library opens one channel for 0 and two for
  2. 0x1E5250 builds the name with `"s%06d.str"` and asks for stereo when the
  id is above 99999; the fixed `"s100000.str"` is played in stereo too.
- On the disc every file is a multiple of 16 bytes; mono files have flag
  byte 0 except the end flag (1) on the last frame; stereo files have the
  end flag on their last two frames, and the 41 looped stereo files (flags
  2, 6 at the loop start, 3 at the end) have the loop start on a pair of
  consecutive frames, 2k and 2k + 1, as a 0x10 interleave requires. The
  first frame is silent in all 844.

### vgmstream

[vgmstream](https://github.com/vgmstream/vgmstream) can play them with a
TXTH file. Save this as `.str.txth` next to the mono files:

```
codec = PSX
channels = 1
sample_rate = 48000
start_offset = 0
num_samples = data_size
loop_flag = auto
```

and this as `.str.txth` in a folder holding the `S1xxxxx.STR` files:

```
codec = PSX
channels = 2
interleave = 0x10
sample_rate = 48000
start_offset = 0
num_samples = data_size
loop_flag = auto
```

## `STR_TBL.BIN`

844 entries of 0x38 bytes, one per `.STR`, then an entry with id -1, then
8 zero bytes (47,328 bytes). The same bytes are member 5 of
`data/SEQ/G000.GRB` (`docs/formats/ara.md`), which is where the game takes
them from: 0x1E484C copies them into a table of up to 900 entries at
start-up. Nothing in the ELF reads the loose file (its path,
`data/snd/xws/str_tbl.bin`, is only a string).

| Offset | Type | Meaning |
|---|---|---|
| 0x00 | char[0x1C] | name, e.g. `M00` (music), `A0072_00_SUS` (a voice line) |
| 0x1C | s32 | sound id = the file number; -1 ends the table |
| 0x20 | 3 × u16 | 0 |
| 0x26 | u16 | 80 in every entry |
| 0x28 | u16 | 128 in every entry |
| 0x2A | u16 | far distance (1700) |
| 0x2C | u16 | near distance (200) |
| 0x2E | u16 | volume at the near distance or closer (128) |
| 0x30 | u16 | volume at the far distance or farther (0) |
| 0x32 | 6 bytes | 0 |

0x1E4C1C looks an id up, starting at entry (id % 100000) / 2 and wrapping at
the -1 entry. 0x1E6E00 computes the volume of a sound placed in the world
from 0x2A-0x30: between the two distances it interpolates the two volumes
linearly, then splits it between the left and right channels.

## Checked against the disc

All 844 `.STR` were checked for size, flag bytes and loop and end positions,
as above. Every id of `STR_TBL.BIN` has its file and every file its entry.
The channel and rate rules come from the code, not from listening.

## Still unknown

- `STR_TBL.BIN` 0x26 and 0x28.
- The `test/aiff/st_00N.xws` and `test/wav/st_00N.xws` names in the ELF:
  leftover test streams, not on the disc.
