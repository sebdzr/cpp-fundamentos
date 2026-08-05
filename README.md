# C++ Fundamentos

Repositorio destinado a practicar programación, algoritmia y estructuras de datos utilizando C++

## Objetivos

- Reforzar los fundamentos de C++
- Aplicar buenas prácticas de programación
- Documentar mi proceso de aprendizaje
- Prepararme para la materia Estructuras de Datos
- Construir un portafolio antes de graduarme

## Estructura

```text
cpp-fundamentos/
├── src/
│   └── main.cpp
├── .gitignore
└── README.md
```

## Ejercicios

### 01. Analizador de números

Programa que solicita varios números enteros y calcula:

- Suma.
- Promedio.
- Número menor.
- Número mayor.
- Cantidad de números pares.
- Cantidad de números impares.

### Conceptos practicados

- `std::vector`.
- `push_back`.
- `reserve`.
- Paso de vectores mediante referencia constante.
- Funciones.
- Ciclos basados en rango.
- Complejidad temporal lineal `O(n)`.
- Estructuras mediante `struct`.
- Refactorización
- Cálculo de estadisticas en un solo recorrido.

#### Optimización

La primera versión calculaba cada estadística mediante un recorrido independiente del vector.

La versión actual utiliza una estructura llamada `Estadisticas` y calcula todos los resultados mediante un único recorrido.

Ambas versiones tienen complejidad temporal `O(n)`, pero la versión optimizada realiza menos recorridos y menos trabajo real.

### Compilación

```powershell
g++ .\src\01_analizador_numeros\main.cpp -std=c++17 -Wall -Wextra -pedantic -o .\bin\analizador.exe
```

### Ejecución

```powershell
.\bin\analizador.exe
```
### 02. Búsqueda lineal

Programa que almacena números enteros y busca un valor recorriendo el vector desde el primer elemento hasta encontrarlo.

#### Conceptos practicados

- Índices de un vector.
- `size()`.
- Acceso seguro mediante `at()`.
- Diferencia entre `at(i)` y `[i]`.
- Uso de `-1` para representar un resultado no encontrado.
- Búsqueda lineal.
- Complejidad temporal `O(n)`.
- Complejidad espacial adicional `O(1)`.

#### Compilación

```powershell
g++ .\src\02_busqueda_lineal\main.cpp -std=c++17 -Wall -Wextra -pedantic -o .\bin\busqueda.exe
```

#### Ejecución

```powershell
.\bin\busqueda.exe
```

### 03. Ordenamiento burbuja

Programa que ordena números enteros de menor a mayor mediante comparaciones e intercambios entre elementos vecinos.

#### Conceptos practicados

- Ordenamiento burbuja.
- Ciclos anidados.
- Acceso seguro mediante `at()`.
- Modificación de vectores mediante referencia.
- Intercambio de valores con `swap()`
- Uso de una bandera booleana.
- Salida anticipada mediante `break`.
- Complejidad temporal cuadrática.

#### Complejidad

- Mejor caso optimizado: `O(n)`.
- Peor caso: `O(n²)`.
- Espacio adicional: `O(1)`.

La optimización utiliza una variable booleana para detener el algoritmo cuando una pasada completa no realiza intercambios.

#### Compilación

```powershell
g++ .\src\03_ordenamiento_burbuja\main.cpp -std=c++17 -Wall -Wextra -pedantic -o .\bin\burbuja.exe
```

#### Ejecución

```powershell
.\bin\burbuja.exe
```

### 04. Búsqueda binaria

Programa que ordena un conjunto de números y busca un valor descartando la mitad de la zona pendiente en cada iteración.

#### Conceptos practicados

- Búsqueda binaria.
- Límites izquierdo, derecho y central.
- Ordenamiento mediante `sort()`.
- Uso de `begin()` y `end()`.
- Acceso seguro mediante `at()`.
- Conversión explícita mediante `static_cast`.
- Complejidad temporal `O(log n)`.
- Complejidad espacial adicional `O(1)`.

#### Compilación

```powershell
g++ .\src\04_busqueda_binaria\main.cpp -std=c++17 -Wall -Wextra -pedantic -o .\bin\binaria.exe
```

#### Ejecución

```powershell
.\bin\binaria.exe
```

### 05. Punteros y funciones

Práctica introductoria sobre punteros en C++ y separación del código en varios archivos.

#### Conceptos aplicados:

- Obtención de direcciones de memoria con `&`.
- Desreferenciación de punteros con `*`.
- Validación de punteros mediante `nullptr`.
- Modificación de una variable desde una función.
- Separación entre archivo de cabecera, implementación y `main`
- Compliación y enlazado de múltiples archivos `.cpp`

#### Compilación

```powershell
g++ .\src\05_punteros_funciones\main.cpp .\src\05_punteros_funciones\Operaciones.cpp -std=c++17 -Wall -Wextra -pedantic -o .\bin\05_punteros_funciones.exe 
```

#### Ejecución

```powershell
.\bin\05_punteros.exe
```

### 06. Memoria en `std::vector`

Práctica para observar cómo `std::vector` administra su tamaño y capacidad durante la inserción de elementos.

Conceptos aplicados:

- Diferencia entre `size()` y `capacity()`.
- Reserva anticipada de memoria con `reserve()`.
- Inserción de elementos al final con `push_back()`.
- Recorrido seguro mediante `size_t` y `at()`.
- Observación de la reasignación de memoria al superar la capacidad.

#### Compilación

```powershell
g++ .\src\06_vector_memoria -std=c++17 -Wall -Wextra -pedantic -o .\bin\06_vector_memoria.exe
```

#### Ejecución

```powershell
.\bin\06_vector_memoria.exe
```