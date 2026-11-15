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
      model_on_screen | grep -qF "$WANT" && break
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
    ;;
  *) echo "unknown AGENT=$AGENT"; exit 2 ;;
esac
sed -i "s/^HANDLE=.*/HANDLE='$HANDLE'/" "$ENV"
echo "$NAME: now $(model_on_screen)"
echo "$HANDLE"
