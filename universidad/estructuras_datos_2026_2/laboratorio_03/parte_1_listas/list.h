#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
struct Node
{
    T data;
    Node<T>* next;
};

template<typename T>
class List
{
private:
    Node<T>* begin;
    int count;

    Node<T>* makeNode(const T& value);
    void printReverse(Node<T>* cur) const;

public:
    List();
    ~List();

    void insert(int pos, const T& value);
    void erase(int pos);

    T& get(int pos) const;

    int size() const;

    void print() const;
    void printReverse() const;
};

#endif