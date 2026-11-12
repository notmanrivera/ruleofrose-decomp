# Worker brief

The text a coordinator sends to a worker agent (see `DECOMPILING.md` §6).
Fill in `<NAME>`, `<FILE>` and `<FUNCS>`, and send it as **one line**: Orca
on Windows breaks multi-line prompts, and an agent's TUI submits at the
first newline. `<FUNCS>` comes from
`tools/backlog.py --file <FILE> --names 20`.

## First brief (fresh session)

```text
You work in this git worktree only: ror-wt-<NAME> (branch wt/<NAME>). Read docs/DECOMPILING.md sections 2, 3 and 6 first. Task: decompile functions of src/<FILE>.cpp (file argument <FILE>) so they compile to identical bytes. Commands (PowerShell, from the worktree root): $py = "..\ruleofrose-decomp-main\tools\.venv\Scripts\python.exe" ; & $py tools\match.py --server start ; & $py tools\work.py <FILE> <func> (check) ; & $py tools\work.py <FILE> <func> --done (only on MATCH). Functions, in this order: <FUNCS>. Rules: edit only src/<FILE>.cpp (declare what you need locally; an asm("name") alias is fine when a prototype already exists with another signature; keep X__vfunc_NN placeholder names as the asm label); never commit asm/, build/, disc/ or any .s file; never push; commit on top of wt/<NAME> as it is (no reset, no rebase). One commit per MATCH with message "<FILE>: <func>"; skip a function after <TRIES> failed tries. At the end report a table (function, result, tries, note) and the final tools\match.py <FILE> line.
```

`<TRIES>`: 5 for small functions; for large ones use "3 distinct approaches,
then commit the best attempt under #ifdef NON_MATCHING with a
// NON_MATCHING: N of M instructions note".

## Follow-up brief (same session)

```text
Verified with match.py and merged. Your branch was reset to the merged result; keep working here, same commands and rules. Next, src/<FILE>.cpp, in order: <FUNCS>. One commit per MATCH ("<FILE>: <func>"), skip after <TRIES> failed tries, final table plus the tools\match.py <FILE> line.
```

## Coordinator loop

1. `tools/backlog.py --exclude <files other workers hold>` to pick a file.
2. Send the brief; wait for the worker's report.
3. `tools/merge_worker.sh <NAME>`: it re-runs `match.py` in the worker's
   worktree, cherry-picks only verified commits, requires `build/ok`, and
   resets the worker's branch.
4. Start a fresh agent session (OpenCode: `/new`) when its context passes
   about a third; long sessions skip more functions.
