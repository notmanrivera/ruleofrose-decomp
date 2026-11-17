#!/bin/sh
# Fill new twins after a merge, with no model: tools/twin_fill.py in its own
# worktree (../ror-wt-twin, made by tools/new_worktree.sh twin), then
# tools/merge_worker.sh twin, which verifies each one again.
#
#   tools/orca/twin_sweep.sh        # what merge_worker.sh runs after a merge
#
# One sweep at a time: a sweep asked for while one runs leaves a mark, and
# the running one goes round again when it ends (a merge may have made new
# twins meanwhile). Log: build/workers/twin-sweep.log (tools/orca/bars.py).
set -u
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
cd "$MAIN"
PY="$MAIN/tools/.venv/Scripts/python.exe"; [ -x "$PY" ] || PY="$MAIN/tools/.venv/bin/python"
ST=build/workers
WT="$(dirname "$MAIN")/ror-wt-twin"
LOG=$ST/twin-sweep.log
[ -d "$WT" ] || { echo "no $WT (tools/new_worktree.sh twin)" >> "$LOG"; exit 1; }
[ -e "$ST/BUILD_FAILED" ] && exit 1

if ! mkdir "$ST/twin.lock" 2>/dev/null; then
  touch "$ST/twin.again"; exit 0
fi
trap 'rm -rf "$ST/twin.lock"' EXIT INT TERM
BRANCH=$(git branch --show-current)
while :; do
  rm -f "$ST/twin.again"
  # wait for a merge going on (its deferred build holds merge.lock)
  i=0; while [ -d "$ST/merge.lock" ] && [ $i -lt 240 ]; do sleep 5; i=$((i + 1)); done
  echo "== $(date '+%F %T') sweep" >> "$LOG"
  git -C "$WT" status --porcelain --untracked-files=no | grep -q . || git -C "$WT" reset -q --hard "$BRANCH"
  (cd "$WT" && "$PY" tools/twin_fill.py) >> "$LOG" 2>&1
  if [ -n "$(git -C "$WT" log --oneline "$BRANCH..HEAD")" ]; then
    sh tools/merge_worker.sh twin >> "$LOG" 2>&1
  fi
  [ -e "$ST/twin.again" ] || break
done
echo "== $(date '+%F %T') done" >> "$LOG"
