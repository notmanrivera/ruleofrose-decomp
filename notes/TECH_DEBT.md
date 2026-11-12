# Technical debt

Things that match byte for byte but should be tidied, or attempts to pick
up again. Regenerate the lists rather than trusting them:

```sh
grep -rn "// NON_MATCHING" src             # attempts kept under #ifdef NON_MATCHING
tools/.venv/bin/python tools/backlog.py --file <file> --max 999 --nonmatching
grep -rlE 'X_[A-Za-z_0-9]+\(.*asm\("' src   # call aliases
```

## NON_MATCHING attempts

About 50 functions keep a close attempt under `#ifdef NON_MATCHING`
(`grep` above), most noted "close, not identical yet". Ones with a measured
gap, from the 2026-11-12 worker run:

| File | Function | Gap |
|---|---|---|
| mag/maglifepc3 | func_0011DC64 | 11 of 55 instructions |
| mag/maglifepc3 | func_0011DD40 | 19 of 46 instructions |
| mag/maglifepcbtl | func_0012CA28 | 3 of 31 instructions |
| mag/maglifepc | pad handler | 56 of 181 instructions |

`mag/maglifepc2` `func_0011D1CC` (133 instructions) has no attempt: Gemini's
content filter blocked every reply about it; give it to another model.

## `X_` call aliases

`extern "C" ... X_func_NNNNNNNN(...) asm("func_NNNNNNNN");` lets a file call
a function whose prototype elsewhere in the file (or a header) has another
signature, or whose real signature is unknown. The convention is
project-wide (68 files). Replace an alias with the real declaration once
the callee is decompiled and its signature is known; the bytes do not
change.

## Missing `return` on purpose

`utl/utlgame` `func_0010254C` and `func_001027D4` are declared `int` but
end without a `return`: that is what stops gcc from turning the last call
into a tail call, as the game has it. The compiler warns; leave them.

## Header declarations proposed by workers

Kept local to their `.cpp` until someone checks them against every caller:

- `src/game/gamman.h`: `extern "C" void func_001D05F4(GamMan *theGamMan, DogVector *theOut, int theA);`
- utl/utlgame: `extern "C" void func_00102AB8(DogVector *theOut, int theA);`
