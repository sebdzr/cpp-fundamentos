#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template <typename... Args>
void print(const Args&... args){
    ((cout << args), ...);
    cout << '\n';
}

void mostrarVector(const vector<int>& numeros){
    for(const int numero : numeros){
        cout << numero << ' ';
    }
    cout << '\n';
}

void ordenarBurbuja(vector<int>& numeros){
    const size_t cantidad{numeros.size()};

    for (size_t pasada = 0; pasada < cantidad -1; pasada++){
        for (size_t i = 0; i < cantidad - 1 - pasada; i++){
            if(numeros.at(i) > numeros.at(i + 1)){
                swap(numeros.at(i), numeros.at(i + 1));
            }
        }
    }
}

int main(){
    int cantidad{};

    print("ORDENAMIENTO BURBUJA");
    cout << "Cantidad de numeros: ";
    cin >> cantidad;

    if (cantidad <= 0){
        print("Error: la cantidad debe ser mayor que cero.");
        return 1;
    }

    vector<int> numeros;
    numeros.reserve(static_cast<size_t>(cantidad));

    for(int i = 0; i < cantidad; i++){
        int numero{};

        cout << "Numero " << i + 1 << ": ";
        cin >> numero;

        numeros.push_back(numero);
    }

    print("\nVector original:");
    mostrarVector(numeros);

    ordenarBurbuja(numeros);

    print("\nVector ordenado:");
    mostrarVector(numeros);

    return 0;
}