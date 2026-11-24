# R25: RX library types (Arc the Lad 2002 debug build + PoPoLoCrois)

Status: research only, nothing applied. Header drafts: `build/research/R25/include/rx/` (rxtype.h, rxfile.h, rxsnd.h, rxsys.h, rxth.h, sce_sif_types.h).

## 1. What the debug info actually contains (important limitation)

`disc/arc_koga/DATAIMG_KOGA_MAIN.ELF` has a `.mdebug` (HDRR at file offset 0x14DB1C, 374 file descriptors, 197k local symbols, only 0x2166 aux entries). Parsed with `build/research/R25/md.py`.

- The 31 RX file descriptors (rxsnd.c .. rxhddth.c, FDR 176-206) carry **no stabs and no types at all**: only `stFile`, `stProc`/`stStaticProc` (name, address, `stEnd` = size), `stStatic` (static variables with address) and the two `gcc2_compiled.` labels. The RX library was linked prebuilt, without -g. So there are **no struct members, no function parameters and no return types for any rx* function** in this donor. The FDRs `xseqdef.h` and `rxthmac.h` (also `../../release/include/rxthmac.h`) exist only because they hold static/inline code.
- The Arc *game* files (kx_*.c, kg_*.c, kw_*.c, ...: 272 of them, compiled with -g, stabs-in-mdebug) all include the same RX public headers, and GCC emitted every typedef/struct/enum of those headers (used or not): 35 to 41 RX-related stabs per file, identical in all files (type numbers shift between files). That is the only RX type information: **the public API typedefs** (section 2). GCC does not emit prototypes of extern functions, and the game functions never use RX types in locals/params, so there are no prototypes either.
- PoPoLoCrois (SCPS_150.63, DWARF1 `.debug`, 5.4 MB) was also probed as a richer donor. Its RX types are only the graphics side (RXPacket, RXBone, RXColi*, rxgeom.h, rxpkt.h, rxvram.h, rxstate.h, RXMcPortInfo, plus tagRXSndUt* = the rxsndut helper layer). Nothing for rxsnd/snd*/rxfile/rxsys/rxth/filecdrom; the sndut types do not belong to our 25 files (no rxSndUt names in our symbols). KOGA_MAIN_OLD.ELF carries the same RX stabs (same numbers 489-558); SCUS_972.31 and SCPS_000.00 carry none.
- Function-pointer typedefs in stabs have **no parameter lists** (`f1` = returns int, `f19` = returns void, `f29` = returns void*, `f475` = returns BOOL).

## 2. Recovered types (all of them; see the header drafts)

Order in the stabs = include order in the game: rxtype-ish base (BOOL, int32..uint8; enum RX_MACHINE_TYPE) -> rxfile.h -> rxsnd.h (SndStr) -> SCE sifrpc types -> enums RX_VIDEO_MODE/RX_COUNTRY/RX_LANGUAGE -> rxsys.h (Malloc/Realloc/Free/Print funcs, RXSysRpcClientData) -> rxth.h.

| Type | Definition (size, members at byte offsets) |
|---|---|
| tagRXFileBranchParam / RXFileBranchParam | 20: u32 offset@0, u8 enable@4, u8 group@5, u8 count@6, u8 max@7, u32 jumpOffset@8, RXFileBranchCallback callback@0xC, u32 data@0x10 |
| tagRXFileStrMarkParam / RXFileStrMarkParam | 12: u32 offset@0, u8 enable@4, u8 group@5, s16 pad@6, u32 param@8 |
| tagRXFileStrMarkInfo / RXFileStrMarkInfo | 8: u32 offset@0, u32 param@4 |
| RXFileBranchCallback, RXFileLoadFunc, RXFileGetSizeFunc, RXFileCdromSearchFileFunc | `int (*)()` |
| RXFileHddIOErrorFunc | `void (*)()` |
| RXSndStrCallback, RXSndStrMarkCallback | `void (*)()` |
| RXSndStrBranchCallback | `BOOL (*)()` (BOOL = int) |
| RXSndStrFormatType | enum NONE=-1, ADPCM=0, PCM=1 |
| RXMallocFunc, RXReallocFunc | `void *(*)()` |
| RXFreeFunc | `void (*)()` |
| RXPrintFunc | `int (*)()` |
| RXThBgFunc, RXThChangeFunc | `void (*)()` |
| RXThWakeupFunc | `int (*)()` |
| enum RX_THREAD_INDEX | MAIN=0, BG=1, MAX=2 |
| enum RX_MACHINE_TYPE | EB2000=0, T10000=1, MAX=2 |
| enum RX_VIDEO_MODE | NTSC=0, PAL=1, MAX=2 |
| enum RX_COUNTRY | JAPAN=0, USA=1, EUROPE=2, MAX=3 |
| enum RX_LANGUAGE | JAPANESE=0, ENGLISH=1, GERMANY=2 (sic), FRENCH=3, ITALIAN=4, SPANISH=5, MAX=6 |
| tagRXSysRpcClientData / RXSysRpcClientData | 128: s32 useSema@0, sceSifClientData sceClientData@0x40 (40 bytes) |
| sceSif* rpc/client/receive/serve/queue | SDK types, listed in sce_sif_types.h with offsets (rpc_data 16, client 40, receive 28, serve 68, queue 24) |

Not recovered (no source): layouts of the RX internal structures (file manager `gFileMgr`, file slots, request records, sound system/stream/SE state, thread tables) and every function prototype. Those can only come from our own asm (section 4) or hand analysis.

## 3. Proposed header split

By evidence (stab order + names): `rx/rxtype.h` (BOOL/intNN + config enums), `rx/rxfile.h`, `rx/rxsnd.h`, `rx/rxsys.h`, `rx/rxth.h`. The Arc FDR list also has `rxthmac.h` (a macro header with inline thread/sema helpers). SCE sif types belong to the SDK header (`eekernel`/`sifrpc.h`), do not redeclare them. Type and enum names are original; header file names are inferred (the mdebug has no include-file records).

## 4. Cross-check against our binary (SLUS_214.48, via tools/disasm.py)

All agree; no disagreement found:

- **RXFileStrMarkParam / list node**: `EnableMark` (0x2457A8) walks the list at manager+0xC4: node next@0, byte at node+8 = enable (stored with sb), byte at node+9 = group (compared with a1). Node = {next@0, RXFileStrMarkParam@4}: enable at 4+4=8, group 4+5=9. Agrees. `EnumMark` (0x2457E8) reads node+4 (offset) and node+0xC (param) and writes {offset, param} pairs stepping 8 bytes: agrees with RXFileStrMarkParam.offset/param and with RXFileStrMarkInfo (8 bytes).
- **RXFileBranchParam**: `EnableBranch` (0x245240) uses the list at manager+0xAC, enable at node+8, group node+9 (same 4-byte node header). `InsertRequestBranchAdjust` (0x244B40) reads param bytes at +4 (enable), +6 (count), +7 (max), +0xC, +0 (offset), +8 (jumpOffset): exactly the Arc offsets 0,4,6,7,8,0xC. Size 20 not directly checked.
- **RXSysRpcClientData**: `rxSysRpcOpen` (0x242188) stores the semaphore at +0, calls sceSifBindRpc(this+0x40, id, 0) and polls `lw 0x64(this)` = sceClientData.serve (0x40+0x24). `rxSysRpcCall` (0x2422A8) calls sceSifCallRpc(this+0x40, ...) with `RpcCallFinishedCallback` receiving `this`. Agrees exactly with useSema@0, sceClientData@0x40, serve@0x24.
- Manager offsets seen only in our asm (not in the debug info): RXFile manager has a request-list pair at +0x8C/+0x90, branch list at +0xAC, a circular mark list with sentinel at +0xB4 (head link +0xB8) and the enabled-mark list at +0xC4. Hypotheses for member names: `m_requestList@0x8C`, `m_branchList@0xAC`, `m_markList@0xC4`.

## 5. API boundary used by the game code (src/)

Game code only touches these RX functions (through `asm("rx...")` aliases and extern declarations, currently declared with `(...)`/int aliases, i.e. rules_check offenders):

- file: rxFileClose, rxFileSeek(int,int,int), rxFileSync, rxFileGetStrPtr, rxFileGetStrPtrOffset, rxFileGetStrBufferSize, rxFileGetStrLeft, rxFilePauseStr (src/game/gamman.cpp, src/mnu/mnuSelectLanguage.cpp, src/snd/rxmpeg.cpp, src/unk/001B64C4.cpp, src/unk/001BE2CC.cpp)
- sound: rxSndSetOutputMode(int) (gamman.cpp, wrapper GamUseSound), rxSndSetMasterVolume(int,int), rxSndSeSetMasterVolume(int,int), rxSndReverbSetDepth (gamsnd.cpp), rxSndSePlay(6 ints), rxSndSeStop(int,int), rxSndSeGetStatus(int), rxSndSePause(int,int,int), rxSndSeSetReverb(int,int), rxSndSeSetVolume(int,int,int), rxSndSeSetPitch(int,float), rxSndPcmOpen(int,int,int), rxSndXVabClose (src/snd/rxmpeg.cpp, sndman.cpp)
- system/thread: rxSysTerm (sndman.cpp), rxThAddBgFunc (rxmpeg.cpp), rxThVSync(int) (magsystem.cpp), rxGsVSync(int) (gamman.cpp, magsystem.cpp, mnuSelectLanguage.cpp, 001B64C4/001BE2CC/002039A4).
- No game file uses an RX struct or callback typedef directly yet (the game passes plain ints). The callbacks (RXSndStrCallback, RXSndStrMarkCallback, RXSndStrBranchCallback, RXFileBranchCallback) are the ones the port boundary will need if the game registers streaming callbacks (check rxmpeg.cpp once decompiled).
- Calls to func_00237340 etc. (most frequent, 0x237xxx) are not RX: they sit below rx/rxsnd (0x237D00).

## 6. Confidence and next steps

- Types in section 2: high (compiler-emitted debug info; three of them verified against our asm). Enum names and values exact; header file names inferred.
- Function prototypes: not obtainable from these donors. Options: derive from our asm per function (callers' register setup, as in section 4), or look in `disc/` (tools/disc_scan.py) for another RX build compiled with -g whose rx*.c FDRs have stabs. Appendix A (Arc symbol names and sizes, including static functions such as SlotAlloc/SetBranch/CheckStreamLeft and static variables such as gFileMgr, gIsInit, threadTable) can name unnamed functions and data in rx/* by size and call graph.

## Appendix A: Arc 2002 RX symbols per source file (names from .mdebug; (s)=static function, sizes in bytes; statics = static variables)

Useful to name our unnamed func_.../D_... in rx/*: same file order as our splits. The 2002 layout may differ from ours, so match by size and call graph, never by address.

**rxsnd.c**
- functions: ThreadChangeCallback(s):8, rxSndInit:36, rxSndTerm:32
- statics: -

**sndsys.c**
- functions: rxSndSysInit:92, rxSndSysTerm:128, rxSndProc:224, rxSndSetOutputMode:72, rxSndSetDebugMode:80, rxSndGetDebugMode:12, rxSndSetTickMode:76, rxSndSetMasterVolume:196, rxSndChangeThread:40, rxSndVoiceGetAllEnvelope:92, rxSndVoiceEnableAutoAlloc:60, rxSndCentToPitch:108, _SndSysInit:48, _SndSysTerm:8, _SndSysProc:8, _SndSysGetCurrentThread:12, _SndSysGetMasterVolumeL:12, _SndSysGetMasterVolumeR:12, _SndGetZeroBuffer:12, _SndDummy:8
- statics: gThreadID, gaNoteToPitch, gaCentToPitch, gInfo, gZeroBuffer

**sndiop.c**
- functions: rxSndIopMalloc:120, rxSndIopMallocR:124, rxSndIopFree:48, rxSndIopWrite:124, rxSndIopRead:112, rxSndIopClear:120, rxSndIopWriteMalloc:96, rxSndIopGetFreeSize:52, rxSndIopGetRunFreeSize:52, _SndIopInit:8, _SndIopTerm:8
- statics: -

**sndspu.c**
- functions: rxSndSpuBlockRegist:280, rxSndSpuBlockRelease:84, rxSndSpuSetBlock:96, rxSndSpuGetBlock:52, rxSndSpuMalloc:36, rxSndSpuMallocR:36, rxSndSpuFree:8, rxSndSpuWrite:84, rxSndSpuRead:84, rxSndSpuIopWrite:80, rxSndSpuIopRead:84, rxSndSpuClear:80, rxSndSpuSync:144, rxSndSpuGetFreeSize:12, rxSndSpuGetRunFreeSize:76, _SndSpuInit:288, _SndSpuTerm:8, GetHeapBlock(s):44, HeapMalloc(s):1068, HeapFree(s):536, HeapFreeBlock(s):276, HeapSlotAlloc(s):40, HeapSlotFree(s):32, HeapDump(s):508
- statics: gInfo

**sndreverb.c**
- functions: rxSndReverbSetType:120, rxSndReverbSetDepth:132, rxSndReverbSetFeedback:116, rxSndReverbSetDelayTime:116, _SndReverbInit:36, _SndReverbTerm:8
- statics: gInfo

**sndformat.c**
- functions: rxSndXVabOpen:1040, rxSndXVabClose:364, rxSndXVabOpenSync:212, rxSndXVabGetIopHeaderAddr:148, rxSndXVabGetSpuBodyAddr:148, rxSndXVabGetHeaderPtr:8, rxSndXVabGetHeaderSize:28, XVabGetBody(s):200, rxSndXVabGetBodyPtr:48, rxSndXVabGetBodySize:48, rxSndXSeqOpen:788, rxSndXSeqClose:324, rxSndXSeqSetBank:188, rxSndXSeqGetIopDataAddr:148, rxSndXSeqGetSize:28, _SndFormatInit:8, _SndFormatTerm:8, RiffGetType(s):8, RiffGetVersion(s):8, RiffGetSize(s):60, RiffFindChunk(s):128, RiffFindChunkOld(s):92, RiffFindChunkNew(s):92, RiffGetChunkData(s):52, RiffGetChunkSize(s):52
- statics: gXVabInfo, gXSeqInfo

**xseqdef.h**
- functions: xseqVariableValue(s):60
- statics: -

**sndbgm.c**
- functions: rxSndBgmSetMasterVolume:128, rxSndBgmPlay:220, rxSndBgmStop:204, rxSndBgmStopAll:76, rxSndBgmPause:196, rxSndBgmGetStatus:60, rxSndBgmSetChannelVolume:192, rxSndBgmSetTrackVolume:192, rxSndBgmSetReverb:152, rxSndBgmSetVolume:292, rxSndBgmSetPitch:168, rxSndBgmSetSpeed:168, _SndBgmInit:88, _SndBgmTerm:8, _SndBgmProc:368, _SndBgmGetMasterVolumeL:12, _SndBgmGetMasterVolumeR:12
- statics: gInfo

**sndse.c**
- functions: rxSndSeSetMasterVolume:128, rxSndSePlay:280, rxSndSePlayNote:280, rxSndSeStop:204, rxSndSeStopAll:76, rxSndSeGetStatus:60, rxSndSeSetReverb:152, rxSndSeSetVolume:292, rxSndSeSetPitch:168, rxSndSeSetSpeed:168, _SndSeInit:88, _SndSeTerm:8, _SndSeProc:376, _SndSeGetMasterVolumeL:12, _SndSeGetMasterVolumeR:12
- statics: gInfo

**sndpcm.c**
- functions: rxSndPcmSetMasterVolume:128, rxSndPcmSetMasterReverb:92, rxSndPcmOpen:484, rxSndPcmClose:208, rxSndPcmCloseAll:52, rxSndPcmGetStatus:64, rxSndPcmGetFreeSize:84, rxSndPcmWrite:736, rxSndPcmWriteTerm:340, rxSndPcmRegistCallback:336, rxSndPcmSetData:64, rxSndPcmGetData:64, rxSndPcmSetProtectCode:156, rxSndPcmPause:152, rxSndPcmSetVolume:280, _SndPcmInit:140, _SndPcmTerm:8, _SndPcmProc:540, _SndPcmGetMasterVolumeL:12, _SndPcmGetMasterVolumeR:12
- statics: gInfo, gPTermBuffer

**sndadpcm.c**
- functions: rxSndAdpcmSetMasterVolume:128, rxSndAdpcmOpen:36, rxSndAdpcmOpenPriority:32, AdpcmOpen(s):716, rxSndAdpcmClose:208, rxSndAdpcmCloseAll:52, rxSndAdpcmGetStatus:56, AdpcmGetFreeSize(s):92, rxSndAdpcmGetFreeSize:32, AdpcmWrite(s):2196, rxSndAdpcmWrite:28, rxSndAdpcmWriteTerm:372, rxSndAdpcmRegistCallback:288, rxSndAdpcmSetData:56, rxSndAdpcmGetData:56, rxSndAdpcmPause:144, rxSndAdpcmSetReverb:144, rxSndAdpcmSetVolume:400, rxSndAdpcmSetPitch:160, rxSndAdpcmSetVoice:164, _SndAdpcmInit:140, _SndAdpcmTerm:8, _SndAdpcmProc:604, _SndAdpcmGetMasterVolumeL:12, _SndAdpcmGetMasterVolumeR:12
- statics: gAdpcmTerm, gInfo, gLRBufferL, gLRBufferR

**rpcclient.c**
- functions: RpcOpen(s):228, RpcClose(s):8, RpcCall(s):304, _SndRpcInit:56, _SndRpcTerm:12, _SndRpcCall:412, _SndRpcPacketOpen:148, _SndRpcPacketGetReceive:24, _SndRpcPacketGetSend:28, _SndRpcPacketClose:60, _SndRpcPacketFlush:144
- statics: gRpcClientData, gaRpcSend, gaRpcReceive

**rxsys.c**
- functions: rxSysDummyFunc(s):36, rxSysSetMallocFunc:40, rxSysSetMallocRFunc:40, rxSysSetReallocFunc:40, rxSysSetFreeFunc:40, SearchCrlf(s):68, SearchBlank(s):68, SkipCrlf(s):64, SkipBlank(s):64, strcpyn(s):56, strcpynlower(s):108, rxSysIsModuleLoaded:140, ExtractFileName(s):176, ExtractFileExt(s):132, CheckComment(s):44, CheckSkipName(s):64, rxSysAppendModuleName(s):60, AppendSkipModuleName(s):68, rxSysUpdateCdMmode(s):68, rxSysRebootIop(s):180, rxSysLoadIopModule(s):448, rxSysLoadIopconf(s):136, rxSysCdInit(s):88, rxSysLoadIopModules(s):476, rxSysIsDeviceEnable:100, rxSysGetBootDevice:12, rxSysScanBootDevice(s):124, strsearch(s):108, rxSysLoadSystemFile(s):568, rxSysDevInit:104, ScanRomVersion(s):84, rxSysInit:484, SearchSection(s):272, GetIdentString(s):204, SearchIdent(s):288, rxSysGetIniString:392, GetIdentCount(s):192, GetIdent(s):252, rxSysGetIniIdentCount:52, rxSysGetIniIdentString:84, rxSysGetSystemString:64, rxSysGetSystemIdentCount:56, rxSysGetSystemIdentString:64, rxSysRpcBind2(s):208, TtypRpcInit(s):64, TtypPrint(s):84, tcpPrintInit(s):128, tcpPrintTerm(s):68, rxSysTerm:60, rxSysGetIopRebooted:12, rxSysSetIopImageName:16, rxSysGetMachineType:8, rxSysGetSceLibraryVersion:8, rxSysGetVideoMode:12, rxSysGetVSyncPerSecond:44, rxSysGetProductNumber:12, rxSysGetProductVersion:12, rxSysGetCountry:12, rxSysGetLanguage:12, rxSysGetWarningMode:12, rxSysGetBootDir:12, rxSysGetBootName:12, rxSysGetMemorySize:28, IsCdFileName(s):128, SkipDriveName(s):188, rxSysSetBootFileName:388, rxSysGetMCardName:12, rxSysSetPrintFunc:16, AllocSyncFunc(s):8, IsTcpPrint(s):44, printf:456, SysRpcInit(s):8, SysRpcTerm(s):8, CreateSemaDirect(s):36, rxSysRpcOpen:216, rxSysRpcClose:60, rxSysRpcCall:204, RpcCallFinishedCallback(s):36, SysSifInit(s):60, SysSifTerm(s):44, AllocLockZone(s):100, AllocUnlockZone(s):12, AllocLockZoneP(s):100, AllocUnlockZoneP(s):12, UpdateCdMmode(s):40, rxSysOpen:80, rxSysClose:56, rxSysRead:88, rxSysWrite:88, rxSysLseek:88, rxSysIoctl:88, rxSysLockSif:8, rxSysUnlockSif:8, ExceptionHandler(s):556, rxSysAddExceptionHandler:168, rxSysRemoveExceptionHandler:152
- statics: printfFunc, sysLibVerStr, sysNumber, sysVersion, sysCountry, sysLanguage, sysVideoMode, sysWarnMode, bootDevice, systemFileLoaded, iopRebooted, romversion, stdoutDesc, gUseTtypPort, bootdevname, bootdir, bootname, mcardtop, moduleCount, tableVideoMode, tableCountry, tableLanguage, tableWarning, deviceName, printCount, gIopImageName, moduleName, iopconf, skipirx, atskipirx, atusbskipirx, deviceEnable, fileBuffer, isInit.177, mcardname, gTtypClientData, gSifPrintSema, gSifUseSema, printBuffer, regInfo, isEnter.370, oldHandler, isHandled

**rxdebug.c**
- functions: rxSysMemDump:360, rxSysMonVSync(s):8, rxSysMonClearLine(s):68, rxSysMonScrollScreen(s):100, localLoadImage(s):116, loadScreen(s):240, rxSysMonDrawScreen(s):72, rxSysMonNewLine(s):144, rxSysMonPutChar(s):132, rxSysMonPrintFunc(s):72, rxSysMonSetDispMask(s):40, rxSysMonClearScreen(s):104, rxSysMonSetWait:20, rxSysMonSetColor:16, rxSysExit(s):68, rxSysMonOpen:252, rxSysMonClose:268
- statics: monOldPrintFunc, monWaitCrlf, monWaitTerm, monIsInit, mFontData8x8, monScreen, gsPacketBuffer.90, monDispEnv, monLocateX, monLocateY, monColor, oldExitCode

**rxdma.c**
- functions: rxSysDmaInit:8, rxSysDmaTerm:8
- statics: -

**rxfile.c**
- functions: _FileThreadChangeCallback(s):8, rxFileInit:280, rxFileTerm:80, rxFileDebug:16, rxFileThChange:28, rxFileSetDeviceStatus:80, rxFileGetDeviceStatus:64, rxFileSetDevice:28, rxFileGetDevice:28, rxFileSetThreadDevice:28, rxFileSetRootDir:44, rxFileGetRootDir:36, rxFileChgDir:44, rxFileGetDir:36, rxFilePushDir:32, rxFilePopDir:32, rxFileGetLastName:36, rxFileSetDivideSize:48, rxFileProc:8, rxFileOpen:36, rxFileOpenStr:52, rxFileOpenDirect:36, rxFileClose:60, rxFileCloseAsync:60, rxFileGetStatus:108, rxFileRead:264, rxFileWrite:240, rxFileSeek:132, rxFileSync:128, rxFileSetBranch:84, rxFileEnableBranch:60, rxFilePauseStr:104, rxFileGetStrPtr:68, rxFileGetStrPtrOffset:56, rxFileGetStrBufferSize:56, rxFileGetStrLeft:100, rxFileIncStrPtr:328, rxFileGetStrPos:88, rxFileSetStrMark:84, rxFileEnableStrMark:60, rxFileEnumStrMark:84, SlotAlloc(s):292, SlotAllocDirect(s):924, SlotAlloc_FinishedCreate(s):80, SlotAlloc_FinishedGetSize(s):136, SlotFree(s):132, CheckStreamLeft(s):108, InsertNormalRequest(s):44, InsertStreamRequest(s):224, InsertRequestBranchAdjust(s):600, InsertRequestEOFAdjust(s):72, InsertRequestDivideAdjust(s):276, InsertRequestBottom(s):248, InsertRequestBottom_FinishedRequest(s):120, SetBranch(s):516, EnableBranch(s):44, AddSectionInfo(s):200, RemoveSectionInfo(s):296, RemoveAllSectionInfo(s):192, GetSectionInfoPosition(s):192, SetMark(s):464, EnableMark(s):44, EnumMark(s):188, rxFileSetDeviceName:80, rxFileGetDeviceName:76
- statics: gFileMgr

**../../release/include/rxthmac.h**
- functions: FORCE_EI(s):76
- statics: -

**rxfileut.c**
- functions: rxFileLoad:60, rxFileGetSize:44, rxFileSetFileLoadFunc:72, rxFileSetFileGetSizeFunc:72, rxFileGetSizeDirect:164, rxFileLoadDirect:244, rxFileSave:192
- statics: -

**rxfilesif.c**
- functions: rxSifMakePath(s):260, rxSifLoadExec:260, rxSifLoadFile:336, rxSifLoadModule:332, rxSifLoadModules:128, rxSifRebootIop:144
- statics: -

**filedev.c**
- functions: _FileDeviceInit:56, _FileDeviceTerm:36, _FileDeviceGetProc:56
- statics: gaProc

**filehost.c**
- functions: _FileDeviceHostInit:120, _FileDeviceHostTerm:8, HostMakeSifPath(s):8, HostSetStatus(s):8, HostGetStatus(s):32, HostGetSize(s):184, HostCreate(s):168, HostRead(s):272, HostWrite(s):272, MakePath(s):76, GetDeviceName(s):12, SetDeviceName(s):36
- statics: gPrefixDef, gHostStatus, gPrefix

**filecdrom.c**
- functions: CdromSleep(s):28, CdromSync(s):68, _FileDeviceCdromInit:140, _FileDeviceCdromTerm:8, CdromCdStatus(s):48, CdromTrayReq(s):28, _FileDeviceCdromCheck:468, CdromMakeSifPath(s):72, CdromSetStatus(s):208, CdromGetStatus(s):104, CdromGetSize(s):128, CdromCreate(s):8, CdromRead(s):212, CdromWrite(s):8, MakePath(s):224, AdjustRead(s):556, AdjustReadSub(s):536, FatCacheInit(s):96, FatCacheReset(s):88, FatCacheFind(s):288, FindInPathTable(s):548, FindInDirRecord(s):448, GetPathToken(s):84, IsOnlyFileName(s):60, CopyFromCache(s):504, GetDeviceName(s):12, SetDeviceName(s):8, rxFileSetCdromSearchFileFunc:16
- statics: gPrefix, gPathPrefix, gPathVersion, gCdromStatus, gCdromPosition, gCdromPositionOffset, gCdromRequest, gSearchFileFunc, checkInterval.117, gFatCacheInfo, gSectorBuffer, gaFatCacheBuffer

**filehdd.c**
- functions: _FileDeviceHddInit:120, _FileDeviceHddTerm:8, HddDetectIOError(s):172, HddMakeSifPath(s):8, HddSetStatus(s):8, HddGetStatus(s):32, HddGetSize(s):200, HddCreate(s):192, HddRead(s):312, HddWrite(s):312, MakePath(s):76, GetDeviceName(s):12, SetDeviceName(s):36
- statics: gPrefixDef, gHddStatus, gPrefix

**fileloc.c**
- functions: _FileLocalInit:180, _FileLocalTerm:8, _FileThChange:96, _FileSetDevice:240, _FileGetDevice:32, _FileSetThreadDevice:252, _FileSetRootDir:192, _FileGetRootDir:32, _FileSetDir:284, _FileGetDir:28, _FilePushDir:128, _FilePopDir:100, _FileSetLastName:44, _FileGetLastName:32, _FileSetDivideSize:48, _FileGetDivideSize:32, _FileGetLoadFunc:32, _FileSetLoadFunc:48, _FileGetGetSizeFunc:32, _FileSetGetSizeFunc:48, GetDeviceInfo(s):56, GetDeviceThreadInfo(s):52, GetCurrentThreadInfo(s):32, cutToken(s):104, cutTailDir(s):120, isUpperDir(s):76
- statics: gFileLocalMgr

**filereq.c**
- functions: _FileRequestInit:20, _FileRequestTerm:136, _FileRequestInsert:96, _FileRequestRemove:264, CreateRequestThreadProc(s):256, RequestThreadProc(s):824, HostCdromHddSyncProc(s):8, MemCardSyncProc(s):8, HddSyncProc(s):8, QueueInit(s):12, QueueInsertHead(s):360, QueueGetTail(s):64, QueueRemoveTail(s):80, QueueGetCount(s):32, QueueGetLeft(s):44, QueueRemoveHasData(s):368, rxFileSetOverrideDevice:164, rxFileAppOverrideDevice:24, rxFileRefOverrideDevice:24, rxFileSetHddIOErrorCallback:12, rxFileGetHddIOErrorCallback:12
- statics: gaOverrideDevice, gaAppOverrideDevice, gpHddIOErrorFunc, gaDevicePairMgr, gaRequestMgr

**rxthsys.c**
- functions: CreateSemaDirect(s):36, CreateThreadDirect(s):84, DeleteThreadDirect(s):40, rxThBgMain(s):132, rxThDummyMain(s):24, rxThIsDI:44, rxThDI:12, rxThEI:12, rxThGetBgFuncCount:28, rxThAddBgFunc:144, rxThSysInit:396, rxThSysTerm:372, ExecCallback(s):96, SearchCallback(s):56, rxThAddCallback:128, rxThRemoveCallback:56, rxThGetGlobalIndex:12, rxThLockZone:128, rxThUnlockZone:56, rxThSleep:256, MainSyncHCallback(s):568, rxThGetCurrentIndex:80, rxThDeleteThread:184, rxThGetThreadCount:12, rxThSetInterval:32, rxThGetInterval:36, rxThGetParam:36, rxThSetParam:32, rxThGetEnable:36, rxThSetEnable:32, rxThCreateThread:388, rxThSetWakeupFunc:268, rxThInit:8, rxThTerm:8, rxThVSyncFunc(s):52, rxThVSync:84, rxThSignalSema(s):8, rxThPollSema(s):8
- statics: gIsInit, mainThPriority, mainBgThreadTop, mainBgThreadBot, wakeupFunc, mainBgThreadTable, hsyncSema, gGlobalIndex, threadTable, cbTable, threadCount, threadIndex, mainThID, mainSema, bgLockSema, dmyStack, mainDmyID, bgStack, mainBgID, hsHandle, sleepVSyncCount, wakeupArgs

**rxthmac.h**
- functions: FORCE_EI(s):76
- statics: -

**rxthsync.c**
- functions: rxSysThInit:8, rxSysThTerm:8, rxThDrawSyncFunc(s):36, rxThDrawSync:76, rxThDmaSyncFunc(s):48, rxThDmaSync:108
- statics: -

**rxgsvs.c**
- functions: SyncVCallback(s):124, rxGsVSyncInit:128, rxGsVSyncTerm:84, GpuUpdateHCount(s):48, GpuGsSyncV(s):60, rxGsGetOddEven:12, rxGsVSync:152
- statics: gpuIntcHandle, gpuOddEven, gIsInit, gpuHCount, gpuVCount

**rxhdd.c**
- functions: CryptChar(s):68, CalcSum(s):52, CryptString(s):184, rxHddChangeThread(s):48, rxHddThreadInfoInit(s):16, rxHddMountRegist(s):276, rxHddMountUnRegist(s):176, rxHddMountInit(s):236, rxHddMountTerm(s):204, rxHddCRCInit(s):120, rxHddCalcCRC(s):84, rxHddCalcPassword(s):92, rxHddPowerOff(s):148, rxHddPathName:244, rxHddFileName:344, rxSysOpenEx:28, rxSysMkdir:28, rxSysRmdir:28, rxSysRemove:28, rxSysFormat:28, rxSysMount:28, rxSysUmount:28, rxSysChdir:28, rxSysRename:28, rxSysDevctl:28, rxSysIoctl2:28, rxSysLseek64:28, rxSysDopen:28, rxSysDclose:28, rxSysDread:28, rxSysGetstat:28, rxSysChstat:28, rxSysSync:28, rxSysSymlink:28, rxSysReadlink:28, rxHddCalcFullPwd:48, rxHddCalcReadPwd:48, rxHddCalcPwd:204, rxHddFormat:36, rxHddFormatPartition:44, rxHddCreatePartition:44, rxHddRemovePartition:36, rxHddFlash:36, rxHddPopen:36, rxHddPread:36, rxHddPclose:36, rxHddMount:44, rxHddUmount:36, rxHddMkdir:36, rxHddChdir:36, rxHddRmdir:36, rxHddDopen:36, rxHddDclose:36, rxHddDread:36, rxHddOpen:44, rxHddClose:36, rxHddRead:44, rxHddSeek:44, rxHddWrite:44, rxHddRemove:36, rxHddRename:44, rxHddSymlink:44, rxHddGetInfo:36, rxHddIsExistPartition:36, rxHddIsExistFile:36, rxHddSave:52, rxHddCopy:52, rxHddSaveResource:44, rxHddExecuteTable:36, rxHddThFormat:168, rxHddThFormatPartition:296, rxHddThCreatePartition:780, rxHddThRemovePartition:280, rxHddThMount:424, rxHddThUmount:148, rxHddThMkdir:168, rxHddThChdir:164, rxHddThRmdir:164, rxHddThFlash:76, rxHddThPopen:56, rxHddThPread:28, rxHddThPclose:28, rxHddThDopen:60, rxHddThDclose:28, rxHddThDread:28, rxHddThOpen:80, rxHddThClose:28, rxHddThRead:28, rxHddThSeek:28, rxHddThWrite:28, rxHddThRemove:164, rxHddThRename:244, rxHddThSymlink:276, rxHddThGetInfo:352, rxHddThIsExistPartition:304, rxHddThIsExistFile:444, rxHddThSave:136, rxHddThCopy:476, rxHddThSaveResource:804, rxHddThExecuteTable:108, rxHddThExecute:112, rxHddChgDevice:112, rxHddPortInfoClear:16, rxHddSetPort:72, rxHddGetPort:16, rxHddIsMount:60, rxHddMountGetEmpty:80, rxHddMountGetFullName:184, rxHddExecute:172, rxHddIsExistDriver:12, rxHddDebug:16, rxHddSetPwdSeed:132, rxHddSysInit:664, rxHddInit:284, rxHddTerm:68, rxHddSync:176
- statics: rxHdd_bInitFlag, rxHdd_bDebugFlag, rxHdd_pPortName, rxHdd_pPFSName, rxHdd_bExistDriver, rxHdd_nPwdSeed, rxHdd_nMountMax, rxHdd_pMountInfo, rxHddCRC_bInitFlag, rxHdd_aThreadInfoTable, rxHdd_pThreadInfo, rxHddCRC_aTable, rxHddTh_pInfo, rxHdd_aORGDeviceName

**rxhddth.c**
- functions: rxHddThreadMain(s):268, rxHddThAddFunc:324, rxHddThInit:92, rxHddThTerm:128
- statics: rxHddTh_nThreadIdent, rxHddTh_nTerminateFlag, rxHddTh_nRegistIdent, rxHddTh_nCurrentIdent, rxHddTh_aThreadTable, rxHddTh_aStack
