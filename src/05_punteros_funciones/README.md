# Punteros y funciones

Duplica una variable mediante una función que recibe su dirección.

## Qué practiqué

Practiqué & y *, la comprobación de nullptr y la separación entre cabecera e implementación. Compilar main.cpp también requiere enlazar Operaciones.cpp.

## Compilar y ejecutar

Desde esta carpeta, en PowerShell con GCC disponible:

```powershell
g++ main.cpp Operaciones.cpp -std=c++17 -Wall -Wextra -pedantic -o ejercicio.exe
.\ejercicio.exe
```

No pide entrada. Muestra 7 antes de llamar la función y 14 después.

Esta es una práctica de fundamentos. Las entradas interactivas esperan números válidos; no se presenta como una aplicación con validación completa.

[Volver al repositorio](../../README.md)
