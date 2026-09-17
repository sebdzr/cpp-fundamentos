#include "ListaEstudiantes.h"
#include <iostream>
#include <cassert>

using namespace std;

ListaEstudiantes :: ListaEstudiantes()
{
    begin = nullptr;
    end = nullptr;
    count = 0;
}

ListaEstudiantes :: ~ListaEstudiantes()
{
    while(begin != nullptr)
    {
        NodoEstudiante* del = begin;
        begin = begin -> next;
        delete del;
    }

    end = nullptr;
    count = 0;
}

NodoEstudiante* ListaEstudiantes :: makeNode(const Estudiante& estudiante)
{
    NodoEstudiante* add = new NodoEstudiante;

    add -> data = estudiante;
    add -> next = nullptr;
    add -> prev = nullptr;

    return add;
}

void ListaEstudiantes :: insert(const Estudiante& estudiante)
{
    NodoEstudiante* add = makeNode(estudiante);

    if(count == 0)
    {
        begin = add;
        end = add;
    }
    else
    {
        add -> prev = end;
        end -> next = add;
        end = add;
    }

    count++;
}

Estudiante& ListaEstudiantes :: get(int pos)
{
    if(pos < 0 || pos >= count)
    {
        cout << "Posicion fuera de rango." << endl;
        assert(false);
    }

    NodoEstudiante* cur = begin;

    for (int i = 0; i < pos; i++)
    {
        cur = cur -> next;
    }

    return cur -> data;

}

int ListaEstudiantes :: size() const
{
    return count;
}

void ListaEstudiantes :: print() const
{
    NodoEstudiante* cur = begin;

    while(cur != nullptr)
    {
        cur -> data.print();
        cout << endl;

        cur = cur -> next;
    }
}

// Punto 6.2

void ListaEstudiantes :: insertOrdenado(const Estudiante& estudiante)
{
    NodoEstudiante* add = makeNode(estudiante);

    if(count == 0)
    {
        begin = add;
        end = add;
    }
    else if(estudiante.getClave() < begin->data.getClave())
    {
        add -> next = begin;
        begin -> prev = add;
        begin = add;
    }
    else
    {

        NodoEstudiante* cur = begin;

        while(cur->next != nullptr && cur->next->data.getClave() < estudiante.getClave())
        {
            cur = cur->next;
        }

        add->next = cur->next;
        add->prev = cur;
        cur->next = add;

        if(add->next != nullptr)
        {
            add->next->prev = add;
        }
        else
        {
            end = add;
        }
    }

    count++;
}
