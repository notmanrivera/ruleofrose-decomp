# Shared build environment for the Rule of Rose decomp.
#
# The PS2 compilers are 32-bit Linux (SCE builds) or Windows (SN Systems
# builds, run through wibo) binaries, so the image is linux/amd64; on Apple
# Silicon Docker runs it under Rosetta.
#
#   docker build --platform linux/amd64 -t ror-build docker/
#   docker run --rm -v "$PWD":/work -w /work ror-build <command>
#
# All EE-GCC 2.9x candidates are installed under /compilers/ps2/<id> (same
# ids and tarballs as decomp.me). Once the game's compiler is identified the
# others can be dropped to slim the image.
FROM --platform=linux/amd64 debian:bookworm-slim

RUN dpkg --add-architecture i386 \
 && apt-get update \
 && apt-get install -y --no-install-recommends \
      ca-certificates curl xz-utils python3 python3-venv libc6:i386 \
      binutils-mips-linux-gnu make ninja-build git \
 && rm -rf /var/lib/apt/lists/*

# Python tooling for splitting and building (pinned for reproducibility)
RUN python3 -m venv /opt/venv \
 && /opt/venv/bin/pip install --no-cache-dir \
      "splat64[mips]==0.50.0" pyelftools ninja_syntax
ENV PATH="/opt/venv/bin:$PATH"

ARG WIBO_VERSION=1.2.0
RUN curl -fsSL -o /usr/local/bin/wibo \
      "https://github.com/decompals/wibo/releases/download/${WIBO_VERSION}/wibo-i686" \
 && chmod +x /usr/local/bin/wibo

ARG DL=https://github.com/decompme/compilers/releases/download/compilers
WORKDIR /tmp/dl

# SCE toolchain builds (Linux binaries)
RUN set -e; for id in ee-gcc2.9-990721 ee-gcc2.9-991111 ee-gcc2.9-991111a \
                     ee-gcc2.9-991111-01 ee-gcc2.96; do \
      mkdir -p /compilers/ps2/$id; \
      curl -fsSL "$DL/$id.tar.xz" | tar xJ -C /compilers/ps2/$id; \
    done
RUN mkdir -p /compilers/ps2/ee-gcc2.9-991111-01-dtls13010 \
 && curl -fsSL "$DL/ee-gcc2.9-991111-01-dtls13010.tar.gz?2025-04-10" \
    | tar xz -C /compilers/ps2/ee-gcc2.9-991111-01-dtls13010

# SN Systems ProDG builds (Windows binaries, run with wibo)
RUN set -e; for id in ee-gcc2.95.2-273a ee-gcc2.95.3-114 ee-gcc2.95.3-136; do \
      mkdir -p /compilers/ps2/$id; \
      curl -fsSL "$DL/$id.tar.gz" | tar xz -C /compilers/ps2/$id; \
    done
RUN curl -fsSL "$DL/ps2_compilers.tar.xz" | tar xJ \
 && for id in ee-gcc2.95.2-274 ee-gcc2.95.3-107; do \
      mkdir -p /compilers/ps2/$id && cp -r $id/* /compilers/ps2/$id/; \
    done \
 && rm -rf /tmp/dl/*

RUN chmod -R a+rX /compilers && find /compilers -type f \( -path "*/bin/*" -o -name "*.exe" -o -path "*/gcc-lib/*" \) -exec chmod +x {} +

COPY ee-cc /usr/local/bin/ee-cc
RUN chmod +x /usr/local/bin/ee-cc

WORKDIR /work
