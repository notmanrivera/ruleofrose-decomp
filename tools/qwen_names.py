#!/usr/bin/env python3
"""Ask a local model (Ollama) for method names, and measure how good it is.

    tools/.venv/bin/python tools/qwen_names.py --test 40      # blind test on methods whose real name is known
    tools/.venv/bin/python tools/qwen_names.py --suggest 30   # suggestions for Class__vfunc_NN placeholders

--test takes decompiled methods whose name is the game's own (from its
mangled symbols), hides the name (FUNC), shows the code with the class's
other method names as a style hint, and scores the model's three guesses
against the real name: exact (case-insensitive), or the share of words in
common (getNodeName vs getName: 2 of 3). --suggest does the same for
placeholder names and writes build/qwen/name_suggestions.tsv for a person to
review: nothing is renamed by this tool.

Log for the progress bar: build/workers/qwen-names.log.
"""
import argparse
import json
import random
import re
import sys
import time
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "build/qwen"
LOG = ROOT / "build/workers/qwen-names.log"
URL = "http://localhost:11434/api/generate"
NL = "\n"
HEAD = re.compile(r"^(?!\s|#|//|static\b|typedef\b)[^;{}()=]*?\b([A-Z]\w*)(::|__)(\w+)\s*\(([^;]*)$")

PROMPT = """This is a function from the PS2 game Rule of Rose (C++, 2006, Japanese developers). Its name is hidden as FUNC.
It is a method of the class {cls}. Other methods of {cls} and its family are called: {siblings}.

```cpp
{code}
```

Propose the 3 most likely original names for FUNC, in the same style as the other names (camelCase verbs like getNodeName, setTop, isAlive, init, live, draw).
Answer only JSON: {{"names": ["best", "second", "third"], "why": "short reason"}}"""


def log(msg):
    LOG.parent.mkdir(parents=True, exist_ok=True)
    with open(LOG, "a", encoding="utf-8") as f:
        f.write(f"{time.strftime('%H:%M:%S')} {msg}{NL}")
    print(msg, flush=True)


def ask(model, prompt):
    body = json.dumps({"model": model, "prompt": prompt, "format": "json", "stream": False,
                       "options": {"temperature": 0.3, "num_ctx": 8192}}).encode()
    req = urllib.request.Request(URL, body, {"Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=600) as r:
        return json.loads(r.read())["response"]


def methods():
    """[(file, class, name, sep, code)] of every function defined in src/
    as Class::name or Class__name (placeholders), outside NON_MATCHING-only
    duplicates."""
    out = []
    for p in sorted((ROOT / "src").rglob("*.cpp")):
        lines = p.read_text(errors="replace").split(NL)
        for i, l in enumerate(lines):
            m = HEAD.match(l)
            if not m or i + 1 >= len(lines) or lines[i + 1].strip() != "{" and not l.rstrip().endswith("{"):
                continue
            j = i + 1
            while j < len(lines) and lines[j] != "}":
                j += 1
            if j >= len(lines) or j - i > 80:
                continue
            out.append((p.relative_to(ROOT / "src").as_posix(), m.group(1), m.group(3), m.group(2),
                        NL.join(lines[i:j + 1])))
    return out


def words(name):
    return [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", name)]


def closeness(guess, real):
    if guess.lower() == real.lower():
        return 1.0
    g, r = set(words(guess)), set(words(real))
    return len(g & r) / len(g | r) if g | r else 0.0


def placeholder(name):
    return bool(re.match(r"^(v?func_|FUN_)", name)) or name.startswith("~") or name.startswith("operator")


def family(cls):
    """Classes sharing the name's prefix (MagLifePC, MagLifePCModeWait...)."""
    return re.match(r"[A-Z][a-z]+[A-Z]?[a-z]*", cls).group(0) if re.match(r"[A-Z][a-z]+", cls) else cls


def main():
    ap = argparse.ArgumentParser(description=__doc__.split(NL)[0])
    ap.add_argument("--test", type=int, metavar="N", help="blind test on N methods with real names")
    ap.add_argument("--suggest", type=int, metavar="N", help="suggest names for N placeholder methods")
    ap.add_argument("--model", default="qwen2.5-coder:7b-instruct")
    ap.add_argument("--seed", type=int, default=1)
    a = ap.parse_args()
    allm = methods()
    known = [m for m in allm if m[3] == "::" and not placeholder(m[2]) and m[2] != m[1]]
    names_of = {}
    for _, cls, name, _, _ in known:
        names_of.setdefault(family(cls), set()).add(name)
    rnd = random.Random(a.seed)
    if a.test:
        jobs = rnd.sample(known, min(a.test, len(known)))
        kind = "test"
    else:
        holders = [m for m in allm if m[3] == "__" and re.match(r"vfunc_\d+$", m[2])]
        jobs = rnd.sample(holders, min(a.suggest or 30, len(holders)))
        kind = "suggest"
    log(f"qwen names {kind}: {len(jobs)} methods, model {a.model}")
    rows, top1, top3, near = [], 0, 0, 0.0
    for k, (file, cls, name, sep, code) in enumerate(jobs, 1):
        hidden = re.sub(rf"\b{re.escape(cls)}(::|__){re.escape(name)}\b", f"{cls}::FUNC", code)
        if kind == "test":
            hidden = re.sub(rf"\b{re.escape(name)}\b", "FUNC", hidden)
        sib = sorted(names_of.get(family(cls), set()) - {name})[:40]
        prompt = PROMPT.format(cls=cls, siblings=", ".join(sib) or "(none known)", code=hidden)
        try:
            ans = json.loads(ask(a.model, prompt))
            guesses = [str(g) for g in ans.get("names", [])][:3]
            why = str(ans.get("why", ""))[:100]
        except Exception as e:  # noqa: BLE001
            guesses, why = [], f"bad answer ({type(e).__name__})"
        if kind == "test":
            sc = [closeness(g, name) for g in guesses] or [0.0]
            top1 += sc[0] == 1.0
            top3 += max(sc) == 1.0
            near += max(sc)
            log(f"[{k}/{len(jobs)}] {cls}::{name} -> {', '.join(guesses) or '-'}"
                f"  ({'exact' if max(sc) == 1.0 else f'{max(sc):.0%} words'})")
            rows.append((file, cls, name, ", ".join(guesses), f"{max(sc):.2f}", why))
        else:
            log(f"[{k}/{len(jobs)}] {cls}__{name} -> {', '.join(guesses) or '-'}")
            rows.append((file, cls, name, ", ".join(guesses), "", why))
    OUT.mkdir(parents=True, exist_ok=True)
    dest = OUT / ("name_test.tsv" if kind == "test" else "name_suggestions.tsv")
    with open(dest, "w", encoding="utf-8", newline=NL) as f:
        f.write("file\tclass\tname\tguesses\tscore\twhy" + NL)
        for r in rows:
            f.write("\t".join(x.replace("\t", " ") for x in r) + NL)
    if kind == "test":
        n = len(jobs)
        log(f"qwen names test done: exact first guess {top1}/{n}, exact in 3 guesses {top3}/{n}, "
            f"mean best word overlap {near / n:.0%} (in {dest.relative_to(ROOT).as_posix()})")
    else:
        log(f"qwen names suggest done: {len(rows)} suggestions in {dest.relative_to(ROOT).as_posix()}")


if __name__ == "__main__":
    main()
