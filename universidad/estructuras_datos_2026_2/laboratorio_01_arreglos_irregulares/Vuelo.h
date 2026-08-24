#ifndef VUELO_H
#define VUELO_H

#include <string>

#include "Aeronave.h"

class Vuelo
{
private:
    std::string codigo;
    std::string origen;
    std::string destino;
    std::string hora;
    Aeronave aeronave;
    bool horaValida(const std::string& hora) const;

public:
    Vuelo();

    Vuelo
    (
        const std::string& codigo,
        const std::string& origen,
        const std::string& destino,
        const std::string& hora,
        const Aeronave& aeronave
    );

    std::string getCodigo() const;
    std::string getOrigen() const;
    std::string getDestino() const;
    std::string getHora() const;
    const Aeronave& getAeronave() const;

    int getCantidadPasajeros() const;

    void setCodigo(const std::string& codigo);
    void setOrigen(const std::string& origen);
    void setDestino(const std::string& destino);
    bool setHora(const std::string& hora);
    void setAeronave(const Aeronave& aeronave);   
    
};

#endif