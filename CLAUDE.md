# Rule of Rose decomp — working rules

Matching decompilation of Rule of Rose (PS2, NTSC-U SLUS-214.48) into C++,
as the base for a native PC and then PS Vita port. Current state and
roadmap: `notes/PROJECT_STATE.md` (Spanish). Setup: `README.md` (English).

## Never commit game data

- No ELF, ISO, assets, or disassembly of game code. `disc/`, `ghidra/`,
  `build/` and `matching/**/*.s` are git-ignored; keep it that way.
- Committable: our own source, tools, notes, and derived symbol data
  (names, addresses, sizes, types).
- Each collaborator extracts `disc/SLUS_214.48` from their own disc.

## Toolchain

- Compiler: **ee-gcc2.96 (SCE), `-Os`**, confirmed byte for byte on three
  `dog/` functions. Treat other modules' flags as unconfirmed until matched.
- Compile only inside the `ror-build` image (`docker/`), via
  `ee-cc <compiler-id> <gcc args>`. On macOS the docker CLI may live in
  `~/.docker/bin`.
- Python tools run from `tools/.venv` (splat64, spimdisasm, rabbitizer,
  pyelftools).
- Ghidra 12.1.4 + ghidra-emotionengine-reloaded (built from source, see
  README); rebuild the project with `tools/ghidra_setup.sh`.

## Conventions

- Symbols come from `tools/ror_symbols.py`; regenerate rather than editing
  `symbols/*.tsv` by hand. Respect provenance: `linkonce` names are exact,
  `vtable-override` names are inferred (check signatures), `vtable-slot`
  names (`vfunc_NN`) are placeholders.
- Keep original identifiers where the binary reveals them (mangled names,
  assert expressions such as `n>=0 && n<=4`, source paths). Assert calls
  (`FUN_00215a30`) give the original file, line and expression; reproduce
  them with `#line` and the `ASSERT` macro.
- A function counts as done only when it compiles to identical bytes
  (relocations aside). Measure with `tools/compiler_id.py`-style scoring;
  never mark near-matches as matched.
- Ghidra scripts must not overwrite `USER_DEFINED` names or signatures.

## Communication

The project owner writes in Spanish and isn't a reverse-engineering
specialist: explain in Spanish, plainly. Code, commit messages and
developer-facing docs stay in English.
