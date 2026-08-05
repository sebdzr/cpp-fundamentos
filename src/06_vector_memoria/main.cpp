#include <iostream>
#include <vector>

using namespace std;

template<typename... Args>
void print(const Args&... args)
{
    ((cout << args), ...);
    cout << endl;
}

int main()
{
    vector<int> numeros;

    print("Estado inicial");
    print("Size", numeros.size());
    print("Capacity: ", numeros.capacity());

    numeros.reserve(5);

    print("Despues de reserve(5)");
    print("Size", numeros.size());
    print("Capacity: ", numeros.capacity());

    for(int i = 1; i <=6; i++)
    {
        numeros.push_back(i * 10);

        print("Se agrego: ", i * 10);
        print("Size: ", numeros.size());
        print("Capacity: ", numeros.capacity());

        for (size_t posicion = 0; posicion < numeros.size(); posicion++)
        {
            print("Posicion ", posicion, ": ", numeros.at(posicion));
        }

        print("");
    }

    return 0;

}