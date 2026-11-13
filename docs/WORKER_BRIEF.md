# Worker brief

The text a coordinator sends to a worker agent (see `DECOMPILING.md` §6).
Fill in `<NAME>`, `<FILE>` and `<FUNCS>`, and send it as **one line**: Orca
on Windows breaks multi-line prompts, and an agent's TUI submits at the
first newline. `<FUNCS>` comes from
`tools/backlog.py --file <FILE> --names 20`.

## First brief (fresh session)

```text
You work in this git worktree only: ror-wt-<NAME> (branch wt/<NAME>). Read docs/DECOMPILING.md sections 2, 3 and 6 first. Task: decompile functions of src/<FILE>.cpp (file argument <FILE>) so they compile to identical bytes. Commands (PowerShell, from the worktree root): $py = "..\ruleofrose-decomp-main\tools\.venv\Scripts\python.exe" ; & $py tools\match.py --server start ; & $py tools\work.py <FILE> <func> (check) ; & $py tools\work.py <FILE> <func> --done (only on MATCH). When work.py prints "twin:", the scratch file holds the C++ of an already matched function with the same instructions: start from it. Functions, in this order: <FUNCS>. Rules: edit only src/<FILE>.cpp (declare what you need locally; an asm("name") alias is fine when a prototype already exists with another signature; keep X__vfunc_NN placeholder names as the asm label); never commit asm/, build/, disc/ or any .s file; never push; commit on top of wt/<NAME> as it is (no reset, no rebase). One commit per MATCH with message "<FILE>: <func>"; skip a function after <TRIES> failed tries. At the end report a table (function, result, tries, note) and the final tools\match.py <FILE> line.
```

`<STATE>` (follow-up only) says what happened to its last commits; `tools/orca/next_batch.sh` fills it in from `merge_worker.sh`.

`<TRIES>`: 5 for small functions; for large ones use "3 distinct approaches,
then commit the best attempt under #ifdef NON_MATCHING with a
// NON_MATCHING: N of M instructions note".

## Follow-up brief (same session)

```text
<STATE> Keep working here, same commands and rules (start from the twin when work.py prints "twin:"). Next, src/<FILE>.cpp, in order: <FUNCS>. One commit per MATCH ("<FILE>: <func>"), skip after <TRIES> failed tries, final table plus the tools\match.py <FILE> line.
```

## Coordinator loop

One call does a whole step:

```sh
tools/orca/next_batch.sh <NAME> --watch     # one step, in the background
tools/orca/next_batch.sh <NAME> --loop      # step after step until something needs you
tools/orca/next_batch.sh <NAME> --retry --loop   # only second tries of functions others skipped
```

It merges the worker's verified commits (`tools/merge_worker.sh`), records
the functions of its last batch it left in asm as skipped
(`build/workers/skipped.txt`, which `tools/backlog.py` leaves out), keeps
the worker on its file while that file has functions left (else takes the
file with the most small functions no other worker holds), fills in the
follow-up brief and sends it (`tools/orca/send_brief.sh`), then waits for the
worker (`tools/orca/watch_agent.sh`). The first line of its output is
`STATUS: idle`, `quota` or `filter`; on the last two, stop giving that
worker work. The first time, give `--handle <terminal> --busy <marker>`
(remembered in `build/workers/<NAME>.env`); `--avoid mag/` keeps a worker
out of a module, `--file`, `--max`, `--names`, `--tries` override the
choice, `--new` starts a fresh agent session with the first brief, and
`--dry-run` only prints the brief.

By hand, the same steps are:

1. `tools/backlog.py --exclude <files other workers hold>` to pick a file.
2. Send the brief; wait for the worker's report.
3. `tools/merge_worker.sh <NAME>`: it re-runs `match.py` in the worker's
   worktree, cherry-picks only verified commits, requires `build/ok`, and
   resets the worker's branch.
4. Start a fresh agent session (OpenCode: `/new`) when its context passes
   about a third; long sessions skip more functions (`next_batch.sh` says so
   when a batch leaves 8 or more).
