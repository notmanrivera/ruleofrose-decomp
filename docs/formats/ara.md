# Area packs (`DATA/SEQ/W###/A###/A###.ARA`)

Each `.ARA` holds what one *area* needs on top of its map units: the area's
event script, compiled to MIPS code, and its sound banks. There are 1,134 of
them, in 12 world folders (`W001`-`W013`, no `W009`; 50 to 154 areas each).
Each `A###` folder holds only `A###.ARA`, of the same number. Every world
folder, and `W014`, `W098` and `W099`, also has a `W000.WRD`.
Little-endian. Names from asserts or strings are quoted; the rest are ours.

`DATA/SEQ` holds no `.STR` files: the 844 `.STR` are the streamed audio in
`DATA/SND/XWS` (`docs/formats/str.md`).

Reader: `game/gamman.cpp`, 0x1C47C4 (not decompiled yet). It builds the path
`data/SEQ/W%03d/A%03d/A%03d.ARA` from the current world and area numbers,
reads the first 0x1800 bytes, then the whole file (its size rounded up to
0x800), uses the members below, and frees the buffer. 0x1C3A48 does the
same for an area pack already in memory.

## Pack

An RPK (`docs/formats/rpk.md`) with flags 0x0003 (sizes and offsets, no
names) and `m_align` 0x10. With N = the number of ids in member 0, it has
6 + N members:

| # | Content | Use |
|---|---|---|
| 0 | s16 ids, ended by -1 | one id per extra actor; always empty on the disc (16 bytes of 0xFF) |
| 1 | 16 bytes of 0xFF | not read by the loader |
| 2 .. N+1 | actor data | each one is loaded into a free actor slot of the scene (0x138CE8) with its id; none on the disc |
| N+2 | `ELFR101` script (below) | handed to the sequence system (0x20EFAC) |
| N+3 | node table (below) | |
| N+4 | area info, 0x1D0 bytes (below) | passed to 0x1DBCF0, which does not read it in this build |
| N+5 | sound pack: RPK with flags 0x0002, `m_align` 0x10, 8 files: a 1,536-byte table, then 7 `XVAB` sound banks (the format of `DATA/SND/XV/*.SE`) | 666 areas; the other 468 have 16 bytes of 0xFF here |

Members N+2, N+3 and N+4 are contiguous. The sequence system copies
0x30000 bytes starting at the script into its own memory, so the node table
and the area info travel with the code.

## The `ELFR101` script

The sequence system (`sequence/`, 0x20D624 on) runs these scripts in a MIPS
interpreter (0x214C24 decodes the opcode in bits 26-31 and calls a handler
per opcode), not on the CPU. The code is little-endian MIPS, linked for an
address close to 0x450000 (0x44FA50 to 0x450080). `data/SEQ/G000.GRB`
holds the global script and tables (below).

| Offset | Type | Meaning |
|---|---|---|
| 0x00 | char[8] | `"ELFR101\0"` |
| 0x08 | s32 | 0 |
| 0x0C | s32 | negative; equal to -(\[0x18\] - \[0x1C\] - 0x10) in 986 of 1,134 scripts |
| 0x10 | s32 | script-space address of the end of the member (the load address is this minus the member size) |
| 0x14 | s32 | size of the code part, header included |
| 0x18 | s32 | size of the data part; 0x14 + 0x18 = member size |
| 0x1C | s32 | smaller than 0x18 |
| 0x20 | s32 | script-space address; \[0x10\] - 0x8010 in 986 scripts (a `$gp`-style pointer?) |
| 0x24 | s32 | script-space address below the load address (0x40xxxx-0x41xxxx), probably into the global script |
| 0x28 | 2 × s32 | 0 |
| 0x30 | | code; it starts with a function prologue (`addiu $sp, $sp, -n`) |

When it loads a script (0x213F48), the sequence system keeps 0x30 as the
code start, 0x10, 0x14, 0x14 + 0x1C + 8, 0x20 and 0x24, and writes two
words 0x20 and 0x10 bytes before the end of the member. It then starts a
thread at the code (0x211E84), looking for the `addiu $sp` prologue in the
words at 0x30-0x3C and then 0x20-0x2C.

## Node table (member N+3)

A 0x10-byte header, then *k* records of 0x80 bytes (k = 2 to 546). Header
word 0 is 0; word 3 is 0x20 in 1,008 files. In each record, +0x10..+0x4F
are 16 link slots, each -1 or the offset of another record (a multiple of
0x80); floats that look like positions and bounds follow. Probably the
area's navigation graph; no reader found yet outside the script.

## Area info (member N+4)

| Offset | Type | Meaning |
|---|---|---|
| 0x00 | char[0x20] | map unit name, in 24 areas only |
| 0x80 | char[0x20] | place, Shift-JIS (e.g. 孤児院, "orphanage") |
| 0xA0 | char[0x20] | area name, Shift-JIS (e.g. 一階廊下, "first floor corridor") |
| 0xC0 | 4 × char[0x20] | names of up to 4 rooms, Shift-JIS |
| 0x140 | 4 × char[0x20] | the map unit of each of those rooms (e.g. `o1_wash`) |
| 0x1C0 | 3 × s32 | 1, 2, 3 or 0xFFFF; then two signed values (0 to 40,850 and -14,400 to 4,250; 0xFFFF for all three in the placeholders) |

This reads like editor or debug data. 844 of the 954 unit names in
0x140-0x1BF exist in `MAPUNIT.BIN`; the rest are placeholders (`dummy Room`,
`-`) or units not on the disc. 8 files have bytes in the name slots that are
not valid Shift-JIS.

## `G000.GRB`

`data/SEQ/G000.GRB` (0x1C1B48, during start-up; the debug path
`data/seq/seq_global/g000.seq` is also in the ELF) is an RPK with flags
0x0002 and `m_align` 0x10, 6 files:

| # | Content | Use |
|---|---|---|
| 0 | starts with `"UNQ_"` | 0x1DBEF8 |
| 1 | same bytes as `DATA/SND/XV/0000.SE` | loaded as sound bank `0000.se` |
| 2 | same bytes as `DATA/SND/XV/6400.SE` | loaded as sound bank `6400.se` |
| 3 | same bytes as `DATA/SND/XV/G000_TBL.BIN` | 0x1E4790 |
| 4 | `ELFR101` global script | 0x20EEA8 |
| 5 | same bytes as `DATA/SND/XWS/STR_TBL.BIN` | the streamed-audio table (`docs/formats/str.md`) |

## Checked against the disc

All 1,134 `.ARA` were checked: pack flags, alignment, `m_size`, the first
offset (within the 0x1800 bytes read first), 6 + N members, members 0 and 1,
every `ELFR101` header rule above that is not marked as partial, node table
sizes and link slots, area info size, members N+2 to N+4 contiguous and
inside the 0x30000 bytes copied, and the sound pack (or its placeholder).
No mismatches. The `G000.GRB` members were compared byte for byte with the
loose files.

## Still unknown

- The ids and actor data of members 0 and 2..N+1 (unused on the disc), and
  member 1.
- `ELFR101` 0x0C, 0x1C, 0x20 and 0x24, exactly; how the script calls the
  game, and how its addresses map onto the copied buffer.
- The node table records, and the first 1,536 bytes of the sound pack.
- Who loads the area's sound pack: the loader frees the file after copying
  the script, and the sound pack lies outside the copied 0x30000 bytes.
- The three words at 0x1C0 of the area info.
- `G000.GRB` member 0.
