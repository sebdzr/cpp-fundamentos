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