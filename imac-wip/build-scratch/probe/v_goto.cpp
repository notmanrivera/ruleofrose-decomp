extern void f(int, int);
void g(int a, int t)
{
    int type;
    switch (t) {
    case 0: case 1: case 2: case 3: type = t; goto done;
    case 'NORM': type = 0; goto done;
    case 'PC02': type = 1; goto done;
    case 'JNFC': type = 2; goto done;
    case 'PC05': type = 3; goto done;
    case 'RMAL': type = 0; goto done;
    default: type = 0; goto done;
    }
done:
    f(a, type);
}
