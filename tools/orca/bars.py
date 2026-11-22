"""Progress of each worker's current batch, and of the session.

    tools/.venv/Scripts/python.exe tools/orca/bars.py            # once
    tools/.venv/Scripts/python.exe tools/orca/bars.py --watch 20 # refresh every 20 s
    tools/.venv/Scripts/python.exe tools/orca/bars.py --reset    # start a new session count

Per worker (build/workers/<name>.env and its worktree ../ror-wt-<name>):
  - what its screen shows: working, waiting, out of quota, content filter,
    and for how long nothing has changed (red after STALE_MIN minutes);
  - each function of the batch: done (no INCLUDE_ASM left in its src/;
    the merge still verifies it byte for byte), or how close its best
    check is (build/work/.best: 1 - edits / instructions) and how many
    checks it took (build/work/.tried).
Session: progress since build/workers/session.txt (written on the first
run or with --reset), functions merged since then (stats.tsv), and exact
matches per hour for each model over all of stats.tsv.
"""
import json
import os
import re
import subprocess
import sys
import time

MAIN = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ST = os.path.join(MAIN, "build", "workers")
PY = sys.executable
WIDTH = 30
STALE_MIN = 15
QUOTA = re.compile(r"quota (reached|exceeded)|[Rr]ate.?limit|resets in [0-9]+h|(HTTP|status|error) 429|"
                   r"[Ii]nsufficient (balance|credits)|out of credits|[Uu]sage limit reached|Resets [0-9]+:[0-9]+|"
                   r"used today.s free messages|[Tt]hey reset at [0-9]|hit your usage limit")
FILTER = re.compile(r"[Cc]ontent (filter|policy)|blocked by (safety|the filter)|SAFETY|[Rr]esponse was blocked|"
                    r"blocked by Gemini.s filters")
C = {"red": "\x1b[31m", "green": "\x1b[32m", "yellow": "\x1b[33m", "dim": "\x1b[2m", "bold": "\x1b[1m",
     "cyan": "\x1b[36m", "magenta": "\x1b[35m", "off": "\x1b[0m"}
LINE = 72                       # width of the section rules
# Who each worker is, for the owner (the .env name is the worktree's).
SHOWN = {"fable": "Neon", "gemini": "Hydrogen", "opencode": "OpenCode", "codex": "Codex"}
# state -> (icon, colour, text)
STATES = {"busy": ("●", "green", "trabajando"), "wait": ("◐", "yellow", "esperando"),
          "idle": ("○", "dim", "libre"), "paused": ("○", "dim", "en pausa"),
          "quota": ("◌", "red", "sin cuota"), "filter": ("✕", "red", "bloqueado por el filtro")}


def section(title):
    """A section header: the title and a thin rule to the right."""
    return col(f" {title} ", "bold") + col("─" * max(4, LINE - len(title) - 2), "dim")


def bar(pct, width=WIDTH, colour="green"):
    f = max(0, min(width, round(width * pct / 100)))
    return col("█" * f, colour) + col("░" * (width - f), "dim")


def col(text, c):
    return C[c] + text + C["off"]


def read_env(path):
    env = {}
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            m = re.match(r"^(\w+)='(.*)'$", line.rstrip("\n"))
            if m:
                env[m.group(1)] = m.group(2)
    return env


def run(args):
    try:
        return subprocess.run(args, capture_output=True, text=True, encoding="utf-8",
                              errors="replace", timeout=20).stdout
    except (OSError, subprocess.SubprocessError):
        return ""


def terminals():
    """handle -> seconds since its last output."""
    try:
        ts = json.loads(run(["orca", "terminal", "list", "--json"]))["result"]["terminals"]
    except (ValueError, KeyError, TypeError):
        return {}
    now = time.time()
    return {t["handle"]: now - t["lastOutputAt"] / 1000 for t in ts if t.get("lastOutputAt")}


def screen(handle):
    try:
        return json.loads(run(["orca", "terminal", "read", "--terminal", handle, "--screen", "--json"])
                          )["result"]["terminal"]["tail"]
    except (ValueError, KeyError, TypeError):
        return []


def src_states(src, names):
    """name -> 'done' | 'near' | 'todo' from a src/<file>.cpp."""
    try:
        with open(src, encoding="utf-8", errors="replace") as f:
            lines = f.readlines()
    except OSError:
        return {n: "todo" for n in names}
    asm, near = set(), set()
    stack = []  # one entry per open #if: True when it is `#ifdef NON_MATCHING`
    for line in lines:
        s = line.strip()
        if s.startswith("#if"):
            stack.append(s.startswith("#ifdef NON_MATCHING") or "defined(NON_MATCHING)" in s)
        elif s.startswith("#endif") and stack:
            stack.pop()
        m = re.search(r'INCLUDE_ASM\("[^"]*",\s*(\w+)\)', s)
        if m:
            (near if any(stack) else asm).add(m.group(1))
    return {n: "near" if n in near else "todo" if n in asm else "done" for n in names}


def closeness(status):
    """0..100 from a work.py status ('MATCH', '7/75 differ, 4 edits', ...), or None."""
    if status == "MATCH":
        return 100
    m = re.search(r"(\d+)/(\d+) differ", status)
    e = re.search(r"(\d+) edits", status)
    if m and e:
        return max(0, round(100 * (1 - int(e.group(1)) / int(m.group(2)))))
    if e:                       # only relocations differ
        return 99
    return None


def best(wt, file, fn):
    try:
        with open(os.path.join(wt, "build", "work", ".best", file, fn + ".cpp"), encoding="utf-8") as f:
            return f.readline().strip().removeprefix("// best: ")
    except OSError:
        return ""


def size(file, fn):
    """Instructions in the game's version of the function, or None."""
    try:
        with open(os.path.join(MAIN, "asm", "nonmatchings", file, fn + ".s"), encoding="utf-8") as f:
            m = re.match(r"nonmatching \S+, 0x([0-9A-Fa-f]+)", f.readline())
            return int(m.group(1), 16) // 4 if m else None
    except OSError:
        return None


def tries(wt, file):
    """fn -> (checks, lowest score). Before work.py scored 'asm' high, an
    unchanged INCLUDE_ASM logged 1, so a 1 is not trusted here."""
    out = {}
    try:
        with open(os.path.join(wt, "build", "work", ".tried"), encoding="utf-8", errors="replace") as f:
            for line in f:
                p = line.split()
                if len(p) >= 2 and p[0] == file:
                    k, lo = out.get(p[1], (0, None))
                    sc = int(p[2]) if len(p) > 2 and p[2].isdigit() else None
                    if sc is not None and 1 < sc < 1 << 30:
                        lo = sc if lo is None else min(lo, sc)
                    out[p[1]] = (k + 1, lo)
    except OSError:
        pass
    return out


def mini(pct, n=10):
    f = round(n * pct / 100)
    return "█" * f + "░" * (n - f)


def progress():
    """(bytes, percent) of the game, from tools/progress.py."""
    m = re.search(r"^game\s.*?([\d,]+) / [\d,]+\s+([\d.]+)%", run([PY, os.path.join(MAIN, "tools", "progress.py")]), re.M)
    return (int(m.group(1).replace(",", "")), float(m.group(2))) if m else (None, None)


def session(reset=False):
    path = os.path.join(ST, "session.txt")
    if reset or not os.path.exists(path):
        b, p = progress()
        if b is None:
            return None
        with open(path, "w", encoding="utf-8") as f:
            f.write(f"{time.strftime('%Y-%m-%d %H:%M')}\t{b}\t{p}\n")
    with open(path, encoding="utf-8") as f:
        t, b, p = f.readline().rstrip("\n").split("\t")
    return t, int(b), float(p)


def stats():
    rows = []
    try:
        with open(os.path.join(ST, "stats.tsv"), encoding="utf-8", errors="replace") as f:
            head = f.readline().rstrip("\n").split("\t")
            for line in f:
                r = dict(zip(head, line.rstrip("\n").split("\t")))
                try:
                    r["exact"] = int(r["merged"]) - int(r["non_matching"])
                    r["minutes"] = int(r["minutes"])
                except (KeyError, ValueError):
                    continue
                rows.append(r)
    except OSError:
        pass
    return rows


def task_rows(name):
    """A worker on a list of tasks instead of a batch of functions
    (build/workers/<name>-tasks.tsv: id, state done|now|todo, title, note;
    the coordinator keeps it up to date): one bar for the tasks, one row
    per task, and for the current one what its worktree holds (files
    changed and commits not merged yet)."""
    rows = []
    try:
        for ln in open(os.path.join(ST, f"{name}-tasks.tsv"), encoding="utf-8"):
            p = ln.rstrip("\n").split("\t")
            if len(p) >= 3 and not ln.startswith("#"):
                rows.append((p[0], p[1], p[2], p[3] if len(p) > 3 else ""))
    except OSError:
        return []
    if not rows:
        return []
    done = sum(r[1] == "done" for r in rows)
    out = [f"   {bar(100 * done / len(rows), 24)} {done}/{len(rows)} tareas hechas"]
    wt = os.path.join(os.path.dirname(MAIN), f"ror-wt-{name}")
    changed = [ln[3:] for ln in run(["git", "-C", wt, "status", "--porcelain"]).splitlines() if ln.strip()]
    # commits whose change is not in pr-merge yet (cherry-picked ones drop out)
    ahead = str(sum(ln.startswith("+") for ln in run(["git", "-C", wt, "cherry", "pr-merge", "HEAD"]).splitlines()))
    for tid, state, title, note in rows:
        mark = {"done": col("✓", "green"), "now": col("▶", "cyan")}.get(state, col("·", "dim"))
        short = title if len(title) <= 52 else title[:51] + "…"
        text = col(short, "bold") if state == "now" else (col(short, "dim") if state != "done" else short)
        line = f"   {mark} {col(tid, 'dim')} {text}"
        if note:
            line += "\n" + col(f"         {note}", "dim") if state == "now" else col(f"  · {note[:40]}", "dim")
        if state == "now":
            extra = []
            if changed:
                extra.append(f"{len(changed)} archivo{'s' if len(changed) != 1 else ''} a medias ("
                             + ", ".join(os.path.basename(c) for c in changed[:3])
                             + (", …" if len(changed) > 3 else "") + ")")
            if ahead and ahead != "0":
                extra.append(f"{ahead} commit{'s' if ahead != '1' else ''} sin fusionar")
            if extra:
                line += "\n" + col("         " + " · ".join(extra), "yellow")
        out.append(line)
    return out


def worker(name, env, idle):
    out = []
    status = env.get("STATUS", "?")
    model = env.get("MODEL", "") or env.get("PRIMARY", "")
    names = [x.strip() for x in env.get("BATCH", "").split(",") if x.strip()]
    tail = screen(env["HANDLE"]) if env.get("HANDLE") else []
    text = "\n".join(tail[-40:])
    quiet = idle.get(env.get("HANDLE", ""))
    if status != "busy":
        key = status if status in STATES else "idle"
    elif QUOTA.search("\n".join(tail[-12:])):
        key = "quota"
    elif FILTER.search("\n".join(tail[-12:])):
        key = "filter"
    elif env.get("BUSY") and re.search(env["BUSY"], text):
        key = "busy"
    else:
        key = "wait"
    icon, colour, what = STATES[key]
    note = ""
    if key in ("busy", "wait") and quiet is not None and quiet > STALE_MIN * 60:
        note = col(f"  pantalla quieta {quiet / 60:.0f} min", "red")
    on = env.get("FILE", "") if key in ("busy", "wait") else ""
    model = model.removeprefix("auto · ")
    out.append(f" {col(icon, colour)} {col(f'{SHOWN.get(name, name):<10}', 'bold')}"
               f"{col(f'{model:<26}', 'dim')} {col(f'{what:<11}', colour)}"
               + (f" {col(on, 'cyan')}" if on else "") + note)
    if key not in ("busy", "wait"):
        return out           # resting: one line is enough
    if not names and os.path.exists(os.path.join(ST, f"{name}-tasks.tsv")):
        out.extend(task_rows(name))
        return out
    if not names:
        return out
    # A batch is one file's functions (FILE, BATCH "f1, f2"), or functions
    # of several files ("file:func, file:func", FILE empty).
    wt = os.path.join(os.path.dirname(MAIN), f"ror-wt-{name}")
    items = [(n.split(":", 1)[0], n.split(":", 1)[1]) if ":" in n else (env.get("FILE", ""), n) for n in names]
    files = sorted({f for f, _ in items})
    st, base, nt = {}, {}, {}
    for f in files:
        fns = [fn for ff, fn in items if ff == f]
        st.update({(f, k): v for k, v in src_states(os.path.join(wt, "src", f + ".cpp"), fns).items()})
        base.update({(f, k): v for k, v in src_states(os.path.join(MAIN, "src", f + ".cpp"), fns).items()})
        nt.update({(f, k): v for k, v in tries(wt, f).items()})
    # The function it is on: the newest scratch file of the batch (work.py's
    # build/work/<file>/<fn>*.cpp), else the last one its screen names.
    now_on, newest = None, 0.0
    for f, n in items:
        for suffix in (".cpp", ".trial.cpp"):
            try:
                t = os.path.getmtime(os.path.join(wt, "build", "work", f, n + suffix))
            except OSError:
                continue
            if t > newest and t >= float(env.get("SENT", "0") or 0):
                now_on, newest = (f, n), t
    if not now_on:
        for line in reversed(tail):
            hit = [(f, n) for f, n in items if n in line]
            if hit:
                now_on = hit[-1]
                break
    pcts, done, near = [], 0, 0
    rows = []
    multi = len(files) > 1
    for f, n in items:
        b = best(wt, f, n)
        pct = closeness(b) if b else None
        k, lo = nt.get((f, n), (0, None))
        sz = size(f, n)
        if pct is None and lo is not None and sz:
            pct = max(0, round(100 * (1 - lo / sz)))
        if st[(f, n)] == "done":
            done += 1
            pct = 100
            mark, what = col("\u2713", "green"), col("escrita", "green")
        elif st[(f, n)] == "near" and base[(f, n)] != "near":
            near += 1
            mark, what = col("~", "yellow"), "guardada casi"
        elif pct == 100:
            mark, what = col("\u2713", "green"), "coincide, sin guardar"
        elif pct is not None:
            mark, what = col("\u00b7", "yellow"), "probando"
        else:
            mark, what = col("\u00b7", "dim"), col("sin probar", "dim")
        pcts.append(pct or 0)
        if pct is None and k:
            what = col("no compila todav\u00eda", "yellow")
        cur = col("  \u25c0 ahora", "bold") if (f, n) == now_on and status == "busy" else ""
        pct_s = f"{mini(pct)} {pct:3d}%" if pct is not None else f"{mini(0)}   -"
        label = f"{f.split('/')[-1]} {n}" if multi else n
        width = 34 if multi else 22
        rows.append(f"    {mark} {label:<{width}} {pct_s}  {what}"
                    + (f", {k} prueba{'s' if k != 1 else ''}" if k else "") + cur)
    avg = sum(pcts) / len(items)
    fw = round(WIDTH * avg / 100)
    mins = ""
    if env.get("SENT", "").isdigit():
        mins = f"  {(time.time() - int(env['SENT'])) / 60:.0f} min"
    where = f"{len(files)} archivos" if multi else files[0]
    out.append(f"   {bar(avg, 24)} {avg:3.0f}%  {done}/{len(items)} escritas"
               + (f", {near} casi" if near else "") + col(f"  \u00b7  {where}{mins}", "dim"))
    out.extend(rows)
    return out


def alive(word, log, minutes=15):
    """Whether a background process runs: by `ps` where there is one (Git
    Bash), else by its log having changed in the last minutes (the Orca tab
    runs in PowerShell, without ps)."""
    ps = run(["ps", "-ef"])
    if ps:
        # not the coordinator's own shell commands, whose text may only
        # mention the name (a grep, a heredoc)
        return any(word in ln and "shell-snapshots" not in ln for ln in ps.splitlines())
    try:
        return time.time() - os.path.getmtime(log) < minutes * 60
    except OSError:
        return False


def permuter():
    """The permuter queue (tools/permute_queue.py, log build/workers/perm-loop.log):
    its bar, the function it is on, that one's best so far, and its matches."""
    path = os.path.join(ST, "perm-loop.log")
    try:
        lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    except OSError:
        return []
    running = alive("permute_queue", path)
    m = re.search(r"--minutes (\S+)", run(["ps", "-ef"]))
    per = float(m.group(1)) if m else 8.0
    is_q = [bool(re.match(r"^\s*\d+ off\s+\S+ \S+", ln)) for ln in lines]
    # matches of every run; the bar for the last run only (a resumed queue
    # lists what is left and appends to the same log)
    all_matches = [ln.split("MATCH committed:", 1)[1].strip() for ln in lines if "MATCH committed:" in ln]
    starts = [i for i in range(len(lines)) if is_q[i] and (i == 0 or not is_q[i - 1])]
    runs = len(starts)
    if starts:
        lines = lines[starts[-1]:]
        is_q = is_q[starts[-1]:]
    queue = [ln for ln, q in zip(lines, is_q) if q]
    started = [i for i, ln in enumerate(lines) if ln.startswith("== ")]
    matches = all_matches
    total = len(queue) or len(started)
    done = len(started) - (1 if running and started else 0)
    out = [f"{col('permutador', 'bold')} " + (col("trabajando", "green") if running else col("parado", "yellow"))
           + f"  (sin IA; log {os.path.relpath(path, MAIN)})"]
    if not total:
        return out + [col("  (cola vac\u00eda)", "dim")]
    f = round(WIDTH * done / total)
    big = "\u2588" * f + "\u2591" * (WIDTH - f)
    left = ""
    if running and per:
        left = f"  quedan \u2264{(total - done) * per / 60:.1f} h"
    out.append(f"  cola de 'casi'  {big} {done}/{total} probadas" + (f" (tanda {runs})" if runs > 1 else "") + ", "
               + col(f"{len(matches)} exactas", "green" if matches else "dim") + left)
    if running and started:
        i = started[-1]
        head = lines[i][3:]
        name, _, start = head.partition(": ")
        best = start
        tries = 0
        for ln in lines[i + 1:]:
            t = re.match(r"^\s*(\d+) tries\s+(.*)$", ln)
            if t:
                tries, best = int(t.group(1)), t.group(2)
        st = re.search(r"(\d+) edits", best)
        s0 = re.search(r"(\d+) edits", start)
        gain = ""
        if st and s0 and int(st.group(1)) < int(s0.group(1)):
            gain = col(f"  (empez\u00f3 en {s0.group(1)} cambios)", "green")
        out.append(f"    \u25c0 ahora {name}: mejor {best}" + (f", {tries} variantes" if tries else "") + gain)
    for mt in matches[-5:]:
        out.append(f"    {col(chr(0x2713), 'green')} {mt}")
    return out


def auto_m2c():
    """tools/auto_m2c.py's run (log build/workers/auto-run.log): the signature
    passes, then one "[k/N] file: note" line per file."""
    path = os.path.join(ST, "auto-run.log")
    try:
        lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    except OSError:
        return []
    running = alive("auto_m2c", path, 30)
    out = [f"{col('auto_m2c', 'bold')} " + (col("trabajando", "green") if running else col("parado", "yellow"))
           + f"  (sin IA; log {os.path.relpath(path, MAIN)})"]
    passes = [ln for ln in lines if ln.startswith("signatures, pass")]
    prog = [re.match(r"^\[(\d+)/(\d+)\] (\S+): (.*)$", ln) for ln in lines]
    prog = [m for m in prog if m]
    if not prog:
        out.append(f"  firmas de las funciones: {len(passes)} pasadas"
                   + (f" (la \u00faltima cambi\u00f3 {passes[-1].split(': ')[-1]})" if passes else ""))
        return out
    k, n = int(prog[-1].group(1)), int(prog[-1].group(2))
    found = [(m.group(3), m.group(4)) for m in prog if "bytes" in m.group(4)]
    got = sum(int(re.search(r"([\d,]+) bytes", note).group(1).replace(",", "")) for _, note in found)
    f = round(WIDTH * k / n)
    big = "\u2588" * f + "\u2591" * (WIDTH - f)
    out.append(f"  archivos  {big} {k}/{n}, " + col(f"{got:,} bytes nuevos en {len(found)} archivos", "green" if got else "dim"))
    for name, note in found[-4:]:
        out.append(f"    {col(chr(0x2713), 'green')} {name}: {note}")
    if not running and lines and lines[-1].startswith("total:"):
        out.append("  " + lines[-1])
    return out


def flag_sweep():
    """tools/flag_sweep.py (log build/workers/flag-sweep.log): one
    "[k/N] file: done" line per file; leads in build/flag_sweep.tsv."""
    path = os.path.join(ST, "flag-sweep.log")
    try:
        lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    except OSError:
        return []
    running = alive("flag_sweep", path, 10)
    prog = [m for m in (re.match(r"^\[(\d+)/(\d+)\] (\S+): (.*)$", ln) for ln in lines) if m]
    if not running and not prog:
        return []
    out = [f"{col('flag_sweep', 'bold')} " + (col("trabajando", "green") if running else col("terminado", "dim"))
           + f"  (opciones por archivo, R19; log {os.path.relpath(path, MAIN)})"]
    if prog:
        k, n = int(prog[-1].group(1)), int(prog[-1].group(2))
        f = round(WIDTH * k / n)
        out.append(f"  archivos  {chr(0x2588) * f}{chr(0x2591) * (WIDTH - f)} {k}/{n}  (último: {prog[-1].group(3)})")
    return out


def qwen():
    """tools/qwen_variants.py (log build/workers/qwen.log): the local model
    proposing variants of NON_MATCHING attempts. The last run: a bar for
    its functions, one row per function (base -> best edits, round)."""
    path = os.path.join(ST, "qwen.log")
    try:
        lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
        age = time.time() - os.path.getmtime(path)
    except OSError:
        return []
    starts = [i for i, ln in enumerate(lines) if " qwen run: " in ln]
    if not starts:
        return []
    run_ = lines[starts[-1]:]
    done = any(" qwen run done" in ln for ln in run_)
    m = re.search(r"qwen run: (\d+) functions, (\d+) rounds", run_[0])
    total, rounds = (int(m.group(1)), int(m.group(2))) if m else (0, 0)
    fns = {}
    for ln in run_:
        p = re.match(r"^\S+ \[(\d+)/\d+\] (\S+) (\S+): (.*)$", ln)
        if not p:
            continue
        k, file, fn, rest = int(p.group(1)), p.group(2), p.group(3), p.group(4)
        st = fns.setdefault(k, {"name": f"{file.split('/')[-1]} {fn}", "base": None, "best": None,
                                "round": 0, "end": False, "note": ""})
        if (b := re.match(r"start, base (\d+)", rest)):
            st["base"] = st["best"] = int(b.group(1))
        if (r := re.search(r"round (\d+)/\d+ done, .*best (\d+)", rest)):
            st["round"], st["best"] = int(r.group(1)), int(r.group(2))
        if (e := re.match(r"(MATCH|end), base (\d+) -> best (\d+)", rest)):
            st["end"], st["best"] = True, int(e.group(3))
        if "skipped" in rest:
            st["end"], st["note"] = True, rest
    finished = sum(s["end"] for s in fns.values())
    state = (col("terminado", "dim") if done else col("trabajando", "green") if age < 300
             else col("parado", "yellow"))
    out = [f"{col('qwen (local)', 'bold')} {state}  (qwen2.5-coder 7B en tu GPU, sin cuota; log {os.path.relpath(path, MAIN)})"]
    f = round(WIDTH * finished / total) if total else 0
    out.append(f"  funciones  {chr(0x2588) * f}{chr(0x2591) * (WIDTH - f)} {finished}/{total}, "
               f"{rounds} rondas cada una")
    for k in sorted(fns):
        s = fns[k]
        if s["note"]:
            out.append(f"    {col('·', 'dim')} {s['name']:<36} {col(s['note'][:60], 'dim')}")
            continue
        gain = (s["base"] or 0) - (s["best"] or 0)
        mark = (col("✓", "green") if s["best"] == 0 else col("~", "yellow") if gain > 0
                else col("·", "dim"))
        now = "" if s["end"] or done else col("  ◀ ahora", "bold")
        out.append(f"    {mark} {s['name']:<36} {s['base']} → {s['best']} cambios"
                   f"  (ronda {s['round']}/{rounds}){now}")
    return out


def qwen_names():
    """tools/qwen_names.py (log build/workers/qwen-names.log): the local
    model guessing method names; the last run's bar and its result."""
    path = os.path.join(ST, "qwen-names.log")
    try:
        lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
        age = time.time() - os.path.getmtime(path)
    except OSError:
        return []
    starts = [i for i, ln in enumerate(lines) if " qwen names " in ln and "methods, model" in ln]
    if not starts:
        return []
    run_ = lines[starts[-1]:]
    m = re.search(r"qwen names (\w+): (\d+) methods", run_[0])
    kind, total = (m.group(1), int(m.group(2))) if m else ("?", 0)
    prog = [p for p in (re.match(r"^\S+ \[(\d+)/\d+\] (.*)$", ln) for ln in run_) if p]
    end = next((ln.split(" ", 1)[1] for ln in run_ if " done:" in ln), None)
    state = (col("terminado", "dim") if end else col("trabajando", "green") if age < 300 else col("parado", "yellow"))
    what = "prueba a ciegas con nombres reales" if kind == "test" else "propuestas para vfunc_NN (a revisar)"
    out = [f"{col('qwen nombres', 'bold')} {state}  ({what}; log {os.path.relpath(path, MAIN)})"]
    k = int(prog[-1].group(1)) if prog else 0
    exact = sum("(exact)" in p.group(2) for p in prog)
    f = round(WIDTH * k / total) if total else 0
    out.append(f"  métodos  {chr(0x2588) * f}{chr(0x2591) * (WIDTH - f)} {k}/{total}"
               + (f", {col(f'{exact} acertados', 'green')}" if kind == "test" else ""))
    for p in prog[-3:]:
        out.append(f"    {col('·', 'dim')} {p.group(2)[:110]}")
    if end:
        out.append(f"  {end[:150]}")
    return out


def research():
    """Research subagents (build/workers/research-R<n>.log, one "[k/N] step"
    line per step they finish, "DONE ..." at the end): the newest one."""
    logs = sorted((p for p in os.listdir(ST) if re.match(r"research-R\d+\.log$", p)),
                  key=lambda p: os.path.getmtime(os.path.join(ST, p)))
    if not logs:
        return []
    path = os.path.join(ST, logs[-1])
    lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    age = time.time() - os.path.getmtime(path)
    done = next((ln for ln in lines if ln.startswith("DONE")), None)
    prog = [p for p in (re.match(r"^\[(\d+)/(\d+)\] (.*)$", ln) for ln in lines) if p]
    state = col("terminada", "dim") if done else col("trabajando", "green") if age < 1800 else col("parada", "yellow")
    out = [f"{col('investigación ' + logs[-1][9:-4], 'bold')} {state}  (Sonnet, solo lectura; log {os.path.relpath(path, MAIN)})"]
    if prog:
        k, n = int(prog[-1].group(1)), int(prog[-1].group(2))
        f = round(WIDTH * k / n)
        out.append(f"  pasos  {chr(0x2588) * f}{chr(0x2591) * (WIDTH - f)} {k}/{n}  {prog[-1].group(3)[:70]}")
    if done:
        out.append(f"  {done[:140]}")
    return out


def twin_sweeps():
    """tools/orca/twin_sweep.sh (log build/workers/twin-sweep.log): twins
    filled with no model after each merge."""
    path = os.path.join(ST, "twin-sweep.log")
    try:
        lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    except OSError:
        return []
    running = os.path.isdir(os.path.join(ST, "twin.lock"))
    sweeps = [i for i, ln in enumerate(lines) if ln.startswith("== ") and ln.endswith(" sweep")]
    total = sum(1 for ln in lines if ln.endswith("MATCH, committed"))
    out = [f"{col('gemelas', 'bold')} " + (col("pasando", "green") if running else col("en espera", "dim"))
           + f"  (sin IA, tras cada fusi\u00f3n; log {os.path.relpath(path, MAIN)})"]
    if sweeps:
        last = lines[sweeps[-1]:]
        res = next((ln for ln in reversed(last) if re.match(r"^\d+ of \d+ twins matched", ln)), None)
        when = lines[sweeps[-1]][3:-6]
        out.append(f"  {len(sweeps)} pasadas, " + col(f"{total} gemelas sacadas", "green" if total else "dim")
                   + f"; la \u00faltima ({when}): {res or 'en curso'}")
        for ln in [ln for ln in last if ln.endswith("MATCH, committed")][-3:]:
            out.append(f"    {col(chr(0x2713), 'green')} {ln.split(' <- ')[0]}")
    return out


def EXTRA_PERM_MATCHES():
    """'(permuter)' commits in git: matches the logs may not show (--apply)."""
    out = run(["git", "-C", MAIN, "log", "--format=%s", "--grep", "(permuter)$", "pr-merge"])
    return [ln for ln in out.splitlines() if ln.endswith("(permuter)") and "MnuDiary: func_0019AE78" not in ln]


def perm_official():
    """tools/perm_official.py's queue (log build/workers/perm-official.log):
    decomp-permuter on the NON_MATCHING attempts."""
    path = os.path.join(ST, "perm-official.log")
    try:
        lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    except OSError:
        return []
    running = alive("perm_official", path, 25)
    q = [ln for ln in lines if ln.startswith("queue: ")]
    # exact ones of every run (also one taken again with --apply); the bar
    # for the last run
    all_ok = [m.group(1) for m in (re.match(r"^\[\d+/\d+\] (\S+ \S+): MATCH", ln) for ln in lines) if m]
    if q:
        lines = lines[max(i for i, ln in enumerate(lines) if ln.startswith("queue: ")):]
    ends = [re.match(r"^\[(\d+)/(\d+)\] (\S+ \S+): (MATCH|no match|skipped)(.*)$", ln) for ln in lines]
    ends = [m for m in ends if m]
    starts = [re.match(r"^\[(\d+)/(\d+)\] (\S+ \S+): start", ln) for ln in lines]
    starts = [m for m in starts if m]
    total = int(q[-1].split()[1]) if q else (int(starts[-1].group(2)) if starts else 0)
    done = len(ends)
    matches = [ln.split(" (permuter)")[0] for ln in EXTRA_PERM_MATCHES()]   # git is the record
    skipped = sum(1 for m in ends if m.group(4) == "skipped")
    out = [f"{col('decomp-permuter', 'bold')} " + (col("trabajando", "green") if running else col("parado", "yellow"))
           + f"  (sin IA; log {os.path.relpath(path, MAIN)})"]
    if not total:
        return out
    f = round(WIDTH * done / total)
    big = "\u2588" * f + "\u2591" * (WIDTH - f)
    out.append(f"  cola de 'casi'  {big} {done}/{total} probadas, "
               + col(f"{len(matches)} exactas", "green" if matches else "dim")
               + (f", {skipped} no se pudieron preparar" if skipped else ""))
    if running and starts and (not ends or int(starts[-1].group(1)) > int(ends[-1].group(1))):
        out.append(f"    \u25c0 ahora {starts[-1].group(3)}")
    for m in ends[-3:]:
        if m.group(4) != "skipped":
            mark = col(chr(0x2713), "green") if m.group(4) == "MATCH" else col("\u00b7", "dim")
            out.append(f"    {mark} {m.group(3)}: {m.group(4)}{m.group(5)}")
    return out


STALE_HOURS = 6


def recent(name, hours):
    """Whether build/workers/<name> changed in the last hours."""
    try:
        return time.time() - os.path.getmtime(os.path.join(ST, name)) < hours * 3600
    except OSError:
        return False


def render(reset=False):
    idle = terminals()
    s = session(reset)
    b, p = progress()
    out = []
    # Header: the game's progress, big.
    out.append(col(" RULE OF ROSE", "bold") + col("  ·  decompilación matching", "dim")
               + " " * 34 + col(time.strftime("%H:%M"), "dim"))
    out.append(col("─" * LINE, "dim"))
    if b is not None:
        out.append(f" {col('Juego', 'bold')}  {bar(p, 40, 'cyan')}  {col(f'{p:.2f} %', 'bold')}")
        today = ""
        if s:
            today = col(f"hoy +{p - s[2]:.2f} %  (+{b - s[1]:,} bytes)", "green")
        out.append(col(f"         {b:,} de {round(b * 100 / p):,} bytes del código del juego", "dim") + "   " + today)
    out.append("")
    # Workers: the busy ones first.
    envs = [(fn[:-4], read_env(os.path.join(ST, fn))) for fn in sorted(os.listdir(ST)) if fn.endswith(".env")]
    envs.sort(key=lambda e: e[1].get("STATUS") != "busy")
    out.append(section("WORKERS"))
    for name, env in envs:
        lines = worker(name, env, idle)
        out.extend(lines)
        if len(lines) > 1:
            out.append("")
    if out[-1]:
        out.append("")
    # The coordinator's own list (build/workers/coord-tasks.tsv, same format
    # as a worker's task list), e.g. tool fixes.
    # Shown while it has something left, or for an hour after the last change.
    coord = task_rows("coord")
    try:
        open_tasks = any(ln.split("\t")[1:2] != ["done"] for ln in
                         open(os.path.join(ST, "coord-tasks.tsv"), encoding="utf-8").read().splitlines() if ln.strip())
    except OSError:
        open_tasks = False
    if coord and (open_tasks or recent("coord-tasks.tsv", 1)):
        out.append(section("COORDINADOR (Claude)"))
        out.extend(coord)
        out.append("")
    # Background tools: only those that ran in the last hours (a running one
    # writes its log all the time); the others are history, not news.
    pq = []
    res = research()
    newest = max((p for p in os.listdir(ST) if re.match(r"research-R\d+\.log$", p)),
                 key=lambda p: os.path.getmtime(os.path.join(ST, p)), default=None)
    if res and newest and recent(newest, STALE_HOURS):
        pq += res
    for log_name, fn in (("qwen.log", qwen), ("qwen-names.log", qwen_names),
                         ("perm-official.log", perm_official), ("perm-loop.log", permuter),
                         ("auto-run.log", auto_m2c), ("twin-sweep.log", twin_sweeps),
                         ("flag-sweep.log", flag_sweep)):
        if not recent(log_name, STALE_HOURS):
            continue
        part = fn()
        if part:
            pq += ([""] if pq else []) + part
    if pq:
        out.append(section("EN SEGUNDO PLANO"))
        out.extend((" " + ln) if ln else ln for ln in pq)
        out.append("")
    # Session.
    rows = stats()
    out.append(section("SESIÓN" + (f" (desde {s[0][5:]})" if s else "")))
    if s and b is not None:
        out.append(f"   juego {s[2]:.2f} % → {col(f'{p:.2f} %', 'green')}")
    if s:
        since = [r for r in rows if r.get("time", "") >= s[0]]
        per = {}
        for r in since:
            per.setdefault(r["worker"], [0, 0])
            per[r["worker"]][0] += r["exact"]
            per[r["worker"]][1] += int(r.get("non_matching", 0) or 0)
        if per:
            out.append("   fusionadas  " + col("  ·  ", "dim").join(
                f"{SHOWN.get(w, w)} {col(str(e), 'green')}" + (col(f" (+{nm} casi)", "dim") if nm else "")
                for w, (e, nm) in sorted(per.items(), key=lambda kv: -kv[1][0])))
            out.append(col("   (sin contar las fusiones a mano de Neon: van en su lista de tareas)", "dim"))
        else:
            out.append("   fusionadas: ninguna todavía")
    by = {}
    week = time.strftime("%Y-%m-%d %H:%M", time.localtime(time.time() - 7 * 86400))
    for r in rows:
        if r.get("time", "") < week:
            continue
        m = r.get("model", "").removeprefix("auto · ").strip() or "?"
        by.setdefault(m, [0, 0, 0])
        by[m][0] += r["exact"]
        by[m][1] += r["minutes"]
        by[m][2] += int(r.get("bytes", 0) or 0)
    rank = sorted(((by_ / (mi / 60), e, mi, by_, m) for m, (e, mi, by_) in by.items() if mi >= 30), reverse=True)
    if rank:
        out.append("")
        out.append(section("RENDIMIENTO (7 días)"))
        top = rank[0][0]
        for rate, e, mi, by_, m in rank[:5]:
            out.append(f"   {m:<28} {bar(100 * rate / top, 16, 'magenta')} {rate:6,.0f} B/h"
                       + col(f"   {e} funciones en {mi / 60:.0f} h", "dim"))
    out.append("")
    out.append(col(" ✓ escrita · ~ casi · % = lo cerca que está su mejor prueba", "dim"))
    return "\n".join(out)


def main():
    if sys.platform == "win32":
        sys.stdout.reconfigure(encoding="utf-8")
        os.system("")  # turn on ANSI colours in the Windows console
    args = sys.argv[1:]
    if "--watch" in args:
        i = args.index("--watch")
        every = int(args[i + 1]) if len(args) > i + 1 else 20
        first = "--reset" in args
        while True:
            text = render(first)
            first = False
            sys.stdout.write("\x1b[2J\x1b[H\n" + text + "\n")
            sys.stdout.flush()
            time.sleep(every)
    print(render("--reset" in args))


if __name__ == "__main__":
    main()
