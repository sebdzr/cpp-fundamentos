#ifndef LISTA_CALIFICACIONES_H
#define LISTA_CALIFICACIONES_H

struct NodoNota
{
    double data;
    NodoNota* next;
};

class ListaCalificaciones
{
private:
    NodoNota* begin;
    NodoNota* end;
    int count;

    NodoNota* makeNode(double value);
    void copiarDesde(const ListaCalificaciones& other);

public:

    ListaCalificaciones();
    ListaCalificaciones(const ListaCalificaciones& other);
    ListaCalificaciones& operator=(const ListaCalificaciones& other);
    ~ListaCalificaciones();

    void insert(double value);

    double total() const;
    double promedio() const;

    int size() const;
    void print() const;
};


#endif
