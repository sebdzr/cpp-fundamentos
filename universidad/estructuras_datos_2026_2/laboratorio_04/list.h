#ifndef LIST_H
#define LIST_H

#include "Termino.h"

struct Node
{
    Termino data;
    Node* next;
};

class List
{
private:
    Node* begin;
    Node* end;
    int count;

    Node* makeNode(const Termino& value);

public:
    List();
    ~List();

    void insert(const Termino& value);
    void sum(const List& other, List& result) const;
    void subtract(const List& other, List& result) const;
    void print() const;
    int size() const;
};

#endif
