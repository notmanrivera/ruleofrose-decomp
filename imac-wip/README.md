# iMac leftovers

Uncommitted files rescued from the iMac when work moved to Windows. Nothing
here is built; `build/` is git-ignored, so these are kept apart from the tree.

- `CLAIMS.md`: the file-claim list (locally excluded via `.git/info/exclude`).
  Session A had claimed `mnu/mnuselect`; no draft of it existed.
- `diffs/`: the working-tree changes to the generated
  `config/SLUS_214.48.yaml` in each checkout. `tools/configure.py` regenerates
  that file, so they only record state.
- `build-scratch/`: hand-written experiments from `build/`: `wip/dogactor.cpp`
  and `rtl/` (RTL dump helpers; `dump.sh` has iMac paths), `exp/` (`dm_test.cpp`,
  `flat.py`) and `probe/` (compiler-behaviour probes). The `dogactor` draft dates
  from 2026-10-02 and predates the current `src/dog/dogactor.cpp`.

Left out on purpose: object files, assembly (`.s`), compiler dumps, `asm/`,
`assets/`, `disc/` and `ghidra/`.
