#!/usr/bin/env bash
# Builds the shared Ghidra project from scratch, reproducibly:
#   1. regenerate symbols from the ELF (tools/ror_symbols.py)
#   2. import disc/SLUS_214.48 into ghidra/RuleOfRose.gpr
#   3. apply recovered symbols before analysis (seeds function starts)
#   4. run auto-analysis
#   5. tag functions with their original source files
#
# Usage: tools/ghidra_setup.sh [processor]
#   processor defaults to the Emotion Engine language if the
#   ghidra-emotionengine-reloaded extension is installed, else plain MIPS.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
ELF="$ROOT/disc/SLUS_214.48"
HEADLESS="${GHIDRA_HEADLESS:-$(command -v analyzeHeadless || echo /opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless)}"

# Homebrew's openjdk@21 is keg-only, so Ghidra can't find it on its own.
if [[ -z "${JAVA_HOME:-}" && -d /opt/homebrew/opt/openjdk@21 ]]; then
  export JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home
fi

[[ -f "$ELF" ]] || { echo "Missing $ELF (extract it from your own disc)"; exit 1; }

PROCESSOR="${1:-}"
if [[ -z "$PROCESSOR" ]]; then
  if find ~/Library/ghidra ~/.ghidra -path '*ghidra-emotionengine-reloaded*' -print -quit 2>/dev/null | grep -q .; then
    PROCESSOR="r5900:LE:32:default"
  else
    PROCESSOR="MIPS:LE:32:default"
    echo "Note: Emotion Engine extension not found, using plain MIPS."
  fi
fi

python3 "$ROOT/tools/ror_symbols.py" "$ELF"
mkdir -p "$ROOT/ghidra"

"$HEADLESS" "$ROOT/ghidra" RuleOfRose \
  -import "$ELF" -overwrite \
  -processor "$PROCESSOR" \
  -scriptPath "$ROOT/ghidra_scripts" \
  -preScript ImportRoRSymbols.java "$ROOT/symbols/ghidra_symbols.tsv" \
  -postScript TagSourceFiles.java "$ROOT/symbols/source_strings.tsv" \
  -log "$ROOT/ghidra/headless.log"
