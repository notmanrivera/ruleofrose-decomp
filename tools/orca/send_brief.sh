#!/bin/sh
# Send a one-line brief to an agent's Orca terminal (Orca on Windows breaks
# multi-line prompts). With --new, first start a fresh agent session
# (OpenCode's /new); MSYS_NO_PATHCONV stops Git Bash from turning "/new"
# into a Windows path.
#
#   tools/orca/send_brief.sh [--new] <terminal-handle> "<brief>"
NEW=""; [ "$1" = "--new" ] && { NEW=1; shift; }
H=$1; TEXT=$2
[ -n "$H" ] && [ -n "$TEXT" ] || { sed -n '7p' "$0" | sed 's/^# *//'; exit 2; }
if [ -n "$NEW" ]; then
  MSYS_NO_PATHCONV=1 orca terminal send --terminal "$H" --text "/new" --json >/dev/null
  sleep 2; orca terminal send --terminal "$H" --enter --json >/dev/null; sleep 5
fi
TEXT=$(printf '%s' "$TEXT" | tr '\n' ' ')
orca terminal send --terminal "$H" --text "$TEXT" --enter --wait-submit 20 --json | grep -q '"accepted": true' &&
  echo "sent" || { echo "not accepted"; exit 1; }
