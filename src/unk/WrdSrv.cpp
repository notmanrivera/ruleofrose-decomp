#include "include_asm.h"
#include "unk/WrdSrv.h"
#include "bed/bedmemory.h"
#include "bed/bedpfh.h"
#include "utl/filereader.h"
#include "sdk/string.h"

#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))

extern BedMemory D_006E9800;
extern WrdSrv D_00298EE0;
extern void *_vt_WrdSrv[] asm("_vt$6WrdSrv");
extern "C" int memcmp(const void *, const void *, unsigned int);
extern "C" void X___builtin_delete(void *) asm("__builtin_delete");
extern "C" int X_sprintf(char *, const char *, ...) asm("func_00279C98");
extern "C" void X_initFileReadReq(FileReadReq *) asm("__11FileReadReq");

extern "C" void func_0017C754(SctLayer *self);
extern "C" int func_0017C7B0(SctLayerHeader *hdr);
extern "C" void func_0017C814(SctGroup *grp);
extern "C" void func_0017C844(SctArea *area, SctCell *cells, int cellNum);
extern "C" SctCell *func_0017C8B8(SctLayer *self, const float *pos, SctCell *hint, float tolY);
extern "C" SctCell *func_0017CAA8(SctLayer *self, int groupId, const float *pos, float tolY);
extern "C" SctCell *func_0017CB50(SctLayer *self, int groupId, const float *pos, float tolY, float margin);
extern "C" int func_0017CC68(SctLayer *self, SctCell *cell, const float *pos, float tolY, float margin);
extern "C" int func_0017CCE8(SctLayer *self, int cellId, const float *pos, float margin);
extern "C" int func_0017CE74(SctLayer *self, const float *pos, int startGroup, float margin);
extern "C" int X_func_0017CF0C(SctLayer *self, int startGroup, int endGroup, SctGroupPath *outPath) asm("func_0017CF0C");
extern "C" void X_func_0017D35C(SctLayer *self, SctCellSearchArg *arg) asm("func_0017D35C");
extern "C" float func_0017DD5C(SctLayer *self, int cellId, const float *pos, float margin);
extern "C" SctArea *func_0017E3D8(SctLayer *self, const char *name);
extern "C" void func_0017E540(WrdSrv *self);
extern "C" void WrdSrv__vfunc_01(WrdSrv *self, int flags);
extern "C" int func_0017E798(WrdSrv *self, WrdHeader *hdr, int copy);
extern "C" void func_0017E9D0(WrdSrv *self);
extern "C" WrdRoom *func_0017EA44(WrdSrv *self, int id);
extern "C" void func_0017F038(int init, int prio);

extern "C" int func_0017C60C(SctLayer *self, SctLayerHeader *hdr, int copy)
{
    int i;

    func_0017C754(self);
    if (copy != 0) {
        int size = func_0017C7B0(hdr);
        void *buf = D_006E9800.alloc(size, -1);
        memcpy(buf, hdr, size);
        self->m_layer = (SctLayerHeader *)buf;
        self->m_flags |= 2;
    } else {
        self->m_layer = hdr;
    }

    self->m_groups = (SctGroup *)((char *)self->m_layer + 0x10);
    for (i = 0; i < self->m_layer->m_groupNum; i++) {
        func_0017C814(&self->m_groups[i]);
    }

    self->m_cells = self->m_groups[0].m_cells;
    self->m_areas = (self->m_layer->m_areaNum > 0)
        ? (SctArea *)&self->m_cells[self->m_layer->m_cellNum]
        : 0;

    for (i = 0; i < self->m_layer->m_areaNum; i++) {
        func_0017C844(&self->m_areas[i], self->m_cells, self->m_layer->m_cellNum);
    }
    return 1;
}

extern "C" void func_0017C754(SctLayer *self)
{
    if (self->m_flags & 2) {
        if (self->m_layer != 0) {
            D_006E9800.free(self->m_layer);
        }
    }
    self->m_layer = 0;
    self->m_groups = 0;
    self->m_cells = 0;
    self->m_areas = 0;
    self->m_flags = 0;
}

// NON_MATCHING: 6/25 differ, 8 edits (prologue add/load schedule)
#ifdef NON_MATCHING
extern "C" int func_0017C7B0(SctLayerHeader *hdr)
{
    int size = sizeof(SctLayerHeader);
    size += hdr->m_groupNum * sizeof(SctGroup);
    size += hdr->m_areaNum * sizeof(SctArea);
    size += hdr->m_cellNum * sizeof(SctCell);
    SctArea *area = (SctArea *)((char *)hdr + sizeof(SctLayerHeader) + hdr->m_groupNum * sizeof(SctGroup) + hdr->m_cellNum * sizeof(SctCell));
    int i;

    for (i = 0; i < hdr->m_areaNum; i++) {
        size += area->m_cellNum * 4;
        area++;
    }
    return size;
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017C7B0);
#endif

extern "C" void func_0017C814(SctGroup *grp)
{
    if ((grp->m_flags ^ 1) & 1) {
        return;
    }
    grp->m_flags |= 1;
    grp->m_cells = (SctCell *)((char *)grp + (int)grp->m_cells);
}

extern "C" void func_0017C844(SctArea *area, SctCell *cells, int cellNum)
{
    if ((area->m_flags ^ 1) & 1) {
        return;
    }
    int i;
    int *src;
    area->m_cells = (SctCell **)((char *)area + (int)area->m_cells);
    src = (int *)area->m_cells;
    for (i = 0; i < area->m_cellNum; i++) {
        area->m_cells[i] = &cells[*src++];
    }
}

extern "C" SctCell *func_0017C8B8(SctLayer *self, const float *pos, SctCell *hint, float tolY)
{
    int groupId;
    SctCell *cell;

    if (self->m_layer == 0) {
        return 0;
    }
    if (hint != 0) {
        if (func_0017CC68(self, hint, pos, tolY, 0.0f) != 0) {
            return hint;
        }
        cell = func_0017CAA8(self, hint->m_groupId, pos, tolY);
        if (cell != 0) {
            return cell;
        }
    }
    groupId = 0;
    for (;;) {
        groupId = func_0017CE74(self, pos, groupId, 0.0f);
        if (groupId == -1) {
            break;
        }
        cell = func_0017CAA8(self, groupId, pos, tolY);
        if (cell != 0) {
            return cell;
        }
        groupId++;
    }
    return 0;
}

extern "C" SctCell *func_0017C994(SctLayer *self, const float *pos, SctCell *hint, float tolY, float margin)
{
    SctCell *cell;
    int groupId;

    if (self->m_layer == 0) {
        return 0;
    }
    cell = func_0017C8B8(self, pos, hint, tolY);
    if (cell != 0) {
        return cell;
    }
    if (margin <= 0.0f) {
        return 0;
    }
    if (hint != 0) {
        if (func_0017CC68(self, hint, pos, tolY, margin) != 0) {
            return hint;
        }
        cell = func_0017CB50(self, hint->m_groupId, pos, tolY, margin);
        if (cell != 0) {
            return cell;
        }
    }
    groupId = 0;
    for (;;) {
        groupId = func_0017CE74(self, pos, groupId, margin);
        if (groupId == -1) {
            break;
        }
        cell = func_0017CB50(self, groupId, pos, tolY, margin);
        if (cell != 0) {
            return cell;
        }
        groupId++;
    }
    return 0;
}

extern "C" SctCell *func_0017CAA8(SctLayer *self, int groupId, const float *pos, float tolY)
{
    SctGroup *grp = &self->m_groups[groupId];
    SctCell *cell = grp->m_cells;
    int i;

    for (i = 0; i < grp->m_cellNum; i++) {
        if (func_0017CC68(self, cell, pos, tolY, 0.0f) != 0) {
            return cell;
        }
        cell++;
    }
    return 0;
}

extern "C" SctCell *func_0017CB50(SctLayer *self, int groupId, const float *pos, float tolY, float margin)
{
    SctGroup *grp = &self->m_groups[groupId];
    SctCell *cell = grp->m_cells;
    SctCell *best = 0;
    float bestDist = 0.0f;
    int i;

    for (i = 0; i < grp->m_cellNum; i++) {
        if (func_0017CC68(self, cell, pos, tolY, margin) != 0) {
            float dx = pos[0] - cell->m_center[0];
            float dy = pos[1] - cell->m_center[1];
            float dz = pos[2] - cell->m_center[2];
            float dist = dx * dx + dy * dy + dz * dz;
            if (best == 0 || dist < bestDist) {
                bestDist = dist;
                best = cell;
            }
        }
        cell++;
    }
    return best;
}

extern "C" int func_0017CC68(SctLayer *self, SctCell *cell, const float *pos, float tolY, float margin)
{
    float h = func_0017DD5C(self, cell->m_id, pos, margin);
    if (h == 100000.0f) {
        return 0;
    }
    h -= pos[1];
    return (-tolY <= h && h <= tolY);
}

struct SctRect {
    float minX;
    float minZ;
    float maxX;
    float maxZ;
};

static inline SctRect expandCellRect(const SctCell *cell, float margin)
{
    SctRect r;
    r.minX = cell->m_rect[0] - margin;
    r.minZ = cell->m_rect[1] - margin;
    r.maxX = cell->m_rect[2] + margin;
    r.maxZ = cell->m_rect[3] + margin;
    return r;
}

extern "C" int func_0017CCE8(SctLayer *self, int cellId, const float *pos, float margin)
{
    SctCell *cell = &self->m_cells[cellId];
    SctRect r = expandCellRect(cell, margin);

    if (!(r.minX <= pos[0] && pos[0] <= r.maxX && r.minZ <= pos[2] && pos[2] <= r.maxZ)) {
        return 0;
    }
    float x0 = 0.0f;
    float x1 = 0.0f;
    float z0 = 0.0f;
    float z1 = 0.0f;
    unsigned int cut = cell->m_flags & 0xF0;

    switch (cut) {
    case 0x00:
        return 1;
    case 0x10:
        x0 = r.minX;
        x1 = r.maxX;
        z0 = r.minZ;
        z1 = r.maxZ;
        break;
    case 0x20:
        x0 = r.maxX;
        x1 = r.minX;
        z0 = r.minZ;
        z1 = r.maxZ;
        break;
    case 0x40:
        x0 = r.minX;
        x1 = r.maxX;
        z0 = r.maxZ;
        z1 = r.minZ;
        break;
    case 0x80:
        x0 = r.maxX;
        x1 = r.minX;
        z0 = r.maxZ;
        z1 = r.minZ;
        break;
    }
    return (1.0f - (pos[0] - x0) / (x1 - x0)) <= (pos[2] - z0) / (z1 - z0);
}

extern "C" int func_0017CE74(SctLayer *self, const float *pos, int startGroup, float margin)
{
    SctGroup *grp = &self->m_groups[startGroup];
    int i;

    for (i = startGroup; i < self->m_layer->m_groupNum; i++) {
        if (grp->m_minX - margin <= pos[0] && pos[0] <= grp->m_maxX + margin &&
            grp->m_minZ - margin <= pos[2] && pos[2] <= grp->m_maxZ + margin) {
            return i;
        }
        grp++;
    }
    return -1;
}

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

extern "C" int func_0017D298(SctLayer *self, SctPathReq *req)
{
    SctCellSearchArg arg;
    SctGroupPath groupPath;
    SctCell *startCell;
    SctCell *endCell;

    if (self->m_layer == 0) {
        return 0;
    }
    startCell = req->m_startCells[req->m_index];
    endCell = req->m_endCells[req->m_index];
    if (startCell == 0 || endCell == 0) {
        return 0;
    }
    if (X_func_0017CF0C(self, startCell->m_groupId, endCell->m_groupId, &groupPath) == 0) {
        return 0;
    }
    arg.m_startCellId = startCell->m_id;
    arg.m_endCellId = endCell->m_id;
    arg.m_groupPath = &groupPath;
    arg.m_outPath = req->m_outPath;
    X_func_0017D35C(self, &arg);
    return 1;
}

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

// NON_MATCHING: 71/89 differ (size 0x164, game 0x174), 20 edits (duplicate 100000.0f load)
#ifdef NON_MATCHING
static inline float sctCellHeight(const SctCell *cell, const float *pos)
{
    float y = 100000.0f;
    unsigned int slope = cell->m_flags & 0xA;

    switch (slope) {
    case 0:
        y = cell->m_y0;
        break;
    case 2:
        y = cell->m_yZ + (cell->m_y0 - cell->m_yZ) * (pos[2] - cell->m_rect[1]) / (cell->m_rect[3] - cell->m_rect[1]);
        break;
    case 8:
        y = cell->m_yX + (cell->m_y0 - cell->m_yX) * (pos[0] - cell->m_rect[0]) / (cell->m_rect[2] - cell->m_rect[0]);
        break;
    case 10:
        y = cell->m_yZ + (cell->m_y0 - cell->m_yZ) * (pos[2] - cell->m_rect[1]) / (cell->m_rect[3] - cell->m_rect[1]) +
            (cell->m_y0 - cell->m_yX) * (pos[0] - cell->m_rect[0]) / (cell->m_rect[2] - cell->m_rect[0]);
        break;
    }
    return y;
}

extern "C" float func_0017DD5C(SctLayer *self, int cellId, const float *pos, float margin)
{
    if (func_0017CCE8(self, cellId, pos, margin) == 0) {
        return 100000.0f;
    }
    return sctCellHeight(&self->m_cells[cellId], pos);
}
#else
INCLUDE_ASM("asm/nonmatchings/unk/WrdSrv", func_0017DD5C);
#endif

extern "C" int func_0017DED0(SctLayer *self, int cellId, const float *pos, float tolY)
{
    SctCell *cell = &self->m_cells[cellId];
    int i;

    for (i = 0; i < 8; i++) {
        int nb = cell->m_neighbor[i];
        if (nb != -1) {
            if (func_0017CC68(self, &self->m_cells[nb], pos, tolY, 0.0f) != 0) {
                return cell->m_neighbor[i];
            }
        }
    }
    return -1;
}

extern "C" void func_0017DFA8(SctLayer *self)
{
    int i;
    SctGroup *grp = self->m_groups;

    for (i = 0; i < self->m_layer->m_groupNum; i++) {
        grp->m_flags &= 0x7FFFFFFF;
        grp++;
    }
}

extern "C" void func_0017DFF0(SctLayer *self, SctGroupPath *path)
{
    int i;
    int j;

    if (path == 0) {
        register SctCell *cell PS2_REG("$6") = self->m_cells;
        for (i = 0; i < self->m_layer->m_cellNum; i++) {
            cell->m_searchFlg &= 0x7FFFFFFF;
            cell++;
        }
    } else {
        register SctGroup **gp PS2_REG("$4") = path->m_groups;
        for (i = 0; i < path->m_count; i++) {
            register SctCell *cell PS2_REG("$6") = (*gp)->m_cells;
            for (j = 0; j < (*gp)->m_cellNum; j++) {
                cell->m_searchFlg &= 0x7FFFFFFF;
                cell++;
            }
            gp++;
        }
    }
}

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

extern "C" SctArea *func_0017E3D8(SctLayer *self, const char *name)
{
    int i;

    for (i = 0; i < self->m_layer->m_areaNum; i++) {
        if (strcmp(self->m_areas[i].m_name, name) == 0) {
            return &self->m_areas[i];
        }
    }
    return 0;
}

extern "C" void func_0017E464(SctLayer *self, const char *name, int mask)
{
    SctArea *area = func_0017E3D8(self, name);
    int i;

    if (area != 0) {
        for (i = 0; i < area->m_cellNum; i++) {
            area->m_cells[i]->m_flags |= mask;
        }
    }
}

extern "C" void func_0017E4D0(SctLayer *self, const char *name, int mask)
{
    SctArea *area = func_0017E3D8(self, name);
    int i;

    if (area != 0) {
        for (i = 0; i < area->m_cellNum; i++) {
            area->m_cells[i]->m_flags &= ~mask;
        }
    }
}

extern "C" void func_0017E540(WrdSrv *self)
{
    self->m_vtbl = _vt_WrdSrv;
    self->m_flags = 0;
    self->m_data = 0;
    self->m_idTable = 0;
    self->m_rooms = 0;
    self->m_states = 0;
}

extern "C" void WrdSrv__vfunc_01(WrdSrv *self, int flags)
{
    self->m_vtbl = _vt_WrdSrv;
    func_0017E9D0(self);
    if (flags & 1) {
        X___builtin_delete(self);
        return;
    }
}

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3080);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3090);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F30A0);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F30C8);

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3118);

extern "C" int func_0017E5C0(WrdSrv *self, int idx)
{
    char buf[0x800];

    if (idx == 99) {
        return 1;
    }

    FileReader reader;
    FileReadReq req;
    req.m_name = "data/wrd/WRD.BIN";
    req.m_unk08 = 1;
    req.m_unk20 = 1;
    req.m_size = sizeof(buf);
    req.m_unk14 = 0;
    req.m_offset = 0;
    req.m_buf = buf;
    req.m_unk04 = 0;
    reader.func_001BE524(&req, 0);

    BedPfh pfh;
    char name[16];
    X_sprintf(name, "%03d", idx);
    pfh.setTop(buf);
    int fileIdx = pfh.getIndex(name);
    int fileSize = pfh.getFileSize(fileIdx);
    void *data = D_006E9800.alloc(fileSize, -1);

    X_initFileReadReq(&req);
    req.m_name = "data/wrd/WRD.BIN";
    req.m_unk08 = 1;
    req.m_unk14 = 0;
    req.m_offset = pfh.getFileOffset(fileIdx);
    req.m_size = fileSize;
    req.m_unk20 = 1;
    req.m_buf = data;
    req.m_unk04 = 0;
    reader.func_001BE524(&req, 0);

    if (func_0017E798(self, (WrdHeader *)data, 1) == 0) {
        D_006E9800.free(data);
        return 0;
    }
    return 1;
}

extern "C" int func_0017E798(WrdSrv *self, WrdHeader *hdr, int copy)
{
    register int i PS2_REG("$7");
    WrdRoom *room;

    func_0017E9D0(self);
    self->m_states = (WrdRoomState *)D_006E9800.alloc(hdr->m_roomNum * sizeof(WrdRoomState), -1);
    memset(self->m_states, 0, hdr->m_roomNum * sizeof(WrdRoomState));
    if (copy != 0) {
        void *buf = D_006E9800.alloc(hdr->m_size, -1);
        memcpy(buf, hdr, hdr->m_size);
        self->m_data = (WrdHeader *)buf;
        self->m_flags |= 2;
    } else {
        self->m_data = hdr;
    }

    WrdHeader *data = self->m_data;
    WrdRoom **idTable = (WrdRoom **)((char *)data + 0x10);
    self->m_idTable = idTable;
    self->m_rooms = (WrdRoom *)((char *)idTable + ((data->m_idTableNum + 3) / 4) * 0x10);

    if (data->m_flags & 1) {
        data->m_flags &= 0xFFFE;
        for (i = 0; i < self->m_data->m_idTableNum; i++) {
            int off = (int)self->m_idTable[i];
            if (off != 0) {
                self->m_idTable[i] = (WrdRoom *)(off + (int)self->m_data);
            }
        }
        room = self->m_rooms;
        for (i = 0; i < self->m_data->m_roomNum; i++) {
            if (room->m_name != 0) {
                room->m_name = (const char *)((int)room->m_name + (int)self->m_data);
            }
            if (room->m_unk08 != 0) {
                room->m_unk08 = (void *)((int)room->m_unk08 + (int)self->m_data);
            }
            if (room->m_unk0C != 0) {
                room->m_unk0C = (void *)((int)room->m_unk0C + (int)self->m_data);
            }
            if (room->m_unk10 != 0) {
                room->m_unk10 = (void *)((int)room->m_unk10 + (int)self->m_data);
            }
            if (room->m_unk14 != 0) {
                room->m_unk14 = (void *)((int)room->m_unk14 + (int)self->m_data);
            }
            if (room->m_neighbors != 0) {
                room->m_neighbors = (int *)((int)room->m_neighbors + (int)self->m_data);
            }
            room++;
        }
    }

    room = self->m_rooms;
    for (i = 0; i < self->m_data->m_roomNum; i++) {
        room->m_state = &self->m_states[i];
        room++;
    }
    return 1;
}

extern "C" void func_0017E9D0(WrdSrv *self)
{
    if (self->m_states != 0) {
        D_006E9800.free(self->m_states);
        self->m_states = 0;
    }
    if (self->m_flags & 2) {
        if (self->m_data != 0) {
            D_006E9800.free(self->m_data);
        }
    }
    self->m_data = 0;
    self->m_rooms = 0;
    self->m_idTable = 0;
    self->m_flags = 0;
}

extern "C" WrdRoom *func_0017EA44(WrdSrv *self, int id)
{
    if (self->m_data == 0) {
        return 0;
    }
    if (id < 0 || id >= self->m_data->m_idTableNum) {
        return 0;
    }
    return self->m_idTable[id];
}

extern "C" WrdRoom *func_0017EA84(WrdSrv *self, const char *name)
{
    if (self->m_data == 0) {
        return 0;
    }
    WrdRoom *room = self->m_rooms;
    int len = strlen(name);
    int i;

    for (i = 0; i < self->m_data->m_roomNum; i++) {
        if (memcmp(room->m_name, name, len) == 0 && (int)strlen(room->m_name) == len) {
            return room;
        }
        room++;
    }
    return 0;
}

extern "C" void func_0017EB3C(WrdSrv *self, float *out, int roomId, const float *in)
{
    if (self->m_data != 0) {
        WrdRoom *room = func_0017EA44(self, roomId);
        out[0] = room->m_origin[0] + in[0];
        out[1] = room->m_origin[1] + in[1];
        out[2] = room->m_origin[2] + in[2];
    }
}

extern "C" void func_0017EBAC(WrdSrv *self, float *out, const float *in, int roomId)
{
    if (self->m_data != 0) {
        WrdRoom *room = func_0017EA44(self, roomId);
        out[0] = in[0] - room->m_origin[0];
        out[1] = in[1] - room->m_origin[1];
        out[2] = in[2] - room->m_origin[2];
    }
}

// NON_MATCHING: 245/248 differ, 8 relocs differ (size 0x3E0, game 0x3D8), 117 edits
#ifdef NON_MATCHING
extern "C" int Xiii_func_0017EA44(int, int) asm("func_0017EA44");
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

extern "C" void func_0017EFF4(WrdSrv *self)
{
    WrdRoomState *st = self->m_states;
    int i;

    for (i = 0; i < self->m_data->m_roomNum; i++) {
        st->m_flags &= ~1;
        st++;
    }
}

extern "C" void func_0017F038(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init == 1) {
            func_0017E540(&D_00298EE0);
        }
        if (init == 0) {
            WrdSrv__vfunc_01(&D_00298EE0, 2);
        }
    }
}

extern "C" void func_0017F090()
{
    func_0017F038(1, 0xFFFF);
}

extern "C" void func_0017F0B0()
{
    func_0017F038(0, 0xFFFF);
}

INCLUDE_RODATA("asm/nonmatchings/unk/WrdSrv", D_002F3148);

