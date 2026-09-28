# Rule of Rose — estado del proyecto

## Objetivo

Decompilación **completa** del juego a C++ legible, compartible y trabajada en
conjunto con un desarrollador profesional (proyecto personal). Sobre esa base,
un port nativo a PS Vita lo más fiel posible, dentro de los límites de la consola.

Política: el repo solo contiene código propio, herramientas y datos derivados
(nombres y direcciones). Nunca el ELF, los assets ni la ISO; cada colaborador
extrae sus archivos de su propio disco.

## Fuente

- ISO original: `~/Downloads/Rule of Rose/Rule of Rose.iso` (3.4 GB, dump propio).
- Versión: **SLUS-21448**, NTSC-U, v1.00 (Atlus, 2006).
- Otras versiones que existen: la japonesa original (Sony, 2006) y la europea
  (505 Games, 2006). No están comparadas; podrían diferir en código o
  conservar más información de depuración. Solo vale la pena revisarlas desde
  un disco propio.

## Ejecutable `SLUS_214.48`

| Dato | Valor |
|---|---|
| Entry point | `0x100008` |
| `.text` | `0x100000`–`0x280e88` (~1.5 MB); Ghidra detecta 7,230 funciones |
| `.vutext` | `0x291230`, 0x4180 bytes: microcódigo VU + 44 overlays `.DVP.overlay` |
| `.data` / `.rodata` | `0x295f00` / `0x2e5300` |
| `.bss` | `0x308100`, ~5.3 MB |
| Compilador | **ee-gcc 2.96 (SCE), `-Os -G0 -fno-exceptions`**; `-G0` porque ninguna instrucción del programa usa `$gp` como base; confirmado byte a byte en 3 funciones (`matching/compiler_id/`). `-fno-exceptions` porque `.eh_frame` solo cubre libgcc: sin esa opción cada objeto C++ emitiría 0x70+ bytes de `.eh_frame` que el original no tiene |
| SDK | Sony libs 3.0 (`libgraph`, `libdma`, `libvu0`, `libipu`, `libmpeg`, `libpad2`, `libmc`, `libcdvd`, `libvib`, `libscf`) |

Sin `.symtab` ni información de depuración (no hay DWARF ni STABS), pero sí:

- 1,449 funciones con nombre original (`.gnu.linkonce.t.*`, métodos inline).
- 284 vtables (`.gnu.linkonce.d._vt$*`), formato GCC2 sin thunks: entradas de 8 bytes `{short delta; short index; void *pfn}`, la 0 apunta a `__tf`.
- 289 clases; jerarquía reconstruida desde las funciones `__tf` → `notes/class_hierarchy.txt`.
- 111 nombres más inferidos por overrides de vtable (con su nombre mangled derivado), y 651 métodos virtuales ligados solo a su clase. Una función compartida por 5 clases abstractas en 6 posiciones distintas es `__pure_virtual` (`0x272a30`); se excluye de la propagación (antes contaminaba 320 nombres).
- 142 cadenas de ruta de fuente (asserts), 133 referenciadas desde código → 529 funciones ligadas a su archivo; orden de archivos en `notes/object_layout.txt`.

## Módulos del motor

Orden en `.text` (según `notes/object_layout.txt`): `bed/` → `utl/` → `dog/` → `mag/` → … → `debug/`, con los métodos inline de los headers al final (`0x281000+`).

- `bed/`: base (memoria, pad, modos).
- `utl/`: utilidades (archivos, TIM2, búsqueda).
- `dog/`: render y animación (`DogModel`, `DogActor`, `DogCamera`, `DogLight*`, `DogMotionBlend`).
- `mag/`: lógica de juego, escenas y menús (`MagLife*`, `MagScene*`); el módulo más grande.
- `emy/`: enemigos (`EmyMain`, `EmyManager`, `*Out*` por tipo).
- `game/`: `GamMan` (gestor principal), sonido, estado, triggers.
- `task/`: todas las tareas heredan de `CmnITask`.
- `mnu/`, `snd/`, `spr/`, `mcd/`, `msg/`, `sequence/`, `system/`, `debug/`.

Sin middleware de terceros. Audio por driver IOP propio `RXSNDDRV.IRX`.

## Assets

| Ruta | Contenido |
|---|---|
| `MOVIE/*.PSS` | 41 videos MPEG-2 (convertibles a H.264 para la Vita) |
| `DATA/BG/MAPUNIT.BIN` | 600 MB, escenarios; formato desconocido |
| `DATA/CH/CHARA.RPK` | 523 MB, personajes; contenedor RPK desconocido |
| `DATA/EVT/*.RPK`, `DATA/MNURPK/*.RPK` | eventos, menús |
| `DATA/SEQ/W###/A###/` | 1,134 `.ARA` + 844 `.STR` (secuencias/scripts por área) |
| `DATA/SND/` | `XV`, `XWS` (audio) |
| `DATA/WRD/` | 15 `.WRD` (texto) |

## Hoja de ruta

1. ✅ Recuperación de símbolos y proyecto Ghidra reproducible, con tipos de parámetros (1,267 firmas).
2. ✅ Compilador identificado: **ee-gcc 2.96 (SCE) con `-Os`**. 3 funciones coinciden byte a byte (87/87 instrucciones); falta confirmar en más módulos y averiguar `-G`. Entorno reproducible en `docker/` (imagen `ror-build`).
3. ✅ splat + build: `tools/dock python3 tools/configure.py && tools/dock ninja` reconstruye la imagen de carga idéntica byte a byte (SHA-1 `fa157dc8763b2f376f6bb73a70b6a4c250181997`), todo en asm por ahora. Claves: `subalign: 4` (las secciones linkonce originales van alineadas a 4) y `ld_align_section_vram_end: False`.
3b. ✅ División en 144 archivos (`config/splits.tsv`, `tools/split_files.py`), compilación sigue idéntica. Evidencias: (1) rutas de assert → 72 archivos conocidos (se corrigió la extracción de rutas: una ruta precedida por el último byte de un float, `0x3F`, se perdía, p. ej. `dog/dogmodel.cpp`); (2) orden de `.rodata`, midiendo contra la cadena más larga de referencias en orden (las pocas cruzadas son `extern const`); (3) **textos duplicados**: GCC comparte literales idénticos solo dentro de un archivo, así que dos copias = dos archivos → 339 restricciones de corte, ninguna contradice el orden de enlace; (4) `.ctors`/`.dtors` → 4 finales exactos; (5) no partir variables locales (candidatas a `static`); (6) cambio de familia de clase (`Hfm*`→`Bds*`) solo si lo anterior lo permite. Resultado: 50 archivos escondidos `unk/<clase principal>` (p. ej. un archivo por tipo de enemigo), 2 cortes con conflicto menor (`dog/dogcamera`, `game/gamstat`). Validación: la ruta `.cpp` de cada archivo conocido cae en su propio bloque de `.rodata`.
4. Decompilar archivo por archivo, empezando por `bed/` y `utl/` (pequeños, sin dependencias).
5. Documentar los formatos RPK / MAPUNIT / ARA / STR.
6. Capa de port: reemplazar las libs `sce*` por equivalentes Vita; reescribir el render (VU1 + GS) sobre vitaGL.

## Pendientes de la división y pistas nuevas (2026-09-28)

- **`.ctors`/`.dtors`** marcan 4 archivos con constructores globales; GCC los emite al final del archivo, así que dan finales exactos: `0x17F0D0` (dentro de `snd/sndman`), `0x2043DC` (dentro de `system/sysnowloading`), `0x2155F4` y `0x215A30` (dentro de `debug/mimu_debug`; el handler de assert `0x215A30` abre su propio archivo). Hay archivos escondidos en esos rangos.
- **Zona `0x218500`–`0x236AC8` (~120 KB)**: no es SDK (ninguna firma), y el juego la llama cientos de veces (`snd/` 311, `mag/` 304, `dog/` 104, `spr/` 104). Es middleware del motor (probablemente la librería gráfica "I3": `tag_I3dMatrixF4x4_s`, `I3M_INTER`, `i3mGetNodeIndexByName`; y el lado EE del driver de sonido). Para el port hay que decompilarla.
- ✅ **`.data` y `.bss` divididos por archivo** (antes bloqueaban el C++). Dueño de cada variable = el único archivo cuyo código la usa, o (en `.data`) cuyas funciones/`.rodata` apunta una tabla; luego la secuencia más larga que respeta el orden de enlace. `.data`: 450 variables con dueño único, 443 (98%) consistentes, 46 archivos con bloque. `.bss`: 318, 291 (92%), 31 archivos; el primero es el buffer `_args` de crt0 (0x144 bytes). `.sbss` (188 bytes, usada por las funciones RTTI y libc) queda en un solo bloque. El tamaño de `.bss` se calcula del ELF (splat omitía 0x48 bytes de alineación): el ELF reconstruido termina en `0x828E94` como el original.
- **Prototipo**: existe un prototipo de localización del 19-jul-2006 catalogado en Hidden Palace, y una demo USA. Se desconoce si conservan símbolos (Sly 1 obtuvo nombres y archivos de un prototipo así).

## Formatos de audio

- `DATA/SND/XWS/*.STR` (844): PS-ADPCM crudo sin cabecera; `vgmstream` lo lee con un `.txth` (falta la frecuencia).
- `DATA/SND/XV/*.SE` (36): bancos con firma `XVAB` y bloques `HEAD`/`TGIF`/`TGPG`/`TGSP`; formato sin documentar (no está en vgmstream). Se entenderá al decompilar `snd/`.

## Librerías del SDK

`tools/sce_symbols.py` identifica 657 funciones por firma (base de datos de PS2Recomp). Orden en `.text`: zona sin identificar `0x218500`–`0x236AC8` (¿otra librería o código propio?), libvu0, libgcc, libcdvd, libmc, libmpeg, libgraph, libdma, libvu0, libdev, libkernl, libipu, libdbc, libpad2, libvib, libscf, libm, libgcc, libc. Ninguna firma coincide dentro del código del juego, lo que confirma el límite `0x218500`.

## Pistas para decompilar

- `FUN_00215a30` es el handler de assert del juego: `printf("Assertion Failed: %s(%d)   %s\n", file, line, expr)` y bucle infinito. Cada llamada revela el archivo, la línea y la expresión originales.
- Los destructores GCC2 reciben `int __in_chrg`; el bit 0 indica si hay que liberar la memoria después.

## Riesgos principales para Vita

1. Microprogramas VU1 (44): hay que reescribirlos como shaders vitaGL/GXM.
2. Efectos de post-proceso del GS (grano, niebla, blur).
3. Formatos propietarios sin documentar.

## Herramientas evaluadas (2026-09-28)

| Proyecto | Veredicto |
|---|---|
| `chaoticgd/ghidra-emotionengine-reloaded` | **En uso.** v2.1.37 compilada contra Ghidra 12.1.4 |
| `bigianb/ghidra-ps2ee` | Abandonado (2019); su propio README remite a la línea beardypig → chaoticgd |
| `zipzip11/ps2-dwarf1` | No aplica: el ELF no tiene secciones DWARF |
| `Raikaru/mwccps2-debugger` | No aplica: el juego se compiló con GCC, no con Metrowerks CodeWarrior |
| `Cwf1997/ruleofrose` | "Decomp" vacío (solo README); sin código |
| `blueroses107-ai/Rule-of-rose-korean-translation` | Solo README |
| Cheats widescreen de OPL para SLUS_214.48 | Pueden dar direcciones de cámara/FOV |
| `TheOnlyZac/sly1` + `theclub654/ProjectCane` | Referencia principal: decomp C++ de PS2 con splat (ee-gcc 2.95.2 de SN) y su port jugable a PC. Obtuvo nombres/archivos de un prototipo con símbolos |
| `ethteck/kh1`, `Fantaskink/SOTC`, `RossyDoubleUnderscore/ICO-decomp`, `weirdbeardgame/Fatal-Frame-1`, `parappadev/parappa2` | Usan ee-gcc 2.96 + splat: referencias para `.data`/`.bss`, objdiff, progreso |
| `LostTemplarRH/sce-symbol-scanner` | Origen de la base de firmas; su CLI (Java, pre-release, sin licencia) usa además vecindad para funciones cortas. No ejecutado |
| `cualquiercosa327/psretrox` | Existe (herramienta de decompilación/recompilación PS2); no evaluada a fondo |
| `matt-kempster/m2c` | Sí, para decompilar: MIPS→C con GCC y C++ parcial (GPL, se instala como herramienta) |
| `vgmstream/vgmstream` | Sí, para el audio `.STR` (con `.txth`); no conoce los bancos `XVAB` |
| `ps2dev/ps2sdk` | Referencia de registros de hardware (GS/DMA/VIF); su API no es la de Sony (`sce*`) |
| `xerpi/libvita2d` | Posible para la UI en Vita; sin cambios desde 2022, vitaGL cubre lo mismo |
| Scripts de Noesis | No hay scripts públicos para Rule of Rose (búsqueda sin resultados) |
| `ran-j/PS2Recomp` | **En uso su base de firmas del SDK** (vía `tools/sce_symbols.py`). Su recompilador estático queda como opción para arrancar el port antes de terminar la decompilación |
| `jhuapl/codecut` | No: guarda el archivo de cada función en el *Namespace* de Ghidra, que usamos para las clases C++; nuestras pistas (asserts + orden de `.rodata`) son más exactas que su heurística |
| `astrelsky/ghidra_MIPSR5900` | Archivado (2020); reemplazado por ghidra-emotionengine-reloaded |
| `Rinnegatamante/vitaGL` | Sí, en la etapa Vita: capa OpenGL sobre sceGxm, muy activa |
| `TheOfficialFloW/gtasa_vita`, `bully_vita` | Referencia para la etapa Vita (audio, memoria, vitaGL); son ports de binarios Android, no de PS2 |
| `vitasdk/vitasdk` (imagen Docker oficial) | Sí, en la etapa Vita, fijando una serie mensual |
