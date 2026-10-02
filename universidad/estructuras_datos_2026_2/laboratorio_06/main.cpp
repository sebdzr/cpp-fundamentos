#include <iostream>
#include <climits>
#include "Recursividad.h"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main()
{
    // Punto 6.3
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    int fallos = 0;
    // Punto 6.1
    const int arreglos[10][10] = {
        {1,2,3,4,5,6,7,8,9,10},
        {10,9,8,7,6,5,4,3,2,1},
        {5,5,5,5,5,5,5,5,5,5},
        {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10},
        {5,4,3,2,0,6,7,8,9,10},
        {8,4,-6,2,9,3,-6,7,1,0},
        {INT_MIN,2,3,4,5,6,7,8,9,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
        {9,8,7,6,-20,4,3,2,1,0},
        {12,45,23,67,34,89,56,90,78,-100}
    };
    const int menores[10] = {1,1,5,-10,0,-6,INT_MIN,INT_MAX,-20,-100};

    cout << "6.1 Menor de 10 arreglos de 10 enteros\n";
    for(int i = 0; i < 10; i++)
    {
        int resultado = 0;
        bool valido = encontrarMenor(arreglos[i], 10, resultado);
        cout << "[";
        for(int j = 0; j < 10; j++)
            cout << arreglos[i][j] << (j == 9 ? "]" : ", ");
        cout << " -> " << resultado << '\n';
        if(!valido || resultado != menores[i])
            fallos++;
    }

    // Punto 6.2
    const int enteros[10] = {12789,0,7,10,1200,-12789,-10,1001,INT_MAX,INT_MIN};
    const long long invertidos[10] = {98721,0,7,1,21,-98721,-1,1001,7463847412LL,-8463847412LL};
    cout << "\n6.2 Invertir digitos (cola recursiva)\n";
    for(int i = 0; i < 10; i++)
    {
        long long resultado = invertirDigitos(enteros[i]);
        cout << enteros[i] << " -> " << resultado << '\n';
        if(resultado != invertidos[i])
            fallos++;
    }

    // Punto 6.3
    const string cadenas[10] = {"abc de","","aeiou AEIOU","BCDFG","Hola mundo",
        "123 !?","y Y","b c d f g","Recursividad","XYZ xyz"};
    const int consonantes[10] = {3,0,0,5,5,0,2,5,7,6};
    cout << "\n6.3 Consonantes\n";
    for(int i = 0; i < 10; i++)
    {
        int resultado = contarConsonantes(cadenas[i]);
        cout << '"' << cadenas[i] << "\" -> " << resultado << '\n';
        if(resultado != consonantes[i])
            fallos++;
    }

    // Punto 6.4
    const int entradas[10][3] = {
        {16,2,2},{15,1,3},{2,3,2},{10,2,3},{12,2,3},
        {20,3,4},{100,5,5},{9,2,2},{6,2,3},{17,3,2}
    };
    const int chocolates[10] = {15,22,0,7,8,7,24,7,4,9};
    cout << "\n6.4 Chocolates (dinero, precio, envoltura)\n";
    for(int i = 0; i < 10; i++)
    {
        long long resultado = contarChocolates(entradas[i][0], entradas[i][1], entradas[i][2]);
        cout << entradas[i][0] << ", " << entradas[i][1] << ", " << entradas[i][2]
             << " -> " << resultado << '\n';
        if(resultado != chocolates[i])
            fallos++;
    }

    // Punto 6.1
    int resultado = 99;
    const int unico[1] = {-42};
    if(encontrarMenor(nullptr, 0, resultado) || resultado != 99)
        fallos++;
    if(encontrarMenor(unico, 0, resultado) || encontrarMenor(unico, -1, resultado))
        fallos++;
    if(!encontrarMenor(unico, 1, resultado) || resultado != -42)
        fallos++;
    // Punto 6.4
    if(contarChocolates(0, 2, 2) != 0 || contarChocolates(5, 0, 2) != -1 ||
       contarChocolates(5, 2, 1) != -1 || contarChocolates(-1, 2, 2) != -1 ||
       contarChocolates(INT_MAX, 1, 2) != 4294967293LL)
        fallos++;

    // Punto 6.3
    if(contarConsonantes(u8"ñ Ñ") != 2 ||
       contarConsonantes(u8"niño") != 2 ||
       contarConsonantes(u8"mañana") != 3 ||
       contarConsonantes(u8"Ñandú") != 3)
        fallos++;

    cout << "\nPruebas automaticas: " << fallos << " fallos.\n";
    // Punto 6.3
    cout << "Cadena opcional (Enter para terminar): ";
    string entrada;
    while(getline(cin, entrada) && !entrada.empty())
    {
        cout << "Consonantes: " << contarConsonantes(entrada) << '\n';
        cout << "Otra cadena (Enter para terminar): ";
    }
    return fallos == 0 ? 0 : 1;
}
