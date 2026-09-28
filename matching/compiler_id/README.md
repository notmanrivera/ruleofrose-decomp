# Compiler identification

Goal: find the exact EE-GCC build and flags that reproduce the game's code
byte for byte. Everything after this (splat config, build system, matching
decomp) depends on it.

## Result (2026-09-28)

**`ee-gcc2.96` (SCE) with `-Os`**: all three test functions match byte for
byte (87/87 instructions). Every other build differs in 65+ instructions,
and `-O2`/`-O3` leave a register-allocation difference in
`getMotionLinkTime` that no source variant removed (6 tried).

Caveats: the sample is three inline methods from `dog/` headers. Other
modules may have been built with different flags, and `-G` can't be told
apart yet (no small globals involved). Confirm on more functions while
setting up splat.

```bash
docker build --platform linux/amd64 -t ror-build docker/
tools/.venv/bin/python tools/compiler_id.py          # full matrix
tools/.venv/bin/python tools/compiler_id.py --show ee-gcc2.96@3   # side-by-side
```

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

## How the matrix runs

`docker/Dockerfile` installs all eleven 2.9x builds from decomp.me's
tarballs (`ee-gcc2.9-991111b-r4` is the same tarball as `-991111`). The
SN builds are Windows binaries run with wibo; under Rosetta their driver
can't spawn subprocesses, so `docker/ee-cc` runs cpp, cc1plus and as
itself with the arguments the driver's specs produce.
