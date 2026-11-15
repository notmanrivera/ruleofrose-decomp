# Modern host compilers (g++ and clang) for tools/host_check.py: every source is also
# checked with g++ for a 32-bit PC target (-m32, like the PS Vita's ARM),
# so the code stays valid for the PC and Vita ports while it matches.
#
#   docker build --platform linux/amd64 -t ror-host docker/host/
FROM --platform=linux/amd64 debian:bookworm-slim
RUN apt-get update \
 && apt-get install -y --no-install-recommends g++ g++-multilib clang \
 && rm -rf /var/lib/apt/lists/*
WORKDIR /work
