# Parte 2 — Inversión de arreglos con templates

Esta versión conserva `exchange`, `print` y `reverseArray`. Invierte arreglos de `int`, `double`, `char` y `string`, y muestra cada uno antes y después.

Practiqué dos parámetros de plantilla: `T` para el tipo y `N` para el tamaño. Recibir el arreglo como `T (&array)[N]` permite conservar su tamaño. La inversión intercambia extremos hasta la mitad y cuesta O(N), con espacio auxiliar constante.

## Compilar y ejecutar

Desde esta carpeta:

```powershell
g++ main.cpp -std=c++17 -Wall -Wextra -pedantic -o templates.exe
.\templates.exe
```

No pide entrada. El arreglo de enteros pasa de `1 2 3 4 5` a `5 4 3 2 1`.

[Volver al laboratorio](../README.md)
