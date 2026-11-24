# Próxima sesión del coordinador

Reescrito el 2026-11-23 (tarde), a 40.33 %; puesto al día esa noche. Las versiones anteriores
(12 al 15 de noviembre) están en el historial de git; lo que seguía vigente
de ellas está aquí. Léelo después de `CLAUDE.md`, `notes/PROJECT_STATE.md`
(sobre todo el último «Estado») y `docs/DECOMPILING.md`.

## Al abrir

- Docker, `tools/match.py --server start`, la pestaña «Progreso workers» de
  Orca (`tools/orca/bars.py --watch 20`).
- Smoke: `tools/cpp_perm_queue.py --max-off 40 --skip
  build/workers/codex-owns.txt --avoid spr/sprtexture,msg/msgman,unk/001B64C4`
  (desde R28: 3 min por función, solo los tipos de casi que cierra, pesos de
  pases y puntuación nuevos; no integra un MATCH que empeore
  `tools/rules_check.py`). `codex-owns.txt` se vació el 23 nov (la lista
  vieja está en `codex-owns.old-close.txt`).
- Workers: Codex hace **G13 y G14** desde el 23 nov (con permiso del dueño;
  brief `codex-brief-g13g14.txt`); OpenCode (brief `opencode-brief-order5.txt`),
  Hydrogen en pausa (lo dosifica el dueño). Neon/Argon (Antigravity) vuelven
  el 29–30 nov: **G8–G12** son suyas (`build/workers/fable-tasks.tsv`).
- Herramientas nuevas del 23 nov: `tools/disc_scan.py` (busca donantes con
  símbolos en una imagen de disco; `--deep` mira dentro de archivos
  grandes) y `tools/retype.py` (cambia desplazamientos por miembros de la
  cabecera y solo deja lo que sigue idéntico; pásala tras cada tarea G).
- Todo cambio que integre o haga el coordinador debe pasar
  `tools/rules_check.py` (no subir la deuda de desplazamientos ni de alias).

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
