extern void f(int, int);
void g(int a, int t)
{
    int type; int *p = &type;
    switch (t) {
    case 0: case 1: case 2: case 3: *p = t; break;
    case 'NORM': *p = 0; break;
    case 'PC02': *p = 1; break;
    case 'JNFC': *p = 2; break;
    case 'PC05': *p = 3; break;
    case 'RMAL': *p = 0; break;
    default: *p = 0; break;
    }
    f(a, type);
}
