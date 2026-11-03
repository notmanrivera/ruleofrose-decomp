"""rtlshow.py DUMP FUNC [fromuid]: compact view of a function's insns in an RTL dump."""
import re, sys
dump, func = sys.argv[1:3]
start = int(sys.argv[3]) if len(sys.argv) > 3 else 0
text = open(dump).read()
i = text.index(f";; Function {func}")
j = text.find("\n;; Function ", i + 1)
body = text[i:j if j > 0 else len(text)]
# split into top-level s-expressions starting with "(insn" "(call_insn" "(jump_insn" "(code_label" "(note"
items = re.split(r"\n(?=\((?:insn|call_insn|jump_insn|code_label|note|barrier) )", body)
for it in items:
    m = re.match(r"\((\w+) (\d+)", it)
    if not m:
        continue
    kind, uid = m.group(1), int(m.group(2))
    if uid < start:
        continue
    flat = re.sub(r"\s+", " ", it)
    if kind == "note":
        if "NOTE_INSN_BASIC_BLOCK" in flat or "LOOP" in flat:
            print(flat[:80])
        continue
    # drop the uid chain
    flat = re.sub(r"^\((\w+) (\d+) (\d+) (\d+) ", r"\1 \2: ", flat)
    print(flat[:400])
