struct S { char *m_name; int m_x; };
extern void g(char *);
char *f1(char *name) {
    if (name) {
        while (*name++) {
        }
    }
    return name;
}
void f2(S *s, int n) {
    char *name = s->m_name;
    for (int i = 0; i < n; i++) {
        g(name);
        if (name) {
            while (*name++) {
            }
        }
    }
}
