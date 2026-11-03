struct S { int x[100]; void f(int, int); };
struct T { int pad[30]; S s; void g(int a, int t); };
void T::g(int a, int t)
{
    switch (t) {
    case 0: case 1: case 2: case 3: s.f(a, t); break;
    case 'NORM': s.f(a, 0); break;
    case 'PC02': s.f(a, 1); break;
    case 'JNFC': s.f(a, 2); break;
    case 'PC05': s.f(a, 3); break;
    case 'RMAL': s.f(a, 0); break;
    default: s.f(a, 0); break;
    }
}
