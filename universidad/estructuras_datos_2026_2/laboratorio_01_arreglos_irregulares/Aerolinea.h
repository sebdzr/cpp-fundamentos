#ifndef AEROLINEA_H
#define AEROLINEA_H

#include <string>

#include "Vuelo.h"

class Aerolinea
{
private:
    std::string nombre;
    std::string codigo;
    
    Vuelo** vuelosPorDia;
    int* cantidadVuelosPorDia;

    static constexpr int CANTIDAD_DIAS = 7;

    bool diaValido(int dia) const;
    void liberarMemoria();
    void copiarDesde(const Aerolinea& otra);

public:
    Aerolinea();

    Aerolinea(
        const std::string& nombre,
        const std::string& codigo
    );

    Aerolinea(const Aerolinea& otra);

    Aerolinea& operator=(const Aerolinea& otra);

    ~Aerolinea();

    std::string getNombre() const;
    std::string getCodigo() const;

    void setNombre(const std::string& nombre);
    void setCodigo(const std::string& codigo);

    int getCantidadVuelos(int dia) const;
    
    Vuelo* getVuelo(int dia, int indice);
    const Vuelo* getVuelo(int dia, int indice) const;

    Vuelo* buscarVuelo(const std::string& codigoVuelo);
    const Vuelo* buscarVuelo(const std::string& codigoVuelo) const;

    Vuelo* buscarVuelo(int dia, const std::string& codigoVuelo);
    const Vuelo* buscarVuelo(int dia, const std::string& codigoVuelo) const;

    bool agregarVuelo(int dia, const Vuelo& vuelo);
    bool eliminarVuelo(int dia, const std::string& codigoVuelo);
  
};

#endif

