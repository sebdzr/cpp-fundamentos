#include "ListaCalificaciones.h"
#include <iostream>

using namespace std;

ListaCalificaciones :: ListaCalificaciones()
{
    begin = nullptr;
    end = nullptr;
    count = 0;
}

ListaCalificaciones :: ListaCalificaciones(const ListaCalificaciones& other)
{
    begin = nullptr;
    end = nullptr;
    count = 0;

    copiarDesde(other);
}

ListaCalificaciones& ListaCalificaciones :: operator=(const ListaCalificaciones& other)
{
    if(this == &other)
    {
        return *this;
    }

    while(begin != nullptr)
    {
        NodoNota* del = begin;

        begin = begin -> next;
        delete del;
    }

    end = nullptr;
    count = 0;

    copiarDesde(other);

    return *this;
}

ListaCalificaciones :: ~ListaCalificaciones()
{
    while(begin != nullptr)
    {
        NodoNota* del = begin;

        begin = begin -> next;
        delete del;
    }

    end = nullptr;
    count = 0;
}

NodoNota* ListaCalificaciones :: makeNode(double value)
{
    NodoNota* nota = new NodoNota;

    nota -> data = value;
    nota -> next = nullptr;

    return nota;
}

void ListaCalificaciones :: copiarDesde(const ListaCalificaciones& other)
{
    NodoNota* cur = other.begin;

    while(cur != nullptr)
    {
        insert(cur -> data);
        cur = cur -> next;
    }
}

void ListaCalificaciones :: insert(double value)
{
    if (count >= 4)
    {
        return;
    }

    NodoNota* add = makeNode(value);

    if(count == 0)
    {
        begin = add;
        end = add;
    }
    else
    {
        end -> next = add;
        end = add;
    }

    count++;
}

double ListaCalificaciones :: total() const
{
    double suma = 0.0;

    NodoNota* cur = begin;

    while(cur != nullptr)
    {
        suma += cur->data;
        cur = cur -> next;
    }

    return suma;
}

double ListaCalificaciones :: promedio() const
{
    if (count == 0)
    {
        return 0.0;
    }

    return total()/count;
}

int ListaCalificaciones :: size() const
{
    return count;
}

void ListaCalificaciones :: print() const
{
    NodoNota* cur = begin;

    while(cur != nullptr)
    {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
}
