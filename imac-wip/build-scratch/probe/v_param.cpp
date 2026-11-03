extern void f(int, int);
void g(int a, int t)
{
    switch (t) {
    case 0: case 1: case 2: case 3: break;
    case 'NORM': t = 0; break;
    case 'PC02': t = 1; break;
    case 'JNFC': t = 2; break;
    case 'PC05': t = 3; break;
    case 'RMAL': t = 0; break;
    default: t = 0; break;
    }
    f(a, t);
}
