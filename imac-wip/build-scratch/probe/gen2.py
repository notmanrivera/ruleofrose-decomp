head = "extern void f(int, int);\nextern int h();\nvoid g(int a, int t)\n{\n    if (a >= 0) { h(); } else { h(); }\n"
def mk(name, body):
    open(name + ".cpp", "w").write(head + body + "    f(a, type);\n}\n")
mk("w_deffirst", """    int type;
    switch (t) {
    default: type = 0; break;
    case 0: case 1: case 2: case 3: type = t; break;
    case 'NORM': type = 0; break;
    case 'PC02': type = 1; break;
    case 'JNFC': type = 2; break;
    case 'PC05': type = 3; break;
    case 'RMAL': type = 0; break;
    }
""")
mk("w_shared", """    int type;
    switch (t) {
    case 0: case 1: case 2: case 3: type = t; break;
    case 'PC02': type = 1; break;
    case 'JNFC': type = 2; break;
    case 'PC05': type = 3; break;
    case 'NORM': case 'RMAL': default: type = 0; break;
    }
""")
mk("w_base", """    int type;
    switch (t) {
    case 0: case 1: case 2: case 3: type = t; break;
    case 'NORM': type = 0; break;
    case 'PC02': type = 1; break;
    case 'JNFC': type = 2; break;
    case 'PC05': type = 3; break;
    case 'RMAL': type = 0; break;
    default: type = 0; break;
    }
""")
