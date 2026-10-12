# Map units (`DATA/BG/MAPUNIT.BIN`)

`MAPUNIT.BIN` (603 MB) holds every room of the game. It is an RPK pack
(`docs/formats/rpk.md`) of 263 smaller RPK packs, one per *map unit* (a room
or a stretch of corridor, e.g. `al_blur`, `au_salon`, `og_road01`).
Little-endian. Field names in `m_*` form, and the assert texts quoted, are
the game's; everything else is ours.

Readers (not decompiled yet; addresses in the ELF):

- `mag/magscene2.cpp`, 0x13836C: loads unit number `theNo`. Reads the first
  0x2000 bytes (`SIZE_HEADER`; asserts `pfh1.getFileOffset(0) <= SIZE_HEADER`
  and `theNo < pfh1.getNumFile()`), then the unit itself, its size rounded up
  to 0x800, into a 64-byte aligned buffer, and hands it to 0x1377F0, which
  parses it into one of the scene's 4 unit slots (0x520 bytes each).
- `game/gamman.cpp`, 0x1CA0DC: reads the first 0x1800 bytes and looks a unit
  up by name (the text before the first `.`), then loads it the same way.
- `mag/magloader.cpp`, 0x142ED8: reads the first 0x2000 bytes and keeps the
  file count, offsets and sizes in its own table.

## Outer pack

RPK with flags 0xC003 (sizes, offsets, names), `m_align` 0x800, 263 files.
The names are the unit names, without extension. The first unit starts at
0x1800, so the header fits in both read sizes above.

## Unit pack

Each unit is an RPK with flags 0x8003 (sizes, offsets, names with extension)
and `m_align` 0x20. Members are found by name (`BedPfh::getIndex`), with
`<u>` = the unit name:

| Member | Units | Content |
|---|---|---|
| `<u>.mdl` | 263 | the room model, always the first member (below) |
| `<u>_c.bin` | 263 | cameras (below) |
| `mapparam.bbb` | 263 | fog and other scene parameters (below) |
| `<u>_col.i3s.i3r` | 263 | collision model, `I3D_BIN` (i3d middleware) |
| `<u>_col.i3s.i3c` | 263 | collision data, `I3D_I3C`; must be the member right after the `.i3r`, because the loader takes index + 1 |
| `<u>_l.bin` | 263 | lights (below); empty (0 bytes) in 3 units, which then have no light set |
| `tenkyu.rpk` | 29 | sky dome (*tenkyū*, "celestial sphere") (below) |
| `sector.sec` | 245 | sector layers, read by `SctLayer` (below) |

On the disc the members always come in this order: `.mdl`, `_c.bin`,
`mapparam.bbb`, `.i3r`, `.i3c`, `_l.bin`, then `tenkyu.rpk` and
`sector.sec` when present.

### `<u>.mdl`

An RPK with flags 0x0003 (sizes and offsets, no names), 3 files:

| # | Content |
|---|---|
| 0 | texture pack: RPK with flags 0xC002, `m_align` 0x40, one `TIM2` image per file, named (e.g. `albl_wal`, `albl_kage_tcc`) |
| 1 | `I3D_BIN`: the room model, loaded with the textures by `DogModel` |
| 2 | `I3D_BIN`: a second model, loaded only when the pack has more than 2 files, into a second `DogModel` and attached to an i3d object of the scene (purpose unknown) |

### `<u>_c.bin`: cameras (`mag/magscenecamera.cpp`)

| Offset | Type | Meaning |
|---|---|---|
| 0x00 | u16 | number of camera paths (1 to 9 on the disc) |
| 0x02 | u16 | 0 or 1: fixed cameras come in pairs (below) |
| 0x04 | count × u32 | offset of each path from the start of the file |

The first path follows the table directly. The scene picks a camera by unit
slot and path index (`m_cam_map_no`, `m_cam_path_no`). Each path ("`ppath`"):

| Offset | Type | Field | Meaning |
|---|---|---|---|
| 0x00 | u8 | `m_pos_num` | number of positions, 1 to 255 (asserts `ppath->m_pos_num > 0`, `numpos > 0 && numpos < 256`). 1 = a fixed camera; more = the camera slides along the line through them |
| 0x01 | u8 | | 0 in every path but one; read by the path code |
| 0x02 | u8 | | 0 on the disc; the loader copies the file's 0x02 field here |
| 0x03 | u8 | | 0 on the disc; at run time, which camera of a fixed pair is active (toggled) |
| 0x04 | f32 | | field of view, in degrees |
| 0x08 | f32 | | 1.0 (2.54 in 4 paths) |
| 0x0C | f32 | | 1000.0 (2540.0 in 4 paths) |
| 0x10 | 3 × f32 | | rotation in radians; the first two become the camera's X and Y rotation |
| 0x1C | 4 × char | | option letters, `'a'`..`'z'` or 0 (below) |
| 0x20 | s32 | | run time: current segment (the loader sets `m_pos_num / 2`) |
| 0x24 | s32 | | run time: target segment |
| 0x28 | f32 | | run time: position within the current segment, 0 to 1 |
| 0x2C | f32 | | run time: target position within the segment |
| 0x30 | `m_pos_num` × 4 × f32 | | positions (x, y, z, w); the camera position is interpolated linearly between position *i* and *i* + 1 (wrapping to 0) |

0x20-0x2F are zero on the disc. When the file's 0x02 field is 1, every
fixed camera (`m_pos_num` = 1) is followed by a second 0x40-byte record of
the same shape, and 0x03 chooses between the two.

Option letters (each read only if it is a letter):

- 0x1C, `'a'`..`'h'`: bit 2 of (letter - `'a'`) sets a mode flag of the path.
  On the disc: `d` (204), `h` (137), `b`, `a`.
- 0x1D: a distance, (letter - `'a'`) × 20 + 100, instead of the scene's
  default.
- 0x1E: (letter - `'a'`) × 10, added to one limit and taken from another.
- 0x1F: passed as (letter - `'a'`) to 0x13E4C0; unused on the disc.

### `mapparam.bbb`

0x30 bytes, 12 × s32 (index 10 is an f32). The loader reads indices 8-10
only when the file is longer than 0x20 bytes (all of them are).

| Index | Meaning |
|---|---|
| 0 | 1 to 65535 (2000 in 226 units); converted to float and stored in the scene (0x2AA14, 0x2AA4C); probably a draw distance |
| 1-3 | fog colour, R G B; divided by 255 |
| 4 | fog start distance (400-1000) |
| 5 | fog amount at the start, / 100 (0 everywhere) |
| 6 | fog end distance (1200-3000) |
| 7 | fog amount at the end, / 100 (100 everywhere) |
| 8 | stored as is in the scene (0x854A4); 1, 2, 4, 8, 9, 10... |
| 9 | stored as is (0x85494); 0, 2 or 3; selects a code path in 0x13B870 |
| 10 | f32, stored as is (0x85498); 0 or ±170.0 and similar |
| 11 | / 100, clamped to 0..1 (default 1.0); multiplies another scene value |

Indices 1-7 go to the scene as one block of 8 floats (colour, w = 0, start,
start amount, end, end amount). The code that reads it back interpolates the
amount between the start and end distances, which is why we call it fog.

### `<u>_l.bin`: lights (`mag/magscenelight.cpp`, 0x13F658)

| Offset | Type | Meaning |
|---|---|---|
| 0x00 | s32 | number of directional lights, 0 or 1 |
| 0x04 | s32 | number of point lights |
| 0x08 | s32 | index of one light, counting the directional light first, that gets an extra call (0x13FBE4); -1 = none (22 units) |
| 0x0C | s32 | 0 |
| 0x10 | 3 × f32 | ambient colour |
| 0x1C | f32 | 0 |
| 0x20 | | the directional light, then the point lights, 0x20 bytes each |

Directional light: colour (3 × f32), then direction (4 × f32) at +0x0C,
+0x1C unused. Point light: colour (3 × f32), position (3 × f32) at +0x0C,
intensity (f32, multiplies the colour) at +0x18, +0x1C unused. The file size
is always 0x20 + 0x20 × (directional + point). The words colour, direction
and position are inferred: each vector goes to the same setter (0x13F980)
with a different parameter code (2, 1 and 0), as in `DogLightPool`.

### `tenkyu.rpk`: sky dome (0x140030)

RPK with flags 0xC003. Member 0 is an `I3D_I3M` (an i3d animation; the
loader also accepts a pack without it), then the `I3D_BIN` model, then its
`TIM2` textures (e.g. `sky02.i3s`, `sky02.i3s`, `sky1_tcc`, `sora3`). The
model is copied to the heap and loaded with the textures of the same pack.

### `sector.sec`: sector layers (`SctLayer`)

`SctLayer` is the game's class name (RTTI; its inline methods `getLayer`,
`getGroup(int)` and `getCell(int)` show the record sizes). The words
*group* and *cell* are from those names; *link* is ours.

| Offset | Type | Meaning |
|---|---|---|
| 0x00 | u32 | 0x100 in every file |
| 0x04 | 4 × u32 | offset of each layer from the start of the file, 0 = no layer (all 245 files have 4) |
| 0x14 | 12 bytes | 0 |

Each layer starts at the end of the previous one rounded up to 16, the
first at 0x20, and the last one ends at the end of the file.

| Offset | Type | Meaning |
|---|---|---|
| 0x00 | s32 | layer number, 0 to 3 |
| 0x04 | s32 | number of groups |
| 0x08 | s32 | number of cells |
| 0x0C | s32 | number of links |
| 0x10 | groups × 0x80 | groups |
|  | cells × 0x90 | cells |
|  | links × 0x20 | links |
|  | | the links' cell lists |

Group: +0x00 its index; +0x5C flags (1 on the disc; when bit 0 is set the
loader turns +0x60 into a pointer); +0x60 offset from the group to its first
cell; +0x64 a count no larger than the number of cells. Cell: +0x00 its
index. Link: +0x14 offset from the link to its list, +0x18 number of
entries, +0x1C flags (same rule as the groups); each entry is a cell index,
which the loader turns into a cell pointer. The rest of the three records is
not read by the loader.

## Checked against the disc

All 263 units were checked against everything above: the outer and inner
pack headers, member names and order, the `.mdl` structure and its texture
pack, camera table and path sizes (0x30 + 16 × `m_pos_num`, + 0x40 for
fixed pairs; 550 paths), option letters, light file sizes, `mapparam.bbb`
sizes and index 0, and the sector header, layer placement, group-to-cell
offsets, link lists and cell indices. No mismatches.

## Still unknown

- The two `I3D_BIN` models of `.mdl` and what the second one is for (the
  i3d formats themselves are the middleware's; see `notes/PROJECT_STATE.md`).
- Camera path 0x01, 0x08 and 0x0C (likely near and far planes: 1 / 1000 and
  2.54 / 2540), the third rotation value, and what the option letters do.
- `mapparam.bbb` indices 0, 8, 9, 10 and 11; whether 1-7 really are fog.
- The light picked by `_l.bin` 0x08.
- What sectors, groups, cells and links are for, and the rest of their
  records (probably the room's areas for visibility or AI).
