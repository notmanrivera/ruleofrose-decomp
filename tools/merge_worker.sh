#!/bin/sh
# Take a worker's verified commits into the main checkout's branch.
#
#   tools/merge_worker.sh <name>          # worktree ../ror-wt-<name>, branch wt/<name>
#   tools/merge_worker.sh <name> --check  # verify only, change nothing
#   tools/merge_worker.sh <name> --defer  # full build after returning (see 3)
#
# 1. Lists the worker's commits not yet in the current branch (by patch, so
#    commits already cherry-picked are skipped) and refuses any that touch
#    something other than src/**.cpp.
# 2. Runs tools/match.py on every touched file inside the worker's worktree;
#    all must report a matching object (functions left as INCLUDE_ASM or
#    NON_MATCHING are fine, a mismatching compiled function is not).
# 3. Cherry-picks them, runs the full build and requires build/ok; on any
#    failure the branch goes back to where it was.
#    With --defer the build runs in the background after the reset (it keeps
#    the merge lock, so the next merge waits for it): the worker gets its next
#    batch at once instead of after the build. match.py already passed, so the
#    build rarely fails; when it does, build/workers/BUILD_FAILED says so and
#    tools/orca/next_batch.sh stops every worker until it is dealt with.
# 4. Resets the worker's branch to the result (only if its tree is clean),
#    and prints the progress before and after.
set -eu
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
[ $# -ge 1 ] || { sed -n '4,5p' "$0" | sed 's/^# *//'; exit 2; }
NAME="$1"; shift; CHECK=""; DEFER=""
for a in "$@"; do case $a in --check) CHECK=--check ;; --defer) DEFER=1 ;; *) echo "unknown option $a"; exit 2 ;; esac; done
WT="$(dirname "$MAIN")/ror-wt-$NAME"
PY="$MAIN/tools/.venv/Scripts/python.exe"
[ -x "$PY" ] || PY="$MAIN/tools/.venv/bin/python"
[ -d "$WT" ] || { echo "no worktree $WT"; exit 1; }
cd "$MAIN"
if [ "$CHECK" != "--check" ]; then
  # One merge+build at a time: two at once share build/, and a failing one's
  # reset would drop the other's cherry-picks.
  L="$MAIN/build/workers/merge.lock"; mkdir -p "$MAIN/build/workers"
  until mkdir "$L" 2>/dev/null; do sleep 10; done
  trap 'rmdir "$L"' EXIT INT TERM
fi
BRANCH="$(git branch --show-current)"
[ -z "$(git status --porcelain --untracked-files=no)" ] || { echo "$MAIN has uncommitted changes"; exit 1; }

progress() { "$PY" tools/progress.py | sed -n 2p | awk '{print $5, "B,", $8}'; }

# Unmerged commits, oldest first.
COMMITS="$(git cherry "$BRANCH" "wt/$NAME" | sed -n 's/^+ //p')"
if [ -z "$COMMITS" ]; then
  echo "wt/$NAME: nothing new"
else
  BAD="$(for c in $COMMITS; do git show --name-only --format= "$c"; done | sort -u | grep -v '^src/.*\.cpp$' || true)"
  [ -z "$BAD" ] || { echo "refusing: commits touch files outside src/*.cpp:"; echo "$BAD"; exit 1; }
  FILES="$(for c in $COMMITS; do git show --name-only --format= "$c"; done | sort -u | sed 's|^src/||; s|\.cpp$||')"
  echo "wt/$NAME: $(echo "$COMMITS" | wc -l | tr -d ' ') commits on: $(echo $FILES)"

  FAIL=0
  for f in $FILES; do
    if out="$(cd "$WT" && "$PY" tools/match.py "$f" 2>&1)"; then
      echo "  $f: $(echo "$out" | tail -1)"
    else
      FAIL=1; echo "  $f: MISMATCH"; echo "$out" | grep -vE ' (MATCH|asm)$' | tail -15
    fi
  done
  [ "$FAIL" = 0 ] || { echo "not merged"; exit 1; }
  [ "$CHECK" = "--check" ] && exit 0

  BEFORE="$(git rev-parse HEAD)"; P0="$(progress)"
  # shellcheck disable=SC2086
  git cherry-pick $COMMITS >/dev/null || { git cherry-pick --abort; echo "cherry-pick failed; nothing merged"; exit 1; }
  if [ -n "$DEFER" ]; then
    echo "merged (full build in the background); progress $P0 -> $(progress)"
  else
    rm -f build/ok
    if ! tools/dock ninja >build/ninja-merge.log 2>&1 || [ ! -e build/ok ]; then
      git reset -q --hard "$BEFORE"
      echo "full build failed (build/ninja-merge.log); merge undone"; exit 1
    fi
    echo "merged, build/ok; progress $P0 -> $(progress)"
  fi
fi

[ "$CHECK" = "--check" ] && exit 0
# Reset only when nothing would be lost: a clean tree and no commit that
# arrived while this ran.
if [ -n "$(git cherry "$BRANCH" "wt/$NAME" | grep '^+' || true)" ]; then
  echo "wt/$NAME has commits made meanwhile; left as is (run again)"
elif [ -z "$(git -C "$WT" status --porcelain --untracked-files=no)" ]; then
  git -C "$WT" reset -q --hard "$BRANCH"
  echo "wt/$NAME reset to $BRANCH"
else
  echo "wt/$NAME has uncommitted work; left as is"
fi

# The deferred build, holding the lock until it ends.
if [ -n "$DEFER" ] && [ -n "$COMMITS" ]; then
  trap - EXIT INT TERM
  (
    rm -f build/ok
    if ! tools/dock ninja >build/ninja-merge.log 2>&1 || [ ! -e build/ok ]; then
      echo "$(date '+%F %T') after merging wt/$NAME ($BEFORE..$(git rev-parse --short HEAD)): full build failed, see build/ninja-merge.log"         > build/workers/BUILD_FAILED
    fi
    rmdir "$L"
  ) </dev/null >/dev/null 2>&1 &
fi
