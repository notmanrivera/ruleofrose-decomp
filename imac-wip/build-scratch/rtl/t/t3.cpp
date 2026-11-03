extern "C" void ror_assert(const char *, int, const char *);
#define ASSERT(e) ((e) ? (void)0 : ror_assert(__FILE__, __LINE__, #e))
const char *b730(void *r, unsigned short i);
int b3d8(void *r, const char *p);
struct M { void *root; int a[7]; };
struct A {
    int max; M *md; short *tbl; void *r3;
    const char *gnn(int n, int i) { ASSERT(n>=0 & n<max); ASSERT(md); ASSERT(md[n].root); ASSERT(0<=i); return b730(md[n].root, i); }
    int gni(const char *p) { ASSERT(r3); ASSERT(p); return b3d8(r3, p); }
    int f1(int no);
    int f2(int no);
};
int A::f1(int no) {
    int num = no; short *p = tbl; int err = 0; *p++ = num;
    for (int i = 0; i < num; ) {
        short *q = p++;
        int node = gni(gnn(no, i++));
        if (node < 0) { node = -1; err++; }
        *q = node;
    }
    return err;
}
int A::f2(int no) {
    int num = no; short *p = tbl; int err = 0; *p++ = num;
    for (int i = 0; i < num; i++) {
        int node = gni(gnn(no, i));
        if (node < 0) { node = -1; err++; }
        *p++ = node;
    }
    return err;
}
