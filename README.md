# C++ Fundamentos

Soy Sebastián, estudiante de Ingeniería de Sistemas. En este repositorio guardo las prácticas con las que estoy reforzando C++, algoritmos y estructuras de datos, junto con las entregas de la universidad.

La idea es poder volver a un ejercicio, entender las decisiones que tomé y ejecutarlo sin depender de cómo estaba configurado mi computador. También es parte de mi preparación profesional: construir evidencia de lo que voy aprendiendo antes de graduarme.

## Cómo ha evolucionado en 2026-2

Empecé con estadísticas, búsquedas y ordenamiento sobre vectores. Después pasé a punteros, separación de archivos y memoria. Las entregas de Estructuras de Datos incorporan arreglos irregulares, listas enlazadas y templates; el laboratorio 04 aplica listas simples a la suma y resta de polinomios.

## Cómo navegarlo

- `src/`: prácticas personales de C++. Cada ejercicio se compila por separado. `src/main.cpp` conserva mi primera presentación en consola.
- [Estructuras de Datos 2026-2](universidad/estructuras_datos_2026_2/README.md): laboratorios del curso con Néstor Suat y sus decisiones académicas.

Este repositorio está dentro de la carpeta local `Proyectos`. Las actividades de otros lenguajes se conservan fuera de `cpp-fundamentos`; aquí reúno únicamente trabajo en C++.

## Prácticas de C++

| Práctica | Qué hace |
| --- | --- |
| [Analizador de números](src/01_analizador_numeros/README.md) | Calcula suma, promedio, extremos y cantidad de pares e impares de un conjunto de enteros. |
| [Búsqueda lineal](src/02_busqueda_lineal/README.md) | Busca un entero recorriendo un vector y devuelve su primer índice o -1. |
| [Ordenamiento burbuja](src/03_ordenamiento_burbuja/README.md) | Ordena enteros de menor a mayor y muestra cada pasada. |
| [Búsqueda binaria](src/04_busqueda_binaria/README.md) | Ordena los enteros con std::sort y muestra cómo se reduce el intervalo de búsqueda. |
| [Punteros y funciones](src/05_punteros_funciones/README.md) | Duplica una variable mediante una función que recibe su dirección. |
| [Memoria de std::vector](src/06_vector_memoria/README.md) | Muestra tamaño y capacidad al reservar espacio y añadir seis valores. |
| [Seguimiento de punteros](src/07_seguimiento_punteros/README.md) | Sigue dos punteros que terminan apuntando a la misma variable y luego separa uno con nullptr. |

## Herramientas y ejecución

Trabajo desde Windows y PowerShell. Los comandos documentados utilizan GCC (`g++`) con C++17 y advertencias activadas. El editor puede ser Visual Studio Code; el compilador es una herramienta independiente.

Comprueba que el compilador esté disponible con `g++ --version`. Entra en la carpeta del ejercicio y sigue su README. Los laboratorios tienen varios archivos `.cpp`; deben compilarse juntos según sus instrucciones. No se compila todo el repositorio en un único ejecutable porque hay varios `main`.

Para ejecutar la primera presentación desde la raíz:

```powershell
g++ src/main.cpp -std=c++17 -Wall -Wextra -pedantic -o presentacion.exe
.\presentacion.exe
```

Git y GitHub conservan el historial. Los ejecutables, temporales, configuraciones locales y credenciales quedan fuera del repositorio mediante `.gitignore`.

## Próximos pasos

- Seguir agregando las actividades reales del semestre con sus instrucciones y límites.
- Profundizar en árboles, tema anunciado para el siguiente parcial de Estructuras de Datos.
- Reforzar casos límite, manejo de memoria y explicación de los recorridos.
- Mantener commits por cambios concretos y revisar las diferencias antes de publicar.

No doy estos pasos por terminados: la documentación irá cambiando junto con el código. Las versiones académicas conservan el enfoque de cada actividad.
