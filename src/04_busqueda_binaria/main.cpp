#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename... Args>
void print(const Args&... args)
{
    ((cout << args), ...);
    cout << '\n';
}

void mostrarVector(const vector<int>& numeros)
{
    for (const int numero : numeros){
        cout << numero << ' ';
    }

    cout << '\n';
}

int buscarBinariamente(const vector<int>& numeros, const int buscado)
{
    int izquierda{0};
    int derecha{static_cast<int>(numeros.size()) - 1};

    while (izquierda <= derecha)
    {
        const int centro{
            izquierda + (derecha - izquierda) / 2
        };

        print("Revisando indice ", centro, " con valor ", numeros.at(static_cast<size_t>(centro)));

        if (numeros.at(static_cast<size_t>(centro)) == buscado)
        {
            return centro;
        }

        if (numeros.at(static_cast<size_t>(centro)) < buscado){
            izquierda = centro + 1;
        } 
        else
        {
            derecha = centro - 1;

        }

    }

    return -1;

}

int main()
{
    int cantidad{};

    print("BUSQUEDA BINARIA");
    cout << "Cantidad de numeros: ";
    cin >> cantidad;

    if(cantidad <= 0)
    {
        print("Error: la cantidad debe ser mayor que cero.");
        return 1;
    }

    vector<int> numeros;
    numeros.reserve(static_cast<size_t>(cantidad));



    for(int i = 0; i < cantidad; i++)
    {
        int numero{};

        cout << "Numero " << i + 1 << ": ";
        cin >> numero;

        numeros.push_back(numero);

    }

    sort(numeros.begin(), numeros.end());

    print("\nVector ordenado:");
    mostrarVector(numeros);

    int buscado{};

    cout << "\nNumero que desea buscar: ";
    cin >> buscado;


    print("\nPasos de la busqueda:");

    const int posicion{buscarBinariamente(numeros, buscado)};

    if (posicion != -1)
    {
        print("\nEl numero ", buscado, " fue encontrado en el indice ", posicion, ".");
    }
    else
    {
        print("\nEl numero ", buscado, " no se encuentra en el vector.");
    }
    
    return 0;
}