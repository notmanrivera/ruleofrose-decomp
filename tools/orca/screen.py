#!/usr/bin/env python3
"""Read facts off an agent's Orca screen (the JSON of `orca terminal read
--screen --json` on stdin):

    orca terminal read --terminal H --screen --json | python tools/orca/screen.py model
    ... | python tools/orca/screen.py context   # context use in %, if the TUI shows it
    ... | python tools/orca/screen.py wait      # seconds until a usage limit resets

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
    m = re.search(r"Resets (\d{1,2}):(\d{2}) ?([AP]M)", text)
    if m:
        h = int(m.group(1)) % 12 + (12 if m.group(3) == "PM" else 0)
        at = now.replace(hour=h, minute=int(m.group(2)), second=0, microsecond=0)
        if at <= now:
            at += datetime.timedelta(days=1)
        secs = (at - now).total_seconds()
    else:
        m = re.search(r"resets in (\d+)h(?:\s*(\d+)m)?", text, re.I)
        if not m:
            return ""
        secs = int(m.group(1)) * 3600 + int(m.group(2) or 0) * 60
    if secs > LIMIT_HOURS * 3600:
        return ""
    return str(int(secs) + 180)   # a few minutes' margin


def main():
    what = sys.argv[1] if len(sys.argv) > 1 else ""
    fn = {"model": model, "context": context, "wait": wait}.get(what)
    if not fn:
        sys.exit(__doc__)
    print(fn(lines()))


if __name__ == "__main__":
    main()
