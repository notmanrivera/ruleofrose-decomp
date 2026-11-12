#!/bin/sh
# One coordinator step for a worker: merge what it finished, pick its next
# batch, send the brief, and (with --watch) wait for it to finish.
#
#   tools/orca/next_batch.sh <name> [options]
#
#   --handle H --busy RE  its Orca terminal and busy marker (see watch_agent.sh);
#                         needed the first time, then remembered
#   --file F              work on this file (default: keep the current file
#                         while it has functions left, else take the file with
#                         the most small functions that no other worker holds)
#   --avoid P             never pick a file under this prefix (e.g. mag/;
#                         remembered; --avoid - clears it)
#   --max N               largest function handed out, in instructions (30)
#   --names N             functions per batch (20)
#   --tries T             tries before skipping a function (5)
#   --new                 fresh agent session (OpenCode /new) and the first brief
#   --retry               second tries: only functions other workers skipped
#                         (backlog.py --retry); remembered
#   --no-merge            don't run merge_worker.sh first
#   --dry-run             print the brief instead of sending it (no merge)
#   --watch               then run watch_agent.sh; exits with its code
#   --loop                --watch, then start over (merge, next batch, ...) until
#                         something needs the coordinator: a failed merge or
#                         build, a worker stop other than idle, a batch with no
#                         match, or no functions left. A batch that leaves 8 or
#                         more skipped makes the next one start a fresh session.
#                         Exit codes: watch_agent.sh's, 1 failure, 6 no match.
#
# State lives in build/workers/ (not in git): <name>.env (handle, marker,
# file, last batch, last status) and skipped.txt, the functions a worker gave
# up on ("<file> <function> <worker>"), which backlog.py leaves out. After a
# merge, a function of the last batch counts as skipped when the worker tried
# it (tools/work.py's scratch file is in its build/work/) and it is still asm.
# The briefs are the text blocks of docs/WORKER_BRIEF.md.
set -eu
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
cd "$MAIN"
PY="$MAIN/tools/.venv/Scripts/python.exe"; [ -x "$PY" ] || PY="$MAIN/tools/.venv/bin/python"
[ $# -ge 1 ] || { sed -n '5p' "$0" | sed 's/^# *//'; exit 2; }
NAME=$1; shift
ARGS="$*"                          # for --loop's next round (no spaces in values)
ST=build/workers; mkdir -p "$ST"; ENV="$ST/$NAME.env"; SKIP="$ST/skipped.txt"; touch "$SKIP"
HANDLE=""; BUSY=""; FILE=""; AVOID=""; BATCH=""; STATUS=""; RETRY=""
# shellcheck disable=SC1090
[ -f "$ENV" ] && . "./$ENV"
NEWFILE=""; MAX=30; NAMES=20; TRIES=5; NEW=""; MERGE=1; DRY=""; WATCH=""; LOOP=""; ROUND=""
while [ $# -gt 0 ]; do
  case $1 in
    --handle) HANDLE=$2; shift ;;
    --busy) BUSY=$2; shift ;;
    --file) NEWFILE=$2; shift ;;
    --avoid) AVOID=$2; [ "$AVOID" = - ] && AVOID=""; shift ;;
    --max) MAX=$2; shift ;;
    --names) NAMES=$2; shift ;;
    --tries) TRIES=$2; shift ;;
    --new) NEW=1 ;;
    --retry) RETRY=1 ;;
    --no-merge) MERGE="" ;;
    --dry-run) DRY=1 ;;
    --watch) WATCH=1 ;;
    --loop) WATCH=1; LOOP=1 ;;
    --round) ROUND=1 ;;              # internal: a --loop round after the first
    *) echo "unknown option $1"; exit 2 ;;
  esac; shift
done
[ -n "$HANDLE" ] && [ -n "$BUSY" ] || { echo "$NAME: give --handle and --busy once"; exit 2; }

save() {
  { echo "HANDLE='$HANDLE'"; echo "BUSY='$BUSY'"; echo "FILE='$FILE'"; echo "AVOID='$AVOID'"
    echo "BATCH='$BATCH'"; echo "STATUS='$STATUS'"; echo "RETRY='$RETRY'"; } > "$ENV"
}

[ -z "$DRY" ] || MERGE=""          # a dry run changes nothing
WT="$(dirname "$MAIN")/ror-wt-$NAME"

# A worker still busy gets nothing new (its TUI would queue the text).
if [ -z "$DRY" ] && orca terminal read --terminal "$HANDLE" --screen --json 2>/dev/null | grep -qE "$BUSY"; then
  echo "$NAME is still working; nothing sent"; exit 1
fi

# 1. Merge. A failure (a mismatch, a broken build) stops here.
STATE="Your last commits were not merged yet; keep your branch as it is."
if [ -n "$MERGE" ]; then
  out=$(sh tools/merge_worker.sh "$NAME") || { echo "$out"; exit 1; }
  echo "$out"
  case $out in
    *"reset to"*) STATE="Verified with match.py and merged; your branch was reset to the merged result." ;;
    *"nothing new"*) STATE="Nothing new to merge from your branch."
      if [ -n "$ROUND" ] && [ -z "$RETRY" ]; then echo "$NAME: no match in its last batch; loop stopped"; exit 6; fi ;;
    *merged*) STATE="Verified with match.py and merged; your branch was left as it is (commit any uncommitted work)." ;;
  esac
fi

# 2. Skipped = tried by the worker (tools/work.py left its scratch file in
# the worktree's build/work/, or logged it in build/work/.tried, which
# survives a worker deleting its scratch files) and still in asm here. Untried functions of
# the batch are not skipped; they simply come back in a later batch.
if [ -n "$BATCH" ] && [ -n "$FILE" ] && [ -n "$MERGE" ]; then
  n=0
  for f in $(echo "$BATCH" | tr ',' ' '); do
    if { [ -e "$WT/build/work/$FILE/$f.cpp" ] || [ -e "$WT/build/work/$FILE/$f.trial.cpp" ] ||
         grep -qx "$FILE $f" "$WT/build/work/.tried" 2>/dev/null; } &&
       grep -qE "INCLUDE_ASM\(\"[^\"]+\", *$f\)" "src/$FILE.cpp" &&
       ! grep -q "^$FILE $f${RETRY:+ $NAME}\b" "$SKIP"; then
      echo "$FILE $f $NAME" >> "$SKIP"; n=$((n + 1))
    fi
  done
  [ $n -eq 0 ] || echo "$NAME skipped $n of its last batch (now in $SKIP)"
  if [ $n -ge 8 ]; then
    if [ -n "$LOOP" ]; then NEW=1; echo "  that is a lot: the next batch starts a fresh session"
    else echo "  that is a lot: start a fresh session (--new) for the next batch"; fi
  fi
  BATCH=""
fi

# 3. Pick the file and the functions.
others=$(for e in "$ST"/*.env; do
  [ -e "$e" ] && [ "$e" != "$ENV" ] && sed -n "s/^FILE='\(.*\)'$/\1/p" "$e"; done | paste -sd, -)
[ -n "$NEWFILE" ] && FILE=$NEWFILE
funcs=""
R=${RETRY:+--retry $NAME}
# shellcheck disable=SC2086
[ -n "$FILE" ] && funcs=$("$PY" tools/backlog.py $R --file "$FILE" --max "$MAX" --names "$NAMES")
if [ -z "$funcs" ]; then
  [ -z "$NEWFILE" ] || { echo "$NEWFILE has no functions of up to $MAX instructions left"; exit 1; }
  # shellcheck disable=SC2086
  FILE=$("$PY" tools/backlog.py $R --max "$MAX" --top 200 --exclude "${others:-}${FILE:+,$FILE}" |
         awk 'NF == 5 && $2 == "functions" {print $5}' |
         { if [ -n "$AVOID" ]; then grep -v "^$AVOID" || true; else cat; fi; } | head -1)
  [ -n "$FILE" ] || { echo "no file left with functions of up to $MAX instructions"; exit 1; }
  # shellcheck disable=SC2086
  funcs=$("$PY" tools/backlog.py $R --file "$FILE" --max "$MAX" --names "$NAMES")
fi

# 4. The brief: the first one for a fresh session, the follow-up otherwise.
brief() {   # $1: section heading in WORKER_BRIEF.md
  awk -v h="$1" '$0 == h {f = 1; next} f && /^```text/ {t = 1; next} t && /^```/ {exit} t' docs/WORKER_BRIEF.md
}
if [ -n "$NEW" ]; then text=$(brief "## First brief (fresh session)"); else text=$(brief "## Follow-up brief (same session)"); fi
[ -n "$text" ] || { echo "no brief text found in docs/WORKER_BRIEF.md"; exit 1; }
text=$(printf '%s' "$text" | sed -e "s|<STATE>|$STATE|g" -e "s|<NAME>|$NAME|g" -e "s|<FILE>|$FILE|g" -e "s|<FUNCS>|$funcs|g" -e "s|<TRIES>|$TRIES|g")

echo "$NAME -> $FILE: $funcs"
if [ -n "$DRY" ]; then echo "$text"; exit 0; fi
sh tools/orca/send_brief.sh ${NEW:+--new} "$HANDLE" "$text"
BATCH=$funcs; STATUS=busy; save

# 5. Wait for the report.
[ -n "$WATCH" ] || exit 0
set +e
sh tools/orca/watch_agent.sh "$HANDLE" "$BUSY"; code=$?
set -e
case $code in 0) STATUS=idle ;; 3) STATUS=quota ;; 4) STATUS=filter ;; *) STATUS=unknown ;; esac
save
if [ -n "$LOOP" ] && [ $code -eq 0 ]; then
  # Next round with the same options, minus the one-shot ones.
  next=$(echo " $ARGS " | sed -e 's/ --new / /g' -e 's/ --file [^ ]* / /g' -e 's/ --round / /g')
  # shellcheck disable=SC2086
  exec sh "$0" "$NAME" $next --round
fi
exit $code
