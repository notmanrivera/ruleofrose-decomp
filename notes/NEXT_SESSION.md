# Próxima sesión del coordinador

Escrito el 2026-11-12 al cerrar la sesión de los workers. Léelo después de
CLAUDE.md, `notes/PROJECT_STATE.md` y `docs/DECOMPILING.md` §6.

## Estado al cerrar

- Rama `pr-merge`, siempre con `build/ok` tras cada integración. Nada subido
  a GitHub. Avance: 18.02 % del código del juego (206,840 / 1,147,560 B);
  el día empezó en 16.80 %.
- Workers en Orca (worktrees al lado del repo):
  - `ror-wt-opencode` (OpenCode, DeepSeek V4.1 Flash, región Global):
    lotes de funciones chicas. Lo último que se le dio: `unk/0020ED9C`.
  - `ror-wt-gemini` (Antigravity): Gemini 4 Argon sin cuota hasta ~18-nov;
    Claude Opus/Sonnet dentro de Antigravity vuelven unas horas después del
    cierre; Gemini 3.8 Flash tiene cuota propia y quedó con `snd/rxmpeg`.
- Al abrir: `git -C ../ror-wt-<n> log pr-merge..` para ver si dejaron
  commits, y `sh tools/merge_worker.sh <n>` para integrarlos.
- Pendientes de funciones: `notes/TECH_DEBT.md`.

## Tarea 1: la jerarquía real de `mag/maglife.h`

Objetivo: declarar las clases `MagLife*` como el original, para que el
constructor, `message` y los archivos hermanos se escriban como métodos
con nombres reales en vez de funciones sueltas con `asm("símbolo")`.

Pruebas que ya hay:

- `notes/class_hierarchy.txt` (de los `__tf<Clase>` del binario) da el árbol:
  `MagLife0` → `MagLife` → `MagLifeControlChara` → {`MagLifeBillboard`,
  `MagLifeBwn`, `MagLifePC`, `MagLifeTest`}; además `MagLifeBwnCtrl`,
  `MagLifeFader`, `MagLifeNoise`, `MagLifeFadeKeyHole`, `MagLifeMenuBase`
  (16 menús), `MagLifePos` → `MagLifeWindow` → `MagLifeWindowDebug`,
  `S2dBg`, `S2dCineSco`, `S2dMes`, con el número de slots de cada vtable.
- **Error conocido:** `src/mag/maglifepc.h` dice que `MagLifePC` hereda de
  `MagLifeBillboard`; el RTTI dice que hereda de `MagLifeControlChara`
  (son hermanas). Hoy compila igual porque los offsets coinciden.
- Dependen de estas clases: `src/mag/maglife.cpp`, `maglife.h`,
  `maglifebwn.cpp`, `maglifeman.h`, `maglifepc.h` (y por él todos los
  `maglifepc*.cpp`), `maglifewindow.h`, `magsceneoption.cpp`.

Cómo comprobar cada paso: `tools/match.py` en cada archivo de esa lista
(todos deben seguir en "OK: object matches") y la compilación completa
(`build/ok`). Ningún worker debe estar trabajando en `mag/` mientras tanto
(hoy no lo está ninguno).

## Tarea 2: seguir mejorando los scripts

Ya hechos hoy: `tools/new_worktree.sh`, `tools/merge_worker.sh`,
`tools/backlog.py`, `docs/WORKER_BRIEF.md`, `tools/orca/watch_agent.sh`,
`tools/orca/send_brief.sh`, el aviso de relleno de `.rodata` en `match.py`.

Ideas pendientes, de más a menos útil:

1. Un solo comando `tools/orca/next_batch.sh <worker>` que encadene
   `merge_worker.sh` → `backlog.py --file ... --names N` → `send_brief.sh`
   con la plantilla de `WORKER_BRIEF.md` → `watch_agent.sh`. El ciclo
   completo costaría una llamada.
2. Recordar qué archivo tiene cada worker (un archivo en `build/`, no en
   git) para que `backlog.py --exclude` se llene solo.
3. Detectar en `watch_agent.sh` los mensajes de cuota agotada ("quota
   reached") y de filtro de contenido, y decirlo en vez de solo "idle".
4. `progress.py`: contar los intentos NON_MATCHING ("N casi listas").
5. Probar `new_worktree.sh` de punta a punta (hoy solo se probaron sus
   comprobaciones) y que copie también el nombre del servidor de match.
6. `merge_worker.sh`: avisar cuando un worker haya saltado muchas
   funciones (señal de que su sesión ya está muy larga).

## Hecho en la sesión siguiente (2026-11-12, tarde)

- Tarea 1 hecha (commit `bab916f`): `MagLife0`/`MagLife` viven ahora en
  `mag/maglife.h` con sus cuerpos inline (las copias de `asm/inline/`) y los
  campos de `MagLife` (+0x18..+0x2F: `m_scene`, `m_hide`). `MagLifePC` hereda
  de `MagLifeControlChara`. Además: el slot 16 no es de `MagLifeControlChara`
  (tiene 15) sino de `MagLifeBwn`/`MagLifePC`/`MagLifeTest`, cada una el
  suyo. `vfunc09` y `MagLifeBillboard::live` vuelven a ser métodos: son los
  "key methods", así que `mag/maglife` emite sus nombres RTTI y el `.rodata`
  de `mag/maglifepc` empieza en 0x2E96B0 (`config/splits_manual.tsv`).
- Fallo de GNU as 2.10-ee encontrado por el camino: si `.rodata` aparece por
  primera vez a mitad del archivo, puede ensamblar la carga de una tabla de
  saltos como lw+addu+lw en vez de lui+addu+lw. `include/include_asm.h` crea
  `.rodata` al principio de cada archivo parcial; `build/ok` sigue verde.
- Tarea 2: `tools/orca/next_batch.sh <worker> --watch` (ideas 1, 2 y 6),
  `watch_agent.sh` dice `STATUS: idle/quota/filter` (idea 3), `progress.py`
  cuenta los NON_MATCHING (idea 4). Falta la 5.

Pendiente que salió:

- `magscene.h` tiene su propio `MagLifePC` de mentira (0xE0 bytes, sin
  vtable) para `MagScene::m_pc` (+0x2ADC0); el real mide 0x220, así que
  `m_unk2AEA0`/`m_unk2AEA4` son campos del PC (+0xE0/+0xE4). Unificarlo con
  `maglifepc.h` y rehacer el relleno de `MagScene` hasta +0x2BD20.
- El `.rodata` de `mag/maglifetest` (0x2ED3C8) empieza con "10MagLifePos",
  "13MagLifeWindow", "8MagLife0", "7MagLife": son los nombres RTTI que cierra
  `mag/maglifewindow` (su key method está ahí); el límite está mal puesto,
  como el de `maglifepc`. Igual con "12MagLifeNoise" (0x2ED408), que
  `maglifetest.cpp` contiene (`MagLifeNoise__vfunc_06`).
- El constructor `func_0011A888` puede escribirse como constructor real de
  `MagLifeControlChara` (y el de `MagLifeBillboard`, inline, lo llama).
- La causa del fallo de as 2.10-ee, según OpenCode (unk/0020ED9C): tras
  secuencias de macros `li` / `dsll $r,$r,32` / `la $r,K($r)` el ensamblador
  deja mal su estado de `$at`, y un `lw/sw/s.s $r,sym($reg)` posterior pierde
  su `lui $at` (sale `lw $r,0($r)` con un R_MIPS_HI16). Los `.set noat` /
  `.set at` que rodean cada INCLUDE_ASM lo reinician; por eso aparecía y
  desaparecía al convertir funciones. El arreglo de `include_asm.h` (crear
  `.rodata` al principio) quizá solo lo esquiva en maglifepc: si vuelve a
  salir, mejor un `RESET_AT_STATE` (ver `src/unk/0020ED9C.cpp`) en
  `include_asm.h` y comprobarlo con la compilación completa.
- Resuelto: `tools/fix_hi16.py` repara en cada objeto (build y match.py)
  todo R_MIPS_HI16 que no caiga sobre un `lui`, con el registro base de su
  R_MIPS_LO16. Se quitó el parche de `include_asm.h`; `build/ok` verde, y
  reparó 2 instrucciones (maglifepc, 0020ED9C). Los `RESET_AT_STATE` de
  `unk/0020ED9C.cpp` ya no hacen falta.

## Revisión de scripts (Fable 5.2): pendiente

Aplicado en "Worker loop fixes from a review": --dry-run sin merge, candado
de merge, skipped solo si el worker la intentó, STATUS unknown, texto real
del brief (<STATE>), work.py. Falta, de más a menos útil:

- Coste: hoy el worker espera los ~200 s de la compilación completa en cada
  ciclo. Reordenar merge_worker: verificar, cherry-pick, resetear al worker y
  mandarle el lote, y compilar después (con el candado); ante un fallo,
  parar el bucle en vez de deshacer. Probar ninja con `docker exec` en el
  contenedor ror-match (ahorraría la copia del mirror, ~54 s).
- Hecho: `next_batch.sh --loop` (a196d8c) y `tools/twins.py` (fe66394:
  46 pendientes con gemela; work.py pone su C++ en el borrador y backlog.py
  las da primero). Falta el resumen corto en vez de 30 líneas de pantalla.
- skipped.txt ya guarda quién la saltó: añadir `--retry-from-others` para
  que el otro modelo la intente una vez antes de darla por perdida.
- work.py: la línea de los errores de compilación es la del .trial.cpp, no
  la de src/. match.py: avisar si el objeto tiene otro número de funciones
  que el juego, en vez de mostrarlo todo como "differ".
- merge_worker: integrar los commits verificados aunque uno falle;
  send_brief.sh: no depender del espaciado del JSON.
