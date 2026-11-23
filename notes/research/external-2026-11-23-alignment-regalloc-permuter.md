# Investigación externa — Rule of Rose: alineación, asignación de registros y decomp-permuter

**Fecha:** 23 de noviembre de 2026  
**Destinatario:** Claude, orquestador Orca  
**Juego:** Rule of Rose, SLUS-214.48  
**Toolchain de referencia del proyecto:** `ee-gcc2.96 -Os -G0 -fno-exceptions -fno-strict-aliasing -x c++`, ensamblador SCE `as 2.10`.  
**Estado:** investigación estática con fuentes públicas, sin ejecutar el compilador del proyecto.  
**Alcance:** únicamente las tres prioridades del encargo del 23 de noviembre. SDK, i3d y selección de `-O2` quedan fuera.

## Resumen ejecutivo

1. **Alineación:** el `config/mips/mips.h` histórico de GCC 2.8.0 define `CONSTANT_ALIGNMENT` para `STRING_CST` y `CONSTRUCTOR`, y `DATA_ALIGNMENT` para arrays/uniones/structs. Ambas elevan alineaciones inferiores a `BITS_PER_WORD`, cuyo valor es 32 o 64 bits según el target. **No se ha localizado ni validado todavía el `mips.h`/override de SCE GCC 2.96**: no permite demostrar automáticamente la regla observada de 16 bytes para la cadena `game/gamsnd.cpp`. Una dirección divisible por 16 no prueba que el símbolo requiera alineación 16.
2. **Registros:** el código fuente histórico de `local-alloc.c` y `global.c` documenta una prioridad relacionada con referencias, frecuencia, tamaño y duración de vida. Además importan **preferencias de copia**, restricciones de clase, cruces de llamadas, interferencias y el paso `reload`. Una receta como «declarar primero para obtener `$v1`» no está probada.
3. **Permutador:** `decomp-permuter` tiene `PERM_GENERAL`, `PERM_VAR`, `PERM_RANDOMIZE`, `PERM_LINESWAP`, `PERM_IGNORE`, `PERM_PRETEND` y pesos por compilador sobrescribibles desde `settings.toml`; la sección `[gcc]` del archivo de pesos ya elimina o reduce varias mutaciones pensadas para IDO. Existe `CriminalRETeam/cpp_permuter`, implementado para C++/MSVC 6, **no verificado con MIPS/SCE GCC 2.96**. Antes de reemplazar el puente C/C++ hay que medir su portabilidad.

### Matriz de confianza

| Hallazgo | Confianza | Advertencia |
|---|---|---|
| Macros de alineación en GCC 2.8.0 MIPS | Confirmado para GCC 2.8.0 | No trasladar ciegamente a SCE 2.96 |
| Reglas exactas de alineación 8/16 de RoR | **No confirmado** | Falta fuente exacta del compilador o matriz de experimentos |
| Fórmula de prioridad de asignación y preferencia por copias | Confirmado en código histórico de GCC | Parche de SCE 2.96 y valores exactos requieren prueba |
| `PERM_*` y pesos configurables en upstream | Confirmado | Verificar versión/clon del proyecto |
| `cpp_permuter` soporta métodos C++ | Confirmado en su README | Compatibilidad PS2 no confirmada |

---

## 1. Reglas de alineación de `.rodata` en MIPS/GCC 2.9x

### 1.1. Evidencia directa: GCC histórico

Fuente primaria: [GCC 2.8.0, `gcc/config/mips/mips.h`](https://gnu.googlesource.com/gcc/+/refs/tags/releases/gcc-2.8.0/gcc/config/mips/mips.h) (buscar `CONSTANT_ALIGNMENT` y `DATA_ALIGNMENT`). El código de esta revisión es:

```c
#define CONSTANT_ALIGNMENT(EXP, ALIGN) \
  ((TREE_CODE (EXP) == STRING_CST || TREE_CODE (EXP) == CONSTRUCTOR) \
   && (ALIGN) < BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))

#define DATA_ALIGNMENT(TYPE, ALIGN) \
  ((((ALIGN) < BITS_PER_WORD) \
     && (TREE_CODE (TYPE) == ARRAY_TYPE \
         || TREE_CODE (TYPE) == UNION_TYPE \
         || TREE_CODE (TYPE) == RECORD_TYPE)) \
    ? BITS_PER_WORD : (ALIGN))

#define BITS_PER_WORD (TARGET_64BIT ? 64 : 32)
```

Interpretación: esta versión **mínimamente** puede elevar una constante de cadena o constructor a alineación de palabra (4 u 8 bytes), y arrays/uniones/structs a una palabra. La macro usa el alineamiento de entrada y no fija un tope. **No determina por sí sola una regla de 16 bytes**. La alineación final depende de tipo, `TARGET_64BIT`, overrides del target, atributos, emisión de `varasm.c`, sección y ensamblador/enlazador.

`BIGGEST_ALIGNMENT` es el máximo alineamiento natural soportado por el target; **no hay que confundirlo con la alineación obligatoria de cada símbolo**. Igual con `MAX_OFILE_ALIGNMENT`: limita capacidad del formato objeto, no dicta la alineación de todos los objetos. `LOCAL_ALIGNMENT`, cuando existe en la configuración, atañe a variables automáticas y no es una explicación directa de `.rodata` global. Las definiciones exactas en el toolchain SCE no fueron verificadas.

El comportamiento de `-Os` **no aparece condicionado directamente** en las dos macros históricas citadas. Puede cambiar emisión de constantes, optimizaciones, fusión o disposición; no tenemos evidencia de que cambie directamente el macro a 8 o 16.

### 1.2. Importante: dirección observable ≠ alineación solicitada

Una cadena de 16 bytes puede comenzar en una dirección múltiplo de 16 por coincidencia, por el padding o por su predecesor, aunque el compilador solo exija 4 u 8 bytes. El hecho de que `"game/gamsnd.cpp"` + NUL tenga longitud 16 y aparezca en `0x...0` **no prueba** alineación 16. Hace falta una muestra variando el elemento anterior y leer la directiva emitida en `.s` y `sh_addralign` en `.o`.

### 1.3. Diferenciar cinco categorías

1. `"texto"` usado en expresión: `STRING_CST`, puede ir a pool de constantes.
2. `static const char name[] = "texto"`: declaración/objeto con tipo array, puede seguir ruta de `DATA_ALIGNMENT` además de inicializador; comprobar `-S`.
3. `static const int table[]`: array de int con alineamiento base de su tipo y posibles incrementos.
4. Literales `double`, constructores de agregados, tablas manuales: verificar 8 bytes, tipo y atributos; no extrapolar a todo `.rodata`.
5. Jump tables del `switch`: emisión mediante backend MIPS/assembler, no necesariamente el mecanismo de los objetos C++ nombrados. El proyecto observa 16 bytes, **pero la regla exacta del backend SCE aún no está documentada en las fuentes recuperadas**.

### 1.4. Experimento propuesto: matriz mínima y reproducible

En un worktree aislado, compilar bajo los flags **exactos** de RoR (`-Os`), primero con `ee-gcc ... -S` y después a `.o`; guardar `-S`, el dump de secciones y su alineación con `readelf -SW`. No modificar el juego original.

```cpp
extern "C" const char *str16() { return "game/gamsnd.cpp"; }
extern "C" const char *str15() { return "game/gamsnd.cp"; }
extern "C" const char *str17() { return "game/gamsnd.cppx"; }
static const char array16[] = "game/gamsnd.cpp";
static const int ints4[] = { 1, 2, 3, 4 };
static const long long longs2[] = { 1, 2 };
extern "C" int use_const(int x) {
    switch(x) { case 1: return 4; case 3: return 9; case 5: return 13;
                case 8: return 11; default: return -1; }
}
```

Advertencia: constantes no usadas pueden eliminarse y los `switch` simples pueden convertirse en condicionales. Añadir referencias reales y un `switch` con suficientes casos densos para forzar una tabla si procede. Registrar, por cada entidad: **nombre, clase de constante, tamaño, tipo, `.align` emitido, `sh_addralign`, offset, dirección final**; repetir con distinto orden de declaraciones y padding previo. Incluir objetos `__attribute__((aligned(8)))` y `(aligned(16))` como **controles positivos**, no como prueba del comportamiento por defecto. Si se confirma que el backend usa `align` en potencias de dos, distinguir `.align 4` en GAS-MIPS (2^4) de `.p2align` y `.balign`, sin suponer sintaxis de otras arquitecturas.

**Entregable para Orca:** tabla de observaciones + hipótesis por clase + script de comparación. **No implantar una heurística de alineación automática antes de obtener esos resultados.**

### 1.5. Prioridad para localizar la fuente del compilador exacto

1. Identificar banner y checksums de `cc1plus`, `cc1`, `ee-as` del contenedor real; registrar `ee-gcc2.96` exacto.
2. Revisar fuentes GPL de EE antiguas y forks históricos, **sin asumir que `ps2dev/ps2toolchain-ee` actual reproduce SCE 2.96**: el proyecto moderno usa GCC 15.2.0, por lo que no es evidencia directa. Fuente: https://github.com/ps2dev/ps2toolchain-ee
3. Buscar overlays del target `config/mips/mips.h`, `ee.h`, `r5900.h`, configuración `tm.h` generada y la implementación de `varasm.c` de **esa** versión. La definición efectiva depende de macros incluidas y valores de target.
4. Usar `-S` del compilador real para resolver empíricamente mientras se localiza su fuente.

---

## 2. Por qué GCC elige `$v1`, `$a0`, `$sN` y `$fN`

### 2.1. El criterio documentado

Fuentes primarias de GCC histórico:
- [`gcc/local-alloc.c` — `QTY_CMP_PRI`, preferencias por copias, cruces de llamadas](https://gnu.googlesource.com/gcc/+/9b1856d6c8c54a1b4b7e3a312f46a76f6d89c3df/gcc/local-alloc.c).
- [`gcc/global.c` — `allocno_compare`, conflictos](https://gnu.googlesource.com/gcc/+/251a817e23053b543f04f101c675f5513bbb1865/gcc/global.c).
- [GCC Internals — Allocation Order](https://gcc.gnu.org/onlinedocs/gccint/Allocation-Order.html).

El comparador local usa, simplificando:

```c
priority ~= floor_log2(n_refs) * frequency * size / live_length
```

La fórmula real también multiplica una escala de frecuencia y **los candidatos con preferencias por copia pueden ordenarse antes**, mediante `qty_phys_num_copy_sugg`, `qty_phys_num_sugg`. El orden de desempate incluye el identificador de quantity. El asignador global usa un criterio parecido para `allocno` y una matriz de interferencias. Esto no basta para decidir el registro concreto porque luego se aplican las clases y restricciones de registros, `find_free_reg`, `REG_ALLOC_ORDER` cuando esté definido y `reload`.

`local-alloc.c` además comprueba `n_calls_crossed`: un pseudo que vive a través de llamadas necesita un registro compatible o salvado. Una intervención pequeña que cambie cuándo muere un valor puede cambiar de `$a0` a `$sN`. En MIPS `$a0` es registro de argumento/caller-saved; `$sN` es callee-saved; aun así la elección concreta depende del ABI SCE y del código alrededor.

### 2.2. Las pruebas de código que sí tienen fundamento

**A. Retrasar la inicialización:**

```cpp
// A: x vive durante una llamada
int x = calculate_index();
external_call();
use(x);

// B: solo equivalente si calculate_index puede moverse sin cambiar efectos
external_call();
int x = calculate_index();
use(x);
```

*Precaución semántica:* B puede cambiar el resultado/efectos; preferir variantes cuyo movimiento sea lícito y comprobable.

**B. Cambiar el alcance manteniendo usos y semántica:**

```cpp
int idx;
if (ok) { idx = transform(v); consume(idx); }
```

versus

```cpp
if (ok) { int idx = transform(v); consume(idx); }
```

Puede afectar IR/vida de un pseudo; no hay garantía de cambiar registro.

**C. Identificar una preferencia por copia de registro de argumento:**

```cpp
void f(int a, int b) {
    int n = a;
    use(n, b);
}
```

Comparar con uso directo de `a` **sin asumir igualdad del ensamblador**. Examinar `.lreg/.greg`: la copia puede crear preferencia por el registro físico previo.

**D. Ordenar inicializaciones y usos que sean independientes:**

```cpp
int a = base + 1;
int b = limit - 1;
return combine(a, b);
```

frente a intercambiar solo estas declaraciones o los usos, siempre que no haya observables distintos. Medir separadamente **orden de declaración**, **orden de inicialización**, **primera/última utilización** y **presencia de llamadas**.

**E. FPR:** para `float`, observar `FP_REGS`, instrucciones `lwc1`/`swc1`, copies y presión de temporales. No tratar `$f2` y `$f4` como si siguieran el mismo orden que los GPR.

### 2.3. Cómo aprovechar `tools/regalloc.py`

En la auditoría anterior `regalloc.py` ya lee `.lreg/.greg`. No duplicar esta herramienta. Mejorarla con:

1. **Comparación A/B** en entradas y directorios inmutables; `--src` para dos variantes, sin sobrescribir volcados de otra sesión.
2. Identificación precisa de funciones C++ sobrecargadas y declaración efectiva, no solo nombre parcial.
3. Mostrar `n_calls_crossed`, `REG_N_REFS`, `REG_FREQ`, `REG_LIVE_LENGTH`, clase preferida, sugerencias hard-reg/copia y estado tras `reload`, **solo si el dump de la versión exacta expone esos datos**.
4. `--json`: antes/después: pseudo, clase, GPR/FPR, referencias, vida, prioridad estimada, hard register observado y primer cambio de asm.
5. Etiquetar **correlación ≠ causalidad**: una diferencia de prioridad no prueba que explique el registro final.

Protocolo para cada near miss: comparar `-dl -dg` (el script `regalloc.py` usa `-dlg`), opcionalmente dumps de `reload` si están soportados, alterar **una** dimensión de la fuente y volver a medir. Registrar cuando el asignador **no** siga la heurística de prioridad, lo cual orienta a preferencias, ABI o reload.

### 2.4. Cuándo evitar fijar registros manualmente

Conservar registros fijos como último recurso controlado o como experimento, pero evaluar si introduce asm de bajo nivel que perjudique el port. No declarar «matching C++ natural» un caso donde el registro se fuerza mediante extensión dependiente de GCC sin observar equivalencia y el build completo.

---

## 3. decomp-permuter: macros, pesos y alternativas C++

### 3.1. Funcionalidad confirmada en upstream

Repositorio: https://github.com/simonlindholm/decomp-permuter

El README documenta:

| Macro | Función |
|---|---|
| `PERM_GENERAL(a,b,...)` | Enumerar alternativas escritas por el investigador |
| `PERM_VAR(k,v)` / `PERM_VAR(k)` | Definir y reutilizar metavariables entre fragmentos |
| `PERM_RANDOMIZE(c)` | Permitir mutaciones aleatorias en un fragmento además de alternativas manuales |
| `PERM_LINESWAP(lines)` | Permutar líneas que constituyen sentencias completas |
| `PERM_INT(lo,hi)` | Probar valores enteros dentro de un rango |
| `PERM_ONCE([key,] code)` | Emitir una pieza exactamente en uno de varios sitios |
| `PERM_IGNORE(code)` | Pasar código sin atravesar el parser C ni sus mutaciones |
| `PERM_PRETEND(code)` | Aportar texto solo para parser/mutador, eliminarlo después |
| `PERM_FORCE_SAMELINE` | Fuerza código en una línea, especialmente útil para IDO |

Las macros pueden anidarse. **Cuando existe una macro de múltiples elecciones, se desactiva la randomización automática**, salvo que se añada `PERM_RANDOMIZE`. Documentación upstream: https://github.com/simonlindholm/decomp-permuter#readme

### 3.2. Ejemplo propuesto de búsqueda guiada

```c
/* Ejemplo sintáctico: probar alternativas SIN cambiar resultado */
int f(int x) {
    int y = PERM_GENERAL(x + 1, 1 + x);
    return y;
}
```

En funciones más complicadas, usar `PERM_GENERAL` para dos órdenes de instrucciones **solo cuando las sentencias sean independientes**, o para variar qué expresión se guarda temporalmente. Reservar `PERM_RANDOMIZE` a un bloque cuyo código sea compatible con C y revisado. No permutar orden de `&&`, operaciones volátiles o stores con aliasing sin análisis de semántica.

### 3.3. Pesos: hecho concreto que ahorra trabajo

Archivo primario: https://github.com/simonlindholm/decomp-permuter/blob/main/default_weights.toml

La sección `[base]` da, por ejemplo, `perm_temp_for_expr = 100`, `perm_expand_expr = 20`, `perm_reorder_stmts = 10`, `perm_reorder_decls = 10`. La sección `[gcc]` reduce algunos pesos de IDO: `perm_add_mask`, `perm_xor_zero`, `perm_refer_to_var`, `perm_float_literal`, `perm_sameline`, `perm_empty_stmt`, `perm_condition`, `perm_mult_zero`, `perm_dummy_comma_expr`, `perm_add_self_assignment`, `perm_duplicate_assignment`, `perm_pad_var_decl` a `0.5` y usa `perm_alias_array = 3` (según la versión pública consultada).

**Cómo configurar:** upstream explica que los pesos se sobreescriben **en `settings.toml` del caso**, no modificando globalmente el archivo de defaults. Revisar la sintaxis exacta admitida por el checkout `build/decomp-permuter`, ya que puede diferir de `main`. No introducir a ciegas claves o sintaxis que no reconozca ese checkout. Para un fallo exclusivamente de registros, priorizar temp/decl/referencia/copia; para scheduling, reordenamientos seguros; para C++ complicado, abstenerse de aleatorizar el fragmento que el parser no entiende.

### 3.4. C++: límites y opciones verificadas

**A. Upstream clásico**: el proyecto explica que es un permutador C basado en `pycparser`. Sugiere `PERM_IGNORE` + `PERM_PRETEND` para código que el parser no entiende, incluido C++; **esto no equivale a soporte nativo de AST C++**. Se puede preservar C++ inmutable alrededor de una región C compatible.

**B. Proyecto aparte**: [CriminalRETeam/cpp_permuter](https://github.com/CriminalRETeam/cpp_permuter) declara soporte de código C++, clases, métodos y mutaciones dirigidas, y publica ejemplos con `PedGroup::...`. Utiliza un motor propio en C++, `llvm-objdump` y está diseñado para **GTA2/MSVC 6**, no PS2/MIPS. Es relevante para **estudiar las transformaciones y el análisis léxico**, pero no se ha probado compilación con `ee-gcc2.96`, GNU-as 2.10 ni el tratamiento de relocaciones del proyecto. La licencia es MIT según el README; revisar el contenido del repositorio antes de reutilizar código.

**C. Recomendación para `perm_official.py`:** mantener el puente actual solo para funciones expresables como C sin pérdida semántica. El script previo convierte `bool` a `int`, altera cadenas con regex y usa parser top-level sensible a comentarios; son riesgos ya documentados en la auditoría. Mejor probar `PERM_IGNORE`/`PERM_PRETEND` o fragmentar las regiones sin transformar literalmente el texto. Si la función necesita C++ real, evaluar experimentalmente `cpp_permuter` en modo adaptado, con compilación exacta y juez `match.py` como autoridad; **no adoptarlo como reemplazo global antes de demostrar al menos tres matches reales**.

### 3.5. Política de candidatos para Orca

- Candidato del permutador `score=0` = **señal**, no aceptación automática.
- Recompilar como el `.cpp` original bajo flags exactos, validar relocaciones y `.rodata`; exigir `MATCH` de TU sin romper otras funciones.
- El coordinador verifica SHA-1 de build en integraciones; dejar el commit y merge sujetos al flujo autorizado.
- Guardar en JSONL: versión del permutador, hash del código, modelo que formuló la hipótesis (si lo hubo), mutación, flags, score, diff, resultado de TU y costo en compilaciones.
- Cambios que alteren semántica, introduzcan UB o eliminen dependencias no deben aceptarse por proximidad de ensamblador.

---

## 4. Plan experimental sugerido (orden de retorno)

| Fase | Trabajo | Criterio de éxito | Riesgo |
|---|---|---|---|
| P0 | Matriz `.rodata` con `-S` y `.o` para 4/8/16 bytes | Deducir alineación **solicitada** separada de dirección accidental | Bajo |
| P0 | `regalloc.py` A/B con dumps aislados y trazas de preferencias | Explicar 3 near misses de registros y reproducirlos | Bajo |
| P1 | Ejecutar búsqueda manual `PERM_GENERAL` para 3 near misses | Mejorar más que random puro a igual nº compilaciones | Bajo/medio |
| P1 | Ajustar pesos en `settings.toml` por clase de mismatch | Menor número de compiles por mejor candidato | Bajo |
| P2 | Evaluar `cpp_permuter` con 3 métodos C++ sencillos | Parser acepta métodos y matches verificados por proyecto | Medio/alto |

**Comparación de eficiencia:** registrar funciones resueltas/100 compilaciones, reducción mediana de edits, tiempo de compilación, propuestas semánticamente inválidas y necesidad de revisión por Gemini. No modificar los archivos fuente de producción para hacer un experimento. Ejecutar en snapshot/worktree.

---

## 5. Preguntas que permanecen abiertas

1. ¿Qué valores efectivos de `CONSTANT_ALIGNMENT`, `DATA_ALIGNMENT`, `BIGGEST_ALIGNMENT`, `MAX_OFILE_ALIGNMENT` y, si aplican, overrides `r5900.h`/`ee.h`, utiliza realmente el `cc1plus` SCE de este proyecto? **No confirmado.**
2. ¿Es la cadena `game/gamsnd.cpp` una `STRING_CST` anónima, un array con nombre o un pool compartido? **No confirmado solo por su longitud.**
3. ¿La alineación 16 de las jump tables se introduce en GCC, ensamblador o linker? **No confirmado.**
4. ¿El `REG_ALLOC_ORDER` del backend SCE difiere del GCC MIPS histórico? **No confirmado**; inspeccionar toolchain real.
5. ¿`cpp_permuter` acepta el C++ de Rule of Rose y puede puntuar objetos MIPS con relocaciones SCE? **No confirmado.**

## 6. Referencias técnicas verificadas

1. GCC 2.8.0 MIPS `mips.h` (macros alineación y `BITS_PER_WORD`): https://gnu.googlesource.com/gcc/+/refs/tags/releases/gcc-2.8.0/gcc/config/mips/mips.h
2. GCC histórico `local-alloc.c` (prioridad, copy suggestions, cruces de llamadas): https://gnu.googlesource.com/gcc/+/9b1856d6c8c54a1b4b7e3a312f46a76f6d89c3df/gcc/local-alloc.c
3. GCC histórico `global.c` (prioridad y conflictos): https://gnu.googlesource.com/gcc/+/251a817e23053b543f04f101c675f5513bbb1865/gcc/global.c
4. GCC Internals: https://gcc.gnu.org/onlinedocs/gccint/Allocation-Order.html
5. decomp-permuter upstream: https://github.com/simonlindholm/decomp-permuter
6. decomp-permuter defaults: https://github.com/simonlindholm/decomp-permuter/blob/main/default_weights.toml
7. cpp_permuter (C++/MSVC): https://github.com/CriminalRETeam/cpp_permuter
8. ps2dev modern toolchain README (aclaración de versión): https://github.com/ps2dev/ps2toolchain-ee
9. gt4-decomp, investigación externa análoga `-O2` **solo como inspiración, no regla para `-Os`**: https://github.com/gustavocanepa/gt4-decomp/blob/master/knowledge/ee-gcc-2.96.md

**No se ejecutó el toolchain de Rule of Rose ni se verificó directamente el código del compilador SCE 2.96.** Los ejemplos de C++ y los experimentos propuestos son instrucciones de verificación, no resultados obtenidos.
