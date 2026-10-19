# Estado local en Windows (2026-10-18)

Documento de traspaso de la sesión de trabajo local (Windows 11, este PC).
El estado general del proyecto sigue en `PROJECT_STATE.md`.

## Hecho en local hoy

- ISO extraída: `disc/SLUS_214.48` (+ `disc/SYSTEM.CNF`). La ISO está en la
  carpeta superior (`Rule of Rose.iso`) y el ELF extraído tiene el SHA-1
  `f9abd6dc…03fb`, el que espera el proyecto.
- Entorno Python del host (`tools/.venv`, en Windows): splat64 0.50.0,
  pyelftools, ninja_syntax y m2c. `tools/.venv/Scripts/python.exe` (en este
  PC el venv es de Windows; en Linux/macOS es `tools/.venv/bin/python`).
- `tools/configure.py` corre también **sin Docker**: genera `asm/`, la
  configuración y `build/SLUS_214.48.rom` con el SHA-1 correcto
  (`fa157dc8…1997`), idénticos a los de la compilación original del repo.
  Para eso se añadió un sustituto en Python de `mips-linux-gnu-objcopy`
  (probado contra el SHA-1 esperado) y `tools/dock`/`tools/match.py`
  toleran rutas de Git Bash en Windows.
- Git local inicializado con `origin` = GitHub (notmanrivera/ruleofrose-decomp),
  `main` = estado descargado. **No se ha subido nada.** Commits locales:
  el fallback de `configure.py` y un `.gitattributes` (LF en todo el repo).
- Docker Desktop instalado (CLI 29.8.2); el motor pedía reiniciar.

## Al arrancar Windows se ejecuta solo

Menú Inicio → `ror_auto_setup.cmd` → `tools/auto_setup.sh`:

1. Espera al motor de Docker (lanza Docker Desktop si no está en marcha).
   Si Docker Desktop pide aceptar sus términos la primera vez, hay que
   aceptarlos a mano una vez.
2. Construye la imagen `ror-build` (descarga los compiladores EE-GCC; tarda
   unos minutos la primera vez).
3. Ejecuta `tools/dock python3 tools/configure.py` y `tools/dock ninja`
   (compilación completa con verificación SHA-1; unos minutos).
4. Deja `build/auto_setup.log` (línea de tiempo), `build/auto_setup.boot.log`
   (salida cruda) y, si todo sale bien, `build/auto_setup.ok`.

## Al retomar

Pedirle al agente: «mira `build/auto_setup.log` y sigue». Con
`build/auto_setup.ok` presente, el entorno está listo y se puede seguir
decompilando sin más preparativos.

## En curso / siguiente

- **`mag/maglifeman`** (siguiente archivo en orden; 0x680 bytes, 7 funciones;
  rango 0x1194B4–0x119B34, `.rodata` en 0x2E9510): análisis empezado.
  - Clase `MagLifeMan`: `m_life_buf[MAX_LIFE]` (64 entradas de 0x10 bytes:
    `{plife, flags, next, prev}`), cabecera de lista en 0x400 y `MAX_LIFE`
    = 64. Los objetos enlazados ("life"; p. ej. `MagLife`) se llaman a través
    de una tabla de métodos guardada en el campo +0x14 del objeto
    (formato `{short delta; fn}`).
  - Asserts originales y sus líneas: 103/104 (`thePod1`, `thePod2`),
    140/141 (`thePod1`, `thePod2`), 210 y 296 y 314
    (`ppod >= &m_life_buf[0] && ppod < &m_life_buf[MAX_LIFE]`),
    235/299/319 (`plife`), 268 (`theNo >= 0 && theNo < MAX_LIFE`).
  - Las cadenas de sus asserts se van a `tools/pad_asserts.py`; los nombres
    de la función `ror_assert` en el asm están en `D_002E9xxx`.
- Pendientes anteriores (C++ bajo `NON_MATCHING`): `bed/bedmemory` (init,
  shrink, cutHead), `dog/dogactor` (func_0010DF54), `dog/dogmodel` (vfunc11),
  `dog/dogtexinfo` (findFree, releasePack, loadTM2, loadPack),
  `mag/magsystem` (setPlayer, endFrame).

## Notas para el agente

- El delta vaddr↔fichero de este ELF es **0xFF000** para todas las secciones
  con contenido (`.text`, `.data`, `.rodata`), no 0x100000.
- `tools/asserts.py` y `tools/split_files.py` necesitan
  `build/SLUS_214.48.map`, que solo existe tras un enlace (build fallido o
  completo).
