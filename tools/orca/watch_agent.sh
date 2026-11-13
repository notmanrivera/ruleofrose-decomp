#!/bin/sh
# Wait until an agent's Orca terminal has really gone idle, then print its
# last screen lines (its report) and exit. Run it in the background and act
# on the exit.
#
#   tools/orca/watch_agent.sh <terminal-handle> <busy-marker-regex>
#
# The busy marker is what the agent's TUI shows while it works:
#   OpenCode: "esc interrupt"     Antigravity (Gemini/Claude): "esc to cancel"
# Handles come from `orca agent launch --json` (launch.outcome.handle) or
# `orca terminal list --json`.
#
# The first output line says why it stopped, and so does the exit code:
#   STATUS: idle (0)   STATUS: quota (3)   STATUS: filter (4)   STATUS: unknown (5)
# "quota" covers quota and rate-limit messages, "filter" a refusal by the
# model's content filter: don't send that worker more work until it's fixed.
H=$1; BUSY=$2
[ -n "$H" ] && [ -n "$BUSY" ] || { sed -n '6p' "$0" | sed 's/^# *//'; exit 2; }
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
PY="$MAIN/tools/.venv/Scripts/python.exe"; [ -x "$PY" ] || PY="$MAIN/tools/.venv/bin/python"
QUOTA='quota (reached|exceeded)|[Rr]ate.?limit|resets in [0-9]+h|(HTTP|status|error) 429|[Ii]nsufficient (balance|credits)|out of credits|[Uu]sage limit reached|Resets [0-9]+:[0-9]+'
FILTER='[Cc]ontent (filter|policy)|blocked by (safety|the filter)|SAFETY|[Rr]esponse was blocked|blocked by Gemini.s filters'
sleep 60
while :; do
  orca terminal wait --terminal "$H" --for tui-idle --timeout-ms 1800000 --json >/dev/null 2>&1
  sleep 30
  # "unknown" (a stale handle, Orca closed) is never read as a normal stop.
  # A failed read is retried for 10 minutes first: Orca updating itself takes
  # its CLI away for a minute or two while the agents keep running.
  scr=""
  for _ in 1 2 3 4 5 6 7 8 9 10; do
    scr=$(orca terminal read --terminal "$H" --screen --json 2>/dev/null |
          "$PY" -c "import sys,json; print('\n'.join(json.load(sys.stdin)['result']['terminal']['tail']))" 2>/dev/null) &&
      [ -n "$scr" ] && break
    scr=""; sleep 60
  done
  [ -n "$scr" ] || { echo "STATUS: unknown (could not read terminal $H)"; exit 5; }
  echo "$scr" | grep -qE "$BUSY" && continue
  last=$(echo "$scr" | grep -v '^\s*$' | tail -30 | cut -c1-170)
  # Only the last lines count: an old message higher up is not the reason.
  tail12=$(echo "$last" | tail -12)
  if echo "$tail12" | grep -qE "$QUOTA"; then st=quota; code=3
  elif echo "$tail12" | grep -qE "$FILTER"; then st=filter; code=4
  else st=idle; code=0; fi
  echo "STATUS: $st"
  echo "$last"
  exit $code
done
