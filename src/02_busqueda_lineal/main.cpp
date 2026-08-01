#include <iostream>
#include <vector>
using namespace std;

template<typename... Args>
void print(const Args&... args){
    ((cout << args), ...);
    cout << '\n';
}

int buscarPosicion(const vector<int>& numeros, const int buscado){
    for (size_t i = 0; i < numeros.size(); i++){
        if (numeros[i] == buscado){
            return static_cast<int>(i);
        }
    }
    
    return -1;
}

int main(){
    int cantidad{};

    print("BUSQUEDA LINEAL");
    cout << "Cantidad de numeros: ";
    cin >> cantidad;

    if (cantidad <= 0){
        print ("Error: la cantidad debe ser mayor que cero.");
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

    int buscado{};

    cout << "\nNumero que desea buscar: ";
    cin >> buscado;

    const int posicion{buscarPosicion(numeros, buscado)};

    if (posicion != -1){
        print("El numero ", buscado, " fue encontrado en el indice ", posicion, ".");

    } else {
        print("El numero ", buscado, " no se encuentra en el vector.");
    }

    return 0;
}