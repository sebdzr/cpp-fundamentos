#include "Aerolinea.h"

using namespace std;

Aerolinea::Aerolinea()
 : nombre("Sin asignar"),
   codigo("Sin asignar"),
   vuelosPorDia(new Vuelo*[CANTIDAD_DIAS]),
   cantidadVuelosPorDia(new int[CANTIDAD_DIAS])
{
    for (int dia = 0; dia < CANTIDAD_DIAS; dia++)
    {
        vuelosPorDia[dia] = nullptr;
        cantidadVuelosPorDia[dia] = 0;
    }
}

Aerolinea::Aerolinea(
    const string& nombre,
    const string& codigo
)
    : Aerolinea()
{
    setNombre(nombre);
    setCodigo(codigo);
}

bool Aerolinea::diaValido(int dia) const
{
    return dia >= 0 && dia < CANTIDAD_DIAS;
}

void Aerolinea::liberarMemoria()
{
    if(vuelosPorDia != nullptr)
    {
        for(int dia = 0; dia < CANTIDAD_DIAS; dia++)
        {
            delete[] vuelosPorDia[dia];
        }
    }

    delete[] vuelosPorDia;
    delete[] cantidadVuelosPorDia;

    vuelosPorDia = nullptr;
    cantidadVuelosPorDia = nullptr;
}

Aerolinea::~Aerolinea()
{
    liberarMemoria();
}

string Aerolinea::getNombre() const
{
    return nombre;
}

string Aerolinea::getCodigo() const
{
    return codigo;
}

void Aerolinea::setNombre(const string& nombre)
{
    if(!nombre.empty())
    {
        this->nombre = nombre;
    }
}

void Aerolinea::setCodigo(const string& codigo)
{
    if(!codigo.empty())
    {
        this->codigo = codigo;
    }
}

int Aerolinea::getCantidadVuelos(int dia) const
{
    if(!diaValido(dia))
    {
        return 0;
    }

    return cantidadVuelosPorDia[dia];
}

bool Aerolinea::agregarVuelo(int dia, const Vuelo& vuelo)
{
    if(!diaValido(dia))
    {
        return false;
    }

    if(buscarVuelo(dia, vuelo.getCodigo()) != nullptr)
    {
        return false;
    }

    int cantidadActual = cantidadVuelosPorDia[dia];

    Vuelo* nuevaFila = new Vuelo[cantidadActual + 1];

    for(int i = 0; i < cantidadActual; i++)
    {
        nuevaFila[i] = vuelosPorDia[dia][i];
    }

    nuevaFila[cantidadActual] = vuelo;

    delete[] vuelosPorDia[dia];

    vuelosPorDia[dia] = nuevaFila;
    cantidadVuelosPorDia[dia]++;

    return true;
}

Vuelo* Aerolinea::buscarVuelo(const string& codigoVuelo)
{
    for(int dia = 0; dia < CANTIDAD_DIAS; dia++)
    {
        for(int i = 0; i < cantidadVuelosPorDia[dia]; i++)
        {
            if (vuelosPorDia[dia][i].getCodigo() == codigoVuelo)
            {
                return &vuelosPorDia[dia][i];
            }
        }
    }
    
    return nullptr;
}

const Vuelo* Aerolinea::buscarVuelo(const string& codigoVuelo) const
{
    for(int dia = 0; dia < CANTIDAD_DIAS; dia++)
    {
        for(int i = 0; i < cantidadVuelosPorDia[dia]; i++)
        {
            if (vuelosPorDia[dia][i].getCodigo() == codigoVuelo)
            {
                return &vuelosPorDia[dia][i];
            }
        }
    }
    
    return nullptr;
}

Vuelo* Aerolinea::buscarVuelo(
    int dia,
    const string& codigoVuelo
)
{
    if (!diaValido(dia))
    {
        return nullptr;
    }

    for (int i = 0; i < cantidadVuelosPorDia[dia]; i++)
    {
        if (vuelosPorDia[dia][i].getCodigo() == codigoVuelo)
        {
            return &vuelosPorDia[dia][i];
        }
    }

    return nullptr;
}

const Vuelo* Aerolinea::buscarVuelo(
    int dia,
    const string& codigoVuelo
) const
{
    if (!diaValido(dia))
    {
        return nullptr;
    }

    for (int i = 0; i < cantidadVuelosPorDia[dia]; i++)
    {
        if (vuelosPorDia[dia][i].getCodigo() == codigoVuelo)
        {
            return &vuelosPorDia[dia][i];
        }
    }

    return nullptr;
}

bool Aerolinea::eliminarVuelo(
    int dia,
    const string& codigoVuelo
)
{
    if(!diaValido(dia))
    {
        return false;
    }

    int cantidadActual = cantidadVuelosPorDia[dia];
    int indiceEliminar = -1;

    for(int i = 0; i < cantidadActual; i++)
    {
        if(vuelosPorDia[dia][i].getCodigo() == codigoVuelo)
        {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar == -1)
    {
        return false;
    }

    if (cantidadActual == 1)
    {
        delete[] vuelosPorDia[dia];

        vuelosPorDia[dia] = nullptr;
        cantidadVuelosPorDia[dia] = 0;

        return true;
    }

    Vuelo* nuevaFila = new Vuelo[cantidadActual - 1];

    int j = 0;

    for (int i = 0; i < cantidadActual; i++)
    {
        if (i != indiceEliminar)
        {
            nuevaFila[j] = vuelosPorDia[dia][i];
            j++;
        }
    }

    delete[] vuelosPorDia[dia];

    vuelosPorDia[dia] = nuevaFila;
    cantidadVuelosPorDia[dia]--;

    return true;
}

Vuelo* Aerolinea::getVuelo(int dia, int indice)
{
    if (!diaValido(dia))
    {
        return nullptr;
    }

    if (indice < 0 || indice >= cantidadVuelosPorDia[dia])
    {
        return nullptr;
    }

    return &vuelosPorDia[dia][indice];
}
 
const Vuelo* Aerolinea::getVuelo(int dia, int indice) const
{
    if (!diaValido(dia))
    {
        return nullptr;
    }

    if (indice < 0 || indice >= cantidadVuelosPorDia[dia])
    {
        return nullptr;
    }

    return &vuelosPorDia[dia][indice];
}

void Aerolinea::copiarDesde(const Aerolinea& otra)
{
    nombre = otra.nombre;
    codigo = otra.codigo;

    vuelosPorDia = new Vuelo*[CANTIDAD_DIAS];
    cantidadVuelosPorDia = new int[CANTIDAD_DIAS];

    for (int dia = 0; dia < CANTIDAD_DIAS; dia++)
    {
        cantidadVuelosPorDia[dia] =
            otra.cantidadVuelosPorDia[dia];

        int cantidad = cantidadVuelosPorDia[dia];

        if (cantidad == 0)
        {
            vuelosPorDia[dia] = nullptr;
            continue;
        }

        vuelosPorDia[dia] = new Vuelo[cantidad];

        for (int i = 0; i < cantidad; i++)
        {
            vuelosPorDia[dia][i] =
                otra.vuelosPorDia[dia][i];
        }
    }
}

Aerolinea::Aerolinea(const Aerolinea& otra)
    : nombre("Sin asignar"),
      codigo("Sin asignar"),
      vuelosPorDia(nullptr),
      cantidadVuelosPorDia(nullptr)
{
    copiarDesde(otra);
}

Aerolinea& Aerolinea::operator=(const Aerolinea& otra)
{
    if (this != &otra)
    {
        liberarMemoria();
        copiarDesde(otra);
    }

    return *this;
}


