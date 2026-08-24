#include "Aeronave.h"
using namespace std;

Aeronave::Aeronave()
    : modelo("Sin asignar"), capacidad(0)
{
}

Aeronave::Aeronave(const string& modelo, int capacidad)
    : modelo("Sin asignar"), capacidad(0)
{
    setModelo(modelo);
    setCapacidad(capacidad);
}

string Aeronave::getModelo() const
{
    return modelo;
}

int Aeronave::getCapacidad() const
{
    return capacidad;
}

void Aeronave::setModelo(const string& modelo)
{
    if (!modelo.empty())
    {
        this->modelo = modelo;
    }
}

void Aeronave::setCapacidad(int capacidad)
{
    if(capacidad > 0)
    {
        this->capacidad = capacidad;
    }
}
