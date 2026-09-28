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
| Compilador | **ee-gcc 2.96 (SCE), `-Os`**; confirmado byte a byte en 3 funciones (`matching/compiler_id/`) |
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
3b. Dividir `.text` (hoy un solo `asm/main/text.s` de 24 MB) y `.rodata` en un archivo por `.cpp` original, usando `notes/object_layout.txt` y las sugerencias de splat. Es requisito para compilar C++: las cadenas de cada función (paths de assert, etc.) viven en el `.rodata` de su objeto, y mientras `.rodata` sea un solo bloque en asm, un `.cpp` que las emita duplicaría bytes.
4. Decompilar archivo por archivo, empezando por `bed/` y `utl/` (pequeños, sin dependencias).
5. Documentar los formatos RPK / MAPUNIT / ARA / STR.
6. Capa de port: reemplazar las libs `sce*` por equivalentes Vita; reescribir el render (VU1 + GS) sobre vitaGL.

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
