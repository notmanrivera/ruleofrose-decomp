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

- **`mag/maglifeman` terminado** (12 funciones byte a byte y su `.rodata`,
  en la compilación completa y con el SHA-1 verificado). Clase
  `MagLifeManager` en `src/mag/maglifeman.h`; los nombres manglados de las
  12 funciones (y sus tamaños) están en `config/symbol_addrs_manual.txt`
  (extraídos del propio objeto). Si se edita `src/mag/maglifeman.cpp`, los
  asserts tienen que seguir en las líneas 103/104, 140/141, 210, 232/235,
  268, 296/299 y 314/319 (`tools/pad_asserts.py`, y `tools/asserts.py
  mag/maglifeman.cpp` los relee). Lección nueva del compilador en
  `docs/DECOMPILING.md`: un tramo de stores al final de una función hoja
  sale rotado (el último primero y el penúltimo en el hueco de `jr $ra`),
  así que hay que probar el orden de las sentencias.
- **`bed/bedmemory` terminado (17/17)**: `init`, `shrink` y `cutHead`
  emparejan byte a byte, más `.rodata`; la imagen completa sigue con el
  SHA-1 `fa157dc8…1997` y `build/ok` regenerado. `cutHead` necesitó una
  variable de registro explícita: `register int diff asm("$3");` para la
  diferencia `h2 - h - 32`. Sin ella, local-alloc le da `$v0` (su PRI es
  80000/16 = 5000 frente a 20000/10 = 2000 del `li -1`) y el `-1` cae en
  `$v1`; el juego tiene justo lo contrario (`diff` en `$v1`, `-1` en
  `$v0`). Fijar `diff` a `$3` deja libres `$v0`, `$a0` y `$a1`, y el
  resto de la asignación sale sola. La forma del fuente es la del juego:
  `diff = (int)h2 - (int)h; diff -= sizeof(BEDMEMHEADER);`.
- Siguiente: **`mag/maglife`** (0x119B34–0x11AB40: `MagLife0`/`MagLife` y
  las clases que cuelgan de ellas; sus vtables e inline están en
  `asm/data/vtbl/_vt_8MagLife0.data.s` etc. y `asm/inline/`), o cerrar los
  pendientes `NON_MATCHING`.
- Pendientes anteriores (C++ bajo `NON_MATCHING`): `dog/dogactor`
  (func_0010DF54), `dog/dogmodel` (vfunc11),
  `dog/dogtexinfo` (findFree, releasePack, loadTM2, loadPack),
  `mag/magsystem` (setPlayer, endFrame).

## Notas para el agente

- El delta vaddr↔fichero de este ELF es **0xFF000** para todas las secciones
  con contenido (`.text`, `.data`, `.rodata`), no 0x100000.
- `tools/asserts.py` y `tools/split_files.py` necesitan
  `build/SLUS_214.48.map`, que ya existe (el build de 20:29 quedó verde).
