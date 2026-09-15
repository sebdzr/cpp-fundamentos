# Búsqueda binaria

Ordena los enteros con std::sort y muestra cómo se reduce el intervalo de búsqueda.

## Qué practiqué

Aquí importa la condición previa: el vector debe estar ordenado. La búsqueda cuesta O(log n), pero el programa también realiza un ordenamiento O(n log n). El índice mostrado corresponde al vector ordenado.

## Compilar y ejecutar

Desde esta carpeta, en PowerShell con GCC disponible:

```powershell
g++ main.cpp -std=c++17 -Wall -Wextra -pedantic -o ejercicio.exe
.\ejercicio.exe
```

Ingresa la cantidad, los enteros y el valor buscado. Prueba los extremos y un valor que no exista.

Esta es una práctica de fundamentos. Las entradas interactivas esperan números válidos; no se presenta como una aplicación con validación completa.

[Volver al repositorio](../../README.md)
