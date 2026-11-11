// Layout of MagLifePC and its modes, deduced from asm/mag/maglifepc.s by
// Gemini 4 Argon (2026-11-11) and checked here: with ee-gcc 2.96 every field
// below lands on the offset in its comment and sizeof(MagLifePC) is 0x220.
// maglifepc.cpp includes it; its functions still reach most fields through
// the I() and F() macros: move them to the member names one by one.
// Names marked "Proposed" are guesses from use; "DOUBTFUL" ones are unverified.
#ifndef MAG_MAGLIFEPC_H
#define MAG_MAGLIFEPC_H

#include "ror.h"
#include "mag/maglife.h"
#include "dog/dogactor.h"
#include "bed/bedpad.h"

class MagLifePC;
typedef MagLifePC MagPC;

// ============================================================================
// 1. MagLifePCMode (aliased as MagPCMode in maglifepc.cpp) & Derived Mode Classes
// ============================================================================
// - vptr position: +0x00 (4 bytes)
// - Virtual table layout (8 bytes per entry: short delta, short index, void *func):
//   * Entry 0 (+0x00): RTTI / type_info
//   * Entry 1 (+0x08): virtual void vfunc01(MagLifePC *thePC)
//     Called in func_0011C2AC at 0x0011C3F4..0x0011C408:
//     lw $v0, 0x0($v1); addiu $v0, $v0, 0x8; lh $a0, 0x0($v0); lw $v0, 0x4($v0); jalr $v0
//   * Entry 2 (+0x10): virtual void vfunc02(MagLifePC *thePC)
//     Called in live__9MagLifePC at 0x0011AE9C..0x0011AEB4:
//     lw $v0, 0x0($v1); addiu $v0, $v0, 0x10; lh $a0, 0x0($v0); lw $v0, 0x4($v0); jalr $v0
//   * Entry 3 (+0x18): virtual int vfunc03(MagLifePC *thePC, void *theA) (theA is BedPad*)
//     Called in func_0011B2C4 at 0x0011B2DC..0x0011B2F0 and MagLifePC__vfunc_16 at 0x0011B468..0x0011B480:
//     lw $v0, 0x0($v1); addiu $v0, $v0, 0x18; lh $a0, 0x0($v0); lw $v0, 0x4($v0); jalr $v0
// - Total size: 0x04 bytes for base and simple modes (deduced from consecutive placement
//   inside MagLifePC at +0x138..+0x1AC in func_0011BF0C and jtbl_002EA190 in func_0011C2AC).
struct MagLifePCMode {
    // void *m_vptr;                // +0x00 (size 0x04) - 0x0011AE9C: lw $v0, 0x0($v1); 0x0011C3F4: lw $v0, 0x0($v1)

    virtual void vfunc01(MagLifePC *thePC);
    virtual void vfunc02(MagLifePC *thePC);
    virtual int vfunc03(MagLifePC *thePC, void *theA);
};
typedef MagLifePCMode MagPCMode;

// Size: 0x04 bytes (placed at MagLifePC + 0x138, next at +0x13C; _vt$17MagLifePCModeNull at 0x0011C048)
struct MagLifePCModeNull : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x13C, next at +0x140; _vt$17MagLifePCModeWait at 0x0011C014)
struct MagLifePCModeWait : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x140, next at +0x144; _vt$19MagLifePCModeWalk2D at 0x0011C018)
struct MagLifePCModeWalk2D : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x144, next at +0x148; _vt$18MagLifePCModeRun2D at 0x0011C020)
struct MagLifePCModeRun2D : public MagLifePCMode {};

// Size: 0x08 bytes (placed at MagLifePC + 0x148, next at +0x150; _vt$17MagLifePCModeTurn at 0x0011C028)
struct MagLifePCModeTurn : public MagLifePCMode {
    int m_unk04;                    // +0x04 (size 0x04, DOUBTFUL: unreferenced in this asm slice; deduced from 8-byte stride +0x148 to +0x150)
};

// Size: 0x04 bytes (placed at MagLifePC + 0x150, next at +0x154; _vt$22MagLifePCModeAtkWait2D at 0x0011C030)
struct MagLifePCModeAtkWait2D : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x154, next at +0x158; _vt$22MagLifePCModeAtkMove2D at 0x0011C038)
struct MagLifePCModeAtkMove2D : public MagLifePCMode {};

// Size: 0x10 bytes (placed at MagLifePC + 0x158, next at +0x168; _vt$22MagLifePCModeAttacking at 0x0011C07C)
struct MagLifePCModeAttacking : public MagLifePCMode {
    int m_unk04;                    // +0x04 (size 0x04) - 0x0011C084: sw $zero, 0x4($v1) (in func_0011BF0C, $v1 = this + 0x158)
    int m_unk08;                    // +0x08 (size 0x04) - 0x0011C088: sw $zero, 0x8($v1) (in func_0011BF0C)
    int m_unk0C;                    // +0x0C (size 0x04) - 0x0011C080: sw $zero, 0xC($v1) (in func_0011BF0C)
};

// Size: 0x0C bytes (placed at MagLifePC + 0x168, next at +0x174; _vt$19MagLifePCModeDamage at 0x0011C08C)
struct MagLifePCModeDamage : public MagLifePCMode {
    int m_unk04;                    // +0x04 (size 0x04, DOUBTFUL: unreferenced in this asm slice; deduced from 0x0C gap +0x168 to +0x174)
    int m_unk08;                    // +0x08 (size 0x04, DOUBTFUL: unreferenced in this asm slice; deduced from 0x0C gap +0x168 to +0x174)
};

// Size: 0x04 bytes (placed at MagLifePC + 0x174, next at +0x178; _vt$17MagLifePCModeItem at 0x0011C090)
struct MagLifePCModeItem : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x178, next at +0x17C; _vt$18MagLifePCModeDogGo at 0x0011C094)
struct MagLifePCModeDogGo : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x17C, next at +0x180; _vt$20MagLifePCModeDogCome at 0x0011C098)
struct MagLifePCModeDogCome : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x180, next at +0x184; _vt$20MagLifePCModeDogStay at 0x0011C09C)
struct MagLifePCModeDogStay : public MagLifePCMode {};

// Size: 0x08 bytes (placed at MagLifePC + 0x184, next at +0x18C; _vt$17MagLifePCModeHold at 0x0011C0A0)
struct MagLifePCModeHold : public MagLifePCMode {
    // Proposed name: m_hold_count (tracks active hold/grab count: incremented on msg 0,
    // decremented on msg 1 and switches to Unhold mode 0xD when reaching 0, reset on map jump)
    int m_unk04;                    // +0x04 (size 0x04) - 0x0011B64C: lw $v0, 0x4($v1) (+1); 0x0011B660: lw $v0, 0x4($v1) (-1); 0x0011BE90: sw $zero, 0x188($s0)
};

// Size: 0x04 bytes (placed at MagLifePC + 0x18C, next at +0x190; _vt$23MagLifePCModeHoldAttack at 0x0011C0A8)
struct MagLifePCModeHoldAttack : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x190, next at +0x194; _vt$19MagLifePCModeUnhold at 0x0011C0AC)
struct MagLifePCModeUnhold : public MagLifePCMode {};

// Size: 0x0C bytes (placed at MagLifePC + 0x194, next at +0x1A0; _vt$17MagLifePCModeRide at 0x0011C0B0)
struct MagLifePCModeRide : public MagLifePCMode {
    int m_unk04;                    // +0x04 (size 0x04) - 0x0011C0BC: sw $zero, 0x4($s7) (in func_0011BF0C); 0x0011BE94: sw $zero, 0x198($s0) (in reset4MapJump)
    int m_unk08;                    // +0x08 (size 0x04, DOUBTFUL: unreferenced in this asm slice; deduced from 0x0C gap +0x194 to +0x1A0, or used inside func_00122C9C called at 0x0011B6A4)
};

// Size: 0x04 bytes (placed at MagLifePC + 0x1A0, next at +0x1A4; _vt$18MagLifePCModeRoped at 0x0011C0C0)
struct MagLifePCModeRoped : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x1A4, next at +0x1A8; _vt$19MagLifePCModeReload at 0x0011C0D0)
struct MagLifePCModeReload : public MagLifePCMode {};

// Size: 0x04 bytes (placed at MagLifePC + 0x1A8, next field at +0x1AC; _vt$16MagLifePCModeHug at 0x0011C124)
struct MagLifePCModeHug : public MagLifePCMode {};


// ============================================================================
// 2. MagLifePC (aliased as MagPC in maglifepc.cpp)
// ============================================================================
// - Inheritance: MagLife0 -> MagLife -> MagLifeControlChara (size 0x80) -> MagLifeBillboard (size 0x84) -> MagLifePC
//   (Proven by .rodata RTTI strings D_002E9660..D_002E96A0 and constructor func_0011BF0C calling
//   MagLifeBillboard/MagLifeControlChara ctor func_0011A888 at 0x0011BF38 before writing +0x84).
//
// - Inherited fields from MagLifeControlChara (+0x00..+0x7F) & MagLifeBillboard (+0x80..+0x83) used in maglifepc.s:
//   * +0x00 (size 0x10): int m_unk00[4] (mode tuple copied to/from +0x30 and pushed/popped to m_submode_stack at +0x90)
//     - +0x00 (int m_unk00[0], current mode ID): 0x0011C22C: lw $v0, 0x0($s1); 0x0011C2C4: lw $v1, 0x0($a0)
//     - +0x04 (int m_unk00[1], mode tick counter): 0x0011AE58: lw $v0, 0x4($s0); 0x0011AE70: sw $v0, 0x4($s0)
//     - +0x08 (int m_unk00[2], mode substate/arg): 0x0011B3B0: sw $zero, 0x8($s0); 0x0011B8D8: lw $v1, 0x8($s1)
//     - +0x00..+0x0F (as 2x 64-bit Pair64/u_long128): 0x0011AB6C..0x0011AB74: sd $v0, 0x0($s0); sd $v1, 0x8($s0)
//   * +0x14 (size 0x04): void *m_vptr - 0x0011BF50: sw $v0, 0x14($fp) (_vt$9MagLifePC); 0x0011C250: lw $v0, 0x14($s1)
//   * +0x20 (size 0x04): MagScene *m_scene - 0x0011AE08: lw $a0, 0x20($s0); 0x0011B178: lw $a0, 0x20($s0)
//   * +0x30 (size 0x10): int m_last0..m_last3 - 0x0011AB54..0x0011AB64: ld $v0, 0x30($s0); ld $v1, 0x38($s0); sq $a1, 0x30($s0)
//   * +0x50 (size 0x04): int m_unk50 - 0x0011BD64: sw $a2, 0x50($s0) (in setActor__9MagLifePCP8DogActorii)
//   * +0x54 (size 0x04): int m_unk54 - 0x0011ACFC: lw $v1, 0x54($a3) (compared with 2); 0x0011BD68: sw $a3, 0x54($s0)
//   * +0x58 (size 0x04): DogActor *m_actor - 0x0011ADF4: lw $v0, 0x58($s0); 0x0011BD60: sw $a1, 0x58($s0)
//   * +0x78 (size 0x04): int m_zeroLink - 0x0011BDA0: sw $v0, 0x78($s0); 0x0011BDA4: sw $zero, 0x78($s0)
//   * +0x80 (size 0x04): float m_distance (inherited from MagLifeBillboard, initialized by func_0011A888)
//
// - Virtual table pointer position: +0x14 (void *m_vptr, inherited from MagLife0/MagLifeControlChara)
// - Virtual table entries evidenced in maglifepc.s:
//   * Entry 0 (+0x00): RTTI / type_info
//   * Entries 1..8 (+0x08..+0x40): Inherited virtual methods (includes overrides in this file whose exact
//     slot index is in _vt$9MagLifePC outside this slice: live__9MagLifePC, message__9MagLifePCiiPv,
//     setActor__9MagLifePCP8DogActorii, reset4MapJump__9MagLifePC, termWorld__9MagLifePC)
//   * Entry 9 (+0x48): virtual void vfunc09(int theMode, int theA)
//     Called in func_0011C1E8 at 0x0011C250..0x0011C26C and termWorld__9MagLifePC at 0x0011C430..0x0011C444:
//     lw $v0, 0x14($s0); addiu $v0, $v0, 0x48; lh $a0, 0x0($v0); lw $v0, 0x4($v0); jalr $v0
//   * Entry 16 (+0x80): virtual void vfunc16(BedPad *thePad) (MagLifePC__vfunc_16 at 0x0011B30C)
//
// - Total size: 0x220 bytes (544 bytes).
//   Deduced from constructor func_0011BF0C (0x0011BF0C..0x0011C1E4) initializing up to +0x21C
//   (0x0011C178: sw $zero, 0x21C($fp)) and 16-byte alignment required by quadword fields (+0x30, +0x90).
struct MagLifePC : public MagLifeBillboard {
    enum { MAX_SUBMODE_STACK = 4 };

    int m_unk84;                    // +0x84 (size 0x04) - 0x0011BF44: sw $zero, 0x84($fp); 0x0011AC98: sw $zero, 0x84($s1)
    int m_unk88;                    // +0x88 (size 0x04, DOUBTFUL: unreferenced; likely 16-byte alignment padding before +0x90)
    int m_unk8C;                    // +0x8C (size 0x04, DOUBTFUL: unreferenced; likely 16-byte alignment padding before +0x90)

    // Proposed name: m_submode_stack (4x 16-byte stack saving +0x00..+0x0F indexed by m_submode_level;
    // named after assert strings D_002EA0F8 / D_002EA138 "MAX_SUBMODE_STACK")
    u_long128 m_submode_stack[MAX_SUBMODE_STACK]; // +0x90 (size 0x40) - 0x0011BF64: sq $a0, 0x0($v1); 0x0011BCB4: sd $v1, 0x0($v0)

    // Proposed name: m_tired / m_stamina (range 0..1000, init 1000, tired when <= 300;
    // decremented by 10 in func_0011BDC0, incremented by 1 in func_0011BE00, queried/set in messages 18..20)
    int m_unkD0;                    // +0xD0 (size 0x04) - 0x0011AC08: lw $v0, 0xD0($s0) (slti 0x12D); 0x0011BF80: sw $v0, 0xD0($fp) (0x3E8)

    // Proposed name: m_tired_timer (counts 0..10 in func_0011BDC0 before subtracting 10 from m_unkD0)
    int m_unkD4;                    // +0xD4 (size 0x04) - 0x0011BDC0: lw $v0, 0xD4($a0); 0x0011BDDC: sw $v0, 0xD4($a0)

    // Exact original name from assert strings D_002EA0F8 & D_002EA138:
    // "m_submode_level >= 0 && m_submode_level < MAX_SUBMODE_STACK"
    int m_submode_level;            // +0xD8 (size 0x04) - 0x0011BC74: lw $v0, 0xD8($s0); 0x0011BCC8: sw $v0, 0xD8($s0)

    // Proposed name: m_atk_input (current result of func_0011ACF4: 0, -1, or m_unk21C + 1 when pad bit 11 is held)
    int m_unkDC;                    // +0xDC (size 0x04) - 0x0011ADA8: lw $v1, 0xDC($s1); 0x0011AF04: lw $v0, 0xDC($a0)

    // Proposed name: m_move_input (current result of func_0011AC24: 0 = idle, 1 = walk, 2 = run)
    int m_unkE0;                    // +0xE0 (size 0x04) - 0x0011AD90: lw $v1, 0xE0($s1); 0x0011ADAC: sw $v0, 0xE0($s1)

    // Proposed name: m_health_status (current result of func_0011AB88: 0 = tired, 1 = normal, 2 = low HP, 3/4 = special)
    int m_unkE4;                    // +0xE4 (size 0x04) - 0x0011AC8C: lw $v1, 0xE4($s1); 0x0011AD94: sw $v0, 0xE4($s1)

    // Proposed name: m_last_atk_input (previous tick value of m_unkDC, saved in func_0011AD6C)
    int m_unkE8;                    // +0xE8 (size 0x04) - 0x0011ADB4: sw $v1, 0xE8($s1); 0x0011B370: lw $v1, 0xE8($s0)

    // Proposed name: m_last_move_input (previous tick value of m_unkE0, saved in func_0011AD6C)
    int m_unkEC;                    // +0xEC (size 0x04) - 0x0011AC9C: lw $v0, 0xEC($s1); 0x0011AD9C: sw $v1, 0xEC($s1)

    // Proposed name: m_last_health_status (previous tick value of m_unkE4, saved in func_0011AD6C)
    int m_unkF0;                    // +0xF0 (size 0x04) - 0x0011AD8C: sw $v0, 0xF0($s1); 0x0011BEA8: sw $zero, 0xF0($s0)

    int m_unkF4;                    // +0xF4 (size 0x04) - 0x0011B388: sw $v0, 0xF4($s0) (-1); 0x0011C03C: sw $t9, 0xF4($fp) (-1)
    int m_unkF8;                    // +0xF8 (size 0x04) - 0x0011B328: sw $v0, 0xF8($s0) (1); 0x0011AEE4: sw $zero, 0xF8($s0)
    int m_unkFC;                    // +0xFC (size 0x04) - 0x0011C040: sw $t9, 0xFC($fp) (initialized to -1)
    int m_unk100;                   // +0x100 (size 0x04) - 0x0011C044: sw $t9, 0x100($fp) (initialized to -1)

    // Proposed name: m_stick_mag (analog stick magnitude from BedPad::getStick if >= m_unk1F8, else 0.0f)
    float m_unk104;                 // +0x104 (size 0x04) - 0x0011AC88: swc1 $f20, 0x104($s1); 0x0011ACD0: sw $zero, 0x104($s1)

    // Proposed name: m_stick_x (1st float output of BedPad::getStick, used as X in vecYaw in func_0011B128)
    float m_unk108;                 // +0x108 (size 0x04) - 0x0011AC3C: addiu $a1, $s1, 0x108; 0x0011B154: lwc1 $f1, 0x108($s0)

    // Proposed name: m_stick_y (2nd float output of BedPad::getStick, negated as Z in vecYaw in func_0011B128)
    float m_unk10C;                 // +0x10C (size 0x04) - 0x0011AC38: addiu $a2, $s1, 0x10C; 0x0011B150: lwc1 $f0, 0x10C($s0)

    // Proposed name: m_stick_yaw (world-space stick yaw angle in radians relative to DogCamera::getYaw)
    float m_unk110;                 // +0x110 (size 0x04) - 0x0011B1E8: swc1 $f1, 0x110($s0); 0x0011B1EC: lwc1 $f0, 0x110($s0)

    // Proposed name: m_stick_change (result of BedPad::getChange(), or 9999.0f on mode change in func_0011C2AC)
    float m_unk114;                 // +0x114 (size 0x04) - 0x0011AC70: swc1 $f0, 0x114($s1); 0x0011B13C: lwc1 $f1, 0x114($s0)

    int m_unk118;                   // +0x118 (size 0x04) - 0x0011C074: sw $zero, 0x118($fp)
    int m_unk11C[5];                // +0x11C..+0x12F (size 0x14, DOUBTFUL: unreferenced in this asm slice)

    // Proposed name: m_mode_timer (reset to 0 in func_0011C2AC, incremented each live() tick, set to -100 on dog command in vfunc_16)
    int m_unk130;                   // +0x130 (size 0x04) - 0x0011AEDC: sw $v0, 0x130($s0); 0x0011C2D0: sw $zero, 0x130($a0)

    // Proposed name: m_cur_mode (pointer to the active MagLifePCMode subobject selected in func_0011C2AC)
    MagLifePCMode *m_unk134;        // +0x134 (size 0x04) - 0x0011AE80: lw $v1, 0x134($s0); 0x0011B2D0: lw $v1, 0x134($a0)

    // Embedded state-machine mode instances (+0x138..+0x1AB, initialized in func_0011BF0C, selected in func_0011C2AC):
    MagLifePCModeNull m_mode_null;              // +0x138 (size 0x04) - 0x0011C048: sw $a0, 0x138($fp); 0x0011C2EC: addiu $v0, $a0, 0x138
    MagLifePCModeWait m_mode_wait;              // +0x13C (size 0x04) - 0x0011C014: sw $t0, 0x13C($fp); 0x0011C2F8: addiu $v0, $a0, 0x13C
    MagLifePCModeWalk2D m_mode_walk2d;          // +0x140 (size 0x04) - 0x0011C018: sw $t1, 0x140($fp); 0x0011C304: addiu $v0, $a0, 0x140
    MagLifePCModeRun2D m_mode_run2d;            // +0x144 (size 0x04) - 0x0011C020: sw $t2, 0x144($fp); 0x0011C310: addiu $v0, $a0, 0x144
    MagLifePCModeTurn m_mode_turn;              // +0x148 (size 0x08) - 0x0011C028: sw $t3, 0x148($fp); 0x0011C31C: addiu $v0, $a0, 0x148
    MagLifePCModeAtkWait2D m_mode_atk_wait2d;   // +0x150 (size 0x04) - 0x0011C030: sw $t4, 0x150($fp); 0x0011C328: addiu $v0, $a0, 0x150
    MagLifePCModeAtkMove2D m_mode_atk_move2d;   // +0x154 (size 0x04) - 0x0011C038: sw $t5, 0x154($fp); 0x0011C334: addiu $v0, $a0, 0x154
    MagLifePCModeAttacking m_mode_attacking;    // +0x158 (size 0x10) - 0x0011BFC4: addiu $v1, $fp, 0x158; 0x0011C340: addiu $v0, $a0, 0x158
    MagLifePCModeDamage m_mode_damage;          // +0x168 (size 0x0C) - 0x0011C08C: sw $t7, 0x168($fp); 0x0011C34C: addiu $v0, $a0, 0x168
    MagLifePCModeItem m_mode_item;              // +0x174 (size 0x04) - 0x0011C090: sw $s0, 0x174($fp); 0x0011C358: addiu $v0, $a0, 0x174
    MagLifePCModeDogGo m_mode_dog_go;           // +0x178 (size 0x04) - 0x0011C094: sw $s1, 0x178($fp); 0x0011C364: addiu $v0, $a0, 0x178
    MagLifePCModeDogCome m_mode_dog_come;       // +0x17C (size 0x04) - 0x0011C098: sw $s2, 0x17C($fp); 0x0011C370: addiu $v0, $a0, 0x17C
    MagLifePCModeDogStay m_mode_dog_stay;       // +0x180 (size 0x04) - 0x0011C09C: sw $s3, 0x180($fp); 0x0011C37C: addiu $v0, $a0, 0x180
    MagLifePCModeHold m_mode_hold;              // +0x184 (size 0x08) - 0x0011BFC8: addiu $t8, $fp, 0x184; 0x0011C388: addiu $v0, $a0, 0x184
    MagLifePCModeHoldAttack m_mode_hold_attack; // +0x18C (size 0x04) - 0x0011C0A8: sw $s5, 0x18C($fp); 0x0011C394: addiu $v0, $a0, 0x18C
    MagLifePCModeUnhold m_mode_unhold;          // +0x190 (size 0x04) - 0x0011C0AC: sw $s6, 0x190($fp); 0x0011C3A0: addiu $v0, $a0, 0x190
    MagLifePCModeRide m_mode_ride;              // +0x194 (size 0x0C) - 0x0011BFEC: addiu $s7, $fp, 0x194; 0x0011C3AC: addiu $v0, $a0, 0x194
    MagLifePCModeRoped m_mode_roped;            // +0x1A0 (size 0x04) - 0x0011C0C0: sw $v0, 0x1A0($fp); 0x0011C3B8: addiu $v0, $a0, 0x1A0
    MagLifePCModeReload m_mode_reload;          // +0x1A4 (size 0x04) - 0x0011C0D0: sw $v0, 0x1A4($fp); 0x0011C3C4: addiu $v0, $a0, 0x1A4
    MagLifePCModeHug m_mode_hug;                // +0x1A8 (size 0x04) - 0x0011C124: sw $v0, 0x1A8($fp); 0x0011C3D0: addiu $v0, $a0, 0x1A8

    int m_unk1AC;                   // +0x1AC (size 0x04) - 0x0011B90C: sw $v1, 0x1AC($s1) (high short of msg 23 arg); 0x0011C130: sw $t9, 0x1AC($fp) (-1)
    int m_unk1B0;                   // +0x1B0 (size 0x04) - 0x0011B910: sw $v0, 0x1B0($s1) (low short of msg 23 arg); 0x0011C134: sw $t9, 0x1B0($fp) (-1)

    // Proposed name: m_forced_status (if >= 0, overrides health/tired status in func_0011AB88; set by msg 24)
    int m_unk1B4;                   // +0x1B4 (size 0x04) - 0x0011AB9C: lw $v1, 0x1B4($s0); 0x0011B928: sw $s0, 0x1B4($s1)

    int m_unk1B8;                   // +0x1B8 (size 0x04) - 0x0011C12C: sw $v0, 0x1B8($fp) (initialized to 1)
    int m_unk1BC;                   // +0x1BC (size 0x04, DOUBTFUL: unreferenced; likely padding to align DogVector at +0x1C0)
    DogVector m_unk1C0;             // +0x1C0 (size 0x10) - 0x0011C01C: addiu $a2, $fp, 0x1C0; 0x0011C13C..0x0011C148: swc1 (0,0,0,1)
    DogVector m_unk1D0;             // +0x1D0 (size 0x10) - 0x0011C024: addiu $a3, $fp, 0x1D0; 0x0011C14C..0x0011C158: swc1 (0,0,0,1)
    int m_unk1E0[6];                // +0x1E0..+0x1F7 (size 0x18, DOUBTFUL: unreferenced in this asm slice)

    // Proposed name: m_stick_deadzone (init 0.1f, range [0.0f, 1.0f), compared with stick magnitude in func_0011AC24)
    float m_unk1F8;                 // +0x1F8 (size 0x04) - 0x0011AC64: lwc1 $f1, 0x1F8($s1); 0x0011B9C0: swc1 $f20, 0x1F8($s0)

    // Proposed name: m_cos_angle1 (init cosf(5 deg), set to cosf(deg * PI / 180) for deg in (0, 90) in func_0011B964 case 7)
    float m_unk1FC;                 // +0x1FC (size 0x04) - 0x0011BA4C: swc1 $f0, 0x1FC($s0); 0x0011C1B0: swc1 $f0, 0x1FC($fp)

    // Proposed name: m_cos_angle2 (init cosf(89 deg), set to cosf(deg * PI / 180) for deg in (0, 90) in func_0011B964 case 8)
    float m_unk200;                 // +0x200 (size 0x04) - 0x0011BAB8: swc1 $f0, 0x200($s0); 0x0011C1B4: swc1 $f0, 0x200($fp)

    float m_unk204;                 // +0x204 (size 0x04) - 0x0011BADC: swc1 $f20, 0x204($s0) (range [0, 10)); 0x0011C160: swc1 $f6, 0x204($fp) (0.07f)
    float m_unk208;                 // +0x208 (size 0x04) - 0x0011BB50: swc1 $f0, 0x208($s0) (deg / 180.0f); 0x0011C164: swc1 $f5, 0x208($fp) (0.9f)

    // Proposed name: m_stick_change_min (init 0.001f, range (0, 1); compared against m_unk114 in func_0011B128)
    float m_unk20C;                 // +0x20C (size 0x04) - 0x0011B140: lwc1 $f0, 0x20C($s0); 0x0011BB74: swc1 $f20, 0x20C($s0)

    float m_unk210;                 // +0x210 (size 0x04) - 0x0011B74C: lwc1 $f12, 0x210($s1); 0x0011BBB8: swc1 $f20, 0x210($s0) (init 45.0f)
    float m_unk214;                 // +0x214 (size 0x04) - 0x0011B72C: lwc1 $f1, 0x214($s1); 0x0011BBFC: swc1 $f20, 0x214($s0) (init 20.0f)
    float m_unk218;                 // +0x218 (size 0x04) - 0x0011BC24: swc1 $f20, 0x218($s0); 0x0011C174: swc1 $f0, 0x218($fp) (init 0.0f)

    // Proposed name: m_equipped_weapon (returned by func_0011CB70 in vfunc_16; +1 returned by func_0011ACF4 when attacking)
    int m_unk21C;                   // +0x21C (size 0x04) - 0x0011AD58: lw $v0, 0x21C($a3); 0x0011B364: sw $v0, 0x21C($s0)
};


// ============================================================================
// 3. Other Classes & Structs Evidenced in maglifepc.s
// ============================================================================

// Stack item query structure used in func_0011B07C (10-element array at 0x00($sp)..0x13F($sp)).
// - No vptr.
// - Total size: 0x20 bytes (deduced from loop stride `addiu $v1, $v1, 0x20` at 0x0011B0BC for 10 items = 0x140 bytes).
struct MagPCItemData {
    DogVector m_unk00;              // +0x00 (size 0x10) - 0x0011B0A8..0x0011B0B4: swc1 $f0, 0x0/0x4/0x8($v1); swc1 $f1, 0xC($v1) (1.0f)
    // Exact field name from assert string D_002E9F48: "itemdata[0].m_obj_id != 0"
    int m_obj_id;                   // +0x10 (size 0x04) - 0x0011B0E0: lw $v0, 0x10($sp); 0x0011B104: lw $a2, 0x10($sp)
    int m_unk14[3];                 // +0x14 (size 0x0C, DOUBTFUL: unreferenced in caller; filled by func_0011C64C)
};

// Partial layout of BedPad fields accessed directly in maglifepc.s (when not already defined in bed/bedpad.h):
// - No vptr evidenced here; methods called: getStick__C6BedPadPfT1 (0x0011AC50), getChange__C6BedPad (0x0011AC5C).
// - Total size: unknown from this file alone (passed by pointer).
struct BedPad_PartialLayout {
    unsigned char m_pad00[0x78];    // +0x00..+0x77
    // Proposed name: m_buttons_held (bit 11 tested in func_0011ACF4 via PadBits::b11)
    unsigned short m_unk78;         // +0x78 (size 0x02) - 0x0011AD40: lhu $v0, 0x78($a1) (srl 11, andi 1)
    // Proposed name: m_buttons_trig (bits 10, 12, 13, 14, 15 tested in MagLifePC__vfunc_16)
    unsigned short m_unk7A;         // +0x7A (size 0x02) - 0x0011B408: lhu $v0, 0x7A($s2) (bit 14); 0x0011B494: lhu $v0, 0x7A($s2) (bit 10); 0x0011B514: lhu $a0, 0x7A($s2) (bits 12,13,15)
};

// Partial layout of DogEntity / DogActor fields accessed directly in maglifepc.s:
// - Total size of DogActor: 0x4D0 bytes (1232 bytes).
//   Deduced from reset4MapJump__9MagLifePC at 0x0011BEAC..0x0011BECC:
//   `addiu $v1, $zero, 0x4D0; mult $a0, $v0, $v1; addu $s0, $s0, $a0; addiu $s0, $s0, 0x2920`
struct DogActor_PartialLayout {
    unsigned char m_unk00[0x40];    // +0x00..+0x3F
    // Proposed name: m_pos (entity position vector, read and updated in message__9MagLifePCiiPv case 21)
    DogVector m_unk40;              // +0x40 (size 0x10) - 0x0011B778: lq $v0, 0x40($t1); 0x0011B810: sq $v0, 0x40($v1)
    int m_unk50;                    // +0x50 (size 0x04, DOUBTFUL: unreferenced in this file)
    // Proposed name: m_rot (yaw rotation in radians, normalized via normalizeRot__9DogEntity right after write)
    float m_unk54;                  // +0x54 (size 0x04) - 0x0011B898: swc1 $f0, 0x54($s0)
    unsigned char m_unk58[0x38];    // +0x58..+0x8F
    int m_unk90;                    // +0x90 (size 0x04) - 0x0011B808: sw $a1, 0x90($v1) (1); 0x0011B8A0: sw $v0, 0x90($s0) (1)
    unsigned char m_unk94[0x43C];   // +0x94..+0x4CF (total size 0x4D0)
};

// Partial layout of MagScene (pointed to by MagLifeControlChara::m_scene at +0x20):
// - Total size: > 0x2BD90 bytes (unknown exact end from this file alone).
struct MagScene_PartialLayout {
    unsigned char m_unk00000[0x22B0];
    float m_unk22B0;                // +0x22B0 (size 0x04) - 0x0011AE1C: swc1 $f0, 0x22B0($a0); 0x0011AE20: lwc1 $f1, 0x22B0($a0)
    unsigned char m_unk22B4[0x66C];
    // Proposed name: m_actors (array of 128 DogActors of size 0x4D0 each = 0x26800 bytes, indexed with < 0x80 bound check)
    unsigned char m_actors[0x80][0x4D0]; // +0x2920..+0x2911F (size 0x26800) - 0x0011BEAC..0x0011BECC: mult 0x4D0, addiu 0x2920
    unsigned char m_unk29120[0x1A50];
    // Embedded DogCamera instance at +0x2AB70 (passed as `this` to getYaw__9DogCamera)
    unsigned char m_camera[0x04];   // +0x2AB70 - 0x0011B17C..0x0011B188: addu $a0, $at, $a0 (0x2AB70); jal getYaw__9DogCamera
    unsigned char m_unk2AB74[0x11AC];
    // Embedded companion dog controller object at +0x2BD20 (passed as `this` to func_0012B65C / func_0012B4A0 / func_0012B5F8)
    unsigned char m_dog_ctrl[0x6C]; // +0x2BD20 - 0x0011AFAC..0x0011AFBC: addu $a0, $at, $a0 (0x2BD20); j func_0012B65C
    int m_unk2BD8C;                 // +0x2BD8C (size 0x04) - 0x0011B500..0x0011B508: lui $at, 3; addu $at, $at, $v0; lw $v0, -0x4274($at)
};

#endif // MAG_MAGLIFEPC_H
