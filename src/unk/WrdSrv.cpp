#include "include_asm.h"
extern "C" int Xii_func_0017E9D0(int) asm("func_0017E9D0");
extern "C" int Xiiii_alloc__9BedMemoryii(int, int, int) asm("alloc__9BedMemoryii");
extern "C" int Xiiii_memcpy(int, int, int) asm("memcpy");
extern "C" int Xiiii_memset(int, int, int) asm("memset");
extern "C" int Xiii_free__9BedMemoryPv(int, int) asm("free__9BedMemoryPv");
extern int D_006E9800;
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
extern "C" int Xiii_func_0017EA44(int, int) asm("func_0017EA44");
// Translated mechanically from m2c drafts: only what matches byte for byte.
extern "C" int X_WrdSrv__vfunc_01(...) asm("WrdSrv__vfunc_01");
extern "C" int X_func_0017E3D8(...) asm("func_0017E3D8");
extern "C" int X_func_0017E540(...) asm("func_0017E540");
extern "C" int X_func_0017F038(...) asm("func_0017F038");
extern "C" int X_memcmp(...) asm("memcmp");
extern "C" int X_strcmp(...) asm("strcmp");
extern "C" int X_strlen(...) asm("strlen");
extern int D_00298EE0;

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C60C);

extern "C" void func_0017C754(int arg0)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 0) & 2) {
        temp_v0 = M2C_FIELD(arg0, int *, 4);
        if (temp_v0 != 0) {
            Xiii_free__9BedMemoryPv((int) (int)&D_006E9800, temp_v0);
        }
    }
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C7B0);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C814);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C844);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C8B8);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C994);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CAA8);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CB50);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CC68);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CCE8);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CE74);

// NON_MATCHING: 203/226 differ, 2 relocs differ (size 0x388, game 0x38C), 165 edits
#ifdef NON_MATCHING
extern "C" void *CF0C_zero(void *, int, unsigned int) asm("memset");
extern "C" void CF0C_clear(int) asm("func_0017DFA8");
extern "C" int func_0017CF0C(int arg0, int arg1, int arg2, int arg3)
{
    int lists[128];
    int counts[2];

    int startOffset = arg2 << 7;
    if (arg1 == arg2) {
        M2C_FIELD(arg3, int *, 0xFC) = 1;
        M2C_FIELD(arg3, int *, 0) = M2C_FIELD(arg0, int *, 8) + startOffset;
        return 1;
    }
    register int *countPtr PS2_REG("$16") = counts;
    CF0C_zero(countPtr, 0, 8);
    int current = 0;
    int limit = M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 4) + 1;
    CF0C_clear(arg0);
    int start = M2C_FIELD(arg0, int *, 8) + startOffset;
    M2C_FIELD(start, int *, 0x64) = 0;
    M2C_FIELD(start, int *, 0x5C) = M2C_FIELD(start, int *, 0x5C) | 0x80000000;
    lists[0] = arg2;
    countPtr[0] = 1;
    do {
        int n = 0;
        if (countPtr[current] > 0) {
            do {
                int node = M2C_FIELD(arg0, int *, 8) + (lists[(current << 6) + n] << 7);
                if (M2C_FIELD(node, int *, 0) != arg1 && M2C_FIELD(node, int *, 0x64) < limit) {
                    int edges = node + 4;
                    int edge = 0;
                    if (M2C_FIELD(edges, int *, 0) != -1) {
                        do {
                            int other = M2C_FIELD(arg0, int *, 8) + (M2C_FIELD(edges + edge * 4, int *, 0) << 7);
                            int flags = M2C_FIELD(other, int *, 0x5C);
                            if (flags >= 0 || M2C_FIELD(node, int *, 0x64) + 1 < M2C_FIELD(other, int *, 0x64)) {
                                int i;
                                for (i = 0; i < countPtr[current]; i++) {
                                    if (lists[(current << 6) + i] == M2C_FIELD(other, int *, 0)) break;
                                }
                                if (i >= countPtr[current]) {
                                    int id = M2C_FIELD(other, int *, 0);
                                    M2C_FIELD(other, int *, 0x5C) = flags | 0x80000000;
                                    int distance = M2C_FIELD(node, int *, 0x64) + 1;
                                    M2C_FIELD(other, int *, 0x64) = distance;
                                    M2C_FIELD(other, int *, 0x68) = M2C_FIELD(node, int *, 0);
                                    if (id == arg1) {
                                        limit = distance;
                                        break;
                                    } else {
                                        int alternate = current ^ 1;
                                        for (i = 0; i < countPtr[alternate]; i++) {
                                            if (lists[(alternate << 6) + i] == id) break;
                                        }
                                        if (i == countPtr[alternate]) {
                                            lists[(alternate << 6) + i] = M2C_FIELD(other, int *, 0);
                                            countPtr[alternate] = i + 1;
                                        }
                                        current = alternate ^ 1;
                                    }
                                }
                            }
                            edge++;
                        } while (M2C_FIELD(edges + edge * 4, int *, 0) != -1);
                    }
                }
                n++;
            } while (n < countPtr[current]);
        }
        int previous = current;
        current ^= 1;
        countPtr[previous] = 0;
    } while (countPtr[current] > 0);
    int result = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 4) >= limit) {
        M2C_FIELD(arg3, int *, 0xFC) = 0;
        int offset = arg1 << 7;
        for (;;) {
            int node = M2C_FIELD(arg0, int *, 8) + offset;
            if (M2C_FIELD(node, int *, 0) == arg2) {
                int count = M2C_FIELD(arg3, int *, 0xFC);
                M2C_FIELD(arg3 + count * 4, int *, 0) = node;
                M2C_FIELD(arg3, int *, 0xFC) = count + 1;
                result = 1;
                break;
            }
            int count = M2C_FIELD(arg3, int *, 0xFC);
            M2C_FIELD(arg3 + count * 4, int *, 0) = node;
            M2C_FIELD(arg3, int *, 0xFC) = count + 1;
            offset = M2C_FIELD(node, int *, 0x68) << 7;
        }
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017CF0C);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017D298);

// NON_MATCHING: 124/174 differ, 1 reloc differs (size 0x2B8, game 0x2D0), 67 edits
#ifdef NON_MATCHING
extern "C" int Xiii_func_0017D62C(int, int) asm("func_0017D62C");
extern "C" int Xiii_func_0017D9AC(int, int) asm("func_0017D9AC");
extern "C" int Xiii_func_0017DFF0(int, int) asm("func_0017DFF0");
struct InitD35C { int data[9]; };
struct PartD35C { int data[8]; };
struct StateD35C { PartD35C first; PartD35C second; int last; };
extern const InitD35C D_002F30A0;
extern "C" void func_0017D35C(int arg0, int arg1)
{
    struct { InitD35C initial; char pad24[12]; int sp30; int sp34; StateD35C current; StateD35C next; } stack;
    int temp_a1, temp_v1_3, var_s3, var_s4, var_v1;
    int var_s1, temp_a0, temp_v0, temp_v1, temp_v1_2, var_a0;    temp_a1 = M2C_FIELD(arg1, int *, 0);
    if (temp_a1 == M2C_FIELD(arg1, int *, 4)) {
        M2C_FIELD(M2C_FIELD(arg1, int *, 0xC), int *, 0) = (int) (M2C_FIELD(arg0, int *, 0xC) + (temp_a1 * 0x90));
        M2C_FIELD(M2C_FIELD(arg1, int *, 0xC), int *, 0x1FC) = 1;
        return;
    }
    var_s4 = 1;
    var_s3 = 1;
    Xiii_func_0017DFF0(arg0, M2C_FIELD(arg1, int *, 8));
    temp_v1 = (M2C_FIELD(arg1, int *, 0) * 0x90) + M2C_FIELD(arg0, int *, 0xC);
    M2C_FIELD(temp_v1, int *, 0x7C) = (int) (M2C_FIELD(temp_v1, int *, 0x7C) | 0x80000000);
    M2C_FIELD(((M2C_FIELD(arg1, int *, 0) * 0x90) + M2C_FIELD(arg0, int *, 0xC)), int *, 0x80) = 0;
    int target = (M2C_FIELD(arg1, int *, 0) * 0x90) + M2C_FIELD(arg0, int *, 0xC);
    register int one PS2_REG("$7") = 1;
    stack.initial = D_002F30A0;
    M2C_FIELD(target, int *, 0x88) = (int)&stack.initial;
    stack.current.last = one;
    var_s1 = M2C_FIELD(arg1, int *, 8) + 4;
    stack.current.first.data[0] = M2C_FIELD(arg1, int *, 0);
    while (var_s3++ < M2C_FIELD(M2C_FIELD(arg1, int *, 8), int *, 0xFC)) {
        temp_v0 = (*(int *)(var_s1));
        var_s1 += 4;
        stack.sp30 = (*(int *)(temp_v0));
        if (Xiii_func_0017D62C(arg0, (int)&stack.sp30) == 0) {
            var_s4 = 0;
            break;
        } else {
            stack.current.first = stack.next.first;
            stack.current.second = stack.next.second;
            stack.current.last = stack.next.last;

        }
    }
    if (var_s4 != 0) {
        stack.sp34 = M2C_FIELD(arg1, int *, 4);
        Xiii_func_0017D9AC(arg0, (int)&stack.sp30);
    }
    M2C_FIELD(M2C_FIELD(arg1, int *, 0xC), int *, 0x1FC) = 1;
    var_v1 = stack.sp34;
loop_11:
    temp_a0 = M2C_FIELD(arg0, int *, 0xC) + (var_v1 * 0x90);
    temp_v1_2 = M2C_FIELD(arg1, int *, 0xC);
    if (M2C_FIELD(temp_a0, int *, 0) != M2C_FIELD(arg1, int *, 0)) {
        M2C_FIELD(temp_v1_2, int *, 0x1FC) = (int) (M2C_FIELD(temp_v1_2, int *, 0x1FC) + 1);
        var_v1 = M2C_FIELD(temp_a0, int *, 0x84);
        goto loop_11;
    }
    var_s3 = M2C_FIELD(temp_v1_2, int *, 0x1FC) - 1;
    var_a0 = M2C_FIELD(arg0, int *, 0xC) + (stack.sp34 * 0x90);
    if (var_s3 >= 0) {
        do {
            temp_v1_3 = var_s3 * 4;
            var_s3 -= 1;
            *(int *)(M2C_FIELD(arg1, int *, 0xC) + temp_v1_3) = var_a0;
            var_a0 = M2C_FIELD(arg0, int *, 0xC) + (M2C_FIELD(var_a0, int *, 0x84) * 0x90);
        } while (var_s3 >= 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017D35C);
#endif

// NON_MATCHING: 162/221 differ, 1 reloc differs (size 0x374, game 0x380), 110 edits
#ifdef NON_MATCHING
struct NeighborD62C { int data[6]; };
extern NeighborD62C D_00298E20[];
extern "C" void *D62C_set(void *, int, unsigned int) asm("memset");
extern "C" void *D62C_copy(void *, const void *, unsigned int) asm("memcpy");
extern "C" int func_0017D62C(int object, int state)
{
    register int arg0 PS2_REG("$19") = object;
    register int arg1 PS2_REG("$17") = state;
    int lists[2][32];
    int counts[2];
    register int *count PS2_REG("$16") = counts;
    register int best PS2_REG("$18") = 0;
    D62C_set(count, 0, 8);
    D62C_copy(lists, (void *)(arg1 + 8), M2C_FIELD(arg1, int *, 0x48) * 4);
    M2C_FIELD(arg1, int *, 0x8C) = 0;
    count[0] = M2C_FIELD(arg1, int *, 0x48);
    int current = 0;
    do {
        int n = 0;
        if (count[current] > 0) {
            do {
                int node = M2C_FIELD(arg0, int *, 0xC) + lists[current][n] * 0x90;
                int *edges = M2C_FIELD(node, int **, 0x88);
                if (*edges != -1) {
                    do {
                        int bounds = node + 0xC;
                        int edge = *edges;
                        int next = M2C_FIELD(bounds + edge * 4, int *, 0x30);
                        if (next != -1) {
                            int other = M2C_FIELD(arg0, int *, 0xC) + next * 0x90;
                            int group = M2C_FIELD(other, int *, 4);
                            if (group == M2C_FIELD(node, int *, 4) || group == M2C_FIELD(arg1, int *, 0)) {
                                int flags = M2C_FIELD(other, int *, 0x7C);
                                int visited = flags & 0x80000000;
                                if (visited == 0 || !(M2C_FIELD(other, float *, 0x80) <= M2C_FIELD(node, float *, 0x80) + M2C_FIELD(bounds + edge * 4, float *, 0x50))) {
                                    if (M2C_FIELD(other, int *, 8) & 4) {
                                        M2C_FIELD(other, int *, 0x7C) = flags | 0x80000000;
                                        if (best == 0 || M2C_FIELD(node, float *, 0x80) < M2C_FIELD(best, float *, 0x80)) best = node;
                                    } else {
                                        int alternate;
                                        if (group == M2C_FIELD(arg1, int *, 0)) {
                                            if (visited == 0) {
                                                int count = M2C_FIELD(arg1, int *, 0x8C);
                                                M2C_FIELD(arg1 + count * 4, int *, 0x4C) = M2C_FIELD(other, int *, 0);
                                                M2C_FIELD(arg1, int *, 0x8C) = count + 1;
                                            }
                                            goto update_node;
                                        }
                                        int i;
                                        for (i = 0; i < count[current]; i++) {
                                            if (lists[current][i] == M2C_FIELD(other, int *, 0)) break;
                                        }
                                        if (i >= count[current]) {
                                            alternate = current ^ 1;
                                            for (i = 0; i < count[alternate]; i++) {
                                                if (lists[alternate][i] == M2C_FIELD(other, int *, 0)) break;
                                            }
                                            if (i == count[alternate]) {
                                                lists[alternate][i] = M2C_FIELD(other, int *, 0);
                                                count[alternate] = i + 1;
                                            }
                                            current = alternate ^ 1;
update_node:
                                            M2C_FIELD(other, int *, 0x7C) = M2C_FIELD(other, int *, 0x7C) | 0x80000000;
                                            M2C_FIELD(other, float *, 0x80) = M2C_FIELD(node, float *, 0x80) + M2C_FIELD(bounds + *edges * 4, float *, 0x50);
                                            M2C_FIELD(other, int *, 0x84) = M2C_FIELD(node, int *, 0);
                                            M2C_FIELD(other, NeighborD62C **, 0x88) = &D_00298E20[*edges];
                                        }
                                    }
                                }
                            }
                        }
                        edges++;
                    } while (*edges != -1);
                }
                n++;
            } while (n < count[current]);
        }
        int previous = current;
        current ^= 1;
        count[previous] = 0;
    } while (count[current] > 0);
    int result = 1;
    if (M2C_FIELD(arg1, int *, 0x8C) <= 0) {
        result = 0;
        M2C_FIELD(arg1, int *, 4) = M2C_FIELD(best, int *, 0);
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017D62C);
#endif

// NON_MATCHING: 161/230 differ (size 0x398, game 0x3B0), 141 edits
#ifdef NON_MATCHING
struct NeighborD9AC { int data[6]; };
extern NeighborD9AC D9AC_neighbors[] asm("D_00298E20");
extern "C" void *D9AC_zero(void *, int, unsigned int) asm("memset");
extern "C" void *D9AC_copy(void *, const void *, unsigned int) asm("memcpy");
extern "C" int func_0017D9AC(int arg0, int arg1)
{
    int lists[64];
    int counts[2];
    register int *countPtr PS2_REG("$16") = counts;
    int *starts = (int *)(arg1 + 8);
    D9AC_zero(countPtr, 0, 8);
    D9AC_copy(lists, starts, M2C_FIELD(arg1, int *, 0x48) * 4);
    M2C_FIELD(arg1, int *, 0x8C) = 0;
    register int best PS2_REG("$14") = 0;
    countPtr[0] = M2C_FIELD(arg1, int *, 0x48);
    register int current PS2_REG("$9") = 0;
    register int reached PS2_REG("$15") = 0;
    do {
        register int n PS2_REG("$12") = 0;
        if (countPtr[current] > 0) {
            do {
                int node = M2C_FIELD(arg0, int *, 0xC) + lists[(current << 5) + n] * 0x90;
                if (M2C_FIELD(node, int *, 0) == M2C_FIELD(arg1, int *, 4)) reached = 1;
                else {
                    int *edges = M2C_FIELD(node, int **, 0x88);
                    while (*edges != -1) {
                        int bounds = node + 0xC;
                        int edge = *edges;
                        int next = M2C_FIELD(bounds + edge * 4, int *, 0x30);
                        if (next != -1) {
                            int other = M2C_FIELD(arg0, int *, 0xC) + next * 0x90;
                            if (M2C_FIELD(other, int *, 4) == M2C_FIELD(node, int *, 4)) {
                                int flags = M2C_FIELD(other, int *, 0x7C);
                                if (flags >= 0 || !(M2C_FIELD(other, float *, 0x80) <= M2C_FIELD(node, float *, 0x80) + M2C_FIELD(bounds + edge * 4, float *, 0x50))) {
                                    M2C_FIELD(other, int *, 0x7C) = flags | 0x80000000;
                                    int id = M2C_FIELD(other, int *, 0);
                                    M2C_FIELD(other, float *, 0x80) = M2C_FIELD(node, float *, 0x80) + M2C_FIELD(bounds + *edges * 4, float *, 0x50);
                                    M2C_FIELD(other, int *, 0x84) = M2C_FIELD(node, int *, 0);
                                    M2C_FIELD(other, NeighborD9AC **, 0x88) = &D9AC_neighbors[*edges];
                                    int target = M2C_FIELD(arg1, int *, 4);
                                    if (M2C_FIELD(other, int *, 8) & 4) {
                                        if (best == 0 || M2C_FIELD(node, float *, 0x80) < M2C_FIELD(best, float *, 0x80)) best = node;
                                        if (id == target) break;
                                    } else {
                                        if (id == target) { reached = 1; break; }
                                        int i;
                                        for (i = 0; i < countPtr[current]; i++) {
                                            if (lists[(current << 5) + i] == id) break;
                                        }
                                        if (i >= countPtr[current]) {
                                            int alternate = current ^ 1;
                                            for (i = 0; i < countPtr[alternate]; i++) {
                                                if (lists[(alternate << 5) + i] == M2C_FIELD(other, int *, 0)) break;
                                            }
                                            if (i == countPtr[alternate]) {
                                                lists[(alternate << 5) + i] = M2C_FIELD(other, int *, 0);
                                                countPtr[alternate] = i + 1;
                                            }
                                            current = alternate ^ 1;
                                        }
                                    }
                                }
                            }
                        }
                        edges++;
                    }
                }
                n++;
            } while (n < countPtr[current]);
        }
        int previous = current;
        current ^= 1;
        countPtr[previous] = 0;
    } while (countPtr[current] > 0);
    int result = 1;
    if (reached == 0) {
        int id;
        if (best == 0) {
            int n = 1;
            int count = M2C_FIELD(arg1, int *, 0x48);
            int base = M2C_FIELD(arg0, int *, 0xC);
            int selected = base + M2C_FIELD(arg1, int *, 8) * 0x90;
            if (count > 1) {
                do {
                    int candidate = starts[n] * 0x90 + base;
                    n++;
                    if (M2C_FIELD(candidate, float *, 0x80) < M2C_FIELD(selected, float *, 0x80)) selected = candidate;
                } while (n < count);
            }
            id = M2C_FIELD(selected, int *, 0);
        } else id = M2C_FIELD(best, int *, 0);
        M2C_FIELD(arg1, int *, 4) = id;
        result = 0;
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017D9AC);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017DD5C);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017DED0);

extern "C" void func_0017DFA8(int arg0)
{
    int var_a2;
    int var_a1;

    var_a2 = 0;
    var_a1 = (*(int *)(int *)((char *)(arg0) + 0x8));
    if ((*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x4))) + 0x4)) > 0) {
        do {
            var_a2 += 1;
            (*(int *)(int *)((char *)(var_a1) + 0x5C)) = (int) ((*(int *)(int *)((char *)(var_a1) + 0x5C)) & 0x7FFFFFFF);
            var_a1 += 0x80;
        } while (var_a2 < (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x4))) + 0x4)));
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017DFF0);

// NON_MATCHING: 115/201 differ, 1 reloc differs (size 0x324, game 0x330), 64 edits
#ifdef NON_MATCHING
struct EdgeE0A8 { int axis, other, boundary, low, high; };
struct TableE0A8 { EdgeE0A8 edges[4]; };
extern const TableE0A8 D_002F30C8;
extern "C" int FE0A8_find(int, const float *, int, float) asm("func_0017C8B8");
extern "C" int func_0017E0A8(int arg0, const float *arg1, const float *arg2, float distance)
{
    TableE0A8 table;
    int order[2];
    float delta[4];
    int node = FE0A8_find(arg0, arg1, 0, distance);
    int end = FE0A8_find(arg0, arg2, 0, distance);
    if (node != 0) {
        if (end != 0) {
            table = D_002F30C8;
            float x = arg1[0];
            float ex = arg2[0];
            float ez = arg2[2];
            float z = arg1[2];
            delta[0] = ex - x;
            delta[2] = ez - z;
            int a = 1;
            if (!(x <= ex)) a = 3;
            order[0] = a;
            int b = 0;
            if (!(z <= ez)) b = 2;
            order[1] = b;
            float dz = delta[2];
            if (dz < 0.0f) dz = -dz;
            if (delta[0] < 0.0f) {
                if (-delta[0] < dz) goto swap_order;
            } else if (delta[0] < dz) {
swap_order:
                int t = order[1]; order[1] = order[0]; order[0] = t;
            }
loop_node:
            {
                if (M2C_FIELD(node, int *, 8) & 4) return 0;
                int i = 0;
                    for (;;) {
                    int bounds = node + 0xC;
                    EdgeE0A8 *edge = &table.edges[order[i]];
                    int axis = edge->axis;
                    float f = (M2C_FIELD(bounds + edge->boundary * 4, float *, 0x10) - arg1[axis]) / delta[axis];
                    if (f >= 1.0f) { i = 2; }
                    else {
                        int other = edge->other;
                        float v = arg1[other] + delta[other] * f;
                        if (!(M2C_FIELD(bounds + edge->low * 4, float *, 0x10) <= v) || !(v <= M2C_FIELD(bounds + edge->high * 4, float *, 0x10))) {
                            i++;
                            if (i < 2) continue;
                        }
                    }
                    if (i != 2) {
                        int next = M2C_FIELD(bounds + order[i] * 4, int *, 0x30);
                        if (next == -1) return 0;
                        node = M2C_FIELD(arg0, int *, 0xC) + next * 0x90;
                        goto loop_node;
                    }
                    return M2C_FIELD(node, int *, 0) == M2C_FIELD(end, int *, 0);
                }
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E0A8);
#endif

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E3D8);

extern "C" void func_0017E464(int arg0, int arg1, int arg2)
{
    int temp_v0_2;
    int var_a1;
    int temp_v0;
    int temp_v1;

    temp_v0 = X_func_0017E3D8();
    if (temp_v0 != 0) {
        var_a1 = 0;
        if ((*(int *)(int *)((char *)(temp_v0) + 0x18)) > 0) {
            do {
                temp_v0_2 = var_a1 * 4;
                var_a1 += 1;
                temp_v1 = *(int *)(temp_v0_2 + (*(int *)(int *)((char *)(temp_v0) + 0x14)));
                (*(int *)(int *)((char *)(temp_v1) + 0x8)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x8)) | arg2);
            } while (var_a1 < (*(int *)(int *)((char *)(temp_v0) + 0x18)));
        }
    }
}


extern "C" void func_0017E4D0(int arg0, int arg1, int arg2)
{
    int temp_v0_2;
    int var_a2;
    int temp_v0;
    int temp_v1;

    temp_v0 = X_func_0017E3D8();
    if (temp_v0 != 0) {
        var_a2 = 0;
        if ((*(int *)(int *)((char *)(temp_v0) + 0x18)) > 0) {
            do {
                temp_v0_2 = var_a2 * 4;
                var_a2 += 1;
                temp_v1 = *(int *)(temp_v0_2 + (*(int *)(int *)((char *)(temp_v0) + 0x14)));
                (*(int *)(int *)((char *)(temp_v1) + 0x8)) = (int) ((*(int *)(int *)((char *)(temp_v1) + 0x8)) & ~arg2);
            } while (var_a2 < (*(int *)(int *)((char *)(temp_v0) + 0x18)));
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E540);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", WrdSrv__vfunc_01);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3080);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3090);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F30A0);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F30C8);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3118);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017E5C0);

extern "C" int func_0017E798(int arg0, int arg1, int arg2)
{
    int temp_a1_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v1;
    int temp_v1_8;
    register int var_a3 PS2_REG("$7");


    unsigned short temp_v1_2;
    int temp_a1;
    int temp_a2;
    int baseFirst;
    int baseSecond;
    int temp_v0;
    int temp_v0_2;
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_5;
    int temp_v1_6;
    int temp_v1_7;
    int var_a0;


    Xii_func_0017E9D0(arg0);
    temp_v0 = Xiiii_alloc__9BedMemoryii((int) (int)&D_006E9800, M2C_FIELD(arg1, int *, 0xC) * 0x10, -1);
    M2C_FIELD(arg0, int *, 0x10) = temp_v0;
    Xiiii_memset(temp_v0, 0, M2C_FIELD(arg1, int *, 0xC) * 0x10);
    if (arg2 != 0) {
        temp_v0_2 = Xiiii_alloc__9BedMemoryii((int) (int)&D_006E9800, M2C_FIELD(arg1, int *, 4), -1);
        Xiiii_memcpy(temp_v0_2, arg1, M2C_FIELD(arg1, int *, 4));
        M2C_FIELD(arg0, int *, 4) = temp_v0_2;
        M2C_FIELD(arg0, int *, 0) = (int) (M2C_FIELD(arg0, int *, 0) | 2);
    } else {
        M2C_FIELD(arg0, int *, 4) = arg1;
    }
    temp_a2 = M2C_FIELD(arg0, int *, 4);
    temp_a1 = temp_a2 + 0x10;
    M2C_FIELD(arg0, int *, 8) = temp_a1;
    temp_v1 = M2C_FIELD(temp_a2, int *, 8);
    temp_v0_3 = temp_v1 + 3;
    M2C_FIELD(arg0, int *, 0xC) = (int) (temp_a1 + ((temp_v1 + 3) / 4 * 0x10));
    temp_v1_2 = M2C_FIELD(temp_a2, unsigned short *, 2);
    if (temp_v1_2 & 1 & 0xFFFF) {
        M2C_FIELD(temp_a2, unsigned short *, 2) = (unsigned short) (temp_v1_2 & 0xFFFE);
        var_a3 = 0;
        if (M2C_FIELD((baseFirst = M2C_FIELD(arg0, int *, 4)), int *, 8) > 0) {
            do {
                temp_v0_4 = var_a3 * 4;
                var_a3 += 1;
                temp_a1_2 = temp_v0_4 + M2C_FIELD(arg0, int *, 8);
                temp_v0_5 = (*(int *)(temp_a1_2));
                if (temp_v0_5 != 0) {
                    (*(int *)(temp_a1_2)) = temp_v0_5 + baseFirst;
                }
            } while (var_a3 < M2C_FIELD((baseFirst = M2C_FIELD(arg0, int *, 4)), int *, 8));
        }
        var_a3 = 0;
        var_a0 = M2C_FIELD(arg0, int *, 0xC);
        if (M2C_FIELD((baseSecond = M2C_FIELD(arg0, int *, 4)), int *, 0xC) > 0) {
            do {
                temp_v0_6 = M2C_FIELD(var_a0, int *, 4);
                if (temp_v0_6 != 0) {
                    M2C_FIELD(var_a0, int *, 4) = (int) (temp_v0_6 + baseSecond);
                }
                temp_v1_3 = M2C_FIELD(var_a0, int *, 8);
                if (temp_v1_3 != 0) {
                    M2C_FIELD(var_a0, int *, 8) = (int) (temp_v1_3 + M2C_FIELD(arg0, int *, 4));
                }
                temp_v1_4 = M2C_FIELD(var_a0, int *, 0xC);
                if (temp_v1_4 != 0) {
                    M2C_FIELD(var_a0, int *, 0xC) = (int) (temp_v1_4 + M2C_FIELD(arg0, int *, 4));
                }
                temp_v1_5 = M2C_FIELD(var_a0, int *, 0x10);
                if (temp_v1_5 != 0) {
                    M2C_FIELD(var_a0, int *, 0x10) = (int) (temp_v1_5 + M2C_FIELD(arg0, int *, 4));
                }
                temp_v1_6 = M2C_FIELD(var_a0, int *, 0x14);
                if (temp_v1_6 != 0) {
                    M2C_FIELD(var_a0, int *, 0x14) = (int) (temp_v1_6 + M2C_FIELD(arg0, int *, 4));
                }
                temp_v1_7 = M2C_FIELD(var_a0, int *, 0x30);
                if (temp_v1_7 != 0) {
                    M2C_FIELD(var_a0, int *, 0x30) = (int) (temp_v1_7 + M2C_FIELD(arg0, int *, 4));
                }
                var_a3 += 1;
                var_a0 += 0x40;
            } while (var_a3 < M2C_FIELD((baseSecond = M2C_FIELD(arg0, int *, 4)), int *, 0xC));
        }
    }
    var_a3 = 0;
    var_a0 = M2C_FIELD(arg0, int *, 0xC);
    if (M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0xC) > 0) {
        do {
            temp_v1_8 = var_a3 * 0x10;
            var_a3 += 1;
            M2C_FIELD(var_a0, int *, 0x34) = (int) (M2C_FIELD(arg0, int *, 0x10) + temp_v1_8);
            var_a0 += 0x40;
        } while (var_a3 < M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0xC));
    }
    return 1;
}

extern "C" void func_0017E9D0(int arg0)
{
    int temp_a1;
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x10);
    if (temp_v0 != 0) {
        Xiii_free__9BedMemoryPv((int) (int)&D_006E9800, temp_v0);
        M2C_FIELD(arg0, int *, 0x10) = 0;
    }
    if (M2C_FIELD(arg0, int *, 0) & 2) {
        temp_a1 = M2C_FIELD(arg0, int *, 4);
        if (temp_a1 != 0) {
            Xiii_free__9BedMemoryPv((int) (int)&D_006E9800, temp_a1);
        }
    }
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    M2C_FIELD(arg0, int *, 0) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EA44);

INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EA84);

extern "C" void func_0017EB3C(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = Xiii_func_0017EA44(arg0, (int) arg2);
        M2C_FIELD(arg1, float *, 0) = (float) (M2C_FIELD(temp_v0, float *, 0x20) + M2C_FIELD(arg3, float *, 0));
        M2C_FIELD(arg1, float *, 4) = (float) (M2C_FIELD(temp_v0, float *, 0x24) + M2C_FIELD(arg3, float *, 4));
        M2C_FIELD(arg1, float *, 8) = (float) (M2C_FIELD(temp_v0, float *, 0x28) + M2C_FIELD(arg3, float *, 8));
    }
}

extern "C" void func_0017EBAC(int arg0, int arg1, int arg2, int arg3)
{
    int temp_v0;

    if (M2C_FIELD(arg0, int *, 4) != 0) {
        temp_v0 = Xiii_func_0017EA44(arg0, (int) arg3);
        M2C_FIELD(arg1, float *, 0) = (float) (M2C_FIELD(arg2, float *, 0) - M2C_FIELD(temp_v0, float *, 0x20));
        M2C_FIELD(arg1, float *, 4) = (float) (M2C_FIELD(arg2, float *, 4) - M2C_FIELD(temp_v0, float *, 0x24));
        M2C_FIELD(arg1, float *, 8) = (float) (M2C_FIELD(arg2, float *, 8) - M2C_FIELD(temp_v0, float *, 0x28));
    }
}

// NON_MATCHING: 245/248 differ, 8 relocs differ (size 0x3E0, game 0x3D8), 117 edits
#ifdef NON_MATCHING
extern "C" void EC1C_clear(int) asm("func_0017EFF4");
extern "C" void *EC1C_zero(void *, int, unsigned int) asm("memset");
extern "C" int func_0017EC1C(int in0, int in1, int in2, int in3)
{
    int lists[128];
    int counts[2];
    register int arg0 PS2_REG("$19") = in0;
    register int arg1 PS2_REG("$22") = in1;
    register int arg2 PS2_REG("$20") = in2;
    register int arg3 PS2_REG("$21") = in3;
    register int *countPtr PS2_REG("$16") = counts;
    register int result PS2_REG("$2") = Xiii_func_0017EA44(arg0, arg1);
    if (result != 0) {
        result = Xiii_func_0017EA44(arg0, arg2);
        if (result != 0) {
            if (arg1 == arg2) {
                M2C_FIELD(arg3, int *, 0) = Xiii_func_0017EA44(arg0, arg2);
                M2C_FIELD(arg3, int *, 0xFC) = 1;
                return 1;
            }
            EC1C_zero(countPtr, 0, 8);
            register int current PS2_REG("$18") = 0;
            register int limit PS2_REG("$23") = M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0xC) + 1;
            EC1C_clear(arg0);
            register int node PS2_REG("$17") = Xiii_func_0017EA44(arg0, arg2);
            M2C_FIELD(M2C_FIELD(node, int *, 0x34), int *, 0) |= 1;
            M2C_FIELD(M2C_FIELD(node, int *, 0x34), int *, 4) = 0;
            lists[0] = arg2;
            countPtr[0] = 1;
            do {
                register int n PS2_REG("$30") = 0;
                if (counts[current] > 0) {
                    do {
                        node = Xiii_func_0017EA44(arg0, lists[(current << 6) + n]);
                        if (M2C_FIELD(node, int *, 0) != arg1 && M2C_FIELD(M2C_FIELD(node, int *, 0x34), int *, 4) < limit) {
                            register int edge PS2_REG("$16") = 0;
                            if (M2C_FIELD(node, int *, 0x2C) > 0) {
                                do {
                                    int other = Xiii_func_0017EA44(arg0, M2C_FIELD(M2C_FIELD(node, int *, 0x30) + edge * 4, int *, 0));
                                    int state = M2C_FIELD(other, int *, 0x34);
                                    if (!(M2C_FIELD(state, int *, 0) & 1) || M2C_FIELD(M2C_FIELD(node, int *, 0x34), int *, 4) + 1 < M2C_FIELD(state, int *, 4)) {
                                        int i;
                                        for (i = 0; i < counts[current]; i++) {
                                            if (lists[(current << 6) + i] == M2C_FIELD(other, int *, 0)) break;
                                        }
                                        if (i >= counts[current]) {
                                            M2C_FIELD(state, int *, 0) |= 1;
                                            M2C_FIELD(M2C_FIELD(other, int *, 0x34), int *, 4) = M2C_FIELD(M2C_FIELD(node, int *, 0x34), int *, 4) + 1;
                                            M2C_FIELD(M2C_FIELD(other, int *, 0x34), int *, 8) = M2C_FIELD(node, int *, 0);
                                            int id = M2C_FIELD(other, int *, 0);
                                            if (id == arg1) {
                                                limit = M2C_FIELD(M2C_FIELD(other, int *, 0x34), int *, 4);
                                                break;
                                            } else {
                                                current ^= 1;
                                                for (i = 0; i < counts[current]; i++) {
                                                    if (lists[(current << 6) + i] == id) break;
                                                }
                                                if (i == counts[current]) {
                                                    lists[(current << 6) + i] = M2C_FIELD(other, int *, 0);
                                                    counts[current] = i + 1;
                                                }
                                                current ^= 1;
                                            }
                                        }
                                    }
                                    edge++;
                                } while (edge < M2C_FIELD(node, int *, 0x2C));
                            }
                        }
                        n++;
                    } while (n < counts[current]);
                }
                int previous = current;
                current ^= 1;
                counts[previous] = 0;
            } while (counts[current] > 0);
            result = 0;
            if (M2C_FIELD(M2C_FIELD(arg0, int *, 4), int *, 0xC) >= limit) {
                M2C_FIELD(arg3, int *, 0xFC) = 0;
                int id = arg1;
                for (;;) {
                    node = Xiii_func_0017EA44(arg0, id);
                    if (M2C_FIELD(node, int *, 0) == arg2) break;
                    int *count = (int *)(arg3 + 0xFC);
                    int oldCount = *count;
                    M2C_FIELD(arg3 + oldCount * 4, int *, 0) = node;
                    *count = oldCount + 1;
                    id = M2C_FIELD(M2C_FIELD(node, int *, 0x34), int *, 8);
                }
                int *count = (int *)(arg3 + 0xFC);
                int oldCount = *count;
                M2C_FIELD(arg3 + oldCount * 4, int *, 0) = node;
                *count = oldCount + 1;
                result = 1;
            }
        }
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017EC1C);
#endif

extern "C" void func_0017EFF4(int arg0)
{
    int var_a1;
    int var_a2;

    var_a2 = 0;
    var_a1 = (*(int *)(int *)((char *)(arg0) + 0x10));
    if ((*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x4))) + 0xC)) > 0) {
        do {
            var_a2 += 1;
            (*(int *)(var_a1)) &= ~1;
            var_a1 += 0x10;
        } while (var_a2 < (*(int *)(int *)((char *)((*(int *)(int *)((char *)(arg0) + 0x4))) + 0xC)));
    }
}


INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017F038);

extern "C" void func_0017F090()
{
    X_func_0017F038(1, 0xFFFF);
}


extern "C" void func_0017F0B0()
{
    X_func_0017F038(0, 0xFFFF);
}

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3148);

