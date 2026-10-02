# Laboratorio 6 - Recursividad

Implementacion de los puntos 6.1 a 6.4 de la guia FO-DOC-112.
No se usan contenedores ni algoritmos STL; se conservan arreglos y string,
como en los laboratorios anteriores.

Desde esta carpeta:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Recursividad.cpp -o laboratorio_06.exe
./laboratorio_06.exe
```

El programa muestra 10 arreglos de 10 enteros, 10 enteros invertidos,
10 cadenas y 10 casos de chocolates; compara sus resultados con valores
esperados y retorna 1 si alguna prueba falla. Despues permite escribir
cadenas completas con espacios; Enter vacio o fin de entrada termina.

## Funciones y casos base

- 6.1: encontrarMenor es no recursiva. Inicializa menor con arreglo[0] e
  indice con 1; menorHelper lleva ambos parametros adicionales y termina
  cuando indice == cantidad. Un arreglo vacio no tiene minimo: retorna false.
- 6.2: invertirDigitos es no recursiva; invertirHelper acumula los digitos
  y retorna directamente la llamada recursiva (cola). Caso base: numero == 0.
  Conserva signos; 1200 produce 21 porque el resultado es un numero entero.
  Retorna long long para que la inversion de cualquier int quepa.
- 6.3: consonantesHelper termina al llegar al final de la cadena. Cuenta
  letras ASCII A-Z/a-z salvo a/e/i/o/u, sin distinguir mayusculas. La suma
  queda pendiente al volver (sin cola). Espacios, cifras y signos no cuentan.
- 6.4: chocolatesHelper termina cuando pendientes < envoltura. Cada canje
  recibe pendientes / envoltura chocolates y conserva pendientes % envoltura
  envolturas; la siguiente llamada recibe nuevos + sobrantes. No se prestan
  envolturas. contarChocolates suma los comprados y los obtenidos por canje.

## Ambiguedades y limites

La guia dice valores positivos mayores que 1, pero su segundo ejemplo usa
precio = 1. Se admite ese precio; envoltura debe ser mayor que 1 para que
el canje termine. Valores invalidos retornan -1. Dinero cero produce cero.

La guia sugiere ASCII. Por solicitud del usuario tambien se cuentan ñ y Ñ
como consonantes en UTF-8. En Windows el programa configura la entrada y
salida de consola en UTF-8 para escribirlas desde el terminal de VS Code.
Los demas caracteres fuera de ASCII no se cuentan.

La recursion de consonantes usa una llamada por byte: cadenas enormes
pueden agotar la pila. C++ no garantiza optimizacion de cola.

## Verificacion

Comprobacion repetida el 1 de octubre de 2026 en Windows y PowerShell,
con GCC 16.1.0: compilacion con C++17, Wall, Wextra y pedantic sin diagnosticos.
Las 40 entradas y bordes incorporados terminan con 0 fallos: arreglo vacio,
un solo elemento, negativos, repetidos, INT_MIN/INT_MAX, cero, ceros finales,
cadena vacia, vocales, mayusculas, signos, espacios, dinero insuficiente,
envolturas sobrantes y parametros de canje invalidos.
Lectura interactiva comprobada con "abc de" -> 3, "Hola mundo" -> 5
y tres espacios -> 0.

Pruebas adicionales: "ñ Ñ" -> 2, "niño" -> 2, "mañana" -> 3 y "Ñandú" -> 3.

Estas comprobaciones usan los casos que ya contiene el programa y entradas
por la entrada estandar; no cubren cadenas enormes ni verifican por si solas
el cumplimiento de toda la guia academica. El enunciado original no se incluye
en esta publicacion.

[Volver al curso](../README.md)
