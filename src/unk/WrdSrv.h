// unk/WrdSrv.h: SctLayer (0x17C60C..0x17E53F, sector/cell navigation layer)
// and WrdSrv (0x17E540..0x17F0B0, world room graph server).
//
// Evidence:
// - Class names "8SctLayer" (D_002F3118) and "6WrdSrv" (D_002F3148),
//   vtables _vt$8SctLayer (0x002E4520) and _vt$6WrdSrv (0x002E4538),
//   and linkonce inline methods:
//   - SctLayer::getLayer()      -> +0x04 (m_layer)
//   - SctLayer::getGroup(int i) -> +0x08 (m_groups[i], stride 0x80)
//   - SctLayer::getCell(int i)  -> +0x0C (m_cells[i],  stride 0x90)
// - SctLayer/SctGroup/SctCell/SctArea layouts from func_0017C60C..0017E4D0.
// - WrdSrv/WrdHeader/WrdRoom/WrdRoomState layouts from func_0017E540..0017F0B0.
#ifndef UNK_WRDSRV_H
#define UNK_WRDSRV_H

// =========================================================================
// SctLayer: navigation grid (groups of cells + named areas)
// =========================================================================

struct SctLayerHeader {
    int m_unk00;                // +0x00
    int m_groupNum;             // +0x04
    int m_cellNum;              // +0x08
    int m_areaNum;              // +0x0C
}; // size 0x10

struct SctCell {
    int m_id;                   // +0x00
    int m_groupId;              // +0x04
    int m_flags;                // +0x08 (0x4: blocked, 0xA: slope mode, 0xF0: cut mode)
    int m_unk0C;                // +0x0C
    float m_center[3];          // +0x10 (x, y, z)
    float m_rect[4];            // +0x1C (minX, minZ, maxX, maxZ)
    float m_y0;                 // +0x2C
    float m_yX;                 // +0x30
    float m_yZ;                 // +0x34
    int m_unk38;                // +0x38
    int m_neighbor[8];          // +0x3C (-1 = none)
    float m_edgeCost[8];        // +0x5C
    int m_searchFlg;            // +0x7C (bit 31: visited)
    float m_dist;               // +0x80
    int m_prev;                 // +0x84
    const int *m_edgeOrder;     // +0x88
    int m_unk8C;                // +0x8C
}; // size 0x90

struct SctGroup {
    int m_id;                   // +0x00
    int m_neighbor[16];         // +0x04 (-1 terminated)
    int m_cellNum;              // +0x44
    int m_unk48;                // +0x48
    float m_minX;               // +0x4C
    float m_minZ;               // +0x50
    float m_maxX;               // +0x54
    float m_maxZ;               // +0x58
    int m_flags;                // +0x5C (bit 0: relocated, bit 31: visited)
    SctCell *m_cells;           // +0x60 (file offset before relocation)
    int m_dist;                 // +0x64
    int m_prev;                 // +0x68
    int m_unk6C[5];             // +0x6C
}; // size 0x80

struct SctArea {
    char m_name[0x14];          // +0x00
    SctCell **m_cells;          // +0x14 (file offset -> array of cell indices -> SctCell*)
    int m_cellNum;              // +0x18
    int m_flags;                // +0x1C (bit 0: needs relocation)
}; // size 0x20

struct SctGroupPath {
    SctGroup *m_groups[63];     // +0x00
    int m_count;                // +0xFC
}; // size 0x100

struct SctCellPath {
    SctCell *m_cells[127];      // +0x00
    int m_count;                // +0x1FC
}; // size 0x200

struct SctPathReq {
    int m_index;                // +0x00
    SctCell **m_startCells;     // +0x04
    SctCell **m_endCells;       // +0x08
    SctCellPath *m_outPath;     // +0x0C
}; // size 0x10

struct SctCellSearchArg {
    int m_startCellId;          // +0x00
    int m_endCellId;            // +0x04
    SctGroupPath *m_groupPath;  // +0x08
    SctCellPath *m_outPath;     // +0x0C
}; // size 0x10

struct SctLayer {
    int m_flags;                // +0x00 (bit 1: owns m_layer allocation)
    SctLayerHeader *m_layer;    // +0x04
    SctGroup *m_groups;         // +0x08
    SctCell *m_cells;           // +0x0C
    SctArea *m_areas;           // +0x10
    void *m_vtbl;               // +0x14 (_vt$8SctLayer)

    SctLayerHeader *getLayer() { return m_layer; }
    SctGroup *getGroup(int i) { return (m_layer && m_groups) ? &m_groups[i] : 0; }
    SctCell *getCell(int i) { return (m_layer && m_cells) ? &m_cells[i] : 0; }
}; // size 0x18

// =========================================================================
// WrdSrv: world room graph ("data/wrd" /WRD.BIN)
// =========================================================================

struct WrdHeader {
    short m_unk00;              // +0x00
    unsigned short m_flags;     // +0x02 (bit 0: needs relocation)
    int m_size;                 // +0x04
    int m_idTableNum;           // +0x08
    int m_roomNum;              // +0x0C
}; // size 0x10

struct WrdRoomState {
    int m_flags;                // +0x00 (bit 0: visited)
    int m_dist;                 // +0x04
    int m_prev;                 // +0x08
    int m_unk0C;                // +0x0C
}; // size 0x10

struct WrdRoom {
    int m_id;                   // +0x00
    const char *m_name;         // +0x04
    void *m_unk08;              // +0x08
    void *m_unk0C;              // +0x0C
    void *m_unk10;              // +0x10
    void *m_unk14;              // +0x14
    int m_unk18[2];             // +0x18
    float m_origin[3];          // +0x20
    int m_neighborNum;          // +0x2C
    int *m_neighbors;           // +0x30
    WrdRoomState *m_state;      // +0x34
    int m_unk38[2];             // +0x38
}; // size 0x40

struct WrdRoomPath {
    WrdRoom *m_rooms[63];       // +0x00
    int m_count;                // +0xFC
}; // size 0x100

struct WrdSrv {
    int m_flags;                // +0x00 (bit 1: owns m_data allocation)
    WrdHeader *m_data;          // +0x04
    WrdRoom **m_idTable;        // +0x08
    WrdRoom *m_rooms;           // +0x0C
    WrdRoomState *m_states;     // +0x10
    void *m_vtbl;               // +0x14 (_vt$6WrdSrv)
}; // size 0x18

#endif
