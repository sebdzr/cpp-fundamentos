#include "list.h"
#include <iostream>

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
    while(begin != nullptr)
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
        cout << "Error";
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
int List<T>::size() const
{
    return count;
}

template class List<int>;