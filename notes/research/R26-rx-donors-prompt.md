# R26 — Juegos de PS2 con la «RX Library» de SCE Japón y símbolos de depuración

Investigación externa (la hace el dueño con ChatGPT, con búsqueda web).
Abajo está el texto para pegar tal cual. Lo que devuelva se guarda en
`notes/research/R26-rx-donors.md` y el coordinador lo comprueba con
`tools/donor_symbols.py` antes de usar nada.

---

## Texto para pegar en ChatGPT

> Necesito una investigación web detallada y con fuentes. Responde en
> español, pero busca en inglés **y en japonés**. Distingue siempre lo
> confirmado (con enlace) de lo que supones.

### Contexto

Hago una decompilación «matching» (reescribir el código en C/C++ hasta
que compile a los mismos bytes) de **Rule of Rose** (PS2, NTSC-U
SLUS-21448, Punchline / Atlus, 2006, publicado en Japón por Sony
Computer Entertainment Japan). Es un proyecto de preservación de código
abierto. Solo uso discos que tengo físicamente o volcados de mis propios
discos.

El juego incluye una librería interna de **Sony Computer Entertainment
Japan** llamada **RX Library** («RX Lib.», a veces acreditada como
«RX Lib. Team» o «RXライブラリ»). La librería cubre sonido (driver de
IOP propio, `RXSNDDRV.IRX`), archivos, hilos, gráficos y MPEG. En
nuestro ejecutable ocupa unas **583 funciones (~830 KB)**. Las cadenas
que la identifican en un ejecutable son:

- `$RX_SCE_LIBRARY_VERSION:4` (en nuestro juego la versión es 4)
- mensajes como `rxsnd : can't allocate SPU heap '%d'`,
  `rxsnd : failed to open XVAB`, `rxsnd : open ADPCM '%d'`,
  `*** rxsndut : BG thread called! %s`,
  `rxFile: occured I/O error (%d), RX_FILE_DEVICE_HDD.`
- nombres de archivo fuente `rxmpeg.c` / `rxmpeg.cpp`, `rxcoli.c`
- formatos de sonido propios **XVAB** y **XSEQ**
- el módulo IOP `RXSNDDRV.IRX` en el disco
- prefijos de funciones: `rxSndSys…`, `rxSndVoice…`, `rxSndSe…`,
  `rxSndPcm…`, `rxSndAdpcm…`, `rxSndBgm…`, `rxSys…`, `rxFile…`, `rxTh…`,
  `rxGs…`, `rxSif…`

**Lo que ya encontramos:** *PoPoLoCrois: Tsuki no Okite no Bouken*
(SCPS-15063, SCEJ, 2005). Su ejecutable `SCPS_150.63` salió **sin quitar
los símbolos**: tabla de símbolos con 35 122 entradas, información de
depuración DWARF 1 (`.debug`, `.line`) y sección `.mwcats`
(compilador Metrowerks CodeWarrior). Su RX Library es idéntica byte a
byte a la nuestra. Con eso nombramos **313 de las 583** funciones.
Faltan **unas 270**, sobre todo partes de la librería que PoPoLoCrois
no usa. Por eso necesito más juegos con la misma librería y con
símbolos.

**Ya revisé, y no sirven** (tienen la librería pero el ejecutable está
sin símbolos, o no tienen la librería):

| Juego | ID | RX | Símbolos |
|---|---|---|---|
| Rule of Rose (USA, EUR, JP, demo comercial) | SLUS-21448, SLES-54218, SCPS-15093, SLUS-28063 | sí | no |
| PoPoLoCrois Tsuki no Okite, disco «fan» | PAPX-90503 | sí | no |
| Arc the Lad: Twilight of the Spirits (USA) | SCUS-97231 | sí | no |
| Arc the Lad: Seirei no Kokon, demo JP | PAPX-90230 | sí | no |
| Wild Arms: The Vth Vanguard, demo JP (Taikenban) | PAPX-90524 | sí | no |
| Disco demo de 3 títulos con PoPoLoCrois | SCPS-15025 / PCPX-96328 | no | no |
| Ape Escape 3 / Saru! Get You! 3 (varios) | SCPS-15096, SCES-53642, SCUS-97548, PCPX-96657 | no | no |
| Saru! Get You! Million Monkeys demo | PCPX-98041 | no | no |
| Chulip | SLUS-20742 | no | no |
| Chaindive | — | no | no |
| Athens 2004 demo | SCED-52491 | no | no |
| Suikoden Tactics (USA), Konami 2005 (GCC, no SCEJ) | SLUS-21245 | no | no (solo los módulos IOP, que no nos sirven) |

Que Arc the Lad y Wild Arms 5 tengan la librería indica que la usaban
juegos **publicados o coproducidos por SCE Japón** entre 2003 y 2007.

### Lo que necesito

**Parte 1. ¿Qué juegos usan la RX Library?** Una lista lo más completa
posible de juegos de PS2 (y, si aparecen, de PSP) que la usan. Fuentes
posibles:
- créditos («RX Lib.», «RX Library», «RXライブラリ», «Library Team» en
  juegos de SCEJ) en MobyGames, GameFAQs, las wikis de cada juego y
  vídeos de créditos;
- listas de juegos publicados por SCE Japón en PS2, como Wikipedia JP
  「ソニー・コンピュータエンタテインメントのゲームタイトル一覧」, para
  cruzarlas;
- menciones de `RXSNDDRV.IRX`, `XVAB` o `XSEQ` en foros de *ripping*
  de audio (Zenhax, Xentax, VGMToolbox, vgmstream, «XVAB format»,
  «.xvb», «.xsq»);
- vgmstream y sus listas de formatos/juegos soportados: buscar los
  formatos XVAB/XSEQ y de qué juegos vienen;
- desarrolladores asociados a SCEJ en esa época: Media.Vision (Wild
  Arms), Cattle Call (Arc the Lad), G-Artists / Epics (PoPoLoCrois),
  Punchline, SCEJ interno (Japan Studio), Contrail, Sugar & Rockets,
  Clap Hanz (Everybody's Golf / Minna no Golf 4), Polyphony (descartar,
  usa librería propia).

**Parte 2. ¿Cuáles de esos tienen símbolos de depuración?** Para cada
juego de la Parte 1 (y para cualquier juego de SCEJ, aunque no sepas si
usa RX), busca si alguna versión salió con símbolos:
- **The Cutting Room Floor** (tcrf.net): páginas de cada juego y las
  categorías «Games with debugging symbols», «Games with unused code»,
  «Debug symbols», «Prototype»;
- **Hidden Palace** (hiddenpalace.org): prototipos y builds de
  desarrollo de PS2 de SCEJ, por ejemplo el **prototipo de localización
  de Rule of Rose del 19 de julio de 2006**: ¿qué contiene el ELF, tiene
  `.symtab` o un `.map`?;
- listas de la comunidad de decompilación de PS2 con «symbols» o
  «unstripped ELF»: el servidor/wiki de decomp.dev y decomp.me, el
  repositorio «PS2 games with symbols» o tablas en GitHub, los proyectos
  de Sly Cooper, Jak & Daxter, Kingdom Hearts y Ratchet, PCSX2 forums y
  psx-place;
- **demos y discos de revista japoneses** (Taikenban, «体験版»,
  Dengeki PlayStation D, «PlayStation Magazine» de Japón, discos
  PAPX/PCPX/PBPX): suelen llevar builds más tempranas sin quitar los
  símbolos;
- versiones de otras regiones (Asia SCAJ, Corea SCKA, Europa) y
  reediciones (PlayStation 2 the Best, Mega Hits) del mismo juego, que a
  veces se compilaban distinto;
- versiones de PSP de las mismas sagas: si alguna usa RX y salió con
  símbolos, también puede servir.

**Señales de que un ejecutable tiene símbolos:** secciones `.symtab`,
`.strtab`, `.debug`, `.line`, `.mdebug`, `.mwcats`; ficheros `.map`,
`.sym` o `*.elf` grandes de más (más de 8 MB) en el disco; nombres de
función visibles en un editor hexadecimal.

### Formato de la respuesta

1. **Tabla principal**, ordenada de más a menos prometedor:

   | Juego | Región / ID de disco (SLPS, SCPS, PAPX, PCPX, SCUS…) | Año | Desarrollador | ¿Usa RX? (confirmado / probable, con prueba) | ¿Tiene símbolos? (confirmado / rumor / desconocido, con prueba) | Qué versión exacta (retail, demo, prototipo, the Best) | Fuente(s) (enlace) |

2. **Lista de demos japoneses de SCEJ** de 2003 a 2007 (Taikenban y
   discos de revista) que contengan alguno de esos juegos, con su ID.
3. **Prototipos conocidos** de juegos de SCEJ en Hidden Palace u otros
   archivos, y qué se sabe de sus ejecutables.
4. **Callejones sin salida:** lo que investigaste y no sirvió, para no
   repetirlo.
5. **Mis siguientes pasos,** ordenados: qué disco conseguir primero y
   qué archivo mirar dentro.

### Límites

- No me des enlaces a descargas de ISOs ni de ROMs. Solo información:
  qué existe, qué contiene y dónde está documentado. Yo compro o
  consigo los discos de forma legal.
- No inventes IDs de disco ni contenidos de ejecutables. Si no está
  confirmado, márcalo como «sin confirmar».
- Si encuentras otro nombre para la librería (por ejemplo en los
  créditos japoneses), dímelo y búscalo también.

---

## Para el coordinador, al recibir el resultado

- Por cada disco nuevo que el dueño consiga: extraer el ELF a
  `disc/<id>/` (git-ignored); comprobar `$RX_SCE_LIBRARY_VERSION` y
  `.symtab`; si tiene símbolos, añadir una entrada a `DONORS` en
  `tools/donor_symbols.py` (sha256 del ELF, sección de código y de
  reubicaciones) y regenerar con `tools/ror_symbols.py`.
- Las versiones de la librería distintas de 4 pueden tener funciones
  cambiadas. El enmascarado por reubicaciones lo detecta: solo se
  aceptan los cuerpos idénticos.
