#include "list.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    List p1;
    List p2;
    List suma;
    List resta;

    ifstream archivo1("datos/polinomio1.txt");
    ifstream archivo2("datos/polinomio2.txt");

    if (!archivo1 || !archivo2)
    {
        cout << "No se pudieron abrir los archivos de los polinomios." << endl;
        return 1;
    }

    int coeficiente;
    int exponente;

    // Cada linea contiene: coeficiente exponente.
    while (archivo1 >> coeficiente >> exponente)
    {
        p1.insert(Termino(coeficiente, exponente));
    }
    while (archivo2 >> coeficiente >> exponente)
    {
        p2.insert(Termino(coeficiente, exponente));
    }
    archivo1.close();
    archivo2.close();

    p1.sum(p2, suma);
    p1.subtract(p2, resta);

    cout << "Cada par indica (coeficiente, exponente)." << endl;
    cout << "\nPolinomio 1: " << p1.size() << " terminos" << endl;
    p1.print();
    cout << "\nPolinomio 2: " << p2.size() << " terminos" << endl;
    p2.print();
    cout << "\nSuma (P1 + P2): " << suma.size() << " terminos" << endl;
    suma.print();
    cout << "\nResta (P1 - P2): " << resta.size() << " terminos" << endl;
    resta.print();

    return 0;
}
