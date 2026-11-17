#!/bin/sh
# Switch a worker's agent to another model (for next_batch.sh's reserve
# models). Prints the terminal handle to use from now on, last.
#
#   tools/orca/switch_model.sh <name> <model> [effort]
#
# build/workers/<name>.env says the agent (AGENT=opencode|antigravity) and
# its terminal (HANDLE).
#   opencode:    its model picker (ctrl+x m), the model searched by the name
#                it shows (e.g. "DeepSeek V4.1 Flash Free"), Enter.
#   antigravity: /model, the model searched by name (e.g. "Claude Sonnet
#                5.5"), effort set from the lowest (low=0 medium=1 high=2
#                xhigh=3 steps right), Enter; same session.
# The switch is checked on the status bar: on success the new handle is
# printed last; on failure (a model not in the plan, "Unavailable", "No
# models match") the picker is closed with Esc and the script exits 1
# without a handle, so a caller never types into an open picker.
set -eu
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
cd "$MAIN"
PY="$MAIN/tools/.venv/Scripts/python.exe"; [ -x "$PY" ] || PY="$MAIN/tools/.venv/bin/python"
NAME=$1; WANT=$2; EFFORT=${3:-high}
ENV=build/workers/$NAME.env
HANDLE=""; AGENT=""
# shellcheck disable=SC1090
. "./$ENV"
[ -n "$AGENT" ] && [ -n "$HANDLE" ] || { echo "$ENV needs AGENT and HANDLE"; exit 2; }
export MSYS_NO_PATHCONV=1
send() { orca terminal send --terminal "$HANDLE" --text "$1" --json >/dev/null; sleep "${2:-1}"; }
status_bar() { orca terminal read --terminal "$HANDLE" 2>/dev/null | grep -v '^[[:space:]]*$' | tail -2; }
picker_open() { orca terminal read --terminal "$HANDLE" 2>/dev/null | tail -15 |
                grep -qE "Switch Model|No models match|Unavailable|Keyboard: .*(Navigate|Clear search|Go Back)"; }
model_on_screen() { orca terminal read --terminal "$HANDLE" --screen --json 2>/dev/null | "$PY" tools/orca/screen.py model; }

case $AGENT in
  opencode)
    # Its model picker (ctrl+x m), searched by the name it shows, Enter.
    # The model is taken at once; a "Select variant" dialog may follow (a
    # moment later) and is closed with Esc (Enter there can pick a variant
    # of the old model). Checked on the status bar, one retry.
    for _ in 1 2; do
      send "$(printf '\030')"; send "m" 2; send "$WANT" 2; send "$(printf '\r')" 3
      for _ in 1 2 3; do
        orca terminal read --terminal "$HANDLE" --screen --json 2>/dev/null | grep -q "Select variant" || break
        send "$(printf '\033')" 2
      done
      # Exact: searching "GLM-5.3" puts "GLM-5.3-Flash Free" first.
      [ "$(model_on_screen)" = "$WANT" ] && break
      send "$(printf '\033')" 1
    done
    ;;
  antigravity)
    case $EFFORT in low) steps=0 ;; medium) steps=1 ;; xhigh) steps=3 ;; *) steps=2 ;; esac
    send "$(printf '\025')"                # clear the input line
    send "/model" 2; send "$(printf '\r')" 3; send "$WANT" 2
    for _ in 1 2 3 4; do send "$(printf '\033[D')"; done
    i=0; while [ $i -lt $steps ]; do send "$(printf '\033[C')"; i=$((i + 1)); done
    send "$(printf '\r')" 3
    if picker_open; then
      send "$(printf '\033')" 1; send "$(printf '\033')" 1
      echo "$NAME: cannot switch to $WANT (not offered, or unavailable on this plan)"; exit 1
    fi
    status_bar | grep -qF "$WANT" || { echo "$NAME: switched, but the status bar does not show $WANT"; exit 1; }
    ;;
  *) echo "unknown AGENT=$AGENT"; exit 2 ;;
esac
if [ "$AGENT" = opencode ] && [ "$(model_on_screen)" != "$WANT" ]; then
  send "$(printf '\033')" 1
  echo "$NAME: cannot switch to $WANT (the status bar shows $(model_on_screen))"; exit 1
fi
sed -i "s/^HANDLE=.*/HANDLE='$HANDLE'/" "$ENV"
echo "$NAME: now $(model_on_screen)"
echo "$HANDLE"
