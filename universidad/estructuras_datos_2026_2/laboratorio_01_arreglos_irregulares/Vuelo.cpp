#include "Vuelo.h"

using namespace std;

Vuelo::Vuelo()
    : codigo("Sin asignar"),
      origen("Sin asignar"),
      destino("Sin asignar"),
      hora("Sin asignar"),
      aeronave()
{
}

Vuelo::Vuelo(
    const string& codigo,
    const string& origen,
    const string& destino,
    const string& hora,
    const Aeronave& aeronave
)
    : codigo("Sin asignar"),
      origen("Sin asignar"),
      destino("Sin asignar"),
      hora("Sin asignar"),
      aeronave()
{
    setCodigo(codigo);
    setOrigen(origen);
    setDestino(destino);
    setHora(hora);
    setAeronave(aeronave);
}

string Vuelo::getCodigo() const
{
    return codigo;
}

string Vuelo::getOrigen() const
{
    return origen;
}

string Vuelo::getDestino() const
{
    return destino;
}

string Vuelo::getHora() const
{
    return hora;
}

const Aeronave& Vuelo::getAeronave() const
{
    return aeronave;
}

int Vuelo::getCantidadPasajeros() const
{
    return aeronave.getCapacidad();
}

void Vuelo::setCodigo(const string& codigo)
{
    if(!codigo.empty())
    {
        this->codigo = codigo;
    }
}

void Vuelo::setOrigen(const string& origen)
{
    if(!origen.empty())
    {
        this->origen = origen;
    }
}

void Vuelo::setDestino(const string& destino)
{
    if(!destino.empty())
    {
        this->destino = destino;
    }
}

bool Vuelo::horaValida(const string& hora) const
{
    if (hora.length() != 5)
    {
        return false;
    }

    if (hora[2] != ':')
    {
        return false;
    }
     if (
        hora[0] < '0' || hora[0] > '9' ||
        hora[1] < '0' || hora[1] > '9' ||
        hora[3] < '0' || hora[3] > '9' ||
        hora[4] < '0' || hora[4] > '9'
    )
    {
        return false;
    }

    int horas =
        (hora[0] - '0') * 10 +
        (hora[1] - '0');

    int minutos =
        (hora[3] - '0') * 10 +
        (hora[4] - '0');

    return horas >= 0 &&
           horas <= 23 &&
           minutos >= 0 &&
           minutos <= 59;
}

bool Vuelo::setHora(const string& hora)
{
    if (!horaValida(hora))
    {
        return false;
    }

    this->hora = hora;

    return true;
}

void Vuelo::setAeronave(const Aeronave& aeronave)
{
    if(aeronave.getCapacidad() > 0)
    {
        this->aeronave = aeronave;
    }
}