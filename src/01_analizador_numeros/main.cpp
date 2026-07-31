#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cantidad{};

    cout << "ANALIZADOR DE NUMEROS\n";
    cout << "Cantidad de numeros: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Error: La cantidad debe ser mayor que cero.\n";
        return 1;
    }

    vector<int> numeros;
    numeros.reserve(static_cast<size_t>(cantidad));

    for (int i = 0; i < cantidad; i++){
        int numero{};
        
        cout << "Numero " << i + 1 << ": ";
        cin >> numero;

        numeros.push_back(numero);
    }

    cout << "\nNumeros almacenados:\n";

    for (const int numero : numeros){
        cout << numero << ' ';
    }

    cout << '\n';

    return 0;

}