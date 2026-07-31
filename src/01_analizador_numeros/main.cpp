#include <iostream>
#include <vector>
using namespace std;

template <typename... Args>
void print(const Args&... args){
    ((cout << args), ...);
    cout << '\n';
}

int calcularSuma(const vector<int>& numeros){
    int suma{};

    for (const int numero : numeros){
        suma += numero;
    }

    return suma;
}

double calcularPromedio(const vector<int>& numeros){
    const int suma{calcularSuma(numeros)};
    
    return static_cast<double>(suma) / numeros.size();
}

int encontrarMenor(const vector<int>& numeros){
    int menor{numeros.front()};

    for(const int numero : numeros){
        if (numero < menor){
            menor = numero;
        }
    }

    return menor;
}

int encontrarMayor(const vector<int>& numeros){
    int mayor{numeros.front()};

    for (const int numero : numeros){
        if (numero > mayor){
            mayor = numero;
        }
    }

    return mayor;
}

int contarPares(const vector<int>& numeros){
    int cantidadPares{};

    for (const int numero : numeros){
        if (numero % 2 == 0){
            cantidadPares++;
        }
    }

    return cantidadPares;
}

int contarImpares(const vector<int>& numeros){
    int cantidadImpares{};

    for(const int numero : numeros){
        if (numero % 2 != 0){
            cantidadImpares++;
        }
    }
    return cantidadImpares;
}

int main()
{
    int cantidad{};

    print("ANALIZADOR DE NUMEROS");
    cout << "Cantidad de numeros: ";
    cin >> cantidad;

    if (cantidad <= 0){
        print("Error: la cantidad debe ser mayor que cero.");
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

    const int suma{calcularSuma(numeros)};
    const double promedio{calcularPromedio(numeros)};
    const int menor{encontrarMenor(numeros)};
    const int mayor{encontrarMayor(numeros)};
    const int pares{contarPares(numeros)};
    const int impares{contarImpares(numeros)};

    print("\nRESULTADOS");
    print("Suma: ", suma);
    print("Promedio: ", promedio);
    print("Numero menor: ", menor);
    print("Numero mayor: ", mayor);
    print("Cantidad de pares: ", pares);
    print("Cantidad de impares: ", impares);

    return 0;
}