#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include "ListaCalificaciones.h"

class Estudiante
{
private:
    std::string nombre;
    ListaCalificaciones calificaciones;

public:
    Estudiante();
    Estudiante(const std::string& nombre);

    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    void agregarCalificacion(double nota);

    double total() const;
    double promedio() const;
    int cantidadCalificaciones() const;

    void print() const;

    // Punto 6.2

    std::string getClave() const;

};

#endif
