#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>


class Aeronave
{
private:
    std::string modelo;
    int capacidad;

 public:
    Aeronave();
    Aeronave(const std::string& modelo, int capacidad);

    std::string getModelo() const;
    int getCapacidad() const;

    void setModelo(const std::  string& modelo);
    void setCapacidad(int capacidad);

};

#endif