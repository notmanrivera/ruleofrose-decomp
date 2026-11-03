extern void f(int, int);
void g(int a, int t)
{
    f(a, ({ int r; switch (t) { case 0: case 1: case 2: case 3: r = t; break; case 'NORM': r = 0; break; case 'PC02': r = 1; break; case 'JNFC': r = 2; break; case 'PC05': r = 3; break; case 'RMAL': r = 0; break; default: r = 0; break; } r; }));
}
