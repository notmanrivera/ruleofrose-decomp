import sys
head = "extern void f(int, int);\nvoid g(int a, int t)\n{\n"
cases = [("case 0: case 1: case 2: case 3:", "t"), ("case 'NORM':", "0"), ("case 'PC02':", "1"), ("case 'JNFC':", "2"), ("case 'PC05':", "3"), ("case 'RMAL':", "0"), ("default:", "0")]
def mk(name, body):
    open(name + ".cpp", "w").write(head + body + "}\n")
def sw(fmt, var="type", pre="    int type;\n", post="    f(a, type);\n", skip=()):
    s = pre + "    switch (t) {\n"
    for lab, val in cases:
        if lab in skip: s += "    %s break;\n" % lab; continue
        s += "    %s %s break;\n" % (lab, fmt % val)
    return s + "    }\n" + post
mk("v_goto", "    int type;\n    switch (t) {\n" + "".join("    %s type = %s; goto done;\n" % (l, v) for l, v in cases) + "    }\ndone:\n    f(a, type);\n")
mk("v_ret_inl", "".join([]) + "    f(a, ({ int r; switch (t) { " + " ".join("%s r = %s; break;" % (l, v) for l, v in cases) + " } r; }));\n")
mk("v_ptr", sw("*p = %s;", pre="    int type; int *p = &type;\n"))
mk("v_short", sw("type = %s;", pre="    short type;\n"))
mk("v_if", "    int type;\n    if (t >= 0 && t <= 3) type = t;\n    else switch (t) {\n" + "".join("    %s type = %s; break;\n" % (l, v) for l, v in cases[1:]) + "    }\n    f(a, type);\n")
mk("v_param", sw("t = %s;", pre="", post="    f(a, t);\n", skip=("case 0: case 1: case 2: case 3:",)).replace("case 0: case 1: case 2: case 3: break;", "case 0: case 1: case 2: case 3: break;"))
