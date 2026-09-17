# Laboratorio 04 — Suma y resta de polinomios

Representé cada polinomio con una lista enlazada simple. Cada nodo contiene un `Termino` con coeficiente y exponente enteros, además del enlace al siguiente nodo. Esta versión usa las clases `Node` y `List`, sin templates.

La guía de Néstor Suat pide leer dos archivos, construir las listas y combinar sus términos. Lo central para mí en esta práctica es seguir los dos recorridos y entender por qué avanza uno o ambos punteros.

## Cómo funciona

`begin` apunta al primer nodo y `end` permite insertar al final sin recorrer de nuevo la lista. En suma y resta, `a` y `b` comparan exponentes:

- Si coinciden, opera los coeficientes y avanza ambos punteros.
- Si son distintos, inserta el término de mayor exponente y avanza su puntero.
- Al terminar una entrada, agrega los términos pendientes de la otra.
- En la resta, los términos procedentes de P2 cambian de signo, también al copiar su resto.
- `insert` descarta coeficientes cero.

Cada combinación cuesta O(n + m), con una lista nueva para el resultado.

## Compilar y ejecutar

Desde la raíz del repositorio:

```powershell
cd universidad/estructuras_datos_2026_2/laboratorio_04
g++ main.cpp list.cpp Termino.cpp -std=c++17 -Wall -Wextra -pedantic -o lab04.exe
.\lab04.exe
```

Ejecuta desde la carpeta del laboratorio: el programa busca `datos/polinomio1.txt` y `datos/polinomio2.txt` respecto a esa ubicación. El archivo se llama `list.cpp`, en minúsculas.

## Entrada y resultado

Cada línea contiene `coeficiente exponente`, ambos enteros. Las entradas deben estar ordenadas de mayor a menor exponente, sin exponentes repetidos dentro de un polinomio. El programa asume esas condiciones; no ordena ni valida el formato completo. Los decimales no están soportados.

Con los archivos incluidos, la suma representa:

```text
2x^4 + 2x^3 + 2x + 8
```

La salida etiqueta cada polinomio y muestra sus términos por separado. La cancelación de `-3x^5` y `3x^5` permite observar por qué no se crea un nodo de coeficiente cero.

## Límites y puntos de repaso

El resultado debe ser una lista vacía, distinta de las entradas. No copiar ni asignar listas: esta implementación no define copia profunda. Los cálculos están limitados al rango de `int`.

Para repasar la sustentación, conviene seguir el caso de exponentes iguales, el cambio de signo en la resta y la liberación de nodos en el destructor.

La guía original del profesor se conserva localmente y no se distribuye con el código.

[Volver al curso](../README.md)
