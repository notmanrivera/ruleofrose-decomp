#!/bin/sh
# dump.sh: compile build/wip/dogactor.cpp with -da; dumps land in build/rtl/
cd /Users/rubenrivera/Desktop/Code/RuleOfRose && cp build/wip/dogactor.cpp build/rtl/da.cpp && rm -f build/rtl/da.cpp.* && \
~/.docker/bin/docker run --rm --platform linux/amd64 -v "$PWD":/work -w /work/build/rtl ror-build sh -c \
 "ee-cc ee-gcc2.96 -Os -G0 -fno-exceptions -fno-strict-aliasing -x c++ -I/work/src -I/work/include -Wa,-I/work $* -da -c da.cpp -o da.o" 2>&1 | tail -3
