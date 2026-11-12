#!/bin/sh
# A git worktree ready for one worker agent: its own branch, the ELF, a
# configured and verified build (build/ok), and its own match.py server.
#
#   tools/new_worktree.sh <name> [<base>]   # ../ror-wt-<name> on wt/<name>
#   tools/new_worktree.sh --remove <name>   # worktree, merged branch, server
#
# <base> defaults to the main checkout's current branch. The worktree has no
# tools/.venv; run the main checkout's interpreter, which is fine because the
# tools find the repo from their own path:
#   ../<main>/tools/.venv/Scripts/python.exe tools/work.py <file> <func>
# Logs: <worktree>/build/configure.log and build/ninja.log.
set -eu
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
DOCKER="$(command -v docker || echo "$HOME/.docker/bin/docker")"
[ -x "$DOCKER" ] || DOCKER="/c/Program Files/Docker/Docker/resources/bin/docker.exe"

usage() { sed -n '5,6p' "$0" | sed 's/^# *//'; exit 2; }
[ $# -ge 1 ] || usage

if [ "$1" = "--remove" ]; then
  [ $# -eq 2 ] || usage
  WT="$(dirname "$MAIN")/ror-wt-$2"
  git -C "$MAIN" worktree remove --force "$WT"
  # -d, not -D: a branch with work not yet in another branch stays.
  git -C "$MAIN" branch -d "wt/$2" || echo "kept branch wt/$2 (not merged); git branch -D wt/$2 drops it"
  "$DOCKER" rm -f "ror-match-ror-wt-$2" >/dev/null 2>&1 || true
  echo "removed $WT"
  exit 0
fi

NAME="$1"
BASE="${2:-$(git -C "$MAIN" branch --show-current)}"
WT="$(dirname "$MAIN")/ror-wt-$NAME"
[ -e "$WT" ] && { echo "$WT already exists"; exit 1; }
[ -f "$MAIN/disc/SLUS_214.48" ] || { echo "no $MAIN/disc/SLUS_214.48"; exit 1; }
"$DOCKER" info >/dev/null 2>&1 || { echo "the docker engine is not running"; exit 1; }

git -C "$MAIN" worktree add "$WT" -b "wt/$NAME" "$BASE"
mkdir -p "$WT/disc" "$WT/build"
cp "$MAIN/disc/SLUS_214.48" "$WT/disc/"
[ -f "$MAIN/disc/SYSTEM.CNF" ] && cp "$MAIN/disc/SYSTEM.CNF" "$WT/disc/"

cd "$WT"
echo "configure (log: build/configure.log)"
# configure.py may clear build/, so log outside it first.
tools/dock python3 tools/configure.py >configure.log 2>&1 || { tail -20 configure.log; exit 1; }
mkdir -p build && mv configure.log build/
echo "ninja (log: build/ninja.log)"
tools/dock ninja >build/ninja.log 2>&1 || { tail -20 build/ninja.log; exit 1; }
[ -e build/ok ] || { echo "no build/ok: the build does not match"; exit 1; }
echo "ready: $WT (branch wt/$NAME from $BASE, build/ok)"
