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
#   --min N               smallest one (0): a worker for the big functions only
#   --names N             functions per batch (20)
#   --budget I            ... and at most about I instructions in all (0: no limit)
#   --tries T             tries before skipping a function (5)
#   --new                 fresh agent session (/new) and the first brief
#   --retry               second tries: only functions other workers skipped
#                         (backlog.py --retry); remembered
#   --no-merge            don't run merge_worker.sh first
#   --dry-run             print the brief instead of sending it (no merge)
#   --watch               then run watch_agent.sh; exits with its code
#   --loop                --watch, then start over (merge, next batch, ...) until
#                         something needs the coordinator: a failed merge or
#                         build, a content-filter or unknown stop, a batch with
#                         no match, or no functions left. A quota stop whose
#                         screen gives the reset time (within 8 h) is waited
#                         out, or, with a reserve model (RESERVE in <name>.env,
#                         see tools/orca/switch_model.sh), worked through on
#                         it until the main model (PRIMARY) resets.
#                         A fresh session starts when a batch leaves 8 or
#                         more skipped, when the agent's context passes 60 %,
#                         or every 4 batches when its screen shows no context.
#                         A --retry loop stops after 2 batches in a row with no
#                         commit. Files are chosen by expected yield
#                         (backlog.py --by-yield).
#                         Exit codes: watch_agent.sh's, 1 failure, 6 no match.
#
# State lives in build/workers/ (not in git): <name>.env (handle, marker,
# file, last batch, its model and start, last status, loop options),
# skipped.txt, the functions a worker gave up on ("<file> <function>
# <worker>"), which backlog.py leaves out, and stats.tsv, one line per batch
# (time, worker, model, file, functions sent, commits merged, of them
# NON_MATCHING, bytes gained, minutes). After a merge, a function of the last
# batch counts as skipped when the worker tried it (tools/work.py's scratch
# file or build/work/.tried) and it is still asm. The briefs are the text
# blocks of docs/WORKER_BRIEF.md.
#
# Merges use merge_worker.sh --defer (the full build runs after the worker
# has its next batch); build/workers/BUILD_FAILED stops every loop. Each run
# executes copies of this script and of the scripts it calls (in
# build/workers/run/), so editing them never breaks a running loop; a loop
# picks up the edits at its next round.
set -eu
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
cd "$MAIN"
PY="$MAIN/tools/.venv/Scripts/python.exe"; [ -x "$PY" ] || PY="$MAIN/tools/.venv/bin/python"
[ $# -ge 1 ] || { sed -n '5p' "$0" | sed 's/^# *//'; exit 2; }
NAME=$1; shift
RUN="$MAIN/build/workers/run"
if [ "${NB_COPY:-}" != "$NAME" ]; then
  mkdir -p "$RUN"; cp tools/orca/next_batch.sh "$RUN/next_batch.$NAME.sh"
  export NB_COPY="$NAME"; exec sh "$RUN/next_batch.$NAME.sh" "$NAME" "$@"
fi
runcopy() {   # $1: script under tools/, then its arguments
  s=$1; shift; c="$RUN/$(basename "$s" .sh).$NAME.sh"; cp "tools/$s" "$c"; sh "$c" "$@"
}
# For --loop's next round. --handle and --busy are left out (they are saved in
# <name>.env, and a busy marker has spaces); other values have none.
ARGS=""; drop=""
for a in "$@"; do
  if [ -n "$drop" ]; then drop=""; continue; fi
  case $a in --handle|--busy) drop=1 ;; *) ARGS="$ARGS $a" ;; esac
done
ST=build/workers; mkdir -p "$ST"; ENV="$ST/$NAME.env"; SKIP="$ST/skipped.txt"; touch "$SKIP"
STATS="$ST/stats.tsv"
HANDLE=""; BUSY=""; FILE=""; AVOID=""; BATCH=""; STATUS=""; RETRY=""; MODEL=""; SENT=""; LOOPARGS=""
ZERO=0; SINCE_NEW=0; AGENT=""; PRIMARY=""; RESERVE=""; ON_RESERVE=""
# shellcheck disable=SC1090
[ -f "$ENV" ] && . "./$ENV"
NEWFILE=""; MAX=30; MIN=0; NAMES=20; BUDGET=0; TRIES=5; NEW=""; MERGE=1; DRY=""; WATCH=""; LOOP=""; ROUND=""
while [ $# -gt 0 ]; do
  case $1 in
    --handle) HANDLE=$2; shift ;;
    --busy) BUSY=$2; shift ;;
    --file) NEWFILE=$2; shift ;;
    --avoid) AVOID=$2; [ "$AVOID" = - ] && AVOID=""; shift ;;
    --max) MAX=$2; shift ;;
    --min) MIN=$2; shift ;;
    --names) NAMES=$2; shift ;;
    --budget) BUDGET=$2; shift ;;
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
# The options a later `tools/orca/resume.sh` restarts the loop with.
[ -z "$LOOP" ] || LOOPARGS=$(echo " $ARGS " | sed -e 's/ --new / /g' -e 's/ --file [^ ]* / /g' -e 's/ --round / /g' -e 's/^ *//; s/ *$//')

save() {
  { echo "HANDLE='$HANDLE'"; echo "BUSY='$BUSY'"; echo "FILE='$FILE'"; echo "AVOID='$AVOID'"
    echo "BATCH='$BATCH'"; echo "STATUS='$STATUS'"; echo "RETRY='$RETRY'"; echo "MODEL='$MODEL'"
    echo "SENT='$SENT'"; echo "LOOPARGS='$LOOPARGS'"; echo "ZERO='$ZERO'"; echo "SINCE_NEW='$SINCE_NEW'"
    echo "AGENT='$AGENT'"; echo "PRIMARY='$PRIMARY'"; echo "RESERVE='$RESERVE'"; echo "ON_RESERVE='$ON_RESERVE'"; } > "$ENV"
}
# The agent's screen as JSON; Orca may be away for a minute (it updates
# itself), so a failed read is retried for 5 minutes. Empty if it never came.
screen() {
  for _ in 1 2 3 4 5 6 7 8 9 10; do
    j=$(orca terminal read --terminal "$HANDLE" --screen --json 2>/dev/null) && [ -n "$j" ] && { printf '%s' "$j"; return 0; }
    sleep 30
  done
}

[ -z "$DRY" ] || MERGE=""          # a dry run changes nothing
WT="$(dirname "$MAIN")/ror-wt-$NAME"

if [ -e "$ST/BUILD_FAILED" ]; then
  echo "stopped: $(cat "$ST/BUILD_FAILED")"; echo "(fix it, then delete $ST/BUILD_FAILED)"; exit 1
fi

# On the reserve model past the main one's reset: back to the main model.
if [ -z "$DRY" ] && [ -n "$ON_RESERVE" ] && [ "$(date +%s)" -ge "$ON_RESERVE" ] && [ -n "$PRIMARY" ]; then
  HANDLE=$(runcopy orca/switch_model.sh "$NAME" "$PRIMARY" | tail -1)
  ON_RESERVE=""; NEW=1; save
  echo "$NAME: the main model's quota is back: $PRIMARY"
fi

# A worker still busy gets nothing new (its TUI would queue the text).
if [ -z "$DRY" ]; then
  scr=$(screen)
  [ -n "$scr" ] || { echo "$NAME: cannot read its terminal $HANDLE (stale handle? tools/orca/resume.sh)"; exit 5; }
  if printf '%s' "$scr" | grep -qE "$BUSY"; then echo "$NAME is still working; nothing sent"; exit 1; fi
fi

# 1. Merge. A failure (a mismatch, a broken build) stops here.
STATE="Your last commits were not merged yet; keep your branch as it is."
H0=$(git rev-parse HEAD); out=""
if [ -n "$MERGE" ]; then
  out=$(runcopy merge_worker.sh "$NAME" --defer) || { echo "$out"; exit 1; }
  echo "$out"
  case $out in
    *"reset to"*) STATE="Verified with match.py and merged; your branch was reset to the merged result." ;;
    *"nothing new"*) STATE="Nothing new to merge from your branch." ;;
    *merged*) STATE="Verified with match.py and merged; your branch was left as it is (commit any uncommitted work)." ;;
  esac
fi

# 2. The last batch: its line in stats.tsv, and what it left skipped.
# Skipped = checked by the worker at least twice with a compiling version
# (tools/work.py logs each in build/work/.tried, apart from the scratch
# files workers delete) and still in asm here. Functions it did not really
# try come back in a later batch, and so does all of a batch the quota cut.
if [ -n "$BATCH" ] && [ -n "$FILE" ] && [ -n "$MERGE" ]; then
  subj=$(git log --format=%s "$H0..HEAD")
  ncommit=$(printf '%s' "$subj" | grep -c . || true)
  nnm=$(printf '%s' "$subj" | grep -c 'NON_MATCHING' || true)
  bytes=$(echo "$out" | sed -n 's/.*progress \([0-9,]*\) B.* -> \([0-9,]*\) B.*/\1 \2/p' | tr -d , |
          awk '{print $2 - $1}')
  mins=""; [ -z "$SENT" ] || mins=$(( ($(date +%s) - SENT) / 60 ))
  nsent=$(echo "$BATCH" | tr ',' '\n' | grep -c . || true)
  [ -e "$STATS" ] || printf 'time\tworker\tmodel\tfile\tsent\tmerged\tnon_matching\tbytes\tminutes\n' > "$STATS"
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$(date '+%F %H:%M')" "$NAME" "$MODEL" "$FILE" \
    "$nsent" "$ncommit" "$nnm" "${bytes:-0}" "$mins" >> "$STATS"
  n=0
  [ "$STATUS" != quota ] || BATCH=""
  for f in $(echo "$BATCH" | tr ',' ' '); do
    if [ "$( (grep -cE "^$FILE $f( |$)" "$WT/build/work/.tried" 2>/dev/null || echo 0) | head -1)" -ge 2 ] &&
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
  # A loop whose worker merged nothing at all is stuck somehow; a retry
  # loop gets two batches (a batch cut off by the quota is no sign either).
  if [ "$ncommit" = 0 ] && [ "$STATUS" != quota ]; then ZERO=$((ZERO + 1)); else ZERO=0; fi
  save
  if [ -n "$ROUND" ] && { { [ -z "$RETRY" ] && [ "$ZERO" -ge 1 ]; } || [ "$ZERO" -ge 2 ]; }; then
    echo "$NAME: nothing merged from its last $ZERO batch(es); loop stopped"; exit 6
  fi
fi

# 3. Pick the file and the functions.
others=$(for e in "$ST"/*.env; do
  [ -e "$e" ] && [ "$e" != "$ENV" ] && sed -n "s/^FILE='\(.*\)'$/\1/p" "$e"; done | paste -sd, -)
[ -n "$NEWFILE" ] && FILE=$NEWFILE
funcs=""
R=${RETRY:+--retry $NAME}
# shellcheck disable=SC2086
[ -n "$FILE" ] && funcs=$("$PY" tools/backlog.py $R --file "$FILE" --min "$MIN" --max "$MAX" --names "$NAMES" --budget "$BUDGET")
if [ -z "$funcs" ]; then
  [ -z "$NEWFILE" ] || { echo "$NEWFILE has no functions of up to $MAX instructions left"; exit 1; }
  # shellcheck disable=SC2086
  FILE=$("$PY" tools/backlog.py $R --by-yield --min "$MIN" --max "$MAX" --top 200 --exclude "${others:-}${FILE:+,$FILE}" |
         awk 'NF == 5 && $2 == "functions" {print $5}' |
         { if [ -n "$AVOID" ]; then grep -v "^$AVOID" || true; else cat; fi; } | head -1)
  [ -n "$FILE" ] || { echo "no file left with functions of up to $MAX instructions"; exit 1; }
  # shellcheck disable=SC2086
  funcs=$("$PY" tools/backlog.py $R --file "$FILE" --min "$MIN" --max "$MAX" --names "$NAMES" --budget "$BUDGET")
fi

# 4. The brief: the first one for a fresh session, the follow-up otherwise.
scr=$(screen)
ctx=$(printf '%s' "$scr" | "$PY" tools/orca/screen.py context)
if [ -z "$NEW" ] && [ -n "$ctx" ] && [ "$ctx" -ge 60 ]; then
  NEW=1; echo "  context at $ctx %: this batch starts a fresh session"
elif [ -z "$NEW" ] && [ -z "$ctx" ] && [ "$SINCE_NEW" -ge 4 ]; then
  NEW=1; echo "  4 batches in this session (its context is not on screen): this one starts a fresh session"
fi
if [ -n "$NEW" ]; then SINCE_NEW=1; else SINCE_NEW=$((SINCE_NEW + 1)); fi
brief() {   # $1: section heading in WORKER_BRIEF.md
  awk -v h="$1" '$0 == h {f = 1; next} f && /^```text/ {t = 1; next} t && /^```/ {exit} t' docs/WORKER_BRIEF.md
}
if [ -n "$NEW" ]; then text=$(brief "## First brief (fresh session)"); else text=$(brief "## Follow-up brief (same session)"); fi
[ -n "$text" ] || { echo "no brief text found in docs/WORKER_BRIEF.md"; exit 1; }
text=$(printf '%s' "$text" | sed -e "s|<STATE>|$STATE|g" -e "s|<NAME>|$NAME|g" -e "s|<FILE>|$FILE|g" -e "s|<FUNCS>|$funcs|g" -e "s|<TRIES>|$TRIES|g")

echo "$NAME -> $FILE: $funcs"
if [ -n "$DRY" ]; then echo "$text"; exit 0; fi
# Codex's /new opens the new chat in a checkout of its own (~/.codex/
# worktrees/), not in the worker's worktree: its fresh session is a new
# agent in the same terminal place instead.
if [ -n "$NEW" ] && [ "$AGENT" = codex ]; then
  orca terminal close --terminal "$HANDLE" --json >/dev/null 2>&1 || true
  wtpath=$(cygpath -m "$WT" 2>/dev/null || echo "$WT")
  HANDLE=$(cd "$WT" && orca agent launch --agent codex --worktree "path:$wtpath" --surface terminal --json |
           sed -n 's/.*"handle": "\(term_[^"]*\)".*/\1/p' | head -1)
  [ -n "$HANDLE" ] || { echo "$NAME: relaunching Codex failed"; exit 1; }
  i=0; until screen | grep -q "GPT-"; do i=$((i + 1)); [ $i -lt 40 ] || break; sleep 3; done
  save; NEW=""; echo "  fresh Codex session: $HANDLE"
fi
sent=""
for _ in 1 2 3; do
  if runcopy orca/send_brief.sh ${NEW:+--new} "$HANDLE" "$text"; then sent=1; break; fi
  sleep 60; NEW=""                   # a retry must not clear the session again
done
[ -n "$sent" ] || { echo "$NAME: the brief was not accepted (3 tries)"; exit 1; }
MODEL=$(printf '%s' "$scr" | "$PY" tools/orca/screen.py model)
BATCH=$funcs; STATUS=busy; SENT=$(date +%s); save

# 5. Wait for the report.
[ -n "$WATCH" ] || exit 0
set +e
runcopy orca/watch_agent.sh "$HANDLE" "$BUSY"; code=$?
set -e
case $code in 0) STATUS=idle ;; 3) STATUS=quota ;; 4) STATUS=filter ;; 7) STATUS=stuck ;; *) STATUS=unknown ;; esac
save
[ -n "$LOOP" ] || exit $code
again=""
if [ $code -eq 3 ]; then
  secs=$(screen | "$PY" tools/orca/screen.py wait)
  if [ -n "$RESERVE" ] && [ -z "$ON_RESERVE" ]; then
    # Out of quota on the main model: go on with the reserve one until the
    # main one resets (4 h if the screen does not say).
    ON_RESERVE=$(( $(date +%s) + ${secs:-14400} ))
    HANDLE=$(runcopy orca/switch_model.sh "$NAME" "$RESERVE" | tail -1)
    save
    echo "$NAME: out of quota; on the reserve model $RESERVE until $(date -d "@$ON_RESERVE" '+%H:%M' 2>/dev/null)"
  else
    # No reserve, or the reserve is out too: wait for the reset (the main
    # model's, if that comes first), when the screen says when it is.
    if [ -n "$ON_RESERVE" ]; then
      left=$(( ON_RESERVE - $(date +%s) )); [ "$left" -gt 0 ] || left=60
      [ -n "$secs" ] && [ "$secs" -lt "$left" ] || secs=$left
    fi
    [ -n "$secs" ] || { echo "$NAME: out of quota, no reset time on screen; loop stopped"; exit 3; }
    echo "$NAME: out of quota; waiting $((secs / 60)) min for the reset"
    sleep "$secs"
  fi
  again="--new"
elif [ $code -ne 0 ]; then
  exit $code
fi
# Next round with the same options, minus the one-shot ones, from a fresh copy.
next=$(echo " $ARGS " | sed -e 's/ --new / /g' -e 's/ --file [^ ]* / /g' -e 's/ --round / /g')
# shellcheck disable=SC2086
export NB_COPY=""; exec sh "$MAIN/tools/orca/next_batch.sh" "$NAME" $next $again --round
