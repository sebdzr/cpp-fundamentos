#include "list.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    List<string> list;

    list.insert(0, "nestor");
    list.insert(1, "victor");
    list.insert(2, "Maria");
    list.insert(3, "juan");
    list.insert(4, "pedro");

    cout << "Orden normal: ";
    list.print();

    cout << "Orden inverso: ";
    list.printReverse();

    return 0;
}