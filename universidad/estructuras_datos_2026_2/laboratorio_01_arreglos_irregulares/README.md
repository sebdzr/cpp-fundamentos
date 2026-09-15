# Laboratorio 01 - Sistema Aerocivil con arreglos irregulares

En este laboratorio de Estructuras de Datos con Néstor Suat trabajé memoria dinámica y arreglos irregulares a través de un sistema de aerolíneas y vuelos. El escenario es el Aeropuerto Vanguardia de Villavicencio.

El punto que quiero conservar de esta práctica es cómo administrar filas de distinto tamaño, redimensionarlas y liberar su memoria sin perder los datos.

## Objetivo

Desarrollar un sistema para Aerocivil Colombia que permita registrar y
administrar los vuelos realizados por diferentes aerolíneas en el Aeropuerto
Vanguardia, considerando que cada aerolínea posee itinerarios diferentes y
que la cantidad de pasajeros depende de la capacidad de la aeronave asignada.

Los vuelos se consideran con ocupación completa.

## Arquitectura

El sistema está dividido en cuatro clases principales:

- `Aeronave`: almacena el modelo y la capacidad de pasajeros.
- `Vuelo`: almacena código, origen, destino, hora y aeronave.
- `Aerolinea`: administra los vuelos mediante un arreglo irregular.
- `SistemaAerocivil`: administra las aerolíneas y coordina las operaciones.

## Arreglo irregular

El núcleo del laboratorio se encuentra en `Aerolinea`:

```cpp
Vuelo** vuelosPorDia;
int* cantidadVuelosPorDia;
```

Cada posición del arreglo exterior representa un día de la semana y cada día
puede tener una cantidad diferente de vuelos.

Ejemplo:

```text
Lunes       -> [Vuelo][Vuelo][Vuelo]
Martes      -> nullptr
Miercoles   -> [Vuelo]
Jueves      -> nullptr
Viernes     -> [Vuelo][Vuelo]
Sabado      -> [Vuelo]
Domingo     -> nullptr

Cantidad    -> [3][0][1][0][2][1][0]
```

Al agregar o eliminar vuelos, las filas se redimensionan manualmente mediante
`new[]` y `delete[]`.

## CRUD

El sistema permite:

- Crear aerolíneas y vuelos.
- Consultar aerolíneas, vuelos e itinerarios.
- Actualizar información de aerolíneas y vuelos.
- Eliminar aerolíneas y vuelos.

## Datos precargados

El código contiene ejemplos de aerolíneas, aeronaves y vuelos para probar el sistema. Son datos de trabajo del ejercicio; este repositorio no mantiene una programación aérea actualizada.

## Qué practiqué

Separé las responsabilidades entre clases y trabajé copia profunda, destructores y redimensionamiento manual. Cada fila representa un día: agregar un vuelo implica reservar espacio, copiar los elementos y liberar la fila anterior.

## Validaciones

El programa contempla, entre otros:

- Días fuera de rango.
- Índices fuera de rango.
- Aerolíneas inexistentes.
- Vuelos inexistentes.
- Códigos de vuelo duplicados en el mismo día.
- Capacidades menores o iguales a cero.
- Horarios con formato inválido.
- Entradas no numéricas en los menús.
- Eliminación del único elemento de una fila.
- Redimensionamiento dinámico de arreglos.
- Copia profunda para evitar aliasing y double free.
- Autoasignación segura.

## UML

El diagrama UML editable se encuentra en:

```text
docs/UML_AEROCIVIL.dia
```

## Compilación

Desde la raíz de `cpp-fundamentos`, crea primero la carpeta de salida:

```powershell
New-Item -ItemType Directory -Force bin | Out-Null
```

```powershell
g++ .\universidad\estructuras_datos_2026_2\laboratorio_01_arreglos_irregulares\main.cpp `
.\universidad\estructuras_datos_2026_2\laboratorio_01_arreglos_irregulares\Aeronave.cpp `
.\universidad\estructuras_datos_2026_2\laboratorio_01_arreglos_irregulares\Vuelo.cpp `
.\universidad\estructuras_datos_2026_2\laboratorio_01_arreglos_irregulares\Aerolinea.cpp `
.\universidad\estructuras_datos_2026_2\laboratorio_01_arreglos_irregulares\SistemaAerocivil.cpp `
-std=c++17 -Wall -Wextra -pedantic `
-o .\bin\lab01_aerocivil.exe
```

Ejecución:

```powershell
.\bin\lab01_aerocivil.exe
```

## Estructura

```text
laboratorio_01_arreglos_irregulares/
├── Aeronave.h
├── Aeronave.cpp
├── Vuelo.h
├── Vuelo.cpp
├── Aerolinea.h
├── Aerolinea.cpp
├── SistemaAerocivil.h
├── SistemaAerocivil.cpp
├── main.cpp
├── README.md
└── docs/
    └── UML_AEROCIVIL.dia
```
[Volver al curso](../README.md)
