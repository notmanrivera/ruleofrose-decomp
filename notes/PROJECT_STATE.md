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
| Compilador | **ee-gcc 2.96 (SCE), `-Os -G0 -fno-exceptions -fno-strict-aliasing`**; `-fno-strict-aliasing` porque el juego relee valores tras escrituras de otro tipo (descubierto en `bed/bedsubmode`); `-G0` porque ninguna instrucción del programa usa `$gp` como base; confirmado byte a byte en 3 funciones (`matching/compiler_id/`). `-fno-exceptions` porque `.eh_frame` solo cubre libgcc: sin esa opción cada objeto C++ emitiría 0x70+ bytes de `.eh_frame` que el original no tiene |
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
4. 🔄 Decompilación iniciada (flujo en `docs/DECOMPILING.md`). ✅ `bed/bedsubmode` (clase `BedSubMode`: pila de 4 estados de 16 bytes, `push`/`pop`/`clear`) y ✅ `utl/utlmisc` (`utlIsTcc`: ¿contiene el nombre "_tcc"?), ambos byte a byte y enlazados en la compilación completa. Hallazgos: hace falta `-fno-strict-aliasing`; el ensamblador de ee-gcc 2.96 deja la tabla de símbolos con un `sh_info` que el ld moderno rechaza (se arregla con `strip -N dummy-symbol-name`, como Sly 1); sin `subalign` cada objeto de ensamblador recibe la alineación del original (código 4; cada bloque de datos, la mayor potencia de 2 que divide su dirección, hasta 8). ✅ **Archivos parciales (`INCLUDE_ASM`)**: `tools/dock python3 tools/configure.py --new <archivo>` crea el `.cpp` con un `INCLUDE_ASM` por función (splat deja cada función en `asm/nonmatchings/` junto con su `.rodata`), y ese esqueleto ya compila idéntico; luego se sustituyen una a una. Mientras quede asm, `.text` y `.rodata` salen del objeto C++ y `.data`/`.bss` siguen en asm (el C++ los usa como `extern D_xxxxxxxx`); la cadena `__FILE__` compartida sigue como `INCLUDE_RODATA` vía `ASSERT_FILE`. El asm lo ensambla el propio ensamblador de ee-gcc 2.96 (GNU as 2.10-ee), y acepta nombres con `$` (destructores). ✅ `bed/bedpad` (clase `BedPad`, un puerto de mando, 13 funciones byte a byte: abrir/cerrar el socket de `scePad2`, vibración, y la lectura de cada frame: botones pulsados / recién pulsados / autorrepetición con retardo e intervalo, los 4 ejes de los sticks con zona muerta (0x60–0xA0), una dirección `x`/`y` de -1 a 1 que sale de la cruceta o del stick izquierdo, una cruceta "virtual" con autorrepetición y un contador de cambios rápidos de dirección; es la referencia para el control en el port. Su `.bss` sigue en asm porque sus últimos 4 bytes, `0x308480`, no los usa ningún código y no hay pruebas de a qué archivo pertenecen). ✅ `bed/bedpfh` (clase `BedPfh`, lector de los paquetes `.RPK`: `clear`, `setTop`, `getName`, `getIndex`, byte a byte) con su cabecera `bed/bedpfh.h`, cuyas funciones inline tienen que estar en líneas concretas (70-73 y 91) porque sus asserts llevan el `__LINE__` del `.h`; ese `.h` lo incluyen unos 18 archivos. `0x105BA4` es `operator delete` (`__builtin_delete`, lo llaman los destructores). Siguiente: archivos más grandes de `bed/`/`utl/`.
   - **Límites movidos con pruebas** (`config/splits_manual.tsv`, cada uno con su justificación): `0x101718` pone a cero un objeto de 0x1C bytes con los mismos campos que usa `bed/bedmemory` y solo se llama desde una inicialización estática sobre el montón global: es el constructor del montón, final de `bed/bedmemory`. `0x100320` pone a cero `m_stack` y `m_depth` con la disposición exacta de `BedSubMode` y lo llama el constructor de `mag/magscene2` justo tras construir ese miembro: es `BedSubMode::clear`, así que `bed/bedmemory` empieza en `0x100354`. `0x101CCC`–`0x102488` leen el mando con el socket de `BedPad` y sus campos: son de `bed/bedpad`, así que `utl/utlgame` empieza en `0x102490`. Lección: los límites `likely` pueden estar desplazados varias funciones; hay que revisar los extremos de cada archivo antes de darlo por terminado.
   - `tools/split_files.py` ya no depende del avance: lee también el desensamblado completo de los archivos decompilados (`make_full_disasm_for_code`) y usa como candidatos de corte las direcciones referenciadas, porque el `.rodata` compilado no deja símbolos en el mapa. Sin filas manuales nuevas, `config/splits.tsv` sale idéntico. Las filas de `config/splits_manual.tsv` valen ya en todo el código del juego, y una fila con el nombre de un archivo existente mueve su inicio.
   - 🔄 **`bed/bedmemory`** (clase `BedMemory`, los montones de memoria del juego: un búfer rellenado con "$RUNTIME" y partido en bloques, cada uno tras una cabecera `BEDMEMHEADER` (nombre original, sacado de un assert) que guarda archivo y línea de quien lo pidió; búsqueda del primer hueco desde abajo o desde arriba, alineación 32/64/128, `alloc`, `realloc`, `free`, `shrink`, `check`, `getInfo`): **14 de 17 funciones byte a byte** y el `.rodata` entero, incluidos textos que ningún código usa (un `ASSERT` con `=` en vez de `==` y código de depuración muerto con ○/■). `init`, `shrink` y `cutHead` siguen en asm con su C++ bajo `NON_MATCHING`: solo difieren en reparto de registros y planificación. El juego tiene tres fallos que se reproducen tal cual (`cutHead` resta los dos punteros, `shrink` y `realloc` no actualizan un enlace de la lista).
   - ✅ **`utl/utlfile`**: solo 2 funciones, byte a byte: copiar un texto a un búfer de tamaño fijo (recortándolo si no cabe) y unir dos textos igual (`"movie/"` + nombre, nombre + `"_c.bin"`). Su inicio real es `0x105E50`: sus asserts están en las líneas 15-16 del `.cpp`, así que es la primera función del archivo.
   - ✅ **`unk/001056E8`**: las 25 funciones que `split_files.py` había metido al principio de `utl/utlfile`. Ningún assert ni texto dice a qué archivo pertenecen (pueden ser el final de `utl/utlmisc` o varios archivos), así que llevan nombre provisional. Todo byte a byte, incluido su `.data`: conversión a punto fijo con la VU0 (`vftoi15`); un lector de textos de parámetros, una línea "nombre valor" cada vez (enteros, hexadecimal con `$`, decimales y "cadenas"; lo usa el menú de opciones); un contador de frames; los `operator new`/`delete` globales (todo `new` del juego sale del montón global, un `BedMemory`); y las funciones de ese montón: al arrancar lo hace tan grande como deja `malloc`, reservando sitio para la pila, y la librería de sonido recibe sus `alloc`/`realloc`/`free`.
   - ✅ **`utl/utlfind`** (10 funciones, byte a byte): ayudas del modo "buscar" del perro Brown (`MagLifeBwnCtrl`): hasta 4 objetos que buscar y cuál de ellos huele mejor desde su posición (alcance de olor entre distancia, la altura cuenta 10 veces; prefiere los de su misma zona). Sus 2 primeras funciones eran utilidades de texto y pasaron al final de `utl/utlfile` (que queda con 4). Aparecen nombres originales del juego: la clase `ObjStat` (objetos) y `GamMan` (gestor del juego, con sus listas de personajes), por sus métodos inline.
   - ✅ **`unk/00106658`** (25 funciones, byte a byte, con su tabla de datos): lo que `split_files.py` había puesto al principio de `dog/dogmotionblend`, que en realidad empieza en `0x10737C`. Son utilidades sin nombre de archivo: matemáticas de vectores sobre la VU0 (rotar, distancias, producto escalar y vectorial, interpolar, ángulos de giro e inclinación), tres ayudas para los nodos de modelos i3d y una tabla que traduce IDs de sonido entre tres rangos (`0x0A00xxxx`, `0x0A01xxxx`, `0x0A02xxxx`) según lo que devuelve `GamMan`.
   - ✅ **`dog/dogmotionblend`** (11 funciones, byte a byte): la clase `DogMotionBlend` (nombre original), que reproduce las animaciones de cada `DogActor`: una principal y hasta 4 superpuestas sobre algunos huesos (máscara de 128 bits), con velocidad, avance por tick (en bucle o parando en los extremos), fundidos de entrada y el cálculo de la pose final mezclando las poses de i3m. Sus asserts van de la línea 83 a la 587; los huecos se rellenan con líneas en blanco. Nueva herramienta: `tools/pad_asserts.py`, que coloca cada assert en su línea original.
   - 🔄 **`dog/dogactor`** (clase `DogActor`, nombre original: la base animada de los personajes, con su modelo, sus animaciones (paquetes `.RPK` en memoria o leídos del disco), la mezcla de poses, los nodos del esqueleto, una lista de comandos de movimiento y los giros): **99 de 100 funciones byte a byte** y su `.rodata` entero. `func_0010DF54` (la pose de cada frame) sigue en asm con su C++ bajo `NON_MATCHING`: solo cambia el orden de un incremento en su primer bucle. ✅ **`unk/0010F3A4`** (7 funciones, byte a byte): los métodos del ojo de `DogActor` (busca el material "eye" y lo hace parpadear); su `.rodata` va detrás del de `dog/dogactor`, así que son otro archivo, de nombre desconocido. Para esto: `config/splits_manual.tsv` puede fijar también dónde empieza el `.rodata` de un archivo; el build define las etiquetas que el asm usa dentro del `.rodata` compilado (`build/cpp_syms.ld`); y los 289 objetos de tipo `__ti<Clase>` tienen nombre (`symbols/symbol_addrs.txt`), porque cada archivo con clases virtuales los declara. Hallazgo: g++ 2.96 sabe que una función ya compilada en el mismo archivo no lanza excepciones, y eso cambia el código de quien la llama; mientras siga en asm se declara con `ASM_NOTHROW`.
   - ✅ **`dog/dogcamera`** (2 funciones, byte a byte): `DogCamera` (nombre original, hereda de `DogEntityEx`) guarda y recupera su posición, rotación, escala y un valor más (`save`/`restore`, nombres nuestros; `m_saved` sale de los asserts). Para que coincida, el contador `m_saved` se cambia al final de cada función.
   - `include/sdk/ctype.h`: las macros de newlib (`isdigit`, `isxdigit`) sobre su tabla `_ctype_`; `_end` y `_stack_size` (símbolos del enlazador) ya tienen nombre.
   - `match.py` ya comprueba las relocaciones: rellena cada dirección como lo haría el enlazador (los nombres importados salen del mapa de la última compilación, `build/SLUS_214.48.map`) y la compara con la del juego. Antes las enmascaraba y daba por buenos dos símbolos intercambiados (pasó en `heapInit`: solo lo detectaba la compilación completa); ahora eso, o una llamada a la función equivocada, sale como `N relocs differ`, con una línea por referencia (`reloc at +0x0: _end (0x00828E94), game 0x00081000`). Si el `.rodata`/`.data`/`.bss` del objeto tiene otro tamaño que el del juego, las referencias a él no se comprueban (todo lo que va detrás de la pieza equivocada se desplaza) y su línea lo indica. Comprobado contra el enlazador real: las 417 relocaciones de los 7 archivos decompilados salen idénticas. Tampoco da por buena una sección `.data`/`.rodata` vacía cuando el original tiene bytes.
   - Herramientas: `tools/match.py` compara cada función en su dirección real (una función de tamaño distinto ya no descuadra las demás); `tools/try_variants.py` prueba variantes de código en serie (órdenes de sentencias, formas de expresión) y dice cuáles coinciden.
   - `tools/asserts.py` lista los 1,475 asserts del juego (archivo, línea, expresión, función); con `--lines` resume las líneas de un `.h`.
5. 🔄 Documentar los formatos. ✅ **RPK** (`docs/formats/rpk.md`): cabecera de 0x20 bytes con firma `RTPK`, tamaño total, banderas, alineación (0x800) y número de archivos; tablas opcionales de tamaños, posiciones, datos de usuario y nombres. Sacado del código de `bed/bedpfh` y comprobado contra los 49 `.RPK` del disco sin ninguna discrepancia. Falta el significado de la bandera `0x4000`. Pendientes: MAPUNIT / ARA / STR.
6. Capa de port: reemplazar las libs `sce*` por equivalentes Vita; reescribir el render (VU1 + GS) sobre vitaGL.

## Pendientes de la división y pistas nuevas (2026-09-28)

- **`.ctors`/`.dtors`** marcan 4 archivos con constructores globales; GCC los emite al final del archivo, así que dan finales exactos: `0x17F0D0` (dentro de `snd/sndman`), `0x2043DC` (dentro de `system/sysnowloading`), `0x2155F4` y `0x215A30` (dentro de `debug/mimu_debug`; el handler de assert `0x215A30` abre su propio archivo). Hay archivos escondidos en esos rangos.
- ✅ **Middleware identificado** (`0x218500`–`0x24B490`, ~200 KB, dos librerías en C que no son del SDK): `mw/i3d` (`0x218500`–`0x237D00`, gráficos: IDs de formato `I3D_BIN`/`I3D_I3M`/`I3D_I3C`, la llaman `dog/`, `mag/`, efectos y menús) y `mw/sound` (`0x237D00`–`0x24B490`, la llaman `snd/` y `game/`). Todas sus funciones están alineadas a 8 (otras opciones de compilación), así que el relleno NO marca archivos. Dividirlas en sus `.c` queda **pendiente por falta de evidencia**: no tienen asserts ni rutas; la afinidad por llamadas (método de CodeCut) propone ~50 cortes por librería, pero en `mw/sound` solo 4 de 46 respetan sus 125 variables locales, así que no es fiable. Para el port, la API de `mw/i3d` es la frontera natural: se puede reimplementar sobre OpenGL/vitaGL sin decompilarla byte a byte.
- ✅ **Falsos positivos del SDK corregidos**: funciones globales que coincidían en varias direcciones (`sceVu0ClampVector` ×4, `sceVu0TransposeMatrix` ×3, `__get_eh_context` ×5) eran imitaciones cortas dentro del middleware; se conserva solo la copia rodeada de su librería (648 nombres). Los tramos falsos `sdk/libvu0`/`sdk/libgcc` en `0x236AC8`/`0x238740` desaparecieron.
- ✅ **`.data` y `.bss` divididos por archivo** (antes bloqueaban el C++). Dueño de cada variable = el único archivo cuyo código la usa, o (en `.data`) cuyas funciones/`.rodata` apunta una tabla; luego la secuencia más larga que respeta el orden de enlace. `.data`: 450 variables con dueño único, 443 (98%) consistentes, 46 archivos con bloque. `.bss`: 318, 291 (92%), 31 archivos; el primero es el buffer `_args` de crt0 (0x144 bytes). `.sbss` (188 bytes, usada por las funciones RTTI y libc) queda en un solo bloque. El tamaño de `.bss` se calcula del ELF (splat omitía 0x48 bytes de alineación): el ELF reconstruido termina en `0x828E94` como el original.
- **Prototipo**: existe un prototipo de localización del 19-jul-2006 catalogado en Hidden Palace, y una demo USA. Se desconoce si conservan símbolos (Sly 1 obtuvo nombres y archivos de un prototipo así).

## Formatos de audio

- `DATA/SND/XWS/*.STR` (844): PS-ADPCM crudo sin cabecera; `vgmstream` lo lee con un `.txth` (falta la frecuencia).
- `DATA/SND/XV/*.SE` (36): bancos con firma `XVAB` y bloques `HEAD`/`TGIF`/`TGPG`/`TGSP`; formato sin documentar (no está en vgmstream). Se entenderá al decompilar `snd/`.

## Librerías del SDK

`tools/sce_symbols.py` identifica 648 funciones por firma (base de datos de PS2Recomp). Orden en `.text` tras el juego: middleware `mw/i3d` y `mw/sound` (`0x218500`–`0x24B490`), luego libcdvd, libmc, libmpeg, libgraph, libdma, libvu0, libdev, libkernl, libipu, libdbc, libpad2, libvib, libscf, libm, libgcc, libc (y dos colas de libkernl/libgcc). Ninguna firma coincide dentro del código del juego, lo que confirma el límite `0x218500`. Cada librería tiene su propio bloque de `.rodata`.

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
