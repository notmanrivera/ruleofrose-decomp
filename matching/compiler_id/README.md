# Compiler identification

Goal: find the exact EE-GCC build and flags that reproduce the game's code
byte for byte. Everything after this (splat config, build system, matching
decomp) depends on it.

## What the binary already tells us

| Evidence | Conclusion |
|---|---|
| GCC 2 mangling (`_$_`, `__tf`, `_vt$`), no `_Z` names | GCC 2.9x. **Rules out ee-gcc 3.2** and Metrowerks |
| Non-thunk vtables (8-byte `{delta, index, pfn}` entries), `.gcc_except_table`, `.eh_frame` | GCC 2.9x C++ ABI with exceptions enabled |
| `.mdebug.eabi64` (empty) | `-mabi=eabi`, 64-bit `long`: standard EE-GCC configuration |
| Sony libraries tagged `3000` / `3020` (SDK 3.0.x) | Contemporary with ee-gcc 2.96 (SCE) and SN's 2.95.3 builds |
| Register moves via `daddu rd, rs, $zero`; callee-saved GPRs spilled with `sd` / `ld` (64-bit, not `sq`); `$f20` saved with `swc1` | Typical EE-GCC 2.9x codegen; doesn't separate versions by itself |
| Strings are loaded with `lui`/`addiu`, never `$gp`-relative | Probably `-G0` (or strings above the `-G` threshold) |

## Candidates

From [decompme/compilers](https://github.com/decompme/compilers/tree/main/platforms/ps2):

| id | Origin | Host binary |
|---|---|---|
| `ee-gcc2.96` | SCE toolchain | Linux |
| `ee-gcc2.9-990721`, `ee-gcc2.9-991111`, `-991111a`, `-991111b-r4`, `-991111-01`, `-991111-01-dtls13010` | SCE toolchain (earlier) | Linux |
| `ee-gcc2.95.2-273a`, `ee-gcc2.95.2-274` | SN Systems ProDG | Windows (via wibo) |
| `ee-gcc2.95.3-107`, `-114`, `-136` | SN Systems ProDG | Windows (via wibo) |

A 2006 game on SDK 3.0 makes `ee-gcc2.96` and the SN `2.95.3-1xx` builds
the most likely, but only compiling can tell.

## Test set

`candidates.cpp` reconstructs three inline methods. Their target assembly
is git-ignored (it is game code); generate it from your own ELF:

```bash
for f in setMotionSpeedSub__8DogActorif getMotionSpeedSub__C8DogActori getMotionLinkTime__8DogActori; do
  tools/.venv/bin/python tools/disasm.py $f > matching/compiler_id/$f.s
done
```

| Function | Address | Exercises |
|---|---|---|
| `DogActor::setMotionSpeedSub(int, float)` | `0x00281030` | float arg in `$f12`, `$f20` spill, assert call, `n*0x30` strength reduction |
| `DogActor::getMotionSpeedSub(int) const` | `0x0028109C` | float return, same shape as above |
| `DogActor::getMotionLinkTime(int)` | `0x00281114` | inlined callee, two asserts, `bnel` branch-likely |

Start with flags `-O2 -G0`; then try `-O1`, `-O3`, and `-fno-exceptions`.

## Running it

The compilers only run on Linux (or Windows for the SN builds), so either:

- **decomp.me** (browser): new scratch → PS2 → paste a `.s` as target and
  `candidates.cpp` as source → switch compilers and flags until the diff is
  empty. Note that scratches are public.
- **Locally**, in a Linux container: download the tarballs listed in
  `decompme/compilers/platforms/ps2/*/Dockerfile` and run `ee-gcc -S` on
  `candidates.cpp`.

Record the winning compiler and flags in `notes/PROJECT_STATE.md`.
