#include <iostream>

using namespace std;

template <typename... Args>
void print(const Args&... args)
{
    ((cout << args << " "), ...);
    cout << '\n';
}

int main()
{
    int num1 = 10;
    int num2 = 20;

    int* ptr1 = &num1;
    int* ptr2 = &num2;

    print(boolalpha);

    print("ESTADO INICIAL");
    print("num1:", num1);
    print("num2:", num2);

    print("Direccion de num1:", &num1);
    print("Direccion de num2:", &num2);

    print("Direccion guardada en ptr1:", ptr1);
    print("Direccion guardada en ptr2:", ptr2);

    ptr1 = ptr2;

    print("AMBOS PUNTEROS APUNTAN A num2");
    print("Valor mediante ptr1:", *ptr1);
    print("Valor mediante ptr2:", *ptr2);

    *ptr1 = 35;

    print("DESPUES DE *ptr1 = 35");
    print("num2:", num2);
    print("Valor mediante ptr2:", *ptr2);

    *ptr2 = 80;

    print("DESPUES DE *ptr2 = 80");
    print("num2:", num2);
    print("Valor mediante ptr1:", *ptr1);


    ptr2 = nullptr;

    print("DESPUES DE ptr2 = nullptr");
    print("ptr1 es nullptr:", (ptr1 == nullptr));
    print("ptr2 es nullptr:", (ptr2 == nullptr));
    print("ptr1 y ptr2 son iguales:", (ptr1 == ptr2));


    if(ptr1 != nullptr)
    {
        print("Valor accedido con *ptr1:", *ptr1);
    }

    if(ptr2 != nullptr)
    {
        print("Valor accedido con *ptr2:", *ptr2);
    }
    else
    {
        print("No se puede desreferenciar ptr2 porque es nullptr.");
    }

    *ptr1 = 50;

    print("ESTADO FINAL");
    print("num1: ", num1);
    print("num2: ", num2);

    return 0;
}