#ifndef LISTA_ESTUDIANTES_H
#define LISTA_ESTUDIANTES_H

#include "Estudiante.h"

struct NodoEstudiante
{
    Estudiante data;
    NodoEstudiante* prev;
    NodoEstudiante* next;
};

class ListaEstudiantes
{
private:
    NodoEstudiante* begin;
    NodoEstudiante* end;
    int count;

    NodoEstudiante* makeNode(const Estudiante& estudiante);

public:
    ListaEstudiantes();
    ~ListaEstudiantes();

    void insert(const Estudiante& estudiante);

    Estudiante& get(int pos);

    int size() const;
    void print() const;

    // Punto 6.2

    void insertOrdenado(const Estudiante& estudiante);
};

#endif
