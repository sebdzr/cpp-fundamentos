#include "list.h"
#include "Punto.h"
#include <string>
using namespace std;

template<typename T>
List<T>::List()
{
    begin = nullptr;
    count = 0;
}

template<typename T>
List<T>::~List()
{
    while (begin != nullptr)
    {
        Node<T>* del = begin;
        begin = begin->next;
        delete del;
    }
}

template<typename T>
Node<T>* List<T>::makeNode(const T& value)
{
    Node<T>* node = new Node<T>;

    node->data = value;
    node->next = nullptr;

    return node;
}

template<typename T>
void List<T>::insert(int pos, const T& value)
{
    if (pos < 0 || pos > count)
    {
        cout << "Error, fuera de rango." << endl;
        return;
    }

    Node<T>* add = makeNode(value);

    if (pos == 0)
    {
        add->next = begin;
        begin = add;
    }
    else
    {
        Node<T>* cur = begin;

        for (int i = 0; i < pos - 1; i++)
        {
            cur = cur->next;
        }

        add->next = cur->next;
        cur->next = add;
    }

    count++;
}

template<typename T>
void List<T>::erase(int pos)
{
    if (pos < 0 || pos >= count)
    {
        cout << "Error, fuera de rango." << endl;
        return;
    }

    if (pos == 0)
    {
        Node<T>* del = begin;
        begin = begin->next;
        delete del;
    }
    else
    {
        Node<T>* cur = begin;

        for (int i = 0; i < pos - 1; i++)
        {
            cur = cur->next;
        }

        Node<T>* del = cur->next;
        cur->next = del->next;
        delete del;
    }

    count--;
}

template<typename T>
T& List<T>::get(int pos) const
{
    if (pos < 0 || pos >= count)
    {
        cout << "Error, fuera de rango." << endl;
        assert(false);
    }

    Node<T>* cur = begin;

    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }

    return cur->data;
}

template<typename T>
int List<T>::size() const
{
    return count;
}

template<typename T>
void List<T>::print() const
{
    Node<T>* cur = begin;

    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

template<typename T>
void List<T>::printReverse(Node<T>* cur) const
{
    if (cur == nullptr)
    {
        return;
    }

    printReverse(cur->next);
    cout << cur->data << " ";
}

template<typename T>
void List<T>::printReverse() const
{
    printReverse(begin);
    cout << endl;
}

template class List<int>;
template class List<double>;
template class List<string>;
template class List<Punto>;