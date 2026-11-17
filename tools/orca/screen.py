#!/usr/bin/env python3
"""Read facts off an agent's Orca screen (the JSON of `orca terminal read
--screen --json` on stdin):

    orca terminal read --terminal H --screen --json | python tools/orca/screen.py model
    ... | python tools/orca/screen.py context   # context use in %, if the TUI shows it
    ... | python tools/orca/screen.py wait      # seconds until a usage limit resets
                                                # ("long <secs>" past LIMIT_HOURS)

Prints nothing when the screen does not say. Known screens: OpenCode
("Build · DeepSeek V4.1 Flash OpenCode Go · high", "778.6K (78%)",
"Resets 11:56 PM today") and Antigravity ("Gemini 4 Hydrogen · high",
"resets in 152h").
"""
import datetime
import json
import re
import sys

LIMIT_HOURS = 8           # a longer wait is not waited out: the loop stops


def lines():
    try:
        return json.load(sys.stdin)["result"]["terminal"]["tail"]
    except (ValueError, KeyError, TypeError):
        return []


def model(tail):
    for line in reversed(tail):
        m = re.search(r"Build · (.+?) OpenCode", line)             # OpenCode
        if m:
            return m.group(1).strip()
        m = re.search(r"^\s*(GPT[\w.\-]+(?: \w+)?) · ", line)                # Codex
        if m:
            return m.group(1).strip()
        m = re.search(r"(\S.*?) · (low|medium|high|xhigh)\s*$", line)  # Antigravity
        if m:
            return f"{m.group(1).split('  ')[-1].strip()} {m.group(2)}"
    return ""


def context(tail):
    for line in reversed(tail):
        m = re.search(r"[\d.]+K \((\d+)%\)", line)
        if m:
            return m.group(1)
    return ""


def wait(tail, now=None):
    now = now or datetime.datetime.now()
    text = "\n".join(tail[-40:])
    # "Resets 11:56 PM today" (OpenCode Go), "They reset at 6:43 p.m." (its free tier),
    # "try again at 6:05 PM" (Codex)
    # (a wrapped line puts a newline anywhere in it)
    m = re.search(r"(?:[Rr]esets?|try\s+again)\s+(?:at\s+)?(\d{1,2}):(\d{2})\s*([AaPp])\.?[Mm]", text)
    if m:
        h = int(m.group(1)) % 12 + (12 if m.group(3).upper() == "P" else 0)
        at = now.replace(hour=h, minute=int(m.group(2)), second=0, microsecond=0)
        if at <= now:
            at += datetime.timedelta(days=1)
        secs = (at - now).total_seconds()
    else:
        # "resets in 152h", "Resets in 2h 5m", "Resets in" + newline + "48m54s"
        m = re.search(r"(?:resets|try again) in\s+(?:(\d+)\s*h\w*)?\s*(?:(\d+)\s*m\w*)?\s*(?:(\d+)\s*s\w*)?",
                      text, re.I)
        if not m or not any(m.groups()):
            return ""
        secs = int(m.group(1) or 0) * 3600 + int(m.group(2) or 0) * 60 + int(m.group(3) or 0)
    if secs > LIMIT_HOURS * 3600:
        return f"long {int(secs)}"   # not worth waiting for: the loop stops
    return str(int(secs) + 180)   # a few minutes' margin


def main():
    what = sys.argv[1] if len(sys.argv) > 1 else ""
    fn = {"model": model, "context": context, "wait": wait}.get(what)
    if not fn:
        sys.exit(__doc__)
    print(fn(lines()))


if __name__ == "__main__":
    main()
