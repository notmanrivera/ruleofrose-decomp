# Próxima sesión del coordinador

Reescrito el 2026-11-23 (tarde), a 40.33 %; puesto al día el 24 nov a 45.10 %. Las versiones anteriores
(12 al 15 de noviembre) están en el historial de git; lo que seguía vigente
de ellas está aquí. Léelo después de `CLAUDE.md`, `notes/PROJECT_STATE.md`
(sobre todo el último «Estado») y `docs/DECOMPILING.md`.

## Al abrir

**Pausa del 24 nov, 13:05, a 45.10 %** (el dueño: «pongamos pausa a todo»).
Todos los workers en `STATUS='paused'`, ningún ciclo en marcha, todo
integrado, `build/ok` en verde, árbol limpio. Para seguir:

1. Docker, `sh tools/orca/resume.sh --start`, `tools/match.py --server
   start`, la pestaña «Progreso workers» (`tools/orca/bars.py --watch 20`).
2. Volver a crear el informe de media hora (cron `7,37 * * * *`).
3. Hydrogen (gemini): `nohup sh tools/orca/next_batch.sh gemini --loop --max
   120 --names 6 --budget 400 --avoid
   mcd/mcdman,unk/TskEnemyMove,unk/0018BD94,unk/TskMsgMan >>
   build/workers/gemini-loop.log 2>&1 &` (se paró por cuota a las 13:00).
4. Codex: ~5 % semanal hasta el 29 nov 13:08; tandas de 1-2 casi
   (`codex-brief-close21.txt` como plantilla). G11 hecha.
5. Cada informe: `tools/techniques.py --since "1 day ago"` y aplicar su
   sección «Only data alignment left» (`config/rodata_align_manual.tsv`,
   configure, build completo): tres funciones gratis el 24 nov.

Lo hecho el 24 nov: G11 (gamsnd.h, Codex), `main` nombrado, registro de
técnicas (`Technique:`/`Blocker:` en cada commit, `tools/techniques.py`) y
su primera promoción a `docs/EE_GCC_TECHNIQUES.md`, `merge_worker.sh`
(acepta bajar `rules_check.tsv`; revisa los que incluyen una cabecera
cambiada de forma indirecta: el fallo de 07:23), triage completo
(`build/regalloc_triage.tsv`), Smoke (1 de 10) y Cyrax (0). Investigación
nueva: R29 (rule-of-rose-recomp, MIT) y R30 (nombres SDK de RozuRecomp).
Las tareas G8-G10 y G12 siguen reservadas para Neon/Argon (29-30 nov).

- Todo cambio que integre o haga el coordinador debe pasar
  `tools/rules_check.py` (no subir la deuda de desplazamientos ni de alias),
  y se hace commit en el acto (un cambio sin commit en el checkout principal
  para todas las integraciones).

## Trabajo para el coordinador, de más a menos útil

1. **Decompilar la librería RX (`rx/`, 25 archivos, 0 %).** Ya tiene sus
   límites y nombres originales (R24 + la versión de depuración de Arc the
   Lad de 2002: `rxsnd.c`, `sndse.c`, `rxfile.c`...) y 580 funciones con
   nombre. Primero averiguar sus opciones de compilador
   (`tools/flag_sweep.py` en un archivo pequeño, como `rx/rxgsvs`): puede
   no ser `-Os` como el juego. Para el port, su API es la frontera: se
   puede reimplementar en nativo sin decompilar el driver IOP.
2. **Tipos de la librería RX (R25).** Del `.mdebug` (stabs) de
   `disc/arc_koga/DATAIMG_KOGA_MAIN.ELF`: structs y prototipos para las
   cabeceras de `rx/`. Solo derivar nombres/tipos; nada de su código.
3. **Donantes: búsqueda cerrada para la librería RX** (R26,
   `notes/research/R26-rx-donors.md`): diez discos revisados; solo
   PoPoLoCrois y el CD de 2002 escondido en Arc the Lad tienen símbolos.
   Para el código propio del juego no hay donante. Si llega un disco nuevo:
   `tools/disc_scan.py --deep <imagen>`.
4. **Pagar deuda de legibilidad** (2,385 desplazamientos): casi todos están
   en funciones con `int arg0` (borradores de m2c), así que antes hay que
   saber la clase (trabajo de las G); `tools/retype.py` hace lo mecánico
   después. Sin tocar los archivos reservados.
5. **Smoke tras R28:** si sigue sin cerrar, `--resume` en los parciales
   (MnuDiary vfunc_05, func_00198CA8, renderPreMain) y una herramienta
   pequeña que pruebe pines `PS2_REG` y declaraciones de funciones
   llamadas (`void`/`throw()`), que es lo que piden los casi atascados.
6. **Intentos cercanos de `unk/MnuDiary`**: `vfunc_05` (Smoke llegó a
   puntuación 4, `build/cpp_perm/MnuDiary__vfunc_05/`), `func_0019AFB0`,
   `func_0019BD6C`, `func_0019B384` (tamaño exacto, registros). Quedan 18
   funciones en asm, varias grandes (`func_0019E474`, 5.7 KB).

## Pendientes antiguos que siguen vigentes

- `magscene.h` tiene su propio `MagLifePC` falso (0xE0 bytes, sin vtable)
  para `MagScene::m_pc` (+0x2ADC0); el real mide 0x220: unificarlo con
  `maglifepc.h` y rehacer el relleno de `MagScene` hasta +0x2BD20.
- El `.rodata` de `mag/maglifetest` (0x2ED3C8) empieza con los nombres RTTI
  que cierra `mag/maglifewindow` («10MagLifePos», «13MagLifeWindow»...): el
  límite está mal puesto, como estaba el de `maglifepc`.
- El constructor `func_0011A888` puede escribirse como constructor real de
  `MagLifeControlChara`.
- Un `context.c` con structs planos para que m2c escriba `this->m_x` en sus
  borradores (encaja con la regla de tipos).
- `merge_worker.sh`: integrar por archivo, para que uno malo no frene los
  demás.
- De sm64: una compilación NON_MATCHING enlazada que arranque en un
  emulador (el enlazado debe aceptar funciones de otro tamaño).
