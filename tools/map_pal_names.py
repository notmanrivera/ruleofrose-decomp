"""Map RoR-Port's PAL (SLES-542.18) hand names to NTSC addresses: for each
name, the delta that puts the most of its 7 nearest neighbours (by PAL
address) on our function starts; accepted when at least 5 of 7 agree and
the name itself lands on a start. Writes build/ror_port_names.tsv
(not committed: a lead list, the names are descriptive and GPL-sourced)."""
import csv, glob, collections, os, pickle, re
starts = pickle.load(open('build/func_starts.pkl', 'rb'))
srcs = {}
for l in open('symbols/function_sources.tsv', encoding='utf8').read().splitlines()[1:]:
    w = l.split('\t')
    srcs[int(w[0], 16)] = w[2] if len(w) > 2 else ''
syms = {int(r['addr'], 16): r for r in csv.DictReader(open('symbols/ghidra_symbols.tsv', encoding='utf8'), delimiter='\t')}
rows = []
for f in sorted(glob.glob('../ext/ror-port/tools/ghidra_scripts/names/*.csv')):
    for line in open(f, encoding='utf8'):
        if line.startswith(('#', 'address')) or not line.strip():
            continue
        w = next(csv.reader([line]))
        try:
            a = int(w[0], 16)
        except ValueError:
            continue
        rows.append((a, w[1], w[2], w[4] if len(w) > 4 else '', os.path.basename(f)))
rows.sort()
deltas = range(-0x8000, 0x8001, 4)
out, stat = [], collections.Counter()
for i, (a, ns, n, ev, f) in enumerate(rows):
    nb = [r[0] for r in rows[max(0, i - 3):i + 4]]
    best = max(deltas, key=lambda d: (sum((x + d) in starts for x in nb), -abs(d)))
    agree = sum((x + best) in starts for x in nb)
    b = a + best
    if b in starts and agree >= min(5, len(nb)):
        ours = starts[b]
        s = syms.get(b, {})
        out.append((b, a, best, f'{ns}::{n}' if ns else n, ours, s.get('class', ''), srcs.get(b, ''), ev[:160], f))
        stat['mapped'] += 1
        stat['ours named' if not re.fullmatch(r'func_[0-9A-F]{8}', ours) else 'ours unnamed'] += 1
    else:
        stat['not mapped'] += 1
with open('build/ror_port_names.tsv', 'w', encoding='utf8', newline='\n') as o:
    o.write('ntsc\tpal\tdelta\ttheir_name\tour_symbol\tour_class\tour_source\tevidence\tfile\n')
    for r in out:
        o.write(f'{r[0]:08X}\t{r[1]:08X}\t{r[2]:+#x}\t' + '\t'.join(r[3:]) + '\n')
print(stat)
# validation: names whose evidence cites a source path vs our source tag
ok = bad = 0
for b, a, d, n, ours, cls, src, ev, f in out:
    m = re.search(r'([a-z]+/[a-z_0-9]+\.cpp)', ev)
    if m and src:
        if m.group(1) in src: ok += 1
        else:
            bad += 1
            print('SRC MISMATCH', hex(b), n, m.group(1), '| ours', src)
print('source check: agree', ok, 'disagree', bad)
# class check
cok = cbad = 0
for b, a, d, n, ours, cls, src, ev, f in out:
    if '::' in n and cls:
        if n.split('::')[0] == cls: cok += 1
        else:
            cbad += 1
            print('CLASS MISMATCH', hex(b), n, '| ours', cls, ours)
print('class check: agree', cok, 'disagree', cbad)
