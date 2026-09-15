# Seguimiento de punteros

Sigue dos punteros que terminan apuntando a la misma variable y luego separa uno con nullptr.

## Qué practiqué

Practiqué la diferencia entre cambiar la dirección de un puntero y modificar el dato al que apunta. Asignar nullptr a ptr2 no cambia ptr1 ni elimina la variable.

## Compilar y ejecutar

Desde esta carpeta, en PowerShell con GCC disponible:

```powershell
g++ main.cpp -std=c++17 -Wall -Wextra -pedantic -o ejercicio.exe
.\ejercicio.exe
```

No pide entrada. Al final num1 vale 10 y num2 vale 50. Las direcciones de memoria pueden cambiar entre ejecuciones.

Esta es una práctica de fundamentos. Las entradas interactivas esperan números válidos; no se presenta como una aplicación con validación completa.

[Volver al repositorio](../../README.md)
