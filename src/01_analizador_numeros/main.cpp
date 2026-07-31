#include <iostream>
#include <vector>
using namespace std;

template <typename... Args>
void print(const Args&... args){
    ((cout << args), ...);
    cout << '\n';
}

struct Estadisticas {
    int suma{};
    double promedio{};
    int menor{};
    int mayor{};
    int cantidadPares{};
    int cantidadImpares{};
};


Estadisticas analizarNumeros(const vector<int>& numeros){
    Estadisticas resultados;

    resultados.menor = numeros.front();
    resultados.mayor = numeros.front();

    for (const int numero : numeros){
        resultados.suma += numero;

        if (numero < resultados.menor){
            resultados.menor = numero;
        }

        if (numero > resultados.mayor){
            resultados.mayor = numero;
        }

        if (numero % 2 == 0){
            resultados.cantidadPares++;
        }

        else {
            resultados.cantidadImpares++;
        }
    }

    resultados.promedio = static_cast<double>(resultados.suma) / numeros.size();

    return resultados;
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

    const Estadisticas resultados{analizarNumeros(numeros)};

    print("\nRESULTADOS");
    print("Suma: ", resultados.suma);
    print("Promedio: ", resultados.promedio);
    print("Numero menor: ", resultados.menor);
    print("Numero mayor: ", resultados.mayor);
    print("Cantidad de pares: ", resultados.cantidadPares);
    print("Cantidad de impares: ", resultados.cantidadImpares);

    return 0;
}
