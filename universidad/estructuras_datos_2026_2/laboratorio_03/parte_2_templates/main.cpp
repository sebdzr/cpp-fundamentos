#include <iostream>
#include <string>

using namespace std;

template<typename T>
void exchange(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T, int N>
void print(T (&array)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

template<typename T, int N>
void reverseArray(T (&array)[N])
{
    for (int i = 0; i < N / 2; i++)
    {
        exchange(array[i], array[N - 1 - i]);
    }
}

int main()
{
    int arrInt[5] = {1, 2, 3, 4, 5};
    double arrDouble[4] = {1.1, 2.2, 3.3, 4.4};
    char arrChar[5] = {'a', 'b', 'c', 'd', 'e'};
    string arrString[4] = {"uno", "dos", "tres", "cuatro"};

    cout << "INT antes: ";
    print(arrInt);

    reverseArray(arrInt);

    cout << "INT despues: ";
    print(arrInt);


    cout << "\nDOUBLE antes: ";
    print(arrDouble);

    reverseArray(arrDouble);

    cout << "DOUBLE despues: ";
    print(arrDouble);


    cout << "\nCHAR antes: ";
    print(arrChar);

    reverseArray(arrChar);

    cout << "CHAR despues: ";
    print(arrChar);


    cout << "\nSTRING antes: ";
    print(arrString);

    reverseArray(arrString);

    cout << "STRING despues: ";
    print(arrString);

    return 0;
}