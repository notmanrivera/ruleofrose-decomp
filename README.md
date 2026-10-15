# Rule of Rose — decompilation

A full decompilation of *Rule of Rose* (PlayStation 2, NTSC-U **SLUS-214.48**) into
C++ source, as the basis for a faithful native port (PC first, then PS Vita).

**This repository contains no game code or assets.** Everyone works from files
extracted from their own disc; `disc/`, the generated `asm/`, `assets/`,
`build/` and the Ghidra project are git-ignored.

## Status

The matching build works: splitting the ELF with splat into one file per
original source file and rebuilding it reproduces the game's load image
byte for byte (SHA-1 checked), now with decompiled C++ files linked in.
How to decompile a file: [docs/DECOMPILING.md](docs/DECOMPILING.md). See [notes/PROJECT_STATE.md](notes/PROJECT_STATE.md) for
findings and the roadmap.

| | |
|---|---|
| Matching build | ✅ SHA-1 `fa157dc8…1997` of the load image, with C++ linked in |
| Decompiled | 20 of 125 game files, 87,756 of 1,147,560 bytes of game code (7.65%), byte for byte: 16 complete, 4 with a few functions still asm (their C++ kept under `NON_MATCHING`); `tools/progress.py` |
| File split | 146 files ([config/splits.tsv](config/splits.tsv)): 125 game files (72 named from assert paths, 53 inferred `unk/...` files), the engine middleware (`mw/i3d` graphics, `mw/sound`) and 19 SDK runs (crt0 included); `.text`, `.rodata`, `.data` and `.bss` each split per file |
| Compiler | **ee-gcc 2.96 (SCE), `-Os -G0 -fno-exceptions -fno-strict-aliasing`**: 3/3 test functions match byte for byte ([details](matching/compiler_id/README.md)) |
| Functions found by Ghidra | 7,230 |
| Functions with their original name | 1,449 exact (`.gnu.linkonce`) + 111 inferred from vtable overrides + 648 SDK/libc/libgcc functions by signature |
| Virtual methods tied to a class only | 651 (`Class::vfunc_NN`) |
| Parameter types applied | 1,267 functions (demangler validated against Ghidra's GCC2 one: 1,160/1,160 equivalent) |
| C++ classes / vtables | 289 / 284, hierarchy in [notes/class_hierarchy.txt](notes/class_hierarchy.txt) |
| Functions tied to an original source file | 529, over 72 files ([notes/object_layout.txt](notes/object_layout.txt)) |

## Setup

Requirements: Docker (Apple Silicon: enable Rosetta emulation in Docker
Desktop), Python 3, Ghidra 12.1.4 + JDK 21, and the
[ghidra-emotionengine-reloaded](https://github.com/chaoticgd/ghidra-emotionengine-reloaded)
extension (it handles EE-specific instructions such as MMI and VU0 macro mode).

Copy `SLUS_214.48` from your disc into `disc/` first.

### Matching build

Everything runs inside the shared `ror-build` image (all EE-GCC 2.9x builds,
binutils, splat), through `tools/dock`:

```bash
docker build --platform linux/amd64 -t ror-build docker/
tools/dock python3 tools/configure.py   # extract the target image, split with splat, write build.ninja
tools/dock ninja                        # assemble/compile, link, verify SHA-1 (creates build/ok)
```

The first build takes a few minutes under emulation; later builds only redo
what changed.

To re-derive symbols and file boundaries (after a build, since they read
`asm/` and the linker map):

```bash
python3 tools/sce_symbols.py                     # SDK names by signature
python3 tools/ror_symbols.py                     # all symbols
tools/.venv/bin/python tools/split_files.py      # config/splits.tsv
tools/dock python3 tools/configure.py && tools/dock ninja
```

 When the SHA-1 doesn't
match, `tools/.venv/bin/python tools/first_diff.py` lists the differing
regions and the symbols they fall in.

### Host tools

```bash
python3 -m venv tools/.venv
tools/.venv/bin/pip install 'splat64[mips]==0.50.0' pyelftools ninja_syntax
tools/.venv/bin/pip install git+https://github.com/matt-kempster/m2c.git@708d2d2cb2698f091a92492b328f73b24209f72d
```

### Ghidra

```bash
brew install ghidra            # pulls openjdk@21 too
```

The extension has no release for Ghidra 12.1.4 yet (v2.1.37 stops at 12.1.3),
so build it against your install:

```bash
git clone --branch v2.1.37 https://github.com/chaoticgd/ghidra-emotionengine-reloaded.git
cd ghidra-emotionengine-reloaded
export GHIDRA_INSTALL_DIR=/opt/homebrew/opt/ghidra/libexec
export JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home
$GHIDRA_INSTALL_DIR/support/gradle/gradlew buildExtension -x test
unzip dist/*.zip -d ~/Library/ghidra/ghidra_12.1.4_PUBLIC/Extensions/
```

Then build the project:

```bash
tools/ghidra_setup.sh
```

That regenerates `symbols/`, imports the ELF as `r5900:LE:32:default` into
`ghidra/RuleOfRose.gpr`, applies the recovered symbols, runs auto-analysis and
tags functions with their source files (about a minute). Open the project with
`ghidraRun`.

## Layout

| Path | Contents |
|---|---|
| `tools/configure.py` | Generates `config/SLUS_214.48.yaml` from the ELF, runs splat, writes `build.ninja` |
| `tools/dock` | Runs a command inside the `ror-build` image |
| `tools/first_diff.py` | Where the built image differs from the original, by symbol |
| `tools/match.py` | Compiles one `src/` file and compares each function and data section with the game |
| `tools/progress.py` | Decompilation progress by files and bytes |
| `src/`, `include/ror.h` | Decompiled C++ (compiled from `src/` so `__FILE__` matches) and shared definitions |
| `tools/split_files.py` | Infers where each original file starts in `.text`/`.rodata` → `config/splits.tsv` |
| `tools/sce_symbols.py` | Names SDK functions with PS2Recomp's signature database (downloaded to `build/cache`, GPL, not committed) |
| `config/` | splat config (generated), `splits.tsv` (generated file boundaries), `splits_manual.tsv` (hand-made boundaries/names with evidence), manual symbol overrides, extra linker script |
| `docker/` | Shared build image: all EE-GCC 2.9x builds, binutils, splat; `ee-cc` compiler front end |
| `include/` | splat's assembler macros and `INCLUDE_ASM` header |
| `tools/ror_symbols.py` | Extracts symbols from the ELF: GCC2 demangling, RTTI hierarchy, vtable name propagation, source-path strings |
| `tools/ghidra_setup.sh` | One-shot headless Ghidra project build |
| `ghidra_scripts/ImportRoRSymbols.java` | Applies `symbols/ghidra_symbols.tsv` (classes, names, parameter types with explicit `this`, typed vtables); never overwrites names or signatures set by hand |
| `ghidra_scripts/TagSourceFiles.java` | Tags functions that reference assert source paths; writes `symbols/function_sources.tsv` |
| `tools/disasm.py` | R5900 disassembly of any function by name or address (GNU as syntax, for decomp.me) |
| `tools/compiler_id.py` | Compiles the test kit with every compiler/flag set and scores it against the game |
| `matching/compiler_id/` | Compiler-identification kit and result |
| `symbols/ghidra_symbols.tsv` | All recovered symbols, with provenance |
| `symbols/symbol_addrs.txt` | Same, in splat format (GCC2-mangled names) |
| `symbols/sce_symbols.tsv` | SDK functions matched by signature (address, library, name, size) |
| `notes/` | Findings, class hierarchy, object-file order |

## Symbol provenance

- `linkonce` — exact original (mangled) name from the ELF section table.
- `vtable-override` — a slot overriding a named slot in a parent or child
  class, so it has the same method name; its mangled name is derived from
  the overridden method's. Very reliable, not guaranteed: check the
  signature when decompiling.
- `vtable-slot` — unnamed virtual method; only the class is known.
- `shared-stub` — a function used at several vtable slot indexes
  (`__pure_virtual`); excluded from name propagation.
- `rtti-helper` — libgcc `__rtti_*` helpers, identified by how `__tf`
  functions call them.
- `sce-sdb` — SDK, libc or libgcc function whose masked bytes match a
  signature in PS2Recomp's database.
