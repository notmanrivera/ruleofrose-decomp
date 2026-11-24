# R26 — RX Library donors: results

Owner's external research (ChatGPT, 2026-11-23), kept verbatim below, with
the coordinator's checks first.

## Coordinator checks (2026-11-23)

- **Suikoden Tactics (USA) SLUS-21245** (owner's disc): no RX library
  (no `$RX_SCE_LIBRARY_VERSION`, no `rxsnd`), boot ELF stripped (GCC
  sections, `.mdebug.eabi64` empty). Only its IOP modules keep `.symtab`;
  not useful (we do not decompile IOP code). Extracted to disc/suikot/.
- **Arc the Lad: Twilight of the Spirits (USA) SCUS-97231**, `ARC.000`
  (2 GB padding file on the owner's retail disc) holds leftovers of
  earlier master images:
  - three 2048-byte-sector ISO images (volume "ARC"; created 2003-02-05,
    2002-09-02, 2002-09-02) whose directories survive but whose boot ELF
    `SCPS_150.40` is overwritten (not an ELF at its extent);
  - the **complete CD of 2002** that Hidden Palace describes (318,313
    sectors, PVD date 2000-12-25, `BOOT2 = cdrom0:\SCPS_000.00`), stored
    as 2348-byte records (4-byte LBA, 16 bytes of header/subheader, 2048
    data, 280 EDC/ECC). Its ELF `SCPS_000.00` (1,388,996 B, sha256
    aa8680763bfec8a41a144ff2e0ed888e9fa019e466ea61542097c2fab03de0b4)
    has RX version 4 and `rxsnd`, but is **stripped** (no .symtab,
    .debug, .mdebug). Its MODULES/ has RXSNDDRV.IRX and SNDN2DRV.IRX.
    Extracted to disc/arc_nested/ (git-ignored). No names to gain.
- **Rule of Rose 19-jul-2006 build (SLUS-28064)** is the owner's trade demo,
  checked 2026-11-15 (RESEARCH_QUEUE "Trade demo"): stripped.
- **Second batch (owner's discs, 2026-11-23)**, all with
  `$RX_SCE_LIBRARY_VERSION:4` and `rxsnd`, all stripped:
  Wa ga Ryuu o Miyo User Taikenban PAPX-90521 (`PAPX_905.21`) and retail
  SCPS-15080 (`SCPS_150.80`, VER 3.02): `.symtab`/`.strtab` headers kept
  but empty (size 0), single merged PROGBITS section; Phase Paradox
  SCPS-15005 and Boku to Maou Taikenban PAPX-90212: no symbol sections.
  Their strings name more RX modules (rxHeap*, rxFont*, rxRend*,
  rxCellMap*, rxColi*, rxMc*) that Rule of Rose does not link (it keeps
  only 7 rx* strings), so they add nothing. Extracted to disc/wagaryu,
  disc/wagaryu_demo, disc/phasepdx, disc/okage_demo (git-ignored).
  Conclusion: version 4 of the library was in use from 2001 (Phase
  Paradox) to 2006, and PoPoLoCrois SCPS-15063 stays the only donor with
  symbols found so far.
- **Correction (2026-11-23, tools/disc_scan.py --deep):** the 2002 CD
  inside ARC.000 also holds `DATAIMG/KOGA/MAIN.ELF` (6.1 MB, sha256
  bda03816...) and `MAIN_OLD.ELF` (sha256 e6885b4b...): debug builds with
  .symtab (7,167 / 7,026 symbols, 4,052 functions, 404 rx*), .mdebug and
  .stab, RX library version 4, no relocations. tools/donor_symbols.py got a
  relocation-free mode (masks from j/jal, lui and lui-based immediates) and
  both as donors arc2002/arc2002old: 155 matches, 151 agree with
  PoPoLoCrois's names (cross-validation), 1 disagrees (a debug-print stub,
  DPRINT vs MapDebugPrintf: dropped), 1 new name kept (rxThDrawSyncFunc;
  the other two were already SDK names). The 2002 RX library is older than
  ours, so most of the 270 unnamed mw/sound functions still differ.
  Extracted to disc/arc_koga/ (git-ignored).
- Previously listed as open: Wa ga Ryuu o Miyo demo PAPX-90521 and retail
  SCPS-15080 (credits "RX Lib.チーム", 2004: best lead), PoPoLoCrois
  Hajimari no Bouken SCPS-15027/15028 (2002), Boku to Maou PAPX-90212 and
  Phase Paradox PCPX-96316 (2001, older library). Check each with
  `$RX_SCE_LIBRARY_VERSION` + `.symtab` first; a donor goes into
  `DONORS` in tools/donor_symbols.py.

---

# R26 — Candidatos de RX Library con símbolos para *Rule of Rose*

**Fecha:** 23 de noviembre de 2026  
**Destino:** `notes/research/R26-rx-donors.md` (propuesta para revisión de Orca; no se ha escrito allí)  
**Alcance:** investigación pública en inglés y japonés, sin descarga ni inspección directa de los ELF propietarios.  
**Prioridad:** cubrir las funciones RX sin nombre después de usar el donante *PoPoLoCrois* `SCPS-15063`.

## 0. Resumen ejecutivo

**Punto de partida proporcionado por el proyecto, no revalidado aquí:** *Rule of Rose* contiene RX Library versión 4, aproximadamente 583 funciones / 830 KB; el ejecutable de *PoPoLoCrois: Tsuki no Okite no Bouken* `SCPS-15063` incluye 35.122 símbolos, DWARF 1 (`.debug`, `.line`) y `.mwcats`; el análisis binario del equipo permitió asignar **313** nombres y quedan alrededor de **270**. Estas cantidades proceden del encargo recibido, no de una nueva ejecución de `donor_symbols.py`.

**Nuevas pistas verificables más útiles:**

1. **`PAPX-90521`, *Wa ga Ryuu o Miyo* (User Taikenban)**: demo japonesa de un juego cuyos créditos incluyen explícitamente «RX Lib.チーム»; su existencia y serial están confirmados por catálogo comercial japonés y Redump. **No está verificado que conserve símbolos ni que el RX del ELF coincida con el de RoR**. Es la principal demo nueva para inspeccionar.
2. **`SCPS-15080`, *Wa ga Ryuu o Miyo* retail**, más **`SCAJ-30004`** (variante asiática de catálogo): buscar la versión de RX y comparar ejecutables antes de comprar distintas revisiones.
3. **Build completo del 22-ago-2002 de *Arc the Lad: Twilight of the Spirits***: Hidden Palace indica que se recuperó de imágenes de disco internas presentes en las ediciones comerciales, con imagen CD íntegra denominada `ARC.000` y serial interno `SCPS-00000`. **No es el ejecutable retail ya descartado**. La presencia de RX y de símbolos en ese build específico permanece sin comprobar.
4. **`PAPX-90212`, demo de *Boku to Maou* / *Okage: Shadow King***: acreditación explícita a RX Lib. Team en los créditos de la edición japonesa y demo japonesa catalogada; fecha 2001, por lo que probablemente se trate de otra versión de biblioteca. Sin evidencia de símbolos.
5. **`PCPX-96316`, *Phase Paradox* Taikenban 2**: demo de otro juego que acredita a RX Lib. Team; biblioteca probablemente más antigua (2001). No hay evidencia de símbolos.
6. **`SCPS-15027`, `SCPS-15028`, `SCPS-15006`, `SCPS-19207`, `SCPS-19307` de *PoPoLoCrois: Hajimari no Bouken***: título de 2002 que acredita RX Lib. Team, con reediciones hasta 2005. **No asumir que la reedición recompiló el ejecutable**, ni que una edición distinta recuperará nombres.

### Cómo interpretar «confirmado»

- **RX confirmado por comparación binaria:** demostrado por los archivos y herramientas del proyecto, indicado solo para RoR y `SCPS-15063` según el encargo. No se han inspeccionado nuevos ELF en esta investigación.
- **RX confirmado por ejecución:** log público con `RXSNDDRV.IRX` y/o prefijos `rxfile`, `rxsnd`; confirma **al menos el subsistema RX de sonido**, no identidad de toda la biblioteca EE.
- **RX acreditado en créditos:** acredita la relación histórica de RX Lib. Team con el juego, pero no su versión, funciones, nombre exacto ni presencia en todas las variantes.
- **RX probable / por comprobar:** vínculo de serie/estudio/edición; no equivale a detección.
- **Símbolos confirmados por catálogo** significa que un tercero los registra; solo el proyecto puede validar cantidad, nombres y sectores mediante análisis directo.

## 1. Tabla principal de candidatos y donantes

Orden: utilidad esperada para encontrar **nombres nuevos**, no calidad general del juego. Las columnas separan evidencia de RX y de símbolos. Todas las filas mantienen la edición precisa y su identificador, cuando está documentado.

| Prioridad | Juego / desarrollo | Edición / serial, año | RX y evidencia | Símbolos / evidencia | Decisión y fuentes |
|---|---|---|---|---|---|
| **Control positivo** | *PoPoLoCrois: Tsuki no Okite no Bouken* — G-Artists / SCEJ | JP retail `SCPS-15063`, build 19-feb-2004; lanzamiento mar-2004 | **Confirmado internamente** por comparación byte a byte del equipo | **Confirmados** en el reporte del proyecto (35.122 símbolos, DWARF 1, `.mwcats`); también listado como DWARF por [debugging.games](https://www.debugging.games/PlayStation%202) y [Retro Reversing](https://www.retroreversing.com/ps2-unstripped) | Ya utilizado para 313 nombres: comparar perfiles y medir qué módulos faltan antes de buscar donantes |
| **1A** | *Wa ga Ryuu o Miyo: Pride of the Dragon Peace* — producción G-Artists / SCEJ | **User Taikenban** JP `PAPX-90521`, distribuida 29-sep-2004 | **Créditos de RX confirmados para el juego base**, no analizado el ELF concreto; [créditos JP](https://raido.moe/staff/ps2/ps2_wagaryu_o_miyo.html) | **Desconocidos**; la existencia del disco está confirmada por [Suruga-ya](https://www.suruga-ya.jp/product/detail/144005651), [Redump](https://redump.info/discs?letter=W&region=&status=&system=) y [anuncio histórico](https://dengekionline.com/data/news/2004/9/29/be044375c4b2f6e4ce574dabd502014a.html) | **Primer disco NUEVO a examinar**, pues combina cronología 2004 y créditos RX |
| **1B** | *Wa ga Ryuu o Miyo* — G-Artists / SCEJ | JP retail `SCPS-15080`, 28-oct-2004 | **Créditos RX directos**: «RX Lib.チーム» | **Desconocidos**, sin inventario público específico; [catálogo SCPS](https://www.suruga-ya.jp/product/detail/144002218) | Segundo candidato del mismo juego; si demo falla, probar retail, comparar RX por módulos |
| **1C** | *Wa ga Ryuu o Miyo* | Asia `SCAJ-30004`, año por confirmar | **Probable** por ser variante del juego; no inspeccionada | **Desconocidos**; [PCSX2 Wiki](https://wiki.pcsx2.net/Waga_Ryuu_o_Miyo%3A_Pride_of_the_Dragon_Peace) | Comparar una vez conocidas las versiones JP; evitar compra si es ejecutable idéntico |
| **2** | *Arc the Lad: Twilight of the Spirits* — Cattle Call / SCEJ | **Build antiguo completo**, 22-ago-2002, `SCPS-00000` interno, imagen de disco `ARC.000`, recuperada dentro de discos retail | **Probable** para el build antiguo: RX constatado en retail USA, pero no se inspeccionó la versión previa | **Desconocidos**; Hidden Palace documenta origen, integridad del CD y fechas [ficha](https://hiddenpalace.org/Arc_the_Lad:_Twilight_of_the_Spirits_(Aug_22,_2002_prototype)) | **Muy alta prioridad** si se dispone de una edición retail que contenga el archivo incrustado; inspeccionar el ELF de ese CD, no solo el retail |
| **3** | *PoPoLoCrois: Hajimari no Bouken* — G-Artists / SCEJ | JP base `SCPS-15027` / `SCPS-15028`, premium `SCPS-15006`, 2002 | **Crédito RX Lib. Team** [créditos JP](https://raido.moe/staff/ps2/ps2_popolocrois_hajimari_no_bouken.html) | **Desconocidos**, no aparecen como DWARF confirmado en el catálogo consultado; [lista de versiones](https://wiki.pcsx2.net/PoPoLoCrois:_Hajimari_no_Bouken) | Familia técnica cercana al donante confirmado; podría aportar nombres de otros módulos RX, pero la versión es anterior |
| **3B** | *PoPoLoCrois: Hajimari no Bouken* | JP Best `SCPS-19207` (ene-2003), Best Reprint `SCPS-19307` (feb-2005) | Créditos RX en el **juego**, no comprobado por versión | **Desconocidos**; [GameFAQs](https://gamefaqs.gamespot.com/ps2/198321-popolocrois-hajimari-no-bouken/data) | Obtener solo si hay evidencia de ejecutable distinto; serial distinto no garantiza recompilación |
| **4** | *Boku to Maou* / *Okage: Shadow King* — Zener Works / SCEJ | JP **Taikenban** `PAPX-90212`, ca. 2001 | **Créditos directos a RX Lib. Team**, [créditos JP](https://raido.moe/staff/ps2/ps2_boku_to_maou.html) | **Desconocidos**; [Redump](https://redump.org/discs/system/ps2/status/5/sort/added/dir/asc/?page=13), [lista de demo](https://www.serialstation.com/titles/?title_id_type=PAPX) | Nuevo disco RX de etapa anterior; posible biblioteca incompleta/diferente |
| **4B** | *Boku to Maou* / *Okage* | JP `SCPS-11008`, Best `SCPS-19102`, USA `SCUS-97129`, 2001–02 | RX confirmado por créditos del juego; versión de EE no comparada | Desconocidos; [OGDB](https://ogdb.eu/index.php?gameid=22773&section=game), [release USA](https://gamefaqs.gamespot.com/ps2/471237-okage-shadow-king/data) | Controles frente a demo/prototipo; antiguo, probablemente menos rentable que Wa ga Ryuu |
| **4C** | *Okage: Shadow King* | **Prototipo de localización**, 2-jul-2001, Hidden Palace | RX atribuible al juego, no comprobado este build | **Desconocidos**: tiene menú debug, pero **menú debug ≠ símbolos ELF**; [Hidden Palace](https://hiddenpalace.org/Okage:_Shadow_King_(Jul_2,_2001_prototype)) | Priorizar si se busca una variante de desarrollo temprana |
| **5** | *Phase Paradox* — SCEJ | **Taikenban 2** `PCPX-96316`, ca. 2001 | **Crédito directo a RX Lib. Team** [créditos JP](https://raido.moe/staff/ps2/ps2_phase_paradox.html) | **Desconocidos**; demo e ID [Redump](https://redump.info/discs?letter=P&page=2&system=PS2), [PCSX2 Wiki](https://wiki.pcsx2.net/Phase_Paradox) | Otro donante temprano con estructura posiblemente diferente |
| **5B** | *Phase Paradox* | JP `SCPS-15005`, 2001 | Créditos RX directos; no comparado | Desconocidos; [PCSX2 Wiki](https://wiki.pcsx2.net/Phase_Paradox) | Solo después de la demo |
| **6** | *Wild Arms 5 / The Vth Vanguard* — Media.Vision / SCEJ (JP), XSEED (US) | USA retail `SLUS-21615`, 2007; JP retail `SCPS-15118`, 2006 | **RX sonido confirmado en USA** por [log de PCSX2](https://forums.pcsx2.net/Thread-Wild-ARMS-5-freezes-after-Ragu-o-Ragula?pid=583931): carga `RXSNDDRV.IRX` y mensajes `rxfile` | **Desconocidos** para retail; seriales [GameFAQs](https://gamefaqs.gamespot.com/ps2/931326-wild-arms-5/data) | Interesante para módulos `rxSnd*`, pero versión 2006/07 puede diferir y no hay símbolos confirmados |
| **6B — ya descartado** | *Wild Arms 5* | Demo JP `PAPX-90524` | RX en juego retail, confirmado en el build revisado según el equipo | **Sin símbolos**, según verificación previa del proyecto; existencia [catálogo de demo](https://muuseo.com/veru/items/89) | No repetir inspección salvo nueva revisión específica |
| **7 — ya descartado** | *Arc the Lad: Twilight of the Spirits* — Cattle Call / SCEJ | USA retail `SCUS-97231`, demo JP `PAPX-90230`/`PCPX-96330`, 2003 | **RX sonido confirmado** por [log de PCSX2](https://forums.launchbox-app.com/topic/46901-pcsx-15-via-launchbox-problem-with-saveload-states-eeir5900-32-recompiler-reset/?comment=296046&do=findComment) | **Sin símbolos** según examen anterior del equipo; [ficha demo](https://www.suruga-ya.jp/product/detail/144005584) | **No confundir con el build completo de 2002** que merece una inspección propia |
| **8, RX por verificar** | *Arc the Lad: End of Darkness* — secuela de Cattle Call / SCEJ | JP `SCPS-15058` (nov-2004), prototipo US del 22-abr-2005 | **NO CONFIRMADO** RX; relación de serie/desarrollo no prueba mismo motor | Símbolos **desconocidos**; [GameFAQs](https://gamefaqs.gamespot.com/ps2/921496-arc-the-lad-end-of-darkness/data), [Hidden Palace](https://hiddenpalace.org/Arc_the_Lad:_End_of_Darkness_(Apr_22,_2005_prototype)) | Abrir solo si se identifica cadena RX, `RXSNDDRV.IRX` o crédito |
| **8B, RX por verificar** | *Wild Arms 4* — Media.Vision / SCEJ | JP `SCPS-15091`, demo `PCPX-96654` (2005) | **NO CONFIRMADO** RX, no extrapolar desde WA5 | Símbolos **desconocidos**; [lista de demos](https://wiki.pcsx2.net/Complete_List_of_Demos_and_Tool_Discs) | Probar primero cadena RX en retail/demo antes de priorizar |
| **8C, RX por verificar** | *Wild Arms: Alter Code F* — Media.Vision | Prototipo de localización del 13-abr-2005, Hidden Palace | **NO CONFIRMADO** RX; no basta mismo estudio/saga | Símbolos **desconocidos**; [Hidden Palace](https://hiddenpalace.org/Wild_Arms:_Alter_Code_-_F_(Apr_13,_2005_prototype)) | Candidato condicionado a detectar RX |

**Nota sobre fechas:** `SCPS-15063` está catalogado con fecha interna 19-feb-2004 y su lanzamiento fue en marzo de 2004; es incorrecto tratar 2005 como año de ese ejecutable. Un número en las listas de ejecutables suele designar *build*, no necesariamente lanzamiento.

## 2. Candidatos SCEJ con símbolos públicos pero RX no identificado

Son potenciales **donantes de SDK/GCC**, y solo se convierten en donantes RX si se encuentran evidencias de biblioteca dentro de su ejecutable. No mezclar estas filas con las confirmadas por créditos.

| Juego | Serial / fecha del build registrado | Símbolos | RX | Fuente |
|---|---|---|---|---|
| *Ka 2: Let's Go Hawaii* | `SCPS-15045` / 8-jun-2003 | Catalogado como ejecutable **unstripped** por Retro Reversing | **Sin prueba de RX** | [PS2 unstripped](https://www.retroreversing.com/ps2-unstripped) |
| *Operator's Side* / *Lifeline* | `SCPS-15038` / 6-ene-2003 | Catalogado como **unstripped** | **Sin prueba de RX** | [PS2 unstripped](https://www.retroreversing.com/ps2-unstripped) |
| *Dark Chronicle*, demo | `PAPX-90506` / 2-sep-2002 | Catalogado **unstripped** | **Sin prueba de RX** (desarrollado por Level-5; no asumir biblioteca Sony) | [PS2 unstripped](https://www.retroreversing.com/ps2-unstripped) |

Estos juegos no tienen prioridad alta R26 hasta detectar cadenas `$RX_SCE_LIBRARY_VERSION`, `rxsnd`, `rxfile`, o presencia de `RXSNDDRV.IRX` en sus propios discos. El hecho de que estén publicados por Sony no basta.

## 3. Demos japonesas SCEJ de 2003–2007: lista operativa

**Solo entradas con un serial y vínculo verificables; no es un inventario exhaustivo de todos los discos japoneses existentes.** Separadas entre nuevas, revisadas y de RX incierto.

| Disco | Año | Contenido / relación | Estado RX y símbolos | Fuente |
|---|---:|---|---|---|
| `PAPX-90230` / `PCPX-96330` | 2003 | *Arc the Lad: Twilight of the Spirits* «PremiereDisc» | RX sí según trabajo anterior; sin símbolos según R26 | [Suruga-ya](https://www.suruga-ya.jp/product/detail/144005584) |
| `PAPX-90503` | 2004 | *PoPoLoCrois: Tsuki no Okite no Bouken*, Fan Limited Disc | RX sí, sin símbolos según R26 | [PCSX2 Wiki](https://wiki.pcsx2.net/Complete_List_of_Demos_and_Tool_Discs) |
| `PAPX-90521` | 2004 | **Wa ga Ryuu o Miyo — User Taikenban** | RX acreditado para el juego, **no analizado este ELF**; símbolos desconocidos | [Suruga-ya](https://www.suruga-ya.jp/product/detail/144005651); [Dengeki](https://dengekionline.com/data/news/2004/9/29/be044375c4b2f6e4ce574dabd502014a.html) |
| `PCPX-96654` | 2005 | *Wild Arms 4* (Taikenban) | RX y símbolos no confirmados | [PCSX2 Wiki](https://wiki.pcsx2.net/Complete_List_of_Demos_and_Tool_Discs) |
| `PAPX-90524` | 2006 | *Wild Arms: The Vth Vanguard* (Taikenban) | RX sí; sin símbolos según R26 | [registro de disco](https://muuseo.com/veru/items/89) |

**Demos relevantes anteriores a 2003** que también pueden servir:

| Disco | Fecha aproximada | Relación |
|---|---|---|
| `PAPX-90212` | 2001 | *Boku to Maou*, RX acreditado, símbolos desconocidos; [Redump](https://redump.org/discs/system/ps2/status/5/sort/added/dir/asc/?page=13) |
| `PCPX-96316` | 2001 | *Phase Paradox*, RX acreditado, símbolos desconocidos; [Redump](https://redump.info/discs?letter=P&page=2&system=PS2) |
| `PCPX-96328` | 2002 | Disco con tres títulos, incluye material de *PoPoLoCrois: Hajimari no Bouken*; proyecto confirmó que no aporta RX ni símbolos. [PCSX2 Wiki](https://wiki.pcsx2.net/List_of_games) |

**Falsos positivos de formato:** `PCPX-96518` se cataloga como video demo y `PAPX-96564` como Dramatic DVD: no deben tratarse automáticamente como ejecutables PS2 analizables. Fuentes: [PCSX2 Wiki](https://wiki.pcsx2.net/Complete_List_of_Demos_and_Tool_Discs).

## 4. Prototipos públicos pertinentes

| Prioridad | Título y build | Evidencia publicada | ¿Símbolos? | Siguiente comprobación |
|---|---|---|---|---|
| **Muy alta** | *Arc the Lad: Twilight* — **22-ago-2002** | Hidden Palace documenta que una imagen CD íntegra (318.313/318.313 sectores) `ARC.000`, serial interno `SCPS-00000`, está presente como disco anidado en ediciones retail. [Ficha](https://hiddenpalace.org/Arc_the_Lad:_Twilight_of_the_Spirits_(Aug_22,_2002_prototype)) | **No confirmado** | Determinar si el ejecutable del disco anidado contiene `.symtab`, `.debug`, `.mdebug`, `.mwcats` o un `.map`; extraer cadena RX |
| Media | *Arc the Lad: Twilight* — 24-feb-2003 y 1-abr-2003 | Mencionados en la galería de versiones del juego en Hidden Palace; no encontré contenido ELF verificado | **No confirmado** | Establecer si el ELF es una nueva compilación respecto a retail, y dónde están los símbolos |
| Baja | *Arc the Lad: Twilight* — 18-nov-2003 (review PAL) | Hidden Palace dice expresamente que es idéntico al retail PAL v1.00 salvo sectores del disco maestro. [Ficha](https://hiddenpalace.org/Arc_the_Lad:_Twilight_of_the_Spirits_(Nov_18,_2003_prototype)) | No hay evidencia adicional | **Descartar como nueva fuente de símbolos** si ya se comprobó retail PAL |
| Media condicionada | *Arc the Lad: End of Darkness* — 22-abr-2005 | Prototipo registrado por Hidden Palace; RX no demostrado. [Ficha](https://hiddenpalace.org/Arc_the_Lad:_End_of_Darkness_(Apr_22,_2005_prototype)) | **No confirmado** | Buscar RX primero |
| Media condicionada | *Wild Arms: Alter Code F* — 13-abr-2005 | Prototipo de localización de 2005 registrado; RX desconocido. [Ficha](https://hiddenpalace.org/Wild_Arms:_Alter_Code_-_F_(Apr_13,_2005_prototype)) | **No confirmado** | Buscar RX primero |
| Baja | *Okage: Shadow King* — 2-jul-2001 | Hidden Palace describe prototipo de localización con menú debug, pero **no afirma símbolos ELF**. [Ficha](https://hiddenpalace.org/Okage:_Shadow_King_(Jul_2,_2001_prototype)) | **No confirmado** | Probar ejecutable y SDK de la época si se obtiene legalmente |
| Baja sin pista RX | *Genji: Dawn of the Samurai* — 12-may, 13-jul y 15-jul-2005 | Builds registrados por Hidden Palace. [Índice](https://hiddenpalace.org/Prototypes_by_system/PlayStation_2) | **No confirmado**, RX tampoco | Solo después de encontrar cadenas/IRX RX en alguna edición |
| Revisar aparte | *Rule of Rose* — 19-jul-2006 `SLUS-28064` | Confirmado como disco de localización, prensa, y build fechado. [Ficha](https://hiddenpalace.org/Rule_of_Rose_(Jul_19,_2006_prototype)) | La ficha **no documenta símbolos** | Si no se ha inspeccionado su ELF, ejecutar `readelf -SW` y buscar `.map`; no inferir por ser prototipo |

### Particularidad de los prototipos *Arc the Lad*

El registro de Hidden Palace explica que no basta mirar el `SCUS_972.31` o `SCPS_150.40` principal: dentro del disco existen imágenes maestras anidadas, con varias revisiones, y el CD de 2002 está completo. Si el equipo tiene un disco retail de *Arc* adquirido legalmente, investigar **esos datos internos** puede ser más rentable que comprar otro título. La existencia de un ELF con símbolos en el build anidado sigue sin probarse.

## 5. Callejones sin salida y cómo no repetirlos

Estas verificaciones son **resultados aportados por el proyecto en el encargo**; no se repitieron aquí:

- *Rule of Rose* comercial USA/EUR/JP y demo comercial `SLUS-28063`: RX sí, sin símbolos en las versiones revisadas. **Ojo:** no confundir con `SLUS-28064` del 19-jul-2006; su ficha de Hidden Palace no permite concluir sobre `.symtab`.
- *PoPoLoCrois: Tsuki no Okite*, demo `PAPX-90503`: RX sí, sin símbolos. No confundir con retail `SCPS-15063` con DWARF.
- *Arc the Lad: Twilight*, retail USA `SCUS-97231` y demo `PAPX-90230`: RX sí, sin símbolos. **El build anidado completo de 2002 es otra versión y otra oportunidad.**
- *Wild Arms 5*, demo `PAPX-90524`: RX sí, sin símbolos; inspeccionar otras variantes solo si hay diferencia de ELF.
- *PoPoLoCrois* disco de tres juegos `PCPX-96328` / `SCPS-15025`: ya descartado por el equipo.
- *Ape Escape 3*, *Million Monkeys*, *Chulip*, *Chaindive*, *Athens 2004*: ya revisados sin RX utilizable; aunque *Ape Escape 3* comparta formato i3d, **i3d ≠ RX**.
- *Suikoden Tactics* `SLUS-21245`: candidato para **SDK/GCC** de 2004–05, no hay pruebas de RX; mantener fuera de la cola RX hasta encontrar cadenas/IRX.
- No contar un agradecimiento a RX Lib. Team como prueba de funciones idénticas ni de nombres exportables.
- No tomar un disco de vídeo promocional como prueba de una aplicación ejecutable.
- No inferir ausencia de símbolos solo por ausencia en catálogos, ni presencia solo por tener menú debug.

## 6. Ruta de verificación local en Orca

**No se inspeccionaron binarios en esta investigación.** Para cada candidato nuevo que el propietario consiga legítimamente, entregar el ELF/IRX y resultados derivados **sin subir ni publicar código o assets propietarios**.

### Paso A — identificar la variante, guardar evidencia

```bash
sha256sum "disc/<SERIAL>/<ELF>"
file "disc/<SERIAL>/<ELF>"
readelf -hW "disc/<SERIAL>/<ELF>"
readelf -SW "disc/<SERIAL>/<ELF>" | grep -Ei 'symtab|strtab|debug|line|mdebug|stab|mwcats|pdr'
readelf -sW "disc/<SERIAL>/<ELF>" > "build/donors/<SERIAL>.symbols.txt"
strings -a "disc/<SERIAL>/<ELF>" | grep -Ei 'RX_SCE_LIBRARY_VERSION|rxsnd|rxfile|rxmpeg|rxcoli|rxSnd|rxGs|rxSif|XVAB|XSEQ'
```

`readelf -sW` puede fallar o no proporcionar funciones aunque haya información CodeWarrior/DWARF 1. Para `.debug`, `.line`, `.mwcats`, complementar con importación del ELF en Ghidra y revisar tanto el símbolo como sus rangos. Un `strings` positivo aislado tampoco prueba la presencia de la biblioteca completa.

### Paso B — buscar mapas y módulos de disco

```bash
find "disc/<SERIAL>/extracted" -type f \
  \( -iname '*.map' -o -iname '*.sym' -o -iname '*.elf' \
     -o -iname '*.irx' -o -iname '*.000' \)
```

Para *Arc*, inspeccionar `ARC.000` y las revisiones completas o parciales **como imágenes de disco internas**, sin asumir que son ejecutables. No confundir tamaños de imágenes con tamaño de ELF.

### Paso C — comparar RX sin falsos positivos

1. Registrar SHA-256 y versión RX de los dos ELF; anotar nombres conocidos y desconocidos.
2. Clasificar donantes por coincidencia exacta con relocalizaciones correctamente resueltas, función/tamaño y referencia cruzada; si hay una variante del compilador, comparar estructura del flujo sin asignar nombres automáticamente.
3. Aplicar el enmascarado específico de **cada tipo de relocación** (`R_MIPS_26`, `HI16`, `LO16`, `R_MIPS_32`, etc.) y exigir un mínimo de bits no enmascarados. Enmascarar todo lo variable sin más produce falsas coincidencias en funciones pequeñas.
4. Validar identidad de cuerpo, llamadas, imports, constantes y contexto de archivo. Los nombres por inferencia van a una tabla de candidatos, no directamente a Ghidra.
5. Mantener separados **RX en el Emotion Engine** y `RXSNDDRV.IRX` (módulo IOP): una coincidencia de IRX no garantiza identidad de las funciones `rxSnd*` del EE.
6. No forzar un nombre donde dos símbolos de donantes den identidades diferentes para la misma función RoR: registrar colisión y revisión manual.

### TSV recomendado: `build/donors/r26_candidates.tsv`

```tsv
ror_address	ror_old_name	new_name	donor_game	disc_serial	donor_sha256	donor_address	match_method	evidence	confidence	status
```

**Estados sugeridos:** `BIN_IDENTICAL_RELOC_VALIDATED`, `SIMILAR_MANUAL_REVIEW`, `CREDIT_ONLY_NO_BINARY`, `REJECTED`, `NOT_CHECKED`. Solo el primero puede entrar en la importación automática con más controles y sin contradicciones.

### Métrica de resultado

- **Nuevas funciones RX nombradas y únicas**, con referencias a donante y comprobación binaria.
- Cobertura **por módulo RX**, no solo el total: `rxSndSys`, `rxSndVoice`, `rxSndSe`, `rxSndPcm`, `rxSndAdpcm`, `rxSndBgm`, `rxSys`, `rxFile`, `rxTh`, `rxGs`, `rxSif`, `rxmpeg`, `rxcoli`.
- Cantidad de coincidencias directas vs. inferencias; colisiones y falsas coincidencias revisadas.
- Tiempo y costo por nombre verificado; evitar repetir disco/edición cuyo ejecutable es idéntico.

## 7. Prioridades: qué adquirir o inspeccionar primero

**Orden pragmático y condicionado por disponibilidad de discos legítimos:**

1. **Sin compra adicional (si se posee retail de Arc):** localizar `ARC.000`, recuperar imagen CD interna de 2002, extraer su ELF y examinar `RX_SCE_LIBRARY_VERSION`, `.symtab`, `.debug`, `.line`, `.mwcats`, `.map`. Si hay símbolos y RX, será un excelente donante; si no, parar.
2. **Primera adquisición nueva para RX:** demo japonesa **`PAPX-90521`** de *Wa ga Ryuu o Miyo*; abrir ELF principal definido en `SYSTEM.CNF` y comprobar RX, símbolos y funciones desconocidas de RoR.
3. **Segundo disco nuevo:** retail **`SCPS-15080`** del mismo juego, si la demo no aporta; cruzar SHA-256 y comparar biblioteca, no suponer iguales.
4. **Tercer grupo:** ediciones *PoPoLoCrois: Hajimari no Bouken* **`SCPS-15027` / `SCPS-15028`** y, solo ante evidencia de diferencia técnica, `SCPS-19207` / `SCPS-19307`.
5. **Cuarto grupo:** demos `PAPX-90212` (*Boku to Maou*) y `PCPX-96316` (*Phase Paradox*), preferiblemente cuando resulten fáciles de obtener.
6. **Candidatos complementarios:** *Wild Arms 5* retail JP `SCPS-15118` o USA `SLUS-21615` y prototipos *Arc*; buscar ante todo **nuevas funciones**, aunque no haya símbolos.
7. **Lista condicionada RX:** *Arc: End of Darkness* / *Wild Arms 4* / *Wild Arms: Alter Code F* y sus demos/prototipos; **no comprar por RX** hasta que aparezcan cadenas/IOP RX en fuentes verificables.

**Regla económica:** si un candidato no conserva símbolos, solo justificar otra edición si incorpora una biblioteca distinta o sirve para hallar un tercer donante identificable. Diferentes discos con el mismo ELF no aportan nombres nuevos.

## 8. Sources y calidad de la evidencia

**Créditos japoneses RX:**

1. *PoPoLoCrois: Hajimari no Bouken* — https://raido.moe/staff/ps2/ps2_popolocrois_hajimari_no_bouken.html (literal «RX Lib. Team»).
2. *Wa ga Ryuu o Miyo* — https://raido.moe/staff/ps2/ps2_wagaryu_o_miyo.html («RX Lib.チーム»).
3. *Phase Paradox* — https://raido.moe/staff/ps2/ps2_phase_paradox.html.
4. *Boku to Maou* — https://raido.moe/staff/ps2/ps2_boku_to_maou.html.

**Identificadores y variantes:**

5. *Wa ga Ryuu* demo, `PAPX-90521` — https://www.suruga-ya.jp/product/detail/144005651 ; https://dengekionline.com/data/news/2004/9/29/be044375c4b2f6e4ce574dabd502014a.html
6. *Wa ga Ryuu* retail, `SCPS-15080` — https://www.suruga-ya.jp/product/detail/144002218
7. *PoPoLoCrois* ediciones — https://wiki.pcsx2.net/PoPoLoCrois:_Hajimari_no_Bouken ; https://gamefaqs.gamespot.com/ps2/198321-popolocrois-hajimari-no-bouken/data
8. Catálogo de demos — https://wiki.pcsx2.net/Complete_List_of_Demos_and_Tool_Discs
9. *Arc* demo — https://www.suruga-ya.jp/product/detail/144005584

**Evidencia técnica:**

10. Registro público de carga de `RXSNDDRV.IRX` en *Wild Arms 5* — https://forums.pcsx2.net/Thread-Wild-ARMS-5-freezes-after-Ragu-o-Ragula?pid=583931
11. Registro de `RXSNDDRV.IRX` en *Arc* — https://forums.launchbox-app.com/topic/46901-pcsx2-15-via-launchbox-problem-with-saveload-states-eeir5900-32-recompiler-reset/?comment=296046&do=findComment
12. Índice de ELF con símbolos — https://www.retroreversing.com/ps2-unstripped
13. Catálogo de ejecutables con DWARF (*PoPoLoCrois*) — https://www.debugging.games/PlayStation%202
14. Hidden Palace *Arc* 22-ago-2002 con imagen CD íntegra en retail — https://hiddenpalace.org/Arc_the_Lad:_Twilight_of_the_Spirits_(Aug_22,_2002_prototype)
15. Hidden Palace *Arc* 18-nov-2003 idéntico PAL retail — https://hiddenpalace.org/Arc_the_Lad:_Twilight_of_the_Spirits_(Nov_18,_2003_prototype)
16. Hidden Palace *Okage* prototipo con menú debug — https://hiddenpalace.org/Okage:_Shadow_King_(Jul_2,_2001_prototype)
17. Hidden Palace *Wild Arms: Alter Code F* — https://hiddenpalace.org/Wild_Arms:_Alter_Code_-_F_(Apr_13,_2005_prototype)
18. Hidden Palace *Rule of Rose* 19-jul-2006 — https://hiddenpalace.org/Rule_of_Rose_(Jul_19,_2006_prototype)
19. Archivo de módulos IRX (presencia genérica, no símbolos de ningún juego) — https://www.retroreversing.com/irx-ps2

## 9. Encargo de seguimiento listo para Claude/Orca

> R26: usar esta investigación como **índice de candidatos, no lista de símbolos confirmados**. Mantener 313 coincidencias ya verificadas como línea base. Para cada variante nueva: documentar `SYSTEM.CNF`, identificador real, SHA-256 del ELF, sección RX, `RX_SCE_LIBRARY_VERSION`, secciones de depuración, conteo de funciones con nombre y comparación de relocalizaciones contra `SLUS-21448`. Priorizar, en este orden: *Arc* 22-ago-2002 incrustado en retail (si está disponible), *Wa ga Ryuu* demo `PAPX-90521`, retail `SCPS-15080`, *PoPoLoCrois Hajimari* 2002 y demos de 2001. No modificar símbolos ni código fuente hasta tener corroboración binaria. No subir, publicar ni compartir ejecutables o assets propietarios. Entregar TSV de nombres **nuevos** y dos controles positivos y negativos por módulo. Marcar como `NOT_CHECKED` todo candidato no inspeccionado, aunque su juego tenga créditos de RX.

---

**Conclusión:** el resultado más prometedor **no es una lista extensa de títulos SCEJ**, sino un conjunto corto de versiones concretas: *Wa ga Ryuu o Miyo* (`PAPX-90521` / `SCPS-15080`) por sus créditos RX cercanos a 2004 y el CD interno de *Arc the Lad* del 22-ago-2002 por ofrecer un **build alternativo completo** dentro de discos que el proyecto podría tener ya. **Ninguno está confirmado todavía como donante de nuevos símbolos.**
