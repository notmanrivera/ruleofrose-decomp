#!/bin/sh
# Get the worker setup going again after a pause, a reboot or a power cut.
#
#   tools/orca/resume.sh            # check and repair; print the loop commands
#   tools/orca/resume.sh --start    # and start the loops (logs in build/workers/<name>-loop.log)
#
# 1. Docker: started (Windows: Docker Desktop) and waited for.
# 2. A merge left half done: a merge.lock with no merge running is removed,
#    and without build/ok the full build runs again (it must pass).
# 3. The compile server (tools/match.py --server start), and m2c's context
#    (tools/m2c_context/*.c included) copied to every worktree.
# 4. Each worker with a build/workers/<name>.env: its terminal handle is
#    looked up again by worktree in `orca terminal list` (Orca gives new
#    handles after a restart) and saved.
# 5. Its loop command, from the options it last ran with (LOOPARGS), with
#    --new: printed, or started in the background with --start.
set -eu
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
cd "$MAIN"
PY="$MAIN/tools/.venv/Scripts/python.exe"; [ -x "$PY" ] || PY="$MAIN/tools/.venv/bin/python"
START=""; [ "${1:-}" = "--start" ] && START=1
ST=build/workers

# 1. Docker.
if ! docker info >/dev/null 2>&1; then
  D="/c/Program Files/Docker/Docker/Docker Desktop.exe"
  if [ -x "$D" ]; then echo "starting Docker Desktop"; "$D" >/dev/null 2>&1 & else echo "start Docker, then run this again"; exit 1; fi
  i=0; until docker info >/dev/null 2>&1; do i=$((i + 1)); [ $i -lt 60 ] || { echo "Docker did not come up"; exit 1; }; sleep 5; done
fi
echo "docker: up"

# 2. A half-done merge.
if [ -d "$ST/merge.lock" ] && ! ps -ef | grep -q "[m]erge_worker"; then
  rm -rf "$ST/merge.lock"; echo "removed a stale merge lock"
fi
if [ -e "$ST/BUILD_FAILED" ]; then echo "BUILD_FAILED: $(cat "$ST/BUILD_FAILED")"; exit 1; fi
if [ ! -e build/ok ]; then
  echo "no build/ok: full build (about 4 minutes)"
  tools/dock ninja >build/ninja-resume.log 2>&1 && [ -e build/ok ] || { echo "full build failed: build/ninja-resume.log"; exit 1; }
fi
echo "build: ok"

# 3. Compile server, and m2c's context (with tools/m2c_context/*.c) for
# every worktree.
"$PY" tools/match.py --server start | tail -1
"$PY" -c "import sys; sys.path.insert(0, 'tools'); import auto_m2c as a; a.write_context(a.signatures(1))"
for d in ../ror-wt-*/build/auto; do [ -d "$d" ] && cp build/auto/context.c build/auto/sigs.json "$d/"; done

# 4 and 5. Workers.
terms=$(orca terminal list --json 2>/dev/null | "$PY" -c '
import json, sys
for t in json.load(sys.stdin)["result"]["terminals"]:
    if t.get("agentIdentity") and t.get("connected"):
        print(t["worktreePath"].rstrip("/").split("/")[-1], t["handle"])')
for env in "$ST"/*.env; do
  [ -e "$env" ] || continue
  name=$(basename "$env" .env)
  h=$(echo "$terms" | awk -v w="ror-wt-$name" '$1 == w {print $2; exit}')
  if [ -z "$h" ]; then echo "$name: no agent terminal in ror-wt-$name (launch one: orca agent launch ...)"; continue; fi
  sed -i "s/^HANDLE=.*/HANDLE='$h'/" "$env"
  args=$(sed -n "s/^LOOPARGS='\(.*\)'$/\1/p" "$env")
  [ -n "$args" ] || args="--loop"
  cmd="sh tools/orca/next_batch.sh $name $args --new"
  if [ -n "$START" ]; then
    nohup sh -c "$cmd > $ST/$name-loop.log 2>&1" >/dev/null 2>&1 &
    echo "$name: started ($h): $cmd"
  else
    echo "$name: $h -> $cmd"
  fi
done
