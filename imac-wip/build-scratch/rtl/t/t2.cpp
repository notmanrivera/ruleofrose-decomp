char *fa(char *name) { if (name) { while (*name != 0) name++; name++; } return name; }
char *fb(char *name) { if (name) { char c; do { c = *name++; } while (c); } return name; }
char *fc(char *name) { if (name) { int c; while ((c = *name++) != 0) {} } return name; }
char *fd(char *name) { if (name) { for (;;) { char c = *name++; if (!c) break; } } return name; }
char *fe(char *name) { if (name) { while (*name++ != '\0') {} } return name; }
char *ff(char *name) { if (name) { while (1) { if (*name++ == 0) break; } } return name; }
char *fg(char *name) { if (name) { int c = *name++; while (c) { c = *name++; } } return name; }
char *fh(char *name) { if (name) { while (*name) { name++; } name++; } return name; }
