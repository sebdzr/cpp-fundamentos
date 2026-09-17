# Laboratorio 05 — Listas de estudiantes y calificaciones

En este laboratorio de Estructuras de Datos con Néstor Suat trabajé una lista de estudiantes donde cada estudiante tiene su propia lista de calificaciones. El objetivo es conectar dos estructuras dinámicas y mantener sus datos y enlaces correctamente.

El programa lee nombres desde un archivo, los inserta en orden por apellido, permite ingresar hasta cuatro calificaciones por estudiante y muestra el total y el promedio de cada uno.

## Cómo está organizado

| Archivo | Responsabilidad |
| --- | --- |
| `ListaCalificaciones.h/.cpp` | Lista simple de notas, suma, promedio y copia profunda. |
| `Estudiante.h/.cpp` | Nombre, calificaciones y clave usada para ordenar. |
| `ListaEstudiantes.h/.cpp` | Lista doble con enlaces `prev` y `next`, inserción ordenada y acceso por posición. |
| `main.cpp` | Lectura del archivo, ingreso de notas y presentación de resultados. |
| `datos/estudiantes.txt` | 16 nombres ficticios de prueba; las notas se ingresan durante la ejecución. |

## Qué practiqué

- Mantener ambos enlaces al insertar al inicio, en medio o al final de una lista doble.
- Recorrer una lista exterior y acceder a la lista de notas de cada estudiante.
- Copiar las calificaciones sin compartir nodos entre objetos. `ListaCalificaciones` tiene constructor de copia, asignación y destructor.
- Validar líneas completas de entrada para evitar que letras sobrantes se interpreten como el siguiente dato.
- Separar la estructura de datos de la interacción en consola.

## Compilar y ejecutar

Con GCC (`g++`) disponible, desde la raíz del repositorio en PowerShell:

```powershell
cd universidad/estructuras_datos_2026_2/laboratorio_05
g++ main.cpp Estudiante.cpp ListaCalificaciones.cpp ListaEstudiantes.cpp -std=c++17 -Wall -Wextra -pedantic -o lab05.exe
.\lab05.exe
```

Ejecuta desde esa carpeta: la ruta `datos/estudiantes.txt` se interpreta respecto al directorio actual. No hace falta la guía del profesor para compilar o ejecutar el programa.

El archivo público usa nombres ficticios (`Nombre01 Apellido16`, etc.) para probar el orden sin publicar nombres de terceros.

Para cada estudiante, ingresa una cantidad entera entre 0 y 4 y después sus notas. Usa punto para los decimales. Por ejemplo, tres notas `3.5`, `4` y `4.5` producen total `12` y promedio `4`. Con cero notas, ambos resultados son `0`.

## Decisiones y límites

- El orden usa la clave `apellido + nombre`, separando el texto por el primer espacio. El archivo espera el formato simple `Nombre Apellido`; no resuelve de forma general los nombres compuestos.
- La comparación es lexicográfica de `std::string`, sensible a mayúsculas; no implementa reglas lingüísticas para ordenar acentos.
- Las notas deben ser finitas y no negativas. Esta versión no impone un máximo de 5.
- Las listas son lineales, no circulares. `get` requiere una posición válida y usa `assert` ante un índice incorrecto.
- `ListaEstudiantes` no implementa copia profunda: no se deben copiar ni asignar objetos de esa clase. La copia profunda disponible corresponde a la lista de calificaciones.
- Los resultados se muestran en consola; no se guardan al cerrar el programa.

## Material del curso

Este README describe mi implementación. Las guías y los enunciados originales del profesor se conservan localmente y no se incluyen en esta publicación.

[Volver al curso](../README.md)
