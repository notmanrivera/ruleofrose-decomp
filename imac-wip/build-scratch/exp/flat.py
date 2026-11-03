import re, sys
# flatten RTL insns of one function from a dump file into one line each
path, func = sys.argv[1], sys.argv[2]
text = open(path).read()
start = text.index(';; Function ' + func)
end = text.find('\n;; Function ', start + 1)
body = text[start:end if end > 0 else None]
insns = re.split(r'\n\n', body)
for ins in insns:
    one = ' '.join(ins.split())
    if one.startswith('(insn') or one.startswith('(jump_insn') or one.startswith('(call_insn'):
        print(one[:260])
