extern void f(int, int);
extern int h();
void g(int a, int t)
{
    if (a >= 0) { h(); } else { h(); }
    int type;
    switch (t) {
    default: type = 0; break;
    case 0: case 1: case 2: case 3: type = t; break;
    case 'NORM': type = 0; break;
    case 'PC02': type = 1; break;
    case 'JNFC': type = 2; break;
    case 'PC05': type = 3; break;
    case 'RMAL': type = 0; break;
    }
    f(a, type);
}
