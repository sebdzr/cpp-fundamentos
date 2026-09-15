# Parte 1 — Lista simple genérica

Implementé una lista con `Node<T>`, un puntero `begin` y un contador. Incluye inserción por posición, eliminación, consulta e impresión normal e inversa. El programa actual muestra una lista de cadenas.

## Decisiones y aprendizaje

El recorrido inverso usa recursividad: primero llega al final y después imprime durante el retorno, sin invertir los enlaces. Para eliminar un nodo hay que reconectar la lista antes de liberar su memoria.

Las implementaciones de templates están en `list.cpp`, con instanciaciones explícitas para `int`, `double`, `string` y `Punto`. Por eso también se compila `Punto.cpp`, aunque el ejemplo actual use cadenas. Agregar otro tipo requiere su correspondiente instanciación.

## Compilar y ejecutar

Desde esta carpeta:

```powershell
g++ main.cpp list.cpp Punto.cpp -std=c++17 -Wall -Wextra -pedantic -o listas.exe
.\listas.exe
```

La salida normal empieza por `nestor` y termina en `pedro`; la inversa muestra el orden contrario. No se solicita entrada.

## Límites de esta versión

No copiar ni asignar objetos `List`: poseen memoria y no implementan copia profunda. `get` requiere una posición válida y usa `assert` al detectar un error; desactivar las aserciones no vuelve seguro un acceso inválido. El ejemplo actual no ejercita todas las operaciones.

[Volver al laboratorio](../README.md)
