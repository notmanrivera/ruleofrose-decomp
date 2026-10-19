# Estado local en Windows (2026-10-18)

Documento de traspaso de la sesión de trabajo local (Windows 11, este PC).
El estado general del proyecto sigue en `PROJECT_STATE.md`.

## Resumen: el entorno ya funciona

- WSL instalado (`wsl.exe --install --no-distribution`; WSL 3.0.3, kernel
  6.18, versión predeterminada 2). Docker Desktop arranca su distro
  `docker-desktop` y el motor responde (`docker info` OK, 16 CPUs).
- Imagen `ror-build` construida.
- `bash tools/auto_setup.sh` termina en **READY**: compilación completa
  (2086 pasos) y SHA-1 del load image = `fa157dc8…1997` (el esperado).
  `build/ok` y `build/auto_setup.ok` presentes.
- Con `build/ok` presente, `auto_setup.sh` no hace nada más (sale en
  segundos), así que el arranque automático es barato.
- `tools/match.py` compila y compara por-fichero (probado con
  `bed/bedpad`, todas las funciones MATCH).

## Hecho en local

- ISO extraída: `disc/SLUS_214.48` (+ `disc/SYSTEM.CNF`); SHA-1
  `f9abd6dc…03fb`, el que espera el proyecto.
- Entorno Python del host (`tools/.venv`, Windows): splat64 0.50.0,
  pyelftools, ninja_syntax y m2c. En este PC es
  `tools/.venv/Scripts/python.exe` (en Linux/macOS, `tools/.venv/bin/python`).
- Git local con `origin` = GitHub (notmanrivera/ruleofrose-decomp),
  rama `master`. **No se ha subido nada.** Commits locales (sobre `c5dacc8`):
  fallback de `configure.py` sin objcopy, `.gitattributes` (LF en todo),
  `tools/dock` en Windows (busca `docker.exe`, rutas `C:/…`,
  `MSYS_NO_PATHCONV`), `tools/auto_setup.sh` de arranque y el espejo de
  compilación de `ee-cc` (EOVERFLOW). Identidad: Rubén Rivera.
- **PATH de máquina reparado**: faltaban `C:\Windows\system32`,
  `C:\Windows`, `System32\Wbem`, `WindowsPowerShell\v1.0` y `OpenSSH`
  (por eso «`wsl` no se reconoce» y cosas parecidas). Se restauraron con
  `wsl_fix.ps1` (en `%TEMP%\opencode`, ejecutado con UAC). Los procesos
  nuevos lo verán tras cerrar sesión/reiniciar; mientras tanto, usar rutas
  completas (`C:\Windows\System32\…`).

## Rarezas de Windows (importante para el agente)

- **configure.py solo dentro del contenedor** (`tools/dock python3
  tools/configure.py`). splat escribe rutas absolutas en `asm/`; si se
  ejecuta en el host salen rutas de Windows y el `ninja` del contenedor
  falla. Además, el wrapper `asm/data/main/vutext.s` (el único textbin)
  solo se escribe si **no** existe: si quedó con una ruta de Windows, hay
  que borrarlo y volver a configurar (splat no lo pisa).
- **EOVERFLOW (compiladores viejos)**: los EE-GCC 2.96 son binarios de
  32 bits y no pueden leer del montaje de Windows (inodos de 64 bits por
  9p): «Value too large for defined data type». `ee-cc` compila desde un
  espejo en el fs del contenedor cuando `EE_CC_MIRROR=1`, que activan
  `tools/dock`, `tools/match.py` y `tools/compiler_id.py` en Windows
  (en Linux/macOS nada cambia). El espejo copia `src/`, `include/`,
  `matching/` y `asm/nonmatchings/` a `/tmp/ee-cc-mirror`, enlaza
  `build/` de vuelta a `/work` (symlink) y conserva las rutas relativas,
  así que los objetos son byte-idénticos y caen en el árbol montado.
- El ensamblador y el linker (`mips-linux-gnu-*`) son modernos y sí leen
  el montaje: no necesitan nada especial.

## Al arrancar Windows se ejecuta solo

Menú Inicio → `ror_auto_setup.cmd` → `tools/auto_setup.sh`:

1. Espera al motor de Docker (lanza Docker Desktop si no está en marcha).
2. Construye la imagen `ror-build` si hace falta.
3. Con `build/ok` presente, sale; si no, ejecuta configure + ninja +
   verificación SHA-1.
4. Logs: `build/auto_setup.log` (línea de tiempo), `build/auto_setup.boot.log`
   (salida cruda) y `build/auto_setup.ok` si todo fue bien.

## Al retomar

Pedirle al agente: «mira `build/auto_setup.log` y sigue». Con
`build/auto_setup.ok` presente el entorno está listo y se sigue el bucle de
`docs/DECOMPILING.md`.

## En curso / siguiente

- **`mag/maglifeman`** (siguiente archivo; 0x680 bytes, rango
  0x1194B4–0x119B34, `.rodata` en 0x2E9510): análisis empezado, aún sin C++.
  - Clase `MagLifeMan`: `m_life_buf[MAX_LIFE]` (64 entradas de 0x10 bytes:
    `{plife, flags, next, prev}`), cabecera de lista en 0x400 y
    `MAX_LIFE` = 64. Los objetos enlazados («life»; p. ej. `MagLife`) se
    llaman a través de una tabla de métodos en el campo +0x14 del objeto
    (formato `{short delta; fn}`).
  - Asserts originales y sus líneas: 103/104 (`thePod1`, `thePod2`),
    140/141 (`thePod1`, `thePod2`), 210 y 296 y 314
    (`ppod >= &m_life_buf[0] && ppod < &m_life_buf[MAX_LIFE]`),
    235/299/319 (`plife`), 268 (`theNo >= 0 && theNo < MAX_LIFE`).
    Las cadenas van a `tools/pad_asserts.py`; los nombres de `ror_assert`
    en el asm están en `D_002E9xxx`.
- Pendientes anteriores (C++ bajo `NON_MATCHING`): `bed/bedmemory` (init,
  shrink, cutHead), `dog/dogactor` (func_0010DF54), `dog/dogmodel` (vfunc11),
  `dog/dogtexinfo` (findFree, releasePack, loadTM2, loadPack),
  `mag/magsystem` (setPlayer, endFrame).

## Notas para el agente

- El delta vaddr↔fichero de este ELF es **0xFF000** para todas las secciones
  con contenido (`.text`, `.data`, `.rodata`), no 0x100000.
- `tools/asserts.py` y `tools/split_files.py` necesitan
  `build/SLUS_214.48.map`, que ya existe (el build de 20:29 quedó verde).
