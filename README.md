# Rule of Rose — decompilation

A full decompilation of *Rule of Rose* (PlayStation 2, NTSC-U **SLUS-214.48**) into
C++ source, as the basis for a faithful native port to PS Vita.

**This repository contains no game code or assets.** Everyone works from files
extracted from their own disc; `disc/` and the generated Ghidra project are
git-ignored.

## Status

Reverse-engineering groundwork. Nothing is decompiled yet. See
[notes/PROJECT_STATE.md](notes/PROJECT_STATE.md) for findings and the roadmap.

| | |
|---|---|
| Functions found by Ghidra | 7,230 |
| Functions with their original name | 1,449 (from `.gnu.linkonce`) + 431 (inferred from vtable overrides) |
| Functions tied to a class only | 332 (`Class::vfunc_NN`) |
| Parameter types applied | 1,587 functions (validated against Ghidra's GCC2 demangler: 1,160/1,160 equivalent) |
| C++ classes / vtables | 289 / 284, hierarchy in [notes/class_hierarchy.txt](notes/class_hierarchy.txt) |
| Functions tied to an original source file | 529, over 72 files ([notes/object_layout.txt](notes/object_layout.txt)) |

## Setup

Requirements: Python 3 (plus `python3 -m venv tools/.venv && tools/.venv/bin/pip install 'splat64[mips]'` for `tools/disasm.py`), Ghidra 12.1.4 + JDK 21, and the
[ghidra-emotionengine-reloaded](https://github.com/chaoticgd/ghidra-emotionengine-reloaded)
extension (it handles EE-specific instructions such as MMI and VU0 macro mode).

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

Then copy `SLUS_214.48` from your disc into `disc/` and build the Ghidra project:

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
| `tools/ror_symbols.py` | Extracts symbols from the ELF: GCC2 demangling, RTTI hierarchy, vtable name propagation, source-path strings |
| `tools/ghidra_setup.sh` | One-shot headless Ghidra project build |
| `ghidra_scripts/ImportRoRSymbols.java` | Applies `symbols/ghidra_symbols.tsv` (classes, names, parameter types with explicit `this`, typed vtables); never overwrites names or signatures set by hand |
| `ghidra_scripts/TagSourceFiles.java` | Tags functions that reference assert source paths; writes `symbols/function_sources.tsv` |
| `tools/disasm.py` | R5900 disassembly of any function by name or address (GNU as syntax, for decomp.me) |
| `matching/compiler_id/` | Kit to identify the exact compiler and flags |
| `symbols/ghidra_symbols.tsv` | All recovered symbols, with provenance (`linkonce`, `vtable-override`, `vtable-slot`, `rtti-helper`) |
| `symbols/symbol_addrs.txt` | Same, in splat format, for the future matching build |
| `notes/` | Findings, class hierarchy, object-file order |

## Symbol provenance

- `linkonce` — exact original (mangled) name from the ELF section table.
- `vtable-override` — a slot overriding a named slot in a parent or child
  class, so it has the same method name. Very reliable, not guaranteed:
  check the signature when decompiling.
- `vtable-slot` — unnamed virtual method; only the class is known.
- `rtti-helper` — libgcc `__rtti_*` helpers, identified by how `__tf`
  functions call them.
