extern "C" void use(const void *);
extern "C" const char *str8()  { return "abcdefg"; }
extern "C" const char *str12() { return "abcdefghijk"; }
extern "C" const char *str15() { return "game/gamsnd.cp"; }
extern "C" const char *str16() { return "game/gamsnd.cpp"; }
extern "C" const char *str17() { return "game/gamsnd.cppx"; }
extern "C" const char *str32() { return "0123456789abcdef0123456789abcde"; }
static const char arr4[] = "abc";
static const char arr16[] = "game/gamsnd.cpp";
static const char arr20[] = "0123456789abcdefghi";
static const int ints2[] = { 1, 2 };
static const int ints4[] = { 1, 2, 3, 4 };
static const int ints8[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
static const short sh4[] = { 1, 2, 3, 4 };
static const double dbl1[] = { 1.5 };
static const float flt4[] = { 1.5f, 2.5f, 3.5f, 4.5f };
struct S12 { int a, b, c; };
static const S12 s12 = { 1, 2, 3 };
extern "C" void useall() { use(arr4); use(arr16); use(arr20); use(ints2); use(ints4); use(ints8); use(sh4); use(dbl1); use(flt4); use(&s12); }
extern "C" double dlit(double x) { return x * 3.25; }
extern "C" float flit(float x) { return x * 3.25f; }
extern "C" int sw(int x) { switch (x) { case 0: return 4; case 1: return 9; case 2: return 13; case 3: return 11; case 4: return 7; case 5: return 2; default: return -1; } }
