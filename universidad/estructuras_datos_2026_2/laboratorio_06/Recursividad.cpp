#include "Recursividad.h"

// Punto 6.1
static int menorHelper(const int arreglo[], int cantidad, int menor, int indice)
{
    if(indice == cantidad)
        return menor;

    if(arreglo[indice] < menor)
        menor = arreglo[indice];

    return menorHelper(arreglo, cantidad, menor, indice + 1);
}

bool encontrarMenor(const int arreglo[], int cantidad, int& resultado)
{
    if(arreglo == nullptr || cantidad <= 0)
        return false;

    resultado = menorHelper(arreglo, cantidad, arreglo[0], 1);
    return true;
}

// Punto 6.2
static long long invertirHelper(long long numero, long long resultado)
{
    if(numero == 0)
        return resultado;

    return invertirHelper(numero / 10, resultado * 10 + numero % 10);
}

long long invertirDigitos(int numero)
{

    return invertirHelper(numero, 0);
}

// Punto 6.3
static int consonantesHelper(const std::string& cadena, std::string::size_type indice)
{
    if(indice == cadena.size())
        return 0;

    unsigned char actual = static_cast<unsigned char>(cadena[indice]);
    if(actual == 0xC3 && indice + 1 < cadena.size())
    {
        unsigned char siguiente = static_cast<unsigned char>(cadena[indice + 1]);
        if(siguiente == 0xB1 || siguiente == 0x91)
            return 1 + consonantesHelper(cadena, indice + 2);
    }

    char letra = cadena[indice];
    if(letra >= 'A' && letra <= 'Z')
        letra = static_cast<char>(letra + ('a' - 'A'));

    int consonante = 0;
    if(letra >= 'a' && letra <= 'z' &&
       letra != 'a' && letra != 'e' && letra != 'i' &&
       letra != 'o' && letra != 'u')
        consonante = 1;

    return consonante + consonantesHelper(cadena, indice + 1);
}

int contarConsonantes(const std::string& cadena)
{
    return consonantesHelper(cadena, 0);
}

// Punto 6.4
static long long chocolatesHelper(long long pendientes, int envoltura)
{
    if(pendientes < envoltura)
        return 0;

    long long nuevos = pendientes / envoltura;
    long long sobrantes = pendientes % envoltura;

    return nuevos + chocolatesHelper(nuevos + sobrantes, envoltura);
}

long long contarChocolates(int dinero, int precio, int envoltura)
{
    if(dinero < 0 || precio <= 0 || envoltura <= 1)
        return -1;

    long long comprados = dinero / precio;
    return comprados + chocolatesHelper(comprados, envoltura);
}
