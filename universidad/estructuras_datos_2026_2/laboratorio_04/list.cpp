#include "list.h"
#include <iostream>

using namespace std;

List::List()
{
    begin = nullptr;
    end = nullptr;
    count = 0;
}

List::~List()
{
    while (begin != nullptr)
    {
        Node* del = begin;
        begin = begin->next;
        delete del;
    }
}

Node* List::makeNode(const Termino& value)
{
    Node* add = new Node;
    add->data = value;
    add->next = nullptr;
    return add;
}

// Los terminos se reciben de mayor a menor exponente, sin repetirlo.
void List::insert(const Termino& value)
{
    if (value.coeficiente == 0)
    {
        return;
    }

    Node* add = makeNode(value);
    if (begin == nullptr)
    {
        begin = add;
    }
    else
    {
        end->next = add;
    }
    end = add;
    count++;
}

// result debe ser una lista vacia, distinta de las dos entradas.
void List::sum(const List& other, List& result) const
{
    Node* a = begin;
    Node* b = other.begin;

    while (a != nullptr && b != nullptr)
    {
        if (a->data.exponente == b->data.exponente)
        {
            int c = a->data.coeficiente + b->data.coeficiente;
            result.insert(Termino(c, a->data.exponente));
            a = a->next;
            b = b->next;
        }
        else if (a->data.exponente > b->data.exponente)
        {
            result.insert(a->data);
            a = a->next;
        }
        else
        {
            result.insert(b->data);
            b = b->next;
        }
    }

    while (a != nullptr)
    {
        result.insert(a->data);
        a = a->next;
    }
    while (b != nullptr)
    {
        result.insert(b->data);
        b = b->next;
    }
}

// result debe ser otra lista vacia; los terminos de B cambian de signo.
void List::subtract(const List& other, List& result) const
{
    Node* a = begin;
    Node* b = other.begin;

    while (a != nullptr && b != nullptr)
    {
        if (a->data.exponente == b->data.exponente)
        {
            int c = a->data.coeficiente - b->data.coeficiente;
            result.insert(Termino(c, a->data.exponente));
            a = a->next;
            b = b->next;
        }
        else if (a->data.exponente > b->data.exponente)
        {
            result.insert(a->data);
            a = a->next;
        }
        else
        {
            result.insert(Termino(-b->data.coeficiente, b->data.exponente));
            b = b->next;
        }
    }

    while (a != nullptr)
    {
        result.insert(a->data);
        a = a->next;
    }
    while (b != nullptr)
    {
        result.insert(Termino(-b->data.coeficiente, b->data.exponente));
        b = b->next;
    }
}

void List::print() const
{
    Node* cur = begin;
    int pos = 1;

    if (cur == nullptr)
    {
        cout << "0 (polinomio sin terminos)" << endl;
    }
    while (cur != nullptr)
    {
        cout << "Termino " << pos << ": ("
             << cur->data.coeficiente << ", "
             << cur->data.exponente << ") -> "
             << cur->data.coeficiente;

        if (cur->data.exponente != 0)
        {
            cout << "x^" << cur->data.exponente;
        }
        cout << endl;
        cur = cur->next;
        pos++;
    }
}

int List::size() const
{
    return count;
}
