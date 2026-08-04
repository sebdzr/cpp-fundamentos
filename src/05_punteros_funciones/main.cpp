#include <iostream>
#include "Operaciones.h"

using namespace std;

int main()
{
    int numero = 7;

    cout << "Antes: " << numero << "\n";

    duplicar(&numero);

    cout << "Despues: " << numero << "\n";

    return 0;
}