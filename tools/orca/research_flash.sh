#!/bin/sh
# Run one notes/RESEARCH_QUEUE.md item with a cheap model, read-only, for
# survey-type questions (scans, classifications, reading other projects'
# docs); the coordinator checks the report before anything is applied.
#
#   tools/orca/research_flash.sh R9 [model]
#
# It runs `opencode run` non-interactively in ../ror-wt-perm (an idle
# worktree, reset to the main branch first), so it can never touch the main
# checkout; any change it leaves there is reported and thrown away. The
# report goes to build/workers/research-<item>.md. Model: the free DeepSeek
# V4.1 Flash by default (its own daily limit, not OpenCode Go's).
set -eu
MAIN="$(cd "$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/.." && pwd)"
ITEM=$1; MODEL=${2:-opencode/deepseek-v4.1-flash-free}
WT="$(dirname "$MAIN")/ror-wt-perm"
OUT="$MAIN/build/workers/research-$ITEM.md"
text=$(awk -v id="$ITEM" 'index($0, "- [ ] " id " ") == 1 {f = 1; print; next} f && index($0, "- [") == 1 {exit} f' "$MAIN/notes/RESEARCH_QUEUE.md")
[ -n "$text" ] || { echo "no open item $ITEM in notes/RESEARCH_QUEUE.md"; exit 1; }
git -C "$WT" reset -q --hard "$(git -C "$MAIN" branch --show-current)"
prompt="Research task, READ-ONLY: do not edit, create or delete any file, do not commit, do not run builds or configure.py; only read files and run read-only commands (grep, git log/show, python scripts that only print). Repo: a matching decompilation of Rule of Rose (PS2, ee-gcc 2.96, C++); read CLAUDE.md and docs/DECOMPILING.md first. The question, from notes/RESEARCH_QUEUE.md: $(printf '%s' "$text" | tr '\n' ' ') Answer in English, under 500 words: findings with evidence (file:line or addresses), what you could not settle, and your confidence (high/medium/low)."
(cd "$WT" && timeout 3600 opencode run -m "$MODEL" "$prompt") > "$OUT" 2>&1 || true
if [ -n "$(git -C "$WT" status --porcelain)" ]; then
  echo "WARNING: the research run changed files in $WT (discarded):" >> "$OUT"
  git -C "$WT" status --porcelain >> "$OUT"
  git -C "$WT" reset -q --hard; git -C "$WT" clean -qfd
fi
echo "report: $OUT ($(wc -l < "$OUT") lines)"
