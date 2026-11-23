# Próxima sesión del coordinador

Reescrito el 2026-11-23 (tarde), a 40.33 %. Las versiones anteriores
(12 al 15 de noviembre) están en el historial de git; lo que seguía vigente
de ellas está aquí. Léelo después de `CLAUDE.md`, `notes/PROJECT_STATE.md`
(sobre todo el último «Estado») y `docs/DECOMPILING.md`.

## Al abrir

- Docker, `tools/match.py --server start`, la pestaña «Progreso workers» de
  Orca (`tools/orca/bars.py --watch 20`).
- Smoke: `tools/cpp_perm_queue.py --minutes 10 --max-off 40 --skip
  build/workers/codex-owns.txt --avoid unk/001B64C4,unk/00166AD0` (salta lo
  ya probado; solo toma intentos de tamaño exacto y referencias correctas;
  no integra un MATCH que empeore `tools/rules_check.py`: queda en su log
  para pasarlo a tipos).
- Workers: Codex (5 h por ventana, briefs `codex-brief-close*`), OpenCode
  (brief `opencode-brief-order5.txt`), Hydrogen en pausa (lo dosifica el
  dueño). Neon/Argon (Antigravity) vuelven el 29–30 nov: **G8–G14** son
  suyas (`build/workers/fable-tasks.tsv`); no tomarlas antes.
- Todo cambio que integre o haga el coordinador debe pasar
  `tools/rules_check.py` (no subir la deuda de desplazamientos ni de alias).

## Trabajo para el coordinador, de más a menos útil

1. **`mw/sound` con los nombres de PoPoLoCrois.** Dividirla en sus
   archivos reales por prefijo (`rxSndSys`, `rxSndVoice`, `rxSndSe`,
   `rxSndPcm`, `rxSndAdpcm`, `rxSndBgm`, `rxSys`, `rxFile`, `rxTh`, `rxGs`...)
   en `config/splits_manual.tsv`, con la prueba en cada fila; luego empezar
   a decompilarla (hoy 0 %). Para el port, su API es la frontera: se puede
   reimplementar en nativo sin decompilar el driver IOP.
2. **Tipos de PoPoLoCrois.** Leer su DWARF 1 (`zipzip11/ps2-dwarf1` o un
   lector propio) para `rxmpeg.c` (nuestro `snd/rxmpeg`) y las cabeceras rx
   que use su código. Solo derivar nombres/tipos; nada de su código.
3. **Más donantes con símbolos.** Juegos con «RX Lib. Team» en sus créditos
   (Boku to Maou, Phase Paradox, Wa ga Ryuu o Miyo...) podrían nombrar las
   270 funciones de `mw/sound` que faltan; `tools/donor_symbols.py` acepta
   más entradas en `DONORS`. Para el código propio del juego, la mejor pista
   sigue siendo el **prototipo de localización del 19-jul-2006** (Hidden
   Palace): Sly 1 sacó sus nombres de uno así. Solo desde discos propios.
4. **Pagar deuda de legibilidad** donde más rinde: los archivos con más
   desplazamientos en código exacto (`tools/rules_check.py --list`), sin
   tocar los reservados para Neon/Argon. Tras bajar un archivo,
   `tools/rules_check.py --update <archivo>`.
5. **Intentos cercanos de `unk/MnuDiary`**: `vfunc_05` (Smoke llegó a
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
