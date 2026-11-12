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
