#ifndef SISTEMA_AEROCIVIL_H
#define SISTEMA_AEROCIVIL_H

#include <string>

#include "Aerolinea.h"

class SistemaAerocivil
{
private:
    Aerolinea* aerolineas;
    int cantidadAerolineas;

    int buscarIndiceAerolinea(const std::string& codigo) const;
    
    void liberarMemoria();
    void copiarDesde(const SistemaAerocivil& otro);

public:
    SistemaAerocivil();

    SistemaAerocivil(const SistemaAerocivil& otro);

    SistemaAerocivil& operator=(const SistemaAerocivil& otro);

    ~SistemaAerocivil();

    int getCantidadAerolineas() const;

    Aerolinea* getAerolinea(int indice);
    const Aerolinea* getAerolinea(int indice) const;

    Aerolinea* buscarAerolinea(const std::string& codigo);
    const Aerolinea* buscarAerolinea(const std::string& codigo) const;

    bool agregarAerolinea(const Aerolinea& aerolinea);
    bool eliminarAerolinea(const std::string& codigo);

    bool agregarVuelo(
        const std::string& codigoAerolinea,
        int dia,
        const Vuelo& vuelo
    );

    bool eliminarVuelo(
        const std::string& codigoAerolinea,
        int dia,
        const std::string& codigoVuelo
    );

    Vuelo* buscarVuelo(
        const std::string& codigoAerolinea,
        const std::string& codigoVuelo
    );

    const Vuelo* buscarVuelo(
        const std::string& codigoAerolinea,
        const std::string& codigoVuelo
    ) const;

    Vuelo* buscarVuelo(
        const std::string& codigoAerolinea,
        int dia,
        const std::string& codigoVuelo
    );

    const Vuelo* buscarVuelo(
        const std::string& codigoAerolinea,
        int dia,
        const std::string& codigoVuelo
    ) const;

    void precargarDatos();

};

#endif