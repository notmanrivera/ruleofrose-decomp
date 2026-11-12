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
H=$1; BUSY=$2
[ -n "$H" ] && [ -n "$BUSY" ] || { sed -n '6p' "$0" | sed 's/^# *//'; exit 2; }
sleep 60
while :; do
  orca terminal wait --terminal "$H" --for tui-idle --timeout-ms 1800000 --json >/dev/null 2>&1
  sleep 30
  scr=$(orca terminal read --terminal "$H" --screen --json 2>/dev/null |
        python -c "import sys,json; print('\n'.join(json.load(sys.stdin)['result']['terminal']['tail']))")
  echo "$scr" | grep -qE "$BUSY" && continue
  echo "$scr" | grep -v '^\s*$' | tail -30 | cut -c1-170
  exit 0
done
