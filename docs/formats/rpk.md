# RPK packs ("RTPK")

Every `*.RPK` on the disc (49 of them: `DATA/CH/CHARA.RPK`, `DATA/EVT/*.RPK`,
`DATA/MNURPK/**.RPK`, `DATA/CMNTEX/CMNTEX.RPK`, `DATA/PREMIERE.RPK`...) is an
archive read by `BedPfh` (`src/bed/bedpfh.h`, `src/bed/bedpfh.cpp`, matching
decompilation). Little-endian. Field names in `m_*` form are the game's where
the asserts give them (`m_num_file`, `m_top`, `m_user_data`); the rest are
ours.

## Header (0x20 bytes)

| Offset | Type | Field | Meaning |
|---|---|---|---|
| 0x00 | u32 | `m_id` | `"RTPK"` (0x4B505452); `BedPfh::checkID` asserts it |
| 0x04 | s32 | `m_size` | size of the whole pack, header included (= the file size) |
| 0x08 | s16 | `m_unk08` | 0 in every pack |
| 0x0A | s16 | `m_flags` | which tables follow (below) |
| 0x0C | s16 | `m_align` | files start at multiples of this: 0x800 (a DVD sector), 0x20 in `CMNTEX.RPK` |
| 0x0E | s16 | `m_num_file` | number of files |
| 0x10 | s32 | `m_name_size` | bytes of the name table |
| 0x14 | 3 × s32 | | 0 |

## Tables

Right after the header, in this order, each present only if its flag is set
(`BedPfh::setTop`):

| Flag | Table | `BedPfh` member |
|---|---|---|
| 0x0001 | `m_num_file` × s32: size of each file | `m_file_size` |
| 0x0002 | `m_num_file` × s32: offset of each file from the start of the pack | `m_file_offset` |
| 0x0010, 0x0020, ... | one table of `m_num_file` × s16 per consecutive bit from 0x0010 | `m_user_data` |
| 0x8000 | `m_name_size` bytes: one NUL-terminated name per file, in file order | `m_name` |

Then the files. The first starts at the end of the tables rounded up to
`m_align`, and each next one at the end of the previous rounded up to
`m_align`. `BedPfh::getName(n)` walks the name table; `BedPfh::getIndex(name)`
looks a name up (-1 if absent).

Flags seen on the disc: 0x8003 (16 packs; names with extensions, e.g.
`base.tm2`, `fnt16US.bin`), 0xC003 (31), 0xC002 (`CMNTEX.RPK`, no size table)
and 0x0003 (`MOTIONPK.RPK`, no names). Nothing in `bed/bedpfh` reads 0x4000;
the packs with it have names without extension. No pack on the disc has user
data tables, but `dog/dogactor` reads them (`m_user_data[n] & 0xFFF`).

All 49 packs were checked against this layout: signature, `m_size`, the
first offset and every following one.

## Still unknown

- Flag 0x4000.
- What the user data values mean.
- The inline methods at `bed/bedpfh.h` lines 81 and 85-86, used by other
  files (`getFileOffset` is one of them, by name).
