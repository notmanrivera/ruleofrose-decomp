#!/bin/sh
# One-shot local setup after a reboot (Windows Git Bash; a Mac/Linux host can
# run it by hand too). Waits for the Docker engine, builds the ror-build
# image, runs the canonical configure and the full matching build, and logs
# everything to build/auto_setup.log (build/auto_setup.ok on success).
# Re-runnable: it skips whatever is already done.
set -u
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
mkdir -p build
LOG="$ROOT/build/auto_setup.log"

log() { echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*" >>"$LOG"; }

DOCKER="$(command -v docker || echo "$HOME/.docker/bin/docker")"
[ -x "$DOCKER" ] || DOCKER="/c/Program Files/Docker/Docker/resources/bin/docker.exe"
if [ ! -x "$DOCKER" ]; then
  log "docker CLI not found; nothing to do"
  exit 1
fi

# 1. Docker engine (start Docker Desktop if it is not running, then wait).
if ! "$DOCKER" info >/dev/null 2>&1; then
  log "docker engine is not up; launching Docker Desktop and waiting"
  DESKTOP="/c/Program Files/Docker/Docker/Docker Desktop.exe"
  [ -x "$DESKTOP" ] && "$DESKTOP" >/dev/null 2>&1 &
  i=0
  while [ "$i" -lt 180 ]; do
    "$DOCKER" info >/dev/null 2>&1 && break
    sleep 10
    i=$((i + 1))
  done
fi
if ! "$DOCKER" info >/dev/null 2>&1; then
  log "gave up waiting for the docker engine (30 min); leaving for a retry"
  exit 1
fi
log "docker engine is up"

# 2. The shared build image.
if "$DOCKER" image inspect ror-build >/dev/null 2>&1; then
  log "image ror-build already present"
else
  log "building image ror-build (first time: downloads the EE-GCC toolchains)"
  if ! "$DOCKER" build --platform linux/amd64 -t ror-build docker/ >>"$LOG" 2>&1; then
    log "docker build FAILED (see above)"
    exit 1
  fi
  log "image built"
fi

# 3. Canonical configure and full build inside the image.
if [ -f build/ok ]; then
  log "build/ok already exists: nothing to do"
  touch build/auto_setup.ok
  exit 0
fi
log "configure"
if ! tools/dock python3 tools/configure.py >>"$LOG" 2>&1; then
  log "configure FAILED (see above)"
  exit 1
fi
log "ninja (a few minutes)"
if ! tools/dock ninja >>"$LOG" 2>&1; then
  log "ninja FAILED (the built image differs); first_diff follows"
  tools/dock python3 tools/first_diff.py >>"$LOG" 2>&1 || true
  exit 1
fi
if [ -f build/ok ]; then
  log "READY: the built image matches the game (SHA-1)"
  touch build/auto_setup.ok
else
  log "ninja ran but build/ok is missing: the SHA-1 did not match"
  exit 1
fi
