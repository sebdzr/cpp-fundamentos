#include "Estudiante.h"
#include <iostream>

using namespace std;

Estudiante :: Estudiante()
{
    nombre = " ";
}

Estudiante :: Estudiante(const string& nombre)
{
    this -> nombre = nombre;
}

string Estudiante :: getNombre() const
{
    return nombre;
}

void Estudiante :: setNombre(const string& nombre)
{
    this -> nombre = nombre;
}

void Estudiante :: agregarCalificacion(double nota)
{
    calificaciones.insert(nota);
}

double Estudiante :: total() const
{
    return calificaciones.total();
}

double Estudiante :: promedio() const
{
    return calificaciones.promedio();
}

int Estudiante :: cantidadCalificaciones() const
{
    return calificaciones.size();
}

void Estudiante :: print() const
{
    cout << "Estudiante: " << nombre << endl;

    cout << "Calificaciones: ";
    calificaciones.print();
    cout << endl;

    cout << "Total: " << total() << endl;
    cout << "Promedio: " << promedio() << endl;

}

// Punto 6.2
string Estudiante :: getClave() const
{
    size_t pos = nombre.find(' ');

    if(pos == string::npos)
    {
        return nombre;
    }

    string primerNombre = nombre.substr(0, pos);
    string apellido = nombre.substr(pos + 1);

    return apellido + " " + primerNombre;
}
