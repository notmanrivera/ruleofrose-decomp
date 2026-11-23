# Rule of Rose — investigación externa profunda: alineación, registros y permutadores C++

**Fecha:** 23 de noviembre de 2026  
**Destinatario:** Claude / Orca, coordinador del proyecto `ruleofrose-decomp`  
**Base solicitada:** `INVESTIGACION_EXTERNA_rule_of_rose_2026-11-23(1).md`  
**Objetivo:** responder con evidencia primaria y experimentos reproducibles, sin modificar el repositorio.

> **Entorno del juego (información del encargo):** PS2 NTSC-U `SLUS-214.48`; C++ compilado con Sony/Cygnus `ee-gcc 2.96`, `-Os -G0 -fno-exceptions -fno-strict-aliasing`, ensamblador SCE `as 2.10`. Progreso comunicado: 39 % del código del juego.
>
> **Límite metodológico:** en esta investigación se inspeccionaron código fuente público de EE-GCC 2.9, documentación y repositorios, y los scripts de Rule of Rose facilitados previamente. **No se ejecutó el compilador SCE 2.96 real ni se inspeccionaron aquí sus objetos `.o` o el ejecutable del juego.** Las reglas procedentes de EE-GCC 2.9 son referencias de familia, **no una reconstrucción confirmada del binario 2.96**.

## Resumen ejecutivo

1. **[Confirmado — código Sony/Cygnus 2.9]** `config/mips/elf5900.h` redefine `BIGGEST_ALIGNMENT` a **128 bits cuando `TARGET_MIPS5900` es verdadero**. Esta es la mejor evidencia localizada del motivo por el que el backend admite alineaciones de 16 bytes; **no** significa que los literales de 16 bytes se alineen necesariamente a 16. Véase [S1].
2. **[Confirmado — código Sony/Cygnus 2.9]** `CONSTANT_ALIGNMENT` aplica un **mínimo de `BITS_PER_WORD`** a `STRING_CST` y `CONSTRUCTOR`, y `DATA_ALIGNMENT` lo aplica a arrays, uniones y estructuras cuando su alineación de partida es menor. El mínimo depende de `TARGET_64BIT` y puede ser 32 o 64 bits en el código inspeccionado. No se halló una regla en esas macros que convierta *longitud de cadena = 16* en *alineación = 16*. Véase [S2].
3. **[Confirmado — código de asignador]** `local-alloc.c` intenta **preferencias por copias hacia registros físicos antes de aplicar otras prioridades** y distingue entre pseudorregistros de un solo bloque, cruces de llamadas y registros preservados. Su función de prioridad incorpora referencias, tamaño y duración de vida. **Existen comprobaciones `!optimize_size` en el flujo**, específicamente relevantes para `-Os`. Véase [S3].
4. **[Confirmado — fuentes de Rule of Rose facilitadas]** `regalloc.py` ya recopila `.lreg` y `.greg`, pero su puntuación no puede explicar por sí sola las preferencias por copias, clases, cruces de llamada ni la fase `reload`. El mayor rendimiento estaría en **comparar volcados de dos variantes y sus movimientos**, no añadir permutaciones ciegas.
5. **[Confirmado — documentación de software]** el permutador de Simon Lindholm permite variantes dirigidas con `PERM_GENERAL`, `PERM_VAR`, `PERM_LINESWAP`, `PERM_RANDOMIZE` y pesos por perfil `gcc`; **las macros multialternativa desactivan la aleatorización automática si no se añade `PERM_RANDOMIZE`**. Véanse [S8]–[S9].
6. **[Confirmado — existencia y características, no soporte PS2]** [`cpp_permuter`](https://github.com/CriminalRETeam/cpp_permuter) sí reconoce **C++/métodos**, acepta comandos de compilación y puntuación externos, símbolos de destino y pruebas aisladas sin modificar archivos. Fue probado principalmente con **MSVC 6 / GTA2 y Clang**, no con el EE-GCC 2.96 de Sony; por tanto, requiere un piloto antes de sustituir la transformación C++→C que usa Orca. Véase [S10].

---

# 1. Reglas de alineación `.rodata` en la familia EE-GCC

## 1.1. Evidencia primaria localizada

### 1.1.1. `elf5900.h`: 128 bits de alineación máxima

**Fuente primaria:** [S1], `ee/gcc/config/mips/elf5900.h`, archivo Sony/Cygnus EE-GCC **2.9-ee**:

```c
/* We must override BIGGEST_ALIGNMENT since we support TImode loads/stores
   which must be properly aligned. */
#undef BIGGEST_ALIGNMENT
#define BIGGEST_ALIGNMENT (TARGET_MIPS5900 ? 128 : 64)
```

**Interpretación correcta:**

- `BIGGEST_ALIGNMENT` es una **cota/alineación natural máxima del backend** para tipos y modos compatibles, **no** una instrucción para alinear todos los símbolos a 16 bytes.
- `TARGET_MIPS5900` selecciona 128 bits; de otro modo quedan 64 bits.
- El archivo también redefine la alineación de pila (`STACK_BOUNDARY` y `MIPS_STACK_ALIGN`) para permitir cargas/escrituras de 128 bits. **Alineación de pila y alineación de `.rodata` son fenómenos diferentes.**
- Las macros `ASM_OUTPUT_ALIGNED_COMMON` y `ASM_OUTPUT_ALIGNED_LOCAL` del mismo archivo tratan **COMMON / BSS**, por lo que no demuestran directamente la disposición de cadenas en `.rodata`.
- **Estado para EE-GCC 2.96 exacto: probable continuidad, no confirmado por el código fuente del 2.96.**

### 1.1.2. `mips.h`: constantes, arrays y tamaño de palabra

**Fuente primaria:** [S2], `ee/gcc/config/mips/mips.h` del mismo compilador 2.9:

```c
#define BITS_PER_WORD (TARGET_64BIT ? 64 : 32)

#define CONSTANT_ALIGNMENT(EXP, ALIGN)                          \
  ((TREE_CODE (EXP) == STRING_CST || TREE_CODE (EXP) == CONSTRUCTOR) \
   && (ALIGN) < BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))

#define DATA_ALIGNMENT(TYPE, ALIGN)                             \
  (((ALIGN) < BITS_PER_WORD &&                                 \
    (TREE_CODE (TYPE) == ARRAY_TYPE ||                         \
     TREE_CODE (TYPE) == UNION_TYPE ||                         \
     TREE_CODE (TYPE) == RECORD_TYPE))                         \
    ? BITS_PER_WORD : (ALIGN))
```

*Transcripción normalizada del formato de los `#define` (mismo comportamiento lógico; consultar [S2] para el texto fuente).* 

**Consecuencias:**

| Categoría | Evidencia en 2.9 | Lo que NO demuestra |
|---|---|---|
| Literal `"texto"` (`STRING_CST`) | Mínimo de `BITS_PER_WORD` si la alineación original es inferior | No asocia el número de caracteres con 8/16 bytes |
| `const char a[] = "texto"` (`ARRAY_TYPE`) | Un objeto estático de tipo array puede recibir mínimo `BITS_PER_WORD` vía `DATA_ALIGNMENT` | No garantiza idéntico tratamiento al literal anónimo |
| Estructura/unión estática | Mínimo de `BITS_PER_WORD` si originalmente menor | No determina si los campos individuales tienen 16 bytes de alineación |
| Entero escalar / `float` | Las macros citadas no elevan automáticamente todos los escalares por tipo array/string | No explican por sí solas constantes agregadas, pools ni tablas del compilador |
| Tabla de saltos | No está regida por la categoría `STRING_CST` por el mero hecho de acabar en `.rodata` | No demuestra alineación 16 para todos los `switch` |

**Muy importante:** `BITS_PER_WORD` depende de `TARGET_64BIT`. La presencia de punteros de 32 bits en R5900 **no implica automáticamente** `BITS_PER_WORD = 32`; el código especifica configuraciones distintas. Medir la configuración efectiva del `ee-cc` de RoR antes de fijar el mínimo esperado.

### 1.1.3. `LOCAL_ALIGNMENT` y `MAX_OFILE_ALIGNMENT`

**Estado: no confirmado para la compilación exacta.** En el `mips.h` Sony 2.9 inspeccionado no localizamos estas definiciones como evidencia de la regla de 16 bytes. `LOCAL_ALIGNMENT`, si aparece en otros encabezados, concierne típicamente a la alineación de variables locales (su aplicación a `.rodata` no debe presuponerse). `MAX_OFILE_ALIGNMENT` es una cota que puede afectar el formato de objeto, no una política universal que alinee cada cadena.

**Acción exacta:** pedir a Orca que inspeccione el árbol completo de encabezados e inclusiones efectivos de su compilador para esas macros; `mips.h` puede ser sobreescrito por `elf5900.h`, otro subtarget o un header genérico. Registrar definición efectiva, no solo coincidencias de `grep` en un archivo.

### 1.1.4. Código emisor y ensamblador

Los nombres de macros son solo parte de la respuesta. El recorrido lógico que necesitamos reconstruir es:

```text
C++ (tipo, inicializador y contexto)
  -> front-end crea decl/STRING_CST/CONSTRUCTOR
  -> alineación del tipo/declaración
  -> DATA_ALIGNMENT / CONSTANT_ALIGNMENT (si se usan)
  -> varasm.c / salida de pool / ASM_OUTPUT_ALIGN
  -> directiva .align y orden de labels en .s
  -> as 2.10 asigna sh_addralign/offset dentro de .o
  -> linker dispone las contribuciones de .rodata
  -> dirección final en ELF
```

En GNU as para MIPS, `.align n` suele significar alinear a **2^n bytes**. Por tanto, un `.align 4` antecediendo al símbolo indica 16 bytes. **No interpretar `.align 4` como 4 bytes**. Comprobar también si el ensamblador usa otra directiva o `.p2align`; las secciones y símbolos ELF dan evidencia adicional.

El código histórico de `varasm.c` distingue emisión de declaraciones y constantes; versiones históricas muestran tanto `CONSTANT_ALIGNMENT` como `ASM_OUTPUT_ALIGN`, pero **no hemos verificado su copia exacta dentro de Sony 2.96**. Referencias de GCC histórico [S4].

## 1.2. ¿Por qué puede parecer que una cadena de 16 bytes se alinea a 16?

El texto `"game/gamsnd.cpp"` tiene **15 caracteres más NUL = 16 bytes**. Ver que comienza en dirección múltiplo de 16 **no prueba** que se pidió una alineación de 16.

Cuatro explicaciones alternativas que deben distinguirse:

1. **Alineación solicitada**: la salida `.s` contiene una `.align 4` o equivalente antes del label de la cadena.
2. **Alineación heredada**: la sección o el dato anterior empieza alineado y su tamaño conduce fortuitamente a un múltiplo de 16, aunque el símbolo solo requiera 4 u 8.
3. **Padding impuesto por el ensamblador/enlazador**: la subsección empieza en una frontera superior a la exigida por el símbolo.
4. **Reordenación/pooling de constantes**: el compilador emitió primero otro dato, fusionó cadenas o separó la contribución; el orden visible no sigue el de su primer uso en C++.

**La regla exacta exigida en el encargo sigue sin estar demostrada para ese literal concreto.** Lo reproducible es la medición de la directiva y del objeto, no inferir por longitud.

## 1.3. Ensayo factorial mínimo — exclusivamente `-Os`

Generar una **matriz de compilaciones independientes** (una TU por caso para evitar interacciones), conservando las flags reales. Los siguientes tamaños son LONGITUD EN BYTES INCLUIDO NUL:

- Cadena de 7, 8, 9, 15, **16**, 17, 31, 32 y 33 bytes.
- Cada tamaño en: `(a)` literal anónimo usado desde función, `(b)` `static const char[]`, `(c)` `const char[]` global, `(d)` duplicado exactamente dos veces.
- Arrays nombrados: `unsigned int [1,2,3,4,5,8]`, `float[2,4]`, `unsigned long long[1,2]`, `u_long128` según disponibilidad real en los headers.
- Tabla `switch`: variantes con casos densos y dispersos (para verificar **si el compilador realmente elige una tabla**).
- Sin atributos en la línea base; segundo barrido controlado con `__attribute__((aligned(8)))` y `aligned(16)` solo como **sondas**, no como solución definitiva.

Ejemplo esquemático de sondas **separadas en archivos**:

```cpp
// probe_literal.cpp — evitar que se elimine la referencia
const char * volatile sink;
void probe_literal() {
    sink = "game/gamsnd.cpp";
}

// probe_array.cpp
const char named_string[] = "game/gamsnd.cpp";
const char * volatile sink;
void probe_array() {
    sink = named_string;
}

// probe_table.cpp
const unsigned int named_table[] = {1u, 3u, 5u, 7u};
const unsigned int * volatile sink;
void probe_table() {
    sink = named_table;
}
```

**IMPORTANTE:** si se añade `extern "C"` o se cambian los prototipos, registrar esa diferencia; los nombres finales afectan la lectura de etiquetas pero no deben confundirse con la alineación.

Desde un checkout con el entorno del proyecto preparado, pedir a Orca adaptar y ejecutar para **una única TU**:

```sh
# Ejemplo del esquema usado en los scripts subidos: comprobar flags y rutas reales.
# Ejecutar dentro del contenedor ror-build, desde el directorio adecuado.
ee-cc ee-gcc2.96 -Os -G0 -fno-exceptions -fno-strict-aliasing \
  -x c++ -S probe_literal.cpp -o probe_literal.s

ee-cc ee-gcc2.96 -Os -G0 -fno-exceptions -fno-strict-aliasing \
  -x c++ -c probe_literal.cpp -o probe_literal.o
```

En el archivo `.s`, registrar el `.align` que **precede al label correcto**, no el de la sección al comienzo. En el objeto registrar `section`, `sh_addralign`, `symbol.st_value` y **padding medido** mediante `readelf -SW`, `readelf -sW`, `objdump -sr`, usando las versiones MIPS instaladas. **Un `st_value` múltiplo de 16 es compatible con alineación requerida de 4, 8 o 16: no basta.**

**CSV recomendado:** `case,compiler_id,flags,source_form,object_length,type,section,align_directive,align_bytes,sh_addralign,symbol_offset,previous_symbol_end,padding,notes`.

### Matriz de interpretación

| Observación | Conclusión admitida |
|---|---|
| `.align 4` previo al label en `.s` | Se solicitó 16 bytes en esa compilación concreta |
| `.align 3` previo al label | Se solicitó 8 bytes |
| Dirección final múltiplo de 16, sin `.align 4` | **No** prueba alineación de 16 |
| `sh_addralign = 16` | La **sección** requiere 16; no prueba que cada símbolo la requiera |
| `-Os` con y sin `-fmerge-constants` produce distinta sección | Cambio del **modo de emisión**; medir antes de atribuirlo a macro específica |
| Un switch usa cadena de branches, no jump table | Caso no apto para medir reglas de tablas |

**Evidencia final necesaria:** una tabla que relacione cada forma de C++ con directiva generada en el **ee-gcc 2.96 real**. Solo entonces proponer automatizar alineaciones en `configure.py` o introducir `aligned` en el código del juego.

---

# 2. Reparto de registros `$v1`, `$a0`, `$s*` en GCC 2.9x

## 2.1. Lo que hace el asignador histórico (primarias)

### 2.1.1. Local: cantidades, sugerencias y rangos de vida

En `local-alloc.c` 2.9 [S3] las asignaciones se realizan en dos etapas: primero se tratan valores que nacen y mueren en un bloque; el resto queda para `global_alloc`. No se trabaja únicamente con variables del programa, sino con **pseudorregistros RTL** y agrupaciones llamadas *quantities*. Se pueden agrupar registros por copias y operaciones para reducir movimientos.

La prioridad básica que se ve en el código es:

```c
#define QTY_CMP_PRI(q) \
 ((int) (((double) (floor_log2 (qty_n_refs[q]) * qty_n_refs[q] * qty_size[q]) \
          / (qty_death[q] - qty_birth[q])) * 10000))
```

**Esto es un comparador de cantidades locales**, no una función que devuelva «el registro exacto» y no necesariamente equivale a la fórmula de `global.c` ni del compilador 2.96. Además, `qty_phys_copy_sugg` y `qty_phys_sugg` se priorizan antes y afectan el orden. Véase [S3].

`find_free_reg` descarta, entre otros, registros no permitidos para el modo, ocupados en el intervalo, restringidos por clase y aquellos que se destruyen en llamadas cuando el valor sigue vivo. Cuando un valor cruza una llamada (`qty_n_calls_crossed > 0`), usa como exclusión el conjunto de registros *call-used* salvo que convenga guardar/restaurar, condicionado por `flag_caller_saves`. La preferencia numérica de `REG_ALLOC_ORDER` solo actúa **entre registros elegibles y libres**.

### 2.1.2. Orden físico MIPS

`config/mips/mips.h` Sony 2.9 [S2] contiene:

```c
#define REG_ALLOC_ORDER { 0, 1, 2, 3, 4, 5, /* ... */ }
#define ORDER_REGS_FOR_LOCAL_ALLOC mips_order_regs_for_local_alloc()
```

El orden base es **numérico**; la función dinámica fue concebida principalmente para MIPS16. Los registros no disponibles (`$zero`, `$at` según usos, `$sp`, etc.) no son opciones arbitrarias para cualquier valor; su elegibilidad se filtra.

Ejemplos de interpretación a verificar con los dumps de RoR:

- Dejar un índice vivo **antes y después** de un `jal` reduce las posibilidades de asignarlo a `$a0`, `$v1` si esos registros no se preservan en una llamada; podría favorecer `$s*` o generar spill/save.
- Acortar el intervalo de un temporal para que no cruce la llamada puede hacer que aparezca en un registro temporal o argumento.
- Reescribir una expresión para que el resultado se utilice directamente como argumento puede generar una **preferencia por copia/coalescing a `$a0`**; no es una garantía.
- Un resultado de llamada suele llegar por el ABI en `$v0`/`$v1`; mantenerlo en el pseudo inicial, copiarlo o extender su vida puede alterar su asignación final.
- Los temporales en FPU deben analizarse en su propia clase de registros y con sus restricciones; no extrapolar las reglas GPR sin comprobación.

### 2.1.3. Diferencia real de `-Os`

En la fuente 2.9 de `local-alloc.c` hay ramas condicionadas por **`!optimize_size`**, que **evitan ciertas estrategias de extensión de vida/evitación de dependencias falsas cuando se optimiza por tamaño**. Esto demuestra que las decisiones internas pueden variar entre `-Os` y otros modos, incluso antes de llegar al scheduling final. [S3].

**Nivel:** comprobado para la fuente Sony 2.9; el efecto exacto para Sony 2.96 requiere medir `.lreg/.greg` y, si fuera accesible, volcados de `reload` del compilador del juego.

### 2.1.4. Global y `reload`

En la familia GCC 2.x, `global.c` opera sobre los pseudo-registros no resueltos localmente, preferencias, costos y **conflictos entre intervalos**. El algoritmo de `global.c` consulta referencias, frecuencias, tamaños y duración; otras variantes del mismo linaje no tienen necesariamente idéntica fórmula de prioridad. Véase [S5].

`reload` puede introducir instrucciones, sustituir registros, mover valores y hacer *spill* bajo restricciones de operandos. Por tanto, **un registro final visto en `objdump` no equivale necesariamente a la elección directa de `local-alloc`**.

## 2.2. Cómo leerlo para Rule of Rose sin ensayo ciego

La herramienta ya disponible `tools/regalloc.py` (script proporcionado) compila mediante `match.compile_file`, pide `-dlg`, lee `*.lreg` y `*.greg` y muestra: pseudo, registro, referencias, *live length*, prioridad aproximada, pertenencia a bloque y etiquetas.

**No hay que reinventar esa funcionalidad.** Su limitación principal es que ordena por una fórmula **unidimensional**. La fuente histórica confirma que su métrica es útil para diagnosticar pero no puede explicar la preferencia por hard-reg copies ni los conflictos de clase.

**Ampliación recomendada — `regalloc.py --compare` (diseño, no implementado):**

```text
func: func_XXXXXXXX
baseline (hash source)                variant A (hash source)
  pseudo 83 -> $v0                      pseudo 83 -> $a0
  refs 3, live 12                      refs 3, live 6
  crosses 1 call                       crosses 0 calls
  suggested hard regs: unknown         suggested hard regs: unknown
  stage: local/global/reload: ?         stage: local/global/reload: ?
  asm: 2 register differences          asm: 0 register differences
  rodata/relocs: unchanged             rodata/relocs: unchanged
```

**Los campos `suggested hard regs` y `stage` son objetivos de instrumentación**: el script actual no los extrae. Si el volcado no los contiene, usar `unknown`, no inventarlos.

Plan por etapas:

1. **Baseline inmutable**: archivo C++ completo y hash, identidad de `ee-cc`, flags, `-DNON_MATCHING` si aplica.
2. **Volcados por intento**: no reutilizar `build/match/dumps/<file>` entre agentes (el script actual borra ese directorio al iniciar); usar directorios con hash/worker/función, y resolver de forma inequívoca funciones C++ homónimas o sobrecargadas.
3. **Mapa pre y post**: obtener el pseudo y asignación desde `.lreg`, `.greg`; comparar el ensamblador final y, solo si el compilador lo soporta, dumps adicionales de `reload` y/o regmove. Registrar si los dumps no se emiten.
4. **Una dimensión por variante**: (i) duración por inicialización retrasada, (ii) vida cruzando llamada, (iii) copia directa a argumento, (iv) reutilizar temporal, (v) expresión equivalente con cast correcto. Mantener idéntica semántica.
5. **Aceptar por verificador**: no solo reducir diferencias; validar instrucciones, relocaciones, `.rodata`, archivo objeto y build final según etapa.

## 2.3. Variantes C++ controladas — no recetas infalibles

### A. Cambiar duración sin alterar significado

```cpp
// A: el resultado se calcula antes de una llamada
int limit = getLimit();
logEvent();
if (i < limit) doWork(i);

// B: solo es equivalente si getLimit() es puro/estable
logEvent();
int limit = getLimit();
if (i < limit) doWork(i);
```

**No permutar** si `getLimit()` lee estado que `logEvent()` modifica. Cuando esa independencia no esté probada, usar un ejemplo diferente con expresión pura (p. ej., `int limit = end - 1;` donde `end` es local inmutable).

### B. Variable intermedia frente a expresión directa

```cpp
// A
if (index < (end - 1)) use(index);

// B
const int limit = end - 1;
if (index < limit) use(index);
```

Las dos versiones pueden producir diferentes pseudo-registros, preferencias o rangos de vida. El compilador puede optimizarlas de modo idéntico; medir.

### C. Alcance distinto

```cpp
// A
int value = count - 1;
if (ready) use(value);

// B
if (ready) {
    int value = count - 1;
    use(value);
}
```

La equivalencia exige que evaluar la expresión `count - 1` fuera del bloque no tenga comportamiento excepcional/observable y que no haya efectos laterales. En aritmética con `int` y límites extremos, evaluar operaciones fuera del bloque puede introducir **UB de overflow**, así que preferir aritmética cuya seguridad esté verificada.

### D. Preparación de argumentos

```cpp
// A
send(x + 1, y);

// B
int first = x + 1;
send(first, y);
```

El efecto posible es sobre cómo el compilador enlaza el pseudo con los registros físicos de argumento (`$a0`, `$a1`). No cambiar el orden de argumentos ni de llamadas con efectos secundarios.

### E. Orden de declaraciones

```cpp
int a;
int b;
```

Comparar con `int b; int a;` solo cuando las variables no cambien de ámbito ni introduzcan una inicialización observable. **Es un ensayo de baja prioridad si los dumps muestran que la presión real proviene de cruces de llamadas o preferencias por copias.**

## 2.4. Tabla de decisiones para Orca

| Síntoma de diff | Primera observación | Variantes que merece ensayar | Qué evitar |
|---|---|---|---|
| `$v1` vs `$a0` | ¿La variable termina en llamada/argumento? ¿Cruza `jal`? | Temporal cerca del uso; copia explícita; aridad/retorno correcto | Forzar registro sin análisis del ABI |
| `$s0` vs `$s1` | ¿Dos intervalos largos se solapan? | Acortar uno; cambiar creación/reutilización del temporal | Asumir que intercambiar declaraciones siempre basta |
| `$f2` vs `$f4` | Clase FP, tipos exactos y `float`/`double` | Duración de temporales FP; orden de evaluación sin cambiar resultados | Casts que cambien redondeo |
| `sw` en otro orden | ¿Independencia por alias demostrada? | Cambiar orden solo si independientes; localizar dependencias | Reordenar escrituras con `volatile` o alias potencial |
| Variación cerca de `jal` | `ASM_NOTHROW` y prototipos, live ranges | Verificar firma del callee y prototipo correcto | Atribuir todo al orden de declaraciones |

**Referente externo:** GT4 documenta técnicas parecidas de alcance, uso de variables, inicializaciones y argumentos con el mismo linaje EE-GCC 2.96 pero principalmente otro perfil de optimización: usarlo como **generador de hipótesis**, no como demostración directa para RoR `-Os`. [S6].

---

# 3. decomp-permuter: búsquedas guiadas y alternativa C++

## 3.1. Macros oficiales y un detalle que ahorra muchas compilaciones

El permutador original de Simon Lindholm [S8] documenta:

| Macro | Función | Uso aconsejado |
|---|---|---|
| `PERM_GENERAL(a, b, ...)` | Probar alternativas explícitas | 2–4 formas para una hipótesis conocida |
| `PERM_VAR(name, expr)` | Fijar/referenciar meta-variable en varias posiciones | Consistencia de elección entre fragmentos |
| `PERM_LINESWAP(...)` | Permutar líneas con sentencias completas | Stores declaradamente independientes |
| `PERM_INT(lo, hi)` | Seleccionar literal en un intervalo | Cuando existen evidencias de valor correcto |
| `PERM_ONCE(key, code)` | Colocar el fragmento una sola vez | Cambiar posición de declaración/acción |
| `PERM_RANDOMIZE(code)` | Habilitar randomización en región | Combinación de alternativas dirigidas + pases aleatorios |
| `PERM_IGNORE(code)` | Saltar parser C para ese fragmento | Extensiones C/C++, uso conservador |
| `PERM_PRETEND(code)` | Ofrecer estructura ficticia al parser y quitarla al final | Puentes de sintaxis compleja, comprobación obligatoria |

**Advertencia oficial decisiva:** al introducir cualquier macro con múltiples alternativas, el permutador **deja de randomizar automáticamente**; hay que añadir `PERM_RANDOMIZE` para combinar ambos comportamientos. Sin esta advertencia, Orca podría malinterpretar un barrido agotado como prueba de que no hay solución. [S8].

Ejemplo dirigido compatible con sintaxis de la herramienta:

```c
int y = PERM_GENERAL(x + 1, 1 + x);
```

Ejemplo sobre orden **solo si no hay alias ni efecto lateral**:

```c
PERM_LINESWAP(
    a = 3;
    b = 5;
)
```

No se recomienda permutar `f() && g()` o reordenar escrituras a objetos con alias potencial: las mutaciones pueden cambiar la semántica del port aunque el score del objeto mejore.

## 3.2. Pesos existentes: no necesitamos inventar un motor nuevo

En el repositorio original [S9] hay un `default_weights.toml` de **dos capas**:

- `[base]`: valores genéricos (`perm_temp_for_expr = 100`, `perm_expand_expr = 20`, `perm_reorder_stmts = 10`, `perm_reorder_decls = 10` y otros).
- `[gcc]`: ajustes por familia, como `perm_alias_array = 3` y descuentos a `perm_add_mask`, `perm_xor_zero`, `perm_float_literal`, `perm_sameline`, `perm_condition`, entre otros.

El README oficial permite sobrescribir pesos desde `settings.toml` del intento. **La sintaxis exacta de la sobreescritura debe comprobarse con la versión descargada en `build/decomp-permuter`; no asumir que una nueva tabla propia será interpretada idénticamente por todas las revisiones.**

En el proyecto RoR, `perm_official.py` ya genera:

```toml
func_name = "func_XXXXXXXX"
compiler_type = "gcc"
```

Esto implica que **ya usa el perfil GCC**, pero no pesos específicos de síntomas (`REG_ONLY`, `SCHEDULE_ONLY`, `BRANCH_LIKELY`).

### Experimento A/B para pesos — diseño

Seleccionar 3 muestras por clase:

1. Solo registros: favorecer temporales/redeclaraciones de variables; bajar mutaciones de aritmética innecesarias.
2. Solo orden de `sw`/`swc1`: favorecer reordenación cuando se haya demostrado independencia, no cambios de tipo.
3. Saltos/delay slots: 2–4 alternativas explícitas de flujo C++ comprobado, con `PERM_GENERAL` en lugar de aleatorizar toda la función.

A/B con misma base, semillas, presupuesto fijo de **compilaciones** (no solo minutos) y score registrado por `match.py`; medir tiempo, mejores ediciones y porcentaje que mejora objeto completo. **No copiar números de pesos de otros compiladores como si fueran óptimos para `-Os`.**

### Precaución concreta con `perm_official.py`

El script adjunto convierte C++ a C mediante `plain_c` y filtrado de declaraciones; la auditoría anterior demostró que cambia palabras como `bool`, `true`, `false` incluso dentro de literales. Eso puede alterar el problema antes de llegar al permutador. También transforma ciertos prototipos y recompila el resultado como C++.

**Mejorar antes de masificar:**

- Excluir comentarios/cadenas de las transformaciones mediante tokenizador C/C++.
- Confirmar que el C++ de prueba recompilado con `base.c` conserva la **firma, el cuerpo y todos los literales relevantes** del original; no basta con «compila».
- Mantener todo en un worktree y rutas temporales únicas por agente, sin usar directorios globales `/tmp/t` o `/tmp/p` para dos trabajos simultáneos.
- No publicar un score 0 como matching final: revalidar TU completa y SHA-1 de build final por coordinador, como ya hacen parcialmente las herramientas del proyecto.

## 3.3. `cpp_permuter`: la opción nueva merece un piloto real

**Código:** [S10] `https://github.com/CriminalRETeam/cpp_permuter`.

**Capacidades comprobadas documentalmente:**

- Trabaja sobre **archivos `.cpp` y métodos como `Class::method`**, conservando su contexto C++.
- `-c '... {src} {obj}'` permite acoplar un **compilador externo**.
- `--score-cmd` acepta un evaluador externo que imprima un número final (0 para coincidencia en ese scorer).
- `--symbol` y `--target-symbol` permiten expresar nombres de símbolos diferentes del demangling supuesto.
- `--dry-run`, `--show-ast`, `--base-only`, `--check-parse`, `--resume`, `-p` y `--weight` facilitan un piloto controlado.
- Su copia/mirror del árbol de trabajo evita modificar los archivos del repositorio.
- Puede intentar cambios de `sink_decl`, `hoist_decl`, `reorder_saves`, `inline_local`, `move_stmt`, etc., relevantes para nuestros casos de registros y orden.

**Límites fundamentales:** sus pruebas públicas son para **MSVC 6 y Clang en x86**, no para EE-GCC 2.96 ni para ISA R5900. La coincidencia de interfaz externa no garantiza que su parser acepte extensiones usadas por Sony o que su scorer nativo reconozca las instrucciones/relocaciones de PS2. **No se ha probado integración local.**

### Protocolo de piloto C++ (sin sustituir al sistema actual)

1. Clonar o descargar `cpp_permuter` en carpeta de herramientas **externa o ignorada por Git**. Registrar commit/revisión y licencia.
2. Ejecutar `--check-parse` sobre tres funciones de RoR: una libre simple, una con método de clase y una con `asm("mangled")`/extensiones; anotar si parsea y qué pasa con el cuerpo.
3. Usar `--dry-run` con `-p sink_decl,hoist_decl` para inspeccionar que **no cambia semántica**. Descartar mutaciones que toquen alias/calls de forma insegura.
4. Implementar wrapper `-c` que reproduzca **la misma ruta, `__FILE__`, flags, include dirs y compilador SCE**, como `match.compile_file`; escribir un objeto nuevo por candidato.
5. Implementar wrapper `--score-cmd` cuyo resultado proceda del **juez de matching completo** (`match.py`), no de un diff genérico de MSVC. Debe verificar al menos tamaño/instrucciones/relocaciones y, cuando proceda, secciones `.rodata`; salida termina en número.
6. Confirmar baseline con puntuación igual a la del `work.py` del mismo C++ antes de lanzar permutaciones. Si diverge, la integración no sirve aún.
7. Limitar búsqueda a 100–300 compilaciones por función y comparar `matches / número de compilaciones / tiempo` frente a `perm_official.py`.
8. Admitir cualquier victoria solo por `work.py --done` y build SHA-1 completo; sin commits automáticos durante el piloto.

**Punto clave:** las transformaciones C++ podrían evitar la distorsión que supone el puente C++→C. Si el parseo falla para clases/atributos SCE, el proyecto actual sigue siendo la opción principal.

---

# 4. Prioridades concretas para Orca

| Orden | Experimento | Prueba objetiva para darlo por terminado | Costo/Riesgo |
|---|---|---|---|
| **1** | Matriz de `.rodata` con 2.96 real y `-Os` | Tabla de directivas `.align` por forma/tamaño + secciones/símbolos | Bajo/medio; sin tocar build |
| **2** | `regalloc.py --compare` sobre 3 near-misses | Dos volcados, causa observable (vida/copia/call) y diff matching | Medio; alto valor |
| **3** | Búsquedas `PERM_GENERAL` sobre 3 funciones casi matching | Mejora real del objeto comparada con permutación aleatoria | Bajo |
| **4** | Pesos `gcc` dirigidos por clase de síntoma | Menos compilaciones para igual o mejor resultado | Medio |
| **5** | Piloto `cpp_permuter` C++ | 3 parseos + compilación idéntica baseline + puntuación confiable | Medio/alto; aislado |
| **6** | Integración en el orquestador | Registro fuente/hash/flags/dumps/relocs/resultado por experimento | Medio; después de validar |

## Reglas de aceptación

- No modificar `configure.py` para alinear cadenas usando solo su longitud.
- No adoptar «primera variable -> primer registro» como regla.
- No usar `-O2` para definir la solución a una función confirmada con `-Os`.
- No aceptar 0 del permutador sin comprobación en el sistema matching real.
- No ejecutar experimentos escribiendo en `src/` compartido; usar copias inmutables y worktrees.
- No atribuir a Sony EE-GCC 2.96 comportamientos que solo se han demostrado para EE-GCC 2.9.
- No tratar un source `C++` transformado a `C` como equivalente si hay diferencias en firmas, aliasing, clases, bool o literales.

---

# 5. Datos que faltan para cerrar la investigación (y cómo obtenerlos)

| Duda abierta | Evidencia mínima | Fuente efectiva |
|---|---|---|
| ¿Regla exacta de string de 16 bytes? | `.s` con `.align` junto al label + `.o` de prueba | EE-GCC 2.96 real, `-Os` |
| ¿Cuándo va tabla de enteros a 8? | Comparar `ARRAY_TYPE`, tamaño y declaración, sección/offset | Matriz de TUs |
| ¿Qué impone 16 a jump tables? | `switch` compilado que realmente genere tabla + `.align` | `.s` generado |
| ¿Qué definición final tienen `LOCAL_ALIGNMENT`/`MAX_OFILE_ALIGNMENT`? | Preprocesador de headers del toolchain exacto o fuentes 2.96 | Archivo fuente exacto aún no hallado |
| ¿Por qué un pseudo recibe `$v1` en vez de `$a0`? | `.lreg/.greg`, preferencia copia, llamadas, `.s` final | EE-GCC 2.96, `regalloc.py` ampliado |
| ¿`cpp_permuter` puede compilar un método RoR sin cambiar el contexto? | Baseline idéntico, parser acepta extensiones, score consistente | Piloto en worktree |

**Respuesta a la pregunta «¿ya tenemos la regla exacta para predecir cada alineación sin probar?»**: **no**. Tenemos evidencias primarias del mecanismo general, incluido el override R5900 de 128 bits, pero faltan los `varasm`/backend del 2.96 exacto o, más inmediatamente, la matriz empírica con el propio compilador que utiliza el proyecto. Pretender que `BIGGEST_ALIGNMENT=128` implica `len=16 => align=16` sería incorrecto.

---

# 6. Fuentes con nivel de fiabilidad

**[S1] Primaria — [confirmado, compilador Sony/Cygnus EE-GCC 2.9, NO 2.96]**  
[`elf5900.h`: `BIGGEST_ALIGNMENT`, `STACK_BOUNDARY`, COMMON/BSS](https://github.com/SSXModding/ps2-ee-toolchain/blob/master/ee/gcc/config/mips/elf5900.h). Buscar en el archivo `BIGGEST_ALIGNMENT` y `ASM_OUTPUT_ALIGNED_LOCAL`.

**[S2] Primaria — [confirmado, compilador Sony/Cygnus EE-GCC 2.9, NO 2.96]**  
[`mips.h`: `BITS_PER_WORD`, `CONSTANT_ALIGNMENT`, `DATA_ALIGNMENT`, `REG_ALLOC_ORDER`](https://raw.githubusercontent.com/SSXModding/ps2-ee-toolchain/master/ee/gcc/config/mips/mips.h). Ver alrededor de las líneas 1265, 1423–1444 y 1868–1884.

**[S3] Primaria — [confirmado, compilador Sony/Cygnus EE-GCC 2.9, NO 2.96]**  
[`local-alloc.c`: quantities, copy suggestions, priority, `optimize_size`, `find_free_reg`](https://raw.githubusercontent.com/SSXModding/ps2-ee-toolchain/master/ee/gcc/local-alloc.c). Ver alrededor de las líneas 77–90, 1300–1355, 1370–1450 y 1790–1930.

**[S4] Primaria — [confirmado como código histórico GCC, no 2.96 SCE]**  
[GCC `varasm.c` histórico](https://gnu.googlesource.com/gcc/+/9b1856d6c8c54a1b4b7e3a312f46a76f6d89c3df/gcc/varasm.c). Rastrear `CONSTANT_ALIGNMENT`, emisión de cadenas y `ASM_OUTPUT_ALIGN`. **El commit es referencia histórica, no prueba de equivalencia con la versión Sony.**

**[S5] Primaria — [confirmado como código histórico GCC, no necesariamente SCE 2.96]**  
[GCC `global.c` histórico](https://gnu.googlesource.com/gcc/+/251a817e23053b543f04f101c675f5513bbb1865/gcc/global.c): prioridades, frecuencias, conflictos y registros.

**[S6] Proyecto externo — [confirmado como experimentos de GT4, transferibilidad RoR: no confirmada]**  
[GT4: EE-GCC 2.96 knowledge notes](https://github.com/gustavocanepa/gt4-decomp/blob/master/knowledge/ee-gcc-2.96.md). La optimización principal documentada allí no es `-Os`.

**[S7] Fuentes/compiler archives — [confirmado existencia; fuente exacta Sony 2.96 no localizada]**  
[SSXModding/ps2-ee-toolchain](https://github.com/SSXModding/ps2-ee-toolchain); [decomp-meadow/ee-gcc-macos](https://github.com/decomp-meadow/ee-gcc-macos) (distingue Sony 2.9 con fuente y 2.96 sin fuente pública localizada); [GCC 2.95.3 upstream](https://www.sourceware.org/pub/gcc/releases/gcc-2.95.3/). No equiparar GCC genérico «2.96» con Sony `2.96-ee-001003-1`.

**[S8] Software original — [confirmado en README de upstream]**  
[simonlindholm/decomp-permuter](https://github.com/simonlindholm/decomp-permuter): macros `PERM_*`, comportamiento de randomización y puntuación imperfecta.

**[S9] Configuración original — [confirmado en archivo upstream]**  
[`default_weights.toml` oficial](https://github.com/simonlindholm/decomp-permuter/blob/main/default_weights.toml). Ver `[base]` y `[gcc]`. La revisión vendorizada puede diferir: consultar la copia real de Orca.

**[S10] Software externo — [confirmado en documentación de upstream; compatibilidad EE-GCC no confirmada]**  
[CriminalRETeam/cpp_permuter](https://github.com/CriminalRETeam/cpp_permuter): CLI `-c`, `--score-cmd`, `--target-symbol`, `--check-parse`, `--resume`, fuentes no modificadas y pruebas de MSVC6/Clang.

**[S11] Source del proyecto — [confirmado por inspección de scripts compartidos, podría haber cambios posteriores]**  
`tools/regalloc.py`, `tools/perm_official.py`, `tools/permute.py`, `tools/match.py`, `tools/configure.py`; el perfil de compilación fue tomado también del encargo enviado. No se garantiza que estos archivos sigan siendo idénticos a la rama actual después de los commits más recientes.

---

# 7. Encargo listo para Claude (ejecución sin cambios destructivos)

> Esta investigación aporta hechos comprobados y un plan de pruebas. No tratar como demostrada la regla `cadena de 16 bytes => alineación de 16`. Primero ejecutar la matriz de `.rodata` con `ee-gcc2.96 -Os` y conservar los `.s/.o` y metadatos completos. Después comparar `.lreg/.greg` de tres funciones REG_ONLY para identificar intervalos vivos, preferencias de copias y cruces de llamadas; realizar solo variantes semánticamente seguras. Probar `PERM_GENERAL` con búsquedas dirigidas, y en paralelo un piloto aislado de `cpp_permuter` con compilador y scorer de Rule of Rose, sin sustituir `perm_official.py` hasta validar baseline. Mantener originales intactos y no publicar ningún match sin comprobación del objeto y del build final. Registrar resultados fallidos tanto como éxitos para evitar trabajo repetido de los agentes.
