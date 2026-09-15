# Ordenamiento burbuja

Ordena enteros de menor a mayor y muestra cada pasada.

## Qué practiqué

Practiqué intercambios entre vecinos y una bandera para terminar si ya no hay cambios. El peor caso es O(n²); con una entrada ordenada basta una pasada O(n).

## Compilar y ejecutar

Desde esta carpeta, en PowerShell con GCC disponible:

```powershell
g++ main.cpp -std=c++17 -Wall -Wextra -pedantic -o ejercicio.exe
.\ejercicio.exe
```

Ingresa una cantidad positiva y los enteros. Compara una secuencia ordenada con una invertida y otra con repetidos.

Esta es una práctica de fundamentos. Las entradas interactivas esperan números válidos; no se presenta como una aplicación con validación completa.

[Volver al repositorio](../../README.md)
