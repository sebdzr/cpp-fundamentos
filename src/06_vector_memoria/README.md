# Memoria de std::vector

Muestra tamaño y capacidad al reservar espacio y añadir seis valores.

## Qué practiqué

La diferencia que observo es que reserve cambia la capacidad disponible, sin agregar elementos. El crecimiento posterior de capacity depende de la implementación; no hay que asumir que siempre se duplica.

## Compilar y ejecutar

Desde esta carpeta, en PowerShell con GCC disponible:

```powershell
g++ main.cpp -std=c++17 -Wall -Wextra -pedantic -o ejercicio.exe
.\ejercicio.exe
```

No pide entrada. Observa size y capacity antes y después de superar los cinco espacios reservados.

Esta es una práctica de fundamentos. Las entradas interactivas esperan números válidos; no se presenta como una aplicación con validación completa.

[Volver al repositorio](../../README.md)
